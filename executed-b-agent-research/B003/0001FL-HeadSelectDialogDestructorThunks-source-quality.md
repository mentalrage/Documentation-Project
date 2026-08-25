** TARGET-REPORT-UID:0001FL **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0001FL HeadSelectDialog Destructor Thunks Source-Quality Research


## Finalized Report / Current Recommendation

- Callback status: exact report artifact SHA `86FCF9B78D0F7ABDC31B3EFEA30F1D76C6DC32B6F50B6F700102C7A359CD0683` passed supervisor Gate 1 under audit `B003 UID0001FL Exact-Artifact Gate 1 Final Reaudit - 2026-07-26T00:20:09-04:00`; the accepted ordinary-document implementation callback is now applied and scoped validation is complete. Supervisor Gate 2A verification, Gate 2B IDA closure, manual coverage application, and report execution remain pending.
- Current recommendation: retain [UID:0001FL] as a reconstructable, class-owned, source-declared/generated-binary MSVC destructor-support range under [UID:000062] `HeadSelectDialog`.
- Final disposition now applied: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:000062`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000062`; formal no-duplicate compiler-generation comment in CPP; blank target H because this exact executable range contains no independent header declaration.
- Applied source action: [UID:000062] now declares `virtual ~HeadSelectDialog();`, [UID:0001FI] emits the ordinary destructor with supported inherited `OnDestroy()` and `OnHide()` calls, and UID0001FL documents compiler regeneration without duplicate hand-authored ABI code.
- Required binary-analysis action: supervisor Gate 2B should create the exact `HeadSelectDialog` UDT, rename/retype/comment the constructor, ordinary destructor, two inherited-facet adjustors, deleting wrapper, and two shared `DialogPane` virtuals listed below. The B agent remains read-only and has not changed IDA.
- Confidence: very strong for range, behavior, vtable routing, complete object size/layout, ownership, and source declaration/body route; strong for inferred human source spellings where no PDB survives.

## Supporting Research

- Historical report-only origin: this artifact began as a new report-only pass for tracker row [UID:0001FL]. Gate 1 later accepted the report, and the current artifact now records the completed ordinary-document callback; it is still not a lifecycle/execution artifact.
- Historical pre-callback page state classified the range directionally correctly but stopped at an empty emitter and carried stale blockers: unresolved `DialogPane` helper names, no destination-ready class declaration, no formal covered-by marker, and an outdated description of the `flags & 4` path. The callback corrected each item.
- Live IDA MCP database session `f085b224` remained healthy under the supervisor override. `server_health` returned `status:ok`, `hexrays_ready:true`, and a live NexusTK IDB; bounded lookup, byte, xref, comment, type, disassembly, and decompile queries all succeeded. `auto_analysis_ready:false` was recorded as context and did not block the live reads.
- Matching historical report search terms were `UID:0001FL`, `0x005538fe`, `HeadSelectDialogDestructorThunks`, and `HeadSelectDialog.*ScalarDeleting`. Relevant leads were the executed B001 UID0001FI report and the B015 ObjectImageButtonPane thunk report. Their claims were rechecked against the current IDB and current docs; stale offline-MCP and old policy conclusions were not copied forward.
- Stale Wave2/Wave3 references in current guidance/old pages were ignored as required. No Wave2/Wave3 output was used as evidence.

## Target

- Target UID: `0001FL`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0001FL] `by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md`, the exact class-specific destructor adjustor/padding/deleting-wrapper range.
- Target path: `by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md`.
- Report path: `tools/leaser/Agents/Agent-B003/research/0001FL-HeadSelectDialogDestructorThunks-source-quality.md`.
- Historical source queue/report row at assignment: `auto-generated/-ag-research-tracker.md` `## by-memory` -> `### Not-Covered Files - Reconstructable`, where UID0001FL was `86/91`, average `88.5`, with zero direct/additional/total B-report coverage. The current generated row is `92/94`, average `93.0`, and correctly remains uncovered until supervisor execution.
- Historical supervisor classification before Gate 1: report-only source-quality research; no target/support edit before acceptance.
- Historical pre-callback scores: target `86/91`, class [UID:000062] `87/88`, file [UID:0000JT] `88/88`, ordinary-body range [UID:0001FI] `87/89`, vtable data [UID:0003DA] `88/92`.
- Current post-callback scores: target `92/94`, class [UID:000062] `92/93`, file [UID:0000JT] `90/92`, ordinary-body range [UID:0001FI] `91/93`, vtable data [UID:0003DA] `92/95`.

## Current Target State

