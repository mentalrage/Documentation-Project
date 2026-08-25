<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00015U-BuildFieldMapPath-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015U-BuildFieldMapPath-source-quality.md](00015U-BuildFieldMapPath-source-quality.md)
- Source report SHA256 before cleanup: `269D51B432A757810A711BD9B4A32A1AAFBB3F1D4F321954A974926C6CFC0E0C`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `646-660`
- Original language: `powershell`
- Block SHA256: `36FCE16E2BAF29FA8C651D7974C51734544F5EB8269A288E4BEB4CD2A54FCDE7`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004b8220-0x004b8284.BuildFieldMapPath.md --apply
python tools\validator.py --mode file --file by-memory\0x004b0bb0-0x004b129b.FieldMapPane.md --apply
python tools\validator.py --mode file --file by-class\FieldMapPane.md --apply
python tools\validator.py --mode file --file by-file\FieldMapPane.md --apply
python tools\validator.py --mode file --file by-memory\0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md --apply
python tools\validator.py --mode file --file by-memory\0x0061a44c-0x0061a458.SharedEpfSuffixString.md --apply
python tools\validator.py --mode file --file by-global\WideApiDispatchTable.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\validator.py --mode file --file by-class\-coverage-report.md --apply
python tools\validator.py --mode file --file by-file\-coverage-report.md --apply
python tools\validator.py --mode autogen --apply
python tools\validator.py --mode rescore --apply
```
