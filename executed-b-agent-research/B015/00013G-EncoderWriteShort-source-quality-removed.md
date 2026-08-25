<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\00013G-EncoderWriteShort-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00013G-EncoderWriteShort-source-quality.md](00013G-EncoderWriteShort-source-quality.md)
- Source report SHA256 before cleanup: `5211C1B023CC8ACF33FB750910B076F57DE5744CA051F8BFA15EE421B45D8AC7`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `518-521`
- Original language: `powershell`
- Block SHA256: `A81CC669039CE4A3CE9201095F7B5E7CD066D2F24347F39F6798F4DB459F9160`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
```

## Removed Block R002

- Original source lines: `525-528`
- Original language: `powershell`
- Block SHA256: `6AAD4109BFC0989E3AC4BDE3B0746269D32709ED5EF269A9CA1957767D2CCDAF`

```powershell
python tools/validator.py --mode file --file by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md --apply
python tools/validator.py --mode autogen --apply
```

## Removed Block R003

- Original source lines: `532-534`
- Original language: `powershell`
- Block SHA256: `0192192E5EAEE7D0F460D5D82EC98CEEDA6027194186729AA2793CB3EF58C000`

```powershell
rg -n "00013G|EncoderWriteShort|WriteShort" source-3/project-documentation/auto-generated/-ag-memory-coverage.md source-3/project-documentation/auto-generated/NexusTK/util/Encoder.cpp source-3/project-documentation/by-memory/-coverage-report.md
```
