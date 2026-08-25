*** UID:0000NF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScrollBar

## UID0000LO Gate 2A ScrollablePane Source Closure - 2026-08-14

The UID0000CF route now contributes ordinary ScrollablePane constructor,
destructor, SetSkinIndex, and six default scroll-metric definitions to
`ScrollBar.cpp`. Every remaining UID0001GL target has an exact per-address
no-code disposition; UID0001H6 separately excludes only compiler adjustors and
the deleting wrapper. `ScrollBar.h` retains the complete class declaration.
This closes the prior header-only K012 justification and raises the file from
`91/90` to `93/92`.

## Status

- Confidence: very strong for `ScrollPane`, `ScrollWidget`, and `ScrollablePane` generic infrastructure and for excluding the OptionPane-local CScrollBarBackPane family.
- Proposed module: `ui/core/ScrollBar.cpp`
- Historical generated-source leads, not current recovered sources: `source-3/simroot_v2/class_ScrollPane.cpp`, `class_ScrollWidget.cpp`, `class_ScrollablePane.cpp`, and `class_CScrollBarBackPane.cpp`. Treat these as stale lead material only; current ownership and emission use by-* docs, MCP evidence, and validator-generated output.
- Main address clusters: `0x0055c200-0x0055e65c`, `0x0055e660-0x0055f44f`, and `0x005654ec-0x00565608`.

## File Role

This module owns generic pane-level scrollbar infrastructure. `ScrollPane` is the visible scrollbar pane, `ScrollWidget` is a small target/enable state helper embedded by scroll users, and `ScrollablePane` wraps a content pane with optional horizontal and vertical `ScrollPane` children.

