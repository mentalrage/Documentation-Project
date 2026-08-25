<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\00021G-SendClanJoinListSelectionPacket-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00021G-SendClanJoinListSelectionPacket-source-quality.md](00021G-SendClanJoinListSelectionPacket-source-quality.md)
- Source report SHA256 before cleanup: `AC310F584ACB1073B9E499F0058B1EFF8D0D18F032BB36FBE74E573C2839AE2F`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `339-350`
- Original language: `powershell`
- Block SHA256: `A3E243FA5CEF1C277EE9DAE72E75324B1480D4CC7A858B75E3367C5B3EA18C7C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00485590-0x00485682.SendClanJoinListSelectionPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanStatusPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Clan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanJoinListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00488900-0x00488b3d.ClanListPaneInputHandlers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00488610-0x004888f1.ClanListPaneVirtuals.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00485520-0x00485588.SendClanJoinListRefreshPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00487600-0x0048779f.ClanStatusRowActionPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `354-357`
- Original language: `powershell`
- Block SHA256: `CB1BA9568DC9E5588CA0E64441D098500921DB17E203F96BBA1D7E0F4C0FE97E`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-item\PacketBufferHelpers.md --apply --queue-timeout 240
```
