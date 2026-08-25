*** UID:0000G3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../browser/Browser.h"

class Event;

class WebBoardDialogOld : public BrowserPane
{
public:
    WebBoardDialogOld(const unsigned char *initialResponsePayload,
                      OLECHAR *initialUrl);
    virtual ~WebBoardDialogOld();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool OnWebBoardPacket(void *event);

    bool HandleBoardResponse(const unsigned char *payload);
    void SendInitialBoardRequest();

private:
    BrowserControlPane *m_browserControlPane;
    unsigned char m_reserved[8];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WebBoardDialogOld

## Status

- Confidence: very strong for class identity, exact `0x278` complete-object size and complete derived-tail declaration, singleton/vtable ownership, source placement, active/old split, destructor ABI, canonical `OnControlCommand` and `HandlePointerOrMouseEvent` overrides, direct hosted-HWND access, and implementation-ready CPP/H routing. Lost folded-hook spelling and the semantic names of the retained eight bytes cap confidence below final.
- Likely source file: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- Address ranges: [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md), [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md), [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md), [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md), [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md), [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md), [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md), and [UID:00033F][0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor](by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md).
- Current generated-output caveat: older `class_RankingDialog.cpp` labels such as `RankingDialog::WebBoardDialogOld_Constructor` and `RankingDialog::HandleWebBoardResponse` are search aliases only. The accepted source route is `NexusTK/ui/dialogs/WebBoardDialog.cpp`.

## Class Purpose

`WebBoardDialogOld` is a legacy browser-backed web-board dialog. It derives from the same `BrowserPane` family as [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md), but wraps the browser control in fixed `WEBBOARD.EPD` / `WEBBOARD.PAD` art and a smaller `540x379` dialog layout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| retained raw no-route browser-control teardown/deferred-delete core | [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) | Retained no-argument raw helper body that shuts down `m_browserControlPane` at offset `+0x26c` through `BrowserControlPane::ShutdownBrowserWindow`, clears the member, calls inherited cleanup/detach virtual slots `+0x38` and `+0x40`, and queues this pane through [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) / [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md). Route search remains negative, so this exact child uses a no-body policy rather than a standalone emitted method body. |
| `GetWebBoardDialogOldModeRect(Rect *out, int selector, int mode)` / mode-control rect helper | [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md) | Class-scoped static `__stdcall` helper that returns old mode/control rectangles for modes `0`, `4`, and `6`, preserves null-output and invalid-selector no-write defaults, and rejects generated `SetModeControlRect` as a search alias. |
| `WebBoardDialogOld::WebBoardDialogOld(const unsigned char *initialResponsePayload, OLECHAR *initialUrl)` | `0x0046e640-0x0046e8bd` | Builds fixed-art web-board dialog, stores singleton `0x0067aba0`, creates `WEBBOARD.EPD` background, close button, browser control, handles optional initial response or direct URL, and queues opcode `0x73` when no direct payload or URL is supplied. |
| `WebBoardDialogOld::~WebBoardDialogOld` | `0x0046e8c0-0x0046e8e8` | Clears [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md), restores `BrowserPane` vtables, and runs base teardown; this is the ordinary source destructor body rather than the deleting wrapper. |
| `WebBoardDialogOld::OnControlCommand(int controlIndex, int notifyCode)` | `0x0046e8f0-0x0046e92a` | Canonical DialogPane primary `+0x48` override at vtable cell `0x006136d4`; control-list index `1` calls `OnBrowserDialogClosed`, shuts down `m_browserControlPane`, calls `OnDestroy` then `OnHide`, and queues deferred deletion. It has no null guards and does not clear the member. Resource/control id `30`, close-state, and deleting-destructor interpretations are rejected. |
| `WebBoardDialogOld::HandlePointerOrMouseEvent(Event *event)` | `0x0046e930-0x0046e9f4` | Canonical EventHandler secondary `+0x04` override at `0x00613704`; physical `this` is complete object `+0xa0`. It preserves branch-sensitive base-call order, reads both hosted HWNDs directly at BrowserControlPane `+0x11c`, uses `GetScreenBounds`, applies the old fixed `+30,+30` inset, calls `RenderPresentation`, and returns the saved base result without invented null guards. |
| `WebBoardDialogOld::OnWebBoardPacket` / packet forwarder | [UID:0000ZC][0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder](by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md) | Vtable/event callback at `0x00613710` that checks packet/event byte `0x62`, returns false on mismatch, and tail-jumps to `HandleBoardResponse` with the secondary-subobject `this` adjusted back by `0xa0`. |
| `WebBoardDialogOld::SendInitialBoardRequest()` | [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md) | Raw helper that sends opcode `0x73` with zero payload through the packet send/queue object and starts timer `0x572` for `20000` ms; no IDA function object or direct xrefs currently exist, and the constructor contains an inline-equivalent branch, but B010 promotes the retained helper to first-draft source. |
| `bool WebBoardDialogOld::HandleBoardResponse(const unsigned char *payload)` | `0x0046eaa0-0x0046ee79` | Cancels timer `0x572`, skips the old response's byte `1`, parses length-prefixed URL, navigation-target, and cookie/query fields, sets `domain` and `boardinfo` cookies, and navigates the embedded browser pane. |
| `EscapeOldWebBoardUrl` | [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) | File-local old URL percent-escape helper; no `this` pointer; uses old state/table `0x0067acb0/0x0067acb8` and old duplicated charsets `0x0066d44c/0x0066d458`; no direct caller/function object found, while `HandleWebBoardResponse` contains the live inline clone of the same behavior. This is old-class context, not proof of a `WebBoardDialogOld::` member function. |
| singleton clear thunk | `0x00470260-0x0047026a` | Exception-unwind/simple cleanup helper that clears `g_pWebBoardDialogOld`. |
| compiler scalar deleting destructor | [UID:00033F][0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor](by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md) | Source-declared/generated-binary wrapper reached from primary vtable `0x0061368c` and `-0xa0/-0xa4` adjustors; source remains the virtual declaration plus UID000212 ordinary body. |

## Evidence Notes

- IDA MCP on 2026-05-24 confirms `0x0046e640` installs `BrowserPane` vtables, then `WebBoardDialogOld` vtables, and writes singleton `0x0067aba0`.
- `0x0046e640` constructs `WEBBOARD.EPD` / `WEBBOARD.PAD` background art, an image-button close control id `30`, and a `BrowserControlPane` at `(30,30)-(510,334)`.
- `0x0046eaa0` is behaviorally the old-variant response parser: it cancels timer `0x572`, decodes URL/domain/boardinfo payload fields, initializes a URL-escape table at `0x0067acb0+`, sets cookies, and calls the browser navigate method.
- B001 2026-06-16 split research created exact child [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) from the former broad [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md) split index. The helper uses offset `+0x26c`, matching `m_browserControlPane`, but has no current function object or direct xref in IDA.
- B010 2026-06-19 source-quality implementation resolves [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) as retained raw WebBoardDialogOld-owned no-route teardown evidence rather than an open-ended dispatch blocker. The raw body shuts down `m_browserControlPane` through `BrowserControlPane::ShutdownBrowserWindow`, clears the member, calls inherited cleanup/detach virtual slots, and queues deletion through `g_pApplicationCleanupQueue` / `BlackHole::QueuePaneForDeferredDeletion(Pane *)`. Prior route searches found no function object, direct xref, absolute pointer hit, vtable slot, or table route to `0x0046e260`; therefore the exact child should keep formal C++ blank and document the no-body proof unless future route evidence appears.
- B010 2026-07-05 revalidation callback refreshed [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) with current MCP session `supervisor_recovery_20260705`: health OK, no function at `0x0046e260` or `0x0046e294`, successor `sub_46E2A0` size `0x216`, zero inbound xrefs, zero exact pointer-byte hits for `60 e2 46 00`, exact body bytes/instructions, and `0xcc` padding before/after the raw body. The child keeps formal C++ blank with no standalone body and no marker unless a future caller/table route is proven.
- [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) carries the active `OnControlCommand` override, gated on control-list index `0`, that shuts down and clears `m_browserControlPane`. [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) carries the old `OnControlCommand` override, gated on index `1`, that shuts down without clearing the member. Both then call `OnDestroy`, `OnHide`, and queue deferred deletion. [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) remains a no-argument raw helper with member-clear but no proven route.
- B010 2026-06-30 promotes [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md) from blank/no-body status to first-draft `static void __stdcall GetWebBoardDialogOldModeRect(Rect *out, int selector, int mode)`. The helper still has no current function object or external caller/pointer route in IDA/raw PE evidence, but the accepted body preserves null-output checks, modes `0`/`4`/`6`, selectors `0..3`, clear-rect cases, and no-write defaults; generated `SetModeControlRect` remains a rejected search alias.
- IDA MCP on 2026-05-27 confirms [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md): destructor bytes clear singleton `0x0067aba0`; callback slots at `0x006136d4` and `0x00613704` own browser-control shutdown and browser HWND reposition behavior.
- B002 2026-08-03 current-slot reanalysis supersedes the 2026-06-17 descriptive callback names. DialogPane primary slot `+0x48` proves `0x46e8f0` is `OnControlCommand(int,int)`, where `1` is the control-list index rather than resource id `30`; EventHandler secondary slot `+0x04` proves `0x46e930` is `HandlePointerOrMouseEvent(Event *)`. The old command callback has no null guards and no member clear; the event callback has no event/global/member/screen guards.
- BrowserPane occupies exactly `0x26c` bytes. The old constructor stores `BrowserControlPane *m_browserControlPane` at the first derived offset `+0x26c`; two allocation sites and deleting-wrapper size checks prove complete size `0x278`. Exhaustive bounded old-family inspection finds no access to `+0x270` or `+0x274`, so `[+0x270,+0x278)` is retained opaque storage represented by `unsigned char m_reserved[8]`. It is not inherited storage, alignment padding, or evidence for invented typed fields.
- Both old event-callback HWND operands are direct `m_browserHostHwnd +0x11c` reads. No modeled function, IDA name, current by-* declaration, or repository declaration supports `GetBrowserWindow()`. The public BrowserControlPane field and `ShutdownBrowserWindow` method are supplied by UID000015 in `NexusTK/browser/Browser.h`.
- IDA MCP on 2026-05-27 confirms [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md): raw helper bytes build `0x73,0x00`, queue length `2`, and start timer `0x572` for `0x4e20`. B010 accepts this as retained first-draft `WebBoardDialogOld::SendInitialBoardRequest()` because the constructor inline-equivalent branch accounts for current reachability.
- IDA MCP on 2026-05-27 confirms [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md): raw helper bytes initialize `0x0067acb0/0x0067acb8` escape state and percent-encode old board info strings.
- B004 2026-06-20 source-quality implementation resolves [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) as file-local `EscapeOldWebBoardUrl`, not a `WebBoardDialogOld::` method. The no-function/no-direct-caller state remains documented, but no longer blocks first-draft helper C++ because the body, state, charsets, range, and owner route are source-quality.
- `simroot_v2/class_RankingDialog.cpp` labels the constructor as `RankingDialog::WebBoardDialogOld_Constructor` and the response as `RankingDialog::HandleWebBoardResponse`. IDA vtable/singleton evidence shows these are not ranking methods.
- Live IDA MCP on 2026-06-08 reconfirmed the current mixed-helper state used for confidence gating: `0x0046e2a0-0x0046e4b6` is a modeled function with no entry xrefs, `0x0046e4c0` remains a raw helper with no IDA function object or entry xrefs, `0x0046e640-0x0046e8be` has two direct constructor callers at `0x00508ddd` and `0x0051461e`, and `g_pWebBoardDialogOld` at `0x0067aba0` has five lifecycle refs from constructor/destructor/unwind/delete paths.
- B008 2026-06-19 source-quality reanalysis independently checked the local PE padding, rel32 and absolute-pointer reachability, vtable slots, singleton references, and string/global evidence. It confirms the old direct island as `0x0046e260-0x0046efda`, with companion cleanup/deleting-destructor thunks at `0x00470260` and `0x004707f0-0x0047084f`, and validates every internal split as function/raw-helper boundary plus compiler alignment rather than arbitrary documentation cuts.

## Closed Source-Quality Findings

- Final class name is `WebBoardDialogOld`. `OldWebBoardDialog` is rejected because current target, child pages, vtable/RTTI support, the singleton `g_pWebBoardDialogOld`, and generated search aliases all use the `WebBoardDialogOld` order.
- Final source placement is `NexusTK/ui/dialogs/WebBoardDialog.cpp` through [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md). Browser remains an infrastructure dependency, and RankingDialog remains generated-output pollution.
- Active [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) and this old class are separate variants in the same source family. They share BrowserPane/BrowserControlPane dependencies, board opcode `0x73`, response byte `0x62`, cookie/URL behavior, and timer id `0x572`, but have separate singleton slots and resource sets.
- Old fixed-art resources are `WEBBOARD.EPD` and `WEBBOARD.PAD` at `0x00613b00` and `0x00613ae4`, used by the old constructor only. Active/shared EPF/PAL board-frame assets and RankingDialog resources do not move this class out of WebBoardDialog.cpp.
- The raw helper start at `0x0046e260` remains retained source-shaped teardown evidence with a negative route search and no standalone body. The previously raw helper starts at `0x0046e4c0` and `0x0046ea30` are now promoted by B010 to first-draft `GetWebBoardDialogOldModeRect` and `WebBoardDialogOld::SendInitialBoardRequest()` because their bodies, argument roles, no-write/default behavior, opcode/timer state, and duplicate live paths are documented enough for this callback.
- [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) is old-class support but not an instance method. It stays a file-local `EscapeOldWebBoardUrl` helper under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md).

