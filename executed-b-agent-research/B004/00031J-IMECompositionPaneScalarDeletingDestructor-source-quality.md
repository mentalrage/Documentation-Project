** TARGET-REPORT-UID:00031J **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00031J IMECompositionPaneScalarDeletingDestructor Source Quality Report

## Finalized Report / Current Recommendation

- Implemented target disposition: [UID:00031J] `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md` is now the exact non-reconstructable, non-emitting compiler scalar-deleting-destructor wrapper documented by this report.
- Current target state: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, `Nested:0`, unchanged exact path/title/range, and a completely blank managed C++ body.
- Current human source disposition: the one source declaration remains `virtual ~IMECompositionPane();` in [UID:00006G], and the one source definition remains `IMECompositionPane::~IMECompositionPane() {}` in [UID:0004C2]. UID00031J emits no second declaration, definition, proof comment, deleting-destructor pseudo-method, explicit vptr restoration, hidden flags, or storage-free call.
- Exact binary disposition: the 85-byte target is MSVC ABI lowering that duplicates the ordinary destructor's three vptr restores and `Pane` teardown, then interprets hidden delete flags. The only extra operations are compiler/runtime storage-deallocation choices and return-this ABI mechanics.
- No source-bearing split was required. The exact target range remains one coherent compiler wrapper; its two composition-pane adjustor entries remain in compiler-only UID00018D with their accepted exact hashes/routes.
- No rename was applied. `IMECompositionPaneScalarDeletingDestructor` remains a precise binary-documentation identity even though no same-named human C++ method exists.
- This artifact makes no claim about report validation, execution, counting, movement, or archive state. Those states are external and supervisor/validator-owned.

## Supporting Research

- Current destination documentation was read directly: UID00031J, ordinary destructor UID0004C2, class UID00006G, source file UID0000K5, mixed aggregate UID00018C, adjustor aggregate UID00018D, vtable data UID00025J, operator-delete wrapper UID000197, Pane core UID0001EA, `by-memory/-ignored.md`, generated `NexusTK/input/IMEPanes.cpp`, the generated tracker, and every affected manual `by-*/-coverage-report.md` row.
- Concrete prior-report search terms were `UID00031J`, `UID:00031J`, `0x004e86c0`, `0x004e8715`, `IMECompositionPaneScalarDeletingDestructor`, `scalar deleting destructor`, `UID0004C2`, `UID00006G`, `UID00018C`, `UID00018D`, `IMEPanes`, `IMECompositionPane`, `adjustor`, `operator delete`, and `guard_check_icall_nop`.
- Active root `tools/leaser/Agents/**`: direct target terms matched only the B004 assignment and supervisor assignment inventory, not another active B-agent research artifact. No active B001-B005 report claims UID00031J.
- Executed root `executed-b-agent-research/**`: three target/family reports were opened and classified.
  - `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md` is a historical family lead. It correctly identifies scalar wrappers as compiler output, but its allowance for a proof-comment emitter is superseded by the current false-page formal-body rule and direct target analysis.
  - `executed-b-agent-research/B010/0004C2-IMECompositionPaneOrdinaryDestructor-source-quality.md` is direct source-anchor evidence. It establishes the source-level empty ordinary destructor and separates hidden deleting-wrapper behavior.
  - `executed-b-agent-research/B007/0004C1-IMECompositionPaneConstructor-source-quality.md` is constructor/vtable parity support, not a direct target report.
- Modern mechanism precedent was opened separately: `executed-b-agent-research/B003/0001AI-ScrolledPictureControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md`. It records an independently evidenced scalar wrapper as `92/94`, class-owned, false, blank emitter/position/formal, and proves `0x0041b6a0` is a one-byte no-op. It is used only as a project-mechanism control; UID00031J's disposition is independently proved from its bytes, CFG, routes, helpers, and ordinary destructor.
- `tools/leaser/Agents/Older-Research/**`: all 3 Markdown files were searched with the direct and family terms; no match was found.
- `tools/leaser/Agents/SpecialReports/**`: no direct target match was found. Four broader IME family matches were opened: `benchmark-high-0004CC-IMEPaneSetFocusPane-source-quality.md`, `benchmark-medium-0004CC-IMEPaneSetFocusPane-source-quality.md`, `benchmark-supervisor-comparison-0004CC-IMEPaneSetFocusPane.md`, and `benchmark-xhigh-0004CC-IMEPaneSetFocusPane-source-quality.md`. All concern UID0004CC `IMEPane::SetFocusPane`; none supplies target bytes, a target source body, or contrary wrapper semantics.
- Actual archive root `project-documentation/archived/**`: it contained zero Markdown reports when searched, so it supplied no direct or family report evidence. This is the correct archive root; no missing `tools/leaser/Agents/archived` root is asserted.
- Direct prior-report result: zero target-specific prior reports. The B008/B010/B007 artifacts are revalidated leads and support, not substitutes for this target pass.

## Target

- UID: `00031J`.
- Current path: `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md`.
- Exact modeled range: `[0x004e86c0,0x004e8715)`.
- Exact size: `0x55` / 85 bytes.
- Exact byte SHA256: `70A98560325CFF07AF2772F37D414ED4B7A86470F90BB097B6396E2FF3DBBF8D`.
- Current binary name: `sub_4E86C0`; recommended documentation name remains `IMECompositionPaneScalarDeletingDestructor`.
- Direct semantic class owner: [UID:00006G] `IMECompositionPane`.
- Source route: [UID:0004C2] ordinary destructor -> [UID:00006G] class -> [UID:0000K5] `NexusTK/input/IMEPanes.cpp`.
- Compiler evidence route: UID00031J plus composition entries in UID00018D and vtable cells in UID00025J.
- Report artifact location at preparation time: `tools/leaser/Agents/Agent-B004/research/00031J-IMECompositionPaneScalarDeletingDestructor-source-quality.md`.

## Current Target State