`CScrollBarBackPane` is excluded from this current source route. The former placement was based on name/visual similarity; exact NewOptionPane fields, inline construction, paired `120x5` layout, common deletion lifetime, drawing role, and code/RTTI adjacency route that support class through [UID:0000M7][OptionPane](by-file/OptionPane.md).

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScrollPane` | `0x0055c200-0x0055e65c` in separate method clusters | Visible scrollbar pane, first-draft `SetSkinIndex` at [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md), corrected Y-first `OnMouseEvent` at [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md), EPF/classic drawing at [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md), and a complete seven-method input/geometry split: [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) `HitTestPart`, [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) `GetScrollPartRect`, [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) `SetHighlightedPart`, [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) `BeginPartPress`, [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) `ProcessActivePart`, [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) `UpdatePositionFromCursor`, and [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) `ResetScrollState`. All exact bodies route through [UID:0000CM][ScrollPane](by-class/ScrollPane.md) `ScrollPane`; [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) is their non-emitting split index. |
| `ScrollWidget` | `0x0055c310-0x0055c3da` | Small clamped scroll target/enabled-state helper with notify callback, including first-draft `SetScrollCurrentValue` formal C++ on [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md). |
| `ScrollablePane` | `0x0055e660-0x0055f44f`, `0x005654ec-0x00565608` | Pane that owns horizontal/vertical `ScrollPane` children, destructor adjustor glue, and default virtuals. |
| `CScrollBarBackPane` (rejected historical placement) | `0x0053fea0-0x0053ff8d`, `0x00542680-0x005426d5`, vtable data `0x00621018-0x006210a0` | Not current ScrollBar contents. [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) and its exact constructor/destructor/OnPaint children route through OptionPane as NewOptionPane volume-slider support; this row preserves the former name-similarity hypothesis only as history. |
| Scrollbar size tables | [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) | Four exact `const int[3]` tables: current/classic vertical widths plus current/classic shared part extents. Three definitions are file-local; `kScrollPanePartExtentBySkin` is defined once here and declared in `ScrollBar.h` for specialized consumers. |
| base scroll vtables/constants | [UID:0003CK][0x00623d58-0x00623de0.ScrollPaneVtableData](by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md), [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md), [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) | Exact compiler-emitted base scroll vtable data and the file-level scrollbar dimension constants split out of the mixed scroll-pane `.rdata` island. |

## Ownership Decision

Keep this separate from [UID:0000MC][Pane](by-file/Pane.md). `Pane` owns base visibility, layers, events, and dirty regions; this module owns scrollbar-specific geometry, drawing, and scroll child layout.

Keep [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md) as a neighboring controls module rather than folding it into `ScrollBar.cpp`. It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), has control type `0x12`, and has broad dialog-level constructor fan-in.

Do not fold `TextEditPane` into this file. `TextEditPane` contains many scrollbar tracking variants, but it is a large rich text editor class. Its scroll methods consume `ScrollPane::GetScrollPartRect` rather than proving the entire editor belongs in scrollbar core.

## Evidence Notes

- `ScrollablePane::ScrollablePane` constructs two `ScrollPane` children: `new ScrollPane(1)` for horizontal and `new ScrollPane(0)` for vertical.
- IDA MCP reports six direct `ScrollablePane` constructor callers: `ChattingPane`, `FolderTreePane`, `ListPane`, `SystemMessagePane`, `OldSystemMessagePane`, and `TextEditPane`.
- `ScrollPane::OnDraw` renders classic `SCRL001.EPD`/`SCRL001.PAD` assets and newer EPF assets such as `SLIDEBG.EPF`, `SCRBUTT.EPF`, `SLIDEBG.PAL`, and `BUTTON.PAL`.
- `ScrollPane::GetScrollPartRect` has 15 direct call references, including calls from `ScrollPane::OnDraw` and nearby `TextEditPane` scrollbar handlers.
- `ScrollWidget` metadata says the recovered subset proves a notify callback at `+0x20`, position/target state, and an enabled flag; the class sits in the same address neighborhood as `ScrollPane`.
- 2026-06-03 IDA MCP recheck corrects the local input-core method ends to half-open ranges, exposes raw setter-shaped bodies at `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370`, and confirms `ScrollWidget` callers from `ScrollablePane` synchronization and `ChattingHandlePane` enable/disable paths.
- `CScrollBarBackPane` has two excluded adjustor thunk methods at `0x0054259f` and `0x005425aa`, now documented inside [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md).
- 2026-06-01 IDA MCP recheck: `CScrollBarBackPane` core contains constructor bytes at `0x0053fea0-0x0053fed2`, internal `0xcc` alignment at `0x0053fed2-0x0053fee0`, cleanup helper `sub_53FEE0` at `0x0053fee0-0x0053feff`, and draw method `sub_53FF00` at `0x0053ff00-0x0053ff8d`.
- 2026-06-01 IDA MCP recheck: `sub_53FF00` is referenced from vtable/data slot `0x00621060`; scalar deleting destructor `sub_542680` is referenced from `0x0062101c` and from adjustor jumps at `0x005425a5`/`0x005425b0`; adjustor thunks are referenced from secondary table slots `0x00621068` and `0x00621098`.
- 2026-06-01 IDA MCP recheck: `0x0062101c` is the primary `CScrollBarBackPane` vtable base, referenced by constructor write `0x0053feb1`, cleanup helper write `0x0053fee0`, NewOptionPane-adjacent code at `0x005400fc`/`0x00540147`, and destructor write `0x00542686`.
- 2026-06-12 A004 Goal 2 split [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md) as the exact `CScrollBarBackPane` vtable/RTTI child: primary base `0x0062101c`, secondary base `0x00621068`, tertiary base `0x00621098`, and successor `NewOptionPane` locator/base at `0x006210a0/0x006210a4`.
- Historical 2026-06-25 state: B003 routed the `CScrollBarBackPane` deleting wrapper through this file while resolving Pane teardown and compiler adjustors. The 2026-07-29 UID0001DV closure supersedes only that source placement: wrapper behavior remains valid compiler evidence, but [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md), [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md), and [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md) now route through OptionPane.

## 2026-07-29 CScrollBarBackPane Exclusion Closure

- [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) is a NewOptionPane-local volume-slider backplate, not generic scrollbar infrastructure. NewOptionPane owns two objects at `+0x12cc/+0x12d0`, constructs both with `Pane(true)` semantics, lays each out at `120x5` beside music/sound ScrollVolumePane controls, and shares their deletion lifetime.
- Exact [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md) OnPaint geometry draws a minus sign, three-line groove, and plus sign through `GrafPort::MoveTo` and typed `g_pfnDrawLineDelta`; that local UI role does not create a ScrollPane/ScrollWidget/ScrollablePane dependency.
- CScrollBarBackPane code/RTTI appears immediately before NewOptionPane, while generic ScrollBar implementation lives in the separate `0x0055c200-0x0055f44f` and `0x005654ec-0x00565608` families. No generic construction, data, layout, lifetime, or call route reaches the backplate class.
- Current CScrollBarBackPane source routes through [UID:0000M7][OptionPane](by-file/OptionPane.md) OptionPane: exact constructor [UID:0004Y8][0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md), ordinary destructor [UID:0004Y9][0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor](by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md), OnPaint [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md), scalar compiler evidence [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md), and vtable/RTTI evidence [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md).
- Historical `cleanup helper`, `DrawScrollBarBackPattern`, raw drawing names, and current-ScrollBar ownership remain preserved in the earlier dated evidence but are rejected by the complete source-quality pass. Generic ScrollPane, ScrollWidget, ScrollablePane, constants, vtables, and unrelated themed-scroll evidence remain unchanged.
- `ScrollCollectionPane` and `ScrollNewGroupPane` share the same pane-derived themed-scrollbar layout pattern and EPF-backed input/paint helpers, but current evidence keeps them as sibling themed scrollbar classes rather than merging them into the older `ScrollPane` core.
- 2026-05-28 IDA MCP boundary review corrected `ScrollPane::OnScrollTimer` to end at `0x0055c643`, `ScrollPane::OnDraw` to end at `0x0055d957`, and `ScrollablePane` destructor/defaults to cover `0x005654ec-0x00565608`.
- 2026-06-11 A001 Batch 224 live IDA MCP verified the base `.rdata` route: `0x00623d58 -> ??_R4ScrollPane@@6B@`, `0x00623d5c -> ??_7ScrollPane@@6B@` with constructor store `0x0055c251`, `0x00623de0 -> ??_R4ScrollablePane@@6B@`, `0x00623de4 -> ??_7ScrollablePane@@6B@` with stores at `0x0055e69f`, `0x0055e789`, and `0x0056551c`, plus the scrollbar constants at `0x00624138-0x00624168`.
- 2026-06-12 A005 Batch245 live IDA MCP reconfirmed the late `ScrollPane` input/geometry helper cluster [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) and corrected [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) to IDA size `0x4b9` / 1209 bytes, so this file now records the generic ScrollPane code span through `0x0055e65c`.
- 2026-06-16 B001 confirms `ScrollablePaneCore` should route through the class [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) and then this source file. `0x0055f250-0x0055f44f` is not a spell-inventory predecessor or TextEditPane fragment; it is an internal helper called from `ScrollablePane` synchronization/layout paths.
- 2026-06-17 B002 confirms [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) should direct-own/emit through [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md), with this file only as source-file ancestor. The late island contains `ScrollablePane` destructor adjustor thunks, the scalar deleting destructor wrapper, and six primary scroll-metric default slots, not `ScrollBar` class body code.
- `ScrollablePane` field layout uses `m_horizontalScrollBarOffset` at `+0x100`, `m_verticalScrollBarOffset` at `+0x104`, and `m_scrollBarInset` at `+0x108`. [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md) initializes the inherited vertical offset to `63`; [UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) assigns `49` to that same inherited field for the EPF-backed UserLook legend view. These independent consumers supersede the historical generic `m_displayMode` placeholder and do not change source ownership or file score.
- 2026-06-26 B004 confirms [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) is now a non-emitting split index. Exact `ScrollPane` children [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md), [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md), [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md), [UID:000432][0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md), [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md), [UID:000434][0x0055c600-0x0055c605.ScrollPaneCanScroll](by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md), and [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md) route through [UID:0000CM][ScrollPane](by-class/ScrollPane.md); exact `ScrollWidget` children [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md), [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md), [UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md), and [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) route through [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md). Formal C++ is present on the constructor, UID00042W skin-index setter, UID000433 EventHandler-adjusted mouse handler, UID00042Z current setter, enable/disable, visibility predicate, default false virtual, and timer callback children; [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) remains no-body but has a formal comment-only marker under `NC-03-current`.
- 2026-06-29 B006 confirms [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) was the generated `ScrollBar.cpp` empty-emitter row because it was reconstructable and routed through [UID:0000CM][ScrollPane](by-class/ScrollPane.md) with a blank formal C++ block. Current MCP session `b6b3c97e` reconfirms no function object, zero direct xrefs, zero VA/RVA pointer hits, exact `+0xfa` compare/write/invalidate behavior, decompile/callee failure, and byte-verified padding. B010 strengthens `+0xfa` as `m_scrollStyle` / the classic fallback style byte, but no source-facing setter route is proven, so the target carries a formal no-body marker rather than a guessed standalone setter body. File score remains `89/85`.
- 2026-06-29 B001 confirms [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md) was the generated `ScrollBar.cpp` empty-emitter row because it was reconstructable and routed through [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md) with a blank formal C++ block. Current MCP session `b6b3c97e` reconfirms no function object at `0x0055c370`, zero direct xrefs, zero VA/RVA pointer hits, exact 39-byte `+0xfe` compare/write/invalidate body, byte-verified padding at `0x0055c36b-0x0055c370` and `0x0055c397-0x0055c3a0`, and sibling [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md) evidence for `m_currentPosition` and inherited `InvalidateRect(&m_bounds)`. B004 `NC-05` is now historical split-pass context; UID00042Z emits first-draft `SetScrollCurrentValue(short currentPosition)` while no-route/no-original-name facts remain score caps. File score remains `89/85`.
- 2026-06-29 B004 confirms [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) was the generated `ScrollBar.cpp` empty-emitter row because it was reconstructable and routed through [UID:0000CM][ScrollPane](by-class/ScrollPane.md) with a blank formal C++ block. Current MCP session `b6b3c97e` reconfirms no function object at `0x0055c2b0`, zero direct xrefs, zero VA/RVA pointer hits, exact 39-byte `+0xf8` compare/write/invalidate body, byte-verified padding at `0x0055c2a1-0x0055c2b0` and `0x0055c2d7-0x0055c2e0`, and `ScrollPane::OnDraw` / `ScrollPane::GetScrollPartRect` table-index evidence for `m_scrollSkinIndex`. UID00042W now emits first-draft `ScrollPane::SetSkinIndex(unsigned short skinIndex)` while no-route/no-original-name facts remain score caps. File score remains `89/85`.
- 2026-06-26 B010 confirms the generic [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md) draw virtual now has first-draft formal C++ under this source-file route through [UID:0000CM][ScrollPane](by-class/ScrollPane.md). The draw body remains generic scrollbar infrastructure: vtable slot `0x00623da0`, EPF/classic branches gated by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), `SLIDEBG`/`SCRBUTT` and `SCRL001` resources, shared scrollbar constants [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md), and [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) / [UID:000432][0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md) dependencies. Similar themed scroll draw code in FittingRoom remains a separate class/source route and should not be folded into this file solely because it shares art/helper families.
- 2026-06-29 B009 confirms the generic [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) geometry method now has first-draft formal C++ under the same generic scrollbar route through [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) and [UID:0000CM][ScrollPane](by-class/ScrollPane.md). The method remains core `ScrollPane` infrastructure, not `TextEditPane`: restored MCP session `B006_0002F1_20260629` reconfirmed the `0x4b9` range, half-open endpoint, padding, 15 direct callers, and constant bytes; the target page resolves EPF/classic horizontal/vertical formulas, `m_scrollSkinIndex`, `m_thumbDragActive`, `kScrollPanePartExtentBySkin`, and `kClassicScrollPanePartExtentBySkin`.
- 2026-07-29 B005 split [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) into six newly registered exact children and rerouted existing [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) directly through [UID:0000CM][ScrollPane](by-class/ScrollPane.md). The seven methods share a signed one-byte `ScrollPanePart` contract and Y-first local coordinates, while [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) now remains only a reviewed non-emitting address/index page. The exact method bodies and first-draft source are [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md), [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md), [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md), [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md), [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md), [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md), and [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md). That dated split left the file at `91/90`; the current file score is `93/92`, and unrelated ScrollWidget/ScrollablePane/CScrollBarBackPane conclusions remain unchanged.

## 2026-07-01 B007 Generated-Output Audit

Validator-generated `auto-generated/NexusTK/ui/core/ScrollBar.cpp` header at report time:

```text
validator-command-id: 000000003290
validator-refreshed-at: 2026-07-01T04:46:53-04:00
source by-file UID: 0000NF
```

Tracker context at report time: [UID:0000NF] `ScrollBar` had 26 total emitters, 13 filled, 13 empty, and 50.0% generated coverage. The filled outputs were `0001E3` CScrollBarBackPane scalar deleting destructor comment-only marker; `00042V` `ScrollPane` constructor; `00042W` `ScrollPane::SetSkinIndex(unsigned short skinIndex)`; `00042X` formal comment-only raw byte-state setter marker; `000432` `ScrollPane::IsScrollThumbVisible()`; `000434` `ScrollPane::CanScroll(int)` false default; `000435` `ScrollPane::OnTimer(...)`; `0001GI` `ScrollPane::OnDraw()`; `0001GK` `ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)`; `00042Y` `ScrollWidget::SetScrollTargetValue(short targetPosition)`; `00042Z` `ScrollWidget::SetScrollCurrentValue(short currentPosition)`; `000430` `ScrollWidget::Enable()`; and `000431` `ScrollWidget::Disable()`.

The thirteen empty markers were triaged as follows:

| UID | Disposition |
| --- | --- |
| `00003D` | `CScrollBarBackPane` is a class route page. It now carries a formal comment marker; exact constructor, draw, destructor, and vtable output belongs to child pages. |
| `0001DV` | `CScrollBarBackPaneCore` is an aggregate over constructor bytes, cleanup glue, and draw behavior. It now carries a formal aggregate no-code marker. |
| `0003LR` | `CScrollBarBackPaneVtableData` is compiler-generated RTTI/vtable data. It now has a nonblank item summary and a formal no-handwritten-table marker. |
| `0000CM` | `ScrollPane` is a class route page. Exact constructor, draw, geometry, input, timer, and raw-state output belongs to child pages. |
| `000433` | `ScrollPaneHandleMouseEvent` is a source-authored 511-byte EventHandler-adjusted body. It now emits first-draft `bool ScrollPane::OnMouseEvent(const PaneMouseEvent& event)`. |
| `0003A5` | Historical 2026-07-01 state called this an aggregate with unsplit helpers. Current 2026-07-29 state is a reviewed non-emitting split index: six newly registered exact children plus directly class-routed [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) emit the seven methods separately. |
| `0003CK` | `ScrollPaneVtableData` is compiler-generated RTTI/vtable data and now carries a formal no-handwritten-table marker. |
| `0000CP` | `ScrollWidget` is a class route page. Exact target/current/enable/disable bodies emit through child pages. |
| `0000CF` | `ScrollablePane` is a class route page. Core/default/vtable detail lives on exact child pages. |
| `0001GL` | `ScrollablePaneCore` is a multi-method class cluster whose formal CPP now includes constructor/destructor/SetSkinIndex plus exact `SetScrollbarsVisible(bool)`; remaining rows retain per-range no-code dispositions. |
| `0001H6` | `ScrollablePaneVirtualDefaults` mixes adjustor thunks, scalar deleting destructor glue, and default metric bodies; it now carries a formal no-handwritten-aggregate marker. |
| `0003CL` | `ScrollablePaneVtableData` is compiler-generated RTTI/vtable data. It now has a nonblank item summary and a formal no-handwritten-table marker. |
| `0003CQ` | `ScrollPaneScrollbarConstantData` is file-level source constant data. It now emits four first-draft three-entry extent table declarations. |

B007 accepted route decisions preserve this page as the file root [UID:0000NF], class routes [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md), [UID:0000CM][ScrollPane](by-class/ScrollPane.md), [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md), and [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md), nested helper route [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md), generated path `NexusTK/ui/core/ScrollBar.cpp`, and direct source constants child [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md). Broad by-file/class pages intentionally emit route comments only because exact source bodies belong to child method/data pages; compiler vtable pages emit formal comments because MSVC regenerates those bytes from declarations.

## Cross-References

- [UID:0000CM][ScrollPane](by-class/ScrollPane.md)
- [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) (rejected historical route; current owner file is UID0000M7)
- [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)
- [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md)
- [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md)
- [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md)
- [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md)
- [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md)
- [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md)
- [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md)
- [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md)
- [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md)
- [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md)
- [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md)
- [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md)
- [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md)
- [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md)
- [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md)
- [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md)
- [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md)
- [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md)
- [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md)
- [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md)
- [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)

## 2026-07-30 Shared Scrollbar Constant Source Contract

[UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) is the sole source-data owner for four contiguous 12-byte arrays at `0x00624138-0x00624168`. Current MCP bytes and 36 direct head xrefs resolve their source-facing roles:

- `kScrollPaneWidthBySkin[3] = {13,13,13}` is the current/EPF vertical scrollbar width table;
- `kScrollPanePartExtentBySkin[3] = {38,38,38}` is the current/EPF fixed button/thumb/part extent and horizontal layout thickness;
- `kClassicScrollPaneWidthBySkin[3] = {13,12,12}` is the classic vertical scrollbar width table;
- `kClassicScrollPanePartExtentBySkin[3] = {13,10,10}` is the classic fixed button/thumb/part extent and horizontal layout thickness.

All four use three 32-bit signed integer elements. The two current IDA half-word heads and optimizer-narrowed loads in `ScrollablePane_LayoutScrollbars` do not describe source width: raw storage, scale-four indexing, full-dword paint/geometry loads, and exact 12-byte fences establish `const int[3]`.

The first, third, and fourth arrays are used only inside generic `ScrollBar.cpp` and remain `static const`. The `0x624144` table is used from accepted `ScrollBar.cpp`, `ScrollCollectionPane.cpp`, and `Group.cpp` routes. It therefore has one external definition in `ScrollBar.cpp` and `extern const int kScrollPanePartExtentBySkin[3];` in `ScrollBar.h`. `ScrollBar.cpp` includes its own header before child definitions so that the declaration governs the definition. Specialized files include that header and must not create private forward declarations or duplicate definitions.

The source placement is evidence-driven rather than proximity-driven. Generic `ScrollablePane_LayoutScrollbars` consumes all four; generic `ScrollPane` consumes both part-extent tables; ScrollSpellInventoryPane, ScrollNewGroupPane, ScrollCollectionPane, and ScrollInventoryPane consume the current table. This cross-family graph confirms file-level ScrollBar ownership and rejects specialized-class ownership, a new constants module, and duplicate per-file arrays.

The completed [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) source includes `../core/ScrollBar.h` and consumes `kScrollPanePartExtentBySkin` in `ScrollInventoryPane::GetPartRect` and `ScrollInventoryPane::UpdatePositionFromCursor`. This is a dependency edge only: `ScrollBar.cpp` remains the sole definition owner, `ScrollBar.h` remains the sole external declaration owner, and `InventoryScrollPane.cpp` must not duplicate the table or add a private forward declaration.

Historical B007 names `kScrollablePaneEpfVerticalScrollbarWidthBySkin`, `kScrollablePaneEpfHorizontalScrollbarHeightBySkin`, `kScrollablePaneLegacyVerticalScrollbarWidthBySkin`, and `kScrollablePaneLegacyHorizontalScrollbarHeightBySkin` remain useful as the first empty-emitter source hypothesis but are superseded. `HorizontalScrollbarHeight` was too narrow for the broad part/thumb geometry contract, `ScrollablePane` was too class-specific for generic and specialized users, and `Classic` is the accepted project spelling for the alternate asset branch. The current score of this file is `93/92`; this support synchronization does not alter unrelated source-family conclusions.

## 2026-07-30 UID0002MZ Complete Source-Root Assembly Contract

This direct by-file page remains a generated source root and therefore does not carry child-style `RECONSTRUCTION_CPP` or `RECONSTRUCTION_H` metadata. Its accepted destination-ready `NexusTK/ui/core/ScrollBar.cpp` assembly contract is:

```cpp
#include "ScrollBar.h"

