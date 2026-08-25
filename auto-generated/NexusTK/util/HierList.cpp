// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JV
// Source by-file doc: by-file/HierList.md
// UID:000065 | by-class/HierList.md | Completion:91 | Confidence:92
struct HierListNode;

class HierList : public List {
    friend class Layer;

public:
    HierList(int payloadSize, HierListNode *ownerNode);
    virtual ~HierList();

    void InsertLast(const void *parentPayload, const void *payload);
    void InsertFirst(const void *parentPayload, const void *payload);
    void InsertBefore(const void *parentPayload,
        const void *referencePayload, const void *payload);
    void InsertAfter(const void *parentPayload,
        const void *referencePayload, const void *payload);
    void RemoveByPayload(const void *payload);

    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void SwapElements(int firstIndex, int secondIndex);

protected:
    HierListNode *ownerNode;

private:
    HierListNode *FindNodeByPayload(const void *payload,
        HierList **outOwnerList, int *outIndex);
    void UpdateHierarchy(int firstIndex, int lastIndex, bool clearParent);

    // UID:0002I8 | by-memory/0x004ce730-0x004ce760.HierListConstructor.md | Completion:90 | Confidence:92
HierList::HierList(int payloadSize, HierListNode *owner)
    : List(payloadSize + 11, 32),
      ownerNode(owner)
{
    owner->childList = this;
}

// UID:0002I9 | by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md | Completion:90 | Confidence:92
HierList::~HierList()
{
    for (int index = 0; index < m_count; ++index) {
        HierListNode *node = static_cast<HierListNode *>(List::GetElementAt(index));
        if (node->childList != NULL) {
            delete node->childList;
            node->childList = NULL;
        }
    }
}

// UID:0002IA | by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md | Completion:90 | Confidence:91
void HierList::InsertLast(const void *parentPayload, const void *payload)
{
    if (parentPayload == NULL) {
        HierListNode *lastNode = static_cast<HierListNode *>(List::GetElementAt(m_count - 1));
        InsertBefore(NULL, lastNode->payload, payload);
        return;
    }

    HierListNode *parentNode = FindNodeByPayload(parentPayload, NULL, NULL);
    HierList *childList = parentNode->childList;
    if (childList != NULL && childList->m_count != 0) {
        HierListNode *lastChild =
            static_cast<HierListNode *>(childList->List::GetElementAt(childList->m_count - 1));
        InsertBefore(parentPayload, lastChild->payload, payload);
    } else {
        InsertBefore(parentPayload, NULL, payload);
    }
}

// UID:0002IB | by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md | Completion:88 | Confidence:91
void HierList::InsertFirst(const void *parentPayload, const void *payload)
{
    InsertBefore(parentPayload, NULL, payload);
}

// UID:0002IC | by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md | Completion:90 | Confidence:92
void HierList::InsertBefore(const void *parentPayload, const void *referencePayload, const void *payload)
{
    MemoryMan *memoryMan = GetMemoryMan();
    HierListNode *node =
        static_cast<HierListNode *>(memoryMan->AllocateBufferMemory(m_elementSize));
    node->childList = NULL;
    memoryMan->MemmoveWrapper(node->payload, payload, m_elementSize - 11);

    int referenceIndex;
    if (parentPayload == NULL) {
        HierList *referenceOwnerList;
        if (referencePayload != NULL) {
            FindNodeByPayload(referencePayload, &referenceOwnerList, &referenceIndex);
        } else {
            referenceOwnerList = this;
            referenceIndex = -1;
        }

        node->parent = ownerNode;
        InsertAt(referenceIndex + 1, 1, node);
    } else {
        HierListNode *parentNode = FindNodeByPayload(parentPayload, NULL, NULL);
        HierList *childList = parentNode->childList;
        if (childList == NULL) {
            childList = new HierList(m_elementSize - 11, parentNode);
        }

        if (referencePayload != NULL) {
            FindNodeByPayload(referencePayload, NULL, &referenceIndex);
        } else {
            referenceIndex = -1;
        }

        node->parent = parentNode;
        childList->InsertAt(referenceIndex + 1, 1, node);
    }

    memoryMan->FreeBufferMemory(node);
}

// UID:0002ID | by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md | Completion:90 | Confidence:92
void HierList::InsertAfter(const void *parentPayload, const void *referencePayload, const void *payload)
{
    MemoryMan *memoryMan = GetMemoryMan();
    HierListNode *node =
        static_cast<HierListNode *>(memoryMan->ZeroAllocateBufferMemory(m_elementSize));
    node->childList = NULL;
    memoryMan->MemmoveWrapper(node->payload, payload, m_elementSize - 11);

    int referenceIndex;
    if (parentPayload == NULL) {
        HierList *referenceOwnerList;
        if (referencePayload != NULL) {
            FindNodeByPayload(referencePayload, &referenceOwnerList, &referenceIndex);
        } else {
            referenceOwnerList = this;
            referenceIndex = m_count - 1;
        }
        node->parent = ownerNode;
        InsertAt(referenceIndex + 1, 1, node);
    } else {
        HierListNode *parentNode = FindNodeByPayload(parentPayload, NULL, NULL);
        HierList *childList = parentNode->childList;
        if (childList == NULL) {
            childList = new HierList(m_elementSize - 11, parentNode);
        }
        if (referencePayload != NULL) {
            FindNodeByPayload(referencePayload, NULL, &referenceIndex);
        } else {
            referenceIndex = childList->m_count - 1;
        }
        node->parent = parentNode;
        childList->InsertAt(referenceIndex + 1, 1, node);
    }

    memoryMan->FreeBufferMemory(node);
}

// UID:0002IE | by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md | Completion:90 | Confidence:92
void HierList::RemoveByPayload(const void *payload)
{
    HierList *ownerList;
    int index;
    HierListNode *node = FindNodeByPayload(payload, &ownerList, &index);
    if (node == NULL) {
        return;
    }

    if (node->childList != NULL) {
        delete node->childList;
        node->childList = NULL;
    }

    ownerList->RemoveAt(index, 1);
}

// UID:0002IF | by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md | Completion:90 | Confidence:92
void *HierList::GetElementAt(int index)
{
    return static_cast<unsigned char *>(List::GetElementAt(index)) + 8;
}

// UID:0002IG | by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md | Completion:90 | Confidence:92
void HierList::InsertAt(int index, int count, void *source)
{
    int oldCount = m_count;
    List::InsertAt(index, count, source);
    if (oldCount > index) {
        UpdateHierarchy(index + count, m_count - 1, false);
    }
}

// UID:0002IH | by-memory/0x004cebb0-0x004cebb9.HierListAppend.md | Completion:89 | Confidence:92
void HierList::Append(int count, void *source)
{
    List::Append(count, source);
}

// UID:0002II | by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md | Completion:90 | Confidence:92
void HierList::RemoveAt(int index, int count)
{
    List::RemoveAt(index, count);
    if (index <= m_count - 1) {
        UpdateHierarchy(index, m_count - 1, false);
    }
}

// UID:0002IJ | by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md | Completion:90 | Confidence:92
void HierList::SwapElements(int firstIndex, int secondIndex)
{
    List::SwapElements(firstIndex, secondIndex);
    UpdateHierarchy(firstIndex, firstIndex, false);
    UpdateHierarchy(secondIndex, secondIndex, false);
}

// UID:0002IK | by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md | Completion:91 | Confidence:92
HierListNode *HierList::FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex)
{
    const int payloadSize = m_elementSize - 11;

    for (int index = 0; index < m_count; ++index) {
        HierListNode *node = static_cast<HierListNode *>(List::GetElementAt(index));
        if (memcmp(payload, node->payload, payloadSize) == 0) {
            if (outOwnerList != NULL) {
                *outOwnerList = this;
            }
            if (outIndex != NULL) {
                *outIndex = index;
            }
            return node;
        }

        if (node->childList != NULL) {
            HierListNode *found = node->childList->FindNodeByPayload(payload, outOwnerList, outIndex);
            if (found != NULL) {
                return found;
            }
        }
    }

    return NULL;
}

