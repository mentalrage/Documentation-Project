// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IX
// Source by-file doc: by-file/EditablePaperPane.md
// UID:000048 | by-class/EditablePaperPane.md | Completion:94 | Confidence:94
#include "EditablePaperPane.h"

// UID:0001EE | by-memory/0x00545170-0x00545e3b.EditablePaperPane.md | Completion:94 | Confidence:93
#include "EditablePaperPane.h"

#include <string.h>
#include <wchar.h>
#include <windows.h>

#include "../controls/TextButtonControlPane.h"
#include "../controls/TextEditControlPane.h"
#include "../controls/TextEditPane.h"
#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ResourceLayoutTable.h"
#include "../core/MainUiLayerSlots.h"

namespace
{
const int kPaperTileSize = 16;
const int kPaperLineHeight = 12;
const int kPaperTextCapacity = 8000;
const int kPaperPacketCapacity = 32000;
const unsigned char kSavePaperOpcode = 0x23;
const wchar_t kPaperResource[] = L"LINE001.EPD";

unsigned short ReadPaperLength(const unsigned char *packet)
{
    return static_cast<unsigned short>(
        (static_cast<unsigned short>(packet[5]) << 8) | packet[6]);
}

void NormalizePaperText(wchar_t *text, wchar_t from, wchar_t to)
{
    const int length = static_cast<int>(wcslen(text));
    for (int index = 0; index < length; ++index) {
        if (text[index] == from)
            text[index] = to;
    }
}
}

EditablePaperPane::EditablePaperPane(const unsigned char *packet,
                                     PaperOpenMode mode)
    : DialogPane(L"", 7, true),
      m_paperMode(mode)
{
    if (mode == kPaperOpenEditable) {
        ParseEditablePacket(packet);
    } else if (mode == kPaperOpenReadOnly) {
        ParseReadOnlyPacket(packet);
    }
}

void EditablePaperPane::OnControlCommand(int controlIndex,
                                         int /*notifyCode*/)
{
    if (controlIndex != 0)
        return;

    if (m_paperMode == kPaperOpenEditable)
        SavePaperContent();

    CloseDialog();
}

void EditablePaperPane::ParseEditablePacket(const unsigned char *packet)
{
    char narrowText[kPaperTextCapacity];
    wchar_t wideText[kPaperTextCapacity];

    m_paperId = packet[1];
    m_packetStatusByte = packet[2];
    m_widthTiles = static_cast<signed char>(packet[3]);
    m_heightTiles = static_cast<signed char>(packet[4]);

    const unsigned short byteCount = ReadPaperLength(packet);
    memcpy(narrowText, packet + 7, byteCount);
    narrowText[byteCount] = 0;

    const int wideCount = MultiByteToWideChar(
        CP_ACP, 0, narrowText, byteCount, wideText, kPaperTextCapacity);
    wideText[wideCount] = 0;
    m_textLength = static_cast<short>(wideCount);

    m_packetStatusByte = 0;
    InitializePaperContent(wideText);
}

void EditablePaperPane::ParseReadOnlyPacket(const unsigned char *packet)
{
    char narrowText[kPaperTextCapacity];
    wchar_t wideText[kPaperTextCapacity];

    m_packetStatusByte = packet[1];
    m_widthTiles = static_cast<signed char>(packet[2]);
    m_heightTiles = static_cast<signed char>(packet[3]);
    m_centerText = packet[4];

    const unsigned short byteCount = ReadPaperLength(packet);
    memcpy(narrowText, packet + 7, byteCount);
    narrowText[byteCount] = 0;

    const int wideCount = MultiByteToWideChar(
        CP_ACP, 0, narrowText, byteCount, wideText, kPaperTextCapacity);
    wideText[wideCount] = 0;
    m_textLength = static_cast<short>(wideCount);

    m_packetStatusByte = 0;
    InitializePaperContent(wideText);
}

