** TARGET-REPORT-UID:00010L **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00010L ClanAttrInputDialogCore Source-Quality Report

## Finalized Report / Current Recommendation
- Callback status: the accepted split plan has been implemented. [UID:00010L] `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md` is now a non-emitting class split index over four exact method child pages.
- Final parent disposition after callback: UID00010L is `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank `EMITTER_POSITION_OPTIONAL`; its formal C++ block is blank because the child pages carry the reconstructable source/no-code decisions.
- Created child pages: [UID:0004HH] `0x00489600-0x00489de1.ClanAttrInputDialogConstructor`, [UID:0004HI] `0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction`, [UID:0004HJ] `0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields`, and [UID:0004HK] `0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent`.
- Callback validators completed for the parent, four children, class support, and Clan file support; generated refresh state was `deferred` in scoped validators and remains supervisor-owned for report execution.
- Confidence: high for target range, child function starts/sizes, padding, vtable-only handler reachability, DLGCLAN2 resource use, submitted-field layout, and active Clan source route; medium-high for constructor/action final method bodies because the split plan resolves the structural blocker while leaving those two child bodies marker-only with exact no-code proof.

## Supporting Research
- Assignment source: `tools/leaser/Agents/Agent-B009/goal.md`, current assignment override dated 2026-07-05 09:20.
- Required report path: `tools/leaser/Agents/Agent-B009/research/00010L-ClanAttrInputDialogCore-source-quality.md`.
- Queue source at report assignment time: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; row listed [UID:00010L] with `85/90`, combined `87.5`, reconstructable `true`, reports `0`.
- Report-only boundary was observed during Gate 1. During the supervisor callback, only authorized by-* docs and this report were edited; generated edits, coverage edits, validator-state edits, lifecycle/archive commands, manual report moves, queue/lock edits, supervisor-ledger edits, and `execute_report` commands were not run.
- Repair-cycle note: supervisor executed this report into `executed-b-agent-research/B009/00010L-ClanAttrInputDialogCore-source-quality.md` with validator command `000000006953` at `2026-07-05T10:16:20-04:00`, then validator `invalidate_execute` command `000000006955` at `2026-07-05T10:25:14-04:00` returned the report to `tools/leaser/Agents/Agent-B009/research/00010L-ClanAttrInputDialogCore-source-quality.md` for lifecycle-text repair. The invalidated executed artifact incorrectly described the current lifecycle as unexecuted/unarchived; that false current-state wording is now corrected here. The validator-owned `VALIDATOR-REPORT-HISTORY` footer is preserved unchanged.
- Prior executed report lead: B007 `0000I8-Clan-empty-emitter-family-source-quality.md` already audited UID00010L as an aggregate that covers four methods and installed the previous marker-only formal comment. That older marker used stale/inclusive-looking child ends (`0x00489de0`, `0x00489eb6`, `0x00489f45`) and is now superseded by current half-open child pages.
- Prior accepted support leads: B004 UID0002O3 and B010 UID00010F resolve the DLGCLAN2 submitted-field names to accepted descriptive source-facing names: `m_submittedClanName`, `m_submittedDescriptionText`, `m_submittedAttributeText`, and `m_submittedAttributeType`. Exact original UI labels remain unrecovered, but this is now a confidence cap rather than a blocker for derived submitter bodies.
- Current MCP evidence is mandatory and was obtained from active session `supervisor_recovery_20260705`; no fallback-only conclusions are used.

## Target
- Target UID: `00010L`.
- Target path: `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, by-memory Not-Covered Files - Reconstructable.
- Current supervisor classification: report-first source-quality research for a reconstructable not-covered by-memory page.
- Current scores and parent state after callback: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position.

## Current Target State
- Current metadata: `90/92`, direct owner [UID:000024] `ClanAttrInputDialog`, reconstructable false, blank emitter list, blank optional emitter position.
- Current C++/emitter state: the parent formal block is blank. Child pages now carry the source/no-code dispositions: constructor/action are reconstructable children with formal no-code proofs; validation/input-event are reconstructable children with populated formal C++.
- Current documented behavior: the target records four modeled child functions, three internal alignment gaps, six length-prefixed packet string decodes from `packet+3`, `DLGCLAN2.EPF` setup, persistent fields at `+0x26c/+0x46c/+0x66c/+0x86c`, controls `8`/`9`/`10`, derived confirmation dispatch through primary vtable slot `+0x5c`, and `g_pClanStatusPane` input-event forwarding.
- Open blockers resolved by this callback: the child/source-body split is now implemented with child paths, child metadata, parent reclassification, support-doc changes, exact formal C++ for the two source-ready handlers, and target-specific no-code proofs for the constructor/action handler.
- Related target/support docs checked: `by-class/ClanAttrInputDialog.md`, `by-file/Clan.md`, `by-file/ClanDialogs.md`, `by-type/by-struct/ClanInputDialogLayouts.md`, `by-type/by-vtable/ClanDialogVtableFamily.md`, `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`, `by-memory/0x00616430-0x00616468.ClanModalDialogResourceStrings.md`, UID0002O3, UID0002O5, and executed B004/B007/B010 reports.
- Current artifact/lifecycle status: this is the active Agent-B009 research copy after invalidation/rework command `000000006955`. Historical validator command `000000006953` did execute a prior copy into the central archive, but that executed artifact was invalidated and returned here for this lifecycle-text repair. Current requested stop point is fresh supervisor Gate 1 review; B009 must not run report execution or lifecycle/archive commands.

## Heuristic / Inference Reanalysis And Validation
- Ownership/source route: pre-callback target metadata routed through [UID:0000I8], and [UID:0000I8] remains the best active source-file route. The implemented direct owner/emitter route for the split family is [UID:000024] `ClanAttrInputDialog`, which itself routes through [UID:0000I8]. `ClanDialogs.cpp` [UID:0000IA] is a documented coordinated split candidate, but its own page says the current stronger source route remains [UID:0000I8] because modal dialogs share Clan status state, resources, packet helpers, destructor/vtable context, and generated output routing. A one-off migration of UID00010L to `ClanDialogs.cpp` is rejected.
- Range/split: UID00010L is an aggregate over four real modeled functions plus padding. Current IDA MCP confirms starts and sizes: `sub_489600` size `0x7e1` / 2017 bytes, `sub_489DF0` size `0xc7` / 199 bytes, `sub_489EC0` size `0x86` / 134 bytes, and `sub_489F50` size `0x30` / 48 bytes (sizes verified with `tools/int_convert.py`). Therefore the exact child ranges are `0x00489600-0x00489de1`, `0x00489df0-0x00489eb7`, `0x00489ec0-0x00489f46`, and `0x00489f50-0x00489f80`. This is safe to implement now because every boundary is function-size-backed or byte-backed, every gap is confirmed `0xcc` padding, and the successor at `0x00489f80` is a separate raw constructor-shaped range.
- Padding: current bytes confirm the previous child-end comments should be corrected. Padding is `0x00489de1-0x00489df0` (15 `0xcc` bytes), `0x00489eb7-0x00489ec0` (9 `0xcc` bytes), and `0x00489f46-0x00489f50` (10 `0xcc` bytes). The target successor starts immediately at `0x00489f80` with raw `ClanEnlistInputDialog` constructor-shaped bytes; there is no post-target gap.
- Constructor/source shape: the constructor is not only a small wrapper. `analyze_function(0x00489600)` reports 663 instructions and shows base-constructor call, vtable stores, six length-prefixed packet-string decodes, five 256-wide-character stack/persistent buffers, `MultiByteToWideChar` conversions, `DLGCLAN2.EPF` resource construction, and many UI helper calls still named `sub_4991F0`, `sub_49DC10`, `sub_495BF0`, `sub_499030`, `sub_498920`, `sub_49FC00`, `sub_49DD80`, `sub_49DDD0`, `sub_49DB60`, `sub_49DFD0`, `sub_49E190`, and `sub_49EC80`.
- Field names: the old "field names unresolved" blocker is partially superseded. Accepted support docs now give descriptive field names for `+0x26c/+0x46c/+0x66c/+0x86c`; however exact original UI labels for controls `8`, `9`, and `10` remain unrecovered. This affects final confidence, not ownership.
- Handler behavior: current decompilation confirms `OnDialogAction` handles OK id `1`, reads controls `8`, `9`, and `10` through inherited control host `this[127]` / `+0x1fc`, copies two text controls to `+0x46c/+0x66c`, parses the third into word `+0x86c`, dispatches primary slot index `23` / `+0x5c`, then closes; cancel id `2` closes without submit.
- Validation behavior: current decompilation confirms `ValidateInputFields` fetches OK id `1` and controls `8`, `9`, `10`; it calls `sub_498C60` on all three submitted fields and jumps through OK-control slots `+0x50` or `+0x4c`. Source-facing polarity should be documented as "toggles OK availability based on whether required controls are empty" unless the final button class names prove exact enable/disable slot spelling.
- Input event behavior: current decompilation confirms `OnInputEvent` checks byte `event+4` for value `3`, forwards the event through `g_pClanStatusPane + 0xa0` slot `+4`, and then returns `sub_49E240` base-handler result. The support class method note saying this method "Refreshes validation after input changes" is stale and should be replaced with the forwarding/base-handler behavior.
- Rejected generated names: `sub_489600`, `sub_489DF0`, `sub_489EC0`, `sub_489F50`, `unk_67ADE4`, raw `v4 + 283`/`v4 + 411`, and helper `sub_` names are evidence labels only, not final source names.
- Wave2/Wave3 handling: old generated/simroot output was used only as a search/context lead. Current conclusions rely on IDA MCP, current by-* docs, and executed report evidence.

