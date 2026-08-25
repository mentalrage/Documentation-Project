** TARGET-REPORT-UID:00031L **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00031L IMEStatusPaneScalarDeletingDestructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current implemented disposition: [UID:00031L] `by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md` is exact class-owned compiler ABI evidence with `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, and an empty managed formal C++ block.
- Final disposition: exact 85-byte MSVC scalar deleting destructor wrapper generated from the human `virtual ~IMEStatusPane();` declaration and the empty ordinary `IMEStatusPane::~IMEStatusPane()` definition. UID00031L is not a second source method, helper, product cleanup routine, or comment-emitting source artifact.
- Callback result: UID, path, exact range, `CANONICAL_OWNER:00006I`, and `Nested:0` were preserved; score is `92/94`; the emitted target proof comment was removed; complete target evidence and support prose were synchronized. The bounded C31L-033 repair removed the reverse-engineering `+0xf8` evidence comment from UID00006I formal C++ while retaining the exact `wchar_t statusText[256];` field and all offset/type evidence in prose.
- Human source route: [UID:0004BY] ordinary destructor -> [UID:00006I] `IMEStatusPane` -> [UID:0000K5] `NexusTK/input/IMEPanes.cpp`. The source declaration remains in the class, and the one source definition is the exact empty ordinary destructor body.
- Confidence: very high for range, bytes, wrapper identity, object size, vtable/adjustor liveness, hidden flag behavior, helper roles, source/no-source split, and placement. The score remains below final-audit values because the original compiler symbol, exact source formatting, and build switches are unavailable.
- Lifecycle boundary: report research, target/no-code implementation, bounded UID00006I source-clean correction, scoped validation, lease release, and final generated verification are complete. B004 performed no report execution, probe, count, revalidation, registry, move, archive, or other lifecycle command. Report validation/execution/archive/count and manual-coverage state remain external supervisor/validator-owned facts.

## Supporting Research

- B004 reread the assignment, current skill/reference/template, `by-structure.md`, the target, the ordinary destructor, constructor, class, file root, mixed aggregate, adjustor aggregate, vtable/read-only page, delete wrapper, Pane core, ignored ranges, generated `IMEPanes.cpp`, tracker row, and all affected manual coverage rows.
- Fresh IDA MCP evidence was collected directly for UID00031L on database `64c11373`; UID00031J was used only as a modern project-mechanism and sibling control, never as a substitute for target bytes, target CFG, target xrefs, target helpers, or target source disposition.
- At `2026-07-15T07:42:29-04:00`, a fresh `idb_list` returned one active adopted NexusTK session `64c11373`, worker PID `21508`. `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, and analysis, Hex-Rays, and string cache ready. A bounded target lookup returned `sub_4E8800`, size `0x55`; a bounded byte call at `2026-07-15T07:42:40-04:00` returned real target bytes. These are evidence-time health facts, not a claim of indefinite session availability.
- Concrete prior-report search terms were `UID00031L`, `UID:00031L`, `0x004e8800`, `0x004e8855`, `IMEStatusPaneScalarDeletingDestructor`, `UID0004BY`, `0x004e7290`, `IMEStatusPaneOrdinaryDestructor`, `UID0004BX`, `0x004e71c0`, `IMEStatusPaneConstructor`, `UID00006I`, `IMEStatusPane`, `UID0000K5`, `IMEPanes`, `UID00018C`, `UID00018D`, `0x004e861e`, `0x004e8629`, `scalar deleting destructor`, `Pane teardown`, `operator delete`, and `guard_check_icall_nop`.
- Active B001-B005 research roots were searched with those terms. No active B001-B005 report matched. `Agent-B003/goal.md` matched only because it explicitly avoided UID00031L as B004's assignment and selected independent UID0002JH; it is coordination evidence, not target research. `Agent-B004/goal.md` is the assignment source.
- Executed report `executed-b-agent-research/B007/0004BY-IMEStatusPaneOrdinaryDestructor-source-quality.md`, SHA256 `1999FB4CCD3C9594666BD8E524D5D81B1191B46991A2105438A60DBD5AFA4505`, was opened. It directly establishes the source-level ordinary destructor, vptr parity, inline `statusText` storage, and wrapper distinction. Its conclusion that UID00031L's proof comment could remain was treated as a historical lead and rejected after the fresh target and generated-output audit.
- Executed report `executed-b-agent-research/B011/0004BX-IMEStatusPaneConstructor-source-quality.md`, SHA256 `B10CB31B9F80D56E7C9F4D45DCAAED7D851FE86881C5CC8ACFD3010A69ACBCA9`, was opened. It corroborates complete-object size/layout evidence, the three status-pane vptr stores, `statusText[256]` at `+0xf8`, and the absence of an owned teardown resource.
- Executed report `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`, SHA256 `0CA4DCCEAEC01D430CFD46BECEDF073BA5671161130A18370AD52301E0DE4A6A`, was opened. It is the source-family/split lead and correctly identifies scalar wrappers as compiler output, but its proof-comment emission mechanism is superseded by current false/non-emitting practice and the direct target analysis.
- Executed report `executed-b-agent-research/B004/00031J-IMECompositionPaneScalarDeletingDestructor-source-quality.md`, SHA256 `3A57D4A6B47538AC08D46F6A129592BE68FDC02130DD534BEE9D219A30268878`, was opened. It is a modern mechanism and family control only. UID00031L was independently analyzed from its own bytes, disassembly, CFG, vtable routes, adjustors, ordinary destructor, constructor, siblings, helpers, and padding.
- No executed report filename or report body provided a direct UID00031L target-specific report. The exact search returned the four relevant controls above plus broader IME method reports; those broader reports were classified as source-family corroboration, not direct wrapper evidence.
- `tools/leaser/Agents/Older-Research/**` contains three Markdown reports. Exact UID/address/title/class/file/aggregate/helper searches returned no match. The three files concern GrafPort, JsonCpp, and ScrollCollectionPane and provide no target evidence.
- `tools/leaser/Agents/SpecialReports/**` contains five Markdown reports. Three `0004CC-IMEPaneSetFocusPane` benchmark reports matched only broad `IMEPane`/`IMEPanes` terms; they concern the root-pane focus method, not UID00031L, the status class, its ordinary destructor, or its scalar wrapper. The third-party inventory and benchmark comparison supplied no direct target report.
- The actual project archive root `project-documentation/archived/**` was inspected and contained zero Markdown reports, so it supplied no direct or support report.
- Historical B004 evidence-time generated checkpoint: `auto-generated/NexusTK/input/IMEPanes.cpp` carried validator command `000000012947`, refresh time `2026-07-15T07:39:52-04:00`, and SHA256 `9B01D6B91DC9B9D575B784F6D4228BB209D295C52EAC4CE4BB3EBDC8BB4A4A64` when the original report was drafted.
- Historical repair-time generated checkpoint: the file was reread after supervisor Gate 1 failure and carried validator command `000000012954`, refresh time `2026-07-15T07:56:58-04:00`, 21,130 bytes, and SHA256 `431301298A1CF0B2E31D6F0DBD94337C9ED2848EB3C780A59EC96DA9E7EA36AF`. Its target semantics were unchanged: exactly one `IMEStatusPane::~IMEStatusPane()` definition, exactly one UID00031L marker/name/proof-comment route, and zero `Empty Emitter Marker` strings. That proof comment was generated-source pollution because the target has no independent source body. The required later readback was completed by waited command `000000012986`.
- Historical callback generated checkpoints: final B004 waited validator command `000000012986`, timestamp/refreshed-at `2026-07-15T08:25:44-04:00`, produced `auto-generated/NexusTK/input/IMEPanes.cpp` with 20,636 bytes, 651 physical lines, and SHA256 `9B56DBC6D64521BC768E61C1E6ADD6B1B1C13912009D1639B2691567BEA26421`; later external command `000000013011` at `2026-07-15T08:35:25-04:00` produced SHA256 `5E1ADF269D2AF9BC0E17D10DB4B007333ECC8C43B540DC90C3BA3E0612B0FBE9`. Both historical checkpoints proved exactly one literally empty UID0004BY definition and zero UID00031L marker/name/proof-comment/body/`Empty Emitter Marker`, but they did not establish source cleanliness of the class field declaration.
- Historical pre-correction generated checkpoint: external validator command `000000013036`, refreshed `2026-07-15T08:49:16-04:00`, `auto-generated/NexusTK/input/IMEPanes.cpp`, 20,636 bytes, 651 physical lines, SHA256 `A0E091A3DBA8DB1198D54F7BA97F758DD70A9B3BA785C9BA8A3E3A547643D82B`. It had exactly one empty UID0004BY `IMEStatusPane::~IMEStatusPane()` definition, zero UID00031L marker/name/body/`Empty Emitter Marker`, and the invalid reverse-engineering field comment `wchar_t statusText[256];  // +0xf8, bounded UTF-16 status label text.` at line 550. This is pre-correction evidence, not a terminal generated-success claim.
- B004 post-correction waited checkpoint: authorized command `000000013040`, refreshed `2026-07-15T09:05:52-04:00`, `auto-generated/NexusTK/input/IMEPanes.cpp`, 20,591 bytes, 651 physical lines, SHA256 `842F165F27BC0D351470A12168334567575228CD38E346DBB5C1D2F65BB969DB`. It proved exactly one source-clean `wchar_t statusText[256];` at line 550, exactly one literally empty UID0004BY destructor at lines 596-598, zero UID00031L marker/name/body/`Empty Emitter Marker`, and zero `+0xf8`/bounded-evidence comment attached to the status field. The latest read-only checkpoint is external command `000000013049`, refreshed `2026-07-15T09:14:29-04:00`, same 20,591 bytes and 651 physical lines, SHA256 `3C94ED08E1FFC24038F5C67672B1887867156583A010414E0BA14D8B26C77850`; it preserves every one of those semantics exactly.

## Target

