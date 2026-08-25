** TARGET-REPORT-UID:00039W **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID00039W SurfaceMinimapRenderInitializer Source-Quality Report

## Finalized Report / Current Recommendation

This report passed Gate 1 and the accepted implementation callback is complete for [UID:00039W] `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`. B006 edited only the accepted target/support by-* docs, ran scoped validators, released leases, did not run `execute_report`, and now stops for supervisor Gate 2 / supervisor-owned execution.

Implemented disposition: no formal C++ was drafted or emitted for UID00039W. The function is live and source-authored, but the old nonblank Surface emitter route overstated readiness because the modeled receiver is the startup `g_pScreenPane` object while the body also initializes Surface render callback globals, alpha lookup globals, and DirectDraw presentation surfaces. The callback converted UID00039W from an emitting-empty Surface child into a researched, reconstructable, non-emitting target with a target-specific no-code proof. Applied metadata is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.

The old generated empty marker in `auto-generated/NexusTK/render/Surface.cpp` is now historical pre-callback evidence of the metadata problem, not current output. After validation, generated `Surface.cpp` refreshed with validator command `000000006355` at `2026-07-04T13:40:42-04:00`; `rg` found no `UID00039W` / `SurfaceMinimapRenderInitializer` occurrence.

## Supporting Research

Local documentation reviewed:

- Target page `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`.
- Aggregate parent `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`.
- Surface support `by-file/Surface.md`, ScreenPane support `by-file/ScreenPane.md` and `by-class/ScreenPane.md`, DirectDraw support `by-file/DirectX.md`.
- Related child pages [UID:00039Q] `SurfaceFlipSurfaces`, [UID:00039S] `ScreenPanePresentationModeFlagSetters`, [UID:00039Z] `SurfaceRestoreLostSurfaces`, [UID:00039P] `SurfaceRenderPresentation`, [UID:00039T] `SurfaceDrawTilePresentation`, [UID:00039V] `SurfaceRenderCallbackInitializerRaw`, and [UID:0003A4] `BlitSurfaceToDisplay`.
- Global/support docs for the render callback table, Surface pixel-format flags, alpha lookup table pointers, and `0x0069ba3c` temporary DirectDraw surface slot.
- Generated lead material in `auto-generated/NexusTK/render/Surface.cpp`, refreshed by validator command `000000006307` at `2026-07-04T12:41:41-04:00`, where UID00039W historically appeared as an empty emitter marker before the implementation callback. Current post-callback generated output refreshed by command `000000006355` at `2026-07-04T13:40:42-04:00` and no longer contains UID00039W.

Prior B-agent reports reviewed as historical/source-family evidence:

- `executed-b-agent-research/B008/00039Q-SurfaceFlipSurfaces-source-quality.md`: reroutes the called `0x00557470` helper to `ScreenPane::PrepareDirectDrawPresentation()` and explicitly notes that the UID00039W caller does not automatically reroute UID00039W itself.
- `executed-b-agent-research/B009/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md`: identifies `+0x12c` as ScreenPane presentation-mode state and treats UID00039W's direct clear at `0x00558c86` as field evidence, not automatic ownership proof.
- `executed-b-agent-research/B005/00039Z-SurfaceRestoreLostSurfaces-source-quality.md`: establishes ScreenPane ownership for the restore helper that consumes surfaces created by UID00039W.
- `executed-b-agent-research/B007/0002H7-ApplicationStartup-source-quality.md`: records the startup caller as loading `g_pScreenPane` and calling this function with a receiver-shaped call.
- `executed-b-agent-research/B001/0001G6-SurfacePresentation.md` and `executed-b-agent-research/B005/0000OC-Surface-empty-emitter-family-source-quality.md`: keep the larger Surface presentation family as a mixed-owner review bucket with several children already split or rerouted.

## Target

