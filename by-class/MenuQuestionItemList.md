*** UID:00007Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionItemList

## Status

- Confidence: strong for support-widget ownership; selection-confirm helper still needs naming review.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) clears at `89/85`, but this child remains `80/84`.
- Final C++ gate: keep blank until the selection-confirm virtual name/prototype, row record type, and `ListPane` base method names are confirmed.

## Class Purpose

`MenuQuestionItemList` is a `ListPane`-derived widget used by `MenuQuestionDialog`. It stores the owner dialog pointer, displays selectable wide-string menu labels, and draws selected rows with highlight/background palette changes.

It is the normal-layout sibling of [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md). Both list widgets are private support classes for the menu-question constructors in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), not generic menu/list infrastructure.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00550d50-0x00550db4` | `MenuQuestionItemList::MenuQuestionItemList(unsigned int ownerPane)` | Constructs the list pane, stores the owner dialog pointer, and installs `MenuQuestionItemList` vtables. |
| `0x00550e30-0x00550e3b` | `OnSelectionConfirmed()` | Tiny selection-confirm virtual helper; final source name/prototype still open. |
| `0x00550e40-0x00550ec1` | `OnPaintItem(...)` | Draws a row label from a record whose wide-string text begins at offset `+2`; selected rows use the menu-question highlight/background path. |

## Evidence Notes

- Existing IDA MCP notes in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) confirm exact starts at `0x00550d50`, `0x00550e30`, and `0x00550e40`.
- Constructor xrefs are from `MenuQuestionDialog` constructors at `0x0054eb04` and `0x0054f276`, supporting private support-widget ownership.
- The normal and larger item-list classes sit at the tail of the same NPC message/menu-question aggregate: `MenuQuestionItemList` covers `0x00550d50-0x00550ec1`, followed by `MenuQuestionItemListLarger` at `0x00550ed0-0x00551021`.
- The row renderer's `+2` text offset is a list-item record detail that should be preserved in source notes, but the record type/name is not yet final.
- Live IDA MCP was unavailable during A005's 2026-06-07 pass after three connection attempts, so this page relies on already-recorded IDA evidence in the linked project documentation rather than claiming a fresh live recheck.

## State And Dependencies

| Dependency | Evidence/Role | Reconstruction Note |
| --- | --- | --- |
| [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md) | Owner dialog constructs this list and receives selection confirmation. | Keep the owner pointer explicit until the dialog field layout is named. |
| `ListPane` base | Constructor and row-paint behavior are list-widget overrides. | Final method names should match the rebuilt list/control framework. |
| item record text at `+2` | Renderer consumes the row label from this offset. | Do not invent a struct name until the menu-question item record is audited. |
| [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md) | Same role for the larger menu-question layout. | Use sibling parity for naming, but keep layout-specific dimensions separate. |

## Autogen And Parent Notes

This class is source-owned by [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), but it is not currently parent-attached because the strict child/direct-parent gate requires both sides to clear `85/85`. The parent clears at `89/85`; this child remains `80/84` with source ownership, exact method boundaries, constructor callers, sibling relationship, and remaining blockers documented.

Do not emit final reconstruction C++ here yet. The class is reconstructable project code, but final source still needs the selection-confirm virtual's source name/prototype, the row item record declaration, and the `ListPane` paint/selection API names.

## Score Rationale

The page is scored `80/84` because it now documents source-family ownership, parent attachment, exact method inventory, constructor callers, row-renderer data offset, sibling parity, dependencies, and explicit final-C++ blockers. Completion and confidence remain below the near-final tier because the selection-confirm helper name, row record type, owner-dialog field names, and base list method names still need a focused method-level audit.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)

## Changes

- 2026-06-07: Raised `COMPLETION` from `74` to `80`, raised `CONFIDENCE` from `82` to `84`, and attached `AUTOGEN_PARENT_UID:0000LA` under the older gate.
  - Before: the class had method starts and private-widget ownership, but no parent metadata, no dependency table, and only shallow notes on the row renderer and remaining final-C++ blockers.
  - After: the page records MessageDialogs parent-gate reasoning, constructor callers from `MenuQuestionDialog`, normal/larger sibling placement, row text offset `+2`, dependency/record-layout caveats, and an explicit score rationale.
  - Evidence: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `88/80` and owns the message/menu-question dialog source family; [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) records the item-list tail ranges and already-recorded IDA method-start evidence.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms this normal menu-question list widget is source-owned UI support for [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md). Kept `AUTOGEN_PARENT_UID` blank because the class was `74/82`, below the then-current parent-attachment gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00550d50`, `0x00550e30`, and `0x00550e40`; `callers` confirms constructor calls from `0x0054eb04` and `0x0054f276` inside `MenuQuestionDialog`.
- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: the normal question-list widget has ownership, constructor, confirm helper, row drawing, and caller evidence documented, but selection-confirm naming and row record layout remain shallow. Evidence: linked message-dialog memory range, IDA-confirmed starts, constructor xrefs from `MenuQuestionDialog`, and noted decompiler-style signature caveat.
- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000LA` attached this class to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), and status text still referenced generated recovered output.
  - After: `AUTOGEN_PARENT_UID:` is blank and the status/autogen notes record the strict `85/85` gate; score remains `80/84`.
  - Summary/evidence: the direct parent is now `89/85`, but this child remains below the child side of the current gate. The source-owner link remains as evidence, backed by recorded IDA method starts, constructor xrefs from `MenuQuestionDialog`, and row text offset/sibling-list documentation.
