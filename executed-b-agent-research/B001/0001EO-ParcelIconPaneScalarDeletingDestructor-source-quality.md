** TARGET-REPORT-UID:0001EO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001EO ParcelIconPane Scalar Deleting Destructor Source-Quality Report


## Finalized Report / Current Recommendation
- Current implementation: UID0001EO is fully researched MSVC scalar-deleting-destructor compiler glue at `92/94`, with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, `Nested:0`, and an exactly blank managed C++ body.
- Final disposition: the complete binary behavior is preserved as ABI evidence without hand-authoring or emitting the wrapper. The source-level cause is the implemented `ParcelIconPane` declaration containing a virtual destructor, direct `Singleton<ParcelIconPane>` inheritance, and corrected constructor/ordinary-destructor definitions that leave singleton publication/clear to that base.
- Applied action: the stale comment-only target marker and true/class-owned route were replaced; UID0000A5 now has the complete class declaration and `[[CHILDREN]]`; constructor/destructor Singleton source shape is corrected; callback, file, layout, aggregate, and ignored-padding support pages are synchronized.
- Confidence: very strong for wrapper identity, bounds, flags, vtable/thunk routes, cleanup sequence, source/compiler split, owner/emitter disposition, direct `Pane`/`Singleton<ParcelIconPane>` bases, exact class size, and source file. The class/layout support confidence is lower because the inactive final 32-bit member has no surviving data flow: `int m_notificationState` is the highest-probability human source representation, but its original lexical name and semantic role are inferred rather than symbol-proven.
- Current lifecycle truth: B001 completed the accepted bounded implementation callback and all authorized ordinary validations/generated verification. B001 performed no manual coverage edit, `execute_report`, report lifecycle/probe/count command, move, or archive. Current report path/count/execution/archive state remains external supervisor/validator-owned and is not asserted or directed by this artifact; no B001 implementation work remains.

## Supporting Research
- Fresh target research was performed against live NexusTK IDB session `64c11373`, worker PID `21508`. A final bounded transport recheck used MCP transport session `a698a3c9-f2a5-4366-a295-0b49f0587182`: request 2 returned one active IDB, request 3 returned `server_health:ok` with auto-analysis, Hex-Rays, and strings ready, request 4 reconfirmed `sub_546F40` size `0xb9` and no function at `0x00546ff9`, and request 5 returned the expected first 16 target bytes.
- Historical direct family lead: `source-3/project-documentation/executed-b-agent-research/B005/0000MF-ParcelPane-empty-emitter-family-source-quality.md` covered UID0001EO only as one row in a broad parcel family callback. Its binary/source split was useful, but its comment-only marker and true/class-emitting policy are superseded by current non-emitting compiler-glue policy.
- Historical constructor support: `source-3/project-documentation/executed-b-agent-research/B006/0001EG-ParcelIconPaneConstructor-empty-emitter-source-quality.md` established the outer constructor and `ParcelPane.cpp` route. Fresh target and caller evidence independently revalidates the allocation size and class receiver.
- Historical aggregate support: `source-3/project-documentation/executed-b-agent-research/B007/0001EH-ParcelNotificationPanes-source-quality.md` established the mixed aggregate/index disposition and parcel-family inventory; it is support, not target authority.
- Current policy comparator: `source-3/project-documentation/executed-b-agent-research/B008/0001EP-ParcelPaneScalarDeletingDestructor-empty-emitter-source-quality.md` supplies the accepted blank-C++, no-owner, non-emitting policy for the immediately adjacent same-family scalar wrapper. Fresh UID0001EO evidence independently reaches the same disposition.
- Other matching executed reports opened and classified: `source-3/project-documentation/executed-b-agent-research/B001/00043J-ParcelIconPaneParcelUpdateRawHelper-by-memory-source-quality.md` is incidental owner/callback support; `source-3/project-documentation/executed-b-agent-research/B002/00012X-versatile-alert-pane-callbacks-source-quality.md` is an unrelated compiler-wrapper policy mention; `source-3/project-documentation/executed-b-agent-research/B002/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md` is a sibling wrapper lead; `source-3/project-documentation/executed-b-agent-research/B002/0002KB-ParcelPaneConstructor-source-quality.md` is child-class support; `source-3/project-documentation/executed-b-agent-research/B006/0002KM-ClearParcelIconPaneSingleton-source-quality.md` is singleton/EH support; `source-3/project-documentation/executed-b-agent-research/B006/0002KN-ClearParcelPaneSingleton-source-quality.md` is adjacent singleton support; `source-3/project-documentation/executed-b-agent-research/B012/000058-FlyingParcelPane-class-source-quality.md` is sibling class context.
- At research-selection time, then-active roots `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/**` through `Agent-B005/research/**` and their then-current `goal.md` files were searched for target UID, address, title, `ParcelIconPane`, `ScalarDeletingDestructor`, `ParcelPane`, wrapper, vtable, singleton, and source-family terms. No direct target report was found in that evidence-time snapshot.
- The research-time central search of `source-3/project-documentation/executed-b-agent-research/**` produced only the exact opened paths above. Archive root `source-3/project-documentation/archived/**`, `Older-Research/**`, and `SpecialReports/**` returned no matching target report; legacy per-agent `research/executed` roots for B001-B005 were absent. The selection-time direct-report-count-zero fact is historical provenance only; this artifact does not assert current report count/path/archive state.
- Fresh repair-pass RTTI evidence identifies `Singleton<ParcelIconPane>` as a direct empty base, not merely a singleton-global convention. IDA names the ParcelIconPane RTTI descriptors at `0x0064dd14/0x0064dd28/0x0064dd38/0x0064dd58` and the Singleton base descriptors at `0x0064dd74/0x0064dd90/0x0064dda0/0x0064dda8`; the Singleton PMD is `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`. This matches the project-proven MSVC empty-base overlap pattern rather than adding a hidden four-byte base field.
- Whole-project source-shape comparators were opened, not inferred from names alone. `by-class/ScreenDimmer.md` emits `Pane, Singleton<ScreenDimmer>` and overlaps its empty base at `+0xf8` with a one-byte member while omitting natural tail padding; `by-class/TransferServerDialogPane.md` uses two observed 32-bit state fields after the same pane region; `by-class/MainMenuPane.md` omits unaccessed alignment bytes from source; and `by-class/ChattingVarietyPane.md` proves a project constructor may leave a real late member uninitialized when another path establishes it. Project fields actually named `m_reserved...` have positive storage behavior such as construction clears, copying, retention, or serialization. No same-or-better project-era precedent supports an explicit reserved byte array solely to force class size.
- The repair-pass MCP evidence remained healthy on NexusTK IDB `64c11373`, worker PID `21508`. Bounded class-island displacement searches, all six singleton xrefs, constructor callers, vtable xrefs, and RTTI/data reads completed. One earlier broad whole-image scan timed out while the worker stayed healthy; it was replaced by bounded target-family queries and is a tool-call limitation, not missing evidence or an MCP outage.

