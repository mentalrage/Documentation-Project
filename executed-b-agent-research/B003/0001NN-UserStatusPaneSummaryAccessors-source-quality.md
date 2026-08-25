** TARGET-REPORT-UID:0001NN **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001NN UserStatusPaneSummaryAccessors Source-Quality Report


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0001NN] `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md` as one exact `UserStatusPane` accessor/setter island owned and emitted through [UID:0000FS][UserStatusPane](../../../../../by-class/UserStatusPane.md).
- Final disposition: target-only source-quality refresh. No split, no owner reroute, no support-doc edit, and no formal C++ change are recommended for Gate 1.
- Required action after supervisor callback: change target metadata from `COMPLETION:85` to `COMPLETION:88` and `CONFIDENCE:90` to `CONFIDENCE:92`; preserve `CANONICAL_OWNER:0000FS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FS`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the existing formal accessor C++ block.
- Confidence: high for range, behavior, owner/emitter route, xrefs, generated freshness, and no-split disposition; below final-audit because field names remain source-facing inference and the adjacent no-xref signed getter at `0x005b86d0-0x005b86d8` remains a separate follow-up candidate.

## Supporting Research
- Lifecycle/status notes: this artifact began as a new report-only B003 report in `tools/leaser/Agents/Agent-B003/research/`; Gate 1 passed at SHA256 `47DA97A5FC26E169551CE05E6C9557AA09552274C693A375E4FF1141860785DD`. The authorized target-only implementation callback was applied to `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`; no support docs were edited because same-or-greater detail was already present, no generated files or coverage reports were edited by hand, and no lifecycle/archive/report execution command was run.
- Current MCP session used: `supervisor_recovery_20260705`, active worker session from `idb_list`, input IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker PID `19604`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Current generated output checked read-only: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` has `validator-command-id: 000000007143`, `validator-refreshed-at: 2026-07-05T15:10:39-04:00`, and contains the UID0001NN accessor/setter block.
- Relevant historical reports opened as leads: executed B004 `00001N-CharacterSummaryRecord-source-routing.md` and executed B009 `0000P2-UserStatusPane-empty-emitter-family-source-quality.md`. B004 used local PE fallback because MCP was unavailable in that session; this B003 report rechecked the core claims with live MCP.

## Target
- Target UID: `0001NN`.
- Target path: `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row reports `85/90`, combined `87.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: xHigh report-first source-quality pass for a reconstructable by-memory item.
- Current scores and parent state: target `85/90`; direct class owner [UID:0000FS] `UserStatusPane` is `88/88`; file route [UID:0000P2] `UserStatusPane` is `90/87`.

## Current Target State
- Existing metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000FS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FS`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.
- Existing owner/emitter/reconstructable state: correct and should stay unchanged. Direct owner/emitter is [UID:0000FS][UserStatusPane](../../../../../by-class/UserStatusPane.md), which routes to [UID:0000P2][UserStatusPane](../../../../../by-file/UserStatusPane.md).
- Existing C++/emitter state: formal `RECONSTRUCTION_CPP CODE` already contains first-draft `UserStatusPane` copy helpers, byte/dword getters, and text setters. Generated output emits this block under UID0001NN.
- Existing open questions/blockers: field/member names are plausible source-facing inference rather than original-symbol proof; `0x005b8660` remains a real no-direct-caller getter inside the target; adjacent `0x005b86d0-0x005b86d8` is a no-xref signed getter outside the target and should not be folded into this page.
- Related target/support docs checked: `by-class/UserStatusPane.md`, `by-file/UserStatusPane.md`, `by-type/by-struct/UserStatusPaneSummaryFields.md`, `by-file/CharacterSummaryRecord.md`, `by-class/CharacterSummaryRecord.md`, `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md`, `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md`, `by-global/g_activeUserStatusPane.md`, and `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`.
- Current artifact/lifecycle status: implementation callback applied target-only; report ledger/checklist updated for supervisor Gate 2 review. The supervisor has not executed or archived this report.

