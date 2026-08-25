** TARGET-REPORT-UID:0001O1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001O1 Snowing/Swallow Weather-Layer Source Placement Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](../../../../../by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) from a reconstructable emitting aggregate to a reviewed non-emitting weather-layer migration index under [UID:0000P8][WeatherLayerPane](../../../../../by-file/WeatherLayerPane.md).
- Final disposition for [UID:0001O1]: `CANONICAL_OWNER:0000P8`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank final C++; recommended score `86/88`.
- Final disposition for linked [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](../../../../../by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md): keep `CANONICAL_OWNER:0000E9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E9`, blank final C++; recommended score `85/88`.
- Required action: target metadata updates for `0001O1`, score/evidence update for `0001O3`, and exact `by-memory/-coverage-report.md` row replacements listed below. No IDA DB edit is recommended.
- Confidence: high for mixed-container reclassification of `0001O1`; medium-high for retaining `0001O3` as source-bearing Swallow raw helper evidence because reachability remains unresolved after static checks.

## Target

- Assignment: `B001-goal2-snowing-swallow-source-placement-0001O1-20260616`.
- Primary target: [UID:0001O1] `by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md`.
- Linked/support target: [UID:0001O3] `by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md`.
- Current primary state before this report: `82/84`, `CANONICAL_OWNER:0000P8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P8`, blank final C++.
- Current support state before this report: `82/84`, `CANONICAL_OWNER:0000E9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E9`, blank final C++.
- Source queue row: `Supervisor_notes.md` line for `0001O1-source-placement`, assigned to B001 on 2026-06-16.

## Executive Recommendation

[UID:0001O1] should not remain an emitting reconstructable memory item. It is useful and should remain owned by the weather-layer source family, but it is a mixed Snowing/Swallow address-neighborhood map whose exact source-bearing children already carry the real output routes. Under the current `by-structure.md` aggregate rule, the container itself is not a source-level object, declaration, table, or emitted source range.

[UID:0001O3] should remain a reconstructable SwallowLayerPane raw helper page. The helpers are not BackPane methods, not proven padding, not proven CRT/compiler-only output, and not proven safe to discard as dead duplicate code. The correct current source model is "retained Swallow private helper evidence with no recovered entry path"; keep final C++ blank until a caller/function-object/liveness recovery or a final-source decision proves whether these helpers should be represented as out-of-line private methods, omitted dead code, or absorbed into `OnTimerEvent`.

No split is required in this B assignment. Splitting `0001O3` into two child helper pages would be mechanically possible, but it would not resolve liveness or source placement; both helper bodies have the same owner, same evidence class, same no-xref blocker, and same final-C++ caveat.

## Guidance Check

`by-structure.md` says reviewed containers should be classified based on whether the container itself becomes a source-level object. It specifically calls for `RECONSTRUCTABLE:FALSE` on broad address-neighborhood maps or mixed-owner convenience pages whose exact children carry the real source ownership. That rule directly applies to `0001O1`.

The same guidance says real NexusTK source code should remain `RECONSTRUCTABLE:TRUE` even when final owner, emitter route, or C++ is not ready. That rule applies to the two raw Swallow helper bodies in `0001O3` unless and until evidence proves they are ignorable dead/compiler-only artifacts.

No Wave2/Wave3 source data was used directly for this report. Existing by-* docs, generated coverage reports under `project-documentation/auto-generated`, live IDA MCP, and raw PE byte scans were used. Existing docs that mention older generated/simroot pollution were treated as documentation evidence and rechecked against IDA/PE facts where material.

## IDA MCP Facts

Active IDA session:

- MCP session: `c001_midiplayer_rdata_20260615`.
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Imagebase: `0x400000`.
- Hex-Rays ready: true.

Function/range facts from live `lookup_funcs`:

| Address | IDA state |
| --- | --- |
| `0x005c1bd0` | `sub_5C1BD0`, size `0xae` |
| `0x005c1c80` | `sub_5C1C80`, size `0x2cc` |
| `0x005c1f50` | `sub_5C1F50`, size `0x184` |
| `0x005c20e0` | `sub_5C20E0`, size `0x148` |
| `0x005c2230` | `sub_5C2230`, size `0x110` |
| `0x005c2340` | `sub_5C2340`, size `0x1f` |
| `0x005c2360` | `sub_5C2360`, size `0xc3` |
| `0x005c2430` | `sub_5C2430`, size `0xca` |
| `0x005c2500` | `sub_5C2500`, size `0x1a6` |
| `0x005c26b0` | `sub_5C26B0`, size `0xac` |
| `0x005c2760`, `0x005c2768`, `0x005c2835` | not functions |
| `0x005c2840`, `0x005c292e` | not functions |
| `0x005c2930` | `sub_5C2930`, size `0x6f` |
| `0x005c29ec`, `0x005c29f7`, `0x005c2a02`, `0x005c2a0d` | thunk functions, each size `0xb` |
| `0x005c2a20` | Snowing scalar deleting destructor, size `0x3b` |
| `0x005c2a60` | Swallow scalar deleting destructor, size `0x55` |
| `0x005c2ac0` | successor `WorldMapPane` function, size `0x7ea` |

Xref facts:

- `0x005c1bd0` has the expected constructor call from `0x0050dc17` inside `sub_50DB50`.
- `0x005c2230` has the expected constructor call from `0x0050dbf3` inside `sub_50DB50`.
- `0x005c2760`, `0x005c2768`, `0x005c2835`, `0x005c2840`, and `0x005c292e` have zero IDA xrefs.
- `0x005c2930` has exactly two IDA xrefs: modeled caller `0x005c25e2` in `sub_5C2500`, and raw-code caller `0x005c291d` with no containing IDA function.
- `0x005c2a20` is reached from Snowing thunks at `0x005c29f2` and `0x005c29fd`, plus data ref `0x006312b0`.
- `0x005c2a60` is reached from Swallow thunks at `0x005c2a08` and `0x005c2a13`, plus data ref `0x00631340`.
- Snowing virtual method target refs are class-local: `0x005c1c80 <- 0x006312f4`, `0x005c1f50 <- 0x006312fc`, `0x005c20e0 <- 0x006312c0`, thunks `0x005c29ec <- 0x00631304` and `0x005c29f7 <- 0x00631334`.
- Swallow virtual method target refs are class-local: `0x005c2360 <- 0x00631384`, `0x005c2430 <- 0x00631388`, `0x005c2500 <- 0x006313c8`, `0x005c26b0 <- 0x00631350`, thunks `0x005c2a02 <- 0x00631394` and `0x005c2a0d <- 0x006313c4`.
- Swallow vtable view stores point to `0x00631340`, `0x00631394`, and `0x006313c4` from the constructor/destructor/deleting-destructor family.
- `SWALLOW.EPF` at `0x006313cc` is referenced only from `0x005c22d6` and `0x005c22e9` inside `sub_5C2230`.
- `SWALLOW.EPD` at `0x006313e4` is referenced only from `0x005c22f0` and `0x005c2303` inside `sub_5C2230`.

Behavior/callee facts:

- `sub_50DB50` calls rain, snow, and swallow constructors: `0x005c1410`, `0x005c1bd0`, and `0x005c2230`.
- `sub_5C2230` calls the base weather constructor `0x005c12a0`, frame/resource helpers `0x00457a60` and `0x004d02f0`, and timer scheduler `0x005975e0`.
- `sub_5C2500` calls `0x004b78f0`, `0x004b8e00`, `_rand`, `0x005c2930`, `0x005975e0`, and the security-cookie check.
- `sub_5C2930` calls only `0x004b78f0` and the security-cookie check.
- Decompilation of `sub_5C2500` contains the live timer implementation for ids `0x100` and `0x101`: choose direction with `rand`, query bounds through `0x004b8e00`, invalidate rectangles through `0x004b78f0` and virtual slot `+0x20`, call `0x005c2930` on the in-bounds step path, schedule `0x101` after `10`, and schedule restart `0x100` after `10000 + rand() % 40000`.
- Decompilation at raw starts `0x005c2760` and `0x005c2840` fails because neither is an IDA function.