## Target
- Target UID: `0001EO`.
- Target path: `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`.
- Historical queue/report row at research selection: `by-memory`, `Not-Covered Files - Reconstructable`, then-ordinary state `86/90`, true, owner/emitter UID0000A5, and direct-report count zero. This is timestamped research provenance, not a current tracker/count assertion.
- Supervisor classification: exact report SHA `CFE7F66787796B1B90C8CF7430963AD377D7B8266F051E6C4F04D8E2158C08AF` passed Gate 1 and authorized the bounded nine-destination implementation callback.
- Current scores and parent state: `92/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, exactly blank formal body, `Nested:0`.
- Exact binary range: `[0x00546f40,0x00546ff9)`, 185 bytes / `0xb9`.

## Current Target State
- UID0001EO now records the exact wrapper as compiler output, ownerless and non-emitting, while preserving the complete function boundary, bytes/hash, CFG, ABI, three vtable routes, child dismissal, singleton clear, base teardown, flags, conditional free, negative caller evidence, and historical policy.
- Its managed body is exactly blank. The old three-line explanatory marker and true/class-owned/emitting state survive only in explicit historical/superseded text with rejection reasons.
- UID0000A5 now emits a source-clean `ParcelIconPane` declaration with direct `Pane` and `Singleton<ParcelIconPane>` bases, virtual destructor, callback declaration, proven fields, inferred inactive final int, and `[[CHILDREN]]`.
- UID0001EG initializes the direct Singleton base and omits manual publication. UID0001EI contains only unguarded child dismissal and event unregister, leaving unconditional singleton clear and Pane teardown to reverse base destruction. UID0001EJ retains its accepted packet body unchanged and now has a complete class route.
- Class/layout docs cover the exact `0x104` object: byte counts at `+0xf8..+0xfa`, natural alignment at `+0xfb`, child pointer at `+0xfc`, and inferred inactive `int m_notificationState` at `+0x100`. Exhaustive no-use and ranked/rejected alternatives remain explicit.
- `by-memory/-ignored.md` now contains both the pre-existing nine-byte predecessor padding and the newly added seven-byte successor padding. UID0001EH inventory is synchronized without metadata/formal changes.
- B001 final waited command `000000013049` generated and verified the accepted source shape. At the final reconciliation readback `2026-07-15T09:30:50-04:00`, a later external validator refresh supplied header command `000000013055`, timestamp `2026-07-15T09:27:44-04:00`, SHA256 `9D3F51DB3A4D83F0E1F570FE76FE408ED501E39E2F405E730A2B60F0529F9632`, 4,771 bytes / 130 lines. That evidence-time content retained one complete class definition, constructor, ordinary destructor, and callback in source order and zero UID0001EO marker/body/comment.
- Related target/support docs checked: UID0001EI, UID0001EG, UID0001EJ, UID0001EM, UID0001EH, UID0001EN, UID0001EP, UID0000A5, UID0000MF, UID0001VI, UID0001YE, UID0002OH, UID0000RX, UID0002W9, `by-memory/-ignored.md`, current manual coverage rows, and current generated `ParcelPane.cpp`.

## Executive Recommendation
- Implemented disposition: UID0001EO is compiler output with no source owner or emitter. Its page emits no function, marker, alias, vptr write, base teardown, flag branch, thunk, or delete call.
- Implemented declaration: UID0000A5 is the source declaration surface with direct `Pane`/`Singleton<ParcelIconPane>` bases, proven parcel fields, inferred inactive final int, virtual destructor, callback, singleton extern, and `[[CHILDREN]]`.
- Implemented lifecycle source: UID0001EG uses `Singleton<ParcelIconPane>()`; UID0001EI contains only child dismissal and unregister. Compiler-inlined direct-base lifecycle preserves unconditional publication/clear and inherited teardown.
- Implemented source placement remains UID0000MF `NexusTK/ui/panels/ParcelPane.cpp`; rejected standalone wrapper/method/flags/relocation alternatives remain rejected.
- Implemented padding synchronization adds exactly `[0x00546ff9,0x00547000)` while preserving the predecessor row.

## Supervisor Active Recheck
- The authoritative callback accepted the exact Gate-1 artifact and bounded B001 to the nine ordinary destinations implemented here.
- No split is required: IDA models one exact function at `0x00546f40` of size `0xb9`; the neighboring ranges are all-`0xcc` padding or separately modeled sibling functions.
- Every source-bearing item needed to regenerate the wrapper now has its complete disposition: UID0000A5 has the declaration; UID0001EG and UID0001EI have corrected direct-Singleton-aware definitions; UID0001EJ retains its complete body; all three have a live `[[CHILDREN]]` route; UID0001EO and UID0001EM remain non-emitting compiler products.
- No new by-memory child, new UID, source file, or direct scalar-wrapper function was created or required.

## Inference Research Guidance Check
- `by-structure.md` and the workflow compiler-glue rule separate documented binary behavior from handwritten reconstruction eligibility. A page can be highly complete/confident while `RECONSTRUCTABLE:FALSE`, ownerless, and non-emitting.
- IDA facts: range, bytes, instructions, branches, vtable slots, thunks, globals, callees, object sizes, constructor call sites, and padding.
- Documentation evidence: accepted names such as `ParcelIconPane`, `m_parcelPane`, `g_pParcelIconPane`, `UnregisterEventHandler`, and the cleanup-queue facade; file and class routing; existing ordinary C++.
- Inference: `int m_notificationState` is the selected source-facing representation for the otherwise inactive final dword because a human-written 32-bit state member is more plausible in this parcel-notification class than explicit reverse-engineering padding. The exact original spelling remains unknown. `protected` access for `OnParcelUpdate` is source-plausible and has no ABI effect; the vtable route proves virtual membership, not original access specifier.
- Historical generated `simroot_v2`, Wave2, and Wave3 mentions were treated only as stale leads. Fresh live IDA evidence and the time-scoped validator-generated checkpoints recorded below control this recommendation.

## Heuristic / Inference Reanalysis And Validation
- Generated name issue: `sub_546F40` is not a plausible human method name. Three destructor vtable routes, ordinary-destructor parity, incoming deleting-destructor flags, and conditional storage release prove compiler-generated scalar deleting destructor identity.
- Ownership issue: vtable membership proves that the compiler generated the wrapper for `ParcelIconPane`; it does not make this machine body a source-authored class method page. The correct source owner of the declaration and ordinary semantics is UID0000A5/UID0001EI, while the wrapper page itself is ownerless.
- Flag issue: the first argument byte is tested with masks `0x01` and `0x04`. Mask `0x01` controls whether any storage-release path is entered; without `0x04`, the body calls the ordinary MemoryMan-backed unsized free wrapper; with `0x04`, it takes the size-bearing compiler/runtime path with literal `0x104`. No stronger source-level names are assigned to these compiler flags.
- Child issue: both ordinary and scalar destructors read `this+0xfc` and unconditionally submit that value to the pane-manager dismissal helper. The helper itself handles null/sentinel cases. The source destructor must not add a target-side null guard not present in source evidence.
- Singleton issue: constructor publication and both destructor-machine clears are unconditional, and there is no comparison with `this`. RTTI proves these stores are inlined `Singleton<ParcelIconPane>` construction/destruction effects. Source must initialize the direct base and must not duplicate publication/clear as body assignments; a guarded clear is also rejected.
- Base issue: `sub_544D70` unregisters the secondary event-handler view, inlined `Singleton<ParcelIconPane>` destruction clears the singleton, and `sub_544580` performs inherited `Pane` teardown. Only child dismissal and unregister are explicit in the ordinary destructor. Singleton clear, the Pane destructor call, and all vptr restores are compiler effects.
- Adjustor issue: `0x00546ea1` and `0x00546eac` subtract `0xa0` and `0xa4` respectively and tail-jump to the target. They are generated from secondary/tertiary base views and must remain under UID0001EM's false/no-code policy.
- Caller/reachability issue: no ordinary call targets UID0001EO. Its only inbound code routes are the two thunks, and its primary data route is vtable slot `0x00621bb4`; this is exactly the reachability expected for a virtual deleting destructor.
- Direct-base/layout issue: live RTTI places direct empty base `Singleton<ParcelIconPane>` at `mdisp=0xf8` with non-virtual PMD values and attributes `0x40`, matching the proven MSVC EBO pattern used by other Pane singletons. Two `sub_4F7D10` construction paths allocate `0x104` bytes before calling UID0001EG, and UID0001EO's `0x04` flag path also carries literal `0x104`; this fixes the complete-object size independently of inferred field names.
- Whole-use tail issue: bounded search of `[0x00545e40,0x00547000)` found eleven `0x100` displacements, but each belongs to the separately allocated child `ParcelPane` rectangles or `FlyingParcelPane::m_animationLayer`; it found zero `0x101`, `0x102`, or `0x103` displacements for the outer object. The six `g_pParcelIconPane` routes only publish, test/queue, or clear the pointer. Each of the three ParcelIconPane vtables is referenced only by constructor, ordinary destructor, and scalar wrapper stores. No constructor variant, EH clear, global consumer, callback, pointer-derived route, adjusted-`this` route, copy, or cleanup accesses the final dword.
- Source-era inference issue: `int m_notificationState` ranks first because it has the exact four-byte width, is feature-local, requires no invented ownership, and is plausible as an inactive status field removed from current control flow while retained in class layout. A one-byte `bool m_updatePending` plus three bytes of natural padding ranks second but is weaker because comparable project flags are initialized or tested. A `ParcelNotificationState` enum ranks third because no value or switch evidence survives. A pointer is rejected for lack of initialization/use/release. `unsigned char m_reservedTail[4]` is rejected as a reverse-engineering placeholder: high-quality project declarations omit pure padding, while genuine reserved storage has positive data flow.
- Singleton source-shape issue: ScreenDimmer, SimpleHelpPane, ChattingBackPane, MapTileImageLib, and other current direct-Singleton declarations model publication/clear through the template base, not body-level global assignment. ParcelIconPane's constructor store occurs after Pane construction at the Singleton subobject stage, and destructor clear occurs between derived cleanup and reverse-order Pane destruction. The prior manual assignment/clear drafts are historical decompiler-shaped source and have been replaced by a base initializer plus implicit base teardown.
- Generated-output issue: the comment-only UID0000A5 block lacks `[[CHILDREN]]`, so every read-only `ParcelPane.cpp` checkpoint recorded by this report contains no actual class or child bodies. A complete class block with `[[CHILDREN]]` is required. The wrapper itself should disappear entirely from source output because the compiler regenerates it.
- Score issue: the target can reach `92/94` despite false reconstruction because all binary, ABI, route, and source-disposition questions are resolved. Class support is capped at `91/92` and layout support at `90/92` because the final member's exact original spelling/meaning remains inferred even though direct bases, width, position, object size, and no-use behavior are resolved.
- Rejected original-source shapes: explicit `ParcelIconPane::ScalarDeletingDestructor`, `ParcelIconPane::~ParcelIconPane(unsigned int flags)`, explicit operator delete, explicit vptr assignment, explicit base-destructor call, a comment-only generated marker, a new source file, and a guarded singleton clear.

## Evidence Standards Used
- Live IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `analyze_function`, `basic_blocks`, `xrefs_to`, bounded `xref_query`, `callees`, `get_int`, bounded `find_bytes`, bounded text searches, and data-flow checks.
- Raw evidence: full 185-byte target digest, first/last bytes, predecessor/successor padding, exact return instruction, exact instruction masks, literal object size, and direct vtable/global values.
- Structural evidence: ordinary destructor parity, constructor allocation sites, primary/secondary/tertiary vtable slots, two adjustor thunks, singleton xref family, and adjacent sibling scalar wrappers.
- Documentation evidence: current by-* metadata/formal blocks, accepted historical reports, current generated output, manual coverage rows, and ignored-range ledger.
- Negative evidence: no ordinary target caller, no extra absolute target pointer, no function at the exclusive end, no source access to outer `+0x100..+0x103`, no pointer ownership lifecycle for the final dword, no target marker/body in the time-scoped generated checkpoints, and no standalone direct prior report.
- Tool limitation: one broad `.text` immediate-value instruction scan timed out after 60 seconds before scanning useful results. MCP remained healthy; narrower target-specific pointer, xref, byte, and range queries completed and supplied the required evidence. No conclusion depends on the timed-out broad scan.

## Evidence Checked
- IDA target checks: exact start/end lookup, full bytes, SHA256, CFG, decompile, instruction listing, callees, target xrefs, vtable values/xrefs, singleton xrefs, ordinary destructor, constructor allocation callers, child-dismissal helper, event-unregister helper, base teardown, operator-delete wrapper, and special size path.
- Tail/inheritance checks: complete ParcelIconPane/Singleton RTTI entity set; Singleton base-descriptor bytes and PMD integers; all three vtable xref sets; all six `g_pParcelIconPane` xrefs and relevant decompilations; bounded `0x100/0x101/0x102/0x103`, `0xf8`, and `0xfc` displacement searches; MainUiGraph `0x104` allocations; parcel-island constructor/EH/callback/destructor routes; and sibling Pane-singleton/source-layout comparators.
- Boundary checks: nine predecessor `0xcc` bytes at `[0x00546f37,0x00546f40)`, seven successor `0xcc` bytes at `[0x00546ff9,0x00547000)`, and separately modeled successor `sub_547000`.
- Documentation checks: target, class, file, constructor, ordinary destructor, callback, aggregate, adjustor thunks, sibling wrappers, layout, vtable inventory/data, singleton pages, ignored ranges, generated `ParcelPane.cpp`, and all affected manual coverage rows.
- Historical searches: active B001-B005 reports, central executed/archive/invalidated roots, missing legacy per-agent executed roots, `Older-Research`, and `SpecialReports`; relevant matches and their direct/incidental classifications are recorded in Supporting Research.
- Historical B001 evidence-time generated checkpoint: `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`, SHA256 `A680CC1AE34FEEECFADEAB496B9E19B76D54ABD0B2CCD777D4BD7C6FD400894C`, 2,607 bytes, 47 physical lines, validator command `000000012954`, refreshed `2026-07-15T07:56:58-04:00`. It is not presented as current.
- Supervisor Gate-1-audit-time checkpoint: command `000000012968`, refreshed `2026-07-15T08:13:22-04:00`, SHA256 `8A7B67203028568EB52C204E8EF3F6AF17E7B7931EEBDD09C418CFFAD618C4BF`. B001's later repair-final read-only checkpoint observed command `000000013032`; its exact hash/timestamp is recorded in Validator Results. All three checkpoints have the same relevant semantic counts: one UID0000A5 comment marker; zero UID0001EG, UID0001EI, UID0001EJ, and UID0001EO markers; zero `class ParcelIconPane`; zero constructor, destructor, or callback definitions; and zero `Empty Emitter Marker` text.
- Callback boundary: no IDA mutation, manual coverage edit, generated-file edit, or report lifecycle command was performed. Ordinary edits, short leases, scoped validators, and one waited generated refresh were performed only after exact-artifact Gate 1 authorization.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1EO-001 | UID0001EO is exactly `[0x00546f40,0x00546ff9)`, size `0xb9`. | 99 | MCP lookup/start/end and full bytes. | UID0001EO Boundary Evidence. | incorporate | applied |
| C1EO-002 | The exact 185 target bytes hash to `0C1591ECCCC2BFB5D9B5846054174EBA2FD819E51B2643C6F77C0FCE16DDDE6A`. | 99 | Full bounded byte read and SHA256. | UID0001EO Binary Evidence. | incorporate | applied |
| C1EO-003 | `[0x00546f37,0x00546f40)` is nine-byte `0xcc` predecessor alignment and is already documented. | 99 | Raw bytes and current ignored row. | `by-memory/-ignored.md` verification. | already-present | already-present |
| C1EO-004 | `[0x00546ff9,0x00547000)` is seven-byte `0xcc` successor alignment and needs an ignored row. | 99 | Raw bytes and successor lookup. | `by-memory/-ignored.md`. | incorporate | applied |
| C1EO-005 | The target is an MSVC scalar deleting destructor wrapper, not a handwritten method. | 99 | Destructor slot, flags, parity, conditional free, `retn 4`. | UID0001EO Status/Disposition. | incorporate | applied |
| C1EO-006 | The ABI shape is `this`, one incoming flag byte/word slot, and a returned original object pointer; it is not a source signature. | 98 | Decompile, disassembly, epilogue. | UID0001EO ABI Evidence. | incorporate | applied |
| C1EO-007 | The wrapper reads the associated child pane from owner offset `+0xfc`. | 99 | `push [esi+0xfc]` and ordinary parity. | UID0001EO Behavior; UID0000A5 layout. | incorporate | applied |
| C1EO-008 | The wrapper restores vtables `0x00621bb4`, `0x00621c00`, and `0x00621c30`. | 99 | Three stores and vtable xrefs. | UID0001EO Vtable Evidence. | incorporate | applied |
| C1EO-009 | Child dismissal is submitted unconditionally through `sub_469180`; source must not add a target-side null guard. | 97 | Disassembly, helper analysis, ordinary parity. | UID0001EO; UID0001EI history. | incorporate | applied |
| C1EO-010 | `sub_544D70` unregisters the secondary event-handler view and maps to accepted `UnregisterEventHandler()`. | 96 | Target/ordinary callees and support docs. | UID0001EO; UID0001EI. | incorporate | applied |
| C1EO-011 | The wrapper unconditionally clears `g_pParcelIconPane` at `0x00546fa0`. | 99 | Direct store and singleton xrefs. | UID0001EO; UID0000A5/file history. | incorporate | applied |
| C1EO-012 | `sub_544580` is implicit inherited `Pane` teardown and must not appear in source C++. | 98 | Callee body/family evidence. | UID0001EO no-code proof; UID0001EI history. | incorporate | applied |
| C1EO-013 | Mask `0x01` controls entry to a storage-release path; zero returns without freeing storage. | 99 | Exact branch at wrapper tail. | UID0001EO Flag Flow. | incorporate | applied |
| C1EO-014 | When `0x01` is set and `0x04` is clear, the wrapper calls the MemoryMan-backed unsized free helper `sub_4F4AC0`. | 98 | Exact branch and callee analysis. | UID0001EO Flag Flow. | incorporate | applied |
| C1EO-015 | When `0x04` is set, the wrapper takes the compiler/runtime size path with literal `0x104`; no handwritten equivalent is warranted. | 97 | Exact instructions and one-byte runtime helper. | UID0001EO Flag Flow/Layout. | incorporate | applied |
| C1EO-016 | All wrapper exits restore SEH state, return the original object pointer, and end in `retn 4`. | 99 | CFG/disassembly. | UID0001EO ABI Evidence. | incorporate | applied |
| C1EO-017 | Primary vtable slot `0x00621bb4` points directly to UID0001EO. | 99 | `get_int`, xref, vtable docs. | UID0001EO; UID0001YE/UID0002OH verification. | incorporate | applied |
| C1EO-018 | Secondary slot `0x00621c00` points to thunk `0x00546ea1`, which subtracts `0xa0` and jumps to UID0001EO. | 99 | `get_int`, thunk disassembly/xrefs. | UID0001EO; UID0001EM verification. | incorporate | applied |
| C1EO-019 | Tertiary slot `0x00621c30` points to thunk `0x00546eac`, which subtracts `0xa4` and jumps to UID0001EO. | 99 | `get_int`, thunk disassembly/xrefs. | UID0001EO; UID0001EM verification. | incorporate | applied |
| C1EO-020 | No ordinary direct caller or extra absolute/RVA target pointer was recovered. | 98 | Target xrefs and bounded pointer searches. | UID0001EO Reachability/Negative Evidence. | incorporate | applied |
| C1EO-021 | UID0001EI performs the same source-level cleanup before the wrapper-only flag/free tail. | 99 | Fresh ordinary destructor analysis. | UID0001EO relationship; UID0001EI. | incorporate | applied |
| C1EO-022 | UID0001EI has no flags/free path and is the source-authored ordinary destructor anchor; singleton clear is an inlined direct-base destruction effect. | 99 | Function body/callees, RTTI, and reverse base order. | UID0001EI Status/Source Disposition. | incorporate | applied |
| C1EO-023 | UID0001EI source must retain unguarded child dismissal and unregister but remove the manual global clear because `Singleton<ParcelIconPane>` owns it. | 98 | Binary operation order, direct-base RTTI, and project Singleton source convention. | UID0001EI formal/history. | reject-stale | applied |
| C1EO-024 | A `virtual ~ParcelIconPane()` declaration is the source-level cause that regenerates the primary/adjusted destructor routes. | 98 | Vtable/thunk/compiler pattern and adjacent comparator. | UID0000A5 formal declaration. | incorporate | applied |
| C1EO-025 | UID0001EO must become `RECONSTRUCTABLE:FALSE`. | 99 | Compiler-generated-only proof. | UID0001EO metadata. | incorporate | applied |
| C1EO-026 | UID0001EO must become `CANONICAL_OWNER:NONE`; class relationship remains prose evidence. | 99 | Source/compiler ownership rule. | UID0001EO metadata. | incorporate | applied |
| C1EO-027 | UID0001EO must have blank `EMITTER_UIDS` and blank position. | 99 | Non-emitting compiler disposition. | UID0001EO metadata. | incorporate | applied |
| C1EO-028 | UID0001EO's managed C++ body must be exactly blank; the comment-only marker is stale. | 99 | Current policy comparator UID0001EP. | UID0001EO formal block/history. | reject-stale | applied |
| C1EO-029 | UID0001EO should score `92/94`, with `Nested:0` retained. | 96 | Complete binary/ABI/source disposition; name/version cap. | UID0001EO metadata/summary. | incorporate | applied |
| C1EO-030 | UID0000A5 needs a complete class declaration and `[[CHILDREN]]`, not a comment-only support marker. | 98 | Current generated omission and complete layout/method evidence. | UID0000A5 formal block. | incorporate | applied |
| C1EO-031 | Proven outer fields are three byte counts at `+0xf8..+0xfa` and `ParcelPane *m_parcelPane` at `+0xfc`; `+0xfb` is natural alignment. | 98 | Constructor/callback/destructor owner accesses. | UID0000A5; UID0001VI. | incorporate | applied |
| C1EO-032 | `sizeof(ParcelIconPane)` is `0x104`; the inactive final dword is best represented as inferred human source `int m_notificationState`, with no invented initialization or behavior. | 92 | Two constructor allocations, wrapper size path, exhaustive no-use pass, ranked project-era source comparison. | UID0000A5; UID0001VI; UID0001EG. | incorporate | applied |
| C1EO-033 | UID0000A5 should score `91/92`, retaining owner/emitter UID0000MF and reconstructable true. | 93 | Complete declaration/route/direct bases; final private member spelling/meaning remains inferred. | UID0000A5 metadata. | incorporate | applied |
| C1EO-034 | UID0001EI should score `92/94`, retain owner/emitter UID0000A5, and use the corrected two-action body with implicit Singleton-base clear. | 97 | Fresh ordinary/wrapper parity, direct-base RTTI, and complete source/compiler split. | UID0001EI metadata/prose/formal. | incorporate | applied |
| C1EO-035 | UID0001EG should score `91/93`; replace manual singleton publication with `Singleton<ParcelIconPane>()`, preserve the remaining body, and record outer `0x104` allocation/final-dword evidence. | 95 | Two callers allocate 260 bytes; target confirms size; RTTI and publish order prove base construction. | UID0001EG metadata/prose/formal. | incorporate | applied |
| C1EO-036 | UID0001EJ should score `90/92`; preserve its exact body and record that UID0000A5 now supplies the declaration/child route. | 93 | Existing accepted callback body/vtable plus resolved class route. | UID0001EJ metadata/prose. | incorporate | applied |
| C1EO-037 | UID0000MF should score `91/92` and document the complete ParcelIconPane source/compiler split while preserving broader sibling caveats. | 93 | Source-family clustering and generated-route repair. | UID0000MF status/history. | incorporate | applied |
| C1EO-038 | UID0001VI should score `90/92`, retain its current route/formal support marker, and add exact direct-base, outer-size, final-dword, ranked-inference, and no-access facts. | 92 | RTTI/PMD, direct layout, negative access evidence, and broader family role. | UID0001VI metadata/layout. | incorporate | applied |
| C1EO-039 | UID0001EM already has the correct false/no-owner/blank-C++ adjustor-thunk disposition. | 99 | Fresh thunk disassembly and current page. | UID0001EM verification only. | already-present | already-present |
| C1EO-040 | UID0001EH already has the correct false/no-owner/blank-C++ aggregate disposition; only its target row/padding inventory needs prose sync. | 98 | Current aggregate and exact child boundaries. | UID0001EH inventory/history. | incorporate | applied |
| C1EO-041 | UID0001YE and UID0002OH accurately map the three ParcelIconPane vtable views; no target-specific metadata change is required. | 99 | Fresh `get_int`/xrefs and current tables. | UID0001YE/UID0002OH verification only. | already-present | already-present |
| C1EO-042 | UID0001EP is the accepted current-policy comparator; UID0001EN's comment-only true/emitting state is a stale sibling control, not authority for UID0001EO. | 97 | Current pages and executed reports. | UID0001EO history; UID0000MF support. | historicalize | applied |
| C1EO-043 | Time-scoped command 12954, supervisor command 12968, and B001 repair-final command 13032 generated checkpoints all omit every ParcelIconPane method because UID0000A5 lacks an actual declaration and child marker. | 99 | Historical/repair checkpoint headers, hashes, and identical semantic counts. | UID0000A5/UID0000MF generated-state prose. | incorporate | applied |
| C1EO-044 | Expected callback output is one class, constructor, ordinary destructor, and callback, with zero UID0001EO marker/body and zero explicit compiler teardown/delete/thunk code. | 98 | Generator route and source/compiler split. | Report checklist; target/class/file changes. | incorporate | applied |
| C1EO-045 | The current target manual coverage row is stale and needs exact supervisor replacement text. | 99 | Current manual row versus recommendation. | `by-memory/-coverage-report.md` handoff. | incorporate | excluded-with-reason |
| C1EO-046 | Current constructor/destructor/callback/class/file/layout manual rows are stale and need exact supervisor replacement text. | 99 | Current manual rows versus implemented callback state. | Coverage handoff section. | incorporate | excluded-with-reason |
| C1EO-047 | B005's comment-marker/class-emitter implementation is valid historical provenance but superseded current policy. | 98 | Executed B005 report and modern comparator. | Target/class/file Historical sections. | historicalize | applied |
| C1EO-048 | No IDA rename/type mutation, third-party import, split, new UID, new source file, or standalone wrapper implementation is applicable. | 99 | Complete evidence and workflow boundaries. | Report and destination notes. | not-applicable | excluded-with-reason |
| C1EO-049 | `Singleton<ParcelIconPane>` is a direct non-virtual empty base at `mdisp=0xf8`, and the class declaration must name it explicitly. | 99 | Live RTTI entities, BCD bytes, PMD integers, and project EBO comparator. | UID0000A5 formal/layout; UID0001VI. | incorporate | applied |
| C1EO-050 | The final-dword ranking is inactive `int` state first, one-byte pending flag plus padding second, enum third; pointer and explicit reserved-byte-array forms are rejected. | 91 | Exhaustive no-use pass and source-era class/layout comparators. | UID0000A5/UID0001VI inference/history. | incorporate | applied |
| C1EO-051 | Command 12954 is historical; command 12968 is the supervisor audit checkpoint; command 13032 is the later B001 repair-final checkpoint, with unchanged target semantic counts. | 99 | Read-only generated headers, hashes, sizes, lines, and token counts. | Report/UID0000A5/UID0000MF generated history. | historicalize | applied |
| C1EO-052 | Destination 2 must contain plausible developer C++ only: direct bases, declarations, fields, and `[[CHILDREN]]`, with no offset/range/reverse-engineering comments. | 99 | Exact managed-block policy and repaired declaration. | UID0000A5 formal block. | incorporate | applied |
| C1EO-053 | UID0001EG must initialize `Singleton<ParcelIconPane>()` and omit manual `g_pParcelIconPane = this`; the final inferred int remains intentionally uninitialized. | 98 | Constructor ordering, RTTI/PMD, inlined publish store, and project Singleton comparators. | UID0001EG formal/history. | incorporate | applied |
| C1EO-054 | UID0001EI must omit manual singleton clear; reverse destruction of the direct Singleton base regenerates the exact unconditional clear before Pane teardown. | 98 | Destructor operation order, direct-base RTTI, and project Singleton comparators. | UID0001EI formal/history. | incorporate | applied |

### Callback Verification Notes
| Claim | Terminal proof |
| --- | --- |
| C1EO-001 | UID0001EO Boundary Evidence now states exact `[0x00546f40,0x00546ff9)` and `0xb9`; scoped validator `000000013038` passed. |
| C1EO-002 | UID0001EO Binary Evidence preserves all 185 bytes and SHA256 `0C1591ECCCC2BFB5D9B5846054174EBA2FD819E51B2643C6F77C0FCE16DDDE6A`; validator `13038` passed. |
| C1EO-003 | The predecessor `[0x00546f37,0x00546f40)` row was reread before editing `by-memory/-ignored.md`, remained unchanged, and command `13048` validated the file. |
| C1EO-004 | The exact seven-byte `[0x00546ff9,0x00547000)` row, all-`0xcc` evidence, regeneration explanation, and owner/support links were added to `by-memory/-ignored.md`; command `13048` passed. |
| C1EO-005 | UID0001EO Status/Disposition now identifies compiler scalar deleting destructor glue and rejects handwritten method treatment; command `13038` passed. |
| C1EO-006 | UID0001EO ABI Evidence records `this`, incoming flags, returned original pointer, SEH restoration, and `retn 4` without inventing a source signature; command `13038` passed. |
| C1EO-007 | Target behavior and UID0000A5/UID0001VI layout now synchronize child pointer `+0xfc`; commands `13038`, `13041`, and `13046` passed. |
| C1EO-008 | UID0001EO preserves all three vtable restores and routes in prose while generated source contains no explicit vptr code; command `13038` and final readback `13049` passed. |
| C1EO-009 | Target and UID0001EI preserve unconditional child submission and explicitly reject a target-side null guard; commands `13038` and `13042` passed. |
| C1EO-010 | Target/ordinary-destructor prose preserves `sub_544D70` evidence and formal source uses exactly `UnregisterEventHandler()`; commands `13038` and `13042` passed. |
| C1EO-011 | Target/file/class history preserves the unconditional machine clear while current source assigns it to implicit Singleton destruction; commands `13038`, `13041`, and `13045` passed. |
| C1EO-012 | Target no-code proof and ordinary-destructor prose classify `sub_544580` as implicit Pane teardown; final generated source has zero explicit `Pane::~Pane`; commands `13038`, `13042`, and `13049` passed. |
| C1EO-013 | UID0001EO Flag Flow retains exact `0x01` entry-to-release semantics; command `13038` passed. |
| C1EO-014 | UID0001EO Flag Flow retains the `0x01` set/`0x04` clear MemoryMan unsized free branch; command `13038` passed. |
| C1EO-015 | UID0001EO Flag Flow/Layout retains the `0x04` size-bearing path and literal `0x104`; generated source has no equivalent handwritten branch; commands `13038` and `13049` passed. |
| C1EO-016 | UID0001EO ABI/CFG evidence preserves all exits, SEH restoration, original-pointer return, and `retn 4`; command `13038` passed. |
| C1EO-017 | Primary slot `0x00621bb4` route remains in target prose; UID0001YE/UID0002OH were verify-only and retained hashes `869FF0...DE5C` / `6B4176...FCAB`; command `13038` passed. |
| C1EO-018 | Secondary thunk `0x00546ea1`, `-0xa0`, and jump route remain in target prose; UID0001EM remained verify-only at SHA `2E2F08...D248`; command `13038` passed. |
| C1EO-019 | Tertiary thunk `0x00546eac`, `-0xa4`, and jump route remain in target prose; UID0001EM remained unchanged and command `13038` passed. |
| C1EO-020 | UID0001EO Reachability/Negative Evidence retains no ordinary caller and no extra absolute/RVA pointer result; command `13038` passed. |
| C1EO-021 | Target and UID0001EI document exact cleanup-prefix parity; the generated ordinary body occurs once and has only the two source actions; commands `13038`, `13042`, and `13049` passed. |
| C1EO-022 | UID0001EI Status/Source Disposition identifies the ordinary body as source anchor with no flags/free path and implicit Singleton clear; command `13042` passed. |
| C1EO-023 | UID0001EI formal C++ retains unguarded queue/unregister calls and removes manual global clear; B005 three-action draft is explicitly historical; command `13042` passed. |
| C1EO-024 | UID0000A5 formal declaration contains exactly `virtual ~ParcelIconPane();`; final generation contains one declaration and one ordinary definition; commands `13041` and `13049` passed. |
| C1EO-025 | UID0001EO header is `RECONSTRUCTABLE:FALSE`; command `13038` passed. |
| C1EO-026 | UID0001EO header is `CANONICAL_OWNER:NONE`; class relationship is retained only in prose; command `13038` passed. |
| C1EO-027 | UID0001EO has blank `EMITTER_UIDS` and blank optional position; command `13038` passed. |
| C1EO-028 | UID0001EO managed block is exactly blank and old marker is historicalized; final generated file has zero UID0001EO or Empty Emitter Marker token; commands `13038` and `13049` passed. |
| C1EO-029 | UID0001EO header is `92/94` and `Nested:0`; command `13038` passed. |
| C1EO-030 | UID0000A5 now contains the complete source-clean class declaration and `[[CHILDREN]]`; command `13041` passed and command `13049` emitted the class plus children. |
| C1EO-031 | UID0000A5 and UID0001VI contain three byte counts, natural `+0xfb` alignment, and `ParcelPane *m_parcelPane` at `+0xfc`; commands `13041` and `13046` passed. |
| C1EO-032 | UID0000A5/UID0001VI/UID0001EG record exact `0x104`, inferred inactive `int m_notificationState`, exhaustive no-use evidence, and deliberate noninitialization; commands `13041`, `13043`, and `13046` passed. |
| C1EO-033 | UID0000A5 is `91/92`, owner/emitter UID0000MF, reconstructable true; command `13041` passed. |
| C1EO-034 | UID0001EI is `92/94`, owner/emitter UID0000A5, with the exact two-action managed body and implicit-clear prose; command `13042` passed. |
| C1EO-035 | UID0001EG is `91/93`, uses `Singleton<ParcelIconPane>()`, omits manual publication, preserves child allocation, and records both `0x104` callers/final-int negative evidence; command `13043` passed. |
| C1EO-036 | UID0001EJ is `90/92`; its managed body was preserved and the class/child route synchronized; command `13044` passed. |
| C1EO-037 | UID0000MF is `91/92` and records the complete ParcelIconPane source/compiler split while retaining unrelated ParcelPane/FlyingParcelPane caveats; command `13045` passed. |
| C1EO-038 | UID0001VI is `90/92`, retains owner/emitter/formal support marker, and contains PMD/EBO, size, final-dword ranking, and no-use evidence; command `13046` passed. |
| C1EO-039 | UID0001EM remained unchanged at SHA256 `2E2F08F7EC75C952BEA477A950C49AE976E0EA7FE78FE7581BE034D5FA13D248`; no edit or lease was used. |
| C1EO-040 | UID0001EH retained `88/91`, none/false/no-emitter/blank formal while target and successor-padding inventory/history were synchronized; command `13047` passed. |
| C1EO-041 | UID0001YE and UID0002OH remained unchanged at SHA256 `869FF037...DE5C` and `6B4176CF...FCAB`; no target-specific metadata edit was made. |
| C1EO-042 | UID0001EP remains current-policy comparator at SHA `AF4637...CDB4`; UID0001EN remains unchanged at SHA `7F4475...5F4` and is labeled historical stale policy in target/file prose. |
| C1EO-043 | Commands `12954`, `12968`, and `13032` remain timestamped historical omission checkpoints; class/file prose now contrasts them with current command `13049`. |
| C1EO-044 | B001 command `13049` generated one complete class definition, constructor, ordinary destructor, and callback in order; zero UID0001EO, empty marker, manual method publication/clear, vptr, base-destructor, delete, scalar-wrapper, or thunk tokens. Current external refresh `13055` preserves the same semantic counts. |
| C1EO-045 | Exact target manual-coverage replacement text remains supplied below, but B001 was forbidden to edit supervisor-owned coverage; terminal state is excluded-with-reason rather than falsely applied. |
| C1EO-046 | Exact constructor/destructor/callback/class/file/layout coverage replacements remain supplied below; B001 made zero coverage edits, so terminal state is excluded-with-reason. |
| C1EO-047 | Target/class/file sections retain B005 facts and explicitly reject its superseded comment-marker/class-emitter/manual-Singleton source shape; commands `13038`, `13041`, and `13045` passed. |
| C1EO-048 | No split, child UID, source file, IDA mutation, third-party import, or wrapper implementation was needed or permitted; excluded-with-reason records that non-applicability. |
| C1EO-049 | UID0000A5 formal class names direct `Singleton<ParcelIconPane>`; UID0001VI records non-virtual PMD `mdisp=0xf8` and EBO overlap; commands `13041` and `13046` passed. |
| C1EO-050 | UID0000A5 and UID0001VI preserve inactive int/one-byte flag/enum ranking and reject pointer/reserved-array alternatives with no-use reasons; commands `13041` and `13046` passed. |
| C1EO-051 | Historical research commands/hashes and B001 callback command `13049` remain preserved; later external current command `13055`, timestamp `2026-07-15T09:27:44-04:00`, and its hash are recorded separately without claiming B001 ran it. |
| C1EO-052 | UID0000A5 managed body contains only plausible declarations/fields/direct bases and `[[CHILDREN]]`; no offset, address, range, or reverse-engineering comments occur inside the block; command `13041` passed. |
| C1EO-053 | UID0001EG formal body contains one `Singleton<ParcelIconPane>()`, zero `g_pParcelIconPane = this`, and no final-int initializer; command `13043` and generated readback `13049` passed. |
| C1EO-054 | UID0001EI formal body contains zero global clear and exactly the queue/unregister actions; generated destructor-body assignment count is zero; command `13042` and readback `13049` passed. |

## Positive Evidence Summary
- The exact wrapper has every canonical scalar-deleting-destructor feature: primary destructor vtable slot, two adjusted entries, ordinary destructor cleanup parity, incoming compiler flags, conditional storage release, and `retn 4`.
- The source-level cleanup is independently anchored by UID0001EI. The missing mechanism is a complete direct-base class declaration with a virtual destructor and `[[CHILDREN]]`, plus removal of the stale manual singleton clear/publication from UID0001EI/UID0001EG source drafts.
- The source-family route is independently anchored by constructor callers, parcel globals, three related classes, adjacent code island, vtables, and current by-file reconstruction path.
- Exact size evidence appears in two independent contexts: MainUiGraph allocates 260 bytes before both constructor calls, and the wrapper's special flag path carries 260 as the object size.
- Live RTTI independently proves the direct empty `Singleton<ParcelIconPane>` base and its `+0xf8` EBO position. This closes a source-shape omission in the failed revision without changing the wrapper conclusion.
- The final dword is not merely “unseen”: bounded constructor/EH/global/vtable/adjusted-receiver/displacement checks exhaust every known outer-object route. Project comparators support an inactive scalar field with no constructor write as a rare but real source shape, while explicit reserved storage without data flow has no strong project-era precedent.
- The immediate same-family UID0001EP wrapper and UID0001EM adjustor strip establish current project policy: compiler artifacts are documented but non-emitting, ownerless, and formally blank.

## IDA MCP Facts
- Function/range facts: `lookup_funcs(0x00546f40)` returned `sub_546F40`, size `0xb9`; `0x00546ff9` is not a function; successor `sub_547000` starts at `0x00547000`.
- Byte facts: first 16 bytes are `55 8b ec 6a ff 68 00 68 5f 00 64 a1 00 00 00 00`; last 16 are `f4 64 89 0d 00 00 00 00 59 5e 8b e5 5d c2 04 00`; exact SHA256 is recorded in C1EO-002.
- CFG facts: primary flow consists of common SEH/vptr/cleanup work, a no-release return, an ordinary free return, a size-bearing special path, and a shared epilogue. IDA also associates external exception-handler fragments; they are compiler support, not extra source children.
- Vtable facts: primary `0x00621bb4 -> 0x00546f40`; secondary `0x00621c00 -> 0x00546ea1`; tertiary `0x00621c30 -> 0x00546eac`. All three tables are written by constructor, ordinary destructor, and scalar wrapper.
- Xref facts: exactly two code xrefs into the target, from `0x00546ea7` and `0x00546eb2`, plus primary vtable data xref `0x00621bb4`. The absolute target VA byte pattern appears only at `0x00621bb4` in the bounded pointer search.
- Callee facts: `sub_469180`, `sub_544D70`, `sub_544580`, `sub_4F4AC0`, and the one-byte compiler/runtime special-path helper at `0x0041b6a0`.
- Singleton facts: six total `g_pParcelIconPane` refs cover MainUiGraph teardown, constructor publish/cleanup, ordinary destructor clear, constructor-EH clear, and scalar-wrapper clear. Target clear is `0x00546fa0`.
- Constructor facts: `sub_4F7D10` allocates `0x104` and calls UID0001EG at `0x004f8491` and `0x004f89f8`; UID0001EG writes known bytes `+0xf8..+0xfa` and child pointer `+0xfc`.
- RTTI/layout facts: the ParcelIconPane hierarchy includes direct `Pane` and `Singleton<ParcelIconPane>` source bases; the Singleton BCD at `0x0064dd74` records `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`, consistent with empty-base overlap at the first derived byte.
- Tail-route facts: the local parcel-island `0x100` hits belong to child `ParcelPane` rectangles or `FlyingParcelPane::m_animationLayer`; no outer `+0x100..+0x103` read/write survives. The six singleton xrefs only publish, test/queue, or clear the whole object, and each vtable is written only by constructor/destructor/wrapper paths.
- Negative IDA facts: no ordinary direct target caller, no modeled function at either padding span, no additional target pointer pattern, no final-dword pointer lifecycle, and no bounded ParcelIconPane access to outer `+0x100..+0x103`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00545e40-0x005470ad` | UID0001EH | mixed parcel executable index | false | none | current `88/91` | metadata/formal preserved; target and padding inventory implemented/validated |
| `0x00545e40-0x0054606a` | UID0001EG | source constructor | true | UID0000A5 | current `91/93` | implemented/validated Singleton initializer, size/route proof, and intentional final-int noninitialization |
| `0x00546070-0x005460e8` | UID0001EI | source ordinary destructor | true | UID0000A5 | current `92/94` | implemented/validated exact unguarded two-action body and implicit Singleton clear |
| `0x005460e8-0x005460f0` | ignored | eight `0xcc` bytes | false | none | n/a | already documented |
| `0x005460f0-0x005461c0` | UID00043J | raw no-route helper | false | none | current | unchanged; not target substitute |
| `0x005461c0-0x0054628d` | UID0001EJ | source secondary callback | true | UID0000A5 | current `90/92` | exact body preserved; complete class declaration route implemented/validated |
| `0x00546e70-0x00546e7b` | UID0002KM | constructor EH clear | false | none | current | unchanged compiler support |
| `0x00546e8b-0x00546ecd` | UID0001EM | six adjustor thunks | false | none | current `86/90` | correct current no-code disposition |
| `0x00546ed0-0x00546f37` | UID0001EN | sibling Flying wrapper | current true | UID000058 | current `86/91` | historical stale-policy comparator only |
| `0x00546f37-0x00546f40` | ignored | nine `0xcc` bytes | false | none | n/a | already documented |
| `0x00546f40-0x00546ff9` | UID0001EO | compiler scalar wrapper | false | none | current `92/94` | implemented/validated corrected boundary evidence, ownerless no-emitter disposition, and blank C++ |
| `0x00546ff9-0x00547000` | ignored | seven `0xcc` bytes | false | none | n/a | exact ignored row implemented/validated |
| `0x00547000-0x005470ad` | UID0001EP | sibling ParcelPane wrapper | false | none | current `86/92` | accepted current-policy comparator |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00621bb4` | data slot -> `0x00546f40` | primary `ParcelIconPane` destructor slot |
| `0x00621c00` | data slot -> `0x00546ea1` | secondary destructor adjustor route |
| `0x00621c30` | data slot -> `0x00546eac` | tertiary destructor adjustor route |
| `0x00546ea7` | thunk jump -> target | normalize `this` by `-0xa0` |
| `0x00546eb2` | thunk jump -> target | normalize `this` by `-0xa4` |
| `0x00546f92` | target -> `sub_469180` | dismiss associated child pane |
| `0x00546f99` | target -> `sub_544D70` | unregister secondary handler |
| `0x00546fa0` | target store -> `g_pParcelIconPane` | unconditional singleton clear |
| `0x00546faa` | target -> `sub_544580` | inherited `Pane` teardown |
| `0x00546fbb` | target -> `sub_4F4AC0` | ordinary storage release branch |
| `0x00546fdd` | target -> `0x0041b6a0` with `0x104` | special compiler/runtime size path |
| `0x004f8491`, `0x004f89f8` | MainUiGraph -> UID0001EG | two outer construction calls after `0x104` allocations |
| UID0001EI | no direct xref | ordinary body selected through compiler destructor machinery |

## Documentation Evidence And IDA Status
- Current target docs preserve all behavior/provenance and now correctly present compiler glue as ownerless, non-reconstructable, non-emitting, blank-C++ evidence.
- UID0001EI now uses the exact two-action source body; its observed singleton clear is documented as implicit direct-base destruction. UID0001EG now uses `Singleton<ParcelIconPane>()` and omits manual publication while preserving all non-Singleton behavior and intentional final-int noninitialization.
- UID0001EJ's complete body is unchanged. UID0000A5 now provides the source-clean declaration and child insertion route, including direct bases and all required fields/declarations.
- UID0001EM, UID0001EP, UID0001YE, UID0002OH, UID0000RX, UID0002W9, UID00043J, and singleton support pages remain unchanged. UID0001EH changed only in accepted target/padding inventory prose. UID0001EN remains an explicitly historical stale-policy comparator.
- Generated output is recorded as a checkpoint timeline, not an indefinite current assertion: historical B001 command `000000012954` (`A680...894C`), supervisor audit command `000000012968` (`8A7B...C4BF`), and later B001 repair-final command `000000013032` (exact reread in Validator Results) all contain class comments only and zero ParcelIconPane source bodies. No generated file was edited.
- Manual coverage files were not edited by B001. The exact supervisor-owned replacement text below remains the durable handoff; application/validation state is external supervisor-owned and is not claimed here.

## Ranked Ownership Analysis

### 1. ParcelIconPane declaration and ordinary destructor in ParcelPane.cpp
- Evidence for: three class-specific vtable views; RTTI-proven direct `Pane` and `Singleton<ParcelIconPane>` bases; constructor and ordinary destructor parity; `g_pParcelIconPane`; owner fields; MainUiGraph constructor calls; parcel-family file route; virtual destructor compiler pattern.
- Evidence against: original header/file split and private names are not symbol-proven.
- Decision: selected source-level ownership. UID0000A5 owns the declaration; UID0001EI owns the handwritten teardown body; UID0000MF owns source placement.

### 2. UID0001EO as a direct ParcelIconPane source method
- Evidence for: the machine body is generated for the class and occupies its destructor vtable slot.
- Evidence against: flags, conditional free, vptr stores, adjusted thunks, base teardown, and ordinary-destructor duplication are compiler ABI signatures, not plausible handwritten source.
- Decision: rejected. Class relationship remains evidence, and current target metadata is ownerless/non-emitting.

### 3. File/global/aggregate/sibling ownership
- Evidence for: UID0000MF groups the code; globals participate in lifecycle; UID0001EH spans the range; sibling classes have adjacent wrappers.
- Evidence against: none is the target receiver or source-level construct. The file is placement, globals are data, the aggregate crosses owners, and sibling vtables point elsewhere.
- Decision: rejected as direct target owner.

### Proposed new file/grouping, if applicable
- Disposition: not applicable; UID0000MF remains the implemented owner at `NexusTK/ui/panels/ParcelPane.cpp`.
- Likely full contents: existing three parcel classes, globals, methods, and support declarations under the current file root.
- Candidate related items rejected: no standalone `ParcelIconPaneScalarDeletingDestructor.cpp`, no new class page, no wrapper child, no helper file.
- Standalone, narrow, or broad source-file inference: existing broad parcel source file is selected; target itself emits nothing.

## Source Placement
- Recommended source placement: `ParcelIconPane` declaration in the source/header surface routed by UID0000MF; constructor, ordinary destructor, and callback definitions through UID0000A5 children in `NexusTK/ui/panels/ParcelPane.cpp`.
- This placement fits the contiguous parcel executable island, shared globals/resources, three class vtable family, current by-file root, and accepted child methods.
- Rejected placements: `Pane.cpp`, `ParcelPane` class ownership, `FlyingParcelPane`, MainUiGraph, global docs, vtable-data source, aggregate source, or a new scalar-wrapper file.
- Remaining placement uncertainty: original flat versus nested header path is not recoverable from the binary, but the project path is already fixed by UID0000MF and does not block reconstruction.

## Range / Split / Padding / Reclassification Analysis
- Exact target range: `[0x00546f40,0x00546ff9)`, 185 bytes, one modeled function.
- Predecessor: UID0001EN ends at `0x00546f37`; `[0x00546f37,0x00546f40)` is nine `0xcc` bytes and already appears in `by-memory/-ignored.md`.
- Successor: `[0x00546ff9,0x00547000)` is seven `0xcc` bytes; UID0001EP starts at `0x00547000`. Add one ignored row for the missing seven-byte span.
- Split decision: no target split and no new UID. SEH fragments associated by IDA are compiler support, not contiguous source children.
- Reclassification applied: target moved from reconstructable/class-emitting comment marker to false/no-owner/no-emitter/blank formal C++; aggregate, adjustor, and vtable inventories retained their dispositions.

## Negative Evidence Summary
- No ordinary direct code caller enters the target.
- No extra absolute VA or RVA pointer route was found beyond the primary vtable slot.
- No function begins at `0x00546ff9`; all seven bytes before UID0001EP are `0xcc`.
- No evidence supports a source-visible flags parameter, explicit wrapper name, explicit vptr assignment, explicit Singleton/Pane teardown call, explicit singleton global assignment/clear in the derived bodies, or explicit delete call.
- No comparison protects the `g_pParcelIconPane` clear; guarded clear is a behavior change.
- No owner-side code access to `+0x100..+0x103` was found across constructor variants, EH, singleton consumers, all vtable routes, adjusted receivers, or bounded displacement searches. The exact original field spelling cannot be claimed; `int m_notificationState` is explicitly a ranked source inference, not a binary fact.
- No initialization/read/write/copy/release evidence supports a pointer at the final dword. No value/switch evidence supports a recovered enum. No high-quality project-era declaration uses an explicit reserved byte array solely to force object size, so `m_reservedTail[4]` is rejected as reverse-engineering-shaped source.
- `g_pParcelIconPane` participation does not make the global page the method owner.
- Adjacent `ParcelPane` and `FlyingParcelPane` wrappers do not own UID0001EO; each has distinct vtables, globals, and cleanup state.
- Historical generated/simroot labels are not current source authority.

## IDA Rename / Type / Comment Recommendations
- Rename recommendation for IDA: none requested; IDA mutation is forbidden. Report/source-facing prose may call `sub_546F40` the `ParcelIconPane` scalar deleting destructor compiler wrapper.
- Source type recommendation: complete `ParcelIconPane : public Pane, public Singleton<ParcelIconPane>`; byte count fields; `ParcelPane *m_parcelPane`; inferred inactive `int m_notificationState`; `const PaneEvent *` callback parameter; virtual destructor.
- Final-member recommendation: `m_notificationState` is the highest-probability human-written feature-local status spelling for the exact-width inactive dword. The report does not claim symbol recovery or invent initialization/use. Rejected alternatives, in order, are weaker pending-flag-plus-padding and enum forms, then contradicted pointer ownership and reverse-engineering placeholder storage.
- Items intentionally unchanged: existing accepted constructor/destructor/callback method names, callback body, `g_pParcelIconPane`, cleanup queue facade, unregister helper, vtable addresses, and adjustor-thunk documentation. Constructor/destructor bodies changed only to replace duplicated Singleton-base lowering with source-level base lifecycle.

## First-Draft C++ Recommendation
- Eligible for draft C++: UID0000A5 complete declaration, UID0001EI ordinary destructor, and UID0001EG constructor. UID0001EO is explicitly ineligible.
- Destination 1, UID0001EO exact managed block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 2, UID0000A5 exact managed block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ParcelIconPane;
class ParcelPane;
struct PaneEvent;

extern ParcelIconPane *g_pParcelIconPane;

class ParcelIconPane : public Pane,
                       public Singleton<ParcelIconPane>
{
public:
    ParcelIconPane();
    virtual ~ParcelIconPane();

protected:
    virtual bool OnParcelUpdate(const PaneEvent *event);

private:
    unsigned char m_totalParcelCount;
    unsigned char m_leftParcelCount;
    unsigned char m_rightParcelCount;
    ParcelPane *m_parcelPane;
    int m_notificationState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 3, UID0001EI exact managed block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelIconPane::~ParcelIconPane()
{
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(m_parcelPane);
    UnregisterEventHandler();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 4, UID0001EG exact managed block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelIconPane::ParcelIconPane()
    : Pane(1),
      Singleton<ParcelIconPane>(),
      m_totalParcelCount(0),
      m_leftParcelCount(0),
      m_rightParcelCount(0),
      m_parcelPane(NULL)
{
    m_parcelPane = new ParcelPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: the class declaration causes the compiler to regenerate the deleting wrapper, three destructor routes, vptr writes, Singleton publication/clear, inherited Pane teardown, and flags/free machinery; the ordinary body preserves only source-authored actions.
- Plausible original source shape: direct Pane/Singleton inheritance, an explicit Singleton base initializer, a virtual destructor declaration, and an ordinary out-of-class destructor that leaves reverse base teardown implicit are standard late-1990s/mid-2000s MSVC source. A named scalar wrapper, manual singleton assignment/clear, or manual vptr/delete code is not.
- Existing UID0001EJ formal C++ remains byte-for-byte unchanged and is reachable through `[[CHILDREN]]`. UID0001EG's formal destination is applied: the historical manual singleton assignment is superseded by the RTTI-proven base initializer.
- Third-party import directive: not applicable; this is NexusTK class source, not a vetted static third-party embed.
- Exact no-code proof: target has only vtable/thunk entry, compiler flags, ordinary cleanup duplication, conditional storage release, adjusted `this` routes, and implicit base mechanics. All human semantics have a separate ordinary source destination.

## Final Recommendation
- C1EO-001 through C1EO-054 are implemented or explicitly excluded/already-present with claim-specific terminal proof; historical, ranked-inference, and negative evidence is preserved.
- UID0001EO is `92/94`, none/false/no-emitter/blank-position/blank-C++, retaining `Nested:0`.
- UID0000A5 has the complete source-clean class block, UID0000MF owner/emitter, `91/92`, and preserved unrelated content.
- UID0001EI is `92/94` with child dismissal/unregister and implicit direct-base Singleton clear; UID0001EG is `91/93` with the direct Singleton initializer and all non-Singleton behavior preserved.
- UID0001EJ is `90/92`, UID0000MF is `91/92`, and UID0001VI is `90/92`; UID0001EH inventory is synchronized at unchanged `88/91`/blank aggregate disposition.
- The exact seven-byte successor padding row is present. UID0001EM, UID0001EN, UID0001EP, UID0001YE, UID0002OH, singleton docs, raw helper, and unrelated parcel children remain verify-only unchanged.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`.
- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank managed body, `Nested:0`.
- Applied evidence: exact bytes/hash/boundaries, CFG/ABI, all three vtable routes, both adjustor thunks, cleanup/flags, ordinary parity, source-generation mechanism, object size, caller/reachability negatives, and generated expectations.
- Applied history: B005's true/class-emitting/comment-marker state and old active-simroot wording are preserved only as superseded provenance with rejection reasons.
- Applied summary: fully researched non-emitting compiler wrapper without redundant rendered metadata.

