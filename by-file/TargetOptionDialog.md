*** UID:0000OG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TargetOptionDialog

## Status

- Confidence: very strong for the dialog/edit-control grouping, emitted source order, behavior, resources, config route, and compiler exclusions; original header basename remains uncertain.
- Proposed module: `ui/dialogs/TargetOptionDialog.cpp`
- Main address docs: [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md) and [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)

## Role

`TargetOptionDialog.cpp` owns the target-option configuration dialog and the small two-button edit control used inside it. The dialog creates two edit-control rows from `g_pConfig + 0x2911dc..+0x2911df`: row 0 is `ARROW` user/monster target bytes and row 1 is `SHIFT+ARROW` user/monster target bytes. `OnControlCommand` accepts only action control `1`; `SaveTargetOptions` copies child-control bytes `+0x10c/+0x10d` back to those rows, then the command slides closed, queues deferred deletion, and calls [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) only when `g_activeMapPane != NULL`.

## Current Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `TargetOptionDialog` | `0x00542270-0x0054259f`, destructor wrapper `0x00542a60-0x00542ab5` | Dialog shell, config-backed control creation, `OnControlCommand` with exact two-row write -> slide-close -> deferred-delete queue -> active-map-gated profile save order, and private `SaveTargetOptions`. |
| `TargetOptionEditControlPane` | `0x004993b0-0x0049980c`, destructor wrapper `0x0049b740` | Small target-option row control that draws two choices, handles mouse selection, and exposes the selected target option. |

## Deterministic Emission Inventory

| Position | UID | Source item |
| ---: | --- | --- |
| `0` | [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md) | Complete `0x110` class declaration, exact fields and inline selection accessors. |
| `10` | [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md) | Separate source-bearing edit-control method inventory; its unresolved bodies remain an intentional marker, not a duplicate class declaration. |
| `50` | [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md) | Complete fieldless `0x26c` class declaration. |
| `60` | [UID:0004QS][0x00542270-0x0054248e.TargetOptionDialogConstructor](by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md) | Constructor with exact base/resource/control/config/geometry/lifecycle order. |
| `70` | [UID:0004QT][0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor](by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md) | Empty ordinary source destructor. |
| `80` | [UID:0004QU][0x005424b0-0x00542534.TargetOptionDialogOnControlCommand](by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md) | Virtual action command with exact close/queue/persistence order. |
| `90` | [UID:0004QV][0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw](by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md) | Retained private two-row save helper. |

## Evidence

- Live IDA confirms `TargetOptionDialog::TargetOptionDialog` at `0x00542270` is called from `MenuVarietySelectPane::HandleMenuMouseEvent` at `0x005bd17c`.
- The dialog constructor calls `TargetOptionEditControlPane::TargetOptionEditControlPane` at `0x005423dc` and passes the dialog/config-backed option state into the embedded edit controls.
- Live IDA confirms the edit-control local function family at `0x004993b0`, `0x00499410`, `0x00499430`, `0x00499660`, `0x00499670`, and `0x00499770`, plus the destructor wrapper at `0x0049b740` and the shared font setter at `0x004b9640`.
- The edit control paints `ARROW` or `SHIFT+ARROW` plus `USER` and `MONSTER`, uses two button rectangles at x ranges `110-130` and `200-220`, and toggles the matching stored selection byte on mouse event kind `1`.
- IDA MCP review on 2026-05-28 confirms the raw helper at `0x00542540-0x0054259f` belongs with `TargetOptionDialog`: it reads child controls 2 and 3 from the dialog child list and stores their selected bytes into config offsets `0x2911dc` and `0x2911de`.
- B005's UID0001AV caller pass resolves the command tail as close/remove followed by a `g_activeMapPane` null test and conditional `SaveUserSettings()`. Historical dirty-state, generic `SaveConfig()`, and `OnConfirm` interpretations are rejected/superseded. The mixed aggregate is now a non-emitting index; exact children carry the complete source without duplication.
- 2026-06-16 B002 source-quality reanalysis confirms `OptionPane` and `ControlPane` are support contexts only; they are not better source owners for this dialog-specific row control.
- Exact resource/geometry contract is empty dialog title; `DLGSETUP.EPF` and `DLGSETUP.PAL`; background `(0,0,338,190)`; action button `(138,156,201,180)`; row bounds `(19,64,318,84)` and `(19,98,318,118)`; child order background/button/rows `0/1/2/3`.
- Constructor lifecycle order is hover/focus/pending control `1`, background resource, `OnCreate` through `g_mainUiLayerSlots.overlayPaneLayerContext`, `OnShow` with `g_pBackPane`, then vertical slide-open.
- Scalar deleting destructors, receiver-adjustor thunks, vtable/RTTI bytes, explicit vptr stores, constructor EH/allocation diamonds, and security-cookie work are compiler-generated and must not appear as handwritten source.
- This by-file page remains prose-only. It has no `RECONSTRUCTION_CPP` metadata/block and does not itself emit a child body.

