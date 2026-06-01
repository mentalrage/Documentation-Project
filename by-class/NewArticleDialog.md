*** UID:00008Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewArticleDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_NewArticleDialog.cpp`

## Class Purpose

`NewArticleDialog` is the bulletin-board article composition dialog. It collects subject/body text, validates or sanitizes it through existing text helpers, serializes the post packet, and handles post transfer replies.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewArticleDialog` | `0x00476c10-0x00477150` | Creates compose dialog controls and initializes article-post state. |
| `OnControlCommand` | `0x004771b0-0x00477211` | Handles send/cancel/control commands. |
| `OnPostError` | `0x00477220-0x004772d2` | Handles post failure alert or recovery flow. |
| `SetChildCount` | `0x004772e0-0x004772e8` | Tiny state setter currently attached by Wave3. |
| `HandleTransferReplyAlert` | `0x004772f0-0x00477442` | Handles server transfer/post acknowledgement alert. |
| `SendPostArticlePacket` | `0x00477590-0x0047778f` | Serializes subject/body text and sends bulletin post opcode data. |

## Evidence Notes

- Wave3 notes identify the inheritance chain as `BulletinDialog` -> `DialogInSession` -> `DialogPane` -> `Pane` -> `GrafPort` -> `LObject`.
- IDA MCP confirms the constructor, command handler, and send-packet boundaries.
- `NewPredefinedFormArticleDialog` is adjacent template/form article feature work and now has its own source-layout page because its constructor/parser are much larger than the normal article composer.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/84`. Summary: the board article composition dialog has clear module placement, constructor/command/error/transfer/send methods, inheritance context, and adjacent predefined-form split documented, but packet serialization and UI control internals are not yet exhaustive. Evidence: linked `BoardArticleDialogs` memory range, board vtable family, IDA-confirmed constructor/command/send boundaries, and relationship to `NewPredefinedFormArticleDialog`.
