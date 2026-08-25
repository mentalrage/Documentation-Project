** TARGET-REPORT-UID:0002QA **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002QA ChangePasswordDialogPaneCore Ownership / Split Research


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0002QA] `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md` at the implemented `88/90`, keep `CANONICAL_OWNER:00001L`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00001L`, keep `EMITTER_POSITION_OPTIONAL` blank, and keep the formal `RECONSTRUCTION_CPP CODE` block blank.
- Final disposition: reconstructable `ChangePasswordDialogPane` core aggregate covering constructor, action, validation, dispatcher, and submit methods. Current MCP closes the stale packet-sender/reply-helper blockers and confirms exact range/caller/child relationships, but it does not make a safe combined class-level C++ block possible for this aggregate.
- Required action: accepted target and narrow support doc updates were applied with current B013 MCP session `supervisor_recovery_20260705` evidence, old-report lead history, child-helper readiness, and exact no-code proof. Generated files and coverage reports were not edited by hand; validator-owned refresh completed during scoped validation.
- Confidence: strong for range, owner/emitter, method inventory, caller/xref routes, packet child relationships, and no-code disposition; capped by unresolved constructor/class member layout, exact UI control/member names, resource/message symbols, and combined aggregate source shape.

## Supporting Research
- Lifecycle/status notes: initial B013 report-only research found no prior UID0002QA direct B-agent report. Supervisor Gate 1 accepted that artifact, then an implementation callback applied the accepted by-* changes and scoped validators. Validator-owned lifecycle records determine the artifact's later location/status after any supervisor action.
- Report-only boundary and callback boundary: the initial report-only pass edited no by-* docs and ran no validators. The implementation callback edited only the approved target/support by-* docs plus this report's status sections, ran scoped validators only, and did not run `execute_report`, execute dry-runs/probes, registry lifecycle commands, manual report moves, archive moves, or supervisor-ledger edits.
- MCP availability: IDA MCP was available and used through `http://127.0.0.1:13337/mcp`. JSON-RPC `initialize` returned `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`; `tools/list` was checked before schema-dependent calls.

## Target
- Target UID: `0002QA`.
- Target path: `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`.
- Source queue/report row before implementation: `auto-generated/-ag-research-tracker.md` listed UID0002QA in by-memory not-covered reconstructable work at `86/89`, average `87.5`, `RECONSTRUCTABLE:true`, direct report count `0`.
- Supervisor classification history: report-only source-quality assignment passed Gate 1; implementation callback completed by B013 without running supervisor-owned execute/lifecycle commands.
- Current scores and parent state after implementation: target records `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00001L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001L`, blank emitter position, blank formal C++.

## Current Target State
- Existing metadata before callback: `86/89`, owner/emitter [UID:00001L] `ChangePasswordDialogPane`, reconstructable true. Implemented metadata after callback: `88/90`, owner/emitter/reconstructable unchanged.
- Existing owner/emitter/reconstructable state: correct. The core is a `ChangePasswordDialogPane` class aggregate; its generated source route remains `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp` through the class/file family.
- Existing C++/emitter state: formal C++ is blank. Generated `ChangePasswordDialogPane.cpp` emits concrete code for sibling/child pages UID0002QB, UID0002QC, UID0002QD, UID0002QE, and UID0002XM, while UID0002QA remains an empty emitter marker now refreshed as `Completion:88 | Confidence:90`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: target text still treats constructor/control-field declarations, exact member names, resource/message meanings, and broad class grouping as final C++ blockers. This report confirms those remain real blockers, while the older statement that packet sender/reply targets are blockers is now stale because those children have source-ready reports/implementations.
- Related target/support docs checked: target, [UID:00001L] `by-class/ChangePasswordDialogPane.md`, [UID:0000I3] `by-file/ChangePasswordDialogPane.md`, [UID:00019U] `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`, [UID:00022W] `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`, children UID0002QB/QC/QD/QE, singleton UID0002XM, [UID:0000TA] `by-global/OpenChangePasswordDialog_4F9060.md`, and generated `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp`.
- Current artifact/lifecycle status: this is the B013 report artifact path submitted for supervisor review; validator-owned lifecycle records determine later location/status after any supervisor action.

## Executive Recommendation
- Keep the direct owner/source family as `ChangePasswordDialogPane`; do not reroute to MainMenuPane, OpenChangePasswordDialog, PacketBuffer, Socket, DialogPane, AlertPane, UID00022W, UID00019U, or no-owner.
- Do not create new split pages in this implementation batch. The target is already an exact core aggregate with documented modeled subranges. Current evidence is enough to improve the target and support docs, but not enough to safely emit combined formal C++ for all five methods.
- Recommended target state: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged as `00001L`, reconstructable true, blank optional emitter position, blank formal C++.
- Exact condition before formal C++ should be added: a later pass must recover or defensibly model the class declaration/member layout, UI control type names, constructor resource/control-building helpers, alert/message symbols, and method signatures/source grouping, or split the five methods into exact child pages with method-specific formal C++ that avoids raw decompiler labels.

## Supervisor Active Recheck
- Supervisor instruction history: Agent-B013 was assigned report-only UID0002QA research for `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`; MCP evidence was mandatory; implementation proceeded only after explicit callback.
- Split repair before final master report: not required for this pass. The current target is an exact half-open aggregate whose internal function starts and padding are now directly confirmed. Candidate method children are documented below, but creating them is not necessary to close the current report-only source-quality item.
- Source-bearing children in scope: adjacent packet children UID0002QB/QC/QD/QE already exist and carry source-ready formal C++ after prior reports. UID0002QA itself remains the core aggregate and should receive evidence/no-code-proof updates rather than formal code.

## Inference Research Guidance Check
- `by-structure.md` supports keeping exact by-memory function/range pages as the source of range evidence and using by-class/by-file pages as owner/source-placement support. The target is source-owned but aggregates multiple methods; blank C++ is acceptable when a target-specific no-code proof explains why formal code would be unsafe.
- Existing assumptions treated as uncertain: generated C++ names, decompiler temporary names, current IDA raw names, old saved-IDB rename claims, and old Wave2/Wave3 wording in historical reports. No Wave2/Wave3 evidence was used as authority.
- Direct IDA facts: current MCP function inventory, xrefs, decompilation summaries, bytes, signatures, strings, vtable refs, singleton refs, and boundary padding.
- Documentation evidence: current by-* docs, generated tracker/coverage state, generated source markers, and executed B-agent reports as leads.
- Inference: source-facing method names such as constructor/action/validation/dispatcher/submit, `accountName`, `currentPassword`, and `newPassword` are supported by caller/control behavior and sibling reports but are not recovered original symbols for the aggregate.

