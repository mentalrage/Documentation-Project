// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HT
// Source by-file doc: by-file/BoardDialogs.md
// UID:00000J | by-class/ArticleDialog.md | Completion:85 | Confidence:87
// UID00000J ArticleDialog class-level source is covered by UID0000HT BoardDialogs and exact ArticleDialog method/support pages. This page emits no standalone partial class declaration until the board/article dialog source split, packet/action field names, and raw helper policy are source-quality.
// UID:00030J | by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md | Completion:88 | Confidence:90
// UID00030J ArticleDialogCore is covered through UID00000J ArticleDialog and UID0000HT BoardDialogs. No partial aggregate body is emitted here because the range mixes the ArticleDialog constructor, action switch, server-response handlers, retained raw packet helpers, jump-table bytes, and unresolved final class/member/control declarations. Current MCP resolves the packet/action roles, but final source should wait for either a synchronized full ArticleDialog draft or exact helper child splits.

// UID:00000K | by-class/ArticleListDialog.md | Completion:85 | Confidence:88
// UID00000K ArticleListDialog class-level source is covered by UID0000HT BoardDialogs and exact ArticleListDialog method/support pages. This page emits no standalone partial class declaration until packet/list-entry fields, raw helper policy, and the board/article dialog source split are source-quality.
// UID:00030G | by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md | Completion:88 | Confidence:89
// UID00030G ArticleListDialogCore is covered through UID00000K ArticleListDialog and UID0000HT BoardDialogs. No partial aggregate body is emitted here because the range includes raw helper bytes, modeled constructor/dispatch/update methods, a shared navigation caller, and unresolved packet/list-entry field names.

// UID:00000L | by-class/ArticleListPane.md | Completion:88 | Confidence:88
// UID00000L ArticleListPane class-level source is covered by UID0000HT BoardDialogs and UID00030I ArticleListPaneCore. This page emits no standalone partial class declaration until ArticleListPane, ArticleListEntry, ListPane, render, and packet declarations are synchronized.
// UID:00030I | by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md | Completion:88 | Confidence:89
// UID00030I ArticleListPaneCore is covered through UID00000L ArticleListPane and UID0000HT BoardDialogs. B001 accepted a no-partial-C++ disposition: emit no aggregate body until synchronized declarations support one full draft or optional exact helper splits for the raw helper bodies, ArticleListEntry layout, m_boardId, and m_pageRequestPending.

// UID:00000Z | by-class/BoardListDialog.md | Completion:88 | Confidence:90
// UID00000Z BoardListDialog class-level source is covered by UID0000HT BoardDialogs and the exact emitting child UID0002EJ BoardListDialogCore. This page emits no standalone partial class declaration until the board dialog hierarchy and header/source split are finalized.
// UID:0002EJ | by-memory/0x00472070-0x004729dd.BoardListDialogCore.md | Completion:88 | Confidence:90
namespace
{
    constexpr int kBoardListOpenCommand = 1;
    constexpr int kBoardListCloseCommand = 2;
    constexpr int kBoardListOpenButtonId = 1;
    constexpr int kBoardListCloseButtonId = 2;
    constexpr int kBoardListPaneId = 3;
    constexpr unsigned char kOpenBoardOpcode = 0x3b;
    constexpr unsigned char kOpenBoardSubcommand = 0x02;
    constexpr unsigned short kOpenBoardLimit = 0x7fff;
    constexpr unsigned char kOpenBoardEpfMode = 0xec;
    constexpr unsigned char kOpenBoardLegacyMode = 0xf0;

    unsigned short ReadBoardIdBE(const unsigned char *cursor)
    {
        return static_cast<unsigned short>((cursor[0] << 8) | cursor[1]);
    }

    void DecodeBoardText(wchar_t *out, unsigned int outCount, const unsigned char *text, unsigned int length)
    {
        ConvertBoardDialogText(out, outCount, text, length);
    }
}

