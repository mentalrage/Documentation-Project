*** UID:0001VF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000092 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000092 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// NewHumanImageLib layout/type facts support the class and method emitters; no standalone source body is emitted from this layout page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ImageFrameTable.h"
#include "Surface.h"

#pragma pack(push, 1)
struct NewHumanSequenceFrame
{
    int recordIndex;
    unsigned char flags;
    int value;
};
#pragma pack(pop)

struct NewHumanSequenceFrameTable
{
    int motionIndex;
    int frameBase;
    int frameCount;
    NewHumanSequenceFrame *frames;
};

#pragma pack(push, 1)
struct NewHumanPartFrameDescriptor
{
    int descriptorId;
    int frameBase;
    int drawIndexBase;
    int rawRecordCount;
    unsigned char primaryFrameCount;
    unsigned short *primaryFrameData;
    unsigned char secondaryFrameCount;
    unsigned short *secondaryFrameData;
    unsigned short sequenceCount;
    NewHumanSequenceFrameTable *sequenceFrames;
};
#pragma pack(pop)

struct NewHumanPartEntry
{
    int partId;
    wchar_t name[20];
    int drawIndexBase;
    int descriptorBase;
    int descriptorCount;
    int rawRecordCount;
    NewHumanPartFrameDescriptor *frameDescriptors;
    ArchiveMetadataTable *spriteArchive;
};

struct NewHumanLayerEntry
{
    int layerId;
    char name[20];
    int childCount;
    int *childIndexes;
};

#pragma pack(push, 1)
struct NewHumanMotionEntry
{
    unsigned char reservedPrefix[0x17];
    int motionId;
    char name[20];
    unsigned char reservedAfterName[2];
    unsigned char direction;
    int fallbackMotionId;
    int frameCount;
    unsigned short *frameOffsets;
    unsigned char *frameData;
};
#pragma pack(pop)

struct NewHumanCompositionDrawCommand
{
    int partId;
    FrameDrawRecord frame;
    SurfaceSpriteBlitOptions options;
    DLPalette *palette;
};

struct Acc2DrwEntry
{
    bool enabled[3];
};

typedef char NewHumanSequenceFrameSizeMustBe9[
    (sizeof(NewHumanSequenceFrame) == 0x09) ? 1 : -1];
typedef char NewHumanSequenceFrameTableSizeMustBe16[
    (sizeof(NewHumanSequenceFrameTable) == 0x10) ? 1 : -1];
typedef char NewHumanPartFrameDescriptorSizeMustBe32[
    (sizeof(NewHumanPartFrameDescriptor) == 0x20) ? 1 : -1];
typedef char NewHumanPartEntrySizeMustBe68[
    (sizeof(NewHumanPartEntry) == 0x44) ? 1 : -1];
typedef char NewHumanLayerEntrySizeMustBe32[
    (sizeof(NewHumanLayerEntry) == 0x20) ? 1 : -1];
typedef char NewHumanMotionEntrySizeMustBe66[
    (sizeof(NewHumanMotionEntry) == 0x42) ? 1 : -1];
typedef char NewHumanCompositionDrawCommandSizeMustBe80[
    (sizeof(NewHumanCompositionDrawCommand) == 0x50) ? 1 : -1];
