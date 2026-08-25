** TARGET-REPORT-UID:00042E **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00042E MapPaneQueueMovementRefreshTimer6 By-Memory Source Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: improve [UID:00042E] target documentation and score, but keep the target non-emitting.
- Final disposition: `MapPane`-owned, reconstructable, source-shaped raw helper with no current callable/pointer/vtable/source route.
- Required action if accepted: update only `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` unless the supervisor wants redundant support-doc sync. Current support docs already carry the necessary MapPane/timer-field/source-placement context.
- Confidence: high for raw bytes, behavior, owner, no-function state, no incoming xref, no absolute pointer route, and no generated output; medium for original source spelling and whether the raw body had an unmodeled original entry route.

## Target

- Target UID: `00042E`.
- Target path: `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md`.
- Source queue row: `auto-generated/-ag-research-tracker.md` under `## by-memory` -> `### Not-Covered Files - Reconstructable`, row score `85/85`, combined `85.0`, reconstructable `true`, reports `0`.
- Current supervisor assignment: report-only source-quality recheck for raw helper liveness, route/xref/pointer evidence, owner/emitter route, timer-id `6` semantics, field writes, config/busy-state guards, source placement, first-draft C++ readiness, and whether blank-emitter state can be improved.

## Current Target State

- Existing metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:85`
  - `CANONICAL_OWNER:00007Q`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - `EMITTER_POSITION_OPTIONAL:` blank
  - formal `RECONSTRUCTION_CPP CODE` block blank
- Existing status says this is a raw no-function MapPane timer queue helper with no emission route.
- Existing item summary says the body stores pending target tiles, schedules event `6`, returns at `0x00505cae`, and remains non-emitting due no route/xref/pointer evidence.
- Current support docs checked:
  - `by-class/MapPane.md`
  - `by-file/MapPane.md`
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md`
  - `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md`
  - `by-memory/0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer.md`
  - `by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md`
  - `by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md`
  - `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`
  - `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md`
  - `auto-generated/NexusTK/map/MapPane.cpp`

## Executive Recommendation

Update the target page to record the fresh MCP evidence and raise it to `COMPLETION:87`, `CONFIDENCE:90`. Preserve:

- `CANONICAL_OWNER:00007Q`
- `RECONSTRUCTABLE:TRUE`
- blank `EMITTER_UIDS`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++ block

The raw body is real MapPane source-shaped code, not padding, but it still lacks a proven entry route. The correct current outcome is stronger no-code/no-emitter documentation, not first-draft C++.

## Supervisor Active Recheck

- The assigned item did not require split repair: the half-open target range `0x00505c00-0x00505cb1` is already isolated, with `0x00505bf8-0x00505c00` and `0x00505cb1-0x00505cc0` confirmed as `0xcc` alignment.
- Every current score/emitter blocker named in this pass was investigated in the same pass: function modeling, xrefs, pointer bytes, vtable/callback route, sibling timer handlers, generated output, owner/source placement, and C++ readiness.
- No fallback-only evidence was used. MCP session `supervisor_resume_20260629` was live and healthy.

## Inference Research Guidance Check

- `by-structure.md` says `by-memory` is the canonical home for exact binary evidence and raw code, and it requires C++ only when the item has a confirmed emitter route and the code is ready for formal insertion.
- The target is reconstructable source-shaped code under `MapPane`, but `by-structure.md` separates `CANONICAL_OWNER` from `EMITTER_UIDS`. Known ownership alone is not enough to fill an emitter route.
- Current `by-class/MapPane.md`, `by-file/MapPane.md`, and the aggregate page already document that raw no-route children remain blank until a route or retained-helper emission policy is proven.
- Wave2/Wave3 material was not used as authority. Generated `auto-generated/NexusTK/map/MapPane.cpp` was used only as a current output lead and negative check.

## Heuristic / Inference Reanalysis And Validation

