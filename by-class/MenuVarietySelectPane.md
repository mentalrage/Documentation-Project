*** UID:000082 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuVarietySelectPane

## Status

- Confidence: strong for class role, boundaries, declaration-level source shape, selector lifecycle, label-vector state, row constants, helper ownership, and vtable coverage; remaining uncertainty is limited to exact original helper/method spellings and final string facade typedef.
- Likely source file: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Main address range: [UID:0001NP][0x005bc610-0x005c0034.MenuVarietyPanes](by-memory/0x005bc610-0x005c0034.MenuVarietyPanes.md)
- Current recovered file: `source-3/simroot_v2/class_MenuVarietySelectPane.cpp`
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Class Purpose

`MenuVarietySelectPane` is the selector opened by `MenuVarietyPane`. It stores menu labels, handles mouse selection, dispatches userlook/board/mail/friends/target/hotkey/profile/ranking/quit actions, and draws SUBWIN frame/border plus menu entries.

## Source Reconstruction Policy

The formal C++ block is intentionally declaration-only. It declares the `Pane`-derived selector class, the ten row constants, confirmed tail fields, helper prototypes, and `[[CHILDREN]]` so the exact constructor/destructor/mouse/draw/helper pages remain the source-body emitters. The `SimpleUString *m_menuLabelsBegin/End/Capacity` triplet is a source-facing conservative declaration for the observed vector storage at `+0xfc/+0x100/+0x104`; the exact public container typedef remains a final-audit issue, not an empty-emitter blocker.

Current MCP session `3fa0535f` supports this source shape: the constructor at `0x005bc970` calls `Pane::Pane(mode=1)`, publishes [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md), installs vtables at `0x00630dc8`, `0x00630e1c`, and `0x00630e4c`, clears `+0xf8`, initializes `+0xf9` to `-1`, zeroes the vector triplet, and appends labels for Userlook, Board, Mail, UserList, Friends, Target, Hotkey, Profile, Ranking, and Quit.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005bc970-0x005bcf7a` | `MenuVarietySelectPane::MenuVarietySelectPane()` | Constructs pane state and appends menu/action labels. |
| `0x005bcf80-0x005bcff7` | `~MenuVarietySelectPane()` | Removes/unregisters pane, destroys label vector, and clears global pointer. |
| `0x005bd000-0x005bd372` | `HandleMenuMouseEvent(...)` | Hover/click handler and action dispatcher. |
| `0x005bd3a0-0x005bd3bf` | `NotifyAndMarkSessionForDeletion()` | Pulses parent and marks session for deletion. |
| `0x005bd3c0-0x005bd5ac` | `DrawMenuEntries()` | Draws labels and selected-row marker. |
| `0x005bd5b0-0x005bd952` | Frame/border drawing | Draws SUBWIN fill and border tiles. |
| `0x005bd960-0x005bd9ad` | [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md) | Raw selector-row rectangle helper for one menu row. |
| `0x005bd9b0-0x005bda3b` | [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md) | Ten-row selector hit-test helper called only by `HandleMenuMouseEvent`; currently generated as `BulletinSession::GetMenuIndexFromPoint`. |
| `0x005bfbd0-0x005bfbdb` | `ClearMenuVarietySelectPaneSingleton` | Clears [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md). |
| `0x005bfc21-0x005bfc37` | Adjustor/thunk helpers | Destructor adjustor helpers. |
| `0x005bfce0-0x005bfd98` | `ScalarDeletingDestructor(...)` | Destructor wrapper with scalar-delete flag handling. |
| `0x005bffe0-0x005c0034` | [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md) | Label-vector append/move helper used by constructor label setup. |

## Evidence Notes

- Wave3 grades the class at effective `96.3`.
- IDA MCP confirms all listed starts as exact functions.
- IDA MCP on 2026-05-26 confirms `0x005bd9b0` is a ten-row hit-test helper with callers only at `0x005bd089` and `0x005bd338` inside `MenuVarietySelectPane::HandleMenuMouseEvent`.
- IDA xrefs and active simroot names resolve global `0x0069bf78` as [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md); the `0x005bfbd0` helper clears this selector singleton.
- The quit action constructs [UID:0000BG][QuitDialog](by-class/QuitDialog.md) at `0x005bd202`; the confirmation dialog implementation belongs to [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).
- Older notes classify adjacent vector helpers as generic small-wide-string vector support, not class-owned menu-variety logic.
- 2026-06-11 A002 live IDA MCP raw-gap audit split [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md), which builds one row rectangle using `index * 16 + 6..22`, width `0..79`, and `sub_4B7C50`; surrounding bytes are `0xcc` padding.
- 2026-06-11 A002 live IDA MCP reconfirmed [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md) as the 24-byte label-vector append/move helper called directly from the selector constructor at `0x005bceef` and `0x005bcf2d`.
- 2026-06-29 B003 implementation callback raises this page to `87/90` and resolves the empty formal block with a declaration/prototype layer. Current MCP session `3fa0535f` reconfirmed `+0xf8/+0xf9`, the label vector triplet at `+0xfc/+0x100/+0x104`, label construction, selector destructor cleanup, and `HandleMenuMouseEvent` calls to [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md).

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md)
- [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md)
- [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md)
- [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md)
- [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md)
- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Changes

- 2026-06-29 B003 implementation callback:
  - Changed to `COMPLETION:87`, `CONFIDENCE:90`, `EMITTER_POSITION_OPTIONAL:0`, and inserted the formal declaration/prototype C++ block with `[[CHILDREN]]`.
  - Summary/evidence: current MCP session `3fa0535f` reconfirmed constructor/destructor/mouse facts, `g_pMenuVarietySelectPane` publish/clear, state bytes `+0xf8/+0xf9`, label-vector storage at `+0xfc/+0x100/+0x104`, the ten selector labels, vtable stores at `0x00630dc8/0x00630e1c/0x00630e4c`, and the two hit-test caller sites. Vtable bytes now emit through [UID:0002Z2][0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData](by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md)'s marker-only coverage, not as raw table arrays.
- 2026-06-11 A002 Batch 199 parent-gate refresh: raised completion/confidence from `84/86` to `86/88` after splitting the selector row rectangle helper as [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md) and documenting constructor use of [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md). Evidence: live IDA MCP confirmed exact raw helper boundaries, row-rectangle constants, vector-helper callers inside the selector constructor, and padding boundaries, so this class now clears the corrected `85/85` direct-parent gate for [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md).
- 2026-06-05: Marked reconstructable and attached to [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) because the class is `84/86` and the parent is `86/82`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x005bc970`, `0x005bcf80`, `0x005bd000`, `0x005bd3a0`, `0x005bd3c0`, `0x005bd5b0`, `0x005bd9b0`, `0x005bfbd0`, and `0x005bfce0`; `callers` confirms the constructor is reached from `0x005bc765` in `MenuVarietyPane` click handling.
- Completion/confidence score update: existed before as `0/0`; changed to `84/86`. Summary: the menu selector pane is documented in high detail across construction, labels/actions, mouse dispatch, draw/frame helpers, singleton cleanup, hit-test helper, quit-dialog dependency, and generic vector-helper exclusion. Evidence: linked `MenuVarietyPanes` range, IDA-confirmed method starts, singleton global references, 2026-05-26 hit-test caller recheck, and adjacent vector-helper classification.