## Evidence Standards Used
- Direct evidence: IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `analyze_function`, `decompile`, and capped `disasm`; all calls were exact-address or small bounded batches.
- Numeric evidence: `tools/int_convert.py` verified size/offset conversions for `0x7e1`, `0xc7`, `0x86`, `0x30`, `0x980`, `0x26c`, `0x46c`, `0x66c`, `0x86c`, `0x5c`, `0xa0`, and `0xa4`.
- Documentation evidence: current target/support by-* pages, current generated tracker row, and matching executed B reports.
- Inference standard: source-facing names are allowed when they are the best current descriptive names and are labeled as inferred; exact original-symbol proof is not required, but unresolved names still cap final C++ confidence.
- Confidence limit: evidence is strong enough for metadata/source-route preservation and doc repair, but not strong enough to replace the target aggregate marker with a single formal multi-method body.

## Evidence Checked
- MCP availability and schema:
  - `initialize` returned server `ida-pro-mcp`, protocol `2025-06-18`.
  - `tools/list` returned 65 tools; required tools were present with current schemas requiring `database` for inspection calls.
  - `idb_list` returned one active session, `supervisor_recovery_20260705`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active true, worker pid `19604`.
  - `server_health` for that database returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, and `strings_cache_ready: true`.
- IDA MCP range checks:
  - `lookup_funcs` for `0x00489600`, `0x00489df0`, `0x00489ec0`, and `0x00489f50` returned `sub_489600` size `0x7e1`, `sub_489DF0` size `0xc7`, `sub_489EC0` size `0x86`, and `sub_489F50` size `0x30`.
  - `lookup_funcs` reported not-functions at `0x004895fe`, `0x00489de1`, `0x00489eb7`, `0x00489f46`, `0x00489f80`, and `0x00489ff0`; successor `0x00489fc0` and `0x0048a030` remain functions for derived submitters.
  - `get_bytes` confirmed two pretarget `0xcc` bytes at `0x004895fe-0x00489600`, the three internal `0xcc` padding gaps, and the raw constructor prologue at `0x00489f80` immediately after the `sub_489F50` `retn 4`.
- IDA MCP xrefs/callees:
  - `xrefs_to(0x00489600)` returned five code refs: three modeled constructor callers at `0x004852e9`, `0x00487f2f`, `0x004883e8`, and two raw derived-constructor calls at `0x00489f8d` and `0x00489ffd`.
  - `xrefs_to` for handlers returned only vtable data refs: `0x00615da0/0x00615e40/0x00615ee0` to `0x00489df0`, `0x00615da4/0x00615e44/0x00615ee4` to `0x00489ec0`, and `0x00615dc0/0x00615e60/0x00615f00` to `0x00489f50`.
  - `xrefs_to` for vtable bases returned constructor stores `0x00489660 -> 0x00615d58`, `0x00489666 -> 0x00615dbc`, and `0x00489670 -> 0x00615dec`.
  - `xrefs_to(0x0061644c)` returned `DLGCLAN2.EPF` refs from `0x00489914` and `0x00489d5c` inside `sub_489600`.
  - `xrefs_to(0x0067ade4)` returned 15 global refs including target input-event use at `0x00489f60`, submitter uses `0x00489fdc` and `0x0048a04c`, and cleanup/destructor refs.
  - `callees` for the four target functions confirmed the constructor's UI/helper fanout, action-handler callees `sub_498C10`, `unknown_libname_24`, `sub_49ED60`, `sub_49DAD0`, validation callee `sub_498C60`, and input-event base callee `sub_49E240`.
- IDA MCP decompilation/analysis:
  - `analyze_function(0x00489600)` confirmed constructor vtable stores at `+0`, `+0xa0`, `+0xa4`, six length-prefixed packet string decodes beginning at `packet+3`, first wide string persisted at `this+0x26c`, stack-local wide buffers, `DLGCLAN2.EPF` resource setup, and 663 total instructions.
  - `decompile(0x00489df0)` confirmed OK/cancel handling, controls `8`, `9`, `10`, field writes, `+0x5c` dispatch, and close helpers.
  - `decompile(0x00489ec0)` confirmed required-control checks and OK-control slot toggling.
  - `decompile(0x00489f50)` confirmed event type `3` forwarding through `g_pClanStatusPane + 0xa0`, then base input-event call.
- Docs and reports checked:
  - Target UID00010L page.
  - Support docs [UID:000024], [UID:0000I8], [UID:0000IA], [UID:0001TY], [UID:0001X9], [UID:0002MN], [UID:0003B9], [UID:0002O3], [UID:0002O5].
  - Generated tracker `auto-generated/-ag-research-tracker.md`.
  - Executed reports B007 UID0000I8, B004 UID0002O3, B010 UID00010F, and B009 UID00010J as an adjacent source-quality comparison.
- Negative/failed/skipped checks:
  - No broad list/search/callgraph/type/batch MCP calls were run.
  - Report-only Gate 1 ran no validators; callback scoped validators are recorded below.
  - No IDA DB rename/type/comment edits were made.
  - No generated output was edited manually; generated `Clan.cpp` and generated tracker/coverage refresh remain validator/supervisor-owned.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| 10L-C01 | Reclassify UID00010L after child creation from the pre-callback aggregate emitter (`85/90`, owner/emitter `0000I8`, reconstructable true) to a non-emitting split index: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position. | High | Current target aggregate state, class `[[CHILDREN]]`, exact four-function split proof, by-structure aggregate/source-body rule. | Parent target metadata and score rationale. | incorporate | applied - parent metadata now matches exactly. |
