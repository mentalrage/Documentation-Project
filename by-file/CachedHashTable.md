*** UID:0000HZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CachedHashTable

## Status

- Proposed module: `util/CachedHashTable.cpp`
- Proposed header: `util/CachedHashTable.h`
- Confidence: strong for source-replication ownership and utility-file placement; active runtime use remains unresolved after IDA and PE route checks.
- Primary class: [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- Primary vtable: [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)

## File Role

`CachedHashTable.cpp` is the likely source for a small fixed-entry hash table/cache helper. The recovered class allocates one fixed-size entry buffer, one parallel slot-state byte buffer, records entry size and slot count, and seeds four per-instance hash bytes with `rand()`.

Current IDA xref checks, a 2026-06-17 PE-aware route scan, and B009's 2026-07-03 MCP session `3a33af0b` found no direct constructor/destructor/helper callers or pointer-table route. Treat this as a recovered source-authored utility/legacy class that may be indirectly constructed through unmodeled code, but currently has no high-probability active construction evidence.

## Likely Contents

- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md)
- constructor at `0x004c6160-0x004c6259`
- ordinary destructor at `0x004c6260-0x004c62ce`
- helper island at `0x004c62d0-0x004c64e1`, including modeled count accessors at `0x004c64b0` and `0x004c64c0`
- scalar deleting destructor at `0x004c64f0-0x004c659c`

[UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) is a reviewed non-emitting lifecycle/split-index aggregate for this inventory. It covers the constructor, ordinary destructor, [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md), already-emitting accessor child [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md), padding, and compiler scalar-deleting destructor wrapper. Constructor/destructor source emission should use exact child pages or a coordinated class/file assembly; do not emit aggregate C++ from UID00016O.

## Evidence

- 2026-06-04 live IDA MCP reports modeled lifecycle boundaries: constructor `0x004c6160-0x004c6259` size `0xf9`, ordinary destructor `0x004c6260-0x004c62ce` size `0x6e`, and scalar deleting destructor `0x004c64f0-0x004c659c` size `0xac`.
- 2026-06-04 live IDA raw disassembly confirmed a class-local helper island ending at the `retn 4` instruction starting `0x004c64de`; B002 later corrected the formal half-open interval to `0x004c62d0-0x004c64e1`. The island covers hash-index calculation, clear, slot removal, checked slot access, fixed-entry copy/update, two count accessors, and unchecked entry addressing.
- 2026-06-04 live IDA reports the larger helper starts `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` are still raw/non-function starts, while `0x004c64b0` and `0x004c64c0` are exact `0x4`-byte functions returning fields `+0x10` and `+0x14`.
- 2026-06-04 live IDA xref checks report no direct code or data references to the constructor, ordinary destructor, raw helper starts, or count accessors. The scalar deleting destructor is referenced only from vtable slot `0x0061aac4`.
- 2026-06-04 live IDA confirms vtable data at `0x0061aac0`: RTTI `??_R4CachedHashTable@@6B@`, slot `0x0061aac4 -> 0x004c64f0`, slot `0x0061aac8 -> 0x004f4b10`, slot `0x0061aacc -> 0x0041b6c0`, followed by `SimpleHelpTextPartPane` RTTI at `0x0061aad0`.
- 2026-06-04 live IDA `DataRefsTo(0x0061aac4)` returns only `0x004c61a1`, `0x004c6288`, and `0x004c651f`, matching constructor/destructor/scalar-deleting-destructor vtable stores or reads and preserving the unresolved live-construction caveat.
- 2026-06-17 B002 corrected the helper island endpoint to `0x004c64e1` and found no external PE rel32/Jcc edges, short-branch hits, VA pointers, or RVA pointers to the lifecycle/helper/accessor starts or into `0x004c62d0-0x004c64f0`.
- 2026-07-03 B009 MCP session `3a33af0b` reconfirmed `0x004c6160` as a modeled `0xf9` / 249-byte constructor, `0x004c6260` as a modeled `0x6e` / 110-byte ordinary destructor, `0x004c64b0` and `0x004c64c0` as exact `0x4`-byte count accessors, and `0x004c64f0` as a modeled `0xac` / 172-byte scalar deleting destructor. The larger raw helper starts and aggregate endpoints are not function starts.
- 2026-07-03 B009 `xrefs_to` found no xrefs to the constructor, ordinary destructor, raw helper starts, or accessors; `0x004c64f0` is reached only from vtable slot `0x0061aac4`, whose refs remain the constructor/destructor/scalar-wrapper sites `0x004c61a1`, `0x004c6288`, and `0x004c651f`.
- 2026-07-03 B009 byte checks reconfirmed constructor tail `c2 08 00` at `0x004c6256`, ordinary destructor tail `c3` at `0x004c62cd`, raw unchecked helper tail through `0x004c64e0`, `0xcc` padding `0x004c64e1-0x004c64f0`, scalar deleting destructor tail through `0x004c659b`, and vtable bytes at `0x0061aac0` containing the RTTI pointer, `0x004c64f0`, `0x004f4b10`, and `0x0041b6c0`.
- 2026-07-03 B009 decompile/disassembly evidence keeps the constructor and ordinary destructor source-shaped, keeps [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) as the exact accessor emitter, and rejects UID00016O aggregate C++ because it would duplicate the accessor child, mix raw helpers/padding, or hand-author compiler scalar-deleting destructor mechanics.