## Recommended Support Doc Changes
- `by-class/ParcelIconPane.md`: applied `91/92`, source-clean Destination 2, direct Singleton PMD/EBO, exact size, ranked final-dword/no-use proof, destructor routes, source/compiler split, generated history, and preserved unrelated content.
- `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md`: applied `92/94`, exact Destination 3, parity, unguarded dismissal, implicit Singleton clear/Pane teardown, compiler exclusions, class route, and historicalized manual clear.
- `by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md`: applied `91/93`, exact Destination 4, both `0x104` callers, direct Singleton publication evidence, final-dword noninitialization, and rejected manual assignment.
- `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md`: applied `90/92`, preserved exact body, complete class route, and packet-layout confidence caps.
- `by-file/ParcelPane.md`: applied `91/92`, target non-emission, complete direct-base declaration/source order, generated timeline/current expectation, B005 provenance, and unrelated family caveats.
- `by-type/by-struct/ParcelNotificationPaneLayouts.md`: applied `90/92`, preserved support marker, direct Singleton PMD/EBO, exact `0x104`, alignment/pointer/final int, ranked alternatives, and no-access evidence.
- `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`: preserved `88/91`, none/false/no-emitter/blank formal; applied target/padding inventory and history.
- `by-memory/-ignored.md`: applied exact `[0x00546ff9,0x00547000)` seven-`0xcc` row and preserved predecessor row.
- Verify-only unchanged: UID0001EM, UID0001EN, UID0001EP, UID0001YE, UID0002OH, UID0000RX, UID0002W9, UID00043J, singleton helper pages, and unrelated parcel family pages.

