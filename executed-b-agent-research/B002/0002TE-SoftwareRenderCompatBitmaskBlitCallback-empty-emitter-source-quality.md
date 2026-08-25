** TARGET-REPORT-UID:0002TE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002TE SoftwareRenderCompatBitmaskBlitCallback Empty-Emitter Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: accept the completed ordinary-document callback for [UID:0002TE] as the source-ready Surface-owned compat/RGB555 bitmask callback at `94/94`, with exact formal C++ and a blank target H block.
- Final disposition applied: exact function range `[0x004be0e0,0x004be66e)`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OC` are retained; the score/formal source state and all accepted slot-6 declaration/ABI/support documentation are implemented.
- Completed lifecycle gates: supervisor Gate 1 accepted the prior exact report artifact, independent post-IDA ordinary-doc Gate 2A completed under commands `000000018623-000000018629`, supervisor Gate 2B technical IDA application/readback/save is complete, B002 ordinary-document/report reconciliation is complete, and the exact manual coverage payloads were applied and validated under commands `000000018631-000000018634`.
- Exact catalog state: after Singer's independent cross-check confirmed all 16 ordinary hashes, eight manual rows, and the persisted IDA poststate, the supervisor independently closed catalog entry `0342 - UID0002TE - Surface RGB555 Compat Packed-Bitmask Callback And Slot 6` to exact state `APPLIED_VERIFIED_RECONCILED`.
- Remaining supervisor actions: perform fresh exact-artifact Gate 1/Gate 2 verification, then run the supervisor-only `execute_report`/archive lifecycle. No research, ordinary-document, IDA, catalog, coverage, generated implementation, or other reconciliation action remains for B002.
- Confidence: very strong for range, ownership, calling convention, arguments, return type, packed-bit traversal, clipping, destination layout, palette fields, all four modes, RGB555 arithmetic, source placement, and physical slot; strong for inferred human spellings of the callback typedef and mode constants.
- Current lifecycle: final report-state reconciliation artifact at the assigned B002 research path. The original sixteen ordinary destinations are implemented; six stale-current-state destinations were reconciled and scoped-validated under commands `000000018560-000000018565`; independent supervisor Gate 2A commands `000000018623-000000018629` all exited `0` with `ok: 1`; exact supervisor-owned coverage application/validation commands `000000018631-000000018634` all exited `0` with `ok: 1`; and commands `000000018565` and `000000018634` completed their respective dated generated-refresh checkpoints. Technical IDA application/readback, ordinary/report reconciliation, and supervisor catalog-state reconciliation are complete; exact catalog entry `0342` is `APPLIED_VERIFIED_RECONCILED`. Final lifecycle-time live generated readback remains supervisor-authoritative. B002 did not edit coverage reports, mutate/save IDA, or run/probe report lifecycle execution.

## Supporting Research

- Live IDA MCP session `5a570ede` was healthy during this pass. `server_health` returned `status:ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, Hex-Rays ready, and string cache ready. `auto_analysis_ready:false` was recorded as context only because bounded live function, xref, item, byte, comment, name, and type queries all succeeded.
- `analyze_function(0x004be0e0)` returned exact function size `1422` / `0x58e`, 494 instructions as independently recorded by the current target evidence, 50 basic blocks, cyclomatic complexity 29, no direct callers, two target-address data references, and the complete seven-callee set.
- Live reanalysis of `0x00467b30` proves nine slot-6 calls use `GrafPort *` in `ECX`, push exactly `mode`, `RectBounds *`, and `maskBits`, ignore the return lane, and always pass mode `1` in this consumer.
- Live reanalysis of `InitializeSurfaceRenderCallbacks` proves slot `0x0069b3f8` receives compat target `0x004be0e0` or RGB565 target `0x004c3ea0`, then is stored once into the fixed global callback slot.
- Live reanalysis of RGB565 peer `0x004c3ea0` confirms the same receiver, three-stack-argument contract, four-mode geometry and bitstream behavior, but a different RGB565 blend helper. The peer is corroboration, not a source for copying its stale `char __fastcall` draft ABI.
- Historical Gate 1 prestate recheck on the same healthy session queried every byte item in `[0x0069b3f8,0x0069b3fc)`: IDA then modeled four separate one-byte items, with a stale six-argument type on the head. Supervisor Gate 2B has superseded that itemization with the persisted one-item readback documented below.
- Existing target and support documentation was treated as evidence, not authority. Earlier wording that the final callback typedef, source name, mask layout, and C++ required a future pass is superseded by this report's live ABI, caller, type, and source-shape reanalysis.
- No Wave2 or Wave3 artifact was used. Any such historical mention is stale under the current project workflow.

## Target

