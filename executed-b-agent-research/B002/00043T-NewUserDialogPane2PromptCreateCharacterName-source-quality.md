** TARGET-REPORT-UID:00043T **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 00043T NewUserDialogPane2 Nexonclub Registration Gate Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation and implemented disposition: retain [UID:00043T] as the source-authored `NewUserDialogPane2::OpenNexonclubRegistrationOrSendCharacterRequest` method at `by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md`. The direct body is a boolean-gated Nexonclub registration launcher with a character-request fallback; it does not construct a character-name prompt.
- UID00043T is now `93/94` with `CANONICAL_OWNER:00009E`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00009E` retained, the exact formal C++ installed, and the exact `0x0052b650-0x0052b724` range preserved. Callback support [UID:00043U] is now `NewUserDialogPane2::OnNexonclubRegistrationResult` at `92/94`, and the `+0x27c` field is consistently documented as the best source-facing `m_nexonclubAccountName`.
- Callback implementation is complete for UID00043T, UID00043U, UID0002QR, UID00009E, UID0000LW, UID0000IK, UID00043K, UID000443, and UID0001RP at report-level detail. UID0001WQ/UID00005N/UID0001CS were reread and already preserve the accepted shared FunctionObjects ownership and exact concrete binding evidence, so no edits were needed. The exact manual coverage rows remain supervisor-owned and are supplied against the current roots below.
- Confidence: very strong. Live IDA proves the exact body, boolean branch, callback object layout, decorated callback vtable, callback target, registration-dialog allocation, localized string id, fallback call, and symmetric sibling implementations. The decoded `STR.RES` payload proves id `227` is the Nexonclub ID/password prompt. Only original lexical spellings and the retained helper's historical callsite remain unavailable.

## Supporting Research

- This report began as a report-only artifact. Supervisor Gate 1 accepted exact SHA256 `A3ED92DF94A1236C0F378C716919F13A2D0E4377FBD6005E7917DC28C2DBE094`, after which B002 performed the authorized implementation callback recorded below.
- Live IDA MCP was healthy throughout the pass. MCP transport session `298bedbb-0e21-4baf-ab2c-8bd7a2fbafba` reported `status: ok`; IDB/database session `9b0396a3` was open on `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, image base `0x00400000`, with auto-analysis, Hex-Rays, and strings ready. Final read-only `server_health` request `909` reconfirmed that state after report creation, with uptime `278053.499` seconds and string cache size `2067`.
- Direct target analysis was returned by MCP batch result `906`; symmetric sibling analysis was returned by batch result `907`. No IDA database changes were made.
- The executed B004 family report `executed-b-agent-research/B004/0002QR-NewUserDialogPane2CreateUserVariant-source-quality.md` was used only as a historical lead. Its `PromptCreateCharacterName`, `ApplyCreateCharacterName`, and `m_createdUserName` interpretation is contradicted by current direct binary/resource evidence and must be preserved only as superseded history.
- The executed B008 report `executed-b-agent-research/B008/0002QT-CreateUserDialogPaneCore-source-quality.md` was used as a sibling lead. Its Nexonclub interpretation at `0x0052e970/0x0052ea50` was independently rederived for UID00043T rather than copied.
- Report execution was not run or probed. This report remains at the assigned active research path for independent supervisor Gate 2 and supervisor-only execution.

## Target

- Target UID: `00043T`.
- Additional target UIDs, or `none`: `none`. UID00043U and the other UIDs below are bounded support destinations, not additional declared report targets.
- Declared-target inventory with path and role for every UID: [UID:00043T] `by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md`, a reconstructable class-method child under UID0002QR and emitter UID00009E.
- Target path: `by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md`.
- Source queue/report row: current `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`; assignment recorded the `87/89`, combined `88.0` row with no direct report.
- Historical supervisor classification was report-only source closure for a reconstructable by-memory child with stale semantics, stale names, and materially incorrect formal C++. Current classification is accepted callback implementation complete, awaiting independent supervisor Gate 2/manual-coverage handling and supervisor-only execution.
- Historical assignment scores were target `87/89` and split/index UID0002QR `89/90`. Current implemented state is target `93/94`; owner/emitter class UID00009E `92/94`; split/index UID0002QR `90/92`, non-reconstructable and non-emitting; file root UID0000LW `92/94`.

## Current Target State

