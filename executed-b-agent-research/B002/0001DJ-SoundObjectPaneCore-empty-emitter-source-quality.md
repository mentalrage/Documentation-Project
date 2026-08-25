** TARGET-REPORT-UID:0001DJ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001DJ SoundObjectPaneCore Ownership / Split Research


## Finalized Report / Current Recommendation

- Current applied disposition: UID0001DJ is a `92/94` non-emitting semantic split index retaining `CANONICAL_OWNER:0000DH`. Its four exact source-bearing children are UID0004PV constructor, UID0004PW ordinary destructor, UID0004PX StartPlayback, and UID0004PY OnTimer at positions `20/30/40/50`.
- Final disposition: UID0000DH remains the direct class owner and UID0000NW remains the `NexusTK/map/SoundObjectPane.cpp` file owner. Exact children alone emit method bodies. The aggregate, scalar deleting wrapper, adjustors, switch table, alignment, and vtable ABI emit no duplicate handwritten source.
- ObjectPane integration disposition: UID00009R is a complete `92/94` declaration emitter at position `10`, with a source-safe `SoundObjectPane` forward declaration, exact `0xf8..0x127` layout, typed `SoundObjectPane *m_soundObjectPane` at `+0x120`, all established ObjectPane method declarations, concrete empty `RenderFrame`/`DrawSpriteFrame` defaults at primary slots `+0x5c/+0x64`, and compiler-only UID0002SK vtable coverage. UID0003XT/UID0003XU are the only handwritten definitions for the typed setter/clear operations.
- Callback result: Destinations 1-14 and 19 and the bounded prose/support synchronization in Destinations 15-18 are applied. The four SoundObjectPane children were registered serially with the exact ranges, positions, and bodies specified by the accepted report.
- Confidence: very strong for split, ownership, callback ABI, field layout, behavior, source placement, and compiler exclusions; strong but deliberately capped for stripped original enum/member spellings.
- B002 implementation, scoped validation, generated verification, and lease release are complete. Current or future report path/count, supervisor validation, execution, move, and archive state are external validator/supervisor-owned and are not asserted here.

## Supporting Research

- The assigned target is UID0001DJ, `by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md`; no duplicate report was created.
- Evidence collection used streamable MCP at `http://127.0.0.1:13337/mcp`. After a supervisor-declared listener outage, work paused without file edits or fallback evidence. On supervisor resume, a fresh HTTP MCP session `7166901a-977b-4042-abde-428ce7531d1b` was initialized, `idb_list` was the first IDB operation, and it returned the sole active NexusTK database `3fc1dcef` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Evidence-time `server_health` at 2026-07-14 reported status `ok`, NexusTK.exe image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and string cache ready with 2,067 entries. Fresh target lookup and bounded byte reads then succeeded. These are evidence-collection-time observations, not assertions about later MCP availability.
- Fresh post-interruption calls reproduced both target function records, target code bytes, all four decompilations, callers/xrefs/callees, basic blocks, per-subrange hashes, ObjectPane link evidence, vtable/adjustor/scalar evidence, pool bytes/xrefs, and random-threshold xrefs. No pre-interruption MCP-only claim is used without a post-resume corroborating call or current ordinary documentation.
- Gate-1 repair reanalysis used a second supervisor-restored database session `9df6e9a0` through fresh HTTP MCP client session `04f21da3-5d03-4a62-829b-a8d9929b6aac`. Fresh `idb_list` returned that sole active adopted NexusTK worker, evidence-time `server_health` was `ok` with analysis/Hex-Rays/strings ready, `lookup_funcs(0x005372d0)` returned the exact `0xc5` constructor, and bounded `get_bytes(0x005372d0,16)` returned `55 8b ec 6a ff 68 d8 51 60 00 64 a1 00 00 00 00`. The earlier `3fc1dcef` session and its facts remain historical evidence snapshots; no present availability is asserted.
- Callback recovery verification used fresh HTTP MCP client session `9273942e-984a-4dc0-a672-f4e8a4a5a22a`. Fresh `idb_list` returned sole evidence-time NexusTK database `6b2e78f3`; `server_health` was `ok` with analysis, Hex-Rays, and strings ready; and bounded `get_bytes(0x0053ca20,16)` returned `55 8b ec 51 56 ff 75 0c 8b f1 ff 75 08 89 75 fc`. This rechecked the callback target after the supervisor-declared `9df6e9a0` worker outage. No fallback evidence was substituted and no present MCP availability is asserted.
- The final bounded slot pass on that same evidence session read ObjectPane primary cells `0x00620298..0x00620300`, eleven derived ObjectPane-family primary slot triplets, the neighboring non-ObjectPane BowGauge table as an exclusion control, and the two MapPane render dispatch helpers. `lookup_funcs(0x005ca28c)` resolved real `__purecall`; `lookup_funcs`/decompile/disassembly resolved `0x0041b6c0` as one-instruction `nullsub_18` / `retn 8`; ObjectPane `+0x00` points to the former while `+0x5c/+0x64` point to the latter. `0x0050dcc0` calls `+0x5c` with `(GrafPort *, RectBounds *)`, and `0x0050dd60` calls `+0x64` with the same two explicit arguments after bounds/intersection work. This proves one pure destructor contract plus two concrete empty render defaults, not three pure methods.
- The fresh ObjectPane pass re-read UID00009R, UID0000M5, UID0001D5, UID0003XN-UID0003Y0, UID00020R/UID00020S, UID0002SK, derived vtable children UID00034X/UID00034Y/UID00034Z/UID000350/UID000351/UID000353/UID000354/UID000355/UID000358/UID000359/UID00035A, neighboring exclusion control UID000352, Pane UID0000A2, PaneLayout UID0001VH, PaneVtables UID0003JA, RectBoundsLayout UID0001VP, generated `NexusTK/map/ObjectPane.cpp`, the executed B001 UID0001D5 report, and every affected manual coverage row. Evidence-time active-report/goal search found no B-agent collision for UID00009R or the typed helpers.
- Search terms were exactly: `UID0001DJ`, `UID:0001DJ`, `0001DJ`, `0x0053ca20`, `0x0053ce3c`, `SoundObjectPaneCore`, `SoundObjectPane`, `0x0053d660`, `0x00620ae4`, `UID0001DN`, `UID00035A`, `g_soundObjectPanePool`, `0x005376d0`, and `0x00537700`.
- Central executed root searched: `executed-b-agent-research`. No direct exact-range/target report exists. Relevant opened artifacts were:
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch4.md`: valid retained `0x0050ec30` SoundObjectPane construction helper with no incoming route; support/history, not target ownership.
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch8.md`: live opcode `0x19` MapPane packet handler with three constructor calls, one StartPlayback call, and MapPane parser ownership; direct caller support.
  - `executed-b-agent-research/B001/0001D5-objectpane-core-source-quality.md`: prior `+0x120` generic owned-image label, live setter, and no-route clear helper; adopted only as historical evidence and independently corrected by current callers.
  - `executed-b-agent-research/B001/000260-ObjectPaneReadOnlyData.md`: exact SoundObjectPane RTTI/vtable range and mixed read-only parent disposition; support only.
  - `executed-b-agent-research/B001/0001DE-LivingObjectPaneCore-source-quality.md`: explicitly excludes UID0001DJ as SoundObjectPane-owned; boundary/ownership support only.
  - `executed-b-agent-research/B002/0000AM-PoolAllocator-class-source-quality.md`: existing descriptive pool name `g_soundObjectPanePool`; adopted after fresh storage/wrapper/xref verification.
  - `executed-b-agent-research/B002/0002WM-StaticObjectPanePoolStaticStorage-source-quality.md`: neighboring pool placement only.
  - `executed-b-agent-research/B008/000356-MotionVtableData-source-quality.md`: adjacent RTTI hierarchy support only.
  - `executed-b-agent-research/B015/0001DH-AttachmentAnchorResolver-source-quality.md`: predecessor padding boundary only.
  - Direct-search matches in B014/B004/B002 `0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md` and B015 `0001DH` were predecessor-boundary references, not direct-target reports.
- Legacy executed root searched: `tools/leaser/Agents/Older-Research`; no direct or family match.
- Archived root searched: `archived`; no direct or family match.
- Special report root searched: `tools/leaser/Agents/SpecialReports`; no direct or family match.
- Active roots searched: every `tools/leaser/Agents/Agent-B001` through `Agent-B015` goal/research path. At evidence collection time only B002's assignment matched; no direct-target or UID0003XT/UID0003XU support collision was present.
- Wave2/Wave3 references found in old aggregate text were treated as stale provenance only and did not override evidence-time MCP/by-structure evidence.

## Target

- Target UID: `0001DJ`.
- Target path: `by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md`.
- Source queue/report row: reconstructable Empty Emitter priority from `auto-generated/-ag-research-tracker.md`, by-memory Not-Covered/Reconstructable inventory.
- Evidence-time supervisor classification: report-only research before exact-artifact Gate 1; that artifact was subsequently accepted for this bounded callback.
- Evidence-time scores and parent state: `86/90`, owner/emitter UID0000DH, reconstructable true, blank position/formal C++, `Nested:0`.

## Current Target State

- UID0001DJ is now `92/94`, retains semantic owner UID0000DH, is non-reconstructable with blank emitter/position/formal C++, and indexes four exact source children plus compiler padding/table spans. Its evidence-time aggregate-emitter state and Empty Emitter Marker are superseded history.
- UID0000DH is now `92/94`, owner/emitter UID0000NW, reconstructable true at position `10`, with the complete `0x158` class declaration. UID0000NW is `92/92` and remains prose-only without by-file reconstruction metadata.
- Evidence-time generated SHA256 `511A785040B5B62BD6BA1A1F4A7433D30810D4D241BB8F20A18CE85977B77689` and its four empty markers remain historical pre-callback evidence. Final waited generated output is recorded under Validator Results and has no UID0001DJ, UID0000DH, UID00035A, or UID0002WN empty marker.
- UID0001DJ now documents probability at `+0x148` and repeat delay at `+0x144`; the old probability-at-`+0x144` statement is retained only as superseded history.
- `OnTriggerSound` is retained only as a descriptive historical alias. The applied source-facing virtual name is `OnTimer`.
- ObjectPane `+0x120` is now the typed `SoundObjectPane *m_soundObjectPane` field, with the deleting replacement and no-release clear declarations and exact UID0003XT/UID0003XU definitions.
- UID00009R is now a complete `92/94` reconstructable declaration emitter at position `10`. It preserves exact `0x128` size/layout, pure ordinary destructor, concrete empty `RenderFrame`/`DrawSpriteFrame` defaults, typed sound-pane link, and complete child insertion.
- UID0002SK is now `91/94`, owner/emitter UID00009R, reconstructable true at position `90`, with class-covered compiler output and no handwritten RTTI/vtable arrays.
- UID0001DN remains a mixed non-emitting destructor index at `90/92`; UID000387 is now the `91/94` non-emitting scalar wrapper with blank emitter/position/formal C++; UID00035A, UID0002WN, and UID0003CB carry their accepted class support dispositions.
- Related target/support docs checked: UID0000DH, UID0000NW, UID0001DN, UID000387, UID00035A, UID0002WN, UID0003CB, UID00009R, UID0000M5, UID0003XT, UID0003XU, UID0003TS, UID0004DZ, UID0000F0, UID0000F1, UID0000SI, UID0000NV, UID00028R, UID0000PR, UID0000TI, UID0002B4, and generated SoundObjectPane.cpp.
- B002 callback state: accepted ordinary destinations are applied, scoped validators and final waited generation completed, and all B002 leases are released. Supervisor-owned report validation/execution/move/archive state is not asserted.

## Executive Recommendation

