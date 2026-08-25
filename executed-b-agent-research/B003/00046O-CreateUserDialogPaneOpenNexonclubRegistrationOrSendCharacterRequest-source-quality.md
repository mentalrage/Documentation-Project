** TARGET-REPORT-UID:00046O **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00046O CreateUserDialogPane Open Nexonclub Registration Or Send Character Request Source-Quality Research


## Finalized Report / Current Recommendation

- Current implementation: `0x0052e970-0x0052ea44` remains one source-authored `CreateUserDialogPane` member method at `92/94`, owner/emitter [UID:00003B], with the exact three-parameter `PlainMemberFunctionObjectT` source form from formal R0.
- Final disposition: source-authored, reconstructable, class-owned method in `NexusTK/login/CreateUserDialogPane.cpp`; no target split, no ownership change, and no IDA edit. Exact support child [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) is non-reconstructable/non-emitting compiler data.
- Callback result: C01-C20 and R0-R1 are implemented at report-level detail. Validator command `000000016646` allocated UID0004WH before dependent links; all ordinary/support documents were then scoped-validated and released.
- Confidence: very strong for the boundary, machine behavior, boolean gate, callback member type/layout, dialog construction, callback ownership/release, and source route; below final-audit certainty only for original private method/local typedef spelling and the literal text behind language id `227`.

## Supporting Research

