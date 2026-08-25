*** UID:0000BO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum RankingScrollPart {
    kRankingScrollPartLeading = 0,
    kRankingScrollPartPageBeforeThumb = 1,
    kRankingScrollPartThumb = 2,
    kRankingScrollPartPageAfterThumb = 3,
    kRankingScrollPartTrailing = 4,
    kRankingScrollPartNone = -1
};

const int kRankingScrollThumbSpan = 38;

class RankingEventScrollPane : public Pane {
public:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool HasActiveEffect();
    virtual void OnPaint();

private:
    RankingScrollPart HitTestPart(int y, int x);
    void GetPartRect(RankingScrollPart part, RectBounds *outRect);
    void SetHighlightedPart(RankingScrollPart part);
    void BeginPartInteraction(RankingScrollPart part, int mouseY, int mouseX);
    void UpdateActiveInteraction();
    void DragToPosition(int y, int x);
    void ResetInteractionState();

    short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    signed char m_highlightPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingEventScrollPane

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Vtables: [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- Layout: [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- Evidence basis: live IDA MCP against `NexusTK.exe` plus linked project documentation.
- Confidence: strong for role, parent ownership, complete source-ready emitted method surface, accepted tail layout, vtable placement, raw-helper boundaries, retained-method names, and source route. UID0000Y2 raw constructor/setter API spellings remain the deliberate completion cap.

## Class Purpose

`RankingEventScrollPane` is the private scrollbar control used by `RankingEventListPane`. It tracks skin/style state, orientation, current position, max position, hover/pressed parts, drag state, and draws the `SLIDEBG` track plus `SCRBUTT` thumb/buttons.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingEventScrollPane` | `0x004598b0-0x0045990c` | Raw non-IDA constructor. Builds `Pane`, installs vtables, initializes scroll state and hover parts. |
| raw setter/test island | `0x00459910-0x00459a59` | Raw non-IDA skin-index/style/range/position/enabled setters plus the enabled-and-positive-range predicate before the modeled mouse handler. |
| `OnMouseEvent` | `0x00459a60-0x00459ccd` | Source-ready first-draft virtual mouse handler. Handles move/down/up event kinds, hover invalidation, press/capture, thumb drag setup, track/page drag updates, release/reset, timer scheduling, and scroll position changes through [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md). |
| `HasActiveEffect` | `0x00459cd0-0x00459cd4` | Returns false. |
| `OnPaint` | `0x00459ce0-0x0045a3f5` | Source-ready first-draft virtual paint method. Draws clipped page-before/page-after track strips with vertical frames `1/0/2` or horizontal frames `4/3/5`, then the `SCRBUTT.EPF` thumb frame selected by `m_highlightPart`, through [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md). |
| `HitTestPart` | `0x0045a400-0x0045a70b` | Source-ready private `RankingScrollPart HitTestPart(int y, int x)` helper. It tests a y-first mouse point against inline leading/page-before/thumb/page-after/trailing rectangles through [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md). |
| `GetPartRect` / historical `GetScrollRegionRect` | `0x0045a710-0x0045a98a` | Source-ready private `void GetPartRect(RankingScrollPart part, RectBounds *outRect)` helper. It preserves the sentinel no-write return, collapsed leading/trailing edges, proportional thumb/page geometry, disabled/no-range fallback, and vertical-only ordered drag clamp through [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md). |
| `SetHighlightedPart` | `0x0045a990-0x0045a9ff` | Source-ready raw retained `void SetHighlightedPart(RankingScrollPart)` child [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md); invalidates old/new non-none rectangles before the signed highlight store. |
| `BeginPartInteraction` | `0x0045aa00-0x0045ab48` | Source-ready raw retained `void BeginPartInteraction(RankingScrollPart, int mouseY, int mouseX)` child [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md); prepares thumb anchor/highlight, active state, update, and repeat timer. |
| `UpdateActiveInteraction` | `0x0045ab50-0x0045ac0f` | Source-ready raw retained `void UpdateActiveInteraction()` child [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md); localizes cursor, drives active part, and clears stale highlight. |
| `DragToPosition` | `0x0045ac10-0x0045adc3` | Source-ready private `void DragToPosition(int y, int x)`. It preserves two sentinel-controlled bounds initializations, orientation-specific signed scaling/clamps, `+1`, vertical-only range cap, no-change return, and factorized `GetOwnerPane()->SetScrollPosition(0, oldPosition, newPosition)` owner synchronization through [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md). |
| `ResetInteractionState` | `0x0045add0-0x0045ae2b` | Source-ready raw retained method [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md); removes pending timers, clears active state, and invalidates/clears stale highlight. |

## Evidence Notes

- `RankingEventListPane` constructs this pane as its scroll child; live IDA shows `sub_45AE30` allocates `0x110` bytes, calls pane setup, installs the three `RankingEventScrollPane` vtables, initializes local scroll fields, and stores the child pointer in the owner at `+0x108`.
- IDA confirms three class vtables at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`, installed by the raw constructor island and also by the inline child setup in `RankingEventListPane::RankingEventListPane` at `0x0045ae30`.
- Vtable slots bind `0x00459ce0` as paint, `0x00459a60` as mouse input, `0x00459cd0` as the false-return active/effect virtual, and `0x00544e90` as the inherited/default event-update slot.
- IDA reports no function object at the raw starts in `0x004598b0-0x00459a59`, `0x0045a990-0x0045ac0f`, or `0x0045add0-0x0045ae2b`, but raw disassembly shows full helper bodies; `0x00459a60`, `0x0045a400`, `0x0045a710`, `0x0045ac10`, and `0x0045ae30` remain modeled IDA functions.
- Live xref evidence on 2026-06-13 confirms the modeled helpers are locally bound: `0x00459a60`, `0x00459cd0`, and `0x00459ce0` have vtable-only data xrefs; `0x0045a400` is called from the mouse handler and raw hover/drag island; `0x0045a710` is called from mouse, paint, drag, reset, and raw helper paths; `0x0045ac10` is called from mouse and raw helper paths.
- 2026-05-27 IDA `py_eval` recheck strengthens the raw helper boundary evidence: constructor/setter starts `0x004598b0`, `0x00459910`, `0x00459940`, `0x00459970`, `0x004599d0`, `0x00459a00`, `0x00459a20`, `0x00459a40`, and reset start `0x0045add0` still have no IDA function objects or direct xrefs, but each has a normal body/return and local calls/field writes matching the scroll pane state model.
- Parent routing remains [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). The class is private to the ranking UI evidence set, the direct file parent already clears the 85/85 gate, and [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md) is supporting owner context rather than a source-file parent.
- The control is feature-specific in current usage, but it shares visual behavior with other custom scrollbars and may eventually share implementation names with generic scrollbar code.
- 2026-06-23 B001 current MCP session `80de0a67` reconfirms the raw-helper disposition at report-level detail: raw starts `0x004598b0`, `0x0045a990`, and `0x0045add0` still have no IDA function objects and zero inbound xrefs, while modeled helpers `0x00459a60`, `0x0045a400`, `0x0045a710`, and `0x0045ac10` remain real functions. Existing raw child pages [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md), [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md), and [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md) already carry the exact no-function/no-xref boundaries.
- 2026-07-09 B004 UID0000Y2 current MCP session `supervisor_nexustk_20260709` refines the raw constructor/setter island at report-level detail: UID0000Y2 is now `88/91`, still owned/emitted by this class through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), with blank formal C++ under a target-specific no-standalone proof. The `0x00459910` helper is the `+0xf8` `m_scrollSkinIndex` word setter candidate, not a current-position setter; `0x00459940` is the `+0xfa` `m_scrollStyle` / style-state byte setter candidate; `+0xfe` remains `m_scrollPosition`; `+0x100` remains `m_scrollRange`; and `+0x102/+0x103/+0x104` remain enabled/highlight/active part bytes. Current MCP reconfirmed no function objects, zero incoming raw-start xrefs, zero raw-start pointer-byte hits, exact bytes/signature, vtable labels/xrefs, and successor [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md).
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md) now has accepted first-draft formal C++ as `bool RankingEventScrollPane::OnMouseEvent(const PaneMouseEvent& event)` under the active combined-score/emitter gate. B003 MCP session `supervisor_nexustk_20260709` reconfirmed `sub_459A60` size `0x26e`, end-exclusive `0x00459cce`, vtable-only xref from `0x00610a9c`, no direct callers, exact event-kind dispatch, and `0xcc` padding at both boundaries.
- Accepted UID0000Y3 source-facing names are `PaneMouseEvent`, `RankingScrollPart`, `m_thumbDragActive` (`+0xfb`), `m_scrollRange` (`+0x100`), `m_enabled` (`+0x102`), `m_highlightPart` (`+0x103`), `m_activePart` (`+0x104`), and `m_thumbDragOffset` (`+0x108/+0x10c`). Helper names used by the first draft are `HitTestPart`, `GetPartRect`, `DragToPosition`, `CaptureMouse`, `ReleaseMouseCapture`, `ScheduleTimer`, `RemovePendingTimers`, `EventMan::GetCursorPosition`, and `GetScreenOffset`.
- B003 current MCP session `359c7886` confirms [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md) as a source-ready `0x716`-byte primary-vtable paint method with sole data xref `0x00610a90`, no direct callers, 578 instructions/44 calls, exact `SLIDEBG`/`SCRBUTT` resources and frame mapping, and formal first-draft `RankingEventScrollPane::OnPaint()` output at `89/91`.
- Accepted paint-side source names are `m_scrollStyle` (`+0xfa`), `m_thumbDragActive` (`+0xfb`), `m_orientation` (`+0xfc`), `m_scrollPosition` (`+0xfe`), `m_scrollRange` (`+0x100`), `m_enabled` (`+0x102`), `m_highlightPart` (`+0x103`), `m_activePart` (`+0x104`), `m_thumbDragOffset` (`+0x108/+0x10c`), inherited `m_drawMode` (`+0x70`), and `GetPartRect(RankingScrollPart, RectBounds *)`. Shared helpers/resources remain dependencies rather than class ownership evidence.
- B004 current MCP session `359c7886` confirms [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md) as source-ready `RankingEventScrollPane::HitTestPart(int y, int x)` at `89/91`: modeled size `0x30c`, four class-local code calls, no data/vtable route, 231 instructions, clean padding, inline orientation/range/drag geometry, and canonical y-first `PointInRect`. The part contract is `kRankingScrollPartLeading`, `PageBeforeThumb`, `Thumb`, `PageAfterThumb`, `Trailing`, and `None`; vertical geometry uses `kRankingScrollThumbSpan = 38`, while horizontal geometry uses control height.
- B004 evidence-time MCP database `bf5519ae` confirms [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md) as source-ready `void RankingEventScrollPane::GetPartRect(RankingScrollPart part, RectBounds *outRect)` at `89/91`. Requests `62006-62019` confirmed modeled size `0x27b` / exclusive end `0x0045a98b`, four-byte prepad and five-byte postpad, exactly fifteen class-local callers, only cursor/screen-offset/empty-rectangle callees, y/x localization and sentinel no-write return, accepted local fields, horizontal height span, vertical literal `38`, disabled/no-range fallback, vertical-only ordered drag clamp, and untouched-output/full-bounds invalid-part asymmetry.
- The target's source-facing part contract remains `kRankingScrollPartLeading`, `kRankingScrollPartPageBeforeThumb`, `kRankingScrollPartThumb`, `kRankingScrollPartPageAfterThumb`, `kRankingScrollPartTrailing`, and separate state sentinel `kRankingScrollPartNone`. Its signed-short `m_scrollPosition`/`m_scrollRange` and `m_thumbDragOffset.y/.x` layout agree with UID0000Y3/Y4/Y5/Y6 and UID0001ZA/VO.
- B003 UID0000Y6 implementation confirms the modeled helper at `[0x0045ac10,0x0045adc4)`, size `0x1b4`, with exactly six local calls at `0x00459c1c`, `0x00459c38`, `0x0045aad8`, `0x0045aaf4`, `0x0045abab`, and `0x0045abd4`. All calls are y-first/x-second. Nonzero `m_orientation` uses horizontal `x/.x` math; zero uses vertical `y/.y` math; both retain signed truncating division and exact clamp behavior.
- UID0000Y6's changed tail is the compiler-expanded body of independently modeled [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md) `SetScrollPosition(int, short, short)` at `0x0045b200`. Its ordinary callers pass `(0, oldPosition, newPosition)`, so the source-ready Y6 body uses `GetOwnerPane()->SetScrollPosition(0, oldPosition, newPosition)` rather than direct access to list-pane private fields. Equal old/new values perform no owner lookup or side effects.
- B005 UID0000Y5 implementation resolves the former class-declaration blocker. The formal block now defines exact `RankingScrollPart` values, `kRankingScrollThumbSpan = 38`, all currently source-ready virtual/private method declarations, accepted `+0xf8-+0x10c` tail fields, natural compiler padding at `+0xfd/+0x105..+0x107`, and `[[CHILDREN]]`. It intentionally does not invent callable APIs for raw UID0000Y2 constructor/setter candidates; that accepted no-standalone proof remains the reason class completion stays below 90.
- UID0000Y5 is now a `90/93` non-emitting split index with exact children UID0004J0/UID0004J1/UID0004J2. Raw starts still have no function objects or direct/pointer routes, but complete bodies, modeled/inlined active copies, normalized family matches, and exact boundaries establish retained private source methods. Seven `0xcc` bytes at `0x0045ab49-0x0045ab4f` remain alignment.
- Validator nesting is relative: UID0000Y5 remains cumulative indent 59, UID0004J0 opens child indent 63 with `Nested:4`, UID0004J1/UID0004J2 remain 63 with `Nested:0`, and executed UID0000Y6 returns to 59 with metadata-only `Nested:-4`. UID0000Y7 and following UID0000Y8 remain `Nested:0`/59.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md)
- [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md)
- [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md)
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md)
- [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)
- [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md)
- [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md)
- [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md)
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md)
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md)
- [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md)

