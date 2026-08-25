// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M4
// Source by-file doc: by-file/ObjectList.md
// UID:00009Q | by-class/ObjectList.md | Completion:92 | Confidence:93
#include "ObjectList.h"
#include "LightingObjectPane.h"
#include "MapPane.h"
#include "ObjectPane.h"
#include "StaticObjectPane.h"
#include "../render/StaticObjImageLib.h"
#include "../util/List.h"

// UID:00023D | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | Completion:94 | Confidence:93
void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)
{
    StaticObjEntry *staticObjEntry =
        g_pStaticObjImageLib->GetStaticObjectEntry(staticObjectId);
    const short extendedRowCount =
        static_cast<short>(m_gridHeight + 12);

    for (int rowIndex = 0; rowIndex < extendedRowCount; ++rowIndex)
    {
        List *staticObjectRow = m_staticObjectRows[rowIndex];
        const int staticObjectCount = staticObjectRow->GetCount();

        for (int objectIndex = 0;
             objectIndex < staticObjectCount;
             ++objectIndex)
        {
            StaticObjectPane *staticObjectPane =
                *static_cast<StaticObjectPane **>(
                    staticObjectRow->GetElementAt(objectIndex));

            if (staticObjectPane->GetStaticObjectId() != staticObjectId)
                continue;

            staticObjectPane->InvalidateRect(NULL);
            LightingObjectPane *lightingObjectPane =
                static_cast<LightingObjectPane *>(
                    staticObjectPane->GetAttachedObject());

            if (lightingObjectPane != NULL)
            {
                if (staticObjEntry->lightImageIndex < 0)
                {
                    const int lightingObjectCount =
                        m_lightingObjects->GetCount();
                    for (int lightIndex = 0;
                         lightIndex < lightingObjectCount;
                         ++lightIndex)
                    {
                        LightingObjectPane *candidate =
                            *static_cast<LightingObjectPane **>(
                                m_lightingObjects->GetElementAt(lightIndex));
                        if (candidate == lightingObjectPane)
                        {
                            m_lightingObjects->RemoveAt(lightIndex, 1);
                            break;
                        }
                    }

                    staticObjectPane->DetachObject();
                    delete lightingObjectPane;
                }
                else
                {
                    lightingObjectPane->SetLightImageIndex(
                        staticObjEntry->lightImageIndex);
                }
            }
            else if (staticObjEntry->lightImageIndex >= 0)
            {
                MapPoint position;
                staticObjectPane->GetMapPosition(&position);

                lightingObjectPane = new LightingObjectPane(
                    staticObjectPane,
                    position.row,
                    position.column,
                    g_mapTilePixelWidth,
                    g_mapTilePixelHeight / 2 -
                        g_mapTilePixelHeight *
                            staticObjEntry->lightHeightClass,
                    staticObjEntry->lightImageIndex);

                AddObjectPane(lightingObjectPane);
                staticObjectPane->AttachObject(lightingObjectPane);
            }
        }
    }
}

// UID:0001D1 | by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md | Completion:87 | Confidence:92
// ObjectList lifecycle aggregate; exact constructor and destructor children own source bodies.
// UID:0002JS | by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md | Completion:90 | Confidence:92
ObjectList::ObjectList(int gridWidth, int gridHeight)
{
    MemoryMan *memoryMan = GetMemoryMan();

    const int paddedWidth = gridWidth + 4;
    const int paddedHeight = gridHeight + 4;
    const int fullListPageSize = paddedWidth * paddedHeight * 100;
    const int rowListPageSize = paddedWidth * 10;
    const short rowCount = static_cast<short>(gridHeight + 4);
    const short extendedRowCount = static_cast<short>(gridHeight + 12);

    m_minX = -30000;
    m_minY = -30000;
    m_gridWidth = gridWidth;
    m_gridHeight = gridHeight;

    m_itemObjects = new List(sizeof(ObjectPane *), fullListPageSize);
    m_flyingObjects = new List(sizeof(ObjectPane *), fullListPageSize);

    m_primaryEffectRows = static_cast<List **>(
        memoryMan->ZeroAllocateBufferMemory(sizeof(List *) * rowCount));
    m_secondaryEffectRows = static_cast<List **>(
        memoryMan->ZeroAllocateBufferMemory(sizeof(List *) * rowCount));

    for (int row = 0; row < rowCount; ++row) {
        m_primaryEffectRows[row] = new List(sizeof(ObjectPane *), rowListPageSize);
        m_secondaryEffectRows[row] = new List(sizeof(ObjectPane *), rowListPageSize);
    }

    m_livingObjectRows = static_cast<List **>(
        memoryMan->ZeroAllocateBufferMemory(sizeof(List *) * rowCount));

    for (int row = 0; row < rowCount; ++row) {
        m_livingObjectRows[row] = new List(sizeof(ObjectPane *), rowListPageSize);
    }

    m_staticObjectRows = static_cast<List **>(
        memoryMan->ZeroAllocateBufferMemory(sizeof(List *) * extendedRowCount));

    for (int row = 0; row < extendedRowCount; ++row) {
        m_staticObjectRows[row] = new List(sizeof(ObjectPane *), rowListPageSize);
    }

    m_balloonObjects = new List(sizeof(ObjectPane *), fullListPageSize);
    m_hitBarObjects = new List(sizeof(ObjectPane *), fullListPageSize);

    if (g_useEpfAssets == true) {
        m_damageNumberObjects = new List(sizeof(ObjectPane *), fullListPageSize);
    }

    m_objectInfoObjects = new List(sizeof(ObjectPane *), fullListPageSize);
    m_lightingObjects = new List(sizeof(ObjectPane *), fullListPageSize);
    m_soundObjects = new List(sizeof(ObjectPane *), fullListPageSize);
}

