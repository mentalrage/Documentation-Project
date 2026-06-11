*** UID:0001X5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00001C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BulletinDialog Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:00001C][BulletinDialog](by-class/BulletinDialog.md).
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Exact vtable data: [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md).
- Confidence: strong for vtable bases and raw-constructor stores; medium for final source-level names of shared virtual slots.
- Autogen status: attached to the `BulletinDialog` class page; final C++ remains blank under the `95/95` reconstruction gate.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00613ba8` | `0x00472017` | `+0x00` | Primary `DialogInSession`/dialog view. |
| secondary | `0x00613c0c` | `0x0047201f` | `+0xa0` | Secondary command/action view. |
| tertiary | `0x00613c3c` | `0x00472029` | `+0xa4` | Small event/update-handler view. |

The raw constructor at [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md) is the only direct code xref to these three table bases in the current IDA database. IDA still does not model that constructor start as a function.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00613ba8` | `+0x00` | `0x0047ea10` | [UID:00001C][BulletinDialog](by-class/BulletinDialog.md). |
| primary `0x00613ba8` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x00613ba8` | `+0x48` | `0x0041b6c0` | Base no-op/default slot. |
| primary `0x00613ba8` | `+0x4c` | `0x0041b6a0` | Guard/no-op slot. |
| primary `0x00613ba8` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x00613ba8` | `+0x54` | `0x0049f2e0` | Inherited dialog border/background drawing virtual. |
| primary `0x00613ba8` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| primary `0x00613ba8` | `+0x5c` | `0x0041d6b0` | Shared default false/handled stub. |
| secondary `0x00613c0c` | `+0x00` | `0x0047e897` | Compiler adjustor thunk into `0x0047ea10` with `this - 0xa0`. |
| secondary `0x00613c0c` | `+0x10` | `0x00472040` | [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md). |
| tertiary `0x00613c3c` | `+0x00` | `0x0047e8a2` | Compiler adjustor thunk into `0x0047ea10` with `this - 0xa4`. |
| tertiary `0x00613c3c` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x60` as a `BulletinDialog` virtual: it is RTTI metadata for the secondary table. Secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` is RTTI for the following `BoardListDialog` table cluster.

## IDA MCP Evidence

- `list_globals *BulletinDialog*` reports vtables at `0x00613ba8`, `0x00613c0c`, and `0x00613c3c`, plus RTTI records at `0x006434e0`, `0x00643590`, `0x006435a4`, and `0x00674cd0`.
- 2026-05-31 IDA dword scan confirms exact RTTI/vtable data range [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). The previous dword at `0x00613ba0` belongs to the preceding table, and `0x00613c44` starts `BoardListDialog` RTTI.
- Raw constructor disassembly at `0x00472000-0x0047203a` calls `0x004a1400`, then stores the three table bases at `0x00472017`, `0x0047201f`, and `0x00472029`.
- `xrefs_to` the three table bases reports only those constructor stores.
- `lookup_funcs` confirms `0x0047e897`, `0x0047e8a2`, `0x0047ea10`, and `0x00472040` as modeled functions, while `0x00472000` remains `Not a function`.
- Current `class_BulletinDialog.meta_wave3` reports `vtable_count: 0` even though active source placeholders name `BulletinDialog_vtable`, `BulletinDialog_vtable2`, and `BulletinDialog_vtable3`.

## Reconstruction Notes

Model `BulletinDialog` as a `DialogInSession`-derived board dialog base with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. Keep the secondary and tertiary destructor adjustor thunks out of handwritten source; the reconstructed class layout should let the compiler regenerate equivalent thunks. Keep `0x00472040` as shared board-dialog virtual behavior rather than duplicating it into every subclass whose vtable points at the same target.

## Parent Rationale

Attach this vtable cluster to [UID:00001C][BulletinDialog](by-class/BulletinDialog.md) because the three tables are the base `BulletinDialog` virtual views installed by the raw constructor-shaped body at `0x00472000-0x0047203a` and consumed by the scalar deleting destructor, adjustor thunks, and shared command-one virtual. The class page is already reconstructable, attached to [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and records the same vtable bases, object offsets, exact vtable-data child, and unresolved constructor-function boundary. The vtable page remains the narrow evidence home for slot order and `.rdata` boundaries.

## Cross-References

- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md)
- [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage despite the owning class and file pages already clearing the attachment gate.
  - What changed: attached the vtable cluster to [UID:00001C][BulletinDialog](by-class/BulletinDialog.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: constructor stores at `0x00472017`, `0x0047201f`, and `0x00472029`, exact [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md), and the class page's `82/86` score support the parent assignment; confidence stays below final-audit level because `0x00472000` is still not modeled as a function and final virtual names remain provisional.

- 2026-05-31: Changed completion/confidence from `0/0` to `84/88` and marked the page reconstructable. Evidence: IDA MCP rechecked `list_globals`, `lookup_funcs`, vtable xrefs, raw constructor stores, and an exact dword scan; the exact vtable data child [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md) now records the range boundary and slot values.
