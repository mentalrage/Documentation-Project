// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L0
// Source by-file doc: by-file/MainMenuPane.md
// UID:00007O | by-class/MainMenuPane.md | Completion:92 | Confidence:94
#include "../ui/core/BlackHole.h"
#include "HistoryViewingPane.h"
#include "MainMenuPane.h"

// UID:00019K | by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md | Completion:93 | Confidence:94
#include "../profile/ProfileStorage.h"

void MainMenuPane::InitializeMainUiGraph()
{
    RectBounds bounds;

    if (g_useEpfAssets == 1) {
        g_mainUiLayerSlots.overlayPaneLayerContext->MarkAllPanesForDeletion();

        BackPane *backPane = new BackPane(L"FRAME.EPF");
        backPane->GetBounds(&bounds);
        backPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.rootPaneLayerContext);
        backPane->SetPaneOrder(0, NULL);

        MapPane *mapPane = new MapPane(17, 15);
        InitRectBounds(
            &bounds,
            -g_mapTilePixelWidth,
            -g_mapTilePixelHeight,
            18 * g_mapTilePixelWidth,
            16 * g_mapTilePixelHeight);
        mapPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapPane->SetPaneOrder(0, backPane);

        ChattingBackPane *chattingBackPane = new ChattingBackPane();
        InitRectBounds(&bounds, 9, 596, 816, 720);
        chattingBackPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingBackPane->SetPaneOrder(0, backPane);

        ChattingPane *chattingPane = new ChattingPane();
        InitRectBounds(&bounds, 23, 606, 806, 710);
        chattingPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingPane->SetPaneOrder(0, backPane);

        ChattingModifyHeightPane *modifyHeightPane =
            new ChattingModifyHeightPane();
        InitRectBounds(&bounds, 792, 590, 807, 605);
        modifyHeightPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        modifyHeightPane->SetPaneOrder(0, backPane);
        modifyHeightPane->SetLineCount(g_pConfig->m_chatVisibleLineCount);

        new GeneralPurposePanel();
        new GeneralPurposePanel2();
        BuildAboveFrameBorder();

        MapNamePane *mapNamePane = new MapNamePane();
        InitRectBounds(&bounds, 316, 0, 509, 24);
        mapNamePane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapNamePane->SetPaneOrder(0, backPane);

        MiniMapButtonPane *miniMapButtonPane = new MiniMapButtonPane();
        InitRectBounds(&bounds, 6, 6, 34, 34);
        miniMapButtonPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        miniMapButtonPane->SetPaneOrder(0, backPane);

        TabPane *tabPane = new TabPane();
        InitRectBounds(&bounds, 808, 79, 831, 365);
        tabPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        tabPane->SetPaneOrder(0, backPane);

        HourPane *hourPane = new HourPane();
        InitRectBounds(&bounds, 830, 736, 885, 751);
        hourPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        hourPane->SetPaneOrder(0, backPane);

        ChattingVarietyPane *chattingVarietyPane =
            new ChattingVarietyPane();
        InitRectBounds(&bounds, 10, 727, 72, 751);
        chattingVarietyPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingVarietyPane->SetPaneOrder(0, backPane);

        ChattingHandlePane *chattingHandlePane = new ChattingHandlePane();
        InitRectBounds(&bounds, 74, 727, 740, 751);
        chattingHandlePane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingHandlePane->SetPaneOrder(0, backPane);

        MenuVarietyPane *menuVarietyPane = new MenuVarietyPane();
        InitRectBounds(&bounds, 744, 727, 805, 751);
        menuVarietyPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        menuVarietyPane->SetPaneOrder(0, backPane);

        UserStatusPane *userStatusPane = new UserStatusPane(m_serverName);
        InitRectBounds(&bounds, 826, 16, 997, 58);
        userStatusPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        userStatusPane->SetPaneOrder(0, backPane);

        UserStatusPane2 *userStatusPane2 = new UserStatusPane2();
        InitRectBounds(&bounds, 881, 659, 1007, 753);
        userStatusPane2->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        userStatusPane2->SetPaneOrder(0, backPane);

        new SoundStatusPane();

        ParcelIconPane *parcelIconPane = new ParcelIconPane();
        parcelIconPane->SetPaneOrder(0, backPane);

        SetLocalPlayerName(m_serverName);

        delete g_pUserPane;
        UserPane *userPane = new UserPane();
        InitRectBounds(&bounds, 0, 0, 0, 0);
        userPane->SetPaneOrder(0, mapPane);

        char playerName[128];
        WideCharToMultiByte(
            CP_ACP,
            0,
            m_serverName,
            -1,
            playerName,
            sizeof(playerName),
            NULL,
            NULL);
        BuildPacketTransformKeyText(playerName);
    } else {
        BackPane *backPane = new BackPane(L"FRAME.EPD");
        InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
        backPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.rootPaneLayerContext);
        backPane->SetPaneOrder(0, NULL);

        MapPane *mapPane = new MapPane(17, 15);
        InitRectBounds(
            &bounds,
            14 - g_mapTilePixelWidth,
            12 - g_mapTilePixelHeight,
            18 * g_mapTilePixelWidth + 14,
            16 * g_mapTilePixelHeight + 12);
        mapPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapPane->SetPaneOrder(0, backPane);

        BuildAboveFrameBorder();

        MapNamePane *mapNamePane = new MapNamePane();
        InitRectBounds(&bounds, 131, 0, 304, 12);
        mapNamePane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapNamePane->SetPaneOrder(0, backPane);

        IconsPane *iconsPane = new IconsPane();
        InitRectBounds(&bounds, 263, 374, 422, 388);
        iconsPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        iconsPane->SetPaneOrder(0, backPane);

        HourPane *hourPane = new HourPane();
        InitRectBounds(&bounds, 14, 375, 43, 387);
        hourPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        hourPane->SetPaneOrder(0, backPane);

        new ConnStatusPane();
        InitRectBounds(&bounds, 244, 374, 263, 388);

        new GeneralPurposePanel();

        OldSystemMessagePane *systemMessagePane =
            new OldSystemMessagePane();
        InitRectBounds(&bounds, 441, 304, 639, 369);
        systemMessagePane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        systemMessagePane->SetPaneOrder(0, backPane);

        ChattingPane *chattingPane = new ChattingPane();
        InitRectBounds(&bounds, 14, 390, 434, 455);
        chattingPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        chattingPane->SetPaneOrder(0, backPane);

        OldUserStatusPane *userStatusPane =
            new OldUserStatusPane(m_serverName);
        InitRectBounds(&bounds, 434, 373, 627, 469);
        userStatusPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        userStatusPane->SetPaneOrder(0, backPane);

        new SoundStatusPane();

        ParcelIconPane *parcelIconPane = new ParcelIconPane();
        parcelIconPane->SetPaneOrder(0, backPane);

        SetLocalPlayerName(m_serverName);

        delete g_pUserPane;
        UserPane *userPane = new UserPane();
        InitRectBounds(&bounds, 0, 0, 0, 0);
        userPane->SetPaneOrder(0, mapPane);
    }

    LoadUserProfileData();
    g_pScreenPane->EnablePresentationMode();
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);

    delete g_pScreenDimmer;

    if (g_useEpfAssets != 1)
        new InterfaceEfxMgr();

    g_pInputMan->TrackInputTarget(0, false);
    g_pSoundManager->RestartMusic(3000);
    g_pApplication->m_inMapSession = true;
}