- Historical pre-callback state was `86/90`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006G`, blank optional position, `Nested:0`, a four-line formal proof comment, and stale `85/89` Score Rationale prose.
- Current implemented state is `92/94`, owner UID00006G, false, blank emitter/position/formal, `Nested:0`, exact Item Summary, and report-level compiler/no-code evidence. Target SHA256 is `5562B4E937B72AE220CC29D14732047FD8C4CE669FB6513B4AAC67AD2C6E78E4`.
- Historical generated command `000000012914` emitted one UID0004C2 definition and one UID00031J proof-comment marker. Final waited validator command `000000012929` at `2026-07-15T06:56:40-04:00` supersedes that generated state.
- Final callback readback of generated `auto-generated/NexusTK/input/IMEPanes.cpp` under command `000000012929` had SHA256 `4F74F6055B8F7EE071A1B4D37F31FA53B271F1E567920C2D69B4F9D7AF0D5CCA`; it contained one UID0004C2 marker, one `IMECompositionPane::~IMECompositionPane()` definition, zero UID00031J marker/name/body, zero Empty Emitter Marker, and zero target vtable-address/object-size/delete/no-op-helper source.
- All seven accepted ordinary destinations are implemented and scoped-validated. All four verify-only controls were reread unchanged. No implementation item remains.

## Executive Recommendation

The strongest source reconstruction has one public virtual destructor declaration and one empty ordinary destructor definition. UID00031J is not another human method. It is the compiler-generated scalar deleting destructor selected from three vtable views. Its first 32 bytes duplicate UID0004C2's three class-vptr restores and base teardown. Its remaining bytes test a hidden flags argument, optionally invoke the MemoryMan-backed global operator-delete wrapper, or call a one-byte no-op runtime stub after passing the complete-object size. Both paths return the complete object pointer with `ret 4`.

UID00031J is now `92/94` with the narrow semantic class owner retained, its emitter removed, false classification applied, and formal C++ blank. UID0004C2 remains the only destructor definition and UID00006G the only declaration owner. Generated proof-comment pollution is removed while the exact vtable, adjustor, object-size `0x30c` / 780, helper, hidden-flag, negative, and historical evidence remains in ordinary documentation.

## Supervisor Active Recheck

- Direct active-report search found no competing UID00031J report and no active B001-B005 destination claim for this target.
- The assignment's current zero-direct-report premise remains true after active, executed, Older-Research, SpecialReports, and actual archive-root searches.
- Current destination paths are stable; no rename, split registration, new UID, or shared active callback dependency is required.
- Callback collision control was completed: each accepted destination was reread after one short lease, only the bounded UID00031J delta was applied, every unrelated/current fact was preserved, and each lease was released immediately after scoped validation.
- Report validation and lifecycle status are not asserted here. This section records only bounded coordination and completed implementation facts.

## Inference Research Guidance Check

- Exact facts are separated from source inference. Bytes, hashes, instruction/block counts, vtable cells, xrefs, vptr writes, calls, flags, return ABI, padding, and helper bodies are direct evidence.
- `IMECompositionPane::~IMECompositionPane()` as the human source contract is supported by the current class declaration and UID0004C2 formal definition, not inferred solely from naming convention.
- Compiler scalar-wrapper disposition is a high-confidence inference from the complete evidence union: hidden flags, return-this ABI, vtable-only/thunk routes, duplicated ordinary teardown, runtime delete helper, no-op flag-4 helper, and absence of unique derived cleanup.
- Retaining `CANONICAL_OWNER:00006G` is a project-model decision under current owner/emitter rules. It means semantic class ownership, not source emission.
- The exact original compiler version, internal deleting-destructor symbol spelling, and build switches remain unrecoverable. They do not block the no-source decision because no handwritten destination depends on those spellings.

## Heuristic / Inference Reanalysis And Validation

| Question | Investigation | Resolution |
| --- | --- | --- |
| Is the target ordinary handwritten cleanup? | Compared every target state effect with UID0004C2 bytes and live decompilation. | No. The same three vptr stores and Pane teardown already arise from the ordinary source destructor. |
| Does the target contain unique class cleanup? | Audited all 28 instructions, five blocks, derived fields, calls, and sibling wrappers. | No unique field, container, singleton, window, string, or owned-resource cleanup exists. |
| Is `flags` a source parameter? | Traced `[ebp+8]`, low-byte tests, return-this, and `ret 4`. | No. It is hidden scalar-deleting-destructor ABI state. |
| Does bit 1 select storage deletion? | Followed both bit-1 outcomes and decompiled `0x004f4ac0`. | Yes. Bit 1 clear skips storage free; bit 1 set proceeds to the bit-4 choice. |
| Is bit 4 sized delete, vector delete, or guarded indirect deletion? | Disassembled direct callee `0x0041b6a0`, checked its size/body/xrefs and the target branch. | No. The callee is `_guard_check_icall_nop@4`, one byte `ret`, with no indirect call and no free. |
| Does `0x30c` imply source `delete` syntax? | Converted it to 780 and compared sibling wrapper shape. | No. It is complete-object-size ABI evidence on the no-op branch, not a human source argument. |
| Are adjustor entries source methods? | Hashed/disassembled both thunks and mapped their vtable cells. | No. They adjust `this` by `0xa0`/`0xa4` and tail-jump to the same compiler wrapper. |
| Could a proof comment be emitted safely? | Compared current generated output and false-page formal rules. | No. A proof comment still creates a target generated marker and is not source. Evidence belongs in prose. |
| Should owner become `NONE`? | Applied current semantic-owner versus emitter policy and compared modern executed precedent. | No. Retain class owner UID00006G; clear only the emitter and reconstructable state. |
| Is a covered-by formal comment appropriate? | Checked `by-structure.md` false-page requirements. | No. Covered-by comments are for reconstructable items covered by another emitter; a false compiler wrapper requires blank C++. |
| Is a split or rename needed? | Checked exact function boundaries, adjacent padding, child index, and binary identity. | No split or rename. Add padding to ignored documentation and correct the existing exact target in place. |
| Can scores exceed the old 86/90? | Closed every target-specific range, ABI, helper, route, ownership, source, no-code, generated, and coverage blocker. | Yes. `92/94` is supported; remaining uncertainty is original compiler-symbol/build metadata, not target behavior. |

## Evidence Standards Used

- Exact byte evidence: bounded MCP `get_bytes`, SHA256, unique prefix/VA occurrence checks, neighboring bytes, and function-boundary lookups.
- Control-flow evidence: bounded `analyze_function`, disassembly, five-block branch partition, callers/callees, and return convention.
- Data-flow evidence: all three vptr writes, stack-flag tests, complete-object receiver, object-size argument, and return-this behavior.
- Route evidence: primary vtable cell, two secondary/tertiary adjustor entries, constructor/ordinary-destructor parity, and zero ordinary callers.
- Helper evidence: direct analysis of Pane teardown, MemoryMan-backed operator-delete wrapper, and one-byte no-op runtime helper.
- Source evidence: current class managed declaration, ordinary destructor managed definition, generated output, file route, and POD/inline derived-field layout.
- Negative evidence: no unique target cleanup, no array cookie/count/loop, no vector element iteration, no indirect call, no sized deallocator, no direct ordinary caller, no source report, and no need for a second source symbol.
- Documentation evidence: current target/support pages, current structural policy, modern executed scalar-wrapper precedent, historical family leads, and all affected manual coverage rows.
- Inferences are labeled and bounded; no score is based only on a prior report or decompiler name.

## Evidence Checked

1. Fresh MCP `idb_list` identified active adopted NexusTK database `4ef1c645`, worker PID `11620`.
2. `server_health(database=4ef1c645)` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, with auto-analysis, Hex-Rays, and string cache ready; string-cache count was 2067.
3. Bounded target `lookup_funcs`, `get_bytes`, pattern search, `analyze_function`, disassembly, xrefs, and vtable/data reads all succeeded against `database=4ef1c645`.
4. A final bounded `analyze_function(addr=0x00544580)` succeeded at evidence time and confirmed the full 263-byte `Pane` ordinary teardown route, including base vptr restoration and Pane-owned cleanup. This distinguishes the shared base destructor from target source logic.
5. Exact target range, ordinary destructor, two adjustors, primary/secondary/tertiary vtable cells, constructor parity stores, helper callees, four sibling wrapper controls, and pre/post padding were checked live.
6. Search terms listed in Supporting Research were run across active, executed, Older-Research, SpecialReports, and actual `project-documentation/archived` roots. Matching paths were opened and classified; zero direct target report was found.
7. Current target/support docs listed in Supporting Research were read, including all current managed blocks and historical score/classification claims.
8. `by-structure.md` owner/emitter/false-page rules were read. A false page may retain a semantic canonical owner but must have blank emitters and blank reconstruction C++.
9. Historical pre-callback generated `auto-generated/NexusTK/input/IMEPanes.cpp` under command `000000012914` was read-only inspected and had one UID0004C2 definition plus one UID00031J proof-comment marker. Waited command `000000012929` superseded that generated state with the corrected assertions recorded below.
10. The generated tracker and generated coverage inspected during research were pre-callback derived state. B004 did not manually edit or use them as current lifecycle authority.
11. Manual `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` were read. Exact supervisor-owned replacement/addition text appears below.
12. Historical report-only phase used no ordinary validator, generated refresh, report lifecycle command, IDA mutation, or lease.
13. Accepted implementation used scoped commands `000000012922` through `000000012928`, each exit 0 / `ok:1`, and final waited command `000000012929`, exit 0 / `ok:1`, generated refresh completed.
14. The seven ordinary destinations were each leased only for their immediate edit/validator window and released immediately. No B004 lease remains.
15. No manual coverage, generated C++, tracker, audit/supervisor, validator-state, lifecycle/archive, or IDA file was manually edited. Generated/state side effects came only from authorized validators.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C31J-001 | Target range is exactly `[0x004e86c0,0x004e8715)`, 85 bytes. | Very high | MCP function lookup and successor boundary. | UID00031J header/Behavior. | incorporate | applied |
| C31J-002 | Exact target SHA256 is `70A98560325CFF07AF2772F37D414ED4B7A86470F90BB097B6396E2FF3DBBF8D`. | Very high | Bounded bytes and local SHA256. | UID00031J Evidence. | incorporate | applied |
| C31J-003 | Target has 28 instructions, five blocks, and complexity 2. | Very high | MCP analyze/disassembly. | UID00031J Evidence. | incorporate | applied |
| C31J-004 | Target writes vptrs `0x0061c3ec`, `0x0061c438`, `0x0061c468` at `this+0`, `+0xa0`, `+0xa4`. | Very high | Exact instructions/data refs. | UID00031J Behavior; UID00006G; UID00025J verify. | incorporate | applied |
| C31J-005 | The three vptr stores match UID0004C2 and constructor UID0004C1 parity. | Very high | Exact byte/store comparison. | UID00031J, UID0004C2, UID00006G. | incorporate | applied |
| C31J-006 | Call `0x00544580` is compiler-lowered `Pane` ordinary teardown, not target-specific source. | Very high | Final live analyze plus UID0001EA. | UID00031J/UID0004C2 behavior. | incorporate | applied |
| C31J-007 | Receiver is complete-object `this` in ECX; hidden flags are one stack dword and only the low byte is tested. | Very high | Prolog, stack load, tests. | UID00031J ABI. | incorporate | applied |
| C31J-008 | Bit 1 clear performs teardown and returns complete `this` without freeing storage. | Very high | Branch audit. | UID00031J flag matrix. | incorporate | applied |
| C31J-009 | Bit 1 set and bit 4 clear calls `0x004f4ac0` with complete `this`. | Very high | Branch/call audit. | UID00031J flag matrix. | incorporate | applied |
| C31J-010 | `0x004f4ac0` is the MemoryMan-backed operator-delete wrapper. | Very high | UID000197 and live callee analysis. | UID00031J support evidence. | incorporate | applied |
| C31J-011 | Bit 1 plus bit 4 pushes size `0x30c` / 780 and `this`, calls `0x0041b6a0`, and returns without storage free. | Very high | Exact branch bytes and integer conversion. | UID00031J flag matrix. | incorporate | applied |
| C31J-012 | `0x0041b6a0` is one-byte `_guard_check_icall_nop@4`, not sized/vector/indirect delete. | Very high | Lookup, one-byte disassembly, ignored row. | UID00031J negatives/history. | reject-stale | applied |
| C31J-013 | Both exits return complete `this` in EAX and use `ret 4`. | Very high | Exit disassembly. | UID00031J ABI. | incorporate | applied |
| C31J-014 | Target has no unique derived-field or resource cleanup beyond ordinary destructor lowering. | Very high | Full instruction and field audit. | UID00031J no-code proof. | incorporate | applied |
| C31J-015 | UID0004C2 is the sole source-level destructor definition and remains exact empty C++. | Very high | Current formal block and exact ordinary bytes. | UID0004C2 prose/formal R1. | already-present | already-present |
| C31J-016 | UID00006G already has the sole `virtual ~IMECompositionPane();` declaration. | Very high | Current class formal block. | UID00006G R2/method table. | already-present | already-present |
| C31J-017 | Derived fields are POD/inline storage and need no explicit target cleanup. | High | Class layout plus ordinary body. | UID0004C2/UID00006G. | incorporate | applied |
| C31J-018 | Target inbound routes are exactly two code jumps and one primary vtable data entry. | Very high | MCP xrefs. | UID00031J xref inventory. | incorporate | applied |
| C31J-019 | Thunk `[0x004e85f2,0x004e85fd)` subtracts `0xa0` and jumps to target; SHA256 `827527CFBC45290361292103BD76CEF9C2AE3D975D9F55933179D4E2D2AA0322`. | Very high | Exact bytes/hash/disassembly. | UID00018D. | incorporate | applied |
| C31J-020 | Thunk `[0x004e85fd,0x004e8608)` subtracts `0xa4` and jumps to target; SHA256 `1DC2A7A9ED390637A20BEB7C4D34DBC79029EC8FCB1C425FC02F1FC55842810C`. | Very high | Exact bytes/hash/disassembly. | UID00018D. | incorporate | applied |
| C31J-021 | Vtable first cells `0x61c3ec`, `0x61c438`, `0x61c468` resolve to target/thunk/thunk. | Very high | Raw dwords and xrefs. | UID00031J/UID00018D; UID00025J verify. | incorporate | applied |
| C31J-022 | Constructor, ordinary destructor, IME cleanup handler, and target all restore the same three class vptrs. | Very high | Data xref inventory. | UID00031J/UID00006G/UID0004C2. | incorporate | applied |
| C31J-023 | Sibling wrapper at `0x004e8800` has the same no-unique-cleanup shape with different complete size `0x2f8`. | High | Live sibling analysis. | UID00031J family control. | incorporate | applied |
| C31J-024 | Candidate and root IME wrappers preserve the same ABI skeleton plus their own unique cleanup, validating the distinction. | High | Live neighboring-function controls. | UID00031J/UID00018C history. | incorporate | applied |
| C31J-025 | Target disposition is `RECONSTRUCTABLE:FALSE` with blank emitter/position/formal. | Very high | C31J-006 through C31J-024 plus structural rules. | UID00031J metadata/R0. | incorporate | applied |
| C31J-026 | Canonical semantic owner remains UID00006G. | High | Class/vtable/source-family evidence and owner policy. | UID00031J metadata. | incorporate | applied |
| C31J-027 | Target score is `92/94`. | High | All target blockers resolved; bounded residual compiler-symbol uncertainty. | UID00031J scores/rationale. | incorporate | applied |
| C31J-028 | Historical proof-comment formal is removed, not replaced by covered-by or pseudo-code text. | Very high | False-page rule and generated pollution. | UID00031J R0. | reject-stale | applied |
| C31J-029 | Target path/name/range/Nested 0 require no rename or split. | Very high | Exact boundary and coherent ABI body. | UID00031J metadata. | already-present | already-present |
| C31J-030 | Pre-target `[0x004e86bf,0x004e86c0)` is one `CC` byte, SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`. | Very high | Bounded bytes/hash and predecessor end. | `by-memory/-ignored.md`. | incorporate | applied |
| C31J-031 | Post-target `[0x004e8715,0x004e8720)` is eleven `CC` bytes, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`. | Very high | Bounded bytes/hash and successor lookup. | `by-memory/-ignored.md`. | incorporate | applied |
| C31J-032 | UID00018C describes UID00031J as compiler-only rather than source-bearing product cleanup. | Very high | Target disposition and stale aggregate rows. | UID00018C prose/item table. | reject-stale | applied |
| C31J-033 | UID00018D stays `85/90`, false/NONE/blank; only composition-thunk precision is added. | Very high | Mixed four-class thunk aggregate. | UID00018D prose/R4. | incorporate | applied |
| C31J-034 | UID0004C2 stays `88/91`, true, owner/emitter UID00006G, exact R1; stale proof-comment wording changes only. | Very high | Source body already exact. | UID0004C2 prose/R1. | incorporate | applied |
| C31J-035 | UID00006G stays `88/91` with exact R2; method/evidence rows gain compiler/non-emitting target facts. | Very high | Current class source is complete. | UID00006G prose/R2. | incorporate | applied |
| C31J-036 | UID0000K5 stays `91/90`; source inventory expects one ordinary destructor and zero UID00031J output. | Very high | File route and generated state. | UID0000K5 prose. | incorporate | applied |
| C31J-037 | UID00025J, UID000197, UID0001EA, and UID0004C1 are verify-only and need no ordinary edit. | Very high | Current docs agree with live facts. | Verify-only destinations. | not-applicable | excluded-with-reason |
| C31J-038 | Generated UID00031J proof-comment marker is absent after implementation; UID0004C2 remains exactly once. | Very high | Current generated readback and emitter decision. | Final waited generated check. | incorporate | applied |
| C31J-039 | Manual coverage rows for target, ordinary child, aggregate, adjustors, class, and file require exact supervisor-owned synchronization. | Very high | Read-only row comparison. | Manual coverage handoff. | incorporate | applied |
| C31J-040 | The historical report-only phase used no validator/edit/lease, and the callback used only authorized scoped validators/leases with no IDA mutation or lifecycle command. | Very high | Assignment restrictions and action log. | Validator/Changed Files/checklist. | already-present | already-present |

### Callback Destination Proof

| Claim ID | Terminal state | Exact implementation or verification proof |
| --- | --- | --- |
| C31J-001 | applied | UID00031J records exact range `[0x004e86c0,0x004e8715)` and size 85; validator `000000012922`, target SHA256 `5562B4E937B72AE220CC29D14732047FD8C4CE669FB6513B4AAC67AD2C6E78E4`. |
| C31J-002 | applied | UID00031J records byte SHA256 `70A98560325CFF07AF2772F37D414ED4B7A86470F90BB097B6396E2FF3DBBF8D`; validator `000000012922`. |
| C31J-003 | applied | UID00031J records 28 instructions, five blocks, and complexity 2; validator `000000012922`. |
| C31J-004 | applied | UID00031J records all three vptr stores and offsets; UID00006G method evidence was synchronized by `000000012924`; UID00025J was reread unchanged at SHA256 `AE927672EEEC0A576DD6101EF2B8B91A6F21BE8CDDD16C093FAE07BA81A2107A`. |
| C31J-005 | applied | UID00031J, UID0004C2, and UID00006G record constructor/ordinary-wrapper vptr parity; validators `000000012922` through `000000012924`. |
| C31J-006 | applied | UID00031J and UID0004C2 distinguish compiler-lowered `Pane` teardown from target source; validators `000000012922` and `000000012923`; UID0001EA verified unchanged at SHA256 `D118C5B2EF39D35359C57003DB2593FCD87CAB3B3111293AE3466DC0EA4EE5E6`. |
| C31J-007 | applied | UID00031J records complete-object ECX, one hidden dword, low-byte tests, pointer return, and `ret 4`; validator `000000012922`. |
| C31J-008 | applied | UID00031J flag matrix records bit-1-clear teardown/no-free behavior; validator `000000012922`. |
| C31J-009 | applied | UID00031J flag matrix records bit-1-set/bit-4-clear call to `0x004f4ac0`; validator `000000012922`. |
| C31J-010 | applied | UID00031J records the MemoryMan-backed operator-delete identity; UID000197 verified unchanged at SHA256 `1EB0C5E970BFCF6F4C6664918137EAF094E76BAAF2019D272948631DD660F7F1`. |
| C31J-011 | applied | UID00031J records the `0x30c` / 780-byte no-op branch and absence of free; validator `000000012922`. |
| C31J-012 | applied | UID00031J rejects sized/vector/guarded-delete readings and preserves `_guard_check_icall_nop@4`; validator `000000012922`. |
| C31J-013 | applied | UID00031J records both EAX complete-object returns and `ret 4`; validator `000000012922`. |
| C31J-014 | applied | UID00031J exhaustive no-code proof records no unique derived-field/resource cleanup; validator `000000012922`. |
| C31J-015 | already-present | UID0004C2 retains the exact empty Destination 2 definition; validator `000000012923`, SHA256 `40DDEFCDE76CDA12949DDA5A971D68F0D4F74F0295575321B560F6926498E24D`. |
| C31J-016 | already-present | UID00006G retains the sole `virtual ~IMECompositionPane();` declaration in exact Destination 3; validator `000000012924`, SHA256 `E715C1FAD31890FA37804EAB6268B8C9A0CC8C5815DDD3C4E90C198D06389E1B`. |
| C31J-017 | applied | UID0004C2 and UID00006G preserve POD/inline-field source shape and no explicit target cleanup; validators `000000012923` and `000000012924`. |
| C31J-018 | applied | UID00031J records exactly two code jumps and one primary vtable data route; validator `000000012922`. |
| C31J-019 | applied | UID00018D records `[0x004e85f2,0x004e85fd)`, `this-0xa0`, target jump, and hash `827527CFBC45290361292103BD76CEF9C2AE3D975D9F55933179D4E2D2AA0322`; validator `000000012927`. |
| C31J-020 | applied | UID00018D records `[0x004e85fd,0x004e8608)`, `this-0xa4`, target jump, and hash `1DC2A7A9ED390637A20BEB7C4D34DBC79029EC8FCB1C425FC02F1FC55842810C`; validator `000000012927`. |
| C31J-021 | applied | UID00031J and UID00018D record the three vtable first-cell routes; UID00025J readback independently matched. |
| C31J-022 | applied | UID00031J, UID0004C2, and UID00006G record the shared three-vptr restoration set; UID0004C1 verified unchanged at SHA256 `64F0AB223F4AD1E21E31353C098D8DDE7FE44C67EB61021D74D666978C01FF01`. |
| C31J-023 | applied | UID00031J records the `0x004e8800` / `0x2f8` sibling control without promoting it to source; validator `000000012922`. |
| C31J-024 | applied | UID00031J and UID00018C preserve candidate/root sibling controls and the unique-cleanup distinction; validators `000000012922` and `000000012926`. |
| C31J-025 | applied | UID00031J now has `RECONSTRUCTABLE:FALSE`, blank emitter/position, and exact blank Destination 1; validator `000000012922`. |
| C31J-026 | applied | UID00031J retains semantic `CANONICAL_OWNER:00006G`; validator `000000012922`. |
| C31J-027 | applied | UID00031J is `92/94` with bounded residual compiler-symbol/build uncertainty; validator `000000012922`. |
| C31J-028 | applied | UID00031J proof comment was removed and not replaced; waited generated command `000000012929` proves zero UID00031J marker/name/body. |
| C31J-029 | already-present | UID00031J retained exact path/name/range and `Nested:0`; no rename or split occurred. |
| C31J-030 | applied | `by-memory/-ignored.md` contains `[0x004e86bf,0x004e86c0)` with exact one-byte hash; validator `000000012928`. |
| C31J-031 | applied | `by-memory/-ignored.md` contains `[0x004e8715,0x004e8720)` with exact eleven-byte hash; validator `000000012928`. |
| C31J-032 | applied | UID00018C now classifies UID00031J as compiler-only while preserving the mixed aggregate; validator `000000012926`, SHA256 `84525504AF95A0ACA6D0E0189591500DEFF9C720C85797FBC312355F8E2C70F1`. |
| C31J-033 | applied | UID00018D remains `85/90`, false/NONE/blank and preserves six unrelated thunks while adding the two exact composition entries; validator `000000012927`, SHA256 `19BCF3F19D8B8F4B1A6190B6FB41371B04EC050691759BB8A53456E9424A7D2B`. |
| C31J-034 | applied | UID0004C2 remains `88/91` with exact Destination 2; only stale target-wrapper prose changed; validator `000000012923`. |
| C31J-035 | applied | UID00006G remains `88/91` with exact Destination 3; only target method/evidence/history rows changed; validator `000000012924`. |
| C31J-036 | applied | UID0000K5 remains `91/90` and now expects one ordinary destructor and zero UID00031J output; validator `000000012925`, SHA256 `EACA42726BB183AFB963531ECC6674DC77E452CB448783775CE256D7E3456256`. |
| C31J-037 | excluded-with-reason | UID00025J, UID000197, UID0001EA, and UID0004C1 were reread, matched direct evidence, and remained byte-for-byte unchanged; their hashes are recorded above and under Changed Files. |
| C31J-038 | applied | Waited command `000000012929` generated SHA256 `4F74F6055B8F7EE071A1B4D37F31FA53B271F1E567920C2D69B4F9D7AF0D5CCA`: one UID0004C2 definition, zero UID00031J marker/name/body, zero target empty marker, and zero target ABI pseudo-source. |
| C31J-039 | applied | Exact manual coverage handoff text remains below after read-only comparison; B004 did not edit manual coverage and does not assert supervisor-owned synchronization state. |
| C31J-040 | already-present | Restrictions held: no IDA mutation, manual coverage/generated/manual-state edit, report lifecycle/count/revalidation/execute/move/archive command, or retained lease occurred. |

## Positive Evidence Summary

- Exact bytes and complete CFG establish a classic hidden-flag deleting wrapper rather than a normal source signature.
- Exact overlap with UID0004C2 establishes the source destructor cause: three class-vptr writes followed by Pane teardown.
- Exact target-only suffix establishes compiler/runtime behavior: flags, MemoryMan-backed free, no-op bit-4 path, return-this, and `ret 4`.
- Exact vtable and thunk routes explain reachability without ordinary callers.
- Exact ordinary source block and class declaration already provide all human source needed.
- Exact sibling controls show when class-specific cleanup exists and that UID00031J lacks it.
- Exact current project policy and modern scalar-wrapper precedent support class ownership without source emission.
- Generated readback demonstrates the concrete defect: the current proof comment is output even though no target source body exists.

## IDA MCP Facts

- Evidence database: `4ef1c645`; session was healthy when every fact below was collected.
- Target lookup: `sub_4E86C0`, size `0x55`; no function starts at `0x004e8715`.
- Target exact bytes:

```text
55 8b ec 56 8b f1 c7 06 ec c3 61 00 c7 86 a0 00
00 00 38 c4 61 00 c7 86 a4 00 00 00 68 c4 61 00
e8 9b be 05 00 8b 45 08 a8 01 74 22 a8 04 75 10
56 e8 ca c3 00 00 83 c4 04 8b c6 5e 5d c2 04 00
68 0c 03 00 00 56 e8 95 2f f3 ff 83 c4 08 8b c6
5e 5d c2 04 00
```

- Unique prefix `55 8B EC 56 8B F1 C7 06 EC C3 61 00` occurs once in the image. Target VA bytes `C0 86 4E 00` occur once, at primary vtable cell `0x0061c3ec`.
- IDA prototype is decompiler-shaped `_DWORD *__thiscall(_DWORD *Block, char)`. Source interpretation is not a public method; ECX is complete `this`, stack argument is hidden flags, EAX returns complete `this`.
- Basic blocks: `[0x4e86c0,0x4e86ec)`, `[0x4e86ec,0x4e86f0)`, `[0x4e86f0,0x4e8700)`, `[0x4e8700,0x4e870e)`, `[0x4e870e,0x4e8715)`.
- Exact ordinary destructor `sub_4E7450` is 31 bytes, SHA256 `E6EFA584158F5D21791471B950A6648C1FA3F178A777B5105085BFDD7196BFD4`, with bytes:

```text
c7 01 ec c3 61 00 c7 81 a0 00 00 00 38 c4 61 00
c7 81 a4 00 00 00 68 c4 61 00 e9 11 d1 05 00
```

- Ordinary destructor has zero inbound xrefs. That is a binary reachability caveat, not no-source evidence; its class declaration, exact compiler lowering, constructor parity, and deleting-wrapper route establish the source destructor.
- Pane teardown `0x00544580` is 263 bytes with 15 blocks and complexity 7. It restores Pane views and performs Pane-owned cleanup before deeper base teardown. The target does not contain that logic itself; it calls the shared routine.
- Operator-delete `0x004f4ac0` reaches MemoryMan initialization/free machinery. It is a runtime storage action, not a target class method.
- Guard helper `0x0041b6a0` is exactly one byte `ret`. No indirect target, deallocator, loop, or state change exists.

## Function / Child Inventory

| Range/address | Current UID | Role | Source disposition | Target-pass action |
| --- | --- | --- | --- | --- |
| `[0x004e7450,0x004e746f)` | UID0004C2 | Ordinary `IMECompositionPane` destructor | Human source definition | Preserve exact R1; correct stale wrapper wording. |
| `[0x004e85f2,0x004e85fd)` | UID00018D subrange | `this -= 0xa0` adjustor | Compiler-only | Add exact hash/route. |
| `[0x004e85fd,0x004e8608)` | UID00018D subrange | `this -= 0xa4` adjustor | Compiler-only | Add exact hash/route. |
| `[0x004e86bf,0x004e86c0)` | ignored gap | One `CC` alignment byte | No source | Add exact ignored row. |
| `[0x004e86c0,0x004e8715)` | UID00031J | Complete-object scalar deleting wrapper | Compiler-only | Reclassify false/non-emitting/blank. |
| `[0x004e8715,0x004e8720)` | ignored gap | Eleven `CC` alignment bytes | No source | Add exact ignored row. |
| `0x0061c3ec` | UID00025J subrange | Primary vtable first function cell | Compiler data | Verify-only. |
| `0x0061c438` | UID00025J subrange | Secondary vtable first function cell | Compiler data | Verify-only. |
| `0x0061c468` | UID00025J subrange | Tertiary vtable first function cell | Compiler data | Verify-only. |
| `0x00544580` | UID0001EA family | Pane ordinary teardown | Human Pane source lowered by compiler | Verify-only. |
| `0x004f4ac0` | UID000197 | MemoryMan-backed operator delete | Runtime/storage support | Verify-only. |
| `0x0041b6a0` | ignored runtime helper | One-byte no-op | Compiler/runtime | Already exact in ignored docs. |

No new child UID is needed. UID00031J already is the exact function child; the adjacent `CC` spans are padding, not functions.

## Direct Xref / Caller Inventory

- Direct inbound xrefs to target are exactly:
  - code jump from `0x004e85f8`, inside the `this -= 0xa0` adjustor;
  - code jump from `0x004e8603`, inside the `this -= 0xa4` adjustor;
  - data reference from primary vtable cell `0x0061c3ec`.
- Secondary vtable cell `0x0061c438` points to `0x004e85f2`; tertiary cell `0x0061c468` points to `0x004e85fd`.
- Vptr locator writes occur in four lifecycle bodies:
  - primary: `0x004e73cd`, `0x004e7450`, `0x004e8238`, `0x004e86c6`;
  - secondary: `0x004e73d3`, `0x004e7456`, `0x004e823e`, `0x004e86cc`;
  - tertiary: `0x004e73dd`, `0x004e7460`, `0x004e8248`, `0x004e86d6`.
- There is no normal direct call from product source to UID00031J. Virtual destruction enters through vtable cells; adjusted subobject views enter through compiler thunks.
- UID0004C2 has zero direct inbound xrefs, consistent with optimizer/compiler destructor organization in this image. It remains the source body because the class declares the virtual destructor and UID00031J invokes equivalent lowering.

## Documentation Evidence And IDA Status

- IDA MCP database `4ef1c645` was healthy at evidence collection time. No indefinite claim about future session availability is made.
- Historical pre-callback UID00031J got the binary identity broadly right but incorrectly treated a compiler wrapper as reconstructable/emitting and left stale `85/89` score prose below a `86/90` header. Current UID00031J has the accepted false/non-emitting `92/94` disposition and exact blank formal.
- UID0004C2 already contained the exact empty source destructor; its former target proof-comment wording is now explicitly historical while the source definition remains byte-for-byte exact.
- UID00006G already had the exact declaration and class layout. Its current method table adds the precise non-emitting compiler-wrapper row without another declaration.
- UID0000K5 historically expected the scalar-wrapper proof comment. It now records one source ordinary destructor and the wrapper as binary-only evidence with zero generated target output.
- UID00018C historically grouped UID00031J with source-bearing product pieces. It now distinguishes this compiler wrapper without changing the broad aggregate's score/formal state.
- UID00018D retained the correct false/blank compiler-glue disposition and now includes exact composition-thunk deltas, hashes, and vtable routes.
- UID00025J records the three composition vtable views accurately and remained verify-only unchanged.
- UID000197, UID0001EA, and UID0004C1 agree with the live evidence and remained verify-only unchanged.
- Historical generated command `000000012914` demonstrated one correct UID0004C2 source definition and one incorrect UID00031J proof-comment marker. Final callback readback under waited command `000000012929` demonstrated one UID0004C2 definition and zero UID00031J output.

## Ranked Ownership Analysis

1. **UID00006G semantic owner, no target emitter - selected.** All three vtable views, constructor/ordinary-destructor parity, target identity, and source route belong to `IMECompositionPane`. Current project rules allow semantic ownership to remain when a compiler artifact is non-reconstructable and non-emitting.
2. **UID0000K5 file ownership - rejected as direct owner.** The source file owns the class, but the narrowest semantic target owner is the class UID, not the file UID.
3. **UID0004C2 as target owner/emitter - rejected.** UID0004C2 is a sibling source method, not the parent entity. It supplies the source definition but should not own the compiler wrapper page.
4. **`CANONICAL_OWNER:NONE` - rejected.** That would discard useful class/vtable identity and conflicts with the current semantic-owner mechanism demonstrated by modern scalar-wrapper handling.
5. **Target remains an emitter - rejected.** The target has no source body. Emission creates only a documentation comment and duplicate pseudo-entity in generated C++.

## Source Placement

- Human declaration: UID00006G `by-class/IMECompositionPane.md`.
- Human definition: UID0004C2 `by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md`.
- Human source file: UID0000K5 `by-file/IMEPanes.md` -> generated route `NexusTK/input/IMEPanes.cpp`.
- Binary/compiler evidence: UID00031J target, UID00018D thunks, UID00025J vtable data, and `by-memory/-ignored.md` alignment/runtime rows.
- No new `.cpp`, helper declaration, deleting-destructor method, explicit specialization, or import directive is appropriate.
- Original source likely contains only the virtual destructor declaration plus its empty definition. The compiler emits ordinary destructor lowering, deleting wrapper, adjusted entries, and vtable cells.

## Range / Split / Padding / Reclassification Analysis

- The target starts exactly at the unique prolog `0x004e86c0` and ends at the final `ret 4` boundary `0x004e8715`.
- No internal padding, adjacent function, table, or source-bearing child exists within the 85-byte range.
- The five blocks all implement one deleting-wrapper state machine. Splitting teardown from delete flags would cut one compiler function and create non-source fragments.
- Predecessor IMECandidate wrapper ends at `0x004e86bf`; one `CC` byte fills `[0x004e86bf,0x004e86c0)`.
- Eleven `CC` bytes fill `[0x004e8715,0x004e8720)` before successor `IMEPane` wrapper.
- Reclassification was metadata/formal only: true/emitting proof comment -> false/non-emitting blank. Path, title, range, owner, optional position, and `Nested:0` stayed stable.
- UID00018C remains a broad false aggregate. UID00018D remains a broad false compiler-thunk aggregate. Neither should emit or be split by this callback.

## Negative Evidence Summary

- No direct product caller invokes the target by name.
- No unique derived field is read, written, destroyed, freed, detached, or cleared by the target.
- No composition string, drag state, cursor state, IME handle, singleton, queue, child pane, or event callback appears.
- No array cookie, element count, stride, repeated destructor loop, vector-delete loop, or array deallocator exists.
- No indirect call occurs on the bit-4 branch.
- No storage free occurs on the bit-4 branch.
- No size-consuming deallocator receives `0x30c`; the direct callee is a one-byte no-op.
- No evidence supports a public/private source method with a flags parameter or pointer return.
- No direct prior target report exists.
- No source body is missing: UID0004C2 and UID00006G already provide the complete human contract.
- No covered-by proof comment is needed because the target is compiler-only, not reconstructable source covered by another emitter.
- No path rename, child registration, owner reassignment to `NONE`, or source-file split is warranted.

## IDA Rename / Type / Comment Recommendations

- Do not mutate IDA during this report/callback. The current database function name `sub_4E86C0` may remain unchanged.
- Documentation binary identity `IMECompositionPaneScalarDeletingDestructor` is sufficient and precise.
- If a future supervisor-owned IDA annotation is desired, use a non-source ABI comment such as: `MSVC scalar deleting destructor for IMECompositionPane; hidden flags; class source destructor is 0x004e7450; bit4 reaches one-byte no-op.` This is optional and outside implementation scope.
- Do not type the function as a public C++ member. A diagnostic ABI type may model complete-object `this`, hidden unsigned flags, and pointer return, but it must not become emitted source.
- Preserve `0x0041b6a0` as `_guard_check_icall_nop@4`; do not rename it to sized delete, guarded delete, vector delete, or deallocator.
- Preserve `0x004f4ac0` as the existing operator-delete wrapper identity.

## First-Draft C++ Recommendation

The target has an exhaustive no-code disposition. Its current complete managed block is exactly blank.

### Destination 1 - UID00031J exact target block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID0004C2 exact preserved source definition

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMECompositionPane::~IMECompositionPane()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID00006G exact preserved class block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class IMEPane;
class Pane;

class IMECompositionPane : public Pane
{
public:
    IMECompositionPane();
    virtual ~IMECompositionPane();

    void SetCompositionString(const wchar_t *text, int length);
    int GetCompositionWidth() const;

protected:
    virtual bool OnMouseEvent(const Event *event);
    virtual bool OnKeyEvent(const Event *event);
    virtual void OnPaint();

private:
    int compositionCursorX;              // +0xf8, cached cursor pixel offset.
    wchar_t compositionText[256];        // +0xfc, bounded UTF-16 composition text.
    bool compositionDragActive;          // +0x2fc, true while the popup is being dragged.
    int compositionDragStartY;           // +0x300, mouse event +0x08 at drag start.
    int compositionDragStartX;           // +0x304, mouse event +0x0c at drag start.
    unsigned char compositionDragSavedMode;  // +0x308, saved Pane mode byte.
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID00018C exact preserved blank aggregate block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID00018D exact preserved blank compiler-thunk block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No managed block exists in UID0000K5 or `by-memory/-ignored.md`; their recommendations are prose-only. No draft/sample/pseudo C++ may be placed outside these managed destinations.

## Final Recommendation

The bounded seven-destination documentation correction is implemented: target UID00031J, source destructor UID0004C2, class UID00006G, file UID0000K5, aggregate UID00018C, adjustors UID00018D, and `by-memory/-ignored.md`. Verify-only UID00025J, UID000197, UID0001EA, and UID0004C1 were reread and preserved unchanged.

The target is `92/94`, class-owned, false, non-emitting, and blank. Its prose retains every exact byte/hash/CFG/vtable/thunk/helper/flag/padding/history/negative fact and explicitly rejects sized/vector/guarded deletion. Source remains exactly one empty ordinary destructor. Final waited command `000000012929` removed the UID00031J generated marker while retaining exactly one UID0004C2 definition and no explicit target compiler ABI code.

No implementation item remains. Report validation, execution, count, path movement, and archive state remain external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.

## Recommended Target Doc Changes

Applied to UID00031J:

1. Changed `COMPLETION:86 -> 92` and `CONFIDENCE:90 -> 94`.
2. Retained `CANONICAL_OWNER:00006G`, blank optional position, exact UID/path/title/range, and `Nested:0`.
3. Changed `RECONSTRUCTABLE:TRUE -> FALSE` and `EMITTER_UIDS:00006G -> blank`.
4. Replaced the proof-comment formal with Destination 1's exact blank managed block.
5. Replaced Item Summary with: `Exact class-owned MSVC scalar deleting destructor wrapper for IMECompositionPane; duplicates UID0004C2 ordinary teardown, interprets hidden delete flags, and remains non-reconstructable/non-emitting with blank formal C++.`
6. Replaced reconstructable-product Status with compiler-generated wrapper disposition and explicit source route through UID0004C2/UID00006G/UID0000K5.
7. Added exact bytes/hash, 28-instruction/five-block CFG, three vptr writes, all direct xrefs, both thunk hashes, vtable cells, flag matrix, `0x30c` / 780 size fact, helper identities, exact padding, sibling controls, negative evidence, source/no-code proof, rejected alternatives, and historical B008/B010 context.
8. Corrected stale Score Rationale to `92/94` and documented the bounded residual uncertainty.
9. Historicalized the 2026-06-30 proof-comment emitter as superseded current-policy behavior without deleting the historical record.

## Recommended Support Doc Changes

### UID0004C2 ordinary destructor

- Preserved `88/91`, owner/emitter UID00006G, true, blank optional position, `Nested:0`, and Destination 2 exactly.
- Replaced stale proof-comment language with current truth: UID00031J is false/non-emitting/blank; UID0004C2 is the only source definition.
- Added exact target no-op bit-4 behavior and stated that storage-delete flags never belong in R1.

### UID00006G class

- Preserved `88/91`, owner/emitter UID0000K5, true, position 0, and Destination 3 exactly.
- Replaced the generic `Deleting destructor wrapper` row with `92/94`, class-owned compiler wrapper, false/non-emitting, exact three-vtable/adjustor/hidden-flag/object-size facts, and source coverage by UID0004C2.
- Historicalized old child-gate score language without changing unrelated methods or fields.

### UID0000K5 file

- Preserved `91/90`, path `NexusTK/input/`, canonical owner FILE, all family routes, and all unrelated content.
- Updated only UID00031J inventory/history/generated expectations: one UID0004C2 source destructor, zero target marker/comment/body, compiler wrapper retained as documentation evidence.

### UID00018C mixed aggregate

- Preserved `86/91`, owner NONE, false, blank emitter/position/formal, `Nested:-4`, exact broad range, and unrelated children.
- Corrected the target row from `85/89` source-bearing cleanup to `92/94` compiler-only class-owned wrapper whose human source is UID0004C2.
- Replaced broad claims that every scalar-wrapper child is source-bearing and distinguished source cleanup children from compiler wrappers while retaining exact index/history.

### UID00018D adjustor aggregate

- Preserved `85/90`, owner NONE, false, blank emitter/position/formal, `Nested:0`, and all other six thunk entries.
- Added exact composition thunk ranges, bytes/hashes, `this` deltas, jump target, and vtable cells. Both are documented as compiler-only and source behavior remains the ordinary virtual destructor.

### `by-memory/-ignored.md`

- Added `[0x004e86bf,0x004e86c0)` one-byte `CC` alignment with SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`, between candidate and composition wrappers.
- Added `[0x004e8715,0x004e8720)` eleven-byte `CC` alignment with SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, between composition and root-pane wrappers.
- Preserved the existing UID00018D ignored-thunk row and one-byte `0x0041b6a0` runtime-helper row.

