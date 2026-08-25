<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0000C6-SayToUserMessageInputPane-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000C6-SayToUserMessageInputPane-class-source-quality.md](0000C6-SayToUserMessageInputPane-class-source-quality.md)
- Source report SHA256 before cleanup: `CEE6F90C13FF7F40733CA8B18DCFCD639045BBACF3BDDA30AAB5379FE2DFFB85`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `419-428`
- Original language: `powershell`
- Block SHA256: `9A281C8066831303BB2A7DB2493EFED2E54B9F9688BF3E7CF28A97C2BC4F7246`

```powershell
cd source-3/project-documentation
python .\tools\validator.py --mode file --file .\by-class\SayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\SayInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b1570-0x005b2562.SayTargetMessageInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SayToUserNameInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\NewSayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00630a18-0x00630a44.DirectWhisperPromptFragments.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