| 10L-C02 | Replace the parent formal marker with a blank formal block after child pages are created; the parent should not emit source because children carry the reconstructable method decisions. | High | `lookup_funcs`, `get_bytes`, `tools/int_convert.py`; parent contains four functions plus padding. | Parent target formal `RECONSTRUCTION_CPP CODE` block. | incorporate | applied - parent formal block is blank. |
| 10L-C03 | Record current MCP session `supervisor_recovery_20260705`, healthy IDB, and schema-current exact-address calls as current provenance. | High | `initialize`, `tools/list`, `idb_list`, `server_health`. | Target `IDA MCP Evidence` / Changes. | incorporate | applied - parent and children record current MCP provenance. |
| 10L-C04 | Four child functions are `sub_489600` size `0x7e1` / 2017, `sub_489DF0` size `0xc7` / 199, `sub_489EC0` size `0x86` / 134, `sub_489F50` size `0x30` / 48. | High | `lookup_funcs`; `tools/int_convert.py`. | Target covered ranges/evidence; class method notes. | incorporate | applied - parent, child pages, and class notes use exact sizes/ranges. |
| 10L-C05 | Internal padding is `0x00489de1-0x00489df0` 15 `0xcc` bytes, `0x00489eb7-0x00489ec0` 9 `0xcc` bytes, `0x00489f46-0x00489f50` 10 `0xcc` bytes; raw successor begins at `0x00489f80`. | High | `get_bytes`, not-function probes, successor lookup. | Target range/padding notes. | incorporate | applied - parent and child range sections document padding and successor. |
| 10L-C06 | Constructor writes ClanAttrInputDialog vtables at `0x00489660`, `0x00489666`, `0x00489670` and uses `DLGCLAN2.EPF` refs at `0x00489914`, `0x00489d5c`. | High | `analyze_function`, `xrefs_to` vtable bases/resource string. | Target IDA evidence; support vtable/resource already present. | incorporate | applied in parent/constructor child; already-present in vtable/resource support docs. |
| 10L-C07 | Constructor decodes six length-prefixed packet strings beginning at `packet+3`; first converted wide string persists at `this+0x26c`; remaining strings feed local dialog labels/default text. | High for behavior, medium-high for final source labels. | `analyze_function`; target and layout docs. | Target behavior/evidence. | incorporate | applied - parent and constructor child record behavior and label caveat. |
| 10L-C08 | Submitted fields are accepted descriptive names: `m_submittedClanName` at `+0x26c`, `m_submittedDescriptionText` at `+0x46c`, `m_submittedAttributeText` at `+0x66c`, `m_submittedAttributeType` at `+0x86c`; exact UI labels remain unrecovered. | Medium-high | UID0002O3, UID0002O5, UID00010F reports/docs; current target/layout docs. | Target behavior/score rationale; support class already mostly present. | incorporate | applied in parent/children; already-present in layout and submitter support docs. |
| 10L-C09 | `OnDialogAction` OK id `1` reads controls `8`, `9`, `10`, stores text/value fields, dispatches primary vtable slot `+0x5c` / decimal `92`, then closes; cancel id `2` closes without submit. | High | `decompile(0x00489df0)`, `tools/int_convert.py`, support reports. | Target behavior/evidence; class method notes. | incorporate | applied - action child and class notes document behavior. |
| 10L-C10 | `ValidateInputFields` fetches OK id `1` and controls `8`, `9`, `10` through control host `+0x1fc` and toggles OK availability based on required-control emptiness. | High | `decompile(0x00489ec0)`. | Target behavior/evidence; class method notes. | incorporate | applied - validation child has exact formal C++ and class/parent notes. |
| 10L-C11 | `OnInputEvent` checks event byte `event+4` for `3`, forwards through `g_pClanStatusPane + 0xa0` slot `+4`, then returns base input-event handler result; support wording that it refreshes validation is stale. | High | `decompile(0x00489f50)`, `xrefs_to(0x0067ade4)`. | Target behavior/evidence; `by-class/ClanAttrInputDialog.md` method row. | incorporate | applied - input-event child and class note now use forwarding/base-handler behavior. |
| 10L-C12 | Constructor reachability is three modeled callers plus two raw derived-constructor calls; handlers are vtable-only/data-ref reachable and have no direct code callers in current IDA xrefs. | High | `xrefs_to` target function starts. | Target xref/caller evidence. | incorporate | applied - parent and child evidence sections record this reachability. |
| 10L-C13 | Source-file route remains [UID:0000I8] `Clan`; direct post-split parent/child ownership is [UID:000024] `ClanAttrInputDialog`; [UID:0000IA] `ClanDialogs` remains a coordinated split candidate only, not a one-off owner for UID00010L. | High | `by-file/Clan.md`, `by-file/ClanDialogs.md`, vtable/resource docs, generated route. | Target ownership/source placement; support docs already present. | incorporate | applied - parent/children/class route through [UID:000024], while `by-file/Clan.md` keeps the source route. |
| 10L-C14 | Create child page `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md` for `ClanAttrInputDialog::ClanAttrInputDialog`, owner/emitter `000024`, reconstructable true, optional position `1`, `COMPLETION:86`, `CONFIDENCE:90`, formal marker-only no-code proof. | High | `lookup_funcs`, constructor xrefs, `analyze_function`, vtable/resource refs, padding bytes. | New child by-memory page. | incorporate | applied - created as [UID:0004HH]. |
| 10L-C15 | Create child page `by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md` for `ClanAttrInputDialog::OnDialogAction`, owner/emitter `000024`, reconstructable true, optional position `2`, `COMPLETION:86`, `CONFIDENCE:90`, formal marker-only no-code proof due unresolved base confirmation-hook source name. | High | `decompile(0x00489df0)`, action handler vtable refs, derived submitter evidence. | New child by-memory page. | incorporate | applied - created as [UID:0004HI]. |
| 10L-C16 | Create child page `by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md`, owner/emitter `000024`, reconstructable true, optional position `3`, `COMPLETION:89`, `CONFIDENCE:91`, with exact formal `ValidateInputFields` C++ block. | High | `decompile(0x00489ec0)`, class declaration, adjacent UID00010J helper naming precedent. | New child by-memory page. | incorporate | applied - created as [UID:0004HJ] with exact formal C++. |
| 10L-C17 | Create child page `by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md`, owner/emitter `000024`, reconstructable true, optional position `4`, `COMPLETION:89`, `CONFIDENCE:91`, with exact formal `OnInputEvent` C++ block. | High | `decompile(0x00489f50)`, `xrefs_to(0x0067ade4)`, class declaration, adjacent UID00010J naming precedent. | New child by-memory page. | incorporate | applied - created as [UID:0004HK] with exact formal C++. |
| 10L-C18 | Update [UID:000024] `by-class/ClanAttrInputDialog.md` method notes/children to use exact half-open ranges, link the four child pages, and correct `OnInputEvent` from validation refresh to event type `3` forwarding plus base handler. | High | Current class page, MCP function ranges, decompile evidence. | `by-class/ClanAttrInputDialog.md`. | incorporate | applied - class support links child UIDs and corrected method notes. |
| 10L-C19 | Update [UID:0000I8] `by-file/Clan.md` only as a source-route support note: `ClanAttrInputDialog` remains under `NexusTK/social/Clan.cpp`, while UID00010L becomes a split index and the four source/no-code decisions route through [UID:000024] children. | High | Current `Clan.md`, class owner route, split plan. | `by-file/Clan.md`. | incorporate | applied - Clan file support note now records the split index and child route. |
| 10L-C20 | Leave [UID:0000IA] `by-file/ClanDialogs.md` unchanged; it already documents `ClanDialogs.cpp` as coordinated split candidate only and warns against one-off migration. | High | Current support page. | `by-file/ClanDialogs.md`. | already-present | already-present - rechecked; no edit required. |
| 10L-C21 | Leave [UID:0001TY] `by-type/by-struct/ClanInputDialogLayouts.md` unchanged; it already has exact half-open UID00010L ranges, submitted-field offsets/names, control ids, source-layout impact, and original-label caveat. | High | Current support page. | `by-type/by-struct/ClanInputDialogLayouts.md`. | already-present | already-present - rechecked; no edit required. |
| 10L-C22 | Leave vtable/resource support docs unchanged; vtable bases/stores and `DLGCLAN2.EPF` xrefs are already present at same-or-greater detail. | High | Current [UID:0001X9], [UID:0002MN], [UID:0003B9] support pages. | Vtable/resource by-* docs. | already-present | already-present for content; validator command `000000006941` inserted validator-managed blank reconstruction/header mapping on [UID:0003B9] while resolving a parent missing-ref warning. |
| 10L-C23 | Do not create padding pages and do not merge UID00021W/UID0002O4 into UID00010L; padding is alignment and `0x00489f80` starts a separate raw constructor-shaped successor. | High | `get_bytes`, successor lookup, current docs. | Parent/child range sections. | excluded-with-reason | excluded-with-reason - padding pages were not created; successor pages were not edited. |
| 10L-C24 | Generated files, coverage reports, validator state, queue/lock files, lifecycle/archive files, and supervisor ledgers must not be manually edited; generated refresh should happen only through scoped validators and supervisor execution. | High | Assignment and B-agent workflow. | Checklist/validator sections. | not-applicable | excluded-with-reason - no manual generated/coverage/state/lifecycle/supervisor edits were made; scoped validators reported generated refresh deferred. |

