*** UID:0000FL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserHairSelectControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserHairSelectControlPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)

## Class Purpose

`UserHairSelectControlPane` is the hair thumbnail selector used by the older create-user dialog. It draws a two-row grid of hair parts, tracks mouse selection, and stores the selected hair slot for the owning dialog.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00501150-0x005012af` | Builds the control, installs vtables, seeds current hair/color/style state, and copies the packed hair-style table. |
| `OnMouseEvent` | `0x005012b0-0x0050135a` | Handles press/release tracking and delegates selection to `SelectHairAtPoint`. |
| `OnPaintFrame` | `0x00501360-0x0050158a` | Draws the 9x2 hair thumbnail grid and the selection frame. |
| `SelectHairAtPoint` | `0x00501590-0x00501612` | Converts mouse coordinates to a selected hair slot. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), `0x00502d90` | Adjustor thunks excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), plus reconstructable scalar deleting destructor. |

## Evidence Notes

- IDA confirms all active method starts.
- `xrefs_to 0x00501150` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- Wave2 memory-report notes also restored `0x00501590` as the real `SelectHairAtPoint` method after retiring a stale helper-class projection.
- IDA confirms `0x005025d4` and `0x005025df` as real 0xb adjustor thunks; `0x005025df` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502d90` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, mouse handler, paint method, hair-selection helper, adjustor thunks, and scalar deleting destructor at `0x00501150`, `0x005012b0`, `0x00501360`, `0x00501590`, `0x005025d4`, `0x005025df`, and `0x00502d90`; this page and parent [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the constructor/mouse/paint/select method map, create-user owner xrefs, restored `SelectHairAtPoint` evidence, and adjustor-thunk/destructor references.
