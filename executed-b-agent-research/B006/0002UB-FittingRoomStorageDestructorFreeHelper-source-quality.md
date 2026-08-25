** TARGET-REPORT-UID:0002UB **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002UB FittingRoomStorageDestructorFreeHelper Source-Quality Report

## Report Scope

- Assignment id: `B006-report-0002UB-fitting-room-storage-destructor-free-helper-20260624`
- Mode: report-only research first.
- Target: [UID:0002UB] `by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md`
- Required report path: `tools/leaser/Agents/Agent-B006/research/0002UB-FittingRoomStorageDestructorFreeHelper-source-quality.md`
- Write scope honored: this report is the only edit made for this pass. No target/support by-* docs, generated files, project-level files, validator/tool state, IDA DB state, leases, or coverage reports were edited.

## Summary Recommendation

Current target metadata:

| Field | Current value |
| --- | --- |
| Completion | `85` |
| Confidence | `88` |
| Canonical owner | `000051` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `000051` |
| Emitter position | blank |
| Formal C++ | blank |

Recommended target metadata:

| Field | Recommended value |
| --- | --- |
| Completion | `88` |
| Confidence | `91` |
| Canonical owner | `000051` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `000051` |
| Emitter position | blank |
| Formal C++ | blank |

Recommended source-facing role: item-state category-lookup storage destructor/free support for `m_categoryLookup` at item-state offset `+0x220`. The helper destroys the category lookup's bucket/backing vector, clears/destroys the intrusive category-node list through `0x00423d70`, and frees the 24-byte sentinel/root node.

Formal C++ recommendation: keep the target formal C++ block blank. Do not add sample, illustrative, draft, body-side, or formal code for [UID:0002UB]. No formal struct/type C++ is recommended in this report.

The previous open questions are resolved enough for target documentation: this is not an `ItemCatalog` method, not the equipment-entry vector destructor, not a mixed-aggregate owner, and not a standalone handwritten source API. It is compiler/container cleanup for a source-declared item-state category lookup member. The source-facing destructor behavior belongs to [UID:0002EB], while [UID:0002UB] should document the generated member-destruction details.

## MCP Provenance

Current IDA MCP was available and used.

