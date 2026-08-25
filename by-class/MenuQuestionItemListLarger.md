*** UID:000080 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MenuQuestionItemListLarger : public ListPane
{
public:
    explicit MenuQuestionItemListLarger(MenuQuestionItemList *pairedList);
    virtual void ConfirmSelection();
    virtual void DrawRow(const MenuQuestionOptionRow *row, const RectBounds *bounds, bool selected);

private:
    MenuQuestionItemList *m_pairedList;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionItemListLarger

## Status

- Confidence: very strong for support-widget ownership, exact method boundaries, vtable slots, paired-list field use, and draw/selection behavior; final source API names still need framework-wide cleanup.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main method children: [UID:0003WD][0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor](by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md), [UID:0003WG][0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection](by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md), [UID:0003WH][0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow](by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md). Raw helper [UID:0003WE][0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw](by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md) is a complete source-shaped `AddRow` / `AppendOptionRow` clone that builds `{ optionId at +0, alignment byte at +1, UTF-16 label[0x100] at +2 }` and calls `ListPane::AddEntry`, but it remains no-owner/non-emitting because B015 found no caller, pointer, vtable, or rel32 route and the live larger constructor already inlines equivalent row insertion. Raw helper [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) is also non-emitting and is best described as a no-route selected-option-id payload helper, not the live selectability/count test. [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) is now a non-emitting split index.
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). The direct parent clears at `89/85`, and this child now clears the strict child/direct-parent `85/85` gate at `86/88`.
- Declaration-level C++ is now emitted for the class shell; method-body emission remains gated on the final row record name and `ListPane` draw/selection API names.

## Class Purpose

`MenuQuestionItemListLarger` is the larger-layout list widget used by `MenuQuestionDialogLarger`. It wraps a `ListPane`, delegates current-item selection to its paired question list, and draws selected entries with the same highlight/background palette pattern as the normal list.

It is the larger-layout sibling of [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md), and both are private support widgets for the menu-question constructors in [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). This class should not be promoted to generic list infrastructure unless later xrefs show reuse outside the NPC message/menu-question dialog family.

B010 2026-07-01 resolves the empty emitter as declaration-level source. It shares the `MenuQuestionOptionRow` row model emitted by [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md), uses `const RectBounds *bounds` for row drawing, and keeps exact method bodies plus retained raw append/selection helper evidence on exact by-memory child pages.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0003WD][0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor](by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md) | `MenuQuestionItemListLarger::MenuQuestionItemListLarger(int32_t questionItemList)` | Calls the `ListPane` base/setup path, stores the paired normal item-list pointer at `this+0x14c`, and installs the three `MenuQuestionItemListLarger` vtable views. |
| [UID:0003WG][0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection](by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md) | `SelectCurrentItem()` | Two-instruction virtual thunk: loads the paired list from `this+0x14c` and jumps to the normal item-list selection-confirm path at `0x0049de70`. |
| [UID:0003WH][0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow](by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md) | `DrawEntry(...)` | Row draw override: tests selected-row state, applies palette/background drawing, forces text mode byte `this+0x88`, draws the row rectangle, then emits the UTF-16 label from item-data offset `+2`. |

## Evidence Notes

