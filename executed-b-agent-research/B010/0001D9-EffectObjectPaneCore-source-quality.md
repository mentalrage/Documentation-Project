** TARGET-REPORT-UID:0001D9 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0001D9 EffectObjectPaneCore Source-Quality Research

## Finalized Report / Current Recommendation
- Final recommendation: convert [UID:0001D9] `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md` from a reconstructable/comment-only emitting aggregate into a non-emitting split/container page owned by [UID:000049] `EffectObjectPane`.
- Recommended target metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000049`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.
- Reason: the range is not one source method. Live MCP session `60724697` confirms it contains constructor, ordinary destructor child, timer-start child, bounds helper, frame-bounds helper, timer/update handler, and render helper bodies separated by padding and vtable data refs. The remaining source-bearing methods need exact child pages; the parent should index the split and preserve range evidence rather than emit a monolithic placeholder or multiple method bodies.
- Exact child-page split recommended:
  - `0x005387b0-0x0053887c` `EffectObjectPaneConstructor`
  - existing [UID:0002QV] `0x00538880-0x0053889f` `EffectObjectPaneNonDeletingDestructor`
  - existing [UID:0001DA] `0x005388a0-0x005388b4` `EffectObjectPaneStartIdleTimer`
  - `0x005388c0-0x00538956` `EffectObjectPaneGetEffectBounds`
  - `0x00538960-0x005389c9` `EffectObjectPaneGetFrameBounds`
  - `0x005389d0-0x00538aef` `EffectObjectPaneUpdateEffectAnimation`
  - `0x00538af0-0x00538baa` `EffectObjectPaneRenderEffect`
- Implementation callback status: applied to the accepted target/support by-* docs, scoped validators completed, leases released, and the artifact is returned for supervisor verification/execution. B010 did not run `execute_report`, lifecycle/archive commands, registry lifecycle commands, manual report moves, generated-file edits, coverage-report edits, validator-state edits, or supervisor-ledger edits.

## Supporting Research
- Assignment source: `tools/leaser/Agents/Agent-B010/goal.md`, target UID `0001D9`, report path `tools/leaser/Agents/Agent-B010/research/0001D9-EffectObjectPaneCore-source-quality.md`.
- Skill used: project-level `ntk-b-agent-workflow`; required references checked: B-agent research/implementation workflow, report template, score-blocker audit standard, and by-structure guidance.
- MCP source: live restored IDA MCP database/session `60724697`.
- Current MCP health: command `102` `server_health` returned `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.
- Current target/support docs checked: target UID0001D9, `by-class/EffectObjectPane.md`, `by-file/Effects.md`, existing children UID0002QV/UID0001DA/UID00023H/UID000351/UID0002WO/UID000382, `EffectInfo`, `EffectFrameRecord`, `EffectObjImageLibRenderEffectFrame`, and `MapPaneCreateEffectObjectPane`.
- Generated context checked: `auto-generated/NexusTK/render/Effects.cpp` was refreshed by validator command `000000006160` at `2026-07-04T05:57:51-04:00`; it contains the class-level UID000049 withheld-source comment and no UID0001D9-specific emitted body or empty marker. Coverage/research tracker files were read only.
- Historical reports/leads checked: B001 UID0002QV destructor report, B002 UID0001DA timer report, B002 UID00017M render-frame report, B007/B008 UID000232 object-effect reports, and B015 UID000351 vtable-data report. They were treated as leads and cross-checks, not substitutes for current MCP.
- Implementation boundary: historical initial report-only phase made no by-* edits. The current post-callback artifact records edits to the accepted target/support docs only; no missing exact child pages were created because the supervisor excluded child-page creation from this callback.
- Forbidden commands observed: no `idb_open`, `idb_close`, manual generated edits, coverage edits, lifecycle/archive commands, registry lifecycle commands, manual report moves, dry-run execute variants, or `execute_report`. Scoped file validators were run only for edited by-* files.

## Target
- Target UID: `0001D9`.
- Target path: `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`.
- Current target metadata after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000049`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`.
- Current formal C++ state after callback: exact blank formal `RECONSTRUCTION_CPP CODE` block; the old comment-only parent output was removed.
- Current classification after callback: non-emitting split/container/index page for EffectObjectPane core methods. Exact source-bearing child pages should own constructor, bounds, frame-bounds, update/timer, and render methods when later authorized.
- Current lifecycle state: B010 has completed the implementation callback and returns this artifact for supervisor Gate 2 verification and execution. B010 has not run supervisor lifecycle commands.

