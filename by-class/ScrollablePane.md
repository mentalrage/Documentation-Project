*** UID:0000CF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScrollBar.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScrollablePane : public Pane
{
public:
    ScrollablePane(bool horizontalScrollEnabled,
                   bool verticalScrollEnabled);
    virtual ~ScrollablePane();

    virtual short GetScrollRange(char axis);
    virtual short GetOverflowCount(char axis);
    virtual short GetPageSize(char axis);
    virtual short GetScrollOffset(char axis, short units);
    virtual Point *GetContentSize(Point *outSize);
    virtual Point *GetScrollDelta(Point *outDelta, char axis,
                                  short oldPosition, short newPosition);

    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollbarsVisible(bool visible);
    void SetScrollTargetValue(short targetPosition, char axis);
    void SetScrollCurrentValue(short currentPosition, char axis);
    short GetScrollMax(char axis) const;
    short GetScrollPosition(char axis) const;
    void SyncScrollbars();
    void ApplyScrollPosition(char axis, unsigned short oldPosition,
                             unsigned short targetPosition);
    void LayoutScrollbars();

protected:
    ScrollPane *m_horizontalScrollPane;
    ScrollPane *m_verticalScrollPane;
    int m_horizontalScrollBarOffset;
    int m_verticalScrollBarOffset;
    int m_scrollBarInset;
    bool m_horizontalScrollEnabled;
    bool m_verticalScrollEnabled;
    RectBounds m_contentRect;
    RectBounds m_scrollContentRect;
};