- Historical research origin: this began as a new report-only assignment from `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- The exact tracker checkpoint read during this pass is validator command `000000016628`, refreshed `2026-07-22T22:36:36-04:00`, source `deferred-generated-refresh`, SHA-256 `F59677CB957557B8B386CFA13D37FE63EAABE66692921EAD6EAF105A41FDD5C2`, `1,634,834` bytes / `6,507` lines. Its [UID:00046O] row is line `1694`, `87/89`, combined `88.0`, reconstructable true, and has zero direct, additional, and B-report coverage.
- Executed [UID:0002QT] B008 is a broad family/split lead. It materially mentions this child but does not declare [UID:00046O] as an additional target and does not resolve the current template-formal inconsistency or the exact `0x00620090-0x006200a8` vtable gap.
- Executed [UID:00003B] B004 is a broad class lead. It preserves the older rejected `void *context` signature and therefore is historical for this target's formal type.
- Historical report-only snapshot: before Gate 1, no validator, report lifecycle command, report execution, by-* edit, generated refresh, manual coverage edit, lease, or IDA mutation had been performed. The accepted callback later authorized the ordinary edits and scoped validators recorded below; manual coverage, IDA, and report lifecycle remained untouched.

## Target

- Target UID: `00046O`.
- Additional target UIDs: none.
- Declared-target inventory:

| UID | Path | Role |
| --- | --- | --- |
| `00046O` | `by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md` | Primary source-authored method target. |

- Target path: `by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md`.
- Source queue/report row: tracker command `16628`, line `1694`, `87/89`, combined `88.0`, reconstructable true, no report coverage.
- Current supervisor classification: accepted implementation callback completed; awaiting independent supervisor verification and execution.
- Current scores and parent state: `92/94`, `CANONICAL_OWNER:00003B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003B`, blank optional position, R0 formal C++, `Nested:0`.

## Current Target State

- Current metadata is structurally valid and the direct owner/emitter route remains correct.
- Current owner/emitter/reconstructable state: [UID:00003B] `CreateUserDialogPane` is the direct class owner/emitter; [UID:0000IJ] `CreateUserDialogPane.cpp` is the class/file source root; [UID:0002QT] is the non-emitting split/index parent.
- Current C++/emitter state: generated output contains one UID00046O method body and no UID00046O empty-emitter marker. The target now uses the compiler-proven three-template-parameter `PlainMemberFunctionObjectT` specialization with a local C++03 pointer-to-member typedef.
- Historical questions/stale assumptions corrected by this callback:
  - broad B004's `void *context` formal is contradicted by the target's single truth test and lack of dereference/forwarding;
  - broad B008 correctly changed the parameter to a boolean but retained an invalid callback-template shorthand;
  - target prose does not document the exact body hash, boundary padding, no-entry proof, sibling-body corroboration, callback vtable, object layout, allocation-failure behavior, callback ownership, or destructor release route;
  - the broad read-only-data aggregate [UID:00025Z] previously left `0x00620090-0x006200a8` without an exact child page; UID0004WH now covers it and excludes successor `0x006200a8`.
- Related target/support docs checked: [UID:00046P], [UID:00046X], [UID:0002QT], [UID:00003B], [UID:0000IJ], [UID:0001CT], [UID:00009I], [UID:0000M0], [UID:0001WQ], [UID:0001CS], [UID:00025Z], [UID:0003C7], [UID:0001FK], [UID:0003GK], [UID:0003DF], and the generated `CreateUserDialogPane.cpp`.
- Current artifact/lifecycle status: implementation is complete and this active report awaits independent supervisor verification/execution. B003 has not run or probed any report lifecycle command.

## Executive Recommendation

- Keep direct target ownership under [UID:00003B] `CreateUserDialogPane`, emitted through [UID:0000IJ] `NexusTK/login/CreateUserDialogPane.cpp`.
- Keep the exact source-facing method name `OpenNexonclubRegistrationOrSendCharacterRequest` and parameter `bool openRegistration`. Both are inferred, but they are the highest-probability project-consistent names after exhaustive caller, pointer, sibling, and support-document checks.
- Replace the current callback allocation with R0. R0 uses a local pointer-to-member typedef and the proven three-parameter `PlainMemberFunctionObjectT<TMember,TObject,TArg>` specialization.
- Keep source behavior intentionally simple: no explicit allocation null checks, callback cleanup, smart pointer, exception wrapper, or returned dialog pointer. Those additions would change the observed behavior and would not resemble the likely original C++03 source.
- Exact non-emitting support child [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) was validator-registered and routed to [UID:0001WQ] `FunctionObjectTemplates`; blank formal C++ and no-code proof document compiler regeneration from the shared template plus R0's construction site.
- Raise [UID:00046P] from `88/90` to `90/93` after adding the exact sole data-xref, concrete callback binding, `+0x27c` / decimal `636` assignment route, and unconditional send contract.

## Supervisor Active Recheck

- Historical Gate 1 instruction re-read: create a complete literal-template Rule 26 report for UID00046O, edit only this report, use healthy live IDA MCP, stop if MCP is unavailable, run no validators or lifecycle commands, and execute no report. Exact SHA `618EA6BDAFE80F8944512D8C45814DB9F485F7CB9517B0948BC960C9134A882C` passed fresh Gate 1; the later callback explicitly authorized the ordinary edits and scoped validators recorded below, but not report execution.
- Split-first check: the executable target is already an exact one-function child. It does not require an executable split.
- Source-bearing child check: the separate callback at [UID:00046P] is already an exact source-bearing child. The only newly discovered child requirement is non-executable support data `0x00620090-0x006200a8`; it must not be merged into the target executable range.
- Duplicate/assignment check: exact UID, range, and title searches found no direct active or executed UID00046O report. B008 UID0002QT is a broad family lead and B004 UID00003B is a class lead. `SupervisorAssignments.md` assigns UID00046O only to B003. No other B goal or active report claims the target.

## Inference Research Guidance Check

- `by-structure.md` was used for exact range ownership, source-authored versus source-declared/generated-binary treatment, and the narrowest durable documentation home.
- The skill-level instruction to ignore Wave2/Wave3 material is controlling. Stale Wave2/Wave3 references in older docs were not used as evidence.
- Existing documentation was treated as fallible:
  - B004's raw pointer parameter was rejected.
  - B008's boolean gate was revalidated and retained.
  - B008's two-argument callback-template draft was rejected after checking the live decorated symbol and current shared declaration.
  - The current method name was not accepted merely because it already existed; it was compared with three sibling helpers, current class/file vocabulary, and the no-route evidence.
- Evidence categories are separated below:
  - IDA fact: exact bytes, function boundaries, instructions, branches, xrefs, calls, object sizes, vtable symbol/slots, and field stores.
  - Documentation evidence: current owner/emitter route, class/file placement, string aliases, and accepted support-page names.
  - Inference: private method name, local typedef name, parameter name, `void` source return, and `SimpleUString` alias spelling.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best resolution | Evidence | Classification |
| --- | --- | --- | --- |
| Target name | Retain `OpenNexonclubRegistrationOrSendCharacterRequest`. | True branch constructs `NexonclubRegistrationDialog`; false branch calls `SendCreateCharacterRequest`; current class/file use the name consistently. | High-probability source-facing inference. |
| Parameter type | `bool`. | The stack value is compared only with zero at `0x0052e996`; it is never dereferenced, stored as user state, passed onward, or used arithmetically before the compiler reuses the stack slot for EH allocation tracking. | Strong ABI/source inference. |
| Parameter name | `openRegistration`. | It describes the true branch without claiming why the caller selected it. | Descriptive inference. |
| Return type | `void`. | The method is a side-effect branch helper. EAX merely retains callee/allocation results; there are no callers that consume it. Three same-shaped sibling helpers use the same tail-value artifact. | Strong source-shape inference. |
| Callback class | `PlainMemberFunctionObjectT`, not current `PlainMemberFunctionObject`. | Live vtable symbol at `0x00620094` includes `PlainMemberFunctionObjectT` and the exact pointer-to-member/class/argument specialization. | Original compiler metadata proof. |
| Callback template arguments | Pointer-to-member type, `CreateUserDialogPane`, and `const SimpleUString &`. | Decorated name contains three arguments; [UID:0001WQ] declares `PlainMemberFunctionObjectT<TMember,TObject,TArg>`. | Original metadata plus current declaration. |
| Callback target | `OnNexonclubRegistrationResult`. | Object store at `+0x08` is exact address `0x0052ea50`; [UID:00046P] copies non-empty input to `+0x27c` and always sends the character request. | Direct binary fact plus accepted source name. |
| Callback object layout | 24 bytes: vptr `+0x00`, inherited/base state through `+0x04`, member target `+0x08`, this adjustment `+0x0c`, bound object `+0x10`. | Allocation immediate `0x18`; stores at `0x0052e9c1`, `0x0052e9c7`, `0x0052e9ce`, and `0x0052e9d5`; shared invoke/object-size slots corroborate the layout. | Direct binary fact. |
| Callback base pointer | `FunctionObjectT<const SimpleUString &> *`. | Registration constructor stores the polymorphic pointer at `+0x26c`; cancel/success invoke virtual slot `+0x0c`; destructor invokes deleting destructor. | Strong source-type inference. |
| String alias | Keep `SimpleUString` in this class-local method. | Compiler metadata proves underlying `mystr::StringBase<wchar_t,...>`; current CreateUserDialogPane class/callback/field use `SimpleUString`. `StringBaseW` is an equivalent project alias used by the proxy branch. | Project-consistent typedef inference. |
| Language id `227` | Localized registration prompt, no invented literal. | Direct `g_pLanguageMan->GetString(227)` call and construction of `NexonclubRegistrationDialog`; no recovered string-table text. | Exact ID plus conservative semantic inference. |
| Dialog size/type | `new NexonclubRegistrationDialog(...)`, 632-byte object. | Allocation `0x278` / decimal `632` and constructor `0x0052f950`. | Direct binary fact and RTTI/class evidence. |
| Callback ownership | Registration dialog owns the callback after constructor handoff. | Constructor stores callback at `+0x26c` / decimal `620`; command cancel and success paths invoke it; destructor invokes deleting destructor with flag `1`. | Direct binary fact. |
| Allocation failure | Do not add source guards or cleanup. | Callback allocation failure passes null if dialog allocation succeeds; dialog allocation failure returns with no explicit callback release; compiler EH funclets only represent lowered new-expression cleanup. | Exact negative/source-shape evidence. |
| Reachability | Retained source-authored method with no recovered live entry route. | Zero target xrefs, zero VA/RVA pointer hits, but a coherent complete source method and three same-shaped sibling retained helpers. | Evidence-backed retained/no-route classification. |
| New support child | `0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData`. | Locator pointer, exact five-slot vtable, sole construction xref, and hard successor boundary at `0x006200a8`. | Exact range/source-declared-generated-binary classification. |

Rejected alternatives:

- `void *context`: rejected because the argument is not dereferenced or forwarded.
- `int`, pointer, dialog pointer, or enum parameter: rejected because only truth value is observed and no caller evidence supports a richer type.
- Current two-template-argument `PlainMemberFunctionObject<CreateUserDialogPane,const SimpleUString &>`: rejected because it does not match the decorated specialization or current shared declaration.
- Emitting the long decorated IDA name: rejected because final source must use a readable C++03 typedef and template form.
- Handwritten callback struct fields or raw vtable dwords: rejected because shared FunctionObjects source should regenerate them.
- `std::function`, lambda, `auto`, smart pointer, RAII wrapper, or modern alias syntax: rejected as anachronistic and binary-shape-changing.
- Explicit callback deletion when dialog allocation fails: rejected because the observed null/failure path does not release it.
- Folding the callback at `0x0052ea50` into this target: rejected because it is an exact separate source method and child page.
- Moving the method to `NexonclubRegistrationDialog`: rejected because the bound object is `CreateUserDialogPane`, the false branch sends that dialog's packet, and the callback writes that dialog's `+0x27c` field.

## Evidence Standards Used

- Exact live IDA MCP function lookup, analysis, decompilation, disassembly, callee, xref, entity-name, raw-byte, and byte-pattern queries.
- Exact source-document metadata and current support-document hashes.
- Compiler-decorated vtable name as stronger type evidence than decompiler guesses.
- Constructor/destructor and virtual-call pairing for callback ownership/lifetime.
- Sibling-body comparison for source-shape and retained/no-route interpretation.
- Negative evidence required more than one route: xrefs, function callers, absolute VA pattern, RVA pattern, and exact report duplicate searches.
- Confidence remains below `95` because there is no original private symbol or caller and no recovered literal text for language id `227`.

## Evidence Checked

- Live MCP database/session: `9b0396a3`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Health: `status:"ok"`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Target:
  - `lookup_funcs` reports `sub_52E970`, size `0xd4` / decimal `212` (Verified with `int_convert.py`).
  - Exact target bytes: 212 bytes, SHA-256 `21D7FD7646F890A61CD299278685A2CFF297ABA0EDB49D443741CBE184999CBA`.
  - `analyze_function` reports 82 instructions and 12 basic blocks.
  - `xrefs_to` reports zero inbound refs.
  - `xref_query both` returns only the function's internal `0x0052e970 -> 0x0052e971` flow.
  - `find_bytes` finds zero `70 E9 52 00` absolute-VA and zero `70 E9 12 00` RVA matches.
- Callback and dependencies:
  - [UID:00046P] `sub_52EA50`, `0x2c` / decimal `44`, one data xref from `0x0052e9c7`.
  - [UID:00046X] `sub_52F160`, `0x22d`, three code callers at `0x0052ea2c`, `0x0052ea72`, and `0x0052f4e6`.
  - Registration constructor `sub_52F950`, `0x64b`, four callers at `0x0052b6f4`, `0x0052d1a4`, `0x0052ea14`, and `0x005538d3`.
  - Registration destructor `sub_52FFA0`, `0x75`, deletes callback stored at `+0x26c`.
  - Registration `OnCommand` `sub_530060` invokes callback on cancel through virtual slot `+0x0c`.
  - Registration notification handler `sub_530230` invokes the same callback with account text on success.
- Callback vtable:
  - exact decorated name at `0x00620094`;
  - sole xref at `0x0052e9c1`;
  - raw table `0x00620090-0x006200a8`;
  - member target absolute pattern `50 EA 52 00` appears exactly once at `0x0052e9ca`; RVA pattern appears zero times.
- Sibling source-shape controls:
  - `sub_52B650` and `sub_52D100` are exact `0xd4` / decimal `212` siblings, have zero inbound xrefs, allocate the same 24-byte callback, use language id `227`, construct the same 632-byte dialog, and bind their class-specific callback methods.
  - live proxy constructor `sub_553610` is an independently called control that uses the same three-argument decorated template specialization and dialog handoff.
- Documentation/report searches:
  - exact `UID:00046O`: goal plus executed B008 broad report;
  - exact `0x0052e970`: goal plus executed B008 and B004 broad reports;
  - exact title: goal/assignment plus executed B008 broad report;
  - no direct active or executed UID00046O report found.
- `int_convert.py` was used for `0xd4`/212, `0x18`/24, `0x278`/632, `0x26c`/620, `0x27c`/636, and `0x0c`/12.
- Failed/unavailable checks: none. No mutating IDA calls were attempted.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | `00046O` | Exact range is one 212-byte function at `0x0052e970-0x0052ea44`. | Very strong | MCP lookup, bytes, disassembly, SHA-256. | UID00046O Evidence/Range | incorporate | applied |
| C02 | `00046O` | Predecessor alignment byte is `0xcc` at `0x0052e96f`; successor gap `0x0052ea44-0x0052ea50` is 12 `0xcc` bytes. | Very strong | MCP raw bytes. | UID00046O Range | incorporate | applied |
| C03 | `00046O` | Parameter is a boolean gate, not an opaque context pointer. | Very strong | Single compare, no dereference/forward/store. | UID00046O Behavior/formal R0 | incorporate | applied |
| C04 | `00046O` | False branch calls `SendCreateCharacterRequest` and returns. | Very strong | Disassembly `0x0052ea2c`. | UID00046O Behavior | incorporate | applied |
| C05 | `00046O` | True branch allocates a 24-byte callback object and a 632-byte registration dialog. | Very strong | Allocation immediates and constructors. | UID00046O Behavior/Layout | incorporate | applied |
| C06 | `00046O` | Callback concrete type is three-argument `PlainMemberFunctionObjectT`. | Very strong | Decorated vtable symbol and UID0001WQ declaration. | UID00046O Type/formal R0 | incorporate | applied |
| C07 | `00046O` | Callback layout is vptr/base, member target `+0x08`, zero adjust `+0x0c`, object `+0x10`. | Very strong | Exact stores at `0x0052e9c1-0x0052e9d5`. | UID00046O Callback Layout | incorporate | applied |
| C08 | `00046O` | Callback member target is `CreateUserDialogPane::OnNexonclubRegistrationResult`. | Very strong | Exact address store and UID00046P body. | UID00046O Behavior/formal R0 | incorporate | applied |
| C09 | `00046O` | Prompt is `g_pLanguageMan->GetString(227)`; literal text is not recovered. | Very strong for ID, medium for semantic label | Direct call and dialog type. | UID00046O Behavior/Open Questions | incorporate | applied |
| C10 | `00046O` | Registration dialog receives ownership of the callback. | Very strong | Constructor `+0x26c` store, command/success invoke, destructor delete. | UID00046O Lifetime | incorporate | applied |
| C11 | `00046O` | Source must not add explicit null guards or cleanup absent from the machine path. | Very strong | Allocation/failure control flow and EH funclets. | UID00046O Negative Evidence/formal rationale | incorporate | applied |
| C12 | `00046O` | No recovered entry route exists, but the complete method remains source-authored and reconstructable. | Strong | Zero xrefs/pointer hits plus three retained same-shaped siblings. | UID00046O Reachability/score | incorporate | applied |
| C13 | `00046O` | Owner/emitter remains UID00003B and file route remains UID0000IJ. | Very strong | Bound `this`, callback field, send helper, current parent chain. | UID00046O metadata/ownership | already-present | already-present |
| C14 | `00046P` | Callback has one data binding, copies non-empty text to `+0x27c`, and always sends. | Very strong | Analyze/disassembly/xref. | UID00046P Evidence/score | incorporate | applied |
| C15 | `0001WQ` | Add the concrete CreateUserDialogPane const-wide-string callback instantiation and exact construction route. | Very strong | Decorated symbol, shared declaration, object stores. | FunctionObjectTemplates concrete inventory | incorporate | applied |
| C16 | `00025Z` | Split exact callback vtable child `0x00620090-0x006200a8` from mixed aggregate inventory. | Very strong | Exact locator/table/successor bytes. | UID00025Z child inventory | incorporate | applied |
| C17 | `0004WH` | Exact child is non-emitting compiler-generated support with blank formal C++. | Very strong | Vtable generated from shared template and construction site. | UID0004WH metadata/formal R1 | incorporate | applied |
| C18 | `0001CT` | Registration constructor is called from UID00046O and stores/owns its callback at `+0x26c`. | Very strong | Constructor caller/store/destructor. | UID0001CT behavior/caller inventory | incorporate | applied |
| C19 | `00003B` | Class method note must name concrete callback template, ownership transfer, and no-entry proof. | Strong | Target and support evidence. | CreateUserDialogPane method notes | incorporate | applied |
| C20 | `0000IJ` | File method inventory must preserve the exact target/callback pair and source placement. | Strong | Class/file/current split. | CreateUserDialogPane file proposed contents/evidence | incorporate | applied |

## Positive Evidence Summary

- The target is a complete modeled 212-byte method with standard prolog, SEH/new-expression lowering, and two coherent source branches.
- Every true-branch object field is explained by the decorated callback class and shared FunctionObjects declaration.
- The callback target, receiver, and argument type are all independently corroborated by `0x0052ea50`, `0x00620094`, and [UID:0001WQ].
- The registration constructor stores the callback and its destructor releases it. This closes the lifetime question rather than leaving an inferred handoff.
- Three same-shaped create-user helpers independently use language id `227`, class-specific string callbacks, and the same registration dialog. This makes the target's retained source method interpretation substantially stronger than a one-off decompiler guess.

## IDA MCP Facts

- Function/range facts:
  - `sub_52E970`, exact size `0xd4` / decimal `212` (Verified with `int_convert.py`), 82 instructions, 12 blocks.
  - Target byte SHA-256 `21D7FD7646F890A61CD299278685A2CFF297ABA0EDB49D443741CBE184999CBA`.
  - Function returns with `retn 4` at `0x0052ea29` and `0x0052ea41`.
- Data/table/padding facts:
  - `0x0052e96f` is one `0xcc` predecessor alignment byte.
  - `0x0052ea44-0x0052ea50` is 12 bytes of `0xcc` alignment (Verified with `int_convert.py`).
  - `0x00620090` is complete-object-locator pointer `0x0064cb04`.
  - `0x00620094-0x006200a8` holds five vtable slots: `0x0052f7c0`, `0x004f4b10`, `0x0041b6c0`, `0x0049af00`, and `0x004673f0`.
  - `0x006200a8` is the next locator pointer `0x0064cb54`; it is excluded.
- Xref facts:
  - target start: zero inbound xrefs;
  - callback target `0x0052ea50`: one data xref from target store `0x0052e9c7`;
  - callback vtable `0x00620094`: one data xref from target store `0x0052e9c1`;
  - send helper `0x0052f160`: three code xrefs, including target false branch and callback completion;
  - registration constructor `0x0052f950`: four code callers, including target at `0x0052ea14`.
- Vtable/global/type facts:
  - vtable name proves pointer-to-member type `void (CreateUserDialogPane::*)(const mystr::StringBase<wchar_t,...>&)`, class `CreateUserDialogPane`, and argument `const mystr::StringBase<wchar_t,...>&`;
  - language manager global is current source-facing `g_pLanguageMan`;
  - callback allocation is `0x18` / decimal `24` (Verified with `int_convert.py`);
  - dialog allocation is `0x278` / decimal `632` (Verified with `int_convert.py`).
- Negative IDA facts:
  - no target callers/xrefs;
  - no target absolute-VA or RVA pointer hits;
  - no callback target RVA hit;
  - no evidence the boolean is a context pointer;
  - no explicit callback cleanup on dialog-allocation null path;
  - no source-authored vtable table required.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0052e970-0x0052ea44` | [UID:00046O] target | Boolean-gated source method | TRUE | `00003B` | current `92/94` | Formal R0 implemented and validated |
