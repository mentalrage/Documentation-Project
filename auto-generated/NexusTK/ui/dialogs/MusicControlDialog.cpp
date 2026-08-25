// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LN
// Source by-file doc: by-file/MusicControlDialog.md
// UID:00008U | by-class/MusicControlDialog.md | Completion:93 | Confidence:95
#include "MusicControlDialog.h"
#include "FolderSelectDialog.h"

// UID:0003MB | by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md | Completion:90 | Confidence:93
enum MusicControlId {
    kControlSoundEffects = 1,
    kControlSampleVolume = 2,
    kControlSoundFrequency = 3,
    kControlMusicVolume = 4,
    kControlMusicSourceMode = 5,
    kControlMusicFolderPath = 6,
    kControlBrowseFolder = 7,
    kControlCdDrive = 8,
    kControlShuffleMusic = 9,
    kControlRepeatMusic = 10,
    kControlPreviousTrack = 11,
    kControlPausePlay = 12,
    kControlNextTrack = 13,
    kControlClose = 14,
};

enum MusicSourceMode {
    kMusicSourceDisabled = 0,
    kMusicSourceStream = 1,
    kMusicSourceRedbook = 2,
};

static void SendMusicDialogOptionPacket(uint8_t optionCode)
{
    uint8_t packet[3];
    packet[0] = 0x1b;
    packet[1] = 0x01;
    packet[2] = optionCode;
    QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
}

MusicControlDialog::MusicControlDialog()
    : DialogPane()
{
    m_musicPaused = false;

    LoadDialogControlResource(L"DLGSCNTL.EPF", L"PFLOOK.PAL");

    AddControl(kControlSoundEffects, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlSampleVolume, new SliderControlPane(/* resource/control operands */));
    AddControl(kControlSoundFrequency, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlMusicVolume, new SliderControlPane(/* resource/control operands */));
    AddControl(kControlMusicSourceMode, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlMusicFolderPath, new TextEditPane(/* resource/control operands */));
    AddControl(kControlBrowseFolder, new ImageButtonControlPane(/* resource/control operands */));
    AddControl(kControlCdDrive, new PopupMenuControlPane(/* resource/control operands */));
    AddControl(kControlShuffleMusic, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlRepeatMusic, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlPreviousTrack, new ImageButtonControlPane(/* resource/control operands */));
    AddControl(kControlPausePlay, new SelectionControlPane(/* resource/control operands */));
    AddControl(kControlNextTrack, new ImageButtonControlPane(/* resource/control operands */));
    AddControl(kControlClose, new ImageButtonControlPane(/* resource/control operands */));

    SetControlText(kControlMusicFolderPath, g_pConfig->m_musicFolderPath);
    ResetTextSelection(kControlMusicFolderPath, 0, 0);

    PopupMenuControlPane *drivePopup = GetControlAs<PopupMenuControlPane>(kControlCdDrive);
    for (wchar_t drive = L'A'; drive <= L'Z'; ++drive)
    {
        char rootPath[] = "X:\\";
        wchar_t label[] = L"X:";
        rootPath[0] = static_cast<char>(drive);
        label[0] = drive;

        if (GetDriveTypeA(rootPath) != DRIVE_CDROM)
            continue;

        int itemIndex = drivePopup->AppendString(label);
        if (drive == g_pConfig->m_redbookDriveLetter)
            drivePopup->SetSelectedIndex(itemIndex);
    }
    drivePopup->AppendString(L"");

    SetSliderValue(kControlSampleVolume, g_pSoundManager->GetSampleVolume());
    SetSliderValue(kControlMusicVolume, g_pSoundManager->GetStreamVolume());

    int soundFrequencySelection = 0;
    if (g_pSoundManager->IsPlaybackEnabled())
        soundFrequencySelection = (g_pConfig->m_soundFrequency == 2) ? 2 : 1;
    SetSelectedValue(kControlSoundFrequency, soundFrequencySelection);

    SetSelectedValue(kControlSoundEffects,
        g_pSoundManager->IsSoundEffectsEnabled() ? 0 : 1);
    SetSelectedValue(kControlMusicSourceMode, g_pConfig->m_musicSourceMode);
    SetSelectedValue(kControlShuffleMusic, g_pConfig->m_randomizeMusicOrder ? 1 : 0);
    SetSelectedValue(kControlRepeatMusic, g_pConfig->m_repeatMusic ? 0 : 1);

    UpdateActionButton();
    SendMusicDialogOptionPacket(0);
}

