// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LQ
// Source by-file doc: by-file/NewHistoryDialogPane.md
// UID:0000RS | by-global/g_pNewHistoryDialog.md | Completion:92 | Confidence:94
class NewHistoryDialogPane;

NewHistoryDialogPane *g_pNewHistoryDialog = 0;

// UID:000091 | by-class/NewHistoryDialogPane.md | Completion:92 | Confidence:94
class Event;
class NewHistoryDialogPane;
extern NewHistoryDialogPane *g_pNewHistoryDialog;

class NewHistoryDialogPane : public DialogPane,
                             public Singleton<NewHistoryDialogPane>
{
public:
    NewHistoryDialogPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
};

[[No Children Attached]]

// UID:0001A3 | by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md | Completion:92 | Confidence:94
NewHistoryDialogPane::NewHistoryDialogPane()
    : DialogPane(L"", -1, true),
      Singleton<NewHistoryDialogPane>()
{
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 1024, 768);
    AddControl(new EPFImageControlPane(L"HISTORYN.EPF", 0, true, &bounds, L"HISTORYN.PAL"));

    InitRectBounds(&bounds, 614, 156, 950, 556);
    AddControl(new ScrolledTextControlPaneForMadeBy(L"MADEBY", &bounds, 30));

    SetBackgroundResource(L"HISTORYN.EPF", 0);
    SetMode(1);

    InitRectBounds(&bounds, 0, 0, 1024, 768);
    OnCreate(&bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(0, g_pMainMenuPane);
}

bool NewHistoryDialogPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        const unsigned char key =
            g_pEventMan->TranslateEventKey(event->m_payload.m_key.m_key,
                                           event->m_payload.m_key.m_modifiers);
        if (key == '\r' || key == '\x1b' || key == ' ')
        {
            CloseDialog();
        }
    }

    return true;
}

bool NewHistoryDialogPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp ||
        event->m_type == kEventRightButtonUp)
    {
        CloseDialog();
    }

    return true;
}
