<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000271-WorldMapReadOnlyData.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000271-WorldMapReadOnlyData.md](000271-WorldMapReadOnlyData.md)
- Source report SHA256 before cleanup: `2AF2410E5F2D28A1404170F08F2460F988892D762D44F8F515B0BC7E4DF1D574`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `108-116`
- Original language: `powershell`
- Block SHA256: `DAAAE4F3790728D0EA251BD0E5014E09234477784C4448270DB98C181DE80BAA`

```powershell
foreach ($f in @(
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x006313fc-0x00631490.WorldMapPaneVtableData.md',
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00631490-0x00631528.WorldMapPaneResourceStrings.md',
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00631528-0x00631570.WorldMapPaneNumericConstants.md'
)) {
  python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file $f --apply
}
```

## Removed Block R002

- Original source lines: `122-133`
- Original language: `powershell`
- Block SHA256: `C0D13CD91FB599F0A9DA890EE2E7358CBED76D10A8B25A84EA1FCF8765E74FA7`

```powershell
foreach ($f in @(
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x006313fc-0x00631490.WorldMapPaneVtableData.md',
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00631490-0x00631528.WorldMapPaneResourceStrings.md',
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00631528-0x00631570.WorldMapPaneNumericConstants.md',
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x006313fc-0x00631570.WorldMapReadOnlyData.md',
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-class\WorldMapPane.md',
  'E:\NTK\GhidraBridge\source-3\project-documentation\by-class\-coverage-report.md'
)) {
  python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file $f --apply
}
```