## Positive Evidence Summary
- Direct IDA facts support current target bounds: four exact functions, exact sizes, not-function probes at child ends, and byte-confirmed padding.
- Direct IDA facts support behavior: constructor vtable writes, six packet string decodes, DLGCLAN2 resource refs, action handler field writes/derived dispatch, validation control checks, and input-event forwarding through `g_pClanStatusPane`.
- Documentation evidence supports names and route: current layout/class/submitter/helper docs agree on the submitted-field offsets and descriptive names; Clan source route remains active and stronger than one-off ClanDialogs migration.
- The strongest inference chain is: vtable stores and resource strings identify the class as `ClanAttrInputDialog`; field writes and derived submitter callers identify the DLGCLAN2 submitted-field layout; caller/xref sets identify construction and virtual reachability; by-file and split-candidate docs keep active source emission under `NexusTK/social/Clan.cpp`.

## IDA MCP Facts
- Function/range facts: `sub_489600` at `0x00489600` size `0x7e1`; `sub_489DF0` at `0x00489df0` size `0xc7`; `sub_489EC0` at `0x00489ec0` size `0x86`; `sub_489F50` at `0x00489f50` size `0x30`; no functions at `0x00489de1`, `0x00489eb7`, `0x00489f46`, or `0x00489f80`.
- Data/table/padding facts: vtable base refs at `0x00615d58`, `0x00615dbc`, `0x00615dec`; DLGCLAN2 refs at `0x0061644c`; `0xcc` alignment at all three internal gaps; successor raw constructor bytes start at `0x00489f80`.
- Xref facts: five xrefs to constructor start; handler starts only have vtable data refs; `g_pClanStatusPane` global has target use at `0x00489f60` and sibling submitter/helper uses.
- Vtable/global/type facts: three vtable stores in constructor; handler xrefs match primary/secondary/tertiary vtable slots in modal dialog family; `g_pClanStatusPane + 0xa0` secondary view is used for input-event forwarding.
- Negative IDA facts: no modeled functions at aggregate internal ends or successor raw constructor start; no direct code callers to the three virtual handlers in current xrefs; no direct owner evidence for [UID:0000IA] over UID00010L alone.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00489600-0x00489f80` | [UID:00010L] `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md` | Aggregate DLGCLAN2 base dialog core / split index | false | [UID:000024] | applied `90/92` | Reclassified as non-emitting split index with blank formal C++. |
| `0x00489600-0x00489de1` | [UID:0004HH] `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md` | Constructor and DLGCLAN2 layout builder | true | [UID:000024] | applied `86/90` | Child created; constructor no-code proof applied. |
| `0x00489de1-0x00489df0` | padding inside UID00010L | 15-byte alignment | false | n/a | n/a | Document as `0xcc` padding, not source. |
| `0x00489df0-0x00489eb7` | [UID:0004HI] `by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md` | OK/cancel handler and derived confirmation dispatch | true | [UID:000024] | applied `86/90` | Child created; action-handler no-code proof applied. |
| `0x00489eb7-0x00489ec0` | padding inside UID00010L | 9-byte alignment | false | n/a | n/a | Document as `0xcc` padding, not source. |
| `0x00489ec0-0x00489f46` | [UID:0004HJ] `by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md` | Required-field OK-state updater | true | [UID:000024] | applied `89/91` | Child created; exact formal C++ block applied. |
| `0x00489f46-0x00489f50` | padding inside UID00010L | 10-byte alignment | false | n/a | n/a | Document as `0xcc` padding, not source. |
| `0x00489f50-0x00489f80` | [UID:0004HK] `by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md` | Input event forwarder/base handler | true | [UID:000024] | applied `89/91` | Child created; exact formal C++ block applied. |
| `0x00489f80-0x00489fb5` | [UID:00021W] `ClanEnlistInputDialogRawConstructor` | Raw derived constructor-shaped successor | true | [UID:00002B] | support page current `85/90` | Separate target; not edited here. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004852e9` | code xref to `0x00489600` in `sub_484F70` | Modeled constructor caller from Clan status packet dispatcher family. |
| `0x00487f2f` | code xref to `0x00489600` in `sub_487EA0` | Modeled constructor caller in dialog-handler island. |
| `0x004883e8` | code xref to `0x00489600` in `sub_488370` | Modeled constructor caller in dialog-handler island. |
| `0x00489f8d` | raw code xref to `0x00489600` with no containing function | Derived raw constructor call in `ClanEnlistInputDialogRawConstructor`. |
| `0x00489ffd` | raw code xref to `0x00489600` with no containing function | Derived raw constructor call in `ClanChangeInputDialogRawConstructor`. |
| `0x00615da0`, `0x00615e40`, `0x00615ee0` | data xrefs to `0x00489df0` | Virtual action handler slots; no direct code callers expected. |
| `0x00615da4`, `0x00615e44`, `0x00615ee4` | data xrefs to `0x00489ec0` | Virtual validation slots; no direct code callers expected. |
| `0x00615dc0`, `0x00615e60`, `0x00615f00` | data xrefs to `0x00489f50` | Virtual input-event slots; no direct code callers expected. |
| `0x00489914`, `0x00489d5c` | data refs to `0x0061644c` | Constructor uses full UTF-16 `DLGCLAN2.EPF` string, not suffix label. |
| `0x00489f60` | data ref to `0x0067ade4` | `OnInputEvent` forwards through `g_pClanStatusPane` secondary view. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target UID00010L already documents the core behavior, exact current target span, field offsets, controls, virtual dispatch, and Clan source route.
  - [UID:000024] emits the class declaration shell and `[[CHILDREN]]`, matching the source-shape need for child method bodies rather than one aggregate body.
  - [UID:0001TY] already has exact half-open UID00010L function bounds and submitted-field names.
  - [UID:0000I8] already lists `ClanAttrInputDialog` under `NexusTK/social/Clan.cpp`.
  - [UID:0000IA] explicitly remains a split candidate and warns against one-off migration.
  - Vtable/resource docs already carry the vtable bases and `DLGCLAN2.EPF` refs.
- Existing docs that are stale, incomplete, or contradicted:
  - Target formal no-code comment uses stale child ends `0x00489de0`, `0x00489eb6`, `0x00489f45`; current IDA half-open ends are `0x00489de1`, `0x00489eb7`, `0x00489f46`.
  - [UID:000024] method notes use the same stale child ends and its `OnInputEvent` row says it refreshes validation after input changes. Current IDA shows event type `3` forwarding through `g_pClanStatusPane` and base handler call; validation is the separate `0x00489ec0` helper.
  - B007's older no-code proof says final widget/member names block UID00010L; field names are now stronger after B004/B010, but the aggregate/split and large constructor helper-name issues still justify no-code.
- Generated/coverage report state: generated tracker reports UID00010L has `Reports:0`. Generated `Clan.cpp` inherits the target formal marker and will remain stale until supervisor-approved target edits are validated/refreshed; B009 did not edit generated files.