- UID: `00039W`
- Target path: `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
- Mode: Gate 1-passed implementation callback complete; awaiting supervisor Gate 2 / supervisor-owned execution.
- Current generated output route: UID00039W has no emitter route after callback, and generated `Surface.cpp` no longer contains the former UID00039W empty marker.

## Current Target State

The target now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank optional position, and an empty formal C++ block. Its prose records the live Surface/minimap render-buffer and DirectDraw initializer evidence while rejecting current source emission through either Surface or ScreenPane.

The page no longer treats the call at `0x0055887d` as a generic Surface restore/flip helper. It now identifies the callee as [UID:00039Q] `ScreenPane::PrepareDirectDrawPresentation()`, records that as strong ScreenPane receiver/dependency evidence, and still preserves Surface as the best current research bucket because this body initializes Surface callback/global state.

## Executive Recommendation

Implemented: no standalone `Surface` source body or speculative `ScreenPane` method body was emitted for UID00039W. The range remains one modeled function, Surface remains the best current canonical research bucket, the emitter is blank, and the target carries the accepted no-code proof. Support docs now say UID00039W is live, startup-reached, heavily evidenced, and non-emitting pending a future source-boundary decision for the ScreenPane receiver versus Surface render/global initialization.

## Supervisor Active Recheck

Current MCP-backed evidence was gathered from live IDA MCP session `nexustk_supervisor_20260704` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

Freshness checks:

- `idb_list`: one active worker session, `session_id:nexustk_supervisor_20260704`, `is_active:true`, `is_analyzing:false`, worker PID `10024`.
- `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- Bounded `lookup_funcs` using current schema key `queries`: `0x00558840` resolves to `sub_558840`, size `0x723`; `0x00558f63` is not a function; `0x004f6199` resolves inside `sub_4F5FB0`, size `0x4e0`.

Earlier MCP schema mismatch attempts used `session_id` and `addrs`; those returned schema errors only and are not evidence failures. The usable current calls used `database:nexustk_supervisor_20260704` and `queries`.

## Inference Research Guidance Check

Generated output is lead material only. The pre-callback empty marker in `auto-generated/NexusTK/render/Surface.cpp` proved the former metadata/source route was defective, not that a Surface C++ body existed or should be invented. Current post-callback generated output no longer contains UID00039W after command `000000006355`.

The implemented action was metadata and evidence correction, not a body draft. Clearing `EMITTER_UIDS` is the source-quality repair because it stopped the empty Surface emission while preserving the function as reconstructable and fully researched.

## Heuristic / Inference Reanalysis And Validation

Aggregate-versus-child emission: UID00039W is already an exact child page, not an aggregate parent. The modeled range is a single 1827-byte function with internal DirectDraw setup, callback-family selection, table allocation, state clears, and error throws. There is no evidence for carving out child by-memory pages inside this function in the current pass.

No-route analysis: UID00039W is not dead code and not a no-route raw helper. It has one direct startup caller at `0x004f6199`. The no-code proof is not a liveness failure. It is a source-placement and emitter-route failure: the startup call passes `g_pScreenPane` as the receiver, while the current emitter is `Surface.cpp`.

Owner/emitter implications: the current owner [UID:0000OC] is still the best research bucket because the unique work initializes Surface callback tables, pixel-format flags, alpha lookup globals, and render surface support. However, the receiver and many fields are ScreenPane-shaped. That split prevents safe C++ emission through `Surface.cpp` and also prevents a unilateral ScreenPane reroute without a broader presentation-family callback.

Generated empty marker: UID00039W has a nonblank emitter and blank formal C++, so generated output produces an empty marker. That marker should be eliminated by clearing the emitter unless a future callback accepts a complete source body.

Rejected alternatives validated:

- Treating the function as padding or dead code is rejected by the direct startup call and modeled `sub_558840`.
- Treating it as a pure ScreenPane method is premature because the function's heaviest unique work is Surface render/global initialization and related support docs still route the presentation family through Surface.
- Treating it as a pure Surface API is also unsafe because `ecx` is loaded from `g_pScreenPane`, the function writes ScreenPane fields, and the called child [UID:00039Q] is ScreenPane-owned.
- Treating MapPane/minimap context as direct ownership is unsupported by current xrefs.
- Treating DirectX as owner is rejected because DirectDraw is a dependency object, not the semantic owner.
- Emitting raw decompiler C++ is rejected because it would leak `sub_*`, stack descriptor arrays, raw vtable offsets, exception helper shapes, and unresolved field names into source output.

## Evidence Standards Used

Evidence was accepted only when supported by current MCP output, current by-* documentation, or executed B-agent reports. Decompiler output was used for behavior, but source-level naming is treated as inference unless already supported by current docs. Generated files were used only to detect the historical pre-callback empty-emitter state and confirm post-callback freshness.

