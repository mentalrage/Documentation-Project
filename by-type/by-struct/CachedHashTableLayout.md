*** UID:0001TU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CachedHashTableLayout

## Status

- Entity kind: class layout support struct
- Confidence: strong for IDA-observed offsets/types and the selected source-facing field set; exact stripped lexical spelling remains inferred.
- Direct owner: [UID:00001F][CachedHashTable](by-class/CachedHashTable.md); final source root [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md).
- Evidence basis: live IDA MCP constructor/destructor/accessor checks and raw helper disassembly.
- Reconstructable: false as an independent emitter. This page is exact ABI/layout support; UID00001F's formal H owns the one real source declaration.

## Layout

```text
CachedHashTableLayout
  +0x00  LObject base
  +0x04  unsigned char* m_entries
  +0x08  unsigned char* m_slotState
  +0x0c  int m_entrySize
  +0x10  int m_slotCount
  +0x14  int m_entryCount
  +0x18  unsigned char m_hashSeed[4]
```

Observed object size is `0x1c` bytes.

## Allocation Rules

- Constructor allocates `m_entrySize * m_slotCount` bytes for `m_entries`.
- Constructor allocates `m_slotCount` bytes for `m_slotState`.
- Constructor zeroes each slot-state byte.
- Destructor frees both buffers through the shared memory manager and clears both pointers.
- Raw helper `0x004c63d0` clears `m_slotState` bytes and resets `m_entryCount`.
- Raw helper `0x004c6450` copies one fixed-size entry into `m_entries + m_entrySize * index`, marks the slot occupied when needed, and updates `m_entryCount`.
- Raw helpers `0x004c63f0`, `0x004c6420`, and `0x004c64d0` return entry addresses derived from the same `m_entries`/`m_entrySize` pair.
- IDA-modeled accessors [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) return `m_slotCount` and `m_entryCount`.
- 2026-05-31 IDA MCP recheck of `0x004c6160` confirms constructor writes `entrySize` at `+0x0c`, `slotCount` at `+0x10`, zeroes `entryCount` at `+0x14`, allocates `entrySize * slotCount` bytes into `+0x04`, allocates `slotCount` bytes into `+0x08`, clears the slot-state buffer, and writes four `rand()` bytes at `+0x18..+0x1b`.
- 2026-05-31 IDA MCP recheck of `0x004c6260` confirms destructor frees `+0x04` and `+0x08`, clears both pointers, and chains to the `LObject` cleanup path.
- 2026-05-31 raw IDA disassembly confirms helper `0x004c63d0` resets `+0x14` and clears every slot-state byte, helper `0x004c6450` copies `entrySize` bytes into `entriesBuffer + entrySize * index`, sets `slotStateBuffer[index] = 1`, and increments `entryCount` only on first occupation.
- 2026-05-31 raw IDA disassembly confirms accessors `0x004c64b0` and `0x004c64c0` return `+0x10` and `+0x14`, respectively.
- 2026-06-04 live IDA MCP reconfirms constructor/destructor half-open boundaries `0x004c6160-0x004c6259` and `0x004c6260-0x004c62ce`; constructor tail writes the four seed bytes through `+0x1b`, and destructor clears buffer pointers at `+0x04` and `+0x08`.
- 2026-06-04 live IDA raw helper disassembly reconfirms `0x004c63d0` clears `+0x14` and the byte array at `+0x08`, `0x004c63f0` clears a slot and decrements `+0x14`, `0x004c6420` checks the slot-state byte before returning an entry address, `0x004c6450` copies `+0x0c` bytes and marks new slots occupied, and `0x004c64d0` computes `+0x04 + +0x0c * index`.
- 2026-06-04 live IDA confirms the two modeled accessors remain exact `0x4`-byte functions: `0x004c64b0-0x004c64b4` returns `+0x10`, and `0x004c64c0-0x004c64c4` returns `+0x14`.

## Naming And Reachability Notes