- Current metadata: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:00009E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009E`, blank optional position.
- Current owner/emitter/reconstructable state: the route is unchanged and correct. The target is a source-authored member of [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md), emitted through that class to [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md).
- Current C++/emitter state: the formal block now defines `void NewUserDialogPane2::OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)` with the exact false-send and true-registration branches. The callback formal now defines `OnNexonclubRegistrationResult(const SimpleUString &accountName)`. The generated source contains both corrected definitions and no stale `PromptCreateCharacterName`, `ApplyCreateCharacterName`, `m_createdUserName`, or invented prompt helpers.
- Historical pre-callback blockers: the target page called this a character-name prompt; UID00043U called its payload a character name; UID00009E and UID0000LW repeated that interpretation; UID00043K cleared `m_createdUserName`; UID000443 serialized it. Those claims are now preserved only as superseded history. Current docs identify a Nexonclub registration prompt, a callback carrying successful registration account text, and a field serialized into the create-character request.
- Related target/support docs checked: UID00043U callback, UID0002QR split/index, UID00009E class, UID0000LW source file, UID0000IK family map, UID00043K constructor, UID000443 character-request builder, UID0001RP resource map, UID00040P LanguageMan lookup, UID0000RC/UID0001OS language singleton pages, UID0001WQ FunctionObjects template, UID00005N callback base class, UID0001CS const-string callback destructors, UID00046O/UID00046P symmetric CreateUserDialogPane pair, NexonclubRegistrationDialog class/file docs, current generated `NewUserDialogPane2.cpp`, current manual coverage roots, and matching executed B reports.
- Current artifact/lifecycle status: the accepted implementation callback is complete. B002 used and released short leases for each ordinary edit and ran the nine scoped validators recorded below. No manual coverage, generated, tracker, audit, supervisor, validator-state, IDA, archive, or lifecycle file was edited by B002; no report lifecycle command was run. Independent supervisor Gate 2 and supervisor-only report execution remain.

## Executive Recommendation

- The best direct owner remains UID00009E. The method uses the `NewUserDialogPane2` receiver, binds a callback member of the same class, and falls back to that class's `SendCreateCharacterRequest`.
- Rename UID00043T to `NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest` and UID00043U to `NewUserDialogPane2OnNexonclubRegistrationResult`. Rename the class methods and the `+0x27c` field consistently.
- Keep the exact target boundary and emitter route. No split, merge, new owner, or no-code treatment is justified.
- Replace the target and callback formal blocks. The target should use a `bool openRegistration` gate, `g_pLanguageMan->GetLocalizedString(227)`, a heap `PlainMemberFunctionObjectT` bound to `OnNexonclubRegistrationResult`, and `NexonclubRegistrationDialog`. The false branch should directly call `SendCreateCharacterRequest`.
- No assignment remains blocked. Original spelling uncertainty is handled through best-supported human source-facing inference, not raw IDA names.

## Supervisor Active Recheck

- The initial supervisor instruction assigned UID00043T for a complete report-only Rule 26 source closure and explicitly required exact prompt, callback, lifetime, `SimpleUString`, method-pointer, resource, error/return, ownership, score, and C++ investigation. The superseding accepted callback required implementation of all C43T-001 through C43T-040 obligations.
- The target does not require split repair. Live IDA confirms one exact modeled function occupying `0x0052b650-0x0052b724`, followed by 12 bytes of `0xCC` padding and the separate modeled callback at `0x0052b730`.
- Every source-bearing item needed to explain the target is resolved: target method, callback support, callback wrapper type, registration dialog constructor, localized resource, class field, and packet consumer. Compiler-generated callback vtable/destructor/invoke support remains represented by the shared FunctionObjects declarations and existing no-code compiler pages.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest semantic owner, exact by-memory range, formal C++ only in managed blocks, and source-facing code rather than decompiler output. Those rules preserve UID00009E ownership and reject both aggregate emission and raw `sub_`/`dword_` names.
- The existing character-name interpretation was treated as uncertain because it originated in an older broad split report without the current direct resource/callback reconstruction.
- IDA fact: one explicit argument is tested only for zero/nonzero; the true branch constructs a concrete callback and `NexonclubRegistrationDialog`; the false branch calls `sub_52BDD0`; the callback conditionally stores its string and always calls `sub_52BDD0`.
- Documentation evidence: UID00046O/UID00046P already describe the structurally identical sibling as a Nexonclub registration gate and callback; NexonclubRegistrationDialog docs prove callback ownership/invocation and successful account-text delivery.
- Inference: `openRegistration`, `OnNexonclubRegistrationResult`, and `m_nexonclubAccountName` are the most plausible human source-facing spellings. They are descriptive inferences, not claimed original symbols.
- Stale Wave2/Wave3 text was encountered in class/file history and ignored. It was not used as evidence.

## Heuristic / Inference Reanalysis And Validation

- **Target role:** resolved. The old "character-name prompt" label is impossible to reconcile with the exact call to `NexonclubRegistrationDialog`, the shared sibling implementations, and resource id `227`.
- **Argument type:** resolved as `bool`. The explicit four-byte argument is only tested by `if (!argument)` and is never dereferenced, stored, or forwarded. An opaque pointer formal would expose decompiler uncertainty rather than source semantics.
- **Return type:** best-supported as `void`. Both branches perform side effects, the sibling accepted source shape is `void`, and the differing residual EAX values are normal compiler residue in a void helper. There is no caller that consumes a return value.
- **Prompt acquisition:** resolved. The true branch calls `LanguageMan::GetLocalizedString(227)` through `g_pLanguageMan`; it does not allocate or populate a local `SimpleUString`.
- **Resource meaning:** resolved. Direct parsing of `baram.dat` entry index `9`, payload offset `11,268,984`, size `7,058`, maps zero-based string id `227` to `Please input nexon.com ID and password.` Nearby ids `224-229` are the associated Nexonclub registration question, yes/no, no-ID, and password-error strings.
- **Callback type and object layout:** resolved. The allocated wrapper is 24 bytes, installs decorated vtable `0x0061ff70`, stores the member target at `+0x08`, zero this-adjust at `+0x0c`, and bound object at `+0x10`. The source type is a `PlainMemberFunctionObjectT` derived from `FunctionObjectT<const SimpleUString &>`.
- **Callback ownership/lifetime:** resolved to transfer into the newly constructed `NexonclubRegistrationDialog`. The dialog stores the result callback at `+0x26c`, later invokes it on successful NCA state `0`, and its lifecycle releases callback/status state. The opener must not delete the wrapper locally.
- **Callback payload:** resolved as Nexonclub account text. `NexonclubRegistrationDialog` helper `0x005304c0` reads the account control, and success state `0` invokes the supplied callback with that text. It is not the final character name.
- **Field at `NewUserDialogPane2+0x27c`:** resolved direction as the Nexonclub account name carried into opcode `0x04`. The callback writes it only when nonempty, and UID000443 serializes the same field as a length-prefixed MBCS string. `m_nexonclubAccountName` is preferred over stale `m_createdUserName` and vague sibling `m_createUserExtraText`.
- **Error and cancel behavior:** resolved for this target. A false gate bypasses registration and sends immediately. Registration failures remain inside `NexonclubRegistrationDialog`; only success state `0` produces account text. An empty callback string preserves the existing field but still sends the character request, matching the exact callback body.
- **Reachability:** exhaustively checked. There are no incoming code/data xrefs to `0x0052b650`, no endpoint refs, and no target VA/RVA/raw-offset pointer encodings. This proves retained/no-current-route status, not dead or compiler-generated status, because two independently modeled siblings preserve the exact source pattern and the body constructs source-level objects.
- **Range:** resolved. Exact modeled target is 212 bytes; `0x0052b724-0x0052b730` is 12-byte `0xCC` alignment; UID00043U starts at `0x0052b730`.
- **Owner/emitter/source placement:** resolved. The receiver, bound callback, fallback, field, and packet path remain `NewUserDialogPane2.cpp` class source. `NexonclubRegistrationDialog.cpp` owns dialog implementation, while FunctionObjects owns reusable callback templates.
- **Generated output pollution:** resolved as stale downstream output. Current generated C++ still reproduces the wrong character-name method, field, and invented helpers because its source docs are stale; generated output is not authority.
- **Final-C++ blocker:** resolved. Exact behavior, type direction, ownership, and source placement support formal first-draft C++. Original lexical spellings are inferred to plausible project style rather than left as IDA labels.
- **Rejected alternatives:** `PromptCreateCharacterName`, `ApplyCreateCharacterName`, `m_createdUserName`, local `SimpleUString initialName`, invented prompt helpers, `void *context`, hard-coded English prompt text, local callback deletion, moving the target to NexonclubRegistrationDialog, moving template code into this target, aggregate UID0002QR emission, and no-code treatment are all rejected by the evidence above.
- **Remaining uncertainty:** only exact original identifier spelling, possible original named enum/constant for id `227`, and why all three duplicate helpers were retained without current xrefs. These do not block source-quality code or the proposed score.

## Evidence Standards Used

- Primary evidence: live IDA MCP function lookup, decompilation, call inventories, xrefs, decorated vtable/type names, vtable slot reads, raw bytes, boundary/padding checks, and pointer-pattern searches.
- Corroborating evidence: exact symmetric helper/callback pairs at `0x0052d100/0x0052d1e0` and `0x0052e970/0x0052ea50`, the four-caller registration-dialog constructor cluster, current FunctionObjects documentation, current NexonclubRegistrationDialog docs, and direct resource extraction.
- Documentation and generated C++ were treated as leads. Claims that conflict with binary/resource evidence are historicalized instead of used to raise confidence.
- The evidence ladder reaches direct binary and direct resource proof for behavior. Confidence remains below 95 because stripped original names, exact typedef spelling, and retained-helper source callsites are not recoverable from current artifacts.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: health/readiness; `lookup_funcs`, `analyze_batch`, decompilation, caller/callee inventories, `xrefs_to`, `xref_query`, `find_bytes`, vtable integer reads, target/callback/sibling byte hashing, and exact boundary/padding checks for `0x0052b650`, `0x0052b730`, `0x0052d100`, `0x0052d1e0`, `0x0052e970`, `0x0052ea50`, and `0x0052f950`.
- Resource check performed: direct read-only parsing of `E:\NTK\Resources\NexusTK\Data\baram.dat`, table entry `9`, `STR.RES` payload offset `11,268,984`, size `7,058`, and zero-based ids surrounding `227`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target UID00043T; callback UID00043U; parent UID0002QR; class UID00009E; file UID0000LW; family UID0000IK; constructor UID00043K; packet builder UID000443; resource UID0001RP; LanguageMan UID00040P/UID0000RC/UID0001OS; FunctionObjects UID0001WQ/UID00005N/UID0001CS; sibling UID00046O/UID00046P; NexonclubRegistrationDialog class/file; current generated `NewUserDialogPane2.cpp`; current manual by-memory/by-class/by-file/by-resource coverage roots; executed B004 UID0002QR and B008 UID0002QT reports.
- Old-report search terms: `00043T`, `0x0052b650`, `PromptCreateCharacterName`, `ApplyCreateCharacterName`, `NexonclubRegistration`, and `m_createdUserName`.
- Negative checks performed: no incoming target xrefs, no endpoint refs, no little-endian target VA `50 B6 52 00`, RVA `50 B6 12 00`, or raw-offset `50 AA 12 00` pointer hits; callback pointer `30 B7 52 00` appears only in the target binding instruction; vtable pointer `70 FF 61 00` appears only in the target vtable store.
- Failed, unavailable, or intentionally skipped checks and why: post-write health request `908` intentionally lacked the now-required `database` argument and returned the MCP `database is required` error; the corrected request `909` on database session `9b0396a3` immediately returned healthy, so this was not an MCP outage. No research check failed. Validators were intentionally not run during the initial report-only phase; nine authorized scoped callback validators were later run and are recorded below. No IDA database edits were attempted; exact original PDB/source symbols are unavailable in the current IDB.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C43T-001 | 00043T | Exact modeled range is `0x0052b650-0x0052b724`, 212 bytes, SHA256 `46089EEA71E6B8B3912883A886152516631910E997182FF94408F0DB057BD247`. | exact | MCP lookup/raw bytes/hash | UID00043T status/evidence | incorporate | applied |
| C43T-002 | 00043T | `0x0052b724-0x0052b730` is 12 bytes of `0xCC`, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C973309`; callback starts at `0x0052b730`. | exact | MCP raw bytes/function boundary | UID00043T range/padding; UID0002QR inventory | incorporate | applied |
| C43T-003 | 00043T | The explicit argument is a boolean gate: only a zero test is performed. | very strong | direct decompile and use inventory | UID00043T behavior/formal | incorporate | applied |
| C43T-004 | 00043T | False gate calls `NewUserDialogPane2::SendCreateCharacterRequest` at `0x0052b70c` and returns. | exact | direct decompile/callee target | UID00043T behavior/formal | incorporate | applied |
| C43T-005 | 00043T | True gate allocates a 24-byte callback wrapper and initializes its base/template state. | exact | calls to `0x004f4aa0` and `0x004f4a80` | UID00043T behavior/callback lifetime | incorporate | applied |
| C43T-006 | 00043T | Callback wrapper uses decorated vtable `0x0061ff70`, member target `0x0052b730`, this-adjust `0`, and bound `this`. | exact | MCP stores/vtable name | UID00043T callback layout/type | incorporate | applied |
| C43T-007 | 00043T | Wrapper source type is `PlainMemberFunctionObjectT` over `FunctionObjectT<const SimpleUString &>`. | very strong | decorated type plus UID0001WQ/UID00005N | UID00043T formal/type notes | incorporate | applied |
| C43T-008 | 00043T | True gate allocates 632 bytes and calls constructor `0x0052f950`, identifying `NexonclubRegistrationDialog`. | exact | direct call/allocation plus class docs | UID00043T behavior/formal | incorporate | applied |
| C43T-009 | 00043T | Prompt comes from `g_pLanguageMan->GetLocalizedString(227)`. | exact | direct call `0x004f0350`, singleton, immediate 227 | UID00043T behavior/formal; UID0001RP | incorporate | applied |
| C43T-010 | 00043T | STR.RES id 227 is `Please input nexon.com ID and password.` in current `baram.dat`. | exact-current-resource | direct DAT payload extraction | UID0001RP id map; UID00043T resource evidence | incorporate | applied |
| C43T-011 | 00043T | The target has no local `SimpleUString` prompt temporary and does not call the two invented prompt helpers in current formal C++. | exact | complete decompile/callee inventory | UID00043T stale-history/formal replacement | reject-stale | applied |
| C43T-012 | 00043T | Target should be renamed `OpenNexonclubRegistrationOrSendCharacterRequest`. | very strong inference | exact role plus symmetric accepted sibling | UID00043T path/title/item/formal; support links | incorporate | applied |
| C43T-013 | 00043T | Callback UID00043U is exact `0x0052b730-0x0052b75c`, 44 bytes, SHA256 `3019CB1E0DBAB342A544722DE3FD62F6A4E22042A029E15B097D9AF33895A1CE`. | exact | MCP lookup/raw bytes/hash | UID00043U evidence | incorporate | applied |
| C43T-014 | 00043T | Callback checks `SimpleUString::empty`, conditionally assigns `this+0x27c`, and always sends the character request. | exact | callback decompile/callees | UID00043U behavior/formal | incorporate | applied |
| C43T-015 | 00043T | Callback payload is successful Nexonclub account text, not a character name. | very strong | registration state-0 callback and account-control helper | UID00043U; UID00009E; UID0000LW | incorporate | applied |
| C43T-016 | 00043T | Callback should be renamed `OnNexonclubRegistrationResult`. | very strong inference | exact payload/role plus sibling naming | UID00043U path/title/formal; class declarations | incorporate | applied |
| C43T-017 | 00043T | Field `+0x27c` should be named `m_nexonclubAccountName`. | strong inference | callback producer and UID000443 packet consumer | UID00009E/UID00043K/UID00043U/UID000443 | incorporate | applied |
| C43T-018 | 00043T | `m_createdUserName` is stale because registration account text is the actual producer. | very strong | producer/consumer route and resource text | affected docs historical sections | reject-stale | applied |
| C43T-019 | 00043T | Registration dialog stores/owns the transferred callback and later releases/invokes it; opener performs no local delete. | very strong | constructor field `+0x26c`, class lifecycle docs | UID00043T lifetime notes/formal | incorporate | applied |
| C43T-020 | 00043T | Registration failure/cancel handling belongs to `NexonclubRegistrationDialog`; this target only launches or bypasses. | very strong | registration response state docs and target call graph | UID00043T scope notes | incorporate | applied |
| C43T-021 | 00043T | Empty callback text leaves the current account field unchanged but still sends. | exact | callback control flow | UID00043U behavior/formal | incorporate | applied |
| C43T-022 | 00043T | Symmetric `NewCreateUserDialogPane` helper/callback at `0x0052d100/0x0052d1e0` has the same source shape. | exact-structural | MCP batch 907 | UID00043T sibling evidence | incorporate | applied |
| C43T-023 | 00043T | Symmetric `CreateUserDialogPane` UID00046O/UID00046P at `0x0052e970/0x0052ea50` has the same source shape. | exact-structural | MCP batch 907/current docs | UID00043T sibling evidence | incorporate | applied |
| C43T-024 | 00043T | `NexonclubRegistrationDialog` constructor has exactly four callers: target, two create-user siblings, and NexonclubProxyDialog. | exact | MCP caller inventory | UID00043T ownership/role evidence | incorporate | applied |
| C43T-025 | 00043T | No incoming target xrefs or target VA/RVA/raw-offset pointer encodings were found. | exact-negative | xrefs and `find_bytes` | UID00043T negative evidence/score rationale | incorporate | applied |
| C43T-026 | 00043T | No incoming route does not justify no-code: duplicate source-authored implementations and object construction prove retained source behavior. | very strong | negative evidence plus siblings | UID00043T disposition | incorporate | applied |
| C43T-027 | 00043T | Owner/emitter remain UID00009E; source root remains UID0000LW. | very strong | receiver, callback, field, fallback, source cluster | UID00043T metadata/source placement | already-present | already-present |
| C43T-028 | 00043T | UID0002QR remains non-reconstructable/non-emitting but its inventory and summary must replace the stale name-prompt interpretation. | very strong | exact split policy/current child table | UID0002QR child inventory/history/score | incorporate | applied |
| C43T-029 | 00043T | UID00009E declarations and method table must use the registration names and account field. | very strong | target/callback/packet route | UID00009E formal/method/evidence/history | incorporate | applied |
| C43T-030 | 00043T | UID00043K must clear `m_nexonclubAccountName`; UID000443 must serialize it. | very strong | same `+0x27c` constructor/callback/consumer | UID00043K and UID000443 formal/prose/history | incorporate | applied |
| C43T-031 | 00043T | UID0000LW and UID0000IK should describe the replicated Nexonclub registration gate/callback family instead of a name prompt. | very strong | exact source-family relationship | UID0000LW/UID0000IK contents/history | incorporate | applied |
| C43T-032 | 00043T | UID0001RP should add exact id 227 resource mapping and caller while preserving runtime lookup. | exact-current-resource | direct payload and target immediate | UID0001RP confirmed ids/score/history | incorporate | applied |
| C43T-033 | 00043T | UID0001WQ/UID00005N/UID0001CS already own reusable callback template/generated destructor evidence; target owns only binding/construction. | very strong | decorated vtable and current FunctionObjects docs | target cross-reference; support verify-only | already-present | already-present |
| C43T-034 | 00043T | Historical generated `NewUserDialogPane2.cpp` command 16594 was stale for these names/formals/field; final B002 readback at command 16678 contains the corrected output. | exact-current-artifact | generated readback/hash | report generated state | historicalize | applied |
| C43T-035 | 00043T | B004's prior character-name inference is superseded but should remain documented as historical rejected analysis. | very strong | old report compared with direct proof | target/support history sections | historicalize | applied |
| C43T-036 | 00043T | Target does not need split, merge, reclassification, or range change. | exact | modeled boundary and padding | UID00043T status; UID0002QR inventory | already-present | already-present |
| C43T-037 | 00043T | Target score should become `93/94`; callback support should become `92/94`; parent/resource support scores should move only as specified. | strong | blocker resolution and score rules | target/support metadata and manual rows | incorporate | applied |
| C43T-038 | 00043T | Exact manual by-memory/class/file/resource rows require supervisor-owned replacement/insertion. | exact-current-doc | current root readback/hashes | manual coverage roots | incorporate | applied |
| C43T-039 | 00043T | No IDA DB rename/type/comment edit is authorized or necessary in report-only scope. | exact-scope | assignment boundary | no IDA destination | not-applicable | excluded-with-reason |
| C43T-040 | 00043T | No third-party source import applies. | exact-scope | native project method/resource path | no import destination | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: exact true/false branch behavior; callback allocation and binding; decorated vtable; callback target; `NexonclubRegistrationDialog` allocation/constructor; language id `227`; false-branch character request; callback account-text store and unconditional send.
- Corroborating documentation/generated-report evidence: two binary-identical source-shape sibling pairs; accepted UID00046O/UID00046P role; FunctionObjects callback declarations; NexonclubRegistrationDialog callback ownership and state-0 account-text behavior.
- Strongest inference chain: resource id 227 names Nexon credentials, constructor `0x0052f950` is the registration dialog, callback success supplies account control text, callback stores `+0x27c`, and character request serializes `+0x27c`. Together those independent routes exclude the current character-name interpretation.

