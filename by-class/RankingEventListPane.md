*** UID:0000BN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingEventListPane

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Current recovered file: `source-3/simroot_v2/class_RankingEventListPane.cpp`
- Confidence: strong for ranking-owned methods and vtables; medium for current generated-source cleanliness because generic render helpers are still emitted in the generated file.

## Class Purpose

`RankingEventListPane` renders and handles the ranking event/category list on the left side of the ranking dialog. It owns a `RankingEventScrollPane`, synchronizes scroll state to the selected category collection, draws up to ten category cards, and sends category selection changes back to `RankingDialog`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingEventListPane` | `0x0045ae30-0x0045af2b` | Constructs `ControlPane`, creates a `RankingEventScrollPane`, and activates it. |
| `OnResize` | `0x0045af70-0x0045aff7` | Positions the scroll child and refreshes scroll range. |
| `OnSetOrigin` | `0x0045b000-0x0045b072` | Updates child clip/origin state. |
| `UpdateScrollBarState` | `0x0045b080-0x0045b1ff` | Computes max scroll position from category count and toggles scroll visibility. |
| `SetScrollPosition` | `0x0045b200-0x0045b24c` | Source-facing `void SetScrollPosition(int unusedMode, short oldPosition, short newPosition)`. When old/new differ, stores the owner position, conditionally syncs/invalidates the scroll child, calls `UpdateScrollBarState`, and invalidates owner bounds; the leading integer is unused and ordinary callers pass `0`. |
| `OnInsertPane` | `0x0045b250-0x0045b2b5` | Attaches the scroll child callback and refreshes range. |
| `OnDetachPane` | `0x0045b2c0-0x0045b2d5` | Detaches scroll child before base detach. |
| `OnPaint` | `0x0045b2e0-0x0045b44b` | Draws tiled background and up to ten visible category records. |
| `CanAcceptFocus` | `0x0045b450-0x0045b454` | Returns false. |
| `HandleEvent` | `0x0045b460-0x0045b627` | Handles mouse click category selection and mouse-wheel scrolling. |
| `DrawRankingItem` | `0x0045b630-0x0045bcf6` | Draws one category/event card with `SUBWIN` frame and optional symbol icon/text. |
| `NullHelper` | `0x0045bd00-0x0045bd02` | Empty virtual/helper body. |
| `AdjustorThunks` | `0x0045bddd-0x0045bdf2` | Compiler-generated destructor adjustor thunks for the secondary and tertiary vtable views. |
| `ScalarDeletingDestructor` | `0x0045be00-0x0045be66` | Destroys scroll child/control pane and optionally frees storage. |

## Evidence Notes

- Current generated source also emits generic drawing functions such as `SetTextColor`, `GetClipRect`, `DrawRectFrame`, `DrawTiledBackground`, RLE blitters, palette helpers, and line/pixel helpers in the `0x004b9690+` range. `0x004b9690` is now documented as a [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), `0x004b96c0` as a [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md), `0x004ba450` as [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), and `0x004ba6b0` as [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md). These are not ranking-owned and should remain in shared rendering/UI drawing modules.
- Current generated source also emits `DrawOutlinedText` at `0x004bacd0`, but IDA reports 31 direct callers and the body only offsets GrafPort cursor/color state before calling `DrawWideText`. Treat it as part of [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), not ranking-owned code.
- Current generated source also emits `ClipLine` at `0x004bb2e0`, but IDA caller checks show it is only used by the software line callbacks at `0x004bb9b0` and `0x004c0850`. Treat it as [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md), not ranking-owned code.
- Current generated source also emits large software-render callback targets at `0x004bb8d0+` and `0x004c0770+`. These are now documented as [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md), not ranking-owned code.
- The list pane accesses [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) for category collection and selected category state.
- IDA confirms `RankingEventListPane` primary, secondary, and tertiary vtables at `0x00610ad4`, `0x00610b3c`, and `0x00610b6c`; current generated metadata still reports `vtable_count: 0`.
- The tertiary table ends after `+0x04`. The following UTF-16 `SUBWIN.EPF` / `SUBWIN.PAL` strings are resource data, not additional virtual slots.
- 2026-05-26 IDA `py_eval` recheck confirms ranking-owned function boundaries from constructor `0x0045ae30-0x0045af2c` through scalar deleting destructor `0x0045be00-0x0045be67`, including paint `0x0045b2e0-0x0045b44c`, event handler `0x0045b460-0x0045b628`, and card drawing `0x0045b630-0x0045bcf7`. It also reconfirms vtable bases `0x00610ad4`, `0x00610b3c`, and `0x00610b6c` with constructor/destructor stores.
- [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md) records the exact ranking read-only data island at `0x00610980-0x00610e38`; its `RankingEventListPane` subrange `0x00610ad0-0x00610b74` gives the RTTI/vtable cells, constructor/destructor store xrefs, and boundary before the `SUBWIN` resource strings used by `DrawRankingItem`.
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) maps the `RankingEventListPane` vtable slots to the destructor, resize, origin, insert/detach, paint, event, focus, and adjustor-thunk methods listed above.
- 2026-06-23 B001 current MCP session `80de0a67` reconfirms constructor `0x0045ae30` as a modeled function that allocates a `0x110`-byte `RankingEventScrollPane` child and installs the scroll-pane vtables inline. This supports the accepted [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) file route and the [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md) private-child relationship.
- B003 UID0000Y6 reanalysis independently confirms `0x0045b200` is a three-argument owner method ending `retn 0x0c`: argument 1 is an unread integer, arguments 2/3 are old/new signed-short positions, and calls at `0x0045b4c4`/`0x0045b4e6` pass `(0, oldPosition, newPosition)`. Its changed body is instruction-sequence equivalent to UID0000Y6's expanded owner tail: owner `+0x10c` store, conditional child `+0xfe` sync/invalidation through owner `+0x108`, `UpdateScrollBarState`, then owner invalidation.
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md) therefore emits source as `GetOwnerPane()->SetScrollPosition(0, oldPosition, newPosition)`. The direct field sequence is preserved as inlined-callee evidence, not exposed/private field access in `RankingEventScrollPane` source. Equal old/new values perform no owner lookup or list/child side effects.
- B005's UID0000Y5 split confirms the complete private child interaction path before that owner callback: [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md) manages highlighted rectangles; [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md) stores active/anchor state and schedules repeat processing; [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md) dispatches y/x to Y6; and [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md) removes timers and clears active/highlight state.
- These methods remain owned by `RankingEventScrollPane`, not this list class. This list is the consumer/owner callback target only after Y6 computes a changed position. `SetScrollPosition`'s unused leading mode argument and ordinary leading-zero callers remain exact; do not collapse it to a one-argument setter or expose list fields directly from scroll source.
- Executed Y6's formal body, `90/92` score, sentinel-controlled rectangles, no-change return, and `GetOwnerPane` factorization remain unchanged. B005 changes only Y6 coverage metadata to relative `Nested:-4` after the new child rows; that nesting delta has no class/source semantic effect.
- Class-level C++ remains blank in this callback. Exact behavior is well documented, but a source-ready class declaration still depends on stable `ControlPane` override signatures and a verified member surface for the scroll child and scroll position. Generic GrafPort/render helper exclusions listed above remain outside ranking ownership.

## UID0003WR Parsed-Category Consumer Relationships

This pane consumes but does not own [UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md):

- `UpdateScrollBarState` calls `RankingCategoryCollection::GetCount` at `0x0045b09a`; `OnPaint` calls it at `0x0045b373`. Those two exact xrefs make the newly parsed record count the source for maximum scroll position and visible-card iteration.
- `OnPaint` calls `GetByIndex` at `0x0045b3ab`. `HandleEvent` calls it at `0x0045b56e` and `0x0045b5c2` while mapping click/wheel state to a category record. The related raw consumer at `0x0045bd74` inspects the same collection surface.
- `DrawRankingItem` obtains persistent wide title text through `GetTitleText` at `0x0045bc9d` and `0x0045bcb7`; it reads state through getter calls at `0x0045bb06` and `0x0045bb1a`. The parser's signed state and CP_ACP-converted title therefore survive as record state used by card rendering.
- Ranking dialog/button code also reads state at `0x004596dd`, and selected-record access spans event-list selection, dialog page requests, reward, and user-list panes. This pane sends a selected category back to the dialog; it does not parse opcode `0x7d` or own PacketBuffer readers.

The relationship does not change this class's `87/89` score, blank formal channels, or existing render-helper exclusions. It adds exact data provenance for count, lookup, title, state, and selection only.

## Assignment Decision

Assigned to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). This class now clears the corrected child gate at `87/89`, and the direct source-file parent clears the parent gate after the accepted B001 2026-06-23 refresh. The ownership relationship is direct because this pane is a private ranking-dialog child control: it reads [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md), owns the ranking event/category list and scroll child, uses ranking UI resources, and sits inside the IDA-confirmed ranking executable and read-only-data islands. Final C++ remains blank for the accepted control-API/member-surface reason above.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)
- [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md)
- [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md)
- [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md)
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md)
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000Y8][0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)

## Changes

- 2026-08-14 B005 UID0003WR consumer synchronization:
  - Added exact `GetCount`, `GetByIndex`, `GetTitleText`, state, and selection caller relationships from parsed category records to scrollbar, paint, card, and input behavior.
  - Preserved UID0000MZ ownership, `87/89`, blank formal CPP/H, and the complete existing non-ranking renderer exclusions; parser ownership remains UID0000BK/UID0003WR.

- 2026-07-12 B005 UID0000Y5 consumer-support callback:
  - Metadata remains `87/89`, owner/emitter UID0000MZ, and class formal block blank.
  - Added complete UID0004J0/UID0004J1/UID0004J2/Y7 child interaction path feeding executed Y6 and reaffirmed this list as callback consumer rather than direct method owner.
  - Preserved exact `void SetScrollPosition(int unusedMode, short oldPosition, short newPosition)`, ordinary leading-zero calls, old/new guard, child sync/invalidation, `UpdateScrollBarState`, owner invalidation, all render-helper exclusions, and B003 Y6 factorization evidence.

- 2026-07-12 B003 UID0000Y6 narrow support callback:
  - Changed to: documentation only; score remains `87/89`, owner/emitter UID0000MZ and blank formal block remain unchanged.
  - Summary/evidence: documented exact `SetScrollPosition(int, short, short)` arity, leading-zero ordinary calls, old/new guard, owner/child/refresh/invalidation sequence, and UID0000Y6 source factorization. Direct owner-field access from Y6 is rejected as compiler expansion/private-access risk.
  - Preserved: method inventory outside `SetScrollPosition`, class ownership, generated render-helper exclusions, and all broader B005-owned class/split work.

- 2026-06-23 B001 accepted source-quality sync:
  - Before: `86/87`, with class ownership and render-helper exclusions documented but stale score and no current-session inline scroll-child setup note.
  - Changed to: `87/89`; owner/emitter remain [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), final C++ blank.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed constructor `0x0045ae30`, inline `RankingEventScrollPane` allocation/setup, scroll child vtable stores, and preserved non-ranking GrafPort/render helper exclusions. Blank C++ is accepted until `ControlPane` override signatures and member surface are source-ready.

- 2026-06-07: Batch 095 raised score from `78/84` to `86/87` and assigned the class to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
  - Before: The page had method/vtable/render-helper evidence but did not meet the corrected `85/85` child gate, and the file parent was below the parent-side completion gate.
  - After: The page documents the complete ranking event-list method family, exact read-only-data/vtable support, direct ranking-dialog dependency, and explicit generic-render-helper exclusions; `AUTOGEN_PARENT_UID` is set to `0000MZ`.
  - Evidence: [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md) confirms the `0x00610ad0-0x00610b74` RTTI/vtable subrange and store xrefs, [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) maps the virtual slots, and [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) now clears the parent-side gate at `85/86`.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The ranking event/category list pane remained unclassified in autogen coverage despite documented ranking-owned methods, vtable evidence, and render-helper exclusions.
  - After: The class is reconstructable but unassigned because the class completion score remains below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms the ranking-owned starts from `0x0045ae30` through `0x0045be00`, including the `nullsub_22` helper at `0x0045bd00` and destructor adjustor thunk at `0x0045bddd`; existing notes exclude generic render helpers from ranking ownership.

- 2026-05-30: Grading changed from `0/0` to `78/84`.
  - Before: page documented list-pane behavior, method boundaries, vtables, and generic rendering-helper pollution but remained unevaluated.
  - After: score reflects documented construction, resize/origin/scroll synchronization, paint, event handling, item drawing, destructor glue, and rendering-helper exclusions.
  - Evidence: linked ranking aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) and render-helper references record IDA-confirmed function boundaries, vtable bases/stores, and non-ranking helper ownership.
