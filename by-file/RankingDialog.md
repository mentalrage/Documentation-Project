*** UID:0000MZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RankingDialog

## Status

- Confidence: strong for ranking UI source grouping; medium for final original filename.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/RankingDialog.cpp`
- Evidence basis: IDA MCP function listing, decompilation, byte checks, vtable references, packet/resource use, and exact child memory pages. Recovered one-class container names are treated only as search aids when they are mentioned.

## Hypothesis

The ranking UI was likely one feature source module rather than seven independent one-class files. `RankingDialog` constructs all ranking child controls, owns the selected-category collection, sends ranking opcode `0x7d` requests, and spawns the reward-info dialog. The event-list, event-scroll, user-list, category-record, category-collection, and reward-info classes are private support types for the same dialog.

Likely structure:

```text
ui/dialogs/RankingDialog.cpp
```

Possible split if the original project used smaller feature files:

```text
ui/dialogs/RankingDialog.cpp
ui/dialogs/RankingRewardInfoDialog.cpp
```

## Proposed Contents

| Entity | Current range | Recovery cue | Role |
| --- | --- | --- | --- |
| [UID:0000BM][RankingDialog](by-class/RankingDialog.md) | `0x00458610-0x004598ac` | `class_RankingDialog.cpp` | Main ranking dialog, category selection, page requests, button handling, and singleton lifecycle. |
| [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md) | `0x004598b0-0x0045ae2b` | `class_RankingEventScrollPane.cpp` | Private scrollbar pane for the event/category list, including raw constructor/setter, IDA-confirmed vtables, hover/drag, and reset helper islands. |
| [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md) | `0x0045ae30-0x0045be67` | `class_RankingEventListPane.cpp` | Scrollable event/category list, category click handling, and event-card drawing. |
| [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) | `0x0045bf60-0x0045c257` | `class_RankingCategoryRecord.cpp` | Parsed ranking category/event record and per-category user-entry storage. |
| [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) | `0x0045c260-0x0045d740` | `class_RankingCategoryCollection.cpp` plus helper tail | Vector-like category collection, selected category id, packet parse helpers, and category/user-entry vector storage helpers. Exact memory: [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md), [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md). |
| [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) | `0x0045d7e0-0x0045f33a` | `class_RankingRewardInfoDialog.cpp` plus helper islands | Modal reward-info dialog, reward response parser, reward list storage, reward drawing, and reward-entry/item vector helpers. Exact memory: [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md), [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md), [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md), [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md), [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md), [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md). |
| [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md) | `0x0045f340-0x0045f9f5` | `class_RankingUserListPane.cpp` | Current ranking page display and local-player rank footer. |
| [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) | `0x0067a7e4` | generated global-data alias | Active ranking dialog singleton. |
| [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md) | `0x0067a7e8` | generated global-data alias | Active ranking reward dialog singleton. |

## Packet And Resource Model

- Ranking packets use opcode `0x7d`.
- Constructor sends subcommand `3` with category/page start values `0,0,10`.
- `RequestRankingPage` sends subcommand `2`, selected category id, start rank `10 * page + 1`, and end rank `10 * (page + 1)`.
- Reward info dialog sends subcommand `5` with the selected category id.
- Reward claim button sends subcommand `6` with the selected category id.
- Main resources include `WBOARDBK.EPF`, `WBOARDBK.PAL`, `WEBBOARD.EPF`, `WEBBOARD.PAL`, `SUBWIN.EPF`, `SUBWIN.PAL`, `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, `BUTTON.PAL`, and `SYMBOLS.EPF`.

## Boundary Notes

- IDA confirms the ranking-owned island beginning at `0x00458610`. Earlier functions at `0x00457ff0-0x0045860f` are adjacent but not assigned to this file yet.
- `RankingEventScrollPane` constructor/setter island at `0x004598b0-0x00459a59`, hover/drag island at `0x0045a990-0x0045ac0f`, and reset helper at `0x0045add0-0x0045ae2b` are raw code starts; IDA reports no function object at those starts, but bytes show complete helper bodies.
- IDA confirms `RankingEventScrollPane` vtables at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`. `RankingEventListPane` constructor `0x0045ae30` allocates a `0x110`-byte child pane and installs those same vtables inline at `0x0045aeb2`, `0x0045aeb8`, and `0x0045aec2`, strengthening this file-level grouping.
- IDA also confirms the broader [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md): `RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, and `RankingUserListPane` all have primary, secondary, and tertiary vtable views. Use the IDA vtable data for slot ownership.
- `RankingDialog` secondary vtable slot `0x006109f4` points to `0x00459210`, a real packet handler for ranking opcode `0x7d` subcommands `1`, `2`, `3`, and `6`. The nearby helpers `0x00459810` and `0x0045efe0` are singleton-clear constructor-unwind helpers, not class behavior entry points.
- 2026-05-26 IDA `py_eval` recheck reconfirms `RankingDialog` method boundaries from `0x00458610` through `0x00459840`, `RankingEventListPane` boundaries from `0x0045ae30` through `0x0045be00`, and the six vtable bases/stores for those two classes. Keep the current `class_RankingDialog.cpp` and `class_RankingEventListPane.cpp` owner-pollution caveats, but do not treat the classes themselves as unproved identities.
- The ranking tertiary vtables stop before adjacent UTF-16 resource/label data such as `RewardInfo`, `SUBWIN.EPF`, `Rank`, `SYMBOLS.EPF`, `Total : %d`, and date format strings. Do not read those dwords as virtual slots.
- Recovered `RankingEventScrollPane` output had an `OnMouseEvent` scoped marker at `0x00459a60` without a reliable body and missed modeled helpers at `0x0045a400` and `0x0045ac10`; use IDA and memory docs for those methods.
- IDA proves [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) owns packet parser/helper methods at `0x0045c2a0`, `0x0045c560`, `0x0045cb10`, `0x0045cdc0`, and vector/storage helpers through `0x0045d740`. Its constructor at `0x0045c260` only initializes begin/end/capacity pointers.
- IDA proves the secondary-vtable packet handler [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md), reward-entry parser [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md), and vector storage helpers [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md), [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md), and [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md) as ranking reward-info support.
- Earlier recovered `RankingDialog` output incorrectly grouped [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), Exchange, popup-menu, and generic [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md) helpers with this file. The web-board layout helper `0x0046e2a0`, constructor `0x0046e640`, and response handler `0x0046eaa0` should stay with their documented owners.
- Earlier recovered `RankingEventListPane` output incorrectly grouped generic render/surface helpers around `0x004b9690+`; `0x004b9690`, `0x004b96c0`, `0x004ba450`, and `0x004ba6b0` are now documented as [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md), [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), and [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md). It also grouped [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) and software-render callback targets from [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md). These belong to shared drawing/rendering modules, not ranking.

