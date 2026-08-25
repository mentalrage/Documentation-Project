<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality.md](0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality.md)
- Source report SHA256 before cleanup: `FB66E5B2015FD3A422949929EAB08E2ABF65851826D6C763A9E0A6679A87938C`
- Cleanup generated: `2026-08-11T14:26:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.


## Removed Block R001

- Source report SHA256 before this cleanup pass: `FB66E5B2015FD3A422949929EAB08E2ABF65851826D6C763A9E0A6679A87938C`
- Original source lines: `2235-2240`
- Original language: `text`
- Block SHA256: `48A1FDB658B9E217C15B8451BFA43D2B6D33190264E2BACEADC9DB83B9910DDC`

     ```text
     python .\tools\validator.py --mode file --file by-memory\0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\FittingRoomDialogItemState.md --apply --queue-timeout 240
     ```


## Removed Block R002

- Source report SHA256 before this cleanup pass: `FB66E5B2015FD3A422949929EAB08E2ABF65851826D6C763A9E0A6679A87938C`
- Original source lines: `2244-2282`
- Original language: `text`
- Block SHA256: `9AD86185E3E68964A7555AF1D7D65328CFD421940EA4929BC927319B702C4A69`

     ```text
     python .\tools\validator.py --mode file --file by-memory\0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00421fe0-0x0042201c.FittingRoomCatalogEntryPartLookup.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00422690-0x0042273e.ItemCatalogLookup.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\FittingEquipmentState.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\FittingRoomDialog.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\FittingRoomListPane.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\SimpleUString.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\StringUtil.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\Region.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\Region.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\ImageLib.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\ImageLib.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-global\g_pEPFLib.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-type\by-struct\ItemObjImageLibLayout.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\ItemObjImageLib.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\DialogPane.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\ObjectStatusBlob.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\ControlPane.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-type\by-struct\FittingEquipmentStateLayout.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423660-0x004236d7.FittingRoomCategoryLookupEraseNode.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-memory\0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md --apply --queue-timeout 240
     python .\tools\validator.py --mode file --file by-file\FittingRoom.md --apply --wait-generated --queue-timeout 240
     ```
