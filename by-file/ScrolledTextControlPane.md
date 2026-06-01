*** UID:0000NI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrolledTextControlPane

## Status

- Confidence: strong.
- Proposed module: `ui/controls/ScrolledTextControlPane.cpp`
- Proposed header: `ui/controls/ScrolledTextControlPane.h`
- Current recovered sources: `source-3/simroot_v2/class_ScrolledTextControlPane.cpp` and `class_ScrolledTextControlPaneForMadeBy.cpp`
- Main address clusters: `0x004ff040-0x004ff7cc` and `0x00502b60-0x00502cbd`

## File Role

This module owns auto-scrolling static text controls. Both variants load text from a DAT/resource path, convert it through `TextEditScrap`, render the text once through a temporary [UID:0000ON][TextEditPane](by-file/TextEditPane.md), store the rendered result in an image/tile context, and scroll/blit that pre-rendered image on timer ticks.

`ScrolledTextControlPaneForMadeBy` is a specialized credits/"made by" variant that scrolls faster and closes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) when the content reaches the end.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScrolledTextControlPane` | `0x004ff040-0x00502c0c` in child ranges | Generic auto-scrolling text control; control type `8`, DAT text load, temporary text edit render, timer scroll, and blit draw. |
| `ScrolledTextControlPaneForMadeBy` | `0x004ff400-0x00502cbd` in child ranges | Credits/attribution variant; same render pipeline with dialog close at end of scroll. |
| `g_pNewHistoryDialog` | `0x0069b49c` | Used by the credits variant to close the active `NewHistoryDialogPane` after scrolling completes. |

## Ownership Decision

Keep both classes in one scrolled-text control module. Their constructors, timers, draw paths, and destructors are nearly parallel, and both use the same resource-to-rendered-text pipeline.

Keep this separate from [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md). Static text controls render current pane text directly; scrolled text controls pre-render DAT text into an image region and scroll that image by timer.

Keep [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md) as the sibling picture-scroller module. It shares the timer/scrolling control pattern, but it loads EPF frame and palette resources instead of rendering DAT text through `TextEditPane`.

## Evidence Notes

- IDA MCP reports four direct references to `ScrolledTextControlPane::ScrolledTextControlPane` at `0x004ff040`.
- IDA MCP reports one direct reference to `ScrolledTextControlPaneForMadeBy::ScrolledTextControlPaneForMadeBy` at `0x004ff400`.
- 2026-05-28 IDA MCP reports the `ScrolledTextControlPaneForMadeBy` scalar deleting destructor at `0x00502c10-0x00502cbd`; `0x00502cbc` is the final `retn 4` immediate byte, not padding.
- Both constructors call `ControlPane` with type `8`, allocate a temporary 372-byte `TextEditPane`, set it read-only/non-editable, render it, copy the resulting `GrafPort`/tile context into the scrolled control, then delete the temporary text pane.
- `ScrolledTextControlPane::OnTimerTick` increments the scroll offset by one and wraps to zero.
- `ScrolledTextControlPaneForMadeBy::OnTimerEvent` increments by two and calls close-dialog behavior on `g_pNewHistoryDialog` when the end is reached.

## Current Caveats

- Generated destructor support references unrelated base names such as `TextButtonExControlPane::~Pane`; treat those as base-owner pollution until vtables/subobject offsets are reconciled.
- The generated source alternates between `EPFTileContext`, `ImageRegion`, and `GrafPort` names for similar embedded render storage. The high-level pipeline is clear, but the field names are provisional.

## Cross-References

- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)
- [UID:00019W][0x004ff040-0x00502c0c.ScrolledTextControlPane](by-memory/0x004ff040-0x00502c0c.ScrolledTextControlPane.md)
- [UID:00019X][0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy](by-memory/0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy.md)
- [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md)
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- Before: the file-level range summary ended `ScrolledTextControlPaneForMadeBy` at `0x00502cbc`.
- After: the file-level range summary ends it at `0x00502cbd`.
- Why: IDA MCP confirms `0x00502cbc` is the final operand byte of the scalar deleting destructor return instruction, so the following padding starts at `0x00502cbd`.
- Evidence: 2026-05-28 IDA MCP decompile/function-boundary check for `0x00502c10` and raw bytes `00 cc cc cc` at `0x00502cbc-0x00502cc0`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `86`.
  - Evidence: document captures both scrolled-text variants, render pipeline, ownership decision, IDA caller and boundary evidence, caveats, range correction, and cross-references; confidence is high because class behavior and grouping are strongly supported.