## Heuristic / Inference Reanalysis And Validation
- Owner/emitter route: best owner remains [UID:00001L] `ChangePasswordDialogPane` with file support [UID:0000I3]. The constructor, validation, action, submit, dispatcher, packet sender, reply handlers, and singleton all form one dialog feature. MainMenu/OpenChangePassword only launch the dialog; packet/network helpers are callees/support.
- Range and split: current MCP `entity_query` over `0x004fdd40-0x004fe790` finds exactly five functions: `0x004fdd40` size `0x720`, `0x004fe460` size `0x2e`, `0x004fe490` size `0x96`, `0x004fe530` size `0x26`, and `0x004fe560` size `0x222`. The internal padding at `0x004fe48e-0x004fe490`, `0x004fe526-0x004fe530`, `0x004fe55b-0x004fe560`, and terminal padding `0x004fe782-0x004fe790` is confirmed by lookup/bytes.
- Constructor shape: current MCP confirms `sub_4FDD40` size `0x720` / 1824 bytes, callers from active `MainMenuPane::ActivateMenuItem` at `0x004f7b49` and retained `OpenChangePasswordDialog` at `0x004f90a0`, vtable writes to `0x0061d6ac`, `0x0061d70c`, `0x0061d73c`, singleton publish/fallback clear at `0x004fdd96`/`0x004fdd9d`, high-resolution resource strings `DLGPASS.EPF` and `DLGPASS.PAL`, and low-resolution `DLGPASS.EPD` support. The body still calls many unresolved UI construction helpers and uses exact rectangles/control IDs without safe final source names.
- Action helper: current MCP confirms `sub_4FE460` size `0x2e` / 46 bytes. Action id `1` calls submit helper `0x004fe560`; action id `2` calls slide/close helpers. Vtable data xref is `0x0061d6f4`.
- Validation helper: current MCP confirms `sub_4FE490` size `0x96` / 150 bytes. It retrieves controls `1`, `3`, `4`, `5`, and `6`, tests text emptiness through `sub_498C60`, and dispatches through virtual slots `+0x50` and `+0x4c`. Vtable data xref is `0x0061d6f8`.
- Dispatcher helper: current MCP confirms `sub_4FE530` size `0x26` / 38 bytes. It reads the packet pointer at argument `+12`, checks packet type `2`, calls UID0002QD at `0x004fe551`, and otherwise returns `0`. Vtable data xref is `0x0061d71c`.
- Submit helper: current MCP confirms `sub_4FE560` size `0x222` / 546 bytes, sole caller `0x004fe484` from action helper, reads controls `3`, `4`, `5`, and `6`, copies each into 16-wide-character locals with max count `15`, checks control `5` for at least one ASCII digit, compares control `5` to confirmation control `6`, focuses control `5` and shows alert text on failure, constructs the dimmer/loading object with `sub_559B90(..., 5, dword_67A7CC)` on success, and calls UID0002QC at `0x004fe778` with controls `3`, `4`, and `5` only.
- Packet child blockers: superseded. UID0002QC is now source-ready active `SendPasswordChangeRequest`; UID0002QD is source-ready active type-2 reply handler; UID0002QB and UID0002QE are source-ready retained helpers with documented no-route caps. Their prior reports are support evidence, not a substitute for this direct UID0002QA report.
- Formal C++ blocker: still active for the aggregate. A combined C++ block would have to model constructor resource/control setup, inherited base calls, control manager access, UI classes, method signatures, vtable-adjusted receiver offsets, message resource names, alert helper names, and class declaration placement. Current evidence would either emit raw `sub_`/`off_` labels or invent unproven members.
- Rejected alternatives: MainMenu/OpenChangePassword owner, UID00022W packet-helper owner, Socket/g_packetSender owner, PacketBuffer owner, DialogPane/AlertPane owner, merging into mixed UID00019U, treating UID0002QA as covered by child packet reports, no-owner/non-emitting, or adding formal C++ now.

## Evidence Standards Used
- Evidence types used: IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `xrefs_to`, `analyze_function`, `get_bytes`, `make_signature_for_range`, `get_string`, `int_convert`; current by-* docs; generated tracker/coverage/source output; and executed old B-agent reports as leads.
- Evidence strength: direct current MCP proves range, xrefs, function inventory, body summaries, boundary bytes, vtable refs, string resources, singleton refs, child-helper calls, and negative boundary facts. Existing docs corroborate field roles and accepted child helper names.
- Confidence limits: IDA still reports raw function names for the five core methods, exact original source symbols are absent, constructor class layout remains broad, and generated output only proves current documentation state, not original source declarations.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `initialize` id `1`, `tools/list` ids `2`/`3`/schema checks, `idb_list` id `10`, `server_health` id `11`.
  - `lookup_funcs` id `12` for `0x004fdd33`, `0x004fdd40`, `0x004fe45f`, `0x004fe460`, `0x004fe48e`, `0x004fe490`, `0x004fe526`, `0x004fe530`, `0x004fe55b`, `0x004fe560`, `0x004fe778`, `0x004fe782`, `0x004fe790`, `0x004fe9e0`, `0x004febf0`, `0x004fee40`, `0x004f9060`, `0x004f7a10`, and `0x0069b48c`.
  - `entity_query` id `13` for functions in `0x004fdd40-0x004fe790`.
  - `xrefs_to` id `14` for core functions, active sender/reply, and singleton.
  - `analyze_function` ids `20` through `24` for the five core functions.
  - `get_bytes` ids `34`, `36`, and `59` for predecessor padding, internal gaps, submit/sender boundary, vtable bytes, layout globals, singleton slot, and dimmer/global state.
  - `make_signature_for_range` ids `37` through `42` for the five core subranges and the full aggregate.
  - `get_string` id `58` for `DLGPASS.PAL`, `DLGPASS.EPF`, `DLGPASS.EPD`, and supporting literal addresses.
  - `int_convert` id `35` for size/constant conversions including `0x720`, `0x2e`, `0x26`, `0x222`, `0x26c`, `0x100`, `0x0f`, `0x58`, `0x1fc`, `0x214`, `0x66da97`, `0x69b48c`, and `0x67a7cc`. The `0x96` conversion was retried conceptually from the size returned by `lookup_funcs`; the first auto-size conversion returned a one-byte-size error, so the decimal `150` comes from `analyze_function` size and existing docs.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target UID0002QA, class/file support, parent mixed aggregate UID00019U, packet aggregate UID00022W, children UID0002QB/QC/QD/QE, singleton UID0002XM, OpenChangePasswordDialog support, generated `ChangePasswordDialogPane.cpp`, `-ag-research-tracker`, `-ag-memory-coverage`, and `-ag-coverage-report-by-memory`.
  - Old reports opened as leads: B010 UID00019Q, B003 UID0002XM, B004/B005 UID0002QB, B009 UID0002QC, B002 UID0002QD, B006 UID0002QE, B001 MEMTOOL UID00019U, and B002 MEMTOOL UID0002QB.
