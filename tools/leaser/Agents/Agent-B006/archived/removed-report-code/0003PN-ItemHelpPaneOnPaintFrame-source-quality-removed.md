<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0003PN-ItemHelpPaneOnPaintFrame-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003PN-ItemHelpPaneOnPaintFrame-source-quality.md](0003PN-ItemHelpPaneOnPaintFrame-source-quality.md)
- Source report SHA256 before cleanup: `B5A1C6BA4AB3D151941D4B5F78F6F7CD736CB6CAA45A6BB1A2BBAF092AE723FF`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `603-612`
- Original language: `powershell`
- Block SHA256: `CE0719101C7D694492D82DE99EA17DE0C0F54D2BAB3E2FFFAF3742DE9F8605F4`

```powershell
python tools/validator.py --file by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md --apply --queue-timeout 240
python tools/validator.py --file by-class/ItemHelpPane.md --apply --queue-timeout 240
python tools/validator.py --file by-file/HelpPanes.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240
```