| `0x0052ea44-0x0052ea50` | no page | Alignment | no | parent aggregate | n/a | Keep padding, do not extend target |
| `0x0052ea50-0x0052ea7c` | [UID:00046P] | Bound result callback | TRUE | `00003B` | current `90/93` | Support update implemented and validated |
| `0x0052f160-0x0052f38d` | [UID:00046X] | Character request sender | TRUE | `00003B` | `88/90` | Caller-context update only |
| `0x0052f950-0x00530636` | [UID:0001CT] | Registration dialog aggregate | TRUE | `0000M0` | `86/90` | Provider/ownership detail implemented |
| `0x00620090-0x006200a8` | [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) | Concrete callback RTTI/vtable support | FALSE | `0001WQ` | current `88/93` | Exact blank-formal child created and validated |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0052e970` | zero inbound xrefs | No recovered direct/code/data entry route. |
| `0x0052e9a2` | calls allocator with 24 | Callback object allocation. |
| `0x0052e9bc` | calls `LObject` base constructor | Callback base initialization. |
| `0x0052e9c1` | stores vtable `0x00620094` | Exact concrete template specialization. |
| `0x0052e9c7` | stores `0x0052ea50` at `+0x08` | Bound member callback. |
| `0x0052e9ce` | stores zero at `+0x0c` | Zero this adjustment. |
| `0x0052e9d5` | stores target `this` at `+0x10` | Bound receiver. |
| `0x0052e9e8` | calls allocator with 632 | Registration dialog allocation. |
| `0x0052ea0c` | `g_pLanguageMan->GetString(227)` | Localized prompt source. |
| `0x0052ea14` | calls `0x0052f950` | Dialog constructor handoff. |
| `0x0052ea2c` | calls `0x0052f160` | False-gate direct send. |
| `0x0052ea50` | one data xref from `0x0052e9c7` | Callback is address-taken only. |
| `0x0052ffa0` | no direct caller, destructor body | Releases stored callback through deleting destructor. |
| `0x00530060` | vtable xref at `0x006200f4` | Cancel invokes callback with empty text. |
| `0x00530230` | vtable xref at `0x00620124` | Registration success invokes callback with account text. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0002QT] correctly establishes the exact child boundary, boolean gate, callback address, language id, and class route.
  - [UID:00003B] and [UID:0000IJ] establish the old dialog class/file and `m_createUserExtraText` field.
  - [UID:00046P] establishes non-empty assignment plus unconditional send.
  - [UID:0001WQ] establishes the three-template-parameter callback declaration.
  - [UID:0001CT], [UID:00009I], and [UID:0000M0] establish registration-dialog callback ownership.
- Existing docs that are stale, incomplete, or contradicted:
  - B004 `void *context` is superseded.
  - target/current generated two-argument callback type is inconsistent with the live decorated symbol and current declaration.
  - [UID:00025Z] describes `0x0061fed8-0x00620094` and then resumes at `0x006200a8`, leaving the exact target callback table without a child.
  - manual coverage rows lag current source-page scores for [UID:0002QT], [UID:00003B], [UID:0000IJ], [UID:0001CT], [UID:0001CS], and [UID:00025Z].
- Historical generated state observed during the report-only research phase:
  - `auto-generated/NexusTK/login/CreateUserDialogPane.cpp`, SHA-256 `812BEA39D30735D34102A281D5F7D287546466BA5BA89DC276440C576005F398`, `16,071` bytes / `505` lines;
  - header command `000000016594`, `2026-07-22T20:38:53-04:00`, foreground-generated;
  - UID00046O occurs once at line `189`;
  - no UID00046O empty marker;
  - that historical block contained the rejected two-argument callback shorthand.
- Current post-callback generated checkpoint:
  - callback command `000000016675`, timestamp `2026-07-22T23:42:16-04:00`, is the historical implementation-generation provenance;
  - a later unrelated foreground refresh produced current command `000000016680`, timestamp `2026-07-22T23:49:26-04:00`;
  - current `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` SHA-256 is `95EF38882E99DF933DD263AAC94693D3CE13FED24BEAD3C29EEE517F25AF0501`, `16,163` bytes / `509` lines;
  - UID00046O occurs once at line `189` and UID00046P occurs once at line `214`;
  - declarations use `bool openRegistration` and `const SimpleUString &text`;
  - UID00046O contains the local pointer-to-member typedef and three-argument `PlainMemberFunctionObjectT` construction;
  - no UID00046O or UID00046P empty marker and no raw UID0004WH vtable/RTTI output;
  - the only two empty markers in this file are unrelated pre-existing UID0002SI vtable data and UID0002B3 singleton-slot pages.

## Ranked Ownership Analysis

### 1. CreateUserDialogPane class [UID:00003B]

- Evidence for:
  - method receiver is the old `CreateUserDialogPane`;
  - callback vtable encodes that class;
  - callback writes this class's `+0x27c` field;
  - false and completion paths call this class's character request sender.
- Evidence against: no direct target callers.
- Decision: accepted. No-route status affects reachability confidence, not owner identity.

### 2. CreateUserDialogPane file [UID:0000IJ]

- Evidence for: exact class source root, old-dialog method inventory, login module, and current emission route.
- Evidence against: file page is a broad source root, not the direct method owner.
- Decision: accepted as source placement/emission root, not direct canonical owner.

### 3. FunctionObjects [UID:0000JO]/[UID:0001WQ]

- Evidence for: owns reusable `FunctionObjectT` and `PlainMemberFunctionObjectT` declarations and should regenerate the concrete callback vtable.
- Evidence against: does not own target branch policy, dialog construction, callback member, or character packet send.
- Decision: dependency and direct owner of proposed compiler-data child only; rejected as target method owner.

### 4. NexonclubRegistrationDialog [UID:00009I]

- Evidence for: constructed by target and receives the callback.
- Evidence against: callback is bound to `CreateUserDialogPane`; registration dialog is consumer/owner after handoff.
- Decision: rejected as target owner; retain as support dependency.

### Proposed new file/grouping, if applicable

- Proposed support path: `by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md`.
- Likely full contents: exact locator pointer, five vtable slots, decorated type, sole construction xref, target callback address, shared destructor/invoke/object-size links, blank formal C++, and no-code proof.
- Direct parent: [UID:0001WQ] `FunctionObjectTemplates`.
- Rejected contents: executable target, callback method body, registration dialog class vtables beginning `0x006200a8`, and raw handwritten dword arrays.

## Source Placement

- Recommended source file/class placement: private/protected `CreateUserDialogPane` method in `NexusTK/login/CreateUserDialogPane.cpp`; declaration remains on [UID:00003B].
- Why: every feature-specific state access and action belongs to the old create-user dialog, while only the reusable callback template belongs to FunctionObjects.
- Rejected placements:
  - `NexonclubRegistrationDialog.cpp`: constructed consumer, not owner.
  - `FunctionObjects.cpp`: template dependency, not feature policy.
  - `CreateUserDialogs.cpp` umbrella: family index, not direct old-dialog source root.
- Remaining placement uncertainty: exact original access specifier and whether the local pointer-to-member typedef lived inside the function or a private source scope. This does not affect binary behavior or direct file ownership.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `0x0052e970-0x0052ea44`, one function, 212 bytes.
- Predecessor: [UID:00046N] function ends at `0x0052e96f`; byte `0x0052e96f` is alignment.
- Successor: 12 `0xcc` bytes at `0x0052ea44-0x0052ea50`, then [UID:00046P].
- Compiler EH funclets at `0x00604d36`, `0x00604d41`, and frame handler tail are generated lowering associated with new expressions; they are outside the target range and do not justify source-child extension.
- Target split decision: no executable split.
- Support-data split decision: [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) now covers `0x00620090-0x006200a8`, excluding successor [UID:0003C7] at `0x006200a8`.
- Parent impact: [UID:0002QT] remains a 22-child non-emitting index; [UID:00025Z] gains one exact child and stays a mixed non-emitting aggregate.

## Negative Evidence Summary

- No target start xref, caller, address table, absolute pointer, or RVA pointer was found.
- No direct evidence recovers the original private method name, parameter name, or access specifier.
- No evidence supports a raw context pointer, integer payload, dialog pointer, or enum parameter.
- No evidence supports returning the allocation/constructor EAX value in source.
- No evidence supports modern callback facilities, explicit ownership wrappers, or an extra cleanup branch.
- No evidence supports hand-emitting vtable/RTTI dwords.
- No evidence identifies the literal text behind language id `227`; the report does not invent it.
- Address locality to `NexonclubRegistrationDialog` does not transfer source ownership.
- The no-entry result is not stated as absolute runtime impossibility; unresolved indirect construction can never be disproved globally. The accurate conclusion is no recovered entry route.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types:
  - `CreateUserDialogPane::OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)`;
  - local `RegistrationResultCallback` pointer-to-member typedef;
  - `FunctionObjectT<const SimpleUString &> *callback`;
  - `PlainMemberFunctionObjectT<RegistrationResultCallback, CreateUserDialogPane, const SimpleUString &>`.
- Proposed documentation-only IDA interpretations:
  - `sub_52E970` as the retained boolean-gated registration/send method;
  - `sub_52EA50` as `OnNexonclubRegistrationResult`;
  - `0x00620090-0x006200a8` as CreateUserDialogPane registration-result callback RTTI/vtable support.
- Items intentionally left unchanged:
  - no IDA symbol/type/comment edits were requested;
  - no original symbol proves the exact method/local typedef spelling;
  - no literal name is assigned to language id `227`.
- IDA DB edits: not requested and not performed. Documentation evidence is sufficient for the report.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The current target already emits, and the corrected form is sufficiently strong for a `92/94` source-quality draft.
- R0 exact target formal replacement:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void CreateUserDialogPane::OpenNexonclubRegistrationOrSendCharacterRequest(
    bool openRegistration)
{
    if (!openRegistration) {
        SendCreateCharacterRequest();
        return;
    }

    typedef void (CreateUserDialogPane::*RegistrationResultCallback)(
        const SimpleUString &);

    FunctionObjectT<const SimpleUString &> *callback =
        new PlainMemberFunctionObjectT<
            RegistrationResultCallback,
            CreateUserDialogPane,
            const SimpleUString &>(
                this,
                &CreateUserDialogPane::OnNexonclubRegistrationResult);

    new NexonclubRegistrationDialog(
        g_pLanguageMan->GetString(227),
        callback);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- R1 exact UID0004WH formal block:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Why R0 preserves behavior:
  - same false/true branch;
  - same 24-byte concrete callback specialization;
  - same bound member and receiver;
  - same language id and dialog constructor;
  - no added failure cleanup, returned pointer, or side effect.
- Why R0 matches plausible original source:
  - C++03-compatible local typedef;
  - project-existing FunctionObjects abstraction;
  - no decompiler labels, offsets, vtable stores, EH funclets, or raw allocator calls;
  - no modern language/library features.
- Inferred names/types: method and local typedef names are high-probability inferred; `SimpleUString` is the current class-local source alias for the compiler-proven wide `StringBase` type.
- Naming style: PascalCase methods/types, `m_` fields, lowerCamel local/parameter names, matching current `CreateUserDialogPane` and shared source docs.
- R1 stays blank because the vtable is source-declared/generated-binary support; R0 plus [UID:0001WQ] should cause compiler emission.

## Final Recommendation

- Applied the full target evidence, behavior, callback layout/lifetime, range, negative evidence, and historical corrections.
- Replaced target formal C++ with R0.
- Raised target to `92/94`; owner/emitter/reconstructable/position/Nested remain unchanged.
- Raised [UID:00046P] to `90/93` and added its direct binding and callback contract.
- Kept [UID:0002QT] `90/90`, [UID:00003B] `88/89`, [UID:0000IJ] `88/89`, [UID:0001WQ] `88/90`, [UID:0001CT] `86/90`, [UID:00009I] `86/86`, [UID:0000M0] `87/86`, [UID:0001CS] `87/91`, and [UID:00025Z] `86/91`; facts were expanded without broad score inflation.
- Registered and created UID0004WH at `88/93`, owner [UID:0001WQ], `RECONSTRUCTABLE:FALSE`, blank emitter, blank formal C++, `Nested:0`.
- No owner remains unknown. No target is left non-emitting. Only the exact compiler-data child is intentionally non-emitting.
- Future work outside this assignment: project-wide normalization of the analogous two-argument callback shorthand in sibling create-user/proxy formal C++ after their own exact-artifact review.

## Recommended Target Doc Changes

Callback status: all accepted target changes below are implemented and scoped-validated. The list is retained as the exact accepted plan and Gate 2 comparison surface.

- Target path: `by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md`.
- Exact facts to incorporate:
  - exact bytes/SHA/range/instruction/block/boundary evidence;
  - complete false and true branches;
  - callback allocation, concrete type, vtable, fields, target, receiver, and size;
  - dialog allocation, prompt id, constructor call, callback ownership, cancel/success invocation, destructor release;
  - allocation-null and compiler-EH behavior;
  - no-entry/pointer negative evidence and sibling corroboration;
  - owner/source placement and rejected alternatives;
  - historical `void *context` and current invalid callback shorthand corrections.
- Metadata:
  - `COMPLETION:92`;
  - `CONFIDENCE:94`;
  - keep `CANONICAL_OWNER:00003B`;
  - keep `RECONSTRUCTABLE:TRUE`;
  - keep `EMITTER_UIDS:00003B`;
  - keep blank optional position;
  - use R0;
  - keep `Nested:0`.
- Preserve historical assumptions in a labeled superseded section rather than deleting why they were rejected.

## Recommended Support Doc Changes

Callback status: all accepted support changes below are implemented and scoped-validated. The list is retained so the supervisor can verify the implementation claim by claim.

- `by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md`
  - raise `88/90 -> 90/93`;
  - add sole data xref `0x0052e9c7`, concrete callback type/vtable, `+0x27c` field, non-empty-only assignment, unconditional send, and source `void` rationale.
- `by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md`
  - keep `90/90`;
  - update UID00046O/46P rows with corrected callback type, exact ownership/lifetime, and scores.
- `by-class/CreateUserDialogPane.md`
  - keep `88/89`;
  - expand method notes with the three-parameter callback type, no-entry proof, ownership handoff, and `m_createUserExtraText` callback route.
- `by-file/CreateUserDialogPane.md`
  - keep `88/89`;
  - expand the optional registration/callback row and evidence with exact type/lifetime/no-entry facts.
- `by-type/by-template/FunctionObjectTemplates.md`
  - keep `88/90`;
  - add concrete `CreateUserDialogPane` const-wide-string callback inventory, exact 24-byte construction fields, vtable `0x00620094`, and issued child UID0004WH.
- `by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md`
  - keep `87/91`;
  - link UID00046O and the exact new vtable child as the CreateUserDialogPane construction context.
- `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`
  - keep `86/91`, `RECONSTRUCTABLE:FALSE`, no owner/emitter;
  - replaced the implicit `0x00620094-0x006200a8` gap with exact child UID0004WH and incremented `Nested`.
- [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md)
  - created exact support page after validator registration;
  - metadata and blank C++ as stated above;
  - document range, slots, xrefs, source-generation route, and no-code proof.
- `by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md`, `by-class/NexonclubRegistrationDialog.md`, and `by-file/NexonclubRegistrationDialog.md`
  - keep scores/owners;
  - add UID00046O as the CreateUserDialogPane provider, the `+0x26c` ownership handoff, cancel/success invocation, and destructor release.
- No manual `-coverage-report.md` file may be edited by B003.

## Score And Metadata Recommendation

- Historical pre-callback target: `87/89`, owner/emitter `00003B`, reconstructable true, nonblank but invalid two-argument callback C++.
- Current implemented target: `92/94`, same owner/emitter/reconstructable/position/Nested, R0 formal C++.
- Reason higher:
  - exact range and byte hash;
  - complete branch, callee, xref, and boundary inventory;
  - exact boolean parameter resolution;
  - exact decorated callback type and 24-byte layout;
  - exact callback target/field/result contract;
  - exact registration constructor, owner transfer, invoke, and release chain;
  - explicit allocation-failure and EH source-shape treatment;
  - exact non-entry/pointer negative evidence;
  - implementation-ready human C++03 formal.
- Reason not `95+`:
  - no original private method/local typedef/parameter symbol;
  - no recovered literal text for language id `227`;
  - no recovered direct caller;
  - exact original `SimpleUString` versus `StringBaseW` typedef spelling remains inferred even though ABI type is proven.
- Score-improvement attempts:

| Previous blocker | Research performed | Result |
| --- | --- | --- |
| No target caller | Xrefs, bidirectional xref query, absolute/RVA pointer scans, sibling comparison | No recovered entry route; retained source interpretation strengthened and precisely bounded. |
| Callback template unknown | Decorated vtable, shared declaration, slot bytes, construction stores | Resolved exact three-argument specialization and legal R0. |
| Callback lifetime unknown | Registration constructor, command handler, success handler, destructor | Resolved ownership transfer, invocation, and deletion. |
| Dialog failure behavior unknown | Full target disassembly and EH funclets | Resolved; do not add cleanup/guards. |
| String callback semantics incomplete | Callback body, field offset, send helper callers | Resolved non-empty store and unconditional send. |
| Vtable data not exactly covered | Raw table bytes, names, xrefs, successor boundary | Resolved exact `0x00620090-0x006200a8` child recommendation. |
| Original source names | Existing project vocabulary, sibling routes, metadata, rejected alternatives | Highest-probability human names selected; remaining uncertainty only caps score below 95. |

## Open Questions With Attempted Resolution

- Original private method name:
  - checked original-symbol names, target xrefs, absolute/RVA pointer patterns, three sibling bodies, class/file docs, broad reports, and generated output;
  - no original symbol survives;
  - accepted `OpenNexonclubRegistrationOrSendCharacterRequest` as the most descriptive existing human name;
  - impact: confidence cap only, not a C++ blocker.
- Original parameter name:
  - checked all target uses and found only a truth gate;
  - accepted `openRegistration`;
  - impact: confidence cap only.
- Original wide-string typedef spelling:
  - decorated type proves `mystr::StringBase<wchar_t,...> const&`;
  - current CreateUserDialogPane docs use `SimpleUString`, while proxy docs use `StringBaseW`;
  - accepted `SimpleUString` locally for class consistency;
  - impact: below-95 source-spelling caveat only.
- Language id `227` literal:
  - checked local docs/reports and live function context;
  - no literal text recovered;
  - retain numeric language lookup and describe it only as registration prompt text;
  - impact: no behavior/C++ blocker.
- No recovered target caller:
  - exhaustive static xref/pointer checks are negative;
  - three sibling source bodies have the same retained/no-route state;
  - retain source method and document no recovered entry route rather than claiming runtime impossibility;
  - impact: confidence cap only.
- No unresolved question remains that requires a raw IDA/decompiler name, blank target C++, owner ambiguity, or score below the recommended gate.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only manual roots at the post-callback checkpoint (`2026-07-22`; the files' last-write times are recorded below):

- `by-memory/-coverage-report.md`: SHA-256 `39866F17A58097EFA75F1DED0B6AFC896E936A081F65208FB4FCF73B4E197A55`, `1,984,236` bytes / `4,566` lines, last written `2026-07-22T23:43:09-04:00`; current UID0002QT/0001CS/0001CT/00025Z anchors are lines `2602`, `2604`, `2606`, and `4105`, while UID00046O/00046P/0004WH are absent.
- `by-class/-coverage-report.md`: SHA-256 `E4F6985825BD360CD322C6099EC097CF87E7597BCD9F328E500829A02937875E`, `257,808` bytes / `624` lines, last written `2026-07-22T21:57:06-04:00`; current UID00003B/00009I anchors are lines `144` and `365`.
- `by-file/-coverage-report.md`: SHA-256 `78B5F2C81A5BDD86AC67655EA7152F0FC8541F1AF5A7DACF8EB7AB7ACB2B0D90`, `154,448` bytes / `317` lines, last written `2026-07-22T21:57:06-04:00`; current UID0000IJ/0000M0 anchors are lines `64` and `189`.
- `by-type/by-template/-coverage-report.md`: SHA-256 `132BBBE1CF8F7AEDA300D108A45B51CCDBD14ED093BC63D41FF8C4392346D6F5`, `4,151` bytes / `29` lines, last written `2026-07-22T17:56:01-04:00`; current UID0001WQ anchor is line `19`.

The older by-memory root `A7D812B60CB35399C541461DC0E214A8380B61D7793E2BB499B9247449A1A70B` at `1,982,596` bytes / `4,564` lines is a historical report-only epoch superseded by unrelated later coverage work. Supervisor must re-read all roots and rebase these rows immediately before application. Preserve unrelated later additions.

File/placement: `by-memory/-coverage-report.md`, replace current UID0002QT row and insert UID00046O/46P immediately below it:

```text
        - [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) 0x0052dd30-0x0052f710 | executable child/index | CreateUserDialogPaneCore : reconstructable : 90% : very-strong : Exact non-emitting 22-child old CreateUserDialogPane split/index with source-authored method children, raw/compiler no-code exclusions, constructor/vtable/singleton evidence, corrected event and packet types, file-local account sender, reply switch-table boundary, and source-quality C++ routed through exact child pages.
            - [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) 0x0052e970-0x0052ea44 | class method | CreateUserDialogPane::OpenNexonclubRegistrationOrSendCharacterRequest : reconstructable : 92% : very-strong : Exact 212-byte retained no-entry boolean-gated source method with false-path character request, true-path 24-byte three-argument PlainMemberFunctionObjectT construction, language id 227, 632-byte NexonclubRegistrationDialog handoff, callback ownership/lifetime, allocation-failure behavior, exact boundary/padding and pointer-negative proof, and human C++03 formal source.
            - [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) 0x0052ea50-0x0052ea7c | class method/callback | CreateUserDialogPane::OnNexonclubRegistrationResult : reconstructable : 90% : very-strong : Exact 44-byte address-taken result callback bound only by UID00046O; non-empty StringBase text is assigned to m_createUserExtraText at +0x27c and the character request is sent unconditionally.
