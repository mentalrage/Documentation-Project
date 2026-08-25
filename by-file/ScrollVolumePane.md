*** UID:0000NK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScrollVolumePane

## Status

- Confidence: very strong for class/source-family identity, direct `ui/controls` module placement, the complete nineteen-method split, exact `0x110` natural layout, EventHandler/TimerHandler virtual identities, horizontal slider behavior, and the ScrollVolumePane/OptionPane ownership split.
- Proposed module: `ui/controls/ScrollVolumePane.cpp`
- Proposed header: `ui/controls/ScrollVolumePane.h`
- Current recovered source: `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp`
- Main class: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- Main address doc: [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- Formal split: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) emits the human declaration to H and `[[CHILDREN]]` to CPP; nineteen exact by-memory children emit definitions. [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md) is now a non-emitting address index.
- Evidence basis: current IDA MCP function/byte/xref/type/vtable evidence, reconciled child reports, homologous slider classes, and current by-* documentation. Generated output is a lead only where it conflicts with exact evidence.
- Remaining uncertainty: original private spellings and direct routes to raw function-shaped starts are unavailable, but exhaustive negative-route checks and convergent class-family behavior support the selected human source names and ownership.

## File Role

`ScrollVolumePane.cpp` owns the horizontal volume slider used by option-panel sound and music volume controls. It is a `Pane`-derived control with three inherited vtable views, signed value/range state, distinct hover/active/drag state, pointer capture and repeat-timer handling, and EPF-backed thumb rendering from `SCRBUTT2.EPF` with `BUTTON.PAL`.

Keep this separate from [UID:0000M7][OptionPane](by-file/OptionPane.md). `NewOptionPane` constructs and configures the two sliders and receives `OnVolumeChanged(volumeType, oldValue, newValue)` callbacks, but this source owns reusable slider geometry, hit-testing, interaction state, horizontal value conversion, and drawing.

## Accepted Source Contents

| Position | Definition | Exact by-memory source |
| --- | --- | --- |
| 10 | `ScrollVolumePane::ScrollVolumePane` | [UID:0004XQ][0x00564710-0x005647b1.ScrollVolumePaneConstructor](by-memory/0x00564710-0x005647b1.ScrollVolumePaneConstructor.md) |
| 20 | `SetTrackStateWord` | [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) |
| 30 | `SetScrollStyle` | [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) |
| 40 | `SetRange` | [UID:0004XR][0x00564820-0x0056487b.ScrollVolumePaneSetRange](by-memory/0x00564820-0x0056487b.ScrollVolumePaneSetRange.md) |
| 50 | `SetValue` | [UID:0004XS][0x00564880-0x005648a7.ScrollVolumePaneSetValue](by-memory/0x00564880-0x005648a7.ScrollVolumePaneSetValue.md) |
| 60 | `Enable` | [UID:0004XT][0x005648b0-0x005648ca.ScrollVolumePaneEnable](by-memory/0x005648b0-0x005648ca.ScrollVolumePaneEnable.md) |
| 70 | `Disable` | [UID:0004XU][0x005648d0-0x005648ea.ScrollVolumePaneDisable](by-memory/0x005648d0-0x005648ea.ScrollVolumePaneDisable.md) |
| 80 | `CanAdjust` | [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) |
| 90 | `HandlePointerOrMouseEvent` | [UID:0004XV][0x00564910-0x00564af1.ScrollVolumePaneHandlePointerOrMouseEvent](by-memory/0x00564910-0x00564af1.ScrollVolumePaneHandlePointerOrMouseEvent.md) |
| 100 | `HandleKeyOrTextEvent` | [UID:0004XW][0x00564b00-0x00564b05.ScrollVolumePaneHandleKeyOrTextEvent](by-memory/0x00564b00-0x00564b05.ScrollVolumePaneHandleKeyOrTextEvent.md) |
| 110 | `OnTimer` | [UID:0004XX][0x00564b10-0x00564b43.ScrollVolumePaneOnTimer](by-memory/0x00564b10-0x00564b43.ScrollVolumePaneOnTimer.md) |
| 120 | `OnPaint` | [UID:0004XY][0x00564b50-0x00564e21.ScrollVolumePaneOnPaint](by-memory/0x00564b50-0x00564e21.ScrollVolumePaneOnPaint.md) |
| 130 | `HitTestPart` | [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) |
| 140 | `GetPartRect` | [UID:0004XZ][0x00565010-0x0056516b.ScrollVolumePaneGetPartRect](by-memory/0x00565010-0x0056516b.ScrollVolumePaneGetPartRect.md) |
| 150 | `SetHoverPart` | [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md) |
| 160 | `BeginInteraction` | [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) |
| 170 | `CommitInteraction` | [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) |
| 180 | `NotifyValueChange` | [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) |
| 190 | `ResetInteractionState` | [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) |

