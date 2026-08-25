<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\000249-platform-string-conversion-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000249-platform-string-conversion-source-quality.md](000249-platform-string-conversion-source-quality.md)
- Source report SHA256 before cleanup: `F272F8F942142644EEEBF7B2AFD8EDCAF0A6335E369F01F071B7E59B6B0EF69D`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `266-278`
- Original language: `powershell`
- Block SHA256: `3852FB3252BFEEB662ED3476C25692FDC2D1EF6CAC06C69CCD2BD3376F7A5FEB`

```powershell
Get-Content tools/leaser/Agents/Agent-B002/goal.md
Get-Content tools/leaser/Agents/Agent-B002/notes.md
Get-Content tools/leaser/Agents/Supervisor.md
Get-Content by-structure.md
Get-Content inference_research.md
rg -n "000249|PlatformStringConversionHelpers|00599440|005994d0|00599550|00599570" tools/leaser/Agents/Agent-B001/research/executed tools/leaser/Agents/Agent-B002/research/executed tools/leaser/Agents/Agent-B003/research/executed
rg -n "000249|0001KE|0000WD|0x00599440|0x005995b0|0x0041a280" by-memory/-coverage-report.md auto-generated/-ag-memory-coverage.md
python tools/int_convert.py 0x68
python tools/int_convert.py 0x15
python tools/int_convert.py 0x73
python tools/int_convert.py 0x37
```

## Removed Block R002

- Original source lines: `294-301`
- Original language: `powershell`
- Block SHA256: `94A6DF2DFCE4BF8AD5CC288F7B29D45A5C833EECDEB0F96EC842E9636CF2BA09`

```powershell
python tools/validator.py --mode file --file by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md --apply
python tools/validator.py --mode file --file by-file/PlatformApi.md --apply
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
python tools/validator.py --mode autogen --apply
python tools/validator.py --mode rescore --apply --lock-timeout -1
python tools/memory_ranges.py report
```
