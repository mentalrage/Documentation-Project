** TARGET-REPORT-UID:0004BN **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0004BN AddItemDialog Destructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Current callback result: [UID:0004BN] remains the exact ordinary, non-deleting `AddItemDialog` destructor at `0x004ae900-0x004ae929`; its guarded singleton-clear draft is replaced by the binary-exact unconditional clear, and all vptr, base-teardown, adjustor, deleting-wrapper, and free behavior remains outside handwritten source.
- Applied disposition: no split, rename, owner change, emitter change, or reconstructability change. The target is now `92/94`, optional emitter position `20`, `Nested:0`, with one source-visible statement emitted through [UID:000007] `AddItemDialog` in [UID:0000KE] `ItemDialogs`.
- Implementation result: the target and five accepted support pages are synchronized at report-level detail without changing their accepted support metadata, formal C++, or unrelated content.
- Confidence: very high for range, instructions, ABI, unconditional global store, base teardown, xrefs, vtable/wrapper relationships, ownership, and source/compiler separation; high for the inferred historical source spelling and exact physical source order.
- Report state: the accepted implementation callback is complete. B001 changed only the six permitted by-* pages plus this report, used short one-file leases and scoped validators, and performed the authorized waited generated refresh. B001 performed no report execution, lifecycle, move, archive, generated-file manual edit, IDA mutation, or supervisor-owned manual edit.

## Supporting Research

- Mandatory MCP evidence was refreshed through the project streamable endpoint at `http://127.0.0.1:13337/mcp` during the 2026-07-13 evidence window. Fresh `idb_list` returned exactly one active adopted worker session, database `supervisor_nexustk_20260713`, worker PID `2236`, `is_analyzing:false`. Evidence-time `server_health` returned `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- The first valid bounded IDB probe resolved `0x004ae900` as `sub_4AE900`, size `0x29`; `0x004ae929` is not a function. Subsequent bounded calls used the same database argument and remained responsive.
- Active-report search roots checked with terms `UID:0004BN`, `TARGET-REPORT-UID:0004BN`, `004ae900`, `AddItemDialogDestructor`, `AddItemDialog::~`, and `sub_4AE900`: `tools/leaser/Agents/Agent-B001` through `Agent-B005`, including each `goal.md` and `research/` directory. The only match was the current B001 assignment in `Agent-B001/goal.md`; no active dedicated or overlapping report was found.
- Historical/archive search roots checked with the same terms: `executed-b-agent-research/`, `archived/`, `tools/leaser/Agents/Older-Research/`, and `tools/leaser/Agents/SpecialReports/`. The latter three roots returned no target match.
- Exact matching historical reports opened and classified:
  - `executed-b-agent-research/B007/0000KE-ItemDialogs-empty-emitter-family-source-quality.md`: direct child-creation history. It created UID0004BN at `86/90` but described the clear only as applicable/where appropriate and did not perform this exact destructor source-quality audit.
  - `executed-b-agent-research/B001/0004BM-AddItemDialogConstructor-source-quality.md`: direct predecessor-boundary, class, source-order, constructor-publication, vtable, and ItemDialogs support; it explicitly preserved UID0004BN unchanged.
  - `executed-b-agent-research/B004/00013A-AddEmployeeItemDialog-source-quality.md`: direct derived-wrapper support; it records the normal call from `0x004a4d00` to the UID0004BN base destructor.
  - `executed-b-agent-research/B001/00014T-ItemExchangeMixDialogs.md`: aggregate adjacency/function-inventory support only.
  - `executed-b-agent-research/B001/00025A-ExchangeItemReadOnlyData-B001-00025A.md`: AddItemDialog vtable-store support only.
  - `executed-b-agent-research/B002/00025A-ExchangeItemReadOnlyData-post-migration.md`: post-migration vtable-store support only.
- Explicit report-search conclusion: no prior report has `TARGET-REPORT-UID:0004BN`; none substitutes for this exact ordinary-destructor audit. B007 is provenance for child creation, while all other matches are caller, boundary, aggregate, vtable, or dependency support.
- Historical pre-callback generated output was read only: `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp`, validator command `000000009765`, refreshed `2026-07-13T11:21:05-04:00`, emitted UID0004BN once with the contradicted guarded singleton clear. Callback refresh command `000000009852` superseded that state with the accepted unconditional body.

## Target

- Target UID: `0004BN`.
- Target path: `by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `86/90`, reports `0` at assignment time.
- Historical supervisor classification before Gate 1 was report-only source-quality research under Rule 26. The supervisor then accepted exact SHA `CAB49A960BCEFCA81A53CA02107FA54EF9293F88D50A95F9CADB9E48A9416912` and authorized this implementation callback.
- Current documented scores and parent state: target `92/94`, direct class owner/emitter [UID:000007] `AddItemDialog` at `90/92`, containing core [UID:00033Q] at `88/92`, file route [UID:0000KE] at `91/90`.

## Current Target State