- Target UID: `0002TE`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0002TE] `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md`, exact source-authored compat/RGB555 slot-6 callback body.
- Target path: `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, under the current empty-emitter priority.
- Assignment-time supervisor classification: reconstructable source-authored Surface callback whose generated `Surface.cpp` representation was an empty emitter marker. Current generated output contains the formal implementation and no UID0002TE empty marker.
- Pre-callback scores and parent state: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank emitter position, blank CPP, blank H.
- Current applied state: `COMPLETION:94`, `CONFIDENCE:94`, same owner/emitter/reconstructable/position, exact nonblank CPP, and blank H.

## Current Target State

- Current metadata: exact function range `[0x004be0e0,0x004be66e)`, `94/94`, source child of the compat/RGB555 callback aggregate, assigned to [UID:0000OC] Surface.
- Current owner/emitter/reconstructable state: correct and retained. Surface owns the callback implementation; aggregate [UID:00016J] and physical table [UID:0001PI] remain non-emitting and do not duplicate bodies/storage.
- Current C++/emitter state: UID0002TE has exact formal CPP and blank H. At the dated post-IDA implementation checkpoint, generated `NexusTK/render/Surface.cpp` after refresh command `000000018565` contained one UID0002TE source marker and zero UID0002TE empty markers; its source-bearing header recorded command `000000018564`. Those command IDs and hashes are checkpoint evidence, not a claim about the final live generated artifact; the supervisor's final lifecycle-time generated readback is authoritative.
- Current catalog reconciliation state: after independent confirmation of all 16 ordinary hashes, eight manual rows, and persisted IDA poststate, the supervisor closed exact catalog entry `0342 - UID0002TE - Surface RGB555 Compat Packed-Bitmask Callback And Slot 6` to `APPLIED_VERIFIED_RECONCILED`. Technical IDA application/readback, ordinary/report reconciliation, and catalog-state reconciliation are complete.
- Applied blocker resolutions:
  - Historical `sub_4BE0E0` is replaced in source and persisted IDA by `SoftwareRenderCompatBitmaskBlitCallback`.
  - The current decompiler `char __fastcall` shape is rejected in favor of exact source `void __thiscall` ABI.
  - The raw mask argument is resolved as `const unsigned char *maskBits`, not an object or `EPFTileContext`.
  - The rectangle is resolved as `const RectBounds *destinationBounds`; it supplies screen destination geometry, while the function derives a local zero-origin mask rectangle.
  - The mode byte is resolved as four exact copy/color-key/half-blend variants.
  - `this+0x78` is resolved by the current canonical `GrafPort` UDT as `m_textBackFillColor`, superseding older `m_secondaryDrawColor` prose.
  - The slot return is resolved as `void`; current return-byte artifacts are dead compiler/decompiler lanes.
  - The target CPP body and target H no-code disposition are complete.
- Related target/support docs checked: UID00016J, UID0000TN, UID0001PI, UID0001G6, UID00039V, UID000164, UID00005V GrafPort class/file support, UID000276 masks, UID0000YZ BalloonObjectPane, UID0002TI peer, UID0000OC Surface, `by-memory/-ignored.md`, and `by-project-structure/proposed-source-tree.md`.
- Current artifact/lifecycle status: active exact-artifact review at the assigned B002 research path. Ordinary implementation, prior exact-artifact Gate 1 acceptance, supervisor Gate 2A, technical Gate 2B application/readback/save, B002 ordinary/report reconciliation, supervisor closure of catalog entry `0342` to `APPLIED_VERIFIED_RECONCILED`, manual coverage application/validation, serial scoped validation, and dated generated-refresh checkpoints are complete. Only fresh exact-artifact Gate 1/Gate 2 verification and supervisor-only `execute_report`/archive remain pending.

## Executive Recommendation

- Keep Surface as the direct source owner and emitter. This callback is selected by Surface initialization, mutates only the supplied GrafPort surface state, and has no feature-specific direct caller or class-method ownership route.
- Emit the exact callback as a file-local `static void __thiscall SoftwareRenderCompatBitmaskBlitCallback(...)` in `Surface.cpp` through UID0002TE. Keep the target H block blank because the function itself is file-local.
- Define the shared source-visible slot type in the semantic callback-table owner [UID:0000TN] H block as `SurfaceBitmaskBlitProc`, declare `extern SurfaceBitmaskBlitProc g_pfnBlitBitmask`, and keep the one storage definition in UID0000TN CPP. Leave physical storage page UID0001PI formally blank.
- UID0002TI's current source uses the same corrected `void __thiscall` slot ABI and canonical fields. Its RGB565 body remains a separate provider using `BlendRgb565Pixel` and does not absorb or duplicate the RGB555 target.
- Keep `[0x004be66e,0x004be680)` ignored as compiler-generated local control-flow data: a two-byte NOP followed by the four-entry jump table `jpt_4BE218`.
- Raise UID0002TE to `94/94`. No behavior, ownership, range, type, or source-emission blocker remains. The residual cap reflects inferred original lexical spellings and absence of compiler binary-diff confirmation, not deferred research.

## Supervisor Active Recheck

- Trigger: the supervisor assigned UID0002TE as a reconstructable by-memory empty emitter and explicitly required all type/name/mode/layout/ownership/range/score blockers to be resolved during report-only research.
- Split-first result: no source child split is needed. The modeled function is a single source-authored body; its successor island is compiler-generated switch data already represented by `-ignored`.
- Every source-bearing item in scope has a disposition:
  - UID0002TE emits the compat/RGB555 function body.
  - UID0000TN emits the shared typedef/declaration and single slot definition.
  - UID0001PI documents physical storage and remains blank to prevent duplication.
  - UID0002TI remains a separate RGB565 function body under the same callback ABI.
  - UID00016J remains a non-emitting family index.
- The generated empty marker is not accepted as a terminal state. Exact formal source is supplied below.

## Inference Research Guidance Check

- Binary facts were separated from source inference. Exact addresses, sizes, xrefs, bytes, field offsets, calls, stack cleanup, branches, and arithmetic are direct IDA facts. Human names and enum spellings are inferred source shape.
- Existing documentation assumptions treated as uncertain and rechecked: `char` return, `__fastcall`, unused EDX as a source argument, `sourceBounds` naming, `m_secondaryDrawColor`, unresolved mask object layout, and blank formal C++.
- The source-shape decision follows current project rules: runtime behavior is preserved exactly, while decompiler labels and ABI artifacts are replaced with plausible human C++03 source.
- `SoftwareRenderCompatBitmaskBlitCallback` is descriptive rather than original-symbol proof, but it is the strongest consistent project spelling because the current initializer formal already uses it and neighboring compat providers use the `SoftwareRenderCompat...Callback` family.
- `SurfaceBitmaskBlitProc` and the four `BitmaskBlitMode` enumerators are inferred. They are preferred over raw `dword_69B3F8`, numeric-only source, or a feature-biased Balloon name.
- No Wave2/Wave3 evidence was accepted.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Best resolution | Classification |
| --- | --- | --- | --- |
| Function name | Checked existing target title, initializer formal, peer naming, neighboring Surface callback names, and current IDA name-index collisions. | `SoftwareRenderCompatBitmaskBlitCallback`; no collision. | Descriptive, high confidence. |
| Calling convention | Checked receiver use, prologue, all nine indirect consumer calls, initializer casts, and `retn 0Ch`. | `void __thiscall` with GrafPort receiver and three stack arguments. | Binary-proven. |
| Return type | Checked consumer result use, early exits, epilogues, and dead low-byte decompiler assignments. | `void`; `char` is a decompiler artifact. | Binary-proven. |
| Mask argument | Checked byte loads, `0x80 >> bit`, byte carry, row carry, no object-field dereference, and static mask tables. | `const unsigned char *maskBits`, contiguous MSB-first packed 1bpp data. | Binary-proven. |
| Bounds role | Checked Balloon caller rectangle construction, clip intersection, local zero-origin rectangle, and clipped source offset derivation. | `const RectBounds *destinationBounds`; local `maskBounds` models source coordinates. | Binary-proven role; human name inferred. |
| Mode type | Checked pushed constant `1`, byte switch, range check, and four targets. | `unsigned char mode` with four file-local enum values 0..3. | Binary-proven width/values; enum names inferred. |
| GrafPort fields | Queried live `GrafPort` UDT and matched offsets `+0x1c`, `+0x71`, `+0x74`, `+0x78`. | `m_surfaceContext`, `m_drawEnabled`, `m_drawColor`, `m_textBackFillColor`. | Current typed IDA fact. |
| Surface layout | Queried live `EPFTileContext` size/members and verified destination formula. | `pixelData`, `rowStridePixels`, and `bounds`; no invented Surface wrapper. | Current typed IDA fact. |
| Color path | Checked `g_pPaletteLib`, `PaletteLib__GetCurrentPalette`, and two `DLPalette_MapColor` calls. | Map primary and background-fill indices before mode dispatch. | Binary-proven. |
| Blend helper | Compared exact masks/formula with existing formal `BlendRgb555Half` in UID0002TB. | Reuse file-local `BlendRgb555Half`; do not create a new binary function. | Binary equivalence plus source-shape inference. |
| Control-flow shape | Checked outer jump table and four separately compiled loops. | Outer switch with four loops; reject an inner per-pixel switch. | Binary-proven compilation shape. |
| Callback slot type | Checked 12 slot refs, nine consumer calls, two provider families, and existing callback typedef pattern. | New `SurfaceBitmaskBlitProc` in UID0000TN H, one global definition in CPP. | Strong source inference, exact ABI. |
| Source placement | Checked target refs, initializer ownership, aggregate, generated Surface.cpp, and rejected feature callers. | File-local provider in `Surface.cpp`; semantic table declaration in `Surface.h`. | Strong. |
| Successor island | Inspected exact items and bytes. | Ignore two-byte NOP plus four-entry local switch table; no source child. | Binary-proven. |
| Score blocker | Rechecked every blocker named in the target and goal. | Raise to 94/94; only original lexical spellings and binary-diff remain uncertain. | Fully researched. |

Rejected alternatives:

- `BlitRgb555BitmaskCallback`: plausible but less consistent with the established compat-family `SoftwareRenderCompat...Callback` names and current initializer formal.
- `BalloonObjectPane::DrawFrameMask`: rejected because BalloonObjectPane is only one indirect consumer; the same fixed Surface slot selects two pixel-format providers.
- `GrafPort::BlitBitmask`: rejected as an ordinary member because the target address is selected and invoked through a global callback slot, not a GrafPort vtable or direct method call.
- `SoftwareBlend16` ownership: rejected because this function performs clipping, destination traversal, palette mapping, and slot dispatch; only scalar blend arithmetic is helper-level behavior.
- `EPFTileContext *mask`: rejected because the argument is dereferenced as raw bytes from offset zero and has no field-based object accesses.
- Inner-loop mode switch: behaviorally equivalent but source-shape inconsistent with the one outer jump table and four duplicated compiled loops.
- `char` return and a dummy EDX parameter: rejected by ignored return values, three stack arguments, ECX receiver, and `retn 0Ch`.

No unresolved research issue blocks owner, range, score, IDA handoff, or first-draft source.

## Evidence Standards Used

- Direct IDA MCP evidence: health, function analysis, decompilation, exact function boundaries, raw bytes, item inspection, comments, xrefs, name-index queries, UDT inspection, typedef inventory, caller analysis, and initializer analysis.
- Binary-context evidence: `ECX` receiver, three pushes, `retn 0Ch`, unused result lane, branch topology, jump-table targets, pointer arithmetic, palette calls, and exact masks.
- Documentation evidence: target history, Surface callback-family aggregate, semantic and physical callback-table pages, Surface/GrafPort pages, Balloon masks/consumer, RGB565 peer, generated Surface.cpp, ignored ranges, source tree, and manual coverage rows.
- Negative evidence: no direct callers, no target-specific feature ownership, no source object layout on mask bytes, no proposed-name collision, no existing `SurfaceBitmaskBlitProc`, no source-bearing successor function, and no reason to duplicate table storage.
- Evidence ladder: direct binary facts control behavior and ABI; current typed IDA facts control layouts; source-family patterns control inferred human names; historical documentation is retained only where not contradicted.
- Tool limitation recorded: `auto_analysis_ready:false` was present, but all required bounded live queries succeeded. It did not reduce confidence or justify fallback conclusions.

## Evidence Checked

- IDA MCP/manual checks:
  - `server_health` on session `5a570ede`.
  - `analyze_function` for `0x004be0e0`, `0x004c3ea0`, `0x00467b30`, and `0x00558690`.
  - `xref_query` for target `0x004be0e0` and slot `0x0069b3f8`.
  - `inspect_items` for function start, tail NOP, jump table, `g_pPaletteLib`, slot head `0x0069b3f8`, and each trailing slot byte/item at `0x0069b3f9`, `0x0069b3fa`, and `0x0069b3fb`.
  - `get_comments` for function start, tail data, jump table, slot head, and all three trailing slot byte/items.
  - `get_bytes` for the exact target, successor island, and slot storage.
  - `entity_query` for proposed/current names.
  - `type_inspect` for `GrafPort`, `EPFTileContext`, `RectBounds`, and absent `SurfaceBitmaskBlitProc`.
  - `type_query` for existing Surface callback typedefs.
- Existing docs checked: UID0002TE, UID00016J, UID0000TN, UID0001PI, UID0001G6, UID00039V, UID000164, UID000276, UID0000YZ, UID0002TI, UID0000OC, GrafPort class/file, ignored ranges, proposed source tree, and current manual coverage rows.
- Generated evidence checked before callback: `auto-generated/NexusTK/render/Surface.cpp`, including `BlendRgb555Half`, the stale UID0002TI formal body, callback initializer assignments, and the UID0002TE empty marker.
- Historical generated checkpoint after the first callback: command `000000018417` produced the initial source-ready Surface CPP/H.
- Dated post-IDA implementation checkpoint: refresh command `000000018565` completed, while Surface.cpp/Surface.h source-bearing headers recorded command `000000018564`. Checkpoint hashes were `7D6462EE50C0089A28DD0EB37FC77E599C32264C5653F081109DF9BDA313B79E` and `FA920EBA7FCD10B9FCE3D67B23C90C73CC8CFB99EF9B6A38EBD5421D18F17761`. At that checkpoint UID0002TE and UID0002TI each had one source marker and one exact definition; neither had an empty marker or raw target label; header typedef/extern topology was present once; and twelve unrelated Surface children remained empty markers. Commands `000000018564` and `000000018565` and these hashes are dated implementation-time evidence only. Final supervisor lifecycle-time live generated readback is authoritative, and this report does not chase or invent replacement hashes.
- Negative checks: no direct code callers, no proposed-name collision, no existing callback typedef, no fourth stack argument, no consumed return value, no object-field reads from mask bytes, no function at `0x004be66e`, and no handwritten-source reason to emit the jump table.
- Initial report-only exclusions were honored. During the authorized callback B002 edited only the accepted ordinary by-* destinations and this same report, ran serial scoped validators, and performed generated readback. IDA mutation/save, coverage edits, audit/catalog/tracker/goal/notes edits, and report lifecycle commands remained prohibited and were not performed.

## Claim And Incorporation Ledger

The `Action` column preserves the historical accepted callback instruction. `Verification state` is the current disposition and controls whether work remains; every row below is applied/verified.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2TE-001 | 0002TE | Exact function is `[0x004be0e0,0x004be66e)`, size `0x58e` / 1422. | Exact | Live function analysis and bytes. | UID0002TE Address Range/IDA Evidence | Replace stale evidence with current exact facts. | APPLIED_VERIFIED: UID0002TE, command 18355. |
| C2TE-002 | 0002TE | Exact target byte SHA256 is `E087538BDDE4E6DCC57B65A4E9F1B4B71ED62D1D2ECCF3C034009844D5848873`. | Exact | Current byte read and hash. | UID0002TE evidence | Add immutable checkpoint. | APPLIED_VERIFIED: UID0002TE, command 18355. |
| C2TE-003 | 0002TE | Source ABI is void `__thiscall`, GrafPort receiver plus mask, destination bounds, and byte mode. | Very strong | Consumer pushes, ECX, `retn 0Ch`, unused result. | UID0002TE Status/Behavior/CPP | Correct current decompiler ABI. | APPLIED_VERIFIED: UID0002TE formal CPP and generated readback. |
| C2TE-004 | 0002TE | Best source name is `SoftwareRenderCompatBitmaskBlitCallback`. | Strong | Initializer formal, family naming, no collision. | UID0002TE title/status/formal CPP | Adopt descriptive source name. | APPLIED_VERIFIED: UID0002TE and generated definition. |
| C2TE-005 | 0002TE | Mask is contiguous MSB-first packed 1bpp bytes. | Exact | `0x80 >> bit`, byte and row carry. | UID0002TE behavior/touched state | Replace unresolved mask-layout wording. | APPLIED_VERIFIED: UID0002TE and support consumers. |
| C2TE-006 | 0002TE | Bounds argument is destination geometry; local zero-origin mask bounds derive source coordinates. | Exact | Caller rectangles and target geometry. | UID0002TE behavior/CPP | Rename source-facing argument. | APPLIED_VERIFIED: UID0002TE formal CPP. |
| C2TE-007 | 0002TE | Destination address uses `pixelData`, `rowStridePixels`, and surface bounds origin. | Exact | Target pointer arithmetic and UDT. | UID0002TE layout/CPP | Add exact typed formula. | APPLIED_VERIFIED: UID0002TE, GrafPort support, generated CPP. |
| C2TE-008 | 0002TE | Primary/background pixels map `m_drawColor` and `m_textBackFillColor` through current palette. | Exact | UDT offsets and two palette calls. | UID0002TE behavior/CPP | Correct stale field aliases. | APPLIED_VERIFIED: target, peer, and GrafPort support. |
| C2TE-009 | 0002TE | Modes 0..3 are copy, color-key copy, full half-blend, and color-key half-blend. | Exact | Four outer switch cases. | UID0002TE behavior/CPP | Add enum and exhaustive behavior. | APPLIED_VERIFIED: UID0002TE formal/generated CPP. |
| C2TE-010 | 0002TE | RGB555 blend is exact half average using masks `0x7c1f` and `0x03e0`. | Exact | Scalar arithmetic. | UID0002TE behavior/CPP | Reuse `BlendRgb555Half`. | APPLIED_VERIFIED: UID0002TE formal/generated CPP. |
| C2TE-011 | 0002TE | Target CPP is source-ready and target H remains blank because function is file-local. | Strong | Source placement and existing helper topology. | UID0002TE formal blocks | Install exact CPP; retain blank H. | APPLIED_VERIFIED: target and command 18417 generated topology. |
| C2TE-012 | 0002TE | Metadata becomes `94/94`, owner/emitter unchanged. | Strong | Blocker audit. | UID0002TE metadata/score | Apply. | APPLIED_VERIFIED: command 18355. |
| C2TE-013 | 00016J | Aggregate remains false/non-emitting but should list UID0002TE as source-ready. | Strong | Exact child topology. | Compat aggregate | Update index and score rationale. | APPLIED_VERIFIED: command 18358. |
| C2TE-014 | 0000TN | Add `SurfaceBitmaskBlitProc` declaration and `g_pfnBlitBitmask`; declarations belong in H. | Strong | Exact ABI and callback family pattern. | Semantic callback table CPP/H | Replace formal blocks as specified. | APPLIED_VERIFIED: command 18362 and generated H/CPP readback. |
| C2TE-015 | 0001PI | Physical slot 6 is exact four-byte zero-initialized storage and must remain non-emitting. | Exact | Bytes, 12 xrefs, semantic owner. | Physical callback table | Correct slot ABI and score narrative. | APPLIED_VERIFIED: command 18391; comment-only covered-by marker retained, no duplicate storage/body. |
| C2TE-016 | 00039V | Initializer selects the two provider functions and stores a `SurfaceBitmaskBlitProc`. | Exact | Live initializer. | Exact initializer child | Correct slot-6 local/type wording. | APPLIED_VERIFIED: command 18363 and generated assignments. |
| C2TE-017 | 0001G6 | Broad presentation aggregate retains both initializer routes as support only. | Strong | Two target refs. | SurfacePresentation | Add resolved ABI/name cross-reference. | APPLIED_VERIFIED: command 18364. |
| C2TE-018 | 000164 | GrafPort clip helper remains a dependency, not owner. | Exact | Direct callee. | GrafPortGetClipRect | Add reciprocal callback link only. | APPLIED_VERIFIED: command 18367. |
| C2TE-019 | 00005V | Current GrafPort fields resolve all receiver offsets used by target. | Exact | Live UDT. | GrafPort class/file | Add callback consumer evidence without layout invention. | APPLIED_VERIFIED: commands 18374 and 18380. |
| C2TE-020 | 000276 | Six four-byte mask entries are exact raw maskBits consumers; mode is always 1 here. | Exact | Balloon caller and table. | Static masks page | Correct callback typedef/role confidence. | APPLIED_VERIFIED: command 18383. |
| C2TE-021 | 0000YZ | PaintBubble performs nine exact slot-6 calls and ignores return. | Exact | Live consumer. | BalloonObjectPane | Replace raw callback prose with typed call contract. | APPLIED_VERIFIED: commands 18394 and 18399. |
| C2TE-022 | 0002TI | RGB565 peer shares void `__thiscall` slot ABI and canonical fields; current draft is stale. | Very strong | Live peer plus shared consumer. | UID0002TI metadata/formal CPP | Correct ABI/body field names, preserve RGB565 behavior. | APPLIED_VERIFIED: command 18409 and generated peer definition. |
| C2TE-023 | 0000OC | Surface owns callback declarations, implementations, and initializer. | Very strong | Source topology and generated root. | Surface file page | Add source-ready slot-6 closure. | APPLIED_VERIFIED: command 18413. |
| C2TE-024 | 0000VN | `[0x004be66e,0x004be680)` is NOP plus local jump table only. | Exact | Items and bytes. | by-memory/-ignored.md | Refine exact split text, no new UID. | APPLIED_VERIFIED: command 18415. |
| C2TE-025 | 0002TE | Function IDA rename/type/comment action is safe and collision-free. | Strong | Literal prestate, name query, and persisted exact readback. | Supervisor Gate 2B | Completed by supervisor after callback verification. | APPLIED_VERIFIED: exact name/type/function-repeatable comment, other start channels blank, bytes/range/two refs unchanged; saved IDB SHA256 `7F3024691E4C38EA46E9160617C636ADFCA079D9CB76798866616FA1004BFB94`. |
| C2TE-026 | 0000TN | Slot name/type/comment action is safe; historical item width/type were stale. | Strong | Literal prestate, slot xrefs, declared typedef, and persisted exact readback. | Supervisor Gate 2B | Completed: type declared and slot type/comment applied. | APPLIED_VERIFIED: four-byte `SurfaceBitmaskBlitProc`, one `g_pfnBlitBitmask` item, exact repeatable/blank regular comment, twelve refs/zero bytes unchanged, protected `g_pfnFillRect` unchanged. |
| C2TE-027 | 0002TE | Target and support manual coverage rows required synchronization with the accepted source-ready state. | Exact | Historical manual rows plus supervisor application/validator readback. | Coverage reports | Completed by supervisor from the exact preserved B002-authored payload below; B002 did not edit coverage. | APPLIED_VERIFIED: exact payload applied to `by-memory/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-file/-coverage-report.md`; commands `000000018631-000000018634` all exited `0` with `ok: 1`, and `000000018634` completed the coverage-time by-memory/generated refresh checkpoint. |
| C2TE-028 | 0002TE | No direct feature/class owner exists. | Strong | No direct callers and global slot route. | Ownership/negative evidence | Preserve rejection rationale. | APPLIED_VERIFIED across target/support ownership sections. |
| C2TE-029 | 0002TE | Generated empty marker must disappear after nonblank formal CPP and refresh. | Exact expected topology | Generator behavior at dated implementation checkpoints. | Generated verification | Verified without hand-editing generated files. | APPLIED_VERIFIED at command 18417 and reconfirmed at dated commands 18564/18565: one source marker, zero target empty markers; final lifecycle-time live generated readback remains authoritative. |
| C2TE-030 | 0000OC | Proposed source tree remains `NexusTK/render/Surface.cpp` plus declaration header. | Strong | Existing root and declaration rule. | proposed-source-tree.md | Completed slot-6 callback closure/Surface.h role. | APPLIED_VERIFIED: command 18417. |

## Positive Evidence Summary

- The exact callback body is a modeled function with a closed half-open range, stable byte hash, and no overlap with the successor data island.
- Both provider addresses are selected by Surface initialization, and the shared global slot has twelve direct references.
- Nine calls from BalloonObjectPane use the same receiver and three-stack-argument form and discard the return lane.
- `retn 0Ch` independently proves exactly three stack arguments after the ECX receiver.
- Current `GrafPort`, `EPFTileContext`, and `RectBounds` UDTs map every accessed offset without an invented layout.
- The mask traversal is exact and self-contained: byte base, starting bit, MSB-first test, per-pixel carry, and cross-row carry all derive from clipped source coordinates.
- The four mode bodies and exact RGB555 half blend are fully visible. No protocol, external state, or opaque helper blocks source reconstruction.
- The existing compat RLE formal already supplies the identical `BlendRgb555Half` helper in Surface.cpp, providing a plausible source reuse route without creating a nonexistent external function.
- The strongest inference chain is: fixed Surface initializer -> fixed global callback slot -> GrafPort receiver consumers -> exact compat/RGB565 providers -> current Surface generated root. This is sufficient for ownership, typedef, source name family, and file placement.

## IDA MCP Facts

- Function/range facts:
  - Current persisted name is `SoftwareRenderCompatBitmaskBlitCallback` at `[0x004be0e0,0x004be66e)`, size `0x58e` / 1422; `sub_4BE0E0` is the historical pre-Gate-2B label.
  - Current persisted prototype is `void __thiscall(GrafPort *port, const unsigned __int8 *maskBits, const RectBounds *destinationBounds, unsigned __int8 mode)`.
  - Current function-repeatable comment is exactly `Surface-owned RGB555 compat packed-bitmask callback; GrafPort receiver, MSB-first 1bpp mask, destination bounds, and modes 0..3 for copy, color-key, and half-blend rendering.`; all other start comment channels are blank.
  - Basic blocks 50, cyclomatic complexity 29, no direct callers.
  - Exact target-byte SHA256: `E087538BDDE4E6DCC57B65A4E9F1B4B71ED62D1D2ECCF3C034009844D5848873`.
- Data/table/padding facts:
  - `[0x004be66e,0x004be670)` is a two-byte data item containing `66 90`.
  - `[0x004be670,0x004be680)` is `jpt_4BE218`, four dwords targeting `0x004be21f`, `0x004be2fe`, `0x004be3cf`, and `0x004be547`.
  - Combined successor bytes are `66 90 1f e2 4b 00 fe e2 4b 00 cf e3 4b 00 47 e5 4b 00`, SHA256 `9BF2E0BD9033ECF03CBFCD3BD728503FE72DD564FAA572769228700E44FF4135`.
  - Slot `[0x0069b3f8,0x0069b3fc)` contains four zero bytes, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
  - Current slot itemization is one exact item `[0x0069b3f8,0x0069b3fc)`, size four; every interior address resolves to head `0x0069b3f8`, name `g_pfnBlitBitmask`, type `SurfaceBitmaskBlitProc`. The regular comment is blank and the repeatable comment is exactly `SurfaceBitmaskBlitProc g_pfnBlitBitmask; initialized with RGB555 compat 0x004BE0E0 or RGB565 0x004C3EA0 and called by BalloonObjectPane::PaintBubble.`
- Xref facts:
  - Target refs: `0x0055872f` in `InitializeSurfaceRenderCallbacks`, `0x00558bbc` in `sub_558840`.
  - Slot refs: nine calls at `0x00467c29`, `0x00467c5e`, `0x00467c92`, `0x00467cd3`, `0x00467d08`, `0x00467d39`, `0x00467d6b`, `0x00467e5d`, `0x00467efb`; setup refs at `0x0055879d`, `0x00558bbc`, `0x00558ed8`.
- Callee facts: `GrafPort_GetClipRect`, `IntersectRects`, `IsRectEmptyOrInvalid`, `InitRectBounds`, `PaletteLib__GetCurrentPalette`, `DLPalette_MapColor`, and `@__security_check_cookie@4`.
- Global/type facts:
  - `g_pPaletteLib` at `0x0067a7e0`, type `PaletteLib *`.
  - `GrafPort` size `0xa0`; exact relevant fields are `m_surfaceContext +0x1c`, `m_drawEnabled +0x71`, `m_drawColor +0x74`, `m_textBackFillColor +0x78`.
  - `EPFTileContext` size `0x28`; `pixelData +0x04`, `rowStridePixels +0x0c`, `bounds +0x10`.
  - `RectBounds` size `0x10`, four `int` fields.
  - Existing Surface callback typedefs are four-byte pointers; `SurfaceBitmaskBlitProc` now exists as a four-byte function-pointer type.
  - Protected `g_pfnFillRect` starts separately at `0x0069b3fc` and is unchanged. Slot/neighbor bytes remain zero; target/tail bytes and ranges remain unchanged; target refs remain two and slot refs remain twelve.
  - Supervisor saved the reconciled IDB at SHA256 `7F3024691E4C38EA46E9160617C636ADFCA079D9CB76798866616FA1004BFB94`, 143,189,681 bytes, last write `2026-07-29T00:05:01.6996219-04:00`. A rejected scalar typedef call and temporary stale regular-comment/blank-visible-name states were corrected before save; no malformed intermediate state was persisted.
- Negative IDA facts: no proposed function-name collision, no existing new typedef, no direct target caller, no extra source stack argument, no consumed return, and no function at the successor island.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004be0e0,0x004be66e)` | UID0002TE target | Compat/RGB555 slot-6 provider | TRUE | UID0000OC Surface | `87/90` -> `94/94` | Current source-ready state. |
| `[0x004be66e,0x004be670)` | UID0000VN ignored interval | Two-byte NOP/alignment | FALSE/ignored | none | 100 | Preserve as ignored. |
| `[0x004be670,0x004be680)` | UID0000VN ignored interval | Four-entry local switch table | FALSE/ignored | none | 100 | Regenerated by source switch. |
| `[0x004be680,...)` | UID0002YF | Next compat fill callback | TRUE | UID0000OC | unchanged | Separate function, outside target. |
| `[0x004c3ea0,0x004c4364)` | UID0002TI | RGB565 slot-6 provider | TRUE | UID0000OC | `89/91` -> `91/93` | ABI/formal correction support. |
| `[0x0069b3f8,0x0069b3fc)` | UID0001PI physical slot 6 | Fixed callback storage | TRUE documentation, non-emitting physical page | UID0000TN | `90/91` -> `91/93` page-level recommendation | No duplicate formal. |
| `0x0069b3f8` semantic slot | UID0000TN | Typedef/declaration/storage owner | TRUE | UID0000OC | `92/93` -> `93/94` | Slot-6 declaration and definition are installed. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0055872f` | `InitializeSurfaceRenderCallbacks` loads `0x004be0e0` | Compat provider selection. |
| `0x00558bbc` | Inline initializer loads target and stores slot | Second retained provider/setup route. |
| `0x0055881d` | Initializer loads `0x004c3ea0` | RGB565 provider selection. |
| `0x00558ed8` | Inline initializer loads RGB565 target/stores slot | Peer route. |
| `0x0055879d` | Shared initializer stores selected pointer to `0x0069b3f8` | Exact global slot installation. |
| `0x00467c29` | Balloon `PaintBubble`, mask `0x0066d41c`, mode 1 | First compact-frame mask call. |
| `0x00467c5e` | Balloon `PaintBubble`, mask `0x0066d420`, mode 1 | Second compact-frame mask call. |
| `0x00467c92` | Balloon `PaintBubble`, mask `0x0066d424`, mode 1 | Third compact-frame mask call. |
| `0x00467cd3` | Balloon `PaintBubble`, mask `0x0066d41c`, mode 1 | First alternate-frame call. |
| `0x00467d08` | Balloon `PaintBubble`, mask `0x0066d420`, mode 1 | Second alternate-frame call. |
| `0x00467d39` | Balloon `PaintBubble`, mask `0x0066d424`, mode 1 | Third alternate-frame call. |
| `0x00467d6b` | Balloon `PaintBubble`, mask `0x0066d428`, mode 1 | Fourth frame mask call. |
| `0x00467e5d` | Balloon `PaintBubble`, slot-6 mask call | Tail/frame composition call. |
| `0x00467efb` | Balloon `PaintBubble`, slot-6 mask call | Final tail/frame composition call. |
| `0x004b96c0` | `GrafPort_GetClipRect` callee | Retrieves active clip bounds. |
| `0x004b7cc0` | `IntersectRects` callee | Clips destination bounds. |
| `0x004b7eb0` | `IsRectEmptyOrInvalid` callee | Early-out after clipping. |
| `0x004b7c50` | `InitRectBounds` callee | Builds local zero-origin mask bounds. |
| `0x00543d40` | palette getter | Gets active palette. |
| `0x00542ac0` | color mapper, called twice | Maps foreground and background-fill indices. |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion:
  - UID0002TE already documents the four mode behaviors, exact RGB555 masks, clipping, target refs, and Surface route.
  - UID00016J establishes exact child boundaries and non-emitting aggregate topology.
  - UID0000TN and UID0001PI establish the semantic/physical callback table split.
  - UID00039V and UID0001G6 preserve both initializer routes.
  - UID000276 and UID0000YZ establish raw masks and the concrete indirect consumer.
  - UID0002TB provides the source-ready `BlendRgb555Half` helper in the same source unit.
- Ordinary documentation callback state:
  - UID0002TE now records exact ABI/name/mask/modes/range/source and emits exact CPP at `94/94`.
  - UID0000TN now owns the exact `SurfaceBitmaskBlitProc` H declaration/extern and CPP definition; UID0001PI documents the four-byte physical slot at `91/93` without duplicate formal storage.
  - UID0002TI now emits corrected `void __thiscall` source with destination bounds, `rowStridePixels`, `m_textBackFillColor`, and retained RGB565 behavior at `91/93`.
  - All accepted initializer, aggregate, GrafPort, Balloon, ignored-island, Surface, and source-tree support claims are incorporated at report-level detail.
  - Manual coverage rows were subsequently synchronized by the supervisor from the exact payload in this report. Commands `000000018631-000000018634` all exited `0` with `ok: 1`, including the dated coverage-time by-memory/generated refresh checkpoint under command `000000018634`.
- Dated generated implementation checkpoint: refresh command `000000018565` completed and the Surface CPP/H source-bearing headers then recorded command `000000018564`. At that checkpoint UID0002TE had one source marker and zero empty markers, and both providers plus the shared H/CPP callback topology were present. This checkpoint preserves semantic implementation evidence only; final supervisor lifecycle-time live generated readback is authoritative and unrelated empty markers remain outside scope.
- IDA status: supervisor Gate 2B is applied, read back exactly, and saved. B002 did not mutate IDA. The action table below preserves literal prestate as historical audit evidence and records the persisted disposition.

## Ranked Ownership Analysis

### 1. UID0000OC Surface

- Evidence for: exact initializer ownership, callback-table ownership, both pixel-format provider families, GrafPort rendering state, generated Surface.cpp root, nearby compat/RGB565 callback children, and absence of a feature-specific direct call.
- Evidence against: none material. The function receives GrafPort rather than a `Surface` object, but this is normal for the Surface-selected callback family.
- Decision: retain as canonical owner and emitter.

### 2. UID00005V GrafPort

- Evidence for: receiver is `GrafPort *`, and the body consumes current GrafPort layout and clip method.
- Evidence against: no GrafPort vtable/direct-method route; the implementation address is selected globally by Surface initialization and changes by pixel format.
- Decision: dependency/type owner only, not source owner.

### 3. UID0000YZ BalloonObjectPane

- Evidence for: nine concrete calls and static frame masks.
- Evidence against: calls are indirect through a shared slot, and neither provider references Balloon state. Feature-biased ownership would be callsite pollution.
- Decision: consumer only.

### 4. UID0000NT SoftwareBlend16

- Evidence for: RGB555 blend arithmetic.
- Evidence against: clipping, palette mapping, bitstream traversal, destination writes, and callback registration dominate the body; the blend helper is only one operation.
- Decision: helper dependency context only.

### Proposed new file/grouping, if applicable

- No new source file is required.
- Existing source placement: `NexusTK/render/Surface.cpp`, with callback typedef/global declarations in `NexusTK/render/Surface.h` through UID0000TN.
- Likely full contents remain the callback typedefs, callback globals, compat/RGB565 providers, and initializer already assigned to Surface.
- Rejected grouping: Balloon/AttachedObjectPane, GrafPort method file, SoftwareBlend16, RankingDialog, and aggregate-level duplicate emission.

## Source Placement

- Recommended target placement: file-local function in `NexusTK/render/Surface.cpp`, physically ordered with the compat callbacks before `SoftwareRenderCompatFillCallback`.
- Recommended declaration placement: `SurfaceBitmaskBlitProc` and `extern g_pfnBlitBitmask` in `Surface.h` through semantic UID0000TN; one definition in `Surface.cpp`.
- Why it fits: the initializer, slot, providers, peer family, palette/surface layouts, and generated root are all Surface infrastructure.
- Rejected placements: GrafPort.cpp would hide pixel-format provider selection; BalloonObjectPane.cpp would encode one consumer; SoftwareBlend16.cpp would conflate rendering state with scalar math; aggregate UID00016J would duplicate exact children.
- Remaining placement uncertainty: none that blocks source. The original project might have used a differently named private render file, but current project source topology consistently uses Surface.cpp and that is the correct reconstruction destination.

## Range / Split / Padding / Reclassification Analysis

- Exact target range remains `[0x004be0e0,0x004be66e)`. No widening or narrowing is recommended.
- Exact successor interval `[0x004be66e,0x004be680)` must remain outside UID0002TE formal source coverage:
  - `[0x004be66e,0x004be670)`: two-byte NOP/alignment data item.
  - `[0x004be670,0x004be680)`: `jpt_4BE218`, four little-endian code targets into the function.
- The source `switch(mode)` regenerates the table. A data declaration would be reverse-engineered pollution and duplicate compiler output.
- The next modeled function starts exactly at `0x004be680`; no boundary gap remains unclassified.
- No child creation, merge, or range reclassification is required.
- Aggregate UID00016J remains false/non-emitting; exact target UID0002TE remains the source body.

## Negative Evidence Summary

- No direct caller names the target or proves feature ownership.
- No vtable slot or direct GrafPort method call owns the function.
- No mask object fields are read; treating `maskBits` as `EPFTileContext *` or another class is unsupported.
- No return value is consumed. The early low-byte assignments in decompilation do not establish a source return.
- No source EDX argument exists. Consumer calls provide ECX plus three pushes, and the callee removes 12 stack bytes.
- No original symbol proves `BlitRgb555BitmaskCallback`; the consistent compat-family name is stronger.
- No source-authored jump-table object exists at the tail.
- Historical pre-Gate-2B state had no type named `SurfaceBitmaskBlitProc`; the supervisor deliberately introduced it and persisted exact four-byte readback.
- No reason exists to put declarations in the CPP formal block after current header-placement rules; the semantic table support page needs a real H disposition.
- The RGB565 peer's prior draft is not authoritative because it preserves decompiler ABI artifacts that contradict the shared consumer.

## IDA Rename / Type / Comment Recommendations

### Action table and persisted disposition

| Entity | Exact historical pre-Gate-2B state | Applied supervisor Gate 2B action | Safety evidence | Persisted exact readback |
| --- | --- | --- | --- | --- |
| Function `[0x004be0e0,0x004be66e)`, size `0x58e` | Historical prestate name: `sub_4BE0E0`. Historical prestate type: `char __fastcall(const struct GrafPort *, int, int, struct RectBounds *, char)`. Historical function-regular comment: blank. Historical function-repeatable comment: blank. Historical address-regular comment: blank. Historical address-repeatable comment: blank. Name-index query for `SoftwareRenderCompatBitmaskBlitCallback` returned zero hits. | Renamed to `SoftwareRenderCompatBitmaskBlitCallback`; applied `void __thiscall SoftwareRenderCompatBitmaskBlitCallback(GrafPort *port, const unsigned __int8 *maskBits, const RectBounds *destinationBounds, unsigned __int8 mode)`; set only this literal function-repeatable comment: `Surface-owned RGB555 compat packed-bitmask callback; GrafPort receiver, MSB-first 1bpp mask, destination bounds, and modes 0..3 for copy, color-key, and half-blend rendering.` | Exact receiver/stack cleanup/caller/body evidence; collision-free name. | Applied/readback name: `SoftwareRenderCompatBitmaskBlitCallback`. Applied/readback type: `void __thiscall(GrafPort *port, const unsigned __int8 *maskBits, const RectBounds *destinationBounds, unsigned __int8 mode)`. Applied/readback function-regular comment: blank. Applied/readback function-repeatable comment: `Surface-owned RGB555 compat packed-bitmask callback; GrafPort receiver, MSB-first 1bpp mask, destination bounds, and modes 0..3 for copy, color-key, and half-blend rendering.` Applied/readback address-regular comment: blank. Applied/readback address-repeatable comment: blank. Range, bytes, and two refs are unchanged. |
| Typedef `SurfaceBitmaskBlitProc` | Historical prestate type lookup: absent; no ordinal, declaration, or size. | The first scalar declaration call was rejected because the declaration was comma-split; the supervisor immediately retried with a JSON array containing this exact declaration: `typedef void (__thiscall *SurfaceBitmaskBlitProc)(GrafPort *port, const unsigned __int8 *maskBits, const RectBounds *destinationBounds, unsigned __int8 mode);` | Same ABI is proved by both providers and shared consumer; existing Surface callback typedefs are size 4. | Exact declaration used and read back: `typedef void (__thiscall *SurfaceBitmaskBlitProc)(GrafPort *port, const unsigned __int8 *maskBits, const RectBounds *destinationBounds, unsigned __int8 mode);`. The type exists as a four-byte function pointer; no unrelated type changed. |
| Physical slot head `0x0069b3f8` | Historical prestate item: `[0x0069b3f8,0x0069b3f9)`, size 1, byte `00`. Historical item-visible name: blank; historical name index: one `g_pfnBlitBitmask` at `0x0069b3f8`. Historical exact type/declaration: `int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)`. Historical address-regular comment: blank. Historical address-repeatable comment: blank. Historical function-regular and function-repeatable channels: not applicable to data. | Preserved/reasserted `g_pfnBlitBitmask`; replaced the four one-byte items with one exact `[0x0069b3f8,0x0069b3fc)` item; applied type `SurfaceBitmaskBlitProc`; set only this literal address-repeatable comment: `SurfaceBitmaskBlitProc g_pfnBlitBitmask; initialized with RGB555 compat 0x004BE0E0 or RGB565 0x004C3EA0 and called by BalloonObjectPane::PaintBubble.` A stale regular comment surfaced during reitemization and was cleared; the item-visible name temporarily became blank and was reasserted before save. | Exact four-byte source slot boundary, four zero bytes, 12 refs, collision-free name, and exact provider/consumer ABI. | Applied/readback item: `[0x0069b3f8,0x0069b3fc)`, size 4, bytes `00 00 00 00`. Applied/readback name: `g_pfnBlitBitmask`. Applied/readback type: `SurfaceBitmaskBlitProc`. Applied/readback address-regular comment: blank. Applied/readback address-repeatable comment: `SurfaceBitmaskBlitProc g_pfnBlitBitmask; initialized with RGB555 compat 0x004BE0E0 or RGB565 0x004C3EA0 and called by BalloonObjectPane::PaintBubble.` Applied/readback function-regular and function-repeatable channels: not applicable to data. All 12 refs are unchanged. |
| Trailing slot item at `0x0069b3f9` | Historical prestate item: `[0x0069b3f9,0x0069b3fa)`, size 1, byte `00`. Historical name: blank. Historical type/declaration: blank. Historical address-regular comment: blank. Historical address-repeatable comment: blank. Historical function-regular and function-repeatable channels: not applicable to data. | Removed only this independent one-byte item boundary as part of bounded four-byte reitemization; created no independent name, type, or comment. It became byte offset `+1` inside `g_pfnBlitBitmask`. | Address is inside the exact four-byte callback slot and had no independent xrefs or source identity. | Querying `0x0069b3f9` resolves to containing item `[0x0069b3f8,0x0069b3fc)`, size 4, name `g_pfnBlitBitmask`, type `SurfaceBitmaskBlitProc`; byte remains `00`. Independent name/type: none. Address-regular comment: blank. Address-repeatable comment: blank. Function channels: not applicable to data. |
| Trailing slot item at `0x0069b3fa` | Historical prestate item: `[0x0069b3fa,0x0069b3fb)`, size 1, byte `00`. Historical name: blank. Historical type/declaration: blank. Historical address-regular comment: blank. Historical address-repeatable comment: blank. Historical function-regular and function-repeatable channels: not applicable to data. | Removed only this independent one-byte item boundary as part of bounded four-byte reitemization; created no independent name, type, or comment. It became byte offset `+2` inside `g_pfnBlitBitmask`. | Address is inside the exact four-byte callback slot and had no independent xrefs or source identity. | Querying `0x0069b3fa` resolves to containing item `[0x0069b3f8,0x0069b3fc)`, size 4, name `g_pfnBlitBitmask`, type `SurfaceBitmaskBlitProc`; byte remains `00`. Independent name/type: none. Address-regular comment: blank. Address-repeatable comment: blank. Function channels: not applicable to data. |
| Trailing slot item at `0x0069b3fb` | Historical prestate item: `[0x0069b3fb,0x0069b3fc)`, size 1, byte `00`. Historical name: blank. Historical type/declaration: blank. Historical address-regular comment: blank. Historical address-repeatable comment: blank. Historical function-regular and function-repeatable channels: not applicable to data. The next indexed name was `g_pfnFillRect` at boundary `0x0069b3fc`. | Removed only this independent one-byte item boundary as part of bounded four-byte reitemization; created no independent name, type, or comment. It became byte offset `+3` inside `g_pfnBlitBitmask`. | Address is inside the exact four-byte callback slot; the next global begins exactly at `0x0069b3fc`, preventing widening. | Querying `0x0069b3fb` resolves to containing item `[0x0069b3f8,0x0069b3fc)`, size 4, name `g_pfnBlitBitmask`, type `SurfaceBitmaskBlitProc`; byte remains `00`. Independent name/type: none. Address-regular comment: blank. Address-repeatable comment: blank. Function channels: not applicable to data. |
| Protected neighbor `0x0069b3fc` | Historical prestate item: separate four-byte slot beginning at `0x0069b3fc`. Historical name: `g_pfnFillRect`. Historical type: `SurfaceFillRectProc`. Historical address-regular comment: blank. Historical address-repeatable comment: blank. Historical function-regular and function-repeatable channels: not applicable to data. | No action; explicitly protected from the bounded slot reitemization. | Exact next-slot boundary prevents UID0002TE storage from widening beyond `0x0069b3fc`. | Applied/readback remains a separate item beginning at `0x0069b3fc`, name `g_pfnFillRect`, type `SurfaceFillRectProc`; address-regular comment blank; address-repeatable comment blank; function channels not applicable. Bytes and boundary are unchanged. |
| Protected data `[0x004be66e,0x004be670)` | Historical prestate item size: 2. Historical name: blank. Historical type: blank. Historical bytes: `66 90`. Historical address-regular comment: blank. Historical address-repeatable comment: blank. Historical function-regular and function-repeatable channels: not applicable to data. | No action. | Compiler alignment/NOP between function and local table. | Applied/readback item size 2; name blank; type blank; bytes `66 90`; address-regular comment blank; address-repeatable comment blank; function channels not applicable. |
| Protected jump table `[0x004be670,0x004be680)` | Historical prestate name: `jpt_4BE218`. Historical item size: 16. Historical type: blank. Historical bytes: four target dwords. Historical address-regular comment: `jump table for switch statement`. Historical address-repeatable comment: blank. Historical function-regular and function-repeatable channels: not applicable to data. | No action; protected name, range, bytes, and comment. | Exact switch targets into UID0002TE. | Applied/readback name `jpt_4BE218`; item size 16; type blank; four target dwords unchanged; address-regular comment `jump table for switch statement`; address-repeatable comment blank; function channels not applicable. |

### Supporting type dependency table

| Type/global | Current existence/declaration/size | Action | Safety reason | Expected readback |
| --- | --- | --- | --- | --- |
| `GrafPort` | Exists, UDT size `0xa0`; relevant exact members `m_surfaceContext +0x1c`, `m_drawEnabled +0x71`, `m_drawColor +0x74`, `m_textBackFillColor +0x78`. | No change. | Current layout matches every target access. | Same name, size, members, and offsets. |
| `EPFTileContext` | Exists, UDT size `0x28`; `pixelData +0x04`, `rowStridePixels +0x0c`, `bounds +0x10`. | No change. | Exact destination formula matches current layout. | Same declaration and offsets. |
| `RectBounds` | Exists, UDT size `0x10`; `int left/top/right/bottom` at `0/4/8/0xc`. | No change. | Caller and target use exact 16-byte copies. | Same declaration and offsets. |
| `DLPalette` | Exists, size `556`; used by current map helper. | No change. | No layout mutation needed. | Same type. |
| `PaletteLib` / `g_pPaletteLib` | Type exists; global at `0x0067a7e0` is `PaletteLib *`. | No change. | Current getter call resolves active palette. | Same name/type/address. |

Negative constraints:

- Do not create a fourth stack argument, retain dummy EDX, or type the function as `__fastcall`.
- Do not change target bytes, function boundaries, switch-table bytes, target addresses, or slot xrefs.
- Reitemize only `[0x0069b3f8,0x0069b3fc)`. Do not consume, rename, retype, or comment the next item `g_pfnFillRect` at `0x0069b3fc`, and do not leave independent item heads at `0x0069b3f9`, `0x0069b3fa`, or `0x0069b3fb` after the action.
- Do not overwrite target internal line comments or local names as part of this bounded handoff.
- Do not rename the RGB565 peer in this target's Gate 2B action; its source-doc correction is ordinary support work, while any peer IDA action needs its own literal prestate audit.
- Do not convert the switch table into source data.
- B002 did not apply or save any IDA mutation. The supervisor performed, verified, and saved Gate 2B; saved IDB SHA256 is `7F3024691E4C38EA46E9160617C636ADFCA079D9CB76798866616FA1004BFB94`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Behavior, ABI, types, source location, and helper dependencies are resolved.
- Target CPP block disposition: replace blank UID0002TE formal CPP with the following exact insertion text.

```cpp
enum BitmaskBlitMode
{
    kBitmaskBlitCopy = 0,
    kBitmaskBlitColorKey = 1,
    kBitmaskBlitBlend = 2,
    kBitmaskBlitColorKeyBlend = 3
};

