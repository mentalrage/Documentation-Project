*** UID:0000HL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AttachmentAnchorResolver

## Status

- Confidence: strong for helper role and exact ranges; medium for standalone original file split.
- Proposed module: `map/AttachmentAnchorResolver.cpp`, possibly private inside `map/AttachedObjectPane.cpp`.
- Current generated source: `source-3/simroot_v2/class_AttachmentAnchorResolver.cpp`
- Primary class doc: [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- Main address doc: [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md)

## File Role

`AttachmentAnchorResolver` is a small map-object placement helper. It combines an image index, local x/y offsets, and a source object pointer to produce either an anchor screen point or a translated bounds rectangle for attached overlays.

The helper belongs near [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) because it is called by attached-object sync/attach paths and by related overlay/object-pane variants. It should not be pulled into [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md) just because it sits between lighting lifecycle and intensity functions in memory.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `AttachmentAnchorResolver` | `0x0053c700-0x0053c92e` | Shared placement helper for object-attached overlays and image bounds. |
| anchor point resolver | `0x0053c700-0x0053c802` | Resolves a source object's anchor mode into a screen point and applies local offsets. |
| `ComputeScreenBounds` | `0x0053c810-0x0053c92e` | Initializes image bounds from `g_pAttachmentImageBounds`, resolves the anchor point, and offsets the rectangle. |

## Boundary Notes

- Active generated source emits only `ComputeScreenBounds` at `0x0053c810`; IDA confirms the preceding `0x0053c700-0x0053c802` helper is real and behaviorally part of the same resolver family.
- The helper uses [UID:0000L3][MapPane](by-file/MapPane.md) coordinate conversion and [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md) attached-position logic for source anchor modes `2` and `4`.
- Current `simroot_v2` metadata mentions this helper from many unrelated classes because they carry xref context. Those references are consumers, not owners.

## Cross-References

- [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)

## Changes

- What existed before: the page documented resolver role and boundary notes but had unevaluated scores.
- What it was changed to: scores were set to `68/82`.
- Summary and evidence: helper range and behavior are strong, but the standalone source-file split remains provisional because the resolver may fold into `AttachedObjectPane.cpp`.