- Direct old-report search terms/results:

| Search term | Report hits | Result summary |
| --- | ---: | --- |
| `TARGET-REPORT-UID:0002QA` | 0 | No direct UID0002QA report. |
| `0002QA` | 5 | Lead hits in B001 MEMTOOL UID00019U, B002 UID0002QD, B005 UID0002QB, B006 UID0002QE, B009 UID0002QC. |
| `0x004fdd40` | 10 | Lead hits include UID00019U, UID0002XM, UID0002QB, UID0002QD, UID0002QC, UID00019Q. |
| `0x004fe782` | 13 | Lead hits include UID00019U, UID0002QB/QC/QD/QE and adjacent support reports. |
| `ChangePasswordDialogPaneCore` | 8 | Lead hits only; no direct target report. |
| `ChangePasswordDialogPane` | 15 | Broad lead hits across launcher, singleton, packet helpers, and class/file family. |
| `OpenChangePasswordDialog` | 6 | Direct launcher lead B010 UID00019Q plus support reports. |
| `g_pChangePasswordDialogPane` | 4 | Direct singleton lead B003 UID0002XM plus launcher/cleanup reports. |
| `SendPasswordChangeRequest` | 6 | Direct active sender lead B009 UID0002QC and raw sibling reports. |
| `HandlePasswordChangeReply` | 3 | Direct reply leads B002 UID0002QD and B006 UID0002QE. |
| `RawPasswordChangePacketWithAccount` | 6 | Direct raw sibling leads B004/B005 and B002 MEMTOOL. |
| `ChangePasswordDialogPacketHelpers` | 7 | Packet aggregate leads across UID0002QB/QC/QD/QE and MEMTOOL. |
| `DLGPASS` | 0 | No old-report hit in searched report roots; current MCP and target docs provide direct resource evidence. |
| `0x0069b48c` | 7 | Singleton and launcher/cleanup leads, including B003 UID0002XM and B010 UID00019Q. |
| `00019Q` | 3 | Direct launcher report B010 plus support-family reports. |
| `0002XM` | 4 | Direct singleton report B003 plus support reports. |
| `0002QB` | 7 | Direct raw packet reports B004/B005 and support reports. |
| `0002QC` | 6 | Direct active sender report B009 and support reports. |
| `0002QD` | 3 | Direct primary reply report B002 and support reports. |
| `0002QE` | 2 | Direct simple reply report B006 and support report. |
| `00022W` | 6 | Packet aggregate appears as support in child reports. |
| `0000I3` | 10 | File owner support appears across child reports. |
| `00001L` | 8 | Class owner support appears across child reports. |

