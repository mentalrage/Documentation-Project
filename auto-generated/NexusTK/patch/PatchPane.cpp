// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MH
// Source by-file doc: by-file/PatchPane.md
// UID:0000AC | by-class/PatchPane__PatchFileSlice.md | Completion:88 | Confidence:91
class PatchPane::PatchFileSlice {
    friend class PatchPane;

public:
    PatchFileSlice();
    virtual ~PatchFileSlice();

private:
    bool m_requestIssued;
    unsigned int m_payloadLength;
    unsigned char *m_payloadData;
};

// UID:0000RZ | by-global/g_pPatchPane2.md | Completion:92 | Confidence:94
PatchPane2 *g_pPatchPane2 = 0;

// UID:0000AA | by-class/PatchPane2.md | Completion:92 | Confidence:94
class WorkThreadNotification;

class PatchPane2 : public DialogPane, public Singleton<PatchPane2> {
public:
    explicit PatchPane2(const unsigned char *patchInfo);
    virtual ~PatchPane2();

    virtual bool AcceptsDownloadWorkEvent(const WorkThreadNotification *event);
    virtual bool HandleDownloadWorkEvent(const WorkThreadNotification *event);

private:
    void ClosePatchFile();
    void FinishAndExit(const wchar_t *message);
    void SendDownloadRequest();
    void ReportWriteError(const wchar_t *path);

    StringBase<wchar_t> m_finalPatchPath;
    StringBase<wchar_t> m_tempPatchPath;
    std::vector<StringBase<wchar_t> > m_patchFileNames;
    unsigned int m_currentDownloadIndex;
    FILE *m_activePatchFile;
    unsigned int m_downloadPassCount;
    unsigned int m_patchVersionMajor;
    unsigned int m_patchVersionMinor;
};
// UID:0004VS | by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md | Completion:92 | Confidence:94
PatchPane2::PatchPane2(const unsigned char *patchInfo)
    : DialogPane(L"", static_cast<unsigned short>(-1), 1),
      Singleton<PatchPane2>(),
      m_currentDownloadIndex(0),
      m_activePatchFile(0),
      m_downloadPassCount(0),
      m_patchVersionMajor(patchInfo[0] | (patchInfo[1] << 8)),
      m_patchVersionMinor(patchInfo[2] | (patchInfo[3] << 8))
{
    const int width = 200;
    const int height = 100;
    const int left = (g_pScreenPane->GetScreenWidth() - width) / 2;
    const int top = (g_pScreenPane->GetScreenHeight() - height) / 2;

    RectBounds dialogBounds;
    InitRectBounds(&dialogBounds, left, top, left + width, top + height);

    RectBounds controlBounds;
    InitRectBounds(&controlBounds,
                   width / 4,
                   10,
                   width * 3 / 4,
                   height / 4);
    AddControl(new StaticTextControlPane(
        L"Ready", false, 128, 143, &controlBounds, false, false));

    InitRectBounds(&controlBounds,
                   10,
                   height / 4 + 10,
                   width - 10,
                   height * 3 / 4 - 15);
    AddControl(new StaticTextControlPane(
        L"0", false, 128, 143, &controlBounds, false, false));

    InitRectBounds(&controlBounds,
                   width / 4,
                   height * 3 / 4 - 5,
                   width * 3 / 4,
                   height - 10);
    AddControl(new TextButtonControlPane(L"Cancel", &controlBounds));

    OnCreate(&dialogBounds, 0, 0, g_pStatusPaneLayer);
    OnShow(0, 0);

    const unsigned int fileCount = patchInfo[4];
    for (unsigned int index = 0; index < fileCount; ++index) {
        const char *fileName =
            reinterpret_cast<const char *>(patchInfo + 5 + index * 256);
        m_patchFileNames.push_back(StringBase<wchar_t>(fileName));
    }

    m_finalPatchPath = L"Patcher.exe";
    StringBase<char> oldPath(m_finalPatchPath);
    _unlink(oldPath.c_str());
    m_tempPatchPath = L"Patcher.exe.new";
    SendDownloadRequest();
}

