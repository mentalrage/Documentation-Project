*** UID:0003H9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenFadeOut Layout

## Status

- Type category: class-local `Pane`-derived fade overlay layout.
- Semantic owner: [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md); this duplicate layout support page is false/non-emitting and has a blank emitter/formal.
- Source context: [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md), expected under `NexusTK/ui/core/`.
- Split from: [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md), which remains a mixed non-emitting index.
- Evidence basis: live IDA MCP checks on 2026-06-12 plus [UID:000395][0x00559e50-0x00559f5e.ScreenFadeOutConstructor](by-memory/0x00559e50-0x00559f5e.ScreenFadeOutConstructor.md), [UID:000396][0x00559f60-0x0055a003.ScreenFadeOutDestructor](by-memory/0x00559f60-0x0055a003.ScreenFadeOutDestructor.md), [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md), [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md), [UID:0003EG][0x00623508-0x006235a0.ScreenFadeOutVtableData](by-memory/0x00623508-0x006235a0.ScreenFadeOutVtableData.md), and [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md).

## Layout

Total observed object size is `0x10c` / 268 bytes (Verified with int_convert.py).

| Offset | Size | Field | Evidence |
| --- | --- | --- | --- |
| `0x000` | pointer | primary `ScreenFadeOut`/`Pane` vtable | Constructor stores `??_7ScreenFadeOut@@6B@` at object base; destructor and scalar deleting destructor restore the same vtable. |
| `0x000-0x0f7` | `0xf8` | inherited `Pane`, `GrafPort`, `LObject`, EventHandler, and TimerHandler storage | The constructor calls the `Pane` constructor at object base, RTTI places GrafPort/LObject/EventHandler/TimerHandler beneath Pane, and the first ScreenFadeOut-owned tail write is at `+0xf8`. |
| `0x0a0` | pointer | inherited EventHandler/secondary interface vtable | Constructor/destructor/deleting destructor store `??_7ScreenFadeOut@@6B@_0`; the related adjustor thunk subtracts `0xa0` / 160 bytes (Verified with int_convert.py). This is inherited through Pane, not a direct ScreenFadeOut base. |
| `0x0a4` | pointer | inherited TimerHandler/tertiary interface vtable | Constructor/destructor/deleting destructor store `??_7ScreenFadeOut@@6B@_1`; timer scheduling and OnTimer use this facet, and the adjustor subtracts `0xa4` / 164 bytes (Verified with int_convert.py). This is inherited through Pane. |
| `0x0f8` | 4 bytes | `m_halfSteps` | Constructor writes `duration / 2` at dword index `62`, offset `+0xf8` / 248 bytes (Verified with int_convert.py). |
| `0x0fc` | 4 bytes | `m_fadeStepDelta` | Constructor writes the negative per-step fade delta as a float. |
| `0x100` | 4 bytes | `m_updatesPerStep` | Constructor writes `duration / halfSteps` and passes that value into timer initialization. |
| `0x104` | 4 bytes | `m_currentAlpha` | Constructor initializes this to `1.0 - m_fadeStepDelta`. |
| `0x108` | 4 bytes | `m_isActive` | Constructor initializes this state to `1` at `+0x108` / 264 bytes (Verified with int_convert.py). |

## IDA Evidence