- Target UID: `00031L`.
- Target path: `by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md`.
- B004 artifact path at report production time: `tools/leaser/Agents/Agent-B004/research/00031L-IMEStatusPaneScalarDeletingDestructor-source-quality.md`.
- Exact half-open range: `[0x004e8800,0x004e8855)`, 85 bytes / `0x55`.
- Source queue/report row: assignment-time validator command `000000012944`; historical original-report evidence-time tracker command `000000012947`; repair-time read-only tracker command `000000012956`, refreshed `2026-07-15T08:02:51-04:00`; `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current tracker row at evidence time: `86/90`, average `88.0`, reconstructable true, `Nested:0`, zero reports.
- Historical pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006I`, blank optional position, `Nested:0`, formal four-line compiler-wrapper proof comment.
- Current implemented metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00006I`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, `Nested:0`, and literally blank managed formal C++.
- Current target file SHA256: `AC99EDE96CD80604509C9D04029FFA46A3351196AA9B73CFE4EB22D34E84BBA5`.
- Current classification: class-owned compiler-generated scalar deleting destructor evidence, no emitter, no independent C++, no split, and no rename.

## Current Target State

- Historical pre-callback target state was internally inconsistent: header `86/90`, stale `85/89` rationale, true/emitter/proof-comment output, generic product-cleanup wording, and stale manual by-memory coverage at reconstructable `85%`.
- Current target state is `92/94`, owner `00006I`, false, blank emitter/position/formal, `Nested:0`, with exact compiler-wrapper behavior, no-source proof, source route, negative evidence, padding, score rationale, and historical correction incorporated at report-level detail.
- Owner `00006I` remains semantically correct because the wrapper belongs to the `IMEStatusPane` vtable family. Ownership is explicitly separated from source emission.
- [UID:0004BY] emits the literally empty `IMEStatusPane::~IMEStatusPane()` body; [UID:00006I] preserves `virtual ~IMEStatusPane();`, the complete class union, and the source-clean `wchar_t statusText[256];` declaration. All wrapper ABI mechanics and reverse-engineering field comments are excluded from source.
- UID00006I, UID0000K5, UID00018C, and UID00018D preserve their scores/metadata/formal dispositions and now carry the accepted target-specific source/compiler relationship. `by-memory/-ignored.md` contains both exact alignment records.
- Scoped validators `000000012970` through `000000012985` accepted every changed ordinary destination. Three narrow corrective validators (`12982`, `12984`, `12985`) replaced one transcribed ordinary-body hash with the accepted exact `CACDD06C35C6...F6782915`; no formal or behavior conclusion changed.
- Commands `000000012986`, `000000013011`, and `000000013036` are historical checkpoints. B004 waited command `000000013040` proves one empty UID0004BY definition, zero UID00031L output or explicit wrapper mechanics, one source-clean status field, and no evidence comment attached to that field; latest external command `000000013049` preserves the same semantic counts.
- Manual coverage was intentionally not edited. Its exact accepted replacement/addition handoff remains below. Latest read-only whole-file hashes are `9699D0900828A80C5B42A0537D68E26AC6DAFC7AD1504E2A351B28131AA9750C`, `F637C4A9829A2E78C7FDF00ECEFC60A43655A655557473DB52B2C7FC5A68B716`, and `F92470E137660A52DD7568768589D86117CBB1699453913F8B2E70449AEFE26D` for by-memory/class/file respectively; affected UID00031L rows and absent UID0004BY/padding rows are unchanged.
- Current artifact/lifecycle boundary: all target/no-code, support, bounded UID00006I formal-comment removal, scoped/waited validation, generated comment-removal proof, report reconciliation, and lease release are complete. Report validation/execution/archive/count/path status is external supervisor/validator-owned and is not asserted by this artifact.

## Executive Recommendation

- Keep direct semantic owner [UID:00006I] `IMEStatusPane`; clear only source-output routing from UID00031L.
- Reclassify UID00031L to `92/94`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, and retain `Nested:0`, exact range, title, and path.
- Treat `0x004e8800` as the compiler's complete-object scalar deleting wrapper. Do not reconstruct a `ScalarDeletingDestructor` method, hidden flags parameter, explicit vptr stores, direct `Pane::~Pane()` call, delete helper call, guarded size call, proof comment, pseudo-body, or covered-by comment.
- Keep the single source declaration in [UID:00006I] and make [UID:0004BY] the exact empty source definition. The class/source file route remains [UID:00006I] -> [UID:0000K5].
- Add the two exact alignment intervals to `by-memory/-ignored.md`; do not split or expand UID00031L.
- Synchronize [UID:00018C] and [UID:00018D] at report-level detail without score/formal inflation. Keep [UID:0004BX], [UID:00025J], [UID:000197], [UID:0001EA], and the one-byte runtime stub verify-only.
- The target compiler/no-source decision and bounded support-class source-shape blocker are resolved. UID00006I retains `wchar_t statusText[256];` without the reverse-engineering comment; B004 waited command 13040 verified clean emission and latest external command 13049 preserves it. Original compiler/source spelling and build configuration remain the only research uncertainty and do not alter the no-source decision.

## Supervisor Active Recheck

- The current supervisor instruction assigns a fresh target-specific pass for UID00031L and explicitly forbids substituting UID00031J evidence. This report satisfies that condition with direct target bytes, hash, disassembly, decompile, CFG, xrefs, vtable values, helper audits, ordinary/constructor parity, sibling controls, and exact padding.
- The assigned item does not require a child split. The modeled function exactly fills `[0x004e8800,0x004e8855)`; both neighboring gaps are compiler alignment and the successor at `0x004e8860` is a separate standard-library helper.
- Every source-bearing item in scope is resolved now: the source declaration is [UID:00006I], the source definition is [UID:0004BY], and UID00031L plus its two adjustors are compiler-only. No exact source child is deferred.
- The completed callback was bounded to seven ordinary destinations: UID00031L, UID0004BY, UID00006I, UID0000K5, UID00018C, UID00018D, and `by-memory/-ignored.md`. Other checked dependencies remained verify-only.

## Inference Research Guidance Check

- `by-structure.md` distinguishes semantic ownership from generated routing. That permits `CANONICAL_OWNER:00006I` with `RECONSTRUCTABLE:FALSE` and blank emitters: the wrapper is class-owned documentation but not a source item.
- The current page's reconstructable/proof-comment state, old family report, generic helper names, Hex-Rays `char` parameter, and generic "teardown/optional delete" wording were treated as hypotheses, not facts.
- IDA facts are labeled as exact bytes, hashes, instructions, CFG, xrefs, vtable values, helper bodies, and boundaries. Documentation evidence is labeled by current pages, generated output, coverage, tracker, and prior reports. Inference is limited to source-level compiler causation, class/source placement, empty ordinary body, and score.
- The evidence ladder was applied from direct target bytes/disassembly and vtable routes, through ordinary/constructor parity and helper semantics, to generated/documentation consequences. Precedent was used only after target-specific closure.
- Wave2/Wave3 wording appears only in historical support cross-references. It was ignored as stale and did not drive any target decision.

## Heuristic / Inference Reanalysis And Validation

| Issue | Fresh evidence and resolution | Classification |
| --- | --- | --- |
| Generated name | `sub_4E8800` is the first slot of the primary `IMEStatusPane` vtable and the tail target of its two adjustors. Keep the descriptive documentation title `IMEStatusPaneScalarDeletingDestructor`; do not invent a human callable method. | Direct ABI identity plus descriptive documentation name. |
| Exact range | `lookup_funcs` gives start `0x004e8800`, size `0x55`; `0x004e8855` is not a function; eleven `0xcc` bytes lead to successor `0x004e8860`. No split/merge is justified. | Direct IDA/byte fact. |
| Receiver | ECX is copied to ESI and all vptr/helper operations use the complete object. The two thunks subtract `0xa0`/`0xa4` before entering this complete-object wrapper. | Direct IDA fact. |
| Hidden argument type | The stack slot is four bytes and both exits use `ret 4`; only AL is tested. Hex-Rays' `char` is a low-byte use artifact. The parameter is compiler deleting-destructor flags and must not appear in human source. | Direct ABI fact; source exclusion inferred from compiler convention and full shape. |
| Vptr writes | The target stores `0x0061c364`, `0x0061c3b0`, and `0x0061c3e0` at `+0`, `+0xa0`, and `+0xa4`. Constructor and ordinary destructor store the same triplet. These are compiler lifecycle lowering, not source statements. | Direct IDA/xref fact. |
| Base teardown | `0x00544580` is the inherited Pane ordinary teardown path. It is called after derived vptr restoration. Human C++ relies on automatic base destruction. | Direct callee analysis plus current Pane docs. |
| Bit 1 | If clear, cleanup returns the complete object without storage release. If set and bit 4 clear, `0x004f4ac0` frees storage through MemoryMan. This is compiler delete policy. | Direct disassembly/helper evidence. |
| Bit 4 | If set, the wrapper passes exact complete-object size `0x2f8` / 760 and `this` to `0x0041b6a0`, whose exact body is one byte `c3`; it then returns without normal free. This is a compiler/runtime guarded no-op branch, not placement-delete source. | Direct byte/disassembly fact. |
| Return shape | Both exits move complete `this` into EAX and use `ret 4`. This is wrapper ABI, not a source return type. | Direct disassembly fact. |
| Unique status cleanup | No read/write touches `statusText`, singleton storage, child pointers, heap members, strings, windows, IME handles, layers, events, or status-specific resources. Therefore the wrapper adds no human cleanup beyond the ordinary destructor. | Exhaustive instruction/field negative evidence. |
| Ordinary body | UID0004BY has three vptr stores and a tail transfer to Pane, with no derived cleanup. `statusText[256]` is inline storage. Highest-probability human source is an empty out-of-line destructor body, not a proof comment or implicit-only destructor. | Direct binary/layout evidence plus source-shape inference. |
| Formal source shape | Historical pre-correction UID00006I and command 13036 contained `wchar_t statusText[256];  // +0xf8, bounded UTF-16 status label text.`. The bounded correction retained the exact field type/count, moved no evidence out of prose, and removed only the source comment. B004 command 13040 emitted one clean declaration, and latest external command 13049 preserves it. | Direct page/generated evidence plus project source-quality rule; bounded correction applied and verified. |
| Liveness | Target has two code xrefs from adjustor thunks and one data xref from the primary vtable. It has no ordinary call route. Liveness is ABI/vtable selection, not evidence for a separate source method. | Direct xref fact. |
| Adjustors | `0x004e861e` and `0x004e8629` are exact 11-byte `this-0xa0` and `this-0xa4` tail thunks with corresponding vtable cells. They are compiler inheritance layout glue. | Direct bytes/hash/disassembly. |
| Sibling control | Candidate and root wrappers have real source cleanup before shared ABI tails; composition and status wrappers do not. Similar wrapper epilogues do not erase class-specific differences. | Direct fresh sibling analysis. |
| Proof comment | Historical commands `12947`/`12954` emitted the UID00031L proof comment. A source file should not contain reverse-engineering proof for a non-source wrapper. False/non-emitting metadata suppresses all target output at command `12986`; B004 command `13040` and latest external command `13049` preserve zero target output. | Historical/current generated readback plus source-quality rule; distinct class-field comment correction applied and verified. |
| Source placement | Declaration and empty ordinary definition belong under `IMEStatusPane` in `NexusTK/input/IMEPanes.cpp`; wrapper, adjustors, vtables, and alignment are generated binary products. | Class/file route and current project structure. |
| Score blocker | Range, hash, CFG, helpers, liveness, ordinary/source split, source route, padding, generated consequence, and negative evidence are resolved. Only unavailable original source/toolchain exactness caps the score. | Evidence-backed score closure. |

Rejected alternatives:

1. Keep UID00031L reconstructable and emit a proof comment. Rejected because a proof comment is not source, creates a target marker, and duplicates a source contract already represented by the class and ordinary destructor.
2. Emit a handwritten scalar deleting destructor or helper. Rejected because hidden flags, return-this ABI, vptr writes, explicit base teardown, delete selection, adjustor entries, and size/no-op branch are compiler/runtime lowering.
3. Fold UID00031L into UID0004BY. Rejected because both exact binary ranges have independent documentation value and different ABI roles; only the source output is singular.
4. Treat the wrapper as status-specific cleanup. Rejected because its full instruction stream touches no status member or resource.
5. Treat bit 4 as array deletion, placement delete, or a class helper. Rejected because the callee is the exact one-byte no-op runtime stub and no source-visible action occurs.
6. Assign direct ownership to `IMEPanes`, Pane core, operator delete, vtable data, or the mixed aggregate. Rejected because `IMEStatusPane` is the narrow semantic owner; the others are source root, inherited/runtime dependencies, generated data, or index pages.
7. Remove the empty ordinary destructor as implicit-only source. Rejected because the binary has a distinct ordinary out-of-line body, the class declares a virtual destructor, and current source routing expects one definition.
8. Keep the explanatory comment inside the ordinary destructor. Rejected as unnecessary reverse-engineering narration; no source statement is required, and the strongest human source shape is literally empty.
9. Rename or split the target. Rejected because the current descriptive path is accurate and the exact function/boundary is closed.
10. Raise all support scores because target evidence improved. Rejected; bounded target synchronization does not justify unrelated support score inflation.

## Evidence Standards Used

- Direct evidence: MCP `idb_list`, `server_health`, bounded `lookup_funcs`, `get_bytes`, `disasm(include_total)`, `analyze_function`, `decompile`, `callees`, `xrefs_to`, `get_int`, `make_signature`, and narrow sibling/helper checks on database `64c11373`.
- Binary integrity evidence: exact half-open target bytes and SHA256; exact ordinary destructor, two adjustors, one-byte runtime stub, prepad, postpad, and sibling-wrapper hashes.
- Structural evidence: 28 instructions, five basic blocks, cyclomatic complexity 2, exact vtable slots/store xrefs, two adjustor routes, primary vtable route, complete-object size, and successor function boundary.
- Source evidence: current `IMEStatusPane` declaration, constructor layout, ordinary destructor definition, source-file route, inline status buffer, generated output, and class/file/aggregate inventories.
- Negative evidence: no ordinary callers, no target-specific field/resource access, no singleton clear, no direct source helper, no EH/unwind branch, no array loop, no source-visible bit-4 action, no target direct prior report, and no missing child range.
- Confidence discipline: direct target evidence controls the decision. Prior reports and sibling wrappers only corroborate mechanism and project treatment.
- Tool limitation: one oversized four-function `analyze_batch` request timed out at 30 seconds. A bounded incident check at `2026-07-15T07:34:28-04:00` found the listener and worker present; fresh `idb_list`, health, lookup, and bytes succeeded, and all required evidence was repeated with narrow calls. This was a request-size/busy limitation, not an evidence gap or outage.
- Two early PowerShell transport attempts used an incorrect response parser/`get_bytes` field name. The server returned HTTP 200 and a schema diagnostic; corrected `addr`-based bounded calls returned real bytes. These client-side schema errors are recorded but do not weaken the successful evidence.