// UID:0004LY | by-memory/0x004f6700-0x004f6904.MainMenuPaneConstructor.md | Completion:90 | Confidence:93
MainMenuPane::MainMenuPane(bool fromTerminalTransition)
    : Pane(0),
      m_paintSuppressed(false),
      m_menuItemCount(6),
      m_selectedMenuItemIndex(1),
      m_fromTerminalTransition(fromTerminalTransition)
{
    m_serverName[0] = 0;

    g_pInputMan->SetInputMode(2);
    g_applicationPhase = 2;

    if (g_pConfig->m_useMenuMusic != 0)
        g_pSoundManager->PlayTrackByIndex(0, 100, 1);
    else
        g_pSoundManager->PlayTrackByIndex(999, 100, 1);

    ScheduleTimer(1, 20000, 0, 0);

    RectBounds bounds;
    InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
    InitializePane(&bounds, g_pMainMenuPane);
    SetPaneMode(0, g_pScreenPane);

    File levelFile(L"LEVEL.BMP", L"rb");
    if (levelFile.IsOpen()) {
        _AUTOBUF<unsigned char> bytes(levelFile.GetRemainingLength());
        levelFile.Read(bytes.GetBuffer(), bytes.GetSize());
        Decode8BitBmpToTileContext(
            bytes.GetBuffer(),
            bytes.GetSize(),
            &m_backgroundTileContext,
            &m_backgroundPalette);
    }
}

