*** UID:00001F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CachedHashTable

## Summary

`CachedHashTable` is a small `LObject`-derived fixed-entry hash/cache table. It stores a contiguous entry buffer, a parallel slot-state byte buffer, entry size, slot count, active entry count, and four one-byte hash seeds.

Current evidence proves the class layout, lifecycle methods, raw helper island, count accessors, and vtable. Active runtime construction is still unresolved, but that only affects priority; it does not make the class disposable for source-complete binary replication.
IDA raw disassembly also proves a class-local helper block between the ordinary destructor and scalar deleting destructor.

## Likely Original Placement

- Source: [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- Vtable: [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md), with exact vtable bytes split as [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md)
- Proposed path: `util/CachedHashTable.cpp`
- Confidence: strong for source-replication ownership, medium for final utility-file placement, unresolved for active runtime use.

## Layout

See [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md).

```text
+0x00  LObject base
+0x04  void* entriesBuffer
+0x08  uint8_t* slotStateBuffer
+0x0c  int entrySize
+0x10  int slotCount
+0x14  int entryCount
+0x18  uint8_t hashSeed0
+0x19  uint8_t hashSeed1
+0x1a  uint8_t hashSeed2
+0x1b  uint8_t hashSeed3
```

Observed size is `0x1c` bytes.

## Methods

| Address | Name | Role |
| --- | --- | --- |
| `0x004c6160-0x004c6259` | `CachedHashTable::CachedHashTable` | Initializes `LObject`, allocates entry and slot-state buffers, zeroes slot state, and seeds hash bytes. |
| `0x004c6260-0x004c62ce` | `CachedHashTable::~CachedHashTable` | Frees entry and slot-state buffers, clears pointers, and tears down `LObject`. |
| `0x004c62d0-0x004c64df` | helper island | Hash index, clear, slot access/update, [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md), and unchecked entry-address helper. See [UID:00016P][0x004c62d0-0x004c64de.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md). |
| `0x004c64f0-0x004c659c` | `CachedHashTable::ScalarDeletingDestructor` | Runs destructor and optionally frees the object. |

## Evidence

- 2026-06-04 live IDA MCP confirms modeled method boundaries: constructor `0x004c6160-0x004c6259`, ordinary destructor `0x004c6260-0x004c62ce`, and scalar deleting destructor `0x004c64f0-0x004c659c`.
- 2026-06-04 live IDA confirms the primary vtable range at `0x0061aac4-0x0061aad0`: slots are `0x004c64f0`, `0x004f4b10`, and `0x0041b6c0`, with the next RTTI pointer at `0x0061aad0`.
- 2026-06-04 live IDA `DataRefsTo(0x0061aac4)` returns `0x004c61a1`, `0x004c6288`, and `0x004c651f`, matching lifecycle vtable writes/reads only. `CodeRefsTo` for the constructor, destructor, helper starts, and accessors is empty.
- 2026-06-04 live IDA raw disassembly confirms the helper island touches only the documented 28-byte layout: `+0x04` entry storage, `+0x08` slot-state bytes, `+0x0c` entry size, `+0x10` slot count, and `+0x14` entry count.
- 2026-06-04 live IDA still reports the larger helper starts at `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` as raw/non-function starts; only `0x004c64b0` and `0x004c64c0` are modeled as exact `0x4`-byte accessors.

For source-complete reconstruction, this should remain a real utility class rather than being ignored as dead code. Its current status is "reconstructable but no confirmed live construction site."

## Open Questions

- Whether this class is unused legacy code, a table constructed only from currently unmodeled raw/indirect code, or an artifact of an optional feature.
- Final names for the slot-state states and the hash function that consumes the four seed bytes.
- Whether caller recovery will prove the raw helper names or show this as legacy library code retained without live callers.
- Whether the original source placed this in a general `util/` folder or a feature-local cache module.

## Cross-References

- File: [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- Layout: [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- Vtable: [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- Vtable data: [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md)
- Memory: [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md)
- Memory: [UID:00016P][0x004c62d0-0x004c64de.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md)
- Memory: [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md)
- Related: [UID:0001QA][client_containers](by-meta/client_containers.md), [UID:00007D][LObject](by-class/LObject.md)

## Changes

- What existed before: the page documented layout, lifecycle methods, raw helpers, vtable evidence, and unresolved live construction.
- What it was changed to: the class is marked reconstructable, scores were raised to `82/84`, and exact vtable-data child range [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md) was added.
- Summary and evidence: object layout, constructor/destructor, scalar delete, helper island, vtable bytes, and no-caller caveat are covered; final helper names and whether this is legacy/indirectly constructed code remain unresolved.
- 2026-06-03: Corrected the scalar deleting destructor method row from `0x004c64f0-0x004c659b` to exclusive end `0x004c659c`, matching [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) and its written IDA boundary evidence.
- 2026-06-04: Raised scores from `82/84` to `86/88` and attached this reconstructable class to [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md). The increase is based on live IDA revalidation of half-open lifecycle boundaries, exact vtable slots and next-RTTI boundary, current no-caller xrefs, and raw helper field touchpoints. Final source C++ remains blank because helper names/signatures and live construction remain unresolved.