- Negative checks performed: no direct UID0002QA old report; no function at `0x004fe782` or `0x004fe790`; no current target-specific evidence that UID0002QB is the active submit sender; no direct owner evidence for MainMenu/OpenChangePassword/PacketBuffer/Socket/DialogPane/AlertPane/no-owner; no safe formal aggregate C++ block.
- Failed, unavailable, or intentionally skipped checks and why: `search_text` probes for constructor resource names used the wrong argument shape and returned no usable structured evidence, so they are not cited. Broad callgraph, broad unbounded search, IDA rename/type/comment edit, define-function, and save operations were intentionally skipped. Validators were intentionally not run in initial report-only mode; scoped implementation validators are recorded below.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0002QA remains a `ChangePasswordDialogPane` class core aggregate owned/emitted by `00001L`. | strong | Target metadata, class/file docs, constructor/action/validation/dispatcher/submit ownership, current MCP xrefs and vtable refs. | Target Status/Ownership Evidence; class/file support rows. | incorporate | applied: target owner/emitter unchanged; class/file support rows updated. |
| C2 | Raise target to `88/90`, not higher. | medium-high | Current direct MCP closes stale evidence and child-helper blockers, but formal C++ remains unsafe. | Target metadata/Score Rationale; class/mixed aggregate child rows. | incorporate | applied: target metadata now `88/90`; class/file/mixed support mention target `88/90`. |
| C3 | Formal C++ remains blank. | strong | Five-method aggregate; unresolved class layout, control/member/resource/helper names, method signatures, and source grouping. | Target Reconstruction Notes/No-Code Proof. | incorporate | applied: target multiline formal C++ remains blank and no-code proof was expanded/preserved. |
| C4 | Core contains exactly five modeled functions in `0x004fdd40-0x004fe790`. | strong | MCP `entity_query` total `5`, `lookup_funcs` boundaries. | Target Address Range/Function Inventory. | incorporate | applied: target evidence notes record exact five-function inventory and padding no-function facts. |
| C5 | Constructor `0x004fdd40` is size `0x720`, called from active menu `0x004f7b49` and retained launcher `0x004f90a0`. | strong | MCP `lookup_funcs`, `xrefs_to`, `analyze_function`. | Target Constructor evidence; class/file support. | incorporate | applied: target, class, file, and mixed support record constructor callers and size context. |
| C6 | Constructor publishes/fallback-clears `g_pChangePasswordDialogPane` and writes three vtables. | strong | MCP `analyze_function`, `xrefs_to 0x0069b48c`, `xrefs_to 0x0061d6ac/70c/73c`, vtable bytes. | Target Touched State/Ownership Evidence. | incorporate | applied: target evidence notes record singleton/vtable refs; support docs preserve singleton as support context. |
| C7 | Constructor resource branches include `DLGPASS.EPF`, `DLGPASS.PAL`, and `DLGPASS.EPD`; exact UI helper/source names remain unresolved. | medium-high | MCP decompile/signature/get_string plus existing target docs. | Target Constructor evidence/no-code proof. | incorporate | applied: target evidence and no-code rationale record resource strings and unresolved helper/source names. |
| C8 | Action helper `0x004fe460` maps action `1` to submit and action `2` to slide/close. | strong | MCP `analyze_function` and vtable data xref `0x0061d6f4`. | Target Method table. | incorporate | applied: existing target method row preserved and current B013 evidence note added. |
| C9 | Validation helper `0x004fe490` checks controls `3`, `4`, `5`, `6` through control `1` and virtual slots `+0x50/+0x4c`. | strong | MCP `analyze_function` and vtable data xref `0x0061d6f8`. | Target Validation evidence. | incorporate | applied: existing target method row preserved and current B013 evidence note added. |
| C10 | Dispatcher `0x004fe530` routes packet type `2` to UID0002QD at `0x004fe551`; otherwise returns `0`. | strong | MCP `analyze_function`, `xrefs_to 0x004febf0`, vtable data xref `0x0061d71c`. | Target Dispatcher evidence; packet-helper support. | incorporate | applied: target/class/file support record dispatcher edge; packet aggregate already had same-or-better detail and was not edited. |
| C11 | Submit `0x004fe560` reads controls `3/4/5/6`, validates control `5`, compares `5` with `6`, and calls UID0002QC with `3/4/5` at `0x004fe778`. | strong | MCP `analyze_function`, `xrefs_to 0x004fe9e0`, bytes at `0x004fe778`. | Target Submit evidence; active sender relationship. | incorporate | applied: target/class/file/mixed support record active sender edge and confirmation-only control distinction. |
| C12 | UID0002QB/QC/QD/QE older reports are leads/support only; UID0002QA needed this direct report. | strong | Old-report search found zero `TARGET-REPORT-UID:0002QA`; current MCP direct recheck completed. | Report Evidence Checked; target Changes/Raw Evidence. | incorporate | applied: target change/evidence note records old reports as leads only and no direct prior UID0002QA report. |
| C13 | No support edits are required for Socket, PacketBuffer, `g_packetSender`, DialogPane, AlertPane, or ResourceLayout docs. | medium-high | Current target behavior uses them as dependencies only; no contradiction found. | Recommended Support Doc Changes. | exclude-with-reason | excluded-with-reason: no contradiction found; those docs were not edited. Packet aggregate, OpenChangePassword, and singleton docs were already same-or-better detail and were not edited. |
| C14 | No manual coverage/tracker text is needed. | strong | Generated `-ag-*` reports are validator-owned; target/source metadata drives refresh. | Exact Manual Supervisor-Owned Coverage Or Tracker Text. | exclude-with-reason | excluded-with-reason: no manual coverage/tracker edits; validator-owned generated refresh completed under command `000000007524`. |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation:
  - MCP session `supervisor_recovery_20260705` is healthy, Hex-Rays ready, auto-analysis ready, and has exact current function inventory for the target range.
  - Constructor, action, validation, dispatcher, and submit helper boundaries match the target page and generated tracker.
  - Xrefs prove constructor callers, action-to-submit, submit-to-active-sender, dispatcher-to-primary-reply, vtable slots, and singleton lifecycle refs.
  - Bytes prove predecessor padding before `0x004fdd40`, internal padding between methods, and terminal padding `0x004fe782-0x004fe790` before raw UID0002QB.
- Corroborating documentation/generated-report evidence:
  - Current target already documents the same method roles and touched state.
  - Child pages UID0002QB/QC/QD/QE now carry source-ready formal C++ and clarify active versus retained routes.
  - Generated `ChangePasswordDialogPane.cpp` contains child helper code and keeps UID0002QA as an empty marker, matching the no-code conclusion.
- Strongest inference chain and why it is sufficient:
  - The target can improve because direct MCP refresh closes stale range/route/packet-child uncertainty. It cannot safely emit aggregate C++ because current facts still stop short of source-level class declaration, member layout, and helper/resource naming.

## IDA MCP Facts
- Function/range facts:
  - `0x004fdd40`: `sub_4FDD40`, size `0x720` / 1824 bytes.
  - `0x004fe460`: `sub_4FE460`, size `0x2e` / 46 bytes.
  - `0x004fe490`: `sub_4FE490`, size `0x96` / 150 bytes.
  - `0x004fe530`: `sub_4FE530`, size `0x26` / 38 bytes.
  - `0x004fe560`: `sub_4FE560`, size `0x222` / 546 bytes.
  - `0x004fe48e`, `0x004fe526`, `0x004fe55b`, `0x004fe782`, and `0x004fe790` are not function starts.
- Data/table/padding facts:
  - `get_bytes 0x004fdd30` shows previous return bytes followed by `0xcc` padding and the `0x004fdd40` prologue.
  - `get_bytes 0x004fe480` shows action helper end, two `0xcc` bytes, and validation prologue at `0x004fe490`.
  - `get_bytes 0x004fe520` shows validation tail, ten `0xcc` bytes, dispatcher prologue at `0x004fe530`, dispatcher tail, ten `0xcc` bytes, and submit prologue at `0x004fe560`.
  - `get_bytes 0x004fe778` shows `call sub_4FE9E0`, a jump back into submit, fourteen `0xcc` bytes from `0x004fe782-0x004fe790`, then UID0002QB raw prologue.
  - `make_signature_for_range` reports unique signatures for constructor, validation, submit, and full aggregate; action and dispatcher signatures are nonunique because they are small thunk-like helpers.
- Xref facts:
  - `xrefs_to 0x004fdd40`: `0x004f7b49` in `sub_4F7A10` and `0x004f90a0` in retained launcher `0x004f9060`.
  - `xrefs_to 0x004fe460`: vtable data `0x0061d6f4`.
  - `xrefs_to 0x004fe490`: vtable data `0x0061d6f8`.
  - `xrefs_to 0x004fe530`: vtable data `0x0061d71c`.
  - `xrefs_to 0x004fe560`: code xref `0x004fe484` from action helper.
  - `xrefs_to 0x004fe9e0`: code xref `0x004fe778` from submit helper.
  - `xrefs_to 0x004febf0`: code xref `0x004fe551` from dispatcher.
  - `xrefs_to 0x0069b48c`: five singleton refs at `0x004f69bf`, `0x004fdd96`, `0x004fdd9d`, `0x005023a0`, and `0x00502656`.
