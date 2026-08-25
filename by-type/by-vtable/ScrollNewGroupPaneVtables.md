*** UID:0001YR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001YR] no standalone C++ body.
// ScrollNewGroupPane vtable clusters are compiler-emitted data; source coverage belongs to the class declaration and virtual method pages.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollNewGroupPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- Exact by-memory child: [UID:0002OS][0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData](by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md)
- Likely source file: [UID:0000JS][Group](by-file/Group.md), with possible later split to a shared scrollbar source.
- Rebuild handling: `source-declared/generated-binary`; rebuild through the class declaration and virtual methods, not literal vtable arrays.
- Autogen parent: [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md).
- Confidence: strong for vtable bases and installed slots.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md). This vtable page now clears the child-side gate at `85/91`, and the direct class parent clears the parent-side gate at `85/86`.

The direct parent is the class page rather than [UID:0000JS][Group](by-file/Group.md) because all three vtable views are `ScrollNewGroupPane` class views. The class page then routes to the Group source file.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x00623f1c` | `0x00560951` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00623f68` | `0x00560957` | Owns mouse/paint-style virtual slots for the pane data view. |
| tertiary `+0xa4` | `0x00623f98` | `0x00560961` | Owns update/effect callback-style virtual slots. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| secondary `0x00623f68` | `+0x04` | `0x00560b00` | `HandleMouseEvent` with formal first-draft C++. |
| secondary `0x00623f68` | `+0x08` | `0x00560cf0` | `CanScroll` / false-return virtual. |
| secondary `0x00623f68` | `+0x34` | `0x00560d00` | `OnScrollTimer` repeat/update callback. |
| tertiary `0x00623f98` | `+0x04` | `0x00560d00` | Same `OnScrollTimer` callback exposed through the tertiary view. |

The primary table inherits many normal pane slots. The active scrollbar behavior is mostly reached through direct helper calls from the virtual methods above rather than all helpers appearing as vtable slots.

## IDA MCP Evidence

- 2026-06-11 A002 live IDA MCP `py_eval` reconfirmed modeled method bounds for constructor `0x00560900-0x005609a1`, `HandleMouseEvent` `0x00560b00-0x00560ce1`, `CanScroll` `0x00560cf0-0x00560cf5`, `OnScrollTimer` `0x00560d00-0x00560d33`, `OnPaint` `0x00560d40-0x00561420`, `HitTestPart` `0x00561420-0x0056173d`, `GetPartRect` `0x00561740-0x005619c7`, interaction update `0x00561b00-0x00561bc0`, and cursor-to-scroll callback `0x00561bc0-0x00561d4d`. B002's 2026-06-30 implementation keeps the current child names and rejects the stale `CanResize` / `OnSelectionChanged` wording.
- The same pass read the relevant vtable dwords: `0x00623f1c -> 0x00421480`, `0x00623f60 -> 0x00560d40`, `0x00623f68 -> 0x004213f8`, `0x00623f6c -> 0x00560b00`, `0x00623f70 -> 0x00560cf0`, `0x00623f98 -> 0x00421403`, `0x00623f9c -> 0x00560d00`, and `0x00623fa0 -> 0x0064fa94` as the next `ScrollCollectionPane` RTTI-adjacent boundary.
- 2026-06-11 xrefs reconfirmed constructor stores at `0x00560951`, `0x00560957`, and `0x00560961`, and slot data references at `0x00623f60`, `0x00623f6c`, `0x00623f70`, and `0x00623f9c`.
- 2026-06-11 owner-path evidence reconfirmed `NewGroupPane` calls the constructor at `0x0056caae` and `Show` at `0x0056cac3`, while the scrollbar cursor-to-position path calls `NewGroupPane::SetScrollPosition` at `0x00561d35 -> 0x0056df00`.
- Constructor disassembly at `0x00560951`, `0x00560957`, and `0x00560961` installs `0x00623f1c`, `0x00623f68`, and `0x00623f98`.
- `xrefs_to` each vtable base shows the constructor as the direct data ref.
- The secondary table includes direct slots for the confirmed `ScrollNewGroupPane` methods at `0x00560b00`, `0x00560cf0`, and `0x00560d00`.
- Boundary check on 2026-06-01: `0x00623f18` is the RTTI-adjacent word before the primary `ScrollNewGroupPane` table, `0x00623f64` and `0x00623f94` are the secondary/tertiary RTTI-adjacent words, and `0x00623fa0` is the next RTTI-adjacent word before `ScrollCollectionPane`.

## Reconstruction Notes

Model the class with the same pane multiple-inheritance pattern seen elsewhere in the client: primary object at `+0x00`, secondary pane-data view at `+0xa0`, and tertiary effect/update view at `+0xa4`.

This vtable-cluster page carries a formal no standalone C++ body marker. Source coverage belongs to the `ScrollNewGroupPane` class declaration and exact virtual method pages, not a hand-authored literal vtable array.

## Cross-References

- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0002OS][0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData](by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md)
- [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md)
- [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md)
- [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md)
- [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md)

## Changes

- 2026-06-30 B002 Group empty-emitter implementation:
  - Inserted the formal no standalone C++ body marker.
  - Corrected stale slot wording to `CanScroll` and `OnScrollTimer`, and updated the `0x00560b00` child wording to `HandleMouseEvent`.
- 2026-06-11 A002 assignment pass:
  - Before: the page was `84/90`, reconstructable, and unassigned because direct class parent [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) was below the corrected gate.
  - Changed to: raised to `85/91`, set `AUTOGEN_PARENT_UID:0000CL`, added the strict gate rationale, and recorded fresh IDA evidence.
  - Evidence: live IDA reconfirmed method bounds, vtable dwords, constructor stores, slot xrefs, NewGroupPane constructor/show callers, cursor-to-scroll callback ownership, and the next `ScrollCollectionPane` boundary. The direct class parent is now `85/86`, so the child/direct-parent `85/85` gate clears.
- Previous: the page tracked vtable bases and slot targets but had no exact by-memory vtable-data child and still carried `0/0` validator scores.
- Changed to: exact child range [UID:0002OS][0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData](by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md) added, reconstruction flag set true, and scores raised conservatively below final-audit level.
- Evidence: IDA MCP confirms constructor stores for all three vtable bases, slot targets for the secondary/tertiary views, and neighboring `ScrollSpellInventoryPane`/`ScrollCollectionPane` boundaries.