## Changes

- 2026-07-12 B005 UID0000Y5 class/split implementation callback:
  - Before: executed B003 narrow support state `88/90`, blank class formal block, provisional Y5/Y7 method names, and generated method definitions without a class declaration.
  - After: `89/92` with exact enum/constant/class/field/declaration block plus `[[CHILDREN]]`; source-ready UID0004J0/UID0004J1/UID0004J2 and UID0000Y7 names/bodies; preserved exact executed UID0000Y6 body; and synchronized raw liveness/nesting evidence.
  - Preserved: owner/emitter UID0000MZ, source route, UID0000Y2 no-standalone disposition, all accepted Y3/Y4/Z9/ZA/ZB/Y6 formal bodies and scores, vtable inheritance, layout offsets, resources, and historical evidence.

- 2026-07-12 B003 UID0000Y6 narrow support callback:
  - Before: `87/89`; the method table described DragToPosition only broadly and did not record its exact source-ready signature, math, no-change path, or owner-method factorization.
  - Changed to: `88/90` with exact `void DragToPosition(int y, int x)` support, six callers, sentinel/geometry/arithmetic evidence, and `GetOwnerPane()->SetScrollPosition(0, oldPosition, newPosition)` source factorization. Owner/emitter UID0000MZ and the blank class-level formal block remain unchanged.
  - Preservation: no UID0000Y5/UID0000Y7 split, class declaration, raw method inventory, or broader B005-owned class work was changed.