BoardListDialog::BoardListDialog(BulletinSession *session, const Rect &bounds, const unsigned char *packetData)
    : DialogInSession(session, 2, 0)
{
    const unsigned int titleLength = packetData[0];
    wchar_t title[256] = {};
    DecodeBoardText(title, 256, packetData + 1, titleLength);
    SetTitle(title);

    const unsigned int itemCount = packetData[titleLength + 1];
    BoardListPane *listPane = new BoardListPane(0x202, itemCount, 360, 14, false, true);

    const unsigned char *cursor = packetData + titleLength + 2;
    for (unsigned int index = 0; index < itemCount; ++index)
    {
        BoardListEntry entry = {};
        entry.boardId = ReadBoardIdBE(cursor);
        cursor += 2;

        const unsigned int textLength = *cursor++;
        DecodeBoardText(entry.text, 257, cursor, textLength);
        cursor += textLength;

        listPane->AddEntry(entry);
    }

    if (g_useEpfAssets == 1)
    {
        AddBackgroundImage("DL");
        AddImageButton(kBoardListOpenButtonId, Rect(144, 381, 207, 405), 17);
        AddImageButton(kBoardListCloseButtonId, Rect(231, 381, 294, 405), 15);
        AddControl(kBoardListPaneId, listPane, Rect(25, 56, 430, 356));
    }
    else
    {
        AddBackgroundImage("DL");
        AddImageButton(kBoardListOpenButtonId, Rect(149, 316, 221, 332), 17);
        AddImageButton(kBoardListCloseButtonId, Rect(226, 316, 298, 332), 15);
        AddControl(kBoardListPaneId, listPane, Rect(36, 71, 410, 295));
    }

    SetHoverControl(kBoardListPaneId);
    SetActiveControl(kBoardListOpenButtonId);
    SetCurrentControl(kBoardListCloseButtonId);
    SetBounds(bounds);
}

void BoardListDialog::OnCommand(int commandId, int unusedNotifyCode)
{
    (void)unusedNotifyCode;

    if (commandId == kBoardListOpenCommand)
    {
        OpenSelectedBoard();
    }
    else if (commandId == kBoardListCloseCommand)
    {
        if (m_session != nullptr)
            m_session->CloseAllDialogs();
    }
}

void BoardListDialog::OpenSelectedBoard()
{
    BoardListPane *listPane = static_cast<BoardListPane *>(GetControl(kBoardListPaneId));
    if (listPane == nullptr)
        return;

    const int selectedIndex = listPane->GetSelectedIndex();
    if (selectedIndex < 0)
        return;

    const BoardListEntry *entry = listPane->GetItem(selectedIndex);
    if (entry == nullptr)
        return;

    unsigned char packet[8] = {};
    PacketBufferWriteUInt8(kOpenBoardOpcode, packet);
    PacketBufferWriteUInt8(kOpenBoardSubcommand, packet + 1);
    PacketBufferWriteUInt16BE(entry->boardId, packet + 2);
    PacketBufferWriteUInt16BE(kOpenBoardLimit, packet + 4);
    PacketBufferWriteUInt8(g_useEpfAssets == 1 ? kOpenBoardEpfMode : kOpenBoardLegacyMode, packet + 6);

    g_packetSender->QueueAndSendPacket(packet, 7);

    if (m_session != nullptr)
    {
        if (g_pUserPane != nullptr)
            g_pUserPane->m_activeDialogHostPane = this;

        m_session->m_dialogTransitionPending = true;
        CreateScreenDimmer();
    }
}

void BoardListDialog::UpdateButtonState()
{
    ButtonPane *openButton = static_cast<ButtonPane *>(GetControl(kBoardListOpenButtonId));
    BoardListPane *listPane = static_cast<BoardListPane *>(GetControl(kBoardListPaneId));
    if (openButton == nullptr || listPane == nullptr)
        return;

    if (listPane->GetSelectionCount() > 0)
        openButton->Enable();
    else
        openButton->Disable();
}

// UID:0002VE | by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md | Completion:88 | Confidence:92
// UID0002VE BoardListDialog vtable data is compiler-emitted layout evidence for UID00000Z BoardListDialog. Do not hand-write raw RTTI or vtable dword arrays here; the final class declarations should cause the compiler to regenerate equivalent tables.

