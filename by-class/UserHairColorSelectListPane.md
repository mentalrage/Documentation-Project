*** UID:0000FK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserHairColorSelectListPane

## Status

- Confidence: strong for the swatch list, low for the generated brush-helper ownership.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserHairColorSelectListPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)

## Class Purpose

`UserHairColorSelectListPane` is the hair-color swatch list in the older create-user dialog. It adds 16 color entries, draws color swatches, and forwards the selected color byte to `CreateUserDialogPane::SetHairColorIndex`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00501e10-0x00501f12` | Builds a 4-column `ListPane`, seeds the hair-color order, selects the first item, and applies it to the owner dialog. |
| `DrawListItem` | `0x00501f30-0x00502087` | Draws selected highlight and inset color swatch through palette lookup. |
| `OnSelectionChanged` | `0x00502090-0x005020c3` | Calls base selection behavior and forwards the selected color to `CreateUserDialogPane::SetHairColorIndex`. |
| Generated `GetBrushHandle` / `SetBrushHandle` | [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) | Current generated ownership is suspect; IDA shows broader drawing callers. |

## Evidence Notes

- IDA confirms the active list-method starts.
- `xrefs_to 0x00501e10` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- `xrefs_to 0x0052e930` reports calls from this constructor and `OnSelectionChanged`, confirming the owner callback.
- IDA direct callers for [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) include `BalloonObjectPane::PaintBubble`, `ColorStringChattingMessage::Draw`, and the face-color list draw method, so those helpers should not be treated as `UserHairColorSelectListPane` methods.

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:74`.
  - Summary/evidence: scored from constructor/draw/selection behavior, owner callback xrefs, create-user appearance grouping, and explicit evidence that generated brush-helper ownership is suspect.
