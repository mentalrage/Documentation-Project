<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002A9-TargetSelectionModeFlags-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002A9-TargetSelectionModeFlags-source-quality.md](0002A9-TargetSelectionModeFlags-source-quality.md)
- Source report SHA256 before cleanup: `9E4DD990568BFB5E8AD8915D95AD0ABC434BC90D5BD1C15C9DFEEE0B375F029C`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `239-243`
- Original language: `powershell`
- Block SHA256: `B6BBC5FFADDD8678D9E1DB143877150BD1DC4ED05BFB666B6F4A527E5A467F5E`

```powershell
python tools\validator.py --mode file --file by-memory\0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md --apply --queue-timeout 240 --wait-generated
python tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240 --wait-generated
python tools\validator.py --mode file --file by-memory\0x0066d000-0x0069d000.DataSection.md --apply --queue-timeout 240 --wait-generated
```