- Current callback-applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:000062`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000062`, blank optional position, exact generated-ABI comment CPP, blank H, and `Nested:0`.
- Historical pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:91`, the same owner/reconstructable/emitter values, and blank CPP/H.
- Existing owner/emitter/reconstructable state: directionally correct. The three class-specific vtable entries, deleting wrapper, ordinary destructor, constructor stores, allocation size, and source module all support direct class ownership and the current class-to-file emitter chain.
- Current C++/emitter state: the target CPP contains the accepted five-line generated-ABI no-duplicate comment and the target H remains correctly blank; UID000062 emits `[[CHILDREN]]` plus the naturally aligned class H, and UID0001FI emits the ordinary destructor body.
- Historical pre-callback open questions/blockers were source-facing destructor declaration/body shape, helper names at `0x0049e1c0` and `0x0049e210`, complete class declaration/layout, compiler-generation conditions, `flags & 4` meaning, and whether this by-memory range needed formal code. The callback-applied ordinary docs now resolve all of them.
- Historical contradictory/stale claims corrected by the callback:
  - The pre-callback target said helper names were unresolved; current `DialogSessionVtables.md` and the callback now resolve the exact virtual slots as `DialogPane::OnDestroy()` and `DialogPane::OnHide()`.
  - The pre-callback target called the `flags & 4` branch a guard/vector/sized-delete-style path. Live IDA and the corrected docs establish `0x0041b6a0` as a one-byte `retn` no-op and reject sized delete, vector delete, guarded delete, and deallocation.
  - The pre-callback UID0001FI source emitted `OnDialogDestroying()` and `RemoveDialogControls()`; the callback replaced them with the supported current vtable/callee identities.
  - The pre-callback vtable page described cells `0x006228b8`, `0x00622918`, and `0x00622948` as RTTI locators. The corrected page distinguishes those pointer cells from actual named complete-object locators `0x0064e730`, `0x0064e794`, and `0x0064e7a8`.
  - The pre-callback ignored ledger said final source should implement scalar-deleting-destructor behavior. The corrected entry requires only the virtual destructor declaration/ordinary body and compiler-regenerated scalar deletion.
- Related target/support docs checked: [UID:000062], [UID:0000JT], [UID:0001FI], [UID:0003DA], [UID:000268], [UID:00023N], `Pane`, `DialogPane`, `PaneLayout`, `DialogPaneLayout`, `PaneVtables`, `DialogSessionVtables`, `by-memory/-ignored.md`, and the three applicable manual coverage reports.
- Current artifact/lifecycle status: active same report in B003 research; exact-artifact Gate 1 passed, ordinary-document callback applied, scoped validation complete, and generated `HeadSelectDialog.cpp/.h` current through command `000000017538`. Supervisor Gate 2A/Gate 2B, manual coverage application, and report execution remain pending. No lifecycle command or IDA mutation was run by B003.

## Executive Recommendation

- Best direct owner: [UID:000062] `HeadSelectDialog`.
- Source file: [UID:0000JT] `NexusTK/ui/dialogs/HeadSelectDialog.cpp` with companion `HeadSelectDialog.h`.
- Source-authored body owner: [UID:0001FI] for `HeadSelectDialog::~HeadSelectDialog()`.
- Generated-binary owner: [UID:0001FL] for the two adjustors, internal padding, and deleting wrapper recognition/coverage only.
- Applied metadata result: no owner/emitter/reconstructable change; accepted score and formal-channel changes only.
- No split or merge: the exact half-open target is one coherent class-specific ABI support island. Keep its 12-byte internal alignment documented in the target and keep successor UID00023N separate.
- Condition for closure: class H declaration, corrected UID0001FI ordinary body, UID0001FL formal covered-by comment, support prose, and scoped validation are complete. Supervisor Gate 2A verification, Gate 2B readback/save, manual coverage rows, and validator-owned report execution remain before closure.

## Supervisor Active Recheck

- Historical report-only instruction: investigate UID0001FL exhaustively, resolve score/open-question blockers during research, use healthy live IDA MCP, and edit only this report before Gate 1. Current instruction is the accepted ordinary-document implementation callback recorded here.
- Split-first check: no source-bearing child is missing from the target. The target already has exact thunk, padding, and wrapper subranges; source-authored destructor code is correctly separate in UID0001FI.
- Source-bearing child check: UID0001FI contains the ordinary destructor and other class methods; UID000062 now carries the class H declaration; UID0001FL carries only a no-duplicate compiler-generated formal comment.
- Successor check: UID00023N starts exactly at `0x005539c3` and routes to a shared default dialog wrapper at `0x00520b70`; it is not part of HeadSelectDialog-specific destruction.

## Inference Research Guidance Check

- Binary facts, documentation facts, and inferences are labeled separately throughout this report.
- Existing documentation was treated as provisional where it used generated labels, old helper names, vague guard/vector terminology, or an empty-emitter policy superseded by current `by-structure.md`.
- The source objective is not to hand-port the decompiler wrapper. It is to recover human C++ that causes the original virtual destructor and inherited layout semantics, then let the compatible compiler/toolchain emit equivalent ABI glue.
- Exact original identifiers are unavailable, so source-facing names are chosen from stable project conventions and behavior. Raw labels `sub_5538FE`, `sub_553909`, `sub_553920`, `Block`, and Boost exception types are rejected.
- Project-wide style evidence favors explicit `virtual ~Class();`, `m_` member names, zero-era pointer syntax, and separate `.cpp`/`.h` source roots. Consistency remains subordinate to exact behavior and plausible original source shape.
- Wave2/Wave3 mentions were ignored as stale. Current IDA, current by-* docs, current validator structure rules, and current report policy controlled the result.

## Heuristic / Inference Reanalysis And Validation

### Destructor declaration and body

- Best source declaration: `virtual ~HeadSelectDialog();`.
- Evidence: the primary vtable first slot points to the class-specific deleting wrapper; the base `DialogPane` destructor is virtual; current project declarations consistently retain explicit `virtual` on derived destructors.
- Best source body: call inherited `OnDestroy()` and `OnHide()` in that order. The compiler then emits vptr reinstalls and `DialogPane::~DialogPane()`.
- Rejected: handwritten vptr stores, explicit `DialogPane_destructor(this)`, direct `NexusTK_operator_delete_wrapper`, flags parameters, return-this ABI, adjustor methods, and a handwritten `ScalarDeletingDestructor` method.

### Inherited facet layout

- `HeadSelectDialog` has one direct source base: `DialogPane`.
- Offsets `+0xa0` and `+0xa4` are inherited `EventHandler` and `TimerHandler` views carried through `Pane`. They are not direct HeadSelectDialog bases and not explicit fields in the final class declaration.
- The two adjustors subtract decimal 160 and 164 respectively (Verified with `int_convert.py`) because their incoming `this` values address those inherited facets.
- Rejected: `class HeadSelectDialog : public DialogPane, public EventHandler, public TimerHandler`; that would duplicate inherited base state and produce the wrong source shape/layout.

### Complete class layout

- `DialogPane` is `0x26c` / 620 bytes (Verified with `int_convert.py`).
- The recovered HeadSelect tail occupies `0x98` bytes from `+0x26c` through `+0x303`; total size is `0x304` / 772 bytes (Verified with `int_convert.py`).
- The wrapper's no-op branch pushes `0x304`, and the packet-dispatch allocation wrapper allocates the same size. This independently validates the complete layout.
- `ObjectStatusBlob` is exactly `0x44` / 68 bytes (Verified with `int_convert.py`) and occupies `+0x278..+0x2bb`.
- Best source-facing member spellings remain those already supported by UID0001FI: `m_dialogSubtype`, `m_headPrice`, `m_npcId`, `m_objectId`, `m_previewObject`, `m_headCount`, `m_selectedHead`, `m_currentPage`, `m_baseHeadDrawOffset`, `m_previewPane`, `m_headButtons`, and three retained action/page buttons.
- `m_headPrice` remains an inference rather than symbol proof, but it is the strongest source-facing name from packet family, position, sibling semantics, and existing current docs. Neutral `m_priceOrRequestId` is weaker and not selected.

### Deleting flags and runtime no-op

- Bit 0 clear: destroy but do not free storage.
- Bit 0 set and bit 2 clear: call the project global operator-delete wrapper.
- Bit 2 set: push complete object size `0x304` and `this`, call one-byte `@_guard_check_icall_nop@4`, discard both arguments, and return `this` without the ordinary free.
- The one-byte helper is not a deallocator and has no meaningful project-source body. The size immediate remains useful object-layout evidence only.
- Rejected: vector delete, sized delete, guarded deallocation, placement delete, a second class cleanup path, or a source-visible flag API.

### Vtable and RTTI shape

- Primary vtable base `0x006228bc` has 23 slots before the secondary COL-pointer cell.
- Secondary base `0x0062291c` has 11 slots before the tertiary COL-pointer cell.
- Tertiary base `0x0062294c` has 2 slots before the next class island at `0x00622954`.
- The unlabeled cells at `0x006228b8`, `0x00622918`, and `0x00622948` point to named COL objects `??_R4HeadSelectDialog@@6B@`, `_0`, and `_1` at `0x0064e730`, `0x0064e794`, and `0x0064e7a8`.
- Constructor, ordinary destructor, and deleting wrapper each store all three vtable bases. This triad proves a single class layout across construction and both destruction forms.

### Formal emission decision

- UID0001FL qualifies for formal output because it is reconstructable, has a confirmed emitter route, and clears the combined score gate.
- Its exact source representation is a comment-only generated-binary coverage marker. No wrapper body or declaration belongs in this target's exact range.
- Class declarations belong in UID000062 H. Method definitions belong in UID0001FI CPP. `[[CHILDREN]]` belongs in the class CPP channel so existing child definitions continue to route.

## Evidence Standards Used

- Direct IDA MCP: `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `inspect_items`, `get_comments`, `type_query`, `decompile`, and `disasm` against live database `f085b224`.
- Binary evidence: exact function bounds, instructions, padding, vtable pointer cells, named COL objects, vtable-store xrefs, constructor caller, helper fan-in, deletion branches, and byte hashes.
- Documentation evidence: current target, class/file/core/vtable pages, base class/layout/vtable contracts, ignored ledger, manual coverage, generated coverage, tracker, and relevant executed reports as leads.
- Negative evidence: no ordinary callers for the thunk/wrapper/ordinary destructor entries, no separate source-visible flags API, no second cleanup in the no-op branch, no direct EventHandler/TimerHandler source bases, and no evidence for Boost ownership.
- Numeric conversions were performed through `tools/int_convert.py`, not manually.
- Evidence is strong enough to remove the target's current blockers. Confidence remains below 95 because original PDB/source spellings and exact historical compiler command line are unavailable.

## Evidence Checked

