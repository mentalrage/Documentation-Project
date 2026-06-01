*** UID:0000QP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCursorManager

## Status

- Confidence: strong that this is an alias of [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), not a separate proven singleton.
- Current generated kind: `global-data` alias / typed view.
- Canonical storage: [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- Likely owner file: [UID:0000NB][ScreenPane](by-file/ScreenPane.md), with helper calls documented through [UID:0000IL][CursorManager](by-file/CursorManager.md)

## Purpose

`g_pCursorManager` is the generated name used when code calls cursor-switching and screen-dimension helper methods. Current evidence shows it points to the same root screen object as [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md). Do not emit this as a second global declaration unless later constructor/allocation evidence proves a distinct cursor manager object.

For source reconstruction, prefer `g_pScreenPane` plus local typed accessors or casts. The generated alias is valuable for finding cursor call sites, but it is not ownership evidence for a standalone global.

## Evidence Notes

- Current `source-3/simroot_v2/class_CursorManager.cpp` still emits `SetActiveCursor`, `GetScreenWidth`, and `GetScreenHeight` as methods over a synthetic `CursorManagerLayout`, but no separate constructor or singleton lifetime is present.
- Current browser generated output still calls `CursorManager::SetActiveCursor(g_pCursorManager, ...)` in browser activation/visibility paths.
- IDA MCP lookup on 2026-05-26 confirms the helper island at [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md).
- IDA MCP decompilation of `ScreenPane::ScreenPane` at `0x00556910` writes `dword_67A7CC = this` and initializes width/height at word offsets `137` and `138`.
- IDA MCP decompilation of the generated `CursorManager` accessors at `0x00557450` and `0x00557460` reads those same word offsets.
- IDA MCP decompilation of `0x005573f0` uses the cursor handle table at byte offset `+0x550` and active cursor word at `+0x580` on the same object.
- IDA MCP decompilation of `ScreenPane::ScreenPane` initializes the root layer list and dimensions but does not initialize the `+0x550` cursor handle table, leaving cursor-resource loading as an unresolved ScreenPane/cursor setup path.
- IDA MCP `py_eval` on 2026-05-26 reports `0x0067a7cc` as a 4-byte `.data` item named `dword_67A7CC` with 145 data xrefs.

## Migration Guidance

Use `g_pScreenPane` as the source-level storage. If the final source keeps `CursorManager` as a separate helper class, pass or cast the screen singleton through that typed view locally; do not create a second `g_pCursorManager` storage definition.

## Cross-References

- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:00003E][CursorManager](by-class/CursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `-1/-1`. Summary/evidence: the page states `g_pCursorManager` is a generated alias/typed view of canonical [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), not separate proven storage, so it should be excluded from completion statistics.
