<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0002NQ-ClanStringListPaneDrawItem-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002NQ-ClanStringListPaneDrawItem-source-quality.md](0002NQ-ClanStringListPaneDrawItem-source-quality.md)
- Source report SHA256 before cleanup: `5B62B9B80B5BA1C640ECC4D83706B0A31F121D02BB5A7916E49E8F4C210AA1BB`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `505-514`
- Original language: `powershell`
- Block SHA256: `A13AD13D1AD41C28822848F533DA90840BB583FCD45C601CE7AC712E9DB4CA2F`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ClanStringListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ClanJoinListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\ClanEnlistListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\Clan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00488610-0x004888f1.ClanListPaneVirtuals.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00615570-0x006158f4.ClanPaneListVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
