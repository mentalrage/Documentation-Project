<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001AW-mappane-packet-source-split-continuation-batch2.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001AW-mappane-packet-source-split-continuation-batch2.md](0001AW-mappane-packet-source-split-continuation-batch2.md)
- Source report SHA256 before cleanup: `33147F7DB5A3B18CE9311E9BA0BF4FC4D6CEB84AD0C911DD1EFFFFC51BFA67C5`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `407-416`
- Original language: `powershell`
- Block SHA256: `A46CF4D0F87B8FB115640C6577665AA0107B1E6327A28096C50513AD2A638D1C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0050e4c0-0x00514920.MapPanePacketHandlers.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\MapPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\MapPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
```
