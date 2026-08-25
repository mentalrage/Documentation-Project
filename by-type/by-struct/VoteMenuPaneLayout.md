*** UID:0001WH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VoteMenuPane Layout

## Status

- Confidence: very strong for the complete normalized tail fields, vtable
  offsets, state-byte use, row constants, inherited-state distinction, and
  declaration-level class route from IDA/MCP and current source evidence.
- Semantic owner class:
  [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md). This page is
  `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps exact blank Destination 4
  because the complete class formal already emits every source field.
- Parent route: the layout is `90/92`, the direct class owner is `93/95`, and
  file parent [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) is `93/95`.
  The historical reconstructable/emitting blank-marker state is superseded.
- Evidence basis: IDA MCP raw constructor disassembly, decompilation of `VoteMenuPane` methods, vtable xrefs, and exact child function evidence. Wave3/simroot output is only a lead and is not used as authority here.

## Layout Summary

`VoteMenuPane` is a `Pane`-derived menu popup with three vtable pointers and a compact state tail.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Primary pane/menu object; constructor stores `0x00622ff8`. |
| `+0xa0` | inherited `EventHandler` facet / secondary vtable | EventHandler subobject used by the two event overrides and destructor thunk; constructor stores `0x0062304c`. |
| `+0xa4` | inherited `TimerHandler` facet / tertiary vtable | Timer/event-update subobject used by its destructor thunk; constructor stores `0x0062307c`. |
| `+0xf8` | `uint8` / `bool` | `m_voteRowPressed`; press-state byte used while clicking a vote row, initialized to `0`. |
| `+0xf9` | `int8_t` | `m_highlightedVoteRow`; highlighted row index, `0xff` / `-1` when no row is selected. |
| `+0xfa..+0xfb` | natural alignment padding | Compiler alignment before the dword constructor-context field. No observed field behavior and no source-declared padding member. |
| `+0xfc` | `uint32` / `int` | `m_voteType`; constructor-only vote type/context argument. Do not treat this as the promote/demote row flag. |
| `+0x100` | `wchar_t[0x21]` | `m_targetName`; target player name copied by constructor. |

## Notes

- IDA decompilation of virtual handlers sometimes presents `this` as the inherited EventHandler facet at complete-object `+0xa0`, causing offsets such as `this + 88` and `this - 160`. The table above is normalized to the object base used by the constructor; source uses ordinary member overrides and no manual receiver arithmetic.
- Keep the two state bytes separate. [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md) initializes `+0xf8` and `+0xf9` separately; [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md) and [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) consume them as distinct flags.
- Source-facing row constants are `kPromoteRow = 0`, `kDemoteRow = 1`, and `kNoVoteRow = -1`. `m_highlightedVoteRow` and the file-local hit-test return are signed bytes so the `-1` sentinel remains stable. The submit helper receives a source-level `bool promote` from the clicked row; `m_voteType` remains a constructor context dword until caller-side evidence narrows it. Promote row `0` maps to `true`, and Demote row `1` maps to `false`.
- Canonical `Event` is `0x110` bytes. `HandlePointerOrMouseEvent(Event *)` consumes `m_type` at `+0x04` and pointer payload `m_y` then `m_x` at `+0x08/+0x0c`; the file-local rectangle containment and hit-test helpers use `(y, x)` ordering. The historical `PaneMouseEvent` overlay and earlier `(x, y)` draft were reconstruction errors, not different object layouts.
- `HandleKeyOrTextEvent(Event *)` occupies the adjacent EventHandler slot, receives the same physical one-pointer event argument, reads no Event or VoteMenuPane tail field, recovers the complete object with the compiler-generated `-0xa0` adjustment, calls `Pane::MarkForDeletion`, and returns false.
- Vote-row geometry is fixed by the file-local rectangle helper: row `0` uses `(0, 6, 79, 22)`, row `1` uses `(0, 22, 79, 38)`, and `GetVoteMenuItemRect(-1)` returns the sentinel `(-1, -1, -1, -1)`.
- [UID:0002LV][0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground](by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md)
  reads inherited `GrafPort::m_visibleBounds` at `+0x44..+0x50` and writes
  inherited `GrafPort::m_drawMode` at `+0x70`. Those are base-class fields,
  not additional VoteMenuPane tail members and not evidence for historical
  target-local `m_bounds` or a VoteMenuPane clip flag.
- See [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md) for IDA-confirmed table bases, slot ownership, and RTTI/string boundary warnings.

## IDA Evidence

- IDA MCP `disasm` on 2026-05-31 shows the raw constructor storing vtables at `+0x00`, `+0xa0`, and `+0xa4`, clearing `+0xf8`, storing the constructor vote-type argument at `+0xfc`, setting `+0xf9` to `0xff`, and copying the target name to `+0x100` with `_wcscpy_s` size `0x21`.
- IDA MCP `decompile` on 2026-05-31 shows [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md), now reconstructed as `HandlePointerOrMouseEvent`, reading/writing the normalized `+0xf8/+0xf9` state bytes and using the normalized target-name buffer at `+0x100` for the submit helper.
- IDA MCP `decompile` on 2026-05-31 shows [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) reading `this[249]` and `this[248]`, which normalize to `+0xf9` and `+0xf8`.
- IDA MCP `xrefs_to` on 2026-05-31 confirms the three vtable bases are written by the raw constructor, non-deleting destructor, and scalar deleting destructor.
- IDA MCP on 2026-06-08 reconfirmed the same base-normalized layout: raw constructor disassembly writes `g_pVoteMenuPane`, clears `+0xf8`, stores the constructor vote-type argument at `+0xfc`, writes vtables at `+0x00/+0xa0/+0xa4`, stores `+0xf9 = 0xff`, and copies the target name to `+0x100` with `_wcscpy_s` count `0x21`.
- The same 2026-06-08 decompile pass confirms the pointer/mouse override is entered through the EventHandler view, so decompiler offsets `this + 88`, `this + 89`, and `this + 96` normalize to object offsets `+0xf8`, `+0xf9`, and `+0x100`. `OnPaint` reads primary-base bytes `this[248]` and `this[249]`, and `xrefs_to` keeps the row hit-test and submit helpers as direct callees of `HandlePointerOrMouseEvent`.
- 2026-06-17 B001 source-quality audit names the normalized tail fields as `m_voteRowPressed`, `m_highlightedVoteRow`, `m_voteType`, and `m_targetName[0x21]`; it rejects treating `+0xfc` as the promote/demote row flag because live local search found only the constructor store and the submit flag is derived from row `0`/`1`.
- 2026-06-17 B003 source-quality audit confirms the mouse-event state machine uses `m_highlightedVoteRow` for hover row state and `m_voteRowPressed` as the press latch. It also ties the fixed row rectangles to `GetVoteMenuItemRect`, hit-testing, paint highlight, and submit flag mapping; no evidence supports merging those fields or treating `m_voteType` as the clicked Promote/Demote flag.
- 2026-07-16 B002 UID0002LV reanalysis confirms the background virtual
  copies inherited bounds from `this+0x44..+0x50`, stores mode `1` at
  `this+0x70`, and directly insets only its local `RectBounds`. It does not
  introduce any new class field, raw offset member, clipping member, or
  target-local bounds declaration.

## Score Rationale

Raised from `87/90` to `90/92`. Exact constructor stores, normalized
secondary-view offsets, paint and mouse consumers, vtable views, row constants,
row geometry, natural alignment, constructor-context caveat, inherited GrafPort-state
distinction, and the complete class-emission route are documented. This page
is semantic layout evidence only: UID0000FX emits the declarations, so false,
blank emitter/position/formal metadata is the source-correct state and avoids
duplicate declarations or an Empty Emitter Marker. Confidence remains below
final audit because exact original source typedef spelling for the byte fields
is inferred. The two bytes at `+0xfa..+0xfb` are natural compiler padding and
must not be emitted as an invented `m_reservedFA` source member.

## Cross-References

- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md)
- [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md)
- [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md)
- [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md)
- [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)

## Changes

- 2026-08-15 B008 UID0002LT accepted implementation callback:
  - Retained `90/92`, semantic owner UID0000FX, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal channels, all exact tail offsets, natural padding, row semantics, and inherited GrafPort distinctions.
  - Identified `+0xa0` as Pane's inherited EventHandler facet and `+0xa4` as TimerHandler; documented canonical Event size `0x110` and consumed `m_type/m_pointer.m_y/m_pointer.m_x` fields at `+0x04/+0x08/+0x0c`.
  - Historical `PaneMouseEvent`, `OnMouseEvent`, `PaneEvent`, and dismiss-role wording is superseded. No duplicate field, direct EventHandler base, manual `this` adjustment, source padding member, declaration, or Empty Emitter Marker was introduced.

- 2026-05-31 IDA-based layout verification:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and evidence text that included Wave3 metadata as part of the basis.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and IDA/MCP-only evidence for the layout fields.
  - Summary/evidence: IDA MCP raw constructor disassembly, decompilation of mouse/paint handlers, and vtable xrefs confirm the documented offsets; generated Wave3/simroot output remains only a lead and not a confidence source.
- 2026-06-08 A008 Batch 128 parent-gate refresh:
  - What existed before: the layout was `78/88`, reconstructable, and unassigned because completion and the current strict direct-parent confidence gate were not both satisfied.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`, and `AUTOGEN_PARENT_UID:0000FX`.
  - Summary/evidence: live IDA MCP rechecked the raw constructor tail stores, secondary-view mouse handler normalization, paint-handler state-byte reads, vtable xrefs, and direct helper xrefs. [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) was refreshed to `86/85`, with [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) at `88/85`, so the child and direct parent cleared the corrected 85/85 gate at that time. The old blank-layout-C++ rationale from this pass is superseded by the 2026-06-19 class declaration route; this page is now no-code support because the class page emits the field declarations.
