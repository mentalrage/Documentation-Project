*** UID:0001W0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollInventoryPane Layout

## Status

- Entity kind: object layout hypothesis.
- Covered class: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md).
- Likely owner: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) or private implementation inside [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md).
- Primary memory evidence: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md).
- Vtable evidence: [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md).
- Confidence: strong for local tail fields and object size; base `Pane` layout remains inherited.

## Layout Hypothesis

IDA MCP confirms that `NewInventoryPane::NewInventoryPane` allocates `272` bytes before calling the `0x00563260` constructor, giving this pane a `0x110`-byte object size. The local tail layout mirrors the sibling scroll-control family:

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor installs `0x0062402c`. |
| `+0xa0` | 4 | secondary vtable/view | Constructor installs `0x00624078`. |
| `+0xa4` | 4 | tertiary timer/update view | Constructor installs `0x006240a8`; reset helper cleans up through `this + 0xa4`. |
| `+0xf8` | 2 | scrollbar size / skin-table index | Constructor writes this as the low halfword of `0x00010000`; paint and geometry helpers index `dword_624144[*(__int16 *)(this + 248)]`. |
| `+0xfa` | 1 | unresolved initialized state byte | Covered by the constructor's `0x00010000` dword store at `+0xf8`; no high-confidence direct semantic name yet. |
| `+0xfb` | 1 | drag-position override flag | Paint and geometry helpers test `*(_BYTE *)(this + 251)` before deriving the thumb rect from `+0x108/+0x10c`. |
| `+0xfc` | 1 | orientation | Constructor argument; `0` is vertical and non-zero is horizontal. |
| `+0xfe` | 2 | current scroll position | `SetScrollPosition` writes this value; drag/update uses it as the old position. |
| `+0x100` | 2 | max scroll range / item count | `SetMaxRange` writes this upper half of the packed scroll-position dword. |
| `+0x102` | 1 | enabled byte | `EnableScrollbar` sets the low byte of `m_scrollFlags`. |
| `+0x103` | 1 | hover/highlight part | `SetHighlightRegion` reads/writes the high byte of `m_scrollFlags`; raw reset invalidates this part before clearing it to `0xff`. |
| `+0x104` | 1 | active interaction part | Constructor initializes to `0xff`; raw reset clears this byte before invalidating stale hover state. |
| `+0x108` | 8 | drag anchor / drag offset point | Constructor calls `SetPoint`; drag and part-rect helpers use this to convert pointer position into a scroll position. |

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

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: The page used generated metadata wording for size and field offsets, with `+0xf8` documented only as a vague packed scroll state.
  - Changed to: IDA-backed allocation, constructor, helper, paint, geometry, raw helper, and vtable evidence; split `+0xf8/+0xfa/+0xfb` into the observed size-index and unresolved/drag-state subfields.
  - Evidence: IDA MCP decompilation of `0x004eb420`, `0x00563260`, `0x00563370`, `0x005636a0`, `0x005640a0`, `0x00564520`, raw disassembly of `0x00564330`, `0x005643a0`, `0x005646b0`, and vtable xrefs to `0x0062402c/0x00624078/0x006240a8`.

## Cross-References

- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md)
- [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md)
- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