## Evidence Checked

- IDA MCP health: fresh session discovery and evidence-time health on `64c11373`; real target lookup and bytes confirmed after the earlier oversized-call incident.
- Target bytes: 85 bytes, SHA256 `36DB541414B33304808CE4E9E26E9EF5CA275766ACE5125F3C6ED2874F5716E2`.
- Target unique signature: `55 8B EC 56 8B F1 C7 06 64 C3 61 00`, unique true.
- Target disassembly/decompile/CFG: 28 instructions, five basic blocks, complexity 2; exact vptr, base-teardown, flags, delete, no-op-size, return-this, and `ret 4` behavior.
- Target xrefs: code at `0x004e8624` and `0x004e862f`; data at `0x0061c364`; no ordinary call route.
- Vtable cells: `0x0061c364 -> 0x004e8800`, `0x0061c3b0 -> 0x004e861e`, `0x0061c3e0 -> 0x004e8629`; constructor/ordinary/target store parity rechecked.
- Adjustors: exact ranges, deltas, bytes, hashes, jump targets, and vtable references for `0x004e861e` and `0x004e8629`.
- Helpers: `0x00544580` Pane teardown, `0x004f4ac0` MemoryMan-backed free wrapper, and `0x0041b6a0` one-byte `ret` runtime stub.
- Source anchor: UID0004BY exact 31-byte ordinary destructor, SHA256 `CACDD06C35C6C88FCD078F5BE400AFB1BAFD0C40CDAA9D2F855154E3F6782915`, no derived cleanup, three matching vptr stores, Pane tail transfer, zero inbound xrefs caveat.
- Constructor/layout: UID0004BX `Pane(0)`, same vptr triplet, `statusText[256]` clear at `+0xf8`, no target-owned teardown resource, complete size corroborated by wrapper constant `0x2f8`.
- Siblings: `0x004e8640` 127 bytes, SHA256 `6D7E5BAF5E4F865F49CFDB7A41F0E4EA699C3EDCF9D7DA675EC267263FB895EF`; `0x004e86c0` 85 bytes, SHA256 `70A98560325CFF07AF2772F37D414ED4B7A86470F90BB097B6396E2FF3DBBF8D`; `0x004e8720` 217 bytes, SHA256 `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`.
- Padding: seven `0xcc` bytes at `[0x004e87f9,0x004e8800)`, SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`; eleven `0xcc` bytes at `[0x004e8855,0x004e8860)`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Callback-start pre-edit hashes after lease reread: UID00031L `BBCA9AFDFF92B161BD168BAC22F9FD5772BF23EF7A09E5F16F819B5ECEB6C249`; UID0004BY `E0CE43FF0700D32E9077F62DED961C66EED7DD5E56D091F54642815C7AE7C892`; UID00006I `980C02B9D39C0030A4EADA3404F01425100AE63D8C90F73288C21BA94EA4DBA3`; UID0000K5 `EACA42726BB183AFB963531ECC6674DC77E452CB448783775CE256D7E3456256`; UID00018C `84525504AF95A0ACA6D0E0189591500DEFF9C720C85797FBC312355F8E2C70F1`; UID00018D `19BCF3F19D8B8F4B1A6190B6FB41371B04EC050691759BB8A53456E9424A7D2B`; ignored `DF9E253D68CECC18D2E30FDEFB9EB1754554C7CF48AD96FACEF8C0F1313F2106`.
- Current post-callback hashes: UID00031L `AC99EDE96CD80604509C9D04029FFA46A3351196AA9B73CFE4EB22D34E84BBA5`; UID0004BY `46DB40E0DA610B72DBDDB67DDBEB9A5F9BAE16FB506E59D8ABAD0E82F343567E`; UID00006I `8FF5531908C89883F75B654AC723428F78BCDF3EE542D9A25FC34D20820C29CE`; UID0000K5 `F77ACD5AC31024B885729E3BE75C0D8DFCBC2C0B5D587EEF572068017A9C6B76`; UID00018C `13B7BADA55F4D7E716BB6697BF5C0AB9D7C360ED17D16E34F83FD4869867AC50`; UID00018D `0D130DC5CA600E706177B51A7749D64ED2CF81848BF7242CF7047F637A424803`; ignored `133C5FFD6688F434F00C8BC09986E25BE8112C487460FF986D1EFE3FA9D51EE5`.
- Generated output: historical original-report checkpoint command `000000012947`, SHA256 `9B01D6B91DC9B9D575B784F6D4228BB209D295C52EAC4CE4BB3EBDC8BB4A4A64`; repair-time checkpoint command `000000012954`, SHA256 `431301298A1CF0B2E31D6F0DBD94337C9ED2848EB3C780A59EC96DA9E7EA36AF`; B004 callback checkpoint command `000000012986`, SHA256 `9B56DBC6D64521BC768E61C1E6ADD6B1B1C13912009D1639B2691567BEA26421`; historical subsequent external command `000000013011`, SHA256 `5E1ADF269D2AF9BC0E17D10DB4B007333ECC8C43B540DC90C3BA3E0612B0FBE9`; historical pre-correction command `000000013036`, SHA256 `A0E091A3DBA8DB1198D54F7BA97F758DD70A9B3BA785C9BA8A3E3A547643D82B`; B004 waited command `000000013040`, SHA256 `842F165F27BC0D351470A12168334567575228CD38E346DBB5C1D2F65BB969DB`; latest external read-only command `000000013049`, SHA256 `3C94ED08E1FFC24038F5C67672B1887867156583A010414E0BA14D8B26C77850`. Commands 13040 and 13049 each have one empty UID0004BY definition, zero UID00031L output, one source-clean status field, and no attached `+0xf8`/bounded-evidence comment.
- Manual coverage: affected by-memory, class, and file rows were reread during repair, at the historical post-command-`000000013011` checkpoint, and after B004 waited command `000000013040`. Latest time-scoped hashes are by-memory `9699D0900828A80C5B42A0537D68E26AC6DAFC7AD1504E2A351B28131AA9750C`, by-class `F637C4A9829A2E78C7FDF00ECEFC60A43655A655557473DB52B2C7FC5A68B716`, and by-file `F92470E137660A52DD7568768589D86117CBB1699453913F8B2E70449AEFE26D`. Across every snapshot, affected IME rows/placement are unchanged: UID0004BY and both exact padding rows remain absent; UID00018C, UID00018D, UID00031L, UID00006I, and UID0000K5 remain stale exactly as quoted below. Exact supervisor-owned replacements/additions therefore require no textual rebase. All whole-file hashes are time-scoped observations, not assertions that unrelated concurrent coverage updates will stop.
- Prior-report roots: active B001-B005, executed reports, Older-Research, SpecialReports, and actual `project-documentation/archived` root searched with concrete terms and classified above.
- Callback action boundary: no IDA mutation, source symbol rename, type application, manual coverage edit, generated-file manual edit, or lifecycle action occurred. The seven accepted ordinary docs were edited only under short B004 leases; scoped validators and one final waited refresh were run as authorized.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C31L-001 | Target is exactly `[0x004e8800,0x004e8855)`, 85 bytes. | Very high | `lookup_funcs`, bytes, successor lookup. | UID00031L Status/Evidence; validated `12982`, final waited `12986`. | incorporate | applied |
| C31L-002 | Target bytes hash to `36DB5414...5716E2`; unique signature is the 12-byte prologue/vptr prefix. | Very high | `get_bytes`, SHA256, `make_signature`. | UID00031L Evidence; post hash `AC99...BBA5`, validator `12982`. | incorporate | applied |
| C31L-003 | Target has 28 instructions, five blocks, complexity 2. | Very high | `disasm`, `analyze_function`. | UID00031L Evidence/Behavior; validator `12982`. | incorporate | applied |
| C31L-004 | ECX is complete `this`; stack dword is hidden deleting flags despite low-byte Hex-Rays type. | Very high | Disassembly, stack frame, `ret 4`, adjustors. | UID00031L Behavior/Reconstruction Notes; validator `12982`. | incorporate | applied |
| C31L-005 | Target restores status vptrs at `+0/+0xa0/+0xa4`. | Very high | Instructions and vtable refs. | UID00031L Behavior/Evidence and UID00006I Evidence; validators `12982`/`12985`. | incorporate | applied |
| C31L-006 | `0x00544580` is inherited Pane ordinary teardown, not target-owned source. | Very high | Callee analysis, UID0001EA. | UID00031L Behavior/Dependencies; UID0001EA verify hash unchanged. | incorporate | applied |
| C31L-007 | Bit 1 clear returns `this` without storage free. | Very high | Exact branch disassembly. | UID00031L Behavior; validator `12982`. | incorporate | applied |
| C31L-008 | Bit 1 set and bit 4 clear frees through MemoryMan-backed `0x004f4ac0`. | Very high | Disassembly, UID000197 helper. | UID00031L Behavior; UID000197 verify hash unchanged. | incorporate | applied |
| C31L-009 | Bit 4 path passes size `0x2f8` and `this` to one-byte `ret` stub, then returns without normal free. | Very high | Disassembly and exact stub byte/hash. | UID00031L Behavior/Rejected Alternatives; validator `12982`. | incorporate | applied |
| C31L-010 | Both exits return complete `this` in EAX and use `ret 4`; this is compiler ABI. | Very high | Full disassembly. | UID00031L Behavior; validator `12982`. | incorporate | applied |
| C31L-011 | Target callees are exactly Pane teardown, delete wrapper, and no-op runtime stub. | Very high | `callees`, full instruction audit. | UID00031L Evidence; validator `12982`. | incorporate | applied |
| C31L-012 | Target liveness is two adjustor code xrefs plus primary vtable data xref, with no ordinary call route. | Very high | `xrefs_to`, `analyze_function`. | UID00031L Evidence and UID00018D rows; validators `12982`/`12977`. | incorporate | applied |
| C31L-013 | `0x004e861e` is exact `this-0xa0` 11-byte thunk, hash `6D51F0...A3E0`. | Very high | Bytes/disassembly/vtable cell. | UID00018D first status row; validator `12977`. | incorporate | applied |
| C31L-014 | `0x004e8629` is exact `this-0xa4` 11-byte thunk, hash `EE7DD0...FD3C`. | Very high | Bytes/disassembly/vtable cell. | UID00018D second status row; validator `12977`. | incorporate | applied |
| C31L-015 | Primary/secondary/tertiary first slots are target/thunk/thunk. | Very high | `get_int`, UID00025J. | UID00031L/UID00018D; UID00025J verify hash unchanged. | incorporate | applied |
| C31L-016 | Constructor stores the same vptr triplet and establishes inline `statusText[256]`. | Very high | Vtable xrefs, fresh constructor control, UID0004BX. | UID00031L/UID00006I; UID0004BX verify hash unchanged. | incorporate | applied |
| C31L-017 | UID0004BY stores the same triplet and tail-transfers to Pane. | Very high | Exact ordinary bytes/disassembly. | UID0004BY/UID00031L; validators `12984`/`12982`. | incorporate | applied |
| C31L-018 | Highest-probability human destructor definition is literally empty. | High | Ordinary body, inline storage, no derived cleanup. | UID0004BY Destination 2 exact formal; validator `12984`, generated `12986`. | incorporate | applied |
| C31L-019 | Target touches no status-specific member/resource and adds no source cleanup. | Very high | Exhaustive instruction/field audit. | UID00031L no-code proof; validator `12982`. | incorporate | applied |
| C31L-020 | Candidate sibling has candidate queue/map cleanup, unlike target. | High | Fresh sibling analysis/hash. | UID00031L sibling controls; candidate sibling verify-only and unchanged. | incorporate | applied |
| C31L-021 | Composition sibling has the same no-unique-cleanup shape but is only a control. | High | Fresh sibling analysis and executed UID00031J. | UID00031L sibling controls; UID00031J verify-only and unchanged. | incorporate | applied |
| C31L-022 | Root IME sibling deletes child state/clears singleton, unlike target. | High | Fresh sibling analysis/hash. | UID00031L sibling controls; root sibling verify-only and unchanged. | incorporate | applied |
| C31L-023 | Zero ordinary callers does not create a source body; vtable/adjustor liveness proves ABI use. | Very high | Xrefs and vtable inventory. | UID00031L negative evidence; validator `12982`. | incorporate | applied |
| C31L-024 | Existing proof-comment emission is stale and must be removed. | Very high | Generated readback and source-quality rules. | UID00031L blank formal; historical command `12986`, B004 waited command `13040`, and latest external command `13049` prove zero target output. | reject-stale | applied |
| C31L-025 | Set `RECONSTRUCTABLE:FALSE`; wrapper is compiler-only. | Very high | Full target/source split proof. | UID00031L metadata; validator `12970` changed registry true -> false, final `12982`. | incorporate | applied |
| C31L-026 | Retain `CANONICAL_OWNER:00006I` as semantic class owner. | Very high | Vtables, constructor, ordinary destructor, class route. | UID00031L metadata retained; validator `12982`. | already-present | applied |
| C31L-027 | Clear emitter and leave optional position blank. | Very high | No independent source output. | UID00031L metadata; validator `12970` cleared emitter, final `12982`. | incorporate | applied |
| C31L-028 | Keep target managed formal C++ literally blank; no proof/pseudo/covered-by text. | Very high | Exhaustive no-code proof. | Destination 1 exact formal hash `CA40...F396`; generated `12986`. | incorporate | applied |
| C31L-029 | Raise target from `86/90` to `92/94`; historical `85/89` prose becomes historical. | High | All blockers resolved; original toolchain cap. | UID00031L metadata/Score/Changes; validators `12970`/`12982`. | incorporate | applied |
| C31L-030 | Retain path/title/range/UID and `Nested:0`; no split or rename. | Very high | Exact boundaries and descriptive identity. | UID00031L path/header retained; validator `12982`. | already-present | applied |
| C31L-031 | Add seven-byte prepad `[0x004e87f9,0x004e8800)` to ignored docs. | Very high | Exact bytes/hash/boundaries. | `by-memory/-ignored.md`; validator `12979`. | incorporate | applied |
| C31L-032 | Add eleven-byte postpad `[0x004e8855,0x004e8860)` to ignored docs. | Very high | Exact bytes/hash/successor. | `by-memory/-ignored.md`; validator `12979`. | incorporate | applied |
| C31L-033 | Preserve UID00006I score, metadata, declarations, children, and target/compiler prose, but make Destination 3 source-clean by changing only `wchar_t statusText[256];  // +0xf8, bounded UTF-16 status label text.` to `wchar_t statusText[256];`. | Very high | Historical command 13036 proved the leak; current page/formal hash and command 13040 prove exact source-clean correction while offset evidence remains in prose. | `by-class/IMEStatusPane.md`; page `7AFD...2722 -> 8FF5...29CE`, formal `5216...501E -> 09FA...7248`, scoped `13039`, waited `13040`. | incorporate | applied |
| C31L-034 | Preserve UID0000K5 score/formal; update source inventory and generated expectation. | Very high | File route and generated output. | `by-file/IMEPanes.md`; validator `12974`, generated `12986`. | incorporate | applied |
| C31L-035 | Preserve UID00018C `86/91` false/blank; replace stale target row and add target evidence. | Very high | Current aggregate and direct target pass. | UID00018C; validator `12976`, Destination 4 exact. | incorporate | applied |
| C31L-036 | Preserve UID00018D `85/90` false/blank; add exact status thunk bytes/hashes/routes. | Very high | Fresh thunk pass. | UID00018D; validator `12977`, Destination 5 exact. | incorporate | applied |
| C31L-037 | UID0004BX, UID00025J, UID000197, UID0001EA, and runtime stub need no ordinary edits absent callback-time contradiction. | Very high | Current docs and direct checks. | Verify-only hashes unchanged; no contradiction or scope expansion. | already-present | applied |
| C31L-038 | Final generated state must have one UID0004BY definition and zero UID00031L marker/comment/body/empty marker. | Very high | False-page routing plus current generated readback. | B004 waited `13040` (`842F...69DB`) and latest external read-only `13049` (`3C94...8B50`); all positive/negative counts pass. | incorporate | applied |
| C31L-039 | Manual coverage requires exact target/support row replacements/additions, including ordinary and padding rows. | Very high | Read-only coverage comparison. | Exact handoff applied to this report; B004 correctly excluded manual coverage edits because coverage is supervisor-owned. | incorporate | applied |
| C31L-040 | Callback must use one-file leases, scoped validators per changed ordinary page, one final waited target validation, zero lifecycle commands, and terminal report reconciliation. | Very high | Project workflow and bounded plan. | Original seven serial batches plus bounded class lease/`13039`/release/`13040`; zero B004 lease/lifecycle command remains. | incorporate | applied |

