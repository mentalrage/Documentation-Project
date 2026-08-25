** TARGET-REPORT-UID:0003O0 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0003O0 SnowingLayerPane Constructor Empty-Emitter Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: accept the independently read-back [UID:0003O0] source-ready `92/94` exact constructor implementation while preserving direct owner/emitter [UID:0000DC] `SnowingLayerPane`.
- Final disposition: one no-argument `SnowingLayerPane::SnowingLayerPane()` definition for `[0x005c1bd0,0x005c1c7e)`. Source-visible work is limited to three inherited animation assignments, initialization of 200 `SnowParticleEntry` records, and inherited `m_drawOnTarget = true`; base construction, three vptr writes, EH/cookie state, ABI return, and cleanup funclets are compiler output.
- Required action: supervisor Gate 1 passed exact report SHA `EB58D1E3792F9E2F79CD74E0EC480BCAECD18CCD081002ECA769A2442F51A62C`; B005 applied and read back C3O0-01 through C3O0-27 and C3O0-30. Supervisor Gate 2A and C3O0-29 Gate 2B are now complete and recorded below. C3O0-28 manual coverage and supervisor lifecycle execution remain pending.
- Confidence: very strong for bytes, bounds, ABI, caller/allocation, object extent, base call, vptrs, field widths and values, particle count/stride/layout, helper contract, direct-target field, compiler cleanup, ownership, emitter route, and executable source shape; strong inferred confidence for private lexical names and the selected current source-family route.

## Supporting Research

- Assignment-time queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`, where UID0003O0 was listed at `86/88`, combined `87.0`, with zero direct, additional, or total reports.
- Historical assignment-time generated source under validator command `000000017074` contained one UID0003O0 empty-emitter marker and no UID0003O0 constructor body. The revoked callback first produced an unverified body checkpoint. B005's completed-callback checkpoint was command `000000017124`, SHA256 `9F6758E7B2254352F0FFA74B66EB418416497AD2EB8A0B88928FF4AE78B73854`, 18,095 bytes, 445 lines, with one UID occurrence, one constructor definition, and zero empty markers. A later shared supervisor foreground refresh advanced the current observed checkpoint to command `000000017138`, timestamp `2026-07-24T08:39:16-04:00`, SHA256 `5EC92EE3819D0BDC93C154908A6899412421D31BA74E5417CA9DB0B2E03FAE0E`, 18,097 bytes, 445 lines, with the same one-body/zero-empty result. C3O0-27 is `APPLIED_VERIFIED`; later unrelated validator commands may advance the shared header/hash while preserving that semantic readback, and B005 never edited the generated file.
- Matching archived research was checked rather than copied: B012 UID0001O0 Snowing method-index research, B001 UID0001O1 Snowing/Swallow source placement, B005 UID0002Z9 Snowing vtable data, B003 UID0003O2 Snow frame-change behavior, B001 UID0003PG Weather constructor, B003 UID0003PI Rain constructor, and the accepted UID0003PJ/UID0003PK Rain layout/render closures.
- Inherited conclusions were classified explicitly. Accepted: direct Snowing class ownership, the Weather source-family route, three Snowing vtable views, the exact 200-record particle layout, and inherited Weather frame/count/interval fields. Revised: the constructor no longer has unresolved helper, field, type, packed-state, object-size, or C++ blockers. Rejected: generic visibility/enabled meaning for `+0xf6`, a monolithic packed integer source member at `+0xf8`, a separate particle table allocation, hand-authored vtable stores, and a forced dedicated `SnowingLayerPane.cpp` route.
- Current live IDA MCP was mandatory and available throughout. Session `supervisor_gate2b_0002OT_20260723` uses `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID 3368, `is_analyzing:false`, server health `ok`, Hex-Rays ready, and strings cache ready. `auto_analysis_ready:false` did not represent a busy worker: all required lookup, decompile, disassembly, xref, byte, type, entity, signature, and search calls completed successfully.

## Target

- Target UID: `0003O0`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0003O0] `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md`, exact Snowing constructor and sole report target.
- Target path: `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md`.
- Assignment-time source queue/report row: not-covered reconstructable by-memory row with zero report coverage and a generated empty emitter. The revoked callback's partial validator side effect does not change the report-lifecycle classification or establish accepted report coverage.
- Current supervisor classification: source-bearing reconstructable method child under [UID:0000DC] `SnowingLayerPane`.
- Assignment-time/pre-callback baseline: target `86/88`, class parent [UID:0000DC] `86/88`, direct target owner/emitter `0000DC`, class source-family owner/emitter [UID:0000P8].
- Current callback readback: target UID0003O0 is `92/94`, SHA256 `3419CC65316840229412A4736498D3A35D8ABF389F1BFF929CB0E53137443F6D`, 15,686 bytes, 143 lines, preserving scoped validator command `000000017085`; class UID0000DC is `90/92`, SHA256 `8C62752D5D562F632B3D1863E19872D2B9C15A1488371292BA06524DCEDC279E`, 22,219 bytes, 156 lines, validated by command `000000017101`. B005 verified both claim by claim after fresh Gate 1, and the supervisor independently passed Gate 2A across all ten ordinary destinations plus generated output.

## Current Target State

- Assignment-time/pre-callback target baseline: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank optional position, blank formal C++, `Nested:4`.
- `APPLIED_VERIFIED` current target state: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000DC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DC`, blank optional position, exact `SnowingLayerPane::SnowingLayerPane()` formal, and `Nested:0`; SHA256 `3419CC65316840229412A4736498D3A35D8ABF389F1BFF929CB0E53137443F6D`, 15,686 bytes, 143 lines. B005 independently reread every C3O0-01..19 destination fact after fresh Gate 1; the preserved scoped validator checkpoint is command `000000017085`, exit `0`, `ok:1`.
- `APPLIED_VERIFIED` current class state: [UID:0000DC] has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000P8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P8`; SHA256 `8C62752D5D562F632B3D1863E19872D2B9C15A1488371292BA06524DCEDC279E`, 22,219 bytes, 156 lines, scoped validator command `000000017101`, exit `0`, `ok:1`. The callback preserved all constructor/layout evidence and historicalized the one stale randomize-field/source blocker without duplicating a child body.
- Assignment-time and current callback-verified owner/emitter/reconstructable routes are unchanged and correct. The exact constructor belongs to the concrete Snowing class, not MapPane, the broad aggregates, the rectangle helper, vtable data, or a file-only owner.
- Assignment-time C++/emitter state was blank target formal plus one generated empty marker. Current callback state is `APPLIED_VERIFIED`: the target contains the exact constructor formal; B005 checkpoint `000000017124`, shared checkpoint `000000017138`, and supervisor foreground checkpoint `000000017156` each contain one UID0003O0 constructor body and zero UID0003O0 empty markers. Supervisor Gate 2A independently passed.
- Assignment-time blockers resolved by this report:
  - `0x004b7c50` is current typed shared helper `void __cdecl InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)` and has 1,731 code xrefs;
  - `0x00c80504` is not one opaque Snow state integer: little-endian bytes `04 05 c8 00` are inherited signed byte `m_currentFrame = 4`, inherited signed byte `m_frameCount = 5`, and inherited signed short `m_timerInterval = 200`;
  - the derived table is exactly `SnowParticleEntry m_snowParticles[200]` at `+0x10c`, each entry is a 16-byte `RectBounds`, one-byte `type`, and three bytes of natural tail padding;
  - `+0xf6` is inherited Pane bool-like `m_drawOnTarget`, separate from visibility at `+0xb4`;
  - current canonical source/header placement is `NexusTK/map/WeatherLayerPane.cpp` plus `WeatherLayerPane.h`, while the dedicated Snowing file is preserved as historical provenance only.
- Related docs checked: UID0000DC, UID0000G1, UID0000P8, UID0000NR, UID0001O0, UID0001O1, UID0001WJ, UID0002Z9, UID0003O1, UID0003O2, UID0003O3, UID0003PG, UID0003PH, UID0003PI, UID0003PJ, UID0003PK, UID0001O2, MapPane class/file, current generated source, research tracker, manual coverage, and matching executed reports.
- Current artifact/lifecycle status: the prior callback stop remains historical. Fresh Gate 1 passed SHA `EB58D1E3792F9E2F79CD74E0EC480BCAECD18CCD081002ECA769A2442F51A62C`, after which B005 verified the preserved target/class, repaired only needed support docs, ran ten serial scoped validators, released every lease, and completed generated readback. C3O0-01..27 and C3O0-30 are `APPLIED_VERIFIED`; supervisor Gate 2A passed; C3O0-29 supervisor IDA is `APPLIED_VERIFIED`/`NO_CHANGE_VERIFIED` item by item. C3O0-28 manual coverage and lifecycle execution remain pending. B005 itself made no IDA, coverage, generated/tracker, audit/supervisor/goal/validator-state, or lifecycle mutation.

## Executive Recommendation

- Keep [UID:0000DC] as direct owner/emitter and [UID:0000P8] as the current canonical source-family route.
- Populate only UID0003O0's formal with the exact qualified constructor. Do not put method code in class/file routers, broad aggregates, the vtable page, or the historical dedicated file candidate.
- Record the exact Snow object layout: `WeatherLayerPane` prefix `0x10c`, followed by `m_snowParticles[200]` with `0x14` stride, giving exact object size `0x10ac`.
- Use source-facing names `m_currentFrame`, `m_frameCount`, `m_timerInterval`, `m_snowParticles`, `bounds`, `type`, and `m_drawOnTarget`. These are either cross-method exact roles or highest-probability human names; no final source should expose `sub_5C1BD0`, `_DWORD *`, raw offsets, `v2`, `v3`, or manual vtable labels.
- Preserve the callback-verified target at `92/94`, Snowing class at `90/92`, and completed WeatherLayerDataLayouts promotion at `92/93`; all other accepted support metadata remains unchanged.
- No target blocker remains. Original private lexical spelling and exact historical physical file split are irrecoverable provenance limits, not reasons to leave code blank or use IDA names.

## Supervisor Active Recheck

- At assignment time, the supervisor selected the next lowest-score not-covered reconstructable by-memory empty emitter, UID0003O0, as a fresh report-only task.
- No split repair is required before the constructor can emit. `[0x005c1bd0,0x005c1c7e)` is one exact modeled function, and adjacent bytes are compiler alignment.
- The broad UID0001O0 and UID0001O1 pages remain non-emitting indexes. Exact source-bearing Snowing children already exist, so this report repairs the constructor child rather than widening or repurposing either aggregate.
- Duplicate screening found no active B005 report at the assigned path and no direct/additional executed report for UID0003O0. Older family reports are support evidence, not substitutes for this target report.

## Inference Research Guidance Check