## Boundary And Reachability

| Target | Reachability result | Current decision |
| --- | --- | --- |
| `0x0046e260` | No function object, direct rel32 route, pointer hit, vtable slot, or table route. | Retained raw teardown/deferred-delete evidence, no standalone body. |
| `0x0046e2a0` | Modeled function with no direct entry xrefs. | Class-owned layout refresh helper; final name inferred. |
| `0x0046e4c0` | No function object or direct route; local switch-table refs only. | Promoted first-draft static `__stdcall GetWebBoardDialogOldModeRect`; no-write invalid defaults are preserved. |
| `0x0046e640` | Direct calls at `0x00508ddd` and `0x0051461e`. | Live old constructor. |
| `0x0046e8c0` | No ordinary direct call; lifecycle routes through generated destructor machinery. | Ordinary destructor body owned by exact child [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md). |
| `0x0046e8f0` | Primary-vtable ref at `0x006136d4`, canonical DialogPane slot `+0x48`. | `OnControlCommand(int controlIndex, int notifyCode)` with index gate `1`. |
| `0x0046e930` | Secondary-vtable ref at `0x00613704`, canonical EventHandler slot `+0x04`. | `HandlePointerOrMouseEvent(Event *event)` with physical adjusted view `this == complete + 0xa0`. |
| `0x0046ea00` | Vtable ref at `0x00613710`. | Packet/event callback, currently named `OnWebBoardPacket` in the class shell. |
| `0x0046ea30` | No function object or direct route; constructor has inline-equivalent branch. | Promoted retained first-draft `WebBoardDialogOld::SendInitialBoardRequest()` body. |
| `0x0046eaa0` | Called from constructor `0x0046e850` and packet tail jump `0x0046ea1e`. | `HandleBoardResponse`. |
| `0x0046ee80` | No direct route; response handler contains inline clone behavior. | File-local `EscapeOldWebBoardUrl`, not a class member. |
| `0x00470260` | Cleanup/static helper jump path. | Singleton-clear cleanup effect, non-emitting mixed thunk support. |
| `0x004707f0` | Vtable/adjustor reachable through `0x0061368c` and thunk jumps. | Scalar deleting destructor wrapper, not ordinary source destructor body. |

