// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NB
// Source by-file doc: by-file/ScreenPane.md
// UID:0000CB | by-class/ScreenPane.md | Completion:93 | Confidence:94
#include "ScreenPane.h"
#include "../../util/FunctionObjects.h"

void ScreenPane::SetLayerFrame(Layer *layer, const Layer *beforeLayer)
{
    int layerIndex;
    if (beforeLayer != 0)
        layerIndex = FindLayerIndex(beforeLayer);
    else
        layerIndex = m_rootLayerList->GetCount();

    m_rootLayerList->InsertAt(layerIndex, 1, &layer);
}

void ScreenPane::DetachLayerFrame(Layer *layer)
{
    m_rootLayerList->RemoveAt(FindLayerIndex(layer), 1);
}

void ScreenPane::OnFrameUpdate(const FrameUpdateContext *context)
{
    if (m_fadeTransitionState == 2) {
        if (!context->dispatching || m_fadeStep == 0)
            RenderPresentation();
        if (--m_fadeStep >= 0) {
            ScheduleFrameCallback(1);
            return;
        }
    } else {
        if (m_fadeTransitionState != 3)
            return;
        if (!context->dispatching || m_fadeStep == 24)
            RenderPresentation();
        if (++m_fadeStep <= 24) {
            ScheduleFrameCallback(1);
            return;
        }
    }

    if (m_fadeCompletionCallback != 0) {
        m_fadeCompletionCallback->Invoke();
        delete m_fadeCompletionCallback;
        m_fadeCompletionCallback = 0;
    }

    const bool showCursor = m_fadePreviousValue != 0;
    m_fadeTransitionState = 1;
    if (showCursor)
        ::ShowCursor(TRUE);
}

// UID:0004RR | by-memory/0x00557380-0x005573a0.ScreenPaneMarkDirtyRegion.md | Completion:93 | Confidence:94
void ScreenPane::MarkDirtyRegion(const RectBounds *bounds)
{
    m_hasPendingDirtyRegion = true;
    UnionRects(&m_pendingDirtyRegion, bounds, &m_pendingDirtyRegion);
}

// UID:0004RS | by-memory/0x005573b0-0x005573e2.ScreenPaneStartPresentation.md | Completion:92 | Confidence:93
void ScreenPane::StartPresentation()
{
    RenderPresentation();
    TimerHandler::ScheduleTimer(0, 1, 0, 0);
    TimerHandler::ScheduleTimer(1, 500, 0, 0);
}

// UID:0004RT | by-memory/0x005573f0-0x0055742b.ScreenPaneSetActiveCursor.md | Completion:93 | Confidence:94
void ScreenPane::SetActiveCursor(signed char cursorIndex, int force)
{
    if (cursorIndex == m_activeCursorIndex && force == 0)
        return;

    m_activeCursorIndex = cursorIndex;
    ::SetCursor(m_cursorHandles[cursorIndex]);
    ::ShowCursor(TRUE);
}

// UID:0004RU | by-memory/0x00557430-0x00557438.ScreenPaneShowCursor.md | Completion:93 | Confidence:94
void ScreenPane::ShowCursor()
{
    ::ShowCursor(TRUE);
}

// UID:0004RV | by-memory/0x00557440-0x00557448.ScreenPaneHideCursor.md | Completion:93 | Confidence:94
void ScreenPane::HideCursor()
{
    ::ShowCursor(FALSE);
}

// UID:0004S0 | by-memory/0x00557450-0x00557457.ScreenPaneGetScreenWidth.md | Completion:93 | Confidence:94
short ScreenPane::GetScreenWidth() const
{
    return m_screenWidth;
}

// UID:0004S2 | by-memory/0x00557460-0x00557467.ScreenPaneGetScreenHeight.md | Completion:93 | Confidence:94
short ScreenPane::GetScreenHeight() const
{
    return m_screenHeight;
}

// UID:0004W7 | by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md | Completion:92 | Confidence:94
extern unsigned char **g_surfaceColorLookup5Bit;
extern unsigned char **g_surfaceColorLookup6Bit;

