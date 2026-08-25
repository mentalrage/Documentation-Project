** TARGET-REPORT-UID:0001O2 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002-goal2-swallowlayerpane-core-source-quality-0001O2-20260617

Primary target: [UID:0001O2] `by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md`

Report-only scope honored. I did not edit `by-*` docs, generated reports, generated/source files, the IDA database, or `by-memory/-coverage-report.md`.

## Recommendation Summary

Raise [UID:0001O2] from `82/88` to `88/90`, keep `CANONICAL_OWNER:0000E9`, keep `RECONSTRUCTABLE:TRUE`, and keep `EMITTER_UIDS:0000E9`. The owner/emitter remains [UID:0000E9] `SwallowLayerPane`; current output routes through `auto-generated/NexusTK/map/WeatherLayerPane.cpp` because the class still surfaces through the conservative weather-layer file family.

Correct the documented range to the current half-open convention: `0x005c2230-0x005c299f`. The current file name/title ending at `0x005c299e` is off by one under `tools/memory_ranges.py` rules. Live IDA reports `sub_5C2930` size `0x6f`, so the modeled helper is `0x005c2930-0x005c299f`; its final `ret` byte is at `0x005c299e`. The next byte `0x005c299f` is alignment before a separate raw helper at `0x005c29a0`.

Do not populate [UID:0001O2]'s formal `RECONSTRUCTION_CPP CODE` block. The target is an aggregate over several source methods plus overlapping raw helper evidence, not a single source method body. The accepted source-quality action should update metadata/range/support documentation and leave first-draft C++ to exact child methods.

## Evidence Reviewed

- Target docs: [UID:0001O2] `SwallowLayerPaneCore`, [UID:0001O3] `SwallowLayerPaneRawFlightHelpers`, [UID:0001O1] `SnowingAndSwallowLayerPanes`, and [UID:0001O0] `SnowingLayerPaneMethodIndex`.
- Class/file docs: [UID:0000E9] `SwallowLayerPane`, [UID:0000OD] `SwallowLayerPane` file, [UID:0000P8] `WeatherLayerPane`, [UID:0000G1] `WeatherLayerPane`, `MapPane`, and `BackPane`.
- Data/support docs: [UID:0002ZA] `SwallowLayerPaneVtableData`, [UID:0002ZB] `SwallowLayerResourceStrings`, [UID:000161] `BackPaneGetBounds`, and timer scheduler docs around `0x005975e0`.
- Generated/source-tree context: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `simroot_v2/class_SwallowLayerPane.cpp`, and `simroot_v2/class_BackPane.cpp`.
- Prior executed lead: `Agent-B001/research/executed/older/0001O1-snowing-swallow-source-placement.md`. I treated it as a lead and rechecked current target-specific IDA/PE facts.
- Live IDA MCP endpoint: `http://127.0.0.1:13337/mcp`, session `b003_00018a_ime_comp_20260617`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.

## Boundary And Range Findings

Live `lookup_funcs` confirms these modeled Swallow functions:

| Range, half-open | Source-facing role |
| --- | --- |
| `0x005c2230-0x005c2340` | `SwallowLayerPane::SwallowLayerPane()` |
| `0x005c2340-0x005c235f` | `SwallowLayerPane::~SwallowLayerPane()` ordinary non-deleting destructor body |
| `0x005c2360-0x005c2423` | `SwallowLayerPane::OnPaint()` |
| `0x005c2430-0x005c24fa` | `SwallowLayerPane::MoveBy(int dx, int dy)` |
| `0x005c2500-0x005c26a6` | timer callback, best source name `SwallowLayerPane::OnTimerEvent(int timerId, int, int)` |
| `0x005c26b0-0x005c275c` | `SwallowLayerPane::DrawSwallow(GrafPort *target)` or equivalent render-target type |
| `0x005c2930-0x005c299f` | `SwallowLayerPane::InvalidateSwallowRect()` / current-rect invalidation helper |

Raw or thunk spans:

| Range, half-open | Finding |
| --- | --- |
| `0x005c2760-0x005c2835` | raw function-shaped start-flight helper; no IDA function object, no xrefs to start |
| `0x005c2835-0x005c2840` | alignment |
| `0x005c2840-0x005c292e` | raw function-shaped step-flight helper; no IDA function object, no xrefs to start; raw call to `0x005c2930` at `0x005c291d` |
| `0x005c292e-0x005c2930` | alignment |
| `0x005c299f-0x005c29a0` | alignment after target helper |
| `0x005c29a0-0x005c29ea` | separate raw Swallow-shaped rectangle builder, probably `GetCurrentSwallowRect(RECT *out)`; no IDA function object and no xrefs |
| `0x005c29ea-0x005c29ec` | alignment before Snowing destructor thunks |
| `0x005c29ec-0x005c2a02` | Snowing adjustor thunks, not Swallow |
| `0x005c2a02-0x005c2a18` | Swallow adjustor thunks forwarding to `0x005c2a60` |
| `0x005c2a60-0x005c2ab5` | Swallow scalar deleting destructor wrapper |

The primary target should be renamed or retitled to `0x005c2230-0x005c299f.SwallowLayerPaneCore.md` if the supervisor applies the half-open range correction. Do not widen [UID:0001O2] to `0x005c29ea` in this pass; `0x005c29a0` is another no-xref raw helper and should be tracked by a child page or a widened raw-helper support page, not silently absorbed into this already mixed aggregate.

## Source Shape And Names

Best source-facing method names/signatures:

| Address | Recommended source-facing name/signature | Evidence |
| --- | --- | --- |
| `0x005c2230` | `SwallowLayerPane::SwallowLayerPane()` | Calls `WeatherLayerPane` base constructor, installs three Swallow vtable views, initializes flight state and two frame records, loads `SWALLOW.EPF`/`SWALLOW.EPD`, schedules timer id `0x100`. |
| `0x005c2340` | `SwallowLayerPane::~SwallowLayerPane()` | Ordinary vtable-restoring destructor body; separate scalar deleting wrapper exists at `0x005c2a60`. |
| `0x005c2360` | `void SwallowLayerPane::OnPaint()` | Clears/sets pane draw context, checks active flag, offsets selected sprite rect, draws active frame. |
| `0x005c2430` | `void SwallowLayerPane::MoveBy(int dx, int dy)` | Invalidates current rect, adds deltas to X/Y, invalidates new rect. This matches Pane/Layer movement naming better than `Move` or `SetPosition`. |
| `0x005c2500` | `bool SwallowLayerPane::OnTimerEvent(int timerId, int, int)` | TimerHandler-subobject callback handles ids `0x100` and `0x101`; decompiler return type is `char`, but source should be boolean success. |
| `0x005c26b0` | `void SwallowLayerPane::DrawSwallow(GrafPort *target)` | Draws the current active frame to caller-supplied draw target without pane clear path. |
| `0x005c2760` | if retained, `void SwallowLayerPane::StartSwallowFlight()` | Body starts a flight; no live caller. |
| `0x005c2840` | if retained, `void SwallowLayerPane::StepSwallowFlight()` or `UpdateSwallowFlight()` | Body advances X and schedules next timer; no live caller. `StepSwallowFlight` is more precise than `Update` because it corresponds to timer id `0x101`. |
| `0x005c2930` | `void SwallowLayerPane::InvalidateSwallowRect()` | Computes current frame rect from direction and position, then calls the pane invalidation vslot at `+0x20`. |
| `0x005c29a0` | support follow-up: `void SwallowLayerPane::GetCurrentSwallowRect(RECT *outRect) const` | Copies the selected source rect, offsets by X/Y, returns through caller-provided rect pointer; no xrefs. |

Rejected names:

- `BackPane::StartScrollAnimation` / `BackPane::UpdateScrollAnimation`: generated pollution only. The bodies use Swallow offsets `+0x10c`, `+0x110`, `+0x114`, `+0x118`, frame offsets `+0x12c/+0x154`, and call the Swallow current-rect helper.
- `WeatherLayerPane::OnTimerEvent` for `0x005c2500`: the callback uses the embedded timer subobject but accesses concrete Swallow flight/frame state; the source owner is `SwallowLayerPane`.
- `DrawPictureObjectPane`-style render names: no evidence of picture-object ownership; the draw path uses Swallow frame records loaded from `SWALLOW`.

## Field, Global, And Helper Directions

Recommended field names/types:

| Offset | Best source-facing field | Evidence |
| --- | --- | --- |
| `+0x0a0` | secondary inherited/adjusted vtable view | Constructor/destructor/scalar deleting destructor store Swallow adjusted vtable `0x00631394`. |
| `+0x0a4` | embedded timer-handler subobject | Constructor schedules through `this+0xa4`; timer callback receives this adjusted pointer and normalizes fields by subtracting `0xa4`. |
| `+0x0f6` | inherited weather/layer enabled byte, likely `m_isVisible` or `m_weatherVisible` | Constructor sets it to `1` after scheduling; sibling weather docs already treat it as inherited weather-pane state. |
| `+0x10c` | `m_isFlightActive` / `m_isSwallowActive` | Paint/draw/timer gates and timer exit clear this byte. |
| `+0x110` | `m_swallowX` | Move/timer/rect helper read/write X position. |
| `+0x114` | `m_swallowY` | Move/timer/rect helper read/write Y position. |
| `+0x118` | `m_direction` or `m_flightDirection` | `1` selects frame at `+0x11c/+0x12c`, starts from left edge, and moves by `+10`; `-1` selects frame at `+0x144/+0x154`, starts from right edge, and moves by `-10`. |
| `+0x11c` / `+0x144` | `m_swallowFrames[2]` or two `EPFFrameDrawRecord`-like records | Constructor initializes both and loads frame indexes `0` and `1`; draw helpers pass them to frame draw routines. |
| `+0x12c` / `+0x154` | source/current frame rects embedded in the frame records | Rect copy/offset helpers select these offsets by direction. |

Recommended dependency names:

- `byte_66DA97`: use established `g_useEpfAssets` direction; constructor selects `SWALLOW.EPF` when true and `SWALLOW.EPD` when false.
- `dword_67A744`: `g_pEPFLib`, the frame/resource library used by `0x004d02f0`.
- `0x004d02f0`: source-facing `EPFLib` frame/resource lookup, e.g. `g_pEPFLib->LoadFrame(...)` or `GetFrame(...)`; avoid final name until EPFLib docs settle exact API.
- `0x00457a60`: frame record initializer/constructor.
- `0x004b8e00`: `BackPane::GetBounds` / bounds getter dependency only; does not imply BackPane ownership.
- `0x004b78f0`: rectangle offset helper, source-like `OffsetRect`.
- `0x005975e0`: `TimerHandler::ScheduleTimer` wrapper through `g_pTimerMgr`.
- virtual slot `+0x20`: pane invalidation method; document as `InvalidateRect` or `InvalidatePaneRect` pending Pane vtable final naming.

## Raw Helper Liveness

The raw start/step helpers at `0x005c2760` and `0x005c2840` remain valid Swallow-shaped code but not proven live methods:

- Live IDA still reports no function object and no xrefs to `0x005c2760`, `0x005c2835`, `0x005c2840`, or `0x005c292e`.
- Local PE scan of `NexusTK.exe` found no little-endian VA/RVA pointer encodings for `0x005c2760`, `0x005c2835`, `0x005c2840`, `0x005c292e`, `0x005c2930`, `0x005c299f`, `0x005c29a0`, `0x005c29ea`, or `0x005c29ec` except the expected Snowing thunk vtable pointer to `0x005c29ec`.
- The same rel32 scan found only two direct calls into the Swallow raw/current-rect window: `0x005c25e2 -> 0x005c2930` and raw `0x005c291d -> 0x005c2930`.
- The raw bodies are unique in current PE evidence per the executed B001 scan; they are not duplicated byte-for-byte elsewhere.