- Semantic ownership remains with SoundObjectPane UID0000DH and file ownership with SoundObjectPane UID0000NW.
- UID0001DJ is `92/94`, retains semantic `CANONICAL_OWNER:0000DH`, has `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and `Nested:0`.
- Exact children UID0004PV/UID0004PW/UID0004PX/UID0004PY are applied at positions `20/30/40/50`; class, pool, vtable, and random-constant positions are `10/0/60/70`.
- Complete human source is applied for the constructor, ordinary destructor, StartPlayback, and OnTimer. Vptr stores, EH/security-cookie support, switch-table bytes, adjustors, scalar delete flags, base destruction, pool return, and vtable/COL arrays remain compiler-only.
- UID0003XT/UID0003XU are source-corrected as the typed SoundObjectPane setter and no-release clear. The clear helper's zero direct xrefs remain documented; its exact conditional clear is inlined in SoundObjectPane destruction while the out-of-line body remains at `0x00537700`.
- UID00009R contains Destination 14. `ObjectPane.h` includes the complete `Pane`/`RectBounds` dependencies and forward-declares `SoundObjectPane`, `GrafPort`, and `MapPoint`; `ObjectPane.cpp` includes `ObjectPane.h` and then `SoundObjectPane.h` before the deleting setter. No circular class inclusion or by-file reconstruction block was introduced.
- UID0002SK is covered by UID00009R at position `90` through Destination 19. The complete declaration and ordinary source regenerate all three vtable views; no table literal is handwritten.
- No investigated blocker remains that justifies blank child C++; stripped original spelling uncertainty is represented by descriptive names and the 94 confidence cap.

## Supervisor Active Recheck

- The supervisor assigned UID0001DJ as the first empty-emitter/no-direct-report SoundObjectPane target and required mandatory live MCP research.
- Split repair is mandatory before source emission because the aggregate contains four functions, two padding spans, and one compiler switch table.
- Every source-bearing subrange has a formal destination. Every non-source subrange has an explicit compiler/padding disposition. Related scalar, vtable, pool, threshold, ObjectPane-link, caller, and source-file routes have accepted destinations or verify-only reasons.

## Inference Research Guidance Check

- `by-structure.md` requires exact leaves to emit and mixed aggregates to remain indexes; this directly controls UID0001DJ's conversion.
- IDA facts are separated from inference: addresses, bytes, xrefs, offsets, vtables, calls, and branches are facts; enum/member spellings are high-probability source-facing inference.
- Existing labels were not trusted. `OnTriggerSound`, `m_ownedObjectImageState`, probability at `+0x144`, all-`ff` pool storage, and aggregate emission were rechecked and superseded where contradicted.
- Consumer ownership was not confused with source ownership: MapPane owns packet decoding; SoundManager and TimerMgr own services; SoundObjectPane owns the object lifecycle and callback policy.
- No explicit Wave2/Wave3 override applied at evidence collection or callback reconciliation.

## Heuristic / Inference Reanalysis And Validation

- Aggregate/source issue: four independent function starts and compiler-only gaps make one body invalid. Resolution: semantic index plus four exact children.
- Callback issue: no direct code caller exists for `0x0053cc70`. Resolution: the data xref at `0x00620b8c`, tertiary vtable view, `this-0xa4` owner recovery, three explicit arguments, and true return prove a TimerHandler virtual callback rather than dead/raw code.
- Timer-receiver issue: callback decompiler offsets are relative to the TimerHandler facet. Resolution: add `0xa4` to adjusted offsets to recover complete-object fields; source remains a normal SoundObjectPane virtual method.
- Field issue: fresh constructor and caller decompilation resolves two 12-byte records and six scalar fields. `+0x140` is playback mode, `+0x144` repeat delay, `+0x148` probability, `+0x14c` lifetime policy, `+0x150` lifetime value, and `+0x154` remaining play count.
- Descriptor issue: `+0x12c/+0x130` are passed unchanged as sample id and volume scale. `+0x128` is descriptor kind and is retained although core playback does not branch on it.
- Origin issue: origin kind zero carries ObjectPane pointer at `+0x138`; kind one carries map X/Y at `+0x138/+0x13c`; other kinds construct at zero/zero. A 32-bit union is the period-plausible exact layout.
- Caller parse issue: the live packet handler reads descriptor kind as a byte, sample id as a 16-bit value, and volume scale as a byte; reads origin kind as a byte; resolves object origin through ObjectList and `GetMapPosition`, reads coordinate origin as two 16-bit values, or supplies zero/zero for other kinds; reads playback mode as a byte; for mode three reads a 16-bit repeat delay; for mode four reads the same delay plus a 16-bit probability divided by `100.0f`; then reads lifetime policy as a byte and a 16-bit lifetime value only for policies one/two. The constructor stores normalized dword/float fields, so the source-facing class fields remain `int`/`float` rather than packed packet fields.
- Object link issue: only two callers reach `0x005376d0`, and both pass a newly constructed SoundObjectPane. Its old generic image-state name is rejected. `0x00537700` is the typed no-release clear, retained out-of-line after the same operation is inlined in destruction.
- ObjectPane declaration issue: fresh constructor decompilation writes byte `+0xf8`, dwords `+0xfc/+0x100/+0x104`, zero `RectBounds` at `+0x108`, null pointers at `+0x118/+0x120`, zero float/dword at `+0x11c`, and zero byte at `+0x124`; the next derived field begins at `+0x128`. The complete declaration uses implicit compiler padding after the two byte fields rather than fabricated reserve arrays.
- ObjectPane abstractness issue: UID0002SK primary slot `+0x00` is `__purecall`, while concrete SoundObjectPane slot `+0x00` is its scalar deleting wrapper. The source-safe declaration is therefore `virtual ~ObjectPane() = 0;` with the existing UID0003XO ordinary destructor body defined out of line. Scalar wrappers, vptr stores, adjusted tables, and RTTI remain compiler output.
- ObjectPane render-default issue: primary slots `+0x5c` and `+0x64` are not `__purecall`; both point to `0x0041b6c0`, exact `nullsub_18` with one instruction `retn 8`. MapPane helpers `0x0050dcc0` and `0x0050dd60` dispatch those slots with `(GrafPort *, RectBounds *)`, and the LivingObjectPane vtable/current accepted children identify the common source-facing contracts as `RenderFrame` and `DrawSpriteFrame`. Destination 14 therefore defines both as concrete empty `void` virtuals in exact slot order. Their shared machine address is consistent with linker identical-function folding of two empty methods, not one aliased source declaration. Leaving them undeclared would under-specify UID0002SK; declaring them pure would incorrectly make directly instantiated SoundObjectPane abstract.
- ObjectPane override issue: comparison with PaneVtables resolves `0x00537740` at primary slot `+0x0c` as `UpdateRenderRegion(const RectBounds *)`, `0x00537720` at `+0x20` as the ObjectPane `InvalidateRect` override, and `0x00537760` at `+0x2c` as the two-argument `SetBounds` override. Existing child titles remain searchable historical/descriptive labels where they differ from these source-facing base contracts.
- Playback mode issue: values `0..4` are exact. Descriptive names are destroy-without-play, one-shot-delete, one-shot-policy, repeated, and probability-repeated. Original enumerator spellings remain stripped, but behavior is complete.
- Lifetime policy issue: values `0/1/2` are persistent, count/after-play, and timeout. Value one means one playback then deletion in mode two and a count in repeated modes; value two schedules timer id one after seconds-to-milliseconds conversion.
- Probability issue: only mode four gates playback. The exact comparison is strict probability-times-32767 greater than floating conversion of `rand()`; equality does not play, and counted mode decrements even on a failed probability test.
- Destruction issue: virtual self-destruction is intentional. The compiler scalar wrapper applies delete flags and returns storage to the pool; source uses ordinary virtual deletion only.
- Timer cleanup issue: no explicit cancellation appears in SoundObjectPane destruction. TimerHandler base destruction unregisters pending events, so adding explicit cancellation would be invented behavior.
- Pool issue: evidence-time storage is zero-initialized, not all `ff`. Wrapper arguments prove a 344-byte block and 32 blocks per chunk; existing module naming proves the static declaration.
- Table issue: five dwords are switch targets, not source data. A normal switch regenerates them.
- Rejected owners: MapPane is a caller/parser, SoundManager is playback service, TimerMgr is scheduler, ObjectPane is the base/link owner, UID0001DN is compiler-wrapper inventory, and the mixed read-only parent is not a source module.
- Rejected code forms: hard-coded owner offset subtraction, handwritten vptrs/vtables, explicit scalar wrappers, explicit jump-table arrays, generic void pointer records, a manual timer-cancel branch, null checks absent from the binary, and duplicate source in the aggregate.

## Evidence Standards Used

- Direct evidence: MCP function lookup, bounded bytes, decompilation, disassembly, basic blocks, xrefs, callees, vtable cells, adjustor bodies, scalar wrapper, caller decompilation, pool storage/xrefs, type-catalog negative results, and SHA256 over fresh byte reads.
- ObjectPane dependency evidence: exact `0x005372d0-0x005378fa` constructor/method span, all 13 constructor and 14 destructor-family xrefs, every exact child decompilation/disassembly, the no-function raw clear body, Pane size/layout and virtual-slot maps, all 40 ObjectPane vtable cells across three views, and current generated/manual-coverage readback.
- Documentation evidence: current by-memory/by-class/by-file/by-global pages, generated SoundObjectPane.cpp, source-tree guidance, manual coverage rows, and classified executed reports.
- Negative evidence: no direct target report, no active collision, no recovered SoundObjectPane/TimerHandler type declaration in the IDB type catalog, no code xref to the callback, no direct xref to the raw clear, and no source reason for compiler ABI artifacts.
- The evidence ladder reaches strong direct binary proof for behavior and source family. Missing original symbols cap names/confidence but do not block a defensible first draft.

## Evidence Checked

- MCP: `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `basic_blocks`, `xrefs_to`, `callees`, and `type_query`; original target calls used evidence session `3fc1dcef`, and the Gate-1 ObjectPane repair used fresh database `9df6e9a0` for every IDB-backed call.
- Freshly checked addresses include all target starts, `0x0050ec30`, `0x00512f20`, `0x005376d0`, `0x00537700`, `0x0053d660`, `0x0053cf72`, `0x0053cf7d`, `0x0057a5c0`, `0x00597910`, `0x00620ae8`, `0x00620b58`, `0x00620b88`, `0x00620c6c`, and `0x0069b8e4`.
- Fresh Gate-1 repair checks include `0x005372d0`, every modeled ObjectPane child through `0x005378a0`, raw `0x00537700`, scattered helpers `0x00469050/0x00469080`, Pane slots `0x004b8e20/0x00544b80/0x00544bd0`, ObjectPane vtables `0x00620294-0x00620340`, `__purecall` at `0x005ca28c`, empty two-argument virtual `nullsub_18` at `0x0041b6c0`, MapPane dispatch helpers `0x0050dcc0/0x0050dd60`, derived slot representatives through SoundObjectPane `0x00620b44`, and the concrete SoundObjectPane first slot at `0x00620ae8`.
- `tools/int_convert.py` verified 148/`0x94`, 136/`0x88`, 268/`0x10c`, 460/`0x1cc`, 344/`0x158`, 32/`0x20`, 160/`0xa0`, 164/`0xa4`, 288/`0x120`, offsets `0x128..0x154`, 32767/`0x7fff`, and 1000/`0x3e8`.
- Current ordinary docs and every affected manual coverage row were read-only inspected. No generated coverage was treated as a substitute for manual coverage review.
- The only failed calls were client-payload mistakes during resume: one PowerShell legacy-parser error, one shadowed `$args` payload, and one wrong `get_bytes` field name. Schemas were refreshed, each call was corrected, and valid bounded responses followed. They are not MCP evidence failures.
- Initial report-only pass intentionally skipped IDA mutation, by-* edits, leases, implementation validators, generated refresh, report execution/probes, lifecycle commands, moves, and archives. The later accepted callback performed only the ordinary edits, leases, validators, and authorized generated refresh recorded below; lifecycle actions remained prohibited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Applied destination / proof | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001DJ becomes a non-emitting semantic split index while retaining UID0000DH semantic ownership. | very strong | Four functions plus padding/table; by-structure | Destination 1; target validator `000000011683` | incorporate | applied |
| C02 | Four exact source children cover constructor, ordinary destructor, StartPlayback, and OnTimer. | very strong | Function lookup, bytes, CFG | Destinations 4-7; UID0004PV/PW/PX/PY validators `000000011648/11655/11656/11657` | incorporate | applied |
| C03 | UID0000DH/UID0000NW are the class/file source route. | very strong | RTTI, callers, existing source tree | Destinations 3/13; validators `000000011664/11669` | incorporate | applied |
| C04 | Class size is `0x158` with inherited EventHandler `+0xa0` and TimerHandler `+0xa4` views. | very strong | RTTI PMDs, vptr stores, pool block | Destination 3; validator `000000011664` | incorporate | applied |
| C05 | Static pool declaration uses block `0x158`, count `0x20`, and module-local name. | very strong | Wrapper args, 8 xrefs, prior name | Destination 2; validator `000000011665` | incorporate | applied |
| C06 | Constructor range/hash/37-instruction/`retn 0x24` ABI is exact. | very strong | Fresh bytes/disasm/hash | Destination 4, UID0004PV; validator `000000011648` | incorporate | applied |
| C07 | Constructor takes two 12-byte records plus mode/delay/probability/policy/value and leaves remaining count uninitialized. | very strong | Constructor and caller decompilation | Destinations 3-4; validators `000000011664/11648` | incorporate | applied |
| C08 | Ordinary destructor clears an object link, removes from active MapPane, and relies on automatic base teardown. | very strong | Dtor decompile/CFG/callees | Destination 5, UID0004PW; validator `000000011655` | incorporate | applied |
| C09 | ObjectPane is a complete `0x128` abstract Pane-derived declaration whose `+0x120` field is `SoundObjectPane *m_soundObjectPane`; typed replace/delete and no-release clear definitions have exact compile-visible declarations/source placement, while concrete empty `RenderFrame`/`DrawSpriteFrame` defaults preserve primary slots `+0x5c/+0x64`. | very strong | Constructor/layout/vtable pass, two typed callers, destructor inline body, `__purecall` versus `nullsub_18` recheck, MapPane slot callers, complete Destination 14 | Destinations 11-12/14-15/19; validators `000000011681/11670/11671/11678/11634` | reject-stale | applied |
| C10 | StartPlayback owns the five-entry compiler switch table and exact mode dispatch. | very strong | Bytes, targets, CFG | Destination 6, UID0004PX; validator `000000011656` | incorporate | applied |
| C11 | Modes zero and one respectively destroy without play and play then destroy. | very strong | StartPlayback decompile | Destination 6, UID0004PX; validator `000000011656` | incorporate | applied |
| C12 | Mode two implements persistent, after-play deletion, and timeout policies. | very strong | StartPlayback/callback branches | Destinations 6-7; validators `000000011656/11657` | incorporate | applied |
| C13 | Modes three/four schedule an immediate repeat event, then initialize count or timeout state. | very strong | StartPlayback branches | Destination 6, UID0004PX; validator `000000011656` | incorporate | applied |
| C14 | `0x0053cc70` is the TimerHandler OnTimer override through vtable cell `0x00620b8c`. | very strong | Vtable xref, `retn 0x0c`, adjusted view | Destinations 3/7; validators `000000011664/11657` | reject-stale | applied |
| C15 | Mode-two callback only deletes for timeout policy and timer id one. | very strong | Callback CFG | Destination 7, UID0004PY; validator `000000011657` | incorporate | applied |
| C16 | Deterministic repeat implements persistent/count/timeout branches and exact rescheduling. | very strong | Callback CFG/calls | Destination 7, UID0004PY; validator `000000011657` | incorporate | applied |
| C17 | Probability repeat uses strict `probability*32767 > float(rand())`; failed tests still consume count. | very strong | Two constant xrefs and branches | Destination 7, UID0004PY; validator `000000011657` | incorporate | applied |
| C18 | Repeat delay is `+0x144`; probability is `+0x148`; timeout value is seconds multiplied by 1000. | very strong | Adjusted offsets, caller parse | Destinations 3/6/7; validators `000000011664/11656/11657` | historicalize | applied |
| C19 | PlaySample consumes sample id and volume scale; globals retain established names. | very strong | Callee signature and calls | Destinations 6-7/16; current dependencies matched accepted evidence | already-present | already-present |
| C20 | Live MapPane handler is the active caller; `0x0050ec30` remains valid retained no-route duplicate/helper evidence. | very strong | Xrefs and report/binary checks | Destination 16; MapPane validator `000000011672` plus retained evidence | incorporate | applied |
| C21 | Three vtable views and two adjustors are compiler ABI generated from normal inheritance. | very strong | Vtable refs, 0xa0/0xa4 thunks | Destination 8; validator `000000011666` | incorporate | applied |
| C22 | UID000387 is a non-emitting compiler scalar wrapper; no handwritten duplicate is valid. | very strong | Scalar decompile, delete flags, pool free | Destination 9; validator `000000011668` | reject-invalid | applied |
| C23 | UID0003CB is the source literal 32767.0 used only by OnTimer and emits as covered-by. | very strong | Dword and two xrefs | Destination 10; validator `000000011667` | incorporate | applied |
| C24 | Twelve/eight CC spans and the 20-byte switch table are padding/compiler output. | very strong | Fresh bytes/hashes | Destination 1 split inventory; validator `000000011683` | incorporate | applied |
| C25 | Source belongs in `NexusTK/map/SoundObjectPane.cpp`, not MapPane/SoundManager/TimerMgr. | very strong | Responsibility and source-tree evidence | Destinations 3/13; validators `000000011664/11669` | incorporate | applied |
| C26 | by-file pages receive prose only and never reconstruction metadata. | very strong | by-file guidance | Destinations 13/15; validators `000000011669/11678`; metadata readback clean | incorporate | applied |
| C27 | Old `OnTriggerSound`, generic image-state field, probability-at-+0x144, and all-ff pool wording remain labeled historical. | very strong | Current contradictory evidence | Destinations 1-16; changed-page validators listed below | historicalize | applied |
| C28 | Applied scores reflect complete SoundObjectPane behavior and a source-safe ObjectPane declaration, with only stripped spelling and unrelated ObjectPane body caps. | strong | Score-blocker audit plus fresh UID00009R declaration audit | Score section and all destination metadata; scoped validator readback | incorporate | applied |
| C29 | Every source/code/blank/covered disposition has exact managed formal text, including UID00009R and UID0002SK. | very strong | Managed-block and destination audit | Destinations 1-14/19; final validators `000000011681/11685` | incorporate | applied |
| C30 | Manual coverage replacements/additions include exact ObjectPane class/vtable rows; callback compile/generated verification is exact and supervisor-owned. | very strong | Read-only row audit/guidance | Manual text unchanged; final waited validator `000000011685` and generated readback | incorporate | applied |

