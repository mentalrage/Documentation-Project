<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md](0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md)
- Source report SHA256 before cleanup: `A734EA2E0033BF257C03DF8BF72522846E20357FFC233B2AA6675C6D7528FDF2`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `420-426`
- Original language: `powershell`
- Block SHA256: `B47E7FFA6EE58494802DEFDAC731026C436B84E73055DBC030BE5CBC78FB7FC6`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\MenuItem.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\MenuItemVtables.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen --apply
rg -n "0002JF|0x005172e0|MenuItemScalarDeletingDestructor" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md
```