## Positive Evidence Summary

- Exact function identity: modeled target start, 85-byte closed range, exact hash, unique signature, 28 instructions, five blocks, complexity 2, and clean successor boundary.
- Exact ABI identity: complete-object receiver; three derived vptr restores; Pane teardown; hidden flag-1/flag-4 branches; return-this and `ret 4`; MemoryMan-backed storage release; complete size `0x2f8`; no-op runtime branch.
- Exact liveness: primary vtable entry and two secondary/tertiary adjustors, with no ordinary source call route.
- Exact source causation: constructor, ordinary destructor, and target restore the same three status vptrs. The ordinary body has no derived cleanup, and the class contains only inline `statusText[256]` beyond Pane.
- Strong sibling discrimination: wrappers with candidate/root source cleanup visibly contain it; composition/status wrappers do not. The shared ABI tail alone is not mistaken for source.
- Generated-output consequence: current proof-comment metadata emits a target marker/comment. False/no-emitter/blank formal is the only disposition that preserves evidence without inventing source.
- Strongest inference chain: exact class vtable routing + exact duplicate ordinary lowering + no target-specific operation + hidden compiler flags/runtime branches + existing human declaration/ordinary definition = compiler-only wrapper with no independent source output.

## IDA MCP Facts

- Database used: evidence-time session `64c11373`, NexusTK IDB, imagebase `0x400000`.
- Function: `sub_4E8800`, `[0x004e8800,0x004e8855)`, size `0x55`; `0x004e8855` not a function; successor `sub_4E8860`, size `0x192`.
- Exact bytes:
  `55 8b ec 56 8b f1 c7 06 64 c3 61 00 c7 86 a0 00 00 00 b0 c3 61 00 c7 86 a4 00 00 00 e0 c3 61 00 e8 5b bd 05 00 8b 45 08 a8 01 74 22 a8 04 75 10 56 e8 8a c2 00 00 83 c4 04 8b c6 5e 5d c2 04 00 68 f8 02 00 00 56 e8 55 2e f3 ff 83 c4 08 8b c6 5e 5d c2 04 00`.
- SHA256: `36DB541414B33304808CE4E9E26E9EF5CA275766ACE5125F3C6ED2874F5716E2`.
- CFG: five blocks covering entry/teardown, bit-1 decision, normal free, bit-4 size/no-op branch, and shared return; complexity 2.
- ABI: `_DWORD *__thiscall` decompiler shape, complete object in ECX/ESI, four-byte stack slot consumed by `ret 4`, low byte tested for flags, EAX returns original complete object.
- Vptr stores: `[this+0] = 0x0061c364`, `[this+0xa0] = 0x0061c3b0`, `[this+0xa4] = 0x0061c3e0`.
- Callees: `0x00544580`, `0x004f4ac0`, `0x0041b6a0`; no additional call.
- Xrefs to target: `0x004e8624` from function `0x004e861e`, `0x004e862f` from function `0x004e8629`, and data cell `0x0061c364`.
- Vtable values: `0x0061c364 -> 0x004e8800`; `0x0061c3b0 -> 0x004e861e`; `0x0061c3e0 -> 0x004e8629`.
- Vtable store xrefs: each table is stored by constructor `0x004e71c0`, ordinary destructor `0x004e7290`, and target `0x004e8800` at matching offsets.
- Thunk 1: `[0x004e861e,0x004e8629)`, bytes `81 e9 a0 00 00 00 e9 d7 01 00 00`, subtract `0xa0`, tail-jump target, SHA256 `6D51F020E447863B5AE66A0249F1EE8BB0EE38BDD706F1FCA9A1EEFDDC21A3E0`.
- Thunk 2: `[0x004e8629,0x004e8634)`, bytes `81 e9 a4 00 00 00 e9 cc 01 00 00`, subtract `0xa4`, tail-jump target, SHA256 `EE7DD0517B7654B8955CFDE578E055A2C71F9A51D184CA65553AFF3F1995FD3C`.
- Ordinary destructor: `[0x004e7290,0x004e72af)`, 31 bytes, three matching vptr stores and Pane tail transfer, SHA256 `CACDD06C35C6C88FCD078F5BE400AFB1BAFD0C40CDAA9D2F855154E3F6782915`.
- Guard stub: `0x0041b6a0` byte `c3`, SHA256 `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`.
- Negative IDA facts: no target-specific field access, no status buffer access, no owned pointer/resource operation, no singleton operation, no EH action, no loop, no direct ordinary caller, no code/data in neighboring `0xcc` gaps.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004e7290,0x004e72af)` | UID0004BY | Human ordinary destructor definition | True | UID00006I | `88/91` | Emit exact empty body; remove internal proof comment. |
| `0x004e71c0` | UID0004BX | Human constructor/layout control | True | UID00006I | `88/90` | Verify-only; no edit expected. |
| `[0x004e861e,0x004e8629)` | UID00018D subrange | Secondary destructor adjustor | False | None/index UID00018D | `85/90` aggregate | Compiler-only; add exact status row detail. |
| `[0x004e8629,0x004e8634)` | UID00018D subrange | Tertiary destructor adjustor | False | None/index UID00018D | `85/90` aggregate | Compiler-only; add exact status row detail. |
| `[0x004e8640,0x004e86bf)` | UID00031I | Candidate sibling scalar wrapper | Existing disposition | UID00006F | Existing | Fresh control only; has real candidate cleanup. |
| `[0x004e86c0,0x004e8715)` | UID00031J | Composition sibling scalar wrapper | False | UID00006G | `92/94` | Executed mechanism control; no target substitution/edit. |
| `[0x004e8715,0x004e8720)` | UID0000VN | Existing alignment | False/ignored | None | Existing | Already documented; unchanged. |
| `[0x004e8720,0x004e87f9)` | UID00031K | Root sibling scalar wrapper | Existing disposition | UID00006H | Existing | Fresh control only; has real child/singleton cleanup. |
| `[0x004e87f9,0x004e8800)` | UID0000VN addition | Seven-byte alignment | False/ignored | None | N/A | Add exact ignored entry. |
| `[0x004e8800,0x004e8855)` | UID00031L | Status scalar deleting wrapper | False | UID00006I | `92/94` | Reclassify non-emitting with blank formal. |
| `[0x004e8855,0x004e8860)` | UID0000VN addition | Eleven-byte alignment | False/ignored | None | N/A | Add exact ignored entry. |
| `0x004e8860` successor | UID0002MT | Candidate-string queue growth helper | Existing ignored/support | Existing | Existing | Separate function; unchanged. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061c364` | First primary-vtable slot -> `0x004e8800` | Primary ABI entry; no handwritten call required. |
| `0x0061c3b0` | First secondary-vtable slot -> `0x004e861e` | Secondary subobject route. |
| `0x0061c3e0` | First tertiary-vtable slot -> `0x004e8629` | Tertiary subobject route. |
| `0x004e8624` | Adjustor code xref to target | Tail route after `this -= 0xa0`. |
| `0x004e862f` | Adjustor code xref to target | Tail route after `this -= 0xa4`. |
| `0x004e8806/0c/16` | Three vptr writes | Most-derived lifecycle lowering. |
| `0x004e8820` | Call `0x00544580` | Inherited Pane teardown. |
| `0x004e8831` | Call `0x004f4ac0` | Normal scalar storage free only. |
| `0x004e8846` | Call `0x0041b6a0` after pushing `0x2f8,this` | Bit-4 compiler/runtime no-op branch. |
| Ordinary-call inventory | None | No normal source helper/caller route. |