Ledger audit: every Action value remains within the permitted vocabulary. Callback Verification states use only legal terminal values; C01-C18 and C20-C30 are `applied`, while verify-only C19 is `already-present`.

## Positive Evidence Summary

- Four exact function records cover all executable bytes; two CC spans and one switch table cover the remaining internal bytes.
- Six constructor xrefs and two StartPlayback xrefs identify both retained and live construction flows.
- The callback is live through a vtable data xref despite no direct code caller.
- Constructor writes, caller records, callback adjusted offsets, and PlaySample arguments agree on every class field.
- The scalar wrapper, pool storage, pool free, RTTI, and three vtable views agree on class size, lifecycle, and inheritance.
- The strongest inference chain is the ObjectPane link: both setter callers pass newly created SoundObjectPane objects, setter deletes the previous pointer, destructor clears exactly that field, and the raw helper contains the identical conditional clear. This is sufficient to replace the generic image-state type.
- Fresh UID00009R evidence closes the compile-integration chain: Pane is exactly `0xf8`; ObjectPane is exactly `0x128`; constructor writes every field; established method children and primary slots resolve all declarations used by the class; the pure virtual destructor is the only ObjectPane-owned pure source contract while `+0x5c/+0x64` are concrete empty render defaults; `SoundObjectPane` can be forward-declared in the header and completed in ObjectPane.cpp; and UID0002SK is generated from the class rather than emitted as a table.

## IDA MCP Facts

- Function facts: constructor `0x0053ca20-0x0053cab4`, 148 bytes, 37 instructions, one block; destructor `0x0053cac0-0x0053cb48`, 136 bytes, 43 instructions, five in-range behavior blocks plus analysis-only external EH chunks; StartPlayback `0x0053cb50-0x0053cc5c`, 268 bytes, 83 instructions, 15 blocks; OnTimer `0x0053cc70-0x0053ce3c`, 460 bytes, 124 instructions, 37 blocks. Decimal/hex pairs were verified with `int_convert.py`.
- Fresh SHA256 values: constructor `4f43ea3a11f2b8ccb13f495fef453472a63bfd59708525c192da53810521c828`; first padding `a0d08a155aa4e9aadd5da959565de99acc8dc9dbda96ec3852dde76c97330902`; destructor `32ebf0c2f40b2df6642aa01b1ee30ce4bfb7167e87aa0601712b5897f5a68188`; second padding `3d2f424783df5853c8d7121b1371650c04241f318e1b0cd46bedbc805b9164c3`; StartPlayback `32d1ea733b38134b2fe14ef4c57573948d5deb64a449b8cce4e49b7ae53d7e3f`; switch table `741ea8cc208770239a16cd4e2a75a4014d5fc5f3c487de56f0f56ea10a6138d1`; OnTimer `c4e759a2be646c5cf5959227dd15e913746fc36bd6414d05dd3b76674fd26274`.
- Data/table facts: `0x0053cab4-0x0053cac0` is 12 CC bytes; `0x0053cb48-0x0053cb50` is 8 CC bytes; table bytes are `6a cb 53 00 c9 cb 53 00 73 cb 53 00 05 cc 53 00 05 cc 53 00`, targeting cases zero through four.
- Xrefs: constructor has six code xrefs, StartPlayback two, ordinary destructor zero direct, OnTimer one data xref at `0x00620b8c`; random constant has two xrefs inside OnTimer; pool base has eight direct xrefs.
- Vtables: primary `0x00620ae8`, EventHandler view `0x00620b58`, TimerHandler view `0x00620b88`; constructor/destructor/scalar each store all three. Adjustors at `0x0053cf72` and `0x0053cf7d` subtract `0xa0` and `0xa4` then jump to scalar destruction.
- Globals/callees: active MapPane `0x0067a764`, SoundManager `0x0067a7d0`, TimerMgr `0x0067ab80`; direct callees are ObjectPane construction/destruction, MapPane remove, SoundManager PlaySample, TimerMgr ScheduleTimer, and `rand`.
- Type-catalog negative fact: no recovered SoundObjectPane or TimerHandler UDT/declaration existed in the evidence-time IDB type catalog, so descriptive source names remain inference rather than symbol proof.
- Fresh ObjectPane byte hashes from database `9df6e9a0`: `0x005372d0-0x005378fa` (1,578 bytes) SHA256 `FC7AE088975A8AD475D3078D21BB45DE980F46BAF398408DC31021020C3081E0`; setter `0x005376d0-0x005376f4` SHA256 `E13ABB02F403AE1042D0776CC677AD9EDD81F3CD140948FE0C1B2EE854D036F0`; raw clear `0x00537700-0x00537714` SHA256 `46BEF2FB067556E0B3E8090D1949DE3E06784601D57F0033E55456F45CEA63AF`; vtable child `0x00620294-0x00620340` SHA256 `62F59AF437F8E7CF94B5829A11A6B86BE7AAA959447C4DCCB0C594D3A2817339`.
- Fresh ObjectPane vtable facts: primary view `0x00620298-0x00620304` has 27 cells; inherited EventHandler view `0x00620308-0x00620334` has 11; inherited TimerHandler view `0x00620338-0x00620340` has two. Constructor and ordinary destructor are the only direct vptr-store xrefs to all three bases. `0x00620340` is the exact StaticObjectPane RTTI successor boundary. The first cells at `0x00620298`, `0x00620308`, and `0x00620338` all point to real `__purecall` as the three pure-destructor views; primary `+0x5c/+0x64 -> 0x0041b6c0` are the same concrete two-argument empty default, not pure cells.
- Primary source-contract cells directly relevant to the declaration are `+0x0c -> 0x00537740` UpdateRenderRegion, `+0x20 -> 0x00537720` InvalidateRect, `+0x2c -> 0x00537760` SetBounds, `+0x48 -> 0x005374f0` AttachObject, `+0x4c -> 0x005375f0` DetachObject, `+0x50 -> 0x00469050` ClearOutputRects, `+0x54 -> 0x00537800` SetObjectData, `+0x58 -> 0x00537880` GetObjectData, `+0x5c -> 0x0041b6c0` empty RenderFrame, `+0x60 -> 0x00469080` GetEmptyRect, `+0x64 -> 0x0041b6c0` empty DrawSpriteFrame, and `+0x68 -> 0x005378a0` SetMapPosition. Destination 14 declares or defines every ObjectPane-owned cell and does not invent handwritten ABI wrappers/tables.

Derived-primary slot comparison from the same bounded read proves both default contracts and override signatures:

| Class / primary cells | `+0x5c` | `+0x64` | Source-contract conclusion |
| --- | --- | --- | --- |
| ObjectPane `0x00620298` | `0x0041b6c0` empty | `0x0041b6c0` empty | concrete two-argument defaults |
| StaticObjectPane `0x00620344` | `0x005379a0` | `0x0041b6c0` | overrides RenderFrame only |
| ItemObjectPane `0x006203f0` / FlyingObjectPane `0x0062049c` | shared `0x00537c70` | `0x0041b6c0` | shared RenderFrame override; second stage inherits empty |
| AttachedObjectPane `0x00620548` | `0x0041b6c0` | `0x0041b6c0` | inherits both empty defaults |
| EffectObjectPane `0x006205fc` | `0x00538af0` | `0x0041b6c0` | overrides RenderFrame only |
| HitBar `0x00620738` / DamageNumber `0x006207ec` / ObjectInfo `0x006208a0` | `0x00539030` / `0x005394d0` / `0x005398e0` | `0x0041b6c0` | each overrides RenderFrame only |
| LivingObjectPane `0x0062097c` | `0x0053bb20` | `0x0053bd20` | accepted `RenderFrame` and `DrawSpriteFrame` overrides with `(GrafPort *, const RectBounds *)` |
| LightingObjectPane `0x00620a3c` / SoundObjectPane `0x00620ae8` | `0x0041b6c0` | `0x0041b6c0` | both remain concrete by inheriting the two defaults |

### Exact Class Layout

