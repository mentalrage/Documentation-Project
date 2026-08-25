// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M5
// Source by-file doc: by-file/ObjectPane.md
// UID:0003XT | by-memory/0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane.md | Completion:91 | Confidence:93
void ObjectPane::SetSoundObjectPane(SoundObjectPane *soundObjectPane)
{
    if (m_soundObjectPane != NULL) {
        delete m_soundObjectPane;
    }

    m_soundObjectPane = soundObjectPane;
}

// UID:0003XU | by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md | Completion:90 | Confidence:92
void ObjectPane::ClearSoundObjectPane()
{
    if (m_soundObjectPane != NULL) {
        m_soundObjectPane = NULL;
    }
}

// UID:0002SK | by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md | Completion:91 | Confidence:94
// Emitted code for this range is covered by [UID:00009R][ObjectPane](by-class/ObjectPane.md).

// UID:00020R | by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md | Completion:92 | Confidence:94
void ObjectPane::ClearOutputRects(
    RectBounds *paneBounds,
    RectBounds *objectDataBounds)
{
    InitRectBounds(paneBounds, 0, 0, 0, 0);
    InitRectBounds(objectDataBounds, 0, 0, 0, 0);
}

// UID:00020S | by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md | Completion:95 | Confidence:95
RectBounds *ObjectPane::ComputeRenderBounds(RectBounds *outBounds)
{
    outBounds->bottom = 0;
    outBounds->top = 0;
    outBounds->right = 0;
    outBounds->left = 0;
    return outBounds;
}



// UID:0003XP | by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md | Completion:92 | Confidence:94
MapPoint *ObjectPane::GetMapPosition(MapPoint *outPosition) const
{
    outPosition->row = m_mapY;
    outPosition->column = m_mapX;
    return outPosition;
}





// UID:0003XW | by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md | Completion:92 | Confidence:94
void ObjectPane::UpdateRenderRegion(const RectBounds *bounds)
{
    m_visibleBounds = *bounds;
}

// UID:0003XX | by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md | Completion:92 | Confidence:94
void ObjectPane::SetBounds(
    const RectBounds *paneBounds,
    const RectBounds *objectDataBounds)
{
    RectBounds currentBounds;
    GetScreenBounds(&currentBounds);

    if (!RectsEquivalent(&currentBounds, paneBounds)) {
        InitPointPair(&m_origin, paneBounds->top, paneBounds->left);
        m_visibleBounds = *paneBounds;
        m_visibleBounds.Offset(-m_visibleBounds.left,
                               -m_visibleBounds.top);
    }

    RectBounds newObjectDataBounds;
    if (objectDataBounds != NULL) {
        newObjectDataBounds = *objectDataBounds;
    } else {
        newObjectDataBounds = *paneBounds;
    }

    SetObjectData(&newObjectDataBounds);
}

// UID:00009R | by-class\ObjectPane.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0003XN | by-memory\0x005372d0-0x00537395.ObjectPaneConstructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003XO | by-memory\0x005373a0-0x005374cb.ObjectPaneNonDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003XQ | by-memory\0x005374f0-0x005375e1.ObjectPaneAttachObject.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003XR | by-memory\0x005375f0-0x005376b5.ObjectPaneDetachObject.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003XS | by-memory\0x005376c0-0x005376c7.ObjectPaneGetAttachedObject.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003XV | by-memory\0x00537720-0x00537739.ObjectPaneInvalidateObjectDataRect.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003XY | by-memory\0x00537800-0x0053787a.ObjectPaneSetObjectData.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003XZ | by-memory\0x00537880-0x00537894.ObjectPaneGetObjectData.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003Y0 | by-memory\0x005378a0-0x005378fa.ObjectPaneSetMapPosition.md | Completion:87 | Confidence:91 | Empty Emitter Marker
