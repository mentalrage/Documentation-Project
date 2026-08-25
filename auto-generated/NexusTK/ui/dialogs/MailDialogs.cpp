// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KZ
// Source by-file doc: by-file/MailDialogs.md
// UID:00007L | by-class/MailListDialog.md | Completion:94 | Confidence:93
// UID:0003PU | by-memory/0x00479110-0x0047a894.MailListDialogCore.md | Completion:94 | Confidence:94
#include "MailDialogs.h"

static signed char GetMailListLayoutOffset();
static int SendMailListPageRequest(unsigned short mailListId,
                                   unsigned short upperMailId,
                                   signed char layoutOffset);
static int SendMailReadRequest(unsigned short mailListId,
                               unsigned short mailId);
static int SendMailDeleteRequest(unsigned short mailListId,
                                 unsigned short mailId);

MailListDialog::MailListDialog(BulletinSession *session,
                               const RectBounds &bounds,
                               const unsigned char *packet)
    : BoardDialog(session, bounds), m_session(session), m_mailListId(0)
{
    PacketReader reader(packet);
    m_mailListId = reader.ReadUInt16BE();

    const bool epfLayout = g_useEpfAssets == 1;
    SetDialogImage(epfLayout ? L"DLGBBS05.EPF" : L"DLGBBS05.EPD",
                   epfLayout ? L"DLGBBS05.PAL" : L"NPAL8.PAL");

    const RectBounds listBounds = epfLayout
        ? RectBounds(25, 80, 430, 332)
        : RectBounds(36, 101, 410, 289);
    MailListPane *mailList =
        new MailListPane(static_cast<short>(listBounds.Height()), m_mailListId);
    AddChildPane(7, mailList, listBounds);

    if (epfLayout) {
        AddDialogButton(1, RectBounds(48, 356, 111, 380), L"Read");
        AddDialogButton(2, RectBounds(127, 356, 190, 380), L"Write");
        AddDialogButton(3, RectBounds(206, 356, 269, 380), L"Reply");
        AddDialogButton(4, RectBounds(285, 356, 348, 380), L"Delete");
        AddDialogButton(5, RectBounds(364, 356, 427, 380), L"Close");
    } else {
        AddDialogButton(1, RectBounds(40, 307, 112, 323), L"Read");
        AddDialogButton(2, RectBounds(115, 307, 187, 323), L"Write");
        AddDialogButton(3, RectBounds(190, 307, 262, 323), L"Reply");
        AddDialogButton(4, RectBounds(265, 307, 337, 323), L"Delete");
        AddDialogButton(5, RectBounds(340, 307, 412, 323), L"Close");
    }

    const signed char entryCount = reader.ReadInt8();
    for (int index = 0; index < entryCount; ++index) {
        const unsigned char unread = reader.ReadUInt8();
        const unsigned short mailId = reader.ReadUInt16BE();
        wchar_t sender[256];
        wchar_t subject[256];
        reader.ReadText8(sender, 256);
        const unsigned char month = reader.ReadUInt8();
        const unsigned char day = reader.ReadUInt8();
        reader.ReadText8(subject, 256);
        mailList->AddOrUpdateMailEntry(
            unread, mailId, sender, month, day, subject);
    }

    SetHoverControl(1);
    UpdateButtonStates();
    CenterWithin(bounds);
}

void MailListDialog::SendSelectedMailReadRequest()
{
    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    const int index = pane->GetPrimarySelectedIndex();
    if (index < 0)
        return;

    MailListEntryRow *row =
        static_cast<MailListEntryRow *>(pane->GetItemAt(index));
    row->unread = 0;
    SendMailReadRequest(pane->GetMailListId(), row->mailId);
    if (m_session->IsModalDialog(this))
        m_session->PopDialog();
}

void MailListDialog::SendSelectedMailDeleteRequests()
{
    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    int selectedIndices[256];
    const int selectedCount = pane->GetSelectedIndices(selectedIndices, 256);
    for (int index = 0; index < selectedCount; ++index) {
        const MailListEntryRow *row = static_cast<const MailListEntryRow *>(
            pane->GetItemAt(selectedIndices[index]));
        SendMailDeleteRequest(pane->GetMailListId(), row->mailId);
    }
}