// UID:0003MC | by-memory/0x00529770-0x0052978f.MusicControlDialogNonDeletingDestructor.md | Completion:87 | Confidence:91
// MusicControlDialog non-deleting destructor body is compiler-generated from
// the class destructor declaration and inherited DialogPane teardown. The
// source carrier is the class/destructor declaration; this exact binary helper
// should not emit a duplicate standalone function body.

// UID:0003MD | by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md | Completion:88 | Confidence:90
void MusicControlDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    switch (controlIndex)
    {
    case kControlSoundEffects:
        SendMusicDialogOptionPacket(0x0d);
        ApplySoundEffectEnabled(GetSelectedValue(kControlSoundEffects) != 1);
        break;

    case kControlSampleVolume:
        g_pSoundManager->SetSampleVolume(GetSliderValue(kControlSampleVolume));
        break;

    case kControlSoundFrequency:
        ApplySoundFrequencySelection(
            GetSelectedValue(kControlSoundFrequency));
        break;

    case kControlMusicVolume:
        g_pSoundManager->SetStreamVolume(GetSliderValue(kControlMusicVolume));
        break;

    case kControlMusicSourceMode:
    {
        int mode = GetSelectedValue(kControlMusicSourceMode);
        if (g_pConfig->m_musicSourceMode != mode)
        {
            g_pConfig->m_musicSourceMode = mode;
            ApplyPlaybackState();
        }
        break;
    }

    case kControlMusicFolderPath:
        break;

    case kControlBrowseFolder:
    {
        StringBaseW currentPath = GetControlText(kControlMusicFolderPath);
        typedef void (MusicControlDialog::*FolderPathCallback)(StringBaseW);
        FolderSelectCallback *callback =
            new PlainMemberFunctionObjectT<
                FolderPathCallback,
                MusicControlDialog,
                StringBaseW>(
                    this, &MusicControlDialog::FolderPathSelected);
        new FolderSelectDialog(callback, currentPath.c_str());
        break;
    }

    case kControlCdDrive:
    {
        PopupMenuControlPane *popup = GetControlAs<PopupMenuControlPane>(kControlCdDrive);
        int selectedIndex = popup->GetSelectedIndex();
        if (selectedIndex < 0)
            break;

        wchar_t driveLetter = ParseDriveLetter(popup->GetSelectedText(selectedIndex));
        if (driveLetter != 0 && g_pConfig->m_redbookDriveLetter != driveLetter)
        {
            g_pConfig->m_redbookDriveLetter = driveLetter;
            ApplyPlaybackState();
        }
        break;
    }

    case kControlShuffleMusic:
        g_pConfig->m_randomizeMusicOrder =
            (GetSelectedValue(kControlShuffleMusic) != 0);
        break;

    case kControlRepeatMusic:
        g_pConfig->m_repeatMusic =
            (GetSelectedValue(kControlRepeatMusic) == 0);
        break;

    case kControlPreviousTrack:
        if (g_pConfig->m_musicSourceMode == kMusicSourceStream)
        {
            if (g_pSoundManager->currentStreamTrackIndex() > 1)
            {
                g_pSoundManager->PlayStreamTrack(
                    g_pSoundManager->currentStreamTrackIndex() - 1,
                    100,
                    true);
            }
        }
        else if (g_pConfig->m_musicSourceMode == kMusicSourceRedbook)
        {
            g_pSoundManager->RewindRedbookTrack();
        }

        if (m_musicPaused)
            TogglePauseState();
        break;

    case kControlPausePlay:
        TogglePauseState();
        break;

    case kControlNextTrack:
        g_pSoundManager->setMusicAdvanceRequested(true);
        if (g_pConfig->m_musicSourceMode == kMusicSourceStream)
            g_pSoundManager->PlayNextTrack();
        else if (g_pConfig->m_musicSourceMode == kMusicSourceRedbook)
            g_pSoundManager->AdvanceRedbookTrack();

        if (m_musicPaused)
            TogglePauseState();
        break;

    case kControlClose:
        CloseDialog();
        break;

    default:
        break;
    }
}

