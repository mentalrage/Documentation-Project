*** UID:0000L2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MapNamePane

## Status

- Confidence: strong for class behavior, live construction sites, vtables, singleton lifecycle, and map folder ownership; medium-high for whether this was standalone or file-local in `MapPane.cpp`.
- Proposed module: `NexusTK/map/MapNamePane.cpp`, or a private helper in [UID:0000L3][MapPane](by-file/MapPane.md)
- Current materialization: documentation-only; final C++ remains intentionally blank until the original source shape is stronger.
- Primary class doc: [UID:00007P][MapNamePane](by-class/MapNamePane.md)
- Main address doc: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)

## File Role

`MapNamePane` is the small map-name overlay pane. It initializes the current-map-name pane, manages map-name resource/font state, draws centered map-name text, and releases global/resource state during teardown.

This is map UI, not generic text-control code. It should stay in the map feature folder even if the final source split folds it back into `MapPane.cpp`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `MapNamePane` | `0x005031f0-0x00503574`, destructor helpers at `0x005037f0`, `0x0050380b`, `0x00503816`, and `0x00503840` | Pane lifecycle, map-name rendering, packet/update handling, global active pointer, and resource cleanup. |
| adjustor thunks | `0x0050380b`, `0x00503816` | Compiler/vtable thunks that forward to scalar deleting destructor. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction/resource setup | `0x005031f0` | Initializes pane state, `g_pMapNamePane`, and map-name resource lookup state. |
| Resource cleanup | `0x005032d0`, `0x00503840` | Releases resources, clears global state, and conditionally frees the pane. |
| Rendering | `0x00503350` | Draws centered map-name text using resource-backed or fallback text rendering. |
| Map-name updates | `0x005034a0` | Handles opcode `0x15`, converts incoming byte-string map names to UTF-16, clamps/ellipsizes the display buffer, and requests a pane redraw. |

## Boundary Notes

- 2026-06-05 live IDA confirms `0x005031f0`, `0x005032d0`, `0x00503350`, `0x005034a0`, `0x005037f0`, `0x0050380b`, `0x00503816`, and `0x00503840` as exact starts.
- Live IDA confirms primary/secondary/tertiary `MapNamePane` vtables at `0x0061e5b4`, `0x0061e600`, and `0x0061e630`; render slot `0x0061e5f8` targets `0x00503350`, and update-handler slot `0x0061e610` targets `0x005034a0`.
- Constructor xrefs from the main UI setup path at `0x004f8051` and `0x004f8695` support map UI ownership and two layout placements.
- IDA also confirms [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) starts at `0x00503580`, so the old MapName-only aggregate span crosses a separate minimap button class.
- Keep `0x0050380b` and `0x00503816` documented as thunks, but do not migrate them as source-level logic.
- 2026-06-07 Batch 043 live IDA MCP reconfirmed `0x0069b4b4-0x0069b4b8` as a clean `0xffffffff` singleton item with six xrefs: constructor publish/fallback writes, destructor clear, singleton helper clear, scalar deleting destructor clear, and an external map-side reader. The exact storage now has a split page [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) and a canonical global page [UID:0002XC][g_pMapNamePane](by-global/g_pMapNamePane.md).

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
- 2026-06-05 live IDA rescore and path staging:
  - Changed from: `COMPLETION:82`, `CONFIDENCE:80`, and blank `PROPOSED_RECONSTRUCTION_PATH`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Reason for score increase: live IDA confirmed the missing `0x005034a0` map-name update handler, singleton-clear helper, vtable slot map, constructor callers, singleton lifecycle refs, exact function sizes, and internal padding around the interleaved MiniMapButtonPane island. The score remains below final reconstruction because the final standalone-vs-file-local split and source-level field/helper names are still unresolved.
- 2026-06-07 Batch 043 split-parent note:
  - Score unchanged at `86/86`.
  - Evidence: live IDA MCP reconfirmed the exact singleton slot and all six xrefs; this page already clears the corrected `85/85` gate for the new direct global page and exact memory split.
