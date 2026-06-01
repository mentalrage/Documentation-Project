*** UID:0000OG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TargetOptionDialog

## Status

- Confidence: strong for class behavior and pairing with `TargetOptionEditControlPane`; medium for whether this was a separate original file or part of a broader options-dialog source.
- Proposed module: `ui/dialogs/TargetOptionDialog.cpp`
- Current recovered sources: `class_TargetOptionDialog.cpp` and `class_TargetOptionEditControlPane.cpp`
- Main address docs: [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md) and [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md)

## Role

`TargetOptionDialog.cpp` owns the target-option configuration dialog and the small two-button edit control used inside it. The dialog reads/writes target-option config bytes around `g_pConfig + 2691548` and saves settings after confirmation.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `TargetOptionDialog` | `0x00542270-0x0054259f`, destructor wrapper `0x00542a60-0x00542ab5` | Dialog shell, config-backed control creation, OK/confirm handling, settings save, and raw target-option config-save helper. |
| `TargetOptionEditControlPane` | `0x004993b0-0x0049980c`, destructor wrapper `0x0049b740` | Small target-option row control that draws two choices, handles mouse selection, and exposes the selected target option. |

## Evidence

- Wave3 reports `TargetOptionDialog` grade `96.8` with constructor, confirm handler, and deleting destructor.
- Wave3 reports `TargetOptionEditControlPane` grade `96.7` with constructor, paint, mouse, hit-test, font, and destructor methods.
- IDA confirms `TargetOptionEditControlPane::TargetOptionEditControlPane` is called from `TargetOptionDialog::TargetOptionDialog` at `0x005423dc`.
- IDA confirms `TargetOptionDialog::TargetOptionDialog` is opened from `MenuVarietySelectPane::HandleMenuMouseEvent` at `0x005bd17c`.
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

- What existed before: the file page treated `TargetOptionDialog` as ending at `0x00542533`.
- What it was changed to: the source candidate now includes the corrected confirm endpoint and target-option config-save helper through `0x0054259f`.
- Summary and evidence: IDA MCP review on 2026-05-28 tied `0x00542540-0x0054259f` to the dialog's child controls and config writes, so it should be retained with `TargetOptionDialog.cpp` rather than left as an unknown gap.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers role, paired edit control, proposed contents, Wave3/IDA evidence, config-save helper correction, boundaries, and cross-references; confidence is capped by whether the dialog was standalone or part of a broader options source.