// UID:0003ME | by-memory/0x00529b70-0x00529bda.MusicControlDialogUnmodeledSoundEffectApply.md | Completion:87 | Confidence:88
// Retained raw MusicControlDialog sound-effect payload helper. Current MCP
// finds no function object, caller, switch-table entry, vtable slot,
// member-function pointer, VA pointer, or RVA pointer route to 0x00529b70.
// The reachable command and packet paths emit the source behavior; this page
// records the raw body evidence and should not emit a duplicate helper.

// UID:0003MF | by-memory/0x00529be0-0x00529c5a.MusicControlDialogSoundEffectPacketHandler.md | Completion:87 | Confidence:90
bool MusicControlDialog::HandlePacketEvent(Event *event)
{
    const char *payload = reinterpret_cast<const char *>(
        event->m_payload.m_packet.m_data);

    if (payload[0] != '#')
        return false;

    const bool enabled = ParseOptionByte(payload + 5) == 1;
    SetSelectedValue(kControlSoundEffects, enabled ? 0 : 1);

    g_pConfig->m_soundEffectsEnabled = enabled ? 1 : 0;
    if (enabled)
        g_pSoundManager->EnableSoundEffects();
    else
        g_pSoundManager->DisableSoundEffects();

    return true;
}

// UID:0003MG | by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md | Completion:87 | Confidence:90
bool MusicControlDialog::HandleType19Event(Event *event)
{
    const unsigned int kBrowseDirectoryNotification = 0x42446972;

    if (event->m_payload.m_notification.m_channel !=
        kBrowseDirectoryNotification)
    {
        return false;
    }

    const char *path = reinterpret_cast<const char *>(
        event->m_payload.m_notification.m_payload) + 4;

    if (*path != '\0')
    {
        mystr::StringBase<char, mystr::mychar_traits<char> > ansiPath(path);
        StringBaseW widePath(ansiPath);
    }

    g_pApplication->m_browseDirectoryPending = false;
    return true;
}

// UID:0003MH | by-memory/0x00529d00-0x00529ed1.MusicControlDialogRefreshControlStates.md | Completion:88 | Confidence:90
void MusicControlDialog::UpdateActionButton()
{
    SetControlEnabled(kControlSampleVolume,
        GetSelectedValue(kControlSoundEffects) == 0);
    SetControlEnabled(kControlMusicVolume,
        GetSelectedValue(kControlSoundFrequency) != 0);

    switch (GetSelectedValue(kControlMusicSourceMode))
    {
    case kMusicSourceDisabled:
        SetControlEnabled(kControlMusicFolderPath, false);
        SetControlEnabled(kControlBrowseFolder, false);
        SetControlEnabled(kControlCdDrive, false);
        SetControlEnabled(kControlShuffleMusic, false);
        SetControlEnabled(kControlRepeatMusic, false);
        SetControlEnabled(kControlPreviousTrack, false);
        SetControlEnabled(kControlPausePlay, false);
        SetControlEnabled(kControlNextTrack, false);
        return;

    case kMusicSourceStream:
        SetControlEnabled(kControlMusicFolderPath, true);
        SetControlEnabled(kControlBrowseFolder, true);
        SetControlEnabled(kControlCdDrive, false);
        break;

    case kMusicSourceRedbook:
        SetControlEnabled(kControlMusicFolderPath, false);
        SetControlEnabled(kControlBrowseFolder, false);
        SetControlEnabled(kControlCdDrive, true);
        break;

    default:
        return;
    }

    SetControlEnabled(kControlShuffleMusic, true);
    SetControlEnabled(kControlRepeatMusic, true);
    SetControlEnabled(kControlPreviousTrack, true);
    SetControlEnabled(kControlPausePlay, true);
    SetControlEnabled(kControlNextTrack, true);
}