The report follows the by-structure C++ gate: a reconstructable, high-scoring, nonblank-emitter target with blank C++ must either get formal C++ or receive a concrete no-code proof plus metadata/emitter correction. UID00039W receives the latter recommendation.

## Evidence Checked

- MCP `lookup_funcs`, `server_health`, `get_bytes`, `analyze_function`, `decompile`, `insn_query`, `xref_query`, `find_bytes`, and integer conversion where relevant.
- Local target/support docs for Surface, ScreenPane, DirectX, DirectDraw presentation children, callback globals, alpha lookup globals, and temporary surface slot.
- Executed B reports for UID00039Q, UID00039S, UID00039Z, ApplicationStartup, and SurfacePresentation family context.
- Generated `Surface.cpp` historical pre-callback empty emitter marker, post-callback absence of UID00039W, and generated research tracker context.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| 39W-001 | MCP session `nexustk_supervisor_20260704` is live and IDB-backed for this evidence pass. | 99 | `idb_list`, `server_health status:ok`, bounded `lookup_funcs`. | Target evidence section. | Add current MCP/session facts. | applied: target `IDA MCP Evidence` names session and health. |
| 39W-002 | UID00039W is modeled as `sub_558840` at `0x00558840`, size `0x723` / 1827 bytes, ending before `0x00558f63`. | 99 | MCP `lookup_funcs` and `analyze_function`. | Target range/evidence; aggregate child row. | Add exact range and size. | applied: target range/evidence and parent child row both record `0x723`. |
| 39W-003 | Range is cleanly bounded by three `0xcc` bytes before and thirteen `0xcc` bytes after. | 98 | MCP `get_bytes` at `0x0055883d` and `0x00558f50`. | Target range/padding section. | Add padding proof; no rename/split. | applied: target range table and parent row/change note record padding. |
| 39W-004 | There is one direct startup code xref from `0x004f6199` in `sub_4F5FB0`; the caller loads `g_pScreenPane` as receiver. | 96 | MCP `xref_query`; `insn_query` caller window. | Target caller evidence; ScreenPane support caveat. | Add startup caller/receiver proof. | applied: target evidence and support rows record caller/receiver; ScreenPane support already had startup receiver caveat. |
| 39W-005 | There is no data xref or saved VA/RVA pointer-pattern route to the function start/end/pre-start. | 94 | MCP `xref_query` and `find_bytes` for start/end/pre-start VA/RVA patterns. | Target negative evidence. | Add no-data-pointer route proof. | applied: target MCP evidence and no-code proof record no data/pointer route. |
| 39W-006 | The function calls [UID:00039Q] at `0x0055887d`, now documented as ScreenPane presentation preparation. | 97 | MCP decompile/insn; executed B008 Q report and current Q page. | Target evidence; `by-file/Surface.md`; aggregate row. | Replace stale Surface flip/restore wording. | applied: target, `by-file/Surface.md`, and parent row no longer present UID00039W as a generic Surface restore/flip call. |
| 39W-007 | The function creates/copies DirectDraw presentation surfaces through fields `+0xfc`, `+0x100`, `+0x104`, and `+0x108`. | 96 | MCP decompile and disassembly windows. | Target behavior; ScreenPane field notes. | Add field-offset evidence. | applied: target records all four offsets; ScreenPane class field notes were already present. |
| 39W-008 | The function clears ScreenPane presentation mode byte `+0x12c` at `0x00558c86`; [UID:00039S] owns the setter helpers, not this whole initializer. | 96 | MCP disassembly and B009/current S support. | Target relationship to UID00039S; ScreenPane support. | Add field clear and ownership caveat. | applied/already-present: target records `+0x12c`; ScreenPane file/class and UID00039S already present same-or-greater detail. |
| 39W-009 | The function initializes Surface callback table globals with RGB555/compat and RGB565 families. | 96 | MCP decompile refs to `0x0069b3e0-0x0069b410`; current callback-table doc. | Target behavior; callback-table support if stale. | Add callback-family evidence. | applied/already-present: target records callback table; callback-table support already present and no contradiction found. |
| 39W-010 | The function allocates and fills alpha lookup table globals at `0x0069b3d8` and `0x0069b3dc`. | 95 | MCP decompile loop and current alpha-table support. | Target behavior; alpha lookup support if stale. | Add allocation/fill evidence. | applied/already-present: target records allocation/fill; alpha lookup support already present and no contradiction found. |
| 39W-011 | The temporary DirectDraw surface slot `0x0069ba3c` has exactly four UID00039W xrefs. | 95 | MCP `xref_query`; current temp-slot support doc. | Target evidence; temp-slot support if stale. | Add exact xref list if target lacks it. | applied/already-present: target links correct [UID:0002AK] and lists four refs; temp-slot page already had same detail. |
| 39W-012 | Formal C++ is not safe in this pass because receiver, owner, file route, field names, DirectDraw wrapper types, and helper names remain partly unresolved. | 93 | Combined MCP behavior, current support docs, and prior B reports. | Target no-code proof; First-Draft C++ Recommendation. | Keep formal block blank; add no-code proof. | applied: target `No-Code And Emitter Disposition` carries the proof; formal block remains empty. |
| 39W-013 | Old `EMITTER_UIDS:0000OC` was the source-quality defect because it generated an empty Surface marker. | 97 | Target metadata plus generated `Surface.cpp` empty marker. | Target metadata; report checklist. | Clear `EMITTER_UIDS`; keep reconstructable. | applied: target `EMITTER_UIDS` is blank; generated `Surface.cpp` no longer contains UID00039W after command `000000006355`. |
| 39W-014 | Recommended score after evidence update is `COMPLETION:88`, `CONFIDENCE:90`. | 90 | High behavior confidence, capped by source-placement/name uncertainty. | Target metadata; aggregate/support rows. | Apply scores if callback accepted. | applied: target metadata and parent child row now show `88/90`. |

