** TARGET-REPORT-UID:0000YL **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0000YL AlphaMaskSurface Source-Quality Research


## Finalized Report / Current Recommendation

This report passed supervisor Gate 1 at hash `D2798626CDB8E2D58A5F7BCB1F3E94CD1140F24C3FBED1210AA393D7F5208BDE` and has now completed the implementation callback for [UID:0000YL] `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`. Target/support by-* changes were applied only to the accepted scope; no `execute_report`, execute dry-run/probe/status variant, lifecycle/archive command, manual report move, generated-file manual edit, coverage-report edit, supervisor-ledger edit, queue/lock edit, or IDA DB edit was performed.

Applied recommendation: UID0000YL remains the AlphaMaskSurface method-family aggregate owned/emitted by [UID:0000HF] `by-file/AlphaMaskSurface.md`; target metadata is now `COMPLETION:87` / `CONFIDENCE:92`; `CANONICAL_OWNER:0000HF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HF`, and blank emitter position are preserved; and the formal C++ block now contains the exact comment-only no-code marker from `## First-Draft C++ Recommendation`.

UID0000YL must not emit a monolithic helper/function body. Current MCP evidence shows the range is a mixed aggregate containing independent AlphaMaskSurface methods, a compiler cleanup chunk, existing exact child/sibling pages, and alignment padding. Exact source bodies should live on exact by-memory child pages or already-resolved sibling/child pages, not in this aggregate.

## Supporting Research

Inputs inspected for this report:

- Current target doc: `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`.
- Required support docs: `by-file/AlphaMaskSurface.md`, `by-class/AlphaMaskSurface.md`, `by-type/by-struct/AlphaMaskSurfaceLayout.md`, `by-type/by-struct/AlphaSurfaceBufferView.md`, `by-type/by-vtable/IntAlphaSurfaceVtable.md`, `by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md`, `by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md`, `by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md`, `by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md`, `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md`, `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`, and matching by-item aliases for `BuildClippedAlphaSurfaceView`, `InitAlphaSurfaceView`, and `AlphaSurfaceReleaseOwnedPixels`.
- Pre-callback read-only generated output: `auto-generated/NexusTK/render/AlphaMaskSurface.cpp`; header reported `validator-command-id: 000000007832`, `validator-refreshed-at: 2026-07-07T03:37:36-04:00`. At report drafting, the generated file emitted real code for UID0002NM and UID0000YN, and an empty emitter marker for UID0000YL. Post-callback generated freshness is recorded in `## Validator Results`.
- Read-only generated tracker/coverage rows: UID0000YL is queued at `85/91`, combined `88.0`, reconstructable `true`, direct report count `0`; generated memory coverage records UID0000YL as reconstructable, emitting to `AlphaMaskSurface.cpp`, but not currently coded.
- Old-report search over `tools/leaser/Agents` and `executed-b-agent-research` used the required terms from `goal.md`. No prior B007/current report for `TARGET-REPORT-UID:0000YL` was found. Relevant executed reports found and incorporated as historical support were B001 UID0000YK raw default constructor, B009 UID0002NM InitAlphaSurfaceView, B008 UID0000YN DrawFrameWithBlendMode, B006 UID0000YP/UID0004FR IntAlphaSurface destructor/release helper, B003 UID00041R encoded alpha-frame caller route, and B008 UID00006W ItemObjImageLib context. A/C supervisor notes also appeared for UID0000U3, UID0000YL, and AlphaMaskSurface support refreshes; they were treated as historical support, not as a substitute for current MCP evidence.
- Stale Wave2/Wave3 references, if encountered in historical material, were ignored unless confirmed by current docs and current IDA MCP evidence.

## Target

- UID: `0000YL`
- Path: `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`
- Current owner/emitter: `CANONICAL_OWNER:0000HF`, `EMITTER_UIDS:0000HF`
- Current status: reconstructable aggregate with blank formal C++ block
- Pre-callback queue score: `COMPLETION:85`, `CONFIDENCE:91`
- Current implemented target score: `COMPLETION:87`, `CONFIDENCE:92`
- Required report path: `tools/leaser/Agents/Agent-B007/research/0000YL-AlphaMaskSurface-source-quality.md`

## Current Target State

The current target doc now identifies UID0000YL as an AlphaMaskSurface aggregate range with these visible roles:

- Active width/height constructor at `0x00462170`.
- EH-only cleanup chunk at `0x00462230` represented by UID0000YM.
- IntAlphaSurface release helper at `0x00462260` represented by UID0004FR.
- Center and buffer-view accessors at `0x004622d0` and `0x00462300`.
- Clipped-view helper at `0x00462320` represented today as by-item UID0000U3 rather than an exact by-memory source body.
- Exact child UID0002NM `InitAlphaSurfaceView` at `0x004623c0`.
- Rectangular alpha fill at `0x00462520`.
- Radial and elliptic gradient fillers at `0x00462680` and `0x00462870`.

Current formal C++ is the accepted comment-only no-code aggregate marker. This replaces the pre-callback blank block and keeps actual method bodies on exact children or future split children.

The target function table now uses the accepted half-open rows: active constructor `0x00462170-0x00462227`, accessors `0x004622d0-0x004622f7` and `0x00462300-0x00462317`, rectangular fill `0x00462520-0x00462672`, radial gradient `0x00462680-0x0046286b`, and elliptic gradient `0x00462870-0x00462e03`.

## Executive Recommendation