- Vtable/global/type facts:
  - Constructor writes vtable pointers at `0x004fdda7`, `0x004fddb0`, and `0x004fddba` to vtable regions `0x0061d6ac`, `0x0061d70c`, and `0x0061d73c`.
  - `get_string` reads `DLGPASS.PAL` at `0x0061e43c`, `DLGPASS.EPF` at `0x0061e454`, and `DLGPASS.EPD` at `0x0061e46c`.
  - Current session bytes at `0x0066da94` show layout globals including `byte_66DA97`; current session bytes at `0x0069b48c` read `00 00 00 00`, while earlier singleton reports preserve a session-qualified byte-value conflict.
- Negative IDA facts:
  - No function starts at the aggregate-exclusive end or adjacent raw helper start.
  - No current evidence proves UID0002QB as active submit route.
  - No current IDA symbols provide original class/member/control/resource helper names for a safe aggregate C++ block.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004fdd40-0x004fe782` | [UID:0002QA] `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md` | assigned core aggregate | `TRUE` | `00001L` | current `86/89`, recommended `88/90` | keep blank formal C++; update evidence |
| `0x004fdd40-0x004fe460` | part of UID0002QA | constructor | source-authored | `00001L` | covered by aggregate | exact modeled function; no separate child proposed now |
| `0x004fe460-0x004fe48e` | part of UID0002QA | action/command helper | source-authored | `00001L` | covered by aggregate | exact modeled function; action `1` submit, `2` close |
| `0x004fe48e-0x004fe490` | ignored/padding | alignment | not source-authored | UID0002QA context | excluded | two `0xcc` bytes |
| `0x004fe490-0x004fe526` | part of UID0002QA | validation helper | source-authored | `00001L` | covered by aggregate | exact modeled function |
| `0x004fe526-0x004fe530` | ignored/padding | alignment | not source-authored | UID0002QA context | excluded | ten `0xcc` bytes |
| `0x004fe530-0x004fe55b` | part of UID0002QA | reply dispatcher | source-authored | `00001L` | covered by aggregate | packet type `2` to UID0002QD |
| `0x004fe55b-0x004fe560` | ignored/padding | alignment | not source-authored | UID0002QA context | excluded | five `0xcc` bytes |
| `0x004fe560-0x004fe782` | part of UID0002QA | submit helper | source-authored | `00001L` | covered by aggregate | active call to UID0002QC at `0x004fe778` |
| `0x004fe782-0x004fe790` | ignored/padding | terminal alignment | not source-authored | between UID0002QA and UID0002QB | excluded | fourteen `0xcc` bytes |
| `0x004fe790-0x004fe9d1` | [UID:0002QB] raw sibling | retained account/id packet sender | `TRUE` | `0000I3` | `90/90` | source-ready retained helper; not active submit route |
| `0x004fe9e0-0x004febe2` | [UID:0002QC] active sibling | active password-change sender | `TRUE` | `0000I3` | `91/91` | source-ready active sender |
| `0x004febf0-0x004fee11` | [UID:0002QD] active sibling | primary reply handler | `TRUE` | `0000I3` | `91/92` | source-ready active reply handler |
| `0x004fee40-0x004ff03f` | [UID:0002QE] retained sibling | simple reply handler | `TRUE` | `0000I3` | `90/91` | source-ready retained/simple reply helper |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004fdd40` | callers `0x004f7b49`, `0x004f90a0` | constructor reached from active main-menu case and retained launcher |
| `0x004fe460` | data xref `0x0061d6f4` | action helper vtable slot |
| `0x004fe490` | data xref `0x0061d6f8` | validation helper vtable slot |
| `0x004fe530` | data xref `0x0061d71c` | packet dispatcher vtable slot |
| `0x004fe560` | caller `0x004fe484` | action id `1` reaches submit |
| `0x004fe778` | call to `0x004fe9e0` | submit sends through UID0002QC |
| `0x004fe551` | call/jump to `0x004febf0` | dispatcher packet type `2` reaches UID0002QD |
| `0x0069b48c` | refs `0x004f69bf`, `0x004fdd96`, `0x004fdd9d`, `0x005023a0`, `0x00502656` | singleton cleanup, publish/fallback clear, helper clear, destructor clear |
| `0x004fe790` | no function at start; old reports show zero active route | retained raw sibling, not target body and not active submit route |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target already documents the five-method core, constructor resources/controls, action/validation/dispatcher/submit behavior, singleton/vtable/layout/dimmer state, and blank C++ rationale.
  - Class/file support docs attach UID0002QA to `ChangePasswordDialogPane`.
  - UID00019U records UID0002QA as the password-change child in a mixed non-emitting aggregate.
  - UID00022W and children UID0002QB/QC/QD/QE record the adjacent packet-helper cluster and current source-ready child state.
- Existing docs that are stale, incomplete, or contradicted:
  - Target/class/file prose should no longer phrase active packet sender/reply-helper work as a blocker. Those children have been resolved to source-ready status.
  - Any current assertion that older saved IDA rename labels are current proof should remain historical only; current MCP reports raw `sub_4FDD40`, `sub_4FE460`, `sub_4FE490`, `sub_4FE530`, and `sub_4FE560`.
  - Singleton byte-value notes should remain session-qualified because current `supervisor_recovery_20260705` bytes read zero while B003 evidence preserved a conflicting `FF FF FF FF` session.
- Generated/coverage report state:
  - `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp` is validator-owned and currently contains concrete code for UID0002QB/QC/QD/QE and UID0002XM, while UID0002QA remains an empty marker.
  - `auto-generated/-ag-memory-coverage.md` routes UID0002QA as emits through `00001L`, `coded? no`.
  - `auto-generated/-ag-coverage-report-by-memory.md` lists UID0002QA as `emits_code:false`, reconstructable, `86` strong.
  - `auto-generated/-ag-research-tracker.md` lists UID0002QA as `86/89`, average `87.5`, direct report count `0` before this report.

## Ranked Ownership Analysis

### 1. [UID:00001L] ChangePasswordDialogPane
- Evidence for: target metadata, constructor body, vtable writes, singleton lifecycle, action/validation/dispatcher/submit methods, control IDs, class docs, and direct current MCP evidence all point to the class core.
- Evidence against: file-level source output is mediated by [UID:0000I3], and exact class declaration/member names remain incomplete.
- Decision: accepted as canonical owner/emitter for the target; keep unchanged.

