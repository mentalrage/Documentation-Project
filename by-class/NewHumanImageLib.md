*** UID:000092 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ImageFrameTable.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]

#include "../util/LObject.h"
#include <deque>
#include <vector>

class GrafPort;
class Motion;
struct NewHumanCompositionState;
struct NewHumanCommandSideRecord;

class NewHumanImageLib : public LObject
{
public:
    NewHumanImageLib();
    virtual ~NewHumanImageLib();

    void CalculateBounds(const HumanImageRenderParams *appearance,
                         unsigned char direction,
                         Motion *motion,
                         int frameIndex,
                         RectBounds *imageBounds,
                         RectBounds *secondaryBounds,
                         int renderMode,
                         bool moving,
                         int rotationStep);
    void Draw(GrafPort *target,
              const RectBounds *bounds,
              const HumanImageRenderParams *appearance,
              unsigned char direction,
              Motion *motion,
              unsigned int effectState,
              int frameIndex,
              bool useMapLightOverlay,
              FrameDrawRecord *translatedClipRecord,
              float translatedClipOffset,
              int renderMode,
              bool moving,
              int rotationStep);

private:
    void LoadPartFrameDrawRecord(int partIndex,
                                 unsigned short descriptorIndex,
                                 int motionIndex,
                                 int frameIndex,
                                 FrameDrawRecord *outRecord);
    void LoadMotionTable(const wchar_t *tableName);
    void LoadLayerTable(const wchar_t *tableName);
    void LoadPartTable(const wchar_t *tableName);
    void LoadPartSpriteDescriptors();
    void LoadAcc2DrwTable(const wchar_t *tableName);
    int CalculateCompositionBounds(const int *drawOrder,
                                   const NewHumanCompositionState &state,
                                   int sequence,
                                   int frame,
                                   RectBounds *bounds,
                                   RectBounds *projectedBounds,
                                   char direction);
    void ResolveCompositionPartRect(NewHumanPartEntry *part,
                                    unsigned short descriptorIndex,
                                    int motionIndex,
                                    int frameIndex,
                                    int yOffset,
                                    int xOffset,
                                    RectBounds *outBounds);
    void ResolveCompositionPartFrame(NewHumanPartEntry *part,
                                     unsigned short descriptorIndex,
                                     int motionIndex,
                                     int frameIndex,
                                     int yOffset,
                                     int xOffset,
                                     FrameDrawRecord *outRecord);

    std::vector<NewHumanPartEntry> m_partEntries;
    std::vector<NewHumanLayerEntry> m_layerEntries;
    std::vector<NewHumanMotionEntry> m_motionEntries;
    std::vector<NewHumanCompositionDrawCommand> m_compositionDrawCommands;
    std::deque<NewHumanCommandSideRecord *> m_loadedPartList;
    std::vector<Acc2DrwEntry> m_acc2drwEntries;
    std::vector<unsigned long> m_hairColorEntries;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewHumanImageLib

## ObjectStatusBlob composition evidence

- ObjectStatusBlob byte `+34` decimal (`+0x22`) is composition/render mode. Riding fields at decimal `+44/+46/+48` (`+0x2c/+0x2e/+0x30`) are definition index, packed palette/render flags, and signed Y offset from `RidableAnimals` columns 1-3. Colors at decimal `+50..+62` (`+0x32..+0x3e`) cover face, hair, shared skin/tint, body, weapon, shield/arrow, helmet, decorations, mantle, neck, and shoes; decimal `+52` (`+0x34`) is the shared skin/tint.
- ObjectStatusBlob `+4` is a context union for appearance id/full face id/HeadSelect head index, not universally Body. Body is `+8`. Address `0x0067a760` is the `g_pNewHumanImageLib` pointer, not a generic remap table; the pointed object's `HAIRCOL.TBL` vector at NewHumanImageLib `+0x54/+0x58` performs the low-five-bit hair-color remap.
- The exact `Part.tbl` row map is: 0 Body, 1 Coat, 2 Face, 3 Emotion, 4 FaceDec, 5 Hair, 6 Helmet, 7 HairDec, 8 Sword, 9 Spear, 10 Bow, 11 Fan, 12 Shield, 13 Arrow, 14 Mantle, 15 Shoes, 16 Neck, 17 All, 18 Back. Selectors and palette bytes come from UID00009S equipment/color fields, including both FaceDec slots.
- `BuildCompositionDrawCommands` at `0x004e21d0`, `RenderPreparedComposition` at `0x004e2fe0`, Draw at `0x004e06a0`, and bounds consumers establish field roles. The `+0x28` member is the typed per-draw `NewHumanCompositionDrawCommand` vector; NewHumanImageLib consumes ObjectStatusBlob but does not own parser children UID0004LK/UID0004LL/UID0004LM. Class score, owner/emitter, singleton/vtable/lifecycle, formal block, and unrelated layout remain unchanged.


## Status

- Confidence: strong for method families, singleton/static-lifetime ownership, resource/table ownership, vector-helper reachability, file parent placement, constructor source shape, and ordinary destructor source shape; medium-high for exact original helper/field/type spellings.
- Likely source file: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Owner/emitter: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) remains the aggregate source-module route. Method-level emitters such as the constructor, ordinary destructor, and exact FrameDrawRecord producers emit through this class. Formal CPP supplies `ImageFrameTable.h` plus children; formal H now supplies the complete class at position 20 after UID00050M/UID0001VF and before UID0000RT.
- Address ranges: [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md), source-adjacent vector/list helpers, singleton clear helper [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md), and scalar deleting destructor [UID:0002VN][0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor](by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md)
- Singleton: [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) at `0x0067a760`
- Vtable: [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md) at `0x0061b76c`
- Layout: [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)

## Class Purpose

`NewHumanImageLib` is the singleton-backed updated human composition/rendering library behind [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md). It loads a table-driven model of motions, layers, parts, part descriptors, accessory draw mappings, and hair colors, then builds and renders composed human sprite commands.

## Assignment Gate Notes

- The class remains the direct semantic parent for [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md). The constructor builds the `LObject` base, stores the [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md), publishes [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md), initializes all observed [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) fields through `+0x5c`, and loads the resource family owned by this class.
- The strict parent gate clears at `90/91`: this page records the singleton, vtable, exact `0x60` layout, method family, source-file parent, lifecycle pages, source-adjacent helpers, resource ownership, complete C++03 class declaration, and exact child-emission route. CPP retains `ImageFrameTable.h` and `[[CHILDREN]]`; H owns the one complete class declaration.

## Observed State

The constructor initializes several vector triplets and a small list/sentinel state:

```text
0x04  part entries begin/end/cap
0x10  layer entries begin/end/cap
0x1c  motion entries begin/end/cap
0x28  composition draw commands begin/end/cap (80-byte rows)
0x34  pending/list state
0x48  acc2drw entries begin/end/cap
0x54  hair color entries begin/end/cap
```

Field names are now implementation-ready inference for constructor/destructor first-draft C++; exact original spellings remain open to refinement during a later final-source audit.

## Method Families

