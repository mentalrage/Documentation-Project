*** UID:0000BN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

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
| `SetScrollPosition` | `0x0045b200-0x0045b24c` | Stores scroll position, syncs child scrollbar, and invalidates owner. |
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

- Current generated source also emits generic drawing functions such as `SetTextColor`, `GetClipRect`, `DrawRectFrame`, `DrawTiledBackground`, RLE blitters, palette helpers, and line/pixel helpers in the `0x004b9690+` range. `0x004b9690` is now documented as a [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), `0x004b96c0` as a [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md), `0x004ba450` as [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), and `0x004ba6b0` as [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md). These are not ranking-owned and should remain in shared rendering/UI drawing modules.
- Current generated source also emits `DrawOutlinedText` at `0x004bacd0`, but IDA reports 31 direct callers and the body only offsets GrafPort cursor/color state before calling `DrawWideText`. Treat it as part of [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), not ranking-owned code.
- Current generated source also emits `ClipLine` at `0x004bb2e0`, but IDA caller checks show it is only used by the software line callbacks at `0x004bb9b0` and `0x004c0850`. Treat it as [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md), not ranking-owned code.
- Current generated source also emits large software-render callback targets at `0x004bb8d0+` and `0x004c0770+`. These are now documented as [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md), not ranking-owned code.
- The list pane accesses [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) for category collection and selected category state.
- IDA confirms `RankingEventListPane` primary, secondary, and tertiary vtables at `0x00610ad4`, `0x00610b3c`, and `0x00610b6c`; current generated metadata still reports `vtable_count: 0`.
- The tertiary table ends after `+0x04`. The following UTF-16 `SUBWIN.EPF` / `SUBWIN.PAL` strings are resource data, not additional virtual slots.
- 2026-05-26 IDA `py_eval` recheck confirms ranking-owned function boundaries from constructor `0x0045ae30-0x0045af2c` through scalar deleting destructor `0x0045be00-0x0045be67`, including paint `0x0045b2e0-0x0045b44c`, event handler `0x0045b460-0x0045b628`, and card drawing `0x0045b630-0x0045bcf7`. It also reconfirms vtable bases `0x00610ad4`, `0x00610b3c`, and `0x00610b6c` with constructor/destructor stores.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000Y8][0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/84`.
  - Before: page documented list-pane behavior, method boundaries, vtables, and generic rendering-helper pollution but remained unevaluated.
  - After: score reflects documented construction, resize/origin/scroll synchronization, paint, event handling, item drawing, destructor glue, and rendering-helper exclusions.
  - Evidence: linked ranking aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) and render-helper references record IDA-confirmed function boundaries, vtable bases/stores, and non-ranking helper ownership.
