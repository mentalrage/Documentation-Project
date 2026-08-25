*** UID:00036L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:200 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted TreeItor<FolderTreePane::TreeElem> RTTI/vtable layout.
// Recreated by the TreeItor<T> virtual destructor declaration in Tree.h; no
// raw vtable array or standalone source definition is emitted from this page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane TreeItor Vtable

## Current Accepted UID0004YK Compiler Data Disposition

The concrete TreeItor<FolderTreePane::TreeElem> vtable and RTTI preserve the exact TreeItor spelling and one destructor slot. They are compiler-generated from the reusable Tree.h declaration, not manually authored source data.

## Status

- Entity kind: concrete `TreeItor<FolderTreePane::TreeElem>` vtable.
- Direct owner: [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md)
- Source context: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) local tree/template support, summarized by [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- Exact data: [UID:00036M][0x0061a50c-0x0061a514.FolderTreeIteratorVtableData](by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md)
- Rebuild handling: `source-declared/generated-binary`; model the iterator declaration and destructor so the compiler regenerates the table.

## Layout

| Address | Slot | Target | Evidence |
| --- | --- | --- | --- |
| `0x0061a50c` | RTTI locator | `0x00647968` | Live IDA dword inventory on 2026-06-11 shows this dword immediately before the iterator vtable base. |
| `0x0061a510` | `+0x00` | `0x004b5a40` | `TreeItor<FolderTreePane::TreeElem>` scalar deleting destructor. |

The next dword at `0x0061a514` is the RTTI locator for the primary `FolderTreePane` vtable, not an iterator slot.

## 2026-06-11 IDA Evidence

- `py_eval` over the read-only-data island reads `0x0061a50c -> 0x00647968`, then IDA names `0x0061a510` as `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`.
- `lookup_funcs 0x004b5a40` returns a `0x24`-byte scalar deleting destructor. Disassembly restores the iterator vtable at `this+0x00` and conditionally frees the `0x0c`-sized iterator object.
- `xrefs_to 0x0061a510` reports constructor/setup stores, traversal helper stores, cleanup-helper stores at `0x004b5670`, `0x004b57f0`, `0x004b5800`, and `0x004b5807`, paint/helper stores, the iterator scalar deleting destructor at `0x004b5a4a`, and the outer `FolderTreePane` scalar deleting destructor at `0x004b5a97`.
- The iterator table is local project template support because its stores are tied to `FolderTreePane` construction, traversal callbacks, selection/path helpers, cleanup thunks, and destruction.

## Split Rationale

The aggregate [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) cannot attach to a single class without mixing this iterator vtable with `Tree<FolderTreePane::TreeElem>` and `FolderTreePane` itself. This page carries the direct iterator-class ownership.

## 2026-06-19 B014 Source-Declared Vtable Policy

B014 source-quality reanalysis confirms this one-slot table is not handwritten source data. It should be regenerated from [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md), which now carries the first-draft `TreeItor<T>` declaration and virtual destructor. The adjacent [UID:00036M][0x0061a50c-0x0061a514.FolderTreeIteratorVtableData](by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md) page remains exact data evidence only; do not emit a raw vtable array unless later project-wide policy explicitly requires binary data emission.

## Cross-References

- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:00036M][0x0061a50c-0x0061a514.FolderTreeIteratorVtableData](by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md)

## Changes

- 2026-06-19 B014 TreeItor support sync:
  - Score unchanged at `86/92`.
  - Summary/evidence: B014 tied this exact iterator vtable to the new [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) `TreeItor<T>` class-level C++ declaration. The vtable remains source-declared/generated-binary support, not a raw emitted array.

- 2026-06-11 A006 split from [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md):
  - What existed before: the iterator vtable was only one row inside a mixed vtable aggregate with a blank parent.
  - Changed to: exact direct-owner vtable page for `TreeItor<FolderTreePane::TreeElem>`.
  - Summary/evidence: live IDA reconfirmed the RTTI locator, one-slot table, scalar deleting destructor size/body shape, broad local iterator/table-store xref set, and the next-table boundary at `0x0061a514`.
