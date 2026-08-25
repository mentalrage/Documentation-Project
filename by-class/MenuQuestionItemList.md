*** UID:00007Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MenuQuestionOptionRow
{
    unsigned char optionId;
    unsigned char reserved;
    wchar_t label[0x100];
};

class MenuQuestionItemList : public ListPane
{
public:
    explicit MenuQuestionItemList(MenuQuestionDialog *ownerDialog);
    virtual void ConfirmSelection();
    virtual void DrawRow(const MenuQuestionOptionRow *row, const RectBounds *bounds, bool selected);

private:
    MenuQuestionDialog *m_ownerDialog;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionItemList

## Status

- Confidence: very strong for support-widget ownership, exact method boundaries, constructor callers, vtable slots, stored owner pointer, selection delegation, and row drawing; final source API names still need framework-wide cleanup.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main method children: [UID:0003W8][0x00550d50-0x00550db4.MenuQuestionItemListConstructor](by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md), [UID:0003WB][0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection](by-memory/0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md), [UID:0003WC][0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow](by-memory/0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md). Raw helper [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) is now semantically class-owned as a retained `AppendMenuQuestionRow` / `AddRow` helper, but remains non-reconstructable and non-emitting because no caller, pointer, vtable, or runtime route reaches `0x00550dc0`; the live constructors inline the same row append behavior. Raw helper [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) remains no-owner/non-emitting and is best described as a no-route selected-option-id payload helper, not the live selectability/count test. [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) is now a non-emitting split index.
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). The direct file parent clears at `89/85`, and this child now clears the strict child/direct-parent gate at `85/87`.
- Declaration-level C++ is now emitted for the class shell; method-body emission remains gated on final selection-confirm virtual naming and `ListPane` framework API names.

## Class Purpose

`MenuQuestionItemList` is a `ListPane`-derived widget used by `MenuQuestionDialog`. It stores the owner dialog pointer, displays selectable wide-string menu labels, and draws selected rows with highlight/background palette changes.

It is the normal-layout sibling of [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md). Both list widgets are private support classes for the menu-question constructors in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), not generic menu/list infrastructure.

B010 2026-07-01 resolves the empty emitter as declaration-level source. The row payload is now documented as `MenuQuestionOptionRow` with `optionId`, one reserved byte, and a UTF-16 `label[0x100]`, and draw calls use `const RectBounds *bounds` instead of broad `void *` placeholders. Exact constructor/draw/selection behavior stays on exact by-memory children and raw no-route append/selection helpers remain non-emitting support evidence.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0003W8][0x00550d50-0x00550db4.MenuQuestionItemListConstructor](by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md) | `MenuQuestionItemList::MenuQuestionItemList(unsigned int ownerPane)` | Constructs the list pane, stores the owner/dialog pointer at `this+0x14c`, and installs `MenuQuestionItemList` vtables. |
| [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) | `AppendMenuQuestionRow(unsigned char optionId, const wchar_t *label)` | Retained no-route helper that builds `{ optionId, padding, wchar_t label[0x100] }` and calls `ListPane::AddEntry`; semantically class-owned but not emitted because no route reaches the helper. |
| [UID:0003WB][0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection](by-memory/0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md) | `SelectionConfirmDelegator()` | Loads the stored owner pointer from `this+0x14c` and tail-jumps to the shared selection path at `0x0049de70`; final source name/prototype still open. |
| [UID:0003WC][0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow](by-memory/0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md) | `DrawEntry(...)` | Draws a row label from a record whose wide-string text begins at offset `+2`; selected rows use the menu-question highlight/background path. |

## Evidence Notes