- MCP health: `status:ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, image base `0x400000`, Hex-Rays ready, strings cache ready; bounded live reads succeeded despite `auto_analysis_ready:false`.
- Exact target bytes: 197 bytes at `0x005538fe`, SHA256 `0C471AAB92AB39D49B5B23DD182393529C1D104DB7301154C258ACE75057F298`.
- Exact vtable-island bytes: 156 bytes at `0x006228b8`, SHA256 `A71844EB34E9D23F6E1975132A08D24864D96348F79BA8B411896425E65DC4E4`.
- Boundary bytes: one `0xcc` at predecessor `0x005538fd`; twelve `0xcc` bytes at `0x00553914-0x00553920`; successor bytes at `0x005539c3` begin a distinct `this -= 0xa0` thunk pair and end before seven `0xcc` bytes.
- Function lookup, exact half-open bounds: constructor `0x00551520-0x00551f26`, size `0xa06`; ordinary destructor `0x00551f30-0x00551f92`, size `0x62`; adjustors `0x005538fe-0x00553909` and `0x00553909-0x00553914`, each size `0xb`; deleting wrapper `0x00553920-0x005539c3`, size `0xa3`; shared virtuals `0x0049e1c0-0x0049e202`, size `0x42`, and `0x0049e210-0x0049e232`, size `0x22`; no-op runtime helper `0x0041b6a0-0x0041b6a1`, size `1`; successor thunk `0x005539c3-0x005539ce`, size `0xb`.
- Xrefs: vtable-only data refs to each target entry; constructor/destructor/wrapper store triads to all three vtable bases; constructor's one code caller at `0x54ca93`; ordinary destructor has zero inbound xrefs.
- Types/comments: current target entries carry Boost-polluted types. Exact `get_comments` readback gives address regular `Block` only at `0x005538fe` and `0x00553909`; every other address regular channel and all seven address repeatable, function regular, and function repeatable channels are empty/absent. Exact `HeadSelectDialog` type/name-index query returned total `0`; proposed function-name lookups returned `Not found` for all seven names.
- UDT dependencies: preserve exact existing `DialogPane` struct ordinal `471`, size `620`/`0x26c`, and exact existing `ObjectStatusBlob` struct ordinal `531`, size `68`/`0x44`; exact queries found no `ObjectImageControlPane` or `ObjectImageButtonPane` local type, while `ImageButtonControlPane` is an existing incomplete/other type at ordinal `540`. These dependencies must not be recreated or overwritten when creating `HeadSelectDialog`.
- Support helpers: `0x49e1c0` and `0x49e210` each have 122 xrefs and current type `void __thiscall(Pane *this)`; current vtable docs identify them as `DialogPane::OnDestroy` and `DialogPane::OnHide`.
- Runtime dependencies: `DialogPane_destructor` at `0x49d9f0`, `NexusTK_operator_delete_wrapper` at `0x4f4ac0`, and `@_guard_check_icall_nop@4` at `0x41b6a0` were read and retained as dependencies, not target owners.
- Old-report search: matching executed B001 UID0001FI and B015 destructor-thunk reports were opened as leads. B001's offline-MCP limitation and B015's older `RECONSTRUCTABLE:FALSE` policy were superseded by live evidence/current structure rules.
- Historical report-only exclusions: the initial pass performed no ordinary-document writes, validators, leases, lifecycle command, IDA mutation, or IDB save. The accepted callback subsequently used short ordinary-document leases and six scoped validators. IDA mutation/save, manual coverage edits, and report lifecycle execution remain supervisor-owned and were not performed.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| FL-001 | 0001FL | Exact half-open range is `0x005538fe-0x005539c3`, 197 bytes. | Very strong | MCP bytes/lookup; target SHA256. | UID0001FL Range/IDA Evidence | replace/sync | applied |
| FL-002 | 0001FL | `0x5538fe` subtracts `0xa0` and tail-jumps to `0x553920`. | Very strong | Two-instruction disasm; vtable ref `0x62291c`. | UID0001FL Covered Functions/IDA Evidence | preserve/refine | applied |
| FL-003 | 0001FL | `0x553909` subtracts `0xa4` and tail-jumps to `0x553920`. | Very strong | Two-instruction disasm; vtable ref `0x62294c`. | UID0001FL Covered Functions/IDA Evidence | preserve/refine | applied |
| FL-004 | 0001FL | `0x553914-0x553920` is exactly 12 bytes of internal `0xcc` alignment. | Very strong | MCP bytes. | UID0001FL Range analysis | preserve/refine | applied to UID0001FL and exact ignored-ledger disposition |
| FL-005 | 0001FL | `0x553920` is the class-specific MSVC deleting wrapper, not a source API. | Very strong | Disasm/decompile/vtable slot/call chain. | UID0001FL Rebuild Handling/formal CPP | replace | applied |
| FL-006 | 0001FL | Bit-2 path calls a one-byte no-op with size `0x304`; it is not sized/vector delete. | Very strong | Exact branch disasm; helper bytes/comment/type. | UID0001FL behavior and stale-history correction | replace | applied |
| FL-007 | 0001FL | Owner/emitter remain UID000062; target remains reconstructable. | Very strong | Three class vtables, constructor/dtor/wrapper stores, source route. | UID0001FL metadata/ownership | retain | applied |
| FL-008 | 0001FL | Target CPP must be a no-duplicate generated-binary comment; target H remains blank. | Strong | `by-structure.md` covered-by rule and exact-range channel rule. | UID0001FL formal CPP/H | insert/retain | applied |
| FL-009 | 0001FL | Source declaration is explicit virtual destructor on `HeadSelectDialog`. | Strong | Base virtual dtor, primary slot, project declaration style. | UID000062 H | insert | applied |
| FL-010 | 0001FL | Ordinary source body calls inherited `OnDestroy()` then `OnHide()`. | Very strong | UID0001FI/UID0001FL identical call sequence; vtable slot docs. | UID0001FI formal CPP/destructor prose | replace | applied |
| FL-011 | 0001FL | EventHandler/TimerHandler views are inherited through Pane, not direct HeadSelect bases. | Very strong | Pane class/layout/vtable docs; offsets. | UID000062 Class Shape; UID0001FL layout | insert | applied |
| FL-012 | 0001FL | Complete class size is `0x304`, with exact tail members through `+0x300`; natural C++ alignment supplies bytes `+0x26d-+0x26f`, so the human H must not author a padding member, while an explicit alignment member is permitted only in the exact IDA UDT. | Very strong | allocation, wrapper immediate, field map, UDT sizes, C++ member alignment. | UID000062 H/Class Shape; IDA UDT | insert | applied to ordinary docs; exact IDA UDT remains pending supervisor Gate 2B |
| FL-013 | 0001FL | Vtable pointer cells and actual COL object addresses must be distinguished. | Very strong | Live bytes/inspect names. | UID0003DA Evidence | correct | applied |
| FL-014 | 0001FL | Successor UID00023N begins exactly at target end and must remain separate. | Very strong | lookup/bytes/xref and successor doc. | UID0001FL Range analysis | preserve | applied |
| FL-015 | 0001FL | Target score should become `92/94`. | Strong | All material target blockers resolved; symbol/toolchain caps remain. | UID0001FL metadata/score rationale | update | applied |
| FL-016 | 0001FL | Class/core/file/vtable support scores should reflect the new declaration/body/layout closure. | Strong | Destination-ready H/CPP, live IDA, current docs. | UID000062, UID0001FI, UID0000JT, UID0003DA | update | applied |
| FL-017 | 0001FL | Ignored-ledger wording must reject handwritten scalar deleting behavior. | Very strong | Current source-declared/generated-binary policy. | `by-memory/-ignored.md` | replace sentence | applied |
| FL-018 | 0001FL | Manual coverage rows are stale or absent and require supervisor-owned text. | Very strong | Read-only row comparison. | three manual coverage reports | supervisor apply | pending supervisor |
| FL-019 | 0001FL | IDA target/helper types and names are polluted/incomplete; all seven exact function bounds, four comment channels, proposed-name collision checks, and UDT dependency protections are itemized for Gate 2B. | Very strong | live lookup/get_comments/type catalog/name collision queries. | Gate 2B IDA | supervisor apply | pending supervisor |
| FL-020 | 0001FL | Generated tracker/coverage refresh must come from validator, never manual edits. | Very strong | project workflow. | validator-generated reports | refresh | applied by validator; CPP/H current at 000000017538 and generated tracker/coverage current at later command 000000017556; manual coverage remains pending supervisor |

## Positive Evidence Summary

- Exact target bytes, hashes, bounds, three function objects, padding, and successor start all agree.
- Each target entry has the expected vtable route: primary directly to `0x553920`, secondary to `0x5538fe`, tertiary to `0x553909`.
- Constructor, ordinary destructor, and deleting wrapper each write the same three HeadSelectDialog vtable bases.
- Ordinary destructor and deleting wrapper perform the same class cleanup before the wrapper's flags branch.
- `DialogSessionVtables.md` resolves the two direct cleanup calls to inherited `OnDestroy()` and `OnHide()`.
- Base layout docs resolve `+0xa0/+0xa4` as inherited facets without introducing extra direct bases.
- Allocation size, wrapper size immediate, and exact recovered fields independently converge on `sizeof(HeadSelectDialog) == 0x304`.
- Current structure policy explicitly provides a formal covered-by comment for reconstructable generated ranges, removing the empty-emitter blocker.

## IDA MCP Facts

- Function/range facts:
  - `sub_5538FE`: `0x5538fe-0x553909`, two instructions, size `0xb` / 11 (Verified with `int_convert.py`).
  - `sub_553909`: `0x553909-0x553914`, two instructions, size `0xb` / 11 (Verified with `int_convert.py`).
  - `sub_553920`: `0x553920-0x5539c3`, 58 instructions, size `0xa3` / 163 (Verified with `int_convert.py`).
  - `sub_551F30`: `0x551f30-0x551f92` function model size `0x62` / 98 (Verified with `int_convert.py`); executable return is at `0x551f91` with SEH support associated by IDA.
- Data/table/padding facts:
  - target size `0xc5` / 197 (Verified with `int_convert.py`);
  - internal padding `0xc` / 12 (Verified with `int_convert.py`);
  - vtable island `0x9c` / 156 (Verified with `int_convert.py`).
- Xref facts:
  - adjustors each have one vtable data ref;
  - wrapper has two thunk code refs plus one primary vtable ref;
  - each vtable base has three write xrefs from constructor, ordinary destructor, and deleting wrapper;
  - ordinary destructor has zero inbound xrefs because the deleting wrapper duplicates/inlines its body.
- Vtable/global/type facts:
  - primary/secondary/tertiary bases are already named correctly;
  - actual COL objects are named correctly at `0x64e730`, `0x64e794`, `0x64e7a8`;
  - `HeadSelectDialog` UDT is absent;
  - current function prototypes are polluted by Boost exception types and one-byte flag inference.
- Negative IDA facts:
  - no ordinary source caller to target entries;
  - no source function in the 12-byte padding;
  - no meaningful helper behavior at `0x41b6a0` beyond `retn`;
  - no target evidence for direct EventHandler/TimerHandler source inheritance.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00551520-0x00551f26` | UID0001FI | HeadSelectDialog constructor | true | UID000062 | `87/89` current support | source-authored |