static void __thiscall SoftwareRenderCompatBitmaskBlitCallback(
    GrafPort *port,
    const unsigned char *maskBits,
    const RectBounds *destinationBounds,
    unsigned char mode)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds = *destinationBounds;
    IntersectRects(&clipBounds, &clippedBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    RectBounds maskBounds;
    InitRectBounds(
        &maskBounds,
        0,
        0,
        destinationBounds->right - destinationBounds->left,
        destinationBounds->bottom - destinationBounds->top);

    const int maskWidth = maskBounds.right - maskBounds.left;
    const int sourceTop =
        clippedBounds.top - destinationBounds->top + maskBounds.top;
    const int sourceLeft =
        clippedBounds.left - destinationBounds->left + maskBounds.left;
    const int sourceBottom =
        clippedBounds.bottom - destinationBounds->bottom + maskBounds.bottom;
    const int sourceRight =
        clippedBounds.right - destinationBounds->right + maskBounds.right;
    const int width = sourceRight - sourceLeft;
    const int height = sourceBottom - sourceTop;

    const int startBitOffset = sourceTop * maskWidth + sourceLeft;
    const unsigned char *rowMask = maskBits + startBitOffset / 8;
    unsigned char rowBit =
        static_cast<unsigned char>(startBitOffset % 8);

    unsigned short *rowPixels =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        (clippedBounds.top - port->m_surfaceContext.bounds.top) *
            port->m_surfaceContext.rowStridePixels +
        clippedBounds.left - port->m_surfaceContext.bounds.left;

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short primaryPixel =
        palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_textBackFillColor);

    switch (mode) {
    case kBitmaskBlitCopy:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                *pixel++ = (*mask & (0x80 >> bit)) != 0
                    ? primaryPixel
                    : secondaryPixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitColorKey:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                if ((*mask & (0x80 >> bit)) != 0) {
                    *pixel = primaryPixel;
                }
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitBlend:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                const unsigned short sourcePixel =
                    (*mask & (0x80 >> bit)) != 0
                        ? primaryPixel
                        : secondaryPixel;
                *pixel = BlendRgb555Half(*pixel, sourcePixel);
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitColorKeyBlend:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                if ((*mask & (0x80 >> bit)) != 0) {
                    *pixel = BlendRgb555Half(*pixel, primaryPixel);
                }
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    default:
        break;
    }
}
```

- Target H block disposition: keep UID0002TE H blank. The function and mode enum are file-local implementation details. The shared callback declaration belongs to UID0000TN H, not the target H.
- Reason it preserves behavior: exact guard, clipping, source offset, destination origin/stride, palette mapping, bit order, row carry, four modes, and RGB555 half-blend behavior are represented.
- Reason it matches plausible original source: it uses an outer switch with four optimized loops, old-MSVC-friendly `__thiscall`, file-local implementation, typed rectangles/surface context, existing helper reuse, and human names rather than decompiler temporaries.
- Inferred names: callback name, typedef, enum, argument names, and local names are descriptive. No `sub_`, `dword_`, raw offset, or dummy-register name remains.
- Naming convention: compat functions use `SoftwareRenderCompat...Callback`; fields follow current `m_...` UDT names; callback typedefs use `Surface...Proc`; globals use `g_pfn...`.
- Third-party import directive: not applicable; this is project-authored executable code.

### UID0000TN exact formal H replacement

The following is exact formal `RECONSTRUCTION_H CODE` insertion text for UID0000TN, not a prose example:

```cpp
class DLPalette;
class GrafPort;
struct EPFTileContext;
struct RectBounds;

