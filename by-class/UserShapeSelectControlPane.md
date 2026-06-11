*** UID:0000FR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserShapeSelectControlPane

## Status

- Confidence: strong for local behavior, medium for final source split.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserShapeSelectControlPane.cpp`
- Primary ranges: [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md) and [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)

## Class Purpose

`UserShapeSelectControlPane` is a body-shape preview/selection control used by create-user dialogs. It stores male/female sprite tables, selected shape, direction/frame state, visibility/active flags, and draws a centered body preview through the sprite library.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetSelectionValue` | `0x004fcd80-0x004fcda4` | Stores a selected option value and refreshes when it changes. |
| constructor | `0x004fce80-0x004fcfb5` | Builds the control, starts animation timer, and seeds male/female sprite id tables. |
| `BuildSpriteDescriptor` | `0x004fcfc0-0x004fd02a` | Builds the sprite render descriptor for the current shape/gender. |
| `SetMaleSprite` / `SetFemaleSprite` | `0x004fd030`, `0x004fd050` | Switches sprite gender mode and refreshes. |
| `AdvanceShapeForward` / `AdvanceShapeBackward` | `0x004fd070`, `0x004fd0d0` | Cycles shape index with edge return values. |
| `SetShapeVisible` | `0x004fd140-0x004fd164` | Toggles visibility and refreshes. |
| `OnTimer` | `0x004fd170-0x004fd1de` | Advances animation frame/direction and restarts the timer. |
| `HandleMouseEnter` | `0x004fd1e0-0x004fd228` | Tracks hover state and invalidates on entry. |
| `OnPaint` | `0x004fd230-0x004fd520` | Draws the optional frame and current body sprite. |
| `SetMaleMode` / `SetFemaleMode` | `0x00501620`, `0x00501640` | Sets selected gender option and refreshes. |
| `SetActive` | `0x0054b700-0x0054b719` | Stores active state and refreshes; shared by several create-user paths. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), `0x00502dd0` | Adjustor thunks excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), plus reconstructable scalar deleting destructor. |

## Evidence Notes

- IDA MCP confirms all listed starts.
- `xrefs_to 0x004fce80` reports constructor calls from `NewUserMiscDialogPane` / `NewUserDialogPane2` areas, so this class is reusable within the create-user family.
- `xrefs_to 0x0054b700` has broad create-user-family callers; keep the helper with this control until a lower-level base-control owner is proven.
- IDA confirms `0x005025ea` and `0x005025f5` as real 0xb adjustor thunks; `0x005025f5` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502dd0` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)

## Changes

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the selector, constructor, sprite/shape/timer/paint helpers, shared active-state helper, adjustor thunks, and scalar deleting destructor starts from `0x004fcd80` through `0x00502dd0`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the body-shape selector method map, constructor xrefs, timer/paint/sprite behavior, create-user-family reuse notes, and adjustor-thunk/destructor evidence; confidence remains moderate on the final source split and shared `SetActive` ownership.
