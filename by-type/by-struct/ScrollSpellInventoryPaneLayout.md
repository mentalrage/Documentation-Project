*** UID:0001W1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane Layout
## UID0000NJ Non-Emitting Layout Closure - 2026-08-16

This page remains the authoritative physical-layout evidence for the `0x110` class but emits no duplicate CPP or H. UID0000CN's complete H channel owns the source declaration and size guard. The inherited `Pane` base occupies `0x00..0xf7`; the tail is `m_sizeIndex` +0xf8/u16, `m_scrollStyle` +0xfa/u8, `m_thumbDragActive` +0xfb/bool, `m_orientation` +0xfc/u8, alignment +0xfd, `m_scrollPosition` +0xfe/i16, `m_scrollRange` +0x100/i16, `m_enabled` +0x102/bool, signed `m_hoverPart` +0x103/i8, signed `m_activePart` +0x104/i8, alignment +0x105..+0x107, and `m_thumbDragOffset` +0x108/Point. The `272`-byte NewSpell allocation and constructor/vtable/field accesses independently support the size and offsets.

The layout page is `RECONSTRUCTABLE:FALSE` because it is evidence consumed by the source class, not a separately emitted source object. Its historical field and inference record is preserved below; its formal CPP/H channels are intentionally blank.

## UID0000LU Header Route Cross-Link - 2026-08-15

The accepted `0x110` layout is now declared once in UID0000CN's normal `ScrollSpellInventoryPane.h`; this layout page remains covered-by evidence and emits no duplicate fields. NewSpell friendship changes access only, not size or offsets.

## Status

- Entity kind: object layout hypothesis.
- Covered class: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md).
- Direct parent: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md), with selected standalone source placement through [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md). The former private-fold possibility under [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) is retained only as rejected historical source-placement evidence.
- Primary memory evidence: [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md).
- Vtable evidence: [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md).
- Confidence: strong for the `0x110` object size, natural local tail fields, project Y/X `Point` order, direct class owner, and the accepted declaration carrier; base `Pane` layout remains inherited.

## Layout Hypothesis

