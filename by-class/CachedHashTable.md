*** UID:00001F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "CachedHashTable.h"

#include "MemoryMan.h"

#include <stdlib.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_CACHEDHASHTABLE_H
#define NEXUSTK_UTIL_CACHEDHASHTABLE_H

#include "LObject.h"

class CachedHashTable : public LObject
{
public:
    CachedHashTable(int entrySize, int slotCount);
    virtual ~CachedHashTable();

    unsigned int ComputeHashIndex(const void *keyBytes, int keyLength) const;
    void Clear();
    void *RemoveAt(unsigned int slotIndex);
    void *GetAt(unsigned int slotIndex) const;
    int SetAt(const void *entry, unsigned int slotIndex);
    int GetSlotCount() const;
    int GetEntryCount() const;

private:
    void *GetEntryAddressUnchecked(unsigned int slotIndex) const;

    unsigned char *m_entries;
    unsigned char *m_slotState;
    int m_entrySize;
    int m_slotCount;
    int m_entryCount;
    unsigned char m_hashSeed[4];
};

typedef char CachedHashTableSizeMustBe28[
    sizeof(CachedHashTable) == 0x1c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CachedHashTable

## Summary

`CachedHashTable` is a small `LObject`-derived fixed-entry hash/cache table. It stores a contiguous entry buffer, a parallel slot-state byte buffer, entry size, slot count, active entry count, and four one-byte hash seeds.

Current evidence proves the class layout, lifecycle methods, raw helper island, count accessors, and vtable. Active runtime construction is still unresolved, but that only affects priority; it does not make the class disposable for source-complete binary replication.
IDA raw disassembly also proves a class-local helper block between the ordinary destructor and scalar deleting destructor.

B009's 2026-07-03 callback established [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) as a non-emitting lifecycle/split index. The 2026-08-14 whole-file callback completed that split: exact source children now emit constructor, ordinary destructor, helpers, and accessors through this class, while the scalar deleting destructor, EH objects, RTTI/vtable data, and padding remain documented compiler consequences with no duplicate source.

## Likely Original Placement

- Source: [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- Vtable: [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md), with exact RTTI/vtable bytes split as [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md)
- Proposed path: `util/CachedHashTable.cpp`
- Confidence: strong for source-replication ownership and utility-file placement, unresolved for active runtime use after IDA and PE route checks.

## Layout

See [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md).

```text
+0x00  LObject base
+0x04  unsigned char* m_entries
+0x08  unsigned char* m_slotState
+0x0c  int m_entrySize
+0x10  int m_slotCount
+0x14  int m_entryCount
+0x18  unsigned char m_hashSeed[4]
```

Observed size is `0x1c` bytes.

The selected names are source-facing reconstruction names backed by constructor/destructor/helper semantics. Historical `entriesBuffer` and `slotStateBuffer` spellings remain descriptive aliases for the two storage roles, not the selected final member spelling.

## Methods

| Address | Name | Role |
| --- | --- | --- |
| `0x004c6160-0x004c6259` | `CachedHashTable::CachedHashTable` | Initializes `LObject`, allocates entry and slot-state buffers, zeroes slot state, and seeds hash bytes. |
| `0x004c6260-0x004c62ce` | `CachedHashTable::~CachedHashTable` | Frees entry and slot-state buffers, clears pointers, and tears down `LObject`. |
| `0x004c62d0-0x004c64e1` | helper island | Hash index, clear, slot access/update, [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md), and unchecked entry-address helper. See [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md). |
| `0x004c64b0-0x004c64b4` | `int CachedHashTable::GetSlotCount() const` | Exact non-virtual leaf accessor; returns `m_slotCount` at `+0x10`. |
| `0x004c64c0-0x004c64c4` | `int CachedHashTable::GetEntryCount() const` | Exact non-virtual leaf accessor; returns `m_entryCount` at `+0x14`. |
| `0x004c64f0-0x004c659c` | `CachedHashTable::ScalarDeletingDestructor` | Compiler scalar-deleting destructor wrapper; source should express the ordinary destructor, not this wrapper body. |

The accessor rows are ordinary methods, not virtual slots. Both use an implicit ECX receiver, return `int` in EAX, have no explicit stack arguments or side effects, and contain only the physical return-address stack row. Their exact bodies are `8B 41 10 C3` and `8B 41 14 C3`. No direct IDA/PE route survives, so they are retained utility/legacy API rather than dead or compiler-generated code.

## Header Ownership

- The two out-of-line definitions belong to the exact [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) and route through `NexusTK/util/CachedHashTable.cpp`.
- Their declarations are `int GetSlotCount() const;` and `int GetEntryCount() const;`, but those declarations belong only inside the complete `CachedHashTable` class declaration owned by this class/file family.
- UID00016Q therefore correctly keeps its formal H block blank. A child-owned header fragment would duplicate or detach member declarations from their class. This page also remains blank until a coordinated whole-class H reconstruction supplies the complete declaration rather than two isolated methods.
- Fresh canonical IDA currently lacks a local `CachedHashTable` UDT and still presents raw accessor names/types. That analysis state is a supervisor Gate 2B handoff and does not weaken the source declaration boundary above.

## Evidence

- 2026-06-04 live IDA MCP confirms modeled method boundaries: constructor `0x004c6160-0x004c6259`, ordinary destructor `0x004c6260-0x004c62ce`, and scalar deleting destructor `0x004c64f0-0x004c659c`.
- 2026-06-04 live IDA confirms the primary RTTI/vtable range at `0x0061aac0-0x0061aad0`: `0x0061aac0 -> ??_R4CachedHashTable@@6B@`, slots are `0x004c64f0`, `0x004f4b10`, and `0x0041b6c0`, with the next RTTI pointer at `0x0061aad0`.
- 2026-06-04 live IDA `DataRefsTo(0x0061aac4)` returns `0x004c61a1`, `0x004c6288`, and `0x004c651f`, matching lifecycle vtable writes/reads only. `CodeRefsTo` for the constructor, destructor, helper starts, and accessors is empty.
- 2026-06-04 live IDA raw disassembly confirms the helper island touches only the documented 28-byte layout: `+0x04` entry storage, `+0x08` slot-state bytes, `+0x0c` entry size, `+0x10` slot count, and `+0x14` entry count.
- 2026-06-04 live IDA still reports the larger helper starts at `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` as raw/non-function starts; only `0x004c64b0` and `0x004c64c0` are modeled as exact `0x4`-byte accessors.
- 2026-06-17 B002 PE-aware scan found no external rel32/Jcc edges, short-branch hits, VA pointers, or RVA pointers to the lifecycle/helper/accessor starts or into `0x004c62d0-0x004c64f0`; the only pointer route in the neighborhood remains the vtable slot to the scalar deleting destructor.
- 2026-07-03 B009 MCP session `3a33af0b` reconfirmed `0x004c6160` as `sub_4C6160` size `0xf9` / 249, `0x004c6260` as `sub_4C6260` size `0x6e` / 110, `0x004c64b0` and `0x004c64c0` as exact `0x4`-byte accessors, and `0x004c64f0` as `sub_4C64F0` size `0xac` / 172. The raw helper starts and aggregate endpoints remain non-function starts.
- 2026-07-03 B009 `xrefs_to` found no direct xrefs to the constructor, ordinary destructor, raw helper starts, or count accessors. The scalar deleting destructor remains vtable-only via `0x0061aac4`, and the vtable base refs remain limited to constructor/destructor/scalar-wrapper sites `0x004c61a1`, `0x004c6288`, and `0x004c651f`.
- 2026-07-03 B009 byte checks reconfirmed constructor/destructor/helper/scalar-wrapper boundaries, `0xcc` padding `0x004c64e1-0x004c64f0`, and vtable bytes at `0x0061aac0`: RTTI pointer, `0x004c64f0`, `0x004f4b10`, and `0x0041b6c0`.
- 2026-07-03 B009 decompilation keeps the constructor and ordinary destructor source-ready: constructor initializes base/vtable, entry size, slot count, entry count, entry and slot-state buffers, zeroes slot state, and seeds four bytes; ordinary destructor frees/clears both buffers and chains to base cleanup. The scalar deleting destructor duplicates cleanup around delete-flag wrapper logic and should not be hand-authored as class source.

For source-complete reconstruction, this should remain a real utility class rather than being ignored as dead code. Its current status is "source-authored retained utility/legacy class with no confirmed live construction site."

## Resolved And Remaining Source-Quality Questions

- Liveness: active direct construction is not proven. B002 checked IDA xrefs plus PE rel32/Jcc/short-branch and VA/RVA pointer routes and found no surviving direct route, so the best current classification is retained utility/legacy code. Indirect construction remains possible but currently has no high-probability supporting evidence.
- Slot-state naming: the byte array is best documented as `slotStateBuffer` or occupied-slot state. Binary semantics are solved at this level: `0` means empty, nonzero means occupied, and `SetAt` writes `1` for a newly occupied slot.
- Hash naming: `ComputeHashIndex` is a descriptive high-probability helper name for the visible raw helper because it sums caller-provided key bytes and returns `sum % slotCount`. The four seed bytes are constructor-seeded state, but no checked helper in this island consumes them.
- Source placement: `util/CachedHashTable.cpp` remains the high-probability placement. Feature-local ownership is rejected because no feature callers, strings, resources, or feature state point at this class.
- C++ readiness: exact children such as [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) may emit draft C++; broad aggregate pages keep formal C++ blank until split/assembly avoids duplicate helper emission.
- Constructor/destructor readiness: the constructor at `0x004c6160-0x004c6259` and ordinary destructor at `0x004c6260-0x004c62ce` are source-ready in behavior and layout terms, but should be emitted through exact child pages or a coordinated `CachedHashTable` class/file assembly rather than the broad [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) aggregate.
- Raw helper/accessor duplication policy: [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md) remains a blank formal-C++ helper aggregate pending exact split or coordinated assembly, while [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) already emits the two accessor methods. Do not emit the same accessors again from UID00016O or UID00016P.
- Scalar deleting destructor policy: `0x004c64f0-0x004c659c` is compiler ABI wrapper output reached through the vtable slot. Document it for binary coverage but let source express `~CachedHashTable()` once.

## Cross-References

- File: [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- Layout: [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- Vtable: [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- Vtable data: [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md)
- Memory: [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md)
- Memory: [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md)
- Memory: [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md)
- Related: [UID:0001QA][client_containers](by-meta/client_containers.md), [UID:00007D][LObject](by-class/LObject.md)

## Complete Source And ABI Assembly

UID00001F is the direct semantic owner of every source method and every class-specific compiler consequence; [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md) remains the final file root. The CPP preamble above emits one ordered child anchor, and the H block owns the only class declaration. Exact definitions arrive in order from [UID:00050T][0x004c6160-0x004c6259.CachedHashTableConstructor](by-memory/0x004c6160-0x004c6259.CachedHashTableConstructor.md), [UID:00050U][0x004c6260-0x004c62ce.CachedHashTableDestructor](by-memory/0x004c6260-0x004c62ce.CachedHashTableDestructor.md), [UID:00050V][0x004c62d0-0x004c63c1.CachedHashTableComputeHashIndex](by-memory/0x004c62d0-0x004c63c1.CachedHashTableComputeHashIndex.md), [UID:00050W][0x004c63d0-0x004c63ee.CachedHashTableClear](by-memory/0x004c63d0-0x004c63ee.CachedHashTableClear.md), [UID:00050X][0x004c63f0-0x004c641e.CachedHashTableRemoveAt](by-memory/0x004c63f0-0x004c641e.CachedHashTableRemoveAt.md), [UID:00050Y][0x004c6420-0x004c6447.CachedHashTableGetAt](by-memory/0x004c6420-0x004c6447.CachedHashTableGetAt.md), [UID:00050Z][0x004c6450-0x004c64a7.CachedHashTableSetAt](by-memory/0x004c6450-0x004c64a7.CachedHashTableSetAt.md), [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md), and [UID:000510][0x004c64d0-0x004c64e1.CachedHashTableGetEntryAddressUnchecked](by-memory/0x004c64d0-0x004c64e1.CachedHashTableGetEntryAddressUnchecked.md). Their H channels remain blank to prevent duplicate declarations.

The exact live UDT is ordinal 1003, size 28, with `vftable +0x0 void **`, `m_entries +0x4 unsigned __int8 *`, `m_slotState +0x8 unsigned __int8 *`, `m_entrySize +0xc int`, `m_slotCount +0x10 int`, `m_entryCount +0x14 int`, and `m_hashSeed +0x18 unsigned __int8[4]`. Historical statements that no UDT or only raw accessor identities existed are dated superseded evidence; they are not current state.

[UID:000511][0x004c64f0-0x004c659c.CachedHashTableScalarDeletingDestructor](by-memory/0x004c64f0-0x004c659c.CachedHashTableScalarDeletingDestructor.md), unique constructor/destructor EH graphs, and the complete RTTI/vtable graph are compiler output from this declaration and ordinary method source. They remain fully documented but have no independent emitter. Shared scalar EH objects and the shared LObject base descriptor retain their external owners. Every internal alignment span remains ignored non-source data.

No visible method reads `m_hashSeed`, but the four constructor writes are exact and retained. No unsupported search/probe method is invented. The source also preserves absent validation, possible modulo-by-zero, integer overflow/wrap behavior, copy-before-occupancy semantics, and the observed base-only constructor unwind cleanup.

## Changes

- What existed before: the page documented layout, lifecycle methods, raw helpers, vtable evidence, and unresolved live construction.
- What it was changed to: the class is marked reconstructable, scores were raised to `82/84`, and exact vtable-data child range [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md) was added.
- Summary and evidence: object layout, constructor/destructor, scalar delete, helper island, vtable bytes, and no-caller caveat are covered; final helper names and whether this is legacy/indirectly constructed code remain unresolved.
- 2026-06-03: Corrected the scalar deleting destructor method row from `0x004c64f0-0x004c659b` to exclusive end `0x004c659c`, matching [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) and its written IDA boundary evidence.
- 2026-06-04: Raised scores from `82/84` to `86/88` and attached this reconstructable class to [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md). The increase is based on live IDA revalidation of half-open lifecycle boundaries, exact vtable slots and next-RTTI boundary, current no-caller xrefs, and raw helper field touchpoints. Final source C++ remains blank because helper names/signatures and live construction remain unresolved.
- 2026-06-17: B002 source-quality refresh corrected the helper island endpoint to `0x004c64e1`, added PE no-route evidence, closed the stale open-question list into evidence-bounded source-quality decisions, and preserved `util/CachedHashTable.cpp` as the high-probability source placement.
- 2026-06-21 B009 read-only-data source-routing support:
  - Score unchanged.
  - Summary/evidence: exact vtable-data child [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md) now includes the `0x0061aac0` RTTI locator that was previously stranded on the mixed [UID:00025F][0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData](by-memory/0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md) parent. B009 raw PE/static export checks confirm the pointed RTTI value is unique to that cell.
- 2026-07-03 B009 UID00016O source-quality callback:
  - Score unchanged.
  - Summary/evidence: class notes now record UID00016O as a reviewed non-emitting lifecycle/split-index aggregate. MCP session `3a33af0b` reconfirmed modeled starts/sizes, raw non-function starts, vtable-only scalar-wrapper route, no direct constructor/destructor/helper/accessor route, byte boundaries, and source-shaped constructor/destructor/accessor behavior. Constructor/destructor are source-ready for exact child pages or coordinated class/file assembly; scalar deleting destructor remains compiler no-code; raw helper/accessor overlap must not be duplicated.
- 2026-08-10 B005 UID00016Q callback:
  - Score and metadata remain `86/88`, owner/emitter [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md), and reconstructable true.
  - Added explicit non-virtual `int GetSlotCount() const` and `int GetEntryCount() const` rows, exact body/ABI and retained-utility evidence, synchronized source-facing member names, and the child-CPP/whole-class-H ownership boundary.
- 2026-08-14 B003 UID0000HZ whole-file callback: raised `86/88 -> 94/94`, installed the accepted CPP preamble and complete `CachedHashTable.h`, routed every exact source child through this class in binary order, and documented all EH/RTTI/vtable/scalar-wrapper consequences without hand-authoring compiler output.