Implemented disposition after supervisor Gate 1 approval:

- UID0000YL target metadata is now `COMPLETION:87` and `CONFIDENCE:92`.
- Preserve `CANONICAL_OWNER:0000HF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HF`, and blank emitter position.
- The formal `RECONSTRUCTION_CPP CODE` block now has the exact no-code aggregate marker in this report.
- Do not emit a standalone AlphaMaskSurface aggregate function body.
- Do not add a `[[CHILDREN]]` insertion marker in this pass. Current generated output already emits exact child/sibling bodies through UID0000HF, and the current target reports no nested children. A future validator-owned split/nesting pass can revisit child insertion if exact child pages are created and registered.
- Current-session MCP facts, xrefs/callers, callee inventory, padding, generated-output state, old-report incorporation, and owner/source-placement rationale were added to the target/support docs at report-level detail.
- No IDA DB rename, type, or comment edits were made.

## Supervisor Active Recheck

Original assignment rechecked from `tools/leaser/Agents/Agent-B007/goal.md`: UID0000YL report-only first pass, B007, required specs header `CHATGPT | 5.5 | xHigh`, report path `tools/leaser/Agents/Agent-B007/research/0000YL-AlphaMaskSurface-source-quality.md`. Current state is the supervisor-approved implementation callback for that same Gate 1 report.

Boundary status for this artifact after implementation callback:

- Supervisor Gate 1 passed for hash `D2798626CDB8E2D58A5F7BCB1F3E94CD1140F24C3FBED1210AA393D7F5208BDE`.
- Edited by-* files were limited to the target, file support, class support, and clipped-view by-item support named in this callback.
- Scoped validators were run only for those four changed by-* files.
- Leases were taken for those four files only for the main edit/validator batch. The first release command later reported `Rejected[No active lease]` for each path, and the current lease report showed no active B007 leases. A second target-only lease was then taken for a small generated-output wording correction on `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`, revalidated, and released successfully.
- No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, registry command, generated-file manual edit, coverage-report edit, supervisor-ledger edit, queue/lock edit, or IDA DB edit was performed.
- IDA MCP evidence remains the accepted live evidence from session `ef57d27f`; target IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` was `ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

## Inference Research Guidance Check

IDA facts used as facts:

- Live MCP function membership, byte ranges, xrefs, callees, vtable bytes, pointer-pattern searches, and name queries from session `ef57d27f`.
- Current generated output state and current by-* metadata as read from disk.

Documentation evidence used as documentation evidence:

- Existing by-* target/support prose and current generated tracker/coverage rows.
- Executed B reports for exact related UIDs. These were used only where current docs and current MCP evidence still support the claim.

Inference kept separate:

- `AlphaMaskSurface` is ranked as the aggregate source owner because the current file/class docs, constructor/accessor/fill behavior, pixel-layout fields, and caller families align under AlphaMaskSurface. The target still needs exact child pages before actual bodies for several subranges can be emitted.
- `IntAlphaSurface` is source-relevant only for the release helper, destination view objects, RTTI/vtable slots, and destructor sibling. It is not the owner for the whole UID0000YL aggregate.
- Image-library callers explain use sites; they do not own the AlphaMaskSurface methods.
- Stale Wave2/Wave3 references were ignored unless current MCP and current docs confirmed the same fact.

## Heuristic / Inference Reanalysis And Validation

UID0000YL passes the reconstructable threshold as a source-level family aggregate, but it does not pass the higher source-quality threshold for a single body. The current range contains multiple entry points and roles with distinct liveness:

- The active constructor and accessors are source-like AlphaMaskSurface member methods but lack exact child pages and formal source names.
- The cleanup at `0x00462230` is compiler EH cleanup and must not be reclassified as handwritten source.
- The release helper at `0x00462260` is already owned by the IntAlphaSurface exact child UID0004FR; duplicating it under UID0000YL would be a source-placement error.
- The view initializer at `0x004623c0` is already resolved by UID0002NM and emits separately.
- DrawFrameWithBlendMode and DrawEncodedAlphaFrame are adjacent siblings outside the target range and must remain outside the aggregate formal block.
- The fill and gradient functions are plausible source methods, but exact by-memory split pages are needed before formal bodies can be safely emitted.

The current blank C++ block is conservative but not ideal. A comment-only formal marker improves generated source readability and prevents future accidental monolithic emission while preserving the target as reconstructable and emitter-routed.

## Evidence Standards Used

- Current IDA MCP evidence outranks historical report claims.
- Exact function boundaries are based on `lookup_funcs` size data and checked against alignment bytes.
- Xref claims are based on `xrefs_to`, not inferred from prose.
- Source ownership requires both behavioral fit and source-placement compatibility; a caller relationship alone is insufficient.
- Formal C++ must be exact final-output insertion text, not body-only pseudocode or decompiler-style scaffolding.
- Report-only recommendations were originally recorded with ledger verification state `proposed`; after this callback, accepted claims in the ledger are updated to `applied`, `already-present`, or `excluded-with-reason` as appropriate.

## Evidence Checked

Live MCP evidence from session `ef57d27f`:

- `idb_list`: active backend worker session `ef57d27f`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`.
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs` command id `20`: resolved active function starts and sizes across `0x00462120-0x004632c0`.
- `xrefs_to` command id `21`: collected direct xrefs to raw default, active constructor, cleanup, release helper, accessors, view helpers, fill/gradient methods, draw siblings, destructor, and vtable.
- `callees` command id `22`: collected outgoing calls for active constructor, accessors, view helpers, fill/gradient methods, draw siblings, and destructor.
- `get_bytes` command id `23`: checked padding/alignment around raw default, constructor end, cleanup/release, view helper split, fill/gradient boundaries, target end, and IntAlphaSurface vtable.
- `find_bytes` command id `24`: checked direct VA/RVA literal pointer patterns for selected raw/live child starts; patterns for `0x00462120`, `0x00462170`, `0x004623c0`, `0x00462520`, `0x00462680`, and `0x00462870` returned zero matches.
- `analyze_function` command ids `30` through `37`: decompiled/reviewed active constructor, center accessor, buffer accessor, clipped-view helper, full/clipped view initializer, rectangular alpha fill, radial gradient fill, and elliptic gradient fill.
- `entity_query` command id `40`: checked current names in `0x00462100-0x00463310`, `0x006112e8-0x00611300`, and alpha-surface regex terms. Current IDB has only raw `sub_` function names in the target range and IntAlphaSurface RTTI names, not source-quality AlphaMaskSurface names.

Non-blocking transport note: an initial plain JSON-RPC initialize attempt without the streamable accept header timed out, then `tools/list`, `idb_list`, and all MCP evidence calls succeeded with the correct streamable response handling. This did not become an MCP availability blocker.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C-0000YL-01 | UID0000YL is a mixed AlphaMaskSurface method-family aggregate, not one callable source function. | 95 | Proof: target formal marker, target evidence notes, by-file support, and by-class support now state aggregate-only/no-monolithic-body. | Target overview and formal C++ rationale | incorporate | applied |
| C-0000YL-02 | Target metadata should move from `85/91` to `87/92`, with owner/emitter/reconstructable unchanged. | 90 | Proof: target header is now `COMPLETION:87`, `CONFIDENCE:92`, with `CANONICAL_OWNER:0000HF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HF`, and blank emitter position preserved; validator `000000007876` confirmed both score updates. | Target metadata and score rationale | incorporate | applied |
| C-0000YL-03 | Formal C++ should become a comment-only no-code aggregate marker and should not include a body or `[[CHILDREN]]` in this pass. | 88 | Proof: target formal block now has the exact three-line UID0000YL comment marker; generated `AlphaMaskSurface.cpp` shows only that marker for UID0000YL and no standalone body. | Target formal `RECONSTRUCTION_CPP CODE` block | incorporate | applied |
| C-0000YL-04 | Active constructor is `0x00462170-0x00462227`, with four code xrefs and AlphaMaskSurface allocation behavior. | 94 | Proof: target function row and by-class method inventory now use `0x00462170-0x00462227`; target evidence records the four xrefs and constructor behavior. | Target function inventory/support class doc | incorporate | applied |
| C-0000YL-05 | `0x00462230-0x00462258` remains EH cleanup, not handwritten source. | 94 | Proof: target retained UID0000YM row and now records the current EH-style xref from `0x005fa593`; UID0000YM support was already same-or-greater detail. | Target inventory/support note | incorporate | applied |
| C-0000YL-06 | `0x00462260-0x00462282` belongs to IntAlphaSurface release helper UID0004FR, not UID0000YL source body. | 94 | Proof: target retained UID0004FR row, added current vtable evidence for `0x006112f0`, and generated output has no duplicate UID0000YL body. UID0004FR and vtable support were already same-or-greater detail. | Target/support docs | incorporate | applied |
| C-0000YL-07 | `0x004622d0-0x004622f7` and `0x00462300-0x00462317` are source-like AlphaMaskSurface accessors needing exact child/split treatment before emission. | 90 | Proof: target function rows and by-class inventory now use the normalized half-open ranges and note caller counts/no aggregate emission. | Target/class method inventory | incorporate | applied |
| C-0000YL-08 | `0x00462320-0x004623b5` is the clipped-view helper with one StaticObjImageLib caller and should remain no-formal/needs exact by-memory promotion before body emission. | 90 | Proof: target evidence, by-class inventory, and by-item support now record current session `ef57d27f`, range `0x00462320-0x004623b5`, caller `0x004dd66a`, and future exact by-memory promotion before formal body emission. | Target and by-item support | incorporate | applied |
| C-0000YL-09 | UID0002NM `0x004623c0-0x00462514` is already source-ready as `InitAlphaSurfaceView`; UID0000YL should not duplicate it. | 92 | Proof: target retained the child row, added generated-output proof that UID0002NM emits separately, and formal UID0000YL marker does not duplicate child code. | Target/support docs | incorporate | applied |
| C-0000YL-10 | Rectangular fill and radial gradient rows should use half-open ends `0x00462672` and `0x0046286b`. | 93 | Proof: target and by-class rows now use `0x00462520-0x00462672` and `0x00462680-0x0046286b`; target evidence records padding at both successor gaps. | Target function inventory and support class doc | incorporate | applied |
| C-0000YL-11 | DrawFrameWithBlendMode and DrawEncodedAlphaFrame are siblings after UID0000YL and should not be merged into the target aggregate. | 93 | Proof: target current-session evidence and generated-output note keep UID0000YN/UID0000YO as sibling outputs outside UID0000YL; by-file support repeats exact child/sibling separate emission. | Target/support docs | incorporate | applied |
| C-0000YL-12 | Current IDB has no source-quality names in the UID0000YL target range; no IDA DB edits are recommended. | 95 | Proof: target evidence now records `entity_query` id `40` and explicitly recommends no IDA DB rename/type/comment edit. | IDA recommendations section/support notes | incorporate | applied |
| C-0000YL-13 | Generated output currently has an empty UID0000YL marker and no monolithic aggregate body. | 92 | Proof: target and by-file support record the pre-callback generated state; post-validator generated output now shows UID0000YL marker comments and no standalone body. | Target/generated-output note | incorporate | applied |
| C-0000YL-14 | Manual coverage/tracker text is not needed for UID0000YL. | 90 | Proof: no manual coverage/tracker edit was made; scoped validators updated generated/projected state through validator-managed side effects only. | Manual tracker section | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- UID0000YL has a stable source placement under `AlphaMaskSurface.cpp`: constructor/accessor/fill/gradient behavior, layout fields, and caller families match AlphaMaskSurface surface/pixel-buffer operations.
- Current MCP confirms exact function starts and sizes for all live subranges, plus explicit padding around most boundaries.
- Exact support work already exists for key children/siblings: UID0004FR release helper, UID0002NM view initializer, UID0000YN draw-frame method, UID0000YO encoded-frame sibling, UID0000YK raw default constructor, and UID0000YM EH cleanup.
- Generated output already proves that exact children can emit through UID0000HF without UID0000YL emitting a duplicate body.
- The target has enough current evidence to improve confidence and replace a blank formal block with a no-code marker, while preserving split-first discipline.