typedef char ScrollablePaneSizeMustBe304[
    sizeof(ScrollablePane) == 0x130 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollablePane

## UID0000LO Gate 2A CPP Closure - 2026-08-14

UID0001GL now emits the ordinary constructor, destructor, and SetSkinIndex
definitions and gives every other core row its own address-bound no-code
disposition. UID0001H6 emits all six source-authored default scroll virtuals and
separately classifies the two adjustors and scalar deleting wrapper as compiler
output. The complete existing H declaration remains the single declaration
owner. No ScrollablePane source-bearing row depends on a generic aggregate
marker or header-only comment. Score rises from `92/93` to `93/94`.

## UID0000LO Accepted Layout Closure - 2026-08-14

The formal H route now exposes the exact two-flag constructor and the recovered
tail layout required by ListPane. The source-facing tail consists of horizontal
and vertical ScrollPane pointers, horizontal/vertical scrollbar offsets, one
scrollbar inset, enable bytes at `+0x10c/+0x10d`, `m_contentRect` at `+0x110`,
and `m_scrollContentRect` at `+0x120`; the class size guard is `0x130`.

The accepted names are `m_horizontalScrollPane`, `m_verticalScrollPane`,
`m_horizontalScrollBarOffset`, `m_verticalScrollBarOffset`,
`m_scrollBarInset`, `m_horizontalScrollEnabled`,
`m_verticalScrollEnabled`, `m_contentRect`, and `m_scrollContentRect`. Stale
`m_scrollTarget/m_scrollCurrent/m_scrollFlags` names are superseded. The
constructor takes horizontal and vertical flags in that order. This declaration
is the resolved base dependency for ListPane H; it does not change the existing
owner or source-file route.

## C134 Header Assembly Closure

This declaration completes the shared `ScrollBar.h` assembly opened by ScrollPane and closes `NEXUSTK_UI_CORE_SCROLLBAR_H`. Exact ScrollablePane bodies remain CPP children, so the declaration channel has no empty attachment token. The result is one guarded ScrollPane/ScrollablePane header with complete Point and RectBounds dependencies and no generated pseudo-attribute between or after the classes.

## Status

- Confidence: strong.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address ranges: `0x0055e660-0x0055f44f` and `0x005654ec-0x00565608`
- Current recovered file: `source-3/simroot_v2/class_ScrollablePane.cpp`

## Class Purpose

`ScrollablePane` is a base pane for content areas that need optional horizontal and vertical scrollbars. It constructs the base `Pane`, owns two `ScrollPane` children, lays them out around the content rectangle, clips the visible region to the scroll content rectangle, and forwards input to the scrollbar children before letting the owner handle it.

## Observed State

Important recovered state:

```text
m_scrollX / m_scrollY                 current content offset
m_hasHorizontalScroll / m_hasVerticalScroll
m_pHorizontalScrollPane / m_pVerticalScrollPane
                                          owned ScrollPane children at +0xf8/+0xfc
m_contentRect / m_scrollContentRect  fixed content and positioned full-content bounds
current/EPF and classic width/part-extent tables
                                          layout-dependent scrollbar size
```

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/layout | `0x0055e660`, `0x0055e7e0`, `0x0055e840`, `0x0055ec00`, `0x0055f250` | Construct base and child scrollbars, propagate `SetSkinIndex(unsigned short)` to both child `m_scrollSkinIndex` words, apply `SetScrollbarsVisible(bool)` horizontal-then-vertical through inline child `SetScrollStyle`, select current/EPF or classic width/part-extent tables, compute scrollbar bounds, and recompute viewport/content rectangles. |

## UID0002NC Scrollbar Visibility Support - 2026-08-16

- The formal H declaration `void SetScrollbarsVisible(bool visible);` is inserted immediately after `SetSkinIndex` and before `SetScrollTargetValue`; no virtual slot, field, padding, or overload is added.
- UID0001GL owns the sole out-of-line definition at `[0x0055e840,0x0055e897)`. It visits `m_horizontalScrollPane` first and `m_verticalScrollPane` second, null-checking each independently.
- Each nonnull child call uses UID0000CM's inline `ScrollPane::SetScrollStyle(unsigned char)`. The compiler lowering compares child `m_scrollStyle +0xfa`, writes one byte only when changed, then virtually invalidates that same child's inherited `GrafPort::m_visibleBounds +0x44`.
- The boolean is narrowed to `unsigned char`; there is no independent mode, row/stride traversal, extra state, new include, or duplicate raw helper body.
- UID0001GL already emits through this class and UID0000NF with `#include "ScrollBar.h"`, where ScrollPane precedes ScrollablePane. The support chain therefore uses declared members and needs no facade or forward declaration.
| Layer membership | `0x0055ee10`, `0x0055ef10` | Add/remove owned scrollbar panes alongside the base pane. |
| Input forwarding | `0x0055ef50`, `0x0055f0d0`, `0x0055f130` | Secondary pointer/mouse and key/text dispatch gives scrollbar children first chance, then falls back to complete-object primary `+0x60` OnMouseEvent, `+0x64` OnKeyEvent, or the separate key-up slot. |
| Region update | `0x0055f190` | Temporarily clips visible region to content, runs scroll update, restores original region. |
| Destructor/defaults | `0x005654ec-0x00565608` | Destructor adjustor thunks, owned scrollbar destruction, and default scroll-metric virtuals. |

## Evidence Notes

- IDA MCP reports six direct constructor callers: `ChattingPane`, `FolderTreePane`, `ListPane`, `SystemMessagePane`, `OldSystemMessagePane`, and `TextEditPane`.
- Constructor directly allocates `ScrollPane(1)` and `ScrollPane(0)`.
- Destructor deletes the horizontal child pointer at `this+0xf8`, then the vertical child pointer at `this+0xfc`, then chains to `Pane`.
- 2026-06-17 B002 PE/vtable audit rejected stale generated no-argument `GetContentWidth`, `GetContentHeight`, and `IsScrollable` names for the late default island. B005's 2026-07-13 direct-family reconciliation supersedes three inferred B002 spellings while preserving the proven slot map: `+0x48` `GetScrollRange(char axis)` returns zero, `+0x4c` `GetOverflowCount(char axis)` returns zero, `+0x50` `GetPageSize(char axis)` returns one, `+0x54` `GetScrollOffset(char axis, short units)` returns zero, `+0x58` `GetContentSize(Point *outSize)` writes y/x `{0,0}`, and `+0x5c` `GetScrollDelta(Point *outDelta, char axis, short oldPosition, short newPosition)` writes y/x `{0,0}`. Historical `GetScrollPosition` at virtual `+0x4c`, `ConvertScrollUnit`, and `ConvertScrollDelta` are explicitly superseded; separate helper `0x0055e950` remains `GetScrollPosition(char axis)`.
- 2026-06-11 A001 live IDA MCP reconfirmed the exact vtable child [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md): `0x00623de0 -> ??_R4ScrollablePane@@6B@`, `0x00623de4 -> ??_7ScrollablePane@@6B@`, constructor/destructor stores at `0x0055e69f`, `0x0055e789`, and `0x0056551c`, tail default slots at `0x00623e80/0x00623e8c`, and the `ScrollSpellInventoryPane` successor locator at `0x00623e90`.
- 2026-06-16 B001 live IDA MCP and raw PE audit correct the core method cluster to `0x0055e660-0x0055f44f`: constructor, non-deleting destructor body, child scrollbar state propagation, raw selected-child setters at `0x0055e8a0`/`0x0055e8d0`, selected-child getters, synchronization/layout/input/key/update methods, raw content-rect copy at `0x0055edf0`, and internal viewport recompute helper `0x0055f250-0x0055f44f`. Direct class ownership is supported by vtable stores, child scrollbar offsets, vtable data [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md), and source-file ancestor [UID:0000NF][ScrollBar](by-file/ScrollBar.md).
- 2026-07-01 B007 implementation confirmed this class page as a high-confidence route/declaration page: exact core/default/vtable detail remains on [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md), [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md), and [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md). The later UID0002MZ callback supersedes the historical marker-only declaration: formal H now carries the complete class declaration while formal CPP retains the owner include and `[[CHILDREN]]` route, so exact child bodies are still not duplicated here.

## Inferred Skin-Index Propagation Support

- Core helper `0x0055e7e0-0x0055e83c` is best named `ScrollablePane::SetSkinIndex(unsigned short)`. It visits both owned scrollbar children, compares and writes each child `m_scrollSkinIndex` word at `+0xf8`, and invokes the child change callback only when the value changes.
- [UID:0002EO][0x0047efb0-0x0047f1ce.ChattingPaneConstructor](by-memory/0x0047efb0-0x0047f1ce.ChattingPaneConstructor.md) is a direct derived caller: after seeding messages and calling `SyncScrollbars()`, it passes literal `1` to this helper. The call corroborates the skin/theme role; it does not make `ChattingPane` the helper owner.
- The spelling remains evidence-backed inference rather than recovered symbol text. It supersedes generic range/state-setter wording but does not change this class page's `89/90` score or UID0000NF owner/emitter route. Its historical marker-only declaration state is superseded by the complete UID0002MZ formal H without changing this helper's evidence or ownership.

## Current And Classic Scrollbar Constant Contract

- `ScrollablePane::LayoutScrollbars` at `0x0055ec00` is the only consumer that reads all four [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) arrays. The `g_useEpfAssets` branch selects the current/EPF pair or classic pair; the common three-element subscript is each child scrollbar's `m_scrollSkinIndex`.
- The current/EPF branch reads `kScrollPanePartExtentBySkin` `{38,38,38}` at `0x0055ec5c` as horizontal scrollbar height and `kScrollPaneWidthBySkin` `{13,13,13}` at `0x0055ecc0` as vertical scrollbar width. The classic branch reads `kClassicScrollPanePartExtentBySkin` `{13,10,10}` at `0x0055ed1c` and `kClassicScrollPaneWidthBySkin` `{13,12,12}` at `0x0055ed75` for the same two axes.
- Coordinate effects establish the names: part extent is subtracted from bottom for the horizontal child; width is subtracted from right for the vertical child. The tables are not generic high/low-resolution sizes, and the index is skin rather than resolution.
- All four objects are 12-byte `const int[3]` arrays. Four-byte spacing and full-dword consumers outweigh isolated narrowed reads or stale IDA half-word heads. UID0003CQ owns the formal definitions through UID0000NF; this class records use and does not duplicate declarations or storage.
- Historical `high/low resolution thickness` wording is superseded by the observed current/EPF-versus-classic asset mode and independent vertical-width/horizontal-part-extent roles. This synchronization does not change `89/90` or UID0000NF ownership/emission; the separate UID0002MZ dependency callback later replaced the historical marker-only declaration with the complete formal H above.

## 2026-07-13 B005 Inherited Scroll Contract Reconciliation

- The six direct constructor callers are ChattingPane, FolderTreePane, ListPane, SystemMessagePane, OldSystemMessagePane, and TextEditPane. Their primary tables and the base table expose one inherited metric contract at slots `+0x48..+0x5c`.
- Canonical declarations are `short GetScrollRange(char)`, `short GetOverflowCount(char)`, `short GetPageSize(char)`, `short GetScrollOffset(char, short)`, `Point *GetContentSize(Point *)`, and `Point *GetScrollDelta(Point *, char, short oldPosition, short newPosition)`.
- `0x0055e910` and `0x0055e950` remain separate selected-child helpers: the former reads the child maximum/target word at `+0x100`, and source-facing `GetScrollPosition(char)` belongs only to the latter current-position word at `+0xfe`. Reusing that signature for virtual `+0x4c` would create an invalid class collision.
- `Point` is the project y/x record. Slot `+0x58` is consumed as height then width; slot `+0x5c` as vertical then horizontal delta. Win32 `POINT`, `SIZE`, generic `int *`, and no-argument virtuals are rejected.
- `ApplyScrollPosition(axis, oldPosition, targetPosition)` passes old/current before new/target to slot `+0x5c`; overrides compute old minus new. Historical reversed `currentPos, previousPos` wording is corrected.
- Fixed content bounds are `m_contentRect` at `+0x110`; the positioned full-content bounds are `m_scrollContentRect` at `+0x120`. Thus `+0x114`/`+0x124` are their respective `top` fields.
- Slot `+0x5c` canonical name is `GetScrollDelta`. Evidence-time MCP covered the base and all six direct derived families; all seven bodies share the output/axis/old/new contract, while the surviving ListPane inventory provides the concrete source spelling. `ConvertScrollDelta` remains only superseded history.
- ChattingPane exact children [UID:0004J8][0x0047f520-0x0047f5b7.ChattingPaneGetScrollRange](by-memory/0x0047f520-0x0047f5b7.ChattingPaneGetScrollRange.md) through [UID:0004JD][0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta](by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md) instantiate the complete contract without changing this class route marker or score.

## 2026-07-13 B001 ScrollableControlPane Child Layout Support

- The ScrollablePane constructor initializes dwords at `+0x100`, `+0x104`, and `+0x108` to zero. These sit after owned horizontal/vertical ScrollPane pointers at `+0xf8/+0xfc` and before fixed content bounds at `+0x110`.
- Layout `0x0055ec00`, layer attach `0x0055ee10`, and viewport recompute `0x0055f250` resolve the roles: `+0x100` is the horizontal scrollbar/local x offset, `+0x104` is the vertical scrollbar/local y offset, and `+0x108` is a common trailing/corner inset subtracted from right/bottom extents when the corresponding scrollbar is enabled.
- Source-facing descriptive names selected for the stripped fields are `m_horizontalScrollBarOffset`, `m_verticalScrollBarOffset`, and `m_scrollBarInset`. This page documents those roles; its existing formal aggregate route marker, owner/emitter, and `89/90` score remain unchanged.
- Two independent derived consumers reinforce the middle field's name: [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md) initializes inherited `m_verticalScrollBarOffset` to `63`, while [UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) assigns `49` before attaching the EPF-backed `LegendPane` view. The values are layout-specific vertical offsets; the older generic `m_displayMode` token is superseded.
- [UID:0004KC][0x004985a0-0x00498656.ScrollableControlPaneConstructor](by-memory/0x004985a0-0x00498656.ScrollableControlPaneConstructor.md) directly writes those three fields from wrapper constructor arguments before calling `SetBounds(bounds, 0)`. Across 44 calls, the first two values are always zero; the last is normally zero and is 13 or 10 in supported layouts, matching scrollbar extents.
- [UID:0004KE][0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw](by-memory/0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw.md) and [UID:0004KF][0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw](by-memory/0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw.md) are wrapper callers of selected-child source contracts `SetScrollTargetValue(short,char)` and `SetScrollCurrentValue(short,char)`.
- [UID:0004KG][0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw](by-memory/0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw.md) calls the standalone helper at `0x0055e910`, source-facing `GetScrollMax(char)`, which reads selected child `+0x100`; [UID:0004KH][0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw](by-memory/0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw.md) calls `GetScrollPosition(char)` at `0x0055e950`, which reads child `+0xfe`.
- These four wrapper relations add callers, not ownership. Helper bodies remain ScrollablePane/ScrollBar source; wrapper bodies remain [UID:0000CE][ScrollableControlPane](by-class/ScrollableControlPane.md) source.
- Historical `scrollStep`, `pageSize`, `range`, duplicate virtual `GetScrollPosition`, and generic embedded-scroll-control descriptions are superseded by the direct field-use and selected-child evidence above.

## 2026-07-30 UID0002MZ Complete Header Reconciliation

- Formal H now carries the complete `ScrollablePane` declaration needed by `FolderTreePane`: exact scroll metric virtuals, `GetScrollMax`, `GetScrollPosition`, unsigned-short `ApplyScrollPosition`, and both `RectBounds` members are declared once under the UID0000NF owner route.
- Formal CPP remains source-root routing only: it includes `ScrollBar.h` and preserves `[[CHILDREN]]`; exact method bodies stay on their by-memory children.
- This closes the former marker-only dependency gap without changing the `89/90` score, owner/emitter metadata, observed layout, or method-body ownership. Earlier dated statements that a marker alone was retained describe their historical checkpoints rather than current formal state.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md)
- [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md)
- [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md)
- [UID:0002ES][0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals](by-memory/0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals.md)

