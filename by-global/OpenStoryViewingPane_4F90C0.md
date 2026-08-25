*** UID:0000TE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// OpenStoryViewingPane is emitted by exact helper [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OpenStoryViewingPane_4F90C0

## Status

- Confidence: very strong for behavior, exact child range, source owner, and current unreferenced status; medium for why the wrapper was retained.
- Address range: [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md)
- Likely owner source: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Parent status: assigned to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) after this helper's exact by-memory child reached `86/90` and the direct parent remains `89/86`.
- Support role: address-suffixed search/symbol alias only. The exact by-memory child [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md) owns the emitted `static void OpenStoryViewingPane()` body; this alias keeps blank formal C++ and exact score `86/90`.

## Function Role

`OpenStoryViewingPane_4F90C0` is a small helper that allocates a `0x108`-byte / 264 decimal byte (Verified with `int_convert.py`) [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) and passes the story resource selected by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md): `STORY.EPF` in EPF/high-layout mode or `STORY.EPD` in legacy mode.

This duplicates the story branch inside `MainMenuPane::ActivateMenuItem`. Current IDA reports no callers or xrefs to the helper start, and 2026-05-28 raw pointer/immediate searches also found no hidden references. Treat it as a real retained duplicate helper unless later evidence proves a callback path.

The final emitted helper name omits the address suffix. Use this page for symbol/search history and source-placement evidence only; do not duplicate the body emitted by [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md).

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f90c0` reports a real function of size `0x7f`.
- IDA MCP callees are allocator `0x004f4aa0` and `HistoryViewingPane::HistoryViewingPane` at `0x004ffd80`.
- IDA MCP reports no direct callers and no xrefs to `0x004f90c0`.
- The constructor call sites inside this helper appear as `0x004f910c` and `0x004f912b` in `callers 0x004ffd80`.
- 2026-06-04 live IDA reports the function as `0x004f90c0-0x004f913f`, followed by one `0xcc` byte before the history helper at `0x004f9140`.
- 2026-06-04 live IDA reports no xrefs to `0x004f90c0` and zero loaded-segment dword hits for `0x004f90c0`.
- 2026-06-04 live disassembly shows an SEH/security-cookie frame, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` branch, allocation size `0x108`, non-null allocation check, and constructor call through `sub_4FFD80`.
- 2026-06-04 live string-byte decoding confirms the resource operands as `STORY.EPF` at `0x0061e128` and `STORY.EPD` at `0x0061e13c`.
- 2026-06-04 live decompile of `sub_4F7A10` confirms active menu case `3` directly duplicates this allocation/resource/constructor sequence.
- 2026-05-26 IDA recheck still reports zero code refs and zero data refs to the helper start.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dword equal to `0x004f90c0`.
- 2026-05-28 IDA MCP recheck still reports no code/data refs, no little-endian pointer byte match for `c0 90 4f 00`, and no immediate-value search hits for `0x004f90c0`.
- 2026-05-28 IDA MCP decompile of `0x004f7a10` shows the active story menu case directly allocating `264` bytes and calling `0x004ffd80` with the story resource, matching this wrapper's behavior without calling the wrapper.
- 2026-06-10 A001 live IDA MCP `lookup_funcs` reconfirms `sub_4F90C0` at `0x004f90c0` with size `0x7f`, 127 decimal bytes (Verified with `int_convert.py`), and confirms `0x004f913f` is not a function head while the adjacent history helper begins at `0x004f9140`.
- 2026-06-10 `callees 0x004f90c0` reports only allocator `0x004f4aa0` and [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) constructor `0x004ffd80`; `callers 0x004f90c0` remains empty.
- 2026-06-10 `callers 0x004ffd80` reports active [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) call sites at `0x004f7b8d`/`0x004f7bc3` for the story branch, `0x004f7c07`/`0x004f7c3d` for the history branch, plus retained wrapper calls at `0x004f912b` and `0x004f91ab`.
- 2026-06-10 `xrefs_to` confirms the story resource operands are referenced by this helper at `0x004f9107` for `STORY.EPF` (`0x0061e128`) and `0x004f9124` for `STORY.EPD` (`0x0061e13c`), matching the active menu-handler sites at `0x004f7b86` and `0x004f7bbc`.
- 2026-06-10 decompilation of `0x004f90c0` still reduces to the `g_useEpfAssets` branch, `0x108` allocation, null check, and constructor call; disassembly shows the SEH/security-cookie frame, `cmp byte_66DA97, 1`, `push 108h`, resource pointer push, and constructor dispatch at `0x004f912b`.
- 2026-06-10 decompilation of `0x004f7a10` confirms active menu cases `3` and `4` inline the same story/history allocation and constructor behavior instead of calling these retained wrappers.
- 2026-06-12 A002 split/route pass created exact child [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md) from the former pair aggregate [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md).
- 2026-06-12 A002 live IDA MCP session `b001_nexustk` reconfirmed `sub_4F90C0` at `0x004f90c0` with size `0x7f` / 127 bytes (Verified with `int_convert.py`), non-function end boundary `0x004f913f`, successor `sub_4F9140` at `0x004f9140`, `0x108` / 264-byte allocation (Verified with `int_convert.py`), resource pushes at `0x004f9107` and `0x004f9124`, and constructor call at `0x004f912b`.
- 2026-06-12 A002 `xrefs_to` reconfirmed zero helper-entry xrefs to `0x004f90c0`; `xrefs_to 0x004ffd80` showed active story call sites at `0x004f7b8d`/`0x004f7bc3` and the retained helper call at `0x004f912b`.
- 2026-06-12 A002 `xrefs_to` reconfirmed `STORY.EPF` at `0x0061e128` is used by active menu site `0x004f7b86`, this helper at `0x004f9107`, and `BackStoryDialogPane` sites; `STORY.EPD` at `0x0061e13c` is used by active menu site `0x004f7bbc`, this helper at `0x004f9124`, and `BackStoryDialogPane` sites.
- 2026-06-29 B004 MCP session `992d23de` reconfirmed the exact `0x7f` / 127-byte child body, `0x108` / 264-byte allocation, `g_useEpfAssets == 1` branch, constructor/resource xrefs, zero helper-entry xrefs/callers, and zero VA/RVA pointer-byte routes. The exact child now carries first-draft `static void OpenStoryViewingPane()` C++; this by-global page remains a blank-C++ alias at exact `86/90`.

