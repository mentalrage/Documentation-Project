*** UID:00000U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BalloonObjectPane

## Status

- Confidence: strong for behavior and most anchors; boundary caveat for `0x00468250` in IDA.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_BalloonObjectPane.cpp`
- Current Wave3 grade: `95.7`
- Current Wave3 coverage: 12 modeled methods, zero missing target refs.

## Class Purpose

`BalloonObjectPane` renders and positions speech balloons attached to map objects. It wraps chat text into lines, creates a cached GrafPort, draws the balloon frame/tail/text, and moves the balloon relative to the speaking object's screen position.

## Class Shape

- Base family: [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)-derived overlay pane.
- Render state: cached bubble surface/GrafPort, wrapped text lines, frame/tail dimensions, color state, and current bounds.
- Placement role: repositions relative to attached object screen coordinates and direction-specific offsets.
- Source placement: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), near other attached-object overlay panes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PaintBubble` | `0x00467b30-0x00468241` | Draws balloon frame pieces, optional tail, colors, and text lines. |
| `RefreshBubbleSurface` | `0x00468250-0x004682bb` | Repaints cached GrafPort if the bubble bounds are non-empty; modeled by Wave3/Ghidra, not currently an IDA function record. |
| constructor | `0x004682c0-0x0046849c` | Builds the attached-object base, stores text/color state, and initializes layout/surface state. |
| `UpdatePositionForDirection` | `0x00468520-0x004687fc` | Repositions balloon for a direction-relative owner offset. |
| `UpdatePosition` | `0x00468800-0x00468aab` | Repositions the balloon based on current attached screen position. |
| `ClearBounds` | `0x00468ab0-0x00468ada` | Clears output bounds. |
| `MoveBubbleGrafPort` | `0x00468ae0-0x00468b81` | Moves the cached bubble GrafPort to the target position. |
| `CalculateLayout` | `0x00468b90-0x00468df1` | Wraps text, computes balloon dimensions, and updates tail placement. |
| destructor | `0x00468f80-0x0046904e` | Releases cached surface and attached base state. |
| `GetAttachedScreenPos` | `0x005386c0-0x005387a3` | Shared attached-screen-position helper used by multiple overlays. |

## Evidence Notes

- IDA confirms all listed anchors except `0x00468250`; Wave3/Ghidra have a prologue/disassembly and imported range for that method.
- MapPane speech packet handlers at `0x0050e100` and `0x00511710` construct the balloon. Wave3 currently reports `0x0050e100` as unknown.
- `PaintBubble` calls the generic [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md), which helps disprove their current generated ownership under `UserHairColorSelectListPane`.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md)

## Changes

- What existed before: the page documented the render/layout/positioning methods and IDA boundary caveat but had unevaluated scores.
- What it was changed to: scores were set to `76/86`, and class-shape notes were added for base family, render state, placement role, and source placement.
- Summary and evidence: most anchors are IDA-confirmed and the map speech packet constructors are known; completion remains below full because one imported method lacks an IDA function record and final text/layout fields need fuller reconstruction.
