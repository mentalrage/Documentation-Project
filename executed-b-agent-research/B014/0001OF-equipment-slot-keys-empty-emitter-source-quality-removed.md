<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0001OF-equipment-slot-keys-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001OF-equipment-slot-keys-empty-emitter-source-quality.md](0001OF-equipment-slot-keys-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `05848C67EDE0138C998D6AD86EFFCCB79D78931C0807E73787A333575E938555`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `321-327`
- Original language: `powershell`
- Block SHA256: `DA539A293CDDF8D21B3113706DB800BB806C1632DCFBF598C73494F6BF35016C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00630bd8-0x00630c06.g_equipmentSlotKeys.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-global\g_equipmentSlotKeys.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\TakeOffInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md --apply --queue-timeout 240
```
