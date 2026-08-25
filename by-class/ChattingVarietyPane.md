*** UID:00001Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingVarietySelectPane;
class Event;

class ChattingVarietyPane : public Pane
{
public:
    ChattingVarietyPane();
    virtual ~ChattingVarietyPane();
    void Refresh();

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual void OnPaint();

private:
    void GetItemRect(int itemIndex, RectBounds *outRect);
    signed char HitTest(int mouseY, int mouseX);

    unsigned char m_compactButtonState;
    ChattingVarietySelectPane *m_selectPane;
};

extern ChattingVarietyPane *g_pChattingVarietyPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChattingVarietyPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Generated/simroot lead file, not authoritative recovered source: `source-3/simroot_v2/class_ChattingVarietyPane.cpp`
- Autogen handling: attached to [UID:0000I5][Chatting](by-file/Chatting.md) as source-owned class code. Formal class C++ is declaration-only; exact method/helper bodies remain owned by the by-memory children. Current generated/simroot output is owner-polluted lead material only and does not override the accepted first-draft constructor C++ on [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md).
- Source declaration closure: the class is closed before `[[CHILDREN]]`, and the source global is exposed once as `extern ChattingVarietyPane *g_pChattingVarietyPane;`. This keeps child definitions outside the class and pairs with the single position-zero definition on [UID:0002X5][g_pChattingVarietyPane](by-global/g_pChattingVarietyPane.md).
- Layout facts represented in prose rather than emitted comments: `m_compactButtonState` is at `+0xf8`, normal pointer alignment supplies three implicit bytes at `+0xf9..+0xfb`, `m_selectPane` is at `+0xfc`, and the constructor caller allocates `0x100` bytes. No authored reserve member is emitted; the names/types in the formal declaration are source-facing while reverse-engineering offsets remain evidence only.
- Pointer-event/source closure: the EventHandler secondary-facet slot is the canonical `HandlePointerOrMouseEvent(Event *)` override. Private `GetItemRect` and `HitTest` declarations pair the retained UID0002FF/UID0002FG bodies with this class; their unused receiver and no-direct-xref status are optimizer evidence because UID0002FC contains their behavior-identical inline expansion.

## Class Purpose