typedef void (__thiscall *SurfaceDrawPixelProc)(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex);

typedef void (__thiscall *SurfaceDrawLineDeltaProc)(
    GrafPort *port,
    int deltaX,
    int deltaY);

typedef void (__thiscall *SurfaceFillRleProc)(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    DLPalette *palette);

typedef void (__thiscall *SurfaceBitmaskBlitProc)(
    GrafPort *port,
    const unsigned char *maskBits,
    const RectBounds *destinationBounds,
    unsigned char mode);

typedef void (__thiscall *SurfaceFillRectProc)(
    GrafPort *port,
    const RectBounds *bounds);

extern SurfaceDrawPixelProc g_pfnDrawPixel;
extern SurfaceDrawLineDeltaProc g_pfnDrawLineDelta;
extern SurfaceFillRleProc g_pfnFillRle;
extern SurfaceBitmaskBlitProc g_pfnBlitBitmask;
extern SurfaceFillRectProc g_pfnFillRect;
```

### UID0000TN exact formal CPP replacement

The following is exact formal `RECONSTRUCTION_CPP CODE` insertion text for UID0000TN, not a prose example:

```cpp
#include "Surface.h"

SurfaceDrawPixelProc g_pfnDrawPixel;
SurfaceDrawLineDeltaProc g_pfnDrawLineDelta;
SurfaceFillRleProc g_pfnFillRle;
SurfaceBitmaskBlitProc g_pfnBlitBitmask;
SurfaceFillRectProc g_pfnFillRect;
```

## Final Recommendation

- UID0002TE is implemented as exact source-ready Surface CPP at `94/94`, retaining owner/emitter/reconstructable fields and blank H.
- UID0000TN now emits the correct slot-6 typedef/declaration/definition through H/CPP; UID0001PI remains non-emitting physical evidence with no duplicate storage/body.
- UID0002TI ordinary documentation/formal source now uses the same exact void/thiscall ABI, canonical fields, `rowStridePixels`, and destination-bounds naming while preserving RGB565-specific `BlendRgb565Pixel` behavior at `91/93`.
- The compat aggregate, initializer/support, Surface file/source tree, GrafPort support, Balloon consumer/masks, and ignored island contain the accepted report facts and passed serial scoped validation.
- Supervisor Gate 2B applied and saved the two bounded IDA actions with exact readback, and B002 completed ordinary/report reconciliation; no additional UID0002TE IDA mutation or ordinary-document implementation is pending.
- After Singer's independent cross-check of all 16 ordinary hashes, eight manual rows, and the persisted IDA poststate, the supervisor independently closed exact catalog entry `0342 - UID0002TE - Surface RGB555 Compat Packed-Bitmask Callback And Slot 6` to `APPLIED_VERIFIED_RECONCILED`; no catalog reconciliation remains.
- Independent supervisor Gate 2A and exact manual coverage application/validation are complete under commands `000000018623-000000018629` and `000000018631-000000018634`. Only fresh exact-artifact Gate 1/Gate 2 verification and supervisor-only execution/archive remain.
- Do not create a new range, child, owner, handwritten jump-table declaration, mask object, or return value.
- Future work outside scope: other unresolved Surface callback slots. No UID0002TE blocker is forwarded.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md`.
- Applied state: C2TE-001..012, C2TE-025, C2TE-028, and generated C2TE-029 are incorporated at report-level detail; C2TE-025 has exact persisted supervisor Gate 2B readback.
- Prior dates and assumptions remain under explicit historical/superseded labels; current status/reconstruction/score wording is source-ready.
- Metadata:
  - `COMPLETION:94`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:0000OC`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000OC`
  - blank `EMITTER_POSITION_OPTIONAL`
  - exact formal CPP above
  - blank formal H
