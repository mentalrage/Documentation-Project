// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OB
// Source by-file doc: by-file/StringUtil.md
// UID:0002DV | by-memory/0x00421310-0x00421362.SimpleUStringClear.md | Completion:88 | Confidence:91
void SimpleUString::Clear()
{
    if (m_capacity >= 8) {
        void* storage = m_heapBuffer;
        unsigned int allocationSize = (m_capacity + 1) * sizeof(wchar_t);

        if (allocationSize >= 0x1000) {
            void* rawStorage = reinterpret_cast<void**>(storage)[-1];
            allocationSize += 0x23;

            if (static_cast<unsigned char*>(storage) -
                    static_cast<unsigned char*>(rawStorage) - sizeof(void*) > 0x1f) {
                _invalid_parameter_noinfo_noreturn();
            }

            storage = rawStorage;
        }

        FreeMemory(storage, allocationSize);
    }

    m_length = 0;
    m_capacity = 7;
    m_inlineBuffer[0] = L'\0';
}

// UID:0002E3 | by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md | Completion:88 | Confidence:90
SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)
{
    unsigned int oldCapacity = m_capacity;
    wchar_t *oldStorage = oldCapacity >= 8 ? m_heapBuffer : m_inlineBuffer;

    if (length <= oldCapacity) {
        m_length = length;
        memmove(oldStorage, source, length * sizeof(wchar_t));
        oldStorage[length] = L'\0';
        return *this;
    }

    if (length > 0x7ffffffe) {
        ThrowStringTooLong();
    }

    unsigned int newCapacity = length | 7;
    if (newCapacity > 0x7ffffffe) {
        newCapacity = 0x7ffffffe;
    } else {
        unsigned int halfCapacity = oldCapacity >> 1;

        if (oldCapacity > 0x7ffffffe - halfCapacity) {
            newCapacity = 0x7ffffffe;
        } else {
            unsigned int grownCapacity = oldCapacity + halfCapacity;
            if (newCapacity < grownCapacity) {
                newCapacity = grownCapacity;
            }
        }
    }

    unsigned int allocationSize = (newCapacity + 1) * sizeof(wchar_t);
    wchar_t *newStorage = NULL;

    if (allocationSize >= 0x1000) {
        unsigned int requestSize = allocationSize + 0x23;
        if (requestSize < allocationSize) {
            requestSize = 0xffffffff;
        }

        void *rawStorage = operator new(requestSize);
        if (rawStorage == NULL) {
            _invalid_parameter_noinfo_noreturn();
        }

        newStorage = reinterpret_cast<wchar_t *>(
            (reinterpret_cast<unsigned int>(rawStorage) + 0x23) & 0xffffffe0);
        reinterpret_cast<void **>(newStorage)[-1] = rawStorage;
    } else if (allocationSize != 0) {
        newStorage = static_cast<wchar_t *>(operator new(allocationSize));
    }

    m_capacity = newCapacity;
    m_length = length;
    memmove(newStorage, source, length * sizeof(wchar_t));
    newStorage[length] = L'\0';

    if (oldCapacity >= 8) {
        unsigned int oldAllocationSize = (oldCapacity + 1) * sizeof(wchar_t);
        void *freeStorage = oldStorage;

        if (oldAllocationSize >= 0x1000) {
            void *rawStorage = reinterpret_cast<void **>(freeStorage)[-1];
            oldAllocationSize += 0x23;

            if (static_cast<unsigned char *>(freeStorage) -
                    static_cast<unsigned char *>(rawStorage) - sizeof(void *) > 0x1f) {
                _invalid_parameter_noinfo_noreturn();
            }

            freeStorage = rawStorage;
        }

        FreeMemory(freeStorage, oldAllocationSize);
    }

    m_heapBuffer = newStorage;
    return *this;
}

// UID:0002U5 | by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md | Completion:87 | Confidence:90
// Internal SimpleUString SSO-7 narrow-range to UTF-16 append helper. The
// binary helper cleans three stack arguments but reads only the half-open
// source range; caller evidence shows the third value is an unused tag/context
// artifact, so no standalone source method is emitted for this exact range.

// UID:0001W5 | by-type/by-struct/SimpleUStringSso7Layout.md | Completion:90 | Confidence:93
// SimpleUString SSO-7 layout evidence is emitted by the SimpleUString class
// declaration; this page records offset and storage-policy proof only and
// should not emit a duplicate struct.

// UID:0000DA | by-class/SimpleUStringVector.md | Completion:88 | Confidence:89
#include "StringUtil.h"

// UID:000112 | by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md | Completion:88 | Confidence:90
SimpleUStringVector::~SimpleUStringVector()
{
    SimpleUStringHandle *slot = m_begin;
    if (slot == NULL)
        return;

    while (slot != m_end) {
        ReleaseWideStringHandle(slot);
        ++slot;
    }

    FreeStringHandleVectorStorage(m_begin,
                                  static_cast<unsigned int>(m_capacity - m_begin));
    m_begin = NULL;
    m_end = NULL;
    m_capacity = NULL;
}

