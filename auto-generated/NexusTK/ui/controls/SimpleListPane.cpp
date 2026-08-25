// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NQ
// Source by-file doc: by-file/SimpleListPane.md
// UID:0000D8 | by-class/SimpleListPane.md | Completion:94 | Confidence:93
#include "SimpleListPane.h"

#include "../../util/MemoryMan.h"
#include "../core/RectBounds.h"

#include <wchar.h>

// UID:0001HP | by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md | Completion:94 | Confidence:93
SimpleListPane::SimpleListPane(int /*unused*/, const RectBounds *bounds)
    : ListPane(4,
               10,
               static_cast<unsigned short>(bounds->right - bounds->left),
               static_cast<unsigned short>(bounds->bottom - bounds->top),
               1,
               1,
               1)
{
}

// UID:000241 | by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md | Completion:94 | Confidence:93
// Emitted code for this aggregate is supplied by exact child ranges [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md)-[UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md).
// UID:0002LE | by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md | Completion:94 | Confidence:94
SimpleListPane::~SimpleListPane()
{
    for (int index = 0; index < GetItemCount(); ++index) {
        wchar_t **textSlot = static_cast<wchar_t **>(GetItem(index));
        if (*textSlot != NULL) {
            GetMemoryMan()->FreeBufferMemory(*textSlot);
            *textSlot = NULL;
        }
    }
}

// UID:0002LF | by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md | Completion:94 | Confidence:92
void SimpleListPane::AppendText(const wchar_t *text)
{
    const size_t textLength = wcslen(text);
    wchar_t *copiedText = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory((textLength + 1) * sizeof(wchar_t)));
    wcscpy_s(copiedText, textLength + 1, text);
    InsertItem(GetItemCount(), &copiedText);
}

// UID:0002LG | by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md | Completion:94 | Confidence:92
void SimpleListPane::InsertText(int index, const wchar_t *text)
{
    const size_t textLength = wcslen(text);
    wchar_t *copiedText = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory((textLength + 1) * sizeof(wchar_t)));
    wcscpy_s(copiedText, textLength + 1, text);
    InsertItem(index, &copiedText);
}

// UID:0002LH | by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md | Completion:94 | Confidence:92
void SimpleListPane::RemoveText(int index)
{
    wchar_t **textSlot = static_cast<wchar_t **>(GetItem(index));
    if (*textSlot != NULL) {
        GetMemoryMan()->FreeBufferMemory(*textSlot);
        *textSlot = NULL;
    }
    RemoveItems(index, 1);
}

// UID:0002LI | by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md | Completion:94 | Confidence:92
void SimpleListPane::ReplaceText(int index, const wchar_t *text)
{
    wchar_t **textSlot = static_cast<wchar_t **>(GetItem(index));
    if (*textSlot != NULL) {
        GetMemoryMan()->FreeBufferMemory(*textSlot);
        *textSlot = NULL;
    }
    RemoveItems(index, 1);

    const size_t textLength = wcslen(text);
    wchar_t *copiedText = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory((textLength + 1) * sizeof(wchar_t)));
    wcscpy_s(copiedText, textLength + 1, text);
    InsertItem(index, &copiedText);
}

// UID:0003D5 | by-memory/0x00624c60-0x00624d24.SimpleListPaneVtableData.md | Completion:94 | Confidence:98
// SimpleListPane RTTI and primary/adjusted vtables are compiler-generated
// from the virtual class declaration; no literal table source is emitted.

// UID:0001W3 | by-type/by-struct/SimpleListPaneLayout.md | Completion:94 | Confidence:95
// SimpleListPane has no source fields beyond the inherited ListPane layout;
// its exact 0x14c-byte shape is represented by the class declaration.
