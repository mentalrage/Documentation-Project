*** UID:000046 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EarthquakeEffecter

## Status

- Confidence: strong for role, medium for constructor boundary because IDA does not currently model `0x0055b110` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_EarthquakeEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`EarthquakeEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that shakes the map render by random X/Y offsets within configured amplitudes. It throttles offset updates, resets map scroll on a new shake sample, respects camera-lock state, and blits the map through the adjusted destination rectangle.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b110-0x0055b151` | constructor | Raw IDA disassembly confirms the `EarthquakeEffecter` vtable store, timer baseline load from `dword_67AB80 + 0x18`, amplitude stores, state zeroing, and `retn 8`. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |
| `0x0055b160-0x0055b292` | `ApplyEffect` | Applies random shake offsets, camera-lock clamps, and a shifted map blit. |
| `0x0055bb90-0x0055bbb3` | scalar deleting destructor | Resets to `ScreenEffecter` base vtable and conditionally deletes storage. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/74`.
  - Summary/evidence: effect role, raw constructor bytes, apply-effect behavior, destructor, map/timer relationships, and vtable family references are documented; score remains limited because IDA does not currently model the constructor start as a function object.