// UID:0004VT | by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md | Completion:92 | Confidence:94
PatchPane2::~PatchPane2()
{
    ClosePatchFile();
}

// UID:0001EV | by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md | Completion:92 | Confidence:94
bool PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)
{
    if (event->m_channel != kHttpNotification)
        return false;

    const httpget::Notification *notification =
        static_cast<const httpget::Notification *>(event->m_payload);

    switch (notification->m_state) {
    case httpget::Started:
    {
        m_activePatchFile = _wfopen(m_tempPatchPath.c_str(), L"wb");
        if (m_activePatchFile == 0)
            ReportWriteError(m_tempPatchPath.c_str());

        GetChild<StaticTextControlPane>(0)->SetText(m_finalPatchPath.c_str());

        StringBase<wchar_t> byteCount;
        byteCount.FormatWide(L"0", ftell(m_activePatchFile));
        GetChild<StaticTextControlPane>(1)->SetText(byteCount.c_str());
        return true;
    }

    case httpget::DataChunk:
    {
        const _AUTOBUF<unsigned char> *chunk =
            static_cast<const _AUTOBUF<unsigned char> *>(notification->m_payload);

        if (fwrite(chunk->data(), 1, chunk->size(), m_activePatchFile) != chunk->size())
            ReportWriteError(m_tempPatchPath.c_str());

        StringBase<wchar_t> byteCount;
        byteCount.FormatWide(L"%d", ftell(m_activePatchFile));
        GetChild<StaticTextControlPane>(1)->SetText(byteCount.c_str());
        return true;
    }

    case httpget::Completed:
    {
        FILE *file = m_activePatchFile;
        const int closeResult = fclose(file);
        m_activePatchFile = 0;
        if (closeResult == EOF)
            throw Win32Error();

        StringBase<char> finalPath(m_finalPatchPath);
        _unlink(finalPath.c_str());

        StringBase<char> renameTarget(m_finalPatchPath);
        StringBase<char> renameSource(m_tempPatchPath);
        if (rename(renameSource.c_str(), renameTarget.c_str()) != 0 && errno != ENOENT)
            throw Win32Error();

        SHELLEXECUTEINFOA executeInfo = {};
        executeInfo.cbSize = sizeof(executeInfo);
        executeInfo.lpVerb = "runas";
        executeInfo.lpFile = "patcher.exe";
        executeInfo.lpParameters = Locale;
        executeInfo.nShow = SW_SHOWNORMAL;
        ShellExecuteExA(&executeInfo);

        FinishAndExit(GetLanguageText(174));
        return true;
    }

    case httpget::ReadOrOpenUrlFailed:
        ClosePatchFile();

        if (m_currentDownloadIndex < m_patchFileNames.size() - 1) {
            ++m_currentDownloadIndex;
            SendDownloadRequest();
            return true;
        }

        if (m_downloadPassCount >= 10)
            FinishAndExit(GetLanguageText(157));
        else {
            m_currentDownloadIndex = 0;
            ++m_downloadPassCount;
        }

        SendDownloadRequest();
        return true;

    case httpget::InternetOpenFailed:
    {
        ClosePatchFile();

        wchar_t message[1024];
        const Error *error = static_cast<const Error *>(notification->m_payload);
        error->FormatErrorMessage(message, 1024);
        FinishAndExit(message);
        return true;
    }

    default:
        return true;
    }
}

// UID:0001EW | by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md | Completion:92 | Confidence:94
bool PatchPane2::AcceptsDownloadWorkEvent(const WorkThreadNotification *event)
{
    return event->m_type == kWorkThreadNotification;
}

// UID:0004VU | by-memory/0x00548f50-0x00548f72.PatchPane2ClosePatchFile.md | Completion:92 | Confidence:94
void PatchPane2::ClosePatchFile()
{
    if (m_activePatchFile != 0) {
        FILE *file = m_activePatchFile;
        m_activePatchFile = 0;
        fclose(file);
    }
}

