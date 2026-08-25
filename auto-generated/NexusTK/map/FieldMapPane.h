// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JA
// Source by-file doc: by-file/FieldMapPane.md
// UID:00004U | by-class/FieldMapPane.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_MAP_FIELDMAPPANE_H
#define NEXUSTK_MAP_FIELDMAPPANE_H

#include "../ui/core/Pane.h"

class Event;

struct FieldMapEntry
{
    Point m_displayPosition;
    wchar_t m_label[64];
    unsigned short m_auxiliaryValue;
    unsigned short m_requestFieldId;
    Point m_requestPosition;
};

class FieldMapPane : public Pane
{
public:
    FieldMapPane(
        const wchar_t *sourcePath,
        short entryCount,
        short initialEntryIndex,
        const Point *displayPositions,
        const wchar_t *const *labels,
        const unsigned short *auxiliaryValues,
        const unsigned short *requestFieldIds,
        const Point *requestPositions);

    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    void CalculateFieldItemRect(short entryIndex, RectBounds *outRect);
    void SendFieldMapRequest(short entryIndex);

    wchar_t m_fieldMapEpfPath[128];
    FieldMapEntry m_fieldEntries[256];
    short m_fieldEntryCount;
    short m_selectedEntryIndex;
    short m_cancelEntryIndex;
    bool m_requestInFlight;
};

typedef char FieldMapEntrySizeCheck[sizeof(FieldMapEntry) == 0x94 ? 1 : -1];
typedef char FieldMapPaneSizeCheck[sizeof(FieldMapPane) == 0x9600 ? 1 : -1];

#endif
