*** UID:0003H8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000C8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenDimmer Layout

## Status

- Type category: non-emitting declaration-support layout for the `Pane, Singleton<ScreenDimmer>` class emitted completely by UID0000C8.
- Direct owner: [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md).
- Source context: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), expected under `NexusTK/ui/core/`.
- Split from: [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md), which remains a mixed non-emitting index.
- Evidence basis: live IDA MCP checks on 2026-06-12 plus [UID:000392][0x00559b90-0x00559ce6.ScreenDimmerConstructor](by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md), the verify-only UID000393 destructor at `0x00559cf0-0x00559dc4`, the verify-only UID000394 OnPaint method at `0x00559dd0-0x00559e2d`, the verify-only UID0003EF vtable data at `0x00623480-0x00623508`, and [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md). The three verify-only UIDs are not currently registered in validator state, so they are retained as exact prose evidence rather than outbound UID-link tokens.
- Rebuild handling: `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++. This does not mean the class layout is omitted from reconstruction; UID0000C8 already emits the complete declaration, so a second layout block would duplicate source.

## Layout

Total observed object size is `0xfc` / 252 bytes (Verified with int_convert.py).

| Offset | Size | Field | Evidence |
| --- | --- | --- | --- |
| `0x000` | pointer | primary `ScreenDimmer`/`Pane` vtable | Constructor stores `??_7ScreenDimmer@@6B@` at object base; destructor and scalar deleting destructor restore the same vtable. |
| `0x000-0x0f7` | `0xf8` | inherited `Pane` storage, including GrafPort/LOBject and EventHandler/TimerHandler facets | The constructor calls `Pane(2)` at object base; RTTI places GrafPort, LObject, EventHandler, and TimerHandler under Pane, and the first derived source field is at `+0xf8`. |
| `0x0a0` | pointer | inherited `EventHandler` vtable facet | Constructor/destructor/deleting destructor store the secondary vptr, modal registration uses the adjusted pointer, and the related thunk subtracts `0xa0`; this is inherited through Pane rather than a direct ScreenDimmer field/base. |
| `0x0a4` | pointer | inherited `TimerHandler` vtable facet | The tertiary vptr and thunk subtraction of `0xa4` identify the second inherited Pane facet, not a direct ScreenDimmer field/base. |
| `0x0f8` | empty base plus 1 byte | direct `Singleton<ScreenDimmer>` EBO overlapping `unsigned char m_dimLevel` | The Singleton BCD at `0x0064b4ac` has `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`; constructor/paint use the same byte for `m_dimLevel`. |
| `0x0f9-0x0fb` | 3 bytes | natural tail padding | No project-owned field writes exist in this tail. It is compiler layout, not an explicit source padding array. |

The `OnPaint` dim-level table maps values `0..7` to palette indices `143, 142, 140, 132, 130, 128, 12, 11`.

## IDA Evidence

- 2026-06-12 live IDA MCP `analyze_function 0x00559b90` decompiled the constructor as storing the primary vtable at `this + 0`, secondary vtable at `this + 0xa0`, tertiary vtable at `this + 0xa4`, writing `*((_BYTE *)this + 248) = a2`, publishing `dword_69AE08`, and adding `this - 0x60` to the modal-list path.
- 2026-06-12 `trace_data_flow` on `0x00623484`, `0x006234d0`, and `0x00623500` returned vtable stores from constructor `0x00559bfe/0x00559c04/0x00559c0a`, destructor `0x00559d2d/0x00559d1d/0x00559d35`, and scalar deleting destructor `0x0055a0ad/0x0055a09d/0x0055a0b5`.
- 2026-06-12 `lookup_funcs` confirmed the relevant ScreenDimmer method and glue sizes: constructor `0x00559b90` size `0x156`, destructor `0x00559cf0` size `0xd4`, paint method `0x00559dd0` size `0x5d`, adjustor thunks `0x0055a03b` and `0x0055a046` size `0x0b` each, and scalar deleting destructor `0x0055a070` size `0x103`.
- 2026-06-12 `entity_query` over `0x00623480-0x006235a0` found the three ScreenDimmer vtable names at `0x00623484`, `0x006234d0`, and `0x00623500`, before the peer `ScreenFadeOut` vtable family.
- 2026-07-14 live RTTI reanalysis found ScreenDimmer class hierarchy records at `0x0064b460-0x0064b4fc`. The seven hierarchy entries are ScreenDimmer, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<ScreenDimmer>`; only Pane and Singleton are direct source bases.
- The `Singleton<ScreenDimmer>` base-class descriptor at `0x0064b4ac` fixes `mdisp=0xf8`, while allocation callers fix total size `0xfc`. The byte field write/read fixes `m_dimLevel` at the same address, proving MSVC empty-base optimization rather than a union, explicit base pointer, or separate padding member.