## IDA MCP Facts

- Function/range facts: `sub_52B650` is `0xd4` / 212 bytes at `0x0052b650-0x0052b724`; `sub_52B730` is `0x2c` / 44 bytes at `0x0052b730-0x0052b75c`.
- Data/table/padding facts: target trailing padding is `0x0052b724-0x0052b730`, all `0xCC`; callback object is 24 bytes; registration dialog allocation is `0x278` / 632 bytes.
- Xref facts: target has no incoming code/data xrefs. Callback has one data/member-pointer reference from the target binding store. `0x0052f950` has four direct callers at target, two sibling helpers, and NexonclubProxyDialog.
- Vtable/global/type facts: callback vtable `0x0061ff70` is decorated as a `PlainMemberFunctionObjectT` for `NewUserDialogPane2` and `const mystr::StringBase<wchar_t,...>&`; slots resolve to scalar deleting destructor `0x0052f7c0`, size helper `0x004f4b10`, `nullsub_18`, shared invoke `0x0049af00`, and object-size helper `0x004673f0`.
- Target callee facts: `0x0052f950`, `0x0052bdd0`, `0x004f4a80`, `0x004f0350`, and `0x004f4aa0`.
- Callback callee facts: `0x005845f0` empty check, `0x00582c60` string assignment, and `0x0052bdd0` character-request sender.
- Negative IDA facts: no target endpoint refs; no target VA/RVA/raw-offset pointer patterns; no local prompt-string object construction; no calls to the two helpers invented by current formal C++.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0052b650-0x0052b724` | UID00043T / current target | Boolean Nexonclub registration-or-send method | true | UID00009E | current `93/94` | renamed; exact formal installed and validated |
| `0x0052b724-0x0052b730` | no page | `0xCC` alignment | no source | UID0002QR range | n/a | preserve as padding |
| `0x0052b730-0x0052b75c` | UID00043U | Registration result callback | true | UID00009E | current `92/94` | renamed; exact formal installed and validated |
| `0x0052d100-0x0052d1d4` | sibling NewCreateUserDialogPane helper | same boolean gate | true | sibling class | supporting evidence | no edit required by this report unless stale references found |
| `0x0052d1e0-0x0052d20c` | sibling callback | same account-text callback | true | sibling class | supporting evidence | no edit required by this report unless stale references found |
| `0x0052e970-0x0052ea44` | UID00046O | accepted old-dialog registration gate | true | UID00003B | `87/89` | supporting evidence; verify-only |
| `0x0052ea50-0x0052ea7c` | UID00046P | accepted old-dialog callback | true | UID00003B | `88/90` | supporting evidence; verify-only |
| `0x0052f950-0x0052ff9b` | UID0001CT aggregate child | registration dialog constructor | true | NexonclubRegistrationDialog | support | stores callback and prompt |
| `0x0061ff70` callback vtable | UID00005N/UID0001CS support | compiler-generated concrete callback type | source-declared, not handwritten body | UID0001WQ template | support | already documented |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0052b650` | no incoming code/data xref | retained helper has no current direct route |
| target false branch `0x0052b70c` | calls `0x0052bdd0` | bypass registration and send character request |
| target true branch | calls `0x004f4aa0` / `0x004f4a80` | allocate and initialize callback wrapper |
| target store near `0x0052b6a7` | stores member target `0x0052b730` | binds registration-result callback |
| target call `0x0052b6ec` | calls `0x004f0350(g_pLanguageMan, 227)` | retrieves localized Nexonclub prompt |
| target call `0x0052b6f4` | calls `0x0052f950` | constructs Nexonclub registration dialog |
| `0x0052b730` | one data/member-pointer ref from target | callback is live through wrapper binding |
| callback | calls `0x005845f0` | tests account text empty state |
| callback | calls `0x00582c60` | assigns nonempty account text to `+0x27c` |
| callback | calls `0x0052bdd0` | always sends character request |
| `0x0052f950` | callers from `0x0052b650`, `0x0052d100`, `0x0052e970`, `0x00553610` | registration dialog is shared by three create-user variants and proxy path |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: UID00046O/UID00046P already use the registration-or-send/callback interpretation; FunctionObjects documents the concrete const-string callback family; NexonclubRegistrationDialog documents result callback ownership, account control readback, state-0 invocation, and states 1-5 failure handling.
- Historical docs that were stale, incomplete, or contradicted: UID00043T, UID00043U, UID0002QR, UID00009E, UID0000LW, UID00043K, and UID000443 used character-name terminology, while UID0001RP lacked id `227`. The callback implementation corrected those ordinary docs and preserved the disproven interpretation as explicit history. The manual coverage rows remain stale and supervisor-owned.
- Final B002 generated readback: `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` was command `000000016678`, timestamp `2026-07-22T23:46:38-04:00`, SHA256 `0226F9D1F9DA45A37E8B2A28F953D0E9610661AD0228A9B509ADD931C9987428`, `15,250` bytes / `528` lines. It contains one UID00043T definition and one UID00043U definition, the corrected class declarations, four `m_nexonclubAccountName` occurrences, one `GetLocalizedString(227)` call, and zero stale `PromptCreateCharacterName`, `ApplyCreateCharacterName`, or `m_createdUserName` occurrences. Two empty-emitter markers remain only for unrelated singleton-global UID0002X3/UID0002X4; neither target nor callback is empty. Historical command `000000016594` and SHA256 `D8B0DA35439039F4831379CA94BB6EDA51371C4B5E39CBEC0B0BE899C4C1F197` are superseded pre-callback evidence; commands 16668 and 16676 were intermediate corrected checkpoints superseded by later repository refreshes. Because other agents may continue running validators, the supervisor should use the generated header as authoritative if it advances again; the semantic parity checks above must remain true.