`m_slotState` is the selected source-facing name for the parallel byte array; current evidence proves `0` means empty and non-zero means occupied. The four `m_hashSeed` bytes are low-byte results of `rand()`; the currently documented raw hash-index helper sums caller-provided key bytes and divides by `m_slotCount`, but no caller has shown whether the seed bytes participate in a higher-level probe/key path.

The selected source field set is `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]`. It follows the established member style and distinguishes storage, slot state, capacity, and occupancy without preserving decompiler offsets. Original lexical proof is unavailable, but constructor/destructor/helper/accessor behavior makes these the highest-probability human names. The raw helper island still has no modeled function starts and no xrefs, so exact child pages or a coordinated class/file assembly should own final method emission.

Historical descriptive aliases `entriesBuffer`, `slotStateBuffer`, `entrySize`, `slotCount`, `entryCount`, `hashSeed0`, `hashSeed1`, `hashSeed2`, and `hashSeed3` are retained in dated evidence where they record how the layout was first understood. They are superseded as current source spelling, not deleted as incorrect behavioral evidence.

## Resolved Field And Split Directions

- Field naming: use `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]` as the source-facing layout. The binary semantics and types for all offsets are solved; only unrecoverable original lexical spelling remains uncertain.
- Slot-state semantics: `0` is empty, nonzero is occupied, and raw `SetAt` writes `1` on first occupation.
- Seed fields: preserve four one-byte `hashSeed` fields. The visible `ComputeHashIndex` helper does not consume them, so any seed-based probing hypothesis remains unproven.
- Raw helper split: the corrected aggregate range is `0x004c62d0-0x004c64e1`. Exact source emission should split or assemble helper bodies so padding and [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) are not duplicated.

## Current IDA Type Status

- Fresh canonical `type_query`, `type_inspect`, and `search_structs` checks find no local `CachedHashTable` UDT. The `LObject` name exists only as an opaque/non-layout declaration.
- The missing analysis UDT does not make the field layout unresolved: constructor `0x004c6160`, destructor `0x004c6260`, raw helper reads/writes, exact count accessors, RTTI, and total allocation size all agree on the `0x1c` layout above.
- Supervisor Gate 2B may add a flattened analysis UDT with exact declaration `struct CachedHashTable { void **vftable; unsigned char *m_entries; unsigned char *m_slotState; int m_entrySize; int m_slotCount; int m_entryCount; unsigned char m_hashSeed[4]; };`. This analysis type preserves all offsets and does not replace the final source inheritance declaration.
- The earlier 2026-06-16 function-rename record below is historical. Fresh canonical readback shows the accessors as `sub_4C64B0` / `sub_4C64C0` with raw `_DWORD *this` types and no comments; any new UDT, rename, type, or comment application remains supervisor-owned.

## 2026-06-16 Source-Quality Refresh

Live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed the current layout and reachability limits:

- `0x004c6160` is a modeled `0xf9`-byte constructor. Decompilation writes entry size at `+0x0c`, slot count at `+0x10`, clears entry count at `+0x14`, allocates `entrySize * slotCount` into `+0x04`, allocates `slotCount` bytes into `+0x08`, zeroes every slot-state byte, and writes four `rand()` low bytes at `+0x18..+0x1b`.
- `0x004c6260` is a modeled `0x6e`-byte ordinary destructor. Decompilation restores the class vtable, frees `+0x04` and `+0x08` through the memory manager, clears both pointers, and chains to the `LObject` cleanup path.
- Raw starts `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` remain `Not a function`, with zero xrefs to the raw starts. Disassembly still shows the hash-index helper, clear, remove, checked-entry, set/copy, and unchecked-entry address routines touching only the documented offsets.
- `0x004c64b0` and `0x004c64c0` remain exact `0x4`-byte IDA functions returning `this[4]` / slot count and `this[5]` / entry count.
- `0x004c64f0` is a modeled scalar deleting destructor referenced only from vtable slot `0x0061aac4`; the vtable base has refs from constructor/destructor/scalar-deleting destructor sites `0x004c61a1`, `0x004c6288`, and `0x004c651f`.
- No direct code or data xrefs exist to the constructor, ordinary destructor, raw helper starts, or count accessors. This keeps active-runtime use unresolved while preserving source-complete utility ownership.

