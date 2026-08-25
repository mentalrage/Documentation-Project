*** UID:00004Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeAlertPane source bodies are carried by exact child pages in this source file route.
// This class marker intentionally does not emit a full member layout because inherited
// DialogPane fields and exact original header order are not source-quality from current evidence.
class ExchangeAlertPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ExchangeAlertPane

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- Vtables: [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md) at `0x0061a1c0`, `0x0061a228`, and `0x0061a258`; exact data child [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md).
- Exact core split inventory: [UID:00033W][0x004b0490-0x004b086b.ExchangeAlertPaneCore](by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md).
- Exact constructor child: [UID:0004CF][0x004b0490-0x004b0819.ExchangeAlertPaneConstructor](by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md).
- Exact button callback child: [UID:0004CG][0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick](by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md).
- Exact singleton-clear child: [UID:0004CH][0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper](by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md).
- Exact close-active helper page: [UID:00033Z][0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper](by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md).
- Historical lead only: old `source-3/simroot_v2/class_ExchangeAlertPane.cpp` references and unrefined source snippets are not source authority; current MCP and by-* docs control.
- Reconstruction parent: attached to [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), which has valid `NexusTK/ui/dialogs/` placement and clears the parent-side `80/80` gate.
- Confidence: strong.
- C++ disposition: this class marker now emits only a forward declaration and `[[CHILDREN]]` route. Full layout remains documentation-only because inherited DialogPane facets and original header order are not source-quality from current evidence.

## Class Purpose

