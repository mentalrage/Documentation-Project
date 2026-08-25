** TARGET-REPORT-UID:00043J **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00043J ParcelIconPaneParcelUpdateRawHelper By-Memory Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00043J] `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md` as reconstructable `ParcelIconPane` source behavior with direct owner [UID:0000A5], but keep `EMITTER_UIDS` and formal `RECONSTRUCTION_CPP CODE` blank.
- Final disposition: raise target documentation from `84/88` to `88/90`; preserve `CANONICAL_OWNER:0000A5`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and an empty formal C++ block.
- Required action if accepted: update only the target page with the current B001 MCP evidence, negative route checks, score rationale, and exact no-code proof. The direct support pages already contain same-or-greater owner/source-family facts, so no support metadata changes are required.
- Confidence: high for behavior, range, owner, source-family placement, and non-emitting status; capped below final-source range because no current evidence proves an original entry route, modeled function, source signature, or safe helper name.

## Target

- Target UID: `00043J`.
- Target path: `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row 1584, `84/88`, combined `86.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: report-only B-agent source-quality pass for a by-memory not-covered reconstructable row.
- Current scores and parent state: target `84/88`, owner [UID:0000A5] `ParcelIconPane` at `88/90`, file route [UID:0000MF] `ParcelPane` at `90/90`, parent/index [UID:0001EH] `ParcelNotificationPanes` non-emitting container at `88/91`.

## Current Target State

- Existing metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000A5`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP CODE`.
- Existing state: documented as an IDA-missed raw helper after eight `0xcc` padding bytes, decoding direct payload parcel counts, writing owner fields `+0xf8/+0xf9/+0xfa`, reading child pointer `+0xfc`, calling `ParcelPane::SetParcelSlotData` at `0x005461b0`, returning zero, and ending at `retn 4`.
- Existing blocker: no modeled IDA function at `0x005460f0`, no inbound xrefs, no proven original helper name/signature/entry route, and no generated output route.
- Related target/support docs checked: [UID:0000A5] `ParcelIconPane`, [UID:0000MF] `ParcelPane`, [UID:0001EH] `ParcelNotificationPanes`, [UID:0001EI] destructor predecessor, [UID:0001EJ] callback successor, [UID:0002KC] `ParcelPaneSetParcelSlotData`, [UID:0001VI] layout page, [UID:0001YE] vtable family, [UID:0000A6] `ParcelPane`, [UID:0001EG] constructor, and [UID:0001EO] scalar wrapper.

## Executive Recommendation

The best direct owner remains [UID:0000A5] `ParcelIconPane`. The helper writes the icon pane's own parcel-count fields and reads its child `ParcelPane *` before forwarding through `ParcelPane::SetParcelSlotData`; the callee is data flow, not ownership transfer. The likely source-family route remains [UID:0000MF] `ParcelPane.cpp`, but no current evidence identifies the helper's original source-facing declaration, callback wrapper, dispatch pointer, or safe emitted method/function signature.

Do not route this target to [UID:0000A5] as an emitter yet, even though the combined score would clear the numeric C++ eligibility threshold after the recommended score movement. The stricter route/name/source-shape evidence is missing, and emitting a C++ function would force a guessed public/private/helper signature for a raw unreferenced body.

## Supervisor Active Recheck

- Supervisor instruction: produce a report-only target-specific B report for [UID:00043J]; investigate whether the blank emitter/no-code disposition is still justified and whether the raw helper can be routed to source-facing `ParcelIconPane` method/helper C++.
- Split repair: not needed. B007 already split this exact child from [UID:0001EH], and current MCP reconfirms the half-open `0x005460f0-0x005461c0` child with `0x005460e8-0x005460f0` padding before it and [UID:0001EJ] beginning at `0x005461c0`.
- Write boundary: no target/support by-* docs, generated files, coverage reports, validator/tool state, supervisor ledgers, IDA DB, or lock files were edited.
- MCP status: available and used. One broad rendered-listing `search_text` over the whole `.text` range for `5460F0` timed out; a narrowed retry over `0x00544000-0x005470ad` succeeded, and `server_health` remained `ok`. This is not a `PAUSED_MCP_UNAVAILABLE` condition.

## Inference Research Guidance Check

