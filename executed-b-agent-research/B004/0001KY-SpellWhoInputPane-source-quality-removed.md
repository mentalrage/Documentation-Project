<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0001KY-SpellWhoInputPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KY-SpellWhoInputPane-source-quality.md](0001KY-SpellWhoInputPane-source-quality.md)
- Source report SHA256 before cleanup: `F582BE0B9A0ECEEF6A87A7E1DFE0F8A62202E59852DA33FD2B24E7E571988257`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `755-766`
- Original language: `powershell`
- Block SHA256: `ADE51D4339DE2288456646F95F18DE63E698727D7AD6C6A01BC70B4714DEDFC3`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/SpellWhoInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/TargetSelectionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005ae380-0x005ae403.SpellWhoInputPaneDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md --apply --queue-timeout 240
```
