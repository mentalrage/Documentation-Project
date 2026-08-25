*** UID:000097 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewOptionPane

## Status

- Confidence: strong for behavior, boundaries, source-file placement, vtable/destructor evidence, major helper ownership, and current helper reachability checks; medium-high for final field names and paint/config helper source spelling.
- Likely source file: [UID:0000M7][OptionPane](by-file/OptionPane.md)
- Main address doc: [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- Exact scalar deleting destructor: [UID:00038E][0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor](by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_NewOptionPane.cpp`
- Parent gate: this class is now `87/89`, and [UID:0000M7][OptionPane](by-file/OptionPane.md) is `92/88`, so exact class-owned children that independently clear `85/85` may attach here. The formal block emits `[[CHILDREN]]` because method/helper bodies remain on exact by-memory children.

## Functionality

`NewOptionPane` is the newer page-based options pane embedded in the general-purpose in-game panel. It owns option-page layout, option entry initialization, keyboard/mouse dispatch, volume slider application, option packet submission, background/button painting, and selected-page state.

For volume controls, `NewOptionPane` constructs/configures two [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) instances and receives `OnVolumeChanged(volumeType, oldValue, newValue)` callbacks; horizontal slider geometry, hit-test, interaction, paint, and value conversion remain owned by [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md).

The same volume-control cluster owns two [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) instances. They provide the fixed `120x5` minus/groove/plus background behind the music and sound sliders; CScrollBarBackPane source routes through OptionPane and does not become duplicate NewOptionPane method source.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor/destructor | `0x0053ff90`, `0x005401a0` | Constructs the panel pane, installs vtables, initializes state, and tears it down. |
| activation/layout/open/close | `0x00540240`, `0x005402a0`, `0x005404d0`, `0x005405c0` | Pane lifecycle and placement. |
| volume helpers | `0x005403b0`, `0x00540490`, `0x00541a90-0x00541b2b` | Applies music/sound volume sliders, receives [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) as `OnVolumeChanged(volumeType, oldValue, newValue)`, and toggles slider visibility. |
| owned volume-control fields | `+0x12c4`, `+0x12c8`, `+0x12cc`, `+0x12d0`; construction `0x00540097-0x00540161`; layout `0x0054031c/0x00540384`; deletion `0x00540207/0x00540216` | Music/sound ScrollVolumePane pointers followed by music/sound CScrollBarBackPane pointers. Both back panes use `120x5` bounds, inline `Pane(true)` construction, and common Pane_MarkForDeletion ownership. |
| paint/input | `0x00540600`, `0x00540880`, `0x00540910` | Draws option background/buttons and handles keyboard/mouse changes. |
| server/config helpers | [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md), `0x005411b0`, `0x00541240`, `0x00541a20` | Handles server option responses, option packet sends, hit-test/apply/volume helpers, option-entry setup, initialization, and page changes. |
| destructor thunks | [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md), [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md), and exact child [UID:00038E][0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor](by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md) | `NewOptionPane` thunks at `0x0054260d-0x00542623`; scalar deleting destructor wrapper at `0x00542860-0x00542933` restores class vtables, releases four owned pointer slots, runs base teardown, and conditionally frees the object. |

## Under Review

- `0x00540db0`, `0x00540e50`, `0x00541040`, `0x00541660`, `0x005416d0`, and discontiguous `0x005a8c60` are active-session modeled helpers around this class; Wave2/Wave3 names remain lead material only.
- `0x00540f50` was modeled by Wave2/Wave3 as `NewOptionPane::ApplyServerOptions`, and 2026-06-15 C001 historically defined neutral IDA function records for `0x00540ef0`, `0x00540f50`, and `0x00540ff0`. Current B001 MCP evidence session `ff68e691` supersedes that as the accepted active report state: all four helper starts `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` report `Not a function` and have no direct xrefs/code refs/data refs/immediate refs or raw pointer hits. The older `0b5e057e` pass is historical and agrees on the same raw/no-route state. The byte bodies remain source-shaped and documented on exact child pages, but they should not be described as retained active IDB functions.
- [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md) and [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md) are currently owned by `FittingRoomDownloadControlPane`, but 2026-05-25 IDA caller evidence ties every direct caller to `NewOptionPane::OnPaint`. Generated `class_NewOptionPane.cpp` references them as undeclared `DrawSectionHeader` and `DrawOptionButton` helpers.
- `0x005a8c60-0x005a8ce7` is a discontiguous option-packet helper used by `NewOptionPane::OnMouseClick` cases that pass selectors `7`, `3`, and `1`. Raw disassembly writes packet bytes `0x1b`, `0x01`, the selector byte, and a `selector == 0` byte, then queues four bytes through `0x00574bb0` using `dword_67A7EC`. This helper should be routed through OptionPane/NewOptionPane support and should not be used as LivingObjectPane-local-player evidence.
- `SendOptionPacket11B_540E50` is a global packet helper shared with `SelfLookPane`, so it should stay near options/network packet docs rather than becoming a `NewOptionPane` method without review.
- 2026-06-01 IDA MCP recheck confirms the full modeled function map for the main range, exact endpoints through `0x00541b2b`, the mouse-click jump table after `0x00540d37`, and the raw helper bodies in [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md).
- 2026-06-01 IDA MCP xrefs confirm constructor caller `0x004b8549`, draw helper callers from `OnPaint`, shared `SendOptionPacket11B_540E50` callers from both `NewOptionPane::OnMouseClick` and `SelfLookPane`, and `UpdateSliderVisibility` callers from open/init/page-change paths.
- 2026-06-12 A005 Batch244 live IDA MCP reconfirmed [UID:00038E][0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor](by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md): `sub_542860` is `0xd3` / 211 bytes (Verified with int_convert.py), has adjustor refs at `0x00542613` and `0x0054261e`, primary vtable data ref `0x006210a4`, vtable stores at offsets `+0x00`, `+0xa0` / 160 bytes, and `+0xa4` / 164 bytes (Verified with int_convert.py), four owned pointer-release calls to `0x00544690`, base teardown `0x005450d0`, optional generic free `0x004f4ac0`, and guard support `0x0041b6a0`.
- 2026-06-16 A002 live IDA MCP recheck on session `b001_mappane_0001AW_20260616` reconfirmed the modeled function map from constructor `0x0053ff90` (`0x204` bytes) through slider visibility `0x00541a90` (`0x9b` bytes), plus scalar deleting destructor `0x00542860` (`0xd3` bytes). That session still saw `0x00540ef0`, `0x00540f50`, and `0x00540ff0` as neutral IDA functions with zero xrefs, while `0x00540ea0` remained `Not a function`; the 2026-06-23 B001 active-session recheck below supersedes this helper-state detail for the current IDB. `SendOptionPacket11B` has six callers: four in `OnMouseClick` at `0x00540a0b`, `0x00540a23`, `0x00540a46`, and `0x00540a90`, plus two `SelfLookPane` neighborhood callers at `0x005690a4` and `0x00569164`. The paint helpers remain option-local by caller set (`0x00541660` has four callers and `0x005416d0` has five, all inside `0x00540600`), and primary vtable `0x006210a4` is written by constructor/destructor/scalar destructor at `0x0053ffcf`, `0x005401cb`, and `0x00542892`.

## 2026-06-23 B001 MCP Evidence Recheck (Current `ff68e691`)

- Current accepted implementation evidence was collected from IDA MCP session `ff68e691` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; the older `0b5e057e` pass remains historical/previously accepted and agrees on the main helper-state result.
- Current `lookup_funcs` reconfirmed the class method map in [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md): constructor/destructor, lifecycle/layout, `ApplyVolumeSettings`, `OnVolumeChanged`, open/close, `OnPaint`, key and mouse dispatch, `SetOptionEntry`, `InitializeOptions`, `ChangePage`, and `UpdateSliderVisibility` remain modeled. `0x00540db0`, `0x00540e50`, `0x00541040`, `0x00541660`, `0x005416d0`, and `0x005a8c60` are also modeled helper functions in the active session.
- Current `lookup_funcs` reports `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` as `Not a function`. `xrefs_to`, code-ref, data-ref, immediate, and raw little-endian pointer searches found zero inbound routes to all four starts. This preserves the no-xref/no-pointer blocker and corrects earlier wording that treated the C001 helper promotion as current.
- 2026-07-06 B006 current-session check `9600ec5b` specifically reconfirmed [UID:0003NP][0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest](by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md) has no helper-start route: `lookup_funcs` reports `Not a function`, `xrefs_to` and `xref_query` any/code/data are zero, and both VA bytes `f0 0e 54 00` and RVA bytes `f0 0e 14 00` have zero pointer-encoding hits. `NewOptionPane::OnMouseClick` still contains the live inline-equivalent visible-option scan, so no class score or C++ disposition change is recommended from this B006 note.
- Constructor and vtable evidence still supports the class owner: constructor caller `0x004b8549` is inside `GeneralPurposePanel` construction; method/callback slots route `0x00540600`, `0x00540910`, and `0x00540db0` through `0x006210e8`, `0x006210f8`, and `0x00621104`; primary vtable base `0x006210a4` is written by constructor, destructor, and scalar destructor.
- Paint helper caller sets remain option-local: `0x00541660` has refs at `0x00540639`, `0x0054064c`, `0x0054065f`, and `0x00540672`; `0x005416d0` has refs at `0x0054068b`, `0x005406aa`, `0x005406be`, `0x005406ea`, and `0x005407fd`. Current text/name searches found no binary proof for exact original names `DrawSectionHeader` or `DrawOptionButton`; those names remain descriptive source-facing candidates.
- `OnMouseClick` still owns the class-side option dispatch: it calls shared `SendOptionPacket11B` with subcommands `5`, `6`, `9`, and `4`, calls discontiguous `0x005a8c60` with selectors `7`, `3`, and `1`, calls low/high display helper `0x00541040`, page helper `0x00541a20`, group-marker helpers, and packet send `0x00574bb0`.
- `0x005a8c60` is OptionPane/NewOptionPane support, not `LivingObjectPane`: active xrefs are exactly `0x00540a58`, `0x00540aa2`, and `0x00540ab4`, all in `NewOptionPane::OnMouseClick`; the body sends four bytes through `dword_67A7EC` / `g_packetSender`: `0x1b`, `0x01`, selector, and `selector == 0`.
- `InitializeOptions` current decompilation corrects the old "27 calls" shorthand. There are 25 explicit `SetOptionEntry` calls for logical indices `0, 1, 14, 9, 2, 3, 4, 18, 5, 7, 10, 12, 11, 13, 8, 19, 20, 21, 22, 16, 17, 23, 24, 25, 26`; the scan/switch domain remains 27 slots, with `6` and `15` as logical holes/default cases.
- `ApplyVolumeSettings` writes five-times-scaled local values to config offsets `0x28de54` (`MusicVolume`) and `0x28de4c` (`SoundVolume`), then calls SoundManager-like helpers. `OnVolumeChanged` returns when `oldValue == newValue`; nonzero `volumeType` writes pane-side music volume `this+0x12bc`, zero writes pane-side sound volume `this+0x12c0`, then calls `ApplyVolumeSettings` and invalidates the pane.
- Keep the class page at `86/87` and keep formal C++ blank. The class owner/source root are strong, but final C++ is still blocked by raw/no-route helper bodies, unresolved original helper/member names, missing exact `0x005a8c60` child coverage, and unsynchronized declarations for `NewOptionPane`, `OptionEntry`, render helpers, Config, packet senders, `ScrollVolumePane`, and SoundManager.

## Score Rationale

- Completion `86`: the class page records source placement, major method families, exact main-range page, helper islands, draw/config ownership caveats, destructor thunk/destructor children, vtable evidence, active raw-helper/no-xref checks, and the discontiguous `0x005a8c60` route. It remains below higher scores because field names, option-entry layout names, and several helper source-level decisions are not final.
- Confidence `87`: IDA-backed evidence is strong for the strict parent gate through [UID:0000M7][OptionPane](by-file/OptionPane.md) and for excluding helper-owner pollution, but confidence stays below final-source quality because current B001 evidence session `ff68e691` reports four raw/no-function helper starts, final declaration names remain unresolved, and exact `0x005a8c60` child coverage is still future work.

## Reconstruction Notes

- Reconstructable is `TRUE` because class behavior, boundaries, vtable/data refs, helper ownership, and the parent file are now IDA-backed.
- The formal C++ block emits `[[CHILDREN]]` because this class page is a source container over exact by-memory children. Several field names, packet/config helpers, and no-xref helper source names/caller routes are not final-source quality, so the class page does not inline method bodies before the class/member/render/packet/Config declarations are synchronized.

## 2026-07-29 CScrollBarBackPane Volume-Control Support

- Inferred field order is `m_musicVolumeScrollPane` at `+0x12c4`, `m_soundVolumeScrollPane` at `+0x12c8`, `m_musicVolumeBackPane` at `+0x12cc`, and `m_soundVolumeBackPane` at `+0x12d0`. Constructor kind `1` versus `0` and OnVolumeChanged behavior support music-then-sound ordering.
- The two back panes repeat [UID:0004Y8][0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md)'s `Pane(true)` plus primary/EventHandler/TimerHandler class-view installation semantics inline at `0x005400f7-0x00540116` and `0x00540142-0x00540161`.
- Layout calls through the `+0x12cc/+0x12d0` fields set paired `120x5` bounds beside their corresponding ScrollVolumePane controls. Deletion calls at `0x00540207/0x00540216` put both back panes in the same owned lifetime as the sliders.
- [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md) draws each background as minus x `0..4`, three-line groove x `7..94`/`8..93`, and plus x `98..102`/vertical x `100`, using exact `GrafPort::MoveTo` and `g_pfnDrawLineDelta` contracts.
- The backplate declaration and exact constructor/destructor/OnPaint definitions belong to [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) through [UID:0000M7][OptionPane](by-file/OptionPane.md) OptionPane. This class page records ownership/interaction only and does not duplicate their formal source.
- Generic ScrollBar placement and raw draw/helper names are superseded historical assumptions. Existing NewOptionPane helper, packet, config, option-entry, and paint-helper questions remain unchanged and continue to cap the broader class score.

## Cross References

- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md)
- [UID:00038E][0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor](by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md)
- [UID:0000TL][SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md)
- [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)
- [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md)
- [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md)
- [UID:0004Y8][0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md)
- [UID:0004Y9][0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor](by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md)
- [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md)

## Changes

- 2026-07-29 B007 accepted UID0001DV support update: kept `87/89` and owner/emitter UID0000M7, added two CScrollBarBackPane fields at `+0x12cc/+0x12d0`, their inline construction, paired `120x5` layout, common deletion lifetime, exact volume-slider background role, and OptionPane source route without duplicating CScrollBarBackPane child source.

- What existed before: the page referenced the main memory range as `0x0053ff90-0x00541b2a` and only listed loose destructor-thunk starts.
- What it was changed to: the main range is `0x0053ff90-0x00541b2b`, and destructor support points to the exact thunk/destructor island pages.
- Summary and evidence: IDA MCP review on 2026-05-28 showed `UpdateSliderVisibility` ends at `0x00541b2b`, with padding after it; the discontiguous destructor support is generated in the `0x0054259f-0x00542ab5` island.
- Before: completion/confidence metadata were `0/0` despite detailed lifecycle, paint/input, server-option, volume, helper-ownership, and destructor-island documentation.
- Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
- Evidence: the page captures the major method families and unresolved helper ownership issues; confidence remains medium because several paint/config helpers still need final owner decisions and source-level reconstruction.
- 2026-06-01: Changed completion/confidence from `82/76` to `84/82`, marked reconstructable, and attached parent [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Before: helper ownership and raw helper boundaries kept confidence below the attachment threshold.
  - After: current IDA MCP evidence confirms the function map, xrefs, helper caller sets, and parent ownership well enough for attachment. Final C++ remains deferred.
- 2026-06-12 A005 Batch244:
  - Changed from `84/82` to `85/85`, retaining parent [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Evidence: live IDA MCP reconfirmed the exact `NewOptionPane` scalar deleting destructor child [UID:00038E][0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor](by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md), primary and adjustor vtable refs, class vtable restores, four owned pointer-release calls, base teardown, optional delete path, and verified `0xd3`, `0xa0`, and `0xa4` conversions. This is enough for strict direct-parent routing, but final C++ remains blank because source-quality names and helper routes are not final.
- 2026-06-15 C001 helper-state refresh: no class score change; recorded that target helper starts `0x00540ef0`, `0x00540f50`, and `0x00540ff0` had neutral IDA function records and comments in that session, with no renames/types and no inbound xrefs or raw pointer hits found. The 2026-06-23 B001 recheck supersedes this as accepted evidence-session state.
- 2026-06-16 A002 class-confidence refresh:
  - Changed from `85/85` to `86/87`, retaining owner/emitter [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Evidence: live IDA MCP reconfirmed the current method map, constructor/vtable/destructor refs, option packet caller split, option-only paint helper callers, `0x00540ea0` raw no-function/no-xref status, and the zero-xref state of the three neutral helper functions. The unresolved blockers are now specifically final option-entry field names, no-xref helper source visibility, and final config/packet helper declarations rather than class ownership or reachability.
- 2026-06-23 B001 NewOptionPane source-quality implementation: no class metadata or C++ change.
  - Evidence: historical B001 MCP evidence session `0b5e057e` reconfirmed class ownership, vtable/callback refs, method boundaries, paint helper caller sets, shared `0x00540e50` caller split, and discontiguous `0x005a8c60` option-packet route; it corrected the accepted helper state by showing `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` are all `Not a function` with no inbound xref/pointer/immediate route in that IDB session. Current redo session `ff68e691` is now the active accepted pass and reconfirms the same no-function/no-route state, corrected 25 explicit `SetOptionEntry` calls across the 27-slot domain with holes `6` and `15`, volume-field behavior, paint helper caller sets, no exact helper-name proof, and blank-C++ rationale. The C001 helper promotion remains historical/session-specific evidence, not retained active-IDB state for this evidence pass.
- 2026-06-30 B007 implementation callback:
  - Changed from `86/87` to `87/89` and inserted formal `[[CHILDREN]]`.
  - Evidence: accepted B007 report preserved current MCP evidence for class ownership, child helper routing, raw/no-route helper starts, paint helper caller sets, and the future [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md) split plan. Confidence rises because blank class output is replaced by the correct container marker; it remains below final-source quality because method child splits, option-entry/config field names, and exact helper spellings are still inferred.

## UID0003UL Server-Option Label Evidence - 2026-07-15

- NewOptionPane's accepted label/index consumers resolve the RegistryConfig bytes used by [UID:0003UL][0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket](by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md): `+0x28de6e` Whisper, `+0x28de6f` Shout, `+0x28de70` Advice, `+0x28de72` Magic, `+0x28de73` Weather, and `+0x28de74` Fixed movement.
- Those exact labels support source-facing fields `m_whisperEnabled`, `m_shoutEnabled`, `m_adviceEnabled`, `m_magicEnabled`, `m_weatherEnabled`, and `m_fixedMovementEnabled` in the player-settings parser. The mapping is label-and-consumer evidence; it does not claim recovered debug symbols.
- UID0003UL writes those six fields directly among a ten-store sequence. It does not route through a NewOptionPane member, transfer class ownership, or make the option pane the parser's source module.
- Class score `87/89`, owner/emitter, method inventory, formal `[[CHILDREN]]` block, raw/no-route helper decisions, and all unrelated option-entry evidence remain unchanged.
