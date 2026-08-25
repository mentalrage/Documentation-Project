// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KL
// Source by-file doc: by-file/Layer.md
// UID:000073 | by-class/Layer.md | Completion:92 | Confidence:94
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

    // UID:0004NR | by-memory/0x004f0480-0x004f0597.LayerConstructor.md | Completion:92 | Confidence:94
Layer::Layer()
    : m_nodes(NULL)
{
    MemoryMan *memoryMan = GetMemoryMan();
    HierListNode *root = static_cast<HierListNode *>(
        memoryMan->AllocateBufferMemory(sizeof(LayerNode) + 11));
    root->parent = NULL;

    LayerNode *rootNode = NodeData(root);
    rootNode->pane = g_pScreenPane;
    InitRectBounds(&rootNode->bounds, 0, 0, g_screenWidth, g_screenHeight);
    InitRectBounds(
        &rootNode->previousBounds, 0, 0, g_screenWidth, g_screenHeight);
    rootNode->visible = false;
    rootNode->blocksChildTraversal = false;
    rootNode->dirty = false;
    rootNode->dirtyRegion = new Region;

    m_nodes = new HierList(sizeof(LayerNode), root);
}

// UID:0004NS | by-memory/0x004f05a0-0x004f062a.LayerDestructor.md | Completion:92 | Confidence:94
Layer::~Layer()
{
    if (m_nodes != NULL) {
        HierListNode *root = RootNode();
        if (root != NULL) {
            delete NodeData(root)->dirtyRegion;
            GetMemoryMan()->FreeBufferMemory(root);
        }

        DestroyNodeRegions(m_nodes);
        delete m_nodes;
        m_nodes = NULL;
    }
}

// UID:0004NT | by-memory/0x004f0630-0x004f083c.LayerAddChildAfter.md | Completion:92 | Confidence:94
void Layer::AddChildAfter(const RectBounds *bounds, Pane *pane,
    Pane *referencePane, Pane *parentPane)
{
    pane->SetBounds(bounds, false);

    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -localBounds.left, -localBounds.top);
    pane->InvalidateRect(&localBounds);

    LayerNode *parentNode = NULL;
    if (parentPane != NULL) {
        HierListNode *node = FindPaneNode(parentPane);
        parentNode = NodeData(node);
    }

    LayerNode *referenceNode = NULL;
    if (referencePane != NULL) {
        HierListNode *node = FindPaneNode(referencePane);
        referenceNode = NodeData(node);
    }

    LayerNode node;
    node.pane = pane;
    InitRectBounds(&node.bounds, 0, 0, 0, 0);
    node.visible = pane->IsVisible();
    node.blocksChildTraversal = pane->BlocksChildTraversal();
    node.dirty = false;
    node.dirtyRegion = new Region;

    m_nodes->InsertAfter(parentNode, referenceNode, &node);
}

// UID:0004NU | by-memory/0x004f0840-0x004f0a5d.LayerAddChildBefore.md | Completion:92 | Confidence:94
void Layer::AddChildBefore(const RectBounds *bounds, Pane *pane,
    Pane *referencePane, Pane *parentPane)
{
    pane->SetBounds(bounds, false);

    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -localBounds.left, -localBounds.top);
    pane->InvalidateRect(&localBounds);

    LayerNode *parentNode = NULL;
    if (parentPane != NULL) {
        HierListNode *node = FindPaneNode(parentPane);
        parentNode = NodeData(node);
    }

    LayerNode *referenceNode = NULL;
    if (referencePane != NULL) {
        HierListNode *node = FindPaneNode(referencePane);
        referenceNode = NodeData(node);
    }

    LayerNode node;
    node.pane = pane;
    InitRectBounds(&node.bounds, 0, 0, 0, 0);
    InitRectBounds(&node.previousBounds, 0, 0, 0, 0);
    node.visible = pane->IsVisible();
    node.blocksChildTraversal = pane->BlocksChildTraversal();
    node.dirty = false;
    node.dirtyRegion = new Region;

    m_nodes->InsertBefore(parentNode, referenceNode, &node);
}