`ExchangeAlertPane` is the modal message/confirmation pane used by player exchange. It centers itself on the parent exchange dialog, sizes itself from message width and button count, creates optional left/right text buttons, stores the active singleton pointer, and invokes exchange callbacks when a button is clicked.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ExchangeAlertPane` | [UID:0004CF][0x004b0490-0x004b0819.ExchangeAlertPaneConstructor](by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md) | Constructs a variable-size alert with message text, optional buttons, centered placement, vtable stores, active singleton setup, focus/pending control setup, and `m_layoutReference` storage. Now `88/90` with an explicit formal no-code marker emitted through this class route; no constructor body is emitted because the live right-button-only branch cannot be source-shaped safely. |
| `OnButtonClick` | [UID:0004CG][0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick](by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md) | Handles button ids `1` and `2`, slides closed, invokes primary/secondary callback slots, and closes the dialog. First-draft C++ emits through this class route. |
| `ClearExchangeAlertPaneSingleton` | [UID:0004CH][0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper](by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md) | Tiny helper that clears [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md). First-draft C++ emits through this class route. |
| interleaved [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) | `0x004b0880-0x004b08a1` | Not an `ExchangeAlertPane` method; kept visible here only because it sits between alert helper rows in the interleaved tail island. |
| `AdjustorThunk` | [UID:00014X][0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks](by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md) | Compiler-generated secondary/tertiary vtable destructor adjustor thunks. |
| `ScalarDeletingDestructor` | `0x004b09d0-0x004b0a14` | Clears `g_pExchangeAlertPane`, chains through dialog teardown, and optionally frees storage. |
| `CloseActiveExchangeAlert` | [UID:00033Z][0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper](by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md) | Closes the active alert if `g_pExchangeAlertPane` is set. |

## Evidence Notes

- IDA xrefs to `0x0069b330` show constructor storage at `0x004b04ff`, destructor clear at `0x004b09d6`, clear helper `0x004b0860`, and close checks from `ExchangeDialog` packet helpers at `0x004ad611`, `0x004ad739`, `0x004addd3`, and `0x004adf51`.
- 2026-05-26 IDA MCP vtable pass confirms `ExchangeAlertPane` primary/secondary/tertiary vtables at `0x0061a1c0`, `0x0061a228`, and `0x0061a258`, installed by constructor stores at `0x004b0514`, `0x004b051a`, and `0x004b0524`.
- 2026-05-31 IDA MCP `py_eval` and xrefs prove exact vtable-data range [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md), ending immediately before `ExchangeMoneyEditControlPane` RTTI at `0x0061a260`.
- `OnButtonClick` is the primary-table slot `+0x48`. It invokes callback extension slots `+0x5c` and `+0x60`, but the concrete `ExchangeAlertPane` table currently holds no-op/guard entries for both slots.
- IDA confirms `0x004b08cd` and `0x004b08d8` as vtable-only adjustor thunks into `0x004b09d0`.
- IDA MCP decompilation on 2026-05-25 confirms `OnButtonClick` at `0x004b0820` performs alert button dispatch directly. The neighboring callback wrapper at `0x004b0880` is constructed by MixItemDialog quantity paths, not by ExchangeAlertPane.
- Constructor calls are at `0x004ad656`, `0x004ad775`, `0x004ade18`, and `0x004adf8d` inside the exchange packet alert paths.
- B009 2026-07-01 UID0004CF implementation rechecked the constructor with live MCP and current support docs. The best inferred source shape is `ExchangeAlertPane::ExchangeAlertPane(const wchar_t *messageText, Pane *parentPane, const wchar_t *leftButtonText, const wchar_t *rightButtonText)`. All four current ExchangeDialog callers allocate `624` bytes and pass message text, the parent/layout reference, the shared OK literal [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md), and null right-button text, matching generated calls shaped as `new ExchangeAlertPane(message, this, g_szDialogOk, 0)`.
- UID0004CF helper names are now resolved at class evidence level: `DialogPane(L"", -1, false)`, `GetMemoryMan()`, `layoutReference->GetScreenOffset`, `layoutReference->GetBounds`, `GrafPort::GetTextWidth`, shared alert-family `MeasureAlertTextHeight`, `InitRectBounds`, `StaticTextControlPane::StaticTextControlPane`, `TextButtonControlPane::TextButtonControlPane`, `DialogPane::AddControl`, `SetFocusedControl(1)`, `SetPendingControl(1/2)`, `OnCreate`, `OnShow`, and `SlideOpenVertical`. The constructor also records static text allocation `0x114` / 276, optional button allocation `0x110` / 272, and the alert-family `m_layoutReference` store at `+0x26c`.
- UID0004CF no-code proof is no longer a generic helper-name blocker. Live target disassembly at `0x004b05b4-0x004b05d4` shows the unexercised `leftButtonText == NULL && rightButtonText != NULL` branch loading the wrapped-text width from the saved `this`/EH local before `MeasureAlertTextHeight`; emitting a full constructor body would either invent corrected behavior or transcribe an uninitialized/decompiler-shaped value. The class declaration stays forward-only, with no full member layout invented.
- `0x004b0870` clears `dword_69B32C` and belongs to the neighboring mix-dialog singleton, not this class.
- 2026-06-10 B001-026 added exact core child [UID:00033W][0x004b0490-0x004b086b.ExchangeAlertPaneCore](by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md), confirming constructor callers from ExchangeDialog packet alert paths, action-slot ref `0x0061a208`, and the `dword_69B330` clear helper boundary before the MixItemDialog clear helper at `0x004b0870`.
- 2026-06-10 B001-027 added exact close-active helper child [UID:00033Z][0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper](by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md). Live IDA confirms callers at `0x004ad741` and `0x004adf59`, singleton read at `0x004b0b20`, indirect close virtual call with argument `1`, and `0xcc` padding before/after the helper.
- 2026-06-30 B011 accepted ExchangeDialog empty-emitter implementation rechecked the class marker. Constructor/destructor route, vtable slots, method inventory, selected offsets, base-class evidence, direct child ownership, and declaration-shell safety were audited. The safe class output is a forward declaration plus `[[CHILDREN]]`; emitting a full member layout would invent inherited DialogPane field order. [UID:00033W][0x004b0490-0x004b086b.ExchangeAlertPaneCore](by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md) is now a non-emitting split inventory, while the constructor, button callback, and singleton-clear helper have exact child pages.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md)
- [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md)
- [UID:00033W][0x004b0490-0x004b086b.ExchangeAlertPaneCore](by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md)
- [UID:0004CF][0x004b0490-0x004b0819.ExchangeAlertPaneConstructor](by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md)
- [UID:0004CG][0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick](by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md)
- [UID:0004CH][0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper](by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md)
- [UID:00033Z][0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper](by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md)
- [UID:00014X][0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks](by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md)
- [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/86`.
  - Summary/evidence: exchange alert role, constructor/button/clear/destructor/close methods, singleton xrefs, vtables, callback slot behavior, interleaved MixItem callback caveat, and constructor call sites are documented; remaining work is minor source-facing callback naming.
