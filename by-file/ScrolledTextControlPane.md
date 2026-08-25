*** UID:0000NI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScrolledTextControlPane

## Status

- Confidence: very strong for the shared translation-unit route, two direct `ControlPane` siblings, complete declarations, exact source children/order, DAT/TextEdit render pipeline, object layouts, and compiler-wrapper exclusions.
- Proposed module: `ui/controls/ScrolledTextControlPane.cpp`
- Proposed header: `ui/controls/ScrolledTextControlPane.h`
- Current recovered sources: `source-3/simroot_v2/class_ScrolledTextControlPane.cpp` and `class_ScrolledTextControlPaneForMadeBy.cpp`
- Main address clusters: non-emitting generic index [UID:00019W][0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore](by-memory/0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore.md), non-emitting made-by index [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md), exact source children listed below, thunk support [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md), and scalar deleting wrappers UID0003LW / [UID:0003LX][0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor](by-memory/0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor.md).

## File Role

This module owns the generic and credits auto-scrolling DAT-text controls. Both direct `ControlPane` siblings load caller-selected text through `DATFile` and `TextEditScrap`, render once through a temporary [UID:0000ON][TextEditPane](by-file/TextEditPane.md), copy the result into `EPFTileContext m_renderedText`, retain an embedded `GrafPort m_renderPort`, and scroll/blit the pre-rendered result. Both complete objects are `0x1dc`: `ControlPane 0x108`, `EPFTileContext 0x28`, `GrafPort 0xa0`, two `int` fields, one signed interval byte, and implicit alignment.