### Verify-only destinations

- UID00025J vtable data, UID000197 operator delete, UID0001EA Pane core, and UID0004C1 constructor matched direct evidence during callback reread and remained unchanged.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Current implemented state | Basis | Residual limit |
| --- | --- | --- | --- | --- |
| UID00031J | `86/90`, owner/emitter 00006G, true | `92/94`, owner 00006G, false, blank emitter/position/R0, Nested 0 | Exact range/hash/CFG/ABI/xrefs/vtables/thunks/helpers/source/no-code/generation/coverage closure. | Exact original compiler symbol/version/build switches remain unavailable. |
| UID0004C2 | `88/91` | unchanged | Exact ordinary bytes and R1 already source-ready. | Zero direct xrefs and stripped original symbols remain bounded historical caveats. |
| UID00006G | `88/91` | unchanged | Target pass adds compiler-wrapper precision, not broader class-method recovery. | Unrelated exact original field/method tokens remain outside target scope. |
| UID0000K5 | `91/90` | unchanged | Source route is already established; only output expectation changes. | Exact original file name remains inferred. |
| UID00018C | `86/91` | unchanged | Broad mixed island remains correctly false. | Many unrelated helpers remain broad-index evidence. |
| UID00018D | `85/90` | unchanged | Two composition thunks become exact, but page covers eight thunks across four classes. | Other class-specific naming remains aggregate-level. |