## Heuristic / Inference Reanalysis And Validation
- Range validation: live MCP `lookup_funcs` confirms the modeled starts in `0x005b85b0-0x005b86ca`: two `0x1c` copy helpers, eight seven-byte getters, and two `0x2a` setters. `0x005b86ca`, `0x005b86d0`, and `0x005b86d8` are not IDA functions; `0x005b86e0` is the next exact setter function.
- Padding/split validation: `get_bytes` for `0x005b85b0` size `304` shows the modeled bodies, internal `0xcc` alignment, six `0xcc` bytes at `0x005b86ca-0x005b86d0`, raw bytes for the separate `movsx [ecx+0x27e]; ret` helper at `0x005b86d0-0x005b86d8`, and alignment before `0x005b86e0`. The assigned target should remain end-exclusive `0x005b85b0-0x005b86ca`; the raw helper is adjacent but not part of this report's target.
- Behavior validation: current Hex-Rays output matches the existing formal C++ shape. The copy helpers call `_wcscpy_s`; byte getters read offsets `+0x281`, `+0x282`, `+0x283`, `+0x27c`, and `+0x27e`; dword getters read `+0x28c`, `+0x294`, and `+0x298`; setters copy to `+0x17c` and `+0x1fc` with capacity `0x40`, then call vtable slot `+0x20` with `this+0x44`.
- Caller/reachability validation: `xrefs_to` returns code callers for all modeled functions except `0x005b8660`. It returns no xrefs for `0x005b8660` or adjacent `0x005b86d0`; `xref_query` data-only checks return zero data xrefs for every modeled start and for `0x005b86d0`.
- Receiver validation: representative caller windows load `unk_69AE0C` as the receiver. Examples include `0x004a1e0a mov ecx, dword ptr unk_69AE0C` before `0x004a1e18 call sub_5B85B0`, `0x004acb0c mov esi, dword ptr unk_69AE0C` followed by calls to `0x005b85b0` and `0x005b85d0`, `0x00565a27` before `SetDisplayLineA`, `0x00565b28` before `SetDisplayLineB`, and `0x00567f91` before the percent getter. This validates `UserStatusPane` receiver ownership and rejects a standalone `CharacterSummaryRecord *`.
- Source-quality naming validation: `CopyNameLineA/B`, `GetPercentStatA/B/C`, `GetNationId`, `GetSpiritId`, `GetDisplayValueA/B/C`, `SetDisplayLineA/B`, `m_nameLine`, `m_secondaryLine`, `m_displayLineA`, and `InvalidateSummaryText` are still inferred source-facing names, but they are now coherent with the class shell and generated output. The unresolved exact original names cap score below `95` but do not block the existing first-draft C++.
- Support-doc validation: current support docs already contain the B004/B009 conclusions at same-or-greater detail. No support drift requiring edit was found.

## Evidence Standards Used
- Direct IDA MCP facts: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, and scoped `insn_query` caller-window checks.
- Documentation evidence: current target/support by-* docs, current generated `UserStatusPane.cpp`, current tracker rows, and executed B004/B009 reports used as leads.
- Negative evidence: no IDA function at `0x005b86d0`; no xrefs to `0x005b8660` or `0x005b86d0`; no data xrefs to any modeled function start; no support-doc contradiction; no standalone constructor/vtable/allocation evidence for `CharacterSummaryRecord`.
- Evidence strength: strong enough for a modest target score increase because current live MCP confirms and extends the existing written evidence. Not strong enough for `95+` because several member names and some summary-tail field semantics remain inferred or unresolved.

## Evidence Checked
- MCP availability and schema: `tools/list` succeeded; active tools include `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, `insn_query`, and related read/write tools. Only read-only, narrow calls were used.
- IDA MCP checks performed:
  - `idb_list`: session `supervisor_recovery_20260705`, active, not analyzing.
  - `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
  - `lookup_funcs`: exact addresses `0x005b83b0`, all UID0001NN starts, `0x005b86ca`, `0x005b86d0`, `0x005b86d8`, `0x005b86e0`, and `0x005b8700`.
  - `get_bytes`: `0x005b85b0` size `304`.
  - `decompile`: every modeled start from `0x005b85b0` through `0x005b86a0`.
  - `disasm`: representative functions `0x005b85b0`, `0x005b8660`, `0x005b8670`, `0x005b86a0`, `0x005b86e0`, and non-function `0x005b86d0`.
  - `xrefs_to`: every modeled UID0001NN function start plus `0x005b86d0`, limit `30`.
  - `xref_query`: data-only checks for every modeled function start and `0x005b86d0`, all returned zero.
  - `callees`: copy/setter functions call `_wcscpy_s`; indirect vtable invalidation is visible in disassembly.
  - `insn_query`: bounded caller windows around `0x004a1e04-0x004a1e20`, `0x004acb06-0x004acb31`, `0x00565a20-0x00565a35`, `0x00565b20-0x00565b38`, `0x00567f88-0x00567fa0`, and `0x005aad58-0x005aad6a`.