## Source-Quality Name Map

| Raw/generated item | Preferred source-quality name | Notes |
| --- | --- | --- |
| `dword_67ABA0` | `g_pWebBoardDialogOld` | Source-level `WebBoardDialogOld *` singleton under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md). |
| `[this+0x26c]` / `this[155]` | `m_browserControlPane` | BrowserControlPane child pointer used by constructor, teardown, callbacks, and response navigation. |
| complete object size | `0x278` | Two constructor allocations and UID00033F guarded-size path agree. Offset `+0x278` is one-past this old object and is not an old-class member. |
| `[this+0x26c]` | first derived `m_browserControlPane` | `BrowserPane` ends at `0x26c`; this pointer occupies `[+0x26c,+0x270)` and is used by the old constructor/callback/response paths. |
| `[this+0x270..+0x277]` | `m_reserved[8]` | Exact retained derived storage required by complete size `0x278`; exhaustive searches find no use, so semantic field invention and alignment-padding claims are rejected. |
| close button id `30` | close button command/control id | Not the `0x0046e8f0` close-state callback state. |
| `dword_67A74C` | `g_pApplicationCleanupQueue` | Cleanup queue used before `BlackHole::QueuePaneForDeferredDeletion(Pane *)`. |
| `sub_46BA90` | `BrowserControlPane::ShutdownBrowserWindow` / shutdown helper | Callee dependency, not owner. |
| `dword_67A7EC` | packet send/queue object | Used with byte writer and `QueueAndSendPacket` for opcode `0x73`. |
| `sub_575380` | packet byte writer | Writes byte plus terminator for packet construction. |
| `sub_574BB0` | `QueueAndSendPacket` | Sends exact two-byte old request. |
| `sub_5975E0` | timer start helper | Starts timer id `0x572` for `20000` ms. |
| `byte_67ACB0` / `byte_67ACB8` | `s_oldWebBoardUrlEscapeInitialized` / `s_oldWebBoardUrlEscapeTable` | BSS-zero old escape state, not `0xff` initialized. |
| `0x0066d44c` / `0x0066d458` | `kOldWebBoardUrlReservedChars` / `kOldWebBoardUrlUnsafeChars` | Old URL escape character sets. |
| `RankingDialog::WebBoardDialogOld_Constructor` / `RankingDialog::HandleWebBoardResponse` | generated search aliases only | Replace narrative with `WebBoardDialogOld` / `HandleBoardResponse` ownership. |
| generated `SetModeControlRect` | search alias only | Prefer `GetWebBoardDialogOldModeRect` until static declaration and default behavior are final. |