- Direct IDA facts are separated from documentation evidence and inference below.
- Current `by-structure.md` requires both a valid emitter route and strong source shape before C++ insertion. Numeric combined score alone is not sufficient.
- Stale Wave2/Wave3 gate language was not used. Current by-* docs and executed reports supersede the earlier `95/95` code-gate wording.
- The workspace does not contain `source-3/simroot_v2`; generated lead material was therefore limited to current `auto-generated/*` reports and `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best current inference | Validation | Disposition |
| --- | --- | --- | --- |
| Raw helper role | `ParcelIconPane` direct-payload parcel update helper | Current MCP raw disassembly and previous B007/B005 docs show the same flag/count decode as [UID:0001EJ], but with direct payload pointer argument instead of `event + 0x0c` wrapper. | Keep descriptive page name; original spelling not proven. |
| Owner | [UID:0000A5] `ParcelIconPane` | Writes `+0xf8/+0xf9/+0xfa`, reads `+0xfc`, matches `ParcelIconPane` constructor/layout/callback fields. | Preserve `CANONICAL_OWNER:0000A5`. |
| Emitter route | none proven | No IDA function, no xrefs to start, no VA/RVA pointer-byte hits, no `sub_5460F0` listing reference in parcel range, generated `ParcelPane.cpp` omits UID00043J. | Keep blank `EMITTER_UIDS`. |
| Source-facing C++ | not safe | A source body would require inventing a helper declaration/signature and call site for a raw unreferenced body. | Keep formal C++ blank; add exact no-code proof. |
| Split/range | exact child remains valid | Current MCP `entity_query` sees functions at `0x00546070`, `0x005461c0`, `0x00546290`, with no function at raw start; bytes confirm padding before and `retn 4` tail. | No split/merge/rename. |
| Score | can improve modestly | Current MCP revalidates body and adds stronger negative route evidence not present in target page. | Recommend `88/90`, not higher. |

Rejected alternatives:

- `ParcelPane` owner: rejected because `ParcelPane::SetParcelSlotData` is a callee reached through the icon pane's child pointer; the raw helper mutates `ParcelIconPane` state first.
- [UID:0001EJ] merge: rejected because [UID:0001EJ] is a modeled secondary-vtable callback at `0x005461c0`, while this helper is a separate raw direct-payload body ending at `0x005461bd`.
- File-level free function emitter under [UID:0000MF]: rejected because no call site, exported symbol, pointer table, or source declaration indicates this was a free helper rather than an unwrapped method/lowered local body.
- Comment-only C++ marker: rejected for now because the target has blank emitters. A comment-only marker in a non-emitting block would not improve generated source and could imply an accepted output route that is not proven.

## Evidence Standards Used

Evidence used: current IDA MCP health/session, exact function lookup, bounded function entity query, raw bytes, bounded raw-range instruction query, xrefs, bounded listing search, byte-pattern route search, current generated coverage/source output, current by-* support docs, and executed B reports. Existing reports were used as leads and checked against current MCP.

The evidence is strong enough for behavior, ownership, and non-emitting disposition. It is not strong enough for formal C++ because it does not establish how source code reached the raw helper.

## Evidence Checked

### IDA MCP / Raw Evidence

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- `idb_list`: one active session `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`, `is_analyzing:false`.
- `server_health(database='supervisor_resume_20260629')`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs` for `0x00546070`, `0x005460e8`, `0x005460f0`, `0x005461b0`, `0x005461bd`, `0x005461c0`, `0x0054628d`, `0x005464b0`: confirms modeled functions at `0x00546070` (`sub_546070`, `0x78`), `0x005461c0` (`sub_5461C0`, `0xcd`), and `0x005464b0` (`sub_5464B0`, `0xc5`); no function at the padding, raw start, call site, return tail, or callback end.
- `entity_query` bounded to `0x00546060-0x005462a0`: returns only `sub_546070`, `sub_5461C0`, and `sub_546290`, confirming no modeled function covering `0x005460f0`.
- `get_bytes`: `0x005460e8` is eight `0xcc` bytes; `0x005460f0` starts `55 8b ec 83 ec 0c 53 56 57...`; `0x005461bd` bytes are `c2 04 00`.
- `insn_query 0x005460e8-0x005461c0`: 72 instructions, no function owner, not truncated. It shows `align 10h` at `0x005460e8`, prologue at `0x005460f0`, two `std::_Narrow_char_traits<char,int>::to_char_type` calls, flag offset math, owner count writes, `call sub_5464B0` at `0x005461b0`, and `retn 4` at `0x005461bd`.
- Tail `insn_query 0x00546158-0x005461c0`: confirms `mov [edx+0F8h], cl`; compares old total/left/right values; on update loads child pointer from `[edx+0FCh]`, writes `[edx+0F9h]` and `[edx+0FAh]`, pushes total/left/right arguments, calls `sub_5464B0`, then returns zero with `retn 4`.
- `xrefs_to 0x005460f0`: zero xrefs. `xref_query` for `0x005460f0` only reports the fall-through/code flow from `0x005460f0` to `0x005460f1`, not an inbound caller.
- `xrefs_to 0x005464b0`: exactly three code refs, `0x005461b0` from this raw helper, `0x00546274` from [UID:0001EJ], and `0x00546dcd` from `FlyingParcelPane` animation completion.
- `xrefs_to 0x005461c0`: one data xref at `0x00621c10`, the `ParcelIconPane` secondary-vtable callback slot.
- `find_bytes` for VA little-endian pointer `F0 60 54 00` and RVA pointer `F0 60 14 00`: zero matches.
- `decompile 0x005460f0`: failed at `0x5460f0`, consistent with the no-function raw-body status.
- `analyze_function 0x005461c0`: callback reads packet pointer from `event + 0x0c`, checks byte `8`, decodes flags, splits count nibbles, writes secondary offsets `+0x58/+0x59/+0x5a`, reads child pointer at `+0x5c`, and calls `sub_5464B0`.
- `analyze_function 0x005464b0`: setter writes `+0xf8/+0xf9/+0xfa`, clears acknowledgement and button-state bytes, attaches/invalidate behavior; callers list excludes the raw helper because it has no function owner, while xrefs include the raw helper call.
- Timed-out check: a broad `search_text pattern='5460F0' start='0x00401000' end='0x0060d000'` timed out after 30 seconds. Narrowed replacement `search_text pattern='5460F0' start='0x00544000' end='0x005470ad'` returned only the raw helper's own listing line at `0x005460f0`; `search_text pattern='sub_5460F0'` in the same parcel range returned no hits. Follow-up `server_health` remained `ok`.

