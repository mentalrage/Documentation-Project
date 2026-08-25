<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002I2-mappane-find-active-effect-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002I2-mappane-find-active-effect-source-quality.md](0002I2-mappane-find-active-effect-source-quality.md)
- Source report SHA256 before cleanup: `AFB0A5F0CB8F16767241A584DCB3383AAB9477089719EFD1348267EF887D9C3E`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `145-150`
- Original language: `powershell`
- Block SHA256: `0EB22009753286AF58BB5DE7F8732840BAF02FB14CF0FDB2D50BDEAA28BCBE23`

```powershell
rg -n "0002I2|0x00503e90|MapPaneFindActiveEffect|FindActiveEffect|0x004f1286|g_activeMapPane" `
  "source-3\project-documentation\tools\leaser\Agents\Agent-B001\research" `
  "source-3\project-documentation\tools\leaser\Agents\Agent-B002\research" `
  "source-3\project-documentation\tools\leaser\Agents\Agent-B003\research"
```

## Removed Block R002

- Original source lines: `165-170`
- Original language: `powershell`
- Block SHA256: `4E9813A128AAC414D0AEE72FB4B280E7224BB05317CFA2EB11C3692D5D053A50`

```powershell
python source-3\project-documentation\tools\validator.py --target source-3\project-documentation\by-memory\0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md --target source-3\project-documentation\by-memory\-coverage-report.md --target source-3\project-documentation\by-class\MapPane.md --target source-3\project-documentation\by-file\MapPane.md
python source-3\project-documentation\tools\memory_ranges.py report
python source-3\project-documentation\tools\validator.py --mode autogen --apply
python source-3\project-documentation\tools\validator.py --mode rescore --apply
```
