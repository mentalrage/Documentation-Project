<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0002GP-ApplicationGetVersionMajor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002GP-ApplicationGetVersionMajor-source-quality.md](0002GP-ApplicationGetVersionMajor-source-quality.md)
- Source report SHA256 before cleanup: `63C8AB6C16075C4E70EA4F59D5FFF8C244BACAEE0522C1897D3A2463A83559DF`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `367-372`
- Original language: `powershell`
- Block SHA256: `24C02A4FB760CD5FF4001D4FB5053006AB3D2E130E1A0419BC0FCBC64AA1A98A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00465300-0x00465308.ApplicationGetVersionMajor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240
```
