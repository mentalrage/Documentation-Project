// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LT
// Source by-file doc: by-file/NewPredefinedFormArticleDialog.md
// UID:000098 | by-class/NewPredefinedFormArticleDialog.md | Completion:94 | Confidence:94
#include "NewPredefinedFormArticleDialog.h"

#include <windows.h>
#include <cstring>
#include <cwchar>

#include "BulletinSession.h"
#include "DialogControls.h"
#include "PacketBuffer.h"
#include "ScreenDimmer.h"
#include "TransferReplyPredefinedAlert.h"

static int __stdcall DeserializePredefinedFormArticleEntries(
    const unsigned char *serializedForm,
    PredefinedFormArticleEntry *entries,
    unsigned short *outVisibleRowCount,
    unsigned short *outEntryCount);

// UID:0002UJ | by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md | Completion:93 | Confidence:94
NewPredefinedFormArticleDialog::NewPredefinedFormArticleDialog(
    DialogSession *session,
    const wchar_t *previousSubject,
    RectBounds *bounds,
    const unsigned char *formPacket)
    : BulletinDialog(session, 5)
{
    const bool freeTextMode =
        g_pUserPane->m_predefinedFormArticleFreeTextMode;

    if (freeTextMode)
    {
        m_predefinedFormEntryCount = 1;
        m_visibleFormRowCount = 5;
    }
    else
    {
        DeserializePredefinedFormArticleEntries(
            formPacket,
            m_predefinedFormEntries,
            &m_visibleFormRowCount,
            &m_predefinedFormEntryCount);
    }

    RectBounds controlBounds;
    const int visibleRows = m_visibleFormRowCount;

    if (g_useEpfAssets)
    {
        InitRectBounds(&controlBounds, 149, 25 * visibleRows + 139,
            212, 25 * visibleRows + 163);
        AddControl(new ImageButtonControlPane(23, &controlBounds));

        InitRectBounds(&controlBounds, 226, 25 * visibleRows + 139,
            289, 25 * visibleRows + 163);
        AddControl(new ImageButtonControlPane(22, &controlBounds));

        InitRectBounds(&controlBounds, 94, 59, 404, 71);
        AddControl(new StaticTextControlPane(previousSubject, true,
            37, 0, &controlBounds, false, false));

        InitRectBounds(&controlBounds, 94, 86, 404, 98);
    }
    else
    {
        InitRectBounds(&controlBounds, 149, 21 * visibleRows + 108,
            221, 21 * visibleRows + 124);
        AddControl(new ImageButtonControlPane(23, &controlBounds));

        InitRectBounds(&controlBounds, 226, 21 * visibleRows + 108,
            298, 21 * visibleRows + 124);
        AddControl(new ImageButtonControlPane(22, &controlBounds));

        InitRectBounds(&controlBounds, 131, 51, 410, 63);
        AddControl(new StaticTextControlPane(previousSubject, true,
            37, 0, &controlBounds, false, false));

        InitRectBounds(&controlBounds, 131, 71, 410, 83);
    }

    AddControl(new TextEditControlPane(g_emptyWideString, true,
        143, 0, &controlBounds, false, false, false, false, 1.0f, 0));

    if (freeTextMode)
    {
        InitRectBounds(&controlBounds, 36, 110, 410,
            (g_useEpfAssets ? 25 : 21) * visibleRows + 110);

        TextEditControlPane *bodyEdit =
            new TextEditControlPane(g_emptyWideString, true,
                143, 0, &controlBounds, false, true,
                false, false, 0.99f, 0);
        bodyEdit->m_reservedControlState = 1;
        bodyEdit->SetMaxLines(1024);
        bodyEdit->SetMaxLength(4096);
        AddControl(bodyEdit);
    }
    else
    {
        int left = 36;
        int rowTop = 110;

        for (unsigned char rowIndex = 0;
             rowIndex < m_predefinedFormEntryCount;
             ++rowIndex)
        {
            PredefinedFormArticleEntry& entry =
                m_predefinedFormEntries[rowIndex];
            const int titleWidth =
                GetTextWidth(entry.title, entry.titleLength);
            const int titleRight = left + titleWidth;

            InitRectBounds(&controlBounds,
                left, rowTop, titleRight, rowTop + 16);
            AddControl(new StaticTextControlPane(entry.title, true,
                37, 0, &controlBounds, false, false));

            TextEditControlPane *valueEdit;

            if (entry.usesUserImagePane)
            {
                InitRectBounds(&controlBounds,
                    titleRight, rowTop,
                    titleRight + titleWidth, rowTop + 16);
                valueEdit = new TextEditControlPane(entry.body, true,
                    143, 0, &controlBounds, false, false,
                    true, false, 1.0f, 0);

                if (entry.rowAdvanceMode != 0)
                {
                    rowTop += 21;
                    left = 36;
                }
                else
                {
                    left = titleRight + 5 + 6 * entry.textLineCount;
                }
            }
            else
            {
                rowTop += 21;
                InitRectBounds(&controlBounds,
                    36, rowTop, 400,
                    rowTop + 16 * entry.textLineCount);
                valueEdit = new TextEditControlPane(entry.body, true,
                    143, 0, &controlBounds, false, true,
                    true, false, 0.99f, 0);
                valueEdit->m_reservedControlState = 1;
                valueEdit->SetMaxLines(1024);
                valueEdit->SetMaxLength(4000);
                rowTop += 21 *
                    ((16 * entry.textLineCount) / 21 + 1);
                left = 36;
            }

            AddControl(valueEdit);
        }
    }

    InitRectBounds(bounds, 50, 50,
        g_useEpfAssets ? 500 : 496,
        (g_useEpfAssets ? 25 : 21) * visibleRows +
            (g_useEpfAssets ? 254 : 208));
    SetPendingControl(1);
    SetHoverControl(3);
    SetBounds(bounds, false);
}