// UID:000010 | by-class/BoardListPane.md | Completion:88 | Confidence:90
// UID000010 BoardListPane class-level source is covered by UID0000HT BoardDialogs and UID0002V9 BoardListPaneCore. This page emits no standalone partial class declaration until BoardListEntry/ListPane/GrafPort declarations are synchronized; UID0002V9 remains an aggregate marker because it mixes retained no-direct-route raw helpers with vtable-dispatched virtual methods.
// UID:0002V9 | by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md | Completion:88 | Confidence:90
// UID0002V9 BoardListPaneCore is covered through UID000010 BoardListPane and UID0000HT BoardDialogs. No partial aggregate body is emitted here because current MCP evidence leaves three retained no-direct-route raw helpers beside two vtable-dispatched virtual methods; exact method children or synchronized BoardListPane/BoardListEntry/ListPane declarations should come before source C++.

// UID:00001C | by-class/BulletinDialog.md | Completion:86 | Confidence:88
// UID00001C BulletinDialog class-level source is covered by UID0000HT BoardDialogs, exact constructor child UID0000ZI, shared command bridge UID0000ZJ, and vtable layout support. This page emits no standalone partial declaration until secondary-interface and virtual declaration policy is source-quality.
// UID:0000ZI | by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md | Completion:87 | Confidence:88
BulletinDialog::BulletinDialog(DialogSession *session, unsigned char dialogType)
    : DialogInSession(session, 2, dialogType)
{
}

// UID:0002MI | by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md | Completion:89 | Confidence:92
// UID0002MI BulletinDialog vtable data is compiler-emitted layout evidence for UID00001C BulletinDialog. Do not hand-write raw RTTI or vtable dword arrays here; the final class declarations should cause the compiler to regenerate equivalent tables.

// UID:0001X5 | by-type/by-vtable/BulletinDialogVtables.md | Completion:86 | Confidence:88
// UID0001X5 BulletinDialogVtables is vtable-layout support for UID00001C BulletinDialog and exact data child UID0002MI. It emits no raw table source because the primary, secondary, and tertiary vtables should be regenerated from class declarations.

// UID:00008Y | by-class/NewArticleDialog.md | Completion:87 | Confidence:89
// UID00008Y NewArticleDialog class-level source is covered by UID0000HT BoardDialogs and the exact emitting child UID00030K NewArticleDialogCore. This page emits no standalone partial class declaration until field/header names and the final article-dialog source split are source-quality.
// UID:00030K | by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md | Completion:88 | Confidence:90
#include "../../auth/PasswordGuard.h"

namespace {
constexpr int kNewArticleCommandSubmit = 1;
constexpr int kNewArticleCommandCancel = 2;
constexpr unsigned char kBoardPacketOpcode = 0x3b;
constexpr unsigned char kArticleSubmitSubcommand = 0x04;
constexpr unsigned char kTransferReplySubcommand = 0x06;
constexpr int kSubjectControlIndex = 4;
constexpr int kBodyControlIndex = 5;
constexpr int kSubmitTimeoutMs = 15000;

std::wstring DecodeArticleReplyMessage(const unsigned char *text, unsigned int length)
{
    char narrow[0x100] = {};
    const unsigned int copyLength = std::min<unsigned int>(length, sizeof(narrow) - 1);
    std::memmove(narrow, text, copyLength);

    wchar_t wide[0x100] = {};
    MultiByteToWideChar(CP_ACP, 0, narrow, -1, wide, static_cast<int>(std::size(wide)));
    return wide;
}
} // namespace

