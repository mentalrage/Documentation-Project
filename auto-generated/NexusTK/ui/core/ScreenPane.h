// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NB
// Source by-file doc: by-file/ScreenPane.md
// UID:0000CB | by-class/ScreenPane.md | Completion:93 | Confidence:94
#pragma once

#include "FrameMgr.h"
#include "Pane.h"
#include "../../util/Singleton.h"

#include <windows.h>
#include <ddraw.h>

class FunctionObject0;
class Layer;
class List;
class LObject;
class NotificationBlock;
class Region;

class ScreenPane : public Pane,
                   public FrameHandler,
                   public Singleton<ScreenPane> {
public:
    enum CursorIndex
    {
        kCursorNormal = 7,
        kCursorSelect = 8,
        kCursorView = 9,
        kCursorPut = 10,
        kCursorAttack = 11
    };

    ScreenPane(short screenWidth, short screenHeight, short screenBitDepth);
    virtual ~ScreenPane();

    void SetLayerFrame(Layer *layer, const Layer *beforeLayer);
    void DetachLayerFrame(Layer *layer);

    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual unsigned char HandleBrowserNotification(const NotificationBlock *block);
    virtual void OnFrameUpdate(const FrameUpdateContext *context);

    void MarkDirtyRegion(const RectBounds *bounds);
    void StartPresentation();
    void SetActiveCursor(signed char cursorIndex, int force);
    void ShowCursor();
    void HideCursor();
    short GetScreenWidth() const;
    short GetScreenHeight() const;
    void PrepareDirectDrawPresentation();
    void RestoreDirectDrawState();
    void SaveScreenshotJPG();
    void SaveScreenshotBMP();
    void SaveScreenshotPNG();
    void EnablePresentationMode();
    void DisablePresentationMode();
    void LoadCursorResources();
    void LoadCursorResourceSlot(unsigned int cursorIndex,
                                const wchar_t *animatedCursorPath,
                                const wchar_t *staticCursorPath);
    int QueueFadeInCallback(LObject *callbackObject);
    int QueueFadeOutCallback(LObject *callbackObject);
    void BeginFadeIn(FunctionObject0 *completionCallback);
    void BeginFadeOut(FunctionObject0 *completionCallback);
    void SetFadeTransitionState(unsigned char state);
    bool IsFadeTransitionActive() const;
    void RestoreLostSurfaces();
    void TraversePresentationList(Region *dirtyRegion);
    void RenderPresentation();

private:
    int FindLayerIndex(const Layer *layer) const;
    void BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE sourceSurface,
                              RECT *sourceRect);

    LPDIRECTDRAWSURFACE m_primarySurfaceCreateResult;
    LPDIRECTDRAWSURFACE m_primarySurface;
    LPDIRECTDRAWSURFACE m_offscreenSurface;
    LPDIRECTDRAWSURFACE m_renderSurface;
    List *m_rootLayerList;
    bool m_restoreCooperativeLevelPending;
    bool m_restoreDisplayModePending;
    short m_screenWidth;
    short m_screenHeight;
    short m_screenBitDepth;
    bool m_hasPendingDirtyRegion;
    RectBounds m_pendingDirtyRegion;
    bool m_presentationModeEnabled;
    __declspec(align(4)) unsigned char m_presentationStateStorage[0x420];
    HCURSOR m_cursorHandles[12];
    short m_activeCursorIndex;
    unsigned char m_cursorStateStorage[0x16];
    short m_fadeCurrentValue;
    short m_fadePreviousValue;
    bool m_presentationDirty;
    short m_presentationJitterX;
    short m_presentationJitterY;
    int m_fadeTransitionState;
    FunctionObject0 *m_fadeCompletionCallback;
    int m_fadeStep;
    bool m_forceFullRedraw;
    bool m_browserNotificationPending;
    bool m_pointerInputActive;
};

extern ScreenPane *g_pScreenPane;

[[No Children Attached]]