void MailListDialog::RemoveMailEntryByIdAndRefresh(unsigned short mailId)
{
    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    pane->RemoveMailEntryById(mailId);
    UpdateButtonStates();
}

void MailListDialog::RemoveSelectedMailEntriesAndRefresh()
{
    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    pane->RemoveSelectedMailEntries();
    UpdateButtonStates();
}

void MailListDialog::RequestInitialMailPage()
{
    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    SendMailListPageRequest(pane->GetMailListId(), 0x7fff,
                            GetMailListLayoutOffset());
}

void MailListDialog::OnCommand(int commandId, int controlId)
{
    switch (commandId) {
    case 1:
        SendSelectedMailReadRequest();
        break;
    case 2:
        OpenBlankComposeDialog();
        break;
    case 3:
        OpenReplyToSelectedMail();
        break;
    case 4:
        CreateSelectedMailDeleteConfirmAlert();
        break;
    case 5:
        m_session->PopDialog();
        break;
    case 6:
        m_session->DispatchDialogCommand(this, controlId);
        break;
    default:
        BoardDialog::OnCommand(commandId, controlId);
        break;
    }
}

void MailListDialog::OpenBlankComposeDialog()
{
    m_session->OpenNewMailDialog(0, 0, 0);
}

void MailListDialog::OpenReplyToSelectedMail()
{
    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    const int index = pane->GetPrimarySelectedIndex();
    if (index < 0)
        return;
    const MailListEntryRow *row =
        static_cast<const MailListEntryRow *>(pane->GetItemAt(index));
    m_session->OpenNewMailDialog(row->sender, 0, 0);
}

void MailListDialog::CreateSelectedMailDeleteConfirmAlert()
{
    if (g_pConfirmDeleteMailAlert)
        return;

    const wchar_t *message = GetLocalizedString(64);
    g_pConfirmDeleteMailAlert =
        new ConfirmDeleteMailAlert(message, this, L"OK", L"Cancel");
    g_pConfirmDeleteMailAlert->SetDeleteMode(
        ConfirmDeleteMailAlert::DeleteSelectedMail);
    g_pConfirmDeleteMailAlert->InstallViews();
}

void MailListDialog::UpdateButtonStates()
{
    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    const bool enabled = pane->GetSelectedCount() != 0;
    SetControlEnabled(1, enabled);
    SetControlEnabled(3, enabled);
    SetControlEnabled(4, enabled);
}

bool MailListDialog::OnServerPacket(const unsigned char *packet)
{
    switch (packet[1]) {
    case 4:
        return ApplyMailListUpdate(packet);
    case 7:
        return ShowMailDeleteReplyAlert(packet + 2);
    default:
        return false;
    }
}

bool MailListDialog::ApplyMailListUpdate(const unsigned char *packet)
{
    PacketReader reader(packet + 2);
    if (reader.ReadUInt16BE() != m_mailListId)
        return false;

    MailListPane *pane = static_cast<MailListPane *>(GetChildPane(7));
    pane->SetPageRequestPending(false);
    reader.Skip(4);
    const signed char entryCount = reader.ReadInt8();
    for (int index = 0; index < entryCount; ++index) {
        const unsigned char unread = reader.ReadUInt8();
        const unsigned short mailId = reader.ReadUInt16BE();
        wchar_t sender[256];
        wchar_t subject[256];
        reader.ReadText8(sender, 256);
        const unsigned char month = reader.ReadUInt8();
        const unsigned char day = reader.ReadUInt8();
        reader.ReadText8(subject, 256);
        pane->AddOrUpdateMailEntry(
            unread, mailId, sender, month, day, subject);
    }
    UpdateButtonStates();
    return true;
}

