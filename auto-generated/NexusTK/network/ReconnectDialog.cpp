// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N0
// Source by-file doc: by-file/ReconnectDialog.md
// UID:0004SO | by-global/g_pConnectionClosedDialog.md | Completion:91 | Confidence:93
class ConnectionClosedDialog;

ConnectionClosedDialog *g_pConnectionClosedDialog = NULL;

// UID:0004SQ | by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md | Completion:92 | Confidence:94
// Exact storage for g_pConnectionClosedDialog is represented by [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md); this range is source-declared/generated-binary storage evidence.

// UID:000039 | by-class/CopyWindow.md | Completion:95 | Confidence:96
#include "../localization/LanguageMan.h"
#include "../map/BackPane.h"
#include "../ui/controls/TextEditPane.h"
#include "../ui/dialogs/AlertPanes.h"

class CopyWindow : public AlertPane
{
public:
    CopyWindow()
        : AlertPane(g_pLanguageMan->GetLocalizedString(0xf1),
                    g_pBackPane,
                    L"Yes",
                    L"No")
    {
    }

protected:
    virtual void OnPrimaryButton()
    {
        g_pActiveTextEditPane->CopyAllToClipboard();
        g_pActiveTextEditPane = NULL;
    }

    virtual void OnSecondaryButton()
    {
        g_pActiveTextEditPane = NULL;
    }

    // UID:0001FV | by-memory/0x005544c0-0x0055454b.CopyWindow.md | Completion:95 | Confidence:96
// The retained out-of-line constructor and both button callbacks are covered by the inline CopyWindow class emitted through [UID:000039][CopyWindow](by-class/CopyWindow.md).

// UID:0003CV | by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md | Completion:94 | Confidence:97
// CopyWindow RTTI and three inherited-facet vtables are compiler-generated from the CopyWindow class declaration and virtual overrides in [UID:000039][CopyWindow](by-class/CopyWindow.md).

// UID:0003G5 | by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md | Completion:94 | Confidence:97
// The pooled UTF-16 L"No" bytes are emitted by the CopyWindow constructor source in [UID:000039][CopyWindow](by-class/CopyWindow.md).

// UID:0003G6 | by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md | Completion:94 | Confidence:97
// The pooled UTF-16 L"Yes" bytes are emitted by the CopyWindow constructor source in [UID:000039][CopyWindow](by-class/CopyWindow.md).
};

// UID:0004SP | by-global/g_pReconnectDialog.md | Completion:91 | Confidence:93
class ReconnectDialog;

ReconnectDialog *g_pReconnectDialog = NULL;

// UID:0004SR | by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md | Completion:92 | Confidence:94
// Exact storage for g_pReconnectDialog is represented by [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md); this range is source-declared/generated-binary storage evidence.

// UID:000036 | by-class/ConnectionClosedDialog.md | Completion:92 | Confidence:94
class Event;
class Pane;

class ConnectionClosedDialog : public AlertPane,
                               public Singleton<ConnectionClosedDialog>
{
public:
    ConnectionClosedDialog();
    explicit ConnectionClosedDialog(Pane *layoutReference);

protected:
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

private:
    void InitializeConnectionState();
};

typedef char ConnectionClosedDialogSizeMustBe624[
    sizeof(ConnectionClosedDialog) == 0x270 ? 1 : -1];

// UID:00023O | by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md | Completion:92 | Confidence:94
ConnectionClosedDialog::ConnectionClosedDialog()
    : AlertPane(g_pLanguageMan->GetLocalizedString(154),
                g_pBackPane,
                L"Reconnect",
                L"Leave")
{
    InitializeConnectionState();
}

// UID:00038J | by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md | Completion:92 | Confidence:94
ConnectionClosedDialog::ConnectionClosedDialog(Pane *layoutReference)
    : AlertPane(g_pLanguageMan->GetLocalizedString(154),
                layoutReference,
                L"Reconnect",
                L"Leave")
{
    InitializeConnectionState();
}

bool ConnectionClosedDialog::HandlePacketEvent(Event *)
{
    return true;
}

void ConnectionClosedDialog::OnPrimaryButton()
{
    delete g_pReconnectDialog;
    new ReconnectDialog(m_layoutReference);
}

void ConnectionClosedDialog::OnSecondaryButton()
{
    g_pApplication->RequestExit();
}

// UID:0001FU | by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md | Completion:92 | Confidence:94
void ConnectionClosedDialog::InitializeConnectionState()
{
    if (g_pActiveTextEditPane != NULL && g_pActiveTextEditPane->GetTextLength() > 0)
        new CopyWindow;

    g_packetSender->PostSocketModeByteCommand(1);
    g_packetSender->WaitForQueueDrain();

    if (g_pScreenDimmer != NULL)
        g_pScreenDimmer->SetDimmed(true);
}

// UID:0003CT | by-memory/0x00622d30-0x00622dd4.ConnectionClosedDialogVtableData.md | Completion:90 | Confidence:94
// [UID:0003CT] ConnectionClosedDialog RTTI and primary/EventHandler/TimerHandler
// vtable bytes are compiler-generated from the [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) class declaration,
// its inherited virtual destructor, and its source-level callback implementations.
// Do not emit raw RTTI, vtable, adjustor-thunk, or scalar-delete-wrapper arrays.

// UID:0000BR | by-class\ReconnectDialog.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:00038L | by-memory\0x00553f40-0x005544b8.ReconnectDialogMethods.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003CU | by-memory\0x00622dd4-0x00622e78.ReconnectDialogVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003G3 | by-memory\0x00622f1c-0x00622f28.SharedLeaveWideString.md | Completion:89 | Confidence:94 | Empty Emitter Marker

// UID:0003G4 | by-memory\0x00622f28-0x00622f3c.SharedReconnectWideString.md | Completion:89 | Confidence:94 | Empty Emitter Marker

// UID:0003G7 | by-memory\0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md | Completion:89 | Confidence:94 | Empty Emitter Marker