- Raw helper liveness: MCP `insn_query` over `0x00505c00-0x00505cb1` returns 50 decoded instructions with a normal prologue, MapPane field reads/writes, global/config guards, `Sleep(100)`, timer scheduling, a post-queue helper call, and `retn 8`. This is not padding or random data.
- Function modeling: MCP `lookup_funcs` reports `0x00505c00`, `0x00505cae`, and `0x00505cb1` as `Not a function`, while the successor `0x00505cc0` is modeled as `sub_505CC0` size `0x39`. The target should stay documented as raw no-function code.
- Route/xref evidence: MCP `xrefs_to 0x00505c00` returns zero incoming references. Exact absolute pointer bytes `00 5C 50 00` and `push 0x00505c00` bytes `68 00 5C 50 00` have zero `find_bytes` hits. Generated `MapPane.cpp` has no `00042E`, `0x00505c00`, or target-name marker. This exhausts the practical current route checks without using broad callgraphs or unbounded searches.
- Timer semantics: the target schedules timer id `6` through `sub_5975E0` with delay `0x2c` / 44 ms and two zero trailing arguments, using the timer facet at `MapPane+0xa4`. The modeled `MapPane::OnTimerEvent` child handles id `6` as the queued movement/path timer and reschedules id `6` at 44 ms while state continues.
- Field semantics: the raw helper writes call arguments into `MapPane+0x8ec/+0x8f0`, conditionally converts them through `word_66DAA0` and `word_66DA9C`, then overwrites the pair with origin-adjusted tile coordinates using `MapPane+0x400` and `MapPane+0x3fc`. Current class docs correctly keep this action-state block descriptive rather than final header-quality.
- Guard semantics: the conversion block requires `byte_66DA97 == 1` and `*(g_pConfig + 0x28de5b) != 0`. The queueing block runs after `Sleep(100)` and requires `MapPane+0x39d == 0` and `unk_69B4CC == 0`; if clear, it sets `+0x39d = 1`, schedules timer id `6`, and calls `0x005449d0`.
- Helper distinction: MCP decompilation shows `0x005449d0` calls `sub_4A6F40(unk_67AB30, this ? this+0xa0 : 0)`, while clear paths call `0x005449f0`, which calls `sub_4A6F40(unk_67AB30, 0)`. The target page should not overstate `0x005449d0` as the same helper used by the modeled clear/notify drain paths.
- Rejected upgrade: first-draft C++ would be mechanically possible from bytes, but it would be unsafe as formal reconstruction because no source-level declaration, vtable slot, function start, direct call, data pointer, generated-output route, or covering live dispatcher branch currently reaches `0x00505c00`.

## Evidence Standards Used

- Direct MCP facts: health/session state, `lookup_funcs`, `xrefs_to`, `get_bytes`, `insn_query`, `find_bytes`, focused `decompile`, `get_global_value`.
- Documentation evidence: current target, direct class/file parent docs, aggregate page, paired timer queue/clear children, notify/timer virtual children, MapPane vtable data, and generated `MapPane.cpp`.
- Inference: source-facing role names such as queued movement/map-state timer state and pending target tile coordinates are descriptive, validated by field use and sibling docs, not original symbol proof.

## Evidence Checked

### IDA MCP evidence

- MCP request `5`: `idb_list` returned one active session, `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `14860`.
- MCP request `6`: `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- MCP request `11`: `lookup_funcs` for `0x00505bf8`, `0x00505c00`, `0x00505cae`, `0x00505cb1`, `0x00505cc0`, `0x00505d00`, `0x00505da0`, `0x00508f60`, and `0x00509030`.
- MCP request `12`: `xrefs_to` for `0x00505c00`, `0x00505cae`, `0x00505cb1`, `0x00505cc0`, `0x00505d00`, and `0x00505da0`.
- MCP request `13`: `get_bytes` for `0x00505bf8-0x00505c00`, `0x00505c00-0x00505cb1`, and `0x00505cb1-0x00505cc0`.
- MCP request `14`: `insn_query` scoped to `0x00505c00-0x00505cb1`, count `120`, max scan `180`, with disassembly.
- MCP request `15`: exact `find_bytes` for `00 5C 50 00`, `68 00 5C 50 00`, and a capped control pattern, limit `20`.
- MCP requests `16` and `17`: focused decompile for `0x00509030` and `0x00508f60`.
- MCP request `18`: `xrefs_to` for vtable slot targets `0x00509030` and `0x00508f60`.
- MCP requests `19` and `20`: focused decompile for paired clearers `0x00505cc0` and `0x00505de0`.
- MCP requests `21` and `22`: exact lookup/value checks for timer helpers, refresh helpers, and relevant globals.
- MCP requests `23` through `25`: focused decompile/xref checks for `0x005449d0` and `0x005449f0`.

### Documentation and generated-output evidence

- Current target page `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md`.
- Direct support docs listed in `Current Target State`.
- Tracker row in `auto-generated/-ag-research-tracker.md`.
- Generated file `auto-generated/NexusTK/map/MapPane.cpp`: `rg` found no `00042E`, `00505c00`, or `MapPaneQueueMovementRefreshTimer6` marker, while UID00042F/UID00042I and the timer virtual child are generated.
- Existing report search terms: `00042E`, `0x00505c00`, `0x00505cb1`, `MapPaneQueueMovementRefreshTimer6`, `Timer6`, `MapPane`, `0x00505cae`.
- Relevant exact old report lead: `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`.
- Stale UID-collision reports: B003/B006 FittingRoom reports mention historical UID00042E for a different `0x00421a30` target; those are not evidence for this MapPane target.

### Negative checks