// UID:0004VV | by-memory/0x00548f80-0x0054901f.PatchPane2FinishAndExit.md | Completion:92 | Confidence:94
void PatchPane2::FinishAndExit(const wchar_t *message)
{
    if (message != 0)
        new AlertPane(message, g_pMainMenuPane, L"OK", 0);

    Sleep(1000);
    CloseDialog();
    g_pMainMenuPane->MarkForDeletion();
    g_pApplication->RequestExit();
}

// UID:0002R7 | by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md | Completion:90 | Confidence:94
// The source-level download index/pass advance behavior is emitted in [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) PatchPane2::HandleDownloadWorkEvent; this raw no-entry duplicate is not emitted separately.

// UID:0001EX | by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md | Completion:92 | Confidence:94
// The source-level close/delete/rename behavior is emitted inline in [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) PatchPane2::HandleDownloadWorkEvent; this no-caller duplicate helper is retained as binary evidence and is not emitted separately.

// UID:0001EY | by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md | Completion:92 | Confidence:94
void PatchPane2::SendDownloadRequest()
{
    StringBase<wchar_t> requestSuffix;
    requestSuffix.FormatWide(L"%d/%d/%s",
                             m_patchVersionMajor,
                             m_patchVersionMinor,
                             m_finalPatchPath.c_str());

    const StringBase<wchar_t> requestPath =
        m_patchFileNames[m_currentDownloadIndex] + requestSuffix;

    g_pMiscWorkThread->RequestHTTPGet(requestPath.c_str());
}

// UID:0004VW | by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md | Completion:92 | Confidence:94
void PatchPane2::ReportWriteError(const wchar_t *path)
{
    StringBase<wchar_t> message;
    message.FormatWide(L"Error writing %s", path);
    FinishAndExit(message.c_str());
}

// UID:0001VJ | by-type/by-struct/PatchPane2Layout.md | Completion:92 | Confidence:94
// PatchPane2 field declarations are emitted by [UID:0000AA][PatchPane2](by-class/PatchPane2.md); this layout evidence page has no duplicate standalone type declaration.

// UID:0000AB | by-class/PatchPane__PatchFileData.md | Completion:92 | Confidence:94
class PatchPane::PatchFileData {
    friend class PatchPane;

public:
    PatchFileData()
        : m_patchEntryCount(0),
          m_patchEntrySlices(0)
    {
        m_currentPatchName[0] = L'\0';
    }

    virtual ~PatchFileData()
    {
        delete[] m_patchEntrySlices;
        m_patchEntrySlices = 0;
    }

private:
    wchar_t m_currentPatchName[256];
    int m_patchEntryCount;
    PatchFileSlice *m_patchEntrySlices;

// UID:0003OC | by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md | Completion:92 | Confidence:94
// Compiler-generated scalar deleting destructor for PatchPane::PatchFileData;
// emitted from its virtual destructor declaration.
};


