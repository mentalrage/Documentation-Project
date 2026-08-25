<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\000250-CollectionReadOnlyData-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000250-CollectionReadOnlyData-source-quality.md](000250-CollectionReadOnlyData-source-quality.md)
- Source report SHA256 before cleanup: `F46A313224328880B53857E36AF2238371D278ED5012415C9821A1D379964A3E`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `411-424`
- Original language: `powershell`
- Block SHA256: `D980631BFF4927102B72E941DE53E7804A508B08ABD28FF22D0CE2361695679F`

```powershell
Push-Location source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x006164f0-0x006168d0.CollectionReadOnlyData.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\CollectionDialogPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\CollectionDialogPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\CollectionEntryControlPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\CollectionBarControlPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0048c640-0x0048e305.CollectionDialogControls.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-resource\collection-ui-resources.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
Pop-Location
```
