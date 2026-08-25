<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00034J-FolderTreeIteratorScalarDeletingDestructor-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00034J-FolderTreeIteratorScalarDeletingDestructor-empty-emitter-source-quality.md](00034J-FolderTreeIteratorScalarDeletingDestructor-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `B2AB43A97FCD75C5768A38454CCD2DC4CF5997CFA17CED1AAA36B30241953BCE`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `304-308`
- Original language: `powershell`
- Block SHA256: `C28537B1010F01151EEF7EC1011FA7619F51D7E0B27206D0F61BAA88716A8AFD`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004b5a40-0x004b5a64.FolderTreeIteratorScalarDeletingDestructor.md --apply --wait-generated
python .\tools\validator.py --mode file --file by-class\TreeItor_struct_FolderTreePane__TreeElem_.md --apply --wait-generated
python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --wait-generated
```

## Removed Block R002

- Original source lines: `312-314`
- Original language: `powershell`
- Block SHA256: `7966D7BA3B1574EE1351105C434690EA1C8660F0AAC9BE701B5DB13F177C2D00`

```powershell
python .\tools\validator.py --mode file --file by-type\by-template\FolderTreePaneTreeTemplates.md --apply --wait-generated
```

## Removed Block R003

- Original source lines: `318-320`
- Original language: `powershell`
- Block SHA256: `7E1F439BBCD61571B5251C44AA819D08AA8675DAB8EB4AD55A9A2FCA89EA206A`

```powershell
rg -n "00034J|FolderTreeIteratorScalarDeletingDestructor|Empty Emitter Marker" auto-generated\NexusTK\ui\controls\FolderTreePane.cpp
```