`92/94` materially improves the target because every reasonable target-specific route is exhausted. It does not claim source reconstructability; the higher scores measure certainty and documentation completeness of the compiler-only disposition.

## Open Questions With Attempted Resolution

- **Could bit 4 still represent sized deletion because size is pushed?** Direct callee inspection proves the called function is a one-byte `ret` with no indirect dispatch or free. Resolved: no sized delete source contract.
- **Could flags be an original explicit parameter?** Vtable-only/thunk routes, return-this, `ret 4`, and sibling wrappers match compiler ABI. Resolved: hidden compiler flags.
- **Could UID00031J own the empty destructor body instead of UID0004C2?** UID0004C2 exactly matches the ordinary destructor lowering and already owns the formal definition. Resolved: UID0004C2 is source; UID00031J is compiler wrapper.
- **Should target retain a covered-by comment?** False-page rules require blank formal C++; current comment visibly pollutes generated output. Resolved: blank only.
- **Should target owner be NONE?** Exact class vtables and current semantic-owner policy favor UID00006G without an emitter. Resolved: retain class owner.
- **Does zero xrefs to UID0004C2 invalidate its source role?** No. Destructor organization/optimization can make the ordinary body unreachable as a standalone symbol; exact source declaration and deleting-wrapper parity remain. Resolved: preserve source body with reachability caveat.
- **Is a target split needed for teardown versus delete?** Both portions are one compiler ABI function and neither is independent human source. Resolved: no split.
- **Are adjacent bytes part of target?** Function end and successor lookup plus exact `CC` spans resolve both gaps. Resolved: target range unchanged; padding documented separately.
- **Is another report needed to resolve sibling wrappers?** No target blocker depends on them. Four sibling controls were analyzed now. Resolved: target recommendation is implementation-ready.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual coverage was read-only compared. Validator-generated coverage does not satisfy this handoff. The following exact text remains the durable supervisor-owned synchronization handoff after completed ordinary callback verification; B004 did not edit these files and does not assert their external application state.