| Method | Address | Role |
| --- | --- | --- |
| `NewHumanImageLib::NewHumanImageLib` | [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) | `91/92`; initializes vectors/list state and loads `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptors, `acc2drw.tbl`, and `HAIRCOL.TBL`; now has formal first-draft constructor C++. |
| `~NewHumanImageLib` | [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) | `90/91`; class-owned/emitting ordinary destructor with formal first-draft C++. Releases part resources, descriptor/frame data, layer child arrays, motion dynamic fields, hair colors, vector/list state, and [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md). |
| `Draw` / `RenderHuman` | `0x004e06a0`, `0x004e0900` | High-level draw entry points that select/render a human composition. |
| `CalculateBounds` / `ComputeOverlayBounds` | `0x004e09e0`, `0x004e0b90` | Bounds calculation for base and overlay draw paths. |
| `LoadPartFrameDrawRecord` | [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) | `91/93`; exact void class-owned child. It indexes an inline `0x10`-byte motion slot, returns without writing when slot `.frames` is null, selects a packed 9-byte frame row, and calls `g_pEPFLib->LoadFrameDrawRecord`. Both direct callers ignore EAX. |
| `GetHeadCount` | [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) | Below-gate `84/86` support page; tiny count accessor used by UI/look code, returning the field used by head/hair descriptor-count paths. |
| `LoadMotionTable` | [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) | `89/90`; class-owned/emitting method with formal first-draft C++. Parses `Motion.tbl`, reads a 23-byte header/count, builds 0x42-byte `NewHumanMotionEntry` rows from a 33-byte fixed file prefix plus per-frame dynamic arrays, appends through the `m_motionEntries` vector, and keeps the binary-observed `VectorGrowMotion` capacity-helper path. Constructor is the sole caller. |
| `LoadLayerTable` | [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) | `88/90`; class-owned/emitting first-draft helper with formal `void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)` C++ on the exact child page. Current MCP confirms raw `sub_4E1040`, modeled function extent `0x004e1040-0x004e11b0` exclusive while the filename key ends at `0x004e11af`, zero direct callers, 23-byte header/count reads, 32-byte `NewHumanLayerEntry` rows, optional child-index arrays, and [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md) only on the full-capacity path. |
| `LoadPartTable` | [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) | `88/90`; class-owned/emitting first-draft helper with formal `void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)` C++ on the exact child page. Current MCP confirms raw `sub_4E11B0`, exact body `0x004e11b0-0x004e13a7` plus padding to `0x004e13b0`, zero direct callers, 23-byte header/count reads, 32-byte `Part.tbl` file rows into 68-byte `NewHumanPartEntry` memory rows, 20-byte ANSI part-name conversion, [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md), and [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) only on the full-capacity path. |
| `LoadPartSpriteDescriptors` | [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md) | `88/90`; class-owned/emitting first-draft helper with formal `void NewHumanImageLib::LoadPartSpriteDescriptors()` C++ on the exact child page. Current MCP confirms raw `sub_4E13B0`, size `0x446`, constructor-only caller `0x004e017c`, `.DSC` suffix byte/xref proof, 23-byte header/count reads, descriptor-count allocation, packed descriptor offsets, and nested sequence-frame tables. |
| `LoadAcc2DrwTable` | [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) | `88/90`; class-owned/emitting first-draft helper with formal `void NewHumanImageLib::LoadAcc2DrwTable(const wchar_t *tableName)` C++ on the exact child page. Current MCP confirms raw `sub_4E1800`, size `0x1c5`, constructor-only caller `0x004e0188`, `acc2drw.tbl` literal xref `0x004e0181` / `0x0061c324`, `m_partEntries[7].descriptorCount` as the row count source, decimal hundreds/tens/ones flags into `Acc2DrwEntry.enabled[0..2]`, and file-local [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) marker support only on the full-capacity append path. |
| `BuildCompositionDrawCommands` | `0x004e21d0` | Builds typed 80-byte `NewHumanCompositionDrawCommand` rows in `m_compositionDrawCommands`; its compiler-only append support is UID0004DQ/UID0004PA. Part/tag case `0x3d` performs the observed target append and then the common append, so the duplicate row behavior is preserved. |
| `BuildPartDrawCommand` | `0x004e2eb0` | Builds one part draw command. Its command-side pointer-ring/vector growth support is [UID:0004DN][0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector](by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md), called once at `0x004e2f7a`; UID0004DN is source-routed through the NewHuman file but is not itself a normal class method because the helper receiver is `this + 13` / command-side storage at byte offset `+0x34`. |
| `RenderPreparedComposition` | `0x004e2fe0` | Traverses `m_compositionDrawCommands` in exact 80-byte strides, consumes `FrameDrawRecord`, `SurfaceSpriteBlitOptions`, and `DLPalette *`, unions/rebases bounds, and invokes the Surface sprite callbacks. |
| [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) | `0x004e31f0` | `91/92`; class-owned and emitted through this class. Complete formal CPP includes `ImageLib.h`, `ResourceLayoutTable.h`, and `RidingImageLib.h`, computes the full composition bounds, uses exact `ResourceLayoutNameRecord` GFACE access through public Find and the inline accessor, and passes `ridingEpfPackage` at both ResourceLayout raw-rectangle calls. Part.tbl dispatch, projection, all branches, and source order remain intact. |
| `CalculateCompositionBoundsRetainedVariant` | [UID:000436][0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant](by-memory/0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant.md) | `88/90`; class-owned/reconstructable retained variant in the post-[UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) gap. It intentionally has no emitter and no formal C++ because current MCP session `60724697` plus raw VA/RVA/rel32/reloc route checks find no external entry route. |
| `ResolveCompositionPartRect` | [UID:000437][0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect](by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md) | `92/94`; exact void class-owned helper with 31 ignored-result callers. It guards zero descriptors, falls back to descriptor zero, indexes the inline motion slot and packed frame row, copies or clears `RectBounds`, and calls `RectBounds::Offset`. |
| `ResolveCompositionPartFrame` | [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md) | `92/94`; exact void class-owned helper used 18 times by `RenderComposition`. It preserves descriptor-zero fallback without adding a zero-count guard, returns without writing on null slot `.frames`, projects through `g_pEPFLib->LoadFrameDrawRecord`, and offsets `FrameDrawRecord::sourceRect`. |
| `RenderComposition` | `0x004e4280` | Full composition render path and owner of one local `std::vector<FrameDrawRecord>` append: initializes/populates a 40-byte local, appends inline with capacity, and invokes UID00017U only on the full-capacity path. |
| [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) | `[0x004e57c0,0x004e598a)` | File-routed compiler grow/insert support at `92/94`, emitted through UID0000LR as an exact marker; not an ordinary class method. |
| [UID:0004DO][0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport](by-memory/0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport.md) | `[0x004e6ff0,0x004e7026)` | File-routed private uninitialized prefix/suffix range-copy support at `92/94`, emitted through UID0000LR as an exact marker; not an ordinary class method. |
| [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) | `0x004e4f10` | File-local NewHumanImageLib vector-growth support at `86/90`; emits a source-disposition marker through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not a class method body. Current MCP confirms raw `sub_4E4F10` size `0x18d`, body `0x004e4f10-0x004e509d` plus three padding bytes, sole caller `0x004e195a` in UID00041D, receiver `this + 18` / object offset `+0x48`, and 3-byte `Acc2DrwEntry` grow/insert behavior. |
| [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md) | `0x004e50a0` | File-local NewHumanImageLib layer-entry vector-growth support at `87/89`; emits a source-disposition marker through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not a class method body. B011's MCP pass confirms raw `sub_4E50A0` size `0x19e` (`414`, Verified with int_convert.py), no function at `0x004e523e`, caller sites `0x004dffb2` and `0x004e1171`, receiver as the layer vector header / `this+0x10`, and `0x20` (`32`, Verified with int_convert.py) byte `NewHumanLayerEntry` grow/insert behavior. |
| [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) | `0x004e5240` | File-local NewHumanImageLib marker support at `87/90`; full-capacity `m_motionEntries` vector-growth slow path called only from `LoadMotionTable`, not a class method body. |
| [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) | `0x004e5420` | File-local NewHumanImageLib part-entry vector-growth support at `87/90`; emits a source-disposition marker through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not a class method body. B007's MCP pass confirms raw `sub_4E5420` size `0x1d6` / 470 bytes, exactly two callers at constructor `0x004e0148` and UID00041B `0x004e1356`, receiver as the part-vector header / object offset `+4`, and 68-byte `NewHumanPartEntry` grow/insert behavior. |
| [UID:0004DN][0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector](by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md) | `0x004e6e50` | File-local NewHumanImageLib command-side pointer-ring/vector support at `88/91`; emits a source-disposition marker through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not a class method body. B004 current MCP session `supervisor_recovery_20260705` confirms exact range/size/padding, unique signature, one `BuildPartDrawCommand` callsite at `0x004e2f7a`, `this + 13` / byte-offset `+0x34` receiver proof, 4-byte pointer-slot growth, caller-side 9-byte side-record allocation/copy, and rejected direct VectorHelpers/class-method/no-owner/standalone-body alternatives. |
| [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) | `0x004e5dd0` | File-local marker support at `88/91`; `m_motionEntries` vector-storage cleanup reached by the destructor and constructor cleanup metadata, not a class method body. |
| `ScalarDeletingDestructor` | [UID:0002VN][0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor](by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md) | `86/91`; compiler-generated scalar-deleting wrapper with optional delete and flag-`4` guard-check branch; first [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md) slot. Its formal block is comment-only because `virtual ~NewHumanImageLib()` plus the ordinary destructor should regenerate it. |

[UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) is a concrete UI preview consumer of the base human render path. Its `OnPaint` status-kind `0` branch calls the singleton [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md), uses `0x004e09e0` as `CalculateBounds` / `CalculateHumanBounds`, and uses `0x004e06a0` as `Draw` / `RenderHuman` with a preview/render-mode constant. This reinforces the existing method aliases without proving the exact original preview flag spelling.

Singleton/static-lifetime support:

| Function | Address | Role |
| --- | --- | --- |
| `NewHumanImageLibSingletonClearHelper` | [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md) | Clears `g_pNewHumanImageLib` / `dword_67A760`. |

Batch 121 rechecked this helper as file-local static cleanup glue. It has no ordinary callsites and no `this` parameter; IDA reports a single constructor-associated cleanup-table xref at `0x00600230`, and `xrefs_to 0x0067a760` reports 52 lifecycle/consumer references around the class singleton. The helper is therefore parented to [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), while this class page records why it belongs to the `NewHumanImageLib` lifetime.

## 2026-07-13 FrameDrawRecord Vector Source Sync

`RenderComposition` is the exact semantic source owner for UID00017U and UID0004DO. It initializes one 40-byte local through `0x00457a60`, populates it through 18 UID000438 calls and the shared `LoadFrameDrawRecord` path, then appends the accepted `FrameDrawRecord`. The no-capacity path copies two 16-byte lanes plus one 8-byte tail inline; the sole full-capacity call at `0x004e4c14` passes position equal to end and reaches UID00017U. UID00017U performs 1.5x vector growth, aligned allocation, inserted-record copy, checked free, and triplet update; its private middle-insert branch calls UID0004DO for prefix and suffix relocation.

The compiler-support elements are shallow-copied. No element constructor, destructor, copy hook, validation, or per-element cleanup exists, and pointer fields remain borrowed values. `FrameDrawRecord` and `EPFTileContext` are both 40 bytes and share initializer ABI, but their `+0x20/+0x24` field semantics differ, so the class uses the accepted FrameDrawRecord declaration rather than collapsing the types. Historical undeclared `NewHumanDrawRecord` is superseded.

UID00017U/UID0004DO are reconstructable exact ranges owned/emitted by UID0000LR, but they are not class methods and have deliberately blank positions. Their exact markers identify `frameDrawRecords.push_back(frameDrawRecord)` as the source operation. UID0000BS is a NONE/FALSE/blank historical index; direct VectorHelpers ownership and handwritten private-STL bodies are rejected.

## 2026-06-16 Evidence Refresh

Live IDA MCP was used to recheck the singleton/vtable/lifecycle evidence, resource-table helper ownership, generated-output omissions, and final field/type blockers:

- `lookup_funcs` confirms the main method family: constructor `0x004dfd10` size `0x53a`, destructor `0x004e0250` size `0x374`, draw/bounds/load/build/render methods through `0x004e4280`, `VectorGrowMotion` `0x004e5240` size `0x1d5`, record-vector helper `0x004e57c0` size `0x1ca`, singleton-clear helper `0x004e5be0` size `0x0b`, `DestroyMotionVector` `0x004e5dd0` size `0x69`, and scalar deleting destructor `0x004e6870` size `0x38`.
- B011's accepted UID00022R split added [UID:0004DN][0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector](by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md) and [UID:0004DQ][0x004e70a0-0x004e70e9.NewHumanCompositionDrawCommandPushBackCompilerSupport](by-memory/0x004e70a0-0x004e70e9.NewHumanCompositionDrawCommandPushBackCompilerSupport.md) as file-routed NewHuman command-side helpers. UID0004DN remains separate `+0x34` pointer-ring support for `BuildPartDrawCommand`. UID0004DQ is now resolved at `92/93` as marker-only typed `std::vector<NewHumanCompositionDrawCommand>::push_back` support for the `+0x28` member, with sole caller `0x004e2c83`, exact 80-byte fast copy, and [UID:0004PA][0x004e5600-0x004e57bb.NewHumanCompositionDrawCommandVectorGrowInsertCompilerSupport](by-memory/0x004e5600-0x004e57bb.NewHumanCompositionDrawCommandVectorGrowInsertCompilerSupport.md) as the three-caller full-capacity companion. Neither compiler helper is an ordinary class method or handwritten source body.
- `xrefs_to 0x004dfd10` returns the startup/application construction caller at `0x004f60a1`. `xrefs_to 0x0061b76c` returns constructor/destructor vtable writes at `0x004dfd78` and `0x004e027e`; the scalar deleting destructor is the vtable slot target at `0x0061b76c`.
- `xrefs_to 0x0067a760` returns 52 singleton refs spanning constructor/destructor/helper lifecycle, startup/shutdown, fitting-room/look setup, and avatar/render/UI consumers. `xrefs_to 0x004e5be0` returns the constructor cleanup-table ref at `0x00600230`.
- `xrefs_to 0x004e5240` returns a single caller at `0x004e0ff2` inside `LoadMotionTable`; current UID000185 MCP session `supervisor_recovery_20260705` confirms `xrefs_to 0x004e5dd0` returns destructor and constructor-cleanup refs at `0x004e0547` and `0x0060025a`. This keeps the `Motion.tbl` vector helpers with `NewHumanImageLib`, not the runtime [UID:00008R][Motion](by-class/Motion.md) class. UID000185 is class-lifetime support for `m_motionEntries`: its receiver is the vector header rather than a `NewHumanImageLib *`, so it remains file-local marker support and not a class method.
- `callees` confirms constructor fanout through `LoadMotionTable`, part/resource string conversion, sprite path resolution, part descriptor loading, accessory table loading, and cleanup/unwind helpers. Composition bounds still calls the shared raw resource-rectangle helper, and full render still uses the record-vector insert helper.

These checks resolve the stale scalar-wrapper-page note and support a confidence raise for class/file ownership. Remaining blockers are final field/type names for vector records, row layouts for `Motion.tbl`/`Layer.tbl`/`Part.tbl`/`acc2drw.tbl`, helper declaration placement, and exact source-level names for disabled owner-relevant helpers.

Owner-relevant exact children:

| Method | Address | Role |
| --- | --- | --- |
| [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) | `0x004e0d70-0x004e0dcf` | The 2026-06-30 callback first resolved this method at `88/90`; that dated promotion remains historical evidence. Its current state is `91/93`, owner/emitter [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md), with formal C++ on the exact child page. It loads one part-specific frame draw record through canonical [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) using the accepted `g_pEPFLib` ResourceLayoutTable/ImageLib-facet receiver route. |
| [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) | `0x004e0dd0-0x004e0dda` | Tiny count accessor used by UI/look code; `84/86`, no owner/emitter metadata yet. |

## 2026-06-25 Constructor C++ And Helper Child Sync

B011 accepted report implementation raises the constructor page [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) to `91/92` and inserts formal first-draft constructor C++. The constructor code uses source-facing inferred names and remains scoped to the constructor body: it calls `LoadMotionTable`, `LoadPartSpriteDescriptors`, and `LoadAcc2DrwTable` out of line, while preserving constructor-inline loops for `Layer.tbl`, `Part.tbl`, and `HAIRCOL.TBL`. This class remains the direct semantic owner for [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md); the source route continues through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).

The newly created helper pages were deliberately below-gate support pages at B011 time unless their own later source-quality passes promoted them. [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) remains support-only where its own metadata still says no-owner/non-emitting. [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) is excluded from that below-gate group by B004's 2026-06-30 implementation; [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) is excluded by B002's 2026-06-30 implementation; [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) is excluded by B006's 2026-06-30 implementation as a class-owned/emitting `NewHumanImageLib::LoadLayerTable` helper at `88/90`; [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) is excluded by B007's 2026-06-30 implementation as a class-owned/emitting `NewHumanImageLib::LoadPartTable` helper at `88/90`; [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md) is excluded by B008's 2026-06-30 implementation as a class-owned/emitting `NewHumanImageLib::LoadPartSpriteDescriptors` helper at `88/90`; [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) is excluded by B009's 2026-06-30 implementation as a class-owned/emitting `NewHumanImageLib::LoadAcc2DrwTable` helper at `88/90`; [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) is excluded by B010's 2026-06-30 implementation as file-owned/emitting marker support at `86/90`; [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md) is excluded by B011's 2026-06-30 implementation as file-owned/emitting marker support at `87/89`; and [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) is excluded by B007's 2026-07-01 implementation as file-owned/emitting marker support at `87/90`.

The local names `LoadLayerTable` and `LoadPartTable` replace old placeholder helper wording. Current xrefs show no calls from the constructor to `0x004e1040` or `0x004e11b0`; [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) and [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) still own retained source-shaped helper bodies despite the no-xref caveat, while the constructor binary has its own inline `Layer.tbl` and `Part.tbl` loops.

## 2026-06-30 LoadPartFrameDrawRecord Source-Quality Sync

B004's accepted 2026-06-30 implementation promoted [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) from the old B011 below-gate/no-owner state to a direct [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) owner/emitter at the then-current `88/90`. The current state is `91/93` after the later source-quality pass, while the source route remains [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). At the 2026-06-30 sync this class overview still kept its aggregate C++ block blank; the 2026-07-13 UID0004DO callback superseded only that header-container state by emitting `#include "ImageFrameTable.h"` plus the class-container marker, while the method body remains only on the exact child page.

Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E0D70` at `0x004e0d70`, size `0x5f`, exact half-open range `0x004e0d70-0x004e0dcf`, one `0xcc` padding byte before successor `sub_4E0DD0`, and three basic blocks. Current IDA names remain raw for `sub_4E0D70` and `sub_4D1600`; the accepted source-facing names are documentation-supported inference. The two code xrefs are [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) paint at `0x0050141a` with part category `5` and [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md) paint at `0x005018fa` with part category `2`.

The method indexes `m_partEntries[partIndex]`, uses the 0x44 part stride, reads part row `+0x3c` as the 0x20-byte descriptor table, reads descriptor `+0x1c` as the nullable motion/sequence table, selects the slot at `base + 0x10 * motionIndex + 0x0c`, returns without an output write on the null branch, reads the 0x09-stride frame mapping row's first dword as `recordIndex`, adds descriptor `drawIndexBase` at `+0x08`, and calls [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) with part row `+0x40` / `part->rawRecords` and the caller-provided `FrameDrawRecord *outRecord`. The former `NewHumanDrawRecord` spelling is historical shorthand only.

Negative ownership evidence still proves UID000417 is not constructor code because it lies outside [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) and has only UI paint xrefs, and it is not owned by the hair/face selector classes because those are consumers. The 2026-06-30 interpretation also rejected ImageFrameTable, ResourceLayout, EPF/ImageLib globals, GrafPort, PaletteLib, Surface callbacks, and `dword_67A744` from the source route because callee `sub_4D1600` overwrites incoming `ecx` from stack argument `frameIndex` at `0x004d1603`. That blanket callee/receiver rejection is historical and superseded: UID000417 itself remains NewHumanImageLib-owned, but canonical callee [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) is the non-virtual `ResourceLayoutTable::LoadFrameDrawRecord` ImageLib-facet method, and systematic caller setup proves [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) `g_pEPFLib` / `dword_67A744` is its source receiver route. Reusing the otherwise-unused incoming member receiver register inside UID0002P6 does not make the callee a free ImageFrameTable helper.

## 2026-06-26 Composition Bounds Source-Quality Sync

B014's accepted implementation historically made [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) a direct class-owned emitter at `89/90`. The formal C++ remains scoped to that method and uses inferred source-facing support names documented in [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md): `NewHumanCompositionState`, `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `Acc2DrwEntry::enabled`, `kNewHumanRidingFrameRectOffsets`, and projection fields at [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md) offsets `+0x3d4/+0x3d8`. The 2026-08-16 closure below supersedes only the old compile-dependency/type/field spellings and raises the child to `91/92`.