- Applied metadata: `CANONICAL_OWNER:000007`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000007`, optional position `20`, `Nested:0`.
- Owner/emitter/reconstructable state was correct and is retained.
- Historical pre-callback C++ conditionally cleared the singleton only when the global equaled `this`; that contradicted the branch-free binary. Current formal C++ is the exact unconditional assignment.
- Historical pre-callback prose was shallow and left base teardown unresolved. Current target/support prose records the complete range, ABI, caller, RTTI, singleton, compiler/source, wrapper, and negative evidence.
- Existing open blockers now resolved: exact instructions, ABI, return path, all inbound routes, vtable/deleting-wrapper route, derived teardown, base destructor identity, compiler/source separation, RTTI inheritance, singleton semantics, source name, source file, and source position.
- Related target/support docs checked: UID0004BM, UID0004BO, UID0004BP, UID000317, UID00033R, UID00033Q, UID00033Y, UID000007, UID000009, UID00013A, UID0000KE, UID0002AY, UID0003ID, UID0001XV, UID00014T, UID00025A/B002 post-migration, UID00003T, UID00012R, and current generated `ItemDialogs.cpp`.
- Current artifact state: accepted callback implementation and report evidence are complete, every B001 lease is released, and no B001 implementation item remains. External supervisor/validator state such as report validation, execution, count, path ownership, move, archive, or lifecycle state is not asserted or directed by this artifact.

## Executive Recommendation

- Keep UID0004BN as one exact source-bearing child under [UID:000007] `AddItemDialog`; do not merge it into UID00033Q or reclassify it as compiler-only.
- The source-visible destructor body is a single unconditional assignment to the accepted ItemDialogs-owned singleton pointer. The three AddItemDialog vptr stores and the tail-chain into `DialogPane` destruction are compiler-generated effects of an ordinary virtual derived destructor.
- Keep the primary scalar deleting wrapper `0x004b0910`, its `-0xa0`/`-0xa4` adjustors, and the inherited AddMixing wrapper `0x004b0970` non-emitting in UID00033Y. They duplicate the ordinary source effect and add delete-flag/free ABI behavior; they are not second source methods.
- Set UID0004BN position `20`, after constructor UID0004BM position `10` and before the later AddItemDialog methods. Do not alter UID0004BO, UID0004BP, UID000317, or UID00033R formal bodies in this callback.
- No blocker remains for a source-ready target update.

## Supervisor Active Recheck

- Supervisor instruction rechecked: the exact Gate-1 artifact passed, and the subsequent callback authorized C4BN-001 through C4BN-038 against only the six named by-* destinations, with scoped validation and waited generated verification.
- The assigned item does not require split repair: the exact IDA function already occupies the full half-open target range, and both neighboring gaps are alignment padding already inventoried by UID00033Q.
- Every source-bearing item in target scope is resolved: UID0004BN emits the one-statement ordinary destructor; scalar wrappers, adjustor thunks, EH cleanup funclets, vptr stores, and base-tail mechanics have precise compiler-generated dispositions.

## Inference Research Guidance Check

- `by-structure.md` required live IDA/MCP to control range, xrefs, types, and behavior. Existing generated prose and Wave3-style labels were treated as leads only.
- Existing uncertain assumptions rechecked rather than inherited: the guarded singleton clear, polluted `boost::exception *this` prototype, unresolved base teardown, blank source position, and generic "where applicable" singleton wording.
- Direct IDA facts are separated below from accepted documentation evidence and source inference.
- Wave2/Wave3 artifacts were not used as authority. The generated C++ file was used only to identify current stale emitted text and expected refresh effects, not to establish binary behavior.

## Heuristic / Inference Reanalysis And Validation

- Function identity: `sub_4AE900` is source-facing `AddItemDialog` ordinary destructor, not a standalone singleton helper. Three class-specific vptr restores, immediate singleton clear, `DialogPane` tail teardown, class RTTI, and scalar-wrapper mirroring make that interpretation decisive.
- Polluted type: IDA renders the target as `void __thiscall(boost::exception *this)` because the tail target at `0x0049d9f0` has a polluted Boost name/type. Decorated AddItemDialog vtable/RTTI names and constructor/destructor relationships override that prototype. Source type is `AddItemDialog *this`.
- Singleton semantics: the target writes zero directly to `0x0069b328`. No instruction reads the global or `this` for comparison. The existing guarded source is rejected-stale; unconditional clear is exact.
- Singleton name/type: `static AddItemDialog *g_pAddItemDialog` is the highest-probability source-facing declaration already accepted by UID0002AY and generated ItemDialogs output. Original lexical spelling is stripped, so the name remains descriptive rather than PDB-proven.
- Base relationship: AddItemDialog RTTI has seven hierarchy entries: AddItemDialog, DialogPane, Pane, GrafPort, LObject, EventHandler, and TimerHandler. There is no `Singleton<AddItemDialog>` base. Constructor base call and destructor tail establish direct source inheritance from DialogPane.
- Source/compiler separation: vptr stores at offsets `+0`, `+0xa0`, and `+0xa4`, implicit base destruction, scalar delete flags, secondary/tertiary `this` adjustors, optional free calls, sized/guarded delete paths, EH cleanup funclets, and padding are compiler/ABI output. Only the global assignment is source-visible target behavior.
- Caller/reachability: the target has exactly three inbound code xrefs. One normal call is from the AddEmployee scalar deleting wrapper; two jumps are constructor-unwind funclets for inline AddMixing construction in MixItemDialog action handling and the standalone AddMixing constructor.
- Duplicate-body analysis: exact ten-byte singleton-clear encoding occurs only at target `0x004ae91a`, AddItemDialog scalar wrapper `0x004b0930`, and AddMixingItemDialog scalar wrapper `0x004b0990`. The two wrappers also repeat all three AddItemDialog vptr stores and DialogPane teardown before delete-flag handling.
- Source placement: address order, accepted constructor position `10`, class/file ownership, and current generated grouping support ItemDialogs.cpp position `20` for the destructor.
- Rejected alternatives:
  - Guarded singleton clear: contradicted by the branch-free store.
  - Empty destructor: would omit the one source-visible global write.
  - Explicit vptr assignments or explicit `DialogPane::~DialogPane()` call: would duplicate compiler-generated destructor lowering.
  - Emit `0x004b0910` or `0x004b0970` as handwritten methods: rejected because flags, adjustors, return-this behavior, free calls, and vtable-only routing are MSVC deleting-destructor ABI.
  - Reclassify UID0004BN as ignored/non-reconstructable: rejected because it carries required source behavior and has a valid class/file emitter route.
  - Assign direct ownership to UID0000KE, UID00033Q, UID0002AY, or DialogPane: rejected because those are file, container, storage, and base dependencies; AddItemDialog is the semantic method owner.
- Unresolved issues: no material behavior, ownership, range, split, C++, or score blocker remains. Only exact original private/global spelling and physical source ordering are inferred; those bounded uncertainties justify staying below `95`.

## Evidence Standards Used

- IDA MCP evidence used: fresh `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `disasm`, `decompile`, `get_bytes`, exact-schema `get_int`, `xrefs_to`, `callees`, `find_bytes`, `search_text`, and bounded `entity_query` calls.
- Binary evidence used: exact target bytes, predecessor/successor padding bytes, five instructions, basic-block count, singleton-clear duplicate encoding, vtable store xrefs, scalar/deleting wrappers, adjustor thunks, EH tail chunks, RTTI locator/class hierarchy/base descriptors, and base cleanup body.
- Documentation evidence used: current by-* target/support pages, current generated C++, tracker row, and every matching active/executed/archive report result listed above.
- Evidence ladder: current MCP controls bytes/ranges/xrefs/behavior; accepted by-* docs control durable UID ownership and source routes; inference supplies only stripped source spellings and position.
- Tool limitations: no IDB mutation was requested or performed. IDA's Boost prototype is known polluted metadata and was explicitly rejected. A four-byte RVA byte search was non-unique and was not treated as pointer evidence; authoritative xrefs and exact code paths control reachability.

## Evidence Checked