- 2026-06-11 live IDA MCP `lookup_funcs` confirms exact function objects at `0x00550ed0` size `0x4f`, `0x00550f90` size `0x0b`, and `0x00550fa0` size `0x81`; the normal sibling functions at `0x00550d50`, `0x00550e30`, and `0x00550e40` have matching constructor/select/draw shape.
- Constructor xrefs are from the larger menu-question constructor at `0x0054fd14` and `0x00550489` inside the `0x0054fb30` constructor range. No ordinary direct callers exist for the select/draw helpers because they are vtable-dispatched.
- The class remains a private support widget for [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md); no broader reuse is documented.
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) records this class as the tail of the message/menu-question executable aggregate: constructor `0x00550ed0-0x00550f1f`, selection delegation helper `0x00550f90-0x00550f9b`, and row renderer `0x00550fa0-0x00551021`.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the normal/larger menu-question item-list vtable band at `0x00622734-0x006228b0`, with ownership routed through `MessageDialogs`.
- Live vtable dword sweep records the `MenuQuestionItemListLarger` primary RTTI pointer at `0x006227f4`; its primary table includes the same base `ListPane` slots as the normal sibling and routes the larger selection/draw overrides through `0x00622874 -> 0x00550f90` and `0x00622878 -> 0x00550fa0`. Secondary and tertiary RTTI pointers are at `0x0062287c` and `0x006228ac`.
- Constructor disassembly calls the base/list setup with `0x202`, `0x10`, `0x12e`, and `0x0c`, then stores the paired list at `this+0x14c` and writes vtables at `this+0x00`, `this+0xa0`, and `this+0xa4`. Number-base checks: `0x202 = 514`, `0x10 = 16`, `0x12e = 302`, `0x0c = 12`, and `0x14c = 332` (Verified with int_convert.py).
- The selection helper disassembles to `mov ecx, [ecx+0x14c]; jmp 0x0049de70`, proving it delegates to the paired normal item-list selection-confirm path instead of reimplementing submission logic.
- The draw helper first calls the selected-row predicate, uses color/index `0x25 = 37` and selected background `0x80 = 128`, calls the shared surface/render callback slot `dword_69B3FC`, sets `this+0x88 = 1`, draws the rectangle from the row bounds argument, then walks a NUL-terminated UTF-16 string beginning at `itemData + 2` before sending it to the text draw helper. Number-base checks: `0x25 = 37`, `0x80 = 128`, and `0x88 = 136` (Verified with int_convert.py).
- 2026-06-16 B001 split execution created exact method children [UID:0003WD][0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor](by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md), [UID:0003WG][0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection](by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md), and [UID:0003WH][0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow](by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md). Raw helpers [UID:0003WE][0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw](by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md) and [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) remain non-emitting because helper routes are not proven.
- B002 2026-06-20 source-routing recheck resolves [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) as `push this+0x134; call 0x004f3dc0; mov al,[eax]; ret`: `+0x134` is inherited `ListPane::m_selectedIndex`, `0x004f3dc0` is the shared explicit-index row accessor, and row byte `+0` is best inferred as the option id / selection value. The live larger confirm-button updater uses `0x004f3e20` instead, so [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) remains no-owner/non-emitting and should not be used as the source selectability test.
- B011 2026-06-19 route recheck keeps [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) outside this class's emitter despite the clear semantic relationship. Local PE scans found the exact 14-byte body only at `0x00550f80`, found no `rel32`/VA/RVA inbound route, and recovered positive-control vtable refs for the adjacent live larger-list methods at `0x00622874 -> 0x00550f90` and `0x00622878 -> 0x00550fa0`. If a route appears later, the best source-facing helper name is `GetSelectedOptionId()` / `GetSelectedMenuValue()`, not `HasSelectableEntry()`, but current class C++ should not declare or emit it.

## State And Dependencies

| Dependency/field | Evidence/role | Reconstruction note |
| --- | --- | --- |
| `this+0x14c` paired item-list pointer | Written by the constructor and consumed by the selection helper. | Treat as a field on the larger list wrapper; final name should reflect the paired normal/menu-question list once the dialog member layout is cleaned up. |
| `this+0x88` text/draw-mode byte | The draw override forces it to `1` before rendering row text. | Keep as a `ListPane`/pane text-mode dependency until the base control layout is named. |
| `itemData + 2` UTF-16 label | The draw override computes string length from this offset and passes the label to the text draw helper. | The row record type is now narrowed to a two-byte prefix plus UTF-16 label, but the source struct name remains open. |
| item record byte at `+0` | B002 [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) recheck identifies this as the selected option id / selection value returned by the no-route helper. | Provisional row shape is `{ uint8_t optionId; uint8_t unknownOrPadding; wchar_t label[]; }`; do not emit a helper without a route. |
| [UID:0003WE][0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw](by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md) | B015 confirms an exact no-route source-shaped row append clone: option byte at `+0`, aligned UTF-16 label at `+2`, `_wcscpy_s(..., 0x100, ...)`, and `ListPane::AddEntry` at `0x004f3c50`. | Best name if a route appears is `AddRow` / `AppendOptionRow`; keep no-owner/non-emitting and do not add it to class C++ because the live larger constructor inlines equivalent insertion and no route to `0x00550f20` is proven. |
| [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md) | Constructor allocates this support widget at two sites. | Direct owner remains the `MessageDialogs` source file; the dialog class documents the construction context. |
| `ListPane` base/control framework | Constructor, selected-row predicate, color/palette setters, row-rect drawing, and text rendering are inherited/support calls. | Future method-body C++ should use the rebuilt control framework names rather than decompiler-style `sub_` names. |

## Score And Gate Rationale

The page is now `86/88`: it documents the exact constructor/delegation/draw ranges, constructor xrefs, no-direct-caller virtual-dispatch evidence, `this+0x14c` paired-list field use, vtable slots for the larger overrides, selected-row draw behavior, row rectangle/text rendering path, row-label offset `+2`, sibling parity, and final-C++ blockers.