bool MailListDialog::ShowMailDeleteReplyAlert(const unsigned char *packet)
{
    if (g_pMailDeleteReplyAlert)
        return false;

    wchar_t message[256];
    const unsigned char length = packet[0];
    ConvertPacketTextToWide(packet + 1, length, message, 256);
    g_pMailDeleteReplyAlert =
        new MailDeleteReplyAlert(message, this, L"OK", 0);
    g_pMailDeleteReplyAlert->SetDeleteMode(
        MailDeleteReplyAlert::DeleteSelectedMail);
    return true;
}

// UID:00007M | by-class/MailListPane.md | Completion:94 | Confidence:94
// UID:0003PV | by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md | Completion:94 | Confidence:94
#include "MailDialogs.h"

static signed char GetMailListLayoutOffset()
{
    return g_useEpfAssets ? -20 : -16;
}

MailListPane::MailListPane(short height, unsigned short mailListId)
    : ListPane(sizeof(MailListEntryRow), 0x1000, height, 14, 0, 1, 1),
      m_mailListId(mailListId), m_pageRequestPending(0)
{
}

void MailListPane::AddOrUpdateMailEntry(unsigned char unread,
                                        unsigned short mailId,
                                        const wchar_t *sender,
                                        unsigned char month,
                                        unsigned char day,
                                        const wchar_t *subject)
{
    MailListEntryRow row = {};
    row.mailId = mailId;
    row.unread = unread;
    row.month = month;
    row.day = day;
    CopyWideStringBounded(row.sender, sender, 256);
    CopyWideStringBounded(row.subject, subject, 256);
    const int oldIndex = FindMailIdIndex(mailId);
    if (oldIndex >= 0)
        RemoveItems(oldIndex, 1);
    const int count = GetItemCount();
    for (int index = 0; index < count; ++index) {
        const MailListEntryRow *oldRow =
            static_cast<const MailListEntryRow *>(GetItemAt(index));
        if (oldRow->mailId == mailId)
            return;
        if (oldRow->mailId < mailId) {
            InsertItem(index, &row);
            return;
        }
    }
    InsertItem(count, &row);
}

void MailListPane::RequestSelectedMailAndMarkRead()
{
    const int index = GetPrimarySelectedIndex();
    if (index < 0)
        return;
    MailListEntryRow *row = static_cast<MailListEntryRow *>(GetItemAt(index));
    row->unread = 0;
    SendMailReadRequest(m_mailListId, row->mailId);
}

void MailListPane::SendDeleteRequestsForSelectedMail()
{
    int selected[256];
    const int count = GetSelectedIndices(selected, 256);
    for (int i = 0; i < count; ++i) {
        const MailListEntryRow *row =
            static_cast<const MailListEntryRow *>(GetItemAt(selected[i]));
        SendMailDeleteRequest(m_mailListId, row->mailId);
    }
}

void MailListPane::RemoveMailEntryById(unsigned short mailId)
{
    const int index = FindMailIdIndex(mailId);
    if (index >= 0)
        RemoveItems(index, 1);
}

void MailListPane::RemoveSelectedMailEntries()
{
    int selected[256];
    const int count = GetSelectedIndices(selected, 256);
    for (int i = 0; i < count; ++i)
        RemoveItems(selected[i] - i, 1);
}

void MailListPane::RequestInitialMailPage()
{
    SendMailListPageRequest(m_mailListId, 0x7fff, GetMailListLayoutOffset());
}

void MailListPane::RequestOlderMailIfNeeded()
{
    unsigned short upperMailId = 0x7fff;
    const int count = GetItemCount();
    if (count) {
        const MailListEntryRow *last =
            static_cast<const MailListEntryRow *>(GetItemAt(count - 1));
        if (last->mailId <= 1)
            return;
        upperMailId = static_cast<unsigned short>(last->mailId - 1);
    }
    SendMailListPageRequest(m_mailListId, upperMailId, GetMailListLayoutOffset());
    m_pageRequestPending = 1;
}

int MailListPane::FindMailIdIndex(unsigned short mailId) const
{
    const int count = GetItemCount();
    for (int index = 0; index < count; ++index) {
        const MailListEntryRow *row =
            static_cast<const MailListEntryRow *>(GetItemAt(index));
        if (row->mailId == mailId)
            return index;
    }
    return -1;
}