## Source Declaration Disposition

- UID0000C8 emits `class ScreenDimmer : public Pane, public Singleton<ScreenDimmer>` with one private `unsigned char m_dimLevel`; this page remains the exact binary-layout proof behind that declaration.
- EventHandler `+0xa0` and TimerHandler `+0xa4` are inherited Pane facets. Their vptrs and adjustor thunks are compiler ABI and do not become fields or handwritten methods.
- Singleton publication and unwind clearing are implicit base lifecycle. No explicit `g_pScreenDimmer` assignment, clear, EBO member, union, vptr, receiver adjustment, EH record, or padding member belongs in source.
- Rejected alternatives are a separately emitted duplicate layout struct, Pane-only inheritance, direct EventHandler/TimerHandler bases, a raw `char[3]` padding member, and treating `+0xf8` as only a byte field without the empty base.

## Assignment Decision

Canonical owner remains [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), but emitter routing is intentionally blank. The complete declaration already lives on the class page and routes through [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md); this exact support page must not emit a second class/struct body.

## Score Rationale

Completion `92` records the complete size, inherited boundary, RTTI hierarchy, three vtable views, direct Singleton EBO, overlapping byte field, natural tail padding, palette use, method evidence, and exact no-duplicate declaration disposition.

Confidence `94` is supported by constructor/paint field access, allocation size, RTTI BCD displacement, vtable restores, adjustor deltas, method boundaries, and direct class ownership. It remains below `95` only because original debug types, exact header organization, and original lexical member spelling were not recovered.

## Cross-References

- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- UID0003EF verify-only vtable data at `by-memory/0x00623480-0x00623508.ScreenDimmerVtableData.md`
- [UID:000392][0x00559b90-0x00559ce6.ScreenDimmerConstructor](by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md)
- UID000393 verify-only destructor at `by-memory/0x00559cf0-0x00559dc4.ScreenDimmerDestructor.md`
- UID000394 verify-only OnPaint at `by-memory/0x00559dd0-0x00559e2d.ScreenDimmerOnPaint.md`

## Changes

- 2026-07-14 B004 UID000392 source-quality callback:
  - Raised `86/91` to `92/94`, retained canonical owner UID0000C8, and reclassified the page to false/non-emitting declaration support with blank emitter, position, and formal C++.
  - Added the direct Pane/Singleton base model, inherited EventHandler/TimerHandler facets, Singleton BCD `mdisp=0xf8`, EBO overlap with one-byte `m_dimLevel`, natural three-byte tail padding, complete `0xfc` size, and exact no-duplicate source disposition.
  - Historical true/emitting treatment is superseded because UID0000C8 now emits the complete class declaration.

- 2026-06-12 A004 Batch303: Created this exact `ScreenDimmer` layout child from the mixed [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) page and routed it to the direct class parent [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md) after live IDA MCP reconfirmed constructor writes, vtable-store refs, method sizes, object size, and dim-level byte ownership.