Best treatment: retain [UID:0001O3] as reconstructable Swallow helper evidence, not BackPane and not ignored dead padding. For final source, treat the raw helpers as likely source-authored private helpers whose logic was duplicated/inlined into `OnTimerEvent`, or as retained orphan compiler/linker artifacts from a source refactor. The stronger source-facing implementation is to express the live timer behavior in `OnTimerEvent`; do not force separate calls to no-xref raw helpers in final C++ without additional caller/pointer evidence.

The newly rechecked `0x005c29a0-0x005c29ea` raw helper should receive support documentation. It is Swallow-shaped and source-like (`GetCurrentSwallowRect(RECT *outRect) const`), but it has no IDA function object, no xrefs, and no VA/RVA pointer hits in the local scan. It should not be used to widen [UID:0001O2] unless the supervisor intentionally converts [UID:0001O2] into a larger raw-helper aggregate.

## Owner, Emitter, And Source Placement

Keep direct semantic owner [UID:0000E9] `SwallowLayerPane`. The constructor is reached from MapPane weather setup at `0x0050dbf3` for weather type `3`, but MapPane is only the creator/owner of the active pane instance, not the source class for these methods.

Keep current emitter [UID:0000E9]. The current autogen class route surfaces to `auto-generated/NexusTK/map/WeatherLayerPane.cpp`; this reflects the unresolved weather-family source split, not evidence that `WeatherLayerPane` is the direct class owner. [UID:0000OD] `SwallowLayerPane` file remains a plausible final file root, but the current repository still routes the class through [UID:0000P8] `WeatherLayerPane`. Do not move the emitter to a standalone `SwallowLayerPane.cpp` until the whole Weather/Raining/Snowing/Swallow family split is applied consistently.

Reject BackPane ownership. Current `simroot_v2/class_BackPane.cpp` still emits the raw `0x005c2760` and `0x005c2840` bodies as scroll-animation methods, but the field offsets, SWALLOW frame state, timer ids, and call into `0x005c2930` prove those generated names are pollution. `BackPane::GetBounds` is a dependency used to query the visible region.

Reject treating [UID:0001O2] as a non-emitting index. Unlike [UID:0001O1], this page is Swallow-only from `0x005c2230` through the current-rect invalidation helper and has a direct class owner/emitter. The reason for blank C++ is aggregate/source-shape policy, not lack of reconstructability.

## Support Docs To Update

If accepted, supervisor should update:

- [UID:0001O2] target: raise score, update H1/path/range to `0x005c2230-0x005c299f`, convert covered ranges to half-open end addresses, add the reanalysis notes above, and leave formal C++ blank.
- [UID:0000E9] `by-class/SwallowLayerPane.md`: add final field-name directions for `+0x10c/+0x110/+0x114/+0x118/+0x11c/+0x144`, clarify `OnTimerEvent` source signature, and document `0x005c29a0` as adjacent raw Swallow rectangle helper evidence.
- [UID:0000OD] `by-file/SwallowLayerPane.md`: update links/ranges from `0x005c299e` to `0x005c299f`, add `0x005c29a0-0x005c29ea` support row or TODO, and reject generated BackPane names explicitly for both raw flight helpers.
- [UID:0000P8] `by-file/WeatherLayerPane.md`: sync the [UID:0001O2] range and keep the conservative weather-family routing caveat.
- [UID:0001O1] `SnowingAndSwallowLayerPanes`: add a covered-range row for `0x005c29a0-0x005c29ea` or point to the new/widened raw-helper support page; it already says `0x005c299f-0x005c29ec` is not pure padding but does not name the helper.
- [UID:0001O3] `SwallowLayerPaneRawFlightHelpers`: either keep as-is for only `0x005c2760-0x005c292e` and create a new child for `0x005c29a0`, or widen/rename to `SwallowLayerPaneRawFlightAndRectHelpers` if supervisor wants one raw-helper page. Do not silently fold `0x005c29a0` into [UID:0001O2]'s final C++.
- Generated pollution notes for BackPane, if edited later: maintain the rejection of `StartScrollAnimation`/`UpdateScrollAnimation` at `0x005c2760`/`0x005c2840`.