- by-* docs checked: target memory page, `UserStatusPane` class/file docs, `UserStatusPaneSummaryFields`, `CharacterSummaryRecord` class/file docs, parent aggregate, status-icon setter, and active singleton docs.
- Generated reports/output checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`.
- Old report search terms used: `0001NN`, `0x005b85b0`, `005b86ca`, `UserStatusPaneSummaryAccessors`, `CharacterSummaryRecord`, `UserStatusPaneSummaryFields`, `g_activeUserStatusPane`, and `UserStatusPane`. Matching executed reports B004 and B009 were opened; other hits were treated as related support leads only.
- Failed, unavailable, or intentionally skipped checks: no MCP failures occurred. No broad callgraph, broad binary survey, IDA write, support-doc validator, or lifecycle command was run. During callback, the scoped target validator ran successfully as recorded in `Validator Results`.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001NN-01 | Current MCP provenance should be added to the target as a 2026-07-05 refresh: session `supervisor_recovery_20260705`, active IDB, Hex-Rays ready, exact-address calls only. | High | `idb_list`, `server_health`, `tools/list`. | Target `Evidence Notes` or new current MCP refresh note | incorporate | applied |
| C-0001NN-02 | The target remains a single end-exclusive range `0x005b85b0-0x005b86ca` with twelve modeled function bodies: `0x1c`, `0x1c`, eight `0x7` getters, and two `0x2a` setters. | High | MCP `lookup_funcs` for all starts; `get_bytes` for range bytes. | Target `Covered Ranges`, `Evidence Notes`, `Item Summary` | incorporate | applied |
| C-0001NN-03 | `0x005b86ca-0x005b86d0` is alignment, `0x005b86d0-0x005b86d8` is a separate no-xref signed `+0x27e` getter, and `0x005b86d8-0x005b86e0` aligns before [UID:0002LP]. | High | MCP `lookup_funcs` reports no function at `0x005b86d0`; `disasm 0x005b86d0`; `get_bytes`; `xrefs_to` zero xrefs. | Target boundary/padding prose; rejected split note | incorporate | applied |
| C-0001NN-04 | Decompilation confirms the existing first-draft behavior: copy helpers use `_wcscpy_s`, getters read offsets `+0x281/+0x282/+0x283/+0x27c/+0x27e/+0x28c/+0x294/+0x298`, and setters copy to `+0x17c/+0x1fc` before invalidating through vtable slot `+0x20` with `this+0x44`. | High | MCP `decompile` for all modeled starts; representative `disasm`. | Target `Evidence Notes`, `Raw Code Evidence`, formal C++ rationale | incorporate | applied |
| C-0001NN-05 | Caller reachability is now current: all modeled functions except `0x005b8660` have direct code xrefs; `0x005b8660` and `0x005b86d0` have zero xrefs; every modeled start has zero data xrefs. | High | MCP `xrefs_to` and `xref_query` data-only checks. | Target caller/xref section and score rationale | incorporate | applied |
| C-0001NN-06 | Representative call sites load `g_activeUserStatusPane` storage `0x0069ae0c` as receiver before calling these methods, so `CharacterSummaryRecord` is a generated alias and not a standalone source owner. | High | MCP `insn_query` caller windows at `0x004a1e0a`, `0x004acb0c`, `0x00565a27`, `0x00565b28`, `0x00567f91`; support docs. | Target `Source-Structure Decision`; rejected alternatives | incorporate | applied |
| C-0001NN-07 | Preserve target ownership/emission metadata: `CANONICAL_OWNER:0000FS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FS`, blank optional position, and `Nested:0`. | High | Current target metadata; direct class/file support docs; MCP receiver evidence. | Target metadata | already-present | already-present |
| C-0001NN-08 | Preserve the existing formal C++ block exactly; it is already the correct first-draft target representation under the current class shell and generated output. | High | Target C++ block; MCP decompile/disasm; generated `UserStatusPane.cpp` UID0001NN block. | Target `RECONSTRUCTION_CPP CODE` block | already-present | already-present |
| C-0001NN-09 | Raise target metadata from `COMPLETION:85` to `COMPLETION:88` and `CONFIDENCE:90` to `CONFIDENCE:92`; do not raise to `95+`. | Medium-high | Current MCP refresh resolves stale evidence freshness and verifies all modeled bodies/xrefs; remaining field-name and adjacent-helper caveats cap the score. | Target metadata and `Score Rationale` | incorporate | applied |
| C-0001NN-10 | Current generated output is fresh enough for review and contains the UID0001NN source block; after callback validation it should remain a non-empty generated block in `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`. | High | Generated header `validator-command-id: 000000007143`, `validator-refreshed-at: 2026-07-05T15:10:39-04:00`; UID block lines checked read-only. | Target generated-output note and implementation checklist | incorporate | applied |
| C-0001NN-11 | No support-doc edit is recommended because `UserStatusPane`, `UserStatusPaneSummaryFields`, `CharacterSummaryRecord`, and singleton docs already contain the same-or-greater source-route and alias-rejection detail. | High | Current support docs; executed B004/B009 implementations. | `by-class/UserStatusPane.md`, `by-file/UserStatusPane.md`, `by-type/by-struct/UserStatusPaneSummaryFields.md`, `by-class/CharacterSummaryRecord.md`, `by-file/CharacterSummaryRecord.md` | already-present | already-present |
| C-0001NN-12 | Reject rerouting directly to `by-file/UserStatusPane`, recreating `CharacterSummaryRecord`, moving the adjacent raw helper into UID0001NN, or pasting these bodies into the broad aggregate. | High | by-structure ownership rules; MCP receiver/range evidence; support docs. | Target rejected alternatives and source-placement prose | incorporate | applied |
| C-0001NN-13 | Implementation callback should run only the scoped target validator unless support drift is found: `python .\tools\validator.py --mode file --file by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md --apply --queue-timeout 240`. | High | Workflow validator rule; target-only recommended change. | Report checklist and target implementation plan | incorporate | applied |

## Positive Evidence Summary
- Direct facts supporting the recommendation: MCP confirms all modeled function starts/sizes, exact decompilation behavior, `_wcscpy_s` callees, vtable-slot invalidation, current caller xrefs, zero data xrefs, and no function/xrefs at `0x005b86d0`.
- Corroborating documentation/generated evidence: target page, [UID:0000FS] class page, [UID:0000P2] file page, [UID:0001WF] layout page, B004/B009 executed reports, and generated `UserStatusPane.cpp` all agree on the same `UserStatusPane` source route.
- Strongest inference chain: constructor and support docs place these offsets in the `UserStatusPane` object; caller windows pass `g_activeUserStatusPane` as `ecx`; the methods access full `UserStatusPane` object offsets; no standalone record lifetime exists. Therefore the direct owner/emitter remains [UID:0000FS].

## IDA MCP Facts
- Function/range facts: `lookup_funcs` confirms `sub_5B85B0` and `sub_5B85D0` are `0x1c`; `sub_5B85F0` through `sub_5B8660` are `0x7`; `sub_5B8670` and `sub_5B86A0` are `0x2a`; `0x005b86ca`, `0x005b86d0`, and `0x005b86d8` are not functions.
- Data/table/padding facts: `get_bytes` shows internal `0xcc` alignment, raw `0f be 81 7e 02 00 00 c3` at `0x005b86d0`, and alignment before `0x005b86e0`.
- Xref facts: direct code xref counts are `4`, `1`, `2`, `2`, `2`, `3`, `1`, `3`, `3`, `0`, `2`, and `2` for the target starts in address order. `0x005b86d0` has zero xrefs.
- Vtable/global/type facts: caller windows show `unk_69AE0C` receiver loads before representative calls, validating [UID:0000PS] `g_activeUserStatusPane` ownership context.
- Negative IDA facts: no data xrefs to any modeled start; no xrefs to `0x005b8660`; no xrefs to `0x005b86d0`; no standalone `CharacterSummaryRecord` lifecycle evidence found in current support docs or MCP caller evidence.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | ---: | --- |
| `0x005b85b0-0x005b85cc` | UID0001NN target | `CopyNameLineA`, copy out `+0x0fc` | true | UID0000FS | 85/90 current, 88/92 recommended | keep in target |
| `0x005b85d0-0x005b85ec` | UID0001NN target | `CopyNameLineB`, copy out `+0x1fc` | true | UID0000FS | 85/90 current, 88/92 recommended | keep in target |
| `0x005b85f0-0x005b8667` | UID0001NN target | byte/dword getter cluster | true | UID0000FS | 85/90 current, 88/92 recommended | keep in target |
| `0x005b8670-0x005b869a` | UID0001NN target | `SetDisplayLineA` plus invalidation | true | UID0000FS | 85/90 current, 88/92 recommended | keep in target |
| `0x005b86a0-0x005b86ca` | UID0001NN target | `SetDisplayLineB` plus invalidation | true | UID0000FS | 85/90 current, 88/92 recommended | keep in target |
| `0x005b86ca-0x005b86d0` | no target | `0xcc` alignment | false/padding | none | not scored | leave outside UID0001NN |
| `0x005b86d0-0x005b86d8` | no current child | no-xref signed `+0x27e` getter | likely reconstructable if future split is approved | none yet | not scored | future exact-child candidate, not current target |
| `0x005b86d8-0x005b86e0` | no target | alignment before UID0002LP | false/padding | none | not scored | leave outside UID0001NN |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b85b0` | callers `0x004a1e18`, `0x004acb1d`, `0x00566bee`, `0x005705e7`; callee `_wcscpy_s` | active copy-out helper |
| `0x005b85d0` | caller `0x004acb2d`; callee `_wcscpy_s` | active secondary-line copy-out helper |
| `0x005b85f0` | callers `0x00567f97`, `0x0057194c` | active byte getter |
| `0x005b8600` | callers `0x0056804a`, `0x005719ff` | active byte getter |
| `0x005b8610` | callers `0x00568103`, `0x00571abe` | active byte getter |
| `0x005b8620` | callers `0x00567cae`, `0x0059be29`, `0x0059d322` | active nation-id getter |
| `0x005b8630` | caller `0x00567e04` | active spirit/totem getter |
| `0x005b8640` | callers `0x00566bf5`, `0x005681be`, `0x005705ee` | active dword getter |
| `0x005b8650` | callers `0x00566c08`, `0x005683bc`, `0x005705fb` | active dword getter |
| `0x005b8660` | no code or data xrefs | real function body, no current direct caller |
| `0x005b8670` | callers `0x00565a2e`, `0x00570277`; callee `_wcscpy_s` plus indirect vtable invalidation | active text setter |
| `0x005b86a0` | callers `0x00565b2f`, `0x00570378`; callee `_wcscpy_s` plus indirect vtable invalidation | active text setter |
| `0x005b86d0` | no xrefs; disassembly only | adjacent no-route signed getter, outside target |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target page, `UserStatusPane` class/file pages, `UserStatusPaneSummaryFields`, `CharacterSummaryRecord` class/file pages, and `g_activeUserStatusPane` docs all already reject standalone `CharacterSummaryRecord` and route the source through `UserStatusPane`.
- Existing docs that are stale, incomplete, or contradicted: no direct contradiction was found. The target's score rationale still reflects a pre-current-MCP state and can be modestly improved; the underlying caveats remain real.
- Generated/coverage report state: generated memory coverage marks UID0001NN `coded` with owner/emitter `0000FS`; current generated `UserStatusPane.cpp` contains the UID0001NN block and is fresher than the last B009 implementation.

