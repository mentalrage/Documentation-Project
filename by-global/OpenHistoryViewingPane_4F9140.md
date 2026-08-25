*** UID:0000TC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// OpenHistoryViewingPane is emitted by exact helper [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OpenHistoryViewingPane_4F9140

## Status

- Confidence: very strong for byte range, exact child range, resource-selection behavior, constructor target, and current unreferenced status; medium for why the wrapper was retained.
- Address range: [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md)
- Likely owner source: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Support role: address-suffixed search/symbol alias only. The exact by-memory child [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md) owns the emitted `static void OpenHistoryViewingPane()` body; this alias keeps blank formal C++ and exact score `86/90`.

## Function Role

`OpenHistoryViewingPane_4F9140` is a small helper that allocates a 264-byte [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) through [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md), then calls [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md) with the history resource selected by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md): `HISTORY.EPF` in EPF/high-layout mode or `HISTORY.EPD` in legacy mode.

This duplicates the history branch inside `MainMenuPane::ActivateMenuItem`. Current IDA reports no callers or xrefs to the helper start, and 2026-05-28 raw pointer/immediate searches also found no hidden references. Treat it as a real retained duplicate helper unless later evidence proves a callback path.

The final emitted helper name omits the address suffix. Use this page for symbol/search history and source-placement evidence only; do not duplicate the body emitted by [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md).

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f9140` reports a real function of size `0x7f`.
- IDA MCP callees are allocator `0x004f4aa0` and `HistoryViewingPane::HistoryViewingPane` at `0x004ffd80`.
- IDA MCP reports no direct callers and no xrefs to `0x004f9140`.
- The constructor call sites inside this helper appear as `0x004f918c` and `0x004f91ab` in `callers 0x004ffd80`.
- 2026-06-04 live IDA reports the function as `0x004f9140-0x004f91bf`, preceded by one `0xcc` byte after the story helper and followed by one `0xcc` byte before `sub_4F91C0`.
- 2026-06-04 live IDA reports no xrefs to `0x004f9140` and zero loaded-segment dword hits for `0x004f9140`.
- 2026-06-04 live disassembly shows an SEH/security-cookie frame, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` branch, allocation size `0x108`, non-null allocation check, and constructor call through `sub_4FFD80`.
- 2026-06-04 live string-byte decoding confirms the resource operands as `HISTORY.EPF` at `0x0061e150` and `HISTORY.EPD` at `0x0061e168`.
- 2026-06-04 live decompile of `sub_4F7A10` confirms active menu case `4` directly duplicates this allocation/resource/constructor sequence.
- 2026-05-26 IDA recheck still reports zero code refs and zero data refs to the helper start.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dword equal to `0x004f9140`.
- 2026-05-28 IDA MCP recheck still reports no code/data refs, no little-endian pointer byte match for `40 91 4f 00`, and no immediate-value search hits for `0x004f9140`.
- 2026-05-28 IDA MCP decompile of `0x004f7a10` shows the active history menu case directly allocating `264` bytes and calling `0x004ffd80` with `HISTORY.EPF`/`HISTORY.EPD`, matching this wrapper's behavior without calling the wrapper.
- 2026-06-10 A001 live MCP recheck reconfirmed `0x004f9140` as a real `sub_4F9140` function, size `0x7f`, with no direct callers and no xrefs to the entry.
- 2026-06-10 `lookup_funcs` reconfirmed the adjacent retained-helper family: story helper `0x004f90c0` size `0x7f`, this history helper `0x004f9140` size `0x7f`, and terminal helper `0x004f91c0` size `0xbd`.
- 2026-06-10 `xrefs_to 0x004ffd80` / `callers 0x004ffd80` report six constructor call sites: four active `MainMenuPane::ActivateMenuItem` calls at `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, and `0x004f7c3d`, plus retained helper calls at `0x004f912b` and `0x004f91ab`.
- 2026-06-10 `xrefs_to 0x0061e150` reports `HISTORY.EPF` used by the active menu case at `0x004f7c00` and this helper at `0x004f9187`; `xrefs_to 0x0061e168` reports `HISTORY.EPD` used by the active menu case at `0x004f7c36` and this helper at `0x004f91a4`.
- 2026-06-10 `callees 0x004f9140` reports only [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) and [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md).
- 2026-06-10 `xrefs_to 0x004f4aa0` was truncated after confirming 1,785 project-wide code references, matching the shared allocator-wrapper evidence and confirming this helper does not own a local allocator.
- 2026-06-12 A002 split/route pass created exact child [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md) from the former pair aggregate [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md).
- 2026-06-12 A002 live IDA MCP session `b001_nexustk` reconfirmed `sub_4F9140` at `0x004f9140` with size `0x7f` / 127 bytes (Verified with `int_convert.py`), non-function end boundary `0x004f91bf`, successor `sub_4F91C0` at `0x004f91c0`, `0x108` / 264-byte allocation (Verified with `int_convert.py`), resource pushes at `0x004f9187` and `0x004f91a4`, and constructor call at `0x004f91ab`.
- 2026-06-12 A002 `xrefs_to` reconfirmed zero helper-entry xrefs to `0x004f9140`; `xrefs_to 0x004ffd80` showed active history call sites at `0x004f7c07`/`0x004f7c3d` and the retained helper call at `0x004f91ab`.
- 2026-06-12 A002 `xrefs_to` reconfirmed `HISTORY.EPF` at `0x0061e150` is used by active menu site `0x004f7c00` and this helper at `0x004f9187`; `HISTORY.EPD` at `0x0061e168` is used by active menu site `0x004f7c36` and this helper at `0x004f91a4`.
- 2026-06-29 B004 MCP session `992d23de` reconfirmed the exact `0x7f` / 127-byte child body, `0x108` / 264-byte allocation, `g_useEpfAssets == 1` branch, constructor/resource xrefs, zero helper-entry xrefs/callers, and zero VA/RVA pointer-byte routes. The exact child now carries first-draft `static void OpenHistoryViewingPane()` C++; this by-global page remains a blank-C++ alias at exact `86/90`.

## Source Layout Decision

Keep this with `login/MainMenuPane.cpp` as a menu action helper for address-matching reconstruction unless later xrefs prove a separate callback table or dead-code exclusion. Do not place it in `HistoryViewingPane.cpp`; the helper selects the menu resource and allocates the viewer, while `HistoryViewingPane` owns viewer behavior. A behavior-only source rebuild can rely on the direct action-handler construction path.

The current strict `85/85` child/parent gate now clears: this page is `86/90`, the exact by-memory child [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md) is `86/90`, and likely owner [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) is `89/86`.

## Autogen Status

- Reconstructable: true, as a retained project helper with exact behavior and boundary evidence.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The child and actual direct parent now clear the strict `85/85` route gate.
- C++: intentionally blank because this is a support/search alias. Emitted source belongs to exact child [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md); duplicating it here would double-emit the same function body.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | Exact boundary, exact child by-memory page, padding relationship, resource operands, allocator/constructor behavior, no-xref/no-pointer checks, matching active menu case, linked allocator and constructor owner pages, sibling-helper boundary recheck, source-placement/strict-gate clearance, and support-only alias disposition are documented. Completion stays unchanged because the source body is now emitted by [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md), not this alias. |
| Confidence `90` | Live IDA strongly confirms the helper body, decoded resource operands, constructor path, current unreferenced status, and direct parent assignment to a `89/86` source file. Confidence remains below final-audit levels because no live caller or callback table has been recovered. |

## Cross-References

- [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md)
- [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md)
- [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-06-12 Agent-A002 Batch 301:
  - Before: `84/88`, parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) but with stale strict-gate caveat and address evidence linked only to aggregate [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md).
  - After: `86/90`, parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), exact child range [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md).
  - Why: the exact child and direct parent now both clear the strict `85/85` gate; the old by-memory pair page was repaired into a non-emitting split index with exact child pages.
  - Evidence: live IDA MCP `b001_nexustk` reconfirmed the `0x7f` / 127-byte helper size, `0x108` / 264-byte allocation, exact end/successor boundary, allocator/constructor callees, history-resource xrefs, empty helper-entry xrefs, and active `MainMenuPane::ActivateMenuItem` duplicate history case.
- 2026-06-29 B004 accepted implementation:
  - Kept exact `86/90`, owner/emitter [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), reconstructable state, and blank formal C++.
  - Clarified support/search alias disposition: exact child [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md) owns the first-draft `static void OpenHistoryViewingPane()` body; this address-suffixed by-global page preserves symbol/source-placement evidence and must not duplicate the body.
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
- 2026-06-07 A008 alias cleanup:
  - Normalized the history resource-selection branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), retaining `byte_66DA97` as the historical IDA lookup alias.

### 2026-06-10 A001 linked-helper and strict-gate refresh

- What existed before: score was `80/86`; the page documented behavior, but still leaned on raw generated names for the allocator and constructor target and did not spell out the strict `85/85` gate caveat.
- What changed: score raised to `84/88`, linked [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) and [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md), added current MCP evidence, and made the parent-gate caveat explicit.
- Summary and evidence: live MCP reconfirmed the `0x004f9140` size `0x7f` helper has no entry xrefs/callers, calls only the shared allocator wrapper and `HistoryViewingPane` constructor, uses `HISTORY.EPF`/`HISTORY.EPD` at the same string addresses as the active main-menu branch, and has the expected sibling launcher boundaries. Scores remain below assignment/final-source level because retained-helper reachability is unresolved and likely parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) is below `85` confidence.