| Complete-object offset | Applied type/name | Exact use |
| --- | --- | --- |
| `+0x000..+0x127` | ObjectPane base | Includes primary view and inherited EventHandler/TimerHandler facets. |
| `+0x0a0` | EventHandler adjusted view | Secondary deleting-destructor vtable view; no target-local event body. |
| `+0x0a4` | TimerHandler adjusted view | Tertiary deleting-destructor view and OnTimer slot. |
| `+0x128` | `int m_sound.kind` | Caller-provided descriptor kind; copied but not branched on by this core. |
| `+0x12c` | `unsigned int m_sound.sampleId` | First PlaySample argument. |
| `+0x130` | `int m_sound.volumeScale` | Second PlaySample argument. |
| `+0x134` | `int m_origin.type` | Zero object-linked, one map coordinates, other non-positional. |
| `+0x138` | `ObjectPane *m_origin.object` / `int m_origin.mapX` | 32-bit union selected by origin type. |
| `+0x13c` | `int m_origin.mapY` | Coordinate-origin Y; zero for non-positional construction. |
| `+0x140` | `int m_playbackMode` | Exact mode values zero through four. |
| `+0x144` | `int m_repeatDelayMilliseconds` | Repeat-event reschedule delay; historical probability label rejected. |
| `+0x148` | `float m_playProbability` | Mode-four random threshold multiplier. |
| `+0x14c` | `int m_lifetimePolicy` | Persistent/count/timeout values zero/one/two. |
| `+0x150` | `int m_lifetimeValue` | Play count or timeout seconds according to policy. |
| `+0x154` | `int m_remainingPlayCount` | Initialized only when repeated counted playback starts, then decremented per event. |
| `+0x158` | end of object | Matches pool block size 344 bytes. |

ObjectPane base sublayout used by both the SoundObjectPane declaration and Destination 14:

| ObjectPane offset | Applied type/name | Exact use |
| --- | --- | --- |
| `+0x000..+0x0f7` | `Pane` base | Exact Pane size `0xf8`, including adjusted EventHandler/TimerHandler views at `+0xa0/+0xa4`. |
| `+0x0f8` | `unsigned char m_objectType` | Constructor byte argument; ObjectPane-type discriminator. Compiler supplies three alignment bytes. |
| `+0x0fc` | `int m_objectId` | ObjectList id lookup; `m_objectSerial` retained only as a historical/protocol alias. |
| `+0x100` | `int m_mapX` | First stored map coordinate and SetMapPosition first input. |
| `+0x104` | `int m_mapY` | Second stored map coordinate; GetMapPosition writes this to output element zero. |
| `+0x108` | `RectBounds m_objectDataRect` | Exact 16-byte rectangle used by invalidation/set/get methods. |
| `+0x118` | `ObjectPane *m_attachedObject` | Attach/detach/get/destructor state. |
| `+0x11c` | `float m_attachmentHeightOffset` | Light-image/attachment descriptor height contribution. |
| `+0x120` | `SoundObjectPane *m_soundObjectPane` | Typed owned link; setter deletes/replaces, clear only nulls, SoundObjectPane destructor clears its owner link. |
| `+0x124` | `unsigned char m_transientObjectFlag` | Constructor and local-object refresh clear it; compiler supplies three tail-padding bytes. |
| `+0x128` | end of ObjectPane | First SoundObjectPane field; proves complete base size without explicit reserve fields. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0053ca20-0x0053ce3c` | UID0001DJ `by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md` | semantic split index | false | UID0000DH semantic owner | `92/94` | applied blank aggregate |
| `0x0053ca20-0x0053cab4` | UID0004PV `by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md` | constructor | true | UID0000DH | `92/94` | applied at position 20 |
| `0x0053cab4-0x0053cac0` | UID0000VN ignored | alignment | false | none | `100/strong` | preserve |
| `0x0053cac0-0x0053cb48` | UID0004PW `by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md` | ordinary destructor | true | UID0000DH | `92/94` | applied at position 30 |
| `0x0053cb48-0x0053cb50` | UID0000VN ignored | alignment | false | none | `100/strong` | preserve |
| `0x0053cb50-0x0053cc5c` | UID0004PX `by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md` | source method | true | UID0000DH | `93/94` | applied at position 40 |
| `0x0053cc5c-0x0053cc70` | UID0000VN ignored | compiler switch table | false | none | `100/strong` | preserve as generated table |
| `0x0053cc70-0x0053ce3c` | UID0004PY `by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md` | TimerHandler override | true | UID0000DH | `93/94` | applied at position 50 |
| class | UID0000DH `by-class/SoundObjectPane.md` | declaration/layout | true | UID0000NW | `92/94` | applied at position 10 |
| pool | UID0002WN `by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md` | static declaration | true | UID0000DH | `91/94` | applied at position 0 |
| vtable | UID00035A `by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md` | compiler ABI covered by class | true marker | UID0000DH | `91/94` | applied at position 60 |
| threshold | UID0003CB `by-memory/0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant.md` | source literal covered by class | true marker | UID0000DH | `91/94` | applied at position 70 |
| scalar wrapper | UID000387 `by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md` | compiler deleting wrapper | false | UID0000DH semantic owner | `91/94` | applied blank/non-emitting |
| mixed scalar index | UID0001DN current path | Sound/Static compiler inventory | false | none | `90/92` | verify-only unchanged |
| `0x005376d0-0x005376f4` | UID0003XT `by-memory/0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane.md` | typed ObjectPane setter | true | UID00009R | `91/93` | applied at position 70 |
| `0x00537700-0x00537714` | UID0003XU `by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md` | typed no-release clear | true | UID00009R | `90/92` | applied at position 80 |
| ObjectPane class | UID00009R `by-class/ObjectPane.md` | complete abstract declaration/layout plus two concrete empty render defaults | true | UID0000M5 | `92/94` | applied at position 10 |
| ObjectPane vtable | UID0002SK `by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md` | compiler ABI covered by class | true marker | UID00009R | `91/94` | applied at position 90 |
| ObjectPane exact method children | UID0003XN-UID0003Y0 plus UID00020R/UID00020S | established declarations/body owners | mixed source-ready body state | UID00009R | preserve current individual scores except typed helpers | declaration dependencies; no duplicate body invented |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| constructor | `0x0050ecaf`, `0x0050ed0f`, `0x0050ed8a` in `0x0050ec30` | retained source-shaped construction helper with no inbound route |
| constructor | `0x005131de`, `0x0051323c`, `0x005132b0` in UID0003TS | live opcode `0x19` MapPane parser |
| StartPlayback | `0x0050edb7`, `0x005132e0` | called after successful construction/list insertion |
| ordinary destructor | no direct xref | reached through virtual/scalar lifecycle, not dead |
| OnTimer | data xref `0x00620b8c` | TimerHandler virtual slot |
| setter `0x005376d0` | callers `0x0050eda0`, `0x005132c6` | both install new SoundObjectPane pointers |
| clear `0x00537700` | no direct xref | retained inline/out-of-line body; equivalent logic in ordinary/scalar destruction |
| ObjectPane constructor `0x005372d0` | 13 subclass constructor calls | static/item/flying/attached/effect/living/lighting/sound families establish the `0x128` base layout |
| ObjectPane ordinary destructor `0x005373a0` | 14 direct family/wrapper/EH calls | out-of-line body required even though the primary destructor slot is pure |
| ObjectPane vtable bases | constructor/destructor stores at `0x0053733a/40/4a` and `0x005373d2/d8/e2` | exact primary/EventHandler/TimerHandler views; no handwritten table source |
| ObjectPane default render slots | `+0x5c/+0x64 -> 0x0041b6c0`, `retn 8` | concrete empty `RenderFrame`/`DrawSpriteFrame` defaults; two explicit pointer arguments |
| MapPane render dispatch | `0x0050dcc0 -> +0x5c`, `0x0050dd60 -> +0x64` | both dispatch `(GrafPort *, RectBounds *)` only after bounds/region intersection succeeds |
| random threshold | `0x0053ccc9`, `0x0053cd4b` | two probability-play paths |
| pool `0x0069b8e4` | eight refs across init/alloc/unwind/scalar/free/cleanup | exact class pool ownership |

## Documentation Evidence And IDA Status

- Evidence-time / pre-callback: UID0001DJ had useful boundaries/callers but stale field/callback and blank-emitter conclusions; UID0000DH/UID0000NW omitted declaration/source; UID000387 was wrongly reconstructable/emitting; UID00035A was below the parent gate; UID0002WN retained stale all-`ff` wording; UID0003CB lacked final literal disposition; UID00009R and UID0002SK were blank emitters. These facts remain historical evidence only.
- Applied SoundObjectPane state: UID0001DJ is `92/94`, FALSE, semantic owner UID0000DH, blank emitter/position/C++; UID0000DH is `92/94` at position `10`; UID0000NW is prose-only `92/92`; UID000387 is `91/94`, FALSE, blank emitter/position/C++; UID00035A is class-covered `91/94` at position `60`; UID0002WN is `91/94` at position `0` with exact pool declaration; UID0003CB is class-covered `91/94` at position `70`. Validators are `000000011683`, `000000011664`, `000000011669`, `000000011668`, `000000011666`, `000000011665`, and `000000011667` respectively.
- Applied exact method state: UID0004PV constructor, UID0004PW destructor, UID0004PX StartPlayback, and UID0004PY OnTimer are registered at positions `20/30/40/50` with scores `92/94`, `92/94`, `93/94`, and `93/94`; validators are `000000011648/11655/11656/11657`.
- Applied ObjectPane state: UID00009R is `92/94` at position `10` with the complete declaration and validator `000000011681`; UID0002SK is class-covered `91/94` at position `90` with validator `000000011634`; UID0003XT and UID0003XU have the typed selected paths, exact definitions, positions `70/80`, and validators `000000011670/11671`; UID0000M5 remains prose-only and its final rename-link synchronization passed validator `000000011678`.
- UID0003XN-UID0003Y0 and UID00020R/UID00020S remain the exact body/evidence children. Destination 14 declares their established source contracts without claiming that independently blank exact child bodies were implemented here. Historical child titles such as `ObjectPaneSetBounds` remain searchable while base-vtable comparison supplies the source-facing override declaration.
- UID0003TS remains MapPane-owned and blank; only its caller/support evidence was updated under validator `000000011672`, and it emits no duplicate SoundObjectPane body.
- UID0004DZ MapPane removal, TimerHandler, TimerMgr, SoundManager, active globals, PoolAllocator static inventory, mixed aggregates, UID0001DN, and the other Destination 18 pages were read-only same-or-greater dependencies and remain unchanged.

## Ranked Ownership Analysis

### 1. SoundObjectPane / SoundObjectPane.cpp

- Evidence for: RTTI/class name, three vtables, constructor/scalar/pool agreement, four cohesive methods, source-tree pages, and caller-created SoundObjectPane objects.
- Evidence against: original header and enum spellings are stripped.
- Decision: accepted direct class/file source owner.

### 2. MapPane

- Evidence for: live packet parser allocates/registers the object and invokes startup; active map removes it.
- Evidence against: parser owns packet decoding while target methods own object-local lifecycle/timer state; class RTTI and pool are SoundObjectPane-specific.
- Decision: caller/dependency only.

### 3. SoundManager / TimerMgr / ObjectPane / UID0001DN

- Evidence for: each provides a called service, base layout/link, or compiler-wrapper inventory.
- Evidence against: none owns all four methods or the class data.
- Decision: reject as SoundObjectPane target owner; retain bounded support roles. ObjectPane independently owns its complete base declaration and typed link methods through UID00009R/UID0000M5.

### Proposed new file/grouping, if applicable

- Applied owner/name/path: no new file was created. UID0000NW remains the `NexusTK/map/SoundObjectPane.cpp` source route.
- Applied contents: pool declaration, SoundObjectPane class-owned method definitions, and compiler-generated ABI/data resulting from the declaration.
- Related items incorporated: UID0002WN, UID00035A, UID0003CB, and exact method children UID0004PV/PW/PX/PY.
- Related items excluded from this source owner: MapPane packet parser, ObjectPane typed link methods, TimerMgr/SoundManager internals, and mixed destructor/read-only aggregates.
- Source result: narrow one-class module matching the established by-file route.

## Source Placement

- Place class declaration under UID0000DH and method/pool source in UID0000NW's `NexusTK/map/SoundObjectPane.cpp` route.
- Keep ObjectPane typed link methods under UID00009R/UID0000M5; SoundObjectPane calls the no-release clear but does not own that base helper.
- Place the full ObjectPane declaration in the UID00009R class/header route and the UID0003XT/UID0003XU definitions in `NexusTK/map/ObjectPane.cpp`. Highest-probability original-style placement is exact: `ObjectPane.h` includes `Pane.h` and `RectBounds.h`, forward-declares `class GrafPort;`, `class SoundObjectPane;`, and `struct MapPoint;`, then declares ObjectPane; `ObjectPane.cpp` includes `ObjectPane.h` followed by `SoundObjectPane.h` before compiling `delete m_soundObjectPane`. UID0000M5 remains prose-only and receives no reconstruction metadata.
- Keep ObjectPane constructor/destructor/other method bodies in their existing exact children. Destination 14 supplies declarations, layout, and child insertion only; it does not duplicate those bodies. UID0002SK emits only a covered marker because ordinary class source regenerates RTTI/vtables.
- Keep packet parsing in MapPane, playback implementation in SoundManager, scheduling implementation in TimerMgr, and allocator mechanics in PoolAllocator.
- Reject a monolithic ObjectPane.cpp target body, a MapPane-local nested class, a SoundManager-owned object, and direct emission from UID0001DJ.
- Remaining uncertainty is only exact original symbol spelling, not placement.

## Range / Split / Padding / Reclassification Analysis

- Exact target span length is `0x41c` / 1,052 bytes. Every byte is assigned to one of four function bodies, two CC spans, or one five-entry switch table.
- Child boundaries are exact and non-overlapping: constructor ends at first padding; destructor begins after it; StartPlayback begins after second padding and ends before its table; OnTimer begins immediately after the table and ends at target end.
- The switch entries are case-zero `0x0053cb6a`, case-one `0x0053cbc9`, case-two `0x0053cb73`, and cases three/four `0x0053cc05`.
- No child covers `0x0053ce3c-0x0053ce40` because those four CC bytes are outside UID0001DJ. The next modeled helper at `0x0053ce40` is unrelated.
- UID0001DJ retains semantic owner UID0000DH but loses emitter/reconstructable state to prevent duplicate output.
- UID000387 similarly retains semantic relationship while becoming compiler-only non-emitting.
- UID00009R is not split or rerouted: it remains the one class declaration owner. Its exact `0x128` layout is `Pane[0xf8] + byte/pad + six dwords/records/pointers through +0x124 + implicit tail pad`; no explicit unknown reserve or duplicate ObjectPane shell is valid.
- UID0002SK remains the exact `0x00620294-0x00620340` child and becomes class-covered. The boundary, 27/11/2 cells, pure destructor slot, concrete empty render defaults, inherited cells, and StaticObjectPane successor remain unchanged.

## Negative Evidence Summary

- No exact-range central, legacy, archived, special, or active direct-target report exists.
- No direct callback code xref exists; the vtable data xref positively resolves liveness.
- No direct raw-clear xref exists; exact inlined destructor behavior plus typed setter callers resolves source role without inventing an external runtime call.
- No target branch uses descriptor kind at `+0x128`; it is preserved as caller-provided data rather than assigned fabricated behavior.
- No null checks protect SoundManager, TimerMgr, or active MapPane; first draft preserves that absence.
- No constructor write initializes remaining count at `+0x154`; first draft does not initialize it until counted playback starts.
- No explicit timer cancellation exists in SoundObjectPane destruction.
- No evidence supports handwritten vptr stores, EH/cookie code, switch arrays, adjustor functions, scalar delete flags, or pool-free calls.
- No evidence supports a generic `void *` or image-state type at ObjectPane `+0x120`; both ordinary setter callers carry SoundObjectPane allocations.
- No evidence supports explicit `char[3]` reserves after `+0xf8` or `+0x124`; normal 32-bit alignment supplies both gaps and yields exact size `0x128`.
- No evidence supports hand-authored ObjectPane vtable arrays, adjusted facets, purecall cells, or deleting wrappers. The complete declaration plus ordinary method bodies is the source route.
- No evidence supports treating `+0x5c/+0x64` as pure, omitted, or unresolved. Both are exact `nullsub_18` defaults; directly constructed SoundObjectPane inherits both, while derived panes selectively override either or both.
- Evidence-time active-report/goal search found no other claim on UID00009R, UID0002SK, UID0003XT, or UID0003XU. No callback collision or deferred header owner was carried into the applied callback.

## IDA Rename / Type / Comment Recommendations

- Source-facing target names: constructor, destructor, StartPlayback, and OnTimer. Preserve `OnTriggerSound` only as rejected/superseded historical search vocabulary.
- Source-facing records: `SoundDescriptor` and `SoundOrigin`; the latter uses an object-pointer/map-X union plus map Y.
- Source-facing fields: sound descriptor, origin descriptor, playback mode, repeat delay milliseconds, play probability, lifetime policy, lifetime value, and remaining play count at exact offsets `+0x128..+0x154`.
- UID0003XT is renamed to `ObjectPaneSetSoundObjectPane`; UID0003XU is renamed to `ObjectPaneClearSoundObjectPaneRaw`; old slugs remain historical aliases.
- ObjectPane `+0x120` is typed as `SoundObjectPane *` and documents replace/delete versus no-release clear semantics.
- Retain `m_objectType`, primary `m_objectId`, `m_mapX`, `m_mapY`, `m_objectDataRect`, `m_attachedObject`, `m_attachmentHeightOffset`, and `m_transientObjectFlag` at exact offsets. Retain `m_objectSerial` and old `m_ownedObjectImageState` / `m_auxiliaryImageState` only as explicitly superseded aliases.
- Declare `ObjectPane` abstract with `virtual ~ObjectPane() = 0;`; keep UID0003XO as the out-of-line ordinary destructor and all scalar deleting wrappers compiler-only.
- Declare concrete empty `virtual void RenderFrame(GrafPort *, const RectBounds *)` and `virtual void DrawSpriteFrame(GrafPort *, const RectBounds *)` in exact primary-slot order. Current LivingObjectPane source-bearing children supply the accepted names/signatures; MapPane ignores the return register, and apparent `char`/`int` decompiler returns on tail-calling derived overrides are tail-expression artifacts rather than a source return-type contract.
- Source-facing override corrections from Pane's table are `UpdateRenderRegion` for `0x00537740`, `InvalidateRect` for `0x00537720`, and `SetBounds` for `0x00537760`. Preserve current child slugs as historical/search names until a UID-preserving callback rename is separately authorized; declarations, not filenames, control compile visibility here.
- Original enum/member spelling is not proved; these names are descriptive high-probability reconstruction names and should not be misrepresented as PDB proof.
- IDA mutation is not requested and was not performed.

## First-Draft C++ Recommendation

- Eligible: yes. Exact source-bearing leaves and source-declared/covered support are represented below. Aggregate/scalar/compiler dispositions are exact blank blocks.
- Third-party import directive: not applicable.

### Destination 1 - UID0001DJ semantic index

Exact destination: `by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md`. Applied `92/94`, retained `CANONICAL_OWNER:0000DH`, `RECONSTRUCTABLE:FALSE`, blank emitter/position, and `Nested:0`.

Exact Item Summary: `Non-emitting SoundObjectPane semantic split index over exact constructor, destructor, playback, and timer-callback children with internal padding/table and compiler-wrapper exclusions.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID0002WN pool declaration

