*** UID:00008Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00008Y NewArticleDialog class-level source is covered by UID0000HT BoardDialogs and the exact emitting child UID00030K NewArticleDialogCore. This page emits no standalone partial class declaration until field/header names and the final article-dialog source split are source-quality.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewArticleDialog

## Status

- Confidence: very strong for behavior, direct class ownership, board-dialog module placement, transfer-reply method identity, and post-packet serialization; medium for exact original member/header names.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md), with shared non-emitting destructor companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)

## Autogen Status

- Parent file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Reconstructable: true.
- Class-level output is marker-only because exact field/header names and the final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` source split are not source-final. The direct child [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) now carries first-draft method-body C++ for the normal compose-dialog cluster.
- Recovered class-file names are only historical search leads on the file parent; this class page now uses by-file/by-memory/by-vtable evidence for ownership.

## Class Purpose

`NewArticleDialog` is the bulletin-board article composition dialog. It collects subject/body text, validates or sanitizes it through existing text helpers, serializes the post packet, and handles post transfer replies.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewArticleDialog` | `0x00476c10-0x00477150` | Creates compose dialog controls and initializes article-post state. |
| retained previous-selection navigation helper | `0x00477160-0x004771a8` | Raw retained helper that reaches shared article navigation helper `0x004751c0` from callsite `0x004771a2`; no direct route is known, but it is class-shaped source logic. |
| `OnCommand` / `HandleButtonClick` | `0x004771b0-0x00477211` | Command `1` submits using `BulletinSession +0x102` board/context id, restores modal dialog state at `DAT_0067a748 + 0x214`, and starts the dimmer; command `2` pops/cancels through `DialogSession`. |
| `HandlePostError` / `OnPostFailed` | `0x00477220-0x004772d2` | Releases active dimmer state and constructs `TransferReplyAlert` with the wide error text and mode `0`. |
| `SetHoverControl` | `0x004772e0-0x004772e8` | One-call DialogPane hover-control forwarder to `0x0049fc00`; the old `SetChildCount`/state-setter label is rejected. |
| `HandleTransferReplyPacket` | `0x004772f0-0x00477442` | Vtable-backed reply handler for packet layout `unused/opcode, subcommand 0x06, reply mode, message length, message bytes`. |
| `HandleTransferReplyPayload` | `0x00477450-0x00477588` | Retained shifted payload-layout helper with no exported callers; starts at `mode,length,text...`, parallel to NewPredefined helper `0x00478aa0`. |
| `SubmitArticle` / `SendPostArticlePacket` | `0x00477590-0x0047778f` | Reads subject control index `4` and body control index `5`, validates/sanitizes text, sends opcode `0x3b` subcommand `4`, and starts a `15000` ms transfer wait. |
| shared scalar deleting destructor | [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) | Non-emitting MSVC wrapper shared through board/article dialog vtables; source reconstruction should express the class hierarchy and let the compiler regenerate it. |

## Evidence Notes

- IDA MCP confirms the constructor, command handler, and send-packet boundaries.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `85/86`, stages the board/article dialog bucket under `NexusTK/ui/dialogs/`, and lists `NewArticleDialog` as the normal article compose dialog with post-packet serialization.
- [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) now records the exact normal compose-dialog method/helper cluster, one raw selected-control helper, direct `BulletinSession` construction caller, command-to-send relationship, and post-packet helper callees.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `NewArticleDialog` primary/secondary/tertiary vtable bases `0x00613fb0`, `0x00614014`, and `0x00614044`, with constructor stores at `0x00476c56`, `0x00476c5c`, and `0x00476c66`.
- B006's 2026-06-27 source-quality implementation records that this class consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) through the secondary view at `0x00614014 + 0x10`: slot `0x00614024` stores `0x00472040`. This is one consumer slot of the shared command-`'1'` secondary bridge, not a NewArticleDialog-owned method body; class-level output is marker-only until the common secondary interface, event/action type, and primary `+0x5c` dispatch declaration are source-quality.
- `NewPredefinedFormArticleDialog` is adjacent template/form article feature work and now has its own source-layout page because its constructor/parser are much larger than the normal article composer.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x00476c10` returns the `BulletinSession` call at `0x00471371`; `callers 0x00477590` returns the command-handler call at `0x004771ee`; `xrefs_to 0x00613fb0` returns the primary vtable store at `0x00476c56` inside `sub_476C10`.
- 2026-06-10 B001-025 created exact shared non-emitting destructor companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md); IDA reports `NewArticleDialog` vtable/data ref `0x00613fb0` among the shared destructor wrapper refs.
- 2026-06-21 B005 source-quality reanalysis resolved the stale method identities on the core child: `0x004772e0` is `SetHoverControl`, `0x00477450` is a shifted transfer-reply payload helper, and `0x00477590` serializes opcode `0x3b` subcommand `4` with subject/body controls `4`/`5`, validation, sanitizer, big-endian board/body fields, and a `15000` ms wait.

## Source-Quality Notes

- The final source class should expose normal compose-dialog methods rather than decompiler labels such as `sub_477590`, `virt_meth_0x4772f0`, or `FUN_00477450`.
- `BulletinSession +0x102` is the board/context id used by submit; `DAT_0067a748 + 0x214` is the active modal/dialog host slot restored before the dimmer is created. Both names remain inferred and should be unified with the wider session/UI-state passes.
- Constructor branches are asset-mode variants of the same layout: EPF uses `DLGBBS04.EPF`/`DLGBBS04.PAL`; legacy uses `DLGBBS04.EPD`/`NPAL8.PAL`. Both create title, subject, body, submit, and cancel controls.
- `HandleTransferReplyPacket` and `HandleTransferReplyPayload` should remain documented as separate binary bodies. A source cleanup may route the full-packet handler through the payload helper, but the by-memory evidence must preserve the no-xref retained helper fact for `0x00477450`.

## Score Rationale

Completion is raised to `87` because the class now has a stable parent file bucket, exact core child coverage, confirmed compose/control/error/reply/send method inventory, corrected `SetHoverControl` and shifted transfer-reply helper identities, source-quality post packet layout, board/article aggregate context, vtable-family evidence, and a child-level draft C++ route. Confidence rises to `89` because local export reanalysis agrees with the existing live IDA caller/xref checks and NewPredefined analogs. The score stays below final because exact original member names, class declaration shape, and source-file split are still inferred.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)
- [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)

## Changes

- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Score and owner/emitter unchanged at `87/89`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Added the secondary `0x00614014 + 0x10 -> 0x00614024 -> 0x00472040` consumer-slot note, preserving class-level C++ blankness and the shared-interface/source-split caveat.
- 2026-06-21 B005 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`; method notes still used stale `SetChildCount`/state-setter wording and did not distinguish the shifted transfer-reply payload helper.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:89`; method notes now name the retained navigation helper, command handler, post-error handler, `SetHoverControl`, full-packet reply handler, shifted payload helper, and submit packet serializer with packet/control details.
  - Summary/evidence: B005 source-quality reanalysis of [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) resolved post-packet fields, subject/body control indexes, validation/sanitization dependencies, `TransferReplyAlert` reply/error construction, and the NewPredefined analog for the retained payload helper. Exact original member names and class declaration C++ remain open.
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
