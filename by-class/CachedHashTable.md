*** UID:00001F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CachedHashTable

## Summary

`CachedHashTable` is a small `LObject`-derived fixed-entry hash/cache table. It stores a contiguous entry buffer, a parallel slot-state byte buffer, entry size, slot count, active entry count, and four one-byte hash seeds.

Current evidence proves the class layout, lifecycle methods, raw helper island, count accessors, and vtable. Active runtime construction is still unresolved, but that only affects priority; it does not make the class disposable for source-complete binary replication.
IDA raw disassembly also proves a class-local helper block that active generated output currently omits.

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
| `0x004c6160-0x004c6258` | `CachedHashTable::CachedHashTable` | Initializes `LObject`, allocates entry and slot-state buffers, zeroes slot state, and seeds hash bytes. |
| `0x004c6260-0x004c62cd` | `CachedHashTable::~CachedHashTable` | Frees entry and slot-state buffers, clears pointers, and tears down `LObject`. |
| `0x004c62d0-0x004c64de` | helper island | Hash index, clear, slot access/update, [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md), and unchecked entry-address helper. See [UID:00016P][0x004c62d0-0x004c64de.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md). |
| `0x004c64f0-0x004c659b` | `CachedHashTable::ScalarDeletingDestructor` | Runs destructor and optionally frees the object. |

## Evidence

- Active `class_CachedHashTable.cpp` emits all three methods and a consistent 28-byte layout.
- `class_CachedHashTable.meta_wave3` records import source `CachedHashTable.cpp` and strong imported reversal grades.
- IDA MCP confirms all three method boundaries.
- IDA raw disassembly confirms the omitted helper island between the ordinary destructor and scalar deleting destructor. Current IDA models only the two tiny count accessors in that island.
- IDA confirms the primary vtable at `0x0061aac4`; current generated metadata still reports `vtable_count: 0`.
- IDA MCP caller checks returned no direct callers for these methods; `xrefs_to` only found vtable/self-reference evidence.
- 2026-05-26 IDA MCP/`py_eval` recheck still found no direct callers or xrefs to the constructor/destructor/helper starts. The only live xrefs to `0x0061aac4` are the vtable stores/reads inside the constructor, destructor, and scalar deleting destructor.
- 2026-05-26 IDA `py_eval` recheck confirmed the vtable layout: RTTI at `0x0061aac0`, slots `0x004c64f0`, `0x004f4b10`, and `0x0041b6c0`, followed by the next RTTI pointer at `0x0061aad0`. It also confirmed the raw helper starts at `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` are not IDA function objects but contain coherent method-shaped bodies over the same layout.
- 2026-05-31 IDA MCP recheck confirms [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md) as the exact vtable-data child range. `0x0061aad0` is `SimpleHelpTextPartPane` RTTI and `0x0061aad4` is the next class vtable start, so `CachedHashTable` does not extend past `0x0061aad0`.

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
