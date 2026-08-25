// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IS
// Source by-file doc: by-file/DescPane.md
// UID:00003Q | by-class/DescPane.md | Completion:92 | Confidence:94
class DescPane;
extern DescPane *g_pDescPane;

class DescPane : public Pane
{
public:
    DescPane();
    virtual ~DescPane();

    static DescPane *GetSingleton();
    void SetSourceAndIndex(Pane *source, int selectedIndex);

protected:
    virtual void OnPaint();

private:
    Pane *m_pDescriptionSource;
    int m_selectedDescriptionIndex;
};

// UID:00012J | by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md | Completion:91 | Confidence:93
DescPane::DescPane()
    : Pane(1),
      m_pDescriptionSource(NULL),
      m_selectedDescriptionIndex(-1)
{
    g_pDescPane = this;
}

// UID:00012L | by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md | Completion:92 | Confidence:94
DescPane::~DescPane()
{
    g_pDescPane = NULL;
}

// UID:00012M | by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md | Completion:91 | Confidence:93
DescPane *DescPane::GetSingleton()
{
    return g_pDescPane;
}

// UID:00012N | by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md | Completion:92 | Confidence:93
void DescPane::SetSourceAndIndex(Pane *source, int selectedIndex)
{
    if (m_pDescriptionSource == source && m_selectedDescriptionIndex == selectedIndex)
        return;

    m_pDescriptionSource = source;
    m_selectedDescriptionIndex = selectedIndex;
    InvalidateRect(&m_bounds);
}

// UID:00012O | by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md | Completion:92 | Confidence:94
void DescPane::OnPaint()
{
    wchar_t description[1024];

    SetDrawColor(0);
    m_drawMode = 0;
    FillRect(&m_bounds);

    if (m_pDescriptionSource != NULL && m_selectedDescriptionIndex != -1)
        m_pDescriptionSource->GetDescription(m_selectedDescriptionIndex, description);
}

// UID:0001U3 | by-type/by-struct/DescPaneLayout.md | Completion:92 | Confidence:94
// DescPane field declarations are emitted by [UID:00003Q][DescPane](by-class/DescPane.md); do not duplicate a separate layout struct.

// UID:0001XC | by-type/by-vtable/DescPaneVtables.md | Completion:92 | Confidence:94
// DescPane virtual-table emission is covered by [UID:00003Q][DescPane](by-class/DescPane.md); do not hand-author table data.
// UID:0002NA | by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md | Completion:92 | Confidence:94
// Compiler-generated DescPane RTTI and vtable bytes for this range are covered by [UID:00003Q][DescPane](by-class/DescPane.md).

// UID:0000QR | by-global/g_pDescPane.md | Completion:92 | Confidence:94
DescPane *g_pDescPane = NULL;

// UID:0001PB | by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md | Completion:92 | Confidence:94
// Storage for this range is emitted by the g_pDescPane definition in [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md).