Raw disassembly facts:

- `0x005c2760` starts with a normal stack-cookie prologue and writes `byte ptr [esi+0x10c] = 1`; it chooses `[esi+0x118]`, queries bounds through `0x004b8e00`, initializes `[esi+0x110]` and `[esi+0x114]`, invalidates a frame rect through `0x004b78f0` and vslot `+0x20`, and schedules timer id `0x101` with delay `0x0a` through `0x005975e0`.
- `0x005c2840` selects frame offsets `0x12c`/`0x154`, reads `[esi+0x110]` and `[esi+0x114]`, invalidates through `0x004b78f0` and vslot `+0x20`, advances `[esi+0x110]` by direction, queries bounds through `0x004b8e00`, clears `[esi+0x10c]` and schedules timer id `0x100` after `0x2710 + rand() % 0x9c40` on the exit path, or calls `0x005c2930` and schedules timer id `0x101` after `0x0a` on the visible path.
- `get_bytes` around the boundaries confirms `0xcc` alignment at `0x005c275c-0x005c2760`, `0x005c2835-0x005c2840`, `0x005c292e-0x005c2930`, `0x005c299f-0x005c29a0`, `0x005c2a18-0x005c2a20`, `0x005c2a5b-0x005c2a60`, and `0x005c2ab5-0x005c2ac0`.

False generated-row evidence:

- Live `get_bytes` at `0x006313cc` decodes UTF-16 `SWALLOW.EPF\0SWALLOW.EPD\0`.
- IDA also sees the first UTF-16 dword as `0x00570053`, producing false data xrefs from `0x006313cc` and `0x006313e4` to `0x00570053`.
- `lookup_funcs 0x00570053` resolves inside `sub_570030`, not at a function start. This explains the existing bad generated `0x00570053` row noted in the Swallow docs and is not executable ownership evidence.

## Raw PE Scan Facts