## Assignment-Gate Refresh

The direct file parent now clears the corrected `85/85` assignment gate for ranking class children whose own pages also meet the gate. Completion is raised to `85` because the page now has a full feature-module inventory, exact method/data child references, ranking packet/resource model, and explicit owner-pollution exclusions. Confidence stays `86`: IDA-backed child pages prove the ranking family and boundaries, while the exact original file split/name remains a modest caveat.

Supporting evidence:

- [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md) documents the exact `0x00610980-0x00610e38` ranking read-only-data child at `86/90`, including `RankingEventListPane` RTTI/vtables at `0x00610ad0-0x00610b74`, constructor/destructor store xrefs, and the `SUBWIN` resource boundary.
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) documents the ranking vtable family at `84/90`, including the `RankingEventListPane` primary, secondary, and tertiary slot anchors.
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) and the exact method children cover the executable ranking island from `RankingDialog` construction through `RankingUserListPane`; lower aggregate completion keeps this source-file score at `85` instead of a higher value.
- The non-ranking WebBoard, popup, dialog animation, and generic render helper ranges are explicitly excluded above, so class children can attach to this file without inheriting those generated-output mistakes.

## Migration Notes

Keep migration as a dry-run planning exercise until the non-ranking helper pollution has been removed or re-owned. Before any real migration, confirm that WebBoard, exchange, popup-menu, generic dialog animation, and render helper rows are not carried into `RankingDialog.cpp`.

## Cross-References

- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md)
- [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md)
- [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md)
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest.md)
- [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md)
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md)
- [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogClearSingletonHelper](by-memory/0x00459810-0x0045981a.RankingDialogClearSingletonHelper.md)
- [UID:0000Y1][0x0045981b-0x00459830.RankingDialogAdjustorThunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md)
- [UID:0000Y8][0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)
- [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md)
- [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md)
- [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md)
- [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md)
- [UID:0001ZE][0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper](by-memory/0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper.md)
- [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md)
- [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md)
- [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
- [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md)
- [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md)
- [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md)
- [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md)
- [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md)

## Changes

### 2026-06-07 - Batch 095 parent-gate refresh

- Before: score was `82/86`; the page was strong but below the corrected `85/85` parent-side gate for assigning class children.
- Changed to: score is `85/86`.
- Summary/evidence: exact ranking read-only data [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md), vtable-family page [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md), executable ranking aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md), and exact method children now give this file page enough documented inventory, boundary, resource, vtable, and pollution-exclusion evidence to serve as the direct parent for ranking class pages that independently clear `85/85`. Remaining original filename/split caveats keep confidence unchanged.

### 2026-05-30 - Grading update

- Before: the file-placement page had detailed ranking UI grouping, packet/resource model, boundary notes, migration notes, and owner-pollution exclusions but remained unevaluated by the completion/confidence header.
- Changed to: score is now `82/86`, reflecting strong evidence that the ranking UI belongs in one `RankingDialog.cpp`-style feature module while keeping the final original filename and recovered-output-cleanliness caveats.
- Summary/evidence: IDA-backed pages identify the main dialog, event scroll/list panes, category collection/record, reward-info dialog, user-list pane, opcode `0x7d` handlers, vtable families, globals, resources, and non-ranking helper pollution.

### 2026-05-27 - Expanded RankingCategoryCollection placement evidence

- Before: `RankingCategoryCollection` was listed as `0x0045c260-0x0045d4f8` with no exact memory-page references and no constructor/parser caveat.
- Changed to: expanded the proposed contents row through the storage helper tail, linked exact memory docs for the parser/helper cluster and vector-storage helpers, and added the constructor/parser caveat.
- Summary/evidence: IDA confirms parser/accessor/helper starts from `0x0045c260` through `0x0045d740`; `0x00459210` dispatches ranking opcode subcommands to the parser methods; `0x0045c260` disassembly lacks the generated selected-id initialization.

### 2026-05-27 - Expanded RankingRewardInfoDialog helper ownership

- Before: `RankingRewardInfoDialog` was listed only as `0x0045dba0-0x0045f12c`, which hid the preceding parser/accessor island and trailing range/allocation helpers.
- Changed to: expanded the proposed contents row to `0x0045d7e0-0x0045f33a`, linked exact reward parser, core, packet-handler, vector-storage, destroy, and range-allocation memory docs.
- Summary/evidence: IDA confirms the reward-info packet handler at `0x0045ddd0`, parser at `0x0045d7e0`, vector helpers through `0x0045f33a`, and nested 560-byte reward entry / 520-byte item row ownership used by reward drawing.
