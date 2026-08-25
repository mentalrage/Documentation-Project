<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002FG-ChattingVarietySelectPaneInitialHitTest-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002FG-ChattingVarietySelectPaneInitialHitTest-source-quality.md](0002FG-ChattingVarietySelectPaneInitialHitTest-source-quality.md)
- Source report SHA256 before cleanup: `F49F167257018BB4941A939CE9F370EB69ACFA936D6439544AD778F5167B2216`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `252-259`
- Original language: `powershell`
- Block SHA256: `18BB2E1A729ADE6B0D1836F0CF6010F7103DB7A99EC841EF979BA57E5F59F65E`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ChattingVarietyPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0047efb0-0x00483ef7.ChattingUI.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Chatting.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md --apply --queue-timeout 240
```
