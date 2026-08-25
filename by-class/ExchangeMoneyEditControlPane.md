*** UID:00004T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../controls/TextEditControlPane.h"
#include "../core/Event.h"

namespace
{
class ExchangeMoneyEditControlPane : public TextEditControlPane
{
public:
    ExchangeMoneyEditControlPane(const RectBounds &bounds,
                                 const wchar_t *initialText)
        : TextEditControlPane(initialText, true, 128, 0, &bounds,
                              false, false, false, false, 1.0f, true)
    {
    }

    virtual bool HandleKeyOrTextEvent(Event *event);

protected:
    virtual void Activate();
};
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ExchangeMoneyEditControlPane

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md); exact helper children [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) and [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md); false generated method start [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- Historical recovered-file lead: old `source-3/simroot_v2/class_ExchangeMoneyEditControlPane.cpp` references are lead material only; current by-* docs, MCP evidence, and generated output control.
- Autogen parent: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md); formal C++ now emits the complete file-local derived declaration, inline constructor, and ordered exact children. Formal H remains blank because the anonymous class is private to `ExchangeDialog.cpp`.
- Confidence: strong for role, method boundaries, and `ExchangeDialog.cpp` ownership; strong that `0x00430058` is not an ExchangeMoney method.

## Class Purpose

`ExchangeMoneyEditControlPane` is the numeric edit control used for the local money amount in `ExchangeDialog`. It accepts only digit key events, forwards accepted input through the text-edit hide/commit path, reports itself editable, and is normalized by `ExchangeDialog` when focus leaves local money control id `6`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetClassName` | [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) | False Wave3-modeled method. IDA says this is an internal branch target inside `sub_430040`, not a valid callable method start. |
| `ScalarDeletingDestructor` | [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md) row `0x004b0a60-0x004b0ab5` | Compiler-generated wrapper that restores vtable pointers, chains through text-edit control teardown, and optionally frees storage. |
| `AdjustorThunks` | [UID:00014Y][0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks](by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md) | Compiler-generated `-0xa0` and `-0xa4` destructor adjustor thunks. |
| `Activate` | [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) | Exact `void` override: calls the embedded text-edit active-state helper with `true, true`, then tail-delegates to inherited `ControlPane::Activate()` through `TextEditControlPane::Activate()`. |
| `HandleKeyOrTextEvent` | [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md) | Exact money-control text-input filter. It accepts only `kEventTextInput` with length one and a UTF-16 digit `L'0'` through `L'9'`, forwards accepted input to `TextEditControlPane::HandleKeyOrTextEvent`, and returns true. |
| shared return-true slot | [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md) | The `ExchangeMoneyEditControlPane` vtable points at this trivial true predicate, but IDA also shows `MapRefreshDimmer`, `ScreenDimmer`, and `InputBlockerPane` vtables using the same body, so it is not assigned to this class. |

## Vtable And Boundary Notes

- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) records the current IDA-backed class tail boundaries: scalar deleting destructor `0x004b0a60-0x004b0ab5`, adjustor thunk strip `0x004b0ab5-0x004b0acb`, activation helper `0x004b0b40-0x004b0b54`, key handler `0x004b0b60-0x004b0b96`, and shared return-true helper `0x004b0ba0-0x004b0ba5`.
- The same tail pass records the relevant vtable-data cells: destructor slot `0x0061a264`, primary-table activation slot `0x0061a2c0`, adjustor thunk slots `0x0061a2cc` and `0x0061a2fc`, shared return-true slot `0x0061a2d0`, and key-handler slot `0x0061a2d4`.
- The exact `ExchangeMoneyEditControlPane` vtable-data island is now split as [UID:0003BK][0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData](by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md). It begins at the RTTI locator `0x0061a260`, covers primary/secondary/tertiary tables at `0x0061a264`, `0x0061a2cc`, and `0x0061a2fc`, and ends before exchange resource strings at `0x0061a304`.
- Parent attachment to `ExchangeDialog` is justified because this class and the file page both clear the corrected `85/85` gate, and the file page groups `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, and `ExchangeAlertPane` as private pieces of the exchange dialog feature.

## Evidence Notes