## Ranked Ownership Analysis
### 1. [UID:0000FS] `UserStatusPane` class
- Evidence for: constructor initializes the fields; caller windows pass `g_activeUserStatusPane` as `ecx`; target functions access full object offsets; class page declares matching methods/fields; generated output routes UID0001NN under this class.
- Evidence against: exact original member names are inferred, not symbol-proven.
- Decision: accept as direct semantic owner and emitter. Preserve `CANONICAL_OWNER:0000FS` and `EMITTER_UIDS:0000FS`.

### 2. [UID:0000P2] `UserStatusPane` source file
- Evidence for: file page owns the status HUD source family and routes class output to `NexusTK/ui/panels/UserStatusPane.cpp`; generated output is current and contains UID0001NN.
- Evidence against: by-structure says direct owner should be the narrowest true owner. These are class methods, so the file is the route through the class, not the direct target owner.
- Decision: accept as source-file route, reject direct target owner change.

### 3. `CharacterSummaryRecord` class/file alias
- Evidence for: historical/generated output used the alias.
- Evidence against: no constructor, destructor, allocation, vtable, RTTI/COL, global instance, or embedded-subobject receiver setup; generated alias omitted real function `0x005b8660`; current callers use `g_activeUserStatusPane`.
- Decision: reject as canonical owner or source file. Keep only as historical/generated search vocabulary.