- No IDA modeled function at the target start or return/end addresses.
- No incoming xref to `0x00505c00`.
- No absolute pointer bytes for `0x00505c00`.
- No `push 0x00505c00` bytes.
- No generated `MapPane.cpp` output marker for UID00042E.
- No vtable slot route to `0x00505c00`; vtable slots route only to the modeled notify/timer children `0x00508f60` and `0x00509030`.
- No safe source declaration or live dispatcher route found in current support docs.

## Positive Evidence Summary

- The target body is exact, bounded, and source-shaped:
  - `0x00505bf8-0x00505c00`: eight bytes `0xcc`.
  - `0x00505c00-0x00505cb1`: 177 bytes of decoded raw helper instructions.
  - `0x00505cae`: final `retn 8`.
  - `0x00505cb1-0x00505cc0`: fifteen bytes `0xcc`.
- The helper uses `MapPane` instance state:
  - `ECX` is saved in `EDI`.
  - writes `+0x8ec/+0x8f0`;
  - reads `+0x3fc/+0x400`;
  - tests and sets `+0x39d`;
  - calls scheduler through `this+0xa4`.
- Timer id `6` has live sibling context:
  - `MapPaneMovementTimerHandler` handles id `6`;
  - `MapPaneClearQueuedMovementRefresh` clears the same `+0x39d` byte and cancels ids `6` and `8`;
  - `MapPaneNotifyMessageCore` drains the same queued state under the global mode gate.

## IDA MCP Facts

### Function and range facts

| Address | MCP fact |
| --- | --- |
| `0x00505bf8` | `lookup_funcs`: not a function; bytes are `cc cc cc cc cc cc cc cc`. |
| `0x00505c00` | `lookup_funcs`: not a function; `insn_query` starts `push ebp; mov ebp, esp; cmp byte_66DA97, 1`. |
| `0x00505cae` | `lookup_funcs`: not a function; `insn_query` final instruction is `retn 8`. |
| `0x00505cb1` | `lookup_funcs`: not a function; successor padding starts here. |
| `0x00505cc0` | `lookup_funcs`: `sub_505CC0`, size `0x39`; paired modeled clearer. |
| `0x00508f60` | `lookup_funcs`: `sub_508F60`, size `0xcb`; data xref from vtable slot `0x0061e77c`. |
| `0x00509030` | `lookup_funcs`: `sub_509030`, size `0x409`; data xref from vtable slot `0x0061e79c`. |

### Raw instruction facts for UID00042E

| Address | Instruction / meaning |
| --- | --- |
| `0x00505c03` | `cmp byte_66DA97, 1`; global mode/config gate for conversion block. |
| `0x00505c14` | `cmp byte ptr [eax+28DE5Bh], 0`; uses `dword_67A7C8` config pointer. |
| `0x00505c20` / `0x00505c29` | stores the two arguments to `MapPane+0x8ec/+0x8f0`. |
| `0x00505c2f` / `0x00505c3f` | uses `word_66DAA0` and `word_66DA9C` tile dimensions. |
| `0x00505c52` / `0x00505c61` | uses `MapPane+0x3fc/+0x400` tile origins. |
| `0x00505c71` | `push 64h`; `Sleep(100)`. |
| `0x00505c79` | tests queued flag `MapPane+0x39d`. |
| `0x00505c82` | tests `unk_69B4CC`; same busy/modal input-blocker singleton used by timer paths. |
| `0x00505c91` | pushes timer id `6`. |
| `0x00505c93` | `lea ecx, [edi+0A4h]`; timer-handler facet. |
| `0x00505c99` | sets `MapPane+0x39d` to `1`. |
| `0x00505ca0` | calls `sub_5975E0` scheduler. |
| `0x00505ca7` | calls `sub_5449D0` with `ECX = MapPane*`. |

### Data/global facts

