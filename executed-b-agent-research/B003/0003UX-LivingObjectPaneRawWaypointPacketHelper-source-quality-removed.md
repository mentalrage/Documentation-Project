<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md](0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md)
- Source report SHA256 before cleanup: `9D0F22F2B3E84497E20B30D8F8F3EDE825F2DF220600CF8EC206DD8E3F7CEF4E`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `656-669`
- Original language: `powershell`
- Block SHA256: `83EA61A9C03EBB7B2ABA8DA8FF5FEB53A6B5A4840367F8F023ED5E63C958C9DE`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b83a0-0x005b83a7.UserPaneGetMapPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00574bb0-0x00574c13.QueueAndSendPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a7ec-0x0067a7f0.g_packetSender.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `673-678`
- Original language: `powershell`
- Block SHA256: `0344ED1E2BA5246D58F61BBAB1EEACB5FC725E77C5F5D9475CB6BB3E8D8DA170`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md --apply --queue-timeout 240
```