## IDA MCP Facts

- Session: `ef57d27f`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Health: `server_health` reported `ok`
- Analysis status: `auto_analysis_ready:true`
- Hex-Rays: `hexrays_ready:true`
- Strings cache: `strings_cache_ready:true`, size `2067`
- Imagebase: `0x400000`
- Current IDB names: no AlphaMaskSurface source names in `0x00462100-0x00463310`; functions remain raw `sub_` names. IntAlphaSurface RTTI names exist outside the target.
- Vtable bytes at `0x006112ec`: destructor slot `0x00463270`, release slot `0x00462260`, followed by two zero slots. Xrefs to the vtable include raw/default construction, active constructor construction, cleanup, view initialization, and destructor reset.
- Direct pointer pattern checks for selected function starts returned zero matches for both VA and RVA byte patterns.

## Function / Child Inventory

| Range | UID/status | Live IDA status | Role | Report disposition |
|---|---|---|---|---|
| `0x00462120-0x00462161` | UID0000YK sibling support | Not an IDA function, zero xrefs | Raw default-constructor-shaped AlphaMaskSurface initialization | Already documented; do not emit from UID0000YL. |
| `0x00462161-0x00462170` | Padding | Bytes show `0xcc` alignment | Gap before active constructor | Document as padding/alignment if range inventory is updated. |
| `0x00462170-0x00462227` | UID0000YL subrange | Function size `0xb7`; four code xrefs | Active width/height AlphaMaskSurface constructor | Needs exact child/split before body emission; update target range row. |
| `0x00462227-0x00462230` | Padding | `0xcc` alignment | Gap before EH cleanup | Document as padding/alignment. |
| `0x00462230-0x00462258` | UID0000YM child/support | EH chunk in IDA function graph, one EH xref | Compiler cleanup for IntAlphaSurface/AlphaMaskSurface construction path | Keep no-code compiler-generated disposition. |
| `0x00462258-0x00462260` | Padding | `0xcc` alignment | Gap before vtable release helper | Document as padding/alignment. |
| `0x00462260-0x00462282` | UID0004FR exact child/support | Function size `0x22`, vtable data xref | `IntAlphaSurface::ReleaseOwnedPixels` | Already source-ready on UID0004FR; no duplicate in aggregate. |
| `0x00462282-0x004622d0` | Padding | Alignment gap before accessor | Inter-function padding | Document as padding/alignment. |
| `0x004622d0-0x004622f7` | UID0000YL subrange | Function size `0x27`; four code xrefs | Center-point accessor | Source-like, but exact child page needed before body emission. |
| `0x004622f7-0x00462300` | Padding | Gap before buffer accessor | Inter-function padding | Document as padding/alignment. |
| `0x00462300-0x00462317` | UID0000YL subrange | Function size `0x17`; two code xrefs | Buffer/view record accessor | Source-like, but exact child page needed before body emission. |
| `0x00462317-0x00462320` | Padding | Gap before clipped-view helper | Inter-function padding | Document as padding/alignment. |
| `0x00462320-0x004623b5` | UID0000U3 by-item alias | Function size `0x95`; one code xref | Clipped AlphaSurfaceBufferView builder | Needs exact by-memory promotion/split before formal body. |
| `0x004623b5-0x004623c0` | Padding | `0xcc` alignment | Gap before view initializer | Document as padding/alignment. |
| `0x004623c0-0x00462514` | UID0002NM exact child | Function size `0x154`; zero direct xrefs | Full/clipped view initializer | Already source-ready; preserve child formal C++. |
| `0x00462514-0x00462520` | Padding | `0xcc` alignment | Gap before rectangular fill | Document as padding/alignment. |
| `0x00462520-0x00462672` | UID0000YL subrange | Function size `0x152`; five code xrefs | Rectangular alpha apply/fill, modes set/add/subtract | Exact child/split needed before body emission; repair stale end offset. |
| `0x00462672-0x00462680` | Padding | `0xcc` alignment | Gap before radial gradient | Document as padding/alignment. |
| `0x00462680-0x0046286b` | UID0000YL subrange | Function size `0x1eb`; two code xrefs | Radial alpha gradient fill | Exact child/split needed before body emission; repair stale end offset. |
| `0x0046286b-0x00462870` | Padding | `0xcc` alignment | Gap before elliptic gradient | Document as padding/alignment. |
| `0x00462870-0x00462e03` | UID0000YL subrange | Function size `0x593`; one code xref | Elliptic alpha gradient fill | Exact child/split needed before body emission. |
| `0x00462e03-0x00462e10` | Padding after target | `0xcc` alignment | Gap before draw-frame sibling | Confirms target end and sibling separation. |
| `0x00462e10-0x00462f1e` | UID0000YN sibling | Function size `0x10e`; two code xrefs | DrawFrameWithBlendMode | Already source-ready; outside UID0000YL. |
| `0x00462f20-0x00463252` | UID0000YO sibling | Function size `0x332`; nine code xrefs | DrawEncodedAlphaFrame | Sibling outside target; still formal blank due encoded-frame source-shape blockers. |

