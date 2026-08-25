<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md](00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `E948A3DC98C5BFC4D035BDCF1902C3C77C41FE1E60F7645E42EB29684CE72A06`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `317-323`
- Original language: `powershell`
- Block SHA256: `0DF35F9D435F552EB064AFC7D3E0CA7EC387BB27EA270C5A49D797E885C0E1FF`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ChangeItemSlotInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b3010-0x005b3196.ChangeItemSlotInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_packetSender.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `327-329`
- Original language: `powershell`
- Block SHA256: `82D8552D5FE5E61BB8B7B1A48670A79FF92A5CC43B9ADBD540ADE4934581B110`

```powershell
Select-String -Path auto-generated\NexusTK\ui\dialogs\ItemActionInputPanes.cpp -Pattern "00042U|SendChangeItemSlotPacket|Empty Emitter Marker" -Context 2,4
```
