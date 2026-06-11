*** UID:00006V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemObjectPane

## Status

- Confidence: strong for source placement, method anchors, vtable ownership, and pool-backed destruction.
- Direct source file: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- Assignment gate: this class is `85/88` and the direct file parent is `85/86`, so `AUTOGEN_PARENT_UID` points to `0000KG`.
- Final C++ remains blank because field names, helper names, and final source-level declarations are still below the 95/95 source gate.

## Class Purpose

`ItemObjectPane` represents a static item object on the map. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), stores the item graphic/variant fields, centers item glyph bounds in a map tile, and dispatches item-image rendering.

It is the ground-item half of the item-object source module documented by [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md). The paired [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) class covers temporary thrown/flying item behavior, while this class owns the static map item constructor, item glyph centering, item-image action dispatch, `ItemObjectPane` vtable family, and item pool-backed scalar deleting destructor.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00537b40-0x00537b91` | Builds the `ObjectPane` base for an item object and stores item graphic/flag state. |
| `BuildCenteredItemRect` | `0x00537bf0-0x00537c65` | Gets item glyph bounds and centers them in the tile dimensions. |
| `ProcessItemAction` | `0x00537c70-0x00537ca2` | Delegates drawing/action handling to the item image library. |
| scalar deleting destructor | `0x0053d2e0-0x0053d377` | Restores vtables, tears down `ObjectPane`, and frees the object when requested. |

## Evidence Notes

- `MapPane::CreateOrUpdateObjectPane` at `0x00505e00` constructs `ItemObjectPane` for decoded item object state.
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) records the contiguous item/flying executable cluster, including the ground item constructor and helper starts, MapPane caller evidence, item-image/tile callees, and the padding boundary before `AttachedObjectPane`.
- [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) records the exact RTTI pointer and three `ItemObjectPane` vtable views at `0x006203f0`, `0x00620460`, and `0x00620490`.
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) records the exact `0x0053d2e0-0x0053d377` scalar deleting destructor, object-pane cleanup call, adjusted vtable references, and `byte_69B9AC` pool-free gate.
- [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md) records the 0x28-byte static `PoolAllocator` storage, block size `300`, chunk count `8`, startup/cleanup wrappers, and direct allocation/free xrefs.
- `FlyingObjectPane` is a close companion for temporary thrown/flying item behavior and belongs in the same source module, but its constructor, animation methods, vtable data, and pool storage stay documented on the flying class and exact memory pages.

## Cross-References

- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md)
- [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: static map item-object role, constructor, centered glyph bounds, action/render delegation, destructor, MapPane creation anchor, and companion FlyingObjectPane relationship are documented with strong confidence; remaining work is field naming and final C++ body reconstruction. Evidence: `ItemAndFlyingObjectPanes`, `FlyingObjectPane`, `ObjectPane`, and MapPane constructor caller note.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the static item-object map pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x00537b40`, `0x00537bf0`, `0x00537c70`, and `0x0053d2e0`, with constructor caller `0x00505e8f` in the MapPane object-creation path.
- 2026-06-10 A002 strict-gate refresh:
  - Before: `74/86`, `AUTOGEN_PARENT_UID` blank, and the status still depended on generated-source provenance.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000KG`, final C++ still blank.
  - Summary/evidence: the file parent [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) is now `85/86`; the class page now records exact executable child evidence, the exact `ItemObjectPane` vtable-data child [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md), destructor-island support for `0x0053d2e0-0x0053d377`, and pool-static-storage evidence for `0x0069b9ac-0x0069b9d4`. This clears the corrected child/direct-parent `85/85` gate while keeping code emission gated by unresolved field/helper names.