### 4. New exact child for `0x005b86d0-0x005b86d8`
- Evidence for: current disassembly shows a real `movsx eax, byte ptr [ecx+0x27e]; ret` helper.
- Evidence against: outside UID0001NN's end-exclusive range, no xrefs, not modeled by IDA as a function, not needed to correct current target. Creating a new child would be split work beyond this target-only recommendation.
- Decision: not applicable for this callback. Preserve as a future exact-child candidate, not as a reason to split UID0001NN now.

## Source Placement
- Recommended source file/class/module placement: `UserStatusPane` class methods emitted through `NexusTK/ui/panels/UserStatusPane.cpp`.
- Why this placement fits: caller receiver setup, field offsets, surrounding constructor/payload docs, class shell, and generated output all place these methods in `UserStatusPane`, not a separate record type.
- Rejected placements: direct file-level free helpers, standalone `CharacterSummaryRecord`, broad aggregate body, and adjacent raw-helper merge.
- Remaining placement uncertainty: none material for owner/emitter route. Only exact original method/field spellings remain inferred.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: keep start-inclusive/end-exclusive `0x005b85b0-0x005b86ca`. Last covered instruction in `sub_5B86A0` is `retn 4` at `0x005b86c7`, followed by alignment through `0x005b86ca`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none in this report. `0x005b86d0-0x005b86d8` can be a future exact tiny child if supervisor assigns adjacent raw-helper coverage.
- Padding/table/data/code distinctions: internal gaps are `0xcc` alignment; adjacent raw helper is code-shaped but no-xref and outside this target; `0x005b86e0` is already [UID:0002LP].
- Parent/container impact: broad [UID:0001NM] remains a container with `[[CHILDREN]]`; UID0001NN remains the exact source-bearing method island.