// UID:0002EK | by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md | Completion:92 | Confidence:93
void NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()
{
    DialogInSession *previous = m_session->FindPreviousDialog(this);
    ListPane *list =
        static_cast<ListPane *>(previous->GetControl(7));
    const unsigned short articleId =
        static_cast<unsigned short>(list->SelectedArticleId());

    SendArticleNavigationRequest(articleId, 0x7fff,
        g_useEpfAssets ? -0x14 : -0x10);
}

// UID:0002UK | by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md | Completion:93 | Confidence:93
void NewPredefinedFormArticleDialog::OnCommand(
    int commandId, int)
{
    BulletinSession *session = GetSession();

    if (commandId == 0)
    {
        const unsigned short boardId =
            session != NULL ? session->m_currentBoardId : 0;
        SubmitArticle(boardId);

        if (g_pUserPane != NULL)
        {
            g_pUserPane->m_activeDialogHostPane = this;
        }

        CreateScreenDimmer();
        return;
    }

    if (commandId == 1 && session != NULL)
    {
        session->PopCurrentDialog(false);
    }
}

// UID:0002UM | by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md | Completion:94 | Confidence:94
bool NewPredefinedFormArticleDialog::OnTimer(
    int timerId, int, int)
{
    if (timerId == 0 && IsScreenDimmerActive())
    {
        ReleaseScreenDimmer();
        new TransferReplyPredefinedAlert(false,
            L"Your post didn't go through due to an error.",
            this);
    }

    return true;
}

// UID:0002UN | by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md | Completion:93 | Confidence:94
void NewPredefinedFormArticleDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}

// UID:0002UO | by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md | Completion:93 | Confidence:94
void NewPredefinedFormArticleDialog::OnPaint()
{
    EPFFrame headerFrame;
    EPFFrame rowFrame;
    EPFFrame footerFrame;
    RectBounds drawRect;

    headerFrame.Clear();
    rowFrame.Clear();
    footerFrame.Clear();

    m_redrawPending = false;
    SetPaneDrawMode(0);
    g_surfaceCallbacks.FillOrPresent(this, &m_paintRegion);
    SetPaneDrawMode(0x80);

    if (g_useEpfAssets)
    {
        g_pEPFLib->LoadFrame(L"DLGBBS08.EPF", 0, &headerFrame);
        g_pEPFLib->LoadFrame(L"DLGBBS08.EPF", 1, &rowFrame);
        g_pEPFLib->LoadFrame(L"DLGBBS08.EPF", 2, &footerFrame);

        drawRect.Set(0, 0, 450, 120);
        DrawEPFFrame(&headerFrame, &drawRect, L"DLGBBS08.PAL");

        drawRect.Offset(0, 120);
        drawRect.bottom = drawRect.top + 25;
        for (unsigned char row = 0;
             row < m_visibleFormRowCount;
             ++row)
        {
            DrawEPFFrame(&rowFrame, &drawRect, L"DLGBBS08.PAL");
            drawRect.Offset(0, 25);
            drawRect.bottom = drawRect.top + 25;
        }

        drawRect.bottom = drawRect.top + 84;
        DrawEPFFrame(&footerFrame, &drawRect, L"DLGBBS08.PAL");
        return;
    }

    g_pEPFLib->LoadFrame(L"DLGBBS08.EPD", 0, &headerFrame);
    g_pEPFLib->LoadFrame(L"DLGBBS08.EPD", 1, &rowFrame);
    g_pEPFLib->LoadFrame(L"DLGBBS08.EPD", 2, &footerFrame);

    drawRect.Set(0, 0, 446, 88);
    DrawEPFFrame(&headerFrame, &drawRect, L"NPAL8.PAL");

    drawRect.Offset(0, 88);
    drawRect.bottom = drawRect.top + 21;
    for (unsigned char row = 0;
         row < m_visibleFormRowCount;
         ++row)
    {
        DrawEPFFrame(&rowFrame, &drawRect, L"NPAL8.PAL");
        drawRect.Offset(0, 21);
        drawRect.bottom = drawRect.top + 21;
    }

    drawRect.bottom = drawRect.top + 70;
    DrawEPFFrame(&footerFrame, &drawRect, L"NPAL8.PAL");
}

