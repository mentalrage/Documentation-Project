*** UID:0001X6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00001F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CachedHashTable Vtable

## Status

- Entity kind: primary `CachedHashTable` vtable.
- Vtable base: `0x0061aac4`.
- RTTI pointer: `0x0061aac0 -> 0x00647de8` (`??_R4CachedHashTable@@6B@`).
- Exact vtable-data range: [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md).
- Confidence: strong for table base, slot boundaries, constructor/destructor/scalar-deleting-destructor refs, and the boundary before `SimpleHelpTextPartPane`.
- Owning class: [UID:00001F][CachedHashTable](by-class/CachedHashTable.md).
- Source owner: [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md).
- Autogen status: attached to the `CachedHashTable` class page; final C++ remains blank under the `95/95` reconstruction gate.

## Slots

| Slot | Address | Current interpretation | Notes |
| --- | --- | --- | --- |
| `+0x00` | `0x004c64f0` | `CachedHashTable::ScalarDeletingDestructor` | Destructor body and optional object free. |
| `+0x04` | `0x004f4b10` | inherited `LObject` runtime-class/name accessor | Shared with the `LObject` base shell. |
| `+0x08` | `0x0041b6c0` | inherited/default no-op virtual | Tiny default callback body; returns after consuming two stack args. |

The next RTTI pointer at `0x0061aad0` belongs to `HelpPane::SimpleHelpTextPartPane`, so the `CachedHashTable` table should stop after the three slots above.

## Evidence

- IDA MCP `xrefs_to 0x0061aac4` reports constructor/destructor vptr stores at `0x004c61a1`, `0x004c6288`, and `0x004c651f`.
- IDA MCP `xrefs_to 0x004c64f0` reports the vtable data reference at `0x0061aac4`.
- A raw `.rdata` dump around `0x0061aac0` shows the `CachedHashTable` RTTI pointer, three function slots, then the next class RTTI pointer.
- Current `class_CachedHashTable.meta_wave3` reports `vtable_count: 0`, so this page is the reconstruction anchor for the table until generated metadata is corrected.
- 2026-05-26 IDA MCP recheck models `0x004c64b0` and `0x004c64c0` as real count accessor functions, but they are ordinary methods, not vtable slots.
- 2026-05-31 IDA MCP `lookup_funcs` confirms constructor `0x004c6160` size `0xf9`, ordinary destructor `0x004c6260` size `0x6e`, scalar deleting destructor `0x004c64f0` size `0xac`, inherited slot `0x004f4b10` size `0x6`, and no-op slot `0x0041b6c0` size `0x3`.
- 2026-05-31 IDA MCP `py_eval` confirms the exact vtable-data child range [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md): `0x0061aac0` is `CachedHashTable` RTTI, `0x0061aac4-0x0061aacc` are the three slots, and `0x0061aad0` is the next `SimpleHelpTextPartPane` RTTI pointer.

## Parent Rationale

Attach this vtable type to [UID:00001F][CachedHashTable](by-class/CachedHashTable.md) because it is the primary virtual surface for that class and its first slot is the class scalar deleting destructor. The class page is already reconstructable, attached to [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md), and documents the same `0x0061aac4` table, lifecycle method boundaries, helper island, and unresolved no-caller caveat. Keeping this page class-attached lets generated type coverage reflect the source-level owner while preserving the vtable page as the narrow slot/boundary evidence home.

## Cross-References

- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md)
- [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md)
- [UID:00016P][0x004c62d0-0x004c64de.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md)
- [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable page was reconstructable but unassigned in generated type coverage even though its owning class and file pages were already documented.
  - What changed: attached the vtable to [UID:00001F][CachedHashTable](by-class/CachedHashTable.md), raised completion to `84`, and added an explicit parent rationale.
  - Summary/evidence: IDA-confirmed constructor/destructor vptr stores, the `0x004c64f0` scalar-deleting-destructor slot, and the exact [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md) child range tie the table to the class; confidence stays below final-audit level because live construction and helper names remain unresolved.

- What existed before: the page identified the `CachedHashTable` vtable and boundary but remained scored `0/0` and had no exact by-memory child page for the vtable bytes.
- What it was changed to: the page is marked reconstructable, scored `82/90`, and linked to the exact [UID:0002M7][0x0061aac4-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md) child range.
- Summary and evidence: 2026-05-31 IDA MCP `lookup_funcs` and `py_eval` checks confirmed the slot targets, constructor/destructor/scalar-deleting-destructor refs, and the boundary before `SimpleHelpTextPartPane` RTTI/vtable data. Live construction remains unresolved, so this is not a final-source `95+` item.
