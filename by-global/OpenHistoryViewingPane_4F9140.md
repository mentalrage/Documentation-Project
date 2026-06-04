*** UID:0000TC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OpenHistoryViewingPane_4F9140

## Status

- Confidence: strong for behavior, source owner, and current unreferenced status; medium for why the wrapper was retained.
- Address range: [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md)
- Likely owner source: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Function Role

`OpenHistoryViewingPane_4F9140` is a small helper that allocates a 264-byte [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) and passes the history resource selected by `g_useEpfAssets`: `HISTORY.EPF` in EPF/high-layout mode or `HISTORY.EPD` in legacy mode.

This duplicates the history branch inside `MainMenuPane::ActivateMenuItem`. Current IDA reports no callers or xrefs to the helper start, and 2026-05-28 raw pointer/immediate searches also found no hidden references. Treat it as a real retained duplicate helper unless later evidence proves a callback path.

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f9140` reports a real function of size `0x7f`.
- IDA MCP callees are allocator `0x004f4aa0` and `HistoryViewingPane::HistoryViewingPane` at `0x004ffd80`.
- IDA MCP reports no direct callers and no xrefs to `0x004f9140`.
- The constructor call sites inside this helper appear as `0x004f918c` and `0x004f91ab` in `callers 0x004ffd80`.
- 2026-06-04 live IDA reports the function as `0x004f9140-0x004f91bf`, preceded by one `0xcc` byte after the story helper and followed by one `0xcc` byte before `sub_4F91C0`.
- 2026-06-04 live IDA reports no xrefs to `0x004f9140` and zero loaded-segment dword hits for `0x004f9140`.
- 2026-06-04 live disassembly shows an SEH/security-cookie frame, `byte_66DA97 == 1` branch, allocation size `0x108`, non-null allocation check, and constructor call through `sub_4FFD80`.
- 2026-06-04 live string-byte decoding confirms the resource operands as `HISTORY.EPF` at `0x0061e150` and `HISTORY.EPD` at `0x0061e168`.
- 2026-06-04 live decompile of `sub_4F7A10` confirms active menu case `4` directly duplicates this allocation/resource/constructor sequence.
- 2026-05-26 IDA recheck still reports zero code refs and zero data refs to the helper start.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dword equal to `0x004f9140`.
- 2026-05-28 IDA MCP recheck still reports no code/data refs, no little-endian pointer byte match for `40 91 4f 00`, and no immediate-value search hits for `0x004f9140`.
- 2026-05-28 IDA MCP decompile of `0x004f7a10` shows the active history menu case directly allocating `264` bytes and calling `0x004ffd80` with `HISTORY.EPF`/`HISTORY.EPD`, matching this wrapper's behavior without calling the wrapper.

## Source Layout Decision

Keep this with `login/MainMenuPane.cpp` as a menu action helper for address-matching reconstruction unless later xrefs prove a separate callback table or dead-code exclusion. Do not place it in `HistoryViewingPane.cpp`; the helper selects the menu resource and allocates the viewer, while `HistoryViewingPane` owns viewer behavior. A behavior-only source rebuild can rely on the direct action-handler construction path.

## Autogen Status

- Reconstructable: true, as a retained project helper with exact behavior and boundary evidence.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
- C++: intentionally blank; this is a small retained wrapper, but final source shape and retention reason are not final-audit quality.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `80` | Exact boundary, padding relationship, resource operands, allocator/constructor behavior, no-xref/no-pointer checks, matching active menu case, and source-placement caveat are documented. Completion remains capped because the retained duplicate wrapper's source reason is unresolved. |
| Confidence `86` | Live IDA strongly confirms the helper body, decoded resource operands, constructor path, and current unreferenced status. Confidence remains below higher scores because no live caller or callback table has been recovered. |

## Cross-References

- [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-06-04: Raised completion/confidence from `72/80` to `80/86` after live IDA verified the exact helper boundary, padding before/after the helper, no entry xrefs, zero loaded dword hits, decoded `HISTORY.EPF`/`HISTORY.EPD` operands, raw instruction shape, and matching active `MainMenuPane` history case.
- Before: the page recorded older behavior/no-reference checks but lacked current padding, resource operand, and instruction-level evidence.
- After: the symbol summary now mirrors the stronger by-memory evidence while keeping final C++ blank and source retention unresolved.
- Why: live IDA proves the helper is real retained project code and strengthens the duplicate/unreferenced interpretation, but still finds no caller or callback table.
- Evidence: 2026-06-04 IDA MCP function lookup, byte checks, `xrefs_to`, loaded pointer scan, operand string decoding, helper disassembly, and `sub_4F7A10` decompile.
- Before: documented as a retained helper with weak unresolved reachability.
- After: documented as a retained duplicate launcher whose current lack of refs has been rechecked; the active main-menu history action is documented as directly duplicating the allocation/constructor sequence.
- Why: IDA MCP found no direct or raw-pointer references to `0x004f9140`, while `0x004f7a10` history case performs the same `264`-byte allocation and `0x004ffd80` constructor call.
- Evidence: 2026-05-28 IDA MCP `xrefs_to`, `callers`, `find_bytes`, immediate `search`, and `decompile 0x004f7a10`.
- 2026-06-02 score and parent update:
  - What existed before: the helper was scored `65/65` with no reconstructable parent attachment.
  - Changed to: completion `72`, confidence `80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000L0`.
  - Summary/evidence: exact function size, callees, call sites, repeated no-xref scans, and duplicated active main-menu construction support treating this as retained `MainMenuPane.cpp` project code while keeping C++ blank.
