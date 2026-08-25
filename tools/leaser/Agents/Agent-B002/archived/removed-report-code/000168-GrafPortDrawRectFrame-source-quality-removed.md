<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\000168-GrafPortDrawRectFrame-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000168-GrafPortDrawRectFrame-source-quality.md](000168-GrafPortDrawRectFrame-source-quality.md)
- Source report SHA256 before cleanup: `DA56BBB2F53B6C1242CCFCB978D955AF4CCD6E57EEB9F1C68A094299D79CA919`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `432-442`
- Original language: `powershell`
- Block SHA256: `C923B602E67AB446783D95977294D55173D1A4FE974F20F36FA7B83D615713A5`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md --apply
python tools\validator.py --mode file --file by-class\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\Surface.md --apply
python tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\validator.py --mode autogen --apply
python tools\validator.py --mode rescore --apply
```
