** TARGET-REPORT-UID:0003PK **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003PK RainingLayerPane DrawOnTarget Empty-Emitter Source Quality


## Finalized Report / Current Recommendation

- Current recommendation: accepted and implemented for C3PK-01 through C3PK-26. [UID:0003PK] now carries behavior-complete `void RainingLayerPane::DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)` C++ and the six ordinary target/support pages contain the accepted detail without duplicate support-page method bodies. The supervisor independently passed Gate 2A for C3PK-01 through C3PK-26 and completed C3PK-27 Gate 2B as `APPLIED_VERIFIED`.
- Final disposition: `CANONICAL_OWNER:0000BJ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000BJ` remain unchanged; target score is `92/94`, the current route remains [UID:0000BJ] -> [UID:0000P8] -> `NexusTK/map/WeatherLayerPane.cpp`, and the post-callback generated readback under command `000000017040` contains exactly one target body and zero target empty markers.
- Reconciliation disposition: Gate 2A implementation verification and Gate 2B C3PK-27 IDA closure are completed supervisor actions. At this B005 reconciliation checkpoint, C3PK-28 manual coverage and supervisor lifecycle execution had not yet been completed. Because this report revision incorporates the final supervisor evidence, it requires a fresh exact-artifact Gate 1 and Gate 2 continuity audit before those remaining actions. Any eventual execution/archive state is authoritative only in the validator-owned footer/registry, not in this body checkpoint.
- Confidence: very strong for exact runtime behavior, signature, object layout, table layout, virtual dispatch, and selected emitter route; strong for human source spelling and the selected one-file Weather source-family placement.

## Supporting Research

- Fresh live IDA MCP research used database session `supervisor_gate2b_0002OT_20260723` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, image base `0x00400000`. A final health read returned `status:ok`, active worker PID `3368`, Hex-Rays ready, strings ready, and no analysis task running.
- The target was rechecked directly rather than promoted from the earlier [UID:0003PJ] sibling report. Existing reports for [UID:0001NZ], [UID:0001ON], [UID:0002Z8], and [UID:0003PJ] were treated as leads and independently reconciled against current IDA facts.
- Historical terminology calling this a minimap draw or source method `DrawRainOnTarget` is superseded. The machine evidence proves a general supplied-target virtual override; the base declaration and indirect caller prove the source contract `DrawOnTarget`.
- Historical Wave2/Wave3 workflow mentions were found in older documentation and ignored as stale, as required by the current project skill.
- Historical report-only state: the exact Gate 1 artifact SHA `AC91DD8FD2B2A3B239EBF2A29C52E886DB04CD20CE71B050235600D2686CB375` contained research only and passed supervisor Gate 1. During the accepted callback B005 implemented C3PK-01 through C3PK-26, ran serial scoped validators, and reread generated output. B005 did not mutate IDA, edit manual coverage/generated files, or run/probe any lifecycle command.

## Target