Raw PE scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`.

Sections relevant to this assignment:

- `.text` `0x00401000-0x0060c600`.
- `.rdata` `0x0060d000-0x0066c200`.
- `.data` `0x0066d000-0x0069ce24`.
- `.rsrc` `0x0069d000-0x006b2e00`.

Exact body uniqueness:

| Body | Range | Result |
| --- | --- | --- |
| raw start helper | `0x005c2760-0x005c2835` | one occurrence, at `0x005c2760` |
| raw step helper | `0x005c2840-0x005c292e` | one occurrence, at `0x005c2840` |
| combined raw pair | `0x005c2760-0x005c292e` | one occurrence, at `0x005c2760` |
| Swallow core aggregate | `0x005c2230-0x005c299e` | one occurrence, at `0x005c2230` |
| Snowing/Swallow island | `0x005c1bd0-0x005c2ab5` | one occurrence, at `0x005c1bd0` |

Pointer-byte scan:

- No little-endian VA or RVA hits were found for `0x005c2760`, `0x005c2768`, `0x005c2835`, `0x005c2840`, `0x005c292e`, `0x005c2930`, `0x005c299f`, `0x005c2ab5`, or `0x005c2ac0`.
- Expected vtable pointer hits were found for the thunk/destructor targets only: `0x005c29ec` at `0x00631304`, `0x005c29f7` at `0x00631334`, `0x005c2a02` at `0x00631394`, `0x005c2a0d` at `0x006313c4`, `0x005c2a20` at `0x006312b0`, and `0x005c2a60` at `0x00631340`.

Relative branch/call scan:

- Direct relative calls to constructors match IDA: `call 0x005c1bd0` at `0x0050dc17`, and `call 0x005c2230` at `0x0050dbf3`.
- No external relative branch or call targets enter either raw helper range.
- Direct relative hits to `0x005c2930` are exactly `call 0x005c2930` at `0x005c25e2` and raw `call 0x005c2930` at `0x005c291d`.
- Direct relative hits to destructors match IDA thunk edges: `jmp 0x005c2a20` at `0x005c29f2` and `0x005c29fd`; `jmp 0x005c2a60` at `0x005c2a08` and `0x005c2a13`.
- The only branch targets into the raw ranges are internal helper branches, for example `0x005c2784 -> 0x005c278b`, `0x005c28cb -> 0x005c2911`, `0x005c2914 -> 0x005c28d2`, and `0x005c292c -> 0x005c28f1`. These are not entry reachability.

Debug/source metadata scan:

- No `RSDS`, `NB10`, `.pdb`, `.PDB`, `.cpp`, or `.CPP` strings were found.
- The PE has a debug directory entry of type `13`, not CodeView/PDB, and it does not recover source-file ownership.
- Strings/names `WeatherLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` appear once each in `.data`, but they do not resolve the one-file versus split-file source decision.

UTF-16 literal scan:

- `SWALLOW.EPF` appears exactly once at `0x006313cc`.
- `SWALLOW.EPD` appears exactly once at `0x006313e4`.

## Function / Child Inventory

| Range / item | UID / path | Role | Reconstructable | Direct parent | Status |
| --- | --- | --- | --- | --- | --- |
| `0x005c1bd0-0x005c2ab5` | `0001O1` | broad interleaved weather-layer migration index | recommend `FALSE` | `0000P8` | exact child pages should carry source, not the aggregate |
| `0x005c1bd0-0x005c2a5b` | `0001O0` | Snowing method index | `FALSE` | `0000DC` | established precedent for non-emitting index over interleaved island |
| `0x005c1bd0-0x005c2228`, `0x005c2a20-0x005c2a5b` | `0003O0`-`0003O4` | exact Snowing children | `TRUE` | `0000DC` | source-bearing child methods |
| `0x005c2230-0x005c299e` plus companion tail | `0001O2` | Swallow core aggregate | `TRUE` | `0000E9` | source-bearing class aggregate, raw-helper caveat remains |
| `0x005c2760-0x005c292e` | `0001O3` | two raw Swallow flight helper bodies | keep `TRUE` | `0000E9` | Swallow-owned raw evidence, no final C++ |
| `0x005c29ec-0x005c2a18` | ignored/thunk rows and child docs | Snowing/Swallow adjustor thunks | compiler-generated | Snowing/Swallow destructor semantics | not parent aggregate source |
| `0x005c2ab5-0x005c2ac0` | ignored row | padding before WorldMapPane | ignored | none | confirmed `0xcc` alignment |

## Documentation And Generated-State Evidence

- [UID:0000P8][WeatherLayerPane](../../../../../by-file/WeatherLayerPane.md) is the current source-family root. It explicitly keeps the final one-file versus per-layer split open and lists the concrete weather panes plus weather static data as the file-family contents.
- [UID:0000NR][SnowingLayerPane](../../../../../by-file/SnowingLayerPane.md) and [UID:0000OD][SwallowLayerPane](../../../../../by-file/SwallowLayerPane.md) are valid map source-file candidates, but current class emitters still route through [UID:0000P8].
- [UID:0000DC][SnowingLayerPane](../../../../../by-class/SnowingLayerPane.md) and [UID:0000E9][SwallowLayerPane](../../../../../by-class/SwallowLayerPane.md) both clear the parent gate and both emit through `0000P8` in current generated coverage.
- `auto-generated/-ag-memory-coverage.md` currently shows `0001O1` emitting directly through `0000P8` to `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, while exact Snowing children and Swallow aggregate/helper pages also emit through their class routes to the same file. This is duplicate emitting metadata for a parent whose C++ block is blank.
- `auto-generated/-ag-file-coverage.md` has separate file roots for `WeatherLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp`, but the active class routes for Weather/Raining/Snowing/Swallow all still emit to `WeatherLayerPane.cpp`.
- The staged map source files are currently zero-byte placeholders, so no actual generated C++ body conflicts exist.
- [UID:0000HO][BackPane](../../../../../by-file/BackPane.md) explicitly rejects `0x005c2760`, `0x005c2840`, and `0x005c2930` as BackPane source and keeps them with Swallow/weather docs. [UID:000161][BackPaneGetBounds](../../../../../by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md) remains the only BackPane-owned helper involved here; it is a broad bounds accessor consumed by the raw Swallow helpers.
- [UID:0002ZB][SwallowLayerResourceStrings](../../../../../by-memory/0x006313cc-0x006313fc.SwallowLayerResourceStrings.md) documents the UTF-16 string typing issue that creates `0x00570053` false-pointer pollution.
- `by-memory/-coverage-report.md` is stale for `0001O1` (`50% : medium : reconstructable`) and should be replaced. `0001O3` is structurally correct but should receive the B001 score/evidence row if the target score is raised.