- MCP health: evidence-time database `supervisor_nexustk_20260713`, worker PID `2236`, server `ok`, analysis/Hex-Rays/strings ready.
- Target checks: lookups at `0x004ae8f4`, `0x004ae8f5`, `0x004ae8ff`, `0x004ae900`, `0x004ae928`, `0x004ae929`, `0x004ae92f`, and `0x004ae930`; exact bytes across `0x004ae8e8-0x004ae930`; complete target analyze/decompile/disassembly.
- Route checks: xrefs to target, singleton, wrappers, and all three AddItemDialog vtables; complete wrapper analyses at `0x004a4d00`, `0x004b0910`, and `0x004b0970`; adjustor analyses at `0x004b08a1` and `0x004b08ac`; EH chunk disassembly at `0x005fe618` and `0x005fe6d8`.
- Base checks: lookup/decompile/disassembly/callees for `0x0049d9f0`, including its ordinary return at `0x0049daca` and tail calls into lower cleanup.
- RTTI/type checks: AddItemDialog locator `0x00647318`; type descriptor `0x00675cc8`; hierarchy descriptor `0x00646ad4`; seven-entry base array; AddItemDialog and DialogPane base descriptors.
- Data checks: eight zero bytes at `0x0069b328-0x0069b330`; exact seven xrefs to the AddItemDialog singleton slot; exact three matches for the zero-store encoding.
- Documentation checks: target, class, file, core, siblings, singleton storage, vtable pages, compiler strip, derived dialog pages, DialogPane support, generated ItemDialogs.cpp, tracker, and historical reports listed under Supporting Research.
- Negative checks: no target-internal data/padding/split, no target endpoint function, no guarded compare/branch, no ordinary vtable cell pointing directly to UID0004BN, no explicit target free/delete path, no `Singleton<AddItemDialog>` RTTI base, and no active/dedicated historical report.
- Failed or unavailable checks: none of the valid bounded IDB-backed calls used for the recommendation failed. No fallback-only evidence was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C4BN-001 | Keep exact function range `0x004ae900-0x004ae929`, size `0x29`; no split. | Direct/very high | MCP lookup, bytes, disassembly | UID0004BN metadata/status/range | incorporate | applied |
| C4BN-002 | Preserve predecessor `0x004ae8f5-0x004ae900` as eleven `0xcc` alignment bytes. | Direct/very high | MCP boundary lookup/get_bytes; UID0004BM/UID00033Q | UID0004BN boundaries; UID00033Q inventory | incorporate | applied |
| C4BN-003 | Preserve successor `0x004ae929-0x004ae930` as seven `0xcc` alignment bytes before UID0004BO. | Direct/very high | MCP boundary lookup/get_bytes | UID0004BN boundaries; UID00033Q inventory | incorporate | applied |
| C4BN-004 | Record five instructions, two basic blocks, cyclomatic complexity one, and no target-local stack frame. | Direct/very high | MCP analyze/disasm | UID0004BN instruction/ABI evidence | incorporate | applied |
| C4BN-005 | Record ordinary `__thiscall` destructor ABI: `ECX=this`, no stack arguments, no local return instruction, tail-chain to base cleanup, eventual plain `retn`. | Direct/very high | Target/base disassembly | UID0004BN ABI/return evidence | incorporate | applied |
| C4BN-006 | Classify vptr stores at `+0`, `+0xa0`, `+0xa4` to `0x00619e8c`, `0x00619eec`, `0x00619f1c` as compiler-generated destructor lowering. | Direct/very high | Target disassembly and vtable xrefs | UID0004BN behavior/negative evidence; UID0003ID already-present support | incorporate | applied |
| C4BN-007 | Replace the target source body with an unconditional zero assignment to the AddItemDialog singleton. | Direct/very high | `mov dword ptr [0x0069b328],0` at `0x004ae91a` | UID0004BN formal block/body | incorporate | applied |
| C4BN-008 | Historicalize and reject the current `global == this` guard; the binary has no load, compare, or branch. | Direct/very high | Complete five-instruction body | UID0004BN historical corrections/negative evidence | reject-stale | excluded-with-reason |
| C4BN-009 | Resolve `0x0049d9f0` as ordinary `DialogPane` cleanup despite polluted Boost naming. | Direct/very high | Base decompile/disasm; UID00012R/UID00003T | UID0004BN base teardown; UID00033Q support | incorporate | applied |
| C4BN-010 | Exclude explicit base-destructor syntax from emitted source; normal C++ destruction regenerates the tail-chain. | Very high | Destructor ABI and class inheritance | UID0004BN compiler/source separation | reject-invalid | excluded-with-reason |
| C4BN-011 | Record exactly three inbound target xrefs and no data/vtable xref to the ordinary body. | Direct/very high | `xrefs_to(0x004ae900)` | UID0004BN caller inventory | incorporate | applied |
| C4BN-012 | Classify `0x004a4d06` as normal base-destructor call from AddEmployee scalar deleting wrapper `0x004a4d00`. | Direct/very high | Wrapper analyze/disasm; UID00013A | UID0004BN derived routes; UID00013A already-present | incorporate | applied |
| C4BN-013 | Classify `0x005fe61e` as EH cleanup tail from inline AddMixing construction in MixItemDialog action handling. | Direct/very high | Parent/chunk disasm at `0x005fe618` | UID0004BN EH routes | incorporate | applied |
| C4BN-014 | Classify `0x005fe6db` as EH cleanup tail from standalone AddMixing constructor. | Direct/very high | Parent/chunk disasm at `0x005fe6d8` | UID0004BN EH routes | incorporate | applied |
| C4BN-015 | Keep primary vtable slot `0x00619e8c -> 0x004b0910`; do not invent direct vtable reachability for UID0004BN. | Direct/very high | Vtable data/xrefs | UID0004BN routing; UID0003ID already-present | already-present | already-present |
| C4BN-016 | Keep `0x004b0910-0x004b096f` as AddItemDialog scalar deleting wrapper, not handwritten source. | Direct/very high | Wrapper disasm; three wrapper xrefs | UID00033Y support and UID0004BN negative evidence | incorporate | applied |
| C4BN-017 | Preserve `0x004b08a1`/`0x004b08ac` as `-0xa0`/`-0xa4` compiler adjustors to `0x004b0910`. | Direct/very high | Thunk disassembly/vtable xrefs | UID00033Y already-present support | already-present | already-present |
| C4BN-018 | Keep `0x004b0970-0x004b09cf` as AddMixing scalar deleting wrapper that duplicates inherited AddItemDialog destruction and adds size-`0x274` delete ABI. | Direct/very high | Wrapper disasm and xrefs | UID00033Y; UID000009 support note | incorporate | applied |
| C4BN-019 | Record singleton-clear duplicate encoding only at `0x004ae91a`, `0x004b0930`, and `0x004b0990`. | Direct/very high | Bounded `find_bytes` | UID0004BN duplicate-body analysis; UID00033Y | incorporate | applied |
| C4BN-020 | Preserve `0x0069b328` as zero-initialized `AddItemDialog *` singleton storage with seven exact refs. | Direct/high | MCP bytes/xrefs; UID0002AY | UID0002AY evidence; UID0004BN global behavior | incorporate | applied |
| C4BN-021 | Record seven-entry AddItemDialog RTTI hierarchy and direct DialogPane inheritance; reject a `Singleton<AddItemDialog>` base. | Direct/very high | COL/CHD/base descriptors; ctor/dtor calls | UID0004BN type evidence; UID000007 class evidence | incorporate | applied |
| C4BN-022 | Retain canonical owner/emitter UID000007 and reconstructable true. | Very high | Decorated vtables/RTTI, class docs, source route | UID0004BN metadata | already-present | already-present |
| C4BN-023 | Retain source module UID0000KE `NexusTK/ui/dialogs/ItemDialogs.cpp`. | High | Existing file route, address family, generated output | UID0004BN source placement; UID0000KE | already-present | already-present |
| C4BN-024 | Set UID0004BN optional emitter position `20`, after UID0004BM position `10`. | High | Binary/source family order and current grouping | UID0004BN metadata; UID0000KE source order | incorporate | applied |
| C4BN-025 | Keep `Nested:0`; no target child, data island, or internal padding exists. | Direct/very high | Exact function/body/boundaries | UID0004BN metadata/range analysis | already-present | already-present |
| C4BN-026 | Raise target score `86/90 -> 92/94`, staying below final-audit scores. | High | Blocker closure and bounded lexical uncertainty | UID0004BN metadata/score rationale | incorporate | applied |
| C4BN-027 | Update UID0004BN summary and prose with full range, ABI, source/compiler, xref, wrapper, RTTI, global, and negative evidence. | High | Full report evidence | UID0004BN all substantive sections | incorporate | applied |
| C4BN-028 | Add exact ordinary-destructor row/evidence to UID000007 while preserving its complete class block and `90/92`. | High | Target and current class page | `by-class/AddItemDialog.md` method/evidence/history | incorporate | applied |
| C4BN-029 | Refine UID00033Q destructor row/evidence to unconditional clear and resolved DialogPane teardown; keep `88/92` and aggregate block. | High | Target and current core page | UID00033Q inventory/evidence/history | incorporate | applied |
| C4BN-030 | Add position-20/source-order and ordinary-versus-wrapper detail to UID0000KE; keep `91/90` and unrelated family content. | High | Target, generated ordering, file docs | `by-file/ItemDialogs.md` contents/evidence/history | incorporate | applied |
| C4BN-031 | Add exact unconditional writer and three duplicate-clear-site distinction to UID0002AY; keep declarations and `89/92`. | High | Singleton bytes/xrefs | UID0002AY evidence/history | incorporate | applied |
| C4BN-032 | Link UID00033Y AddItem/AddMixing scalar rows to UID0004BN as covered source behavior; keep strip non-emitting at `88/91`. | High | Wrapper analyses | UID00033Y inventory/reconstruction/history | incorporate | applied |
| C4BN-033 | Preserve UID0003ID and UID0001XV vtable facts unchanged because they already contain the same-or-greater stores, slots, and adjustors. | High | Current vtable docs and MCP xrefs | UID0003ID/UID0001XV | already-present | already-present |
| C4BN-034 | Preserve UID00013A and UID000009 derived-destructor facts unchanged; both already contain sufficient base-call/inheritance and compiler-wrapper dispositions. | High | Current derived docs and wrapper evidence | UID00013A/UID000009 | already-present | already-present |
| C4BN-035 | Preserve B007 child-creation and family reports as historical support, not direct target authority. | High | Report search/open results | UID0004BN history and report Supporting Research | historicalize | applied |
| C4BN-036 | Generated ItemDialogs.cpp must refresh to one unconditional UID0004BN body with no guarded-compare text and no emitted compiler wrapper. | High | Current generated output and accepted source route | Validator-generated `ItemDialogs.cpp` verification only | incorporate | applied |
| C4BN-037 | No IDA rename/type/comment mutation is required; retain source-facing names in docs only. | High | Stripped symbols plus accepted decorated RTTI/vtables | Report IDA recommendations; no IDB edit | not-applicable | excluded-with-reason |
| C4BN-038 | No new ignored row or padding child is required; UID00033Q already inventories both adjacent alignment spans. | High | Current core inventory and exact bytes | Range/split section; UID00033Q | already-present | already-present |

