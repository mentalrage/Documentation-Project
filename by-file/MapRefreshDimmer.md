*** UID:0000L4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MapRefreshDimmer

## Status

- Confidence: strong for class behavior and anchors; medium for whether this was standalone or file-local in `MapPane.cpp`.
- Proposed module: `map/MapRefreshDimmer.cpp`, or a private helper in [UID:0000L3][MapPane](by-file/MapPane.md)
- Current generated source: `class_MapRefreshDimmer.cpp`
- Primary class doc: [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md)
- Main address doc: [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md)

## File Role

`MapRefreshDimmer` is a short-lived map transition/fade helper. It builds on the generic [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) overlay behavior, installs a timer during construction, and deletes itself once the fade timer expires.

The class belongs with map transition code rather than generic dimmer UI unless later caller evidence shows wider reuse.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `MapRefreshDimmer` | `0x00514920-0x00514a0d`, destructor wrapper at `0x00514e20` | Timer-backed map refresh/loading dimmer. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction/timer setup | `0x00514920` | Constructs pane state and schedules the transition timer. |
| Timer expiration | `0x005149f0` | Deletes the helper when fade-out completes. |
| Destruction | `0x00514e20` | Destroys base state and conditionally frees storage. |

## Boundary Notes

- IDA confirms `0x00514920`, `0x005149f0`, and `0x00514e20` as exact starts.
- The range is sparse because only three child methods are modeled; do not claim the full `0x00514920-0x00514e5b` span as continuous class logic.
- Keep this helper near [UID:0000L3][MapPane](by-file/MapPane.md) map-change and transition code, but keep its generic dimmer base/companion logic documented under [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).

## Cross-References

- [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md)
- [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)

## Changes

- 2026-05-28: Corrected the sparse range endpoint from `0x00514e5a` to `0x00514e5b`. Evidence: IDA MCP reports the scalar deleting destructor at `0x00514e20-0x00514e5b`; the prior endpoint omitted the final immediate byte of `retn 4`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:80`.
  - Summary/evidence: map transition dimmer role, constructor/timer/destructor families, sparse-range caveat, ScreenDimmer boundary, cross-references, and endpoint correction are documented; completion is moderate because the helper is small and source placement still depends on the broader `MapPane` split.