## Changes

- 2026-08-16 B001 UID0002NC support callback: inserted the exact `SetScrollbarsVisible(bool)` declaration at its accepted position and documented the sole UID0001GL definition, horizontal/vertical order, null/change checks, child inline API, inherited bounds invalidation, one-byte narrowing, dependency route, and no-layout/no-slot effects. Score and unrelated declarations remain unchanged.

- 2026-07-30 B002 accepted UID0003CQ support synchronization:
  - Replaced generic high/low-resolution thickness wording with the exact four-array current/EPF-versus-classic layout contract, values, xref sites, skin indexing, axis-specific coordinate effects, and `const int[3]` width proof.
  - Preserved UID0003CQ as the sole constant emitter through UID0000NF and kept this class at `89/90` with its existing route marker.

- 2026-07-20 B002 UID0003RM bounded support synchronization:
  - Recorded the independent `LegendPane` value `63` and `UserLookPane::ShowLegendView` value `49` consumers of inherited `m_verticalScrollBarOffset` at `+0x104`, superseding the historical `m_displayMode` placeholder.
  - Preserved `89/90`, the UID0000NF owner/emitter route, the class marker formal, and all unrelated ScrollablePane declarations and evidence.
- 2026-07-21 B001 UID0002WY bounded support synchronization:
  - Added inferred `SetSkinIndex(unsigned short)` ownership at `0x0055e7e0`, exact propagation to both child `m_scrollSkinIndex` words, change-only callbacks, and the [UID:0002EO][0x0047efb0-0x0047f1ce.ChattingPaneConstructor](by-memory/0x0047efb0-0x0047f1ce.ChattingPaneConstructor.md) caller with literal `1` after `SyncScrollbars()`.
  - Preserved `89/90`, owner/emitter UID0000NF, formal route marker, complete current ScrollablePane union, and every unrelated method/layout fact.
