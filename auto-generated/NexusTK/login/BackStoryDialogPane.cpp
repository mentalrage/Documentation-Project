// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HP
// Source by-file doc: by-file/BackStoryDialogPane.md
// UID:0000Q9 | by-global/g_pBackStoryDialogPane.md | Completion:92 | Confidence:94
class BackStoryDialogPane;

BackStoryDialogPane *g_pBackStoryDialogPane = 0;

// UID:00000T | by-class/BackStoryDialogPane.md | Completion:92 | Confidence:94
class BackStoryDialogPane;
extern BackStoryDialogPane *g_pBackStoryDialogPane;

class BackStoryDialogPane : public DialogPane,
                            public Singleton<BackStoryDialogPane>
{
public:
    BackStoryDialogPane();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};

[[No Children Attached]]

// UID:0001A2 | by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md | Completion:92 | Confidence:94
BackStoryDialogPane::BackStoryDialogPane()
    : DialogPane(L"", -1, true),
      Singleton<BackStoryDialogPane>()
{
    RectBounds bounds;

    if (g_useEpfAssets)
    {
        InitRectBounds(&bounds, 0, 0, 384, 341);
        AddControl(new EPFImageControlPane(L"STORY.EPF", 0, true, &bounds, L"PAL01.PAL"));

        InitRectBounds(&bounds, 169, 305, 232, 329);
        AddControl(new ImageButtonControlPane(14, &bounds));

        InitRectBounds(&bounds, 25, 56, 361, 278);
        AddControl(new ScrolledTextControlPane(L"BACKTALE", &bounds, 50));

        SetHoverControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"STORY.EPF", 0);
        SetMode(1);

        InitRectBounds(&bounds, 246, 150, 630, 491);
    }
    else
    {
        InitRectBounds(&bounds, 0, 0, 267, 337);
        AddControl(new EPFImageControlPane(L"STORY.EPD", 0, true, &bounds, L"NPAL8.PAL"));

        InitRectBounds(&bounds, 98, 287, 170, 303);
        AddControl(new ImageButtonControlPane(14, &bounds));

        InitRectBounds(&bounds, 36, 71, 228, 265);
        AddControl(new ScrolledTextControlPane(L"BACKTALE", &bounds, 50));

        SetHoverControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"STORY.EPD", 0);
        SetMode(1);

        InitRectBounds(&bounds, 363, 150, 630, 487);
    }

    OnCreate(&bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(0, g_pMainMenuPane);
    SlideOpenVertical();
}

void BackStoryDialogPane::OnControlCommand(int controlIndex, int)
{
    if (controlIndex == 1)
    {
        SlideCloseVertical();
        CloseDialog();
    }
}