## 2026-08-16 ResourceLayout And Riding Dependency Closure

UID0002V8's complete formal CPP now begins with the literal owner headers `ImageLib.h`, `ResourceLayoutTable.h`, and `RidingImageLib.h`. Its GFACE branch calls the now-public `ImageLib::FindResourceIndex`, obtains the exact `ResourceLayoutNameRecord` through the compiler-covered inline `GetResourceLayout(int) const`, tests `entryCount` and `entries`, and copies the first row's leading 16 bytes as `RectBounds`. This removes the historical undefined `ResourceLayoutRecord` and nonexistent `ResourceLayoutEntry::rect` assumptions without altering behavior.

The two raw-record rectangle calls use `g_pRidingImageLib->ridingEpfPackage`, matching the binary `+0x0c` field loads. [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) grants the narrow `friend class NewHumanImageLib;` route before its private fields; no broad friendship, duplicate Riding declaration, public storage, or accessor is introduced. The class score remains unchanged, and the complete NewHuman declaration stays in this page's established formal H channel with no ResourceLayout row/helper or Riding class duplication.

The class owns two new emitting helper pages: [UID:000437][0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect](by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md) and [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md). These resolve Part.tbl descriptor/frame data for bounds and render paths, respectively.

The class also owns the retained variant [UID:000436][0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant](by-memory/0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant.md), but that page is intentionally non-emitting. Current MCP session `60724697` confirms no modeled function/decompile at `0x004e3a80`, zero xrefs to the entry and end/alignment, one internal jump-table xref from `0x004e3d6c` to `0x004e4110`, exact prologue/tail/jump-table bytes, and retained calls into the same composition helper family. The raw route proof remains negative: VA/RVA scans find no exact entry pointer, direct rel32 branch scans find no outside branch into the retained range, the PE relocation directory is empty, and the only absolute pointers into the body are its internal jump-table dwords at `0x004e4110-0x004e4138`. That rejects merging the retained body into [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md), adding a covered-by marker, or emitting a speculative duplicate method.

