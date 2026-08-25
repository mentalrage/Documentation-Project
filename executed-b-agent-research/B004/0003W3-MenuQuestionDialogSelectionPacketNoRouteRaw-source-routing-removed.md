<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0003W3-MenuQuestionDialogSelectionPacketNoRouteRaw-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003W3-MenuQuestionDialogSelectionPacketNoRouteRaw-source-routing.md](0003W3-MenuQuestionDialogSelectionPacketNoRouteRaw-source-routing.md)
- Source report SHA256 before cleanup: `AA07973FF6C02F3776EF93C7392623583145F41794FFB243800CA5CBEB306094`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `333-340`
- Original language: `powershell`
- Block SHA256: `2B63C8AE95B308B93A07EDA0F1C65A6F0F60FC89FEC3A65DAA46D0C0C775C756`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MenuQuestionDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\MessageDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md --apply --queue-timeout 240
```
