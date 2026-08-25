<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0001CR-CreateUserDialogVariants-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001CR-CreateUserDialogVariants-source-quality.md](0001CR-CreateUserDialogVariants-source-quality.md)
- Source report SHA256 before cleanup: `D5AD2311D653DEEBD565ACD1BDF03B5CBF178B7B50696246159F3DD0DA5C5BEB`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `330-346`
- Original language: `powershell`
- Block SHA256: `AB7CE49113A9E7CDA987EE4093BE8F91EFEE17DC3E0EDD3267F522F8B00047F1`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/CreateUserDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/NewUserDialogPane2.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/NewCreateUserDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/CreateUserDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/NewUserDialogPane2.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/NewCreateUserDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/CreateUserDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_pNewUserDialogPane2.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_pNewCreateUserDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md --apply --queue-timeout 240
```