The Part.tbl row-index/draw-tag map from [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) is class-level consumer evidence for the layout: rows 0-18 are selected by draw tags `0x32..0x3e`, with accessory gating via `acc2drw.tbl`, equipment bucket helpers at `0x004e05d0` and `0x004e0630`, and riding overlay raw rectangles through [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md).

## 2026-06-26 Destructor Source-Quality Sync

B010's accepted implementation makes [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) a direct class-owned emitter at `90/91`. The method route is now [UID:000092] for owner/emitter and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) for the source module. This replaces the stale file-owned blank-C++ treatment: the destructor is the ordinary `NewHumanImageLib::~NewHumanImageLib()` body required by the scalar-deleting wrapper [UID:0002VN][0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor](by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md).

The destructor formal block uses the same implementation-ready inferred member and row names accepted for constructor/layout/composition work: `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_compositionDrawCommands`, `m_loadedPartList`, `m_acc2drwEntries`, `m_hairColorEntries`, `NewHumanPartEntry`, `NewHumanLayerEntry`, `NewHumanMotionEntry`, `NewHumanPartFrameDescriptor`, and `NewHumanSequenceFrameTable`. MCP session `80de0a67` reconfirmed the scalar-wrapper call at `0x004e6876`, vtable restore at `0x004e027e`, singleton clear at `0x004e059e`, helper callees, helper xrefs, and exact function boundary. The 2026-08-16 closure supplies these row types and the class in formal H; exact original private spellings remain inferred and cap confidence at `91`.

The destructor helper names are source-facing inference backed by current body and xref evidence: `DestroyAcc2DrwVector` for the 3-byte `acc2drw.tbl` vector at `+0x48`, `DestroyLoadedPartListState` for the `+0x34` list/sentinel state, historical/search alias [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) for `m_motionEntries` vector-storage cleanup, `DestroyPartVector` for the 68-byte part vector, and descriptive lowered-cleanup alias `DestroyCompositionDrawCommands` for the shallow 80-byte command vector at `+0x28`. That alias and UID000185 are not proof of standalone source-authored helper bodies. The broad 4-byte vector helper at `0x00423810` remains shared and is represented in the formal destructor as `m_hairColorEntries.clear()`.

## 2026-06-30 LoadMotionTable Source-Quality Sync

B002's accepted [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) implementation promotes the `Motion.tbl` loader to a direct [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) owner/emitter at `89/90`. Current MCP session `supervisor_resume_20260629` reported `sub_4E0E20` at `0x004e0e20`, size `0x21f`, with the sole constructor caller at `0x004dfe5a`, the `Motion.tbl` literal xref at `0x004dfe4f` / `0x0061c2e4`, and the sole `VectorGrowMotion` capacity-helper call at `0x004e0ff2`.

The promoted method carries formal first-draft `void NewHumanImageLib::LoadMotionTable(const wchar_t *tableName)` C++. It preserves the binary-observed source shape: the constructor calls the helper out of line, the helper reads the 23-byte table header and count, zeroes a 0x42-byte `NewHumanMotionEntry`, reads a 33-byte fixed file prefix (`motionId`, 20-byte `name`, `direction`, `fallbackMotionId`, `frameCount`), allocates `frameOffsets` and `frameData`, reads each 2-byte frame offset/value plus 120-byte frame-data block, and appends into `m_motionEntries`.