## Ranked Ownership / Source-Placement Analysis

### 1. `0001O1` as non-emitting WeatherLayerPane migration index

Evidence for:

- It is a real, useful map of the local weather-layer island.
- The source family owner [UID:0000P8] is appropriate because the island is a Weather/Raining/Snowing/Swallow map-weather source-family cluster.
- It is mixed by direct class ownership: Snowing owns `0x005c1bd0-0x005c2228`, Snowing thunks/destructor own `0x005c29ec-0x005c2a5b`, Swallow owns `0x005c2230-0x005c299f`, Swallow thunks/destructor own `0x005c2a02-0x005c2ab5`, and padding separates several pieces.
- Exact source-bearing children already exist for the Snowing side and for the Swallow core/raw-helper side.
- [UID:0001O0] is already a reviewed non-emitting method index over a subset of the same interleaved island, which is the closest local precedent.

Evidence against:

- None that makes the broad address range itself a source-level declaration or function. Even if final output keeps all weather classes in one `WeatherLayerPane.cpp`, the emitted source items are the classes/methods/helpers/tables, not the broad memory island page.

Decision: accept. Keep `CANONICAL_OWNER:0000P8` for semantic/source-family containment, but change `RECONSTRUCTABLE` to `FALSE` and clear `EMITTER_UIDS`.

### 2. `0001O1` as a reconstructable aggregate emitted through WeatherLayerPane

Evidence for:

- The whole island belongs to the map weather-layer family.
- Existing docs already attach it to [UID:0000P8].
- Neighbor [UID:0001NZ] still uses an emitting aggregate model for the base/rain island.

Evidence against:

- `0001O1` has no unique source-level object represented by the full range.
- Exact children already carry source ownership. Emitting the parent is duplicate metadata even with blank C++.
- The active aggregate rule says broad mixed-owner convenience pages whose exact children carry source should be `FALSE`.
- The page itself says it must split into Snowing/Swallow pieces before final code emission; those pieces now exist.

Decision: reject for `0001O1`. This does not force a change to [UID:0001NZ] in this assignment, because `0001NZ` was not the assigned target and may need a separate exact-child split/review pass.

### 3. Separate SnowingLayerPane.cpp and SwallowLayerPane.cpp emitters

Evidence for:

- Proposed source tree and by-file roots list `WeatherLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp` under `map/`.
- The concrete class docs name standalone file candidates.

Evidence against:

- No PDB/source path/linker map evidence exists to prove final split.
- Current class pages deliberately route through [UID:0000P8] as the conservative weather-family emitter.
- Moving class emitters from `0000P8` to `0000NR`/`0000OD` would be a broader weather-family source-layout decision beyond this one memory-container fix.

Decision: do not change class/file emitters now. Record that final split remains open.

### 4. BackPane owner/emitter for raw helpers

Evidence for:

- Historical generated output named the raw helpers as BackPane scroll-animation methods.
- The raw helpers call [UID:000161] `BackPaneGetBounds`.

Evidence against:

- Raw helper fields are Swallow fields: active flag `+0x10c`, position `+0x110/+0x114`, direction `+0x118`, frame records `+0x12c/+0x154`, and timer subobject `+0xa4`.
- The raw step helper calls Swallow current-rect invalidation helper `0x005c2930`.
- BackPane docs explicitly reject these rows as generated-owner pollution.
- Calling a broad BackPane bounds accessor is consumer/dependency evidence, not source ownership.

