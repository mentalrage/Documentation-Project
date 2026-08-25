*** UID:0000CB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenPane

## 2026-08-18 ObjectImage Presentation Consumer

- ObjectImageButtonPane::HandleKeyOrTextEvent calls g_pScreenPane->RenderPresentation() exactly twice: once after setting the selected control's visual state to 11 and once after clearing selection with control id -1/state 10.
- The calls bracket Sleep(0x85) before DialogPane command dispatch. They are exact UI presentation dependencies and do not transfer ScreenPane method or singleton ownership to ObjectImage source.

## 2026-08-14 B003 Header Route Closure

- CPP now includes `ScreenPane.h` before children. H is guarded and directly includes complete FrameHandler, Pane, Singleton, Win32, and DirectDraw declarations while preserving the full existing class body and `g_pScreenPane` declaration.
- ChangePasswordDialogPane requires this header for `g_pScreenPane` and ScreenDimmer parent construction. UID0000CB/UID0000NB remain `93/94`; no screen behavior is moved to the dialog unit.

## Status

- Confidence: very strong for class role, direct hierarchy, complete physical layout, singleton lifecycle, exact ordinary destructor route, cursor/presentation state, and accepted method declarations; original private spellings and two provisional storage-member semantic types remain below final-audit certainty.
- Likely source file: [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- Main address range: [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- Rebuild handling: source-authored root screen class with compiler-generated vtables, scalar deleting destructor support, adjustor thunks, EH/runtime glue, and alignment bytes.
- Parent/C++ status: reconstructable and attached to owning [UID:0000NB][ScreenPane](by-file/ScreenPane.md). The H managed block contains the complete C++03 declaration, closes the class before `[[CHILDREN]]`, and declares every accepted qualified method, including exact public `SetLayerFrame(Layer *, const Layer *)` and `DetachLayerFrame(Layer *)`, private const `FindLayerIndex`, private `BlitSurfaceToDisplay`, the three screenshot methods, and retained `BeginFadeIn`/`BeginFadeOut`. The CPP managed block owns the exact Set/Detach definitions before `OnFrameUpdate`; exact child UID0003A1 emits the private lookup body through `[[CHILDREN]]`. The declaration preserves exact physical occupancy through `sizeof(ScreenPane)==0x5b4`.

## Class Purpose

### UID0003A1 root Layer-list contract

- Constructor allocation `List(4,4)` at `m_rootLayerList` / `+0x10c` proves four-byte stored `Layer *` elements. `List::GetElementAt` returns element storage, so UID0003A1 and all three UID0003A3 traversal accesses dereference `Layer **` slots before using the stored pointer.
- `SetLayerFrame` takes a `Layer *` plus optional `const Layer *beforeLayer`: a non-null predecessor is resolved through private `FindLayerIndex`, while null appends at current count; insertion is exactly `InsertAt(index,1,&layer)`.
- `DetachLayerFrame` returns `void` and passes `FindLayerIndex(layer)` directly to `RemoveAt(index,1)` without inventing an index guard. `FindLayerIndex` snapshots count, returns the first matching signed index, and returns `-1` on empty/miss.
- UID0003A1 owns no file-global/static-data island. `m_rootLayerList` remains this class's field and `Layer`/`List` remain external dependency types.

## UID00039P Public Presentation Route

- Function `0x00557140-0x00557377` is the class-owned `ScreenPane::RenderPresentation()`. The receiver is `g_pScreenPane`, current type information is ScreenPane, and the body consumes ScreenPane presentation state and methods.
- The declaration is public because at least 37 code xrefs across 24 named caller functions invoke it after state changes, including UID000312. Keeping it private would make unrelated caller source illegal without unsupported friend declarations.
- The body coordinates callback-table rendering, dirty-region traversal, browser synchronization, final blitting, and window redraw. Surface and DirectDraw are dependencies; they do not own this member.
- The stable by-memory filename `SurfaceRenderPresentation` and earlier Surface ownership are retained as superseded routing history. Current class/file ownership is [UID:0000CB]/[UID:0000NB][ScreenPane](by-file/ScreenPane.md).
- This bounded callback changes only declaration visibility and ownership documentation. The exact function page remains blank pending its dedicated full-body source pass, and ScreenPane scores remain `93/94`.

### UID0002YJ And UID0002YO Fade-Transfer Relation

- `m_fadeStep` is the signed ordinal dword at `+0x5ac`; it is part of the existing proven class layout and is not a newly inserted field.
- [UID:0003A0][0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md) `BeginFadeIn`/`BeginFadeOut` and matching `OnTimer` branches write endpoint values 24 and 0 while setting transition states 2 and 3; historical `HandleMessage` remains an evidence alias only.
- [UID:00039P][0x00557140-0x00557377.SurfaceRenderPresentation](by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md) and [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) pass `m_fadeStep` to Surface semantic slot `g_pfnTransferPixels` with the active mutable 16-bit pixel buffer and total pixel count.
- Compat/RGB555 provider [UID:0002YJ][0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback](by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md) and RGB565 provider [UID:0002YO][0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback](by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md) both clamp the value to `0..24`, preserve full intensity at 0, apply exact ordinal attenuation at 1 through 23, and clear to black at 24. Both process packed pairs plus one odd tail, perform no internal clipping, and leave a zero-count buffer untouched.
- UID0002YO's RGB565 channel-safe masks are `s1=(x>>4)&0x0841`, `s2=(x>>3)&0x18c3`, `s4=(x>>2)&0x39c7`, and `s8=(x>>1)&0x7bcf`. Its 25 results are `x`, `x-s1`, `x+s1-s2`, `x-s2`, `x-s1-s2`, `x+s1-s4`, `x-s4`, `x-s1-s4`, `x-s2-s4`, `x-s1-s2-s4`, `x+s1-2*s4`, `x+s1-s8`, `s1+s8`, `s8`, `s8-s1`, `2*s4-s1`, `s1+s2+s4`, `s2+s4`, `s1+s4`, `s4`, `s4-s1`, `s1+s2`, `s2`, `s1`, and `0`. This relation changes no class ownership, size, member offset, formal declaration order, or provider ownership.

### UID0003A0 retained transition methods

- `BeginFadeIn(FunctionObject0 *completionCallback)` at `[0x00559200,0x005592a9)` and `BeginFadeOut(FunctionObject0 *completionCallback)` at `[0x005592b0,0x00559359)` are complete source-authored ScreenPane methods. Each is `0xa9` bytes, 55 instructions, five basic blocks, one explicit argument, and an automatic `Region` traversal lifetime.
- Both methods snapshot `m_fadeCurrentValue` into `m_fadePreviousValue`, enter preparing state 1, call `TraversePresentationList`, store the typed completion callback, commit direction-specific state/step endpoints, and call `FrameHandler::ScheduleNextFrame()` through the direct base at `+0xf8`.
- Fade-in commits state 2 at black step 24; `OnFrameUpdate` decrements toward visibility. Fade-out commits state 3 at visible step 0; `OnFrameUpdate` increments toward black.
- Both retained starts currently have zero direct callers/xrefs and no VA/RVA pointer-pattern hit. The exact live `OnTimer` `FdIn`/`FdOt` inline duplicates, complete ABI, typed fields, and ordinary Region lifetime establish retained source methods; the negative evidence is a liveness and lexical-confidence cap, not a reason to omit declarations or source.
- UID0003A0 owns both formal definitions. This class H owns only their declarations; no duplicate class-level CPP body is added.

`ScreenPane` is the root full-screen pane and frame/fade controller. It stores screen dimensions, fade state, display/surface handles, an internal list, cursor state, and frame-handler state. It also owns cleanup for shared tile/sprite caches and DirectDraw display-mode restoration.

The root singleton is [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) at `0x0067a7cc`; the exact storage is also documented by [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md). Existing alias documentation also routes historical cursor helper reads through [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md). UID0001G7 reanalysis closes that source-owner question: the alias is the same storage, [UID:00003E][CursorManager](by-class/CursorManager.md) is a non-emitting historical typed view, and all seven exact helpers are ScreenPane methods. UID0001G9 reanalysis likewise proves that JPG/BMP/PNG are ScreenPane methods whose out-of-line definitions live in ScreenshotCapture.cpp; a concrete ScreenshotCapture class and file-local `ScreenPane*` helper fallback are rejected.

[UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md) resolves the startup cursor resource loader as a ScreenPane class method emitted through this class and routed to [UID:0000NB][ScreenPane](by-file/ScreenPane.md), not as a standalone CursorManager source root. B010 MCP session `18aed30a` proves the modeled loader writes cursor table slots 7-11 at `+0x56c/+0x570/+0x574/+0x578/+0x57c`, a retained raw helper writes the same `+0x550` table, and no separate CursorManager lifetime is visible.

[UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) is now class-owned as `ScreenPane::RestoreDirectDrawState()`. It remains inside the mixed [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) address neighborhood, but the accepted MCP-backed owner evidence is ScreenPane-specific: both direct callers pass [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), the body tests and clears bytes `+0x111/+0x110`, the constructor zeros the word at `+0x110` at `0x00556a06`, the destructor repeats the same DirectDraw restore/normal-cooperative cleanup sequence, and [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) sets the paired setup flags at `0x005574e5` and `0x00557537`.

[UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) is likewise class-owned as `ScreenPane::PrepareDirectDrawPresentation()`, not a generic Surface method despite the stale generated name. Current MCP session `31debdf2` proves the exact `__thiscall` body at `0x00557470-0x0055769d`; external callers at `0x00465d13`, `0x00465d1e`, `0x00466a02`, and `0x0055887d` load or already carry [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md); the method sets ScreenPane restore flags `+0x110/+0x111`, reads screen dimensions `+0x112/+0x114/+0x116`, and color-fills the primary/display surface field `+0x100`. It calls `IDirectDraw::SetCooperativeLevel` at vtable slot `+0x50`, `IDirectDraw::SetDisplayMode` at `+0x54`, `IDirectDrawSurface::Blt` at `+0x14`, and `IDirectDrawSurface::Restore` at `+0x6c`; it does not call `IDirectDrawSurface::Flip` at slot `+0x2c`.

[UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) is the private `ScreenPane::BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE, RECT *)` presentation method, not a generic Surface free function. All four direct calls come from the ScreenPane presentation bodies at `0x00557140` and `0x005583a0`; the body consumes `m_primarySurface` at `+0x100`, `m_offscreenSurface` at `+0x104`, inherited GrafPort/render surfaces, and Application window geometry. Its exact paths are exclusive `BltFast`, windowed non-32-bit `Blt`, windowed 32-bit RGB565 expansion followed by DirectDraw `Blt` for DrawType 1, or GDI `BitBlt`/`StretchBlt` with `COLORONCOLOR` for DrawType 2 and `HALFTONE` otherwise. Only `DDERR_SURFACELOST` receives one unchecked restore and one retry; ignored `Lock`, `GetDC`, retry, and release results are deliberate preserved behavior.

[UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) is still emitted through the current [UID:0000OC][Surface](by-file/Surface.md) presentation source bucket, not this class, because no external entry route or family-wide Surface/ScreenPane owner decision is proven. B012 reanalysis confirms the semantic receiver is nevertheless ScreenPane-shaped: `ecx` is the root presentation object, sibling [UID:00039P][0x00557140-0x00557377.SurfaceRenderPresentation](by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md) callers load [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), and the helper mutates ScreenPane presentation fields `+0x59c/+0x59e/+0x5a0/+0x5a4/+0x5ac/+0x5b0`. Treat this as a family-audit caveat, not as a one-off class method row yet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScheduleFrameCallback` | `0x004b6d30-0x004b6d4b` | Schedules a frame callback at current tick plus delay. |
| `ScreenPane::ScreenPane` | `0x00556910-0x00556a5a` | Constructs base `Pane`, installs singleton/vtables, dimensions, root layer list at `+0x10c`, surface/fade defaults. |
| `~ScreenPane` | `0x00556a60-0x00556cd4` | Releases caches, DirectDraw surfaces, display mode/cooperative level, list/extra object, singleton, and base objects. |
| root layer-list helpers | `0x00556ce0-0x00556d41` | Exact `void SetLayerFrame(Layer *layer, const Layer *beforeLayer)` inserts before the optional pointer or appends; exact `void DetachLayerFrame(Layer *layer)` removes at private `FindLayerIndex(layer)` without a guard. UID0003A1 supplies the signed first-match index-or-`-1` lookup over dereferenced List(4,4) `Layer *` slots. Historical integer slot/return and `RemoveLayerFrame` wording is superseded. |
| active MapPane visible-tile repaint call | `0x005051c0-0x00505228` | Caller dependency from `OnTimer` (historically documented as `HandleMessage`)/raw palette bridge into [UID:00007Q][MapPane](by-class/MapPane.md) `RedrawVisibleTiles`; earlier callsite-only `ParcelPane` ownership is false. |
| `OnTimer(int,int,int)` | `0x00556d50-0x00556f61` | Pane-owned TimerHandler callback handling fade in/out and repaint-style screen events; historical `HandleMessage` remains an evidence alias. |
| `HandleBrowserNotification` | `0x00556f70-0x00557070` | [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md) source-ready vtable-referenced handler for `Bros` payloads; raw EventHandler-view displacement `+0x511` normalizes through primary `+0xa0` to `m_browserNotificationPending` at primary `+0x5b1`. |
| `OnFrameUpdate(const FrameUpdateContext *)` | `0x00557070-0x00557132` | Direct FrameHandler callback advancing fade animation and callback/cursor state; dispatcher `0x004b6f60` proves the three-field context record. Historical `OnFrameTick` remains an evidence alias. |
| cursor/screen helpers | [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md) | Non-emitting semantic index over seven exact ScreenPane method children; provisional CursorManager ownership and boolean visibility syntax are superseded. |
| [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md) | `0x00558f70-0x005590da` | `ScreenPane::LoadCursorResources()` plus retained raw `ScreenPane::LoadCursorResourceSlot(...)`; startup caller `0x004f61c9` uses `g_pScreenPane->LoadCursorResources()`. The loader initializes cursor table slots 7-11 as normal/select/view/put/attack from `.ani`, then `.cur`, then `LoadCursorW(NULL, IDC_ARROW)` fallback. Raw helper `0x00559080-0x005590da` has no external xrefs, so it caps confidence but remains source-authored ScreenPane helper code. |
| [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) | `0x00557470-0x0055769d` | `ScreenPane::PrepareDirectDrawPresentation`; returns when `g_pDirectX` is null, sets cooperative level from `ApplicationActiveGate`, sets display mode from `+0x112/+0x114/+0x116` when inactive, marks paired restore flags `+0x110/+0x111`, then color-fills `m_primarySurface` / `+0x100` with `IDirectDrawSurface::Blt(DDBLT_COLORFILL)` and retries once after `DDERR_SURFACELOST` by calling `Restore`. No `Flip` call occurs. |
| [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) | `0x005576a0-0x00557810` | `ScreenPane::RestoreDirectDrawState`; returns when `g_pDirectX` is null, restores `IDirectDraw::RestoreDisplayMode()` from flag `+0x111` only when `ApplicationActiveGate == 0`, restores `IDirectDraw::SetCooperativeLevel(g_pApplication->GetMainWindowHandle(), DDSCL_NORMAL)` from flag `+0x110`, clears flags on success, throws `DDError` on negative HRESULTs, and preserves the `DDError::FormatErrorMessage(formattedError, 0x50)` side call before the second throw on SetCooperativeLevel failure. |
| [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) | `[0x00557840,0x00557a96)` | `ScreenPane::SaveScreenshotJPG`; retained/no-direct-start-route method that temporarily selects `m_renderSurface` through inherited `m_ddSurface`, writes JPEG, posts local capture status under saved/cleared/restored EventMan modifier state, and sends proof through ScreenshotCapture.cpp. |
| [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) | `[0x00557aa0,0x00557e73)` | `ScreenPane::SaveScreenshotBMP`; hotkey-reached method that writes 14/40-byte BMP headers and positive-height bottom-up 16-bit rows, with exact RGB565-to-555 conversion and browser/status/proof side effects. |
| [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md) | `[0x00557e80,0x00558239)` | `ScreenPane::SaveScreenshotPNG`; hotkey-reached method that converts capture bounds to top-down RGBA8, calls stock `lodepng_encode32_file`, posts status, and sends proof. |
| `EnablePresentationMode()` | `0x00557820-0x00557828` | [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md) true setter for inferred byte `m_presentationModeEnabled` / `+0x12c`; called by [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) after loading `g_pScreenPane`. |
| `DisablePresentationMode()` | `0x00557830-0x00557838` | [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md) false setter for inferred byte `m_presentationModeEnabled` / `+0x12c`; called by [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) after compressed map save and before settings save. |
| [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) | `0x005590e0-0x00559108` | Resets `m_fadeTransitionState` / `+0x5a4` and schedules exact event `FdIn` through inherited `TimerHandler::ScheduleTimer`; Pane owns the TimerHandler facet at primary `+0xa4`, so no embedded `m_timerHandler` member exists. |
| [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) | `0x00559110-0x00559138` | Resets `m_fadeTransitionState` / `+0x5a4` and schedules exact event `FdOt` through inherited `TimerHandler::ScheduleTimer`; direct callers are the Application exit and LogoPane advance paths. |
| [UID:0003A0][0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md) `BeginFadeIn(FunctionObject0 *)` | `[0x00559200,0x005592a9)` | Retained ScreenPane setup method with one typed completion callback: automatic Region traversal, direct FrameHandler scheduling, state 2, black step 24, and later decrement toward visibility. Current zero-xref/pointer evidence is retained-liveness uncertainty only. |
| [UID:0003A0][0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md) `BeginFadeOut(FunctionObject0 *)` | `[0x005592b0,0x00559359)` | Symmetric retained setup method: automatic Region traversal, direct FrameHandler scheduling, state 3, visible step 0, and later increment toward black. Current zero-xref/pointer evidence is retained-liveness uncertainty only. |
| [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) | `0x00559140-0x00559151` | Retained raw ScreenPane method that zero-extends a byte argument and stores it as the dword transition state at `+0x5a4`; no direct caller xrefs are currently documented, but exact padding starts at `0x00559151`. |
| [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) | `0x00559160-0x0055916b` | Retained raw ScreenPane predicate that returns whether dword transition state `+0x5a4` is nonzero; no direct caller xrefs are currently documented, and the following `0x0055916b-0x00559170` bytes are padding before `SurfaceRestoreLostSurfaces`. |
| [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) | `0x00559170-0x005591fc` | `ScreenPane::RestoreLostSurfaces`; live `WM_SETFOCUS` path from `Main_WndProc` through [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), restores the inherited GrafPort/backing surface at `+0x18` once on `DDERR_SURFACELOST`, retries `m_primarySurface` / `+0x100` up to `10000` times with early return on failure, and retries `m_renderSurface` / `+0x108` before returning. DirectDraw slots `+0x60` and `+0x6c` are `IDirectDrawSurface::IsLost` and `Restore`. |
| [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) | `0x00559410-0x005595ca` | `ScreenPane::TraversePresentationList(Region *dirtyRegion)`; reverse dirty aggregation and forward render traversal over root layer-list `+0x10c`, temporary inherited `GrafPort +0x18` swap to render surface `+0x108`, presentation-dirty update at `+0x59c`, pending dirty-region consume/reset at `+0x118/+0x11c`, and dirty output for Surface presentation callers. `ScreenLayerEntry` and exact method spelling remain inferred. |
| [UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) | `0x005595d0-0x00559a0f` | Private `ScreenPane::BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE sourceSurface, RECT *sourceRect)`; four ScreenPane callers, fields `+0x100/+0x104`, exact exclusive/windowed/32-bit DirectDraw/GDI branch matrix, RGB565-to-zero-alpha-RGB expansion, Application destination geometry, and one-shot `DDERR_SURFACELOST` restore/retry behavior. |
| ordinary destructor | `0x00556a60-0x00556cd4` | [UID:0004W7][0x00556a60-0x00556cd4.ScreenPaneDestructor](by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md) exact C++03 destructor body and compiler/source boundary. |
| deleting support island | `0x00559b20-0x00559b8b` | [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md) non-emitting Singleton constructor-unwind cleanup, three compiler-generated adjustor thunks, scalar deleting destructor, and padding boundaries. |

[UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) belongs to the ScreenPane source file rather than the ScreenPane class method table. It has no receiver, but it duplicates the palette-refresh branch in `ScreenPane::OnTimer` (historically documented as `ScreenPane::HandleMessage`) and coordinates ScreenPane-side refresh through `g_pPaletteLib`, `g_activeMapPane`, `MapPane::RedrawVisibleTiles()`, the inherited pane refresh/invalidate slot, and `g_pGeneralPurposePanel->DispatchActiveChildRefresh()`. Keep it as file-static `RefreshVisibleTilesForPaletteChange()` unless future caller evidence proves a class receiver.

## Exact Hierarchy And Complete Layout

- RTTI and constructor/destructor vptr stores prove direct source order `Pane`, `FrameHandler`, `Singleton<ScreenPane>`. Pane begins at `+0x000` and contains EventHandler/TimerHandler facets at primary `+0xa0/+0xa4`; direct FrameHandler begins at `+0xf8`; empty Singleton begins at `+0xfc` and overlaps the first derived dword under old-MSVC empty-base optimization.
- The scalar deleting wrapper's bit-4 path embeds exact complete size `0x5b4`. Every downstream field offset below must survive the target 32-bit MSVC ABI; zero Empty Emitter Markers is insufficient if the class layout differs.

| Primary offset | Size/type | Source member or disposition |
| --- | --- | --- |
| `+0x000..+0x0f7` | `Pane` | direct base; EventHandler/TimerHandler facets at `+0xa0/+0xa4`. |
| `+0x0f8..+0x0fb` | `FrameHandler` | direct base. |
| `+0x0fc` | empty `Singleton<ScreenPane>` plus dword | EBO overlaps `m_primarySurfaceCreateResult`. |
| `+0x100/+0x104/+0x108` | surface pointers | `m_primarySurface`, `m_offscreenSurface`, `m_renderSurface`. |
| `+0x10c` | `List *` | `m_rootLayerList`. |
| `+0x110/+0x111` | `bool` | cooperative-level and display-mode restore flags. |
| `+0x112/+0x114/+0x116` | signed `short` | width, height, bit depth. |
| `+0x118` | `bool` | `m_hasPendingDirtyRegion`. |
| `+0x11c..+0x12b` | `RectBounds` | `m_pendingDirtyRegion`. |
| `+0x12c` | `bool` | `m_presentationModeEnabled`. |
| `+0x130..+0x54f` | provisional MSVC-aligned `unsigned char[0x420]` | `m_presentationStateStorage`; `__declspec(align(4))` preserves the proven aggregate alignment after the byte at `+0x12c`; physically mandatory, semantic type not recovered. |
| `+0x550..+0x57f` | `HCURSOR[12]` | `m_cursorHandles`. |
| `+0x580` | signed `short` | `m_activeCursorIndex`. |
| `+0x582..+0x597` | provisional `unsigned char[0x16]` | `m_cursorStateStorage`; physically mandatory, semantic type not recovered. |
| `+0x598/+0x59a` | signed `short` | current/previous fade values. |
| `+0x59c` | `bool` | `m_presentationDirty`. |
| `+0x59e/+0x5a0` | signed `short` | presentation jitter X/Y. |
| `+0x5a4` | `int` | `m_fadeTransitionState`. |
| `+0x5a8` | `FunctionObject0 *` | `m_fadeCompletionCallback`. |
| `+0x5ac` | `int` | `m_fadeStep`. |
| `+0x5b0/+0x5b1/+0x5b2` | `bool` | full redraw, browser notification, pointer input. |
| `+0x5b3` | tail alignment | complete size `0x5b4`. |

### Unidentified Span Reanalysis

- Constructor, destructor, ScreenPane family, and 145 `g_pScreenPane` xref functions contain no read, write, address-take, constructor, destructor, RTTI, allocation, or lifetime operation for either span. Apparent later offsets from secondary receivers normalize to known tail members.
- `DDPIXELFORMAT` (`0x20`) plus `PALETTEENTRY[256]` (`0x400`) equals `0x420`, but ScreenPane has no such receiver access or lifetime; palette behavior routes through global PaletteLib. Arithmetic fit alone cannot justify the types.
- Region/rectangle arrays, cursor descriptors/path matrices, resource tables, hidden bases, and an embedded CursorManager are rejected by missing consumers/lifetime and by current CursorManager alias evidence. The `0x16` span could fit several short/character aggregates, but no element width or role is observed.
- Silent omission is forbidden: omitting the two ranges collapses `0x436` bytes, shifts `m_cursorHandles` and all fade/callback/tail members, and contradicts `sizeof(ScreenPane)==0x5b4`.
- The R3 byte arrays are therefore transparent, last-resort first-draft C++03 storage. The `0x420` member requires target-MSVC `__declspec(align(4))`: without it, a byte array begins at `+0x12d`, contradicting the proven `+0x130` span even though later pointer alignment hides the mistake. They add no unobserved construction/destruction behavior and must be replaced only by evidence-backed types with identical size/alignment.

### Target-ABI Verification Contract

Callback completion requires 32-bit MSVC layout proof for `sizeof(ScreenPane)==0x5b4`, direct bases `+0/+0xf8/+0xfc`, Pane facets `+0xa0/+0xa4`, both storage members `+0x130/0x420` and `+0x582/0x16`, and every table offset above. Because multiple inheritance makes portable `offsetof` unsuitable, use target-compiler class-layout output plus compile-time assertions in a temporary ABI verifier. The verifier must fail if the target-specific alignment annotation is removed.

## Layout Notes

- Root layer list pointer: dword offset `67`, byte offset `+0x10c`, allocated by `ScreenPane::ScreenPane`.
- Inherited GrafPort/backing DirectDraw surface: primary byte offset `+0x18`, source access `m_grafPort.m_surface`. [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) calls `IsLost`/`Restore` on it and [UID:0004W7][0x00556a60-0x00556cd4.ScreenPaneDestructor](by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md) releases it; superseded duplicate-derived `m_grafPortSurface` remains historical only.
- Primary/display DirectDraw surface: byte offset `+0x100`, best current source-facing name `m_primarySurface` with `m_displaySurface` as an acceptable alternate if later naming chooses display vocabulary. [UID:00039W][0x00558840-0x00558f63.SurfaceMinimapRenderInitializer](by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md) creates/copies the primary-surface result into this slot, [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) color-fills it through `IDirectDrawSurface::Blt` and retries after `DDERR_SURFACELOST` by calling `Restore`, [UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) uses it as display destination, and [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) restores it with a bounded retry loop.
- Supporting DirectDraw surface fields near the display slot: `+0xfc` is a temporary/retained primary-surface create result copied to `+0x100`; `+0x104` is `m_offscreenSurface`, the lockable 32-bit conversion destination used by [UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) before DrawType 1 presentation, but it is not directly restored by [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md); `+0x108` is best named `m_renderSurface` or, if later terminology standardizes that way, `m_backBufferSurface`. The constructor/destructor initialize/release `+0x108`, the initializer creates and locks/unlocks it, and UID00039Z restores it after the primary/display surface succeeds.
- DirectDraw cooperative-level restore flag: byte offset `+0x110`, provisional name `m_restoreCooperativeLevelPending` with alternate `m_directDrawCooperativeLevelActive`. MCP-backed lifecycle evidence shows the constructor zeros the word containing `+0x110/+0x111` at `0x00556a06`; [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) sets this byte in the setup side at `0x005574e5`; [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) calls `IDirectDraw::SetCooperativeLevel(g_pApplication->GetMainWindowHandle(), DDSCL_NORMAL)` when it is set and clears it on success; `~ScreenPane` has the duplicate cleanup sequence.
- DirectDraw display-mode restore flag: byte offset `+0x111`, provisional name `m_restoreDisplayModePending` with alternate `m_displayModeChanged`. MCP-backed lifecycle evidence shows [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) sets this byte after display-mode setup at `0x00557537`; [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) calls `IDirectDraw::RestoreDisplayMode()` only when this byte is set and `ApplicationActiveGate == 0`, then clears it on success; `~ScreenPane` repeats the display-mode restore path.
- Screen dimensions: signed short fields at byte offsets `+0x112`, `+0x114`, and `+0x116`; exact ScreenPane accessors UID0004S0/UID0004S2 return the first two, and [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) uses all three for `IDirectDraw::SetDisplayMode` plus the fill rectangle size.

## Screen Cursor Method Island

UID0001G7 is now a non-emitting semantic index. The exact children below are ordinary source-authored methods, all owned/emitted by this class and ordered deterministically in `ScreenPane.cpp`.

| Position | Child | Return/arguments | Exact class role |
| --- | --- | --- | --- |
| 110 | [UID:0004RR][0x00557380-0x005573a0.ScreenPaneMarkDirtyRegion](by-memory/0x00557380-0x005573a0.ScreenPaneMarkDirtyRegion.md) | void; one const RectBounds pointer | sets bool `m_hasPendingDirtyRegion` at `+0x118` and unions into RectBounds `m_pendingDirtyRegion` at `+0x11c` |
| 120 | [UID:0004RS][0x005573b0-0x005573e2.ScreenPaneStartPresentation](by-memory/0x005573b0-0x005573e2.ScreenPaneStartPresentation.md) | void; no explicit arguments | calls RenderPresentation, then schedules inherited TimerHandler IDs 0/1 after 1/500 ms |
| 130 | [UID:0004RT][0x005573f0-0x0055742b.ScreenPaneSetActiveCursor](by-memory/0x005573f0-0x0055742b.ScreenPaneSetActiveCursor.md) | void; signed-char index and int force | compares/stores signed short active index at `+0x580`, selects `HCURSOR m_cursorHandles[12]` at `+0x550`, then calls SetCursor and ShowCursor(TRUE) |
| 140 | [UID:0004RU][0x00557430-0x00557438.ScreenPaneShowCursor](by-memory/0x00557430-0x00557438.ScreenPaneShowCursor.md) | void; no explicit arguments | calls global Win32 ShowCursor(TRUE) |
| 150 | [UID:0004RV][0x00557440-0x00557448.ScreenPaneHideCursor](by-memory/0x00557440-0x00557448.ScreenPaneHideCursor.md) | void; no explicit arguments | calls global Win32 ShowCursor(FALSE) |
| 160 | [UID:0004S0][0x00557450-0x00557457.ScreenPaneGetScreenWidth](by-memory/0x00557450-0x00557457.ScreenPaneGetScreenWidth.md) | signed short; no explicit arguments; read-only | returns `m_screenWidth` at `+0x112`; callers sign-extend AX |
| 170 | [UID:0004S2][0x00557460-0x00557467.ScreenPaneGetScreenHeight](by-memory/0x00557460-0x00557467.ScreenPaneGetScreenHeight.md) | signed short; no explicit arguments; read-only | returns `m_screenHeight` at `+0x114`; callers sign-extend AX |

Class/source declarations must expose these seven names and the exact field types above. The `+0xa4` receiver used by StartPresentation is the inherited `TimerHandler` base view within `Pane`, not an embedded `m_timerHandler` field. Constructor evidence installs the `Pane` and `FrameHandler` relationships and initializes the signed dimension fields; UID00039X fills cursor slots 7-11 in the same ScreenPane object.

Behavioral exclusions are part of the declaration contract: no null check in MarkDirtyRegion, no cursor index/handle check in SetActiveCursor, no boolean argument on either visibility method, no imported API return exposed as a source return, and no handwritten vptr/vtable/thunk/scalar/EH/alignment source. The unresolved names of cursor slots 0-6 do not block the generic 12-element HCURSOR field.

## UID0001G7 Source-Quality Resolution

- Fresh binary evidence identifies seven aligned functions with exact SHA256 values and independent caller sets; their source is emitted only by exact children, not the semantic index.
- ScreenPane ownership is proven by constructor field stores, canonical g_pScreenPane receivers, dirty-state consumer UID0003A3, and cursor-loader UID00039X.
- Historical `RequestPresentAndTimers` is superseded by `StartPresentation`; timer-event rearming proves startup/recurring presentation intent.
- Historical `ShowCursor(true/false)` is ABI-invalid because two separate no-argument functions push their own TRUE/FALSE values.
- Historical CursorManager ownership is superseded; no constructor, destructor, allocator, vtable, storage, or independent singleton lifetime exists.
- The current broad class score is `93/94`: exact method/layout/source contracts are strong, while remaining original private spellings and source-shape inferences cap a perfect score.
- Presentation/gameplay-mode byte: `+0x12c`, best source-facing name `m_presentationModeEnabled`, alternate `m_gamePresentationActive`. [UID:00039W][0x00558840-0x00558f63.SurfaceMinimapRenderInitializer](by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md) clears it at startup at `0x00558c86` after receiving `g_pScreenPane`; [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) enables it through [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md), and [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) disables it during exit-to-menu. Field spelling is inferred, not recovered.
- Pending dirty-region flag: `+0x118`, best source-facing name `m_hasPendingDirtyRegion` / `m_dirtyRegionPending`. [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md) sets it when a dirty rectangle is marked; [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) consumes and clears it after unioning the pending rectangle into frame dirty output.
- Pending dirty rectangle/region: `+0x11c`, best source-facing name `m_pendingDirtyRegion` / `m_pendingDirtyRect`. Screen cursor/dirty helpers accumulate caller rectangles into this state through the shared Rect/Region helper family; `ScreenPane::TraversePresentationList` unions it into the caller `Region` and resets it with `InitRectBounds`.
- Presentation/frame dirty byte: `+0x59c`, best source-facing name `m_presentationDirty` / `m_frameDirty`. [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) ORs recursive render returns into it and forces it when pending dirty state exists; Surface presentation callers use this byte to decide whether dirty blit/redraw work is needed.
- Cursor handle table: word offset `680`, byte offset `+0x550`; used by the active-cursor helper and initialized by [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md). B010 names the target-loaded slots 7-11 as normal/select/view/put/attack from direct resource literals, with writes at `+0x56c/+0x570/+0x574/+0x578/+0x57c`; slots `0-6` remain outside that target and should not be named from this evidence.
- Active cursor index: word offset `704`, byte offset `+0x580`.
- Repaint/timer helper subobject: byte offset `+0xa4`, passed to the timer-wrapper helper at `0x005975e0`.
- Browser-notification pending/state byte: primary `+0x5b1`, best source-facing name `m_browserNotificationPending`; [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md) enters through EventHandler at primary `+0xa0`, so raw receiver displacement `+0x511` resolves to this tail member. Exact spelling remains inferred.
- Deleting-support adjustors subtract `0xa0`, `0xa4`, and `0xf8` before entering the scalar deleting destructor; these offsets are strong evidence of multiple inherited ScreenPane facets, but the final interface names still need a class-layout audit.
- Fade/presentation transition current word: `+0x598`, formal member `short m_fadeCurrentValue`; [UID:0003A0][0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md) copies it into `+0x59a`, and the constructor initializes it.
- Fade/presentation transition saved/previous word: `+0x59a`, formal member `short m_fadePreviousValue`; `OnTimer` and the retained begin methods copy `+0x598` into this slot before traversal. Historical `HandleMessage` is an evidence alias.
- Fade/presentation transition state: dword offset `+0x5a4`, formal member `int m_fadeTransitionState`. [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) clears, sets, and tests this field; `OnTimer` and retained begin methods use enum-like values `0`, `1`, `2`, and `3`; Surface presentation helpers consume it but do not own it.
- Fade completion callback: `+0x5a8`, formal member `FunctionObject0 *m_fadeCompletionCallback`; `OnTimer` stores its timer payload there after the queue helpers pass caller-created callback objects through [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), while UID0003A0 stores its sole typed method argument directly.
- Fade step: `+0x5ac`, formal member `int m_fadeStep`; the `FdIn` branch stores `0x18` / 24, the `FdOt` branch stores `0`, and presentation passes it as the ordinal third argument to `SurfaceTransferPixelsProc g_pfnTransferPixels`. UID0002YJ and UID0002YO define the exact RGB555 and RGB565 endpoint and intermediate behavior for the two selected surface families.

## Source / Compiler Split And Score Rationale

- [UID:0004W7][0x00556a60-0x00556cd4.ScreenPaneDestructor](by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md) is the sole exact ordinary-destructor emitter. [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md) and [UID:0003CI][0x006230e8-0x0062317c.ScreenPaneVtableData](by-memory/0x006230e8-0x0062317c.ScreenPaneVtableData.md) are compiler-only/non-emitting; [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md) is a non-emitting method index. The semantic singleton definition emits once from [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), while physical [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) is non-emitting evidence.
- Constructor-unwind Singleton cleanup, scalar deleting flags/operator delete/size guard, adjustor thunks, vptr writes, raw RTTI/vtables, explicit base calls, EH, cookies, and alignment are compiler consequences and must not appear as hand-authored ScreenPane methods.
- UID0003A1 is ordinary handwritten private class source and emits through `[[CHILDREN]]`; its exact H remains blank because this class owns `int FindLayerIndex(const Layer *layer) const`. UID0001G5 remains a non-emitting index, while this class CPP owns the two public mutation-helper definitions.
- Completion `93` reflects a complete compile-visible class declaration, exact direct hierarchy, full `0x5b4` physical layout, ordinary destructor/source route, accepted methods including all three screenshot declarations, globals, and compiler exclusions. Confidence `94` remains capped by inferred private spellings and the semantic identity of two provisional storage members.
- Historical blank-class reasoning is preserved as superseded: a partial class would have been unsafe, but the complete target-specific pass now closes every accepted method and physically mandatory field. Leaving the formal blank or omitting the two storage spans would be less accurate than the current evidence-backed first draft.

## Cross-References

- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md)
- [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md)
- [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md)
- [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md)
- [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md)
- [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md)
- [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md)
- [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md)
- [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md)
- [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md)
- [UID:0003A0][0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md)
- [UID:0003A1][0x00559360-0x005593a2.ScreenPaneLayerIndexLookup](by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md)
- [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md)
- [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:00003E][CursorManager](by-class/CursorManager.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)

## UID0003CJ Literal-Pool And Class Boundary

[UID:0003CJ][0x0062317c-0x00623480.ScreenPaneResourceStringData](by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md) begins after the final ScreenPane adjusted-vtable slot and ends before the `ScreenDimmer` COL, but it is not class-static ScreenPane data. Live MCP proves a 772-byte mixed compiler pool (SHA256 `F918C4378A7496A181BFD31A980104700DA382E6A44072E5C2186CF886449AC6`) whose 20 referenced heads are partitioned among screenshot/proof code, ScreenPane cursor loading, and Surface helpers.

The class-owned source relationship is limited to [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md), which uses the ten wide paths at `0x00623304-0x0062345c` inline and populates the existing cursor table. The screenshot directory/name/status strings remain literals inside ScreenPane member definitions emitted through ScreenshotCapture.cpp; class ownership of those member functions does not turn the physical pool into class-static members. The proof mask is file-local helper state, while `0x00623460` and `0x00623470` are Surface-use compiler constants.

UID0003CJ is therefore non-emitting with owner none. Do not add class members, static arrays, resource identifiers, raw data, or a covered-by child to the ScreenPane class formal. The class remains `93/94`, and its compiler-only UID0003CI vtable-data exclusion remains separate and unchanged.

## Changes

- 2026-08-25 B006 UID0003A1 accepted implementation callback:
  - Replaced stale integer-slot/`int` helper declarations with exact public pointer/void declarations, added private const `FindLayerIndex`, and inserted exact Set/Detach definitions before `OnFrameUpdate`.
  - Added List(4,4) pointer-slot, first-match/`-1`, null-before append, direct unguarded removal, owner/emitter, and no-target-owned-data contracts while preserving `93/94`, full `0x5b4` layout, source order, and unrelated declarations/history.
  - Added UID0003A1 to class cross-references; UID0003A1 emits its exact body through `[[CHILDREN]]`, and the class H remains the sole declaration owner.
- 2026-08-14 B001 UID0002YO class-support synchronization:
  - Extended the exact `m_fadeStep +0x5ac` relation to source-ready RGB565 provider UID0002YO, including its masks, 25-step progression, packed/odd-tail behavior, zero-count/no-clipping disposition, and 0/full-intensity and 24/black endpoints.
  - Preserved `93/94`, owner/emitter UID0000NB, reconstructable true, binary size `0x5b4`, and the existing class CPP/H without changing layout or declaration order.

- 2026-08-11 B001 UID0003A0 source-quality implementation:
  - Preserved class score `93/94`, owner/emitter metadata, exact direct hierarchy, complete `0x5b4` layout, and blank class CPP channel.
  - Added exact public declarations for `BeginFadeIn(FunctionObject0 *)` and `BeginFadeOut(FunctionObject0 *)`, complete method-inventory rows, ABI/Region/direct-FrameHandler relations, 2/24 versus 3/0 direction contracts, and retained zero-xref liveness evidence.
  - Normalized current transition-field wording to the accepted `m_fadeCurrentValue`, `m_fadePreviousValue`, `m_fadeTransitionState`, `m_fadeCompletionCallback`, and `m_fadeStep` declarations while retaining `HandleMessage` only as a historical alias for `OnTimer`.

- 2026-08-11 B007 UID0002YJ class-support synchronization:
  - Added the exact `m_fadeStep +0x5ac` relation to transition endpoint writes and Surface slot-11 consumption, including UID0002YJ's 0/full-intensity and 24/black endpoint semantics.
  - Preserved `93/94`, owner/emitter UID0000NB, reconstructable true, binary size `0x5b4`, and the existing class CPP/H without changing layout or declaration order.

- 2026-07-29 B009 UID00037S callback: added the source-visible `CursorIndex` values loaded in established order by UID00039X and consumed by MapPane pointer handling: normal/select/view/put/attack are exactly `7..11`. The unresolved meanings of slots `0..6`, cursor storage, class layout, `93/94` score, owner/emitter, and all unrelated declarations remain unchanged.

- 2026-07-24 B002 UID0003A4 implementation callback: preserved `93/94` and the exact `0x5b4` layout; declared private `ScreenPane::BlitSurfaceToDisplay`, added its exact four-call ABI/behavior route, confirmed `+0x104` as the RGB565 conversion destination `m_offscreenSurface`, and retained every observed weak error, cleanup-order, and one-shot lost-surface behavior. The former generic Surface route remains historical dependency context only.

- 2026-07-24 B001 UID0003CJ class-boundary synchronization: preserved `93/94`, hierarchy/layout/formal code, method routes, and compiler-data exclusions; added exact mixed-pool evidence, the cursor-only class-source relationship, and rejection of class-static/duplicate literal declarations.

- 2026-07-24 B004 UID0001G9 implementation callback: raised `92/93 -> 93/94`; applied the accepted complete class block with `SaveScreenshotJPG`, `SaveScreenshotBMP`, and `SaveScreenshotPNG` declarations immediately after `RestoreDirectDrawState`; linked exact JPG/BMP/PNG pages; documented inherited `m_ddSurface` plus class-owned `m_renderSurface`; and retained ScreenshotCapture.cpp as the out-of-line definition route without adding duplicate class-level bodies or changing the existing `0x5b4` layout.

- 2026-07-22 B003 UID00023U implementation callback:
  - Raised `90/93 -> 92/93`, installed the complete R3 C++03 declaration before `[[CHILDREN]]`, and added exact ordinary destructor child [UID:0004W7][0x00556a60-0x00556cd4.ScreenPaneDestructor](by-memory/0x00556a60-0x00556cd4.ScreenPaneDestructor.md).
  - Added direct hierarchy/PMD/EBO evidence, exact `0x5b4` layout, provisional `0x420`/`0x16` storage with exhausted semantic alternatives, and the target-ABI verification contract.
  - Normalized source-facing `OnTimer`, `OnFrameUpdate`, inherited `TimerHandler::ScheduleTimer`, inherited `m_grafPort.m_surface`, `m_renderSurface`, and primary browser field `+0x5b1`; preserved raw adjusted offsets and historical names as evidence.
  - Recorded UID0001G5/UID00023U/UID0003CI/UID0001OX no-code dispositions and the sole semantic global route through UID0000S7.
  - Target x86 MSVC verification found the initially accepted unaligned byte array started at `+0x12d`; corrected R3 to target-period `__declspec(align(4)) unsigned char[0x420]` so the bounded physical span begins at exact `+0x130`. This implementation-time correction is mandatory for the accepted layout contract and is retained as verifier-backed history.

- 2026-07-15 B002 accepted UID0001G7 callback:
  - Raised `87/90` to `90/93` and retained owner/emitter UID0000NB with reconstructable true and blank broad formal class body.
  - Added the exact seven-method source order, real child UIDs, return/parameter contracts, fields and offsets, inherited TimerHandler relationship, cursor-loader/dirty-consumer evidence, source exclusions, and score rationale.
  - Historicalized the provisional CursorManager source view, boolean visibility overload, and `RequestPresentAndTimers` spelling without deleting prior evidence.

- 2026-07-06 B010 UID00039X cursor-loader implementation support sync:
  - Score unchanged at `87/90`; broad class C++ remains blank.
  - Added [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md) as class-owned `ScreenPane::LoadCursorResources()` with retained raw `LoadCursorResourceSlot(...)`, emitted through this class to [UID:0000NB][ScreenPane](by-file/ScreenPane.md).
  - Updated cursor-table layout notes for `+0x550`: slots 7-11 are normal/select/view/put/attack from the `.ani`/`.cur` resource pairs; active cursor index remains `+0x580`; slots `0-6`, exact helper spelling, and raw-helper liveness stay score caps.
  - Evidence: accepted B010 report `tools/leaser/Agents/Agent-B010/research/00039X-ScreenPaneCursorResourceLoader-source-quality.md`, MCP session `18aed30a`, startup caller `0x004f61c9`, modeled loader `0x00558f70-0x00559075`, raw helper `0x00559080-0x005590da`, padding at `0x00559075-0x00559080` and `0x005590da-0x005590e0`, ten cursor resource literals, writes to the ScreenPane table at `+0x56c/+0x570/+0x574/+0x578/+0x57c`, and negative evidence rejecting standalone CursorManager and Surface ownership.

- 2026-07-03 B007 UID0002VO implementation support sync:
  - Score unchanged at `87/90`; broad class C++ remains blank.
  - Updated the browser-notification method row to source-ready inferred `HandleBrowserNotification`, tied UID0002VO to MCP session `31debdf2`, vtable slot `0x00623150`, produced states `0`/`1`, `+0x511` inferred `m_browserNotificationPending`, old-browser close, optional alert allocation, and the preserved unproduced-state high-byte fallback.
  - Updated the layout note for `+0x511` to record the accepted field role and confidence cap while rejecting raw `sub_556F70`, Browser-owned, and `browser::Notification`-owned source placement.

- 2026-07-03 B008 SurfaceFlipSurfaces source-quality implementation:
  - Score unchanged at `87/90`.
  - Added [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) as `ScreenPane::PrepareDirectDrawPresentation()`, a ScreenPane class method emitted through [UID:0000NB][ScreenPane](by-file/ScreenPane.md), and updated field notes for `+0x100`, `+0x110/+0x111`, and `+0x112/+0x114/+0x116`.
  - Evidence: accepted B008 report `tools/leaser/Agents/Agent-B008/research/00039Q-SurfaceFlipSurfaces-source-quality.md`, MCP session `31debdf2`, exact `0x00557470-0x0055769d` `__thiscall` body, callers at `0x00465d13`, `0x00465d1e`, `0x00466a02`, and `0x0055887d` using [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), paired restore flag relationship with [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md), DirectDraw vtable slots `+0x50/+0x54`, DirectDrawSurface `Blt`/`Restore` slots `+0x14/+0x6c`, and negative evidence that `Flip` slot `+0x2c` is not called.

- 2026-06-29 B008 ApplicationShutdown DetachLayerFrame support sync:
  - Score unchanged at `87/90`; broad class C++ remains blank.
  - Added the source-facing helper alias for `0x00556d20` as `DetachLayerFrame` / `RemoveLayerFrame` so [UID:0002H8][0x004f6490-0x004f66a5.BaramAppShutdown](by-memory/0x004f6490-0x004f66a5.BaramAppShutdown.md) can use `g_pScreenPane->DetachLayerFrame(...)` in first-draft source while preserving exact original spelling as a support cap.
  - Summary/evidence: B008 report `tools/leaser/Agents/Agent-B008/research/0002H8-ApplicationShutdown-empty-emitter-source-quality.md`, MCP session `agent_b009_0002my_20260628`, `analyze_function 0x00556d20` mapping the argument through the ScreenPane root layer list at `+0x10c` and vtable detach/remove path, and existing [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md) evidence for six Application shutdown callers at `0x004f64cc`, `0x004f64dd`, `0x004f64ee`, `0x004f64ff`, `0x004f6510`, and `0x004f6521`.

- 2026-06-23 B005 SurfaceDirectDrawRestoreMaintenance source-quality implementation:
  - Score unchanged at `87/90`.
  - Added method-table and layout entries for [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md), source-facing `ScreenPane::RestoreDirectDrawState()`.
  - Consolidated field roles for `+0x110` and `+0x111`, tied them to [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) setup writes and `~ScreenPane` duplicate cleanup, and recorded the DirectDraw/DDError slot identities: `RestoreDisplayMode` at `IDirectDraw +0x4c`, `SetCooperativeLevel` at `IDirectDraw +0x50`, and DDError formatter at `DDError +0x0c`.
  - Evidence: accepted B005 MCP-backed report `tools/leaser/Agents/Agent-B005/research/00039R-SurfaceDirectDrawRestoreMaintenance-source-quality.md`, updated target page, ScreenPane file page, IDA MCP session `b880584f`, two direct callers at `BaramApp::OnDeactivate` `0x00466abb` and `_WinMain@16` `0x004f5ed7`, zero data xrefs, constructor zero at `0x00556a06`, destructor duplicate lifecycle docs, IDA `IDirectDrawVtbl` slot names, DDError vtable/decompilation proof for formatter target `0x004a6290`, and [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) setup writes at `0x005574e5` and `0x00557537`.

- 2026-06-21 B012 ScreenPanePresentationTraversal source-quality incorporation:
  - Added method-table and layout entries for [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md), source-facing `ScreenPane::TraversePresentationList(Region *dirtyRegion)`.
  - Consolidated field roles for `+0x118`, `+0x11c`, and `+0x59c`, and tied `+0x108` surface swapping back to the existing render-surface field notes.
  - Evidence: B012 report `tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md`, updated target page, ScreenPane file page, ScreenCursorHelpers, Surface presentation callers, Layer helper docs, and Region/Motion helper docs.
- 2026-06-21 B012 SurfaceDrawTilePresentation receiver caveat:
  - Score unchanged at `87/90`.
  - Added a class-level caveat for [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md): current emitted route remains [UID:0000OC][Surface](by-file/Surface.md), but receiver and field evidence are ScreenPane-shaped and should be evaluated with the broader presentation family before any owner migration.
  - Evidence: B012 report `tools/leaser/Agents/Agent-B012/research/00039T-SurfaceDrawTilePresentation-source-quality.md`, target [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md), sibling [UID:00039P][0x00557140-0x00557377.SurfaceRenderPresentation](by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md), [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md), and [UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md).
- 2026-06-21 B005 SurfaceRestoreLostSurfaces source-quality implementation:
  - Before: score `86/89`; [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) was absent from the class method table and the `+0x18/+0x100/+0x108` DirectDraw surface field roles were not consolidated here.
  - After: score `87/90`; added `ScreenPane::RestoreLostSurfaces`, documented the `WM_SETFOCUS` / `g_pScreenPane` caller route, DirectDraw `IsLost`/`Restore` slots, `DDERR_SURFACELOST`, retry behavior, and ScreenPane/GrafPort surface field map.
  - Evidence: accepted B005 report `tools/leaser/Agents/Agent-B005/research/00039Z-SurfaceRestoreLostSurfaces-source-quality.md`, target [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md), ScreenPane constructor/destructor lifecycle docs, [UID:00039W][0x00558840-0x00558f63.SurfaceMinimapRenderInitializer](by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md) surface initializer, [UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) blit helper, and [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md).
- 2026-06-21 B007 [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) support sync:
  - Added the file-static helper note so this class page does not overclaim a receiver for the raw helper.
  - Historical evidence wording: B007 local-byte and dependency recheck confirmed no `this` argument, complete body between `0xcc` padding, duplication of the callback then documented as `ScreenPane::HandleMessage` (current name `ScreenPane::OnTimer`), PaletteLib/MapPane/GeneralPurposePanel callee roles, and unresolved direct-caller route.
- 2026-06-19 B009 ScreenPane presentation-mode setter implementation:
  - Added [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md) method rows for `EnablePresentationMode()` at `0x00557820` and `DisablePresentationMode()` at `0x00557830`.
  - Documented `ScreenPane +0x12c` as inferred `m_presentationModeEnabled` / alternate `m_gamePresentationActive`, with startup clear evidence at `0x00558c86` inside [UID:00039W][0x00558840-0x00558f63.SurfaceMinimapRenderInitializer](by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md) and lifecycle toggles from [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) and [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md).
- 2026-06-19 B005 ScreenPane callback/transition helper implementation:
  - Before: score `85/88`; the class method inventory did not list [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md), and layout notes only covered the timer subobject generally.
  - After: score `86/89`; added `QueueFadeInCallback`, `QueueFadeOutCallback`, retained raw `SetFadeTransitionState`, and retained raw `IsFadeTransitionActive` method rows; documented `+0x598`, `+0x59a`, `+0x5a4`, `+0x5a8`, and `+0x5ac` fade/presentation fields; cross-linked [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) and [UID:0003A0][0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md).
  - Historical evidence wording: accepted B005 report `tools/leaser/Agents/Agent-B005/research/00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality.md`, local export caller facts for `0x005590e0`/`0x00559110`, retained raw-helper boundary evidence, and the callback then documented as ScreenPane `HandleMessage` (current name `OnTimer`)/transition-helper documentation tying `FdIn`/`FdOt` to the same transition fields.
- 2026-06-18 B005 visible-tile repaint owner sync:
  - Historical wording: reworded the method table to treat `0x005051c0-0x00505228` as a caller dependency into [UID:00007Q][MapPane](by-class/MapPane.md) `RedrawVisibleTiles`, not as a ScreenPane-owned helper. ScreenPane still owns the callback then documented as `HandleMessage` (current name `OnTimer`) and the raw palette bridge that load `g_activeMapPane` and call the MapPane repaint method.
- 2026-06-06 A009:
  - Before: the page still cited a recovered generated-source file, used observed-last-byte endings for several methods, omitted the split browser-notification handler, and kept the destructor-support island as a terse layout stray.
  - After: changed completion/confidence from `82/84` to `84/87`, removed generated-source provenance as an authority, normalized method ranges to end-exclusive bounds, added the browser handler TMP child link, documented the `+0x511` state byte, and linked the refreshed destructor-support island.
  - Evidence: related by-memory pages record IDA-backed function boundaries, vtable refs, `Bros` handler behavior, `g_pScreenPane` lifecycle refs, destructor callee/delete-wrapper evidence, adjustor offsets `0xa0`/`0xa4`/`0xf8`, and padding boundaries.

- 2026-06-06 A008:
  - Before: the class stayed reconstructable but unassigned because the owning [UID:0000NB][ScreenPane](by-file/ScreenPane.md) source-root page was still `84/78`, below the documented 80/80 parent gate.
  - After: changed completion/confidence to `85/88` and set `AUTOGEN_PARENT_UID` to `0000NB`; `RECONSTRUCTION_CPP CODE` remains blank because the final class declaration, inherited interface names, field names, and method signatures are still below the final-source threshold.
  - Evidence: the file page now records the exact ScreenPane method aggregate, browser notification handler, destructor-support island, vtable/read-only data, singleton storage, root layer-list helpers, and remaining cursor/surface/palette split caveats at `86/82`.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The root screen pane remained unclassified in autogen coverage despite documented singleton, frame/fade, surface cleanup, layer-list, and cursor-helper ownership evidence.
  - After: The class is reconstructable but unassigned because the likely parent file confidence is below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms `0x004b6d30`, `0x00556910`, `0x00556a60`, `0x00556ce0`, `0x005051c0`, `0x00556d50`, `0x00557070`, `0x00557380`, and destructor thunk start `0x00559b20`.

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented root-screen responsibility, singleton ownership, major methods, layout offsets, helper ownership caveats, and corrected memory ranges.
  - After: changed completion/confidence to `82/84`.
  - Evidence: existing method notes, layout notes, singleton/cursor alias discussion, IDA-backed range correction, and class/file/global cross-references support high-confidence class documentation.

- 2026-05-28:
  - Before: the main `ScreenPane` range ended at `0x00557131`, and the destructor thunk island was listed as `0x00559b2b-0x00559b8a`.
  - After: corrected the main range to `0x00556910-0x00557132` and the thunk island to `0x00559b20-0x00559b8b`.
  - Evidence: IDA MCP disassembly shows `0x00557131` is the final `ShowCursor` tail-jump byte, and `0x00559b20-0x00559b8b` contains the singleton clear plus ScreenPane destructor thunks/scalar deleting destructor.

## 2026-08-24 B001 UID0000JM Frame Callback Reconciliation

- Preserved `93/94`, owner/emitter UID0000NB, the complete `0x5b4` layout, all unrelated ScreenPane declarations/bodies, and the existing `FrameMgr.h` dependency.
- Removed only the duplicate local `FrameUpdateContext` definition; UID00005G now owns the single complete `0x0c` definition in `FrameMgr.h`. Changed only `OnFrameUpdate` from historical `bool` to the proven `void OnFrameUpdate(const FrameUpdateContext *)` FrameHandler override.
- Added the exact `[0x00557070,0x00557132)` class-level CPP body before children plus `../../util/FunctionObjects.h` for complete `Invoke()`/delete semantics. State 2 decrements fade step toward visibility; state 3 increments toward black; rendering is gated by dispatch state/endpoints; unfinished transitions reschedule after one frame.
- On completion the callback invokes and deletes the optional completion object, clears it, restores transition state 1, and shows the cursor only when the saved previous fade value was nonzero. The body remains 194 bytes/53 instructions with sole vtable route `0x00623178`; no exact child page exists, so UID0000CB is the single source carrier and UID0001G5 remains blank/non-emitting.