// UID:0004LZ | by-memory/0x004f6910-0x004f6998.MainMenuPaneDestructor.md | Completion:90 | Confidence:93
MainMenuPane::~MainMenuPane()
{
    g_pMidiPlayer->StopPlayback();
    CloseMainMenuDialogSingletons();
}

// UID:0004M0 | by-memory/0x004f6a40-0x004f6a5e.MainMenuPaneSetServerNameRaw.md | Completion:88 | Confidence:91
void MainMenuPane::SetServerName(const wchar_t *serverName)
{
    wcscpy_s(m_serverName, 128, serverName);
}

// UID:0004M1 | by-memory/0x004f6a60-0x004f6ae4.MainMenuPaneHandleSystemOrControlEvent.md | Completion:90 | Confidence:92
bool MainMenuPane::HandleSystemOrControlEvent(Event *event)
{
    if (event->m_type != kEventWorkNotification)
        return false;

    CloseMainMenuDialogSingletons();
    new ConnectionClosedDialog(this);
    return true;
}

// UID:0004M2 | by-memory/0x004f6af0-0x004f6be1.MainMenuPaneHandlePointerOrMouseEvent.md | Completion:90 | Confidence:93
bool MainMenuPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type != kEventCursorMove &&
        event->m_type != kEventLeftButtonUp)
        return true;

    const signed char oldPosition = m_selectedMenuItemIndex;
    m_selectedMenuItemIndex = HitTestMenuItem(
        this,
        event->m_payload.m_pointer.m_y,
        event->m_payload.m_pointer.m_x);

    if (m_selectedMenuItemIndex == -1)
        m_selectedMenuItemIndex = oldPosition;

    if (m_selectedMenuItemIndex != oldPosition) {
        RectBounds itemRect;
        ComputeMenuItemRect(oldPosition, &itemRect);
        InvalidateRect(&itemRect);
        ComputeMenuItemRect(m_selectedMenuItemIndex, &itemRect);
        InvalidateRect(&itemRect);
    }

    if (event->m_type == kEventLeftButtonUp)
        ActivateMenuItem();

    return true;
}

// UID:0004M3 | by-memory/0x004f6bf0-0x004f6ceb.MainMenuPaneHandleKeyOrTextEvent.md | Completion:90 | Confidence:93
bool MainMenuPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type != kEventKeyDown)
        return true;

    const signed char key = NarrowInputKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == 13) {
        ActivateMenuItem();
        return true;
    }

    const signed char oldPosition = m_selectedMenuItemIndex;
    switch (key) {
    case (signed char)0x80:
    case (signed char)0x81:
        if (m_selectedMenuItemIndex == -1)
            m_selectedMenuItemIndex = m_menuItemCount - 1;
        else
            m_selectedMenuItemIndex =
                (m_menuItemCount + m_selectedMenuItemIndex - 1) % m_menuItemCount;
        break;

    case (signed char)0x82:
    case (signed char)0x83:
        if (m_selectedMenuItemIndex == -1)
            m_selectedMenuItemIndex = 0;
        else
            m_selectedMenuItemIndex =
                (m_selectedMenuItemIndex + 1) % m_menuItemCount;
        break;

    default:
        return true;
    }

    RectBounds itemRect;
    ComputeMenuItemRect(oldPosition, &itemRect);
    InvalidateRect(&itemRect);
    ComputeMenuItemRect(m_selectedMenuItemIndex, &itemRect);
    InvalidateRect(&itemRect);
    return true;
}

// UID:0004M4 | by-memory/0x004f6d80-0x004f75ba.MainMenuPaneHandlePacketEvent.md | Completion:90 | Confidence:92
bool MainMenuPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);
    if (packet == NULL)
        return false;


## 2026-07-15 UID0003UP Config-Field Synchronization