IDA database source-quality edits made from this evidence: `sub_4C6160` -> `CachedHashTable_Constructor`, `sub_4C6260` -> `CachedHashTable_Destructor`, `sub_4C64B0` -> `CachedHashTable_GetSlotCount`, `sub_4C64C0` -> `CachedHashTable_GetEntryCount`, and `sub_4C64F0` -> `CachedHashTable_ScalarDeletingDestructor`. No raw helper functions or field/member types were created because caller recovery and function-boundary evidence remain insufficient.

## Cross-References

- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md)
- [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md)
- [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Current UDT And No-Code Disposition

Live IDA now contains exact `CachedHashTable` UDT ordinal 1003, size 28, with seven members: `vftable +0x0 void **`, `m_entries +0x4 unsigned __int8 *`, `m_slotState +0x8 unsigned __int8 *`, `m_entrySize +0xc int`, `m_slotCount +0x10 int`, `m_entryCount +0x14 int`, and `m_hashSeed +0x18 unsigned __int8[4]`. Constructor, destructor, all helper children, both count accessors, RTTI, and the vtable independently agree.

This duplicate structural representation does not emit a separate struct/class, CPP body, or H fragment. [UID:00001F][CachedHashTable](by-class/CachedHashTable.md) now supplies the complete LObject-derived declaration and `sizeof(CachedHashTable) == 0x1c` assertion. Historical absent-UDT and true/empty-emitter statements remain progression evidence only.

## Changes

- 2026-08-14 B003 UID0000HZ callback: changed `85/90 -> 94/94`, direct owner from UID0000HZ to UID00001F, reconstructable true to false, and emitter to blank after installing the complete declaration once in UID00001F H; added the current exact UDT ordinal/member proof and retained older absent-UDT/true-emitter wording only as history.

- What existed before: the page had a documented 28-byte layout but needed current live evidence and report alignment.
- What changed: evidence basis now foregrounds live IDA MCP constructor/destructor/helper checks, and the page is marked reconstructable as layout documentation.
- Summary/evidence: IDA MCP rechecked `0x004c6160`, `0x004c6260`, raw helper disassembly at `0x004c63d0-0x004c64df`, and the count accessors at `0x004c64b0/0x004c64c0`.
- 2026-06-04: Raised scores from `74/86` to `82/90` and attached the layout to [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md). The increase is justified by live IDA verification of every documented field offset through constructor, destructor, clear/remove/get/set/accessor helpers, plus exact `0x4`-byte accessor bodies. Completion remains below final-source level because field names are still provisional and the original class declaration is not proven.
- 2026-06-16 C001 source-quality refresh:
  - Before: `82/90`.
  - After: `85/90`.
  - Summary/evidence: live IDA MCP reconfirmed constructor/destructor/accessor boundaries, raw helper no-function/no-xref status, vtable-only lifecycle refs, and absence of live construction callers. IDA function names were updated for the modeled lifecycle/accessor/deleting-destructor functions. Completion now clears the gate because the page records the current source-quality investigation and exact unresolved blockers; confidence stays at `90` because live use, raw helper splitting, and final field names remain open.
- 2026-06-17: B002 source-quality evidence corrected the raw helper aggregate endpoint to `0x004c64e1`, added PE no-route evidence, and converted field/split open questions into descriptive-name and exact-split directions.
- 2026-08-10 B005 UID00016Q callback:
  - Kept metadata `85/90`, owner/emitter [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md), and reconstructable true.
  - Synchronized current names/types to `m_entries`, `m_slotState`, `m_entrySize`, `m_slotCount`, `m_entryCount`, and `m_hashSeed[4]`; retained earlier buffer/individual-seed spellings only as historical descriptive aliases.
  - Recorded the current absence of a local `CachedHashTable` UDT and the exact flattened analysis-UDT handoff without claiming that IDA was modified.