[[CHILDREN]]
```

Its accepted destination-ready `NexusTK/ui/core/ScrollBar.h` assembly contract is:

```cpp
#ifndef NEXUSTK_UI_CORE_SCROLLBAR_H
#define NEXUSTK_UI_CORE_SCROLLBAR_H

#include "Pane.h"
#include "RectBounds.h"

[[CHILDREN]]

#endif
```

The wrapper is emitted exactly once across the ordered class fragments: [UID:0000CM][ScrollPane](by-class/ScrollPane.md) opens the guard, includes complete `Pane.h` and `RectBounds.h`, and emits the `ScrollPane` declaration; [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) follows with the `ScrollablePane` declaration and closes the guard. The second fragment therefore has no late duplicate Pane include, incomplete `Point` declaration, or redundant `ScrollPane` forward declaration. The literal `[[No Children Attached]]` token is not source and must not appear in either assembled file. The normal child markers remain so the complete `ScrollPane`, `ScrollWidget`, and `ScrollablePane` declarations and their exact by-memory method children assemble through this file root. No force-include shim or duplicate local rectangle declaration is part of the source model.

## Changes

- 2026-08-16 B001 UID0002NC support callback:
  - Preserved the `93/92` file score and existing `NexusTK/ui/core/ScrollBar.cpp/.h` route.
  - UID0000CM H now defines inline `ScrollPane::SetScrollStyle(unsigned char)` after `SetSkinIndex`; it uses existing `m_scrollStyle`, inherited `m_visibleBounds`, and `InvalidateRect` with no new include, field, slot, or duplicate CPP body.
  - UID0000CF H now declares `SetScrollbarsVisible(bool)` after `SetSkinIndex`; UID0001GL CPP owns the sole body at `[0x0055e840,0x0055e897)`, horizontal then vertical with independent null checks and child inline calls.
  - UID00042X remains the exact retained out-of-line compiler copy of the inline style setter and emits only its one-definition disposition. Existing `#include "ScrollBar.h"` ordering makes ScrollPane visible before ScrollablePane; no facade or additional dependency is introduced.

