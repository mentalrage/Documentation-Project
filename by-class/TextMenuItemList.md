*** UID:0000ET | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextMenuItemList

## Status

- Confidence: strong for list-pane role and boundaries; some helper/thunk bodies are omitted from current emitted source.
- Likely source file: [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_TextMenuItemList.cpp`

## Class Purpose

`TextMenuItemList` is the private scrollable row list used by `TextMenuDialog`. It stores a menu type, owner/context id, owner dialog pointer, and row records containing a 16-bit menu item id followed by UTF-16 label text.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00519520-0x00519580` | `TextMenuItemList` | Constructs the `ListPane` with text-menu row geometry and stores owner context. |
| `0x00519590-0x005195e7` | `AddTextEntry` | Builds a temporary row record from item id and label text, then appends it to the list. |
| `0x00519840-0x0051984a` | selection-state forwarder | Thin virtual helper/forwarder for owner menu selection state; Wave3 treats it as excluded. |
| `0x00519850-0x005198d0` | `DrawListItem` | Draws a highlighted or normal list row and renders the wide label text. |
| `0x00520b55-0x00520b6a` | vtable adjustor thunks | Compiler-generated this-adjustors forwarding to the destructor. |
| `0x00520df0-0x00520e2a` | scalar deleting destructor | Destroys embedded list state and deletes according to flags. |

## Evidence Notes

- Wave3 summary: maintains and renders text-menu dialog rows, including entry creation and scalar-destruction behavior.
- IDA MCP confirms all listed function starts. The constructor has callers inside `TextMenuDialog` at `0x0051814d` and `0x005186d4`; `AddTextEntry` is called from the large-list branch at `0x005189ed`.
- The active generated `.cpp` currently omits some excluded helper/thunk bodies even though Wave3 metadata and IDA know about them; this is tracked in [wave3_data_issues](../wave3_data_issues.md).

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `82`.
- Evidence: the page documents private list role, row layout, constructor/add/forwarder/draw/destructor-thunk ranges, caller evidence, and current emitted-source omissions; confidence remains capped by omitted helper/thunk bodies.