// UID:0003MI | by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md | Completion:88 | Confidence:92
void MusicControlDialog::FolderPathSelected(StringBaseW path)
{
    if (path.empty())
        return;

    if (g_pConfig->m_musicFolderPath == path)
        return;

    g_pConfig->m_musicFolderPath = path;
    SetControlText(kControlMusicFolderPath, path);
    ResetTextSelection(kControlMusicFolderPath, 0, 0);

    g_pSoundManager->ScanMusicDirectory(
        path.c_str(),
        g_pConfig->m_randomizeMusicOrder != 0,
        true);

    ApplyPlaybackState();
}

// UID:0003MJ | by-memory/0x0052a010-0x0052a120.MusicControlDialogDrivePopupPopulate.md | Completion:87 | Confidence:91
void MusicControlDialog::PopulateCdDrivePopup()
{
    PopupMenuControlPane* popup = GetControlAs<PopupMenuControlPane>(kControlCdDrive);

    for (wchar_t drive = L'A'; drive <= L'Z'; ++drive)
    {
        char rootPath[] = "X:\\";
        wchar_t label[] = L"X:";
        rootPath[0] = static_cast<char>(drive);
        label[0] = drive;

        if (GetDriveTypeA(rootPath) != DRIVE_CDROM)
            continue;

        const int index = popup->AppendString(label);
        if (drive == g_pConfig->m_redbookDriveLetter)
            popup->SetSelectedIndex(index);
    }

    popup->AppendString(L"");
}

// UID:0003MK | by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md | Completion:88 | Confidence:92
void MusicControlDialog::ApplyPlaybackState()
{
    if (m_musicPaused)
        TogglePauseState();

    switch (g_pConfig->m_musicSourceMode)
    {
    case kMusicSourceDisabled:
        g_pSoundManager->StopMusicPlayback(0);
        if (g_pConfig->m_musicSourceMode == kMusicSourceDisabled)
        {
            g_pSoundManager->PlayMusicByZone(
                g_activeMapPane->m_zoneMusicId,
                g_activeMapPane->m_zoneMusicFallbackTrackIndex,
                g_activeMapPane->m_zoneMusicVolumeScale,
                0);
        }
        break;

    case kMusicSourceStream:
        g_pSoundManager->RestartMusic(0);
        break;

    case kMusicSourceRedbook:
        g_pSoundManager->OpenRedbookDrive(g_pConfig->m_redbookDriveLetter);
        g_pSoundManager->RestartMusic(0);
        break;

    default:
        break;
    }
}

// UID:0003ML | by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md | Completion:88 | Confidence:92
void MusicControlDialog::TogglePauseState()
{
    m_musicPaused = !m_musicPaused;

    if (g_pConfig->m_musicSourceMode == kMusicSourceStream)
        g_pSoundManager->SetStreamPaused(m_musicPaused);
    else if (g_pConfig->m_musicSourceMode == kMusicSourceRedbook)
        g_pSoundManager->SetRedbookPaused(m_musicPaused);

    SetSelectedValue(kControlPausePlay, m_musicPaused ? 37 : 48);
}

