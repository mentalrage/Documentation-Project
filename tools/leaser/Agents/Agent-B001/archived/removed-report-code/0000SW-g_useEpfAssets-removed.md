<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000SW-g_useEpfAssets.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000SW-g_useEpfAssets.md](0000SW-g_useEpfAssets.md)
- Source report SHA256 before cleanup: `BFD7BD49257C6E857F7F61792B9773A9BA892B4F2CFE74138CBC63604E0352AE`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `141-154`
- Original language: `powershell`
- Block SHA256: `C6758279BE4D7B5A5FCB402F07D8DE4EA0608D09718018D7F8DBFBE5E7AEA0DC`

```powershell
$files = @(
  'by-global\g_useEpfAssets.md',
  'by-memory\0x0066da97-0x0066da98.g_useEpfAssets.md',
  'by-file\StartupWindow.md',
  'by-global\-coverage-report.md',
  'by-memory\-coverage-report.md'
)
foreach ($f in $files) {
  Write-Output "VALIDATOR $f"
  python .\tools\validator.py --mode file --file $f --apply --queue-timeout 180 --lock-timeout 60
  if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}
```