### 2. [UID:0000I3] ChangePasswordDialogPane file
- Evidence for: generated source output path, child packet helpers, singleton source declaration, and file support docs all route the broader implementation to `NexusTK/login/ChangePasswordDialogPane.cpp`.
- Evidence against: target metadata uses class UID `00001L` as direct owner/emitter; file page is support/source placement rather than target header owner.
- Decision: support placement only. File support was updated during the implementation callback; target owner remains `00001L`, not `0000I3`.

### 3. [UID:0000L0]/[UID:00019Q] MainMenuPane/OpenChangePasswordDialog
- Evidence for: constructor callers include active main-menu duplicate path and retained launcher.
- Evidence against: those functions construct/open the dialog; they do not own constructor body, validation, submit, dispatcher, packet layout, or reply handling.
- Decision: rejected as target owner; keep as caller/launcher support.

### 4. [UID:00022W] ChangePasswordDialogPacketHelpers
- Evidence for: adjacent helper cluster and packet child relationship.
- Evidence against: UID0002QA precedes the packet-helper cluster and owns core dialog behavior; UID00022W is a support aggregate for adjacent children.
- Decision: rejected as target owner; support doc only.

### 5. Socket, PacketBuffer, DialogPane, AlertPane, MemoryMan, no-owner
- Evidence for: these provide callees/support APIs and inherited UI mechanisms.
- Evidence against: none owns the password-dialog constructor/control/submit/dispatcher feature. No-owner is contradicted by class/file ownership and source behavior.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file proposed. Keep `NexusTK/login/ChangePasswordDialogPane.cpp` as the source placement.
- Likely full contents: existing class/file docs already include constructor/action/validation/dispatcher/submit core, singleton, packet sender/reply helpers, and destructor/cleanup family.
- Candidate related items that belong: UID0002QA, UID0002XM, UID0002QB/QC/QD/QE, and documented lifecycle helpers.
- Candidate related items rejected: MainMenu launcher code remains MainMenuPane-owned; Socket/PacketBuffer/MemoryMan helpers remain support-owned.
- Standalone, narrow, or broad source-file inference: narrow source placement in `ChangePasswordDialogPane.cpp`; broader login/account folding remains a file-level uncertainty but does not alter current owner/emitter.

## Source Placement
- Recommended source file/class/global/module placement: keep UID0002QA with `ChangePasswordDialogPane` class/file family, generated under `NexusTK/login/ChangePasswordDialogPane.cpp`.
- Why this placement fits source-tree and subsystem context: controls, validation, submit, packet dispatch, sender/reply helper children, singleton, and launch lifecycle all belong to password-change login/account UI behavior.
- Rejected placements and why: MainMenu/OpenChangePassword are launchers only; UID00022W is adjacent packet-helper support; Socket/PacketBuffer/MemoryMan are callees; DialogPane/AlertPane are inherited/common UI support; mixed UID00019U is non-emitting physical context.
- Remaining placement uncertainty, if any: exact original source organization could have been folded into a broader login/account file, but current by-file route `ChangePasswordDialogPane.cpp` remains the project convention and generated output path.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: assigned half-open range `0x004fdd40-0x004fe782`; predecessor padding before `0x004fdd40`; internal padding after action, validation, and dispatcher; terminal padding `0x004fe782-0x004fe790` before UID0002QB.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child pages are recommended now. Candidate future children are constructor `0x004fdd40-0x004fe460`, action `0x004fe460-0x004fe48e`, validation `0x004fe490-0x004fe526`, dispatcher `0x004fe530-0x004fe55b`, and submit `0x004fe560-0x004fe782`, with padding left ignored. Creating them would be a topology change and would not by itself solve the unresolved source names.
- Padding/table/data/code distinctions: all internal gaps are `0xcc` alignment. `0x004fe782-0x004fe790` separates the submit helper from raw UID0002QB. No compiler switch table or source data lives inside UID0002QA.
- Parent/container impact: UID00019U remains non-emitting mixed-owner context; UID00022W remains adjacent packet-helper aggregate; no merge/reclassification is recommended.

## Negative Evidence Summary
- No direct UID0002QA old report was found; older child/launcher/singleton reports are leads only.
- Packet child formal C++ does not justify aggregate formal C++. UID0002QC/QD resolve sender/reply behavior, but constructor/control/resource/class layout blockers remain in UID0002QA.
- Current MCP does not recover original class member names, exact UI control field names, exact alert/message resource identifiers, or source declarations for constructor helpers.
- MainMenu/OpenChangePassword constructor xrefs are caller evidence, not target ownership.
- Socket, PacketBuffer, MemoryMan, DialogPane, AlertPane, and globals are support/dependency evidence, not direct ownership.
- UID00019U is physical locality only and is non-reconstructable; it cannot own or emit this core.
- Current bytes at `0x0069b48c` conflict with older singleton byte evidence; byte-value conflict does not change UID0002QA's core ownership or constructor publish/fallback facts.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: keep descriptive documentation names `ChangePasswordDialogPaneCore`, constructor, `OnDialogAction`, validation helper, packet dispatcher, and submit helper as source-facing descriptions only. Do not claim current IDA has these names.
- Evidence for each proposed name/type/comment: method roles are proven by current decompilation and existing class/file docs, but exact original names are not symbol-proven.
- Items intentionally left unchanged and why: no IDA DB rename, type application, stack variable declarations, comments, or saves are requested in this B-agent report.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. B agents must not mutate IDA state for this report.

## First-Draft C++ Recommendation
- Eligible for draft C++: no, not for the aggregate UID0002QA in this pass.
- Recommended code: none. Keep the target formal `RECONSTRUCTION_CPP CODE` block blank.
- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: blank formal C++ avoids emitting a decompiler-shaped or invented class block that would misrepresent unresolved constructor/control/resource/member semantics.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: the original source likely contained class methods and private/static helpers with meaningful member/control/resource names; current evidence has behavior but not enough declarations to recreate that shape for the whole aggregate.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: use prose names such as action helper, validation helper, packet dispatcher, submit helper, `accountName`, `currentPassword`, `newPassword`, and confirmation control only in documentation, not formal C++.
- Naming/coding style convention used and evidence for consistency: child helpers use formal C++ only after exact body/source shape was established. This aggregate does not meet that standard yet.
- Reason code should remain blank, if applicable: UID0002QA spans five methods and a large constructor. Current MCP still exposes raw helper calls (`sub_49D8A0`, `sub_49DC10`, `sub_4B7C50`, `sub_498920`, `sub_495BF0`, `sub_49FEB0`, `sub_559B90`, and others), unresolved UI classes/control member declarations, unresolved resource/message symbolic names, and decompiler receiver adjustments. A formal block would have to invent too much or retain raw labels.
- Exact no-code proof, if not eligible: current MCP directly rechecked every function in the target range, the active sender/reply child routes, vtable refs, singleton refs, resources, boundary bytes, and support docs. Those checks did not recover source-level class layout or method declarations sufficient for formal aggregate C++. The child packet helpers being source-ready removes old packet blockers but does not resolve constructor/control/class blockers. Therefore blank formal C++ is the only implementation-ready disposition for this target.

