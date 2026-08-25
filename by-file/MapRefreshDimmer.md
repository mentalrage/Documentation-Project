*** UID:0000L4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MapRefreshDimmer

## UID00037R Ctrl+R Initiation And Private Placement - 2026-08-24

- Exact consumer [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) keeps this helper private in `NexusTK/map/MapPane.cpp`. Ctrl+R checks `g_pTransferServerDialog` at `0x00506f81`, then starts inline MapRefreshDimmer construction at `0x00506f93` only when that global is null.
- The inline copy matches the retained constructor: complete/EventHandler/TimerHandler vptr stores at `0x00506fcf/0x00506fd5/0x00506fdf`, ScreenDimmer setup, and timer 0 scheduled for 2000 ms. The source then sends one-byte opcode `0x38`, sets both visible/full-map refresh flags, and invokes ObjectList mark then row-prune preparation.
- Packet opcode `0x22` remains the completion side of this same protocol and timer id 0 remains the timeout side. This semantic file stays a `91/93` historical index with no independent generated source; the declaration routes through UID00007Q at position `0` and exact definitions remain direct MapPane.cpp positions 2-4.
- Validator readback after UID00037R gained formal code showed why the declaration edge must precede unpositioned MapPane methods: a direct file position sorted after the complete UID00007Q subtree and left `new MapRefreshDimmer` before the class definition. The corrected UID00007Q position `0` edge restores compile-visible ordering without changing the private source file, class owner, method positions, or UID00037R's required blank position.
- The declaration formal omits `[[CHILDREN]]` because all three method pages emit directly to UID0000L3 at positions 2-4. Generated MapPane.cpp therefore contains no `[[No Children Attached]]` fallback token for this class.

## Status

- Confidence: very strong for class behavior, vtable anchors, and private MapPane.cpp source placement.
- Disposition: historical semantic file index only; there is no separate generated `MapRefreshDimmer.cpp` emitter.
- Actual source module: private helper in [UID:0000L3][MapPane](by-file/MapPane.md); the complete declaration routes through UID00007Q at position `0`, while exact method definitions remain direct positions 2-4.
- Primary class doc: [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md)
- Main address docs: [UID:0001B1][0x00514920-0x00514a0d.MapRefreshDimmerMethods](by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md), [UID:0003M5][0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks](by-memory/0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks.md), and [UID:0003M6][0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor](by-memory/0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor.md)

## File Role

`MapRefreshDimmer` is a short-lived map transition/fade helper. It builds on the generic [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) overlay behavior, installs a timer during construction, and deletes itself when either packet opcode `0x22` completes refresh or timer id 0 expires.

The class belongs privately in MapPane.cpp. This page remains for stable historical searchability and source-family indexing; it must not create an independent source output.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md) | Authored children UID0004VY `0x00514920-0x0051499b`, UID0004VZ `0x005149a0-0x005149e2`, and UID0004W0 `0x005149f0-0x00514a0d`; compiler adjustors `0x00514d34-0x00514d4a` and scalar wrapper `0x00514e20-0x00514e5b` | Private MapPane.cpp timer-backed map refresh/loading dimmer; implicit destructor and compiler ABI pages remain non-emitting. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction/timer setup | `0x00514920`, inline branch in `0x00506df0` | Constructs pane state and schedules the transition timer. |
| Packet completion | `0x005149a0` | Accepts opcode `0x22`, deletes the helper, then calls `g_activeMapPane->FinishVisibleObjectRefresh()`. |
| Timer expiration | `0x005149f0` | Deletes for timer id 0 and returns true for every timer event. |
| Interface adjustors/destruction | `0x00514d34`, `0x00514d3f`, `0x00514e20` | Adjusts secondary/tertiary interface pointers, destroys base state, and conditionally frees storage. |

## Boundary Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA confirms `0x00514920`, `0x005149f0`, `0x00514d34`, `0x00514d3f`, and `0x00514e20` as exact starts.
- The constructor calls the generic `ScreenDimmer` constructor with dim level `3`, writes MapRefreshDimmer vtables at offsets `0`, `0xa0`, and `0xa4`, then starts a timer through `0x005975e0` with interval `2000`.
- `sub_506DF0`, a MapPane-side input handler, contains the visible construction branch: it allocates `0xfc` bytes, runs the `ScreenDimmer` base setup, installs the same MapRefreshDimmer vtables, starts the two-second timer, and continues map refresh work.
- The vtable block confirms `??_7MapRefreshDimmer@@6B@` at `0x0061e858`, secondary table `0x0061e8a4`, tertiary table `0x0061e8d4`, timer callback slot `0x0061e8d8 -> 0x005149f0`, and deleting destructor slot `0x0061e858 -> 0x00514e20`.
- The old `0x00514920-0x00514e5b` span is not a continuous class range: it crossed `UInt32Vector`, object-pane unwind wrappers, GameServerConfig cleanup, and MapPane destructor glue. The class now uses exact method/destructor pages instead of a single sparse executable range.
- Emit this helper only through [UID:0000L3][MapPane](by-file/MapPane.md) map-change and transition code; keep generic dimmer base/companion logic under [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).
- Zero standalone-constructor callers plus exact inline construction at `0x00506df0` and exact UID0004QA completion inlining resolve the old standalone/private uncertainty to private MapPane.cpp source.
- [UID:0001B1][0x00514920-0x00514a0d.MapRefreshDimmerMethods](by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md), UID0003M5, UID0003M6, physical UID0002SR, and semantic [UID:0004W1][MapRefreshDimmerVtables](by-type/by-vtable/MapRefreshDimmerVtables.md) are non-emitting compiler/split evidence.
- Historical standalone `MapRefreshDimmer.cpp`, authored destructor, `OnTimerExpired`, explicit facet-base, and handwritten vtable alternatives are superseded or rejected; no separate output should exist for this page.

## Cross-References

- [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md)
- [UID:0001B1][0x00514920-0x00514a0d.MapRefreshDimmerMethods](by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md)
- [UID:0003M5][0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks](by-memory/0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks.md)
- [UID:0003M6][0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor](by-memory/0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0004W1][MapRefreshDimmerVtables](by-type/by-vtable/MapRefreshDimmerVtables.md)

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
- 2026-06-12 Agent-C001 Goal 2:
  - Score unchanged at `86/88`.
  - Replaced the stale sparse main memory range with exact method/destructor pages after live IDA MCP proved the old range crossed unrelated owners. [UID:0001B1][0x00514920-0x00514a0d.MapRefreshDimmerMethods](by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md) now covers the contiguous constructor/callback/timer island, while [UID:0003M5][0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks](by-memory/0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks.md) and [UID:0003M6][0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor](by-memory/0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor.md) cover destructor glue.
- 2026-07-22 B004 UID0002SR callback: Raised to `91/93`, resolved the source route to private UID0000L3 MapPane.cpp positions 1-4, retained this page as a historical non-emitting semantic index, linked the registered authored children and vtable authority, and preserved all binary boundaries/ABI history without creating a standalone source emitter.