NewArticleDialog::NewArticleDialog(BulletinSession *session,
                                   const wchar_t *title,
                                   const Rect &bounds)
    : DialogInSession(session, 2, 4)
{
    SetBounds(bounds);

    if (g_useEpfAssets == 1) {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, bounds.Width(), bounds.Height()),
                                           0x14c,
                                           L"DLGBBS04.EPF",
                                           L"DLGBBS04.PAL"));
        AddControl(new ImageButtonControlPane(MakeRect(0x90, 0x17d, 0xcf, 0x195), 0x17));
        AddControl(new ImageButtonControlPane(MakeRect(0xe7, 0x17d, 0x126, 0x195), 0x16));
        AddControl(new StaticTextControlPane(MakeRect(0x5e, 0x3a, 0x196, 0x46), title));
        AddControl(new TextEditControlPane(MakeRect(0x5e, 0x55, 0x196, 0x61), L""));

        TextEditControlPane *body =
            new TextEditControlPane(MakeRect(0x19, 0x70, 0x1ae, 0x164), L"");
        body->SetMultiline(true);
        body->SetMaxLength(0x400);
        body->SetTextLimit(4000);
        AddControl(body);
        LoadDialogBackground(L"DLGBBS04.EPF");
    } else {
        AddControl(new ImageControlPane(MakeRect(0, 0, bounds.Width(), bounds.Height()),
                                        L"DLGBBS04.EPD",
                                        L"NPAL8.PAL"));
        AddControl(new ImageButtonControlPane(MakeRect(0x95, 0x13c, 0xdd, 0x14c), 0x17));
        AddControl(new ImageButtonControlPane(MakeRect(0xe2, 0x13c, 0x12a, 0x14c), 0x16));
        AddControl(new StaticTextControlPane(MakeRect(0x83, 0x36, 0x19a, 0x42), title));
        AddControl(new TextEditControlPane(MakeRect(0x83, 0x48, 0x19a, 0x55), L""));

        TextEditControlPane *body =
            new TextEditControlPane(MakeRect(0x24, 0x5b, 0x19a, 0x127), L"");
        body->SetMultiline(true);
        body->SetMaxLength(0x400);
        body->SetTextLimit(4000);
        AddControl(body);
        LoadDialogBackground(L"DLGBBS04.EPD");
    }

    SetDialogMode(2);
    SetHoverControl(kSubjectControlIndex);
}

void NewArticleDialog::NavigateToPreviousArticleSelection()
{
    ArticleDialog *previous = FindPreviousArticleDialog();
    if (previous == nullptr) {
        return;
    }

    const short boardId = GetSession() != nullptr ? GetSession()->m_currentBoardId : 0;
    const short articleId = previous->GetSelectedArticleId();
    SendArticleNavigationRequest(boardId, articleId, previous->GetNavigationMode());
}

void NewArticleDialog::OnCommand(int commandId)
{
    BulletinSession *session = GetSession();

    if (commandId == kNewArticleCommandSubmit) {
        const short boardId = session != nullptr ? session->m_currentBoardId : 0;
        SubmitArticle(boardId);

        if (g_pCollectionData != nullptr) {
            g_pCollectionData->m_activeDialogHostPane = this;
        }
        CreateScreenDimmer();
        return;
    }

    if (commandId == kNewArticleCommandCancel && session != nullptr) {
        session->PopCurrentDialog(false);
    }
}

bool NewArticleDialog::HandlePostError(int resultCode)
{
    if (resultCode != 0) {
        return false;
    }

    if (IsScreenDimmerActive()) {
        ReleaseScreenDimmer();
    }

    new TransferReplyAlert(this, L"Your post didn't go through due to an error.", 0);
    return true;
}

void NewArticleDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}

bool NewArticleDialog::HandleTransferReplyPacket(const unsigned char *packet)
{
    if (packet[1] != kTransferReplySubcommand) {
        return false;
    }

    return HandleTransferReplyPayload(packet + 2);
}

bool NewArticleDialog::HandleTransferReplyPayload(const unsigned char *payload)
{
    if (IsScreenDimmerActive()) {
        ReleaseScreenDimmer();
    }

    const unsigned char replyMode = payload[0];
    const unsigned char messageLength = payload[1];
    const std::wstring message = DecodeArticleReplyMessage(payload + 2, messageLength);
    new TransferReplyAlert(this, message.c_str(), replyMode);
    return true;
}

