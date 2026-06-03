*** UID:0000FK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserHairColorSelectListPane

## Status

- Confidence: strong for the swatch list, create-user ownership, and generic brush-helper exclusion.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserHairColorSelectListPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Autogen parent: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); C++ remains blank because the final class declaration/field layout is below the `95+` source gate.

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
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) is `86/80` with a validated `NexusTK/login/` path and lists both color-list panes as proposed source contents.
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) is `70/85`, now reconstructable, and attached to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); it records the `0x00501e10-0x005020c3` hair-color constructor/draw/selection span.
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) is attached to [UID:0000JR][GrafPort](by-file/GrafPort.md), so the previous brush-helper ownership uncertainty no longer blocks this class's create-user placement.

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
- 2026-06-03 autogen attachment pass:
  - Before: the page remained unparented at `80/74`, with confidence capped by generated brush-helper ownership.
  - Changed to: completion/confidence `82/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OX`.
  - Evidence: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) is `86/80`; [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) is `70/85` and attached to the same parent; [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) is separately attached to [UID:0000JR][GrafPort](by-file/GrafPort.md), resolving the stale generated helper-owner caveat for this class. C++ remains blank because the final class declaration and field names are not at the `95+` threshold.