The old B011 shorthand "0x42-byte rows" is now refined: `0x42` is the in-memory entry stride and vector element size, while the `Motion.tbl` file row has a fixed prefix plus count-driven variable frame payload. Direct read-only sampling of `E:\NTK\Resources\NexusTK\Data\char.dat` at the documented `Motion.tbl` offset confirms header `MotionStandard`, count `68`, initial rows `NormalWalkNorth/East/South/West`, direction bytes `0..3`, and `fallbackMotionId=-1` for normal rows. Exact original field spellings and 120-byte frame payload semantics remain inferred, so the method score stays below final-audit confidence.

## 2026-06-30 LoadLayerTable Source-Quality Sync

B006's accepted [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) implementation promotes the retained `Layer.tbl` loader to a direct [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) owner/emitter at `88/90`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E1040`, size `0x170`, 133 instructions, 17 blocks, zero direct callers, modeled `thiscall` receiver plus `wchar_t *` path argument, and the function-extent nuance that the by-memory filename key ends at `0x004e11af` while the modeled exclusive end is `0x004e11b0`.

The method carries formal first-draft `void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)` C++ on the exact child page. It opens the supplied path rather than hard-coding `L"Layer.tbl"`, reads a 23-byte header and 4-byte count, reads each 32-byte `NewHumanLayerEntry` as `layerId`, 20-byte `name`, `childCount`, and optional `childIndexes`, and appends through `m_layerEntries.push_back(layer)`. The binary direct-copy/full-capacity split is represented source-wise by that push; [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md) is now file-local marker support for the capacity path, not a class method body and not a separate promoted standalone helper body.

The zero-xref caveat remains: the constructor does not call `0x004e1040` and still has its own inline `Layer.tbl` loop. That negative caller evidence rejects constructor folding and stale `MotionTableLocalHelperA` naming, but it no longer blocks the retained helper from emitting through this class and source file.

## 2026-06-30 LoadPartTable Source-Quality Sync

B007's accepted [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) implementation promotes the retained `Part.tbl` loader to a direct [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) owner/emitter at `88/90`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E11B0`, size `0x1f7`, exact body `0x004e11b0-0x004e13a7`, nine bytes of `0xcc` padding at `0x004e13a7-0x004e13b0`, zero direct callers, modeled `thiscall` receiver plus `wchar_t *` path argument, and the [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) full-capacity call.

The method carries formal first-draft `void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)` C++ on the exact child page. It opens the supplied path rather than hard-coding `L"Part.tbl"`, reads a 23-byte header and 4-byte count, reads each 32-byte file row as a part id, 20-byte ANSI name, `drawIndexBase`, and `descriptorBase`, converts the name to wide text, resolves part archive metadata through [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md), and appends into `m_partEntries`. The class-level layout still treats the appended `NewHumanPartEntry` as a 68-byte in-memory row; direct `char.dat` sampling confirms `PartInformation`, count `19`, payload `608` bytes, and first rows such as `Body 0 19999`, `Coat 20000 39999`, `Face 200 999`, `Emotion 1 1`, and `FaceDec 0 9999`.

The zero-xref caveat remains: the constructor does not call `0x004e11b0` and still has its own inline `Part.tbl` loop. That negative caller evidence rejects constructor folding and stale `MotionTableLocalHelperB` naming, but it no longer blocks the retained helper from emitting through this class and source file. Exact original names/semantics for the two 4-byte scalar fields remain inferred score caps, not implementation blockers.

## 2026-06-30 LoadPartSpriteDescriptors Source-Quality Sync

B008's accepted [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md) implementation promotes the constructor-called descriptor loader to a direct [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) owner/emitter at `88/90`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E13B0`, size `0x446`, exact body `0x004e13b0-0x004e17f6`, constructor-only caller `0x004e017c`, successor `sub_4E1800`, and the byte-level `.DSC` suffix at `0x0061c33c` with the target xref at `0x004e1435`.

The method carries formal first-draft `void NewHumanImageLib::LoadPartSpriteDescriptors()` C++ on the exact child page. It walks `m_partEntries`, appends `.DSC` to each part name, reads a 23-byte header and descriptor count, allocates 0x20-byte `NewHumanPartFrameDescriptor` rows, records packed count/pointer fields at descriptor `+0x10/+0x11` and `+0x15/+0x16`, accumulates raw-record counts, and builds motion-indexed `NewHumanSequenceFrameTable` arrays with 9-byte sequence-frame rows. The accepted source-facing names for the first descriptor dwords remain inferred, while the `.DSC` path, count/allocation behavior, and sequence table shape are direct binary facts.

## 2026-06-30 VectorGrowAcc2Drw Source-Quality Sync