void NewArticleDialog::SubmitArticle(short boardId)
{
    wchar_t subjectWide[0x100] = {};
    wchar_t bodyWide[0x1000] = {};

    const unsigned int subjectChars =
        GetTextEditControl(kSubjectControlIndex)->GetText(subjectWide, 0xff);
    const unsigned int bodyChars =
        GetTextEditControl(kBodyControlIndex)->GetText(bodyWide, 0xfff);

    ValidateChatInputOrThrowPasswordError(subjectWide);
    ValidateChatInputOrThrowPasswordError(bodyWide);
    SanitizeWideTextForChat(subjectWide, subjectChars);
    SanitizeWideTextForChat(bodyWide, bodyChars);

    unsigned char packet[0x7fff] = {};
    packet[0] = kBoardPacketOpcode;
    packet[1] = kArticleSubmitSubcommand;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(boardId), packet + 2);

    char subjectBytes[0x100] = {};
    const int subjectLength =
        WideCharToMultiByte(CP_ACP, 0, subjectWide, -1, subjectBytes,
                            sizeof(subjectBytes), nullptr, nullptr) - 1;
    packet[4] = static_cast<unsigned char>(subjectLength);
    std::memmove(packet + 5, subjectBytes, subjectLength);

    char bodyBytes[0x1000] = {};
    const int bodyLength =
        WideCharToMultiByte(CP_ACP, 0, bodyWide, -1, bodyBytes,
                            sizeof(bodyBytes), nullptr, nullptr) - 1;

    unsigned char *bodyLengthField = packet + 5 + subjectLength;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(bodyLength), bodyLengthField);
    std::memmove(bodyLengthField + 2, bodyBytes, bodyLength);

    QueueAndSendPacket(g_packetSender,
                       packet,
                       static_cast<short>(subjectLength + bodyLength + 7));
    StartTransferTimeout(kSubmitTimeoutMs);
}

// UID:0000ZJ | by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md | Completion:88 | Confidence:92
// UID0000ZJ is the shared command-'1' secondary bridge routed through UID0000HT BoardDialogs. No source body is emitted here because a formal C++ body would invent the shared secondary interface, event+0x0c field, and primary +0x5c virtual declaration or encode an ABI this-0xa0 adjustment that belongs to compiler-generated layout.

// UID:00030H | by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md | Completion:89 | Confidence:91
void SendArticleNavigationRequest(short boardId, short articleId, signed char layoutOffset)
{
    unsigned char packet[0x100] = {};

    PacketBufferWriteUInt8(0x3b, &packet[0]);
    PacketBufferWriteUInt8(2, &packet[1]);
    PacketBufferWriteUInt16BE(boardId, &packet[2]);
    PacketBufferWriteUInt16BE(articleId, &packet[4]);
    PacketBufferWriteUInt8(static_cast<unsigned char>(layoutOffset), &packet[6]);
    QueueAndSendPacket(g_packetSender, packet, 7);
}

void SendArticleReadRequest(short boardId, short articleId)
{
    unsigned char packet[0x100] = {};

    PacketBufferWriteUInt8(0x3b, &packet[0]);
    PacketBufferWriteUInt8(3, &packet[1]);
    PacketBufferWriteUInt16BE(boardId, &packet[2]);
    PacketBufferWriteUInt16BE(articleId, &packet[4]);
    PacketBufferWriteUInt8(0, &packet[6]);
    QueueAndSendPacket(g_packetSender, packet, 7);
}

void SendArticleSubcommand7Request(short boardId, short articleId)
{
    unsigned char packet[0x100] = {};

    PacketBufferWriteUInt8(0x3b, &packet[0]);
    PacketBufferWriteUInt8(7, &packet[1]);
    PacketBufferWriteUInt16BE(boardId, &packet[2]);
    PacketBufferWriteUInt16BE(articleId, &packet[4]);
    QueueAndSendPacket(g_packetSender, packet, 6);
}

void SendArticleDeleteRequest(short boardId, short articleId)
{
    unsigned char packet[0x100] = {};

    PacketBufferWriteUInt8(0x3b, &packet[0]);
    PacketBufferWriteUInt8(5, &packet[1]);
    PacketBufferWriteUInt16BE(boardId, &packet[2]);
    PacketBufferWriteUInt16BE(articleId, &packet[4]);
    QueueAndSendPacket(g_packetSender, packet, 6);
}

// UID:0001X4 | by-type/by-vtable/BoardArticleDialogVtableFamily.md | Completion:88 | Confidence:93
// UID0001X4 BoardArticleDialogVtableFamily is layout support for the board/article dialog class family under UID0000HT BoardDialogs. It emits no raw vtable source because the documented table bytes should be regenerated from final class declarations and inheritance layout.
