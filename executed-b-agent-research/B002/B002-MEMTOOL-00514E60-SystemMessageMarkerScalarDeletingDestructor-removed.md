<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor.md](B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor.md)
- Source report SHA256 before cleanup: `2C835257BA0B4347AB21C14BD4C7CBD65A6E9334B0E4D87A6E5696D0EED37AB5`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `174-178`
- Original language: `powershell`
- Block SHA256: `04AA21F3D16FB02D2E1FC87EEF07D828741535DFD4F9EC1CDF25813564D61FCC`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md --apply
python tools\memory_ranges.py report
```
