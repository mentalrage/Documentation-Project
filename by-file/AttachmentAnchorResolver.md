*** UID:0000HL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AttachmentAnchorResolver

## Status

- Confidence: strong for helper role, exact ranges, and `NexusTK/map/` placement; medium for standalone original file split versus folding into [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- Proposed module: `NexusTK/map/AttachmentAnchorResolver.cpp`, possibly private inside `map/AttachedObjectPane.cpp`.
- Documentation basis: IDA-confirmed anchor resolver and light-apply ranges plus the class, memory, file, and source-tree docs listed below.
- Primary class doc: [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- Main address doc: [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md)
- Newly split raw/modeled neighbors: [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md), [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md), [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md), and [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md)
- Reconstruction state: keep the projected path as `NexusTK/map/` until the final file split is settled; no final C++ is emitted below the 95/95 reconstruction gate.

## File Role

`AttachmentAnchorResolver` is a small map-object placement helper. It combines an image index, local x/y offsets, and a source object pointer to produce either an anchor screen point or a translated bounds rectangle for attached overlays.

The helper belongs near [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) because it is called by attached-object sync/attach paths and by related overlay/object-pane variants. It should not be pulled into [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md) just because it sits between lighting lifecycle and intensity functions in memory.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| raw image/bounds metric helper | [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) | Unreferenced code-shaped table metric helper using the resolver-local image/table index. |
| `AttachmentAnchorResolver` | [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md) | Shared placement helper for object-attached overlays and image bounds. |
| anchor point resolver | `0x0053c700-0x0053c802` | Resolves a source object's anchor mode into a screen point and applies local offsets. |
| `ComputeScreenBounds` | `0x0053c810-0x0053c92e` | Initializes image bounds from `g_pAttachmentImageBounds`, resolves the anchor point, and offsets the rectangle. |
| raw screen-bounds notification helper | [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md) | Unreferenced code-shaped helper that computes bounds and passes them to a global map/pane virtual slot. |
| `ApplyLightAtAnchor` / light-table apply helper | [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) | Caller-backed helper that applies global light table slot `+0x0c` at the resolved anchor point. |
| raw light-table twin helper | [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md) | Unreferenced code-shaped twin that calls global light table slot `+0x10`. |

## Boundary Notes

- The by-* inventory now covers `0x0053c700`, `0x0053c810`, and `0x0053c9c0` as AttachmentAnchorResolver-owned helpers; IDA confirms the modeled function boundaries and caller-backed relationship for `0x0053c9c0`.
- IDA still reports no function object and no xrefs for the raw code-shaped helper starts at `0x0053c6b0`, `0x0053c930`, and `0x0053c9f0`; keep them as documented raw siblings until reachability is proven.
- The helper uses [UID:0000L3][MapPane](by-file/MapPane.md) coordinate conversion and [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md) attached-position logic for source anchor modes `2` and `4`.
- Recovered-output xref context has mentioned this helper from many unrelated classes because they carry consumer context. Those references are consumers, not owners.

## Attachment State

- This file root is the current parent for [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md); both now clear the 80% completion/confidence parent gate.
- The attached modeled memory children cover the resolver/bounds pair and light-table apply helper. The raw image metric, screen-bounds notification, and light-table twin pages stay as adjacent raw siblings until reachability is proven.
- Do not merge this root into [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md). The lighting-adjacent ranges have separate ownership notes, and this file's callers are attached-object/map overlay consumers.

## Cross-References

- [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md)
- [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md)
- [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md)
- [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md)
- [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)

## Changes

- What existed before: the page documented resolver role and boundary notes but had unevaluated scores.
- What it was changed to: scores were set to `68/82`.
- Summary and evidence: helper range and behavior are strong, but the standalone source-file split remains provisional because the resolver may fold into `AttachedObjectPane.cpp`.
- 2026-06-03 path/split update:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, recovered-output notes were stale about `0x0053c700`, and adjacent helper islands around `0x0053c6b0`, `0x0053c930`, `0x0053c9c0`, and `0x0053c9f0` were not integrated into the file map.
  - Changed to: `76/84`, path `NexusTK/map/`, exact sibling pages for the raw/modeled helper islands, and an explicit caveat that the standalone file may still fold into `AttachedObjectPane.cpp`.
  - Evidence: restarted IDA MCP boundary, xref, caller-context, decompilation, and raw pointer-scan checks plus the existing project source tree placement under `map/`.
- 2026-06-06 provenance cleanup:
  - Scores and projected path unchanged.
  - Summary/evidence: replaced stale output-provenance framing with the current IDA/by-* evidence basis. The page still keeps the standalone-file-versus-`AttachedObjectPane.cpp` fold as the main unresolved source-layout caveat.
- 2026-06-06 attachment-gate cleanup:
  - Before: the file root remained `76/84` with child attachment already present but without an explicit parent-gate rationale.
  - Changed to: `82/84`, source-layout caveat kept, reconstruction-state and attachment-state notes added, and no final C++ emitted.
  - Evidence: existing by-class/by-memory pages document the exact modeled ranges, raw sibling exclusions, caller-backed light-apply helper, map placement, and LightingObjectPane exclusion; the unresolved work is final source layout and names.