Exact destination: `by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md`. Applied `91/94`, owner/emitter UID0000DH, reconstructable true, position `0`, `Nested:0`.

Exact Item Summary: `SoundObjectPane static pool declaration with class-size/chunk policy and complete initialization, allocation, unwind, free, scalar-wrapper, and cleanup evidence.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static PoolAllocator g_soundObjectPanePool(0x158, 0x20);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID0000DH class declaration

Exact destination: `by-class/SoundObjectPane.md`. Applied `92/94`, owner/emitter UID0000NW, reconstructable true, position `10`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SoundObjectPane : public ObjectPane
{
public:
    struct SoundDescriptor
    {
        int kind;
        unsigned int sampleId;
        int volumeScale;
    };

    struct SoundOrigin
    {
        enum Type
        {
            kObject = 0,
            kMapPosition = 1,
            kNone = 2
        };

        int type;
        union
        {
            ObjectPane *object;
            int mapX;
        };
        int mapY;
    };

    enum PlaybackMode
    {
        kDestroyWithoutPlayback = 0,
        kPlayOnceAndDestroy = 1,
        kPlayOnce = 2,
        kRepeatPlayback = 3,
        kRandomRepeatPlayback = 4
    };

    enum LifetimePolicy
    {
        kPersistent = 0,
        kPlayCount = 1,
        kTimeout = 2
    };

    enum TimerId
    {
        kRepeatTimer = 0,
        kLifetimeTimer = 1
    };

    SoundObjectPane(int mapX,
                    int mapY,
                    const SoundDescriptor &sound,
                    const SoundOrigin &origin,
                    int playbackMode,
                    int repeatDelayMilliseconds,
                    float playProbability,
                    int lifetimePolicy,
                    int lifetimeValue);
    virtual ~SoundObjectPane();

    void StartPlayback();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    SoundDescriptor m_sound;
    SoundOrigin m_origin;
    int m_playbackMode;
    int m_repeatDelayMilliseconds;
    float m_playProbability;
    int m_lifetimePolicy;
    int m_lifetimeValue;
    int m_remainingPlayCount;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID0004PV constructor child

Exact destination: [UID:0004PV][0x0053ca20-0x0053cab4.SoundObjectPaneConstructor](by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md), `92/94`, owner/emitter UID0000DH, reconstructable true, position `20`, `Nested:0`.

Exact Item Summary: `SoundObjectPane construction from typed sound/origin records and playback-policy state, with base object coordinates and compiler-managed multiple-inheritance views.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SoundObjectPane::SoundObjectPane(
    int mapX,
    int mapY,
    const SoundDescriptor &sound,
    const SoundOrigin &origin,
    int playbackMode,
    int repeatDelayMilliseconds,
    float playProbability,
    int lifetimePolicy,
    int lifetimeValue)
    : ObjectPane(11, 0, mapX, mapY),
      m_sound(sound),
      m_origin(origin),
      m_playbackMode(playbackMode),
      m_repeatDelayMilliseconds(repeatDelayMilliseconds),
      m_playProbability(playProbability),
      m_lifetimePolicy(lifetimePolicy),
      m_lifetimeValue(lifetimeValue)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID0004PW ordinary destructor child

Exact destination: [UID:0004PW][0x0053cac0-0x0053cb48.SoundObjectPaneDestructor](by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md), `92/94`, owner/emitter UID0000DH, reconstructable true, position `30`, `Nested:0`.

Exact Item Summary: `Ordinary SoundObjectPane destruction with typed linked-object clear, active-map removal, inherited timer cleanup, and compiler lifecycle exclusions.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SoundObjectPane::~SoundObjectPane()
{
    if (m_origin.type == SoundOrigin::kObject &&
        m_origin.object != NULL) {
        m_origin.object->ClearSoundObjectPane();
    }

    g_activeMapPane->RemoveObjectPaneIfPresent(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0004PX StartPlayback child

Exact destination: [UID:0004PX][0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback](by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md), `93/94`, owner/emitter UID0000DH, reconstructable true, position `40`, `Nested:0`.

Exact Item Summary: `SoundObjectPane playback startup across immediate, one-shot, repeated, random, counted, and timeout policies with compiler-generated switch support.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SoundObjectPane::StartPlayback()
{
    switch (m_playbackMode) {
    case kDestroyWithoutPlayback:
        delete this;
        return;

    case kPlayOnceAndDestroy:
        g_pSoundManager->PlaySample(
            m_sound.sampleId, m_sound.volumeScale);
        delete this;
        return;

    case kPlayOnce:
        switch (m_lifetimePolicy) {
        case kPersistent:
            g_pSoundManager->PlaySample(
                m_sound.sampleId, m_sound.volumeScale);
            break;

        case kPlayCount:
            g_pSoundManager->PlaySample(
                m_sound.sampleId, m_sound.volumeScale);
            delete this;
            break;

        case kTimeout:
            g_pSoundManager->PlaySample(
                m_sound.sampleId, m_sound.volumeScale);
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLifetimeTimer,
                1000 * m_lifetimeValue,
                0,
                0);
            break;
        }
        return;

    case kRepeatPlayback:
    case kRandomRepeatPlayback:
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kRepeatTimer,
            0,
            0,
            0);

        if (m_lifetimePolicy == kPlayCount) {
            m_remainingPlayCount = m_lifetimeValue;
        } else if (m_lifetimePolicy == kTimeout) {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLifetimeTimer,
                1000 * m_lifetimeValue,
                0,
                0);
        }
        return;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - UID0004PY OnTimer child

Exact destination: [UID:0004PY][0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer](by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md), `93/94`, owner/emitter UID0000DH, reconstructable true, position `50`, `Nested:0`.

Exact Item Summary: `SoundObjectPane TimerHandler callback with deterministic/probability playback, count and timeout deletion, exact rescheduling, and unconditional handled return.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SoundObjectPane::OnTimer(int timerId, int, int)
{
    if (m_playbackMode == kPlayOnce) {
        if (m_lifetimePolicy == kTimeout &&
            timerId == kLifetimeTimer) {
            delete this;
        }
        return true;
    }

    if (m_playbackMode != kRepeatPlayback &&
        m_playbackMode != kRandomRepeatPlayback) {
        return true;
    }

    if (m_lifetimePolicy == kPersistent) {
        if (timerId == kRepeatTimer) {
            if (m_playbackMode == kRepeatPlayback ||
                m_playProbability * 32767.0f >
                    static_cast<float>(rand())) {
                g_pSoundManager->PlaySample(
                    m_sound.sampleId, m_sound.volumeScale);
            }

            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kRepeatTimer,
                m_repeatDelayMilliseconds,
                0,
                0);
        }
        return true;
    }

    if (m_lifetimePolicy == kPlayCount) {
        if (timerId == kRepeatTimer) {
            if (m_remainingPlayCount > 0) {
                if (m_playbackMode == kRepeatPlayback ||
                    m_playProbability * 32767.0f >
                        static_cast<float>(rand())) {
                    g_pSoundManager->PlaySample(
                        m_sound.sampleId, m_sound.volumeScale);
                }

                --m_remainingPlayCount;
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kRepeatTimer,
                    m_repeatDelayMilliseconds,
                    0,
                    0);
            } else {
                delete this;
            }
        }
        return true;
    }

    if (m_lifetimePolicy == kTimeout) {
        if (timerId == kRepeatTimer) {
            if (m_playbackMode == kRepeatPlayback ||
                m_playProbability * 32767.0f >
                    static_cast<float>(rand())) {
                g_pSoundManager->PlaySample(
                    m_sound.sampleId, m_sound.volumeScale);
            }

            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kRepeatTimer,
                m_repeatDelayMilliseconds,
                0,
                0);
        } else if (timerId == kLifetimeTimer) {
            delete this;
        }
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - UID00035A vtable covered marker

Exact destination: `by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md`. Applied `91/94`, owner/emitter UID0000DH, reconstructable true, position `60`, `Nested:0`.

Exact Item Summary: `SoundObjectPane primary, EventHandler, and TimerHandler RTTI-vtable views plus compiler adjustors covered by the class declaration.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - UID000387 scalar wrapper blank formal