- 2026-07-12 B004 UID0001ZB GetPartRect support sync:
  - Changed to: documentation support only; class `87/89`, owner/emitter UID0000MZ, reconstructable state, and blank class-level C++ remain unchanged. The method inventory now marks UID0001ZB source-ready as `void GetPartRect(RankingScrollPart, RectBounds *)`.
  - Evidence: accepted B004 UID0001ZB report SHA256 `1EE84348BCBB99F49649536529ED4DBCBF15E30FAACD46AED663DA084ABAA915` and evidence-time MCP database `bf5519ae` requests `62006-62019` prove the exact target boundary/padding, fifteen callers, three callees, sentinel/output contract, all orientation/part/disabled/drag branches, and accepted enum/field/type vocabulary.
  - Preserved: separate whole-class declaration no-code proof, raw constructor/helper boundary caveats, sibling method work, original-name uncertainty, RankingDialog source route, and rejection of generic/FittingRoom/ScrollCollection ownership or target splitting.

- 2026-07-12 B004 UID0000Y4 HitTestPart support sync:
  - Changed to: documentation support only; class score `87/89`, owner/emitter, reconstructable metadata, and blank class-level C++ remain unchanged. Replaced stale `HitTestScrollPart` with source-facing `HitTestPart(int y, int x)` and added the full ranking part/constant/geometry contract.
  - Evidence: current MCP session `359c7886` proves UID0000Y4's exact modeled body, caller/callee and padding facts, y-first point order, inline geometry, and first-draft readiness. The broad class score remains capped by incomplete whole-class declaration and sibling helper-body coverage.

