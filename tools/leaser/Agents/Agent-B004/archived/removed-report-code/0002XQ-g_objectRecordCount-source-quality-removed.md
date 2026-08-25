<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002XQ-g_objectRecordCount-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002XQ-g_objectRecordCount-source-quality.md](0002XQ-g_objectRecordCount-source-quality.md)
- Source report SHA256 before cleanup: `A7A790E77EE733E12D3816CF243FE14C099E8638DD268A4BED248A55676ED7D2`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `302-312`
- Original language: `powershell`
- Block SHA256: `9A9175ED4DFF7101D17F3E2F77948425A3A1C7EA4A9A0F36526D43595E9EF257`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0069b4bc-0x0069b4c0.g_objectRecordCount.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_objectRecordCount.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005039f0-0x00504521.GameServerNationAndMapInit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_objectNationMap.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0069b4c0-0x0069b4c4.g_objectNationMap.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_gameServerNationTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00504110-0x00504521.MapPaneInitialize.md --apply --queue-timeout 240
```