```

File/placement: `by-memory/-coverage-report.md`, replace current UID0001CT row:

```text
    - [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md) : reconstructable : 86% : very-strong : Exact NexonclubRegistrationDialog aggregate with constructor/destructor/command/response/status/helper/thunk/deleting-destructor inventory, four constructor providers including UID00046O, callback storage at +0x26c, cancel/success invocation and destructor release, NCA submission/response routing, vtable/resource/padding evidence, and coordinated child/declaration C++ still required.
```

File/placement: `by-memory/-coverage-report.md`, replace current UID0001CS row:

```text
    - [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) 0x0052f780-0x0052f7fe | template destructor | FunctionObjectTConstStringDestructors : reconstructable : 87% : very-strong : Non-emitting source-declared/generated-binary const-reference StringBase callback scalar deleting destructor pair with exact bounds, bytes, vtable/data refs, no caller/endpoint routes, shared FunctionObjects ownership, and concrete NewUserDialogPane2/NewCreateUserDialogPane/CreateUserDialogPane/NexonclubProxyDialog construction contexts.
```

File/placement: `by-memory/-coverage-report.md`, replace UID00025Z row and insert issued child UID0004WH immediately below:

```text
    - [UID:00025Z][0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData](by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md) 0x0061fd04-0x00620284 | vtable/string-data aggregate | CreateUserRegistrationReadOnlyData : not-reconstructable : 86% : very-strong : Mixed non-emitting create-user, callback, registration, NumberInputDialog and resource-data aggregate with exact class-vtable children, exact CreateUserDialogPane registration-callback vtable child, corrected successor boundaries, and source declarations/construction sites identified as binary regeneration routes.
        - [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) 0x00620090-0x006200a8 | callback RTTI/vtable data | CreateUserDialogPaneRegistrationCallbackVtableData : not-reconstructable : 88% : very-strong : Exact 24-byte complete-object locator pointer plus five-slot PlainMemberFunctionObjectT<CreateUserDialogPane,const StringBaseW&> vtable, with sole construction store in UID00046O, bound target UID00046P, shared FunctionObjects generation route, hard NexonclubRegistrationDialog successor boundary, blank formal C++, and no raw dword emission.