## Score And Metadata Recommendation
- UID0001EO historical pre-callback state was `86/90`, class owner/emitter, true, comment marker; current applied state is `92/94`, none, false, no emitter, blank position, blank formal, `Nested:0`.
- Completion rises because all bounds, behavior, ABI, caller, vtable/thunk, flags, ordinary-source relationship, ownership, emitter, formal, source placement, and generated effects are closed. False reconstruction is not a low-completion state.
- Confidence stops at 94 because original compiler option naming and original private final-member spelling are not symbol-proven; neither uncertainty affects wrapper behavior or source eligibility.
- UID0000A5 is now `91/92`: direct bases, class declaration, exact layout, virtual route, extern, and children are complete; access specifier and final-member spelling/meaning remain inferred.
- UID0001EI is now `92/94`: parity and direct-base order close source/compiler teardown and unconditional clear behavior; accepted facade names remain the small inference cap.
- UID0001EG is now `91/93`: two allocation sites, target size path, and direct Singleton publication close outer size/lifecycle; optimized child construction and original private names retain the cap.
- UID0001EJ is now `90/92`: class declaration/child route blocker is closed; `PaneEvent::packetData` remains inferred.
- UID0000MF is now `91/92`: ParcelIconPane integration is complete while unrelated family declaration/private-helper caveats remain.
- UID0001VI is now `90/92`: direct-base geometry and exact outer size/width/no-use state are closed; final-member semantics and broader helper spellings retain the cap.
- UID0001EH `88/91` and verify-only support metadata remain unchanged because target research confirms rather than expands their broader scope.

