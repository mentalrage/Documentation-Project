<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001BO-ItemMenuDialogs-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001BO-ItemMenuDialogs-source-quality.md](0001BO-ItemMenuDialogs-source-quality.md)
- Source report SHA256 before cleanup: `13DB700F2D0B1A87BB931F8B67F1F83C962D914ADAF83A1EEEAF46E4149E2F30`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `422-432`
- Original language: `powershell`
- Block SHA256: `29468F8DEC3237145F9B1CEE13453AB58AC06E82B45D4D00AE8B65F23029CC64`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/ServerItemMenuDialog.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/ServerItemMenuItemList.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/ClientItemMenuDialog.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/ClientItemMenuItemList.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/ItemMenuDialogs.md --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
```