Exact destination: `by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md`. Applied `91/94`, retained semantic owner UID0000DH, reconstructable false, blank emitter/position, and `Nested:0`.

Exact Item Summary: `Compiler scalar-deleting wrapper for ordinary SoundObjectPane cleanup and optional class-pool return; no handwritten source emitter.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10 - UID0003CB threshold covered marker

Exact destination: `by-memory/0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant.md`. Applied `91/94`, owner/emitter UID0000DH, reconstructable true, position `70`, `Nested:0`.

Exact Item Summary: `Source literal for SoundObjectPane probability-repeat normalization, covered by the class OnTimer source.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11 - UID0003XT typed setter

Exact selected rename: `by-memory/0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane.md`, preserving UID0003XT. Applied `91/93`, owner/emitter UID00009R, reconstructable true, position `70`. This follows the six earlier ObjectPane source methods and precedes the no-release clear in exact address/source order.

Exact Item Summary: `Typed ObjectPane ownership-link replacement for SoundObjectPane, deleting the previous pane before storing the new pointer.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ObjectPane::SetSoundObjectPane(SoundObjectPane *soundObjectPane)
{
    if (m_soundObjectPane != NULL) {
        delete m_soundObjectPane;
    }

    m_soundObjectPane = soundObjectPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12 - UID0003XU typed no-release clear

Exact selected rename: `by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md`, preserving UID0003XU. Applied `90/92`, owner/emitter UID00009R, reconstructable true, position `80`. Raw/no-direct-xref history remains while inline-source liveness is current.

Exact Item Summary: `Typed conditional no-release clear for the ObjectPane SoundObjectPane link, retained out-of-line after equivalent destructor inlining.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ObjectPane::ClearSoundObjectPane()
{
    if (m_soundObjectPane != NULL) {
        m_soundObjectPane = NULL;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 13 - UID0000NW file prose only

Exact destination: `by-file/SoundObjectPane.md`. Raise to `92/92`; add source order `pool/class/constructor/destructor/StartPlayback/OnTimer/vtable-covered/threshold-covered`; preserve no by-file reconstruction metadata.

### Destination 14 - UID00009R ObjectPane class support

Exact destination: `by-class/ObjectPane.md`. Applied `87/90 -> 92/94`, retained owner/emitter UID0000M5 and reconstructable true, and set position `10`. The blank class emitter is replaced by this complete declaration. It preserves the exact `0xf8` Pane base, `0x128` ObjectPane size, primary/EventHandler/TimerHandler views, every established field and exact method child, pure ordinary-destructor contract, concrete empty primary `+0x5c/+0x64` render defaults, implicit alignment, child insertion, and historical aliases. The `SoundObjectPane` forward declaration makes the member and method prototypes legal in `ObjectPane.h`; ObjectPane.cpp includes the complete SoundObjectPane declaration before Destination 11's deleting definition.

Exact Item Summary: `Complete abstract ObjectPane declaration over Pane with exact 0x128 layout, established virtual/nonvirtual method contracts, concrete empty two-stage render defaults, typed SoundObjectPane ownership link, and compiler-generated three-view vtable disposition.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SoundObjectPane;
class GrafPort;
struct MapPoint;

class ObjectPane : public Pane
{
public:
    ObjectPane(unsigned char objectType,
               int objectId,
               int mapX,
               int mapY);
    virtual ~ObjectPane() = 0;

    MapPoint *GetMapPosition(MapPoint *outPosition) const;
    ObjectPane *GetAttachedObject() const;
    void SetSoundObjectPane(SoundObjectPane *soundObjectPane);
    void ClearSoundObjectPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *clipBounds);
    virtual void AttachObject(ObjectPane *attachedObject);
    virtual void DetachObject();
    virtual void ClearOutputRects(RectBounds *firstBounds,
                                  RectBounds *secondBounds);
    virtual void SetObjectData(const RectBounds *objectData);
    virtual RectBounds *GetObjectData(RectBounds *outObjectData) const;
    virtual void RenderFrame(GrafPort *target,
                             const RectBounds *bounds)
    {
    }
    virtual RectBounds *GetEmptyRect(RectBounds *outBounds) const;
    virtual void DrawSpriteFrame(GrafPort *target,
                                 const RectBounds *bounds)
    {
    }
    virtual void SetMapPosition(int mapX, int mapY);

protected:
    unsigned char m_objectType;
    int m_objectId;
    int m_mapX;
    int m_mapY;
    RectBounds m_objectDataRect;
    ObjectPane *m_attachedObject;
    float m_attachmentHeightOffset;
    SoundObjectPane *m_soundObjectPane;
    unsigned char m_transientObjectFlag;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Compile/layout proof: 32-bit compiler alignment inserts three bytes after `m_objectType` and three bytes after `m_transientObjectFlag`; no explicit reserve field is source-authored. The resulting extension is exactly `0x30` bytes over `Pane[0xf8]`, ending at `0x128`. Slot `+0x00` remains the pure virtual destructor contract with UID0003XO's required out-of-line body. Slots `+0x5c/+0x64` are explicitly defined as empty two-argument `void` methods because both exact cells point to `nullsub_18` / `retn 8`; their inline empty bodies are source-safe, permit linker identical-function folding to one address, and preserve directly instantiated SoundObjectPane as concrete.

### Destination 15 - UID0000M5 ObjectPane file support

Exact destination: `by-file/ObjectPane.md`. Prose only: add the complete UID00009R declaration/header route; exact `ObjectPane.h` `Pane.h`/`RectBounds.h` dependency plus `GrafPort`/`SoundObjectPane`/`MapPoint` forward declarations; `ObjectPane.cpp` `ObjectPane.h` then `SoundObjectPane.h` complete-type include order; exact `0x128` layout; pure-destructor/concrete-empty-render/vtable disposition; typed link ownership; setter replacement/delete semantics; no-release clear semantics; inline liveness; and SoundObjectPane destructor relationship. Preserve all existing method/source evidence. Never add by-file reconstruction metadata.

### Destination 16 - UID0003TS live caller support

Exact destination: `by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md`. Retain `86/90` and MapPane ownership; add exact two-record constructor contract, object/map/non-positional origin routes, mode/delay/probability/policy/value parsing, typed ObjectPane setter, and SoundObjectPane source ownership. Keep its own formal body blank.

### Destination 17 - UID0001DN and verify-only ABI support

Exact destination: `by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md`. Verify-only `90/92`, owner NONE, reconstructable false, blank emitter/position/formal. Add no source if already same-or-greater; UID000387 carries the exact compiler disposition.

### Destination 18 - same-or-greater read-only dependencies

Verify UID0004DZ MapPane removal, UID0000F0 TimerHandler, UID0000F1 TimerMgr, UID0000SI global, UID0000NV/UID00028R SoundManager, UID0000PR active MapPane, UID0000TI pool inventory, UID0002B4 aggregate, Pane UID0000A2, PaneLayout UID0001VH, PaneVtables UID0003JA, RectBoundsLayout UID0001VP, ObjectPane exact children other than UID0003XT/UID0003XU, and derived ObjectPane-family vtable children UID00034X/UID00034Y/UID00034Z/UID000350/UID000351/UID000353/UID000354/UID000355/UID000358/UID000359/UID00035A. Their slot cells are read-only comparison evidence for the base contracts, not B002 source destinations. Edit only if callback readback finds a concrete target-specific contradiction; otherwise record `already-present`/`excluded-with-reason`.

### Destination 19 - UID0002SK ObjectPane vtable covered marker

Exact destination: `by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md`. Applied `86/91 -> 91/94`, retained owner/emitter UID00009R and reconstructable true, set position `90`, and retained `Nested:0`. Exact RTTI pointer, 27-cell primary table, 11-cell EventHandler table, two-cell TimerHandler table, six constructor/destructor vptr-store refs, `__purecall` first cells at all three bases `0x00620298/0x00620308/0x00620338`, concrete primary `+0x5c/+0x64` `nullsub_18` defaults, inherited slots, adjusted views, and `0x00620340` successor boundary are preserved. Stale parent-blank/Empty Emitter wording is replaced with compiler-covered disposition.

Exact Item Summary: `Exact ObjectPane primary, EventHandler, and TimerHandler RTTI-vtable views covered by the complete abstract class declaration, concrete empty render defaults, and ordinary method source.`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:00009R][ObjectPane](by-class/ObjectPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: formal source reproduces all mode/policy/timer branches, strict random comparison, count decrement timing, immediate and delayed scheduling, virtual deletion, object-link clear, and no extra checks/cancellation. Destination 14 changes declaration visibility and typing only; it does not alter any established ObjectPane method behavior.
- Period shape: ordinary classes, nested POD records/enums, initialization lists, switches, `NULL`, inherited virtual callback, static pool object, and standard virtual deletion fit the compiler/runtime evidence without decompiler offsets or modern abstractions.
- Naming style: descriptive PascalCase methods/types and `m_` fields follow current project source conventions. Original spelling remains a confidence cap, not a blank-C++ blocker.

## Final Recommendation

- Destinations 1-14 and 19 and the full-detail bounded dispositions in Destinations 15-18 are applied.
- Four children were registered serially as UID0004PV/PW/PX/PY. Logical source positions are pool `0`, class `10`, constructor `20`, destructor `30`, StartPlayback `40`, OnTimer `50`, vtable marker `60`, and threshold marker `70`. Validator hierarchy emits the class root before inserting its children; final physical generated order is class, pool, constructor, destructor, StartPlayback, OnTimer, vtable marker, threshold marker.
- UID00009R was populated and validated before UID0003XT/UID0003XU. Destination 14 retains the pure destructor plus concrete empty `RenderFrame`/`DrawSpriteFrame` defaults. ObjectPane order is class `10`, setter `70`, clear `80`, and vtable-covered marker `90`; all other ObjectPane exact children retain their independent body status.
- UID0001DJ and UID000387 are non-emitting with semantic owner UID0000DH; UID0001DN remains ownerless/non-emitting.
- All compiler-generated switch/padding/vptr/EH/scalar/adjustor/vtable mechanics remain outside handwritten source.
- No separate duplicate report is needed for the callback or ObjectPane helper support.
- Exact original stripped enum/member spellings may be improved only by new symbols/source, but no declaration, type, layout, source-placement, or compile-visibility blocker remains deferred by this report.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md`.
- Applied exact subrange hashes, instruction/CFG counts, table bytes/targets, callers/callees/xrefs, field layout, mode/policy/timer behavior, source/compiler split, class/file ownership, negative evidence, and support relationships from this report.
- Applied `92/94`, semantic owner UID0000DH, reconstructable false, blank emitter/position/formal C++, `Nested:0`, and the non-duplicative semantic-index Item Summary.
- Preserved June 2026 facts as historical evidence and explicitly superseded aggregate emission, probability-at-`+0x144`, `OnTriggerSound`, and unresolved-field blank-C++ conclusions.

## Recommended Support Doc Changes

- UID0000DH: applied complete class declaration/layout/method inventory, score/position, compiler exclusions, and child order.
- UID0000NW: applied complete file role/source order and generated contract as prose only.
- UID0002WN: applied exact declaration, evidence-time zero bytes, wrappers/xrefs, and historical all-`ff` assumption.
- UID00035A: applied complete RTTI/vtable/adjustor relationship and covered marker.
- UID0003CB: applied literal interpretation and covered marker.
- UID000387/UID0001DN: applied compiler-only scalar disposition; UID0001DN was already-present and unchanged.
- UID00009R: applied Destination 14's complete `0x128` abstract class declaration, score/position, all fields/prototypes, concrete empty `RenderFrame`/`DrawSpriteFrame` defaults, forward declarations, implicit padding, child insertion, and historical aliases.
- UID0003XT/UID0003XU: applied typed SoundObjectPane link names, exact bodies, ownership, positions, inline route, and historical aliases; definitions match UID00009R declarations.
- UID0000M5: applied prose-only complete header/source placement, including `Pane.h`/`RectBounds.h` dependencies, `GrafPort`/`SoundObjectPane`/`MapPoint` forward declarations, and `ObjectPane.h` then `SoundObjectPane.h` source include order; no by-file reconstruction metadata was added.
- UID0002SK: applied exact table evidence, the distinction between view-first `__purecall` cells and primary `+0x5c/+0x64` `nullsub_18`, and Destination 19's class-covered marker at position `90`.
- UID0003TS: applied exact caller-side records and argument parsing without taking target ownership.
- Verify-only support named in Destination 18 was read back as same-or-greater and remains unchanged.

## Score And Metadata Recommendation

| Item | Evidence-time / pre-callback | Applied state | Metadata disposition |
| --- | --- | --- | --- |
| UID0001DJ | `86/90`, TRUE, emitter UID0000DH | `92/94`, FALSE | retain semantic owner; blank emitter/position/C++ |
| UID0000DH | `85/89` | `92/94` | retain owner/emitter UID0000NW; position 10 |
| UID0000NW | `85/87` | `92/92` | by-file prose; no reconstruction metadata |
| UID0004PV constructor | absent before callback | `92/94` applied | UID0000DH, TRUE, position 20 |
| UID0004PW destructor | absent before callback | `92/94` applied | UID0000DH, TRUE, position 30 |
| UID0004PX StartPlayback | absent before callback | `93/94` applied | UID0000DH, TRUE, position 40 |
| UID0004PY OnTimer | absent before callback | `93/94` applied | UID0000DH, TRUE, position 50 |
| UID0002WN | `86/92` | `91/94` | retain owner/emitter; position 0 |
| UID00035A | `87/90` | `91/94` | retain owner/emitter; position 60; covered marker |
| UID0003CB | `85/90` | `91/94` | retain owner/emitter; position 70; covered marker |
| UID000387 | `88/92`, TRUE/emitting | `91/94`, FALSE | retain semantic owner; blank emitter/position/C++ |
| UID0003XT | `85/89` generic name | `91/93` typed name/body | owner/emitter UID00009R; position 70 |
| UID0003XU | `85/88`, NONE/FALSE | `90/92`, typed TRUE | owner/emitter UID00009R; position 80; retain no-direct-xref caveat |
| UID00009R | `87/90`, blank class emitter | `92/94` complete declaration | retain owner/emitter UID0000M5; TRUE; position 10 |
| UID0000M5 | `89/88` | `91/92` | prose-only file/header/source route; no reconstruction metadata |
| UID0002SK | `86/91`, blank vtable emitter | `91/94` class-covered | retain owner/emitter UID00009R; TRUE; position 90 |

- Completion rises because all SoundObjectPane source/compiler bytes and the full ObjectPane declaration integration are resolved: exact base size/layout, forward declarations, method prototypes, typed field, abstract destructor, two concrete empty render defaults, complete-type source include, and vtable coverage now have formal destinations.
- Confidence stops at 94 because original private enum/member spellings and header access layout are stripped; behavior and binary contracts are stronger than the remaining spelling uncertainty.
- Score-improvement attempts removed every prior blocker: live callback route, field offsets/types, pool linkage, source owner, typed ObjectPane link, complete branch source, ObjectPane declaration visibility, pure-versus-empty vtable contracts, render-default signatures, and compiler exclusions. Type-catalog search confirmed that only original spelling proof remains unavailable; unrelated blank ObjectPane method bodies remain their exact child scopes and do not make the class declaration partial.

## Open Questions With Attempted Resolution

- Is callback dead because no direct caller exists? No. Vtable cell `0x00620b8c` is a direct durable route and ABI matches TimerHandler.
- Is `+0x144` probability? No. Caller parse and adjusted callback access prove repeat delay at `+0x144` and probability at `+0x148`.
- Is ObjectPane `+0x120` a generic image state? No. Both setter callers, virtual deletion, and destruction clear prove SoundObjectPane pointer semantics.
- Is raw clear dead? No defensible dead-code conclusion remains. It has no direct xref, but its exact operation is inlined into destruction and its retained body is consistent with an inline header method.
- Can UID0003XT/UID0003XU compile against ObjectPane? Yes. The evidence-time blank class could not; applied Destination 14 supplies `class SoundObjectPane;`, typed storage, and matching declarations. The applied source order is `ObjectPane.h` followed by `SoundObjectPane.h` in ObjectPane.cpp before the deleting setter definition.
- Is ObjectPane declaration complete or a narrow shell? Complete for the established class evidence. It declares every current ObjectPane field and known method child, preserves inherited Pane facets, exact size/alignment, the pure ordinary destructor, concrete empty primary `+0x5c/+0x64` defaults, child insertion, and compiler vtable route. It does not invent bodies for exact children that remain independently blank.
- Are ObjectPane `+0x5c/+0x64` pure or unresolved? No. Both exact cells point to `nullsub_18` / `retn 8`; MapPane passes `GrafPort *` and `RectBounds *`; LivingObjectPane's accepted source children establish the `RenderFrame`/`DrawSpriteFrame` names. Concrete empty `void` defaults are the only source shape consistent with directly constructing SoundObjectPane and the exact base vtable.
- Does ObjectPane require handwritten vtable or adjusted facets? No. UID0002SK's 27/11/2 cells and six vptr-store refs are regenerated by Destination 14 and represented by Destination 19's covered marker.
- Does UID0001DJ emit? No. Exact children are required and aggregate emission duplicates them/table support.
- Should the scalar wrapper emit? No. Delete flags, adjustors, vptr stores, base teardown, and pool return are compiler-generated from ordinary source.
- Are original names exact? No symbols prove spelling. The chosen names are the highest-probability descriptive source form and the score cap records this. No behavior/type/source blocker remains unresolved.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected read-only rows: by-memory UID0001DJ, UID0001DN, UID00035A, UID0002WN, UID00020R, UID00020S, and UID0002SK; absence of UID000387, UID0003CB, UID0003XT, UID0003XU, and exact UID0003XN-UID0003Y0 rows; by-class UID0000DH and UID00009R; by-file UID0000NW and UID0000M5.
- Manual coverage is supervisor-owned. B002 must not edit it, and generated validator coverage does not satisfy these replacements/additions.

File: `by-class/-coverage-report.md`. Replace the current UID0000DH row with:

```text
- [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md) : reconstructable : 92% : very-strong : Complete 0x158 SoundObjectPane declaration with ObjectPane inheritance, inherited EventHandler/TimerHandler views, exact descriptor/origin/mode/delay/probability/policy/count layout, constructor/destructor/StartPlayback/OnTimer child order, typed ObjectPane sound-link lifecycle, PoolAllocator source declaration, vtable/constant covered dispositions, and compiler scalar/adjustor/table exclusions.
```

In the same file, replace the current UID00009R row with:

```text
- [UID:00009R][ObjectPane](by-class/ObjectPane.md) : reconstructable : 92% : very-strong : Complete abstract 0x128 ObjectPane declaration over Pane with exact object type/id, map coordinates, RectBounds data, attached-object/height state, typed SoundObjectPane ownership link, transient flag, established method prototypes, pure ordinary destructor, concrete empty RenderFrame/DrawSpriteFrame defaults at primary +0x5c/+0x64, implicit alignment, three-view compiler vtable coverage, and exact child-only method-body ownership.
```

File: `by-file/-coverage-report.md`. Replace the current UID0000NW row with:

```text
- [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md) : reconstructable : 92% : very-strong : NexusTK/map/SoundObjectPane.cpp source root for the exact pool/class/constructor/destructor/StartPlayback/OnTimer sequence; preserves MapPane caller, SoundManager/TimerMgr dependency, typed ObjectPane sound-link, random-repeat/lifetime behavior, and compiler-only scalar/adjustor/vtable/table exclusions without by-file reconstruction metadata.
```

In the same file, replace the current UID0000M5 row with:

```text
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ObjectPane.cpp source root for the complete 0x128 ObjectPane declaration and exact method children; ObjectPane.h includes Pane/RectBounds dependencies and forward-declares GrafPort/SoundObjectPane/MapPoint, ObjectPane.cpp includes ObjectPane.h then SoundObjectPane.h before the deleting setter, concrete empty RenderFrame/DrawSpriteFrame defaults preserve primary +0x5c/+0x64, and compiler-only primary/EventHandler/TimerHandler vtables remain class-covered without by-file reconstruction metadata.
```

File: `by-memory/-coverage-report.md`. Replace UID0001DJ and insert its exact children immediately beneath it:

```text
    - [UID:0001DJ][0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md) 0x0053ca20-0x0053ce3c | non-emitting semantic split index | SoundObjectPaneCore : not_reconstructable : 92% : very-strong : Exact SoundObjectPane constructor/destructor/StartPlayback/OnTimer inventory with complete bytes/hashes/CFG, 0x158 typed layout, MapPane callers, SoundManager/TimerMgr behavior, typed ObjectPane sound link, two alignment spans, five-entry compiler switch table, and child-only source emission through UID0000DH.
        - [UID:0004PV][0x0053ca20-0x0053cab4.SoundObjectPaneConstructor](by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md) 0x0053ca20-0x0053cab4 | constructor | SoundObjectPaneConstructor : reconstructable : 92% : very-strong : Exact 148-byte constructor with ObjectPane type 11/id 0 base call, three compiler vptr views, two copied 12-byte records, mode/delay/probability/policy/value fields, nine explicit arguments, six live/retained caller sites, and source-ready initialization-list body.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053cab4-0x0053cac0 | padding | SoundObjectPane constructor to destructor alignment : ignored : 100% : strong : Exact twelve 0xcc bytes.
        - [UID:0004PW][0x0053cac0-0x0053cb48.SoundObjectPaneDestructor](by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md) 0x0053cac0-0x0053cb48 | ordinary destructor | SoundObjectPaneDestructor : reconstructable : 92% : very-strong : Exact typed object-link clear, active MapPane removal, automatic ObjectPane/TimerHandler teardown, no explicit timer cancellation, and compiler vptr/EH exclusion.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053cb48-0x0053cb50 | padding | SoundObjectPane destructor to StartPlayback alignment : ignored : 100% : strong : Exact eight 0xcc bytes.
        - [UID:0004PX][0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback](by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md) 0x0053cb50-0x0053cc5c | method | SoundObjectPaneStartPlayback : reconstructable : 93% : very-strong : Complete modes 0-4 startup, immediate playback/deletion, persistent/count/timeout policy, timer ids 0/1, seconds-to-milliseconds timeout, repeat-count initialization, no added null checks, and source switch regeneration.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053cc5c-0x0053cc70 | compiler switch table | SoundObjectPane StartPlayback five-entry switch support : ignored : 100% : strong : Exact targets 0x0053cb6a, 0x0053cbc9, 0x0053cb73, 0x0053cc05, 0x0053cc05; regenerated by source switch and never hand-emitted.
        - [UID:0004PY][0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer](by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md) 0x0053cc70-0x0053ce3c | virtual timer callback | SoundObjectPaneOnTimer : reconstructable : 93% : very-strong : TimerHandler +0xa4 vtable callback with exact mode/policy/timer branches, deterministic and probability repeats, strict probability*32767 > float(rand()) test, count consumption on failed random play, reschedule/delete behavior, and unconditional true return.
```

Replace UID0001DN and add UID000387 beneath it:

```text
    - [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md) 0x0053d660-0x0053d7bd | mixed compiler-destructor split index | SoundAndStaticObjectPaneDestructors : not_reconstructable : 90% : very-strong : Non-emitting mixed-owner index over exact SoundObjectPane and StaticObjectPane scalar wrappers, adjustors, alignment, vtable references, delete flags, base cleanup, and pool return; ordinary class destructors alone carry handwritten source.
        - [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md) 0x0053d660-0x0053d739 | compiler scalar deleting wrapper | SoundObjectPaneScalarDeletingDestructor : not_reconstructable : 91% : very-strong : Compiler-only wrapper reproducing ordinary destructor cleanup, three vptr stores, delete-flag/size-guard behavior, ObjectPane teardown, and optional g_soundObjectPanePool return; semantic class owner UID0000DH, blank emitter/position/C++.
```

Replace UID00035A with:

```text
        - [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md) 0x00620ae4-0x00620b90 | vtable-data | SoundObjectPaneVtableData : reconstructable : 91% : very-strong : Exact primary/EventHandler/TimerHandler RTTI-vtable views, constructor/destructor/scalar vptr refs, +0xa0/+0xa4 deleting adjustors, OnTimer slot 0x00620b8c, and class-covered compiler ABI emission through UID0000DH.
```

Add UID0003CB beneath UID0002YT's exact numeric-constant children:

```text
            - [UID:0003CB][0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant](by-memory/0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant.md) 0x00620c6c-0x00620c70 | source literal/constant data | SoundObjectPaneRandomThresholdConstant : reconstructable : 91% : very-strong : Exact 0x46fffe00 float 32767.0f with two OnTimer probability xrefs, strict comparison semantics, OptionPane successor boundary, and class-covered source-literal emission through UID0000DH.
```

Replace UID0002WN with:

```text
        - [UID:0002WN][0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage](by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md) 0x0069b8e4-0x0069b90c | static PoolAllocator storage | SoundObjectPanePoolStaticStorage : reconstructable : 91% : very-strong : Exact evidence-time zero-initialized 0x28-byte storage, module-static g_soundObjectPanePool source declaration with block size 0x158 and chunk count 0x20, eight init/allocation/unwind/scalar/free/cleanup xrefs, wrapper boundaries, class ownership, and historicalized all-ff observation.
```

Add UID0003XT/UID0003XU beneath UID0001D5 in address order, with UID-preserving selected paths:

```text
        - [UID:0003XT][0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane](by-memory/0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane.md) 0x005376d0-0x005376f4 | method | ObjectPaneSetSoundObjectPane : reconstructable : 91% : very-strong : Typed ObjectPane SoundObjectPane-pointer setter with exactly two construction-flow callers, virtual deletion of the previous pane, replacement store at +0x120, and source-ready body; old owned-image-state name retained only as historical alias.
        - [UID:0003XU][0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw](by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md) 0x00537700-0x00537714 | inline/out-of-line method body | ObjectPaneClearSoundObjectPaneRaw : reconstructable : 90% : very-strong : Typed conditional no-release clear of ObjectPane +0x120, no direct xref retained as negative evidence, and source liveness proven by the exact inlined SoundObjectPane ordinary/scalar destructor operation.
```

Replace UID0002SK with:

```text
        - [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md) 0x00620294-0x00620340 | vtable-data | ObjectPaneVtableData : reconstructable : 91% : very-strong : Exact ObjectPane RTTI pointer, 27-cell primary table, 11-cell EventHandler table, two-cell TimerHandler table, six constructor/destructor vptr-store refs, __purecall first cells at all three bases, concrete primary +0x5c/+0x64 nullsub_18 defaults, inherited cells, adjusted views, and StaticObjectPane successor boundary; compiler emission is covered by complete UID00009R source.
```

UID00020R/UID00020S rows remain unchanged in this bounded repair: direct readback confirms that their exact behavior/range/vtable evidence is current, while their descriptive source names and independent body formals remain separate from the UID00009R declaration blocker.

## Follow-Up Actions

- B002 callback work, scoped validators, generated readback, and lease release are complete; no B002 implementation item remains pending.
- Manual coverage text remains read-only and supervisor-owned. Current/future supervisor validation, execution, report move/archive, report count, and artifact path are external state and are not asserted or directed here.
- A-agent actions: none.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong at the applied values.
- Remaining uncertainty: exact stripped private enum/member spelling and whether the compiler retained the ObjectPane clear as an inline COMDAT versus another equivalent header form. ObjectPane inheritance, size, fields, method declarations, abstract-destructor contract, typed ownership, complete-type source include, and vtable generation are resolved; the remaining spelling uncertainty changes none of them.

## Validator Results

- Common scoped command shape, run from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. New child pages were validated serially so UID assignment completed before the next dependent edit. The final authorized command added `--wait-generated` for `by-class/SoundObjectPane.md`.

| Command ID | Timestamp (America/New_York) | Ordinary destination | Result |
| --- | --- | --- | --- |
| `000000011633` | `2026-07-14T14:12:15-04:00` | `by-class/ObjectPane.md` initial complete declaration | exit `0`, `ok:1` |
| `000000011634` | `2026-07-14T14:12:58-04:00` | `by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md` | exit `0`, `ok:1` |
| `000000011638` | `2026-07-14T14:13:47-04:00` | `by-file/ObjectPane.md` initial prose pass | exit `0`, `ok:1` |
| `000000011648` | `2026-07-14T14:15:15-04:00` | constructor registration, assigned UID0004PV | exit `0`, `ok:1` |
| `000000011655` | `2026-07-14T14:15:59-04:00` | destructor registration, assigned UID0004PW | exit `0`, `ok:1` |
| `000000011656` | `2026-07-14T14:17:04-04:00` | StartPlayback registration, assigned UID0004PX | exit `0`, `ok:1` |
| `000000011657` | `2026-07-14T14:18:05-04:00` | OnTimer registration, assigned UID0004PY | exit `0`, `ok:1` |
| `000000011661` | `2026-07-14T14:20:06-04:00` | UID0001DJ aggregate | exit `0`, `ok:1` |
| `000000011664` | `2026-07-14T14:21:26-04:00` | `by-class/SoundObjectPane.md` | exit `0`, `ok:1` |
| `000000011665` | `2026-07-14T14:22:08-04:00` | UID0002WN pool storage | exit `0`, `ok:1` |
| `000000011666` | `2026-07-14T14:23:09-04:00` | UID00035A vtable data | exit `0`, `ok:1` |
| `000000011667` | `2026-07-14T14:23:45-04:00` | UID0003CB threshold constant | exit `0`, `ok:1` |
| `000000011668` | `2026-07-14T14:24:53-04:00` | UID000387 scalar wrapper | exit `0`, `ok:1` |
| `000000011669` | `2026-07-14T14:25:39-04:00` | `by-file/SoundObjectPane.md` | exit `0`, `ok:1` |
| `000000011670` | `2026-07-14T14:26:56-04:00` | UID0003XT selected rename/setter | exit `0`, `ok:1` |
| `000000011671` | `2026-07-14T14:28:33-04:00` | UID0003XU selected rename/clear | exit `0`, `ok:1` |
| `000000011672` | `2026-07-14T14:29:05-04:00` | UID0003TS MapPane caller support | exit `0`, `ok:1` |
| `000000011673` | `2026-07-14T14:30:07-04:00` | UID0001D5 ObjectPane aggregate support | exit `0`, `ok:1` |
| `000000011678` | `2026-07-14T14:34:48-04:00` | `by-file/ObjectPane.md` authoritative post-recovery rename-link pass | exit `0`, `ok:1` |
| `000000011681` | `2026-07-14T14:35:20-04:00` | `by-class/ObjectPane.md` authoritative historical-link pass | exit `0`, `ok:1` |
| `000000011683` | `2026-07-14T14:36:12-04:00` | UID0001DJ authoritative stale-callback wording pass | exit `0`, `ok:1` |
| `000000011685` | `2026-07-14T14:36:45-04:00` | final `by-class/SoundObjectPane.md --wait-generated` | exit `0`, `ok:1`; generated complete |

- Warning disposition: scoped validators reported legacy `missing_ref_uid` warnings for exact child references not yet present in `validator.ini` during registration order; UID0003XT's pass similarly preceded UID0003XU registration. Later serial validators resolved the targeted routes. Final broad warnings (`autogen_children_marker_missing`, `autogen_emitter_has_no_code`, and fallback insertion) concern unrelated ordinary pages and produced no targeted failure.
- Validator side effects: validator-owned UID registry/reference/statistics and generated/auto-coverage refreshes only. B002 made no manual generated, coverage, tracker, audit, supervisor, queue, lock, or validator-state edit.
- MCP outage handling: work stopped when session `9df6e9a0` became unreachable. No fallback conclusion, ordinary edit, or validator was performed during the pause. The interrupted ObjectPane-file validation was superseded by authoritative command `000000011678` after fresh `idb_list`, healthy `server_health`, and bounded target bytes on evidence-time database `6b2e78f3`.
- Authorized waited command `000000011685` completed the B002-stage generated refresh. Its immediate generated snapshots were SoundObjectPane SHA256 `CAA75CC37E8CEC04E32C648AE16E6E1DA347D73F745FB25E55BF403D099B509F` and ObjectPane SHA256 `7D250CD733E831760B1E30A2366522720CBE83A6070C8D364A328D1A3BCF6FD6`. A later validator-owned foreground refresh identified by generated header command `000000011692` changed only generated framing/newline state, not targeted source content; B002 did not run or edit that state.
- Current read-only generated `auto-generated/NexusTK/map/SoundObjectPane.cpp`: SHA256 `D1D45F7B094C7469BF2A212DF38F556E78F4692845AE6612A209F6B64167FC2A`, 268 lines, exactly one pool declaration, one complete class, one constructor, one destructor, one StartPlayback, and one OnTimer. Physical order is class line 8, pool 84, constructor 87, destructor 109, StartPlayback 120, OnTimer 183, vtable marker 265, threshold marker 268; the class-root-first physical order is validator hierarchy, while logical positions remain `0/10/20/30/40/50/60/70`. Counts are zero for UID0001DJ Empty Emitter Marker, duplicate typed ObjectPane link bodies, and handwritten scalar/adjustor/vtable/table ABI source.
- Current read-only generated `auto-generated/NexusTK/map/ObjectPane.cpp`: SHA256 `B5F777E156E5F1F00C711FF1D63F26702744222C7D4C17DF57F1365B3A37589E`, 82 lines, exactly one complete ObjectPane class, one concrete inline empty RenderFrame default, one concrete inline empty DrawSpriteFrame default, one typed setter, one typed clear, and one UID0002SK covered marker. Order is forward declaration line 8, class line 12, pure destructor declaration line 19, RenderFrame line 36, DrawSpriteFrame line 41, setter line 60, clear line 70, covered marker line 78. UID0001DJ, UID00009R, and UID0002SK Empty Emitter Marker counts are zero; scalar/adjustor/table text counts are zero. Unrelated verify-only UID00020R/UID00020S markers remain outside this callback.
- `by-file/SoundObjectPane.md` and `by-file/ObjectPane.md` contain no `RECONSTRUCTION_CPP` metadata or managed block.

## Changed Files

- Report modified additively: `tools/leaser/Agents/Agent-B002/research/0001DJ-SoundObjectPaneCore-empty-emitter-source-quality.md`.
- Changed ordinary pages: `by-class/ObjectPane.md`, `by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md`, `by-file/ObjectPane.md`, `by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md`, `by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md`, `by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md`, `by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md`, `by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md`, `by-class/SoundObjectPane.md`, `by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md`, `by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md`, `by-memory/0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant.md`, `by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md`, `by-file/SoundObjectPane.md`, `by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md`, and `by-memory/0x005372d0-0x005378fa.ObjectPane.md`.
- UID-preserving renames: `by-memory/0x005376d0-0x005376f4.ObjectPaneSetOwnedObjectImageState.md` to `by-memory/0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane.md` (UID0003XT), and `by-memory/0x00537700-0x00537714.ObjectPaneClearOwnedObjectImageNoReleaseRaw.md` to `by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md` (UID0003XU).
- New children: UID0004PV `by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md`; UID0004PW `by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md`; UID0004PX `by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md`; UID0004PY `by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md`.
- Verify-only Destination 18 pages not listed above were read-only and unchanged. Manual coverage and generated files were not manually edited.
- Leases: each ordinary page was leased only for its immediate edit/validator and released immediately. No B002 lease remains.
- Report execution/lifecycle/move/archive: not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact report SHA `B089568D0A00FB2D28E082AF3424A1343F26E6666FAF4CB2624453807A6696F0` before implementation.
- [x] Target/support destinations 1-19 identified exactly, with verify-only exclusions honored and no by-file reconstruction metadata.
- [x] Current target state and actual evidence checked recorded, including post-MCP-resume target revalidation and fresh ObjectPane reanalysis.
- [x] Initial Claim And Incorporation Ledger used only permitted Action values and exact `proposed` report-only states; final ledger now uses legal terminal states.
- [x] Metadata/score changes fixed by the exact Score And Metadata Recommendation table.
- [x] Score-limiting blockers researched to resolution; only original stripped spelling remains as a confidence cap.
- [x] Owner/emitter/reconstructable dispositions and exact child routes fixed.
- [x] Four new-child routes and two UID-preserving ObjectPane helper renames fixed.
- [x] Source placement, range/split/padding/reclassification, and rename/type recommendations fixed.
- [x] Exact formal C++ Destinations 1-12, 14, and 19 fixed at source-text level.
- [x] UID00009R complete declaration, exact `0x128` layout, pure destructor, concrete empty defaults, forward declarations, typed `+0x120` field, established prototypes, and `[[CHILDREN]]` confirmed.
- [x] UID0002SK covered-vtable disposition and `91/94` score fixed; no handwritten ABI table planned.
- [x] Third-party import confirmed not applicable; no import directive used.
- [x] Exact target/support facts specified at report-level detail without compression.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 artifacts rejected as stale provenance.
- [x] Open questions closed or bounded with evidence-backed spelling uncertainty.
- [x] Scoped validator requirement and short-lease/release protocol specified.
- [x] Final waited generated verification and exact supervisor-owned manual coverage text specified.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] C01-C30 updated to legal final states with separate destination proof.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or excluded with exact reason.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions reconciled against callback-time current pages.
- [x] One scoped validator run and recorded per changed ordinary page; authoritative reruns recorded where interruption or final link synchronization required them; each lease released immediately.
- [x] Waited generated refresh verifies one complete SoundObjectPane class, one pool, one constructor/destructor/StartPlayback/OnTimer, one complete ObjectPane declaration with concrete empty `RenderFrame`/`DrawSpriteFrame` defaults before exactly one typed setter and one typed clear, zero target/class/vtable Empty Emitter markers, zero duplicate scalar/adjustor/vtable/table source, and no undeclared or duplicate ObjectPane link body.
- [x] Manual coverage remains unedited by B002 and exact supervisor text remains synchronized.
- [x] No unapplied accepted item or exact blocker remains in B002 scope.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000011750","destination_path":"executed-b-agent-research/B002/0001DJ-SoundObjectPaneCore-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001DJ-SoundObjectPaneCore-empty-emitter-source-quality.md","timestamp":"2026-07-14T15:30:41-04:00","uid":"0001DJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