// UID:0002JT | by-memory/0x00531260-0x00531473.ObjectListDestructor.md | Completion:90 | Confidence:92
ObjectList::~ObjectList()
{
    MemoryMan *memoryMan = GetMemoryMan();
    const short rowCount = static_cast<short>(m_gridHeight + 4);
    const short extendedRowCount = static_cast<short>(m_gridHeight + 12);

    if (m_livingObjectRows != NULL) {
        for (int row = 0; row < rowCount; ++row) {
            if (m_livingObjectRows[row] != NULL) {
                delete m_livingObjectRows[row];
                m_livingObjectRows[row] = NULL;
            }
        }

        m_livingObjectRows = static_cast<List **>(
            memoryMan->FreeBufferMemory(m_livingObjectRows));
    }

    if (m_staticObjectRows != NULL) {
        for (int row = 0; row < extendedRowCount; ++row) {
            if (m_staticObjectRows[row] != NULL) {
                delete m_staticObjectRows[row];
                m_staticObjectRows[row] = NULL;
            }
        }

        m_staticObjectRows = static_cast<List **>(
            memoryMan->FreeBufferMemory(m_staticObjectRows));
    }

    if (m_itemObjects != NULL) {
        delete m_itemObjects;
        m_itemObjects = NULL;
    }

    if (m_flyingObjects != NULL) {
        delete m_flyingObjects;
        m_flyingObjects = NULL;
    }

    if (m_primaryEffectRows != NULL) {
        for (int row = 0; row < rowCount; ++row) {
            if (m_primaryEffectRows[row] != NULL) {
                delete m_primaryEffectRows[row];
                m_primaryEffectRows[row] = NULL;
            }

            if (m_secondaryEffectRows[row] != NULL) {
                delete m_secondaryEffectRows[row];
                m_secondaryEffectRows[row] = NULL;
            }
        }

        m_primaryEffectRows = static_cast<List **>(
            memoryMan->FreeBufferMemory(m_primaryEffectRows));
        m_secondaryEffectRows = static_cast<List **>(
            memoryMan->FreeBufferMemory(m_secondaryEffectRows));
    }

    if (m_balloonObjects != NULL) {
        delete m_balloonObjects;
        m_balloonObjects = NULL;
    }

    if (m_hitBarObjects != NULL) {
        delete m_hitBarObjects;
        m_hitBarObjects = NULL;
    }

    if (g_useEpfAssets == true) {
        if (m_damageNumberObjects != NULL) {
            delete m_damageNumberObjects;
            m_damageNumberObjects = NULL;
        }
    }

    if (m_objectInfoObjects != NULL) {
        delete m_objectInfoObjects;
        m_objectInfoObjects = NULL;
    }

    if (m_lightingObjects != NULL) {
        delete m_lightingObjects;
        m_lightingObjects = NULL;
    }

    if (m_soundObjects != NULL) {
        delete m_soundObjects;
        m_soundObjects = NULL;
    }
}