## Positive Evidence Summary

UID00039W is a real, modeled, startup-reached initializer. MCP identifies `sub_558840` at `0x00558840` with size `0x723`, and decompilation/disassembly show a coherent DirectDraw presentation setup sequence.

Confirmed behavior includes:

- Startup path loads `g_pScreenPane` and calls the function at `0x004f6199`.
- Function immediately calls [UID:00039Q] `ScreenPane::PrepareDirectDrawPresentation()`.
- It constructs DirectDraw surface descriptors using ScreenPane dimensions at `+0x112` and `+0x114`.
- It creates or stores surfaces at `+0x108`, stack temporary `v32`, `+0x104`, `+0xfc`, and copies `+0xfc` into `+0x100`.
- It optionally creates/attaches/configures the global temporary slot `0x0069ba3c`.
- It obtains display/pixel-format information from DirectDraw and selects RGB555/compat or RGB565 callback families.
- It fills the global Surface callback table at `0x0069b3e0-0x0069b410`.
- It allocates and fills alpha lookup tables at `0x0069b3d8` and `0x0069b3dc`.
- It locks/unlocks surfaces via DirectDraw virtuals, clears ScreenPane presentation state at `+0x12c`, clears other presentation flags/rects, and calls a virtual invalidation/draw route at `this+0x2c`.

## IDA MCP Facts

- Session: `nexustk_supervisor_20260704`
- Health: `status:ok`, Hex-Rays ready, auto-analysis ready.
- Function: `sub_558840`
- Start: `0x00558840`
- Size: `0x723` / 1827 bytes
- End boundary: next non-padding function begins at `0x00558f70`; `0x00558f63` is not a function.
- Pre-padding: `0x0055883d-0x00558840`, three `0xcc` bytes.
- Post-padding: `0x00558f63-0x00558f70`, thirteen `0xcc` bytes.
- Callees reported by MCP include `sub_557470`, `sub_4651D0`, `sub_4F4AA0`, `sub_4B7C50`, `sub_4A6260`, `unknown_libname_19`, `_memset`, `_CxxThrowException`, and `@__security_check_cookie@4`.
- Cyclomatic complexity: 17 with 54 basic blocks, enough to block casual manual body drafting.

## Function / Child Inventory

UID00039W should remain one by-memory child for this pass. The internal sections are behavior phases, not independent child functions:

- Startup receiver/prologue and call to [UID:00039Q].
- DirectDraw surface descriptor construction and surface creation.
- Optional temporary surface slot setup.
- Pixel-format read and callback-family selection.
- Alpha lookup table allocation and fill.
- Presentation state/dirty flag/rect reset.
- DDError exception throw path.

