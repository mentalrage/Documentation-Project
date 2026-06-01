*** UID:000073 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Layer

## Status

- Confidence: strong for class behavior.
- Likely source file: [UID:0000KL][Layer](by-file/Layer.md)
- Address range: [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- Current recovered file: `source-3/simroot_v2/class_Layer.cpp`

## Class Purpose

`Layer` manages a hierarchical tree of panes. Each node records a pane, bounds, clip bounds, visibility/flags, dirty state, and a `Region` or `Motion` slot. The class supports adding/removing panes, moving pane bounds through the tree, building aggregate dirty regions, and recursively rendering visible children.

## Observed State

```text
0x00  LObject base / vtable
0x04  HierList* child tree
```

Wave3 notes describe tree nodes with parent/next links, child sub-layer pointer, pane ID/pane pointer, flags, bounds rectangles, visibility/property bytes, dirty byte, and `Region`/`Motion` data. IDA MCP confirms `Layer::AddChildBefore`, `Layer::AddChildAfter`, and `Layer::RemoveChild` call [UID:000065][HierList](by-class/HierList.md) methods rather than a separate `TreeContainer` owner.

## Evidence Notes

- `Pane::AddToLayer` calls `Layer::AddChildAfter`.
- `Pane::InsertInLayer` calls `Layer::AddChildBefore`.
- `Pane` removal paths call `Layer::RemoveChild`.
- `MapPane` constructs `Layer` objects, so `Layer` should be documented as UI/render infrastructure rather than a feature-specific map class until map ownership is fully reviewed.

## Cross-References

- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:000065][HierList](by-class/HierList.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: the page documents the class purpose, core state, tree ownership, and major caller evidence, but it is not yet a complete method-by-method source reconstruction. Evidence: linked by-memory `Layer` range, `Pane` add/insert/remove call paths, `HierList` ownership confirmation, and map/UI infrastructure notes.
