*** UID:0001YO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Screen Effecter Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered module: [UID:0000IZ][Effects](by-file/Effects.md).
- Confidence: strong for table bases and constructor/destructor-store xrefs; medium for final original file split inside `render/Effects.cpp` versus a `render/effects/` subfolder.
- Exact by-memory child: [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- Evidence basis: IDA MCP `list_globals`, IDA `py_eval` xref checks on 2026-05-26 and 2026-06-01, representative constructor decompilation, and current `simroot_v2` metadata checks only as a generated-data caveat.

## Base And Pixel Effecter Tables

| Class | Vtable bases | Store/xref evidence |
| --- | --- | --- |
| [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md) | `0x006235a4` | Referenced by base destructor/reset paths and derived teardown stores, including `0x0055bfd0` and the surrounding destructor strip. |
| [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) | `0x006235c4` | Constructor/base stores at `0x0055a2a9` and `0x0055a30b`. |
| [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) | `0x00623be4` | Constructor store at `0x0055b114`. |
| [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md) | `0x00623c08` | Constructor store at `0x0055b2be`. |
| [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md) | `0x00623c2c` | Constructor store at `0x0055b4a9`. |
| [UID:000070][LakeEffecter](by-class/LakeEffecter.md) | `0x00623cf8` | Constructor store at `0x0055b829`. |

## Overlay Effecter Tables

The overlay family has four vtable views installed at object offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`. IDA decompilation of `OverlayEffecter::OverlayEffecter` at `0x0055a2e0` shows `Pane` construction at `this + 4`, then the four table stores.

| Class | Primary | View `+0x04` | View `+0xa4` | View `+0xa8` | Store evidence |
| --- | --- | --- | --- | --- | --- |
| [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) | `0x006235e8` | `0x0062360c` | `0x00623658` | `0x00623688` | `0x0055a329`, `0x0055a32f`, `0x0055a336`, `0x0055a340`. |
| [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md) | `0x00623694` | `0x006236b8` | `0x00623704` | `0x00623734` | `0x0055a4e7`, `0x0055a4ed`, `0x0055a4f4`, `0x0055a4fe`. |
| [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md) | `0x00623740` | `0x00623764` | `0x006237b0` | `0x006237e0` | `0x0055a663`, `0x0055a669`, `0x0055a670`, `0x0055a67a`. |
| [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md) | `0x006237ec` | `0x00623810` | `0x0062385c` | `0x0062388c` | `0x0055a817`, `0x0055a81d`, `0x0055a824`, `0x0055a82e`. |
| [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) | `0x00623898` | `0x006238bc` | `0x00623908` | `0x00623938` | `0x0055ab44`, `0x0055ab4a`, `0x0055ab51`, `0x0055ab5b`. |

## Filter Effecter Tables

The filter family uses the same four-view object shape at `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`. IDA decompilation of `FilterEffecter::FilterEffecter` at `0x0055ad00` shows the base `Pane` construction and the four table stores.

| Class | Primary | View `+0x04` | View `+0xa4` | View `+0xa8` | Store evidence |
| --- | --- | --- | --- | --- | --- |
| [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) | `0x00623944` | `0x00623964` | `0x006239b0` | `0x006239e0` | `0x0055ad41`, `0x0055ad4d`, `0x0055ad54`, `0x0055ad5e`. |
| [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) | `0x006239ec` | `0x00623a0c` | `0x00623a58` | `0x00623a88` | `0x0055ae46`, `0x0055ae4c`, `0x0055ae53`, `0x0055ae5d`. |
| [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) | `0x00623a94` | `0x00623ab4` | `0x00623b00` | `0x00623b30` | `0x0055b00f`, `0x0055b017`, `0x0055b01e`, `0x0055b028`. |
| [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) | `0x00623b3c` | `0x00623b5c` | `0x00623ba8` | `0x00623bd8` | `0x0055b09f`, `0x0055b0a7`, `0x0055b0ae`, `0x0055b0b8`. |
| [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) | `0x00623c50` | `0x00623c70` | `0x00623cbc` | `0x00623cec` | `0x0055b6d1`, `0x0055b6d7`, `0x0055b6de`, `0x0055b6e8`. |

## Layout Notes

- `ScreenEffecter` and `PixelEffecter` form the single-primary-vtable root and pixel-effect branch.
- Overlay and filter subclasses embed a `Pane`-like subobject at `+0x04`, then additional vtable views at `+0xa4` and `+0xa8`, matching the general pane/update/event subobject pattern used elsewhere in the client.
- Several small constructor starts are not IDA function objects, but their vtable stores are present as data xrefs. 2026-05-26 read-only disassembly confirms these as constructor-shaped raw code boundaries; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md).
- The effecter vtables are tightly ordered in `.rdata` from `0x006235a4` through `0x00623cf8`, matching the code cluster order at [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md). The cluster now includes the `ScreenEffecter` vtable/default stubs starting at `0x0055a260`.

## Boundary Evidence

2026-06-01 IDA MCP `py_eval` confirms the exact effecter-family vtable-data child is [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md):

| Address | Observed value | Interpretation |
|---|---|---|
| `0x00623590` | `0x80000000` | Adjacent `ScreenFadeOut` constant data before the effecter family. |
| `0x006235a0` | `0x0064f01c` -> `??_R4ScreenEffecter@@6B@` | `ScreenEffecter` complete-object-locator pointer; start of this family. |
| `0x006235a4` | `0x0055c1c0` -> `sub_55C1C0` | Start of `??_7ScreenEffecter@@6B@`. |
| `0x00623cf8` | `0x0055c1b0` -> `sub_55C1B0` | Start of `??_7LakeEffecter@@6B@`, the final effecter vtable in the family. |
| `0x00623d18` | `off_623D18` | Effect-resource string/constant tail; excluded from the pure vtable-data child. |
| `0x00623d58` | `0x0064f8cc` -> `??_R4ScrollPane@@6B@` | Next class boundary after the effecter read-only-data aggregate. |

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for every checked class in this family even though IDA confirms the table bases above:

`ScreenEffecter`, `PixelEffecter`, `OverlayEffecter`, `OverlayImageEffecter`, `OverlayFrameImageEffecter`, `OverlayImageOnPointEffecter`, `OverlayMovingImageEffecter`, `FilterEffecter`, `SolidColorFilterEffecter`, `CloudFilterEffecter`, `StaticCloudFilterEffecter`, `WaterFilterEffecter`, `EarthquakeEffecter`, `XWaveEffecter`, `YFlipEffecter`, and `LakeEffecter`.

## Reconstruction Notes

Use this page as the class-layout anchor for `render/Effects.cpp`. The vtable order supports the existing file-level grouping: root effecter types first, overlay branch, filter branch, then pixel/water/lake effect subclasses. Do not split the runtime effecters into unrelated one-class files solely because current generated output emits one class per file.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-01:
  - Before: the page was marked `0/0` despite documenting most vtable bases, store xrefs, and layout notes, and it had no exact by-memory child for the pure ScreenEffecter-family vtable data.
  - Changed to: scored the page as `86/90`, marked it reconstructable, added exact child [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), and recorded the start/end boundary evidence.
  - Summary/evidence: IDA MCP `py_eval` confirms the family starts at `0x006235a0 -> ??_R4ScreenEffecter@@6B@`, carries named vtable bases through `0x00623cf8 -> ??_7LakeEffecter@@6B@`, and ends before `off_623D18` at `0x00623d18`; the broader aggregate ends before `0x00623d58 -> ??_R4ScrollPane@@6B@`.
