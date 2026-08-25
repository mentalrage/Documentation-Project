*** UID:000073 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct LayerNode {
    Pane *pane;
    unsigned char paneFlags;
    unsigned char padding05[3];
    RectBounds bounds;
    RectBounds previousBounds;
    bool visible;
    bool blocksChildTraversal;
    bool dirty;
    unsigned char padding2B;
    Region *dirtyRegion;
};

class Layer : public LObject {
public:
    Layer();
    virtual ~Layer();

    void AddChildAfter(const RectBounds *bounds, Pane *pane,
        Pane *referencePane, Pane *parentPane);
    void AddChildBefore(const RectBounds *bounds, Pane *pane,
        Pane *referencePane, Pane *parentPane);
    void RemoveChild(Pane *pane);
    void MarkAllPanesForDeletion();
    void SetPaneFlagsMasked(Pane *pane, unsigned char value,
        unsigned char mask);
    unsigned char GetPaneFlags(Pane *pane) const;
    bool ContainsPane(Pane *pane) const;
    void InvalidatePaneRegion(Pane *pane, const RectBounds *bounds);

    void ClearDirtyRegion();
    void CopyDirtyRegion(Region *region) const;
    void UnionDirtyRegion(const Region *region);
    void CollectDirtyRegion(Region *region, Region *pendingRegion);
    void PropagateDirtyRegion();
    bool RenderRecursive(GrafPort *grafPort, int xOffset, int yOffset,
        Region *renderedRegion, HierList *list = NULL);
    void EndRender();

    HierList *GetChildList(Pane *pane) const;
    Pane *GetParentPane(Pane *pane) const;
    void GetScreenOffset(Point *offset, Pane *pane) const;

private:
    static LayerNode *NodeData(HierListNode *node)
    {
        return reinterpret_cast<LayerNode *>(node->payload);
    }

    static HierListNode *NodeHeader(LayerNode *node)
    {
        return reinterpret_cast<HierListNode *>(
            reinterpret_cast<unsigned char *>(node) - 8);
    }

    static LayerNode *NodeAt(HierList *list, int index)
    {
        return static_cast<LayerNode *>(list->GetElementAt(index));
    }

    HierListNode *RootNode() const
    {
        return m_nodes->ownerNode;
    }

    HierListNode *FindPaneNode(Pane *pane, HierList **ownerList = NULL,
        int *index = NULL, HierList *list = NULL) const;
    void UpdateDirtyRegionsRecursive(LayerNode *parentNode,
        HierList *list, Region *dirtyRegion);
    static void PropagateDirtyRegionRecursive(LayerNode *parentNode,
        HierList *list);
    static void DestroyNodeRegions(HierList *list);

