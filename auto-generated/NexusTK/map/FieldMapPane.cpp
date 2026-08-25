// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JA
// Source by-file doc: by-file/FieldMapPane.md
// UID:00004U | by-class/FieldMapPane.md | Completion:93 | Confidence:94
#include "FieldMapPane.h"

#include "../network/PacketBuffer.h"
#include "../network/Socket.h"
#include "../platform/PlatformApi.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"

#include <string.h>
#include <wchar.h>

static void BuildFieldMapPath(const wchar_t *sourcePath, wchar_t *destination);

// UID:00014Z | by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md | Completion:92 | Confidence:94
FieldMapPane::FieldMapPane(
    const wchar_t *sourcePath,
    short entryCount,
    short initialEntryIndex,
    const Point *displayPositions,
    const wchar_t *const *labels,
    const unsigned short *auxiliaryValues,
    const unsigned short *requestFieldIds,
    const Point *requestPositions)
    : Pane(0),
      m_fieldEntryCount(entryCount),
      m_selectedEntryIndex(initialEntryIndex),
      m_cancelEntryIndex(initialEntryIndex),
      m_requestInFlight(false)
{
    BuildFieldMapPath(sourcePath, m_fieldMapEpfPath);
    wcscat_s(m_fieldMapEpfPath, 128, L".EPF");
    g_pfnCharUpperBuffW(m_fieldMapEpfPath, (DWORD)wcslen(m_fieldMapEpfPath));

    for (short i = 0; i < entryCount; ++i)
    {
        FieldMapEntry &entry = m_fieldEntries[i];
        entry.m_displayPosition = displayPositions[i];
        wcscpy_s(entry.m_label, 64, labels[i]);
        entry.m_auxiliaryValue = auxiliaryValues[i];
        entry.m_requestFieldId = requestFieldIds[i];
        entry.m_requestPosition = requestPositions[i];
    }
}

bool FieldMapPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonDown)
    {
        for (short i = 0; i < m_fieldEntryCount; ++i)
        {
            RectBounds bounds;
            CalculateFieldItemRect(i, &bounds);
            if (PointInRect(event->m_payload.m_pointer.m_y,
                            event->m_payload.m_pointer.m_x,
                            &bounds) &&
                !m_requestInFlight)
            {
                SendFieldMapRequest(i);
            }
        }
    }
    return true;
}

bool FieldMapPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (event->m_type == kEventKeyDown)
    {
        switch (key)
        {
        case 0x0d:
            if (!m_requestInFlight)
                SendFieldMapRequest(m_selectedEntryIndex);
            break;
        case kPaneKeyEscape:
        case 0x71:
            SendFieldMapRequest(m_cancelEntryIndex);
            break;
        case kPaneKeyLeft:
            m_selectedEntryIndex =
                (short)((m_selectedEntryIndex + 1) % m_fieldEntryCount);
            InvalidateRect(&m_visibleBounds);
            break;
        case kPaneKeyRight:
            m_selectedEntryIndex =
                (short)((m_selectedEntryIndex + m_fieldEntryCount - 1) % m_fieldEntryCount);
            InvalidateRect(&m_visibleBounds);
            break;
        }
    }
    return true;
}

void FieldMapPane::OnPaint()
{
    EPFTileContext context;
    g_pEPFLib->LookupLayoutEntry(m_fieldMapEpfPath, 0, &context);
    g_pfnBlitSprite(this, &context, &context.bounds, &m_visibleBounds, 0, 0, 0);

    SetDrawMode(0);
    for (short i = 0; i < m_fieldEntryCount; ++i)
    {
        RectBounds bounds;
        CalculateFieldItemRect(i, &bounds);

        SetDrawColor(i == m_selectedEntryIndex ? 37 : 4);
        SetDrawMode(2);
        g_pfnFillRect(this, &bounds);

        SetDrawMode(0);
        SetDrawColor(0x80);
        DrawRectFrame(&bounds);

        SetDrawMode(1);
        MoveTo(bounds.left + 6, bounds.bottom - 6);
        DrawWideText(
            m_fieldEntries[i].m_label,
            (int)wcslen(m_fieldEntries[i].m_label));
    }
}

// UID:000150 | by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md | Completion:91 | Confidence:93
void FieldMapPane::CalculateFieldItemRect(short entryIndex, RectBounds *outRect)
{
    const FieldMapEntry &entry = m_fieldEntries[entryIndex];
    const int width = GetTextWidth(entry.m_label) + 12;
    const int height = GetLineHeight() * 2;

    outRect->top = entry.m_displayPosition.y - height / 2;
    outRect->bottom = outRect->top + height;
    outRect->left = entry.m_displayPosition.x - width / 2;
    outRect->right = outRect->left + width;
}

// UID:000151 | by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md | Completion:92 | Confidence:94
void FieldMapPane::SendFieldMapRequest(short entryIndex)
{
    const FieldMapEntry &entry = m_fieldEntries[entryIndex];
    unsigned char packet[0x100];

    PacketBufferWriteUInt8(0x3f, packet);
    PacketBufferWriteUInt16BE(entry.m_requestFieldId, packet + 1);
    PacketBufferWriteUInt16BE(entry.m_requestPosition.x, packet + 3);
    PacketBufferWriteUInt16BE(entry.m_requestPosition.y, packet + 5);
    packet[7] = 0;

    g_packetSender->QueueAndSendPacket(packet, 7);
    m_requestInFlight = true;
}

// UID:00015U | by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md | Completion:91 | Confidence:93
static void BuildFieldMapPath(const wchar_t *sourcePath, wchar_t *destination)
{
    const wchar_t *end = sourcePath;
    while (*end != L'\0')
        ++end;

    const wchar_t *lastDot = 0;
    const wchar_t *scan = end;
    while (scan != sourcePath)
    {
        --scan;
        if (*scan == L'.')
        {
            lastDot = scan;
            break;
        }
    }

    const size_t copyChars = lastDot != 0
        ? (size_t)(lastDot - sourcePath)
        : (size_t)(end - sourcePath);
    memmove(destination, sourcePath, copyChars * sizeof(wchar_t));
    destination[copyChars] = L'\0';
}

// UID:0003P9 | by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md | Completion:87 | Confidence:92
// The shared .EPF suffix literal is emitted inline at each proven source use.
