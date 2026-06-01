*** UID:0000AI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PixelEffecter

## Status

- Confidence: strong for role, medium for exact constructor boundary because IDA does not currently model `0x0055a2a0` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_PixelEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`PixelEffecter` is a minimal runtime effect base under [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md). The generated constructor only installs the `PixelEffecter` vtable, which matches the behavior expected for the map/pixel displacement effect classes that do not need a pane-backed overlay or filter base.

Known subclasses in the current cluster include [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md), [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md), [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md), and [UID:000070][LakeEffecter](by-class/LakeEffecter.md).

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a2a0-0x0055a2b3` | constructor | Raw IDA disassembly confirms a normal prologue, `PixelEffecter` vtable store at `0x0055a2a9`, return, and alignment before the next helper. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite base-effect role, subclass list, raw constructor evidence, and boundary caveat notes.
- Changed to: `COMPLETION:60` and `CONFIDENCE:68`.
- Evidence: the page documents the minimal vtable-store constructor, its raw disassembly boundary, known subclasses, and screen-effect cluster placement; score remains conservative because IDA does not model `0x0055a2a0` as a function object and there is little behavior beyond construction.