## Ranked Ownership Analysis
### 1. [UID:0000I8] Clan / `NexusTK/social/Clan.cpp`
- Evidence for: current target metadata; `Clan.md` source map; DLGCLAN2 resource and Clan modal dialog family; constructor callers from Clan status/dialog handler island; submitted-field consumers UID0002O3 and UID0002O5 route through Clan source; current generated route.
- Evidence against: possible final split to `ClanDialogs.cpp` remains plausible for the modal dialog island.
- Decision: keep as the source file route, not as the post-split direct owner/emitter for UID00010L. After child creation, [UID:0000I8] should remain the parent source route through [UID:000024] `ClanAttrInputDialog`, while direct child method ownership/emission moves to the class.

### 2. [UID:000024] ClanAttrInputDialog class
- Evidence for: the code is a class constructor plus class virtual handlers; support class page clears `86/89`, emits declaration shell, and is the direct owner for the implemented exact child method pages.
- Evidence against: changing only the aggregate owner without child creation would churn route semantics and still leave the source-body split unresolved.
- Decision: accept as the direct owner for the split family after callback. Reclassify UID00010L to a class-owned non-emitting split index and make the four child method pages class-owned/emitted through [UID:000024] so bodies route through the class `[[CHILDREN]]`.

### 3. [UID:0000IA] ClanDialogs / `NexusTK/ui/dialogs/ClanDialogs.cpp`
- Evidence for: documented split-candidate file for Clan modal dialogs; candidate contents include `ClanAttrInputDialog`.
- Evidence against: page explicitly says current stronger owner is [UID:0000I8]; one-off migration would desynchronize base cores, vtables, raw constructors, derived submitters, and current generated route.
- Decision: reject for this report. Keep it as a coordinated source-layout candidate only; do not use it for the UID00010L split callback.

### 4. Vtable/resource/global pages
- Evidence for: vtable data, DLGCLAN2 resource strings, and `g_pClanStatusPane` are important dependencies.
- Evidence against: they are support evidence, not owners of method bodies.
- Decision: reject as direct owners for UID00010L.

### 5. No-owner/non-emitting
- Evidence for: none sufficient; code is source-authored class behavior and already has a valid Clan route.
- Evidence against: exact vtable/class/source route, constructor callers, and support docs prove source ownership.
- Decision: reject.