## Direct Xref / Caller Inventory

| Target | Xref count and sources | Caller/source role |
|---|---|---|
| `0x00462120` raw default | Zero xrefs | Retained/raw constructor-shaped support only. |
| `0x00462170` active constructor | Four code xrefs: `0x004df9a9`, `0x0050442c`, `0x005a288d`, `0x005a2b8e` | LightObjImageLib constructor, MapPane/GameServerConfig initialization, UserPane constructor paths. |
| `0x00462230` EH cleanup | One code xref `0x005fa593` in the view initializer function graph | EH-only cleanup, not a source method. |
| `0x00462260` release helper | One data xref `0x006112f0` | IntAlphaSurface vtable slot. |
| `0x004622d0` center accessor | Four code xrefs: `0x004dd62e`, `0x004df9f6`, `0x005a28b7`, `0x005a2bb8` | StaticObjImageLib/LightObjImageLib/UserPane center calculations. |
| `0x00462300` buffer accessor | Two code xrefs: `0x004bdfb5`, `0x004c3d65` | Software render callbacks obtain pixel/view records. |
| `0x00462320` clipped-view helper | One code xref `0x004dd66a` | StaticObjImageLib render path. |
| `0x004623c0` view initializer | Zero direct xrefs | Source-ready helper with no current direct caller; confidence remains capped below final. |
| `0x00462520` rectangular fill | Five code xrefs: `0x004df9ea`, `0x00509642`, `0x0050aa52`, `0x005a28a8`, `0x005a2ba9` | LightObjImageLib, MapPane render/config path, UserPane paths, plus one raw/anonymous containing function entry. |
| `0x00462680` radial gradient | Two code xrefs: `0x005a28dc`, `0x005a2bdd` | UserPane constructor paths. |
| `0x00462870` elliptic gradient | One code xref `0x004dfa39` | LightObjImageLib constructor path. |
| `0x00462e10` DrawFrameWithBlendMode | Two code xrefs: `0x004dfc42`, `0x004dfcf2` | LightObjImageLib draw mode functions. |
| `0x00462f20` DrawEncodedAlphaFrame | Nine code xrefs, including six modeled image-library callers and three raw caller offsets | Encoded frame blitter sibling outside UID0000YL. |
| `0x006112ec` IntAlphaSurface vtable | Five refs/stores from raw/default construction, active constructor, EH cleanup, view initializer, destructor reset | Supports IntAlphaSurface subobject/view roles but not aggregate ownership. |

## Documentation Evidence And IDA Status

Current target/support docs are broadly directionally correct but under-incorporate current session detail:

- UID0000YL correctly names the aggregate and score blockers but lacks current session facts, exact command-backed xref inventory, generated-output state, no-code marker, and several half-open boundary corrections.
- UID0000HF `by-file/AlphaMaskSurface.md` correctly owns the file/module route and records source-split caveats. It should receive the current no-monolithic-aggregate and generated marker note if this report is accepted.
- UID00000C `by-class/AlphaMaskSurface.md` has the correct field layout and method family but should receive the same boundary/current-MCP refresh.
- UID0001TP and UID0001TQ layout structs already match current offset usage; no metadata change is recommended.
- UID0001XT already documents IntAlphaSurface vtable slots and the source-colocation caveat; no metadata change is recommended.
- UID0000YK, UID0000YM, UID0004FR, UID0002NM, UID0000YN, and UID0000YO already carry the important exact-child/sibling dispositions from prior B reports. This report should not override their ownership or duplicate their formal code.
- `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` currently has no standalone UID0000YL code block beyond an empty emitter marker. This is a generated-state input only; it must not be edited manually.

Live IDA status:

- IDA has no source-quality AlphaMaskSurface function names in the target range.
- The current session confirms the aggregate split, padding, and xrefs.
- No IDA rename/type/comment action is needed or recommended.

Historical reports:

- B001 UID0000YK proved the raw default constructor has no xrefs and should stay a retained constructor-family support target with blank formal C++.
- B009 UID0002NM proved the view initializer source shape and installed an exact formal body on the exact child.
- B008 UID0000YN proved DrawFrameWithBlendMode is a source-ready sibling method.
- B006 UID0000YP/UID0004FR proved the IntAlphaSurface destructor/release-helper split and release-helper source shape.
- B003 UID00041R and B008 UID00006W constrain DrawEncodedAlphaFrame caller/context evidence but do not make UID0000YO or UID0000YL final.