## First-Draft C++ Readiness

The class page emits only `[[CHILDREN]]` in CPP and the complete declaration in H. Class identity, source route, vtable/singleton evidence, canonical callbacks, Browser.h dependencies, child ownership, and every byte through complete size `0x278` are stable above the draft gate; method bodies remain delegated to exact by-memory children.

Current declarations retain `bool HandleBoardResponse(const unsigned char *payload)` and `SendInitialBoardRequest()`; `EscapeOldWebBoardUrl` remains a file-local helper under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md). The former `RefreshOldLayout(int mode)` declaration is rejected: [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md) uses active-only `+0x278` storage and is now active `WebBoardDialog::RefreshLayout(int mode)`. Original semantic declarations for the retained eight bytes and exact lexical spelling of folded lifecycle hooks remain unavailable, but the explicit opaque/human-source dispositions are not compile blockers.

## Assignment Gate

This class remains assigned to [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md). The class is now `92/93` and the direct file parent remains above gate. Exact old-dialog method children attach to [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) with [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) as the source module route. UID000211, UID0000ZB, UID0000ZC, UID000213, UID0000ZD, UID000212, and UID00033F use direct class owner/emitter metadata; UID000214 remains file-local. UID0000ZA is explicitly excluded and routes to active [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md).

## Closed Open Questions

