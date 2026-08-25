<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00000B-alertpane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00000B-alertpane-source-quality.md](00000B-alertpane-source-quality.md)
- Source report SHA256 before cleanup: `775B0DB45E0DAD755AFC7957DDB1A820C90A30C7E53980A105506E62CDAEAB95`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `448-462`
- Original language: `powershell`
- Block SHA256: `0002559B0E693B9B59CE71135B02D3067FE619F9B2C01B8D05A9907C2EA0134E`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation

python .\tools\validator.py --file .\by-class\AlertPane.md --lock-timeout -1
python .\tools\validator.py --file .\by-memory\0x0049feb0-0x004a0686.AlertPaneCore.md --lock-timeout -1
python .\tools\validator.py --file .\by-memory\0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md --lock-timeout -1
python .\tools\validator.py --file .\by-memory\0x00618b00-0x00618ba0.AlertPaneVtableData.md --lock-timeout -1
python .\tools\validator.py --file .\by-type\by-vtable\AlertPaneVtables.md --lock-timeout -1
python .\tools\validator.py --file .\by-type\by-struct\AlertPaneLayout.md --lock-timeout -1
python .\tools\validator.py --file .\by-file\AlertPanes.md --lock-timeout -1
python .\tools\validator.py --file .\by-class\-coverage-report.md --lock-timeout -1
python .\tools\validator.py --file .\by-memory\-coverage-report.md --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
```