| `0x00551f30-0x00551f92` IDA model | UID0001FI | ordinary destructor lowering | true | UID000062 | recommend `91/93` aggregate | source body plus compiler lowering |
| `0x005538fe-0x00553909` | UID0001FL | `+0xa0` inherited-facet deleting adjustor | true as target aggregate | UID000062 | recommend target `92/94` | compiler-generated |
| `0x00553909-0x00553914` | UID0001FL | `+0xa4` inherited-facet deleting adjustor | true as target aggregate | UID000062 | recommend target `92/94` | compiler-generated |
| `0x00553914-0x00553920` | UID0001FL | internal alignment | true only within source-declared aggregate | UID000062 | recommend target `92/94` | compiler/linker-generated padding |
| `0x00553920-0x005539c3` | UID0001FL | primary deleting wrapper | true as target aggregate | UID000062 | recommend target `92/94` | source-declared/generated-binary |
| `0x006228b8-0x00622954` | UID0003DA | COL-pointer cells plus three vtable views | true | UID000062 | recommend `92/95` | source-declared/generated-binary |
| `0x005539c3-0x005539d9` | UID00023N | shared/proxy adjustor pair | false | none | `88/92` current | separate compiler glue |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x5538fe` | data `0x62291c` | secondary HeadSelectDialog vtable deleting entry only |
| `0x553909` | data `0x62294c` | tertiary HeadSelectDialog vtable deleting entry only |
| `0x553920` | code `0x553904`, code `0x55390f`, data `0x6228bc` | two adjustors and primary vtable only |
| `0x6228bc` | stores `0x551571`, `0x551f55`, `0x55394c` | constructor, ordinary destructor, deleting wrapper primary view |
| `0x62291c` | stores `0x551577`, `0x551f5b`, `0x553952` | same three lifecycle forms, inherited EventHandler view |
| `0x62294c` | stores `0x551581`, `0x551f65`, `0x55395c` | same three lifecycle forms, inherited TimerHandler view |
| `0x551520` | caller `0x54ca93` in wrapper `0x54ca50` | allocation/constructor route for a `0x304` object |
| `0x551f30` | zero inbound xrefs | standalone ordinary body retained despite wrapper duplication |
| `0x49e1c0` | 122 xrefs, including both HeadSelect destruction forms | shared `DialogPane::OnDestroy()` virtual/body |
| `0x49e210` | 122 xrefs, including both HeadSelect destruction forms | shared `DialogPane::OnHide()` virtual/body |
| `0x49d9f0` | 176 xrefs | shared ordinary `DialogPane` base teardown, not Boost |
| `0x4f4ac0` | over 500 refs | project global operator delete dependency |
| `0x41b6a0` | over 500 refs | shared one-byte compiler/runtime no-op dependency |
| `0x5539c3` | data `0x622cb8` | first successor shared/proxy vtable adjustor, excluded |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion:
  - `DialogSessionVtables.md` fixes `0x49e1c0`/`0x49e210` at primary slots `+0x38/+0x40` as `OnDestroy`/`OnHide`.
  - `Pane.md` states the EventHandler and TimerHandler facets at `+0xa0/+0xa4` are inherited through Pane.
  - UID0001FI provides the complete class-tail field map and ordinary destructor range.
  - UID0003DA provides exact class vtable island ownership.
- Existing stale/incomplete docs:
  - UID0001FL empty emitter, old helper-name blocker, and stale no-op-branch wording;
  - UID0001FI synthetic destructor helper names;
  - UID000062 blank H/CPP routing despite source-ready fields/methods;
  - UID0003DA COL-pointer-cell terminology;
  - ignored ledger's instruction to implement scalar deleting behavior;
  - three stale manual coverage rows plus absent UID0003DA manual child row.
- Generated state:
  - `-ag-memory-coverage.md` currently reports UID0001FL as emitting to `HeadSelectDialog.cpp` but empty;
  - `-ag-research-tracker.md` reports zero B coverage;
  - both are validator-owned and must update through scoped validation/report execution, not manual edits.

## Ranked Ownership Analysis

### 1. UID000062 HeadSelectDialog

- Evidence for: all three decorated class vtables, constructor/destructor/wrapper vtable resets, class-specific ordinary cleanup, `0x304` allocation/layout, exact source module, and direct method/core ownership.
- Evidence against: none material. The target bytes are compiler output, but the declaration causing them is class-owned.
- Decision: retain as canonical owner and emitter.

### 2. UID0001FI HeadSelectDialogCore as source-body destination

- Evidence for: contains the ordinary destructor range and all authored class methods; already emits `HeadSelectDialog::~HeadSelectDialog()` through the class.
- Evidence against: it is not the semantic owner of the noncontiguous target bytes and should not absorb their address range.
- Decision: use as covered-by ordinary-body destination, not canonical owner of UID0001FL.

### 3. Owner NONE / non-reconstructable compiler glue

- Evidence for: adjustors, padding, and wrapper lowering are compiler generated; older analogous pages sometimes use this policy.
- Evidence against: current `by-structure.md` distinguishes pure ignorable glue from source-declared/generated-binary items and explicitly provides a formal covered-by comment. This target is class-specific, has an exact declaration/body obligation, and already has a valid source route.
- Decision: reject. Do not revert to `NONE/FALSE`.

### Proposed new file/grouping, if applicable

- No new file is required.
- Existing owner/name/path: `NexusTK/ui/dialogs/HeadSelectDialog.cpp` and companion `.h` under UID0000JT.
- Likely full contents: class declaration, child method definitions from UID0001FI, two file-local head-offset arrays, class-specific vtable/resource declarations generated by compiler/linker, and the formal no-duplicate destructor-support comment.
- Rejected grouping: generic DialogPane, ObjectImage controls, MessageDialogs dispatcher, NexonclubProxyDialog, or a standalone thunk source file.

## Source Placement

- Recommended placement: class declaration in `NexusTK/ui/dialogs/HeadSelectDialog.h`; ordinary destructor and other methods in `NexusTK/ui/dialogs/HeadSelectDialog.cpp`.
- Why: file/class/core/vtable/resource/table ownership already converges on UID0000JT/UID000062, and the only constructor route is the message-dialog packet wrapper consuming this class.
- Target placement: UID0001FL remains a by-memory evidence child routed through UID000062; it does not become a separate source function/file.
- Rejected: `DialogPane.cpp` owns only inherited base virtuals/destruction; `MessageDialogs.cpp` owns the allocation/dispatch caller; compiler/runtime and Boost do not own project class source.
- Remaining placement uncertainty: none material for this target.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x005538fe-0x005539c3`, half-open.
- Predecessor: `0x005538fd` is one confirmed `0xcc` byte outside the target and remains ignored padding.
- Child layout:
  - `0x005538fe-0x00553909`: `this -= 0xa0` adjustor;
  - `0x00553909-0x00553914`: `this -= 0xa4` adjustor;
  - `0x00553914-0x00553920`: 12-byte internal alignment;
  - `0x00553920-0x005539c3`: class-specific deleting wrapper.
- Successor: UID00023N starts exactly at `0x005539c3` and consists of a different pair of adjustors to shared wrapper `0x00520b70`.
- Split decision: no new page. The target is already the exact coherent HeadSelect-specific generated support island and the padding is only internal alignment.
- Merge decision: do not merge UID0001FI, UID0003DA, UID00023N, or ignored padding. Their address/semantic roles differ.
- Reclassification: preserve aggregate `source-declared/generated-binary`, while labeling individual adjustors/padding as compiler/linker-generated and the wrapper as declaration/body-induced ABI output.

## Negative Evidence Summary

