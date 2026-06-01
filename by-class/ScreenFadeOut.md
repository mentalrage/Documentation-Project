*** UID:0000CA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenFadeOut

## Status

- Confidence: strong for behavior and layout; medium for final source split.
- Likely source file: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), or neighboring `ui/core/ScreenFadeOut.cpp`.
- Address range: [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- Current generated file: `source-3/simroot_v2/class_ScreenFadeOut.cpp`
- Imported source hint: `ScreenFadeOut.cpp`

## Class Purpose

`ScreenFadeOut` is a `Pane`-derived full-screen fade overlay. Its constructor computes duration-derived fade parameters, initializes the timer interface, and sets its display region from the current back pane bounds. Destruction invalidates the active back pane region so the fade overlay is repainted away.

This class is adjacent to [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), but it is not the same as the `ScreenEffecter` runtime effect hierarchy documented under [UID:0000IZ][Effects](by-file/Effects.md).

## Layout Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x000` | primary `Pane`/`ScreenFadeOut` vtable | IDA MCP confirms constructor/destructor paths install the primary `ScreenFadeOut` table at object base. |
| `0x000-0x0f7` | inherited `Pane` / interface storage | IDA confirms the derived fade/timer fields begin at `0x0f8`; exact inherited tail names are still unresolved. |
| `0x0a0` | secondary vtable/interface | Constructor installs `ScreenFadeOut_vtable2`; adjustor thunk at `0x0055a051` subtracts `0xa0`. |
| `0x0a4` | tertiary timer/interface | Constructor installs `ScreenFadeOut_vtable3`; timer initialization is called through this area and the adjustor thunk at `0x0055a05c` subtracts `0xa4`. |
| `0x0f8` | `m_halfSteps` | Constructor stores `duration / 2`. |
| `0x0fc` | `m_fadeStepDelta` | Float fade delta computed from `startAlpha` and half-step count. |
| `0x100` | `m_updatesPerStep` | Constructor stores `duration / halfSteps`. |
| `0x104` | `m_currentAlpha` | Initial alpha state after step-delta calculation. |
| `0x108` | `m_isActive` | Constructor initializes this to `1`. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScreenFadeOut(float startAlpha, int duration)` | `0x00559e50-0x00559f5e` | Constructs pane overlay, computes fade timing fields, initializes timer, sets display region. |
| `~ScreenFadeOut` | `0x00559f60-0x0055a003` | Resets vtables, invalidates primary or fallback back pane, and destroys `Pane`. |
| `IsHandled` | `0x0055a010-0x0055a015` | Returns false. |
| `OnUpdate` | `0x0055a020-0x0055a021` | Empty virtual hook; cached prewave size is one byte even though current metadata records a zero-length end. |
| `ScalarDeletingDestructor_vtable2_adjustor` | [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md) | Adjusts `this` from offset `0xa0` and forwards to the scalar deleting destructor. Current generated output leaves this in the disabled companion. |
| `ScalarDeletingDestructor_vtable3_adjustor` | [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md) | Adjusts `this` from offset `0xa4` and forwards to the scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x0055a180-0x0055a252` | Calls the destructor and conditionally frees heap storage. |

## Data Caveats

- `class_ScreenFadeOut.meta_wave3` marks `0x0055a051` and `0x0055a05c` as disabled methods even though live IDA confirms both are real 11-byte adjustor thunks.
- The active generated source contains `OnUpdate`, but metadata records its range as `0x0055a020-0x0055a020`; live IDA reports `nullsub_46` at `0x0055a020` with size 1.
- Metadata says the destructor chain is `TextButtonExControlPane::~TextButtonExControlPane -> Pane::~Pane`, which looks like stale base-name pollution. Treat `Pane` as the confirmed base/member evidence.
- 2026-05-26 recheck: current `class_ScreenFadeOut.cpp` still omits the `0x0055a051` and `0x0055a05c` adjustor thunks, while IDA MCP still reports them as real 11-byte functions with vtable data xrefs and decompiles them as `this - 0xa0` / `this - 0xa4` forwards to `0x0055a180`.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md)
- [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md)
- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:0000IZ][Effects](by-file/Effects.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `84/82`.
  - Before: The page was unevaluated despite documenting fade overlay behavior, timer/layout fields, adjustor thunks, scalar destructor, and metadata caveats.
  - After: Scored as high completion and strong confidence with remaining uncertainty around final source split and generated metadata defects.
  - Evidence: Existing layout notes, method notes, data caveats, IDA recheck notes, dimmer relationship, and overlay layout cross-references support the score.
- 2026-05-31: Marked reconstructable in validator metadata and replaced generated `Pane`-size wording with IDA-backed inherited-storage wording.
  - Before: The page documented source-owned class behavior but left `RECONSTRUCTABLE` blank and described the base span from generated metadata.
  - After: `RECONSTRUCTABLE` is set to `TRUE`; inherited storage is bounded by the first confirmed derived fade field at `0x0f8`; parent UID and C++ remain blank because the final source-file split and final-source-quality code are not at the 95+ gate.
  - Evidence: IDA MCP decompilation of `0x00559e50`, `0x00559f60`, and `0x0055a180` confirms project class construction/destruction, derived fade fields, and `Pane` teardown behavior.