## Open Questions With Attempted Resolution
- Is the target source-authored? Resolved no through vtable-only route, thunks, flags, conditional free, ordinary parity, and sibling compiler policy.
- Who owns source semantics? Resolved to UID0000A5 declaration plus UID0001EI body, placed by UID0000MF. Target itself has no source owner.
- What do flags mean? Exact masks and machine effects are resolved. Original internal enum names are intentionally not invented because no source-facing flag parameter should exist.
- Does child dismissal need a null guard? Resolved no at the caller; the binary submits the field unconditionally and the helper owns defensive handling.
- Is singleton publication/clearing handwritten or conditional? Resolved as unconditional compiler-inlined `Singleton<ParcelIconPane>` construction/destruction. Source uses the direct base initializer and implicit reverse base teardown; it emits neither manual global assignment nor guarded/unconditional body clear.
- What is object size? Resolved `0x104` by independent constructor and wrapper evidence.
- What is at `+0x100`? Exact width, position, no-use behavior, and necessity for `sizeof==0x104` are resolved after constructor/EH, destructor, callback, singleton-consumer, vtable, adjusted-receiver, displacement, source-history, and project-comparator checks. Ranked source representations are: inactive 32-bit status member first; one-byte pending flag plus padding second; enum third; pointer and explicit reserved storage rejected. Destination 2 uses inferred `int m_notificationState` without initialization or behavior. Original spelling remains a class/layout confidence cap, not a C++ blocker.
- Is `Singleton<ParcelIconPane>` a source base or only a global pattern? Resolved as a direct non-virtual empty source base by live RTTI/PMD and matching EBO comparators.
- Should the wrapper comment marker remain? Resolved no; modern false/no-emitter policy uses a blank formal block, and explanatory evidence belongs in prose.
- Should a new file, split, child, or UID be created? Resolved no; one exact function and existing source destinations cover the complete behavior.
- Unresolved-item count affecting implementation: `0`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- B001 inspected the manual rows affected by every implemented score/path/reconstructability/source-quality change. B001 did not edit these supervisor-owned files.
- `by-memory/-coverage-report.md`, replace the current UID0001EO row with:

```text
    - [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md) 0x00546f40-0x00546ff9 | compiler-generated scalar deleting destructor | ParcelIconPane scalar deleting destructor ABI wrapper : non-reconstructable : 92% : very-strong : Fresh IDA MCP proves the exact 0xb9-byte wrapper, full bytes/CFG, primary and two adjusted vtable routes, unconditional child-dismissal/event-unregister/singleton-clear/base-teardown parity with the ordinary destructor, exact 0x01/0x04 flag branches, 0x104 size path, conditional storage release, no ordinary caller, and seven-byte successor padding; source belongs to the complete Pane plus Singleton<ParcelIconPane> declaration and corrected ordinary destructor, so this page is ownerless, non-emitting, and formally blank.
```

- `by-memory/-coverage-report.md`, replace the UID0001EG row with:

```text
    - [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) 0x00545e40-0x0054606a | constructor | ParcelIconPane constructor : reconstructable : 91% : very-strong : Source-ready ParcelIconPane constructor with exact 0x22a range, two MainUiGraph callers allocating 0x104 bytes, direct Pane and empty Singleton<ParcelIconPane> base initialization, implicit singleton publication instead of a manual global assignment, three count-byte initializers, child ParcelPane allocation at +0xfc, exact class/file route, and an inferred inactive final int whose absent constructor write is preserved rather than fabricated.
```