// UID:0002C8 | by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md | Completion:88 | Confidence:91
bool ObjectList::HasValidGridOrigin()
{
    return m_minY != -30000 && m_minX != -30000;
}

// UID:00023E | by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md | Completion:88 | Confidence:90
// ObjectList categorize and lookup aggregate; exact child pages own emitted method bodies.
[[No Children Attached]]

// UID:0002C9 | by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md | Completion:91 | Confidence:93
void ObjectList::AddObjectPane(ObjectPane *object)
{
    if (object == NULL)
        return;

    List *targetList = NULL;
    bool rowBucket = false;
    bool requireBounds = true;
    int bottomPadding = 2;

    switch (object->m_objectType) {
    case kObjectPaneTypeItem:
        targetList = m_itemObjects;
        break;
    case kObjectPaneTypeFlying:
        targetList = m_flyingObjects;
        break;
    case kObjectPaneTypePrimaryEffect:
        rowBucket = true;
        break;
    case kObjectPaneTypeLiving:
        rowBucket = true;
        break;
    case kObjectPaneTypeSecondaryEffect:
        rowBucket = true;
        break;
    case kObjectPaneTypeStatic:
        rowBucket = true;
        bottomPadding = 10;
        break;
    case kObjectPaneTypeBalloon:
        targetList = m_balloonObjects;
        break;
    case kObjectPaneTypeHitBar:
        targetList = m_hitBarObjects;
        break;
    case kObjectPaneTypeDamageNumber:
        targetList = m_damageNumberObjects;
        break;
    case kObjectPaneTypeObjectInfo:
        targetList = m_objectInfoObjects;
        break;
    case kObjectPaneTypeLighting:
        targetList = m_lightingObjects;
        break;
    case kObjectPaneTypeSound:
        targetList = m_soundObjects;
        requireBounds = false;
        break;
    default:
        return;
    }

    MapPoint position;
    object->GetMapPosition(&position);

    RectBounds bounds;
    if (requireBounds) {
        InitRectBounds(&bounds,
                       m_minX - 2,
                       m_minY - 2,
                       m_minX + m_gridWidth + 2,
                       m_minY + m_gridHeight + bottomPadding);

        if (!PointInRect(position.row, position.column, &bounds))
            return;
    }

    if (rowBucket) {
        int rowIndex = position.row - bounds.top;

        switch (object->m_objectType) {
        case kObjectPaneTypePrimaryEffect:
            targetList = m_primaryEffectRows[rowIndex];
            break;
        case kObjectPaneTypeLiving:
            targetList = m_livingObjectRows[rowIndex];
            break;
        case kObjectPaneTypeSecondaryEffect:
            targetList = m_secondaryEffectRows[rowIndex];
            break;
        case kObjectPaneTypeStatic:
            targetList = m_staticObjectRows[rowIndex];
            break;
        }
    }

    int insertIndex = 0;
    int count = targetList->GetCount();

    while (insertIndex < count) {
        ObjectPane *existing =
            *static_cast<ObjectPane **>(targetList->GetElementAt(insertIndex));

        MapPoint existingPosition;
        existing->GetMapPosition(&existingPosition);

        if (rowBucket) {
            if (position.column < existingPosition.column)
                break;
        } else {
            if (position.row < existingPosition.row ||
                (position.row == existingPosition.row &&
                 position.column < existingPosition.column)) {
                break;
            }
        }

        ++insertIndex;
    }

    targetList->InsertAt(insertIndex, 1, &object);
}