typedef char Acc2DrwEntrySizeMustBe3[
    (sizeof(Acc2DrwEntry) == 0x03) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewHumanImageLib Layout

## ObjectStatusBlob and HAIRCOL integration

- ObjectStatusBlob byte `+34` decimal (`+0x22`) is composition/render mode. Riding fields at decimal `+44/+46/+48` (`+0x2c/+0x2e/+0x30`) are definition index, packed palette/render flags, and signed Y offset from `RidableAnimals` columns 1-3. Colors at decimal `+50..+62` (`+0x32..+0x3e`) cover face, hair, shared skin/tint, body, weapon, shield/arrow, helmet, decorations, mantle, neck, and shoes; decimal `+52` (`+0x34`) is the shared skin/tint.
- ObjectStatusBlob `+4` is a context union for appearance id/full face id/HeadSelect head index, not universally Body. Body is `+8`. Address `0x0067a760` is the `g_pNewHumanImageLib` pointer, not a generic remap table; the pointed object's `HAIRCOL.TBL` vector at NewHumanImageLib `+0x54/+0x58` performs the low-five-bit hair-color remap.
- Composition copies the exact 68-byte ObjectStatusBlob and consumes Part selectors/colors, context mode, and riding words; this does not embed ObjectStatusBlob into NewHumanImageLib layout or transfer parser ownership.
- The `+0x54/+0x58` vector role is specifically HAIRCOL remap data indexed by full-parser hair id. Any historical generic appearance-remap or title-field interpretation is superseded. Existing struct offsets, score, formal block, and all other vector/resource roles remain unchanged.


## Status

- Confidence: strong for observed offsets, constructor/destructor agreement, and first-draft constructor/destructor use of accepted member names; medium for exact original field names and exact original nested row type names.
- Owner class: [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md).
- Owner/emitter route: attached to [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md), which now clears the strict `85/85` route gate and emits through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Evidence: IDA constructor/destructor decompilation on 2026-05-26, constructor/function-boundary recheck on 2026-05-31, and live IDA MCP layout refresh on 2026-06-14.

## Layout

```text
NewHumanImageLib
  +0x00  LObject/vtable
  +0x04  NewHumanPartEntry* partEntriesBegin
  +0x08  NewHumanPartEntry* partEntriesEnd
  +0x0c  NewHumanPartEntry* partEntriesCapacity
  +0x10  NewHumanLayerEntry* layerEntriesBegin
  +0x14  NewHumanLayerEntry* layerEntriesEnd
  +0x18  NewHumanLayerEntry* layerEntriesCapacity
  +0x1c  NewHumanMotionEntry* motionEntriesBegin
  +0x20  NewHumanMotionEntry* motionEntriesEnd
  +0x24  NewHumanMotionEntry* motionEntriesCapacity
  +0x28  NewHumanCompositionDrawCommand* compositionDrawCommandsBegin
  +0x2c  NewHumanCompositionDrawCommand* compositionDrawCommandsEnd
  +0x30  NewHumanCompositionDrawCommand* compositionDrawCommandsCapacity
  +0x34  list/sentinel state begin
  +0x38  list/sentinel state
  +0x3c  list/sentinel state
  +0x40  list/sentinel state
  +0x44  list/sentinel state end
  +0x48  Acc2DrwEntry* acc2drwEntriesBegin
  +0x4c  Acc2DrwEntry* acc2drwEntriesEnd
  +0x50  Acc2DrwEntry* acc2drwEntriesCapacity
  +0x54  int* hairColorEntriesBegin
  +0x58  int* hairColorEntriesEnd
  +0x5c  int* hairColorEntriesCapacity
```

## Notes

- The exact constructor page is [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md). It writes [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md), constructs the `LObject` base, stores the [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md), zeros all vector triplets, allocates an 8-byte sentinel/list node for the `+0x34` state, then loads `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptors, `acc2drw.tbl`, and `HAIRCOL.TBL`.
- `Part.tbl` file rows are 0x20-byte / 32-byte records, while `NewHumanPartEntry` rows are 0x44-byte / 68-byte records in the `+0x04` vector. The constructor and [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) convert the 20-byte ANSI part name to wide characters and store the resolved part EPF path at row offset `+0x40`.
- `Layer.tbl` rows are 0x20-byte records in the `+0x10` vector. Rows can own a child-index array at row offset `+0x1c`.
- `Motion.tbl` produces 0x42-byte in-memory `NewHumanMotionEntry` rows in the `+0x1c` vector; the file payload is a 33-byte fixed prefix plus count-driven frame payloads, not a fixed 0x42-byte file row. [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) frees each row's dynamic `frameOffsets`/`frameData` payloads, then [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) frees the `m_motionEntries` vector storage and resets the triplet.
- `acc2drw.tbl` entries live in the `+0x48` vector, and `HAIRCOL.TBL` integer palette indices live in the `+0x54` vector.
- [UID:0004DN][0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector](by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md) adds command-builder evidence for the `+0x34..+0x44` region without renaming the whole state. Current MCP session `supervisor_recovery_20260705` shows `BuildPartDrawCommand` calls UID0004DN at `0x004e2f7a` with `this + 13` and `1`; `this + 13` is byte offset `+0x34`, and the helper grows/rebalances 4-byte pointer slots while the caller masks the ring index, lazily allocates 9-byte side records, copies 8 bytes plus 1 byte into the selected record, and increments the command-side count. This supports treating the region as command-side pointer-ring/vector state in the build-command path, while destructor/list evidence still keeps exact field names and the broader state role as confidence caps.
- Current generated source emits several shared render globals in `class_NewHumanImageLib.cpp`; that does not make them fields of this object. This layout should be used for object reconstruction.

## 2026-07-14 Composition Draw Command Vector Layout

- The `+0x28/+0x2c/+0x30` triplet is the per-draw `std::vector<NewHumanCompositionDrawCommand>` member, inferred source name `m_compositionDrawCommands`. Constructor initialization, BuildComposition receiver setup, exact append/grow arithmetic, RenderPreparedComposition traversal, Draw reorder/remove/reset behavior, and destructor cleanup all address this same triplet.
- [UID:0004DQ][0x004e70a0-0x004e70e9.NewHumanCompositionDrawCommandPushBackCompilerSupport](by-memory/0x004e70a0-0x004e70e9.NewHumanCompositionDrawCommandPushBackCompilerSupport.md) performs the one-caller in-capacity append and delegates full-capacity insertion to [UID:0004PA][0x004e5600-0x004e57bb.NewHumanCompositionDrawCommandVectorGrowInsertCompilerSupport](by-memory/0x004e5600-0x004e57bb.NewHumanCompositionDrawCommandVectorGrowInsertCompilerSupport.md). Both are file-routed compiler markers regenerated by `m_compositionDrawCommands.push_back(drawCommand)`, not class methods or handwritten STL bodies.
- The exact source-facing row layout is:

| Offset | Size | Inferred source field | Direct/corroborating evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | `int partId` | BuildPart initialization and Draw comparisons/reordering across part categories. |
| `+0x04` | 40 | `FrameDrawRecord frame` | `0x00457a60` initialization, BuildPart fill, and RenderPreparedComposition frame/rectangle use. |
| `+0x2c` | 32 | `SurfaceSpriteBlitOptions options` | Exact Surface callback options region, including selector and alpha fields. |
| `+0x4c` | 4 | `DLPalette *palette` | `0x00543e40` producer and Surface sprite callback argument. |

- Five OWORD lanes, end advancement, grow-helper division/allocation, Draw moves, and renderer count all prove an exact `0x50` / 80-byte stride. Cleanup at `0x004557f0` invokes no element destructors, so the row is shallow/trivially destructible.
- `BuildCompositionDrawCommands` constructs the row and preserves the observed part/tag `0x3d` target append followed by the common append. `RenderPreparedComposition` consumes the exact frame/options/palette layout. Draw swaps/removes full rows, renders, and resets end to begin while retaining capacity.
- UID0004DN's pointer-ring/vector receiver is object byte offset `+0x34`; it remains separate from this typed `+0x28` vector.
- `NewHumanCompositionDrawCommand`, `m_compositionDrawCommands`, and field spellings are implementation-ready source inference, not original-symbol proof. Exact offsets, widths, behavior, and compiler-only disposition are proven. Historical `NewHumanDrawRecord` and generic auxiliary terminology are superseded.
- Historically this evidence left metadata at `85/88` with a comment-only formal block. The 2026-08-16 dependency-complete closure supersedes that state with `92/93` and exact formal H declarations; broader original nested-row/member spellings remain the confidence cap.

## 2026-06-25 Inferred Constructor And Row Names

The constructor first-draft C++ in [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) uses source-facing inferred names for the already observed object fields. `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_compositionDrawCommands`, `m_loadedPartList`, `m_acc2drwEntries`, and `m_hairColorEntries` correspond respectively to the layout triplets/list state at `+0x04`, `+0x10`, `+0x1c`, `+0x28`, `+0x34`, `+0x48`, and `+0x54`. These names are implementation-ready inference for first-draft source, not proof of original member spelling.

`NewHumanLayerEntry` is the accepted inferred name for the 32-byte `Layer.tbl` row. The constructor and [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) evidence support fields named `layerId`, `name`, `childCount`, and `childIndexes`, with `childIndexes` at row offset `+0x1c`. Rows with a nonzero child count allocate an index array before appending the row to the layer vector.

Accepted source-facing declaration for current implementation work:

```cpp
struct NewHumanLayerEntry
{
    int layerId;
    char name[20];
    int childCount;
    int *childIndexes;
};
```

These names are source-ready inference for constructor/destructor/layer-loader reconstruction, not proof of original source spelling.

`NewHumanPartEntry` is the accepted inferred name for the 68-byte in-memory `Part.tbl` row stored in `m_partEntries`. The constructor and [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) evidence support a 32-byte file row made of a 4-byte id, 20-byte ANSI source part name, and two 4-byte scalar fields currently named `drawIndexBase` and `descriptorBase`. The loader converts the ANSI part name to a wide `name`, populates `spriteArchive`/metadata through [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md), and appends the 68-byte memory row through the part vector. `descriptorCount` is populated by later descriptor-loading support and consumed by the constructor's `HAIRCOL.TBL` loop for the hair part's line count; the source-facing constant `kNewHumanHairPartIndex` is inferred from the fixed constructor index, not yet proven as original spelling.

The exact original names and semantics for `drawIndexBase` and `descriptorBase` remain inferred score caps. Direct `char.dat` sampling for [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) confirms `PartInformation`, count `19`, 608 bytes of row payload, and sampled scalar pairs such as `Body 0 19999`, `Coat 20000 39999`, `Face 200 999`, `Emotion 1 1`, and `FaceDec 0 9999`, but those values do not prove final field spellings.

`NewHumanPartFrameDescriptor` is the accepted inferred name for the packed 0x20-byte descriptor rows loaded by [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md). B008's current MCP pass confirms that the loader reads per-part `<part-name>.DSC` files, allocates one row per descriptor count, and fills these offsets:

| Offset | Field | Evidence |
| ---: | --- | --- |
| `+0x00` | `descriptorId` | First dword read from the descriptor stream; source-facing name remains inferred. |
| `+0x04` | `frameBase` | Second dword read from the descriptor stream; source-facing name remains inferred. |
| `+0x08` | `drawIndexBase` | Dword consumed by part-frame draw record and composition helpers as the descriptor draw-index base. |
| `+0x0c` | `rawRecordCount` | Dword accumulated into the parent part's raw-record total. |
| `+0x10` | `primaryFrameCount` | Count byte controlling optional primary unsigned-short frame-data allocation. |
| `+0x11` | `primaryFrameData` | Packed pointer field storing the primary 2-byte frame data. |
| `+0x15` | `secondaryFrameCount` | Count byte controlling optional secondary unsigned-short frame-data allocation. |
| `+0x16` | `secondaryFrameData` | Packed pointer field storing the secondary 2-byte frame data. |
| `+0x1a` | `sequenceCount` | Word storing the motion-count-sized sequence slot count. |
| `+0x1c` | `sequenceFrames` | Pointer to the motion-indexed `NewHumanSequenceFrameTable` array. |

`NewHumanSequenceFrameTable` is the accepted inferred name for the 0x10-byte per-motion sequence slot array allocated by UID00041C for each descriptor. `NewHumanPartFrameDescriptor::sequenceFrames` points to the first element of that inline slot array; `sequenceFrames[motionIndex]` is a slot object/reference, not a nullable slot pointer. The loader initializes every slot to `motionIndex = -1`, `frameBase = -1`, `frameCount = 0`, and `frames = NULL`, then fills populated slots selected by file-provided motion index. Only the slot's `frames` member at `+0x0c` is nullable. Each populated slot owns a `NewHumanSequenceFrame` array whose compact file row is 9 bytes: 4-byte `recordIndex`, 1-byte `flags`, and 4-byte `value`. UID000417, UID000437, and UID000438 independently confirm the `0x10 * motionIndex` slot stride, `.frames` null test, and packed `0x09` frame-row stride. Older boolean-style descriptor wording and pointer-to-selected-slot interpretations are superseded by these count-bearing inline-slot semantics, but the names remain source-facing reconstruction labels rather than original-symbol proof.

`NewHumanMotionEntry` remains the accepted inferred row type for the 66-byte `Motion.tbl` in-memory rows appended through [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) and grown by [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md). B002's 2026-06-30 source-quality pass promotes UID000419 to class-owned/emitting C++ and refines the layout: the file payload has a 33-byte fixed prefix plus count-driven frame payloads, while the object vector stores a 0x42-byte entry. Current implementation-ready field names are `motionId`, 20-byte `name`, one-byte `direction`, `fallbackMotionId`, `frameCount`, `frameOffsets`, and `frameData`. B015's UID000185 source-quality sync keeps `DestroyMotionVector` as a historical/search alias for lowered `m_motionEntries` vector-storage cleanup; it does not introduce a separate `MotionEntryVector` type or standalone helper body.

```text
NewHumanMotionEntry (0x42 bytes)
  +0x00..+0x16  reserved/zero-initialized prefix not read from the file loader
  +0x17         int motionId
  +0x1b         char name[20]
  +0x31         unsigned char direction
  +0x32         int fallbackMotionId
  +0x36         int frameCount
  +0x3a         unsigned short* frameOffsets
  +0x3e         unsigned char* frameData
  +0x42         end
```

The names are source-facing inference, not proof of original spelling. The `direction` inference is supported by direct `Motion.tbl` rows such as `NormalWalkNorth/East/South/West` with direction bytes `0..3`. `fallbackMotionId` is descriptive: direct `char.dat` sampling found `-1` for normal rows and `0` for the final `Test` row. [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) already uses `frameOffsets`, `frameData`, and `frameCount` in formal destructor C++, matching the loader's dynamic fields. Current UID000185 MCP session `supervisor_recovery_20260705` confirms the destructor call `0x004e0547`, constructor cleanup-table ref `0x0060025a`, raw-base large-allocation guard, `sub_5C7526` checked-free/runtime allocator callee, and final begin/end/capacity reset for the vector storage.

`Acc2DrwEntry` is the accepted inferred row type for the 3-byte accessory-to-draw rows appended by [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) and grown by [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md). B009's UID00041D implementation proves the producer shape: it clears `m_acc2drwEntries`, reads one text row per `m_partEntries[7].descriptorCount`, parses base-10 flags, stores the hundreds/tens/ones digits into `Acc2DrwEntry.enabled[0..2]`, and appends the 3-byte row. Current MCP for UID00041E proves the caller at `0x004e195a` passes `this + 18`, i.e. byte offset `+0x48`, tying the helper receiver directly to the `+0x48/+0x4c/+0x50` `m_acc2drwEntries` vector triplet. The helper body divides vector spans by 3 and copies inserted records as two bytes plus one byte, reinforcing `Acc2DrwEntry` as a compact 3-byte row. The object field `partEntriesBegin + 0x210` is the raw address expression behind `m_partEntries[7].descriptorCount`, because `0x210 = 7 * 0x44 + 0x34`; the fixed hair-part row contributes the `HAIRCOL.TBL` count. Exact final names can be refined later without blocking the constructor, destructor, motion-loader, UID00041D loader, or UID00041E marker-support source shape.

## 2026-06-30 Acc2Drw Vector-Growth Consumer Evidence

B010's accepted [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) implementation does not change this layout page's score, but it adds direct receiver proof for the `m_acc2drwEntries` field. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E4F10`, size `0x18d`, executable body `0x004e4f10-0x004e509d`, padding through `0x004e50a0`, sole caller `0x004e195a` in UID00041D, and the call argument `this + 18`.

Because `this + 18` is dword index 18, the helper receiver is object byte offset `+0x48`, matching `acc2drwEntriesBegin`; the paired end/capacity words remain `+0x4c/+0x50`. The grow/insert body uses 3-byte element arithmetic, small/large allocation, prefix/suffix `_memmove_0`, old-storage free, and begin/end/capacity updates. This supports `m_acc2drwEntries` and `Acc2DrwEntry` as implementation-ready inferred names while preserving the caveat that exact original spelling and the final typed-vector/template policy are unresolved. B009's UID00041D implementation now supplies the producer loader body, while UID00041E remains marker-only vector-growth support.

## 2026-06-30 LoadAcc2DrwTable Producer Evidence

B009's accepted [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) implementation does not change this layout page's score, but it adds direct producer proof for `m_acc2drwEntries` and `Acc2DrwEntry::enabled`. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E1800`, size `0x1c5`, constructor-only caller `0x004e0188`, `acc2drw.tbl` literal xref `0x004e0181` / `0x0061c324`, row count source `m_partEntries[7].descriptorCount`, and the UID00041E full-capacity call at `0x004e195a`.

The loader source shape maps each decimal flag row into exactly three byte-sized booleans: `(flags % 1000) / 100` for `enabled[0]`, `(flags % 100) / 10` for `enabled[1]`, and `flags % 10` for `enabled[2]`. That producer evidence matches composition consumer evidence that gates draw tags through `Acc2DrwEntry::enabled[3]`, and it keeps the field name `enabled` as implementation-ready inference rather than final original-spelling proof.

## 2026-06-30 LoadLayerTable Consumer Evidence

B006's accepted [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) implementation independently re-proves the `NewHumanLayerEntry` shape. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E1040`, zero direct callers, `wchar_t *` path argument, 23-byte header/count reads, 32-byte row zeroing, 4-byte `layerId` read at row offset `+0x00`, 20-byte `name` read at `+0x04`, 4-byte `childCount` read at `+0x18`, `childCount * 4` child-index allocation, 4-byte child-index reads, and append into the layer vector at `m_layerEntries`.

This sync does not make this struct page an emitter. The formal source body lives on [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md), and [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md) remains a capacity-helper dependency. The constructor still inlines its own `Layer.tbl` loop, so the no-xref caveat on UID00041A is preserved.

## 2026-06-30 LoadPartTable Consumer Evidence

B007's accepted [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) implementation independently re-proves the `NewHumanPartEntry` loader shape. Current MCP session `supervisor_resume_20260629` confirms raw `sub_4E11B0`, zero direct callers, `wchar_t *` path argument, 23-byte header/count reads, 68-byte row zeroing, 4-byte `partId` read at memory offset `+0x00`, 20-byte ANSI name read from the file row, two 4-byte scalar reads at file-row offsets `+0x18` and `+0x1c`, `MultiByteToWideChar` conversion into the wide name field, [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) callsite `0x004e12fe`, and append into the part vector at `m_partEntries`.

This sync does not make this struct page an emitter. The formal source body lives on [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md), and [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) now carries the file-local marker for the full-capacity `m_partEntries` vector slow path. The constructor still inlines its own `Part.tbl` loop, so the no-xref caveat on UID00041B is preserved.

## 2026-06-26 Composition Bounds Consumer Evidence

[UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) provides exact consumer evidence for the `Part.tbl` vector and nested descriptor names:

| Evidence | Layout impact |
| --- | --- |
| The target indexes `m_partEntries` as 68-byte rows and selects rows 0-18 from draw tags `0x32..0x3e`. | Reinforces `NewHumanPartEntry` as the source-facing row type for the `+0x04` vector and confirms this vector is consumed beyond construction/destruction. |
| The target gates tags `0x34`, `0x35`, and the first `0x36` pass through `acc2drw.tbl` bytes. | Confirms `Acc2DrwEntry` is a compact 3-byte row consumed as `enabled[3]`; the exact original field name remains inferred. |
| [UID:000437][0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect](by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md) reads a part descriptor, per-sequence frame table, raw record index, and raw ResourceLayout rectangle. | Supports inferred support names `NewHumanPartFrameDescriptor` and `NewHumanSequenceFrameTable` for first-draft helper C++; original spellings remain unproven. |
| [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md) resolves a part-frame draw record through `LoadFrameDrawRecord` and adjusts raw offset `+0x10`. | Supports the accepted shared `FrameDrawRecord` output type and exact `sourceRect` field. Historical undeclared `NewHumanDrawRecord` shorthand is superseded. |
| The target copies a 0x44-byte composition state and uses fixed offsets `+0x04`, `+0x06`, `+0x0a`, `+0x0c`, `+0x0e`, `+0x10`, `+0x12`, `+0x16`, `+0x18`, `+0x1a`, `+0x1c`, `+0x1e`, `+0x22`, `+0x2c`, `+0x30`, and `+0x40`. | Supports inferred source-facing type `NewHumanCompositionState`; exact field names are documented on [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) with offset caveats. |

These names are implementation-ready support names for current formal C++ blocks, not direct proof of original source spelling.

## 2026-07-13 FrameDrawRecord Type Synchronization

- [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) and UID000438 both use the accepted `FrameDrawRecord *` output type supplied by `ImageFrameTable.h`; no distinct `NewHumanDrawRecord` declaration exists.
- UID000438 maps its raw output offset `+0x10` to accepted `FrameDrawRecord::sourceRect`. All part, descriptor, sequence-frame, and object-layout offsets remain unchanged.
- `RenderComposition` initializes and populates one 40-byte FrameDrawRecord local, then appends it to a local vector. The inline fast path and file-routed UID00017U/UID0004DO compiler markers prove shallow 40-byte vector use without adding any field to `NewHumanImageLib` itself.
- `FrameDrawRecord` is ABI-compatible with the shared 40-byte `EPFTileContext` initializer, but distinct `+0x20/+0x24` payload-span/end versus encoded-mask semantics require separate source declarations. This layout page keeps its existing metadata and formal block unchanged.

## 2026-06-26 Destructor Consumer Evidence

[UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) now carries formal first-draft `NewHumanImageLib::~NewHumanImageLib()` C++ using this layout's accepted member names. B010 MCP session `80de0a67` confirms that the destructor's observed cleanup agrees with the constructor/layout model:

| Layout region | Destructor agreement |
| --- | --- |
| `m_partEntries` at `+0x04/+0x08/+0x0c` | Walked as 68-byte `NewHumanPartEntry` rows; releases each row's sprite/archive package, descriptor rows, descriptor primary/secondary frame data, sequence-frame arrays, and descriptor array before `DestroyPartVector`. |
| `m_layerEntries` at `+0x10/+0x14/+0x18` | Walked as 32-byte `NewHumanLayerEntry` rows; frees each row's `childIndexes` array before final layer vector storage cleanup. |
| `m_motionEntries` at `+0x1c/+0x20/+0x24` | Walked as 66-byte `NewHumanMotionEntry` rows; the destructor frees per-motion `frameOffsets`/`frameData`-style dynamic fields, then reaches [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) for lowered vector-storage free and triplet reset. UID000185 is marker-only source support, not a standalone helper body and not the owner of the per-entry payload loop. |
| `m_compositionDrawCommands` at `+0x28/+0x2c/+0x30` | Cleaned by shallow 80-byte command-vector cleanup at `0x004557f0`; the helper itself is shared compiler support, while the call at `0x004e053f` is this typed member's destructor route. |
| `m_loadedPartList` at `+0x34-+0x47` | Cleaned by `DestroyLoadedPartListState` (`0x004e5c30`), which drains child pointers, frees the pointer array, frees sentinel/root storage, and zeroes state. |
| `m_acc2drwEntries` at `+0x48/+0x4c/+0x50` | Cleaned by `DestroyAcc2DrwVector` (`0x004e5d00`), whose body computes a 3-byte element span and clears vector triplet state. |
| `m_hairColorEntries` at `+0x54/+0x58/+0x5c` | Freed through a shared 4-byte vector cleanup shape and represented in first-draft source as `m_hairColorEntries.clear()`. |

The destructor formal block confirms that these names are suitable for current first-draft C++ in both constructor and destructor pages. They remain inferred source-facing names rather than direct proof of original spelling, so this layout score stays below final-source confidence.

## IDA Verification Notes

- `lookup_funcs 0x004dfd10` reports `sub_4DFD10`, size `0x53a`, exact range `0x004dfd10-0x004e024a`.
- `lookup_funcs 0x004e0250` reports the ordinary destructor body at `0x004e0250-0x004e05c4` exclusive; older notes used `0x004e05c3` as the last observed byte, while current by-memory documentation uses the corrected exclusive-end form.
- IDA decompilation shows constructor writes to object words `a1[1]` through `a1[23]`, matching fields through `+0x5c`.
- IDA UTF-16 reads confirm the constructor resource strings `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, `.DSC`, and `HAIRCOL.TBL`.
- Destructor cleanup agrees with the constructor layout: it walks 0x44-byte part rows from `+0x04`, 0x20-byte layer rows from `+0x10`, and 0x42-byte in-memory `NewHumanMotionEntry` rows from `+0x1c`; after the row-payload loop, UID000185 frees the `+0x1c` motion vector storage and resets its triplet. The destructor then frees the `+0x54` hair-color vector plus `+0x48`, `+0x34`, `+0x28`, `+0x10`, and `+0x04` storage in reverse-style cleanup order.
- 2026-06-14 live IDA MCP rechecked `sub_4DFD10` as size `0x53a`, caller `sub_4F5FB0`, and `sub_4E0250` as size `0x374`, caller `sub_4E6870`. The constructor publishes [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md), installs [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md), zeroes the vector triplets through `a1[23]`, allocates the `+0x34` sentinel/list node, and calls the table/path helpers for `Motion.tbl`, layer/part/descriptor resources, `acc2drw.tbl`, and `HAIRCOL.TBL`. The destructor restores the same vtable, walks the `0x44` part rows, releases nested descriptor buffers, and frees the vectors/list storage in the reverse cleanup family.

## Score Rationale

Completion is `92` because the layout has exact owner/emitter routing, constructor/destructor sizes, singleton/vtable anchors, object-word coverage through `+0x5c`, table-resource provenance, destructor cleanup agreement, complete by-value row declarations, transitive sequence/descriptor types, exact C++03 owner order, eight size guards, and exact inline `NewHumanSequenceFrameTable` slot versus nullable `.frames` semantics proven by three consumers. Confidence is `93` because live IDA and loader/consumer evidence agree on the offsets, widths, dependencies, `0x10` slot stride, `0x09` frame-row stride, and cleanup shape; inferred private lexical spellings remain below original-symbol proof. Formal CPP remains non-body type support, while formal H now emits the complete position-10 declaration block.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
- [UID:0004DQ][0x004e70a0-0x004e70e9.NewHumanCompositionDrawCommandPushBackCompilerSupport](by-memory/0x004e70a0-0x004e70e9.NewHumanCompositionDrawCommandPushBackCompilerSupport.md)
- [UID:0004PA][0x004e5600-0x004e57bb.NewHumanCompositionDrawCommandVectorGrowInsertCompilerSupport](by-memory/0x004e5600-0x004e57bb.NewHumanCompositionDrawCommandVectorGrowInsertCompilerSupport.md)
- [UID:0004DN][0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector](by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)
- [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md)
- [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md)
- [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md)
- [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md)
- [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md)
- [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md)
- [UID:000437][0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect](by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md)
- [UID:000438][0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame](by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md)

## Changes

### 2026-08-16 UID0003F8 Dependency-Complete Header Closure

- This page now owns the complete NewHuman internal row declarations in `NexusTK/render/NewHumanImageLib.h` at H position 10. It follows [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) at position 5 and precedes [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) at position 20 and [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) at position 30.
- `NewHumanPartEntry`, `NewHumanLayerEntry`, `NewHumanMotionEntry`, `NewHumanCompositionDrawCommand`, and `Acc2DrwEntry` are stored by value in standard-library vectors. C++03 requires complete definitions before the class declaration; forward declarations are insufficient. The prior blank formal H and generated header with incomplete vector element types are historical, compile-incomplete state.
- `NewHumanPartEntry` is exactly `0x44`: `partId`, `wchar_t name[20]`, `drawIndexBase`, `descriptorBase`, `descriptorCount`, `rawRecordCount`, descriptor pointer, and sprite-archive pointer. Loader conversion, 68-byte vector growth/destruction, descriptor setup, and archive lookup agree on the width and order.
- `NewHumanLayerEntry` is exactly `0x20`: `layerId`, `char name[20]`, `childCount`, and `childIndexes`. The layer loader and vector helpers agree on the row and its optional owned index array.
- Packed `NewHumanMotionEntry` is exactly `0x42`: 23-byte prefix, `motionId`, 20-byte name, two reserved bytes, direction, fallback motion, frame count, and two dynamic frame-data pointers. The loader, 66-byte vector helpers, and destructor agree on every offset.
- `NewHumanCompositionDrawCommand` is exactly `0x50`: `partId`, by-value `FrameDrawRecord`, by-value `SurfaceSpriteBlitOptions`, and `DLPalette *`. Five OWORD lanes, 80-byte vector helpers, builder, renderer, reorder, and reset paths prove the stride and shallow source shape.
- `Acc2DrwEntry` is exactly three bytes as `bool enabled[3]`; decimal digit parsing, three-byte append/growth, and consumer indexing agree on the representation.
- Transitive by-value dependencies are complete first: packed `NewHumanSequenceFrame` is `0x09`, `NewHumanSequenceFrameTable` is `0x10`, and packed `NewHumanPartFrameDescriptor` is `0x20`. Their loaders and consumers agree on the inline motion table, nullable `frames` member, descriptor pointers, and packed offsets.
- `ImageFrameTable.h` remains the sole owner of complete `FrameDrawRecord`, `RectBounds`, and archive metadata declarations. `Surface.h` remains the sole owner of complete `SurfaceSpriteBlitOptions`; the palette type is pointer-only. This page includes the existing owners instead of duplicating types.
- Eight period-compatible typedef guards enforce every exact width. Only original private lexical spellings remain inferential; raw IDA labels, decompiler temporaries, duplicate dependency structs, and modern-only assertions are rejected.
- Metadata advances from `87/90` to `92/93` because the exact formal H, owner order, transitive dependencies, and size guards are installed. Confidence remains below final-audit strength because private names are inferred rather than symbol-proven.

- 2026-07-22 B004 UID000438 accepted support callback:
  - Raised `85/88 -> 87/90`; owner/emitter and comment-only formal remain unchanged.
  - Clarified that `sequenceFrames` points to an array of inline `0x10`-byte `NewHumanSequenceFrameTable` slots, `sequenceFrames[motionIndex]` is an object/reference, and only slot `.frames` at `+0x0c` is nullable.
  - Added independent UID000417/UID000437/UID000438 consumer confirmation of the slot and packed 9-byte frame-row layouts while preserving all offsets and historical aliases.

- 2026-07-13 B002 UID0004DO source-quality synchronization:
  - Replaced current `NewHumanDrawRecord` support direction with accepted `FrameDrawRecord` for UID000417, UID000438, and `RenderComposition`, and mapped UID000438 raw `+0x10` to `sourceRect`.
  - Preserved every object/nested offset, all unrelated inferred names, metadata, and the existing layout-support formal block; the historical shorthand remains documented as superseded rather than erased.

- 2026-07-14 B004 UID0004DQ typed command-vector synchronization:
  - Score/formal/owner/emitter metadata remain unchanged at `85/88`, UID000092, and comment-only layout support.
  - Replaced current generic `m_auxiliaryEntries`/`void *` labels at `+0x28/+0x2c/+0x30` with the inferred typed `m_compositionDrawCommands` pointer triplet and exact 80-byte row layout.
  - Preserved constructor/destructor symmetry, duplicate part/tag `0x3d` append behavior, Build/Render/Draw lifetime, shallow cleanup, UID0004DN separation, inferred-name caveats, and rejected generic/standalone compiler-body alternatives.

- 2026-07-06 B015 DestroyMotionVector implementation sync:
  - Score unchanged at `85/88`.
  - Clarified that `Motion.tbl` has a 33-byte fixed file prefix plus count-driven frame payloads and becomes a 0x42-byte in-memory `NewHumanMotionEntry`, not a fixed 0x42-byte file row.
  - Split destructor responsibility from UID000185 responsibility: [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) frees per-entry `frameOffsets`/`frameData`, while [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) frees `m_motionEntries` vector storage and resets the triplet.
  - Evidence: current UID000185 MCP session `supervisor_recovery_20260705` confirms destructor call `0x004e0547`, constructor cleanup-table ref `0x0060025a`, checked-free/runtime allocator callee `sub_5C7526`, raw-base large-allocation guard, final triplet reset, and no source proof for a standalone `DestroyMotionVector` body or separate `MotionEntryVector` type.

- 2026-07-06 B004 NewHuman command-side vector support sync:
  - Score unchanged at `85/88`.
  - Added narrow UID0004DN evidence that `BuildPartDrawCommand` passes `this + 13` / byte offset `+0x34` into the command-side pointer-ring/vector growth helper, tying `+0x34..+0x44` to command-side pointer-slot state without broadly renaming the whole region.
  - Evidence: current MCP session `supervisor_recovery_20260705` confirms sole UID0004DN callsite `0x004e2f7a`, helper receiver `this + 13`, 4-byte pointer-slot grow/rebalance behavior, caller-side 9-byte side-record allocation/copy, and remaining caps for exact field names, side-record type/name, and typed `BuildPartDrawCommand` source.
- 2026-07-01 B011 empty-emitter implementation: filled the layout support formal block with the accepted no-standalone-source comment.
- 2026-06-30 B008 LoadPartSpriteDescriptors implementation sync:
  - Score unchanged at `85/88`.
  - Added accepted source-ready `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, and `NewHumanSequenceFrame` loader details used by [UID:00041C][0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md): packed 0x20 descriptor rows, count-bearing primary/secondary fields, motion-indexed 0x10 sequence slots, and 9-byte frame rows.
  - Evidence: current MCP body/disassembly for UID00041C proves `.DSC` file naming, 23-byte header/count reads, descriptor-count allocation, packed descriptor offsets, motion-count table allocation/initialization, and sequence-frame row reads while keeping original spellings inferred.
- 2026-06-30 B009 LoadAcc2DrwTable implementation sync:
  - Score unchanged.
  - Added Acc2Drw producer evidence from [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md), confirming `m_partEntries[7].descriptorCount` as the row count source, `m_acc2drwEntries.clear()` / `push_back()` producer shape, and `Acc2DrwEntry.enabled[0..2]` as the hundreds/tens/ones byte fields.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms UID00041D size/range/padding, constructor-only caller, `acc2drw.tbl` literal, UID00041E full-capacity support, and rejected no-owner/file-only/resource/VectorHelpers/HumanImageLib/successor-merge/raw-helper alternatives. B010's UID00041E marker evidence remains the vector-growth support counterpart.
- 2026-06-30 B007 LoadPartTable implementation sync:
  - Score unchanged at `85/88`.
  - Added accepted source-ready `NewHumanPartEntry` loader details used by [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md): 32-byte `Part.tbl` file rows, 68-byte memory/vector rows, 4-byte `partId`, 20-byte ANSI name, inferred `drawIndexBase` and `descriptorBase`, wide `name`, and `spriteArchive`.
  - Evidence: current MCP body/disassembly for UID00041B re-proves the row reads, `MultiByteToWideChar` conversion, `ResolveSpritePartPath` call, `VectorGrowPart` relation, vector append, no-xref caveat, and `char.dat` sample values while keeping original spellings inferred.
- 2026-07-01 B007 VectorGrowPart implementation sync:
  - Score unchanged at `85/88`.
  - Updated the `NewHumanPartEntry` support note to treat [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md) as file-local [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) marker support for `m_partEntries` rather than unresolved capacity-helper dependency.
  - Evidence: current MCP confirms UID00041G size `0x1d6` / 470 bytes, exact body `0x004e5420-0x004e55f6`, exactly two callsites, receiver setup at object offset `+4`, and 68-byte `NewHumanPartEntry` element stride; constructor and UID00041B source keep the behavior as `m_partEntries.push_back(part)`.
- 2026-06-30 B010 VectorGrowAcc2Drw implementation sync:
  - Score unchanged at `85/88`.
  - Added Acc2Drw vector-growth consumer evidence from [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md), confirming the UID00041D call passes `this + 18` / byte offset `+0x48` into the helper and therefore ties the helper receiver to `m_acc2drwEntries`.
  - Evidence: current MCP session `supervisor_resume_20260629` confirms target size/body-end/padding, sole caller `0x004e195a`, 3-byte vector span arithmetic and inserted-record copy, runtime/vector-only callee set, and rejected class-method/generic-VectorHelpers/runtime-only/standalone-body alternatives. B009's UID00041D implementation now supplies the calling producer body and keeps UID00041E as marker-only full-capacity support.
- 2026-06-30 B006 LoadLayerTable implementation sync:
  - Added the accepted source-ready `NewHumanLayerEntry` declaration details used by [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md): `int layerId`, `char name[20]`, `int childCount`, and `int *childIndexes`.
  - Evidence: current MCP body/disassembly for UID00041A re-proves the row offsets, 32-byte stride, child-index allocation/read loop, vector append, and no-xref caveat while keeping original spellings inferred.
- 2026-06-26 B010 destructor implementation sync:
  - Score unchanged at `85/88`.
  - Added destructor consumer evidence from [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md), confirming the then-current first-draft names including historical `m_auxiliaryEntries`; the 2026-07-14 UID0004DQ synchronization supersedes that generic member label with `m_compositionDrawCommands` while preserving the same exact offset and cleanup route.
  - Evidence: B010 MCP session `80de0a67` reconfirmed destructor cleanup agreement, helper xrefs, helper roles, scalar-wrapper caller, vtable/global refs, and exact boundaries.
- 2026-06-26 B014 composition-bounds implementation sync:
  - Score unchanged at `85/88`.
  - Added consumer evidence from [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md), confirming Part.tbl row-index use, 3-byte `Acc2DrwEntry::enabled[3]` consumption, inferred support names `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, then-used `NewHumanDrawRecord` (now superseded by accepted `FrameDrawRecord`), and `NewHumanCompositionState`.
- 2026-06-25 B011 constructor implementation sync:
  - Score unchanged at `85/88`.
  - Added implementation-ready inferred member and row names used by [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md).
  - Evidence: constructor/support pages now resolve `NewHumanLayerEntry`, `NewHumanPartEntry`, `NewHumanMotionEntry`, `Acc2DrwEntry`, vector member names, and `kNewHumanHairPartIndex` enough for first-draft constructor C++ while preserving the caveat that original spellings are inferred.
- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `80/86`, with strong layout notes but stale parent-gate wording and no current live IDA refresh.
  - Changed to: `85/88`.
  - Summary/evidence: live IDA MCP reconfirmed constructor `0x004dfd10-0x004e024a` size `0x53a`, destructor `0x004e0250-0x004e05c4` size `0x374`, singleton/vtable writes, zeroed object words through `+0x5c`, sentinel allocation at `+0x34`, table-resource loader calls, and destructor cleanup agreement. The layout formal block is comment-only because final field and nested row type names are not source-quality for standalone type C++.
- 2026-06-06: Attached the object layout to [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md). Scores remain `80/86`; this pass only records the direct class parent for the already documented constructor/destructor layout.
- Before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` even though the page contained substantial layout evidence.
- Changed to: `COMPLETION:80`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP rechecked the constructor range, resource strings, constructor field writes, and destructor cleanup agreement on 2026-05-31. The score remains below final-audit status because final original field names and nested row type names are still not fully proven.
