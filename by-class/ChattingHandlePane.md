*** UID:00001V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;

static signed char GetChatButtonAtPoint(int mouseY, int mouseX);

enum ChatHandleButtonHit
{
    kChatHandleButtonNone = -1,
    kChatHandleButtonLeft = 0,
    kChatHandleBody = 1,
    kChatHandleButtonMode = 2,
    kChatHandleButtonSecondary = 3,
};

enum ChatHandleButtonPaintState
{
    kChatHandleButtonNormal = 0,
    kChatHandleButtonHover = 1,
    kChatHandleButtonPressed = 2,
};

struct ChattingHandleRenderState
{
    bool valid;
    bool chatTargetPending;
    int chatHandleModeIndex;
    bool secondaryChatEnabled;
    int leftButtonPaintState;
    int modeButtonPaintState;
    int secondaryButtonPaintState;
};

class ChattingHandlePane : public Pane,
                           public Singleton<ChattingHandlePane>
{
public:
    ChattingHandlePane();
    virtual ~ChattingHandlePane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();

private:
    bool IsRenderStateCurrent(const ChattingHandleRenderState *state) const;
    void CaptureRenderState(ChattingHandleRenderState *state) const;

    ChattingHandleRenderState m_renderStateSnapshot;
    bool m_mouseCaptured;

public:
    bool m_chatTargetPending;
    int m_chatHandleModeIndex;
    bool m_secondaryChatEnabled;

private:
    bool m_leftButtonPressed;
    bool m_modeButtonPressed;
    bool m_secondaryButtonPressed;
    int m_leftButtonPaintState;
    int m_modeButtonPaintState;
    int m_secondaryButtonPaintState;
};

extern ChattingHandlePane *g_pChattingHandlePane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChattingHandlePane

## Status