- 2026-06-12 live IDA MCP `analyze_function 0x00559e50` decompiled the constructor as storing the primary vtable at `this + 0`, secondary vtable at `this + 0xa0`, tertiary vtable at `this + 0xa4`, writing `duration / 2` at `+0xf8`, fade delta at `+0xfc`, update period at `+0x100`, current alpha at `+0x104`, and active state at `+0x108`.
- 2026-06-12 `trace_data_flow` on `0x0062350c`, `0x00623558`, and `0x00623588` returned vtable stores from constructor `0x00559eb1/0x00559ebf/0x00559ed6`, destructor `0x00559f8b/0x00559f91/0x00559f9b`, and scalar deleting destructor `0x0055a1ab/0x0055a1b1/0x0055a1bb`.
- 2026-06-12 `lookup_funcs` confirmed the relevant ScreenFadeOut method and glue sizes: constructor `0x00559e50` size `0x10e`, destructor `0x00559f60` size `0xa3`, historically named `IsHandled` at `0x0055a010` size `0x05`, historically named `OnUpdate` at `0x0055a020` size `0x01`, adjustor thunks `0x0055a051` and `0x0055a05c` size `0x0b` each, and scalar deleting destructor `0x0055a180` size `0xd2`.
- 2026-07-21 live IDA MCP/vtable reconciliation resolves those historical names: `0x0055a010` is [UID:000397][0x0055a010-0x0055a015.ScreenFadeOutOnTimer](by-memory/0x0055a010-0x0055a015.ScreenFadeOutOnTimer.md) in the tertiary TimerHandler slot, and `0x0055a020` is [UID:000398][0x0055a020-0x0055a021.ScreenFadeOutOnPaint](by-memory/0x0055a020-0x0055a021.ScreenFadeOutOnPaint.md) in primary slot `+0x44`.
- 2026-06-12 `entity_query` over `0x00623480-0x006235a0` found the three ScreenFadeOut vtable names at `0x0062350c`, `0x00623558`, and `0x00623588`, after the peer `ScreenDimmer` vtable family and before the runtime `ScreenEffecter` vtable family.

## Assignment Decision

`CANONICAL_OWNER` remains semantic [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md), but this page is now `RECONSTRUCTABLE:FALSE`, blank emitter, blank optional position, and blank R10. The complete class declaration contains the only source-level field layout and routes through [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md); this page documents exact covered-by evidence and must not emit duplicate layout code or an Empty Emitter Marker.

## Source Representation And No-Code Proof

- The sole source shape is `class ScreenFadeOut : public Pane` with five naturally ordered private fields: `int m_halfSteps`, `float m_fadeStepDelta`, `int m_updatesPerStep`, `float m_currentAlpha`, and `int m_isActive`.
- Those five four-byte fields occupy contiguous offsets `+0xf8..+0x10b`, closing the exact `0x10c` object without raw byte arrays, explicit padding members, embedded interface objects, or offset comments.
- Pane's inherited layout already supplies all storage through `+0xf7`, including EventHandler and TimerHandler facets. Listing those facets as direct ScreenFadeOut bases would duplicate Pane storage and contradict RTTI/construction.
- Vptr fields, raw RTTI/vtable arrays, synthetic overlays, placement scaffolding, and explicit compiler padding are excluded. UID0003EG retains physical binary table evidence; UID0000CA alone carries source declarations.

## Score Rationale

Completion is `91` because the object size, complete inherited boundary, three vtable views, exact five-field natural tail, corrected OnTimer/OnPaint identities, constructor/destructor/scalar stores, semantic owner, blank no-code disposition, and sole class-source representation are documented.

Confidence is `94` because constructor field writes, destructor/deleting-destructor vtable restores, method boundaries/slots, RTTI hierarchy, `.rdata` table names, inherited facet offsets, and exact class ownership were rechecked live. It remains below 95 because original private lexical names and compiler-emitted internal symbols are not debug-symbol proven.

## Cross-References

- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md)
- [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md)
- [UID:0003EG][0x00623508-0x006235a0.ScreenFadeOutVtableData](by-memory/0x00623508-0x006235a0.ScreenFadeOutVtableData.md)
- [UID:000395][0x00559e50-0x00559f5e.ScreenFadeOutConstructor](by-memory/0x00559e50-0x00559f5e.ScreenFadeOutConstructor.md)
- [UID:000396][0x00559f60-0x0055a003.ScreenFadeOutDestructor](by-memory/0x00559f60-0x0055a003.ScreenFadeOutDestructor.md)
- [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md)
- [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md)

## Changes

- 2026-06-12 A004 Batch303: Created this exact `ScreenFadeOut` layout child from the mixed [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) page and routed it to the direct class parent [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md) after live IDA MCP reconfirmed constructor writes, vtable-store refs, method sizes, object size, and fade/timer tail ownership.
- 2026-07-21 B003 UID000395 callback: Raised scores to `91/94`, retained semantic owner UID0000CA, changed the duplicate layout page to false/non-emitting with blank R10, resolved inherited EventHandler/TimerHandler facets and OnTimer/OnPaint identities, and documented the complete natural 0x10c class-source representation without raw layout emission.
