<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality.md](0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality.md)
- Source report SHA256 before cleanup: `7F8AC25D46BF152CC701DAFA36A0F6785809A5935FA241357D5BB2EA7B859814`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `582-592`
- Original language: `powershell`
- Block SHA256: `00FC948FD814482595D68F9D2680769B9814B4B8CD0D5AC9A39E1A8D93331F4F`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation\tools
python validator.py --mode file --file ..\by-memory\0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md --apply
python validator.py --mode file --file ..\by-memory\0x00563260-0x0056470c.ScrollInventoryPane.md --apply
python validator.py --mode file --file ..\by-memory\0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md --apply
python validator.py --mode file --file ..\by-class\ScrollInventoryPane.md --apply
python validator.py --mode file --file ..\by-file\InventoryScrollPane.md --apply
python validator.py --mode file --file ..\by-type\by-struct\ScrollInventoryPaneLayout.md --apply
python validator.py --mode file --file ..\by-memory\-coverage-report.md --apply
python validator.py --mode autogen --apply
```

## Removed Block R002

- Original source lines: `596-600`
- Original language: `powershell`
- Block SHA256: `0A7ECCA54AA917C1283C54F246A112E67256DFF747BC49ECD35567EA7CC9B86F`

```powershell
Select-String -Path E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md -Pattern 'ResetScrollState|0x005646b0|0x00597600|0x005640a0|\+0x103|\+0x104|\+0xa4|95/95|0000CK|0000KB'
Select-String -Path E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md -Pattern '0001GZ|0001H0|0001H1'
Select-String -Path E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ScrollInventoryPane.md,E:\NTK\GhidraBridge\source-3\project-documentation\by-file\InventoryScrollPane.md,E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-struct\ScrollInventoryPaneLayout.md -Pattern 'ResetScrollState|\+0x103|\+0x104|\+0xa4|95/95'
```