- `get_global_value 0x0066da97` returned `0x1`.
- `get_global_value 0x0066da9c` returned `0x30`.
- `get_global_value 0x0066daa0` returned `0x30`.
- `get_global_value 0x0069b4cc` returned `0x0`.
- `lookup_funcs 0x005975e0`: `sub_5975E0`, size `0x1f`, scheduler wrapper.
- `lookup_funcs 0x00597610`: `sub_597610`, size `0x16`, cancel wrapper.
- `lookup_funcs 0x005449d0`: `sub_5449D0`, size `0x19`.
- `lookup_funcs 0x005449f0`: `sub_5449F0`, size `0xe`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00505c00-0x00505cb1` | [UID:00042E] `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` | Raw no-function queue helper for timer id `6` | TRUE | [UID:00007Q] MapPane | current `85/85`; recommend `87/90` | Keep non-emitting. |
| `0x00505cc0-0x00505cf9` | [UID:00042F] `MapPaneClearQueuedMovementRefresh` | Modeled clearer for `+0x39d`, cancels ids `6/8` | TRUE | [UID:00007Q] MapPane | `87/89` | Emits formal C++. |
| `0x00505d00-0x00505d9a` | [UID:00042G] `MapPaneQueueMovementRefreshTimer8` | Raw no-function queue helper for timer id `8` | TRUE | [UID:00007Q] MapPane | `85/85` | Non-emitting sibling. |
| `0x00505da0-0x00505dd2` | [UID:00042H] `MapPaneQueueActionPollTimer` | Raw no-function queue helper for timer id `7` | TRUE | [UID:00007Q] MapPane | `85/85` | Non-emitting sibling. |
| `0x00505de0-0x00505dfe` | [UID:00042I] `MapPaneClearPendingActionPoll` | Modeled clearer for `+0x39e`, cancels id `7` | TRUE | [UID:00007Q] MapPane | `87/89` | Emits formal C++. |
| `0x00509030-0x00509439` | [UID:0003ZS] `MapPaneMovementTimerHandler` | Live timer virtual method handling ids `5/6/7/8` | TRUE | [UID:00007Q] MapPane | `88/89` | Emits formal C++. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00505c00` | `xrefs_to`: none | No current entry/call/data route to UID00042E. |
| `0x00505cae` | one code xref from `0x00505cad` | Internal fall-through/reference around the final `pop ebp; retn 8`, not an external route. |
| `0x00505cc0` | 19 xrefs including `0x00509030` and packet/input paths | Paired modeled clearer is live and routed; this does not prove UID00042E entry. |
| `0x00509030` | data xref from `0x0061e79c` | Tertiary vtable route for timer callback. |
| `0x00508f60` | data xref from `0x0061e77c` | Secondary vtable route for notify callback. |
| `0x005449d0` | xrefs include `0x00505ca7` and `0x00505d8f` | Raw queue helpers call the nonzero-context scheduling/refresh wrapper. |
| `0x005449f0` | xrefs include `0x00505cf2` and `0x00508fc8` | Clear/notify paths call the zero-context drain wrapper. |

## Documentation Evidence And IDA Status

