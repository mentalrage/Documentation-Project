*** UID:0000J9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ExchangeDialog

## Status

- Confidence: strong for source grouping and behavior; medium for exact original filename.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/ExchangeDialog.cpp`
- Current generated sources: `class_ExchangeDialog.cpp`, `class_ExchangeItemListPane.cpp`, `class_ExchangeMoneyEditControlPane.cpp`, and `class_ExchangeAlertPane.cpp`
- Evidence basis: generated Wave3 sources, raw `simroot_v2` metadata, and IDA MCP boundary/decompile checks on 2026-05-23 and 2026-05-24.

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

## Packet And Control Model

- Client sends exchange requests through opcode `0x4A`: subcommand `3` submits money, subcommand `4` cancels or confirms depending state, and subcommand `5` is used by the alternate confirm path.
- IDA-confirmed server packet dispatcher `0x004ad320` checks opcode `0x42` and handles add-item, item-row update, money update, cancel message, and ready/confirm message cases.
- Controls `5` and `8` are the local and remote `ExchangeItemListPane` scrollable lists.
- Control `6` is the local `ExchangeMoneyEditControlPane`; control `9` is the remote money display.
- The constructor loads `DL_20`/`DL_20.PAL`, builds a fixed `451x371` dialog, reads the exchange id and partner name from the packet, and displays player/partner gold labels.

## Boundary Notes

- IDA confirms normal functions at [UID:00014L][0x004ad320-0x004ad7b2.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b2.ExchangeDialogPacketDispatcher.md), [UID:00014M][0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper.md), [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md), and [UID:00014P][0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md), but current Wave3 generated source omits them from `class_ExchangeDialog.cpp`.
- Wave3 lists `ExchangeDialog::OnExchangePacket` at [UID:00014N][0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate](by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md); IDA does not have a function object there, but raw bytes form a complete money-update helper ending at `0x004add33`.
- Wave3 lists `ExchangeItemListPane::ExchangeItemListPane` at `0x004ae060`; IDA does not have a function object there, but raw bytes form a complete constructor at `0x004ae060-0x004ae0a4`.
- Raw helpers at [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) and [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) look like `ExchangeItemListPane` row upsert/find helpers. IDA currently has no function objects or xrefs for those starts, so treat them as data-cleanup targets before migration.
- 2026-06-03 IDA MCP confirms the list pane's exact helper boundaries, `0xcc` padding between constructor/upsert/find/null/draw bodies, vtable views at `0x00619dc8`, `0x00619e50`, and `0x00619e80`, null virtual slot `0x00619e40 -> 0x004ae1b0`, and draw slot `0x00619e48 -> 0x004ae1c0`.
- `ExchangeMoneyEditControlPane::GetClassName` at `0x00430058` is a false generated method start inside [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md), not an Exchange control method.
- 2026-05-26 IDA MCP confirms `ExchangeAlertPane` vtables at `0x0061a1c0`, `0x0061a228`, and `0x0061a258`, installed by constructor stores at `0x004b0514`, `0x004b051a`, and `0x004b0524`. The generated metadata still reports `class_ExchangeAlertPane.meta_wave3` `vtable_count: 0`.
- 2026-05-31 IDA MCP `py_eval` and xrefs confirm exact `ExchangeAlertPane` vtable data [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md), ending before adjacent `ExchangeMoneyEditControlPane` RTTI at `0x0061a260`.

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
- [UID:00014L][0x004ad320-0x004ad7b2.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b2.ExchangeDialogPacketDispatcher.md)
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

- 2026-06-01 reconstruction path fill-in:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the body proposed `ui/dialogs/ExchangeDialog.cpp`.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: path now matches the documented module folder and lets reconstructable ExchangeDialog memory pages parent to the feature file without inventing class-level source names.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: exchange dialog grouping, class/private control contents, packet/control model, raw helper boundary notes, false method exclusion, migration plan, resource/global/type cross-references, and item-picker boundary are documented; confidence remains strong but capped by exact original filename and raw helper cleanup questions.