void EditablePaperPane::InitializePaperContent(wchar_t *text)
{
    NormalizePaperText(text, L'\t', L'\r');

    const short paneWidth =
        static_cast<short>((m_widthTiles + 2) * kPaperTileSize);
    const short paneHeight =
        static_cast<short>((m_heightTiles + 3) * kPaperTileSize);

    RectBounds bounds;
    InitRectBounds(&bounds, -200, -200, -140, -180);
    AddControl(new TextButtonControlPane(
        g_pLanguageMan->GetLocalizedString(
            m_paperMode == kPaperOpenEditable ? 95 : 96),
        &bounds));

    if (m_paperMode == kPaperOpenReadOnly && m_centerText != 0) {
        const short textWidth =
            static_cast<short>(8 * static_cast<short>(wcslen(text)));
        const short left = static_cast<short>((paneWidth - textWidth) / 2);
        const short top = static_cast<short>((paneHeight - kPaperLineHeight) / 2);
        InitRectBounds(&bounds, left, top,
                       static_cast<short>(left + textWidth),
                       static_cast<short>(top + kPaperLineHeight));
    } else {
        InitRectBounds(&bounds,
                       kPaperTileSize,
                       kPaperTileSize,
                       static_cast<short>(paneWidth - kPaperTileSize),
                       static_cast<short>((m_heightTiles + 1) *
                                          kPaperTileSize));
    }

    bounds.bottom = static_cast<short>(
        bounds.top +
        kPaperLineHeight *
            ((bounds.bottom - bounds.top - 1) / kPaperLineHeight));

    TextEditControlPane *editor =
        new TextEditControlPane(L"", true, 128, 143, &bounds,
                                false, true, false, false, 1.0f, false);
    AddControl(editor);
    editor->GetTextEditPane()->SetScrollbarsVisible(false);
    editor->SetHandlesEnterKey(true);

    if (m_paperMode == kPaperOpenEditable) {
        editor->SetMaxLines(42);
        editor->SetMaxLength(250);
        editor->GetTextEditPane()->InsertTextRange(
            text, static_cast<short>(wcslen(text)), NULL, NULL);
        SetHoverControl(1);
        editor->GetTextEditPane()->SetSelectionRange(0, 0);
    } else {
        editor->SetMaxLines(2000);
        editor->SetMaxLength(30000);
        editor->SetEditActiveState(false, false);
        editor->GetTextEditPane()->InsertTextRange(
            text, static_cast<short>(wcslen(text)), NULL, NULL);
        editor->GetTextEditPane()->SetSelectionRange(0, 0);
        editor->SetSelectable(false);
        SetHoverControl(0);
    }

    SetPendingControl(0);
    if (m_paperMode == kPaperOpenReadOnly)
        SetFocusedControl(0);

    InitRectBounds(&bounds,
                   320 - paneWidth / 2,
                   240 - paneHeight / 2,
                   320 + paneWidth / 2,
                   240 + paneHeight / 2);
    OnCreate(&bounds, 0, NULL,
             g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

void EditablePaperPane::SavePaperContent()
{
    wchar_t wideText[kPaperTextCapacity];
    char narrowText[kPaperTextCapacity];
    unsigned char packet[kPaperPacketCapacity];

    TextEditControlPane *editor = GetChild<TextEditControlPane>(1);
    const short wideCount = editor->ReadText(
        wideText, static_cast<short>(kPaperTextCapacity));

    for (short index = 0; index < wideCount; ++index) {
        if (wideText[index] == L'\r')
            wideText[index] = L'\t';
    }

    packet[0] = kSavePaperOpcode;
    packet[1] = m_paperId;

    const int byteCount = WideCharToMultiByte(
        CP_ACP, 0, wideText, wideCount,
        narrowText, kPaperTextCapacity, NULL, NULL);
    narrowText[byteCount] = 0;
    packet[2] = static_cast<unsigned char>(byteCount >> 8);
    packet[3] = static_cast<unsigned char>(byteCount);
    memcpy(packet + 4, narrowText, byteCount);

    const unsigned int packetLength =
        static_cast<unsigned int>(byteCount + 4);
    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}

void EditablePaperPane::DrawBorder()
{
    EPFTileContext frames[8];
    const int frameOrder[8] = { 0, 1, 2, 7, 3, 6, 5, 4 };
    for (int index = 0; index < 8; ++index) {
        g_pEPFLib->LookupLayoutEntry(
            kPaperResource, frameOrder[index], &frames[index]);
    }

    RectBounds sourceBounds;
    RectBounds originBounds;
    RectBounds destinationBounds;
    InitRectBounds(&sourceBounds, 0, 0, 16, 16);
    InitRectBounds(&originBounds, 0, 0, 16, 16);

    const int width = m_visibleBounds.right - m_visibleBounds.left;
    const int height = m_visibleBounds.bottom - m_visibleBounds.top;

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16, 0);
    do {
        RenderTileFrame(&frames[1], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 16, 0);
    } while (destinationBounds.right < originBounds.left + width - 1);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16, height - 16);
    do {
        RenderTileFrame(&frames[6], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 16, 0);
    } while (destinationBounds.right < originBounds.left + width - 1);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0, 16);
    do {
        RenderTileFrame(&frames[3], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 0, 16);
    } while (destinationBounds.bottom < originBounds.top + height - 1);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, width - 16, 16);
    do {
        RenderTileFrame(&frames[4], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 0, 16);
    } while (destinationBounds.bottom < originBounds.top + height - 1);

    destinationBounds = originBounds;
    RenderTileFrame(&frames[0], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, width - 16, 0);
    RenderTileFrame(&frames[2], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0, height - 16);
    RenderTileFrame(&frames[5], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, width - 16, height - 16);
    RenderTileFrame(&frames[7], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
}

void EditablePaperPane::DrawBackground()
{
    EPFTileContext frame;
    g_pEPFLib->LookupLayoutEntry(kPaperResource, 8, &frame);

    RectBounds bounds = m_visibleBounds;
    InsetRect(&bounds, kPaperTileSize, kPaperTileSize);
    m_drawMode = 0;
    DrawTiledBackground(&bounds, &frame, NULL);
}
