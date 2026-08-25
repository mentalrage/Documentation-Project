<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md](0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md)
- Source report SHA256 before cleanup: `DBE661265E2E8AA83B0312860A7B1E3D4F0FF27494A669957099444A9DCF8E10`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `528-541`
- Original language: `powershell`
- Block SHA256: `8BE84AA67F9FF9F13682003063DF2D396E7305CD9223B00F27C4B4850EF449A7`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b83a0-0x005b83a7.UserPaneGetMapPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240
```
