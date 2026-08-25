** TARGET-REPORT-UID:0000XX **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000XX DATIndexVectorFindNodeByKey Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0000XX] `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md` assigned to [UID:00003K] `by-class/DATIndexVector.md`, keep emitter [UID:00003K], keep `RECONSTRUCTABLE:TRUE`, and keep formal C++ blank after applying current MCP session `b006-0000xu` evidence.
- Final disposition: exact `DATIndexVector` keyed bucket lookup method, not a MiniMapVersionManager, MonsterImageLib, DATFileMgr, generic LinkedList, or no-owner helper.
- Implementation callback status: Gate 1 passed for report SHA256 `2FE9AD699A40FEA98FD30003E8509EEE92924E163DDF3FB8B3A73F89261B6F8F`; target/support edits were applied on 2026-07-05 and scoped validators passed.
- Applied action: target evidence and source-quality notes updated; score changed from `COMPLETION:85` / `CONFIDENCE:90` to `COMPLETION:88` / `CONFIDENCE:91`.
- Confidence: high for boundary, behavior, caller fanout, owner, and no-callee body; medium-high for final source-facing method signature because the binary ABI returns through a one-slot result/out object with `retn 8`, while current class/generated docs expose a pointer-returning convenience declaration.

## Supporting Research
- Original Gate 1 report-only pass for UID `0000XX`: no by-* documentation, generated file, validator registry/state file, manual coverage file, lifecycle/archive file, or executed-report folder was edited.
- Gate 2 implementation callback: edited only the target by-memory page, `by-class/DATIndexVector.md`, `by-file/DATIndexVector.md`, and this B007 research report. Scoped validators updated validator-owned projected stats and generated DATIndexVector output; no manual generated/report/coverage/lifecycle edits were made.
- Primary queue context at assignment time was `auto-generated/-ag-research-tracker.md` line-area row for `0000XX` under by-memory not-covered reconstructable work: tracker state `85/90`, combined `87.5`, reconstructable `true`, report count `0`.
- MCP incident note: the first MCP session listed by `idb_list`, `19917133`, was stale. `server_health` and `lookup_funcs` with that session returned `Session not found: 19917133`; the listener and process checks showed MCP still listening on `127.0.0.1:13337`. A later read-only `idb_list` returned active session `b006-0000xu`, which was used for all current binary evidence below. No fallback-only evidence is used.

