*** UID:0000HZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CachedHashTable

## Status

- Proposed module: `util/CachedHashTable.cpp`
- Proposed header: `util/CachedHashTable.h`
- Confidence: strong for source-replication ownership, medium for final utility-file placement, unresolved for active runtime use.
- Current recovered source: `source-3/simroot_v2/class_CachedHashTable.cpp`
- Primary class: [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- Primary vtable: [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)

## File Role

`CachedHashTable.cpp` is the likely source for a small fixed-entry hash table/cache helper. The recovered class allocates one fixed-size entry buffer, one parallel slot-state byte buffer, records entry size and slot count, and seeds four per-instance hash bytes with `rand()`.

Current IDA xref checks found no direct constructor/destructor callers. Treat this as a recovered utility class that may be unused legacy code, indirectly constructed through unmodeled data, or referenced only through code patterns not currently represented as direct calls.

## Likely Contents

- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md)
- constructor at `0x004c6160-0x004c6258`
- ordinary destructor at `0x004c6260-0x004c62cd`
- helper island at `0x004c62d0-0x004c64de`, including modeled count accessors at `0x004c64b0` and `0x004c64c0`
- scalar deleting destructor at `0x004c64f0-0x004c659b`

## Evidence

- `class_CachedHashTable.meta_wave3` imports `CachedHashTable` from `CachedHashTable.cpp` with three included methods and a 28-byte Ghidra-derived layout.
- Active `class_CachedHashTable.cpp` shows an embedded `LObject`, fixed-entry allocation, slot-state allocation/zeroing, and four random hash seeds.
- IDA MCP confirms method starts and sizes: constructor `0xf9`, destructor `0x6e`, scalar deleting destructor `0xac`.
- IDA MCP `xrefs_to` shows the vtable at `0x0061aac4` is referenced by the constructor/destructor bodies and contains the scalar deleting destructor pointer.
- IDA raw disassembly confirms a class-local helper island at `0x004c62d0-0x004c64de` for hash index calculation, clear, slot access, slot update, and count/address accessors. Current IDA models only the two count accessors at `0x004c64b0` and `0x004c64c0`; the larger helper starts remain raw/non-function starts.
- IDA MCP caller checks on the three method starts returned no direct callers in the current database.
- 2026-05-26 IDA MCP/`py_eval` recheck reconfirmed constructor `0x004c6160`, destructor `0x004c6260`, scalar deleting destructor `0x004c64f0`, and the two `0x4`-byte count accessors at `0x004c64b0`/`0x004c64c0`. It still reports the larger helper starts as raw/non-function starts, no direct callers or xrefs to the lifecycle/helper starts, and only constructor/destructor/scalar-deleting-destructor data refs to the vtable at `0x0061aac4`.
- The same IDA recheck confirmed the vtable sequence at `0x0061aac0`: RTTI pointer, scalar deleting destructor, inherited `LObject` slot, inherited/default no-op slot, then the next class RTTI pointer at `0x0061aad0`. This supports a standalone class source unit even without a recovered construction caller.
- 2026-05-31 IDA MCP recheck confirms [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md) as the exact vtable-data child range and proves the end boundary before `SimpleHelpTextPartPane` RTTI/vtable data.

## Source-Structure Decision

Use `util/CachedHashTable.cpp` as a provisional source module. Its behavior is generic storage/cache infrastructure and should not be assigned to UI, map, or archive code without caller evidence.

For full binary replication, keep this class and its helper island in the source tree even though active caller evidence is absent. The no-caller result only lowers runtime priority; it does not make the code disposable, because the constructor/destructor, vtable, RTTI, and raw helper bodies are all present in the binary.

Do not merge it into [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) or [UID:0000IR][Deque](by-file/Deque.md). Those helpers have active caller evidence and different layouts.

## Generated Output Caveats

- Active generated source uses modernized C++ surface syntax and generic `m_*` names. Use it for structure and behavior, not final original source style.
- Active generated source omits the helper island at `0x004c62d0-0x004c64de`, including the two IDA-modeled count accessors.
- Current generated metadata reports `vtable_count: 0`, but IDA confirms the primary vtable at `0x0061aac4`.
- The no-caller result is important: migration should keep this as a low-priority utility/legacy candidate until object construction or non-lifecycle vtable references are found.
- The generated lifecycle methods are useful, but they are not the complete class implementation.

## Cross-References

- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md)
- [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md)
- [UID:00016P][0x004c62d0-0x004c64de.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md)
- [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000KV][LObject](by-file/LObject.md)

## Changes

- 2026-05-30/2026-05-31: Grading changed from `0/0` to `72/80`, and the validator reconstruction path was assigned to `NexusTK/util/`.
  - Before: page documented the standalone utility class, lifecycle methods, vtable, raw helper island, no-caller result, and generated-output omissions but remained unevaluated and had no projected path.
  - After: score reflects strong source-replication evidence for the class and helper island, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `CachedHashTable.cpp` under `util/`.
  - Evidence: IDA checks confirm lifecycle method starts, exact primary vtable child range, count accessors, raw helper island, and no direct callers; linked memory/type pages cover the layout and helper ranges.