- 2026-06-17 B001 support refresh:
  - Summary/evidence: accepted source-quality audit records the best current field names, row constants, `m_voteType` caveat, and target-name capacity. Score remains unchanged because final emitted layout declarations still depend on broader Pane mode and caller-side constructor evidence.
- 2026-06-17 B003 support refresh:
  - Summary/evidence: added the accepted report's Promote/Demote flag mapping, fixed row rectangles, `GetVoteMenuItemRect(-1)` sentinel behavior, and event-state split. Score remains unchanged because this page still defers final emitted layout declarations to a broader class/header pass.
- 2026-06-19 B014 class source-quality implementation:
  - Changed to `COMPLETION:87`, `CONFIDENCE:90`.
  - Historical summary/evidence: class-level declaration C++ was accepted on [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), including an explicit `m_reservedFA[2]` member. The UID0001FZ pass later rejected that invented source member in favor of natural compiler alignment; this page remains a support/no-code layout record for the normalized offsets and vtable views.
- 2026-07-16 B002 UID0002LV implementation callback:
  - Changed `87/90`, reconstructable true, emitter UID0000FX to `90/92`,
    semantic owner UID0000FX, `RECONSTRUCTABLE:FALSE`, blank emitter and
    position, and exact blank Destination 4.
  - Preserved every field and offset, documented UID0002LV's inherited
    `m_visibleBounds`/`m_drawMode` use without inventing new layout members,
    and historicalized the former layout Empty Emitter Marker.
- 2026-07-26 B004 UID0001FZ support synchronization:
  - Retained `90/92`, semantic owner UID0000FX, `RECONSTRUCTABLE:FALSE`, blank emitter/position, and blank formal channels.
  - Recorded signed-byte hit results and `-1` sentinel behavior, `kind/y/x` event and helper ordering, boolean Promote/Demote packet semantics, and natural `+0xfa..+0xfb` alignment. The prior source declaration of `m_reservedFA[2]` is historicalized and rejected as an invented field.