- Target UID: `0003PK`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0003PK] `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md`, the exact 951-byte RainingLayerPane target-port render override.
- Target path: `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `by-memory -> Not-Covered Files - Reconstructable`, assignment-time `86/88`, zero direct/additional/total report coverage; generated `NexusTK/map/WeatherLayerPane.cpp` showed an empty-emitter marker.
- Current supervisor classification: reconstructable source-bearing by-memory child with direct class owner [UID:0000BJ].
- Assignment-time scores and parent state: target `86/88`, owner/emitter `0000BJ`, reconstructable true, blank formal C++; [UID:0000BJ] routed through [UID:0000P8]. Current callback state is target `92/94` with behavior-complete managed C++ and unchanged routing.

## Current Target State

- Current target metadata is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000BJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BJ`, and blank optional position. Ownership/routing was preserved exactly.
- Current formal state uses a blank inline metadata value plus the accepted complete multiline `RainingLayerPane::DrawOnTarget` block. The first callback validator exposed `autogen_inline_ignored` when both inline and multiline values were populated; command `000000017029` cleared that error after adopting the established managed-block shape without changing one line of method C++.
- Post-callback generated readback `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, command `000000017040`, refreshed `2026-07-24T01:22:25-04:00`, handoff-observed SHA256 `A6559F06F5171071F79FD587CE3CF9A2BF73BCEA31FE26AA3882B7F5A17565EA`, contains the exact target block once, one UID0003PK marker, and zero target empty markers. The earlier command `000000017030`/SHA `9E45C70A...1C78` remains the immediate UID0003PK callback checkpoint. This shared generated file may receive later unrelated validator refreshes; those do not invalidate this timestamped readback if the UID0003PK counts/body remain intact.
- All assignment-time GrafPort/helper, field, table, full-control-flow, source-signature, clipping, naming, and source-placement blockers are resolved and incorporated. The page title/path retains `DrawRainOnTarget` only as a stable historical documentation identifier; source prose/formal uses `DrawOnTarget`.
- Related docs checked: [UID:0003PI], [UID:0003PJ], [UID:0001ON], [UID:0001NZ], [UID:0002Z8], [UID:0000BJ], [UID:0000P8], [UID:0000MY], Pane/Layer virtual-contract pages, MapPane and active-map singleton pages, generated WeatherLayerPane output, generated memory coverage, research tracker, and current manual coverage reports.
- Artifact/lifecycle checkpoint: supervisor Gate 1 passed the exact pre-callback artifact; B005 completed the accepted ordinary-document callback; supervisor independently passed Gate 2A for C3PK-01 through C3PK-26 and completed C3PK-27 Gate 2B with applied/readback/save evidence. At the time of this B005 reconciliation, C3PK-28 and supervisor lifecycle execution were not yet completed, and the changed report revision required fresh exact-artifact Gate 1 and Gate 2 continuity audits. B005 never performs report execution; the validator-owned history footer/registry is authoritative for lifecycle truth after any later supervisor action.

## Executive Recommendation

- Keep direct ownership on [UID:0000BJ] `RainingLayerPane`; the primary vtable cell `0x00631230`, Rain constructor stores, exact Rain-only target arrays, and concrete `this` layout all identify a class method.
- Keep the current source route [UID:0003PK] -> [UID:0000BJ] -> [UID:0000P8] -> `NexusTK/map/WeatherLayerPane.cpp`. A dedicated historical `RainingLayerPane.cpp` remains plausible but has no PDB/source-path proof and must not displace the current contiguous source-family route.
- Implemented: the complete destination-ready method formal is present only on the target; vtable data, rain arrays, fake support declarations, and class/file method-body duplication remain excluded.
- Implemented: target is `92/94`; accepted support scores are UID0000BJ `91/93`, UID0000P8 `92/93`, UID0001NZ `89/92`, UID0002Z8 `89/93`, and UID0000MY unchanged `89/91`.
- The target has no remaining behavior or final-C++ blocker. Residual uncertainty concerns original lexical names and original physical file split, so it caps confidence below 95 rather than keeping code blank.

## Supervisor Active Recheck

- The original triggering instruction was exhaustive report-only research; supervisor then accepted exact report SHA `AC91DD8F...CB375` and authorized ordinary-document implementation of C3PK-01 through C3PK-26 only.
- No range split or child creation is required: `0x005c1810-0x005c1bc7` is one unique modeled function bounded by compiler padding.
- The only declared target is source-bearing and now has the accepted exact signature, behavior model, formal C++, metadata, support synchronization, and generated route implemented. Supervisor Gate 2A passed C3PK-01 through C3PK-26, and the former IDA Gate 2B handoff is now supervisor `APPLIED_VERIFIED` closure for C3PK-27. Only the exact C3PK-28 manual coverage payload remained unapplied at this reconciliation checkpoint.
- No active B001-B005 goal/report or lease duplicated this target at assignment time.

## Inference Research Guidance Check

- Direct IDA facts were separated from documentation facts and source inference. Bytes, bounds, signed loads, loop counts, constants, xrefs, calls, vtable cell, stack cleanup, and ignored parameters are binary facts.
- `DrawOnTarget`, `RainingLayerPane`, `GrafPort`, `RectBounds`, Rain field names, target-array names, callbacks, and current source-family placement are documentation/type evidence corroborated by RTTI, current local types, the base virtual contract, and related accepted pages.
- `rainColor` and loop variable spelling are source-shape inferences. They are human C++03 names chosen to match nearby project style and are not claimed as original-symbol proof.
- Existing assumptions treated as uncertain and rechecked: minimap specificity, the `DrawRainOnTarget` source name, the stale IDA `int,int` prototype, whether rectangle parameters drive local clipping, whether target arrays alias main arrays, whether frame state changes locally, and whether a dedicated physical source file is required.
- Wave2/Wave3 mentions were ignored as stale and supplied no evidence or workflow constraint.

## Heuristic / Inference Reanalysis And Validation

- Method identity: `DrawOnTarget` is preferred over `DrawRainOnTarget`. The base virtual at `0x0041d680` is currently named and typed `Pane_DrawOnTarget(Pane *, GrafPort *, const RectBounds *, const RectBounds *)`; `Layer_RenderRecursive` dispatches vtable slot `+0x10` with exactly those arguments. `DrawRainOnTarget` remains only a descriptive documentation filename.
- Return type: `void` is preferred over a decompiler-inferred integer. The exact base contract is void, the target ends with `retn 0Ch`, and no target path constructs a return value.
- Rectangle argument types: two `const RectBounds *` parameters are proven. The target's current `int,int` IDA prototype is stale, while the caller constructs two `RectBounds` locals and pushes their addresses.
- Unused rectangle parameters: intentional override behavior, not missing analysis. `Layer_RenderRecursive` sets the target clip before the virtual call; [UID:0003PK] never reads either pointer and performs no local clip operation.
- Target surface: the first explicit argument is a supplied `GrafPort *`. All movement/color calls use it as receiver, and all line/pixel callbacks receive it as their first argument.
- Rain state: `m_currentFrame` is the inherited signed byte at `+0xf8`; constructor evidence sets `m_frameCount=3` and `m_timerInterval=120`. The method repeatedly reloads the frame and does not advance or randomize it.
- Rain records: `RainStreak` is three signed shorts and `RainSplash` two signed shorts. Every field load is signed; unsigned or packed-byte alternatives are rejected.
- Array identity: the method exclusively consumes `s_targetRainStreaks[3][24]`, `s_targetRainSmallSplashes[3][7]`, and `s_targetRainLargeSplashes[3][7]`. Byte identity with main-view arrays is not source aliasing; distinct addresses and exclusive consumers require distinct source objects.
- Draw behavior: exactly 18 streak iterations, 7 small-splash iterations with two pixels each, and 7 large-splash iterations with four pixels each. Six zero-filled streak records per frame remain explicit table capacity and are not looped over.
- Coordinate arithmetic: preserve integer multiplication/division order and truncation exactly. Algebraic simplification, floating point, precomputed scale constants, or reordered division could alter negative-coordinate rounding and are rejected.
- Gate behavior: direct dereference of `g_activeMapPane->m_waitingForLocalPlayerStatus`; nonzero returns before color setup. A defensive null check would change behavior and is rejected.
- Color and blend: `SetDrawColor(143)` occurs once after the gate; decimal `143` equals hexadecimal `0x8f` (Verified with int_convert.py), and `143` is also passed to every pixel callback. There is no blend-mode mutation, background fill, color restore, or clip restore.
- Callback source form: accepted `g_pfnDrawLineDelta` and `g_pfnDrawPixel` typed callback names are used rather than `dword_69B3E4`, `dword_69B3E0`, raw vtable slots, or casts.
- Source placement: contiguous Weather/Rain code, shared data, and current emitter infrastructure support [UID:0000P8]. Dedicated [UID:0000MY] remains historical evidence, not a current reroute.
- Rejected generated form: decompiler temporaries, offset casts, local fake class declarations, IDA names, raw callback calls, hand-authored vtables, and duplicated support tables would look reverse-engineered and are not acceptable source reconstruction.
- All assignment-time score blockers were actively researched. None remains sufficient to block formal C++ or a score increase.

## Evidence Standards Used

- Highest-weight evidence: live IDA MCP bytes, disassembly/decompilation, exact function/range lookup, xrefs, signature uniqueness, pointer scan, vtable slot, current local types, and the indirect virtual caller.
- Corroborating evidence: accepted by-memory, by-class, by-file, by-type, and by-global documentation; earlier executed reports; generated memory/source output; research tracker; manual coverage rows.
- Negative evidence: no ordinary direct caller, no second byte/signature hit, no extra VA/RVA pointer route, no reads of bounds parameters, no random/state update, no local clipping, no main-array xrefs, and no PDB/source-path proof of a dedicated file.
- The evidence is strong enough for exact runtime reconstruction because all branches, loops, constants, calls, data objects, and ABI parameters are accounted for. Original variable spelling and physical file split remain inferred and keep the score below final-audit territory.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks: `idb_list`, `server_health`, function lookup/profile/analysis, decompile/disassembly, xrefs, byte reads, signature generation/search, VA/RVA pointer searches, adjacent bytes/functions, local type queries, base virtual, and `Layer_RenderRecursive` dispatch.
- Integer-base verification: from `source-3/project-documentation`, exact command `python .\tools\int_convert.py 143 --single` returned `{"input": "143", "result": {"decimal": "143", "hexadecimal": "0x8f", "bytes": "8f 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", "ascii": null, "binary": "0b10001111"}, "error": null}`; therefore decimal `143` is hexadecimal `0x8f` (Verified with int_convert.py).
- Documentation checked: target, Rain constructor and OnPaint, Rain tables, Rain vtable, Weather/Rain aggregate, Rain class, current and historical source-family pages, Pane and Layer contracts, active MapPane state, callback/type documentation, generated WeatherLayerPane.cpp, generated memory coverage, research tracker, and manual coverage rows.
- Negative checks: target start/end and vtable-cell routes, target/main array separation, unused rectangle parameters, absence of clip/fill/blend/restore/random/state writes, absence of null guard, and successor-boundary padding.
- Historical report-only boundary: IDA mutations, validators, generated refresh, coverage edits, ordinary documentation edits, build/codegen comparison, and lifecycle commands were intentionally skipped before Gate 1. After Gate 1 acceptance, B005 edited only the six authorized ordinary documents, ran their serial scoped validators, and independently reread the destinations and generated output. IDA mutation, manual coverage edits, report execution, and build/codegen comparison remain unperformed by B005.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3PK-01 | 0003PK | Exact function range is `0x005c1810-0x005c1bc7`, 951 bytes. | Exact | IDA lookup, bytes, adjacent padding | Target Status/Evidence | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; validator command `000000017029` |
| C3PK-02 | 0003PK | Byte SHA256 is `13AF20BD86C583978C8B2EE099182C61F44C5783A14E8062A60E796558BFCE90`. | Exact | 951-byte live read | Target Evidence | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; validator command `000000017029` |
| C3PK-03 | 0003PK | Unique entry signature is `55 8B EC 51 A1 64 A7 67 00 56`. | Exact | Signature search, one hit | Target Evidence | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; validator command `000000017029` |
| C3PK-04 | 0003PK | Sole incoming machine route is Rain primary-vtable cell `0x00631230`. | Exact | xrefs and VA/RVA scan | Target Reachability | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; validator command `000000017029` |
| C3PK-05 | 0003PK | Source signature is `void RainingLayerPane::DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`. | Very strong | Base type, stack cleanup, caller | Target formal/signature | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; generated command `000000017030` contains one exact body |
| C3PK-06 | 0003PK | Both rectangle parameters are intentionally unused. | Exact | Full body and caller clip setup | Target behavior/negative evidence | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; validator command `000000017029` |
| C3PK-07 | 0003PK | Nonzero active-map waiting byte returns before color/draw work. | Exact | Entry disassembly/decompile | Target behavior/C++ | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; generated command `000000017030` |
| C3PK-08 | 0003PK | The method directly dereferences the singleton without a null guard. | Exact | Entry instructions | Target negative evidence/C++ | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; generated command `000000017030` |
| C3PK-09 | 0003PK | Target color is palette index decimal `143`, hexadecimal `0x8f` (Verified with int_convert.py). | Exact | SetDrawColor call, pixel args, and `python .\tools\int_convert.py 143 --single` result | Target behavior/C++ | Applied | Verified in UID0003PK SHA `F857C70C...38F32`; generated command `000000017030` |
| C3PK-10 | 0003PK | Streak loop draws exactly 18 records. | Exact | CFG/disassembly | Target behavior/C++ | Applied | Verified in UID0003PK and exact generated body under command `000000017030` |
| C3PK-11 | 0003PK | Small-splash loop draws 7 records and 14 pixels. | Exact | CFG/disassembly | Target behavior/C++ | Applied | Verified in UID0003PK and exact generated body under command `000000017030` |
| C3PK-12 | 0003PK | Large-splash loop draws 7 records and 28 pixels. | Exact | CFG/disassembly | Target behavior/C++ | Applied | Verified in UID0003PK and exact generated body under command `000000017030` |
| C3PK-13 | 0003PK | All Rain record fields and frame loads use signed source types. | Exact | `movsx`, current UDTs | Target types/C++ | Applied | Verified in UID0003PK SHA `F857C70C...38F32` |
| C3PK-14 | 0003PK | Integer scaling/truncation order must remain exact. | Exact | Instruction sequence per coordinate | Target behavior/C++ | Applied | Verified byte-for-byte in the target managed block and generated command `000000017030` |
| C3PK-15 | 0003PK | Current frame is reloaded around callbacks and is not cached or advanced. | Exact | Full disassembly | Target behavior/C++ | Applied | Verified in UID0003PK behavior/negative evidence and managed C++ |
| C3PK-16 | 0003PK | Target arrays are distinct source objects from main-view arrays. | Exact | Exclusive xrefs and physical addresses | Target data dependencies | Applied | Verified in UID0003PK data-dependency and negative-evidence text |
| C3PK-17 | 0003PK | No local clipping, fill, blend change, restore, randomization, or table mutation occurs. | Exact | Complete call/write inventory | Target negative evidence | Applied | Verified in UID0003PK negative-evidence section |
| C3PK-18 | 0003PK | `Layer_RenderRecursive` sets clip and dispatches Pane vtable slot `+0x10`. | Exact | Caller disassembly `0x004f1250-0x004f125d` | Target caller context | Applied | Verified in UID0003PK caller/clipping context |
| C3PK-19 | 0003PK | Owner/emitter remain `0000BJ`; source family remains `0000P8`. | Very strong | Vtable/constructor/class/file evidence | Target metadata/placement | Applied | Verified unchanged in UID0003PK metadata and UID0000P8 routing |
| C3PK-20 | 0003PK | Method formal is eligible and destination-ready. | Very strong | Complete behavioral/ABI closure | Target formal C++ | Applied | Verified as one exact generated body and zero target empty markers under command `000000017030` |
| C3PK-21 | 0003PK | Target score should become `92/94`. | Strong | All prior blockers resolved | Target metadata | Applied | Verified in UID0003PK metadata; validator command `000000017029` |
| C3PK-22 | 0003PK | Class support gains behavior-complete DrawOnTarget contract. | Very strong | Target + current class route | UID0000BJ behavior/method map | Applied | Verified in UID0000BJ SHA `C8557495...A1A2E9`; validator command `000000017020` |
| C3PK-23 | 0003PK | File support gains exact target method and generated body. | Very strong | Target + emitter route | UID0000P8 function/source map | Applied | Verified in UID0000P8 SHA `E9044749...94E4CB`; validator command `000000017022`; generated command `000000017030` |
| C3PK-24 | 0003PK | Aggregate remains non-emitting but must record target closure. | Very strong | Exact child split model | UID0001NZ child inventory | Applied | Verified in UID0001NZ SHA `232A1A7F...301A9`; validator command `000000017024` |
| C3PK-25 | 0003PK | Vtable page should call slot `DrawOnTarget`, not `DrawRainOnTarget`. | Very strong | Base contract/current type | UID0002Z8 slot/contract | Applied | Verified at callback SHA `EB9EEC2C...F9FE8`, command `000000017026`; compatible later support update reread at SHA `D012ABB0...9F65C` retains the exact slot closure |
| C3PK-26 | 0003PK | Historical dedicated-file page remains noncanonical and needs current score-rationale repair. | Strong | Current metadata and route | UID0000MY score/source notes | Applied | Verified in UID0000MY SHA `63D67F17...EDEE`; validator command `000000017027` |
| C3PK-27 | 0003PK | IDA function should be renamed and retyped; vtable cell should be commented. | Very strong | Exact ABI plus supervisor mutation/readback/save | Supervisor Gate 2B | Applied | `APPLIED_VERIFIED`: rename/type/function comment at `0x005c1810`, vtable comment at `0x00631230`, no-change checks, and saved-IDB checkpoint recorded below |
| C3PK-28 | 0003PK | Six manual coverage rows need exact replacement text. | Strong | Current row audit | Manual coverage reports | Proposed supervisor edit | Pending at B005 reconciliation checkpoint; supervisor-owned |

- Supervisor Gate 2A disposition: C3PK-01 through C3PK-26 independently passed claim-by-claim implementation verification. Their existing destination hashes, validator commands, and generated readbacks remain the accepted evidence.

## Positive Evidence Summary

- Exact target bytes, range, signature, CFG, and call inventory are stable and unique.
- The sole pointer route is the concrete Rain vtable slot; the Rain constructor installs that vtable and MapPane constructs the class.
- The Pane base virtual and `Layer_RenderRecursive` caller independently resolve the stale target prototype and source method name.
- Every array access resolves to accepted signed-short Rain types and exact target-only arrays.
- All drawing operations, loop counts, offsets, scaling expressions, gate behavior, and callback uses are accounted for.
- Existing [UID:0003PJ] source establishes compatible project naming/style, but the target body was independently reconstructed and differs correctly by receiver, arrays, no initial fill, and caller-managed clipping.

## IDA MCP Facts

- Function/range facts: `sub_5C1810`, start `0x005c1810`, end `0x005c1bc7`, size `0x3b7`/951, 10 basic blocks, cyclomatic complexity 5, `retn 0Ch`.
- Byte facts: SHA256 `13AF20BD86C583978C8B2EE099182C61F44C5783A14E8062A60E796558BFCE90`; first 16 bytes `558BEC51A164A76700568BF18975FC80`; last 16 bytes `070F8C42FEFFFF5F5E8BE55DC20C00`.
- Boundary facts: four `0xcc` bytes immediately precede the function; nine `0xcc` bytes fill `0x005c1bc7-0x005c1bd0`; successor `sub_5C1BD0` starts at `0x005c1bd0`, size `0xae`.
- Xref facts: target code has one data xref from `0x00631230`; the little-endian target VA appears once, at that cell; no target RVA hit and no xref to the end boundary.
- Callees: `GrafPort_MoveTo`, `GrafPort_SetDrawColor`, `g_pfnDrawPixel` at `0x0069b3e0`, and `g_pfnDrawLineDelta` at `0x0069b3e4`.
- Target-table refs: `0x006702c8` at `0x005c1877`; `0x00670478` at `0x005c1950/0x005c19bd`; `0x006704d0` at `0x005c1a3a/0x005c1aa5/0x005c1b10/0x005c1b7e`.
- Callback refs: line-delta cell at `0x005c18fc`; pixel cell at `0x005c1977`, `0x005c19e7`, `0x005c1a61`, `0x005c1acc`, `0x005c1b3a`, and `0x005c1ba8`.
- Vtable/global/type facts: target cell `0x00631230` lies in decorated Rain primary vtable `??_7RainingLayerPane@@6B@`; current local `RainingLayerPane` size is `0x10c`, `RainStreak` size 6, `RainSplash` size 4, `RectBounds` size 16, and `GrafPort` size `0x88`.
- Base contract: `Pane_DrawOnTarget` at `0x0041d680` is typed `void __thiscall(Pane *, GrafPort *, const RectBounds *, const RectBounds *)` and returns with `retn 0Ch`.
- Indirect caller: `Layer_RenderRecursive` at `0x004f0ff0` prepares two `RectBounds`, pushes both plus target `GrafPort`, and calls `[vtable+0x10]` after target clip setup.
- Negative IDA facts: no ordinary direct caller; no rectangle-pointer read; no random call; no target-state write; no clip/fill/blend/restore call; no main-view array reference.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005c1410-0x005c145a` | UID0003PI | Rain constructor | true | UID0000BJ | `86/88` | Support; establishes three frames/120 ms |
| `0x005c1460-0x005c180c` | UID0003PJ | Main-view `OnPaint` | true | UID0000BJ | `92/94` | Behavior-complete sibling |
| `0x005c1810-0x005c1bc7` | UID0003PK | Supplied-target `DrawOnTarget` | true | UID0000BJ | `86/88 -> 92/94` | Assigned target; formal proposed |
| `0x005c12a0-0x005c1bc7` | UID0001NZ | Weather/Rain migration index | false | none | `88/90 -> 89/92` | Non-emitting inventory support |
| `0x0063121c-0x006312ac` | UID0002Z8 | Rain RTTI/vtable data | true | UID0000BJ | `88/92 -> 89/93` | Compiler-generated marker support |
| `0x006702c8-0x00670784` | UID0001ON | Six exact Rain coordinate arrays | true | UID0000P8 | `93/94` | Already complete; no change |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00631230` | dword `0x005c1810` | Sole incoming machine route; Rain primary virtual slot `+0x10` |
| `0x004f1250-0x004f125d` | `Layer_RenderRecursive` indirect call | Proves target plus two `RectBounds *` virtual-call contract |
| `0x0067a764` | read at `0x005c1814` | Direct active-MapPane readiness gate |
| `0x006702c8` | read at `0x005c1877` | Target streak table only |
| `0x00670478` | reads at `0x005c1950/0x005c19bd` | Target small-splash table only |
| `0x006704d0` | reads at four large-splash sites | Target large-splash table only |
| `0x0069b3e4` | indirect call at `0x005c18fc` | One line-delta callback per streak |
| `0x0069b3e0` | six static call sites inside loops | Two/four pixel callbacks per splash record |
| `0x004b9600` | direct call | `GrafPort::MoveTo` for streak start |
| `0x004b9660` | direct call | `GrafPort::SetDrawColor(143)` after readiness gate |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion: Pane and Layer pages already carry the exact `DrawOnTarget` virtual signature; [UID:0003PJ] establishes shared Rain fields/callback style; [UID:0001ON] establishes target-array declarations; [UID:0003PI] establishes frame/timer semantics; [UID:0002Z8] establishes the Rain vtable slot; [UID:0000BJ]/[UID:0000P8] establish current ownership and source route.
- Historical assignment-time docs needing correction: target said formal C++ was blocked; UID0002Z8 labeled one slot `DrawRainOnTarget`; UID0000BJ/UID0000P8/UID0001NZ/manual rows called target behavior conceptual or blank; UID0000MY score rationale quoted stale `86/87` despite `89/91` metadata. C3PK-01 through C3PK-26 corrected the authorized ordinary docs; C3PK-28 manual rows remained supervisor-owned at this reconciliation checkpoint.
- Historical IDA pre-state before supervisor Gate 2B: `0x005c1810` was `sub_5C1810` with stale `void __thiscall(char *, GrafPort *, int, int)` typing. Supporting UDTs, target-array names, callback names, active-map global, base `Pane_DrawOnTarget`, and decorated Rain vtable name were already present. C3PK-27 is now supervisor `APPLIED_VERIFIED` as recorded under the exact IDA heading below.
- Historical generated assignment state: validator command `000000017005` produced an [UID:0003PK] `86/88` empty-emitter marker in `auto-generated/NexusTK/map/WeatherLayerPane.cpp`; commands `000000017030` and `000000017040` later verified one exact body and zero target empty markers.
- Historical coverage assignment state: generated memory coverage recorded owner/emitter `0000BJ` and `emits_code:no`; research tracker recorded `86/88` and zero report coverage. Generated state subsequently refreshed through validators, never by B005 manual edits. Manual C3PK-28 rows remained a separate supervisor-owned action at this reconciliation checkpoint.

## Ranked Ownership Analysis

### 1. UID0000BJ RainingLayerPane

- Evidence for: concrete Rain vtable slot, Rain constructor vtable stores, exact `RainingLayerPane *this` layout, Rain-only target arrays, sibling `OnPaint`, and class-qualified source contract.
- Evidence against: none material; the class page is a source declaration/child container rather than the physical source file.
- Decision: keep as direct canonical owner and emitter.

### 2. UID0000P8 WeatherLayerPane source family

- Evidence for: contiguous Weather/Rain family, current class-owner route, shared private Rain arrays, selected generated `NexusTK/map/WeatherLayerPane.cpp`, and accepted one-file family documentation.
- Evidence against: no PDB/source-path proof that the original physical file combined every weather class.
- Decision: keep as current physical file route through UID0000BJ, not as direct target owner.

### 3. UID0000MY historical RainingLayerPane file candidate

- Evidence for: a dedicated file would be plausible mid-2000s organization for a concrete weather class and its methods.
- Evidence against: current project route and contiguous family evidence favor UID0000P8; no source path, symbol, or binary boundary proves a dedicated disk file.
- Decision: preserve as historical alternative only; do not reroute emission.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; no new file or grouping is required.
- Likely full contents: target method remains a child definition under the existing WeatherLayerPane source family.
- Candidate related items that belong: existing Rain constructor, OnPaint, target arrays, and source-generated vtable remain in their current owners/routes.
- Candidate related items rejected: main-view arrays must not be merged with target arrays; vtable bytes must not be hand-authored; no local support-header facsimile belongs in the target.
- Standalone, narrow, or broad source-file inference: current broad WeatherLayerPane family remains selected, with dedicated Rain file preserved as a lower-ranked historical hypothesis.

## Source Placement

- Recommended placement: declaration in canonical `NexusTK/map/WeatherLayerPane.h`; qualified method definition emitted from [UID:0003PK] through [UID:0000BJ]/[UID:0000P8] into `NexusTK/map/WeatherLayerPane.cpp`.
- This placement matches current project routing, contiguous Weather/Rain code, shared file-static Rain arrays, MapPane construction, and sibling method placement.
- Rejected placements: `MapPane.cpp` owns construction/caller context but not the concrete Rain method; `Surface.cpp` owns callbacks but not weather policy; dedicated `RainingLayerPane.cpp` remains unproven; by-class/by-file pages must not duplicate method-body source.
- Remaining uncertainty: exact historical one-file versus per-concrete-layer disk split is unproved. It affects confidence only, not the selected current emitter route or executable behavior.

## Range / Split / Padding / Reclassification Analysis

- Exact range: one modeled function at `0x005c1810-0x005c1bc7`; no embedded data, secondary entry, or mixed owner.
- Predecessor boundary: [UID:0003PJ] ends at `0x005c180c`, followed by four `0xcc` bytes through `0x005c1810`.
- Successor boundary: nine `0xcc` bytes at `0x005c1bc7-0x005c1bd0`; `sub_5C1BD0` starts the SnowingLayerPane family.
- No child creation, merge, range expansion, ignored subrange, or reclassification is warranted.
- Parent/container impact: [UID:0001NZ] remains a non-emitting migration index and should record this child as behavior-complete without absorbing the formal body.

## Negative Evidence Summary

- No direct code caller exists; this does not imply dead code because the exact Rain vtable cell is the sole expected route and the base caller dispatches indirectly.
- No minimap-specific caller, field, string, table, or independent vtable route exists; minimap naming is rejected.
- No reads of `sourceBounds` or `targetBounds` exist; caller-side clip setup explains the intentional nonuse.
- No null check for `g_activeMapPane` exists; adding one would alter behavior.
- No target fill, clip, blend, restore, random, frame advance, table write, or object-state write occurs.
- No target-array alias to main-view arrays exists despite pairwise identical bytes.
- No evidence supports unsigned Rain coordinates, floating-point scaling, algebraic reordering, a 24-streak loop, or deduplication of zero records.
- No PDB/source path proves the historical dedicated-file hypothesis.

## IDA Rename / Type / Comment Recommendations

- Historical accepted Gate 2B pre-state: `0x005c1810` was named `sub_5C1810` with stale declaration `void __thiscall(char *this, GrafPort *target, int sourceBounds, int targetBounds)`.
- Historical accepted function rename recommendation: `RainingLayerPane__DrawOnTarget` at `0x005c1810`. This is IDA-valid, consistent with current `RainingLayerPane__OnPaint`, and preserves the source method spelling without a C++ decorated-name claim.
- Historical accepted exact function type: `void __thiscall RainingLayerPane__DrawOnTarget(RainingLayerPane *this, GrafPort *target, const RectBounds *sourceBounds, const RectBounds *targetBounds)`.
- Historical accepted exact function comment at `0x005c1810`: `RainingLayerPane DrawOnTarget override. Returns immediately while active MapPane awaits local-player status; otherwise renders frame-selected target rain arrays to the supplied GrafPort using color 143, 18 streaks, 7 small splashes, and 7 large splashes. RectBounds parameters are inherited virtual-contract inputs and intentionally unused; Layer configures clipping before dispatch.`
- Historical accepted exact data comment at `0x00631230`: `RainingLayerPane primary vtable +0x10: DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *) -> 0x005c1810.`
- Historical accepted supporting-type expectation: `RainingLayerPane` size `0x10c` with `m_currentFrame` signed byte at `+0xf8`; `RainStreak` size 6 with signed-short `x/y/length`; `RainSplash` size 4 with signed-short `x/y`; `RectBounds` size 16; `GrafPort` size `0x88`; `SurfaceDrawPixelProc`; `SurfaceDrawLineDeltaProc`.
- Historical accepted already-present/no-change set: `s_targetRainStreaks`, `s_targetRainSmallSplashes`, `s_targetRainLargeSplashes`, `g_pfnDrawPixel`, `g_pfnDrawLineDelta`, `g_activeMapPane`, `Pane_DrawOnTarget`, `RainingLayerPane__OnPaint`, and decorated `??_7RainingLayerPane@@6B@`/RTTI symbols.
- Historical accepted negative constraints: do not name the source method `DrawRainOnTarget`; do not retain integer rectangle arguments; do not invent parameter reads, clipping, state changes, null guards, local table aliases, randomization, or a hand-authored vtable; do not rename decorated compiler symbols.
- Supervisor Gate 2B environment: active database/session `supervisor_gate2b_0002OT_20260723`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Supervisor pre-mutation backup: `E:\NTK\Resources\NexusTK\NexusTK.pre-gate2b-0003PK-20260724-0138.i64`, SHA256 `578FDEAE94BE53B81DB95E0F0C9042A215E29C934794EE402AA0476C0B558654`, 143186430 bytes.
- `APPLIED_VERIFIED` at `0x005c1810`: renamed `sub_5C1810` to `RainingLayerPane__DrawOnTarget`; applied and read back exact type `void __thiscall RainingLayerPane__DrawOnTarget(RainingLayerPane *this, GrafPort *target, const RectBounds *sourceBounds, const RectBounds *targetBounds)`.
- `APPLIED_VERIFIED` function comment at `0x005c1810`: `RainingLayerPane DrawOnTarget override. Returns immediately while active MapPane awaits local-player status; otherwise renders frame-selected target rain arrays to the supplied GrafPort using color 143, 18 streaks, 7 small splashes, and 7 large splashes. RectBounds parameters are inherited virtual-contract inputs and intentionally unused; Layer configures clipping before dispatch.` The supervisor read back the exact report-proposed text.
- `APPLIED_VERIFIED` data comment at `0x00631230`: `RainingLayerPane primary vtable +0x10: DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *) -> 0x005c1810.` The supervisor read back the exact report-proposed text through non-function disassembly.
- `ALREADY_PRESENT_VERIFIED`: `RainingLayerPane` size `0x10c` with signed-byte `m_currentFrame` at `+0xf8`; `RainStreak` size 6; `RainSplash` size 4; `RectBounds` size 16; `GrafPort` size `0x88`; typedefs `SurfaceDrawPixelProc` and `SurfaceDrawLineDeltaProc`; arrays `s_targetRainStreaks`, `s_targetRainSmallSplashes`, and `s_targetRainLargeSplashes`; callbacks/globals `g_pfnDrawPixel`, `g_pfnDrawLineDelta`, and `g_activeMapPane`; functions `Pane_DrawOnTarget` and `RainingLayerPane__OnPaint`; decorated Rain vtable/RTTI identities.
- `NO_CHANGE_VERIFIED`: exactly one target xref remains from vtable cell `0x00631230`; target function size remains `0x3b7`; vtable cell bytes remain `10 18 5c 00`; function bytes/bounds, callback/global addresses, array storage, adjacent padding, and decorated compiler identities remain unchanged.
- Supervisor save closure: `idb_save` returned `ok`. Saved `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` SHA256 `DC6375D64BE25D8225EEB7EE64153BD1AE77B5EFB3822CC23E29010462BA4B65`, 143184835 bytes, timestamp `2026-07-24T01:40:54.1386080-04:00`.
- Gate 2B disposition: C3PK-27 is supervisor `APPLIED_VERIFIED`; all accepted negative constraints and compiler-generated-name preservation requirements remain satisfied.
- B005 made no IDA mutation, did not create the backup, did not perform readback/save, and only incorporated the supervisor-provided closure into this same report.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The ABI, full body, data types, branches, loops, constants, dependencies, and source route are closed.
- Implemented code: exact destination managed-block text. The inline value is intentionally blank because validator command `000000017018` proved that a nonblank inline value causes the complete multiline block to be ignored; command `000000017029` accepted the blank-inline plus nonblank multiline form and command `000000017030` generated the exact body once:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RainingLayerPane::DrawOnTarget(
    GrafPort *target,
    const RectBounds *,
    const RectBounds *)
{
    if (g_activeMapPane->m_waitingForLocalPlayerStatus)
        return;

    const unsigned int rainColor = 143;
    target->SetDrawColor(rainColor);

    int i;
    for (i = 0; i < 18; ++i) {
        target->MoveTo(
            2 * (17 * s_targetRainStreaks[m_currentFrame][i].x / 15),
            2 * (15 * s_targetRainStreaks[m_currentFrame][i].y / 13));
        g_pfnDrawLineDelta(
            target,
            2 * (-17 * s_targetRainStreaks[m_currentFrame][i].length / 15),
            2 * (30 * s_targetRainStreaks[m_currentFrame][i].length / 13));
    }

    for (i = 0; i < 7; ++i) {
        g_pfnDrawPixel(
            target,
            2 * (17 * s_targetRainSmallSplashes[m_currentFrame][i].x / 15),
            2 * (15 * (s_targetRainSmallSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * (s_targetRainSmallSplashes[m_currentFrame][i].x + 2) / 15),
            2 * (15 * (s_targetRainSmallSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
    }

    for (i = 0; i < 7; ++i) {
        g_pfnDrawPixel(
            target,
            2 * (17 * s_targetRainLargeSplashes[m_currentFrame][i].x / 15),
            2 * (15 * s_targetRainLargeSplashes[m_currentFrame][i].y / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * s_targetRainLargeSplashes[m_currentFrame][i].x / 15),
            2 * (15 * (s_targetRainLargeSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * (s_targetRainLargeSplashes[m_currentFrame][i].x + 4) / 15),
            2 * (15 * (s_targetRainLargeSplashes[m_currentFrame][i].y + 6) / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * (s_targetRainLargeSplashes[m_currentFrame][i].x + 6) / 15),
            2 * (15 * (s_targetRainLargeSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable; this is original NexusTK class code, not a vetted static third-party embed.
- Exact behavior preservation: the formal retains the direct singleton gate, target receiver, palette color, exact iteration counts, signed table accesses, callback ordering, pixel offsets, and integer operation order.
- Human source shape: unnamed unused definition parameters are valid C++03 and avoid fabricated local uses; `rainColor`, `target`, and `i` are conventional source-facing names; no IDA labels, offset casts, raw slots, or decompiler temporaries remain.
- Naming/style: class/member and `g_`/`s_` names follow accepted nearby Weather/Rain and callback documentation. Runtime fidelity and human source shape take priority over speculative stylistic normalization.
- Reason code should remain blank: not applicable.
- Exact no-code proof: not applicable because the target is eligible and behavior-complete.

## Final Recommendation

- C3PK-01 through C3PK-26 are applied and independently verified in the six authorized ordinary documents. UID0003PK now contains the exact behavior-complete managed C++, detailed evidence, corrected method name/signature, behavior/negative evidence, generated-state explanation, and score `92/94`.
- Exact target ownership and emitter metadata remain unchanged: owner/emitter `0000BJ`, reconstructable true, blank optional position.
- UID0000BJ, UID0000P8, UID0001NZ, UID0002Z8, and UID0000MY contain the bounded support facts without duplicating the target method body.
- UID0001ON remains `93/94`, UID0003PJ remains `92/94`, and UID0003PI remains `86/88`; their target-relevant evidence required no callback edit.
- Immediate callback command `000000017030` and post-callback compatible readback command `000000017040` each contain exactly one UID0003PK `DrawOnTarget` body and zero UID0003PK empty-emitter markers. Supervisor C3PK-27 Gate 2B is `APPLIED_VERIFIED`; C3PK-28 manual coverage remained supervisor-owned and unapplied at this B005 reconciliation checkpoint.
- Preserve the current file route until independent source-path evidence proves a different original physical split.

## Recommended Target Doc Changes

- Implemented at `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md`, final SHA `F857C70C8142AACD67D18AE8521FBC957555A82A3A15DFCD995019947D938F32`.
- Scores are `COMPLETION:92`, `CONFIDENCE:94`; owner/emitter/reconstructable metadata is unchanged.
- The exact complete formal is installed as a blank inline header plus nonblank multiline managed block, the validator-compatible representation for the accepted body.
- Exact ABI, caller-managed clipping, byte/hash/signature, control flow, loops, arithmetic, table/callback, negative evidence, source placement, and generated-route closure replace stale current blockers without deleting their historical context.
- Item Summary now records the exact `DrawOnTarget` virtual contract, caller-configured clipping, 18/7/7 target-array rendering, color 143, and behavior-complete emitted C++ without repeating validator-rendered metadata.
- Older minimap terminology, the stable `DrawRainOnTarget` documentation filename, and the earlier blocker list are preserved as historical assumptions with supersession reasons.
- Negative constraints are preserved: no null guard, parameter reads, local clip/fill/blend/restore, random/frame update, table alias/deduplication, or operation-order simplification.

## Recommended Support Doc Changes

- Implemented in `by-class/RainingLayerPane.md` [UID:0000BJ], SHA `C8557495BAE93F2928028E77888E46C53115160BAA02B25FD858105C7621A2E9`: exact `DrawOnTarget` caller/signature/behavior closure and sibling difference; comment-plus-children formal retained; score `91/93`; no method body embedded.
- Implemented in `by-file/WeatherLayerPane.md` [UID:0000P8], SHA `E9044749143830EAE52848D6C9F91C7B54CED060AFA89D98B04F2A429B94E4CB`: stale blank-target statement historicalized; behavior-complete target formal/generated route recorded; score `92/93`.
- Implemented in `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md` [UID:0001NZ], SHA `232A1A7F3B635D61F283500377D2098E3F9F061D8CB3C56185DE9834807301A9`: non-reconstructable/non-emitting index retained; both Rain methods recorded as behavior-complete exact children; score `89/92`.
- Implemented in `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md` [UID:0002Z8], callback SHA `EB9EEC2CE23F9403FD4C1B04140ECC5B9844D98CED3BEB0E33BD3AC5BFAF9FE8`, post-callback compatible readback SHA `D012ABB0934D905B2BC835B0B7D3C796AF48F1F66CBA73BB92F6D9647299F65C`: slot prose remains corrected to `DrawOnTarget`; exact typed contract and behavior-complete child remain recorded; marker-only C++ and score `89/93` remain intact. A later unrelated UID0003PH support callback added timer/frame-hook detail without displacing C3PK-25.
- Implemented in `by-file/RainingLayerPane.md` [UID:0000MY], SHA `63D67F171EDEA7EE64367D1BEEF7CA6838EFCED5895E39AD175AB2DA41A4EDEE`: `89/91` and historical/noncanonical status retained; stale score rationale repaired; target closure recorded; dedicated-file hypothesis remains secondary.
- No change was needed in Pane/Layer virtual-contract pages, UID0001ON arrays, UID0003PI constructor, UID0003PJ OnPaint, active-map singleton/type docs, or callback docs because they already provide sufficient accepted support.

## Score And Metadata Recommendation

- Assignment-time target: `86/88`, owner/emitter `0000BJ`, reconstructable true, blank formal C++.
- Current implemented target: `92/94`, owner/emitter/reconstructable unchanged, behavior-complete formal C++ present and generated exactly once.
- Reason not lower: exact bytes/bounds/signature, unique vtable route, typed base contract, indirect caller, complete CFG/call/data inventory, accepted types/names, exact C++ source form, and generated route are all resolved.
- Reason not higher: original local lexical names and exact historical one-file versus dedicated Rain source split lack original symbols/PDB/source-path proof; no rebuilt binary/codegen comparison has yet validated compiler identity.
- Score-improvement attempt: stale GrafPort/helper names were checked against current names/types; Rain fields and arrays against current UDTs/docs; prototype against base/caller; clipping against caller and body; control flow against full disassembly; source route against class/file/generator evidence; all formerly listed blockers were removed.
- Current support scores after callback: UID0000BJ `91/93`; UID0000P8 `92/93`; UID0001NZ `89/92`; UID0002Z8 `89/93`; UID0000MY remains `89/91`; UID0001ON/UID0003PI/UID0003PJ remain unchanged.
- No owner, emitter, reconstructable, optional-position, split, or range metadata change is warranted.

## Open Questions With Attempted Resolution

- Is this minimap-specific? Checked callers, vtables, strings, fields, arrays, and old reports. Resolution: no support for minimap specificity; use general target-port semantics.
- Is the source method named `DrawRainOnTarget`? Checked base declaration, vtable slot, caller, project naming, and current Pane type. Resolution: `DrawOnTarget` is the high-probability source name; preserve old filename only as a stable artifact.
- Are final arguments integers or rectangles? Checked caller stack construction, base prototype, stack cleanup, and target nonuse. Resolution: two `const RectBounds *` arguments.
- Who owns clipping? Checked caller and full target call inventory. Resolution: `Layer_RenderRecursive` configures target clipping before dispatch; target intentionally ignores both rectangles.
- Are target arrays aliases of main arrays? Checked addresses, hashes, xrefs, and accepted table declarations. Resolution: distinct file-static source objects despite byte identity.
- Does the method mutate animation/random state? Checked all writes/calls. Resolution: no; timer/base machinery advances frames externally.
- Should source route move to dedicated `RainingLayerPane.cpp`? Checked binary adjacency, current docs, generator route, and source-path evidence. Resolution: keep UID0000P8 current route; historical split remains a confidence cap.
- Can exact original local names be proven? No original symbols exist. Resolution: use conventional `target`, `rainColor`, and `i`; these are source-quality inferences and do not block code.
- Remaining unresolved questions: only original lexical spellings and physical source-file split. Exhaustive available evidence cannot prove them, but both have high-probability source-quality choices and neither blocks exact execution or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected current manual rows: UID0003PK, UID0001NZ, UID0002Z8 in `by-memory/-coverage-report.md`; UID0000BJ in `by-class/-coverage-report.md`; UID0000P8 and UID0000MY in `by-file/-coverage-report.md`.
- File/placement: replace the existing UID0003PK row in `by-memory/-coverage-report.md` with:

```text
        - [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) 0x005c1810-0x005c1bc7 | target-port rain renderer | RainingLayerPaneDrawRainOnTarget : reconstructable : 92% : very-strong : Behavior-complete void RainingLayerPane::DrawOnTarget(GrafPort*,const RectBounds*,const RectBounds*) override reached through Rain vtable slot 0x00631230; Layer configures clipping before dispatch and this override intentionally ignores both bounds, applies the active-MapPane readiness gate, sets color 143, and renders exact 18/7/7 signed-short target-array loops through GrafPort/Surface callbacks with preserved integer truncation and no local fill, clip, blend, restore, random, or state update.
