*** UID:000070 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LakeEffecter

## Status

- Confidence: strong for role, medium for constructor boundary because IDA does not currently model `0x0055b810` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_LakeEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Autogen parent: [UID:0000IZ][Effects](by-file/Effects.md). C++ is intentionally blank because the constructor remains raw/non-modeled in IDA and final field/local names are not final-source quality.

## Responsibility

`LakeEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that renders a waterline/reflection effect over the parcel/map pane. It clamps a blend factor, computes a waterline between visible top and bottom bounds, renders the source region above the waterline, then emits reflected one-line strips below it.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b810-0x0055b851` | constructor | Raw IDA disassembly confirms float clamp constants, `LakeEffecter` vtable store, clamped blend/timer stores, and `retn 4`. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |
| `0x0055b870-0x0055ba21` | `ApplyLakeEffect` | Uses parcel visible bounds, tile margins, and repeated `MapPane::RenderRegion` calls to draw/reflection rows. |
| `0x0055bbc0-0x0055bbe3` | scalar deleting destructor | Resets to `ScreenEffecter` base vtable and conditionally deletes storage. |

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `88/80`, assigned to `NexusTK/render/`, and lists `LakeEffecter` as the waterline/reflection render effect in the runtime effecter module.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) is scored `78/82`, reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md); it places the lake constructor and apply body inside the water/lake effect span and records the `0x0055b870` callee check through `0x004ba250`.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the `LakeEffecter` vtable base at `0x00623cf8` and the constructor store at `0x0055b829`.
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records the raw constructor bytes at `0x0055b810-0x0055b851`: float clamp constants, vtable store, clamped blend/timer state, and `retn 4`.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/76`. Summary: the water/reflection effect role and major methods are documented, but the page remains below high completion because the constructor boundary and final source placement still need more confirmation. Evidence: IDA-backed method address table, PixelEffecter relationship, parcel/map rendering behavior, and ScreenEffecter cluster references.
- 2026-06-03 parent attachment pass:
  - What existed before: the page documented the lake/reflection role and method ranges but remained unattached with blank reconstructable metadata and `72/76` scoring.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: the Effects file doc, runtime aggregate, vtable-family page, and small-constructor boundary page all support `render/Effects.cpp` ownership and the `LakeEffecter` identity. C++ remains blank because the constructor is still a raw/non-modeled body and final field/local names are below the 95+ reconstruction gate.
