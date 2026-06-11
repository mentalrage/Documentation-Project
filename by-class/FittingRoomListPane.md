*** UID:000053 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomListPane

## Status

- Confidence: strong for fitting-room list behavior and local constructor/layout/scroll-management/paint/input/destructor boundaries through `0x00421477`, strong for the list-owned item-entry vector insert/move helpers split from `0x00420de0-0x00421301`, and medium for remaining shared-helper ownership and final field names.
- Current Wave3 file: `class_FittingRoomListPane.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Autogen status: reconstructable source class attached to the fitting-room feature file; C++ remains blank because final field names, helper ownership, and child method snippets are not final-source quality.
- Evidence basis: Wave3 inspection, generated source, and IDA MCP xref checks on 2026-05-23 with constructor decompilation rechecked on 2026-05-25.

## Role

Scrollable item-list pane for the fitting-room dialog. It synchronizes the fitting-room scrollbar, reads the embedded [UID:00006T][ItemCatalog](by-class/ItemCatalog.md), renders list/grid entries, handles keyboard/mouse input, and updates the selected preview item.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0002DC][0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor](by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md) | constructor | Control type `8`; initializes list state and allocates/embeds a `FittingRoomScrollPane`. |
| [UID:0002DD][0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup](by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md) | raw destructor/cleanup body | No current IDA function record/xrefs; restores vtables, deletes scroll child, and jumps to base cleanup. |
| [UID:0002DE][0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize](by-memory/0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize.md) | `OnResize` | Positions scrollbar on the right edge and recomputes scroll range. |
| [UID:0002DG][0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane](by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md) | `OnMovePane` | Updates render origin/bounds after the pane moves. |
| [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md) | `UpdateScrollBar` | Counts visible catalog entries, clamps scrollbar range/current value, and toggles scroll child visibility. |
| [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md) | `OnScrollPositionChanged` | Synchronizes list scroll position from the child scrollbar callback. |
| [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md) | `ResetScrollPosition` | Resets scroll and selection/category side state. |
| [UID:0002DJ][0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane](by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md) | `OnInsertPane` | Inserts/attaches the embedded scroll pane, then updates scroll range. |
| [UID:0002DK][0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane](by-memory/0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane.md) | `OnDetachPane` | Detaches the embedded scroll pane and then the list pane. |
| [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md) | `OnPaint` | Draws tiled background, item cells, selection/cart highlights, icons, and item text. |
| [UID:0002DM][0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll](by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md) | `OnKeyScroll` | Handles keyboard page scrolling and refreshes list/scrollbar state. |
| [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md) | `OnInputEvent` | Handles mouse/input selection, slot-to-catalog translation, and cart/selection updates. |
| [UID:0002DO][0x004207ce-0x00420840.FittingRoomListPaneOnInputEventJumpTables](by-memory/0x004207ce-0x00420840.FittingRoomListPaneOnInputEventJumpTables.md) | input switch tables | Compiler-generated jump tables owned by `OnInputEvent`; document for coverage, do not hand-author. |
| [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md) | `OnScrollStep` | Handles repeated scroll-step direction commands. |
| [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md) | raw slot-rect helpers | IDA currently has no function records; byte review shows valid slot-geometry helper bodies and jump tables. |
| [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md) | `HitTestSlot` | Maps mouse coordinates to list/grid item slot. |
| [UID:0002DQ][0x00420d00-0x00420d50.ValidateFittingSelectionIndex](by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md) | `ValidateFittingSelectionIndex` | Free helper that accepts only visible active-category catalog items. |
| [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md) | raw slot-layout helpers | IDA currently has no function records; computes slot origins and clears scratch resource state. |
| [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) | selection/vector helper island | Mixed helper-island aggregate now split into exact child pages; only the 180-byte entry-vector insert/move children below are direct `FittingRoomListPane` evidence. |
| [UID:00030R][0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert](by-memory/0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md) | item-entry vector insert helper | Sole ordinary caller is `OnInputEvent` at `0x00420191`; inserts `0xb4` byte fitting-room item/selection entries and deep-copies the nested vector at `+0xa8`. |
| [UID:00030T][0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange](by-memory/0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange.md) | item-entry move/copy range helper | Internal to `00030R`; moves `0xb4` byte entries and transfers nested vector fields at `+0xa8/+0xac/+0xb0`. |
| [UID:0002DW][0x00421380-0x004213e1.FittingRoomDialogItemEntryRelease](by-memory/0x00421380-0x004213e1.FittingRoomDialogItemEntryRelease.md) | entry release helper | Releases per-entry vector storage at offsets `+0xa8/+0xac/+0xb0` in the `0xb4` byte fitting-room item entry layout. |
| [UID:0002DX][0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor](by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md) | scalar deleting destructor | Restores list-pane vtables, deletes the embedded scroll child, runs base pane teardown, and conditionally frees `this`. |
| [UID:0002E0][0x004214d0-0x004214f7.FittingRoomDialogItemEntryRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomDialogItemEntryRangeRelease.md) | entry range release helper | Walks `0xb4` byte entries and calls the single-entry release helper; likely used by selection/cart vector cleanup. |

## Boundary Cautions

- 2026-06-05 IDA MCP refresh for [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md) confirms exact vtable-only placement at `0x0060dd54`, `0x8eb` method size, 604 instruction heads, 43 calls, `WBOARDBK.EPF`/`WBOARDBK.PAL` resource refs, `g_pFittingRoomDialog` catalog/category reads, six-column/eighteen-cell visible list rendering, cart-highlight checks, icon service calls, wrapped item-name text drawing, and cleanup. This strengthens the class-level paint/input/list cluster enough for the class score to clear the documented 80% parent-attachment threshold.
- 2026-06-05 IDA MCP refresh for [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md) confirms exact vtable-only placement at `0x0060dd7c`, `0xafe` method size, 694 instruction heads, 20 calls, type `3` selection/cart behavior, type `7` scroll behavior, adjacent switch-table bytes, selection/cart vector updates, preview/equipment slot writes, and adjusted child/base event delegation.
- 2026-05-25 IDA MCP decompilation of `0x0041eb90` shows the constructor allocating `272` bytes, calling shared pane/control setup helper `0x00544460`, writing the `FittingRoomScrollPane` vtables inline, and storing the child at list offset `0x11c`. It does not call the generated `0x0041d6c0` constructor record in current IDA output.
- 2026-05-30 IDA MCP byte review shows the apparent post-constructor gap `0x0041ecbd-0x0041ed00` is not all padding. `0x0041ecc0-0x0041ecf5` is a raw destructor/cleanup-shaped body with no current IDA function record or xrefs; document it as cleanup evidence, not a normal method boundary.
- 2026-05-30 IDA MCP byte review shows `0x004207ce-0x00420840` is switch/jump-table data for `OnInputEvent`, while raw helper bodies at `0x00420950`, `0x00420a10`, `0x00420a90`, `0x00420d50`, and `0x00420db0` are valid code even though current IDA has no function records at those starts.
- The historical [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md) aggregate sits adjacent to this class but is mixed. Only the entry release helpers and scalar deleting destructor rows above should be treated as `FittingRoomListPane` evidence; the string, checkbox, generated thunk, padding, and runtime/vector rows belong elsewhere.
- 2026-06-08 A002 parent-source audit for [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) confirms this class is the actual direct owner only for [UID:00030R][0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert](by-memory/0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md) and [UID:00030T][0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange](by-memory/0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange.md). The sibling pointer-vector helpers route to [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), and both wide-format wrappers [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md) and [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md) route to [UID:0000OB][StringUtil](by-file/StringUtil.md). This class therefore clears `85/87` for the list-owned children without owning the mixed aggregate.
- `SetTextColor` at `0x004b9660` is now documented as part of [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md). Current IDA caller checks report 305 direct call sites, so it is generic drawing state, not fitting-room-private code.
- `SetEnabled`, `Show`, and `Hide` around `0x00494b80-0x00494bd0` look like inherited or generic control helpers and should not be used as primary fitting-room ownership anchors.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:00006T][ItemCatalog](by-class/ItemCatalog.md)
- [UID:000054][FittingRoomScrollPane](by-class/FittingRoomScrollPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0002DC][0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor](by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md)
- [UID:0002DD][0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup](by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md)
- [UID:0002DE][0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize](by-memory/0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize.md)
- [UID:0002DG][0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane](by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md)
- [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md)
- [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md)
- [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md)
- [UID:0002DJ][0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane](by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md)
- [UID:0002DK][0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane](by-memory/0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane.md)
- [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md)
- [UID:0002DM][0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll](by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md)
- [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md)
- [UID:0002DO][0x004207ce-0x00420840.FittingRoomListPaneOnInputEventJumpTables](by-memory/0x004207ce-0x00420840.FittingRoomListPaneOnInputEventJumpTables.md)
- [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md)
- [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md)
- [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md)
- [UID:0002DQ][0x00420d00-0x00420d50.ValidateFittingSelectionIndex](by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md)
- [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md)
- [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md)
- [UID:00030R][0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert](by-memory/0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md)
- [UID:00030T][0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange](by-memory/0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange.md)
- [UID:0002DW][0x00421380-0x004213e1.FittingRoomDialogItemEntryRelease](by-memory/0x00421380-0x004213e1.FittingRoomDialogItemEntryRelease.md)
- [UID:0002DX][0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor](by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md)
- [UID:0002E0][0x004214d0-0x004214f7.FittingRoomDialogItemEntryRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomDialogItemEntryRangeRelease.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)

## Changes

- 2026-06-08 supervisor/B001 follow-up application: Scores unchanged at `85/87`. Updated the `0002DR` boundary caution to record that [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md) now routes to [UID:0000OB][StringUtil](by-file/StringUtil.md), confirming this class owns only the fitting-room entry-vector children [UID:00030R][0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert](by-memory/0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md) and [UID:00030T][0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange](by-memory/0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange.md).
- 2026-06-08 A002 Batch101 parent-source follow-up: Raised completion/confidence from `82/86` to `85/87` after replacing the old mixed `0002DR` method-table evidence with exact child pages [UID:00030R][0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert](by-memory/0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert.md) and [UID:00030T][0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange](by-memory/0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange.md). Evidence: `00030R` has one ordinary caller inside `OnInputEvent`, `00030T` is internal to that insert helper, both operate on the documented `0xb4` byte list entry layout, and sibling split children are shared utility/StringUtil helpers rather than class-owned methods. C++ remains blank because final list-entry field/type names are not source-quality.
- 2026-06-05 A003 OnInputEvent refresh: Raised class completion/confidence from `80/85` to `82/86` with C++ still blank. Evidence: live IDA MCP refresh of the input child [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md) confirms exact boundary, vtable-only placement, selection/cart update path, scroll-event path, adjacent switch-table ownership, preview/equipment state writes, and child/base delegation, strengthening the class's main input behavior while helper names and final field layouts remain below the final-source C++ gate.
- 2026-06-05 A003 OnPaint refresh: Raised class completion/confidence from `76/84` to `80/85` with C++ still blank. Evidence: live IDA MCP refresh of the paint child [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md) confirms exact boundary, vtable-only placement, resource refs, global catalog/category reads, scrollbar/list-grid rendering, cart-highlight/icon/text drawing, and cleanup, making the class attachment to [UID:0000JE][FittingRoom](by-file/FittingRoom.md) conform to the 80%+ threshold while remaining below the final-source C++ gate.
- 2026-06-02 low-score child pass: Marked the class `RECONSTRUCTABLE:TRUE` and attached it to [UID:0000JE][FittingRoom](by-file/FittingRoom.md) so confirmed high-confidence child methods can attach to their class parent. C++ remains blank. Evidence: the page already has exact child method coverage through the list-pane constructor, scroll, paint, input, geometry, vector-helper, entry-release, and destructor blocks, and the fitting-room file page has a valid `NexusTK/cashshop/` reconstruction path with `87` confidence.
- 2026-05-30: Existing method table used address-only rows for constructor, resize, move, scroll update, scroll-position callback, reset, insert, and detach methods. Changed those rows to exact by-memory UID links and added the raw cleanup body at `0x0041ecc0-0x0041ecf5`. Evidence: IDA MCP function inventory/decompilation/xrefs/callees for `0x0041eb90-0x0041f2a6`, simroot names as leads, and byte review of the non-padding constructor tail.
- 2026-05-30: Existing method table still used address-only rows for paint, key-scroll, input, scroll-step, and hit-test methods. Changed those to exact by-memory UID links, added the `OnInputEvent` jump-table span, and added raw slot-geometry/layout helper pages through `0x00421301`. Evidence: IDA MCP function inventory, vtable data xrefs, byte/disassembly review for no-function raw helper starts, and `simroot_v2` method names used only as leads.
- 2026-05-30: Existing class documentation still treated the following `0x00421310-0x004216cb` island as unresolved/shared. Changed this page to link the exact fitting-room-owned entry release helpers and scalar deleting destructor, while warning that the same island also contains non-fitting-room string, checkbox, thunk, padding, and runtime/vector support. Evidence: IDA MCP decompilation, function inventory, vtable data refs, and byte audit for `0x00421310-0x004216cb`.
