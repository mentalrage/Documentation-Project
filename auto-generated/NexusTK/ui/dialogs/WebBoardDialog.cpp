// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P9
// Source by-file doc: by-file/WebBoardDialog.md
// UID:0002AG | by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md | Completion:92 | Confidence:94
static bool s_webBoardUrlEscapeInitialized;
static unsigned char s_webBoardUrlEscapeTable[256];

// UID:0002AH | by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md | Completion:92 | Confidence:94
static bool s_oldWebBoardUrlEscapeInitialized;
static unsigned char s_oldWebBoardUrlEscapeTable[256];

// UID:000214 | by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md | Completion:90 | Confidence:92
static const char kOldWebBoardUrlReservedChars[] = "$&+,/:=?@";
static const char kOldWebBoardUrlUnsafeChars[] = " \"<>#%{}|\\^~[]`";

static char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                          short sourceLength,
                                          char *dest,
                                          short destCapacity)
{
    if (!s_oldWebBoardUrlEscapeInitialized) {
        for (int ch = 0; ch < 256; ++ch) {
            s_oldWebBoardUrlEscapeTable[ch] =
                (ch < 0x20 || ch >= 0x80) ? 1 : 0;
        }

        for (int i = 0; i < 9; ++i) {
            const unsigned char ch =
                static_cast<unsigned char>(kOldWebBoardUrlReservedChars[i]);
            s_oldWebBoardUrlEscapeTable[ch] = 1;
        }

        for (int i = 0; i < 15; ++i) {
            const unsigned char ch =
                static_cast<unsigned char>(kOldWebBoardUrlUnsafeChars[i]);
            s_oldWebBoardUrlEscapeTable[ch] = 1;
        }

        s_oldWebBoardUrlEscapeInitialized = true;
    }

    short sourceIndex = 0;
    short produced = 0;

    while (sourceIndex < sourceLength && produced < destCapacity - 3) {
        const unsigned char ch =
            static_cast<unsigned char>(source[sourceIndex]);

        if (s_oldWebBoardUrlEscapeTable[ch] == 1) {
            sprintf_s(dest + produced,
                      destCapacity - produced,
                      "%%%2X",
                      static_cast<unsigned int>(ch));
            produced += 3;
        } else {
            dest[produced++] = static_cast<char>(ch);
        }

        ++sourceIndex;
    }

    dest[produced] = '\0';
    return dest;
}

// UID:0000G2 | by-class/WebBoardDialog.md | Completion:92 | Confidence:93
#include "../core/BlackHole.h"

// UID:0000Z7 | by-memory/0x0046d050-0x0046d324.WebBoardDialog.md | Completion:90 | Confidence:92
WebBoardDialog::WebBoardDialog(int boardMode,
                               const wchar_t *boardOwnerName,
                               const void *initialResponsePacket,
                               OLECHAR *initialUrl)
    : BrowserPane(L"", -1, true),
      m_browserControlPane(NULL),
      m_closeButton(NULL)
{
    g_pWebBoardDialog = this;

    if (boardOwnerName != NULL)
        wcscpy_s(m_boardOwnerName, 0x80, boardOwnerName);

    Rect closeRect;
    if (boardMode == 0 || boardMode == 4)
        closeRect.Set(318, 468, 381, 492);
    else if (boardMode == 6)
        closeRect.Set(368, 568, 431, 592);

    m_closeButton = new ImageButtonControlPane(30, closeRect);
    AddChild(m_closeButton);

    Rect browserRect;
    if (boardMode == 0)
        browserRect.Set(11, 42, 689, 460);
    else if (boardMode == 4)
        browserRect.Set(11, 42, 407, 526);
    else if (boardMode == 6)
        browserRect.Set(11, 42, 789, 560);

    m_browserControlPane = new BrowserControlPane(browserRect, initialUrl, this);
    AddChild(m_browserControlPane);

    Rect dialogRect;
    if (boardMode == 0)
        dialogRect.Set(162, 134, 862, 634);
    else if (boardMode == 4)
        dialogRect.Set(303, 101, 721, 667);
    else if (boardMode == 6)
        dialogRect.Set(112, 84, 912, 684);

    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(false);
    SetEnabled(false);

    if (initialResponsePacket != NULL) {
        HandleBoardResponse(initialResponsePacket);
    } else if (initialUrl != NULL) {
        m_browserControlPane->Navigate(initialUrl, NULL);
    } else {
        SendInitialBoardRequest(static_cast<unsigned char>(boardMode));
    }
}