B010's accepted [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) implementation promotes the `m_acc2drwEntries` grow/insert slow path out of the old B011 below-gate group to file-local NewHumanImageLib support at `86/90`. It is owned and emitted by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not by this class page as a method, because the target receiver is the vector header passed from UID00041D rather than a `NewHumanImageLib *`.

Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E4F10`, size `0x18d`, executable body `0x004e4f10-0x004e509d`, three `0xcc` padding bytes through `0x004e50a0`, one caller at `0x004e195a` in [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md), and caller argument `this + 18`, which is object offset `+0x48` and matches the accepted `m_acc2drwEntries` layout. The helper divides vector spans by 3, grows capacity by capacity plus half, uses small/large allocation paths, copies the inserted `Acc2DrwEntry` as two bytes plus one byte, memmoves prefix/suffix spans, frees old storage, and updates begin/end/capacity.

The formal child C++ is a source-disposition marker. It rejects a standalone decompiler-shaped helper body, direct generic [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) ownership, runtime/non-reconstructable classification, and class-method ownership. B009's UID00041D implementation now supplies the loader source body that calls this vector-growth marker only as source-level `m_acc2drwEntries.push_back(entry)` full-capacity support.

## 2026-06-30 VectorGrowLayer Source-Quality Sync

B011's accepted [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md) implementation promotes the `m_layerEntries` grow/insert slow path out of the old below-gate group to file-local NewHumanImageLib support at `87/89`. It is owned and emitted by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not by this class page as a method, because the target receiver is the vector header passed from the constructor and UID00041A rather than a `NewHumanImageLib *`.

B011's current MCP pass confirms raw `sub_4E50A0`, size `0x19e` (`414`, Verified with int_convert.py), no function at `0x004e523e`, successor `sub_4E5240`, two callsites at `0x004dffb2` and `0x004e1171`, and caller setup that passes the layer vector at object offset `+0x10`. The helper operates on `0x20` (`32`, Verified with int_convert.py) byte `NewHumanLayerEntry` rows, grows capacity, allocates replacement storage, relocates prefix/insert/suffix rows, frees old storage, and updates begin/end/capacity.

The formal child C++ is a source-disposition marker. It rejects a standalone decompiler-shaped `VectorGrowLayer` helper body, direct generic [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) ownership, class-method ownership, continued no-owner/non-emitting status, and unrelated TimerMgr UID-collision cleanup. The constructor and UID00041A already supply the source-level behavior as `m_layerEntries.push_back(layer)`; UID00041F only records the out-of-line full-capacity lowering route, with VectorHelpers reserved as a compatibility-template fallback if typed NewHuman source cannot regenerate the helper.

## 2026-07-04 VectorGrowMotion Source-Quality Sync

B005's accepted [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) implementation promotes the `m_motionEntries` grow/insert slow path from the older one-line marker state to file-local NewHumanImageLib support at `87/90`. It is owned and emitted by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not by this class page as a method, because the target receiver is the vector header passed from UID000419 rather than a `NewHumanImageLib *`.

B005 current MCP session `60724697` confirms raw `sub_4E5240`, size `0x1d5`, 176 instructions, exact body `0x004e5240-0x004e5415`, one callsite at `0x004e0ff2` in UID000419, caller setup through the `m_motionEntries` vector at object offset `+0x1c`, and 66-byte `NewHumanMotionEntry` grow/insert behavior. The helper allocates replacement storage, relocates prefix/insert/suffix rows, frees old storage, updates begin/end/capacity, and ends before eleven `0xcc` padding bytes to UID00041G.

The formal child C++ is a source-disposition marker. It rejects a standalone decompiler-shaped `VectorGrowMotion` helper body, direct generic [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) ownership, class-method ownership, runtime Motion ownership, continued no-owner/non-emitting status, data/padding/dead-code classification, and range extension. UID000419 already supplies the source-level behavior as `m_motionEntries.push_back(motion)`; UID00017T records only the out-of-line full-capacity lowering route, with VectorHelpers reserved as a compatibility-template fallback if typed NewHuman source cannot regenerate the helper.

## 2026-07-06 DestroyMotionVector Source-Quality Sync

B015's accepted [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) implementation promotes the `m_motionEntries` cleanup helper documentation to file-local marker support at `88/91`. It is owned/emitted by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not by this class page as a method, because the target receiver is the vector header passed by the destructor rather than a `NewHumanImageLib *`.

Current MCP session `supervisor_recovery_20260705` confirms raw `sub_4E5DD0`, size `0x69`, exact range `0x004e5dd0-0x004e5e39`, ordinary destructor callsite `0x004e0547`, constructor cleanup-table reference `0x0060025a`, cleanup-only callees `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`, the raw-base large-allocation guard, triplet reset, unique signature, and padding before successor `0x004e5e40`. Lookup/type/listing checks found no source proof for `DestroyMotionVector`, `MotionEntryVector`, or `NewHumanMotionEntry`, so `DestroyMotionVector` remains a historical/search alias and no standalone helper body is emitted. Source behavior remains the destructor's per-row `NewHumanMotionEntry` payload cleanup followed by vector member cleanup.

## 2026-07-01 VectorGrowPart Source-Quality Sync

B007's accepted [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) implementation promotes the `m_partEntries` grow/insert slow path out of the old below-gate group to file-local NewHumanImageLib support at `87/90`. It is owned and emitted by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not by this class page as a method, because the target receiver is the vector header passed from the constructor and UID00041B rather than a `NewHumanImageLib *`.

B007's current MCP pass confirms raw `sub_4E5420`, size `0x1d6` / 470 bytes, exact body `0x004e5420-0x004e55f6`, padding at `0x004e55f6` before successor `sub_4E5600`, two callsites at `0x004e0148` and `0x004e1356`, and caller setup that passes the part vector at object offset `+4`. The helper operates on `0x44` / 68-byte `NewHumanPartEntry` rows, grows capacity, allocates replacement storage, copies the inserted row, relocates prefix/suffix rows with `_memmove_0`, frees old storage, and updates begin/end/capacity.

The formal child C++ is a source-disposition marker. It rejects a standalone decompiler-shaped `VectorGrowPart` helper body, direct generic [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) ownership, class-method ownership, and continued no-owner/non-emitting status. The constructor and UID00041B already supply the source-level behavior as `m_partEntries.push_back(part)`; UID00041G records only the out-of-line full-capacity lowering route, with VectorHelpers reserved as a compatibility-template fallback if typed NewHuman source cannot regenerate the helper.

## 2026-07-22 Composition Helper And Child-Emission Reanalysis

- UID000417, UID000437, and UID000438 are exact non-static `void` members. Their callers prepare the NewHuman receiver, and complete ignored-result audits reject the prior decompiler-return model: two callers for UID000417, 31 for UID000437, and 18 for UID000438.
- All three consumers prove that descriptor `sequenceFrames` points to an array of inline `0x10`-byte `NewHumanSequenceFrameTable` slots. `sequenceFrames[motionIndex]` is an object/reference; only slot `.frames` at `+0x0c` is nullable. The selected frame rows are packed at a 9-byte stride.
- UID000417 and UID000438 project through `g_pEPFLib->LoadFrameDrawRecord(...)`. UID000438 then calls `FrameDrawRecord::sourceRect.Offset(xOffset, yOffset)` and deliberately has no descriptor-count-zero guard. UID000437 retains its own zero-count guard, copies or clears `RectBounds`, and calls `RectBounds::Offset`.
- The aggregate formal's former omission of `[[CHILDREN]]` was a generated-route defect: coded exact children did not reach `NewHumanImageLib.cpp`. The restored marker is the narrow repair; it does not invent a standalone class declaration or move file-routed compiler support into the class.
- Historical first drafts using `int __stdcall`, synthetic return values, nullable slot pointers, free projection calls, and synthetic rectangle helpers are retained in their child pages as superseded reasoning. Current source uses ordinary human-authored member forms while preserving exact binary behavior.
- Class metadata is `88/90`. Exact original private method/field spellings and the final aggregate header declaration remain inference caps, but they no longer block child emission or first-draft method source.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md)
- [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
- [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md)
- [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md)
- [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md)
- [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md)
- [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md)
- [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md)
- [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md)
- [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md)
- [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md)
- [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md)
- [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md)
- [UID:0004DN][0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector](by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md)
- [UID:000436][0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant](by-memory/0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant.md)
- [UID:000437][0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect](by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md)
- [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md)
- [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md)
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-08-16 B001 ResourceLayoutTable whole-file implementation: class score unchanged. Synchronized UID0002V8's current `91/92` compile-closed formal route, three owner includes, exact `ResourceLayoutNameRecord` GFACE access, two `ridingEpfPackage` operands, narrow Riding friendship dependency, and no-duplicate generated expectations while preserving the complete existing class declaration and all unrelated source evidence.

### 2026-08-16 UID0003F8 Complete Class Header And Group Consumer Closure

- The formal H channel now emits one complete `NewHumanImageLib` declaration at position 20 in `NexusTK/render/NewHumanImageLib.h`. It follows [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) position 5 and [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) position 10, and precedes the [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) extern at position 30.
- The declaration includes every currently emitted class child needed by constructor/destructor/table-loader and composition source, plus the full binary-observed public `CalculateBounds` and `Draw` contracts. `NewGroupPane::OnPaint` is a direct consumer of the nine-argument bounds call and thirteen-argument draw call; shortened overloads are rejected.
- The exact `0x60` object storage is represented with complete `std::vector<NewHumanPartEntry>`, `std::vector<NewHumanLayerEntry>`, `std::vector<NewHumanMotionEntry>`, `std::vector<NewHumanCompositionDrawCommand>`, `std::deque<NewHumanCommandSideRecord *>`, `std::vector<Acc2DrwEntry>`, and `std::vector<unsigned long>` members. UID0001VF supplies all by-value row definitions before this class.
- Only `GrafPort`, `Motion`, `NewHumanCompositionState`, and `NewHumanCommandSideRecord` remain forward-declared. Every class-declaration-time use is pointer, reference, or deque-of-pointer and is legal under C++03. No by-value vector element remains incomplete.
- Formal CPP remains exactly `#include "ImageFrameTable.h"` plus `[[CHILDREN]]`; the class is not duplicated in CPP. Formal H begins with its explicit `[[CHILDREN]]` insertion point so UID0001VF's complete position-10 row block precedes the class body rather than being fallback-inserted inside it. Existing exact method children continue to emit through UID0000LR, and UID0000RT remains the sole CPP singleton definition.
- The older deferred-class comment and blank H were compile-incomplete historical state. Raw helper wrappers, retained non-emitting variants, compiler vector helpers, and unproven additional private methods are not fabricated as ordinary declarations.
- Metadata advances from `88/90` to `90/91`. Exact layout, lifecycle, current emitted method contracts, complete C++03 dependency order, singleton route, and Group consumer are closed; inferred private names and retained/non-emitting method-family spellings cap confidence.

