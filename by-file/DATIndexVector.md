*** UID:0000IP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DATIndexVector

## Status

- Confidence: medium for `archive/DATIndexVector.cpp`, strong that the helper should be standalone rather than folded into `DATFileMgr.cpp`.
- Proposed module: `NexusTK/archive/DATIndexVector.cpp`
- Proposed header: `NexusTK/archive/DATIndexVector.h`
- Current recovered file: `source-3/simroot_v2/class_DATIndexVector.cpp`
- Evidence basis: Wave2 import source file `DATIndexVector.cpp`, Wave3 generated source, exact IDA MCP function/caller checks on 2026-05-24 and 2026-05-25, and cross-caller review against DAT, minimap, fitting-room, and monster image code.

## Proposed Contents

This file should own the reusable archive/index helper and its small support records.

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) | discontiguous | `archive/DATIndexVector.cpp` | FNV-1a keyed intrusive hash/list plus value-table resize helper. |
| [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md) | type-only | `archive/DATIndexVector.h` or private source struct | Intrusive node: next, prev, integer key, payload pointer. |
| [UID:0001U0][DATIndexVectorBucket](by-type/by-struct/DATIndexVectorBucket.md) | type-only | `archive/DATIndexVector.h` or private source struct | Per-bucket first/last pair over the shared intrusive list. |
| `RemoveNodeForInsertUnwind` / private remove helper | `0x00457310-0x004573b2` | `archive/DATIndexVector.cpp` internal helper | Detaches/frees one keyed node; IDA-observed caller is only the `DATIndexVector::InsertNode` EH/unwind cleanup block. |

## Method Ranges

| Range | Symbol | Role |
| --- | --- | --- |
| [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) | `DATIndexVector::ResizeAndFill` | Value-table capacity/initialization helper. |
| [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) | `DATIndexVector::InsertNode` | Bucket/list insert, duplicate collapse, load-factor rehash. |
| [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) | private cleanup/remove helper | Bucket/list unlink and node free used from `InsertNode` EH cleanup. |
| [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) | `DATIndexVector::~DATIndexVector` | Frees value storage and list state. |
| [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) | `DATIndexVector::FindNodeByKey` | Key lookup in selected bucket range. |

## File-Level Rationale

The helper is used by several subsystems:

- DAT manager construction and `_DATFileMgr::InsertOrFindEntry`.
- `MiniMapVersionManager` initialization, teardown, and hash-list updates.
- `MonsterImageLib` archive/bounds lookup paths.
- Fitting-room item-state list/vector helpers.

That caller mix rules out a manager-private placement in [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). The imported source name `DATIndexVector.cpp` and DAT-manager use still make `archive/DATIndexVector.cpp` a reasonable first placement, but the final folder should remain reviewable if more non-DAT users are recovered.

Because this helper has non-DAT callers, it is also tracked in [UID:0001QA][client_containers](by-meta/client_containers.md) as a possible utility-container candidate. Generic sentinel-list allocation and cleanup support is tracked separately in [UID:0000KR][LinkedList](by-file/LinkedList.md); keep only DATIndexVector's bucket-aware keyed helpers here.

2026-05-31 IDA MCP recheck confirms the resize/fill helper at `0x00423b00`, insert/remove/destructor/find helpers at `0x00457100`, `0x00457310`, `0x004573d0`, and `0x00457580`, and caller fan-in from DAT manager code plus minimap, fitting-room, and monster-image code. This supports a standalone source file and rules out folding the helper into `DATFileMgr.cpp`; the `NexusTK/archive/` projected path follows current proposed-source-tree ownership but remains reviewable if later evidence proves the original project placed it in a common container folder.

## Exclusions

Do not place these here:

- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md): only called by `DATFile::ReadAllEntries` and `ReadAllEntriesAlt`, so it remains with [UID:0000IN][DATFile](by-file/DATFile.md) as private/static-style support.
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md) if created later: IDA shows it is called only by `MonsterImageLib::LoadMonsterArchives`, so current ownership leans [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), not this helper.
- `_DATFileMgr` resolver/string lookup methods: those remain [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) internal manager code.

## Migration Notes

Likely Wave3 dry-run sequence after review:

```powershell
python E:\NTK\GhidraBridge\source-3\wave3.py rename file class_DATIndexVector.cpp DATIndexVector.cpp --dry-run
python E:\NTK\GhidraBridge\source-3\wave3.py set file-simpath DATIndexVector.cpp archive/DATIndexVector.cpp --dry-run
```

Before applying ownership changes, review whether the value-table/bucket-table fields need a split type model. The `0x00457310` attachment question is resolved for now: keep it in `DATIndexVector.cpp` as private exception-cleanup support, not as a public erase API.

## Open Questions

- Is `archive/` the true original folder, or did the project have a common container/helper folder included by archive and render code?
- Is the original file named `DATIndexVector.cpp`, `DATIndex.cpp`, or a more generic container name?
- Should `DATIndexVectorNode` and `DATIndexVectorBucket` be public header declarations or private source-only implementation structs?

## Cross-References

- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: helper contents, method ranges, caller fanout, file-level rationale, exclusions, migration notes, open naming/folder questions, and archive/container cross-references are documented; confidence is medium-high because standalone ownership is strong but exact original folder/name remains uncertain.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `84/78`, and module/header paths used `archive/` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"`, scores `85/80`, and proposed paths `NexusTK/archive/DATIndexVector.cpp/.h`.
  - Summary/evidence: IDA MCP reconfirmed exact helper starts and broad non-DAT caller fan-in. The path is assigned to match current `proposed-source-tree.md`, but the confidence remains below high because a future common-container folder remains plausible. No C++ reconstruction code is emitted yet because method rewrites, field names, and original folder confidence are below the `95+` final-code gate.
