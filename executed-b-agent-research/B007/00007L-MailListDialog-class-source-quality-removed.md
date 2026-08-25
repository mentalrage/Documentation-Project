<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\00007L-MailListDialog-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00007L-MailListDialog-class-source-quality.md](00007L-MailListDialog-class-source-quality.md)
- Source report SHA256 before cleanup: `28149344A5F99505FB4065730013974EB3A77F41B847A5BDCB6C70419A1F2F9B`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `5`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `40-42`
- Original language: `powershell`
- Block SHA256: `C89F93482B536B6B3798358C86658C6DCC60C5A1337C96797B3A2C6A16B367CE`

```powershell
python .\tools\validator.py --mode file --file .\by-class\MailListDialog.md --queue-timeout 240; exit $LASTEXITCODE
```

## Removed Block R002

- Original source lines: `60-63`
- Original language: `powershell`
- Block SHA256: `8797B757AC9BADE1B14A984E06BB1E0AD2C230ED3F27B0A9ECF4814B2348D102`

```powershell
$body = @{ jsonrpc = '2.0'; id = 1; method = 'tools/list'; params = @{} } | ConvertTo-Json -Depth 8
Invoke-WebRequest -UseBasicParsing -Method Post -Uri 'http://127.0.0.1:13337/mcp' -ContentType 'application/json' -Body $body -TimeoutSec 5
```

## Removed Block R003

- Original source lines: `515-523`
- Original language: `powershell`
- Block SHA256: `31DBB135CC314ECB0B82FCB1B376F7E4C4E7759053BAE183BB27A118213B3236`

```powershell
Get-Content .\by-class\MailListDialog.md
Get-Content .\by-memory\0x00479110-0x0047a894.MailListDialogCore.md
Get-Content .\by-class\MailListPane.md
Get-Content .\by-memory\0x0047a8a0-0x0047b110.MailListPaneCore.md
Get-Content .\by-file\MailDialogs.md
Get-Content .\by-memory\0x00479110-0x0047ec2b.MailDialogs.md
Get-Content .\by-type\by-vtable\MailDialogCoreVtables.md
```

## Removed Block R004

- Original source lines: `569-580`
- Original language: `powershell`
- Block SHA256: `F7524E47AA2F8DADCBEBA129AA9C788B6D1BDF3035261C0F852BF27A86A64F20`

```powershell
python .\tools\validator.py --mode file --file .\by-class\MailListDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00479110-0x0047a894.MailListDialogCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MailListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047a8a0-0x0047b110.MailListPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\MailDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00479110-0x0047ec2b.MailDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\MailDialogCoreVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\BulletinReplyAlerts.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MailDeleteReplyAlert.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ConfirmDeleteMailAlert.md --apply --queue-timeout 240
```

## Removed Block R005

- Original source lines: `584-586`
- Original language: `powershell`
- Block SHA256: `D3BEB97616B6D37FC8A4F0AA0BB61F6EE69724C8CA6C63DA92FCAD5F206B7667`

```powershell
python .\tools\validator.py --mode changed --apply --queue-timeout 240
```
