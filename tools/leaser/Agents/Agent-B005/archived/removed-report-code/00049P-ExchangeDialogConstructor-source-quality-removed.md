<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00049P-ExchangeDialogConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00049P-ExchangeDialogConstructor-source-quality.md](00049P-ExchangeDialogConstructor-source-quality.md)
- Source report SHA256 before cleanup: `AF69B52BA732C65CE4B8D3DE7C77AE6D5B162BAFED5734D4BEE2F533A8A5988D`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `424-429`
- Original language: `powershell`
- Block SHA256: `CFCD3E9B167CCD5F3E858588B04974A307BC11896779FBC2E4DB9A4BBE85A7F8`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `442-445`
- Original language: `powershell`
- Block SHA256: `B290F993C6F9B93123D3981A1551804CE3216A6EFAE9A12CAEC2588E2165B2BC`

```powershell
rg -n "UID:00049P|ExchangeDialog::ExchangeDialog" .\auto-generated\NexusTK\ui\dialogs\ExchangeDialog.cpp
rg -n "00049P" .\auto-generated\-ag-coverage-report-by-memory.md .\auto-generated\-ag-research-tracker.md .\project-level\-auto-completion-stats.md
```
