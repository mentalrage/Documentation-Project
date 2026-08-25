*** UID:0000EE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/BlackHole.h"

class TargetOptionDialog : public DialogPane
{
public:
    TargetOptionDialog();
    virtual ~TargetOptionDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    void SaveTargetOptions();
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TargetOptionDialog

## Status

- Confidence: very strong for complete declaration, fieldless layout, four-child split, behavior, and pairing with `TargetOptionEditControlPane`.
- Likely source file: [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- Main address doc: [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)

## Functionality

`TargetOptionDialog` is a small configuration dialog for target-option settings. It creates two `TargetOptionEditControlPane` controls from config data, applies the ARROW and SHIFT+ARROW user/monster bytes back to the two config rows, closes/removes the dialog, and calls [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) only when `g_activeMapPane != NULL`.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | [UID:0004QS][0x00542270-0x0054248e.TargetOptionDialogConstructor](by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md) | Builds the dialog and child target-option edit controls. |
| ordinary destructor | [UID:0004QT][0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor](by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md) | Explicit empty source destructor; vptr/base teardown is compiler lowering. |
| `OnControlCommand` | [UID:0004QU][0x005424b0-0x00542534.TargetOptionDialogOnControlCommand](by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md) | Accepts only control 1, saves, closes, queues deletion, then conditionally persists. |
| `SaveTargetOptions` | [UID:0004QV][0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw](by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md) | Retained raw private helper that copies controls 2/3 into config rows 0/1. |
| scalar deleting destructor | `0x00542a60-0x00542ab5` | Deleting destructor wrapper in [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md). |

## Evidence

- The accepted `OnControlCommand` ordering is exact: write the two target-option rows -> slide close -> queue deferred deletion -> test `g_activeMapPane` -> call `SaveUserSettings`. The gate is active-map availability, not dirty state, and the target is not a generic `SaveConfig()` method.
- The complete fieldless class declaration now emits at position `50`; exact source bodies emit only through registered children at positions `60/70/80/90`. Mixed parent UID0001E2 is a non-emitting semantic index.

- Live IDA confirms the dialog constructor at `0x00542270` is `0x21e` bytes and is called from `MenuVarietySelectPane::HandleMenuMouseEvent` at `0x005bd17c`.
- The dialog constructor calls `TargetOptionEditControlPane::TargetOptionEditControlPane` at `0x005423dc`, along with the expected dialog/control setup helpers.
- The config-save span at `0x00542540-0x0054259f` is not modeled as a function start; existing live review ties it to reading child controls 2 and 3 and writing selected bytes into config offsets `0x2911dc` and `0x2911de`.
- 2026-06-16 B002 source-quality reanalysis: row 0 is the `ARROW` target-option row and loads/saves user/monster bytes at `g_pConfig + 0x2911dc/+0x2911dd`; row 1 is the `SHIFT+ARROW` row and loads/saves `g_pConfig + 0x2911de/+0x2911df`. Child controls 2 and 3 expose those bytes through [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md) fields `+0x10c/+0x10d`.
- The scalar deleting destructor at `0x00542a60-0x00542ab5` is vtable/adjustor-thunk reached, with thunk refs at `0x0054266b` and `0x00542676` plus a vtable data ref at `0x006211cc`.
- The caller allocates `620` / `0x26c` bytes, exactly the accepted `DialogPane` size, and no target-owned data tail is used. `TargetOptionDialog` is therefore a fieldless derived class.
- Primary/secondary/tertiary vtable views are `0x006211cc`, `0x0062122c`, and `0x0062125c`; command cell `0x00621214` proves `OnControlCommand`. Historical `OnConfirm` and `SaveTargetOptionsFromControls` are superseded aliases.
- Scalar wrapper [UID:00038I][0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor](by-memory/0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor.md), target adjustors `0x00542665/0x00542670`, [UID:0003C9][0x006211c8-0x00621264.TargetOptionDialogVtableData](by-memory/0x006211c8-0x00621264.TargetOptionDialogVtableData.md) vtable/RTTI bytes, constructor EH, security cookie, and explicit vptr writes remain compiler-generated and are not handwritten source.

## Layout And Source Order

- Base class: [UID:00003T][DialogPane](by-class/DialogPane.md), exact size `0x26c`; no derived fields or synthetic reserve bytes.
- Deterministic order in `TargetOptionDialog.cpp`: TargetOptionEditControlPane declaration `0`, UID00011K separate support inventory `10`, TargetOptionDialog declaration `50`, constructor `60`, destructor `70`, command `80`, private helper `90`.
- `[[CHILDREN]]` emits only exact owner-linked method children. UID0001E2 remains semantic inventory and does not duplicate any method.
- Constructor may declare but does not define `InitRectBounds`; command may declare but does not define `SaveUserSettings`. Their existing source owners remain sole definitions.

## Score Rationale

Completion `92` reflects the complete class declaration, exact fieldless size, virtual/private method contract, registered child inventory and order, resources/config/lifecycle behavior, vtable identity, and compiler exclusions. Confidence `94` is capped only by original header/private spelling, not by behavior or emission readiness.

## Cross References

- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md)
- [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)
- [UID:0004QS][0x00542270-0x0054248e.TargetOptionDialogConstructor](by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md)
- [UID:0004QT][0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor](by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md)
- [UID:0004QU][0x005424b0-0x00542534.TargetOptionDialogOnControlCommand](by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md)
- [UID:0004QV][0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw](by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- 2026-07-14 B002 UID0001E2 implementation callback:
  - Raised `86/88` to `92/94`, set source position `50`, installed the complete fieldless `0x26c` class declaration, and linked registered children UID0004QS/0004QT/0004QU/0004QV.
  - Replaced the current blank-class/split-pending state with applied source order and compiler exclusions while retaining older B005/A004/B002 entries below as labeled evidence-time history.

- 2026-07-14 B005 [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) implementation callback support sync:
  - Score, metadata, owner/file route, and blank class formal remain unchanged. Added exact two-row write -> close/remove -> `g_activeMapPane`-gated SaveUserSettings behavior and closed the old call-name/gate ambiguity.

- 2026-06-05 A004 live refresh:
  - Before: the page still carried recovered-source provenance and summarized older IDA evidence.
  - After: raised from `84/86` to `86/88`, kept parent [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md), removed generated-source provenance, and kept final C++ blank.
  - Evidence: live IDA confirms the constructor size and caller, edit-control constructor call, raw non-function config-save helper status, scalar deleting destructor refs, and source-file parent eligibility.
- What existed before: the page referenced the target dialog as `0x00542270-0x00542533` and only named the confirm handler plus scalar deleting destructor.
- What it was changed to: the main range is `0x00542270-0x0054259f`, with the confirm endpoint corrected and the raw config-save helper documented.
- Summary and evidence: IDA MCP review on 2026-05-28 showed `OnConfirm` ends at `0x00542534`, padding continues to `0x00542540`, and the helper through `0x0054259f` reads two child controls and writes their selected bytes into the target-option config block.
- 2026-06-16 B002 source-quality support note:
  - Added field-level config-row mapping for `ARROW` and `SHIFT+ARROW` target options. No class score or route change; final C++ remains blank pending final source names for inherited dialog APIs and helper signatures.