No split is recommended because the whole body is one modeled function and there are no clean internal raw helper entry points.

## Direct Xref / Caller Inventory

- Direct code xrefs to `0x00558840`: one, from `0x004f6199` inside ApplicationStartup `sub_4F5FB0`.
- Caller window: `0x004f618a` loads `dword_67A7CC`, `0x004f6190` moves it to `ecx`, and `0x004f6199` calls `sub_558840`.
- Data xrefs to `0x00558840`: none found in current MCP.
- `find_bytes` pointer-pattern probes for `0x00558840`, `0x00558f63`, and pre-start `0x0055883d` found no VA/RVA route.

This proves a live startup call, but not a saved callback, vtable slot, or public API route.

## Documentation Evidence And IDA Status

Current target and support documentation correctly keep UID00039W separate from the aggregate [UID:0001G6] SurfacePresentation parent. After the implementation callback, the target no longer has the stale source-output state: `EMITTER_UIDS` is blank, formal C++ is blank with a no-code proof, and generated Surface output no longer carries UID00039W as an empty marker.

Support pages already contain useful facts that should be preserved:

- [UID:00039Q] is ScreenPane-owned and is called by UID00039W.
- [UID:00039S] owns ScreenPane presentation-mode setter helpers and documents the `+0x12c` field.
- [UID:00039Z] restores ScreenPane surfaces that UID00039W creates or links.
- Surface/global docs identify callback table globals, pixel-format flags, alpha lookup pointers, and temporary surface slot refs.