// UID:00020Y | by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md | Completion:92 | Confidence:94
WebBoardDialog::~WebBoardDialog()
{
    g_pWebBoardDialog = NULL;
}

void WebBoardDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex != 0)
        return;

    OnBrowserDialogClosed();
    m_browserControlPane->ShutdownBrowserWindow();
    m_browserControlPane = NULL;
    OnDestroy();
    OnHide();
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}

bool WebBoardDialog::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type != 0 || !m_isTitleDragActive)
        return DialogPane::HandlePointerOrMouseEvent(event);

    const bool handled = DialogPane::HandlePointerOrMouseEvent(event);

    RECT browserClient;
    ::GetClientRect(g_activeBrowserControlPane->m_browserHostHwnd, &browserClient);

    RectBounds dialogBounds;
    GetScreenBounds(&dialogBounds);

    ::MoveWindow(m_browserControlPane->m_browserHostHwnd,
                 dialogBounds.left + 11,
                 dialogBounds.top + 42,
                 browserClient.right - browserClient.left,
                 browserClient.bottom - browserClient.top,
                 FALSE);

    g_pScreenPane->RenderPresentation();
    return handled;
}

// UID:0000Z8 | by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md | Completion:91 | Confidence:93
bool WebBoardDialog::OnPacket(void *event)
{
    const unsigned char *payload = GetWebBoardPacketPayload(event);

    if (payload == NULL || payload[0] != kWebBoardResponseOpcode)
        return false;

    return HandleBoardResponse(payload);
}

// UID:00020Z | by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md | Completion:88 | Confidence:91
static const unsigned char kWebBoardInitialRequestOpcode = 0x73;
static const unsigned int kWebBoardRequestTimerId = 0x572;
static const unsigned int kWebBoardRequestTimerDuration = 20000;

bool WebBoardDialog::OnKeyEvent(InputEvent *event)
{
    const char key =
        NarrowInputCharacter(event->rawKey, event->modifierState);

    if (event->type == 8) {
        if (key == 'b' && (event->modifierState & 7) == 0) {
            CloseOrBackFromBoardOwner();
            return true;
        }

        if (event->rawKey == 0x90)
            return true;
    }

    DialogPane::OnKeyEvent(event);
    return true;
}

void WebBoardDialog::SendInitialBoardRequest(unsigned char boardMode)
{
    unsigned char packet[3];

    PacketBufferWriteByte(kWebBoardInitialRequestOpcode, &packet[0]);
    PacketBufferWriteByte(boardMode, &packet[1]);
    packet[2] = 0;

    QueueAndSendPacket(g_pPacketQueue, packet, 2);
    StartPaneTimer(kWebBoardRequestTimerId,
                   kWebBoardRequestTimerDuration,
                   0,
                   0);
}

// UID:0000Z9 | by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md | Completion:89 | Confidence:91
static const char kWebBoardUrlReservedChars[] = "$&+,/:=?@";
static const char kWebBoardUrlUnsafeChars[] = " \"<>#%{}|\\^~[]`";

static void InitializeWebBoardUrlEscapeTable()
{
    if (s_webBoardUrlEscapeInitialized)
        return;

    for (int ch = 0; ch < 256; ++ch)
        s_webBoardUrlEscapeTable[ch] = (ch < 0x20 || ch >= 0x80) ? 1 : 0;

    for (int i = 0; i < 9; ++i)
        s_webBoardUrlEscapeTable[
            static_cast<unsigned char>(kWebBoardUrlReservedChars[i])] = 1;

    for (int i = 0; i < 15; ++i)
        s_webBoardUrlEscapeTable[
            static_cast<unsigned char>(kWebBoardUrlUnsafeChars[i])] = 1;

    s_webBoardUrlEscapeInitialized = true;
}