## Ranked Ownership Analysis

### 1. UID00009E NewUserDialogPane2

- Evidence for: method receiver is `NewUserDialogPane2`; callback member target is UID00043U on the same receiver; false path calls UID000443 on the same class; callback writes the class field; address lies inside UID0002QR's exact class island; existing owner/emitter route is already stable.
- Evidence against: no direct incoming target caller survives.
- Decision: retain direct owner/emitter UID00009E. Missing callsite does not outweigh exact class-local semantics and symmetric retained methods.

### 2. UID0000LW NewUserDialogPane2.cpp source root

- Evidence for: the target, callback, constructor field, and packet consumer all belong to this file; UID00009E emits through UID0000LW; sibling dialog implementations live in their own corresponding source roots.
- Evidence against: registration dialog implementation and reusable callback template are dependencies in other modules.
- Decision: retain UID0000LW as source root. Dependencies do not own the binding method.

### 3. NexonclubRegistrationDialog / FunctionObjects alternatives

- Evidence for: the target constructs `NexonclubRegistrationDialog` and instantiates a FunctionObjects template.
- Evidence against: the method is not a registration-dialog member, and its concrete callback is bound to `NewUserDialogPane2`; reusable template source already exists under UID0001WQ.
- Decision: reject both ownership moves. Keep dependency cross-references only.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; no new owner or source file is needed.
- Likely full contents: existing `NexusTK/login/NewUserDialogPane2.cpp` remains the correct source root.
- Candidate related items that belong: UID00043T, UID00043U, UID00043K, UID000443, and the rest of the established UID0002QR exact children.
- Candidate related items rejected: NexonclubRegistrationDialog implementation and shared callback template bodies remain in their existing owners.
- Standalone, narrow, or broad source-file inference: narrow class-method child within the established file.

