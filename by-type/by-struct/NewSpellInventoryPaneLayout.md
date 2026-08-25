*** UID:000534 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// NewSpellInventoryPane storage is declared by UID00009A; this exact layout page documents the allocator-proven 0x148 object and emits no duplicate fields.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewSpellInventoryPane Layout

## Status

- Natural complete-object size: `0x148` bytes.
- Base subobject: `PanelPane [0x000,0x0f8)`.
- Owner/emitter: [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md), source position `5`.
- This page emits only the accepted covered-by comment; UID00009A's H channel owns the sole storage declaration.

## Exact Field Layout

| Offset | Size | Accepted field | Read/write evidence |
| --- | ---: | --- | --- |
| `+0x000` | `0xf8` | `PanelPane` base | base constructor/destructor and inherited pane/render/event operations |
| `+0x0f8` | 1 | `signed char m_scrollPosition` | constructor zero; rebuild, scroll, key, pointer, timer, toggle reads/writes |
| `+0x0f9` | 1 | `unsigned char m_spellListCount` | constructor zero; rebuild writes; navigation reads |
| `+0x0fa` | 1 | `bool m_spellInputActive` | constructor zero; activation/input dispatch reads/writes |
| `+0x0fb` | 5 | `unsigned char m_reservedFB[5]` | natural pointer alignment; no supported semantic field claim |
| `+0x100` | 4 | `ScrollSpellInventoryPane *m_scrollPane` | constructor allocation/store; destructor delete; layout/input/timer/list consumers |
| `+0x104` | `0x35` | `unsigned char m_visibleSpellSlots[53]` | rebuild writes one-based learned slots; paint/hit/resolve reads |
| `+0x139` | 1 | `signed char m_hoverSpellSlot` | constructor `-1`; pointer flow and paint selection fill |
| `+0x13a` | 1 | `signed char m_selectedSpellSlot` | constructor `-1`; press/drag/release and paint reads/writes |
| `+0x13b` | 1 | `unsigned char m_reserved13B` | alignment before timer integer; no supported semantic field claim |
| `+0x13c` | 4 | `int m_activeRepeatTimer` | constructor zero; pointer/timer cleanup reads/writes |
| `+0x140` | 4 | `int m_expandButtonState` | constructor zero; pointer/paint/toggle reads/writes |
| `+0x144` | 1 | `bool m_expanded` | constructor zero; layout/list/paint/input/toggle reads/writes |
| `+0x145` | 1 | `bool m_draggedSincePress` | constructor zero; pointer press/drag/release reads/writes |
| `+0x146` | 2 | `unsigned char m_tailPadding[2]` | complete-object alignment to allocator-proven `0x148` |

## Allocation And Constructor Proof

- `GeneralPurposePanel__Constructor` allocates exactly `0x148` bytes at `0x004b84b6`, calls the NewSpell constructor at `0x004b84cb`, and stores the result as child index 3.
- Constructor and cross-body writes reach `+0x145`; the private Scroll companion is stored at `+0x100`, not stale `+0xfc`.
- The three NewSpell vtable-view stores and the `PanelPane` base size fix the base/tail boundary independently of inferred private names.

## Read And Write Reconciliation

All source-bearing bodies were audited against this table. List, selection, timer, expand, drag, and child-pointer accesses fit without overlap; no function requires hidden storage beyond `+0x145`. Reserved bytes preserve unknown semantics instead of inventing fields.

## Stale IDA Projection

The current named IDA UDT is a preserved semantic prestate at size `0x100`, with `m_scrollPane` at `+0xfc`. It is contradicted by allocation and live writes and is not source authority. This documentation/H correction deliberately makes no IDA type-parser or UDT mutation claim.

## Source Ownership

UID00009A declares this layout exactly once in `NewSpellInventoryPane.h`. This page contributes no duplicate class or field declaration, and the compiler owns alignment and the size-check typedef lowering.

## Cross-References

- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
- [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