static char *EscapeWebBoardUrl(const char *source,
                               short sourceLength,
                               char *dest,
                               short destCapacity)
{
    InitializeWebBoardUrlEscapeTable();

    short sourceIndex = 0;
    short produced = 0;

    while (sourceIndex < sourceLength && produced < destCapacity - 3) {
        const unsigned char ch =
            static_cast<unsigned char>(source[sourceIndex]);

        if (s_webBoardUrlEscapeTable[ch] == 1) {
            sprintf_s(dest + produced,
                      destCapacity - produced,
                      "%%%2X",
                      static_cast<unsigned int>(ch));
            produced += 3;
        } else {
            dest[produced++] = static_cast<char>(ch);
        }

        ++sourceIndex;
    }

    dest[produced] = '\0';
    return dest;
}

bool WebBoardDialog::HandleBoardResponse(const void *packet)
{
    const unsigned char *payload =
        static_cast<const unsigned char *>(packet);

    StopPaneTimer(kWebBoardRequestTimerId);

    const unsigned char *cursor = payload + 1;
    const bool ownerPageResponse = (*cursor++ != 0);

    if (ownerPageResponse) {
        char baseUrl[256];
        char checkedField[256];
        wchar_t wideBaseUrl[512];
        wchar_t wideCheckedField[1024];
        wchar_t navigateUrl[1024];

        cursor = CopyWebBoardPacketField(cursor, baseUrl, sizeof(baseUrl));
        const int baseChars = MultiByteToWideChar(0, 0,
                                                  baseUrl,
                                                  strlen(baseUrl),
                                                  wideBaseUrl,
                                                  512);
        if (baseChars >= 512)
            __report_rangecheckfailure(0);
        wideBaseUrl[baseChars] = 0;

        cursor = CopyWebBoardPacketField(cursor,
                                         checkedField,
                                         sizeof(checkedField));
        const int checkedChars = MultiByteToWideChar(0, 0,
                                                     checkedField,
                                                     strlen(checkedField),
                                                     wideCheckedField,
                                                     1024);
        if (checkedChars >= 1024)
            __report_rangecheckfailure(0);
        wideCheckedField[checkedChars] = 0;

        swprintf_s(navigateUrl,
                   1024,
                   L"%s/%s.html",
                   wideBaseUrl,
                   m_boardOwnerName);
        m_browserControlPane->Navigate(navigateUrl, NULL);
        return true;
    }

    char url[256];
    char navigateTarget[256];
    char cookieData[256];
    char domainValue[128];
    char escapedBoardInfo[1024];
    wchar_t wideUrl[256];
    wchar_t wideTarget[256];

    cursor = CopyWebBoardPacketField(cursor, url, sizeof(url));
    cursor = CopyWebBoardPacketField(cursor, navigateTarget, sizeof(navigateTarget));
    cursor = CopyWebBoardPacketField(cursor, cookieData, sizeof(cookieData));

    short boardInfoLength = 0;
    const char *boardInfo = ExtractWebBoardCookieValue(cookieData,
                                                       domainValue,
                                                       sizeof(domainValue),
                                                       &boardInfoLength);

    InternetSetCookieA(url, "domain", domainValue);
    EscapeWebBoardUrl(boardInfo,
                      boardInfoLength,
                      escapedBoardInfo,
                      sizeof(escapedBoardInfo));
    InternetSetCookieA(url, "boardinfo", escapedBoardInfo);

    const int urlChars = MultiByteToWideChar(0, 0, url, strlen(url),
                                             wideUrl, 256);
    if (urlChars >= 256)
        __report_rangecheckfailure(0);
    wideUrl[urlChars] = 0;

    m_browserControlPane->SetCurrentUrl(wideUrl);

    const int targetChars = MultiByteToWideChar(0, 0,
                                                navigateTarget,
                                                strlen(navigateTarget),
                                                wideTarget,
                                                256);
    if (targetChars >= 256)
        __report_rangecheckfailure(0);
    wideTarget[targetChars] = 0;

    m_browserControlPane->Navigate(wideTarget, NULL);
    return true;
}