- Current Item Summary describes the exact source-ready void/thiscall ABI, raw MSB-first 1bpp mask, clipping, four modes, RGB555 helper reuse, Surface route, and nonblank formal CPP without repeating generated metadata fields.
- Preserve negative evidence: no direct callers, data-only provider refs, shared-slot ownership, ignored switch table, and rejected feature/GrafPort/SoftwareBlend16 ownership.

## Recommended Support Doc Changes

The table below records the applied/current support state. Its verbs describe completed incorporation, not work still delegated to B002.

| Support path / UID | Applied/current incorporation | Current metadata/formal disposition |
| --- | --- | --- |
| `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md` UID00016J | Lists UID0002TE as source-ready slot 6 with exact ABI/modes/blend/range and preserves the complete family inventory and ignored islands. | Current `90/92`; ownerless, false, non-emitting, blank formals. |
| `by-global/SurfaceRenderCallbackTable.md` UID0000TN | Resolves slot 6 typedef/global/providers/consumers with declarations in H and the single definition in CPP. | Current `93/94`; exact accepted H/CPP replacements are installed. |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` UID0001PI | Documents slot 6 as void/thiscall `SurfaceBitmaskBlitProc`, one four-byte zero slot, 12 refs, and semantic-owner emission. | Current `91/93`; physical formal blocks remain blank. |
| `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md` UID00039V | Uses the exact provider pair and typedef instead of provisional cast/return wording and preserves display-mode selection. | Current `91/93`; initializer formal assignment names remain. |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` UID0001G6 | Records resolved two-route slot-6 initialization as support, not direct emission. | Score/owner/formals remain unchanged. |
| `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md` UID000164 | Records the reciprocal dependency from the two bitmask providers. | Metadata remains unchanged. |
| `by-class/GrafPort.md` UID00005V and `by-file/GrafPort.md` | Record exact fields consumed and reject stale `m_secondaryDrawColor`/stride aliases for these callbacks. | Layout/source ownership remains unchanged. |
| `by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md` UID000276 | Records the raw packed 1bpp contract, exact table entries, mode 1 calls, and resolved typedef. | Current `90/94`; current class/source owner remains supported by the direct consumer. |
| `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md` UID0000YZ and `by-class/BalloonObjectPane.md` | Record nine void slot-6 calls with mask pointer, destination bounds, and mode 1 while preserving the consumer-only role. | Metadata remains unchanged. |
| `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md` UID0002TI | Uses the corrected formal return/calling convention, no dummy EDX, destination bounds, `rowStridePixels`, and `m_textBackFillColor`, while retaining four modes and the RGB565 helper. | Current `91/93`, Surface owner/emitter, nonblank corrected CPP, blank H. |
| `by-file/Surface.md` UID0000OC | Records source-ready slot-6 providers, shared declaration, completed marker removal, persisted Gate 2B readback, and header/source topology. | Current `90/89`; broader unresolved Surface caveats remain preserved. |
| `by-memory/-ignored.md` UID0000VN | Records the exact two-byte NOP plus 16-byte local jump-table split and hashes. | Ignored/100 remains unchanged. |
| `by-project-structure/proposed-source-tree.md` | Records Surface.h callback declarations and source-ready compat/RGB565 slot-6 implementations under Surface.cpp. | No score metadata. |