## Executive Recommendation
- Update UID0001D9 to a non-emitting split/container page at `88/91`.
- Remove the current comment-only formal code route from the target page by blanking `RECONSTRUCTION_CPP CODE` and clearing `RECONSTRUCTABLE`/`EMITTER_UIDS` as recommended. A comment-only formal C++ block on a reconstructable aggregate is not a source body.
- Add an explicit function inventory with the seven method ranges and current child ownership state.
- Recommend exact child pages for the five unsplit source-bearing functions in this range: constructor, effect-bounds helper, frame-bounds helper, update/timer handler, and render helper.
- Keep direct owner [UID:000049] `EffectObjectPane`; keep source placement under [UID:0000IZ] `NexusTK/render/Effects.cpp`.
- Do not emit a monolithic C++ body in UID0001D9. The range spans multiple C++ members, adjusted-base dispatch, and padding, so one formal body would be source-shaped incorrectly even if each individual method can later become reconstructable.

## Supervisor Active Recheck
- Current conversation history first assigned UID0001D9 as report-only research, then supervisor Gate 1 passed and authorized this implementation callback for the same report artifact.
- Supervisor restored MCP and instructed B010 to use live session `60724697`. B010 used that database parameter on every successful MCP evidence call in this pass.
- MCP schema corrections: call `101` omitted the required `database` parameter and call `103` used stale `lookup_funcs` `addrs` syntax; both were immediately corrected. Evidence-bearing calls are `102` and `104` through `112`.
- Report path did not exist before the initial report-only pass; this post-callback artifact remains in B010's own `research/` folder pending supervisor execution.

## Inference Research Guidance Check
- By-structure guidance prefers the narrow semantic owner when a class method or class method cluster is proven. UID0001D9's direct semantic owner is [UID:000049] `EffectObjectPane`; source-file route is [UID:0000IZ] `Effects`.
- By-structure guidance also rejects comment-only source for a reconstructable target when the target is only an index/container. UID0001D9 is exactly that case after current MCP recheck.
- First-draft C++ is not recommended for the parent target because the parent range is a multi-function aggregate. Exact child pages are the appropriate reconstruction units.
- Original source names are not claimed for unresolved method names. `EffectObjectPaneGetEffectBounds`, `EffectObjectPaneGetFrameBounds`, `EffectObjectPaneUpdateEffectAnimation`, and `EffectObjectPaneRenderEffect` are descriptive source-quality names grounded in behavior and current support docs.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / blocker effect |
| --- | --- | --- | --- |
| Aggregate vs single method | MCP `lookup_funcs` command `104` reports function starts at `0x005387b0`, `0x00538880`, `0x005388a0`, `0x005388c0`, `0x00538960`, `0x005389d0`, and `0x00538af0`; `get_bytes` command `107` confirms padding around existing children and after `0x00538baa`. | Treat UID0001D9 as a split/container page. | Reject a single formal C++ body in the parent. Reject "multi-method source body" as non-source-shaped. |
| Direct owner | Constructor/destructor vtable stores target `EffectObjectPane` vtables; render/update/bounds methods consume fields copied by the constructor; support docs already attach the class to Effects. | Direct owner [UID:000049] `EffectObjectPane`. | Reject MapPane, EffectObjImageLib, TimerMgr, LightingObjectPane, and AttachedObjectPane as direct owners; they are callers/callees/base/dependencies. |
| Source placement | `by-file/Effects.md` owns EffectObjectPane class-level staging; generated `Effects.cpp` has UID000049 class-level comment. | Source route [UID:0000IZ] `NexusTK/render/Effects.cpp`. | Reject standalone helper file and EffectObjImageLib source placement. EffectObjImageLib owns frame rendering, not the pane methods. |
| Existing children | UID0002QV destructor, UID0001DA StartIdleTimer, UID00023H IsLooping, UID000351 vtable, UID0002WO pool storage, and UID000382 scalar deleting destructor already document adjacent/exact class artifacts. | Preserve existing child ownership and cross-link them from the parent inventory. | Reject duplicating those bodies/data in UID0001D9. |
| Constructor fields | Decompile command `108` copies `EffectInfo +0x00` to complete offset `+0x148`, copies one 24-byte frame-sequence header into `+0x12c..+0x143`, initializes `+0x144` to `-1`, sets `+0x14c` from nonnegative range fields, stores compact flag at `+0x14d`, and clears `+0x14e`. | Create exact constructor child; document field mapping and provisional signature. | First-draft constructor C++ remains unsafe because final constructor signature and the selected-sequence parameter names are not original-symbol proven. |
| Bounds helpers | Decompile commands `111` and `112` validate current-frame guard against frame count, `0x10` stride frame-record use, fallback empty rect, and `GetSpriteBounds` call. Command `111` also gets pane position and calls virtual slot `+44` after offsetting. | Create exact bounds child pages with method-specific no-code proofs until virtual signatures and return type are finalized. | Reject stuffing these methods into the parent; reject raw helper labels in source. |
| Update/timer handler | Decompile command `109` shows TimerHandler-adjusted `this` semantics: fields are complete-object offsets after subtracting `0xa4`; event `1` advances frames, event `2` clears looping, event `0` removes the pane, and scheduling uses timer manager `0x67AB80`. | Create exact `EffectObjectPaneUpdateEffectAnimation` child with adjusted-view/source-signature caveat. | First-draft C++ remains unsafe until the source event-handler signature and adjusted-base declaration style are finalized. |
| Render helper | Decompile command `110` shows current-frame guard, frame-record forwarding to `EffectObjImageLib::RenderEffectFrame`, optional overlay gate through active map/render context, and use of `g_pEffectObjImageLib`. | Create exact `EffectObjectPaneRenderEffect` child; it can call documented `EffectObjImageLib::RenderEffectFrame` once its own signature and render-context types are formalized. | Reject EffectObjImageLib ownership of the caller. Reject raw `unk_69B44C` in source; support docs name it `g_pEffectObjImageLib`. |
| Generated state | `auto-generated/NexusTK/render/Effects.cpp` contains UID000049 class-level withheld-source comment and no UID0001D9 target body/marker. | Record that active generated output does not currently emit UID0001D9-specific source; the callback should not manually edit generated files. | Reject stale wording that UID0001D9 is currently an emitted empty marker in `Effects.cpp`. |