```

- File/placement: replace the existing UID0001NZ row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) 0x005c12a0-0x005c1bc7 | non-emitting WeatherLayerPane/RainingLayerPane migration index | WeatherAndRainingLayerPanes : not_reconstructable : 89% : very-strong : Exact Weather/Rain executable inventory with five source-bearing function children, four compiler-alignment gaps, current WeatherLayerPane.cpp source-family route, exact 0x10c Weather/Rain inheritance layout, three-frame/120 ms Rain animation, and behavior-complete RainingLayerPane::OnPaint plus DrawOnTarget formals; the target override uses caller-configured clipping, exact 18/7/7 target-array rendering, and no local state update, while canonical project headers remain surrounding source-tree obligations and exact children retain target-specific formals.
```

- File/placement: replace the existing UID0002Z8 row in `by-memory/-coverage-report.md` with:

```text
        - [UID:0002Z8][0x0063121c-0x006312ac.RainingLayerPaneVtableData](by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md) 0x0063121c-0x006312ac | vtable-data | RainingLayerPaneVtableData : reconstructable : 89% : very-strong : Exact 0x90-byte Rain RTTI/vtable child assigned to direct class parent [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md); current evidence confirms primary and adjusted views, constructor stores, MapPane caller, behavior-complete OnPaint and typed DrawOnTarget(GrafPort*,const RectBounds*,const RectBounds*) slots, shared OnTimer contract, exact no-added-storage 0x10c class extent, compiler-only vtable generation, three-frame/120 ms constructor semantics, and canonical WeatherLayerPane.h class-contract placement.
```

