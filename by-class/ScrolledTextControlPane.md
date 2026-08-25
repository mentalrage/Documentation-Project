*** UID:0000CI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScrolledTextControlPane : public ControlPane
{
public:
    ScrolledTextControlPane(const wchar_t *resourceName,
                            const RectBounds *bounds,
                            signed char scrollInterval);
    virtual ~ScrolledTextControlPane();

    virtual bool OnTimerEvent(int eventId, int param1, int param2);
    virtual void OnPaintFrame();

private:
    EPFTileContext m_renderedText;
    GrafPort m_renderPort;
    int m_scrollOffset;
    int m_scrollLimit;
    signed char m_scrollInterval;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrolledTextControlPane

## Status

- Confidence: very strong for direct base, exact `0x1dc` layout, constructor ABI, four source methods, three vtable views, caller/resource set, source placement, and compiler-wrapper exclusions.
- Source file: [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md).
- Exact body index: [UID:00019W][0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore](by-memory/0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore.md), now non-emitting because registered leaf pages carry all authored definitions.
- Compiler support: [UID:0003LW][0x00502b60-0x00502c0d.ScrolledTextControlPaneScalarDeletingDestructor](by-memory/0x00502b60-0x00502c0d.ScrolledTextControlPaneScalarDeletingDestructor.md) and [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md), both non-emitting.
- Position `10` places the complete generic declaration and its positions `20..50` before the made-by declaration/children at `100..140`.

## Class Purpose

`ScrolledTextControlPane` is a control type `8` widget that loads caller-selected DAT text, imports it through `TextEditScrap`, renders it once through a temporary [UID:0000EO][TextEditPane](by-class/TextEditPane.md), copies the result into an embedded `EPFTileContext`, and scrolls/blits that retained image on timer and paint callbacks.

It is the direct `ControlPane` sibling of [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md), not its base or derivative. The generic class advances by one and wraps silently; the made-by class advances by two and closes the active NewHistory dialog. [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md) is a separate resource-picture scroller using EPF/palette input rather than DAT/TextEdit rendering.

## Method Families And Source Order

| Source position | Exact child | Function and role |
| --- | --- | --- |
| `20` | [UID:0004WP][0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor](by-memory/0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor.md) | Constructor: automatic member construction, unchecked DAT read, generic TextEdit render/copy/mask pipeline, scroll initialization, and initial timer. |
| `30` | [UID:0004WQ][0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor](by-memory/0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor.md) | Ordinary destructor: explicit rendered-buffer release; member/base teardown remains automatic. |
| `40` | [UID:0004WR][0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent](by-memory/0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent.md) | `OnTimerEvent`: event-zero +1, strict greater-than wrap, signed-interval reschedule, invalidate, always true. |
| `50` | [UID:0004WS][0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame](by-memory/0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame.md) | `OnPaintFrame`: fill bounds, exact two-branch scrolling rectangles, one mode-0 null-option sprite blit. |

`[[CHILDREN]]` follows the closed class declaration so definitions emit at namespace scope. The aggregate UID00019W, scalar wrapper UID0003LW, adjustor thunks UID0003LY, vtables, RTTI, EH cleanup, and padding remain absent from authored source.

## Exact Class Layout

| Offset | Size | Source member / role |
| --- | --- | --- |
| `+0x000` | `0x108` | inherited `ControlPane` complete base and its primary/secondary/tertiary views |
| `+0x108` | `0x28` | `EPFTileContext m_renderedText`; automatic default construction, editor-surface copy, encoded mask, paint source, explicit buffer release |
| `+0x130` | `0xa0` | `GrafPort m_renderPort`; compiler-proven embedded lifetime and render state |
| `+0x1d0` | `4` | `int m_scrollOffset`; initialized zero, incremented by one, consumed by paint |
| `+0x1d4` | `4` | `int m_scrollLimit`; pane height plus rendered text height |
| `+0x1d8` | `1` | `signed char m_scrollInterval`; caller passes `50`, promoted for timer scheduling |
| `+0x1d9` | `3` | implicit tail alignment to exact object size `0x1dc`; no authored reserve member |

All four callers allocate `0x1dc`, and every constructor/destructor/timer/paint access agrees with this layout. `m_renderedText` must remain declared before `m_renderPort`: the binary constructs them at `0x004ff0ae` then `0x004ff0b9`, before constructor-body work. The source therefore must not contain a duplicate `m_renderedText.Initialize()` body call.

## Complete Behavioral Contract

- Constructor ABI is `(const wchar_t *, const RectBounds *, signed char)`. Staffs callers use `STAFFS2`/`STAFFS`, bounds `(38,62,230,305)`, interval `50`; BackStory callers use `BACKTALE`, interval `50`, and bounds `(25,56,361,278)` or `(36,71,228,265)`.
- The fixed 1001-byte temporary allocation, unchecked `data[dataSize] = 0`, absence of file/allocation/read guards, and exact local lifetime are intentional binary behavior.
- The temporary TextEditPane allocation is `0x174` bytes. Generic final constructor booleans are `true,false`, unlike the made-by sibling's `false,false` state.
- Destructor source explicitly releases only rendered context buffers. GrafPort and base teardown, scalar deletion, vptr writes, and this-adjustors are compiler lowering.
- Timer ignores nonzero events, adds one for event zero, wraps only when offset becomes strictly greater than limit, reschedules with signed interval, invalidates bounds, and returns true.
- Paint sets draw color zero, fills bounds, preserves exact strict rise/crop arithmetic, and blits once through `g_pfnBlitSprite` with mode zero and null palette/options. No target-local clipping, null, empty-rectangle, or clamp guard exists.

## Vtable, Caller, And Ownership Evidence

- Constructor calls: `0x004ffc52`, `0x004ffc79`, `0x00500207`, and `0x0050033e`.
- Primary paint slot `0x0061d78c` points to UID0004WS; tertiary timer slot `0x0061d7e4` points to UID0004WR.
- Primary scalar wrapper slot `0x0061d748` and generic adjustor slots `0x0061d7b0`/`0x0061d7e0` explain virtual destruction without authored ABI wrappers.
- TextEditPane, GrafPort, DATArchive, StaffsDialogPane, BackStoryDialogPane, and Surface are dependencies/consumers, not owners. Complete receiver layout/vtables/lifetime prove this class and [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md) as the narrow semantic/source route.

## Historical Assumptions And Corrections

- `OnTimerTick` and `OnDraw` remain searchable historical aliases; source now uses project-consistent `OnTimerEvent` and `OnPaintFrame`.
- Earlier `ImageRegion`/generic render-storage wording is superseded by exact `EPFTileContext m_renderedText` plus `GrafPort m_renderPort` layout.
- Earlier `0x88` GrafPort size is superseded by compiler-proven `0xa0`; no artificial padding member is introduced.
- Earlier blank-C++ status was a pre-split limitation, not a current source-quality blocker. Exact leaf pages now own complete definitions.

## Score Rationale

Completion `92` and confidence `94` reflect complete declaration, exact size/layout/member order, ABI, child inventory/order, full constructor/destructor/timer/paint behavior, callers/resources/vtables, ownership/source placement, negative evidence, and compiler exclusions. The score remains below final 95+ because original private/helper spellings and whole-program binary-equivalence proof are not recovered.

## Cross-References

- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)
- [UID:00019W][0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore](by-memory/0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore.md)
- [UID:0004WP][0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor](by-memory/0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor.md)
- [UID:0004WQ][0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor](by-memory/0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor.md)
- [UID:0004WR][0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent](by-memory/0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent.md)
- [UID:0004WS][0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame](by-memory/0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame.md)
- [UID:0003LW][0x00502b60-0x00502c0d.ScrolledTextControlPaneScalarDeletingDestructor](by-memory/0x00502b60-0x00502c0d.ScrolledTextControlPaneScalarDeletingDestructor.md)
- [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md)
- [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)