- 2026-07-22 B004 UID000438 accepted implementation callback:
  - Raised `86/88 -> 88/90`; owner/emitter remain [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
  - Added the required `[[CHILDREN]]` marker to the accepted `ImageFrameTable.h` aggregate formal so exact class-owned method pages reach generated source.
  - Updated UID000417/UID000437/UID000438 inventory entries with their void member contracts, inline-slot/null-member semantics, accepted `FrameDrawRecord`/`RectBounds` calls, caller counts, and current `91/93`, `92/94`, and `92/94` scores.
  - Preserved the deferred aggregate declaration and all unrelated class, lifecycle, resource, layout, and compiler-support evidence.

- 2026-07-14 B004 UID0004DQ typed composition-command vector sync:
  - Preserved class metadata `86/88`, UID0000LR owner/emitter, and the existing `ImageFrameTable.h` aggregate formal block.
  - Replaced generic `+0x28` auxiliary terminology with inferred `m_compositionDrawCommands`, whose exact begin/end/capacity triplet stores shallow 80-byte `NewHumanCompositionDrawCommand` rows.
  - Recorded the exact row layout: `int partId` at `+0x00`, 40-byte `FrameDrawRecord` at `+0x04`, 32-byte `SurfaceSpriteBlitOptions` at `+0x2c`, and `DLPalette *palette` at `+0x4c`. Offsets/types are direct or strongly corroborated; source spellings remain inferred confidence caps.
  - Recorded BuildComposition construction, the preserved part/tag `0x3d` duplicate append, RenderPreparedComposition consumption, Draw reorder/remove/render/end-reset lifetime, and shallow destructor cleanup.
  - Resolved UID0004DQ and UID0004PA as NewHuman-file-routed compiler-only `push_back`/grow support. Direct VectorHelpers, class-method, aggregate, IME, standalone-body, and non-reconstructable alternatives are rejected; UID0004DN's separate `+0x34` pointer-ring support is unchanged.

- 2026-07-13 B002 UID0004DO source-quality synchronization:
  - Installed the exact `ImageFrameTable.h` class-route formal block, preserving the aggregate declaration deferral comment and unchanged class metadata.
  - Added the typed `RenderComposition` FrameDrawRecord append inventory and distinguished UID00017U/UID0004DO file-routed compiler support from ordinary class methods.
  - Historicalized `NewHumanDrawRecord` and direct RecordVector/VectorHelpers ownership while preserving all unrelated class, layout, lifecycle, resource, and helper evidence.

- 2026-07-06 B004 NewHuman command-side vector support sync:
  - Score unchanged for this class overview.
  - Added/refined UID0004DN support evidence so `BuildPartDrawCommand` records its file-routed command-side pointer-ring/vector helper while preserving that UID0004DN is not a normal class method body.
  - Evidence: current MCP session `supervisor_recovery_20260705` confirms UID0004DN exact range/size/padding, unique signature, one `BuildPartDrawCommand` caller at `0x004e2f7a`, `this + 13` / byte-offset `+0x34` receiver proof, 4-byte pointer-slot grow/rebalance behavior, caller-side 9-byte side-record allocation/copy, no VA/RVA pointer hits, no local source names/types, and rejected direct VectorHelpers/class-method/no-owner/standalone-body alternatives.
- 2026-07-06 B015 DestroyMotionVector implementation sync:
  - Updated UID000185 helper row/evidence to current file-local marker support at `88/91`, not a class method. Source behavior is the destructor's per-row `NewHumanMotionEntry` payload cleanup followed by `m_motionEntries` vector member cleanup.
  - Evidence: current MCP session `supervisor_recovery_20260705` confirms exact range, destructor call, constructor cleanup-table reference, cleanup-only callees, raw-base guard, triplet reset, unique signature, and no source symbol/type/listing proof for the helper/type aliases.
- 2026-07-04 B005 VectorGrowMotion implementation sync:
  - Score unchanged for this class overview.
  - Changed [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) from older source-adjacent shorthand to file-local NewHumanImageLib marker support at `87/90`, with `EMITTER_UIDS:0000LR` and a formal source-disposition marker on the exact child page.
  - Evidence: current MCP session `60724697` confirms raw `sub_4E5240`, size `0x1d5`, 176 instructions, exact body/padding, sole callsite `0x004e0ff2`, receiver setup as the motion-vector header / object offset `+0x1c`, 66-byte `NewHumanMotionEntry` grow/insert mechanics, allocation/memmove/free behavior, loader source route `m_motionEntries.push_back(motion)`, no source names/types, no pointer/immediate matches, and rejected class-method/direct-VectorHelpers/runtime-Motion/no-owner/standalone-body alternatives.
- 2026-07-01 B007 VectorGrowPart implementation sync:
  - Score unchanged for this class overview.
  - Changed [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) from stale below-gate/no-owner wording to file-local NewHumanImageLib part-entry vector-growth support at `87/90`, with `EMITTER_UIDS:0000LR` and a formal marker on the exact child page.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms raw `sub_4E5420`, size `0x1d6` / 470 bytes, exact body/padding, two callsites `0x004e0148` and `0x004e1356`, receiver setup as the part-vector header / object offset `+4`, 68-byte `NewHumanPartEntry` grow/insert mechanics, allocation/memmove/free behavior, and rejected class-method/direct-VectorHelpers/no-owner/standalone-body alternatives. Constructor and UID00041B source continue to represent this as `m_partEntries.push_back(part)`.
- 2026-07-01 B011 empty-emitter implementation: filled the aggregate formal block with a no-standalone-source comment so exact child pages remain the only method/data emitters.
- 2026-06-30 B011 VectorGrowLayer implementation sync:
  - Score unchanged.
  - Changed [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md) from stale B011 below-gate/no-owner wording to file-local NewHumanImageLib layer-entry vector-growth support at `87/89`, with `EMITTER_UIDS:0000LR` and a formal marker on the exact child page.
  - Evidence: B011's current MCP pass confirms raw `sub_4E50A0`, size `0x19e` (`414`, Verified with int_convert.py), no function at `0x004e523e`, successor `sub_4E5240`, two callsites `0x004dffb2` and `0x004e1171`, receiver setup as the layer vector header / `this+0x10`, `0x20` (`32`, Verified with int_convert.py) byte `NewHumanLayerEntry` grow/insert mechanics, allocation/relocation/free behavior, and rejected class-method/direct-VectorHelpers/no-owner/standalone-body/TimerMgr alternatives. Constructor and UID00041A source continue to represent this as `m_layerEntries.push_back(layer)`.
- 2026-06-30 B008 LoadPartSpriteDescriptors implementation sync:
  - Score unchanged.
  - Changed [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md) from stale B011 below-gate/no-owner wording to a class-owned/emitting first-draft child at `88/90` with formal C++ on the exact child page.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms raw `sub_4E13B0`, size `0x446`, exact body, constructor-only caller `0x004e017c`, `.DSC` suffix byte/xref proof, 23-byte header/count reads, descriptor-count allocation, packed descriptor offsets, motion-count sequence tables, and 9-byte sequence-frame rows. Negative evidence rejects no-owner, constructor-inline ownership, local-cluster ownership, resource-page ownership, DAT/StringBase helper ownership, stale `.tbl` wording, and raw decompiler naming.
- 2026-06-30 B009 LoadAcc2DrwTable implementation sync:
  - Score unchanged.
  - Changed [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) from stale B011 below-gate/no-owner wording to a class-owned/emitting first-draft child at `88/90` with formal C++ on the exact child page.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms raw `sub_4E1800`, size `0x1c5`, exact body with no successor merge, constructor-only caller `0x004e0188`, `acc2drw.tbl` literal xref `0x004e0181` / `0x0061c324`, row count from `m_partEntries[7].descriptorCount`, `Acc2DrwEntry.enabled[0..2]` from decimal hundreds/tens/ones flags, `m_acc2drwEntries.clear()` / `push_back()` source shape, fatal path through `DestroyDATFileMgr`, `DestroyExceptionHandler`, `MessageBoxW(L"Error on ACC2DRW table!", L"Error", MB_ICONEXCLAMATION)`, and `__loaddll(0)`, plus B010-coordinated [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) marker support on the full-capacity append path. Negative evidence rejects no-owner, file-only, resource, VectorHelpers, HumanImageLib, successor-merge, and raw standalone vector-grow ownership alternatives.
- 2026-06-30 B007 LoadPartTable implementation sync:
  - Score unchanged.
  - Changed [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) from stale B011 below-gate/no-owner wording to a class-owned/emitting first-draft child at `88/90` with formal C++ on the exact child page.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms raw `sub_4E11B0`, size `0x1f7`, exact body and padding, zero direct callers, `wchar_t *` path argument, 23-byte header/count reads, 32-byte `Part.tbl` file rows into 68-byte `NewHumanPartEntry` memory rows, `ResolveSpritePartPath` callsite `0x004e12fe`, `VectorGrowPart` full-capacity path, and `char.dat` sample rows. Negative evidence keeps the constructor-inline `Part.tbl` loop unchanged and rejects constructor-call, local-cluster, resource, vector-helper, raw decompiler, duplicate-page, and TimerMgr UID-collision alternatives.
- 2026-06-30 B010 VectorGrowAcc2Drw implementation sync:
  - Score unchanged.
  - Changed [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) from stale B011 below-gate/no-owner wording to file-local NewHumanImageLib vector-growth support at `86/90`, with `EMITTER_UIDS:0000LR` and a formal marker on the exact child page.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms raw `sub_4E4F10`, size `0x18d`, body `0x004e4f10-0x004e509d`, padding `0x004e509d-0x004e50a0`, sole caller `0x004e195a` in UID00041D, receiver `this + 18` / object offset `+0x48`, 3-byte `Acc2DrwEntry` vector grow/insert mechanics, and runtime/vector-only callees. Negative evidence rejects class-method ownership, direct generic VectorHelpers ownership, runtime-only classification, and standalone helper-body C++; B009's UID00041D implementation now supplies the calling loader body and keeps UID00041E as marker-only full-capacity support.
- 2026-06-30 B006 LoadLayerTable implementation sync:
  - Score unchanged.
  - Changed [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) from stale B011 below-gate/no-owner wording to a class-owned/emitting first-draft child at `88/90` with formal C++ on the exact child page.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms raw `sub_4E1040`, size `0x170`, zero direct callers, `wchar_t *` path argument, 23-byte header/count reads, 32-byte row fields, optional child-index allocation/read loop, direct append plus `VectorGrowLayer` full-capacity call, and boundary nuance `0x004e1040-0x004e11b0` exclusive for the current `0x004e1040-0x004e11af` path. Negative evidence keeps the constructor-inline `Layer.tbl` loop unchanged and rejects constructor-call, local-cluster, resource, vector-helper, raw decompiler, duplicate-page, and TimerMgr UID-collision alternatives.
- 2026-06-30 B004 LoadPartFrameDrawRecord implementation sync:
  - Score unchanged.
  - The 2026-06-30 support change marked [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) as a class-owned/emitting first-draft child at the then-current `88/90` with `EMITTER_UIDS:000092`, while preserving this class page's blank declaration-container C++ policy. The later source-quality pass preserves that promotion and records the current `91/93` method state.
  - Historical evidence: evidence-time MCP session `supervisor_resume_20260629` confirmed raw `sub_4E0D70` at `0x004e0d70-0x004e0dcf`, one-byte successor padding, three basic blocks, two UI paint callers, and callee `sub_4D1600`; accepted support docs then used `m_partEntries`, `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, historical `NewHumanDrawRecord`, and `LoadFrameDrawRecord`. The 2026-07-13 callback superseded that one alias with accepted `FrameDrawRecord`. Constructor folding, caller ownership, and raw `sub_4E0D70` source naming remain rejected. The old blanket rejection of callee/ImageFrameTable/ResourceLayout ownership and `dword_67A744` receiver ownership is superseded for UID0002P6: UID000417 remains NewHumanImageLib-owned, while its callee now routes as `ResourceLayoutTable::LoadFrameDrawRecord` through the `g_pEPFLib` ImageLib facet.
- 2026-06-26 B010 destructor implementation sync:
  - Score unchanged.
  - Changed support text to mark [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) as a class-owned/emitting ordinary destructor at `90/91` with formal first-draft C++.
  - Evidence: B010 MCP session `80de0a67` rechecked the destructor body, scalar-wrapper caller, vtable/global refs, helper body roles, helper xrefs, cleanup order, and boundary bytes; the current constructor/layout/composition docs supply implementation-ready source-facing names while exact original spellings remain inferred.
- 2026-06-26 B014 composition-bounds implementation sync:
  - Changed support text without changing class score.
  - Evidence: [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) is now class-owned/emitting at `89/90` with formal first-draft C++; new helper pages [UID:000437][0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect](by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md) and [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md) emit through this class; retained variant [UID:000436][0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant](by-memory/0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant.md) is class-owned/reconstructable but intentionally non-emitting after negative route checks.
- 2026-06-25 B011 constructor implementation sync:
  - Changed support text without changing the class score.
  - Evidence: [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) is now `91/92` with formal first-draft constructor C++; helper pages [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) through [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) were created at `84/86` with no owner/emitter metadata; `LoadLayerTable` and `LoadPartTable` replace old placeholder helper wording because current xrefs show no constructor calls to `0x004e1040` or `0x004e11b0`. UID000417's below-gate state is superseded by the 2026-06-30 B004 class-owned/emitting implementation, UID000419's below-gate state is superseded by the 2026-06-30 B002 class-owned/emitting loader implementation, UID00041A's below-gate state is superseded by the 2026-06-30 B006 class-owned/emitting loader implementation, UID00041B's below-gate state is superseded by the 2026-06-30 B007 class-owned/emitting loader implementation, UID00041D's below-gate state is superseded by the 2026-06-30 B009 class-owned/emitting loader implementation, UID00041E's below-gate state is superseded by the 2026-06-30 B010 file-local marker implementation, UID00041F's below-gate state is superseded by the 2026-06-30 B011 file-local marker implementation, and UID00041G's below-gate state is superseded by the 2026-07-01 B007 file-local marker implementation.
- 2026-06-21 B008 ObjectImageControlPane support sync:
  - Score unchanged.
  - Evidence: recorded [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) as a concrete UI preview consumer of `CalculateBounds` / `Draw` at `0x004e09e0` / `0x004e06a0`, using status kind `0` as human/avatar appearance through [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md).
- 2026-06-16 A002 Goal2 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; owner and emitter remain [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
  - Evidence: live IDA MCP reconfirmed main method/helper sizes, startup constructor caller, singleton/vtable refs, cleanup-table helper ref, 52 singleton consumers/lifecycle refs, `VectorGrowMotion` and `DestroyMotionVector` caller sets, constructor/render/bounds callees, and exact scalar-deleting destructor page availability. The class-level formal block is now comment-only because table/vector field names, helper declarations, and source-level disabled-helper names are not source-final.
- 2026-06-17 B002 scalar-wrapper support update:
  - Changed support text without changing this class score.
  - Evidence: [UID:0002VN][0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor](by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md) is now `86/91`; B002 reconfirmed it as vtable-only compiler-generated scalar deleting destructor glue, resolved the source declaration to `virtual ~NewHumanImageLib()`, validated the `(flags & 1) && !(flags & 4)` delete route, rejected generated simroot wrapper code, and kept formal wrapper C++ blank.
- 2026-06-13 A003 constructor gate note:
  - Changed to: added explicit parent-gate rationale for [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) without changing the class score.
  - Evidence: the constructor page now records live IDA MCP evidence for the exact constructor boundary, singleton/vtable stores, resource load flow, row-size constants, UTF-16 table-name bytes, and constructor unwind cleanup handlers. This class was already the direct owner at `85/85`; the class-level formal block is now comment-only because field/type/helper declarations are not source-final.
- 2026-06-08 A001 Batch 121 static-helper refresh:
  - Before: completion/confidence were `82/82`, and the singleton-clear helper row linked the child but did not record the constructor cleanup-table evidence needed for the corrected parent gate.
  - Changed to: completion `85`, confidence `85`, with the helper described as file-local static cleanup tied to the `NewHumanImageLib` constructor/lifetime rather than as a class method.
  - Summary/evidence: live IDA MCP reconfirmed [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md), its `dword_67A760 = 0` body, the single cleanup-table xref at `0x00600230`, and 52 singleton global xrefs. The class-level formal block is now comment-only because field/type/helper declarations are not source-final.
- Before: completion/confidence metadata were `0/0` despite substantial singleton, layout, method-family, and resource-table documentation.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: the page records constructor/destructor ownership, render/bounds/load families, singleton and vtable references, vector helpers, and observed field offsets; confidence remains medium because final field/type names and exact layout semantics still need a dedicated pass.
- Before: the class page did not mark the confirmed source-owned class as reconstructable and referenced the constructor only by start address.
- Changed to: `RECONSTRUCTABLE:TRUE`, `COMPLETION:82`, `CONFIDENCE:82`, and the exact constructor page/range link.
- Evidence: IDA MCP `lookup_funcs 0x004dfd10` reports `0x004dfd10-0x004e024a`, with constructor resource loads and object-layout writes documented in [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md). Scores remain below 95 because final field/type names and full method-by-method reconstruction are still incomplete.
- Before: owner/emitter routing was blank even though both the class page and file page had 80+ confidence and agreed on ownership.
- Changed to: owner/emitter routing through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Evidence: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) owns `NexusTK/render/NewHumanImageLib.cpp`, and this class page records the matching singleton, vtable, layout, method family, and resource-table evidence. The reconstruction C++ block is now comment-only because final field names and member declarations remain below final-source quality.
- Before: `CalculateCompositionBounds` was listed only by address.
- Changed to: the method-family table links [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md).
- Evidence: IDA MCP on 2026-06-03 confirmed the method boundary, callers, callees, and two overlay-resource rectangle calls to [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md).
- Before: status still carried an obsolete source-path provenance line, the aggregate link used the one-byte-short `0x004e68a7` end, and destructor/static-helper rows were address-only.
- Changed to: removed the obsolete provenance line, updated the aggregate link and scalar-wrapper range to `0x004e68a8`, linked destructor/static-helper rows to their by-memory pages, and recorded the scalar-deleting wrapper as pending a standalone page.
- Evidence: IDA MCP on 2026-06-06 confirmed `sub_4E6870` spans `0x004e6870-0x004e68a8`, has ordinary-destructor/delete/guard-check callees, has no direct callers, and is followed by eight `0xcc` bytes.