- File/placement: replace the existing UID0000BJ row in `by-class/-coverage-report.md` with:

```text
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) : reconstructable : 91% : very-strong : Exact no-added-storage 0x10c `RainingLayerPane : public WeatherLayerPane` class model with constructor, behavior-complete `OnPaint()` and `DrawOnTarget(GrafPort*,const RectBounds*,const RectBounds*)` contracts, exact method ranges, MapPane construction, Rain vtable slots, inherited Pane/Weather state, three-frame/120 ms animation, and six exact file-static signed-short rain arrays; DrawOnTarget uses caller-configured clipping and exact 18/7/7 target-array rendering, comment-plus-children R5 routes qualified definitions, canonical WeatherLayerPane.h owns the class declaration, and compiler-generated data plus historical dedicated-file context remain preserved.
```

- File/placement: replace the existing UID0000P8 row in `by-file/-coverage-report.md` with:

```text
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) : reconstructable : 92% : very-strong : Weather-layer source family under NexusTK/map/ with exact UID0001ON arrays, 0x10c Weather/Rain inheritance models, map ownership, exact Weather/Rain/Snow/Swallow routes, contiguous code/RTTI/vtables plus adjacent data, inherited animation state, corrected three-frame/120 ms Rain semantics, direct g_activeMapPane readiness gate, and behavior-complete RainingLayerPane::OnPaint plus DrawOnTarget source; the target override preserves caller-configured clipping and exact 18/7/7 target-array rendering, while canonical project headers remain surrounding obligations and historical split-file alternatives remain preserved.
```

