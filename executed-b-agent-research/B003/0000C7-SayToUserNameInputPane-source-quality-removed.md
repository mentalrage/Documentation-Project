<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0000C7-SayToUserNameInputPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000C7-SayToUserNameInputPane-source-quality.md](0000C7-SayToUserNameInputPane-source-quality.md)
- Source report SHA256 before cleanup: `598B89EDDB71E804388770E23570F9C92B691AA44C02108278D3B2FDA55CA15E`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `476-486`
- Original language: `powershell`
- Block SHA256: `00D817FF0FC332DA22E35478687FB26C97633ECAD19F24C0FB6DCAE9A221EB72`

```powershell
cd source-3/project-documentation
python .\tools\validator.py --mode file --file .\by-class\SayToUserNameInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b3cb0-0x005b4219.SayToUserNameInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\SayInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\LineInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\NewSayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