## Ranked Ownership Analysis

1. `AlphaMaskSurface` / UID0000HF owner: best fit. The active constructor, accessors, buffer/view helpers, fill methods, gradients, and draw siblings all operate on the same alpha-mask object fields and support the `NexusTK/render/AlphaMaskSurface.cpp` module route.
2. `by-class/AlphaMaskSurface` / UID00000C class: best class-level support. It should describe the method family and layout, but exact emitting source bodies should stay on exact by-memory children/siblings.
3. `IntAlphaSurface`: valid for UID0004FR release helper, UID0000YP destructor sibling, and destination view initialization. It is not the owner of the whole UID0000YL range.
4. Image-library callers: useful for liveness and parameter-shape evidence only. LightObjImageLib, StaticObjImageLib, UserPane, MapPane, ItemObjImageLib, and related callers do not own the AlphaMaskSurface implementation.
5. Compiler/IDA artifacts: EH cleanup and raw `sub_` naming are not source owners.

## Source Placement

Source placement should remain `NexusTK/render/AlphaMaskSurface.cpp` through UID0000HF. UID0000YL should serve as an aggregate/source-family documentation target, not as a direct source body. Exact source bodies should be placed on:

- Already-resolved exact children/siblings: UID0002NM, UID0000YN, UID0004FR/UID0000YP where applicable.
- Future exact child pages for the active constructor/accessors/fill/gradient functions if the supervisor chooses to split them.
- Existing by-item UID0000U3 can remain support for now, but a future exact by-memory split is the correct route before formal body emission for the clipped-view helper.

The target should not be reclassified to `NO_OWNER`, `IntAlphaSurface`, `Surface`, or an image-library caller. It should not be merged with UID0000YN or UID0000YO.

## Range / Split / Padding / Reclassification Analysis

The assigned range `0x00462170-0x00462e03` is correct as an aggregate interval. Current MCP confirms that the next live sibling begins at `0x00462e10`, with padding `0x00462e03-0x00462e10`.

Split analysis:

- UID0000YL contains several independent source-like functions and should not receive a monolithic function body.
- Half-open function boundaries should be normalized from current MCP sizes during implementation.
- Existing exact child/sibling pages should be preserved; the aggregate should refer to them without duplicating code.
- Future split candidates inside UID0000YL are `0x00462170-0x00462227`, `0x004622d0-0x004622f7`, `0x00462300-0x00462317`, `0x00462320-0x004623b5`, `0x00462520-0x00462672`, `0x00462680-0x0046286b`, and `0x00462870-0x00462e03`.

Padding/alignment observed or inferred from current lookup/bytes:

- `0x00462227-0x00462230`
- `0x00462258-0x00462260`
- `0x00462282-0x004622d0`
- `0x004622f7-0x00462300`
- `0x00462317-0x00462320`
- `0x004623b5-0x004623c0`
- `0x00462514-0x00462520`
- `0x00462672-0x00462680`
- `0x0046286b-0x00462870`
- `0x00462e03-0x00462e10`

No reclassification to non-reconstructable is recommended. The aggregate is source-level reconstructable as documentation/source-family context, but its formal block should be a no-code marker until exact child pages own the actual function bodies.

## Negative Evidence Summary

- No current IDA source names support inserting polished C++ names directly from the database.
- No direct xrefs reach the raw default constructor `0x00462120`; it should not be promoted through UID0000YL.
- No direct xrefs reach `0x004623c0`; UID0002NM remains source-ready but not final-confidence.
- The aggregate contains compiler-generated EH cleanup and IntAlphaSurface helper code, proving a single AlphaMaskSurface function body would be wrong.
- Existing generated output has no standalone UID0000YL body; forcing one would risk duplicate or misplaced code.
- DrawFrameWithBlendMode and DrawEncodedAlphaFrame are outside the target range and already have distinct docs/dispositions.
- A `[[CHILDREN]]` marker is not recommended in this pass because current nesting is absent and direct child/sibling emission is already handled elsewhere by the generator.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are recommended or performed. Do not rename raw IDA functions, force new function definitions, change types, or add IDA comments for this UID0000YL implementation.

Source-facing names can remain descriptive in docs:

- AlphaMaskSurface active constructor
- AlphaMaskSurface center-point accessor
- AlphaMaskSurface buffer-view accessor
- BuildClippedAlphaSurfaceView
- InitAlphaSurfaceView
- ApplyRectAlpha
- FillRadialGradient
- FillEllipticGradient

These are documentation/source-facing names only. Final C++ must not use raw `sub_`, `func_`, `dword_`, or anonymous IDA-style names.

## First-Draft C++ Recommendation

Recommended exact target formal block if the supervisor accepts this report:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0000YL is the AlphaMaskSurface method-family aggregate for 0x00462170-0x00462e03.
// This range contains multiple independent methods, compiler cleanup, child-owned helpers, and padding.
// Do not emit a monolithic body here; exact source bodies must live on exact child pages or future split children.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Disposition: no standalone helper body, no pasted child code, no decompiler-derived aggregate function, no `[[CHILDREN]]` insertion in this pass, and no raw IDA names in the formal marker.

## Final Recommendation

UID0000YL has been improved as a documented aggregate only. The score is now `87/92`, ownership/emission is unchanged, the exact no-code marker is inserted, and the current MCP inventory/range/split facts are incorporated into the target and scoped support docs. No monolithic AlphaMaskSurface aggregate body was created or emitted.