`ChattingVarietyPane` is the compact chat-mode button. It displays the current chat mode label and opens or dismisses `ChattingVarietySelectPane` when clicked.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingVarietyPane` | [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md) | First-draft constructor C++ now emits on the child: `Pane(1)`, `g_pChattingVarietyPane = this`, and `m_compactButtonState = 0`; compiler-generated vtable stores remain omitted. |
| destructor body | [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md) | Ordinary source destructor; binary restores three class vtables, clears `g_pChattingVarietyPane`, and compiler-chains to ordinary `Pane::~Pane()`. Source body is `g_pChattingVarietyPane = NULL;`; scalar deleting wrapper lives in [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md). |
| `HandlePointerOrMouseEvent` | [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md) | Complete canonical Event override with UserPane input-lock and left-button gates, private compact `HitTest(y,x)`, selector create/delete paths, exact bounds/layer/order setup, invalidation, and true/false returns. |
| `OnPaint` | [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md) | Source-ready paint override: initializes a borrowed `EPFTileContext`, sets text-back fill to 0, resolves `CHATVAR.EPF` through the ImageLib/ResourceLayoutTable compatibility API, selects frame 0/1 from `g_pChattingVarietySelectPane`, renders `CHATVAR.PAL`, maps `UserPane::m_currentSayMode` values 0..4 to Talk/Shout/Whisper/Group/Clan without a fabricated fallback, sets text color 128, and double-strikes centered text at `x+1` then `x` with unchanged draw state. The exact child emits the method body; this class already owns its declaration. |
| `Refresh` | no independent handwritten body | Source-facing no-argument dependency used by [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) and the existing selector/cleanup callers. The observed operation is exact pane bounds invalidation through virtual slot `+0x48`, but `Refresh` is an inferred, project-style lexical name rather than an original recovered symbol. |
| secondary forwarder | [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md) | Compiler-generated secondary-subobject forwarder retained as vtable/layout evidence, not handwritten source. |
| compact button rectangle helper | [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) | `90/93` retained/inlined private `GetItemRect(int,RectBounds *)`; writes compact `(0,0,62,24)` for item 0 and an empty rectangle otherwise, with complete source C++. |
| compact button hit-test helper | [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) | `90/93` retained/inlined private `HitTest(mouseY,mouseX)`; tests one compact item through `GetItemRect`/`PointInRect`, returning signed 0 or -1 with complete source C++. |
| `ScalarDeletingDestructor` | `0x00483d50` | Clears `g_pChattingVarietyPane`. |

- Paint dependency: `0x004b9670` is shared `GrafPort::SetTextBackFillColor`, an exact [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) helper that stores zero at inherited field `+0x78`. It is not a draw/display-mode write to `+0x70`, not a `ChattingVarietyPane` method, and must not be duplicated under this class. The later `0x004b9680` call is shared `GrafPort::SetTextColor(128)` over `+0x7c`.

## Evidence Notes

- 2026-08-05 B006 UID0002FD source-closure callback: [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md) now carries exact method-only first-draft C++ at `94/94`. The complete body is `[0x00480e80,0x00480ff1)`, 369 bytes, SHA256 `51D838D5125C26AC11DAA7357271B5BD6CC20884638CE1EC66560862E0F60679`, reached only through primary-vtable slot `0x00614ee4`; the trailing 15-byte `0xcc` fence and UID0002FE forwarder remain outside the method.
- The source sequence is closed: initialize a borrowed 0x28-byte `EPFTileContext`; call `SetTextBackFillColor(0)`; resolve `CHATVAR.EPF` with frame `g_pChattingVarietySelectPane != NULL`; render with context bounds, pane bounds, zero draw argument, `CHATVAR.PAL`, and null final pointer; map `g_pUserPane->m_currentSayMode` cases 0..4 to Talk/Shout/Whisper/Group/Clan through bounded copies; obtain the source `wcslen`; call `SetTextColor(128)`; and draw centered text at `x+1` and `x` without a state change between passes.
- The absent default branch and absent context release/destructor/EH cleanup are behaviorally significant. The stack context is a borrowed initialized view, and the same-state double draw is overdraw rather than a separately colored shadow/foreground effect. Adding a fallback label, cleanup, draw-mode write, or color transition would diverge from the executable.
- Source placement remains this class under [UID:0000I5][Chatting](by-file/Chatting.md). [UID:0000FQ][UserPane](by-class/UserPane.md) owns `m_currentSayMode`; [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) owns the shared `SayInputMode` declaration in `SayInputPanes.h`; [UID:00006E][ImageLib](by-class/ImageLib.md) owns the non-virtual resource API and `g_pEPFLib` declaration; GrafPort and EPFTileContext keep their shared definitions. None of those dependencies moves ownership or requires a duplicate declaration in this class.
- Historical OnPaint prose describing `0x004b9670` as a display-mode setter and the two text passes as separate shadow/foreground colors is superseded by the exact field stores and unchanged draw state. The earlier blank-C++ dependency blocker is likewise superseded; original lexical spellings remain a confidence cap only.
- 2026-07-21 B004 UID0002X6 source-closure reanalysis proves the class/global boundary. The constructor at `0x00480c50` publishes `this` to `g_pChattingVarietyPane` at `0x00480c75` and clears only `m_compactButtonState` at `+0xf8`; the ordinary destructor at `0x00480ca0` clears the same global at `0x00480cba`. No constructor write proves an initializer for `m_selectPane`, so the constructor child remains unchanged. The physical singleton storage is loader-zeroed compiler/linker output on UID0002X6; the semantic source definition is UID0002X5.
- The complete 18-reference singleton graph preserves the current class contract: selector branches and dismissal, [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) and close/reset, `MapPane` exit, SelectObject/TargetObject cleanup, and NewSay cleanup all read the pointer and invoke or guard pane behavior. The current-layout constructor stores itself in `g_pUserPane->m_activeLineInputPane` before issuing the no-argument `Refresh()` call; the legacy branch omits both operations. The exact behavior is bounds invalidation through the established virtual route. `Refresh()` is retained as the strongest human source-facing inference and must not be replaced by raw slot or forwarder labels. The compiler scalar deleting wrapper's additional clear is lifecycle evidence only and does not justify a source-visible deleting destructor.
- Source-quality score is now `90/93`: class inheritance, public/protected surface, field order/types, size bound, ordinary constructor/destructor, singleton declaration, source owner, and child ordering are closed. Residual uncertainty is limited to the semantic name of the otherwise unobserved `+0xf8` byte. Fresh negative-access evidence and ordinary 32-bit pointer alignment resolve `+0xf9..+0xfb` as implicit compiler padding rather than an authored source member.
- IDA MCP confirms exact local constructor, destructor body, mouse handler, paint method, and small `0x00481000` helper.
- IDA MCP vtable data xrefs tie `0x00480cd0`, `0x00480e80`, and `0x00481000` to the `ChattingVarietyPane` vtable area.
- IDA decompilation uses labels `Shout`, `Whisper`, `Group`, and `Clan`, with the default label likely `Talk`, directly tying the class to chat/social mode selection.
- 2026-06-03 review keeps the unmodeled `0x00481010` and `0x00481060` helpers with this compact pane because both use the same `(0,0,62,24)` button rectangle as `OnMouseEvent`; the popup selector's six-row geometry is handled by [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) and [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).
- 2026-06-17 B003 source-quality reanalysis established the declaration-only `Pane` shell, field layout, and child route. The 2026-07-21 B002 closure preserves that union while replacing historical `PaneMouseEvent`/`OnMouseEvent` spelling with canonical `Event *`/`HandlePointerOrMouseEvent` and declaring both retained compact helpers privately. Method bodies remain on exact children.
- Historical 2026-06-23 B001 helper evidence remains accepted: no modeled helper functions/xrefs, exact padding, compact geometry, stack-cookie hit body, 0/-1 returns, and selector-row rejection. The 2026-07-21 B002 source-shape closure supersedes only its blank-C++ disposition: the paired private member declarations and UID0002FC live inline identity support complete source definitions while preserving every negative route fact.
- `dword_67A748 + 0x3eb4` is best named `currentChatMode` / `currentChatVarietyMode` with values Talk/Shout/Whisper/Group/Clan. `dword_67A748 + 0x13eb1d` is a broader local-player/UserPane input-lock byte, not a chat-owned global.
- `g_pChattingVarietyPane` and `g_pChattingVarietySelectPane` are resolved through [UID:0002X5][g_pChattingVarietyPane](by-global/g_pChattingVarietyPane.md)/[UID:0002X6][0x0067add8-0x0067addc.g_pChattingVarietyPane](by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md) and [UID:0002XA][g_pChattingVarietySelectPane](by-global/g_pChattingVarietySelectPane.md)/[UID:0002XB][0x0067addc-0x0067ade0.g_pChattingVarietySelectPane](by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md). MCP session `b880584f` still reports no inbound route to the compact raw helper starts, so their child pages keep the no-direct-route caveat and blank C++ even though [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) and [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) now clear the above-85 documentation score.
- 2026-06-18 B005 destructor-cluster source-quality pass resolves [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md) as ordinary `ChattingVarietyPane::~ChattingVarietyPane()`. The inherited base cleanup target is ordinary `Pane::~Pane()` at `0x00544580`; vtable stores, scalar deleting wrapper, adjustors, optional delete, and the implicit base destructor call are compiler output.
- 2026-06-29 B001 constructor empty-emitter implementation resolves [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md) as first-draft constructor C++ ready at `90/93`. Current MCP session `B006_0002F1_20260629` reconfirms modeled `sub_480C50` size `0x4f`, one-byte `0xcc` postpad, sole caller `sub_4F7D10` allocating `0x100` bytes and placing the pane at `(10,727,72,751)`, sole base `Pane` constructor callee `0x00544460` with argument `1`, `g_pChattingVarietyPane` store at `0x0067add8`, `m_compactButtonState` clear at `+0xf8`, and the three `ChattingVarietyPane` vtable stores as compiler output. The child formal body is `ChattingVarietyPane::ChattingVarietyPane() : Pane(1) { g_pChattingVarietyPane = this; m_compactButtonState = 0; }`; it intentionally does not initialize `m_selectPane` because no write to `+0xfc` exists in this constructor. The generated/simroot file line above is preserved only as non-authoritative lead material.
- B002 2026-07-21 post-callback ABI repair rechecked live MCP session `9b0396a3`: the constructor writes only `m_compactButtonState` at `+0xf8`; the complete Chatting-family scan has zero `+0xfa` or `+0xfb` accesses and only the expected `m_selectPane` accesses at `+0xfc`; and ordinary four-byte pointer alignment explains `+0xf9..+0xfb` plus the exact `0x100` object size. The earlier `m_reservedF9[3]` declaration was a reverse-engineered offset placeholder without read/write/init/serialization evidence and is superseded by implicit compiler padding.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md)
- [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md)
- [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md)
- [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md)
- [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md)
- [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md)
- [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md)
- [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md)

## Changes

- 2026-08-05 B006 UID0002FD source-quality callback:
  - Kept class score `90/93`, owner/emitter, formal declaration, size, fields, constructor/destructor/mouse/helper surface, and all unrelated evidence unchanged.
  - Corrected the shared `0x004b9670` dependency to `SetTextBackFillColor(0)` at `+0x78`, documented `SetTextColor(128)` at `+0x7c`, and replaced the compact OnPaint row with the exact resource/frame/mode/lifetime/coordinate/double-strike behavior.
  - Added full source-closure evidence for the method-only child C++, parent declaration ownership, UID0002RX shared-enum ownership, external dependency direction, exact range/hash/fence, and superseded display-mode/shadow/blank-C++ assumptions.
- 2026-07-30 B008 UID00035P ordinary callback: added the source-facing no-argument `Refresh()` declaration and documented its exact bounds-invalidation behavior, current-layout LineInputPane constructor consumer and ordering, lexical-inference limit, and separation from the compiler-generated UID0002FE forwarder. Score, ownership, layout, and existing child bodies remain unchanged.
- 2026-07-21 B002 UID0002XB source-quality callback:
  - Preserved the complete B004 `90/93` class/global/layout/constructor/destructor union and all unrelated evidence.
  - Rebased the formal declaration to canonical `Event *` / `HandlePointerOrMouseEvent`, added private `GetItemRect`/`HitTest` declarations, and source-closed UID0002FC/FF/FG without changing the exact `0x100` layout or existing children. No method body was moved into the class block.
  - Post-callback ABI repair removed the unsupported historical `m_reservedF9[3]` source member. Exact `+0xf9..+0xfb`, `m_selectPane +0xfc`, and `0x100` layout facts remain documented as normal implicit pointer alignment.
- 2026-07-21 B004 UID0002X6 source-closure callback:
  - Raised the class to `90/93` and preserved all existing method, child, compiler-glue, helper, and source-route evidence.
  - Rebased the complete formal class union without loss, removed reverse-engineering offset comments from emitted C++, closed the class before `[[CHILDREN]]`, and added the one source declaration `extern ChattingVarietyPane *g_pChattingVarietyPane;`.
  - Kept offsets `+0xf8`, `+0xf9..+0xfb`, `+0xfc`, the `0x100` allocation, exact lifecycle stores, 18-reference liveness graph, compiler-wrapper exclusion, field-name confidence cap, and padding caveat in prose.
- 2026-06-23 B001 [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) implementation callback:
  - Class score remains `87/92`.
  - Refreshed compact-hit-test evidence from MCP session `b880584f`: [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) is now `86/92`, remains owned/emitted by this class, and stays blank-C++ because no current caller/pointer/table/source-declaration route proves the original declaration shape.
  - Preserved compact-versus-selector routing: [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) is a one-candidate compact `(0,0,62,24)` hit-test returning byte `0` or `0xff`/signed `-1`; selector row geometry remains [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) and [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).

- 2026-06-23 B001 [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) implementation callback:
  - Class score remains `87/92`.
  - Refreshed compact-helper evidence from MCP session `b880584f`: [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) is now `86/92`, remains owned/emitted by this class, and stays blank-C++ because no current caller/pointer/table route proves the original declaration shape.
  - Preserved compact-versus-selector routing: [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) and [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) are compact-button helpers matching `ChattingVarietyPane::OnMouseEvent`; selector row geometry remains [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) and [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).

- 2026-06-17 B003 source-quality execution:
  - Before: score was `82/90`, formal C++ was blank, and the method table still treated `0x004b9670` as a possible class helper.
  - After: raised to `87/92`, populated declaration-only class C++, removed `0x004b9670` from the owned method list, and documented it as a shared [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) dependency.
  - Evidence: B003 rechecked constructor/destructor/mouse/paint names, singleton lifecycle, compact-vs-selector raw helper ownership, `currentChatMode` at `dword_67A748+0x3eb4`, local-player input-lock gate at `+0x13eb1d`, generated-output owner pollution, compiler forwarder exclusion, and declaration-only first-draft C++ safety.

- What existed before: the page documented mode-button behavior and method anchors, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/86`.
- Summary and evidence: constructor, toggle behavior, paint/init, mode labels, and destructor are covered; field layout and final method names remain light.
- 2026-05-31: Updated completion/confidence from `72/86` to `82/90` after adding exact by-memory pages for the constructor, destructor body, mouse handler, paint method, and tiny refresh forwarder. Evidence: IDA MCP function boundaries, decompilation, xrefs, vtable data audit, render strings, mode labels, and padding audit.
- 2026-06-03: Marked the class source-owned reconstructable, attached it to [UID:0000I5][Chatting](by-file/Chatting.md), and added the raw compact-button rectangle and initial hit-test helpers at `0x00481010` and `0x00481060` to the method list. Evidence: both helpers are source-owned raw bodies between compact-pane padding and the selector constructor, and their geometry matches the compact button rather than the popup list.
- 2026-06-03: Reclassified the `0x00481000` secondary forwarder as compiler-generated layout/vtable glue rather than handwritten source. Evidence: [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md) records the IDA boundary, slot dispatch body, historical Wave2/Wave3 generated-overlay exclusion metadata, and disabled generated overlay; those historical labels are not current source authority.