ScreenPane::~ScreenPane()
{
    if (g_surfaceColorLookup5Bit != 0) {
        for (int index = 0; index < 256; ++index) {
            if (g_surfaceColorLookup5Bit[index] != 0)
                free(g_surfaceColorLookup5Bit[index]);
        }
        free(g_surfaceColorLookup5Bit);
    }

    if (g_surfaceColorLookup6Bit != 0) {
        for (int index = 0; index < 256; ++index) {
            if (g_surfaceColorLookup6Bit[index] != 0)
                free(g_surfaceColorLookup6Bit[index]);
        }
        free(g_surfaceColorLookup6Bit);
    }

    if (g_pDirectX != 0) {
        if (m_renderSurface != 0) {
            m_renderSurface->Release();
            m_renderSurface = 0;
        }

        if (m_grafPort.m_surface != 0) {
            m_grafPort.m_surface->Release();
            m_grafPort.m_surface = 0;
        }

        if (m_primarySurface != 0) {
            m_primarySurface->Release();
            m_primarySurface = 0;
        }
    }

    if (g_pDirectX != 0) {
        LPDIRECTDRAW directDraw = g_pDirectX->m_pDirectDraw;

        if (m_restoreDisplayModePending && ApplicationActiveGate == 0) {
            HRESULT result = directDraw->RestoreDisplayMode();
            if (FAILED(result))
                throw new DDError(result);

            m_restoreDisplayModePending = false;
        }

        if (m_restoreCooperativeLevelPending) {
            HRESULT result = directDraw->SetCooperativeLevel(
                g_pApplication->GetMainWindowHandle(),
                DDSCL_NORMAL);

            if (FAILED(result)) {
                wchar_t formattedError[0x50];
                DDError *errorText = new DDError(result);
                errorText->FormatErrorMessage(formattedError, 0x50);
                throw new DDError(result);
            }

            m_restoreCooperativeLevelPending = false;
        }
    }

    delete m_rootLayerList;
    m_rootLayerList = 0;

    delete m_fadeCompletionCallback;
    m_fadeCompletionCallback = 0;
}

// UID:0002VO | by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md | Completion:88 | Confidence:90
unsigned char ScreenPane::HandleBrowserNotification(const NotificationBlock *block)
{
    if (block->channel != kBrowserNotificationChannel)
        return 0;

    browser::Notification *notification =
        static_cast<browser::Notification *>(block->payload);

    switch (notification->m_state)
    {
    case kBrowserNotificationBrowserShown:
        m_browserNotificationPending = true;
        return 1;

    case kBrowserNotificationOpenUrl:
        m_browserNotificationPending = false;

        if (g_pBrowserDialogOld != NULL)
            g_pBrowserDialogOld->Close(1);

        if (!notification->m_text.empty())
        {
            new AlertPane(notification->m_text.c_str(),
                          g_pBackPane,
                          kDialogOkButtonText,
                          NULL);
        }
        return 1;

    default:
        // The original binary returns the high byte of the incoming block
        // pointer for unproduced notification states. Preserve that edge.
        return static_cast<unsigned char>(
            (reinterpret_cast<unsigned int>(block) >> 24) & 0xff);
    }
}