- `ExchangeDialog` constructs this control at rectangle `73,295,197,307` and assigns it control id `6`.
- [UID:00049T][0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent](by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md) reads this control on text digit events through `TextEditControlPane::ReadText(..., 10)`, parses `_wtol`, clamps non-positive values to zero, and submits the amount through [UID:00049V][0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount](by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md).
- [UID:00049Y][0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange](by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md) handles the focus-leave path for local money control id `6`: when the inherited active-control slot was `6`, the incoming control id is not `6`, and the TextEditControlPane active byte `+0x101` is set, it reads text through [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md), parses `_wtol`, writes the display text to `L"0"` for non-positive values through the TextEditControlPane set-text wrapper, submits the amount through [UID:00049V][0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount](by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md), and then calls inherited `DialogPane::SetHoverControl`.
- UID00049Y's formal source uses `TextEditControlPane::m_editActive` as the source-facing alias for byte `+0x101`; that member spelling is inferred from the documented active/show-state role and the existing `SetEditActiveState` helper family, not original-symbol proof.
- Historical Wave3 output had a low emitted score because of missing base type names and synthetic layout artifacts. It is superseded lead material and is not current source authority.
- IDA MCP recheck on 2026-05-26 shows apparent data xrefs to `0x00430058` are false dword interpretations inside wide resource strings such as `DLGE1.PAL` and `DLGE2.PEF`, not ExchangeMoney vtable entries.
- 2026-06-10 B001-027 IDA MCP recheck confirms `0x004b0b40-0x004b0b54` has only the `0x0061a2c0` vtable/data ref and calls `0x00498c00(this, 1, 1)` before tail-jumping to `0x00494c30`.
- 2026-06-10 B001-027 IDA MCP recheck confirms `0x004b0b60-0x004b0b96` has vtable/data ref `0x0061a2d4`, accepts only event byte `+4 == 10`, byte `+9 == 1`, and UTF-16 digit code `0x30-0x39`, then calls `0x00498d90`.
- 2026-06-10 B001-027 IDA MCP recheck confirms `0x004b0ba0-0x004b0ba5` returns true but has additional non-exchange vtable refs from `MapRefreshDimmer`, `ScreenDimmer`, and `InputBlockerPane`, so this page records it as a consumed shared helper rather than a direct child assignment.
- 2026-06-11 A004 Batch 212 IDA MCP recheck confirms the exact vtable-data child [UID:0003BK][0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData](by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md), including table refs from `ExchangeDialog` construction at `0x004accd3/0x004accd9/0x004acce3` and destructor-restoration refs at `0x004b0a66/0x004b0a6c/0x004b0a76`.
- 2026-06-12 C001 Batch C001-015 boundary repair corrects that exact vtable-data child to end at `0x0061a304`: IDA MCP `get_bytes` shows the tertiary table slots at `0x0061a2fc` and `0x0061a300`, then UTF-16 `DLGEXC1.PAL` begins at `0x0061a304`.
- The archived B001 `0003LQ` audit is preserved as negative ownership evidence for the shared state/border helper band: ExchangeMoney consumes four helpers from [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) through vtable cells `0x0061a2a8`, `0x0061a2b0`, `0x0061a2b4`, and `0x0061a2bc`, but it has no `0x00498ed0` cell and instead owns the exact local activation/state helper at [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md). That rejects whole-band ExchangeMoney ownership or multi-emission while remaining consistent with the later RTTI evidence that these consumed slots are inherited `TextEditControlPane` base virtuals.

## 2026-08-17 B010 Accepted Class And Source Closure