// UID:0004NV | by-memory/0x004f0a60-0x004f0b3d.LayerRemoveChild.md | Completion:92 | Confidence:94
void Layer::RemoveChild(Pane *pane)
{
    HierListNode *node = FindPaneNode(pane);
    if (node == NULL) {
        return;
    }

    LayerNode *data = NodeData(node);
    delete data->dirtyRegion;
    data->dirtyRegion = NULL;

    if (node->childList != NULL) {
        DestroyNodeRegions(node->childList);
    }

    Pane *parentPane = NodeData(node->parent)->pane;
    RectBounds bounds;
    pane->GetBounds(&bounds);
    parentPane->InvalidateRect(&bounds);

    m_nodes->RemoveByPayload(data);
}

// UID:0004NW | by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md | Completion:91 | Confidence:94
void Layer::MarkAllPanesForDeletion()
{
    const int count = m_nodes->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(m_nodes, index);
        if (node != NULL && node->pane != NULL) {
            node->pane->MarkForDeletion();
        }
    }
}

// UID:0004NX | by-memory/0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked.md | Completion:91 | Confidence:93
void Layer::SetPaneFlagsMasked(Pane *pane, unsigned char value,
    unsigned char mask)
{
    HierListNode *node = FindPaneNode(pane);
    LayerNode *data = NodeData(node);
    unsigned char oldFlags = data->paneFlags;
    unsigned char newFlags =
        (oldFlags & static_cast<unsigned char>(~mask)) | (value & mask);

    if ((oldFlags & 1) != (newFlags & 1)) {
        InitRectBounds(&data->bounds, 0, 0, 0, 0);
        InitRectBounds(&data->previousBounds, 0, 0, 0, 0);
        data->visible = pane->IsVisible();
        data->blocksChildTraversal = pane->BlocksChildTraversal();
        data->dirty = false;
        data->dirtyRegion->SetEmpty();

        if ((newFlags & 1) == 0) {
            RectBounds bounds;
            pane->GetBounds(&bounds);
            NodeData(node->parent)->pane->InvalidateRect(&bounds);
        }
    }

    data->paneFlags = newFlags;
}

// UID:0004NY | by-memory/0x004f0ca0-0x004f0d11.LayerGetPaneFlags.md | Completion:90 | Confidence:93
unsigned char Layer::GetPaneFlags(Pane *pane) const
{
    return NodeData(FindPaneNode(pane))->paneFlags;
}

// UID:0004NZ | by-memory/0x004f0d20-0x004f0d93.LayerContainsPane.md | Completion:91 | Confidence:94
bool Layer::ContainsPane(Pane *pane) const
{
    return FindPaneNode(pane) != NULL;
}

// UID:0004O0 | by-memory/0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md | Completion:92 | Confidence:94
void Layer::InvalidatePaneRegion(Pane *pane, const RectBounds *bounds)
{
    HierListNode *node = FindPaneNode(pane);
    if (node == NULL) {
        return;
    }

    Region dirtyRegion;
    Region paneRegion;
    dirtyRegion.SetRect(bounds);
    pane->GetRenderRegion(&paneRegion);
    dirtyRegion.IntersectWith(paneRegion);

    RectBounds paneBounds;
    pane->GetBounds(&paneBounds);
    dirtyRegion.IntersectWithRect(&paneBounds);

    LayerNode *data = NodeData(node);
    data->dirty = true;
    data->dirtyRegion->UnionWith(dirtyRegion);

    HierListNode *root = RootNode();
    while (node != root) {
        Point offset;
        data->pane->GetLocalOffset(&offset);
        dirtyRegion.Offset(offset.y, offset.x);

        node = node->parent;
        data = NodeData(node);
        data->dirty = true;
        data->dirtyRegion->UnionWith(dirtyRegion);
    }
}

