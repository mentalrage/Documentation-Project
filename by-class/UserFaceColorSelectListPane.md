*** UID:0000FI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserFaceColorSelectListPane

## Status

- Confidence: strong for the swatch list, create-user ownership, and generic brush-helper exclusion.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserFaceColorSelectListPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Autogen parent: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); C++ remains blank because the final class declaration/field layout is below the `95+` source gate.

## Class Purpose

`UserFaceColorSelectListPane` is the face-color swatch list in the older create-user dialog. It adds 16 color entries, draws color swatches, and forwards the selected color byte to `CreateUserDialogPane::SetFaceColorIndex`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005020d0-0x005021d2` | Builds a 4-column `ListPane`, seeds the face-color order, selects the first item, and applies it to the owner dialog. |
| `OnPaintItem` | `0x005021f0-0x00502347` | Draws selected highlight and inset color swatch through palette lookup. |
| `OnSelectionChanged` | `0x00502350-0x00502383` | Calls base selection behavior and forwards the selected color to `CreateUserDialogPane::SetFaceColorIndex`. |
| Brush-state helper calls | [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) | `OnPaintItem` calls the same generic brush-state helpers used by hair swatches, balloon drawing, and chat-message drawing. |

## Evidence Notes

- IDA confirms all listed starts.
- `xrefs_to 0x005020d0` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- `xrefs_to 0x0052e950` reports calls from this constructor and `OnSelectionChanged`, confirming the owner callback.
- IDA direct callers for [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) show the brush helpers are generic draw-state helpers rather than face/hair color-list-owned methods.
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) is `86/80` with a validated `NexusTK/login/` path and lists both color-list panes as proposed source contents.
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) is `70/85`, now reconstructable, and attached to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); it records the `0x005020d0-0x00502383` face-color constructor/paint/selection span.
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) is attached to [UID:0000JR][GrafPort](by-file/GrafPort.md), so the previous brush-helper ownership uncertainty no longer blocks this class's create-user placement.

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:74`.
  - Summary/evidence: scored from constructor/paint/selection behavior, owner callback xrefs, swatch-list role, and generic brush-helper evidence; confidence remains lower because inherited/generated brush-helper ownership is explicitly unresolved.
- 2026-06-03 autogen attachment pass:
  - Before: the page remained unparented at `80/74`, with confidence capped by generated brush-helper ownership.
  - Changed to: completion/confidence `82/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OX`.
  - Evidence: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) is `86/80`; [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) is `70/85` and attached to the same parent; [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) is separately attached to [UID:0000JR][GrafPort](by-file/GrafPort.md), resolving the stale generated helper-owner caveat for this class. C++ remains blank because the final class declaration and field names are not at the `95+` threshold.
