<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\000160-00022M-grafport-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000160-00022M-grafport-source-quality.md](000160-00022M-grafport-source-quality.md)
- Source report SHA256 before cleanup: `DF075EC750B358FE02D62E3A8032536D3498E10829962FC61D807353185D8423`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `180-210`
- Original language: `powershell`
- Block SHA256: `285342FE7FF7D9315A0D1A6DD8B1EBE32D37A46149034723F2E69B9D29DD9DD8`

```powershell
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004b8bf0-0x004bb8c4.GrafPort.md --apply

$files = @(
 'by-memory\0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md',
 'by-memory\0x004b8bf0-0x004bb8c4.GrafPort.md',
 'by-memory\0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md',
 'by-memory\0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md',
 'by-memory\0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md',
 'by-memory\0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw.md',
 'by-memory\0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md',
 'by-class\GrafPort.md',
 'by-file\GrafPort.md',
 'by-file\NumericStringControlPane.md'
)
foreach ($f in $files) {
  python source-3\project-documentation\tools\validator.py --mode file --file $f --apply
}

rg -n "Open Questions|open question|unresolved|provisional|split recommended|future work|TODO|TBD|cannot safely|blank pending|historical caveat|source-layout caveats" `
  source-3\project-documentation\by-memory\0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md `
  source-3\project-documentation\by-memory\0x004b8bf0-0x004bb8c4.GrafPort.md `
  source-3\project-documentation\by-memory\0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md `
  source-3\project-documentation\by-memory\0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md `
  source-3\project-documentation\by-memory\0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md `
  source-3\project-documentation\by-memory\0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw.md `
  source-3\project-documentation\by-memory\0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md `
  source-3\project-documentation\by-class\GrafPort.md `
  source-3\project-documentation\by-file\GrafPort.md `
  source-3\project-documentation\by-file\NumericStringControlPane.md
```