## Documentation Evidence And IDA Status

- UID00031L now records the exact wrapper role, false/non-emitting/blank disposition, exact bytes/hash/CFG, object size, helper semantics, negative evidence, score rationale, source route, and superseded proof-comment history.
- UID0004BY separates ordinary from scalar destruction, records inline storage, exact vptr parity and Pane tail transfer, and now emits the literally empty source body with explanation kept only in documentation.
- UID0004BX and UID00006I establish `statusText[256]` at `+0xf8`, the three-vptr class layout, source declaration, and IMEPanes route. They do not show any derived destructor resource.
- UID00018C and UID00018D remain non-emitting index/glue pages at unchanged scores/metadata/formals; their status rows now carry the accepted target score, source/no-source split, exact thunk bytes/hashes/deltas/jump sites/vtable routes, and hidden ABI disposition.
- UID00025J already records the status vtable first-slot values and constructor/ordinary/wrapper stores. It is sufficient and remains verify-only.
- UID000197 and UID0001EA correctly identify the global delete wrapper and inherited Pane cleanup. They are dependencies, not source owners.
- Generated `IMEPanes.cpp` commands `000000012986`, `000000013011`, and `000000013036` are historical checkpoints. B004 waited command `000000013040`, SHA256 `842F165F...969DB`, proved one UID0004BY definition, zero UID00031L output, one clean status-field declaration, and no attached reverse-engineering comment; latest external command `000000013049`, SHA256 `3C94ED08...8B50`, preserves those facts. Historical commands `12947` and `12954` remain labeled as stale proof-route checkpoints.
- Current read-only manual coverage hashes after command `13040` are by-memory `9699D0900828A80C5B42A0537D68E26AC6DAFC7AD1504E2A351B28131AA9750C`, by-class `F637C4A9829A2E78C7FDF00ECEFC60A43655A655557473DB52B2C7FC5A68B716`, and by-file `F92470E137660A52DD7568768589D86117CBB1699453913F8B2E70449AEFE26D`. The accepted handoff remains supervisor-owned: target/class/aggregate/thunk/file rows are stale, UID0004BY and both padding rows are absent, and the exact replacement/addition text below remains current. Earlier hashes remain time-scoped checkpoints.
- IDA status: session `64c11373` was healthy when the recorded target evidence was collected. The earlier oversized request and client parser/schema errors were bounded and followed by successful narrow checks; no MCP-dependent item was left unresolved.

## Ranked Ownership Analysis

### 1. UID00006I IMEStatusPane semantic owner

- Evidence for: exact class vtables; constructor, ordinary destructor, and target vptr parity; status methods; inline field layout; primary/secondary/tertiary vtable routes; existing class/source route.
- Evidence against: UID00031L itself is not source-bearing. This affects emitter/reconstructable state, not semantic ownership.
- Decision: retain `CANONICAL_OWNER:00006I`; clear emission and mark false.

### 2. UID0000K5 IMEPanes source file

- Evidence for: all human `IMEStatusPane` declarations/definitions route to `NexusTK/input/IMEPanes.cpp`; class and ordinary destructor emit there.
- Evidence against: the file is broader than the class and should not become the direct semantic owner of an exact wrapper page.
- Decision: retain as indirect source root through UID00006I; never emit UID00031L itself.

### 3. UID00018C, UID00018D, UID00025J, UID0001EA, or UID000197

- Evidence for: each documents physical containment, adjustor routing, generated vtable data, inherited teardown, or storage release.
- Evidence against: none is the most-derived class whose layout caused the wrapper. Consumer/callee/containment relationships do not prove source ownership.
- Decision: reject as canonical owners. Preserve them as support/index/dependency evidence.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. Existing UID00006I -> UID0000K5 is exact.
- Likely full contents: existing `IMEStatusPane` class and methods, including one virtual destructor declaration and one empty ordinary definition.
- Candidate related items that belong: UID0004BY belongs as the source definition; UID00031L and two adjustors belong only as documentation of compiler output.
- Candidate related items rejected: no new deleting-destructor helper, runtime wrapper file, or compiler-glue source file.
- Standalone, narrow, or broad source-file inference: narrow class ownership within the existing IMEPanes source root.

## Source Placement

- Recommended source placement: `IMEStatusPane` class declaration and ordinary method definitions in `NexusTK/input/IMEPanes.cpp` through UID00006I/UID0000K5.
- Destructor source shape: one public `virtual ~IMEStatusPane();` declaration and one exact empty out-of-line definition from UID0004BY.
- Binary-only products: UID00031L scalar wrapper, UID00018D status adjustors, UID00025J vtables/RTTI, and adjacent alignment are emitted by compiler/linker from class layout and source declaration/definition.
- Rejected placement in Pane core: `0x00544580` is inherited cleanup, not the derived source owner.
- Rejected placement in MemoryMan: `0x004f4ac0` is global delete support selected by compiler flags.
- Rejected standalone compiler-support source: no human target body exists and no external source file is needed.
- Remaining placement uncertainty: none that affects callback. Original file basename/capitalization is already established by UID0000K5; only unavailable original formatting remains.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x004e8800,0x004e8855)`, one modeled 85-byte function, no internal padding/data/child.
- Predecessor: UID00031K ends exactly at `0x004e87f9`. `[0x004e87f9,0x004e8800)` is seven `0xcc` bytes, no function/data role, SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`.
- Successor: target ends exactly at `0x004e8855`. `[0x004e8855,0x004e8860)` is eleven `0xcc` bytes, no function/data role, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; UID0002MT begins at `0x004e8860`.
- Split decision: no target child, merge, boundary correction, or rename. Add only two ignored alignment entries.
- Reclassification: `RECONSTRUCTABLE:TRUE` -> `FALSE`; emitter `00006I` -> blank; proof-comment formal -> blank. Retain owner/path/range/title/UID/position blank/`Nested:0`.
- Parent/container impact: UID00018C remains a false/non-emitting mixed index; exact source children remain independent. UID00018D remains false/non-emitting compiler glue.
- `Nested` decision: `0` remains exact because UID00031L is an exact standalone address-sorted child row, not a container delta change.

## Negative Evidence Summary

- No instruction reads or writes `statusText[256]` or any status-specific field after vptr restoration.
- No heap member, child pane, IME handle, window handle, graphics object, string owner, queue, singleton, layer, dispatcher, or event resource is released by the target.
- No ordinary/direct source caller invokes the target. Its liveness is entirely primary vtable plus two adjustor routes.
- No unique target callee exists. All three callees are inherited or runtime/compiler support.
- No bit-4 source behavior exists: the callee is exactly one byte `ret`.
- No array loop, array cookie, element count, repeated destruction, or vector deleting behavior exists.
- No EH/unwind metadata path or constructor-failure cleanup is part of the function.
- No independent source signature is safe or needed. Hex-Rays' `(_DWORD *Block, char)` is decompiler ABI shape, not human source.
- No target proof comment belongs in generated C++; it creates output without source semantics.
- No rename/split/new file is supported; exact boundaries and descriptive name are already correct.
- No prior report supplies target evidence; all prior items are controls/leads and were revalidated directly.
- No consumer/callee with more xrefs overrides the class owner. Ownership follows the vtable/class cause, not helper use.

## IDA Rename / Type / Comment Recommendations

- Source-facing name: do not create `IMEStatusPane::ScalarDeletingDestructor`. Keep the documentation title as a descriptive binary artifact name only.
- Source-facing declaration: retain `virtual ~IMEStatusPane();` in UID00006I.
- Source-facing definition: UID0004BY now emits the literally empty ordinary destructor body supplied below.
- Hidden parameter: do not expose a `char`, `int`, `unsigned int`, flags enum, or delete-size argument in human source.
- Complete object size: document `0x2f8` / 760 as ABI/layout evidence, not a field or source constant.
- Comments: remove the target's generated proof comment and the comment inside the ordinary destructor formal body; preserve all proof in by-* prose.
- IDA DB: no rename/type/comment mutation is requested or authorized. Existing `sub_4E8800`/Hex-Rays types remain evidence inputs only.
- Items intentionally unchanged: constructor and class field types, vtable read-only data, Pane/delete helper pages, and sibling wrapper identities.

## First-Draft C++ Recommendation

- Eligible for target draft C++: no. UID00031L is non-source compiler ABI output.
- Exact Destination 1, UID00031L managed formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact Destination 2, UID0004BY managed formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMEStatusPane::~IMEStatusPane()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact Destination 3, UID00006I managed formal block, rebased from current bytes and preserving all unrelated declarations:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Pane;

class IMEStatusPane : public Pane
{
public:
    IMEStatusPane();
    virtual ~IMEStatusPane();

