*** UID:000073 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Layer

## Status

- Confidence: strong for class behavior, source-file ownership, and key method boundaries; medium for the not-yet-final node field names/layout.
- Likely source file: [UID:0000KL][Layer](by-file/Layer.md)
- Address range: [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- Current recovered file: `source-3/simroot_v2/class_Layer.cpp`
- Reconstructable: true; attached to [UID:0000KL][Layer](by-file/Layer.md), with C++ intentionally blank until the node layout and final names reach the reconstruction bar.

## Class Purpose

`Layer` manages a hierarchical tree of panes. Each node records a pane, bounds, clip bounds, visibility/flags, dirty state, and a `Region` or `Motion` slot. The class supports adding/removing panes, moving pane bounds through the tree, building aggregate dirty regions, and recursively rendering visible children.

## Observed State

```text
0x00  LObject base / vtable
0x04  HierList* child tree
```

The aggregate memory page describes tree nodes with parent/next links, child sub-layer pointer, pane ID/pane pointer, flags, bounds rectangles, visibility/property bytes, dirty byte, and `Region`/`Motion` data. IDA MCP confirms `Layer::AddChildBefore`, `Layer::AddChildAfter`, and `Layer::RemoveChild` call [UID:000065][HierList](by-class/HierList.md) methods rather than a separate `TreeContainer` owner.

## Evidence Notes

- `Pane::AddToLayer` calls `Layer::AddChildAfter`.
- `Pane::InsertInLayer` calls `Layer::AddChildBefore`.
- `Pane` removal paths call `Layer::RemoveChild`.
- `MapPane` constructs `Layer` objects, so `Layer` should be documented as UI/render infrastructure rather than a feature-specific map class until map ownership is fully reviewed.
- 2026-06-06 IDA MCP recheck confirms key method anchors for constructor `0x004f0480`, add/insert/remove helpers `0x004f0630`, `0x004f0840`, and `0x004f0a60`, recursive render traversal `0x004f0ff0`, dirty propagation `0x004f15a0`, and scalar deleting destructor `0x004f1b40`.
- The same caller/callee pass ties add/insert/remove directly to [UID:0000A2][Pane](by-class/Pane.md) wrappers at `0x00544c93`, `0x00544cc6`, `0x0054460a`, `0x00544d19`, and `0x00544fe1`, and ties container operations to HierList insert/remove helpers at `0x004ce9b0`, `0x004ce860`, and `0x004ceb00`.
- Vtable xrefs to `0x0061ca48` come from constructor/destructor setup at `0x004f04ba`, `0x004f05c9`, and `0x004f1b70`; [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md) carries the full 22-function map.

## Cross-References

- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:000065][HierList](by-class/HierList.md)

## Changes

- 2026-06-06 A004 parent gate and evidence refresh:
  - Before: the class was `78/82`, reconstructable but unattached because the owning file had not cleared the `80/80` parent gate, and the observed-state note still leaned on recovered-tool provenance.
  - After: raised to `84/86`, attached `AUTOGEN_PARENT_UID` to [UID:0000KL][Layer](by-file/Layer.md), replaced the tool-provenance wording with current aggregate-memory evidence, and added live IDA method/caller/callee/vtable evidence.
  - Evidence: [UID:0000KL][Layer](by-file/Layer.md) is now `86/86`; IDA MCP `lookup_funcs`, `callers`, `callees`, and `xrefs_to` confirm the key constructor/add/insert/remove/render/dirty/destructor anchors, Pane wrappers, HierList backing operations, and Layer vtable writes. C++ remains blank because the exact node layout and final source names are not final-audit quality.
- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: the page documents the class purpose, core state, tree ownership, and major caller evidence, but it is not yet a complete method-by-method source reconstruction. Evidence: linked by-memory `Layer` range, `Pane` add/insert/remove call paths, `HierList` ownership confirmation, and map/UI infrastructure notes.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the pane-tree layer class unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `78/82` and parent confidence is below the 80 attachment gate.
  - Summary/evidence: live IDA MCP reconfirms the constructor/core start at `0x004f0480` with callers from application UI initialization and map/UI paths, matching the documented reusable UI layer role.