## Evidence Standards Used
- Current MCP-backed facts are primary evidence for function starts, xrefs, callees, bytes, and decompiles.
- Existing by-* docs are support evidence for names and ownership, not a substitute for the current MCP pass.
- Generated C++ is treated as route/status evidence only. It is not used to infer source names when binary/support evidence disagrees.
- Historical B-agent reports are treated as leads and implementation history. Current MCP session `60724697` supersedes stale conclusions where conflicts exist.
- Raw labels such as `sub_`, `unk_`, `dword_`, or decompiler local names are acceptable in evidence sections only. They are rejected for recommended source-facing output.

## Evidence Checked
- MCP command `102`: `server_health` for database `60724697`, status OK, Hex-Rays ready.
- MCP command `104`: `lookup_funcs` for `0x005387b0`, `0x00538880`, `0x005388a0`, `0x005388c0`, `0x00538960`, `0x005389d0`, `0x00538af0`, and successor `0x00538bb0`.
- MCP command `105`: `xrefs_to` for the same starts; constructor and StartIdleTimer each have one code xref from `0x0050ea30`; destructor has zero direct xrefs; bounds/update/render have vtable data xrefs; IsLooping has six code xrefs from MapPane/local-player effect paths.
- MCP command `106`: `callees` for the seven UID0001D9 range functions.
- MCP command `107`: `get_bytes` for `0x0053887c` size `68` and `0x00538baa` size `6`, confirming padding and adjacent child bytes.
- MCP commands `108` through `112`: decompile for constructor, update/timer handler, render helper, effect-bounds helper, and frame-bounds helper.
- Local docs: target UID0001D9, `EffectObjectPane`, `Effects`, `EffectInfo`, `EffectFrameRecord`, `EffectObjImageLibRenderEffectFrame`, `MapPaneCreateEffectObjectPane`, and existing exact children/artifacts listed above.
- Generated docs/files: `auto-generated/NexusTK/render/Effects.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md` read only.

## Current Target State
- Target page now records `88/91`, owner UID000049, `RECONSTRUCTABLE:FALSE`, blank emitter, blank emitter position, and blank formal C++.
- The target summary now states the page is a non-emitting split/container for the exact constructor, destructor child, StartIdleTimer child, bounds, frame-bounds, update/timer, render, and successor IsLooping ranges.
- Active generated `Effects.cpp` after validation is refreshed at validator command `000000006235`, timestamp `2026-07-04T11:58:04-04:00`, `validator-refresh-source: deferred-generated-refresh`; it shows UID000049 class-level withheld-source text and no UID0001D9-specific body or empty marker.
- Support docs now resolve the route: `by-class/EffectObjectPane.md` records UID0001D9 as a non-emitting split/container with missing child plan, and `by-file/Effects.md` routes UID0001D9 under `Effects.cpp` as a split/container.
- Remaining confidence caps are method-local and child-scoped: constructor source signature, bounds helper virtual signatures/return types, TimerHandler adjusted event-handler signature, render context/overlay type spelling, and final names for byte `+0x14e` and float `+0x11c`.