### `by-memory/-coverage-report.md` replace UID00031J row

```text
        - [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) 0x004e86c0-0x004e8715 | compiler-generated scalar deleting destructor wrapper | IMECompositionPaneScalarDeletingDestructor : not_reconstructable : 92% : very-strong : Exact 85-byte MSVC wrapper, SHA256 70A98560325CFF07AF2772F37D414ED4B7A86470F90BB097B6396E2FF3DBBF8D; primary vtable plus -0xa0/-0xa4 adjustor entries reach it, it duplicates UID0004C2 vptr/Pane teardown, bit 1 selects MemoryMan-backed operator delete, and bit 4 reaches the one-byte no-free runtime stub. Human source is the single virtual IMECompositionPane destructor in UID0004C2; UID00031J remains class-owned but non-emitting with blank formal C++.
```

### `by-memory/-coverage-report.md` add UID0004C2 row adjacent to the composition constructor/method children

```text
        - [UID:0004C2][0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor](by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md) 0x004e7450-0x004e746f | ordinary destructor | IMECompositionPane::~IMECompositionPane : reconstructable : 88% : very-strong : Exact empty source destructor definition; the 31-byte binary restores three IMECompositionPane vptrs and tail-transfers to Pane teardown, while UID00031J owns only non-emitting compiler deleting-wrapper evidence.
```