- Final class name: closed as `WebBoardDialogOld`; `OldWebBoardDialog` is unsupported by current evidence.
- Source placement: closed as `NexusTK/ui/dialogs/WebBoardDialog.cpp`. Browser is dependency-only and RankingDialog is generated pollution.
- Active/old relationship: closed as separate classes/variants in the same source family, with distinct singleton/resource state.
- `0x0046e2a0`: closed as old layout refresh helper, not constructor; final original name remains inferred.
- `0x0046e4c0`: closed as class-scoped static `__stdcall GetWebBoardDialogOldModeRect(Rect *out, int selector, int mode)`; the first-draft body preserves null-output and invalid-input no-write defaults.
- `0x0046e260`: closed as retained raw no-route teardown evidence with no standalone body emission.
- `0x0046ea30`: closed as retained first-draft `WebBoardDialogOld::SendInitialBoardRequest()`; constructor inline-equivalent branch accounts for current reachability.
- `0x0046ee80`: closed as file-local old URL escape helper support, not a class method.

## Cross-References

- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md)
- [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md)
- [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md) - reclassified active `WebBoardDialog::RefreshLayout`; retained here only as a corrected historical relationship.
- [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md)
- [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md)
- [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md)
- [UID:0000ZC][0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder](by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md)
- [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md)
- [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md)
- [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md)
- [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)

