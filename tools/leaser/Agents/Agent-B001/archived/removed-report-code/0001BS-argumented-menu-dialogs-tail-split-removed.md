<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001BS-argumented-menu-dialogs-tail-split.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001BS-argumented-menu-dialogs-tail-split.md](0001BS-argumented-menu-dialogs-tail-split.md)
- Source report SHA256 before cleanup: `D43D7B3E27345CDD8A057ACC7E3569049287718D629AA77A6481FA26C05700DA`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `275-294`
- Original language: `powershell`
- Block SHA256: `F2BAFA8CECD89C6322D5033C1A5D273223492E5528522DD391B74DEAC00FE1D6`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\ArgumentedMenuMenuItemList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\ArgumentedMenuDialogs.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\ArgumentedItemInputDialogs.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-item\ArgumentedItemPurchaseHelpers_51f450_51f640.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
```
