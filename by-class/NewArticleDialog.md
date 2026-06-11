*** UID:00008Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewArticleDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md), with shared non-emitting destructor companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)

## Autogen Status

- Parent file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Reconstructable: true.
- Final C++ remains blank because post-packet/body-control field names, raw-helper reachability, and final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` source placement are not source-final.
- Recovered class-file names are only historical search leads on the file parent; this class page now uses by-file/by-memory/by-vtable evidence for ownership.

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
| shared scalar deleting destructor | [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) | Non-emitting MSVC wrapper shared through board/article dialog vtables; source reconstruction should express the class hierarchy and let the compiler regenerate it. |

## Evidence Notes

- IDA MCP confirms the constructor, command handler, and send-packet boundaries.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `85/86`, stages the board/article dialog bucket under `NexusTK/ui/dialogs/`, and lists `NewArticleDialog` as the normal article compose dialog with post-packet serialization.
- [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) now records the exact normal compose-dialog method/helper cluster, one raw selected-control helper, direct `BulletinSession` construction caller, command-to-send relationship, and post-packet helper callees.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `NewArticleDialog` primary/secondary/tertiary vtable bases `0x00613fb0`, `0x00614014`, and `0x00614044`, with constructor stores at `0x00476c56`, `0x00476c5c`, and `0x00476c66`.
- `NewPredefinedFormArticleDialog` is adjacent template/form article feature work and now has its own source-layout page because its constructor/parser are much larger than the normal article composer.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x00476c10` returns the `BulletinSession` call at `0x00471371`; `callers 0x00477590` returns the command-handler call at `0x004771ee`; `xrefs_to 0x00613fb0` returns the primary vtable store at `0x00476c56` inside `sub_476C10`.
- 2026-06-10 B001-025 created exact shared non-emitting destructor companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md); IDA reports `NewArticleDialog` vtable/data ref `0x00613fb0` among the shared destructor wrapper refs.

## Score Rationale

Completion is raised to `85` because the class now has a stable parent file bucket, exact core child coverage, confirmed compose/control/error/state/reply/send method inventory, board/article aggregate context, and vtable-family evidence. Confidence rises to `86` because live IDA caller/xref checks agree with the direct class owner, but final C++ remains gated on post-packet/body-control field names and raw helper reachability.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)
- [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed compose/control/error/state/reply/send starts at `0x00476c10`, `0x004771b0`, `0x00477220`, `0x004772e0`, `0x004772f0`, and `0x00477590`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion attachment gate even though [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `78/84`. Summary: the board article composition dialog has clear module placement, constructor/command/error/transfer/send methods, inheritance context, and adjacent predefined-form split documented, but packet serialization and UI control internals are not yet exhaustive. Evidence: linked `BoardArticleDialogs` memory range, board vtable family, IDA-confirmed constructor/command/send boundaries, and relationship to `NewPredefinedFormArticleDialog`.
- 2026-06-07:
  - Before: score stayed at `78/84`, `AUTOGEN_PARENT_UID` was blank, and status still named the recovered class file as current context.
  - After: raised completion to `80`, attached parent [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), removed generated-source dependency, and added autogen-status/evidence/score-rationale sections.
  - Summary/evidence: the file parent, board/article aggregate, and board/article vtable-family page now provide durable ownership evidence while exact child splits and post-packet/body-control internals remain open.
- 2026-06-08 A008 Batch 107 continuation:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`, and the page still treated the exact compose child split as pending.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: exact child [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) now covers the normal compose-dialog method/helper cluster; live IDA rechecked the `BulletinSession` constructor caller, command-to-send caller, and primary vtable-store xref. This clears the direct class-parent gate for the child while preserving post-packet/body-control and raw-helper caveats.
- 2026-06-10 B001-025:
  - Changed: linked the class to shared non-emitting companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md).
  - Summary/evidence: IDA MCP confirms the destructor wrapper is ABI glue shared through `NewArticleDialog` vtable/data ref `0x00613fb0` and other bulletin/board/article dialog vtables.
