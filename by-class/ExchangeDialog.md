*** UID:00004R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExchangeDialog

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md), plus destructor `0x004b0a20-0x004b0a5a`
- Current recovered file: `source-3/simroot_v2/class_ExchangeDialog.cpp`
- Confidence: strong for behavior and source placement; medium for omitted helper names.

## Class Purpose

`ExchangeDialog` is the player-to-player trade dialog. It builds the two-sided exchange window, maintains the exchange id and ready/money flags, invokes item picker dialogs, submits local money, handles cancel/confirm actions, and processes server exchange packets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ExchangeDialog` | `0x004ac8a0-0x004ad0a9` | Constructs the `DL_20` trade dialog, item lists, money controls, labels, and initial state from the server packet. |
| `OnButtonAction` | `0x004ad0b0-0x004ad1c9` | Handles OK/confirm, add-item, and cancel buttons. Sends opcode `0x4A` or opens `AddItemDialog`. |
| `OnClose` | `0x004ad1d0-0x004ad1f3` | Disables the close control and clears pending close state. |
| `UpdateButtonStates` | `0x004ad200-0x004ad2fc` | Enables or disables OK/cancel/confirm/money controls from local and remote offer flags. |
| `DispatchExchangePacket` | [UID:00014L][0x004ad320-0x004ad7b2.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b2.ExchangeDialogPacketDispatcher.md) | IDA-confirmed omitted helper. Dispatches server opcode `0x42` subcommands for items, money, cancel, and ready/confirm messages. |
| `OnKeyEvent` | `0x004ad7d0-0x004ad85e` | Submits money after numeric key input in the money control. |
| `SendCancelPacket` | `0x004ad900-0x004ad95e` | Sends opcode `0x4A`, subcommand `4`, and the exchange id. |
| `SubmitExchangeAmount` | `0x004ad960-0x004ada15` | Updates the local amount and sends opcode `0x4A` subcommand `3` or fallback subcommand `4`. |
| `SetExchangeAmount` | `0x004ada20-0x004ada83` | Updates the local amount, locks decreased amounts, enables OK, and schedules a timer. |
| `OpenAddItemWithCountDialog` | [UID:00014M][0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper.md) | IDA-confirmed omitted helper that constructs `AddItemWithCountDialog` from packet data. |
| `UpdateMoneyFromPacketRaw` | [UID:00014N][0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate](by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md) | Raw non-IDA function body. Updates local/remote money display and clears local amount when the packet amount is zero. |
| `ShowExchangeCancelAlert` | [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md) | IDA-confirmed omitted helper that decodes a message, closes an existing alert, constructs `ExchangeAlertPane`, and closes exchange UI. |
| `ShowExchangeReadyAlert` | [UID:00014P][0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md) | IDA-confirmed omitted helper for ready/confirm packet state and alert creation. |
| `OnControlFocusChange` | `0x004adfb0-0x004ae052` | Normalizes and submits money text when focus leaves control `6`, then updates hover control. |
| `ScalarDeletingDestructor` | `0x004b0a20-0x004b0a5a` | Chains to `DialogPane` teardown and optionally frees storage. |

## Data And Controls

- `+0x26c`: exchange session id read from packet bytes `+2`.
- `+0x270` through `+0x278`: packed ready/confirmed, remote-ready, amount, and lock/change flags.
- Control `5`: local offered-item list.
- Control `6`: local money edit control.
- Control `8`: remote offered-item list.
- Control `9`: remote money text display.
- Uses `g_pPlayerProfile`, `g_pPlayerData`, `g_pDefaultParent`, `g_pScreenPane`, and `g_packetSender`.

## Open Questions

- Import or explicitly model `0x004ad320`, `0x004ada90`, `0x004add40`, and `0x004ade60` in Wave3 before source migration.
- Decide whether the raw `0x004adca0` body is a valid separate method, duplicate decompiler split from `0x004ad320`, or a vtable-only helper that IDA failed to create. IDA currently has no function object or xrefs for the raw start.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md)
- [UID:00004T][ExchangeMoneyEditControlPane](by-class/ExchangeMoneyEditControlPane.md)
- [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/80`.
  - Summary/evidence: trade-dialog role, constructor/action/close/state/update/packet/money/alert/helper methods, data/control map, child control links, and open omitted/raw helper questions are documented; confidence remains limited by raw `0x004adca0` modeling and omitted helper names.