- Existing IDA MCP notes in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) confirm exact starts at `0x00550d50`, `0x00550e30`, and `0x00550e40`.
- Constructor xrefs are from `MenuQuestionDialog` constructors at `0x0054eb04` and `0x0054f276`, supporting private support-widget ownership.
- The normal and larger item-list classes sit at the tail of the same NPC message/menu-question aggregate: `MenuQuestionItemList` covers `0x00550d50-0x00550ec1`, followed by `MenuQuestionItemListLarger` at `0x00550ed0-0x00551021`.
- The row renderer's `+2` text offset is a list-item record detail that should be preserved in source notes, but the record type/name is not yet final.
- 2026-06-12 IDA MCP session `a001-b276` reconfirmed `0x00550d50` as a `0x64` constructor, `0x00550e30` as an `0x0b` selection/delegation helper, and `0x00550e40` as an `0x81` draw override.
- The constructor calls the `ListPane` setup path with `0x202`, `0x10`, either `0x12e` or `0x10d` depending on `byte_66DA97`, and `0x0c`, stores the owner/dialog pointer at `this+0x14c`, and writes the primary/secondary/tertiary vtables at `this+0x00`, `this+0xa0`, and `this+0xa4`. Number-base checks: `0x202 = 514`, `0x10 = 16`, `0x12e = 302`, `0x10d = 269`, `0x0c = 12`, `0x14c = 332`, `0xa0 = 160`, and `0xa4 = 164` (Verified with int_convert.py).
- `trace_data_flow` confirms only two code xrefs to the constructor, both inside the normal [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md) constructor at `0x0054eb04` and `0x0054f276`; the selection and draw helpers have no ordinary callers and are reached through vtable cells `0x006227b0` and `0x006227b4`.
- The selection helper disassembles to `mov ecx, [ecx+0x14c]; jmp 0x0049de70`, so the source-level role is delegation through the stored owner/control pointer rather than independent dialog packet serialization.
- The draw override calls the selected-row predicate, uses color/index `0x25 = 37` and selected background `0x80 = 128`, calls the shared surface/render callback slot `dword_69B3FC`, sets `this+0x88 = 1`, draws the row rectangle from the bounds argument, then walks a NUL-terminated UTF-16 label beginning at `itemData + 2` before text rendering. Number-base checks: `0x25 = 37`, `0x80 = 128`, and `0x88 = 136` (Verified with int_convert.py).
- 2026-06-16 B001 split execution created exact method children [UID:0003W8][0x00550d50-0x00550db4.MenuQuestionItemListConstructor](by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md), [UID:0003WB][0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection](by-memory/0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md), and [UID:0003WC][0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow](by-memory/0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md). Raw helpers [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) and [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) were initially recorded as non-emitting raw helper evidence.
- B002 2026-06-20 source-routing recheck resolves [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) as `push this+0x134; call 0x004f3dc0; mov al,[eax]; ret`: `+0x134` is inherited `ListPane::m_selectedIndex`, `0x004f3dc0` is the shared explicit-index row accessor, and row byte `+0` is best inferred as the option id / selection value. The live confirm-button updater uses `0x004f3e20` instead, so [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) remains no-owner/non-emitting and should not be used as the source selectability test.
- B013 2026-06-19 source-routing recheck resolves [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) as semantically class-owned retained helper material. The helper has `thiscall` shape, copies an option id at row byte `+0`, copies a UTF-16 label to `+2` with `_wcscpy_s(..., 0x100, ...)`, calls `ListPane::AddEntry` at `0x004f3c50`, and matches active constructor inline row appends at `0x0054ebe8` and `0x0054f358`. It still has no rel32/VA/RVA route, no vtable cell, and no IDA function object, so it remains non-reconstructable/non-emitting.

## State And Dependencies

| Dependency | Evidence/Role | Reconstruction Note |
| --- | --- | --- |
| `this+0x14c` owner/control pointer | Constructor stores the argument from `MenuQuestionDialog`; selection helper loads it before tail-jumping to the shared selection path. | Keep the field name provisional until the list/dialog member layout is finalized. |
| [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md) | Owner dialog constructs this list at `0x0054eb04` and `0x0054f276`. | Keep the widget private to the normal menu-question dialog path. |
| `ListPane` base | Constructor and row-paint behavior are list-widget overrides. | Final method names should match the rebuilt list/control framework. |
| `MenuQuestionItemRow` text at `+2` | Renderer consumes the row label from this offset, and [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) stages `_wcscpy_s(row.label, 0x100, label)` at `row+2`. | Provisional source record is `{ uint8_t optionId; uint8_t padding; wchar_t label[0x100]; }`; keep the name provisional until the menu-question item record is audited across normal/larger variants. |
| item record byte at `+0` | B002 [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) recheck identifies this as the selected option id / selection value returned by the no-route helper; B013 [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) writes the same byte when staging a row. | Provisional row shape is `{ uint8_t optionId; uint8_t padding; wchar_t label[0x100]; }`; do not emit a helper without a route. |
| [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md) | Same role for the larger menu-question layout. | Use sibling parity for naming, but keep layout-specific dimensions separate. |