```

File/placement: `by-class/-coverage-report.md`, replace UID00003B row:

```text
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) : reconstructable : 88% : strong : Old CreateUserDialogPane class owned by UID0000IJ with exact 22-child method split, declaration-level C++, field/control inventory, constructor/vtable/singleton/lifecycle evidence, packet/reply flow, and UID00046O/46P three-argument FunctionObjects callback construction, registration handoff, no-entry proof, result storage and send contract; inherited interface and a few source-local names remain below final certainty.
```

File/placement: `by-class/-coverage-report.md`, replace UID00009I row:

```text
- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md) : reconstructable : 86% : strong : Registration form dialog owned by UID0000M0 with constructor/destructor/command/response/status/helper/thunk/deleting-destructor map, four provider routes including UID00046O, callback ownership at +0x26c with cancel/success invocation and destructor release, NCA flow, resource/vtable evidence, and coordinated declaration/helper C++ still pending.
```

File/placement: `by-file/-coverage-report.md`, replace UID0000IJ row:

```text
- [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) : reconstructable : 88% : strong : Old create-user dialog source root in NexusTK/login with exact child-method emission, class/vtable/singleton/lifecycle evidence, appearance and packet/reply flow, file-local account sender, and UID00046O/46P boolean-gated registration callback construction, concrete FunctionObjects type/lifetime, no-entry proof and character-request completion route.
```

File/placement: `by-file/-coverage-report.md`, replace UID0000M0 row:

```text
- [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) : reconstructable : 87% : strong : Registration dialog source root with exact function map, NCA request/response policy, resource and vtable support, four constructor providers including CreateUserDialogPane UID00046O, callback storage/invocation/release ownership, and remaining coordinated class/helper C++ work.
```

File/placement: `by-type/by-template/-coverage-report.md`, replace UID0001WQ row:

```text
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) : reconstructable : 88% : strong : Shared FunctionObject, FunctionObject0, FunctionObjectT, PlainMemberFunctionObject and PlainMemberFunctionObjectT declarations routed through UID0000JO, with exact 24-byte callback layouts and concrete TerminalPane, PopupMenu, create-user and Nexonclub string-callback construction contexts; UID00046O proves the three-argument CreateUserDialogPane const-wide-string specialization and exact compiler-generated vtable child without duplicating feature source.
```

Reason B003 must not apply rows directly: all manual `-coverage-report.md` files are supervisor-owned collision points. UID0004WH has been substituted in the exact handoff text, but the supervisor must rebase and apply it.

## Follow-Up Actions

- Supervisor:
  - independently verify this callback implementation claim by claim;
  - apply/rebase and validate the exact manual coverage rows;
  - run the supervisor-only report lifecycle command only after verification;
  - execute/archive only after independent verification.
- B003 callback completion:
  - UID0004WH was registered/created through the validator-supported new-file workflow;
  - every accepted claim was applied at report-level detail;
  - no manual coverage file was edited;
  - only callback-authorized scoped validators were run.
- Other agents: no action required.

## Confidence

- Recommendation confidence: `94`.
- Score confidence: very strong. `92/94` reflects a fully researched narrow method with human C++03 source, while preserving exact below-95 name/reachability/string-literal caveats.
- Remaining uncertainty:
  - original private method/local typedef/parameter spelling;
  - exact source alias `SimpleUString` versus `StringBaseW`;
  - literal text behind language id `227`;
  - unrecovered direct caller.
- None of those uncertainties justify raw/decompiler names, blank target C++, owner ambiguity, or a lower source-quality score.

## Validator Results

- Working directory for every command: `E:\NTK\GhidraBridge\source-3\project-documentation`.

| Command | Timestamp | Literal command | Exit / ok | Generated state |
| --- | --- | --- | --- | --- |
| `000000016646` | `2026-07-22T23:24:55-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md" --apply --queue-timeout 240` | exit `0`; matched output emitted no `ok` field; successful UID0004WH insertion confirmed registration | deferred |
| `000000016651` | `2026-07-22T23:28:14-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016652` | `2026-07-22T23:28:26-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016654` | `2026-07-22T23:29:53-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md" --apply --queue-timeout 240 --wait-generated` | exit `0`; `ok: 1` | completed |
| `000000016656` | `2026-07-22T23:31:04-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016658` | `2026-07-22T23:31:54-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016661` | `2026-07-22T23:34:00-04:00` | `python .\tools\validator.py --mode file --file "by-class/CreateUserDialogPane.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016665` | `2026-07-22T23:35:39-04:00` | `python .\tools\validator.py --mode file --file "by-file/CreateUserDialogPane.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016669` | `2026-07-22T23:38:45-04:00` | `python .\tools\validator.py --mode file --file "by-type/by-template/FunctionObjectTemplates.md" --apply --queue-timeout 240` | exit `0`; `ok: 1`; six pre-existing missing-reference warnings | deferred |
| `000000016671` | `2026-07-22T23:39:48-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016673` | `2026-07-22T23:40:37-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016674` | `2026-07-22T23:41:34-04:00` | `python .\tools\validator.py --mode file --file "by-class/NexonclubRegistrationDialog.md" --apply --queue-timeout 240` | exit `0`; `ok: 1` | deferred |
| `000000016675` | `2026-07-22T23:42:16-04:00` | `python .\tools\validator.py --mode file --file "by-file/NexonclubRegistrationDialog.md" --apply --queue-timeout 240 --wait-generated` | exit `0`; `ok: 1` | completed |