## Source Placement

- Recommended source file/class/global/module placement: `NewUserDialogPane2::OpenNexonclubRegistrationOrSendCharacterRequest` and `NewUserDialogPane2::OnNexonclubRegistrationResult` in `NexusTK/login/NewUserDialogPane2.cpp`; declarations and `m_nexonclubAccountName` in the corresponding class declaration.
- Why this placement fits source-tree and subsystem context: all three create-user dialog variants retain parallel helpers in their own classes, while a shared `NexonclubRegistrationDialog` consumes the callback.
- Rejected placements and why: moving the helper into Nexonclub registration would reverse the provider/consumer relationship; moving it into FunctionObjects would confuse template implementation with feature binding; moving it to UID0002QR formal C++ would duplicate exact children.
- Remaining placement uncertainty, if any: none material. Header basename and include ordering remain broader source-tree details.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target `0x0052b650-0x0052b724`; 12-byte `0xCC` padding `0x0052b724-0x0052b730`; callback `0x0052b730-0x0052b75c`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child. Rename/repair existing UID00043T and UID00043U.
- Padding/table/data/code distinctions: trailing `0xCC` is alignment and must not be emitted; callback vtable at `0x0061ff70` is compiler-generated data from existing template/class source.
- Parent/container impact: UID0002QR child inventory, item summary, behavior sections, and stale-history section must use the corrected roles. `Nested:21` and non-emitting aggregate disposition remain unchanged.

## Negative Evidence Summary

