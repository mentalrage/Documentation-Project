*** UID:0000AI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Rebuild Handling

- Source placement: attach to [UID:0000IZ][Effects](by-file/Effects.md), which already owns the screen-effect hierarchy and has IDA-backed vtable-family evidence.
- Reconstructability: true for the class declaration and minimal constructor behavior. The source-side constructor can be emitted as a small vtable-owning constructor, but no final C++ is recorded here because the current evidence is below the 95+ threshold and IDA still does not have a function object at `0x0055a2a0`.
- Boundary rule: keep the constructor range documented as raw constructor-shaped code until the function object is created in IDA. Do not promote `0x0055a2a0` to an IDA-modeled function in notes or generated comments without that follow-up evidence.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a2a0-0x0055a2b3` | constructor | Raw IDA disassembly confirms a normal prologue, `PixelEffecter` vtable store at `0x0055a2a9`, return, and alignment before the next helper. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |

## IDA Evidence

- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the `PixelEffecter` vtable at `0x006235c4`.
- The same vtable-family page records constructor/base stores at `0x0055a2a9` and `0x0055a30b`, tying the raw constructor bytes and derived overlay construction path to this class.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) records `0x0055a2a0-0x0055a2b3` as `PixelEffecter` constructor-shaped bytes that store `0x006235c4`, then return; it also notes that `lookup_funcs 0x0055a2a0` still reports `Not a function`.
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) records `0x006235c4` as `??_7PixelEffecter@@6B@`.

## Reconstruction Notes

- Model `PixelEffecter` as the narrow pixel-effect branch below `ScreenEffecter`, not as an overlay/filter class with pane-owned state.
- The constructor has no documented member initialization beyond installing the class vtable view. Subclass pages carry the effect-specific state and runtime behavior.
- Keep source output minimal: declaration, inheritance, and constructor ownership are supported; additional methods or fields would be speculative from the current page evidence.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite base-effect role, subclass list, raw constructor evidence, and boundary caveat notes.
- Changed to: `COMPLETION:60` and `CONFIDENCE:68`.
- Evidence: the page documents the minimal vtable-store constructor, its raw disassembly boundary, known subclasses, and screen-effect cluster placement; score remains conservative because IDA does not model `0x0055a2a0` as a function object and there is little behavior beyond construction.
- 2026-06-02: Raised from `60/68` to `74/82`, marked reconstructable, and attached under [UID:0000IZ][Effects](by-file/Effects.md).
  - Before: the class stayed in the low-both queue even though the Effects file, vtable family, vtable-data page, and runtime cluster all agreed on ownership.
  - Evidence: `0x006235c4` vtable identity, constructor/base stores at `0x0055a2a9` and `0x0055a30b`, raw constructor range `0x0055a2a0-0x0055a2b3`, and the explicit IDA caveat that `0x0055a2a0` is not yet a function object.