## Score And Metadata Recommendation

- Pre-callback target: `87/90`, owner/emitter UID0000OC, reconstructable true, blank position/CPP/H.
- Current applied target: `94/94`, same owner/emitter/reconstructable/position, exact nonblank CPP, blank H.
- Reason not lower: exact behavior, ABI, range, data island, ownership, types, source name, callback typedef, mode meanings, fields, helper, and formal source are all resolved with live evidence.
- Reason not higher:
  - No original debug symbol proves the exact callback/typedef/enum/local spellings.
  - No compiler binary-diff has yet confirmed instruction-for-instruction regeneration from the proposed source.
  - Internal loop variable widths are inferred from sign-extension/code shape rather than recovered declarations.
- Score-improvement attempt:
  - Final typedef blocker: resolved by shared consumer/provider ABI and current callback typedef family.
  - Public name blocker: resolved with initializer/family spelling and collision check.
  - Mask layout blocker: resolved as raw contiguous MSB-first 1bpp bytes.
  - Mode blocker: all four cases resolved.
  - Field/layout blocker: resolved with live current UDTs.
  - Source placement blocker: resolved to Surface CPP plus semantic table H.
  - Range blocker: exact function and ignored tail split resolved.
  - Blank C++ blocker: exact formal target CPP and support H/CPP provided.
- No unresolved issue justifies retaining the empty emitter or old score.

## Open Questions With Attempted Resolution

- Original callback name:
  - Checked current initializer formal, family names, target title, peer name, and name collisions.
  - Resolution: use `SoftwareRenderCompatBitmaskBlitCallback`; descriptive high-confidence name. Original lexical proof is unavailable but raw naming is not acceptable final source.
- Original typedef name:
  - Checked six existing `Surface...Proc` typedefs and global `g_pfn...` convention.
  - Resolution: `SurfaceBitmaskBlitProc` and `g_pfnBlitBitmask`.
- Original mode enum names:
  - Checked exact semantics and project naming style.
  - Resolution: file-local `BitmaskBlitMode` with copy/color-key/blend/color-key-blend names. Numeric behavior is exact; spellings are inferred.
- Rectangle role:
  - Checked every consumer rectangle and target's local source rectangle construction.
  - Resolution: destination bounds, not source bounds.
- Return type and EDX lane:
  - Checked all calls, epilogue, and return use.
  - Resolution: void `__thiscall`; no dummy EDX source parameter.
- Loop counter declarations:
  - Checked sign-extension in compiled loops and expected dimensions.
  - Resolution: use `short` loop counters to preserve plausible original code shape; width/height arithmetic remains int.
- Header/source split:
  - Checked current declarations incorrectly emitted in UID0000TN CPP and current project rule.
  - Resolution: declarations/externs in UID0000TN H; definitions in UID0000TN CPP; target function remains file-local CPP.
- Questions remaining unresolved: only exact original lexical spellings and compiler binary-diff. Neither blocks source, IDA handoff, metadata, or score 94.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- B002 inspected the historical manual rows and did not edit them. The following blocks preserve the exact supervisor replacement payloads supplied by this report. The supervisor subsequently applied these payloads to the three named coverage reports and validated them under commands `000000018631-000000018634`, all exit `0` / `ok: 1`.

File: `by-memory/-coverage-report.md`

Historical supervisor instruction, now applied and validated: replace the then-current UID00016J row with:

```text
    - [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) 0x004bb8d0-0x004c069e | function-family | SoftwareRenderCompatCallbacks : not reconstructable : 90% : very-strong : Non-emitting compat/RGB555 callback-family index over exact Surface-owned source children; UID0002PF pixel, UID0002TB RLE fill, and UID0002TE bitmask callbacks are source-ready with exact slot ABIs and formal child C++, while this aggregate remains ownerless, non-emitting, and blank to prevent duplicate emission.
```

Historical supervisor instruction, now applied and validated: replace the then-current UID0002TE row with:

```text
        - [UID:0002TE][0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback](by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md) 0x004be0e0-0x004be66e | function | SoftwareRenderCompatBitmaskBlitCallback : reconstructable : 94% : very-strong : Source-ready Surface slot-6 RGB555 compat bitmask callback with exact void __thiscall GrafPort/maskBits/destinationBounds/mode ABI, MSB-first packed 1bpp traversal, clipping and destination-pitch math, palette-mapped foreground/background-fill colors, four copy/color-key/half-blend modes, exact RGB555 BlendRgb555Half semantics, two provider refs, twelve shared-slot refs, and formal Surface.cpp C++.
```

Historical supervisor instruction, now applied and validated: replace the then-current UID0000VN successor-island row with:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004be66e-0x004be680 | switch-data | SoftwareRenderCompatBitmaskBlitCallback local jump table and alignment : ignored : 100% : very-strong : Exact two-byte 66 90 NOP/alignment at 0x004be66e followed by four-entry jpt_4BE218 at 0x004be670 targeting 0x004be21f, 0x004be2fe, 0x004be3cf, and 0x004be547; regenerate from the source switch and do not emit handwritten data.
```

Historical supervisor instruction, now applied and validated: replace the then-current UID0002TI row after its accepted support correction with:

```text
        - [UID:0002TI][0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback](by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md) 0x004c3ea0-0x004c4364 | function | SoftwareRenderRgb565BitmaskBlitCallback : reconstructable : 91% : very-strong : Source-ready Surface slot-6 RGB565 peer with the same exact void __thiscall GrafPort/maskBits/destinationBounds/mode ABI and packed-bit clipping/traversal contract as UID0002TE, four RGB565 copy/color-key/BlendRgb565Pixel modes, two provider refs, twelve shared-slot refs, corrected canonical GrafPort fields, and formal Surface.cpp C++.
```

Historical supervisor instruction, now applied and validated: replace the then-current UID0001PI row with:

```text
    - [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) 0x0069b3e0-0x0069b410 | function-pointer table | SurfaceRenderCallbackTable : reconstructable : 91% : very-strong : Twelve declaration-ordered zero-initialized Surface render callback globals with exact physical storage, initializer, and dispatch evidence; semantic UID0000TN emits the single Surface.h/Surface.cpp declaration-definition set, now including exact slot-6 SurfaceBitmaskBlitProc g_pfnBlitBitmask and source-ready RGB555/RGB565 providers, while this physical page stays blank to prevent duplicate storage.
```

Historical supervisor instruction, now applied and validated: replace the then-current UID000276 row after support implementation with:

```text
    - [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) 0x0066d414-0x0066d42c | initialized data table | BalloonObjectPaneStaticMasks : reconstructable : 90% : very-strong : Six exact four-byte MSB-first packed 1bpp BalloonObjectPane frame/tail masks consumed by nine PaintBubble calls through SurfaceBitmaskBlitProc g_pfnBlitBitmask with destination RectBounds and mode 1; exact data boundaries, consumer-only Surface dependency, and current class/source ownership are preserved.