// UID:0002CA | by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md | Completion:91 | Confidence:93
void ObjectList::RemoveObjectPane(ObjectPane *object)
{
    if (object == NULL)
        return;

    List *targetList = NULL;
    List **rowLists = NULL;
    bool rowBucket = false;
    bool fallbackRows = false;
    int bottomPadding = 2;

    switch (object->m_objectType) {
    case kObjectPaneTypeItem:
        targetList = m_itemObjects;
        break;
    case kObjectPaneTypeFlying:
        targetList = m_flyingObjects;
        break;
    case kObjectPaneTypePrimaryEffect:
        rowLists = m_primaryEffectRows;
        rowBucket = true;
        fallbackRows = true;
        break;
    case kObjectPaneTypeLiving:
        rowLists = m_livingObjectRows;
        rowBucket = true;
        fallbackRows = true;
        break;
    case kObjectPaneTypeSecondaryEffect:
        rowLists = m_secondaryEffectRows;
        rowBucket = true;
        fallbackRows = true;
        break;
    case kObjectPaneTypeStatic:
        rowLists = m_staticObjectRows;
        rowBucket = true;
        bottomPadding = 10;
        break;
    case kObjectPaneTypeBalloon:
        targetList = m_balloonObjects;
        break;
    case kObjectPaneTypeHitBar:
        targetList = m_hitBarObjects;
        break;
    case kObjectPaneTypeDamageNumber:
        targetList = m_damageNumberObjects;
        break;
    case kObjectPaneTypeObjectInfo:
        targetList = m_objectInfoObjects;
        break;
    case kObjectPaneTypeLighting:
        targetList = m_lightingObjects;
        break;
    case kObjectPaneTypeSound:
        targetList = m_soundObjects;
        break;
    default:
        return;
    }

    if (rowBucket) {
        MapPoint position;
        object->GetMapPosition(&position);

        RectBounds bounds;
        InitRectBounds(&bounds,
                       m_minX - 2,
                       m_minY - 2,
                       m_minX + m_gridWidth + 2,
                       m_minY + m_gridHeight + bottomPadding);

        if (PointInRect(position.row, position.column, &bounds)) {
            List *rowList = rowLists[position.row - bounds.top];
            int count = rowList->GetCount();

            for (int index = 0; index < count; ++index) {
                ObjectPane *existing =
                    *static_cast<ObjectPane **>(rowList->GetElementAt(index));

                if (existing == object) {
                    rowList->RemoveAt(index, 1);
                    return;
                }
            }
        }

        if (!fallbackRows)
            return;

        int rowCount = m_gridHeight + 4;
        for (int rowIndex = rowCount - 1; rowIndex >= 0; --rowIndex) {
            List *rowList = rowLists[rowIndex];
            int count = rowList->GetCount();

            for (int index = 0; index < count; ++index) {
                ObjectPane *existing =
                    *static_cast<ObjectPane **>(rowList->GetElementAt(index));

                if (existing == object) {
                    rowList->RemoveAt(index, 1);
                    return;
                }
            }
        }

        return;
    }

    int count = targetList->GetCount();
    for (int index = 0; index < count; ++index) {
        ObjectPane *existing =
            *static_cast<ObjectPane **>(targetList->GetElementAt(index));

        if (existing == object) {
            targetList->RemoveAt(index, 1);
            return;
        }
    }
}

// UID:0002CB | by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md | Completion:91 | Confidence:93
ObjectPane *ObjectList::ResolveObjectListKey(ObjectListKey key)
{
    unsigned char keyType;
    short rowSelector;
    unsigned int index;

    DecodeObjectListKey(key, &keyType, &rowSelector, &index);

    switch (keyType) {
    case 0:
        return *static_cast<ObjectPane **>(m_itemObjects->GetElementAt(index));
    case 1:
        return *static_cast<ObjectPane **>(m_flyingObjects->GetElementAt(index));
    case 2:
        return *static_cast<ObjectPane **>(
            m_primaryEffectRows[rowSelector]->GetElementAt(index));
    case 3:
        return *static_cast<ObjectPane **>(
            m_livingObjectRows[rowSelector]->GetElementAt(index));
    case 4:
        return *static_cast<ObjectPane **>(
            m_secondaryEffectRows[rowSelector]->GetElementAt(index));
    case 5:
        return *static_cast<ObjectPane **>(
            m_staticObjectRows[rowSelector]->GetElementAt(index));
    case 6:
        return *static_cast<ObjectPane **>(m_balloonObjects->GetElementAt(index));
    case 7:
        return *static_cast<ObjectPane **>(m_hitBarObjects->GetElementAt(index));
    case 8:
        return *static_cast<ObjectPane **>(m_damageNumberObjects->GetElementAt(index));
    case 9:
        return *static_cast<ObjectPane **>(m_objectInfoObjects->GetElementAt(index));
    default:
        return NULL;
    }
}