// UID:00039Q | by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md | Completion:88 | Confidence:90
void ScreenPane::PrepareDirectDrawPresentation()
{
    if (g_pDirectX == NULL)
        return;

    LPDIRECTDRAW directDraw = g_pDirectX->m_pDirectDraw;

    if (!m_restoreCooperativeLevelPending) {
        DWORD cooperativeFlags = ApplicationActiveGate
            ? DDSCL_NORMAL
            : (DDSCL_FULLSCREEN | DDSCL_ALLOWREBOOT | DDSCL_EXCLUSIVE);

        HRESULT hr = directDraw->SetCooperativeLevel(
            g_pApplication->GetMainWindowHandle(),
            cooperativeFlags);
        if (FAILED(hr))
            throw new DDError(hr);

        m_restoreCooperativeLevelPending = true;
    }

    if (!m_restoreDisplayModePending) {
        if (ApplicationActiveGate == 0) {
            RECT desktopRect;
            GetWindowRect(GetDesktopWindow(), &desktopRect);

            HRESULT hr = directDraw->SetDisplayMode(
                m_screenWidth,
                m_screenHeight,
                m_screenBitDepth);
            if (FAILED(hr))
                throw new DDError(hr);
        }

        m_restoreDisplayModePending = true;
    }

    if (m_primarySurface != NULL) {
        RECT fillRect;
        fillRect.left = 0;
        fillRect.top = 0;
        fillRect.right = m_screenWidth;
        fillRect.bottom = m_screenHeight;

        DDBLTFX bltFx;
        memset(&bltFx, 0, sizeof(bltFx));
        bltFx.dwSize = sizeof(bltFx);
        bltFx.dwFillColor = 0;

        if (ApplicationActiveGate) {
            OffsetRect(
                &fillRect,
                g_pApplication->m_windowOffsetX,
                g_pApplication->m_windowOffsetY);
        }

        HRESULT hr = m_primarySurface->Blt(
            &fillRect,
            NULL,
            NULL,
            DDBLT_COLORFILL,
            &bltFx);

        if (hr == DDERR_SURFACELOST) {
            m_primarySurface->Restore();
            m_primarySurface->Blt(
                &fillRect,
                NULL,
                NULL,
                DDBLT_COLORFILL,
                &bltFx);
        }
    }
}

// UID:00039R | by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md | Completion:88 | Confidence:91
void ScreenPane::RestoreDirectDrawState()
{
    if (g_pDirectX == NULL)
        return;

    LPDIRECTDRAW directDraw = g_pDirectX->m_pDirectDraw;

    if (m_restoreDisplayModePending && ApplicationActiveGate == 0) {
        HRESULT hr = directDraw->RestoreDisplayMode();
        if (FAILED(hr))
            throw new DDError(hr);

        m_restoreDisplayModePending = false;
    }

    if (m_restoreCooperativeLevelPending) {
        HRESULT hr = directDraw->SetCooperativeLevel(
            g_pApplication->GetMainWindowHandle(),
            DDSCL_NORMAL);

        if (FAILED(hr)) {
            wchar_t formattedError[0x50];
            DDError *errorText = new DDError(hr);
            errorText->FormatErrorMessage(formattedError, 0x50);
            throw new DDError(hr);
        }

        m_restoreCooperativeLevelPending = false;
    }
}


// UID:00039X | by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md | Completion:90 | Confidence:91
static const unsigned int kScreenCursorNormal = 7;
static const unsigned int kScreenCursorSelect = 8;
static const unsigned int kScreenCursorView = 9;
static const unsigned int kScreenCursorPut = 10;
static const unsigned int kScreenCursorAttack = 11;
static const unsigned int kScreenCursorMax = 11;

void ScreenPane::LoadCursorResources()
{
    HCURSOR cursor;

    cursor = LoadCursorFromFileW(L"Cursor\\normal.ani");
    m_cursorHandles[kScreenCursorNormal] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\normal.cur");
        m_cursorHandles[kScreenCursorNormal] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorNormal] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\select.ani");
    m_cursorHandles[kScreenCursorSelect] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\select.cur");
        m_cursorHandles[kScreenCursorSelect] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorSelect] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\view.ani");
    m_cursorHandles[kScreenCursorView] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\view.cur");
        m_cursorHandles[kScreenCursorView] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorView] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\put.ani");
    m_cursorHandles[kScreenCursorPut] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\put.cur");
        m_cursorHandles[kScreenCursorPut] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorPut] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\attack.ani");
    m_cursorHandles[kScreenCursorAttack] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\attack.cur");
        m_cursorHandles[kScreenCursorAttack] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorAttack] = LoadCursorW(NULL, IDC_ARROW);
    }
}

