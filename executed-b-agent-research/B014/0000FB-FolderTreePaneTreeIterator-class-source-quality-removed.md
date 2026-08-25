<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0000FB-FolderTreePaneTreeIterator-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000FB-FolderTreePaneTreeIterator-class-source-quality.md](0000FB-FolderTreePaneTreeIterator-class-source-quality.md)
- Source report SHA256 before cleanup: `D8D591F1D0A7B57EF9D7DBA023CCE7DD7B9DC0610A3215E8DF33EBA384287A22`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `770-772`
- Original language: `powershell`
- Block SHA256: `129FED19663B3EF98C7CE0CC3CB7AE191C964A9DB925C580C3608FF826986385`

```powershell
python .\tools\validator.py --mode file --file .\by-class\TreeItor_struct_FolderTreePane__TreeElem_.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `790-798`
- Original language: `powershell`
- Block SHA256: `E74D7ED0ADA9CFD861CF051AFB76F567B807F92630131838319E37056DD3B24A`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-class\TreeItor_struct_FolderTreePane__TreeElem_.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-template\FolderTreePaneTreeTemplates.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\FolderTreePane__TreeElem.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md --queue-timeout 240
```

## Removed Block R003

- Original source lines: `802-807`
- Original language: `powershell`
- Block SHA256: `D003958F9E0958A0E3B86DBBA8FBBA2CFFC0294370A3941E2B582040FF3B0E51`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\FolderTreePaneTreeItorVtable.md --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md --queue-timeout 240
```
