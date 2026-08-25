<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md](0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md)
- Source report SHA256 before cleanup: `5CAC9BEF22648559D0BC99541CC74A7AF8662C0ECD2B153AE5D52672BC5A0B67`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `386-392`
- Original language: `powershell`
- Block SHA256: `112EAD632FAC19BB4FF147BF29C0A5284A2D5DA6712C3E118974A5CC80BCE8BB`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `396-401`
- Original language: `powershell`
- Block SHA256: `2A2A2501ED761E30E77397B84A4E6BE68F49539E8466CAD288F1F2E75F250A7B`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md --apply --queue-timeout 240
```