- 2026-05-31:
  - Before: vtable evidence named the three table bases but did not link an exact by-memory child range and the class metadata did not explicitly mark the class reconstructable.
  - After: linked exact vtable-data child [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md), marked the class reconstructable, and raised scoring to `82/88`.
  - Summary/evidence: IDA MCP confirms the constructor stores, `OnButtonClick` slot, adjustor-thunk slots, scalar destructor slot, and the boundary before `ExchangeMoneyEditControlPane` RTTI.
- 2026-06-07 parent attachment:
  - Before: the class was reconstructable but parentless even though [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) already documented the feature file and valid path.
  - Changed to: `AUTOGEN_PARENT_UID:0000J9`; final class C++ remains blank.
  - Evidence: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) is `86/80` with `NexusTK/ui/dialogs/` placement and explicitly owns the exchange alert helper class. The mixed [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) aggregate remains parentless because it crosses exchange, item/mix, and compiler-thunk ownership, but this class is a single-owner exchange child.
- 2026-06-10 B001-026 gate repair:
  - Before: class completion was `82`, below the strict reconstructable direct-parent threshold for the new exact core child.
  - After: `85/88`; exact core child [UID:00033W][0x004b0490-0x004b086b.ExchangeAlertPaneCore](by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md) is `85/88`.
  - Evidence: constructor callers, vtable stores, action-slot ref, singleton clear/store refs, and negative boundary evidence against `0x004b0870` support direct ExchangeAlertPane ownership. Final callback/control names remain below C++ emission quality.
- 2026-06-10 B001-027 tail split:
  - Before: the close-active helper was listed only as a raw row under [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md).
  - After: `86/89`; exact helper child [UID:00033Z][0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper](by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md) is assigned to this class.
  - Evidence: IDA confirms the helper reads `dword_69B330`, calls the active alert virtual close slot with argument `1`, has only exchange packet/ready helper callers, and is separated from the following control helper by `0xcc` padding.
- 2026-06-30 B011 empty-emitter family implementation:
  - Before: this class had blank formal C++ and pointed the constructor, button callback, and singleton-clear helper at the mixed [UID:00033W][0x004b0490-0x004b086b.ExchangeAlertPaneCore](by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md) rows.
  - After: metadata is `88/90`, the formal block emits a forward declaration plus `[[CHILDREN]]`, and method inventory now points at exact child pages for the constructor, button callback, and singleton-clear helper.
  - Evidence: B011 current MCP reports `sub_4B0490` size `0x389`, `sub_4B0820` size `0x40`, `sub_4B0860` size `0x0b`, alert vtable slot `0x0061a208`, constructor vtable stores `0x0061a1c0/0x0061a228/0x0061a258`, singleton storage `0x0069b330`, and no function at the exclusive end addresses. Full class layout remains intentionally un-emitted.
- 2026-07-01 B009 UID0004CF constructor source-quality implementation:
  - Before: the constructor method row still said no constructor body was emitted because the target was below code-entry quality and had unresolved helper/source-layout issues.
  - After: [UID:0004CF][0x004b0490-0x004b0819.ExchangeAlertPaneConstructor](by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md) is `88/90`, routes an explicit formal no-code marker through this class, and keeps the class declaration-only output unchanged.
  - Evidence: B009 resolved the helper audit to source-facing DialogPane, RectBounds, GrafPort, StaticTextControlPane, TextButtonControlPane, BackPane bounds, GetMemoryMan, and alert-layout names; current callers all pass OK/null-right arguments; vtable stores, singleton publication, `m_layoutReference`, focus/pending control behavior, and compiler-only lowering are documented on the child. The remaining no-body proof is the right-button-only branch that reads width from a saved `this`/EH local.