Stale support wording was fixed in `by-file/Surface.md` and `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: UID00039W is no longer described as source-ready through Surface or as a generic Surface flip/restore caller. It is documented as a live Surface-presentation initializer with ScreenPane receiver evidence and no current emitter.

## Ranked Ownership Analysis

1. Direct semantic owner, Surface/render presentation [UID:0000OC]: strongest current bucket. The body initializes Surface render callback families, pixel-format flags, alpha lookup tables, and DirectDraw presentation support. Existing support docs already place this family under Surface while acknowledging mixed ScreenPane edges. Keep `CANONICAL_OWNER:0000OC` for now.

2. Receiver/class owner, ScreenPane [UID:0000CB or ScreenPane file owner]: strong counter-evidence, but not enough for unilateral reroute. The startup caller passes `g_pScreenPane`; fields `+0xfc`, `+0x100`, `+0x104`, `+0x108`, `+0x118`, `+0x11c`, `+0x12c`, and `+0x59c` are receiver-shaped. However, prior reports deliberately stopped short of rerouting UID00039W when Q/S/Z were rerouted, because this body also performs Surface-global initialization.

3. Source-file owner, `by-file/Surface.md`: current emitter route but unsafe. It explains global Surface state, yet it cannot safely emit a `thiscall` body whose receiver is `g_pScreenPane`.

4. Caller/consumer, ApplicationStartup: rejected as owner. It reaches the initializer but does not own the DirectDraw/render surface state.

5. DirectX: rejected as owner. DirectDraw interfaces and globals are dependencies; they are not the semantic source owner of the game presentation initializer.

6. MapPane/minimap owner: rejected for this pass. The target name and family history mention minimap/render context, but current MCP evidence does not show a direct MapPane object or minimap caller route.

7. Generic/no-owner fallback: rejected. The Surface bucket remains more informative than `NONE`, and the function has strong subsystem identity.

Decision: keep `CANONICAL_OWNER:0000OC`, but clear `EMITTER_UIDS` until a future callback either accepts a ScreenPane/Surface boundary decision or supplies a safe formal body.

## Source Placement

Recommended current placement is documentation ownership under Surface render presentation, non-emitting. That means the target remains in the Surface family docs and aggregate parent, but it must not output an empty body into `Surface.cpp`.

Rejected placements:

- `Surface.cpp` formal body now: rejected due ScreenPane receiver/field route and unresolved source declaration.
- `ScreenPane.cpp` formal body now: rejected because the body initializes Surface callback/global state and would require broader family reroute.
- `DirectX.cpp`: rejected because DirectDraw is dependency infrastructure.
- `MapPane.cpp` or minimap-specific file: rejected due no direct route.
- ApplicationStartup source body: rejected because startup only calls the initializer.

## Range / Split / Padding / Reclassification Analysis

The current target path `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` is correct. MCP confirms a modeled function at `0x00558840` with size `0x723`; `0x00558f63` is post-return padding and the next function begins at `0x00558f70`. Three bytes of pre-padding and thirteen bytes of post-padding are clean enough to keep the current range.

No split, merge, rename, or path change is recommended. The implementation callback should update metadata and evidence only.

## Negative Evidence Summary

Negative evidence and rejected routes:

- No data xrefs to `0x00558840`.
- No saved VA/RVA pointer-pattern route for the function start/end/pre-start.
- No vtable slot or callback-cell route for UID00039W itself.
- No direct MapPane or minimap object route in current MCP output.
- No safe original source declaration proof for `InitializeSurfacePresentation` or any Surface/ScreenPane method spelling.
- No proof that `Surface.cpp` is the correct emitter for a `thiscall` body using ScreenPane fields.
- No proof that ScreenPane should absorb Surface callback-table and alpha lookup initialization without a broader support update.

These negatives block formal C++ emission, not reconstructability.

## IDA Rename / Type / Comment Recommendations

No IDA database edits are recommended or authorized by this report. If a future supervisor-owned IDA naming pass is opened, candidate names should be derived from the accepted documentation after the Surface/ScreenPane source-boundary decision, not from this report alone.

No IDA rename, comment, or type edits were made during the callback.

## First-Draft C++ Recommendation

No first-draft C++ should be inserted for UID00039W in this callback. The target formal C++ block should remain empty.

Concrete no-code proof:

- UID00039W is live and modeled, so blank C++ is not justified by dead-code or padding treatment.
- The only direct caller passes `g_pScreenPane` as receiver, and the body writes ScreenPane-shaped fields.
- The current emitter is Surface, and the body also initializes Surface callback/global state.
- A Surface formal body would contradict the receiver and field route.
- A ScreenPane formal body would require a broader accepted ownership/emitter reroute for Surface presentation globals and support docs.
- Raw decompiler C++ would expose unresolved `sub_*` helpers, vtable offsets, stack descriptor arrays, exception helper details, and non-source field names.

Therefore the implementation callback should clear `EMITTER_UIDS` and document this no-code proof rather than emit code.

## Final Recommendation

Apply a metadata/evidence correction, not a body draft:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000OC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ block: empty
- Add target-specific no-code proof and current MCP evidence.

This resolved the historical empty-emitter defect while preserving the function for future source-boundary work.

## Recommended Target Doc Changes

For `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`:

- Set `COMPLETION:88` and `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000OC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Clear `EMITTER_UIDS`.
- Keep optional position blank.
- Keep the formal C++ block empty.
- Add current MCP session `nexustk_supervisor_20260704`, exact function size/range, padding, startup caller, no data/pointer route, DirectDraw surface creation sequence, callback-family globals, alpha lookup allocation, ScreenPane field writes, and relationships to UID00039Q/UID00039S/UID00039Z.
- Replace stale source-ready/empty-emitter wording with the no-code proof above.

## Recommended Support Doc Changes

Update only if stale:

- `by-file/Surface.md`: update UID00039W row so it is not described as source-ready through Surface and does not call [UID:00039Q] a generic Surface flip/restore helper. It should say UID00039W is a non-emitting, live Surface-presentation initializer with ScreenPane receiver caveat.
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: update the UID00039W child row to `88/90`, Surface-owned, reconstructable, non-emitting/no-code-proof, and preserve parent non-reconstructable metadata.
- `by-file/ScreenPane.md` and `by-class/ScreenPane.md`: add or adjust only concise support wording if current docs lack the startup receiver and field evidence. Do not add UID00039W as a source-ready ScreenPane method in this callback.
- `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`: inspect only; expected already-present. Do not change unless it still misstates the UID00039W relationship.
- `by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md`: inspect only; expected already-present for `+0x12c`.
- `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md`: inspect only; expected already-present for `+0x100`/`+0x108` restoration relationship.
- Global/support docs for callback table, pixel-format flags, alpha lookup pointers, and temporary surface slot: inspect only; update only if they omit or contradict UID00039W-specific xrefs already proven.

## Score And Metadata Recommendation