## Recommended Target Doc Changes

Implementation callback applied to `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`:

- Set `COMPLETION:87` and `CONFIDENCE:92`.
- Preserved `CANONICAL_OWNER:0000HF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HF`, and blank emitter position.
- Replaced the blank formal C++ block with the exact no-code marker from `## First-Draft C++ Recommendation`.
- Added current MCP session facts: session `ef57d27f`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `server_health ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Added the function/child inventory, caller/xref inventory, outgoing callee summary, vtable support facts, direct pointer-pattern zero-hit note, generated-output state, and no-IDA-edit disposition.
- Normalized half-open function rows for the active constructor/accessors and stale fill/gradient rows.
- Explained that UID0000YL is a method-family aggregate and that source-ready bodies should remain on exact children/siblings or future split children.
- Preserved the raw default constructor, EH cleanup, release helper, view initializer, draw-frame, and encoded-frame sibling dispositions without merging or duplicating them.

## Recommended Support Doc Changes

Implementation callback support handling:

- `by-file/AlphaMaskSurface.md`: applied current-session note that UID0000YL is aggregate-only/no-monolithic-body, generated output had UID0000YL marker-only state before callback, exact children/siblings emit separately, and future exact splits are needed for constructor/accessors/fill/gradients before formal bodies.
- `by-class/AlphaMaskSurface.md`: applied method inventory refresh with current half-open ranges, xrefs/callers, and no-code aggregate disposition.
- `by-item/BuildClippedAlphaSurfaceView_00462320.md`: applied current-session confirmation of range `0x00462320-0x004623b5`, one StaticObjImageLib caller at `0x004dd66a`, and future exact by-memory promotion before formal body emission.
- `by-type/by-struct/AlphaMaskSurfaceLayout.md` and `by-type/by-struct/AlphaSurfaceBufferView.md`: read/check only; current text already had same-or-greater layout/use facts and no contradiction was found.
- `by-type/by-vtable/IntAlphaSurfaceVtable.md`, UID0000YK, UID0000YM, UID0004FR, UID0002NM, UID0000YN, and UID0000YO: read/check only; current text already had same-or-greater formal/no-code dispositions and no contradiction was found.

Generated reports and manual coverage/tracker files were not manually edited. Validator-owned generated files refreshed only through scoped validators after by-* edits.

## Score And Metadata Recommendation

Before:

- `COMPLETION:85`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000HF`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000HF`

Applied after callback:

- `COMPLETION:87`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000HF`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000HF`

Rationale: current MCP evidence resolves the current aggregate inventory, xrefs, padding, generated-output state, and several stale boundary details. That warrants a modest completion/confidence increase and a formal no-code marker. The score should remain below final/source-ready because several live AlphaMaskSurface methods still lack exact child pages and formal source-quality bodies, the view-initializer caller route is still zero-direct-xref, and DrawEncodedAlphaFrame remains an adjacent formal-blank sibling with source-type blockers.

## Open Questions With Attempted Resolution

- Should UID0000YL emit a monolithic body? Resolved no. The range contains multiple functions, compiler cleanup, existing exact children, and padding.
- Should UID0000YL become non-reconstructable? Resolved no. It is a source-level AlphaMaskSurface method-family aggregate with valid owner/emitter routing.
- Should it become IntAlphaSurface-owned? Resolved no. IntAlphaSurface is relevant to the release helper and view destination object only.
- Should it include `[[CHILDREN]]`? Resolved no for this pass. Current generated output already emits exact children directly and current target has no nested child relation.
- Should raw default constructor evidence change the target formal body? Resolved no. UID0000YK remains separate retained/raw support with zero xrefs.
- Can the fill/gradient functions be emitted now from UID0000YL? Resolved no. They need exact by-memory split pages or child ownership before formal bodies.
- Are manual tracker/coverage edits needed? Resolved no. Generated tracker/coverage are validator-owned and already reflect current queue status.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

None needed. No manual coverage or tracker edits are recommended for UID0000YL. Generated tracker/coverage files are validator-owned and were not manually edited during this callback.

## Follow-Up Actions

- Supervisor Gate 2 verification of the callback implementation.
- Supervisor may execute the report only after Gate 2 verification.
- Future exact split pages remain useful for constructor/accessor/fill/gradient bodies if the project chooses to emit those functions.
- Agent-B007 did not run and must not run `execute_report`, lifecycle/archive commands, manual report moves, report registry commands, generated/coverage manual edits, or supervisor-ledger edits.

## Confidence

- Recommendation confidence: 90. Current MCP evidence is strong and current docs/generator state align with the aggregate/no-code-marker recommendation.
- Score confidence: 88. `87/92` is a conservative improvement; higher completion should wait for exact child pages and formal bodies for constructor/accessors/fill/gradient functions.
- Remaining uncertainty: exact final source names and signatures for the constructor/accessors/fill/gradient methods, the future split/nesting model if the project creates exact child pages, and any later source placement for DrawEncodedAlphaFrame outside UID0000YL.

## Validator Results

Scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | command_id | command_timestamp | Exit code | Result |
|---|---|---|---|---:|---|
| `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md` | `python .\tools\validator.py --mode file --file by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md --apply --queue-timeout 240` | `000000007876` | `2026-07-07T14:39:32-04:00` | 0 | `ok: 1`; completion update `87`; confidence update `92`; generated refresh deferred. |
| `by-file/AlphaMaskSurface.md` | `python .\tools\validator.py --mode file --file by-file/AlphaMaskSurface.md --apply --queue-timeout 240` | `000000007877` | `2026-07-07T14:39:37-04:00` | 0 | `ok: 1`; generated refresh deferred. |
| `by-class/AlphaMaskSurface.md` | `python .\tools\validator.py --mode file --file by-class/AlphaMaskSurface.md --apply --queue-timeout 240` | `000000007879` | `2026-07-07T14:39:52-04:00` | 0 | `ok: 1`; generated refresh deferred. |
| `by-item/BuildClippedAlphaSurfaceView_00462320.md` | `python .\tools\validator.py --mode file --file by-item/BuildClippedAlphaSurfaceView_00462320.md --apply --queue-timeout 240` | `000000007881` | `2026-07-07T14:40:00-04:00` | 0 | `ok: 1`; generated refresh deferred. |
| `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md` | `python .\tools\validator.py --mode file --file by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md --apply --queue-timeout 240` | `000000007887` | `2026-07-07T14:46:31-04:00` | 0 | `ok: 1`; target revalidation after generated-state wording correction; generated refresh deferred. |

Generated freshness check after validators:

- `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` read-only header after final validation: `validator-command-id: 000000007887`, `validator-refreshed-at: 2026-07-07T14:46:31-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- The generated file now shows UID0000YL at `Completion:87 | Confidence:92` with the exact comment-only marker and no standalone aggregate body, followed by exact child/sibling output such as UID0002NM and UID0000YN.
- Header command `000000007887` is equal/newer than all scoped validator commands from this callback (`000000007876`, `000000007877`, `000000007879`, `000000007881`, `000000007887`).

