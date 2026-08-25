<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00010C-00010G-clan-status-pane-ui-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00010C-00010G-clan-status-pane-ui-source-quality.md](00010C-00010G-clan-status-pane-ui-source-quality.md)
- Source report SHA256 before cleanup: `DD5A95E8A538AEEBA6503C52E0DCAD0C15A1CD9932B0E719840DD50E63EC2875`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `258-260`
- Original language: `powershell`
- Block SHA256: `29F7C4BD85BCD2ABB59028C71D1D94F137D8E68E47331F59BC302E57F2288714`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `264-266`
- Original language: `powershell`
- Block SHA256: `444B0F1827085E171429C02DDCFB0734DAE22628BB469A2E564E745285F7C9B3`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md --apply --queue-timeout 240
```
