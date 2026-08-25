// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MN
// Source by-file doc: by-file/PopupMenuControls.md
// UID:0001V5 | by-type/by-struct/MenuItemLayouts.md | Completion:92 | Confidence:94
#pragma once

#include <errno.h>
#include <stddef.h>

#include "../../util/LObject.h"
#include "../core/RectBounds.h"

class GrafPort;

struct MenuItemMetrics
{
    int height;
    int width;
};

struct MenuItemStyleFlags
{
    unsigned short bits;
};

// UID:00007V | by-class/MenuItem.md | Completion:93 | Confidence:94
class MenuItem : public LObject
{
public:
    MenuItem();

    bool IsEnabled() const;
    void SetEnabled(bool enabled);
    bool IsSelected() const;
    void SetSelected(bool selected);

    RectBounds *GetBounds(RectBounds *outBounds) const;
    void SetBounds(const RectBounds *bounds);

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const = 0;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const = 0;
    virtual void DrawItem(GrafPort *port) = 0;

protected:
    RectBounds m_bounds;
    bool m_enabled;
    bool m_selected;
};

// UID:0000E8 | by-class/StringMenuItem.md | Completion:92 | Confidence:94
class StringMenuItem : public MenuItem
{
public:
    explicit StringMenuItem(const wchar_t *text);

    errno_t CopyText(wchar_t *destination, size_t sizeInWords) const;

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const;
    virtual void DrawItem(GrafPort *port);

protected:
    wchar_t m_text[0x80];
};

// UID:0000CY | by-class/SeparatorMenuItem.md | Completion:92 | Confidence:94
class SeparatorMenuItem : public MenuItem
{
public:
    SeparatorMenuItem();

    virtual void DrawItem(GrafPort *port);
    virtual MenuItemMetrics GetDefaultDimensions() const;
    virtual MenuItemStyleFlags GetStyleFlags() const;
};

// UID:0000AN | by-class/PopupMenuControlPane.md | Completion:90 | Confidence:92
#include "../core/ControlPane.h"

struct PaneMouseEvent;
struct PaneKeyEvent;
struct RectBounds;
class DialogPane;
class MenuItem;
class MenuPane;

class PopupMenuControlPane : public ControlPane
{
public:
    PopupMenuControlPane(DialogPane *parentDialog, const RectBounds *bounds);
    virtual ~PopupMenuControlPane();

    void AppendItem(MenuItem *item);
    MenuItem *GetItem(int index) const;
    int GetItemCount() const;
    long GetSelectedIndex() const;
    void SetSelectedIndex(long index);

protected:
    virtual void OnDraw();
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnKeyDown(const PaneKeyEvent *event);
    virtual int GetControlType();

private:
    void SelectItemAndNotifyParent(long index);

    MenuPane *m_menuPane;
    long m_selectedIndex;
    DialogPane *m_parentDialog;
};