## Source-Structure Decision

Use `util/CachedHashTable.cpp` as the high-probability source module. Its behavior is generic storage/cache infrastructure and should not be assigned to UI, map, archive, or another feature module without caller evidence.

For full binary replication, keep this class and its helper island in the source tree even though active caller evidence is absent. The no-caller result only lowers runtime priority; it does not make the code disposable, because the constructor/destructor, vtable, RTTI, and raw helper bodies are all present in the binary.

Do not merge it into [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) or [UID:0000IR][Deque](by-file/Deque.md). Those helpers have active caller evidence and different layouts.

## UID00016Q Accessor Evidence

[UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) supplies two source-ready non-virtual methods for this file:

| Range | Exact body | Source method | ABI and behavior |
| --- | --- | --- | --- |
| `[0x004c64b0,0x004c64b4)` | `8B 41 10 C3` | `int CachedHashTable::GetSlotCount() const` | Leaf `__thiscall`; ECX receiver; no explicit stack arguments, locals, saved registers, callees, or side effects; returns `m_slotCount` at `+0x10` in EAX. |
| `[0x004c64c0,0x004c64c4)` | `8B 41 14 C3` | `int CachedHashTable::GetEntryCount() const` | Leaf `__thiscall`; ECX receiver; no explicit stack arguments, locals, saved registers, callees, or side effects; returns `m_entryCount` at `+0x14` in EAX. |

- Each physical stack frame contains only `__return_address` at `+0x0`, size `0x4`, type `_UNKNOWN *`. The source-level trailing `const` changes no calling-convention, register, stack, byte, control-flow, or runtime property.
- Constructor `0x004c6160` proves the complete field sequence used by these methods: `m_entries` `+0x04`, `m_slotState` `+0x08`, `m_entrySize` `+0x0c`, `m_slotCount` `+0x10`, `m_entryCount` `+0x14`, and `m_hashSeed[4]` `+0x18`, for total size `0x1c`.
- RTTI names `??_R4CachedHashTable@@6B@` and `??_R0?AVCachedHashTable@@@8` identify the class. Vtable `0x0061aac4` routes only the scalar deleting destructor among class-specific methods, proving the two getters are non-virtual.
- Current live IDA has zero incoming xrefs and no VA/RVA pointer route to either accessor; the prior PE-aware scan also found no external rel32/Jcc, short-branch, VA, or RVA route. Their short body patterns are nonunique, so identity depends on the constructor layout, RTTI, vtable adjacency, and helper-island context rather than opcode shape alone.
- The strongest liveness conclusion is retained utility/legacy API with no surviving direct route. That bounded negative result does not remove these source-authored methods from `CachedHashTable.cpp`.
- `GetSlotCount` and `GetEntryCount` are the selected source names; generic `GetCapacity`/`GetCount` alternatives are less precise. The selected source fields use the established project member style: `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed`.
- Fresh canonical readback still presents raw `sub_4C64B0` / `sub_4C64C0` names, `int __thiscall(_DWORD *this)` types, absent function/address comments, and no local `CachedHashTable` UDT. Those are supervisor Gate 2B analysis improvements, not reasons to retain raw labels in reconstructed source.
- Source placement remains `NexusTK/util/CachedHashTable.cpp` through this page. The exact child owns the two CPP definitions; their declarations belong to the complete class header, so the child H channel remains blank.