- File/placement: replace the existing UID0000MY row in `by-file/-coverage-report.md` with:

```text
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md) : reconstructable : 89% : very-strong : Rain-overlay dedicated-file historical candidate under NexusTK/map/ preserving exact constructor, behavior-complete OnPaint and DrawOnTarget methods, no-added-storage 0x10c Rain model, MapPane construction, Rain vtables, three-frame/120 ms animation, direct active-map readiness gate, inherited Pane/Weather state, exact main/target rain arrays, and source-named Surface callbacks; reconstruction remains routed through the stronger contiguous WeatherLayerPane.cpp family with canonical project-header dependencies, so standalone RainingLayerPane.cpp remains secondary.
```

- Reason B005 must not apply these rows directly: all `-coverage-report.md` files are supervisor-owned collision points. Generated tracker/coverage files must be refreshed by validator/lifecycle tools, not manually edited.

## Follow-Up Actions

- Completed supervisor Gate 2A: C3PK-01 through C3PK-26 passed independent claim-by-claim destination, validator, and generated-output verification.
- Completed supervisor Gate 2B: C3PK-27 is `APPLIED_VERIFIED` with exact pre-backup, rename/type/comments, already-present/no-change readback, saved-IDB hash, size, and timestamp recorded under the IDA heading.
- Fresh-artifact requirement: because this B005 reconciliation changes the exact report revision by incorporating final supervisor evidence, the supervisor must perform a fresh exact-artifact Gate 1 and Gate 2 continuity audit before any remaining action.
- Supervisor C3PK-28 checkpoint: the exact manual coverage rows supplied below had not yet been applied/validated when B005 performed this reconciliation; B005 did not edit any coverage report.
- Supervisor lifecycle boundary: B005 does not run, probe, dry-run, or invoke lifecycle commands. Any eventual supervisor execution/archive authorization and result must be recorded by the validator-owned history footer/registry, which is authoritative whether this artifact is still active or later archived.
- A-agent actions: none.
- B005 future actions: none remaining from C3PK-01 through C3PK-27 unless the fresh exact-artifact audits identify a concrete report defect or new evidence contradicts a claim.