- `by-class/MapPane.md` already documents `+0x39d` as `m_queuedMapStateRefresh` / `m_movementTimerQueued`, links UID00042E and UID00042G as raw queue setters, and links UID00042F as the modeled clearer.
- `by-class/MapPane.md` already documents `+0x8ec/+0x8f0` as descriptive pending target/saved tile coordinates and correctly says not to promote the adjacent action-state structure to final header fields yet.
- `by-file/MapPane.md` already records UID00042E as one of the raw no-route children under the B009 `0001AP` split and states the current no-function/xref/pointer proof.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` already records UID00042E in the child table and adjacent `0xcc` padding ledger.
- Generated `MapPane.cpp` emits UID00042F and UID00042I clearers and UID0003ZS timer handling, but no UID00042E marker or body.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane

- Evidence for:
  - Raw `ECX` is used as a `MapPane*`.
  - Direct field writes/readbacks are MapPane offsets `+0x39d`, `+0x3fc`, `+0x400`, `+0x8ec`, and `+0x8f0`.
  - Scheduler receiver is `MapPane+0xa4`, matching the documented TimerHandler facet used by `MapPane::OnTimerEvent`.
  - Sibling modeled timer and clearer pages are MapPane-owned and use the same state.
- Evidence against:
  - No callable route to this specific raw helper is currently proven.
- Decision: keep `CANONICAL_OWNER:00007Q`.

### 2. [UID:0000L3] MapPane file root

- Evidence for:
  - The source module route for MapPane children is `NexusTK/map/MapPane.cpp`.
  - The raw helper belongs to the coordinate/object/timer interior of the MapPane aggregate.
- Evidence against:
  - `by-structure.md` says a class-owned method/helper should use the class as canonical owner when supported.
- Decision: source placement stays through the MapPane class to `by-file/MapPane.md`, but `CANONICAL_OWNER` should not be changed to the file UID.

### 3. TimerHandler / TimerMgr

- Evidence for:
  - The helper schedules timer id `6` through `sub_5975E0` and uses a timer-handler facet pointer.
- Evidence against:
  - The body reads/writes MapPane fields and uses MapPane-specific tile/action state.
  - TimerHandler owns generic scheduling wrappers only.
- Decision: dependency/callee only, not owner or emitter.

### 4. Input blocker / config / session global owners

- Evidence for:
  - The body reads `byte_66DA97`, `dword_67A7C8+0x28de5b`, and `unk_69B4CC`.
- Evidence against:
  - These are guards consumed by the helper; they do not own the helper body.
- Decision: dependency/guard context only.

## Source Placement

- Recommended source placement: `MapPane` class helper inside the `NexusTK/map/MapPane.cpp` source family, documented through [UID:00007Q] and [UID:0000L3].
- Emission placement: none at present. Keep `EMITTER_UIDS` blank.
- Forced source-facing name if a future route is proven: a private descriptive helper such as `MapPane::QueueMovementRefreshTimer6` or `MapPane::QueueMovementPathTimer` would be plausible, but this report does not recommend inserting that name into formal C++ because no entry route is proven.
- Rejected placements: TimerHandler/TimerMgr, Config, InputBlockerPane, standalone `MapPaneTimerQueue.cpp`, and no-owner. They either own dependencies rather than this body or are weaker than the direct MapPane field evidence.

## Range / Split / Padding / Reclassification Analysis

- No new split is recommended.
- Exact target range `0x00505c00-0x00505cb1` should remain half-open.
- `0x00505bf8-0x00505c00` is eight bytes of `0xcc` alignment.
- `0x00505cb1-0x00505cc0` is fifteen bytes of `0xcc` alignment.
- The target body includes the final `retn 8` at `0x00505cae`.
- The successor function starts at `0x00505cc0` and should remain separate.
- Do not reclassify the raw helper body as ignored padding. It is reconstructable source-shaped MapPane code.

## Negative Evidence Summary

- No current IDA function start means no reliable function-level decompilation, prototype, stack frame, or IDA call inventory for `0x00505c00`.
- No incoming xref to the raw start means current IDA does not prove ordinary call reachability.
- No absolute pointer bytes or `push` immediate bytes means no obvious table, callback, or manually stored pointer route was found.
- The paired clearers and timer virtual methods prove the state machine, but not the raw helper's entry route.
- Generated output absence proves current documentation does not route this body into `MapPane.cpp`.
- The original helper name and exact source declaration remain unproven. Source-shaped behavior alone is insufficient for formal C++ under the active emitter/source-quality gate.

## IDA Rename / Type / Comment Recommendations

- No IDA DB changes are requested.
- Source-facing field names should remain descriptive:
  - `MapPane+0x39d`: `m_queuedMapStateRefresh` / `m_movementTimerQueued`.
  - `MapPane+0x8ec/+0x8f0`: pending target/action tile coordinate pair, not final header-quality names.
  - `MapPane+0xa4`: timer-handler facet.
- Target prose should distinguish `0x005449d0` from `0x005449f0`.

## First-Draft C++ Recommendation

- Eligible for draft C++: no.
- Recommended code: leave the formal `RECONSTRUCTION_CPP CODE` block empty and keep `EMITTER_UIDS` blank.
- Exact no-code proof:
  - MCP `lookup_funcs` says `0x00505c00` is not a function.
  - MCP `xrefs_to 0x00505c00` returns no incoming references.
  - Exact absolute pointer bytes for `0x00505c00` have zero hits.
  - Exact `push 0x00505c00` bytes have zero hits.
  - Vtable data routes the live notify/timer callbacks to `0x00508f60` and `0x00509030`, not to `0x00505c00`.
  - Current generated `MapPane.cpp` has no UID00042E marker.
  - Sibling clear/timer pages cover the live state-machine behavior with emitted C++, but they do not cover this raw entry body.
  - Therefore inserting a `MapPane::QueueMovementRefreshTimer6` formal C++ method now would introduce an unproven source declaration and route.
- Reason this preserves behavior: leaving it non-emitting avoids fabricating a callable source item while documenting the binary body for future route recovery.
- Reason not higher: lack of route/source declaration prevents final source shape and emitter assignment.

## Final Recommendation

- Update target score from `85/85` to `87/90`.
- Preserve `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Expand the target page with:
  - live MCP evidence request list;
  - exact bytes/padding boundaries;
  - exact instruction-level behavior;
  - guard semantics;
  - timer id `6` scheduling and state relationship;
  - `0x005449d0` versus `0x005449f0` distinction;
  - no-route/no-code proof;
  - rejected C++/emitter alternatives.
- No support doc score/metadata changes are required. Current support docs are already sufficient at same-or-greater detail for owner/source placement.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md`.
- Metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - keep `CANONICAL_OWNER:00007Q`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:` blank
  - keep formal C++ block blank
- Item Summary replacement direction:
  - Describe the body as a raw no-function MapPane queue helper for TimerHandler event id `6`.
  - Include the optional `byte_66DA97` plus `g_pConfig+0x28de5b` conversion gate, writes/conversion for `+0x8ec/+0x8f0`, `Sleep(100)`, `+0x39d` and `unk_69B4CC` queue gates, scheduling id `6` at 44 ms through `MapPane+0xa4`, setting `+0x39d`, and calling `0x005449d0`.
  - Preserve non-emitting/no-route status.
- Add sections or bullets for:
  - `Live MCP Recheck`
  - `Behavior`
  - `Field And Guard Notes`
  - `No-Code / No-Emitter Proof`
  - `Score Rationale`
  - `Rejected Alternatives`

## Recommended Support Doc Changes