## Final Recommendation
- Exact changes applied or recommended: report artifact updated after implementation; target metadata is now `88/90`, owner/emitter unchanged, blank formal C++ unchanged, evidence/no-code proof added.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:00001L`; keep file/source support through [UID:0000I3].
- Exact items left no-owner/non-emitting and why: no new no-owner items. Padding remains ignored/non-source; UID00019U remains mixed non-emitting context.
- Exact future work, if any, outside this assignment scope: later method-specific child splits or class-declaration source work may enable formal C++; not required for this report-only pass.

## Recommended Target Doc Changes
- Target path: `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`.
- Exact report facts to incorporate:
  - Current MCP session `supervisor_recovery_20260705`, health OK, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays/string cache ready.
  - Exact five-function inventory and sizes: constructor `0x720`, action `0x2e`, validation `0x96`, dispatcher `0x26`, submit `0x222`.
  - No functions at internal/terminal padding boundaries and no function at `0x004fe790`.
  - Constructor callers `0x004f7b49` and `0x004f90a0`; singleton refs; vtable refs; `DLGPASS.PAL`/`DLGPASS.EPF`/`DLGPASS.EPD` resource evidence.
  - Action/validation/dispatcher/submit behavior at report detail, especially active submit call `0x004fe778 -> 0x004fe9e0` and dispatcher call `0x004fe551 -> 0x004febf0`.
  - Boundary bytes including `0x004fe782-0x004fe790` fourteen `0xcc` bytes before UID0002QB.
  - Old reports are leads only; no direct UID0002QA report existed.
- Metadata/score/owner/emitter/reconstructable/C++ changes: set `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00001L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001L`, blank optional position, blank formal C++.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve no-code proof; update old packet-child blockers as superseded; keep rejected PacketBuffer/Socket/global/main-menu/no-owner routes; keep singleton byte conflict session-qualified if mentioned.

## Recommended Support Doc Changes
- Support path: `by-class/ChangePasswordDialogPane.md`.
  - Exact report facts to incorporate: update UID0002QA method row/details to `88/90`; mention current B013 direct MCP recheck; state packet sender/reply children are no longer UID0002QA blockers; preserve aggregate blank C++ due constructor/class/member/resource blockers.
  - Metadata/link/score/coverage/source-placement changes: no owner/source-path change.
- Support path: `by-file/ChangePasswordDialogPane.md`.
  - Exact report facts to incorporate: keep UID0002QA in `NexusTK/login/ChangePasswordDialogPane.cpp`; note current recheck and blank aggregate C++; child helpers UID0002QB/QC/QD/QE remain source-ready in the same file family.
  - Metadata/link/score/coverage/source-placement changes: no file owner change.
- Support path: `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`.
  - Exact report facts to incorporate: update UID0002QA child row from `86/89` to `88/90`; preserve that UID00019U is a non-emitting mixed-owner context; preserve exact predecessor boundary and adjacent packet-helper relationship.
  - Metadata/link/score/coverage/source-placement changes: no parent metadata change.
- Support path: `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`.
  - Exact report facts to incorporate: no required edit unless a stale statement says UID0002QA's packet sender/reply children are unresolved. If edited, mention direct B013 recheck confirmed the core ends at `0x004fe782`, fourteen `0xcc` bytes precede UID0002QB, and UID0002QC remains the active sender.
  - Metadata/link/score/coverage/source-placement changes: none required.
- Support path: `by-global/OpenChangePasswordDialog_4F9060.md` and UID0002XM singleton docs.
  - Exact report facts to incorporate: no required edit found. Existing launcher/singleton docs already preserve relevant caller/singleton evidence and byte-conflict caveat.
  - Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation
- Current score/metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00001L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001L`, blank optional position, blank formal C++.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter/reconstructable unchanged, blank optional position, blank formal C++.
- Score rationale and reason not higher/lower:
  - Completion rises because this report adds direct current MCP evidence for session health, exact function inventory, xrefs, boundary bytes, vtables, singleton refs, resources, child helper status, old-report search results, and no-code proof.
  - Confidence rises because the owner/range/submit/dispatcher/child relationships are current-session facts, not only historical docs.
  - Scores do not rise higher because formal C++ remains blank and unresolved source names/member layout/resource/message declarations still materially block source reconstruction.
- Score-improvement attempt:
  - Constructor layout checked through MCP decompilation/signature/strings/xrefs; result: behavior strong, source-level class/control names unresolved.
  - Control IDs checked through submit/validation decompilation; result: roles strong for controls `3/4/5/6`, exact member/control types unresolved.
  - Singleton/vtable/resource state checked through xrefs/bytes/get_string; result: ownership strong, original declaration/source names still inferred.
  - Submit route checked through xrefs/body/bytes; result: UID0002QC active route exact, UID0002QB rejected as active route.
  - Reply dispatcher route checked through body/xrefs; result: packet type `2` to UID0002QD exact, UID0002QE retained no-route remains child cap only.
  - Split concerns checked through entity query and bytes; result: exact candidate subranges known, no new split required for this pass.
- Metadata fields to change or leave unchanged: change only completion/confidence; leave owner, reconstructable, emitter, optional position, and formal C++ state unchanged.

## Open Questions With Attempted Resolution
- Open question: can UID0002QA receive a safe first-draft class-level constructor/helper block now that packet children are source-ready?
  - Evidence checked: current MCP five-function decompile summaries, current child helper reports/docs, class/file docs, generated output.
  - Best resolution: no. Packet children are resolved, but aggregate C++ still requires unresolved class layout/control/resource/helper declarations.
- Open question: should UID0002QA be split into five exact child method pages now?
  - Evidence checked: `entity_query`, `lookup_funcs`, bytes, parent/sibling docs.
  - Best resolution: not for this assignment. Exact subranges are known and can support future work, but target-level source-quality can improve with evidence/no-code proof without topology changes.