bool MailListPane::OnScrollChanged(int delta)
{
    const bool handled = ListPane::OnScrollChanged(delta);
    if (GetScrollPosition() == GetMaximumScrollPosition() &&
        !m_pageRequestPending) {
        RequestOlderMailIfNeeded();
    }
    return handled;
}

bool MailListPane::OnItemSelected(unsigned int index)
{
    const bool handled = ListPane::OnItemSelected(index);
    if (index + 1 == static_cast<unsigned int>(GetItemCount()) &&
        !m_pageRequestPending) {
        RequestOlderMailIfNeeded();
    }
    return handled;
}

int MailListPane::RequestSelectedMail()
{
    MailListDialog *dialog = static_cast<MailListDialog *>(
        GetOwningPane()->GetOwningPane());
    dialog->SendSelectedMailReadRequest();
    return 1;
}

void MailListPane::DrawEntry(GrafPort &port, unsigned int index,
                             const MailListEntryRow &row,
                             const RectBounds &bounds)
{
    const bool selected = IsItemSelected(index);
    if (selected) {
        port.FillRect(bounds, 0x25);
        DrawSelectionBackground(port, bounds);
    }

    const unsigned char color = selected ? 0x25 : (row.unread ? 0x0e : 0x8f);
    wchar_t text[256];
    swprintf(text, L"%5d", row.mailId);
    port.DrawText(bounds.left, bounds.top, text, color);

    CopyWideStringBounded(text, row.sender, 256);
    FitWideTextWithEllipsis(port, text, 80);
    port.DrawText(bounds.left + 35, bounds.top, text, color);

    swprintf(text, L"%2d/%2d", row.month, row.day);
    port.DrawText(bounds.left + 110, bounds.top, text, color);

    CopyWideStringBounded(text, row.subject, 256);
    FitWideTextWithEllipsis(port, text, 208);
    port.DrawText(bounds.left + 150, bounds.top, text, color);
}

static int SendMailListPageRequest(unsigned short mailListId,
                                   unsigned short upperMailId,
                                   signed char layoutOffset)
{
    unsigned char packet[7];
    packet[0] = 0x3b;
    packet[1] = 0x02;
    WriteUInt16BE(packet + 2, mailListId);
    WriteUInt16BE(packet + 4, upperMailId);
    packet[6] = static_cast<unsigned char>(layoutOffset);
    return QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
}

static int SendMailReadRequest(unsigned short mailListId,
                               unsigned short mailId)
{
    unsigned char packet[7] = { 0x3b, 0x03 };
    WriteUInt16BE(packet + 2, mailListId);
    WriteUInt16BE(packet + 4, mailId);
    return QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
}

static int SendMailDeleteRequest(unsigned short mailListId,
                                 unsigned short mailId)
{
    unsigned char packet[6] = { 0x3b, 0x05 };
    WriteUInt16BE(packet + 2, mailListId);
    WriteUInt16BE(packet + 4, mailId);
    return QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
}

// UID:00007K | by-class/MailDialog.md | Completion:94 | Confidence:93
// UID:0003PW | by-memory/0x0047b220-0x0047cd79.MailDialogCore.md | Completion:94 | Confidence:94
#include "MailDialogs.h"

static int SendMailDeleteRequest(unsigned short mailListId,
                                 unsigned short mailId);

