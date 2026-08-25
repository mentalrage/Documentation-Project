** TARGET-REPORT-UID:0002ZP **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002ZP g_pPatchPane2 Source-Quality Research

## Finalized Report / Current Recommendation

- Current implemented state: physical slot UID0002ZP `[0x0069ba2c,0x0069ba30)` is `92/94`, canonical owner UID0000RZ, reconstructable false, blank emitter/position/formal, and `Nested:0`. It is loader-created physical backing, not a second source declaration.
- Final disposition: semantic global UID0000RZ is `92/94` and remains the sole source definition `PatchPane2 *g_pPatchPane2 = 0;` in `NexusTK/patch/PatchPane.cpp`. The exact four-byte target has five lifecycle references but no independent handwritten declaration beyond that semantic global.
- Source-family closure is complete: class/layout, constructor, ordinary destructor, callback predicate, close/finish/report helpers, source route, aggregate split, vtable/no-code policy, and main/send bodies are implemented. Serial allocation produced exact UIDs `0004VS`, `0004VT`, `0004VU`, `0004VV`, `0004VW`, and `0004VX`; no placeholder token remains.
- Supervisor-owned manual coverage incorporation is also complete: the exact M01-M20 handoff was applied and externally validated under commands `16351-16355`, and waited command `16356` reconfirmed the generated/tracker state. B005 did not perform those supervisor actions.
- B001 boundary protection: active UID0002ZO `[0x0069ba28,0x0069ba2c)` is predecessor-only evidence. This report neither edits nor consumes it. The successor `[0x0069ba30,0x0069ba34)` remains zero-reference filler before `g_pPowerDialog` at `0x0069ba34`.
- Confidence: very strong for bytes, PE zero-fill, boundaries, pointer type, five-reference lifecycle, one-definition route, class inheritance, object size, field layout, method ranges, and source module; strong rather than symbol-exact for private field/helper spellings and the original callback-interface constant names.

## Supporting Research

