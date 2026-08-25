<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md](00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md)
- Source report SHA256 before cleanup: `A65CB31FE60FC0209D9ACB403193D1EEE29852F893B370422FF14F5015403BF8`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `439-446`
- Original language: `powershell`
- Block SHA256: `9498D3BFACA342F62FB2EDE3304B6DDB1CAF273FDF6E9FC2745763E288794F9C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ExchangeItemListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `450-453`
- Original language: `powershell`
- Block SHA256: `1FECF12B033614177238A9DDB99C6E6C70FEA2D713931C001B067E8C3F70BBBE`

```powershell
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
