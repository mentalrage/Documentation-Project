<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002MY-FolderTreeResetToSingleRoot-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002MY-FolderTreeResetToSingleRoot-empty-emitter-source-quality.md](0002MY-FolderTreeResetToSingleRoot-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `5F5ECA702237552C4247A344E2F3332B4D38DA75B5891DF018931B6DA65B54B5`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `447-457`
- Original language: `powershell`
- Block SHA256: `399521C1FD4080F5F2980BBDE58330904A2CF8B2C543910FF0959DD70EA14EBB`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\Tree_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TreeStorage_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\FolderTreePane__TreeElem.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-template\FolderTreePaneTreeTemplates.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1b90-0x004b32c9.FolderTreePaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md --apply --queue-timeout 240
```
