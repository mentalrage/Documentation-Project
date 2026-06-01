*** UID:00009B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewSystemMessageModifyHeightPane

## Status

- Confidence: strong for role, globals, and IDA boundaries; generated source ownership has caveats.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewSystemMessageModifyHeightPane.cpp`

## Class Purpose

`NewSystemMessageModifyHeightPane` is the drag handle for resizing the newer system-message panel. It reads the saved message-panel height from the config object, tracks drag state, clamps the new height to a 70-175 pixel range, applies a preview rectangle through the owner panel, commits the height on release, and refreshes [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005881f0-0x005882b4` | constructor | Constructs the pane, stores [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md), loads the saved height from config, and initializes preview bounds. |
| `0x005882c0-0x005882e8` | non-deleting cleanup | Reinstalls vtables, clears `g_pHeightModifyPane`, and calls pane cleanup. Active generated output omits this body. |
| `0x005882f0-0x005884ab` | drag handler | Handles press/drag/release events, clamps height, updates preview rect, persists config height, and refreshes `g_pNewSystemMessagePane`. |
| `0x00588500-0x0058855b` | `OnPaint` | Loads `SYSBAR.EPF` and draws the grip using `invenbut.pal`. |
| `0x0058aaa0-0x0058aaaa` | singleton clear helper | Clears `g_pHeightModifyPane`. Active generated output omits this body. |
| `0x0058acc0-0x0058ad1e` | scalar deleting destructor | Clears `g_pHeightModifyPane`, tears down pane state, and conditionally deletes storage. |

## Generated Data Caveats

- Active `class_NewSystemMessageModifyHeightPane.cpp` also emits `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560`. IDA and metadata notes indicate that constructor belongs to [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md), not this height pane.
- Active output omits the non-deleting cleanup at `0x005882c0` and clear helper at `0x0058aaa0`.
- 2026-05-25 IDA recheck: `0x005882c0` reinstalls `NewSystemMessageModifyHeightPane` vtables, clears `g_pHeightModifyPane` at `0x0069bc0c`, and calls shared pane-base cleanup `0x00544580`; `0x0058aaa0` is the standalone singleton-clear helper for the same global.
- IDA `xrefs_to 0x0069bc0c` shows constructor writes at `0x00588239`/`0x00588240`, cleanup/destructor clears at `0x005882da`, `0x0058aaa0`, and `0x0058ace0`, and child construction inside `NewSystemMessagePane` at `0x00588620`/`0x00588627`.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md)
- [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite detailed resize-handle behavior, global ownership, method-map, and generated-data caveat notes.
- Changed to: `COMPLETION:78` and `CONFIDENCE:80`.
- Evidence: the page records drag/clamp/commit behavior, singleton global writes/clears, constructor/destructor/helper ranges, resource use, and IDA xrefs; remaining gaps are final generated-source partition cleanup and body-level C++ reconstruction.