## Source Placement
- Recommended source file/class/global/module placement: keep the source file route under [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp`, but implement the direct source-body split under [UID:000024] `ClanAttrInputDialog`. UID00010L becomes a non-emitting class split index; the four child pages become class-owned emitters.
- Why this placement fits source-tree and subsystem context: DLGCLAN2 modal behavior, Clan status-pane callers, opcode `0x4b` derived submitters, modal vtable data, and resource strings all live in the Clan modal dialog family under the current social feature source.
- Rejected placements and why:
  - `NexusTK/ui/dialogs/ClanDialogs.cpp`: plausible coordinated split but not current one-off target owner.
  - `ClanStatusPane`: constructor callers and input forwarding use status-pane state, but the class body belongs to `ClanAttrInputDialog`.
  - Derived classes `ClanEnlistInputDialog` and `ClanChangeInputDialog`: they inherit and call into this base but do not own the base constructor/handlers.
- Remaining placement uncertainty: final original source may have had a modal-dialog split, but current docs do not justify moving UID00010L or its children to `ClanDialogs.cpp` during this callback. This uncertainty is a confidence cap, not a blocker to creating class-owned child pages under the active `Clan.cpp` route.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts:
  - Target span is `0x00489600-0x00489f80`.
  - Four contained functions have exact current half-open ranges `0x00489600-0x00489de1`, `0x00489df0-0x00489eb7`, `0x00489ec0-0x00489f46`, and `0x00489f50-0x00489f80`.
  - Internal gaps are padding, not source code.
  - Successor `0x00489f80` is not a function and begins the separate raw constructor-shaped UID00021W range.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - Create `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md` for the constructor/DLGCLAN2 layout builder.
  - Create `by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md` for the OK/cancel action handler and derived confirmation dispatch.
  - Create `by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md` for the required-field OK-state updater.
  - Create `by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md` for the event type `3` status-pane forwarder and base handler tail.
  - Do not merge UID00021W or UID0002O4 into UID00010L.
  - Padding remains documented as alignment inside the parent aggregate and does not receive source bodies.
- Parent/container impact: reclassify UID00010L from a reconstructable aggregate emitter into a non-emitting split index with class ownership. Its formal C++ block should be blank after the child pages exist; source/no-code decisions live on the children.

## Split Implementation Plan
- Parent after split:
  - Path: `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md`.
  - Metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`.
  - Formal C++: blank, because non-emitting parent pages must not carry source bodies or marker comments once children carry the exact method dispositions.
  - Item summary/source notes: describe UID00010L as the DLGCLAN2 `ClanAttrInputDialog` split index over four function child pages plus internal `0xcc` alignment padding.
- Child 1:
  - Path/title: `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md`, `ClanAttrInputDialogConstructor`.
  - Implemented metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, `EMITTER_POSITION_OPTIONAL:1`.
  - Formal C++ disposition: marker-only no-code proof. Current MCP proves exact construction behavior, but final source-quality constructor emission is unsafe because the 663-instruction body still uses unresolved UI framework helper/control-construction names and unrecovered exact UI label strings.
- Child 2:
  - Path/title: `by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md`, `ClanAttrInputDialogOnDialogAction`.
  - Implemented metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, `EMITTER_POSITION_OPTIONAL:2`.
  - Formal C++ disposition: marker-only no-code proof. Current MCP proves OK/cancel, field stores, parse, close, and slot `+0x5c` dispatch, but final emission is unsafe until the base confirmation-hook source name/signature is reconciled with derived submitter pages that currently use different source-facing names.
- Child 3:
  - Path/title: `by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md`, `ClanAttrInputDialogValidateInputFields`.
  - Implemented metadata: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, `EMITTER_POSITION_OPTIONAL:3`.
  - Formal C++ disposition: emit the exact `ValidateInputFields` formal block in `First-Draft C++ Recommendation`.
- Child 4:
  - Path/title: `by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md`, `ClanAttrInputDialogOnInputEvent`.
  - Implemented metadata: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, `EMITTER_POSITION_OPTIONAL:4`.
  - Formal C++ disposition: emit the exact `OnInputEvent` formal block in `First-Draft C++ Recommendation`.
- Support-doc changes:
  - `by-class/ClanAttrInputDialog.md`: add the four child links/ranges in method notes/children, correct `OnInputEvent` behavior, and preserve the existing class declaration with `[[CHILDREN]]`.
  - `by-file/Clan.md`: keep `ClanAttrInputDialog` under `NexusTK/social/Clan.cpp` and add a concise note that UID00010L is now a non-emitting split index whose method bodies route through [UID:000024] children.
  - `by-file/ClanDialogs.md`, `by-type/by-struct/ClanInputDialogLayouts.md`, vtable, modal-vtable-data, and resource-string docs: no edit required because they already contain same-or-greater support facts.
- Validators run during callback:
  - `python .\tools\validator.py --mode file --file by-memory\0x00489600-0x00489f80.ClanAttrInputDialogCore.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\ClanAttrInputDialog.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\Clan.md --apply --queue-timeout 240`

## Negative Evidence Summary
- Handler direct callers: current `xrefs_to` found only vtable data refs for `0x00489df0`, `0x00489ec0`, and `0x00489f50`; direct code callers are not expected and should not be invented.
- Source split: `ClanDialogs.cpp` is not accepted as a one-off direct owner; its support doc itself keeps the active route in [UID:0000I8].
- Generated names: IDA `sub_` names and `unk_67ADE4` are not source names. Use them only as evidence labels.
- Formal aggregate C++: a single parent formal body would either merge multiple source methods into one block or require a large source draft for a 663-instruction constructor with many unresolved UI helper names. Current evidence does not justify that as final-output source.
- Class support wording: `OnInputEvent` is not the validation refresh function; validation remains `0x00489ec0`.
- Raw constructor successor: `0x00489f80` is a separate no-function raw constructor-shaped body and not tail padding for UID00010L.

## IDA Rename / Type / Comment Recommendations
- Implemented source-facing names/types/comments:
  - Keep source-facing class/method names `ClanAttrInputDialog::ClanAttrInputDialog`, `OnDialogAction`, `ValidateInputFields`, and `OnInputEvent`.
  - Keep accepted descriptive member names `m_submittedClanName`, `m_submittedDescriptionText`, `m_submittedAttributeText`, and `m_submittedAttributeType` with exact-label caveats.
  - Keep global source name `g_pClanStatusPane` for `0x0067ade4` when documenting input forwarding.
- Evidence for each implemented name/type/comment: current class declaration, accepted submitter/helper reports, field offset consumers, vtable slots, and current MCP decompilation.
- Items intentionally left unchanged and why: UI helper calls such as `sub_4991F0`, `sub_49DC10`, `sub_49EC80`, etc. are not renamed in this report because their exact framework names are outside UID00010L and not conclusively recovered here.
- IDA DB edits: not requested and not made.

## First-Draft C++ Recommendation
- Parent UID00010L after split is not eligible for source emission because it becomes a non-emitting split index. Use this exact blank formal block for the parent after creating the children:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Child `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md` should use this exact formal no-code proof:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body yet: current MCP proves the exact ClanAttrInputDialog DLGCLAN2 construction range, base call, vtable stores, six packet-string decodes, persistent submitted-field storage, and resource setup, but the 663-instruction UI-construction body still has unresolved final source names for framework helper/control-construction calls and original UI labels. Keep this child reconstructable with evidence until a constructor-specific helper-name pass can emit source-quality C++.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Child `by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md` should use this exact formal no-code proof:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone action-handler body yet: current MCP proves OK id 1 reads controls 8, 9, and 10, stores the submitted description/attribute/type fields, dispatches primary vtable slot +0x5c, and closes while cancel id 2 only closes. Emitting compilable C++ is unsafe until the shared confirmation-hook source name/signature is reconciled with derived submitter pages that currently use distinct source-facing submit method names.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Child `by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md` should use this exact formal C++ block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ClanAttrInputDialog::ValidateInputFields()
{
    ImageButtonControlPane *okButton =
        static_cast<ImageButtonControlPane *>(GetChildControl(1));
    TextEditControlPane *descriptionEdit =
        static_cast<TextEditControlPane *>(GetChildControl(8));
    TextEditControlPane *attributeEdit =
        static_cast<TextEditControlPane *>(GetChildControl(9));
    TextEditControlPane *typeEdit =
        static_cast<TextEditControlPane *>(GetChildControl(10));

    okButton->SetEnabled(!descriptionEdit->IsEmpty() &&
        !attributeEdit->IsEmpty() &&
        !typeEdit->IsEmpty());
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Child `by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md` should use this exact formal C++ block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ClanAttrInputDialog::OnInputEvent(const InputEvent &event)
{
    if (event.type == 3) {
        g_pClanStatusPane->ForwardInputEvent(event);
    }

    return DialogPane::OnInputEvent(event);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason this resolves the source-body blocker: the parent no longer tries to emit a multi-method aggregate. Two children receive source-quality formal C++ from direct decompile/control evidence and adjacent accepted naming precedent; two children receive exact child-local no-code proofs with the specific unresolved source issues and capped scores.
- Source-facing names used: class and method names are stable; member fields are accepted descriptive names; helper names remain unresolved only for the constructor/action no-code children.
- Third-party import directive: not applicable.

## Final Recommendation
- Exact changes recommended:
  - Parent target doc: reclassify UID00010L to a non-emitting class split index with `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position, blank formal C++, current MCP provenance/evidence, exact ranges, padding, xrefs, and rejected alternatives.
  - Created four child by-memory pages at the exact ranges in `Split Implementation Plan`, with the accepted metadata and formal C++/no-code blocks above.
  - Support doc [UID:000024]: add/link the four child ranges, keep the class declaration with `[[CHILDREN]]`, correct method-note half-open ranges, and replace `OnInputEvent` "Refreshes validation" wording with current event-forwarding/base-handler behavior.
  - Support doc [UID:0000I8] `by-file/Clan.md`: preserve `NexusTK/social/Clan.cpp` as source route and add the split-index/child-routing note.
  - Support docs [UID:0000IA], [UID:0001TY], [UID:0001X9], [UID:0002MN], [UID:0003B9], UID0002O3, and UID0002O5: checked as support evidence and intentionally no-edit because already present at same-or-greater detail.
- Exact parent assignments recommended: UID00010L becomes class-owned non-emitting split index; child pages become class-owned/class-emitted through [UID:000024], and the file route remains [UID:0000I8] `Clan`.
- Exact items left no-owner/non-emitting: padding gaps only; they are alignment bytes, not separate source bodies. No source-authored child is left no-owner.
- No remaining main blocker: child split, parent impact, support-doc changes, child C++/no-code decisions, validators, and score impact are specified here for callback implementation.

## Recommended Target Doc Changes
- Parent target path: `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md`.
- Exact report facts to incorporate:
  - Current MCP session `supervisor_recovery_20260705`, server health OK, NexusTK IDB active.
  - Function starts/sizes and exact half-open child ranges.
  - Internal padding byte facts and raw constructor successor at `0x00489f80`.
  - Constructor vtable stores, six string decodes, first string persistence at `+0x26c`, DLGCLAN2 refs, and unresolved helper-name caveat.
  - Action/validation/input-event current decompile facts.
  - Xrefs: three modeled constructor callers, two raw derived-constructor calls, vtable-only handler refs, resource/global refs.
  - Accepted descriptive submitted-field names and exact original-label caveat.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `COMPLETION:85` to `COMPLETION:90`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Change `CANONICAL_OWNER:0000I8` to `CANONICAL_OWNER:000024`.
  - Change `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE`.
  - Clear `EMITTER_UIDS`.
  - Keep blank `EMITTER_POSITION_OPTIONAL`.
  - Replace the parent formal marker with the exact blank formal block in `First-Draft C++ Recommendation`.
- New child target docs to create:
  - `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md`: metadata `86/90`, owner/emitter `000024`, reconstructable true, optional position `1`, constructor evidence, formal no-code proof.
  - `by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md`: metadata `86/90`, owner/emitter `000024`, reconstructable true, optional position `2`, action evidence, formal no-code proof.
  - `by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md`: metadata `89/91`, owner/emitter `000024`, reconstructable true, optional position `3`, validation evidence, exact formal C++ block.
  - `by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md`: metadata `89/91`, owner/emitter `000024`, reconstructable true, optional position `4`, input-event evidence, exact formal C++ block.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Historicalize the old inclusive-looking child-end marker.
  - Preserve the no-standalone-parent-body proof, but update rationale from "field names unresolved" alone to "parent is a non-emitting split index; constructor/action child bodies have exact no-code proofs."
  - Preserve rejected `ClanDialogs.cpp` one-off migration, generated/IDA names, and handler direct-caller absence.

## Recommended Support Doc Changes
- Support path: `by-class/ClanAttrInputDialog.md`.
  - Exact report facts to incorporate:
    - Add/link child pages `0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md`, `0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md`, `0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md`, and `0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md` beside the existing declaration and `[[CHILDREN]]`.
    - In `Method Notes`, change core method ranges to `0x00489600-0x00489de1`, `0x00489df0-0x00489eb7`, `0x00489ec0-0x00489f46`, and `0x00489f50-0x00489f80`.
    - Change the `OnInputEvent` role from validation refresh to event type `3` forwarding through `g_pClanStatusPane` secondary view followed by base input-event handler.
    - Add a 2026-07-05 B009 support note that current MCP session `supervisor_recovery_20260705` reconfirmed the ranges, padding, handler behavior, target split-index disposition, and child C++/no-code split.
  - Metadata/link/score/coverage/source-placement changes: no class metadata change recommended; the class declaration route remains [UID:0000I8] through `Clan.cpp`.
- Support path: `by-file/Clan.md`.
  - Exact report facts to incorporate: keep `ClanAttrInputDialog` under `social/Clan.cpp`; add a concise note that UID00010L is now a non-emitting split index and the four method child pages route through [UID:000024] `ClanAttrInputDialog`.
- Support path: `by-file/ClanDialogs.md`.
  - Exact report facts to incorporate: no edit required; it already documents `ClanDialogs.cpp` as a split candidate only and warns against one-off migration while [UID:0000I8] remains stronger.
- Support path: `by-type/by-struct/ClanInputDialogLayouts.md`.
  - Exact report facts to incorporate: no edit required; it already has exact half-open UID00010L ranges, submitted-field offsets/names, control ids, source-layout impact, and the original-label caveat.
- Support path: `by-type/by-vtable/ClanDialogVtableFamily.md` and `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`.
  - Exact report facts to incorporate: no edit required; vtable bases/stores for `ClanAttrInputDialog` are already present.
- Support path: `by-memory/0x00616430-0x00616468.ClanModalDialogResourceStrings.md`.
  - Exact report facts to incorporate: no edit required; `DLGCLAN2.EPF` and xrefs from `0x00489914`/`0x00489d5c` are already present.

## Score And Metadata Recommendation
- Pre-callback score/metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`, blank optional emitter position.
- Recommended parent score/metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position.
- Recommended child score/metadata:
  - Constructor child: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, optional position `1`.
  - OnDialogAction child: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, optional position `2`.
  - ValidateInputFields child: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, optional position `3`.
  - OnInputEvent child: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000024`, optional position `4`.
- Score rationale:
  - Parent completion/confidence improve because the aggregate is no longer forced to carry incompatible source-body responsibility; it becomes a fully bounded split index with exact child routing and blank non-emitting formal C++.
  - Constructor/action children remain capped at `86/90` because current evidence is exact enough for boundaries and behavior, but not final enough for safe compilable source bodies.
  - Validation/input-event children clear first-draft source quality at `89/91` because their decompiled behavior is small, direct, and consistent with existing class declarations and adjacent accepted naming precedent.
  - File/source-route confidence stays below final-audit level because `ClanDialogs.cpp` remains a coordinated split candidate and exact UI labels/helper names are unrecovered, but neither issue blocks this child split.
- Score-improvement attempts now resolved:
  - Ownership/source placement was rechecked through [UID:0000I8], [UID:0000IA], vtable/resource docs, generated tracker, and current MCP. Result: direct child ownership should be class [UID:000024], while source file route remains [UID:0000I8].
  - Field-name blocker was rechecked through UID0002O3, UID0002O5, and UID00010F. Result: field names are accepted descriptive names; exact labels remain a confidence cap only.
  - Range/split blocker was rechecked with current MCP and padding bytes. Result: exact split ranges are safe and implementation-ready now.
  - First-draft C++ was reconsidered. Result: parent blank formal, two child no-code proofs, and two child formal C++ blocks are the safest current source-quality outcome.

## Open Questions With Attempted Resolution
- Open question: should UID00010L move to `ClanDialogs.cpp`?
  - Evidence checked: [UID:0000IA], [UID:0000I8], vtable/resource docs, generated route, caller context.
  - Best supported resolution: no one-off move; `ClanDialogs.cpp` is a coordinated split candidate only.
  - Remaining impact: confidence cap only.
- Open question: are submitted-field names exact original symbols?
  - Evidence checked: UID0002O3, UID0002O5, UID00010F, target/layout docs, control ids and helper arguments.
  - Best supported resolution: use accepted descriptive names; exact original UI labels are unrecovered.
  - Remaining impact: confidence cap and constructor/source-text caveat, not owner blocker.
- Open question: can formal C++ be emitted now?
  - Evidence checked: current MCP constructor complexity, handler decompiles, class declaration shell, by-structure aggregate rules, prior B007 no-code proof, adjacent UID00010J source-ready comparison.
  - Best supported resolution: partially. Parent formal C++ must be blank after reclassification; constructor/action children need exact no-code proofs; validation/input-event children can receive the exact formal C++ blocks listed above.
  - Remaining impact: the split blocker is resolved. Constructor/action child scores remain capped until their specific helper/hook-name blockers are resolved.
- Open question: is `OnInputEvent` a validation refresher?
  - Evidence checked: current decompile of `0x00489f50`, target docs, support class docs.
  - Best supported resolution: no; validation is `0x00489ec0`, while `0x00489f50` forwards type `3` events through `g_pClanStatusPane` and calls the base handler.
  - Remaining impact: concrete support-doc repair item.
- Open question: exact UI helper/source API names for constructor controls.
  - Evidence checked: constructor `analyze_function`, callee list, adjacent UID00010J accepted source, current support docs.
  - Best supported resolution: helper roles are known but many final framework names remain unresolved; put this exact no-code proof on the constructor child instead of blocking the parent split.
  - Remaining impact: constructor child completion/confidence cap only.
- Open question: can the action handler body call a named virtual submit hook safely?
  - Evidence checked: current `0x00489df0` decompile, derived UID0002O3/UID0002O5 submitter pages, class declaration shell, vtable slot `+0x5c`.
  - Best supported resolution: no; the slot behavior is proven, but the shared source name/signature is not reconciled with derived pages that currently use distinct source-facing names. Use the action child no-code proof.
  - Remaining impact: action child completion/confidence cap only.

## Validator Results
- Callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`. All listed scoped file validator commands exited `0`; generated refresh was reported as `deferred` / validator-owned. B009 did not edit generated files, coverage reports, validator state, queue/lock files, lifecycle/archive files, supervisor ledgers, or run `execute_report`.
- Parent UID00010L initial validation: `python .\tools\validator.py --mode file --file by-memory\0x00489600-0x00489f80.ClanAttrInputDialogCore.md --apply --queue-timeout 240`
  - `command_id: 000000006940`; `command_timestamp: 2026-07-05T09:59:21-04:00`; exit `0`; `ok: 5`.
  - Side effects: assigned child UIDs `0004HH` through `0004HK`, resolved temporary refs/path updates, updated projected stats, generated refresh deferred.
  - Warning: `missing_ref_uid 0003B9` for the resource string reference; resolved by the next scoped validator.
- Resource support UID mapping repair: `python .\tools\validator.py --mode file --file by-memory\0x00616430-0x00616468.ClanModalDialogResourceStrings.md --apply --queue-timeout 240`
  - `command_id: 000000006941`; `command_timestamp: 2026-07-05T10:00:10-04:00`; exit `0`; `ok: 1`.
  - Side effects: validator inserted blank reconstruction/header mapping for [UID:0003B9], path/registry updates, projected stats update, generated refresh deferred.
  - Warning: `missing_ref_uid 0003BB`, outside UID00010L accepted split scope.
- Parent UID00010L revalidation after UID mapping: same parent command as above.
  - `command_id: 000000006942`; `command_timestamp: 2026-07-05T10:00:23-04:00`; exit `0`; `ok: 1`.
  - Side effects: reference-index add for [UID:0003B9], projected stats update, generated refresh deferred; no missing-ref warning for the parent.
- Constructor child [UID:0004HH]: `python .\tools\validator.py --mode file --file by-memory\0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md --apply --queue-timeout 240`
  - `command_id: 000000006943`; `command_timestamp: 2026-07-05T10:00:30-04:00`; exit `0`; `ok: 1`; no warnings; generated refresh deferred.
- Action child [UID:0004HI]: `python .\tools\validator.py --mode file --file by-memory\0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md --apply --queue-timeout 240`
  - `command_id: 000000006944`; `command_timestamp: 2026-07-05T10:00:41-04:00`; exit `0`; `ok: 1`; no warnings; generated refresh deferred.
- Validation child [UID:0004HJ]: `python .\tools\validator.py --mode file --file by-memory\0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md --apply --queue-timeout 240`
  - `command_id: 000000006945`; `command_timestamp: 2026-07-05T10:00:52-04:00`; exit `0`; `ok: 1`; no warnings; generated refresh deferred.
- Input-event child [UID:0004HK]: `python .\tools\validator.py --mode file --file by-memory\0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md --apply --queue-timeout 240`
  - `command_id: 000000006946`; `command_timestamp: 2026-07-05T10:01:03-04:00`; exit `0`; `ok: 2`; no warnings; generated refresh deferred.
- Class support [UID:000024]: `python .\tools\validator.py --mode file --file by-class\ClanAttrInputDialog.md --apply --queue-timeout 240`
  - `command_id: 000000006947`; `command_timestamp: 2026-07-05T10:01:15-04:00`; exit `0`; `ok: 13`; no warnings; generated refresh deferred.
- Clan file support [UID:0000I8]: `python .\tools\validator.py --mode file --file by-file\Clan.md --apply --queue-timeout 240`
  - `command_id: 000000006948`; `command_timestamp: 2026-07-05T10:01:26-04:00`; exit `0`; `ok: 5`.
  - Side effects: four temporary refs resolved, stats row update for [UID:0000I8], projected stats update, generated refresh deferred.
  - Warnings: `missing_ref_uid: 17`, including [UID:0003HE], [UID:000411], [UID:000412], [UID:000413], [UID:0003B8], and suppressed rows; these are pre-existing/outside UID00010L accepted split scope.

## Changed Files
- Created:
  - `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md` ([UID:0004HH])
  - `by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnDialogAction.md` ([UID:0004HI])
  - `by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md` ([UID:0004HJ])
  - `by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md` ([UID:0004HK])
- Modified by B009:
  - `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md`
  - `by-class/ClanAttrInputDialog.md`
  - `by-file/Clan.md`
  - `tools/leaser/Agents/Agent-B009/research/00010L-ClanAttrInputDialogCore-source-quality.md`
- Validator-managed by-* side effect:
  - `by-memory/0x00616430-0x00616468.ClanModalDialogResourceStrings.md` received validator-owned blank reconstruction/header mapping for [UID:0003B9] while resolving parent `missing_ref_uid`.
- Renamed:
  - None.
- Report execution/lifecycle: supervisor-owned validator command `000000006953` executed a prior copy; supervisor-owned validator command `000000006955` invalidated/de-executed that archive copy back to the active research path for this repair. B009 did not run either lifecycle command and must not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, or manual report moves.

## Implementation Tracking Checklist
Report-only Gate 1 repair pass:
- [x] Gate 1 report repair completed before callback; no by-* docs, generated files, coverage files, validator state, lifecycle/archive files, queue/lock files, or supervisor ledgers were edited in that phase.
- [x] Current target state and MCP evidence recorded from session `supervisor_recovery_20260705`, including exact `lookup_funcs`, xrefs, bytes, decompile/analyze, and `tools/int_convert.py` conversions.
- [x] Split/source-body blocker resolved with an implementation-ready four-child plan before callback.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at SHA256 `1C477B06A52B5DCEB4407381CBC9ECCFEBA90F236E423243FD129D65A7FA596C`.
- [x] Parent target updated: `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md` now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000024`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position, and blank formal C++.
- [x] Child pages created and validated: [UID:0004HH] constructor child `86/90` position `1` with formal no-code proof; [UID:0004HI] action child `86/90` position `2` with formal no-code proof; [UID:0004HJ] validation child `89/91` position `3` with formal `ValidateInputFields` C++; [UID:0004HK] input-event child `89/91` position `4` with formal `OnInputEvent` C++.
- [x] Parent and child docs incorporate MCP session/health, function sizes, exact half-open ranges, xrefs, padding bytes, vtable/resource/global refs, constructor decode, action/validation/input-event decompile facts, field names/caveats, parent split-index proof, and child C++/no-code dispositions.
- [x] `by-class/ClanAttrInputDialog.md` updated with child links/ranges, corrected half-open method ranges, event type `3` forwarding/base-handler wording for `OnInputEvent`, and the 2026-07-05 B009 split sync note.
- [x] `by-file/Clan.md` updated to preserve `NexusTK/social/Clan.cpp` source route and document UID00010L as a non-emitting split index whose method children route through [UID:000024].
- [x] Support docs verified already-present/no-edit: `by-file/ClanDialogs.md`, `by-type/by-struct/ClanInputDialogLayouts.md`, `by-type/by-vtable/ClanDialogVtableFamily.md`, `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`, content of `by-memory/0x00616430-0x00616468.ClanModalDialogResourceStrings.md`, UID0002O3, and UID0002O5.
- [x] Claim And Incorporation Ledger rows `10L-C01` through `10L-C24` updated to `applied`, `already-present`, or `excluded-with-reason`; no accepted claim remains in `proposed` state.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old marker end addresses are superseded; field-name-only no-code blocker is superseded; `ClanDialogs.cpp` one-off route, generated names, direct handler callers, padding pages, and raw successor merge remain rejected.
- [x] Scoped validators run and exact command IDs/timestamps/results/warnings recorded in `Validator Results`.
- [x] Lease use recorded: initial lease on parent/class/Clan at `2026-07-05T13:54:05Z` expired during early validation; re-leased parent, four children, class, and Clan at `2026-07-05T14:00:03Z`; all seven were released after validation. `tools/leaser/Agents/current_leases.md` currently shows no active leases.
- [x] Generated refresh status recorded: scoped validators reported generated refresh deferred; B009 did not manually edit generated files, coverage reports, validator state, queue/lock files, lifecycle/archive files, executed-report records, or supervisor ledgers.
- [x] B009 did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, manual report moves, generated edits, coverage edits, or validator-state edits.
- [x] Remaining accepted items: none blocked or unapplied. Remaining warnings are outside UID00010L accepted split scope and recorded above.

Invalidation/rework lifecycle-text repair pass:
- [x] Validator `invalidate_execute` command `000000006955` historicalized in `Supporting Research` and `Current Target State`.
- [x] Stale false current-state text about unexecuted/unarchived lifecycle status removed/corrected.
- [x] Validator-owned `VALIDATOR-REPORT-HISTORY` footer preserved unchanged.
- [x] Required B-agent report sections rechecked against the skill-local report template: core target/current-state, evidence, ledger, positive/negative evidence, ownership/source placement, split/reclassification, C++ decision, final recommendation, target/support recommendations, score/metadata, open questions, validator results, changed files, and implementation checklist are present with target-specific content.
- [x] No by-* docs, generated files, coverage reports, validator state, queue/lock files, executed archives, supervisor ledgers, lifecycle commands, manual report moves, or `execute_report` commands were touched during this lifecycle-text repair.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000006953","destination_path":"executed-b-agent-research/B009/00010L-ClanAttrInputDialogCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00010L-ClanAttrInputDialogCore-source-quality.md","timestamp":"2026-07-05T10:16:20-04:00","uid":"00010L"} -->
<!-- {"agent":"B009","command_id":"000000006955","destination_path":"tools/leaser/Agents/Agent-B009/research/00010L-ClanAttrInputDialogCore-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/00010L-ClanAttrInputDialogCore-source-quality.md","timestamp":"2026-07-05T10:25:14-04:00","uid":"00010L"} -->
<!-- {"agent":"B009","command_id":"000000006956","destination_path":"executed-b-agent-research/B009/00010L-ClanAttrInputDialogCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00010L-ClanAttrInputDialogCore-source-quality.md","timestamp":"2026-07-05T10:29:56-04:00","uid":"00010L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