MailDialog::MailDialog(BulletinSession *session, const RectBounds &bounds,
                       const unsigned char *packet)
    : BoardDialog(session, bounds), m_session(session),
      m_mailListId(0), m_currentMailId(0)
{
    PacketReader reader(packet);
    m_mailListId = reader.ReadUInt16BE();
    m_currentMailId = reader.ReadUInt16BE();
    reader.ReadText8(m_sender, 256);
    reader.ReadText8(m_date, 64);
    reader.ReadText8(m_subject, 256);
    reader.ReadText16(m_body, 16384);
    NormalizeCarriageReturns(m_body, 16384);

    const bool epfLayout = g_useEpfAssets == 1;
    SetDialogImage(epfLayout ? L"DLGBBS06.EPF" : L"DLGBBS06.EPD",
                   epfLayout ? L"DLGBBS06.PAL" : L"NPAL8.PAL");
    if (epfLayout) {
        AddDialogLabel(8, RectBounds(94, 59, 214, 71), m_sender);
        AddDialogLabel(9, RectBounds(310, 59, 430, 71), m_date);
        AddDialogLabel(10, RectBounds(94, 86, 406, 98), m_subject);
        AddDialogText(11, RectBounds(25, 112, 430, 336), m_body, 405, 228);
        AddDialogButton(32, RectBounds(59, 356, 122, 380), L"New");
        AddDialogButton(33, RectBounds(144, 356, 207, 380), L"Reply");
        AddDialogButton(21, RectBounds(229, 356, 292, 380), L"Delete");
        AddDialogButton(31, RectBounds(314, 356, 377, 380), L"Close");
        AddDialogButton(19, RectBounds(102, 386, 165, 410), L"Previous");
        AddDialogButton(15, RectBounds(187, 386, 250, 410), L"Save");
        AddDialogButton(18, RectBounds(272, 386, 335, 410), L"Next");
        AddScrollPane(12, RectBounds(25, 112, 430, 336), GetChildPane(11));
    } else {
        AddDialogLabel(8, RectBounds(111, 84, 231, 96), m_sender);
        AddDialogLabel(9, RectBounds(290, 84, 410, 96), m_date);
        AddDialogLabel(10, RectBounds(111, 103, 410, 116), m_subject);
        AddDialogText(11, RectBounds(36, 127, 410, 295), m_body, 374, 168);
        AddDialogButton(32, RectBounds(74, 316, 146, 332), L"New");
        AddDialogButton(33, RectBounds(149, 316, 221, 332), L"Reply");
        AddDialogButton(21, RectBounds(224, 316, 296, 332), L"Delete");
        AddDialogButton(31, RectBounds(299, 316, 371, 332), L"Close");
        AddDialogButton(19, RectBounds(112, 333, 184, 349), L"Previous");
        AddDialogButton(15, RectBounds(187, 333, 259, 349), L"Save");
        AddDialogButton(18, RectBounds(262, 333, 334, 349), L"Next");
        AddScrollPane(12, RectBounds(36, 127, 410, 295), GetChildPane(11));
    }
    SetHoverControl(31);
}

void MailDialog::SendDeleteCurrentMailRequest()
{
    SendMailDeleteRequest(m_mailListId, m_currentMailId);
    g_pUserPane->m_activeDialog = this;
    m_session->PopDialog();
}

void MailDialog::RefreshSelectedMailInList()
{
    MailListDialog *dialog = m_session->GetMailListDialog();
    if (!dialog)
        return;
    MailListPane *pane =
        static_cast<MailListPane *>(dialog->GetChildPane(7));
    pane->RemoveMailEntryById(m_currentMailId);
    dialog->UpdateButtonStates();
}

void MailDialog::OnCommand(int commandId, int controlId)
{
    switch (commandId) {
    case 1:
        OpenBlankComposeDialog();
        break;
    case 2:
        SendReply();
        break;
    case 3:
        CreateConfirmDeleteAlert();
        break;
    case 4:
        m_session->PopDialog();
        break;
    case 5:
        NavigateToAdjacentMail(false);
        break;
    case 6:
        m_session->DispatchDialogCommand(this, controlId);
        break;
    case 7:
        NavigateToAdjacentMail(true);
        break;
    default:
        BoardDialog::OnCommand(commandId, controlId);
        break;
    }
}

bool MailDialog::OnKeyInput(const unsigned char *keyState)
{
    const KeyEvent &event = *reinterpret_cast<const KeyEvent *>(keyState);
    if (event.key == 115 && event.modifiers == 2) {
        SaveCurrentMailToFile();
        return true;
    }
    return DialogPane::OnKeyInput(keyState);
}