// UID:0004O1 | by-memory/0x004f0f30-0x004f0f42.LayerClearDirtyRegion.md | Completion:92 | Confidence:94
void Layer::ClearDirtyRegion()
{
    LayerNode *root = NodeData(RootNode());
    root->dirty = false;
    root->dirtyRegion->SetEmpty();
}

// UID:0004O2 | by-memory/0x004f0f50-0x004f0f68.LayerCopyDirtyRegion.md | Completion:92 | Confidence:94
void Layer::CopyDirtyRegion(Region *region) const
{
    region->CopyRectFrom(*NodeData(RootNode())->dirtyRegion);
}

// UID:0004O3 | by-memory/0x004f0f70-0x004f0f82.LayerUnionDirtyRegion.md | Completion:92 | Confidence:94
void Layer::UnionDirtyRegion(const Region *region)
{
    NodeData(RootNode())->dirtyRegion->UnionWith(*region);
}

// UID:0004O4 | by-memory/0x004f0f90-0x004f0fca.LayerCollectDirtyRegion.md | Completion:92 | Confidence:94
void Layer::CollectDirtyRegion(Region *region, Region *pendingRegion)
{
    LayerNode *root = NodeData(RootNode());
    root->dirtyRegion->UnionWith(*pendingRegion);
    UpdateDirtyRegionsRecursive(root, m_nodes, pendingRegion);
    region->CopyRectFrom(*root->dirtyRegion);
}

// UID:0004O5 | by-memory/0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion.md | Completion:92 | Confidence:94
void Layer::PropagateDirtyRegion()
{
    PropagateDirtyRegionRecursive(NodeData(RootNode()), m_nodes);
}

// UID:0004O6 | by-memory/0x004f0ff0-0x004f138b.LayerRenderRecursive.md | Completion:92 | Confidence:94
bool Layer::RenderRecursive(GrafPort *grafPort, int xOffset, int yOffset,
    Region *renderedRegion, HierList *list)
{
    bool rendered = false;
    if (list == NULL) {
        list = m_nodes;
    }

    LayerNode *owner = NodeData(list->ownerNode);
    Region parentRegion;
    owner->pane->GetRenderRegion(&parentRegion);

    RectBounds ownerBounds;
    owner->pane->GetBounds(&ownerBounds);
    parentRegion.IntersectWithRect(&ownerBounds);
    parentRegion.Offset(yOffset, xOffset);

    RectBounds screenBounds;
    InitRectBounds(&screenBounds, 0, 0, g_screenWidth, g_screenHeight);

    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        Pane *pane = node->pane;
        if (!pane->IsVisible()) {
            continue;
        }

        Point origin;
        pane->GetLocalOffset(&origin);
        origin.x += xOffset;
        origin.y += yOffset;

        if (node->dirty) {
            rendered = true;

            if (pane->GetMode() != 4) {
                Region drawRegion;
                drawRegion.CopyRectFrom(*node->dirtyRegion);

                RectBounds paneBounds;
                pane->GetBounds(&paneBounds);
                drawRegion.IntersectWithRect(&paneBounds);

                Region paneRegion;
                pane->GetRenderRegion(&paneRegion);
                drawRegion.IntersectWith(paneRegion);
                drawRegion.Offset(origin.y, origin.x);
                drawRegion.IntersectWith(parentRegion);
                drawRegion.IntersectWithRect(&screenBounds);

                Region localRegion;
                localRegion.CopyRectFrom(drawRegion);
                localRegion.Offset(-origin.y, -origin.x);
                grafPort->SetClipRegion(&drawRegion);

                RectBounds clipBounds;
                RectBounds localBounds;
                localRegion.GetRect(&clipBounds);
                drawRegion.GetRect(&localBounds);

                if (!IsRectEmptyOrInvalid(&clipBounds)) {
                    if (pane->UsesCustomPaint()) {
                        grafPort->BeginPaint();
                        pane->OnPaint(grafPort, &clipBounds, &localBounds);
                        grafPort->EndPaint();
                    } else if (g_pActiveMapPane != NULL
                        && pane == g_pActiveMapPane
                        && g_pActiveMapPane->HasScreenEffecters()) {
                        ScreenEffecter *effecter =
                            g_pActiveMapPane->FindActivePixelEffecter();
                        if (effecter != NULL) {
                            effecter->Apply(grafPort, &clipBounds, &localBounds);
                        } else {
                            grafPort->DrawPane(
                                pane, &clipBounds, &localBounds, pane->GetMode());
                        }
                    } else {
                        grafPort->DrawPane(
                            pane, &clipBounds, &localBounds, pane->GetMode());
                    }

                    renderedRegion->UnionWithRect(&localBounds);
                }
            }

            node->dirty = false;
            node->dirtyRegion->SetEmpty();
        }

        HierListNode *header = NodeHeader(node);
        if (header->childList != NULL && !node->blocksChildTraversal) {
            if (RenderRecursive(grafPort, origin.x, origin.y,
                    renderedRegion, header->childList)) {
                rendered = true;
            }
        }
    }

    return rendered;
}

