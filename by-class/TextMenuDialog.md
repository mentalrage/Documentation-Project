*** UID:0000ES | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextMenuDialog

## Status

- Confidence: strong for behavior and boundaries; generated source still has method-name/control-character caveats.
- Likely source file: [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_TextMenuDialog.cpp`

## Class Purpose

`TextMenuDialog` is a packet-driven NPC/merchant text menu. It parses a server packet for dialog id, subtype, portrait/object image data, text, optional extra string, and menu entries. It then builds either a small direct-button layout or a scrollable list layout and sends opcode `0x39` responses for selections.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00517ec0-0x00517f25` | `SendMenuRequestPacket` | Sends cancel/request packet opcode `0x43`, subtype `1`, with the dialog id, then closes the dialog. |
| `0x00517f30-0x00518e16` | `TextMenuDialog` | Constructor and packet parser; builds `DLGMERC1`/EPD or EPF dialog layout and creates `TextMenuItemList` when needed. |
| `0x00518e20-0x00519101` | `OnPaint` | Draws the merchant/menu background and portrait/object assets for the older tile-backed path before base paint. |
| `0x00519210-0x005194b0` | `OnDialogAction` | Handles OK/cancel/close/menu selections and writes opcode `0x39` response payloads. |
| `0x005194c0-0x00519510` | `UpdateScrollButtons` | Updates action/scroll button state after selection changes. |
| `0x00520b3f-0x00520b54` | vtable adjustor thunks | Compiler-generated this-adjustors forwarding to the destructor. |
| `0x00520da0-0x00520de7` | scalar deleting destructor | Releases the embedded `LObject`, destroys base dialog state, and deletes according to flags. |

## Evidence Notes

- Wave3 summary: network-driven NPC text menu dialog that parses server packets and handles menu selections.
- Wave3 notes identify key fields: dialog id at `0x270`, dialog subtype at `0x274`, item count at `0x278`, extra-string flag at `0x279`, `LObject` at `0x27c`, and menu item ids at `0x280`.
- IDA MCP confirms the main methods, vtable-referenced thunks, and destructor starts listed above.
- Direct callers of the constructor sit in the nearby dialog-packet dispatch area around `0x005174df`, `0x0051752d`, `0x00517809`, and `0x00517899`.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `84`.
- Evidence: the page documents packet-driven menu behavior, constructor/paint/action/update/destructor-thunk ranges, key fields, caller evidence, vtable family, and related text-input/list/dialog classes; confidence remains slightly capped by generated source name/control-character caveats.
