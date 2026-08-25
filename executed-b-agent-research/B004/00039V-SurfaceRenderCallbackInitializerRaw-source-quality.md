** TARGET-REPORT-UID:00039V **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# 00039V InitializeSurfaceRenderCallbacks Source-Quality Report

## Finalized Report / Current Recommendation
- Current recommendation: retain the completed UID-preserving rename to `0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md`, target score `90/92`, and one complete free-function definition through [UID:0000OC] `Surface`.
- Final disposition: one NexusTK source-authored, no-argument, `void` free function at exact half-open range `[0x00558690,0x0055883d)`. It is not padding, not a compiler helper, not a two-function sequence, not a child of UID00039W, and not dead source merely because IDA lacks a function object and direct machine callers.
- Completed callback state: `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` are preserved; the exact managed block is present; and the bounded Surface, aggregate, initializer, flag, and callback-table support pages are synchronized without copying a callback implementation body.
- Confidence: high for bytes, boundaries, control flow, ABI, DirectDraw query, flags, all 24 selected callback targets, table writes, owner, and source-level inlining; medium-high for the descriptive original function and global pointer spellings because no PDB or source symbol survives.

## Supporting Research
- Mandatory live evidence was collected at `2026-07-13T13:03:23-04:00` through the streamable MCP endpoint. `idb_list` returned the named `supervisor_nexustk_20260713` NexusTK session, and `server_health(database=supervisor_nexustk_20260713)` returned `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true` at that evidence time.
- Callback-start MCP availability was rechecked before editing: schema-refreshed `idb_list` returned `supervisor_nexustk_20260713`, `server_health` returned `status:ok`, and schema-current bounded `get_bytes` returned the real UID00039V prologue. Two initial local PowerShell JSON-wrapper/schema payload errors were corrected client-side; no IDB-backed call reported a missing/unreachable session and no MCP outage occurred.
- A bounded target probe succeeded: `lookup_funcs(0x00558690, 0x0055883d)` returned `Not a function` for both addresses, while `get_bytes(0x00558690, 32)` returned the real `55 8b ec 81 ec 88 ...` prologue bytes. The absent IDA function object is therefore a modeling defect, not an availability failure or no-code proof.
- Binary survey at evidence time identified `NexusTK.exe`, image base `0x00400000`, 32-bit architecture, image size `0x2b3000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, and SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Old-report searches used the concrete terms `UID00039V`, `UID:00039V`, `00039V`, `0x00558690`, `0x0055883d`, `SurfaceRenderCallbackInitializerRaw`, `SurfaceRenderCallback`, `SurfacePresentation`, `0x0069b3e0`, `0x0069b3fc`, `0x00558811`, `0x00558770`, `0x00558ee2`, `UID0002YK`, `UID0002PF`, `g_surfaceUses32BitPresentation`, `g_surfaceUsesRgb565Pixels`, `Surface`, and `DirectX` across agent research paths present when searched and `executed-b-agent-research`.
- Matching executed report opened: `executed-b-agent-research/B001/0001G6-SurfacePresentation.md`. It is the aggregate split source and proves the target/padding inventory, but its UID00039V row is intentionally shallow and contains no dedicated liveness, inline-duplicate, ABI, or formal-C++ resolution.
- Matching executed report opened: `executed-b-agent-research/B006/00039W-SurfaceMinimapRenderInitializer-source-quality.md`. It proves the following modeled initializer and its startup receiver/source-route conflict. Its copied sentence that calls `0x00558811` the compat `0x004be680` load is stale; live disassembly proves `0x00558811` loads RGB565 target `0x004c4380`, while compat target `0x004be680` is loaded at `0x00558723`.
- Matching executed report opened: `executed-b-agent-research/B002/0002YK-SoftwareRenderRgb565FillCallback-source-quality.md`. It independently records `0x00558811 -> 0x004c4380 -> 0x00558770 -> 0x0069b3fc` and modeled peer store `0x00558ee2 -> 0x0069b3fc`, confirming the live-MCP correction.
- Matching executed report opened: `executed-b-agent-research/B011/0002PF-SoftwareRenderCompatPixelCallback-source-quality.md`. It proves slot 0's compat target ABI and source-ready body, and it treats the initializer refs as data setup rather than ordinary callback callers.
- Matching report opened from the B011 research path that existed when searched: `tools/leaser/Agents/Agent-B011/research/00029U-SurfacePixelFormatFlags-source-quality.md`. It records zero image bytes at its evidence time, descriptive D4/D5 names, seven/sixteen xrefs, and the exact 32/24/16-bit flag rules. Its lifecycle state is not inferred here.
- The exact-term search found no earlier dedicated report with `TARGET-REPORT-UID:00039V`. Broad Surface/callback matches were treated only as leads and did not substitute for the mandatory current binary pass.

## Target
- Target UID: `00039V`.
- Historical target path before callback: `by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md`.
- Current UID-preserving target path after callback: `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md`; the old path is absent and the UID header is unique.
- Historical source queue/report snapshot: `auto-generated/-ag-research-tracker.md` recorded `85/88`, average `86.5`, reconstructable `true`, and report count `0` before this report. That pre-callback snapshot is not asserted as current or permanent tracker truth.
- Current artifact classification: research and implementation callback evidence are complete. Report validation, execution, counting, path movement, and archive state remain external supervisor/validator-owned facts.
- Current scores and parent state: `90/92`, owner/emitter [UID:0000OC] `Surface`, reconstructable true, blank position, exact populated formal C++, and `Nested:0`.

## Current Target State
- Current metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Current owner/emitter/reconstructable state: the Surface owner and emitter route remain unchanged and are now backed by the complete source-quality explanation.
- Current C++/emitter state: the exact formal block is populated. Waited refresh command `000000009979` emits one UID00039V definition and no target Empty Emitter Marker in `auto-generated/NexusTK/render/Surface.cpp`.
- Resolved historical blockers: the absent IDA function object and zero direct caller xrefs are retained as negative machine-route evidence; typed source shape, exact signature/body, DirectDraw local, complete branches, UID00039W inline liveness, semantic globals, and corrected slot-7 routing are now documented and emitted.
- Related target/support docs checked: UID0001G6 aggregate, UID00039U predecessor, UID00039W successor, UID00029U flags, UID0000TN global callback group, UID0001PI exact callback storage, UID0002YK RGB565 fill, UID0002PF compat pixel, both callback-family aggregates and their 24 exact children, `by-file/Surface.md`, `by-file/DirectX.md`, `by-global/g_pDirectX.md`, generated `Surface.cpp`, and the research tracker row.
- Current artifact/lifecycle status: research, bounded implementation, scoped validation, and generated verification are complete. B004 performed no report execute, move, archive, or lifecycle command; report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed here.

## Executive Recommendation
- Keep the exact body as one Surface-owned source function. The direct semantic owner is [UID:0000OC] `Surface`; [UID:0000TN] owns the callback-global documentation grouping, and [UID:0000IW] `DirectX` supplies the queried interface, but neither owns this executable source body.
- Rename the source identity from the raw documentation label to descriptive human source name `InitializeSurfaceRenderCallbacks`. Use a free function, not a Surface member or ScreenPane method: the raw ABI has no receiver, no arguments, and no object-field accesses.
- Treat the standalone function as source-live through inlining. The complete semantic body is duplicated inside the immediately following UID00039W function after DirectDraw surface creation and before lookup-table allocation. The compiler inlined the source call but retained an out-of-line externally linked copy, explaining zero direct machine calls.
- Use twelve typed module-global callback pointers rather than a pointer to a runtime table object. Every consumer and initializer references a fixed absolute slot, no code indexes the base or loads a table-object pointer, and the contiguous 48-byte block is best understood as a documentation aggregate over declaration-ordered globals.
- Populate exact first-draft C++ now. Neither the absent IDA function object nor the zero direct-call count remains a blocker after the inline-copy proof.

## Supervisor Active Recheck
- Historical Gate 1 scope assigned UID00039V only, required mandatory healthy MCP and the complete literal template, and forbade by-* edits, validators, leases, and report lifecycle commands during research. The later accepted implementation callback authorized only the seven destinations recorded below.
- Split repair is not required. The exact target is one function between eight predecessor `0xcc` bytes and three successor `0xcc` bytes. Internal late blocks after the first textual `retn` are reached by branches from the entry flow and must not become children.
- Every source-bearing item in the target range is accounted for by the one function. UID00039U, both padding spans, UID00039W, 24 callback implementations, two flags, and callback storage remain separate existing items.

## Inference Research Guidance Check
- `by-structure.md` classifies full raw function bodies and reconstructed source as `by-memory`, allows C++ only with a confirmed emitter and combined score above 85, limits the block to the page's own range, and requires source-quality names instead of decompiler scaffolding. UID00039V satisfies those conditions after this pass.
- Existing assumptions treated as uncertain were: no-caller means dead/no-code; adjacency proves ownership; the raw range might contain multiple helpers; the callback block is necessarily a C++ struct; `0x00558811` is compat setup; and raw IDA names are acceptable source names.
- Direct IDA facts are separated below from documentation evidence and inference. The original symbol spellings are not claimed as recovered symbols; `InitializeSurfaceRenderCallbacks` and the `g_pfn*` names are descriptive, evidence-backed reconstruction names.
- Wave2/Wave3 material was not used. Any stale mentions encountered in broad repository search were ignored under the current project skill.

## Heuristic / Inference Reanalysis And Validation
- Function-boundary heuristic: the target has a standard prologue at `0x00558690`, one stack frame, one cookie, one logical return path, and a final internal jump at `0x00558838` whose five bytes end exactly at `0x0055883d`. Eight `0xcc` bytes precede it and three follow it. Decision: one exact function, no split.
- Late-block heuristic: the textual `retn` at `0x005587b7` is not the end of source control flow. Branches from `0x005586c1` and `0x005586e5` target `0x005587da` and `0x005587b8`; RGB565 setup at `0x005587e7-0x0055883c` jumps backward into shared stores. Decision: late compiler layout, not extra functions or padding.
- ABI heuristic: no incoming stack argument is read, `ecx` is not an incoming receiver, the epilogue uses plain `retn`, and EBX/ESI/EDI are preserved. Decision: `void` no-argument free-function source contract; `void __cdecl(void)` is the IDA type direction.
- Linkage heuristic: a complete out-of-line copy survives even though the only source use was inlined into UID00039W. External linkage is more likely than a removable all-inlined `static` helper. Decision: formal C++ omits `static`; this remains inferred, not original-symbol proof.
- Local-type heuristic: stack local `[ebp-0x70]` begins with decimal `108` / `0x6c`; reads at local offsets `+0x54` and `+0x5c` are RGB bit count and green mask. Decision: unseeded `DDSURFACEDESC displayMode`, with only `dwSize` initialized before `IDirectDraw::GetDisplayMode`.
- HRESULT heuristic: assembly uses `test eax,eax` and treats every nonzero value as fallback. Decision: compare exactly with `DD_OK`, not `SUCCEEDED`, `FAILED`, or a signed-negative test.
- Flag heuristic: D4 is true only for 32-bit presentation; D5 is true for 32-bit or 16-bit green mask `0x07e0`. A successful 24-bit mode clears both; 16-bit clears D4 and sets D5 from the mask equality. Query failure or an unsupported bit count preserves both prior globals and selects from the prior D5 state.
- Callback-global heuristic: all 12 slots are fixed absolute variables; no base/index use exists. Decision: use descriptive typed globals `g_pfnDrawPixel`, `g_pfnDrawLineDelta`, `g_pfnBlitSprite`, `g_pfnFillRle`, `g_pfnBlitScaledRleTint`, `g_pfnBlitAlphaLookup`, `g_pfnBlitBitmask`, `g_pfnFillRect`, `g_pfnExpandPixel`, `g_pfnPackPixel`, `g_pfnTransformPaletteColor`, and `g_pfnTransferPixels`. Keep `SurfaceRenderCallbackTable` as the documentation grouping, not a required pointer-object source shape.
- Callback function-name heuristic: use current source-quality child names for target identities, including accepted `SoftwareRenderCompatPixelCallback`, `BlitRgb565BitmaskCallback`, `FillRgb565RectCallback`, `ExpandRgb555Pixel`, `PackRgb555Pixel`, `TransformRgb555PaletteColor`, and their current descriptive sibling names. Do not invent callback bodies here.
- Source-order heuristic: all callback target implementations precede this body by address and the inline source call appears inside the following initializer. Decision: emit this helper after callback definitions and before the source-level UID00039W callsite. Keep position blank because current unpositioned Surface children preserve scan/source order and a new numeric position would sort ahead of them.
- Rejected alternative: merge UID00039V into UID00039W. The independent prologue, cookie, epilogue, padding boundaries, and retained out-of-line copy prove a separate source function.
- Rejected alternative: make UID00039V a ScreenPane method. It has no receiver and touches no ScreenPane field.
- Rejected alternative: make DirectX the owner. `g_pDirectX->m_pDirectDraw` is a service dependency; DirectX does not own flags, callback globals, or callback implementations.
- Rejected alternative: leave C++ blank due zero callers. The exact inlined copy resolves liveness and source shape.
- Rejected alternative: preserve `sub_`, `unk_`, raw address, raw slot-number, `g_pfnLockSurface`, or caller-specific `RefreshPaneRegion` names. Those are binary labels or consumer-biased aliases, not coherent source identities.

## Evidence Standards Used
- Evidence types: MCP health and binary survey, bounded bytes, full scoped instruction query, lookup, xrefs, target-address byte searches, callback target profiles, decompilation of UID00039W and representative consumers, neighboring ranges, current by-* docs, generated output, tracker state, and matching old reports.
- Evidence ladder: current bytes/control flow and current xrefs are primary; current decompilation and installed-target pair comparison are secondary; by-* docs and reports are corroboration; names and linkage are explicit inference.
- The evidence is strong enough for a formal body because every source-visible branch, global write, target identity, ABI property, local type, and boundary is directly recoverable, and the source-level call is proved by a complete adjacent inline duplicate.
- Confidence is below final-symbol certainty because stripped symbols do not prove original function/global/typedef spellings, and IDA has not been mutated to define the raw function.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed: fresh initialize/tools list; `idb_list`; `server_health`; bounded `lookup_funcs`; bounded `get_bytes`; `survey_binary(minimal)`; complete scoped `insn_query` over `[0x00558690,0x00558840)`; target/end `xref_query`; code/data-ref searches; VA/RVA byte searches; `decompile(0x00558840)`; profiles and xrefs for all 24 callback targets; D4/D5/slot/global xrefs; and current bytes for flags plus the 48-byte callback storage.
- by-* docs checked: exact target; UID00039U; UID00039W; UID0001G6; UID00029U; UID0000TN; UID0001PI; UID0002YK; UID0002PF; all compat/RGB565 callback children; Surface; DirectX; g_pDirectX; generated Surface.cpp; tracker.
- Old reports checked with exact path and finding are listed under Supporting Research. No dedicated prior UID00039V report was found.
- Negative checks performed: zero code/data xrefs to start/end; zero little-endian VA `90 86 55 00`; zero RVA `90 86 15 00`; zero pointers to end; no table-base indexing; no target strings; no `Surface.cpp`, `RenderCallback`, RGB555, or RGB565 source-name string; no parameters; no receiver; no exception throw/unwind body; no internal padding; no extra global writes.
- Failed or intentionally skipped checks: decompilation/basic-block APIs require an IDA function object, so raw-body semantics and 12-block CFG were reconstructed from the complete bounded instruction stream. No IDA define/rename/type write was performed. Validators were prohibited during the historical report-only pass; callback validators are recorded under Validator Results. No lifecycle command was run by B004.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact body is `[0x00558690,0x0055883d)`, 429 bytes, SHA256 `8BE000DDCECBB030F8889297E29A95E15BD3C05B43BF78C23FF0C3E4B01A61EC`. | high | MCP bytes and local hash over returned bytes | target Range/Evidence | incorporate | applied |
| C02 | `0x00558688-0x00558690` is eight `0xcc`; `0x0055883d-0x00558840` is three `0xcc`. | high | MCP bytes | target and aggregate padding | incorporate | applied |
| C03 | The range is one function with 96 real decoded instructions plus one alignment directive and 12 reconstructed basic blocks. | high | complete scoped instruction query and branch targets | target CFG | incorporate | applied |
| C04 | ABI is no-argument `void` free function, best IDA type `void __cdecl(void)`. | high | no arg reads, no receiver, plain `retn` | target signature/type | incorporate | applied |
| C05 | Local is an unseeded 108-byte `DDSURFACEDESC`; source initializes only `dwSize`. | high | stack offsets, literal 0x6c, DD structure fields | target behavior/C++ | incorporate | applied |
| C06 | Query is `g_pDirectX->m_pDirectDraw->GetDisplayMode(&displayMode)` through vtable slot `+0x30`. | high | raw instructions and DirectDraw layout | target behavior/C++; DirectX support | incorporate | applied |
| C07 | Query success means exact `DD_OK`/zero; every nonzero result uses fallback. | high | `test eax,eax; jnz` | target behavior/C++ | incorporate | applied |
| C08 | 32-bit mode sets both presentation and RGB565 flags true. | high | raw and inline clone writes | target/UID00029U/UID00039W | incorporate | applied |
| C09 | 24-bit mode clears both flags. | high | raw and inline clone writes | target/UID00029U/UID00039W | incorporate | applied |
| C10 | 16-bit mode clears D4 and sets D5 exactly when `dwGBitMask == 0x07e0`. | high | raw and inline clone compare | target/UID00029U/UID00039W | incorporate | applied |
| C11 | Failed query or unsupported bit count preserves prior flags and selects callbacks from prior D5. | high | branch to D5 test without stores | target behavior/C++ | incorporate | applied |
| C12 | Slot 0 is `g_pfnDrawPixel`, compat `0x004bb8d0`, RGB565 `0x004c0770`, receiver plus x/y/color, void. | high | profiles, UID0002PF, target xrefs | target/global/storage docs | incorporate | applied |
| C13 | Slot 1 is `g_pfnDrawLineDelta`, compat `0x004bb9b0`, RGB565 `0x004c0850`, receiver plus signed dx/dy. | high | retn 8, wrappers, pair profiles | target/global/storage docs | incorporate | applied |
| C14 | Slot 2 is `g_pfnBlitSprite`, compat `0x004bc090`, RGB565 `0x004c0f80`, receiver plus source context, source/destination rects, mode, palette, nullable options; int result direction. | high | installed pair and consumer ABI | target/global/storage docs | incorporate | applied |
| C15 | Slot 3 is `g_pfnFillRle`, compat `0x004bd420`, RGB565 `0x004c3190`, receiver plus source/rect/mode/palette shape. | high | UID00035C five-argument forwarder and pair profiles | target/global/storage docs | incorporate | applied |
| C16 | Slot 4 is `g_pfnBlitScaledRleTint`, compat `0x004bdcc0`, RGB565 `0x004c3a50`, receiver plus source/rect/mode/tint/scale shape. | medium-high | paired prototypes and body docs | target/global/storage docs | incorporate | applied |
| C17 | Slot 5 is `g_pfnBlitAlphaLookup`, compat `0x004bdf40`, RGB565 `0x004c3cf0`, receiver plus source descriptor and source/destination rects. | high | sole consumer at 0x0050a267 and paired profiles | target/global/storage docs | incorporate | applied |
| C18 | Slot 6 is `g_pfnBlitBitmask`, compat `0x004be0e0`, RGB565 `0x004c3ea0`, receiver plus packed bits, bounds, and mode; byte result. | high | source-ready UID0002TI and pair profile | target/global/storage docs | incorporate | applied |
| C19 | Slot 7 is `g_pfnFillRect`, compat `0x004be680`, RGB565 `0x004c4380`, receiver plus `RectBounds`, void. | high | UID0002YK, consumer ABI, pair profile | target/global/storage docs | incorporate | applied |
| C20 | Slot 8 is `g_pfnExpandPixel`, compat `0x004bed80`, RGB565 `0x004c46d0`, packed pixel plus three output bytes, void. | high | source-ready pair and consumer return-use check | target/global/storage docs | incorporate | applied |
| C21 | Slot 9 is `g_pfnPackPixel`, compat `0x004bedb0`, RGB565 `0x004c4700`, three byte lanes to unsigned short. | high | source-ready pair | target/global/storage docs | incorporate | applied |
| C22 | Slot 10 is `g_pfnTransformPaletteColor`, compat `0x004bede0`, RGB565 `0x004c4730`, unsigned short plus strength to unsigned short. | high | source-ready pair and PaletteLib consumers | target/global/storage docs | incorporate | applied |
| C23 | Slot 11 is `g_pfnTransferPixels`, compat `0x004bee40`, RGB565 `0x004c4790`, pixel buffer/count/mode block transform; caller ignores return. | high | source pair and 0x005571e6/0x005584a4 calls | target/global/storage docs | incorporate | applied |
| C24 | Every callback target has exactly two data refs: one raw UID00039V ref and one modeled UID00039W inline-copy ref. | high | current xrefs for all 24 targets | target liveness/callback inventory | incorporate | applied |
| C25 | `0x00558811` loads RGB565 `0x004c4380`; compat `0x004be680` is loaded at `0x00558723`; both reach shared store `0x00558770`. | high | live bounded disassembly and UID0002YK report | target and UID00039W correction | reject-stale | applied |
| C26 | Modeled peer directly stores `0x004c4380` to slot 7 at `0x00558ee2`. | high | UID00039W decompile/disassembly | target/UID00039W/global/storage | incorporate | applied |
| C27 | Complete semantic duplicate inside UID00039W proves an inlined source call and resolves zero-caller liveness. | high | exact branch/flag/24-target equivalence | target/UID00039W/Surface | incorporate | applied |
| C28 | No code/data xref or VA/RVA pointer targets raw start/end; this remains negative machine-route evidence, not dead-source evidence. | high | xrefs/find/find_bytes | target negative evidence | incorporate | applied |
| C29 | Best source name is `InitializeSurfaceRenderCallbacks`; the raw page received a UID-preserving rename. | medium-high | behavior, source family, source order | target path/title/C++ | incorporate | applied |
| C30 | Best linkage is external free function, not member and not `static`, because an out-of-line copy survives after the source call was inlined. | medium-high | ABI plus retained copy | target C++/source placement | incorporate | applied |
| C31 | Direct owner/emitter stays UID0000OC Surface; DirectX, ScreenPane, callback global, and aggregate are dependencies/contexts. | high | globals touched, no receiver, existing route | target metadata/ownership | already-present | already-present |
| C32 | Callback storage is best documented as 12 declaration-ordered typed globals, not a pointer-to-table object. | medium-high | fixed absolute refs, no base/index/pointer use | UID0000TN/UID0001PI | incorporate | applied |
| C33 | Keep blank emitter position; source order is after callback definitions and before UID00039W's inlined call. | high | executable order and generator position semantics | target metadata/Surface | already-present | already-present |
| C34 | Raise only target to `90/92`; retain reconstructable, owner/emitter, position, and Nested values. | high | blocker closure and residual symbol uncertainty | target metadata | incorporate | applied |
| C35 | Preserve callback child bodies/scores and compiler-cookie/history/negative evidence; support synchronization must not duplicate callback C++. | high | ownership and by-memory range rule | all destinations | already-present | already-present |
| C36 | Generated Surface.cpp contains one UID00039V helper definition and no target Empty Emitter Marker after the authorized waited refresh. | high | target formal block and generated command 9979 | generated read-only verification | incorporate | applied |

### Callback Claim-By-Claim Proof
- C01 applied: renamed UID00039V records exact `[0x00558690,0x0055883d)`, 429-byte size, and body SHA256; target validators `000000009949` and `000000009979` returned exit 0/`ok:1`.
- C02 applied: target and UID0001G6 retain eight predecessor and three successor `0xcc` bytes; validators `9949` and `9955` accepted both pages.
- C03 applied: target documents one function, 96 executable instructions, one alignment directive, twelve blocks, late branch targets, and the shared epilogue; command `9949` accepted the page.
- C04 applied: target status/ABI/formal block use a no-argument `void` free function; generated command `9979` emits exactly one `void InitializeSurfaceRenderCallbacks()` definition.
- C05 applied: target ABI and exact formal block use a 108-byte `DDSURFACEDESC` and initialize only `dwSize`; generated body lines 483-484 preserve that source shape.
- C06 applied: target and Surface support identify `g_pDirectX->m_pDirectDraw->GetDisplayMode` and DirectDraw slot `+0x30`; `DirectX.md` and `g_pDirectX.md` were intentionally unchanged because their dependency detail was already sufficient.
- C07 applied: target, formal block, and generated body compare the result exactly with `DD_OK`; no `SUCCEEDED`, `FAILED`, or descriptor seeding was introduced.
- C08 applied: target, UID00039W, and UID00029U document the 32-bit branch setting both globals true; commands `9949`, `9958`, and `9978` accepted those destinations.
- C09 applied: the same three destinations document the 24-bit branch clearing both globals; generated body lines 493-496 reproduce it.
- C10 applied: the same three destinations document the 16-bit branch clearing D4 and setting D5 exactly from `dwGBitMask == 0x07e0`; generated body lines 498-502 reproduce it.
- C11 applied: target, UID00039W, and UID00029U record that query failure/unsupported depth preserves both prior flags and selects callbacks from prior D5; no default assignment or clamp appears in generated output.
- C12 applied: target, UID0000TN, and UID0001PI identify slot 0 `g_pfnDrawPixel`, both target addresses, and its receiver/x/y/color void direction; commands `9949`, `9962`, and `9964` accepted the synchronized detail.
- C13 applied: those destinations identify slot 1 `g_pfnDrawLineDelta`, both targets, signed deltas, and physical `retn 8` evidence.
- C14 applied: those destinations identify slot 2 `g_pfnBlitSprite`, both targets, receiver/source/rectangle/mode/palette/options shape, and int result direction.
- C15 applied: those destinations identify slot 3 `g_pfnFillRle`, both targets, and source/rectangle/mode/palette shape while preserving UID00035C evidence.
- C16 applied: those destinations identify slot 4 `g_pfnBlitScaledRleTint`, both targets, and source/rectangle/mode/tint/scale direction with the medium-high spelling cap intact.
- C17 applied: those destinations identify slot 5 `g_pfnBlitAlphaLookup`, both targets, source descriptor, and source/destination rectangles.
- C18 applied: those destinations identify slot 6 `g_pfnBlitBitmask`, both targets, packed bits/bounds/mode direction, and byte result while retaining UID0002TI support.
- C19 applied: those destinations identify slot 7 `g_pfnFillRect`, compat `0x004be680`, RGB565 `0x004c4380`, and `RectBounds`/void direction without changing UID0002YK.
- C20 applied: those destinations identify slot 8 `g_pfnExpandPixel`, both targets, packed input, three byte outputs, and void direction.
- C21 applied: those destinations identify slot 9 `g_pfnPackPixel`, both targets, three byte channels, and unsigned-short result.
- C22 applied: those destinations identify slot 10 `g_pfnTransformPaletteColor`, both targets, packed input/strength, and unsigned-short result.
- C23 applied: those destinations identify slot 11 `g_pfnTransferPixels`, both targets, mutable pixel buffer/count/mode direction, and ignored physical return.
- C24 applied: target, UID00039W, UID0000TN, and UID0001PI retain the exact raw-plus-inline two-ref setup for all 24 targets; no callback child page was edited.
- C25 applied: all edited route-bearing pages now state raw `0x00558811` is RGB565 `0x004c4380`, compat `0x004be680` is at `0x00558723`, and shared store is `0x00558770`; stale wording survives only when explicitly labeled historical/superseded.
- C26 applied: target, UID00039W, UID0000TN, UID0001PI, Surface, and UID0001G6 record inline `0x00558ee2` storing RGB565 `0x004c4380` to slot 7.
- C27 applied: target, UID00039W, Surface, and UID0001G6 record the complete semantic inline copy as source-call liveness while keeping UID00039W `88/90` and non-emitting.
- C28 applied: target and support retain zero start/end xrefs, zero VA/RVA pointer matches, and no registration/export/vtable route as negative machine-route evidence rather than dead-source proof.
- C29 applied: validator-preserving command `9949` moved the old path once, updated UID00039V to the new path, and propagated known reverse links; the old path is absent and one by-* UID00039V header remains.
- C30 applied: target/formal C++ use an externally linked free function with no receiver or `static`; the spelling/linkage confidence cap remains explicit.
- C31 already-present: UID0000OC remained canonical owner/emitter throughout; DirectX, ScreenPane, UID0000TN, and UID0001G6 remain dependency/context roles.
- C32 applied: UID0000TN and UID0001PI now document twelve declaration-ordered fixed typed globals, no runtime table pointer/base/index, and both assignment copies; final validators were `9962` and `9964`.
- C33 already-present: blank emitter position was retained, Surface documents source order, and generated command `9979` places UID00039V after callback definitions and before the next emitted Surface helper without numeric reordering.
- C34 applied: UID00039V alone changed `85/88 -> 90/92`; UID, owner/emitter, reconstructable state, blank position, exact range, and `Nested:0` are unchanged.
- C35 already-present: no callback child, UID0002YK, UID0002PF, DirectX, or g_pDirectX page was edited; target retains cookie/cold-layout/history/negative evidence and emitted code contains no duplicated callback implementation body.
- C36 applied: waited command `000000009979` refreshed `Surface.cpp`; read-only inspection found one UID00039V marker, one target definition, zero UID00039V Empty Emitter Markers, zero old identities, 24 assignments, and zero `sub_`, raw-address, or cookie artifacts in the body.

## Positive Evidence Summary
- Direct facts: exact prologue/frame/cookie, exact 429-byte body, exact padding, no arguments/receiver, one DirectDraw query, exact D4/D5 branches, all 12 slot writes, all 24 target identities, and exact epilogue.
- Corroboration: each callback target has precisely the raw and modeled setup refs; current flag/table docs agree on storage and consumers; UID0002YK independently proves the corrected slot-7 route.
- Strongest inference chain: standalone full function plus a complete semantic duplicate in the immediately following live startup initializer is the expected binary signature of a source helper whose call was inlined while an out-of-line definition was retained. This is sufficient to reject the old blank-C++/no-caller conclusion.

## IDA MCP Facts
- Function/range facts: IDA does not define a function at `0x00558690`; complete scoped decode returns 97 heads including final align, with 96 executable instructions. Body SHA256 is `8BE000DDCECBB030F8889297E29A95E15BD3C05B43BF78C23FF0C3E4B01A61EC`.
- CFG facts: 12 logical blocks: entry/query `0x00558690-0x005586c7`; 32-bit test `0x005586c7-0x005586cf`; 32-bit writes `0x005586cf-0x005586e2`; 24-bit test `0x005586e2-0x005586eb`; 24-bit clears `0x005586eb-0x005586f9`; compat target loads `0x005586f9-0x0055874a`; shared stores/epilogue `0x0055874a-0x005587b8`; 16-bit test `0x005587b8-0x005587bd`; green-mask test/D4 clear `0x005587bd-0x005587d1`; D5 true branch `0x005587d1-0x005587da`; prior-D5 fallback `0x005587da-0x005587e7`; RGB565 target loads/back-jump `0x005587e7-0x0055883d`.
- Data/table/padding facts: D4/D5 and all 48 callback-storage bytes read zero in the image at evidence time. Raw body writes no global except D4, D5, and the 12 callback pointers; it reads the security cookie and g_pDirectX.
- Xref facts: start and end each have zero xrefs; little-endian VA/RVA patterns have zero matches; all 24 callback targets have exactly two setup refs; D4 has seven refs, D5 sixteen, slot 7 has 206, and slot 11 has five.
- Vtable/global/type facts: `g_pDirectX` has 19 refs including raw `0x005586a3`; `[g_pDirectX+4]` supplies `LPDIRECTDRAW`; vtable `+0x30` is `GetDisplayMode`; local size/field offsets match `DDSURFACEDESC` and `DDPIXELFORMAT`.
- Negative IDA facts: no target string or original symbol; no function object; no direct caller; no pointer registration; no vtable entry; no table-base indexing; no EH throw/catch; no source-visible cookie operation.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00558680-0x00558688` | UID00039U | ScreenPane flag setter | true | ScreenPane class | `86/88` | separate predecessor |
| `0x00558688-0x00558690` | ignored padding | eight `0xcc` bytes | false | physical range | n/a | preserve |
| `0x00558690-0x0055883d` | UID00039V target | free Surface callback initializer | true | UID0000OC | current `90/92` | UID-preserving rename and exact body applied |
| `0x0055883d-0x00558840` | ignored padding | three `0xcc` bytes | false | physical range | n/a | preserve |
| `0x00558840-0x00558f63` | UID00039W | mixed ScreenPane-receiver/Surface-global startup initializer | true/non-emitting | UID0000OC research bucket | `88/90` | contains inlined UID00039V source call |
| `0x0069b3d4-0x0069b3d8` | UID00029U | two bool globals plus alignment | true | UID0000OC | `88/93` | names/definitions already source-ready |
| `0x0069b3e0-0x0069b410` | UID0001PI | 12 callback-pointer globals | true | UID0000TN | `89/88` | support synchronization only |
| `0x004bb8d0-0x004c069e` | UID00016J plus exact children | compat/RGB555 callback family | mixed child readiness | UID0000OC children | unchanged | no body duplication |
| `0x004c0770-0x004c5fde` | UID00016L plus exact children | RGB565 callback family | mixed child readiness | UID0000OC children | unchanged | no body duplication |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00558690` | zero inbound code/data refs | retained out-of-line helper copy |
| `0x005586bc` | indirect call through DirectDraw vtable `+0x30` | `GetDisplayMode` query |
| `0x005586cf/0x005586eb/0x005587c4` | writes D4 | 32/24/16 presentation flag branches |
| `0x005586d6/0x005586f2/0x005587d1/0x005587da` | writes/tests D5 | RGB565-family selection and fallback |
| `0x005586f9-0x00558745` | 12 compat target refs | complete compat family load set |
| `0x0055874a-0x005587a9` | 12 callback-global stores | shared compiler-scheduled store block |
| `0x005587e7-0x00558833` | 12 RGB565 target refs | complete RGB565 family load set |
| `0x00558838` | internal backward jump to `0x0055874a` | RGB565 family shares stores/epilogue |
| `0x00558b2f-0x00558f0f` within UID00039W | semantic inline duplicate | source-level helper call was inlined |
| `0x00558811` | data ref to `0x004c4380` | corrected RGB565 slot-7 load |
| `0x00558723` | data ref to `0x004be680` | actual compat slot-7 load |
| `0x00558770` | store to `0x0069b3fc` | raw shared slot-7 assignment |
| `0x00558ee2` | direct modeled store of `0x004c4380` | inline RGB565 slot-7 assignment |
| `0x005587af` | security-cookie check | compiler scaffolding only |

Complete callback-pair and initializer-reference inventory:

| Slot / storage / source global | Highest-probability source interface | Compat target / raw ref / inline ref | RGB565 target / raw ref / inline ref |
| --- | --- | --- | --- |
| 0 / `0x0069b3e0` / `g_pfnDrawPixel` | `void`; `GrafPort` receiver in ECX plus `int x`, `int y`, `unsigned int colorIndex` | `SoftwareRenderCompatPixelCallback` `0x004bb8d0` / `0x00558745` / `0x00558b80` | `SoftwareRenderRgb565PixelCallback` `0x004c0770` / `0x00558833` / `0x00558e9c` |
| 1 / `0x0069b3e4` / `g_pfnDrawLineDelta` | `void`; `GrafPort` receiver in ECX plus signed `int deltaX`, `int deltaY`; physical callee cleanup is `retn 8` | `SoftwareRenderCompatLineCallback` `0x004bb9b0` / `0x00558734` / `0x00558b8a` | `SoftwareRenderRgb565LineCallback` `0x004c0850` / `0x00558822` / `0x00558ea6` |
| 2 / `0x0069b3e8` / `g_pfnBlitSprite` | `int`; `GrafPort` receiver plus source context, source and destination rectangles, mode byte, palette-or-null, and nullable `SurfaceSpriteBlitOptions *` | `SoftwareRenderCompatSpriteBlitCallback` `0x004bc090` / `0x00558740` / `0x00558b94` | `SoftwareRenderRgb565SpriteBlitCallback` `0x004c0f80` / `0x0055882e` / `0x00558eb0` |
| 3 / `0x0069b3ec` / `g_pfnFillRle` | byte result direction; `GrafPort` receiver plus RLE source record, source/destination rectangle inputs, mode byte, and resolved palette/destination-span input; register-shaped `__userpurge` is rejected as source syntax | `SoftwareRenderCompatRleFillCallback` `0x004bd420` / `0x00558728` / `0x00558b9e` | `SoftwareRenderRgb565RleFillCallback` `0x004c3190` / `0x00558816` / `0x00558eba` |
| 4 / `0x0069b3f0` / `g_pfnBlitScaledRleTint` | `void`; `GrafPort` receiver plus eight physical arguments covering RLE source, rectangle, mode, tint selector, and horizontal/vertical scale state | `SoftwareRenderCompatScaledRleTintCallback` `0x004bdcc0` / `0x0055873b` / `0x00558ba8` | `SoftwareRenderRgb565ScaledRleTintCallback` `0x004c3a50` / `0x00558829` / `0x00558ec4` |
| 5 / `0x0069b3f4` / `g_pfnBlitAlphaLookup` | byte-result physical direction; `GrafPort` receiver plus source descriptor and source/destination rectangle pointers; the sole direct consumer supplies exactly those four semantic operands | `SoftwareRenderCompatAlphaLookupBlitCallback` `0x004bdf40` / `0x005586fe` / `0x00558bb2` | `SoftwareRenderRgb565AlphaLookupBlitCallback` `0x004c3cf0` / `0x005587ec` / `0x00558ece` |
| 6 / `0x0069b3f8` / `g_pfnBlitBitmask` | `unsigned char`; `GrafPort` receiver, packed-mask bytes, `RectBounds`, and mode byte; physical peer is fastcall-shaped with one unused register lane | `SoftwareRenderCompatBitmaskBlitCallback` `0x004be0e0` / `0x0055872f` / `0x00558bbc` | `BlitRgb565BitmaskCallback` `0x004c3ea0` / `0x0055881d` / `0x00558ed8` |
| 7 / `0x0069b3fc` / `g_pfnFillRect` | `void`; `GrafPort` receiver and `const RectBounds *`; RGB565 physical peer is fastcall-shaped with one unused register lane | `SoftwareRenderCompatFillCallback` `0x004be680` / `0x00558723` / `0x00558bc6` | `FillRgb565RectCallback` `0x004c4380` / `0x00558811` / `0x00558ee2` |
| 8 / `0x0069b400` / `g_pfnExpandPixel` | `void`; packed `unsigned short pixel` plus three `unsigned char *` channel outputs | `ExpandRgb555Pixel` `0x004bed80` / `0x00558710` / `0x00558bda` | `ExpandRgb565Pixel` `0x004c46d0` / `0x005587fe` / `0x00558ef6` |
| 9 / `0x0069b404` / `g_pfnPackPixel` | `unsigned short`; three `unsigned char` channel inputs | `PackRgb555Pixel` `0x004bedb0` / `0x00558705` / `0x00558be4` | `PackRgb565Pixel` `0x004c4700` / `0x005587f3` / `0x00558f00` |
| 10 / `0x0069b408` / `g_pfnTransformPaletteColor` | `unsigned short`; `unsigned short pixel`, `unsigned char strength` | `TransformRgb555PaletteColor` `0x004bede0` / `0x0055871e` / `0x00558bd0` | `TransformRgb565PaletteColor` `0x004c4730` / `0x0055880c` / `0x00558eec` |
| 11 / `0x0069b40c` / `g_pfnTransferPixels` | source-facing `void`; mutable pixel buffer, `unsigned int pixelCount`, and mode; decompiler pointer return is rejected because both direct consumers ignore EAX | `SoftwareRenderCompatBlockTransferCallback` `0x004bee40` / `0x005586f9` / `0x00558bee` | `SoftwareRenderRgb565BlockTransferCallback` `0x004c4790` / `0x005587e7` / `0x00558f0a` |

- Type-status boundary: the table records the complete physical ABI and highest-probability semantic interface needed to type each global and select the correct pair. Original public typedef spellings are not symbol-proven; unresolved spelling does not justify raw addresses or vague slot labels in the initializer and does not authorize changes to callback-child formal bodies in this assignment.

## Documentation Evidence And IDA Status
- Callback-readback docs: Surface owns the callback implementations and globals; UID00029U supplies source flag names and both writer copies; UID0001PI/UID0000TN supply exact storage, semantic fixed-global shape, and target pairing; UID0002YK/UID0002PF supply unchanged source-ready peer contracts; DirectX supplies `g_pDirectX->m_pDirectDraw`.
- Historical pre-callback gaps, now resolved: UID00039V had blank C++ and no inline-liveness proof; UID00039V/UID00039W called `0x00558811` compat; aggregate/Surface rows used the raw target name and `85/88`; global/storage pages did not distinguish fixed globals from a table object. The seven bounded callback destinations now resolve each gap while retaining the old conclusions only as labeled history.
- Generated state: waited command `000000009979` produced one UID00039V definition and no target Empty Emitter Marker. Generated output was inspected read-only and was never manually edited by B004.

## Ranked Ownership Analysis

### 1. Surface file UID0000OC
- Evidence for: all 12 globals are Surface render dispatch; all 24 targets are Surface-owned callback implementations; flags are Surface-owned; helper has no receiver and uses only DirectDraw service plus Surface globals; current emitter route already reaches `NexusTK/render/Surface.cpp`.
- Evidence against: physical adjacency is in a mixed Surface/ScreenPane presentation neighborhood, and the source call was inlined into a ScreenPane-receiver initializer.
- Decision: accepted direct owner/emitter. Semantic globals and callback implementations outweigh adjacency, and the free helper isolates the Surface work from UID00039W's receiver conflict.

### 2. SurfaceRenderCallbackTable UID0000TN
- Evidence for: the helper initializes every callback pointer and no unrelated state except the two format flags.
- Evidence against: UID0000TN is a global documentation grouping and routes to Surface; it is not a source file or executable function owner.
- Decision: support/data parent only, rejected as direct executable owner.

### 3. ScreenPane and DirectX
- Evidence for ScreenPane: source call is inlined inside UID00039W, whose caller passes `g_pScreenPane` and whose broader body mutates ScreenPane fields.
- Evidence against ScreenPane: UID00039V has no receiver, no ScreenPane fields, and only Surface globals.
- Evidence for DirectX: helper queries `LPDIRECTDRAW::GetDisplayMode`.
- Evidence against DirectX: it neither owns callback globals nor selected functions.
- Decision: ScreenPane is callsite context and DirectX is a dependency; both are rejected as direct owner/emitter.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new source file. Keep `NexusTK/render/Surface.cpp` and rename only the exact UID00039V page.
- Likely full contents: one `InitializeSurfaceRenderCallbacks` definition in existing Surface source order.
- Candidate related items that belong: UID00029U flags, UID0001PI/UID0000TN pointer globals, and callback child declarations remain dependencies/support, not children pasted into this body.
- Candidate related items rejected: UID00039W body, callback bodies, DirectX implementation, ScreenPane fields, and lookup-table allocation.
- Standalone/narrow/broad inference: narrow free helper in Surface.cpp.

## Source Placement
- Recommended placement: free function in `NexusTK/render/Surface.cpp`, after callback implementations/declarations and before the source-level call in UID00039W's initializer.
- Why it fits: direct callback/global ownership, executable/link order, existing emitter route, and no class receiver.
- Rejected placements: ScreenPane.cpp would mis-own globals; DirectX.cpp would mis-own render dispatch; a new RenderCallbacks.cpp lacks evidence; by-global/table output cannot own the executable function.
- Remaining uncertainty: original filename casing and exact symbol spelling are stripped; they cap confidence but do not change the source family or implementation.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: predecessor UID00039U ends at `0x00558688`; eight `0xcc` bytes lead to target start; target ends exactly before three `0xcc`; UID00039W begins at `0x00558840`.
- Children/subranges: create none. Do not split cold blocks after `0x005587b7`; they have inbound branches from the entry CFG.
- Padding/table/data/code distinctions: only `[0x00558690,0x0055883d)` is target code. D4/D5 and callback slots are external data dependencies with separate pages.
- Parent/container impact: UID0001G6 remains a non-emitting mixed container; update only its child row/name/score/evidence.

## Negative Evidence Summary
- Zero direct code/data xrefs, zero VA/RVA pointer literals, and no export/vtable/registration route were found for the standalone address.
- Those negatives reject direct machine invocation and function-pointer registration. They do not reject source liveness because the complete body appears inline in UID00039W.
- No code takes or indexes a callback-table base, so a runtime pointer-to-struct table is rejected as the best source model.
- No ScreenPane field is touched, so the inlining host does not become owner.
- No exception construction or unwind path exists; only compiler security-cookie scaffolding is present.
- No source-name strings/PDB evidence survive; descriptive names are inference, not original-proof.

## IDA Rename / Type / Comment Recommendations
- Proposed function definition/name: define one function at `0x00558690-0x0055883d`, name it `InitializeSurfaceRenderCallbacks`, and type it `void __cdecl(void)`.
- Proposed data names: retain accepted `g_surfaceUses32BitPresentation` and `g_surfaceUsesRgb565Pixels`; use the twelve `g_pfn*` semantic names listed in C12-C23 while keeping raw addresses in comments/evidence only.
- Proposed local/type comment: `DDSURFACEDESC displayMode; only dwSize is initialized before GetDisplayMode; nonzero HRESULT preserves prior flags`.
- Proposed chunk comments: `0x005587b8` and `0x005587e7` are late blocks of the same function; `0x00558838` joins shared stores; `0x0055883d` begins padding.
- Items intentionally unchanged: callback implementation names/bodies and existing D4/D5 source definitions; this pass should not overwrite stronger accepted child work.
- IDA DB edits: safe as recommendations after approval, but not requested or performed during research or callback.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. Owner/emitter is confirmed, current score is above 85, boundaries and behavior are exact, and liveness is resolved by the inline duplicate.
- Applied code: exact formal insertion text present in renamed UID00039V and generated output follows.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InitializeSurfaceRenderCallbacks()
{
    DDSURFACEDESC displayMode;
    displayMode.dwSize = sizeof(displayMode);

    if (g_pDirectX->m_pDirectDraw->GetDisplayMode(&displayMode) == DD_OK) {
        switch (displayMode.ddpfPixelFormat.dwRGBBitCount) {
        case 32:
            g_surfaceUses32BitPresentation = true;
            g_surfaceUsesRgb565Pixels = true;
            break;

        case 24:
            g_surfaceUses32BitPresentation = false;
            g_surfaceUsesRgb565Pixels = false;
            break;

        case 16:
            g_surfaceUses32BitPresentation = false;
            g_surfaceUsesRgb565Pixels =
                displayMode.ddpfPixelFormat.dwGBitMask == 0x07e0;
            break;
        }
    }

    if (g_surfaceUsesRgb565Pixels) {
        g_pfnDrawPixel = SoftwareRenderRgb565PixelCallback;
        g_pfnDrawLineDelta = SoftwareRenderRgb565LineCallback;
        g_pfnBlitSprite = SoftwareRenderRgb565SpriteBlitCallback;
        g_pfnFillRle = SoftwareRenderRgb565RleFillCallback;
        g_pfnBlitScaledRleTint = SoftwareRenderRgb565ScaledRleTintCallback;
        g_pfnBlitAlphaLookup = SoftwareRenderRgb565AlphaLookupBlitCallback;
        g_pfnBlitBitmask = BlitRgb565BitmaskCallback;
        g_pfnFillRect = FillRgb565RectCallback;
        g_pfnExpandPixel = ExpandRgb565Pixel;
        g_pfnPackPixel = PackRgb565Pixel;
        g_pfnTransformPaletteColor = TransformRgb565PaletteColor;
        g_pfnTransferPixels = SoftwareRenderRgb565BlockTransferCallback;
    } else {
        g_pfnDrawPixel = SoftwareRenderCompatPixelCallback;
        g_pfnDrawLineDelta = SoftwareRenderCompatLineCallback;
        g_pfnBlitSprite = SoftwareRenderCompatSpriteBlitCallback;
        g_pfnFillRle = SoftwareRenderCompatRleFillCallback;
        g_pfnBlitScaledRleTint = SoftwareRenderCompatScaledRleTintCallback;
        g_pfnBlitAlphaLookup = SoftwareRenderCompatAlphaLookupBlitCallback;
        g_pfnBlitBitmask = SoftwareRenderCompatBitmaskBlitCallback;
        g_pfnFillRect = SoftwareRenderCompatFillCallback;
        g_pfnExpandPixel = ExpandRgb555Pixel;
        g_pfnPackPixel = PackRgb555Pixel;
        g_pfnTransformPaletteColor = TransformRgb555PaletteColor;
        g_pfnTransferPixels = SoftwareRenderCompatBlockTransferCallback;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation: the block leaves the descriptor unseeded except `dwSize`, uses exact zero-success semantics, preserves prior flags on failure/unsupported bit depth, applies exact 32/24/16 rules, and installs every target in semantic slot order.
- Period source shape: a DirectDraw SDK descriptor, bool globals, named function-pointer globals, explicit switch, and paired software-render families match late-1990s/mid-2000s Windows C++ better than raw slots, an address array, or decompiler temporaries.
- Inferred source names/types: `InitializeSurfaceRenderCallbacks`, `displayMode`, `DDSURFACEDESC`, `DDPIXELFORMAT` fields, accepted D4/D5 names, semantic `g_pfn*` globals, and current callback-child names.
- Coding convention: Win32/DirectDraw uppercase SDK types and `g_p*`/`g_pfn*` project globals are already used by current DirectX, Surface, Palette, and callback docs.
- Compiler-only operations intentionally absent: cookie load/check, saved registers, pointer temporaries, shared-store scheduling, backward join, and cold-block ordering.

## Final Recommendation
- Retain the completed UID00039V path/title `InitializeSurfaceRenderCallbacks`, exact body, and `90/92` score.
- Retain preserved owner/emitter UID0000OC, reconstructable true, blank position, exact range, and Nested 0.
- Retain UID0001G6 non-emitting, UID00039W non-emitting, callback bodies in their exact children, and UID0000TN/UID0001PI as support/data documentation.
- No exact child, split, new source file, or manual coverage row is required.
- Outside this assignment: original symbol/typedef spellings could only be improved by authentic source/PDB evidence; their absence does not block this descriptive source reconstruction.

## Recommended Target Doc Changes
- Applied path: UID-preserving rename from historical `by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md` to current `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md` through validator-preserving command `000000009949`.
- Applied exact facts: body/hash/padding, 12-block CFG, no-arg void ABI, unseeded descriptor, exact DD_OK query, complete flag behavior, 12 globals/24 targets, raw/inlined duplicate relationship, pointer/xref negatives, compiler artifacts, and ranked ownership.
- Applied metadata: `85/88 -> 90/92`; owner/emitter/reconstructable/position/Nested retained; exact managed C++ inserted.
- Applied Item Summary: Surface-source free helper that queries current DirectDraw mode, preserves prior mode on fallback, selects the complete compat/RGB565 callback family, and is source-live through an inlined copy in startup presentation setup without repeating metadata.
- Preserved historical/stale material explicitly as historical: prior blank-C++/no-caller conclusion, raw IDA names, and wrong compat interpretation of `0x00558811`.

## Recommended Support Doc Changes
- `by-file/Surface.md`: applied UID00039V row/link/name/score, exact free-function role, inline-call liveness, source order, DirectX dependency, complete callback assignment, and no-body-duplication evidence; Surface score stayed unchanged.
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: applied only UID00039V child/link/name/score/evidence detail; parent remains `RECONSTRUCTABLE:FALSE`, mixed-owner, non-emitting, with unchanged aggregate score and unrelated children.
- `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`: corrected `0x00558811` to RGB565 `0x004c4380`, identified compat `0x004be680` at `0x00558723`, recorded the full inline UID00039V source call and placement, and retained UID00039W `88/90`, blank emitter/C++, receiver caveat, and unrelated behavior.
- `by-global/SurfaceRenderCallbackTable.md`: applied UID00039V standalone/inlined initialization, 12 semantic `g_pfn*` identities and ABI directions, and the declaration-ordered fixed-global source shape; score, owner, emitter, and blank formal block remain unchanged.
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: applied raw/inline routes, semantic names/type directions, current zero image bytes, historical all-FF context, and fixed-global conclusion; score/metadata/formal disposition remain unchanged and no definition/body was duplicated.
- `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md`: applied raw UID00039V writer peer, separate inline refs, and preserved-value failure behavior while retaining declarations, `88/93`, position 9, padding, names, and consumers.
- `by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`: no body/score change. Confirm its existing `0x00558811` and `0x00558ee2` setup facts remain authoritative.
- `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md` and other exact callback children: no score/body changes. Their target refs and semantic pair names are support evidence only.
- `by-file/DirectX.md` and `by-global/g_pDirectX.md`: no edit required; current `LPDIRECTDRAW m_pDirectDraw` and dependency boundary already provide equal-or-greater detail.

## Score And Metadata Recommendation
- Historical pre-callback state: `85/88`, owner/emitter UID0000OC, reconstructable true, blank position/formal C++, Nested 0.
- Current callback state: `90/92`, same owner/emitter/reconstructable/position/Nested, formal C++ populated, UID-preserving descriptive rename complete.
- Completion rationale: exact body, all branches, all targets, types, source names, owner, source placement, and implementation-ready C++ are resolved. It is not above 90 because source header declarations and original names are not recovered.
- Confidence rationale: current MCP directly proves all binary semantics and inlining. It is not above 92 because linkage/name/typedef spellings are inferred and IDA lacks an original symbol.
- Score-improvement attempts: function modeling replaced by full linear decode; caller blocker resolved through inline duplicate; pointer route exhausted with xrefs and VA/RVA searches; local type resolved from SDK layout; every target profiled and paired; stale route corrected; table-object ambiguity resolved from access shape; source route ranked against Surface/ScreenPane/DirectX/global alternatives.
- Metadata result: completion/confidence and formal C++ changed; path/title renamed; UID, owner, emitter, reconstructable, position, and Nested stayed unchanged.

## Open Questions With Attempted Resolution
- Original function spelling: no PDB/source/string survived. Full behavior and local conventions support `InitializeSurfaceRenderCallbacks`; this descriptive name is safe and only caps confidence.
- Static versus external linkage: no inbound refs initially suggested static/dead code, but the inlined duplicate plus retained standalone copy makes external linkage more probable. Formal C++ therefore omits `static`; authentic symbols would be needed to prove spelling/linkage beyond this inference.
- Struct table versus independent globals: no base/index/pointer use was found across initializers or consumers. Fixed independent typed globals are the best source model; the documentation title can remain an aggregate label.
- Exact public typedef spellings: installed pairs and callers resolve ABI/semantic types for all slots, but not original typedef names. Descriptive `Surface*Proc` type directions and `g_pfn*` globals are sufficient for initializer C++; no callback body depends on inventing public typedef syntax here.
- UID00039W ownership conflict: the helper itself has no receiver and is Surface-owned; the following mixed initializer contains only an inlined call. This resolves target ownership without forcing a broad UID00039W reroute.
- Material unresolved issue: none blocks target owner, emitter, range, score, or formal C++. Only authentic original spelling remains unavailable.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. No manual `-coverage-report.md` or supervisor tracker edit is recommended.
- The validator-owned research tracker must not be edited by B004. The target Item Summary and `Nested:0` are the source fields from which generated coverage should refresh after any authorized callback.

## Follow-Up Actions
- Supervisor-owned report validation, execution, count, path, move, and archive state are external and neither asserted nor directed by this artifact.
- The bounded implementation callback and all in-scope target/support work are complete; no implementation item remains.
- A-agent actions: none.
- B004 future research actions: none for this target unless the same artifact is returned with an exact defect.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for `90/92` under current evidence.
- Remaining uncertainty: descriptive original spellings, public typedef names, and linkage are inferred; bytes, behavior, route, and ownership are not uncertain.

## Validator Results
- `000000009949`, `2026-07-13T13:15:42-04:00`: default file scan of renamed UID00039V; exit 0, `ok:1`. It preserved UID00039V, recorded the old-to-new path update, changed registry state from blank to a populated block/hash, propagated three known Surface reverse links, reported 21 known missing-reference warnings, updated projected stats, and deferred generated refresh.
- `000000009952`, `2026-07-13T13:16:33-04:00`: scoped `by-file/Surface.md`; exit 0, `ok:1`. It reported 21 known missing-reference warnings, projected/stat side effects, and deferred generated refresh.
- `000000009955`, `2026-07-13T13:17:08-04:00`: scoped UID0001G6 aggregate; exit 0, `ok:1`. It reported 37 known missing-reference warnings, normalized one stale old target link, added reference-index entries, updated projected stats, and deferred generated refresh.
- `000000009958`, `2026-07-13T13:17:55-04:00`: scoped UID00039W; exit 0, `ok:1`. It reported five known UID00039Z missing-reference warnings, added the UID00039V reference index, updated projected stats, and deferred generated refresh.
- `000000009961`, `2026-07-13T13:19:24-04:00`: initial scoped UID0000TN pass; exit 0, `ok:1`. It reported seven known missing-reference warnings and exposed that an initial edit had compressed an existing UID0002TI support reference. B004 restored that pre-existing detail before lease release; this pass is superseded by `9962`.
- `000000009962`, `2026-07-13T13:20:19-04:00`: final scoped UID0000TN pass; exit 0, `ok:1`. It retained seven known missing-reference warnings, restored UID0002TI to the reference index, updated projected stats, deferred generated refresh, and is the authoritative validator for that destination.
- `000000009964`, `2026-07-13T13:22:07-04:00`: scoped UID0001PI storage; exit 0, `ok:1`. It reported eight known missing-reference warnings, added UID00039V to the reference index, updated projected stats, and deferred generated refresh.
- `000000009978`, `2026-07-13T13:25:00-04:00`: scoped UID00029U flags; exit 0, `ok:1`. It reported two pre-existing missing UID0003ZP references, added UID00039V/UID00039W/UID0003A4 reference entries, updated projected stats, and deferred generated refresh.
- `000000009979`, `2026-07-13T13:25:20-04:00`: final target scan with `--wait-generated`; exit 0, `ok:1`, `generated_refresh: completed`, generated timestamp `2026-07-13T13:25:20-04:00`. Validator-owned side effects were a 4,669-node/3,803-edge registry rebuild, 281 generated metadata refreshes, projected stats, and pre-existing global marker/no-code diagnostics; B004 did not edit those files manually.
- Lease proof: the old UID00039V path, Surface, UID0001G6, UID00039W, UID0000TN, UID0001PI, and UID00029U were each leased alone immediately before their bounded edit and reread after acquisition. Release after each page's final scoped validator returned `Success`; UID0000TN remained leased through its corrective second pass `9962` and was then released. Final `current_leases.md` readback contains no Agent-B004 entry.
- Exact formal-block proof: report and renamed target managed blocks compare byte-for-byte equal after readback and each hashes to `942E8176F211D64A3DA54C1E9C22CA3E19E78C866D63E5D0E2839C3D8C84215D` over the extracted text.
- Read-only generated proof: `auto-generated/NexusTK/render/Surface.cpp` header records command `9979`; it contains one UID00039V marker, one `void InitializeSurfaceRenderCallbacks()` definition, one exact `GetDisplayMode(&displayMode) == DD_OK` query, 24 `g_pfn*` assignments, zero target Empty Emitter Markers, zero `SurfaceRenderCallbackInitializerRaw` identities, and zero `sub_`, raw address, or cookie tokens in the emitted body. Across the 24 callback identities, nine existing source-ready bodies are each defined once and fifteen remain empty under their own unchanged dispositions; no callback definition count exceeds one. UID00039V remains between its pre-existing emitted siblings.
- Unresolved validator errors: none. Reported missing references and global generation diagnostics are pre-existing/known project-wide conditions, not callback failures.

## Changed Files
- Renamed once, UID preserved: `by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md` -> `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md`. The old path is absent; the new path exists; exactly one ordinary by-* UID00039V header remains.
- Modified and scoped-validated: `by-file/Surface.md`.
- Modified and scoped-validated: `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`.
- Modified and scoped-validated: `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`.
- Modified and scoped-validated: `by-global/SurfaceRenderCallbackTable.md`.
- Modified and scoped-validated: `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`.
- Modified and scoped-validated: `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md`.
- Modified callback artifact: `tools/leaser/Agents/Agent-B004/research/00039V-SurfaceRenderCallbackInitializerRaw-source-quality.md`.
- Validator-owned side effects only: generated metadata/C++, projected stats, reference index, and registry refreshes listed above. B004 did not manually edit generated, tracker, coverage, supervisor, validator-state, or lifecycle files.
- Explicitly unchanged: UID0002YK, UID0002PF, all callback children, `by-file/DirectX.md`, and `by-global/g_pDirectX.md`; no unrelated callback score/body/formal block was changed.
- Report lifecycle boundary: B004 ran no report execute, move, archive, invalidation, revalidation-lifecycle, or other lifecycle command. External lifecycle state is not tracked as pending implementation work in this artifact.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Historical Gate 1 validation passed exact pre-callback SHA `0ED6DCFB92A4F7EBA9FDA56BEBD10D1972E5FFC582721D678EDF8DED633D121D` before implementation authorization.
- [x] UID-preserving rename target to `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md` used the documented validator-preserving mechanism.
- [x] Applied target `85/88 -> 90/92`; retained UID0000OC owner/emitter, reconstructable true, blank position, exact range, and Nested 0.
- [x] Inserted the exact managed `InitializeSurfaceRenderCallbacks` formal block without body-only variation.
- [x] Incorporated C01-C36 claim by claim at report-level detail and set each ledger verification state to `applied` or `already-present`.
- [x] Added exact body/hash/padding/CFG/ABI/local/DirectDraw/flag/fallback/compiler-artifact evidence to the target.
- [x] Added all 12 semantic callback globals, 24 target identities, slot ABI directions, assignment routes, and initialization order without copying callback bodies.
- [x] Corrected stale `0x00558811` compat wording in the target and UID00039W; preserved `0x00558723` compat and `0x00558ee2` modeled RGB565 facts.
- [x] Added inline-copy source-liveness proof and retained zero-xref/VA/RVA evidence as negative machine-route evidence.
- [x] Updated `by-file/Surface.md` with renamed link, score, free-helper role, source order, and dependencies; kept its score and unrelated content unchanged.
- [x] Updated UID0001G6 aggregate UID00039V child/detail only; preserved parent false/non-emitting/mixed status and unrelated children.
- [x] Updated UID00039W support only; preserved `88/90`, blank emitter/C++, receiver conflict, and unrelated setup behavior.
- [x] Updated UID0000TN and UID0001PI with fixed-global names/type directions and both initialization copies; preserved scores/metadata/formal blocks.
- [x] Updated UID00029U with raw writer peer and failure behavior; preserved definitions, score, position, padding, and consumers.
- [x] Confirmed UID0002YK, UID0002PF, and every callback child score/body remain unchanged and are not duplicated.
- [x] Preserved historical no-caller/no-code text only as superseded history, rejected owner/table/caller-specific alternatives, and compiler cookie/cold-block disposition.
- [x] Confirmed no split/new child/new source file/manual coverage/tracker change is required.
- [x] Confirmed third-party import directive is not applicable.
- [x] Confirmed Wave2/Wave3 artifacts were ignored and not incorporated.
- [x] Ran one scoped file validator per changed ordinary by-* destination after short per-file leases; released each lease immediately.
- [x] Ran final waited refresh `9979`; verified one UID00039V helper, no target Empty Emitter Marker, no duplicated callback body, no raw address/`sub_`/cookie source, and preserved sibling order.
- [x] Recorded exact validator IDs, timestamps, exits/ok, side effects, changed files, lease releases, and generated proof in this same report.

Implementation callback pass:
- [x] Report was accepted by the supervisor for implementation at the exact historical Gate 1 SHA above.
- [x] All accepted target/support details were incorporated without compression.
- [x] Claim ledger C01-C36 uses legal callback verification states with separate claim-by-claim proof.
- [x] Rename/metadata/owner/emitter/range/Nested/formal C++ changes were applied exactly; no accepted item was blocked or excluded.
- [x] Historical/stale assumptions, rejected alternatives, compiler artifacts, and negative evidence were preserved.
- [x] Open questions remain only as evidence-backed spelling/linkage/typedef confidence caps.
- [x] Scoped validators ran and exact results are recorded.
- [x] Waited generated refresh completed and exact `Surface.cpp` checks are recorded.
- [x] No B004 lease remains and no implementation item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000010007","destination_path":"executed-b-agent-research/B004/00039V-SurfaceRenderCallbackInitializerRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00039V-SurfaceRenderCallbackInitializerRaw-source-quality.md","timestamp":"2026-07-13T13:42:53-04:00","uid":"00039V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
