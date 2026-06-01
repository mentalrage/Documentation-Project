*** UID:0000L2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MapNamePane

## Status

- Confidence: strong for class behavior and anchors; medium for whether this was standalone or file-local in `MapPane.cpp`.
- Proposed module: `map/MapNamePane.cpp`, or a private helper in [UID:0000L3][MapPane](by-file/MapPane.md)
- Current generated source: `class_MapNamePane.cpp`
- Primary class doc: [UID:00007P][MapNamePane](by-class/MapNamePane.md)
- Main address doc: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)

## File Role

`MapNamePane` is the small map-name overlay pane. It initializes the current-map-name pane, manages map-name resource/font state, draws centered map-name text, and releases global/resource state during teardown.

This is map UI, not generic text-control code. It should stay in the map feature folder even if the final source split folds it back into `MapPane.cpp`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `MapNamePane` | `0x005031f0-0x0050349f`, destructor wrapper at `0x00503840` | Pane lifecycle, map-name rendering, global active pointer, and resource cleanup. |
| adjustor thunks | `0x0050380b`, `0x00503816` | Compiler/vtable thunks that forward to scalar deleting destructor. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction/resource setup | `0x005031f0` | Initializes pane state, `g_pMapNamePane`, and map-name resource lookup state. |
| Resource cleanup | `0x005032d0`, `0x00503840` | Releases resources, clears global state, and conditionally frees the pane. |
| Rendering | `0x00503350` | Draws centered map-name text using resource-backed or fallback text rendering. |

## Boundary Notes

- IDA confirms `0x005031f0`, `0x005032d0`, `0x00503350`, `0x00503816`, and `0x00503840` as exact starts.
- IDA also confirms [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) starts at `0x00503580`, so the old MapName-only aggregate span crosses a separate minimap button class.
- Keep `0x0050380b` and `0x00503816` documented as thunks, but do not migrate them as source-level logic.
- Constructor xrefs from the login/startup UI path around `0x004f8051` and `0x004f8695` support map UI ownership.

## Cross-References

- [UID:00007P][MapNamePane](by-class/MapNamePane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AK][0x005031f0-0x005038fd.MapNamePane](by-memory/0x005031f0-0x005038fd.MapNamePane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-28: Updated the main address document reference from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the adjacent `MiniMapButtonPane` scalar deleting destructor ending at `0x0050395f`, with `0x0050395e` as the final immediate byte.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: map-name overlay role, constructor/render/cleanup families, boundary notes, minimap-button split, constructor xrefs, and corrected memory reference are documented; confidence is capped by whether it was standalone or file-local in `MapPane.cpp`.