// UID:0002UQ | by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md | Completion:92 | Confidence:93
bool NewPredefinedFormArticleDialog::
HandleTransferReplyPredefinedAlert(const unsigned char *packet)
{
    if (packet[1] != 0x06)
    {
        return false;
    }

    if (IsScreenDimmerActive())
    {
        ReleaseScreenDimmer();
    }

    const unsigned char replyMode = packet[2];
    const unsigned int messageLength = packet[3];

    char multiByteMessage[256] = {};
    memmove(multiByteMessage, packet + 4, messageLength);
    multiByteMessage[messageLength] = '\0';

    wchar_t wideMessage[256] = {};
    const unsigned char wideLength =
        static_cast<unsigned char>(MultiByteToWideChar(
            CP_ACP, 0, multiByteMessage,
            static_cast<int>(messageLength),
            wideMessage, 256));
    wideMessage[wideLength] = L'\0';

    new TransferReplyPredefinedAlert(
        replyMode, wideMessage, this);
    return true;
}

// UID:0002UR | by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md | Completion:92 | Confidence:93
bool NewPredefinedFormArticleDialog::
HandleTransferReplyPredefinedAlertPayload(
    const unsigned char *payload)
{
    if (IsScreenDimmerActive())
    {
        ReleaseScreenDimmer();
    }

    const unsigned char replyMode = payload[0];
    const unsigned int messageLength = payload[1];

    char multiByteMessage[256] = {};
    memmove(multiByteMessage, payload + 2, messageLength);
    multiByteMessage[messageLength] = '\0';

    wchar_t wideMessage[256] = {};
    const unsigned char wideLength =
        static_cast<unsigned char>(MultiByteToWideChar(
            CP_ACP, 0, multiByteMessage,
            static_cast<int>(messageLength),
            wideMessage, 256));
    wideMessage[wideLength] = L'\0';

    new TransferReplyPredefinedAlert(
        replyMode, wideMessage, this);
    return true;
}

