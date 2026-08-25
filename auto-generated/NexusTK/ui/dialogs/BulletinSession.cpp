// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HX
// Source by-file doc: by-file/BulletinSession.md
// UID:0000QG | by-global/g_pBulletinSession.md | Completion:92 | Confidence:94
class BulletinSession;

BulletinSession *g_pBulletinSession = 0;

// UID:00001D | by-class/BulletinSession.md | Completion:92 | Confidence:94
class Event;
class ScreenDimmer;
class BulletinSession;

extern BulletinSession *g_pBulletinSession;

class BulletinSession : public DialogSession,
                        public Singleton<BulletinSession>
{
public:
    BulletinSession(unsigned char initializationMode,
                    const unsigned char *initialPacket,
                    bool requestPredefinedForms);
    virtual ~BulletinSession();

    virtual bool HandlePacketEvent(Event *event);

    void OpenNewArticleDialog(const wchar_t *title);
    void OpenReplyDialog(const wchar_t *recipientText,
                         const wchar_t *quoteText,
                         short quoteLength);

private:
    ScreenDimmer *ActivateScreenDimmer();
    void OpenBoardListDialog(const unsigned char *packetData);
    void HandlePredefinedFormAction(const unsigned char *packet);
    bool DispatchPacket(const unsigned char *packet);

    bool m_pendingListResponse;
    unsigned short m_activeListId;
};

// UID:0004FS | by-memory/0x00471150-0x0047126c.BulletinSessionConstructor.md | Completion:91 | Confidence:94
BulletinSession::BulletinSession(unsigned char initializationMode,
                                 const unsigned char *initialPacket,
                                 bool requestPredefinedForms)
    : DialogSession(),
      Singleton<BulletinSession>(),
      m_pendingListResponse(false),
      m_activeListId(0)
{
    if (initializationMode == 1) {
        const unsigned char request[3] = {
            0x3b,
            static_cast<unsigned char>(requestPredefinedForms ? 9 : 1),
            0
        };

        SendPacketBytes(request, 2);

        if (requestPredefinedForms)
            m_pendingListResponse = true;
    } else if (initializationMode == 0) {
        m_pendingListResponse = true;
        DispatchPacket(initialPacket);
    }
}

// UID:0004FT | by-memory/0x00471270-0x00471299.BulletinSessionCleanup.md | Completion:91 | Confidence:94
BulletinSession::~BulletinSession()
{
}

// UID:0004FU | by-memory/0x004712a0-0x004712ac.BulletinSessionActivateScreenDimmer.md | Completion:88 | Confidence:90
ScreenDimmer *BulletinSession::ActivateScreenDimmer()
{
    m_pendingListResponse = true;
    return CreateScreenDimmer();
}

// UID:0004FW | by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md | Completion:88 | Confidence:91
void BulletinSession::OpenNewArticleDialog(const wchar_t *title)
{
    Rect bounds;

    if (g_useEpfAssets == 1) {
        bounds = MakeRect(0x0a, 0x0a, 0x1cd, 0x1ae);
    } else {
        bounds = MakeRect(0x0a, 0x0a, 0x1c8, 0x178);
    }

    PushDialog(new NewArticleDialog(this, title, bounds));
}

// UID:0004FX | by-memory/0x004713b0-0x00471476.BulletinSessionOpenReplyDialog.md | Completion:88 | Confidence:91
void BulletinSession::OpenReplyDialog(const wchar_t *recipientText,
                                      const wchar_t *quoteText,
                                      short quoteLength)
{
    RectBounds bounds;

    if (g_useEpfAssets)
        InitRectBounds(&bounds, 10, 10, 461, 430);
    else
        InitRectBounds(&bounds, 10, 10, 456, 376);

    NewMailDialog *dialog = new NewMailDialog(this, &bounds, recipientText, quoteText, quoteLength);
    PushDialog(dialog);
}

// UID:0004FY | by-memory/0x00471480-0x004714a3.BulletinSessionPacketForwarder.md | Completion:92 | Confidence:94
bool BulletinSession::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] != 0x31)
        return false;

    return DispatchPacket(packet);
}

// UID:0004G3 | by-memory/0x004718a0-0x00471956.BulletinSessionOpenBoardListDialog.md | Completion:88 | Confidence:91
void BulletinSession::OpenBoardListDialog(const unsigned char *packetData)
{
    const Rect bounds = (g_useEpfAssets == 1)
        ? Rect(10, 10, 461, 430)
        : Rect(10, 10, 456, 376);

    BoardListDialog *dialog = new BoardListDialog(this, bounds, packetData);
    PushDialog(dialog);
}

// UID:0004G6 | by-memory/0x00471c00-0x00471dcd.BulletinSessionHandlePredefinedFormAction.md | Completion:88 | Confidence:91
void BulletinSession::HandlePredefinedFormAction(const unsigned char *packet)
{
    wchar_t initialSubject[256] = L"N/A";

    if (IsScreenDimmerActive())
        ReleaseScreenDimmer();

    if (PacketBufferReadUInt16BE(packet + 2) != 0) {
        if (m_activeDialogIndex != -1) {
            DialogInSession *dialog = GetDialogAtIndex(m_activeDialogIndex);
            if (dialog->m_dialogType == 2)
                PopCurrentDialog(false);
        }

        if (m_activeDialogIndex != -1) {
            DialogInSession *dialog = GetDialogAtIndex(m_activeDialogIndex);
            if (dialog->m_dialogType == 1)
                wcscpy_s(initialSubject, _countof(initialSubject), dialog->m_title);
        }

        RECT initialRect;
        if (g_useEpfAssets)
            SetRect(&initialRect, 10, 10, 461, 430);
        else
            SetRect(&initialRect, 10, 10, 456, 376);

        PushDialog(new NewPredefinedFormArticleDialog(this, initialSubject, initialRect, packet));
    } else {
        new AlertPane(g_pLanguageMan->GetLocalizedString(65), this, g_szDialogOk, NULL);
    }
}