// UID:0004O7 | by-memory/0x004f1390-0x004f1391.LayerEndRender.md | Completion:91 | Confidence:94
void Layer::EndRender()
{
}

// UID:0004O8 | by-memory/0x004f13a0-0x004f1411.LayerGetChildList.md | Completion:90 | Confidence:93
HierList *Layer::GetChildList(Pane *pane) const
{
    return FindPaneNode(pane)->childList;
}

// UID:0004O9 | by-memory/0x004f1420-0x004f1499.LayerGetParentPane.md | Completion:92 | Confidence:94
Pane *Layer::GetParentPane(Pane *pane) const
{
    HierList *ownerList;
    FindPaneNode(pane, &ownerList);

    HierListNode *parent = ownerList->ownerNode;
    return parent != NULL ? NodeData(parent)->pane : NULL;
}

// UID:0004OA | by-memory/0x004f14a0-0x004f1593.LayerGetScreenOffset.md | Completion:92 | Confidence:94
void Layer::GetScreenOffset(Point *offset, Pane *pane) const
{
    InitPointPair(offset, 0, 0);

    HierListNode *node = FindPaneNode(pane);
    if (node == NULL) {
        InitPointPair(offset, -1000, -1000);
        return;
    }

    HierListNode *root = RootNode();
    while (node != root) {
        Point localOffset;
        NodeData(node)->pane->GetLocalOffset(&localOffset);
        offset->x += localOffset.x;
        offset->y += localOffset.y;
        node = node->parent;
    }
}

