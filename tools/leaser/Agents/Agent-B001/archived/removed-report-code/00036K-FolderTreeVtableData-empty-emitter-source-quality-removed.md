<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00036K-FolderTreeVtableData-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00036K-FolderTreeVtableData-empty-emitter-source-quality.md](00036K-FolderTreeVtableData-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `15BE0C60F28A7A7331BA677BC3CF9E084AF76A90A846AAC419F9B5CD0551C626`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `289-296`
- Original language: `powershell`
- Block SHA256: `A52982F39F23E4EFB773AE481C2456A568F80251A13782FD255FEC343991D448`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0061a4fc-0x0061a50c.FolderTreeVtableData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-type\by-vtable\FolderTreePaneTreeVtable.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-type\by-vtable\FolderTreePaneVtables.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\Tree_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `300-302`
- Original language: `powershell`
- Block SHA256: `0BD56913CBCB9877D561D88B3B93C0F0D14CE268439B47509E99842631BB7EA9`

```powershell
rg -n "validator-command-id|validator-refreshed-at|UID:00036K|UID:00036J|Empty Emitter Marker" auto-generated\NexusTK\ui\controls\FolderTreePane.cpp
```