- The complete dispatcher body, score, owner/emitter, source route, and all packet cases remain unchanged.
- Current base Config layout names the canonical server-directory block `m_serverDirectory`. Case `0x5b` consumes the ANSI `m_loginServerAddress` together with startup port/mode fields; it does not reinterpret the high endpoint or music buffers.
- The launcher storage is a typed protocol-view union. Earlier incomplete/opaque launcher and endpoint-role wording is historicalized, while exact packet ordering, UI behavior, and unrelated cases remain intact.
    switch (packet[0]) {
    case 0x00:
        switch (packet[1]) {
        case 0:
            InitializeMainMenuMetaData();
            g_pMetaMan->LoadMetaDatAndRequestSync();
            break;

        case 1:
            new AlertPane(
                g_pLanguageMan->GetLocalizedString(88),
                this,
                g_mainMenuAlertButtons,
                NULL);
            break;

        case 2:
        case 3: {
            unsigned char patchInfo[0x10606];
            BuildMainMenuPatchInfo(packet, patchInfo, sizeof(patchInfo));
            DestroyActiveScreenDimmer();

            if (packet[1] == 2) {
                new PatchPane(patchInfo);
            } else {
                File patchFile(L"Patch/Info", L"wb");
                if (patchFile.Write(patchInfo, sizeof(patchInfo)) != sizeof(patchInfo))
                    throw Win32Error(GetLastError());
                new PatchPane2(patchInfo);
            }
            return true;
        }
        }
        return false;

    case 0x03:
        return HandleLegacyMainMenuPacket(this, packet);

    case 0x49:
    case 0x6a:
        if (g_pTransferServerDialog != NULL)
            CloseDialogPane(g_pTransferServerDialog);
        return false;

    case 0x56: {
        unsigned char unpacked[2048];
        const unsigned short compressedLength = PacketBufferReadUInt16BE(packet + 1);
        InflatePacketBuffer(packet + 3, compressedLength, unpacked, sizeof(unpacked));

        ServerSelectDirectory &directory = g_pConfig->m_serverDirectory;
        directory.ReleaseOwnedBuffers();
        directory.entryCount = unpacked[0];

        const unsigned char *cursor = unpacked + 1;
        for (int index = 0; index < directory.entryCount; ++index) {
            ServerSelectEntry &entry = directory.entries[index];
            entry.serverId = cursor[0];
            entry.address[0] = cursor[4];
            entry.address[1] = cursor[3];
            entry.address[2] = cursor[2];
            entry.address[3] = cursor[1];
            entry.port = PacketBufferReadUInt16BE(cursor + 5);

            char text[256];
            strcpy_s(text, sizeof(text), reinterpret_cast<const char *>(cursor + 7));
            char *context = NULL;
            char *primary = strtok_s(text, ";", &context);
            char *secondary = strtok_s(NULL, ";", &context);
            if (secondary == NULL) {
                context = NULL;
                primary = strtok_s(text, ":", &context);
                secondary = strtok_s(NULL, ":", &context);
            }

            AssignServerSelectEntryText(&entry.name, primary != NULL ? primary : "");
            AssignServerSelectEntryText(&entry.description, secondary != NULL ? secondary : "");
            AssignServerSelectEntryText(&entry.agreementText, " ");
            cursor += strlen(reinterpret_cast<const char *>(cursor + 7)) + 8;
        }

        if (g_pServerSelectPane == NULL)
            new ServerSelectPane(&directory);
        return false;
    }

    case 0x5b: {
        int offset = 1;
        StringBase addressText;
        PacketBufferReadAnsiBytes16(&addressText, packet, &offset);
        g_pConfig->m_loginServerAddress = addressText;
        g_pConfig->m_loginServerPort = PacketBufferReadUInt16BE(packet + offset);
        offset += 2;
        g_pConfig->m_auxiliaryServerPort = PacketBufferReadUInt16BE(packet + offset);
        offset += 2;
        g_pConfig->m_serverMode = packet[offset];
        return false;
    }

    case 0x5e:
        if (g_pUserPane != NULL)
            g_pTimerMgr->RemovePendingTimersForOwner(&g_pUserPane->m_timerHandler);
        if (g_pTransferServerDialog != NULL)
            return true;
        new TransferServerDialogPane(true);
        return true;

    case 0x66:
        return HandleAnsiTextUrlDialogPacket(packet);

    case 0x6f:
        return g_pMetaMan->HandleMainMenuPacket(packet);
    }

    return false;
}