## Boundaries

`TargetOptionDialog` cross-references [UID:0000M7][OptionPane](by-file/OptionPane.md), but caller and ownership evidence reject merging it into `OptionPane.cpp`, `MenuVarietyPanes.cpp`, `ProfileStorage.cpp`, `RegistryConfig.cpp`, `DialogPane.cpp`, or `ControlPane.cpp`. The accepted reconstruction root remains `NexusTK/ui/dialogs/TargetOptionDialog.cpp`.

## Score Rationale

Completion `90` reflects the exact two-class source grouping, registered method children and deterministic order, class layouts, config/resources/controls/lifecycle behavior, compile-visible external declarations, compiler exclusions, and separate UID00011K inventory. Confidence `91` is capped by the unrecoverable original header/file arrangement, not by source placement or behavior.

## Cross References

- [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md)
- [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- 2026-07-14 B002 UID0001E2 implementation callback:
  - Raised `86/86` to `90/91` and synchronized the prose-only source root to complete class declarations and registered children UID0004QS/0004QT/0004QU/0004QV.
  - Added deterministic order, exact resources/config/control/lifecycle behavior, compiler exclusions, separate UID00011K disposition, and explicit no-by-file-formal policy. Prior B005/A004/B002 entries below remain evidence-time history.

- 2026-07-14 B005 [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) implementation callback support sync:
  - Scores, source path, owner, and formal state remain unchanged. Added exact two-row write -> close/remove -> `g_activeMapPane`-gated SaveUserSettings behavior and preserved the mixed aggregate's no-partial-C++ disposition.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented dialog and custom edit-control anchors at `0x00542270` and `0x004993b0`; proposed-source-tree keeps this settings dialog in `ui/dialogs/` beside `OptionPane.cpp`.
- 2026-06-05 A004 live refresh:
  - Before: the file page still used generated-source provenance and non-live grading evidence for the dialog/edit-control pair.
  - After: raised from `84/80` to `86/86`, removed generated-source provenance, and replaced stale grading evidence with live IDA constructor/caller, edit-control method, raw helper, and paint/input behavior evidence.
  - Evidence: live IDA confirms the dialog constructor caller, edit-control constructor call, exact edit-control local method sizes, destructor wrapper and shared font setter, and the config-save helper ownership.
- What existed before: the file page treated `TargetOptionDialog` as ending at `0x00542533`.
- What it was changed to: the source candidate now includes the corrected confirm endpoint and target-option config-save helper through `0x0054259f`.
- Summary and evidence: IDA MCP review on 2026-05-28 tied `0x00542540-0x0054259f` to the dialog's child controls and config writes, so it should be retained with `TargetOptionDialog.cpp` rather than left as an unknown gap.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covered role, paired edit control, proposed contents, non-live grading/IDA evidence, config-save helper correction, boundaries, and cross-references; confidence was capped by whether the dialog was standalone or part of a broader options source.
- 2026-06-16 B002 source-quality note:
  - Refreshed target-option config-row wording: `ARROW` uses `g_pConfig + 0x2911dc/+0x2911dd`, `SHIFT+ARROW` uses `g_pConfig + 0x2911de/+0x2911df`, and [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md) child bytes `+0x10c/+0x10d` are the row values. No file score/path change.
