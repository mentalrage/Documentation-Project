*** UID:0001W0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollInventoryPane Layout

## Status

- Entity kind: object layout hypothesis.
- Covered class: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md).
- Direct parent: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), with finalized standalone source placement through [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md).
- Primary memory evidence: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md).
- Vtable evidence: [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md).
- Confidence: strong for the complete local tail, `0x110` object size, three inherited interface views, field widths, sentinels, and source-facing declaration. The base `Pane` prefix remains inherited rather than duplicated here.

## Layout Hypothesis

IDA MCP confirms that `NewInventoryPane::NewInventoryPane` allocates `272` bytes (`0x110`, verified with `int_convert.py`) before calling the `0x00563260` constructor, giving this pane a `0x110`-byte object size. The local tail layout mirrors the sibling scroll-control family:

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor installs `0x0062402c`. |
| `+0xa0` | 4 | secondary vtable/view | Constructor installs `0x00624078`. |
| `+0xa4` | 4 | tertiary `TimerHandler` / update-handler subobject view | Constructor installs the tertiary vtable at `+0xa4`; interaction helpers pass `ecx = this + 0xa4` to generic `TimerHandler` wrappers. `ResetScrollState` calls `TimerHandler::RemovePendingTimers()` at `0x00597600` through this view. Do not model this as an unrelated widget-local scalar field. |
| `+0xf8` | 2 | scrollbar size / skin-table index | Constructor writes this as the low halfword of `0x00010000`; paint and geometry helpers index `dword_624144[*(__int16 *)(this + 248)]`. |
| `+0xfa` | 1 | `unsigned char m_scrollStyle` | Covered by the constructor's packed `0x00010000` store at `+0xf8`; `SetScrollStyleRaw` writes this byte and the current reconstructed declaration preserves the byte-sized style rather than inventing an unobserved enum. |
| `+0xfb` | 1 | `bool m_thumbDragActive` | Paint and geometry helpers test this byte before deriving the thumb rect from `+0x108/+0x10c`; begin-interaction sets it for thumb dragging and reset clears it. |
| `+0xfc` | 1 | `unsigned char m_orientation` | Constructor argument; `0` is vertical and non-zero is horizontal. |
| `+0xfd` | 1 | natural alignment padding | Separates the byte flags from the following signed 16-bit position. It is compiler layout, not an authored member. |
| `+0xfe` | 2 | current scroll position | `SetScrollPosition` writes this value; drag/update uses it as the old position. |
| `+0x100` | 2 | max scroll range / item count | `SetMaxRange` writes this upper half of the packed scroll-position dword. |
| `+0x102` | 1 | `bool m_scrollEnabled` | `Enable` writes one and `DisableRaw` writes zero; interaction and paint paths consult the byte. |
| `+0x103` | 1 | `signed char m_highlightPart` | Highlighted/hovered scrollbar part, with `0xff` / `-1` as no-part sentinel. `SetHighlightedPartRaw` writes it; `ResetScrollState` reads the old value, invalidates that part rectangle when valid, and clears it. |
| `+0x104` | 1 | `signed char m_activePart` | Active/pressed/tracking scrollbar part, with `0xff` / `-1` as no-part sentinel. `BeginPartInteractionRaw` writes it, drag and timer paths consume it, and `ResetScrollState` clears it unconditionally. |
| `+0x105-0x107` | 3 | natural alignment padding | Aligns the following `Point`; clone/hash evidence preserves these bytes as compiler padding, not source fields. |
| `+0x108` | 8 | `Point m_thumbDragOffset` | Constructor calls `SetPoint`; drag and part-rect helpers use the two coordinates to convert pointer position into a scroll position. |

The complete accepted declaration is centralized in [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) and emitted through `InventoryScrollPane.h`. This support page intentionally has no emitter and keeps both formal code channels blank: it documents the reconstructable storage contract but must not duplicate the class declaration, manufacture explicit padding members, emit a second definition, or leave an empty-emitter marker in generated source.

## Part Codes

IDA-observed helper behavior uses five scrollbar sub-regions:

| Code | Meaning |
| --- | --- |
| `0` | leading edge / up-left button region |
| `1` | track before thumb |
| `2` | thumb |
| `3` | track after thumb |
| `4` | trailing edge / down-right button region |
| `0xff` | no hover or active part |

## IDA MCP Evidence

