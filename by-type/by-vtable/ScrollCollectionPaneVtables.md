*** UID:0001YP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
