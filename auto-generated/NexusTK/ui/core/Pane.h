// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MC
// Source by-file doc: by-file/Pane.md
// UID:0000A2 | by-class/Pane.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_UI_CORE_PANE_H
#define NEXUSTK_UI_CORE_PANE_H

#include "../../render/GrafPort.h"
#include "../../util/TimerHandler.h"
#include "EventHandler.h"
#include "RectBounds.h"
#include "Region.h"

class Layer;
class Message;
struct RuntimeClass;

class Pane : public GrafPort, public EventHandler, public TimerHandler
{
public:
    explicit Pane(unsigned char mode);
    virtual ~Pane();
    virtual void OnChangeMessage(LObject *owner, Message *message);
    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void DrawOnTarget(GrafPort *target, const RectBounds *bounds,
                              const RectBounds *clipBounds);
    virtual void Show();
    virtual void Hide();
    virtual Pane *GetParentPane();
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void GetDescription(int descriptionId, wchar_t *description);
    virtual RectBounds *GetScreenBounds(RectBounds *outBounds) const;
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *previousBounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void InsertInLayer(RectBounds *bounds, int order,
                               Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void SetPaneOrder(Pane *beforePane, Pane *afterPane);
    virtual void UnregisterEventHandler();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool HandleType19Event(Event *event);
    virtual void GetLocalOffset(Point *offset);
    virtual void GetScreenOffset(Point *offset);
    virtual bool ShouldAcceptEvent() const;
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void SetMode(unsigned char mode);
    bool IsAttachedToLayer() const;
    void SetFocusRegistration(bool active);
    void MarkForDeletion();
    void NotifyPaneMessageHandled(bool handled);

protected:
    void CaptureMouse();
    void ReleaseMouseCapture();

    Layer *m_layer;
    Point m_origin;
    bool m_visible;
    unsigned char m_mode;
    Pane *m_redrawPeerPane;
    unsigned int m_redrawState;
    bool m_redrawPending;
    Region m_pendingMotionRegion;
    bool m_inMotionPaint;
    Region m_motionRegion;
    unsigned int m_inputRegistrationState;
    bool m_pendingDelete;
    bool m_hasPendingMotionRegion;
    bool m_drawOnTarget;
};

typedef char PaneSizeMustBe248[sizeof(Pane) == 0xf8 ? 1 : -1];

#endif
