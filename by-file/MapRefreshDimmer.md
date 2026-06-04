*** UID:0000L4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MapRefreshDimmer

## Status

- Confidence: strong for class behavior, vtable anchors, and map-side construction evidence; medium for whether this was standalone or file-local in `MapPane.cpp`.
- Proposed module: `NexusTK/map/MapRefreshDimmer.cpp`, or a private helper in [UID:0000L3][MapPane](by-file/MapPane.md)
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
| Construction/timer setup | `0x00514920`, inline branch in `0x00506df0` | Constructs pane state and schedules the transition timer. |
| Timer expiration | `0x005149f0` | Deletes the helper when fade-out completes. |
| Interface adjustors/destruction | `0x00514d34`, `0x00514d3f`, `0x00514e20` | Adjusts secondary/tertiary interface pointers, destroys base state, and conditionally frees storage. |

## Boundary Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA confirms `0x00514920`, `0x005149f0`, `0x00514d34`, `0x00514d3f`, and `0x00514e20` as exact starts.
- The constructor calls the generic `ScreenDimmer` constructor with dim level `3`, writes MapRefreshDimmer vtables at offsets `0`, `0xa0`, and `0xa4`, then starts a timer through `0x005975e0` with interval `2000`.
- `sub_506DF0`, a MapPane-side input handler, contains the visible construction branch: it allocates `0xfc` bytes, runs the `ScreenDimmer` base setup, installs the same MapRefreshDimmer vtables, starts the two-second timer, and continues map refresh work.
- The vtable block confirms `??_7MapRefreshDimmer@@6B@` at `0x0061e858`, secondary table `0x0061e8a4`, tertiary table `0x0061e8d4`, timer callback slot `0x0061e8d8 -> 0x005149f0`, and deleting destructor slot `0x0061e858 -> 0x00514e20`.
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
- 2026-06-04 path and score update:
  - Before: scored as `78/80`, with a blank proposed path and only partial evidence for the map placement decision.
  - After: scored as `86/88` and assigned `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Summary/evidence: live IDA MCP rechecked the executable identity, exact function starts, `ScreenDimmer` base call, three vtable writes, two-second timer setup, adjustor thunks, deleting destructor behavior, timer callback vtable slot, and the MapPane-side inline construction branch in `sub_506DF0`; this proves map-folder ownership, while standalone-file versus private-helper placement remains open.
