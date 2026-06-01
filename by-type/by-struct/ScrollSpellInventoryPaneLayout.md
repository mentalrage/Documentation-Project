*** UID:0001W1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane Layout

## Status

- Entity kind: object layout hypothesis.
- Covered class: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md).
- Likely owner: [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) or private implementation inside [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md).
- Primary memory evidence: [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md).
- Vtable evidence: [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md).
- Confidence: strong for local tail fields and object size; base `Pane` layout remains inherited.

## Layout Hypothesis

IDA MCP confirms that `NewSpellInventoryPane::NewSpellInventoryPane` allocates `272` bytes before calling the `0x0055f450` constructor, giving this pane a `0x110`-byte object size. The local tail layout mirrors [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md):

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor installs `0x00623e94`. |
| `+0xa0` | 4 | secondary vtable/view | Constructor installs `0x00623ee0`. |
| `+0xa4` | 4 | tertiary timer/update view | Constructor installs `0x00623f10`; raw reset cleans up through the timer/update view. |
| `+0xf8` | 2 | scrollbar size / skin-table index | Constructor writes this as the low halfword of `0x00010000`; paint and geometry helpers index `dword_624144[*(__int16 *)(this + 248)]`. |
| `+0xfa` | 1 | unresolved initialized state byte | Covered by the constructor's `0x00010000` dword store at `+0xf8`; no high-confidence direct semantic name yet. |
| `+0xfb` | 1 | drag-position override flag | Paint and geometry helpers test `*(_BYTE *)(this + 251)` before deriving the thumb rect from `+0x108/+0x10c`. |
| `+0xfc` | 1 | orientation | Constructor argument; `0` is vertical and non-zero is horizontal. |
| `+0xfe` | 2 | current scroll position | `SetScrollPosition` writes this value; drag/update compares old and new positions. |
| `+0x100` | 2 | max scroll range / spell count | `SetMaxRange` writes this upper half of the packed scroll-position dword. |
| `+0x102` | 1 | enabled/visible byte | Constructor sets it to `1`; `Activate` sets it before invalidating. |
| `+0x103` | 1 | hover part | Constructor initializes to `0xff`; `SetHoverPart` invalidates old/new part rectangles. |
| `+0x104` | 1 | previous active/pressed part | Constructor initializes to `0xff`; raw reset clears it before clearing hover state. |
| `+0x108` | 8 | drag anchor point | Constructor calls `SetPoint`; drag/update helpers use it to convert pointer movement into a scroll position. |

## Part Codes

The scrollbar part coding matches the item-inventory sibling:

| Code | Meaning |
| --- | --- |
| `0` | leading edge / up-left button region |
| `1` | track before thumb |
| `2` | thumb |
| `3` | track after thumb |
| `4` | trailing edge / down-right button region |
| `0xff` | no hover or active part |

## IDA MCP Evidence

- `0x0057cf70` (`NewSpellInventoryPane::NewSpellInventoryPane`) calls the allocator with `272` bytes, then calls `0x0055f450(v2, 0)`, confirming the `0x110` allocation size and spell-inventory ownership.
- The `0x0055f450` constructor writes the orientation byte at `+0xfc`, zeroes the current/range halfwords at `+0xfe/+0x100`, installs vtables at `+0x00/+0xa0/+0xa4`, writes `0x00010000` at `+0xf8`, writes `0xff01` at `+0x102`, writes `0xff` at `+0x104`, and clears the point at `+0x108`.
- `0x0055f560`, `0x0055f5c0`, and `0x0055f5f0` confirm the max-range, current-position, and enabled/activation fields at `+0x100`, `+0xfe`, and `+0x102`.
- `0x0055f890` and `0x00560290` read the low halfword at `+0xf8` as the `dword_624144` scrollbar-size index, read `+0xfc` as orientation, read `+0xfe/+0x100` as current/range words, test `+0xfb` as the drag-position override flag, and use the point at `+0x108/+0x10c`.
- Raw disassembly at `0x00560520` shows the hover/highlight helper invalidating the old `+0x103` part and storing the new part in `+0x103`.
- Raw disassembly at `0x00560590` sets active part `+0x104`, computes the thumb rect, writes the drag offset point at `+0x108`, and starts the timer through the `+0xa4` view.
- Raw disassembly at `0x005608a0` stops the `+0xa4` timer/update view, clears `+0x104`, invalidates the old `+0x103` hover part, and clears `+0x103` to `0xff`.
- IDA `xrefs_to` confirms constructor stores to vtable bases `0x00623e94`, `0x00623ee0`, and `0x00623f10`.

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: The page used generated metadata/source wording for size and field offsets, with `+0xf8` documented only as a vague packed scroll state.
  - Changed to: IDA-backed allocation, constructor, helper, paint, geometry, raw helper, and vtable evidence; split `+0xf8/+0xfa/+0xfb` into the observed size-index and unresolved/drag-state subfields.
  - Evidence: IDA MCP decompilation of `0x0057cf70`, `0x0055f450`, `0x0055f560`, `0x0055f890`, `0x00560290`, `0x00560710`, raw disassembly of `0x00560520`, `0x00560590`, `0x005608a0`, and vtable xrefs to `0x00623e94/0x00623ee0/0x00623f10`.

## Cross-References

- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md)
- [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md)
- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