- Confidence: very strong for exact inheritance, size/layout, lifecycle, method/field roles, source ordering, and compiler exclusions; strong for inferred private helper spellings and access labels.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingHandlePane.cpp`
- Source emitter position: `10`, after sole semantic global definition UID0002XE and before method children at positions `20-70`.
- Complete object size: `0x128` bytes.

## Class Purpose

`ChattingHandlePane` owns the chat handle controls. It tracks hover/toggle state for the handle buttons, persists chat-related display options to config, enables/disables the secondary chat scroll widget, and paints `CHATBUTT.EPF` frames.

The source class directly derives from `Pane` and `Singleton<ChattingHandlePane>`. RTTI names the Singleton specialization and gives its base PMD as `mdisp=+0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`. The compiler's adjusted-null publication, ordinary/unwind/scalar clears, secondary forwarder, vptr writes, Pane teardown, RTTI, and vtables are consequences of that declaration, not handwritten class methods.

## Field Map

2026-06-28 B003 source-quality reanalysis resolves the active handle state and rendered-state snapshot into source-facing names used by [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) and [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md):

| Offset | Source-facing name | Role |
| ---: | --- | --- |
| `+0x0f8..+0x10c` | `m_renderStateSnapshot` | Rendered-state record: `valid`, `chatTargetPending`, `chatHandleModeIndex`, `secondaryChatEnabled`, `leftButtonPaintState`, `modeButtonPaintState`, and `secondaryButtonPaintState`. |
| `+0x110` | `m_mouseCaptured` | Mouse-down capture/drag-latch flag for the handle mouse dispatcher. |
| `+0x111` | `m_chatTargetPending` | Class-side pending chat-target state toggled by the left handle button. It is persisted through config-side `g_pConfig->m_chatHandleLeftToggle` at `+0x28de81` and consumed by target-selection and say-mode code as pending chat-target state. |
| `+0x114` | `m_chatHandleModeIndex` | Three-state handle mode index loaded from and persisted to `g_pConfig->m_chatHandleModeIndex` at `+0x28de7c`. |
| `+0x118` | `m_secondaryChatEnabled` | Secondary chat enable flag loaded from and persisted to `g_pConfig->m_secondaryChatEnabled` at `+0x28de80`; it controls the chat display scroll widget, gates modify-height painting, and gates UID0002EV current-layout ChattingPane message iteration while preserving the disabled background fill. |
| `+0x119..+0x11b` | `m_leftButtonPressed`, `m_modeButtonPressed`, `m_secondaryButtonPressed` | Transient mouse-down latch bytes reset after every left-button-up handling path. |
| `+0x11c`, `+0x120`, `+0x124` | `m_leftButtonPaintState`, `m_modeButtonPaintState`, `m_secondaryButtonPaintState` | Paint-state dwords where `0` is normal, `1` is hover, and `2` is pressed. |

### Exact Layout / Access / Padding Closure

- Empty-base optimization allows direct `Singleton<ChattingHandlePane>` and the first `ChattingHandleRenderState` member to begin at `+0xf8`. The record's exact source layout is bool `valid` at `+0x00`, bool `chatTargetPending` at `+0x01`, implicit alignment `+0x02..+0x03`, int `chatHandleModeIndex` at `+0x04`, bool `secondaryChatEnabled` at `+0x08`, implicit alignment `+0x09..+0x0b`, and three paint-state ints at `+0x0c/+0x10/+0x14`; total size `0x18`.
- In the complete object that produces snapshot `+0xf8..+0x10f`, mouse capture `+0x110`, pending target `+0x111`, implicit alignment `+0x112..+0x113`, mode `+0x114`, secondary enable `+0x118`, three latch bytes `+0x119..+0x11b`, and paint-state ints `+0x11c/+0x120/+0x124`; final size `0x128`.
- No authored reserve/padding array is supported. Only natural C++ alignment is represented.
- Ten runtime functions outside this class directly read `m_chatTargetPending`, `m_chatHandleModeIndex`, or `m_secondaryChatEnabled`. Those three fields are therefore source-visible. Internal snapshot, capture flag, latches, paint fields, and retained helpers remain private. This access split is inferred but compile-required by the direct reads.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `IsRenderStateCurrent` | [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md) | Source-ready retained private helper at `90/93`: exact 89-byte valid-first six-field comparison of a `ChattingHandleRenderState` argument against active fields; no inbound route, but a complete `__thiscall` source body rather than selector or compiler glue. |
| `CaptureRenderState` | [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) | Source-ready retained private helper at `90/93`: exact 69-byte valid-first six-field copy to a caller-provided 24-byte record; no inbound route and historical marker-only coverage is superseded. |
| `ChattingHandlePane::ChattingHandlePane()` | [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md) | Source-ready constructor at `92/94`: `Pane(1)` plus direct `Singleton<ChattingHandlePane>`, config imports, `ScrollWidget::Enable/Disable`, and exact field initialization. Publication, adjusted-null arithmetic, vptrs, EH/cookie, and unwind clear are compiler output. |
| `ChattingHandlePane::~ChattingHandlePane()` | [UID:0002FS][0x00481d30-0x00481d59.ChattingHandlePaneDestructor](by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md) | Source-ready empty human destructor at `92/94`; vptr restores, Singleton clear, Pane teardown, scalar delete flags/size guard, and storage release are compiler output. |
| `OnMouseEvent` | [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) | First-draft C++ ready at `89/91`: handles inline hover rectangles, coordinate-based `GetChatButtonAtPoint` down/up hit-testing, pending-target/mode/secondary toggles, config writes, `ScrollWidget::Enable/Disable`, dependent-pane invalidation, and snapshot repaint invalidation. |
| `OnPaint` | [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md) | First-draft C++ ready at `89/91`: draws `CHATBUTT.EPF`/`CHATBUTT.PAL` frames for `(0,4)-(19,21)`, `(630,4)-(649,21)`, and `(649,4)-(668,21)` using `3 * paintState` plus pending/mode/secondary offsets, then refreshes `m_renderStateSnapshot`. |
| virtual forwarder | [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md) | Compiler-generated secondary-subobject forwarder retained as vtable/layout evidence, not handwritten source. |
| rectangle helper | [UID:0002FW][0x00482310-0x00482400.GetChatButtonRectRaw](by-memory/0x00482310-0x00482400.GetChatButtonRectRaw.md) | Source-ready `89/92` retained file-local `static void __stdcall GetChatButtonRect(int buttonIndex, RectBounds *outRect)` helper. It writes cases `0..3` or the invalid `-1` rectangle, does not consume `this`, and emits independently through Chatting.cpp despite zero inbound route. |
| [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) | `0x00482400-0x004824e0` | File-local helper for hit-testing chat handle regions; includes its switch jump table tail, now emits first-draft formal C++ at `89/92`, takes project hit-test order `mouseY, mouseX`, and does not take `this` or the pane/event object. |
| `ScalarDeletingDestructor` | `0x00483ba0` | Compiler wrapper only: restores vptrs, clears through direct Singleton destruction, invokes Pane teardown, interprets delete flags/size guard, and optionally frees storage. No handwritten ABI source. |

## Evidence Notes

- IDA MCP confirms exact boundaries for the constructor, destructor body, mouse handler, paint handler, tiny forwarder, raw rectangle helper, and hit-test helper.
- The recovered helper [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) hit-tests four hardcoded regions: left button, middle strip, middle-right button, and right button.
- Historical 2026-05-26 IDA recheck proved the helper is coordinate-based, not `this,eventData`. B006 2026-07-07 refines the source order: current MCP session `43ccf853` shows the call sites push `[event + 0x0c]` then `[event + 0x08]`, while the callee forwards its first coordinate to canonical `PointInRect(int y, int x, const RectBounds *bounds)`. Source calls should therefore use `GetChatButtonAtPoint(event->mouseY, event->mouseX)`, not older generated/stale `event->mouseX,event->mouseY` or `this,eventData` forms.
- 2026-05-31 IDA raw head review confirms `0x00482310-0x00482400` is a real rectangle-writing helper with switch table `jpt_482321`; no direct xrefs are exposed. B004's 2026-07-12 callback resolves it as a source-authored retained file-local helper, not a class member: full-dword index and output-pointer stack arguments, no incoming `this`, `retn 8`, canonical `RectBounds` output, explicit `-1,0..3` switch behavior, and exact four rectangles support independent source emission. UID000107, OnMouseEvent, and OnPaint still do not call it.
- 2026-05-31 IDA raw head review confirms `GetChatButtonAtPoint` has a switch jump table tail at `0x004824cc-0x004824e0`, so the by-memory page was renamed from the shorter `0x00482400-0x004824c8` range.
- Historical B002 2026-06-16 reanalysis correctly rerouted [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md) and [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) here from `ChattingVarietySelectPane`. Its then-current blank/marker-only final-C++ conclusion is superseded: exact receiver/record signatures and complete source bodies now emit as retained private helpers despite zero inbound routes.
- B003 2026-06-28 reanalysis raises [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) to first-draft C++ readiness at `89/91`. B006 2026-07-07 corrects the coordinate signature to `GetChatButtonAtPoint(int mouseY, int mouseX)`, rejects a live `GetChatButtonRectRaw` call from hover/down/up handling, keeps `m_chatTargetPending` as the class-side name for config-side `m_chatHandleLeftToggle`, and records `ScrollWidget::Enable/Disable` plus inherited pane invalidation as dependencies rather than owner moves.
- B014 2026-06-28 implementation raises [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md) to first-draft C++ readiness at `89/91`. It uses the B003 field names, exact `CHATBUTT.EPF` / `CHATBUTT.PAL` button frame formulas, shared render/helper dependencies, and inline snapshot writes; ownership and emitter remain with this class.
- B009 2026-06-29 implementation raises [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md) to source-ready constructor C++ at `90/92`. Current MCP session `b2ae72ec` reconfirmed exact range `0x00481c10-0x00481d2a`, size `0x11a`, eleven-byte prepad, six-byte postpad, one direct `sub_4F7D10` allocation/call site with `0x128` object size and placement rectangle `(74,727,740,751)`, `g_pChattingHandlePane` singleton store, config reads at `+0x28de7c/+0x28de80/+0x28de81`, `ScrollWidget::Enable/Disable` through `g_pChattingDisplayPane->m_scrollWidget`, field zeroing, and generated empty-marker cause as blank target C++; ownership and emitter remain with this class under [UID:0000I5][Chatting](by-file/Chatting.md).
- Historical B008 2026-06-29 implementation raised [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) to `87/91` and used marker-only coverage. Its exact bytes/padding/no-route/field evidence remains valid; only the no-source conclusion is superseded by the now source-ready retained `CaptureRenderState` body.
- B004's 2026-07-13 [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md) pass confirms another exact `+0x118` reader. Current-layout OnPaint directly loads `g_pChattingHandlePane->m_secondaryChatEnabled` without a null check; false skips GetClipRect and message iteration but still performs `SetDrawColor(0)` and `FillRect(&m_bounds)`. Legacy OnPaint does not read the field. This strengthens the existing field identity without changing class ownership, layout, constructor/config behavior, or formal C++.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md)
- [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md)
- [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md)
- [UID:0002FS][0x00481d30-0x00481d59.ChattingHandlePaneDestructor](by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md)
- [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md)
- [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md)
- [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md)
- [UID:0002FW][0x00482310-0x00482400.GetChatButtonRectRaw](by-memory/0x00482310-0x00482400.GetChatButtonRectRaw.md)
- [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md)
- [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md)
- [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md)

## Changes

- 2026-07-21 B002 UID0002XF callback: raised `86/90` to `92/94`, set position `10`, installed the complete Pane plus direct Singleton class/header declaration before `[[CHILDREN]]`, added exact enums/prototype/record/access/layout/padding, source-ready FP/FQ/lifecycle declarations, sole extern global, and full compiler/no-duplicate distinctions. Historical blank-helper and explicit publication/clear assumptions are retained as superseded evidence.
- 2026-07-13 B004 UID0002EV support synchronization: added ChattingPane::OnPaint as an exact direct `m_secondaryChatEnabled` reader, including the current-layout-only no-null-check gate and disabled background-fill/no-message-loop behavior. Class scores, metadata, formal C++, field offsets, owner/route, and all sibling methods remain unchanged at `86/90`.
- 2026-07-12 B004 UID0002FW support synchronization: updated the rectangle-helper row/evidence to source-ready `GetChatButtonRect(int buttonIndex, RectBounds *outRect)` at `89/92`, preserved file-local rather than member ownership, and preserved the independent no-call relation. Class scores, metadata, formal C++, fields, and sibling method content remain unchanged.
- 2026-07-07 B006 UID000107 support callback: updated the helper row and evidence notes for [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md). Current source order is `mouseY, mouseX`, formal body lives on UID000107 at `89/92`, UID0000SX is marker-only coverage, `GetChatButtonRectRaw` remains no-route, and current IDA session `43ccf853` labels the helper `sub_482400` rather than proving the source name.

- What existed before: the page documented handle behavior, methods, helper signature correction, and references, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: mouse, paint, config, helper, destructor, and generated-signature caveat are covered; field layout and final header form remain incomplete.
- 2026-05-31: Updated completion/confidence from `78/86` to `86/90` after splitting the exact handle cluster through `0x004824e0`, including constructor, destructor body, mouse, paint, forwarder, raw rectangle helper, and hit-test helper switch table tail. Evidence: IDA MCP function iteration, decompilation, vtable xrefs, raw head review, and padding audit.
- 2026-06-03: Reclassified the `0x00482300` secondary forwarder as compiler-generated layout/vtable glue rather than handwritten source. Evidence: [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md) records the IDA boundary, slot dispatch body, Wave2/Wave3 exclusion metadata, and disabled generated overlay.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and attached the class to [UID:0000I5][Chatting](by-file/Chatting.md). Current IDA MCP `lookup_funcs` reconfirmed constructor/destructor/mouse/paint/hit-test/scalar-destructor starts at `0x00481c10`, `0x00481d30`, `0x00481d60`, `0x00482150`, `0x00482400`, and `0x00483ba0`, and `callers` shows construction from main chat UI initialization. Both class (`86/90`) and file (`83/87`) clear the 80+ attachment gate; reconstruction C++ remains blank pending final class layout and field names.
- 2026-06-16: Added [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md) and [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) as retained no-route render-state helpers after B002 field/source-owner reanalysis; final C++ remains blank pending source-grade helper signatures.
- 2026-06-28 B003 Rule 26 implementation: added the accepted field map for `m_renderStateSnapshot` and active handle state, marked `OnMouseEvent` first-draft C++ ready at `89/91`, and aligned method/support prose with the `m_chatTargetPending` / `m_chatHandleLeftToggle` dual-role byte, coordinate hit-test helper, secondary scroll-widget dependency, and dependent-pane invalidation behavior.
- 2026-06-28 B014 implementation callback: marked `OnPaint` first-draft C++ ready at `89/91`, recorded exact handle-button rectangles/frame formulas and rendered-state snapshot writes, and preserved existing ownership/emitter/file route.
- 2026-06-29 B009 implementation callback: marked the constructor source-ready at `90/92`, inserted the accepted formal body in the exact child page, and recorded current `b2ae72ec` proof for range/size/padding, sole allocation call site, object size, placement rectangle, singleton store, config imports, scroll-widget branch, zeroed state fields, compiler vtable writes, and unchanged [UID:00001V] / [UID:0000I5][Chatting](by-file/Chatting.md) owner/emitter route.
- 2026-06-29 B008 implementation callback: updated the UID0002FQ method/support notes with marker-only no-standalone-helper disposition, current `b2ae72ec` no-route evidence, paired UID0002FP comparison support, and UID0002FU OnPaint inline snapshot-write coverage. Class score remains `86/90`.