## Negative Evidence Summary
- No data xrefs to any modeled target function start, so the target is ordinary call-reached code rather than a vtable/table-pointer family.
- No xrefs to `0x005b8660`; it should stay documented as a real but no-direct-caller getter inside the range, not as a generated omission to delete.
- No xrefs and no IDA function at `0x005b86d0`; this prevents merging it into UID0001NN or claiming a current source route for it.
- No caller evidence passes a `UserStatusPane + offset` embedded record pointer; representative callers pass `g_activeUserStatusPane` itself.
- No support doc currently claims a stronger contradictory owner. `CharacterSummaryRecord` pages already mark the alias as non-standalone.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: no IDA DB edits were requested or made.
- Evidence for source names: the existing source-facing names match B009's accepted class shell and current decompilation offsets. They should remain documented as inferred.
- Items intentionally left unchanged: do not create a real IDA `CharacterSummaryRecord` class; do not define a function at `0x005b86d0` during this report; do not rename IDA functions in the DB.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. Documentation and generated output are the authoritative scope here.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is reconstructable, has a confirmed emitter route, combined score is already greater than `85`, and current MCP confirms the method bodies.
- Recommended code: already present in the target. Preserve the existing formal block exactly:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
errno_t UserStatusPane::CopyNameLineA(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_nameLine);
}

errno_t UserStatusPane::CopyNameLineB(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_secondaryLine);
}

unsigned char UserStatusPane::GetPercentStatA() const { return m_percentStatA; }
unsigned char UserStatusPane::GetPercentStatB() const { return m_percentStatB; }
unsigned char UserStatusPane::GetPercentStatC() const { return m_percentStatC; }
signed char UserStatusPane::GetNationId() const { return m_nationId; }
signed char UserStatusPane::GetSpiritId() const { return m_spiritId; }
unsigned int UserStatusPane::GetDisplayValueA() const { return m_displayValueA; }
unsigned int UserStatusPane::GetDisplayValueB() const { return m_displayValueB; }
unsigned int UserStatusPane::GetDisplayValueC() const { return m_displayValueC; }

void UserStatusPane::SetDisplayLineA(const wchar_t *text)
{
    wcscpy_s(m_displayLineA, 64, text);
    InvalidateSummaryText();
}

