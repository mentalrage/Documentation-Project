<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002XS-g_gameServerNationTable-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002XS-g_gameServerNationTable-source-quality.md](0002XS-g_gameServerNationTable-source-quality.md)
- Source report SHA256 before cleanup: `5DC87E5E124B31808F8E60132BE092A7453FA176FE47020186E4B80A745E124B`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `291-295`
- Original language: `powershell`
- Block SHA256: `C35C1E70C0AF43659577C50B7A26280182A6371B6E62A51436CD767819A0A277`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_gameServerNationTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\GameServerConfig.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `299-304`
- Original language: `powershell`
- Block SHA256: `F83DF01709F7174CDA367AF0A70FBF00CD2ED0DE65EA037448E74ECB3E02ECD6`

```powershell
python .\tools\validator.py --mode file --file by-class\GameServerConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005039f0-0x00504521.GameServerNationAndMapInit.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00504110-0x00504521.MapPaneInitialize.md --apply --queue-timeout 240
```