// UID:0002CC | by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md | Completion:92 | Confidence:94
ObjectListKey ObjectList::GetTypedObjectKey(ObjectPane *object)
{
    switch (object->m_objectType) {
    case kObjectPaneTypeItem:
        return FindItemObjectKey(object);
    case kObjectPaneTypeFlying:
        return FindFlyingObjectKey(object);
    case kObjectPaneTypePrimaryEffect:
        return FindPrimaryEffectObjectKey(object);
    case kObjectPaneTypeLiving:
        return FindLivingObjectKey(object);
    case kObjectPaneTypeSecondaryEffect:
        return FindSecondaryEffectObjectKey(object);
    case kObjectPaneTypeStatic:
        return FindStaticObjectKey(object);
    case kObjectPaneTypeBalloon:
        return FindBalloonObjectKey(object);
    case kObjectPaneTypeHitBar:
        return FindHitBarObjectKey(object);
    case kObjectPaneTypeDamageNumber:
        return FindDamageNumberObjectKey(object);
    default:
        return kObjectListKeyNotFound;
    }
}

// UID:0002CD | by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md | Completion:90 | Confidence:91
ObjectPane *ObjectList::FindByObjectId(int objectId)
{
    short rowCount = static_cast<short>(m_gridHeight + 4);

    for (short rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        List *targetList = m_livingObjectRows[rowIndex];
        int count = targetList->GetCount();

        for (int index = 0; index < count; ++index) {
            ObjectPane *object =
                *static_cast<ObjectPane **>(targetList->GetElementAt(index));

            if (object->m_objectId == objectId)
                return object;
        }
    }

    int itemCount = m_itemObjects->GetCount();
    for (int index = 0; index < itemCount; ++index) {
        ObjectPane *object =
            *static_cast<ObjectPane **>(m_itemObjects->GetElementAt(index));

        if (object->m_objectId == objectId)
            return object;
    }

    int flyingCount = m_flyingObjects->GetCount();
    for (int index = 0; index < flyingCount; ++index) {
        ObjectPane *object =
            *static_cast<ObjectPane **>(m_flyingObjects->GetElementAt(index));

        if (object->m_objectId == objectId)
            return object;
    }

    return NULL;
}

// UID:0002CE | by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md | Completion:91 | Confidence:92
bool ObjectList::ContainsTypedObject(ObjectPane *object)
{
    switch (object->m_objectType) {
    case kObjectPaneTypeItem:
        return FindItemObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypeFlying:
        return FindFlyingObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypePrimaryEffect:
        return FindPrimaryEffectObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypeLiving:
        return FindLivingObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypeSecondaryEffect:
        return FindSecondaryEffectObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypeStatic:
        return FindStaticObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypeBalloon:
        return FindBalloonObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypeHitBar:
        return FindHitBarObjectKey(object) != kObjectListKeyNotFound;
    case kObjectPaneTypeDamageNumber:
        return FindDamageNumberObjectKey(object) != kObjectListKeyNotFound;
    default:
        return false;
    }
}

// UID:0001D2 | by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md | Completion:92 | Confidence:93
List *ObjectList::GetPrimaryCellList()
{
    return m_itemObjects;
}

List *ObjectList::GetSecondaryCellList()
{
    return m_flyingObjects;
}

List *ObjectList::GetPrimaryRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);
    return m_primaryEffectRows[row - bounds.top];
}

List *ObjectList::GetSecondaryRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);
    return m_secondaryEffectRows[row - bounds.top];
}

List *ObjectList::GetVisibleObjectList()
{
    return m_balloonObjects;
}

List *ObjectList::GetSecondaryGlobalList()
{
    return m_hitBarObjects;
}

List *ObjectList::GetAlternateGlobalList()
{
    return m_damageNumberObjects;
}

List *ObjectList::GetTertiaryGlobalList()
{
    return m_objectInfoObjects;
}

List *ObjectList::GetQuaternaryGlobalList()
{
    return m_lightingObjects;
}

List *ObjectList::GetQuinaryGlobalList()
{
    return m_soundObjects;
}

List *ObjectList::GetFrontRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);
    return m_livingObjectRows[row - bounds.top];
}

List *ObjectList::GetBackRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 10);
    return m_staticObjectRows[row - bounds.top];
}

// UID:0001D3 | by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md | Completion:89 | Confidence:92
// ObjectList accessor and sweep aggregate; exact child pages own emitted method bodies.
[[No Children Attached]]

