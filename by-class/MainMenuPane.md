*** UID:00007O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/BlackHole.h"
#include "HistoryViewingPane.h"
#include "MainMenuPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../render/EPFTileContext.h"
#include "../render/Palette.h"
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Event;

class MainMenuPane : public Pane, public Singleton<MainMenuPane>
{
public:
    explicit MainMenuPane(bool fromTerminalTransition);
    virtual ~MainMenuPane();

    void SetServerName(const wchar_t *serverName);
    void SetPaintSuppressed(bool suppressed);
    void ActivateMenuItem();
    void InitializeMainUiGraph();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

    bool m_paintSuppressed;
    signed char m_menuItemCount;
    signed char m_selectedMenuItemIndex;
    wchar_t m_serverName[128];
    EPFTileContext m_backgroundTileContext;
    DLPalette m_backgroundPalette;
    bool m_fromTerminalTransition;
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MainMenuPane

## 2026-08-14 B003 Header Route Closure

- The complete class moved from CPP to guarded H with exact EPFTileContext, Palette, Pane, and Singleton includes plus Event forward. CPP now includes `MainMenuPane.h` before children.
- The class body, `0x454` layout, and method inventory are unchanged. This provides the complete derived type needed by ChangePasswordDialogPane::OnShow while retaining UID00007O/UID0000L0 at `92/94`.
- Emitter position `0` guarantees that this complete class appears before UID0000RF's singleton extern in both generated channels.

## Status

- Confidence: strong
- Likely source file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Exact core range: [UID:00036Y][0x004f6700-0x004f7d10.MainMenuPaneCore](by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md)
- Broader mixed neighborhood: [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MainMenuPane.cpp`

## Class Purpose

`MainMenuPane` is the pre-login menu controller. It renders and navigates the main menu, handles pre-login server messages, and opens the login/account/password/story/exit flows selected by the user.

## Accepted 0x454 Layout And Access Model

| Offset range | Size | Source member/relation | Evidence |
| --- | ---: | --- | --- |
| `+0x000..+0x0f7` | `0xf8` | inherited `Pane` state | Pane plus inherited EventHandler/TimerHandler views precede `+0xf8`; RTTI COL offsets are `0`, `0xa0`, `0xa4`. |
| `+0x0f8` | EBO | `Singleton<MainMenuPane>` base | RTTI PMD is exactly `+0xf8`; empty-base optimization consumes no additional storage. |
| `+0x0f8` | `1` | `bool m_paintSuppressed` | OnPaint tests and SetPaintSuppressed stores this byte; it intentionally overlaps the empty Singleton anchor. |
| `+0x0f9` | `1` | `signed char m_menuItemCount` | Constructor initializes 6; HitTest and paint loops consume it. |
| `+0x0fa` | `1` | `signed char m_selectedMenuItemIndex` | Constructor initializes 1; pointer/key/paint/activation use signed `-1` and `0..5`. |
| `+0x0fb` | `1` | reserved natural alignment | Compiler insertion for two-byte Windows `wchar_t`; not a source member. |
| `+0x0fc..+0x1fb` | `0x100` | `wchar_t m_serverName[128]` | SetServerName calls `wcscpy_s(this+0xfc,0x80,...)`: 128 wide characters / 256 bytes. |
| `+0x1fc..+0x223` | `0x28` | `EPFTileContext m_backgroundTileContext` | constructor/member construction, LEVEL.BMP decode and paint/resource evidence. |
| `+0x224..+0x44f` | `0x22c` | `DLPalette m_backgroundPalette` | constructor/member construction, reverse destruction and decode/render evidence. |
| `+0x450` | `1` | `bool m_fromTerminalTransition` | two constructor callers pass `0/1`; only this byte receives the argument. |
| `+0x451..+0x453` | `3` | natural tail alignment | four-byte maximum alignment closes allocation at exactly `0x454`; not a source member. |

The exact closure is `0xf8 + 3 + 1 alignment + 0x100 + 0x28 + 0x22c + 1 + 3 tail = 0x454`. No `m_reserved...` arrays are emitted. Access control has no binary representation: accepted file-local `HitTestMenuItem` reads `pane->m_menuItemCount`, so the compile-ready first draft intentionally keeps data public rather than inventing a friend declaration. Later source recovery may make members private and friend the helper without changing layout or behavior.

## Exact Core Child Methods

| UID | Method / range | Route and source role |
| --- | --- | --- |
| [UID:0004LY][0x004f6700-0x004f6904.MainMenuPaneConstructor](by-memory/0x004f6700-0x004f6904.MainMenuPaneConstructor.md) | `MainMenuPane(bool)`, `0x004f6700-0x004f6904` | callers pass false/true; lifecycle/resource/timer initialization |
| [UID:0004LZ][0x004f6910-0x004f6998.MainMenuPaneDestructor](by-memory/0x004f6910-0x004f6998.MainMenuPaneDestructor.md) | `~MainMenuPane`, `0x004f6910-0x004f6998` | ordinary destructor; compiler member/base teardown implicit |
| [UID:0004M0][0x004f6a40-0x004f6a5e.MainMenuPaneSetServerNameRaw](by-memory/0x004f6a40-0x004f6a5e.MainMenuPaneSetServerNameRaw.md) | `SetServerName`, `0x004f6a40-0x004f6a5e` | retained unique no-route thiscall setter |
| [UID:0004M1][0x004f6a60-0x004f6ae4.MainMenuPaneHandleSystemOrControlEvent](by-memory/0x004f6a60-0x004f6ae4.MainMenuPaneHandleSystemOrControlEvent.md) | `HandleSystemOrControlEvent`, `0x004f6a60-0x004f6ae4` | EventHandler slot `+0x14` |
| [UID:0004M2][0x004f6af0-0x004f6be1.MainMenuPaneHandlePointerOrMouseEvent](by-memory/0x004f6af0-0x004f6be1.MainMenuPaneHandlePointerOrMouseEvent.md) | `HandlePointerOrMouseEvent`, `0x004f6af0-0x004f6be1` | EventHandler slot `+4`, exact `m_y,m_x` HitTest call |
| [UID:0004M3][0x004f6bf0-0x004f6ceb.MainMenuPaneHandleKeyOrTextEvent](by-memory/0x004f6bf0-0x004f6ceb.MainMenuPaneHandleKeyOrTextEvent.md) | `HandleKeyOrTextEvent`, `0x004f6bf0-0x004f6ceb` | EventHandler slot `+8` |
| [UID:0004M4][0x004f6d80-0x004f75ba.MainMenuPaneHandlePacketEvent](by-memory/0x004f6d80-0x004f75ba.MainMenuPaneHandlePacketEvent.md) | `HandlePacketEvent`, `0x004f6d80-0x004f75ba` | EventHandler slot `+0x10` and full pre-login packet dispatch |
| [UID:0004M5][0x004f7660-0x004f76cb.MainMenuPaneOnTimer](by-memory/0x004f7660-0x004f76cb.MainMenuPaneOnTimer.md) | `OnTimer`, `0x004f7660-0x004f76cb` | TimerHandler slot `+4`, timer ID 1/opcode 113/rearm |
| [UID:0004M6][0x004f76d0-0x004f79ec.MainMenuPaneOnPaint](by-memory/0x004f76d0-0x004f79ec.MainMenuPaneOnPaint.md) | `OnPaint`, `0x004f76d0-0x004f79ec` | primary slot `+0x44`, EPF/classic resources |
| [UID:0004M7][0x004f79f0-0x004f7a0d.MainMenuPaneSetPaintSuppressedRaw](by-memory/0x004f79f0-0x004f7a0d.MainMenuPaneSetPaintSuppressedRaw.md) | `SetPaintSuppressed`, `0x004f79f0-0x004f7a0d` | retained unique no-route thiscall setter |
| [UID:0004M8][0x004f7a10-0x004f7ce9.MainMenuPaneActivateMenuItem](by-memory/0x004f7a10-0x004f7ce9.MainMenuPaneActivateMenuItem.md) | `ActivateMenuItem`, `0x004f7a10-0x004f7ce9` | signed cases 0-5, accepted retained launch-helper factorization |
| [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) | `InitializeMainUiGraph`, `0x004f7d10-0x004f8b2a`, position `120` | complete two-layout UI construction method; sole login-success caller uses `g_pMainMenuPane` as `this` |

Existing [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md) remains a file-local static helper owned/emitted by UID0000L0, not a class method. `ComputeMenuItemRect`, `HitTestMenuItem`, legacy/ANSI packet helpers, and retained launch helpers also stay file-local. Historical `OnMouseEvent`, `OnKeyEvent`, and `OnServerMessage` are search aliases superseded by current EventHandler interface names.

## Raw Liveness, Callers, And Compiler Boundaries

- Constructor callers `0x00504b35`/`0x0058b3de` pass `0/1`. Virtual reachability is through primary `0x0061d264`, EventHandler `0x0061d2b0`, and TimerHandler `0x0061d2e0`; Activate has calls `0x004f6bc7`/`0x004f6cd2`.
- Both raw setters have unique coherent signatures but zero entry xrefs, VA/RVA/raw pointers, relative routes, table routes, or duplicate bodies. They remain source children with `88/91` confidence caps; callback registration is not claimed.
- Vptr writes, RTTI, three vtable views, scalar deleting/adjustor wrappers, switch tables, natural padding, and member/base teardown are compiler output caused by this declaration/method family and are not handwritten C++.
- Rejected owners include EventDispatcher, TimerMgr, PacketBuffer, Config, ServerSelectPane, PatchPane, image/audio/dialog dependencies; they consume or are called by this class but own neither receiver, layout, vtables, nor source range.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MainMenuPane` | `0x004f6700` | Constructs the menu pane and loads menu art/resources, including optional `LEVEL.BMP` decode through ImageLoaders with an embedded `EPFTileContext` at `this + 0x1fc` and `DLPalette` at `this + 0x224`. |
| `~MainMenuPane` | `0x004f6910` | Tears down menu state and calls dialog-singleton cleanup. |
| `CloseMainMenuDialogSingletons` | `0x004f69a0` | File-local static helper in `MainMenuPane.cpp`, not an instance method; sweeps global main-menu dialog singleton slots for the destructor, scalar deleting destructor, and menu/server transition callback. |
| `SetServerName` | `0x004f6a40` | Unique no-route raw setter for `wchar_t[128]`; exact child UID0004M0. |
| `HandleSystemOrControlEvent` | `0x004f6a60` | Event type 22 closes dialogs and opens ConnectionClosedDialog; UID0004M1. |
| `HandlePointerOrMouseEvent` | `0x004f6af0` | Updates selection through `HitTestMenuItem(this,m_y,m_x)`, invalidates old/new, activates on left-button-up; UID0004M2. |
| `HandleKeyOrTextEvent` | `0x004f6bf0` | Signed keyboard wrap navigation and activation; UID0004M3. |
| `HandlePacketEvent` | `0x004f6d80` | Exact pre-login packet dispatcher; UID0004M4. |
| `OnTimer` | `0x004f7660` | Timer ID 1 active notification/rearm; UID0004M5. |
| `OnPaint` | `0x004f76d0` | Paints menu assets and selected item. |
| `SetPaintSuppressed` | `0x004f79f0` | Unique no-route raw setter; invalidates inherited bounds then stores paint gate; UID0004M7. |
| `ActivateMenuItem` | `0x004f7a10` | Dispatches selected menu item to create-user, login, password, story/history frame viewer, terminal, or exit. |
| `ComputeMenuItemRect` | `0x004f8b90` | File-local helper used by mouse/key/paint paths to compute a `RectBounds` for a selected main-menu item or the `-1` zero-rectangle sentinel. |
| `HitTestMenuItem` | `0x004f8c10` | Sibling file-local helper, not a class method, used by `OnMouseEvent` to map mouse coordinates to a signed menu item index or `-1`; first-draft source calls `ComputeMenuItemRect`, while the raw duplicated rectangle formula is preserved as byte-for-byte fallback evidence. |
| `HandleLegacyMainMenuPacket` / historical `HandleLegacyMainMenuPacket_4F8D00` | `0x004f8d00` | File-local helper for pre-login server-message opcode `3`; child [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md) carries first-draft C++ with conservative helper naming after transfer-only/reconnect-only/meta-only/login-redirect alternatives were rejected. |
| `OpenTransferServerDialog` | `0x004f8f10` | Retained file-local transfer-server overlay launcher; current B003 MCP session `80de0a67` confirms exact 133-byte body/SHA16 `729a5ccb73a2f46f`, first-draft `static bool __stdcall OpenTransferServerDialog(int)` C++ readiness, timer-owner cancellation through `g_pTimerMgr`, `g_pTransferServerDialog` guard, `TransferServerDialogPane(true)` construction, and duplicate active `OnServerMessage` opcode `0x5e` behavior. Historical/search alias: `OpenTransferServerDialog_4F8F10`; no direct entry xrefs or VA/RVA pointer route remain confidence caps. |
| `OpenCreateUserDialog` | `0x004f8fa0` | Retained file-local create-user launcher; exact child [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) now emits accepted first-draft `static void OpenCreateUserDialog()` C++ under `MainMenuPane.cpp`. No direct helper xrefs or accepted callback route remain confidence caps, not blank-C++ blockers. Historical/search alias: `OpenCreateUserDialog_4F8FA0`. |
| `OpenChangePasswordDialog` | `0x004f9060` | Retained file-local password-dialog launcher; accepted B010 evidence supports first-draft `static void OpenChangePasswordDialog()` C++ under `MainMenuPane.cpp`, with historical/search alias `OpenChangePasswordDialog_4F9060`, current misleading IDA name `___std_parallel_algorithms_hw_threads@0_0`, no direct helper xrefs or accepted VA/RVA pointer route, duplicate active `ActivateMenuItem` case `2` allocation/constructor behavior, and `g_pChangePasswordDialogPane` singleton publication supporting the `void` source shape. |
| `OpenStoryViewingPane` | `0x004f90c0` | Retained file-local story viewer opener; accepted B004 evidence supports first-draft `static void OpenStoryViewingPane()` C++ under `MainMenuPane.cpp`, with historical/search alias `OpenStoryViewingPane_4F90C0`, exact child [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md), no direct helper xrefs or accepted VA/RVA pointer route, duplicate active `ActivateMenuItem` case `3` allocation/constructor behavior, and `g_pHistoryViewingPane` constructor publication supporting the `void` source shape. |
| `OpenHistoryViewingPane` | `0x004f9140` | Retained file-local history viewer opener; accepted B004 evidence supports first-draft `static void OpenHistoryViewingPane()` C++ under `MainMenuPane.cpp`, with historical/search alias `OpenHistoryViewingPane_4F9140`, exact child [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md), no direct helper xrefs or accepted VA/RVA pointer route, duplicate active `ActivateMenuItem` case `4` allocation/constructor behavior, and `g_pHistoryViewingPane` constructor publication supporting the `void` source shape. |
| `OpenTerminalPane` | `0x004f91c0` | Retained file-local terminal launcher; exact child [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md) now emits accepted first-draft `static void OpenTerminalPane(MainMenuPane *pane)` C++ under `MainMenuPane.cpp`. No direct helper xrefs or accepted callback route remain confidence caps, not blank-C++ blockers. Historical/search alias: `OpenTerminalPane_4F91C0`. |
| `DestroyActiveScreenDimmer` | `0x00502e10` | File-local helper reached only from `OnServerMessage` at `0x004f733a`; consumes no `this` pointer and deletes active `g_pScreenDimmer` if present. |
| `HandleAnsiTextUrlDialogPacket` | `0x00502e30` | File-local opcode `0x66` helper reached only from `OnServerMessage` at `0x004f74c2`; consumes a packet pointer, constructs URL alerts for subtype `1`/`2`, and writes the NCA confirm-user URL override for subtype `3`. |
| Destructor thunks | `0x005024e2`, `0x005024ed`, `0x00502850` | Multiple-inheritance deleting destructor family. |

## Evidence Notes

- [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md) is the concrete `MainMenuPane *` singleton slot. The constructor assigns `this`, shared dialog/menu paths consume it, and shutdown clears it. Historical `g_pMainUiGraph` wording is superseded.
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) is a source-authored class method, not a `MainUiGraph` free function. Its 3,611-byte range expands the two source layout branches, common tail, allocation/EH lowering, and cleanup funclets; the emitted method retains the human-written operations and excludes compiler scaffolding.

- IDA MCP confirms all listed method starts as functions.
- `ActivateMenuItem` calls `LoginDialogPane::LoginDialogPane`, `ChangePasswordDialogPane::ChangePasswordDialogPane`, `CreateUserDialogPane::CreateUserDialogPane`, and `NewUserDialogPane2::NewUserDialogPane2`.
- `ActivateMenuItem` calls [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) for the story/history menu branches, passing `STORY.EPF`/`STORY.EPD` or `HISTORY.EPF`/`HISTORY.EPD` based on the high-resolution layout flag.
- [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md) is a local menu geometry helper used by mouse, key, and paint handlers; [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md) is the address-suffixed alias page.
- [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) is called only from `OnMouseEvent` in the current IDA database and is a sibling file-local helper, not a class method. B012 resolves the source-facing helper as `static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)`: it reads base `+0xf9` as `m_menuItemCount`, returns a signed index or `-1`, and uses the raw point-test order `mouseY, mouseX` because [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) compare the first coordinate against top/bottom and the second against left/right.
- Main-menu byte fields now have high-probability names: base `+0xf9` is `m_menuItemCount` (constructor initializes the little-endian word at `+0xf9` to `0x0106`, giving count `6` and initial selection `1`), and base `+0xfa` is `m_selectedMenuItemIndex` (written by mouse hit testing, wrapped by keyboard navigation, read by paint overlays, and switched by `ActivateMenuItem` cases `0..5`).
- [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md) is called only from `OnServerMessage` case `3` and now carries first-draft `HandleLegacyMainMenuPacket` C++ under [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). Current B001 MCP evidence resolves the target as payload `+1/+5/+7/+8` parsing, `DATFile` local lifetime, Socket command-6 reconnect post, `Socket::PostConnectionStatusQuery(bool *outConnected)` / `Thread::WaitForResult`, failed-status `AlertPane(..., NULL, NULL)` button-label arguments, outbound opcode `0x10` with `g_useEpfAssets`, `g_pScreenDimmer` deletion, and `MetaMan` sync. [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md) remains an alias/support page.
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) is a standalone retained helper with no direct helper-start xrefs; current B003 MCP session `80de0a67` confirms exact `0x85` / 133 byte body, SHA16 `729a5ccb73a2f46f`, fourteen-byte pre-padding, eleven-byte post-padding, zero inbound xrefs, zero VA/RVA pointer-byte route, and a body that mirrors the active `OnServerMessage` opcode `0x5e` transfer branch by cancelling the `g_pUserPane+0xa4` timer-owner target through `g_pTimerMgr`, checking `g_pTransferServerDialog`, allocating `0x100`, and constructing `TransferServerDialogPane(true)`. The accepted source-facing shape is the file-local `static bool __stdcall OpenTransferServerDialog(int)` helper; inferred `m_timerHandler` names the documented `+0xa4` `TimerHandler` subobject and the unresolved retained callback registration only caps confidence.
- [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) is a standalone retained password-dialog launcher under this file. Accepted B010 session `875bf182` and current implementation-check session `b001_000241_20260627` still report the misleading `___std_parallel_algorithms_hw_threads@0_0` name, exact `0x54` / 84-byte size, `0x26c` / 620-byte allocation, zero helper-entry xrefs, no accepted VA/RVA pointer route, active `ActivateMenuItem` case `2` duplicate construction that ignores the pointer, and constructor publication through `g_pChangePasswordDialogPane`. The accepted source-facing shape is file-local `static void OpenChangePasswordDialog()`; the unresolved retained registration route only caps confidence.
- [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md) and [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md) are standalone retained story/history viewer openers under this file. Accepted B004 MCP session `992d23de` confirms exact `0x7f` / 127-byte child bodies, `0x108` / 264-byte allocations, `g_useEpfAssets == 1` resource selection, `STORY.EPF`/`STORY.EPD` and `HISTORY.EPF`/`HISTORY.EPD` constructor paths, zero helper-entry xrefs/callers, zero VA/RVA pointer-byte routes, and active `ActivateMenuItem` cases `3`/`4` duplicate construction that ignores the pointer. The accepted source-facing shapes are file-local `static void OpenStoryViewingPane()` and `static void OpenHistoryViewingPane()`; the unresolved retained registration route only caps confidence, and [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) / [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md) remain blank-C++ aliases.
- [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) and [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md) are real retained launch helpers under this file and now own accepted first-draft file-local C++ bodies. [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) and [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) remain address-suffixed support/search aliases. Current no-direct-xref evidence remains a confidence cap, not a blank-C++ blocker.
- [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md) is called from main-menu teardown paths and closes the pre-login singleton dialog cluster. B010 reanalysis resolves it as a file-local/static helper in `MainMenuPane.cpp`, not a private instance method, because the raw function has no `this` argument and reads only global singleton slots. [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md) remains the recovered address-suffixed alias page.
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) owns two MainMenuPane file-local helpers, `DestroyActiveScreenDimmer` and `HandleAnsiTextUrlDialogPacket`. They are not class virtual methods and consume no `this` pointer; both are reached only from `MainMenuPane::OnServerMessage`.
- The constructor's optional `LEVEL.BMP` path calls [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) at `0x004f68bd` after reading the file into an `_AUTOBUF<unsigned char>`. The call arguments are `(buffer, byteCount, this + 0x1fc, this + 0x224)`, giving high-probability field roles for the class's background/level tile context and palette while leaving the decode helper owned by [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).
- Generated source uses `g_useHighResLayout`/config bytes to select old/new menu branches.
- 2026-06-11 IDA MCP confirms the exact core method island at [UID:00036Y][0x004f6700-0x004f7d10.MainMenuPaneCore](by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md), including all modeled constructor/destructor/input/server/timer/paint/activate functions, local jump-table/padding tails, and raw function-shaped unmodeled bodies at `0x004f6a40-0x004f6a5e` and `0x004f79f0-0x004f7a0d`.