Forbidden commands not run: `execute_report`, execute dry-run/probing/status variants, lifecycle/archive commands, manual report moves, registry lifecycle commands, broad validators, or validator lifecycle commands.

## Changed Files

Manual edits:

- `tools/leaser/Agents/Agent-B007/research/0000YL-AlphaMaskSurface-source-quality.md`
- `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`
- `by-file/AlphaMaskSurface.md`
- `by-class/AlphaMaskSurface.md`
- `by-item/BuildClippedAlphaSurfaceView_00462320.md`

Validator-managed/generated side effects observed from scoped validators:

- `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` refreshed through validator-generated output, not manual edit.
- Projected stats/autogen registry updates were reported by scoped validators, including validator-managed updates to `project-level/-auto-completion-stats.md` and `tools/validator.ini`. No generated, coverage, validator-state, queue/lock, lifecycle, archive, or supervisor-ledger file was manually edited.

## Implementation Tracking Checklist

- [x] Read current B007 goal and project-level `ntk-b-agent-workflow` instructions for this assignment.
- [x] Inspected target/support docs and current generated output as read-only evidence.
- [x] Searched old reports with the required UID/address/name terms and incorporated relevant B-report findings.
- [x] Collected live IDA MCP evidence from session `ef57d27f`.
- [x] Produced report-only recommendation with ledger verification states set to `proposed`.
- [x] Supervisor Gate 1 audit completed for hash `D2798626CDB8E2D58A5F7BCB1F3E94CD1140F24C3FBED1210AA393D7F5208BDE`.
- [x] Implementation callback received.
- [x] Leased `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`, `by-file/AlphaMaskSurface.md`, `by-class/AlphaMaskSurface.md`, and `by-item/BuildClippedAlphaSurfaceView_00462320.md` immediately before editing.
- [x] Applied target metadata update, exact no-code marker, current MCP facts, xref/caller inventory, range/padding corrections, generated-output note, and split/source-placement rationale.
- [x] Edited only support docs that lacked same-or-greater accepted detail: `by-file/AlphaMaskSurface.md`, `by-class/AlphaMaskSurface.md`, and `by-item/BuildClippedAlphaSurfaceView_00462320.md`.
- [x] Read/check-only support pages with same-or-greater detail left unchanged: `AlphaMaskSurfaceLayout`, `AlphaSurfaceBufferView`, `IntAlphaSurfaceVtable`, UID0000YK, UID0000YM, UID0004FR, UID0002NM, UID0000YN, and UID0000YO.
- [x] Ran scoped validators only for changed by-* files from `source-3/project-documentation`; the four main file validators and final target revalidation all returned exit code 0 and `ok: 1`.
- [x] Rechecked generated `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` read-only after validation; final header is `000000007887` / `2026-07-07T14:46:31-04:00`, UID0000YL emits only the accepted marker, and no standalone aggregate body is present.
- [x] Released/cleared leases after the edit/validator batch: the first unlease command reported `Rejected[No active lease]` for all four paths and the current lease report showed no active B007 leases; the later target-only lease released successfully.
- [x] Updated this report's Claim And Incorporation Ledger with `applied` and `excluded-with-reason` proof after implementation.
- [x] Updated this checklist after callback implementation.
- [x] Ready to return `READY_FOR_SUPERVISOR_EXECUTE`; no `execute_report`, lifecycle/archive command, manual report move, generated manual edit, coverage edit, supervisor-ledger edit, validator-state edit, queue/lock edit, or IDA DB edit was performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000007889","destination_path":"executed-b-agent-research/B007/0000YL-AlphaMaskSurface-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000YL-AlphaMaskSurface-source-quality.md","timestamp":"2026-07-07T15:05:50-04:00","uid":"0000YL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