void ScreenPane::LoadCursorResourceSlot(unsigned int cursorIndex,
                                        const wchar_t *animatedCursorPath,
                                        const wchar_t *staticCursorPath)
{
    if (cursorIndex > kScreenCursorMax)
        return;

    if (animatedCursorPath == NULL)
        return;

    HCURSOR cursor = LoadCursorFromFileW(animatedCursorPath);
    m_cursorHandles[cursorIndex] = cursor;
    if (cursor != NULL)
        return;

    if (staticCursorPath == NULL)
        return;

    cursor = LoadCursorFromFileW(staticCursorPath);
    m_cursorHandles[cursorIndex] = cursor;
    if (cursor != NULL)
        return;

    m_cursorHandles[cursorIndex] = LoadCursorW(NULL, IDC_ARROW);
}

// UID:00039Y | by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md | Completion:88 | Confidence:90
namespace {
const int kScreenPaneFadeInEvent = 0x4664496e;  // FdIn
const int kScreenPaneFadeOutEvent = 0x46644f74; // FdOt
}

int ScreenPane::QueueFadeInCallback(LObject *callbackObject)
{
    m_fadeTransitionState = 0;
    return TimerHandler::ScheduleTimer(kScreenPaneFadeInEvent, 0, callbackObject, 0);
}

int ScreenPane::QueueFadeOutCallback(LObject *callbackObject)
{
    m_fadeTransitionState = 0;
    return TimerHandler::ScheduleTimer(kScreenPaneFadeOutEvent, 0, callbackObject, 0);
}

void ScreenPane::SetFadeTransitionState(unsigned char state)
{
    m_fadeTransitionState = state;
}

bool ScreenPane::IsFadeTransitionActive() const
{
    return m_fadeTransitionState != 0;
}

// UID:00039Z | by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md | Completion:88 | Confidence:91
namespace {
const int kRestoreLostSurfaceMaxAttempts = 10000;

bool RestoreSurfaceWithRetry(IDirectDrawSurface *surface)
{
    if (surface == 0)
        return true;

    if (surface->IsLost() >= 0)
        return true;

    for (int attempt = 0; attempt < kRestoreLostSurfaceMaxAttempts; ++attempt) {
        if (surface->Restore() >= 0)
            return true;
    }

    return false;
}
}

void ScreenPane::RestoreLostSurfaces()
{
    if (m_grafPort.m_surface != 0 &&
        m_grafPort.m_surface->IsLost() == DDERR_SURFACELOST) {
        m_grafPort.m_surface->Restore();
    }

    if (!RestoreSurfaceWithRetry(m_primarySurface))
        return;

    RestoreSurfaceWithRetry(m_renderSurface);
}

// UID:0003A0 | by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md | Completion:93 | Confidence:93
namespace {
enum FadeTransitionState
{
    kFadeTransitionPreparing = 1,
    kFadeTransitionIn = 2,
    kFadeTransitionOut = 3
};

const int kFadeBlackStep = 24;
}

void ScreenPane::BeginFadeIn(FunctionObject0 *completionCallback)
{
    m_fadePreviousValue = m_fadeCurrentValue;
    m_fadeTransitionState = kFadeTransitionPreparing;

    Region dirtyRegion;
    TraversePresentationList(&dirtyRegion);

    m_fadeCompletionCallback = completionCallback;
    m_fadeTransitionState = kFadeTransitionIn;
    m_fadeStep = kFadeBlackStep;
    FrameHandler::ScheduleNextFrame();
}

void ScreenPane::BeginFadeOut(FunctionObject0 *completionCallback)
{
    m_fadePreviousValue = m_fadeCurrentValue;
    m_fadeTransitionState = kFadeTransitionPreparing;

    Region dirtyRegion;
    TraversePresentationList(&dirtyRegion);

    m_fadeCompletionCallback = completionCallback;
    m_fadeTransitionState = kFadeTransitionOut;
    m_fadeStep = 0;
    FrameHandler::ScheduleNextFrame();
}

// UID:0003A1 | by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md | Completion:90 | Confidence:92
int ScreenPane::FindLayerIndex(const Layer *layer) const
{
    const int layerCount = m_rootLayerList->GetCount();
    for (int index = 0; index < layerCount; ++index) {
        Layer *entry = *static_cast<Layer **>(
            m_rootLayerList->GetElementAt(index));
        if (entry == layer)
            return index;
    }

    return -1;
}

