<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\00037E-TextMenuDialogDestructorThunks-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00037E-TextMenuDialogDestructorThunks-source-routing.md](00037E-TextMenuDialogDestructorThunks-source-routing.md)
- Source report SHA256 before cleanup: `BC30C6B774EA618CCE48861AEE28BAD1758F3AD26907AB3927A1832C6B16B911`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `193-202`
- Original language: `powershell`
- Block SHA256: `80227C99B5148E34160E6F571DB72E4700C7F4FEDF0AD9A73B7F58B8A0567C80`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/TextMenuDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/TextMenuDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-vtable/TextMenuDialogVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `206-208`
- Original language: `powershell`
- Block SHA256: `E1E0EABBDCBC70DF5931C9EDBBB4103CDCBFD6EC80121A6F0C88F7F1591A6119`

```powershell
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240
```