`AUTOGEN_PARENT_UID` is set to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) because the direct parent is `89/85` and this child now clears the strict child/direct-parent `85/85` gate. Completion remains below final-audit quality because the source-level row record name and final `ListPane` API names are not yet settled across the UI control framework.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:0003WD][0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor](by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md)
- [UID:0003WE][0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw](by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md)
- [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md)
- [UID:0003WG][0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection](by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md)
- [UID:0003WH][0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow](by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## Changes

- 2026-07-01 Agent-B010 implementation callback: raised `86/88 -> 87/89`, set emitter position `30`, and added the accepted declaration shell with typed row drawing, paired-list pointer, and `[[CHILDREN]]`; retained the executed larger raw helper caveats.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms this larger menu-question list widget is source-owned UI support for [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md). Kept `AUTOGEN_PARENT_UID` blank because the class is `76/84`, below the strict `85/85` child gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00550ed0`, `0x00550f90`, and `0x00550fa0`; `callers` confirms constructor calls from `0x0054fd14` and `0x00550489` inside `MenuQuestionDialogLarger`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger question-list widget has clear ownership, constructor, delegated selection, row drawing, and constructor-caller evidence, but row data layout and final source-level details are not exhaustive. Evidence: linked message-dialog memory range, IDA-confirmed method starts, constructor xref from `MenuQuestionDialogLarger`, and paired-list relationship.
- 2026-06-10 A002 provenance/gate cleanup:
  - Before: status/evidence still referenced generated recovered output and the change log cited the old parent-attachment threshold.
  - After: status records the strict `85/85` gate and evidence now centers on IDA-confirmed starts, constructor xrefs, and the private support-widget relationship to `MenuQuestionDialogLarger`.
  - Summary/evidence: the direct parent is `89/85`, but this child remains `76/84`, so the source-owner link stays informational rather than an autogen assignment.
- 2026-06-11 A002 evidence refresh:
  - Before: `76/84`, with sparse method and ownership notes.
  - After: `82/85`, `AUTOGEN_PARENT_UID` still blank.
  - Summary/evidence: incorporated exact aggregate range evidence from [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), constructor xrefs at `0x0054fd14` and `0x00550489`, sibling/paired-list relationship to [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md), and the menu-question item-list vtable band from [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md). Parent remains blank because this child is still below the `85` completion gate.
- 2026-06-11 A006 method-level parent-gate pass:
  - Before: `82/85`, with the direct parent blank because the child was still below the completion side of the strict gate.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000LA`.
  - Summary/evidence: live IDA MCP reconfirmed exact function sizes, constructor callers, no direct non-vtable callers for select/draw, constructor base/setup args, `this+0x14c` paired-list storage/delegation, primary/secondary/tertiary vtable slots including `0x00622874 -> 0x00550f90` and `0x00622878 -> 0x00550fa0`, selected-row draw behavior, `this+0x88` text-mode write, row rectangle use, and UTF-16 label rendering from `itemData+2`. The direct parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) already clears `89/85`, so the child now attaches under the strict `85/85` gate.
- 2026-06-16 B001 split execution:
  - Score remains `86/88`.
  - Summary/evidence: linked exact method children [UID:0003WD][0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor](by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md), [UID:0003WG][0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection](by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md), and [UID:0003WH][0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow](by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md); [UID:0003WE][0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw](by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md) and [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) are recorded as non-emitting raw helper evidence.
- 2026-06-20 B002 Rule 26 support sync:
  - Score unchanged. [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md) is now documented as a no-route selected-option-id helper rather than a live selectability/count probe.
  - Evidence: B002 PE scan found no rel32/short-branch/VA/RVA/raw-offset route to `0x00550f80`, while positive controls found adjacent vtable refs and direct call fanout for `0x004f3dc0`/`0x004f3e20`.
- 2026-06-21 supervisor-worker Rule 26 incorporation of B011 `0003WF-MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw-source-routing.md`:
  - Score unchanged. Added target-specific B011 route proof and source-placement decision for [UID:0003WF][0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw](by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md): nearest semantic class is this class, but no caller/pointer/vtable route is proven, active action code inlines the behavior, and no class helper should be emitted yet.
- 2026-06-22 supervisor Rule 26 incorporation of B015 `0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing.md`:
  - Score unchanged. Expanded the larger raw add-row caveat with B015's source-shaped name direction, row layout, no-route proof, active-constructor inline duplicate, generated `ChattingColorListPane` rejection, and no-emitter policy.