The file does not own the `0x005654ec` successor thunks. Sixteen internal all-`0xCC` alignment spans are non-source padding and are documented in [UID:0000VN][-ignored](by-memory/-ignored.md). Raw helper starts retain explicit no-xref/no-pointer-route evidence without being treated as dead data.

## Historical Proposed Contents (Superseded Where Corrected Above)

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) | `0x00564710-0x005654ec` | Horizontal volume slider pane declaration, constructor, value/range API, mouse handling, drawing, and helper methods. |
| [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) | `0x005647c0-0x005647e7` | Raw `SetTrackStateWord` helper that stores inferred `m_trackStateWord` at `+0xf8`, the low word of the `+0xf8..+0xfb` state cluster, and invalidates the bounds rect when changed. |
| [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) | `0x005647f0-0x00564814` | Raw `SetScrollStyle` helper that stores inferred `m_scrollStyle` byte `+0xfa`, initialized to `1`, and invalidates the bounds rect when changed; exact original spelling and live route remain unrecovered. |
| [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) | `0x005648f0-0x0056490a` | Raw source-ready `CanAdjust() const` predicate that returns `m_enabled && m_range > 0`; B007 current MCP confirms exact bytes, no raw-start route, field census, accepted inferred name, and formal child C++ through `NexusTK/ui/controls/ScrollVolumePane.cpp`. |
| [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) | `0x00564e30-0x00565006` | Helper that maps a point to horizontal `ScrollVolumePart` id `0..4` or `-1` by building candidate rectangles inline. |
| [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md) | `0x00565170-0x005651e0` | Raw helper that invalidates old/new hovered slider parts and stores hover state; the older highlight wording is superseded. |
| [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) | `0x005651e0-0x0056529f` | Raw `BeginInteraction(ScrollVolumePart part, int localY, int localX)` helper that initializes thumb drag state, stores active part, calls commit, and starts timer/update handling; the trailing byte at `0x0056529f` is separate padding. |
| [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) | `0x005652a0-0x00565360` | Omitted helper that commits mouse/focus interactions and clears highlight state. |
| [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) | `0x00565360-0x00565488` | Omitted helper that computes changed slider values and calls the option-pane callback. |
| [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) | `0x00565490-0x005654ec` | Raw helper that stops timer/update handling and clears active/highlight state before `ScrollablePane` destructor thunks. |
| [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md) | offsets `+0xf8` through `+0x10f` | Naturally aligned signed value/range, enabled, hover, active, drag-state, and Point fields. |
| [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md) | `0x006240b4`, `0x00624100`, `0x00624130` | Primary Pane plus inherited EventHandler and TimerHandler views for paint, pointer/mouse, key/text, and timer callbacks. |
| `g_pEPFLibrary` / [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) dependency | global data dependency | Loads `SCRBUTT2.EPF`/`BUTTON.PAL` for thumb frames; generated `g_pEPFLibrary` should be treated as an unresolved alias lead until reconciled with the reviewed EPF registry singleton. |

## Evidence Notes

