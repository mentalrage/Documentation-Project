*** UID:00000O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AttachmentAnchorResolver

## Status

- Confidence: strong for behavior and ranges.
- Likely source file: [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md)
- Current recovered file: `source-3/simroot_v2/class_AttachmentAnchorResolver.cpp`

## Class Purpose

`AttachmentAnchorResolver` is a compact helper used by attached map-object overlays. It stores an image index, local offsets, and an anchor-source pointer, then converts the source object's anchor mode and world/tile position into screen-space coordinates or a translated bounds rectangle.

## Class Shape

- Role: attachment placement helper for overlay panes that need screen-space anchors.
- Stored state: image index, local X/Y offsets, and anchor-source pointer.
- Coordinate dependencies: uses `BalloonObjectPane` attached-position helpers for selected anchor modes and falls back through [UID:0000L3][MapPane](by-file/MapPane.md) world-to-screen conversion.
- Source placement: [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md), likely adjacent to attached-object overlay code.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| probable `ResolveAnchorPoint` | `0x0053c700-0x0053c802` | Resolves the source anchor into a screen point; active generated output currently omits this helper. |
| `ComputeScreenBounds` | `0x0053c810-0x0053c92e` | Builds the image bounds rectangle and offsets it to the resolved anchor point plus local offsets. |

## Layout Notes

- Inferred fields include `imageIndex` at `+0x128`, `localOffsetY` at `+0x12c`, `localOffsetX` at `+0x130`, and `anchorSource` at `+0x134`.
- Anchor mode `3` uses world coordinates plus optional tile-offset scaling.
- Anchor modes `2` and `4` use `BalloonObjectPane::GetAttachedScreenPos`.
- Other modes fall back to world-to-screen conversion through [UID:0000L3][MapPane](by-file/MapPane.md).

## Cross-References

- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md)
- [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- What existed before: the page identified the resolver methods and inferred fields but remained scored as unevaluated.
- What it was changed to: scores were set to `70/84`, and class-shape notes were added for role, state, coordinate dependencies, and source placement.
- Summary and evidence: the compact by-memory range and field/mode notes support strong behavior confidence; completion stays moderate because the generated output omits one helper and the final field names still need direct C++ reconstruction.
