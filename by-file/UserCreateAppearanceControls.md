*** UID:0000OX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserCreateAppearanceControls

## Status

- Confidence: strong for the old create-user appearance controls, medium for exact original source split.
- Proposed module: `login/UserCreateAppearanceControls.cpp`, or a private section inside `login/CreateUserDialogPane.cpp`
- Current recovered sources: `class_UserShapeSelectControlPane.cpp`, `class_UserHairSelectControlPane.cpp`, `class_UserFaceSelectControlPane.cpp`, `class_UserCreatePreviewControlPane.cpp`, `class_UserHairColorSelectListPane.cpp`, and `class_UserFaceColorSelectListPane.cpp`
- Main memory doc: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Related support docs: [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md), [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md), and [UID:0000VN][-ignored](by-memory/-ignored.md)

## File Role

This file group owns the older create-user appearance widgets: body-shape preview buttons, hair and face thumbnail grids, the final character preview pane, and hair/face color swatch lists. The controls are tightly coupled to [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), `NewHumanImageLib`, sprite rendering, and palette lookup.

The controls could have lived in `CreateUserDialogPane.cpp` in the original codebase, but a split `UserCreateAppearanceControls.cpp` is a practical reconstruction candidate because the controls are reusable UI classes and `UserShapeSelectControlPane` is also referenced by newer/misc create-user flows.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserShapeSelectControlPane` | `0x004fcd80-0x004fd520`, helpers `0x00501620`, `0x00501640`, `0x0054b700`, destructor/thunks `0x005025ea`, `0x005025f5`, `0x00502dd0` | Body-shape selector/preview control with gender mode and active-state helpers. |
| `UserHairSelectControlPane` | `0x00501150-0x00501612`, destructor/thunks `0x005025d4`, `0x005025df`, `0x00502d90` | Hair thumbnail grid, mouse selection, paint, and selected-hair update. |
| `UserFaceSelectControlPane` | `0x00501660-0x00501af2`, destructor/thunks `0x005025be`, `0x005025c9`, `0x00502d50` | Face thumbnail grid, mouse selection, paint, and selected-face update. |
| `UserCreatePreviewControlPane` | `0x00501b40-0x00501e05`, destructor/thunks `0x005025a8`, `0x005025b3`, `0x00502d10` | Final character preview render pane and direction/update helpers. |
| `UserHairColorSelectListPane` | `0x00501e10-0x005020c3` | Hair-color swatch list that calls `CreateUserDialogPane::SetHairColorIndex`. |
| `UserFaceColorSelectListPane` | `0x005020d0-0x00502383` | Face-color swatch list that calls `CreateUserDialogPane::SetFaceColorIndex`. |

## Evidence Notes

- IDA MCP confirms every major function start listed above.
- 2026-06-01 IDA MCP resplit confirms the source-bearing `UserShapeSelectControlPane` constructor/method island is [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md); the neighboring `0x004fccf0-0x004fce7e` island is [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md), with only a small selected-state setter at `0x004fcd80` in that generic select-box owner.
- `xrefs_to` confirms `UserHairSelectControlPane`, `UserFaceSelectControlPane`, both color list constructors, and `UserCreatePreviewControlPane` are constructed by `CreateUserDialogPane::CreateUserDialogPane` at `0x0052dd30`.
- `xrefs_to 0x004fce80` also reports construction from the `NewUserMiscDialogPane` / `NewUserDialogPane2` area, so `UserShapeSelectControlPane` is a reusable create-user-family control rather than an inlined old-dialog-only helper.
- `xrefs_to 0x0052e930` and `0x0052e950` confirms the hair/face color lists call back into `CreateUserDialogPane::SetHairColorIndex` and `CreateUserDialogPane::SetFaceColorIndex`.

## Ownership Notes

- Keep this cluster with login/create-user UI, not generic controls. It depends on create-user state and human-image resources.
- The brush helpers [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) are currently emitted under `UserHairColorSelectListPane`, but IDA caller evidence is broader than this class. Treat those as generic draw-context/pane brush helpers until re-owned.
- The dense destructor/adjustor thunk area around [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md) and [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md) is compiler support for these controls and adjacent create-user panes; do not use the thunk pile as evidence for a separate source module. The adjustor range is excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md), while the scalar deleting destructors remain reconstructable.
- 2026-05-26 IDA MCP recheck confirms the appearance adjustor thunks as `this - 0xa0` / `this - 0xa4` destructor wrappers. The same pass reconfirmed `0x004b96a0` and `0x004b96b0` as broad draw-context brush helpers, not hair-color-list-owned methods.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md)
- [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md)
- [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)
- [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page already documents the appearance-control source role, likely class contents, IDA-backed constructor/vtable/resource evidence, ownership boundaries, and open source-split caveats, but exact original file split remains less than fully proven.
