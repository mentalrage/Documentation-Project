*** UID:00001W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct PaneMouseEvent;

class ChattingModifyHeightPane : public Pane,
                                 public Singleton<ChattingModifyHeightPane>
{
public:
    ChattingModifyHeightPane();
    virtual ~ChattingModifyHeightPane();

    void SetLineCount(int requestedLineCount);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    bool m_dragActive;
    int m_dragAnchorY;
    RectBounds m_handleRect;
};

extern ChattingModifyHeightPane *g_pChattingModifyHeightPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChattingModifyHeightPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Source position: `10`, after the source module's global definitions.
- Direct bases: `Pane`, then `Singleton<ChattingModifyHeightPane>`; the second base is proven by RTTI and PMD `+0xf8`.
- Current recovered file: `source-3/simroot_v2/class_ChattingModifyHeightPane.cpp`

## Class Purpose

`ChattingModifyHeightPane` is the draggable chat-height handle. It lets the user change the number of visible chat rows, updates the scroll viewport/display pane, repositions the handle, stores the line count in config, and cancels/restores an in-progress drag when modal server packet events arrive.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingModifyHeightPane` | [UID:0002F4][0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor](by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md) | Constructs the handle pane and initializes its fixed rectangle. |
| `~ChattingModifyHeightPane` body | [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md) | Empty ordinary source destructor. The binary restores three class vtables, then implicit `Singleton<ChattingModifyHeightPane>` base destruction clears the global before ordinary `Pane::~Pane()` runs. Scalar deleting and unwind wrappers live in [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md) and are compiler output. The older explicit-clear source body is superseded. |
| `OnMouseEvent` | [UID:0002F6][0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent](by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md) | Handles drag start, drag preview, and drag release line-count calculation. |
| `HandlePacketEvent` | [UID:0002F7][0x00480a80-0x00480ac5.ChattingModifyHeightPaneHandlePacketEvent](by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneHandlePacketEvent.md) | EventHandler secondary-slot `+0x10` override; packet opcodes `0x2f`, `0x30`, and `0x42` unconditionally clear `m_dragActive`, restore `m_handleRect`, invalidate inherited `m_bounds`, and return false. |
| external BackPane viewport update | [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) | Called from `OnMouseEvent` at `0x0048093e`; direct owner/emitter is now [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md), because the receiver is `g_pChattingBackPane` and the method mutates BackPane geometry. |
| `SetLineCount` | [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md) | Applies the visible line count, resizes the chat viewport/display pane, and positions the handle. |
| `OnPaint` | [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) | First-draft paint C++ ready at `88/92`; gates on `g_pChattingHandlePane->m_secondaryChatEnabled` (`+0x118`), draws `CHATSC.EPF` frame `0` with `invenbut.pal` into the inherited pane bounds at `this+0x44`, passes `tile + 0x10` / `tile.m_bounds` as the EPF source rectangle, and otherwise performs inactive/clear refresh with `Pane::SetMode(1)`, `SetGrafPortColorState(0)`, and `dword_69B3FC(this,this+0x44)`. |
| `ScalarDeletingDestructor` | `0x00483c00` | Compiler wrapper that lowers implicit Singleton clearing, ordinary destruction, optional delete, and ABI mechanics; it is not another source method. |

## Field Notes

The resize/input virtuals use a secondary event-interface `this` pointer at full object `+0xa0`. Normalize secondary offsets before naming fields:

| Full-object offset | Secondary-view offset | Recommended name | Role |
| --- | --- | --- | --- |
| `+0xf8` | `+0x58` | `m_dragActive` | Set on left-button down, tested during move/up, cleared on commit/cancel. |
| `+0xfc` | `+0x5c` | `m_dragAnchorY` | Initial vertical drag coordinate used for preview/commit top math. |
| `+0x100` | `+0x60` | `m_handleRect` | Current/committed handle rectangle, hit-tested and restored on cancel. |

`m_handleRect` is the class-local resize geometry field maintained by the constructor, drag, packet-cancel, and `SetLineCount` paths. The exact initialization allocation pushes `0x110` bytes immediately before the sole constructor call at `0x004f7f71`. Direct RTTI names `Singleton<class ChattingModifyHeightPane>` and its base descriptor records PMD `(248, -1, 0, 64)`, placing the empty direct base at complete-object `+0xf8`. Empty-base optimization lets `m_dragActive` also occupy `+0xf8` because the member is not the Singleton type. Normal VC-era alignment then supplies implicit padding at `+0xf9..+0xfb`, places `m_dragAnchorY` at `+0xfc`, and places the 16-byte `m_handleRect` at `+0x100..+0x10f`; the object therefore ends exactly at `+0x110`. The empty base and compiler-supplied three-byte gap are not explicit data members.

[UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) does not pass `m_handleRect` directly; it computes and passes the inherited `Pane` rectangle at full-object offset `+0x44` to both the enabled `RenderTileFrame` branch and the disabled `dword_69B3FC` refresh branch. UID0002F7 also uses inherited `m_bounds` at complete `+0x44`, but restores the distinct class-local `m_handleRect` at `+0x100` first.

## EventHandler Secondary Vtable Contract

The secondary EventHandler subobject begins at complete-object `+0xa0`. Incoming secondary `this` adjustment back to the complete object is compiler lowering; source methods use ordinary `this`.

| Secondary slot / table cell | Target | Source role |
| --- | --- | --- |
| `+0x00` / `0x00614e64` | `0x00483a43` | Compiler adjustor for scalar deleting destructor; no handwritten source body. |
| `+0x04` / `0x00614e68` | `0x00480890` | UID0002F6 `OnMouseEvent`. |
| `+0x08` / `0x00614e6c` | `0x00544dc0` | Inherited key/text EventHandler family. |
| `+0x0c` / `0x00614e70` | `0x00544dd0` | Inherited IME EventHandler family. |
| `+0x10` / `0x00614e74` | `0x00480a80` | UID0002F7 `HandlePacketEvent(Event *)`. |
| `+0x14` / `0x00614e78` | `0x00544df0` | Inherited system/control event family. |
| `+0x18` / `0x00614e7c` | `0x00544e00` | Inherited exact type-19 event family. |
| `+0x1c` / `0x00614e80` | `0x004a89f0` | `EventHandler::ForwardHandlerOrder`. |
| `+0x20` / `0x00614e84` | `0x00544e10` | Inherited local pair-output query. |
| `+0x24` / `0x00614e88` | `0x00544e30` | Inherited screen pair-output query. |
| `+0x28` / `0x00614e8c` | `0x00544e70` | Inherited `ShouldAcceptEvent` predicate. |

The constructor writes primary, secondary, and tertiary vtables at complete offsets `+0`, `+0xa0`, and `+0xa4`. UID0002F7's primary virtual calls resolve `+0x2c -> Pane::SetBounds` (`0x00544bd0`) and `+0x20 -> Pane::InvalidateRect` (`0x00544800`). Source reconstruction keeps the ordinary declarations and bodies while excluding vptr stores, vtable arrays, RTTI, adjustors, explicit `this - 0xa0`, scalar-delete logic, and alignment bytes.

## Singleton Lifetime And Source Split

The constructor computes the Singleton subobject at complete `this+0xf8`, performs the null-preserving adjustment back to the complete object, and stores [UID:0002X1][g_pChattingModifyHeightPane](by-global/g_pChattingModifyHeightPane.md). This is old-MSVC lowering of direct empty Singleton base construction. Human source therefore lists `Singleton<ChattingModifyHeightPane>` as the second direct base and does not contain an explicit global assignment.

With direct bases declared as `Pane` then Singleton, destruction runs them in reverse after the empty derived body. The Singleton base clears the global, then `Pane` tears down. That order matches the ordinary destructor at `0x00480860`, constructor-unwind cleanup at `0x004839d0`, and scalar wrapper at `0x00483c00`. Vptr restoration, adjusted-null handling, EH state, cleanup funclets, delete flags, optional delete, and the implicit base calls remain compiler output.

The class block contains the complete current method/field surface, the direct base list, and the header-facing external declaration. `[[CHILDREN]]` follows the class closing brace and external declaration so validator-emitted method definitions compile against the complete class. [UID:0002X1][g_pChattingModifyHeightPane](by-global/g_pChattingModifyHeightPane.md) emits the sole source definition; [UID:0002X2][0x0067add4-0x0067add8.g_pChattingModifyHeightPane](by-memory/0x0067add4-0x0067add8.g_pChattingModifyHeightPane.md) is false/non-emitting.

## Evidence Notes

- IDA MCP confirms exact functions and `0xcc` padding across `0x004807b0-0x00480c50`.
- IDA MCP recheck on 2026-05-26 confirms generated `BackPane::SetScrollViewport` at `0x004806d0` has exactly one direct caller, `ChattingModifyHeightPane::OnMouseEvent` at `0x0048093e`; treat it as chat viewport layout support despite the current generated owner.
- 2026-05-31 IDA MCP decompilation confirms drag line-count formula `(710 - clampedY) / 13`, clamps visible lines to at least `4`, and stores the resulting count at `dword_67A7C8 + 2678392`.
- 2026-05-31 IDA MCP render evidence confirms the paint method uses `CHATSC.EPF` and `invenbut.pal`.
- Historical 2026-06-15 Wave2 method-analysis correctly identified the `0x004807b0-0x00480c45` class cluster, `Pane` base context, and handle rectangle beginning at `this + 0x100`, but its `528` / `0x210` size claim is superseded by the live `push 0x110` allocation immediately before construction and the exact tail ending at `+0x110`.
- 2026-06-15 live IDA MCP reconfirms `sub_480AD0` at `0x00480ad0-0x00480ba3`, sole direct caller `0x004f7fd5`, calls to the bounds helper, rectangle helper, [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md), and the exact handle/back-pane rectangle stores used by the class' drag-height behavior.
- 2026-06-17 B001 source-quality execution resolves first-draft field/source names for the resize handle: `m_dragActive`, `m_dragAnchorY`, `m_handleRect`, `g_pChattingHandlePane->m_secondaryChatEnabled`, and `g_pConfig->m_chatVisibleLineCount`. It also moves [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) to direct `ChattingBackPane` ownership while preserving this class as the sole caller.
- 2026-06-21 B011 Rule 26 incorporation resolves [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) as first-draft C++ ready. The method is a `ChattingModifyHeightPane` vtable paint slot, not `ChattingBackPane` or EPF helper ownership; it uses `g_pChattingHandlePane->m_secondaryChatEnabled`, shared `g_pEPFLib`/`RenderTileFrame`, `CHATSC.EPF`, `invenbut.pal`, `Pane::SetMode(1)`, `GrafPort::SetDrawColor(0)`, and the shared surface slot `0x0069b3fc` to refresh the handle/bounds rectangle. Exact render-helper and rectangle member spellings remain final-polish details.
- 2026-06-22 B011 exact [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) incorporation corrects the paint destination from the class-local `m_handleRect` at `+0x100` to the inherited `Pane` rectangle at `this+0x44`. The `+0x100` field remains the committed handle geometry source for layout and drag behavior; the paint body directly consumes `+0x44`, uses `FrameDrawRecord` scratch for the enabled tile render, and treats the disabled branch as inactive/clear refresh rather than a hidden/transparent setter.
- 2026-06-22 B015 [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) source-quality verification raises the paint child to `88/92` and this class page to `88/92`. B015 confirms the exact raw range `0x0007ffb0-0x00080045`, target-byte SHA-256 `be3b5b7def9e1dbfe1d0e0ccc2039407ad00e694af5e1ecc5df9002c7af42a2f`, vtable-only liveness through `0x00614e5c`, no direct external code callers, and corrects the enabled render source rectangle to `tile + 0x10` / `tile.m_bounds` rather than an independent scratch record. The disabled branch remains an inactive/clear refresh path: mode `1`, draw/fill color `0`, and surface slot-7 fill/refresh over inherited bounds.
- 2026-06-18 B005 destructor-cluster source-quality pass resolves [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md) as ordinary `ChattingModifyHeightPane::~ChattingModifyHeightPane()`. The inherited base cleanup target is ordinary `Pane::~Pane()` at `0x00544580`, not `TextButtonExControlPane` teardown; vtable stores, scalar deleting wrapper, adjustors, optional delete, and the implicit base destructor call are compiler output.
- 2026-07-14 B001 UID0002F7 reanalysis resolves the formerly named cancel/key helper as EventHandler packet override `HandlePacketEvent(Event *)`. Complete target bytes, secondary cell `0x00614e74`, EventDispatcher packet slot `+0x10`, Event packet data at `+0x0c`, modal opcodes `0x2f/0x30/0x42`, complete-object `+0xa0` adjustment, primary slots `+0x2c/+0x20`, and false return are current source-shape evidence. There is no key/text payload, guard, direct caller/callee, or alternate owner.
- Exact allocation/layout proof comes from `push 0x110` at the initializer immediately before allocator/constructor call `0x004f7f71`, plus constructor vtable stores at `+0/+0xa0/+0xa4`, byte clear at `+0xf8`, and rectangle initialization through `+0x10f`. This supersedes only the old `0x210` size, not the valid historical method, field, or paint/destructor evidence.
- 2026-07-21 direct RTTI recheck establishes the missing source base: `Singleton<class ChattingModifyHeightPane>` appears in the hierarchy, its PMD places it at `+0xf8`, and constructor/destructor order explains all five global lifetime references. The older explicit constructor publication and explicit ordinary-destructor clear are retained only as superseded source-shape interpretations.

## Score Rationale

Completion is `92` because the class now has a complete source declaration, exact constructor/destructor/mouse/packet/set-line-count/paint children, exact `0x110` size and tail layout, complete secondary EventHandler table, primary virtual identities, owner/emitter/source route, compiler-artifact exclusions, and historical corrections. Confidence is `94` because live allocation, constructor, function, dispatcher, vtable, sibling, and current interface evidence converge. Unavailable original private member/header spelling and protocol constant spelling cap the score below final-symbol certainty without blocking reconstruction.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001X][ChattingPane](by-class/ChattingPane.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)
- [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md)
- [UID:0002F4][0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor](by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md)
- [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md)
- [UID:0002F6][0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent](by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md)
- [UID:0002F7][0x00480a80-0x00480ac5.ChattingModifyHeightPaneHandlePacketEvent](by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneHandlePacketEvent.md)
- [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md)
- [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md)

## Changes

- 2026-07-21 B005 UID0002X2 source-quality callback: preserved `92/94` and the complete current class/method/field/history union, set source position `10`, added direct `Singleton<ChattingModifyHeightPane>` inheritance and the external pointer declaration, and documented PMD `+0xf8`, EBO, exact `0x110` layout, implicit publication/clearing, source/compiler boundaries, and one-definition placement. The managed block keeps `[[CHILDREN]]` outside the closed class.
- What existed before: the page documented drag/line-count behavior and helper ownership, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/86`.
- Summary and evidence: constructor, mouse handling, viewport helper, line count, paint, and destructor are covered; detailed fields and final layout remain incomplete.
- 2026-05-31: Updated completion/confidence from `76/86` to `82/90` after adding exact by-memory pages for every function in the `0x004807b0-0x00480c50` cluster and replacing raw address rows with UID references. Evidence: IDA MCP function iteration, decompilation, xrefs, vtable data xrefs, render strings, and padding audit.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and attached the class to [UID:0000I5][Chatting](by-file/Chatting.md). Current IDA MCP `lookup_funcs` reconfirmed constructor/destructor/mouse/set-line-count/paint/scalar-destructor starts at `0x004807b0`, `0x00480860`, `0x00480890`, `0x00480ad0`, `0x00480bb0`, and `0x00483c00`, and `callers` shows construction from main chat UI initialization. Both class (`82/90`) and file (`83/87`) clear the 80+ attachment gate; reconstruction C++ remains blank pending final class layout and field names.
- Historical 2026-06-15 A001 Goal 2: raised from `82/90` to `85/90` after Wave2 method/filter/struct review and live IDA MCP reconfirmed the full class cluster, `this + 0x100` handle rectangle field, `SetLineCount` caller/effects, and direct [UID:0000I5][Chatting](by-file/Chatting.md) route. That pass's `0x210` size and blank-class-C++ conclusions are superseded by the 2026-07-14 exact `0x110` allocation/layout and complete managed declaration; its cluster/field/caller/owner facts remain valid history.
- 2026-06-17 B001 source-quality execution: raised `85/90` to `87/91`, added field notes for `m_dragActive`, `m_dragAnchorY`, and `m_handleRect`, moved [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) to `ChattingBackPane` ownership, and recorded that constructor/mouse/cancel/set-line-count children now carry first-draft C++.
- 2026-06-21 B011 Rule 26 incorporation: no class score change. [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) now carries first-draft C++ at `86/91`, resolving the stale blank-C++ blocker for paint while preserving shared render-helper spelling as a nonblocking integration caveat.
- 2026-06-22 B011 exact [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) Rule 26 incorporation: no class score change. The paint child now carries `87/92` and its draft C++/support prose correctly use inherited pane bounds `this+0x44` rather than `m_handleRect` at `+0x100`; the old rectangle wording is retained as a corrected historical assumption.
- 2026-06-22 B015 [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) Rule 26 verification: raised class metadata to `88/92` after incorporating B015's raw PE/vtable recheck and source-rectangle correction. The paint child now carries `88/92`; enabled rendering uses `tile.m_bounds` (`tile + 0x10`) as the source rectangle, and the disabled path remains active clear/suppression rather than visibility-byte evidence.
- 2026-07-14 B001 UID0002F7 callback: raised `88/92` to `92/94`, inserted the complete `ChattingModifyHeightPane : Pane` declaration with post-class `[[CHILDREN]]`, corrected UID0002F7 to `HandlePacketEvent(Event *)`, documented the exact `0x110` layout and eleven-slot secondary table, and historicalized the superseded Wave2 `0x210` and key-event interpretations while preserving all prior child work.
