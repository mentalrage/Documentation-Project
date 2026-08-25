<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00026K-startupwindow-rdata-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00026K-startupwindow-rdata-source-quality.md](00026K-startupwindow-rdata-source-quality.md)
- Source report SHA256 before cleanup: `C2DC5CE9D68CE1F2C945A2E8B3C6B7D68DDDB756246850159469E66E4B04A12B`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `382-397`
- Original language: `powershell`
- Block SHA256: `347BAC499D4B6C76A771F26F50E2A90C8ECEA3AD7E325A1FB098F132AED09ABC`

```powershell
$root = 'E:\NTK\GhidraBridge\source-3\project-documentation'
python "$root\tools\validator.py" --mode file --file "by-memory\0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-file\StartupWindow.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-class\StartupWindow.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\0x005807d0-0x0058206e.StartupWindowUpdateCheck.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-resource\startup-update-notice-resources.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\0x00670260-0x00670268.StartupWindowNoticePointerData.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\-coverage-report.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode documented --remove-missing --apply --lock-timeout -1
python "$root\tools\validator.py" --mode autogen --apply --lock-timeout -1
python "$root\tools\validator.py" --mode rescore --apply --lock-timeout -1
python "$root\tools\memory_ranges.py" report
```