### Callback Verification Notes

| Claim ID | Detailed callback proof |
| --- | --- |
| C4BN-001 | UID0004BN now states exact half-open range `[0x004ae900,0x004ae929)`, 41 bytes, with no split; target validator `000000009842` returned exit `0`, `ok:1`. |
| C4BN-002 | UID0004BN Boundaries And Reachability records eleven leading `0xcc` bytes, and UID00033Q retains the `0x004ae8f5-0x004ae900` padding row; validators `000000009842` and `000000009847` passed. |
| C4BN-003 | UID0004BN records seven trailing `0xcc` bytes and UID00033Q retains the `0x004ae929-0x004ae930` row before UID0004BO; both scoped validators passed. |
| C4BN-004 | UID0004BN Exact Range And Behavior records 41 bytes, five instructions, two blocks, complexity 1; Status records no explicit arguments and the accepted ABI. |
| C4BN-005 | UID0004BN Status records ordinary non-deleting `thiscall`, `ECX=this`, no explicit stack arguments, and tail-inherited return behavior; Exact Range And Behavior records the `0x0049d9f0` tail. |
| C4BN-006 | UID0004BN classifies all three exact vptr stores as compiler mechanics; UID000007, UID00033Q, and UID00033Y synchronize that separation while UID0003ID remains unchanged. |
| C4BN-007 | UID0004BN's managed block contains exactly `g_pAddItemDialog = 0;`; generated ItemDialogs.cpp has one destructor definition and one exact four-space assignment line. |
| C4BN-008 | UID0004BN Negative And Historical Evidence explicitly rejects the prior hygiene inference; generated verification found zero `g_pAddItemDialog == this` matches. |
| C4BN-009 | UID0004BN resolves the `0x004ae924` tail to DialogPane cleanup `0x0049d9f0`; UID00033Q repeats the resolved base route despite polluted Boost metadata. |
| C4BN-010 | Explicit base-destructor syntax is excluded in UID0004BN and UID00033Y; generated verification found zero `DialogPane::~DialogPane` calls. |
| C4BN-011 | UID0004BN Boundaries And Reachability records exactly three direct code xrefs and no direct vtable route; the accepted MCP evidence remains preserved. |
| C4BN-012 | UID0004BN records `0x004a4d06` as the AddEmployee scalar-wrapper call; UID00013A remains unchanged as same-or-greater support. |
| C4BN-013 | UID0004BN records `0x005fe61e` as the EH cleanup associated with inline AddMixing construction in MixItemDialog action handling. |
| C4BN-014 | UID0004BN records `0x005fe6db` as the EH cleanup associated with standalone AddMixing construction. |
| C4BN-015 | UID0004BN and UID00033Y preserve the primary vtable route through `0x004b0910`; UID0003ID was not edited and no direct vtable claim was introduced. |
| C4BN-016 | UID00033Y links `0x004b0910-0x004b096f` to UID0004BN as a non-emitting `0x270` scalar wrapper; generated checks found zero delete/base/vptr/adjustor implementation tokens. |
| C4BN-017 | UID00033Y retains exact `0x004b08a1` and `0x004b08ac` rows with `-0xa0`/`-0xa4` adjustments to `0x004b0910`; no source body was added. |
| C4BN-018 | UID00033Y links `0x004b0970-0x004b09cf` to inherited UID0004BN behavior, records size `0x274`, and keeps the wrapper non-emitting; UID000009 remains unchanged. |
| C4BN-019 | UID0004BN, UID0002AY, and UID00033Y each distinguish exact clear sites `0x004ae91a`, `0x004b0930`, and `0x004b0990` as one authored store plus two wrapper copies. |
| C4BN-020 | UID0002AY retains its zero-initialized declaration and `89/92`, now enumerates all seven exact slot refs, and identifies UID0004BN as the one authored writer; validator `000000009850` passed. |
| C4BN-021 | UID0004BN, UID000007, and UID00033Q record the seven-entry RTTI hierarchy, direct DialogPane base, and absence of `Singleton<AddItemDialog>`. |
| C4BN-022 | UID0004BN header retains `CANONICAL_OWNER:000007`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000007`; target validation passed without owner/emitter mutation. |
| C4BN-023 | UID0004BN and UID0000KE retain the `NexusTK/ui/dialogs/ItemDialogs.cpp` route; waited generation refreshed that exact output path. |
| C4BN-024 | UID0004BN header is position `20`; generated output places UID0004BM at line 24 and UID0004BN at line 92 before UID0004BO at line 101. |
| C4BN-025 | UID0004BN retains `Nested:0`; no child, internal padding row, or data island was created. |
| C4BN-026 | Target validator `000000009842` recorded completion `92` and confidence `94`; generated metadata uses the same values. |
| C4BN-027 | UID0004BN now contains complete Status, Exact Range And Behavior, Boundaries And Reachability, RTTI And Ownership Evidence, Compiler Artifacts, Negative And Historical Evidence, and Score Rationale sections. |
| C4BN-028 | UID000007 retains `90/92` and its complete managed declaration; the exact UID0004BN method row/evidence/history was added and validator `000000009846` returned exit `0`, `ok:1`. |
| C4BN-029 | UID00033Q retains `88/92`, `[[CHILDREN]]`, all four child rows, and constructor/action/update material; destructor inventory/evidence/history was refined and validator `000000009847` passed. |
| C4BN-030 | UID0000KE retains `91/90` and all family content; it now records position 20, unconditional ordinary body, wrapper exclusion, and generated uniqueness expectations; validator `000000009849` passed. |
| C4BN-031 | UID0002AY retains `89/92`, both declarations, and MixItem content while adding the one-authored/two-wrapper clear distinction; validator `000000009850` passed. |
| C4BN-032 | UID00033Y retains `88/91`, no owner/emitter, non-reconstructable status, blank formal C++, and every strip row; AddItem/AddMixing rows now link to UID0004BN and validator `000000009851` passed. |
| C4BN-033 | UID0003ID and UID0001XV were outside the permitted edit set and remain unchanged; their accepted same-or-greater vtable/store/adjustor evidence is still the controlling support. |
| C4BN-034 | UID00013A and UID000009 were outside the permitted edit set and remain unchanged; their accepted derived base-call/inheritance/compiler-wrapper facts remain sufficient. |
| C4BN-035 | Supporting Research retains B007 as historical child-creation provenance and separately classifies constructor, AddEmployee, aggregate, and vtable reports as support rather than direct target authority. |
| C4BN-036 | Waited command `000000009852` completed generated refresh. ItemDialogs.cpp contains one `UID:0004BN`, one destructor, one unconditional assignment, zero guard, and zero explicit vptr/base/delete/adjustor implementation tokens. |
| C4BN-037 | No IDA mutation command was run during the callback. Source-facing names remain documentation-only, so mutation is excluded as unnecessary and unauthorized. |
| C4BN-038 | UID00033Q still inventories both adjacent padding spans; no new by-memory child or ignored-row edit exists in the changed-file set. |

## Positive Evidence Summary

- Exact target facts: one `0x29`-byte function, five instructions, three AddItemDialog vptr stores, one unconditional singleton clear, and one tail jump to DialogPane cleanup.
- Exact route facts: one normal derived-wrapper call and two constructor-EH cleanup jumps; no direct target vtable cell.
- Exact wrapper facts: primary AddItemDialog and derived AddMixing scalar wrappers duplicate the same three vptr stores, singleton clear, and DialogPane cleanup, then add delete flags/free behavior.
- Exact type facts: decorated AddItemDialog vtables/RTTI and a seven-entry hierarchy rooted through DialogPane; no Singleton base.
- Exact global facts: zero-initialized pointer storage with seven xrefs and three destructor/cleanup zero stores.
- Strongest inference chain: decorated class identity + constructor/base relationship + ordinary target shape + deleting-wrapper/vtable route + accepted ItemDialogs grouping support one conventional virtual destructor with a single handwritten global assignment.

## IDA MCP Facts

- Function/range facts: `sub_4AE900`, `0x004ae900-0x004ae929`, size `0x29`, five instructions, two basic blocks, complexity one. Endpoint `0x004ae929` is not a function; successor `sub_4AE930` begins at `0x004ae930`.
- Exact instructions:
  - `0x004ae900`: store primary AddItemDialog vtable `0x00619e8c` at `this+0`.
  - `0x004ae906`: store secondary AddItemDialog vtable `0x00619eec` at `this+0xa0`.
  - `0x004ae910`: store tertiary AddItemDialog vtable `0x00619f1c` at `this+0xa4`.
  - `0x004ae91a`: store zero to singleton slot `0x0069b328`.
  - `0x004ae924`: tail jump to `0x0049d9f0`.
- Raw target bytes: `C7 01 8C 9E 61 00 C7 81 A0 00 00 00 EC 9E 61 00 C7 81 A4 00 00 00 1C 9F 61 00 C7 05 28 B3 69 00 00 00 00 00 E9 C7 F0 FE FF`.
- Padding facts: eleven `0xcc` bytes at `0x004ae8f5-0x004ae900`; seven `0xcc` bytes at `0x004ae929-0x004ae930`.
- ABI facts: ordinary `__thiscall`, complete-object pointer in ECX, no explicit stack arguments, no local prolog/epilog, void source return, tail-preserved caller return address, eventual base `retn` at `0x0049daca`.
- Xref facts: target inbound xrefs are `0x004a4d06`, `0x005fe61e`, and `0x005fe6db`, all code. No target data xref exists.
- Vtable facts: each AddItemDialog vtable base has four code-store refs: constructor, ordinary destructor, AddItem scalar wrapper, and AddMixing scalar wrapper. Primary slot `0x00619e8c` points to scalar wrapper `0x004b0910`; adjustors at `0x004b08a1`/`0x004b08ac` subtract `0xa0`/`0xa4` and jump there.
- Deleting-wrapper facts: `0x004b0910` handles AddItemDialog size `0x270`; `0x004b0970` handles AddMixingItemDialog size `0x274`. Each has exactly three inbound refs: two adjustors and one primary vtable cell.
- Global facts: `0x0069b328-0x0069b330` is eight zero bytes for the adjacent AddItem/MixItem pointer slots. AddItem slot xrefs are reads at `0x004ad670`, `0x004ade32`, and `0x004aeab0`; constructor publication at `0x004ae8d2`; clears at `0x004ae91a`, `0x004b0930`, and `0x004b0990`.
- RTTI facts: AddItemDialog complete object locator `0x00647318` names type descriptor `0x00675cc8` and hierarchy `0x00646ad4`. The hierarchy has seven entries and direct DialogPane lineage; AddItemDialog and DialogPane base descriptors both have `mdisp=0`, `pdisp=-1`, `vdisp=0`.
- Negative IDA facts: no compare/branch in target, no Singleton RTTI base, no target-local delete/free, no explicit return-this behavior, no internal padding/table/data, no alternate function start, and no valid reason to preserve the polluted Boost prototype.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ae8f5-0x004ae900` | UID00033Q inventory | Eleven-byte alignment span | no source | UID00033Q | not scored | Already inventoried; no child |
| `0x004ae900-0x004ae929` | UID0004BN target | Ordinary AddItemDialog destructor | true | UID000007 | `86/90 -> 92/94` | Exact source child; update |
| `0x004ae929-0x004ae930` | UID00033Q inventory | Seven-byte alignment span | no source | UID00033Q | not scored | Already inventoried; no child |
| `0x004ae930-0x004aea3a` | UID0004BO | AddItemDialog action handler | true | UID000007 | `88/90` | Existing sibling; unchanged |
| `0x004a4d00-0x004a4d3b` | UID00013A range | AddEmployee scalar deleting wrapper calling UID0004BN | compiler-covered | AddEmployeeItemDialog | `88/90` parent page | Support only |
| `0x004b08a1-0x004b08ac` | UID00033Y row | AddItem secondary adjustor | no handwritten source | none | `88/91` strip | Compiler support |
| `0x004b08ac-0x004b08b7` | UID00033Y row | AddItem tertiary adjustor | no handwritten source | none | `88/91` strip | Compiler support |
| `0x004b0910-0x004b096f` | UID00033Y row | AddItem scalar deleting wrapper | covered by UID0004BN | none | `88/91` strip | Compiler support |
| `0x004b0970-0x004b09cf` | UID00033Y row | AddMixing scalar deleting wrapper, inherited base effect | covered by UID0004BN plus derived declaration | none | `88/91` strip | Compiler support |
| `0x0049d9f0-0x0049dacb` | UID00012R aggregate row | Ordinary DialogPane cleanup | true through DialogPane | UID00003T | UID00012R `86/88` | Base dependency |
| `0x005fe618-0x005fe623` | parent chunk in UID0004BU context | Inline AddMixing construction EH cleanup | no handwritten helper | compiler | not scored | Tail-jumps to target |
| `0x005fe6d8-0x005fe6e0` | parent chunk in UID0002U1 context | AddMixing constructor EH cleanup | no handwritten helper | compiler | not scored | Tail-jumps to target |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004a4d06` | `sub_4A4D00` -> UID0004BN | Normal AddEmployee scalar deleting wrapper invokes the base ordinary destructor before delete flags/free. |
| `0x005fe61e` | tail chunk of `sub_4AF8B0` -> UID0004BN | Constructor-unwind cleanup for inline AddMixing object construction in MixItemDialog action handling. |
| `0x005fe6db` | tail chunk of `sub_4B0000` -> UID0004BN | Constructor-unwind cleanup for standalone AddMixingItemDialog construction. |
| `0x00619e8c` | primary AddItemDialog vtable -> `0x004b0910` | Virtual destruction enters compiler scalar wrapper, not UID0004BN directly. |
| `0x00619eec` | secondary AddItemDialog vtable -> `0x004b08a1` | `this-0xa0` adjustor to scalar wrapper. |
| `0x00619f1c` | tertiary AddItemDialog vtable -> `0x004b08ac` | `this-0xa4` adjustor to scalar wrapper. |
| `0x004b0910` | two adjustors + primary vtable | AddItem scalar wrapper duplicates UID0004BN source effect and adds delete ABI. |
| `0x004b0970` | AddMixing adjustors + primary vtable `0x0061a124` | Derived scalar wrapper duplicates inherited AddItemDialog destruction and adds delete ABI. |
| `0x0049d9f0` | target tail callee | Resolved DialogPane ordinary cleanup; polluted Boost label rejected. |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion: UID0004BM proves immediate predecessor and constructor publication last; UID000007 provides direct class declaration and DialogPane base; UID00033Q provides exact child/padding inventory; UID0002AY provides accepted singleton declaration; UID0003ID/UID0001XV provide exact vtable cells/stores; UID00033Y provides wrapper/adjustor inventory; UID00013A provides the normal derived-wrapper caller; UID00003T/UID00012R resolve base cleanup; UID0000KE provides ItemDialogs source placement.
- Historical pre-callback stale/incomplete docs: UID0004BN had a guarded formal body and unresolved base-teardown score cap; UID00033Q lacked unconditional/source-versus-compiler detail; UID00033Y lacked a precise covered-by link from the AddItem/AddMixing scalar rows to UID0004BN; file/class/global pages lacked the full exact route distinction. The callback corrected each item in the accepted six-page set.
- Generated/coverage state: pre-callback ItemDialogs.cpp emitted the stale conditional body once, and the tracker showed target `86/90`, reports `0` at assignment time. Authorized validator command `000000009852` now generates the exact unconditional target at `92/94`; B001 made no manual generated, coverage, or tracker edit.

## Ranked Ownership Analysis

### 1. [UID:000007] AddItemDialog

- Evidence for: decorated vtables and RTTI, constructor/destructor address family, class declaration, direct DialogPane inheritance, global lifecycle, and primary/adjustor deleting-wrapper route.
- Evidence against: none material; stripped lexical symbols do not weaken semantic class ownership.
- Decision: retain direct owner/emitter.

### 2. [UID:0000KE] ItemDialogs source file

- Evidence for: accepted constructor/file route, adjacent AddItem methods, singleton declaration, generated source, and item-dialog family locality.
- Evidence against: a by-file page is the source route, not the direct semantic method owner.
- Decision: retain source module and generated file route; do not replace class ownership.

### 3. [UID:00033Q] AddItemDialogCore aggregate

- Evidence for: exact containing range and child/padding index.
- Evidence against: aggregate spans four methods and padding and should not emit a duplicate destructor body.
- Decision: retain as container/support index only.

### 4. [UID:00003T] DialogPane / UID00012R

- Evidence for: base cleanup target and direct inherited source relationship.
- Evidence against: target writes AddItemDialog vtables and class singleton before entering base cleanup.
- Decision: base dependency only.

### 5. Compiler-only / ignored ownership

- Evidence for: most instructions are compiler destructor lowering.
- Evidence against: unconditional singleton clear is source-visible and required in reconstructed C++.
- Decision: reject target reclassification; compiler-only status applies only to vptr/base/wrapper/adjustor/EH mechanics.

### Proposed new file/grouping, if applicable

- Not applicable. Keep the existing `NexusTK/ui/dialogs/ItemDialogs.cpp` grouping.
- Likely full local ordering in current scope: class declaration, UID0004BM constructor at position `10`, UID0004BN destructor at position `20`, then existing action/update/packet/helper bodies in their accepted relative order.
- Rejected new grouping: standalone `AddItemDialogDestructor.cpp`, direct `ExchangeDialog.cpp`, employee-dialog source, DialogPane source, or compiler-support source.

## Source Placement

- Recommended placement: `AddItemDialog` implementation in [UID:0000KE] `NexusTK/ui/dialogs/ItemDialogs.cpp`.
- Recommended target position: `20`, immediately after UID0004BM position `10` and before UID0004BO/UID0004BP.
- Why: exact code order, accepted constructor placement, common class grouping, singleton declaration ownership, and current generated module all agree.
- Rejected placements: ExchangeDialog is a consumer/caller context; EmployeeDialogPane owns only its derived class; DialogPane owns the base cleanup; UID00033Y owns only compiler inventory.
- Remaining placement uncertainty: original private section ordering and exact file spelling are not PDB-proven, but no competing source owner has comparable evidence.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is already correct and contains one IDA function with no internal gap or secondary entry.
- Predecessor UID0004BM ends at `0x004ae8f5`; eleven padding bytes lead to target start.
- Target ends at `0x004ae929`; seven padding bytes lead to UID0004BO at `0x004ae930`.
- UID00033Q already inventories both spans. No new child page, ignored row, table/data split, merge, or range rename is required.
- Scalar wrappers and EH chunks are non-contiguous compiler support and must remain in their existing pages/parent functions rather than be nested under the exact target range.
- Parent impact: UID00033Q remains a four-child source index with padding inventory; no metadata or formal block change is needed beyond prose synchronization.

## Negative Evidence Summary

- No instruction compares `g_pAddItemDialog` with `this`; guarded clear is false.
- No target instruction allocates, frees, tests delete flags, adjusts `this`, or returns the object pointer; those behaviors belong to deleting wrappers/adjustors.
- No primary, secondary, or tertiary vtable entry points directly to UID0004BN.
- No Singleton template base appears in AddItemDialog RTTI, unlike known BrowserDialog precedent.
- No internal padding, table, secondary function, disjoint owner, or split pressure exists in the target.
- No ordinary target xref exists beyond the one AddEmployee wrapper call and two EH cleanup tails.
- No exact VA pointer bytes for `0x004ae900` were found by the bounded pointer-pattern check; the four-byte RVA pattern was non-unique in `.text` and was rejected as route evidence.
- No source-level reason exists to write explicit vptr assignments, an explicit base-destructor call, scalar wrapper, adjustor thunks, EH cleanup, or delete helper.
- No active or historical direct target report exists.

## IDA Rename / Type / Comment Recommendations

- Documentation/source-facing function name: `AddItemDialog` ordinary destructor at `0x004ae900`.
- Documentation/source-facing `this` type: `AddItemDialog *`; reject IDA's polluted `boost::exception *` target type.
- Documentation/source-facing global: `static AddItemDialog *g_pAddItemDialog`, already accepted by UID0002AY.
- Optional read-only comment direction, if an A-agent later owns IDA cleanup: ordinary AddItemDialog destructor; unconditional singleton clear is source-visible; three vptr stores and DialogPane tail are compiler-generated.
- Items intentionally unchanged: decorated vtable/RTTI names, base cleanup address, wrapper/adjustor addresses, and all IDA database state.
- IDA DB edits: not requested and not performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The exact one-statement ordinary destructor is source-visible, behavior-complete, and compatible with accepted class/global declarations.
- Destination: `by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
AddItemDialog::~AddItemDialog()
{
    g_pAddItemDialog = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Reason it preserves exact behavior: it emits the only source-visible state change in the ordinary body. Normal virtual C++ destruction regenerates vptr transitions and invokes DialogPane destruction.
- Reason it matches plausible late-1999/mid-2000s source: project docs consistently use `g_p...` singleton pointers, explicit zero assignment, out-of-line virtual destructors, and class/file grouping by dialog family.
- Inferred names used: accepted descriptive global `g_pAddItemDialog`; class/destructor spelling is fixed by decorated RTTI/vtables.
- Coding style: brace placement and literal zero match current ItemDialogs generated/source recommendations.
- No-code proof: not applicable to UID0004BN. The wrappers/adjustors/EH chunks remain no-code compiler support and receive no additional managed block.
- Whole-report managed destination block count: exactly one.

## Final Recommendation

- Applied UID0004BN at `92/94`, position `20`, retained UID000007 owner/emitter, reconstructable true, `Nested:0`, exact path/range, and replaced only its stale formal body with the managed block above.
- Added complete binary/source/compiler/caller/wrapper/RTTI/global/padding/history evidence to the target.
- Synchronized UID000007, UID00033Q, UID0000KE, UID0002AY, and UID00033Y at report-level detail without score inflation or unrelated formal changes.
- Preserved UID0003ID, UID0001XV, UID00013A, UID000009, UID00003T, UID00012R, UID00014T, and both UID00025A reports as unchanged same-or-greater support.
- Generated, coverage, tracker, supervisor, validator-state, IDA, and lifecycle artifacts were not edited manually; generated output changed only through authorized validator refresh.
- No future target research blocker remains inside this assignment.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md`.
- Applied header: `COMPLETION:92`, `CONFIDENCE:94`, owner UID000007 unchanged, reconstructable true unchanged, emitter UID000007 unchanged, `EMITTER_POSITION_OPTIONAL:20`, `Nested:0` unchanged.
- Applied formal C++: replaced the guarded body with the exact managed destination block in `First-Draft C++ Recommendation`.
- Applied Item Summary: identifies an ordinary AddItemDialog destructor that unconditionally clears the ItemDialogs singleton while compiler-generated vptr resets and DialogPane teardown reproduce ABI cleanup.
- Applied substantive sections: status/ABI, exact instructions/raw bytes, boundaries/padding, singleton lifecycle, direct xrefs, vtable and scalar-wrapper routes, AddEmployee/AddMixing/EH derived routes, RTTI/base relationship, source/compiler separation, source placement/order, negative evidence, score rationale, cross-references, and dated change history.
- Preserved rejected history: guarded clear, unresolved base teardown, polluted Boost type, generic compiler-glue score cap, and any suggestion to hand-author deleting-wrapper mechanics.

## Recommended Support Doc Changes

- `by-class/AddItemDialog.md` (UID000007): preserved `90/92`, owner/emitter/file route, full managed class declaration, constructor work, and unrelated methods; added the exact UID0004BN ordinary-destructor row and distinguished the unconditional source clear from vptr/base compiler lowering and primary scalar wrapper UID00033Y.
- `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md` (UID00033Q): preserved `88/92`, metadata, four-child aggregate, all constructor/action/update details, and padding inventory; refined only destructor row/evidence/history with the unconditional clear, exact DialogPane tail, three inbound routes, and wrapper duplication.
- `by-file/ItemDialogs.md` (UID0000KE): preserved `91/90`, source path, all family decisions, singleton declarations, and unrelated content; added target position `20`, ordinary body semantics, wrapper exclusion, and generated verification expectation.
- `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md` (UID0002AY): preserved `89/92`, owner/emitter, zero-initialized formal declarations, neighboring MixItem slot, and all refs; clarified that UID0004BN's clear is unconditional and that `0x004b0930`/`0x004b0990` are compiler-wrapper duplicates.
- `by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md` (UID00033Y): preserved `88/91`, no owner/emitter, non-reconstructable status, blank formal C++, every strip row, and unrelated class wrappers; linked AddItem `0x004b0910` and inherited AddMixing `0x004b0970` source effects to UID0004BN and stated that no wrapper body is emitted.
- `by-type/by-vtable/AddItemDialogVtables.md` (UID0003ID) and `by-type/by-vtable/ItemDialogVtableFamily.md` (UID0001XV): already contain same-or-greater slot/store/adjustor facts; no edit required.
- `by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md` (UID00013A): already contains the exact normal base-destructor call and empty derived source destructor; no edit required.
- `by-class/AddMixingItemDialog.md` (UID000009): current AddItemDialog inheritance and scalar-wrapper disposition are already sufficient; no edit required.
- UID00003T/UID00012R DialogPane support: already resolves `0x0049d9f0` and polluted Boost metadata; no edit required.
- UID00014T/UID00025A historical aggregate/data support: preserve unchanged.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner/emitter UID000007, reconstructable true, blank position, nonblank guarded C++, `Nested:0`.
- Current applied target: `92/94`, owner/emitter UID000007 unchanged, reconstructable true unchanged, position `20`, exact unconditional C++, `Nested:0`.
- Completion rationale: every byte, instruction, block, boundary, padding span, ABI route, caller/xref, wrapper, adjustor, vtable, RTTI/base, singleton, compiler/source, source placement, and formal-C++ question is resolved.
- Confidence rationale: direct MCP and decorated RTTI/vtable evidence are internally consistent. Confidence stays below `95` because original private/global lexical spelling, physical source filename, and exact source declaration order are not PDB/source recovered.
- Score-improvement attempts:
  - Base teardown blocker: decompiled/disassembled `0x0049d9f0`; resolved as DialogPane cleanup.
  - Guard semantics blocker: inspected all five instructions/raw bytes; guard rejected.
  - Reachability blocker: enumerated all target/wrapper/vtable/global xrefs and EH chunks; complete routes classified.
  - Compiler/source blocker: compared ordinary body with AddItem/AddMixing scalar wrappers and adjustors; one source statement isolated.
  - Type/inheritance blocker: decoded AddItemDialog COL/CHD/base descriptors; direct DialogPane lineage and no Singleton base established.
  - Source placement/order blocker: rechecked constructor report, class/file docs, address order, and generated output; ItemDialogs position `20` chosen.
  - Name blocker: decorated class identity is exact; global spelling remains accepted descriptive convention and only limits sub-95 confidence.
- Support metadata result: no support score, owner, emitter, reconstructable, position, or formal-block value changed.

## Open Questions With Attempted Resolution

- Is the singleton clear guarded? Resolved no; exact body has an unconditional store and no branch.
- Is `0x004ae900` an ordinary destructor, helper, or compiler-only tail? Resolved ordinary source destructor by class vptrs, base tail, scalar mirrors, derived callers, and RTTI.
- Is the tail target Boost or DialogPane? Resolved DialogPane cleanup; Boost is polluted IDA metadata.
- Does AddItemDialog inherit a Singleton template that could own the clear? Resolved no; seven-entry RTTI hierarchy has no Singleton base.
- Should wrappers or adjustors emit C++? Resolved no; they are compiler ABI coverage of the ordinary destructor and class hierarchy.
- Are there hidden callers or inline duplicates? Resolved to three inbound target xrefs and two scalar-wrapper duplicates; exact clear encoding appears at three sites total.
- Does the target need a split or padding child? Resolved no; exact function is contiguous and adjacent padding is already inventoried by UID00033Q.
- What is the source owner/file/order? Resolved to AddItemDialog / ItemDialogs.cpp / position `20`.
- What remains unresolved? Only original lexical spelling and physical source layout are not symbol-proven. They do not block C++, owner, source placement, or score; they cap confidence below final audit.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker edit is required.
- Auto-generated coverage/tracker rows refreshed only through the authorized scoped validators and waited callback command; B001 made no manual edit.
- UID0004BN Item Summary is the source for generated row wording; no B001 manual generated edit is permitted.

## Follow-Up Actions

- External supervisor/validator systems own report validation, execution, count/path, move, archive, and lifecycle state; this artifact neither asserts nor directs those states.
- A-agent/IDA follow-up: optional only. If IDA naming cleanup is separately assigned, replace the polluted target prototype/comment with AddItemDialog ordinary-destructor semantics while preserving binary bytes.
- B001 callback work is complete: C4BN-001 through C4BN-038 were applied to the exact target/support set, each one-file lease was released after scoped validation, and the authorized waited generated check completed.
- No additional B001 research target should begin from this report.

## Confidence

- Recommendation confidence: very high.
- Score confidence: high.
- Range/ABI/behavior confidence: very high.
- Owner/emitter/source-family confidence: very high.
- Exact original lexical spelling/source-order confidence: high but not symbol-proven.
- Remaining uncertainty: bounded to source spelling/physical ordering and reflected in the sub-95 score.

## Validator Results

- Callback pre-edit mandatory MCP confirmation at `2026-07-13T12:06:16-04:00`: fresh `idb_list` returned the one active `supervisor_nexustk_20260713` worker (PID `2236`, analysis idle), `server_health` returned `ok` with analysis/Hex-Rays/strings ready, and bounded `lookup_funcs(0x004ae900)` returned `sub_4AE900`, size `0x29`. No callback IDB mutation was performed.
- All commands ran from `source-3/project-documentation` with `--mode file --apply --queue-timeout 240`. Each ordinary scoped command ran while only its destination was leased; each returned exit `0`, `ok:1`, deferred generated refresh, and was followed immediately by a successful B001 unlease.

| Destination | Command id / timestamp | Wall interval / exit | Result and validator side effects |
| --- | --- | --- | --- |
| UID0004BN target | `000000009842`; `2026-07-13T12:07:55-04:00` | `12:07:55.0127712-04:00` to `12:07:56.9613663-04:00`; exit `0` | `ok:1`; completion `92`, confidence `94`, position/hash registry updates, UID00033Y reference-index add, projected stats update; generated refresh deferred. |
| UID000007 class | `000000009846`; `2026-07-13T12:08:51-04:00` | `12:08:51.1610266-04:00` to `12:09:11.4233483-04:00`; exit `0` | `ok:1`; UID0004BN reference-index add and projected stats update. Four existing UID0003ID missing-registry-reference warnings were reported; they pre-existed this callback and did not fail validation. |
| UID00033Q core | `000000009847`; `2026-07-13T12:09:54-04:00` | `12:09:54.1485271-04:00` to `12:09:56.1057345-04:00`; exit `0` | `ok:1`; projected stats update; generated refresh deferred. |
| UID0000KE file | `000000009849`; `2026-07-13T12:10:52-04:00` | `12:10:52.7700602-04:00` to `12:10:54.7268868-04:00`; exit `0` | `ok:1`; UID0004BN reference-index add and projected stats update. Twenty existing missing-registry-reference warnings, including UID0003ID/3IE/3IG/3IF, were reported and did not fail validation. |
| UID0002AY singleton | `000000009850`; `2026-07-13T12:11:37-04:00` | `12:11:36.8844788-04:00` to `12:11:38.8314775-04:00`; exit `0` | `ok:1`; UID0004BN reference-index add and projected stats update; generated refresh deferred. |
| UID00033Y strip | `000000009851`; `2026-07-13T12:12:44-04:00` | `12:12:44.7804755-04:00` to `12:12:46.7266643-04:00`; exit `0` | `ok:1`; UID0004BN reference-index add and projected stats update; generated refresh deferred. |
| Final UID0004BN waited refresh | `000000009852`; `2026-07-13T12:13:05-04:00` | `12:13:05.7827085-04:00` to `12:13:24.0447462-04:00`; exit `0` | `ok:1`; `generated_refresh:completed`, validator registry rebuild (`4662` nodes, `3795` edges), coverage/generated metadata refresh, and generated ItemDialogs.cpp refresh. Global warnings were non-fatal inventory findings outside this callback scope. |

- Generated target verification: `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` mtime `2026-07-13T12:13:13.4527886-04:00`, SHA256 `2A22372B42D138E5076CCCA3B4E2C6A504013EA2E2E7F84AC4F1EC821B80A063`, command header `000000009852`.
- Exact counts: `UID:0004BN=1`; `AddItemDialog::~AddItemDialog()=1`; exact indented `g_pAddItemDialog = 0;=1`; `g_pAddItemDialog == this=0`; vptr/vfptr tokens `0`; `DialogPane::~DialogPane=0`; `operator delete=0`; adjustor tokens `0`.
- Surrounding preservation: one constructor definition and marker UID0004BM at line 24, UID0004BN at line 92, one OnAction definition/UID0004BO at line 101, one UpdateActionButton definition/UID0004BP at line 136, then UID000317 and UID00033R in their prior order. No aggregate destructor duplicate exists. UID00033Q's existing non-body `[[No Children Attached]]` placeholder remains a separate generated container marker and is not a UID0004BN duplicate.
- Remaining validator limitations: the non-fatal UID0003ID-family registry-reference warnings and project-wide generated children-marker/emitter findings are outside the accepted six-page edit set. They did not invalidate any C4BN claim and were not edited around.

## Changed Files

- Manually modified by B001 with `apply_patch`, exactly the accepted six by-* destinations:
  - `by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md`;
  - `by-class/AddItemDialog.md`;
  - `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md`;
  - `by-file/ItemDialogs.md`;
  - `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`;
  - `by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md`.
- Manually modified report: `tools/leaser/Agents/Agent-B001/research/0004BN-AddItemDialogDestructor-source-quality.md`.
- Validator-generated relevant output: `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp`; validator-owned registry, reference index, projected stats, generated metadata, and coverage metadata side effects are recorded under command ids above and were not manually edited.
- Created or renamed by B001 during callback: none. No new by-* child, ignored row, generated file, or report was created.
- Protected files manually edited by B001: none. IDA files/mutations: none.
- Lease proof: all six file-specific lease commands returned `Success`, every matching unlease returned `Success`, and the shared lease report showed no B001 lease after each release or at final check. A later unrelated B004 lease is present and was not touched.
- Lifecycle boundary: B001 ran no `execute_report`, dry run, lifecycle probe, report move, or archive command. External report validation/execution/count/path/move/archive state remains supervisor/validator-owned and is not asserted here.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation completed first: exact accepted Gate-1 SHA `CAB49A960BCEFCA81A53CA02107FA54EF9293F88D50A95F9CADB9E48A9416912` authorized this callback.
- [x] Ledger Action values remain limited to the six accepted report enums; every callback Verification state is now exactly `applied`, `already-present`, or `excluded-with-reason`, with no free-form state.
- [x] Edit scope remained exactly UID0004BN, UID000007, UID00033Q, UID0000KE, UID0002AY, and UID00033Y; no other by-* page changed.
- [x] Current target state and actual MCP/document/generated evidence remain recorded, with pre-callback facts explicitly historicalized.
- [x] C4BN-001 through C4BN-038 were handled individually; the separate Callback Verification Notes table proves each claim.
- [x] UID0004BN is `92/94`, owner/emitter UID000007, reconstructable true, position `20`, and `Nested:0`; validator `000000009842` recorded the score/position changes.
- [x] The guarded target body was replaced by the one accepted managed block only; generated output confirms one unconditional assignment.
- [x] UID0004BM remains position `10`; UID0004BO/UID0004BP/UID000317/UID00033R bodies and unrelated ItemDialogs family decisions remain present and ordered.
- [x] Scalar wrappers, adjustors, EH chunks, vptr stores, and base teardown remain compiler-generated/non-emitting support; generated forbidden-token counts are zero.
- [x] Both adjacent padding spans remain in UID00033Q; no split, padding child, or ignored row was created.
- [x] Complete caller/xref/vtable/global/RTTI/base/wrapper/derived/EH evidence and rejected alternatives are present across the six accepted destinations.
- [x] Historical B007 child-creation provenance remains under Supporting Research; all other matched reports remain classified by their exact support role.
- [x] Third-party import directive remains not applicable; this is project-authored UI code with no import requirement.
- [x] Each destination was reread immediately before leasing; the shared lease report showed no conflict or claim-invalidating drift.
- [x] Only one file was leased at a time; each file was scoped-validated while leased and released immediately after completion.
- [x] Six scoped validators are recorded with command id, timestamp, interval, exit, `ok`, side effects, warning disposition, and release proof.
- [x] Final authorized `--wait-generated` command `000000009852` ran only after all six accepted edits and completed successfully.
- [x] Generated ItemDialogs.cpp has one UID0004BN marker, one destructor, one assignment, zero guard, zero explicit compiler-wrapper tokens, and preserved constructor/action/update order.
- [x] B001 made no manual generated, tracker, coverage, supervisor, validator-state, lifecycle, or IDA edit; validator-owned side effects are separately identified.
- [x] B001 ran no report execution, lifecycle, move, or archive command.

Implementation callback pass:
- [x] Supervisor accepted the exact report SHA and explicitly authorized the same-report implementation callback.
- [x] UID0004BN was reread, leased, updated at report-level detail, validated by `000000009842`, and released; final waited revalidation was `000000009852` with no lease retained.
- [x] UID000007 was reread, leased, updated without formal/score loss, validated by `000000009846`, and released.
- [x] UID00033Q was reread, leased, updated without constructor/action/update loss, validated by `000000009847`, and released.
- [x] UID0000KE was reread, leased, updated without family/source loss, validated by `000000009849`, and released.
- [x] UID0002AY was reread, leased, updated without MixItem/declaration loss, validated by `000000009850`, and released.
- [x] UID00033Y was reread, leased, updated without wrapper-row/non-emitting loss, validated by `000000009851`, and released.
- [x] UID000009 and UID00013A remain unchanged as already-present derived-destructor support; neither was leased or edited.
- [x] Claim And Incorporation Ledger uses exact callback enums, and all 38 claims have separate detailed proof.
- [x] Target metadata, score, owner, emitter, position, nesting, summary, and exact managed C++ were applied as accepted; support metadata/formal blocks stayed unchanged.
- [x] Historical guarded-clear/base/prototype assumptions, rejected alternatives, and all negative evidence remain present in target/support/report history.
- [x] Every open question remains closed; no drift invalidated or altered an accepted claim.
- [x] All scoped command ids, timestamps, exits, `ok` states, side effects, non-fatal warnings, and lease releases are recorded in Validator Results.
- [x] Waited generated freshness, output SHA/mtime, exact counts, forbidden-token checks, and surrounding order are recorded.
- [x] Changed Files lists every manual destination, relevant validator output, protected-file boundary, and final lease-clear proof.
- [x] No accepted item is unapplied, blocked, compressed away, or silently substituted.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000009874","destination_path":"executed-b-agent-research/B001/0004BN-AddItemDialogDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0004BN-AddItemDialogDestructor-source-quality.md","timestamp":"2026-07-13T12:30:41-04:00","uid":"0004BN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