- 2026-08-15 B005 UID0000KB support callback: preserved the accepted shared-constant contract at the current `93/92` file score; added the finalized `InventoryScrollPane.cpp` consumer route through `ScrollBar.h`, explicitly rejected a duplicate inventory-local definition or forward declaration, and completed coherent consumer CPP/H verification under validator command `000000024570`.

- 2026-07-30 B002 UID0003CQ support callback: replaced the narrow four-static constants inventory with exact current/classic width/part-extent names; recorded 32-bit/count proof, generic and specialized ownership evidence, three-file-local/one-shared linkage, the required ScrollBar header declaration/include contract, rejected duplicate/specialized/new-module alternatives, and historicalized the B007 names. At that dated checkpoint file metadata was `91/90`; the current score is `93/92`.

- 2026-07-29 B005 UID0003A5 implementation callback:
  - At that dated checkpoint, preserved `91/90`, `NexusTK/ui/core/`, and all unrelated source-family conclusions; the current score is `93/92`.
  - Reconciled the stale aggregate/unsplit-helper wording to a non-emitting [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) index plus seven direct `ScrollPane` method children with exact formal bodies, signed-byte part contract, and Y-first geometry/input order.

- 2026-07-29 B007 accepted UID0001DV callback:
  - Raised `90/87 -> 91/90` after resolving the remaining CScrollBarBackPane source-placement uncertainty.
  - Removed CScrollBarBackPane ranges from current file contents while preserving their earlier evidence as rejected history; exact class/method/scalar/vtable routes now point to OptionPane.
  - Left all generic ScrollPane/ScrollWidget/ScrollablePane content, ranges, constants, source, and open questions unchanged.

