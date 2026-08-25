<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\00015E-FpsPaneDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015E-FpsPaneDestructor-source-quality.md](00015E-FpsPaneDestructor-source-quality.md)
- Source report SHA256 before cleanup: `72ED653EEBCE0DC8413C9CC0FA03035540B2161A4F1C2F806C5FE8116C105FD7`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `165-170`
- Original language: `powershell`
- Block SHA256: `D8FC4A97850EB551AB2E517769934A9DC3320D0429356D683E979A67A3AB2478`

```powershell
python source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x004b6470-0x004b6499.FpsPaneDestructor.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python source-3\project-documentation\tools\validator.py --mode autogen --apply
python source-3\project-documentation\tools\validator.py --mode rescore --apply
```