## Source-Quality Resolution

- Liveness: no direct IDA xrefs or PE rel32/Jcc/VA/RVA route currently reaches the constructor, raw helpers, or count accessors. This supports a retained utility/legacy classification; it does not justify deleting the source-authored class.
- Helper names: `ComputeHashIndex`, `Clear`, `RemoveAt`, `GetAt`, `SetAt`, `GetSlotCount`, `GetEntryCount`, and `GetEntryAddressUnchecked` are descriptive names inferred from current behavior and layout. Original-name proof is unavailable, but the inferred names are strong enough for documentation and draft child C++ where exact ranges are safe.
- Historical field aliases: `entriesBuffer`, `slotStateBuffer`, `entrySize`, `slotCount`, `entryCount`, and four hash seed bytes were useful descriptive layout names. Slot-state semantics were solved as empty/occupied at the binary level; the following bullet records the selected source-facing spelling.
- Current source-facing field names are `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]`. Older `entriesBuffer`/`slotStateBuffer` wording remains useful historical description of storage roles, but it is not the selected final spelling.
- C++ emission: exact child pages now emit every accepted method definition through UID00001F's single class/file assembly. This broad file page, helper/lifecycle aggregates, layout/vtable support, vtable data, padding, EH objects, and scalar wrapper remain blank so no source or compiler output is duplicated.
- Lifecycle aggregate policy: [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) is source-routing documentation, not a source-emitting unit. It should stay blank-emitter/blank-C++ while constructor/destructor source moves through exact children or coordinated `CachedHashTable.cpp` assembly.
- Scalar deleting destructor policy: document `0x004c64f0-0x004c659c` as compiler ABI wrapper output. The source model should express the ordinary destructor once and let the compiler produce deleting-destructor machinery.

## Cross-References

- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md)
- [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md)
- [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md)
- [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000KV][LObject](by-file/LObject.md)

## Whole-File Implementation Closure

The complete retained utility/legacy compilation unit is now reconstructed through direct class owner [UID:00001F][CachedHashTable](by-class/CachedHashTable.md). This by-file page remains the `NexusTK/util/CachedHashTable.cpp` and required `CachedHashTable.h` root; it intentionally owns no formal source channel itself. UID00001F supplies the include preamble, one `[[CHILDREN]]` anchor, and the complete header declaration. Exact by-memory children supply only their own method definitions in source order:

| Position | Child | Binary identity | Source/no-code disposition |
| ---: | --- | --- | --- |
| 1 | [UID:00050T][0x004c6160-0x004c6259.CachedHashTableConstructor](by-memory/0x004c6160-0x004c6259.CachedHashTableConstructor.md) | `[0x004c6160,0x004c6259)`, SHA256 `47560B2B32152BF6068A71D261247B8A5F5F6EFC79FC6F8BD6D103AFDB0E4782` | exact constructor CPP; unique cleanup/handler/UnwindMap/FuncInfo remain compiler consequences |
| 2 | [UID:00050U][0x004c6260-0x004c62ce.CachedHashTableDestructor](by-memory/0x004c6260-0x004c62ce.CachedHashTableDestructor.md) | `[0x004c6260,0x004c62ce)`, SHA256 `CE8B55AF39B5269E62D6330FCDC05CA1AA3D1F3D3209CFFAEFFC1F00124FD57D` | exact ordinary destructor CPP; unique handler/FuncInfo remain compiler consequences |
| 3 | [UID:00050V][0x004c62d0-0x004c63c1.CachedHashTableComputeHashIndex](by-memory/0x004c62d0-0x004c63c1.CachedHashTableComputeHashIndex.md) | `[0x004c62d0,0x004c63c1)`, SHA256 `3C9121ECF63C1A59D13441E092A70A9FB6296029C9299282BA16C3C9D8AA2F9E` | ordinary unsigned byte loop/modulo CPP; SSE/unrolling is compiler optimization |
| 4 | [UID:00050W][0x004c63d0-0x004c63ee.CachedHashTableClear](by-memory/0x004c63d0-0x004c63ee.CachedHashTableClear.md) | `[0x004c63d0,0x004c63ee)`, SHA256 `255D0F1BEE6AA38E4E35960E5EBB64C579BE4FF13DC5E93A8ACA821A3AAFE495` | exact Clear CPP |
| 5 | [UID:00050X][0x004c63f0-0x004c641e.CachedHashTableRemoveAt](by-memory/0x004c63f0-0x004c641e.CachedHashTableRemoveAt.md) | `[0x004c63f0,0x004c641e)`, SHA256 `AA8040A98E8E9D0FF6AC1423149F115FB8022F08B167DCBA7EAB40822299892A` | exact RemoveAt CPP; retained entry bytes are not erased |
| 6 | [UID:00050Y][0x004c6420-0x004c6447.CachedHashTableGetAt](by-memory/0x004c6420-0x004c6447.CachedHashTableGetAt.md) | `[0x004c6420,0x004c6447)`, SHA256 `111C5E9BCF6B8F855519F06F53B6BD06C82568E25503295156A36267A9C6F5DC` | exact checked GetAt CPP |
| 7 | [UID:00050Z][0x004c6450-0x004c64a7.CachedHashTableSetAt](by-memory/0x004c6450-0x004c64a7.CachedHashTableSetAt.md) | `[0x004c6450,0x004c64a7)`, SHA256 `D7107969194FDA78A8576DB358FA6D8F464D8A14000826AF1040EE7D8451F463` | exact copy-before-occupancy SetAt CPP |
| 8 | [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) | exact four-byte field accessors | existing exact GetSlotCount/GetEntryCount CPP once each |
| 9 | [UID:000510][0x004c64d0-0x004c64e1.CachedHashTableGetEntryAddressUnchecked](by-memory/0x004c64d0-0x004c64e1.CachedHashTableGetEntryAddressUnchecked.md) | `[0x004c64d0,0x004c64e1)`, SHA256 `96700E84B110A62D68D586A11AE707C894526DA505DE3D35AFA7693651C4F310` | exact private unchecked-address CPP |
| compiler | [UID:000511][0x004c64f0-0x004c659c.CachedHashTableScalarDeletingDestructor](by-memory/0x004c64f0-0x004c659c.CachedHashTableScalarDeletingDestructor.md) | `[0x004c64f0,0x004c659c)`, SHA256 `F12CF55D9DA70CE69F42AA544937A23360C093AD11A0FC56B755778AE9C64F91` | false/non-emitting MSVC wrapper generated from the virtual ordinary destructor |

Every internal gap is exact zero-xref `0xcc` compiler/linker fill and is recorded in [UID:0000VN][-ignored](by-memory/-ignored.md): `[0x4c6259,0x4c6260)`, `[0x4c62ce,0x4c62d0)`, `[0x4c63c1,0x4c63d0)`, `[0x4c63ee,0x4c63f0)`, `[0x4c641e,0x4c6420)`, `[0x4c6447,0x4c6450)`, `[0x4c64a7,0x4c64b0)`, `[0x4c64c4,0x4c64d0)`, `[0x4c64e1,0x4c64f0)`, and `[0x4c659c,0x4c65a0)`. No child absorbs or emits padding.

