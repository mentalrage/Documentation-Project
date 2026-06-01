*** UID:0001VY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Screen Overlay Pane Layouts

## Status

- Confidence: strong for IDA-verified offsets, vtable writes, and adjustor thunks; medium for final field/interface names.
- Type category: pane-derived overlay class layouts.
- Likely owner: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Related classes: [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md)

## ScreenDimmer Layout

| Offset | Size | Candidate field | Evidence |
| --- | --- | --- | --- |
| `0x000` | pointer | primary `ScreenDimmer` vtable | IDA MCP decompilation stores `??_7ScreenDimmer@@6B@` at `this + 0`; xrefs point to constructor/destructor/scalar-deleting destructor. |
| `0x000-0x0f7` | `0xf8` | inherited `Pane` / interface storage | `ScreenDimmer` calls the pane constructor at object base; the first confirmed derived field write is at `this + 0xf8`. Exact inherited tail names remain unresolved. |
| `0x0a0` | pointer | secondary interface vtable | Constructor/destructors install `??_7ScreenDimmer@@6B@_0`; modal list receives `this + 160`; adjustor thunk at `0x0055a03b` subtracts `0xa0`. |
| `0x0a4` | pointer | tertiary interface vtable | Constructor/destructors install `??_7ScreenDimmer@@6B@_1`; adjustor thunk at `0x0055a046` subtracts `0xa4`. |
| `0x0f8` | 1 | `m_dimLevel` | Constructor stores the input byte at `this + 0xf8`; `OnPaint` reads it as a byte selector for values `0` through `7`. |
| `0x0f9-0x0fb` | 3 | padding or unused bytes | No confirmed project field writes in the current IDA pass; total allocation is `0xfc` bytes. |

Total observed size is 252 bytes.

## ScreenFadeOut Layout

| Offset | Size | Candidate field | Evidence |
| --- | --- | --- | --- |
| `0x000` | pointer | primary `ScreenFadeOut` vtable | IDA MCP decompilation stores `??_7ScreenFadeOut@@6B@` at `this + 0`; xrefs point to constructor/destructor/scalar-deleting destructor. |
| `0x000-0x0f7` | `0xf8` | inherited `Pane` / interface storage | `ScreenFadeOut` calls the pane constructor at object base; derived fade fields begin at `this + 0xf8`. Exact inherited tail names remain unresolved. |
| `0x0a0` | pointer | secondary interface vtable | Constructor/destructors install `??_7ScreenFadeOut@@6B@_0`; live IDA confirms adjustor thunk [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md) subtracts `0xa0`. |
| `0x0a4` | pointer | tertiary timer/interface vtable | Constructor/destructors install `??_7ScreenFadeOut@@6B@_1`; timer initialization is called on `this + 0xa4`; live IDA confirms thunk [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md) subtracts `0xa4`. |
| `0x0f8` | 4 | `m_halfSteps` | Constructor stores `duration / 2`. |
| `0x0fc` | 4 | `m_fadeStepDelta` | Constructor stores the negative per-step fade delta as a float. |
| `0x100` | 4 | `m_updatesPerStep` | Constructor stores `duration / halfSteps`. |
| `0x104` | 4 | `m_currentAlpha` | Constructor initializes alpha state to `1.0 - m_fadeStepDelta`. |
| `0x108` | 4 | `m_isActive` | Constructor initializes active flag/state to `1`. |

Total observed size is 268 bytes.

## Caveats

- IDA confirms the first derived overlay fields begin at `0x0f8`, but it does not by itself name every inherited `Pane` field between `0x000` and `0x0f7`.
- The vtable/interface labels are descriptive only. Final names should come from broader `Pane`/event/timer interface reconstruction.
- Current `ScreenFadeOut` generated data disables real adjustor thunks at `0x0055a051` and `0x0055a05c`; live IDA confirms the offsets, but final interface names still depend on broader `Pane`/timer-interface reconstruction.
- 2026-05-26 recheck: active `class_ScreenFadeOut.cpp` still does not emit the two adjustor thunks, and IDA MCP still reports the secondary/tertiary forwards from offsets `0x0a0` and `0x0a4`.

## IDA MCP Verification

- 2026-05-31 `lookup_funcs` confirms the overlay island function boundaries from `0x00559b90` through `0x0055a252`, including the one-byte `ScreenFadeOut::OnUpdate` at `0x0055a020` and all four 11-byte adjustor thunks at `0x0055a03b`, `0x0055a046`, `0x0055a051`, and `0x0055a05c`.
- `ScreenDimmer` constructor `0x00559b90` calls the pane constructor at object base, stores vtables at `this + 0`, `this + 0xa0`, and `this + 0xa4`, stores `m_dimLevel` as a byte at `this + 0xf8`, and registers `this + 0xa0` with the modal list.
- `ScreenDimmer::OnPaint` at `0x00559dd0` reads `*(byte *)(this + 0xf8)` and maps values `0..7` to palette indices `143, 142, 140, 132, 130, 128, 12, 11`.
- `ScreenFadeOut` constructor `0x00559e50` stores vtables at `this + 0`, `this + 0xa0`, and `this + 0xa4`; writes `duration / 2` at `0xf8`, fade delta at `0xfc`, updates-per-step at `0x100`, current alpha at `0x104`, active state at `0x108`, and initializes timer state through `this + 0xa4`.
- IDA named `.rdata` confirms the table starts `??_7ScreenDimmer@@6B@` at `0x00623484`, `??_7ScreenDimmer@@6B@_0` at `0x006234d0`, `??_7ScreenDimmer@@6B@_1` at `0x00623500`, `??_7ScreenFadeOut@@6B@` at `0x0062350c`, `??_7ScreenFadeOut@@6B@_0` at `0x00623558`, and `??_7ScreenFadeOut@@6B@_1` at `0x00623588`.
- IDA disassembly confirms the adjustor thunks subtract `0xa0` or `0xa4` and jump to the corresponding scalar-deleting destructor at `0x0055a070` or `0x0055a180`.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md)
- [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `74/86`, marked reconstructable, and corrected `ScreenDimmer::m_dimLevel` from a 4-byte field to a one-byte selector with three trailing padding/unused bytes.
  - Before: The page was ungraded, depended partly on generated metadata for the inherited `Pane` span, and listed `m_dimLevel` as size 4.
  - After: The page records IDA MCP evidence for constructor field writes, vtable table addresses, adjustor thunk bodies, fade fields, and the dim-level byte read/write behavior.
  - Evidence: 2026-05-31 IDA MCP `lookup_funcs`, `decompile`, `disasm`, `.rdata` name enumeration, and vtable xref checks listed in `## IDA MCP Verification`.