- 2026-07-20 B002 UID0003RM bounded support synchronization:
  - Added the exact `ScrollablePane` `+0x100/+0x104/+0x108` field layout and the independent `LegendPane` value `63` / `UserLookPane::ShowLegendView` value `49` consumers of `m_verticalScrollBarOffset`.
  - Historicalized `m_displayMode` as a rejected placeholder while preserving `90/87`, file ownership, source path, and all unrelated scrollbar-family evidence.
- 2026-05-28: Changed `CScrollBarBackPane` core end from `0x0053ff8c` to `0x0053ff8d`.
  - Before: the file candidate stopped before the final `ret` byte of the draw helper.
  - After: the file candidate includes the full `DrawScrollBarBackPattern` helper.
  - Evidence: IDA MCP reports `sub_53FF00` as `0x0053ff00-0x0053ff8d`; bytes after that end are padding before `NewOptionPane`.
- 2026-05-28: Changed `CScrollBarBackPane` destructor end from `0x005426d4` to `0x005426d5`.
  - Before: the file candidate omitted the final byte of the scalar deleting destructor wrapper.
  - After: the file candidate includes the full wrapper and points excluded adjustor thunks to the shared thunk island.
  - Evidence: IDA MCP reports `sub_542680` as `0x00542680-0x005426d5`; related adjustor thunks live in [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md).
