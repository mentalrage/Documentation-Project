*** UID:0000D1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerSelectMenuItemList

## Status

- Confidence: strong for active list behavior, medium for constructor boundary.
- Likely source file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Current recovered file: `source-3/simroot_v2/class_ServerSelectMenuItemList.cpp`
- Address range: [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)

## Class Purpose

`ServerSelectMenuItemList` is the list-pane widget used by `ServerSelectPane`. It forwards row activation to the owner pane and draws each server row as `Name : Description`, updating the selected server name in the application/session buffer when a row is highlighted.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Projected constructor | `0x005744a0-0x005744f7` | Wave3-modeled constructor, but IDA MCP does not currently define a function at `0x005744a0`. Treat as projected until reviewed. |
| `OnItemActivated` | `0x00574660-0x0057466a` | Tail-call style activation helper that tells the owner/server-select context to update pending selection state. |
| `DrawListItem` | `0x00574670-0x00574747` | Draws selected/unselected rows, formats `Name : Description`, and copies the selected server name to application state. |

## Evidence Notes

- Wave3 effective grade is `96.5`.
- IDA MCP confirms `0x00574660` and `0x00574670`, but reports no function at projected constructor start `0x005744a0`.
- Current generated source omits the projected constructor body and only emits the two active virtual methods.
- 2026-05-24 IDA MCP decompilation of `0x00574670` confirms the server-entry layout used by the selection helpers: `[entry + 4]` is server name, `[entry + 8]` is description, and selected rows copy the name into `g_pApplication + 2136`.
- Selection helper `0x00574510` uses the same entry pointer family and forwards the first byte plus endpoint fields to `0x005745b0`.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents active list behavior, owner/file grouping, by-memory range, confirmed virtual methods, entry layout, and helper relationship; confidence is limited by the projected constructor boundary.
