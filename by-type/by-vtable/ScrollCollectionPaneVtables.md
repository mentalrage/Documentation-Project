*** UID:0001YP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000CG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollCollectionPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- Likely source file: [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), or final merge into [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Confidence: strong for vtable bases and installed slots.
- Autogen parent: [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md); final C++ stays blank because the page documents compiler-emitted vtable layout rather than a source declaration ready for emission.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x00623fa4` | `0x00561e01` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00623ff0` | `0x00561e07` | Owns input/paint-style virtual slots for the pane data view. |
| tertiary `+0xa4` | `0x00624020` | `0x00561e11` | Owns update/effect callback-style virtual slots. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00623fa4` | `+0x44` | `0x005621f0` | Draw scrollbar / paint body. |
| secondary `0x00623ff0` | `+0x04` | `0x00561fb0` | Mouse/input handler. |
| secondary `0x00623ff0` | `+0x08` | `0x005621a0` | Boolean false-return virtual. |
| secondary `0x00623ff0` | `+0x34` | `0x005621b0` | Update/effect callback. |
| tertiary `0x00624020` | `+0x04` | `0x005621b0` | Same update callback through the tertiary view. |

## Parent And Slot Rationale

[UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) is now the type parent because it is reconstructable, scored `82/80`, and already attached to [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md). The class page records the same three constructor-installed vtable views, the `+0x00`/`+0xa0`/`+0xa4` subobject offsets, and the method map that gives source-facing roles to the notable slots above.

This vtable page should not emit standalone C++. The required rebuild effect is the `ScrollCollectionPane` class declaration and virtual method ordering; exact source declarations should come from the class/file pages once the broader scrollbar-family split is final.

## IDA MCP Evidence

- Constructor disassembly at `0x00561e01`, `0x00561e07`, and `0x00561e11` installs `0x00623fa4`, `0x00623ff0`, and `0x00624020`.
- `xrefs_to` each vtable base reports the constructor store as the direct data reference.
- The secondary and tertiary tables mirror the sibling [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md), but with `ScrollCollectionPane` method addresses.

## Reconstruction Notes

The same `+0x00`, `+0xa0`, `+0xa4` pane view pattern appears throughout the UI pane hierarchy. Do not model these vtables as standalone source logic; they prove class layout and virtual dispatch surfaces.

## Cross-References

- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md)
- [UID:0001GT][0x00561db0-0x0056325b.ScrollCollectionPane](by-memory/0x00561db0-0x0056325b.ScrollCollectionPane.md)
- [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md)
- [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `70/86` and marked reconstructable.
  - Before: The page had detailed vtable base/slot notes but was ungraded and not marked in validator metadata.
  - After: The page records a conservative completion score with strong confidence for the verified vtable bases and direct constructor xrefs; `RECONSTRUCTABLE` is `TRUE` because the class declarations must reproduce these compiler-emitted vtables.
  - Evidence: IDA MCP `xrefs_to` on `0x00623fa4`, `0x00623ff0`, and `0x00624020` confirms constructor stores at `0x00561e01`, `0x00561e07`, and `0x00561e11`.
- 2026-06-07: Raised completion from `70` to `74` and attached autogen parent [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md); confidence remains `86`.
  - Before: The page documented the vtable bases and slots but left `AUTOGEN_PARENT_UID` blank, so the type page was not connected to the already-parented class.
  - After: The page records the class parent, parent/slot rationale, and no-code policy for this compiler-emitted layout evidence.
  - Evidence: [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) is reconstructable at `82/80`, attached to [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), and records the same constructor stores, subobject offsets, method map, raw-helper caveats, and final `ScrollBar` merge caveat.