void MailDialog::NavigateToAdjacentMail(bool forward)
{
    const int direction = forward ? 1 : -1;
    int nextId = static_cast<int>(m_currentMailId) + direction;
    if (nextId < 1 || nextId > 0x7fff)
        return;
    unsigned char packet[7] = { 0x3b, 0x03 };
    WriteUInt16BE(packet + 2, m_mailListId);
    WriteUInt16BE(packet + 4, static_cast<unsigned short>(nextId));
    packet[6] = static_cast<unsigned char>(direction);
    QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
    g_pUserPane->m_activeDialog = this;
    m_session->PopDialog();
}

void MailDialog::OpenBlankComposeDialog()
{
    m_session->PopDialog();
    m_session->OpenNewMailDialog(0, 0, 0);
}

void MailDialog::SendReply()
{
    wchar_t quotedText[0x8000];
    TextEditPane *body = static_cast<TextEditPane *>(GetChildPane(11));
    const short length = static_cast<short>(
        body->GetText(quotedText, 0x7fff));
    m_session->PopDialog();
    m_session->OpenNewMailDialog(m_sender, quotedText, length);
}

void MailDialog::CreateConfirmDeleteAlert()
{
    if (g_pConfirmDeleteMailAlert)
        return;
    g_pConfirmDeleteMailAlert = new ConfirmDeleteMailAlert(
        GetLocalizedString(64), this, L"OK", L"Cancel");
    g_pConfirmDeleteMailAlert->SetDeleteMode(
        ConfirmDeleteMailAlert::DeleteCurrentMail);
    g_pConfirmDeleteMailAlert->InstallViews();
}

bool MailDialog::OnMailDeleteReply(const unsigned char *packet)
{
    if (packet[1] != 7)
        return false;
    const bool shown = ShowMailDeleteReplyAlert(packet + 2);
    if (shown)
        RefreshSelectedMailInList();
    return shown;
}

bool MailDialog::ShowMailDeleteReplyAlert(const unsigned char *packet)
{
    if (g_pMailDeleteReplyAlert)
        return false;
    wchar_t message[256];
    const unsigned char length = packet[0];
    ConvertPacketTextToWide(packet + 1, length, message, 256);
    g_pMailDeleteReplyAlert =
        new MailDeleteReplyAlert(message, this, L"OK", 0);
    g_pMailDeleteReplyAlert->SetDeleteMode(
        MailDeleteReplyAlert::DeleteCurrentMail);
    return true;
}

static int SendMailNavigationRequest(unsigned short mailListId,
                                     unsigned short mailId,
                                     signed char direction)
{
    unsigned char packet[7] = { 0x3b, 0x03 };
    WriteUInt16BE(packet + 2, mailListId);
    WriteUInt16BE(packet + 4, mailId);
    packet[6] = static_cast<unsigned char>(direction);
    return QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
}

static int SendCurrentMailDeleteRequest(unsigned short mailListId,
                                        unsigned short mailId)
{
    unsigned char packet[6] = { 0x3b, 0x05 };
    WriteUInt16BE(packet + 2, mailListId);
    WriteUInt16BE(packet + 4, mailId);
    return QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
}

// UID:0003PX | by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md | Completion:94 | Confidence:94
#include <shlobj.h>
#include <stdio.h>
#include "MailDialogs.h"

void MailDialog::SaveCurrentMailToFile()
{
    wchar_t documents[MAX_PATH];
    if (FAILED(SHGetFolderPathW(
            0, CSIDL_PERSONAL | CSIDL_FLAG_CREATE, 0, SHGFP_TYPE_CURRENT,
            documents))) {
        return;
    }

    wchar_t nexusDirectory[MAX_PATH];
    wchar_t mailDirectory[MAX_PATH];
    wchar_t playerDirectory[MAX_PATH];
    swprintf(nexusDirectory, L"%s\\NexusTK", documents);
    swprintf(mailDirectory, L"%s\\NexusTK\\Mail", documents);
    swprintf(playerDirectory, L"%s\\%s", mailDirectory, g_playerName);
    CreateDirectoryW(nexusDirectory, 0);
    CreateDirectoryW(mailDirectory, 0);
    CreateDirectoryW(playerDirectory, 0);

    wchar_t path[MAX_PATH];
    swprintf(path, L"%s\\%d_%s_%s.txt",
             playerDirectory, m_currentMailId, m_sender, m_subject);
    FILE *file = _wfopen(path, L"wb");
    if (!file)
        return;

    WriteWideText(file, L"From : ");
    WriteWideText(file, m_sender);
    WriteWideText(file, L"\r\nDate : ");
    WriteWideText(file, m_date);
    WriteWideText(file, L"\r\nSubject : ");
    WriteWideText(file, m_subject);
    WriteWideText(file, L"\r\n\r\n");
    WriteWideText(file, m_body);
    fclose(file);
    ShowSystemMessage(L"Successfully saved mail");
}