- Command `000000016669` retained six existing missing-reference warnings for UID0003LP/000365/000366/00036G already present in FunctionObjectTemplates; they are unrelated to C01-C20 and did not prevent `ok: 1`.
- Command `000000016675` reported broad validator-owned metadata refreshes and one unrelated generated UID0000P8 Weather update. B003 did not manually edit generated files.
- Current generated identity is the later unrelated foreground command `000000016680`, timestamp `2026-07-22T23:49:26-04:00`; it preserved the exact callback command16675 semantic shape and counts.
- Every assigned by-* document returned exit `0` and `ok: 1` after its final content, except initial registration command `000000016646`, whose matched output emitted no `ok` field before the final child validation succeeded.
- `int_convert.py` is a read-only numeric conversion helper, not a validator; it was used for all decimal/hex conversions recorded above.

## Changed Files

- `by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md`: SHA-256 `2CA57CD3C90EB9B60E5D6148A6E09D7EB1775FB8E23AADF8570EF748CC1F5286`, `10,292` bytes / `132` lines.
- `by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md`: SHA-256 `217BCECDF0EE7974D9F8A68835CB8DCFF50D022030BDB9D685C3463F48EC331B`, `5,306` bytes / `71` lines.
- `by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md`: SHA-256 `DFBF079DF27DD8547CE433F4C437F701607F7B50B46F5C6751C511B0EA04E616`, `16,491` bytes / `97` lines.
- `by-class/CreateUserDialogPane.md`: SHA-256 `36B98C02E9AC81189D83B9EF6BAF5E96AF172CF777680DB4B6250C6F0AB54E43`, `37,733` bytes / `249` lines.
- `by-file/CreateUserDialogPane.md`: SHA-256 `5BDE5E1CF9EFC7C1E20C8906004C2A74E9466D233E31F0E8D048DA26E5E52D92`, `27,739` bytes / `155` lines.
- `by-type/by-template/FunctionObjectTemplates.md`: SHA-256 `F8A7CFA53025EC159FF49AAE5E8F808CF4663281356D4124219D79CDA4925E10`, `64,804` bytes / `510` lines.
- `by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md`: SHA-256 `9F0CE08CB856E62B4076DE2B759B9B61203E9E86547F4264D1AC91283FF1B7FF`, `19,436` bytes / `126` lines.
- `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`: SHA-256 `B7B03E26E524DDBD21763C376CFE5C793BB3C6D56C252223F9883E1A390FEFCE`, `26,462` bytes / `139` lines.
- Created `by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md`: UID0004WH, SHA-256 `879991B88DBEB34E23A7BDCE24BA504155E6BE0001499615EBB5E3E31888B44C`, `10,868` bytes / `104` lines.
- `by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md`: SHA-256 `56AB598535D98E5456EB1DE679D48A42F2A783B97524FF2ECDD1DDB7DB2F8E7E`, `16,885` bytes / `123` lines.
- `by-class/NexonclubRegistrationDialog.md`: SHA-256 `FA65B52105BD2D4A8301B2AD76FDA16987B64565727577B1CADCF60530A33100`, `15,447` bytes / `112` lines.
- `by-file/NexonclubRegistrationDialog.md`: SHA-256 `1D22E33B351D7573975288B50F36ACD11D422C1D15940657F3EBE4864EAE1702`, `16,504` bytes / `129` lines.
- Current generated readback: `auto-generated/NexusTK/login/CreateUserDialogPane.cpp`, command `000000016680`, timestamp `2026-07-22T23:49:26-04:00`, SHA-256 `95EF38882E99DF933DD263AAC94693D3CE13FED24BEAD3C29EEE517F25AF0501`, `16,163` bytes / `509` lines; validator-owned, not manually edited.
- Validator-owned side effects: projected completion stats and generated metadata/report files were refreshed as reported by the commands above; B003 did not edit them manually.
- Manual coverage: no `-coverage-report.md` file edited.
- Report execution/lifecycle: not run or probed.
- Leases: every ordinary-file lease was acquired only for its edit/validation batch and released immediately; current B003 leases are zero.
- IDA mutations: zero.