- Open question: does UID0002QB become active submit route after child updates?
  - Evidence checked: current submit decompilation, `xrefs_to 0x004fe9e0`, old UID0002QB reports.
  - Best resolution: no. Submit calls UID0002QC at `0x004fe778` with controls `3/4/5`; UID0002QB remains retained no-route sibling.
- Open question: do current singleton bytes require support edit?
  - Evidence checked: current `get_bytes 0x0069b48c`, `xrefs_to`, B003 singleton report.
  - Best resolution: no report-only support edit required. Keep byte-value evidence session-qualified; constructor publish/fallback and refs are the relevant UID0002QA facts.
- Questions remaining unresolved: exact original constructor/control helper names, class member layout, message resource labels for submit failure alerts, exact method signatures, and original source grouping. These keep formal C++ blank and cap score at `88/90`; future evidence would need source-level declarations, stronger type recovery, or exact child-method reconstruction work.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. No explicit manual `-coverage-report.md` or supervisor-owned tracker row change is requested.
- File/placement: none.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated `auto-generated/-ag-*` reports are validator-owned, and manual coverage/tracker edits are supervisor-owned.

## Follow-Up Actions
- Supervisor-owned lifecycle actions are outside B013 scope; validator/lifecycle records determine report state after supervisor review or execution.
- A-agent actions: none requested.
- B013 future research actions: none for this UID unless supervisor returns a specific repair request.

## Confidence
- Recommendation confidence: high that target should remain `88/90`, owner/emitter `00001L`, and blank C++.
- Score confidence: medium-high. `88/90` reflects strong current evidence with a real formal-C++ blocker.
- Remaining uncertainty: exact source names, class/member layout, UI helper APIs, resource/message symbols, source grouping, and whether later exact child splits should carry method-level code.

## Validator Results
- Scoped B013 validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md --apply --queue-timeout 240`; start `2026-07-06T01:15:05.2059045-04:00`; `command_id: 000000007517`; `command_timestamp: 2026-07-06T01:15:05-04:00`; exit `0`; `ok: 1`; `completion_update: 1`; `confidence_update: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class/ChangePasswordDialogPane.md --apply --queue-timeout 240`; start `2026-07-06T01:15:16.9189032-04:00`; `command_id: 000000007519`; `command_timestamp: 2026-07-06T01:15:17-04:00`; exit `0`; `ok: 1`; `stats_row_update: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file/ChangePasswordDialogPane.md --apply --queue-timeout 240`; start `2026-07-06T01:15:27.7629032-04:00`; `command_id: 000000007521`; `command_timestamp: 2026-07-06T01:15:27-04:00`; exit `0`; `ok: 1`; `stats_row_update: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md --apply --queue-timeout 240`; start `2026-07-06T01:15:37.6929066-04:00`; `command_id: 000000007523`; `command_timestamp: 2026-07-06T01:15:37-04:00`; exit `0`; `ok: 1`; `stats_row_update: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md --apply --queue-timeout 240 --wait-generated`; start `2026-07-06T01:15:47.6209043-04:00`; `command_id: 000000007524`; `command_timestamp: 2026-07-06T01:15:47-04:00`; exit `0`; `ok: 1`; `generated_refresh: completed`.
- Generated refresh state: completed by validator command `000000007524`. `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp` was validator-refreshed at `2026-07-06T01:15:57.3679040-04:00`, length `8114`, and contains `// UID:0002QA ... Completion:88 | Confidence:90 | Empty Emitter Marker`.
- Validator warnings/errors: no blocking errors. Command `000000007524` reported broad validator-owned autogen notices (`autogen_children_marker_missing`, `autogen_emitter_has_no_code`, fallback child marker notices, and generated metadata refresh rows) while completing generated refresh; these are existing/generated-output notices, not UID0002QA blockers.

## Changed Files
- Report artifact updated: `tools/leaser/Agents/Agent-B013/research/0002QA-ChangePasswordDialogPaneCore-source-quality.md`.
- Manual by-* edits applied under B013 leases:
  - `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`
  - `by-class/ChangePasswordDialogPane.md`
  - `by-file/ChangePasswordDialogPane.md`
  - `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`
- By-* support docs intentionally not edited: `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`, `by-global/OpenChangePasswordDialog_4F9060.md`, UID0002XM singleton docs, Socket, PacketBuffer, `g_packetSender`, DialogPane, AlertPane, ResourceLayout, and other dependency docs because no contradiction was found or same-or-better detail was already present.
- Validator-owned generated refresh: `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp` now shows UID0002QA `Completion:88 | Confidence:90 | Empty Emitter Marker`; validator also refreshed generated metadata/coverage reports and projected stats under command `000000007524`. No generated, coverage, validator-state, lifecycle/archive, supervisor-ledger, or `-coverage-report.md` file was manually edited by B013.
- Leases: B013 leased the four edited by-* files immediately before editing and released all four after validation with `python .\leaser.py B013 unlease`; release output returned `Success` for all four paths and post-release checks found no matching current leases.
- Report execution: not run. B agents must not run `execute_report`, execute dry-run/probing variants, registry lifecycle commands, manual report moves, or archive moves.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update: target UID0002QA; narrow class/file/mixed-aggregate support; packet aggregate only if stale contradiction remains.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: target `86/89 -> 88/90`, owner/emitter/reconstructable unchanged, blank formal C++ unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or exact evidence-backed no-improvement proof after current routes were exhausted.
- [x] Owner/emitter/reconstructable changes to apply: none.
- [x] Split/rename/new-child changes to apply: none; candidate exact child subranges documented for future work only.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable.
- [x] First-draft C++ or no-code proof to apply: no-code proof; keep target formal C++ blank.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank.
- [x] Exact target/support doc facts to incorporate at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable.
- [x] Open questions to close or document as evidence-backed unresolved.
- [x] Validators to run: none in report-only; after callback, run scoped validators only for edited by-* files.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator-owned refresh only after implementation; no manual coverage text.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; no manual supervisor-owned coverage/tracker text was supplied or edited.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000007526","destination_path":"executed-b-agent-research/B013/0002QA-ChangePasswordDialogPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0002QA-ChangePasswordDialogPaneCore-source-quality.md","timestamp":"2026-07-06T01:27:48-04:00","uid":"0002QA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
