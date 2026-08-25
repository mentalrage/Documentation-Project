*** UID:00036N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted FolderTreePane primary/secondary/tertiary RTTI/vtable layout.
// Source reconstruction is routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
// class declarations and virtual method/destructor declarations; no raw vtable
// array is emitted from this type page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane Class Vtables

## Status

- Entity kind: primary, secondary, and tertiary `FolderTreePane` vtable views.
- Direct owner: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Source file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Exact data: [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md)
- Rebuild handling: `source-declared/generated-binary`; rebuild the `FolderTreePane` class declaration and inheritance layout, not hand-authored table bytes.
- Empty-emitter disposition: this page now emits only the formal comment marker above through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md). The marker is trace evidence for compiler-emitted layout, not permission to emit raw `DWORD` arrays, fixed addresses, adjustor thunk bodies, or scalar deleting destructor glue.

## Vtable Inventory

| View | RTTI locator | Vtable base | Slots | Key slots |
| --- | --- | --- | --- | --- |
| Primary `FolderTreePane` | `0x0061a514` -> `0x00647894` | `0x0061a518` | `+0x00-+0x6c` | `+0x00` -> `0x004b5a70`; `+0x48-+0x6c` are tree-control paint, scroll, mouse, key, and content helpers. |
| Secondary `+0xa0` view | `0x0061a588` -> `0x006478f4` | `0x0061a58c` | `+0x00-+0x28` | `+0x00` -> `0x004b59d5` adjustor thunk into `0x004b5a70`; remaining slots are inherited pane callbacks. |
| Tertiary `+0xa4` view | `0x0061a5b8` -> `0x00647908` | `0x0061a5bc` | `+0x00-+0x04` | `+0x00` -> `0x004b59e0` adjustor thunk into `0x004b5a70`; `+0x04` -> `0x00544e90`. |

The tertiary view stops at `0x0061a5c4`. Address `0x0061a5c4` starts the UTF-16 `TREEICON.EPF` resource name; its dwords are not virtual slots.

## Primary Slots

| Slot | Target | Current role |
| --- | --- | --- |
| `+0x00` | `0x004b5a70` | `FolderTreePane` scalar deleting destructor. |
| `+0x30` | `0x0055ee10` | Inherited scroll/pane virtual. |
| `+0x38` | `0x0055ef10` | Inherited scroll/pane virtual. |
| `+0x44` | `0x0055f190` | Inherited scroll/pane virtual. |
| `+0x48` | `0x004b2a80` | Content extent helper. |
| `+0x4c` | `0x004b2ab0` | Visible extent helper. |
| `+0x50` | `0x004b2af0` | Viewport size helper. |
| `+0x54` | `0x004b2b20` | Scroll value transform helper. |
| `+0x58` | `0x004b2b30` | Content dimensions helper. |
| `+0x5c` | `0x004b2b50` | Scroll delta computation. |
| `+0x60` | `0x004b2dc0` | Mouse event handler. |
| `+0x64` | `0x004b2b80` | Key event handler. |
| `+0x68` | `0x0041d6b0` | Inherited/default callback slot. |
| `+0x6c` | `0x004b2a00` | Paint visible tree rows. |

B001's 2026-06-28 scalar deleting destructor repair keeps the `+0x00` primary slot `0x004b5a70` represented through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)'s `virtual ~FolderTreePane();` declaration. The exact child [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md) is non-emitting metadata with blank `EMITTER_UIDS:` and blank formal C++; this vtable page should not imply a standalone destructor body, comment marker, or raw vtable array.

## 2026-06-11 IDA Evidence

- `py_eval` over `0x0061a4e8-0x0061a5c8` reads the primary/secondary/tertiary RTTI locator dwords at `0x0061a514`, `0x0061a588`, and `0x0061a5b8`, followed by vtable bases named `??_7FolderTreePane@@6B@`, `??_7FolderTreePane@@6B@_0`, and `??_7FolderTreePane@@6B@_1`.
- `xrefs_to 0x0061a518`, `0x0061a58c`, and `0x0061a5bc` reports constructor stores at `0x004b1bd5`, `0x004b1bdb`, and `0x004b1be5`, cleanup stores at `0x004b1cf4`, `0x004b1d00`, and `0x004b1d0a`, and destructor stores at `0x004b5a77`, `0x004b5a83`, and `0x004b5a8d`.
- `lookup_funcs` returns `0x004b5a70` as a `0x84`-byte scalar deleting destructor and `0x004b59d5` / `0x004b59e0` as `0x0b`-byte adjustor thunks.
- Disassembly of `0x004b5a70` restores the three `FolderTreePane` vtable views, resets embedded iterator/tree vtables at `this+0x170` and `this+0x130`, destroys the tree storage, tears down the base pane, and conditionally frees or guard-deletes the `0x17c`-sized pane.
- `xrefs_to 0x0061a5c4` reports `TREEICON.EPF` data references from the constructor/root-name setup paths at `0x004b1c51`, `0x004b1c89`, and `0x004b2618`, proving the table boundary.

