<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality.md](0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality.md)
- Source report SHA256 before cleanup: `75DF1B18E2792C8FE81362F9E8F7D41C66DF0FE678DA653BF3BE46CBD04C98B4`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `701-709`
- Original language: `powershell`
- Block SHA256: `19B3EB7A0D584C48308253A7AED7148150367CE57CEA641F91B588C067A2A0FC`

```powershell
Set-Location 'E:\NTK\GhidraBridge\source-3\project-documentation'
python tools\validator.py --mode file --file by-memory\0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md
python tools\validator.py --mode file --file by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md
python tools\validator.py --mode file --file by-memory\0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md
python tools\validator.py --mode file --file by-memory\0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md
python tools\validator.py --mode file --file by-class\FittingRoomListPane.md
python tools\validator.py --mode file --file by-file\FittingRoom.md
```

## Removed Block R002

- Original source lines: `713-716`
- Original language: `powershell`
- Block SHA256: `25935808DC9FF4CECCE7C284AF82C422CF70D2698C8B440915558DBC1B16C67A`

```powershell
python tools\validator.py --mode autogen --apply
rg -n "0002DF|0002DL|0002DN|0002DQ" by-memory\-coverage-report.md
```
