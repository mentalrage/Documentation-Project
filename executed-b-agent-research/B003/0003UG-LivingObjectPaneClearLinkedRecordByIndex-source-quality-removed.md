<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality.md](0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality.md)
- Source report SHA256 before cleanup: `7AC61EF7CAA208F04FDDB68375F31A8793CF31DE9BC57988BEE58297D22996D6`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `606-608`
- Original language: `powershell`
- Block SHA256: `E496B9EA2C64BA901575FA8D67C9597854EA7BAF4F5C056560D14B92BC2804DE`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `620-630`
- Original language: `powershell`
- Block SHA256: `A40AA633EE8ED6EA6967032E845F82CB67BDB48461FC5068E08214DAD21575B6`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0053a110-0x0053d818.LivingObjectPaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `634-640`
- Original language: `powershell`
- Block SHA256: `9B0A2E2E7946223A811A08B9F4B29E9293EE7209772EC710764D2EA7585B56F9`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005a2530-0x005b8395.UserPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
```