### `by-memory/-coverage-report.md` replace UID00018C row

```text
    - [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md) 0x004e8450-0x004e8ae6 | reviewed mixed aggregate/index | IMECandidateQueueAndDestructors : not_reconstructable : 86% : very-strong : Broad index over exact IME source cleanup children, compiler scalar-deleting wrappers, compiler adjustor thunks, ignored STL deque/wstring helpers, and padding; UID00031J is class-owned compiler output whose human source is UID0004C2, while live IDA confirms all boundaries and InputMan alignment.
```

### `by-memory/-coverage-report.md` replace UID00018D row

```text
        - [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md) : ignored : 85% : very-strong : Eight compiler-generated secondary/tertiary destructor adjustor thunks for four IME pane classes; composition entries [0x004e85f2,0x004e85fd) and [0x004e85fd,0x004e8608) subtract 0xa0/0xa4 and jump to non-emitting UID00031J. No handwritten NexusTK source body is emitted.
```

### `by-class/-coverage-report.md` replace UID00006G row

```text
- [UID:00006G][IMECompositionPane](by-class/IMECompositionPane.md) : reconstructable : 88% : strong : IME composition popup pane attached to IMEPanes with constructor, exact empty ordinary destructor UID0004C2, set-string, mouse, key, paint, and width methods; compiler-only UID00031J is class-owned but false/non-emitting/blank and is reached through three vtable views plus two adjustor entries.
```