- No ordinary code caller reaches either adjustor or deleting wrapper; dispatch is vtable-only.
- The ordinary destructor has no inbound xref, proving absence of an ordinary direct call does not make it dead; the wrapper duplicates its lowering.
- No separate source method, API, packet route, or user-visible behavior corresponds to scalar-deleting flags.
- The `flags & 4` call target is one byte `c3`; no deallocation, vector loop, size check, or guard logic exists there.
- No evidence supports direct `EventHandler`/`TimerHandler` bases in HeadSelectDialog; doing so conflicts with Pane's inherited facets.
- No target evidence supports Boost exception ownership/types. Those types are analysis pollution.
- Consumer/callee fan-in to DialogPane/operator-delete/runtime helpers does not transfer target ownership.
- Adjacency to NexonclubProxyDialog successor thunks is not a merge signal.
- Exact original identifier spellings are unavailable, but that does not justify raw labels in source or IDA.

## IDA Rename / Type / Comment Recommendations

All actions below are supervisor-owned Gate 2B work. B003 made no IDA mutation.

| Address/entity | Literal current pre-state | Proposed action | Evidence / confidence | Expected readback |
| --- | --- | --- | --- | --- |
| Type `HeadSelectDialog` | Exact type/name-index query `HeadSelectDialog`: total `0`; no ordinal, declaration, size, or members. Dependencies: preserve `DialogPane` struct ordinal `471`, size `0x26c`; preserve `ObjectStatusBlob` struct ordinal `531`, size `0x44`; `ObjectImageControlPane` and `ObjectImageButtonPane` exact queries total `0`; preserve existing incomplete `ImageButtonControlPane` ordinal `540`. | Immediately before creation, rerun the exact `HeadSelectDialog` type/name-index query and abort/escalate on any collision rather than overwrite. Create only the exact size-`0x304` UDT below. Reuse ordinals `471`, `531`, and `540` unchanged. If IDA requires definitions for the two absent ObjectImage pointer targets, create opaque forward declarations only; do not infer layouts or replace a type that appears before Gate 2B. | allocation, wrapper immediate, current field docs, exact live type catalog; very strong | exactly one `HeadSelectDialog` type entry, size `772`/`0x304`, with listed offsets; `DialogPane` ordinal `471` and `ObjectStatusBlob` ordinal `531` retain their exact sizes/members; `ImageButtonControlPane` ordinal `540` remains incomplete; no duplicate/colliding dependency type |
| Function `0x00551520-0x00551f26`, size `0xa06` | name `sub_551520`; type `int __thiscall(int this, int)`; address regular comment: absent; address repeatable comment: absent; function regular comment: absent; function repeatable comment: absent | Rename `HeadSelectDialog__Constructor`; type `HeadSelectDialog *__thiscall(HeadSelectDialog *this, const unsigned char *packet)`; set function regular comment to `Constructs the 0x304-byte packet-driven HeadSelectDialog, installs its three inherited Pane/DialogPane vtable views, parses the head-selection payload, and creates the dialog controls.`; leave the other three comment channels absent. | exact constructor behavior/caller/vtable stores; very strong | exact range/size unchanged; name/type match; address regular absent; address repeatable absent; function regular equals proposed text; function repeatable absent; decompile receiver/packet typed |
| Function `0x00551f30-0x00551f92`, size `0x62` | name `sub_551F30`; type `void __thiscall(boost::exception *this)`; address regular comment: absent; address repeatable comment: absent; function regular comment: absent; function repeatable comment: absent | Rename `HeadSelectDialog__Destructor`; type `void __thiscall(HeadSelectDialog *this)`; set function regular comment to `Ordinary HeadSelectDialog destructor lowering: restores the three class vtable views, calls inherited DialogPane::OnDestroy() and OnHide(), then performs DialogPane base destruction. Source body belongs to UID0001FI; deleting wrapper/thunks are UID0001FL.`; leave the other three comment channels absent. | exact ordinary body and current docs; very strong | exact range/size unchanged; name/type match; address regular absent; address repeatable absent; function regular equals proposed text; function repeatable absent; typed decompile uses HeadSelectDialog receiver |
| Function `0x005538fe-0x00553909`, size `0xb` | name `sub_5538FE`; type `boost::exception *__thiscall(char *this, char)`; address regular comment: literal `Block`; address repeatable comment: absent; function regular comment: absent; function repeatable comment: absent | Rename `HeadSelectDialog_ScalarDeletingDestructor_AdjustA0`; type `HeadSelectDialog *__thiscall(char *adjustedThis, unsigned int flags)`; clear address regular `Block`; set function regular comment to `Compiler-generated inherited EventHandler-view deleting-destructor adjustor: subtracts 0xA0 from this and tail-jumps to HeadSelectDialog_ScalarDeletingDestructor. Do not reconstruct as handwritten source.`; leave address repeatable and function repeatable absent. | exact two instructions and secondary vtable; very strong | exact range/size unchanged; name/type match; address regular absent; address repeatable absent; function regular equals proposed text; function repeatable absent; decompile shows decimal-160 adjustment without Boost |
| Function `0x00553909-0x00553914`, size `0xb` | name `sub_553909`; type `boost::exception *__thiscall(char *this, char)`; address regular comment: literal `Block`; address repeatable comment: absent; function regular comment: absent; function repeatable comment: absent | Rename `HeadSelectDialog_ScalarDeletingDestructor_AdjustA4`; type `HeadSelectDialog *__thiscall(char *adjustedThis, unsigned int flags)`; clear address regular `Block`; set function regular comment to `Compiler-generated inherited TimerHandler-view deleting-destructor adjustor: subtracts 0xA4 from this and tail-jumps to HeadSelectDialog_ScalarDeletingDestructor. Do not reconstruct as handwritten source.`; leave address repeatable and function repeatable absent. | exact two instructions and tertiary vtable; very strong | exact range/size unchanged; name/type match; address regular absent; address repeatable absent; function regular equals proposed text; function repeatable absent; decompile shows decimal-164 adjustment without Boost |
| Function `0x00553920-0x005539c3`, size `0xa3` | name `sub_553920`; type `boost::exception *__thiscall(boost::exception *Block, char)`; address regular comment: absent; address repeatable comment: absent; function regular comment: absent; function repeatable comment: absent | Rename `HeadSelectDialog_ScalarDeletingDestructor`; type `HeadSelectDialog *__thiscall(HeadSelectDialog *this, unsigned int flags)`; set function regular comment to `Compiler-generated MSVC deleting-destructor wrapper for virtual HeadSelectDialog::~HeadSelectDialog(). It duplicates OnDestroy/OnHide/DialogPane teardown, conditionally calls the project operator-delete wrapper for bit 0 when bit 2 is clear, and sends this plus size 0x304 through the bit-2 one-byte no-op path. Do not hand-author this wrapper.`; leave the other three comment channels absent. | exact disasm/decompile/vtable route; very strong | exact range/size unchanged; name/type match; address regular absent; address repeatable absent; function regular equals proposed text; function repeatable absent; typed decompile has no Boost/Block/char-flag pollution |
| Function `0x0049e1c0-0x0049e202`, size `0x42` | name `sub_49E1C0`; type `void __thiscall(Pane *this)`; address regular comment: absent; address repeatable comment: absent; function regular comment: absent; function repeatable comment: absent | Rename `DialogPane_OnDestroy`; type `void __thiscall(DialogPane *this)`; set function regular comment to `DialogPane::OnDestroy(): releases child-control state through m_controlManager, then performs inherited Pane removal/destruction-side handling. Primary vtable slot +0x38.`; leave the other three comment channels absent. | current vtable contract, body, 122 refs; very strong | exact range/size unchanged; name/type match; address regular absent; address repeatable absent; function regular equals proposed text; function repeatable absent; named typed shared virtual in destructor decompiles |
| Function `0x0049e210-0x0049e232`, size `0x22` | name `sub_49E210`; type `void __thiscall(Pane *this)`; address regular comment: absent; address repeatable comment: absent; function regular comment: absent; function repeatable comment: absent | Rename `DialogPane_OnHide`; type `void __thiscall(DialogPane *this)`; set function regular comment to `DialogPane::OnHide(): unregisters/removes the inherited +0xA0 EventHandler facet from modal tracking, then performs inherited Pane hide handling. Primary vtable slot +0x40.`; leave the other three comment channels absent. | current vtable contract, body, 122 refs; very strong | exact range/size unchanged; name/type match; address regular absent; address repeatable absent; function regular equals proposed text; function repeatable absent; named typed shared virtual in destructor decompiles |

Current exact proposed-name collision check: live `lookup_funcs` returned `Not found` for `HeadSelectDialog__Constructor`, `HeadSelectDialog__Destructor`, `HeadSelectDialog_ScalarDeletingDestructor_AdjustA0`, `HeadSelectDialog_ScalarDeletingDestructor_AdjustA4`, `HeadSelectDialog_ScalarDeletingDestructor`, `DialogPane_OnDestroy`, and `DialogPane_OnHide`. Gate 2B must repeat this check immediately before each rename and abort/escalate rather than overwrite any name that has since appeared at another address.