## Changes

- 2026-08-03 B002 UID000212 accepted callback incorporation:
  - Raised metadata from `90/90` to `92/93`, retained owner/emitter UID0000P9, moved class-level declarations from CPP to the formal H channel, and left CPP as exactly `[[CHILDREN]]`.
  - Declared canonical `OnControlCommand` and `HandlePointerOrMouseEvent` overrides, direct Browser.h dependencies, `m_browserControlPane +0x26c`, and opaque retained `m_reserved[8]` through complete size `0x278`.
  - Added exact close/event behavior, physical adjusted-view normalization, direct hosted-HWND/no-accessor evidence, no-guard/no-clear distinctions, and exhaustive retained-tail no-improvement proof.
  - Historical correction: `OnCloseStateChanged`, `OnInputEventWithBrowserReposition`, inherited-pointer wording, and the earlier no-derived-members shell are superseded assumptions retained only in dated history.

- 2026-07-12 B004 UID00033F source-quality callback:
  - Raised confidence `88 -> 90` with completion unchanged at 90.
  - Applied the complete corrected declaration block, preserving all unrelated methods and `[[CHILDREN]]` while removing active-only `RefreshOldLayout` and false old-private fields.
  - Recorded exact old size `0x278`, inherited browser pointer `+0x26c`, UID000212 ordinary body, UID00033F vtable/adjustor/delete relation, and UID0000ZA active-owner correction.

- 2026-06-30 B010 [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) empty-emitter implementation callback:
  - Updated the class shell to `WebBoardDialogOld(const unsigned char *initialResponsePayload, OLECHAR *initialUrl)`, `void RefreshOldLayout(int mode)`, `bool HandleBoardResponse(const unsigned char *payload)`, and `void SendInitialBoardRequest()`.
  - Recorded the promoted first-draft disposition for [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md), [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md), [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md), [UID:0000ZC][0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder](by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md), [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md), and [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md), while preserving [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) as the no-body retained teardown proof and [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) as file-local URL escape support.

- 2026-06-21 B008 [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) source-quality implementation:
  - Changed to: `COMPLETION:90`, `CONFIDENCE:88`, with declaration-level first-draft C++ shell and `[[CHILDREN]]`; owner/emitter remain [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md).
  - Closed source placement, active/old variant relationship, class-name, RankingDialog pollution, Browser dependency-only, raw no-route helper policy, field/global/helper names, and file-local URL escape-helper context.
  - Summary/evidence: B008 local PE and documentation reanalysis reconfirmed padding-bounded old island `0x0046e260-0x0046efda`, constructor callers `0x00508ddd` and `0x0051461e`, WebBoardDialogOld vtable slots at `0x0061368c`, `0x006136d4`, `0x00613704`, and `0x00613710`, old singleton `0x0067aba0`, fixed `WEBBOARD.EPD/PAD` resources, opcode `0x73` request path, response byte `0x62`, timer `0x572`, old URL escape state, and no-route evidence for retained raw helpers.

- 2026-06-20 B004 [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) implementation:
  - Updated the method inventory and evidence notes to use `EscapeOldWebBoardUrl` as a file-local helper name and to reject a `WebBoardDialogOld::` member interpretation.
  - Summary/evidence: the helper has no `this` pointer or direct caller, but B004 verified the old state/table, old duplicated charsets, exact range/padding, `%%%2X` escape behavior, and [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) owner/emitter route.