### Documentation / Generated Evidence

- Target by-memory doc currently documents the same raw helper behavior and no-code policy based on B007's accepted split implementation.
- `auto-generated/-ag-research-tracker.md` row 1584 lists UID00043J as `84/88`, reconstructable, reports `0`.
- `auto-generated/-ag-memory-coverage.md` row 2615 lists UID00043J as `non-emits`, owner `0000A5`, blank emitters, `emits_code:no`.
- `auto-generated/-ag-coverage-report-by-memory.md` row 1909 lists UID00043J as `emits_code:false`, reconstructable, `84%`, strong.
- `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` refreshed at validator command `000000004132` on `2026-07-01T18:08:08-04:00`; it contains class/global/vtable/layout support comments but no UID00043J body or marker, because the target has no emitter route.
- `source-3/simroot_v2` does not exist in this workspace. Current generated output was checked through `auto-generated/NexusTK`.

### Existing Report Search

Required terms searched with `rg`: `00043J`, `0x005460f0`, `0x005461c0`, `ParcelIconPaneParcelUpdateRawHelper`, `ParcelIconPane`, `ParcelPaneSetParcelSlotData`, and `ParcelNotificationPanes`.

Opened matching executed reports:

- `executed-b-agent-research/B007/0001EH-ParcelNotificationPanes-source-quality.md`: lead for child creation and prior no-code policy.
- `executed-b-agent-research/B005/0000MF-ParcelPane-empty-emitter-family-source-quality.md`: lead for current generated `ParcelPane.cpp` source/no-code surface and `OnParcelUpdate` body.
- `executed-b-agent-research/B002/0002KC-ParcelPaneSetParcelSlotData-source-quality.md`: lead for callee argument order and setter source shape.
- `executed-b-agent-research/B006/0001EG-ParcelIconPaneConstructor-empty-emitter-source-quality.md`: lead for current `ParcelIconPane` source route, fields, and generated route through [UID:0000A5].