- `by-memory/-coverage-report.md`, replace the UID0001EI row with:

```text
    - [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md) 0x00546070-0x005460e8 | destructor | ParcelIconPane ordinary destructor : reconstructable : 92% : very-strong : Fresh ordinary/scalar parity proves unguarded child-pane dismissal and event-handler unregister as the derived body, unconditional g_pParcelIconPane clear through implicit Singleton<ParcelIconPane> base destruction, compiler vptr restoration and implicit Pane teardown, exact source ownership in ParcelIconPane, corrected formal destructor C++, and compiler regeneration of the separate ownerless scalar wrapper.
```

- `by-memory/-coverage-report.md`, replace the UID0001EJ row with:

```text
    - [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md) 0x005461c0-0x0054628d | class callback | ParcelIconPane parcel update callback : reconstructable : 90% : strong : Secondary-vtable ParcelIconPane callback with exact packet opcode/offset/count behavior, normalized owner fields, accepted formal body, complete ParcelIconPane declaration, active child-emission route through ParcelPane.cpp, and retained confidence cap for inferred PaneEvent packetData spelling.
```

- `by-class/-coverage-report.md`, replace the UID0000A5 row with:

```text
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md) : reconstructable : 91% : very-strong : Complete ParcelIconPane declaration and ParcelPane.cpp child route with direct Pane and RTTI-proven empty Singleton<ParcelIconPane> bases, implicit singleton publication/clear, virtual destructor, parcel update callback, exact +0xf8/+0xf9/+0xfa count bytes, +0xfc child pointer, natural +0xfb alignment, inferred inactive int at +0x100 preserving sizeof 0x104, exhaustive no-use evidence and ranked rejected alternatives, corrected constructor/destructor plus retained callback source children, compiler-generated ownerless scalar wrapper, three vtable views, and preserved raw-helper negative evidence.
```

- `by-file/-coverage-report.md`, replace the UID0000MF row with:

```text
- [UID:0000MF][ParcelPane](by-file/ParcelPane.md) : reconstructable : 91% : very-strong : Parcel notification UI source root with three-class grouping, complete Pane plus Singleton<ParcelIconPane> declaration and child route, corrected implicit singleton lifecycle in constructor/destructor source, source-authored method separation from compiler-generated scalar wrappers/thunks/EH support, exact globals/vtables/layout/resources and PatchPane boundary, while retaining bounded file-wide caveats for unrelated ParcelPane/FlyingParcelPane declaration and helper API spelling.
```

- `by-type/by-struct/-coverage-report.md`, replace the UID0001VI row with:

```text
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) : reconstructable : 90% : very-strong : Parcel notification family layout support with exact normalized Pane secondary/tertiary views, accepted ParcelPane/FlyingParcelPane fields, and fresh ParcelIconPane sizeof 0x104 proof: direct empty Singleton<ParcelIconPane> base at +0xf8 by RTTI PMD, count bytes at +0xf8..+0xfa, natural alignment at +0xfb, child pointer at +0xfc, and inferred inactive int at +0x100 after exhaustive no-use checks; original private spelling/meaning and broader helper APIs remain the bounded confidence cap.
```

- No manual row is required for `by-memory/-ignored.md`; the ordinary ignored ledger row itself is the exact supervisor-reviewed source text. No validator-owned auto-generated tracker text is supplied.
- Reason B001 did not apply them: all manual `-coverage-report.md` files and lifecycle/tracker state are supervisor-owned and explicitly outside the callback write scope.

## Follow-Up Actions
- Supervisor-owned boundary: report validation/execution/count/path/move/archive and manual coverage application state are external supervisor/validator-owned. This artifact neither asserts nor directs those lifecycle states.
- A-agent actions: none.
- B001 actions remaining: none. The bounded implementation callback, validation/readback, report reconciliation, and lease release are complete; B001 did not execute or move the report.

## Confidence
- Recommendation confidence: `94/100`.
- Score confidence: `96/100` for target `92/94`; `93/100` for support score changes.
- Remaining uncertainty: original compiler option spelling, original access specifier, and original lexical name/semantic role of the inactive final 32-bit member. Its exact width/layout and no-use behavior are fixed; the source-facing `int m_notificationState` spelling is an explicit ranked inference. None changes target behavior, ownership, emitter policy, source placement, or generated-wrapper mechanism.
- Unresolved implementation blockers: `0`.

## Validator Results
- All commands ran from `source-3/project-documentation`; each ordinary destination was leased alone, reread after lease, edited with `apply_patch`, scoped-validated while leased, and immediately released.

| Command | Timestamp | Scoped file / purpose | Exit / ok | Reported side effects |
| --- | --- | --- | --- | --- |
| `000000013038` | `2026-07-15T09:04:07-04:00` | UID0001EO target | `0 / 1` | `autogen_registry_update:4`, `canonical_owner_update:1`, `completion_update:1`, `confidence_update:1`, `projected_stats_update:1`, `reference_index_add:1`, `stats_incremental_noop:1`, `uid_link_update:2`; refresh deferred. |
| `000000013041` | `2026-07-15T09:06:41-04:00` | UID0000A5 class | `0 / 1` | `autogen_registry_update:1`, completion/confidence updates, `projected_stats_update:1`, `reference_index_remove:1`, `stats_incremental_noop:1`, `uid_link_update:1`; refresh deferred. |
| `000000013042` | `2026-07-15T09:08:15-04:00` | UID0001EI ordinary destructor | `0 / 1` | `autogen_registry_update:1`, completion/confidence updates, `projected_stats_update:1`, `stats_incremental_noop:1`; refresh deferred. |
| `000000013043` | `2026-07-15T09:09:16-04:00` | UID0001EG constructor | `0 / 1` | `autogen_registry_update:1`, completion/confidence updates, `projected_stats_update:1`, `stats_incremental_noop:1`; refresh deferred. |
| `000000013044` | `2026-07-15T09:10:05-04:00` | UID0001EJ callback | `0 / 1` | completion/confidence updates, `projected_stats_update:1`, `stats_incremental_noop:1`; refresh deferred. |
| `000000013045` | `2026-07-15T09:11:32-04:00` | UID0000MF file | `0 / 1` | completion/confidence updates, `uid_link_insert:3`, `reference_index_remove:2`, `projected_stats_update:1`, `stats_incremental_noop:1`; refresh deferred. |
| `000000013046` | `2026-07-15T09:12:34-04:00` | UID0001VI layout | `0 / 1` | completion/confidence updates, `projected_stats_update:1`, `stats_incremental_noop:1`; refresh deferred. |
| `000000013047` | `2026-07-15T09:13:27-04:00` | UID0001EH aggregate | `0 / 1` | `projected_stats_update:1`, `stats_incremental_noop:1`; refresh deferred. |
| `000000013048` | `2026-07-15T09:14:16-04:00` | `by-memory/-ignored.md` | `0 / 1` | `missing_ref_uid:277`, `projected_stats_update:1`, `stats_incremental_noop:1`; the missing-reference warnings are pre-existing unrelated rows, with 267 suppressed by normal output. Refresh deferred. |
| `000000013049` | `2026-07-15T09:14:29-04:00` | final UID0001EO `--wait-generated` | `0 / 1` | `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:85`, `autogen_emitter_has_no_code:170`, `autogen_registry_rebuild:1`, `generated_metadata_refresh:281`, `projected_stats_update:1`, `stats_incremental_noop:1`; generated refresh completed. These project-wide notices are validator output, not edits by B001. |