`ScrolledTextControlPaneForMadeBy` is a specialized credits/"made by" variant that scrolls faster and closes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) when the content reaches the end.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScrolledTextControlPane` | [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md), non-emitting [UID:00019W][0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore](by-memory/0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore.md), and exact children UID0004WP-UID0004WS | Generic declaration at position 10 followed by exact constructor/destructor/timer/paint definitions at 20/30/40/50; control type `8`, caller-selected `STAFFS2`/`STAFFS`/`BACKTALE`, +1 wrapping timer, and exact clipped sprite paint. |
| `ScrolledTextControlPaneForMadeBy` | [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md) plus [UID:0003LX][0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor](by-memory/0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor.md) | Credits/attribution variant; same render pipeline with dialog close at end of scroll. |
| scrolled text destructor thunks | [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md) | Compiler-generated secondary/tertiary destructor adjustor thunks for both scrolled text classes; documented as non-emitting support. |
| `g_pNewHistoryDialog` | `0x0069b49c` | Used by the credits variant to close the active `NewHistoryDialogPane` after scrolling completes. |

## Exact Generic Source Inventory And Order

| Position | Source entity | Exact range and role |
| --- | --- | --- |
| `10` | [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md) | Complete `0x1dc` class declaration with `[[CHILDREN]]`. |
| `20` | [UID:0004WP][0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor](by-memory/0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor.md) | Automatic rendered-context/GrafPort construction; unchecked DAT/TextEdit render pipeline; generic `true,false` final editor flags; initial timer. |
| `30` | [UID:0004WQ][0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor](by-memory/0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor.md) | Explicit rendered buffer release; automatic member/base teardown. |
| `40` | [UID:0004WR][0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent](by-memory/0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent.md) | Event-zero +1, strict greater-than wrap, signed interval reschedule, invalidate, true return. |
| `50` | [UID:0004WS][0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame](by-memory/0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame.md) | Fill-before-blit, exact two-branch rectangles, one mode-0 null-palette/options sprite callback. |

The made-by class remains later at positions `100..140`. Generic and made-by aggregates are physical indexes only; their exact children carry source. Scalar deleting destructors, adjustor thunks, vtables/RTTI, EH cleanup, and padding remain compiler-generated and do not emit handwritten bodies.

## Resolved Dependency And Lifetime Model

- `EPFTileContext m_renderedText` is automatically constructed before `GrafPort m_renderPort`; the binary calls at `0x004ff0ae` then `0x004ff0b9` precede constructor-body work. Generic source therefore contains no duplicate explicit `Initialize()` call.
- The constructor preserves the exact fixed 1001-byte allocation and unchecked terminator write, temporary `0x174` TextEditPane, rectangle setup, render/copy/mask order, and local lifetimes.
- Destructor source explicitly releases rendered buffers only. GrafPort/base cleanup, delete-flag wrappers, vptr stores, and this-adjustors are automatic compiler lowering.
- Surface callbacks remain shared dependencies: control source uses inherited `FillRect` for slot `0x0069b3fc` and `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` for slot `0x0069b3e8`. No raw `dword_*` label enters authored source.
- StaffsDialogPane, BackStoryDialogPane, and NewHistoryDialogPane instantiate these reusable controls but do not own the class definitions.

## Ownership Decision

Keep both classes in one scrolled-text control module. Their constructors, timers, draw paths, and destructors are nearly parallel, and both use the same resource-to-rendered-text pipeline.

Keep this separate from [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md). Static text controls render current pane text directly; scrolled text controls pre-render DAT text into an image region and scroll that image by timer.

Keep [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md) as the sibling picture-scroller module. It shares the timer/scrolling control pattern, but it loads EPF frame and palette resources instead of rendering DAT text through `TextEditPane`.

## Evidence Notes

- 2026-06-12 IDA MCP reports four direct references to `ScrolledTextControlPane::ScrolledTextControlPane` at `0x004ff040` and one direct reference to `ScrolledTextControlPaneForMadeBy::ScrolledTextControlPaneForMadeBy` at `0x004ff400`.
- 2026-06-12 IDA MCP confirms exact body clusters `0x004ff040-0x004ff3fd` and `0x004ff400-0x004ff7cd`, separated by `0xcc` padding and followed by `ScrolledPictureControlPaneCore` at `0x004ff7d0`.
- 2026-06-12 IDA MCP reports the `ScrolledTextControlPane` scalar deleting destructor at `0x00502b60-0x00502c0d` and the `ScrolledTextControlPaneForMadeBy` scalar deleting destructor at `0x00502c10-0x00502cbd`; `0x00502cbd-0x00502cc0` is padding before `StaffsDialogPaneDestructor`.
- 2026-06-12 IDA MCP confirms four adjacent scrolled-text destructor adjustor thunks at `0x00502566`, `0x00502571`, `0x0050257c`, and `0x00502587`; each is a two-instruction `this` adjustment and jump into the matching scalar deleting destructor.
- Both constructors call `ControlPane` with type `8`, allocate a temporary 372-byte `TextEditPane`, set it read-only/non-editable, render it, copy the resulting `GrafPort`/tile context into the scrolled control, then delete the temporary text pane.
- `ScrolledTextControlPane::OnTimerTick` increments the scroll offset by one and wraps to zero.
- `ScrolledTextControlPaneForMadeBy::OnTimerEvent` increments by two and calls close-dialog behavior on `g_pNewHistoryDialog` when the end is reached.

## Historical Caveats And Current Resolution

- Historical generated destructor names such as `TextButtonExControlPane::~Pane` are base-owner pollution. Exact ordinary destructor children now own authored cleanup; scalar wrappers/thunks are explicitly compiler-only.
- Historical alternation among `EPFTileContext`, `ImageRegion`, and truncated `GrafPort` storage is resolved. Both classes use `EPFTileContext m_renderedText` followed by full `0xa0` `GrafPort m_renderPort`.
- Historical aggregate blank emitters and `OnTimerTick`/`OnDraw` names are superseded by exact children and project-consistent `OnTimerEvent`/`OnPaintFrame` declarations.
- Original private/helper token spelling and final header include partition remain inferred, but no behavioral, ownership, split, or source-order blocker remains.

## Score Rationale

Completion `92` and confidence `94` reflect both class declarations, exact generic and made-by child inventories/order, complete layouts/ABIs, resource/render/timer/paint behavior, caller/module decisions, compiler-wrapper exclusions, and resolved dependency names. The score remains below final 95+ because stripped lexical spelling and whole-program binary equivalence are not proven.

## Cross-References

- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)
- [UID:00019W][0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore](by-memory/0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore.md)
- [UID:0004WP][0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor](by-memory/0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor.md)
- [UID:0004WQ][0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor](by-memory/0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor.md)
- [UID:0004WR][0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent](by-memory/0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent.md)
- [UID:0004WS][0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame](by-memory/0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame.md)
- [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md)
- [UID:0003LW][0x00502b60-0x00502c0d.ScrolledTextControlPaneScalarDeletingDestructor](by-memory/0x00502b60-0x00502c0d.ScrolledTextControlPaneScalarDeletingDestructor.md)
- [UID:0003LX][0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor](by-memory/0x00502c10-0x00502cbd.ScrolledTextControlPaneForMadeByScalarDeletingDestructor.md)
- [UID:0003LY][0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks](by-memory/0x00502566-0x00502592.ScrolledTextControlPaneDestructorThunks.md)
- [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md)
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-07-24 B005 generic source-family completion:
  - Before: `86/88`, correct shared file grouping but aggregate-only generic routing, unresolved EPFTileContext/ImageRegion/GrafPort caveat, and compiler-wrapper/source-body ambiguity.
  - After: `92/94`; registered exact generic class/method order at positions 10-50, resolved the `0x1dc` layout and automatic member order, preserved made-by positions 100-140, and excluded scalar/thunk/vtable/EH/padding lowering from authored source.
  - Evidence: accepted C19W-01..32, validator-assigned UID0004WP-UID0004WS, exact bytes/callers/resources/vtables, and source-ready child formals.

- 2026-06-12 A001 barrier-crossing repair:
  - Before: the file page was `84/86`, and the child memory pages used stale continuous ranges that crossed unrelated neighboring classes.
  - After: raised to `86/88`, replaced continuous range summaries with exact core/scalar-destructor/thunk children, and documented current IDA boundary, caller, vtable, and thunk evidence for both scrolled-text variants.
  - Evidence: 2026-06-12 IDA MCP `lookup_funcs`, `xrefs_to`, `analyze_function`, `entity_query`, and padding range checks used during the by-memory split.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented `ScrolledTextControlPane` constructor anchor at `0x004ff040`; proposed-source-tree groups this DAT-text scroller with static/scrolled UI controls, not login history or generic text-edit ownership.
- Before: the file-level range summary ended `ScrolledTextControlPaneForMadeBy` at `0x00502cbc`.
- After: the file-level range summary ends it at `0x00502cbd`.
- Why: IDA MCP confirms `0x00502cbc` is the final operand byte of the scalar deleting destructor return instruction, so the following padding starts at `0x00502cbd`.
- Evidence: 2026-05-28 IDA MCP decompile/function-boundary check for `0x00502c10` and raw bytes `00 cc cc cc` at `0x00502cbc-0x00502cc0`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `86`.
  - Evidence: document captures both scrolled-text variants, render pipeline, ownership decision, IDA caller and boundary evidence, caveats, range correction, and cross-references; confidence is high because class behavior and grouping are strongly supported.
