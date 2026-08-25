*** UID:0000GC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class XWaveEffecter : public PixelEffecter
{
public:
    XWaveEffecter(float amplitude, short wavelength, short period);
    virtual ~XWaveEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);

private:
    float m_amplitude;
    short m_wavelength;
    short m_period;
    unsigned int m_lastPhaseTick;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# XWaveEffecter

## Status

- Confidence: very strong for modeled constructor/apply/destructor boundaries, vtable slots, call sites, and wave-displacement behavior; medium-high for final source field/local names.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_XWaveEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Autogen parent: [UID:0000IZ][Effects](by-file/Effects.md). Formal C++ now emits the class declaration and best-supported field names; exact constructor/apply/destructor bodies remain owned by exact method pages or future splits.

## Responsibility

`XWaveEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that draws horizontal sine-wave displacement by shifting scanline strips. It uses timer phase, tile height, map scroll, wavelength, period, and amplitude to compute per-row X offsets.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b2a0-0x0055b2cf` | constructor | IDA confirms a small constructor that installs vtable `0x00623c08`, stores the amplitude scalar at `+0x04`, and stores two signed-word wave parameters at `+0x08/+0x0a`. |
| `0x0055b2d0-0x0055b49b` | `ApplyWaveEffect` | Builds temporary regions, computes sine displacement per scanline, clamps source/destination strips, and renders visible shifted rows. |
| `0x0055c180-0x0055c1a4` | scalar deleting destructor | Resets to `ScreenEffecter` base vtable and conditionally deletes storage. |

## Field And Behavior Evidence

| Offset / input | Evidence | Current interpretation |
| --- | --- | --- |
| `this + 0x04` | Constructor stores the third argument; apply reads it with `movss` and multiplies the sine result by it. | Wave amplitude scalar. |
| `this + 0x08` | Constructor stores first 16-bit argument; apply divides the row/map-coordinate term by this signed word before the sine call. | Wavelength or row-scale divisor. |
| `this + 0x0a` | Constructor stores third 16-bit argument; apply divides the timer phase by this signed word before the sine call. | Period or time-scale divisor. |
| `this + 0x0c` | Apply compares/stores against `unk_67AB80 + 0x18` and clamps phase jumps over `0x3c`. | Last observed render/timer tick used for wave phase continuity. |
| `arg_0` / `arg_1` | Apply treats both as four-int rectangles and iterates from source top to bottom. | Source and destination strip rectangles supplied by the caller. |

2026-06-13 IDA MCP `disasm` of `0x0055b2d0` shows the core formula path: each scanline combines the row index, `word_66DAA0` scaled by the map/viewport helper result from `sub_505290`, the current timer value from `unk_67AB80 + 0x18`, and the `this + 0x08/+0x0a` divisors; multiplies by `qword_623D50`; calls `__libm_sse2_sin_precise`; multiplies by the `this + 0x04` amplitude scalar; then shifts source/destination X bounds before drawing through `sub_4BA250` when the shifted strip is visible.

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `89/85`, assigned to `NexusTK/render/`, and lists `XWaveEffecter` as the horizontal sine-wave scanline displacement effect in the runtime effecter module.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) is scored `82/86`, reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md); it records modeled functions `0x0055b2a0`, `0x0055b2d0`, and `0x0055c180`, representative callees for `0x0055b2d0`, and the `qword_623D50` read as read-only effecter data.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the `XWaveEffecter` vtable base at `0x00623c08` and constructor store at `0x0055b2be`.
- The [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000OT][TimerMgr](by-file/TimerMgr.md), and render/surface cross-references remain dependencies of the effect behavior, not alternative source owners.
- 2026-06-13 live IDA MCP `lookup_funcs` reports exact modeled functions: constructor `0x0055b2a0` size `0x2f`, apply body `0x0055b2d0` size `0x1cb`, and scalar deleting destructor `0x0055c180` size `0x24`.
- 2026-06-13 `xrefs_to` reports constructor call sites at `0x0050401f` inside [UID:0002I4][0x00503ef0-0x0050408d.MapPaneConfigureEffectList](by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md) and `0x0050a68c` inside [UID:00037W][0x0050a500-0x0050ab95.MapPanePaintLightingCore](by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md), confirming map effect setup/paint consumers without moving class ownership out of [UID:0000IZ][Effects](by-file/Effects.md).
- 2026-06-13 `xrefs_to` confirms vtable data links: `0x00623c08` is stored by the constructor at `0x0055b2be`, vtable slot `0x00623c24` points to `0x0055b2d0`, vtable slot `0x00623c20` points to `0x0055c180`, and `qword_623D50` is read only by the wave apply body at `0x0055b3fa`.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the `XWaveEffecter : public PixelEffecter` declaration with amplitude, wavelength, period, and last-phase tick state. Current modeled constructor/apply/destructor boundaries and the vtable base `0x00623c08` support class identity and field direction. Exact method bodies remain deferred to exact pages or future splits because final local/helper names are still below final-source quality.

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the horizontal sine-wave effect responsibility, constructor/apply/destructor method map, effect/render/timer cross-references, and source-field-name caveat.
- 2026-06-03 parent attachment pass:
  - What existed before: the page had modeled method ranges and behavior notes but remained unattached with blank reconstructable metadata and `76/76` scoring.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: the Effects file doc, runtime aggregate, and vtable-family page support `render/Effects.cpp` ownership and the modeled constructor/apply/destructor identity. Formal output was withheld at that time because field names, locals, and final helper names were below the 95+ reconstruction gate; B006 2026-06-30 now emits the declaration while method bodies remain deferred.
- 2026-06-13 Agent-A001 Goal 2 refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:82`.
  - After: `COMPLETION:86`, `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP reconfirmed exact modeled function sizes, constructor callers from MapPane effect configuration/paint paths, vtable-slot xrefs, destructor reset behavior, and the apply-body sine/phase/strip-render data flow. `RECONSTRUCTION_CPP CODE` stays blank because the class is still below the active `90/90+` code-entry gate and final source field/local names remain provisional.