- No incoming target xrefs were found by code/data xref queries.
- No target VA, RVA, or raw-offset pointer encodings were found.
- The only callback-address hit is the target's own member-pointer binding; the only callback-vtable pointer hit is the target's own vtable store.
- No local `SimpleUString` is constructed in the target.
- No prompt-copy helper or generic prompt-launch helper is called.
- The prompt is not a hard-coded string and is not character-name text.
- The target does not own registration errors, NCA request handling, or callback destruction; those are registration-dialog responsibilities.
- Consumer dependency on NexonclubRegistrationDialog does not transfer ownership away from NewUserDialogPane2.
- Nearby retained siblings corroborate source liveness; therefore no-xref evidence limits callsite confidence but does not justify no-code or non-reconstructable treatment.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: target `NewUserDialogPane2::OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)`; callback `NewUserDialogPane2::OnNexonclubRegistrationResult(const SimpleUString &accountName)`; field `SimpleUString m_nexonclubAccountName`; callback base `FunctionObjectT<const SimpleUString &>` with concrete `PlainMemberFunctionObjectT`.
- Evidence for each proposed name/type/comment: exact branch role, resource text, callback payload, field producer/consumer, decorated callback vtable, and accepted symmetric sibling names.
- Items intentionally left unchanged and why: `g_pLanguageMan`, `GetLocalizedString`, `NexonclubRegistrationDialog`, owner/emitter routing, callback-template owner, and exact ranges already have stronger established project names/structure.
- Whether IDA DB edits are safe, unsafe, or not requested: no IDA DB edits are requested or authorized. These are source-document names for supervisor-approved implementation.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is source-authored, reconstructable, emitting, and all behavior/type/source blockers in scope are resolved.
- Recommended target code:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::OpenNexonclubRegistrationOrSendCharacterRequest(
    bool openRegistration)
{
    if (!openRegistration) {
        SendCreateCharacterRequest();
        return;
    }

    FunctionObjectT<const SimpleUString &> *callback =
        new PlainMemberFunctionObjectT<
            void (NewUserDialogPane2::*)(const SimpleUString &),
            NewUserDialogPane2,
            const SimpleUString &>(
                this,
                &NewUserDialogPane2::OnNexonclubRegistrationResult);

    new NexonclubRegistrationDialog(
        g_pLanguageMan->GetLocalizedString(227),
        callback);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Recommended UID00043U support code:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::OnNexonclubRegistrationResult(
    const SimpleUString &accountName)
{
    if (!accountName.empty()) {
        m_nexonclubAccountName = accountName;
    }

    SendCreateCharacterRequest();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Third-party import directive, when applicable: not applicable; this is native NexusTK class source.
- Reason it preserves exact original behavior: branch side effects, allocation sizes through source types, callback member binding, localized id lookup, callback conditional assignment, and unconditional send match the decompiled control/data flow.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: it uses the project's callback templates and dialog classes directly, omits compiler vtable/member-pointer stores, avoids raw allocation helpers, and uses normal class/member names.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `openRegistration`, `callback`, `accountName`, `m_nexonclubAccountName`, `FunctionObjectT`, and `PlainMemberFunctionObjectT`.
- Naming/coding style convention used and evidence for consistency: class methods use PascalCase, members use `m_`, globals use `g_`, and project template/dialog names match current accepted docs. Exact behavior and human source shape take precedence over cosmetic consistency.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes applied: target/callback renames, exact formal replacements, field rename propagation, resource id mapping, parent/class/file/family prose correction, score updates, and history preservation are complete in the nine listed ordinary docs. Exact manual row replacement/insertion remains supervisor-owned.
- Exact disposition and implementation proof for each declared target UID: UID00043T remains reconstructable/emitting under UID00009E and is now `93/94`; direct MCP/resource proof and callback verification are recorded in C43T-001 through C43T-040.
- Exact parent assignments applied: UID00009E owner/emitter and UID0000LW source route were retained; UID0002QR remains the non-emitting split/index at `90/92`.
- Exact items left no-owner/non-emitting and why: no new no-owner item. Existing compiler-generated callback support remains non-handwritten under its current FunctionObjects policy.
- Exact future work, if any, outside this assignment scope: supervisor manual-coverage application, independent Gate 2, and supervisor-only execution remain. A later project-wide coordinated rename could normalize the same account field on the two sibling create-user classes and replace literal `227` with a proven string-id enum if such an enum is reconstructed; neither blocks this implementation.

## Recommended Target Doc Changes

- Target path applied: `by-memory/0x0052b650-0x0052b724.NewUserDialogPane2PromptCreateCharacterName.md` was renamed to `by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md`, preserving UID00043T.
- Exact report facts incorporated: exact range/size/hash/padding; no incoming route and pointer negatives; boolean-gate use; false fallback; callback allocation/layout/type/binding; language id and decoded resource text; registration dialog allocation/constructor/lifetime; symmetric siblings; stale character-name rejection; ownership/source placement; score rationale.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: `87/89 -> 93/94`; owner/emitter/reconstructable unchanged; exact target formal installed; title/item summary/cross-links updated.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: the B004 character-name interpretation is retained under explicit superseded history; no-xref/pointer-route evidence remains with the explanation that it does not make the method compiler-generated or non-source.

## Recommended Support Doc Changes

- `by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md` UID00043U: renamed, retained owner/emitter/reconstructable, raised `88/90 -> 92/94`, and received the exact range/hash/caller/callees/account-text/empty-string behavior plus exact formal.
- `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md` UID0002QR: raised `89/90 -> 90/92`; summary, child table, naming/source-shape, historical assumptions, exact target/callback facts, and links updated; non-reconstructable/non-emitting/blank formal and `Nested:21` retained.
- `by-class/NewUserDialogPane2.md` UID00009E: retained `92/94`; both declarations and the field were renamed, method table/layout/evidence/history updated, and unrelated class facts preserved.
- `by-file/NewUserDialogPane2.md` UID0000LW: retained `92/94`; exact registration gate/callback/resource/template/provider-consumer facts replaced stale name-prompt language while source boundaries were preserved.
- `by-file/CreateUserDialogs.md` UID0000IK: retained `90/89`; the three-variant replicated registration-gate pattern now distinguishes feature binding from registration/template ownership.
- `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` UID00043K: retained score/route; the formal/item/evidence/history now clear `m_nexonclubAccountName` without changing constructor behavior.
- `by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md` UID000443: retained score/route; the formal serializes `m_nexonclubAccountName`, producer provenance is explicit, and stale character-name history is preserved without changing packet bytes/order.
- `by-resource/str-res-localized-strings.md` UID0001RP: raised `89/94 -> 90/94` and now records id `227`/`0xe3`, exact current text, target caller, package provenance, and runtime-lookup rule.
- `by-type/by-template/FunctionObjectTemplates.md` UID0001WQ, UID00005N class support, and UID0001CS destructor support: reread after callback and verified already present at same-or-greater detail. They preserve the shared callback declaration, concrete `0x0061ff70` vtable, generated destructor pair, exact `0x0052b650`/`0x0052b730` consumer binding, 24-byte object, and feature-vs-template ownership, so no edit or validator was needed.
- Generated/manual files: B002 must not edit them. Scoped validators should refresh generated source after callback; supervisor applies exact manual text below.

## Score And Metadata Recommendation

- Historical pre-callback score/metadata: UID00043T `87/89`, owner/emitter UID00009E, reconstructable true.
- Current implemented score/metadata: UID00043T `93/94`, owner/emitter/reconstructable unchanged; UID00043U `92/94`; UID0002QR `90/92`; UID0001RP `90/94`; UID00009E/UID0000LW/UID0000IK/UID00043K/UID000443 retained their accepted metadata.
- Score rationale and reason not higher/lower: completion reaches 93 because exact control flow, resource, callback type/layout/lifetime, field semantics, owner/emitter/source placement, range, formal C++, support propagation, and manual handoff are implementation-ready. Confidence reaches 94 because independent binary, decorated type, symmetric siblings, dialog behavior, and direct resource payload agree. Scores remain below 95 because original lexical spellings, an original named constant for id 227, exact include/typedef shape, and the retained method's historical source callsite are not symbol-proven.
- Score-improvement attempt:
  - Stale behavior/name blocker: direct target/callback decompile plus resource parsing resolved it.
  - Missing caller/reachability blocker: exhaustive xref and pointer searches proved no current route; sibling duplication and exact object construction establish retained source disposition.
  - Callback type/lifetime blocker: decorated vtable, 24-byte layout, shared template docs, and registration-dialog storage/destruction resolved it.
  - Prompt/resource blocker: direct id 227 call and decoded STR.RES payload resolved it.
  - Field meaning blocker: callback producer, registration account-control source, and packet consumer resolved it.
  - Formal-C++ blocker: exact source-shape code is supplied in managed blocks.
- Metadata fields to change or leave unchanged: change only completion/confidence and path/title/formal/prose for UID00043T; owner, reconstructable, emitter, optional position, exact range, and UID remain unchanged.

## Open Questions With Attempted Resolution

- Open question: why are three structurally identical registration-gate helpers retained without current incoming xrefs?
  - Evidence checked: direct xrefs, endpoint refs, VA/RVA/raw-offset pointer searches, sibling bodies, constructor caller cluster, class/source docs.
  - Best supported resolution or inference: source had parallel class methods, but current build has no surviving direct route to these particular helpers. Retention may reflect disabled UI/config paths or link-time non-elimination. This does not change exact method behavior or source ownership.
- Open question: exact original names for method, callback, argument, and field.
  - Evidence checked: decorated callback type, resource string, sibling docs, class naming conventions, callback producer/consumer, packet serialization.
  - Best supported resolution or inference: use `OpenNexonclubRegistrationOrSendCharacterRequest`, `OnNexonclubRegistrationResult`, `openRegistration`, and `m_nexonclubAccountName`; do not retain IDA or stale names merely because PDB spellings are absent.
- Open question: literal `227` versus original enum/constant.
  - Evidence checked: current LanguageMan callers, resource docs, sibling formal C++, direct immediate.
  - Best supported resolution or inference: preserve exact runtime lookup with literal `227` now. A later coordinated string-id enum may replace the literal only if project-wide evidence establishes that source shape.
- Questions remaining unresolved, exhaustive evidence proving why no defensible answer is safe now, score/C++ impact, and unavailable future evidence required: exact historical callsite and exact original lexical spellings require unavailable original source/PDB or a separate binary containing symbols. They do not block the recommended code because behavior and best source-facing inference are resolved; they cap confidence below 95.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Callback-completion reread of current roots (by-memory advanced after the first callback read due unrelated concurrent rows; the other three roots remained unchanged):
  - `by-memory/-coverage-report.md`: SHA256 `39866F17A58097EFA75F1DED0B6AFC896E936A081F65208FB4FCF73B4E197A55`, `1,984,236` bytes / `4,566` lines. UID0002QR is at line 2596, UID00043S at line 2600, and UID00043T/UID00043U are absent.
  - `by-class/-coverage-report.md`: SHA256 `E4F6985825BD360CD322C6099EC097CF87E7597BCD9F328E500829A02937875E`, `257,808` bytes / `624` lines. UID00009E is at line 361.
  - `by-file/-coverage-report.md`: SHA256 `78B5F2C81A5BDD86AC67655EA7152F0FC8541F1AF5A7DACF8EB7AB7ACB2B0D90`, `154,448` bytes / `317` lines. UID0000IK is at line 65 and UID0000LW at line 185.
  - `by-resource/-coverage-report.md`: SHA256 `EF28BB82AE827E585B5F85E3F45D590A665C54095C2767CF970820493FA1DD72`, `16,981` bytes / `50` lines. UID0001RP is at line 38.
- File/placement: replace the exact UID0002QR row in `by-memory/-coverage-report.md`:

        - [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) 0x0052a540-0x0052c325 | executable child/index | NewUserDialogPane2CreateUserVariant : reconstructable : 90% : very-strong : Exact alternate 640x480 create-user dialog split/index with constructor, complete-destructor evidence, left/right shape shifts, nation/totem/shape/gender selectors, Nexonclub registration-or-send gate and account-result callback using STR.RES id 227, command/key/packet/notify bridges, account/character submit and packet/reply paths, singleton/vtable evidence, exact child boundaries/padding, inherited DialogPane control-manager route, corrected selected-state/edge-button behavior, source-emitting exact children, and compiler/raw no-code exclusions; historical broad aggregate, derived m_childControls, and character-name prompt/apply assumptions are superseded.

- File/placement: insert these exact rows immediately after UID00043S and before the next sibling row under UID0002QR:

            - [UID:00043T][0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md) 0x0052b650-0x0052b724 | class method | NewUserDialogPane2::OpenNexonclubRegistrationOrSendCharacterRequest : reconstructable : 93% : very-strong : Exact 212-byte boolean-gated helper with no current incoming route: false sends the character request directly; true binds a 24-byte PlainMemberFunctionObjectT callback to OnNexonclubRegistrationResult, reads STR.RES id 227 through g_pLanguageMan, and constructs the 632-byte NexonclubRegistrationDialog; trailing 0x0052b724-0x0052b730 is CC alignment.
            - [UID:00043U][0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult](by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md) 0x0052b730-0x0052b75c | callback method | NewUserDialogPane2::OnNexonclubRegistrationResult : reconstructable : 92% : very-strong : Exact 44-byte const-SimpleUString callback bound by UID00043T; stores nonempty Nexonclub account text in m_nexonclubAccountName and unconditionally sends the create-character request.

- File/placement: replace UID00009E in `by-class/-coverage-report.md`:

- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) : reconstructable : 92% : very-strong : Complete alternate 640x480 create-user dialog declaration and exact-child route under NewUserDialogPane2.cpp: constructor callers, singleton/vtable evidence, inherited DialogPane typed child lookup, own +0x26c nation/+0x270 totem/+0x274 shape-slot/+0x278 reply-phase/+0x27c Nexonclub account-name layout, exact left/right selection, exact gender-mode selectors, Nexonclub registration-or-send gate and account-result callback through STR.RES id 227, command/key/packet/notify bridges, submit/account/character packet/reply paths, class closure before [[CHILDREN]], compiler/raw exclusions, and superseded duplicate-manager, simplistic shift, generic gender-helper, loop, reselect, and character-name prompt assumptions preserved historically.

- File/placement: replace UID0000IK in `by-file/-coverage-report.md`:

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) : reconstructable : 90% : strong : Non-emitting create-user dialog family map covering old/new variants, appearance controls, shape/misc variants, boundaries, callers, split recommendations, and migration cautions; all three create-user variants retain the Nexonclub registration-or-send plus account-result callback pattern, while registration-dialog implementation and reusable PlainMemberFunctionObjectT source remain in their own modules; exact helper ownership keeps UserShape male/female banks at 0x004fd030/0x004fd050 and rejects stale cross-class and character-name prompt interpretations.

