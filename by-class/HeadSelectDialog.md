*** UID:000062 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HeadSelectDialog

## Status

- Confidence: strong for class responsibility and core boundaries, medium for shared helper ownership.
- Likely source file: [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)
- Main address range: [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md)
- Destructor-thunk detail: [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_HeadSelectDialog.cpp`

## Class Purpose

`HeadSelectDialog` is a packet-driven in-game dialog for selecting a character head/appearance variant. It parses object, NPC, price, and message fields from the packet; builds a dialog from EPF image, image-button, object-image, and static-text controls; shows the current character preview; and manages a ten-button paged head-selection grid.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00551030-0x005511fd` | `RefreshHeadPreview` | Rebuilds the object-image preview after the selected head changes. |
| `0x00551200-0x0055124d` | `UpdatePageButtonStates` | Enables or disables page navigation controls. |
| `0x00551350-0x00551510` | `PopulateHeadButtons` | Creates current-page [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) controls and applies selected highlighting. |
| `0x00551520-0x00551f25` | constructor | Parses packet data and constructs the initial dialog/control tree. |
| `0x00551f30-0x00551f91` | destructor | Dialog unregister and cleanup. |
| `0x00551fa0-0x005520e5` | `OnAction` | Handles close, page movement, and head-slot selection actions. |
| `0x005538fe-0x00553914` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Secondary/tertiary vtable thunk support. |
| `0x00553920-0x005539c3` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Deleting-destructor wrapper. |

## Key Relationships

- Uses [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md) for the current character/head preview.
- Uses [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) for the paged head-choice buttons.
- Uses [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md), [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md), and [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md) for the dialog background, actions, and packet-provided message text.
- Uses [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) head-count and head-offset data to clamp and preview selectable heads.

## Ownership Notes

The small helper at `0x0049dd00` is currently generated as `HeadSelectDialog::SwitchCategory`, but caller evidence crosses other dialog classes. Treat it as a shared dialog/control-list category switch rather than firm `HeadSelectDialog` ownership.

Adjacent IDA functions at `0x00552110`, `0x00553610`, and nearby starts install other dialog vtables and should not be included in this class by locality.

2026-05-25 recheck: IDA still shows `0x0049dd00` called from `0x0041cdc0`, twice from `0x0046e2a0`, and from `HeadSelectDialog::PopulateHeadButtons` at `0x00551350`. Current simroot still emits the helper under `HeadSelectDialog`, so preserve the shared-helper caveat.

## Cross-References

- [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)
- [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md)
- [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md)
- [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)

## Changes

- Before: `HeadSelectDialogCore` and `OnAction` ended at `0x005520e4`.
- Changed to: both end at `0x005520e5`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old endpoint omitted the final `retn 8` operand byte.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: packet-driven dialog responsibility, method families, control relationships, shared-helper caveat, adjacent non-owned functions, and corrected boundary evidence are documented in detail; confidence remains limited by shared helper ownership. Evidence: `HeadSelectDialogCore`, `HeadSelectDialogDestructorThunks`, `DialogCategorySwitch`, object-image control relationships, and NewHumanImageLib source-file references.
