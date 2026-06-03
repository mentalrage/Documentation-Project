*** UID:00000O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AttachmentAnchorResolver

## Status

- Confidence: strong for behavior, modeled ranges, caller-backed light apply helper, and raw-neighbor caveats.
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
| raw image/bounds metric helper | [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) | Code-shaped no-function island that selects a global image/bounds table entry by `+0x128`; reachability unresolved. |
| probable `ResolveAnchorPoint` | `0x0053c700-0x0053c802` | Resolves the source anchor into a screen point; current generated output emits this helper, but final field/type names remain provisional. |
| `ComputeScreenBounds` | `0x0053c810-0x0053c92e` | Builds the image bounds rectangle and offsets it to the resolved anchor point plus local offsets. |
| raw screen-bounds notification helper | [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md) | Code-shaped no-function island that calls `ComputeScreenBounds` and passes the rectangle through a global map/pane virtual slot. |
| `ApplyLightAtAnchor` / light-table apply helper | [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) | Live caller-backed helper used after bounds/intersection and anchor-point resolution; calls global light table slot `+0x0c`. |
| raw light-table twin helper | [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md) | Code-shaped no-function twin that calls global light table slot `+0x10`; reachability unresolved. |

## Layout Notes

- Inferred fields include `imageIndex` at `+0x128`, `localOffsetY` at `+0x12c`, `localOffsetX` at `+0x130`, and `anchorSource` at `+0x134`.
- Anchor mode `3` uses world coordinates plus optional tile-offset scaling.
- Anchor modes `2` and `4` use `BalloonObjectPane::GetAttachedScreenPos`.
- Other modes fall back to world-to-screen conversion through [UID:0000L3][MapPane](by-file/MapPane.md).
- The `+0x128` field is used as the image/bounds table index in `0x0053c810` and as the light-table index in `0x0053c9c0`; keep the final field name provisional until the shared table semantics are audited.

## Evidence Notes

- 2026-06-03 restarted IDA MCP confirms modeled functions at `0x0053c700-0x0053c802`, `0x0053c810-0x0053c92e`, and `0x0053c9c0-0x0053c9eb`.
- IDA reports no function object, no start xrefs, and no raw pointer hits for the raw helper starts at `0x0053c6b0`, `0x0053c930`, and `0x0053c9f0`.
- The `0x0053c9c0` callers at `0x005096cc` and `0x0050aacf` first call `0x0053c810`, test the screen bounds, then call `0x0053c700` and pass the resolved anchor point into `0x0053c9c0`.

## Cross-References

- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md)
- [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md)
- [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md)
- [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md)
- [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md)
- [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- What existed before: the page identified the resolver methods and inferred fields but remained scored as unevaluated.
- What it was changed to: scores were set to `70/84`, and class-shape notes were added for role, state, coordinate dependencies, and source placement.
- Summary and evidence: the compact by-memory range and field/mode notes support strong behavior confidence; completion stays moderate because the generated output omits one helper and the final field names still need direct C++ reconstruction.
- 2026-06-03 raw-neighbor update:
  - Before: the method inventory only covered `0x0053c700` and `0x0053c810`, and still said active generated output omitted `0x0053c700`.
  - Changed to: `76/86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) at position `10`, and method inventory expanded with raw siblings at `0x0053c6b0`, `0x0053c930`, `0x0053c9f0`, plus modeled light-apply helper `0x0053c9c0`.
  - Evidence: restarted IDA MCP function/xref checks, caller-context disassembly, decompilation of `0x0053c9c0`, raw pointer scans, and current `simroot_v2` source/source-map.