- 2026-05-28: Corrected ScrollPane/ScrollablePane boundary endpoints.
  - Before: `ScrollPaneInputCore`, `ScrollPaneOnDraw`, and `ScrollablePaneVirtualDefaults` used `0x0055c642`, `0x0055d956`, and `0x00565510-0x00565607`.
  - After: the file doc uses corrected owner ranges `0x0055c200-0x0055c643`, `0x0055c650-0x0055d957`, and `0x005654ec-0x00565608`.
  - Evidence: IDA MCP reports the final bytes of `OnScrollTimer`, `OnDraw`, and `IsScrollable`, plus two `ScrollablePane` destructor adjustor thunks at `0x005654ec` and `0x005654f7`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers scrollbar class family contents, ownership decisions, IDA evidence, boundary corrections, sibling-class exclusions, and cross-references; confidence remains capped by whether `CScrollBarBackPane` was originally in the same source file.
- 2026-06-01: Changed `PROPOSED_RECONSTRUCTION_PATH` from blank to `NexusTK/ui/core/`, raised completion/confidence from `86/80` to `88/82`, and added current `CScrollBarBackPane` IDA evidence.
  - Before: the page had a proposed module but no validator path, and the CScrollBarBackPane child evidence missed the local cleanup helper.
  - After: the source path is explicit and child pages can attach to this file; final source remains deferred because helper names and `CScrollBarBackPane` file placement are not final-audit quality.