// UID:0002UL | by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md | Completion:93 | Confidence:94
void NewPredefinedFormArticleDialog::SubmitArticle(
    unsigned short boardId)
{
    char packet[0x8000] = {};
    char convertedText[0x1000] = {};
    wchar_t subject[0x100] = {};
    wchar_t body[0x1000] = {};
    wchar_t fieldText[0x1000] = {};

    const int subjectLength = static_cast<TextEditControlPane *>(
        GetControl(3))->ReadText(subject, 0xff);

    int bodyLength = 0;

    if (m_predefinedFormEntryCount != 0)
    {
        if (g_pUserPane->m_predefinedFormArticleFreeTextMode)
        {
            bodyLength = static_cast<TextEditControlPane *>(
                GetControl(4))->ReadText(body, 0xfff);
        }
        else
        {
            for (unsigned char row = 0;
                 row < m_predefinedFormEntryCount;
                 ++row)
            {
                const PredefinedFormArticleEntry& entry =
                    m_predefinedFormEntries[row];

                const int labelLength =
                    static_cast<TextEditControlPane *>(
                        GetControl(4 + row * 2))->
                            ReadText(fieldText, 0xfff);
                memmove(body + bodyLength, fieldText,
                    labelLength * sizeof(wchar_t));
                bodyLength += labelLength;

                if (!entry.usesUserImagePane)
                {
                    body[bodyLength++] = L' ';
                }

                const int valueLength =
                    static_cast<TextEditControlPane *>(
                        GetControl(5 + row * 2))->
                            ReadText(fieldText, 0xfff);
                memmove(body + bodyLength, fieldText,
                    valueLength * sizeof(wchar_t));
                bodyLength += valueLength;

                if (entry.rowAdvanceMode == 0)
                {
                    body[bodyLength++] = L' ';
                }
                else if (entry.rowAdvanceMode == 1)
                {
                    body[bodyLength++] = L'\r';
                }
            }
        }
    }

    body[bodyLength] = L'\0';

    PacketBufferWriteUInt8(0x3b, packet);
    PacketBufferWriteUInt8(0x04, packet + 1);
    PacketBufferWriteUInt16BE(boardId, packet + 2);

    const int subjectByteLength = WideCharToMultiByte(
        CP_ACP, 0, subject, subjectLength,
        convertedText, 0x100, NULL, NULL);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(subjectByteLength),
        packet + 4);
    memmove(packet + 5, convertedText, subjectByteLength);

    const int bodyByteLength = WideCharToMultiByte(
        CP_ACP, 0, body, bodyLength,
        convertedText, sizeof(convertedText), NULL, NULL);

    char *bodyLengthField = packet + 5 + subjectByteLength;
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(bodyByteLength),
        bodyLengthField);
    memmove(bodyLengthField + 2, convertedText, bodyByteLength);

    const int packetLength =
        subjectByteLength + bodyByteLength + 7;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    TimerHandler::ScheduleTimer(0, 15000, 0, 0);
}

// UID:0002UP | by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md | Completion:93 | Confidence:94
static int __stdcall DeserializePredefinedFormArticleEntries(
    const unsigned char *serializedForm,
    PredefinedFormArticleEntry *entries,
    unsigned short *outVisibleRowCount,
    unsigned short *outEntryCount)
{
    char narrowText[256] = {};
    wchar_t convertedBody[256] = {};

    unsigned char entryCount = 0;
    unsigned char visibleRowCount = 0;
    unsigned char titleByteLength = serializedForm[1];
    int cursor = 2;

    while (titleByteLength != 0)
    {
        PredefinedFormArticleEntry& entry = entries[entryCount];

        memmove(narrowText, serializedForm + cursor, titleByteLength);
        narrowText[titleByteLength] = '\0';

        const unsigned char titleLength =
            static_cast<unsigned char>(MultiByteToWideChar(
                CP_ACP, 0, narrowText, titleByteLength,
                entry.title, 256));
        entry.titleLength = titleLength;
        entry.title[titleLength] = L'\0';

        cursor += titleByteLength + 1;
        entry.usesUserImagePane = serializedForm[cursor++] == 1;
        entry.textLineCount = serializedForm[cursor++];

        const unsigned char bodyByteLength =
            serializedForm[cursor++];
        memmove(narrowText, serializedForm + cursor, bodyByteLength);
        narrowText[bodyByteLength] = '\0';
        cursor += bodyByteLength;

        const unsigned char convertedBodyLength =
            static_cast<unsigned char>(MultiByteToWideChar(
                CP_ACP, 0, narrowText, bodyByteLength,
                convertedBody, 256));
        convertedBody[convertedBodyLength] = L'\0';

        const bool bodyIsEmpty =
            wcscmp(convertedBody, L"empty") == 0;
        entry.bodyLength =
            bodyIsEmpty ? 0 : convertedBodyLength;
        wcscpy_s(entry.body, 256,
            bodyIsEmpty ? g_emptyWideString : convertedBody);

        entry.rowAdvanceMode =
            serializedForm[cursor++] == 1 ? 1 : 0;

        unsigned char rowBase = visibleRowCount;
        if (entry.rowAdvanceMode == 1)
        {
            rowBase = ++visibleRowCount;
        }

        if (!entry.usesUserImagePane)
        {
            visibleRowCount = static_cast<unsigned char>(
                rowBase + (16 * entry.textLineCount) / 21 + 1);
        }

        ++entryCount;
        titleByteLength = serializedForm[cursor++];
    }

    *outEntryCount = entryCount;
    *outVisibleRowCount = visibleRowCount;
    return visibleRowCount;
}