- 2026-07-16 B001 UID00023W accepted implementation callback: synchronized the exact inherited EventHandler dispatch contracts for `0x0055ef50` and `0x0055f0d0`; preserved the class score, route-marker formal, ownership, layout fields, scroll metric contracts, and unrelated methods.
- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented owned horizontal/vertical scrollbars, layout/input families, constructor callers, and the corrected destructor/default range.
  - After: changed completion/confidence to `78/84`.
  - Evidence: existing class purpose, observed state, method families, IDA constructor/destructor evidence, and endpoint correction support strong class-role confidence.

- 2026-05-28: Changed the destructor/default virtual range from `0x00565510-0x00565607` to `0x005654ec-0x00565608`.
  - Before: the class doc omitted two destructor adjustor thunks and the final byte of `IsScrollable`.
  - After: the class doc includes the full destructor/default cluster.
  - Evidence: IDA MCP reports adjustor thunks at `0x005654ec` and `0x005654f7`, target scalar deleting destructor at `0x00565510`, and `sub_565600` ending at `0x00565608`.
- [UID:0000CM][ScrollPane](by-class/ScrollPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- 2026-06-03: Attached class metadata to ScrollBar.
  - Before: the page was `78/84`, but reconstructability and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000NF][ScrollBar](by-file/ScrollBar.md) at position `30`, with C++ blank.
  - Evidence: Existing constructor/destructor/layout/input evidence already meets the parent-attachment threshold, and the ScrollWidget pass reconfirmed the `ScrollablePane` constructor creates both horizontal and vertical `ScrollPane` children plus later sync helpers call the embedded scroll widgets.
