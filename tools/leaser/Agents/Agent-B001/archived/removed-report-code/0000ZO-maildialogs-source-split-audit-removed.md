<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000ZO-maildialogs-source-split-audit.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000ZO-maildialogs-source-split-audit.md](0000ZO-maildialogs-source-split-audit.md)
- Source report SHA256 before cleanup: `DAE8393B67579F13D743E8B3FCD964B8CB6CC46FB27C4941DCC145D7039F6643`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `312-314`
- Original language: `powershell`
- Block SHA256: `6B6BD9B5F391EB49603E39DAA746DDCD11375E1B29ED35E11956D86D9E4060B6`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\<new-child>.md --apply --lock-timeout -1
```

## Removed Block R002

- Original source lines: `319-321`
- Original language: `powershell`
- Block SHA256: `924CEA4CE1E5C018963D1DA2C53D4EFF48297B2AA0C8F536E1780E8C52E80FA7`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --lock-timeout -1
```

## Removed Block R003

- Original source lines: `325-327`
- Original language: `powershell`
- Block SHA256: `8F3B0B95CD8246F1135B89B6F5A4C8D8A5D30CFEDA230A184A2B1EEC24660A0C`

```powershell
python .\tools\memory_ranges.py report
```