// UID:0004M5 | by-memory/0x004f7660-0x004f76cb.MainMenuPaneOnTimer.md | Completion:90 | Confidence:93
bool MainMenuPane::OnTimer(int timerId, int, int)
{
    if (timerId == 1) {
        if (!g_pIdleWatcher->IsIdle()) {
            unsigned char packet[1];
            packet[0] = 113;
            g_packetSender->QueueAndSendPacket(packet, sizeof(packet));
        }
        ScheduleTimer(1, 20000, 0, 0);
    }
    return true;
}

// UID:0004M6 | by-memory/0x004f76d0-0x004f79ec.MainMenuPaneOnPaint.md | Completion:90 | Confidence:92
void MainMenuPane::OnPaint()
{
    if (m_paintSuppressed)
        return;

    RectBounds destination = m_bounds;
    wchar_t versionText[32];
    swprintf_s(
        versionText,
        32,
        L"V%d.%d",
        g_pApplication->GetVersionMajor(),
        g_pApplication->GetVersionMinor());

    if (g_useEpfAssets == 1) {
        DrawUiFrame(L"TITLE.EPF", 0, L"TITLE.PAL", &destination);
        SetTextStyle(9, 16, 28);
        DrawText(versionText);

        for (signed char item = 0; item < m_menuItemCount; ++item) {
            RectBounds itemRect;
            ComputeMenuItemRect(item, &itemRect);
            DrawUiFrame(L"TITLEBUT.EPF", item, L"TITLEBUT.PAL", &itemRect);
        }

        if (m_selectedMenuItemIndex != -1) {
            RectBounds itemRect;
            ComputeMenuItemRect(m_selectedMenuItemIndex, &itemRect);
            DrawUiFrame(
                L"TITLESEL.EPF",
                m_selectedMenuItemIndex,
                L"TITLESEL.PAL",
                &itemRect);
        }
    } else {
        DrawUiFrame(L"TITLE.EPD", 0, L"NPAL2.PAL", &destination);
        SetTextStyle(9, 10, 20);
        DrawText(versionText);

        if (m_selectedMenuItemIndex != -1) {
            RectBounds itemRect;
            ComputeMenuItemRect(m_selectedMenuItemIndex, &itemRect);
            DrawUiFrame(
                L"TITLESEL.EPD",
                m_selectedMenuItemIndex,
                L"NPAL2.PAL",
                &itemRect);
        }
    }
}

// UID:0004M7 | by-memory/0x004f79f0-0x004f7a0d.MainMenuPaneSetPaintSuppressedRaw.md | Completion:88 | Confidence:91
void MainMenuPane::SetPaintSuppressed(bool suppressed)
{
    InvalidateRect(&m_bounds);
    m_paintSuppressed = suppressed;
}

// UID:0004M8 | by-memory/0x004f7a10-0x004f7ce9.MainMenuPaneActivateMenuItem.md | Completion:90 | Confidence:93
void MainMenuPane::ActivateMenuItem()
{
    switch (m_selectedMenuItemIndex) {
    case 0:
        OpenCreateUserDialog();
        break;

    case 1:
        if (g_pLoginDialogPane == NULL)
            new LoginDialogPane;
        break;

    case 2:
        OpenChangePasswordDialog();
        break;

    case 3:
        OpenStoryViewingPane();
        break;

    case 4:
        OpenHistoryViewingPane();
        break;

    case 5:
        OpenTerminalPane(this);
        break;
    }
}


// UID:0000RF | by-global/g_pMainMenuPane.md | Completion:92 | Confidence:94
// UID:0002AF | by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md | Completion:93 | Confidence:94
class MainMenuPane;

MainMenuPane *g_pMainMenuPane = NULL;

// UID:0000PH | by-global/CloseMainMenuDialogSingletons_4F69A0.md | Completion:86 | Confidence:90
// CloseMainMenuDialogSingletons is emitted by exact helper [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md); this address-suffixed global page is an alias/search marker and does not duplicate the helper body.

// UID:0000PI | by-global/ComputeMenuItemRect_4F8B90.md | Completion:86 | Confidence:90
// ComputeMenuItemRect is emitted by exact helper [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md); this address-suffixed global page is an alias/search marker and does not duplicate the helper body.

// UID:0000SZ | by-global/HandleLegacyMainMenuPacket_4F8D00.md | Completion:86 | Confidence:90
// HandleLegacyMainMenuPacket is emitted by exact helper [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md); this address-suffixed global page preserves packet-helper evidence without duplicating the body.

