*** UID:0000CM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address ranges: `0x0055c200-0x0055de98`
- Current recovered file: `source-3/simroot_v2/class_ScrollPane.cpp`

## Class Purpose

`ScrollPane` is the visible scrollbar pane. It stores scrollbar orientation, range, current position, pressed/hot part state, thumb visibility, drag anchor state, and style index. It draws both classic `SCRL001` scrollbar assets and newer EPF skin assets.

## Observed State

Important recovered state:

```text
orientation  0 = vertical, 1 = horizontal
scrollRange  nonzero range enables the thumb
pressedPart  0 = start button, 2 = thumb, 4 = end button
part ids     0 = first button, 1 = track before thumb, 2 = thumb,
             3 = track after thumb, 4 = second button
```

The constructor initializes the scrollbar as a `Pane`, sets three vtable pointers, clears range, sets default flags, and stores an initial `(0, 0)` scroll position.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/state | `0x0055c200`, `0x0055c3e0` | Initializes pane/vtables and tests whether the scroll thumb should be visible. |
| Input/timer | `0x0055c400-0x0055c642` | Mouse handling, default `CanScroll`, and repeat timer callback into the owner scroll handler. |
| Drawing | `0x0055c650-0x0055d957` | Draws classic and EPF scrollbar modes using scrollbar part rectangles. |
| Geometry | `0x0055d9e0-0x0055de98` | Computes button, track, and thumb rectangles for vertical/horizontal bars. |

## Evidence Notes

- `ScrollablePane::ScrollablePane` constructs `ScrollPane(1)` and `ScrollPane(0)` for horizontal and vertical scrollbars.
- `ScrollPane::OnDraw` loads `SCRL001.EPD`/`SCRL001.PAD` in classic mode and `SLIDEBG.EPF`, `SCRBUTT.EPF`, `SLIDEBG.PAL`, and `BUTTON.PAL` in EPF mode.
- IDA MCP reports `ScrollPane::GetScrollPartRect` has 15 direct call references, mostly from `ScrollPane::OnDraw` and `TextEditPane` scrollbar handlers.
- Generated `OnScrollTimer` subtracts `164` bytes from `this` and calls `TextEditPane::UpdateScrollbarCursor`, which suggests this pane is often embedded as a subobject inside richer scroll owners.

## Current Caveats

- Current generated source uses unrelated feature-class names for generic drawing helpers such as clip-rect, frame blit, and text color. Treat those names as provisional until the helper owners are cleaned up.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)
- [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented scrollbar responsibility, observed state, method families, constructor users, drawing resources, and current helper-owner caveats.
  - After: changed completion/confidence to `78/82`.
  - Evidence: existing method-family table, evidence notes, generated-source caveats, endpoint correction, and ScrollablePane/ScrollWidget cross-references support strong behavior confidence with moderate remaining helper-owner cleanup.

- 2026-05-28: Corrected `ScrollPane` input/draw memory endpoints.
  - Before: cross-references used `0x0055c200-0x0055c642` and `0x0055c650-0x0055d956`.
  - After: IDA-backed endpoints are `0x0055c200-0x0055c643` and `0x0055c650-0x0055d957`; following bytes are padding.
  - Evidence: 2026-05-28 IDA MCP reports `sub_55C610` as `0x0055c610-0x0055c643` and `sub_55C650` as `0x0055c650-0x0055d957`.
- [UID:0001GK][0x0055d9e0-0x0055de98.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de98.ScrollPaneGetScrollPartRect.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md)
- [UID:0000A2][Pane](by-class/Pane.md)