## Target
- Target UID: `0000XX`.
- Target path: `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row near assignment-time line `1571`.
- Current supervisor classification: Gate 1 accepted implementation callback for a reconstructable by-memory item.
- Current scores and parent state after callback: target is `88/91`; direct class parent [UID:00003K] `DATIndexVector` is `88/90`; file parent [UID:0000IP] `DATIndexVector` is `88/88`.

## Current Target State
- Post-callback metadata: `UID:0000XX`, range `0x00457580-0x00457613`, `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00003K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003K`, blank formal C++.
- Existing owner/emitter/reconstructable state: correct. The method belongs to the reusable `DATIndexVector` class and emits through the class/file route to `auto-generated/NexusTK/archive/DATIndexVector.cpp`.
- Existing C++/emitter state: generated `DATIndexVector.cpp` currently emits the class declaration plus `ResizeAndFill` and `EnsureBucketSlotCapacity`; `0000XX` remains an `Empty Emitter Marker`.
- Existing blockers or stale assumptions:
  - The target page correctly records the FNV-1a bucket lookup, caller spread, node/bucket layout, and blank C++ policy.
  - The target page's historical change note says the boundary fix captured the final byte of a `retn 4`; current disassembly shows both exits are `retn 8`, so that note should be corrected or historicalized.
  - The class/generated declaration `DATIndexVectorNode* FindNodeByKey(const int& key) const` is source-convenient for consumers, but current binary evidence shows this exact function takes a result slot and key pointer on the stack and returns the address of the result slot. A formal method body should not be emitted until the source API shape is resolved as pointer-return wrapper versus iterator/result-object return.
- Related target/support docs checked:
  - `by-class/DATIndexVector.md`
  - `by-file/DATIndexVector.md`
  - `by-type/by-struct/DATIndexVectorNode.md`
  - `by-type/by-struct/DATIndexVectorBucket.md`
  - `by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md`
  - `by-class/MonsterImageLib.md`
  - `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`
  - generated `auto-generated/NexusTK/archive/DATIndexVector.cpp`
  - executed reports B009 `00003K-DATIndexVector-class-source-quality.md`, B002 minimap version-manager report, and B003 `00017E-MonsterImageLibGetArchiveBoundsBucket-source-quality.md`.

## Executive Recommendation
- Keep direct owner [UID:00003K] `DATIndexVector` and source file [UID:0000IP] `DATIndexVector`.
- Raise the target to `88/91` if the supervisor accepts the current ABI/source-signature/no-code clarification. Do not raise higher because formal C++ for this exact method is still blocked by the unsettled source API shape.
- Keep formal target C++ blank for now, but replace the broad blank-C++ rationale with an exact no-code proof: the behavior is fully understood, yet a body using the current pointer-returning declaration would not match the observed sret/out-slot ABI, while a raw out-slot body would be decompiler-shaped.
- Add current MCP evidence for session `b006-0000xu`: health, exact function size, decompile, full bounded disassembly, xrefs, no callees, caller use patterns, and boundary/padding bytes.

## Supervisor Active Recheck
- Original instruction assigned Agent-B007 to report-only research for UID `0000XX`; the current supervisor callback explicitly authorized the target/support by-* implementation edits after Gate 1 while keeping lifecycle/archive/execute commands prohibited.
- No split repair is needed. `lookup_funcs` reports one function at `0x00457580`, size `0x93`, and `get_bytes` confirms three `0xcc` bytes before the start and thirteen `0xcc` bytes after `0x00457613`.
- No source-bearing child is missing inside the assigned range. The function has no callees and no data xrefs from the body.
- MCP evidence is current. Initial stale-session errors were handled under the MCP incident playbook; active session `b006-0000xu` served the final exact-address calls.

## Inference Research Guidance Check
- `by-structure.md` MCP discipline was followed: `initialize`, `tools/list`, `idb_list`, then exact-address `lookup_funcs`, `server_health`, `analyze_function`, `decompile`, `disasm`, bounded `xrefs_to`/`xref_query`, bounded `get_bytes`, `type_inspect`, and bounded `entity_query`.
- Existing documentation assumptions treated as uncertain and rechecked:
  - exact function boundary and post-body padding;
  - whether the historical `retn 4` wording was correct;
  - whether `FindNodeByKey(const int& key) const` is exact source/API proof or a convenience declaration;
  - whether caller spread still rules out MiniMapVersionManager and MonsterImageLib ownership;
  - whether IDA has durable type records for `DATIndexVector`, `DATIndexVectorNode`, or `DATIndexVectorBucket`.
- Direct IDA fact: raw function name is still `sub_457580`, no IDA type records exist for the three DATIndexVector types in this session, xrefs are exactly three code callers, and both exits use `retn 8`.
- Documentation evidence: current by-* docs correctly converge on `DATIndexVector` ownership, node/bucket fields, and the broad consumer fanout.
- Inference: source-facing names `DATIndexVector`, `FindNodeByKey`, `DATIndexVectorNode`, and `DATIndexVectorBucket` remain the best reconstruction, but original symbol/API spelling is not proven.
- Wave2/Wave3 artifacts were not used as authority. Generated output was read only as current emission-state context.

## Heuristic / Inference Reanalysis And Validation
- Function role: `DATIndexVectorFindNodeByKey` is a reusable bucket lookup over the `DATIndexVector` object. Current decompile hashes exactly four bytes from the key address, masks by `this[6]` / `m_bucketMask`, selects a bucket from `this[3]` / `m_bucketsBegin`, scans from bucket `first`, stops at sentinel or `last->next`, compares `node->key` at `+0x08`, and stores either the matching node or sentinel into the caller result slot.
- ABI/source API: current disassembly pushes two stack arguments at each caller: a local result slot and the key address. The callee returns the result-slot address in `eax` and uses `retn 8`. Callers immediately load `[eax]`. This is consistent with a one-field result object or iterator-style return at the binary level. It is not exact proof that the original source returned a raw pointer directly, even though a raw-pointer wrapper remains a plausible high-level interface.
- Source-facing name: keep `FindNodeByKey`. It describes both observed caller roles and the class method family, and is already used by class/file/consumer docs. `Lookup`, `Find`, or `FindNode` are plausible but not enough better to churn existing documentation.
- Key type: the method hashes four bytes and compares a 32-bit stored key. `const int& key` remains a plausible source-facing parameter if the final API wraps the out-result ABI. Docs should state the binary key input is a pointer to four bytes.
- Node layout: current `node + 0x08` key comparison and `node + 0x00` next traversal agree with `DATIndexVectorNode { next, prev, key, value }`; `value` at `+0x0c` is consumed by MiniMapVersionManager and MonsterImageLib callers, not by this helper body.
- Bucket layout: current bucket access at `m_bucketsBegin + 8 * index`, first at `+0x00`, last at `+0x04`, and stop rule using `last->next` agree with `DATIndexVectorBucket { first, last }`.
- Ownership: the direct callers are a minimap version lookup wrapper and two calls inside MonsterImageLib archive/bounds loading. This spread supports shared `DATIndexVector` ownership and rejects feature-specific ownership.
- Formal C++ blocker: behavior is source-ready, but method-body C++ should wait. A pointer-return body would misrepresent observed `retn 8`/out-slot ABI; an exact ABI body would expose a compiler/decompiler result-object implementation detail unless the project first decides the source-facing return wrapper.
- Rejected alternatives:
  - MiniMapVersionManager owner: rejected because MonsterImageLib also calls the same function.
  - MonsterImageLib owner: rejected because minimap also calls it and the helper uses only DATIndexVector fields.
  - DATFileMgr/archive owner: rejected because no DATFileMgr-only state appears and callers include non-DAT feature code.
  - LinkedList/STL owner: rejected because the function implements FNV-keyed bucket selection, not generic list traversal alone.
  - No-owner/non-emitting: rejected because the method is reconstructable class logic and current owner/emitter metadata is supported.
  - Immediate formal C++: rejected for this pass because exact source API/return-shape remains unresolved after checking callers, class docs, generated output, and IDA type state.

## Evidence Standards Used
- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Active evidence session: `b006-0000xu`.
- `server_health` returned `status:"ok"`, IDB `E:\Desktop\Clone\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`.
- Evidence types used: exact-address MCP function lookup, decompile, disassembly, xrefs, callee query, raw bytes, type inspection, entity/name query, current by-* docs, generated output as read-only context, and prior executed B reports as leads.
- Evidence ladder: direct MCP facts prove range, ABI, xrefs, no-callee status, byte padding, and algorithm; by-* docs support source-facing names and owner/file routing; inference is used only for original source API spelling and final declaration shape.
- Tool limitations: current MCP session does not provide original PDB symbols or durable `DATIndexVector` type definitions. Current `type_inspect` reports the three target type names are not present in IDA.

## Evidence Checked
- IDA MCP checks performed:
  - `initialize` and `tools/list` against MCP.
  - `idb_list`: initial stale session `19917133`; final active session `b006-0000xu`.
  - `server_health b006-0000xu`.
  - `lookup_funcs 0x00457580`: `sub_457580`, size `0x93`.
  - `analyze_function 0x00457580`: prototype `_DWORD *__thiscall(_DWORD *this, _DWORD *, unsigned __int8 *)`, size `147`, no callees, callers `sub_4570B0` and `sub_4DBE60`, xrefs to `0x4570c2`, `0x4dbe9d`, `0x4dc139`.
  - `decompile 0x00457580`: four-byte FNV-1a hash, bucket mask, bucket first/last scan, key compare, result-slot store.
  - `disasm 0x00457580` with `max_instructions=80`: 58 instructions, both exits `retn 8`, full body within `0x00457580-0x00457613`.
  - `xrefs_to` and `xref_query` for `0x00457580`: exactly three code xrefs, no more.
  - `callees 0x00457580`: empty.
  - `lookup_funcs` for direct callers and neighbors: `0x004570b0`, `0x004dbe60`, `0x00457550`, `0x00457620`, plus sibling DATIndexVector functions.
  - `analyze_function` and bounded `disasm` for `0x004570b0`: pushes key address and out-slot, calls target, dereferences `[eax]`, compares to sentinel at `this+0x4c`, returns payload at `+0x0c`.
  - `analyze_function` and paged `disasm` for `0x004dbe60`: calls target at `0x004dbe9d` and `0x004dc139` with the same result-slot/key-address pattern.
  - `get_bytes` at `0x0045757d` and `0x00457613`: three pre-function and thirteen post-function `0xcc` bytes; bulk byte read confirms the target body bytes and two `c2 08 00` returns.
  - `type_inspect` for `DATIndexVector`, `DATIndexVectorNode`, and `DATIndexVectorBucket`: all `Type not found`.
  - `entity_query` for function/name `DATIndexVector|457580|sub_457580`: one function `sub_457580`; no matching named symbols.
- Documentation/generated checks:
  - target page `0000XX`;
  - DATIndexVector class/file and node/bucket pages;
  - minimap direct caller page `0000XQ`;
  - MonsterImageLib class and `00017E` target;
  - generated `auto-generated/NexusTK/archive/DATIndexVector.cpp`;
  - tracker and auto-completion stats context.
- Old report searches:
  - Search terms used: `0000XX`, `0x00457580`, `DATIndexVectorFindNodeByKey`, `FindNodeByKey`, `sub_457580`, and `DATIndexVector`.
  - Directly relevant opened reports: B009 `00003K-DATIndexVector-class-source-quality.md`, B002 minimap version-manager report, and B003 `00017E-MonsterImageLibGetArchiveBoundsBucket-source-quality.md`.
- Failed, unavailable, or intentionally skipped checks:
  - Initial MCP calls against session `19917133` failed with `Session not found`; not used as fallback evidence.
  - No IDA renames, type applications, comments, DB saves, or other IDA DB edits were made.
  - Original report-only pass ran no validators because no by-* docs were edited. Implementation callback validator results are recorded below.
  - No `execute_report`, lifecycle, registry, archive, dry-run, probing, or equivalent commands were run.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | `0000XX` remains exact range `0x00457580-0x00457613`, size `0x93`, with three leading and thirteen trailing `0xcc` padding bytes. | High | MCP `lookup_funcs`, `disasm`, `get_bytes` session `b006-0000xu`. | target `Boundary` / `Live Evidence` | incorporate | applied |
| C02 | The body hashes exactly four key bytes with FNV-1a seed `0x811c9dc5` and multiplier `0x01000193`, then masks by `m_bucketMask`. | High | MCP decompile/disasm `0x00457580`. | target `Behavior` / `Layout Evidence` | incorporate | applied |
| C03 | The callee ABI uses result-slot plus key-address stack arguments and returns with `retn 8`; callers dereference `[eax]` after the call. | High | Target disasm; caller disasm at `0x004570b0`, `0x004dbe60`. | target `Behavior`, `Autogen And C++ Handling`; class/file method notes | incorporate | applied |
| C04 | Existing historical `retn 4` wording is stale for this target; both target exits are `retn 8`. | High | Target disasm shows returns at `0x457605` and `0x457610`. | target `Changes` / historical correction | historicalize | applied |
| C05 | Direct xrefs are exactly `0x4570c2`, `0x4dbe9d`, and `0x4dc139`; target has no external callees. | High | `xrefs_to`, `xref_query`, `callees`, `analyze_function`. | target `Live Evidence` / `Caller Ownership Audit` | incorporate | applied |
| C06 | DATIndexVector ownership remains correct; feature-specific ownership is rejected. | High | Caller fanout across minimap and MonsterImageLib; target accesses DATIndexVector fields only. | target `Ownership Decision` / `Rejected Alternatives`; support notes keep file route | already-present plus refreshed evidence | applied |
| C07 | Formal method-body C++ should remain blank until the source API decides pointer-return wrapper versus iterator/result-object return. | Medium-high | `retn 8`/out-slot ABI, no IDA type definitions, generated declaration read-only context. | target `Autogen And C++ Handling`; class/file method notes | incorporate | applied |
| C08 | Recommended target score is `88/91`; owner/emitter/reconstructable stay unchanged. | Medium-high | Fresh MCP evidence resolves current ABI/no-code blocker but not exact source API. | target metadata / score rationale | incorporate | applied |

## Positive Evidence Summary
- Direct facts supporting the recommendation: exact current MCP function identity, full bounded disassembly, current decompile, xref set, no callees, caller use patterns, and boundary bytes all support the existing DATIndexVector method role.
- Corroborating documentation evidence: class/file/support struct pages already model the unified 0x20-byte DATIndexVector object, node/bucket layouts, and broad caller fanout. MiniMap and MonsterImageLib docs both treat this helper as a shared dependency.
- Strongest inference chain: the body uses only DATIndexVector fields and is called from two independent feature owners; therefore it is a shared class method. The same evidence also proves why formal C++ is not yet safe: the behavior is clear, but the observed ABI is not the raw pointer-return API currently printed in generated class declarations.

## IDA MCP Facts
- Function/range facts: `sub_457580`, `0x00457580`, size `0x93`, 58 instructions, end-exclusive `0x00457613`.
- Data/table/padding facts: no data xrefs from the target; pre-function bytes at `0x0045757d-0x00457580` are `cc cc cc`; post-function bytes at `0x00457613-0x00457620` are thirteen `cc` bytes.
- Xref facts: code xrefs to target are `0x004570c2` in `sub_4570B0`, `0x004dbe9d` in `sub_4DBE60`, and `0x004dc139` in `sub_4DBE60`.
- Vtable/global/type facts: `type_inspect` finds no IDA UDTs named `DATIndexVector`, `DATIndexVectorNode`, or `DATIndexVectorBucket`; `entity_query` finds no durable names beyond `sub_457580`.
- Negative IDA facts: no external callees; no IDA type proof for final API; no extra xrefs beyond the three direct code callers.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00457580-0x00457613` | [UID:0000XX] `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md` | DATIndexVector keyed bucket lookup | true | [UID:00003K] `DATIndexVector` | applied `88/91` | target evidence and no-code proof updated |
| `0x004570b0-0x004570e0` | [UID:0000XQ] minimap lookup wrapper | consumer of target through `m_versionIndex` | true | [UID:00008H] `MiniMapVersionManager` | `88/92` | no required edit |
| `0x004dbe60-0x004dc174` | [UID:00017E] MonsterImageLib bounds bucket loader | consumer of target through `m_boundsBucketIndex` | true | [UID:00008N] `MonsterImageLib` | `88/91` | no required edit |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004570c2` | call from `sub_4570B0` / [UID:0000XQ] | MiniMapVersionManager uses embedded DATIndexVector at `this+0x48`, compares returned node against sentinel at `this+0x4c`, returns node payload at `+0x0c`. |
| `0x004dbe9d` | first call from `sub_4DBE60` / [UID:00017E] | MonsterImageLib checks the bounds-bucket cache at `this+0x3c` before constructing `DATA/MON%d.DAT` state. |
| `0x004dc139` | second call from `sub_4DBE60` / [UID:00017E] | MonsterImageLib returns the cached or newly inserted bucket payload through node `+0x0c`. |
| target callees | none | Pure lookup body; no helper ownership is imported from callees. |

## Documentation Evidence And IDA Status
- Existing docs supporting the conclusion:
  - Target page already records FNV-1a behavior, bucket/list layout, DATIndexVector ownership, minimap and monster-image callers, and blank C++ caveats.
  - `by-class/DATIndexVector.md` currently has the unified object layout and class declaration.
  - `by-file/DATIndexVector.md` routes the class through `NexusTK/archive/DATIndexVector.cpp` and lists this target as a method.
  - `DATIndexVectorNode` and `DATIndexVectorBucket` pages support the `next/prev/key/value` and `first/last` interpretations.
- Existing docs that are stale or incomplete:
  - Target historical change note says `retn 4`; current target disassembly shows `retn 8`.
  - Target/class docs should be clearer that pointer-returning `FindNodeByKey(const int& key)` is a source-facing convenience candidate, while the observed ABI returns through a result slot.
  - Generated output still emits `0000XX` as an empty marker and does not contain a body-level no-code proof.
- Generated/coverage state: `auto-generated/NexusTK/archive/DATIndexVector.cpp` was refreshed by validator command id `000000006679` at `2026-07-05T02:31:48-04:00`; it contains `UID:0000XX` as an empty emitter marker.

## Ranked Ownership Analysis

### 1. [UID:00003K] DATIndexVector
- Evidence for: target reads DATIndexVector layout fields at `+0x04`, `+0x0c`, and `+0x18`; uses DATIndexVector node/bucket semantics; direct callers are consumers from multiple feature owners; class/file/support docs already clear the ownership gate.
- Evidence against: original symbol/type records are unavailable in current IDA. This affects exact source API spelling, not owner.
- Decision: accepted owner and emitter.

### 2. [UID:0000IP] DATIndexVector file route
- Evidence for: class owner emits through this file; generated output is `auto-generated/NexusTK/archive/DATIndexVector.cpp`; file page lists the method family and supports standalone route.
- Evidence against: final folder may eventually be common/util instead of archive due broad fanout.
- Decision: accepted source file route through class; no path change recommended.

### 3. MiniMapVersionManager / MonsterImageLib feature owners
- Evidence for: each is a direct caller and has a clear payload interpretation for node `+0x0c`.
- Evidence against: neither owns both call families, and neither owns the bucket/list layout. They pass a `DATIndexVector` subobject to the shared helper.
- Decision: rejected as owners; keep as consumers/cross-references.

### 4. LinkedList / runtime support
- Evidence for: target scans intrusive next links and returns a sentinel-like list node.
- Evidence against: function hashes keys, selects DATIndexVector buckets, uses `m_bucketMask`, and compares node keys. This is not a generic list helper.
- Decision: rejected.

### 5. No-owner/non-emitting
- Evidence for: exact source API spelling is unresolved.
- Evidence against: behavior and ownership are strong; target is custom source-authored class logic and already reconstructable/emitting.
- Decision: rejected.

## Source Placement
- Recommended placement: `DATIndexVector::FindNodeByKey` under [UID:00003K] `DATIndexVector`, emitted through [UID:0000IP] `NexusTK/archive/DATIndexVector.cpp`.
- Why this placement fits: it is a reusable keyed index method over class fields, and both minimap and monster-image code use it as a dependency.
- Rejected placements: `MiniMapVersionManager.cpp`, `MonsterImageLib.cpp`, `DATFileMgr.cpp`, `LinkedList` support, and generated no-owner output.
- Remaining placement uncertainty: final folder/header visibility and exact method signature are source-polish blockers. They do not block owner/emitter.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts:
  - previous function `sub_457550` is `0x00457550`, size `0x2d`;
  - bytes `0x0045757d-0x00457580` are `cc cc cc`;
  - target starts at `0x00457580`, size `0x93`, end-exclusive `0x00457613`;
  - bytes `0x00457613-0x00457620` are thirteen `0xcc` bytes;
  - next function `sub_457620` starts at `0x00457620`.
- Children/subranges: no split, merge, new child, ignored subrange, or padding page is recommended.
- Padding/table/data/code distinctions: the assigned range is executable code; surrounding `0xcc` bytes are alignment/padding, not target body.
- Parent/container impact: no parent/container split change. The target only needs evidence/source-quality text updates.

## Negative Evidence Summary
- The minimap caller does not prove minimap ownership because MonsterImageLib also calls the target and the body uses only DATIndexVector fields.
- The MonsterImageLib callers do not prove monster-image ownership because minimap also calls the target and the body is not archive-specific.
- No IDA type named `DATIndexVector` exists in this session, so class/type names remain documentation inference.
- No current evidence proves a raw pointer-return ABI for this exact function. The stack/result-slot ABI and `retn 8` argue against adding pointer-return body C++ now.
- No xref or callee evidence supports widening, splitting, or reclassifying the target.

## IDA Rename / Type / Comment Recommendations
- Source-facing documentation names to keep:
  - function: `DATIndexVectorFindNodeByKey` / `DATIndexVector::FindNodeByKey`;
  - key parameter: `key`;
  - result concept: `node`, `result`, or iterator-like one-slot result object until final API is decided;
  - fields: `m_listHead`, `m_bucketsBegin`, `m_bucketMask`;
  - support types: `DATIndexVectorNode`, `DATIndexVectorBucket`.
- Evidence for each: current MCP decompile/disasm and existing class/support docs.
- Items intentionally left unchanged:
  - no IDA DB rename/type/comment edit is requested in this report-only pass;
  - do not force IDA UDTs during the report-only pass;
  - do not rename the source API to a new original-looking name without stronger evidence.
- Whether IDA DB edits are safe: not requested. If a future IDA pass is approved, `sub_457580 -> DATIndexVectorFindNodeByKey` is high-confidence, but type application should wait for the return-shape decision.

## First-Draft C++ Recommendation
- Eligible for draft C++: metadata and owner/emitter route make the target potentially eligible.
- Recommended code: keep the formal `RECONSTRUCTION_CPP CODE` block blank for this exact method in this pass.
- Third-party import directive: not applicable.
- Reason it preserves exact original behavior: leaving the block blank avoids emitting a body whose source API conflicts with the observed binary ABI.
- Reason it matches plausible mid-2000s source shape: the likely human source would call a small `FindNodeByKey`/iterator-style method, not expose a decompiler-shaped `_DWORD* result` ABI. That source shape needs the class API decision first.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `DATIndexVector`, `FindNodeByKey`, `DATIndexVectorNode`, `DATIndexVectorBucket`, `m_listHead`, `m_bucketsBegin`, `m_bucketMask`, `key`.
- Naming/coding style convention used: current DATIndexVector docs use `m_` member names and `DATIndexVector*` support types; keep that convention.
- Reason code should remain blank:
  - The observed target has two stack arguments, returns the address of the result slot, and uses `retn 8`.
  - Callers dereference `[eax]` after the call; this looks like a returned one-field result object/iterator or compiler-lowered out-result form.
  - Current generated class declaration exposes `DATIndexVectorNode* FindNodeByKey(const int& key) const`, but current MCP does not prove that exact declaration was the original source signature.
  - A raw exact body would include result-slot mechanics and look decompiler-shaped. A clean pointer-return body would likely not match the observed ABI without a wrapper/iterator explanation.
- Exact no-code proof: all reasonable current evidence routes were checked: target decompile, full target disassembly, byte padding, direct caller disassembly, xrefs, no-callee query, IDA type/name query, current DATIndexVector class/file docs, node/bucket support docs, generated output, minimap consumer docs, MonsterImageLib consumer docs, and old B reports. These prove behavior and owner, but not a source-ready return type. Formal C++ should wait until the DATIndexVector API is resolved as pointer-return wrapper versus iterator/result-object return.

## Final Recommendation
- Exact changes recommended:
  - update target score to `88/91`;
  - keep `CANONICAL_OWNER:00003K`;
  - keep `RECONSTRUCTABLE:TRUE`;
  - keep `EMITTER_UIDS:00003K`;
  - keep blank `EMITTER_POSITION_OPTIONAL`;
  - keep formal C++ blank with the no-code proof above;
  - update live evidence from current MCP session `b006-0000xu`;
  - correct/historicalize the stale `retn 4` wording to `retn 8`;
  - add caller ABI details showing result-slot/key-address pushes and post-call `[eax]` dereference.
- Exact parent assignments recommended: no owner/emitter/parent change.
- Exact items left no-owner/non-emitting and why: none.
- Exact future work outside this assignment scope: a later accepted implementation or separate class API pass should decide the formal source signature/iterator wrapper and then add method C++ if safe.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md`.
- Exact report facts to incorporate:
  - MCP session `b006-0000xu` health and stale-session note;
  - `lookup_funcs` identity `sub_457580`, size `0x93`;
  - decompile/disasm evidence for four-byte FNV-1a, bucket mask, bucket first/last scan, stop rule, key compare, matching/sentinel result store;
  - full ABI note: two stack arguments, result slot plus key pointer, both exits `retn 8`, callers dereference `[eax]`;
  - xref set: `0x4570c2`, `0x4dbe9d`, `0x4dc139`;
  - no-callee fact;
  - `get_bytes` padding facts;
  - `type_inspect` and `entity_query` negative facts showing no IDA UDT/name proof;
  - generated-output state: `0000XX` still empty marker in `auto-generated/NexusTK/archive/DATIndexVector.cpp`.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:85` -> `COMPLETION:88`;
  - `CONFIDENCE:90` -> `CONFIDENCE:91`;
  - owner/emitter/reconstructable unchanged;
  - formal C++ remains blank.
- Suggested Item Summary replacement:
  - `Current MCP session b006-0000xu confirms the exact 0x93-byte DATIndexVector keyed bucket lookup at 0x00457580-0x00457613: it hashes four key bytes with FNV-1a, masks by m_bucketMask, scans the selected DATIndexVectorBucket first/last range, compares node->key at +0x08, writes either the matching node or m_listHead sentinel through a caller result slot, and has exactly three code callers from MiniMapVersionManager and MonsterImageLib; owner/emitter remain DATIndexVector, while formal C++ stays blank until the source API resolves the observed out-result/iterator-style retn 8 ABI versus the current pointer-returning declaration.`
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - historical `retn 4` wording should be corrected to `retn 8`;
  - keep feature-owner rejection;
  - keep final folder/header/source-name caveats;
  - preserve that generated pointer-return declaration is source-facing convenience, not exact ABI proof.

## Recommended Support Doc Changes
- `by-class/DATIndexVector.md`:
  - Add a method note that current MCP for [UID:0000XX] observes a result-slot/key-pointer ABI and `retn 8`; the current declaration `DATIndexVectorNode* FindNodeByKey(const int& key) const` remains a source-facing convenience candidate, not a final method-body proof.
  - No score change required.
- `by-file/DATIndexVector.md`:
  - Optional no-score support note that `FindNodeByKey` remains an empty marker until the class API chooses the source-level return wrapper; do not move the method out of `DATIndexVector.cpp`.
- `by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md`:
  - No required edit. Its current C++ and caveat already state helper call spelling may need adjustment if DATIndexVector uses an out-parameter wrapper.
- `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`:
  - No required edit. If touched for context, add only that current [UID:0000XX] evidence confirms the helper's out-result lookup ABI and reinforces the existing no-code proof for high-level cache APIs.
- `by-type/by-struct/DATIndexVectorNode.md` and `by-type/by-struct/DATIndexVectorBucket.md`:
  - No required edit. Their field evidence remains correct; target caller evidence supports the same `key` and `value` caveats.
- Generated reports and generated C++:
  - Do not edit directly. A later scoped validator after accepted implementation should refresh generated metadata.

## Score And Metadata Recommendation
- Current score/metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:00003K`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00003K`
  - blank formal C++.
- Recommended score/metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - owner/emitter/reconstructable/emitter-position unchanged;
  - formal C++ remains blank.
- Score rationale and reason not higher/lower:
  - Upward movement is justified because the report adds current MCP-backed ABI proof, caller disassembly, padding bytes, no-callee confirmation, stale `retn 4` correction, IDA type/name negative checks, and an exact no-code proof.
  - Do not go higher because original source symbols, durable IDA types, exact public/private header visibility, and exact method return API remain unresolved.
  - Do not go lower because owner, behavior, range, caller set, and layout are all strong.
- Score-improvement attempt:
  - Boundary blocker: resolved with `lookup_funcs`, `disasm`, and `get_bytes`.
  - Ownership blocker: already resolved, revalidated with current xrefs and caller docs.
  - Source-signature blocker: actively investigated through target/caller disassembly, generated output, class docs, type inspection, and prior reports; converted into implementation-ready no-code/API-resolution plan.
  - Formal C++ blocker: not left as a vague future task; exact unsafe alternatives and required future evidence are documented.
- Metadata fields to change or leave unchanged:
  - change only completion/confidence if accepted;
  - leave owner, reconstructable, emitter, and emitter position unchanged.

## Open Questions With Attempted Resolution
- Open question: should this target get formal C++ now?
  - Evidence checked: current decompile/disasm, caller disasm, class declaration, generated output, old reports, IDA type/name checks.
  - Best supported resolution: no. The algorithm is source-ready, but the exact source API is not. Keep C++ blank until the return wrapper is decided.
  - Score/C++ impact: score can rise to `88/91`; C++ stays blank.
- Open question: is pointer-returning `FindNodeByKey(const int& key) const` wrong?
  - Evidence checked: current generated declaration and consumer C++ use that form; current binary ABI uses result slot and `retn 8`.
  - Best supported resolution: treat pointer-returning form as source-facing convenience candidate, not exact proof. Do not remove it without a wider class API callback.
  - Score/C++ impact: confidence cap remains.
- Open question: can original type names be proven now?
  - Evidence checked: `type_inspect` and `entity_query`.
  - Best supported resolution: no. Names remain documentation inference, but they are stable and well-supported by behavior/caller context.
- Open question: does stale MCP state invalidate the evidence?
  - Evidence checked: MCP playbook, listener/process checks, failed stale session calls, final active session calls.
  - Best supported resolution: no. The stale session was not used for evidence; final proof is from active session `b006-0000xu`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Manual edits are not applicable. Do not edit manual `-coverage-report.md` files or validator-owned `auto-generated/-ag-*` reports.
- Scoped validators refreshed projected stats and `auto-generated/NexusTK/archive/DATIndexVector.cpp`; no manual tracker/coverage text was edited.

## Follow-Up Actions
- Supervisor actions: Gate 2 review this implementation callback package and decide whether to execute/incorporate downstream lifecycle steps.
- A-agent actions: none required.
- Future B-agent/source API action: resolve `DATIndexVector::FindNodeByKey` source API shape before method-body C++ is written. Candidate directions are a pointer-returning wrapper with documented ABI lowering, or an iterator/result-object return that matches current `retn 8` more directly.

## Confidence
- Recommendation confidence: high for evidence update, ownership, score move, and blank-C++ disposition.
- Score confidence: medium-high for `88/91`; exact score could reasonably be `87/91` if supervisor wants to reserve completion movement for the actual by-* callback.
- Remaining uncertainty: original source symbol/API spelling, final header visibility of node/bucket structs, and whether generated class declaration should eventually shift from raw pointer return to an iterator/result wrapper.

## Validator Results
- Target validator:
  - Command: `python .\tools\validator.py --mode file --file by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md --apply --queue-timeout 240`
  - Command timestamp: `2026-07-05T02:57:37-04:00`
  - Command ID: `000000006686`
  - Exit code: `0`
  - Result: `ok: 1`, `completion_update: 1`, `confidence_update: 1`, `uid_link_insert: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`
  - Warnings/errors: none reported.
  - Generated refresh: `deferred`, refresh command ID `000000006686`, timestamp `2026-07-05T02:57:37-04:00`.
- Class validator:
  - Command: `python .\tools\validator.py --mode file --file by-class/DATIndexVector.md --apply --queue-timeout 240`
  - Command timestamp: `2026-07-05T02:57:45-04:00`
  - Command ID: `000000006687`
  - Exit code: `0`
  - Result: `ok: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`
  - Warnings/errors: none reported.
  - Generated refresh: `deferred`, refresh command ID `000000006687`, timestamp `2026-07-05T02:57:45-04:00`.
- File validator:
  - Command: `python .\tools\validator.py --mode file --file by-file/DATIndexVector.md --apply --queue-timeout 240`
  - Command timestamp: `2026-07-05T02:57:56-04:00`
  - Command ID: `000000006688`
  - Exit code: `0`
  - Result: `ok: 1`, `uid_link_update: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`
  - Warnings/errors: none reported.
  - Generated refresh: `deferred`, refresh command ID `000000006688`, timestamp `2026-07-05T02:57:56-04:00`.
- Generated freshness state after validators: `auto-generated/NexusTK/archive/DATIndexVector.cpp` was refreshed by validator command ID `000000006688` at `2026-07-05T02:57:56-04:00` with `validator-refresh-source: deferred-generated-refresh`. It now shows `UID:0000XX` at `Completion:88 | Confidence:91 | Empty Emitter Marker`. The target's formal C++ remains blank.
- Projected stats state: validators updated `project-level/-auto-completion-stats.md` projected path completion sections. No manual `-coverage-report.md`, generated report, registry/state, lifecycle/archive, or executed-report files were edited.
- Score before/after: target `85/90 -> 88/91`; class `88/90` unchanged; file `88/88` unchanged.

## Lease Results
- Leases acquired:
  - `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md`: `Success`; current lease report recorded `2026-07-05T06:52:43Z` to `2026-07-05T06:57:43Z`.
  - `by-class/DATIndexVector.md`: `Success`; current lease report recorded `2026-07-05T06:54:48Z` to `2026-07-05T06:59:48Z`.
  - `by-file/DATIndexVector.md`: `Success`; current lease report recorded `2026-07-05T06:54:48Z` to `2026-07-05T06:59:48Z`.
- Release command: `python .\tools\leaser\leaser.py B007 unlease`
- Release result: class and file leases released with `Success`; the target lease had reached expiration by the release command and was purged by leaser state handling. Final `current_leases.md` at `2026-07-05T02:58:29-04:00` reports no active leases.

## Changed Files
- Created during Gate 1 report-only pass: `tools/leaser/Agents/Agent-B007/research/0000XX-DATIndexVectorFindNodeByKey-source-quality.md`.
- Modified by B007 implementation callback:
  - `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md`
  - `by-class/DATIndexVector.md`
  - `by-file/DATIndexVector.md`
  - `tools/leaser/Agents/Agent-B007/research/0000XX-DATIndexVectorFindNodeByKey-source-quality.md`
- Validator/tool-generated updates:
  - `auto-generated/NexusTK/archive/DATIndexVector.cpp`
  - `project-level/-auto-completion-stats.md`
  - leaser runtime/current-lease state files via `leaser.py`
- Renamed: none.
- Report execution: not run. `execute_report`, dry-run/probing execute variants, lifecycle/registry/archive commands, manual report moves, generated-report edits, and coverage-report edits were not run.

## Implementation Tracking Checklist
- [x] Supervisor validation required before implementation: Gate 1 passed for SHA256 `2FE9AD699A40FEA98FD30003E8509EEE92924E163DDF3FB8B3A73F89261B6F8F`.
- [x] Target/support docs to update: target `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md`, `by-class/DATIndexVector.md`, and `by-file/DATIndexVector.md` updated; no MiniMapVersionManager, MonsterImageLib, node/bucket docs, manual coverage docs, generated reports, or lifecycle/archive files were manually edited.
- [x] Current target state and actual evidence checked recorded: MCP session `b006-0000xu`, stale session handling, function lookup, decompile/disasm, xrefs, no callees, bytes, type/name negative checks, and generated-output state are incorporated.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C01-C08 are `applied`.
- [x] Metadata/score changes applied: target `85/90 -> 88/91`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched and documented: source-signature/C++ blocker converted to exact no-code/API-resolution plan.
- [x] Owner/emitter/reconstructable changes applied or confirmed not applicable: preserved [UID:00003K] owner/emitter and reconstructable true.
- [x] Split/rename/new-child changes applied or confirmed not applicable: none; exact range and padding preserved.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable: target range/padding evidence updated, stale `retn 4` note historicalized, no IDA DB edits.
- [x] First-draft C++ or no-code proof applied: formal C++ remains blank with exact out-result/iterator-style `retn 8` ABI proof.
- [x] Third-party import directive applied or confirmed not applicable: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: target summary, behavior, live evidence, caller inventory, C++ handling, score rationale, changes, and class/file support caveats updated.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: historical `retn 4` wording corrected/historicalized; feature-owner/LinkedList/no-owner and immediate-C++ alternatives rejected with reasons.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated output read as current emission state only, not source authority.
- [x] Open questions closed or documented as evidence-backed unresolved: ownership/range closed; exact source API remains unresolved with C++ impact documented.
- [x] Validators run after accepted implementation: target, class, and file scoped validators all exited `0` with `ok: 1`.
- [x] Generated refresh state recorded: `auto-generated/NexusTK/archive/DATIndexVector.cpp` refreshed under deferred generated refresh command `000000006688`; `0000XX` remains an empty marker at `88/91`; no manual coverage/tracker text is recommended.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated refresh completed by validator as deferred-generated-refresh and recorded; no manual supervisor-owned coverage/tracker text supplied.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000006723","destination_path":"executed-b-agent-research/B007/0000XX-DATIndexVectorFindNodeByKey-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000XX-DATIndexVectorFindNodeByKey-source-quality.md","timestamp":"2026-07-05T03:15:17-04:00","uid":"0000XX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