## Function / Child Inventory
| Range / Item | Current UID / Path | Role | Current state | Recommendation |
| --- | --- | --- | --- | --- |
| `0x005387b0-0x0053887c` | covered only by UID0001D9 parent | `EffectObjectPane` constructor | unsplit source-bearing method | create exact child `EffectObjectPaneConstructor`; owner/emitter UID000049; method-specific no-code proof until signature is safe |
| `0x00538880-0x0053889f` | [UID:0002QV] `EffectObjectPaneNonDeletingDestructor` | ordinary complete-object destructor | existing exact child | keep child; parent links to it |
| `0x005388a0-0x005388b4` | [UID:0001DA] `EffectObjectPaneStartIdleTimer` | schedules timer event `1` through inherited `+0xa4` TimerHandler view | existing source-ready child | keep child; parent links to it |
| `0x005388c0-0x00538956` | covered only by UID0001D9 parent | computes/updates effect bounds from current frame | unsplit source-bearing method | create exact child `EffectObjectPaneGetEffectBounds`; no parent C++ |
| `0x00538960-0x005389c9` | covered only by UID0001D9 parent | copies current frame bounds to two outputs/fallback empty rect | unsplit source-bearing method | create exact child `EffectObjectPaneGetFrameBounds`; no parent C++ |
| `0x005389d0-0x00538aef` | covered only by UID0001D9 parent | TimerHandler-adjusted animation/update event handler | unsplit source-bearing method | create exact child `EffectObjectPaneUpdateEffectAnimation`; no parent C++ |
| `0x00538af0-0x00538baa` | covered only by UID0001D9 parent | forwards frame record to effect image renderer with optional overlay | unsplit source-bearing method | create exact child `EffectObjectPaneRenderEffect`; no parent C++ |
| `0x00538bb0-0x00538bb7` | [UID:00023H] `EffectObjectPaneIsLooping` | returns byte `+0x14c` | existing successor child outside parent range | keep separate |
| `0x006205f8-0x006206ac` | [UID:000351] `EffectObjectPaneVtableData` | class vtable/RTTI data | existing class artifact | keep separate |
| `0x0069b90c-0x0069b934` | [UID:0002WO] `EffectObjectPanePoolStaticStorage` | pool static storage | existing class artifact | keep separate |
| `0x0053d100-0x0053d197` | [UID:000382] scalar deleting destructor | compiler deleting wrapper/pool return | existing wrapper artifact | keep separate |

## Direct Xref / Caller Inventory
| Address / Item | Current MCP result | Meaning |
| --- | --- | --- |
| `0x005387b0` | command `105`: one code xref at `0x0050eacf` in `sub_50EA30` | MapPane create helper constructs `EffectObjectPane`. |
| `0x00538880` | command `105`: zero direct xrefs | ordinary destructor body retained without direct call/table xref; existing UID0002QV covers this. |
| `0x005388a0` | command `105`: one code xref at `0x0050eb14` in `sub_50EA30` | MapPane create helper starts the idle/animation timer after construction. |
| `0x005388c0` | command `105`: data xref at `0x0062066c` | virtual-method table entry for bounds/update behavior. |
| `0x00538960` | command `105`: data xref at `0x0062064c` | virtual-method table entry for frame-bounds behavior. |
| `0x005389d0` | command `105`: data xref at `0x006206a8` | adjusted TimerHandler/event vtable entry. |
| `0x00538af0` | command `105`: data xref at `0x00620658` | virtual render method entry. |
| `0x00538bb0` | command `105`: six code xrefs at `0x0050e397`, `0x0050e42d`, `0x0050e8fa`, `0x0050e9a0`, `0x005a2f48`, `0x005a2fa9` | MapPane/local-player effect reuse checks call `EffectObjectPane::IsLooping()`. |

## Positive Evidence Summary
- The target range is exact and live: seven recognized function starts lie inside `0x005387b0-0x00538baa`, followed by six `0xcc` bytes.
- Constructor evidence ties the range to `EffectObjectPane`: it writes the three class vtables, stores `m_effectId` at `+0x148`, copies the selected `EffectInfo` frame header to `+0x12c..+0x143`, initializes current frame at `+0x144`, and sets loop byte `+0x14c`.
- Existing children already own destructor and timer-start bodies, proving the parent is not the right emission unit.
- Bounds, update, and render methods all consume the constructor-copied frame header and `EffectFrameRecord` entries.
- `EffectFrameRecord` and `EffectInfo` support pages now provide usable source-facing type names and field roles for the child pages.
- `EffectObjImageLib::RenderEffectFrame` is already first-draft emitted and can be called by the future render child without using raw labels.
- `g_pEffectObjImageLib` is a documented global support owner; raw `unk_69B44C` should not appear in source.

