*** UID:0000GC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# XWaveEffecter

## Status

- Confidence: strong for wave effect behavior; medium for source field names.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_XWaveEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Autogen parent: [UID:0000IZ][Effects](by-file/Effects.md). C++ is intentionally blank because source field names and final local/helper names are not final-source quality.

## Responsibility

`XWaveEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that draws horizontal sine-wave displacement by shifting scanline strips. It uses timer phase, tile height, map scroll, wavelength, period, and amplitude to compute per-row X offsets.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b2a0-0x0055b2ce` | constructor | IDA confirms a small constructor that installs the vtable and stores wavelength/amplitude/period. |
| `0x0055b2d0-0x0055b49a` | `ApplyWaveEffect` | Builds a temporary region, computes sine displacement per scanline, and renders visible shifted strips. |
| `0x0055c180-0x0055c1a3` | scalar deleting destructor | Resets to `ScreenEffecter` base vtable and conditionally deletes storage. |

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `88/80`, assigned to `NexusTK/render/`, and lists `XWaveEffecter` as the horizontal sine-wave scanline displacement effect in the runtime effecter module.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) is scored `78/82`, reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md); it records modeled functions `0x0055b2a0`, `0x0055b2d0`, and `0x0055c180`, representative callees for `0x0055b2d0`, and the `qword_623D50` read as read-only effecter data.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the `XWaveEffecter` vtable base at `0x00623c08` and constructor store at `0x0055b2be`.
- The [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000OT][TimerMgr](by-file/TimerMgr.md), and render/surface cross-references remain dependencies of the effect behavior, not alternative source owners.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the horizontal sine-wave effect responsibility, constructor/apply/destructor method map, effect/render/timer cross-references, and source-field-name caveat.
- 2026-06-03 parent attachment pass:
  - What existed before: the page had modeled method ranges and behavior notes but remained unattached with blank reconstructable metadata and `76/76` scoring.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: the Effects file doc, runtime aggregate, and vtable-family page support `render/Effects.cpp` ownership and the modeled constructor/apply/destructor identity. C++ remains blank because field names, locals, and final helper names are below the 95+ reconstruction gate.