- Historical/superseded Wave3 metadata imported the class from `ScrollVolumePane.cpp` and described a 272-byte struct extending `Pane`; current ordinary documentation independently confirms the `0x110` layout and accepted source placement.
- IDA confirms real function starts for constructor and primary methods at `0x00564710`, `0x00564820`, `0x00564880`, `0x005648b0`, `0x005648d0`, `0x00564910`, `0x00564b00`, `0x00564b10`, `0x00564b50`, `0x00564e30`, `0x00565010`, `0x005652a0`, and `0x00565360`.
- 2026-05-25 IDA MCP checks confirm the omitted helpers at `0x00564e30`, `0x005652a0`, and `0x00565360` are an internal slider interaction chain; the final helper calls [UID:0000M7][OptionPane](by-file/OptionPane.md) callback `0x00540490` only after a value change.
- 2026-05-26 IDA MCP recheck leaves the boundary unchanged: `0x00565170`, `0x005651e0`, and `0x00565490` still report `Not a function` with no xrefs, while `0x005654ec` and `0x005654f7` are vtable-referenced adjustor thunks that jump to `ScrollablePane::ScalarDeletingDestructor` at `0x00565510`.
- 2026-05-31 IDA MCP raw-disassembly pass split `0x00565170`, `0x005651e0`, and `0x00565490` into exact memory pages so the file-level contents no longer rely on inline projected rows.
- IDA confirms vtable bases `0x006240b4`, `0x00624100`, and `0x00624130`. Historical/superseded Wave3 metadata had `vtable_count: 0`; current ordinary vtable documentation records the accepted `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and `OnTimer` identities.
- Constructor callers are two allocations from [UID:0000M7][OptionPane](by-file/OptionPane.md) constructor at `0x00540097` and `0x005400c6`, corresponding to music and sound sliders.
- `SetRange`, `SetValue`, `Enable`, and `Disable` are called by `NewOptionPane` helpers at `0x005403b0` and `0x00541a90`.
- Historical Wave2 recovery identified `ScrollVolumePane::SetRange`, `SetValue`, `Enable`, and `Disable`; current exact child pages and ordinary source routing independently retain those methods. Wave2 is not current authority.
- Historical 2026-06-08 A008 IDA MCP notes used superseded `OnMouseEvent`/`OnLoseFocus` labels for internal callers. The same evidence currently supports the source-module boundary through `HandlePointerOrMouseEvent`, `OnTimer`, and raw helper spans; constructor calls remain at `0x00540097`/`0x005400c6`, setters remain at `0x005403b0`/`0x00541a90`, and the `0x005654ec`/`0x005654f7` thunks remain neighboring `ScrollablePane` destructor glue.
- The same pass found raw source-looking helpers at `0x005647c0`, `0x005647f0`, and `0x005648f0`; these now have exact by-memory pages and remain in this source file. B001 resolves the `0x005647c0` helper to inferred `SetTrackStateWord` / `m_trackStateWord`, B002 resolves the `0x005647f0` helper to inferred `SetScrollStyle` / `m_scrollStyle`, and B007 resolves the `0x005648f0` helper as accepted inferred `CanAdjust() const`. Exact original spellings and live raw-start routes remain unrecovered, but [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) no longer lacks target-level source-ready C++.
- 2026-06-23 B005 MCP session `80de0a67` rechecked [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) as a ScrollVolumePane-owned raw helper: no IDA function at `0x005651e0`, no xrefs or VA/RVA/raw-offset pointer patterns to the raw start, exact previous-target-successor byte boundaries, and a complete 71-instruction method-shaped body that calls `GetPartRect`, pane invalidation slot `+0x20`, `InitPointPair`, `CommitInteraction`, and `TimerHandler::ScheduleTimer(0, 200, 0, 0)`. The child now emits enum-synchronized `ScrollVolumePane::BeginInteraction` C++; TextEditPane/DrawScrollbarPartF, OptionPane/NewOptionPane, TimerMgr/helper-module, aggregate-only/no-owner, and covered-by-marker routes remain rejected.
- 2026-06-26 B007 MCP session `80de0a67` rechecked [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) as a ScrollVolumePane-owned raw predicate: `lookup_funcs` reports modeled `Disable` at `0x005648d0` size `0x1a` / 26 bytes, raw non-functions at `0x005648f0`, `0x00564909`, and `0x0056490a`, and modeled `0x00564910` under the superseded `OnMouseEvent` label; the current source identity is `HandlePointerOrMouseEvent`, size `0x1e1` / 481 bytes (sizes Verified with tools/int_convert.py). The target bytes are `80 b9 02 01 00 00 00 74 0e 33 c0 66 3b 81 00 01 00 00 7d 03 b0 01 c3 32 c0 c3`, bounded by six `0xcc` bytes before and after. `xrefs_to` finds no raw-start/end xrefs, while the `HandlePointerOrMouseEvent` positive control remains the vtable pointer at `0x00624104`; local PE route scanning finds no VA/RVA/file-offset/direct-branch route to the raw start/end while finding direct routes to sibling helpers. Scoped field census finds 11 `102h` hits for `m_enabled`, 11 `100h` hits for `m_range`, and 10 `0FEh` hits separating `m_value`; rejected alternatives include OptionPane/NewOptionPane ownership, generic ScrollBar/ScrollableControlPane ownership, stale TextEditPane ownership, padding/data/no-owner placement, and narrower names such as `IsEnabled`, `HasRange`, `CanScroll`, or drag/hover names.

## Generated Output Caveats

- Active `class_ScrollVolumePane.cpp` previously emitted helper bodies at `0x00564e30`, `0x005652a0`, and `0x00565360` with stale `TextEditPane::*` signatures. Current source-quality direction rejects those names as generated-owner pollution: the bodies belong to `ScrollVolumePane`, and the declaration-level C++ now lives on [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) while exact bodies live on child by-memory pages.
- Active output includes raw/projected helper-shaped starts at `0x005647c0`, `0x005647f0`, `0x005648f0`, `0x00565170`, and `0x00565490`; IDA `lookup_funcs` reports these starts as `Not a function` and `xrefs_to` reports no direct xrefs. Keep them as raw/projected helpers. The `0x005647c0` body now emits inferred `SetTrackStateWord`, the `0x005647f0` body now emits inferred `SetScrollStyle`, and the `0x005648f0` body now emits retained inferred `CanAdjust() const`; the no-function/no-xref/no-pointer-route caveat still applies to those raw starts.
- At B007 intake, `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp` already emitted the correct [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) `CanAdjust` body but carried stale `78/85` generated UID comments from older tracker state. Update source by-* metadata and use validator refresh; do not edit generated source by hand.
- The adjacent `0x005654ec`, `0x005654f7`, and `0x00565510` destructor tail is [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) glue, not `ScrollVolumePane` ownership evidence. The canonical memory page now starts at `0x005654ec` so those thunks are covered by `ScrollablePane`, not this file.
- `class_ScrollVolumePane.cpp.source_map.json` still reports generated `g_pEPFLibrary` as unresolved global-data provenance with no memory range. Use [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) as the reviewed canonical global, or run a dedicated alias/global pass before treating the local comment as a distinct ownership record.

## Changes

- 2026-06-26 B007 [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) source-quality sync:
  - Score remains `89/88`; file route remains `NexusTK/ui/controls/ScrollVolumePane.cpp`.
  - Evidence: accepted B007 report and current MCP session `80de0a67` raise the child to `89/91`, preserve the exact formal `ScrollVolumePane::CanAdjust() const` body, and resolve stale final-name-open wording. The file page now records exact target bytes, six-byte padding before/after, raw non-function/no-xref/no-route status, positive controls, field census for `m_enabled`/`m_range`/`m_value`, accepted inferred naming, rejected owner/name/split alternatives, and the generated-output stale-score caveat. Broad file-level source remains a route/contents document; method bodies continue to emit from exact by-memory child pages.
- 2026-05-28: Clarified that `0x005654ec` and `0x005654f7` are now included in the `ScrollablePaneVirtualDefaults` page.
  - Before: this file pointed to a `0x00565510-0x00565607` page that described the thunks only in prose.
  - After: the `ScrollablePane` page range itself covers `0x005654ec-0x00565608`; `ScrollVolumePane` still ends at `0x005654ec`.
  - Evidence: IDA MCP reports the two thunks subtracting `0xa0`/`0xa4` and jumping to `0x00565510`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document includes role, proposed contents, omitted helper chain, layout/vtable refs, IDA evidence, generated-output caveats, boundary correction, source-structure decision, and cross-references; confidence remains capped by final folder and raw/projected helper modeling.
- 2026-05-30: Corrected the current recovered source path and generated-output caveat.
  - Before: The page referenced the old flat `source-3/simroot_v2/class_ScrollVolumePane.cpp` path and said the active output omitted the three helper bodies.
  - Historical after-state: the page pointed to `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp` and recorded helper bodies emitted with `TextEditPane` ownership/name pollution. Current ordinary pages use `ScrollVolumePane`; renewed supervisor generated-output verification remains pending.
  - Historical/superseded evidence: the then-current `simroot_v2` file list, `class_ScrollVolumePane.cpp.source_map.json`, and `class_ScrollVolumePane.meta_wave3` snapshot reported path `ui\controls\class_ScrollVolumePane.cpp`, active methods `0x00564e30`, `0x005652a0`, and `0x00565360`, and stale `TextEditPane::*` signatures.
- 2026-05-31: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/` and added the split raw helper memory pages to proposed contents.
  - Before: The validator-managed projected path was blank and raw helper spans were only described in caveats.
  - After: The file stages as `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`, matching the proposed source tree, and contents link the exact raw helper pages by UID.
  - Evidence: `by-project-structure/proposed-source-tree.md` already places `ScrollVolumePane.cpp` under controls; IDA MCP confirms the raw helper boundaries and the class remains a reusable UI control consumed by `OptionPane`.
