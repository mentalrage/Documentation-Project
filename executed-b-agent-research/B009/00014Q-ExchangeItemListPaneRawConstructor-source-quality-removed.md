<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\00014Q-ExchangeItemListPaneRawConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00014Q-ExchangeItemListPaneRawConstructor-source-quality.md](00014Q-ExchangeItemListPaneRawConstructor-source-quality.md)
- Source report SHA256 before cleanup: `53EB85F0E84794574BCEF94E16CC136CE1AECCE93A604524B368A6CFC3F904B2`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `222-228`
- Original language: `powershell`
- Block SHA256: `D28F8B03FDE1059566FE60F77717CE9CF66C97A38128073C3E5A92A3572C8A08`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ExchangeItemListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ExchangeDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `232-270`
- Original language: `text`
- Block SHA256: `0186582DF6DED24A085C6B97D13C70F6AECC80C579C9D9BE72FE103B1200E30C`

```text
python .\tools\validator.py --mode file --file by-memory\0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md --apply --queue-timeout 240
  command_id: 000000001805
  command_timestamp: 2026-06-25T17:09:32-04:00
  exit code: 0
  ok: 1
  generated_refresh: deferred

python .\tools\validator.py --mode file --file by-class\ExchangeItemListPane.md --apply --queue-timeout 240
  command_id: 000000001807
  command_timestamp: 2026-06-25T17:09:42-04:00
  exit code: 0
  ok: 1
  generated_refresh: deferred
  warnings: pre-existing missing reference diagnostics for UID 0003NF / UID 00025A.

python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240
  command_id: 000000001809
  command_timestamp: 2026-06-25T17:09:48-04:00
  exit code: 0
  ok: 1
  generated_refresh: deferred
  warnings: pre-existing missing target diagnostics for UID 00014T stale path.

python .\tools\validator.py --mode file --file by-class\ExchangeDialog.md --apply --queue-timeout 240
  command_id: 000000001811
  command_timestamp: 2026-06-25T17:09:53-04:00
  exit code: 0
  ok: 1
  generated_refresh: deferred

python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240
  command_id: 000000001813
  command_timestamp: 2026-06-25T17:10:03-04:00
  exit code: 0
  ok: 1
  generated_refresh: deferred
  warnings: pre-existing missing target diagnostic for UID 00014T stale path.
```