### `by-file/-coverage-report.md` replace UID0000K5 row

```text
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md) : reconstructable : 91% : very-strong : NexusTK/input/IMEPanes.cpp source root with complete status/composition/candidate/root pane ordering, g_pIMEPane singleton, exact source destructor and helper routes, candidate-string STL/template caveats, and explicit compiler-wrapper exclusions; UID0004C2 emits the one IMECompositionPane destructor while UID00031J remains non-reconstructable/non-emitting binary evidence with no generated marker or body.
```

No separate manual coverage row exists for `by-memory/-ignored.md`; the current manual by-memory coverage was searched for both padding ranges and has no row to replace. The exact additions belong only in the ordinary ignored document. UID00025J, UID000197, UID0001EA, and UID0004C1 rows need no target-pass change after read-only comparison.

## Follow-Up Actions

- The bounded seven-destination implementation, scoped validators, lease releases, and waited generated verification are complete; no ordinary implementation item remains.
- Each destination was reread under its short lease, rebased without loss of unrelated/current content, scoped-validated, and immediately released.
- Waited command `000000012929` proved exactly one UID0004C2 destructor definition; zero UID00031J marker/name/body; zero target Empty Emitter Marker; and no explicit target vptr, hidden flags, adjustor, object-size, operator-delete, or no-op-helper source.
- Manual coverage synchronization remains supervisor-owned. Exact text is supplied above; B004 did not edit manual coverage and this artifact does not assert its external synchronization state.
- Report validation, execution, count, path movement, and archive state remain external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.

## Confidence

- Overall disposition confidence: `94/100`.
- Documentation completeness recommendation: `92/100`.
- Range/bytes/hash/CFG/ABI confidence: very high.
- Vtable/adjustor/helper/source-route confidence: very high.
- No-code/formal-blank confidence: very high.
- Canonical class-owner recommendation: high.
- Residual uncertainty: exact original compiler version, internal deleting-destructor symbol spelling, and build switches are unavailable in the stripped binary. None would change the human source result.

## Validator Results

All validator commands were run from `source-3/project-documentation` in scoped file mode. Each ordinary validator ran while B004 held only that file's short lease; the lease was released immediately afterward.