## Exact Score And Metadata Recommendations

For [UID:0001O2]:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000E9
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000E9
RECONSTRUCTION_CPP CODE:[[[]]]
```

Rationale: source owner, method boundaries, caller/vtable/resource dependencies, timer semantics, fields, and generated pollution are now strong. Completion should not exceed high 80s because this page is still a multi-method aggregate, two in-range helper bodies are raw/no-xref, final standalone-vs-weather-family file routing is unresolved, and adjacent raw helper `0x005c29a0` needs a support split decision.

## Supervisor-Owned Coverage Row

If supervisor applies the range correction and score change, replace the existing [UID:0001O2] row near the current [UID:0001O1]/[UID:0001O3] rows in `by-memory/-coverage-report.md` with:

```text
    - [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md) : reconstructable : 88% : strong : SwallowLayerPane core aggregate; live IDA and PE-byte reanalysis confirm the modeled constructor/destructor/paint/move/timer/draw/current-rect helper boundaries, correct half-open end `0x005c299f`, MapPane weather setup caller, Swallow vtable/resource/timer dependencies, active/position/direction/frame-record field semantics, raw flight helper no-xref status, generated BackPane pollution rejection, and blank formal C++ policy because this is a multi-method aggregate with overlapping raw-helper split decisions.
```

Adjacent note: the current [UID:0001O3] coverage row in `by-memory/-coverage-report.md` still shows `82% : medium-high`, while the executed B001 docs/report say it was accepted at `85/88`. That synchronization is not a new B002 primary recommendation, but the supervisor may want to apply the already-accepted B001 row while editing this neighborhood.

## Heuristic / Inference Reanalysis And Validation

Best defensible names/types/source directions:

- Class owner is `SwallowLayerPane`, not `BackPane`, `MapPane`, or base `WeatherLayerPane`.
- `0x005c2500` is a TimerHandler-adjusted `SwallowLayerPane::OnTimerEvent` body. The incoming `this` points at the embedded timer subobject at full-object `+0xa4`; all field names must be normalized back to full-object offsets.
- `+0x10c` is active/flight-active state, `+0x110/+0x114` are X/Y, `+0x118` is signed direction, and `+0x11c/+0x144` are two frame records with selected rects at `+0x12c/+0x154`.
- `0x005c2760` and `0x005c2840` are Swallow raw helper evidence. The best source names are `StartSwallowFlight` and `StepSwallowFlight`, but they should not be emitted as live helpers unless new caller/pointer evidence appears.
- `0x005c2930` is `InvalidateSwallowRect` and should be included in the target with half-open end `0x005c299f`.
- `0x005c29a0` is likely `GetCurrentSwallowRect(RECT *outRect) const` and should be documented separately as adjacent no-xref raw helper evidence.

Evidence checked:

- Live IDA `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `disasm`, and `analyze_function` on the modeled functions and raw boundaries.
- Constructor decompilation for vtable stores, `SWALLOW.EPF`/`SWALLOW.EPD` resource selection through `g_useEpfAssets`, frame initialization/load calls, and timer scheduling.
- Paint/draw/move/timer decompilation for field use, rect invalidation, timer ids `0x100`/`0x101`, 10 ms step cadence, and restart delay `10000 + rand() % 40000`.
- Vtable data docs and live xrefs for `0x00631340`, `0x00631394`, and `0x006313c4`.
- Generated-output context showing `BackPane` pollution and real Swallow class output.
- Local PE-byte scan for VA/RVA encodings and direct rel32 branches/calls into the raw Swallow helper window.

Rejected alternatives:

- BackPane source ownership: rejected because only the bounds getter is a BackPane dependency; raw helper fields and frame resources are Swallow-specific.
- MapPane ownership: rejected because MapPane creates/selects the weather pane but does not implement these methods.
- Base `WeatherLayerPane` method ownership: rejected for the concrete Swallow vtables, resources, and fields; retained only as conservative file-family emitter route.
- Treating raw helpers as pure padding/dead ignored bytes: rejected because they are complete function-shaped bodies with coherent Swallow behavior and internal calls.
- Treating raw helpers as proven live source methods: rejected because live IDA xrefs and PE pointer/direct-edge scans found no call/pointer references to their starts.
- Populating final C++ in the aggregate: rejected because it would mix multiple methods, raw no-xref bodies, child-page overlap, and an unresolved `0x005c29a0` support split.

Validation or correction of existing docs:

- Existing docs are correct to attach [UID:0001O2] to `SwallowLayerPane` and to reject generated BackPane ownership.
- Existing docs are stale/incomplete on the half-open end of the target helper: the current target filename/title ending `0x005c299e` should become `0x005c299f`.
- Existing aggregate [UID:0001O1] correctly says `0x005c299f-0x005c29ec` is not pure padding, but support docs should name/split the `0x005c29a0-0x005c29ea` raw rect helper.
- Existing raw-helper liveness uncertainty is validated but narrowed: not just "no xrefs"; the direct-edge/pointer scan also failed to find VA/RVA or external rel32 references to the raw starts.

Score/source-placement/final-C++ impact:

- Score can rise to `88/90` because the remaining issues are source-shape/split-policy issues, not owner or behavior uncertainty.
- Source placement should stay with `SwallowLayerPane` under the weather-layer map family; final `SwallowLayerPane.cpp` versus combined `WeatherLayerPane.cpp` should be resolved family-wide.
- Formal C++ should remain blank for [UID:0001O2] despite passing the numeric gate, because the page is not a single target method and C++ would either duplicate child raw-helper pages or omit in-range bytes.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:0001O2].

Concrete reason: [UID:0001O2] is a reconstructable/emitting aggregate, not a single final source method. It spans constructor/destructor/paint/move/timer/draw/current-rect helper bodies plus two overlapping no-xref raw helper bodies already tracked by [UID:0001O3]. It also sits immediately before a newly rechecked no-xref raw rect helper at `0x005c29a0`. Entering a multi-method C++ fragment into this aggregate would create duplicate or misleading output and would not resolve the retained-helper versus inlined/orphan artifact policy.

For future exact child C++ drafts, use these source directions:

```cpp
SwallowLayerPane::SwallowLayerPane();
SwallowLayerPane::~SwallowLayerPane();
void SwallowLayerPane::OnPaint();
void SwallowLayerPane::MoveBy(int dx, int dy);
bool SwallowLayerPane::OnTimerEvent(int timerId, int param1, int param2);
void SwallowLayerPane::DrawSwallow(GrafPort *target);
void SwallowLayerPane::InvalidateSwallowRect();

// Raw/no-xref helpers: document but do not force into live final source yet.
void SwallowLayerPane::StartSwallowFlight();
void SwallowLayerPane::StepSwallowFlight();
void SwallowLayerPane::GetCurrentSwallowRect(RECT *outRect) const;
```

## Validation Commands

Read-only/verification commands used or recommended:

> Executable block R001 was removed from this report and preserved verbatim in [0001O2-swallowlayerpane-core-source-quality-removed.md](0001O2-swallowlayerpane-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Leases, Changed Files, Blockers

No leases were needed for this report-only write in the B002 research folder.

Changed file:

- `tools/leaser/Agents/Agent-B002/research/0001O2-swallowlayerpane-core-source-quality.md`

No blocker prevents supervisor review. The only unresolved follow-up is policy/coverage work for adjacent `0x005c29a0-0x005c29ea`: create a new child page or widen/rename [UID:0001O3] if the supervisor wants that no-xref raw rectangle helper represented explicitly.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001O2-swallowlayerpane-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001O2"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001O2-swallowlayerpane-core-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001O2-swallowlayerpane-core-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001O2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
