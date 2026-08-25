<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0002Q1-BaramAppDeletingDestructorThunk-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002Q1-BaramAppDeletingDestructorThunk-source-routing.md](0002Q1-BaramAppDeletingDestructorThunk-source-routing.md)
- Source report SHA256 before cleanup: `4469D80ADCA2218AE6DAA80492B2D30E6305EAA38F0F23F6DD052584B83FFBA7`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `317-327`
- Original language: `powershell`
- Block SHA256: `73A234EAF1D7E48351ADD538FE2381B95C110773F6D0335240F1747E2567E41A`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\BaramApp.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0061d118-0x0061d140.BaramAppVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0061d118-0x0061d264.BaramAppReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00463970-0x004639c4.ApplicationDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\-ignored.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