Exact proposed IDA UDT declaration:

```cpp
struct ObjectImageControlPane;
struct ObjectImageButtonPane;
struct ImageButtonControlPane;

struct HeadSelectDialog
{
    DialogPane base;                              // +0x000
    unsigned char m_dialogSubtype;               // +0x26c
    unsigned char _alignment26D[3];              // +0x26d, IDA-layout-only explicit alignment
    unsigned int m_headPrice;                    // +0x270
    unsigned short m_npcId;                      // +0x274
    unsigned short m_objectId;                   // +0x276
    ObjectStatusBlob m_previewObject;            // +0x278
    int m_headCount;                             // +0x2bc
    int m_selectedHead;                          // +0x2c0
    int m_currentPage;                           // +0x2c4
    int m_baseHeadDrawOffset;                    // +0x2c8
    ObjectImageControlPane *m_previewPane;       // +0x2cc
    ObjectImageButtonPane *m_headButtons[10];    // +0x2d0
    ImageButtonControlPane *m_confirmButton;     // +0x2f8
    ImageButtonControlPane *m_nextPageButton;    // +0x2fc
    ImageButtonControlPane *m_prevPageButton;    // +0x300
};
```

The explicit `_alignment26D` member above is an IDA-layout-only device. It preserves byte-exact member offsets in the analysis UDT and must not be copied into the human source declaration. The Gate 2B creator must preserve the existing dependency ordinals and use only pointer-level opaque declarations for absent ObjectImage dependencies as specified in the table.

Protected/no-change entities:

- Keep `DialogPane_destructor` at `0x0049d9f0`, its `DialogPane *` type, and its existing anti-Boost function comments.
- Keep `NexusTK_operator_delete_wrapper` at `0x004f4ac0`, its `void *` type, and its existing ownership comment.
- Keep `@_guard_check_icall_nop@4` at `0x0041b6a0`, type `void()`, and existing exact no-op comments.
- Keep decorated vtable names at `0x006228bc`, `0x0062291c`, `0x0062294c` and decorated COL names at `0x0064e730`, `0x0064e794`, `0x0064e7a8`.
- Do not name the unlabeled COL-pointer cells as locators; they are pointer cells immediately before vtable bases.
- Do not create a function in `0x00553914-0x00553920`, merge successor `0x005539c3`, add a direct EventHandler/TimerHandler base, or overwrite compiler/runtime identities.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, as exact formal channel payloads after supervisor Gate 1.
- Target CPP block disposition, exact UID0001FL insertion:

```cpp
// Compiler-generated MSVC deleting-destructor support for HeadSelectDialog.
// Reconstruct virtual ~HeadSelectDialog() through UID000062 and its ordinary body through UID0001FI.
// Let the compiler regenerate the primary deleting wrapper, +0xA0/+0xA4 inherited-facet
// adjustors, vtable restores, DialogPane base destruction, deleting flags, and storage release.
// The bit-2 branch's 0x304 size/no-op lowering is compiler/runtime output. Do not hand-author it.
```

- Target H block disposition: remain blank. UID0001FL's exact `.text` range contains no independent declaration; the required declaration belongs to class UID000062.
- Support UID000062 CPP block disposition, exact replacement:

```cpp
[[CHILDREN]]
```

- Support UID000062 H block disposition, exact insertion:

```cpp
#include "../core/DialogPane.h"
#include "../../map/ObjectStatusBlob.h"

class ImageButtonControlPane;
class ObjectImageButtonPane;
class ObjectImageControlPane;

class HeadSelectDialog : public DialogPane
{
public:
    HeadSelectDialog(const unsigned char *packet);
    virtual ~HeadSelectDialog();

    virtual void OnAction(int actionId, int unused);

private:
    void RefreshHeadPreview();
    void UpdatePageButtonStates();
    void NextHeadPage();
    void PreviousHeadPage();
    void PopulateHeadButtons(int page, bool removeExistingButtons);

    unsigned char m_dialogSubtype;
    unsigned int m_headPrice;
    unsigned short m_npcId;
    unsigned short m_objectId;
    ObjectStatusBlob m_previewObject;
    int m_headCount;
    int m_selectedHead;
    int m_currentPage;
    int m_baseHeadDrawOffset;
    ObjectImageControlPane *m_previewPane;
    ObjectImageButtonPane *m_headButtons[10];
    ImageButtonControlPane *m_confirmButton;
    ImageButtonControlPane *m_nextPageButton;
    ImageButtonControlPane *m_prevPageButton;
};
```

No explicit source padding member belongs between `m_dialogSubtype` and `m_headPrice`: ordinary C++ alignment supplies bytes `+0x26d-+0x26f` and places the 32-bit member at `+0x270`. Authoring those bytes as a named field would make the human reconstruction decompiler-shaped.

- Support UID0001FI ordinary-destructor definition, exact replacement:

```cpp
HeadSelectDialog::~HeadSelectDialog()
{
    OnDestroy();
    OnHide();
}
```

- Reason it preserves behavior: the two direct inherited virtual calls match both live destructor forms; C++ base destruction supplies `DialogPane::~DialogPane`; virtual destruction plus inherited Pane facets supplies the three deleting entries and all ABI-only branches.
- Reason it matches plausible original source: it contains only a normal C++03-era class declaration and ordinary destructor body, not decompiler flags, vptr stores, raw addresses, or synthetic scalar-deleting APIs.
- Inferred names: descriptive class/member/method names already used consistently by current HeadSelect docs; no `sub_`, `Block`, Boost, or decompiler temporary survives.
- Style: explicit `virtual`, `m_` members, `0`-era pointer conventions in existing CPP, no modern override/nullptr/attributes, and standard separate header/source placement.
- Third-party import: not applicable.

## Final Recommendation

- Applied ordinary-document result: UID0001FL is `92/94` with retained owner/reconstructable/emitter/position/range, exact target CPP comment, and blank target H.
- Applied ordinary-document result: UID000062 now has child-routing CPP, the naturally aligned full class H declaration, and score `92/93`.
- Applied ordinary-document result: UID0001FI now has the exact ordinary destructor source/prose and score `91/93`.
- Applied ordinary-document result: UID0000JT now records the source/header and destructor split at `90/92`; validator command `000000017538` generated current CPP/H.
- Applied ordinary-document result: UID0003DA now distinguishes COL pointer cells from actual objects, carries current hash/slot/store evidence and a generated-data CPP comment, and scores `92/95`.
- Applied ordinary-document result: the ignored ledger now rejects handwritten scalar deleting behavior and separately disposes the internal 12-byte alignment. Supervisor-owned manual coverage rows remain pending.
- Supervisor should perform all listed IDA actions in Gate 2B, read back each exact entity, save the IDB, and record the checkpoint before report execution.
- Do not hand-author target wrapper code, create direct inherited-facet bases, merge successor glue, or leave any final source with raw IDA labels.

## Recommended Target Doc Changes

