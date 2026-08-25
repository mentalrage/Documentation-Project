<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00023G-StaticObjectPaneSendInteractionPacket-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00023G-StaticObjectPaneSendInteractionPacket-source-quality.md](00023G-StaticObjectPaneSendInteractionPacket-source-quality.md)
- Source report SHA256 before cleanup: `2794C70DDD4A2597BAA07C122D2BA748B65CBFCD3D87CE9E49C2366FE2D7B0E8`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `392-398`
- Original language: `powershell`
- Block SHA256: `381B833670FB9F6A03ACBE43A2364CF7DBB668F1F836F2C1D9E8FA8CC0B15357`

```powershell
python tools/validator.py --mode file --file by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-class/StaticObjectPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file/StaticObjectPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `402-405`
- Original language: `powershell`
- Block SHA256: `C2F52687C7F0B6743DE5B61D89A350D9CACBC175923D82736EC5EC7154CA72DB`

```powershell
rg -n "leave formal C\\+\\+ blank|raw-start liveness|raw-start reachability|do-not-populate|FUN_00537ac0|sub_575380|sub_5753A0|dword_67A7EC|g_pPacketSender" by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md by-class/StaticObjectPane.md by-file/StaticObjectPane.md by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md
rg -n "UID:00023G|SendInteractionPacket" auto-generated/NexusTK/map/StaticObjectPane.cpp auto-generated/-ag-memory-coverage.md
```
