*** UID:0000CJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:100 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScrolledTextControlPaneForMadeBy : public ControlPane
{
public:
    ScrolledTextControlPaneForMadeBy(const wchar_t *resourceName,
                                     const RectBounds *bounds,
                                     signed char scrollInterval);
    virtual ~ScrolledTextControlPaneForMadeBy();

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

# ScrolledTextControlPaneForMadeBy

## Status

- Confidence: very strong for direct base, exact `0x1dc` layout, constructor ABI, four source methods, vtable views, source placement, and compiler-wrapper exclusions; stripped private/helper spellings remain the only material score cap.
- Likely source file: [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- Main address ranges: [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md), [UID:0003LX][0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor](by-memory/0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor.md), and compiler-generated thunk support [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_ScrolledTextControlPaneForMadeBy.cpp`

## Class Purpose

`ScrolledTextControlPaneForMadeBy` is the credits/attribution parallel sibling of [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md). Both classes derive directly from `ControlPane`; the made-by class does not derive from the generic scroller. It uses the same source-family DAT-text-to-rendered-image pipeline but scrolls by two pixels and closes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) when the content reaches the end.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| [UID:0004MA][0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor](by-memory/0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md) | constructor | Exact DAT/TextEdit render pipeline, typed state initialization, and initial timer schedule; source position 110. |
| [UID:0004MB][0x004ff650-0x004ff6bc.ScrolledTextControlPaneForMadeByDestructor](by-memory/0x004ff650-0x004ff6bc.ScrolledTextControlPaneForMadeByDestructor.md) | destructor | Exact explicit rendered-buffer release; automatic member/base teardown; source position 120. |
| [UID:0004MC][0x004ff6c0-0x004ff725.ScrolledTextControlPaneForMadeByOnTimerEvent](by-memory/0x004ff6c0-0x004ff725.ScrolledTextControlPaneForMadeByOnTimerEvent.md) | `OnTimerEvent` | Event-0 `+2`, strict greater-than reset/close, reschedule/invalidate, always true; source position 130. |
| [UID:0004MD][0x004ff730-0x004ff7cd.ScrolledTextControlPaneForMadeByOnPaintFrame](by-memory/0x004ff730-0x004ff7cd.ScrolledTextControlPaneForMadeByOnPaintFrame.md) | `OnPaintFrame` | Fill then exact two-branch rectangle calculation and one mode-0 null-option blit; source position 140. |
| [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md) | destructor adjustor thunks | Compiler-generated secondary/tertiary vtable adjustors shared with the generic variant; non-emitting support. |
| [UID:0003LX][0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor](by-memory/0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor.md) | scalar deleting destructor | Deleting-destructor wrapper. IDA confirms `0x00502cbc` is the final `retn 4` immediate byte. |

## Exact Class Layout

| Offset | Size | Source member / role |
| --- | --- | --- |
| `+0x000` | `0x108` | inherited `ControlPane` complete base, including primary/secondary/tertiary pane views |
| `+0x108` | `0x28` | `EPFTileContext m_renderedText`; initialized, receives copied editor surface, builds mask, supplies paint bounds/pixels, releases buffers |
| `+0x130` | `0xa0` | `GrafPort m_renderPort`; embedded render state with automatic lifetime |
| `+0x1d0` | `4` | `int m_scrollOffset`; starts at zero, timer adds two, paint consumes it |
| `+0x1d4` | `4` | `int m_scrollLimit`; pane height plus rendered text height |
| `+0x1d8` | `1` | `signed char m_scrollInterval`; caller-provided `30` in NewHistory, promoted for rescheduling |
| `+0x1d9` | `3` | implicit tail alignment to exact object size `0x1dc`; no source reserve member |

The sole constructor caller allocates `0x1dc`, and every member access plus ordinary/scalar destructor cleanup agrees with this layout. The formal declaration intentionally relies on normal compiler alignment after `m_scrollInterval`.

## Declaration And Source Order

- The class owns the exact constructor ABI `(const wchar_t *, const RectBounds *, signed char)`, a virtual ordinary destructor, tertiary-view `bool OnTimerEvent(int,int,int)`, and primary-view `void OnPaintFrame()`.
- Position `100` places the class after the generic sibling family. Registered children UID0004MA, UID0004MB, UID0004MC, and UID0004MD emit deterministically at `110`, `120`, `130`, and `140`.
- `[[CHILDREN]]` follows the closed class declaration so all child method definitions emit at namespace scope.
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md) remains the file owner and emitter. The one NewHistory caller does not move this reusable class into the login dialog module.
- UID00019X remains the non-emitting semantic aggregate index. UID0003LX scalar deletion, UID0003LY adjustors, and vtable data remain compiler-generated, blank, and absent from handwritten source.

## Complete Behavioral Contract

- Constructor loads only caller-selected `MADEBY` DAT text, uses a fixed 1001-byte temporary allocation without failure/size guards, imports `TextEditScrap`, renders through a temporary `0x174`-byte `TextEditPane`, copies the surface into `m_renderedText`, builds its mask, deletes the editor, and schedules timer delay 1.
- Destructor source explicitly calls only `m_renderedText.ReleaseBuffers()`; embedded GrafPort and base cleanup are automatic.
- Timer handles only event 0, adds two, resets then closes the non-null-assumed `g_pNewHistoryDialog` only on strict `offset > limit`, reschedules with the signed-byte interval, invalidates, and always returns true.
- Paint sets color 0, fills bounds, applies the exact destination-rise/source-crop formulas, and performs one mode-0 blit with null palette/options and no target-local clip/null/empty-rect guard.

## Evidence Notes

- Constructor summary identifies it as an auto-scrolling credits text control.
- 2026-06-12 IDA MCP reports the made-by core function extents as `0x004ff400-0x004ff644`, `0x004ff650-0x004ff6bc`, `0x004ff6c0-0x004ff725`, and `0x004ff730-0x004ff7cd`; `0x004ff7cd-0x004ff7d0` is `CC CC CC` padding before `ScrolledPictureControlPaneCore`.
- IDA MCP reports one direct constructor caller at `0x0050052e`.
- 2026-06-12 `analyze_function 0x004ff6c0` shows the timer increments scroll by two, wraps to zero at the end, calls close-dialog behavior through `g_pNewHistoryDialog`, invalidates, and notifies the parent path.
- 2026-06-12 IDA MCP reports `sub_502C10` as `0x00502c10-0x00502cbd`; raw-byte/range checks show only `0x00502cbd-0x00502cc0` is padding.
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) records the timer close path as `0x004ff6c0-0x004ff725`, with the singleton read at `0x004ff6eb`.
- The timer path calls close-dialog behavior through `g_pNewHistoryDialog` when the scroll reaches the end.
- Mandatory 2026-07-13 evidence collected on IDB database `supervisor_nexustk_20260713` resolved aggregate SHA256 `ABA0099F9CD9F1B30EB1E77C52AE69B70BD32D21BF3F0A42A5AFF396C012F716`, all four exact child hashes/CFGs, three internal padding spans, direct caller `0x0050052e`, primary/secondary/tertiary vtables `0x0061d7ec/0x0061d854/0x0061d884`, object layout, helper order, absent guards, and compiler/source disposition.

## Score Rationale

Completion `92` and confidence `94` reflect exact base/layout/object size, ABI, declaration, child inventory and source order, full constructor/destructor/timer/paint contracts, caller/vtables/resources/globals, ownership/source placement, negative evidence, and compiler exclusions. Remaining uncertainty concerns stripped private/helper spellings and final header organization, not source-bearing behavior or compile shape.

## Cross-References

- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)
- [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md)
- [UID:0004MA][0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor](by-memory/0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md)
- [UID:0004MB][0x004ff650-0x004ff6bc.ScrolledTextControlPaneForMadeByDestructor](by-memory/0x004ff650-0x004ff6bc.ScrolledTextControlPaneForMadeByDestructor.md)
- [UID:0004MC][0x004ff6c0-0x004ff725.ScrolledTextControlPaneForMadeByOnTimerEvent](by-memory/0x004ff6c0-0x004ff725.ScrolledTextControlPaneForMadeByOnTimerEvent.md)
- [UID:0004MD][0x004ff730-0x004ff7cd.ScrolledTextControlPaneForMadeByOnPaintFrame](by-memory/0x004ff730-0x004ff7cd.ScrolledTextControlPaneForMadeByOnPaintFrame.md)
- [UID:0003LX][0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor](by-memory/0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor.md)
- [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md)
- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)

## Changes

- 2026-07-13 B002 accepted implementation callback:
  - Before: `86/89`, blank class formal, blank source position, shallow embedded-state wording, and no exact source-bearing child definitions.
  - After: `92/94`, retained owner/emitter UID0000NI, set position `100`, installed the exact typed `ControlPane`-derived declaration with `[[CHILDREN]]`, documented the `0x1dc` layout and implicit tail alignment, and linked serial children UID0004MA-UID0004MD at positions 110-140.
  - Evidence: Gate-1-accepted C01-C30/Destination 2, exact caller allocation/member offsets/vtables, four function analyses, dependency docs, and validated child registration.

- 2026-06-12 A001 barrier-crossing repair:
  - Before: the class was `82/86`, below the active strict direct-parent gate, and pointed at stale continuous memory range [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md).
  - After: raised to `86/89`, updated exact half-open method ranges, linked the split core/scalar-destructor/thunk pages, and documented current IDA caller/vtable/timer/destructor evidence.
  - Evidence: 2026-06-12 IDA MCP `lookup_funcs`, `xrefs_to`, `analyze_function`, and padding range checks for the made-by core cluster and scalar destructor support.

- 2026-06-06:
  - Before: the method table displayed the timer handler as `0x004ff6c0-0x004ff724`.
  - After: corrected the display to the half-open `0x004ff6c0-0x004ff725` range and linked the singleton memory evidence.
  - Evidence: [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) records the timer path, singleton read at `0x004ff6eb`, and end-of-scroll close behavior.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NI`.
  - Before: The credits text-scroller variant remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ScrolledTextControlPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor/destructor/timer/paint starts at `0x004ff400`, `0x004ff650`, `0x004ff6c0`, and `0x004ff730`, deleting thunk `0x0050257c`, and scalar deleting destructor `0x00502c10`; parent [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md) owns the DAT-text scroller family.

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented the credits variant role, constructor/destructor/timer/paint families, one caller, close-on-end behavior, and corrected destructor endpoint.
  - After: changed completion/confidence to `82/86`.
  - Evidence: existing method-family table, IDA caller and endpoint evidence, `g_pNewHistoryDialog` behavior, and related text-control cross-references support high-confidence documentation.

- Before: this class page listed the destructor range and main address range ending at `0x00502cbc`.
- After: the ranges now end at `0x00502cbd`.
- Why: IDA MCP shows the byte at `0x00502cbc` belongs to the scalar deleting destructor as the immediate operand of `retn 4`.
- Evidence: 2026-05-28 IDA MCP function-boundary and raw-byte check for `0x00502c10` and `0x00502cbc-0x00502cc0`.