// UID:0000T1 | by-global/HitTestMenuItem_4F8C10.md | Completion:86 | Confidence:90
// HitTestMenuItem is emitted by exact helper [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md); this address-suffixed global page is an alias/search marker and does not duplicate the hit-test body.

// UID:0000TA | by-global/OpenChangePasswordDialog_4F9060.md | Completion:88 | Confidence:90
// OpenChangePasswordDialog is emitted by exact helper [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.

// UID:0000TB | by-global/OpenCreateUserDialog_4F8FA0.md | Completion:86 | Confidence:90
// OpenCreateUserDialog is emitted by exact helper [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.

// UID:0000TC | by-global/OpenHistoryViewingPane_4F9140.md | Completion:86 | Confidence:90
// OpenHistoryViewingPane is emitted by exact helper [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.

// UID:0000TE | by-global/OpenStoryViewingPane_4F90C0.md | Completion:86 | Confidence:90
// OpenStoryViewingPane is emitted by exact helper [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.

// UID:0000TF | by-global/OpenTerminalPane_4F91C0.md | Completion:86 | Confidence:90
// OpenTerminalPane is emitted by exact helper [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.

// UID:00019J | by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md | Completion:88 | Confidence:91
static void CloseMainMenuDialogSingletons()
{
    if (g_pScreenDimmer != NULL)
        delete g_pScreenDimmer;

    if (g_pLoginDialogPane != NULL)
        CloseDialogPane(g_pLoginDialogPane);

    if (g_pChangePasswordDialogPane != NULL)
        CloseDialogPane(g_pChangePasswordDialogPane);

    if (g_pBackStoryDialogPane != NULL)
        CloseDialogPane(g_pBackStoryDialogPane);

    if (g_pHistoryViewingPane != NULL)
        g_pHistoryViewingPane->MarkForDeletion();

    if (g_pForcedInformMessageDialog != NULL)
        CloseDialogPane(g_pForcedInformMessageDialog);

    if (g_pServerSelectPane != NULL)
        CloseDialogPane(g_pServerSelectPane);

    if (g_useEpfAssets == 1) {
        if (g_pNewCreateUserDialogPane != NULL)
            CloseDialogPane(g_pNewCreateUserDialogPane);
    } else {
        if (g_pNewUserDialogPane2 != NULL)
            CloseDialogPane(g_pNewUserDialogPane2);
    }
}

// UID:00019M | by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md | Completion:88 | Confidence:92
static void __stdcall ComputeMenuItemRect(signed char itemIndex, RectBounds *outRect)
{
    if (itemIndex == -1) {
        InitRectBounds(outRect, 0, 0, 0, 0);
        return;
    }

    if (g_useEpfAssets == 1) {
        const int top = 493 + 41 * itemIndex;
        InitRectBounds(outRect, 781, top, 972, top + 39);
    } else {
        const int top = 299 + 30 * itemIndex;
        InitRectBounds(outRect, 467, top, 640, top + 30);
    }
}

// UID:00019N | by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md | Completion:87 | Confidence:91
static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)
{
    if (pane->m_menuItemCount <= 0)
        return -1;

    for (signed char itemIndex = 0; itemIndex < pane->m_menuItemCount; ++itemIndex) {
        RectBounds itemRect;
        ComputeMenuItemRect(itemIndex, &itemRect);
        if (PointInRect(mouseY, mouseX, &itemRect))
            return itemIndex;
    }

    return -1;
}

// UID:00019O | by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md | Completion:88 | Confidence:91
static bool HandleLegacyMainMenuPacket(MainMenuPane *pane, const unsigned char *payload)
{
    DATFile datFile;
    unsigned char text[256];
    unsigned char packet[1024];

    const unsigned int reconnectAddress = PacketBufferReadUInt32BE(payload + 1);
    const unsigned short reconnectPort = PacketBufferReadUInt16BE(payload + 5);
    const unsigned char textLength = payload[7];

    memcpy(text, payload + 8, textLength);
    text[textLength] = '\0';

    if (g_packetSender->IsSocketConnectedState()) {
        g_packetSender->PostReconnectEndpointCommand(reconnectAddress, reconnectPort);

        bool connectionAvailable = false;
        HANDLE resultEvent = g_packetSender->PostConnectionStatusQuery(&connectionAvailable);
        g_packetSender->WaitForResult(resultEvent);

        if (!connectionAvailable) {
            new AlertPane(g_pLanguageMan->GetLocalizedString(0x9d), pane, NULL, NULL);
            g_pApplication->RequestExit();
        }
    }

    PacketBufferWriteUInt8(0x10, packet);
    memcpy(packet + 1, text, textLength);
    PacketBufferWriteUInt8(g_useEpfAssets, packet + textLength + 1);
    packet[textLength + 2] = '\0';

    g_packetSender->SetSocketSendDisabled(false);
    g_packetSender->QueueAndSendPacket(packet, textLength + 2);

    if (g_pScreenDimmer != NULL)
        delete g_pScreenDimmer;

    g_pMetaMan->LoadMetaDatAndRequestSync();
    return true;
}

