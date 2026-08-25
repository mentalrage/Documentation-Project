*** UID:0001YO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ScreenEffecter vtable-family bytes are compiler-emitted from the class
// declarations and virtual methods in the Effects family. This page is the
// layout authority and should not hand-author static vtable data.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Screen Effecter Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered module: [UID:0000IZ][Effects](by-file/Effects.md).
- Confidence: very strong for table bases, representative slot targets, constructor/destructor-store xrefs, and vtable-only boundaries; medium for final original file split inside `render/Effects.cpp` versus a `render/effects/` subfolder.
- Exact by-memory child: [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- Evidence basis: IDA MCP `list_globals`, IDA `py_eval` xref checks on 2026-05-26 and 2026-06-01, representative constructor decompilation, and current `simroot_v2` metadata checks only as a generated-data caveat.

## Base And Pixel Effecter Tables

| Class | Vtable bases | Store/xref evidence |
| --- | --- | --- |
| [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md) | `0x006235a4` | Referenced by base destructor/reset paths and derived teardown stores, including `0x0055bfd0` and the surrounding destructor strip. |
| [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) | `0x006235c4` | Constructor/base stores at `0x0055a2a9` and `0x0055a30b`. |
| [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) | `0x00623be4` | Constructor store at `0x0055b114`; single-primary pixel branch with destructor slot `0x00623bfc -> 0x0055bb90` and `ApplyEffect` slot `0x00623c00 -> 0x0055b160`. |
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
| [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) | `0x00623898` | `0x006238bc` | `0x00623908` | `0x00623938` | Constructor stores at `0x0055ab44`, `0x0055ab4a`, `0x0055ab51`, `0x0055ab5b`; ordinary destructor stores at `0x0055ac7c`, `0x0055ac82`, `0x0055ac89`, `0x0055ac93`; scalar destructor stores at `0x0055bf1c`, `0x0055bf22`, `0x0055bf29`, `0x0055bf33`. |

2026-06-25 B003 OverlayEffecter support sync: the OverlayEffecter primary table at `0x006235e8` has scalar deleting destructor slot `0x00623600 -> 0x0055bbf0`. The inherited Pane/GrafPort view entries used for adjusted destruction are `0x0062360c -> 0x0055ba40`, `0x00623658 -> 0x0055ba48`, and `0x00623688 -> 0x0055ba53`; current MCP disassembly from session `80de0a67` proves those thunks subtract `0x04`, `0xa4`, and `0xa8` from `ecx` before jumping to `0x0055bbf0`. Treat the scalar wrapper and thunks as compiler ABI evidence generated from `virtual ~OverlayEffecter()`, not as handwritten source methods. The source-facing class page now emits only the `OverlayEffecter : public PixelEffecter, public Pane` declaration and leaves constructor/destructor bodies to exact method pages if split later.

2026-06-22 B015 OverlayFrameImageEffecter support sync: the adjusted `+0x04` Pane/GrafPort view at `0x00623764` has slot `+0x44` at `0x006237a8 -> 0x0055a5e0`, now documented by [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md) as `RenderOverlayFrame` / paint-slot behavior. The receiver for that body is `complete this + 4`, so render-body offsets normalize from adjusted `+0xfc/+0x11c/+0x140/+0x168` to complete `+0x100/+0x120/+0x144/+0x16c`. Complete `+0x140` remains the owned `LoadImageFrameTable` block, not the render draw record. The primary scalar deleting destructor slot is `0x00623758 -> 0x0055bc90`; direct destructor jump-strip branches at `0x0055ba61`, `0x0055ba6c`, and `0x0055ba77` are compiler evidence for the wrapper, not handwritten source methods.

2026-06-20 B002 OverlayImageOnPointEffecter support sync: the adjusted `+0x04` Pane/GrafPort view at `0x00623810` has slot `+0x44` at `0x00623854 -> 0x0055a7a0`, now documented by [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md) as `RenderOverlayImageAtPoint()` / paint-slot behavior. The receiver for that body is `complete this + 4`, so render-body offsets normalize from adjusted `+0x11c/+0x140/+0x150/+0x44/+0x70` to complete `+0x120/+0x144/+0x154/+0x48/+0x74`. The primary scalar deleting destructor slot is `0x00623804 -> 0x0055be10`; the secondary adjusted scalar deleting destructor thunks are `0x0055ba9a` (`sub ecx, 4`), `0x0055baa2` (`sub ecx, 0xa4`), and `0x0055baad` (`sub ecx, 0xa8`). Treat the scalar wrapper and thunks as compiler evidence for an ordinary virtual destructor declaration, not source methods.

2026-06-20 B004 OverlayImageEffecter support sync: the adjusted `+0x04` Pane/GrafPort view at `0x006236b8` has slot `+0x44` at `0x006236fc -> 0x0055a440`, now documented by [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md) as `void OverlayImageEffecter::ApplyOverlayImage()`. The receiver for that body is `complete this + 4`, so render-body offsets normalize from adjusted `+0x11c/+0x140/+0x150` to complete `+0x120` copied palette/overlay name, complete `+0x144` embedded `EPFTileContext`, and complete `+0x154` tile-context bounds/source record. Constructor stores at `0x0055a4e7`, `0x0055a4ed`, `0x0055a4f4`, and `0x0055a4fe` remain the four view-install evidence. The primary scalar deleting destructor slot and secondary adjusted thunk routes point to compiler-generated wrapper behavior at `0x0055bd70` via thunks `0x0055ba7c` (`sub ecx, 4`), `0x0055ba84` (`sub ecx, 0xa4`), and `0x0055ba8f` (`sub ecx, 0xa8`); treat those as compiler evidence for ordinary virtual destructor declarations, not handwritten source methods.

2026-06-20 B001 OverlayMovingImageEffecter support sync: the adjusted `+0x04` Pane/GrafPort view at `0x006238bc` has slot `+0x44` at `0x00623900 -> 0x0055a990`, now documented by [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) as `OverlayMovingImageEffecter::OnPaint()`. The primary scalar deleting destructor slot is `0x006238b0 -> 0x0055bef0`; the secondary adjusted scalar deleting destructor thunks are `0x006238bc -> 0x0055bab8` (`sub ecx, 4`), `0x00623908 -> 0x0055bac0` (`sub ecx, 0xa4`), and `0x00623938 -> 0x0055bacb` (`sub ecx, 0xa8`). Treat those destructor entries as compiler evidence for an ordinary virtual destructor declaration, not handwritten source methods.

## Filter Effecter Tables

The filter family uses the same four-view object shape at complete-object offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`. IDA decompilation of `FilterEffecter::FilterEffecter` at `0x0055ad00` shows inherited `Pane` construction at `this + 4` and the four table stores. The B013 FilterEffecter pass resolves this as `FilterEffecter : public ScreenEffecter, public Pane`: `+0x04` is the inherited Pane/GrafPort view, and `+0xa4/+0xa8` are adjusted inherited Pane-side vptr slots, not fields.

| Class | Primary | View `+0x04` | View `+0xa4` | View `+0xa8` | Store evidence |
| --- | --- | --- | --- | --- | --- |
| [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) | `0x00623944` | `0x00623964` | `0x006239b0` | `0x006239e0` | `0x0055ad41`, `0x0055ad4d`, `0x0055ad54`, `0x0055ad5e`. |
| [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) | `0x006239ec` | `0x00623a0c` | `0x00623a58` | `0x00623a88` | `0x0055ae46`, `0x0055ae4c`, `0x0055ae53`, `0x0055ae5d`. |
| [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) | `0x00623a94` | `0x00623ab4` | `0x00623b00` | `0x00623b30` | `0x0055b00f`, `0x0055b017`, `0x0055b01e`, `0x0055b028`. |
| [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) | `0x00623b3c` | `0x00623b5c` | `0x00623ba8` | `0x00623bd8` | `0x0055b09f`, `0x0055b0a7`, `0x0055b0ae`, `0x0055b0b8`. |
| [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) | `0x00623c50` | `0x00623c70` | `0x00623cbc` | `0x00623cec` | `0x0055b6d1`, `0x0055b6d7`, `0x0055b6de`, `0x0055b6e8`. |

2026-06-17 B002 WaterFilterEffecter support sync: the adjusted `+0x04` Pane/GrafPort view at `0x00623c70` has slot `+0x44` at `0x00623cb4 -> 0x0055b5d0`, now documented by [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) as the caustic paint/update override.

## Layout Notes

- `ScreenEffecter` and `PixelEffecter` form the single-primary-vtable root and pixel-effect branch.
- MapPane consumes the primary table's first category slot through [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md). B002's 2026-06-17 pass confirms the slot is true for `PixelEffecter`/`XWaveEffecter` and false for `ScreenEffecter`/filter effecters, making `IsPixelEffecter()` or `UsesPrimaryEffectPass()` the best source-facing predicate direction.
- B001 2026-06-18 source-placement update for [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md): the physical true/false bodies used by the effecter first boolean slot are folded with system-message marker predicates and runtime/startup tables. Treat `IsPixelEffecter()` / `UsesPrimaryEffectPass()` as descriptive class-level slot names; do not route [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) through this vtable family as an emitted helper.
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) stays in this single-primary pixel branch. Its source-quality declaration uses the resolved 20-byte shake-state layout and an ordinary virtual destructor; the physical destructor slot is compiler glue, while `ApplyEffect` at `0x0055b160` performs timer-throttled map-image displacement.
- Overlay and filter subclasses embed/inherit a `Pane`-like subobject at `+0x04`, then additional adjusted vtable views at `+0xa4` and `+0xa8`, matching the general pane/update/event subobject pattern used elsewhere in the client. For FilterEffecter specifically, [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) now treats this as source multiple inheritance (`ScreenEffecter, Pane`) rather than a private Pane data member.
- Complete-object `+0x94` and `+0xf9` in FilterEffecter-derived classes should be read through the inherited Pane/GrafPort view: `+0x94` is view `+0x90` alpha state, and `+0xf9` is Pane-relative `+0xf5` flag state. Do not add FilterEffecter-owned fields for those offsets from vtable-view evidence.
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

## 2026-06-11 Slot And Xref Refresh

IDA MCP `py_eval` rechecked the live dwords, value names, boundaries, and representative xrefs:

- `0x006235a0 -> const ScreenEffecter::RTTI Complete Object Locator`, followed by `ScreenEffecter` vtable slots `0x0055c1c0`, `0x0055c1c0`, `0x0055c1c0`, `0x0055c1d0`, `0x0055a270`, `0x0055a280`, and `0x0055bfd0`.
- `0x006235c0 -> const PixelEffecter::RTTI Complete Object Locator`, followed by the pixel branch slots `0x0055c1b0`, `0x0055c1c0`, `0x0055c1c0`, `0x0055c1d0`, `0x0055a270`, `0x0055a280`, `0x0055bfd0`, and `0x0055a2d0`.
- Representative primary-table xrefs remain in the effecter runtime cluster: `ScreenEffecter` stores/reset refs at `0x0055a260`, `0x0055a290`, `0x0055a2c0`, and multiple derived teardown sites; `PixelEffecter` stores at `0x0055a2a9` and `0x0055a30b`; `OverlayEffecter` view stores/resets include `0x0055a329`, `0x0055a3f9`, `0x0055a590`, `0x0055a752`, `0x0055a942`, `0x0055acb2`, and destructor-strip refs; `FilterEffecter` refs include `0x0055ad41`, `0x0055adcc`, `0x0055af22`, raw cloud/static-cloud constructor writes `0x0055b05c`/`0x0055b0dc`, and destructor-strip refs.
- Water/lake evidence remains localized: `WaterFilterEffecter` primary refs are `0x0055b6d1`, `0x0055b7a9`, and `0x0055c0f0`; `LakeEffecter` has constructor store `0x0055b829`.
- Function lookup verifies the important tiny/shared slot targets: `0x0055c1b0` and `0x0055c1c0` are each 3-byte boolean/default virtuals, `0x0055a270` and `0x0055a280` are 1-byte no-op virtuals, `0x0055bfd0` is a 0x24-byte destructor/reset-style body, `0x0055c1d0` is a 0x2f-byte completion predicate, and `0x0055b870` is the 0x1b2-byte lake/reflection render body.
- Boundary dwords remain stable: `0x00623590` is adjacent `ScreenFadeOut` constant data, `0x00623d18` decodes as the first word of UTF-16LE `CAUST.EPF`, and `0x00623d58 -> const ScrollPane::RTTI Complete Object Locator`.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for every checked class in this family even though IDA confirms the table bases above:

`ScreenEffecter`, `PixelEffecter`, `OverlayEffecter`, `OverlayImageEffecter`, `OverlayFrameImageEffecter`, `OverlayImageOnPointEffecter`, `OverlayMovingImageEffecter`, `FilterEffecter`, `SolidColorFilterEffecter`, `CloudFilterEffecter`, `StaticCloudFilterEffecter`, `WaterFilterEffecter`, `EarthquakeEffecter`, `XWaveEffecter`, `YFlipEffecter`, and `LakeEffecter`.

## Reconstruction Notes

Use this page as the class-layout anchor for `render/Effects.cpp`. The vtable order supports the existing file-level grouping: root effecter types first, overlay branch, filter branch, then pixel/water/lake effect subclasses. Do not split the runtime effecters into unrelated one-class files solely because current generated output emits one class per file.

## Assignment Decision

`AUTOGEN_PARENT_UID` is set to [UID:0000IZ][Effects](by-file/Effects.md). This page clears `88/92`, and the direct file parent now clears `89/85` after the Batch149 parent-gate refresh. The file page is the narrowest documented source owner for the whole family because this vtable page spans `ScreenEffecter`, `PixelEffecter`, overlay subclasses, filter subclasses, pixel/water/lake subclasses, and their multiple adjusted views. Do not route this family through one individual class page.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal output is now a comment-only vtable-family block. This page remains the layout authority for the ScreenEffecter family, but the vtable/COL bytes are compiler-emitted from class declarations and virtual methods rooted at [UID:0000IZ][Effects](by-file/Effects.md), not handwritten static table source. The callback preserves the exact vtable-family boundary and routes handwritten source to class/exact method pages while keeping this page as table evidence.

## Changes

- 2026-06-25 B003 OverlayEffecter support sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: added exact [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) slot-level evidence. The vtable family now records primary scalar deleting destructor slot `0x00623600 -> 0x0055bbf0` and secondary adjusted scalar-deleting destructor thunks at `0x0055ba40`, `0x0055ba48`, and `0x0055ba53`, subtracting `0x04`, `0xa4`, and `0xa8` before the scalar-wrapper jump. These remain compiler-generated evidence for a normal virtual destructor declaration, not source methods.
- 2026-06-22 B015 OverlayFrameImageEffecter support sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: added exact [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md) slot-level evidence. The vtable family now records `0x006237a8 -> 0x0055a5e0` as the adjusted Pane/GrafPort render/paint slot, complete-object offset normalization from the adjusted receiver, complete `+0x140` owned-table versus complete `+0x144` draw-record separation, primary scalar deleting destructor slot `0x00623758 -> 0x0055bc90`, and destructor jump-strip routes as compiler-generated wrapper evidence.
- 2026-06-20 B004 OverlayImageEffecter support sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: added exact [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md) slot-level evidence. The vtable family now records `0x006236fc -> 0x0055a440` as the adjusted Pane/GrafPort render/apply slot, complete-object offset normalization from the adjusted receiver, constructor store refs, and compiler-generated scalar deleting destructor/adjustor thunk policy.
- 2026-06-20 B002 OverlayImageOnPointEffecter support sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: added exact [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md) slot-level evidence. The vtable family now records `0x00623854 -> 0x0055a7a0` as the adjusted Pane/GrafPort render/paint slot, complete-object offset normalization from the adjusted receiver, primary scalar deleting destructor slot `0x00623804 -> 0x0055be10`, and secondary scalar-deleting destructor adjustors subtracting `4`, `0xa4`, and `0xa8`.
- 2026-06-20 B001 OverlayMovingImageEffecter support sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: added the exact [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) slot-level evidence. The vtable family now records `0x00623900 -> 0x0055a990` as the adjusted Pane/GrafPort `OnPaint()` slot, primary scalar deleting destructor slot `0x006238b0 -> 0x0055bef0`, and secondary scalar-deleting destructor adjustors subtracting `4`, `0xa4`, and `0xa8`.
- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: added Earthquake's destructor/apply slot targets and single-primary pixel-branch support while preserving the `IsPixelEffecter()` / `UsesPrimaryEffectPass()` predicate naming policy and no-owner policy for the folded physical boolean stubs.
- 2026-06-19 B013 FilterEffecter source-quality implementation:
  - Score unchanged at `88/92`.
  - Summary/evidence: refined the FilterEffecter row/view-offset wording to match the accepted class shape. The filter branch still has four views, but the `+0x04` view is inherited Pane/GrafPort and `+0xa4/+0xa8` are adjusted inherited vptr slots; complete `+0x94/+0xf9` belong to inherited Pane/GrafPort state. Constructor stores at `0x0055ad41/0x0055ad4d/0x0055ad54/0x0055ad5e` remain the exact vtable-store evidence.
- 2026-06-18 B001 folded-boolean support sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: incorporated the [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) no-owner policy into the effecter vtable family. The first effecter slot still has a high-probability `IsPixelEffecter()` / `UsesPrimaryEffectPass()` interpretation, but the physical true/false addresses are folded with SystemMessagePanes and runtime table use and should not be emitted here.
- 2026-06-11:
  - Before: the page was `86/90` with strong family inventory and boundary evidence, but it did not contain a current slot-target/xref refresh or explicit strict parent-gate decision.
  - Changed to: raised to `88/92`, added live IDA MCP dword/value-name/xref/function-size refresh notes, and assigned to [UID:0000IZ][Effects](by-file/Effects.md) after the parent was refreshed to `89/85`.
  - Summary/evidence: live IDA MCP reconfirms the `ScreenEffecter`/`PixelEffecter` dwords, representative overlay/filter/water/lake table-store xrefs, tiny/default slot target sizes, and the `CAUST.EPF`/`ScrollPane` boundaries. The direct parent is the `Effects` file root because no individual class owns the whole vtable family.
- 2026-06-17 B002 WaterFilterEffecter support sync:
  - Score unchanged.
  - Summary/evidence: added the exact WaterFilterEffecter `+0x04` view slot evidence `0x00623cb4 -> 0x0055b5d0`, tying [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) to the pane/GrafPort paint/default virtual route.
- 2026-06-01:
  - Before: the page was marked `0/0` despite documenting most vtable bases, store xrefs, and layout notes, and it had no exact by-memory child for the pure ScreenEffecter-family vtable data.
  - Changed to: scored the page as `86/90`, marked it reconstructable, added exact child [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), and recorded the start/end boundary evidence.
  - Summary/evidence: IDA MCP `py_eval` confirms the family starts at `0x006235a0 -> ??_R4ScreenEffecter@@6B@`, carries named vtable bases through `0x00623cf8 -> ??_7LakeEffecter@@6B@`, and ends before `off_623D18` at `0x00623d18`; the broader aggregate ends before `0x00623d58 -> ??_R4ScrollPane@@6B@`.
