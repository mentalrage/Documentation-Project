*** UID:0001VZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollCollectionPane Layout

## Status

- Entity kind: class/object layout notes.
- Covered class: [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- Direct parent: [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md); accepted source file [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}`.
- Confidence: very strong for offsets, widths, natural alignment, exact `0x110` size, direct class ownership, member roles, and declaration relationship; strong for inferred source spellings.

## Layout Hypothesis

`ScrollCollectionPane` follows the common pane multiple-inheritance shape. `CollectionPane::CollectionPane` allocates `272` bytes / `0x110` bytes (Verified with int_convert.py), constructs this child with orientation `0`, stores it at `CollectionPane + 0x108`, and immediately enables it.

| Offset | Size | Name hypothesis | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary pane vtable | Constructor stores vtable `0x00623fa4`; xrefs show the constructor store at `0x00561e01`. |
| `+0x44` | 16 | bounds/display rect | Draw, hit-test, and rectangle helpers read the pane rect at `this + 68`; invalidation calls pass this rectangle. |
| `+0xa0` | 4 | secondary pane-data view | Constructor stores vtable `0x00623ff0`; secondary slots route input and boolean virtuals. |
| `+0xa4` | 4 | tertiary `TimerHandler` / update-handler view | Constructor stores vtable `0x00624020`; interaction helpers call scheduler/update methods through `this + 0xa4`, and [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) calls `TimerHandler::RemovePendingTimers()` through this adjusted view during `ResetScrollState`. |
| `+0xf8` | 2 | `m_scrollSkinIndex` / historical scrollbar style index | Constructor initializes the low word through `0x00010000`; draw, hit-test, and part-rect helpers read `*(__int16 *)(this + 0xf8)` as an index into `dword_624144` / `kScrollPanePartExtentBySkin`. B006 [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) uses this alias in first-draft C++; older `m_scrollStyle` wording is retained only as historical/descriptive context. |
| `+0xfa` | 1 | `unsigned char m_scrollStyle` | Constructor initializes this byte to `1`; [UID:0004X6][0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw](by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md) compares/stores it and invalidates on change, proving live one-byte configuration state. |
| `+0xfb` | 1 | `m_thumbDragActive` | Draw/rectangle helpers test `*(byte *)(this + 0xfb)` before using drag-offset coordinates instead of the stored scroll position. B006 [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) confirms the vertical hit-test branch uses this flag to compute thumb geometry from live cursor minus `m_thumbDragOffset`. |
| `+0xfc` | 1 | orientation | Constructor copies the orientation argument here; geometry and drag helpers branch on this byte. |
| `+0xfd` | 1 | natural compiler alignment | Aligns the signed-short position at `+0xfe`; no source member is required. |
| `+0xfe` | 2 | current scroll position | `SetScrollPosition` compares/stores `this[127]`; drag helpers read the old position here. |
| `+0x100` | 2 | max scroll range / collection row range | `SetMaxRange` compares/stores `this[128]`, clamps to `30000` / `0x7530` (Verified with int_convert.py), and part-rect helpers require it to be positive. |
| `+0x102` | 1 | `m_scrollEnabled` | Constructor initializes it to `1`; `EnableScrollbar` sets this byte before invalidating the bounds. B006 [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) confirms hit-test page-before/page-after geometry requires this enabled byte plus positive `m_scrollRange`. |
| `+0x103` | 1 | `char m_highlightPart` | Constructor initializes to `0xff`; [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) / `SetHighlightedPart` updates and invalidates this part, [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) / `BeginPartInteraction` forces it to `kScrollCollectionPartThumb` when thumb dragging starts, and `ResetScrollState` reads the old value, invalidates the stale part rectangle when valid, then clears it. |
| `+0x104` | 1 | `char m_activePart` | Constructor initializes to `0xff`; [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) writes the incoming `ScrollCollectionPart`, `UpdateDragScroll` consumes it, and `ResetScrollState` clears it unconditionally before handling the old highlight. |
| `+0x105-0x107` | 3 | natural compiler alignment | Aligns `Point m_thumbDragOffset` at `+0x108`; no source byte array is emitted. |
| `+0x108` | 8 | `Point m_thumbDragOffset` | Constructor zeroes this point; [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) initializes it as `mouseY - rect.top, mouseX - rect.left`, and cursor-to-position code uses it as the mouse-to-thumb offset in project `Point` order `y,x`. [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) consumes `+0x108` with `localY` / `m_thumbDragOffset.y` and `+0x10c` with `localX` / `m_thumbDragOffset.x`. |

The object size is exactly evidenced at `0x110` for the direct `CollectionPane` child allocation. Natural compiler alignment accounts for `+0xfd` and `+0x105-0x107`; they are not source members. The accepted class H lists members in offset order and relies on natural layout. The withdrawn reverse-engineering-style `SizeMustBe` typedef must not be emitted.

## Part Codes

IDA-observed helpers use the same five scrollbar sub-regions as the sibling scroll-control layouts:

| Code | Meaning |
| --- | --- |
| `0` | `kScrollCollectionPartLeading`: leading edge / up-left button region |
| `1` | `kScrollCollectionPartPageBeforeThumb`: track/page area before the thumb |
| `2` | `kScrollCollectionPartThumb`: thumb |
| `3` | `kScrollCollectionPartPageAfterThumb`: track/page area after the thumb |
| `4` | `kScrollCollectionPartTrailing`: trailing edge / down-right button region |
| `0xff` | `kScrollCollectionPartNone`: no highlighted, active, or hit-tested part |

## IDA MCP Evidence

- Constructor decompilation at `0x00561db0` stores the orientation byte at `+0xfc`, zeroes `+0xfe/+0x100`, initializes `+0xf8` with `0x00010000`, sets `+0x102` to `1`, sets `+0x103` and `+0x104` to `0xff`, and zeroes the point at `+0x108`.
- 2026-06-11 IDA MCP decompilation of `0x0056e940` confirms the direct allocation/caller path: `sub_4F4AA0(272)`, constructor call `0x00561db0(v2, 0)`, child pointer store at `this[66]`, and immediate `0x00561f50` enable call.
- 2026-06-11 IDA MCP decompilation of `0x0056ece0`, `0x0056f670`, and `0x0056fa90` confirms the parent `CollectionPane` stores and consumes the child at `CollectionPane + 0x108`, calls `SetMaxRange`, calls `SetScrollPosition`, and keeps the collection-side current row byte synchronized with the scrollbar child.
- 2026-06-11 IDA MCP decompilation of `0x00561ec0`, `0x00561f20`, and `0x00561f50` reconfirms range/current/enabled fields at `+0x100`, `+0xfe`, and `+0x102`; `SetMaxRange` clamps to `30000` / `0x7530` (Verified with int_convert.py).
- IDA MCP `lookup_funcs` on 2026-05-31 confirms the function boundaries in the associated memory island, including the modeled functions at `0x00561db0`, `0x00561ec0`, `0x00561f20`, `0x00561f50`, `0x00562bf0`, `0x00562fb0`, and `0x00563070`, and the raw/not-modeled helper starts at `0x00562e80`, `0x00562ef0`, and `0x00563200`.
- 2026-06-11 IDA MCP `lookup_funcs`, `callers`, and `callees` reconfirm `0x00561db0-0x0056325c` as a contiguous class helper island with the next sibling constructor at `0x00563260`; the internal graph connects input, paint, hit-test, geometry, drag update, and cursor-to-position helpers without an alternate owner.
- `SetMaxRange` at `0x00561ec0` reads/writes `+0x100` and clamps `+0xfe` when the range shrinks.
- `SetScrollPosition` at `0x00561f20` reads/writes `+0xfe`.
- `GetPartRect` at `0x00562bf0` (historical alias `GetScrollRegionRect`), `UpdateDragScroll` at `0x00562fb0`, and `UpdatePositionFromCursor` at `0x00563070` all use the `+0xfc` orientation, `+0xfe` position, `+0x100` range, `+0x102` enabled, and `+0x108/+0x10c` drag-offset state.
- IDA MCP xrefs to vtable bases `0x00623fa4`, `0x00623ff0`, and `0x00624020` point to constructor stores at `0x00561e01`, `0x00561e07`, and `0x00561e11`.
- 2026-06-25 B014 rechecked [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md): the raw helper calls `0x00597600` through `this+0xa4`, reads old `+0x103`, clears `+0x104` to `0xff`, calls `0x00562bf0` with the old part and stack rectangle, invalidates through inherited slot `+0x20`, then clears `+0x103`. This supports the source-facing field names `m_highlightPart` and `m_activePart` for these offsets while retaining byte-level `0xff` sentinel evidence.
- 2026-06-26 B001 rechecked [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md): accepted source-facing C++ consumes `+0x108` in the vertical/local-Y branch and `+0x10c` in the horizontal/local-X branch, matching the project `Point` storage order `y,x` used by [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) and the raw start-drag setup.
- 2026-06-27 B002 rechecked [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) and [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md): live MCP session `80de0a67` confirmed raw no-function starts but complete ownerless bodies that use `+0x103` as `m_highlightPart`, `+0x104` as `m_activePart`, and `+0x108/+0x10c` as `m_thumbDragOffset` in project `Point` order. The no-part sentinel remains `0xff`, and part value `2` is the thumb part.
- 2026-06-27 B006 rechecked [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md): live MCP session `b001_000241_20260627` confirmed the hit-test consumes `+0xf8` as the `dword_624144` / `kScrollPanePartExtentBySkin` index, `+0xfb` as the live thumb-drag geometry switch, `+0xfc` as orientation, `+0xfe/+0x100` as position/range, `+0x102` as the enabled gate, and `+0x108/+0x10c` as thumb drag offset before returning part `0..4` or `0xff`.

## RTTI And Secondary-View Confirmation

B002's independent [UID:0003CN][0x00623fa0-0x00624028.ScrollCollectionPaneVtableData](by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md) audit directly confirms the three ABI views used by the natural `0x110` layout:

| View | COL pointer / record | COL offset | Constructor table store |
| --- | --- | ---: | --- |
| primary `Pane`-derived view | `0x00623fa0 -> 0x0064fa94` | `0` | `0x00561e01` writes table `0x00623fa4` at object `+0` |
| `EventHandler` view | `0x00623fec -> 0x0064faf0` | `160` / `0xa0` | `0x00561e07` writes table `0x00623ff0` at object `+0xa0` |
| `TimerHandler` view | `0x0062401c -> 0x0064fb04` | `164` / `0xa4` | `0x00561e11` writes table `0x00624020` at object `+0xa4` |

All three COLs share ScrollCollectionPane type descriptor `0x00678fe4` and hierarchy descriptor `0x0064faa8`; the hierarchy records six bases. The secondary offsets end before the source-owned tail fields at `+0xf8`, so the vtable evidence and field reconstruction agree without synthetic padding or a size-enforcement typedef.

The primary/EventHandler/TimerHandler callable counts are `18/11/2`. Shared deleting adjustors normalize secondary receivers by `-0xa0` and `-0xa4` before reaching the common wrapper. Those compiler artifacts confirm subobject offsets but are not extra source members. The layout page remains source-layout evidence at `92/93`; the physical vtable pages are separately nonreconstructable/nonemitting. Literal vtable fields, decorated compiler labels, and an explicit empty destructor remain rejected source-shape alternatives.

## Assignment Gate

Assigned to direct class parent [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md), now `93/93`, with accepted file owner [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) at `91/92`. This layout is `92/93` and remains a support emitter with blank formal C++ so it does not duplicate the complete class declaration.

## Reconstruction Notes

Use accepted member names and widths: `unsigned short m_scrollSkinIndex` at `+0xf8`, `unsigned char m_scrollStyle` at `+0xfa`, `bool m_thumbDragActive` at `+0xfb`, `unsigned char m_orientation` at `+0xfc`, signed shorts at `+0xfe/+0x100`, `bool m_scrollEnabled` at `+0x102`, signed-byte part fields at `+0x103/+0x104`, and `Point m_thumbDragOffset` at `+0x108`. The stored no-part value is byte `0xff` and source enum `-1`; Point order is `y,x`. The same tail family appears in sibling scrollbars, but direct ownership and source emission are ScrollCollectionPane-specific. This page stays blank in CPP/H because [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) owns the declaration and exact children own definitions.

## Cross-References

- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md)
- [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md)
- [UID:0003CN][0x00623fa0-0x00624028.ScrollCollectionPaneVtableData](by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)

## Changes

- 2026-07-26 B002 accepted UID0003CN implementation callback:
  - Added direct COL/type/hierarchy evidence for primary `+0`, EventHandler `+0xa0`, and TimerHandler `+0xa4` views, the three sole constructor table stores, and complete `18/11/2` callable counts.
  - Confirmed the secondary views precede the natural tail at `+0xf8`, support the existing `0x110` layout without synthetic padding, and do not introduce literal vtable members or a source destructor requirement.
  - Kept `92/93`, class owner/emitter, blank formals, and all accepted field/history evidence unchanged.

- 2026-07-26 B005 accepted UID0001GT implementation callback:
  - Before: `85/88`, `+0xfa` unresolved, source file uncertain, and natural alignment/class-declaration relationship incomplete.
  - Changed to: `92/93`, resolved skin/style/drag/orientation/position/range/enabled/part/Point fields, explicit natural padding and exact `0x110` size, dedicated class/file route, centralized class-H ownership, and explicit prohibition on the withdrawn `SizeMustBe` typedef.
  - Evidence: constructor and new [UID:0004X6][0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw](by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md) style-setter child, all geometry/interaction consumers, direct 272-byte allocation, and accepted B005 report.

- 2026-06-27 B006 `HitTestScrollRegion` support sync:
  - Before: `+0xf8`, `+0xfb`, and `+0x102` were documented with descriptive names only, and the part-code table did not carry the source-facing constants now used by first-draft hit-test C++.
  - Changed to: field rows now prefer `m_scrollSkinIndex`, `m_thumbDragActive`, and `m_scrollEnabled`; part-code rows now list the `ScrollCollectionPart` constants; IDA evidence and reconstruction notes tie those aliases to [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md). Score remains `85/88` because this is a support-alias sync, not a full layout audit.
  - Evidence: accepted B006 report `tools/leaser/Agents/Agent-B006/research/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md` and implemented target page; live MCP session `b001_000241_20260627` confirmed the hit-test reads these fields in the inline vertical/horizontal geometry loop.
- 2026-06-27 B002 `SetHighlightedPart` / `BeginPartInteraction` support sync:
  - Before: this layout already had accepted field names but did not tie `m_highlightPart`, `m_activePart`, and `m_thumbDragOffset` to the now-emitting raw interaction children.
  - Changed to: field rows, IDA evidence, and reconstruction notes now cross-reference [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) and [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md); score remains `85/88` because this is a support cross-reference update, not a full layout audit.
  - Evidence: accepted B002 report `tools/leaser/Agents/Agent-B002/research/0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality.md` and implemented child pages.
- 2026-06-26 B001 `UpdatePositionFromCursor` implementation:
  - Before: `+0x108/+0x10c` were documented only as a generic drag anchor point/offset, without explicit project `Point` component mapping.
  - Changed to: `+0x108/+0x10c` are documented as `Point m_thumbDragOffset` in project `y,x` storage; [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) consumes `+0x108` with `localY` and `+0x10c` with `localX`. Metadata is unchanged.
  - Evidence: accepted B001 report and target implementation for [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md), cross-checked against accepted B005 [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) argument order.
- 2026-06-25 B014 source-quality implementation:
  - Before: `+0xa4`, `+0x103`, and `+0x104` had descriptive names but not the accepted source-facing reset-helper names.
  - Changed to: `+0xa4` is documented as the tertiary `TimerHandler` / update-handler view used by `RemovePendingTimers()`, `+0x103` as `char m_highlightPart`, and `+0x104` as `char m_activePart`; score and owner/emitter remain unchanged.
  - Evidence: [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) reads, clears, and invalidates exactly these fields in the accepted `ResetScrollState` body.
- 2026-05-31: Changed completion/confidence from `0/0` to `78/84`, marked reconstructable, and split the prior `+0xf8` dword description into better-supported subfields.
  - Before: The page was ungraded and described `+0xf8` as a vague dword size/index state.
  - After: The page records `+0xf8` as the 16-bit scrollbar size-table index, calls out adjacent initialized/drag-state bytes at `+0xfa/+0xfb`, and records 2026-05-31 IDA evidence for vtable stores and helper boundaries.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, raw disassembly of `0x00562e80/0x00562ef0`, and `xrefs_to` checks for `0x00623fa4`, `0x00623ff0`, and `0x00624020`.
- 2026-06-11 A004 Batch 151 strict-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:84`, and blank `AUTOGEN_PARENT_UID`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000CG`.
  - Evidence: live IDA MCP reconfirmed the `272` / `0x110` byte allocation (Verified with int_convert.py), direct `CollectionPane` constructor/range/current callback callers, constructor field writes, range clamp `30000` / `0x7530` (Verified with int_convert.py), vtable-store xrefs, internal helper graph, part-code behavior, and next sibling boundary. The parent class [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) was raised to `85/85`; final C++ remains blank.
- 2026-06-16 A002 support sync: updated the assignment-gate wording after [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) reached `86/88` and [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) reached `86/85`; no score or owner/emitter change on this layout page.