```

File: `by-global/-coverage-report.md`

Historical supervisor instruction, now applied and validated: replace the then-current UID0000TN row with:

```text
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) : reconstructable : 93% : very-strong : Semantic/source owner for twelve fixed Surface render callback globals; Surface.h owns typed declarations and externs while Surface.cpp owns the single definitions, now including exact slot-6 SurfaceBitmaskBlitProc g_pfnBlitBitmask with void GrafPort receiver, packed mask bytes, destination RectBounds, and mode byte; physical UID0001PI remains blank to prevent duplicate storage and both RGB555/RGB565 slot-6 providers are source-ready.
```

File: `by-file/-coverage-report.md`

Historical supervisor instruction, now applied and validated: replace the then-current UID0000OC row with:

```text
- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 90% : strong : Generated root NexusTK/render/Surface.cpp plus Surface.h callback declarations owns callback typedefs/definitions, initializer selection, pixel-format/lookup globals, software callback families, and true Surface helpers; slot 6 now has exact SurfaceBitmaskBlitProc storage and source-ready RGB555 compat/RGB565 providers, while broader unresolved callback-family caveats remain preserved.
```

- Historical placement instruction, completed: replace the exact existing UID rows in place without inserting duplicates.
- Reason B002 must not apply directly: all `-coverage-report.md` files are supervisor-owned collision points, and coverage follows accepted ordinary implementation plus supervisor verification.
- Applied status: the supervisor replaced the exact existing rows without using B002 to edit a coverage file; `by-memory/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-file/-coverage-report.md` passed commands `000000018631`, `000000018632`, and `000000018633`, and the dated by-memory/generated refresh checkpoint command `000000018634` completed successfully.
- No validator-owned `auto-generated/-ag-*` row text was proposed or hand-edited. Command `000000018634` completed the documented coverage-time generated-refresh checkpoint; final supervisor lifecycle-time live generated readback remains authoritative.

## Follow-Up Actions

- Supervisor:
  - retain the completed prior exact-artifact Gate 1 acceptance, Gate 2A commands `000000018623-000000018629`, Gate 2B readback/save evidence, and coverage commands `000000018631-000000018634`; no further UID0002TE research, ordinary-document, IDA, coverage, or generated implementation action is requested;
  - retain the independently closed state of exact IDA catalog entry `0342 - UID0002TE - Surface RGB555 Compat Packed-Bitmask Callback And Slot 6`: `APPLIED_VERIFIED_RECONCILED`; technical IDA application/readback, ordinary/report reconciliation, and catalog-state reconciliation are complete;
  - perform fresh exact-artifact Gate 1/Gate 2 verification;
  - run the supervisor-only `execute_report`/archive lifecycle after both fresh gates pass.
- A-agent actions: none.
- B002 future research: none for UID0002TE. The accepted peer/table/header corrections are implemented; B002 remains available only for same-report repair if a fresh gate identifies a concrete defect.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong for `94/94`; the cap is conservative for inferred lexical names and lack of binary-diff proof.
- Remaining uncertainty: exact original private symbol, typedef, enum, and local variable spellings. The selected names are the most defensible human source names and no final source should retain IDA labels.
- No uncertainty remains about runtime behavior, range, source owner, emitter route, formal body eligibility, slot ABI, or data-island disposition.

## Validator Results

- Shared invocation context for every row below: cwd `E:\NTK\GhidraBridge\source-3\project-documentation`; validator-resolved documentation root `C:\FastStorage\NTK_Sources\source-3\project-documentation`. Every listed command exited `0` with `ok: 1`. B002 did not rerun or probe any validator during this final report-state reconciliation.

### Initial ordinary-document implementation validators

| ID / timestamp | Exact command | Warnings | Generated and document effects |
| --- | --- | --- | --- |
| `000000018355` / `2026-07-28T15:54:37-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md --apply --queue-timeout 240` | None. | Target validated at `94/94`; registry/type and UID0002TI link updates; projected stats updated; generated refresh deferred. |
| `000000018358` / `2026-07-28T15:55:25-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md --apply --queue-timeout 240` | None. | Aggregate validated at `90/92`; projected stats updated; generated refresh deferred. |
| `000000018362` / `2026-07-28T15:56:23-04:00` | `python .\tools\validator.py --mode file --file by-global/SurfaceRenderCallbackTable.md --apply --queue-timeout 240` | Three pre-existing missing-reference notices for UID0003XE. | Semantic table validated at `93/94`; registry/formal and UID0002TE/UID0002TI links updated; projected stats updated; generated refresh deferred. |
| `000000018363` / `2026-07-28T15:57:26-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md --apply --queue-timeout 240` | None. | Initializer validated at `91/93`; registry/reference updates and projected stats completed; generated refresh deferred. |
| `000000018364` / `2026-07-28T15:58:21-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00557140-0x00559aef.SurfacePresentation.md --apply --queue-timeout 240` | 29 pre-existing missing-reference notices involving UID00039P, UID00039R, UID00039U, UID0003A0, UID0003A1, and UID0003A2; 19 duplicate notices were suppressed. | UID0002TE/UID0002TI support references and projected stats updated; generated refresh deferred. |
| `000000018367` / `2026-07-28T15:59:05-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md --apply --queue-timeout 240` | One pre-existing missing-reference notice for UID0003XE. | UID0002TE/UID0002TI reciprocal references and projected stats updated; generated refresh deferred. |
| `000000018374` / `2026-07-28T16:00:01-04:00` | `python .\tools\validator.py --mode file --file by-class/GrafPort.md --apply --queue-timeout 240` | Three pre-existing missing-reference notices for UID0003XE. | Callback-field references and projected stats updated; generated refresh deferred. |
| `000000018380` / `2026-07-28T16:00:50-04:00` | `python .\tools\validator.py --mode file --file by-file/GrafPort.md --apply --queue-timeout 240` | Four pre-existing missing-reference notices for UID0003XE. | Callback/source references and projected stats updated; generated refresh deferred. |
| `000000018383` / `2026-07-28T16:01:59-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md --apply --queue-timeout 240` | None. | Masks page validated at `90/94`; UID0002TE reference and projected stats updated; generated refresh deferred. |
| `000000018391` / `2026-07-28T16:04:59-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240` | Three pre-existing missing-reference notices for UID0003XE. | Physical table validated at `91/93`; projected stats updated; generated refresh deferred. |
| `000000018394` / `2026-07-28T16:06:15-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md --apply --queue-timeout 240` | None. | UID0002TE, UID0002TI, and UID000276 links plus projected stats updated; generated refresh deferred. |
| `000000018399` / `2026-07-28T16:06:47-04:00` | `python .\tools\validator.py --mode file --file by-class/BalloonObjectPane.md --apply --queue-timeout 240` | None. | UID0000TN, UID0002TE, and UID0002TI references and projected class rows updated; generated refresh deferred. |
| `000000018409` / `2026-07-28T16:09:22-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md --apply --queue-timeout 240` | None. | RGB565 peer validated at `91/93`; registry/formal and projected stats updated; generated refresh deferred. |
| `000000018413` / `2026-07-28T16:10:36-04:00` | `python .\tools\validator.py --mode file --file by-file/Surface.md --apply --queue-timeout 240` | 15 pre-existing missing-reference notices involving UID00039R, UID00039P, and UID0003XE; five duplicate notices were suppressed. | Surface validated at `90/89`; UID0000YZ link and projected stats updated; generated refresh deferred. |
| `000000018415` / `2026-07-28T16:11:17-04:00` | `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240` | 200 pre-existing missing-reference notices; visible UIDs were UID0003J2, UID0003J3, UID0003BR, UID0003BU, UID0003BV, UID0003BX, UID0003II, UID0003IJ, and UID0003IK; 190 notices were suppressed. | UID0003VS reference and projected stats updated; generated refresh deferred. |
| `000000018417` / `2026-07-28T16:12:02-04:00` | `python .\tools\validator.py --mode file --file by-project-structure/proposed-source-tree.md --apply --queue-timeout 240 --wait-generated` | Five pre-existing missing-reference notices: UID0003LP, UID0003WL, UID0003WM, UID0003WN, and UID0003WO. | Registry rebuilt to 5,370 nodes / 4,199 edges; generated coverage metadata, C++/header metadata, and projected stats refreshed; generated refresh completed. |

### Post-IDA ordinary-document reconciliation validators

| ID / timestamp | Exact command | Warnings | Generated and document effects |
| --- | --- | --- | --- |
| `000000018560` / `2026-07-29T00:11:59-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md --apply --queue-timeout 240` | None. | Target projected stats updated; generated refresh deferred. |
| `000000018561` / `2026-07-29T00:12:01-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md --apply --queue-timeout 240` | None. | Aggregate projected stats updated; generated refresh deferred. |
| `000000018562` / `2026-07-29T00:12:03-04:00` | `python .\tools\validator.py --mode file --file by-global/SurfaceRenderCallbackTable.md --apply --queue-timeout 240` | Three pre-existing missing-reference notices for UID0003XE. | Semantic-table projected stats updated; generated refresh deferred. |
| `000000018563` / `2026-07-29T00:12:16-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240` | Three pre-existing missing-reference notices for UID0003XE. | Physical-table projected stats updated; generated refresh deferred. |
| `000000018564` / `2026-07-29T00:12:28-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md --apply --queue-timeout 240` | None. | Initializer projected stats updated; generated refresh deferred. |
| `000000018565` / `2026-07-29T00:12:37-04:00` | `python .\tools\validator.py --mode file --file by-file/Surface.md --apply --queue-timeout 240 --wait-generated` | 15 pre-existing missing-reference notices involving UID00039R, UID00039P, and UID0003XE; five duplicate notices were suppressed. | Registry rebuilt to 5,376 nodes / 4,204 edges; generated coverage metadata, C++/header metadata, and projected stats refreshed; generated refresh completed. |

- Dated implementation-time generated checkpoint after command `000000018565`: source-bearing headers recorded command `000000018564` at `2026-07-29T00:12:28-04:00`; `Surface.cpp` was SHA256 `7D6462EE50C0089A28DD0EB37FC77E599C32264C5653F081109DF9BDA313B79E`, 53,997 bytes, mtime `2026-07-29T00:13:15.5153023-04:00`; `Surface.h` was SHA256 `FA920EBA7FCD10B9FCE3D67B23C90C73CC8CFB99EF9B6A38EBD5421D18F17761`, 1,606 bytes, mtime `2026-07-29T00:13:15.5439899-04:00`.
- At that dated checkpoint, CPP had UID0002TE once, UID0002TI once, both exact provider definitions, and both initializer assignments; H had `SurfaceBitmaskBlitProc` twice (typedef plus extern context) and `g_pfnBlitBitmask` once. Both files had zero `sub_4BE0E0`, `sub_4C3EA0`, `dword_69B3F8`, and `BlitRgb565BitmaskCallback` labels; UID0002TE/UID0002TI had zero empty markers. Twelve unrelated Surface children remained empty markers and one unrelated provider retained `m_secondaryDrawColor` outside scope.
- Commands `000000018564-000000018565` and those two hashes are dated implementation-time checkpoint evidence only. They preserve one-definition/no-empty-marker proof for that checkpoint; they are not claims about the final live files. Final supervisor lifecycle-time generated readback is authoritative.

### Independent supervisor Gate 2A validators

| ID / timestamp | Exact command | Warnings | Generated and document effects |
| --- | --- | --- | --- |
| `000000018623` / `2026-07-29T00:39:01-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md --apply --queue-timeout 240 --no-generated-refresh` | None. | Target projected stats updated; generated refresh explicitly skipped. |
| `000000018624` / `2026-07-29T00:39:03-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md --apply --queue-timeout 240 --no-generated-refresh` | None. | Aggregate projected stats updated; generated refresh explicitly skipped. |
| `000000018625` / `2026-07-29T00:39:05-04:00` | `python .\tools\validator.py --mode file --file by-global/SurfaceRenderCallbackTable.md --apply --queue-timeout 240 --no-generated-refresh` | Three pre-existing missing-reference notices for UID0003XE. | Semantic-table projected stats updated; generated refresh explicitly skipped. |
| `000000018626` / `2026-07-29T00:39:08-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240 --no-generated-refresh` | Three pre-existing missing-reference notices for UID0003XE. | Physical-table projected stats updated; generated refresh explicitly skipped. |
| `000000018627` / `2026-07-29T00:39:10-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md --apply --queue-timeout 240 --no-generated-refresh` | None. | Initializer projected stats updated; generated refresh explicitly skipped. |
| `000000018628` / `2026-07-29T00:39:12-04:00` | `python .\tools\validator.py --mode file --file by-file/Surface.md --apply --queue-timeout 240 --no-generated-refresh` | 15 pre-existing missing-reference notices involving UID00039R, UID00039P, and UID0003XE; five duplicate notices were suppressed. | Surface projected stats updated; generated refresh explicitly skipped. |
| `000000018629` / `2026-07-29T00:39:14-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md --apply --queue-timeout 240 --wait-generated` | None. | Registry rebuilt to 5,378 nodes / 4,204 edges; generated child fallback count 11, missing-marker count 72, emitter count 100, header-metadata count 27, header no-op count 242, generated-metadata count 277, research-tracker update count 1, and projected stats refreshed; generated refresh completed. |

### Supervisor-owned coverage validators

| ID / timestamp | Exact command | Warnings | Generated and coverage effects |
| --- | --- | --- | --- |
| `000000018631` / `2026-07-29T00:40:23-04:00` | `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --no-generated-refresh` | Two pre-existing missing-reference notices: UID00039L and UID0003T6. | Exact by-memory payload validated; projected stats updated; generated refresh explicitly skipped. |
| `000000018632` / `2026-07-29T00:40:26-04:00` | `python .\tools\validator.py --mode file --file by-global/-coverage-report.md --apply --queue-timeout 240 --no-generated-refresh` | One pre-existing missing-reference notice: UID0003MS. | Exact by-global payload validated; projected stats updated; generated refresh explicitly skipped. |
| `000000018633` / `2026-07-29T00:40:28-04:00` | `python .\tools\validator.py --mode file --file by-file/-coverage-report.md --apply --queue-timeout 240 --no-generated-refresh` | None. | Exact by-file payload validated; projected stats updated; generated refresh explicitly skipped. |
| `000000018634` / `2026-07-29T00:40:30-04:00` | `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --wait-generated` | Two pre-existing missing-reference notices: UID00039L and UID0003T6. | Registry rebuilt to 5,378 nodes / 4,204 edges; generated child fallback count 11, missing-marker count 72, emitter count 100, header-metadata count 27, header no-op count 242, generated-metadata count 278, projected stats refreshed; generated refresh completed. |

- Initial, post-IDA, Gate 2A, and coverage commands above all returned exit `0` / `ok: 1`; the listed warnings were pre-existing broad-page/reference notices and no UID0002TE-specific validation error remained.
- Command `000000018634` is a later coverage-time generated-refresh checkpoint than `000000018565`, but it is not asserted as permanent current state. Final supervisor lifecycle-time live generated readback after `execute_report`/archive is authoritative; this report deliberately does not chase current generated hashes.

## Changed Files

- Existing report updated in place: `tools/leaser/Agents/Agent-B002/research/0002TE-SoftwareRenderCompatBitmaskBlitCallback-empty-emitter-source-quality.md`.
- Modified ordinary documents and their preserved post-IDA implementation-checkpoint SHA256 values; supervisor Gate 2A later passed under commands `000000018623-000000018629`, but the callback did not supply replacement ordinary-document hashes:
  - `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md` - `3116C3418E06A433644EF16C716EA6952B933BFC2186A98B82C68C109CF4FB13`.
  - `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md` - `DDFE665182C79C2F64DF96EFB4B6E6A51C356A2C019C05F8F85EB69F0C9D6D9A`.
  - `by-global/SurfaceRenderCallbackTable.md` - `C79FC9E7989895198360FF687A4E10519FD6C912BEF317B7390710E7670E4270`.
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` - `3FF79C4FC7A00FBFB73AC4EBC04DACFCB8AFCEE7527B7AB1BF8DB7C7463899ED`.
  - `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md` - `E0C88B5D8655975055E134C09716D958C4AC598781DDE66AC4D0F958855942DA`.
  - `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` - `CFF844A2E10F6342236566D7A21B5338FD1C316048245364A2D32C0AED4B919F`.
  - `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md` - `9A376F9D2E90CF2428592275AF73667B8851E7BD3DFB9BC1D1733D33E77C7FFB`.
  - `by-class/GrafPort.md` - `E863CD211A23A0CE1042B9C89E8EF7496FA29CD32C5272049F2162F10F481613`.
  - `by-file/GrafPort.md` - `44FEE161B6E42B35D2B9CF765BF675A2B2B165E770E156E07DD8978FD70A9A45`.
  - `by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md` - `D825054B7D55CBEBEDBE1C3EF4829C62727C83EED752CBB06DAB4E3A98522385`.
  - `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md` - `B24AE58AE3B778302CD1443DD61A27BA40C35C9CF7F4726C707B70C6027FEAFB`.
  - `by-class/BalloonObjectPane.md` - `7918140C3CC88B61BE0636F5A31DECDED7619C86715B93CE4F1A5607F5B9C2E6`.
  - `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md` - `B992A2F50369C4743B9F6FC11012AC6865E4915209E2C13141C678A606C1C253`.
  - `by-file/Surface.md` - `F9DF982285257FEB0B56976AFD9400DA1ED3027A06C9EC49992628802DD48A24`.
  - `by-memory/-ignored.md` - `64D0FEE49591764B5C9213AC05F5E193C1686D1EB828981068911DE14734FCED`.
  - `by-project-structure/proposed-source-tree.md` - `4823946CE895697E54E0A2D1F1B57196564371F61F20002C9D529973D3E3F189`.