Decision: reject. Do not attach `0001O3` to BackPane or move any rows into `BackPane.cpp`.

### 5. Treat `0001O3` as dead/duplicate/non-emitting evidence only

Evidence for:

- No IDA function objects at `0x005c2760` or `0x005c2840`.
- No IDA xrefs to the raw starts or alignment endpoints.
- No local PE VA/RVA pointer hits to the raw starts/endpoints.
- No external relative branch/call encodings into the raw helper ranges.
- Modeled `SwallowLayerPane::OnTimerEvent` already contains equivalent start/step timer behavior.

Evidence against:

- The byte bodies are complete function-shaped NexusTK code, not padding.
- They are exact unique bodies in `.text`.
- They operate entirely on Swallow fields and dependencies.
- The step helper has a real outgoing code edge to modeled `0x005c2930`, and IDA records that raw-code xref.
- No debug/source/linker metadata is available to prove whether these are unused out-of-line private methods, emitted-but-inlined helper bodies, or dead duplicate code from a retained object file.

Decision: reject reclassification to `FALSE` or ignored for now. Keep `0001O3` as reconstructable Swallow raw helper evidence with blank final C++ and documented liveness blocker.

### 6. IDA DB repair by creating functions at raw starts

Evidence for:

- Both raw bodies have clear prologues, stack cookies, code flow, and returns/alignment.
- Creating functions could improve local decompilation.

Evidence against:

- No incoming refs, pointer hits, or external branch targets prove either raw start is a live entry point.
- The documentation question is source/liveness classification, not just decompiler convenience.
- Creating IDA functions would make the database imply a stronger entry-point claim than the evidence supports.

Decision: no IDA DB repair. Leave IDA untouched. If a future agent wants experimental function creation for local analysis, it should be treated as temporary and not as documentation evidence unless reachability is also proven.

## Unresolved Issues And How They Were Investigated

Raw helper liveness remains unresolved. Checked evidence: live IDA `lookup_funcs`, `xref_query`, `trace_data_flow`, `disasm`, `decompile` failures at raw starts, local PE exact body uniqueness, VA/RVA pointer scans, direct relative branch/call scans, modeled `OnTimerEvent` decompilation, BackPane/Swallow/Weather docs, resource-string false-pointer pollution, and PE debug/source metadata. Static evidence proves the helpers are Swallow-shaped and unreferenced in the current IDB/PE, but it cannot prove original source intent or whether final reconstruction should emit out-of-line private helpers. This blocks final C++ for `0001O3`, not ownership.

Final one-file versus split-file weather source placement remains unresolved. Checked evidence: by-file roots for Weather/Snowing/Swallow, by-class emitter routes, proposed source tree, generated coverage, constructor call paths from MapPane, vtable/resource ownership, and PE debug/source metadata. No source path, PDB, linker map, or compilation-unit metadata was found. Current [UID:0000P8] source-family routing remains the conservative route; do not move class emitters to `0000NR`/`0000OD` in this assignment.

`0001NZ` may deserve a future source-container review. It is a neighboring Weather/Raining aggregate still marked reconstructable/emitting, but it was not assigned here and does not have the same current exact-child split state as `0001O1`. This report does not recommend changing `0001NZ`.

## Supervisor Actions

### Target metadata: `0001O1`

In `by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md`, replace the header metadata with:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `EMITTER_POSITION_OPTIONAL` blank and keep `RECONSTRUCTION_CPP CODE` blank.

Recommended status wording to add or use when editing the page:

```text
- Disposition: reviewed non-emitting weather-layer migration index/source-family map.
- Reconstruction handling: `RECONSTRUCTABLE:FALSE`; keep [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) as the semantic source-family owner, but do not emit source from this broad mixed Snowing/Swallow address island. Exact Snowing and Swallow child pages carry source ownership and any future C++.
```

Recommended change-log note:

```text
- 2026-06-16 B001 source-placement review:
  - Changed from `82/84`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P8` to `86/88`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
  - Summary/evidence: live IDA MCP, raw PE pointer/branch/body scans, generated coverage, source-tree docs, and neighboring weather-layer pages show this is a mixed Snowing/Swallow migration index whose exact child pages already carry source ownership. Keep [UID:0000P8] as the semantic weather-family owner, but do not emit aggregate source from this broad range.
```

### Target metadata: `0001O3`

In `by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md`, change only scores:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000E9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep final C++ blank.

Recommended change-log note:

```text
- 2026-06-16 B001 source-placement/liveness review:
  - Changed scores from `82/84` to `85/88`; owner, reconstructable flag, emitter route, and blank final C++ remain unchanged.
  - Summary/evidence: live IDA still has no function objects or incoming xrefs for `0x005c2760`/`0x005c2840`; local PE scans found each helper body exactly once, no VA/RVA pointer hits to raw starts/endpoints, and no external branch/call targets into the raw ranges. The raw bodies remain Swallow-shaped through active/direction/position/frame/timer fields and the raw call to `0x005c2930`, so they stay reconstructable Swallow raw helper evidence, not BackPane and not proven dead/ignored code.
```

### Shared `by-memory/-coverage-report.md` rows

Do not edit this file directly as B001. Supervisor should replace the current `0001O1` row immediately after the `0x005c1bc7-0x005c1bd0` padding row and before the `0001O0` row with:

```text
    - [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) 0x005c1bd0-0x005c2ab5 | migration index | SnowingAndSwallowLayerPanes : not_reconstructable : 86% : strong : B001 2026-06-16 reclassified the interleaved Snowing/Swallow weather-layer island as a non-emitting source-family migration index under [UID:0000P8] WeatherLayerPane; exact Snowing children, Swallow core [UID:0001O2], raw Swallow helpers [UID:0001O3], compiler thunks, and padding rows carry the actual source/ignore state, so no aggregate final C++ should emit from this range.
```

Supervisor should replace the current `0001O3` row immediately after the `0001O2` row and before the `0x005c2ab5-0x005c2ac0` padding row with:

```text
    - [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) 0x005c2760-0x005c292e | raw helper pair | SwallowLayerPaneRawFlightHelpers : reconstructable : 85% : strong : B001 2026-06-16 keeps these as SwallowLayerPane raw start/step flight helper evidence: live IDA reports no function objects or incoming xrefs at the raw starts/endpoints, local PE scans find unique helper bodies with no raw-start pointer or external branch/call hits, and the disassembly matches Swallow active/direction/position/frame/timer state plus the raw call to `0x005c2930`; helper liveness and final C++ remain blocked.
```

If the supervisor performs containment-format cleanup in the same shared-row edit, the existing `0001O0`, exact Snowing child rows, `0001O2`, and `0001O3` rows should be nested under the non-emitting `0001O1` migration-index row. That nesting is a coverage-format cleanup; the required semantic change is the `0001O1` `not_reconstructable` row and the `0001O3` score/evidence row above.

### Validation commands for supervisor

Run after applying target/shared row edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001O1-snowing-swallow-source-placement-removed.md](0001O1-snowing-swallow-source-placement-removed.md). The archived block is non-authoritative and must not be executed.

### No recommended changes

- No IDA DB repair.
- No BackPane doc change; existing BackPane docs already reject the raw helper pollution.
- No WeatherLayerPane/SnowingLayerPane/SwallowLayerPane by-file or by-class emitter-route change in this assignment.
- No split/merge/rename for `0001O3` now.
- No final C++ for either target.

## Validator Results

No validator commands were run by B001 because this assignment requested a research report only and no by-* files were edited directly.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001O1-snowing-swallow-source-placement.md`.
- Modified: none outside the Agent-B001 research report.
- IDA DB: untouched.
- `by-memory/-coverage-report.md`: untouched by B001; exact supervisor replacement rows are provided above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001O1-snowing-swallow-source-placement.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001O1"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001O1-snowing-swallow-source-placement-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001O1-snowing-swallow-source-placement.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001O1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