void UserStatusPane::SetDisplayLineB(const wchar_t *text)
{
    wcscpy_s(m_secondaryLine, 64, text);
    InvalidateSummaryText();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: decompilation and disassembly match the copy/getter/setter operations; setter source `void` bodies can leave the indirect invalidation return in `eax` without exposing a source return value.
- Reason it matches plausible original source shape: these are short `UserStatusPane` accessors/setters over class fields, not decompiler-shaped free helpers or a fabricated record class.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: all `m_*` fields and `InvalidateSummaryText()` remain inferred from [UID:0001WF] layout and vtable invalidation behavior.
- Naming/coding style convention used and evidence for consistency: class member style follows the accepted B009 `UserStatusPane` class shell.
- Reason code should remain blank, if applicable: not applicable for UID0001NN. The formal C++ should remain populated.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended: target metadata `COMPLETION:88`, `CONFIDENCE:92`; add/update target prose with current MCP session evidence, exact xrefs/data-xref negatives, generated freshness, and no-split/no-reroute conclusions.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:0000FS`; keep `EMITTER_UIDS:0000FS`.
- Exact items left no-owner/non-emitting and why: none inside UID0001NN. Adjacent `0x005b86d0-0x005b86d8` remains outside this target and has no current owner/emitter route.
- Exact future work outside this assignment scope: optional future by-memory child for `0x005b86d0-0x005b86d8` if the supervisor wants full adjacent raw-helper coverage; broader final source-name audit for unresolved `UserStatusPaneSummaryFields` tail fields before any `95+` score.

## Recommended Target Doc Changes
- Target path: `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`.
- Exact report facts to incorporate:
  - Current MCP provenance: session `supervisor_recovery_20260705`; `server_health` ready; exact-address evidence only.
  - Exact function inventory from `lookup_funcs`, including no function at `0x005b86ca`, `0x005b86d0`, and `0x005b86d8`.
  - Current decompile and disassembly evidence for copy helpers, getters, setters, `_wcscpy_s`, and vtable-slot invalidation.
  - Current xref counts and negative data-xref findings.
  - Receiver windows showing `g_activeUserStatusPane`/`unk_69AE0C` as receiver, not a `CharacterSummaryRecord` pointer.
  - Generated freshness: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` currently has command id `000000007143` and contains UID0001NN code.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `COMPLETION:85` to `COMPLETION:88`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Preserve `CANONICAL_OWNER:0000FS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FS`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the formal C++ block exactly.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - `CharacterSummaryRecord` is a generated alias only.
  - `0x005b8660` is real but no-direct-caller.
  - `0x005b86d0` is adjacent, signed, no-xref, and outside this exact range.
  - Do not paste bodies into [UID:0001NM] or reroute direct owner to file UID0000P2.
- Validator command required after accepted target edit:

> Executable block R001 was removed from this report and preserved verbatim in [0001NN-UserStatusPaneSummaryAccessors-source-quality-removed.md](0001NN-UserStatusPaneSummaryAccessors-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Generated freshness expectation after callback: inspect `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` read-only. UID0001NN should remain a non-empty accessor/setter block, and the generated header should be equal/newer than the validator command metadata or reported as deferred/older.

## Recommended Support Doc Changes
- Support path: [UID:0000FS] `by-class/UserStatusPane.md`.
  - Exact report facts to incorporate: none recommended. Current page already declares the methods, fields, `g_activeUserStatusPane`, `[[CHILDREN]]`, `CharacterSummaryRecord` rejection, and UID0001NN routing.
  - Metadata/link/score/coverage/source-placement changes: none.
- Support path: [UID:0000P2] `by-file/UserStatusPane.md`.
  - Exact report facts to incorporate: none recommended. Current page already documents `UserStatusPaneSummaryFields` as folded into `UserStatusPane`, B004/B009 dispositions, generated output caveats, and UID0001NN first-draft C++.
  - Metadata/link/score/coverage/source-placement changes: none.
- Support path: [UID:0001WF] `by-type/by-struct/UserStatusPaneSummaryFields.md`.
  - Exact report facts to incorporate: none recommended. Current page already has the field offsets, provisional-name caveats, non-standalone layout-support disposition, and adjacent signed getter caveat.
  - Metadata/link/score/coverage/source-placement changes: none.
- Support path: [UID:00001N]/[UID:0000I4] `CharacterSummaryRecord` class/file docs.
  - Exact report facts to incorporate: none recommended. Current pages already reject standalone `CharacterSummaryRecord` at same-or-greater detail.
  - Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation
- Current score/metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000FS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FS`, blank optional emitter position.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:92`, with owner/reconstructable/emitter fields unchanged.
- Score rationale and reason not higher/lower:
  - Raise completion to `88` because the target now has formal C++, current MCP proof for every modeled start/body/xref class, generated freshness, and support-route consistency.
  - Raise confidence to `92` because current MCP independently reconfirms B004/B009 conclusions and removes stale-evidence risk.
  - Do not raise to `95+` because source member names are still inferred, `0x005b86d0` remains a separate no-route raw helper, and several summary-tail fields in [UID:0001WF] still have unresolved final semantics.
- Score-improvement attempt:
  - Range blocker: checked with `lookup_funcs`, `get_bytes`, and `disasm`; resolved for UID0001NN, adjacent helper remains outside range.
  - Caller/reachability blocker: checked with `xrefs_to`, `xref_query`, and caller-window `insn_query`; resolved for modeled functions, with explicit no-xref status for `0x005b8660`.
  - Ownership/emitter blocker: checked receiver setup and support docs; resolved as [UID:0000FS].
  - Source-name blocker: checked class/type docs and decompilation; partially unresolved, capped below `95`.
  - First-draft C++ blocker: checked generated output and decompile; already resolved by existing formal block.
- Metadata fields to change or leave unchanged: change only `COMPLETION` and `CONFIDENCE`; leave all other validator metadata unchanged.

## Open Questions With Attempted Resolution
- Open question: should the range split before final recommendations?
  - Evidence checked: `lookup_funcs`, `get_bytes`, `disasm 0x005b86d0`, xrefs, parent/neighbor docs.
  - Resolution: no split for UID0001NN. The exact target remains `0x005b85b0-0x005b86ca`; adjacent `0x005b86d0-0x005b86d8` is a future target candidate only.
- Open question: is `CharacterSummaryRecord` an owner/source type?
  - Evidence checked: support docs, B004/B009, current caller windows, `g_activeUserStatusPane` xrefs.
  - Resolution: no. It is generated alias vocabulary and should remain rejected.
- Open question: can exact original member names be finalized?
  - Evidence checked: class shell, layout doc, decompile offsets, status-payload support notes.
  - Resolution: not fully. Current inferred names are good enough for first-draft C++ and `92` confidence, but not enough for final-audit `95+`.
- Open question: is `0x005b8660` dead code that should be removed or split?
  - Evidence checked: current function lookup, decompile, disassembly, xrefs/data-xrefs.
  - Resolution: it is a real getter inside UID0001NN with no direct xrefs. Keep it in the target and generated C++; no split/removal.
- Questions remaining unresolved: only exact original naming and adjacent raw-helper ownership remain unresolved, with limited score impact and no target owner/C++ impact.

## Validator Results
- Commands run:

> Executable block R002 was removed from this report and preserved verbatim in [0001NN-UserStatusPaneSummaryAccessors-source-quality-removed.md](0001NN-UserStatusPaneSummaryAccessors-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: `command_id: 000000007243`, `command_timestamp: 2026-07-05T16:40:42-04:00`, exit code `0`, `ok: 1`, `completion_update: 1`, `confidence_update: 1`.
- Validator-reported generated refresh: `generated_refresh: deferred`, `generated_refresh_command_id: 000000007243`, `generated_refresh_timestamp: 2026-07-05T16:40:42-04:00`.
- Generated freshness check: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` header is equal/current at `validator-command-id: 000000007243`, `validator-refreshed-at: 2026-07-05T16:40:42-04:00`, `validator-refresh-source: deferred-generated-refresh`; UID0001NN remains a non-empty generated accessor/setter block with `Completion:88 | Confidence:92`.
- Queue status check after generated freshness: `python .\tools\validator.py --queue-status`, `command_id: 000000007244`, `command_timestamp: 2026-07-05T16:40:56-04:00`, worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Any unresolved validator warnings/errors: none for the scoped target validator.

## Changed Files
- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0001NN-UserStatusPaneSummaryAccessors-source-quality.md`.
- Modified by B003: `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`; this report artifact.
- Validator-owned/generated side effects observed: scoped validator updated projected stats and refreshed `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` to command `000000007243`. No generated file, coverage report, validator state, or project-level file was edited by hand.
- Renamed: none.
- Report execution: not run. B agents must never run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, or archive moves.

## Implementation Tracking Checklist
- [x] Supervisor validation required before implementation. Proof: Gate 1 passed for SHA256 `47DA97A5FC26E169551CE05E6C9557AA09552274C693A375E4FF1141860785DD`; supervisor authorized target-only callback.
- [x] Target/support docs to update: target only, `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`; support docs already same-or-greater. Proof: target edited; no support drift discovered and no support docs edited.
- [x] Current target state and actual evidence checked recorded: current metadata, C++ block, generated output, MCP session `supervisor_recovery_20260705`, exact function inventory, xrefs, data-xrefs, caller windows, and support docs are recorded above and in the target's 2026-07-05 B003 MCP refresh section.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: rows C-0001NN-01 through C-0001NN-13 now use callback states `applied` or `already-present`.
- [x] Metadata/score changes to apply: target `COMPLETION:85 -> 88`; `CONFIDENCE:90 -> 92`; preserve `CANONICAL_OWNER:0000FS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FS`, blank optional position, and `Nested:0`. Proof: target header updated and validator `000000007243` recorded both score updates.
- [x] Score-limiting blockers researched to resolution or evidence-backed cap. Proof: target score rationale now records current MCP proof and below-`95` caps for inferred member names and adjacent no-xref helper.
- [x] Owner/emitter/reconstructable changes to apply: none. Proof: target still has `CANONICAL_OWNER:0000FS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FS`, blank optional position, and `Nested:0`.
- [x] Split/rename/new-child changes to apply: none. Proof: no child was created for `0x005b86d0`; target prose marks it as a future exact-child candidate outside this callback.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Proof: source placement remains `UserStatusPane`; range remains `0x005b85b0-0x005b86ca`; IDA DB edits were not requested or made.
- [x] First-draft C++ or no-code proof to apply: preserve existing target formal C++ block exactly; no C++ text change. Proof: post-edit header check showed the formal block unchanged; generated UID0001NN block remains non-empty after validation.
- [x] Third-party import directive to apply or confirm not applicable. Proof: not applicable; no third-party import directive added.
- [x] Exact target/support doc facts to incorporate at report-level detail. Proof: target now includes current MCP provenance, function inventory, decompile/disasm behavior, xref/data-xref results, receiver-route proof, generated freshness, rejected alternatives, and score rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: target preserves generated `CharacterSummaryRecord` rejection, no direct owner change to file UID0000P2, no broad aggregate body, `0x005b8660` no-xref status, and `0x005b86d0` adjacent helper status.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Proof: generated `CharacterSummaryRecord` and `simroot_v2` aliases remain documented as leads/search vocabulary only, not ownership proof.
- [x] Open questions to close or document as evidence-backed unresolved. Proof: exact original member names and adjacent helper ownership remain capped but nonblocking in score rationale and current MCP refresh prose.
- [x] Validators to run after callback. Proof: scoped target validator ran from `source-3/project-documentation`, command `python .\tools\validator.py --mode file --file by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md --apply --queue-timeout 240`, command id `000000007243`, timestamp `2026-07-05T16:40:42-04:00`, exit `0`, `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply. Proof: no manual coverage/tracker text; generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` is current/equal at command `000000007243`, refresh source `deferred-generated-refresh`, and UID0001NN remains non-empty with `Completion:88 | Confidence:92`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000007246","destination_path":"executed-b-agent-research/B003/0001NN-UserStatusPaneSummaryAccessors-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001NN-UserStatusPaneSummaryAccessors-source-quality.md","timestamp":"2026-07-05T16:45:46-04:00","uid":"0001NN"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001NN-UserStatusPaneSummaryAccessors-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001NN-UserStatusPaneSummaryAccessors-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001NN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