- `GetPartRect` has broad helper use inside this source and possibly text-edit/scroll helpers; do not move it to [UID:0000ON][TextEditPane](by-file/TextEditPane.md) solely from generated notes.
- 2026-06-08 A008 Batch 137 strict-gate refresh:
  - Before: score was `88/80`, with source placement strong but confidence capped by generated-output caveats and missing raw helper splits.
  - Changed to: confidence `85`; completion remains `88`.
  - Evidence: live IDA MCP rechecked constructor/setter callers, vtable installs, internal helper callers, the neighboring `ScrollablePane` thunk boundary, and exact raw helper pages [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md), [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md), and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md). The file now meets the strict gate as direct parent for [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md), while exact original helper spellings and raw routes remain below final-audit confidence.
- 2026-06-19 B014 class source-quality incorporation:
  - Changed to: completion/confidence `89/88`, horizontal volume-slider role, resolved `TextEditPane` generated-signature pollution, and class/source placement synced with [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md).
  - Evidence: B014 report confirmed direct `NewOptionPane` constructor/setter/callback routes, exact child boundary/padding, raw helper no-route evidence, horizontal part/value model, class declaration C++ readiness, and `ScrollablePane` successor thunk exclusion.
- 2026-06-22 Rule 26 [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) sync:
  - Score remains `89/88`; the file-level contents now explicitly model `HitTestPart` as a source-authored ScrollVolumePane helper that constructs its five hit-test rectangles inline, not by delegating to the sibling `GetPartRect` helper.
  - Evidence: `Agent-B014/research/0001H3-ScrollVolumePaneHitTestPart-source-quality.md` directly rechecked `0x00564e30`, rejected stale `TextEditPane::TrackScrollButtonF`, and kept this source in `NexusTK/ui/controls/ScrollVolumePane.cpp`.