- 2026-06-03: Attached core scroll class pages and corrected ScrollWidget local ranges.
  - Before: `ScrollPane`, `ScrollWidget`, and `ScrollablePane` class pages were listed here but unassigned in autogen metadata, and `ScrollWidget` method ranges omitted return bytes.
  - After: attached [UID:0000CM][ScrollPane](by-class/ScrollPane.md), [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md), and [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) to this file; C++ remains blank for all.
  - Evidence: IDA MCP `py_eval` on 2026-06-03 confirms the input-core function boundaries, raw setter bodies, `ScrollablePane` callers, `ChattingHandlePane` enable/disable callers, and notification callback pattern.
- 2026-06-11 A001 Batch 224 parent-gate refresh:
  - Before: `88/82`; the file documented the core scrollbar family but confidence was below the strict direct-parent gate for newly split base scroll `.rdata` children.
  - After: `89/85`; no C++ emitted.
  - Evidence: live IDA reconfirmed exact base `ScrollPane` and `ScrollablePane` vtable child boundaries/stores plus the file-level scrollbar constant child. This resolves the parent-side gate for [UID:0003CK][0x00623d58-0x00623de0.ScrollPaneVtableData](by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md), [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md), and [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md).
- 2026-06-12 A005 Batch245:
  - Before: the file still showed the generic `ScrollPane` code cluster ending at the stale `0x0055de98` boundary.
  - After: score unchanged at `89/85`; updated `ScrollPane` span to `0x0055c200-0x0055e65c`, added [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md), and corrected [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) links to `0x0055de99`.
  - Evidence: live IDA reconfirmed the seven-function input/geometry helper cluster and the corrected `ScrollPaneGetScrollPartRect` half-open end from IDA function size `0x4b9`.
- 2026-06-12 A004 Goal 2:
  - Before: `CScrollBarBackPane` vtable evidence was present, but the exact `.rdata` child was still implicit inside a mixed option/macro/profile aggregate.
  - After: score unchanged at `89/85`; added [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md) as the exact vtable/RTTI child and documented the direct class-parent gate.
  - Evidence: live IDA confirmed the table bases, slot refs, successor boundary, and `CScrollBarBackPane` class score `86/88`, so core/destructor/vtable children can route to the class while this file remains their source-file ancestor.
- 2026-06-25 B003 CScrollBarBackPane destructor implementation callback:
  - Before: this file kept `CScrollBarBackPane` in the ScrollBar source route but did not record the accepted deleting-destructor source policy.
  - After: source placement remains `NexusTK/ui/core/ScrollBar`; [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md) is documented as compiler-generated wrapper glue covered by the `CScrollBarBackPane` class/declaration route and a comment-only emitted marker, not a handwritten `ScrollBar.cpp` function body.
- 2026-06-16 B001 ScrollablePane core audit executed by supervisor:
  - Before: the file still showed `ScrollablePane` core ending at `0x0055f242`.
  - After: the file records `ScrollablePane` core through `0x0055f44f`; score unchanged at `89/85`.
  - Evidence: B001 live IDA MCP and raw PE audit proved `0x0055f250-0x0055f44f` is a `ScrollablePane` internal viewport/content recompute helper called by synchronization/layout code, with the next unrelated `ScrollSpellInventoryPane` function starting at `0x0055f450`.
- 2026-06-17 B002 ScrollablePane virtual-default audit executed by supervisor:
  - Before: the file-level doc still treated [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) as a direct ScrollBar-owned late island.
  - After: score unchanged at `89/85`; the doc records that [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) routes through [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) while remaining in this source-file grouping.
  - Evidence: B002 PE/vtable audit of the `ScrollablePane` destructor/default virtual island and [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md).
