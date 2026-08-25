<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002H0-0002JV-application-lifecycle-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002H0-0002JV-application-lifecycle-source-quality.md](0002H0-0002JV-application-lifecycle-source-quality.md)
- Source report SHA256 before cleanup: `0ED1AFC1D98D1FEF9F487EAE271A9EED8F1BC1C4ABB1C9A65583CC4379D9C3A9`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `493-506`
- Original language: `powershell`
- Block SHA256: `86A838E58B1AAA6FBC9BD7BD710055BF788B2B06FC17C3BB49619344361540AE`

```powershell
python tools/validator.py --mode file --file by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-class/Application.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-file/Application.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-memory/-ignored.md --apply --lock-timeout -1
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1
python tools/memory_ranges.py report
python tools/validator.py --mode rescore --apply --lock-timeout -1
```
