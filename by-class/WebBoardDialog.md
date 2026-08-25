*** UID:0000G2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/BlackHole.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../browser/Browser.h"

class Event;
class InputEvent;
class ImageButtonControlPane;

class WebBoardDialog : public BrowserPane
{
public:
    WebBoardDialog(int boardMode,
                   const wchar_t *boardOwnerName,
                   const void *initialResponsePacket,
                   OLECHAR *initialUrl);
    virtual ~WebBoardDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool OnPacket(void *event);
    virtual bool OnKeyEvent(InputEvent *event);

    void RefreshLayout(int mode);
    bool HandleBoardResponse(const void *packet);
    void SendInitialBoardRequest(unsigned char boardMode);

private:
    BrowserControlPane *m_browserControlPane; // +0x26c
    unsigned char m_reserved[8];              // +0x270
    ImageButtonControlPane *m_closeButton;    // +0x278
    wchar_t m_boardOwnerName[0x80];           // +0x27c
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WebBoardDialog

## Status

- Confidence: very strong for behavior, singleton, core method boundaries, class-owned constructor route, packet/response ownership, and declaration-level first-draft C++; medium only for final original helper/field spellings and project-wide packet typedefs.
- Likely source file: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), with board references from [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) and browser infrastructure from [UID:0000HV][Browser](by-file/Browser.md)
- Address ranges: [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md), [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md), [UID:0003V1][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md), [UID:0003V2][0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh](by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md), [UID:0003V3][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md), [UID:0003V4][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md)
- Current recovered file: `source-3/simroot_v2/class_WebBoardDialog.cpp`

## Class Purpose