// UID:0003A4 | by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md | Completion:93 | Confidence:94
void ScreenPane::BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE sourceSurface,
                                      RECT *sourceRect)
{
    RECT destinationRect = *sourceRect;

    if (g_isWindowedDisplayMode != 0) {
        if (g_surfaceUses32BitPresentation) {
            DDSURFACEDESC sourceDescription;
            memset(&sourceDescription, 0, sizeof(sourceDescription));
            sourceDescription.dwSize = sizeof(sourceDescription);

            if (sourceSurface->Lock(NULL,
                                    &sourceDescription,
                                    DDLOCK_WAIT,
                                    NULL) == DD_OK) {
                DDSURFACEDESC destinationDescription;
                memset(&destinationDescription, 0, sizeof(destinationDescription));
                destinationDescription.dwSize = sizeof(destinationDescription);

                if (m_offscreenSurface->Lock(NULL,
                                             &destinationDescription,
                                             DDLOCK_WAIT,
                                             NULL) == DD_OK) {
                    WORD *sourcePixels =
                        static_cast<WORD *>(sourceDescription.lpSurface);
                    DWORD *destinationPixels =
                        static_cast<DWORD *>(destinationDescription.lpSurface);
                    const int sourcePitch = sourceDescription.lPitch / sizeof(WORD);
                    const int destinationPitch =
                        destinationDescription.lPitch / sizeof(DWORD);

                    for (unsigned short y = 0;
                         y < sourceDescription.dwHeight;
                         ++y) {
                        for (unsigned short x = 0;
                             x < sourceDescription.dwWidth;
                             ++x) {
                            const WORD pixel = sourcePixels[y * sourcePitch + x];
                            destinationPixels[y * destinationPitch + x] =
                                ((pixel & 0xf800) << 8) |
                                ((pixel & 0x07e0) << 5) |
                                ((pixel & 0x001f) << 3);
                        }
                    }

                    m_offscreenSurface->Unlock(destinationDescription.lpSurface);
                }

                sourceSurface->Unlock(sourceDescription.lpSurface);
            }

            const int windowTop = g_pApplication->m_windowTop;
            const int windowLeft = g_pApplication->m_windowLeft;
            const int windowHeight = g_pApplication->m_windowHeight;
            const int windowWidth = g_pApplication->m_windowWidth;

            if (g_displayStartupDrawType == 1) {
                RECT windowRect = {
                    windowLeft,
                    windowTop,
                    windowLeft + windowWidth,
                    windowTop + windowHeight
                };
                RECT fullSurfaceRect = { 0, 0, g_screenWidth, g_screenHeight };

                HRESULT result = m_primarySurface->Blt(&windowRect,
                                                       m_offscreenSurface,
                                                       &fullSurfaceRect,
                                                       DDBLT_WAIT,
                                                       NULL);
                if (result == DDERR_SURFACELOST) {
                    m_primarySurface->Restore();
                    m_primarySurface->Blt(&windowRect,
                                          m_offscreenSurface,
                                          &fullSurfaceRect,
                                          DDBLT_WAIT,
                                          NULL);
                }
                return;
            }

            HDC sourceDC;
            HDC destinationDC;
            sourceSurface->GetDC(&sourceDC);
            m_primarySurface->GetDC(&destinationDC);

            if (windowWidth == g_screenWidth &&
                windowHeight == g_screenHeight) {
                BitBlt(destinationDC,
                       windowLeft,
                       windowTop,
                       g_screenWidth,
                       g_screenHeight,
                       sourceDC,
                       0,
                       0,
                       SRCCOPY);
            } else {
                SetStretchBltMode(destinationDC,
                                  g_displayStartupDrawType == 2
                                      ? COLORONCOLOR
                                      : HALFTONE);
                StretchBlt(destinationDC,
                           windowLeft,
                           windowTop,
                           windowWidth,
                           windowHeight,
                           sourceDC,
                           0,
                           0,
                           g_screenWidth,
                           g_screenHeight,
                           SRCCOPY);
            }

            sourceSurface->ReleaseDC(sourceDC);
            m_primarySurface->ReleaseDC(destinationDC);
            return;
        }

        m_primarySurface->Blt(&destinationRect,
                              sourceSurface,
                              sourceRect,
                              DDBLT_WAIT,
                              NULL);
        return;
    }

    HRESULT result = m_primarySurface->BltFast(sourceRect->left,
                                               sourceRect->top,
                                               sourceSurface,
                                               sourceRect,
                                               DDBLTFAST_WAIT);
    if (result == DDERR_SURFACELOST) {
        m_primarySurface->Restore();
        m_primarySurface->BltFast(sourceRect->left,
                                  sourceRect->top,
                                  sourceSurface,
                                  sourceRect,
                                  DDBLTFAST_WAIT);
    }
}

