*** UID:00003K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATIndexVector

## Status

- Confidence: strong for behavior and method ownership, medium for original source folder.
- Current recovered file: `source-3/simroot_v2/class_DATIndexVector.cpp`
- Wave2 import source file: `DATIndexVector.cpp`
- Proposed source module: [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), with `common/DATIndexVector.cpp` still a plausible folder alternative.
- Evidence basis: generated Wave3 source/meta, `by-memory/-report.md`, and IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, disassembly, and targeted decompilation checks on 2026-05-24 and 2026-05-25.

## Responsibility

`DATIndexVector` is a reusable index/list helper, not a private `_DATFileMgr` subobject. It combines two related storage views:

- a fill-backed 32-bit pair table initialized by `ResizeAndFill`;
- an intrusive hash bucket/list index keyed by a four-byte integer and hashed with FNV-1a.

The class is archive-named and used by DAT-manager code, but callers also include minimap version state, monster image archive bounds, and fitting-room item-state helpers. Keep it as a standalone helper until final folder ownership is proved.

## Methods And Helpers

| Range | Method/helper | Notes |
| --- | --- | --- |
| [UID:0000WW][0x00423b00-0x00423c3c.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3c.DATIndexVectorResizeAndFill.md) | `ResizeAndFill` | Ensures `entryCount * 2` 32-bit slots, fills with the stored default value, and updates `lastIndex`/`entryCount`. |
| [UID:0000XS][0x00457100-0x0045730e.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730e.DATIndexVectorInsertNode.md) | `InsertNode` | Inserts an intrusive node into a bucket range, coalesces duplicate keys, and rehashes when load factor exceeds `maxLoadFactor`. |
| [UID:0000XT][0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper.md) | private cleanup/remove helper | Detaches and frees a node, updates bucket first/last links, and returns the next node. IDA shows only the `InsertNode` EH/unwind cleanup block calling it. |
| [UID:0000XU][0x004573d0-0x00457428.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457428.DATIndexVectorDestructor.md) | destructor | Frees value storage, clears begin/end/capacity, then tail-jumps into shared [UID:0000XV][0x00457430-0x00457473.LinkedListStateCleanup](by-memory/0x00457430-0x00457473.LinkedListStateCleanup.md). |
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

Support records:

- [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md)
- [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md)

## Caller Evidence

IDA MCP caller checks on 2026-05-24 showed:

- `ResizeAndFill` callers include fitting-room item-state helpers at `0x00422020`, `0x00422470`, and `0x00423470`, minimap version-manager code at `0x004563c0`, `0x00456480`, `0x00456700`, and `0x00457480`, DAT manager code at `0x0049bd30` and `0x0049ce50`, and monster image library code at `0x004daec0` and `0x004dc2e0`.
- `InsertNode` callers include `MiniMapVersionManager::UpdateHashList` at `0x00456a90`, `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60`, and its own rehash path.
- `FindNodeByKey` callers include `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60` and [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) at `0x004570b0`.
- `VectorGrowArchiveIndex` at `0x004e5990` is separate: it grows a monster archive-index array and is called only by `MonsterImageLib::LoadMonsterArchives`.

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