// UID:0003MM | by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md | Completion:89 | Confidence:90
// Retained raw MusicControlDialog folder-path control refresh helper. Current
// MCP/PE checks find no function object, caller, switch-table entry, vtable slot,
// member-function pointer, VA/RVA/file-offset pointer, or relative branch/call
// route to 0x0052a1f0.
// The reachable FolderPathSelected path emits the config copy, control text,
// selection reset, scan, and playback behavior; this raw UI-text subset should
// not emit a duplicate helper body.

// UID:0003MN | by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md | Completion:88 | Confidence:90
// Retained raw MusicControlDialog next-track helper. Current MCP finds no
// function object, caller, switch-table entry, vtable slot, member-function
// pointer, VA pointer, or RVA pointer route to 0x0052a230. Command case 13
// inside HandleControlCommand carries the reachable source path, so this raw
// duplicate should not emit a standalone helper body.

// UID:0003MO | by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md | Completion:89 | Confidence:91
// UID0003MO is a retained raw MusicControlDialog previous-track helper body.
// Current MCP session 507affd6 finds no function object, incoming xref,
// command-switch entry, vtable slot, member-function pointer, VA pointer, RVA
// pointer, file-offset pointer, or source-entry route to 0x0052a280. A
// read-only PE scan found no relative call/jump/branch route either. Command
// case 11 in UID0003MD carries the live inline previous-track source path, so
// this child must not emit a standalone helper body.

// UID:0003MQ | by-memory/0x0052a310-0x0052a3e0.MusicControlDialogApplyOutputSelection.md | Completion:93 | Confidence:95
void MusicControlDialog::ApplySoundFrequencySelection(int selection)
{
    if (selection == 0)
    {
        g_pSoundManager->MuteMusic();
        return;
    }

    if (g_pConfig->m_soundFrequency != selection)
    {
        g_pConfig->m_soundFrequency = static_cast<unsigned char>(selection);
        new AlertPane(
            g_pLanguageMan->GetLocalizedString(244),
            this,
            L"OK",
            NULL);
    }

    if (!g_pSoundManager->IsPlaybackEnabled())
        g_pSoundManager->UnmuteMusic();
}

// UID:0003MR | by-memory/0x0052a4e0-0x0052a535.MusicControlDialogScalarDeletingDestructor.md | Completion:87 | Confidence:91
// MusicControlDialog scalar deleting destructor wrapper is compiler-generated
// from the class destructor declaration, inherited teardown, and delete flags.
// The rebuilt compiler should regenerate this wrapper and the related adjustor
// thunks; this exact binary helper should not emit standalone source.


// UID:00025Y | by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md | Completion:87 | Confidence:91
// MusicControlDialog read-only vtables, RTTI-adjacent cells, resource
// literals, and folder-callback vtable cells are regenerated from the class,
// virtual method, resource, and FunctionObject declarations. This page records
// the physical .rdata evidence and should not emit duplicate source bytes.

// UID:0001CP | by-memory/0x00528e60-0x0052a535.MusicControlDialog.md | Completion:92 | Confidence:94
// MusicControlDialog executable aggregate is a source-layout index over exact
// child methods, callback wrappers, compiler support, retained raw bodies,
// and data pages. Source output is emitted by the exact child pages or by their
// formal no-code markers; this aggregate should not emit duplicate C++.

// UID:0003MP | by-memory/0x0052a2d0-0x0052a304.MusicControlDialogApplySoundEffectEnabled.md | Completion:90 | Confidence:94
static void __stdcall ApplySoundEffectEnabled(bool enabled)
{
    g_pConfig->m_soundEffectsEnabled = enabled ? 1 : 0;

    if (enabled)
        g_pSoundManager->EnableSoundEffects();
    else
        g_pSoundManager->DisableSoundEffects();
}

// UID:00027V | by-memory/0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md | Completion:88 | Confidence:91
static char RootPathName[4] = "X:\\";
static wchar_t MusicControlDriveLabel[4] = L"X:";
static int MusicControlDriveRootBufferTail = 0x50;

// UID:00040O | by-memory\0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md | Completion:86 | Confidence:91 | Empty Emitter Marker