The exact `0x1c` UDT, source-facing fields, ordinary methods, LObject inheritance, and MemoryMan dependencies are complete. The unique constructor/destructor EH objects remain attached to their methods. The scalar wrapper's 84-ref handler, 131-ref terminate thunk, shared UnwindMap, and nine-ref FuncInfo remain shared compiler objects. [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md) and [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md) preserve the class-specific COL, CHD, base array, CachedHashTable BCD, type descriptor, locator cell, and three-slot vtable; the 481-ref LObject BCD remains externally owned.

The implementation deliberately preserves unchecked multiplication, possible modulo-by-zero, 32-bit arithmetic wraparound, null/invalid-pointer behavior, copy-before-occupancy ordering, retained removed-entry bytes, and constructor partial-allocation behavior. Exhaustive names/xref/string/resource/source-neighborhood searches found no authored CachedHashTable global, file-static object, string, resource, import wrapper, initializer, free function, template instantiation, or additional data island. The no-direct-route result therefore remains a retained-legacy/liveness caveat, not an excuse to omit this complete source object.

Historical statements that exact children, the local UDT, accessor analysis, or final source assembly were still absent describe prior snapshots. The current ordinary documentation state is the exact split and class-owned CPP/H route above.

## Changes

- 2026-05-30/2026-05-31: Grading changed from `0/0` to `72/80`, and the validator reconstruction path was assigned to `NexusTK/util/`.
  - Before: page documented the standalone utility class, lifecycle methods, vtable, raw helper island, and no-caller result but remained unevaluated and had no projected path.
  - After: score reflects strong source-replication evidence for the class and helper island, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `CachedHashTable.cpp` under `util/`.
  - Evidence: IDA checks confirm lifecycle method starts, exact primary vtable child range, count accessors, raw helper island, and no direct callers; linked memory/type pages cover the layout and helper ranges.
- 2026-06-03: Corrected the scalar deleting destructor inventory endpoint from `0x004c659b` to exclusive end `0x004c659c`, matching [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) and the written IDA evidence that the final `retn 4` consumes bytes through `0x004c659b`.
- 2026-06-04: Raised scores from `72/80` to `84/88` after live IDA MCP revalidated all lifecycle boundaries, corrected the constructor/destructor/helper intervals to half-open ranges, reconfirmed the exact vtable slots and `0x0061aad0` boundary, and proved the no-caller caveat with current xref checks. Completion remains below final-audit level because helper names, public signatures, and live construction are still unresolved.
- 2026-06-17: Raised scores from `84/88` to `85/89` after B002 corrected the helper island endpoint to `0x004c64e1`, added PE-aware no-route evidence, and converted stale migration questions into evidence-bounded source-quality decisions.
- 2026-06-21 B009 read-only-data source-routing support:
  - Score unchanged.
  - Summary/evidence: updated the exact vtable-data child path/range to [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md), including the `CachedHashTable` RTTI locator that was previously documented only as a parent-boundary dword.
- 2026-07-03 B009 UID00016O source-quality callback:
  - Score unchanged.
  - Summary/evidence: [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) is now recorded as a reviewed non-emitting lifecycle/split-index aggregate. MCP session `3a33af0b` reconfirmed modeled starts/sizes, raw non-function starts, vtable-only scalar-wrapper route, no direct constructor/destructor/helper/accessor route, byte boundaries, and source-shaped constructor/destructor/accessor behavior. Constructor/destructor source emission should be exact child or coordinated class/file assembly, not aggregate UID00016O C++.
- 2026-08-10 B005 UID00016Q callback: added the exact accessor bodies, leaf ABI and frame contracts, constructor/RTTI/vtable class proof, exhaustive no-route and nonunique-pattern results, selected source names/types, current raw IDA prestate, retained-utility classification, and unchanged `NexusTK/util/CachedHashTable.cpp` route. File metadata remains `85/89`.
- 2026-08-14 B003 UID0000HZ whole-file callback: raised `85/89 -> 94/94`, created and routed nine exact source/compiler children, closed every internal padding span, installed the class-owned CPP/H assembly, preserved unique/shared EH and complete RTTI/vtable evidence, removed false support emitters, and closed the negative authored-global inventory. Exact original lexical spellings and historical liveness remain the score caps.