// UID:0004OB | by-memory/0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive.md | Completion:92 | Confidence:94
void Layer::UpdateDirtyRegionsRecursive(LayerNode *parentNode,
    HierList *list, Region *dirtyRegion)
{
    HierListNode *root = RootNode();
    const int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);
        Pane *pane = node->pane;

        if (pane != NULL && pane->HasPendingMotion()) {
            Region motionRegion;
            Region paneRegion;
            pane->GetCurrentMotionRegion(&motionRegion);
            pane->GetRenderRegion(&paneRegion);
            motionRegion.IntersectWith(paneRegion);
            pane->BeginMotionPaint();
            if (!pane->SuppressesMotionRefresh()) {
                pane->RefreshMotionLayout();
            }
            pane->EndMotionPaint();

            HierListNode *ancestor = header;
            Pane *ancestorPane = pane;
            while (ancestor != root) {
                Point ancestorOffset;
                ancestorPane->GetLocalOffset(&ancestorOffset);
                motionRegion.Offset(ancestorOffset.y, ancestorOffset.x);
                ancestor = ancestor->parent;
                ancestorPane = NodeData(ancestor)->pane;
            }

            LayerNode *ancestorNode = NodeData(ancestor);
            ancestorNode->dirty = true;
            ancestorNode->dirtyRegion->UnionWith(motionRegion);
            if (pane->GetMode() != 0) {
                dirtyRegion->UnionWith(motionRegion);
            } else {
                dirtyRegion->Subtract(motionRegion);
            }
        }

        RectBounds currentBounds;
        pane->GetBounds(&currentBounds);
        if (currentBounds != node->bounds) {
            Region currentRegion;
            pane->GetRenderRegion(&currentRegion);
            currentRegion.Offset(currentBounds.top, currentBounds.left);
            currentRegion.IntersectWithRect(&currentBounds);

            RectBounds currentRegionBounds;
            currentRegion.GetRect(&currentRegionBounds);

            Region changedRegion;
            changedRegion.SetRect(&currentRegionBounds);
            changedRegion.UnionWithRect(&node->previousBounds);

            Region previousRegion;
            parentNode->pane->GetRenderRegion(&previousRegion);
            changedRegion.IntersectWith(previousRegion);

            HierListNode *ancestor = header->parent;
            Pane *ancestorPane = NodeData(ancestor)->pane;
            while (ancestor != root) {
                Point ancestorOffset;
                ancestorPane->GetLocalOffset(&ancestorOffset);
                changedRegion.Offset(ancestorOffset.y, ancestorOffset.x);
                ancestor = ancestor->parent;
                ancestorPane = NodeData(ancestor)->pane;
            }

            LayerNode *ancestorNode = NodeData(ancestor);
            ancestorNode->dirty = true;
            ancestorNode->dirtyRegion->UnionWith(changedRegion);
            if (currentRegionBounds != node->previousBounds) {
                dirtyRegion->UnionWith(changedRegion);
            }

            node->bounds = currentBounds;
            node->previousBounds = currentRegionBounds;
        }

        if (header->childList != NULL && !node->blocksChildTraversal) {
            UpdateDirtyRegionsRecursive(node, header->childList, dirtyRegion);
        }
    }
}

// UID:0004OC | by-memory/0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive.md | Completion:92 | Confidence:94
void Layer::PropagateDirtyRegionRecursive(LayerNode *parentNode,
    HierList *list)
{
    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);

        RectBounds bounds;
        node->pane->GetBounds(&bounds);

        Region childDirty;
        childDirty.CopyRectFrom(*parentNode->dirtyRegion);
        if (childDirty.IntersectWithRect(&bounds)) {
            childDirty.Offset(-bounds.top, -bounds.left);

            Region paneRegion;
            node->pane->GetRenderRegion(&paneRegion);
            childDirty.IntersectWith(paneRegion);

            node->dirty = true;
            node->dirtyRegion->UnionWith(childDirty);
        }

        if (header->childList != NULL && !node->blocksChildTraversal) {
            PropagateDirtyRegionRecursive(node, header->childList);
        }
    }
}

// UID:0004OD | by-memory/0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions.md | Completion:92 | Confidence:94
void Layer::DestroyNodeRegions(HierList *list)
{
    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);
        if (header->childList != NULL) {
            DestroyNodeRegions(header->childList);
        }
        delete node->dirtyRegion;
        node->dirtyRegion = NULL;
    }
}

// UID:0004OE | by-memory/0x004f1ab0-0x004f1b32.LayerFindPaneNode.md | Completion:92 | Confidence:94
HierListNode *Layer::FindPaneNode(Pane *pane, HierList **ownerList,
    int *outIndex, HierList *list) const
{
    if (list == NULL) {
        list = m_nodes;
    }

    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);
        if (node->pane == pane) {
            if (ownerList != NULL) {
                *ownerList = list;
            }
            if (outIndex != NULL) {
                *outIndex = index;
            }
            return header;
        }

        if (header->childList != NULL) {
            HierListNode *found = FindPaneNode(
                pane, ownerList, outIndex, header->childList);
            if (found != NULL) {
                return found;
            }
        }
    }

    return NULL;
}
};
