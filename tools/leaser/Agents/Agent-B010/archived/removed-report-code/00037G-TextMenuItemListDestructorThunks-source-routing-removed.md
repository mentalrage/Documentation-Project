<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\00037G-TextMenuItemListDestructorThunks-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00037G-TextMenuItemListDestructorThunks-source-routing.md](00037G-TextMenuItemListDestructorThunks-source-routing.md)
- Source report SHA256 before cleanup: `17050FBBA6BB7A9A2ED72FC4A56E3C96909187E8E42F9F55A047B755072D0EA8`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `233-240`
- Original language: `powershell`
- Block SHA256: `937B4455C3C14BDF1D9EF121DC11CAB58DD0593845B5D1FBD8579BF5734AD1DC`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TextMenuItemList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\TextMenuDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `244-248`
- Original language: `powershell`
- Block SHA256: `9BE07CF27EA0BA0A6712C2381DC341EB66F115759A68953EB2ADF3EAEEC1590F`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00520b55-0x00520b6b.TextMenuItemListDestructorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\TextMenuDialogVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\MerchantMenuDialogVtableFamily.md --apply --queue-timeout 240
```
