// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MN
// Source by-file doc: by-file/PopupMenuControls.md
// UID:0001V5 | by-type/by-struct/MenuItemLayouts.md | Completion:92 | Confidence:94
#include "PopupMenuControls.h"

// UID:00007V | by-class/MenuItem.md | Completion:93 | Confidence:94
// UID:0002J3 | by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md | Completion:86 | Confidence:91
MenuItem::MenuItem()
    : LObject()
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
    m_enabled = true;
    m_selected = false;
}

// UID:0002J4 | by-memory/0x00516f70-0x00516f74.MenuItemIsEnabled.md | Completion:90 | Confidence:93
bool MenuItem::IsEnabled() const
{
    return m_enabled;
}

// UID:0002JH | by-memory/0x00516f80-0x00516f8d.MenuItemSetEnabled.md | Completion:90 | Confidence:93
void MenuItem::SetEnabled(bool enabled)
{
    m_enabled = enabled;
}

// UID:0002J5 | by-memory/0x00516f90-0x00516f94.MenuItemIsSelected.md | Completion:90 | Confidence:93
bool MenuItem::IsSelected() const
{
    return m_selected;
}

// UID:0002JI | by-memory/0x00516fa0-0x00516fad.MenuItemSetSelected.md | Completion:90 | Confidence:93
void MenuItem::SetSelected(bool selected)
{
    m_selected = selected;
}

// UID:0002JJ | by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md | Completion:92 | Confidence:94
RectBounds *MenuItem::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_bounds;
    return outBounds;
}

// UID:0002JK | by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md | Completion:90 | Confidence:93
void MenuItem::SetBounds(const RectBounds *bounds)
{
    m_bounds = *bounds;
}

// UID:0002JF | by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md | Completion:86 | Confidence:92
// [UID:0002JF] compiler-generated MenuItem scalar deleting destructor wrapper;
// rebuilt from ordinary virtual MenuItem destructor semantics, not handwritten source.

// UID:0000E8 | by-class/StringMenuItem.md | Completion:92 | Confidence:94
// UID:0002J6 | by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md | Completion:87 | Confidence:91
StringMenuItem::StringMenuItem(const wchar_t *text)
    : MenuItem()
{
    wcscpy_s(m_text, _countof(m_text), text);
}

// UID:0002J7 | by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md | Completion:87 | Confidence:92
errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_text);
}

// UID:0002J8 | by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md | Completion:87 | Confidence:90
MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const
{
    const int textLength = static_cast<int>(wcslen(m_text));
    const short textWidth = port->GetTextWidth(m_text, textLength);

    MenuItemMetrics metrics = { 14, static_cast<int>(textWidth) + 24 };
    return metrics;
}

// UID:0002J9 | by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md | Completion:94 | Confidence:95
errno_t StringMenuItem::GetText(wchar_t *destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_text);
}

// UID:0002JA | by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md | Completion:88 | Confidence:91
void StringMenuItem::DrawItem(GrafPort *port)
{
    port->m_textRunDirty = true;

    if (IsSelected()) {
        port->SetTextColor(0x80);
        g_surfaceRenderCallbacks.fillOrInvalidate(port, &m_bounds);
        port->SetBackgroundColor(0x8f);
    } else {
        port->SetBackgroundColor(0x80);
    }

    port->MoveTo(m_bounds.left + 12, m_bounds.bottom - 1);
    port->DrawWideText(m_text, static_cast<int>(wcslen(m_text)));
}

// UID:0000CY | by-class/SeparatorMenuItem.md | Completion:92 | Confidence:94
// UID:0002JB | by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md | Completion:87 | Confidence:92
SeparatorMenuItem::SeparatorMenuItem()
    : MenuItem()
{
    m_enabled = false;
}

// UID:0002JC | by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md | Completion:86 | Confidence:92
MenuItemMetrics SeparatorMenuItem::GetDefaultDimensions() const
{
    MenuItemMetrics metrics = { 6, 20 };
    return metrics;
}

// UID:0002JD | by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md | Completion:86 | Confidence:92
MenuItemStyleFlags SeparatorMenuItem::GetStyleFlags() const
{
    MenuItemStyleFlags flags = { 0 };
    return flags;
}

