*** UID:000097 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewOptionPane

## Status

- Confidence: strong for behavior and boundaries; medium-high for helper ownership around paint/config packet helpers.
- Likely source file: [UID:0000M7][OptionPane](by-file/OptionPane.md)
- Main address doc: [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- Current recovered file: `source-3/simroot_v2/class_NewOptionPane.cpp`

## Functionality

`NewOptionPane` is the newer page-based options pane embedded in the general-purpose in-game panel. It owns option-page layout, option entry initialization, keyboard/mouse dispatch, volume slider application, option packet submission, background/button painting, and selected-page state.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor/destructor | `0x0053ff90`, `0x005401a0` | Constructs the panel pane, installs vtables, initializes state, and tears it down. |
| activation/layout/open/close | `0x00540240`, `0x005402a0`, `0x005404d0`, `0x005405c0` | Pane lifecycle and placement. |
| volume helpers | `0x005403b0`, `0x00540490`, `0x00541a90-0x00541b2b` | Applies music/sound volume sliders, receives [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md), and toggles slider visibility. |
| paint/input | `0x00540600`, `0x00540880`, `0x00540910` | Draws option background/buttons and handles keyboard/mouse changes. |
| server/config helpers | [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md), `0x005411b0`, `0x00541240`, `0x00541a20` | Handles server option responses, option packet sends, raw hit-test/apply helpers, option-entry setup, initialization, and page changes. |
| destructor thunks | [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md), [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) | `NewOptionPane` thunks at `0x0054260d-0x00542623`; scalar deleting destructor wrapper at `0x00542860-0x00542933`. |

## Under Review

- `0x00540db0` and `0x00541040` are IDA-confirmed helpers in this neighborhood, but Wave3 currently reports them as unknown.
- `0x00540f50` is modeled by Wave3 as `NewOptionPane::ApplyServerOptions`; IDA does not currently define a function at that address, but raw-head inspection shows a valid function-shaped body at [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md).
- [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md) and [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md) are currently owned by `FittingRoomDownloadControlPane`, but 2026-05-25 IDA caller evidence ties every direct caller to `NewOptionPane::OnPaint`. Generated `class_NewOptionPane.cpp` references them as undeclared `DrawSectionHeader` and `DrawOptionButton` helpers.
- `SendOptionPacket11B_540E50` is a global packet helper shared with `SelfLookPane`, so it should stay near options/network packet docs rather than becoming a `NewOptionPane` method without review.
- 2026-06-01 IDA MCP recheck confirms the full modeled function map for the main range, exact endpoints through `0x00541b2b`, the mouse-click jump table after `0x00540d37`, and the raw helper bodies in [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md).
- 2026-06-01 IDA MCP xrefs confirm constructor caller `0x004b8549`, draw helper callers from `OnPaint`, shared `SendOptionPacket11B_540E50` callers from both `NewOptionPane::OnMouseClick` and `SelfLookPane`, and `UpdateSliderVisibility` callers from open/init/page-change paths.

## Reconstruction Notes

- Reconstructable is `TRUE` because class behavior, boundaries, vtable/data refs, helper ownership, and the parent file are now IDA-backed.
- The C++ block remains blank because several field names, packet/config helpers, and raw helper promotion decisions are not final-source quality.

## Cross References

- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md)
- [UID:0000TL][SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md)
- [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- What existed before: the page referenced the main memory range as `0x0053ff90-0x00541b2a` and only listed loose destructor-thunk starts.
- What it was changed to: the main range is `0x0053ff90-0x00541b2b`, and destructor support points to the exact thunk/destructor island pages.
- Summary and evidence: IDA MCP review on 2026-05-28 showed `UpdateSliderVisibility` ends at `0x00541b2b`, with padding after it; the discontiguous destructor support is generated in the `0x0054259f-0x00542ab5` island.
- Before: completion/confidence metadata were `0/0` despite detailed lifecycle, paint/input, server-option, volume, helper-ownership, and destructor-island documentation.
- Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
- Evidence: the page captures the major method families and unresolved helper ownership issues; confidence remains medium because several paint/config helpers still need final owner decisions and source-level reconstruction.
- 2026-06-01: Changed completion/confidence from `82/76` to `84/82`, marked reconstructable, and attached parent [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Before: helper ownership and raw helper boundaries kept confidence below the attachment threshold.
  - After: current IDA MCP evidence confirms the function map, xrefs, helper caller sets, and parent ownership well enough for attachment. Final C++ remains deferred.
