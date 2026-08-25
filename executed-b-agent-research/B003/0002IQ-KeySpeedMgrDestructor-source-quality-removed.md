<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002IQ-KeySpeedMgrDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IQ-KeySpeedMgrDestructor-source-quality.md](0002IQ-KeySpeedMgrDestructor-source-quality.md)
- Source report SHA256 before cleanup: `852769FF94DAC8BB71BD22DF97AE52CB5F58626EF62D8531791C2814B778EBC3`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `496-510`
- Original language: `powershell`
- Block SHA256: `F3F862916D5B87F77E1CF88F68E606857D3DA935C55336EE1118E537BC3316EA`

```powershell
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004efee0-0x004efef5.KeySpeedMgrDestructor.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-class\KeySpeedMgr.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-file\KeySpeedMgr.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004efea0-0x004f0008.KeySpeedMgr.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-struct\KeySpeedMgrLayout.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\KeySpeedMgrVtable.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-global\g_pKeySpeedMgr.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md'
Get-Content -Raw -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004673c0-0x004673d1.DestroyKeySpeedMgr.md'
rg -n "0002IQ|004efee0|004efef5|KeySpeedMgrDestructor|004effc0" 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md' 'E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md' 'E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\by-memory-tool-report.md'
(Get-FileHash -Algorithm SHA256 -LiteralPath 'E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe').Hash
Get-Item -LiteralPath 'E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\NexusTK\input\KeySpeedMgr.cpp' | Select-Object FullName,Length,LastWriteTime | Format-List
```

## Removed Block R002

- Original source lines: `516-524`
- Original language: `powershell`
- Block SHA256: `E7DD0CCC347BA94F8D2504D4408ED48F4971752F9E693465E9B0E6B2B43238D4`

```powershell
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-memory\0x004efee0-0x004efef5.KeySpeedMgrDestructor.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-class\KeySpeedMgr.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-file\KeySpeedMgr.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-memory\0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-memory\-coverage-report.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode autogen
rg -n "0002IQ|004efee0|KeySpeedMgr::~KeySpeedMgr|g_pKeySpeedMgr = 0" 'E:\NTK\GhidraBridge\source-3\project-documentation'
```
