*** UID:0001XC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DescPane Vtables

## Status

- Disposition: reconstructable project vtable data
- Owner class: [UID:00003Q][DescPane](by-class/DescPane.md)
- Likely source module: [UID:0000IS][DescPane](by-file/DescPane.md)
- Exact vtable-data page: [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)
- Confidence: strong for table bases, slot boundaries, and constructor/destructor stores.
- Autogen status: attached to the `DescPane` class page; final C++ remains blank under the `95/95` reconstruction gate.

## Vtable Inventory

| View | RTTI / pre-vtable word | Vtable base | Slot range | Notes |
| --- | --- | --- | --- | --- |
| primary `DescPane` view | `0x006189d8` -> `??_R4DescPane@@6B@` | `0x006189dc` | `0x006189dc-0x00618a24` | 18 slots. Slot 0 is scalar deleting destructor `0x0049d840`; slot `0x00618a20` is `RefreshDescription` at `0x0049d7c0`. |
| secondary view at object `+0xa0` | `0x00618a24` -> `??_R4DescPane@@6B@_0` | `0x00618a28` | `0x00618a28-0x00618a54` | 11 slots. Slot 0 is destructor adjustor thunk `0x0049d81e`. |
| tertiary view at object `+0xa4` | `0x00618a54` -> `??_R4DescPane@@6B@_1` | `0x00618a58` | `0x00618a58-0x00618a60` | 2 slots. Slot 0 is destructor adjustor thunk `0x0049d829`; slot 1 is inherited helper `0x00544e90`. |

The next dword after the tertiary table is `0x006465cc`, `DialogPane` RTTI. Do not read past `0x00618a60` as `DescPane` slots.

## IDA Evidence

- `xrefs_to 0x006189dc` reports vtable stores at raw constructor offset `0x0049d701`, non-deleting destructor offset `0x0049d740`, and scalar deleting destructor offset `0x0049d846`.
- `xrefs_to 0x00618a28` reports stores at raw constructor offset `0x0049d709`, non-deleting destructor offset `0x0049d746`, and scalar deleting destructor offset `0x0049d84c`.
- `xrefs_to 0x00618a58` reports stores at raw constructor offset `0x0049d713`, non-deleting destructor offset `0x0049d750`, and scalar deleting destructor offset `0x0049d856`.
- `xrefs_to 0x0049d7c0` reports the primary-vtable slot at `0x00618a20`.
- `xrefs_to 0x0049d81e` and `xrefs_to 0x0049d829` report secondary and tertiary vtable refs at `0x00618a28` and `0x00618a58`.
- Current `source-3/simroot_v2/class_DescPane.meta_wave3` reports `vtable_count: 0` despite these IDA-confirmed vtables.

## Slot Notes

Primary slots between `0x006189e0` and `0x00618a1c` are inherited `Pane`/UI-control behavior. `DescPane`'s class-specific override in this table is the description refresh slot at `0x00618a20`, reached indirectly by the raw source/index update helper at `0x0049d780`.

The secondary and tertiary tables are inherited-base views used for destructor dispatch. Their first slots are compiler-generated adjustor thunks; those code ranges are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md) because they are not handwritten description-pane behavior.

## Source Reconstruction Notes

Use these vtable bases when reconstructing the constructor, non-deleting destructor, and scalar deleting destructor. The raw constructor at `0x0049d6f0` installs all three tables, but IDA currently does not model that start as a function.

## Parent Rationale

Attach this vtable cluster to [UID:00003Q][DescPane](by-class/DescPane.md) because the three tables are the concrete `DescPane` virtual views installed by the raw constructor-shaped block and restored by the non-deleting and scalar deleting destructor paths. The class page is already reconstructable, attached to [UID:0000IS][DescPane](by-file/DescPane.md), and records the same singleton ownership, constructor/destructor stores, refresh slot, adjustor thunks, exact vtable-data child, and raw helper caveats. The vtable page remains the narrow evidence home for slot order and `.rdata` boundaries.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md)
- [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md)
- [UID:00012N][0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md)
- [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md)
- [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md)
- [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage despite the owning class and source file pages already clearing the attachment gate.
  - What changed: attached the vtable cluster to [UID:00003Q][DescPane](by-class/DescPane.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: constructor/destructor stores to `0x006189dc`, `0x00618a28`, and `0x00618a58`, exact [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md), and the class page's `84/86` score support the parent assignment; provider-interface naming and raw non-function starts remain below final-audit level.

- 2026-05-31 exact child split:
  - What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, blank reconstructability metadata, and described the vtable bases without an exact `by-memory` child page.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, and the exact [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md) child page.
  - Summary/evidence: 2026-05-31 IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, and dword reads reconfirm the three vtable bases, constructor/destructor store xrefs, key slot targets, modeled/raw function split, and boundary before `DialogPane` RTTI at `0x00618a60`; score remains below `95+` because provider-interface naming and raw constructor/setter ownership still need broader final-source audit.
