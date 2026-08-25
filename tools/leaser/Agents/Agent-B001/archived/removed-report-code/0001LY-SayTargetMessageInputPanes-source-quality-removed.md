<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001LY-SayTargetMessageInputPanes-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001LY-SayTargetMessageInputPanes-source-quality.md](0001LY-SayTargetMessageInputPanes-source-quality.md)
- Source report SHA256 before cleanup: `7B6D3C78F97AFEFC3F635BD492378CD392A4EE66979E907F455793BC4CC404DE`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `670-682`
- Original language: `powershell`
- Block SHA256: `B94B6495E478304BE3B56E8BC1C05C3F11308A9ECBDB80781456D97E12CD9744`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x005b1570-0x005b2562.SayTargetMessageInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\SayInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\NewSayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SayToGroupMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SayToPlanMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x006309d0-0x006309dc.SayModeGroupClanPrefixFragments.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00630a44-0x00630a6c.GroupClanPromptFragments.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
