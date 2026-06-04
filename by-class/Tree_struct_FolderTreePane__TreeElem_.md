*** UID:0000F9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Tree_struct_FolderTreePane__TreeElem_

## Status

- Confidence: strong for helper responsibility, live vtable identity, reset/destructor boundaries, and `FolderTreePane` ownership; medium for original template/header spelling.
- Likely source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Address range: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- Vtable: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) at `0x0061a500`
- Parent attachment: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) has the current `NexusTK/ui/controls/` reconstruction path and owns the folder-tree template helpers.
- Reconstruction handling: attached to `FolderTreePane.cpp`; C++ remains blank until final template names, field names, and header factoring reach the final-source bar.

## Class Purpose

This is the current concrete label for `Tree<FolderTreePane::TreeElem>`, embedded inside [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) at offset `0x130`. It wraps [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), owns reset/destruction behavior, and keeps the root node alive.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| destructor cleanup fragment | `0x004b5650-0x004b5668` | Resets the tree vtable, destroys embedded storage, and jumps to `LObject` teardown. IDA associates this block with `FolderTreePane` constructor EH cleanup, so it is not a clean direct-called standalone function. |
| scalar-deleting destructor | `0x004b59f0-0x004b5a38` | Restores tree vtable, destroys embedded storage, tears down `LObject`, and optionally deletes. |
| `ResetToSingleRoot` | [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) | Destroys existing node names, rewinds storage, and creates one root record with link fields set to `-1`. |

## Evidence Notes

- 2026-06-04 live IDA MCP names the tree vtable at `0x0061a500` as `??_7?$Tree@UTreeElem@FolderTreePane@@@@6B@` and reads its first slots as `0x004b59f0`, `0x004f4b10`, and `0x0041b6c0`.
- Live xrefs to the tree vtable come from the `FolderTreePane` constructor/setup paths at `0x004b1bf7` and `0x004b1d1e`, the constructor cleanup fragment at `0x004b5656`, the tree scalar deleting destructor at `0x004b59f9`, and the outer `FolderTreePane` destructor at `0x004b5aa1`.
- Live IDA confirms `0x004b59f0-0x004b5a38` as a standalone scalar deleting destructor that resets the tree vtable, calls `TreeStorage<FolderTreePane::TreeElem>` destructor `0x004b56e0` on `this + 4`, tears down `LObject` through `0x004f4a90`, and conditionally deletes through `0x004f4ac0`.
- Live IDA confirms `0x004b5650` is still modeled as a `sub_4B1B90` constructor/EH chunk, with a sole code xref from the unwind thunk at `0x005fe944`; it is cleanup support for the embedded tree rather than a clean direct-called source method.
- Live IDA confirms `0x004b5b00-0x004b5bae` as the reset helper, with callers at `0x004b1c18`, `0x004b1c95`, and `0x004b262a`. Decompilation destroys existing record names at `record + 0x14`, rewinds storage, initializes a root record from `xmmword_619660` plus a fifth `-1`, and calls `0x004b3d50` or `0x004b55e0` depending on capacity.
- Boundary bytes around the tree-wrapper methods are alignment/padding: `0x004b564d-0x004b5650`, `0x004b59eb-0x004b59f0`, `0x004b5a38-0x004b5a40`, `0x004b5af4-0x004b5b00`, and `0x004b5bae-0x004b5bb0`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 84 | The page now records live vtable identity/slots/xrefs, destructor cleanup handling, scalar destructor behavior, reset helper child page, storage/type/template ownership, parent file placement, and reconstruction gating. |
| Confidence | 88 | Confidence is strong because live IDA ties the tree wrapper to `FolderTreePane` construction/destruction and the named `Tree<FolderTreePane::TreeElem>` vtable; final template spelling/header factoring and field names remain inferred. |
| Reconstructable | true | This is source-owned folder-tree template support, but final C++ remains blank below the 95/95 final-source threshold. |

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:000158][0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the embedded tree purpose, destructor cleanup, scalar deleting destructor, reset-to-root helper, FolderTreePane offsets, type/template/vtable links, and the cleanup-ownership caveat.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JG`.
  - Evidence: live IDA MCP confirmed the named tree vtable at `0x0061a500`, vtable slots and xrefs from `FolderTreePane` construction/destruction/cleanup, scalar deleting destructor range and storage/base teardown behavior, reset helper callers and root-record initialization, EH-only cleanup fragment xref, and padding around the helper methods.
  - Remaining limits: final C++ stays blank because exact original template spelling/header factoring and field names are still below the final-source bar.