## Confidence

- Recommendation confidence: very strong (`94`) for exact behavior/signature/route; strong for inferred source spellings and physical source-family choice.
- Score confidence: strong. `92/94` matches the behavior-complete sibling while retaining sub-95 caps for source-name/file-split and no rebuild comparison.
- Remaining uncertainty: original local lexical spelling and original disk split only; both have explicit best-supported choices and do not block execution-equivalent human source.

## Validator Results

- UID0003PK initial scoped validation: command `000000017018`, `2026-07-24T01:11:47-04:00`, `ok: 1`. It reported `autogen_inline_ignored` because the nonblank inline value took precedence over the multiline body, and the generated target remained omitted. This result is historical and superseded by the corrected managed-header validation.
- UID0000BJ scoped validation: command `000000017020`, `2026-07-24T01:12:53-04:00`, `ok: 1`, with no target-specific warning.
- UID0000P8 scoped validation: command `000000017022`, `2026-07-24T01:13:50-04:00`, `ok: 1`. It retained 14 pre-existing `missing_ref_uid` warnings involving UID0003YQ and UID0003O2; those unrelated references were outside this accepted callback.
- UID0001NZ scoped validation: command `000000017024`, `2026-07-24T01:14:42-04:00`, `ok: 1`. It retained the existing `emitter_inactive_has_data` warning for a non-reconstructable aggregate carrying marker comments; the aggregate remains intentionally non-emitting.
- UID0002Z8 scoped validation: command `000000017026`, `2026-07-24T01:15:38-04:00`, `ok: 1`, clean for this target.
- UID0000MY scoped validation: command `000000017027`, `2026-07-24T01:16:19-04:00`, `ok: 1`. The validator projected an empty reconstructed-source placeholder at `auto-generated/NexusTK/map/RainingLayerPane.cpp`; B005 did not manually edit generated output.
- UID0003PK final scoped validation after blanking only the inline managed-header value: command `000000017029`, `2026-07-24T01:17:14-04:00`, `ok: 1`, with `autogen_error_clear` and no remaining UID0003PK emitter error.
- Immediate callback generated checkpoint: `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, command `000000017030`, `2026-07-24T01:17:42-04:00`, SHA256 `9E45C70A4B6B2AA32906365293AF2B92DB22085C7812B367268B40508B0D1C78`, 17600 bytes, 425 content lines. It contained one UID0003PK record, one exact `RainingLayerPane::DrawOnTarget` body, the complete target managed block verbatim, and zero UID0003PK empty-emitter markers.
- Post-callback compatible generated readback after unrelated validator activity: command `000000017040`, `2026-07-24T01:22:25-04:00`, handoff-observed SHA256 `A6559F06F5171071F79FD587CE3CF9A2BF73BCEA31FE26AA3882B7F5A17565EA`, 17600 bytes, 425 content lines. UID0003PK still occurs once, the exact method body still occurs once, and its empty-emitter marker count remains zero. Later unrelated refreshes may advance this shared checkpoint.
- Validators automatically refreshed their owned projected statistics, generated source, memory coverage, and validator state. B005 did not manually edit those files and did not run any report lifecycle command.

## Changed Files

- Modified target: `by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md`, SHA256 `F857C70C8142AACD67D18AE8521FBC957555A82A3A15DFCD995019947D938F32`, 15539 bytes, 143 lines.
- Modified support: `by-class/RainingLayerPane.md`, SHA256 `C8557495BAE93F2928028E77888E46C53115160BAA02B25FD858105C7621A2E9`, 17554 bytes, 131 lines.
- Modified support: `by-file/WeatherLayerPane.md`, SHA256 `E9044749143830EAE52848D6C9F91C7B54CED060AFA89D98B04F2A429B94E4CB`, 46698 bytes, 271 lines.
- Modified support: `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md`, SHA256 `232A1A7F3B635D61F283500377D2098E3F9F061D8CB3C56185DE9834807301A9`, 22986 bytes, 164 lines.
- Modified support: `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`, callback SHA256 `EB9EEC2CE23F9403FD4C1B04140ECC5B9844D98CED3BEB0E33BD3AC5BFAF9FE8`; post-callback compatible readback SHA256 `D012ABB0934D905B2BC835B0B7D3C796AF48F1F66CBA73BB92F6D9647299F65C`, 24306 bytes, 190 content lines. The later UID0003PH support addition preserves all UID0003PK C3PK-25 content.
- Modified support: `by-file/RainingLayerPane.md`, SHA256 `63D67F171EDEA7EE64367D1BEEF7CA6838EFCED5895E39AD175AB2DA41A4EDEE`, 18025 bytes, 126 lines.
- Reconciled this same report in place after independently rereading all six destinations and generated WeatherLayerPane.cpp, then incorporated the supervisor-provided Gate 2A and C3PK-27 Gate 2B closure without changing any ordinary/generated/coverage/IDA/validator/lifecycle state; its exact final hash and metrics are returned with this handoff.
- Renamed: none.
- B005 lifecycle action: none. At this reconciliation checkpoint supervisor lifecycle execution had not yet been recorded; B005 did not run, probe, dry-run, or invoke `execute_report` or any equivalent lifecycle command. If the supervisor later executes/archives this report, the validator-owned history footer/registry supersedes this checkpoint for current lifecycle truth.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 passed exact pre-callback SHA `AC91DD8FD2B2A3B239EBF2A29C52E886DB04CD20CE71B050235600D2686CB375` before implementation.
- [x] Target/support docs updated: UID0003PK, UID0000BJ, UID0000P8, UID0001NZ, UID0002Z8, and UID0000MY.
- [x] Every declared support UID has target-specific evidence, recommendation, ledger rows, destination docs, and independent validation.
- [x] Current target state and actual evidence recorded, including decimal `143` to hexadecimal `0x8f` verification with `tools/int_convert.py`.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: target `92/94`; bounded support scores listed above.
- [x] Score-limiting blockers researched to resolution, including exact ABI, clipping ownership, source placement, arrays, operation order, naming, and generated emitter closure.
- [x] Owner/emitter/reconstructable routes independently confirmed unchanged.
- [x] No document split/child/path change applied; source method spelling corrected without filename churn.
- [x] Source placement and range/split/padding/reclassification conclusions applied to the authorized ordinary documents.
- [x] Supervisor Gate 2B C3PK-27 completed as `APPLIED_VERIFIED`: exact address/entity, pre-state, backup, rename/type/comments, supporting types, safety constraints, no-change readback, and saved-IDB checkpoint are recorded.
- [x] Behavior-complete first-draft C++ applied only to UID0003PK in validator-compatible managed-block form.
- [x] Third-party import directive confirmed not applicable: original NexusTK method, not a third-party embed.
- [x] Exact target/support facts incorporated at report-level detail without summary-only loss.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 artifacts were not used as evidence.
- [x] Open questions closed with evidence-backed best-supported conclusions.
- [x] Serial scoped validators run for all six authorized ordinary documents.
- [x] Generated WeatherLayerPane.cpp refreshed under command `000000017030` and independently reverified after compatible command `000000017040`.
- [ ] At the B005 reconciliation checkpoint, C3PK-28 exact manual supervisor-owned coverage text had not yet been applied/validated; B005 did not edit coverage.

Implementation callback pass:
- [x] Supervisor-owned IDA changes are `APPLIED_VERIFIED`; B005 did not mutate IDA and only recorded the supervisor's exact Gate 2B closure.
- [x] Report accepted by supervisor for implementation at exact Gate 1 SHA `AC91DD8F...CB375`.
- [x] All accepted C3PK-01 through C3PK-26 target/support details incorporated at report-level detail.
- [x] Every primary/support destination independently reread against its ledger claims and final hash.
- [x] Claim And Incorporation Ledger reconciled with applied destination and verification state for C3PK-01 through C3PK-26.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly retained with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved with evidence-backed best-supported conclusions.
- [x] All six scoped validators run serially and results recorded.
- [x] Generated refresh completed and independently checked for one exact target body and zero target empty markers.
- [x] No B005-owned accepted callback item remains unapplied; supervisor Gate 2A and C3PK-27 Gate 2B are complete, while C3PK-28 and lifecycle were not complete at this reconciliation checkpoint.
- [x] Supervisor Gate 2A independently passed C3PK-01 through C3PK-26 against the destinations, validators, and generated output.
- [ ] Fresh exact-artifact Gate 1 and Gate 2 continuity audits of this reconciled report revision remain supervisor-only prerequisites before C3PK-28/lifecycle handling.
- [ ] At the B005 reconciliation checkpoint, supervisor lifecycle execution/archive had not yet been recorded; any later status is authoritative only in the validator-owned history footer/registry.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000017061","destination_path":"executed-b-agent-research/B005/0003PK-RainingLayerPaneDrawRainOnTarget-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003PK-RainingLayerPaneDrawRainOnTarget-empty-emitter-source-quality.md","timestamp":"2026-07-24T01:54:31-04:00","uid":"0003PK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
