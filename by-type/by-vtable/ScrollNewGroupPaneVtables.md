*** UID:0001YR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollNewGroupPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- Exact by-memory child: [UID:0002OS][0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData](by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md)
- Likely source file: [UID:0000JS][Group](by-file/Group.md), with possible later split to a shared scrollbar source.
- Confidence: strong for vtable bases and installed slots.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x00623f1c` | `0x00560951` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00623f68` | `0x00560957` | Owns mouse/paint-style virtual slots for the pane data view. |
| tertiary `+0xa4` | `0x00623f98` | `0x00560961` | Owns update/effect callback-style virtual slots. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| secondary `0x00623f68` | `+0x04` | `0x00560b00` | `OnMouseEvent`. |
| secondary `0x00623f68` | `+0x08` | `0x00560cf0` | `CanResize` / false-return virtual. |
| secondary `0x00623f68` | `+0x34` | `0x00560d00` | Selection/effect update callback. |
| tertiary `0x00623f98` | `+0x04` | `0x00560d00` | Same update callback exposed through the tertiary view. |

The primary table inherits many normal pane slots. The active scrollbar behavior is mostly reached through direct helper calls from the virtual methods above rather than all helpers appearing as vtable slots.

## IDA MCP Evidence

- Constructor disassembly at `0x00560951`, `0x00560957`, and `0x00560961` installs `0x00623f1c`, `0x00623f68`, and `0x00623f98`.
- `xrefs_to` each vtable base shows the constructor as the direct data ref.
- The secondary table includes direct slots for the confirmed `ScrollNewGroupPane` methods at `0x00560b00`, `0x00560cf0`, and `0x00560d00`.
- Boundary check on 2026-06-01: `0x00623f18` is the RTTI-adjacent word before the primary `ScrollNewGroupPane` table, `0x00623f64` and `0x00623f94` are the secondary/tertiary RTTI-adjacent words, and `0x00623fa0` is the next RTTI-adjacent word before `ScrollCollectionPane`.

## Reconstruction Notes

Model the class with the same pane multiple-inheritance pattern seen elsewhere in the client: primary object at `+0x00`, secondary pane-data view at `+0xa0`, and tertiary effect/update view at `+0xa4`.

## Cross-References

- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0002OS][0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData](by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md)
- [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md)
- [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md)
- [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md)
- [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md)

## Changes

- Previous: the page tracked vtable bases and slot targets but had no exact by-memory vtable-data child and still carried `0/0` validator scores.
- Changed to: exact child range [UID:0002OS][0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData](by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md) added, reconstruction flag set true, and scores raised conservatively below final-audit level.
- Evidence: IDA MCP confirms constructor stores for all three vtable bases, slot targets for the secondary/tertiary views, and neighboring `ScrollSpellInventoryPane`/`ScrollCollectionPane` boundaries.
