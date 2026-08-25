<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md](0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md)
- Source report SHA256 before cleanup: `C6360222F03B567244E6D3084C192FE97A3A1C372A47EA1DC1C70D40CA1B3988`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `310-319`
- Original language: `powershell`
- Block SHA256: `10D26605911A03FD3CFB19FAB6654612C206EE5FF6FB56783F628E7CC6E228D8`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\SelfLookPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\SelfLookPane.md --apply --queue-timeout 240 --wait-generated
```