## Source Layout Decision

Keep this with `login/MainMenuPane.cpp` as a menu action helper for address-matching reconstruction unless later xrefs prove a separate callback table or dead-code exclusion. Do not place it in `HistoryViewingPane.cpp`; the helper selects the menu resource and allocates the viewer, while `HistoryViewingPane` owns viewer behavior. A behavior-only source rebuild can rely on the direct action-handler construction path.

## Autogen Status

- Reconstructable: true, as a retained project helper with exact behavior and boundary evidence.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The child and actual direct parent now clear the strict `85/85` route gate.
- C++: intentionally blank because this is a support/search alias. Emitted source belongs to exact child [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md); duplicating it here would double-emit the same function body.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | Exact boundary, exact child by-memory page, function size, padding relationship, resource operands, allocator/constructor behavior, direct no-caller status, constructor caller matrix, matching active menu cases, source-placement caveat, strict parent-gate clearance, and support-only alias disposition are documented. Completion stays unchanged because the source body is now emitted by [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md), not this alias. |
| Confidence `90` | Live IDA strongly confirms the helper body, decoded resource operands, constructor path, direct lack of callers, duplicated active menu behavior, and direct parent assignment to a `89/86` source file. Confidence remains below final-audit levels because no live caller or callback table has been recovered. |

## Cross-References

- [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md)
- [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-06-12 Agent-A002 Batch 301:
  - Before: `84/88`, parent blank, address evidence linked only to aggregate [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md).
  - After: `86/90`, parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), exact child range [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md).
  - Why: the exact child and direct parent now both clear the strict `85/85` gate; the old by-memory pair page was repaired into a non-emitting split index with exact child pages.
  - Evidence: live IDA MCP `b001_nexustk` reconfirmed the `0x7f` / 127-byte helper size, `0x108` / 264-byte allocation, exact end/successor boundary, allocator/constructor callees, story-resource xrefs, empty helper-entry xrefs, and active `MainMenuPane::ActivateMenuItem` duplicate story case.
- 2026-06-29 B004 accepted implementation:
  - Kept exact `86/90`, owner/emitter [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), reconstructable state, and blank formal C++.
  - Clarified support/search alias disposition: exact child [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md) owns the first-draft `static void OpenStoryViewingPane()` body; this address-suffixed by-global page preserves symbol/source-placement evidence and must not duplicate the body.
- 2026-06-04: Raised completion/confidence from `72/80` to `80/86` after live IDA verified the exact helper boundary, internal padding relationship, no entry xrefs, zero loaded dword hits, decoded `STORY.EPF`/`STORY.EPD` operands, raw instruction shape, and matching active `MainMenuPane` story case.
- Before: the page recorded older behavior/no-reference checks but lacked current padding, resource operand, and instruction-level evidence.
- After: the symbol summary now mirrors the stronger by-memory evidence while keeping final C++ blank and source retention unresolved.
- Why: live IDA proves the helper is real retained project code and strengthens the duplicate/unreferenced interpretation, but still finds no caller or callback table.
- Evidence: 2026-06-04 IDA MCP function lookup, byte checks, `xrefs_to`, loaded pointer scan, operand string decoding, helper disassembly, and `sub_4F7A10` decompile.
- Before: documented as a retained helper with weak unresolved reachability.
- After: documented as a retained duplicate launcher whose current lack of refs has been rechecked; the active main-menu story action is documented as directly duplicating the allocation/constructor sequence.
- Why: IDA MCP found no direct or raw-pointer references to `0x004f90c0`, while `0x004f7a10` story case performs the same `264`-byte allocation and `0x004ffd80` constructor call.
- Evidence: 2026-05-28 IDA MCP `xrefs_to`, `callers`, `find_bytes`, immediate `search`, and `decompile 0x004f7a10`.
- 2026-06-02 score and parent update:
  - What existed before: the helper was scored `65/65` with no reconstructable parent attachment.
  - Changed to: completion `72`, confidence `80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000L0`.
  - Summary/evidence: exact function size, callees, call sites, repeated no-xref scans, and duplicated active main-menu construction support treating this as retained `MainMenuPane.cpp` project code while keeping C++ blank.
- 2026-06-07 A008 alias cleanup:
  - Normalized the story resource-selection branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), retaining `byte_66DA97` as the historical IDA lookup alias.
- 2026-06-10 A001 live refresh and parent-gate repair:
  - Before: scored `80/86` and assigned to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) even though that likely direct parent was `88/82`.
  - Changed to: `84/88`, blank `AUTOGEN_PARENT_UID`, added current IDA function/callee/caller/xref/decompile/disassembly evidence, and recorded `int_convert.py` checks for `0x7f` and `0x108`.
  - Why: the helper is still strongly confirmed as retained project code, but the strict child/direct-parent gate blocks assignment until `MainMenuPane` reaches at least `85/85`.
