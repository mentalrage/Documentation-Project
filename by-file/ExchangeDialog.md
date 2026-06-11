*** UID:0000J9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ExchangeDialog

## Status

- Confidence: strong for source grouping, behavior, and exchange-alert singleton ownership; medium-high for exact original filename.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/ExchangeDialog.cpp`
- Current generated sources: `class_ExchangeDialog.cpp`, `class_ExchangeItemListPane.cpp`, `class_ExchangeMoneyEditControlPane.cpp`, and `class_ExchangeAlertPane.cpp`
- Evidence basis: generated Wave3 sources, raw `simroot_v2` metadata, and IDA MCP boundary/decompile checks through the 2026-06-08 Batch 116 parent/source recheck.

## Hypothesis

`ExchangeDialog.cpp` should own the player-to-player trade session UI. This is distinct from [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md): `AddItemDialog` and `AddItemWithCountDialog` are reusable item pickers invoked by exchange, while `ExchangeDialog` owns the live trade window, offered item lists, money input, exchange packet state, and confirmation alerts.

Likely original grouping:

```text
ui/dialogs/ExchangeDialog.cpp
```

Likely contents:

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md) | `0x004ac8a0-0x004ae052`, destructor `0x004b0a20` | `class_ExchangeDialog.cpp` | Main two-party exchange dialog, packet dispatch, money submission, and ready/cancel flow. |
| [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md) | shared destructor [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md), `0x004ae060-0x004ae4b6` | `class_ExchangeItemListPane.cpp` | Private list widget for offered item rows. |
| [UID:00004T][ExchangeMoneyEditControlPane](by-class/ExchangeMoneyEditControlPane.md) | `0x004b0a60-0x004b0ba4`; false outlier `0x00430058` | `class_ExchangeMoneyEditControlPane.cpp` | Private numeric money edit control used by the local offer slot. |
| [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md) | `0x004b0490-0x004b0b30`, vtables [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md), exact vtable child [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md) | `class_ExchangeAlertPane.cpp` | Modal alert shown for cancellation and exchange confirmation states. |
| [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) | `0x004b0880-0x004b08a1` | long generated template filename | Interleaved callback-template dispatch row in the exchange/item/mix tail; construction sites tie it to `MixItemDialog` quantity callbacks, not ExchangeDialog ownership. |
| [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md) | `0x0069b330` | generated global-data alias | Active exchange alert singleton. |
| [UID:0002VZ][0x0069b330-0x0069b334.g_pExchangeAlertPane](by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md) | `0x0069b330-0x0069b334` | exact global-data slot | Physical `.data` storage for the active exchange alert singleton. |

## Packet And Control Model

- Client sends exchange requests through opcode `0x4A`: subcommand `3` submits money, subcommand `4` cancels or confirms depending state, and subcommand `5` is used by the alternate confirm path.
- IDA-confirmed server packet dispatcher `0x004ad320` checks opcode `0x42` and handles add-item, item-row update, money update, cancel message, and ready/confirm message cases.
- Controls `5` and `8` are the local and remote `ExchangeItemListPane` scrollable lists.
- Control `6` is the local `ExchangeMoneyEditControlPane`; control `9` is the remote money display.
- The constructor loads `DLGEXC1.EPF`/`DLGEXC1.PAL`, builds a fixed `451x371` dialog, reads the exchange id and partner name from the packet, and displays player/partner gold labels.

## Boundary Notes

- IDA confirms normal functions at [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md), [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md), [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md), and [UID:00014P][0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md), but current generated recovery output omits them from `class_ExchangeDialog.cpp`.
- Wave3 lists `ExchangeDialog::OnExchangePacket` at [UID:00014N][0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate](by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md); IDA does not have a function object there, but raw bytes form a complete money-update helper ending at `0x004add33`.
- Wave3 lists `ExchangeItemListPane::ExchangeItemListPane` at `0x004ae060`; IDA does not have a function object there, but raw bytes form a complete constructor at `0x004ae060-0x004ae0a4`.
- Raw helpers at [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) and [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) look like `ExchangeItemListPane` row upsert/find helpers. IDA currently has no function objects or xrefs for those starts, so treat them as data-cleanup targets before migration.
- 2026-06-03 IDA MCP confirms the list pane's exact helper boundaries, `0xcc` padding between constructor/upsert/find/null/draw bodies, vtable views at `0x00619dc8`, `0x00619e50`, and `0x00619e80`, null virtual slot `0x00619e40 -> 0x004ae1b0`, and draw slot `0x00619e48 -> 0x004ae1c0`.
- `ExchangeMoneyEditControlPane::GetClassName` at `0x00430058` is a false generated method start inside [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md), not an Exchange control method.
- 2026-05-26 IDA MCP confirms `ExchangeAlertPane` vtables at `0x0061a1c0`, `0x0061a228`, and `0x0061a258`, installed by constructor stores at `0x004b0514`, `0x004b051a`, and `0x004b0524`. The generated metadata still reports `class_ExchangeAlertPane.meta_wave3` `vtable_count: 0`.
- 2026-05-31 IDA MCP `py_eval` and xrefs confirm exact `ExchangeAlertPane` vtable data [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md), ending before adjacent `ExchangeMoneyEditControlPane` RTTI at `0x0061a260`.
- 2026-06-07 Batch038 IDA refresh confirms [UID:0002VZ][0x0069b330-0x0069b334.g_pExchangeAlertPane](by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md) as exact exchange-owned singleton storage: packet/action refs at `0x004ad611`, `0x004ad739`, `0x004addd3`, and `0x004adf51`, publish/fallback refs at `0x004b04ff`/`0x004b0506`, and clear/close refs at `0x004b0860`, `0x004b09d6`, and `0x004b0b20`.
- 2026-06-08 Batch 116 parent/source recheck confirms this file remains the direct source parent for the exchange alert, exchange-dialog destructor, exchange money edit control, and active exchange alert singleton rows in [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md). The same pass rejects this file as the direct parent for the neighboring item/mix packet-close, quantity, callback, singleton-clear, and destructor/thunk rows, which are documented under [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), [UID:00008J][MixItemDialog](by-class/MixItemDialog.md), and [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).

## Migration Notes

Use one feature file for the dialog and private helper panes:

```powershell
python source-3\wave3.py create file ExchangeDialog.cpp --kind source --simpath ui/dialogs/ExchangeDialog.cpp --dry-run
python source-3\wave3.py attach class ExchangeDialog --to-file ExchangeDialog.cpp --dry-run
python source-3\wave3.py attach class ExchangeItemListPane --to-file ExchangeDialog.cpp --dry-run
python source-3\wave3.py attach class ExchangeMoneyEditControlPane --to-file ExchangeDialog.cpp --dry-run
python source-3\wave3.py attach class ExchangeAlertPane --to-file ExchangeDialog.cpp --dry-run
```

Do not attach `AddItemDialog` here unless later source evidence proves the original project folded item picker dialogs into the player exchange file. Current evidence favors keeping item pickers in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) and cross-referencing them from exchange.

For broad overlapping memory aggregates, use this page only for the exchange-owned rows. [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md) and [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) remain unassigned as aggregates because they interleave ExchangeDialog rows with ItemDialogs/function-object rows.

## Cross-References

- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md)
- [UID:00004T][ExchangeMoneyEditControlPane](by-class/ExchangeMoneyEditControlPane.md)
- [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md)
- [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md)
- [UID:00014X][0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks](by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md)
- [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md)
- [UID:00014N][0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate](by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:0001RA][exchange-dialog-resources](by-resource/exchange-dialog-resources.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)

## Changes

- 2026-06-08 A007 Batch 116 parent/source recheck:
  - What existed before: `COMPLETION:87`, `CONFIDENCE:85`; ExchangeDialog already cleared the parent gate but the overlapping item/mix tail relationship was not explicit enough for Batch 116 routing decisions.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:86`; added explicit evidence that this file owns the exchange alert/dialog/money-control tail rows while rejecting direct ownership of the neighboring item/mix/function-object rows.
  - Summary/evidence: current Batch 116 IDA MCP and associated docs distinguish ExchangeDialog-owned rows in [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) from ItemDialogs-owned packet-close/quantity/destructor rows in [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)/[UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md). This supports exact exchange children but keeps the broad overlapping aggregates unassigned.