- Historical generated checkpoints remain: command `000000012954`, refresh `2026-07-15T07:56:58-04:00`, SHA256 `A680CC1AE34FEEECFADEAB496B9E19B76D54ABD0B2CCD777D4BD7C6FD400894C`; supervisor command `000000012968`, refresh `2026-07-15T08:13:22-04:00`, SHA256 `8A7B67203028568EB52C204E8EF3F6AF17E7B7931EEBDD09C418CFFAD618C4BF`; B001 repair-final command `000000013032`, refresh `2026-07-15T08:47:22-04:00`, SHA256 `22E999AB0EE747574A4030C560DE13353A5843C969B131313EAC71704D228B22`, 2,607 bytes / 47 lines. Their class-comment-only omission is historical.
- B001 waited snapshot: `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`, command `000000013049`, refresh `2026-07-15T09:14:29-04:00`, SHA256 `0CB4AFA11A417D2F9F2A2731FD64B6DE0885FB0143940E633DCE8EC536C9C372`, 4,771 bytes / 130 lines.
- Final evidence-time external-validator readback at `2026-07-15T09:30:50-04:00`: header command `000000013055`, refresh `2026-07-15T09:27:44-04:00`, source `foreground-generated-refresh`, SHA256 `9D3F51DB3A4D83F0E1F570FE76FE408ED501E39E2F405E730A2B60F0529F9632`, 4,771 bytes / 130 lines. B001 did not run command `13055`; its semantic assertions matched B001 command `13049`.
- Positive generated assertions: one ParcelIconPane forward declaration, one complete class definition, one UID0001EG marker/constructor, one `Singleton<ParcelIconPane>()` initializer, one child allocation, one UID0001EI marker/destructor, one queue call, one unregister call, one UID0001EJ marker/callback, and class/constructor/destructor/callback order before UID0000A6. Surrounding union markers UID000058, UID0000A6, UID0000RX, UID0000RY, UID0002OH, UID0002ZO, UID0001VI, and UID0001YE each remain exactly once.
- Negative generated assertions: zero UID0001EO tokens, Empty Emitter Markers, manual `g_pParcelIconPane = this`, destructor-body global assignments, guarded singleton comparisons, `_vftable`, `operator delete`, `ScalarDeletingDestructor`, explicit `Pane::~Pane`, or explicit `Singleton<ParcelIconPane>::~Singleton`; no duplicate definition.
- Unresolved validator errors: none. Unapplied accepted claims: none; C1EO-045/046/048 are intentionally excluded with exact reasons, not blocked.

## Changed Files
- Same report modified in place: `tools/leaser/Agents/Agent-B001/research/0001EO-ParcelIconPaneScalarDeletingDestructor-source-quality.md`; its external terminal SHA/size/line count is computed after the final mutation because a file cannot stably embed its own SHA.

| Ordinary destination | Pre-callback SHA256 | Current SHA256 | Validator |
| --- | --- | --- | --- |
| `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md` | `F652431EFA14716AB3E208B94742A31ED08B2CA2C65EDAD46EAF623CAD89C98A` | `1DC1ECCF7FE475E206D84991BD95F457621EF66482AE32D0424441885FE6CB37` | `13038`, final `13049` |
| `by-class/ParcelIconPane.md` | `F3978F66407A7E1E6DBE1C06FD36C861549B28E8BDC540B86298CA724D02FAD2` | `C7D84E0A26034C7323BD648C5CEB7C8BCA9E1AD62A6A16FBE61FC5032C60629E` | `13041` |
| `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md` | `CDD46B347BCFD2730FED2C17F8BCD6FBAEDDEC632397D6D3D9DB52CD64266468` | `7FA552F87D01A0A3731B6CC50A59C9D57807328870B9DD8F83E4B71C2CE1CD3F` | `13042` |
| `by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md` | `7C563E51C6CD81E0F3FEADD49339D5866D60552092C813887495066EF7BD1D0E` | `4C2F6FF8E29D2D226C2C6F223FD764852B794E9C697D4637DF38CD58F2343E6E` | `13043` |
| `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md` | `66E7483842D0CC42C27C6B24B37C1A62E95C7827BFEBA605F73F3847035AE8CE` | `B263BA88C2B19E7BA7F4AF17BC518859EC755C343C30EC06A0F5460A04C9F814` | `13044` |
| `by-file/ParcelPane.md` | `49D60863EE5E2833E4DEE0870EED799F537B9C913BAA45EBB22E4C4CB9995FF4` | `8876774BE2A1F6525F032B909321107D5C1F63E2A144DC134279B3C32ADBE415` | `13045` |
| `by-type/by-struct/ParcelNotificationPaneLayouts.md` | `329FA577AE40E3E03898F7720A4E9D3063FF2CB4581FD8FE11EBA0E578743ECD` | `3ECEB3CDC0F41E68DE93F0206A0235D740F56CDF8A79D71C1BD78239E3925D9C` | `13046` |
| `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md` | `1D27A97414D95416EBB8A21675CA76BA57290632EA76C3F92230609A32DDE5F4` | `E7DB5F40C555B3D2308723B3086E39A9EE2DF9A2E8BDB074928F6FE11C7A9D13` | `13047` |
| `by-memory/-ignored.md` | `133C5FFD6688F434F00C8BC09986E25BE8112C487460FF986D1EFE3FA9D51EE5` | `8CA94C61BFC7C2E698C3386A2E8F63BE1EE0E85630305C4F2DB985D63BEC7D74` | B001 `13048`; current hash rebased after a later concurrent mutation, with both accepted padding rows reread intact |

- Verify-only current hashes: UID0001EM `2E2F08F7EC75C952BEA477A950C49AE976E0EA7FE78FE7581BE034D5FA13D248`; UID0001EN `7F4475E95163B4C81EEB488A24B78E680F28AB214577EC899F1B3BEBCD69F5F4`; UID0001EP `AF4637D5CEEB2A10D34EB7718A410E2DF80962C6BB4B50E426FFC493C595CDB4`; UID0001YE `869FF03729B9A4476B8DC52F8E3C22197A16D8E12CB8B828FD5A1C0F23DBDE5C`; UID0002OH `6B4176CF06322B1E286B61D7A172B8FC8EA63ACC61872182B03C1653A6DDFCAB`; UID0000RX `09E1663C06E81E1BC6305B73FE7ED26E705FBB4347704B620C9EADBED9EE9BB3`; UID0002W9 `34A3BD288D85B9F12FAE890BD436989A8DE2EE407CDFB8C833F2ACCAC9D003A2`; UID00043J `8CCC9BF2BFAC0C968489DE3592230C4B62A23114AE5A60B76CD160737D808315`; UID0002KM `CF5423611B20DABEB2F608B690A9C5C17528C99B9A8C5405C5E5444CFDCC9B11`; UID0002KN `9AC52DF63B34CF42865485C0763B6C2DD9677BFA828F4C827BD926C7D8A3A439`.
- Renamed/new ordinary files: none. New UIDs: none. IDA mutation/third-party import: none.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/IDA files manually edited by B001: zero. Generated output was validator-owned and read only.
- At final lease readback `2026-07-15T09:30:50-04:00`, `tools/leaser/Agents/current_leases.md` contained no B001 row; B001 held zero leases. The report listed one unrelated B003 lease, which B001 neither owned nor touched.
- B001 did not run/probe `execute_report`, run lifecycle/probe/count commands, or move/archive the report.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor exact-artifact Gate 1 passed before implementation.
- [x] UID0001EO is `92/94`, none/false/no-emitter/blank position/blank C++, retaining `Nested:0`.
- [x] UID0000A5 has source-clean Destination 2, direct bases, `[[CHILDREN]]`, and `91/92`.
- [x] UID0001EI has Destination 3 at `92/94`, unguarded dismissal/unregister, implicit Singleton clear, and compiler exclusions.
- [x] UID0001EG has Destination 4 at `91/93`, direct Singleton initializer, no manual publication, two-callsite `0x104`, and inactive-final-dword evidence.
- [x] UID0001EJ is `90/92`; exact body preserved and complete class route synchronized.
- [x] UID0000MF is `91/92`; source/compiler placement synchronized and unrelated caveats preserved.
- [x] UID0001VI is `90/92`; route/formal marker preserved and direct-base/size/final-dword/ranking/no-use evidence added.
- [x] UID0001EH metadata/formal block preserved and target/padding inventory synchronized.
- [x] Only `[0x00546ff9,0x00547000)` was added to `by-memory/-ignored.md`; predecessor row remains unchanged.
- [x] Verify-only UID0001EM, UID0001EN, UID0001EP, UID0001YE, UID0002OH, singleton pages, and raw helper remain unchanged.
- [x] C1EO-001 through C1EO-054 are incorporated at report-level detail with legal terminal states and claim-specific proof.
- [x] Exact bytes/hash/CFG/ABI/vtable/thunk/flag/caller/callee/layout evidence is preserved.
- [x] B005/B006/B007/B008 provenance is preserved with accepted facts and explicit supersession reasons.
- [x] Rejected alternatives and negative evidence are preserved, including no direct caller, exhaustive no-access proof, and rejected pointer/enum/reserved-array tail shapes.
- [x] Every C++ payload remains only inside its exact managed destination block; callback block is preserved.
- [x] Split/new UID/new file/IDA mutation/third-party import remain not applicable.
- [x] One scoped validator ran per changed ordinary destination after callback authorization.
- [x] Every one-file lease was released immediately after its scoped validator.
- [x] Final authorized UID0001EO validation ran with `--wait-generated` as B001 command `13049`; current external command `13055` was separately reread without attribution to B001.
- [x] Current generated `ParcelPane.cpp` at command `13055` has one complete class definition, constructor, ordinary destructor, and callback; zero UID0001EO/empty marker/explicit flags-vptr-base-delete-thunk implementation; unrelated union markers remain.
- [x] Exact supervisor-owned manual coverage text is supplied without editing coverage files.
- [x] Report ledger, validator results, changed files, generated proof, current-state wording, and checklist are reconciled.

Implementation callback pass:
- [x] Report SHA `CFE7F66787796B1B90C8CF7430963AD377D7B8266F051E6C4F04D8E2158C08AF` was accepted by the supervisor for implementation.
- [x] All accepted target/support details are incorporated at report-level detail.
- [x] All 54 ledger rows use legal callback states with claim-specific proof: 48 applied, 3 already-present, 3 excluded-with-reason, 0 blocked.
- [x] Metadata/score/owner/emitter/reconstructable/formal changes are applied exactly.
- [x] Historical assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Open questions remain closed with direct Singleton-base proof, ranked final-dword inference, and exact lexical/semantic confidence cap.
- [x] Scoped validator command IDs/timestamps/exits/ok/side effects are recorded.
- [x] Final waited refresh and exact source-count/order/no-wrapper assertions are recorded.
- [x] Current ordinary hashes, external final report hash procedure, changed-file inventory, and zero-lease proof are recorded.
- [x] Remaining unapplied accepted items: none; only supervisor-owned coverage application and non-applicable actions are excluded with reason.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000013080","destination_path":"executed-b-agent-research/B001/0001EO-ParcelIconPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001EO-ParcelIconPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-15T10:00:55-04:00","uid":"0001EO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
