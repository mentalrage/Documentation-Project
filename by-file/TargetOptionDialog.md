*** UID:0000OG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TargetOptionDialog

## Status

- Confidence: strong for the dialog/edit-control behavior and source grouping; medium-high for whether this was a separate original file or part of a broader options-dialog source.
- Proposed module: `ui/dialogs/TargetOptionDialog.cpp`
- Main address docs: [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md) and [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)

## Role

`TargetOptionDialog.cpp` owns the target-option configuration dialog and the small two-button edit control used inside it. The dialog reads/writes target-option config bytes around `g_pConfig + 2691548` and saves settings after confirmation.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `TargetOptionDialog` | `0x00542270-0x0054259f`, destructor wrapper `0x00542a60-0x00542ab5` | Dialog shell, config-backed control creation, OK/confirm handling, settings save, and raw target-option config-save helper. |
| `TargetOptionEditControlPane` | `0x004993b0-0x0049980c`, destructor wrapper `0x0049b740` | Small target-option row control that draws two choices, handles mouse selection, and exposes the selected target option. |

## Evidence

- Live IDA confirms `TargetOptionDialog::TargetOptionDialog` at `0x00542270` is called from `MenuVarietySelectPane::HandleMenuMouseEvent` at `0x005bd17c`.
- The dialog constructor calls `TargetOptionEditControlPane::TargetOptionEditControlPane` at `0x005423dc` and passes the dialog/config-backed option state into the embedded edit controls.
- Live IDA confirms the edit-control local function family at `0x004993b0`, `0x00499410`, `0x00499430`, `0x00499660`, `0x00499670`, and `0x00499770`, plus the destructor wrapper at `0x0049b740` and the shared font setter at `0x004b9640`.
- The edit control paints `ARROW` or `SHIFT+ARROW` plus `USER` and `MONSTER`, uses two button rectangles at x ranges `110-130` and `200-220`, and toggles the matching stored selection byte on mouse event kind `1`.
- IDA MCP review on 2026-05-28 confirms the raw helper at `0x00542540-0x0054259f` belongs with `TargetOptionDialog`: it reads child controls 2 and 3 from the dialog child list and stores their selected bytes into config offsets `0x2911dc` and `0x2911de`.

## Boundaries

`TargetOptionDialog` should cross-reference [UID:0000M7][OptionPane](by-file/OptionPane.md), but current caller evidence does not require merging it into `OptionPane.cpp`. It is likely a neighboring options/settings dialog file.

## Cross References

- [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md)
- [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

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
