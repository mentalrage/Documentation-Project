*** UID:00000U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BalloonObjectPane

## Status

- Confidence: strong for behavior, vtable ownership, constructor callers, and all IDA-modeled methods; medium-high for raw repaint helper at `0x00468250`.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)

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
| raw `RefreshBubbleSurface` helper | `0x00468250-0x004682bb` | Repaints cached GrafPort if bounds are non-empty; live IDA marks the bytes as code but still has no function object at the entry. |
| constructor | `0x004682c0-0x0046849c` | Builds the attached-object base, stores text/color state, and initializes layout/surface state. |
| constructor cleanup helper | `0x004684a0-0x0046851d` | Resets vtables, releases owner/cached GrafPort state, and tears down the attached base. |
| `UpdatePositionForDirection` | `0x00468520-0x004687fc` | Repositions balloon for a direction-relative owner offset. |
| `UpdatePosition` | `0x00468800-0x00468aab` | Repositions the balloon based on current attached screen position. |
| `ClearBounds` | `0x00468ab0-0x00468ada` | Clears output bounds. |
| `MoveBubbleGrafPort` | `0x00468ae0-0x00468b81` | Moves the cached bubble GrafPort to the target position. |
| `CalculateLayout` | `0x00468b90-0x00468df1` | Wraps text, computes balloon dimensions, and updates tail placement. |
| adjustor thunks | `0x00468f65-0x00468f7b` | Secondary and tertiary this-adjustors for the deleting destructor. |
| destructor | `0x00468f80-0x0046904e` | Releases cached surface and attached base state. |
| `GetAttachedScreenPos` | `0x005386c0-0x005387a3` | Shared attached-screen-position helper used by multiple overlays. |

## Evidence Notes

- Live IDA MCP on 2026-06-04 confirms function objects at every method entry listed above except the raw `0x00468250` helper. That helper is still code bytes with a prologue, security cookie, cached GrafPort check, bounds check, `PaintBubble` call, and unlock/return sequence.
- MapPane speech packet handlers at `0x0050e100` and `0x00511710` construct the balloon at call sites `0x0050e1b9` and `0x00511906`, then register the overlay through `0x0053ada0`.
- Constructor decompilation installs BalloonObjectPane vtables at `0x00613064`, `0x006130dc`, and `0x0061310c`, clamps copied text to `0x45` wide characters, stores layout/color fields, allocates a cached GrafPort at `+0x1dc`, runs `CalculateLayout`, and performs an initial `PaintBubble`.
- Vtable data places `ClearBounds`, `MoveBubbleGrafPort`, the shared ObjectPane empty-rect helper, and the two update-position methods in the primary BalloonObjectPane vtable, with secondary destructor adjustors in the two secondary slices.
- `PaintBubble` references the six [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) entries and uses GrafPort/palette/text draw helpers. `CalculateLayout` calls the text width helper at `0x004b6020` and the MapPane visibility/overlap helper at `0x005062f0`.
- `PaintBubble` calls the generic [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md), which helps disprove assigning those shared helpers to `UserHairColorSelectListPane`.

## Score Rationale

Raised to `84/90` on 2026-06-04 because live IDA confirms the constructor callers, vtables, method ranges, raw repaint helper body, static-mask usage, layout/update dependencies, and destructor cleanup path. Completion remains below final-source level because field names and the raw `0x00468250` function record are still not source-final, and no C++ reconstruction is emitted.

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

- 2026-06-04 live IDA aggregate pass:
  - What existed before: the class page was scored `76/86`, reconstructable/parent metadata was blank, and it retained stale generated-file and non-IDA boundary wording.
  - What it was changed to: raised to `84/90`, marked reconstructable under [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), replaced the boundary basis with live IDA evidence, added the constructor cleanup helper and destructor adjustor thunks, and recorded constructor/vtable/static-mask evidence.
  - Summary/evidence: live IDA verifies the modeled methods, raw `0x00468250` repaint body, two constructor callers, vtable slices at `0x00613064/0x006130dc/0x0061310c`, `PaintBubble` mask/data refs, and destructor cleanup through the cached GrafPort and attached base.