| Final ordinary path | Command | Timestamp | Exit / ok | Warnings | Validator-managed side effects | Current SHA256 |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md` | `000000012922` | `2026-07-15T06:49:16-04:00` | `0 / 1` | None reported. | Rebuilt four autogen registry entries; refreshed completion/confidence data; corrected two UID000197 reverse links to its current path; projected stats; generated refresh deferred. | `5562B4E937B72AE220CC29D14732047FD8C4CE669FB6513B4AAC67AD2C6E78E4` |
| `by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md` | `000000012923` | `2026-07-15T06:50:29-04:00` | `0 / 1` | None reported. | Refreshed one reverse-reference set; projected stats; generated refresh deferred. | `40DDEFCDE76CDA12949DDA5A971D68F0D4F74F0295575321B560F6926498E24D` |
| `by-class/IMECompositionPane.md` | `000000012924` | `2026-07-15T06:51:21-04:00` | `0 / 1` | None reported. | Projected stats; generated refresh deferred. | `E715C1FAD31890FA37804EAB6268B8C9A0CC8C5815DDD3C4E90C198D06389E1B` |
| `by-file/IMEPanes.md` | `000000012925` | `2026-07-15T06:52:38-04:00` | `0 / 1` | None reported. | Projected stats; generated refresh deferred. | `EACA42726BB183AFB963531ECC6674DC77E452CB448783775CE256D7E3456256` |
| `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` | `000000012926` | `2026-07-15T06:54:04-04:00` | `0 / 1` | None reported. | Projected stats; generated refresh deferred. | `84525504AF95A0ACA6D0E0189591500DEFF9C720C85797FBC312355F8E2C70F1` |
| `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` | `000000012927` | `2026-07-15T06:54:57-04:00` | `0 / 1` | None reported. | Refreshed two reverse-reference sets; projected stats; generated refresh deferred. | `19BCF3F19D8B8F4B1A6190B6FB41371B04EC050691759BB8A53456E9424A7D2B` |
| `by-memory/-ignored.md` | `000000012928` | `2026-07-15T06:55:56-04:00` | `0 / 1` | `missing_ref_uid:277`, a pre-existing broad ignored-index warning set; first listed UIDs were 0003E6/E7/E8/E9/J2/J3/BR/BS/BT/BU and 267 were suppressed. | Validator-managed unrelated UID0003TD link correction to `MapPaneRemoveGroupMemberHitBar`; four reverse-reference updates; projected stats; generated refresh deferred. | `40D6FBA6B55A05F740555B9A1A61F153EC110978CCDA5E45872BCB81683A6664` |

Final authorized waited validation:

- Command `000000012929`, timestamp `2026-07-15T06:56:40-04:00`, target UID00031J final path, exit `0`, `ok:1`; generated refresh completed at the same timestamp.
- Broad generator warnings were `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:86`, `autogen_emitter_has_no_code:170`, and `generated_metadata_refresh:281`; none was a target validation error.
- Generated `auto-generated/NexusTK/input/IMEPanes.cpp` SHA256 `4F74F6055B8F7EE071A1B4D37F31FA53B271F1E567920C2D69B4F9D7AF0D5CCA` has one UID0004C2 marker and exactly one `IMECompositionPane::~IMECompositionPane()` definition, at generated line 225.
- It has zero UID00031J UID/name/body occurrence, zero Empty Emitter Marker, zero target vptr-address occurrence (`0x0061c3ec`, `0x0061c438`, `0x0061c468`), zero `0x30c`, operator-delete, `_guard_check_icall_nop`, hidden-delete-flag, or target adjustor source. Three unrelated sibling proof comments containing the word `adjustor` remain outside UID00031J and were not changed.
- No report lifecycle, count, probe, revalidation, `execute_report`, move, or archive command was run.

## Changed Files

- `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md` - bounded target metadata/formal/evidence correction; SHA256 `5562B4E937B72AE220CC29D14732047FD8C4CE669FB6513B4AAC67AD2C6E78E4`.
- `by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md` - target-wrapper prose synchronization only; SHA256 `40DDEFCDE76CDA12949DDA5A971D68F0D4F74F0295575321B560F6926498E24D`.
- `by-class/IMECompositionPane.md` - target method/evidence/history synchronization only; SHA256 `E715C1FAD31890FA37804EAB6268B8C9A0CC8C5815DDD3C4E90C198D06389E1B`.
- `by-file/IMEPanes.md` - target inventory/history/generated expectation synchronization only; SHA256 `EACA42726BB183AFB963531ECC6674DC77E452CB448783775CE256D7E3456256`.
- `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` - target source/compiler distinction only; SHA256 `84525504AF95A0ACA6D0E0189591500DEFF9C720C85797FBC312355F8E2C70F1`.
- `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` - exact two composition-thunk facts only; SHA256 `19BCF3F19D8B8F4B1A6190B6FB41371B04EC050691759BB8A53456E9424A7D2B`.
- `by-memory/-ignored.md` - exact one-byte and eleven-byte padding entries plus validator-managed unrelated UID0003TD link correction; SHA256 `40D6FBA6B55A05F740555B9A1A61F153EC110978CCDA5E45872BCB81683A6664`.
- This same report was reconciled from accepted Gate 1 SHA256 `74CD80E1C0352C4863D732CE0E82D501D28ABD8A0B58F8C70D5723918E026CDB`; its current hash is computed externally after final byte review to avoid a circular self-hash assertion.
- Verify-only unchanged: UID00025J SHA256 `AE927672EEEC0A576DD6101EF2B8B91A6F21BE8CDDD16C093FAE07BA81A2107A`; UID000197 `1EB0C5E970BFCF6F4C6664918137EAF094E76BAAF2019D272948631DD660F7F1`; UID0001EA `D118C5B2EF39D35359C57003DB2593FCD87CAB3B3111293AE3466DC0EA4EE5E6`; UID0004C1 `64F0AB223F4AD1E21E31353C098D8DDE7FE44C67EB61021D74D666978C01FF01`.
- Restricted/manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/archive/IDA files manually edited: zero. Generated/state side effects were validator-owned.
- All seven short leases were released immediately after their validators; retained B004 leases: zero.

## Implementation Tracking Checklist

### Report-Only Research Phase

- [x] Supervisor accepted exact pre-callback report SHA256 `74CD80E1C0352C4863D732CE0E82D501D28ABD8A0B58F8C70D5723918E026CDB` for this bounded implementation.
- [x] Callback-time reread confirmed UID00031J had the documented historical pre-callback state and no concurrent contradiction.
- [x] Callback-time reread confirmed every support destination could preserve all unrelated/current content.

### Target Implementation

- [x] Leased only UID00031J immediately before its edit.
- [x] Applied `92/94`, owner UID00006G, false, blank emitter/position, `Nested:0`, and exact Destination 1.
- [x] Applied all exact target bytes/hash/CFG/ABI/vtable/thunk/helper/flag/padding/source/history/negative/rejected-alternative evidence without compression.
- [x] Replaced stale Item Summary, Status, Reconstruction Notes, Score Rationale, and proof-comment current-state wording while preserving historical facts.
- [x] Scoped-validated UID00031J with `000000012922` and released its lease immediately.

### Support Implementation

- [x] Leased/reread/rebased UID0004C2; preserved `88/91` and Destination 2; changed only target-wrapper prose; scoped validator `000000012923`; released immediately.
- [x] Leased/reread/rebased UID00006G; preserved `88/91` and complete Destination 3; changed only target method/evidence/history rows; scoped validator `000000012924`; released immediately.
- [x] Leased/reread/rebased UID0000K5; preserved `91/90` and unrelated family content; changed target inventory/generated expectation; scoped validator `000000012925`; released immediately.
- [x] Leased/reread/rebased UID00018C; preserved `86/91`, false/NONE/blank, `Nested:-4`, and unrelated index entries; corrected source/compiler distinctions; scoped validator `000000012926`; released immediately.
- [x] Leased/reread/rebased UID00018D; preserved `85/90`, false/NONE/blank and six unrelated thunks; added exact two composition-thunk facts; scoped validator `000000012927`; released immediately.
- [x] Leased/reread/rebased `by-memory/-ignored.md`; added exactly the one-byte and eleven-byte alignment entries and preserved current facts; scoped validator `000000012928`; released immediately.
- [x] Verified UID00025J vtable data unchanged and exact at SHA256 `AE927672EEEC0A576DD6101EF2B8B91A6F21BE8CDDD16C093FAE07BA81A2107A`.
- [x] Verified UID000197 operator-delete wrapper unchanged and exact at SHA256 `1EB0C5E970BFCF6F4C6664918137EAF094E76BAAF2019D272948631DD660F7F1`.
- [x] Verified UID0001EA Pane teardown unchanged and exact at SHA256 `D118C5B2EF39D35359C57003DB2593FCD87CAB3B3111293AE3466DC0EA4EE5E6`.
- [x] Verified UID0004C1 constructor parity unchanged and exact at SHA256 `64F0AB223F4AD1E21E31353C098D8DDE7FE44C67EB61021D74D666978C01FF01`.

### Validation And Generated Verification

- [x] Ran exactly one scoped file validator per changed ordinary destination and recorded command ID, timestamp, exit, ok, warnings, and side effects above.
- [x] Confirmed every immediate edit lease was released and no B004 lease remains.
- [x] Ran authorized final `--wait-generated` command `000000012929` on UID00031J.
- [x] Verified generated `NexusTK/input/IMEPanes.cpp` has exactly one UID0004C2 destructor definition.
- [x] Verified generated output has zero UID00031J marker/name/body and zero target Empty Emitter Marker.
- [x] Verified generated output contains no explicit target vptr, hidden flags, target adjustor, `0x30c`, operator-delete, or no-op-helper source.
- [x] Verified the bounded target/class/source definitions remain singular and unrelated sibling adjustor proof comments remain unchanged.

### Report Reconciliation And Supervisor Boundary

- [x] Converted every C31J-001 through C31J-040 verification state to a legal terminal callback state and added claim-specific destination/validator/generated proof.
- [x] Replaced report-only current-state wording with archive-neutral completed-callback truth after implementation and generated verification became independently true.
- [x] Populated exact Validator Results and Changed Files inventories and ordinary/generated hashes; final report hash is computed externally after byte review.
- [x] Confirmed every UID/path is literal, proof-comment wording is historical only, and no implementation-scheduling contradiction remains.
- [x] Preserved the exact manual coverage handoff text for supervisor-owned synchronization; B004 did not edit manual coverage.
- [x] Confirmed B004 did not run or probe `execute_report`, report lifecycle/count/revalidation, move, or archive commands.
- [x] Confirmed report validation/execution/archive/count state remains external supervisor/validator-owned and is not tracked as pending implementation work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012943","destination_path":"executed-b-agent-research/B004/00031J-IMECompositionPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00031J-IMECompositionPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-15T07:21:38-04:00","uid":"00031J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
