<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\000012-brdir-Notification-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000012-brdir-Notification-source-quality.md](000012-brdir-Notification-source-quality.md)
- Source report SHA256 before cleanup: `CB87B1785C1B5DCE93C0E97F275A95C19D61E92D1F26D80ED645A292C1147F08`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `550-554`
- Original language: `powershell`
- Block SHA256: `0BE41237E20D46017B5BC382ABF5109B511690D06DB4909E6ABE5133E54D3856`

```powershell
python .\tools\validator.py --mode file --file .\by-class\brdir__Notification.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `558-568`
- Original language: `powershell`
- Block SHA256: `8B0662E4094FA1DC05AE0B4C82AFE9AF4D5E70378EB54478C97961480B213A5B`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0061fbac-0x0061fbdc.WorkThreadNotificationVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\MiscWorkThread.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MiscWorkThread.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-enum\MiscWorkThreadMessageId.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00528290-0x005283d5.CashShopRequestAuthDirectory.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
