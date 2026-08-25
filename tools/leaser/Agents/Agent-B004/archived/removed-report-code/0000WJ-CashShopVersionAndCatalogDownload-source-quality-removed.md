<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0000WJ-CashShopVersionAndCatalogDownload-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000WJ-CashShopVersionAndCatalogDownload-source-quality.md](0000WJ-CashShopVersionAndCatalogDownload-source-quality.md)
- Source report SHA256 before cleanup: `1412E38115412E78329077F1FCE7F15329BD1F471FE1CFCA79D565169D04C442`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `361-366`
- Original language: `powershell`
- Block SHA256: `668B62E67524B0226EA1F8265D6BF2B6B2B02E85B00E01B3D1160C913FC83C1C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FileDownloader.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\FileDownloader.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0041a670-0x0041b69f.FileDownloaderDispatch.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `370-377`
- Original language: `powershell`
- Block SHA256: `F59121C143C8EB687695504C4F18533BE6B4792ED851634BFE6312BAB7208F5C`

```powershell
python .\tools\validator.py --mode file --file by-file\FittingRoom.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\FittingRoomDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\CashShopVersionRequest.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\CashShopVersionRequest.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pCashShopRequest.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a738-0x0067a73c.g_pCashShopRequest.md --apply --queue-timeout 240
```