| Item | Value |
| --- | --- |
| MCP JSON-RPC session | `b4379a4e-7e93-4295-b4f3-15eb281f8b17` |
| Active database session | `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Server health | `ok`; auto-analysis ready; Hex-Rays ready |
| Evidence timestamps | 2026-06-24 `15:26-15:29` America/New_York |
| Tools used | `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xref_query`, `find_bytes`, `get_bytes` |

No IDA mutating tools were used.

## Current State And Existing Support

The target page currently has useful June 7 evidence but leaves several questions as open: storage field names, nested block/type names, relation to `0x00423d70`, and final C++ readiness. Current [UID:000051] `FittingRoomDialogItemState` and [UID:0000JE] `FittingRoom` support docs have advanced since that state:

- [UID:000051] now records `m_categoryLookup` at item-state offset `+0x220`, separate `m_equipmentEntries` at `+0x240/+0x244/+0x248`, `m_cacheLoaded`, encode/decode keys, the 0xc0 category-entry layout, the six-byte part-record layout, and category-node helper routing.
- [UID:000051] also records accepted inferred names `FittingRoomCategoryNode` and `FittingRoomCategoryTransferRecord` from the recent [UID:0002U4] source-quality pass. Those names are sufficient for prose/layout documentation, but they do not make this destructor/free helper a standalone source API.
- [UID:0000JE] keeps the file route as `NexusTK/cashshop/FittingRoom.cpp`; direct ownership for exact item-state category-storage children goes through [UID:000051].
- [UID:0002EE] is still a non-reconstructable mixed aggregate over exact child pages. It remains address-containment context only, not a direct owner for [UID:0002UB].

The generated memory coverage row already routes [UID:0002UB] as emitting under `000051` to `auto-generated/NexusTK/cashshop/FittingRoom.cpp` with an empty marker. That generated empty marker is consistent with the no-code recommendation below.

## Function And Boundary Evidence

Fresh MCP `lookup_funcs` confirms the exact target range:

| Probe | MCP result |
| --- | --- |
| `0x00423710` | function `sub_423710`, size `0x67` |
| `0x00423776` | still inside `sub_423710` |
| `0x00423777` | not a function |
| `0x00423800` | separate thunk `sub_423800`, size `0x5` |
| `0x00423805` | not a function |
| `0x00423810` | next modeled helper `sub_423810`, size `0x50` |

`get_bytes` for `0x00423710-0x00423777` returned 103 bytes, SHA-256 `ebd1cd10d0a6e5bc6ab573596f7c49fa8dd983a5b648eaf67f279e432c16dd02`, first 16 bytes `56 8b f1 8b 46 0c 85 c0 74 41 8b 56 14 2b d0 83`, and last 8 bytes `08 5e c3 e8 90 9e 1a 00`.

`disasm` reports 33 total instructions. The instruction anchors are:

| Address | Evidence |
| --- | --- |
| `0x00423713` | loads the category lookup backing/vector begin pointer from receiver offset `+0x0c`. |
| `0x0042371a-0x00423728` | computes the rounded allocation span from `+0x14 - +0x0c`, checks the `0x1000` large-allocation threshold. |
| `0x0042372a-0x0042373a` | validates the aligned-allocation header at `begin[-1]` and rejects front padding above `0x1f`. |
| `0x0042373e` | calls heap/free wrapper `0x005c7526` for the backing storage. |
| `0x00423743-0x00423754` | clears offsets `+0x0c/+0x10/+0x14`. |
| `0x0042375b-0x0042375e` | passes receiver offset `+0x04` to `0x00423d70`. |
| `0x00423763-0x00423768` | frees the 24-byte node/sentinel block stored at receiver offset `+0x04`. |
| `0x00423771` | normal return. |
| `0x00423772` | invalid-parameter noreturn path inside the target range. |

Boundary and split evidence:

- `0x00423777-0x00423780` is nine `0xcc` bytes.
- `0x00423780` is not part of this target; `lookup_funcs` assigns it to [UID:0002E7] constructor cleanup chunks under `sub_422020`.
- `0x004237a0` is not part of this target; `lookup_funcs` assigns it to [UID:0002E6] category-loader cleanup chunks under `sub_422BA0`.
- `0x00423800-0x00423805` is [UID:0002UC], a separate five-byte thunk to the target.
- `0x00423805-0x00423810` is eleven `0xcc` bytes before the next vector-storage helper.

This closes the split/range question. [UID:0002UB] should stay exactly `0x00423710-0x00423777`.

## Receiver Layout Used By This Target

The receiver is the item-state category lookup object at item-state offset `+0x220`, not the item-state object itself.

| Receiver offset | Size | Field role | Cleanup role in [UID:0002UB] | Evidence source |
| --- | ---: | --- | --- | --- |
| `+0x00` | 4 | category lookup load factor/config word | Not directly touched by this helper. Constructor writes `0x3f800000` and initializes buckets with count 8. | [UID:0002E7] constructor MCP/decompile and [UID:000051] class layout. |
| `+0x04` | 4 | sentinel/root node pointer for the category-node intrusive list | Passed as the base of the nested list controller to `0x00423d70`, then freed as a 24-byte block. | Target disasm `0x0042375b-0x00423768`; `0x00423d70` decompile. |
| `+0x08` | 4 | category-node count paired with the sentinel/list controller | Cleared by `0x00423d70` when [UID:0002UB] passes receiver `+0x04`. | `0x00423d70` decompile writes `this[1] = 0`; caller passes `this + 1`. |
| `+0x0c` | 4 | backing/bucket vector begin pointer | Tested, freed when non-null, and cleared. | Target disasm/decompile at `0x00423713`, `0x0042373e`, `0x00423743`. |
| `+0x10` | 4 | backing/bucket vector current/end field | Cleared after the backing allocation is freed. | Target disasm/decompile at `0x0042374d`. |
| `+0x14` | 4 | backing/bucket vector capacity/end field | Read for allocation span; cleared after free. | Target disasm/decompile at `0x0042371a-0x00423728`, `0x00423754`. |

The nested helper `0x00423d70` clears the category-node list rooted at receiver `+0x04`. Current MCP decompile shows it resets the sentinel links and count, then walks nodes until it returns to the sentinel. For each node, it frees the node payload vector at node offsets `+0x0c/+0x10/+0x14`, clears that triplet, and frees the node block. [UID:0002UB] then frees the sentinel/root block itself.

## Caller, Callee, And Required UID Relations

Fresh MCP `xref_query` reports exactly two xrefs to `0x00423710`:

| Xref | Relation |
| --- | --- |
| `0x00422415 -> 0x00423710` | Ordinary source caller inside [UID:0002EB] item-state destructor. |
| `0x00423800 -> 0x00423710` | [UID:0002UC] five-byte thunk. |

MCP `xref_query` for data references to `0x00423710` reports zero data xrefs. `find_bytes` for absolute and RVA-shaped address patterns `10 37 42 00` and `10 37 02 00` also reports zero matches. The same checks for the thunk start patterns `00 38 42 00` and `00 38 02 00` report zero matches.

Required relation matrix:

| UID | Relation to [UID:0002UB] |
| --- | --- |
| [UID:0002EB] item-state destructor | Direct ordinary caller. Fresh MCP decompile shows it calls the equipment-entry vector cleanup sibling at `0x0042240a`, then loads `this + 0x220` and calls [UID:0002UB] at `0x00422415`, then releases the catalog-version string. |
| [UID:0002EC] reset category entries | Not a caller of [UID:0002UB]. It performs logical reset: walks category nodes, destroys `0xc0` entries and their part vectors, calls `0x00423d70`, then reinitializes the lookup with 8 buckets. [UID:0002UB] is final object destruction: it frees bucket storage, calls the same clear helper, and frees the sentinel block without reinitializing. |
| [UID:0002EE] category-storage/string-helper aggregate | Address-containment context only. It remains mixed and non-reconstructable; exact children carry source placement. |
| [UID:0002UE] entry string/equipment vector destroy helper | Sibling destructor helper called immediately before [UID:0002UB] from [UID:0002EB]. It operates on item-state `+0x240/+0x244/+0x248` and `0xb4` equipment-entry storage, not category lookup storage. |
| [UID:0002UI] category tree node cleanup/free | Sibling category-node cleanup used by finalize/cleanup helpers at `0x004234fa` and `0x004236c7`. It shares the node payload-vector free pattern but is not called by [UID:0002UB]; [UID:0002UB] instead calls `0x00423d70` for whole-list clear. |
| [UID:000051] FittingRoomDialogItemState | Accepted direct owner. The only ordinary caller is the item-state destructor, and the receiver offset is documented as `m_categoryLookup`. |
| [UID:0000JE] FittingRoom | Accepted file root only. The source-family route is `NexusTK/cashshop/FittingRoom.cpp`; direct ownership should remain with [UID:000051]. |

The target callee set from `analyze_function` is `0x00423d70`, heap/free wrapper `0x005c7526`, and invalid-parameter noreturn `0x005cd607`.

## Source-Quality Interpretation

The best source interpretation is: category lookup member destruction generated from a source-declared item-state category lookup field.

What is resolved:

- Cleanup role: [UID:0002UB] is final destruction of the category lookup object, not reset/reuse.
- Owner route: [UID:000051] is the direct semantic owner; [UID:0000JE] is the file root.
- Helper/type naming: prose can safely use `m_categoryLookup`, category lookup, category-node list, bucket/backing vector, and 24-byte sentinel/root node. The newer `FittingRoomCategoryNode` name is accepted as inferred support vocabulary from [UID:0002U4], but this target does not need a new formal type declaration.
- Split/range: exact `0x00423710-0x00423777`; do not merge cleanup chunks, thunk, or neighboring vector helpers.
- C++ readiness: formal target C++ should remain blank by exact no-code proof below.

## Rejected Alternatives And Negative Checks

| Alternative | Decision | Evidence |
| --- | --- | --- |
| Handwritten public/source helper API for [UID:0002UB] | Rejected | No data refs, no VA/RVA pointer byte hits, no independent callers, and no original declaration/name proof. The only ordinary call is member teardown in the item-state destructor. |
| Compiler-only no-owner ignored helper | Rejected | The ordinary caller passes the item-state category lookup at `+0x220`, and [UID:000051] owns that source-declared member. The page should stay reconstructable evidence under [UID:000051], just without formal C++ body text. |
| [UID:0002EE] aggregate owner | Rejected | [UID:0002EE] mixes fitting-room category helpers, shared string/vector/DAT helpers, CRT/runtime support, cleanup chunks, and padding. It is non-reconstructable address containment. |
| [UID:0000KD]/[UID:00006T] ItemCatalog owner | Rejected | ItemCatalog is a facade/consumer over category lookup count/index behavior. It does not own item-state destructor storage or the `+0x220` lifetime. |
| [UID:0002UE] equipment-entry vector cleanup | Rejected | [UID:0002UE] is called at `0x0042240a` with item-state `+0x240`; [UID:0002UB] is called at `0x00422415` with item-state `+0x220`. |
| Merge with [UID:0002UC] thunk | Rejected | [UID:0002UC] is a separate five-byte jump thunk with its own exact page and no behavior beyond routing unwind metadata. |
| Merge with `0x00423780` or `0x004237a0` chunks | Rejected | Fresh lookup assigns those chunks to constructor/category-loader cleanup ownership, not this helper; padding separates the target from them. |
| Formal struct/type C++ insertion from this report | Rejected | The target is a destructor/free helper, not a type-documentation target. Existing support docs already carry inferred category-node vocabulary. Adding a formal type block here would be out of scope and would not be exact insertion text for this target. |

## Target-Specific No-Code Proof

Even after the recommended score increase, [UID:0002UB] should keep the formal C++ block blank.

Proof:

1. The source-facing item-state destructor is already represented by [UID:0002EB]. Its formal source shape should express the high-level reset behavior and rely on declared member destructors for category lookup, equipment vector, strings, and catalog version cleanup.
2. [UID:0002UB] contains allocation-header validation, raw heap-free calls, vector triplet clearing, sentinel/list clearing, and a 24-byte block free. Those are compiler/container implementation details for the category lookup member. A standalone target body would hand-port binary support internals instead of source logic.
3. Fresh MCP route checks found only one ordinary source call from [UID:0002EB] and one thunk edge from [UID:0002UC]. There are zero data xrefs and zero absolute/RVA pointer byte matches for both the target and thunk starts.
4. The helper has no proven original source function name or declaration route. Introducing a callable source helper for it would invent an API surface not supported by current evidence.
5. The target remains reconstructable because the binary range is regenerated from the accepted owner/emitter's source data model. Reconstructable status does not require a standalone formal C++ block when the exact target is compiler/container lifecycle output.

No formal struct/type C++ is recommended in this report. If a future type-declaration pass is approved, its destination should be an explicit support/type documentation target, not this destructor/free helper.

## Score Rationale

| Score field | Recommendation | Rationale |
| --- | ---: | --- |
| Completion | `88` | The current pass resolves the target's cleanup role, direct owner/emitter route, field layout used by the body, relation to all requested UIDs, split/range boundaries, callee set, no-route checks, rejected alternatives, and target-specific no-code proof. Not higher because original category lookup typedef/member spelling and `0x00423d70` final source-name policy remain inferred support vocabulary, and no formal C++ is recommended. |
| Confidence | `91` | Confidence is strong because current MCP confirms exact bounds, byte hash, full 33-instruction body, caller/xref set, zero data xrefs, zero VA/RVA pointer byte hits, sibling-helper relationships, and support-doc layout consistency. Not higher because original UDT symbols are absent and this remains generated member-cleanup support rather than a named source body. |

## Implementation Checklist For Future Callback

Implementation callback status: accepted and applied on 2026-06-24.

- [x] Update [UID:0002UB] metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep owner `000051`, emitter `000051`, reconstructable true, blank emitter position, and blank formal C++. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000051`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000051`, blank `EMITTER_POSITION_OPTIONAL`, and no text between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.
- [x] Incorporate the MCP provenance from session `b4379a4e-7e93-4295-b4f3-15eb281f8b17` / database `80de0a67`, including exact range, 103-byte SHA-256, 33-instruction disassembly, boundary padding, adjacent cleanup chunks, thunk separation, caller/xref data, and no pointer/data route checks. Proof: target sections `MCP Provenance`, `Function And Boundary Evidence`, and `Caller, Callee, And UID Relations` carry those details.
- [x] Replace target open questions with resolved prose: final category lookup member destruction; receiver is `m_categoryLookup` at item-state `+0x220`; target frees backing/bucket storage and the sentinel/list, while reset/reinit remains [UID:0002EC]. Proof: target sections `Behavior` and `Closed Questions` replace the old unresolved field/type/C++ questions with that disposition.
- [x] Add the receiver layout table for offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, `+0x10`, and `+0x14` with evidence sources. Proof: target section `Receiver Layout Used By This Target` contains all six rows and evidence sources.
- [x] Add the required UID relation matrix for [UID:0002EB], [UID:0002EC], [UID:0002EE], [UID:0002UE], [UID:0002UI], [UID:000051], and [UID:0000JE]. Proof: target section `Caller, Callee, And UID Relations` contains the relation matrix and callee set.
- [x] Add rejected alternatives and negative checks: no standalone API, no aggregate ownership, no ItemCatalog route, no equipment-vector merge, no thunk/chunk merge, no formal struct/type C++ from this report. Proof: target section `Source Placement And Rejected Alternatives` records each rejection and the negative xref/pointer checks.
- [x] Add the target-specific no-code proof and ensure the formal `RECONSTRUCTION_CPP CODE` block stays blank. Do not add sample, illustrative, draft, or body-side C++ anywhere in the target doc. Proof: target section `Target-Specific No-Code Proof` gives the five-point proof; scan found only the formal begin/end header markers and no body-side code fences or struct/class/code samples.
- [x] No support-doc edits are required by this report. Current [UID:000051], [UID:0000JE], [UID:0002EE], [UID:0002EB], [UID:0002EC], [UID:0002UE], and [UID:0002UI] docs already carry compatible or broader detail. Proof: no support docs were edited for this callback; no target-specific validator failure required a support correction.
- [x] Run the scoped validator named by the implementation callback. Proof: ran `python .\tools\validator.py --mode file --file by-memory\0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md --apply --queue-timeout 240` from `source-3/project-documentation`; command id `000000000528`, timestamp `2026-06-24T15:44:19-04:00`, exit code `0`, `ok: 1`, scanned markdown files `1`. Validator reported `generated_refresh: deferred`, `generated_refresh_command_id: 000000000528`, and `generated_refresh_timestamp: 2026-06-24T15:44:19-04:00`. B006's retained implementation changes are target/report only; generated/project-level/coverage/tool-state outputs are not part of this callback's changed-file set.
- [x] Lease proof. Proof: B006 held the target lease for the immediate edit/validator batch (`current_leases.md` showed B006 on the target from `2026-06-24T19:39:21Z` to `2026-06-24T19:44:21Z`); after validation, explicit unlease returned `Rejected[No active lease]` because the lease had already expired/cleared. Current lease report after cleanup no longer lists B006.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002UB-FittingRoomStorageDestructorFreeHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002UB-FittingRoomStorageDestructorFreeHelper-source-quality.md","timestamp":"2026-06-24T15:49:50","uid":"0002UB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