    HierList *m_nodes;

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Layer

## Current Implemented Class State

- Applied score and route: `92/94`, owner/emitter [UID:0000KL][Layer](by-file/Layer.md), reconstructable true, source position 10.
- Object layout: inherited LObject/vptr at `+0x00`, `HierList *m_nodes` at `+0x04`; total source object size eight bytes.
- LayerNode is the exact 48-byte HierList payload. The declaration preserves pane, flags/padding, current/previous bounds, visible, traversal-block, dirty, padding, and owned Region pointer at offsets `+0x00/+0x04/+0x05/+0x08/+0x18/+0x28/+0x29/+0x2a/+0x2b/+0x2c`.
- The class owns its root/list and per-node Regions, borrows Pane pointers, and requests Pane deletion through MarkAllPanesForDeletion rather than deleting panes itself.
- Source placement remains `NexusTK/ui/core/Layer.cpp`; ScreenPane, MapPane, Pane, HierList, Region/Motion, Application, WorldMapPane, MainMenuPane, and FlyingParcelPane are callers/clients/dependencies.

## Registered Method Children

| Child | Applied disposition |
| --- | --- |
| [UID:0004NR][0x004f0480-0x004f0597.LayerConstructor](by-memory/0x004f0480-0x004f0597.LayerConstructor.md) | source position 20 |
| [UID:0004NS][0x004f05a0-0x004f062a.LayerDestructor](by-memory/0x004f05a0-0x004f062a.LayerDestructor.md) | source position 30 |
| [UID:0004NT][0x004f0630-0x004f083c.LayerAddChildAfter](by-memory/0x004f0630-0x004f083c.LayerAddChildAfter.md) | source position 40 |
| [UID:0004NU][0x004f0840-0x004f0a5d.LayerAddChildBefore](by-memory/0x004f0840-0x004f0a5d.LayerAddChildBefore.md) | source position 50 |
| [UID:0004NV][0x004f0a60-0x004f0b3d.LayerRemoveChild](by-memory/0x004f0a60-0x004f0b3d.LayerRemoveChild.md) | source position 60 |
| [UID:0004NW][0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion](by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md) | source position 70 |
| [UID:0004NX][0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked](by-memory/0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked.md) | source position 80 |
| [UID:0004NY][0x004f0ca0-0x004f0d11.LayerGetPaneFlags](by-memory/0x004f0ca0-0x004f0d11.LayerGetPaneFlags.md) | source position 90 |
| [UID:0004NZ][0x004f0d20-0x004f0d93.LayerContainsPane](by-memory/0x004f0d20-0x004f0d93.LayerContainsPane.md) | source position 100 |
| [UID:0004O0][0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion](by-memory/0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md) | source position 110 |
| [UID:0004O1][0x004f0f30-0x004f0f42.LayerClearDirtyRegion](by-memory/0x004f0f30-0x004f0f42.LayerClearDirtyRegion.md) | source position 120 |
| [UID:0004O2][0x004f0f50-0x004f0f68.LayerCopyDirtyRegion](by-memory/0x004f0f50-0x004f0f68.LayerCopyDirtyRegion.md) | source position 130 |
| [UID:0004O3][0x004f0f70-0x004f0f82.LayerUnionDirtyRegion](by-memory/0x004f0f70-0x004f0f82.LayerUnionDirtyRegion.md) | source position 140 |
| [UID:0004O4][0x004f0f90-0x004f0fca.LayerCollectDirtyRegion](by-memory/0x004f0f90-0x004f0fca.LayerCollectDirtyRegion.md) | source position 150 |
| [UID:0004O5][0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion](by-memory/0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion.md) | source position 160 |
| [UID:0004O6][0x004f0ff0-0x004f138b.LayerRenderRecursive](by-memory/0x004f0ff0-0x004f138b.LayerRenderRecursive.md) | source position 170 |
| [UID:0004O7][0x004f1390-0x004f1391.LayerEndRender](by-memory/0x004f1390-0x004f1391.LayerEndRender.md) | source position 180 |
| [UID:0004O8][0x004f13a0-0x004f1411.LayerGetChildList](by-memory/0x004f13a0-0x004f1411.LayerGetChildList.md) | source position 190 |
| [UID:0004O9][0x004f1420-0x004f1499.LayerGetParentPane](by-memory/0x004f1420-0x004f1499.LayerGetParentPane.md) | source position 200 |
| [UID:0004OA][0x004f14a0-0x004f1593.LayerGetScreenOffset](by-memory/0x004f14a0-0x004f1593.LayerGetScreenOffset.md) | source position 210 |
| [UID:0004OB][0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive](by-memory/0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive.md) | source position 220 |
| [UID:0004OC][0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive](by-memory/0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive.md) | source position 230 |
| [UID:0004OD][0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions](by-memory/0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions.md) | source position 240 |
| [UID:0004OE][0x004f1ab0-0x004f1b32.LayerFindPaneNode](by-memory/0x004f1ab0-0x004f1b32.LayerFindPaneNode.md) | source position 250 |
| [UID:0004OF][0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor](by-memory/0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor.md) | compiler-only, no source position |

The first 24 children emit once through this class in address/source order. UID0004OF is the compiler scalar deleting destructor: it remains non-reconstructable, non-emitting, and is regenerated from the virtual ordinary destructor. The three raw members retain their no-xref evidence, and Layer::EndRender remains a direct ordinary no-op member rather than a vtable callback.

## Current Evidence And Inference

Constructor allocation size `0x3b`, HierList payload size 48, and complete field use prove the LayerNode and 59-byte row layouts. Pane wrappers call add-after, add-before, remove, membership, invalidation, parent, and offset methods. ScreenPane calls the dirty/render sequence and direct EndRender. MainMenuPane initialization and MapPane teardown/reset call the independently revalidated full top-level `MarkAllPanesForDeletion` traversal. Layer vtable refs at `0x004f04ba`, `0x004f05c9`, and `0x004f1b70` plus slots at `0x0061ca48..0x0061ca50` establish the virtual destructor source cause and compiler-only scalar wrapper.

The accepted source-facing names are the strongest behavior/caller/class-order inferences. `LayerEntry`, `ScreenLayerEntry`, `PaneNodeData`, `MarkRootPanesForDeletion`, `DeleteAllPanes`, optional/nullsub EndRender, render-side ownership, and handwritten scalar cleanup are rejected or historical. No PDB UDT survives, which caps the score below 95 but does not leave an implementation blocker.



## Historical Pre-Split Status

- Confidence: strong for class behavior, source-file ownership, vtable evidence, and method boundaries; medium-high for the not-yet-final node field names/layout.
- Likely source file: [UID:0000KL][Layer](by-file/Layer.md)
- Address range: [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- Generated-output note: no Wave2/Wave3 source output is used as authority; ownership rests on by-file/by-memory/IDA evidence.
- Reconstructable: true; attached to [UID:0000KL][Layer](by-file/Layer.md), with C++ intentionally blank until the node layout and final names reach the reconstruction bar.

## Historical Pre-Split Class Purpose

`Layer` manages a hierarchical tree of panes. Each node records a pane, bounds, clip bounds, visibility/flags, dirty state, and a `Region` or `Motion` slot. The class supports adding/removing panes, moving pane bounds through the tree, building aggregate dirty regions, and recursively rendering visible children.

## Historical Pre-Split Observed State

```text
0x00  LObject base / vtable
0x04  HierList* child tree
```

The aggregate memory page describes tree nodes with parent/next links, child sub-layer pointer, pane ID/pane pointer, flags, bounds rectangles, visibility/property bytes, dirty byte, and `Region`/`Motion` data. IDA MCP confirms `Layer::AddChildBefore`, `Layer::AddChildAfter`, and `Layer::RemoveChild` call [UID:000065][HierList](by-class/HierList.md) methods rather than a separate `TreeContainer` owner.

## Historical Pre-Split Evidence Notes

- `Pane::AddToLayer` calls `Layer::AddChildAfter`.
- `Pane::InsertInLayer` calls `Layer::AddChildBefore`.
- `Pane` removal paths call `Layer::RemoveChild`.
- `MapPane` constructs `Layer` objects, so `Layer` should be documented as UI/render infrastructure rather than a feature-specific map class until map ownership is fully reviewed.
- 2026-06-06 IDA MCP recheck confirms key method anchors for constructor `0x004f0480`, add/insert/remove helpers `0x004f0630`, `0x004f0840`, and `0x004f0a60`, recursive render traversal `0x004f0ff0`, dirty propagation `0x004f15a0`, and scalar deleting destructor `0x004f1b40`.
- The same caller/callee pass ties add/insert/remove directly to [UID:0000A2][Pane](by-class/Pane.md) wrappers at `0x00544c93`, `0x00544cc6`, `0x0054460a`, `0x00544d19`, and `0x00544fe1`, and ties container operations to HierList insert/remove helpers at `0x004ce9b0`, `0x004ce860`, and `0x004ceb00`.
- Vtable xrefs to `0x0061ca48` come from constructor/destructor setup at `0x004f04ba`, `0x004f05c9`, and `0x004f1b70`; [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md) carries the full 22-function map.

## Historical 2026-06-16 A001 Evidence Refresh

- Live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the 22 modeled functions in [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md), including constructor `0x004f0480` size `0x117`, destructor/reset `0x004f05a0` size `0x8a`, add/insert/remove anchors `0x004f0630`/`0x004f0840`/`0x004f0a60`, recursive render `0x004f0ff0` size `0x39b`, dirty propagation `0x004f15a0` size `0x366`, and scalar deleting destructor `0x004f1b40` size `0xb6`.
- `lookup_funcs` also reconfirmed that `0x004f0b80`, `0x004f0c10`, `0x004f0c70`, and the half-open end `0x004f1bf6` are not functions, while successor `0x004f1c00` begins a separate `0x409`-byte function. No split/merge change is supported.
- `xrefs_to 0x0061ca48` returns constructor/destructor vtable refs at `0x004f04ba`, `0x004f05c9`, and `0x004f1b70`. Constructor `0x004f0480` has nine refs from UI/map/startup paths; add/insert/remove have Pane wrapper refs; recursive render and dirty propagation have self-recursive refs plus external use sites.
- `func_profile` confirms the constructor callers/callees include allocator, pane/system setup, `HierList` construction, and cleanup helpers; render/dirty profiles show recursive self edges and calls into draw/region/motion helper families. This supports `Layer` as shared UI/render infrastructure, not a `MapPane` child.
- `search_structs`/`type_query` found no IDA UDT for `Layer` or `LayerNode`; `entity_query names *LayerNode*` returned no names. Final node member names and header/source declaration shape therefore remain unsafe to claim despite stable behavior.

## Historical Pre-Split Score Rationale

Completion/confidence are raised from `84/86` to `86/88` because current IDA evidence reconfirms the full function map, non-function gaps, constructor/destructor/vtable refs, Pane caller routes, recursive render/dirty behavior, and the direct by-file/by-memory support pages. Final C++ remains blank because `LayerNode` field names and source-facing method names are not backed by IDA UDT/name evidence.

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
- 2026-06-16 A001 source-quality refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: current IDA MCP rechecked all 22 modeled function starts, internal non-function gaps, successor boundary, vtable refs, constructor/render/dirty profiles, Pane caller routes, and absence of IDA `LayerNode` type/name evidence. Owner/emitter remains [UID:0000KL][Layer](by-file/Layer.md); final C++ remains gated by node-layout and source-name evidence.
