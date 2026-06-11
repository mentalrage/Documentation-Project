*** UID:0000EE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TargetOptionDialog

## Status

- Confidence: strong for behavior and pairing with `TargetOptionEditControlPane`.
- Likely source file: [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- Main address doc: [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)

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

- Live IDA confirms the dialog constructor at `0x00542270` is `0x21e` bytes and is called from `MenuVarietySelectPane::HandleMenuMouseEvent` at `0x005bd17c`.
- The dialog constructor calls `TargetOptionEditControlPane::TargetOptionEditControlPane` at `0x005423dc`, along with the expected dialog/control setup helpers.
- The config-save span at `0x00542540-0x0054259f` is not modeled as a function start; existing live review ties it to reading child controls 2 and 3 and writing selected bytes into config offsets `0x2911dc` and `0x2911de`.
- The scalar deleting destructor at `0x00542a60-0x00542ab4` is vtable/adjustor-thunk reached, with thunk refs at `0x0054266b` and `0x00542676` plus a vtable data ref at `0x006211cc`.
- Final C++ is intentionally blank because the class remains below the 95/95 reconstruction-code threshold.

## Cross References

- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md)
- [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- 2026-06-05 A004 live refresh:
  - Before: the page still carried recovered-source provenance and summarized older IDA evidence.
  - After: raised from `84/86` to `86/88`, kept parent [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md), removed generated-source provenance, and kept final C++ blank.
  - Evidence: live IDA confirms the constructor size and caller, edit-control constructor call, raw non-function config-save helper status, scalar deleting destructor refs, and source-file parent eligibility.
- What existed before: the page referenced the target dialog as `0x00542270-0x00542533` and only named the confirm handler plus scalar deleting destructor.
- What it was changed to: the main range is `0x00542270-0x0054259f`, with the confirm endpoint corrected and the raw config-save helper documented.
- Summary and evidence: IDA MCP review on 2026-05-28 showed `OnConfirm` ends at `0x00542534`, padding continues to `0x00542540`, and the helper through `0x0054259f` reads two child controls and writes their selected bytes into the target-option config block.