// UID:0002JE | by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md | Completion:88 | Confidence:92
void SeparatorMenuItem::DrawItem(GrafPort *port)
{
    port->m_drawMode = 0;
    port->SetDrawColor(0x80);

    const int centerY = (m_bounds.top + m_bounds.bottom) / 2;

    RectBounds separatorRect;
    separatorRect.left = m_bounds.left + 3;
    separatorRect.top = centerY - 1;
    separatorRect.right = m_bounds.right - 3;
    separatorRect.bottom = centerY + 2;

    g_surfaceRenderCallbacks.fillOrInvalidate(port, &separatorRect);
}

// UID:0001Y4 | by-type/by-vtable/MenuItemVtables.md | Completion:93 | Confidence:95
// [UID:0001Y4] MenuItem/StringMenuItem/SeparatorMenuItem vtable layout evidence.
// MSVC regenerates this vtable data from the class declarations and exact virtual method implementations.
// UID:00036I | by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md | Completion:94 | Confidence:95
// [UID:00036I] Compiler-generated MenuItem, StringMenuItem, and
// SeparatorMenuItem RTTI complete-object-locator and vtable data.
// The class declarations and virtual method implementations regenerate this
// range; no fixed-address RTTI object, vtable array, or deleting wrapper is
// handwritten.

// UID:00007W | by-class/MenuPane.md | Completion:86 | Confidence:89
// MenuPane class declaration is intentionally withheld until its field layout,
// callback object ownership, and final method names are ready for source-quality declaration C++.




// UID:0000AN | by-class/PopupMenuControlPane.md | Completion:90 | Confidence:92
// UID:0004IM | by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md | Completion:91 | Confidence:92
PopupMenuControlPane::PopupMenuControlPane(DialogPane *parentDialog,
                                           const RectBounds *bounds)
    : ControlPane(3, bounds),
      m_menuPane(0),
      m_selectedIndex(-1),
      m_parentDialog(parentDialog)
{
    typedef void (PopupMenuControlPane::*SelectionCallback)(long);

    FunctionObjectT<long> *callback =
        new PlainMemberFunctionObject<SelectionCallback, PopupMenuControlPane, long>(
            &PopupMenuControlPane::SetSelectedIndex, 0, this);

    m_menuPane = new MenuPane(callback);
    m_controlFlags = 1;
}

// UID:0004IN | by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md | Completion:92 | Confidence:94
PopupMenuControlPane::~PopupMenuControlPane()
{
    delete m_menuPane;
}

// UID:0004IO | by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md | Completion:90 | Confidence:92
void PopupMenuControlPane::AppendItem(MenuItem *item)
{
    m_menuPane->AppendItem(item);
}

// UID:0004IP | by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md | Completion:90 | Confidence:93
MenuItem *PopupMenuControlPane::GetItem(int index) const
{
    return m_menuPane->GetItem(index);
}

// UID:0004IQ | by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md | Completion:90 | Confidence:93
int PopupMenuControlPane::GetItemCount() const
{
    return m_menuPane->GetItemCount();
}

// UID:0004IR | by-memory/0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex.md | Completion:90 | Confidence:94
long PopupMenuControlPane::GetSelectedIndex() const
{
    return m_selectedIndex;
}

// UID:0004IS | by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md | Completion:94 | Confidence:93
void PopupMenuControlPane::SelectItemAndNotifyParent(long index)
{
    DialogPane *parentDialog = static_cast<DialogPane *>(GetParent());

    SetSelectedIndex(index);

    const int controlIndex = parentDialog->FindControlIndex(this);
    if (controlIndex != -1)
        parentDialog->OnControlCommand(controlIndex, 12);
}

// UID:0004IT | by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md | Completion:91 | Confidence:92
void PopupMenuControlPane::SetSelectedIndex(long index)
{
    if (index == m_selectedIndex || index == -1)
        return;

    m_selectedIndex = index;
    InvalidateRect(&m_bounds);

    DialogPane *parentDialog = static_cast<DialogPane *>(GetParent());
    if (parentDialog != 0) {
        const int controlIndex = parentDialog->FindControlIndex(this);
        parentDialog->OnControlCommand(controlIndex, 10);
    }
}

