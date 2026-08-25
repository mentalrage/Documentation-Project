<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001FH-npc-message-menu-question-source-split.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001FH-npc-message-menu-question-source-split.md](0001FH-npc-message-menu-question-source-split.md)
- Source report SHA256 before cleanup: `F2E3DBDABA85DC90EBF01FA9DCD3AE62DA7C9448ADA4597B018D255EB43F7EFB`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `330-342`
- Original language: `powershell`
- Block SHA256: `D2E75370143B1AF20CBC5C232FECADFC32E31DB57A3AFEEB19DE3534E8609298`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\MessageDialogs.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\MessageDialog.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\MenuQuestionDialog.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\MenuQuestionDialogLarger.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\MenuQuestionItemList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\MenuQuestionItemListLarger.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-ignored.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```