Searches found no prior target-specific executed report with `TARGET-REPORT-UID:00043J`; B007 created the target as a child during the [UID:0001EH] aggregate implementation.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00043J-01 | UID00043J is exact half-open raw code `0x005460f0-0x005461c0`; `0x005460e8-0x005460f0` is padding and `0x005461c0` starts [UID:0001EJ]. | High | `lookup_funcs`, `entity_query`, `get_bytes`, `insn_query`. | Target `Boundary Evidence` / `IDA MCP Evidence`. | incorporate | applied - target `Boundary Evidence` already held the split and padding facts, and target `IDA MCP Evidence` now records current B001 lookup/entity/byte/instruction proof; validator `000000004149`, `2026-07-01T18:33:59-04:00`, exit `0`, `ok:1`. |
| C-00043J-02 | IDA still has no modeled function at `0x005460f0`, and Hex-Rays decompile fails there. | High | `lookup_funcs`, `entity_query`, `decompile`. | Target `Status`, `IDA MCP Evidence`, `No-Code Proof`. | incorporate | applied - target `Status`, `IDA MCP Evidence`, and `No-Code Proof` now record no modeled function, no covering entity, and failed decompile; validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-03 | No inbound xrefs currently target `0x005460f0`. | High | `xrefs_to`, `xref_query`. | Target `Status`, `IDA MCP Evidence`, `No-Code Proof`, `Open Questions`. | incorporate | applied - target records zero inbound xrefs and only local fall-through/code flow, with caller/dispatch route left evidence-backed unresolved; validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-04 | No VA/RVA pointer-byte hits for the raw start were found. | Medium-high | `find_bytes F0 60 54 00`, `F0 60 14 00`. | Target `IDA MCP Evidence` / `No-Code Proof`. | incorporate | applied - target `IDA MCP Evidence` and `No-Code Proof` record zero VA/RVA pointer-byte route hits; validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-05 | Narrowed rendered-listing search found only the raw start line and no `sub_5460F0` call/name reference in the parcel range. | Medium | `search_text` narrowed to `0x00544000-0x005470ad`; broad `.text` attempt timed out. | Target `IDA MCP Evidence`, `No-Code Proof`, `Open Questions`. | incorporate | applied - target records the broad timeout, narrowed successful retry, no `sub_5460F0` hit, and post-timeout health remaining `ok`; validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-06 | The helper decodes flag-dependent packed counts from a direct payload pointer argument, not from an event wrapper. | High | `insn_query`, comparison with `analyze_function 0x005461c0`. | Target `Behavior`, `IDA MCP Evidence`. | incorporate | applied - target `Behavior` already contained the direct-payload decode and target `IDA MCP Evidence` now adds current instruction proof and callback comparison context; validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-07 | The helper writes `ParcelIconPane` owner fields `+0xf8/+0xf9/+0xfa` and reads child pointer `+0xfc`. | High | raw `insn_query`, [UID:0000A5], [UID:0001VI], [UID:0001EG], [UID:0001EJ]. | Target `Behavior`, `IDA MCP Evidence`, `Ownership And Reconstruction Notes`. | incorporate | applied - target preserves the field table and owner notes and adds current tail-instruction proof for `[edx+0F8h]`, `[edx+0F9h]`, `[edx+0FAh]`, and `[edx+0FCh]`; validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-08 | The helper calls `ParcelPane::SetParcelSlotData` at `0x005461b0` with total/left/right counts, and this is one of three current xrefs to `0x005464b0`. | High | raw `insn_query`, `xrefs_to 0x005464b0`, [UID:0002KC]. | Target `Behavior`, `IDA MCP Evidence`; support [UID:0002KC] already sufficient. | incorporate | applied - target `Behavior` and `IDA MCP Evidence` now record the `0x005461b0` call and the three current xrefs to `0x005464b0`; support doc edit excluded because [UID:0002KC] already contains the callee role. Validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-09 | Direct owner remains [UID:0000A5] `ParcelIconPane`; [UID:0000MF] is source-family route, not direct owner. | High | owner field writes, child pointer, class/file docs, B007/B005. | Target metadata/prose, `Status`, `Ownership And Reconstruction Notes`, `Score Rationale`, `Rejected Alternatives`. | incorporate | applied - target preserves `CANONICAL_OWNER:0000A5`, adds source-family/direct-owner rationale, and rejects `ParcelPane` direct ownership; support doc edits excluded because [UID:0000A5] and [UID:0000MF] already carry the owner/source-family facts. Validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-10 | No first-draft C++ is currently safe because no entry route/signature/helper declaration is proven. | High | no function, no xrefs, no pointer bytes, generated output omitted UID00043J. | Target formal C++ block, `Status`, `No-Code Proof`, `Rejected Alternatives`, `Open Questions`. | incorporate | applied - formal C++ remains blank and target now records exact no-code proof, rejected C++ marker/free-helper alternatives, and unresolved route/signature questions; validator `000000004149`, exit `0`, `ok:1`. |
| C-00043J-11 | Recommended score becomes `88/90`, not higher. | Medium-high | current MCP revalidation plus remaining route/name block. | Target metadata and `Score Rationale`. | incorporate | applied - target metadata is `COMPLETION:88`, `CONFIDENCE:90`, and `Score Rationale` explains the raise and cap; validator `000000004149` reported `completion_update 00043J ... 88`, `confidence_update 00043J ... 90`, exit `0`, `ok:1`. |
| C-00043J-12 | No support doc metadata or source-route changes are required. | High | support docs already record raw helper owner/source-family/no-code role. | Report checklist; target page only. | not-applicable | excluded-with-reason - callback accepted target-only implementation and no direct support contradiction was found; no support docs were edited. Target validator `000000004149`, exit `0`, `ok:1`; report checklist records support edits as excluded/already sufficient. |

## Positive Evidence Summary

- The raw body is real executable code with a normal prologue and `retn 4`, not padding.
- The body's field accesses line up with `ParcelIconPane` layout and [UID:0001EJ]'s owner-normalized update fields.
- The body calls the accepted `ParcelPane::SetParcelSlotData` method at `0x005461b0` with the same total/left/right count data flow documented for [UID:0001EJ].
- The source-family context is strong: constructor/destructor/callback/slot setter support pages and generated `ParcelPane.cpp` agree that parcel notification source belongs under [UID:0000MF].

## IDA MCP Facts

