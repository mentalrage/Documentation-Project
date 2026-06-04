*** UID:0000HZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CachedHashTable

## Status

- Proposed module: `util/CachedHashTable.cpp`
- Proposed header: `util/CachedHashTable.h`
- Confidence: strong for source-replication ownership, medium for final utility-file placement, unresolved for active runtime use.
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
- constructor at `0x004c6160-0x004c6259`
- ordinary destructor at `0x004c6260-0x004c62ce`
- helper island at `0x004c62d0-0x004c64df`, including modeled count accessors at `0x004c64b0` and `0x004c64c0`
- scalar deleting destructor at `0x004c64f0-0x004c659c`

## Evidence

- 2026-06-04 live IDA MCP reports modeled lifecycle boundaries: constructor `0x004c6160-0x004c6259` size `0xf9`, ordinary destructor `0x004c6260-0x004c62ce` size `0x6e`, and scalar deleting destructor `0x004c64f0-0x004c659c` size `0xac`.
- 2026-06-04 live IDA raw disassembly confirms a class-local helper island at `0x004c62d0-0x004c64df` for hash-index calculation, clear, slot removal, checked slot access, fixed-entry copy/update, two count accessors, and unchecked entry addressing. The final helper return is at `0x004c64de`; alignment begins at `0x004c64e1`.
- 2026-06-04 live IDA reports the larger helper starts `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` are still raw/non-function starts, while `0x004c64b0` and `0x004c64c0` are exact `0x4`-byte functions returning fields `+0x10` and `+0x14`.
- 2026-06-04 live IDA xref checks report no direct code or data references to the constructor, ordinary destructor, raw helper starts, or count accessors. The scalar deleting destructor is referenced only from vtable slot `0x0061aac4`.
- 2026-06-04 live IDA confirms vtable data at `0x0061aac0`: RTTI `??_R4CachedHashTable@@6B@`, slot `0x0061aac4 -> 0x004c64f0`, slot `0x0061aac8 -> 0x004f4b10`, slot `0x0061aacc -> 0x0041b6c0`, followed by `SimpleHelpTextPartPane` RTTI at `0x0061aad0`.
- 2026-06-04 live IDA `DataRefsTo(0x0061aac4)` returns only `0x004c61a1`, `0x004c6288`, and `0x004c651f`, matching constructor/destructor/scalar-deleting-destructor vtable stores or reads and preserving the unresolved live-construction caveat.

## Source-Structure Decision

Use `util/CachedHashTable.cpp` as a provisional source module. Its behavior is generic storage/cache infrastructure and should not be assigned to UI, map, or archive code without caller evidence.

For full binary replication, keep this class and its helper island in the source tree even though active caller evidence is absent. The no-caller result only lowers runtime priority; it does not make the code disposable, because the constructor/destructor, vtable, RTTI, and raw helper bodies are all present in the binary.

Do not merge it into [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) or [UID:0000IR][Deque](by-file/Deque.md). Those helpers have active caller evidence and different layouts.

## Open Migration Notes

- The no-caller result is important: migration should keep this as a low-priority utility/legacy candidate until object construction or non-lifecycle vtable references are found.
- Helper names and public signatures remain provisional because the live database still has no recovered caller for the raw helper starts.
- Do not emit final reconstruction C++ yet; the helper surface, original field names, and live-use status remain below the 95/95 bar.
- The primary vtable and helper island are still real binary content and should be kept for source-complete replication even if this ultimately proves to be retained legacy code.

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
  - Before: page documented the standalone utility class, lifecycle methods, vtable, raw helper island, and no-caller result but remained unevaluated and had no projected path.
  - After: score reflects strong source-replication evidence for the class and helper island, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `CachedHashTable.cpp` under `util/`.
  - Evidence: IDA checks confirm lifecycle method starts, exact primary vtable child range, count accessors, raw helper island, and no direct callers; linked memory/type pages cover the layout and helper ranges.
- 2026-06-03: Corrected the scalar deleting destructor inventory endpoint from `0x004c659b` to exclusive end `0x004c659c`, matching [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) and the written IDA evidence that the final `retn 4` consumes bytes through `0x004c659b`.
- 2026-06-04: Raised scores from `72/80` to `84/88` after live IDA MCP revalidated all lifecycle boundaries, corrected the constructor/destructor/helper intervals to half-open ranges, reconfirmed the exact vtable slots and `0x0061aad0` boundary, and proved the no-caller caveat with current xref checks. Completion remains below final-audit level because helper names, public signatures, and live construction are still unresolved.