// UID:0004SI | by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md | Completion:90 | Confidence:93
StaticObjectPane *ObjectList::FindStaticObjectPaneAt(int tileX, int tileY)
{
    RectBounds paddedBounds;
    InitRectBounds(
        &paddedBounds,
        m_minX - 2,
        m_minY - 2,
        m_minX + m_gridWidth + 2,
        m_minY + m_gridHeight + 10);

    List *row = m_staticObjectRows[tileY - paddedBounds.top];
    const int count = row->GetCount();
    for (int index = 0; index < count; ++index)
    {
        StaticObjectPane *objectPane =
            *static_cast<StaticObjectPane **>(row->GetElementAt(index));
        MapPoint position;
        objectPane->GetMapPosition(&position);
        if (position.column == tileX && position.row == tileY)
            return objectPane;
    }

    return NULL;
}

// UID:00023F | by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md | Completion:90 | Confidence:92
// ObjectList extended helper aggregate; exact child and split pages own emitted method bodies.
[[No Children Attached]]

// UID:0002BA | by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md | Completion:88 | Confidence:90
// Mixed ObjectList encoded-key and bounds helper island; split the live decoder before emitting source.

// UID:0002BB | by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md | Completion:92 | Confidence:94
ObjectListKey ObjectList::FindStaticObjectKey(ObjectPane *object)
{
    MapPoint position;
    object->GetMapPosition(&position);

    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 10);

    int rowIndex = position.row - bounds.top;
    List *list = m_staticObjectRows[rowIndex];
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   ((static_cast<ObjectListKey>(static_cast<unsigned char>(rowIndex)) |
                     0x5000u) << 16);
        }
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindLivingObjectKey(ObjectPane *object)
{
    MapPoint position;
    object->GetMapPosition(&position);

    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);

    int rowIndex = position.row - bounds.top;
    List *list = m_livingObjectRows[rowIndex];
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   ((static_cast<ObjectListKey>(static_cast<unsigned char>(rowIndex)) |
                     0x3000u) << 16);
        }
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindItemObjectKey(ObjectPane *object)
{
    List *list = m_itemObjects;
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object)
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index));
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindFlyingObjectKey(ObjectPane *object)
{
    List *list = m_flyingObjects;
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   0x10000000u;
        }
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindPrimaryEffectObjectKey(ObjectPane *object)
{
    MapPoint position;
    object->GetMapPosition(&position);

    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);

    int rowIndex = position.row - bounds.top;
    List *list = m_primaryEffectRows[rowIndex];
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   ((static_cast<ObjectListKey>(static_cast<unsigned char>(rowIndex)) |
                     0x2000u) << 16);
        }
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindSecondaryEffectObjectKey(ObjectPane *object)
{
    MapPoint position;
    object->GetMapPosition(&position);

    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);

    int rowIndex = position.row - bounds.top;
    List *list = m_secondaryEffectRows[rowIndex];
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   ((static_cast<ObjectListKey>(static_cast<unsigned char>(rowIndex)) |
                     0x2000u) << 16);
        }
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindBalloonObjectKey(ObjectPane *object)
{
    List *list = m_balloonObjects;
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   0x60000000u;
        }
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindHitBarObjectKey(ObjectPane *object)
{
    List *list = m_hitBarObjects;
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   0x70000000u;
        }
    }

    return kObjectListKeyNotFound;
}

ObjectListKey ObjectList::FindDamageNumberObjectKey(ObjectPane *object)
{
    List *list = m_damageNumberObjects;
    int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *entry =
            *static_cast<ObjectPane **>(list->GetElementAt(index));

        if (entry == object) {
            return static_cast<ObjectListKey>(static_cast<unsigned short>(index)) |
                   0xc0000000u;
        }
    }

    return kObjectListKeyNotFound;
}

// UID:0002BC | by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md | Completion:86 | Confidence:88
// ObjectList tier helper cluster retained as a combined no-code island; active dispatcher bodies own source.

// UID:0001D4 | by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Emitted code for this range is covered by [UID:00009Q][ObjectList](by-class/ObjectList.md).

// UID:0002OF | by-memory/0x00620284-0x00620294.ObjectListVtableData.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:00009Q][ObjectList](by-class/ObjectList.md).

// UID:0001VG | by-type/by-struct/ObjectListLayout.md | Completion:92 | Confidence:94
// ObjectList layout is represented by the ObjectList class fields and exact method children.

// UID:0001YB | by-type/by-vtable/ObjectList_vtable.md | Completion:92 | Confidence:94
// Emitted code for this vtable is covered by [UID:00009Q][ObjectList](by-class/ObjectList.md).

// UID:0003IO | by-memory\0x0061e6f8-0x0061e700.SharedGmWideString.md | Completion:88 | Confidence:93 | Empty Emitter Marker
