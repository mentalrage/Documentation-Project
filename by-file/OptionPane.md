*** UID:0000M7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# OptionPane

## Status

- Confidence: strong for `OptionPane` and `NewOptionPane` behavior; medium for final original file grouping.
- Proposed module: `ui/dialogs/OptionPane.cpp`
- Current recovered sources: `class_OptionPane.cpp`, `class_NewOptionPane.cpp`, and `SendOptionPacket11B_00540E50.cpp`
- Main address docs: [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md) and [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)

## Role

`OptionPane.cpp` is the client options/settings UI family. It includes the older compact `OptionPane` dialog and the newer page-based `NewOptionPane` panel used by the general-purpose in-game panel.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `OptionPane` | `0x0053d820-0x0053e520`, destructor wrapper `0x00542940` | Older option dialog; builds radio/checkbox controls, sends option opcode `0x11b` updates, and applies server-provided option availability state. |
| `NewOptionPane` | `0x0053ff90-0x00541b2b`, destructor/thunks [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) and [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) | New page-based options pane; initializes option entries, handles pages, draws option buttons, applies sound sliders, and sends config/server updates. |
| [UID:0000TL][SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md) | [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) | Shared 3-byte opcode `0x011b` option packet helper used by `NewOptionPane` and `SelfLookPane`; old `OptionPane` has a distinct local copy at [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md). |
| [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) consumers | constructor calls `0x00540097`/`0x005400c6`; setters from `0x005403b0` and `0x00541a90`; callback at `0x00540490` | `NewOptionPane` owns the music/sound setting policy and callback target, while slider hit-test/commit/value computation stays in `ScrollVolumePane.cpp`. |
| option-local helpers under review | [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md), [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md), [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md), [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md), [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md) | IDA-confirmed helpers that are currently unmodeled, raw/projected, or owned by suspicious feature classes. |

## Boundaries

- Keep [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md) as a neighboring target-settings dialog candidate for now. It is opened from the menu-variety path rather than directly from `NewOptionPane`.
- Keep macro setup dialogs (`MacroDialog`, `NewMacroDialog`, `IntegrateMacroDialog`) for a separate macro-dialog pass. They are physically adjacent but large enough to justify their own source-layout review.
- Keep [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) and [UID:0000NV][SoundManager](by-file/SoundManager.md) in their own modules. `NewOptionPane` consumes volume sliders and audio APIs, but it does not own the slider control or audio implementation.
- Keep `RefreshGroupMemberMarkers_5ADC20` and `ClearGroupMemberMarkers_5ADC70` with the group/map marker helper documentation. `NewOptionPane::OnMouseClick` toggles those helpers but does not own their table-walk behavior.

## Evidence

- Wave3 reports `OptionPane` grade `95.2`, five methods, and owner file `class_OptionPane.cpp`.
- Wave3 reports `NewOptionPane` grade `96.2`, nineteen methods, and owner file `class_NewOptionPane.cpp`.
- IDA confirms `NewOptionPane::NewOptionPane` is constructed from `GeneralPurposePanel::GeneralPurposePanel` at `0x004b8549`.
- IDA confirms `NewOptionPane::OnMouseClick` calls `SendOptionPacket11B_540E50` and the group-member marker helpers.
- IDA confirms `NewOptionPane::OnVolumeChanged` at `0x00540490` is called from [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md), so the callback belongs here while slider math remains in [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md).
- IDA confirms real functions at `0x00540db0` and `0x00541040` inside the `NewOptionPane` neighborhood, and raw function-shaped helpers at `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0`; see [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md).
- IDA confirms `0x0053e380` and `0x00540e50` have identical three-byte opcode `0x011b` send behavior, but separate caller sets. Keep `0x0053e380` as the old `OptionPane` local helper and `0x00540e50` as the shared global helper.
- IDA MCP byte/function review on 2026-05-28 confirms real old `OptionPane` helper bodies at `0x0053e3d0` and `0x0053e420`, between the corrected local sender end at `0x0053e3c1` and the macro-dialog boundary at `0x0053e520`.
- 2026-06-01 IDA MCP recheck confirms the old pane function map at `0x0053d820-0x0053dd4f`, `0x0053dd50-0x0053dd6f`, `0x0053ddb0-0x0053e191`, `0x0053e1e0-0x0053e377`, and `0x0053e380-0x0053e3c1`; the raw helper bytes at `0x0053e3d0` and `0x0053e420` remain source-shaped bodies without IDA function records.
- 2026-05-25 IDA MCP recheck confirms `0x00541660` and `0x005416d0` are real functions whose direct callers are all inside `NewOptionPane::OnPaint`; generated `class_NewOptionPane.cpp` calls `DrawSectionHeader` / `DrawOptionButton`, but the helper bodies are currently emitted under `FittingRoomDownloadControlPane`.

## Migration Notes

Do not migrate the current generated `class_NewOptionPane.cpp` without reviewing the helper ownership caveats. In particular, `0x00541660` and `0x005416d0` are currently owned by `FittingRoomDownloadControlPane`, but their IDA callers in this range are `NewOptionPane::OnPaint`. Treat them as option-pane paint helpers under review until caller/owner data is cleaned.

Preferred provisional names for those two helpers are `NewOptionPane::DrawSectionHeader` and `NewOptionPane::DrawOptionButton`, or equivalent file-local helpers in `OptionPane.cpp`, unless a later caller sweep finds broader non-option use.

## Cross References

- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md)
- [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md)
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md)
- [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md)
- [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md)
- [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md)
- [UID:0000TL][SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md)
- [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md)
- [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md)

## Changes

- 2026-05-28: Changed the old `OptionPane` range from `0x0053d820-0x0053e3c0` to `0x0053d820-0x0053e520`.
  - Before: the file-level candidate treated the old pane as ending at the local three-byte packet sender.
  - After: the file-level candidate includes the corrected local sender and the newly documented server-option update helper island before `MacroDialogs`.
  - Evidence: IDA MCP review shows `sub_53E380` ending at `0x0053e3c1`, padding to `0x0053e3d0`, helper bodies at `0x0053e3d0` and `0x0053e420`, and `MacroDialogs` beginning at `0x0053e520`.
- 2026-05-28: Changed the `NewOptionPane` range from `0x0053ff90-0x00541b2a` to `0x0053ff90-0x00541b2b`.
  - Before: the file-level candidate ended the pane one byte early and left the following bytes as UNKNOWN.
  - After: `NewOptionPane` includes the full `UpdateSliderVisibility` endpoint; padding and generated destructor support are split into exact `by-memory` rows.
  - Evidence: IDA MCP review shows `sub_541A90` ending at `0x00541b2b`, padding through `0x00541b30`, and generated thunk/destructor support in [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) and [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md).

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `90`, confidence `82`.
- Summary/evidence: the page documents old/new option-pane ownership, source contents, helper boundaries, evidence, migration notes, detailed range changes, and many cross-references; confidence remains capped by final original grouping and helper ownership caveats.
- 2026-06-01 projected path assignment:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, preventing attached children from staging under the proposed source tree.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` already places `OptionPane.cpp` under `ui/dialogs`, and the page's proposed module is `ui/dialogs/OptionPane.cpp`.