## Direct Parent Gate

`MainMenuPane` now clears the strict 85/85 direct-parent gate for the exact core child [UID:00036Y][0x004f6700-0x004f7d10.MainMenuPaneCore](by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md). The child is `85/88`; this class page is `85/89` after recording the exact core child, raw-island caveats, and live IDA boundary evidence. The broader [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md) page remains a mixed aggregate and should not be attached to this class.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The class page now has a live exact core child, method inventory, local helper ownership, dialog-launch dependencies, retained launcher caveats, raw-island caveats, and parent-gate status. Remaining work is final source signatures, field naming, and full C++ reconstruction. |
| Confidence | 89 | IDA confirms the core range boundaries, method starts, helper relationships, key constructor/activation/callback evidence, and the raw unmodeled bodies. Confidence remains below final audit because some retained launchers and raw helper signatures are still unresolved. |

## Cross-References

- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:00036Y][0x004f6700-0x004f7d10.MainMenuPaneCore](by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md)
- [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md)
- [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md)
- [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md)
- [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md)
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md)
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md)
- [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md)
- [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md)
- [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md)
- [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md)
- [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-08-16 UID0000JW consumer callback: added `#include "HistoryViewingPane.h"` to the formal CPP shell so the four active direct constructor sites and retained `OpenStoryViewingPane`/`OpenHistoryViewingPane` helpers have a compile-visible complete class declaration. Ownership remains MainMenu for launch decisions and `HistoryViewingPane.cpp/.h` for viewer implementation.
- The empty H `[[CHILDREN]]` marker was removed because MainMenuPane has no declaration children in that slot; UID0000RF's extern remains a separate root child. This prevents the validator's literal `[[No Children Attached]]` placeholder without changing class content or source ownership.

- 2026-07-14 B002 UID0002AF callback: raised to `92/94`; added the exact `void InitializeMainUiGraph();` declaration; registered UID00019K at position `120`; synchronized concrete `g_pMainMenuPane` ownership, full method/source route, and historical alias disposition while preserving all stronger existing class detail.

- 2026-07-13 B003 UID00036Y callback: score `85/89 -> 91/93`; replaced historical comment-only class marker with the exact managed `0x454` declaration and `[[CHILDREN]]`; documented exact EBO/member/natural-padding layout, public helper-compatible access, eleven registered class children, callers/vtable slots, raw negatives, compiler exclusions, rejected owners, and superseded interface/raw names.

- 2026-06-29 B004 HistoryViewingPane launch-helper implementation: score unchanged; synchronized the class helper inventory and evidence for exact children [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md) and [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md). Accepted B004 MCP session `992d23de` supports first-draft file-local `static void` C++ in `MainMenuPane.cpp`; the aggregate [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md) remains non-emitting, and [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) / [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md) remain blank-C++ aliases.

- 2026-06-25 B001 LegacyMainMenuPacket source-quality sync: score unchanged; updated the helper inventory and evidence notes for [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md). The exact child now owns the first-draft `HandleLegacyMainMenuPacket` body as a file-local `MainMenuPane.cpp` helper, with command-12 `Socket::PostConnectionStatusQuery(bool *outConnected)` support synchronized while `Socket::QueryTransportState` remains the vtable consumer. The conservative helper name is accepted after rejecting transfer-only, reconnect-only, meta-only, and login-redirect alternatives; class-level C++ remains declaration/child-driven because this exact helper is file-local/static.

- 2026-06-24 B003 OpenTransferServerDialog source-quality implementation: score unchanged; refreshed [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) as a retained file-local helper under [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), with current MCP session `80de0a67` exact range/bytes/SHA16, no direct xref or VA/RVA pointer route, duplicate active opcode `0x5e` branch, `g_pUserPane+0xa4` / inferred `m_timerHandler` timer-owner cancellation, `g_pTransferServerDialog` guard, `TransferServerDialogPane(true)` construction, rejected TransferServerDialogPane/TimerMgr/UserPane/singleton/no-owner ownership alternatives, and first-draft formal C++ readiness. Class-level emission remains declaration/child-driven because this exact helper is file-local/static and the method bodies belong to by-memory children.

- 2026-06-27 B010 OpenChangePasswordDialog source-quality implementation: score unchanged; refreshed [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) as a retained file-local helper under [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The exact child now owns first-draft `static void OpenChangePasswordDialog()` C++; current MCP still reports `___std_parallel_algorithms_hw_threads@0_0`, no direct helper xref or accepted pointer route exists, active `ActivateMenuItem` case `2` duplicates the allocation/constructor path and ignores the pointer, and singleton publication through `g_pChangePasswordDialogPane` rejects pointer-return C++. Class-level emission remains declaration/child-driven because this exact helper is file-local/static.

- 2026-06-21 B010 CloseMainMenuDialogSingletons source-quality sync:
  - Added the file-local cleanup helper to the method/helper inventory and clarified that it is not a `MainMenuPane` instance method.
  - Recorded caller/reachability scope: non-deleting destructor, scalar deleting destructor, and menu/server transition callback all share the same global singleton sweep.

- 2026-06-21 Supervisor Rule 26 / B007 ComputeMenuItemRect incorporation: added the source-facing `ComputeMenuItemRect` helper row, renamed the display text for `HitTestMenuItem`, and recorded that the raw hit-test helper duplicates the rectangle formula. This preserves [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md) and [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md) as recovered alias pages while routing source-facing implementation detail through [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md) and [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md).
- 2026-06-21 B012 MainMenuHitTest source-quality sync: score unchanged; added the first-draft `HitTestMenuItem` helper shape, `mouseY, mouseX` point-test order, `m_menuItemCount` at base `+0xf9`, `m_selectedMenuItemIndex` at base `+0xfa`, and the source-quality/byte-for-byte split for the rectangle-helper relationship.
- 2026-06-21 B007 BMP decoder consumer sync: score unchanged; added the `LEVEL.BMP` constructor call evidence from [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md), including the `_AUTOBUF<unsigned char>` buffer/size pair, `this + 0x1fc` `EPFTileContext`, and `this + 0x224` `DLPalette` field roles.
- 2026-06-12 Agent-A004 Goal 2: score unchanged at `85/89`; added the retained `OpenTransferServerDialog_4F8F10` helper to the method inventory and evidence notes after live IDA MCP confirmed its exact body and its match to the active `OnServerMessage` opcode `0x5e` transfer branch. The helper remains filed under [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) rather than this class page because it is a standalone `__stdcall` launcher with no `this` pointer.
- 2026-06-11 Agent-A006 Batch160: raised from `84/88` to `85/89` after creating and validating exact child [UID:00036Y][0x004f6700-0x004f7d10.MainMenuPaneCore](by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md). Live IDA MCP evidence now records the exact core boundary, all modeled functions before `InitializeMainUiGraph`, raw function-shaped unmodeled bodies at `0x004f6a40-0x004f6a5e` and `0x004f79f0-0x004f7a0d`, and the strict direct-parent gate for the new child.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) because the class is `84/88` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts for the constructor/destructor, mouse/key/server/timer/paint handlers, activation helper, retained launch helpers, and scalar deleting destructor at `0x004f6700`, `0x004f6910`, `0x004f6af0`, `0x004f6bf0`, `0x004f6d80`, `0x004f7660`, `0x004f76d0`, `0x004f7a10`, `0x004f8c10`, `0x004f8d00`, `0x004f8fa0`, `0x004f91c0`, and `0x00502850`; `callers` confirms constructor calls from `0x00504b35` and `0x0058b3de`.
- Completion/confidence score update: existed before as `0/0`; changed to `84/88`. Summary: the pre-login menu controller has detailed purpose, method inventory, dialog-launch dependencies, local helper ownership, retained launcher caveats, singleton cleanup, resource branches, and high-resolution behavior documented, with final source-level rewrite detail still incomplete. Evidence: IDA-confirmed method starts, `ActivateMenuItem` callees, menu geometry/helper globals, story/history resource references, and retained no-xref launcher notes.