// UID:0002IL | by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md | Completion:90 | Confidence:92
void HierList::UpdateHierarchy(int firstIndex, int lastIndex, bool clearParent)
{
    for (int index = firstIndex; index <= lastIndex; ++index) {
        HierListNode *node = static_cast<HierListNode *>(List::GetElementAt(index));
        HierList *childList = node->childList;
        if (childList == NULL) {
            continue;
        }

        HierListNode *parentNode = clearParent ? NULL : node;
        childList->ownerNode = parentNode;

        for (int childIndex = 0; childIndex < childList->m_count; ++childIndex) {
            HierListNode *childNode =
                static_cast<HierListNode *>(childList->List::GetElementAt(childIndex));
            childNode->parent = parentNode;
        }
    }
}

// UID:0003BL | by-memory/0x0061b340-0x0061b36c.HierListVtableData.md | Completion:88 | Confidence:92
/* NC-0003BL: HierList vtable/RTTI data is compiler-generated from the
   HierList class declaration, destructor, and virtual method set. Do not
   hand-port the .rdata dwords as handwritten C++; source reconstruction
   belongs to the class declaration and exact method pages. */

// UID:0001UQ | by-type/by-struct/HierListNode.md | Completion:90 | Confidence:92
struct HierListNode {
    HierListNode *parent;
    HierList *childList;
    unsigned char payload[1];
};
};