IDA MCP confirms that `NewSpellInventoryPane::NewSpellInventoryPane` allocates `272` bytes before calling the `0x0055f450` constructor, giving this pane a `0x110`-byte object size. The local tail layout mirrors [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md):

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor installs `0x00623e94`. |
| `+0xa0` | 4 | secondary vtable/view | Constructor installs `0x00623ee0`. |
| `+0xa4` | 4 | tertiary `TimerHandler` / timer-update view | Constructor installs tertiary vtable `0x00623f10`; repeat/reset paths call timer schedule/remove helpers with `ecx = this + 0xa4`. Treat as a `TimerHandler` view in source, not as an ordinary scalar data field. |
| `+0xf8` | 2 | scrollbar size / skin-table index | Constructor writes this as the low halfword of `0x00010000`; paint and geometry helpers index `dword_624144[*(__int16 *)(this + 248)]`. |
| `+0xfa` | 1 | `unsigned char m_scrollStyle` | Covered by the constructor's `0x00010000` dword store at `+0xf8`; raw `SetScrollStyle` at `0x0055f530-0x0055f554` updates this byte and invalidates on change. The name is the selected source-facing inference; `SetStateByte` is rejected as insufficiently descriptive. |
| `+0xfb` | 1 | `bool m_thumbDragActive` | Paint and geometry helpers test this drag-position override before deriving the thumb rect from `m_thumbDragOffset`. |
| `+0xfc` | 1 | `unsigned char m_orientation` | Constructor argument; `0` is vertical and non-zero is horizontal. |
| `+0xfe` | 2 | `short m_scrollPosition` | `SetScrollPosition` writes this signed value; `UpdateFromDrag` compares old and new positions. |
| `+0x100` | 2 | `short m_scrollRange` | `SetMaxRange` writes this signed upper half of the packed position/range dword. |
| `+0x102` | 1 | `bool m_enabled` | Constructor sets it to `1`; `Activate` sets it and `Deactivate` clears it before invalidating. |
| `+0x103` | 1 | `char m_hoverPart` | Hover/highlight scroll-control part. `0xff` / `-1` is the no-part sentinel. `SetHoverPart`, inline mouse-release cleanup, and raw reset invalidate the old part rectangle through `GetPartRect` and Pane invalidation before replacing or clearing it. |
| `+0x104` | 1 | `char m_activePart` | Active/tracked scroll-control part. Begin-interaction writes the clicked/tracked part, update/commit paths read it, and reset clears it to `0xff`; this replaces misleading `m_prevActivePart` / previous-active wording from generated-source pollution. |
| `+0x108` | 8 | `Point m_thumbDragOffset` | Constructor clears the point. Project `Point` order and UID0001GN argument use prove `+0x108 = .y` paired with `localY` and `+0x10c = .x` paired with `localX`. Earlier opposite wording is superseded. |

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
- B002 2026-06-20 aggregate reanalysis records the early raw setter pockets that were previously underdescribed by the aggregate page: `0x0055f500-0x0055f527` updates the `+0xf8` scrollbar size/skin-table index word and invalidates on change, while `0x0055f530-0x0055f554` updates the unresolved `+0xfa` byte and invalidates on change. This strengthens the `+0xfa` field as real class state while keeping the final source name open.
- IDA `xrefs_to` confirms constructor stores to vtable bases `0x00623e94`, `0x00623ee0`, and `0x00623f10`.
- 2026-06-11 IDA MCP refresh confirms the constructor `0x0055f450-0x0055f4f1` has one direct caller at `0x0057d013` inside `NewSpellInventoryPane::NewSpellInventoryPane`, whose constructor allocates `272` bytes and stores the returned scrollbar at `this + 0x100`.
- 2026-06-11 IDA MCP decompilation reconfirms the constructor stores `0x00623e94`, `0x00623ee0`, and `0x00623f10` into the three vtable views, writes orientation/current/range/enabled/hover/active/drag fields at `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and `+0x108`, and leaves only the `+0xfa` initialized byte without a semantic name.
- 2026-06-11 IDA MCP caller and xref checks confirm `0x0055f560`, `0x0055f5c0`, `0x0055f5f0`, `0x0055f890`, `0x00560290`, and `0x00560710` consume the same offsets; `0x005608a0` remains method-shaped raw code ending before the next function at `0x00560900`, so it supports reset-state evidence without raising the page to final-source quality.
- 2026-06-18 B002 source-quality pass for [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) refines the source-facing tail names: `+0xa4` is the tertiary TimerHandler/update-handler view used for pending-timer removal, `+0x103` is `m_hoverPart`, and `+0x104` is `m_activePart`. The prior `m_prevActivePart` / previous-active wording is treated as generated-source pollution because begin-interaction writes the current tracked part and reset clears it.
- B001 MCP session `9b0396a3` and exact [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) branch use resolve the drag point components: vertical/localY consumes `+0x108/.y`, while horizontal/localX consumes `+0x10c/.x`. Signed word operations and setters support `short` for position/range.

## Assignment Gate

This page is nonreconstructable layout evidence owned by [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md). The layout is not mixed: every local field from `+0xf8` through `+0x10f` is used by the constructor, paint/layout helpers, drag updater, or reset helper, and the observed allocator path is the NewSpell constructor. The evidence score is `93/95`; source declaration remains solely on UID0000CN.

The page has no emitter position and blank CPP/H because object storage is declared once on UID0000CN. It must not duplicate class fields, method bodies, or a covered-by source comment; it remains the detailed binary-layout evidence record.

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: The page used generated metadata/source wording for size and field offsets, with `+0xf8` documented only as a vague packed scroll state.
  - Changed to: IDA-backed allocation, constructor, helper, paint, geometry, raw helper, and vtable evidence; split `+0xf8/+0xfa/+0xfb` into the observed size-index and unresolved/drag-state subfields.
  - Evidence: IDA MCP decompilation of `0x0057cf70`, `0x0055f450`, `0x0055f560`, `0x0055f890`, `0x00560290`, `0x00560710`, raw disassembly of `0x00560520`, `0x00560590`, `0x005608a0`, and vtable xrefs to `0x00623e94/0x00623ee0/0x00623f10`.
- 2026-06-11 A005 assignment refresh:
  - Before: completion/confidence were `78/84`, `AUTOGEN_PARENT_UID` was blank, and the page had strong field evidence but no explicit strict-gate rationale.
  - Changed to: completion `85`, confidence `88`, and `AUTOGEN_PARENT_UID:0000CN`.
  - Evidence: live IDA MCP reconfirmed the `272`-byte allocation, sole constructor caller in `NewSpellInventoryPane`, three vtable stores, constructor writes for every local tail offset, helper reads/writes for range/current/enabled/part/drag fields, and the raw reset-helper boundary before `0x00560900`.
- 2026-06-18 B002 support incorporation:
  - Changed wording for `+0xa4`, `+0x103`, and `+0x104` to carry the reset-helper source-quality findings.
  - Evidence: B002 confirmed `ResetScrollState` removes pending timers through the `+0xa4` TimerHandler view, invalidates old `m_hoverPart` at `+0x103` through `GetPartRect`/Pane invalidation, and clears `m_activePart` at `+0x104`; generated `m_prevActivePart` wording is not source-quality.
- 2026-06-20 B002 aggregate support incorporation:
  - Strengthened the `+0xfa` row and evidence notes with the raw setter at `0x0055f530-0x0055f554`, while retaining the unresolved style/state-byte caveat.
  - Evidence: local PE/listing reanalysis of [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) confirmed the raw setter endpoints and invalidation behavior; no final source name is defensible yet.
- 2026-07-22 B001 UID0001GN implementation callback:
  - Retained `85/88` and owner/emitter [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md), set position `20`, and inserted the exact class-layout covered-by comment.
  - Resolved the natural tail declarations and Y/X mapping used by the class formal: `m_scrollStyle`, `m_thumbDragActive`, `m_orientation`, signed `m_scrollPosition`/`m_scrollRange`, `m_enabled`, `m_hoverPart`, `m_activePart`, and `Point m_thumbDragOffset` with `.y` at `+0x108` and `.x` at `+0x10c`.
  - Preserved all allocation, constructor, setter, paint, geometry, timer-facet, raw reset, and vtable-store evidence; no duplicate field block or method body is emitted here.

## Cross-References

- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md)
- [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md)
- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