- `by-class/MapPane.md`: no required edit. Already documents `+0x39d`, `+0x8ec/+0x8f0`, UID00042E, UID00042F, UID00042G, UID00042H, UID00042I, the timer-handler child, and the no-route policy at sufficient detail. If a supervisor wants a support sync, add only the `0x005449d0` versus `0x005449f0` distinction to avoid over-naming both as one refresh helper.
- `by-file/MapPane.md`: no required edit. Already documents the B009 raw no-route children, UID00042E, the `MapPane.cpp` source family, and child-only exact C++ policy.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: no required edit. Already lists UID00042E as raw no-route child and records padding classification. Optional support sync could add the `0x005449d0`/`0x005449f0` distinction.
- `auto-generated/NexusTK/map/MapPane.cpp`: do not edit. It is generated and currently should remain without UID00042E output.

## Score And Metadata Recommendation

- Current score/metadata: `85/85`, owner `00007Q`, reconstructable true, blank emitters, blank C++.
- Recommended score/metadata: `87/90`, owner `00007Q`, reconstructable true, blank emitters, blank C++.
- Completion rationale:
  - Raise above `85` because this pass adds fresh MCP health/session evidence, exact byte/range proof, instruction-level behavior, route-negative checks, generated-output absence, and no-code rationale.
  - Keep below `90` because source route, original symbol name, exact source declaration, and final field names for the action-state block remain unresolved.
- Confidence rationale:
  - Raise to `90` because the binary facts and negative route checks are direct and current.
  - Keep below final-audit levels because no route means the original source status is still not fully reconstructable as emitted C++.
- Metadata fields:
  - `CANONICAL_OWNER`: unchanged `00007Q`.
  - `RECONSTRUCTABLE`: unchanged `TRUE`.
  - `EMITTER_UIDS`: unchanged blank.
  - `EMITTER_POSITION_OPTIONAL`: unchanged blank.

## Open Questions With Attempted Resolution

- Open question: Is there a current callable route to `0x00505c00`?
  - Evidence checked: `lookup_funcs`, `xrefs_to`, exact absolute pointer bytes, exact push-immediate bytes, generated output, vtable/support docs.
  - Best supported resolution: no current route is proven.
  - Impact: blocks formal C++ and emitter assignment.
- Open question: Are `+0x8ec/+0x8f0` final class fields?
  - Evidence checked: UID00042E raw writes/conversion plus UID0003ZS event-8 usage and current class layout notes.
  - Best supported resolution: they are pending target/action tile-coordinate fields, but final source names and structure grouping remain broader action-state work.
  - Impact: does not block owner/no-code disposition; helps cap score.
- Open question: Is `0x005449d0` the same refresh helper as the clear paths?
  - Evidence checked: decompiled `0x005449d0` and `0x005449f0`.
  - Best supported resolution: related wrappers over `sub_4A6F40`, but not identical. UID00042E uses nonzero context `this+0xa0`; clear/notify uses zero context.
  - Impact: target prose should distinguish them.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | MCP was live and current for this pass. | High | MCP `idb_list` request `5`, `server_health` request `6`. | Target `Live MCP Recheck` | incorporate | applied - target `Live MCP Recheck` names session `supervisor_resume_20260629`, request `5` active IDB, and request `6` health OK. |