## Autogen And Parent Notes

This class is source-owned by [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and is now parent-attached because the strict child/direct-parent gate clears. The parent is `89/85`; this child is `85/87` with source ownership, exact method boundaries, constructor callers, vtable slots, sibling relationship, and remaining blockers documented.

Do not emit method-body reconstruction C++ here yet. The class is reconstructable project code and now emits a declaration shell, but final method bodies still need the selection-confirm virtual's source name/prototype and the `ListPane` paint/selection API names.

## Score Rationale

The page is now `85/87` because it documents source-family ownership, parent attachment, exact method inventory, constructor callers, vtable-only override slots, owner/control pointer storage, selection delegation, row-renderer data offset, selected-row draw behavior, sibling parity, dependencies, and explicit final-C++ blockers. Completion and confidence remain below final-audit quality because the selection helper's final source name, row record type, owner/dialog member names, and base list method names still need framework-wide cleanup.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:0003W8][0x00550d50-0x00550db4.MenuQuestionItemListConstructor](by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md)
- [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md)
- [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md)
- [UID:0003WB][0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection](by-memory/0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md)
- [UID:0003WC][0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow](by-memory/0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md)

## Changes

- 2026-07-01 Agent-B010 implementation callback: raised `85/87 -> 86/88`, set emitter position `20`, and added the accepted declaration shell with `MenuQuestionOptionRow`, typed `DrawRow(const MenuQuestionOptionRow *row, const RectBounds *bounds, bool selected)`, owner pointer, and `[[CHILDREN]]`; retained the executed raw helper caveats.
- 2026-06-12 A001 Batch 276 parent-gate pass:
  - Before: `80/84`, with `AUTOGEN_PARENT_UID` blank because the child class did not clear the strict gate.
  - After: `85/87`, `AUTOGEN_PARENT_UID:0000LA`.
  - Summary/evidence: live IDA MCP reconfirmed exact function sizes, constructor xrefs from `MenuQuestionDialog`, no ordinary non-vtable callers for the selection/draw helpers, constructor `ListPane` setup args, `this+0x14c` owner/control pointer storage and selection delegation, primary/secondary/tertiary vtable writes, vtable cells `0x006227b0 -> 0x00550e30` and `0x006227b4 -> 0x00550e40`, selected-row draw behavior, `this+0x88` text-mode write, row rectangle use, and UTF-16 label rendering from `itemData+2`. The direct parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) already clears `89/85`, so the child now attaches under the strict `85/85` gate.
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
- 2026-06-16 B001 split execution:
  - Score remains `85/87`.
  - Summary/evidence: linked exact method children [UID:0003W8][0x00550d50-0x00550db4.MenuQuestionItemListConstructor](by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md), [UID:0003WB][0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection](by-memory/0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md), and [UID:0003WC][0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow](by-memory/0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md); [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) and [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) are recorded as non-emitting raw helper evidence.
- 2026-06-20 B002 Rule 26 support sync:
  - Score unchanged. [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) is now documented as a no-route selected-option-id helper rather than a live selectability/count probe.
  - Evidence: B002 PE scan found no rel32/short-branch/VA/RVA/raw-offset route to `0x00550e20`, while positive controls found adjacent vtable refs and direct call fanout for `0x004f3dc0`/`0x004f3e20`.
- 2026-06-22 supervisor-worker Rule 26 incorporation of B013 `0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing.md`:
  - Score unchanged. [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) is now documented as semantically class-owned retained `AppendMenuQuestionRow` / `AddRow` material, while remaining non-reconstructable/non-emitting because no route reaches `0x00550dc0`.
  - Evidence: B013 PE/source-routing report confirmed the exact `0x56` byte helper, row layout `{ optionId, padding, wchar_t label[0x100] }`, `_wcscpy_s` copy contract, `ListPane::AddEntry` dependency, negative route scan with positive controls, active constructor inline equivalents, and the exact no-code proof.
