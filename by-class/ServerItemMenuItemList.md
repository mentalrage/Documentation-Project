*** UID:0000D0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerItemMenuItemList

## Status

- Confidence: strong for item-menu list behavior; medium for generated scattered-method ownership.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- Main address range: [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- Current recovered file: `source-3/simroot_v2/class_ServerItemMenuItemList.cpp`

## Class Purpose

`ServerItemMenuItemList` is the row-list widget for server-provided item action menus. It stores packet/item context, maintains selected-row description text, forwards activation into the owning menu context, and draws rows with item icon, display name, and right-aligned value.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `ServerItemMenuItemList` | `0x0051ae90-0x0051aefc` | Raw constructor-shaped code; builds a `ListPane` with server menu row geometry and installs three `ServerItemMenuItemList` vtables. |
| non-deleting destructor | `0x0051af00-0x0051af35` | Resets vtables, notifies `g_serverItemMenuObserver`, and tail-calls shared `ListPane` cleanup. |
| append row helper | `0x0051af40-0x0051afbf` | Builds a server item row record from id/style/value/name/detail strings and appends it to the list. |
| selected-name packet helper | `0x0051afd0-0x0051b0f8` | Builds opcode `0x39` payload from the selected row's wide display string. |
| `OnItemSelected` | `0x0051b100-0x0051b18d` | Updates owner text slot `7` from the selected row detail text before delegating to `ListPane`. |
| explicit-text packet helper | `0x0051b190-0x0051b2a8` | Builds opcode `0x39` payload from a caller-supplied wide string. |
| `OnItemActivated` thunk | `0x0051b2b0-0x0051b2bb` | Loads owner/context from `this + 0x158` and jumps to shared activation logic at `0x0049de70`. |
| `HandleMenuEvent` | `0x0051b2c0-0x0051b3e0` | Handles row pointer/event logic and high-resolution help-pane behavior. |
| `DrawListEntry` | `0x0051b3e0-0x0051b87a` | Draws item icon, name, and numeric value in high-resolution and legacy layouts. |
| destructor thunks | `0x00520b13`, `0x00520b1e`, `0x00520ce0` | Secondary/tertiary adjustor thunks and scalar deleting destructor. |

## Evidence Notes

- IDA MCP reports no function object at `0x0051ae90`, but disassembly confirms a complete constructor ending before alignment at `0x0051aefc`.
- IDA MCP confirms vtable xrefs for `0x0051b100`, `0x0051b2b0`, `0x0051b2c0`, and `0x0051b3e0` from the `ServerItemMenuItemList` vtable.
- The out-of-line constructor at `0x0051ae90` has no direct IDA xrefs. `ServerItemMenuDialog` contains inline-equivalent list setup and vtable writes while parsing server packet rows.
- Generated methods at `0x00474da0`, `0x0047ac30`, `0x004aec80`, and `0x004f3bd0` should not be treated as final item-menu ownership. IDA caller fanout ties them to article/mail pagination, other list panes, or shared `ListPane` state.
- Active generated `HandleMenuEvent` source is malformed: it starts an event struct and then flows into the `DrawListEntry` install marker rather than emitting the real `0x0051b2c0` body.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents constructor-shaped code, destructor, row append, packet helpers, activation/event/draw behavior, destructor thunks, vtable xrefs, and generated ownership warnings; confidence stays medium-high because constructor and scattered helper ownership need final source placement.
