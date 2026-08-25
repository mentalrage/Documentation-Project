// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KV
// Source by-file doc: by-file/LObject.md
// UID:00007D | by-class/LObject.md | Completion:93 | Confidence:93
#ifndef NEXUSTK_UTIL_LOBJECT_H
#define NEXUSTK_UTIL_LOBJECT_H

typedef unsigned int MessageType;

class LObject;
class Message;

struct RuntimeClass
{
    typedef LObject *(*CreateObjectProc)();

    const wchar_t *m_className;
    unsigned int m_objectSize;
    CreateObjectProc m_createObject;
    const RuntimeClass *m_baseClass;

    LObject *CreateObject() const;
    bool IsDerivedFrom(const RuntimeClass *runtimeClass) const;
};

class LObject
{
public:
    static const RuntimeClass s_runtimeClass;

    LObject();
    virtual ~LObject();
    virtual const RuntimeClass *GetRuntimeClass() const;
    virtual void OnChangeMessage(LObject *owner, Message *message);

    bool IsKindOf(const RuntimeClass *runtimeClass) const;
    void RegisterChangeListener(LObject *listener,
                                MessageType messageType,
                                bool allMessages);
    void UnregisterChangeListener(LObject *listener,
                                  MessageType messageType,
                                  bool allMessages);
    void ForwardMessage(Message *message);
};

#endif