- 2026-07-12 B003 UID0001ZA OnPaint support sync:
  - Changed to: documentation support only; class score, owner/emitter, reconstructable metadata, and blank class-level C++ remain unchanged.
  - Summary/evidence: UID0001ZA now emits first-draft `RankingEventScrollPane::OnPaint()` at `89/91`. Current MCP session `359c7886` proves exact `0x00459ce0-0x0045a3f6` boundary, sole vtable data xref `0x00610a90`, no direct callers, resource/frame/helper call set, accepted Ranking fields, and the separate class-declaration compile-support requirement.

- 2026-07-09 B004 UID0000Y2 support sync:
  - Changed to: documentation only; `87/89`, owner/emitter [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), reconstructable status, and blank class-level C++ remain unchanged.
  - Summary/evidence: accepted B004 UID0000Y2 report and current MCP session `supervisor_nexustk_20260709` refreshed the raw constructor/setter island, repaired stale `+0xf8` current-position wording to `m_scrollSkinIndex`, clarified `+0xfa` as `m_scrollStyle` / style-state byte, and preserved the no-standalone proof for the exact raw child while retaining this class as the direct owner.

- 2026-07-09 B003 UID0000Y3 implementation callback:
  - Changed to: documentation support only; class score, owner, emitter, and reconstructable metadata remain unchanged.
  - Summary/evidence: [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md) now emits first-draft `RankingEventScrollPane::OnMouseEvent(const PaneMouseEvent& event)` at `89/91`. This page records the accepted source-facing event/scroll-part/field/helper names and separates the remaining class declaration/generated compile-completeness support requirement from the target method's C++ readiness.

