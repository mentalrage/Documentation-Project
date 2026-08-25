<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md](0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md)
- Source report SHA256 before cleanup: `47AE89C7AE116FEBEDFF9EC633BF649A32731634B00212729CAEEA833CE1D04C`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `508-516`
- Original language: `powershell`
- Block SHA256: `EC70EF51B94F5001D1B0B494CC878A73146F79DC9A4C3590B3FEB49AB8FEE892`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-class/SpellSlotInputPane.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-file/SpellInputPanes.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md" --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
rg -n "0003VX|0x005b14f0|SendSpellSlotPacket|SpellSlotDirectSlotPacketRaw" source-3/project-documentation/by-memory source-3/project-documentation/by-class/SpellSlotInputPane.md source-3/project-documentation/by-file/SpellInputPanes.md source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp source-3/project-documentation/project-level/-auto-completion-stats.md
```
