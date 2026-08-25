<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001M1-TakeOffInputPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001M1-TakeOffInputPane-source-quality.md](0001M1-TakeOffInputPane-source-quality.md)
- Source report SHA256 before cleanup: `780473B5DA72B7C2746E321B56E5A6E761F55A4547284320D214D917D45A0431`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `750-756`
- Original language: `powershell`
- Block SHA256: `600035039DF67B0649D2268B88477D1AE5B2164B2DE2316C7A5C4AF0403389D3`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b2720-0x005b296b.TakeOffInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TakeOffInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b27c0-0x005b2827.SendTakeOffPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md --apply --queue-timeout 240
```