- Callback disposition: all accepted target changes below are applied and survived scoped validator command `000000017531` (`exit 0`, `ok: 1`).
- Target path: `by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md`.
- Metadata: `86/91 -> 92/94`; retain `CANONICAL_OWNER:000062`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000062`, blank optional position, `Nested:0`.
- Formal CPP: insert the exact five-line compiler-generated coverage comment from `First-Draft C++ Recommendation`.
- Formal H: keep blank with the target-specific declaration-placement reason.
- Replace `Item Summary` with:
  `Class-specific source-declared/generated-binary HeadSelectDialog destructor support: exact inherited-facet adjustors, internal alignment, deleting wrapper, vtable routes, ordinary-body parity, delete/no-op flag paths, class-layout requirement, covered-by source route, and successor exclusion are live-IDB confirmed.`
- Add exact current byte hash, function counts/bounds, COL-pointer-cell correction, complete class size/layout evidence, and bit-2 no-op correction.
- Replace unresolved helper-name blocker with the supported `DialogPane::OnDestroy()`/`OnHide()` resolution.
- Preserve historical assumptions in a clearly superseded subsection: prior Boost type/name pollution, old `guard-or-vector-delete` wording, and prior empty-C++ deferral.

## Recommended Support Doc Changes

- Callback disposition: all accepted ordinary support-document changes below are applied. Supervisor-owned manual coverage and IDA work remain excluded from B003 write scope.
- `by-class/HeadSelectDialog.md`:
  - replace blank CPP with `[[CHILDREN]]`;
  - populate H with the exact declaration above;
  - add direct `DialogPane` inheritance, inherited-facet-not-direct-base rule, exact `0x304` layout table, destructor source/ABI split, and score `92/93`;
  - retain all existing behavior/relationships/history.
- `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`:
  - replace only the destructor definition with `OnDestroy(); OnHide();`;
  - update destructor prose to distinguish the two authored calls, compiler vptr/base lowering, and UID0001FL deleting support;
  - recommend `91/93`; retain all unrelated code/evidence/history.
- `by-file/HeadSelectDialog.md`:
  - record generated `.cpp` plus `.h`, class declaration route, exact destructor source split, inherited facet rule, and recommend `90/92`;
  - retain module placement and all existing contents.
- `by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md`:
  - correct pointer-cell versus actual COL-object terminology;
  - add the live byte hash, 23/11/2 slot counts, exact store triads, inherited facet interpretation, class H requirement, and recommend `92/95`;
  - insert a minimal covered-by CPP comment if supervisor applies the current empty-emitter rule to this source-declared/generated-binary vtable child, leaving H blank because declaration belongs to UID000062.
- `by-memory/-ignored.md`:
  - replace the current `Why ignored` sentence with:
    `Why ignored: compiler-generated inherited-facet vtable adjustor thunks, not handwritten project logic. Final source must declare and define the ordinary virtual HeadSelectDialog destructor through UID000062/UID0001FI, then let the compiler regenerate both adjustors and the scalar deleting wrapper; do not hand-author scalar-deleting flags or wrapper behavior.`
- `by-type/by-vtable/DialogSessionVtables.md`, `by-class/Pane.md`, `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`: no semantic change required; they already supply the decisive base-slot/facet facts. Add only cross-reference/history if the supervisor wants report traceability.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/91`, owner/emitter UID000062, reconstructable true, blank CPP/H.
- Current callback-applied target: `92/94`, same owner/emitter/reconstructable/position/range, exact comment CPP, blank H.
- Reason not lower: current live IDA independently confirms every target instruction/boundary, three vtable routes, constructor/destructor/wrapper stores, ordinary-body parity, delete/no-op branches, complete object size/layout, source declaration/body route, and successor exclusion.
- Reason not higher: original source/PDB spellings, exact historical compiler command line, and exact author choice to spell `virtual` explicitly are unavailable; target confidence should not reach final-perfect symbol certainty.
- Score-improvement attempt:
  - unresolved helper names -> resolved through current vtable contract plus live bodies/xrefs;
  - blank class declaration -> resolved with destination-ready H and exact layout;
  - blank target C++ -> resolved through current covered-by comment policy;
  - unclear compiler regeneration -> resolved through base virtual destructor, three-view inherited layout, ordinary body, and vtable/store evidence;
  - flags bit 2 -> resolved as size-immediate one-byte no-op, not deletion;
  - source placement -> resolved to existing class/core/file chain;
  - range/successor -> live bytes/functions resolve exactly.
- Applied support scores: UID000062 `92/93`, UID0001FI `91/93`, UID0000JT `90/92`, UID0003DA `92/95`.
- No metadata owner/emitter/reconstructable changes are recommended for target/support pages.

## Open Questions With Attempted Resolution

- Exact original destructor keyword spelling:
  - Checked: base virtuality, primary deleting slot, project class declaration style.
  - Resolution: use explicit `virtual ~HeadSelectDialog();`; omitting `virtual` would retain ABI through base inheritance, but explicit spelling is the strongest project-style inference.
  - Impact: no remaining behavior/score blocker.
- Exact original names for `OnDestroy`/`OnHide`:
  - Checked: current primary vtable slot map, function bodies, broad refs, Pane base semantics.
  - Resolution: use current canonical `DialogPane::OnDestroy()` and `OnHide()` names; reject synthetic `OnDialogDestroying`/`RemoveDialogControls`.
  - Impact: resolved enough for source and IDA.
- Exact original `m_headPrice` spelling/meaning:
  - Checked: packet position, field storage, dialog family, current HeadSelect docs, lack of later in-range reads.
  - Resolution: retain `m_headPrice` as high-probability source-facing inference and preserve the historical neutral alternative in prose, not code.
  - Impact: prevents final-perfect naming confidence but does not block the destructor/header/layout reconstruction.
- Exact historical compiler/toolchain switches:
  - Checked: MSVC-style EH/security-cookie/deleting-wrapper shape, vtable/RTTI layout, current project era.
  - Resolution: source obligations and lowering shape are established; binary-identical regeneration still depends on project-wide compatible compiler/linker settings outside this target.
  - Impact: project-wide build concern, not an unanswered target research action.
- Whether bit-2 is a named MSVC flag:
  - Checked: exact instructions and no-op target.
  - Resolution: document behavior, not an invented public/source enumerator. It has no handwritten API representation.
  - Impact: none on source output.
- Questions remaining unresolved after exhaustive current checks: no material target blocker. Only unavailable original spellings/compiler command-line details remain, and their exact score impact is already reflected.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only manual rows inspected:
  - `by-memory/-coverage-report.md` UID0001FI line 3003 and UID0001FL line 3013; both stale.
  - `by-class/-coverage-report.md` UID000062 line 243; stale.
  - `by-file/-coverage-report.md` UID0000JT line 110; stale.
  - UID0003DA has no exact manual by-memory row; containing UID000268 is at line 4216.
- Validator-owned generated tracker/coverage files must not be edited manually.

File `by-memory/-coverage-report.md`, replace UID0001FL row with:

```text
    - [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) 0x005538fe-0x005539c3 | source-declared/generated-binary destructor support | HeadSelectDialogDestructorThunks : reconstructable : 92% : very-strong : Live IDA confirms exact +0xa0/+0xa4 inherited-facet adjustors, 12-byte internal alignment, 0xa3 deleting wrapper, primary/secondary/tertiary vtable-only routes, ordinary OnDestroy/OnHide/DialogPane teardown parity, bit-0 operator-delete path, bit-2 0x304 one-byte no-op path, complete class-layout/declaration requirements, UID0001FI covered-by source route, and exact UID00023N successor exclusion; compiler ABI code is not handwritten.
```

File `by-memory/-coverage-report.md`, replace UID0001FI row with:

```text
    - [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md) 0x00551030-0x005520e5 | class method cluster | HeadSelectDialogCore : reconstructable : 91% : very-strong : Source-ready HeadSelectDialog constructor, preview, page, button-population, action, and ordinary-destructor methods with exact packet/member/control/table behavior; live destructor recheck resolves the authored OnDestroy/OnHide calls, compiler-performed DialogPane base teardown, and separate UID0001FL deleting-wrapper/adjustor generation without synthetic cleanup names.
```

File `by-memory/-coverage-report.md`, insert under UID000268 after the containing aggregate row:

```text
        - [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md) 0x006228b8-0x00622954 | RTTI/vtable data | HeadSelectDialogVtableData : reconstructable : 92% : very-strong : Exact three-view HeadSelectDialog source-declared/generated-binary island with unlabeled COL-pointer cells to named locators, 23/11/2 vtable slots, primary/secondary/tertiary deleting routes, constructor/ordinary-destructor/deleting-wrapper store triads, inherited Pane EventHandler/TimerHandler facet interpretation, exact successor boundary, and class-declaration regeneration through UID000062.
```

File `by-class/-coverage-report.md`, replace UID000062 row with:

```text
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) : reconstructable : 92% : very-strong : Complete packet-driven HeadSelectDialog class declaration and 0x304 layout with direct DialogPane inheritance, inherited +0xa0/+0xa4 Pane facets, constructor/destructor/action/private page/preview/button methods, exact ObjectStatusBlob and control fields, resource/layout-table ownership, ordinary OnDestroy/OnHide destructor source, and compiler-regenerated deleting-wrapper/vtable support routed through the HeadSelectDialog source/header pair.
```

File `by-file/-coverage-report.md`, replace UID0000JT row with:

```text
- [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) : reconstructable : 90% : very-strong : NexusTK/ui/dialogs/HeadSelectDialog.cpp and companion .h source root with complete class declaration/layout, packet-driven preview/page/action methods, exact ordinary destructor versus compiler deleting-support split, three-view inherited Pane vtable shape, allocation/object size 0x304, class-specific resource/vtable data, static normal/high head-offset tables, and message-dialog constructor route.
```

- Reason B agent must not apply these rows: all `-coverage-report.md` files are supervisor-owned during multi-agent work to prevent collisions.

## Follow-Up Actions

- Supervisor actions:
  - perform Gate 2A claim-by-claim verification against the six callback-edited ordinary docs and the validator records below;
  - perform every Gate 2B IDA action/disposition, read back names/types/comments/UDT, save the IDB, and record the checkpoint;
  - apply the exact manual coverage text, validate those supervisor-owned files, then execute/archive the report through validator lifecycle.