- Function/range facts: no IDA function at `0x005460f0`; adjacent modeled functions are `sub_546070` and `sub_5461C0`.
- Data/table/padding facts: `0x005460e8-0x005460f0` is eight `0xcc` bytes; `0x005461bd` is `retn 4`.
- Xref facts: no inbound xrefs to raw start; three xrefs to `SetParcelSlotData`, including this raw call at `0x005461b0`.
- Vtable/global/type facts: [UID:0001EJ] has the `0x00621c10` secondary-vtable slot; this raw helper has no vtable slot.
- Negative IDA facts: no function object, no decompilation, no VA/RVA pointer-byte references, no local `sub_5460F0` rendered-listing caller/name hit.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00546070-0x005460e8` | [UID:0001EI] destructor | preceding ordinary destructor | TRUE | [UID:0000A5] | `88/91` | Emits ordinary destructor source. |
| `0x005460e8-0x005460f0` | no page | alignment padding | FALSE | none | n/a | Eight `0xcc` bytes; no child page needed. |
| `0x005460f0-0x005461c0` | [UID:00043J] target | raw direct-payload parcel update helper | TRUE | [UID:0000A5] | recommend `88/90` | Non-emitting, blank C++. |
| `0x005461c0-0x0054628d` | [UID:0001EJ] callback | secondary-vtable event-wrapper parcel update callback | TRUE | [UID:0000A5] | `88/91` | Emits first-draft `OnParcelUpdate`. |
| `0x005464b0-0x00546575` | [UID:0002KC] setter | child `ParcelPane` slot data setter | TRUE | [UID:0000A6] | `91/92` | Emits first-draft setter source. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005460f0` | no inbound xrefs | No proven caller or pointer route to raw helper start. |
| `0x005461b0` | call to `0x005464b0` | Raw helper forwards changed counts to child `ParcelPane`. |
| `0x00546274` | call to `0x005464b0` from `sub_5461C0` | Modeled event-wrapper callback uses same setter. |
| `0x00546dcd` | call to `0x005464b0` from `sub_546D70` | FlyingParcelPane completion updates global parcel pane. |
| `0x00621c10` | data xref to `0x005461c0` | Vtable route for callback successor, not for raw helper. |

## Documentation Evidence And IDA Status

- Existing docs support the owner/source-family conclusion. [UID:0000A5] lists UID00043J as class-local raw helper; [UID:0000MF] preserves it as no-function/no-entry, blank-C++ support; [UID:0001EH] treats it as an exact child of a non-emitting container.
- Existing generated output confirms the target is currently not emitted. The generated `ParcelPane.cpp` source root has no UID00043J body or marker.
- No current support page contradicts the recommended target-only update.

## Ranked Ownership Analysis

### 1. [UID:0000A5] `ParcelIconPane` - selected

- Evidence for: owner field writes at `+0xf8/+0xf9/+0xfa`, child pointer read at `+0xfc`, adjacency to `ParcelIconPane` destructor/callback, paired logic with [UID:0001EJ], class page already records the field names and method inventory.
- Evidence against: no function object or inbound xref means the exact source declaration is not proven.
- Decision: direct owner remains [UID:0000A5], but owner proof is not emitter proof.

### 2. [UID:0000MF] `ParcelPane.cpp` source file - selected as source family only

- Evidence for: parcel notification source family groups `ParcelIconPane`, `ParcelPane`, `FlyingParcelPane`, globals, vtables, and alert resources; generated source root is `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.
- Evidence against: file-level source route does not prove a direct free helper signature or output position for an unreferenced raw body.
- Decision: retain source-family placement, not target emitter route.

### 3. [UID:0000A6] `ParcelPane` - rejected

- Evidence for: raw helper calls `ParcelPane::SetParcelSlotData`.
- Evidence against: receiver state belongs to `ParcelIconPane`; `ParcelPane` is only the child callee.
- Decision: dependency/callee only.

### 4. New file/free helper - rejected

- Evidence for: a no-function raw body could theoretically be an internal helper.
- Evidence against: no call site, pointer table, source symbol, resource route, or generated family evidence supports a standalone declaration.
- Decision: unsafe.

### 5. No-owner/non-emitting - partially rejected

- Evidence for: no xrefs/source signature.
- Evidence against: field writes strongly identify [UID:0000A5] as semantic owner.
- Decision: not no-owner; it is owned by [UID:0000A5] but non-emitting.

## Source Placement

- Recommended source placement: class-local `ParcelIconPane` behavior in the `ParcelPane.cpp` source family, documented on the exact by-memory page only.
- Why it fits: the source module already emits `ParcelIconPane` constructor/destructor/callback source and `ParcelPane` setter source; the helper uses the same parcel packet update domain.
- Rejected placements: `ParcelPane` method, aggregate [UID:0001EH], vtable callback, and standalone new file.
- Remaining uncertainty: original signature and reachability path. The helper may be a raw unmodeled method, compiler/lowering artifact, or a no-longer-referenced local body. Current evidence cannot choose safely.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x005460f0-0x005461c0` half-open.
- Preceding padding: `0x005460e8-0x005460f0`, eight `0xcc` bytes.
- Successor: [UID:0001EJ] starts at `0x005461c0`.
- No split required: bounded raw helper has one coherent behavior and one return.
- No merge required: callback successor has separate vtable route and event-wrapper source shape.
- Reclassification: keep reconstructable true, but non-emitting.