- Assignment source: canonical `tools/leaser/Agents/Agent-B005/goal.md`, first as direct report-only UID0002ZP research and then as the supervisor-accepted same-report implementation callback. Manual coverage, generated output, tracker, audit, lifecycle state, validator state, and IDA were never edited manually by B005; generated/tracker changes and commands `16351-16356` below are validator/supervisor-owned external actions.
- Mandatory live MCP evidence was collected through the healthy direct HTTP endpoint `http://127.0.0.1:13337/mcp`. A fresh `idb_list` selected active/adopted session `9b0396a3`; `server_health(database=9b0396a3)` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache (`2067` entries).
- A current bounded recheck returned 32 zero bytes at `0x0069ba20`, including the target, and exactly five xrefs to `0x0069ba2c`: constructor stores at `0x005486f4/0x005486fb`, raw ordinary-destructor clear at `0x00548a6d`, constructor-EH clear at `0x00549340`, and scalar deleting destructor clear at `0x005493d0`.
- Independent raw PE analysis used `E:/NTK/Resources/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. `.data` has RVA `0x0026d000`, virtual size `0x2fe24`, raw size `0xd800`, raw pointer `0x26ac00`, raw-backed RVA end `0x0027a800`, and virtual end `0x0029ce24`. Target RVA `0x0029ba2c` is in the loader-zero virtual tail, beyond raw file data.
- Exact target bytes are `00 00 00 00`; SHA256 of those four bytes is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. Historical `0xffffffff` wording is disproved and retained only as superseded provenance.
- Old-report search terms actually used: `0002ZP`, `0x0069ba2c`, `0x0069BA2C`, `g_pPatchPane2`, `PatchPane2`, `dword_69BA2C`, `unk_69BA2C`, `sub_548690`, `sub_548A10`, `sub_549370`, `PatchPane2Layout`, `PatchPane2VtableData`, `PatchPane`, and `PatchPane.cpp`.
- Search roots actually checked: central `executed-b-agent-research/**`; all active `tools/leaser/Agents/Agent-B*/research/**`; `tools/leaser/Agents/Older-Research/**`; and legacy `archived/b-agent-reports-20260623/**/research/**`. The legacy roots had no narrow exact-target match.
- Every narrow-term matching report path was opened read-only:

| Matching report | Classification and useful current finding |
| --- | --- |
| `executed-b-agent-research/B001/0001CJ-MiscWorkThreadAndNotifications-source-quality.md` | Incidental support; confirms work-thread notification/channel and HTTP request route. |
| `executed-b-agent-research/B001/0002KK-FlyingParcelPaneAnimateStep-source-quality.md` | Incidental adjacent-family evidence only; no PatchPane2 source ownership. |
| `executed-b-agent-research/B002/00012G-simple-ustring-vector-grow-insert-source-quality.md` | Incidental container evidence; compiler helper does not prove PatchPane2 used a project wrapper instead of its observed three-pointer vector. |
| `executed-b-agent-research/B002/0002HJ-Win32ErrorConstructor-source-quality.md` | Incidental exception-source support for close/rename failures. |
| `executed-b-agent-research/B002/0002KB-ParcelPaneConstructor-source-quality.md` | Incidental predecessor/boundary support; not target ownership. |
| `executed-b-agent-research/B003/0001EQ-patchpane-family-source-quality.md` | Direct family evidence; split inventory and module route are useful, while unresolved class/C++ blockers are superseded by this pass. |
| `executed-b-agent-research/B003/0001ES-0001ET-PatchFileSliceCtorDtor-source-quality.md` | Incidental same-module child evidence; no direct target declaration. |
| `executed-b-agent-research/B003/0001EW-0001EY-0001EZ-patchpane2-helper-source-quality.md` | Direct helper evidence; predicate/send/EH facts were revalidated, and old blank-predicate/API uncertainty is superseded. |
| `executed-b-agent-research/B003/0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md` | Direct historical mixed-range report; exact split was useful, but aggregate-emitter implications and old initializer language are superseded. |
| `executed-b-agent-research/B003/00036Y-MainMenuPaneCore-source-quality.md` | Incidental constructor-caller and finish/exit route support. |
| `executed-b-agent-research/B005/0000MF-ParcelPane-empty-emitter-family-source-quality.md` | Incidental predecessor semantic/physical split precedent. |
| `executed-b-agent-research/B005/000179-ObjectStatusBlobParsers-source-quality.md` | Incidental packed-buffer/source-shape precedent only. |
| `executed-b-agent-research/B006/0002KN-ClearParcelPaneSingleton-source-quality.md` | Incidental adjacent Singleton/EH cleanup precedent. |
| `executed-b-agent-research/B008/0001ER-PatchPanePacketResponseHandler-source-quality.md` | Direct same-file source-route and callback style support. |
| `executed-b-agent-research/B008/0002JY-0002GR-ApplicationAccessorsAndExchangeMsgHandler-source-quality.md` | Incidental Application/global/accessor evidence. |
| `executed-b-agent-research/B009/0001EV-PatchPane2MainLoop-source-quality.md` | Direct method report; event-state/body evidence remains useful, while fake `m_statusControls` storage is corrected to inherited child lookup. |
| `executed-b-agent-research/B010/0001EX-PatchPane2CloseAndRenameDownloadedFile-source-quality.md` | Direct duplicate-body report; no-caller covered-by disposition remains valid. |
| `executed-b-agent-research/B010/00022D-PatchPane2DownloadPathJoinHelper-source-quality.md` | Direct callee evidence; confirms StringBase concatenation ownership, not PatchPane2 ownership. |
| `executed-b-agent-research/B010/0002R7-PatchPane2AdvanceDownloadIndexRaw-source-quality.md` | Direct raw-body report; exact duplicate/no-entry disposition remains valid. |
| `executed-b-agent-research/B011/000012-brdir-Notification-source-quality.md` | Incidental notification type/layout evidence. |
| `executed-b-agent-research/B011/0000MH-PatchPane-empty-emitter-family-source-quality.md` | Direct family implementation evidence; source route/global/send/covered-by choices remain useful, while class/predicate/layout deferrals are closed here. |
| `tools/leaser/Agents/Agent-B001/research/0002ZO-g_pParcelPane-source-quality.md` | Active adjacent predecessor coordination evidence. B001 owns UID0002ZO; this report is read-only and does not preempt it. |
| `tools/leaser/Agents/Agent-B002/research/0001PY-g_pBowGaugeObjectPane-source-quality.md` | Active incidental singleton-storage precedent; no target ownership. |

- Evidence-based old-report conclusion: no prior standalone direct UID0002ZP source-quality report exists. The PatchPane2 family reports are evidence leads, not substitutes; all material target, source-family, and no-code conclusions below were independently checked.

## Target

- Target UID: `0002ZP`.
- Target path: `by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md`.
- Source queue: validator-owned `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable` at assignment time.
- Current supervisor classification: accepted callback implemented; exact manual handoff externally applied and validated; same report reconciled for independent Gate 2 review.
- Current score/metadata: `92/94`, owner UID0000RZ, reconstructable false, blank emitter/position/formal, `Nested:0`.

## Current Target State

- Current target SHA256: `D1FB8382F6FD3767306DB71ABAF3EDA9F2C1EE4B48724B894F4709852D4B1A9D`, `9,097` bytes / `89` physical lines. It records loader-zero storage, exact four-byte hash, all five lifecycle refs, one-definition split, predecessor/filler/successor boundaries, and dated rejection of the old all-ones initializer.
- The target is now structurally correct as physical no-code storage: false reconstruction, no emitter, and a blank formal. UID0000RZ alone emits the semantic definition.
- UID0000RZ, UID0000AA, UID0000MH, and UID0001VJ are now `92/94`; the class declaration and layout marker are complete and source order is validator-owned.
- B005 final waited command `000000016297` at `2026-07-21T19:59:16-04:00` remains historical callback provenance. External commands `16317` and `16340` are later historical evidence-time checkpoints. After the supervisor applied manual coverage, waited command `000000016356` refreshed `PatchPane.cpp` at `2026-07-21T21:02:15-04:00`, SHA256 `9A4853E432C564B4A07AC44DCC574D3838D63AE883CB2DF659880ABB36419470`, `15,080` bytes / `401` lines. That command-scoped readback preserves one global, one complete class, eight authored source definitions, two covered comments, zero target/aggregate/EH/thunk/scalar/vtable markers, and no resolved-page Empty Emitter Marker. No mutable generated hash is asserted as permanent authority.
- Tracker commands `16315`, `16339`, `16343`, and later unrelated deferred epochs are historical evidence-time state. The post-coverage waited checkpoint is command `000000016356`, refreshed `2026-07-21T21:02:15-04:00`, SHA256 `5BE4DE7F334E25C94FE969AEBE0E645AE9A780D0A5BA5ECBAFD759661EBF636D`, `1,557,918` bytes / `6,301` lines. That named epoch retains UID0002ZP and all six real child UIDs exactly once with the applied states; no mutable tracker hash is a permanent authority.
- Current lifecycle statement: B005's accepted implementation and report reconciliation are complete, and the supervisor has externally applied and validated M01-M20. Independent Gate 2, report execution, movement, and archival remain external supervisor lifecycle state; no B005 work item remains pending.

## Executive Recommendation

- Applied UID0002ZP as physical backing only at `92/94`, owner UID0000RZ, false reconstruction, blank emitter/position/formal, exact range/path/title, and `Nested:0`.
- Retained UID0000RZ as the sole `92/94` module-global source definition; no `extern` or second physical definition was introduced.
- Completed UID0000AA as `class PatchPane2 : public DialogPane, public Singleton<PatchPane2>` with exact `0x294` layout, constructor, virtual destructor, two callback virtuals, four private helpers, seven source fields, and post-brace `[[CHILDREN]]`.
- Registered the six exact ranges serially as UID0004VS/0004VT/0004VU/0004VV/0004VW/0004VX before cross-linking.
- Preserved UID0002R7 and UID0001EX as covered duplicates and UID0001EZ/UID0001F0/UID0002OJ/UID0004VX as compiler/EH-only no-code evidence.
- Routed all source emitters through `NexusTK/patch/PatchPane.cpp`; no companion split or explicit vptr/global-clear/delete/EH/decompiler mechanics were added.

## Supervisor Active Recheck

- The supervisor assigned exact UID0002ZP after UID00029O completed, accepted report SHA `84B505F84BC9C28EA0F18FB69BFE0FC2B1BB2959D0C19DC05EF236E52FD451F9`, and authorized this completed implementation callback.
- Split-first analysis was mandatory because the target was formerly part of UID0002A0 and because B001 owns adjacent UID0002ZO. Exact target, filler, power-dialog, aggregate, method, table, and padding boundaries were rechecked.
- Every decisive direct source body in the PatchPane2 island is either supplied with destination-ready C++, retained as a proven covered-by duplicate, or proven compiler/EH-only with a blank formal. No direct body is deferred as generic future research.

## Inference Research Guidance Check

- `by-structure.md` source-first, split-first, no-duplicate-emission, and cumulative `Nested` rules control the recommendation. `Nested` is not a child count.
- Existing docs were treated as hypotheses where they used `0xffffffff`, `dword_69BA2C`, fake `m_statusControls`, provisional companion-file routing, unresolved callback ABI, raw-helper liveness, or blank class/layout C++.
- Direct facts are labeled as MCP/PE/byte/xref/disassembly/RTTI facts. Private field and helper names are source-facing inferences supported by repeated offset/consumer roles. Covered-by/no-code choices are source-shape inferences constrained by one-definition and caller evidence.
- Wave2/Wave3 references encountered in historical docs were ignored as stale generated analyses where they contradicted current IDA function/vtable evidence. No Wave2/Wave3 artifact is used as authority.

## Heuristic / Inference Reanalysis And Validation

- **Initializer and storage role:** raw bytes alone could look like a compiled zero initializer. PE mapping proves the target has no raw initializer at all; Windows loader zero-fill supplies it. Human source still has `= 0` at semantic UID0000RZ. Therefore physical UID0002ZP is no-code backing, while semantic UID0000RZ is the source emitter.
- **Type/name:** all five refs store/clear a `PatchPane2 *`, constructor `0x00548690` publishes `this`, destructor paths clear it, and the by-global/module convention uses `g_p<Class>`. `PatchPane2 *g_pPatchPane2` is stronger than `void *`, integer, `dword_69BA2C`, or an aggregate member.
- **Inheritance:** RTTI base descriptors prove direct `DialogPane` and direct `Singleton<PatchPane2>` inheritance. Singleton has PMD `{mdisp=0x26c,pdisp=-1,vdisp=0}` and class descriptor attribute `0x40`; empty-base optimization overlaps it with the first tail member. `EventHandler`/`TimerHandler` are inherited through the dialog hierarchy, so they are not repeated as direct bases.
- **Layout:** base/empty-base region ends at `+0x26c`; two `StringBase<wchar_t>` objects occupy `+0x26c/+0x270`; vector begin/end/capacity occupy `+0x274/+0x278/+0x27c`; current index, active `FILE *`, pass count, and two promoted version values occupy `+0x280/+0x284/+0x288/+0x28c/+0x290`; `sizeof(PatchPane2)==0x294`.
- **Container:** constructor push-back, main-loop `.size()`/indexing, destructor three-pointer cleanup, and current layout all support `std::vector<StringBase<wchar_t> >`. The generic simple-string-vector helper report is a compiler support lead, not proof that PatchPane2 used a different declared wrapper.
- **Inherited controls:** main-loop object-relative `+0x1fc` is DialogPane child-control infrastructure. No PatchPane2 tail field exists there. `GetChild<StaticTextControlPane>(0/1)` is compile-legal with current DialogPane declarations and replaces the unsupported `m_statusControls` field.
- **Constructor input:** sole caller builds a local packet-derived buffer with two little-endian words at `+0/+2`, count byte at `+4`, and `count` fixed 256-byte ANSI rows at `+5`. `const unsigned char *patchInfo` preserves the observed source-era packed input without inventing a globally shared struct name.
- **Ordinary destructor gap:** no IDA function object starts at `0x00548a10`, but bytes, vtable resets, file close, member destructors, global clear, base teardown, scalar-wrapper call, and constructor-EH parity prove a real source destructor body through `0x00548a7d`. Absence of an IDA model is not no-source evidence.
- **Predicate ABI:** exact seven-instruction body takes one stack argument, returns `event->m_type == 0x16`, and is installed in the callback vtable. Paired `HandleDownloadWorkEvent(const WorkThreadNotification *)` and current callback family support the virtual member declaration; `AcceptsDownloadWorkEvent` is the best role name.
- **Raw `0x00549020`:** no function object, xref, pointer, immediate, or relative-branch entry exists. The bytes duplicate main-loop subtype-3 index/pass logic exactly. It remains reconstructable binary evidence but is covered by the main method and must not emit a second body.
- **Modeled `0x00549080`:** the helper has a real function object but zero callers/xrefs, while main subtype-2 emits its complete close/remove/rename/launch behavior inline. It is a canonical duplicate/unused out-of-line copy, retained as a covered-by comment rather than a second active source method.
- **Compiler glue:** UID0001EZ is constructor-unwind global clear; UID0001F0 are adjustor thunks; the scalar deleting destructor wraps the ordinary destructor and optional delete; UID0002OJ vtables derive from class/virtual definitions. None receives handwritten ABI mechanics.
- **Source placement:** constructor and methods form one contiguous PatchPane2 island inside the existing PatchPane module; globals/vtables/literals and the common MainMenu patch-decision caller reinforce `NexusTK/patch/PatchPane.cpp`. There is no path/string/compilation-unit evidence for a separate `PatchPane2.cpp`.
- **Rejected alternatives:** integer/global-array field, physical source definition, mixed Parcel/Patch aggregate, direct EventHandler/TimerHandler duplication, SimpleUStringVector substitution, explicit Singleton global writes, handwritten vptrs/EH/delete flags, active raw duplicate, active no-caller rename duplicate, and companion file are rejected by the evidence above.
- No score-blocking open question remains. Exact historical private spellings are not recoverable, but repeated source roles make the chosen names high-probability and do not block compile-legal source.

## Evidence Standards Used

- Highest tier: fresh IDA MCP bytes, xrefs, function lookup, decompilation/disassembly, callers/callees, vtable/RTTI data, and bounded global reads.
- Independent corroboration: raw PE section mapping, exact function-range SHA256 values, literal/string decoding, current ordinary by-* docs, generated `PatchPane.cpp` semantics at named command epochs, row-specific tracker/manual checks at named evidence epochs, and old-report comparisons.
- Negative evidence was required for duplicate/no-source conclusions: zero entry/xref/pointer/branch routes were combined with exact body parity, compiler patterns, and a canonical emitting body. Absence of xrefs alone was not used to deny source.
- Confidence is capped below original-symbol certainty because private names and enum constants are inferred. Behavior, layout, ownership, and source/no-code disposition are not dependent on those original spellings.

## Evidence Checked

- Fresh MCP calls: `idb_list`, `server_health`, bounded `get_bytes`, `get_global_value`, `xrefs_to`, `lookup_funcs`, `decompile`, `disasm`, caller/callee analysis, vtable/RTTI reads, and string reads under session `9b0396a3`.
- Exact PE/function bytes and hashes: target plus constructor, ordinary destructor, main callback, predicate, close, finish, raw advance, close/rename duplicate, send, report, EH clear, adjustors, and scalar wrapper.
- Evidence inputs: current ordinary target, semantic global, PatchPane2 class/layout/vtable, PatchPane file, aggregate, main/predicate/raw/rename/send/EH/adjustor pages, DialogPane/control/string/vector/work-thread supports, B001 predecessor, and successor filler/power-dialog neighborhood; mutable generated source, tracker, ignored ledger, and manual coverage roots were read at explicitly named evidence-time checkpoints.
- Old reports: every narrow target/family match listed under Supporting Research was opened; no direct prior standalone UID0002ZP report exists.
- Negative checks: no raw target initializer; no sixth target xref; no xref at successor filler; no modeled ordinary-destructor start; no raw-advance entry route; no close/rename caller; no target-generated marker; no evidence for a companion source file; no evidence for a standalone vtable/global-clear/scalar-wrapper source body.
- Tool note: an early bounded direct-HTTP attempt used obsolete singular parameter names and returned schema validation errors. Live `tools/list` corrected the request shape immediately; subsequent valid calls succeeded. This was not MCP downtime and no conclusion relies on failed calls.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target bytes are exactly four zeros with SHA256 `DF3F6198...B81119`. | 99 | MCP bounded bytes plus PE read | UID0002ZP bytes/evidence | incorporate | applied |
| C02 | Target lies in `.data` virtual tail beyond raw-backed RVA `0x27a800`; loader creates zero storage. | 99 | PE section table and RVA mapping | UID0002ZP initialization | incorporate | applied |
| C03 | Historical `0xffffffff` initializer is false for this executable and must be retained only as superseded history. | 99 | current bytes/PE versus old docs | target/global/class/file history | historicalize | applied |
| C04 | Exact boundaries are predecessor UID0002ZO `[69ba28,69ba2c)`, target `[69ba2c,69ba30)`, filler `[69ba30,69ba34)`, power dialog at `69ba34`. | 99 | bytes, xrefs, current pages | target/aggregate/boundary prose | incorporate | applied |
| C05 | Exactly five target xrefs exist at `5486f4`, `5486fb`, `548a6d`, `549340`, and `5493d0`. | 99 | fresh MCP `xrefs_to` | target/global/class/file | incorporate | applied |
| C06 | Constructor publishes `this` and has a null fallback clear through Singleton lowering. | 98 | ctor disassembly/decompile/xrefs | constructor/target/global | incorporate | applied |
| C07 | Raw `[548a10,548a7d)` is the ordinary destructor and clears the singleton at `548a6d`. | 97 | exact bytes, vtable/member/base teardown, scalar/EH parity | new destructor/class/aggregate | incorporate | applied |
| C08 | UID0001EZ is constructor-EH cleanup only and remains false/non-emitting. | 99 | sole ctor-unwind xref, 11-byte clear body | UID0001EZ | already-present | applied |
| C09 | Scalar wrapper `[549370,54940f)` calls ordinary destruction and optional delete; it is compiler-only. | 99 | decompile/disasm/vtable adjustors | new scalar page/class | incorporate | applied |
| C10 | Physical UID0002ZP is false/non-emitting with blank formal; UID0000RZ alone emits source. | 99 | PE storage role, one-definition, generated state | Destination 1/2 | incorporate | applied |
| C11 | Sole source definition is `PatchPane2 *g_pPatchPane2 = 0;` in PatchPane.cpp. | 98 | current global formal, lifecycle, file route | UID0000RZ | already-present | applied |
| C12 | Source-facing type/name are `PatchPane2 *` / `g_pPatchPane2`; integer/raw labels are rejected. | 99 | all stores/clears and class lifecycle | target/global/manual rows | incorporate | applied |
| C13 | PatchPane2 directly inherits `DialogPane` and `Singleton<PatchPane2>`; Singleton EBO begins at `+0x26c`. | 97 | RTTI BCA/BCD/PMD and ctor/dtor | class/layout | incorporate | applied |
| C14 | Exact object size is `0x294` with resolved tail fields through `+0x290`. | 97 | ctor/main/send/dtor offset union | class/layout | incorporate | applied |
| C15 | Filename storage is a three-pointer `std::vector<StringBase<wchar_t> >`; `+0x1fc` controls are inherited, not a PatchPane2 field. | 94 | push/index/size/destructor and DialogPane API | class/layout/main | incorporate | applied |
| C16 | Constructor is `[548690,548a06)`, 886 bytes, SHA `69D138CF...7CF7C41`, called from `4f7432`. | 99 | bytes/lookup/xref | new constructor/aggregate | incorporate | applied |
| C17 | Constructor input is two little-endian words, one count byte, and fixed 256-byte ANSI name rows. | 97 | MainMenu caller and ctor parser parity | constructor/class | incorporate | applied |
| C18 | Constructor builds a centered 200x100 dialog with Ready/count/Cancel controls, status layer, Patcher paths, and first request. | 96 | ctor decompile, literals, control APIs | constructor/class/file | incorporate | applied |
| C19 | Constructor source must omit explicit vptr, global publish, EH guards, and base/compiler lowering. | 99 | compiler-pattern separation | constructor/class | reject-invalid | applied |
| C20 | Ordinary destructor source closes the active file; automatic members/bases/Singleton perform remaining teardown. | 96 | raw dtor and source/ABI separation | new destructor | incorporate | applied |
| C21 | Predicate is `AcceptsDownloadWorkEvent` and tests event type byte `+4 == 0x16`; main separately tests HTTP channel `+8`. | 96 | predicate disasm/vtable and main decompile | UID0001EW/class | incorporate | applied |
| C22 | `[548f50,548f72)` is `ClosePatchFile`, closing and clearing `m_activePatchFile`. | 99 | exact decompile/callers | new close/class | incorporate | applied |
| C23 | `[548f80,54901f)` is `FinishAndExit`, optional alert, delay, dialog/menu shutdown, and application exit. | 97 | exact decompile/callers/globals | new finish/class | incorporate | applied |
| C24 | `[5492d0,549339)` is `ReportWriteError`, formatting `L"Error writing %s"` and calling FinishAndExit. | 99 | exact decompile/string/two callers | new report/class | incorporate | applied |
| C25 | Main callback remains source-bearing but replaces unsupported `m_statusControls` with inherited `GetChild<StaticTextControlPane>`. | 96 | current body plus DialogPane layout/API | UID0001EV/class | incorporate | applied |
| C26 | Raw `[549020,549080)` has no entry route and duplicates main subtype-3; keep covered-by main, not standalone C++. | 98 | exhaustive negative route scan and body parity | UID0002R7 | already-present | applied |
| C27 | Modeled `[549080,549214)` has zero callers and duplicates main subtype-2; keep covered-by main. | 98 | MCP callers/xrefs/body parity | UID0001EX | already-present | applied |
| C28 | Send helper remains `SendDownloadRequest`, using version values, final path, filename vector, and MiscWorkThread HTTP queue. | 97 | exact body/four callers/StringBase callee | UID0001EY/class | already-present | applied |
| C29 | Scalar deleting destructor gets a false/non-emitting exact child, blank formal, and no handwritten flags/delete. | 99 | compiler wrapper shape | new scalar page | incorporate | applied |
| C30 | UID0001EZ retains false/non-emitting blank formal and receives complete lifecycle synchronization only. | 99 | constructor unwind | UID0001EZ | already-present | applied |
| C31 | UID0001F0 retains false/non-emitting blank formal as two compiler adjustor thunks. | 99 | exact thunk bytes/vtable routes | UID0001F0 | already-present | applied |
| C32 | UID0002OJ becomes false/non-emitting blank formal; vtable bytes are compiler products of class/virtual declarations. | 99 | RTTI/vtable/compiler source policy | UID0002OJ | incorporate | applied |
| C33 | UID0001EQ remains false/non-emitting aggregate but gains complete split inventory and six real children after registration. | 98 | exact island ranges/padding/source roles | aggregate | incorporate | applied |
| C34 | `NexusTK/patch/PatchPane.cpp` is the sole current route; companion PatchPane2.cpp remains rejected. | 95 | contiguous island, globals, literals, shared caller, current generator | class/file/all emitters | incorporate | applied |
| C35 | Literal/global/caller evidence resolves Ready/Cancel/Patcher paths/error text/status layer/MiscWorkThread/Application routes. | 97 | MCP strings/xrefs/decompilation/current docs | constructor/helpers/file | incorporate | applied |
| C36 | No prior standalone direct UID0002ZP report exists; 23 narrow matches are direct-family or incidental evidence only. | 99 | exact multi-root searches and opened reports | Supporting Research/history | incorporate | applied |
| C37 | Target/global/class/file/layout/aggregate/method/compiler pages receive only evidence-justified score changes listed below. | 96 | blocker-by-blocker closure | metadata destinations | incorporate | applied |
| C38 | Exact no-loss manual coverage actions were supplied by B005 and later applied/validated by the supervisor without B005 editing those roots. | 99 | row comparison plus supervisor commands `16351-16355` | manual handoff/application history | incorporate | applied |
| C39 | Callback must issue six UIDs serially, scoped-validate each changed page, then wait-generated and inspect exact output. | 99 | validator workflow/source dependencies | checklist/validator plan | incorporate | applied |
| C40 | Third-party import, IDA mutation, B001 UID0002ZO edit, generated/manual direct edit, and report lifecycle action are all excluded. | 99 | scope and source ownership | all destinations | reject-invalid | excluded-with-reason |

Callback verification notes:

| Claim | Terminal destination-specific proof |
| --- | --- |
| Claim C01 | UID0002ZP current SHA `D1FB8382...B1A9D` records four zero bytes/hash; validator `16281`. |
| Claim C02 | UID0002ZP retains `.data` RVA/raw-tail mapping and loader-zero conclusion; validator `16281`. |
| Claim C03 | UID0002ZP/UID0000RZ/class/file retain the old all-ones claim only as superseded history. |
| Claim C04 | UID0002ZP and UID0001EQ retain predecessor/target/filler/power-dialog boundaries; UID0002ZO remained verify-only SHA `A04BE87C...773EC`. |
| Claim C05 | UID0002ZP, UID0000RZ, class, and file record all five exact lifecycle refs; validators `16281/16282/16284/16286`. |
| Claim C06 | UID0004VS and global/target pages record constructor publish/fallback while D4 omits compiler lowering; allocation `16273`. |
| Claim C07 | UID0004VT records raw ordinary-destructor range/liveness/global clear/member/base parity; allocation `16274`. |
| Claim C08 | UID0001EZ remains NONE/false/blank with complete constructor-unwind proof; validator `16294`. |
| Claim C09 | UID0004VX is NONE/false/blank and linked to ordinary destructor/adjustors/vtable; allocation `16278`. |
| Claim C10 | UID0002ZP D1 is blank/false and UID0000RZ D2 is sole definition; generated command `16297` counts `0/1`. |
| Claim C11 | UID0000RZ retains exact `PatchPane2 *g_pPatchPane2 = 0;` at position 10; validator `16282`. |
| Claim C12 | Target/global/class/file use only pointer/global source names; generated output has zero `dword_`/raw labels. |
| Claim C13 | UID0000AA D3 and UID0001VJ record direct DialogPane/Singleton inheritance and EBO; validators `16284/16287`. |
| Claim C14 | UID0000AA/UID0001VJ apply the exact typed `0x294` layout; generated class contains all seven source fields. |
| Claim C15 | Class/layout/main use `std::vector<StringBase<wchar_t> >` and inherited `GetChild`; generated has zero `m_statusControls`. |
| Claim C16 | UID0004VS records exact range/size/hash/caller and emits one constructor; allocation `16273`, generated `16297`. |
| Claim C17 | UID0004VS records two words/count/fixed 256-byte ANSI rows and emits matching parser source. |
| Claim C18 | UID0004VS records/emits centered Ready/count/Cancel dialog, status layer, paths, and first request. |
| Claim C19 | UID0004VS formal and generated source contain no explicit vptr/global publish/EH guard/base teardown. |
| Claim C20 | UID0004VT D5 emits only `ClosePatchFile`; automatic member/base/Singleton teardown remains compiler-owned. |
| Claim C21 | UID0001EW D7 tests `m_type`; UID0001EV D6 separately tests `m_channel`; validators `16290/16289`. |
| Claim C22 | UID0004VU D8 emits one close-and-clear body at position 70; allocation `16275`, generated `16297`. |
| Claim C23 | UID0004VV D9 emits one alert/delay/dialog/menu/application-exit body; allocation `16276`. |
| Claim C24 | UID0004VW D13 emits one `Error writing %s` forwarder with exact range/callers; allocation `16277`. |
| Claim C25 | UID0001EV D6 contains three `GetChild<StaticTextControlPane>` calls and zero fake field references; validator `16289`. |
| Claim C26 | UID0002R7 stays true/class-owned at `90/94`, position 90, exact D10 covered comment; validator `16291`. |
| Claim C27 | UID0001EX stays true/class-owned at `92/94`, position 100, exact D11 covered comment; validator `16292`. |
| Claim C28 | UID0001EY remains exact D12 at `92/94`, position 110, with complete caller/type route; validator `16293`. |
| Claim C29 | UID0004VX is a registered blank compiler wrapper with zero generated marker/body; allocation `16278`, refresh `16297`. |
| Claim C30 | UID0001EZ lifecycle sync is applied without metadata/formal emission change; validator `16294`. |
| Claim C31 | UID0001F0 two-thunk sync is applied without metadata/formal emission change; validator `16295`. |
| Claim C32 | UID0002OJ is class-owned, false, blank emitter/position/formal, with zero generated marker; validator `16296`. |
| Claim C33 | UID0001EQ is `92/94`, false/blank, and lists all real children/ranges/padding/source roles; validator `16288`. |
| Claim C34 | UID0000MH/class/aggregate route every emitter through `NexusTK/patch/PatchPane.cpp`; generated command `16297`. |
| Claim C35 | Constructor/helpers/file retain all accepted literals, globals, callers, resources, and application/work-thread routes. |
| Claim C36 | The 23 opened-report classifications and no-prior-direct-report conclusion remain preserved in Supporting Research. |
| Claim C37 | Current 20-path hash table proves only accepted scores/metadata changed; every terminal scoped validator is recorded. |
| Claim C38 | Exact M01-M20 text contains the six real UIDs, remained unchanged as implementation history, and matches the supervisor-applied rows validated by commands `16351-16355`; the roots remain unedited by B005. |
| Claim C39 | Serial allocators `16273-16278`, scoped validators `16281-16296`, and waited refresh `16297` completed with zero leases. |
| Claim C40 | Excluded with reason: no import, IDA mutation, UID0002ZO edit, direct generated/manual/state edit, execute_report, or lifecycle command occurred. |

## Positive Evidence Summary

- PE mapping and bytes prove exact loader-zero physical storage; constructor/destructor/EH/scalar xrefs prove one `PatchPane2 *` lifecycle.
- RTTI, vtables, constructor/destructor, member-offset consumers, and current class/layout docs converge on a complete `DialogPane + Singleton<PatchPane2>` class with size `0x294`.
- Exact function hashes, modeled boundaries, raw unmodeled destructor bytes, callers, vtable slots, and literals close every direct body in the island.
- Named generated checkpoints validate the sole UID0000RZ definition and covered-by duplicate strategy. The pre-callback class/predicate/layout empty-marker state is historical; the command-16340 readback confirms the implemented class, predicate, and layout closure without resolved-target markers.
- The strongest inference chain is: loader-zero slot -> constructor publish -> ordinary/EH/scalar clears -> Singleton RTTI -> sole semantic global -> complete class/source module. No competing source shape explains all facts without duplicate emission or compiler artifacts.

## IDA MCP Facts

### Exact bytes and PE data

- `get_bytes(0x0069ba20,32)` returned all zeros. `get_global_value` at `0x0069ba24/28/2c/30/34` returned zero.
- Target SHA256 is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- `.data` virtual range is VA `0x0066d000-0x0069ce24`; raw-backed data ends at VA `0x0067a800`. UID0002ZP has no raw file initializer.

### Exact code ranges and hashes

| Role | Exact range | Bytes | SHA256 |
| --- | --- | ---: | --- |
| Constructor | `0x00548690-0x00548a06` | 886 | `69D138CF1F820ADFE4178EC415CBAF36A50CD9F71E1AF7E6C4EF5334A7CF7C41` |
| Ordinary destructor | `0x00548a10-0x00548a7d` | 109 | `3F2D0F1B994BF794CAA288AD9133B88FAA4FDAC1744B4B18CD0CAD1C6DAB3139` |
| Main callback | `0x00548a80-0x00548f1a` | 1178 | `4EF4A1F098D800A36BF5BCF02F73E13E7ADA520CB6444E101BE414082C4C3B4D` |
| Predicate | `0x00548f30-0x00548f41` | 17 | `F94C60ABC26F9D52A6DCCF4ACB3F7D3CCE6F2D94910AE83BF1F1D45C6F33E972` |
| Close active file | `0x00548f50-0x00548f72` | 34 | `B9AB338E469FD67794FF8605D2B67FD454C8C4319FB427ECDDF1CE2BE175B436` |
| Finish/exit | `0x00548f80-0x0054901f` | 159 | `00E65F0B62F1122A5A0D3CE4AC4B7D3E588817A955607B709F3CE978FE25B4E8` |
| Raw advance duplicate | `0x00549020-0x00549080` | 96 | `7703FAC7F364CAED7E65DDC507F9E137FABB0FF1A610BA15861FCA49DC4EAA85` |
| Close/rename duplicate | `0x00549080-0x00549214` | 404 | `F9491D9DA47651976CC7CD853807F524E6B66E615301F6AE89A5E5B92FC43F0B` |
| Send request | `0x00549220-0x005492cf` | 175 | `33E8AFE3CC706506ECAB55A38AFCE1967AC83B8EF06A908CB2940D5CBB6D2809` |
| Report write error | `0x005492d0-0x00549339` | 105 | `138BE80BF8057E044347AB1CC2B892A66BE2305FD0726DC99D7C1D7D84CC7A5B` |
| EH singleton clear | `0x00549340-0x0054934b` | 11 | `33366BDD057245C134884D1EE6F878E48C9F2BB7EADF317CFB6DEA9210B9AE7E` |
| Adjustor thunks | `0x0054934b-0x00549361` | 22 | `F8E99D5CD9C2ABE99CAAA9D773F9B096F8EB799DA18899867209D5B4509DA08D` |
| Scalar wrapper | `0x00549370-0x0054940f` | 159 | `01AB752D3E7FFFDDF1F07F099FA53D1F7DC55F76D93370A74968216A2EC98A17` |

### Vtable, RTTI, string, and negative facts

- PatchPane2 primary/secondary/tertiary vtable bases are `0x00621f40`, `0x00621fa0`, and `0x00621fd0`; predicate/main slots are `0x00621fb4/0x00621fb8`.
- RTTI lists PatchPane2, DialogPane, inherited Pane/GrafPort/LObject/EventHandler/TimerHandler chain, and direct Singleton<PatchPane2>; Singleton PMD is `{0x26c,-1,0}`.
- Decoded literals include `L"OK"` at `0x00613a18`, `L"Cancel"` at `0x00614cbc`, `L"Ready"` at `0x00621e7c`, `L"Patcher.exe"` at `0x00621f04`, `L"Patcher.exe.new"` at `0x00621fd8`, `L"%d/%d/%s"` at `0x00621ff8`, and `L"Error writing %s"` at `0x0062200c`.
- Constructor has one code caller at `0x004f7432`; predicate/main are vtable-only; send has constructor plus three main-loop callers; report has two main-loop callers; EH clear has one unwind xref; raw advance and close/rename duplicate have no entry xrefs.

## Function / Child Inventory

| Range / item | UID / path | Role | Reconstructable | Direct parent | Recommended score | Status |
| --- | --- | --- | --- | --- | ---: | --- |
| `0x00548690-0x00548a06` | UID0004VS / `PatchPane2Constructor` | constructor | true | UID0000AA | `92/94` | validator-issued; Destination 4 |
| `0x00548a10-0x00548a7d` | UID0004VT / `PatchPane2Destructor` | ordinary destructor | true | UID0000AA | `92/94` | validator-issued; Destination 5 |
| `0x00548a80-0x00548f1a` | UID0001EV | work-event main callback | true | UID0000AA | `92/94` | revise body; Destination 6 |
| `0x00548f30-0x00548f41` | UID0001EW | event predicate | true | UID0000AA | `92/94` | add body; Destination 7 |
| `0x00548f50-0x00548f72` | UID0004VU / `PatchPane2ClosePatchFile` | source helper | true | UID0000AA | `92/94` | validator-issued; Destination 8 |
| `0x00548f80-0x0054901f` | UID0004VV / `PatchPane2FinishAndExit` | source helper | true | UID0000AA | `92/94` | validator-issued; Destination 9 |
| `0x00549020-0x00549080` | UID0002R7 | no-entry duplicate of main case 3 | true/covered | UID0000AA | `90/94` | preserve comment; Destination 10 |
| `0x00549080-0x00549214` | UID0001EX | no-caller duplicate of main case 2 | true/covered | UID0000AA | `92/94` | preserve comment; Destination 11 |
| `0x00549220-0x005492cf` | UID0001EY | send next HTTP request | true | UID0000AA | `92/94` | preserve body; Destination 12 |
| `0x005492d0-0x00549339` | UID0004VW / `PatchPane2ReportWriteError` | source helper | true | UID0000AA | `92/94` | validator-issued; Destination 13 |
| `0x00549340-0x0054934b` | UID0001EZ | constructor-EH clear | false | NONE | `92/94` | blank formal, prose sync |
| `0x0054934b-0x00549361` | UID0001F0 | compiler adjustors | false | NONE | `92/94` | blank formal, prose sync |
| `0x00549370-0x0054940f` | UID0004VX / `PatchPane2ScalarDeletingDestructor` | compiler wrapper | false | NONE | `92/94` | validator-issued; Destination 14 |
| `0x00621f40-0x00621fd8` | UID0002OJ | compiler vtables/RTTI-adjacent data | false | UID0000AA context | `92/94` | blank formal; Destination 16 |
| `0x0069ba2c-0x0069ba30` | UID0002ZP | physical global backing | false | UID0000RZ | `92/94` | blank formal; Destination 1 |
| `0x005470b0-0x0054940f` | UID0001EQ | family split/index aggregate | false | UID0000MH | `92/94` | blank formal; Destination 17 |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x005486f4` | ctor -> `0x0069ba2c` | publishes live `this` through Singleton lowering |
| `0x005486fb` | ctor -> `0x0069ba2c` | constructor fallback/initialization clear |
| `0x00548a6d` | raw ordinary destructor -> slot | clears singleton during ordinary teardown |
| `0x00549340` | ctor EH helper -> slot | unwind-only clear |
| `0x005493d0` | scalar wrapper -> slot | destructor-path clear before optional delete |
| `0x004f7432` | MainMenu patch decision -> constructor | sole object-construction caller; packed input layout authority |
| `0x00621fb4` | vtable -> predicate | expected virtual-only reachability |
| `0x00621fb8` | vtable -> main callback | expected virtual-only reachability |
| ctor + `0x00548c71/9b/c1` | callers -> send | first request plus retry/advance requests |
| `0x00548b16/0x00548bc7` | main -> report | open/write failures |
| three main sites + report/raw | callers -> finish | terminal success/failure/worker-error routes |
| none at `0x00549020` | no modeled/pointer/branch entry | duplicate raw body, not a standalone source method |
| none at `0x00549080` | modeled but no callers | retained duplicate out-of-line copy |
| none at `0x0069ba30` | filler | proves target end and rejects eight-byte target |

## Documentation Evidence And IDA Status

- Current target/global/class/file/layout/aggregate and method pages preserve substantial historical evidence. The stale blockers are limited to physical-emitter status, blank class/predicate/layout, six missing exact children, fake control field, companion-file uncertainty, and incomplete compiler/no-code classification.
- Historical report-only checkpoint command `16248` recorded one semantic global, existing main/send/covered comments, and then-empty class/predicate/layout markers; command `16223` is an earlier historical epoch. Callback refresh `16297` superseded those states for B005 implementation proof, and later external commands `16317` and `16340` are separately labeled evidence-time readbacks rather than indefinite authority.
- Historical tracker command `16265` recorded report-only queue context and command `16227` is earlier still. Callback command `16297`, external commands `16315/16339`, and the later observed deferred command `16343` are named evidence epochs; B005 never edited tracker content directly.
- Earlier manual-root observations by-memory `5C6C89F1...93FFB8`, by-global `E163655B...9C584C`, by-class `F2BCF2B8...2F9E4D`, by-file `A64A0250...82504`, by-struct `676BAA47...CB8F`, and ignored ledger `FDBCEED0...43F6`, plus the later `75E9FB13/259FE974/2C7954D8/2E3B0FF3/444B3337` set, are explicitly historical evidence-time snapshots. At those pre-application epochs the 14 replacement rows were present and six insertion rows absent. Supervisor commands `16351-16355` subsequently applied the exact union; the durable post-application assertion is row-specific because unrelated supervisor coverage can continue changing whole-file hashes.

## Ranked Ownership Analysis

### 1. UID0000RZ semantic global under UID0000MH PatchPane

- Evidence for: exact pointer lifecycle; current ordinary sole-definition documentation; file-owned emitter; constructor/destructor/EH/scalar routes; generated one-definition behavior at named command epochs; contiguous PatchPane2 source island.
- Evidence against: none material. Private name is inferred but strongly conventional and already current.
- Decision: accepted. UID0002ZP remains its physical backing, not another emitter.

### 2. UID0000AA PatchPane2 class for source-bearing methods

- Evidence for: RTTI/vtables, all object-relative field uses, class-specific literals, source helper fan-in, MainMenu construction, and existing class/file family.
- Evidence against: callback interfaces and private names are not symbol-recovered.
- Decision: accepted with source-facing inferred names and behavior-exact bodies; lexical uncertainty caps confidence at 94.

### 3. Rejected mixed aggregate, generic application owner, or companion module

- Evidence for: only address adjacency or historical migration speculation.
- Evidence against: B001 predecessor has independent type/lifecycle; filler separates successor; all target refs are PatchPane2 lifecycle; no companion path/string/build clue exists; current generator uses one module.
- Decision: rejected. Preserve historical aggregate/companion statements only as superseded assumptions.

### Proposed new file/grouping, if applicable

- No new source file. Existing owner is UID0000MH `NexusTK/patch/PatchPane.cpp`.
- Six new exact by-memory children are documentation splits inside the existing source family, not new source modules.
- UID0002ZO and the power-dialog successor are excluded from ownership despite adjacency.

## Source Placement

- Recommended source: global definition, complete class declaration, constructor/destructor, main/predicate/close/finish/send/report bodies all route through UID0000MH `NexusTK/patch/PatchPane.cpp` and its corresponding header/class declaration context.
- The contiguous code island, vtables/read-only literals, common MainMenu patch-decision caller, existing generator route, and shared patch globals support one module.
- Rejected: `Application.cpp` (consumer/lifecycle only), `MiscWorkThread.cpp` (download transport callee only), `DialogPane.cpp` (base APIs only), `StringBase.cpp` (concatenation callee only), and speculative `PatchPane2.cpp` (no artifact proof).
- No source-placement uncertainty remains that affects owner/emitter or code generation.

## Range / Split / Padding / Reclassification Analysis

- Global neighborhood: UID0002ZO ends exactly at `0x0069ba2c`; UID0002ZP is four bytes; `[0x0069ba30,0x0069ba34)` is zero-reference filler; power-dialog singleton begins at `0x0069ba34`. UID0002A0's former eight-byte mixed view remains historical split evidence only.
- Code island padding/data: ctor ends `0x548a06`, alignment to destructor at `0x548a10`; destructor ends `0x548a7d`, three `0xcc` bytes to main; main ends `0x548f1a`, two-byte alignment plus switch table `[0x548f1c,0x548f30)`; predicate ends `0x548f41`, alignment to close at `0x548f50`; finish ends `0x54901f`, one-byte alignment; close/rename ends `0x549214`, alignment to send at `0x549220`; report ends `0x549339`, alignment to EH clear; adjustors end `0x549361`, alignment to scalar at `0x549370`; scalar ends `0x54940f`, one-byte boundary before ImageLoaders at `0x549410`.
- Six new children were created in address order, one validator registration at a time, as UID0004VS/0004VT/0004VU/0004VV/0004VW/0004VX. Each uses `Nested:0`; the existing aggregate's cumulative nesting is preserved rather than treating Nested as a child count.
- UID0002ZP, UID0002OJ, scalar wrapper, and aggregate become/remain false/non-emitting with blank formals. Layout is absorbed by the class and receives a covered-by no-duplicate declaration comment. Raw/rename duplicates retain covered-by comments.
- Parent UID0001EQ remains exact `[0x005470b0,0x0054940f)` and does not absorb the ImageLoaders-owned `0x00549410` successor.

## Negative Evidence Summary

- No raw initializer supports `0xffffffff`; no source should encode that historical value.
- No evidence supports an eight-byte Parcel/Patch aggregate, a target extending into filler, or target ownership of B001 UID0002ZO.
- No sixth target xref, non-lifecycle consumer, indirect pointer table, or independent storage owner exists.
- No independent PatchPane2 field exists at `+0x1fc`; adding `m_statusControls` would conflict with inherited DialogPane layout.
- No function model at ordinary destructor or raw advance start is insufficient by itself; exact body/lifecycle evidence distinguishes source destructor from covered duplicate.
- No callers to close/rename duplicate, combined with exact inline parity, rejects active standalone emission.
- No project evidence supports explicit source vptr writes, global clear/publish, deleting flags, guard state, EH helper, adjustor thunk, or vtable data.
- No third-party source, static import, IDA mutation, or legacy Wave2/Wave3 ownership route applies.

## IDA Rename / Type / Comment Recommendations

- Source-facing method names: `PatchPane2::PatchPane2`, `~PatchPane2`, `AcceptsDownloadWorkEvent`, `HandleDownloadWorkEvent`, `ClosePatchFile`, `FinishAndExit`, `SendDownloadRequest`, and `ReportWriteError`.
- Source-facing fields: `m_finalPatchPath`, `m_tempPatchPath`, `m_patchFileNames`, `m_currentDownloadIndex`, `m_activePatchFile`, `m_downloadPassCount`, `m_patchVersionMajor`, and `m_patchVersionMinor`.
- Source-facing event fields: `WorkThreadNotification::m_type`, `m_channel`, `m_payload`; exact constant spellings `kWorkThreadNotification` and `kHttpNotification` are descriptive source inferences.
- Preserve exact comments for raw advance and close/rename as covered duplicates. Use no `sub_*`, `dword_*`, raw offsets, PMD terms, or decompiler labels in final source.
- No IDA rename/type/comment mutation is requested or permitted in this phase. Recommendations apply only to documentation/source reconstruction after supervisor acceptance.

## First-Draft C++ Recommendation

- Exactly 17 accepted destination blocks follow. They are the only applied source/formal changes; prose descriptions elsewhere are evidence and disposition, not substitute C++.
- Destinations 1, 14, 16, and 17 are intentionally blank exact no-code blocks. Destination 15 is a no-duplicate declaration marker. Destinations 10 and 11 preserve existing covered-by comments.
- No third-party import directive applies.

### Destination 1 - `by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: UID0002ZP is loader-created physical backing for the semantic UID0000RZ definition. Emitting any comment/declaration from this page would preserve a redundant address-level emitter and weaken the one-definition route.

### Destination 2 - `by-global/g_pPatchPane2.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PatchPane2 *g_pPatchPane2 = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - `by-class/PatchPane2.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WorkThreadNotification;

class PatchPane2 : public DialogPane, public Singleton<PatchPane2> {
public:
    explicit PatchPane2(const unsigned char *patchInfo);
    virtual ~PatchPane2();

    virtual bool AcceptsDownloadWorkEvent(const WorkThreadNotification *event);
    virtual bool HandleDownloadWorkEvent(const WorkThreadNotification *event);

private:
    void ClosePatchFile();
    void FinishAndExit(const wchar_t *message);
    void SendDownloadRequest();
    void ReportWriteError(const wchar_t *path);

    StringBase<wchar_t> m_finalPatchPath;
    StringBase<wchar_t> m_tempPatchPath;
    std::vector<StringBase<wchar_t> > m_patchFileNames;
    unsigned int m_currentDownloadIndex;
    FILE *m_activePatchFile;
    unsigned int m_downloadPassCount;
    unsigned int m_patchVersionMajor;
    unsigned int m_patchVersionMinor;
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - new `by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PatchPane2::PatchPane2(const unsigned char *patchInfo)
    : DialogPane(L"", static_cast<unsigned short>(-1), 1),
      Singleton<PatchPane2>(),
      m_currentDownloadIndex(0),
      m_activePatchFile(0),
      m_downloadPassCount(0),
      m_patchVersionMajor(patchInfo[0] | (patchInfo[1] << 8)),
      m_patchVersionMinor(patchInfo[2] | (patchInfo[3] << 8))
{
    const int width = 200;
    const int height = 100;
    const int left = (g_pScreenPane->GetScreenWidth() - width) / 2;
    const int top = (g_pScreenPane->GetScreenHeight() - height) / 2;

    RectBounds dialogBounds;
    InitRectBounds(&dialogBounds, left, top, left + width, top + height);

    RectBounds controlBounds;
    InitRectBounds(&controlBounds,
                   width / 4,
                   10,
                   width * 3 / 4,
                   height / 4);
    AddControl(new StaticTextControlPane(
        L"Ready", false, 128, 143, &controlBounds, false, false));

    InitRectBounds(&controlBounds,
                   10,
                   height / 4 + 10,
                   width - 10,
                   height * 3 / 4 - 15);
    AddControl(new StaticTextControlPane(
        L"0", false, 128, 143, &controlBounds, false, false));

    InitRectBounds(&controlBounds,
                   width / 4,
                   height * 3 / 4 - 5,
                   width * 3 / 4,
                   height - 10);
    AddControl(new TextButtonControlPane(L"Cancel", &controlBounds));

    OnCreate(&dialogBounds, 0, 0, g_pStatusPaneLayer);
    OnShow(0, 0);

    const unsigned int fileCount = patchInfo[4];
    for (unsigned int index = 0; index < fileCount; ++index) {
        const char *fileName =
            reinterpret_cast<const char *>(patchInfo + 5 + index * 256);
        m_patchFileNames.push_back(StringBase<wchar_t>(fileName));
    }

    m_finalPatchPath = L"Patcher.exe";
    StringBase<char> oldPath(m_finalPatchPath);
    _unlink(oldPath.c_str());
    m_tempPatchPath = L"Patcher.exe.new";
    SendDownloadRequest();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - new `by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PatchPane2::~PatchPane2()
{
    ClosePatchFile();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)
{
    if (event->m_channel != kHttpNotification)
        return false;

    const httpget::Notification *notification =
        static_cast<const httpget::Notification *>(event->m_payload);

    switch (notification->m_state) {
    case httpget::Started:
    {
        m_activePatchFile = _wfopen(m_tempPatchPath.c_str(), L"wb");
        if (m_activePatchFile == 0)
            ReportWriteError(m_tempPatchPath.c_str());

        GetChild<StaticTextControlPane>(0)->SetText(m_finalPatchPath.c_str());

        StringBase<wchar_t> byteCount;
        byteCount.FormatWide(L"0", ftell(m_activePatchFile));
        GetChild<StaticTextControlPane>(1)->SetText(byteCount.c_str());
        return true;
    }

    case httpget::DataChunk:
    {
        const _AUTOBUF<unsigned char> *chunk =
            static_cast<const _AUTOBUF<unsigned char> *>(notification->m_payload);

        if (fwrite(chunk->data(), 1, chunk->size(), m_activePatchFile) != chunk->size())
            ReportWriteError(m_tempPatchPath.c_str());

        StringBase<wchar_t> byteCount;
        byteCount.FormatWide(L"%d", ftell(m_activePatchFile));
        GetChild<StaticTextControlPane>(1)->SetText(byteCount.c_str());
        return true;
    }

    case httpget::Completed:
    {
        FILE *file = m_activePatchFile;
        const int closeResult = fclose(file);
        m_activePatchFile = 0;
        if (closeResult == EOF)
            throw Win32Error();

        StringBase<char> finalPath(m_finalPatchPath);
        _unlink(finalPath.c_str());

        StringBase<char> renameTarget(m_finalPatchPath);
        StringBase<char> renameSource(m_tempPatchPath);
        if (rename(renameSource.c_str(), renameTarget.c_str()) != 0 && errno != ENOENT)
            throw Win32Error();

        SHELLEXECUTEINFOA executeInfo = {};
        executeInfo.cbSize = sizeof(executeInfo);
        executeInfo.lpVerb = "runas";
        executeInfo.lpFile = "patcher.exe";
        executeInfo.lpParameters = Locale;
        executeInfo.nShow = SW_SHOWNORMAL;
        ShellExecuteExA(&executeInfo);

        FinishAndExit(GetLanguageText(174));
        return true;
    }

    case httpget::ReadOrOpenUrlFailed:
        ClosePatchFile();

        if (m_currentDownloadIndex < m_patchFileNames.size() - 1) {
            ++m_currentDownloadIndex;
            SendDownloadRequest();
            return true;
        }

        if (m_downloadPassCount >= 10)
            FinishAndExit(GetLanguageText(157));
        else {
            m_currentDownloadIndex = 0;
            ++m_downloadPassCount;
        }

        SendDownloadRequest();
        return true;

    case httpget::InternetOpenFailed:
    {
        ClosePatchFile();

        wchar_t message[1024];
        const Error *error = static_cast<const Error *>(notification->m_payload);
        error->FormatErrorMessage(message, 1024);
        FinishAndExit(message);
        return true;
    }

    default:
        return true;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - `by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PatchPane2::AcceptsDownloadWorkEvent(const WorkThreadNotification *event)
{
    return event->m_type == kWorkThreadNotification;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 8 - new `by-memory/0x00548f50-0x00548f72.PatchPane2ClosePatchFile.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PatchPane2::ClosePatchFile()
{
    if (m_activePatchFile != 0) {
        FILE *file = m_activePatchFile;
        m_activePatchFile = 0;
        fclose(file);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 9 - new `by-memory/0x00548f80-0x0054901f.PatchPane2FinishAndExit.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PatchPane2::FinishAndExit(const wchar_t *message)
{
    if (message != 0)
        new AlertPane(message, g_pMainMenuPane, L"OK", 0);

    Sleep(1000);
    CloseDialog();
    g_pMainMenuPane->MarkForDeletion();
    g_pApplication->RequestExit();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 10 - `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The source-level download index/pass advance behavior is emitted in [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) PatchPane2::HandleDownloadWorkEvent; this raw no-entry duplicate is not emitted separately.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 11 - `by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The source-level close/delete/rename behavior is emitted inline in [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) PatchPane2::HandleDownloadWorkEvent; this no-caller duplicate helper is retained as binary evidence and is not emitted separately.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 12 - `by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PatchPane2::SendDownloadRequest()
{
    StringBase<wchar_t> requestSuffix;
    requestSuffix.FormatWide(L"%d/%d/%s",
                             m_patchVersionMajor,
                             m_patchVersionMinor,
                             m_finalPatchPath.c_str());

    const StringBase<wchar_t> requestPath =
        m_patchFileNames[m_currentDownloadIndex] + requestSuffix;

    g_pMiscWorkThread->RequestHTTPGet(requestPath.c_str());
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 13 - new `by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PatchPane2::ReportWriteError(const wchar_t *path)
{
    StringBase<wchar_t> message;
    message.FormatWide(L"Error writing %s", path);
    FinishAndExit(message.c_str());
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 14 - new `by-memory/0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: the range is a compiler scalar-deleting wrapper around the ordinary virtual destructor plus conditional operator delete. The class virtual destructor generates it; handwritten flags/delete logic would duplicate ABI lowering.

### Destination 15 - `by-type/by-struct/PatchPane2Layout.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// PatchPane2 field declarations are emitted by [UID:0000AA][PatchPane2](by-class/PatchPane2.md); this layout evidence page has no duplicate standalone type declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 16 - `by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: all bytes are compiler-generated vtable/RTTI products of Destination 3 and virtual definitions. The current covered-by prose emitter should be replaced by false/non-emitting blank metadata, not emitted static data.

### Destination 17 - `by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

No-code proof: UID0001EQ is a split/index aggregate. Exact child pages own every source-bearing body; aggregate emission would duplicate them.

## Final Recommendation

- Destinations 1-17 are applied exactly. The six exact children were registered serially with validator-issued UIDs; no UID was guessed and no placeholder was cross-linked.
- UID0002ZP, UID0004VX, UID0002OJ, and UID0001EQ are blank/non-emitting as specified. UID0001EZ/UID0001F0 remain blank/compiler-only, and UID0002R7/UID0001EX remain covered duplicates.
- Semantic UID0000RZ remains the sole global source definition. Class/layout and source bodies are complete through UID0000MH PatchPane.cpp.
- Leave B001 UID0002ZO and the power-dialog successor unchanged. Their facts are boundary evidence only.
- No target source body remains deferred. Remaining uncertainty is limited to original private lexical spellings and does not affect the applied source.

## Recommended Target Doc Changes

- Path: `by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md`.
- Applied completion/confidence `92/94` while preserving UID, exact path/title/range, canonical owner UID0000RZ, blank position, and `Nested:0`.
- Applied false reconstruction, cleared emitter UID0000RZ, and replaced the covered-by comment with exact blank Destination 1.
- Exact Item Summary: `Exact loader-zeroed four-byte physical backing for semantic global g_pPatchPane2: PE virtual-tail mapping, four zero bytes, five constructor/ordinary-destructor/EH/scalar-wrapper lifecycle refs, PatchPane2 pointer type, exact ParcelPane/filler/power-dialog boundaries, sole source definition through UID0000RZ, blank non-emitting formal, and superseded historical 0xffffffff initializer are all resolved.`
- Full PE mapping, target hash, five-xref classification, pointer/one-definition proof, exact boundaries, negative checks, and historical all-ones rejection are applied while every valid prior lifecycle fact and B001 predecessor link is preserved.

## Recommended Support Doc Changes

| Destination | Exact applied change |
| --- | --- |
| `by-global/g_pPatchPane2.md` | Raise `88/91 -> 92/94`, retain owner/emitter UID0000MH and true, set position `10`, preserve Destination 2, and add loader-zero/sole-definition/lifecycle/B001-boundary proof. |
| `by-class/PatchPane2.md` | Raise `87/88 -> 92/94`, retain owner/emitter UID0000MH and true, set position `20`, replace blank class with Destination 3, add complete inheritance/layout/method/duplicate/compiler history. |
| `by-file/PatchPane.md` | Raise `90/89 -> 92/94`; preserve route/path and all PatchPane/PatchFile content; add exact PatchPane2 global/class/child/source order and reject companion split as superseded. No by-file formal block. |
| `by-type/by-struct/PatchPane2Layout.md` | Raise `86/89 -> 92/94`, retain class owner/emitter, apply Destination 15, add exact size/offset/type/consumer/Singleton-EBO proof. |
| `by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md` | Raise `87/91 -> 92/94`, remain false/blank, apply Destination 17, replace future child gaps with real issued UIDs, preserve complete PatchPane half and ImageLoaders exclusion. |
| New constructor page | Create exact `[0x00548690,0x00548a06)`, `92/94`, owner/emitter UID0000AA, true, position `30`, `Nested:0`, Destination 4, exact Item Summary and full evidence. |
| New ordinary destructor page | Create exact `[0x00548a10,0x00548a7d)`, `92/94`, owner/emitter UID0000AA, true, position `40`, `Nested:0`, Destination 5, exact raw-liveness/vtable/member/base/global-clear proof. |
| UID0001EV main | Raise `90/91 -> 92/94`, retain owner/emitter/class/range/true, position `50`, apply Destination 6, replace active fake control field with inherited GetChild route while historicalizing it. |
| UID0001EW predicate | Raise `86/91 -> 92/94`, retain owner/emitter/class/range/true, position `60`, apply Destination 7, resolve type-byte versus HTTP-channel distinction. |
| New close page | Create exact `[0x00548f50,0x00548f72)`, `92/94`, owner/emitter UID0000AA, true, position `70`, `Nested:0`, Destination 8. |
| New finish page | Create exact `[0x00548f80,0x0054901f)`, `92/94`, owner/emitter UID0000AA, true, position `80`, `Nested:0`, Destination 9. |
| UID0002R7 raw advance | Raise `85/88 -> 90/94`, preserve true/class ownership, set position `90`, preserve Destination 10 and exact no-entry/duplicate evidence; remove unresolved-future wording. |
| UID0001EX close/rename | Raise `88/91 -> 92/94`, preserve true/class ownership, set position `100`, preserve Destination 11 and no-caller/inline-duplicate evidence. |
| UID0001EY send | Raise `88/91 -> 92/94`, preserve true/class ownership, set position `110`, preserve Destination 12, add final class/type/caller closure. |
| New report page | Create exact `[0x005492d0,0x00549339)`, `92/94`, owner/emitter UID0000AA, true, position `120`, `Nested:0`, Destination 13. |
| UID0001EZ EH clear | Raise `88/92 -> 92/94`, preserve NONE/false/blank/formal/range, add exact ctor-unwind and ordinary/Singleton counterpart proof. |
| UID0001F0 adjustors | Raise `86/90 -> 92/94`, preserve NONE/false/blank/range, add exact two-thunk/scalar-wrapper/vtable proof. |
| New scalar wrapper page | Create exact `[0x00549370,0x0054940f)`, `92/94`, owner NONE, false, blank emitter/position/formal, `Nested:0`, Destination 14. |
| UID0002OJ vtable | Raise `88/92 -> 92/94`, change owner context to UID0000AA, false, blank emitter/position/formal, Destination 16; preserve slot/RTTI/range evidence. |

- Exact new-child Item Summaries:
  - constructor: `Source-ready PatchPane2 constructor with exact 0x376-byte range/hash, sole MainMenu caller, packed version/count/256-byte filename input, centered 200x100 Ready/count/Cancel dialog, status-layer creation, Patcher path setup, vector population, first HTTP request, and compiler-only Singleton/vptr/EH lowering excluded.`
  - destructor: `Source-ready raw ordinary PatchPane2 destructor with exact 0x6d-byte range/hash, vtable repair, active FILE close, vector/string teardown, Singleton global clear, base destruction, scalar-wrapper/EH parity, and no reliance on an IDA function object.`
  - close: `Source-ready PatchPane2::ClosePatchFile helper with exact 0x22-byte range/hash and main/destructor callers; closes and clears the active FILE pointer without compiler scaffolding.`
  - finish: `Source-ready PatchPane2::FinishAndExit helper with exact 0x9f-byte range/hash, optional OK alert, one-second delay, dialog close, MainMenu deletion, Application exit request, and five exact caller routes.`
  - report: `Source-ready PatchPane2::ReportWriteError helper with exact 0x69-byte range/hash, two main-loop callers, Error writing %s formatting, and FinishAndExit forwarding.`
  - scalar: `Compiler-only PatchPane2 scalar deleting destructor wrapper with exact 0x9f-byte range/hash, vtable/adjustor routes, ordinary teardown, conditional delete flag, blank false/non-emitting formal, and no handwritten ABI mechanics.`
- The serial registration procedure is completed historical callback evidence. No brace token or provisional placeholder remains; real UIDs are `0004VS`, `0004VT`, `0004VU`, `0004VV`, `0004VW`, and `0004VX`.

## Score And Metadata Recommendation

| Page | Before callback | Applied | Metadata/formal disposition |
| --- | ---: | ---: | --- |
| UID0002ZP | `86/90` | `92/94` | owner UID0000RZ retained; true/emitter/comment -> false/blank |
| UID0000RZ | `88/91` | `92/94` | file owner/emitter retained; position 10; sole definition retained |
| UID0000AA | `87/88` | `92/94` | file owner/emitter retained; position 20; complete class |
| UID0000MH | `90/89` | `92/94` | path/owner retained; source inventory resolved |
| UID0001VJ | `86/89` | `92/94` | class owner/emitter retained; covered-by class declaration |
| UID0001EQ | `87/91` | `92/94` | false/blank retained; complete split inventory |
| UID0001EV | `90/91` | `92/94` | class owner/emitter/true retained; body corrected |
| UID0001EW | `86/91` | `92/94` | class owner/emitter/true retained; body added |
| UID0002R7 | `85/88` | `90/94` | true/class covered duplicate retained |
| UID0001EX | `88/91` | `92/94` | true/class covered duplicate retained |
| UID0001EY | `88/91` | `92/94` | true/class body retained |
| UID0001EZ | `88/92` | `92/94` | NONE/false/blank retained |
| UID0001F0 | `86/90` | `92/94` | NONE/false/blank retained |
| UID0002OJ | `88/92` | `92/94` | change to class context, false, blank |
| Six new children | absent | as listed | serial registration; exact ranges/roles |

- Score blockers removed: raw-versus-virtual initialization; physical/semantic duplicate; pointer type/name; inheritance; object size/layout/container; inherited controls; constructor input/UI; raw ordinary destructor; predicate ABI/role; direct close/finish/report bodies; raw duplicate liveness; no-caller duplicate disposition; compiler/EH/vtable policy; source route; exact child/range inventory; historical assumptions.
- Completion stops at 92 rather than 100 because exact original private lexical names, enum labels, and include/header organization are unavailable. Confidence stops at 94 because those lexical choices remain inferred despite behavior/layout certainty.
- No support score is raised without a destination-specific implementation-ready correction. UID0002R7 remains 90 completion because it is retained binary evidence without independent source emission.

## Open Questions With Attempted Resolution

- **Was the initializer `0xffffffff`?** No. Fresh bytes and PE mapping prove loader zero-fill with no raw initializer. Historical language is superseded.
- **Is UID0002ZP source-bearing?** No. Semantic UID0000RZ already emits the one definition; physical storage is false/non-emitting.
- **Is the target part of an eight-byte singleton pair?** Physically adjacent historically, but not one source declaration. Independent types/lifecycles and exact split pages resolve it.
- **Does PatchPane2 directly inherit callback bases?** RTTI places EventHandler/TimerHandler through DialogPane and Singleton directly at `+0x26c`; only DialogPane and Singleton are direct declarations.
- **What occupies `+0x26c-+0x294`?** Fully resolved typed fields; no reserved/unknown byte arrays are needed.
- **What is the callback predicate signature?** Paired vtable/interface evidence supports the virtual member taking `const WorkThreadNotification *`; its test is event type 22, distinct from main's HTTP channel test.
- **Are raw `0x549020` or modeled `0x549080` active methods?** No. Exhaustive entry checks plus exact inline parity prove covered duplicate dispositions.
- **Is the ordinary destructor source despite no IDA function?** Yes. Raw teardown sequence, scalar wrapper, vtables, and ctor-EH parity prove it.
- **Separate PatchPane2.cpp?** No current evidence. The one-module route is stronger and source-complete.
- **Unresolved items:** only original private lexical spellings/constant identifiers. The selected source-facing names are role-specific, compile-legal, and do not alter score/C++ behavior. No unavailable evidence route would change owner, range, type, layout, or source/no-code disposition.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-application root snapshots include by-memory `70752950...8A352`, by-global `E163655B...C584C`, by-class `FD57AEA8...395B7`, by-file `F24B1741...54272`, and by-struct `2E3B0FF3...F67D4`. They are evidence-time observations only and are superseded for post-application proof.
- Supervisor application/validation commands were by-memory `16351`, by-global `16352`, by-class `16353`, by-file `16354`, and by-type/by-struct `16355`, each exit `0` / `ok:1`. Command-scoped post-application evidence-time snapshots are: by-memory SHA `696733A30A8B9E91BD1FB15710B478A03A5611FD8603C3CCF59DD459524F3242` (`1,953,587` bytes / `4,527` lines); by-global `D06DB9D9F400C32437AD77D6D56B8613D39968917F5B1F3F2730B947D8549199` (`98,177 / 217`); by-class `1BEAB11B2AA92B638951A2F06491149D9D5A9293B069EBDE38877E866032D5D8` (`252,152 / 623`); by-file `0027712B1BE942674FE0F530CE1FB8C0A7993EF27C2F3D94656A512E09370AD4` (`149,851 / 317`); by-struct `6D2AF85D500B2E461B179FF7E2D4BA7B4D9D962BE790CAF7DFBC002EC39A2080` (`57,690 / 137`). These whole-file hashes are named evidence epochs, not permanent current-state locks.
- Row-specific post-application readback confirms every M01-M20 UID occurs exactly once in its relevant manual root and the applied row text preserves the exact no-loss handoff. This row-level result is the durable current-state assertion; future unrelated coverage must be rebased without dropping it.
- Exact 20-action handoff follows as preserved implementation history. The supervisor applied these actions under commands `16351-16355`; the text is retained verbatim for independent review and future no-loss rebasing.

### M01 - replace UID0002ZP in `by-memory/-coverage-report.md`

`        - [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md) 0x0069ba2c-0x0069ba30 | physical singleton backing | g_pPatchPane2 : not_reconstructable : 92% : very-strong : Exact loader-zeroed four-byte physical backing for semantic global g_pPatchPane2 with four zero bytes, five constructor/ordinary-destructor/EH/scalar-wrapper lifecycle refs, PatchPane2 pointer type, exact ParcelPane/filler/power-dialog boundaries, sole source definition through UID0000RZ, blank non-emitting formal, and superseded historical 0xffffffff initializer.`

### M02 - replace UID0000RZ in `by-global/-coverage-report.md`

`- [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md) : reconstructable : 92% : very-strong : Sole externally linked PatchPane2 pointer definition in PatchPane.cpp; exact loader-zero physical child UID0002ZP, five constructor/ordinary-destructor/EH/scalar-wrapper lifecycle refs, direct Singleton<PatchPane2> route, exact adjacent boundaries, one-definition/no-duplicate policy, and historical 0xffffffff rejection are complete.`

### M03 - replace UID0000AA in `by-class/-coverage-report.md`

`- [UID:0000AA][PatchPane2](by-class/PatchPane2.md) : reconstructable : 92% : very-strong : Complete DialogPane plus Singleton<PatchPane2> class surface and 0x294 layout with two path strings, filename vector, index/FILE/pass/version fields, source-ready constructor/destructor/main/predicate/close/finish/send/report methods, covered raw/rename duplicates, compiler-only EH/adjustor/scalar/vtable evidence, semantic singleton definition, and single PatchPane.cpp source route.`

### M04 - replace UID0000MH in `by-file/-coverage-report.md`

`- [UID:0000MH][PatchPane](by-file/PatchPane.md) : reconstructable : 92% : very-strong : Complete PatchPane/PatchPane2 patch-update module route in NexusTK/patch/PatchPane.cpp, preserving all PatchPane/PatchFile content while adding sole g_pPatchPane2 definition, complete PatchPane2 class/layout and constructor/destructor/helper inventory, exact source/covered/compiler split, contiguous code/read-only/global evidence, and rejected companion-file migration assumption.`

### M05 - replace UID0001VJ in `by-type/by-struct/-coverage-report.md`

`- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) : reconstructable : 92% : very-strong : Exact 0x294 PatchPane2 layout: DialogPane plus Singleton EBO through +0x26c; final/temp StringBase paths, three-pointer vector of wide StringBase file names, index, FILE pointer, pass count, and promoted major/minor values through +0x290; constructor/main/send/destructor consumers and class-covered no-duplicate declaration are complete.`

### M06-M14 - replace existing by-memory method/data rows

`    - [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md) : not_reconstructable : 92% : very-strong : Non-emitting PatchPane/PatchPane2 split index with exact child inventory, hashes, padding/switch-table boundaries, source/covered/compiler dispositions, complete PatchPane2 constructor/destructor/helper closure, and strict exclusion of the ImageLoaders-owned 0x00549410 successor.`

`    - [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) : reconstructable : 92% : very-strong : Source-ready PatchPane2 HTTP work-event handler for Started/DataChunk/Completed/read-open-failure/InternetOpenFailure states, exact vtable-only route and range/hash, inherited GetChild status-control access, file/vector/retry/version state, close/rename/launch/error behavior, and switch-table/padding proof.`

`    - [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md) : reconstructable : 92% : very-strong : Source-ready virtual PatchPane2::AcceptsDownloadWorkEvent predicate with exact seven-instruction 0x11-byte body, event type byte +4 equals 0x16, paired main callback HTTP-channel distinction, sole vtable slot, no direct callers/callees, and exact surrounding switch-table/alignment boundaries.`

`    - [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) : reconstructable : 90% : very-strong : Exact raw no-function/no-xref/no-pointer/no-branch-entry duplicate of the main callback file-index/pass-advance path; complete bytes/hash/outgoing routes and covered-by main formal preserve binary evidence without a duplicate standalone source body.`

`    - [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) : reconstructable : 92% : very-strong : Exact modeled no-caller close/delete/rename duplicate with path conversions, FILE clear, Win32Error behavior, range/hash/padding proof, and canonical covered-by disposition because the main callback emits the full completed-download source path inline.`

`    - [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) : reconstructable : 92% : very-strong : Source-ready PatchPane2::SendDownloadRequest with exact range/hash, constructor plus three main callers, major/minor/final-path formatting, selected filename vector concatenation, StringBase helper ownership, and MiscWorkThread HTTP queue route.`

`    - [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) : ignored : 92% : very-strong : Exact 0x0b constructor-unwind Singleton cleanup with one EH xref and g_pPatchPane2 clear, ordinary/scalar teardown counterparts, blank false/non-emitting formal, and no standalone handwritten helper.`

`    - [UID:0001F0][0x0054934b-0x00549361.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md) : ignored : 92% : very-strong : Exact two compiler-generated secondary/tertiary this-adjustor thunks forwarding to the scalar deleting destructor, with vtable routes, 0x16-byte combined hash, blank false/non-emitting formal, and no handwritten ABI mechanics.`

`        - [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md) 0x00621f40-0x00621fd8 | compiler vtable data | PatchPane2VtableData : not_reconstructable : 92% : very-strong : Exact primary/secondary/tertiary PatchPane2 vtable ranges and slots, RTTI/base/adjustor/destructor/work-event routes, Patcher.exe.new successor boundary, and blank non-emitting policy because Destination 3 class/virtual declarations generate the data.`

### M15-M20 - insert new exact child rows in address order under the UID0001EQ PatchPane2 inventory

`        - [UID:0004VS][0x00548690-0x00548a06.PatchPane2Constructor](by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md) 0x00548690-0x00548a06 | constructor | PatchPane2Constructor : reconstructable : 92% : very-strong : Source-ready PatchPane2 constructor with exact range/hash, sole MainMenu caller, packed two-word/count/256-byte-name input, centered Ready/count/Cancel dialog, status-layer creation, vector/path setup, first HTTP request, and compiler-only Singleton/vptr/EH lowering excluded.`

`        - [UID:0004VT][0x00548a10-0x00548a7d.PatchPane2Destructor](by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md) 0x00548a10-0x00548a7d | ordinary destructor | PatchPane2Destructor : reconstructable : 92% : very-strong : Source-ready raw ordinary PatchPane2 destructor with exact range/hash, active FILE close, automatic vector/string/Singleton/base teardown, vtable/global-clear/scalar/EH parity, and decisive source liveness despite no IDA function object.`

`        - [UID:0004VU][0x00548f50-0x00548f72.PatchPane2ClosePatchFile](by-memory/0x00548f50-0x00548f72.PatchPane2ClosePatchFile.md) 0x00548f50-0x00548f72 | private method | PatchPane2ClosePatchFile : reconstructable : 92% : very-strong : Source-ready exact close-and-clear helper for m_activePatchFile with main/destructor callers, 0x22-byte range/hash, and no compiler scaffolding.`

`        - [UID:0004VV][0x00548f80-0x0054901f.PatchPane2FinishAndExit](by-memory/0x00548f80-0x0054901f.PatchPane2FinishAndExit.md) 0x00548f80-0x0054901f | private method | PatchPane2FinishAndExit : reconstructable : 92% : very-strong : Source-ready optional OK alert, one-second delay, dialog close, MainMenu deletion, and Application exit helper with exact range/hash, globals, literals, and five caller routes.`

`        - [UID:0004VW][0x005492d0-0x00549339.PatchPane2ReportWriteError](by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md) 0x005492d0-0x00549339 | private method | PatchPane2ReportWriteError : reconstructable : 92% : very-strong : Source-ready Error writing %s formatter and FinishAndExit forwarder with exact half-open range/hash, two main-loop callers, and corrected historical inclusive endpoint.`

`        - [UID:0004VX][0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor](by-memory/0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor.md) 0x00549370-0x0054940f | compiler scalar deleting destructor | PatchPane2ScalarDeletingDestructor : ignored : 92% : very-strong : Exact compiler wrapper around ordinary PatchPane2 teardown and conditional delete, with vtable/adjustor routes, range/hash, blank false/non-emitting formal, and no handwritten flag/delete/vptr/global-clear mechanics.`

- M15-M20 contain the real serially issued UIDs. The exact twenty-action block was supervisor-applied and externally validated and contains no tokenized row.
- No tracker text is supplied: `auto-generated/-ag-research-tracker.md` is validator-owned. Validator refreshes derive it from ordinary pages.
- B005 did not apply these rows; all `-coverage-report.md` roots remained supervisor-owned, and commands `16351-16355` record the external application.

## Follow-Up Actions

- B005 responsibilities are complete: six children were serially registered, C01-C40 and Destinations 1-17 were applied without detail loss, every ordinary page was scoped-validated/released, final command `16297` refreshed generated output, and this report was reconciled.
- UID0002ZO remains B001-owned and unchanged by B005; its current hash was reread as verify-only boundary evidence.
- The exact twenty-action manual coverage handoff remains preserved as implementation history and is now supervisor-applied/validated. Full-root hashes are command-scoped evidence-time observations; the one-row-per-UID result is the durable post-application proof.
- Independent Gate 2, report execution, movement, and archival remain external supervisor lifecycle state. Manual-row application is complete, and no pending B005 implementation task remains.

## Confidence

- Recommendation confidence: `94/100` for physical/semantic disposition and one-definition route.
- Source-family confidence: `94/100` for owner, class layout, method inventory, and PatchPane.cpp placement.
- Body confidence: `94/100` for constructor/destructor/predicate/close/finish/report and existing main/send behavior; direct machine behavior is exact, private lexical names are inferred.
- Range/padding/compiler confidence: `98/100` because bytes, function extents, vtable routes, no-entry/no-caller evidence, and compiler patterns agree.
- Remaining uncertainty: original private spellings, enum names, and include/header organization only. It does not affect applied ownership, metadata, ranges, source/no-code choices, or behavior.

## Validator Results

- Report-only Gate 1 ran no validators. After acceptance, all 20 ordinary destinations were validated serially under short leases, with all commands exit `0` / `ok:1`; validator-owned projected stats, reference-index, registry, generated metadata, and deferred-refresh side effects were not edited manually.
- Serial allocations: UID0004VS command `16273` at `19:37:34`; UID0004VT `16274` at `19:38:54`; UID0004VU `16275` at `19:40:10`; UID0004VV `16276` at `19:41:16`; UID0004VW `16277` at `19:42:26`; UID0004VX `16278` at `19:43:36` (all `2026-07-21T...-04:00`, exit `0`, `ok:1`). Each UID was substituted before the next page/cross-link.
- Existing-page validators: UID0002ZP `16281` (`19:45:03`); UID0000RZ `16282` (`19:45:44`); UID0000AA initial `16283` (`19:48:24`) exposed an invalid duplicate managed wrapper, corrected and revalidated by `16284` (`19:49:12`, error cleared); UID0000MH `16286` (`19:50:58`); UID0001VJ `16287` (`19:51:58`); UID0001EQ `16288` (`19:53:08`); UID0001EV `16289` (`19:53:54`); UID0001EW `16290` (`19:54:37`); UID0002R7 `16291` (`19:55:31`); UID0001EX `16292` (`19:56:04`); UID0001EY `16293` (`19:56:47`); UID0001EZ `16294` (`19:57:29`); UID0001F0 `16295` (`19:58:06`); UID0002OJ `16296` (`19:58:55`). Every terminal validator exited `0` / `ok:1` and its lease was immediately released.
- Final waited target validation command `000000016297`, timestamp `2026-07-21T19:59:16-04:00`, exited `0` / `ok:1` and completed generated refresh after zero ordinary leases. Its reported warnings (`children_marker_missing`, `children_fallback_insert`, `emitter_has_no_code`) are pre-existing project-wide rows; none identifies a resolved UID0002ZP destination.
- Supervisor manual validators `16351-16355` each exited `0` / `ok:1`; those commands applied the exact M01-M20 rows to the five manual roots and were not run by B005.
- Final supervisor waited target command `000000016356`, refreshed `2026-07-21T21:02:15-04:00`, exited `0` / `ok:1`. Its command-scoped PatchPane.cpp checkpoint is SHA256 `9A4853E432C564B4A07AC44DCC574D3838D63AE883CB2DF659880ABB36419470`, `15,080` bytes / `401` lines. Exact counts remain one UID0000RZ definition; one UID0000AA class; one each constructor, ordinary destructor, main, predicate, close, finish, send, and report definition; one UID0002R7 and one UID0001EX covered comment; zero UID0002ZP/UID0001EQ/UID0001EZ/UID0001F0/UID0004VX/UID0002OJ markers; zero `m_statusControls`, `dword_`, `sub_`, cookie, scalar-delete, or handwritten ABI mechanics. The only two Empty Emitter Markers belong to unrelated pre-existing UID0000A9 and UID0000AB. Commands `16297/16317/16340` and their hashes remain historical callback/evidence-time provenance.
- The same command-`16356` tracker checkpoint is SHA256 `5BE4DE7F334E25C94FE969AEBE0E645AE9A780D0A5BA5ECBAFD759661EBF636D`, `1,557,918` bytes / `6,301` lines. It preserves UID0002ZP and all six new UIDs exactly once with applied score/reconstruction states. Commands `16315/16339/16343` and earlier values remain historical evidence-time provenance; no tracker hash is permanent authority.
- Formal parity readback: Destinations 1-17 match their 17 ordinary managed BEGIN/END bodies exactly after newline normalization; all blocks are balanced, D3 has one post-class `[[CHILDREN]]`, and D1/D14/D16/D17 remain intentionally blank.
- Post-application manual readback found all 20 M01-M20 UIDs exactly once in their relevant roots and the exact handoff text applied without duplication or loss.
- Manual coverage rows remained supervisor-owned and were not edited by B005. Supervisor commands, named post-application evidence-time root snapshots, and the preserved exact twenty-action history are recorded above.

## Changed Files

- Created and then callback-reconciled artifact: `tools/leaser/Agents/Agent-B005/research/0002ZP-g_pPatchPane2-source-quality.md`.
- Ordinary callback scope: 14 existing destinations modified and six exact children created, all listed in the current table below. UID0002ZO and other dependencies remained verify-only.
- Renamed/moved files: none. Report execution: not run. No lifecycle/probe/move/archive, IDA mutation, manual coverage edit, or manual generated/tracker/state edit was performed.
- This final reconciliation edits only this report. Manual coverage commands `16351-16355` and waited command `16356` are external supervisor/validator actions, not B005 changed files or commands.
- Historical pre-callback destination baselines preserved for no-loss comparison:

| Path | Evidence-time SHA256 | Bytes / lines | Callback role |
| --- | --- | ---: | --- |
| `by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md` | `6AE27F3408441A2015F9DFBFF522CB2875BBB6445F60AF2FBD76D57BA3DBB6E8` | `8,572 / 84` | edit |
| `by-global/g_pPatchPane2.md` | `DE70A62C20782D549C519049E50F63B74FE8ED828518329DF45315BEE030184B` | `10,503 / 102` | edit |
| `by-class/PatchPane2.md` | `D60BF80DF111D24795E617A7EDBC8085144DE45A0501720EF433692D0917C12E` | `20,392 / 114` | edit |
| `by-file/PatchPane.md` | `D4D9DE76ED94845AD540D7C89C2283401E45680262685DA33826B8A2052F3993` | `23,669 / 138` | edit/no-loss rebase |
| `by-type/by-struct/PatchPane2Layout.md` | `5D33065122D885DE6227BC0E7FA945DC5AB1B0217D96568125E57F9AA290F43B` | `17,288 / 133` | edit |
| `by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md` | `CBD80E00015D427F19A09CD145990242707AC2685A4C3D844A012F04D97AD2F4` | `22,982 / 157` | edit |
| `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md` | `DAF7BC6FFA126F2F4636AF9A6751BE17ACA3F478B176CD5BE100074A0F2C1FB0` | `21,572 / 257` | edit |
| `by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md` | `06B3F7F8A7B45CFAA64455A34B9E835CD8A6DCF91F7F6AC6492D5AB5C51832B5` | `6,515 / 86` | edit |
| `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md` | `E093907CF5806B11F2F0B4BACF06A16B4D32BCF28E3DBFE52D0D97DBF6A31AF4` | `10,645 / 132` | edit prose/score only; preserve formal |
| `by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md` | `46B0482D1D6A761F3AA1EAEE2E87F33832A4E198B53F0EF8BD2422C9D2F2D7E8` | `15,943 / 139` | edit prose/score only; preserve formal |
| `by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md` | `DC1DF0B0A42246BDE981D14FED65FE7DA482D1FD0F3E53D827AD420F8AF87405` | `15,284 / 142` | edit prose/score only; preserve formal |
| `by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md` | `8DEAA14C623F634ECB8085BDABA715ECFDB74D3B9896C218B1CEA5BABB5057AD` | `6,172 / 80` | edit prose/score only; blank formal preserved |
| `by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md` | `50ABBD7ACC27C19CB8C9FBF36A264A3012D416EB010EC3EFCDB06CFE7B597775` | `4,073 / 59` | edit prose/score only; blank formal preserved |
| `by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md` | `617C7CC1EF6035588D371E18C3D0EE6B60280FA25171BE3D65DCD02A00885732` | `10,278 / 106` | edit metadata/formal/prose |
| `by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md` | `CA7057496B8C2ABBF8580BD8B8E121E9AD0BAF993931C4DA28AAA6157737B3D7` | `5,530 / 64` | verify-only historical split; no edit |

- The six paths that were absent at report time now exist under validator-issued UIDs and were registered in exact address order.

Current callback destination readback after command `16297`:

| Path | Current SHA256 | Bytes / lines | Terminal result |
| --- | --- | ---: | --- |
| `by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md` | `D1FB8382F6FD3767306DB71ABAF3EDA9F2C1EE4B48724B894F4709852D4B1A9D` | `9,097 / 89` | UID0002ZP false/blank `92/94` |
| `by-global/g_pPatchPane2.md` | `6B4D05E76E00C8A639707C2A2BFEDFFF26E7BCC8C88F397388940E9CF3A2CAEC` | `12,238 / 111` | UID0000RZ sole definition position 10 |
| `by-class/PatchPane2.md` | `F0EB62F8C85A1144DA05BB0F2D76D221FB1A977270A460C6FABFB2B8C70FDC88` | `25,202 / 160` | UID0000AA complete class position 20 |
| `by-file/PatchPane.md` | `7C709692A475692440B28D2E69B70253DE688361B605692573472894C9DAAD82` | `27,339 / 151` | UID0000MH full source-order union |
| `by-type/by-struct/PatchPane2Layout.md` | `C91F0CCA14C902606B9C9DEBC7459129F159404D2AFE9425584A1E18123DA19F` | `18,991 / 145` | UID0001VJ complete layout marker |
| `by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md` | `6463ECCD33647D7D0344AC333916A076117903E321B28DC8EF7BD40868F910A9` | `25,995 / 174` | UID0001EQ complete split index |
| `by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md` | `87DF71E551BCD809CCC593F8DB9ABB191844CDF152F78E6C831C828FAC38D61B` | `7,161 / 127` | UID0004VS source constructor |
| `by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md` | `90833013DB95EA51466653D57380A5F780A60A29129523B3FA470DA7E03C9C87` | `4,457 / 62` | UID0004VT ordinary destructor |
| `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md` | `DC13244E49C74C1FB47D9E6267515BAE21795BFA076C8837021FCC6A0473231C` | `22,617 / 264` | UID0001EV inherited GetChild body |
| `by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md` | `B625139584E296F534D8C1164DFE0EECEECC49F40A1088729D1D24A0CCF78FC8` | `7,556 / 96` | UID0001EW source predicate |
| `by-memory/0x00548f50-0x00548f72.PatchPane2ClosePatchFile.md` | `C66E51418519208AFF36709C59A95373C7882D7CEB0CB2282480B9C2202BE1D7` | `3,537 / 60` | UID0004VU source close helper |
| `by-memory/0x00548f80-0x0054901f.PatchPane2FinishAndExit.md` | `7377414101BD4703E3EE0B42C772425A76E90516876559F83B6634D192E26A14` | `3,757 / 60` | UID0004VV source finish helper |
| `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md` | `32CAF89166B7DFCD1F772EBB68587791E41AF27E0B1D4AEFA2EDD43067FF846E` | `11,791 / 139` | UID0002R7 covered duplicate |
| `by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md` | `BFA735966A04E8D6C2940C367CC46D1DE4792C41C774CB2573FB348E88BCAF7E` | `16,923 / 147` | UID0001EX covered duplicate |
| `by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md` | `F4619F2E123149F3156370BAEE482D6CCC2F18292C2F59F7608547E0BE3A9189` | `16,426 / 151` | UID0001EY source send helper |
| `by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md` | `96C3E1EC380BFE2E4A1733357ECC39F80A67133C470BEF81C2FCF6C43BBF8179` | `3,625 / 58` | UID0004VW source error helper |
| `by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md` | `3E21913EB2DDBAE257CC776A55E594E67FA96B81E8CF9D1CE0BD8BE0B7181C05` | `7,262 / 86` | UID0001EZ compiler/EH blank |
| `by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md` | `E13103C109E19FA8B70F728B9DDFD0BC1392914B886CF3E799A55F4D6E7E6EE5` | `5,298 / 65` | UID0001F0 compiler thunks blank |
| `by-memory/0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor.md` | `08C51F3B96B94DE45C71E871EDAC7A7A257C7E8D6C2ABCB88F8008FB8A88FACE` | `4,146 / 53` | UID0004VX compiler scalar blank |
| `by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md` | `30FC4F14208FB699C55C5D429644BC8CE57FDB013BE0B6AFEA8895340E261023` | `11,163 / 112` | UID0002OJ compiler vtable blank |

- Verify-only predecessor `by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md` was not edited; final readback SHA256 `A04BE87C25D3E9F46A28DC7A0D4AA7C614B5D3554238170205CE7AA8A8E773EC`, `5,952` bytes / `68` lines preserved its concurrent owner content and the UID0002ZP boundary.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] C01 exact target bytes/hash incorporated into UID0002ZP.
- [x] C02 PE virtual-tail loader-zero proof incorporated.
- [x] C03 old `0xffffffff` claim historicalized everywhere it remains relevant.
- [x] C04 exact predecessor/target/filler/power-dialog boundaries preserved without editing UID0002ZO.
- [x] C05 all five target xrefs incorporated and read back.
- [x] C06 constructor publish/fallback lifecycle incorporated.
- [x] C07 raw ordinary-destructor liveness incorporated.
- [x] C08 UID0001EZ constructor-EH-only disposition verified.
- [x] C09 scalar-wrapper compiler-only disposition applied.
- [x] C10 physical/semantic one-definition split applied.
- [x] C11 UID0000RZ sole definition and position verified.
- [x] C12 source-facing pointer type/name applied without raw labels.
- [x] C13 exact DialogPane plus Singleton inheritance applied.
- [x] C14 exact `0x294` class size/layout applied.
- [x] C15 vector type and inherited-control correction applied.
- [x] C16 constructor exact range/hash/caller recorded.
- [x] C17 packed constructor input layout recorded.
- [x] C18 constructor UI/resource/path/request behavior recorded.
- [x] C19 constructor compiler lowering excluded from source.
- [x] C20 ordinary destructor source/automatic teardown distinction applied.
- [x] C21 predicate event-type versus main HTTP-channel distinction applied.
- [x] C22 ClosePatchFile child created and applied.
- [x] C23 FinishAndExit child created and applied.
- [x] C24 ReportWriteError child created and applied.
- [x] C25 main body inherited GetChild correction applied.
- [x] C26 raw advance covered-duplicate disposition preserved.
- [x] C27 close/rename covered-duplicate disposition preserved.
- [x] C28 send helper body/caller/type closure preserved.
- [x] C29 scalar wrapper child created false/non-emitting.
- [x] C30 UID0001EZ blank no-code proof synchronized.
- [x] C31 UID0001F0 blank no-code proof synchronized.
- [x] C32 UID0002OJ false/blank compiler-vtable policy applied.
- [x] C33 UID0001EQ complete split inventory and real UIDs applied.
- [x] C34 single PatchPane.cpp source route synchronized.
- [x] C35 literal/global/caller evidence synchronized.
- [x] C36 old-report provenance and superseded facts preserved.
- [x] C37 every accepted score/metadata change applied exactly.
- [x] C38 exact 20-action manual handoff retained with real UIDs.
- [x] C39 serial registration/scoped validators/final waited refresh completed.
- [x] C40 exclusions and B001 boundary protection verified.
- [x] Destination 1 applied byte-for-byte to UID0002ZP.
- [x] Destination 2 preserved byte-for-byte on UID0000RZ.
- [x] Destination 3 complete class with post-brace `[[CHILDREN]]` applied.
- [x] Register UID0004VS first and preserve validator allocation proof before cross-linking.
- [x] Destination 4 applied to the real constructor child.
- [x] Register UID0004VT second and preserve validator allocation proof before cross-linking.
- [x] Destination 5 applied to the real ordinary-destructor child.
- [x] Destination 6 applied to UID0001EV.
- [x] Destination 7 applied to UID0001EW.
- [x] Register UID0004VU third and preserve validator allocation proof before cross-linking.
- [x] Destination 8 applied to the real close child.
- [x] Register UID0004VV fourth and preserve validator allocation proof before cross-linking.
- [x] Destination 9 applied to the real finish child.
- [x] Destinations 10 and 11 preserved exactly on covered duplicates.
- [x] Destination 12 preserved exactly on UID0001EY.
- [x] Register UID0004VW fifth and preserve validator allocation proof before cross-linking.
- [x] Destination 13 applied to the real report child.
- [x] Register UID0004VX sixth and preserve validator allocation proof before cross-linking.
- [x] Destination 14 applied as blank false/non-emitting scalar child.
- [x] Destinations 15-17 applied exactly to layout, vtable, and aggregate.
- [x] UID0000MH and every prose-only support page updated at same-or-greater detail.
- [x] Every edited ordinary page reread after lease, scoped-validated, and immediately released.
- [x] No provisional brace token remains in report or ordinary docs.
- [x] Final waited generated refresh completed after all leases clear.
- [x] Generated PatchPane.cpp satisfies all exact one-definition/body/comment/no-marker/no-ABI assertions.
- [x] Current ordinary hashes and named evidence-time generated/tracker/manual hashes plus validator command IDs recorded in callback report without treating mutable whole-file snapshots as permanent authority.
- [x] Exact supervisor-owned manual coverage handoff retained as history; supervisor application commands `16351-16355` and one-row-per-UID readback recorded without B005 editing coverage.
- [x] Third-party import confirmed not applicable.
- [x] No IDA, generated, tracker, coverage, audit, supervisor, validator-state, or lifecycle file edited manually.
- [x] No execute_report, probe, move, archive, or lifecycle command run.
- [x] All B005 leases released and zero leases confirmed.

Implementation callback pass:

- [x] Exact report accepted by supervisor for implementation.
- [x] All accepted target/support facts incorporated at report-level detail.
- [x] C01-C40 changed from proposed to legal terminal verification states with destination-specific proof.
- [x] All 17 formal destinations independently verified against accepted report blocks.
- [x] Six real validator-issued UIDs and serial registration commands/results recorded.
- [x] Historical/stale assumptions, rejected alternatives, raw-liveness, and negative evidence preserved without compression.
- [x] Open questions remain closed or are explicitly excluded with evidence-backed reason.
- [x] Scoped validator command IDs/timestamps/exits/ok/warnings/side effects recorded for every changed ordinary page.
- [x] Final generated command/header/hash/count/order assertions recorded.
- [x] Changed and verify-only paths with final SHA256/metrics recorded.
- [x] Manual coverage remains supervisor-owned; exact M01-M20 application is externally validated and retained as durable row-specific proof.
- [x] Checklist contains no checked item unless verified by final readback.
- [x] Report lifecycle wording is archive-neutral and B005 responsibilities are complete.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000016359","destination_path":"executed-b-agent-research/B005/0002ZP-g_pPatchPane2-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002ZP-g_pPatchPane2-source-quality.md","timestamp":"2026-07-21T21:24:17-04:00","uid":"0002ZP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
