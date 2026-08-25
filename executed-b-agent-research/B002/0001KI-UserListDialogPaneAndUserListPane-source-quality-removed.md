<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001KI-UserListDialogPaneAndUserListPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KI-UserListDialogPaneAndUserListPane-source-quality.md](0001KI-UserListDialogPaneAndUserListPane-source-quality.md)
- Source report SHA256 before cleanup: `2290B209CBE772A7AFEA8CAAB1BE1B5F1A24CBB4877B99766A68C6872AB19C1B`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `831-833`
- Original language: `powershell`
- Block SHA256: `1DEC76CC1567AD748403C1399E144DC83E1C688B56520D9D1AEB905265D86C10`

```powershell
python .\tools\validator.py --mode file --file <relative-by-memory-path> --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `837-872`
- Original language: `powershell`
- Block SHA256: `B3CF7EFD5F46A0675DA334C214B6561C42811CF25F7A52FAB44054F976853BB3`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d198-0x0059d1e0.UserListDialogPaneConstructorCleanupTail.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d1e0-0x0059d1e3.UserListDialogPaneNullsub61.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d5fe-0x0059d620.UserListDialogPaneRefreshCategorySwitchTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandleUserListPacket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059d900-0x0059da82.UserListDialogPaneOnKeyEvent.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059dbe3-0x0059dc20.UserListDialogPaneOnControlCommandSwitchTable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059de60-0x0059decf.AddUserListSourceMessage.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e3a0-0x0059e3bf.PartySearchEditPaneCleanupHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e3c0-0x0059e3c1.PartySearchEditPaneOnDestroyChildControlsNoop.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e8a0-0x0059e943.UserListPaneDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e950-0x0059e983.CompareUserListRecordsByStatus.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e990-0x0059e9a6.CompareUserListRecordsByName.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e9b0-0x0059e9cf.UserListPaneSortByStatusNoRouteWrapper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e9d0-0x0059e9ef.UserListPaneSortByNameNoRouteWrapper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059e9f0-0x0059ea8f.SyncUserListSourceTextIntoBucket.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059ea90-0x0059ed18.UserListPaneDrawUserEntry.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059f0b0-0x0059f105.PartySearchEditPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059f110-0x0059f181.UserListDialogPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059f190-0x0059f25b.UserListPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `876-885`
- Original language: `powershell`
- Block SHA256: `4FC35A4DC791B5676E39EE7B8E9B08D8B14552FF6AF3ED7F34F308DD17984707`

```powershell
python .\tools\validator.py --mode file --file by-file/UserListDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/UserListDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/UserListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/PartySearchEditPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_bShowHuntersListOnly.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_pUserListDialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_useEpfAssets.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-enum/MapServerPacketOpcode.md --apply --queue-timeout 240
```