## Negative Evidence Summary

- No function object at `0x005460f0`; decompilation fails.
- No inbound xrefs to `0x005460f0`.
- No VA/RVA pointer bytes for `0x005460f0`.
- No `sub_5460F0` rendered-listing reference in the parcel range.
- No generated output route in fresh `ParcelPane.cpp`.
- No support report or by-* doc proves an original helper declaration/signature.

Consumer/callee evidence alone is not ownership or emitter proof. The `SetParcelSlotData` call proves the child update data flow, not a `ParcelPane` source owner or a safe source declaration for this raw helper.

## First-Draft C++ Recommendation

- Eligible for draft C++: no.
- Recommended code: keep the formal `RECONSTRUCTION_CPP CODE` block empty.
- Reason code should remain blank: this target is reconstructable behavior with a strong semantic owner but no proven emitted source route. Any C++ body would need to invent a source-facing helper name, member/free-function status, parameter type, and call path for a raw body that IDA does not model as a function and that current xref/pointer searches cannot reach.
- Exact no-code proof for target page:

```text
Formal C++ remains blank for UID00043J. Current B001 MCP recheck on session `supervisor_resume_20260629` confirms the raw body is real ParcelIconPane-owned executable code, but it also confirms no IDA function object at `0x005460f0`, failed decompilation at that address, zero inbound xrefs to the raw start, no VA/RVA pointer-byte hits for `0x005460f0`, no `sub_5460F0` rendered-listing caller/name hit in the parcel notification range, and no generated `ParcelPane.cpp` output route. The behavior is documented for reconstruction, but no current evidence proves the original source signature or entry route well enough to emit human-source-shaped C++ without inventing a helper declaration.
```

## Final Recommendation

- Update target score to `COMPLETION:88`, `CONFIDENCE:90`.
- Preserve owner/reconstructable metadata.
- Preserve blank emitters and blank C++.
- Incorporate the current MCP proof and negative route checks into the target page.
- Do not edit support docs unless supervisor wants an optional dated change note; current support docs already preserve the valid owner/source-family/no-code facts.

## Recommended Target Doc Changes

Target path: `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`.

Exact facts to incorporate:

- Current MCP session `supervisor_resume_20260629` health/session details.
- Current lookup/entity query facts proving no function at raw start and adjacent modeled functions.
- Current raw bytes and bounded instruction evidence, including `0x005461b0` call and `retn 4`.
- Current xref/byte-pattern/listing negative route checks.
- Current generated output absence from `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.
- No-code proof text above.

Metadata changes:

- `COMPLETION:84` -> `COMPLETION:88`.
- `CONFIDENCE:88` -> `CONFIDENCE:90`.
- No change to `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, or the formal C++ block.

Historical/rejected facts to preserve:

- B007 created this exact child from [UID:0001EH].
- The target is not padding and not part of [UID:0001EJ].
- The target is not a `ParcelPane` method despite calling `ParcelPane::SetParcelSlotData`.
- The lack of route/signature is a source-output blocker, not an ownership blocker.

## Recommended Support Doc Changes

No required support doc changes.

- [UID:0000A5] `by-class/ParcelIconPane.md`: already lists UID00043J as the raw helper and explains blank emitter/no-C++ policy.
- [UID:0000MF] `by-file/ParcelPane.md`: already records UID00043J as ParcelIconPane-owned, no-function/no-entry, blank emitter/C++.
- [UID:0001EH] `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`: already lists UID00043J as exact child and keeps the aggregate non-emitting.
- [UID:0001EJ] and [UID:0002KC]: already contain the paired callback and callee facts needed by this target.

## Score And Metadata Recommendation

- Current score/metadata: `84/88`, owner `0000A5`, reconstructable true, blank emitter/code.
- Recommended score/metadata: `88/90`, owner `0000A5`, reconstructable true, blank emitter/code.
- Reason higher: current MCP rechecked the target under the active session, refreshed exact function/non-function boundaries, raw instruction behavior, call/xref facts, route-negative byte searches, generated output state, and no-code proof.
- Reason not higher: no function object, decompilation failure, no inbound xrefs, no pointer-table hits, and no source signature remain material source-quality blockers. A high-90s score would be inappropriate because another agent would still need new route evidence before trusting emitted C++.

