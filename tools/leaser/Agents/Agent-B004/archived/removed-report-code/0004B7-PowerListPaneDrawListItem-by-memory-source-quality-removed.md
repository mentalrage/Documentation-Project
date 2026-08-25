<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0004B7-PowerListPaneDrawListItem-by-memory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004B7-PowerListPaneDrawListItem-by-memory-source-quality.md](0004B7-PowerListPaneDrawListItem-by-memory-source-quality.md)
- Source report SHA256 before cleanup: `C0D236D679B9E340FD76F115307BC006A9E1BCA0F0C3C951BB535A6364773E5F`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `358-363`
- Original language: `powershell`
- Block SHA256: `45B550C69538F3A8F26DDE6983568B4C85A7D6DCD7D0BCB3F1CB219719E73314`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/PowerListPane.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/PowerDialogPane.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md --apply --wait-generated --queue-timeout 240
```
