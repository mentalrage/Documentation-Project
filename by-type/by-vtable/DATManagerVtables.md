*** UID:0001XB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DAT Manager Vtables

## Status

- Disposition: reconstructable project vtable data
- Covered classes: [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) and [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- Likely source module: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Confidence: strong for table bases, short extents, and exact child ranges.
- Autogen status: attached to the `DATFileMgr` file page because this page covers the public/private manager pair; final C++ remains blank under the `95/95` reconstruction gate.

## Vtable Inventory

| Class | RTTI / pre-vtable word | Vtable base | Slots | Boundary note |
| --- | --- | --- | --- | --- |
| `DATFileMgr` | `0x00618910` -> `??_R4DATFileMgr@@6B@` | `0x00618914` | `0x00618914` -> `0x0049d350` | One-slot table. The next dword at `0x00618918` is `DATFileContainer` RTTI, not a `DATFileMgr` slot. |
| `_DATFileMgr` | `0x006189c8` -> `??_R4_DATFileMgr@@6B@` | `0x006189cc` | `0x006189cc` -> `0x0049d3d0` | One-slot table. The next dwords at `0x006189d0`/`0x006189d4` decode as adjacent UTF-16 `"../"` data, not `_DATFileMgr` slots. |

## Exact By-Memory Children

- [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md) documents the exact public-wrapper RTTI pointer and one-slot vtable.
- [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md) documents the exact internal-manager RTTI pointer and one-slot vtable.

## IDA Evidence

- `xrefs_to 0x00618914` reports constructor/destructor vtable stores at `0x0049bd81`, raw/cleanup store `0x0049be50`, and scalar destructor store `0x0049d359`.
- `xrefs_to 0x006189cc` reports inner-manager constructor store `0x0049bda1`, raw ordinary destructor store `0x0049c755`, and scalar deleting destructor store `0x0049d3dd`.
- `xrefs_to 0x0049d350` reports vtable/data reference `0x00618914`.
- `xrefs_to 0x0049d3d0` reports vtable/data reference `0x006189cc`.
- 2026-05-26 local `simroot_v2` metadata check: `class_DATFileMgr.meta_wave3` and `class__DATFileMgr.meta_wave3` both report `vtable_count: 0`.
- 2026-05-31 IDA MCP `list_globals` recheck reports `??_7DATFileMgr@@6B@` at `0x00618914`, `??_7_DATFileMgr@@6B@` at `0x006189cc`, and the corresponding RTTI records at `0x0064645c` and `0x006463cc`.
- 2026-05-31 IDA MCP dword scan shows the public manager range ends at `0x00618918` because that dword points to `??_R4DATFileContainer@@6B@`; the internal manager range ends at `0x006189d0` because that dword begins a UTF-16 `"../"` string referenced from `_DATFileMgr::LoadDATFileIndex`.

## Source Reconstruction Notes

Do not read past either single-slot vtable. `DATFileMgr` is immediately followed by `DATFileContainer` RTTI/vtable data, while `_DATFileMgr` is immediately followed by a string/data island before `DescPane` RTTI/vtable data. Any generated method rows past the first slot should be treated as vtable-boundary pollution unless independently confirmed by IDA.

## Parent Rationale

Attach this vtable inventory to [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), not to one individual class, because it covers both the public wrapper [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) and private implementation [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md). The file page is already reconstructable as the archive manager source root, owns both classes, and records the same exact vtable-data child ranges and non-slot boundary warnings. This page remains the narrow evidence home for the two one-slot vtables and their adjacent `.rdata` boundaries.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md)
- [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable inventory was reconstructable but unassigned in generated type coverage.
  - What changed: attached the inventory to [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), raised completion to `86`, and added an explicit file-level parent rationale.
  - Summary/evidence: exact [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md) and [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md) children plus the [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) file page's `89/84` score support a file-level attachment; final helper class naming and method rewrites remain below the final-code gate.

- 2026-05-31 exact child split:
  - What existed before: metadata was `0/0` with `RECONSTRUCTABLE` blank, and this page described the two one-slot vtables without exact by-memory child pages.
  - Changed to: scored `84/91`, marked reconstructable, and linked exact `0x00618910-0x00618918` and `0x006189c8-0x006189d0` by-memory vtable-data pages.
  - Summary/evidence: IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, and dword scan confirm the RTTI pointers, one-slot destructor targets, constructor/destructor vtable stores, and adjacent non-slot boundaries.