- Binary facts control range, behavior, data width, object extent, caller route, and helper ABI. Existing docs control accepted project owner/emitter and source-family conventions only where current IDA agrees.
- Inference is used for private lexical spelling and human source organization, not to change observed behavior. Every inferred name is ranked against callers, sibling constructors, later consumers, accepted project naming, and C++03 source plausibility.
- Existing statements that blank C++ is required until all original names or the historical `.cpp` split are proven were treated as stale assumptions. The workflow requires a best defensible human name after exhaustive checking, not retention of decompiler labels.
- The source shape follows `by-structure.md`: exact method child emits the body, the class page routes children, the file page owns source placement, vtable bytes remain compiler-generated, and broad mixed aggregates do not duplicate source.
- Historical Wave2/Wave3 mentions occur in older file/source-placement docs. They were ignored as stale workflow/source evidence. Current IDA, current by-* docs, current generated routes, and current skill rules control this report.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best resolution | Classification |
| --- | --- | --- | --- |
| `sub_5C1BD0` identity | Snow RTTI/vtables, three Snow vptr stores, direct class child, MapPane weather selector 2, exact object allocation, sibling constructors | source `SnowingLayerPane::SnowingLayerPane()`; IDA-safe name `SnowingLayerPane__SnowingLayerPane` | class/ABI exact; lexical spelling conventional |
| `_DWORD *__thiscall(_DWORD *this)` | ECX receiver, no stack args, EAX=`this`, caller `new` lowering | no-argument C++ constructor; IDA prototype may return `SnowingLayerPane *` for decompilation | exact ABI/source distinction |
| Base call | sole first semantic call is current `WeatherLayerPane__Constructor` | implicit default `WeatherLayerPane()` construction | exact |
| Three vptr stores | decorated primary and two adjusted Snowing vtables, matching inherited EventHandler/TimerHandler facets | compiler output from class inheritance; omit from source body | exact compiler/source distinction |
| Packed `0x00c80504` | little-endian bytes, Weather layout, Weather timer, Rain constructor, Snow timer/OnFrameChanged consumers | three inherited assignments: frame 4, count 5, interval 200 ms | field roles/types exact; assignment coalescing compiler optimization |
| `+0x10c` table | base extent `0x10c`, loop start, 20-byte stride, 200 iterations, caller allocation `0x10ac` | `SnowParticleEntry m_snowParticles[200]` | exact layout; type/member spelling inferred/high probability |
| Particle entry | helper writes four `int` bounds fields at `+0..+0xf`; target clears byte `+0x10`; stride leaves `+0x11..+0x13` untouched | `RectBounds bounds; unsigned char type;` with natural 3-byte tail padding | exact fields/widths; source type name inferred/high probability |
| Initial bounds | exact helper arguments `0, 800, 8, 808` | call `InitRectBounds(&m_snowParticles[i].bounds, 0, 800, 8, 808)` | exact |
| Particle initialization style | only bounds and type are written; padding is untouched | explicit helper call plus `type = 0`; reject value-initialization/memset | exact execution constraint |
| `+0xf6 = 1` | Pane default clear, Rain/Snow/Swallow writers, unique Layer consumer, separate visibility byte | `m_drawOnTarget = true` | behavior exact; lexical spelling best inference |
| EH/cleanup | target SEH state begins after base call; cleanup funclet tail-jumps Pane destructor; caller has three allocation-delete funclets | no explicit try/catch, destructor call, or delete in constructor source | exact compiler/source distinction |
| Object size | MapPane branch allocates `0x10ac`; base `0x10c` plus 200*`0x14` equals `0x10ac` | `sizeof(SnowingLayerPane)==0x10ac` with no trailing derived fields | exact |
| Rectangle helper name | current IDA and UID00015S use `InitRectBounds`; helper has exact typed no-callee body and broad fan-in | preserve `InitRectBounds`; reject stale `SetRect` alias for this new body | exact current source convention |
| Source route | current class/file emitter chain, contiguous Weather/Rain/Snow/Swallow code+RTTI+data, current generated destination, no source-path string | current canonical `WeatherLayerPane.cpp`/`.h`; dedicated Snow file remains historical only | project route strong; original file provenance unproven |
| Header/type order | target body needs complete class fields and shared geometry helper | `RectBounds`/helper declaration, `SnowParticleEntry`, `WeatherLayerPane`, `SnowingLayerPane`, then qualified constructor | exact dependency requirement |
| Empty emitter | assignment-time target was reconstructable with valid owner/emitter but blank formal; the fresh callback preserves the exact formal and generated command `000000017124` has one body/zero empty markers | keep exact child body and no-duplicate router/data support | resolved and `APPLIED_VERIFIED`; supervisor Gate 2A independently passed |

Rejected alternatives:

- One opaque `int m_snowState = 0x00c80504`: later signed byte/byte/short consumers disprove this source shape.
- `m_isVisible`, `m_enabled`, or `m_ready` for `+0xf6`: Pane `+0xb4` is visibility; the unique `+0xf6` reader gates generic `OnPaint` in favor of direct-target weather rendering.
- Heap or pointer particle storage: allocation size includes the complete 4,000-byte inline array and all accesses are `this`-relative.
- `memset` or `SnowParticleEntry()` value initialization: binary leaves three tail-padding bytes per record untouched.
- `SetRect` in the new constructor: current accepted shared helper/IDA name is `InitRectBounds`; `SetRect` is an older descriptive alias in Snow generated code.
- Explicit base call, vptr assignments, EAX return, SEH, cookie, or cleanup calls: all are compiler lowering.
- MapPane ownership: MapPane selects and owns the active instance, but caller reachability is not method ownership.
- Vtable/aggregate ownership: these are compiler-data and migration indexes, not authored constructor containers.
- Forced `SnowingLayerPane.cpp`: no PDB/source-path proof supersedes the accepted combined Weather source route.

## Evidence Standards Used

