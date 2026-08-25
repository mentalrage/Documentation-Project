// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KE
// Source by-file doc: by-file/ItemDialogs.md
// UID:00008W | by-class/MyItemListPane.md | Completion:92 | Confidence:93
#pragma once

#include "../controls/ListPane.h"
#include "../core/RectBounds.h"

// UID:0001VE | by-type/by-struct/MyItemListPaneEntryLayouts.md | Completion:90 | Confidence:92
struct MyItemListEntry
{
    unsigned char slotIndex;
    unsigned short itemId;
    unsigned char iconStyle;
    wchar_t displayName[256];
    unsigned char reservedTail[6];
};

typedef char MyItemListEntrySizeMustBe524[
    sizeof(MyItemListEntry) == 0x20c ? 1 : -1];

class MyItemListPane : public ListPane
{
public:
    MyItemListPane();
    unsigned char GetSelectedSlotIndex();

protected:
    virtual void DrawListEntry(
        int rowIndex,
        void *rowData,
        RectBounds *rowBounds);
};

// UID:000009 | by-class/AddMixingItemDialog.md | Completion:90 | Confidence:91
class MixItemDialog;

class AddMixingItemDialog : public AddItemDialog
{
public:
    explicit AddMixingItemDialog(MixItemDialog *mixDialog);
    virtual int OnAction(unsigned int actionId);

private:
    MixItemDialog *m_mixDialog;
};

typedef char AddMixingItemDialogSizeMustBe628[
    sizeof(AddMixingItemDialog) == 0x274 ? 1 : -1];