- File/placement: replace UID0000LW in `by-file/-coverage-report.md`:

- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) : reconstructable : 92% : very-strong : Alternate 640x480 create-character source under NexusTK/login/ with complete NewUserDialogPane2 declaration and exact child definitions: singleton storage, constructor/resources/callbacks, inherited DialogPane child lookup, exact left/right shape-slot behavior, nation/totem/shape selectors, exact male/female selectors, Nexonclub registration-or-send gate and account-result callback using STR.RES id 227 and m_nexonclubAccountName, command/key/packet/notify bridges, account/character submit/packet/reply paths, complete layout, exact vtable/data/lifecycle boundaries, neighboring variant separation, compiler/raw exclusions, and historical old-account, duplicate-manager, generic-helper, loop, reselect, and character-name prompt assumptions explicitly disposed.

- File/placement: replace UID0001RP in `by-resource/-coverage-report.md`:

- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) : reconstructable : 90% : very strong : DAT-backed STR.RES parser/resource contract with current package provenance and confirmed high-value ids, including zero-based id 227 text Please input nexon.com ID and password. consumed by NewUserDialogPane2's Nexonclub registration gate and the three create-user variant helpers; callers preserve LanguageMan lookup ids rather than hard-coded English.

- Reason B agent must not apply it directly: all `-coverage-report.md` files are manual supervisor-owned collision points. The exact rows above are current handoff text, not B002-applied state. The supervisor must reread current roots immediately before applying because hashes/line positions can advance after this callback.

## Follow-Up Actions

- Supervisor actions: independently verify C43T-001 through C43T-040, the exact ordinary-file hashes, the nine scoped validator records, generated readback, and this checklist; reread/apply the exact current manual coverage rows; perform Gate 2; and only then execute the report through the supervisor-only lifecycle.
- A-agent actions: none.
- B002 future actions: none unless Gate 2 identifies a concrete same-report or implementation defect. Repair this same report if returned; do not rewrite it.

## Confidence

- Recommendation confidence: very strong (`94`).
- Score confidence: strong; `93/94` accurately reflects complete source-ready behavior while respecting the 95 barrier.
- Remaining uncertainty: exact original lexical spellings, a possible symbolic string-id constant, and the unavailable retained-helper source callsite.

## Validator Results

