<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00016A-GrafPortDrawTiledBackground-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00016A-GrafPortDrawTiledBackground-source-quality.md](00016A-GrafPortDrawTiledBackground-source-quality.md)
- Source report SHA256 before cleanup: `45E1F952682BAA5E1A8CA894C01830C2012F6E0DAC6A038614DE6EFC778F1C0F`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `595-609`
- Original language: `powershell`
- Block SHA256: `BB2E2F8A9E5404C8D6F942709881BD146EBF55AF8C4CB47F59BC9058BDC300D4`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md --apply
python tools\validator.py --mode file --file by-class\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\GrafPort.md --apply
python tools\validator.py --mode file --file by-file\Surface.md --apply
python tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply
python tools\validator.py --mode file --file by-item\LoadFrameDrawRecord_004D1600.md --apply
python tools\validator.py --mode file --file by-memory\0x004d1600-0x004d165d.LoadFrameDrawRecord.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\validator.py --mode file --file by-class\-coverage-report.md --apply
python tools\validator.py --mode file --file by-file\-coverage-report.md --apply
python tools\validator.py --mode autogen --apply
python tools\validator.py --mode rescore --apply
```
