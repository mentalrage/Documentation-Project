// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KV
// Source by-file doc: by-file/LObject.md
// UID:00007D | by-class/LObject.md | Completion:93 | Confidence:93
// UID:0000WM | by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md | Completion:92 | Confidence:94
void LObject::OnChangeMessage(LObject *, Message *)
{
}

// UID:00036Z | by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md | Completion:88 | Confidence:92
LObject::LObject()
{
}

// UID:000370 | by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md | Completion:92 | Confidence:95
LObject::~LObject()
{
}

// UID:000371 | by-memory/0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor.md | Completion:93 | Confidence:94
const RuntimeClass *LObject::GetRuntimeClass() const
{
    return &s_runtimeClass;
}

// UID:000375 | by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md | Completion:92 | Confidence:93
bool LObject::IsKindOf(const RuntimeClass *runtimeClass) const
{
    return GetRuntimeClass()->IsDerivedFrom(runtimeClass);
}

// UID:000198 | by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md | Completion:92 | Confidence:94
void LObject::RegisterChangeListener(LObject *listener,
                                     MessageType messageType,
                                     bool allMessages)
{
    g_pChangeMan->Register(this, listener, messageType, allMessages);
}

// UID:00019A | by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md | Completion:93 | Confidence:94
void LObject::UnregisterChangeListener(LObject *listener,
                                       MessageType messageType,
                                       bool allMessages)
{
    g_pChangeMan->Unregister(this, listener, messageType, allMessages);
}

// UID:00019B | by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md | Completion:91 | Confidence:94
void LObject::ForwardMessage(Message *message)
{
    g_pChangeMan->DispatchMessage(this, message);
}

// UID:0003ON | by-memory/0x0061cf44-0x0061cf68.LObjectTypeNameData.md | Completion:93 | Confidence:94
const RuntimeClass LObject::s_runtimeClass =
{
    L"LObject",
    sizeof(LObject),
    0,
    0
};

// UID:0003OO | by-memory/0x0061cf68-0x0061cf74.LObjectVtableData.md | Completion:94 | Confidence:94
// The LObject primary-vtable slots at 0x0061cf68-0x0061cf74 are generated
// from the virtual declarations and definitions emitted through UID00007D.
// Do not hand-author a vtable array for this compiler-generated range.

// UID:00023R | by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md | Completion:92 | Confidence:93
LObject *RuntimeClass::CreateObject() const
{
    if (m_createObject != 0)
        return m_createObject();

    return 0;
}

bool RuntimeClass::IsDerivedFrom(const RuntimeClass *runtimeClass) const
{
    const RuntimeClass *currentClass = this;
    while (currentClass != 0)
    {
        if (currentClass == runtimeClass)
            return true;

        currentClass = currentClass->m_baseClass;
    }

    return false;
}
