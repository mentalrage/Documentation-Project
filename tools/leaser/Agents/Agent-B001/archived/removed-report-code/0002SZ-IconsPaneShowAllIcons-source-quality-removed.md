<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002SZ-IconsPaneShowAllIcons-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002SZ-IconsPaneShowAllIcons-source-quality.md](0002SZ-IconsPaneShowAllIcons-source-quality.md)
- Source report SHA256 before cleanup: `C671DB3537118ECF94180098873C8E6D0D002030D6D2B81328B65AAF9432B95C`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `489-494`
- Original language: `powershell`
- Block SHA256: `A222A9ED22D3DEC3B29D2EA22C2C4457F98B6104FAE1EBCEF1024DA74D00807F`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/IconsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/IconsPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md --apply --queue-timeout 240
```
