<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0002J8-StringMenuItemMeasureText-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002J8-StringMenuItemMeasureText-source-quality.md](0002J8-StringMenuItemMeasureText-source-quality.md)
- Source report SHA256 before cleanup: `0AC21840E90D0BF1B789B023DBE32FCBBF8F2EE7E4EFFFC97A6ED350B23F254E`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `108-111`
- Original language: `powershell`
- Block SHA256: `83AD5057795DAD0EC4924F25618802F744E128D57C1CEC84F79A6D190B79C02F`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools/validator.py --mode file --file by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md --uid-only
```

## Removed Block R002

- Original source lines: `320-329`
- Original language: `powershell`
- Block SHA256: `69E370AE80BC389E0C1BB85E8B2ED7AA046BAE62B859BB6BE1E278884313A0A7`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools/validator.py --mode file --file by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md --apply
python tools/validator.py --mode file --file by-class/StringMenuItem.md --apply
python tools/validator.py --mode file --file by-type/by-struct/MenuItemLayouts.md --apply
python tools/validator.py --mode file --file by-type/by-vtable/MenuItemVtables.md --apply
python tools/validator.py --mode file --file by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md --apply
python tools/validator.py --mode file --file by-file/PopupMenuControls.md --apply
python tools/validator.py --mode autogen --apply
```