`WebBoardDialog` is a browser-backed in-game board dialog. It derives from the browser pane/dialog family, creates an embedded `BrowserControlPane`, and routes packet-driven or direct-URL startup into the board response/browser loader. Its active URL-escape guard and 256-byte table are file-static dependencies emitted by [UID:0002AG][0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState](by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md), not fields in this class layout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WebBoardDialog::WebBoardDialog(int boardMode, const wchar_t *boardOwnerName, const void *initialResponsePacket, OLECHAR *initialUrl)` | `0x0046d050-0x0046d324` | Builds the browser-backed board dialog; creates the close button and embedded `BrowserControlPane`; selects immediate response handling, direct URL loading, or opcode `0x73` request plus timer `0x572`. |
| `WebBoardDialog::~WebBoardDialog` | `0x0046d330-0x0046d359` | Clears [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md), restores `BrowserPane` vtables, and runs base teardown; this is the ordinary source destructor body rather than the deleting wrapper. |
| `WebBoardDialog::OnControlCommand(int controlIndex, int notifyCode)` | `0x0046d360-0x0046d3a5` | Primary `+0x48` override. On control-list index `0`, calls `OnBrowserDialogClosed`, shuts down and clears derived `m_browserControlPane`, calls `OnDestroy` and `OnHide`, then queues deferred deletion; no invented null guard or resource-id interpretation. |
| `WebBoardDialog::HandlePointerOrMouseEvent(Event *event)` | `0x0046d3b0-0x0046d475` | EventHandler secondary `+0x04` override. Delegates to DialogPane, directly uses active/member `m_browserHostHwnd`, applies WebBoard inset `+11,+42`, and calls `g_pScreenPane->RenderPresentation()`; generated `DialogPane` ownership is pollution. |
| `WebBoardDialog::OnPacket(void *event)` | `0x0046d480-0x0046d4a3` | Vtable/event callback that reads the payload pointer at `event + 0x0c`, checks response opcode byte `0x62`, returns false on mismatch, and returns `HandleBoardResponse(payload)` on match. |
| `WebBoardDialog::OnKeyEvent(InputEvent *event)` | `0x0046d4b0-0x0046d50e` | Handles the board/browser `b` close/back key case and raw key `0x90`, otherwise falls back to shared DialogPane key handling, with a truth-valued callback contract. |
| initial board request helper | `0x0046d510-0x0046d57c` | Raw helper that queues opcode `0x73` with a caller byte and starts timer `0x572`; live bytes show `0x0046d57b` is the final `retn 4` immediate byte. |
| `bool WebBoardDialog::HandleBoardResponse(const void *packet)` | `0x0046d580-0x0046da62` | Cancels timer `0x572`, parses active web-board payloads, handles the owner-page branch, sets `domain`/`boardinfo` cookies, and navigates the embedded browser pane. |
| `void WebBoardDialog::RefreshLayout(int mode)` | [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md) | Rebuilds the active close-button and browser-control fields at `+0x278` and `+0x26c` for modes `0`, `4`, and `6`; the filename preserves historical old-owner wording, but active `0x37c` size and old `0x278` complete size resolve current ownership here. |
| URL escape helper | `0x0046da70-0x0046dbca` | Raw helper emitted through UID0000Z9 that initializes and consumes file-static active state emitted once by UID0002AG, then copies or `%XX`-escapes response URL bytes into a bounded buffer. |
| control/layout refresh vtable helper | `0x0046dbd0-0x0046dcf3` | Vtable-backed helper at slot `0x00613620`; clears pending browser state and adjusts selected child/control rect drawing around resource ids `0x84`/`0x86`. |
| background tile render helper | `0x0046dd00-0x0046de96` | Vtable-backed helper at slot `0x0061362c`; tiles the web-board interior/background resource across the inset dialog rect. |
| frame tile render helper | `0x0046dea0-0x0046e25b` | Vtable-backed helper at slot `0x00613630`; draws web-board frame/corner/edge tiles when the embedded browser-control state is clear. |
| singleton clear thunk | `0x00470250-0x0047025a` | Exception-unwind/simple cleanup helper that clears `g_pWebBoardDialog`. |
| scalar deleting destructor | [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md) | Compiler-generated deleting wrapper used from the vtable/adjustor routes; clears `g_pWebBoardDialog`, optionally frees storage, and should remain comment-only while [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) emits the ordinary `WebBoardDialog::~WebBoardDialog()` source body. |

## First-Draft C++ Readiness

B005's 2026-06-19 source-quality pass routes constructor [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md) directly through this class. The accepted UID000212 callback now places exactly `[[CHILDREN]]` in class CPP and the complete class declaration in H, so `NexusTK/ui/dialogs/WebBoardDialog.h` includes `../../browser/Browser.h` before exact by-memory child bodies assemble into the source file.

Current class field inferences from the accepted B005 report:

| Offset | Current source-facing name | Type / role | Evidence |
| --- | --- | --- | --- |
| `+0x26c` | `m_browserControlPane` | `BrowserControlPane *` | Constructor store, [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) shutdown/reposition use, and BrowserControlPane hosted-HWND/navigation docs. |
| `+0x270..+0x277` | `m_reserved` | `unsigned char[8]` retained derived storage | BrowserPane ends at `0x26c`; the next evidenced member starts at `+0x278`, while complete active size is `0x37c`. No constructor write or stronger semantic field identity is invented for this exact interval. |
| `+0x278` | `m_closeButton` | `ImageButtonControlPane *` / close-command pane | Constructor allocates size `276`, constructs through `0x00495bf0` with id `30` and mode-dependent close-button rectangles, then adds it as a child. |
| `+0x27c` | `m_boardOwnerName` | `wchar_t[0x80]` | Constructor copies `boardOwnerName` with `wcscpy_s`; mode `4` callers pass selected/local player names. |

[UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md) is an active-class method despite its historical filename and lack of direct entry xrefs. It destroys and rebuilds `m_browserControlPane` at `+0x26c` and `m_closeButton` at `+0x278`, then applies the complete active mode `0`/`4`/`6` geometry. Those offsets fit this class's proven `0x37c` complete size. The rejected `WebBoardDialogOld::RefreshOldLayout` interpretation would place a member at exactly one-past the old class's proven `0x278` complete size; the old constructor instead keeps its id-30 close button in a local and performs no `+0x278` store.

Constructor mode facts:

- Modes `0` and `4` are proven by callers at `0x00508da0`, `0x005145db`, `0x00554d76`, and `0x005bd0cf`.
- Mode `6` has no observed current caller in exported xrefs, but it has complete constructor-local close/browser/dialog rectangle sets and remains source-shaped dormant behavior.
- The constructor branch with no response packet and no URL sends opcode `0x73`, appends `boardMode`, and starts timer `0x572` for `20000` ms. The source-level helper name `SendInitialBoardRequest(unsigned char boardMode)` is descriptive and linked to [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md).

The class declaration deliberately excludes concrete BrowserPane/WebBoardDialog vtable stores; those are compiler output from base construction and virtual method declarations.

B010's accepted 2026-06-30 empty-emitter implementation callback updates the shell signatures without changing this class score. [UID:0000Z8][0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder](by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md) and [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md) use direct owner/emitter [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md). The accepted source shape uses local `void *event` packet callbacks plus `GetWebBoardPacketPayload(const void *event)` in the child bodies because MCP proves only the payload-pointer slot at `event + 0x0c`; a broader engine packet typedef is outside this by-file repair. The later UID0002AG callback preserves this complete class formal byte-for-byte and changes only module-static source ownership: UID0002AG emits the active guard/table declarations at source position `0`, while UID0000Z9 retains literals, initialization, URL-escape helper, and response-handler code.

## Evidence Notes

- B002 UID000212 current callback/layout reconciliation proves the complete declaration route: `BrowserPane` base size is `0x26c`; active derived storage is `m_browserControlPane +0x26c`, retained bytes `+0x270..+0x277`, `m_closeButton +0x278`, and `m_boardOwnerName +0x27c`, through complete size `0x37c`. The H block declares every derived byte used by accepted method CPP and includes `../../browser/Browser.h`; CPP contains only `[[CHILDREN]]`.
- Active primary cell `0x00613624` proves `OnControlCommand(int,int)` at inherited `+0x48`; secondary cell `0x00613654` proves `HandlePointerOrMouseEvent(Event *)` at EventHandler `+0x04`. Exact bodies preserve active-only `m_browserControlPane = NULL`, inset `+11,+42`, direct `m_browserHostHwnd` access, and `RenderPresentation`. Current API searches find no `GetBrowserWindow()` route, and no null guards occur in the binary body.
- Wave3 summary identifies the class as a `BrowserPane`-derived modal board flow.
- IDA MCP confirms `0x0046d050` as a real function with size `0x2d4`.
- IDA MCP on 2026-05-24 confirms `0x0046d480` size `0x23`, `0x0046d580` size `0x4e3`, `0x0046d330` size `0x29`, and `0x00470790` size `0x5f`.
- IDA MCP on 2026-05-27 confirms the virtual companion cluster at [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md), with vtable slots at `0x00613624`, `0x00613654`, and the adjacent packet slot at `0x00613660`.
- IDA MCP on 2026-05-27 confirms [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md), including vtable-backed `0x0046d4b0` at slot `0x00613658` and raw non-modeled helper `0x0046d510-0x0046d57c`.
- B001 2026-06-16 split research moved [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md) to a non-emitting split index and created exact active children [UID:0003V1][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md), [UID:0003V2][0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh](by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md), [UID:0003V3][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md), and [UID:0003V4][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md). IDA MCP evidence confirms active WebBoardDialog vtable slots `0x00613620`, `0x0061362c`, and `0x00613630`, plus the raw active URL escape helper at `0x0046da70`.
- `0x0046d050` stores singleton `0x0067ab9c`; destructor paths clear the same global.
- The active constructor callers are browser/menu/map-adjacent open paths at `0x00508da0`, `0x005145db`, `0x00554d76`, and `0x005bd0cf`.
- Source placement is split-confidence: behavior is board-specific, but base implementation and control dependencies are in the browser module. Keep the source candidate under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) until import-source evidence proves otherwise.
- B001-024 exact child [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md) documents `sub_470790`, vtable ref `0x006135dc`, adjustor callers at `0x004702d6`/`0x004702e1`, `g_pWebBoardDialog` clear, base teardown, and delete flag behavior.
- B011 2026-06-21 source-quality reanalysis confirms [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md) is the compiler-generated scalar deleting destructor wrapper for this class, not a handwritten source helper and not the ordinary destructor body. Keep the class declaration's `virtual ~WebBoardDialog();` plus [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) as the real source destructor; [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md) should emit only the comment marker documenting generated-wrapper handling.
- B002 2026-06-17 source-quality reanalysis accepts first-draft C++ for [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md). The compact companion cluster has stable source placement under this class/file, vtable refs at `0x00613624` and `0x00613654`, `m_browserControlPane` at `+0x26c`, BrowserControlPane hosted HWND at `+0x11c`, `g_activeBrowserControlPane`, `g_pScreenPane`, and `g_pApplicationCleanupQueue`. Current generated `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` was empty before this formal C++ population because the route existed but the formal C++ block was blank, not because ownership was wrong.
- B005 2026-06-19 source-quality reanalysis accepts [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md) as the class-owned constructor, with exact `0x2d4` bytes, SHA1 `ce6793e9f83e8de9144284e6ab04223837d7b600`, four ordinary callers, `g_pWebBoardDialog` singleton store, `m_browserControlPane` at `+0x26c`, `m_closeButton` at `+0x278`, `m_boardOwnerName[0x80]` at `+0x27c`, modes `0`/`4`/`6`, and first-draft constructor C++.
- B010 2026-06-30 empty-emitter implementation callback resolves active packet/handler ownership and return contracts: [UID:0000Z8][0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder](by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md) and [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md) move from file-owned to class-owned emitters, use `bool` callbacks/handlers, and preserve the packet payload pointer at `event + 0x0c` in a file-local accessor instead of inventing a project-wide event struct.

## Related Variant

[UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) is a separate legacy fixed-art variant in the same [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) source family. B008 2026-06-19 closes the active-vs-old placement question: both variants belong under `NexusTK/ui/dialogs/WebBoardDialog.cpp`, but they keep distinct class identity, singleton slots, resource sets, and field/layout geometry. Do not merge the old generated `class_RankingDialog.cpp` body into `RankingDialog`; keep old WebBoardDialog helper/body ownership with the old class or file-local WebBoardDialog support as documented by the exact child pages.

## Cross-References

- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md)
- [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md)
- [UID:0000Z8][0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder](by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md)
- [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md)
- [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md)
- [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md)
- [UID:0003V1][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md)
- [UID:0003V2][0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh](by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md)
- [UID:0003V3][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md)
- [UID:0003V4][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md)
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md)
- [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md)
- [UID:000013][Browser](by-class/Browser.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)

## Changes

- 2026-08-03 B002 UID000212 implementation callback:
  - Raised `88/90 -> 92/93`, moved the class declaration from CPP to formal H, set formal CPP to exactly `[[CHILDREN]]`, and added the exact `../../browser/Browser.h` include/forward declarations.
  - Corrected callbacks to `OnControlCommand(int,int)` and `HandlePointerOrMouseEvent(Event *)`; added the complete active layout including retained `[+0x270,+0x278)` storage; preserved active member clear, `+11,+42` geometry, direct hosted-HWND access, and all prior constructor/packet/layout/render/source evidence.
  - The dated 2026-06-17 callback names below remain historical assumptions superseded by this accepted callback.

- 2026-07-21 B005 UID0002AG implementation callback:
  - Preserved score `88/90`, class metadata, declaration/fields/methods/`[[CHILDREN]]` block byte-for-byte, and all unrelated active/old/destructor/render evidence.
  - Synchronized only the active URL-escape dependency inventory: [UID:0002AG][0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState](by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md) is the sole file-static guard/table emitter at source position `0`; UID0000Z9 still emits the literals, initializer, helper, and handler. These objects are not `WebBoardDialog` fields.

- 2026-07-12 B004 UID00033F source-quality callback:
  - Preserved `88/90`, all existing declarations, fields, children, constructor/callback/destructor facts, and source routing while adding only `void RefreshLayout(int mode);` to the complete managed class block.
  - Recorded UID0000ZA's active owner/emitter correction, active complete size `0x37c`, valid `+0x26c`/`+0x278` fields, no-entry-xref caveat, and the exact old-size `0x278` contradiction that rejects historical WebBoardDialogOld ownership.

- 2026-06-30 B010 [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) empty-emitter implementation callback:
  - Updated the class shell to `virtual bool OnPacket(void *event)`, `virtual bool OnKeyEvent(InputEvent *event)`, and `bool HandleBoardResponse(const void *packet)`.
  - Recorded direct class ownership for [UID:0000Z8][0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder](by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md) and [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md), including the `event + 0x0c` payload slot, opcode `0x62`, truth-valued return contract, active response field order, and active URL escape support emitted through [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md).

- 2026-06-21 B008 old-variant source-family sync:
  - Updated the related-variant note to record that [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) is a separate class/variant in the same [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) source family, not RankingDialog or Browser ownership.
  - Summary/evidence: B008 old-class reanalysis validated the old singleton/vtable/resource/opcode route and preserved this active class as the active browser-backed variant with its own singleton, resources, geometry, and child emitters.

- 2026-06-21 B011 [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md) source-quality sync:
  - Updated the scalar deleting destructor row and evidence notes to mark UID `00033E` as compiler-generated ABI wrapper output that should stay comment-only in formal C++, with [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) carrying the ordinary `WebBoardDialog::~WebBoardDialog()` body.
  - Summary/evidence: B011 reconfirmed vtable reachability through `0x006135dc`, adjustor routes at `0x004702d6`/`0x004702e1`, `g_pWebBoardDialog` clear at `0x00470796`, and rejection of Browser/BrowserPane/global/aggregate/old-variant/handwritten-wrapper ownership alternatives. No class score change was required.

- 2026-06-19 B005 constructor source-quality execution:
  - Before: `COMPLETION:85`, `CONFIDENCE:87`, blank class declaration C++, and constructor row without source signature/field detail.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, declaration-level first-draft C++ shell with `[[CHILDREN]]`, source signature for `WebBoardDialog::WebBoardDialog(int boardMode, const wchar_t *boardOwnerName, const void *initialResponsePacket, OLECHAR *initialUrl)`, and explicit field notes for `m_browserControlPane`, `m_closeButton`, and `m_boardOwnerName`.
  - Summary/evidence: B005 reanalysis proves [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md) is a source-authored class constructor rather than a file-only bucket item, rejects Browser/BrowserControlPane/BoardDialogs/DialogPane/WebBoardDialogOld/no-owner alternatives, and confirms the constructor has first-draft C++ ready while exact original helper/field spellings remain inferred.

- 2026-06-17 B002 source-quality execution:
  - Updated the active destructor/close/reposition rows to `WebBoardDialog::~WebBoardDialog`, `WebBoardDialog::OnCloseStateChanged(int state, int reason)`, and `WebBoardDialog::OnInputEventWithBrowserReposition(...)`.
  - Added the active `state == 0` close gate, `m_browserControlPane` member clear, `+11,+42` hosted browser geometry, global dependencies, generated `DialogPane` owner-pollution caveat, and generated-output-empty explanation.
  - [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) now carries accepted first-draft formal C++.

- 2026-06-16 supervisor-executed B001 split:
  - Before: active URL escape/render helpers were represented only through broad parent [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md).
  - Changed to: address ranges, evidence, and cross-references now point to exact active children [UID:0003V1][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md), [UID:0003V2][0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh](by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md), [UID:0003V3][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md), and [UID:0003V4][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md).
  - Summary/evidence: B001 IDA MCP review confirmed the active vtable slots, raw active URL escape helper, and source-quality blockers; no score change was made on this class page.
- 2026-06-10 B001-024 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, with the scalar deleting destructor listed but no exact child page.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`, and linked exact child [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md).
  - Summary/evidence: live IDA MCP confirms `sub_470790`, vtable ref `0x006135dc`, adjustor callers, singleton clear, base teardown, and delete flag behavior. This clears the strict `85/85` parent gate for the in-range WebBoardDialog destructor child.
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the active constructor/destructor/close/input/packet/response/render-helper/singleton-clear/destructor starts from `0x0046d050` through `0x00470790`; IDA still reports raw helper offsets `0x0046d510` and `0x0046da70` as not separate functions, matching the existing raw-helper notes. The class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-06-05: Corrected the active initial request helper extent from `0x0046d510-0x0046d57b` to `0x0046d510-0x0046d57c`.
  - Evidence: live IDA raw-byte audit shows `retn 4` starts at `0x0046d579` and consumes byte `0x0046d57b`; padding before `sub_46D580` begins at `0x0046d57c`.

- 2026-05-27: The constructor method row previously ended at `0x0046d323`; changed it to exclusive end `0x0046d324`. IDA MCP reports `sub_46D050` size `0x2d4`, and the matching by-memory page uses `0x0046d050-0x0046d324`.
- 2026-05-27: The destructor method row previously ended at `0x0046d358`; changed it to exclusive end `0x0046d359`. IDA MCP reports `sub_46D330` size `0x29`, and the new virtual-companion memory page records the exact function span.
- 2026-05-27: The packet forwarder method row previously ended at `0x0046d4a2`; changed it to exclusive end `0x0046d4a3`. IDA MCP reports `sub_46D480` size `0x23`, and the matching by-memory page uses `0x0046d480-0x0046d4a3`.
- 2026-05-30: Grading changed from unevaluated `0/0` to `82/86`.
  - Before: class page had detailed active-method coverage but no score.
  - After: score reflects the documented constructor/destructor/input/packet/response/render/url-escape method family and singleton/browser-control ownership.
  - Evidence: linked by-memory pages cover the active class core through `0x0046e25b`, while the generated `simroot_v2/ui/dialogs/WebBoardDialog.cpp` still contains unresolved symbols and synthetic layout artifacts, keeping completion below fully reconstructed class pages.
