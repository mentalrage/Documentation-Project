// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L8
// Source by-file doc: by-file/MenuVarietyPanes.md
// UID:000081 | by-class/MenuVarietyPane.md | Completion:87 | Confidence:90
struct PaneMouseEvent;
struct Rect;
class MenuVarietySelectPane;

class MenuVarietyPane : public Pane
{
public:
    MenuVarietyPane();
    virtual ~MenuVarietyPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();
    virtual int RefreshMenuButton();

private:
    unsigned char m_menuButtonPressed;    // +0xf8
};

extern MenuVarietyPane *g_pMenuVarietyPane;
extern MenuVarietySelectPane *g_pMenuVarietySelectPane;

static void GetMenuVarietyButtonRect(int row, Rect *rect);


// UID:0002Z1 | by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md | Completion:88 | Confidence:92
// Emitted code for this MenuVarietyPane vtable-data range is covered by [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md) MenuVarietyPane class declarations.

// UID:000082 | by-class/MenuVarietySelectPane.md | Completion:87 | Confidence:90
struct PaneMouseEvent;
struct PaneEvent;
struct Rect;
class SimpleUString;

class MenuVarietySelectPane : public Pane
{
public:
    MenuVarietySelectPane();
    virtual ~MenuVarietySelectPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnDismiss(const PaneEvent *event);
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kUserlookRow = 0,
        kBoardRow = 1,
        kMailRow = 2,
        kUserListRow = 3,
        kFriendsRow = 4,
        kTargetRow = 5,
        kHotkeyRow = 6,
        kProfileRow = 7,
        kRankingRow = 8,
        kQuitRow = 9,
        kMenuRowCount = 10,
        kNoMenuRow = -1
    };

    unsigned char m_menuRowPressed;       // +0xf8
    signed char m_highlightedMenuRow;     // +0xf9
    unsigned char m_reservedFA[2];        // +0xfa..+0xfb alignment
    SimpleUString *m_menuLabelsBegin;     // +0xfc
    SimpleUString *m_menuLabelsEnd;       // +0x100
    SimpleUString *m_menuLabelsCapacity;  // +0x104
};

extern MenuVarietySelectPane *g_pMenuVarietySelectPane;

static void GetMenuVarietyItemRect(int row, Rect *rect);
static int HitTestMenuVarietyItem(int x, int y);


// UID:0002Z2 | by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md | Completion:88 | Confidence:92
// Emitted code for this MenuVarietySelectPane vtable-data range is covered by [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md) MenuVarietySelectPane class declarations.

// UID:0000RI | by-global/g_pMenuVarietyPane.md | Completion:87 | Confidence:91
MenuVarietyPane *g_pMenuVarietyPane = NULL;

// UID:0000RJ | by-global/g_pMenuVarietySelectPane.md | Completion:87 | Confidence:90
MenuVarietySelectPane *g_pMenuVarietySelectPane = NULL;

// UID:0001NQ | by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md | Completion:87 | Confidence:91
static int HitTestMenuVarietyItem(int x, int y)
{
    Rect rect;

    for (int row = 0; row < 10; ++row) {
        SetRect(&rect, 0, row * 16 + 6, 79, row * 16 + 22);
        if (PointInRect(rect, x, y))
            return row;
    }

    return -1;
}

// UID:0003AH | by-memory\0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003AI | by-memory\0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003AJ | by-memory\0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003JD | by-memory\0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings.md | Completion:88 | Confidence:93 | Empty Emitter Marker