// UID:00012G | by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md | Completion:89 | Confidence:90
SimpleUStringHandle *SimpleUStringVector::GrowAndInsert(
    SimpleUStringHandle *position,
    const SimpleUStringHandle *value)
{
    unsigned int size = static_cast<unsigned int>(m_end - m_begin);
    unsigned int insertIndex = static_cast<unsigned int>(position - m_begin);

    if (size == 0x3fffffff)
        ThrowVectorTooLong();

    unsigned int oldCapacity = static_cast<unsigned int>(m_capacity - m_begin);
    unsigned int newCapacity = size + 1;
    if (oldCapacity <= 0x3fffffff - (oldCapacity >> 1)) {
        unsigned int grownCapacity = oldCapacity + (oldCapacity >> 1);
        if (newCapacity < grownCapacity)
            newCapacity = grownCapacity;
    }

    SimpleUStringHandle *newBegin = AllocateStringHandleVectorStorage(newCapacity);
    SimpleUStringHandle *newPosition = newBegin + insertIndex;

    ConstructWideStringHandle(newPosition, value);
    CopyConstructWideStringHandleRange(m_begin, position, newBegin);
    CopyConstructWideStringHandleRange(position, m_end, newPosition + 1);

    for (SimpleUStringHandle *slot = m_begin; slot != m_end; ++slot)
        ReleaseWideStringHandle(slot);

    FreeStringHandleVectorStorage(m_begin, oldCapacity);

    m_begin = newBegin;
    m_end = newBegin + size + 1;
    m_capacity = newBegin + newCapacity;
    return m_begin + insertIndex;
}

// UID:0001J4 | by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md | Completion:89 | Confidence:90
void SimpleUStringVector::PushBack(const SimpleUStringHandle *value)
{
    if (m_end == m_capacity) {
        GrowAndInsert(m_end, value);
        return;
    }

    CopyConstructWideStringHandle(m_end, value);
    ++m_end;
}

// UID:0001W6 | by-type/by-struct/SimpleUStringVectorLayout.md | Completion:87 | Confidence:90
// SimpleUStringVector layout is emitted by the SimpleUStringVector class
// declaration; this page records the begin/end/capacity offsets and 4-byte
// string-handle slot proof only and should not emit a duplicate struct.

// UID:0000E7 | by-class/StringIter.md | Completion:88 | Confidence:89
#include "../util/StringUtil.h"

[[No Children Attached]]

// UID:0000PW | by-global/g_emptySimpleUString.md | Completion:92 | Confidence:93
SimpleUString g_emptySimpleUString;

// UID:0003MS | by-global/StaticSimpleUStringVector_69B39C.md | Completion:88 | Confidence:90
// Reconstructed descriptive name; original variable spelling is not recovered.
static std::vector<SimpleUString> StaticSimpleUStringVector_69B39C;

// UID:0001ZY | by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md | Completion:89 | Confidence:89
struct WideStringMapNode
{
    WideStringMapNode *left;
    WideStringMapNode *parent;
    WideStringMapNode *right;
    unsigned char color;
    unsigned char isSentinel;
    unsigned char reserved[2];
    SimpleUString key;
    int value;
};

static WideStringMapNode *CreateWideStringMapSentinel()
{
    WideStringMapNode *node = static_cast<WideStringMapNode *>(
        operator new(sizeof(WideStringMapNode)));
    node->left = node;
    node->parent = node;
    node->right = node;
    node->color = 1;
    node->isSentinel = 1;
    return node;
}

static WideStringMapNode *CreateWideStringMapNodeFromHeader(WideStringMapNode *header)
{
    WideStringMapNode *node = static_cast<WideStringMapNode *>(
        operator new(sizeof(WideStringMapNode)));
    node->left = header->left;
    node->parent = header->left;
    node->right = header->left;
    return node;
}

static void DestroyWideStringMapNodes(WideStringMapNode *node)
{
    while (!node->isSentinel) {
        DestroyWideStringMapNodes(node->right);
        WideStringMapNode *next = node->left;
        node->key.Clear();
        FreeMemory(node);
        node = next;
    }
}

static void FreeWideStringMapNode(WideStringMapNode *node)
{
    FreeMemory(node);
}

// UID:0001J5 | by-memory/0x00584d80-0x00584e9e.StringIter.md | Completion:88 | Confidence:90
StringIter::StringIter(const wchar_t *data, int length)
    : LObject(),
      m_data(data),
      m_length(length),
      m_position(0)
{
}

StringIter::StringIter(const wchar_t *data, int length, int startPosition)
    : LObject(),
      m_data(data),
      m_length(length),
      m_position(startPosition)
{
}

StringIter::~StringIter()
{
}

wchar_t StringIter::PeekCharAtOffset(int offset) const
{
    int index = m_position + offset;
    if (index >= m_length || index < 0)
        return 0;

    return m_data[index];
}

void StringIter::Advance(int count)
{
    m_position += count;
}

wchar_t StringIter::GetNextChar()
{
    if (m_position >= m_length)
        return 0;

    return m_data[m_position++];
}

// The scalar deleting destructor at 0x00584e60 is compiler-generated from
// StringIter::~StringIter() and the vtable; do not model it as a handwritten
// source method.

// UID:0000D9 | by-class\SimpleUString.md | Completion:90 | Confidence:92 | Empty Emitter Marker
