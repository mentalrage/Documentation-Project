*** UID:00006V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemObjectPane

## Status

- Confidence: strong for role and anchors.
- Likely source file: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_ItemObjectPane.cpp`
- Current Wave3 grade: `95.9`
- Current Wave3 coverage: 6 modeled methods, zero missing target refs.

## Class Purpose

`ItemObjectPane` represents a static item object on the map. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), stores the item graphic/variant fields, centers item glyph bounds in a map tile, and dispatches item-image rendering.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00537b40-0x00537b91` | Builds the `ObjectPane` base for an item object and stores item graphic/flag state. |
| `BuildCenteredItemRect` | `0x00537bf0-0x00537c65` | Gets item glyph bounds and centers them in the tile dimensions. |
| `ProcessItemAction` | `0x00537c70-0x00537ca2` | Delegates drawing/action handling to the item image library. |
| scalar deleting destructor | `0x0053d2e0-0x0053d377` | Restores vtables, tears down `ObjectPane`, and frees the object when requested. |

## Evidence Notes

- `MapPane::CreateOrUpdateObjectPane` at `0x00505e00` constructs `ItemObjectPane` for decoded item object state.
- `FlyingObjectPane` is a close companion for temporary thrown/flying item behavior and likely belongs in the same source module.

## Cross-References

- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: static map item-object role, constructor, centered glyph bounds, action/render delegation, destructor, MapPane creation anchor, and companion FlyingObjectPane relationship are documented with strong confidence; remaining work is field naming and final C++ body reconstruction. Evidence: `ItemAndFlyingObjectPanes`, `FlyingObjectPane`, `ObjectPane`, and MapPane constructor caller note.
