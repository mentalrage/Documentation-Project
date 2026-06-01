*** UID:00003E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CursorManager

## Status

- Confidence: strong for the recovered helper bodies, medium for typed-view identity, low for a separate allocated class.
- Likely source file: [UID:0000NB][ScreenPane](by-file/ScreenPane.md), with [UID:0000IL][CursorManager](by-file/CursorManager.md) retained as a provisional source-layout candidate.
- Main address range: [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_CursorManager.cpp`

## Class Purpose

`CursorManager` is the generated class view for root-screen cursor and dimension helpers. It exposes cached screen dimensions and switches the Win32 cursor handle used by the active UI state.

This is probably not a separately allocated manager object. The methods operate on the same root object stored in [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), and the generated [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) name is an alias over that storage in current evidence. The dimension fields are initialized by [UID:0000CB][ScreenPane](by-class/ScreenPane.md). Use `CursorManager` as a provisional typed view until the final `ScreenPane` layout and source split are resolved.

The 2026-05-26 IDA check found no constructor, destructor, allocation site, or singleton lifetime for a distinct cursor manager. It did confirm that `ScreenPane::ScreenPane` initializes the screen singleton and dimensions but does not initialize the cursor handle table, so cursor-resource loading remains a separate open path.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetActiveCursor` | `0x005573f0-0x0055742b` | Updates active cursor index, loads a handle from the object-local cursor table, calls `SetCursor`, and makes the cursor visible. |
| `GetScreenWidth` | `0x00557450-0x00557457` | Returns cached screen width from the root screen object. |
| `GetScreenHeight` | `0x00557460-0x00557467` | Returns cached screen height from the root screen object. |

## Nearby Helpers

- `0x00557380-0x005573a0`: root screen dirty/update helper; sets byte offset `+0x118` and merges state through the helper region at `+0x11c`.
- `0x005573b0-0x005573e2`: presentation/timer request helper; calls the local presentation helper and schedules immediate/delayed timer callbacks through the `+0xa4` subobject.
- `0x00557430-0x00557448`: tiny `ShowCursor(TRUE/FALSE)` wrappers.

## Data Notes

- Cursor handle table: IDA places the table at word offset `680`, byte offset `+0x550`.
- Active cursor index: IDA places it at word offset `704`, byte offset `+0x580`.
- Screen width/height: IDA confirms getters read word offsets `137` and `138`, byte offsets `+0x112` and `+0x114`, matching `ScreenPane::ScreenPane` initialization.
- `ScreenPane::ScreenPane` initializes the singleton, root layer list at dword offset `67` / byte offset `+0x10c`, dimensions, and frame/fade fields, but not the cursor handle table at `+0x550`.
- 2026-05-26 recheck: IDA MCP still reports no separate cursor-manager constructor/lifetime. Current active simroot output still emits these methods in `class_CursorManager.cpp`, but all observed lifetime evidence belongs to `ScreenPane` / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md).

## Cross-References

- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/68`.
  - Summary/evidence: helper bodies, cursor/dimension offsets, root screen relationship, and absence of separate lifetime evidence are documented; confidence stays lower because the `CursorManager` class identity is probably a generated typed view over `ScreenPane` storage.