- Direct IDA MCP evidence: `server_health`, `idb_list`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xref_query`, `get_bytes`, `find_bytes`, `find`, `find_regex`, `entity_query`, `type_inspect`, and `make_signature_for_function`.
- Raw-byte evidence: exact target and alignment slices were read through MCP and independently matched against the local PE slice.
- Cross-function evidence: MapPane allocation/call/delete lowering, Weather constructor/timer, Snow frame-change/update/render consumers, Pane direct-target consumer, sibling Rain/Swallow constructors, and Snow vtable data.
- Documentation evidence: research-time target/support by-* files, generated source/tracker/coverage, matching archived reports, historical revoked-callback checkpoints, and current callback-verified target/class/support/generated readbacks recorded under exact hashes below.
- Negative evidence: no second target caller, no exclusive-end xref, no VA/RVA/raw-offset pointer hit, no duplicate signature, no source-path/PDB string, no target-local global/table/string, no alternate vtable family, and no extra object tail.
- Confidence is below final-audit `95+` because original private spellings and exact historical file partition are not symbol-proven and no full compiler codegen-match rebuild is claimed. Those limits do not justify blank source.

## Evidence Checked

- Live MCP health/session: active `supervisor_gate2b_0002OT_20260723`; IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; server health `ok`; worker not analyzing; all queries responsive.
- Target `analyze_function` and `disasm`: 57 instructions, seven IDA blocks including compiler funclets, exact source body and cleanup route.
- Caller `0x0050db50`: decompile/disasm, four incoming calls, selector branches, allocations `0x10c`, `0x10ac`, and `0x16c`, constructor calls, MapPane storage, virtual setup call, and three allocation-delete funclets.
- Helper `0x004b7c50`: current name/type/comment, exact four-field writes, no callees, and 1,731 code xrefs.
- Sibling/current functions: `WeatherLayerPane__Constructor`, `WeatherLayerPane__OnTimer`, `SnowingLayerPane__OnFrameChanged`, Snow update/render methods, Rain constructor, and Swallow constructor/core.
- Types: current `Pane` is exact size `0xf8`; `RainingLayerPane` is exact UDT size `0x10c` with inherited Weather tail; `RectBounds` is exact size `0x10`; `WeatherLayerPane` and `SnowingLayerPane` are current forward-only names; `SnowParticleEntry` is absent.
- RTTI/names: three decorated Snowing vtables and matching RTTI names are present; no conflicting `SnowingLayerPane__SnowingLayerPane` or `SnowingLayerPane__Constructor` function exists.
- Exact target bytes: 174 bytes at `[0x005c1bd0,0x005c1c7e)`, SHA256 `F328CB6C86DA1506F441912CEDA6919E2DD1374623CAC3397E94F60D7953D01D`.
- Direct PE cross-check: input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, RVA `0x001c1bd0`, raw file offset `0x001c0fd0`, 174-byte SHA256 identical to MCP.
- Alignment bytes: nine `0xcc` bytes at `[0x005c1bc7,0x005c1bd0)`, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; two `0xcc` bytes at `[0x005c1c7e,0x005c1c80)`, SHA256 `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2`.
- Signature/searches: unique entry signature `55 8B EC 6A FF 68 4B BE 60 00`; a longer 16-byte prefix also matches only `0x005c1bd0`; target VA/RVA/raw-offset byte patterns return zero; each Snowing vtable immediate occurs only at its constructor store.
- String search returns only RTTI strings `.?AVWeatherLayerPane@@` and `.?AVSnowingLayerPane@@`; no `.cpp` or `.pdb` path survived.
- Exact conversion evidence:
  - `python .\tools\int_convert.py --text 0xae --size 2 --single` -> decimal 174, hexadecimal `0xae` (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0x10c --single` -> decimal 268 (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0x10ac --single` -> decimal 4268 (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0xc8 --size 2 --single` -> decimal 200 (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0x14 --single` -> decimal 20 (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 4000 --single` -> hexadecimal `0xfa0` (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0x320 --single` -> decimal 800 and `python .\tools\int_convert.py --text 0x328 --single` -> decimal 808 (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0x00c80504 --size 4 --single` -> decimal 13108484, bytes `04 05 c8 00` (Verified with int_convert.py).
- During the initial report-only pass, no validator or lifecycle command was run. The accepted ordinary-document callback later ran ten serial scoped validators and completed generated readback as recorded in `## Validator Results`; B005 ran no report lifecycle command.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3O0-01 | 0003O0 | Exact function range is `[0x005c1bd0,0x005c1c7e)`, 174 bytes, SHA256 `F328...01D`. | Very high | MCP function/bytes/disasm plus PE slice | target Address Range/Evidence/Item Summary | incorporate | APPLIED_VERIFIED |
| C3O0-02 | 0003O0 | This is a no-argument `__thiscall` constructor; EAX `this` return is ABI only. | Very high | disasm, caller ECX setup, `retn` | target Runtime/ABI and formal | incorporate | APPLIED_VERIFIED |
| C3O0-03 | 0003O0 | Sole constructor xref is `0x0050dc17`; caller allocates exactly `0x10ac` and stores result as active weather pane. | Very high | xref query, caller decompile/disasm | target Caller/Reachability | incorporate | APPLIED_VERIFIED |
| C3O0-04 | 0003O0 | `0x005c1bfb` is implicit default `WeatherLayerPane` base construction. | Very high | current named/typed base function and three-derived caller family | target Behavior/ABI | incorporate | APPLIED_VERIFIED |
| C3O0-05 | 0003O0 | Stores to `0x006312b0`, `0x00631304`, and `0x00631334` are compiler primary/adjusted vptr transitions. | Very high | decorated names and unique constructor-store xrefs | target Vptr/Compiler Mechanics | incorporate | APPLIED_VERIFIED |
| C3O0-06 | 0003O0 | Packed `04 05 c8 00` is `m_currentFrame=4`, `m_frameCount=5`, `m_timerInterval=200`. | Very high | int conversion, Weather layout/timer, Snow consumers | target State Initialization/formal | incorporate | APPLIED_VERIFIED |
| C3O0-07 | 0003O0 | `Pane+0xf6` is inherited `m_drawOnTarget`, not visibility, readiness, or padding. | Very high behavior/high name | writer/reader family and separate `+0xb4` visibility | target Behavior/formal/history | incorporate | APPLIED_VERIFIED |
| C3O0-08 | 0003O0 | `0x004b7c50` is shared `InitRectBounds(bounds,left,top,right,bottom)`. | Very high | live typed helper body and UID00015S | target Helper Contract/formal | incorporate | APPLIED_VERIFIED |
| C3O0-09 | 0003O0 | `SnowParticleEntry` is `RectBounds bounds` plus one-byte `type` and natural tail padding. | Very high layout/high spelling | constructor writes and Snow method consumers | target Object Layout; UID0001WJ | incorporate | APPLIED_VERIFIED |
| C3O0-10 | 0003O0 | Inline array starts at `+0x10c`, has 200 entries at `0x14` stride, occupies `0xfa0`, and ends at object size `0x10ac`. | Very high | loop, caller allocation, cross-method access | target Object Layout; UID0000DC/UID0001WJ | incorporate | APPLIED_VERIFIED |
| C3O0-11 | 0003O0 | Every record starts at bounds `(0,800,8,808)` with `type=0`; padding remains untouched. | Very high | exact helper pushes/store/stride | target Particle Initialization/formal | incorporate | APPLIED_VERIFIED |
| C3O0-12 | 0003O0 | Source order is inherited animation assignments, 200-entry loop, then direct-target enable; base/vptr/return mechanics remain implicit. | High | instruction order plus source reconstruction rules | target formal/ABI | incorporate | APPLIED_VERIFIED |
| C3O0-13 | 0003O0 | Constructor EH/cookie and cleanup funclets are compiler output; caller owns allocation cleanup. | Very high | target/caller funclets and EH state | target Exception/Negative Evidence | incorporate | APPLIED_VERIFIED |
| C3O0-14 | 0003O0 | Entry signature is unique; target pointers/end xrefs/duplicate body are absent; alignment is exact. | Very high | signature, byte search, xrefs, hashes | target Range/Negative Evidence | incorporate | APPLIED_VERIFIED |
| C3O0-15 | 0003O0 | Direct owner/emitter remains UID0000DC; MapPane, UID0001O0/1O1, UID0002Z9, and UID0000P8 are caller/index/data/source-route contexts. | Very high | class/vtable/caller/source graph | target Status/Ownership | preserve | APPLIED_VERIFIED |
| C3O0-16 | 0003O0 | Current canonical source/header route is UID0000P8 `WeatherLayerPane.cpp`/`.h`; UID0000NR is historical only. | High | current routes, contiguous family, generated destination, source-string negative | target Source Placement; file supports | incorporate | APPLIED_VERIFIED |
| C3O0-17 | 0003O0 | Exact destination-ready constructor formal is eligible and removes the empty emitter. | Very high | all preceding claims | target managed C++ | incorporate | APPLIED_VERIFIED |
| C3O0-18 | 0003O0 | Target metadata should become `92/94`; owner/emitter/reconstructable remain unchanged; `Nested` should become `0`. | High | evidence completeness and exact child shape | target metadata | update | APPLIED_VERIFIED |
| C3O0-19 | 0003O0 | Target prose must preserve exact bytes/hash, helper/field/type inference, padding, compiler/source separation, and rejected alternatives. | High | Rule 26 no-loss standard | target all substantive sections | incorporate | APPLIED_VERIFIED |
| C3O0-20 | 0003O0 | Snowing class page gains exact `0x10ac` layout, constructor source, class dependency order, and score `90/92` without duplicating method code. | High | target plus existing Snow method/vtable evidence | UID0000DC | incorporate/update | APPLIED_VERIFIED |
| C3O0-21 | 0003O0 | Weather class/file pages retain their current scores/routes and add the exact Snow derived layout/constructor contract. | High | current canonical route and layout | UID0000G1, UID0000P8 | incorporate/preserve | APPLIED_VERIFIED |
| C3O0-22 | 0003O0 | Dedicated Snow file stays a historical candidate at `88/86`; it must not become the current constructor emitter. | High | no source-path proof and accepted file route | UID0000NR | historicalize/preserve | APPLIED_VERIFIED |
| C3O0-23 | 0003O0 | WeatherLayerDataLayouts gains source-ready SnowParticleEntry and exact Snow object extent; score becomes `92/93`. | High | exact binary layout and allocation | UID0001WJ | incorporate/update | APPLIED_VERIFIED |
| C3O0-24 | 0003O0 | UID0001O0/UID0001O1 remain non-emitting indexes and gain current exact constructor/source-route facts. | Very high | current metadata and child split | UID0001O0/UID0001O1 | incorporate/preserve | APPLIED_VERIFIED |
| C3O0-25 | 0003O0 | UID0002Z9 keeps no-hand-authored-vtable disposition and gains exact object/constructor state; metadata remains `88/92`. | Very high | current vtable report plus target | UID0002Z9 | incorporate/preserve | APPLIED_VERIFIED |
| C3O0-26 | 0003O0 | UID0003O1/UID0003O2 support prose must replace stale `m_snowRefreshMode`/unnamed Weather offsets with inherited `m_currentFrame` and `m_weatherBounds`; their separately owned formals are not rewritten by this constructor report. | High | live decompiles and accepted Weather layout | UID0003O1/UID0003O2 prose | incorporate | APPLIED_VERIFIED |
| C3O0-27 | 0003O0 | Generated expectation is one UID0003O0 constructor body and zero UID0003O0 empty markers in WeatherLayerPane.cpp. | Very high | current owner/emitter route | generated readback after validator | verify | APPLIED_VERIFIED |
| C3O0-28 | 0003O0 | Supervisor manual coverage must insert the exact target row and repair stale Snow class/file/index/vtable/type rows listed below. | High | current manual row audit | manual coverage files | supervisor apply | PENDING_SUPERVISOR |
| C3O0-29 | 0003O0 | Supervisor Gate 2B declared exact Weather/Snow particle/Snow object types, renamed/typed/commented target, and annotated caller/cleanup while preserving decorated compiler names. | High | live pre-state, mutation, readback, unchanged bytes/xrefs/bounds, and saved IDB | shared IDA | supervisor apply/read back | APPLIED_VERIFIED |
| C3O0-30 | 0003O0 | No generated/tracker/audit/coverage/IDA/validator/lifecycle file is a B005 write destination during report-only or ordinary callback. | Very high | explicit assignment/workflow boundary | report checklist | preserve | APPLIED_VERIFIED |

## Positive Evidence Summary

- Exact target bytes and PE slice match, the entry signature is unique, and both alignment fences are pure `0xcc`.
- The sole caller allocates `0x10ac`, calls only this constructor for weather selector 2, stores the result in MapPane, and has compiler allocation-delete cleanup.
- Base construction and three decorated Snow vptr stores establish class identity and inheritance facets.
- The packed state bytes agree independently with Weather timer semantics and Snow frame-change behavior.
- The loop base, count, stride, helper signature, type-byte store, and caller allocation close the complete derived object layout with no unexplained tail.
- The direct-target field has an exact default/writer/reader family and is distinct from visibility.
- Current owner/emitter and generated route already point to the correct exact method destination; no split or ownership migration is required.

## IDA MCP Facts

- Function/range facts:
  - `sub_5C1BD0`, size `0xae` / 174 bytes (Verified with int_convert.py), begins `push ebp`, returns at `0x005c1c7d`, exclusive end `0x005c1c7e`.
  - Current prototype `_DWORD *__thiscall(_DWORD *this)`; source is a no-argument constructor.
  - 57 target/funclet instructions; source-relevant body begins with Weather base call and ends after direct-target assignment.
- Data/table/padding facts:
  - packed immediate appears only at `0x005c1c2c`;
  - derived table spans `[this+0x10c,this+0x10ac)`;
  - nine-byte predecessor and two-byte successor fences are exact alignment.
- Xref facts:
  - exactly one target xref, call `0x0050dc17` in `sub_50DB50`;
  - exactly one constructor-store xref to each vtable base: `0x005c1c0d -> 0x006312b0`, `0x005c1c18 -> 0x00631304`, `0x005c1c22 -> 0x00631334`;
  - zero target-end xrefs and zero target-address VA/RVA/raw-offset byte hits.
- Vtable/global/type facts:
  - decorated Snowing primary/adjusted vtables and RTTI names are present and must remain protected;
  - `Pane` size `0xf8`, `RainingLayerPane` exact size `0x10c`, and `RectBounds` size `0x10` are current UDT facts;
  - `WeatherLayerPane`/`SnowingLayerPane` are forward-only current names and `SnowParticleEntry` is absent, enabling a non-colliding type upgrade.
- Negative IDA facts:
  - no second constructor, duplicate signature, explicit stack parameter, string, local global, switch table, alternate class vptr, source path, or object tail;
  - target has no source-visible allocator/delete, timer scheduling, rendering, randomization, resource load, or map-state branch.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005c1bd0-0x005c1c7e` | UID0003O0 target | exact constructor | true | UID0000DC | assignment-time `86/88`; callback-verified `92/94` | `APPLIED_VERIFIED` by B005 readback and supervisor Gate 2A |
| `0x005c1c80-0x005c1f4c` | UID0003O1 | update/render | true | UID0000DC | `88/89` | existing emitter; prose alias sync only |
| `0x005c1f50-0x005c20d4` | UID0003O2 | `OnFrameChanged` | true | UID0000DC | `88/89` | existing blank child; prose blocker sync only |
| `0x005c20e0-0x005c2228` | UID0003O3 | render on target | true | UID0000DC | `88/89` | existing emitter |
| `0x005c2a20-0x005c2a5b` | UID0003O4 | scalar deleting destructor | true/compiler wrapper | UID0000DC | current | unchanged |
| `0x006312ac-0x0063133c` | UID0002Z9 | Snow RTTI/vtable data | source-declared/generated-binary | UID0000DC | `88/92` | marker-only unchanged |
| `0x005c1bd0-0x005c2a5b` | UID0001O0 | Snow method index | false | UID0000DC | `88/89` | non-emitting index |
| `0x005c1bd0-0x005c2ab5` | UID0001O1 | Snow/Swallow mixed index | false | UID0000P8 | `86/88` | non-emitting index |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050dc17` | sole call to target in `sub_50DB50` | MapPane weather selector 2 constructs Snowing after `0x10ac` allocation |
| `0x005c1bfb` | call to `WeatherLayerPane__Constructor` | implicit base construction |
| `0x005c1c0d` | store of `0x006312b0` | primary Snowing vptr compiler transition |
| `0x005c1c18` | store of `0x00631304` | adjusted EventHandler-style Snowing vptr transition |
| `0x005c1c22` | store of `0x00631334` | adjusted TimerHandler-style Snowing vptr transition |
| `0x005c1c4f` | call to `InitRectBounds` | initializes one particle bounds record per iteration |
| `0x006312fc` | vtable cell to `SnowingLayerPane__OnFrameChanged` | later consumer of inherited frame state and particle array |
| `0x004f16b2` | unique bounded read of Pane `+0xf6` | direct-target mode bypasses generic `OnPaint` dispatch |
| `0x00508505`, `0x0050bc9e`, `0x00510733`, `0x005137f3` | callers of MapPane setup `0x0050db50` | constructor route is live through map change/effect-state paths |

## Documentation Evidence And IDA Status

- Assignment-time target already had the correct class owner, MapPane caller, base call, vtable stores, and direct-target meaning, but its blank-C++ statement and unresolved field/helper/source wording were stale. After fresh Gate 1, B005 independently reread the preserved target and verified the complete report-proposed repair as `APPLIED_VERIFIED`; supervisor Gate 2A independently passed.
- UID0003PG/UID0003PH/UID0003PI/UID0003PJ/UID0003PK close the Weather tail, signed field roles, direct-target field, and canonical header/source route needed by this constructor.
- UID0003O1/UID0003O2/UID0003O3 and UID0001WJ independently confirm the `+0x10c` particle base, `0x14` stride, type byte, and later bounds/type use.
- UID00015S plus live IDA close `InitRectBounds`; no target-local fake wrapper is needed.
- Current manual by-memory coverage is stale: UID0003O0 is absent, UID0001O0/UID0001O1 remain old `50%` reconstructable rows despite current non-emitting metadata, and UID0002Z9 remains at old `85%`.
- Current class/file manual coverage is stale for Snowing: class row remains `86%`; dedicated file row says `86%` although current file metadata is `88/86`.
- IDA target pre-state at Gate 2B entry was raw `sub_5C1BD0` with raw `_DWORD *` receiver. The supervisor has now applied and read back the exact Gate 2B upgrades below without erasing the pre-existing helper/base/direct-target evidence.

## Ranked Ownership Analysis

### 1. UID0000DC SnowingLayerPane class

- Evidence for: decorated RTTI/vtables, all three constructor stores, exact Snow virtual method family, direct class page, object layout, and current owner/emitter route.
- Evidence against: none.
- Decision: retain as direct owner and emitter.

### 2. UID0000P8 WeatherLayerPane file/source family

- Evidence for: current class emitter route, canonical combined Weather source, contiguous code/RTTI/data, shared base and layout, generated destination.
- Evidence against: it is broader than direct semantic class ownership and exact historical one-file provenance is not symbol-proven.
- Decision: retain as source/header route, not direct target owner.

### 3. UID0000NR SnowingLayerPane dedicated file candidate

- Evidence for: class-specific filename is plausible for a human source tree and remains documented historically.
- Evidence against: current owner chain and generated route use WeatherLayerPane; no PDB/source-path string proves a dedicated original file; moving one constructor would split one class inconsistently.
- Decision: preserve as historical candidate only; do not route or emit the target there.

### 4. MapPane, aggregates, vtable data, or RectBounds helper owner

- Evidence for: MapPane calls the constructor; aggregates contain its address; vtable data names its class; helper initializes its bounds.
- Evidence against: caller, physical containment, compiler data, and dependency use do not establish authored method ownership.
- Decision: reject all as direct owners/emitters.

### Proposed new file/grouping, if applicable

- No new by-file or by-memory page is required.
- The source-visible support type `SnowParticleEntry` belongs with the Weather/Snow class declaration contract in `WeatherLayerPane.h`, documented by UID0001WJ; it is not a standalone executable child or separate source file.

## Source Placement

- Recommended source file: `NexusTK/map/WeatherLayerPane.cpp`, qualified `SnowingLayerPane::SnowingLayerPane()` emitted through UID0000DC -> UID0000P8.
- Recommended header: canonical `WeatherLayerPane.h`, after `RectBounds` and `WeatherLayerPane` are complete and after `SnowParticleEntry` is declared.
- Header dependency order: shared `RectBounds`/`InitRectBounds` declaration; `SnowParticleEntry`; `WeatherLayerPane : public Pane`; `SnowingLayerPane : public WeatherLayerPane`; then the out-of-line constructor definition in the `.cpp`.
- The class/file router pages retain comment-plus-children behavior and must not duplicate this method body or fabricate a second partial class definition.
- Rejected placements: MapPane.cpp, RectBounds.cpp, the vtable page, the non-emitting aggregates, and current dedicated Snowing file output.
- Remaining uncertainty: exact historical physical file split is not recoverable from the current binary. The project route is nevertheless settled enough for source reconstruction and is not a target blocker.

## Range / Split / Padding / Reclassification Analysis

- Exact range is one modeled function `[0x005c1bd0,0x005c1c7e)`; no interior function, embedded table, switch data, or source-bearing child split exists.
- Predecessor `[0x005c1bc7,0x005c1bd0)` is nine-byte Rain-to-Snow alignment and remains ignored padding.
- Successor `[0x005c1c7e,0x005c1c80)` is two-byte alignment before UID0003O1 and remains ignored padding.
- Do not widen target into UID0003O1 or backward into UID0003PK.
- Assignment-time `Nested:4` was stale aggregate-era metadata; the current callback-verified target uses `Nested:0`, and supervisor Gate 2A passed before lifecycle execution.
- No reclassification is needed: target remains reconstructable source code with a direct emitter.

## Negative Evidence Summary

- No second target caller, duplicate function signature, direct target pointer, end xref, alternate constructor, or explicit source parameter exists.
- No target-local string, global, table, resource, renderer, randomizer, timer scheduler, allocation, delete, or map-state branch exists.
- No source path or PDB string proves a dedicated Snow file.
- No current complete Snowing/Weather UDT exists in IDA; therefore raw decompiler types are not counterevidence to the exact layout proved by allocation and consumers.
- Vtable references prove class identity but do not justify handwritten vtable arrays or explicit vptr assignments.
- Caller allocation/delete paths prove object liveness and exception cleanup but do not move source ownership to MapPane.
- Adjacent Rain/Snow methods and data prove family placement but do not justify widening this exact child.
- The three bytes after each type byte are never initialized by the constructor; do not invent source fields or zero them.

## IDA Rename / Type / Comment Recommendations

All actions are supervisor Gate 2B work. B005 remained read-only and performed no IDA mutation.

Fresh exact pre-state source: live read-only MCP session `supervisor_gate2b_0002OT_20260723`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The successful bounded calls were `tools/list` JSON-RPC id `9201`; target `disasm` id `9301`; `lookup_funcs`, `stack_frame`, and `type_inspect` ids `9302..9304`; `func_profile`/caller/helper `disasm` ids `9305..9307`; `export_funcs` exact line-comment maps id `9309`; Weather/helper profile/export ids `9310..9311`; vtable/RTTI `entity_query` ids `9312..9313`; and bounded data/comment readbacks ids `9401` and `9410..9418`. MCP remained healthy and no mutation tool was called.

Comment-pre-state convention for this table:

- `export_funcs` returns each instruction comment as separate `regular` and `repeatable` keys. An address omitted from that exact function comment map has both line-comment variants absent.
- Function-level comment state is also checked against the decompiler prefix and call-site propagation. A displayed operand annotation such as ``const SnowingLayerPane::`vftable'`` is IDA-rendered symbol/type text, not a regular or repeatable line comment.
- At a call instruction, a propagated callee description is recorded separately from the call instruction's own regular/repeatable comments. This prevents inherited callee text from being misreported as a local comment.

### Exact Type And Function Pre-State

| Address/entity | Exact current name/declaration/type/width or local state | Exact current regular/repeatable comment pre-state | Proposed supervisor action | Expected readback |
| --- | --- | --- | --- | --- |
| type `Pane` | UDT `Pane`, exact width `248` / `0xf8`; one synthetic member `_paneBase` at `+0x0`, type `unsigned __int8[248]` | type regular comment absent; type repeatable comment absent | `NO_CHANGE_VERIFIED`; preserve this exact base extent and do not replace it under UID0003O0. | same `Pane` UDT, width, member, and absent comments |
| type `RectBounds` | UDT `RectBounds`, exact width `16` / `0x10`; `left:int +0x0`, `top:int +0x4`, `right:int +0x8`, `bottom:int +0xc` | type regular comment absent; type repeatable comment absent | `NO_CHANGE_VERIFIED`; preserve exact declaration/members. | same declaration, width, members, and absent comments |
| type `WeatherLayerPane` | exact forward declaration name `WeatherLayerPane`; `is_udt:false`, no members, IDA `BADSIZE` rendered as `18446744073709551615` | type regular comment absent; type repeatable comment absent | Upgrade this exact forward name in place to `struct WeatherLayerPane { Pane _base; signed __int8 m_currentFrame; signed __int8 m_frameCount; __int16 m_timerInterval; RectBounds m_weatherBounds; };`, width `0x10c`, offsets `0xf8/0xf9/0xfa/0xfc`. Do not create a suffixed duplicate. | one `WeatherLayerPane` UDT, width `0x10c`, exact members/offsets, and no duplicate |
| type `SnowParticleEntry` | exact query result `exists:false`, `Type not found: SnowParticleEntry`; no declaration or width exists | type regular comment absent; type repeatable comment absent | Declare `struct SnowParticleEntry { RectBounds bounds; unsigned __int8 type; unsigned __int8 _tailPadding[3]; };` for IDA layout, width `0x14`; `_tailPadding` models compiler padding and is not authored source state. | width `0x14`, bounds `+0`, type `+0x10`, layout pad `+0x11..+0x13` |
| type `SnowingLayerPane` | exact forward declaration name `SnowingLayerPane`; `is_udt:false`, no members, IDA `BADSIZE` rendered as `18446744073709551615` | type regular comment absent; type repeatable comment absent | Upgrade this exact forward name in place to `struct SnowingLayerPane { WeatherLayerPane _base; SnowParticleEntry m_snowParticles[200]; };`, width `0x10ac`. Do not create a suffixed duplicate. | one `SnowingLayerPane` UDT, base `+0`, array `+0x10c`, width `0x10ac`, and no duplicate |
| target function `[0x005c1bd0,0x005c1c7e)` | exact current name `sub_5C1BD0`, width `0xae`; exact prototype `_DWORD *__thiscall sub_5C1BD0(_DWORD *this)` | at `0x005c1bd0`: line regular absent; line repeatable absent; function regular absent; function repeatable absent; decompiler leading comment absent | Rename to `SnowingLayerPane__SnowingLayerPane`; apply `SnowingLayerPane *__thiscall SnowingLayerPane__SnowingLayerPane(SnowingLayerPane *this)`; set exact function regular comment `SnowingLayerPane constructor. Calls WeatherLayerPane, installs compiler primary/EventHandler/TimerHandler vptrs, initializes inherited frame/count/interval to 4/5/200 ms, initializes 200 inline SnowParticleEntry bounds to (0,800,8,808) and type 0, enables inherited m_drawOnTarget, and returns this by constructor ABI. Exact range [0x005c1bd0,0x005c1c7e); sizeof(SnowingLayerPane)=0x10ac.` Preserve exact bounds and leave repeatable absent. | exact name/prototype/range; exact function regular comment; line regular absent, line repeatable absent, and function repeatable absent unless the supervisor records an explicit channel change |
| target decompiler local `v2` | exact current local name `v2`, type `struct RectBounds *`, register ESI | local regular comment absent; local repeatable comment absent | After target type application, rename to `particleBounds` only if this exact live local remains. If retyping removes or reshapes it, record `NO_CHANGE_VERIFIED` rather than forcing a stale local ID. | `particleBounds: RectBounds *` in the re-decompile or explicit no-change/removal readback |
| target decompiler local `v3` | exact current local name `v3`, type `int`, register EDI | local regular comment absent; local repeatable comment absent | After target type application, rename to `remainingParticles` only if this exact live local remains. If retyping removes or reshapes it, record `NO_CHANGE_VERIFIED`. | `remainingParticles:int` in the re-decompile or explicit no-change/removal readback |
| target stack slot `var_10` | exact current stack name `var_10`, frame offset `0x10`, width `4`, type `_DWORD *` | stack/local regular comment absent; stack/local repeatable comment absent | After target type application, if the exact slot survives, rename to `thisForCleanup` and type `SnowingLayerPane *`; otherwise record its compiler removal/reshape without forcing it. | typed/named cleanup slot or explicit post-retype removal/reshape disposition |
| target stack slot `var_C` | exact current stack name `var_C`, frame offset `0x14`, width `4`, type `_DWORD` | stack/local regular comment absent; stack/local repeatable comment absent | `NO_CHANGE_VERIFIED`; compiler EH state, not a source local. | same compiler slot or exact post-retype compiler-state disposition |
| target stack slot `var_4` | exact current stack name `var_4`, frame offset `0x1c`, width `4`, type `_DWORD` | stack/local regular comment absent; stack/local repeatable comment absent | `NO_CHANGE_VERIFIED`; compiler EH/cookie state, not a source local. | same compiler slot or exact post-retype compiler-state disposition |
| target stack slot `__saved_registers` | exact current stack name `__saved_registers`, frame offset `0x20`, width `4`, type `_DWORD` | stack/local regular comment absent; stack/local repeatable comment absent | `NO_CHANGE_VERIFIED`; preserve IDA compiler-frame identity. | same compiler-frame slot |
| target stack slot `__return_address` | exact current stack name `__return_address`, frame offset `0x24`, width `4`, type `_UNKNOWN *` | stack/local regular comment absent; stack/local repeatable comment absent | `NO_CHANGE_VERIFIED`; preserve IDA compiler-frame identity. | same compiler-frame slot |
| target stack slot `arg_4` | exact current stack name `arg_4`, frame offset `0x2c`, width `4`, type `_DWORD` | stack/local regular comment absent; stack/local repeatable comment absent | `NO_CHANGE_VERIFIED`; do not invent a source constructor parameter. Recheck after target prototype application and record whether IDA removes or retains this compiler-frame artifact. | no source parameter in the target prototype and exact retained/removed slot readback |
| caller function `[0x0050db50,0x0050dcb3)` | exact current name `sub_50DB50`, width `0x163`; exact prototype `char __thiscall sub_50DB50(int this, unsigned __int8 arg1, char arg2)` | at `0x0050db50`: line regular absent; line repeatable absent; function regular absent; function repeatable absent; decompiler leading comment absent | `NO_CHANGE_VERIFIED` for caller name/type under this report; apply only the independent instruction comments below. | caller name/type/comments unchanged; independent line-comment readbacks recorded |
| helper function `[0x004b7c50,0x004b7c6f)` | exact current name `InitRectBounds`, width `0x1f`; exact prototype `void __cdecl InitRectBounds(struct RectBounds *bounds, int left, int top, int right, int bottom)` | at `0x004b7c50`: line regular absent; line repeatable absent; function regular exact `Initializes RectBounds fields in left, top, right, bottom order.`; function repeatable absent; all helper instruction line regular/repeatable comments absent | `ALREADY_PRESENT_VERIFIED`; preserve exact name, prototype, function comment, bounds, and body. | same name/type/function regular comment; function repeatable and instruction comments remain absent; no target-local wrapper |

### Exact Instruction, Caller, And Cleanup Pre-State

| Address/action | Exact current instruction/name/type/width state | Exact current regular/repeatable line-comment pre-state | Proposed supervisor action | Expected readback |
| --- | --- | --- | --- | --- |
| base call `0x005c1bfb` | no local label; `call WeatherLayerPane__Constructor`, rel32 call; callee exact type `WeatherLayerPane *__thiscall WeatherLayerPane__Constructor(WeatherLayerPane *this)` | own regular absent; own repeatable absent; rendered propagated callee description exact `WeatherLayerPane constructor. Calls Pane(true), installs the primary/EventHandler/TimerHandler Weather vptr views, computes m_weatherBounds from g_useEpfAssets and 15x17 map-tile dimensions with legacy +12/+14 offsets, clears m_currentFrame/m_frameCount/m_timerInterval, and schedules timer id 0 with zero delay/payloads. Called by Rain, Snow, and Swallow constructors. Exact range [0x005c12a0,0x005c13a1).` | `ALREADY_PRESENT_VERIFIED`; preserve own-comment absence and inherited callee description; do not duplicate the callee text locally. | same named rel32 call, same inherited description, own regular absent, own repeatable absent |
| primary vptr store `0x005c1c0d` | no local label; `mov dword ptr [ebx], offset ??_7SnowingLayerPane@@6B@`; write width `4`; operand display includes automatic ``const SnowingLayerPane::`vftable'`` | regular absent; repeatable absent | Add exact regular `compiler primary SnowingLayerPane vptr`; preserve decorated operand/name. | exact regular comment, repeatable absent, unchanged instruction/name |
| adjusted vptr store `0x005c1c18` | no local label; `mov dword ptr [ebx+0A0h], offset ??_7SnowingLayerPane@@6B@_0`; write width `4`; automatic ``const SnowingLayerPane::`vftable'`` | regular absent; repeatable absent | Add exact regular `compiler adjusted EventHandler-facet SnowingLayerPane vptr`; preserve decorated operand/name. | exact regular comment, repeatable absent, unchanged instruction/name |
| adjusted vptr store `0x005c1c22` | no local label; `mov dword ptr [ebx+0A4h], offset ??_7SnowingLayerPane@@6B@_1`; write width `4`; automatic ``const SnowingLayerPane::`vftable'`` | regular absent; repeatable absent | Add exact regular `compiler adjusted TimerHandler-facet SnowingLayerPane vptr`; preserve decorated operand/name. | exact regular comment, repeatable absent, unchanged instruction/name |
| packed store `0x005c1c2c` | no address label; `mov dword ptr [ebx+0F8h], 0C80504h`; write width `4`, immediate bytes `04 05 c8 00` | regular absent; repeatable absent | Add exact regular `compiler-coalesced stores: m_currentFrame=4, m_frameCount=5, m_timerInterval=200 ms (bytes 04 05 c8 00)`. | exact regular comment, repeatable absent, unchanged instruction bytes |
| loop head `0x005c1c40` | exact label `loc_5C1C40`; `push 328h`; pushed stack-argument width `4` | regular exact `bottom`; repeatable absent | Append without deleting `bottom`: `initialize 200 inline SnowParticleEntry records; stride 0x14; bounds=(0,800,8,808); type=0; tail padding untouched`. | regular retains exact `bottom` plus semantic text; repeatable absent |
| loop argument `0x005c1c45` | no local label; `push 8`; pushed stack-argument width `4` | regular exact `right`; repeatable absent | `ALREADY_PRESENT_VERIFIED`; preserve. | regular exact `right`; repeatable absent |
| loop argument `0x005c1c47` | no local label; `push 320h`; pushed stack-argument width `4` | regular exact `top`; repeatable absent | `ALREADY_PRESENT_VERIFIED`; preserve. | regular exact `top`; repeatable absent |
| loop argument `0x005c1c4c` | no local label; `push 0`; pushed stack-argument width `4` | regular exact `left`; repeatable absent | `ALREADY_PRESENT_VERIFIED`; preserve. | regular exact `left`; repeatable absent |
| loop argument `0x005c1c4e` | no local label; `push esi`; pushed pointer width `4`, current ESI local type `RectBounds *` | regular exact `bounds`; repeatable absent | `ALREADY_PRESENT_VERIFIED`; preserve. | regular exact `bounds`; repeatable absent |
| loop helper call `0x005c1c4f` | no local label; `call InitRectBounds`; rel32 call to exact helper `[0x004b7c50,0x004b7c6f)` | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; loop-head semantic comment is sufficient. | same named rel32 call; regular absent; repeatable absent |
| loop type store `0x005c1c54` | no local label; `mov byte ptr [esi+10h], 0`; write width `1` | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; preserve exact byte store. | unchanged instruction; regular absent; repeatable absent |
| loop stack cleanup `0x005c1c58` | no local label; `add esp, 14h`; 32-bit stack-pointer operation removing `0x14` bytes | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; preserve compiler call cleanup. | unchanged instruction; regular absent; repeatable absent |
| loop pointer advance `0x005c1c5b` | no local label; `add esi, 14h`; 32-bit pointer advance by exact stride `0x14` | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; preserve exact stride. | unchanged instruction; regular absent; repeatable absent |
| loop decrement `0x005c1c5e` | no local label; `sub edi, 1`; 32-bit signed loop-counter operation | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; preserve exact count-down. | unchanged instruction; regular absent; repeatable absent |
| loop branch `0x005c1c61` | no local label; `jnz short loc_5C1C40`; short conditional branch to `0x005c1c40` | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; preserve exact branch target. | unchanged branch/bounds; regular absent; repeatable absent |
| direct-target store `0x005c1c63` | no local label; `mov byte ptr [ebx+0F6h], 1`; write width `1` | regular exact `inherited Pane direct-target paint mode (preferred source name m_drawOnTarget) = true; SnowingLayerPane uses direct-target rendering`; repeatable absent | `ALREADY_PRESENT_VERIFIED`; preserve literal text exactly. | exact regular text; repeatable absent; unchanged byte store |
| caller allocation `0x0050dbfa` | exact label `loc_50DBFA`; `push 10ACh`; pushed stack-argument width `4` | regular absent; repeatable absent | Add exact regular `allocate sizeof(SnowingLayerPane) = 0x10ac for weather selector 2`. | exact regular comment; repeatable absent; unchanged instruction/label |
| caller call `0x0050dc17` | no local label; `call sub_5C1BD0`; rel32 call to exact target `[0x005c1bd0,0x005c1c7e)` | regular absent; repeatable absent | Target rename updates the operand; add exact regular `construct SnowingLayerPane and publish as active MapPane weather pane`. | named target rel32 call; exact regular comment; repeatable absent |
| cleanup load `0x0060be43` | exact label `loc_60BE43`; `mov ecx, [ebp+var_10]`; read width `4`, current slot type `_DWORD *` | regular exact `this`; repeatable absent | Replace only regular `this` with exact `compiler EH cleanup for failed SnowingLayerPane construction: destroy the already-constructed Weather/Pane base; no explicit source destructor call`. | exact replacement regular; repeatable absent; unchanged load and target-tail label |
| cleanup tail jump `0x0060be46` | no local label; `jmp j_Pane__Destructor`; near tail transfer to exact existing thunk name `j_Pane__Destructor` | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; preserve compiler tail cleanup and exact thunk identity. | unchanged jump/name; regular absent; repeatable absent |

### Exact Protected Names, Bounds, And No-Change State

| Address/range | Exact current name/type/width state | Exact current regular/repeatable comment pre-state | Supervisor disposition | Expected readback |
| --- | --- | --- | --- | --- |
| vtable data `0x006312b0` | exact decorated name `??_7SnowingLayerPane@@6B@`; named `.rdata` vtable-base cell, width `4`; exact type query failure `Failed to get type information for variable at 0x6312b0` | regular absent; repeatable absent; rendered vtable annotation is automatic symbol/type text, not a user comment | `NO_CHANGE_VERIFIED`; preserve exact decorated identity and bytes | same name/address/bytes; regular absent; repeatable absent |
| vtable data `0x00631304` | exact decorated name `??_7SnowingLayerPane@@6B@_0`; named `.rdata` adjusted-vtable-base cell, width `4`; exact type query failure `Failed to get type information for variable at 0x631304` | regular absent; repeatable absent; rendered vtable annotation is automatic symbol/type text, not a user comment | `NO_CHANGE_VERIFIED`; preserve exact decorated identity and bytes | same name/address/bytes; regular absent; repeatable absent |
| vtable data `0x00631334` | exact decorated name `??_7SnowingLayerPane@@6B@_1`; named `.rdata` adjusted-vtable-base cell, width `4`; exact type query failure `Failed to get type information for variable at 0x631334` | regular absent; repeatable absent; rendered vtable annotation is automatic symbol/type text, not a user comment | `NO_CHANGE_VERIFIED`; preserve exact decorated identity and bytes | same name/address/bytes; regular absent; repeatable absent |
| RTTI data `[0x006540f8,0x0065410c)` | exact decorated name `??_R4SnowingLayerPane@@6B@`; complete-object-locator entity, boundary width `0x14` | regular absent; repeatable absent; rendered automatic annotation exact `signature` | `NO_CHANGE_VERIFIED`; preserve decorated compiler RTTI entity | same name/range/bytes and comment-channel absence |
| RTTI data `[0x0065410c,0x0065411c)` | exact decorated name `??_R3SnowingLayerPane@@8`; class-hierarchy descriptor entity, boundary width `0x10` | regular absent; repeatable absent; rendered automatic annotation exact `signature` | `NO_CHANGE_VERIFIED`; preserve decorated compiler RTTI entity | same name/range/bytes and comment-channel absence |
| RTTI data `[0x0065411c,0x0065413c)` | exact decorated name `??_R2SnowingLayerPane@@8`; base-class-array entity, boundary width `0x20` | regular absent; repeatable absent; rendered automatic annotation exact `reference to base class decription 1` | `NO_CHANGE_VERIFIED`; preserve decorated compiler RTTI entity and the literal rendered annotation typo | same name/range/bytes and comment-channel absence |
| RTTI data `[0x0065413c,0x00654158)` | exact decorated name `??_R1A@?0A@EA@SnowingLayerPane@@8`; base-class-descriptor entity, boundary width `0x1c` | regular absent; repeatable absent; rendered automatic annotation exact `reference to type description` | `NO_CHANGE_VERIFIED`; preserve decorated compiler RTTI entity | same name/range/bytes and comment-channel absence |
| RTTI data `[0x00654158,0x0065416c)` | exact decorated name `??_R4SnowingLayerPane@@6B@_0`; adjusted complete-object-locator entity, boundary width `0x14` | regular absent; repeatable absent; rendered automatic annotation exact `signature` | `NO_CHANGE_VERIFIED`; preserve decorated compiler RTTI entity | same name/range/bytes and comment-channel absence |
| RTTI data `[0x0065416c,0x00654180)` | exact decorated name `??_R4SnowingLayerPane@@6B@_1`; adjusted complete-object-locator entity, boundary width `0x14` | regular absent; repeatable absent; rendered automatic annotation exact `signature` | `NO_CHANGE_VERIFIED`; preserve decorated compiler RTTI entity | same name/range/bytes and comment-channel absence |
| successor RTTI data `0x00654180` | exact decorated name `??_R4SwallowLayerPane@@6B@`; compiler RTTI entity outside UID0003O0 | regular absent; repeatable absent | `NO_CHANGE_VERIFIED`; outside target and protected | same name/address and comment-channel absence |
| predecessor alignment `[0x005c1bc7,0x005c1bd0)` | no function; exact nine-byte compiler alignment fence | regular absent at every byte; repeatable absent at every byte | `NO_CHANGE_VERIFIED`; do not create/extend a function into this range | same bytes, no function, no comments |
| target bounds `[0x005c1bd0,0x005c1c7e)` | exact modeled function `sub_5C1BD0`, width `0xae` before the proposed rename/type | at `0x005c1bd0`: line regular absent; line repeatable absent; function regular absent; function repeatable absent | preserve exact range; do not split, widen, alter bytes, or absorb cleanup funclets | exact unchanged bounds/bytes/xrefs after rename/type/comment application |
| successor alignment `[0x005c1c7e,0x005c1c80)` | no function; exact two-byte compiler alignment fence | regular absent at every byte; repeatable absent at every byte | `NO_CHANGE_VERIFIED`; do not create/extend a function into this range | same bytes, no function, no comments |

Non-action compiler/runtime dependencies remain protected individually: `SEH_5C1BD0`, `___security_cookie`, `@__security_check_cookie@4`, `___CxxFrameHandler3`, `j_Pane__Destructor`, imported Win32 `OffsetRect`, and the caller allocator/delete helpers. They require no rename/type/comment action under UID0003O0 and therefore are not padded into the action tables.

Safety and collision constraints:

- Back up the IDB before mutation, apply only after rechecking current names/types/comments, and stop if another accepted Gate 2B batch changed these exact entities incompatibly.
- Upgrade existing forward types in place; do not create suffixed duplicate types.
- Do not rename imported Win32 `OffsetRect`, decorated RTTI/vtables, SEH handlers, cookie helpers, or allocator/delete functions under this report.
- Do not type the source constructor as returning `void` in IDA; IDA's decompiler-compatible constructor prototype may return `SnowingLayerPane *`, while authored C++ has no return type.
- Do not expose `_tailPadding` in authored C++; it is IDA layout notation only.
- Expected final readback includes exact UDT sizes/members, target name/type/comment, every address-level regular/repeatable comment disposition above, local rename/no-change disposition after re-decompile, unchanged bytes/xrefs/bounds/decorated names, successful `idb_save`, and saved IDB path/hash/size/timestamp recorded in the report by the supervisor.

### Supervisor Gate 2B Closure

- Gate result: `GATE2B_PASSED` for C3O0-29. Live MCP database `supervisor_gate2b_0002OT_20260723` remained healthy and responsive throughout the bounded pre-state, mutation, and readback sequence.
- Backup: before mutation the supervisor copied `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0003O0-20260724-085703.bak`; both were 143,186,697 bytes with SHA256 `25EB523953ED2443C024108DF4EE9195A15A54B4397F7D38352E970A18FC8798`.
- `NO_CHANGE_VERIFIED`: `Pane` remains size `0xf8` with synthetic `_paneBase`; `RectBounds` remains size `0x10` with exact four `int` members; caller `sub_50DB50`, helper `InitRectBounds`, helper prototype/function comment, compiler EH slots other than the accepted cleanup-slot edit, target bounds, alignment fences, vtable/RTTI decorated identities, target bytes, and xrefs remain unchanged.
- `APPLIED_VERIFIED`: the existing `WeatherLayerPane` forward became one size-`0x10c` UDT with members at `0xf8/0xf9/0xfa/0xfc`; new `SnowParticleEntry` is size `0x14` with `bounds +0`, `type +0x10`, and `_tailPadding +0x11`; the existing `SnowingLayerPane` forward became one size-`0x10ac` UDT with its 200-entry array at `+0x10c`. No suffixed duplicate was created.
- `APPLIED_VERIFIED`: target `0x005c1bd0` is now `SnowingLayerPane__SnowingLayerPane` with prototype `SnowingLayerPane *__thiscall SnowingLayerPane__SnowingLayerPane(SnowingLayerPane *this)` and the exact requested function comment. Retyping reshaped former local `v2` into typed `m_snowParticles`, so its forced rename is `NO_CHANGE_VERIFIED`; `v3` is now `remainingParticles`; stack slot `var_10` is now `thisForCleanup` with type `SnowingLayerPane *`; compiler slots remain intact and no source constructor argument was introduced.
- `APPLIED_VERIFIED`: exact vptr/packed-state comments are present at `0x005c1c0d`, `0x005c1c18`, `0x005c1c22`, and `0x005c1c2c`; `0x005c1c40` retains `bottom` and appends the exact 200-entry initialization comment; caller comments are present at `0x0050dbfa` and `0x0050dc17`; `0x0060be43` contains the exact EH-cleanup replacement. Required pre-existing comments at `0x005c1c45`, `0x005c1c47`, `0x005c1c4c`, `0x005c1c4e`, and `0x005c1c63` remain exact.
- Integrity readback: target remains `[0x005c1bd0,0x005c1c7e)` with the same 174 bytes and sole incoming code xref at `0x0050dc17`; no xref appeared at `0x005c1c7e`; vtable names at `0x006312b0/0x00631304/0x00631334` and Snow/Swallow RTTI names through `0x00654180` remain exact.
- Save: `idb_save` returned `ok:true` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Saved file is 143,185,263 bytes, last write `2026-07-24T09:00:09.2809897-04:00`, SHA256 `131CC1805C5D045FAC2A25A84D53E5ECFA43954C1A3B75E597C2688A1A37E7A9`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Every target-specific behavior, field width/value, dependency, ownership route, and compiler/source distinction is resolved.
- Exact destination-specific managed block for UID0003O0:

```text
*** UID:0003O0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SnowingLayerPane::SnowingLayerPane()
{
    m_currentFrame = 4;
    m_frameCount = 5;
    m_timerInterval = 200;

    for (int i = 0; i < 200; ++i) {
        InitRectBounds(&m_snowParticles[i].bounds, 0, 800, 8, 808);
        m_snowParticles[i].type = 0;
    }

    m_drawOnTarget = true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source-ready no-argument Snow constructor with unique 174-byte body/hash, sole MapPane 0x10ac allocation/call route, implicit WeatherLayerPane base construction, compiler-only primary/adjusted Snow vptr installation, inherited frame/count/interval state 4/5/200 ms, 200 inline 20-byte particle records initialized to bounds (0,800,8,808) and type zero without touching tail padding, inherited direct-target paint mode, compiler-owned unwind cleanup, exact alignment/pointer negatives, and canonical WeatherLayerPane.cpp/.h placement. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Reason it preserves exact behavior:
  - default base construction occurs first;
  - normal MSVC class construction emits the three vptr transitions and ABI return;
  - separate scalar assignments permit the observed optimized packed dword while preserving actual field types;
  - each loop iteration writes exactly 16 bounds bytes and one type byte, leaving natural padding untouched;
  - final direct-target assignment remains after the particle loop;
  - exceptions use compiler-generated base cleanup without explicit source cleanup.
- Reason it matches plausible late-1999 through mid-2000s source: a direct out-of-line constructor with an integer-index loop, C-style shared rectangle helper, inherited `m_` members, no modern range loops/`auto`/uniform initialization, no reverse-engineering labels, and no manual ABI machinery.
- Naming/style: class names PascalCase, members `m_` plus lower camel case, local `i`, braces on following lines for functions and same line for the compact loop, four-space indentation, `true` for bool state, consistent with accepted Weather/Rain source.
- Source dependencies: complete `SnowParticleEntry` and `SnowingLayerPane` declarations plus `InitRectBounds` prototype must precede this definition. `SnowParticleEntry` authored source contains `RectBounds bounds; unsigned char type;`; compiler tail padding supplies size `0x14` without an explicit padding member.
- Third-party import directive: not applicable; this is NexusTK-authored project code.
- Reason code should remain blank: not applicable. The historical blank-body rationale is superseded.

## Final Recommendation

- Accept the callback-verified target C3O0-01 through C3O0-19 implementation, including the complete formal and score `92/94`.
- Accept bounded support C3O0-20 through C3O0-26 without moving method bodies into routers or rewriting separately owned child formals.
- Preserve direct target owner/emitter UID0000DC and source-family route UID0000P8.
- Keep compiler vptr/EH/cookie/return/deleting behavior out of authored C++.
- Keep UID0001O0/UID0001O1 non-emitting and UID0002Z9 generated-binary marker-only.
- Supervisor Gate 2A and C3O0-29 IDA Gate 2B are complete; C3O0-28 manual coverage and lifecycle execution remain.
- No item is left no-owner. Historical file provenance remains documented but does not block the exact source reconstruction.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md`.
- `APPLIED_VERIFIED`: metadata/formal/summary match the exact managed block above at SHA256 `3419CC65316840229412A4736498D3A35D8ABF389F1BFF929CB0E53137443F6D`.
- `APPLIED_VERIFIED`: exact address/PE/hash/signature/padding, sole caller and `0x10ac` allocation, ABI return, caller/target cleanup distinction, pointer/string/duplicate negatives, complete object/particle layout, untouched tail padding, helper argument order, packed-state decomposition, source placement/dependency order, compiler/source separation, historical assumptions, and owner/emitter route are all present at report-level detail.

## Recommended Support Doc Changes

- `by-class/SnowingLayerPane.md` [UID:0000DC]: `APPLIED_VERIFIED` at `90/92`, SHA256 `8C62752D5D562F632B3D1863E19872D2B9C15A1488371292BA06524DCEDC279E`; exact `0x10ac` extent, Weather base `0x10c`, 200-entry inline array, particle layout, constructor contract, dependency order, canonical route, comment-plus-children router, preserved method evidence, and corrected historical blocker prose all read back.
- `APPLIED_VERIFIED` support: UID0000G1 remains `90/93`; UID0000P8 remains `92/93`; UID0000NR remains `88/86`; UID0001WJ is now `92/93`; UID0001O0 remains `88/89` non-emitting; UID0001O1 remains `86/88` non-emitting; UID0002Z9 remains `88/92` marker-only; UID0003O1 remains `88/89` with its formal preserved; UID0003O2 remains `88/89` with blank separately owned formal. Each now carries its exact bounded constructor/layout/source/history update.
- Generated/tracker/audit/coverage files are never B005 ordinary edit targets. Generated expectations are verified after scoped validators; manual coverage is supervisor-owned.

## Score And Metadata Recommendation

- Target assignment-time/pre-callback baseline: `86/88`, owner/emitter UID0000DC, reconstructable true, blank position/C++, `Nested:4`.
- `APPLIED_VERIFIED` current target: `92/94`, same owner/emitter/reconstructable/blank position, exact constructor formal, `Nested:0`, SHA256 `3419CC65316840229412A4736498D3A35D8ABF389F1BFF929CB0E53137443F6D`; preserved scoped validator command `000000017085` exited `0` with `ok:1` and callback readback confirms C3O0-01..19.
- `APPLIED_VERIFIED` current class: UID0000DC `90/92`, owner/emitter UID0000P8, reconstructable true, SHA256 `8C62752D5D562F632B3D1863E19872D2B9C15A1488371292BA06524DCEDC279E`; scoped validator command `000000017101` exited `0` with `ok:1`.
- Supervisor Gate 2A preserved those target/class states and UID0001WJ `92/93`; all other support scores/routes remain as listed above.
- Reason not lower: exact range/bytes/hash, unique signature, sole caller, exact allocation/object size, ABI, base call, all vptrs, every source-visible assignment, field types/values, helper contract, complete particle layout/count/stride/padding, cleanup boundary, direct owner/emitter, source/header route, and human C++ are closed.
- Reason not higher: original private lexical spellings and exact historical one-file versus per-layer partition are not symbol-proven; no full header build or compiler codegen match has been performed. The `95/95` final-code barrier therefore remains respected.
- Score-improvement attempt:
  - helper blocker: resolved through current typed `InitRectBounds` and UID00015S;
  - packed-state blocker: resolved through int conversion and Weather/Snow consumers;
  - field blocker: resolved to signed byte/byte/short inherited members and direct-target bool;
  - type/layout blocker: resolved through writes, 20-byte stride, 200 count, 4,000-byte array, and exact allocation;
  - caller/reachability blocker: resolved to one direct constructor call inside a live four-caller MapPane setup path;
  - source-placement blocker: current project route selected; historical provenance bounded rather than deferred;
  - C++ blocker: every instruction classified as source-visible or compiler-generated, producing exact destination code;
  - range blocker: exact hashes, unique signature, pointer negatives, and padding prove boundaries.
- Support recommendations: UID0000DC `90/92`; UID0001WJ `92/93`; all other listed support metadata unchanged.

## Open Questions With Attempted Resolution

- Original spelling of the particle record/type/member:
  - checked constructor writes, all Snow consumers, type docs, generated code, old reports, and project naming;
  - resolution: use `SnowParticleEntry`, `m_snowParticles`, `bounds`, and `type` as the highest-probability coherent human vocabulary. This is sufficient for source; raw offsets are rejected.
- Original source order of the three packed assignments:
  - checked packed bytes, declaration order, Rain/Weather sibling constructors, and later consumers;
  - resolution: write declaration-order assignments `m_currentFrame`, `m_frameCount`, `m_timerInterval`; compiler may legally coalesce them to the observed dword.
- Exact original source file split:
  - checked current file/class routes, generated output, contiguous code/RTTI/data, archived placement research, strings, and types;
  - resolution: use current canonical `WeatherLayerPane.cpp`/`.h`; retain dedicated Snowing file only as historical provenance. No implementation blocker remains.
- Explicit padding source member:
  - checked write coverage and x86 alignment;
  - resolution: authored source has no padding field and does not value-initialize records; natural alignment creates the three bytes. IDA may model explicit `_tailPadding[3]` for layout only.
- Constructor cleanup source:
  - checked target SEH state, cleanup funclet, and caller delete funclets;
  - resolution: ordinary C++ construction generates cleanup. No explicit try/catch/base destructor/delete belongs in source.
- Questions remaining unresolved: no target behavior, ownership, source placement, range, type, score, or C++ question remains. Only irrecoverable original private spelling/file-provenance uncertainty remains as an explicit confidence cap.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following current manual rows were inspected. B005 must not apply them. Auto-generated tracker/coverage rows are validator-owned and receive no manual text.

- `by-memory/-coverage-report.md`: UID0003O0 is absent; UID0001O0/UID0001O1 and UID0002Z9 are stale.
- `by-class/-coverage-report.md`: UID0000DC is stale at `86%`; UID0000G1 is stale at `88%` versus current `90/93` but its broader correction may be applied with this batch.
- `by-file/-coverage-report.md`: UID0000NR is stale at `86%`; UID0000P8 is current `92%` but lacks Snow constructor closure.
- `by-type/by-struct/-coverage-report.md`: UID0001WJ is current `91%` and requires the recommended `92%` update.

File/placement: replace the current UID0001O1 and UID0001O0 lines near by-memory address `0x005c1bd0`, then insert the exact target row immediately under UID0001O0:

```text
    - [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) 0x005c1bd0-0x005c2ab5 | mixed weather-layer migration index | SnowingAndSwallowLayerPanes : not_reconstructable : 86% : strong : Reviewed non-emitting Weather/Snow/Swallow migration index under WeatherLayerPane; exact Snowing and Swallow children own source, including source-ready UID0003O0, while broad aggregate C++ and emitters remain blank to prevent duplication.
    - [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md) 0x005c1bd0-0x005c2a5b | SnowingLayerPane method index | SnowingLayerPaneMethodIndex : not_reconstructable : 88% : strong : Non-emitting Snowing method index; exact constructor/update/frame-change/render/destructor children carry source through SnowingLayerPane, with UID0003O0 now source-ready at 92/94 and current canonical source placement through WeatherLayerPane.cpp.
        - [UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md) 0x005c1bd0-0x005c1c7e | constructor | SnowingLayerPaneConstructor : reconstructable : 92% : very-strong : Exact source-ready no-argument Snow constructor with unique 174-byte body/hash, sole MapPane 0x10ac allocation/call route, implicit Weather base construction, compiler-only primary/adjusted vptrs, inherited 4/5/200 ms animation state, 200 inline 20-byte particle records initialized to bounds (0,800,8,808) and type zero without touching tail padding, inherited direct-target mode, compiler-owned cleanup, exact alignment/pointer negatives, and canonical WeatherLayerPane.cpp/.h placement.
```

File/placement: replace the current UID0002Z9 by-memory row:

```text
        - [UID:0002Z9][0x006312ac-0x0063133c.SnowingLayerPaneVtableData](by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md) 0x006312ac-0x0063133c | vtable-data | SnowingLayerPaneVtableData : reconstructable : 88% : very-strong : Exact Snowing primary and adjusted RTTI/vtable views assigned to direct class parent UID0000DC; live constructor evidence confirms all three vptr stores, exact 0x10ac object/200-entry particle layout, 4/5/200 ms inherited animation state, Snow method/destructor/thunk slots, shared Weather timer, and source-declared/compiler-generated no-handwritten-vtable disposition.
```

File/placement: replace UID0000DC in `by-class/-coverage-report.md`:

```text
- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) : reconstructable : 90% : very-strong : Source-backed Snow weather class with exact 0x10ac Weather-derived layout, 200 inline 20-byte SnowParticleEntry records, source-ready constructor, inherited 4/5/200 ms animation state and direct-target mode, exact update/frame-change/render/destructor/vtable family, current WeatherLayerPane.cpp/.h route, and bounded historical standalone-file and private-name uncertainty.
```

File/placement: replace UID0000G1 in `by-class/-coverage-report.md` while preserving its current `90/93` metadata:

```text
- [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) : reconstructable : 90% : very-strong : Exact 0x10c WeatherLayerPane : public Pane class with source-ready constructor/shared timer, signed frame/count/interval fields, RectBounds weather bounds, Rain/Snow/Swallow derivation, three vtable views, EPF/legacy 15x17-tile bounds, and qualified child routing; Snowing now extends the exact prefix to 0x10ac with 200 inline particle records and 4/5/200 ms inherited state.
```

File/placement: replace UID0000NR and UID0000P8 in `by-file/-coverage-report.md`:

```text
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) : reconstructable : 88% : medium-high : Historical dedicated SnowingLayerPane.cpp candidate with exact class/method/vtable/table inventory and source-ready 0x10ac constructor/layout evidence; current canonical emitter remains the combined WeatherLayerPane.cpp source family because no source-path/PDB proof justifies a split.
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) : reconstructable : 92% : very-strong : Canonical map weather source family with exact Weather/Rain/Snow/Swallow routes, source-ready Weather/Rain/Snow constructors, exact 0x10c Weather/Rain and 0x10ac Snow layouts, inherited signed animation fields/direct-target mode, exact rain/snow data types and render paths, contiguous code/RTTI/data evidence, and preserved historical per-layer file alternatives.
```

File/placement: replace UID0001WJ in `by-type/by-struct/-coverage-report.md`:

```text
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md) : reconstructable : 92% : very-strong : Weather-layer layout support with exact 0x10c Weather/Rain extent, signed inherited frame/count/interval and RectBounds tail, exact 0x10ac Snow extent, source-ready 20-byte SnowParticleEntry containing RectBounds plus one-byte type and natural tail padding, 200-entry inline particle array, exact signed RainStreak/RainSplash families, and bounded Snow descriptor naming/header uncertainty.
```

Reason B agent must not apply directly: all `-coverage-report.md` files are shared supervisor-owned collision points; generated trackers are validator-owned.

## Follow-Up Actions

- Fresh Gate 1 is complete for SHA `EB58D1E3792F9E2F79CD74E0EC480BCAECD18CCD081002ECA769A2442F51A62C`; B005 ordinary implementation/readback is complete for C3O0-01..27 and C3O0-30.
- Remaining unapplied accepted item C3O0-28, supervisor-owned: apply and validate the exact manual coverage rows in `## Exact Manual Supervisor-Owned Coverage Or Tracker Text`. B005 did not edit any coverage file.
- Completed accepted item C3O0-29, supervisor-owned: Gate 2B passed from the preserved exact 50-row IDA handoff with backup, item-level pre/post readback, unchanged bytes/xrefs/bounds/protected names, and successful IDB save. B005 did not mutate IDA.
- Supervisor lifecycle: Gate 2A and Gate 2B are complete. Execute/archive through the validator, then apply and validate C3O0-28 manual coverage under the active supervisor workflow. B005 did not run/probe any lifecycle command.
- A-agent actions: not applicable.

## Confidence

- Recommendation confidence: very high.
- Score confidence: high for `92/94`, consistent with exact Weather/Rain constructor closures and below the `95/95` final-code barrier.
- Remaining uncertainty: original private lexical names and exact historical physical source split only. Neither changes execution, ownership, current source route, or eligibility for human C++.

## Validator Results

- Preserved target checkpoint: command `000000017085` for `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md` exited `0`, `ok:1`; the file was unchanged in this callback and was independently reread claim by claim.
- Command `000000017101`, timestamp `2026-07-24T08:23:09-04:00`: `by-class/SnowingLayerPane.md`, exit `0`, `ok:1`.
- Command `000000017103`, timestamp `2026-07-24T08:24:20-04:00`: `by-type/by-struct/WeatherLayerDataLayouts.md`, exit `0`, `ok:1`, completion update `92`.
- Command `000000017104`, timestamp `2026-07-24T08:25:17-04:00`: `by-class/WeatherLayerPane.md`, exit `0`, `ok:1`.
- Command `000000017106`, timestamp `2026-07-24T08:27:07-04:00`: `by-file/WeatherLayerPane.md`, exit `0`, `ok:1`; six pre-existing `missing_ref_uid 0003YQ` diagnostics remain.
- Command `000000017108`, timestamp `2026-07-24T08:28:08-04:00`: `by-file/SnowingLayerPane.md`, exit `0`, `ok:1`; one pre-existing `missing_ref_uid 0003O4` diagnostic remains.
- Command `000000017114`, timestamp `2026-07-24T08:29:17-04:00`: `by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md`, exit `0`, `ok:1`; three pre-existing `missing_ref_uid 0003O4` diagnostics remain and the validator inserted the canonical UID0000DC link.
- Command `000000017118`, timestamp `2026-07-24T08:30:10-04:00`: `by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md`, exit `0`, `ok:1`; pre-existing `emitter_inactive_has_data` and five `missing_ref_uid 0003YQ` diagnostics remain.
- Command `000000017119`, timestamp `2026-07-24T08:31:05-04:00`: `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`, exit `0`, `ok:1`.
- Command `000000017121`, timestamp `2026-07-24T08:31:58-04:00`: `by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md`, exit `0`, `ok:1`.
- Command `000000017124`, timestamp `2026-07-24T08:33:41-04:00`: `by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md`, exit `0`, `ok:1`.
- All ten callback validators were serial. Each reported deferred generated refresh; B005's final generated readback reached command `000000017124` at the matching timestamp. A later shared supervisor foreground refresh advanced the generated header to command `000000017138` without changing the UID0003O0 body/empty-marker counts. B005 ran no report lifecycle command.

## Changed Files

- Report reconciled in place: `tools/leaser/Agents/Agent-B005/research/0003O0-SnowingLayerPaneConstructor-empty-emitter-source-quality.md`.
- `APPLIED_VERIFIED`, preserved target: `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md`, SHA256 `3419CC65316840229412A4736498D3A35D8ABF389F1BFF929CB0E53137443F6D`, 15,686 bytes, 143 lines.
- `APPLIED_VERIFIED`: `by-class/SnowingLayerPane.md`, SHA256 `8C62752D5D562F632B3D1863E19872D2B9C15A1488371292BA06524DCEDC279E`, 22,219 bytes, 156 lines.
- `APPLIED_VERIFIED`: `by-type/by-struct/WeatherLayerDataLayouts.md`, SHA256 `EB70731F410FD251D98F477F769AAA06409D27E273892619DE509D23015E3F55`, 31,018 bytes, 206 lines.
- `APPLIED_VERIFIED`: `by-class/WeatherLayerPane.md`, SHA256 `BCD4F62F083B99B286D7E3A9D75E6F145401162145140284F9CB4EF83F3DFFCB`, 22,938 bytes, 169 lines.
- `APPLIED_VERIFIED`: `by-file/WeatherLayerPane.md`, SHA256 `228B7074CE02833B44438C3C89F8E582786E069681EA2843B3942DB63E7CA9D5`, 53,849 bytes, 309 lines.
- `APPLIED_VERIFIED`: `by-file/SnowingLayerPane.md`, SHA256 `1E6F5285A181781D268ACB76A884934374AF5895C52247196C6C0F32BCCDD570`, 18,239 bytes, 129 lines.
- `APPLIED_VERIFIED`: `by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md`, SHA256 `5728140F99B672A2C334F15C3FB17D627E481BF730E8466A2D97EDA272660541`, 12,040 bytes, 98 lines.
- `APPLIED_VERIFIED`: `by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md`, SHA256 `E4236B0D7B0496F170590DA3966F92BF9FE0D9CBCD794148C994FFE0057E4E7A`, 21,912 bytes, 145 lines.
- `APPLIED_VERIFIED`: `by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md`, SHA256 `E6E6FCFBAC2BB44F028E5ABC1DDBAABC03F873FBE45486F6D6A3ADF21FE92C49`, 22,265 bytes, 170 lines.
- `APPLIED_VERIFIED`: `by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md`, SHA256 `F5D957217610B3C4E4AC9121925C8661FCD360C991DC0AF732455EC483649154`, 11,933 bytes, 141 lines.
- `APPLIED_VERIFIED`: `by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md`, SHA256 `638594A880D4BBE62ACEBBCFBBB1E2DBD92BA8915C9D6CD99280FA7106A2B0A8`, 26,127 bytes, 211 lines.
- Validator-owned generated readback: B005 callback checkpoint command `000000017124`, SHA256 `9F6758E7B2254352F0FFA74B66EB418416497AD2EB8A0B88928FF4AE78B73854`, 18,095 bytes, 445 lines; later observed shared checkpoint command `000000017138`, SHA256 `5EC92EE3819D0BDC93C154908A6899412421D31BA74E5417CA9DB0B2E03FAE0E`, 18,097 bytes, 445 lines. Both have one UID0003O0 occurrence, one constructor definition, and zero UID0003O0 empty markers. B005 did not edit this file.
- Renamed/created/deleted ordinary files: none. Every ordinary lease was taken immediately before its edit/validator and released immediately afterward; current lease readback shows no B005 lease.
- IDA mutations, coverage edits, generated/tracker/audit/supervisor/goal/validator-state changes, and report execution by B005: none.
- Supervisor Gate 2B changed and saved `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` only after creating the timestamped pre-0003O0 backup recorded above; no B005 IDA mutation occurred.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Fresh supervisor Gate 1 passed exact report SHA `EB58D1E3792F9E2F79CD74E0EC480BCAECD18CCD081002ECA769A2442F51A62C` before resumed implementation.
- [x] UID0003O0 target C3O0-01 through C3O0-19 independently reread at report-level detail; preserved implementation is `APPLIED_VERIFIED`.
- [x] Additional target UIDs remain none; support edits claim no direct/additional report coverage.
- [x] Target is `92/94` with exact formal/summary and `Nested:0`; owner/emitter/reconstructable/position are preserved.
- [x] UID0000DC is `90/92` with exact class/layout/constructor evidence, preserved history, and no duplicate child body.
- [x] UID0001WJ is `92/93` with source-ready `SnowParticleEntry`, natural padding, and exact Snow object extent.
- [x] Bounded no-score support updates are applied/read back for UID0000G1, UID0000P8, UID0000NR, UID0001O0, UID0001O1, UID0002Z9, UID0003O1, and UID0003O2.
- [x] Historical assumptions remain labeled historical/rejected rather than deleted.
- [x] Exact bytes/hashes/caller/vptr/helper/layout/padding/EH/negative evidence is preserved.
- [x] Current canonical WeatherLayerPane route and historical dedicated Snow provenance are preserved.
- [x] Exact target managed C++ remains only in UID0003O0; routers, aggregates, vtable data, generated files, and separately owned method formals contain no duplicate constructor body.
- [x] Third-party import directive is not applicable.
- [x] Supervisor Gate 2B applied or explicitly dispositioned every IDA table row, verified the complete readback, and saved the IDB; B005 performed no mutation.
- [ ] Supervisor must apply exact manual coverage payloads; B005 leaves this unchecked.
- [x] Each ordinary file was leased only immediately before editing and released immediately after its serial scoped validator.
- [x] Ten scoped file validators ran serially during this accepted callback; the unchanged target retained its prior passing command.
- [x] Generated `WeatherLayerPane.cpp` callback command `000000017124` and later shared command `000000017138` each contain one UID0003O0 body and zero UID0003O0 empty markers.
- [x] Every C3O0 ledger row and destination hash is reconciled after readback.
- [x] Wave2/Wave3 material remains ignored as stale.
- [x] The preserved target/class revisions and generated side effect independently passed supervisor Gate 2A after fresh Gate 1.

Implementation callback pass:

- [x] Fresh repaired report accepted by supervisor for implementation at exact SHA `EB58D1E3792F9E2F79CD74E0EC480BCAECD18CCD081002ECA769A2442F51A62C`; revoked prior acceptance was not reused.
- [x] All B005-owned accepted target/support facts are incorporated without summarization loss.
- [x] Target and support metadata/C++ boundaries are independently verified by B005 readback and supervisor Gate 2A.
- [x] Historical/stale assumptions and negative evidence are preserved.
- [x] Claim ledger is updated claim by claim with destination hashes and verification state.
- [x] Ordinary-file leases were acquired only immediately before edits and released immediately afterward.
- [x] Scoped validators ran serially and command IDs/results are recorded.
- [x] Generated output was independently reread and counts/hash are recorded.
- [x] Supervisor-owned IDA changes are complete and recorded only from supervisor live readback/save evidence; B005 performed none.
- [ ] Supervisor-owned manual coverage remains pending or is recorded only from supervisor confirmation; B005 edits none.
- [x] No report execution/lifecycle command was run, probed, or dry-run by B005.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000017170","destination_path":"executed-b-agent-research/B005/0003O0-SnowingLayerPaneConstructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003O0-SnowingLayerPaneConstructor-empty-emitter-source-quality.md","timestamp":"2026-07-24T09:04:13-04:00","uid":"0003O0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