    void SetText(const wchar_t *text, int length);

protected:
    virtual bool OnIMEModeChange(const Event *event);
    virtual void OnPaintFrame();

private:
    wchar_t statusText[256];
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact Destination 4, UID00018C managed formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact Destination 5, UID00018D managed formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason this preserves exact behavior: the compiler generates vptr restoration, inherited base teardown, hidden deleting flags, storage release selection, adjustor thunks, vtables, and alignment from the class declaration and ordinary destructor. Handwriting those operations would duplicate or corrupt ABI behavior.
- Reason this matches plausible original source: a virtual class with only inline derived storage commonly has an explicitly declared, out-of-line empty destructor; no developer-authored scalar deleting pseudo-method exists in ordinary C++.
- Naming/style: preserve existing `IMEStatusPane`, destructor spelling, braces, declaration order, and class child insertion style. No decompiler labels enter source.
- Third-party import directive: not applicable. This is NexusTK class/compiler output, not embedded third-party static source.
- Exact no-code proof: all 28 target instructions are prologue/epilogue, three compiler vptr stores, inherited base teardown, hidden flag tests, global storage release, one-byte runtime stub call, and return-this mechanics. There is zero derived field/resource behavior; the human declaration and ordinary definition already represent the complete source cause. Therefore target formal content must be literally blank.
- Destination 3 source-clean proof: the field count/type remains exact, while `+0xf8` and bounded UTF-16 evidence stay in documentation prose only. Destination 3 and current UID00006I are newline-normalized byte-equal at SHA256 `09FA4AB0D0E6CA35741A2ABB6D79B90377D7F38DF4F8E4B11E2BFCB77C677248`; historical pre-correction class block hash was `52166BF3F6B1728143DD22BE11AE847B6E2199FF752E5CD3BA412B32E022501E`.

## Final Recommendation

- UID00031L: `92/94`, owner `00006I`, false, blank emitter, blank position, blank formal, `Nested:0`, exact range/path/title preserved.
- UID0004BY: `88/91`, owner/emitter/class route, true, path/range preserved; the comment-bearing formal was replaced with the exact empty definition and all binary/source-split evidence remains.
- UID00006I: `88/90`, exact complete class union, current-facing method/evidence rows, UID0004BY source definition, UID00031L false/non-emitting relationship, and historical score records are retained. Destination 3 source-clean removal of the `+0xf8` evidence comment is applied and verified.
- UID0000K5: `91/90` and existing formal/source order preserved; status inventory and generated expectation now state one ordinary destructor and zero UID00031L output.
- UID00018C: `86/91`, owner NONE, false, blank emitter/position/formal, `Nested:-4` preserved; the target row now carries complete compiler-wrapper/no-source evidence.
- UID00018D: `85/90`, owner NONE, false, blank emitter/position/formal, `Nested:0` preserved; the two status rows now carry exact thunk bytes/hashes/deltas/vtable routes and target false state.
- `by-memory/-ignored.md`: exact seven-byte prepad and eleven-byte postpad entries are present with hashes, adjacency, no-source disposition, replacement/procurement, and owner docs.
- Verify-only: UID0004BX, UID00025J, UID000197, UID0001EA, UID00031J, sibling wrapper pages, and successor UID0002MT remained unchanged; callback reread found no contradiction.
- No independent source item or implementation item remains. Manual coverage and report lifecycle state remain external supervisor/validator-owned boundaries.

## Recommended Target Doc Changes

- Callback status: all accepted target changes below are applied; the arrow notation preserves the audited pre/post transition rather than describing future work.
- Target path: `by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md`.
- Metadata: `86/90 -> 92/94`; retain owner `00006I`; `RECONSTRUCTABLE:TRUE -> FALSE`; `EMITTER_UIDS:00006I -> blank`; optional position remains blank; `Nested:0` retained.
- Formal: the four-line proof comment was replaced with exact Destination 1 blank managed block.
- Exact Item Summary value: `Exact 85-byte MSVC scalar deleting destructor wrapper for IMEStatusPane; three class-vptr restores, Pane teardown, hidden flags, MemoryMan-backed free or 0x2f8 one-byte no-op branch, primary/adjustor vtable liveness, and no independent human source body.`
- Status/Behavior: compiler-generated ABI output, semantic-owner/emission distinction, exact source cause, and ordinary destructor route are documented.
- Evidence: exact range/bytes/hash/signature/instruction/CFG data, target xrefs, vtable values/store parity, adjustor routes/hashes, helper roles, ordinary/constructor controls, sibling distinctions, and exact padding are incorporated.
- Negative/rejected evidence: zero direct callers, no field/resource cleanup, no human signature, no proof-comment output, no split/rename, and rejected helper/owner/array-delete alternatives are preserved and expanded.
- Score: stale `85/89` rationale was replaced by exact `92/94` rationale; old values remain only in explicitly historical Changes text.
- History: the 2026-06-08 creation and 2026-06-30 proof-comment callback remain historical states explicitly superseded by the target pass.

## Recommended Support Doc Changes

- Callback status: all accepted support prose and Destinations 2/3/4/5 are applied and scoped-validated. Destination 3 below is byte-equal to the current source-clean class block.
- `by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md` [UID0004BY]: preserve `88/91`, owner/emitter `00006I`, true, blank position, `Nested:0`, path/range, all exact binary and zero-xref caveat evidence. Apply Destination 2 exact empty formal. Update reconstruction/generated notes so UID00031L produces zero output, not a proof comment.
- `by-class/IMEStatusPane.md` [UID00006I]: `88/90`, owner/emitter `0000K5`, true, position 0, all declarations, children, links, target/source facts, and historical Changes values are preserved. Corrected Destination 3 is applied: only the reverse-engineering comment after `wchar_t statusText[256];` was removed, while `+0xf8` and bounded UTF-16 evidence remain in prose rather than formal C++.
- Exact current-facing class method rows:

```text
| `~IMEStatusPane` | [UID:0004BY][0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor](by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md) | `88/91`; exact empty source destructor definition. Binary restores three IMEStatusPane vptrs and tail-transfers to Pane teardown; UID00031L owns only compiler deleting-wrapper evidence. |
| `ScalarDeletingDestructor` | [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) | `92/94`; class-owned compiler ABI wrapper, non-reconstructable/non-emitting with blank formal C++. Primary and -0xa0/-0xa4 vtable routes reach it; it adds only hidden delete flags, MemoryMan-backed free, and the 0x2f8 no-op runtime branch. |
```

- `by-file/IMEPanes.md` [UID0000K5]: preserve `91/90`, source path/formal/order and unrelated family content. Update the status inventory/source-quality notes with UID0004BY source definition, UID00031L no-source classification, exact route, and expected zero target output.
- Exact replacement for the current status inventory row:

```text
| [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md) | exact `SetText` child [UID:0004BW][0x004e70f0-0x004e71bc.IMEStatusPaneSetText](by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md), exact emitting constructor [UID:0004BX][0x004e71c0-0x004e728a.IMEStatusPaneConstructor](by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md), exact empty source destructor [UID:0004BY][0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor](by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md), `0x004e70f0-0x004e737b`, non-emitting compiler scalar wrapper [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md), adjustor wrappers in [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md) | Bottom-right ENG/IME status label with one ordinary destructor source definition and no handwritten scalar-wrapper output. |
```

- `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` [UID00018C]: preserve `86/91`, NONE/false/blank metadata, `Nested:-4`, and Destination 4 blank formal. Replace stale `85/89` status row with exact `92/94` false/non-emitting evidence and preserve every sibling/helper row.
- Exact replacement for the UID00031L aggregate inventory row:

```text
| [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) | `IMEStatusPaneScalarDeletingDestructor` | `92/94`, class-owned by [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md) but `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal. Exact 85-byte compiler wrapper duplicates UID0004BY vptr/Pane teardown, enters through primary/`this-0xa0`/`this-0xa4` vtable routes, interprets hidden flags, uses normal MemoryMan-backed free or a one-byte no-op bit-4 path with complete size `0x2f8`, and emits no handwritten source. |
```

- `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` [UID00018D]: preserve `85/90`, NONE/false/blank metadata, `Nested:0`, Destination 5 blank formal, and all six non-status thunk rows. Add exact status thunk bytes/hashes/deltas/jump sites/vtable cells and UID00031L human-source route.
- Exact replacement rows for the two status adjustors:

```text
| `0x004e861e-0x004e8629` | `IMEStatusPane` | [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) | Exact bytes `81 e9 a0 00 00 00 e9 d7 01 00 00`, SHA256 `6D51F020E447863B5AE66A0249F1EE8BB0EE38BDD706F1FCA9A1EEFDDC21A3E0`; subtracts `0xa0` / 160 from `ECX` and tail-jumps from `0x004e8624` to non-emitting UID00031L. First vtable entry is `0x0061c3b0`. |
| `0x004e8629-0x004e8634` | `IMEStatusPane` | [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) | Exact bytes `81 e9 a4 00 00 00 e9 cc 01 00 00`, SHA256 `EE7DD0517B7654B8955CFDE578E055A2C71F9A51D184CA65553AFF3F1995FD3C`; subtracts `0xa4` / 164 from `ECX` and tail-jumps from `0x004e862f` to non-emitting UID00031L. First vtable entry is `0x0061c3e0`. |
```

- `by-memory/-ignored.md` [UID0000VN]: add only the two exact padding entries from C31L-031/C31L-032 near the existing IME wrapper alignment entries; preserve all existing entries.
- Exact ignored entry 1:

```text
- `0x004e87f9-0x004e8800` - seven-byte alignment between the root IME-pane and status-pane scalar deleting wrappers.
  - Why ignored: exactly seven `0xcc` compiler/linker alignment bytes after [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) and before [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md); the span has no modeled function, branch target, data role, or source behavior.
  - Evidence: B004 2026-07-15 bounded IDA MCP byte/function review on database `64c11373` confirmed the exact half-open span, adjacent function boundaries, seven bytes `cc cc cc cc cc cc cc`, and SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`.
  - Replacement/procurement: no source replacement; let the compiler/linker regenerate alignment before the next compiler scalar-deleting-wrapper body.
  - Owner docs: [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md), [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md), [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md), [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
```

- Exact ignored entry 2:

```text
- `0x004e8855-0x004e8860` - eleven-byte alignment between the status-pane scalar deleting wrapper and CandidateStringQueue reserve helper.
  - Why ignored: exactly eleven `0xcc` compiler/linker alignment bytes after [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) and before [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md); the span has no modeled function, branch target, data role, or source behavior.
  - Evidence: B004 2026-07-15 bounded IDA MCP byte/function review on database `64c11373` confirmed the exact half-open span, adjacent function boundaries, eleven bytes `cc cc cc cc cc cc cc cc cc cc cc`, and SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
  - Replacement/procurement: no source replacement; let the compiler/linker regenerate alignment before the next standard-library helper body.
  - Owner docs: [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md), [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md), [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md), [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
```

- Verify-only pages: UID0004BX constructor SHA256 `C1B3853F0C3BD9DF7CB28B385BA92FC2C7375B6B8C39F1207500B66CD1EAC0C7`; UID00025J vtable data SHA256 `AE927672EEEC0A576DD6101EF2B8B91A6F21BE8CDDD16C093FAE07BA81A2107A`; UID000197 SHA256 `1EB0C5E970BFCF6F4C6664918137EAF094E76BAAF2019D272948631DD660F7F1`; UID0001EA SHA256 `D118C5B2EF39D35359C57003DB2593FCD87CAB3B3111293AE3466DC0EA4EE5E6`.
- No support score changes were applied. Target-specific synchronization did not inflate broader class/file/aggregate/thunk scores or alter unrelated formal C++.

## Score And Metadata Recommendation

- Historical pre-callback target: header `86/90`, owner/emitter `00006I`, true, blank position, proof comment, `Nested:0`; stale internal/manual values `85/89` and `85%`.
- Current implemented target: `92/94`, owner `00006I`, false, blank emitter/position/formal, `Nested:0`, exact path/range/title retained.
- Completion 92 rationale: exact range, full bytes/hash/signature, 28-instruction behavior, CFG, receiver/hidden flags, all helper branches, complete size, returns, liveness, vtable/adjustor routes, constructor/ordinary parity, source definition, sibling controls, generated consequence, padding, source placement, support edits, manual coverage text, no-code proof, validators, and generated equivalence are resolved. It remains below 95 because original source/toolchain exactness is unavailable.
- Confidence 94 rationale: mutually reinforcing direct evidence leaves no credible competing source disposition. It remains below 95 because no original symbol/PDB/source and no exact compiler build-switch proof exists.
- Score-improvement attempt:
  - Range blocker: resolved by target/successor lookup and exact bytes/padding.
  - Source-body blocker: resolved through full instruction audit and ordinary/constructor parity.
  - Hidden-ABI blocker: resolved through stack slot, AL tests, return shape, and sibling wrappers.
  - Helper blocker: resolved by Pane, MemoryMan delete, and one-byte no-op analyses.
  - Liveness blocker: resolved by exact primary/adjustor vtable routes and negative ordinary caller check.
  - Ownership/emitter blocker: resolved by semantic-owner/output-route separation in `by-structure.md`.
  - C++ blocker: resolved by exact target blank block and exact empty ordinary source definition.
  - Padding/split blocker: resolved by exact hashes and successor boundary.
  - Generated blocker: resolved by current readback and precise zero-target output expectation.
  - Prior-report blocker: resolved by concrete active/executed/Older/Special/archive searches and fresh target reanalysis.
- Support metadata: all support scores/owners/reconstructable/emitter/position/Nested values remain unchanged except current-facing prose and UID0004BY formal comment removal.

## Open Questions With Attempted Resolution

- Is the hidden argument a `char` or four-byte flags word? The stack slot and `ret 4` prove four bytes are consumed; AL-only use explains Hex-Rays `char`. Resolution: compiler ABI detail, excluded from source either way.
- Is bit 4 array-delete behavior? No element loop/cookie/count exists, and the exact callee is one byte `ret`. Resolution: guarded compiler/runtime size/no-free branch, not source array deletion.
- Does `0x2f8` identify a source allocation request? It is passed only on the hidden bit-4 branch after teardown and matches complete layout scale. Resolution: document complete-object size evidence, not a source constant or allocation call.
- Does zero ordinary call routing invalidate the source destructor? No. The distinct ordinary body, class declaration, constructor/vtable parity, and deleting-wrapper route establish an out-of-line source destructor. Zero xrefs remains a reachability caveat.
- Should UID00031L keep a proof comment? Generated readback proves the comment appears as source despite no body. Resolution: false/no-emitter/blank formal; proof stays in docs.
- Should UID0004BY keep an explanatory comment inside its empty body? No source action corresponds to it. Resolution: literally empty body, with explanation retained in documentation.
- Could UID00031L own cleanup omitted by decompiler? Full 85-byte disassembly contains no additional read/write/call and exact bytes are closed. Resolution: no.
- Should the wrapper be renamed, merged, or split? Exact descriptive identity and boundaries are already correct. Resolution: retain.
- Should UID00031J determine this result? No. It is only a mechanism control; all UID00031L-dependent checks were repeated directly. Resolution: direct evidence is independently sufficient.
- Remaining unresolved question: exact original compiler-generated symbol spelling/build switches and whitespace cannot be recovered without PDB/source/build records. This does not affect ownership, no-source disposition, score direction, or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only comparison history: the original report recorded `by-memory/-coverage-report.md` SHA256 `9B41FBD009EFE1D56BB92E699F949DFE331282F6B3636BF010A681711E0D8B90`; the supervisor's `2026-07-15T08:00:26-04:00` audit observed `8412C89F4DBD8F7E30B6B55FEC15A579F38A8CC0C76C162DCE134E61584B5102`; intermediate snapshots included `B920D2FB...F4313`, `3A060E53...561F4`, and `540A00B2...B76B`. The historical post-callback read-only rebase after external command `000000013011` observed by-memory `4CB628D1...24B1`, by-class `53094F85...855F`, and by-file `788CACC9...B22E`; the latest post-command-`000000013040` rebase observed by-memory `9699D0900828A80C5B42A0537D68E26AC6DAFC7AD1504E2A351B28131AA9750C`, by-class `F637C4A9829A2E78C7FDF00ECEFC60A43655A655557473DB52B2C7FC5A68B716`, and by-file `F92470E137660A52DD7568768589D86117CBB1699453913F8B2E70449AEFE26D`. The affected rows remain at lines 1823/1831/1834/1838 and class/file lines 259/122; UID0004BY and both exact padding rows remain absent. Every exact addition/replacement below therefore remains correctly rebased. Whole-file hashes are time-scoped evidence; any later supervisor-owned coverage application must reread rows rather than assume a durable global hash.
- The following text is exact supervisor-owned handoff text. B004 must not apply it directly.

File/placement: `by-memory/-coverage-report.md`, add immediately after the UID000189 parent row's existing UID0004C2 child row:

```text
        - [UID:0004BY][0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor](by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md) 0x004e7290-0x004e72af | ordinary destructor | IMEStatusPane::~IMEStatusPane : reconstructable : 88% : very-strong : Exact empty source destructor definition; the 31-byte binary restores three IMEStatusPane vptrs and tail-transfers to Pane teardown, while UID00031L owns only non-emitting compiler deleting-wrapper evidence.
```

File/placement: `by-memory/-coverage-report.md`, replace the complete UID00018C row:

```text
    - [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md) 0x004e8450-0x004e8ae6 | reviewed mixed aggregate/index | IMECandidateQueueAndDestructors : not_reconstructable : 86% : very-strong : Broad index over exact IME source cleanup children, compiler scalar-deleting wrappers, compiler adjustor thunks, ignored STL deque/wstring helpers, and padding; UID00031J and UID00031L are class-owned compiler output whose human sources are UID0004C2 and UID0004BY respectively, while live IDA confirms all boundaries and InputMan alignment.
```

File/placement: `by-memory/-coverage-report.md`, replace the complete UID00018D row:

```text
        - [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md) : ignored : 85% : very-strong : Eight compiler-generated secondary/tertiary destructor adjustor thunks for four IME pane classes; composition and status pairs subtract 0xa0/0xa4 and jump to non-emitting UID00031J/UID00031L. No handwritten NexusTK source body is emitted.
```

File/placement: `by-memory/-coverage-report.md`, insert immediately before the UID00031L target row:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004e87f9-0x004e8800 | padding | IMEPane to IMEStatusPane scalar deleting wrapper alignment : ignored : 100% : strong : Confirmed seven 0xcc compiler/linker alignment bytes, SHA256 F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D.
```

File/placement: `by-memory/-coverage-report.md`, replace the complete UID00031L row:

```text
        - [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) 0x004e8800-0x004e8855 | compiler-generated scalar deleting destructor wrapper | IMEStatusPaneScalarDeletingDestructor : not_reconstructable : 92% : very-strong : Exact 85-byte MSVC wrapper, SHA256 36DB541414B33304808CE4E9E26E9EF5CA275766ACE5125F3C6ED2874F5716E2; primary vtable plus -0xa0/-0xa4 adjustor entries reach it, it duplicates UID0004BY vptr/Pane teardown, bit 1 selects MemoryMan-backed operator delete, and bit 4 reaches the one-byte no-free runtime stub with complete size 0x2f8. Human source is the single virtual IMEStatusPane destructor in UID0004BY; UID00031L remains class-owned but non-emitting with blank formal C++.
```

File/placement: `by-memory/-coverage-report.md`, insert immediately after the UID00031L row and before UID0002MT:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004e8855-0x004e8860 | padding | IMEStatusPane scalar deleting wrapper to CandidateStringQueueReserveAdditional alignment : ignored : 100% : strong : Confirmed eleven 0xcc compiler/linker alignment bytes, SHA256 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943.
```

File/placement: `by-class/-coverage-report.md`, replace the complete UID00006I row:

```text
- [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md) : reconstructable : 88% : very-strong : IME status-label pane attached to IMEPanes with exact SetText/constructor/mode-change/paint source bodies, one empty ordinary destructor definition in UID0004BY, exact non-emitting compiler scalar wrapper UID00031L, three-vtable/adjustor evidence, inline statusText[256], and complete class/file source routing.
```

File/placement: `by-file/-coverage-report.md`, replace the complete UID0000K5 row:

```text
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md) : reconstructable : 91% : very-strong : NexusTK/input/IMEPanes.cpp source root with complete status/composition/candidate/root pane ordering, g_pIMEPane singleton, exact source destructor and helper routes, candidate-string STL/template caveats, and explicit compiler-wrapper exclusions; UID0004C2 and UID0004BY emit the composition/status ordinary destructors while UID00031J and UID00031L remain non-reconstructable/non-emitting binary evidence with no generated marker or body.
```

- Tracker text: no manual tracker edit is proposed. Validator commands `000000012980` and `000000012986` refreshed generated state from ordinary metadata; external commands `000000013011` and `000000013036` are historical; B004's authorized waited checkpoint is `000000013040`, and latest external read-only checkpoint `000000013049` preserves its semantics. B004 did not write an auto-generated row.
- Reason B004 must not apply coverage text directly: manual `-coverage-report.md` files and report lifecycle/coverage synchronization are supervisor-owned by explicit assignment and workflow restrictions.

## Follow-Up Actions

- Implementation and verification boundary: C31L-001 through C31L-040 are terminal as recorded. Destinations 1-5, all seven original ordinary destinations, the bounded UID00006I correction, scoped/waited validators, formal equality, generated readback, and lease release are complete; no implementation item remains.
- Supervisor-owned boundary: exact-artifact validation, independent callback verification, manual coverage application, report execution, count, path, move, and archive state are external supervisor/validator-owned and are neither asserted nor directed by this artifact.
- B004 waited command `000000013040` proves exactly one empty UID0004BY definition, zero UID00031L marker/name/body/`Empty Emitter Marker` or explicit wrapper mechanics, exactly one source-clean `wchar_t statusText[256];`, and no `+0xf8`/bounded-evidence comment attached to that field. Latest external read-only command `000000013049` preserves the same facts; commands `12986`, `13011`, and `13036` remain historical checkpoints.
- Manual coverage remains an external handoff only. The exact text under `Exact Manual Supervisor-Owned Coverage Or Tracker Text` is preserved and current read-only hashes are recorded; B004 made no manual coverage edit.
- A-agent actions: none. No IDA mutation or new split is requested.
- Future B004 research: none in scope. Exact compiler symbol/build formatting is non-actionable without external source/PDB/build artifacts and does not block implementation.

## Confidence

- Recommendation confidence: `94/100` equivalent. Direct target-specific binary and source-route evidence is mutually reinforcing.
- Score confidence: high. `92/94` reflects exhaustive target evidence and the completed target/no-code callback while preserving a cap for unavailable original source/toolchain; the bounded class-comment cleanup does not change the score.
- Range/split confidence: effectively exact; modeled boundaries and all adjacent bytes are known.
- Owner/source-placement confidence: very high; status vtables and existing class/file route are unambiguous.
- No-code confidence: very high; no target-specific source operation exists, and the human source cause is fully represented elsewhere.
- Remaining uncertainty: original source whitespace/comment choices, exact compiler-generated symbol spelling, and build switches only.

## Validator Results

- Every command below ran from `source-3/project-documentation` with `--mode file --file <path> --apply --queue-timeout 240`; exit and `ok` are exact validator results. Commands through `12986` are historical original-callback evidence; current bounded-correction commands are `13039` and `13040`. The intervening report-only Gate 1 repair ran no validator or generated refresh.

| Command | Timestamp | Destination / role | Exit / ok | Warnings and side effects |
| --- | --- | --- | --- | --- |
| `000000012970` | `2026-07-15T08:15:51-04:00` | UID00031L initial scoped validation | `0 / 1` | No warning; completion/confidence, true->false, emitter clear, block->blank, registry/hash and one validator-managed UID000197 link update; projected stats; generated deferred. |
| `000000012971` | `2026-07-15T08:16:49-04:00` | UID0004BY initial scoped validation | `0 / 1` | No warning; formal registry hash update, projected stats; generated deferred. |
| `000000012972` | `2026-07-15T08:17:44-04:00` | UID00006I initial scoped validation | `0 / 1` | No warning; UID0004BY reference-index add, projected stats; generated deferred. |
| `000000012974` | `2026-07-15T08:18:35-04:00` | UID0000K5 scoped validation | `0 / 1` | No warning; UID0004BY reference-index add, projected stats; generated deferred. |
| `000000012976` | `2026-07-15T08:19:32-04:00` | UID00018C scoped validation | `0 / 1` | No warning; projected stats; generated deferred. |
| `000000012977` | `2026-07-15T08:20:27-04:00` | UID00018D scoped validation | `0 / 1` | No warning; UID00031L/UID0004BY reference-index adds, projected stats; generated deferred. |
| `000000012979` | `2026-07-15T08:21:18-04:00` | `by-memory/-ignored.md` scoped validation | `0 / 1` | `missing_ref_uid:277`, pre-existing unrelated aggregate warnings (first ten listed by validator, 267 suppressed); UID00031L reference-index add, projected stats; generated deferred. No target-specific warning. |
| `000000012980` | `2026-07-15T08:21:40-04:00` | First authorized waited UID00031L refresh | `0 / 1` | Generated completed; registry rebuild, tracker/projected stats and generated metadata refresh; unrelated project-wide fallback/missing-marker/no-code diagnostics. Generated semantic assertions passed. |
| `000000012982` | `2026-07-15T08:24:17-04:00` | UID00031L exact ordinary-hash transcription repair | `0 / 1` | No warning; projected stats; generated deferred. |
| `000000012984` | `2026-07-15T08:24:53-04:00` | UID0004BY exact ordinary-hash transcription repair | `0 / 1` | No warning; projected stats; generated deferred. |
| `000000012985` | `2026-07-15T08:25:30-04:00` | UID00006I exact ordinary-hash transcription repair | `0 / 1` | No warning; projected stats; generated deferred. |
| `000000012986` | `2026-07-15T08:25:44-04:00` | Final authorized waited UID00031L verification | `0 / 1` | Generated completed; 4,970-node/4,004-edge registry rebuild, 281 generated metadata refreshes, projected stats; unrelated project-wide fallback/missing-marker/no-code diagnostics only. |
| `000000013039` | `2026-07-15T09:05:30-04:00` | Bounded UID00006I source-clean scoped validation | `0 / 1` | No warning; formal registry hash `8978A632...5438E -> 423D6AE9...149F`, projected stats, generated deferred. Lease released immediately afterward with leaser `Success`. |
| `000000013040` | `2026-07-15T09:05:52-04:00` | Final authorized waited UID00006I verification | `0 / 1` | Generated completed; 4,970-node/4,003-edge registry rebuild, 280 generated metadata refreshes, projected stats; unrelated project-wide fallback/missing-marker/no-code diagnostics only. |

- Historical B004 target waited readback: `auto-generated/NexusTK/input/IMEPanes.cpp`, validator header `000000012986`, refreshed `2026-07-15T08:25:44-04:00`, 20,636 bytes, 651 physical lines, SHA256 `9B56DBC6D64521BC768E61C1E6ADD6B1B1C13912009D1639B2691567BEA26421`.
- Historical subsequent generated readback: external validator header `000000013011`, refreshed `2026-07-15T08:35:25-04:00`, 20,636 bytes, 651 physical lines, SHA256 `5E1ADF269D2AF9BC0E17D10DB4B007333ECC8C43B540DC90C3BA3E0612B0FBE9`; target/no-code assertions remained identical, but source cleanliness was not established.
- Historical pre-correction generated readback: external validator header `000000013036`, refreshed `2026-07-15T08:49:16-04:00`, 20,636 bytes, 651 physical lines, SHA256 `A0E091A3DBA8DB1198D54F7BA97F758DD70A9B3BA785C9BA8A3E3A547643D82B`; one exact empty UID0004BY destructor, zero UID00031L marker/name/body/`Empty Emitter Marker`, and the invalid `+0xf8` field comment at line 550.
- B004 authorized waited generated readback: validator header `000000013040`, refreshed `2026-07-15T09:05:52-04:00`, 20,591 bytes, 651 physical lines, SHA256 `842F165F27BC0D351470A12168334567575228CD38E346DBB5C1D2F65BB969DB`.
- Latest external read-only generated readback: validator header `000000013049`, refreshed `2026-07-15T09:14:29-04:00`, 20,591 bytes, 651 physical lines, SHA256 `3C94ED08E1FFC24038F5C67672B1887867156583A010414E0BA14D8B26C77850`; all positive, negative, and source-clean counts below are unchanged.
- Positive generated count: `IMEStatusPane::~IMEStatusPane()` = 1, with exact literally empty body at lines 596-598 and UID0004BY marker at line 595.
- Negative generated counts: `UID:00031L` = 0; `IMEStatusPaneScalarDeletingDestructor` = 0; target proof-comment phrase = 0; `Empty Emitter Marker` = 0; hidden-flags names = 0; `0x2f8`/`760` = 0; target vptr constants = 0; `Pane::~Pane` = 0; delete/no-op helper spellings = 0; adjustor source spellings = 0.
- Source-clean generated field count: exact standalone `wchar_t statusText[256];` = 1 at line 550; field-attached `+0xf8`/`bounded UTF-16` comment = 0. Unrelated evidence comments on other class fields remain outside this bounded correction.
- All five destinations are newline-normalized byte-equal to their ordinary pages. SHA256 values: Destination 1 `CA40B93B6569C6F5127EE922903894943A86E38CB071968DB2A2260DC2E3F396`; Destination 2 `F02EE46A384115BAB790B3B26EA147738FE1CC903B8D40E37F797B6FEE9038D8`; Destination 3 `09FA4AB0D0E6CA35741A2ABB6D79B90377D7F38DF4F8E4B11E2BFCB77C677248`; Destinations 4 and 5 each `CA40B93B6569C6F5127EE922903894943A86E38CB071968DB2A2260DC2E3F396`.
- MCP transport notes remain historical research evidence: one oversized batch timeout and two client parser/schema errors were followed by successful bounded health/lookup/bytes and narrow target calls; no evidence item remains blocked.

## Changed Files

- Modified in this bounded callback: `by-class/IMEStatusPane.md` and this same report only. All research, headings, target/no-code decisions, Destinations 1/2/4/5, manual coverage handoff, exact evidence, rejected alternatives, validator history, and unrelated ordinary content remain preserved.
- Modified UID00031L: pre `BBCA9AFD...C249` -> post `AC99EDE9...BBA5`; metadata/formal/no-code/evidence/score/history applied; validators `12970`, `12982`, final `12986`.
- Modified UID0004BY: pre `E0CE43FF...C892` -> post `46DB40E0...567E`; exact literally empty formal and current wrapper/generated evidence; validators `12971`, `12984`.
- Bounded UID00006I correction: page SHA256 `7AFDEB91DFA52F8031BA2A4D83A30A33851581D933B7E9C91B0303B686892722 -> 8FF5531908C89883F75B654AC723428F78BCDF3EE542D9A25FC34D20820C29CE`; formal SHA256 `52166BF3F6B1728143DD22BE11AE847B6E2199FF752E5CD3BA412B32E022501E -> 09FA4AB0D0E6CA35741A2ABB6D79B90377D7F38DF4F8E4B11E2BFCB77C677248`. Only the formal field comment was removed; prose line retaining `+0xf8` evidence remains.
- Modified UID0000K5: pre `EACA4272...256D` -> post `F77ACD5A...6B76`; complete source-family union preserved, status inventory/generated contract synchronized; validator `12974`.
- Modified UID00018C: pre `84525504...70F1` -> post `13B7BADA...AC50`; `86/91` false/blank state and all siblings preserved, exact status row/evidence synchronized; validator `12976`.
- Modified UID00018D: pre `19BCF3F1...7D2B` -> post `0D130DC5...4803`; `85/90` false/blank state and six other rows preserved, exact status thunk rows/evidence synchronized; validator `12977`.
- Modified `by-memory/-ignored.md`: pre `DF9E253D...2106` -> post `133C5FFD...1EE5`; only the two exact accepted padding records were added; validator `12979`.
- Verify-only and unchanged: UID0004BX `C1B3853F...C0C7`; UID00025J `AE927672...107A`; UID000197 `1EB0C5E9...7F1`; UID0001EA `D118C5B2...E5E6`; UID00031J `5562B4E9...78E4`; UID00031I `774A1807...8551`; UID00031K `503D430D...9FFE`; UID0002MT `8FB2B9F8...4C90`. No contradiction required scope expansion.
- Modified other ordinary/restricted/manual-coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/IDA files manually: none. Generated changes came only from authorized validator command `13040`; B004 did not edit generated output.
- Renamed: none.
- Lease proof: historical callback leases remain as recorded. For this bounded callback, only `by-class/IMEStatusPane.md` was leased immediately before reread/edit, scoped-validated by command `13039`, and immediately unleased with leaser `Success`; final waited command `13040` ran after release. Current `current_leases.md` contains no B004 row.
- Report execution: not run. B004 ran no execute, dry-run, probe, count, revalidation, registry, move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor exact-artifact Gate 1 accepted SHA256 `DB96F89A7F00B3C1FC402E045B4C3850FABB19A9C543E4D5176F2E4CFD3DE564` before implementation.
- [x] UID00031L was reread after its short lease; callback-start hash `BBCA9AFD...C249` matched the accepted baseline and concurrent facts were preserved.
- [x] Exact range, bytes, `36DB...16E2` hash, signature, 28-instruction/five-block CFG, prepad, postpad, and successor are present in UID00031L.
- [x] Complete receiver/hidden-flags/return-this ABI is documented in UID00031L without human-source exposure.
- [x] Three vptr stores and constructor/ordinary parity are incorporated as compiler-lowering evidence in UID00031L/UID00006I/UID0004BY.
- [x] Pane teardown, MemoryMan-backed free, and one-byte bit-4 no-op helper roles are incorporated in UID00031L.
- [x] Primary/secondary/tertiary vtable liveness and exact two-adjustor routes are incorporated in UID00031L/UID00018D.
- [x] Candidate/composition/root sibling controls are retained as controls only; their verify-only pages remained unchanged.
- [x] UID00031L is `92/94`, owner `00006I`, false, blank emitter/position/formal, `Nested:0`; validators `12970`/`12982`.
- [x] Destination 1 equals report hash `CA40...F396`; final command `12986` proves the proof comment is absent.
- [x] Destination 2 equals report hash `F02E...38D8`; UID0004BY remains `88/91` with complete binary evidence; validators `12971`/`12984`.
- [x] Applied the one-page UID00006I class-formal correction under a short lease: preserved the complete union and changed only the field line to `wchar_t statusText[256];`, matching Destination 3 hash `09FA...7248`.
- [x] Scoped-validated `by-class/IMEStatusPane.md` while leased with command `13039`, timestamp `2026-07-15T09:05:30-04:00`, `exit 0 / ok 1`; score, metadata, source route, unrelated declarations, children, prose, and historical Changes content remained intact.
- [x] UID0000K5 status inventory/generated expectation is synchronized without score/source-order changes; validator `12974`.
- [x] Destination 4 equals report hash `CA40...F396`; UID00018C remains `86/91`, false/blank, with every sibling preserved; validator `12976`.
- [x] Destination 5 equals report hash `CA40...F396`; UID00018D remains `85/90`, false/blank, with six other rows preserved; validator `12977`.
- [x] `[0x004e87f9,0x004e8800)` exact ignored entry is present with bytes/hash/owners; validator `12979`.
- [x] `[0x004e8855,0x004e8860)` exact ignored entry is present with bytes/hash/owners; validator `12979`.
- [x] UID0004BX, UID00025J, UID000197, UID0001EA, UID00031J, sibling wrappers, and UID0002MT were reread/hashed verify-only; no contradiction or scope expansion occurred.
- [x] Historical target proof-comment and old-score states remain only in explicitly historical report/page Changes text.
- [x] Negative evidence and rejected helper/owner/split/array-delete/proof-comment alternatives remain at report-level detail.
- [x] No target rename, split, new child, source file, IDA edit, or third-party import applies; none occurred.
- [x] Proved all five managed destination blocks newline-normalized byte-equal to the report blocks; Destination 3 now equals `09FA...7248` and the other four hashes remain unchanged.
- [x] Every exact manual coverage row remains preserved as supervisor-owned handoff; current rows/hashes were reread and no manual coverage file was edited.
- [x] Each of the seven changed ordinary pages passed a scoped validator while leased; exact commands/results are recorded.
- [x] Ran authorized final waited command `13040`, timestamp/header `2026-07-15T09:05:52-04:00`, `exit 0 / ok 1`; generated SHA `842F...69DB`, 20,591 bytes, 651 lines, one empty UID0004BY definition, and zero UID00031L output/mechanics.
- [x] Every command ID/timestamp/exit/ok/warning/side effect, pre/post hash, generated hash, and lease release is recorded.
- [x] C31L-001 through C31L-040 have legal terminal verification states and destination proof without research compression; C31L-033 is applied.
- [x] Reconciled Current Target State, C31L-033, Validator Results, Changed Files, formal equality, generated proof, and lifecycle wording to terminal callback truth after the bounded correction.
- [x] Wave2/Wave3 mentions remain explicitly historical/stale and did not drive implementation.
- [x] No manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, archive, or IDA file was edited manually; generated/state side effects came only from authorized validators.
- [x] Proved generated `IMEPanes.cpp` contains exactly one standalone `wchar_t statusText[256];` with zero field-attached `+0xf8`/bounded-evidence comment while preserving all target/no-code and sibling assertions.
- [x] Released the UID00006I lease immediately after scoped command `13039`; leaser returned `Success`, waited command `13040` ran after release, and zero B004 lease rows remain.

Implementation callback pass:

- [x] Supervisor accepted the exact pre-callback report SHA listed above and authorized implementation.
- [x] UID00031L metadata/formal/prose is fully applied; validators `12970`/`12982`, waited `12986`; every target lease was released.
- [x] UID0004BY exact empty source destructor is fully applied; validators `12971`/`12984`; every lease was released.
- [x] Historical UID00006I callback preserved the class union and validated support text through `12972`/`12985`; bounded command `13039` removed only the field comment and preserved the full union/prose.
- [x] UID0000K5 bounded status/file route update passed `12974`; its lease was released.
- [x] UID00018C bounded aggregate update passed `12976`; its lease was released.
- [x] UID00018D bounded thunk update passed `12977`; its lease was released.
- [x] `by-memory/-ignored.md` two exact additions passed `12979`; its lease was released.
- [x] Current ledger is internally exact and fully terminal: 40 `applied`, 0 `proposed`, 0 `blocked`; retained/already-present actions and the supervisor-owned coverage exclusion remain explicit in their Action/destination-proof cells.
- [x] Historical commands `12986`, `13011`, and `13036` preserve target/no-code history; B004 waited command `13040` (`842F...69DB`) proves target/no-code assertions and source-clean field emission, and latest external read-only command `13049` (`3C94...8B50`) preserves them.
- [x] Manual supervisor-owned coverage handoff remains exact and external coverage state/hashes are described truthfully.
- [x] All accepted research, exact hashes, history, negative evidence, and rejected alternatives remain at report-level detail.
- [x] All leases were released; current lease report contains zero B004 rows.
- [x] B004 lifecycle boundary confirmed: no `execute_report`, probe, count, revalidation, registry, move, or archive command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000013057","destination_path":"executed-b-agent-research/B004/00031L-IMEStatusPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00031L-IMEStatusPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-15T09:28:28-04:00","uid":"00031L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
