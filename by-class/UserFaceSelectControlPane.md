*** UID:0000FJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserFaceSelectControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserFaceSelectControlPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)

## Class Purpose

`UserFaceSelectControlPane` is the face thumbnail selector used by the older create-user dialog. It draws a two-row grid of face parts, handles mouse selection, and stores the selected face slot for the owning dialog.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00501660-0x00501783` | Builds the control, installs vtables, stores face/gender/set state, and seeds packed face-coordinate tables. |
| `OnMouseEvent` | `0x00501790-0x0050183a` | Handles press/release tracking and delegates selection to `SelectFaceAtPoint`. |
| `OnPaintFrame` | `0x00501840-0x00501a6a` | Draws the 6x2 face thumbnail grid and the selection frame. |
| `SelectFaceAtPoint` | `0x00501a70-0x00501af2` | Converts mouse coordinates to a selected face slot. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks.md), `0x00502d50` | Adjustor thunks excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), plus reconstructable scalar deleting destructor. |

## Evidence Notes

- IDA confirms all active method starts.
- `xrefs_to 0x00501660` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- Wave2 memory-report notes restored `0x00501a70` as the real `SelectFaceAtPoint` method after retiring a stale helper-class projection.
- IDA confirms `0x005025be` and `0x005025c9` as real 0xb adjustor thunks; `0x005025c9` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502d50` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:0001AF][0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the constructor/mouse/paint/select method map, create-user owner xrefs, restored `SelectFaceAtPoint` evidence, and adjustor-thunk/destructor references.