- Fresh IDA MCP construction evidence at `0x004ac8a0` allocates exactly `0x114` bytes, invokes the full `TextEditControlPane` constructor, and installs the anonymous derived primary/secondary/tertiary vptrs at `0x004accd3`, `0x004accd9`, and `0x004acce3`. `TextEditControlPane` is also exactly `0x114`, so the derived class introduces no source fields or synthetic padding.
- The inline constructor preserves the observed source call contract: initial text, enabled edit mode, maximum length `128`, mode `0`, caller-provided bounds, four false feature flags, scale `1.0f`, and final true option. It is emitted inline because the constructor is folded into ExchangeDialog construction rather than modeled as an independent function.
- Primary cell `0x0061a2c0` selects [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) for inherited `Activate`; secondary cell `0x0061a2d4` selects [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md) for `HandleKeyOrTextEvent`. The primary/secondary/tertiary views and destructor thunks remain compiler-generated through [UID:0003BK][0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData](by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md), not handwritten arrays.
- Source order is explicit: this declaration emits at position 5, [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) at position 10, and [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md) at position 20. The class must precede ExchangeDialog constructor use; the old late forward declaration was insufficient and is historicalized.
- Formal H is intentionally blank. Anonymous RTTI and construction confined to the ExchangeDialog family show that this helper class belongs only in `ExchangeDialog.cpp`; creating `ExchangeDialog.h` content or a standalone class header would expose an unsupported public type.
- Historical source surfaces `int OnActivate()`, `bool OnKeyEvent(KeyEvent *)`, raw pseudo-fields, and `CommitCurrentEditText()` are superseded by exact vtable/Event/helper evidence. The earlier marker-only declaration is preserved in dated history as the source of the incomplete generated order, not as current guidance.
- The accepted class remains [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)-owned/emitted and reconstructable. Completion/confidence `93/95` reflects complete layout, construction, virtual declarations, child behavior, source order, and no-header disposition; stripped original private naming and absent rebuilt-binary comparison keep it below 100.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00049T][0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent](by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md)
- [UID:00049Y][0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange](by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md)
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- [UID:0003BK][0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData](by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md)
- [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md)
- [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md)
- [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-30 B011 accepted UID0000J9 empty-emitter family implementation:
  - Before: `COMPLETION:85`, `CONFIDENCE:88`, blank formal block, with child helper bodies still documented as non-final.
  - After: `COMPLETION:88`, `CONFIDENCE:90`; formal block now contains the narrow class declaration plus `[[CHILDREN]]`, while exact child pages carry `OnActivate` and `OnKeyEvent` first-draft bodies.
  - Summary/evidence: accepted report audited the constructor/destructor route, vtable slots at `0x0061a2c0` and `0x0061a2d4`, class fields inherited from `TextEditControlPane`, direct child ownership, false `0x00430058` method evidence, and shared `0x004b0ba0` return-true helper. Full inherited text-edit layout remains intentionally un-emitted.
- 2026-06-29 B002 UID00049Y implementation support sync:
  - Score and metadata unchanged.
  - Summary/evidence: aligned this class with UID00049Y's accepted current-session focus-leave behavior. Local money control id `6` is read through `TextEditControlPaneReadTextForwarder`, parsed with CRT `_wtol`, normalized to display `L"0"` for non-positive values, submitted through `ExchangeDialog::SubmitExchangeAmount`, and followed by inherited `DialogPane::SetHoverControl`. The formal target code uses inferred source-facing field name `m_editActive` for TextEditControlPane byte `+0x101`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: money edit-control role, destructor/thunks/key/editable methods, control id and ExchangeDialog amount flow, and false `GetClassName`/string-fragment evidence are documented; remaining work is mostly base type/source polish.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving this confirmed exchange money input control unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `76/84`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP confirms real method starts at `0x004b0a60`, `0x004b0b60`, and `0x004b0ba0`, while `0x00430058` remains an interior address of `sub_430040` rather than an ExchangeMoney method start.
- 2026-06-07: Attached to `ExchangeDialog.cpp` and raised class scores to `82/86`.
  - Before: parent was blank and the page did not record the later ExchangeDialog-tail vtable/data slot pass.
  - After: set `AUTOGEN_PARENT_UID:0000J9`, added boundary/vtable notes, and kept final C++ blank.
  - Summary/evidence: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) now records IDA-backed method boundaries, money-edit vtable slots, adjustor thunk linkage, padding boundaries, and the next `FieldMapPane` boundary, while [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) is a validated 86/80 source root for the exchange dialog feature.
- 2026-06-10 B001-027 parent gate repair:
  - Before: `82/86`; exact money-edit helper rows inside [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) could not be assigned under the corrected `85/85` direct-parent gate.
  - After: `85/88`; exact children [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) and [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md) attach to this class. [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md) stays parent-blank because IDA proves multiple non-exchange vtables reuse that tiny helper.
  - Summary/evidence: live IDA confirms activation/key-handler exact ranges, `0x0061a2c0`/`0x0061a2d4` vtable refs, callee behavior through TextEditControlPane/control-family helpers, digit-key filtering behavior, and the shared-helper negative evidence for `0x004b0ba0`.
- 2026-06-11 A004 Batch 212 exact vtable-data split:
  - Score unchanged at `85/88`.
  - Added exact child [UID:0003BK][0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData](by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md) and replaced stale wording that said the vtable island was not split.
  - Summary/evidence: live IDA MCP confirmed primary/secondary/tertiary vtable bases, constructor/destructor refs, and boundaries after [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md) and before the exchange resource-string cluster.
- 2026-06-12 C001 Batch C001-015 boundary repair:
  - Score unchanged at `85/88`.
  - Corrected the exact vtable-data child range from `0x0061a260-0x0061a310` to `0x0061a260-0x0061a304`; the child score changed independently to `86/92`.
  - Summary/evidence: live IDA MCP `get_bytes` proves `0x0061a304` starts UTF-16 `DLGEXC1.PAL`, while `0x0061a2fc`/`0x0061a300` are the final tertiary vtable slots.
- 2026-06-22 Rule 26 incorporation for archived B001 report `0003LQ-TextControlSharedStateAndBorderHelpers.md`:
  - Score unchanged at `85/88`.
  - Added the explicit negative ownership link for the shared state/border helper band: ExchangeMoney uses only four inherited TextEditControlPane slots from [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) and owns its separate local override/helper pages instead.