## 2026-06-29 B006 MCP Evidence

Current acceptance evidence uses MCP session `86fb854e`. The historical `supervisor_20260628_resume` evidence remains corroborating lead material only.

- `idb_list` reported active adopted worker session `86fb854e` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:"ok"` and `lookup_funcs 0x00401000` returned `sub_401000`.
- `entity_query names 0x0061a4e0-0x0061a5d0` reconfirmed `0x0061a518 ??_7FolderTreePane@@6B@`, `0x0061a58c ??_7FolderTreePane@@6B@_0`, and `0x0061a5bc ??_7FolderTreePane@@6B@_1`.
- `get_int` reconfirmed the class-view dwords: RTTI locators `0x00647894`, `0x006478f4`, and `0x00647908`; vtable slot bases `0x004b5a70`, `0x004b59d5`, `0x004b59e0`; and final tertiary slot `0x00544e90`.
- `xrefs_to` reconfirmed constructor stores at `0x004b1bd5`, `0x004b1bdb`, `0x004b1be5`; cleanup stores at `0x004b1cf4`, `0x004b1d00`, `0x004b1d0a`; and destructor stores at `0x004b5a77`, `0x004b5a83`, `0x004b5a8d`.
- `disasm 0x004b59d5` and `0x004b59e0` reconfirmed the secondary and tertiary adjustor thunks into `sub_4B5A70`; `get_bytes 0x0061a5c4 size 24` decoded `TREEICON.EPF`, and `xrefs_to 0x0061a5c4` tied that successor string to constructor/root-name setup.

## Split Rationale

This page is the exact `FolderTreePane` class-owned subset split out of [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md). The aggregate also includes direct vtable owners for `Tree<FolderTreePane::TreeElem>` and `TreeItor<FolderTreePane::TreeElem>`, so this class page attaches to [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) instead of forcing the aggregate to one owner.

## 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 reanalysis keeps these vtables as source-declared/generated-binary class data owned by [UID:00005A][FolderTreePane](by-class/FolderTreePane.md). The class shell now records `FolderTreePane : public ScrollablePane`, size `0x17c`, primary view `+0x00`, secondary view `+0xa0`, tertiary view `+0xa4`, and `virtual ~FolderTreePane()`.

The exact data boundary remains `0x0061a514-0x0061a5c4`, with `0x0061a5c4` starting `TREEICON.EPF`. Any generated virtual entries decoded from the successor string must be rejected as string data, not class methods.

The 2026-06-29 B006 implementation closes this page's empty-emitter state with a comment-only marker. It keeps owner/reconstructable/emitter metadata unchanged and explicitly rejects a standalone raw vtable array, class declaration copy, destructor body, or adjustor thunk body on this type-layout page.

## Cross-References

- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md)
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md)
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md)
- [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md)

## Changes

- 2026-06-29 B006 empty-emitter implementation:
  - Score changed from `87/92` to `89/93`; owner, reconstructable state, and emitter route remain [UID:00005A][FolderTreePane](by-class/FolderTreePane.md).
  - Inserted the paired formal comment-only no-code marker and synchronized MCP session `86fb854e` evidence for class vtable names, in-range dwords, constructor/destructor xrefs, adjustor thunk disassembly, and the `TREEICON.EPF` boundary.
  - Preserved no-raw-array, no-standalone-destructor/thunk, and no false string-derived virtual-row policy for these compiler-emitted class vtable views.

- 2026-06-28 B001 [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md) support sync:
  - Score unchanged at `87/92`.
  - Added the accepted slot/source-route note: the primary `+0x00` slot points at [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md), but source representation is [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)'s virtual destructor declaration and the exact child is blank-emitter non-emitting metadata.

- 2026-06-11 A006 split from [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md):
  - What existed before: the `FolderTreePane` class views were intermixed with the local tree/template vtables in one blank-parent aggregate.
  - Changed to: exact direct-owner vtable page for the `FolderTreePane` class.
  - Summary/evidence: live IDA reconfirmed the three RTTI locators, primary/secondary/tertiary table slots, constructor/cleanup/destructor store triads, adjustor-thunk xrefs, scalar deleting destructor body shape, and `TREEICON.EPF` successor boundary.
