<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\0002J6-StringMenuItemConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002J6-StringMenuItemConstructor-source-quality.md](0002J6-StringMenuItemConstructor-source-quality.md)
- Source report SHA256 before cleanup: `56447CC0013998C89330FA6CB349F430DADB6D009AA4F942C2B53CBD7CB106C9`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `238-245`
- Original language: `powershell`
- Block SHA256: `0B7A59AE5D41DBA0BFF24EE88D2FF73D1E325BC995881BEF939CA66B683291AD`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-class/StringMenuItem.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-file/PopupMenuControls.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-type/by-struct/MenuItemLayouts.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
```

## Removed Block R002

- Original source lines: `249-251`
- Original language: `powershell`
- Block SHA256: `A139456A64563C942BCC2788137A0C7BB7A4F62FC6D0D0554D6113E54871E80C`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
```