- 2026-06-23 B005 [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) source-quality sync:
  - Score remains `89/88`; file route remains `NexusTK/ui/controls/ScrollVolumePane.cpp`.
  - Evidence: target child raised to `88/90` with current MCP session `80de0a67`, formal enum `BeginInteraction` C++, no raw-start function/xref/pointer route, exact body/call/boundary evidence, and explicit rejection of stale `TextEditPane::DrawScrollbarPartF` and covered-by-marker alternatives.
- 2026-06-25 B002 [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) source-quality sync:
  - Score remains `89/88`; file route remains `NexusTK/ui/controls/ScrollVolumePane.cpp`.
  - Evidence: target child was renamed from `SetStateByteRaw` to `SetScrollStyleRaw`, raised to `88/90`, and now emits inferred `ScrollVolumePane::SetScrollStyle(unsigned char style)` / `m_scrollStyle`. Current MCP session `80de0a67` records exact bytes, no-function/no-xref/no-pointer-route evidence, constructor initialization of `+0xfa` to `1`, field-use census showing no local consumers outside the setter, and comparative `ScrollSpellInventoryPane` `+0xfa` scroll style/state setter evidence.
- 2026-06-25 B001 [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) source-quality sync:
  - Score remains `89/88`; file route remains `NexusTK/ui/controls/ScrollVolumePane.cpp`.
  - Evidence: target child was renamed from `SetLowStateWordRaw` to `SetTrackStateWordRaw`, raised to `88/90`, and now emits inferred `ScrollVolumePane::SetTrackStateWord(unsigned short state)` / `m_trackStateWord`. Current MCP session `80de0a67` records target instruction proof, constructor packed initialization `0x00010000`, sibling `+0xfa` setter shape, scoped `+0xf8/+0xfa/+0xfb` field-reference scan, no-function/no-xref/no-pointer-route evidence, and rejected alternatives for value/range/enabled/part/drag names.

