<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0002ZK-HourPaneFrameTableTailConstants-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002ZK-HourPaneFrameTableTailConstants-source-routing.md](0002ZK-HourPaneFrameTableTailConstants-source-routing.md)
- Source report SHA256 before cleanup: `4844E16E61754A0B84F6E93BEFAF78C7A3C5132B500C07633BE1160F320B9040`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `188-191`
- Original language: `powershell`
- Block SHA256: `A0B024588E7DC408EA2A7D355B783D0D54EB3396DEC039D102558FEE4E63BEFD`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0066db1c-0x0066db3c.HourPaneFrameTableTailConstants.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `195-204`
- Original language: `powershell`
- Block SHA256: `3B64ED89D195CB262762738357B6611AB54FD7EE50D2FC86A6BCB24937C1CA1A`

```powershell
python .\tools\validator.py --mode file --file by-global\g_hourFrameTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\HourPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\HourPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-resource\hourpane-time-resources.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ImageLoaders.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\ImageDecodeJpegEoiMarker.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0066db04-0x0066db1c.HourPaneFrameTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md --apply --queue-timeout 240
```