- Working directory for every callback command: `E:\NTK\GhidraBridge\source-3\project-documentation`. Validator output canonicalized the project root to `C:\FastStorage\NTK_Sources\source-3\project-documentation`.
- `000000016639`, `2026-07-22T23:22:38-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated the UID00043T rename, `93/94` metadata, exact formal, path/reference updates, and target documentation.
- `000000016644`, `2026-07-22T23:24:22-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated the UID00043U rename, `92/94` metadata, exact formal, and callback documentation.
- `000000016650`, `2026-07-22T23:26:50-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated UID0002QR at `90/92` with its non-emitting aggregate disposition, child inventory, and corrected source history.
- `000000016653`, `2026-07-22T23:28:30-04:00`: `python .\tools\validator.py --mode file --file by-class/NewUserDialogPane2.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated the corrected class declarations, method inventory, field, and evidence.
- `000000016655`, `2026-07-22T23:30:46-04:00`: `python .\tools\validator.py --mode file --file by-file/NewUserDialogPane2.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated the corrected class source root and registration-gate/callback documentation.
- `000000016657`, `2026-07-22T23:31:51-04:00`: `python .\tools\validator.py --mode file --file by-file/CreateUserDialogs.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated the three-variant Nexonclub registration-gate family pattern and dependency ownership.
- `000000016659`, `2026-07-22T23:32:46-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated the constructor's `m_nexonclubAccountName` clear without changing behavior.
- `000000016660`, `2026-07-22T23:33:49-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated the corrected field serialization and producer history without changing packet bytes/order. Validator-owned generated side effects also refreshed UID0000LW and unrelated concurrent WeatherLayerPane/RainingLayerPane output; B002 did not edit those generated artifacts.
- `000000016667`, `2026-07-22T23:37:36-04:00`: `python .\tools\validator.py --mode file --file by-resource/str-res-localized-strings.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, generated refresh completed. This validated UID0001RP at `90/94`, added UID00043T to the resource reference index, removed UID0001RP from the generated low-score stats row, and refreshed projected/generated metadata.
- Warnings/side effects: every command reported only generic or pre-existing project-wide `[[CHILDREN]]`/empty-emitter/generated-metadata diagnostics; none was target-specific failure. Generated reports, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated C++ were validator-owned side effects and were not edited by B002.
- Final B002 generated readback: a later repository validator refresh produced `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` command `000000016678`, timestamp `2026-07-22T23:46:38-04:00`, SHA256 `0226F9D1F9DA45A37E8B2A28F953D0E9610661AD0228A9B509ADD931C9987428`, `15,250` bytes / `528` lines. It has one UID00043T definition, one UID00043U definition, corrected class declarations/field/formals, one id-227 lookup, zero stale target/callback/field names, and no target/callback empty marker. Its two empty markers are unrelated UID0002X3/UID0002X4 singleton-global pages. Commands 16668 and 16676 were earlier corrected intermediate checkpoints; a later header-only/project-wide refresh may supersede the command/hash without invalidating the semantic checks.

## Changed Files

- Renamed/modified:
  - UID00043T -> `by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md`, SHA256 `3F3D045D84704F7DC2A8610AC96289F63EF92193E8AE6F510310A9CC5500B5EA`, `11,907` bytes / `121` lines.
  - UID00043U -> `by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md`, SHA256 `302EA86E602A5F6BD0B784577B1FE5AF36909BACAB509156F9A1E9ED32917049`, `7,745` bytes / `94` lines.
- Modified:
  - `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md`, SHA256 `50DA617FDC143E62BA39EA1573E8646D6FA42B149D1C33E6AD5546274B6401D6`, `25,833` bytes / `152` lines.
  - `by-class/NewUserDialogPane2.md`, SHA256 `9DC3E47C43A30A890E81F299AC443030BCCDE47B21724BA967936E8E79BBF1D5`, `28,532` bytes / `190` lines.
  - `by-file/NewUserDialogPane2.md`, SHA256 `A34690CCDECBC069181AEE09E1A1E1BC4753B7E3D1142F99F2C65655E8C5E563`, `28,554` bytes / `171` lines.
  - `by-file/CreateUserDialogs.md`, SHA256 `BF693103B9C52E6811933D65B7752382BBFC808F73BE5611A5BF91449AA69C04`, `33,028` bytes / `215` lines.
  - `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md`, SHA256 `A5C3DF6CA1B05CC68B08F19A617A200C0404A47600B060FAD61CCE47144A3B13`, `5,090` bytes / `76` lines.
  - `by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md`, SHA256 `396643E34DE7709E36DF6DB3BF5294615AC4A8D7F6BF1AC2976C2F5F55C7E373`, `4,415` bytes / `65` lines.
  - `by-resource/str-res-localized-strings.md`, SHA256 `CFD6923D80412E486FE734DBDC1769D1A1AEF95FBC29E5D82CF1A9593C37AEC5`, `25,122` bytes / `171` lines.
  - This same active report, updated from accepted report-only state to exact callback state.
- Verify-only and unchanged: UID0001WQ, UID00005N, and UID0001CS already contained the accepted callback-template/vtable/generated-destructor and target-binding detail.
- Not manually changed: any `-coverage-report.md`, generated/tracker/audit/supervisor/validator-state/IDA/lifecycle file. Generated and project-level changes were validator-owned effects.
- Report execution: not run or probed. B002 did not invoke `execute_report`, move/archive the report, or run any lifecycle command.

## Implementation Tracking Checklist

Implementation callback pass:
- [x] Supervisor Gate 1 accepted exact report SHA256 `A3ED92DF94A1236C0F378C716919F13A2D0E4377FBD6005E7917DC28C2DBE094` and authorized C43T-001 through C43T-040.
- [x] Renamed/updated UID00043T to `NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest`, preserved exact range/UID/owner/emitter, applied `93/94`, and incorporated C43T-001 through C43T-012 and C43T-025 through C43T-027 at report-level detail.
- [x] Renamed/updated UID00043U to `NewUserDialogPane2OnNexonclubRegistrationResult`, applied `92/94`, and incorporated C43T-013 through C43T-021 at report-level detail.
- [x] Updated UID0002QR child inventory, item summary, source-shape sections, exact padding, score `90/92`, and superseded prompt history without changing its non-emitting aggregate disposition, blank formal, or `Nested:21`.
- [x] Updated UID00009E declarations, method inventory, `+0x27c` field, evidence, cross-links, and historical corrections while retaining `92/94` and the owner/emitter route.
- [x] Updated UID0000LW and UID0000IK with the replicated registration-gate pattern, dependency ownership, stale-history correction, and exact target/support links.
- [x] Updated UID00043K formal/prose to clear `m_nexonclubAccountName` without changing constructor behavior.
- [x] Updated UID000443 formal/prose to serialize `m_nexonclubAccountName` without changing packet layout/order.
- [x] Updated UID0001RP with id `227` / `0xe3`, exact current text, target caller, package provenance, runtime-lookup rule, and `90/94`.
- [x] Verified UID0001WQ/UID00005N/UID0001CS already preserve shared callback template/vtable/generated-destructor evidence and the exact NewUserDialogPane2 binding at same-or-greater detail; no edit was justified.
- [x] Confirmed no additional report target UIDs are declared; all support UIDs remain bounded implementation destinations.
- [x] Updated current target state and actual evidence checked to callback-complete truth.
- [x] Updated C43T-001 through C43T-040 from report-only `proposed` to exact `applied`, `already-present`, or `excluded-with-reason` verification state.
- [x] Applied metadata/score changes: UID00043T `93/94`, UID00043U `92/94`, UID0002QR `90/92`, UID0001RP `90/94`; retained accepted support metadata elsewhere.
- [x] Preserved score-blocker resolution, exact remaining lexical/callsite uncertainty, and score impact.
- [x] Retained UID00009E owner/emitter and UID0000LW source route; no owner/emitter/reconstructable change was introduced.
- [x] Renamed UID00043T and UID00043U paths/titles; no split, merge, reclassification, range change, or new child was introduced.
- [x] Confirmed source placement, exact range/padding, and no-IDA-edit dispositions.
- [x] Installed the two exact managed formal C++ blocks and propagated `m_nexonclubAccountName` through class/constructor/packet formals.
- [x] Excluded third-party import with reason: native NexusTK class/resource path.
- [x] Incorporated exact bytes, hashes, xrefs, callees, callback layout/lifetime, resource provenance, siblings, ownership, score rationale, rejected alternatives, and negative evidence without summary loss.
- [x] Preserved B004 character-name assumptions as explicit superseded history rather than deleting them.
- [x] Ignored stale Wave2/Wave3 mentions and did not use them as evidence.
- [x] Closed in-scope open questions or retained only evidence-backed lexical/callsite limits.
- [x] Ran nine scoped validators serially, recording literal commands, working directory, command IDs/timestamps, exit/ok, warnings, and generated refresh state.
- [x] Confirmed final B002 readback of generated `NewUserDialogPane2.cpp` command 16678 has corrected declarations/field/target/callback bodies, zero stale invented prompt names, and no target/callback empty marker; two unrelated singleton-global empty markers remain.
- [x] Reread current manual by-memory/by-class/by-file/by-resource roots after callback and supplied exact replacement/insertion text without editing them.
- [x] All B002-applied ordinary-file leases were acquired only for immediate edit/validator batches and released immediately; final lease audit must show zero B002 leases.
- [ ] Supervisor applies and validates the exact manual coverage rows after one final current-root reread.
- [ ] Supervisor independently performs Gate 2 and, only after it passes, runs the supervisor-only report execution lifecycle.
- [x] No accepted B002 ordinary implementation item remains blocked or unapplied.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000016689","destination_path":"executed-b-agent-research/B002/00043T-NewUserDialogPane2PromptCreateCharacterName-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00043T-NewUserDialogPane2PromptCreateCharacterName-source-quality.md","timestamp":"2026-07-23T00:01:35-04:00","uid":"00043T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
