// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JQ
// Source by-file doc: by-file/GeneralPurposePanel.md
// UID:0000R0 | by-global/g_pGeneralPurposePanel.md | Completion:92 | Confidence:94
class GeneralPurposePanel;

GeneralPurposePanel *g_pGeneralPurposePanel = 0;

// UID:00005Q | by-class/GeneralPurposePanel.md | Completion:92 | Confidence:94
class GeneralPurposePanel : public LObject, public Singleton<GeneralPurposePanel>
{
public:
    GeneralPurposePanel();
    virtual ~GeneralPurposePanel();

    Pane *GetChildPaneByIndex(int index);
    Pane *GetActiveChildPane();
    void DispatchActiveChildRefresh();
    void SwitchActiveTab(
        int tabIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[7];
    int m_activeChildIndex;
};

extern GeneralPurposePanel *g_pGeneralPurposePanel;

// UID:0004UL | by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md | Completion:92 | Confidence:94
GeneralPurposePanel::GeneralPurposePanel()
    : Singleton<GeneralPurposePanel>(),
      m_activeChildIndex(-1)
{
    m_childPanes[0] = new SelfLookPane;
    m_childPanes[1] = new UserLookPane;
    m_childPanes[2] = new NewInventoryPane;
    m_childPanes[3] = new NewSpellInventoryPane;
    m_childPanes[4] = new NewGroupPane;
    m_childPanes[5] = new CollectionPane;
    m_childPanes[6] = new NewOptionPane;
}

// UID:0004UM | by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md | Completion:92 | Confidence:94
GeneralPurposePanel::~GeneralPurposePanel()
{
    for (int index = 0; index < 7; ++index)
        m_childPanes[index]->MarkForDeletion();
}

// UID:00015W | by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md | Completion:92 | Confidence:94
Pane* GeneralPurposePanel::GetChildPaneByIndex(int index)
{
    const int childCount = (g_useEpfAssets == 1) ? 7 : 4;
    if (index >= childCount) {
        return NULL;
    }

    return m_childPanes[index];
}

Pane* GeneralPurposePanel::GetActiveChildPane()
{
    if (m_activeChildIndex == -1) {
        return NULL;
    }

    return m_childPanes[m_activeChildIndex];
}

void GeneralPurposePanel::DispatchActiveChildRefresh()
{
    if (m_activeChildIndex != -1) {
        m_childPanes[m_activeChildIndex]->InvalidateRect(NULL);
    }
}

// UID:00015X | by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md | Completion:91 | Confidence:94
void GeneralPurposePanel::SwitchActiveTab(
    int tabIndex,
    const unsigned char *packetData)
{
    if (g_useEpfAssets == 1) {
        if (tabIndex >= 7)
            return;

        if (tabIndex == m_activeChildIndex &&
            tabIndex != 0 &&
            tabIndex != 1)
            return;

        if (g_pTotemFrame != NULL)
            g_pTotemFrame->MarkForDeletion();

        Pane *oldChild = NULL;
        if (m_activeChildIndex != -1)
            oldChild = m_childPanes[m_activeChildIndex];

        if (oldChild != NULL) {
            oldChild->Collapse();
            oldChild->UnregisterEventHandler();
        }

        m_activeChildIndex = tabIndex;

        Pane *newChild = NULL;
        if (tabIndex != -1)
            newChild = m_childPanes[tabIndex];

        RectBounds bounds;
        bounds.SetLTRB(832, 79, 1021, 367);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        newChild->OnActivate(packetData);
        ReleaseDynamicAboveFrame();
        RecreateDynamicAboveFrame();
    } else {
        if (tabIndex >= 4)
            return;

        if (tabIndex == m_activeChildIndex &&
            tabIndex != 0 &&
            tabIndex != 1)
            return;

        if (g_pTotemFrame != NULL)
            g_pTotemFrame->MarkForDeletion();

        Pane *oldChild = NULL;
        if (m_activeChildIndex != -1)
            oldChild = m_childPanes[m_activeChildIndex];

        if (oldChild != NULL) {
            oldChild->Collapse();
            oldChild->UnregisterEventHandler();
        }

        m_activeChildIndex = tabIndex;

        Pane *newChild = NULL;
        if (tabIndex != -1)
            newChild = m_childPanes[tabIndex];

        RectBounds bounds;
        bounds.SetLTRB(434, 12, 626, 300);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        if (packetData != NULL)
            newChild->OnActivate(packetData);
        g_pInterfaceEfxMgr->TriggerInterfaceEffect(m_activeChildIndex);
    }
}

// UID:0000R1 | by-global/g_pGeneralPurposePanel2.md | Completion:92 | Confidence:94
class GeneralPurposePanel2;

GeneralPurposePanel2 *g_pGeneralPurposePanel2 = 0;

// UID:00005R | by-class/GeneralPurposePanel2.md | Completion:92 | Confidence:94
class GeneralPurposePanel2 : public LObject, public Singleton<GeneralPurposePanel2>
{
public:
    GeneralPurposePanel2();
    virtual ~GeneralPurposePanel2();

    Pane *GetChildPaneByIndex(int index);
    Pane *GetActiveChildPane();
    void DispatchActiveChildRefresh();
    void SwitchActiveChild(
        int childIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[1];
    int m_activeChildIndex;
};

extern GeneralPurposePanel2 *g_pGeneralPurposePanel2;

// UID:0004UU | by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md | Completion:92 | Confidence:94
GeneralPurposePanel2::GeneralPurposePanel2()
    : Singleton<GeneralPurposePanel2>(),
      m_activeChildIndex(-1)
{
    m_childPanes[0] = new NewSystemMessagePane;
}

// UID:0004UV | by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md | Completion:92 | Confidence:94
GeneralPurposePanel2::~GeneralPurposePanel2()
{
    m_childPanes[0]->MarkForDeletion();
}

// UID:0004UW | by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md | Completion:92 | Confidence:94
Pane *GeneralPurposePanel2::GetChildPaneByIndex(int index)
{
    if (index >= 1)
        return NULL;

    return m_childPanes[index];
}

// UID:0004UX | by-memory/0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane.md | Completion:90 | Confidence:92
Pane *GeneralPurposePanel2::GetActiveChildPane()
{
    if (m_activeChildIndex == -1)
        return NULL;

    return m_childPanes[m_activeChildIndex];
}

// UID:0004UY | by-memory/0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh.md | Completion:90 | Confidence:92
void GeneralPurposePanel2::DispatchActiveChildRefresh()
{
    if (m_activeChildIndex != -1)
        m_childPanes[m_activeChildIndex]->InvalidateRect(NULL);
}

// UID:00015Y | by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md | Completion:91 | Confidence:93
void GeneralPurposePanel2::SwitchActiveChild(
    int childIndex,
    const unsigned char *packetData)
{
    if (childIndex >= 1)
        return;

    if (g_pTotemFrame != NULL)
        g_pTotemFrame->MarkForDeletion();

    Pane *oldChild = NULL;
    if (m_activeChildIndex != -1)
        oldChild = m_childPanes[m_activeChildIndex];

    m_activeChildIndex = childIndex;

    if (oldChild != NULL) {
        oldChild->Collapse();
        oldChild->UnregisterEventHandler();
    }

    if (m_activeChildIndex != -1) {
        Pane *newChild = m_childPanes[m_activeChildIndex];
        RectBounds bounds;
        bounds.SetLTRB(832, 376, 1021, 641);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        newChild->OnActivate(packetData);
    }

    ReleaseDynamicAboveFrame();
    RecreateDynamicAboveFrame();
}