// UID:0000ZA | by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md | Completion:88 | Confidence:90
void WebBoardDialog::RefreshLayout(int mode)
{
    ReleaseDialogControls();
    DetachDialogChildren();
    RemoveControl(1);
    RemoveControl(0);
    SetVisible(true);
    SetEnabled(false);

    if (m_closeButton != NULL)
        m_closeButton->Destroy(true);

    if (m_browserControlPane != NULL)
        m_browserControlPane->Destroy(true);

    Rect closeRect;
    if (mode == 0 || mode == 4)
        closeRect.Set(318, 468, 381, 492);
    else if (mode == 6)
        closeRect.Set(368, 568, 431, 592);

    m_closeButton = new ImageButtonControlPane(14, closeRect);
    AddChild(m_closeButton);

    Rect browserRect;
    if (mode == 0)
        browserRect.Set(11, 42, 689, 460);
    else if (mode == 4)
        browserRect.Set(11, 42, 407, 526);
    else if (mode == 6)
        browserRect.Set(11, 42, 789, 560);

    m_browserControlPane = new BrowserControlPane(browserRect, NULL, this);
    AddChild(m_browserControlPane);

    Rect dialogRect;
    if (mode == 0)
        dialogRect.Set(162, 134, 862, 634);
    else if (mode == 4)
        dialogRect.Set(303, 101, 721, 667);
    else if (mode == 6)
        dialogRect.Set(112, 84, 912, 684);

    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(false);
    SetEnabled(false);
}

// UID:00033E | by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md | Completion:86 | Confidence:90
// Compiler-generated scalar deleting destructor for WebBoardDialog.
// Source reconstruction is the virtual destructor declaration plus WebBoardDialog::~WebBoardDialog()
// emitted by UID 00020Y; do not hand-author this wrapper.

// UID:0000G3 | by-class/WebBoardDialogOld.md | Completion:92 | Confidence:93

// UID:000211 | by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md | Completion:89 | Confidence:91
static void __stdcall GetWebBoardDialogOldModeRect(Rect *out,
                                                   int selector,
                                                   int mode)
{
    if (out == NULL)
        return;

    switch (mode) {
    case 0:
        switch (selector) {
        case 0: out->Set(162, 134, 862, 634); break;
        case 1: out->Set(318, 468, 381, 492); break;
        case 2: out->Set(11, 42, 689, 460); break;
        case 3: out->Set(0, 0, 0, 0); break;
        default: break;
        }
        break;

    case 4:
        switch (selector) {
        case 0: out->Set(303, 101, 721, 667); break;
        case 1: out->Set(318, 468, 381, 492); break;
        case 2: out->Set(11, 42, 407, 526); break;
        case 3: out->Set(0, 0, 0, 0); break;
        default: break;
        }
        break;

    case 6:
        switch (selector) {
        case 0: out->Set(112, 84, 912, 684); break;
        case 1: out->Set(368, 568, 431, 592); break;
        case 2: out->Set(11, 42, 789, 560); break;
        case 3: out->Set(0, 0, 0, 0); break;
        default: break;
        }
        break;

    default:
        break;
    }
}