## Negative Evidence Summary
- No evidence supports a single monolithic source body for UID0001D9.
- No evidence supports keeping a comment-only formal C++ block as reconstructable target output.
- No evidence supports moving direct ownership to MapPane: MapPane constructs and schedules the pane but does not own the pane methods.
- No evidence supports moving direct ownership to EffectObjImageLib: it owns frame records/rendering resources, while UID0001D9 owns the pane caller-side consumption.
- No evidence supports TimerMgr ownership of update behavior: TimerMgr is a generic scheduling callee; `EffectObjectPane` owns the event-handler body.
- No evidence supports AttachedObjectPane ownership for this aggregate: AttachedObjectPane is the base class and cleanup dependency, not the derived EffectObjectPane method cluster.
- Generated/simroot output is insufficient to recover original method names and must not be copied where it uses decompiler-style placeholders.
- Raw labels such as `sub_4DE2A0`, `unk_69B44C`, `dword_67A764`, and decompiler locals are rejected for source-facing recommendations.

## Ranked Ownership Analysis
1. [UID:000049] `EffectObjectPane`: accepted. It explains vtable writes, object fields, constructor/update/render/bounds behavior, existing child pages, vtable data, pool storage, and source placement through Effects.
2. [UID:0000IZ] `Effects`: accepted as file/source route only. It owns the physical `NexusTK/render/Effects.cpp` route but is broader than the direct class owner.
3. [UID:00007Q] `MapPane`: rejected as direct owner. It constructs and manages effect panes through `MapPane::CreateEffectObjectPane`, but UID0001D9 methods execute on `EffectObjectPane`.
4. [UID:00004A] `EffectObjImageLib`: rejected as direct owner. It owns `EffectInfo`, `EffectFrameRecord`, `g_pEffectObjImageLib`, and `RenderEffectFrame`; UID0001D9 consumes those dependencies.
5. TimerMgr/TimerHandler support: rejected as direct owner. The update method is called through an adjusted TimerHandler view, but it is still the EffectObjectPane override/handler body.
6. AttachedObjectPane/ObjectPane/LivingObjectPane: rejected as direct owner. They provide base behavior, registry fields, and virtual slots; derived EffectObjectPane owns this aggregate.

## Source Placement
- Direct class owner: [UID:000049] `EffectObjectPane`.
- File route: [UID:0000IZ] `NexusTK/render/Effects.cpp`.
- Current generated route evidence: `auto-generated/NexusTK/render/Effects.cpp` contains UID000049 class-level withheld-source comment and does not currently emit UID0001D9-specific code.
- Recommended parent handling: UID0001D9 should not emit; exact child pages should emit or carry no-code proofs under UID000049/UID0000IZ.
- Future exact child pages should stay in `Effects.cpp`, not in `MapPane.cpp`, `EffectObjImageLib.cpp`, or a standalone helper file.

## First-Draft C++ Recommendation
UID0001D9 should not receive a first-draft source body. The correct formal insertion for the parent after callback is a blank block with `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Target-specific no-code proof:
- The target range spans multiple independent functions and padding. A single C++ method body cannot source-shape constructor, destructor, timer start, bounds, update, and render methods at once.
- Two source-bearing exact children already exist inside the range. Emitting those bodies again through UID0001D9 would duplicate ownership.
- The update function is an adjusted `+0xa4` TimerHandler view. Combining it with complete-object methods in one parent block would obscure the source ABI.
- Remaining unsplit methods require their own exact pages because each has a different signature and confidence cap: constructor signature, bounds virtual signatures, frame-bounds out-parameter contract, event-handler signature, and render-context overlay types.
- Active generated `Effects.cpp` already withholds class-level EffectObjectPane source; adding a monolithic parent body would conflict with the current source route rather than fix it.

## Recommended Target Doc Changes
- Set UID0001D9 metadata to:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:000049`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank `EMITTER_POSITION_OPTIONAL`
  - blank formal `RECONSTRUCTION_CPP CODE`
