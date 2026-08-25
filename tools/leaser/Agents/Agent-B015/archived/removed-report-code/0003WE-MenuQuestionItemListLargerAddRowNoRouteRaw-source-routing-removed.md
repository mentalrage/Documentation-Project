<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing.md](0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing.md)
- Source report SHA256 before cleanup: `77065A612371FB7365B062A553B2FE240E54F1DCBE6864D5230F026EB240F6D6`
- Cleanup generated: `2026-08-11T12:47:19Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `467-476`
- Original language: `powershell`
- Block SHA256: `17C3DB41A3D29430A83A5958FCFF1114B38E92F2A6173B0C9E7F42F762D7A0B3`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MenuQuestionItemListLarger.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MessageDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