Recommended target metadata after callback:

- `COMPLETION:88`: behavior, range, caller, globals, and field evidence are now well documented; formal source remains intentionally absent.
- `CONFIDENCE:90`: high confidence in behavior and range, capped by original source declaration, owner/emitter boundary, and helper/type naming.
- `CANONICAL_OWNER:0000OC`: keep Surface as the best current source-family bucket.
- `RECONSTRUCTABLE:TRUE`: the function is source-authored and analyzable, not compiler glue or dead code.
- `EMITTER_UIDS:` blank: required to stop generating an empty Surface marker.
- `EMITTER_POSITION_OPTIONAL:` blank.

## Open Questions With Attempted Resolution

- Original source declaration: unresolved. ApplicationStartup supports a ScreenPane receiver-style call, but Surface/global initialization blocks a simple owner reroute.
- Field names: `+0xfc`, `+0x100`, `+0x104`, `+0x108`, `+0x118`, `+0x11c`, `+0x12c`, and `+0x59c` have behavioral support, but not all have stable original spelling. This blocks formal C++ names.
- DirectDraw wrapper types: unresolved enough to block source body. Vtable calls are understood behaviorally, but raw vtable offsets should not enter formal source.
- Callback helper names: current support docs identify callback families, but a full source body would need stable names for all entries and flags.
- Minimap naming: target/family terminology uses minimap/render context, but MCP did not prove direct MapPane/minimap ownership. This remains a naming caveat, not a reason to move owner.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

None. This report does not request manual generated coverage edits, tracker edits, registry edits, or lifecycle actions. Generated output should change only as a side effect of scoped validators after accepted by-* edits in a supervisor callback.

## Follow-Up Actions

Implementation callback follow-up is complete:

- Leased and edited only the target, `by-file/Surface.md`, and the `SurfacePresentation` parent.
- Applied target metadata, blank emitter, blank formal C++, and no-code proof.
- Synced stale support rows in `by-file/Surface.md` and `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`.
- Inspected ScreenPane, Q/S/Z, callback-table, pixel-format, alpha-lookup, and temp-slot support pages; no direct contradiction required edits.
- Ran scoped validators for each changed by-* file.
- Confirmed generated `auto-generated/NexusTK/render/Surface.cpp` no longer contains UID00039W.

Supervisor next step is Gate 2 verification and supervisor-owned `execute_report` if Gate 2 passes.

## Confidence

Confidence is high for range, liveness, caller, DirectDraw setup behavior, callback-family assignment, alpha lookup allocation, ScreenPane field evidence, and the resolved historical empty-emitter defect. Confidence is intentionally capped for source placement and formal C++ because the function straddles ScreenPane receiver state and Surface/global rendering initialization.

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every changed by-* file.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
|---|---|---|---|---:|---:|---|
| `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` | `python .\tools\validator.py --mode file --file by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md --apply --queue-timeout 240` | `000000006351` | `2026-07-04T13:40:05-04:00` | 0 | 1 | Superseded target validator pass. It updated completion/confidence and cleared the emitter, but also exposed a bad temporary UID link I had introduced for the temp surface slot. I corrected that link to [UID:0002AK] and reran validation. |
| `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` | same scoped command | `000000006353` | `2026-07-04T13:40:29-04:00` | 0 | 1 | Final target validator. Warnings: `missing_ref_uid:9` for legacy UID references `00039S`/`00039Z` not present in `validator.ini`; `reference_index_add 0002AK`; generated refresh deferred. |
| `by-file/Surface.md` | `python .\tools\validator.py --mode file --file by-file/Surface.md --apply --queue-timeout 240` | `000000006355` | `2026-07-04T13:40:42-04:00` | 0 | 1 | Warnings: `missing_ref_uid:30` for existing legacy UID references; `stats_row_update 0000OC`; generated refresh deferred. Generated `auto-generated/NexusTK/render/Surface.cpp` refreshed from this command. |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | `python .\tools\validator.py --mode file --file by-memory/0x00557140-0x00559aef.SurfacePresentation.md --apply --queue-timeout 240` | `000000006356` | `2026-07-04T13:40:56-04:00` | 0 | 1 | Warnings: `missing_ref_uid:58` for existing legacy child UID references; generated refresh deferred. |