## Changes

- 2026-07-24 B005 complete declaration and exact-child implementation:
  - Before: `86/88`, blank position/formal, provisional `OnTimerTick`/`OnDraw` and render-storage wording, and no exact source-bearing child definitions.
  - After: `92/94`, retained owner/emitter UID0000NI, set position `10`, installed the complete `0x1dc` `ControlPane`-derived declaration with `[[CHILDREN]]`, and linked UID0004WP-UID0004WS at positions `20..50`.
  - Evidence: Gate-1-accepted C19W-01..32, four exact child hashes/CFGs, caller allocations/resources, vtable routes, automatic member order, exact behavioral bodies, and compiler-wrapper exclusions.

- 2026-06-12 A001 barrier-crossing repair:
  - Before: the class was `80/84`, below the active direct-parent gate, and pointed at stale continuous memory range [UID:00019W][0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore](by-memory/0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore.md).
  - After: raised to `86/88`, updated exact half-open method ranges, linked the split core/scalar-destructor/thunk pages, and documented current IDA caller/vtable/thunk evidence.
  - Evidence: 2026-06-12 IDA MCP `lookup_funcs`, `xrefs_to`, `analyze_function`, and padding range checks for the core cluster and scalar destructor support.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NI`.
  - Before: The DAT-text scroller remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ScrolledTextControlPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms the constructor/destructor/timer/draw/deleting-destructor starts at `0x004ff040`, `0x004ff290`, `0x004ff300`, `0x004ff360`, and `0x00502b60`; parent [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md) records the same DAT-text scroller ownership.

- 2026-05-30: Changed completion/confidence from `0/0` to `80/84`.
  - Before: The page was unevaluated despite documenting DAT text loading, temporary `TextEditPane` rendering, timer wrapping, paint behavior, and destructor range.
  - After: Scored as high completion and strong confidence for the auto-scrolling text control.
  - Evidence: Existing method-family table, constructor caller evidence, timer behavior, and text/picture control cross-references support the score.
