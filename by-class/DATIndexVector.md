*** UID:00003K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATIndexVector

## Status

- Confidence: strong for behavior, method ownership, and object identity; medium-high for original source folder and final field names.
- Current recovered file: `source-3/simroot_v2/class_DATIndexVector.cpp`
- Wave2 import source file: `DATIndexVector.cpp`
- Proposed source module: [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), with `common/DATIndexVector.cpp` still a plausible folder alternative.
- Parent/C++ status: attached to [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), the current standalone `NexusTK/archive/DATIndexVector.cpp` source root used by the validator. The class/file pair now clears the corrected `85/85` routing gate for exact DATIndexVector method children, but final C++ remains blank because field split, helper naming, and possible common-container folder ownership are still below the final-source gate.
- Evidence basis: generated Wave3 source/meta, `by-memory/-report.md`, and IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, disassembly, and targeted decompilation checks on 2026-05-24 and 2026-05-25.

## Responsibility

`DATIndexVector` is a reusable index/list helper, not a private `_DATFileMgr` subobject. It combines two related storage views:

- a fill-backed 32-bit pair table initialized by `ResizeAndFill`;
- an intrusive hash bucket/list index keyed by a four-byte integer and hashed with FNV-1a.

The class is archive-named and used by DAT-manager code, but callers also include minimap version state, monster image archive bounds, and fitting-room item-state helpers. Keep it as a standalone helper until final folder ownership is proved.

## Changes

- 2026-06-03: Marked the class reconstructable after the live-verified [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) boundary correction reaffirmed DATIndexVector ownership. Evidence is the existing DATIndexVector class/file documentation plus the 2026-06-03 live IDA boundary correction for `sub_423B00`.

## Methods And Helpers

| Range | Method/helper | Notes |
| --- | --- | --- |
| [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) | `ResizeAndFill` | Ensures `entryCount * 2` 32-bit slots, fills with the stored default value, and updates `lastIndex`/`entryCount`. |
| [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) | `InsertNode` | Inserts an intrusive node into a bucket range, coalesces duplicate keys, and rehashes when load factor exceeds `maxLoadFactor`. |
| [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) | private cleanup/remove helper | Detaches and frees a node, updates bucket first/last links, and returns the next node. IDA shows only the `InsertNode` EH/unwind cleanup block calling it. |
| [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) | destructor | Frees value storage, clears begin/end/capacity, then tail-jumps into shared [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md). |
| [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) | `FindNodeByKey` | Uses the same four-byte FNV-1a hash as `InsertNode` and scans the selected bucket range for an exact integer key. |

## Layout Notes

Wave3 currently exposes two overlapping C++ views:

```cpp
struct DATIndexVectorLayout {
    uint32_t scalar00;
    uint32_t fillValue;
    uint32_t reserved08;
    uint32_t* valuesBegin;
    uint32_t* valuesEnd;
    uint32_t* valuesCapacity;
    int32_t lastIndex;
    int32_t entryCount;
};
```

```cpp
class DATIndexVector {
public:
    float maxLoadFactor;
    DATIndexVectorNode* listHead;
    uint32_t nodeCount;
    DATIndexVectorBucket* bucketsBegin;
    DATIndexVectorBucket* bucketsEnd;
    DATIndexVectorBucket* bucketsCapacity;
    uint32_t bucketMask;
    uint32_t bucketCount;
};
```

This may be one helper with multiple initialized subobject views, or Wave3 may still be conflating closely related VC6-era list/vector helpers. Do not generate a final header from either view without reviewing all embedded-object call sites.

The generic sentinel-list node allocation and list-state cleanup helpers are not owned here; they are tracked under [UID:0000KR][LinkedList](by-file/LinkedList.md). `DATIndexVector` should own only the bucket-aware keyed node operations and the value-table/bucket-table state that wraps those generic nodes.

Batch076 parent-gate review treats the exact DATIndexVector method pages as routable to this class because the documented helpers cover the value-table resize/fill path, bucket insert/rehash path, insert cleanup/remove helper, destructor storage release, and keyed lookup. The destructor's `this + 1` handoff still belongs to the shared linked-list cleanup page, but the freed `+0x0c/+0x10/+0x14` storage fields and sibling helper evidence are DATIndexVector state.

Support records:

- [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md)
- [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md)

## Caller Evidence

IDA MCP caller checks on 2026-05-24 showed:

- `ResizeAndFill` callers include fitting-room item-state helpers at `0x00422020`, `0x00422470`, and `0x00423470`, minimap version-manager code at `0x004563c0`, `0x00456480`, `0x00456700`, and `0x00457480`, DAT manager code at `0x0049bd30` and `0x0049ce50`, and monster image library code at `0x004daec0` and `0x004dc2e0`.
- `InsertNode` callers include `MiniMapVersionManager::UpdateHashList` at `0x00456a90`, `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60`, and its own rehash path.
- `FindNodeByKey` callers include `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60` and [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) at `0x004570b0`.
- `VectorGrowArchiveIndex` at `0x004e5990` is separate: it grows a monster archive-index array and is called only by `MonsterImageLib::LoadMonsterArchives`.

## Score Rationale

Completion is raised to `85` because the class page now has the exact core method inventory, support struct links, caller fanout, layout caveats, source-file parent, and routing boundary against generic linked-list cleanup. Confidence is raised to `86` because multiple exact `85+` method pages agree on the DATIndexVector object shape and shared-container caller spread; it remains below final-source confidence because the original folder, final field names, and possible value-table/hash-view split are still reviewable.

## File Placement

Current best placement is a standalone [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) source module. It should not be merged into [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), because DAT-manager callers are only part of the caller set. It should also not be treated as a render-owned helper, because archive and non-render callers use the same object shape.

## Open Questions

- Whether the final folder should be `archive/` because of the imported `DATIndexVector.cpp` name, or `common/`/`utility/` because of the broad caller fanout.
- Whether `ResizeAndFill`'s value-table view and the hash bucket/list view are one original class or two adjacent STL-like helper templates currently collapsed by recovery.

## Cross-References

- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/80`.
  - Summary/evidence: method/helper ranges, layout views, support records, caller fanout, source-placement reasoning, and open questions are documented with IDA caller evidence; remaining uncertainty is whether the value-table and bucket/list views are one original class or conflated helper shapes.

- 2026-06-06 A008 parent-chain pass:
  - Before: [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md) and [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md) pointed at this class, but the class had no autogen parent, leaving both child struct pages blocked by `autogen_parent_unknown`.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), the current standalone `NexusTK/archive/DATIndexVector.cpp` source root.
  - Evidence: [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is assigned to that generated source root at `85/80`; this class is `82/80`; and method/helper ranges, support records, caller fanout, and standalone ownership evidence rule out a private `DATFileMgr` fold. The `archive/` folder and exact layout split remain provisional, so final C++ stays blank.

- 2026-06-07 A007 Batch 076 parent-gate repair:
  - Before: `82/80`; exact DATIndexVector method children could not satisfy the corrected child-and-parent `85/85` assignment gate against this class.
  - After: `85/86`; the exact core method inventory, destructor storage evidence, support struct links, caller fanout, and standalone file parent now support routing exact DATIndexVector method pages here.
  - Evidence: [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md), [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md), [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md), [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md), and [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) document a coherent shared helper while preserving final folder/layout caveats.
