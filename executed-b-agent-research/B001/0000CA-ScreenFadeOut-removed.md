<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000CA-ScreenFadeOut.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000CA-ScreenFadeOut.md](0000CA-ScreenFadeOut.md)
- Source report SHA256 before cleanup: `21F3AA2F7D012FC23E4A88FF67CCF6929B656060EEC97F759B922A0CA77404BF`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `147-161`
- Original language: `powershell`
- Block SHA256: `40C6664ECB96D260C51567E94694A8F3F485C192EC135572A8EDC72B8E8F2870`

```powershell
$files = @(
  'by-file\ScreenFadeOut.md',
  'by-class\ScreenFadeOut.md',
  'by-file\ScreenDimmer.md',
  'by-type\by-struct\ScreenOverlayPaneLayouts.md',
  'by-project-structure\proposed-source-tree.md',
  'by-file\-coverage-report.md',
  'by-class\-coverage-report.md',
  'by-type\by-struct\-coverage-report.md'
)
foreach ($f in $files) {
  python .\tools\validator.py --mode file --file $f --apply --queue-timeout 180 --lock-timeout 60
}
```
