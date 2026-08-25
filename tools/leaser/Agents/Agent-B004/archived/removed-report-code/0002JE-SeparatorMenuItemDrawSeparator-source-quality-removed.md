<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002JE-SeparatorMenuItemDrawSeparator-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002JE-SeparatorMenuItemDrawSeparator-source-quality.md](0002JE-SeparatorMenuItemDrawSeparator-source-quality.md)
- Source report SHA256 before cleanup: `76D90DCF5654D03B48F48B96F63C58BF8C9508CCA0006AE9B367AF7BE0408BFD`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `365-370`
- Original language: `powershell`
- Block SHA256: `B19CA32626D7E0AB1C3A990EF2BFA44D244E626F75EBF652565DE2178090D204`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\SeparatorMenuItem.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\MenuItemVtables.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `374-382`
- Original language: `powershell`
- Block SHA256: `3F7813D09583A84764C55D11D973EF9BCDDE84218914AA0C2B3EAF5C0C8F8AEE`

```powershell
python .\tools\validator.py --mode file --file .\by-type\by-struct\MenuItemLayouts.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\PopupMenuControls.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MenuPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00516290-0x00517441.MenuPaneAndItems.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\SurfaceRenderCallbackTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0069b3e0-0x0069b424.SurfaceRenderCallbackTable.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `386-388`
- Original language: `powershell`
- Block SHA256: `EDBAAF6E1143005DA085ABE613272DF1C35A91FA9DE1C71B9DD2A2893045AD3F`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240
```
