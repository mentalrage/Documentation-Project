<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md](0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md)
- Source report SHA256 before cleanup: `960473E367CCE9242B69313BD8C0F1E5A368446C55D78B0ECF0A0685FAF9D05D`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `278-288`
- Original language: `powershell`
- Block SHA256: `EE5890B6985382A2B8B71256B46F60F1EA8CEEF25A7F29925C0C1077C9FC57E9`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md --apply
python tools\validator.py --mode file --file by-memory\0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md --apply
python tools\validator.py --mode file --file by-memory\0x004b8bf0-0x004bb8c4.GrafPort.md --apply
python tools\validator.py --mode file --file by-file\Surface.md --apply
python tools\validator.py --mode file --file by-file\GrafPort.md --apply
python tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply
python tools\memory_ranges.py
rg -n "0003XE|0003XF|004bb2d5|004bb2d7|004bb5b0" by-memory -g "*.md"
```