Generated freshness:

- `auto-generated/NexusTK/render/Surface.cpp` header: `validator-command-id: 000000006355`, `validator-refreshed-at: 2026-07-04T13:40:42-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- `rg "00039W|SurfaceMinimapRenderInitializer"` against generated `Surface.cpp` returned no matches.
- Queue-status readback command `000000006358` at `2026-07-04T13:41:26-04:00` reported worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.

## Changed Files

By-* docs changed by B006:

- `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
- `by-file/Surface.md`
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`

Report updated by B006:

- `tools/leaser/Agents/Agent-B006/research/00039W-SurfaceMinimapRenderInitializer-source-quality.md`

Validator-generated side effects observed:

- `auto-generated/NexusTK/render/Surface.cpp` refreshed and no longer contains UID00039W.
- `project-level/-auto-completion-stats.md` updated by scoped validator/projected stats.
- `tools/validator.ini` was touched by the validator; B006 did not manually edit validator state.

No coverage reports, lifecycle/archive files, supervisor ledgers, or generated files were manually edited.

## Implementation Tracking Checklist

Implementation callback items:

- [x] Lease `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` immediately before editing. Proof: B006 lease command succeeded for the target, `by-file/Surface.md`, and parent page.
- [x] Set target `COMPLETION:88` and `CONFIDENCE:90`. Proof: target metadata and validator command `000000006353`.
- [x] Keep target `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and blank optional position. Proof: target metadata unchanged for these fields.
- [x] Clear target `EMITTER_UIDS` and keep the formal C++ block empty. Proof: target metadata is blank emitter; formal block remains empty.
- [x] Add target evidence for MCP session `nexustk_supervisor_20260704`, function size `0x723`, range/padding, one startup caller, no data/pointer route, DirectDraw surfaces, callback globals, alpha lookup globals, temp surface slot, ScreenPane field writes, and Q/S/Z relationships. Proof: target `Behavior`, `IDA MCP Evidence`, and `Changes`.
- [x] Add the target-specific no-code proof and historicalize the generated empty marker as the reason for emitter cleanup. Proof: target `No-Code And Emitter Disposition`, `Status`, and generated freshness notes.
- [x] Inspect and update `by-file/Surface.md` where stale. Proof: UID00039W row and 2026-07-04 B006 change note now mark non-emitting Surface research bucket and remove stale restore/flip/source-ready wording.
- [x] Inspect and update `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` where stale. Proof: UID00039W child row now `88/90`, Surface research bucket, non-emitting/no-code-proof; parent metadata unchanged.
- [x] Inspect `by-file/ScreenPane.md` and `by-class/ScreenPane.md`. Proof: already-present; both docs already carry startup receiver/field caveats for UID00039W / fields `+0xfc/+0x100/+0x108/+0x12c`.
- [x] Inspect UID00039Q/UID00039S/UID00039Z support pages and callback/global support pages. Proof: already-present/excluded-with-reason; Q/S/Z pages and callback/pixel/alpha/temp-slot pages contain same-or-greater support detail and no direct UID00039W contradiction, so no edits were made.
- [x] Run scoped validators from `source-3/project-documentation` for every changed by-* file. Proof: commands `000000006353`, `000000006355`, and `000000006356` are final validators with `exit 0` / `ok:1`; command `000000006351` is recorded as a superseded first target pass.
- [x] Record command IDs, timestamps, exit codes, ok counts, warnings, and generated freshness. Proof: `Validator Results` section.
- [x] Do not manually edit generated files, coverage reports, validator state, lifecycle/archive state, or supervisor ledgers. Proof: generated/project stats/validator.ini changes were validator side effects only; no coverage/lifecycle/supervisor ledger edits.
- [x] Do not run `execute_report`, dry-run/probing variants, registry lifecycle commands, report moves, or archive commands. Proof: only scoped file validators and queue-status readback were run.
- [x] Release leases immediately after edit/validator batch. Proof: B006 unlease command succeeded for all three leased by-* files, and current lease report has no B006/UID00039W entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000006377","destination_path":"executed-b-agent-research/B006/00039W-SurfaceMinimapRenderInitializer-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00039W-SurfaceMinimapRenderInitializer-source-quality.md","timestamp":"2026-07-04T17:45:56-04:00","uid":"00039W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
