*** UID:000046 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EarthquakeEffecter

## Status

- Confidence: strong for role, source-module placement, vtable identity, and `ApplyEffect` behavior; medium-high for the constructor boundary because IDA does not currently model `0x0055b110` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_EarthquakeEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Read-only data: [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) records the `EarthquakeEffecter` vtable at `0x00623be4`.

## Responsibility

`EarthquakeEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that shakes the map render by random X/Y offsets within configured amplitudes. It throttles offset updates, resets map scroll on a new shake sample, respects camera-lock state, and blits the map through the adjusted destination rectangle.

## Hierarchy And Layout Evidence

| Item | Evidence |
| --- | --- |
| Source module | [UID:0000IZ][Effects](by-file/Effects.md) groups `EarthquakeEffecter` with the runtime `ScreenEffecter`/`PixelEffecter` family in `render/Effects.cpp`, not a standalone one-class source file. |
| Base class | [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) places `EarthquakeEffecter` in the single-primary pixel-effect branch with `PixelEffecter`, `XWaveEffecter`, `YFlipEffecter`, and `LakeEffecter`. |
| Vtable | [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) lists `??_7EarthquakeEffecter@@6B@` at `0x00623be4`, with constructor store evidence at `0x0055b114`. |
| Runtime cluster | [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) groups `0x0055b110-0x0055b5c2` as the earthquake, X-wave, and Y-flip displacement-effect block. |

## State And Behavior Notes

- Constructor state is documented from raw bytes in [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md): install vtable `0x00623be4`, read the timer baseline from `dword_67AB80 + 0x18`, subtract `0x3c`, store the two short amplitude arguments, zero current shake state, and return with `retn 8`.
- `ApplyEffect` at `0x0055b160-0x0055b292` uses `_rand`, timer/render helpers, map scroll/reset helpers, and a shifted blit path; [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) records representative callees `0x004b78f0`, `0x004ba250`, `0x00505080`, `_rand`, and security-cookie checking.
- The scalar deleting destructor at `0x0055bb90-0x0055bbb3` belongs to the effecter destructor strip and resets to the base `ScreenEffecter` vtable before optional deallocation.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b110-0x0055b151` | constructor | Raw IDA disassembly confirms the `EarthquakeEffecter` vtable store, timer baseline load from `dword_67AB80 + 0x18`, amplitude stores, state zeroing, and `retn 8`. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |
| `0x0055b160-0x0055b292` | `ApplyEffect` | Applies random shake offsets, camera-lock clamps, and a shifted map blit. |
| `0x0055bb90-0x0055bbb3` | scalar deleting destructor | Resets to `ScreenEffecter` base vtable and conditionally deletes storage. |

## Reconstruction Notes

- Marked reconstructable because this is source-owned runtime effecter code under [UID:0000IZ][Effects](by-file/Effects.md), with an exact vtable anchor and documented constructor/apply/destructor ranges.
- Do not emit reconstructed C++ yet. The constructor start is raw/non-modeled in IDA, exact source field names are not final, and the relationship between timer baseline, sample cadence, and camera-lock branch still needs a method-level field-layout pass.
- Do not treat the generated one-class `class_EarthquakeEffecter.cpp` path as original source layout; sibling docs and the vtable family support a shared `render/Effects.cpp` owner.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-06-02:
  - Before: scored `68/74`, reconstructable/parent blank, with role and method list but missing the stronger source-module, vtable-data, runtime-cluster, and constructor-boundary evidence now present in related docs.
  - After: scored `78/84`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) and [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) confirm the single-primary `EarthquakeEffecter` vtable at `0x00623be4` and constructor store at `0x0055b114`; [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) confirms the runtime displacement-effect block and representative callees; [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records the raw constructor bytes and the remaining IDA function-object caveat.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/74`.
  - Summary/evidence: effect role, raw constructor bytes, apply-effect behavior, destructor, map/timer relationships, and vtable family references are documented; score remains limited because IDA does not currently model the constructor start as a function object.