// UID:0001ER | by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md | Completion:90 | Confidence:90
bool PatchPane::HandlePatchResponsePacket(const PacketEvent *event)
{
    const unsigned char *packet = event->payload;

    if (packet[0] != 0x40)
        return false;

    switch (packet[1]) {
    case 0: {
        const unsigned int nameLength = packet[2];
        wchar_t patchName[1024];
        const int convertedLength =
            MultiByteToWideChar(CP_ACP,
                                0,
                                reinterpret_cast<const char *>(packet + 3),
                                nameLength,
                                patchName,
                                1023);
        patchName[convertedLength] = L'\0';

        if (wcscmp(m_patchFileData.m_currentPatchName, patchName) == 0 &&
            m_patchFileData.m_patchEntrySlices == NULL) {
            m_patchFileData.m_patchEntryCount =
                static_cast<int>(PacketBufferReadUInt32BE(packet + 3 + nameLength));
            m_patchFileData.m_patchEntrySlices =
                new PatchFileSlice[m_patchFileData.m_patchEntryCount];

            SendPendingPatchEntryRequests();

            static_cast<TextEditControlPane *>(
                m_controlManager->GetControl(0))->SetText(patchName);
            static_cast<ProgressBarControlPane *>(
                m_controlManager->GetControl(1))->SetCurrentValue(0);
        }

        return true;
    }

    case 1: {
        const unsigned int nameLength = packet[2];
        wchar_t patchName[1024];
        const int convertedLength =
            MultiByteToWideChar(CP_ACP,
                                0,
                                reinterpret_cast<const char *>(packet + 3),
                                nameLength,
                                patchName,
                                1023);
        patchName[convertedLength] = L'\0';

        if (wcscmp(m_patchFileData.m_currentPatchName, patchName) == 0 &&
            m_patchFileData.m_patchEntrySlices != NULL) {
            const unsigned char *cursor = packet + 3 + nameLength;
            const int entryIndex =
                static_cast<int>(PacketBufferReadUInt32BE(cursor));

            if (entryIndex >= 0 &&
                entryIndex < m_patchFileData.m_patchEntryCount) {
                PatchFileSlice &slice =
                    m_patchFileData.m_patchEntrySlices[entryIndex];

                if (slice.m_payloadData == NULL) {
                    cursor += 4;

                    slice.m_payloadLength = PacketBufferReadUInt32BE(cursor);
                    slice.m_payloadData =
                        static_cast<unsigned char *>(malloc(slice.m_payloadLength));
                    memmove(slice.m_payloadData, cursor + 4, slice.m_payloadLength);

                    int completedCount = 0;
                    for (int i = 0;
                         i < m_patchFileData.m_patchEntryCount;
                         ++i) {
                        if (m_patchFileData.m_patchEntrySlices[i].m_payloadData != NULL)
                            ++completedCount;
                    }

                    static_cast<ProgressBarControlPane *>(
                        m_controlManager->GetControl(1))->SetCurrentValue(
                            static_cast<short>(100 * completedCount /
                                               m_patchFileData.m_patchEntryCount));
                }
            }
        }

        SendPendingPatchEntryRequests();
        return true;
    }

    case 2:
        ShowPatchAlertAndExit(g_pLanguageMan->GetLocalizedString(176));
        return false;

    default:
        return false;
    }
}

// UID:0001ES | by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md | Completion:87 | Confidence:91
PatchPane::PatchFileSlice::PatchFileSlice()
    : m_requestIssued(false),
      m_payloadLength(0),
      m_payloadData(0)
{
}

// UID:0001ET | by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md | Completion:87 | Confidence:91
PatchPane::PatchFileSlice::~PatchFileSlice()
{
    if (m_payloadData != 0)
        free(m_payloadData);
}

// UID:000487 | by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md | Completion:87 | Confidence:91
// Application patch, version, PasswordGuard, and error strings are pooled literals emitted at their source use sites; this broad range emits no standalone static string table.

// UID:0002OI | by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md | Completion:88 | Confidence:92
// PatchPane vtable bytes are compiler-generated from the PatchPane class declaration and virtual member definitions; this data range has no standalone handwritten C++ emission.

// UID:000264 | by-memory/0x00621db8-0x00622030.PatchPaneReadOnlyData.md | Completion:86 | Confidence:92
// PatchPane/PatchPane2 read-only vtable and pooled-literal storage is emitted by class declarations and string use sites; this aggregate range has no standalone handwritten C++ emission.

// UID:0001YF | by-type/by-vtable/PatchPaneVtableFamily.md | Completion:86 | Confidence:92
// The PatchPane/PatchPane2 vtable family is compiler-generated from class declarations and virtual member definitions; no hand-authored vtable object is emitted here.

// UID:0000A9 | by-class\PatchPane.md | Completion:87 | Confidence:88 | Empty Emitter Marker