- 2026-06-17 B002 source-quality execution:
  - Updated the old destructor/callback method rows to `WebBoardDialogOld::~WebBoardDialogOld`, `WebBoardDialogOld::OnCloseStateChanged(int state, int reason)`, and `WebBoardDialogOld::OnInputEventWithBrowserReposition(...)`.
  - Added the `state == 1` close-state gate, rejection of close-button id `30` / deleting-destructor / generic DialogPane / RankingDialog interpretations, old `+30,+30` browser HWND geometry, `m_browserControlPane`, and no-member-null-store note.
  - [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) now carries accepted first-draft formal C++.

- 2026-06-19 B010 [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) retained raw teardown source-quality execution:
  - Resolved the exact child as WebBoardDialogOld-owned retained raw no-route browser-control teardown/deferred-delete core, not BrowserControlPane, BlackHole, RankingDialog, compiler thunk, destructor wrapper, ownerless code, or parent-only split-index content.
  - Replaced raw names with `m_browserControlPane`, `BrowserControlPane::ShutdownBrowserWindow`, `g_pApplicationCleanupQueue`, and `BlackHole::QueuePaneForDeferredDeletion(Pane *)`.
  - Recorded the active/old close-body relationship and no-body policy: [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) and [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) carry modeled vtable-referenced teardown callbacks, while [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) has member-clear semantics but no proven caller/table route and should not emit a standalone C++ method body.

- 2026-07-05 B010 [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) revalidation callback:
  - Added current MCP session `supervisor_recovery_20260705` no-function/no-route/padding evidence and preserved the strict formal-blank/no-standalone-body/no marker disposition for this retained raw child.
  - Preserved existing owner/source-route, source-shaped teardown behavior, active/old close-body relationship, and rejected ownership alternatives.

- 2026-06-16 supervisor-executed B001 [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md) source-route/liveness report:
  - Changed to: method notes, evidence, assignment-gate text, and open questions now attach [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md) directly to [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), with [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) as the source module route.
  - Summary/evidence: B001 live IDA/raw PE audit confirmed the raw no-function/no-entry-xref state, switch-table-only local references, unique helper bytes, and rejected RankingDialog/generic/dead-code routes. Final C++ remains blank because the generated `SetModeControlRect` source shape and static/calling convention are still not final-quality.
- 2026-06-16 supervisor-executed B001 split:
  - Before: the raw old browser-control teardown helper was referenced through broad parent [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md).
  - Changed to: address ranges, method notes, evidence, and cross-references now point to exact child [UID:0003V5][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md).
  - Summary/evidence: B001 IDA MCP review confirmed the raw no-function/no-xref teardown body and old-class offset pattern; no score change was made on this class page.
- 2026-06-07: Replaced raw `dword_67A74C` unregister references with canonical [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) links.
  - Before: the old web-board teardown/callback rows described deferred unregistering through the historical generated global only.
  - After: the method table links the resolved BlackHole deferred cleanup queue while retaining the historical label for IDA traceability.
  - Evidence: the generated resolved-name report maps `dword_67A74C` to `g_pApplicationCleanupQueue`, and this page's existing memory evidence ties the old web-board close paths to the `0x00469180` deferred-deletion helper.

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the old layout, constructor, destructor/callback, packet/response, singleton-clear, and scalar deleting destructor starts from `0x0046e2a0` through `0x004707f0`; IDA still reports raw helper offsets `0x0046e260`, `0x0046e4c0`, `0x0046ea30`, and `0x0046ee80` as not separate functions, matching the existing raw-helper notes. The class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the detailed legacy web-board constructor, layout, rect helper, callbacks, packet forwarder, request/response, URL escape, singleton/destructor, resource, and generated-owner-correction evidence; confidence remains capped by raw helper starts with no direct xrefs and unresolved final source-file placement.
- 2026-06-08 A006 Batch105 parent-gate refresh:
  - Before: score `88/80`; exact children such as [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md) could not attach to this direct class parent under the corrected gate.
  - Changed to: confidence `85`, with explicit assignment-gate text.
  - Summary/evidence: live IDA MCP reconfirmed the layout helper's modeled no-xref state, the raw mode-rect helper no-function/no-xref state, the old constructor's two direct callers, and five `g_pWebBoardDialogOld` lifecycle refs. Confidence remains below higher levels because several old helper starts are raw/unxrefed and exact final source names are still provisional.
