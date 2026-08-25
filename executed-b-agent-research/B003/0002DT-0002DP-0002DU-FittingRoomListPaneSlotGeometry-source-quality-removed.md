<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md](0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md)
- Source report SHA256 before cleanup: `A0A6B48E2BBBD2AA01CF1C01DC514AE4BF7624C79766B8C31DE3F4D227C39F22`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `723-732`
- Original language: `powershell`
- Block SHA256: `B35A29C1E2E861DA48A3BD67F6ADF9DA997D82E8E9702523A5FE1EF4172753C9`

```powershell
python tools\validator.py --mode file --file by-memory\0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md
python tools\validator.py --mode file --file by-memory\0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md
python tools\validator.py --mode file --file by-memory\0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md
python tools\validator.py --mode file --file by-class\FittingRoomListPane.md
python tools\validator.py --mode file --file by-file\FittingRoom.md
python tools\validator.py --mode file --file by-memory\0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md
python tools\validator.py --mode documented
python tools\validator.py --mode autogen
```

## Removed Block R002

- Original source lines: `736-739`
- Original language: `powershell`
- Block SHA256: `FD2AF796D94F568995F37559F36E1C96C70382916C3EA6E7BE9649530C2675E4`

```powershell
python tools\validator.py --mode documented --apply
python tools\validator.py --mode autogen --apply
```