// UID:0000ZB | by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md | Completion:90 | Confidence:91
WebBoardDialogOld::WebBoardDialogOld(const unsigned char *initialResponsePayload,
                                     OLECHAR *initialUrl)
    : BrowserPane(L"", -1, true)
{
    g_pWebBoardDialogOld = this;

    Rect frameRect(0, 0, 540, 379);
    ImagePane *frame =
        new ImagePane(L"WEBBOARD.EPD", frameRect, true, L"WEBBOARD.PAD");
    AddChild(frame);

    Rect closeRect(234, 342, 306, 358);
    ImageButtonControlPane *closeButton =
        new ImageButtonControlPane(30, closeRect);
    AddChild(closeButton);

    Rect browserRect(30, 30, 510, 334);
    m_browserControlPane = new BrowserControlPane(browserRect,
                                                  initialUrl,
                                                  this);
    AddChild(m_browserControlPane);

    Rect dialogRect(50, 50, 590, 429);
    SetBackgroundImage(L"WEBBOARD.EPD", 0);
    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(true);
    SetEnabled(true);

    if (initialResponsePayload != NULL)
        HandleBoardResponse(initialResponsePayload);
    else if (initialUrl == NULL)
        SendInitialBoardRequest();
}

// UID:000212 | by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md | Completion:92 | Confidence:94
WebBoardDialogOld::~WebBoardDialogOld()
{
    g_pWebBoardDialogOld = NULL;
}

void WebBoardDialogOld::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex != 1)
        return;

    OnBrowserDialogClosed();
    m_browserControlPane->ShutdownBrowserWindow();
    OnDestroy();
    OnHide();
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}

bool WebBoardDialogOld::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type != 0 || !m_isTitleDragActive)
        return DialogPane::HandlePointerOrMouseEvent(event);

    const bool handled = DialogPane::HandlePointerOrMouseEvent(event);

    RECT browserClient;
    ::GetClientRect(g_activeBrowserControlPane->m_browserHostHwnd, &browserClient);

    RectBounds dialogBounds;
    GetScreenBounds(&dialogBounds);

    ::MoveWindow(m_browserControlPane->m_browserHostHwnd,
                 dialogBounds.left + 30,
                 dialogBounds.top + 30,
                 browserClient.right - browserClient.left,
                 browserClient.bottom - browserClient.top,
                 FALSE);

    g_pScreenPane->RenderPresentation();
    return handled;
}

// UID:0000ZC | by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md | Completion:91 | Confidence:93
static const unsigned char kWebBoardResponseOpcode = 0x62;

static const unsigned char *GetWebBoardPacketPayload(const void *event)
{
    const unsigned char * const *payloadSlot =
        reinterpret_cast<const unsigned char * const *>(
            static_cast<const unsigned char *>(event) + 0x0c);
    return *payloadSlot;
}

bool WebBoardDialogOld::OnWebBoardPacket(void *event)
{
    const unsigned char *payload = GetWebBoardPacketPayload(event);

    if (payload == NULL || payload[0] != kWebBoardResponseOpcode)
        return false;

    return HandleBoardResponse(payload);
}

// UID:000213 | by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md | Completion:88 | Confidence:91
void WebBoardDialogOld::SendInitialBoardRequest()
{
    unsigned char packet[3];

    PacketBufferWriteByte(kWebBoardInitialRequestOpcode, &packet[0]);
    PacketBufferWriteByte(0, &packet[1]);
    packet[2] = 0;

    QueueAndSendPacket(g_pPacketQueue, packet, 2);
    StartPaneTimer(kWebBoardRequestTimerId,
                   kWebBoardRequestTimerDuration,
                   0,
                   0);
}

// UID:0000ZD | by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md | Completion:89 | Confidence:91
static const unsigned char *CopyWebBoardPacketField(const unsigned char *cursor,
                                                    char *dest,
                                                    size_t destCapacity)
{
    const unsigned int length = *cursor++;

    if (length >= destCapacity)
        __report_rangecheckfailure(0);

    memcpy(dest, cursor, length);
    dest[length] = '\0';
    return cursor + length;
}

static const char *ExtractWebBoardCookieValue(const char *cookieData,
                                              char *domainValue,
                                              size_t domainCapacity,
                                              short *boardInfoLength)
{
    const char *equals = strchr(cookieData, '=');
    const char *ampersand = (equals != NULL) ? strchr(equals + 1, '&') : NULL;

    if (equals == NULL || ampersand == NULL)
        __report_rangecheckfailure(0);

    const size_t domainLength = static_cast<size_t>(ampersand - (equals + 1));
    if (domainLength >= domainCapacity)
        __report_rangecheckfailure(0);

    strncpy_s(domainValue, domainCapacity, equals + 1, domainLength);
    domainValue[domainLength] = '\0';

    const char *boardInfo = ampersand + 1;
    *boardInfoLength = static_cast<short>(strlen(boardInfo));
    return boardInfo;
}

