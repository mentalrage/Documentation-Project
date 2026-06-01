*** UID:0000FH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserCreatePreviewControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserCreatePreviewControlPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)

## Class Purpose

`UserCreatePreviewControlPane` renders the final character preview in the older create-user dialog. It combines base body, face, hair, color, and gender fields into sprite-render parameters and supports direction cycling.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00501b40-0x00501bba` | Builds the preview control and seeds body/face/hair/gender state. |
| `BuildPreviewParams` | `0x00501bc0-0x00501c58` | Fills the packed sprite-render parameter structure. |
| `OnPaint` | `0x00501c60-0x00501d45` | Computes anchor/offset and draws the character preview sprite. |
| `AdvanceDirection` | `0x00501d50-0x00501d74` | Rotates the preview direction and refreshes. |
| `UpdatePreview` | `0x00501dc0-0x00501e05` | Updates face/hair/color/gender fields and refreshes. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks.md), `0x00502d10` | Adjustor thunks excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), plus reconstructable scalar deleting destructor. |

## Evidence Notes

- IDA confirms all listed starts.
- `xrefs_to 0x00501b40` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- `xrefs_to 0x00501d50` and `0x00501dc0` ties direction/update calls to `CreateUserDialogPane` command handling.
- IDA confirms `0x005025a8` and `0x005025b3` as real 0xb adjustor thunks; `0x005025b3` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502d10` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:0001AF][0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the preview rendering/update method map, constructor/caller xrefs, appearance-control file grouping, and adjustor-thunk/destructor evidence.
