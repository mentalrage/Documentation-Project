*** UID:0000GD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# YFlipEffecter

## Status

- Confidence: strong for role, medium for constructor boundary because IDA does not currently model `0x0055b4a0` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_YFlipEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`YFlipEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that flips map rendering vertically by drawing source scanlines from bottom to top into the destination region. It uses `MapPane` scanline buffer state and per-line blit calls.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b4a0-0x0055b4b3` | constructor | Raw IDA disassembly confirms the `YFlipEffecter` vtable store, return, and alignment before the IDA-modeled `ApplyEffect` body at `0x0055b4c0`. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |
| `0x0055b4c0-0x0055b5c2` | `ApplyEffect` | Builds a temporary sprite frame/scanline buffer and blits scanlines in reverse Y order. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the vertical flip effect responsibility, raw constructor/apply method map, effect/render cross-references, and the unresolved IDA function-object boundary for `0x0055b4a0`.
