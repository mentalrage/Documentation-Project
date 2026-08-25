<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0001IH-SpellInventoryPanes-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001IH-SpellInventoryPanes-source-quality.md](0001IH-SpellInventoryPanes-source-quality.md)
- Source report SHA256 before cleanup: `0F90022A681519212836AD200F7A4BE9EE378E6388F006F74C6B86DE94F77642`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `385-402`
- Original language: `powershell`
- Block SHA256: `172714430F5085094865DA140953A80B4CF004143F832BA6C55C4D3E5DB15A51`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0057c2d0-0x0057f742.SpellInventoryPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\SpellInventoryPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\NewSpellInventoryPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SpellInventoryPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\NewSpellInventoryPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SpellInventoryPane2.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
python .\tools\validator.py --mode rescore --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `406-409`
- Original language: `powershell`
- Block SHA256: `8454FB38FA747AEF1C05EF26116663B69A99B1CC4FBC8DE351E2FBDE823F75E2`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0057c2d0-0x0057f742.SpellInventoryPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