| C002 | UID00042E remains not modeled as an IDA function, while successor `0x00505cc0` is modeled. | High | MCP `lookup_funcs` request `11`. | Target `Status` / `Live MCP Recheck` | incorporate | applied - target `Live MCP Recheck` records `0x00505c00`, return, and end as not functions, and `0x00505cc0` as `sub_505CC0` size `0x39`. |
| C003 | Target body is real source-shaped raw code, not padding. | High | MCP `insn_query` request `14`; `get_bytes` request `13`. | Target `Behavior` / `Range` | incorporate | applied - target `Status`, `Range And Boundary Evidence`, and `Behavior` document 50 instructions, stack frame, field access, helper calls, and `retn 8`. |
| C004 | Adjacent spans `0x00505bf8-0x00505c00` and `0x00505cb1-0x00505cc0` are `0xcc` alignment. | High | MCP `get_bytes` request `13`; aggregate doc already present. | Target `Range` | incorporate | applied - target `Range And Boundary Evidence` lists both `0xcc` alignment spans and the half-open raw body. |
| C005 | No entry route is currently proven for `0x00505c00`. | High | MCP `xrefs_to` request `12`; `find_bytes` request `15`; generated `rg` negative. | Target `No-Code / No-Emitter Proof` | incorporate | applied - target `No-Code / No-Emitter Proof` records no xrefs, no pointer bytes, no push-immediate bytes, no vtable route, no generated marker, and no source declaration. |
| C006 | The helper conditionally converts arguments through `byte_66DA97`, `g_pConfig+0x28de5b`, tile dimensions, and MapPane origins before overwriting `+0x8ec/+0x8f0`. | High | MCP `insn_query` request `14`; class field notes. | Target `Behavior` / `Field And Guard Notes` | incorporate | applied - target `Behavior` documents the config guard, argument stores, tile dimensions `word_66DAA0`/`word_66DA9C`, and origin fields `+0x400/+0x3fc`. |
| C007 | The helper sleeps 100 ms, gates on `+0x39d` and `unk_69B4CC`, schedules timer id `6` at 44 ms via `MapPane+0xa4`, sets `+0x39d`, and calls `0x005449d0`. | High | MCP `insn_query` request `14`; timer helper lookup request `21`. | Target `Behavior` | incorporate | applied - target `Behavior` records `Sleep(100)`, the queue gate, scheduler `0x005975e0`, timer id `6`, delay `0x2c`, `MapPane+0xa4`, `+0x39d = 1`, and `0x005449d0`. |
| C008 | `0x005449d0` and `0x005449f0` are related but distinct wrappers and should not be collapsed in prose. | High | MCP decompile requests `23` and `24`; xrefs request `25`. | Target `Behavior` / optional support note | incorporate | applied - target `Live MCP Recheck`, `Behavior`, and `Rejected Alternatives` distinguish nonzero-context `0x005449d0` from zero-context `0x005449f0`; no support edit needed. |
| C009 | Direct owner remains [UID:00007Q] MapPane. | High | MapPane fields/facet in MCP `insn_query`; current class/file docs. | Target metadata/status | already-present | already-present - target metadata already had `CANONICAL_OWNER:00007Q`; target `Status` and `Owner And Source Placement` now restate MapPane ownership with field/facet proof. |
| C010 | `EMITTER_UIDS` and formal C++ should remain blank. | High | No route evidence plus `by-structure.md` code-entry/emitter gate. | Target metadata / C++ block | incorporate | applied - target metadata keeps blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`; target `No-Code / No-Emitter Proof` explains why. |
| C011 | Recommended target score is `87/90`. | Medium-high | Fresh evidence closes documentation gaps but not source route/name. | Target metadata / score rationale | incorporate | applied - target metadata changed from `COMPLETION:85`, `CONFIDENCE:85` to `COMPLETION:87`, `CONFIDENCE:90`; validator command `000000004118` reported completion/confidence updates and final command `000000004120` remained stable. |
| C012 | `by-class/MapPane.md`, `by-file/MapPane.md`, and the aggregate page already carry support owner/source-placement facts at sufficient detail. | High | Support-doc reads and `Select-String` checks. | Support docs | already-present | already-present - no support docs edited; target `Owner And Source Placement` records support sufficiency and the callback scope was target-only unless contradiction appeared. |
| C013 | Older B003/B006 UID00042E FittingRoom reports are stale UID-collision leads only. | High | Exact search terms show different `0x00421a30` target; current goal warning. | Target `Historical/Stale Leads` or report only | reject-stale | applied - target `Rejected Alternatives And Stale Leads` records that older B003/B006 UID00042E FittingRoom reports are stale `0x00421a30` collision leads and not evidence for this MapPane page. |

## Validator Results

- Target validator command:
  - Command: `python .\tools\validator.py --mode file --file by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md --apply --queue-timeout 240 --wait-generated`
  - First run command_id: `000000004118`
  - First run command_timestamp: `2026-07-01T18:03:29-04:00`
  - First run local UTC wrapper timestamp: `2026-07-01T22:03:29.5518029Z`
  - First run exit code: `0`
  - First run ok count: `ok: 1`
  - First run generated-refresh state: `generated_refresh: completed`, `generated_refresh_command_id: 000000004118`, `generated_refresh_timestamp: 2026-07-01T18:03:29-04:00`
  - First run note: validator correctly normalized three mistaken sibling UID labels (`000430-000432`) to registry targets; B010 corrected those labels to `00042G`, `00042H`, and `00042I` and reran the scoped validator.
- Final target validator command:
  - Command: `python .\tools\validator.py --mode file --file by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md --apply --queue-timeout 240 --wait-generated`
  - Final command_id: `000000004120`
  - Final command_timestamp: `2026-07-01T18:04:12-04:00`
  - Final local UTC wrapper timestamp: `2026-07-01T22:04:11.8225774Z`
  - Final exit code: `0`
  - Final ok count: `ok: 1`
  - Final warnings/non-blocking notes: validator reported registry reference cleanup for the corrected sibling UIDs, plus existing broad generated refresh notices such as `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code`; none block the target.
  - Final generated-refresh state: `generated_refresh: completed`, `generated_refresh_command_id: 000000004120`, `generated_refresh_timestamp: 2026-07-01T18:04:12-04:00`.
- Generated output freshness:
  - `auto-generated/NexusTK/map/MapPane.cpp` header after validation: `validator-command-id: 000000004120`, `validator-refreshed-at: 2026-07-01T18:04:12-04:00`, `validator-refresh-source: foreground-generated-refresh`.
  - File timestamp: `LastWriteTimeUtc: 2026-07-01T22:04:18Z`, size `40174`.
  - `Select-String` for `00042E`, `0x00505c00`, and `MapPaneQueueMovementRefreshTimer6` returned no matches, confirming UID00042E remains absent from generated C++ as expected for the no-emitter disposition.
- Lease proof:
  - Acquired: `python .\tools\leaser\leaser.py B010 lease by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` returned `Success`.
  - Released: `python .\tools\leaser\leaser.py B010 unlease by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` returned `Success`.
  - Serial read of `tools/leaser/Agents/current_leases.md` after release showed no `B010` rows; other agents' rows remained.

## Changed Files

- Modified by B010:
  - `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md`
  - `tools/leaser/Agents/Agent-B010/research/00042E-MapPaneQueueMovementRefreshTimer6-by-memory-source-quality.md`
- Validator-owned generated refresh observed but not manually edited:
  - `auto-generated/NexusTK/map/MapPane.cpp` refreshed by validator command `000000004120` and remains without UID00042E output.
  - The validator also reported generated metadata/report refreshes and backup creation as normal validator-owned side effects.
- Support docs not edited: `by-class/MapPane.md`, `by-file/MapPane.md`, and `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`.
- Score/metadata before: `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Score/metadata after: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.

