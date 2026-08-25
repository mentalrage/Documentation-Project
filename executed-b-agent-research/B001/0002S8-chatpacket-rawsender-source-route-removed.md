<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002S8-chatpacket-rawsender-source-route.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002S8-chatpacket-rawsender-source-route.md](0002S8-chatpacket-rawsender-source-route.md)
- Source report SHA256 before cleanup: `7CA1CF42606D459C66308B2DEF538CF8F86436B330FB3EF715912B92CD70C83E`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `248-250`
- Original language: `powershell`
- Block SHA256: `47197DBE5B9B5550A1A611DC38E3F06A95249280CDC3263A1C16B81DD9E43A78`

```powershell
git mv by-memory\0x005b37f0-0x005b38d5.ChatPacketRawSender.md by-memory\0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md
```

## Removed Block R002

- Original source lines: `362-374`
- Original language: `powershell`
- Block SHA256: `D0B3125358A68471499B07318984E73CD7EF39DEB23DCE33F07729D061995168`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\Chatting.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\ChatInputPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x005b3940-0x005b3bba.ChatInputPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x005b34d0-0x005b37ea.SayInputPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode autogen --apply --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
```