Score-limiting blockers researched:

- Caller/entry route: checked xrefs, pointer bytes, bounded listing search; unresolved with exact negative evidence.
- Source signature/helper name: checked current docs, generated output, reports; unresolved because no route exists to name.
- Emitter route: checked generated source and support docs; unresolved, so blank emitter stays.
- Split/range: resolved; no split needed.
- Owner/source placement: resolved to owner [UID:0000A5], source family [UID:0000MF].

## Open Questions With Attempted Resolution

- What calls or dispatches to `0x005460f0`?
  - Evidence checked: xrefs, xref query, byte-pattern pointer search, bounded rendered-listing search, generated output, prior reports.
  - Resolution: unresolved with negative evidence; no current route is safe.
- What original source signature/name should this helper use?
  - Evidence checked: current support docs, generated output, prior B reports, raw calling convention shape (`ecx` owner plus one direct payload argument).
  - Resolution: unresolved; descriptive page name remains acceptable for documentation, not formal source.
- Should it emit as a private `ParcelIconPane` helper?
  - Evidence checked: owner fields support class locality, but no caller/source declaration supports the helper surface.
  - Resolution: no current emission.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker text is required. If the supervisor accepts the report and target page update, run the scoped validator on the target page and let validator-owned generated coverage/tracker files refresh.

## Follow-Up Actions

- Supervisor: review this report for acceptance and, if accepted, callback B001 to apply the target-only update.
- Future research: only new route evidence should reopen C++ eligibility, such as a recovered pointer table, callback registration wrapper, external trace, or source-declaration proof for the raw helper.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: original call/dispatch route and source declaration.

## Validator Results

- Report-only pass: no validators were run because no by-* docs were edited.
- Implementation callback validator:
  - Working directory: `E:\NTK\GhidraBridge\source-3\project-documentation`.
  - Command: `python .\tools\validator.py --mode file --file by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md --apply --queue-timeout 240`.
  - Exit: `0`.
  - `command_id`: `000000004149`.
  - `command_timestamp`: `2026-07-01T18:33:59-04:00`.
  - `ok`: `1`.
  - Target effects: `completion_update 00043J ... 88`, `confidence_update 00043J ... 90`.
  - Validator-owned side effects: `projected_stats_update:1`, `stats_rescore_recommended:1`, and three `stats_row_remove` entries from `project-level/-auto-completion-stats.md` (`Low_Completion_Reconstructable`, `Low_Both_Reconstructable`, `by-memory_Reconstructable`).
  - Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000004149`, `generated_refresh_timestamp: 2026-07-01T18:33:59-04:00`.
  - Generated source expectation: no UID00043J C++ output is expected while `EMITTER_UIDS` and formal C++ remain blank.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00043J-ParcelIconPaneParcelUpdateRawHelper-by-memory-source-quality.md`.
- Modified by B001 implementation callback:
  - `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`.
  - `tools/leaser/Agents/Agent-B001/research/00043J-ParcelIconPaneParcelUpdateRawHelper-by-memory-source-quality.md`.
- Validator-owned side effect reported by scoped validator: `project-level/-auto-completion-stats.md` projected stats update/stat-row removals. This was not manually edited.
- Renamed: none.
- Leases used:
  - B001 acquired a short lease for `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md` before the target edit/validator batch; `leaser.py` returned `Success`.
  - B001 released the same target lease immediately after validator command `000000004149`; `leaser.py` returned `Success`.
  - Follow-up `current_leases.md` showed no B001 leases remaining; only unrelated B006 leases were active.