- A-agent actions: none.
- B003 future research actions: none unless Gate 2A identifies a precise same-report or ordinary-document reconciliation defect. Any repair should remain incremental, not a rewrite.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; `92/94` is justified without claiming final-perfect symbol recovery.
- Remaining uncertainty: exact original spellings and build command line only. No unresolved ownership, behavior, range, source-placement, class-layout, formal-channel, or compiler-generated-code blocker remains.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory\0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md --apply --queue-timeout 240` -> command `000000017531`, timestamp `2026-07-26T00:30:37-04:00`, exit `0`, `ok: 1`, generated refresh initially deferred.
- `python .\tools\validator.py --mode file --file by-class\HeadSelectDialog.md --apply --queue-timeout 240` -> command `000000017532`, timestamp `2026-07-26T00:30:46-04:00`, exit `0`, `ok: 1`, generated refresh initially deferred.
- `python .\tools\validator.py --mode file --file by-memory\0x00551030-0x005520e5.HeadSelectDialogCore.md --apply --queue-timeout 240` -> command `000000017534`, timestamp `2026-07-26T00:31:04-04:00`, exit `0`, `ok: 1`, generated refresh initially deferred.
- `python .\tools\validator.py --mode file --file by-file\HeadSelectDialog.md --apply --queue-timeout 240` -> command `000000017536`, timestamp `2026-07-26T00:31:18-04:00`, exit `0`, `ok: 1`, generated refresh initially deferred.
- `python .\tools\validator.py --mode file --file by-memory\0x006228b8-0x00622954.HeadSelectDialogVtableData.md --apply --queue-timeout 240` -> command `000000017538`, timestamp `2026-07-26T00:31:36-04:00`, exit `0`, `ok: 1`, registered new UID0003DA path/owner/emitter state, generated refresh initially deferred.
- `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240` -> command `000000017541`, timestamp `2026-07-26T00:31:55-04:00`, exit `0`, `ok: 1`, generated refresh initially deferred.
- Generated freshness: `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp` and `.h` carry command `000000017538` / `2026-07-26T00:31:36-04:00` and contain the accepted class declaration, ordinary `OnDestroy(); OnHide();` destructor body, UID0001FL generated-ABI comment, and UID0003DA generated-vtable comment. No `m_padding26D` survives. `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-memory-coverage.md` later refreshed at command `000000017556` / `2026-07-26T00:34:46-04:00` and show UID0001FL at `92/94` and coded.
- Validator diagnostics: the first target/class/file passes reported UID0003DA as missing because its new path had not yet been registered; command `000000017538` registered it. `by-memory/-ignored.md` reported its pre-existing broad set of missing-reference diagnostics (`209`, with `199` suppressed) but returned `ok: 1`; none is introduced as a target-specific callback failure. No scoped command returned an error.

## Changed Files

- Modified ordinary docs:
  - `by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md`.
  - `by-class/HeadSelectDialog.md`.
  - `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`.
  - `by-file/HeadSelectDialog.md`.
  - `by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md`.
  - `by-memory/-ignored.md`.
- Updated current report: `tools/leaser/Agents/Agent-B003/research/0001FL-HeadSelectDialogDestructorThunks-source-quality.md`.
- Validator-owned side effects: generated `HeadSelectDialog.cpp/.h`, generated research/memory coverage, projected stats, and validator registry/reference state refreshed through the six scoped commands; B003 did not edit those artifacts manually.
- Leases used and released immediately after each ordinary edit: UID0001FL, UID000062, UID0001FI, UID0000JT, UID0003DA, and `by-memory/-ignored.md`. No B003 lease remains active.
- Renamed/created ordinary docs: none.
- Report execution: not run. No report-lifecycle command, IDA mutation, IDB save, manual coverage edit, generated-file manual edit, supervisor audit edit, or manual archive move was performed.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation completed before implementation: exact artifact SHA `86FCF9B78D0F7ABDC31B3EFEA30F1D76C6DC32B6F50B6F700102C7A359CD0683` received `GATE1_PASSED` under the named final reaudit.
- [x] Target/support update set prepared in the initial report-only state: UID0001FL, UID000062, UID0001FI, UID0000JT, UID0003DA, and `by-memory/-ignored.md` exactly as listed; callback application is recorded below.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: no additional target UIDs declared.
- [x] Current target state and actual evidence checked recorded, including exact current function bounds, all four comment channels, UDT/type dependencies, and collision checks.
- [x] Claim And Incorporation Ledger completed for report-only state with destination, action, and proposed/pending verification state for every claim.
- [x] Metadata/score plan prepared in the initial report-only state: UID0001FL `92/94`; support recommendations UID000062 `92/93`, UID0001FI `91/93`, UID0000JT `90/92`, UID0003DA `92/95`; callback application is recorded below.
- [x] Score-limiting blockers researched to resolution: helper names, declaration/body shape, complete layout, no-op branch, formal CPP/H disposition, ownership/source placement, exact boundaries, natural source alignment, and Gate 2B prestate completeness.
- [x] Owner/emitter/reconstructable disposition completed for report-only state: retain all UID0001FL values; callback retained the route exactly.
- [x] Documentation split/new-child disposition completed for report-only state: no documentation split or new child; proposed IDA renames remain pending supervisor Gate 2B.
- [x] Source-placement and range/split/padding/reclassification analyses completed; exact IDA rename/type/comment handoff is documented but remains unapplied pending Gate 2B.
- [ ] Supervisor Gate 2B IDA handoff lists every exact address/entity, literal pre-state, proposed action, supporting type, safety constraint, and expected readback; this row remains unchecked for supervisor closure.
- [x] First-draft CPP/H recommendations prepared for supervisor review: target comment CPP/blank H, class child-routing CPP/full naturally aligned H, and core ordinary destructor replacement; callback application is recorded below.
- [x] Third-party import directive reviewed and found not applicable; no third-party source is involved.
- [x] Exact target/support incorporation facts prepared at report-level detail with destinations and actions; callback incorporation is recorded below.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence identified and ledgered for callback preservation.
- [x] Wave2/Wave3 mentions encountered and ignored as stale.
- [x] Open questions closed or bounded with evidence-backed residual original-spelling/toolchain uncertainty.
- [x] Validator plan prepared for after callback: scoped file validation for every changed by-* page and generated CPP/H freshness checks; execution remained forbidden.
- [x] Generated/manual coverage plan prepared: validator-owned generated reports refresh through scoped validation, and exact manual supervisor-owned coverage payload is supplied in the report.
- [x] Validator-owned generated CPP/H and generated tracker/coverage refresh completed and freshness was checked.
- [ ] Manual `-coverage-report.md` application remains supervisor-owned and pending.

Implementation callback pass:

- [ ] Supervisor-owned IDA changes remain pending and were not applied by the B agent.
- [x] Report accepted by supervisor for implementation under the exact Gate 1 artifact/audit named above.
- [x] All accepted target/support ordinary-doc details incorporated at report-level detail across the six callback paths.
- [x] Declared primary UID0001FL verified independently against its ledger and destination docs; no additional target UID was declared. Support UIDs were separately checked.
- [x] Claim And Incorporation Ledger updated with callback destinations and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied or explicitly retained: exact scores applied, owner/emitter/reconstructable routes retained, no split/rename, target ABI CPP/blank H, class children CPP/naturally aligned H, core destructor body, and vtable ABI CPP applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved in the affected docs, including helper-name, bit-2, direct-base, COL-cell, handwritten-wrapper, synthetic-padding, and successor corrections.
- [x] Open questions remain resolved or bounded to original spelling/compiler-command uncertainty with no ordinary-document blocker.
- [x] Six scoped validators ran serially; exact commands, ids, timestamps, exits, `ok` counts, diagnostics, and freshness are recorded above.
- [x] Generated CPP/H and generated tracker/coverage refresh completed by validator; affected generated files are current. Exact manual supervisor-owned coverage text remains unapplied as required.
- [x] Remaining unapplied work is explicitly limited to supervisor Gate 2A verification, Gate 2B IDA actions/readback/save, manual coverage application/validation, and validator-owned report execution.
- [ ] Supervisor Gate 2A verification remains pending.
- [ ] Supervisor manual coverage updates and validation remain pending.
- [ ] Supervisor report execution/lifecycle remains pending; B003 did not run or probe `execute_report`.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000017633","destination_path":"executed-b-agent-research/B003/0001FL-HeadSelectDialogDestructorThunks-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001FL-HeadSelectDialogDestructorThunks-source-quality.md","timestamp":"2026-07-26T00:54:25-04:00","uid":"0001FL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
