*** UID:00036J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:190 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted Tree<FolderTreePane::TreeElem> RTTI/vtable layout.
// Source reconstruction is routed through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md); no raw vtable array is emitted from this type page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane Tree Vtable

## Current Accepted UID0004YK Compiler Data Disposition

The concrete Tree<FolderTreePane::TreeElem> vtable and RTTI prove public LObject inheritance and the virtual destructor shape used by reusable Tree.h. They are compiler-owned data generated from those declarations, not source arrays. The protected source contract is the inline virtual destructor and LObject base, with no manual vtable emission.

## Status

- Entity kind: concrete `Tree<FolderTreePane::TreeElem>` vtable.
- Direct owner: [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md)
- Generic source context: [UID:0004YK][Tree](by-file/Tree.md) `Tree.h`; FolderTreePane is the concrete instantiation/evidence context.
- Exact data: [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md)
- Rebuild handling: `source-declared/generated-binary`; model the concrete tree wrapper declaration so MSVC regenerates the table.

## Layout

| Address | Slot | Target | Evidence |
| --- | --- | --- | --- |
| `0x0061a4fc` | RTTI locator | `0x0064791c` | Live IDA byte/dword inventory on 2026-06-11 shows this dword immediately before the tree vtable base. |
| `0x0061a500` | `+0x00` | `0x004b59f0` | `Tree<FolderTreePane::TreeElem>` scalar deleting destructor. |
| `0x0061a504` | `+0x04` | `0x004f4b10` | Inherited/runtime class virtual slot from the local `LObject`-style wrapper. |
| `0x0061a508` | `+0x08` | `0x0041b6c0` | Inherited no-op/null virtual slot. |

## Historical Binary Evidence Under Superseded TreeStorage Labels

- `py_eval` over `0x0061a4e8-0x0061a5c8` reads `0x0061a4fc -> 0x0064791c`, then IDA names `0x0061a500` as `??_7?$Tree@UTreeElem@FolderTreePane@@@@6B@`.
- `xrefs_to 0x0061a500` reports stores from `FolderTreePane` construction/setup at `0x004b1bf7` and `0x004b1d1e`, constructor cleanup at `0x004b5656`, the tree scalar deleting destructor at `0x004b59f9`, and the outer `FolderTreePane` scalar deleting destructor at `0x004b5aa1`.
- `lookup_funcs 0x004b59f0` returns a `0x48`-byte function. Disassembly restores this tree vtable, calls the concrete direct-vector destructor instance at `0x004b56e0`, calls `LObject` teardown, then conditionally frees or guard-deletes the object.
- The next dword at `0x0061a50c` is the RTTI locator for the `TreeItor<FolderTreePane::TreeElem>` vtable, so this exact table stops before `0x0061a50c`.

## Historical Superseded 2026-06-28 B001 Empty-Emitter Disposition

This page is the vtable-layout evidence page for [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md), not a raw emitted vtable array. The accepted disposition keeps owner/emitter [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md), raises the page to `88/93`, and inserts the paired formal no-code marker so generated output records the source route without hand-porting compiler RTTI/vtable bytes.

The current MCP recheck confirmed the same `Tree<FolderTreePane::TreeElem>` table shape: RTTI locator `0x0064791c` at `0x0061a4fc`, slots `0x004b59f0`, `0x004f4b10`, and `0x0041b6c0`, predecessor `X:\` literal boundary, successor `TreeItor` RTTI boundary, five `0x0061a500` refs from constructor/cleanup/destructor paths, and a `0x48`-byte tree scalar deleting destructor that restores this table before storage/base teardown. Raw vtable array C++, non-reconstructable classification, and untraced blank-emitter routing are rejected.

## Split Rationale

The older aggregate [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) groups three direct owners: this tree wrapper, the iterator wrapper, and the `FolderTreePane` pane class. This exact page carries the `Tree<FolderTreePane::TreeElem>` direct-owner attachment instead of forcing the aggregate to one parent.

## Cross-References

- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md)

## Changes

- 2026-06-28 B001 empty-emitter implementation:
  - What existed before: the page was `86/92` with owner/emitter [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) and blank formal C++, leaving a paired blank nonblank emitter with [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md).
  - Changed to: `88/93`, owner/emitter/reconstructable unchanged, and the paired formal comment-only no-code marker inserted.
  - Summary/evidence: B001's current MCP pass reconfirmed the `Tree<FolderTreePane::TreeElem>` RTTI/vtable layout, xrefs, boundaries, and scalar deleting destructor behavior. This page remains layout evidence routed through [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md), not a raw array emitter.

- 2026-06-11 A006 split from [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md):
  - What existed before: the tree vtable was only one row inside a mixed vtable aggregate with a blank parent.
  - Changed to: exact direct-owner vtable page for `Tree<FolderTreePane::TreeElem>`.
  - Summary/evidence: live IDA reconfirmed the RTTI locator, three vtable slots, five table-store xrefs, scalar deleting destructor size/body shape, and the next-table boundary at `0x0061a50c`.