- Renamed: none.
- IDA: B002 remained read-only. Supervisor Gate 2B mutation/readback/save is reconciled above; persisted IDB SHA256 is `7F3024691E4C38EA46E9160617C636ADFCA079D9CB76798866616FA1004BFB94`.
- B002 coverage/tracker/audit/catalog/goal/notes edits: none. After B002's ordinary-document work, the supervisor applied the report's exact payloads to `by-memory/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-file/-coverage-report.md` and validated/refreshed them under commands `000000018631-000000018634`; B002 did not hand-edit those files. Generated Surface CPP/H and validator registry/stat artifacts changed only through authorized validator/generated-refresh workflows.
- Final reconciliation callback changed only this existing report. No by-* document, IDA state, coverage/generated file, supervisor file, goal/notes file, or validator state was edited or invoked by B002 during this callback.
- Report execution: not run. B002 did not run, probe, dry-run, or issue `execute_report` or any report lifecycle command.
- Leases: B002 leased only the six post-IDA edited ordinary pages for the immediate edit/validator batch. The leases expired during serial validation; the shared lease report was rechecked afterward and shows no active B002 lease.

### Post-IDA 16-destination stale-state inspection

| Destination | Result |
| --- | --- |
| UID0002TE target | Edited: stale current function/type/slot and pending Gate 2B wording replaced; dated raw observations retained as history. |
| UID00016J compat aggregate | Edited: current provider identity and persisted slot route synchronized. |
| UID0000TN semantic callback table | Edited: exact persisted typedef/item/comment/save evidence added. |
| UID0001PI physical callback table | Edited: current raw slot name replaced and exact one-item readback added. |
| UID00039V initializer | Edited: persisted target/slot state synchronized to existing formal assignments. |
| UID0001G6 SurfacePresentation | Inspected, no edit: already uses accepted names and labels raw aliases historical. |
| UID000164 GrafPortGetClipRect | Inspected, no edit: no stale UID0002TE IDA state. |
| GrafPort class | Inspected, no UID0002TE edit: callback ABI is current; its separate pending layout Gate 2B note is unrelated. |
| GrafPort file | Inspected, no edit: source/dependency ownership is current. |
| UID000276 Balloon masks | Inspected, no edit: current typedef/slot contract is correct; raw labels occur only in dated evidence. |
| UID0000YZ BalloonObjectPane | Inspected, no edit: accepted typed call route is current; raw labels are explicit history. |
| BalloonObjectPane class | Inspected, no edit: accepted typed call route is current; raw labels are explicit history. |
| UID0002TI RGB565 peer | Inspected, no edit: shared slot source contract is current; peer's own IDA identity and dated raw observations are outside UID0002TE Gate 2B. |
| UID0000OC Surface file | Edited: current provider/slot identities, persisted Gate 2B evidence, and completed marker removal synchronized. |
| `by-memory/-ignored.md` | Inspected, no edit: only protected successor switch/alignment evidence; no stale target/slot current state. |
| proposed source tree | Inspected, no edit: source typedef/global/provider topology is already current. |

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Initial exact artifact SHA256 `7C12A32A7A28DC56BE3989C78BEBF1265C831F62D1F0E7F31764DD339DD2FE70` accepted by supervisor for implementation.
- [x] Target/support doc update plan completed and implemented for UID0002TE, UID00016J, UID0000TN, UID0001PI, UID00039V, UID0001G6, UID000164, GrafPort class/file, UID000276, UID0000YZ/BalloonObjectPane, UID0002TI, UID0000OC, `by-memory/-ignored.md`, and `by-project-structure/proposed-source-tree.md`.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable; no additional target UID is declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger reconciled from planned to actual ordinary/generated verification state for every claim.
- [x] Metadata/score plan applied: UID0002TE `94/94`, UID00016J `90/92`, UID0000TN `93/94`, UID0001PI `91/93`, UID00039V `91/93`, UID000276 `90/94`, UID0002TI `91/93`, and UID0000OC `90/89`; unchanged support scores remained unchanged.
- [x] Score-limiting blockers researched to resolution: ABI, return, names, mask layout, mode semantics, fields, source placement, range, and formal source are resolved.
- [x] Owner/emitter/reconstructable route completed: target owner/emitter/reconstructable retained; aggregate/physical non-emitting dispositions retained.
- [x] Split/rename/new-child analysis completed: no target split; ignored tail text refinement only.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment handoff analysis completed.
- [x] Supervisor Gate 2B handoff and persisted reconciliation completed: historical four-byte-item prestate, exact actions, corrected intermediate tool failures, final function/type/comments, one four-byte slot item, protected neighbor, unchanged bytes/xrefs/ranges, and saved-IDB identity are recorded.
- [x] First-draft source implementation completed: exact target CPP, blank target H, exact UID0000TN H/CPP, and corrected UID0002TI CPP/blank H are installed and generated-read back.
- [x] Third-party import directive assessed as not applicable because the target is project-authored source.
- [x] Exact target/support facts to incorporate are recorded at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve are recorded.
- [x] Wave2/Wave3 mentions or artifacts were excluded as stale.
- [x] Open questions are closed or documented with evidence-backed inferred lexical resolutions.
- [x] Validator plan executed serially for all sixteen changed ordinary documents; exact command IDs/results are recorded.
- [x] Generated plan completed initially under command `000000018417` and was revalidated after Gate 2B at the dated implementation checkpoint under refresh command `000000018565` / source-bearing header command `000000018564`; the report records checkpoint Surface CPP/H hashes and one-definition/no-empty-marker topology, not permanent current hashes.
- [x] Manual supervisor-owned coverage payload applied exactly to the three named coverage reports and validated under commands `000000018631-000000018634`; command `000000018634` completed the later coverage-time generated-refresh checkpoint.
- [x] Generated-currentness authority is explicit: commands `000000018564`, `000000018565`, and `000000018634` are dated checkpoints, while final supervisor lifecycle-time live generated readback after execution/archive is authoritative.

Implementation callback pass:

- [x] Supervisor-owned IDA changes were applied/read back/saved by the supervisor and reconciled by B002; B002 did not mutate IDA.
- [x] Report accepted by supervisor for implementation at exact pre-callback SHA256 above.
- [x] All accepted target/support ordinary-doc details incorporated at report-level detail.
- [x] Primary UID0002TE verified against ledger, destination doc, validator result, and generated definition.
- [x] Claim And Incorporation Ledger updated from planned to actual verification states.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied or explicitly retained with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed lexical rationale.
- [x] Validators run and exact results recorded.
- [x] Post-IDA serial validators `000000018560-000000018565` and generated CPP/H refresh/readback completed.
- [x] No accepted ordinary-document or generated-verification item remains unapplied.
- [x] Prior exact-artifact supervisor Gate 1 completed and authorized the accepted implementation/lifecycle progression.
- [x] Supervisor Gate 2A ordinary-doc verification completed under commands `000000018623-000000018629`, all exit `0` / `ok: 1`; command `000000018629` completed its dated generated-refresh checkpoint.
- [x] Supervisor Gate 2B technical IDA application/readback/save is complete, and B002 ordinary/report reconciliation is complete.
- [x] Supervisor manual coverage application/validation completed under commands `000000018631-000000018634`, all exit `0` / `ok: 1`; command `000000018634` completed its dated coverage-time generated-refresh checkpoint.
- [x] After Singer independently confirmed all 16 ordinary hashes, eight manual rows, and persisted IDA poststate, the supervisor closed exact catalog entry `0342 - UID0002TE - Surface RGB555 Compat Packed-Bitmask Callback And Slot 6` to `APPLIED_VERIFIED_RECONCILED`.
- [ ] Fresh exact-artifact supervisor Gate 1/Gate 2 verification remains pending.
- [ ] Supervisor-only `execute_report`/archive remains pending.

READY_FOR_SUPERVISOR_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000018734","destination_path":"executed-b-agent-research/B002/0002TE-SoftwareRenderCompatBitmaskBlitCallback-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002TE-SoftwareRenderCompatBitmaskBlitCallback-empty-emitter-source-quality.md","timestamp":"2026-07-29T02:23:54-04:00","uid":"0002TE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
