<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002J7-StringMenuItemCopyText-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002J7-StringMenuItemCopyText-source-quality.md](0002J7-StringMenuItemCopyText-source-quality.md)
- Source report SHA256 before cleanup: `4A992A3A0B68DCD39A583CC2AE6C05FBCEF46C982B4B27CB8BD67B443AAEF8E3`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `485-491`
- Original language: `powershell`
- Block SHA256: `07BD83EFCB0FE9B2C56113ADC1F4FB94681FB441AD4A9A46C83CC97BD09795C5`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00517070-0x00517089.StringMenuItemCopyText.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\StringMenuItem.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\PopupMenuControls.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00516290-0x00517441.MenuPaneAndItems.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\MenuItemVtables.md --apply --queue-timeout 240
```
