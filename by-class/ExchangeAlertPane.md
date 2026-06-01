*** UID:00004Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExchangeAlertPane

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- Vtables: [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md) at `0x0061a1c0`, `0x0061a228`, and `0x0061a258`; exact data child [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md).
- Current recovered file: `source-3/simroot_v2/class_ExchangeAlertPane.cpp`
- Confidence: strong.

## Class Purpose

`ExchangeAlertPane` is the modal message/confirmation pane used by player exchange. It centers itself on the parent exchange dialog, sizes itself from message width and button count, creates optional left/right text buttons, stores the active singleton pointer, and invokes exchange callbacks when a button is clicked.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ExchangeAlertPane` | `0x004b0490-0x004b0818` | Constructs a variable-size alert with message text, optional buttons, centered placement, and parent pointer. |
| `OnButtonClick` | `0x004b0820-0x004b085f` | Handles button ids `1` and `2`, slides closed, invokes primary/secondary callback slots, and closes the dialog. |
| `ClearExchangeAlertPane` | `0x004b0860-0x004b086a` | Tiny helper that clears [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md). |
| interleaved [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) | `0x004b0880-0x004b08a1` | Not an `ExchangeAlertPane` method; kept visible here only because it sits between alert helper rows in the interleaved tail island. |
| `AdjustorThunk` | [UID:00014X][0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks](by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md) | Compiler-generated secondary/tertiary vtable destructor adjustor thunks. |
| `ScalarDeletingDestructor` | `0x004b09d0-0x004b0a14` | Clears `g_pExchangeAlertPane`, chains through dialog teardown, and optionally frees storage. |
| `CloseActiveExchangeAlert` | `0x004b0b20-0x004b0b30` | Closes the active alert if `g_pExchangeAlertPane` is set. |

## Evidence Notes

- IDA xrefs to `0x0069b330` show constructor storage at `0x004b04ff`, destructor clear at `0x004b09d6`, clear helper `0x004b0860`, and close checks from `ExchangeDialog` packet helpers at `0x004ad611`, `0x004ad739`, `0x004addd3`, and `0x004adf51`.
- 2026-05-26 IDA MCP vtable pass confirms `ExchangeAlertPane` primary/secondary/tertiary vtables at `0x0061a1c0`, `0x0061a228`, and `0x0061a258`, installed by constructor stores at `0x004b0514`, `0x004b051a`, and `0x004b0524`.
- 2026-05-31 IDA MCP `py_eval` and xrefs prove exact vtable-data range [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md), ending immediately before `ExchangeMoneyEditControlPane` RTTI at `0x0061a260`.
- `OnButtonClick` is the primary-table slot `+0x48`. It invokes callback extension slots `+0x5c` and `+0x60`, but the concrete `ExchangeAlertPane` table currently holds no-op/guard entries for both slots.
- IDA confirms `0x004b08cd` and `0x004b08d8` as vtable-only adjustor thunks into `0x004b09d0`.
- IDA MCP decompilation on 2026-05-25 confirms `OnButtonClick` at `0x004b0820` performs alert button dispatch directly. The neighboring callback wrapper at `0x004b0880` is constructed by MixItemDialog quantity paths, not by ExchangeAlertPane.
- Constructor calls are at `0x004ad656`, `0x004ad775`, `0x004ade18`, and `0x004adf8d` inside the exchange packet alert paths.
- `0x004b0870` clears `dword_69B32C` and belongs to the neighboring mix-dialog singleton, not this class.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md)
- [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md)
- [UID:00014X][0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks](by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md)
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