- 2026-06-23 B001 accepted source-quality sync:
  - Before: `86/88`, with raw helper boundaries documented but no current-session confirmation from the accepted report.
  - Changed to: `87/89`; class-level C++ remains blank.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed raw no-function/no-xref starts, modeled helper functions, inline setup from `RankingEventListPane`, and the reason exact child pages own behavior while class C++ waits on stable interface signatures.

- 2026-06-13: Raised `COMPLETION` from `78` to `86` and `CONFIDENCE` from `82` to `88`.
  - Before: the class page had useful role and method inventory notes, but it still relied on stale recovered-source wording and left the low-scored type children as weak support.
  - After: the page records live IDA MCP evidence for constructor allocation, three vtable stores, modeled helper xrefs, raw/non-function helper islands, and parent routing. The related layout and vtable support pages were tightened to 85/85+ evidence quality.
  - Evidence: active IDA MCP session `a001_goal2_0002UM` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed `sub_459A60`, `sub_459CD0`, `sub_459CE0`, `sub_45A400`, `sub_45A710`, `sub_45AC10`, and `sub_45AE30`; `xrefs_to` confirmed the vtable-only virtual slots and local helper call graph; `analyze_function 0x0045ae30` confirmed the `0x110` child allocation and inline `RankingEventScrollPane` setup.
- 2026-05-30: Grading changed from `0/0` to `78/82`.
  - Before: page documented the private scrollbar role, raw/modelled method islands, vtables, resource usage, and helper omissions but remained unevaluated.
  - After: score reflects documented scroll state, mouse handling, painting, hit-test/geometry helpers, drag/reset behavior, vtable evidence, and raw-helper caveats. The misplaced ranking resource reference was moved into Cross-References.
  - Evidence: linked memory child pages and [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md) record IDA-confirmed modelled functions, raw helper bodies, vtable slot binding, and `SLIDEBG`/`SCRBUTT` resource use.
- 2026-05-31: Marked reconstructable and attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) without adding C++.
  - Before: the class page was scored but not connected to validator autogen/reconstruction metadata.
  - After: the class is marked as a reconstructable ranking-dialog helper class, while source emission remains blocked until final helper names and source shape are near-final.
  - Evidence: IDA-confirmed vtables, child allocation/setup from `RankingEventListPane`, and linked exact memory child pages place the class inside `RankingDialog.cpp`.
- 2026-05-27: Changed the class confidence note from medium raw helper boundaries to strong raw/helper boundaries with medium final raw helper names. Evidence: IDA `py_eval` confirmed normal raw bodies/returns for the constructor/setter island and reset helper while still reporting no modeled function objects or direct xrefs for those raw starts.