- Report provenance: original `** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **` preserved unchanged.
- Report execution: leave blank. Supervisor runs executed-report lifecycle only after accepting and verifying implementation.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor implementation callback accepted report UID00043J for target-only documentation/no-code proof incorporation.
- [x] Target doc to update: `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`. Proof: target page modified and validator `000000004149` returned exit `0`, `ok:1`.
- [x] Current target state and actual evidence checked recorded in target page, including MCP session `supervisor_resume_20260629`, health proof, lookup/entity query, raw bytes/instructions, xrefs, byte-pattern searches, generated output state, and bounded search retry after the broad timeout. Proof: target `IDA MCP Evidence`, `No-Code Proof`, and `Open Questions`.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: ledger rows C-00043J-01 through C-00043J-12 now resolve to `applied` or `excluded-with-reason` with target sections and validator proof.
- [x] Metadata/score changes to apply: `84/88` -> `88/90`; preserve owner `0000A5`, reconstructable true, blank emitters, blank formal C++. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000A5`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++; validator `000000004149` confirmed the completion/confidence updates.
- [x] Score-limiting blockers researched to resolution or exact evidence-backed no-code proof: caller/xref route unresolved after xrefs/pointer/listing/generator checks; no current safe C++. Proof: target `No-Code Proof`, `Rejected Alternatives`, `Open Questions`, and `Score Rationale`.
- [x] Owner/emitter/reconstructable changes to apply: no owner/reconstructable change; explicitly preserve blank `EMITTER_UIDS`. Proof: target metadata preserved; validator `000000004149` only reported completion/confidence updates.
- [x] Split/rename/new-child changes to apply: none; current split is valid. Proof: target `Boundary Evidence` and `IDA MCP Evidence`; no files renamed or created during callback.
- [x] Source-placement/range/no-code facts to apply: owner [UID:0000A5], source-family [UID:0000MF], no-code proof text inserted or equivalently preserved at report-level detail. Proof: target `Status`, `Ownership And Reconstruction Notes`, `No-Code Proof`, and `Score Rationale`.
- [x] First-draft C++ or no-code proof to apply: keep C++ block empty and incorporate the exact no-code proof. Proof: target formal C++ block remains empty and `No-Code Proof` contains the exact report proof.
- [x] Third-party import directive: not applicable. Proof: target is a raw NexusTK helper, not third-party import; no formal import directive added.
- [x] Exact target/support doc facts to incorporate at report-level detail: current MCP proof, raw behavior, negative route evidence, score rationale, and rejected alternatives. Proof: target `Behavior`, `IDA MCP Evidence`, `No-Code Proof`, `Score Rationale`, and `Rejected Alternatives`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: not padding, not [UID:0001EJ] body, not `ParcelPane` method, no function/no xrefs/no pointer route, no generated output. Proof: target `Boundary Evidence`, `IDA MCP Evidence`, `Rejected Alternatives`, and `Changes`.
- [x] Wave2/Wave3 artifacts encountered and ignored/rejected as stale: `source-3/simroot_v2` absent; current generated output checked under `auto-generated/NexusTK`. Proof: no Wave2/Wave3 material was incorporated into target; target generated-output note uses current `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` state.
- [x] Open questions to document as evidence-backed unresolved: original caller/dispatch route and exact helper signature/name. Proof: target `Open Questions` documents caller/dispatch, source signature/name, and private helper emission as unresolved with evidence checked.
- [x] Validators to run after callback edit: `python .\tools\validator.py --mode file --file by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md --apply --queue-timeout 240`. Proof: command ran from `source-3/project-documentation`, command id `000000004149`, timestamp `2026-07-01T18:33:59-04:00`, exit `0`, `ok:1`.
- [x] Generated report refresh expected through validator; no manual generated/coverage/tracker edits. Proof: validator reported `generated_refresh: deferred`; B001 made no manual generated, coverage, tracker, validator state, queue, archive, lock, or IDA DB edits.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: supervisor callback accepted target-only documentation improvement/no-code proof for UID00043J.
- [x] All accepted target doc details incorporated at report-level detail. Proof: target now includes current MCP session/health, lookup/entity, bytes/instructions, xrefs, byte-pattern searches, narrowed listing search after broad timeout, generated-output absence, no-code proof, score rationale, owner/source-family reasoning, rejected alternatives, and open questions.
- [x] Claim And Incorporation Ledger updated to final callback states. Proof: C-00043J-01 through C-00043J-11 are `applied`; C-00043J-12 is `excluded-with-reason` because support docs were accepted as already sufficient and no contradiction was found.
- [x] Metadata/score/no-code changes applied or explicitly not applied with reason. Proof: target score is `88/90`, owner/reconstructable/blank emitters/blank formal C++ preserved, and `No-Code Proof` explains why C++ remains blank.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target `Rejected Alternatives`, `Open Questions`, `IDA MCP Evidence`, and `Changes`.
- [x] Open questions documented with evidence-backed unresolved rationale. Proof: target `Open Questions`.
- [x] Scoped target validator run and command id/timestamp/exit/ok recorded. Proof: command `python .\tools\validator.py --mode file --file by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md --apply --queue-timeout 240`, id `000000004149`, timestamp `2026-07-01T18:33:59-04:00`, exit `0`, `ok:1`.
- [x] Generated report refresh completed by validator or generated-refresh state recorded. Proof: validator reported `generated_refresh: deferred`, `generated_refresh_command_id: 000000004149`, `generated_refresh_timestamp: 2026-07-01T18:33:59-04:00`; no manual generated-file edits.
- [x] Remaining accepted-item blockers listed. Proof: none; all accepted target items are incorporated, and support-doc edits were explicitly excluded because the accepted report/callback treated support docs as already sufficient.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004221","destination_path":"executed-b-agent-research/B001/00043J-ParcelIconPaneParcelUpdateRawHelper-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00043J-ParcelIconPaneParcelUpdateRawHelper-by-memory-source-quality.md","timestamp":"2026-07-02T05:03:48-04:00","uid":"00043J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
