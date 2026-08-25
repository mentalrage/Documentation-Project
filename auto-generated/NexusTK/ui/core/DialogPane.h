// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IT
// Source by-file doc: by-file/DialogPane.md
// UID:00003T | by-class/DialogPane.md | Completion:93 | Confidence:96
#pragma once

#include "../../render/EPFTileContext.h"
#include "Pane.h"

class ControlPane;
class Event;
class Layer;
class List;

class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    int FindControlIndex(const ControlPane *control) const;
    void SetSelectionVisualState(int controlId, unsigned char state);
    void CloseDialog();

protected:
    void StoreClampRect(const RectBounds *bounds);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, short frameIndex);
    void AddControl(ControlPane *control);
    void RemoveControl(ControlPane *control);
    void RemoveControl(int controlIndex);
    int GetControlCount() const;
    ControlPane *GetChildControl(int controlIndex) const;

    template <class T>
    T *GetChild(int controlIndex) const
    {
        return static_cast<T *>(GetChildControl(controlIndex));
    }

    virtual void DrawBackground();
    virtual void DrawBorder();
    char HitTestControls(int mouseY, int mouseX, int *outControlId);
    void DispatchInputToControl(Event *event, int controlId);
    void SavePosition(const RectBounds *unusedBounds);
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    virtual void SetHoverControl(int controlId);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RefreshActionButtonState();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    List *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginY;
    int m_dragOriginX;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinX;
    int m_dragClampMinY;
    int m_dragClampMaxX;
    int m_dragClampMaxY;
    EPFTileContext m_backgroundTileContext;
    int m_backgroundImageWidth;
    bool m_hasCustomBackground;
};

[[No Children Attached]]

// UID:0000PQ | by-global/g_activeDialogCount.md | Completion:86 | Confidence:88
extern signed char g_activeDialogCount;