## Source-Structure Decision

Use a separate `ui/controls/ScrollVolumePane.cpp` module. It is more specific than [UID:0000NF][ScrollBar](by-file/ScrollBar.md) and [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md), but still a reusable control. [UID:0000M7][OptionPane](by-file/OptionPane.md) consumes it to implement audio settings and should not absorb its class methods.

## Source-Quality Sync

- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) now emits the declaration-level first draft with `ScrollVolumePart`, `kScrollVolumeThumbSpan = 38`, known helper declarations, and `[[CHILDREN]]`.
- [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) now emits inferred `SetTrackStateWord(unsigned short state)` and `m_trackStateWord` for the raw `+0xf8` invalidating setter. Preserve the caveat that exact original spelling and live dispatch route are not recovered, while treating the old `SetLowStateWord` wording as superseded storage-shaped draft terminology.
- [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) now emits inferred `SetScrollStyle(unsigned char style)` and `m_scrollStyle` for the raw `+0xfa` invalidating setter. Preserve the caveat that exact original spelling, live dispatch route, and external effect are not recovered.
- [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) now emits retained inferred `CanAdjust() const` for the raw `+0x102/+0x100` predicate. Preserve the caveat that exact original spelling and live dispatch route are not recovered, while treating old "final source name remains open" wording as stale.
- The source-facing part model is horizontal: leading end, page before thumb, thumb, page after thumb, trailing end, and none. Old vertical top/bottom language was inherited from stale scrollbar-style interpretation and should not be used for this file.
- [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) now matches the class declaration and is a real child body, not a covered-by comment: it uses `ScrollVolumePart part`, `kScrollVolumePartThumb`, `kScrollVolumePartNone`, `m_hoverPart`, `m_activePart`, and `m_thumbDragOffset`, while the byte-store narrowing is explicit in the formal target block. Historical `m_highlightPart` wording is superseded.
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) owns the hit-test helper body and builds candidate rectangles inline. `0x00565010` is the requested-part rectangle helper for callers that need one part rectangle; do not reduce the hit-test source body to a `GetPartRect` loop.
- Method bodies remain on exact by-memory children. [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md) is only the aggregate/container index, vtable/resource pages are compiler/resource support, and the `0x005654ec` successor belongs to `ScrollablePane` destructor glue.
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md) owns construction/configuration and callback policy. `ScrollVolumePane.cpp` owns hit-test, part-rectangle, interaction, timer/update, paint, and horizontal value-conversion behavior.

## Cross-References

- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md)
- [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md)
- [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md)
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md)
- [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md)
- [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md)
- [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md)
- [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)