- 2026-06-26 B004 ScrollPaneInputCore implementation callback:
  - Before: [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) still routed as a reconstructable file-level blank emitter through this page.
  - After: score unchanged at `89/85`; [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) is documented as a non-emitting split index while exact `ScrollPane` and `ScrollWidget` children route through their class pages and selected child formal C++ blocks. This file remains the common source-file ancestor.
  - Evidence: accepted B004 report and child pages [UID:00042V][0x0055c200-0x0055c2a1.ScrollPaneConstructor](by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md) through [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md).
- 2026-06-26 B010 ScrollPaneOnDraw implementation callback:
  - Before: this file recorded `ScrollPane::OnDraw` as generic scrollbar drawing but did not record the accepted first-draft C++ readiness or the rejected FittingRoom ownership boundary.
  - After: score unchanged at `89/85`; [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md) remains routed through [UID:0000CM][ScrollPane](by-class/ScrollPane.md) and this file, with formal draw C++ in the target page.
  - Evidence: B010 MCP-backed report records vtable-only route `0x00623da0`, exact range and padding, EPF/classic resources, shared constants, normalized renderer/resource helper roles, and rejected FittingRoom/TextEditPane/Surface owner alternatives.
- 2026-06-29 B006 UID00042X empty-emitter implementation callback:
  - Before: this file grouped [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) with blank raw/no-route setters, leaving it as an empty emitter in generated `auto-generated/NexusTK/ui/core/ScrollBar.cpp`.
  - After: score unchanged at `89/85`; [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) remains a no-standalone-body raw `ScrollPane` child under this source-file route, but its target page now carries a formal comment-only marker to clear the empty-emitter row. At that point [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) still remained blank under its separate no-code proof and [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md) was still blank; those historical states are superseded by the later B004 UID00042W and B001 UID00042Z callbacks.
  - Evidence: accepted B006 report, current MCP session `b6b3c97e`, target score `86/88`, and B010 `+0xfa` draw-state evidence.
- 2026-06-29 B001 UID00042Z empty-emitter implementation callback:
  - Before: this file still described [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md) as blank under B004 `NC-05`, leaving a generated `ScrollBar.cpp` empty-emitter marker.
  - After: score unchanged at `89/85`; historical `simroot_v2` source paths are explicitly marked as stale generated-source leads; UID00042Z now emits first-draft `ScrollWidget::SetScrollCurrentValue(short currentPosition)` through [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md) and this source-file route.
  - Evidence: accepted B001 report, current MCP session `b6b3c97e`, exact UID00042Z raw body and padding bytes, sibling current-field/invalidation evidence, and generated empty-emitter cause.
- 2026-06-29 B004 UID00042W empty-emitter implementation callback:
  - Before: this file still described [UID:00042W][0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) as blank under `NC-02`, leaving a generated `ScrollBar.cpp` empty-emitter marker.
  - After: score unchanged at `89/85`; UID00042W now emits first-draft `ScrollPane::SetSkinIndex(unsigned short skinIndex)` through [UID:0000CM][ScrollPane](by-class/ScrollPane.md) and this source-file route, and `m_scrollSkinIndex` replaces historical `m_trackStateWord` wording for the `+0xf8` table-index field.
  - Evidence: accepted B004 report, current MCP session `b6b3c97e`, exact UID00042W raw body and padding bytes, `ScrollPane::OnDraw` / `GetScrollPartRect` field consumers, and generated empty-emitter cause.
- 2026-06-29 B009 UID0001GK empty-emitter implementation callback:
  - Before: this file listed UID0001GK as the hit part rectangle calculation but did not record its source-ready formal C++ body, leaving it as an empty-emitter row in generated `ScrollBar.cpp`.
  - After: score unchanged at `89/85`; UID0001GK now emits first-draft `ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)` through the existing generic `ScrollPane`/`ScrollBar` route while preserving TextEditPane as consumer-only and keeping shared constants under this file-level constants child.
  - Evidence: accepted B009 report, restored MCP session `B006_0002F1_20260629`, target metadata `89/91`, formal geometry C++ insertion, exact caller/range/padding evidence, and rejected TextEditPane/ScrollWidget/ScrollablePane/private-constants ownership alternatives.
- 2026-07-01 B007 ScrollBar empty-emitter family implementation callback:
  - Before: generated `auto-generated/NexusTK/ui/core/ScrollBar.cpp` had 13 remaining empty markers under validator command `000000003290`, and this file was scored `89/85`.
  - After: raised file score to `90/87`, added the generated-output audit above, cleared class/aggregate/vtable route pages with formal comment markers, inserted first-draft `ScrollPane::OnMouseEvent` on UID000433, and inserted four file-level scrollbar extent table declarations on UID0003CQ.
  - Evidence: accepted B007 report `0000NF-ScrollBar-empty-emitter-family-source-quality.md`, current MCP evidence for UID000433 and UID0003CQ, and scoped validators with `--wait-generated`.
