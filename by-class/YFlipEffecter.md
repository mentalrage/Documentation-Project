*** UID:0000GD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `88/80`, has proposed path `NexusTK/render/`, and lists `YFlipEffecter` in the runtime effecter module at `0x0055b4a0-0x0055b5c2`.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) records the `0x0055b110-0x0055b5c2` map/pixel displacement block, the raw `YFlipEffecter` constructor bytes, and the modeled `sub_55B4C0` runtime effect body.
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records `0x0055b4a0-0x0055b4b3` as valid constructor-shaped raw code: install vtable `0x00623c2c`, return `this`, then align before the modeled `ApplyEffect` routine.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) and [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) tie the `YFlipEffecter` vtable at `0x00623c2c` to constructor store `0x0055b4a9` inside the ScreenEffecter family.
- The class remains below final-source quality because the `ApplyEffect` body is still documented only through the aggregate/class summary and does not yet have a focused exact by-memory page with field/local naming and full callee/touched-state evidence.

## Autogen Status

- Reconstructable: true for the runtime effecter class.
- Parent: [UID:0000IZ][Effects](by-file/Effects.md). The parent path and confidence are sufficient for attachment.
- Code: intentionally blank. Constructor identity is strong, but the `ApplyEffect` method still needs a focused exact-range pass before final source code can be emitted.

## Score Rationale

- Completion is raised to 80 because ownership, constructor boundary, apply-method range, vtable evidence, and parent attachment are now documented on the class page.
- Confidence is raised to 84 because the written evidence agrees across the Effects file, runtime cluster, constructor-boundary item, vtable family, and exact vtable-data child.
- Remaining gaps are exact `ApplyEffect` internals, final field/local names, and a dedicated by-memory child for `0x0055b4c0-0x0055b5c2`.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the vertical flip effect responsibility, raw constructor/apply method map, effect/render cross-references, and the unresolved IDA function-object boundary for `0x0055b4a0`.
- 2026-06-02: Raised to `80/84`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and added parent, runtime-cluster, constructor-boundary, vtable-family, exact vtable-data, and score-rationale evidence. C++ remains blank pending a focused `ApplyEffect` exact-range pass.
