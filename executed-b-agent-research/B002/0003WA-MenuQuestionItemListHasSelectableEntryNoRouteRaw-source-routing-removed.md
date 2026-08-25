<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing.md](0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing.md)
- Source report SHA256 before cleanup: `3C6008D57D34A760BCEC28914A5762FD5C5D886FCA890054D4758AC26FD748E8`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `303-309`
- Original language: `powershell`
- Block SHA256: `D1884BB978442AEB3013B36CABA48779226780E1004329A9190DB1188EEB659E`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MenuQuestionItemList.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MenuQuestionDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\MessageDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `313-320`
- Original language: `powershell`
- Block SHA256: `FEB95B8B426C75FB122EEFB2EB7447D1C25D3AC69F576FC041DBABD4B3010CCD`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MenuQuestionItemListLarger.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\MenuQuestionDialogLarger.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md --apply --queue-timeout 240
```