// UID:000096 | by-class/NewMailDialog.md | Completion:94 | Confidence:93
// UID:0003PY | by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md | Completion:94 | Confidence:94
#include "MailDialogs.h"
#include "../../auth/PasswordGuard.h"

static signed char GetMailListLayoutOffset();
static int SendMailListPageRequest(unsigned short mailListId,
                                   unsigned short upperMailId,
                                   signed char layoutOffset);

NewMailDialog::NewMailDialog(BulletinSession *session,
                             const RectBounds &bounds,
                             const wchar_t *recipient,
                             const wchar_t *quotedText,
                             short quotedLength)
    : BoardDialog(session, bounds), m_session(session)
{
    const bool epfLayout = g_useEpfAssets == 1;
    SetDialogImage(epfLayout ? L"DLGBBS07.EPF" : L"DLGBBS07.EPD",
                   epfLayout ? L"DLGBBS07.PAL" : L"NPAL8.PAL");
    if (epfLayout) {
        AddDialogTextEdit(3, RectBounds(94, 58, 406, 70), recipient, 256, 1);
        AddDialogTextEdit(4, RectBounds(94, 85, 406, 97), L"", 256, 1);
        AddDialogTextEdit(5, RectBounds(25, 112, 430, 356), L"", 4000, 1024);
        AddDialogButton(23, RectBounds(144, 381, 207, 405), L"Send");
        AddDialogButton(22, RectBounds(231, 381, 294, 405), L"Cancel");
        AddDialogCheckBox(6, RectBounds(36, 384, 52, 400), false);
        AddDialogLabel(7, RectBounds(56, 386, 128, 398), L"Keep a copy");
    } else {
        AddDialogTextEdit(3, RectBounds(111, 73, 410, 85), recipient, 256, 1);
        AddDialogTextEdit(4, RectBounds(111, 93, 410, 105), L"", 256, 1);
        AddDialogTextEdit(5, RectBounds(36, 115, 410, 295), L"", 4000, 1024);
        AddDialogButton(23, RectBounds(149, 316, 221, 332), L"Send");
        AddDialogButton(22, RectBounds(226, 316, 298, 332), L"Cancel");
    }

    if (quotedText && quotedLength > 0)
        AppendQuotedMessage(quotedText, quotedLength);
    SetHoverControl(recipient && *recipient ? 4 : 3);
}

void NewMailDialog::RequestInitialMailPage()
{
    MailListDialog *dialog = m_session->GetMailListDialog();
    if (!dialog)
        return;
    MailListPane *pane =
        static_cast<MailListPane *>(dialog->GetChildPane(7));
    SendMailListPageRequest(
        pane->GetMailListId(), 0x7fff, GetMailListLayoutOffset());
}

void NewMailDialog::OnCommand(int commandId, int)
{
    switch (commandId) {
    case 1:
        SendMail(1);
        g_pUserPane->m_activeDialog = this;
        m_session->PopDialog();
        break;
    case 2:
        m_session->PopDialog();
        break;
    default:
        break;
    }
}

bool NewMailDialog::ShowSendFailureAlert(const unsigned char *packet)
{
    if (packet || g_pMailTransferReplyAlert)
        return false;
    if (m_session->IsDialogCurrent(this))
        m_session->PopDialog();
    g_pMailTransferReplyAlert = new MailTransferReplyAlert(
        L"Your mail didn't go through due to an error.", this, L"OK", 0);
    g_pMailTransferReplyAlert->SetMode(0);
    return true;
}

void NewMailDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}

// The names below are source-facing adapters for already documented project
// primitives. They keep packet, control, and session mechanics explicit without
// leaking disassembler labels or physical object offsets into recovered source.

bool NewMailDialog::AppendQuotedMessage(const wchar_t *text, short length)
{
    TextEditPane *body = static_cast<TextEditPane *>(GetChildPane(5));
    if (!body || !text || length <= 0)
        return false;

    body->SetText(text, length);
    int line = 0;
    while (line < body->GetLineCount()) {
        const int lineStart = body->GetLineStart(line);
        body->InsertText(lineStart, L"> ", 2);
        ++line;
    }
    body->AppendText(L"\n", 1);
    body->SetSelection(0, 0);
    return true;
}

bool NewMailDialog::OnMailTransferReplyPacket(const unsigned char *packet)
{
    if (packet[1] != 6)
        return false;
    return ShowMailTransferReplyAlert(packet + 2);
}

bool NewMailDialog::ShowMailTransferReplyAlert(const unsigned char *packet)
{
    wchar_t message[256];
    const unsigned char mode = packet[0];
    const unsigned char length = packet[1];
    ConvertPacketTextToWide(packet + 2, length, message, 256);
    MailTransferReplyAlert *alert =
        new MailTransferReplyAlert(message, this, L"OK", 0);
    alert->m_mode = mode;
    return true;
}

int NewMailDialog::SendMail(short)
{
    wchar_t recipient[256];
    wchar_t subject[256];
    wchar_t body[4096];
    GetTextEditValue(3, recipient, 256);
    GetTextEditValue(4, subject, 256);
    GetTextEditValue(5, body, 4096);

    ValidateChatInputOrThrowPasswordError(subject);
    ValidateChatInputOrThrowPasswordError(body);
    FilterAsciiAlphaNumeric(recipient);
    SanitizeMailText(subject);
    SanitizeMailText(body);

    char recipientText[256];
    char subjectText[256];
    char bodyText[4096];
    const int recipientLength =
        WideTextToPacketText(recipient, recipientText, sizeof(recipientText));
    const int subjectLength =
        WideTextToPacketText(subject, subjectText, sizeof(subjectText));
    const int bodyLength =
        WideTextToPacketText(body, bodyText, sizeof(bodyText));

    const int packetLength =
        2 + 2 + 1 + recipientLength + 1 + subjectLength +
        2 + bodyLength + 1;
    if (packetLength >= 0x7fff)
        return 0;

    unsigned char packet[0x8000];
    unsigned char *out = packet;
    PacketBufferWriteUInt8(0x3b, out);
    PacketBufferWriteUInt8(0x06, out);
    PacketBufferWriteUInt16BE(m_session->GetMailListId(), out);
    PacketBufferWriteUInt8(static_cast<unsigned char>(recipientLength), out);
    PacketBufferWriteBytes(recipientText, recipientLength, out);
    PacketBufferWriteUInt8(static_cast<unsigned char>(subjectLength), out);
    PacketBufferWriteBytes(subjectText, subjectLength, out);
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(bodyLength), out);
    PacketBufferWriteBytes(bodyText, bodyLength, out);
    PacketBufferWriteUInt8(IsControlChecked(6) ? 1 : 0, out);

    const int result =
        QueueAndSendPacket(g_packetSender, packet, packetLength);
    StartTimer(15000);
    return result;
}

// UID:000321 | by-type/by-vtable/MailDialogCoreVtables.md | Completion:94 | Confidence:95
// Compiler-generated MailDialogs vtables and RTTI are covered by the class declarations in [UID:00007L][MailListDialog](by-class/MailListDialog.md), [UID:00007M][MailListPane](by-class/MailListPane.md), [UID:00007K][MailDialog](by-class/MailDialog.md), and [UID:000096][NewMailDialog](by-class/NewMailDialog.md).