## Implementation Tracking Checklist

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the UID00042E report and updated `goal.md` with implementation callback `B010-implement-00042E-MapPaneQueueMovementRefreshTimer6-by-memory-20260701`.
- [x] Update target `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` metadata to `COMPLETION:87`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++. Proof: target metadata now shows exactly those values; validator command `000000004118` reported `completion_update 00042E ... 87` and `confidence_update 00042E ... 90`; final validator `000000004120` remained stable.
- [x] Update target status/range behavior with fresh MCP request ids `5`, `6`, and `11` through `25`, including exact no-function, bytes, scoped instruction scan, and no-route evidence. Proof: target sections `Live MCP Recheck` and `Range And Boundary Evidence`.
- [x] Update target behavior to include the optional conversion guard (`byte_66DA97 == 1` and `g_pConfig+0x28de5b != 0`), argument stores to `+0x8ec/+0x8f0`, tile-dimension/origin conversion, `Sleep(100)`, `+0x39d`/`unk_69B4CC` gate, timer id `6` scheduling at `44` ms through `MapPane+0xa4`, `+0x39d` set, and `0x005449d0` call. Proof: target `Behavior`.
- [x] Update target no-code/no-emitter proof: no modeled function, no incoming xref to `0x00505c00`, no absolute pointer bytes, no `push 0x00505c00` bytes, no vtable route, no generated `MapPane.cpp` marker, and no safe source declaration. Proof: target `No-Code / No-Emitter Proof`; generated check below confirms no emitted marker/body.
- [x] Preserve rejected alternatives in the target: do not assign TimerHandler/TimerMgr, Config, InputBlocker, standalone helper file, or no-owner over MapPane; do not fabricate formal C++ from raw bytes alone. Proof: target `Owner And Source Placement` and `Rejected Alternatives And Stale Leads`.
- [x] Confirm support docs are already present and do not require edits: `by-class/MapPane.md`, `by-file/MapPane.md`, and `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`. Proof: target `Owner And Source Placement` records support-doc sufficiency; no support docs were edited, so support validators were not applicable.
- [x] Update this report's Claim And Incorporation Ledger during callback with verification states `applied`, `already-present`, `excluded-with-reason`, or `blocked` plus proof. Proof: ledger above uses `applied` or `already-present` state/proof for all accepted items.
- [x] Run target validator after any accepted target edit: `python .\tools\validator.py --mode file --file by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md --apply --queue-timeout 240 --wait-generated`. Proof: final command `000000004120`, timestamp `2026-07-01T18:04:12-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] If support docs are edited, run the exact touched support validators, at minimum as applicable: `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240 --wait-generated`, `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240 --wait-generated`, and `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240 --wait-generated`. Proof: support docs were not edited, so these validator commands were not applicable.
- [x] After validation, verify `auto-generated/NexusTK/map/MapPane.cpp` stays fresh and still has no UID00042E emitted marker/body; expected output remains UID00042F/UID00042I/UID0003ZS support only. Proof: generated header shows `validator-command-id: 000000004120`, `validator-refreshed-at: 2026-07-01T18:04:12-04:00`; `Select-String` for `00042E`, `0x00505c00`, and `MapPaneQueueMovementRefreshTimer6` returned no matches.
- [x] Record validator `command_id`, `command_timestamp`, exit code, ok count, warnings, and generated-refresh state in this report during callback. Proof: see `Validator Results`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00042E-MapPaneQueueMovementRefreshTimer6-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00042E-MapPaneQueueMovementRefreshTimer6-by-memory-source-quality.md","timestamp":"2026-07-01T18:09:03","uid":"00042E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