// UID:0004IU | by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md | Completion:90 | Confidence:91
void PopupMenuControlPane::OnDraw()
{
    EPFTileContext leftTile;
    EPFTileContext centerTile;
    EPFTileContext rightTile;


    g_pResourceLayoutTable->LookupLayoutEntry(L"POPUPMNU.EPF", 0, &leftTile);
    g_pResourceLayoutTable->LookupLayoutEntry(L"POPUPMNU.EPF", 1, &centerTile);
    g_pResourceLayoutTable->LookupLayoutEntry(L"POPUPMNU.EPF", 2, &rightTile);

    const int leftWidth = leftTile.bounds.right - leftTile.bounds.left;
    const int rightWidth = rightTile.bounds.right - rightTile.bounds.left;

    RectBounds destination = m_bounds;
    destination.right = destination.left + leftWidth;
    m_drawMode = 0;
    RenderTileFrame(&leftTile, &leftTile.bounds, &destination, 0, L"NPAL8.PAL", 0);

    destination = m_bounds;
    destination.left += leftWidth;
    destination.right -= rightWidth;
    DrawTiledBackground(&destination, &centerTile, L"NPAL8.PAL");

    destination = m_bounds;
    destination.left = destination.right - rightWidth;
    RenderTileFrame(&rightTile, &rightTile.bounds, &destination, 0, L"NPAL8.PAL", 0);

    wchar_t selectedText[256];
    selectedText[0] = L'\0';
    if (m_selectedIndex != -1)
        m_menuPane->GetItem(m_selectedIndex)->GetText(selectedText, _countof(selectedText));

    SetTextColor(0x25);
    MoveTo(m_bounds.left + 1, m_bounds.bottom - 2);
    DrawWideText(selectedText, static_cast<int>(wcslen(selectedText)));

    if (!m_controlVisible) {
        m_drawMode = 2;
        SetDrawColor(0x8f);
        g_surfaceRenderCallbacks.fillOrInvalidate(this, &m_bounds);
    }

    if (m_controlVisible && m_controlActive) {
        SetDrawColor(0x80);
        m_drawMode = 0;
        DrawRectFrame(&m_bounds);
    }
}

// UID:0004IV | by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md | Completion:90 | Confidence:92
bool PopupMenuControlPane::OnMouseEvent(const PaneMouseEvent *event)
{
    if (event->eventKind == kEventLeftButtonUp &&
        PointInRect(event->y, event->x, &m_bounds)) {
        Point screenOffset;
        GetScreenOffset(&screenOffset);

        m_menuPane->Show(m_parentDialog,
                         screenOffset.x + m_bounds.right - m_bounds.left - 1,
                         screenOffset.y,
                         m_selectedIndex);
    }

    return false;
}

// UID:0004IW | by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md | Completion:90 | Confidence:92
bool PopupMenuControlPane::OnKeyDown(const PaneKeyEvent *event)
{
    const unsigned char key =
        g_pEventMan->TranslateEventKey(event->payload[0], event->keyState);

    if (event->eventKind != kEventKeyDown || key != 0x83 || event->keyState != 0)
        return false;

    Point screenOffset;
    GetScreenOffset(&screenOffset);

    m_menuPane->Show(m_parentDialog,
                     screenOffset.x + m_bounds.right - m_bounds.left - 1,
                     screenOffset.y,
                     m_selectedIndex);
    return true;
}

// UID:0003LM | by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md | Completion:90 | Confidence:94
int PopupMenuControlPane::GetControlType()
{
    return 12;
}

// UID:0001BK | by-memory/0x00516290-0x00517441.MenuPaneAndItems.md | Completion:88 | Confidence:90
// [UID:0001BK] MenuPane/MenuItem aggregate range.
// Do not emit a standalone aggregate body; exact child methods, class declarations, and type pages provide the source coverage.
[[No Children Attached]]

// UID:000377 | by-memory\0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:000378 | by-memory\0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:000379 | by-memory\0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003C5 | by-memory\0x0061eb0c-0x0061eb94.MenuPaneVtableData.md | Completion:87 | Confidence:91 | Empty Emitter Marker