- 2026-06-07 A009 Batch038 singleton split:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:80`; exchange-alert global ownership was present through [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md) but not tied to the exact split memory child.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:85`; added [UID:0002VZ][0x0069b330-0x0069b334.g_pExchangeAlertPane](by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md) and exact Batch038 xrefs.
  - Summary/evidence: live IDA confirms the singleton slot is directly exchange-alert/session state. Confidence rises to the corrected parent gate while preserving original-filename and raw-helper caveats.

- 2026-06-01 reconstruction path fill-in:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the body proposed `ui/dialogs/ExchangeDialog.cpp`.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: path now matches the documented module folder and lets reconstructable ExchangeDialog memory pages parent to the feature file without inventing class-level source names.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: exchange dialog grouping, class/private control contents, packet/control model, raw helper boundary notes, false method exclusion, migration plan, resource/global/type cross-references, and item-picker boundary are documented; confidence remains strong but capped by exact original filename and raw helper cleanup questions.
- 2026-06-06 resource-name correction:
  - What existed before: packet/control notes still said the constructor loaded `DL_20`/`DL_20.PAL`.
  - Changed to: `DLGEXC1.EPF`/`DLGEXC1.PAL`.
  - Summary/evidence: [UID:0001RA][exchange-dialog-resources](by-resource/exchange-dialog-resources.md) records IDA MCP UTF-16 strings and xrefs at `0x0061a304` and `0x0061a31c`; the same resource page records that this pass found no support for the older `DL_20` names.