bool WebBoardDialogOld::HandleBoardResponse(const unsigned char *payload)
{
    StopPaneTimer(kWebBoardRequestTimerId);

    const unsigned char *cursor = payload + 2;
    char url[256];
    char navigateTarget[256];
    char cookieData[256];
    char domainValue[128];
    char escapedBoardInfo[1024];
    wchar_t wideUrl[256];
    wchar_t wideTarget[256];

    cursor = CopyWebBoardPacketField(cursor, url, sizeof(url));
    cursor = CopyWebBoardPacketField(cursor, navigateTarget, sizeof(navigateTarget));
    cursor = CopyWebBoardPacketField(cursor, cookieData, sizeof(cookieData));

    short boardInfoLength = 0;
    const char *boardInfo = ExtractWebBoardCookieValue(cookieData,
                                                       domainValue,
                                                       sizeof(domainValue),
                                                       &boardInfoLength);

    InternetSetCookieA(url, "domain", domainValue);
    EscapeOldWebBoardUrl(boardInfo,
                         boardInfoLength,
                         escapedBoardInfo,
                         sizeof(escapedBoardInfo));
    InternetSetCookieA(url, "boardinfo", escapedBoardInfo);

    const int urlChars = MultiByteToWideChar(0, 0, url, strlen(url),
                                             wideUrl, 256);
    if (urlChars >= 256)
        __report_rangecheckfailure(0);
    wideUrl[urlChars] = 0;

    m_browserControlPane->SetCurrentUrl(wideUrl);

    const int targetChars = MultiByteToWideChar(0, 0,
                                                navigateTarget,
                                                strlen(navigateTarget),
                                                wideTarget,
                                                256);
    if (targetChars >= 256)
        __report_rangecheckfailure(0);
    wideTarget[targetChars] = 0;

    m_browserControlPane->Navigate(wideTarget, NULL);
    return true;
}

// UID:00033F | by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md | Completion:90 | Confidence:93
// Compiler-generated MSVC scalar deleting destructor for WebBoardDialogOld.
// Reconstruct virtual ~WebBoardDialogOld() and the ordinary destructor body emitted by UID000212.
// Let the compiler regenerate vtable deleting dispatch, +0xa0/+0xa4 adjustor thunks,
// BrowserPane/DialogPane base destruction, deleting-flag handling, the 0x278 guarded-size path,
// return-this ABI behavior, and storage release. Do not hand-author this wrapper.

// UID:0000SQ | by-global/g_pWebBoardDialog.md | Completion:90 | Confidence:94
WebBoardDialog *g_pWebBoardDialog = NULL;

// UID:0000SR | by-global/g_pWebBoardDialogOld.md | Completion:90 | Confidence:94
WebBoardDialogOld *g_pWebBoardDialogOld = NULL;

// UID:0003V1 | by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md | Completion:86 | Confidence:89
// Active EscapeWebBoardUrl source is emitted with [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md).
// Active guard/table declarations are emitted with [UID:0002AG][0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState](by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md).
// This raw helper page documents the retained helper range only; do not
// duplicate the active helper body, guard/table storage, or character literals here.

// UID:000278 | by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md | Completion:90 | Confidence:94
// Active WebBoard URL escape literals are emitted once with UID0000Z9.
// Old WebBoard URL escape literals are emitted once with UID000214.
// This exact initialized-data page documents both literal pairs and must not
// emit duplicate character arrays.

// UID:0003V2 | by-memory\0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003V3 | by-memory\0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003V4 | by-memory\0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003V5 | by-memory\0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md | Completion:88 | Confidence:90 | Empty Emitter Marker