// UID:0002Q6 | by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md | Completion:88 | Confidence:90
static bool __stdcall OpenTransferServerDialog(int)
{
    if (g_pUserPane != NULL)
        g_pTimerMgr->RemovePendingTimersForOwner(&g_pUserPane->m_timerHandler);

    if (g_pTransferServerDialog == NULL)
        new TransferServerDialogPane(true);

    return true;
}

// UID:00019P | by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md | Completion:88 | Confidence:90
static void OpenCreateUserDialog()
{
    if (g_useEpfAssets == 1) {
        if (g_pLoginDialogPane != NULL)
            CloseDialogPane(g_pLoginDialogPane);

        new CreateUserDialogPane;
        g_pSoundManager->PlayTrackByIndex(0, 100, 1);
    } else {
        new NewUserDialogPane2;
    }
}

// UID:00019Q | by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md | Completion:88 | Confidence:90
static void OpenChangePasswordDialog()
{
    new ChangePasswordDialogPane;
}

// UID:0003H6 | by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md | Completion:88 | Confidence:90
static void OpenStoryViewingPane()
{
    if (g_useEpfAssets == 1)
        new HistoryViewingPane(L"STORY.EPF");
    else
        new HistoryViewingPane(L"STORY.EPD");
}

// UID:0003H7 | by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md | Completion:88 | Confidence:90
static void OpenHistoryViewingPane()
{
    if (g_useEpfAssets == 1)
        new HistoryViewingPane(L"HISTORY.EPF");
    else
        new HistoryViewingPane(L"HISTORY.EPD");
}

// UID:00019S | by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md | Completion:88 | Confidence:90
static void OpenTerminalPane(MainMenuPane *pane)
{
    g_packetSender->SendCleanupPacket();
    g_packetSender->WaitForQueueDrain();

    if (g_pLoginDialogPane != NULL)
        CloseDialogPane(g_pLoginDialogPane);

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(pane);

    if (g_pConfig->m_startupTerminalReady != 0) {
        g_pApplication->RequestExit();
    } else {
        new TerminalPane;
    }

    g_pSoundManager->PlaySample(0x192, 100);
}

// UID:00022Y | by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md | Completion:87 | Confidence:90
static void DestroyActiveScreenDimmer()
{
    if (g_pScreenDimmer != 0)
        delete g_pScreenDimmer;
}

static bool HandleAnsiTextUrlDialogPacket(const unsigned char *packet)
{
    int offset = 1;
    unsigned char subtype = packet[offset++];

    DestroyActiveScreenDimmer();

    if (subtype == 1 || subtype == 2) {
        unsigned short urlLength = PacketBufferReadUInt16BE(packet + offset);
        const char *urlText = reinterpret_cast<const char *>(packet + offset + 2);
        offset += 2 + urlLength;

        unsigned short messageLength = PacketBufferReadUInt16BE(packet + offset);
        offset += 2;

        wchar_t messageText[1000];
        int wideLength = MultiByteToWideChar(
            0,
            0,
            reinterpret_cast<const char *>(packet + offset),
            messageLength,
            messageText,
            999);
        messageText[wideLength] = 0;

        new UrlAlertPane(
            subtype == 1,
            g_pMainMenuPane,
            messageText,
            urlText,
            urlLength);
    } else if (subtype == 3) {
        StringBase overrideUrl;
        PacketBufferReadAnsiBytes8(&overrideUrl, packet, &offset);
        g_ncauthConfirmUserUrlOverrideString = overrideUrl;
    }

    return true;
}

// UID:0003P6 | by-memory\0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer.md | Completion:86 | Confidence:92 | Empty Emitter Marker