// UID:0000S7 | by-global/g_pScreenPane.md | Completion:92 | Confidence:94
class ScreenPane;
ScreenPane *g_pScreenPane = 0;

// UID:00039S | by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md | Completion:88 | Confidence:91
void ScreenPane::EnablePresentationMode()
{
    m_presentationModeEnabled = true;
}

void ScreenPane::DisablePresentationMode()
{
    m_presentationModeEnabled = false;
}

// UID:0003A2 | by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md | Completion:88 | Confidence:88
static void RefreshVisibleTilesForPaletteChange()
{
    PaletteLib *paletteLib = g_pPaletteLib;
    if (paletteLib == NULL)
        return;

    paletteLib->SetScreenPaletteMode(1);
    paletteLib->ResetScreenPaletteSlots();

    MapPane *mapPane = g_activeMapPane;
    if (mapPane != NULL && mapPane->IsAttachedToLayer()) {
        mapPane->RedrawVisibleTiles();
        mapPane->InvalidateRect(NULL);
    }

    if (g_pGeneralPurposePanel != NULL)
        g_pGeneralPurposePanel->DispatchActiveChildRefresh();

    paletteLib->SetScreenPaletteMode(0);
}

// UID:0003A3 | by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md | Completion:90 | Confidence:92
void ScreenPane::TraversePresentationList(Region *dirtyRegion)
{
    Region layerDirty;
    Region currentMotion;

    GetCurrentMotionRegion(&currentMotion);
    SubtractMotionFromDirtyRegion(&currentMotion);

    const int layerCount = m_rootLayerList->GetCount();
    const int lastLayer = layerCount - 1;

    for (int index = lastLayer; index >= 0; --index) {
        Layer *layer = *static_cast<Layer **>(
            m_rootLayerList->GetElementAt(index));
        layer->ClearDirtyRegion();
        layer->CollectDirtyRegion(&layerDirty, &currentMotion);
        dirtyRegion->UnionWith(layerDirty);
    }

    void *savedSurface = m_grafPort.m_surface;
    m_grafPort.m_surface = m_renderSurface;

    Point origin;
    InitPointPair(&origin, 0, 0);

    for (int index = 0; index < layerCount; ++index) {
        Layer *layer = *static_cast<Layer **>(
            m_rootLayerList->GetElementAt(index));

        if (index < lastLayer) {
            Layer *nextLayer = *static_cast<Layer **>(
                m_rootLayerList->GetElementAt(index + 1));
            layer->CopyDirtyRegion(&layerDirty);
            nextLayer->UnionDirtyRegion(&layerDirty);
        }

        layer->PropagateDirtyRegion();
        if (layer->RenderRecursive(
                &m_grafPort, origin.x, origin.y, &layerDirty, NULL)) {
            m_presentationDirty = true;
        }
        layer->EndRender();
    }

    m_grafPort.m_surface = savedSurface;

    if (m_hasPendingDirtyRegion) {
        m_presentationDirty = true;
        dirtyRegion->UnionWithRect(&m_pendingDirtyRegion);
        m_hasPendingDirtyRegion = false;
        InitRectBounds(&m_pendingDirtyRegion, 0, 0, 0, 0);
    }
}

// UID:00039P | by-memory\0x00557140-0x00557377.SurfaceRenderPresentation.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:00039U | by-memory\0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md | Completion:86 | Confidence:88 | Empty Emitter Marker
