// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I2
// Source by-file doc: by-file/ChangeMan.md
// UID:00001K | by-class/ChangeMan.md | Completion:93 | Confidence:94
ChangeMan::~ChangeMan()
{
    delete m_changeList;
    m_changeList = NULL;
    g_pChangeMan = NULL;
}

// UID:0000ZW | by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md | Completion:92 | Confidence:94
void ChangeMan::Register(LObject *owner,
                         LObject *listener,
                         MessageType messageType,
                         bool allMessages)
{
    ChangeManEntry entry;
    entry.owner = owner;
    entry.listener = listener;
    entry.allMessages = allMessages;
    entry.messageType = messageType;

    m_changeList->InsertSorted(&entry);
}

// UID:0000ZT | by-memory/0x0047ec70-0x0047ed20.ChangeManConstructor.md | Completion:86 | Confidence:90
ChangeMan::ChangeMan()
    : LObject(),
      m_changeList(NULL)
{
    g_pChangeMan = this;
    m_changeList = new SortedList(sizeof(ChangeManEntry),
                                  CompareChangeEntries,
                                  100);
}

// UID:0000ZY | by-memory/0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered.md | Completion:91 | Confidence:94
void ChangeMan::Unregister(LObject *owner,
                           LObject *listener,
                           MessageType messageType,
                           bool allMessages)
{
    ChangeManEntry key;
    key.owner = owner;

    int index = m_changeList->FindFirstEqual(&key);
    if (index < 0)
        return;

    int count = m_changeList->GetCount();
    for (; index < count; ++index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry == NULL || entry->owner != owner)
            break;

        const bool listenerMatches =
            (listener == NULL || entry->listener == listener);
        const bool messageMatches =
            (allMessages == true) ||
            (allMessages == false && entry->messageType == messageType);

        if (listenerMatches && messageMatches) {
            m_changeList->RemoveRange(index, 1);
            --index;
            --count;
        }
    }
}

// UID:0000ZZ | by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md | Completion:92 | Confidence:94
void ChangeMan::DispatchMessage(LObject *owner, Message *message)
{
    ChangeManEntry key;
    key.owner = owner;

    int index = m_changeList->FindFirstEqual(&key);
    if (index < 0)
        return;

    int count = m_changeList->GetCount();
    for (; index < count; ++index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner != owner)
            break;

        if (entry->allMessages == true ||
            (entry->allMessages == false &&
             entry->messageType == message->m_type)) {
            entry->listener->OnChangeMessage(owner, message);
        }
    }
}

// UID:000100 | by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md | Completion:90 | Confidence:94
void ChangeMan::UnregisterObject(LObject *object)
{
    for (int index = m_changeList->GetCount() - 1; index >= 0; --index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner == object || entry->listener == object)
            m_changeList->RemoveRange(index, 1);
    }
}

// UID:0004I6 | by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md | Completion:90 | Confidence:93
bool ChangeMan::HasRegistrationForObject(LObject *object)
{
    for (int index = m_changeList->GetCount() - 1; index >= 0; --index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner == object || entry->listener == object)
            return true;
    }

    return false;
}

// UID:0001TV | by-type/by-struct/ChangeManEntry.md | Completion:92 | Confidence:94
struct ChangeManEntry {
    LObject *owner;
    LObject *listener;
    bool allMessages;
    MessageType messageType;
};

// UID:0001TW | by-type/by-struct/ChangeManLayout.md | Completion:92 | Confidence:94
class ChangeMan : public LObject {
public:
    ChangeMan();
    virtual ~ChangeMan();

    void Register(LObject *owner,
                  LObject *listener,
                  MessageType messageType,
                  bool allMessages);
    void Unregister(LObject *owner,
                    LObject *listener,
                    MessageType messageType,
                    bool allMessages);
    void DispatchMessage(LObject *owner, Message *message);
    void UnregisterObject(LObject *object);
    bool HasRegistrationForObject(LObject *object);

private:
    SortedList *m_changeList;
};

// UID:0001X7 | by-type/by-vtable/ChangeManVtable.md | Completion:86 | Confidence:91
// ChangeMan vtable bytes are generated from the ChangeMan virtual declaration
// and ordinary destructor. Exact slot data is documented by [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md);
// no handwritten vtable object should be emitted here.

// UID:0000QI | by-global/g_pChangeMan.md | Completion:91 | Confidence:90
ChangeMan *g_pChangeMan = NULL;

// UID:000101 | by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md | Completion:90 | Confidence:94
static int CompareChangeEntries(const void *left, const void *right)
{
    const ChangeManEntry *leftEntry =
        static_cast<const ChangeManEntry *>(left);
    const ChangeManEntry *rightEntry =
        static_cast<const ChangeManEntry *>(right);

    const uintptr_t leftOwner =
        reinterpret_cast<uintptr_t>(leftEntry->owner);
    const uintptr_t rightOwner =
        reinterpret_cast<uintptr_t>(rightEntry->owner);

    if (leftOwner < rightOwner)
        return -1;
    if (leftOwner > rightOwner)
        return 1;
    return 0;
}

// UID:0002M8 | by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md | Completion:86 | Confidence:91
// Exact ChangeMan vtable data at 0x00614cd0-0x00614cdc is generated by the
// compiler/linker from the ChangeMan class declaration and destructor. The
// three slot values are evidence, not a handwritten source table.

// UID:0001P4 | by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md | Completion:88 | Confidence:91
// Exact storage for g_pChangeMan is emitted by the semantic global declaration
// on [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md). This page documents the zero-initialized 0x0067ab2c storage
// and xref set without duplicating the source definition.
