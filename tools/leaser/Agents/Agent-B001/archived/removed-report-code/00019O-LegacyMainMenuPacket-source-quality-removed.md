<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00019O-LegacyMainMenuPacket-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00019O-LegacyMainMenuPacket-source-quality.md](00019O-LegacyMainMenuPacket-source-quality.md)
- Source report SHA256 before cleanup: `275BEC00828D93F43C95E474D7A0304E87A3CF7BEDC0A2A56E38F8511909417B`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `200-211`
- Original language: `powershell`
- Block SHA256: `7E8A65994676F91D626325853475F18C59C048C4B9249D82069CA456486B82DD`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\HandleLegacyMainMenuPacket_4F8D00.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MainMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MainMenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Socket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Socket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00575d90-0x005797ae.SocketTransportCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