- Replace the current comment-only formal block with the exact blank formal block shown above.
- Add MCP session `60724697` evidence at report-level detail: health command `102`, function inventory command `104`, xrefs command `105`, callees command `106`, bytes command `107`, and decompile commands `108-112`.
- Replace broad "multi-method aggregate" wording with a resolved split table for constructor, existing destructor child, existing timer-start child, bounds helper, frame-bounds helper, update/timer handler, and render helper.
- Preserve negative evidence rejecting monolithic parent C++, MapPane ownership, EffectObjImageLib ownership, TimerMgr ownership, AttachedObjectPane ownership, raw labels, and generated/simroot decompiler names.
- Add current generated-output fact: active `Effects.cpp` has UID000049 withheld-source text and no UID0001D9-specific body/marker.

## Recommended Support Doc Changes
- `by-class/EffectObjectPane.md`: update the method inventory to state that UID0001D9 should become a non-emitting split/container and that future exact children should own constructor, bounds, frame-bounds, update, and render bodies. Keep `+0x148` as `m_effectId`, `+0x14c` as `m_looping`, and document provisional roles for `+0x11c`, `+0x12c`, `+0x138`, `+0x13c`, `+0x140`, `+0x144`, `+0x14d`, and `+0x14e`.
- `by-file/Effects.md`: update the EffectObjectPane row to say UID0001D9 is a split/container under `Effects.cpp`, not a formal source body, and that exact child pages should be created before source emission.
- Existing child docs UID0002QV, UID0001DA, UID00023H, UID000351, UID0002WO, and UID000382: no mandatory edits unless stale cross-links still imply UID0001D9 should emit their content.
- Optional future support after child creation: add narrow child rows for constructor/bounds/update/render pages in `EffectObjectPane` and `Effects`.
- No support doc should introduce raw `sub_`, `unk_`, `dword_`, or decompiler local names in source-facing signatures.