- `0x004eb420` (`NewInventoryPane::NewInventoryPane`) calls the allocator with `272` bytes, then calls `0x00563260(v2, 0)` and stores the returned pane at `this + 0x114`, confirming the `0x110` allocation size and item-inventory ownership.
- The `0x00563260` constructor writes the orientation byte at `+0xfc`, zeroes the current/range halfwords at `+0xfe/+0x100`, installs vtables at `+0x00/+0xa0/+0xa4`, writes `0x00010000` at `+0xf8`, writes `0xff01` at `+0x102`, writes `0xff` at `+0x104`, and clears the point at `+0x108`.
- `0x00563370`, `0x005633d0`, and `0x00563400` confirm the max-range, current-position, and enabled fields at `+0x100`, `+0xfe`, and `+0x102`.
- `0x005636a0` and `0x005640a0` read the low halfword at `+0xf8` as the `dword_624144` scrollbar-size index, read `+0xfc` as orientation, read `+0xfe/+0x100` as current/range words, test `+0xfb` as the drag-position override flag, and use the point at `+0x108/+0x10c`.
- Raw disassembly at `0x00564330` shows the hover/highlight helper invalidating the old `+0x103` part and storing the new part in `+0x103`.
- Raw disassembly at `0x005643a0` sets active part `+0x104`, computes the thumb rect, writes the drag offset point at `+0x108`, and starts the timer through the `+0xa4` view.
- Raw disassembly at `0x005646b0` stops the `+0xa4` timer/update view, clears `+0x104`, invalidates the old `+0x103` hover part, and clears `+0x103` to `0xff`.
- IDA `xrefs_to` confirms constructor stores to vtable bases `0x0062402c`, `0x00624078`, and `0x006240a8`.
- 2026-06-11 IDA MCP refresh confirms the constructor `0x00563260-0x00563301` has one direct caller at `0x004eb4e4` inside `NewInventoryPane::NewInventoryPane`, whose constructor allocates `272` bytes (`0x110`, verified with `int_convert.py`) and stores the returned scrollbar at `this + 0x114`.
- 2026-06-11 IDA MCP decompilation reconfirms the constructor stores `0x0062402c`, `0x00624078`, and `0x006240a8` into the three vtable views and writes orientation/current/range/enabled/hover/active/drag fields at `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and `+0x108`. The whole-file pass additionally resolves `+0xfa` through the exact raw style setter at `0x00563340-0x00563364`.
- 2026-06-11 IDA MCP caller and xref checks confirm the one-caller constructor relationship and the three vtable stores. Existing raw-helper evidence still covers `0x00564330`, `0x005643a0`, and `0x005646b0`, so the raw reset-helper boundary supports layout confidence without raising the page to final-source quality.
- 2026-06-18 B003 source-quality pass for [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) refines the source-facing tail names: `+0xa4` is the tertiary TimerHandler/update-handler view used for pending-timer removal, `+0x103` is `m_highlightPart`, and `+0x104` is `m_activePart`. The pass rejects swapping `+0x103` and `+0x104`: reset reads and conditionally invalidates `+0x103`, while it clears `+0x104` unconditionally as current active/tracked state.

## Assignment Gate

This page is assigned to the direct class parent [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md). The layout is not mixed: every authored local field from `+0xf8` through `+0x10f` is read or written by the item-scrollbar constructor, exact setters, paint/layout helpers, drag updater, or reset helper, and the only observed allocator/caller path is the new item inventory constructor. The current class score is `89/91`, this layout remains `93/95`, and validator command `000000024570` completed coherent generated header verification; exact original spellings and rebuilt-binary comparison remain the relevant limits.

The page still leaves final C++ blank because it describes object storage rather than a standalone source implementation. The raw reset child now carries bounded first-draft C++; this layout page remains support metadata for the class definition and field names rather than a code-emitting method body.

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: The page used generated metadata wording for size and field offsets, with `+0xf8` documented only as a vague packed scroll state.
  - Changed to: IDA-backed allocation, constructor, helper, paint, geometry, raw helper, and vtable evidence; split `+0xf8/+0xfa/+0xfb` into the observed size-index and unresolved/drag-state subfields.
  - Evidence: IDA MCP decompilation of `0x004eb420`, `0x00563260`, `0x00563370`, `0x005636a0`, `0x005640a0`, `0x00564520`, raw disassembly of `0x00564330`, `0x005643a0`, `0x005646b0`, and vtable xrefs to `0x0062402c/0x00624078/0x006240a8`.
- 2026-06-11 A008 Batch 155 assignment refresh:
  - Before: completion/confidence were `78/84`, `AUTOGEN_PARENT_UID` was blank, and the page had strong field evidence but no explicit strict-gate rationale.
  - Changed to: completion `85`, confidence `88`, and `AUTOGEN_PARENT_UID:0000CK`.
  - Evidence: live IDA MCP reconfirmed the `272`-byte allocation (`0x110`, verified with `int_convert.py`), sole `NewInventoryPane` constructor caller, three vtable stores, constructor writes for every local tail offset, helper reads/writes for range/current/enabled/part/drag fields, and the raw reset-helper boundary before `0x00564710`.
- 2026-06-18 B003 support incorporation:
  - Changed wording for `+0xa4`, `+0x103`, and `+0x104` to carry the reset-helper source-quality findings.
  - Evidence: B003 confirmed `ResetScrollState` removes pending timers through the `+0xa4` TimerHandler view, invalidates old `m_highlightPart` at `+0x103` through `GetPartRect`/Pane invalidation, and clears `m_activePart` at `+0x104`; pointer-looking route artifacts did not affect these field roles.
- 2026-08-15 B005 accepted whole-file callback:
  - Raised `85/88` to `93/95`, finalized standalone `InventoryScrollPane.h` placement through [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), resolved `+0xfa` as `m_scrollStyle`, and recorded the complete `0x110` layout including natural `+0xfd` and `+0x105-0x107` alignment gaps.
  - Cleared the emitter route and preserved blank formal channels because the class page owns the one authored declaration; explicit source padding fields, a duplicate layout declaration, and a generated empty-emitter marker are rejected.
  - Evidence: exact constructor writes, all 19 method bodies, `SetScrollStyleRaw`, allocation size, vtable stores, clone-family comparison, and NewInventoryPane's `+0x114` consumer route from the accepted UID0000KB report.

## Cross-References

- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md)
- [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md)
- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
