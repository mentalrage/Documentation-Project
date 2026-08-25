<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\0002IB-HierListDefaultInsertWrapper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IB-HierListDefaultInsertWrapper-source-quality.md](0002IB-HierListDefaultInsertWrapper-source-quality.md)
- Source report SHA256 before cleanup: `605DAF204CA7B688ACD0819A06ABF6F3B62DACC2928A699B1CD223875F719FB1`
- Cleanup generated: `2026-08-11T12:47:19Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `275-281`
- Original language: `powershell`
- Block SHA256: `4F2745A93979DDCB3530F0C0901A6096C5BB07FF16843AA254F1D5ABED6A7C93`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ce860-0x004ce9ad.HierListInsertBefore.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `285-287`
- Original language: `powershell`
- Block SHA256: `4A00D9ACDFC9DAC5E819CF21851DB5CC6A2047B8E8740DF618DD7557C3ABB830`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md --apply --queue-timeout 240
```