## Score And Metadata Recommendation
| Item | Pre-callback state | Applied recommendation | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `88` | Current report resolves aggregate split, active generated state, xrefs, callees, bytes, existing children, field roles, and no-code proof. |
| `CONFIDENCE` | `88` | `91` | Live MCP session `60724697` revalidated exact boundaries, xrefs, callees, padding, and decompiles for unresolved functions. |
| `CANONICAL_OWNER` | `000049` | `000049` | EffectObjectPane remains the correct semantic owner. |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` | Parent is an aggregate/container, not an emission unit. Exact children should reconstruct method bodies. |
| `EMITTER_UIDS` | `000049` | blank | Parent should not emit. |
| Formal C++ | comment-only aggregate marker | blank | Comment-only formal source is not useful for a non-emitting split parent. |

## Open Questions With Attempted Resolution
- Constructor signature: investigated with MCP decompile command `108` and MapPane create helper docs. Best source shape uses `EffectInfo` descriptor/sequence selection and compact flag, but exact original argument names and by-reference spelling are not final. This blocks constructor-child first-draft C++ only, not the parent split.
- Bounds helper names/signatures: investigated with commands `111` and `112`. Behavior is clear, but exact virtual method names, return types, and output parameter names remain not original-symbol proven. This blocks child C++ only.
- Update/timer handler signature: investigated with command `109` and UID0001DA TimerHandler support. The adjusted `+0xa4` receiver is proven, but the source event-handler declaration style is not final. This blocks child C++ only.
- Render-context overlay types: investigated with command `110` and UID00017M support. `EffectObjImageLib::RenderEffectFrame` call readiness is resolved, but the caller-side render context fields at `a2+0x3dc/+0x3e0` and `EffectObjectPane +0x11c` are still provisional. This blocks child C++ only.
- Generated state: checked active `Effects.cpp`; UID0001D9 is not currently emitted as a specific marker. The pre-callback source-quality issue was the target page's reconstructable/comment-only route; the callback has converted that route to non-emitting split/container state.

## Final Recommendation
Implementation callback completed: UID0001D9 is now a non-emitting split/container page at `88/91`, class/file support docs point future work at exact children, and the parent emits no C++. Child-page creation remains excluded from this callback by supervisor scope; future creation of `EffectObjectPaneConstructor`, `EffectObjectPaneGetEffectBounds`, `EffectObjectPaneGetFrameBounds`, `EffectObjectPaneUpdateEffectAnimation`, and `EffectObjectPaneRenderEffect` requires explicit authorization. Return this artifact for supervisor verification and execution.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001D9 is a multi-function aggregate, not one method. | high | MCP `lookup_funcs` command `104` lists seven starts in range. | Target `Covered Ranges` and `2026-07-04 B010 Split/Container Callback Evidence` | incorporate | applied |
| C02 | Parent should be non-emitting with blank formal C++. | high | Existing exact children plus no-code proof and generated UID000049 withheld-source state. | Target metadata/formal block | incorporate | applied |
| C03 | Direct owner remains EffectObjectPane UID000049. | high | Vtable writes, field use, existing class docs, child docs. | Target metadata/status; `by-class/EffectObjectPane.md` responsibility/reconstruction state | incorporate | applied |
| C04 | Source file route remains Effects.cpp UID0000IZ. | high | `by-file/Effects.md`; generated `Effects.cpp` UID000049 comment. | Target source placement; `by-file/Effects.md` inventory/evidence | incorporate | applied |
| C05 | Constructor child should be split at `0x005387b0-0x0053887c`. | high | MCP command `108` constructor decompile; command `104` size `0xcc`. | Target covered ranges/evidence; `by-class/EffectObjectPane.md` method table; `by-file/Effects.md` UID0001D9 route | incorporate | applied |
| C06 | Existing destructor child UID0002QV should remain separate. | high | Existing child doc; MCP command `104`/`105` confirms function and zero direct xrefs. | Target function inventory and support doc method/cross-link state | already-present | already-present |
| C07 | Existing StartIdleTimer child UID0001DA should remain separate and source-ready. | high | Existing child doc; MCP command `105` caller at `0x0050eb14`; command `106` callee `0x5975e0`. | Target function inventory and support doc method/cross-link state | already-present | already-present |
| C08 | Bounds helpers need exact child pages. | high | MCP commands `111`/`112`; vtable data xrefs command `105`. | Target covered ranges/evidence; `by-class/EffectObjectPane.md` method table; `by-file/Effects.md` route note | incorporate | applied |
| C09 | Update/timer handler needs exact child page with adjusted-view caveat. | high | MCP command `109`; UID0001DA/TimerHandler support. | Target covered ranges/evidence; `by-class/EffectObjectPane.md` method table; `by-file/Effects.md` route note | incorporate | applied |
| C10 | Render helper needs exact child page and may call documented `EffectObjImageLib::RenderEffectFrame`. | high | MCP command `110`; UID00017M first-draft emitted support. | Target covered ranges/evidence; `by-class/EffectObjectPane.md` method table; `by-file/Effects.md` route note | incorporate | applied |
| C11 | `g_pEffectObjImageLib` is the source-facing name for `0x0069b44c`. | high | `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md`; render decompile refs. | Target render evidence/dependency text; support docs keep EffectObjImageLib as dependency not owner | incorporate | applied |
| C12 | Constructor fields include `+0x12c` frame records, `+0x138` count, `+0x13c/+0x140` loop bounds, `+0x144` current frame, `+0x148` effect id, `+0x14c` loop byte, `+0x14d` compact flag, `+0x14e` cleared byte. | medium-high | MCP command `108`; `EffectInfo`/`EffectFrameRecord` docs. | Target command `108` evidence; `by-class/EffectObjectPane.md` responsibility/method table | incorporate | applied |
| C13 | Active generated `Effects.cpp` does not contain UID0001D9-specific emitted source. | high | Generated header after callback command `000000006235`; grep shows UID000049 only and no UID0001D9 marker. | Target evidence/current state; report validator results | incorporate | applied |
| C14 | MapPane ownership is rejected. | high | Constructor/StartIdleTimer callers from MapPane; methods execute on EffectObjectPane. | Target negative evidence; `by-class/EffectObjectPane.md`; `by-file/Effects.md` B010 callback note | incorporate | applied |
| C15 | EffectObjImageLib ownership is rejected for UID0001D9. | high | Render caller consumes `EffectObjImageLib`; UID00017M owns callee. | Target negative evidence; `by-file/Effects.md` asset/runtime separation | incorporate | applied |
| C16 | Raw labels are rejected for source-facing output. | high | Workflow/report standard; evidence has source-facing support names. | Target negative evidence; support-doc route notes avoid raw source labels | incorporate | applied |
| C17 | Five missing exact child pages should not be created in this callback. | high | Supervisor callback scope explicitly excludes child-page creation; support docs only record the future split plan. | Report ledger/checklist; target/support docs record future child plan without new files | exclude-with-reason | excluded: supervisor callback scope |

## Implementation Tracking Checklist
- [x] Target metadata set to `88/91`, owner `000049`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank emitter position. Applied in `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`; validator `000000006233` confirmed completion/confidence and registry reconstructable/emitter updates.
- [x] Target formal C++ replaced with exact blank `RECONSTRUCTION_CPP CODE` block; no comment-only parent output remains. Applied in target; validator `000000006233` recorded registry block -> blank.
- [x] Target function inventory updated with constructor, existing destructor child, existing StartIdleTimer child, bounds helper, frame-bounds helper, update/timer handler, render helper, and successor IsLooping child. Applied in target `Covered Ranges` and `2026-07-04 B010 Split/Container Callback Evidence`.
- [x] Target MCP evidence section records session `60724697` commands `102`, `104`, `105`, `106`, `107`, `108`, `109`, `110`, `111`, and `112`. Applied in target `2026-07-04 B010 Split/Container Callback Evidence`.
- [x] Target generated-state wording says active `Effects.cpp` currently has UID000049 class-level withheld-source text and no UID0001D9-specific body/marker. Applied in target; post-validator generated header `000000006235` confirms no UID0001D9 marker.
- [x] Target negative evidence preserves rejection of monolithic parent C++, MapPane ownership, EffectObjImageLib ownership, TimerMgr ownership, AttachedObjectPane ownership, raw labels, and generated/simroot decompiler names. Applied in target B010 evidence section and support docs.
- [x] `by-class/EffectObjectPane.md` support note updated if stale with parent split/container route and missing child plan. Applied in responsibility, method table, reconstruction state, and B010 callback note; validator `000000006234` passed.
- [x] `by-file/Effects.md` support note updated if stale with UID0001D9 split/container route under `Effects.cpp`. Applied in Proposed Contents, empty-emitter callback table, and B010 evidence note; validator `000000006235` passed.
- [x] Existing child docs left unchanged unless stale cross-link contradictions are found. Already present at same-or-greater detail; no direct contradictions required child-page edits, and supervisor scope excluded child-page creation.
- [x] Scoped validators run for every edited by-* doc during callback only. Commands `000000006233`, `000000006234`, and `000000006235` all exited `0` with `ok:1`.
- [x] No manual generated files, coverage reports, lifecycle/archive files, validator state, or supervisor ledgers edited. Scoped validators refreshed generated/project-level state as reported below; B010 did not hand-edit those files and did not run lifecycle commands.

## Validator Results
- `python .\tools\validator.py --mode file --file by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md --apply --queue-timeout 240`
  - command_id: `000000006233`
  - command_timestamp: `2026-07-04T11:57:47-04:00`
  - exit code: `0`
  - ok: `1`
  - notable output: completion update `88`, confidence update `91`, reconstructable `true -> false`, emitter `000049 ->` blank, source block `block -> blank`; missing-ref warning for UID000382; generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-class/EffectObjectPane.md --apply --queue-timeout 240`
  - command_id: `000000006234`
  - command_timestamp: `2026-07-04T11:57:54-04:00`
  - exit code: `0`
  - ok: `1`
  - notable output: missing-ref warnings for UID000382; generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file/Effects.md --apply --queue-timeout 240`
  - command_id: `000000006235`
  - command_timestamp: `2026-07-04T11:58:04-04:00`
  - exit code: `0`
  - ok: `1`
  - notable output: missing-ref warnings for LakeEffecter child UIDs `0003HA`, `0003HC`, `0003HB`, and `0003HD`; generated refresh deferred.
- Generated/queue check: final `python .\tools\validator.py --queue-status` returned command_id `000000006250`, timestamp `2026-07-04T12:02:39-04:00`, worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Generated freshness: `auto-generated/NexusTK/render/Effects.cpp` header now shows `validator-command-id: 000000006235`, `validator-refreshed-at: 2026-07-04T11:58:04-04:00`, `validator-refresh-source: deferred-generated-refresh`. Grep shows UID000049 class-level withheld-source text and no UID0001D9-specific body or empty marker.

## Changed Files
- Modified by B010:
  - `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`
  - `by-class/EffectObjectPane.md`
  - `by-file/Effects.md`
  - `tools/leaser/Agents/Agent-B010/research/0001D9-EffectObjectPaneCore-source-quality.md`
- Validator-owned/generated side effects reported by scoped validators:
  - projected stats updated by validators;
  - `auto-generated/NexusTK/render/Effects.cpp` refreshed to command `000000006235`;
  - generated refresh jobs are caught up per final queue-status command `000000006250`.
- No coverage reports were manually edited.
- No generated files, validator state, lifecycle/archive files, or supervisor ledgers were manually edited by B010.
- Report execution: not run by B010; supervisor-only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000006262","destination_path":"executed-b-agent-research/B010/0001D9-EffectObjectPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0001D9-EffectObjectPaneCore-source-quality.md","timestamp":"2026-07-04T12:07:08-04:00","uid":"0001D9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
