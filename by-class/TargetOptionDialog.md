*** UID:0000EE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TargetOptionDialog

## Status

- Confidence: strong for behavior and pairing with `TargetOptionEditControlPane`.
- Likely source file: [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- Main address doc: [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)
- Current recovered file: `source-3/simroot_v2/class_TargetOptionDialog.cpp`

## Functionality

`TargetOptionDialog` is a small configuration dialog for target-option settings. It creates two `TargetOptionEditControlPane` controls from config data, applies confirmed values back to the config table, saves user settings, and closes the dialog.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x00542270-0x0054248d` | Builds the dialog and child target-option edit controls. |
| confirm handler | `0x005424b0-0x00542534` | Reads child control values, writes config, saves settings, and closes. |
| config-save helper | `0x00542540-0x0054259f` | Raw helper that stores selected target-option control bytes into config offsets `0x2911dc` and `0x2911de`. |
| scalar deleting destructor | `0x00542a60-0x00542ab5` | Deleting destructor wrapper in [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md). |

## Evidence

IDA confirms the constructor is called from `MenuVarietySelectPane::HandleMenuMouseEvent`, and the edit-control constructor is called from this dialog at `0x005423dc`.

## Cross References

- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md)
- [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `86`.
- Evidence: the page documents dialog behavior, source ownership, constructor/confirm/config-save/destructor ranges, edit-control pairing, caller evidence, and corrected helper endpoint; remaining completion gap is source-ready C++ detail.
- What existed before: the page referenced the target dialog as `0x00542270-0x00542533` and only named the confirm handler plus scalar deleting destructor.
- What it was changed to: the main range is `0x00542270-0x0054259f`, with the confirm endpoint corrected and the raw config-save helper documented.
- Summary and evidence: IDA MCP review on 2026-05-28 showed `OnConfirm` ends at `0x00542534`, padding continues to `0x00542540`, and the helper through `0x0054259f` reads two child controls and writes their selected bytes into the target-option config block.
