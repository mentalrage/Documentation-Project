// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M4
// Source by-file doc: by-file/ObjectList.md
// UID:00009Q | by-class/ObjectList.md | Completion:92 | Confidence:93
#ifndef NEXUSTK_MAP_OBJECTLIST_H
#define NEXUSTK_MAP_OBJECTLIST_H

#include "../util/LObject.h"

typedef unsigned int ObjectListKey;

class List;
class ObjectPane;
class StaticObjectPane;

class ObjectList : public LObject
{
public:
    ObjectList(int gridWidth, int gridHeight);
    virtual ~ObjectList();

    bool HasValidGridOrigin();
    void AddObjectPane(ObjectPane *object);
    void RemoveObjectPane(ObjectPane *object);
    ObjectPane *ResolveObjectListKey(ObjectListKey key);
    ObjectListKey GetTypedObjectKey(ObjectPane *object);
    ObjectPane *FindByObjectId(int objectId);
    bool ContainsTypedObject(ObjectPane *object);
    void DetachAll(ObjectPane *preserveObject);
    void PruneMarkedRowObjects();
    void MarkVisibleObjectsForRefresh();
    void RemoveMarkedVisibleObjects();
    void RefreshStaticObjectLighting(unsigned short staticObjectId);

    List *GetPrimaryCellList();
    List *GetSecondaryCellList();
    List *GetPrimaryRowBucket(int row);
    List *GetSecondaryRowBucket(int row);
    List *GetVisibleObjectList();
    List *GetSecondaryGlobalList();
    List *GetAlternateGlobalList();
    List *GetTertiaryGlobalList();
    List *GetQuaternaryGlobalList();
    List *GetQuinaryGlobalList();
    List *GetFrontRowBucket(int row);
    List *GetBackRowBucket(int row);
    StaticObjectPane *FindStaticObjectPaneAt(int tileX, int tileY);

private:
    static const ObjectListKey kObjectListKeyNotFound = 0xffffffffu;

    ObjectListKey FindStaticObjectKey(ObjectPane *object);
    ObjectListKey FindLivingObjectKey(ObjectPane *object);
    ObjectListKey FindItemObjectKey(ObjectPane *object);
    ObjectListKey FindFlyingObjectKey(ObjectPane *object);
    ObjectListKey FindPrimaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindSecondaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindBalloonObjectKey(ObjectPane *object);
    ObjectListKey FindHitBarObjectKey(ObjectPane *object);
    ObjectListKey FindDamageNumberObjectKey(ObjectPane *object);

    int m_minX;
    int m_minY;
    int m_gridWidth;
    int m_gridHeight;
    List *m_itemObjects;
    List *m_flyingObjects;
    List **m_primaryEffectRows;
    List **m_secondaryEffectRows;
    List **m_livingObjectRows;
    List **m_staticObjectRows;
    List *m_balloonObjects;
    List *m_hitBarObjects;
    List *m_damageNumberObjects;
    List *m_objectInfoObjects;
    List *m_lightingObjects;
    List *m_soundObjects;
};

#endif
