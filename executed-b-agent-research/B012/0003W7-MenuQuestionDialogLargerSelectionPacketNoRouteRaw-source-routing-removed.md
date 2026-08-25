<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing.md](0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing.md)
- Source report SHA256 before cleanup: `B8A3553429893F756B9097175F6DC7A16BD8EED9E0682B25972DECA4A26B556B`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `495-500`
- Original language: `powershell`
- Block SHA256: `83AA0B87A399D482312F698E9A54D1BFBC35BCF1397D9320D5C8D4FFF3216F4A`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-class\MenuQuestionDialogLarger.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-file\MessageDialogs.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md --apply
```

## Removed Block R002

- Original source lines: `504-506`
- Original language: `powershell`
- Block SHA256: `33EF4324EE2ACBD01BF88E27101D8387D97F414AFD2D75DCE96B4EBED868A455`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\-coverage-report.md --apply
```
