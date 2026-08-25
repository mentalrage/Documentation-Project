<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md](0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md)
- Source report SHA256 before cleanup: `68BA45CB3C0DEB45F9509C6B35E14D99A192AAC37852EF6E0692CF8C88119DB3`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `379-392`
- Original language: `powershell`
- Block SHA256: `96F8F0400E6423F4A92EB02445D120B6AA5A64E66388742E2A073C9349E09259`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0053a110-0x0053d818.LivingObjectPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
