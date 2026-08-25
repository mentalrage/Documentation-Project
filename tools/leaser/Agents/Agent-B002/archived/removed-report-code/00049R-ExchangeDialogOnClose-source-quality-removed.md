<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00049R-ExchangeDialogOnClose-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00049R-ExchangeDialogOnClose-source-quality.md](00049R-ExchangeDialogOnClose-source-quality.md)
- Source report SHA256 before cleanup: `73E7B90CC9707A6C81C65F00ACD8A0851F1940975E137508479CE17493386DFA`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `320-327`
- Original language: `powershell`
- Block SHA256: `833B1D4E20E47ABFE0204764D8C19F20E3BEAF8522B259DDBE13A19D9ACA7266`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00619d28-0x00619dc4.ExchangeDialogVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `331-333`
- Original language: `powershell`
- Block SHA256: `2CB0831B6DDA803F66C5D58F8461DB5D632E9CA124E81580BC5181EA765FCA9D`

```powershell
Select-String -Path .\auto-generated\NexusTK\ui\dialogs\ExchangeDialog.cpp -Pattern "validator-command-id","validator-refreshed-at","UID:00049R","ExchangeDialog::OnClose"
```