- 2026-06-11 A001 Batch 224 parent-gate refresh:
  - Before: `78/84`, below the strict gate for exact vtable-data assignment.
  - After: `85/86`, parent remains [UID:0000NF][ScrollBar](by-file/ScrollBar.md), C++ remains blank.
  - Evidence: live IDA reconfirmed the exact [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md) locator/vtable/store boundary, and the file parent was refreshed to `89/85`.
- 2026-06-16 B001 ScrollablePane core audit executed by supervisor:
  - Before: `85/86`, main core range stopped at `0x0055f242`.
  - After: `87/89`, main core range is `0x0055e660-0x0055f44f`; C++ remains blank.
  - Evidence: B001 live IDA MCP and raw PE audit corrected the full class-owned function/helper inventory, raw helper reachability, and successor boundary, while leaving final source blocked on field, virtual-slot, helper, and table names.
- 2026-06-17 B002 ScrollablePane virtual-default audit executed by supervisor:
  - Before: `87/89`, the class doc still repeated generated content-width/content-height/IsScrollable names for the late default island.
  - After: `88/90`, the class doc records the high-confidence six-slot default scroll-metric mapping and horizontal/vertical child destructor offsets; C++ remains blank.
  - Evidence: B002 byte/vtable/derived-override audit of [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) and [UID:0003CL][0x00623de0-0x00623e90.ScrollablePaneVtableData](by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md).
- 2026-07-01 B007 empty-emitter callback:
  - Before: the class route page was `88/90` with a blank formal block.
  - After: raised completion to `89` and inserted the formal class-route comment marker with `[[CHILDREN]]`; exact constructor/layout/default/vtable facts remain on child pages.
- 2026-07-13 B005 UID0002ES support synchronization:
  - Kept `89/90`, owner/emitter UID0000NF, and the formal route marker unchanged; corrected the active six-slot contract, Point y/x type, rectangle roles, scalar widths, and old/new order.
  - Preserved `0x0055e950` as the separate `GetScrollPosition(char)` helper, canonicalized virtual `+0x5c` to `GetScrollDelta`, and retained B002 `ConvertScrollDelta` only as superseded historical inference.
- 2026-07-13 B001 UID000126 support synchronization:
  - Added the `+0x100/+0x104/+0x108` placement/inset roles, strongest descriptive field names, all-caller value evidence, and four exact ScrollableControlPane wrapper relations.
  - Score, owner/emitter, reconstructable state, and formal C++ remain unchanged; this is additive dependency evidence, not a source-owner move.