## Implementation Tracking Checklist

Completed B003 report and implementation obligations:

- [x] Exact report SHA `618EA6BDAFE80F8944512D8C45814DB9F485F7CB9517B0948BC960C9134A882C` passed fresh full Gate 1 before callback.
- [x] Additional target UID handling remains not applicable because the report declares only primary UID00046O; support UIDs are destination dependencies, not additional report targets.
- [x] C01-C20 retain one normalized target UID and controlled actions; C01-C12/C14-C20 are `applied`, and C13 is `already-present`.
- [x] UID00046O formal C++ is R0, score is `92/94`, and owner/emitter/reconstructable/position/Nested remain unchanged.
- [x] UID00046P is `90/93` with sole binding, `+0x27c` non-empty assignment, and unconditional send documented.
- [x] Validator command16646 registered UID0004WH before dependent links; every placeholder was replaced.
- [x] UID0004WH exactly covers `0x00620090-0x006200a8`, excludes successor `0x006200a8`, is `88/93`, owner UID0001WQ, non-reconstructable/non-emitting, and has blank R1 formal C++ with no-code proof.
- [x] UID0002QT, UID00003B, UID0000IJ, UID0001WQ, UID0001CS, UID00025Z, UID0001CT, UID00009I, and UID0000M0 were updated without broad score inflation.
- [x] Full positive/negative evidence, rejected alternatives, historical corrections, boundary facts, allocation-failure behavior, and callback ownership/lifetime were preserved.
- [x] Target-byte SHA remains `21D7FD7646F890A61CD299278685A2CFF297ABA0EDB49D443741CBE184999CBA`.
- [x] R0 contains no decompiler labels, raw offsets, vtable stores, explicit cleanup, modern C++ features, or behavior-changing guards.
- [x] Source placement, exact split/padding classification, no-entry proof, and no IDA rename/type/comment action are recorded in destination docs.
- [x] Third-party import handling is not applicable; no `third_party_embeds/...` directive was added.
- [x] Every changed by-* document received a final scoped validation; all final passes returned exit `0`, `ok: 1`.
- [x] Final waited generation contains UID00046O and UID00046P exactly once each, correct source form, and zero target/callback empty markers.
- [x] Manual coverage roots and exact handoff rows were re-read read-only; B003 did not edit manual coverage.
- [x] No Wave2/Wave3 artifact controls any accepted fact.
- [x] No report lifecycle/execute command was run or probed by B003.
- [x] All ordinary leases were released; zero B003 leases remain.

Supervisor-only pending stages:

- [ ] Independently verify C01-C20, R0-R1, all destination hashes, validator provenance, and generated readback.
- [ ] Rebase/apply/validate the exact manual coverage handoff rows without deleting unrelated later additions.
- [ ] Execute/archive this report through the supervisor-only lifecycle command after verification.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000016694","destination_path":"executed-b-agent-research/B003/00046O-CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00046O-CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest-source-quality.md","timestamp":"2026-07-23T00:09:04-04:00","uid":"00046O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
