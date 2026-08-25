# 0000HH ArgumentedItemInputDialogs Whole-File Source Quality Research
** TARGET-REPORT-UID:0000HH **
** TARGET-REPORT-ADDITIONAL-UIDS:00000F,00000G,0001BT **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: retain a standalone `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp` and sibling `ArgumentedItemInputDialogs.h`. The unit owns two `DialogPane`-derived classes and four source-authored methods in `[0x0051fc90,0x00520539)`. It does not own the selected-row helpers at `0x0051f450`, `0x0051f510`, or packet helper `0x0051f640`; those remain `ArgumentedMenuMenuItemList` methods in `ArgumentedMenuDialogs.cpp`.
- Final disposition: make UID0000HH a complete reconstructable file route; retain UID0001BT as the exact executable aggregate/index without a monolithic body; create four exact class-owned by-memory method children; populate both class declarations; split the exact input-dialog vtable/RTTI band and literal band from mixed UID00025U; add class-layout/vtable/resource support pages; and replace all current empty output with formal human-written CPP/H or compiler-covered markers.
- Callback disposition: all accepted ordinary-document claims were applied and physically verified. The ten created pages received validator-assigned UIDs 000554 through 00055D, serial scoped validation completed, and a coherent generated reread closed CPP/H output. Manual coverage and IDA mutation remain supervisor-owned.
- Confidence: `very-strong` for runtime behavior, ranges, ownership, class layouts, virtual slot identity, resource literals, and source eligibility; `strong` for the standalone physical source split and inferred original source spellings.

## Supporting Research

- Dated whole-file IDA evidence: read-only canonical IDA MCP session `supervisor_uid0000nj_gate2b_retry_20260816`, exact IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; schema-1 runtime attestation at `2026-08-16T15:51:10.471053Z` returned `ok:true`, empty errors, exact canonical-session binding, and a live stateful worker. The bounded lookups, decompiles, item inspections, frames, xrefs, comments, type checks, and collision checks recorded from that session are dated evidence; fresh supervisor Gate 2B readback is authoritative for current IDA state.
- Gate 1 repair refresh: read-only canonical IDA MCP session `supervisor_uid0000od_gate2b_20260817` was healthy. Bounded `lookup_funcs`, `inspect_items`, `stack_frame`, `get_comments`, `type_inspect`, and decompile reads reconfirmed the four persisted function types, complete frames, independent AR/AP/FR/FP states, destination-name absence, six vtable heads, six COL cells, and three absent named UDTs used by Section 21. No mutation endpoint was called.
- Historical B008 report `0001BT-ArgumentedItemInputDialogs-source-quality.md` was a deliberately limited medium-model callback. Its exact range, caller, vtable, resource, and aggregate-routing facts remain useful. Its deferred child creation, blank formal class/source output, unresolved fields/signatures, and source-split caveat are superseded by this exhaustive xHigh whole-file pass.
- Historical B001 tail-split report `0001BS-argumented-menu-dialogs-tail-split.md` remains authoritative for the ownership correction: `0x0051f450`, `0x0051f510`, and `0x0051f640` consume `ArgumentedMenuMenuItemList` state and belong to UID00000I/UID0000HI. Their no-direct-start-ref state does not transfer them into UID0000HH and does not justify dropping their source behavior.
- Latest pre-callback generated snapshot observed by B010 was validator command `000000025350`, refresh `2026-08-17T09:52:06-04:00`, CPP SHA256 `C8ABF65D702A3A584D4AF704415587405A5DC57351EFA83B28CCC0189E336269`, 1,096 bytes, 17 physical lines. It contained UID0001BT's aggregate route comment followed by `[[No Children Attached]]`, two class empty-emitter markers, no method bodies, and no sibling H. This is a dated pre-callback research snapshot only; command `000000025458` below is the dated callback receipt, and fresh supervisor Gate 2A/final reread remains authoritative for current generated state.
- Callback-time coherent generated refresh command `000000025458`, `2026-08-17T11:48:37-04:00`, completed after every serial scoped validator. Physical reread found complete target, ArgumentedMenu, and StaticText CPP/H output with zero empty/no-children markers, placeholders, stubs, TODOs, raw ABI arrays, duplicate helper/destructor definitions, or generated labels. Module headers truthfully retain their last content-producing command IDs: target CPP/H `000000025456`, ArgumentedMenu CPP/H `000000025457`, and StaticText CPP/H `000000025458`. These are dated callback receipts; dynamic supervisor Gate 2A/final reread remains authoritative for later shared state.
- Wave2/Wave3 material was encountered only through stale legacy trace text and was ignored. Current documentation, executable facts, and live MCP evidence control this report.
- Lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the report path and validator-owned history being acted on; ordinary report prose does not assert a current lifecycle phase.

## Target

- Target UID: `0000HH`.
- Additional target UIDs: `0001BT`, `00000F`, `00000G`.
- Declared-target inventory:
  - UID0000HH `by-file/ArgumentedItemInputDialogs.md`: complete inferred compilation-unit owner.
  - UID0001BT `by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md`: exact executable aggregate and method-child index.
  - UID00000G `by-class/ArgumentedItemQuantityInputDialogPane.md`: quantity-input class owner.
  - UID00000F `by-class/ArgumentedItemConfirmInputDialogPane.md`: price-confirm class owner.
- Target path: `by-file/ArgumentedItemInputDialogs.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `by-file / Not-Covered Files - Not Reconstructable`, evidence-time `86/89`, blank file-level reconstructable metadata, zero reports.
- Post-callback report classification: `47` ordinary claims are applied and checked, `17` supervisor-owned claims remain proposed and unchecked, and exactly one terminal supervisor-execute control marker is present. Execution/archive occurrence remains supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.
- Callback-applied scores and parent state: UID0000HH `93/94`, owner `FILE`; UID0001BT `92/94`, owner/emitter UID0000HH; UID00000F and UID00000G each `92/94`, owner/emitter UID0000HH.
- Inferred compilation-unit boundary: source-authored `.text` is `[0x0051fc90,0x00520539)`, preceded by three `0xcc` alignment bytes after UID0001BS and followed by seven `0xcc` bytes before `ObjectImageControlPane` at `0x00520540`. Compiler-generated input-dialog vtable/COL storage is `[0x0061f584,0x0061f6bc)`. Source literal storage is `[0x0061f99c,0x0061fa3c)`. External list-context methods, base UI methods, shared globals/resources, and folded destructor wrappers are dependencies, not file-owned source bodies.

## Current Target State

- Callback-applied metadata: UID0000HH is `93/94`, retains `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CANONICAL_OWNER:FILE`, and is a complete reconstructable standalone file route. UID0001BT is the `92/94` exact aggregate/index at position 10; UID00000G and UID00000F are `92/94` class routes.
- Callback-applied owner/emitter state: the four exact methods emit through class-owned by-memory children UID000554, UID000555, UID000557, and UID000558. Layouts UID000556/UID000559, vtable data/type UID00055A/UID00055C, literal UID00055B, and resource UID00055D preserve complete support ownership without duplicate handwritten bodies.
- Callback-applied C++/emitter state: UID0001BT emits only its no-duplicate aggregate route plus children. UID00000G/F provide complete formal declarations and class routes; exact methods provide formal CPP. Layout and vtable evidence pages emit explicit no-standalone-source/compiler-generated comments instead of empty markers. Their H channels remain intentionally blank because declarations are owned by the class pages.
- Resolved blockers retained by the callback:
  - standalone versus folded: standalone selected, with the folded alternative retained only as historical uncertainty;
  - weak `0x0051f450`/`0x0051f510` reachability: resolved as a confidence note on UID00000I methods, not UID0000HH membership or source eligibility;
  - generated names: four collision-free source names selected;
  - method signatures: constructors plus exact primary `OnControlCommand(int,int)` override selected;
  - class layouts: exact `0x274` and `0x27c` sizes and tail fields resolved;
  - destructor handling: implicit source destructors with no owned-pointer cleanup; six compiler wrappers/thunks remain non-emitting;
  - vtable/RTTI ownership: six views and two seven-base RTTI graphs resolved to the two class declarations;
  - source/header route: exact CPP/H fragments and support dependency contract supplied in Section 22.
- Related docs checked and callback-reconciled where authorized: UID0000HH, UID0001BT, UID00000F/G, UID0000HI, UID00000H/I, UID0000TY, UID00025U, UID0001Y5, UID000320, UID0003VF/VH/VI/VJ/VL, UID0003Q5, UID00033Y, UID0000O8, UID0000E3, UID000222, DialogPane/class/file/layout/vtables, BackPane/global, LanguageMan/global, shared dialog resource pages, historical B001/B008 reports, and physically reread generated ArgumentedItemInputDialogs, ArgumentedMenuDialogs, and StaticTextControlPane CPP/H.
- Current complete inventory: 4 source-authored functions; 2 implicit derived destructors; 6 shared compiler destructor artifacts; 5 local alignment spans; 2 class types; 2 exact tail layouts; 6 vtable views; 6 COL cells; 2 CHDs and 2 complete seven-base RTTI graphs; 4 owned UTF-16 literals; 5 shared/resource dependencies; 3 external list-context methods plus one copy constructor; no file-owned global/static object.
- Historical generated baseline command `000000025350` had incomplete CPP and no H. Callback refresh `000000025458` physically verified H declarations in quantity-then-confirm order and CPP definitions in quantity constructor/action then confirm constructor/action order, followed only by explicit compiler/layout coverage comments. The six reread artifacts contain no raw arrays, destructor wrappers, duplicate list helpers, placeholders, TODOs, stubs, empty markers, or generated labels.
- Callback state: 32 ordinary by-* destinations were created or updated and validated. Supervisor-owned IDA, manual coverage, Gate 2/lifecycle occurrence, and any later shared generated state are authoritative only from the supervisor's fresh readback and validator-owned metadata.

## Executive Recommendation

- Direct owner: UID0000HH for the standalone `ArgumentedItemInputDialogs.cpp/.h`; UID00000G owns quantity methods and layout; UID00000F owns confirm methods and layout.
- Exact callback-created method children:
  - UID000554 `by-memory/0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor.md`, owner/emitter UID00000G, position 10.
  - UID000555 `by-memory/0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand.md`, owner/emitter UID00000G, position 20.
  - UID000557 `by-memory/0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor.md`, owner/emitter UID00000F, position 10.
  - UID000558 `by-memory/0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand.md`, owner/emitter UID00000F, position 20.
- Exact callback-created data/type support: UID00055A vtable data, UID00055C vtable type, UID000556/UID000559 class layouts, UID00055B source-literal band, and UID00055D resource index. UIDs are validator-assigned and propagated through all authorized parents/support pages.
- Retain UID0001BT as a reconstructable exact aggregate/index with a no-duplicate compiler/source-routing marker, not as a broad function body and not as the method parent.
- Keep UID00025U, UID0003Q5, the shared adjustor strip, and UID00033Y non-emitting. Update them only to record the exact input-dialog child dispositions and shared wrapper consumers.
- The report finds no unresolved research blocker to the callback-applied formal CPP/H. Original identifier spellings are lost, but descriptive human names remain strongly constrained by class RTTI, virtual slots, field use, sibling dialog conventions, and project style. Manual coverage and IDA work remain supervisor-owned.

## Supervisor Active Recheck

- Callback recheck: all ten assigned new pages exist with validator-assigned UIDs `000554` through `00055D`, and all `32` ordinary target/support destinations are callback-complete.
- Callback generated recheck: command `000000025458` completed the coherent refresh; B010 physically reread the six affected generated CPP/H artifacts and verified the complete declaration/definition inventory with no empty/no-children markers, placeholders, stubs, TODOs, generated labels, duplicate helper/destructor definitions, or raw ABI arrays.
- Every source-bearing item has a callback-applied, validator-checked disposition. External helper bodies at `0x0051f450`, `0x0051f510`, `0x0051f640`, and copy constructor `0x0051f290` remain in UID0000HI while their required declarations/access contracts are callback-applied.
- Remaining supervisor work is limited to fresh Gate 2A generated/documentation reread, Gate 2B IDA application/readback, the ten exact manual-coverage payloads, and lifecycle handling. Their occurrence is externally authoritative and is not asserted by ordinary report prose.

## Inference Research Guidance Check

- `by-structure.md` requires exact half-open children, class-owned method emitters, compiler-data markers rather than raw arrays, and no broad aggregate body. The recommendation follows those rules.
- Existing assumptions treated as uncertain and rechecked: folded source ownership; `OnAction` versus `OnControlCommand`; copied-list field semantics; implicit destructor cleanup; no-xref helper liveness; vtable successor boundary; and the B008 statement that exact signatures/fields remained unresolved.
- Direct IDA facts are kept separate from inference: ranges, slot values, stores, frames, fields, strings, and xrefs are facts; standalone physical file split, source identifier spellings, private/friend access, and include spellings are strong inference.
- Human-source requirement: generated labels such as `sub_51FC90`, `a1`, `ArgList`, `Buffer`, `dword_69B36C`, or raw vtable arrays are rejected from formal source. Descriptive names are used consistently with current DialogPane/ListPane documentation.
- Wave2/Wave3 references were ignored as stale, per current project policy.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and attempted resolution | Best supported result |
| --- | --- | --- |
| Standalone versus folded file | `.text` begins on a 16-byte boundary after the exact UID0001BS end; vtable family begins immediately after UID000320's explicit successor boundary; two self-contained derived classes and four methods form a complete unit; current source tree already reserves the file. | Standalone `ArgumentedItemInputDialogs.cpp/.h` is the highest-probability source shape. Folding into `ArgumentedMenuDialogs.cpp` is retained only as rejected history. |
| `0x0051f450`/`0x0051f510` zero xrefs | Live xrefs are still zero; old PE VA/RVA/rel32 scans were also zero. Bodies read list selection/row fields, call input constructors, sit among list methods, and parallel the inline dialog path. | Retained source-shaped UID00000I private helpers. No-xref is linker/reachability evidence, not permission to omit or reown them. |
| Four `sub_*` names | Decorated class vtables and primary slot `+0x48`, constructor stores, call sites, and DialogPane contract constrain roles. Fresh `lookup_funcs` found all four proposed names free. | Use class-qualified constructor and `OnControlCommand` names; no compiler label survives source. |
| Handler signature | Current IDA userpurge signatures are decompiler artifacts. Both target cells occupy DialogPane primary slot `+0x48`; current DialogPane H defines `virtual void OnControlCommand(int controlIndex, int notifyCode)`. | Exact source signature `virtual void OnControlCommand(int controlIndex, int notifyCode)`; `notifyCode` intentionally ignored. |
| Tail member types | Allocation sizes, dword stores, copy constructor call, packet helper arguments, and action reads constrain width and order. | Quantity: pointer `+0x26c`, `unsigned int m_argumentId +0x270`. Confirm: pointer `+0x26c`, unsigned dwords `m_maxQuantity +0x270`, `m_expectedPrice +0x274`, `m_argumentId +0x278`. |
| Ownership of copied list pointer | Constructors allocate `0x15c` and call UID0003VF. Shared scalar wrappers restore derived vtables and tear down only DialogPane/base state; no delete of `+0x26c` occurs. | Preserve raw pointer and implicit destructor behavior exactly. Do not invent `delete`, smart pointers, ownership annotations, or a source-authored destructor body. |
| Quantity validation | Parsed dword is initialized to zero; binary uses unsigned `> 100`, then zero check; control index 1 always closes after alert/send or null-context path. | Initialize `int quantity = 0`; cast for unsigned limit; show exact alerts; close for every confirm-control path. Negative values follow unsigned-over-100 branch. |
| Confirm validation | Parsed value initialized zero and compared bitwise to expected-price dword. Mismatch constructs alert and returns without closing; match sends quantity one or opens quantity dialog, then closes. | Formal code preserves mismatch-open and match-close behavior exactly. |
| Vtables/RTTI | Six decorated heads, six COL cells, constructor stores, exact 23/11/2 slots, two seven-base RTTI graphs, +0xa0/+0xa4 PMDs, ObjectImage successor. | Compiler-generated from two class declarations. Split exact child; never emit raw tables. |
| Destructor wrapper sharing | Quantity slots use shared `0x47eaf0`, `0x47e8d9`, `0x47e8e4`; confirm slots use `0x4b0a20`, `0x4b08e3`, `0x4b08ee`, also documented under other classes. | Compiler COMDAT/folding, not cross-class source ownership. Record consumers; no wrapper C++. |
| Resource ownership | Four unique literals are contiguous at `[0x61f99c,0x61fa3c)`; DLGEXC3/PAL01, `%d`, `OK`, localized id 246, BackPane, LanguageMan, and main UI layer are shared dependencies. | Unique literals belong to UID0000HH source methods; shared resources/globals stay with current owners and are included/referenced, not duplicated. |
| List helper access | Dialog methods call UID0003VL on copied list context and constructors call UID0003VF. Existing class H is blank. | Apply the exact copy-constructor, packet/helper, field, and friend declarations from Section 22 to UID00000I's `ArgumentedMenuDialogs.h` route. Private methods plus the two tightly coupled input-class friends best match encapsulation while preserving calls. |
| Original spelling and style | No original PDB/source symbols survive for four methods/fields. Project declarations use PascalCase methods, `m_` fields, `g_` globals, C++03 `NULL`, and explicit virtual syntax. | Apply one consistent period-compatible style. Original-proof facts outrank stylistic consistency if later recovered. |

Rejected alternatives:

- `OnAction(int,int)` is rejected as stale because current DialogPane primary `+0x48` is `OnControlCommand(int,int)` and both vtable cells occupy that exact slot.
- A monolithic UID0001BT body is rejected because it would conflate four class methods and compiler/data ranges.
- Owning the three list-context helpers in UID0000HH is rejected because their receiver fields, row access, neighboring methods, and packet context belong to UID00000I.
- Treating the copied pointer as owning is rejected by destructor bytes.
- Hand-emitting vtables, RTTI, scalar deleting wrappers, or adjustor thunks is rejected as compiler output.
- Leaving names as `sub_*`, `_DWORD`, `ArgList`, or `Buffer` is rejected because strong semantic evidence supports human source names.

## Evidence Standards Used

- Strongest evidence: exact function boundaries, decompiled branches, call targets, data slots, constructor vptr stores, RTTI/COL graphs, object sizes, stack frames, literal values, and direct xrefs from current canonical IDA.
- Corroboration: current by-* ownership/layout/resource pages, exact sibling DialogPane and Employee quantity-dialog patterns, historical B001/B008 research, generated CPP snapshot, and manual coverage rows.
- Negative evidence: no direct starts for `0x51f450/0x51f510`, no separate function at `0x520046`, absent derived/list UDTs, absent comments/types on target tables, no generated H, no target global, no owned-pointer destructor cleanup, and exact successor boundaries.
- Evidence ladder: binary facts decide behavior/range/layout; source placement and names use bounded inference only after binary/docs agree. Tool limits do not block the result because every behavior and layout claim has independent slot/caller/field evidence.
- Confidence remains below original-source proof only for physical file naming, access specifiers, and exact identifier spellings, not runtime reconstruction.

## Evidence Checked

- IDA MCP: `idb_list`, schema-1 `runtime_attestation`, `lookup_funcs`, `inspect_items`, `decompile`, `stack_frame`, `xrefs_to`, `get_comments`, `type_inspect`, and collision lookups for all four proposed names.
- Exact current functions: `sub_51FC90` size `0x2dc`; `sub_51FF70` size `0x154`; `sub_5200D0` size `0x2ee`; `sub_5203C0` size `0x179`; successor `sub_520540` size `0x75`.
- Exact fresh IDA presentation/types/frames: all four current persisted item types and every stack row are reproduced in Sections 13, 14, and 21. `DialogPane` exists at size `0x26c`; all three target/support UDTs are absent. The fresh canonical Gate 2B precheck corrected the dated stale constructor `__int16 *` return/receiver presentation to exact persisted `DialogPane *` return/receiver types for F01 and F03; the confirm action's EBX/EDI presentation remains `unsigned int`/`__int16 *`.
- Xrefs: quantity constructor callers `0x51f570`, `0x5204ec`; quantity action table cell `0x61f5d0`; confirm constructor callers `0x51f22a`, `0x51f4de`; confirm action cell `0x61f66c`; packet helper calls `0x51f504`, `0x51f58d`, `0x52008e`, `0x520501`; zero direct xrefs to `0x51f450` and `0x51f510`.
- Vtable/COL state: all six table heads and six COL cells inspected; exact names/types/comments recorded. Constructor stores and slot values were cross-checked against UID0001BT/UID00025U and live decompile.
- Docs/reports: all declared target pages, every named support page in Sections 14/25, manual coverage rows, the dated pre-callback command-25350 generated CPP and then-absent target/ArgumentedMenuDialogs/StaticTextControlPane H outputs, current ButtonControlPane/EPFImageControlPane/TextEditControlPane/DialogPane/AlertPanes/MainUiGraph/BackPane/LanguageMan headers, executed B001/B008 reports, and relevant DialogPane/Employee/NumberInput precedent. The absent H/page observations are pre-callback report-only history; callback validators and command `000000025458` receipts are recorded in Section 31.
- Negative searches: matching reports/goals/leases; alternative owners; separate functions at interior addresses; raw-pointer cleanup; target globals/statics; separate resource owner; duplicate input-dialog vtable page; existing exact method/layout/resource pages; executable/report scripts.
- Failed/unavailable checks: none. MCP remained responsive during the dated research reads. The report-only phase used no validator; the accepted callback's scoped validators and coherent command `000000025458` are recorded in Section 31. IDA mutation and lifecycle operations were not used by B010.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0HH-001 | 0000HH | Incorporate the exhaustive whole-file inventory and all source/compiler/support dispositions. | very-strong | Current IDA, docs, reports, generated audit. | UID0000HH inventory/evidence | incorporate | applied |
| C0HH-002 | 0000HH | Retain standalone NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp and create its sibling H. | strong | Text/vtable boundaries, two-class unit, source-tree route. | UID0000HH ownership/source placement | incorporate | applied |
| C0HH-003 | 0000HH | Raise file scores to 93/94 while retaining path and FILE owner. | strong | All blockers investigated; original spellings remain inferred. | UID0000HH metadata | incorporate | applied |
| C0HH-004 | 0000HH | Define exact generated CPP/H order and eliminate every historical/callback empty or no-children marker in the affected output. | very-strong | Dated command-25350 baseline plus command-25458 callback physical reread. | UID0000HH generated criteria | incorporate | applied |
| C0HH-005 | 0001BT | Retain exact aggregate range/owner/emitter, set position 10, score 92/94, and emit no-duplicate route marker. | very-strong | Four exact methods and boundaries. | UID0001BT metadata/CPP | incorporate | applied |
| C0HH-006 | 00000G | Create exact quantity constructor child at [0x51fc90,0x51ff6c), owner/emitter UID00000G position 10. | very-strong | Function, callers, vptr stores, behavior. | new by-memory constructor page | incorporate | applied |
| C0HH-007 | 00000G | Create exact quantity OnControlCommand child at [0x51ff70,0x5200c4), owner/emitter UID00000G position 20. | very-strong | Primary +0x48 cell and full branch behavior. | new by-memory action page | incorporate | applied |
| C0HH-008 | 00000F | Create exact confirm constructor child at [0x5200d0,0x5203be), owner/emitter UID00000F position 10. | very-strong | Function, callers, vptr stores, behavior. | new by-memory constructor page | incorporate | applied |
| C0HH-009 | 00000F | Create exact confirm OnControlCommand child at [0x5203c0,0x520539), owner/emitter UID00000F position 20. | very-strong | Primary +0x48 cell and full branch behavior. | new by-memory action page | incorporate | applied |
| C0HH-010 | 00000G | Populate quantity class declaration, class route marker, exact fields/layout/method inventory, and score 92/94. | very-strong | 0x274 allocation, DialogPane size, vtables, fields. | UID00000G CPP/H/layout | incorporate | applied |
| C0HH-011 | 00000F | Populate confirm class declaration, class route marker, exact fields/layout/method inventory, and score 92/94. | very-strong | 0x27c allocation, DialogPane size, vtables, fields. | UID00000F CPP/H/layout | incorporate | applied |
| C0HH-012 | 00000G | Use pointer +0x26c and unsigned argument id +0x270; no source-authored destructor. | very-strong | Stores/reads and shared destructor wrapper. | UID00000G fields/destructor | incorporate | applied |
| C0HH-013 | 00000F | Use pointer +0x26c plus max quantity/expected price/argument id at +0x270/+0x274/+0x278; no source destructor. | very-strong | Stores/reads and shared destructor wrapper. | UID00000F fields/destructor | incorporate | applied |
| C0HH-014 | 00000G | Create a source-local quantity layout page with exact size 0x274 and inherited three-view offsets. | very-strong | Type size and constructor/RTTI facts. | new by-type layout page | incorporate | applied |
| C0HH-015 | 00000F | Create a source-local confirm layout page with exact size 0x27c and inherited three-view offsets. | very-strong | Type size and constructor/RTTI facts. | new by-type layout page | incorporate | applied |
| C0HH-016 | 0000HH | Create exact [0x61f584,0x61f6bc) vtable-data child with six tables/COLs and compiler marker. | very-strong | Exact data items, slots, stores, successor. | new by-memory vtable page | incorporate | applied |
| C0HH-017 | 0000HH | Create input-dialog vtable type page with complete six-view slot/RTTI contract and no raw arrays. | very-strong | 23/11/2 tables and two seven-base RTTI graphs. | new by-type vtable page | incorporate | applied |
| C0HH-018 | 0000HH | Create exact [0x61f99c,0x61fa3c) source-literal page covered by formal method literals. | very-strong | Four contiguous UTF-16 literals and successor. | new by-memory literal page | incorporate | applied |
| C0HH-019 | 0000HH | Create argumented-item-input resource index for four owned literals and shared resource dependencies. | strong | Literal xrefs and existing resource owners. | new by-resource page | incorporate | applied |
| C0HH-020 | 00025U | Add exact vtable/literal children and retain mixed aggregate non-emitting at 86/92. | very-strong | Existing broad range crosses owners. | UID00025U split inventory | incorporate | applied |
| C0HH-021 | 0000HH | Use current DialogPane APIs and exact OnControlCommand override, not stale OnAction wrappers. | very-strong | Current DialogPane H and vtable slot +0x48. | UID0000HH dependencies/source | reject-stale | applied |
| C0HH-022 | 00000I | Add copy-constructor/packet-helper declarations and friend access required by input source. | strong | Exact calls and class-private coupling. | UID00000I formal H/support | incorporate | applied |
| C0HH-023 | 0000HI | Document complete ArgumentedMenuDialogs.h dependency and retain helper bodies in ArgumentedMenuDialogs.cpp. | strong | UID00000I owner route and input include dependency. | UID0000HI source/header route | incorporate | applied |
| C0HH-024 | 0003VF | Promote exact copy-constructor declaration eligibility and record the two input constructor callers. | very-strong | Current callers and copy behavior. | UID0003VF C++/evidence | incorporate | applied |
| C0HH-025 | 0003VI | Replace deferred/no-name/no-xref blocker with retained private OpenBuyConfirmDialog inference. | strong | Selected row fields, constructor call, source adjacency. | UID0003VI behavior/CPP | reject-stale | applied |
| C0HH-026 | 0003VJ | Replace deferred/no-name/no-xref blocker with retained private OpenQuantityDialogOrSendSingle inference. | strong | Quantity gate, localization, ctor/send calls. | UID0003VJ behavior/CPP | reject-stale | applied |
| C0HH-027 | 0003VL | Promote SendArgumentedItemQuantityPacket signature and exact input-dialog caller contract. | very-strong | Four calls, packet fields, exact widths. | UID0003VL CPP/H/evidence | incorporate | applied |
| C0HH-028 | 0000TY | Preserve non-emitting helper index and record resolved source names/UID0000HI ownership. | very-strong | B001 split plus current reanalysis. | UID0000TY inventory | incorporate | applied |
| C0HH-029 | 0003Q5 | Record quantity primary-vtable use of shared 0x47eaf0 wrapper; retain non-emitting. | very-strong | Vtable slot and 0x274 object size. | UID0003Q5 consumers/no-code | incorporate | applied |
| C0HH-030 | 0000HH | Update shared adjustor strip for quantity cells 0x61f5e8/0x61f618 and implicit destructor route. | very-strong | 0x47e8d9/0x47e8e4 slots. | DialogAndAlertDestructorAdjustorThunks | incorporate | applied |
| C0HH-031 | 00033Y | Correct active wrapper ownership text: 0x4b0a20/08e3/08ee also serve confirm class by folding. | very-strong | Confirm vtable cells and shared code. | UID00033Y consumers/no-code | reject-stale | applied |
| C0HH-032 | 000320 | Preserve 0x61f588 as exact successor boundary into UID0000HH and link new vtable child. | very-strong | Existing page and live items. | UID000320 boundary | incorporate | applied |
| C0HH-033 | 0000HH | Preserve exact five padding spans and ObjectImage successor exclusion. | original-proof | Boundary bytes and next function/table. | UID0000HH range section | incorporate | applied |
| C0HH-034 | 0000HH | Preserve four unique source literals and shared DLGEXC3/PAL01/%d/OK/localization dependencies without duplication. | very-strong | Exact string addresses/xrefs. | UID0000HH resource inventory | incorporate | applied |
| C0HH-035 | 0000HH | Preserve quantity unsigned-limit/zero semantics and always-close control-1 behavior. | original-proof | Full current decompile. | quantity action child CPP | incorporate | applied |
| C0HH-036 | 0000HH | Preserve confirm mismatch-open, match send-or-quantity, and match-close behavior. | original-proof | Full current decompile. | confirm action child CPP | incorporate | applied |
| C0HH-037 | 0000HH | Preserve implicit pointer leak/no-cleanup behavior rather than inventing ownership. | original-proof | Shared wrappers never read/delete +0x26c. | both classes history/source | incorporate | applied |
| C0HH-038 | 0000HH | Close formal CPP/H dependencies through existing ButtonControlPane.h, corrected pointer/full-constructor calls, a complete ArgumentedMenuDialogs.h list-context declaration, and a complete StaticTextControlPane.h declaration/route; remove duplicate local row-struct emission. | strong | Command-25458 physical CPP/H readback, formal owner docs, live allocation sizes, and accepted control APIs. | UID0000HH/00000F/00000G; UID0000HI/00000H/00000I/0003VH; UID0000O8/0000E3/000222 | incorporate | applied |
| C0HH-039 | 0000HH | Historicalize B008's limited child/formal-code deferral while retaining its binary facts. | very-strong | Historical report versus current pass. | UID0000HH/0001BT history | reject-stale | applied |
| C0HH-040 | 0000HH | Preserve B001 helper ownership and no-xref evidence without treating it as a target blocker. | very-strong | Historical report and live xrefs. | UID0000HH/00000I history | incorporate | applied |
| C0HH-041 | 0000HH | Rename 0x51fc90 to ArgumentedItemQuantityInputDialogPane_Constructor. | very-strong | RTTI/vptr/callers; destination free. | IDA Gate 2B A0HH-01 | incorporate | proposed |
| C0HH-042 | 0000HH | Add exact regular function comment at 0x51fc90. | very-strong | Constructor behavior/layout. | IDA Gate 2B A0HH-02 | incorporate | proposed |
| C0HH-043 | 0000HH | Rename 0x51ff70 to ArgumentedItemQuantityInputDialogPane_OnControlCommand. | very-strong | Primary +0x48 cell; destination free. | IDA Gate 2B A0HH-03 | incorporate | proposed |
| C0HH-044 | 0000HH | Add exact regular function comment at 0x51ff70. | very-strong | Validation/send/close behavior. | IDA Gate 2B A0HH-04 | incorporate | proposed |
| C0HH-045 | 0000HH | Rename 0x5200d0 to ArgumentedItemConfirmInputDialogPane_Constructor. | very-strong | RTTI/vptr/callers; destination free. | IDA Gate 2B A0HH-05 | incorporate | proposed |
| C0HH-046 | 0000HH | Add exact regular function comment at 0x5200d0. | very-strong | Constructor behavior/layout. | IDA Gate 2B A0HH-06 | incorporate | proposed |
| C0HH-047 | 0000HH | Rename 0x5203c0 to ArgumentedItemConfirmInputDialogPane_OnControlCommand. | very-strong | Primary +0x48 cell; destination free. | IDA Gate 2B A0HH-07 | incorporate | proposed |
| C0HH-048 | 0000HH | Add exact regular function comment at 0x5203c0. | very-strong | Price/quantity/send/close behavior. | IDA Gate 2B A0HH-08 | incorporate | proposed |
| C0HH-049 | 0000HH | Protect six decorated vtable names/types/comments and exact table ranges unchanged. | original-proof | Current inspect/comments/slot inventory. | IDA Gate 2B A0HH-09..14 | not-applicable | proposed |
| C0HH-050 | 0000HH | Protect six COL pointer cells as name absent/type absent/comment absent. | original-proof | Current inspect/comments and RTTI values. | IDA Gate 2B A0HH-15..20 | not-applicable | proposed |
| C0HH-051 | 0000HH | Do not install partial derived/list UDTs; preserve absence until complete declarations can be applied atomically. | very-strong | Current type_inspect and source dependency closure. | IDA Gate 2B A0HH-21..23 | not-applicable | proposed |
| C0HH-052 | 0000HH | Replace manual by-file coverage row with exact 93% whole-file description. | strong | Current row 82% and complete report. | by-file/-coverage-report.md | incorporate | proposed |
| C0HH-053 | 0001BT | Replace manual by-memory coverage row with exact 92% split/child description. | strong | Current row 84% and complete split. | by-memory/-coverage-report.md | incorporate | proposed |
| C0HH-054 | 00000G | Replace manual class coverage row with exact 92% source/layout description. | strong | Current row 82% and formal class/method route. | by-class/-coverage-report.md | incorporate | proposed |
| C0HH-055 | 00000F | Replace manual class coverage row with exact 92% source/layout description. | strong | Current row 82% and formal class/method route. | by-class/-coverage-report.md | incorporate | proposed |
| C0HH-056 | 0000HH | Apply the ten literal manual coverage payloads in Section 28 using validator-assigned UIDs 000554 through 00055D while preserving each exact path/title/score/reconstructability/owner/emitter description and placement. | strong | Ten complete assigned-UID payloads and placement contexts in this report. | relevant -coverage-report.md files | incorporate | proposed |
| C0HH-057 | 0000HH | Run scoped validation for every changed ordinary by-* page in the callback. | strong | Commands 25417-25458; every final destination returned exit 0 and ok 1. | Validator Results | incorporate | applied |
| C0HH-058 | 0000HH | Run one coherent waited source refresh and physically reread callback-time CPP/H against the complete inventory. | strong | Command 25458 and six exact generated hashes/readbacks. | Validator Results/generated readback | incorporate | applied |
| C0HH-059 | 0000HH | Preserve no third-party import disposition. | original-proof | First-party NexusTK classes and code. | UID0000HH formal source | not-applicable | applied |
| C0HH-060 | 0000HH | Preserve Wave2/Wave3 rejection and current-evidence authority. | very-strong | Skill policy and stale trace occurrence. | UID0000HH history | reject-stale | applied |
| C0HH-061 | 0000HH | Preserve report-level positive/negative evidence and rejected alternatives without pruning. | very-strong | Rule 26 no-loss requirement. | all affected docs | incorporate | applied |
| C0HH-062 | 0000HH | Keep manual coverage, IDA mutation, and lifecycle execution supervisor-owned. | original-proof | Goal and workflow boundary. | supervisor handoff | not-applicable | proposed |
| C0HH-063 | 0000HH | Preserve source style as C++03-era virtual/NULL/m_ and g_ conventions with no decompiler artifacts. | strong | Project headers and source-era constraints. | formal CPP/H and docs | incorporate | applied |
| C0HH-064 | 0000HH | Record remaining identifier/file-split uncertainty as a confidence cap, not a source/code blocker. | strong | Exhaustive evidence and absent original symbols. | score/open questions | incorporate | applied |

## Positive Evidence Summary

- The four methods are contiguous, exactly bounded, class-anchored, and sufficient to implement two complete dialogs.
- Constructor vptr stores identify both classes and all three inherited views. Action handlers occupy the exact DialogPane control-command slot, eliminating the stale generic-action name.
- Callers connect list-selection helpers to confirm construction, confirm to quantity construction, and both actions to the same packet helper.
- Allocation sizes and field accesses yield complete class tails without overlaps or unknown bytes.
- Unique strings, geometries, resources, validation constants, localized prompt id, and closing behavior are all literal in the binary.
- The `.text` and `.rdata` owner transitions independently agree on the standalone source boundary.
- The strongest inference chain is: exact separate code/vtable boundary + two coherent classes + current source-tree route + no foreign source bodies inside the range. That is sufficient to select standalone ownership even though the original filename is not present in symbols.

## IDA MCP Facts

- Fresh canonical 2026-08-17 persisted item presentations and exact modeled function ranges:
  - `0x0051fc90-0x0051ff6c`, size `0x2dc`, `sub_51FC90`, persisted item type `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int)`.
  - `0x0051ff70-0x005200c4`, size `0x154`, `sub_51FF70`, persisted item type `void __userpurge(int@<ecx>, int@<ebx>, int@<edi>, int, int)`.
  - `0x005200d0-0x005203be`, size `0x2ee`, `sub_5200D0`, persisted item type `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int, int, int)`.
  - `0x005203c0-0x00520539`, size `0x179`, `sub_5203C0`, persisted item type `void __userpurge(int *@<ecx>, unsigned int@<ebx>, __int16 *@<edi>, int, int)`.
- Quantity-constructor frame rows: `textWidthScale/float/+0x0/4`, `var_38/DialogPane */+0x14/4`, `Block/void */+0x18/4`, `var_30/RectBounds/+0x1c/0x10`, `bounds/RectBounds/+0x2c/0x10`, `var_10/_DWORD/+0x3c/4`, `var_C/_DWORD/+0x40/4`, `var_4/_DWORD/+0x48/4`, saved/return rows, and `arg_0/arg_4/arg_8` at `+0x54/+0x58/+0x5c`.
- Quantity-action frame rows: `Block/void */+0x8/4`, `ArgList/char[4]/+0xc/4`, `Buffer/wchar_t/+0x10/2` with logical 128-wide storage through `+0x10f`, `var_10/+0x110`, `var_C/+0x114`, `var_4/+0x11c`, saved/return, `arg_0/+0x128`, `arg_4/+0x12c`.
- Confirm-constructor frame equals the quantity constructor through the return row and adds `arg_0..arg_10` at `+0x54..+0x64`.
- Confirm-action frame rows: `block/void */+0x10/4`, `Block/void */+0x14/4`, `ArgList/char[4]/+0x18/4`, `Buffer/wchar_t/+0x1c/2` with logical 128-wide storage, `var_10/+0x11c`, `var_C/+0x120`, `var_4/+0x128`, saved/return, `arg_0/+0x134`, `arg_4/+0x138`.
- Fresh comments: address regular, address repeatable, function regular, and function repeatable are independently empty on each of the four functions. Regular and repeatable address comments are independently empty on every vtable head and COL cell.
- Fresh named types: `DialogPane` exists, size `620/0x26c`; `type_inspect` returned `exists:false` independently for `ArgumentedMenuMenuItemList`, `ArgumentedItemQuantityInputDialogPane`, and `ArgumentedItemConfirmInputDialogPane`.
- Fresh collision results: `lookup_funcs` returned `Not found` independently for all four proposed function names, while source lookups returned the exact current functions/ranges above.
- Boundaries: `0x51fc8d-0x51fc90`, `0x51ff6c-0x51ff70`, `0x5200c4-0x5200d0`, `0x5203be-0x5203c0`, and `0x520539-0x520540` are `0xcc` alignment. `0x520540` starts the unrelated ObjectImage function.
- Vtable views:
  - quantity primary `0x61f588-0x61f5e4`, secondary `0x61f5e8-0x61f614`, tertiary `0x61f618-0x61f620`;
  - confirm primary `0x61f624-0x61f680`, secondary `0x61f684-0x61f6b0`, tertiary `0x61f6b4-0x61f6bc`.
- COL cells are four-byte data at `0x61f584`, `0x61f5e4`, `0x61f614`, `0x61f620`, `0x61f680`, and `0x61f6b0`; each has name absent and type absent. Table types are absent while decorated table names are present.
- Quantity constructor stores table bases at `0x51fcec`, `0x51fcf2`, `0x51fcfc`; confirm stores at `0x520147`, `0x52014d`, `0x520157`.
- Quantity RTTI self descriptor `0x677b70`, primary COL `0x64bf18`, CHD `0x64bf2c`; confirm self descriptor `0x677ba4`, primary COL `0x64bfa0`, CHD `0x64bfb4`. Each CHD enumerates seven bases; secondary/tertiary PMD offsets are `+0xa0/+0xa4`.
- Unique literal band: `ArgumentQuantity` at `0x61f99c`; `You can't buy more than 100.` at `0x61f9c0`; `How much?` at `0x61f9fc`; `Price is different.` at `0x61fa10`; successor Message vtable begins `0x61fa3c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x51fc90,0x51ff6c)` | UID000554 quantity constructor child | Builds controls/resources, clones list context, creates/shows/slides pane | true | UID00000G | 92/94 applied | Formal CPP emitted and command-25458 coherent output reread. |
| `[0x51ff70,0x5200c4)` | UID000555 quantity OnControlCommand child | Parses/validates quantity, alerts, sends, closes | true | UID00000G | 93/94 applied | Formal CPP emitted and command-25458 coherent output reread. |
| `[0x5200d0,0x5203be)` | UID000557 confirm constructor child | Builds controls/resources, clones context, stores max/price/argument | true | UID00000F | 92/94 applied | Formal CPP emitted and command-25458 coherent output reread. |
| `[0x5203c0,0x520539)` | UID000558 confirm OnControlCommand child | Validates price, alerts or sends/opens quantity, closes on match | true | UID00000F | 93/94 applied | Formal CPP emitted and command-25458 coherent output reread. |
| quantity implicit destructor | UID00000G source effect | Compiler-generated derived destructor; base teardown only | compiler-covered | UID00000G | class score | No source body/declaration required; no pointer cleanup. |
| confirm implicit destructor | UID00000F source effect | Compiler-generated derived destructor; base teardown only | compiler-covered | UID00000F | class score | No source body/declaration required; no pointer cleanup. |
| `0x47eaf0`, `0x47e8d9`, `0x47e8e4` | UID0003Q5 + shared adjustor strip | Quantity scalar wrapper and +0xa0/+0xa4 thunks | false | none | retain | Shared compiler output; update consumer facts only. |
| `0x4b0a20`, `0x4b08e3`, `0x4b08ee` | UID00033Y | Confirm scalar wrapper and +0xa0/+0xa4 thunks | false | none | retain 88/91 | Folded compiler output; update active misclassification. |
| `0x51fc8d-0x51fc90` | UID0000VN ignored padding | predecessor alignment | false | none | n/a | Excluded from source methods. |
| `0x51ff6c-0x51ff70` | UID0000VN ignored padding | inter-method alignment | false | none | n/a | Excluded. |
| `0x5200c4-0x5200d0` | UID0000VN ignored padding | inter-class alignment | false | none | n/a | Excluded. |
| `0x5203be-0x5203c0` | UID0000VN ignored padding | inter-method alignment | false | none | n/a | Excluded. |
| `0x520539-0x520540` | UID0000VN ignored padding | successor alignment | false | none | n/a | Excluded; ObjectImage starts at 0x520540. |
| `ArgumentedItemQuantityInputDialogPane` | UID00000G | DialogPane-derived quantity class, size 0x274 | true | UID0000HH | 92/94 applied | Complete formal H and class route emitted. |
| `ArgumentedItemConfirmInputDialogPane` | UID00000F | DialogPane-derived confirm class, size 0x27c | true | UID0000HH | 92/94 applied | Complete formal H and class route emitted. |
| quantity layout | UID000556 | base 0x26c + pointer/dword tail | true | UID00000G | 92/94 applied | Exact evidence page plus explicit no-standalone-source marker. |
| confirm layout | UID000559 | base 0x26c + pointer/three-dword tail | true | UID00000F | 92/94 applied | Exact evidence page plus explicit no-standalone-source marker. |
| quantity primary vtable | `[0x61f588,0x61f5e4)` | 23 slots; action at +0x48 | compiler-covered | UID00000G | vtable child | Exact slot inventory; declaration-generated. |
| quantity secondary vtable | `[0x61f5e8,0x61f614)` | 11 EventHandler slots | compiler-covered | UID00000G | vtable child | Exact decorated name and +0xa0 view. |
| quantity tertiary vtable | `[0x61f618,0x61f620)` | 2 TimerHandler slots | compiler-covered | UID00000G | vtable child | Exact decorated name and +0xa4 view. |
| confirm primary vtable | `[0x61f624,0x61f680)` | 23 slots; action at +0x48 | compiler-covered | UID00000F | vtable child | Exact slot inventory; declaration-generated. |
| confirm secondary vtable | `[0x61f684,0x61f6b0)` | 11 EventHandler slots | compiler-covered | UID00000F | vtable child | Exact decorated name and +0xa0 view. |
| confirm tertiary vtable | `[0x61f6b4,0x61f6bc)` | 2 TimerHandler slots | compiler-covered | UID00000F | vtable child | Exact decorated name and +0xa4 view. |
| six COL cells/RTTI graphs | UID00055A/UID00055C | two seven-base graphs; six view-specific COLs | compiler-covered | UID0000HH/classes | 92/95 applied | Split from UID00025U; explicit compiler marker only. |
| `[0x61f99c,0x61fa3c)` | UID00055B | four owned UTF-16 source literals | compiler-covered | UID0000HH | 92/95 applied | Literals emitted by methods; no duplicate array. |
| `DLGEXC3.EPF`, `PAL01.PAL` | existing shared resource pages | background art/palette dependencies | external | DialogPane/resource owners | retain | Reference/include only. |
| `L"%d"`, `L"OK"`, empty title | shared literals | parsing/alert/edit dependencies | external | existing owners | retain | Do not duplicate storage page. |
| localized string id 246 | g_pLanguageMan/resource dependency | quantity prompt | external | LanguageMan | retain | Source call through localization owner. |
| `g_pBackPane` / `g_mainUiLayerSlots` | existing global/file owners | dialog show/layer dependencies | external | BackPane/MainUiGraph | retain | Include owning declarations. |
| `0x51f290` | UID0003VF | list-context copy constructor | true external | UID00000I | promote support | Declaration needed by input constructors. |
| `0x51f450` | UID0003VI | list private open-confirm helper | true external | UID00000I | promote support | Zero xrefs retained; body stays in ArgumentedMenuDialogs.cpp. |
| `0x51f510` | UID0003VJ | list private quantity-or-send helper | true external | UID00000I | promote support | Zero xrefs retained; body stays external. |
| `0x51f640` | UID0003VL | list packet helper | true external | UID00000I | promote support | Four calls; declaration/friend access required. |
| `0x520540` and `0x61f6bc` successors | ObjectImageControlPane | next executable and COL/table owner | excluded | UID0000M3 | retain | Hard half-open boundaries. |

Inventory totals: 4 source-authored methods, 2 compiler-covered implicit destructors, 6 compiler executable artifacts, 5 padding spans, 2 classes, 2 layouts, 6 vtables, 6 COLs/two RTTI graphs, 4 owned literals, 5 shared resource/global dependency groups, 4 external list methods, and 2 hard successors. Every row has an owner, source/no-code disposition, destination, and ledger/checklist claim.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x51fc90` | callers `0x51f570` in UID0003VJ and `0x5204ec` in confirm action | Quantity dialog constructed from list helper and accepted confirm path. |
| `0x51fc90` | calls DialogPane ctor/control constructors, UID0003VF, OnCreate/OnShow/SlideOpenVertical | Exact initialization and dependency set. |
| `0x51ff70` | data xref `0x61f5d0` only | Virtual primary `+0x48` dispatch; no missing direct caller. |
| `0x51ff70` | call `0x52008e -> 0x51f640` | Valid quantity serializes through list-context helper. |
| `0x5200d0` | callers `0x51f22a` and `0x51f4de` | Confirm dialog opened from owning dialog/list selected-row flows. |
| `0x5200d0` | calls DialogPane ctor/control constructors, UID0003VF, OnCreate/OnShow/SlideOpenVertical | Exact initialization and dependency set. |
| `0x5203c0` | data xref `0x61f66c` only | Virtual primary `+0x48` dispatch. |
| `0x5203c0` | calls `0x5204ec -> 0x51fc90`, `0x520501 -> 0x51f640`, LanguageMan id 246, AlertPane | Exact mismatch/single/multiple-quantity branch graph. |
| `0x51f450` | zero inbound xrefs/pointer hits; calls `0x5200d0` at `0x51f4de` | Retained list helper, not input-file owner. |
| `0x51f510` | zero inbound xrefs/pointer hits; calls `0x51fc90` and `0x51f640` | Retained list helper, not dead code. |
| `0x51f640` | calls from `0x51f504`, `0x51f58d`, `0x52008e`, `0x520501` | Shared list-context packet method used by both files. |
| quantity vtable bases | ctor stores `0x51fcec/0x51fcf2/0x51fcfc` | Exact three-view object construction. |
| confirm vtable bases | ctor stores `0x520147/0x52014d/0x520157` | Exact three-view object construction. |
| four owned strings | direct refs in the four target methods | Source literals, not standalone authored globals. |
| shared DLGEXC3/PAL01 | constructor refs plus many non-target consumers | Shared resource storage; target consumes without owning. |
| `g_pBackPane` | reads in both constructors' OnShow path | Existing BackPane global dependency. |
| `g_pLanguageMan` | confirm action read for id 246 | Existing localization dependency. |
| layer slot `0x69b36c` | both constructors pass it to OnCreate | Existing `g_mainUiLayerSlots.overlayPaneLayerContext`; not a target global. |

## Documentation Evidence And IDA Status

- Callback-applied ordinary docs agree on file/class/aggregate ownership, exact method ranges, helper separation, row fields, packet layout, vtable bases, unique strings, complete CPP/H routes, ten assigned child/support UIDs, source order, and compiler-only dispositions.
- Historical stale state is retained in dated correction sections: UID0000HH split uncertainty, UID0001BT child deferral, blank UID00000F/G and UID00000I H routes, UID0003VI/VJ/VL C++ deferral, UID00033Y's ExchangeDialog-only description, UID00025U's unsplit family, and command-25350's incomplete generated output. Manual coverage rows remain supervisor-owned and do not define ordinary-document completion.
- In the dated 2026-08-17 read-only prestate, IDA names remained `sub_*`, comments were absent, and derived/list UDTs were absent. Fresh supervisor Gate 2B readback is authoritative for any later IDA state; these dated database-quality gaps are not reasons to retain decompiler source.
- Generated status includes dated pre-callback command 25350 and callback-time coherent command 25458. Later validator-generated authority must still be reread dynamically by the supervisor.

## Ranked Ownership Analysis

### 1. Standalone ArgumentedItemInputDialogs.cpp/.h

- Evidence for: exact aligned `.text` transition after UID0001BS; exact vtable-owner transition after UID000320; two coherent classes; four complete methods; unique literal tail; existing file route; no foreign method inside the executable range.
- Evidence against: no recovered original filename/PDB; close coupling to ArgumentedMenuMenuItemList.
- Decision: selected, strong confidence. Coupling is handled by an ordinary header dependency and friends, not folding.

### 2. Fold into ArgumentedMenuDialogs.cpp/.h

- Evidence for: direct constructor/helper calls, copied list context, contiguous executable adjacency.
- Evidence against: independent aligned boundary, separate vtable family, two complete derived classes, current explicit source route, and cleaner declaration ownership.
- Decision: rejected as lower probability; preserve as historical assumption with reasons.

### 3. Fold into TextMenuDialogs.cpp or a generic item-dialog unit

- Evidence for: related merchant-menu/dialog UI family and shared control resources.
- Evidence against: no text-menu method/vtable ownership in target range; argumented packet/context semantics are specific; exact owner transitions separate these units.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: existing UID0000HH, `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp` and `.h`.
- Full contents: two class declarations, two constructors, two control-command methods; compiler-generated implicit destructors/vtables/RTTI/literal pools are covered by those declarations/definitions.
- Related items accepted: four exact methods, six vtable views/two RTTI graphs, two layouts, four owned literals.
- Related items rejected: UID00000I helper bodies, DialogPane methods, shared resources/globals, shared destructor wrappers, ObjectImage successors.
- Source-file inference: narrow standalone two-class companion file.

## Source Placement

- Recommended placement: `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp/.h` under UID0000HH.
- Class declarations emit through UID00000G then UID00000F in H. Their exact method children emit through each class's CPP `[[CHILDREN]]` route. UID0001BT becomes an index/no-duplicate marker, not a method parent.
- `ArgumentedMenuDialogs.h` must expose the complete `ArgumentedMenuMenuItemList` declaration needed by copy construction and packet submission. Its three helper bodies remain in `ArgumentedMenuDialogs.cpp`.
- Rejected placements: `TextMenuDialogs` lacks target ownership; generic ItemDialogs would lose argumented protocol/context locality; raw by-memory aggregate emission would violate class/method boundaries.
- Remaining uncertainty: the historical developers could have folded the two classes into ArgumentedMenuDialogs.cpp, but current evidence favors standalone. This caps confidence only.

## Range / Split / Padding / Reclassification Analysis

- Exact executable child ranges are the four half-open functions listed above. Interior `0x520046` is not a function.
- Exact padding: 3, 4, 12, 2, and 7 `0xcc` bytes at the five listed boundaries; remain ignored and unowned.
- UID0001BT remains exact `[0x51fc90,0x520539)` aggregate/index but no longer carries `[[CHILDREN]]`; method pages attach to class owners.
- Create `[0x61f584,0x61f6bc)` exact vtable child. `0x61f6bc` is the ObjectImage COL and excluded.
- Create `[0x61f99c,0x61fa3c)` exact literal child. `0x61fa3c` is Message vtable data and excluded.
- UID00025U remains mixed, non-emitting, and non-owned after linking the exact children.
- Shared destructor ranges remain mixed/folded compiler islands and cannot be assigned to UID0000HH as source bodies.

## Negative Evidence Summary

- No original symbols prove the physical filename, field spellings, helper access level, or include spelling.
- No inbound start refs or pointer hits prove live calls to `0x51f450/0x51f510`; however, their complete source-shaped bodies and internal graph reject dead-padding or input-owner interpretations.
- No derived/list UDTs existed in the dated Gate 1 read-only prestate; partial UDT installation would be unsafe and is not proposed. Fresh supervisor precheck controls later IDA authority.
- No target-owned global/static object exists. Layer, BackPane, LanguageMan, resource, and packet dependencies have other owners.
- No destructor body deletes `m_menuContext`; source cleanup must not be invented.
- No extra target function exists at `0x520046`, after `0x520539`, or before `0x51fc90`.
- No evidence supports raw vtable/RTTI arrays or hand-authored scalar deleting wrappers.
- At dated command `000000025350`, no generated H or complete CPP existed; that historical snapshot cannot be used as later completion proof, and current authority requires dynamic physical reread.

## IDA Rename / Type / Comment Recommendations

This is an inert semantic supervisor handoff, not an executable transaction. `DB` below is a runtime-bound placeholder for the canonical session selected by the supervisor. Backup, save, rollback, worker retirement, and persistence verification remain supervisor-owned. Every stage hard-stops before mutation on any mismatch in item head/range/size, name, persisted type, complete frame, independent comment channel, collision result, callers/xrefs, vtable/COL item, or named-type state.

Literal complete function/frame prestates from the fresh 2026-08-17 canonical readback:

- `F01`, `0x51fc90-0x51ff6c`, size `0x2dc`, name `sub_51FC90`, type `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int)`, callers exactly `{0x51f570,0x5204ec}`; frame exactly `textWidthScale@0x0/0x4:float`, `var_38@0x14/0x4:DialogPane *`, `Block@0x18/0x4:void *`, `var_30@0x1c/0x10:RectBounds`, `bounds@0x2c/0x10:RectBounds`, `var_10@0x3c/0x4:_DWORD`, `var_C@0x40/0x4:_DWORD`, `var_4@0x48/0x4:_DWORD`, `__saved_registers@0x4c/0x4:_DWORD`, `__return_address@0x50/0x4:_UNKNOWN *`, `arg_0@0x54/0x4:_DWORD`, `arg_4@0x58/0x4:_DWORD`, `arg_8@0x5c/0x4:_DWORD`.
- `F02`, `0x51ff70-0x5200c4`, size `0x154`, name `sub_51FF70`, type `void __userpurge(int@<ecx>, int@<ebx>, int@<edi>, int, int)`, xrefs exactly `{data 0x61f5d0}`; frame exactly `Block@0x8/0x4:void *`, `ArgList@0xc/0x4:char[4]`, `Buffer@0x10/0x2:wchar_t`, `var_10@0x110/0x4:_DWORD`, `var_C@0x114/0x4:_DWORD`, `var_4@0x11c/0x4:_DWORD`, `__saved_registers@0x120/0x4:_DWORD`, `__return_address@0x124/0x4:_UNKNOWN *`, `arg_0@0x128/0x4:_DWORD`, `arg_4@0x12c/0x4:_DWORD`.
- `F03`, `0x5200d0-0x5203be`, size `0x2ee`, name `sub_5200D0`, type `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int, int, int)`, callers exactly `{0x51f22a,0x51f4de}`; frame exactly `textWidthScale@0x0/0x4:float`, `var_38@0x14/0x4:DialogPane *`, `Block@0x18/0x4:void *`, `var_30@0x1c/0x10:RectBounds`, `bounds@0x2c/0x10:RectBounds`, `var_10@0x3c/0x4:_DWORD`, `var_C@0x40/0x4:_DWORD`, `var_4@0x48/0x4:_DWORD`, `__saved_registers@0x4c/0x4:_DWORD`, `__return_address@0x50/0x4:_UNKNOWN *`, `arg_0@0x54/0x4:_DWORD`, `arg_4@0x58/0x4:_DWORD`, `arg_8@0x5c/0x4:_DWORD`, `arg_C@0x60/0x4:_DWORD`, `arg_10@0x64/0x4:_DWORD`.
- `F04`, `0x5203c0-0x520539`, size `0x179`, name `sub_5203C0`, type `void __userpurge(int *@<ecx>, unsigned int@<ebx>, __int16 *@<edi>, int, int)`, xrefs exactly `{data 0x61f66c}`; frame exactly `block@0x10/0x4:void *`, `Block@0x14/0x4:void *`, `ArgList@0x18/0x4:char[4]`, `Buffer@0x1c/0x2:wchar_t`, `var_10@0x11c/0x4:_DWORD`, `var_C@0x120/0x4:_DWORD`, `var_4@0x128/0x4:_DWORD`, `__saved_registers@0x12c/0x4:_DWORD`, `__return_address@0x130/0x4:_UNKNOWN *`, `arg_0@0x134/0x4:_DWORD`, `arg_4@0x138/0x4:_DWORD`.

For each function, address regular `AR`, address repeatable `AP`, function regular `FR`, and function repeatable `FP` are independently empty before the corresponding action. The required immediate readback endpoints are `lookup_funcs({database:DB,queries:[source,destination]})`, `inspect_items({database:DB,addrs:[entry]})`, `stack_frame({database:DB,addrs:[entry]})`, and `get_comments({database:DB,addrs:[entry]})`.

| Action ID | Entity/range | Literal current prestate | Public endpoint/action | Collision and hard-stop contract | Complete expected poststate |
| --- | --- | --- | --- | --- | --- |
| A0HH-01 | `F01` | exact F01 including type `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int)`; AR empty; AP empty; FR empty; FP empty; destination absent | collision lookup, then `rename({database:DB,batch:{func:[{addr:"0x51fc90",name:"ArgumentedItemQuantityInputDialogPane_Constructor"}],dry_run:true,pure:true,stop_on_error:true,allow_overwrite:false}})`; if exact, repeat with `dry_run:false` | source lookup must be exact F01 including the literal `DialogPane *` return/receiver type and destination `Not found`; dry-run one success/zero failure; no overwrite | name exact `ArgumentedItemQuantityInputDialogPane_Constructor`; type remains exactly `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int)`; range/size/complete F01 frame/callers exact; AR/AP/FR/FP independently empty |
| A0HH-02 | `F01` after A0HH-01 | renamed name exact; type exactly `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int)`; F01 range/size/frame/callers exact; AR empty; AP empty; FR empty; FP empty | `set_function_comments({database:DB,items:[{addr:"0x51fc90",comment:"Constructs ArgumentedItemQuantityInputDialogPane, clones ArgumentedMenuMenuItemList context, and opens the quantity prompt."}]})` | A0HH-01 immediate readback must match before call | same name; type remains exactly `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int)`; same range/size/frame/callers; AR empty; AP empty; FR exact requested text; FP empty |
| A0HH-03 | `F02` | exact F02; AR empty; AP empty; FR empty; FP empty; destination absent | collision lookup, then `rename({database:DB,batch:{func:[{addr:"0x51ff70",name:"ArgumentedItemQuantityInputDialogPane_OnControlCommand"}],dry_run:true,pure:true,stop_on_error:true,allow_overwrite:false}})`; if exact, repeat with `dry_run:false` | source exact F02; destination `Not found`; dry-run one success/zero failure; no overwrite | name exact `ArgumentedItemQuantityInputDialogPane_OnControlCommand`; type/range/size/complete F02 frame/xrefs exact; AR/AP/FR/FP independently empty |
| A0HH-04 | `F02` after A0HH-03 | renamed name exact; F02 type/range/size/frame/xrefs exact; AR empty; AP empty; FR empty; FP empty | `set_function_comments({database:DB,items:[{addr:"0x51ff70",comment:"Handles quantity confirm/cancel, validates unsigned range 1..100, sends the argumented-item quantity packet, and closes."}]})` | A0HH-03 immediate readback exact | same name/type/range/size/frame/xrefs; AR empty; AP empty; FR exact requested text; FP empty |
| A0HH-05 | `F03` | exact F03 including type `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int, int, int)`; AR empty; AP empty; FR empty; FP empty; destination absent | collision lookup, then `rename({database:DB,batch:{func:[{addr:"0x5200d0",name:"ArgumentedItemConfirmInputDialogPane_Constructor"}],dry_run:true,pure:true,stop_on_error:true,allow_overwrite:false}})`; if exact, repeat with `dry_run:false` | source lookup must be exact F03 including the literal `DialogPane *` return/receiver type and destination `Not found`; dry-run one success/zero failure; no overwrite | name exact `ArgumentedItemConfirmInputDialogPane_Constructor`; type remains exactly `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int, int, int)`; range/size/complete F03 frame/callers exact; AR/AP/FR/FP independently empty |
| A0HH-06 | `F03` after A0HH-05 | renamed name exact; type exactly `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int, int, int)`; F03 range/size/frame/callers exact; AR empty; AP empty; FR empty; FP empty | `set_function_comments({database:DB,items:[{addr:"0x5200d0",comment:"Constructs ArgumentedItemConfirmInputDialogPane, clones list context, stores quantity/price/argument fields, and opens the price prompt."}]})` | A0HH-05 immediate readback exact | same name; type remains exactly `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 *, int, int, int, int)`; same range/size/frame/callers; AR empty; AP empty; FR exact requested text; FP empty |
| A0HH-07 | `F04` | exact F04; AR empty; AP empty; FR empty; FP empty; destination absent | collision lookup, then `rename({database:DB,batch:{func:[{addr:"0x5203c0",name:"ArgumentedItemConfirmInputDialogPane_OnControlCommand"}],dry_run:true,pure:true,stop_on_error:true,allow_overwrite:false}})`; if exact, repeat with `dry_run:false` | source exact F04; destination `Not found`; dry-run one success/zero failure; no overwrite | name exact `ArgumentedItemConfirmInputDialogPane_OnControlCommand`; type/range/size/complete F04 frame/xrefs exact; AR/AP/FR/FP independently empty |
| A0HH-08 | `F04` after A0HH-07 | renamed name exact; F04 type/range/size/frame/xrefs exact; AR empty; AP empty; FR empty; FP empty | `set_function_comments({database:DB,items:[{addr:"0x5203c0",comment:"Handles price confirmation; preserves the dialog on mismatch, otherwise sends quantity one or opens the quantity prompt and closes."}]})` | A0HH-07 immediate readback exact | same name/type/range/size/frame/xrefs; AR empty; AP empty; FR exact requested text; FP empty |
| A0HH-09 | quantity primary `[0x61f588,0x61f5e4)` | every one of 23 slots is the independent literal state in the A0HH-09 manifest below | protection/readback only through every row-specific endpoint in the manifest | hard stop on any slot item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | every slot remains the exact literal poststate in its manifest row |
| A0HH-10 | quantity secondary `[0x61f5e8,0x61f614)` | every one of 11 slots is the independent literal state in the A0HH-10 manifest below | protection/readback only through every row-specific endpoint in the manifest | hard stop on any slot item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | every slot remains the exact literal poststate in its manifest row |
| A0HH-11 | quantity tertiary `[0x61f618,0x61f620)` | both slots are independent literal states in the A0HH-11 manifest below | protection/readback only through every row-specific endpoint in the manifest | hard stop on either slot item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | both slots remain the exact literal poststates in their manifest rows |
| A0HH-12 | confirm primary `[0x61f624,0x61f680)` | every one of 23 slots is the independent literal state in the A0HH-12 manifest below | protection/readback only through every row-specific endpoint in the manifest | hard stop on any slot item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | every slot remains the exact literal poststate in its manifest row |
| A0HH-13 | confirm secondary `[0x61f684,0x61f6b0)` | every one of 11 slots is the independent literal state in the A0HH-13 manifest below | protection/readback only through every row-specific endpoint in the manifest | hard stop on any slot item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | every slot remains the exact literal poststate in its manifest row |
| A0HH-14 | confirm tertiary `[0x61f6b4,0x61f6bc)` | both slots are independent literal states in the A0HH-14 manifest below | protection/readback only through every row-specific endpoint in the manifest | hard stop on either slot item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | both slots remain the exact literal poststates in their manifest rows |
| A0HH-15 | COL `[0x61f584,0x61f588)` | independent literal COL-cell state in the A0HH-15 manifest below, including inbound empty and outbound `{data 0x0064bf18}` | protection/readback only through the exact A0HH-15 byte/item/comment/xref endpoints | hard stop on item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | exact A0HH-15 literal poststate preserved |
| A0HH-16 | COL `[0x61f5e4,0x61f5e8)` | independent literal COL-cell state in the A0HH-16 manifest below, including inbound empty and outbound `{data 0x0064bf78}` | protection/readback only through the exact A0HH-16 byte/item/comment/xref endpoints | hard stop on item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | exact A0HH-16 literal poststate preserved |
| A0HH-17 | COL `[0x61f614,0x61f618)` | independent literal COL-cell state in the A0HH-17 manifest below, including inbound empty and outbound `{data 0x0064bf8c}` | protection/readback only through the exact A0HH-17 byte/item/comment/xref endpoints | hard stop on item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | exact A0HH-17 literal poststate preserved |
| A0HH-18 | COL `[0x61f620,0x61f624)` | independent literal COL-cell state in the A0HH-18 manifest below, including inbound empty and outbound `{data 0x0064bfa0}` | protection/readback only through the exact A0HH-18 byte/item/comment/xref endpoints | hard stop on item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | exact A0HH-18 literal poststate preserved |
| A0HH-19 | COL `[0x61f680,0x61f684)` | independent literal COL-cell state in the A0HH-19 manifest below, including inbound empty and outbound `{data 0x0064c000}` | protection/readback only through the exact A0HH-19 byte/item/comment/xref endpoints | hard stop on item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | exact A0HH-19 literal poststate preserved |
| A0HH-20 | COL `[0x61f6b0,0x61f6b4)` | independent literal COL-cell state in the A0HH-20 manifest below, including inbound empty and outbound `{data 0x0064c014}` | protection/readback only through the exact A0HH-20 byte/item/comment/xref endpoints | hard stop on item/range/kind/width/value/bytes/name/type/AR/AP/FR/FP/inbound/outbound drift | exact A0HH-20 literal poststate preserved |
| A0HH-21 | named type `ArgumentedMenuMenuItemList` | `type_inspect({database:DB,queries:{name:"ArgumentedMenuMenuItemList",include_members:true,max_members:64}})` returns `exists:false`, `Type not found` | no mutation; protection/readback only | never install a partial 0x15c placeholder | exact absence preserved |
| A0HH-22 | named type `ArgumentedItemQuantityInputDialogPane` | same exact query shape returns `exists:false`, `Type not found` | no mutation; protection/readback only | no partial inheritance/layout type | exact absence preserved |
| A0HH-23 | named type `ArgumentedItemConfirmInputDialogPane` | same exact query shape returns `exists:false`, `Type not found` | no mutation; protection/readback only | no partial inheritance/layout type | exact absence preserved |

**A0HH-09 through A0HH-14 literal vtable-slot protection manifests**

Each row is independently protected. `direction:"to"` is the exact inbound set for the slot address and `direction:"from"` is the exact outbound set from the stored pointer. Both xref queries must return terminal pagination (`next_offset:null`); any extra, missing, reordered after canonical sort, or differently typed xref hard-stops the handoff. No row permits mutation.

**A0HH-09 quantity primary manifest, exact table range `0x0061f588-0x0061f5e4`**

| Slot/range | Literal current prestate | Inbound xrefs | Outbound xrefs | Exact byte/item/comment/xref readback endpoints | Permitted delta | Exact unchanged poststate |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061f588-0x0061f58c` | `0x0061f588-0x0061f58c`; vtable dword data slot; width `4`; value `0x0047eaf0`; bytes `f0 ea 47 00`; name `??_7ArgumentedItemQuantityInputDialogPane@@6B@`; type empty; AR empty; AP empty; FR not applicable; FP not applicable | {code 0x0051fcec} | {data 0x0047eaf0} | `inspect_items({database:DB,addrs:["0x0061f588"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f588",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f588"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f588",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f588",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f588-0x0061f58c`; vtable dword data slot; width `4`; value `0x0047eaf0`; bytes `f0 ea 47 00`; name `??_7ArgumentedItemQuantityInputDialogPane@@6B@`; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound {code 0x0051fcec}; outbound {data 0x0047eaf0} |
| `0x0061f58c-0x0061f590` | `0x0061f58c-0x0061f590`; vtable dword data slot; width `4`; value `0x004f4b10`; bytes `10 4b 4f 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x004f4b10} | `inspect_items({database:DB,addrs:["0x0061f58c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f58c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f58c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f58c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f58c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f58c-0x0061f590`; vtable dword data slot; width `4`; value `0x004f4b10`; bytes `10 4b 4f 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x004f4b10} |
| `0x0061f590-0x0061f594` | `0x0061f590-0x0061f594`; vtable dword data slot; width `4`; value `0x0041b6c0`; bytes `c0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041b6c0} | `inspect_items({database:DB,addrs:["0x0061f590"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f590",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f590"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f590",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f590",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f590-0x0061f594`; vtable dword data slot; width `4`; value `0x0041b6c0`; bytes `c0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041b6c0} |
| `0x0061f594-0x0061f598` | `0x0061f594-0x0061f598`; vtable dword data slot; width `4`; value `0x004b8e20`; bytes `20 8e 4b 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x004b8e20} | `inspect_items({database:DB,addrs:["0x0061f594"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f594",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f594"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f594",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f594",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f594-0x0061f598`; vtable dword data slot; width `4`; value `0x004b8e20`; bytes `20 8e 4b 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x004b8e20} |
| `0x0061f598-0x0061f59c` | `0x0061f598-0x0061f59c`; vtable dword data slot; width `4`; value `0x0041d680`; bytes `80 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041d680} | `inspect_items({database:DB,addrs:["0x0061f598"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f598",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f598"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f598",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f598",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f598-0x0061f59c`; vtable dword data slot; width `4`; value `0x0041d680`; bytes `80 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041d680} |
| `0x0061f59c-0x0061f5a0` | `0x0061f59c-0x0061f5a0`; vtable dword data slot; width `4`; value `0x00544730`; bytes `30 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544730} | `inspect_items({database:DB,addrs:["0x0061f59c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f59c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f59c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f59c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f59c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f59c-0x0061f5a0`; vtable dword data slot; width `4`; value `0x00544730`; bytes `30 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544730} |
| `0x0061f5a0-0x0061f5a4` | `0x0061f5a0-0x0061f5a4`; vtable dword data slot; width `4`; value `0x00544750`; bytes `50 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544750} | `inspect_items({database:DB,addrs:["0x0061f5a0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5a0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5a0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5a0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5a0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5a0-0x0061f5a4`; vtable dword data slot; width `4`; value `0x00544750`; bytes `50 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544750} |
| `0x0061f5a4-0x0061f5a8` | `0x0061f5a4-0x0061f5a8`; vtable dword data slot; width `4`; value `0x005447a0`; bytes `a0 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x005447a0} | `inspect_items({database:DB,addrs:["0x0061f5a4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5a4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5a4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5a4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5a4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5a4-0x0061f5a8`; vtable dword data slot; width `4`; value `0x005447a0`; bytes `a0 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x005447a0} |
| `0x0061f5a8-0x0061f5ac` | `0x0061f5a8-0x0061f5ac`; vtable dword data slot; width `4`; value `0x00544800`; bytes `00 48 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544800} | `inspect_items({database:DB,addrs:["0x0061f5a8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5a8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5a8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5a8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5a8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5a8-0x0061f5ac`; vtable dword data slot; width `4`; value `0x00544800`; bytes `00 48 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544800} |
| `0x0061f5ac-0x0061f5b0` | `0x0061f5ac-0x0061f5b0`; vtable dword data slot; width `4`; value `0x00544a20`; bytes `20 4a 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544a20} | `inspect_items({database:DB,addrs:["0x0061f5ac"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5ac",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5ac"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5ac",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5ac",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5ac-0x0061f5b0`; vtable dword data slot; width `4`; value `0x00544a20`; bytes `20 4a 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544a20} |
| `0x0061f5b0-0x0061f5b4` | `0x0061f5b0-0x0061f5b4`; vtable dword data slot; width `4`; value `0x00544b80`; bytes `80 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544b80} | `inspect_items({database:DB,addrs:["0x0061f5b0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5b0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5b0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5b0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5b0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5b0-0x0061f5b4`; vtable dword data slot; width `4`; value `0x00544b80`; bytes `80 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544b80} |
| `0x0061f5b4-0x0061f5b8` | `0x0061f5b4-0x0061f5b8`; vtable dword data slot; width `4`; value `0x00544bd0`; bytes `d0 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544bd0} | `inspect_items({database:DB,addrs:["0x0061f5b4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5b4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5b4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5b4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5b4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5b4-0x0061f5b8`; vtable dword data slot; width `4`; value `0x00544bd0`; bytes `d0 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544bd0} |
| `0x0061f5b8-0x0061f5bc` | `0x0061f5b8-0x0061f5bc`; vtable dword data slot; width `4`; value `0x0049dfd0`; bytes `d0 df 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049dfd0} | `inspect_items({database:DB,addrs:["0x0061f5b8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5b8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5b8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5b8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5b8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5b8-0x0061f5bc`; vtable dword data slot; width `4`; value `0x0049dfd0`; bytes `d0 df 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049dfd0} |
| `0x0061f5bc-0x0061f5c0` | `0x0061f5bc-0x0061f5c0`; vtable dword data slot; width `4`; value `0x00544cb0`; bytes `b0 4c 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544cb0} | `inspect_items({database:DB,addrs:["0x0061f5bc"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5bc",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5bc"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5bc",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5bc",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5bc-0x0061f5c0`; vtable dword data slot; width `4`; value `0x00544cb0`; bytes `b0 4c 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544cb0} |
| `0x0061f5c0-0x0061f5c4` | `0x0061f5c0-0x0061f5c4`; vtable dword data slot; width `4`; value `0x0049e1c0`; bytes `c0 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e1c0} | `inspect_items({database:DB,addrs:["0x0061f5c0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5c0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5c0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5c0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5c0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5c0-0x0061f5c4`; vtable dword data slot; width `4`; value `0x0049e1c0`; bytes `c0 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e1c0} |
| `0x0061f5c4-0x0061f5c8` | `0x0061f5c4-0x0061f5c8`; vtable dword data slot; width `4`; value `0x0049e190`; bytes `90 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e190} | `inspect_items({database:DB,addrs:["0x0061f5c4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5c4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5c4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5c4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5c4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5c4-0x0061f5c8`; vtable dword data slot; width `4`; value `0x0049e190`; bytes `90 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e190} |
| `0x0061f5c8-0x0061f5cc` | `0x0061f5c8-0x0061f5cc`; vtable dword data slot; width `4`; value `0x0049e210`; bytes `10 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e210} | `inspect_items({database:DB,addrs:["0x0061f5c8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5c8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5c8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5c8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5c8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5c8-0x0061f5cc`; vtable dword data slot; width `4`; value `0x0049e210`; bytes `10 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e210} |
| `0x0061f5cc-0x0061f5d0` | `0x0061f5cc-0x0061f5d0`; vtable dword data slot; width `4`; value `0x0049f090`; bytes `90 f0 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049f090} | `inspect_items({database:DB,addrs:["0x0061f5cc"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5cc",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5cc"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5cc",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5cc",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5cc-0x0061f5d0`; vtable dword data slot; width `4`; value `0x0049f090`; bytes `90 f0 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049f090} |
| `0x0061f5d0-0x0061f5d4` | `0x0061f5d0-0x0061f5d4`; vtable dword data slot; width `4`; value `0x0051ff70`; bytes `70 ff 51 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0051ff70} | `inspect_items({database:DB,addrs:["0x0061f5d0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5d0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5d0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5d0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5d0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5d0-0x0061f5d4`; vtable dword data slot; width `4`; value `0x0051ff70`; bytes `70 ff 51 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0051ff70} |
| `0x0061f5d4-0x0061f5d8` | `0x0061f5d4-0x0061f5d8`; vtable dword data slot; width `4`; value `0x0041b6a0`; bytes `a0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041b6a0} | `inspect_items({database:DB,addrs:["0x0061f5d4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5d4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5d4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5d4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5d4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5d4-0x0061f5d8`; vtable dword data slot; width `4`; value `0x0041b6a0`; bytes `a0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041b6a0} |
| `0x0061f5d8-0x0061f5dc` | `0x0061f5d8-0x0061f5dc`; vtable dword data slot; width `4`; value `0x0049f1d0`; bytes `d0 f1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049f1d0} | `inspect_items({database:DB,addrs:["0x0061f5d8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5d8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5d8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5d8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5d8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5d8-0x0061f5dc`; vtable dword data slot; width `4`; value `0x0049f1d0`; bytes `d0 f1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049f1d0} |
| `0x0061f5dc-0x0061f5e0` | `0x0061f5dc-0x0061f5e0`; vtable dword data slot; width `4`; value `0x0049f2e0`; bytes `e0 f2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049f2e0} | `inspect_items({database:DB,addrs:["0x0061f5dc"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5dc",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5dc"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5dc",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5dc",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5dc-0x0061f5e0`; vtable dword data slot; width `4`; value `0x0049f2e0`; bytes `e0 f2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049f2e0} |
| `0x0061f5e0-0x0061f5e4` | `0x0061f5e0-0x0061f5e4`; vtable dword data slot; width `4`; value `0x0049fc00`; bytes `00 fc 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049fc00} | `inspect_items({database:DB,addrs:["0x0061f5e0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5e0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5e0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5e0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5e0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5e0-0x0061f5e4`; vtable dword data slot; width `4`; value `0x0049fc00`; bytes `00 fc 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049fc00} |

**A0HH-10 quantity secondary manifest, exact table range `0x0061f5e8-0x0061f614`**

| Slot/range | Literal current prestate | Inbound xrefs | Outbound xrefs | Exact byte/item/comment/xref readback endpoints | Permitted delta | Exact unchanged poststate |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061f5e8-0x0061f5ec` | `0x0061f5e8-0x0061f5ec`; vtable dword data slot; width `4`; value `0x0047e8d9`; bytes `d9 e8 47 00`; name `??_7ArgumentedItemQuantityInputDialogPane@@6B@_0`; type empty; AR empty; AP empty; FR not applicable; FP not applicable | {code 0x0051fcf2} | {data 0x0047e8d9} | `inspect_items({database:DB,addrs:["0x0061f5e8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5e8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5e8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5e8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5e8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5e8-0x0061f5ec`; vtable dword data slot; width `4`; value `0x0047e8d9`; bytes `d9 e8 47 00`; name `??_7ArgumentedItemQuantityInputDialogPane@@6B@_0`; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound {code 0x0051fcf2}; outbound {data 0x0047e8d9} |
| `0x0061f5ec-0x0061f5f0` | `0x0061f5ec-0x0061f5f0`; vtable dword data slot; width `4`; value `0x0049e240`; bytes `40 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e240} | `inspect_items({database:DB,addrs:["0x0061f5ec"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5ec",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5ec"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5ec",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5ec",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5ec-0x0061f5f0`; vtable dword data slot; width `4`; value `0x0049e240`; bytes `40 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e240} |
| `0x0061f5f0-0x0061f5f4` | `0x0061f5f0-0x0061f5f4`; vtable dword data slot; width `4`; value `0x0049e6e0`; bytes `e0 e6 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e6e0} | `inspect_items({database:DB,addrs:["0x0061f5f0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5f0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5f0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5f0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5f0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5f0-0x0061f5f4`; vtable dword data slot; width `4`; value `0x0049e6e0`; bytes `e0 e6 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e6e0} |
| `0x0061f5f4-0x0061f5f8` | `0x0061f5f4-0x0061f5f8`; vtable dword data slot; width `4`; value `0x0049ea60`; bytes `60 ea 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049ea60} | `inspect_items({database:DB,addrs:["0x0061f5f4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5f4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5f4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5f4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5f4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5f4-0x0061f5f8`; vtable dword data slot; width `4`; value `0x0049ea60`; bytes `60 ea 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049ea60} |
| `0x0061f5f8-0x0061f5fc` | `0x0061f5f8-0x0061f5fc`; vtable dword data slot; width `4`; value `0x0041d6b0`; bytes `b0 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041d6b0} | `inspect_items({database:DB,addrs:["0x0061f5f8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5f8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5f8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5f8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5f8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5f8-0x0061f5fc`; vtable dword data slot; width `4`; value `0x0041d6b0`; bytes `b0 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041d6b0} |
| `0x0061f5fc-0x0061f600` | `0x0061f5fc-0x0061f600`; vtable dword data slot; width `4`; value `0x00544df0`; bytes `f0 4d 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544df0} | `inspect_items({database:DB,addrs:["0x0061f5fc"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5fc",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5fc"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5fc",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5fc",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5fc-0x0061f600`; vtable dword data slot; width `4`; value `0x00544df0`; bytes `f0 4d 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544df0} |
| `0x0061f600-0x0061f604` | `0x0061f600-0x0061f604`; vtable dword data slot; width `4`; value `0x00544e00`; bytes `00 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e00} | `inspect_items({database:DB,addrs:["0x0061f600"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f600",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f600"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f600",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f600",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f600-0x0061f604`; vtable dword data slot; width `4`; value `0x00544e00`; bytes `00 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e00} |
| `0x0061f604-0x0061f608` | `0x0061f604-0x0061f608`; vtable dword data slot; width `4`; value `0x004a89f0`; bytes `f0 89 4a 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x004a89f0} | `inspect_items({database:DB,addrs:["0x0061f604"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f604",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f604"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f604",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f604",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f604-0x0061f608`; vtable dword data slot; width `4`; value `0x004a89f0`; bytes `f0 89 4a 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x004a89f0} |
| `0x0061f608-0x0061f60c` | `0x0061f608-0x0061f60c`; vtable dword data slot; width `4`; value `0x00544e10`; bytes `10 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e10} | `inspect_items({database:DB,addrs:["0x0061f608"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f608",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f608"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f608",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f608",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f608-0x0061f60c`; vtable dword data slot; width `4`; value `0x00544e10`; bytes `10 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e10} |
| `0x0061f60c-0x0061f610` | `0x0061f60c-0x0061f610`; vtable dword data slot; width `4`; value `0x00544e30`; bytes `30 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e30} | `inspect_items({database:DB,addrs:["0x0061f60c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f60c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f60c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f60c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f60c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f60c-0x0061f610`; vtable dword data slot; width `4`; value `0x00544e30`; bytes `30 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e30} |
| `0x0061f610-0x0061f614` | `0x0061f610-0x0061f614`; vtable dword data slot; width `4`; value `0x00544e70`; bytes `70 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e70} | `inspect_items({database:DB,addrs:["0x0061f610"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f610",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f610"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f610",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f610",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f610-0x0061f614`; vtable dword data slot; width `4`; value `0x00544e70`; bytes `70 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e70} |

**A0HH-11 quantity tertiary manifest, exact table range `0x0061f618-0x0061f620`**

| Slot/range | Literal current prestate | Inbound xrefs | Outbound xrefs | Exact byte/item/comment/xref readback endpoints | Permitted delta | Exact unchanged poststate |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061f618-0x0061f61c` | `0x0061f618-0x0061f61c`; vtable dword data slot; width `4`; value `0x0047e8e4`; bytes `e4 e8 47 00`; name `??_7ArgumentedItemQuantityInputDialogPane@@6B@_1`; type empty; AR empty; AP empty; FR not applicable; FP not applicable | {code 0x0051fcfc} | {data 0x0047e8e4} | `inspect_items({database:DB,addrs:["0x0061f618"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f618",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f618"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f618",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f618",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f618-0x0061f61c`; vtable dword data slot; width `4`; value `0x0047e8e4`; bytes `e4 e8 47 00`; name `??_7ArgumentedItemQuantityInputDialogPane@@6B@_1`; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound {code 0x0051fcfc}; outbound {data 0x0047e8e4} |
| `0x0061f61c-0x0061f620` | `0x0061f61c-0x0061f620`; vtable dword data slot; width `4`; value `0x00544e90`; bytes `90 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e90} | `inspect_items({database:DB,addrs:["0x0061f61c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f61c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f61c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f61c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f61c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f61c-0x0061f620`; vtable dword data slot; width `4`; value `0x00544e90`; bytes `90 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e90} |

**A0HH-12 confirm primary manifest, exact table range `0x0061f624-0x0061f680`**

| Slot/range | Literal current prestate | Inbound xrefs | Outbound xrefs | Exact byte/item/comment/xref readback endpoints | Permitted delta | Exact unchanged poststate |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061f624-0x0061f628` | `0x0061f624-0x0061f628`; vtable dword data slot; width `4`; value `0x004b0a20`; bytes `20 0a 4b 00`; name `??_7ArgumentedItemConfirmInputDialogPane@@6B@`; type empty; AR empty; AP empty; FR not applicable; FP not applicable | {code 0x00520147} | {data 0x004b0a20} | `inspect_items({database:DB,addrs:["0x0061f624"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f624",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f624"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f624",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f624",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f624-0x0061f628`; vtable dword data slot; width `4`; value `0x004b0a20`; bytes `20 0a 4b 00`; name `??_7ArgumentedItemConfirmInputDialogPane@@6B@`; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound {code 0x00520147}; outbound {data 0x004b0a20} |
| `0x0061f628-0x0061f62c` | `0x0061f628-0x0061f62c`; vtable dword data slot; width `4`; value `0x004f4b10`; bytes `10 4b 4f 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x004f4b10} | `inspect_items({database:DB,addrs:["0x0061f628"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f628",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f628"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f628",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f628",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f628-0x0061f62c`; vtable dword data slot; width `4`; value `0x004f4b10`; bytes `10 4b 4f 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x004f4b10} |
| `0x0061f62c-0x0061f630` | `0x0061f62c-0x0061f630`; vtable dword data slot; width `4`; value `0x0041b6c0`; bytes `c0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041b6c0} | `inspect_items({database:DB,addrs:["0x0061f62c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f62c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f62c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f62c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f62c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f62c-0x0061f630`; vtable dword data slot; width `4`; value `0x0041b6c0`; bytes `c0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041b6c0} |
| `0x0061f630-0x0061f634` | `0x0061f630-0x0061f634`; vtable dword data slot; width `4`; value `0x004b8e20`; bytes `20 8e 4b 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x004b8e20} | `inspect_items({database:DB,addrs:["0x0061f630"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f630",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f630"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f630",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f630",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f630-0x0061f634`; vtable dword data slot; width `4`; value `0x004b8e20`; bytes `20 8e 4b 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x004b8e20} |
| `0x0061f634-0x0061f638` | `0x0061f634-0x0061f638`; vtable dword data slot; width `4`; value `0x0041d680`; bytes `80 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041d680} | `inspect_items({database:DB,addrs:["0x0061f634"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f634",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f634"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f634",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f634",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f634-0x0061f638`; vtable dword data slot; width `4`; value `0x0041d680`; bytes `80 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041d680} |
| `0x0061f638-0x0061f63c` | `0x0061f638-0x0061f63c`; vtable dword data slot; width `4`; value `0x00544730`; bytes `30 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544730} | `inspect_items({database:DB,addrs:["0x0061f638"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f638",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f638"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f638",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f638",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f638-0x0061f63c`; vtable dword data slot; width `4`; value `0x00544730`; bytes `30 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544730} |
| `0x0061f63c-0x0061f640` | `0x0061f63c-0x0061f640`; vtable dword data slot; width `4`; value `0x00544750`; bytes `50 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544750} | `inspect_items({database:DB,addrs:["0x0061f63c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f63c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f63c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f63c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f63c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f63c-0x0061f640`; vtable dword data slot; width `4`; value `0x00544750`; bytes `50 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544750} |
| `0x0061f640-0x0061f644` | `0x0061f640-0x0061f644`; vtable dword data slot; width `4`; value `0x005447a0`; bytes `a0 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x005447a0} | `inspect_items({database:DB,addrs:["0x0061f640"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f640",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f640"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f640",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f640",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f640-0x0061f644`; vtable dword data slot; width `4`; value `0x005447a0`; bytes `a0 47 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x005447a0} |
| `0x0061f644-0x0061f648` | `0x0061f644-0x0061f648`; vtable dword data slot; width `4`; value `0x00544800`; bytes `00 48 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544800} | `inspect_items({database:DB,addrs:["0x0061f644"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f644",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f644"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f644",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f644",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f644-0x0061f648`; vtable dword data slot; width `4`; value `0x00544800`; bytes `00 48 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544800} |
| `0x0061f648-0x0061f64c` | `0x0061f648-0x0061f64c`; vtable dword data slot; width `4`; value `0x00544a20`; bytes `20 4a 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544a20} | `inspect_items({database:DB,addrs:["0x0061f648"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f648",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f648"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f648",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f648",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f648-0x0061f64c`; vtable dword data slot; width `4`; value `0x00544a20`; bytes `20 4a 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544a20} |
| `0x0061f64c-0x0061f650` | `0x0061f64c-0x0061f650`; vtable dword data slot; width `4`; value `0x00544b80`; bytes `80 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544b80} | `inspect_items({database:DB,addrs:["0x0061f64c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f64c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f64c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f64c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f64c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f64c-0x0061f650`; vtable dword data slot; width `4`; value `0x00544b80`; bytes `80 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544b80} |
| `0x0061f650-0x0061f654` | `0x0061f650-0x0061f654`; vtable dword data slot; width `4`; value `0x00544bd0`; bytes `d0 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544bd0} | `inspect_items({database:DB,addrs:["0x0061f650"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f650",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f650"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f650",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f650",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f650-0x0061f654`; vtable dword data slot; width `4`; value `0x00544bd0`; bytes `d0 4b 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544bd0} |
| `0x0061f654-0x0061f658` | `0x0061f654-0x0061f658`; vtable dword data slot; width `4`; value `0x0049dfd0`; bytes `d0 df 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049dfd0} | `inspect_items({database:DB,addrs:["0x0061f654"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f654",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f654"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f654",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f654",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f654-0x0061f658`; vtable dword data slot; width `4`; value `0x0049dfd0`; bytes `d0 df 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049dfd0} |
| `0x0061f658-0x0061f65c` | `0x0061f658-0x0061f65c`; vtable dword data slot; width `4`; value `0x00544cb0`; bytes `b0 4c 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544cb0} | `inspect_items({database:DB,addrs:["0x0061f658"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f658",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f658"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f658",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f658",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f658-0x0061f65c`; vtable dword data slot; width `4`; value `0x00544cb0`; bytes `b0 4c 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544cb0} |
| `0x0061f65c-0x0061f660` | `0x0061f65c-0x0061f660`; vtable dword data slot; width `4`; value `0x0049e1c0`; bytes `c0 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e1c0} | `inspect_items({database:DB,addrs:["0x0061f65c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f65c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f65c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f65c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f65c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f65c-0x0061f660`; vtable dword data slot; width `4`; value `0x0049e1c0`; bytes `c0 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e1c0} |
| `0x0061f660-0x0061f664` | `0x0061f660-0x0061f664`; vtable dword data slot; width `4`; value `0x0049e190`; bytes `90 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e190} | `inspect_items({database:DB,addrs:["0x0061f660"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f660",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f660"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f660",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f660",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f660-0x0061f664`; vtable dword data slot; width `4`; value `0x0049e190`; bytes `90 e1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e190} |
| `0x0061f664-0x0061f668` | `0x0061f664-0x0061f668`; vtable dword data slot; width `4`; value `0x0049e210`; bytes `10 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e210} | `inspect_items({database:DB,addrs:["0x0061f664"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f664",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f664"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f664",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f664",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f664-0x0061f668`; vtable dword data slot; width `4`; value `0x0049e210`; bytes `10 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e210} |
| `0x0061f668-0x0061f66c` | `0x0061f668-0x0061f66c`; vtable dword data slot; width `4`; value `0x0049f090`; bytes `90 f0 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049f090} | `inspect_items({database:DB,addrs:["0x0061f668"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f668",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f668"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f668",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f668",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f668-0x0061f66c`; vtable dword data slot; width `4`; value `0x0049f090`; bytes `90 f0 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049f090} |
| `0x0061f66c-0x0061f670` | `0x0061f66c-0x0061f670`; vtable dword data slot; width `4`; value `0x005203c0`; bytes `c0 03 52 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x005203c0} | `inspect_items({database:DB,addrs:["0x0061f66c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f66c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f66c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f66c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f66c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f66c-0x0061f670`; vtable dword data slot; width `4`; value `0x005203c0`; bytes `c0 03 52 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x005203c0} |
| `0x0061f670-0x0061f674` | `0x0061f670-0x0061f674`; vtable dword data slot; width `4`; value `0x0041b6a0`; bytes `a0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041b6a0} | `inspect_items({database:DB,addrs:["0x0061f670"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f670",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f670"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f670",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f670",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f670-0x0061f674`; vtable dword data slot; width `4`; value `0x0041b6a0`; bytes `a0 b6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041b6a0} |
| `0x0061f674-0x0061f678` | `0x0061f674-0x0061f678`; vtable dword data slot; width `4`; value `0x0049f1d0`; bytes `d0 f1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049f1d0} | `inspect_items({database:DB,addrs:["0x0061f674"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f674",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f674"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f674",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f674",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f674-0x0061f678`; vtable dword data slot; width `4`; value `0x0049f1d0`; bytes `d0 f1 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049f1d0} |
| `0x0061f678-0x0061f67c` | `0x0061f678-0x0061f67c`; vtable dword data slot; width `4`; value `0x0049f2e0`; bytes `e0 f2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049f2e0} | `inspect_items({database:DB,addrs:["0x0061f678"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f678",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f678"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f678",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f678",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f678-0x0061f67c`; vtable dword data slot; width `4`; value `0x0049f2e0`; bytes `e0 f2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049f2e0} |
| `0x0061f67c-0x0061f680` | `0x0061f67c-0x0061f680`; vtable dword data slot; width `4`; value `0x0049fc00`; bytes `00 fc 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049fc00} | `inspect_items({database:DB,addrs:["0x0061f67c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f67c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f67c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f67c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f67c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f67c-0x0061f680`; vtable dword data slot; width `4`; value `0x0049fc00`; bytes `00 fc 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049fc00} |

**A0HH-13 confirm secondary manifest, exact table range `0x0061f684-0x0061f6b0`**

| Slot/range | Literal current prestate | Inbound xrefs | Outbound xrefs | Exact byte/item/comment/xref readback endpoints | Permitted delta | Exact unchanged poststate |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061f684-0x0061f688` | `0x0061f684-0x0061f688`; vtable dword data slot; width `4`; value `0x004b08e3`; bytes `e3 08 4b 00`; name `??_7ArgumentedItemConfirmInputDialogPane@@6B@_0`; type empty; AR empty; AP empty; FR not applicable; FP not applicable | {code 0x0052014d} | {data 0x004b08e3} | `inspect_items({database:DB,addrs:["0x0061f684"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f684",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f684"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f684",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f684",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f684-0x0061f688`; vtable dword data slot; width `4`; value `0x004b08e3`; bytes `e3 08 4b 00`; name `??_7ArgumentedItemConfirmInputDialogPane@@6B@_0`; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound {code 0x0052014d}; outbound {data 0x004b08e3} |
| `0x0061f688-0x0061f68c` | `0x0061f688-0x0061f68c`; vtable dword data slot; width `4`; value `0x0049e240`; bytes `40 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e240} | `inspect_items({database:DB,addrs:["0x0061f688"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f688",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f688"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f688",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f688",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f688-0x0061f68c`; vtable dword data slot; width `4`; value `0x0049e240`; bytes `40 e2 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e240} |
| `0x0061f68c-0x0061f690` | `0x0061f68c-0x0061f690`; vtable dword data slot; width `4`; value `0x0049e6e0`; bytes `e0 e6 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049e6e0} | `inspect_items({database:DB,addrs:["0x0061f68c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f68c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f68c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f68c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f68c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f68c-0x0061f690`; vtable dword data slot; width `4`; value `0x0049e6e0`; bytes `e0 e6 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049e6e0} |
| `0x0061f690-0x0061f694` | `0x0061f690-0x0061f694`; vtable dword data slot; width `4`; value `0x0049ea60`; bytes `60 ea 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0049ea60} | `inspect_items({database:DB,addrs:["0x0061f690"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f690",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f690"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f690",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f690",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f690-0x0061f694`; vtable dword data slot; width `4`; value `0x0049ea60`; bytes `60 ea 49 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0049ea60} |
| `0x0061f694-0x0061f698` | `0x0061f694-0x0061f698`; vtable dword data slot; width `4`; value `0x0041d6b0`; bytes `b0 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0041d6b0} | `inspect_items({database:DB,addrs:["0x0061f694"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f694",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f694"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f694",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f694",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f694-0x0061f698`; vtable dword data slot; width `4`; value `0x0041d6b0`; bytes `b0 d6 41 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0041d6b0} |
| `0x0061f698-0x0061f69c` | `0x0061f698-0x0061f69c`; vtable dword data slot; width `4`; value `0x00544df0`; bytes `f0 4d 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544df0} | `inspect_items({database:DB,addrs:["0x0061f698"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f698",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f698"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f698",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f698",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f698-0x0061f69c`; vtable dword data slot; width `4`; value `0x00544df0`; bytes `f0 4d 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544df0} |
| `0x0061f69c-0x0061f6a0` | `0x0061f69c-0x0061f6a0`; vtable dword data slot; width `4`; value `0x00544e00`; bytes `00 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e00} | `inspect_items({database:DB,addrs:["0x0061f69c"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f69c",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f69c"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f69c",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f69c",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f69c-0x0061f6a0`; vtable dword data slot; width `4`; value `0x00544e00`; bytes `00 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e00} |
| `0x0061f6a0-0x0061f6a4` | `0x0061f6a0-0x0061f6a4`; vtable dword data slot; width `4`; value `0x004a89f0`; bytes `f0 89 4a 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x004a89f0} | `inspect_items({database:DB,addrs:["0x0061f6a0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f6a0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f6a0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f6a0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f6a0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f6a0-0x0061f6a4`; vtable dword data slot; width `4`; value `0x004a89f0`; bytes `f0 89 4a 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x004a89f0} |
| `0x0061f6a4-0x0061f6a8` | `0x0061f6a4-0x0061f6a8`; vtable dword data slot; width `4`; value `0x00544e10`; bytes `10 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e10} | `inspect_items({database:DB,addrs:["0x0061f6a4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f6a4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f6a4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f6a4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f6a4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f6a4-0x0061f6a8`; vtable dword data slot; width `4`; value `0x00544e10`; bytes `10 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e10} |
| `0x0061f6a8-0x0061f6ac` | `0x0061f6a8-0x0061f6ac`; vtable dword data slot; width `4`; value `0x00544e30`; bytes `30 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e30} | `inspect_items({database:DB,addrs:["0x0061f6a8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f6a8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f6a8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f6a8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f6a8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f6a8-0x0061f6ac`; vtable dword data slot; width `4`; value `0x00544e30`; bytes `30 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e30} |
| `0x0061f6ac-0x0061f6b0` | `0x0061f6ac-0x0061f6b0`; vtable dword data slot; width `4`; value `0x00544e70`; bytes `70 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e70} | `inspect_items({database:DB,addrs:["0x0061f6ac"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f6ac",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f6ac"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f6ac",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f6ac",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f6ac-0x0061f6b0`; vtable dword data slot; width `4`; value `0x00544e70`; bytes `70 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e70} |

**A0HH-14 confirm tertiary manifest, exact table range `0x0061f6b4-0x0061f6bc`**

| Slot/range | Literal current prestate | Inbound xrefs | Outbound xrefs | Exact byte/item/comment/xref readback endpoints | Permitted delta | Exact unchanged poststate |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061f6b4-0x0061f6b8` | `0x0061f6b4-0x0061f6b8`; vtable dword data slot; width `4`; value `0x004b08ee`; bytes `ee 08 4b 00`; name `??_7ArgumentedItemConfirmInputDialogPane@@6B@_1`; type empty; AR empty; AP empty; FR not applicable; FP not applicable | {code 0x00520157} | {data 0x004b08ee} | `inspect_items({database:DB,addrs:["0x0061f6b4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f6b4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f6b4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f6b4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f6b4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f6b4-0x0061f6b8`; vtable dword data slot; width `4`; value `0x004b08ee`; bytes `ee 08 4b 00`; name `??_7ArgumentedItemConfirmInputDialogPane@@6B@_1`; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound {code 0x00520157}; outbound {data 0x004b08ee} |
| `0x0061f6b8-0x0061f6bc` | `0x0061f6b8-0x0061f6bc`; vtable dword data slot; width `4`; value `0x00544e90`; bytes `90 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x00544e90} | `inspect_items({database:DB,addrs:["0x0061f6b8"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f6b8",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f6b8"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f6b8",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f6b8",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f6b8-0x0061f6bc`; vtable dword data slot; width `4`; value `0x00544e90`; bytes `90 4e 54 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x00544e90} |

**A0HH-15 through A0HH-20 literal COL-cell protection manifests**

| Bound manifest | Cell/range | Literal current prestate | Inbound xrefs | Outbound xrefs | Exact byte/item/comment/xref readback endpoints | Permitted delta | Exact unchanged poststate |
| --- | --- | --- | --- | --- | --- | --- | --- |
| COL15 bound to A0HH-15 | `0x0061f584-0x0061f588` | `0x0061f584-0x0061f588`; COL-pointer dword data item; width `4`; value `0x0064bf18`; bytes `18 bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0064bf18} | `inspect_items({database:DB,addrs:["0x0061f584"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f584",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f584"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f584",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f584",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f584-0x0061f588`; COL-pointer dword data item; width `4`; value `0x0064bf18`; bytes `18 bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0064bf18} |
| COL16 bound to A0HH-16 | `0x0061f5e4-0x0061f5e8` | `0x0061f5e4-0x0061f5e8`; COL-pointer dword data item; width `4`; value `0x0064bf78`; bytes `78 bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0064bf78} | `inspect_items({database:DB,addrs:["0x0061f5e4"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f5e4",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f5e4"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f5e4",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f5e4",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f5e4-0x0061f5e8`; COL-pointer dword data item; width `4`; value `0x0064bf78`; bytes `78 bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0064bf78} |
| COL17 bound to A0HH-17 | `0x0061f614-0x0061f618` | `0x0061f614-0x0061f618`; COL-pointer dword data item; width `4`; value `0x0064bf8c`; bytes `8c bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0064bf8c} | `inspect_items({database:DB,addrs:["0x0061f614"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f614",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f614"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f614",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f614",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f614-0x0061f618`; COL-pointer dword data item; width `4`; value `0x0064bf8c`; bytes `8c bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0064bf8c} |
| COL18 bound to A0HH-18 | `0x0061f620-0x0061f624` | `0x0061f620-0x0061f624`; COL-pointer dword data item; width `4`; value `0x0064bfa0`; bytes `a0 bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0064bfa0} | `inspect_items({database:DB,addrs:["0x0061f620"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f620",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f620"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f620",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f620",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f620-0x0061f624`; COL-pointer dword data item; width `4`; value `0x0064bfa0`; bytes `a0 bf 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0064bfa0} |
| COL19 bound to A0HH-19 | `0x0061f680-0x0061f684` | `0x0061f680-0x0061f684`; COL-pointer dword data item; width `4`; value `0x0064c000`; bytes `00 c0 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0064c000} | `inspect_items({database:DB,addrs:["0x0061f680"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f680",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f680"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f680",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f680",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f680-0x0061f684`; COL-pointer dword data item; width `4`; value `0x0064c000`; bytes `00 c0 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0064c000} |
| COL20 bound to A0HH-20 | `0x0061f6b0-0x0061f6b4` | `0x0061f6b0-0x0061f6b4`; COL-pointer dword data item; width `4`; value `0x0064c014`; bytes `14 c0 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable | empty | {data 0x0064c014} | `inspect_items({database:DB,addrs:["0x0061f6b0"]})`; `get_bytes({database:DB,regions:[{addr:"0x0061f6b0",size:4}]})`; `get_comments({database:DB,addrs:["0x0061f6b0"]})`; `xref_query({database:DB,queries:[{addr:"0x0061f6b0",direction:"to",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false},{addr:"0x0061f6b0",direction:"from",xref_type:"any",offset:0,count:200,include_fn:true,dedup:true,sort_by:"addr",descending:false}]})` | none | unchanged `0x0061f6b0-0x0061f6b4`; COL-pointer dword data item; width `4`; value `0x0064c014`; bytes `14 c0 64 00`; name empty; type empty; AR empty; AP empty; FR not applicable; FP not applicable; inbound empty; outbound {data 0x0064c014} |

For A0HH-09 through A0HH-20, `inspect_items` must reproduce the literal item/range/kind/width/value/name/type state, `get_bytes` must reproduce the four literal bytes, `get_comments` must reproduce independent AR/AP with FR/FP not applicable to these data addresses, and the paired terminal `xref_query` calls must reproduce the literal inbound/outbound sets before any later stage may proceed.

There are exactly 23 atomic recommendation/protection rows: eight apply rows (four pure function renames and four regular function comments), twelve protected data entities, and three protected absent named types. Each apply row requires its own precheck and immediate readback before the next row. No stack/local/type mutation is recommended; formal source supplies human names without an unsafe partial IDA type package.

## First-Draft C++ Recommendation

- Eligible: all four methods and both class declarations. Compiler-covered items receive markers only.
- Source standard: behaviorally exact, period-compatible C++03 shape, `NULL`, explicit `virtual`, no `override`, no decompiler labels, and consistent project `m_`/`g_` naming.

Formal UID0001BT aggregate CPP replacement:

```cpp
// Exact method definitions for this aggregate are emitted by the
// ArgumentedItemQuantityInputDialogPane and
// ArgumentedItemConfirmInputDialogPane class-owned children below.
// Do not emit a monolithic body for [0x0051fc90,0x00520539).
```

Formal UID00000G CPP insertion:

```cpp
#include "ArgumentedItemInputDialogs.h"

#include "AlertPanes.h"
#include "ArgumentedMenuDialogs.h"
#include "../MainUiGraph.h"
#include "../controls/ButtonControlPane.h"
#include "../controls/EPFImageControlPane.h"
#include "../controls/StaticTextControlPane.h"
#include "../controls/TextEditControlPane.h"
#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"

#include <wchar.h>

namespace
{
enum
{
    kConfirmControlIndex = 1,
    kCancelControlIndex = 2,
    kTextEditControlIndex = 4,
    kConfirmButtonId = 14,
    kCancelButtonId = 22,
    kMaximumPurchaseQuantity = 100,
    kQuantityPromptStringId = 246
};
}

[[CHILDREN]]
```

Formal UID00000G H insertion:

```h
#pragma once

#include "../core/DialogPane.h"

class ArgumentedMenuMenuItemList;

class ArgumentedItemQuantityInputDialogPane : public DialogPane
{
public:
    ArgumentedItemQuantityInputDialogPane(
        const wchar_t *promptText,
        ArgumentedMenuMenuItemList *menuContext,
        unsigned int argumentId);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    ArgumentedMenuMenuItemList *m_menuContext;
    unsigned int m_argumentId;
};
```

Formal quantity constructor child CPP:

```cpp
ArgumentedItemQuantityInputDialogPane::ArgumentedItemQuantityInputDialogPane(
    const wchar_t *promptText,
    ArgumentedMenuMenuItemList *menuContext,
    unsigned int argumentId)
    : DialogPane(L"ArgumentQuantity", 0x13, 1)
{
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(
        L"DLGEXC3.EPF", 0, 1, &bounds, L"PAL01.PAL"));

    InitRectBounds(&bounds, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(kConfirmButtonId, &bounds));

    InitRectBounds(&bounds, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(kCancelButtonId, &bounds));

    InitRectBounds(&bounds, 30, 60, 197, 72);
    AddControl(new StaticTextControlPane(
        promptText, false, 128, 0, &bounds, false, false));

    InitRectBounds(&bounds, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(
        L"", true, 143, 0, &bounds,
        false, false, false, false, 1.0f, false));

    SetBackgroundResource(L"DLGEXC3.EPF", 0);
    SetFocusedControl(kConfirmControlIndex);
    SetPendingControl(kCancelControlIndex);
    SetHoverControl(kTextEditControlIndex);

    m_menuContext = new ArgumentedMenuMenuItemList(*menuContext);
    m_argumentId = argumentId;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}
```

Formal quantity action child CPP:

```cpp
void ArgumentedItemQuantityInputDialogPane::OnControlCommand(
    int controlIndex,
    int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == kConfirmControlIndex) {
        if (m_menuContext != NULL) {
            wchar_t quantityText[128];
            int quantity = 0;
            TextEditControlPane *quantityEdit =
                GetChild<TextEditControlPane>(kTextEditControlIndex);

            quantityEdit->ReadText(quantityText, 128);
            swscanf(quantityText, L"%d", &quantity);

            if (static_cast<unsigned int>(quantity) >
                kMaximumPurchaseQuantity) {
                new AlertPane(
                    L"You can't buy more than 100.", this, L"OK", NULL);
            } else if (quantity == 0) {
                new AlertPane(L"How much?", this, L"OK", NULL);
            } else {
                m_menuContext->SendArgumentedItemQuantityPacket(
                    m_argumentId,
                    static_cast<unsigned char>(quantity));
            }
        }

        SlideCloseVertical();
        CloseDialog();
        return;
    }

    if (controlIndex == kCancelControlIndex) {
        SlideCloseVertical();
        CloseDialog();
    }
}
```

Formal UID00000F CPP insertion:

```cpp
[[CHILDREN]]
```

Formal UID00000F H insertion:

```h
class ArgumentedItemConfirmInputDialogPane : public DialogPane
{
public:
    ArgumentedItemConfirmInputDialogPane(
        const wchar_t *promptText,
        ArgumentedMenuMenuItemList *menuContext,
        unsigned int maxQuantity,
        unsigned int expectedPrice,
        unsigned int argumentId);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    ArgumentedMenuMenuItemList *m_menuContext;
    unsigned int m_maxQuantity;
    unsigned int m_expectedPrice;
    unsigned int m_argumentId;
};
```

Formal confirm constructor child CPP:

```cpp
ArgumentedItemConfirmInputDialogPane::ArgumentedItemConfirmInputDialogPane(
    const wchar_t *promptText,
    ArgumentedMenuMenuItemList *menuContext,
    unsigned int maxQuantity,
    unsigned int expectedPrice,
    unsigned int argumentId)
    : DialogPane(L"ArgumentQuantity", 0x13, 1)
{
    RectBounds bounds;

    m_maxQuantity = maxQuantity;
    m_expectedPrice = expectedPrice;
    m_argumentId = argumentId;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(
        L"DLGEXC3.EPF", 0, 1, &bounds, L"PAL01.PAL"));

    InitRectBounds(&bounds, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(kConfirmButtonId, &bounds));

    InitRectBounds(&bounds, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(kCancelButtonId, &bounds));

    InitRectBounds(&bounds, 30, 45, 210, 81);
    AddControl(new StaticTextControlPane(
        promptText, false, 128, 0, &bounds, false, false));

    InitRectBounds(&bounds, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(
        L"", true, 143, 0, &bounds,
        false, false, false, false, 1.0f, false));

    SetBackgroundResource(L"DLGEXC3.EPF", 0);
    SetFocusedControl(kConfirmControlIndex);
    SetPendingControl(kCancelControlIndex);
    SetHoverControl(kTextEditControlIndex);

    m_menuContext = new ArgumentedMenuMenuItemList(*menuContext);

    InitRectBounds(&bounds, 0, 0, 239, 283);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}
```

Formal confirm action child CPP:

```cpp
void ArgumentedItemConfirmInputDialogPane::OnControlCommand(
    int controlIndex,
    int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == kConfirmControlIndex) {
        if (m_menuContext == NULL)
            return;

        wchar_t priceText[128];
        int enteredPrice = 0;
        TextEditControlPane *priceEdit =
            GetChild<TextEditControlPane>(kTextEditControlIndex);

        priceEdit->ReadText(priceText, 128);
        swscanf(priceText, L"%d", &enteredPrice);

        if (static_cast<unsigned int>(enteredPrice) != m_expectedPrice) {
            new AlertPane(L"Price is different.", this, L"OK", NULL);
            return;
        }

        if (m_maxQuantity <= 1) {
            m_menuContext->SendArgumentedItemQuantityPacket(m_argumentId, 1);
        } else {
            new ArgumentedItemQuantityInputDialogPane(
                g_pLanguageMan->GetLocalizedString(kQuantityPromptStringId),
                m_menuContext,
                m_argumentId);
        }

        SlideCloseVertical();
        CloseDialog();
        return;
    }

    if (controlIndex == kCancelControlIndex) {
        SlideCloseVertical();
        CloseDialog();
    }
}
```

Formal new vtable-data child CPP marker:

```cpp
// ArgumentedItemQuantityInputDialogPane and
// ArgumentedItemConfirmInputDialogPane vtables, RTTI, deleting-destructor
// wrappers, and adjustor thunks are generated by the class declarations and
// compiler. Do not emit raw ABI arrays for [0x0061f584,0x0061f6bc).
```

Formal new literal child CPP marker:

```cpp
// [0x0061f99c,0x0061fa3c) is covered by the source literals in the exact
// constructor and OnControlCommand definitions. Do not emit duplicate arrays.
```

Formal UID00000H CPP replacement, moving the class shell out of CPP and establishing the real sibling-header route:

```cpp
#include "ArgumentedMenuDialogs.h"
#include "ArgumentedItemInputDialogs.h"

[[CHILDREN]]
```

Formal UID00000H H replacement at ArgumentedMenuDialogs source position 10:

```h
#pragma once

#include "MerchantDialogPane.h"
#include "../controls/ListPane.h"

class ArgumentedMenuMenuItemList;

class ArgumentedMenuMenuDialog : public MerchantDialogPane
{
public:
    ArgumentedMenuMenuDialog(const RectBounds &bounds,
                             const unsigned char *payload,
                             unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    ArgumentedMenuMenuItemList *GetArgumentedMenuList(int controlIndex) const;

    unsigned int m_ownerId;
    unsigned char m_commandType;
};
```

Formal UID00000I CPP replacement at ArgumentedMenuDialogs source position 20:

```cpp
[[CHILDREN]]
```

Formal UID00000I H replacement appended to `ArgumentedMenuDialogs.h`. This is complete for the exact `0x410` row, exact `0x15c` list-context layout, both current source constructors, the source-visible input-dialog dependency, and the current dialog/list call surface:

```h
class ArgumentedItemQuantityInputDialogPane;
class ArgumentedItemConfirmInputDialogPane;

struct ArgumentedMenuItemEntry
{
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned int price;
    wchar_t name[0x100];
    wchar_t description[0x100];
    unsigned int argumentId;
    unsigned int maxQuantity;
};

class ArgumentedMenuMenuItemList : public ListPane
{
public:
    ArgumentedMenuMenuItemList(
        unsigned char commandType,
        unsigned int ownerId,
        unsigned short listParameter,
        ArgumentedMenuMenuDialog *ownerDialog);
    ArgumentedMenuMenuItemList(
        const ArgumentedMenuMenuItemList &source);
    virtual ~ArgumentedMenuMenuItemList();

    void AppendItem(unsigned short itemId,
                    unsigned char itemStyle,
                    unsigned int price,
                    const wchar_t *name,
                    const wchar_t *description,
                    unsigned int argumentId,
                    unsigned char maxQuantity);
    const ArgumentedMenuItemEntry *GetSelectedEntry() const;

private:
    friend class ArgumentedItemQuantityInputDialogPane;
    friend class ArgumentedItemConfirmInputDialogPane;

    void OpenBuyConfirmDialog();
    void OpenQuantityDialogOrSendSingle();
    void SendArgumentedItemQuantityPacket(
        unsigned int argumentId,
        unsigned char quantity);

    unsigned char m_commandType;
    unsigned int m_ownerId;
    unsigned short m_listParameter;
    ArgumentedMenuMenuDialog *m_ownerDialog;
};
```

UID0003VH support correction: remove its duplicate namespace-scope `ArgumentedMenuItemEntry` definition from the child CPP and preserve the existing `ArgumentedMenuMenuItemList::AppendItem(...)` method body unchanged; the type now has one declaration in `ArgumentedMenuDialogs.h`.

Formal UID0000E3 CPP replacement at StaticTextControlPane source position 10:

```cpp
#include "StaticTextControlPane.h"
#include "TextEditPane.h"

[[CHILDREN]]
```

Formal UID0000E3 H replacement that creates the previously absent `StaticTextControlPane.h` source route. Natural C++ alignment places the fields at `+0x108`, `+0x10c`, and `+0x110` and closes the IDA-proven `0x114` allocation without explicit reverse-engineering padding members:

```h
#pragma once

#include "../core/ControlPane.h"

class TextEditPane;

class StaticTextControlPane : public ControlPane
{
public:
    StaticTextControlPane(const wchar_t *text,
                          bool useAlternateStyle,
                          int textColor,
                          int shadowColor,
                          const RectBounds *bounds,
                          bool useWideContentWidth,
                          bool inputMode);

    virtual unsigned char GetControlType(int, int);

private:
    unsigned short m_textStateFlags;
    TextEditPane *m_textEditPane;
    unsigned char m_savedTextPaneState;
};
```

Formal UID000222 CPP insertion required by that declaration and its exact `mov al,13h; retn 8` body:

```cpp
unsigned char StaticTextControlPane::GetControlType(int, int)
{
    return 19;
}
```

Dependency closure is exact rather than consumer-local: `ImageButtonControlPane` is obtained from existing `../controls/ButtonControlPane.h`; no `ImageButtonControlPane.h` was created. `EPFImageControlPane`, `TextEditControlPane`, DialogPane, AlertPane, MainUiGraph, BackPane, and LanguageMan use their existing headers. The callback validated UID0000HI/00000H/00000I/0003VH and UID0000O8/0000E3/000222 in addition to the target pages, then physically verified generated `ArgumentedMenuDialogs.h` and `StaticTextControlPane.h`.

- Runtime fidelity: branch ordering, unsigned comparison, initialized parse values, close/no-close paths, object sizes, field order, control geometry, prompt id, resources, parent/layer calls, and packet-helper receiver are preserved.
- Human source shape: ordinary constructors/virtual methods/class declarations regenerate compiler artifacts. No raw offsets, register parameters, vtable arrays, manual deleting wrappers, or IDA names remain.
- Third-party import: not applicable; this is first-party NexusTK client code.

## Final Recommendation

- Ordinary claims C0HH-001..040, C0HH-057..061, C0HH-063, and C0HH-064 are callback-applied and physically verified. Coverage C0HH-052..056, IDA C0HH-041..051, boundary C0HH-062, and lifecycle remain supervisor-owned.
- Declared UID dispositions:
  - UID0000HH becomes complete file owner at `93/94`.
  - UID0001BT becomes exact aggregate/index at `92/94`, position 10, no broad body.
  - UID00000G and UID00000F become complete class declaration/child routes at `92/94`, positions 20/30.
- Exact callback-created pages: four method children UID000554/000555/000557/000558, two layouts UID000556/000559, vtable data UID00055A, vtable type UID00055C, literal UID00055B, and resource UID00055D.
- Items left non-emitting/no-owner: shared wrapper/thunk pages and mixed UID00025U, because compiler/class declarations or exact children cover their source effect.
- Ordinary source implementation is callback-closed through exact method/layout/data/type/resource pages, complete support H routes, scoped validation, and physical coherent generated CPP/H readback. Manual coverage and IDA closure remain supervisor-owned.

## Recommended Target Doc Changes

- `by-file/ArgumentedItemInputDialogs.md`: callback-applied complete inventory, standalone decision, formal output plan, exact behavior/layout/vtable/resource/dependency facts, historical B008/B001 reconciliation, generated criteria, and `93/94` score.
- `by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md`: callback-applied `92/94`, position 10, owner/emitter UID0000HH, no-duplicate route marker, exact UID000554/000555/000557/000558 children, boundaries, and history.
- `by-class/ArgumentedItemQuantityInputDialogPane.md`: callback-applied `92/94`, position 20, formal CPP/H, exact 0x274 layout, methods, resources, RTTI, implicit destructor, and child links.
- `by-class/ArgumentedItemConfirmInputDialogPane.md`: callback-applied `92/94`, position 30, formal CPP/H, exact 0x27c layout, methods, resources, RTTI, implicit destructor, and child links.
- Historical material must remain in explicitly dated/superseded sections: folded source possibility, `OnAction`, unresolved fields/signatures, broad aggregate emission, no-xref-as-C++-blocker, and B008 limited-callback boundary.

## Recommended Support Doc Changes

- Callback-created the four exact method pages with complete decompile/disassembly facts, CPP bodies, class owner/emitter, positions, scores, item summaries, and boundaries.
- Callback-created UID00055A and UID00055C; all six table cells/slots, six COLs, two CHDs/seven-base graphs, stores, folded destructors, and ObjectImage successor are documented without raw ABI emission.
- Callback-created UID000556 and UID000559 with exact bases/sizes/tails and no invented padding fields.
- Callback-created UID00055B and UID00055D, distinguishing owned literals from shared DLGEXC3/PAL01/%d/OK/localization resources.
- UID00025U now links exact vtable/literal children and retains mixed non-emitting status.
- UID0000HI/UID00000H/UID00000I now provide the complete `ArgumentedMenuDialogs.h` route, including the source include, exact list-context declaration, copy constructor, packet/helper declarations, friend access, natural fields, and retained helper-body ownership in `ArgumentedMenuDialogs.cpp`.
- UID0003VH retains the accepted append body without the former duplicate consumer-local `ArgumentedMenuItemEntry` declaration; UID00000I is the single H owner.
- UID0000O8/UID0000E3/UID000222 now route and emit complete `StaticTextControlPane.h` declaration/source children and preserve the exact type-id-19 body.
- Existing `ButtonControlPane.h`: use its current `ImageButtonControlPane` declaration; do not create or include nonexistent `ImageButtonControlPane.h`.
- UID0003VF now has exact copy-constructor source eligibility and input callers.
- UID0003VI/VJ/VL now have source-ready private helper/packet-method dispositions and formal definitions under UID00000I while preserving zero-xref facts.
- UID0000TY retains its non-emitting index and records resolved source names.
- UID0003Q5 and `DialogAndAlertDestructorAdjustorThunks` record quantity class folded-wrapper consumers.
- UID00033Y now records shared ExchangeDialog/ArgumentedItemConfirmInputDialogPane compiler folding for `0x4b08e3-0x4b08f9` and `0x4b0a20-0x4b0a5b`.
- UID000320/UID0001Y5 link the exact successor input-vtable child while retaining argumented-menu ownership boundaries.
- UID0000VN: no edit required; its existing ignored-padding authority already preserves all five spans and remains evidence-only.
- Existing DialogPane, BackPane, LanguageMan, MainUiGraph, EPFImageControlPane, ButtonControlPane/ImageButtonControlPane, TextEditControlPane, AlertPane, packet sender, and shared resource pages require no edit in this callback. Their current declarations/ownership are compile dependencies only and must not be reowned or changed speculatively.

## Score And Metadata Recommendation

| Page | Historical pre-callback | Callback-applied | Metadata |
| --- | --- | --- | --- |
| UID0000HH | 86/89 | 93/94 | retained path and FILE owner; reconstructable ordinary route |
| UID0001BT | 88/91 | 92/94 | owner/emitter 0000HH; reconstructable true; position 10; no-duplicate marker |
| UID00000G | 86/90 | 92/94 | owner/emitter 0000HH; reconstructable true; position 20; formal CPP/H |
| UID00000F | 86/90 | 92/94 | owner/emitter 0000HH; reconstructable true; position 30; formal CPP/H |
| UID000554/000555/000557/000558 | absent | constructors 92/94; actions 93/94 | owner/emitter direct class; positions 10/20 |
| UID00055A/00055C | absent | 92/95 | declaration-generated markers; no raw arrays |
| UID000556/000559 | absent | 92/94 | direct class ownership; non-duplicating evidence pages |
| UID00055B/00055D | absent | 92/95 and 91/94 | source-covered literals/resource index; no duplicate arrays |
| UID00025U | 86/92 | retain 86/92 | none/non-reconstructable/non-emitting; link children |

- Reason not higher: original file/access/identifier spellings remain inferred; manual coverage and IDA remain supervisor-owned; and rebuilt compilation/binary comparison is absent. The support-header and ten-page ordinary payloads, scoped validators, and coherent generated reread are callback-complete and are no longer score blockers.
- Reason not lower: every method, branch, field, virtual slot, table, RTTI graph, resource, caller, boundary, compiler artifact, dependency, and rejected owner is identified with current evidence and formal source.
- Score improvement attempts: source split resolved by dual code/data boundaries; names by slot/RTTI/collision checks; fields by sizes/stores/reads; helpers by row/context/body graph despite zero xrefs; destructor by shared wrapper inspection; output by exact CPP/H plan.

## Open Questions With Attempted Resolution

- Original physical filename: no symbol/PDB/string proves it. Code/vtable transitions and current tree make standalone highly probable; select it and cap confidence rather than defer.
- Exact original class-field/helper spellings: no symbols survive. The selected names are descriptive, type/offset exact, and consistent with project style. Raw IDA names are forbidden.
- Private versus public list helper access: call graph shows tight two-class coupling but no source access metadata. Private methods with two friend classes best preserve encapsulation and direct binary calls; use that implementation direction.
- Constness of copied list parameter: body reads source but historical code style and callers use mutable pointers. Use non-const pointer in dialog constructors and conventional `const &` in the copy constructor declaration; runtime unaffected.
- Why no destructor cleanup: binary proves none. The leak/raw snapshot lifetime is preserved intentionally, not left unanswered.
- Weak helper reachability: all current xref and historical pointer/rel32 routes are exhausted. Exact source-shaped bodies justify retention; no stronger runtime reachability proof is available in static IDB, so this caps helper confidence only.
- Complete control/header availability: dated command `000000025350` lacked `ArgumentedMenuDialogs.h`, `StaticTextControlPane.h`, and the target H. The callback applied the exact owner payloads; command-25458 physical reread verified all three H routes without consumer-local partial classes.
- No unresolved evidence question blocks the source shape, ownership, child pages, or scores. Ordinary implementation and generated readback are complete; manual coverage and IDA remain supervisor-owned.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Dated report-research rows inspected and exact supervisor-owned replacement payloads:

- `by-file/-coverage-report.md` replace UID0000HH row with:
  `- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) : reconstructable : 93% : very-strong : Standalone NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp/.h owner with four exact class-owned constructor/control-command children, complete quantity/confirm layouts, six vtable views/two RTTI graphs, exact resource literals, ArgumentedMenuMenuItemList dependency boundary, formal CPP/H, and generated empty-marker closure.`
- `by-memory/-coverage-report.md` replace UID0001BT row with:
  `    - [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md) : reconstructable : 92% : very-strong : Exact four-method argumented-item input-dialog aggregate/index; method bodies emit through class-owned exact children, boundaries/padding/ObjectImage successor are closed, and no monolithic body duplicates class source.`
- `by-class/-coverage-report.md` replace UID00000G row with:
  `- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md) : reconstructable : 92% : very-strong : Complete 0x274 DialogPane-derived quantity prompt with exact constructor and OnControlCommand children, copied list context, argument id, unsigned 1..100 validation, exact alert/send/close behavior, three-view RTTI/vtables, implicit-destructor disposition, and formal CPP/H.`
- `by-class/-coverage-report.md` replace UID00000F row with:
  `- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md) : reconstructable : 92% : very-strong : Complete 0x27c DialogPane-derived price-confirm prompt with exact constructor and OnControlCommand children, copied list context, max/price/argument fields, mismatch-open and send-or-quantity behavior, three-view RTTI/vtables, implicit-destructor disposition, and formal CPP/H.`
- `by-memory/-coverage-report.md`, insert immediately after UID0001BT in executable address order:
  `        - [UID:000554][0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor](by-memory/0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor.md) 0x0051fc90-0x0051ff6c | function | ArgumentedItemQuantityInputDialogPaneConstructor : reconstructable : 92% : very-strong : Exact quantity-dialog constructor body; direct owner/emitter UID00000G at position 10; 0x274 object layout, copied ArgumentedMenuMenuItemList context, control construction, resources, vptr transitions, callers, padding boundary, and formal human C++ are closed.`
- `by-memory/-coverage-report.md`, insert immediately after the preceding constructor row:
  `        - [UID:000555][0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand](by-memory/0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand.md) 0x0051ff70-0x005200c4 | function | ArgumentedItemQuantityInputDialogPaneOnControlCommand : reconstructable : 93% : very-strong : Exact quantity confirm/cancel handler; direct owner/emitter UID00000G at position 20; unsigned 1..100 validation, parse-failure alert, packet helper receiver/widths, always-close semantics, vtable slot, xrefs, and formal human C++ are closed.`
- `by-memory/-coverage-report.md`, insert immediately after the preceding action row:
  `        - [UID:000557][0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor](by-memory/0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor.md) 0x005200d0-0x005203be | function | ArgumentedItemConfirmInputDialogPaneConstructor : reconstructable : 92% : very-strong : Exact confirm-dialog constructor body; direct owner/emitter UID00000F at position 10; 0x27c object layout, copied list context, quantity/price/argument fields, full control APIs/resources, callers, padding boundary, and formal human C++ are closed.`
- `by-memory/-coverage-report.md`, insert immediately after the preceding constructor row:
  `        - [UID:000558][0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand](by-memory/0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand.md) 0x005203c0-0x00520539 | function | ArgumentedItemConfirmInputDialogPaneOnControlCommand : reconstructable : 93% : very-strong : Exact price-confirm handler; direct owner/emitter UID00000F at position 20; mismatch alert/no-close path, match send-or-open-quantity branch, close ordering, packet widths, vtable slot, xrefs, and formal human C++ are closed.`
- `by-memory/-coverage-report.md`, insert as address-sorted exact children immediately after mixed parent UID00025U, vtable row before literal row:
  `        - [UID:00055A][0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData](by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md) 0x0061f584-0x0061f6bc | vtable-data | ArgumentedItemInputDialogVtableData : reconstructable : 92% : very-strong : Exact six-view quantity/confirm vtable and COL band; owner/emitter UID0000HH through compiler-generated declaration coverage, with 23/11/2-slot tables, two seven-base RTTI graphs, folded destructor routes, constructor stores, and ObjectImage successor boundary; no raw arrays emit.`
  `        - [UID:00055B][0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings](by-memory/0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings.md) 0x0061f99c-0x0061fa3c | data | ArgumentedItemInputDialogStrings : reconstructable : 92% : very-strong : Exact four-literal source band owned/emitted by UID0000HH through formal method literals; distinguishes owned prompt/title text from shared DLGEXC3/PAL01/%d/OK/localization dependencies and excludes the Message-vtable successor; no duplicate literal array emits.`
- `by-type/-coverage-report.md`, insert the two struct rows in title order under `by-type/by-struct`:
  `- [UID:000559][ArgumentedItemConfirmInputDialogPaneLayout](by-type/by-struct/ArgumentedItemConfirmInputDialogPaneLayout.md) : reconstructable : 92% : very-strong : Exact 0x27c DialogPane-derived layout owned/emitted by UID00000F, with inherited primary/secondary/tertiary views, list-context pointer at +0x26c, max quantity at +0x270, expected price at +0x274, argument id at +0x278, natural size closure, constructor/action consumers, and no duplicate source body.`
  `- [UID:000556][ArgumentedItemQuantityInputDialogPaneLayout](by-type/by-struct/ArgumentedItemQuantityInputDialogPaneLayout.md) : reconstructable : 92% : very-strong : Exact 0x274 DialogPane-derived layout owned/emitted by UID00000G, with inherited primary/secondary/tertiary views, list-context pointer at +0x26c, unsigned argument id at +0x270, natural size closure, constructor/action consumers, and no duplicate source body.`
- `by-type/-coverage-report.md`, insert in title order under `by-type/by-vtable`:
  `- [UID:00055C][ArgumentedItemInputDialogVtables](by-type/by-vtable/ArgumentedItemInputDialogVtables.md) : reconstructable : 92% : very-strong : Complete six-view quantity/confirm vtable contract owned/emitted by UID0000HH through ordinary class declarations; exact primary/secondary/tertiary slots, two seven-base RTTI graphs, adjustor/destructor folding, constructor stores, and no hand-authored vtable arrays.`
- `by-resource/-coverage-report.md`, insert in title order:
  `- [UID:00055D][argumented-item-input-dialog-resources](by-resource/argumented-item-input-dialog-resources.md) : reconstructable : 91% : strong : Argumented-item input-dialog resource index with owner/emitter UID0000HH, covering the four exact source literals and their constructor/action xrefs while linking, not reowning, shared DLGEXC3, PAL01, %d, OK, LanguageMan, BackPane, and control-resource dependencies; source emission remains in formal dialog methods.`
- UID000554 through UID00055D above are the exact validator-assigned callback UIDs. Coverage-file insertion remains supervisor-owned; this report updates only the inert payload text.
- B010 must not edit coverage files because concurrent B-agent coverage edits are forbidden; the supervisor applies these rows after ordinary implementation and verifies current physical row text dynamically rather than relying on mutable line numbers.

## Follow-Up Actions

- Supervisor exact-artifact review and claim-by-claim ordinary Gate 2A use this report's callback receipts and fresh destination/generated rereads; gate occurrence is authoritative only from supervisor state.
- Supervisor applies C0HH-041..051 through read-only precheck and Gate 2B mutation with hard-stop-on-drift behavior.
- Supervisor applies manual coverage C0HH-052..056 using assigned UIDs 000554 through 00055D and independently verifies any later generated/lifecycle state.
- B010 ordinary callback evidence is complete: just-in-time leases were released, every changed page was scoped-validated, coherent generated CPP/H was physically reread, and this report preserves all research.
- This report does not authorize a new target; any later assignment derives solely from current supervisor state.

## Confidence

- Recommendation confidence: `94/100`, very-strong binary/source-routing support.
- Score confidence: `strong`; callback-applied scores reflect complete ordinary documentation/source output and remain below final-audit range because IDA/manual coverage and rebuilt-binary comparison are separate evidence layers.
- Remaining uncertainty: original filename, helper access, and exact identifier/include spellings only. Runtime behavior, ownership, range, layout, resource, and compiler coverage are closed.

## Validator Results

- Callback validation root: `E:\NTK\GhidraBridge\source-3\project-documentation`. Every command used scoped file mode with `--apply --queue-timeout 240`; each returned exit `0`, `ok: 1`, and no target-invalidating warning. UID000320 retained seven preexisting missing-reference warnings for legacy UIDs absent from validator.ini; those warnings were not introduced or hidden by this callback.
- Validator UID assignment receipts: UID000554 command `000000025407` at `2026-08-17T11:15:59-04:00`; UID000555 `000000025408` at `11:16:02`; UID000556 `000000025409` at `11:16:04`; UID000557 `000000025410` at `11:17:38`; UID000558 `000000025411` at `11:17:40`; UID000559 `000000025412` at `11:17:43`; UID00055A `000000025413` at `11:22:33`; UID00055B `000000025414` at `11:22:35`; UID00055C `000000025415` at `11:22:37`; UID00055D `000000025416` at `11:22:40`.

| Final scoped validator command | Timestamp (`2026-08-17`, `-04:00`) | Ordinary destination |
| --- | --- | --- |
| `000000025458` (`--wait-generated`) | `11:48:37` | `by-file/ArgumentedItemInputDialogs.md` |
| `000000025427` | `11:30:51` | `by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md` |
| `000000025428` | `11:30:54` | `by-class/ArgumentedItemQuantityInputDialogPane.md` |
| `000000025429` | `11:30:56` | `by-class/ArgumentedItemConfirmInputDialogPane.md` |
| `000000025417` | `11:26:48` | UID000554 quantity constructor |
| `000000025418` | `11:26:51` | UID000555 quantity action |
| `000000025454` | `11:48:16` | UID000556 quantity layout/no-code marker |
| `000000025419` | `11:26:53` | UID000557 confirm constructor |
| `000000025420` | `11:26:56` | UID000558 confirm action |
| `000000025455` | `11:48:18` | UID000559 confirm layout/no-code marker |
| `000000025421` | `11:26:58` | UID00055A vtable data |
| `000000025422` | `11:27:01` | UID00055B literal band |
| `000000025456` | `11:48:20` | UID00055C input-dialog vtable/no-code marker |
| `000000025426` | `11:27:12` | UID00055D resource index |
| `000000025443` | `11:42:57` | UID00025U mixed read-only aggregate |
| `000000025435` | `11:39:32` | `by-file/ArgumentedMenuDialogs.md` |
| `000000025436` | `11:39:35` | `by-class/ArgumentedMenuMenuDialog.md` |
| `000000025437` | `11:39:37` | `by-class/ArgumentedMenuMenuItemList.md` |
| `000000025438` | `11:39:40` | UID0003VF copy constructor |
| `000000025439` | `11:39:43` | UID0003VH append helper |
| `000000025440` | `11:39:45` | UID0003VI buy-confirm helper |
| `000000025441` | `11:39:48` | UID0003VJ quantity-or-send helper |
| `000000025442` | `11:39:51` | UID0003VL packet helper |
| `000000025446` | `11:43:05` | UID0000TY helper index |
| `000000025447` | `11:43:08` | UID0003Q5 shared scalar wrapper |
| `000000025448` | `11:43:10` | shared destructor adjustor strip |
| `000000025449` | `11:43:13` | UID00033Y folded wrapper strip |
| `000000025457` | `11:48:22` | UID000320 argumented-menu vtable/no-code marker |
| `000000025445` | `11:43:02` | UID0001Y5 mixed vtable family |
| `000000025450` | `11:43:15` | `by-file/StaticTextControlPane.md` |
| `000000025451` | `11:43:18` | `by-class/StaticTextControlPane.md` |
| `000000025452` | `11:43:34` | UID000222 StaticText type-id method |

- Intermediate coherent refresh command `000000025453` at `2026-08-17T11:44:03-04:00` completed before the four explicit no-code marker repairs. Final owning-page command `000000025458` at `2026-08-17T11:48:37-04:00` completed the coherent refresh after those repairs and rebuilt the registry with 5,763 nodes/4,458 edges.

| Physically reread generated artifact | Header command | SHA256 | Bytes / lines | Readback |
| --- | --- | --- | ---: | --- |
| `auto-generated/NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp` | `000000025456` | `FD1EA0975742C8B340C3BF72810293BF09A145857135A5D8DE0F4FE935D9E4EA` | `8,894 / 237` | Four exact definitions at lines 43, 85, 131, 178; layout/vtable compiler comments; exact order. |
| `auto-generated/NexusTK/ui/dialogs/ArgumentedItemInputDialogs.h` | `000000025456` | `8FB4CE0399BC123385875E55770A330D83035D84E0B9CC8B885FE72026F745A4` | `1,527 / 47` | Quantity then confirm declarations at lines 14 and 30. |
| `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` | `000000025457` | `8B0D9D92013CD3810D4000C8F5D45CA3BC2A4385FACBAB676616AE6795A2B7C7` | `8,263 / 220` | Copy/append/buy/quantity/packet definitions at lines 130/141/164/183/199; compiler vtable comment. |
| `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.h` | `000000025457` | `4F55C91A5B0D3350B5D679A183B4FA8EBCD8A98418A79D122E05E5F25309AE9E` | `2,688 / 85` | One row struct, complete dialog/list declarations, input-class friends, helper declarations. |
| `auto-generated/NexusTK/ui/controls/StaticTextControlPane.cpp` | `000000025458` | `AD17B56BA9748EB0A09EDF2AC91E0137B8985FF4AAC6B612E02DF9F61BD0EA32` | `17,488 / 489` | Exact `GetControlType` body at line 12 and retained source inventory. |
| `auto-generated/NexusTK/ui/controls/StaticTextControlPane.h` | `000000025458` | `8670A803B0B08C73DBC5F7367AC53568FD18AD16DAC548FDC3C30005C91665A3` | `1,035 / 31` | Complete class declaration at line 14. |

- All six generated artifacts end with LF. Physical scans returned zero `Empty Emitter Marker`, `No Children Marker`, `[[CHILDREN]]`, TODO, placeholder, stub, `sub_*`, or `dword_*` hits in the relevant output. No generated file was edited directly. Header command IDs are module content-producing receipts no newer than the final coherent wait; later shared generated truth remains dynamically supervisor-readable.

## Changed Files

- Created exactly ten ordinary pages; each pre-callback state was physically absent:

| UID | Path | Callback-time SHA256 |
| --- | --- | --- |
| 000554 | `by-memory/0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor.md` | `6126388C29984997BA50172CE137428665114614702CE4CC92BBDD14CDA30DD4` |
| 000555 | `by-memory/0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand.md` | `10166B316521E60D763C3524D6971F51427426095C0950EB9DAC425447EA77A0` |
| 000556 | `by-type/by-struct/ArgumentedItemQuantityInputDialogPaneLayout.md` | `638CF5DDBDD46931B45A8C95D472D63B94D824B8802C8038FEEEA844A8A3C7F0` |
| 000557 | `by-memory/0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor.md` | `B6B19894684B860CCAE68FD8007AA8F356C699D4DCB64111ACC28F5FE36D234B` |
| 000558 | `by-memory/0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand.md` | `66653E3987B23128D2D609F60A50FAF7822EF0C322C95A50A2C309E311B0BB3A` |
| 000559 | `by-type/by-struct/ArgumentedItemConfirmInputDialogPaneLayout.md` | `CA14B7BABF48F58D90BC5EEF3765D58CD5BA456FBBB2152A6A224D1FA32E0CDB` |
| 00055A | `by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md` | `448CEE1DF9461A2C7ADB13D64226E0366BE8442DECBDA4F85CC2CCEA06C73DF6` |
| 00055B | `by-memory/0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings.md` | `FA1F16F3C62870FB85467E7D185B0AD9FD5EDC3BD6B2C373A593D73FECFCB603` |
| 00055C | `by-type/by-vtable/ArgumentedItemInputDialogVtables.md` | `1C9BB9DD3BB1B1E18EC50A26582F620930C56D4EBD0D3D1B8CD851F4D589754C` |
| 00055D | `by-resource/argumented-item-input-dialog-resources.md` | `59FA151F948FEC7C78035121B0801093AF95564AEA2E684E98DCB2C6773EFE28` |

- Modified 22 existing ordinary pages. The following are exact callback-time post hashes; pre-callback state is preserved by the accepted report and dated historical sections. Where B010 captured a physical pre-hash before editing, it is included in the `pre` field; omitted pre-hashes are not retroactively invented from repository HEAD.

| Path | Pre SHA256 when captured | Callback-time post SHA256 |
| --- | --- | --- |
| `by-file/ArgumentedItemInputDialogs.md` | not captured | `6496F62D8876DC519C6C3EAE10613AA39308EC9C0C10D14E7B88CEC219CD4678` |
| `by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md` | not captured | `D062A23013B47893DCCF602CAD6BF18AEA7D50C88ED25DDAE36C851AD048CF9A` |
| `by-class/ArgumentedItemQuantityInputDialogPane.md` | not captured | `8858AAB24073E22D6A24CEE4ACC3E5CBB5877E3CA55BC02943704F80856CF8A5` |
| `by-class/ArgumentedItemConfirmInputDialogPane.md` | not captured | `77335ABE73227D2D3263F0C2054B5C907C0282743236CDE122E40DD64AD23031` |
| `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md` | `8B657205FEA48489F58424BF91FE2BC8BC5432F16521A580AE0F8907F49E2F56` | `B063CB0FB24ECE7FC2964393E48AFCF27DD46F078993A0D73B4423C568B121C7` |
| `by-file/ArgumentedMenuDialogs.md` | `E0DBAFDE210F4E22626BB1BEB9A1E1F0656D13B750A621CE11DFC580D88566A1` | `A3A8A0B100E9C96B69FE00FAD4202FE6836E51F6A92CE814ABC1325FC7EBE642` |
| `by-class/ArgumentedMenuMenuDialog.md` | `82707FF541E04A1DDED2EA7BFC8731CDDDCCD95438F27BC59F97AF3D34DCF562` | `8CCD5830B4DDAEC97E1A30EE9DA5620B6F2A344B629312E9DE431F9348E33F5D` |
| `by-class/ArgumentedMenuMenuItemList.md` | `35C1B506B4075D5044C526484403F666DEC25651DCF07C15BCB0C58F67A019B8` | `7C009528A87BDDAC9B1B5FCD9054AAD3DA2CFD07F382C345604C475848F02D8D` |
| `by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md` | `97B6BDB39E25E1F35159A50D0CD23928031B0C1A83E10A1493D0300CEB100EB6` | `FFCB35525941E28EDB333870BB072B26195BDFBB40A8AA05269AEA08AA3BCA37` |
| `by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md` | `BCDC4BE28F4463BD06FC4B1979E6185BC9DB398FDF33E2848AF264D7E201A5D8` | `2BE6C9CB971FB093F7CEFCFD88E2BB3DD3B6212611E6A0736956758531614E96` |
| `by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md` | `674B9672620B00346FD606F9C11446FD58DA1C0EC79C906D1EA6F82BB96A24C9` | `E4C46D87DC8A0CBF6614935B138DA415A0410F6589CCFFBA4448602A5DE30D70` |
| `by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md` | `03AEF6D392FF333AB73EA8559F312539D5440E5831ED31CFC600499517AF0156` | `01FF4F66BEA387D9CAE56AFB9598FF27D8B074C27046E563BD267B94AF6239C4` |
| `by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md` | `09893FB1B8B55DFA7918154AB4BDAD10A76D3A7FC9F725DC0B3FAC5F52832399` | `EEEFB5011FEB5515E5C910E003EE83BF97282BB77FD87B7A2375B3C6A519D305` |
| `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md` | `9250D85C393AF899D71C78C0E12E1B0C4096B361982E013A250EF0AE74EB68D3` | `0BD0E9BEE9D652D4683D22FB3493F9B852A75A8EE36C87E10C96589696CE9C2A` |
| `by-memory/0x0047eaf0-0x0047eb2b.SharedAlertPaneScalarDeletingDestructor.md` | `00F3B62FCD4785BF3AD37718D34E68F1D4E4FBC31CB198007C5700DFCB0E1A48` | `B29B49E23DA286979AA865DDE64B0ACCC281850ABD15686AF70A4B18EB2DFCFA` |
| `by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md` | `9F072637D692ACA13558968454A8FA539CFEEE88928BBE3939C3DFC1276B00E1` | `0DFBF1ACA656EA91C973E298E82FC5BB2382AB6CA3C7203B77BF2BAFEFE30848` |
| `by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md` | `BF341F990ABBDF4907730236783AEA24F5223D6493B21A51AABBC9C7C6812FDC` | `B1BA786F13DFDC463EE5CDE0F8F3ED586CD8F5F038547A1C3046638A5921C610` |
| `by-type/by-vtable/ArgumentedMenuDialogVtables.md` | `6B82513DCFF6CE38293EB4784C71A09709E7E52202EA859EE2A32D38A0D53996` | `2A6DD239DD52BB7A8B5110BB0C0B8F5B467503FC5E44690E04684E21EBFA867F` |
| `by-type/by-vtable/MerchantMenuDialogVtableFamily.md` | `8857F6899C8BE5214A660DF2F5035AA47B90FB8EA55522CC9C9239EFF33128CD` | `E5E0E866F074C9D9F265DE8B540C0B13A15D1DB1624A45E77A00D14D589E4A0F` |
| `by-file/StaticTextControlPane.md` | `A95EF52DEBD7C780DFD2309F30663456256F8997A33E93E7F5A3FACB6A1D96FB` | `D15BF79858CD2BA9B45504C8697A29D5032F8CBBBBE94066D7BD6B4516CE75E8` |
| `by-class/StaticTextControlPane.md` | `83DF3B16F7394D47F1080C85062A34AD40B702B2925233C31C981C3CE42EE171` | `0989C6E845B24983FAFABF60B9B7A54842BD32732B6BB6F1C2EAB7B2BE7C410F` |
| `by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md` | `BE18E0FBBD0DE6C82760618F2DDC32401CE0CE7A698DF0CFB87B8D963835C5FA` | `1647C393791D2D48AC45EB45DF0512787A4716184EFF32C06E30056DC9AEF5E5` |

- Modified report: `tools/leaser/Agents/Agent-B010/research/0000HH-ArgumentedItemInputDialogs-file-source-quality.md`; its exact post-edit identity is returned externally because embedding its own hash would be self-referential.
- Renamed/moved ordinary files: none. UID0000VN and dependency-only APIs/resources remain evidence-only no-change dispositions.
- No manual coverage, generated, tracker, audit, catalog, validator-registry, goal/notes, IDA, or lifecycle file was edited directly. No IDA mutation, `execute_report`, lifecycle command, or report movement occurred. Execution/archive occurrence remains supervisor-owned and authoritative only from current path and validator-owned history.

## Implementation Tracking Checklist

Callback allocation: `47` ordinary claims are checked with verification state `applied`; `17` supervisor-owned claims remain unchecked with state `proposed` (IDA C0HH-041..051, manual coverage C0HH-052..056, and boundary C0HH-062).

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0HH-001 | 0000HH | Incorporate the exhaustive whole-file inventory and all source/compiler/support dispositions. | very-strong | Current IDA, docs, reports, generated audit. | UID0000HH inventory/evidence | incorporate | applied |
| [x] | C0HH-002 | 0000HH | Retain standalone NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp and create its sibling H. | strong | Text/vtable boundaries, two-class unit, source-tree route. | UID0000HH ownership/source placement | incorporate | applied |
| [x] | C0HH-003 | 0000HH | Raise file scores to 93/94 while retaining path and FILE owner. | strong | All blockers investigated; original spellings remain inferred. | UID0000HH metadata | incorporate | applied |
| [x] | C0HH-004 | 0000HH | Define exact generated CPP/H order and eliminate every historical/callback empty or no-children marker in the affected output. | very-strong | Dated command-25350 baseline plus command-25458 callback physical reread. | UID0000HH generated criteria | incorporate | applied |
| [x] | C0HH-005 | 0001BT | Retain exact aggregate range/owner/emitter, set position 10, score 92/94, and emit no-duplicate route marker. | very-strong | Four exact methods and boundaries. | UID0001BT metadata/CPP | incorporate | applied |
| [x] | C0HH-006 | 00000G | Create exact quantity constructor child at [0x51fc90,0x51ff6c), owner/emitter UID00000G position 10. | very-strong | Function, callers, vptr stores, behavior. | new by-memory constructor page | incorporate | applied |
| [x] | C0HH-007 | 00000G | Create exact quantity OnControlCommand child at [0x51ff70,0x5200c4), owner/emitter UID00000G position 20. | very-strong | Primary +0x48 cell and full branch behavior. | new by-memory action page | incorporate | applied |
| [x] | C0HH-008 | 00000F | Create exact confirm constructor child at [0x5200d0,0x5203be), owner/emitter UID00000F position 10. | very-strong | Function, callers, vptr stores, behavior. | new by-memory constructor page | incorporate | applied |
| [x] | C0HH-009 | 00000F | Create exact confirm OnControlCommand child at [0x5203c0,0x520539), owner/emitter UID00000F position 20. | very-strong | Primary +0x48 cell and full branch behavior. | new by-memory action page | incorporate | applied |
| [x] | C0HH-010 | 00000G | Populate quantity class declaration, class route marker, exact fields/layout/method inventory, and score 92/94. | very-strong | 0x274 allocation, DialogPane size, vtables, fields. | UID00000G CPP/H/layout | incorporate | applied |
| [x] | C0HH-011 | 00000F | Populate confirm class declaration, class route marker, exact fields/layout/method inventory, and score 92/94. | very-strong | 0x27c allocation, DialogPane size, vtables, fields. | UID00000F CPP/H/layout | incorporate | applied |
| [x] | C0HH-012 | 00000G | Use pointer +0x26c and unsigned argument id +0x270; no source-authored destructor. | very-strong | Stores/reads and shared destructor wrapper. | UID00000G fields/destructor | incorporate | applied |
| [x] | C0HH-013 | 00000F | Use pointer +0x26c plus max quantity/expected price/argument id at +0x270/+0x274/+0x278; no source destructor. | very-strong | Stores/reads and shared destructor wrapper. | UID00000F fields/destructor | incorporate | applied |
| [x] | C0HH-014 | 00000G | Create a source-local quantity layout page with exact size 0x274 and inherited three-view offsets. | very-strong | Type size and constructor/RTTI facts. | new by-type layout page | incorporate | applied |
| [x] | C0HH-015 | 00000F | Create a source-local confirm layout page with exact size 0x27c and inherited three-view offsets. | very-strong | Type size and constructor/RTTI facts. | new by-type layout page | incorporate | applied |
| [x] | C0HH-016 | 0000HH | Create exact [0x61f584,0x61f6bc) vtable-data child with six tables/COLs and compiler marker. | very-strong | Exact data items, slots, stores, successor. | new by-memory vtable page | incorporate | applied |
| [x] | C0HH-017 | 0000HH | Create input-dialog vtable type page with complete six-view slot/RTTI contract and no raw arrays. | very-strong | 23/11/2 tables and two seven-base RTTI graphs. | new by-type vtable page | incorporate | applied |
| [x] | C0HH-018 | 0000HH | Create exact [0x61f99c,0x61fa3c) source-literal page covered by formal method literals. | very-strong | Four contiguous UTF-16 literals and successor. | new by-memory literal page | incorporate | applied |
| [x] | C0HH-019 | 0000HH | Create argumented-item-input resource index for four owned literals and shared resource dependencies. | strong | Literal xrefs and existing resource owners. | new by-resource page | incorporate | applied |
| [x] | C0HH-020 | 00025U | Add exact vtable/literal children and retain mixed aggregate non-emitting at 86/92. | very-strong | Existing broad range crosses owners. | UID00025U split inventory | incorporate | applied |
| [x] | C0HH-021 | 0000HH | Use current DialogPane APIs and exact OnControlCommand override, not stale OnAction wrappers. | very-strong | Current DialogPane H and vtable slot +0x48. | UID0000HH dependencies/source | reject-stale | applied |
| [x] | C0HH-022 | 00000I | Add copy-constructor/packet-helper declarations and friend access required by input source. | strong | Exact calls and class-private coupling. | UID00000I formal H/support | incorporate | applied |
| [x] | C0HH-023 | 0000HI | Document complete ArgumentedMenuDialogs.h dependency and retain helper bodies in ArgumentedMenuDialogs.cpp. | strong | UID00000I owner route and input include dependency. | UID0000HI source/header route | incorporate | applied |
| [x] | C0HH-024 | 0003VF | Promote exact copy-constructor declaration eligibility and record the two input constructor callers. | very-strong | Current callers and copy behavior. | UID0003VF C++/evidence | incorporate | applied |
| [x] | C0HH-025 | 0003VI | Replace deferred/no-name/no-xref blocker with retained private OpenBuyConfirmDialog inference. | strong | Selected row fields, constructor call, source adjacency. | UID0003VI behavior/CPP | reject-stale | applied |
| [x] | C0HH-026 | 0003VJ | Replace deferred/no-name/no-xref blocker with retained private OpenQuantityDialogOrSendSingle inference. | strong | Quantity gate, localization, ctor/send calls. | UID0003VJ behavior/CPP | reject-stale | applied |
| [x] | C0HH-027 | 0003VL | Promote SendArgumentedItemQuantityPacket signature and exact input-dialog caller contract. | very-strong | Four calls, packet fields, exact widths. | UID0003VL CPP/H/evidence | incorporate | applied |
| [x] | C0HH-028 | 0000TY | Preserve non-emitting helper index and record resolved source names/UID0000HI ownership. | very-strong | B001 split plus current reanalysis. | UID0000TY inventory | incorporate | applied |
| [x] | C0HH-029 | 0003Q5 | Record quantity primary-vtable use of shared 0x47eaf0 wrapper; retain non-emitting. | very-strong | Vtable slot and 0x274 object size. | UID0003Q5 consumers/no-code | incorporate | applied |
| [x] | C0HH-030 | 0000HH | Update shared adjustor strip for quantity cells 0x61f5e8/0x61f618 and implicit destructor route. | very-strong | 0x47e8d9/0x47e8e4 slots. | DialogAndAlertDestructorAdjustorThunks | incorporate | applied |
| [x] | C0HH-031 | 00033Y | Correct active wrapper ownership text: 0x4b0a20/08e3/08ee also serve confirm class by folding. | very-strong | Confirm vtable cells and shared code. | UID00033Y consumers/no-code | reject-stale | applied |
| [x] | C0HH-032 | 000320 | Preserve 0x61f588 as exact successor boundary into UID0000HH and link new vtable child. | very-strong | Existing page and live items. | UID000320 boundary | incorporate | applied |
| [x] | C0HH-033 | 0000HH | Preserve exact five padding spans and ObjectImage successor exclusion. | original-proof | Boundary bytes and next function/table. | UID0000HH range section | incorporate | applied |
| [x] | C0HH-034 | 0000HH | Preserve four unique source literals and shared DLGEXC3/PAL01/%d/OK/localization dependencies without duplication. | very-strong | Exact string addresses/xrefs. | UID0000HH resource inventory | incorporate | applied |
| [x] | C0HH-035 | 0000HH | Preserve quantity unsigned-limit/zero semantics and always-close control-1 behavior. | original-proof | Full current decompile. | quantity action child CPP | incorporate | applied |
| [x] | C0HH-036 | 0000HH | Preserve confirm mismatch-open, match send-or-quantity, and match-close behavior. | original-proof | Full current decompile. | confirm action child CPP | incorporate | applied |
| [x] | C0HH-037 | 0000HH | Preserve implicit pointer leak/no-cleanup behavior rather than inventing ownership. | original-proof | Shared wrappers never read/delete +0x26c. | both classes history/source | incorporate | applied |
| [x] | C0HH-038 | 0000HH | Close formal CPP/H dependencies through existing ButtonControlPane.h, corrected pointer/full-constructor calls, a complete ArgumentedMenuDialogs.h list-context declaration, and a complete StaticTextControlPane.h declaration/route; remove duplicate local row-struct emission. | strong | Command-25458 physical CPP/H readback, formal owner docs, live allocation sizes, and accepted control APIs. | UID0000HH/00000F/00000G; UID0000HI/00000H/00000I/0003VH; UID0000O8/0000E3/000222 | incorporate | applied |
| [x] | C0HH-039 | 0000HH | Historicalize B008's limited child/formal-code deferral while retaining its binary facts. | very-strong | Historical report versus current pass. | UID0000HH/0001BT history | reject-stale | applied |
| [x] | C0HH-040 | 0000HH | Preserve B001 helper ownership and no-xref evidence without treating it as a target blocker. | very-strong | Historical report and live xrefs. | UID0000HH/00000I history | incorporate | applied |
| [ ] | C0HH-041 | 0000HH | Rename 0x51fc90 to ArgumentedItemQuantityInputDialogPane_Constructor. | very-strong | RTTI/vptr/callers; destination free. | IDA Gate 2B A0HH-01 | incorporate | proposed |
| [ ] | C0HH-042 | 0000HH | Add exact regular function comment at 0x51fc90. | very-strong | Constructor behavior/layout. | IDA Gate 2B A0HH-02 | incorporate | proposed |
| [ ] | C0HH-043 | 0000HH | Rename 0x51ff70 to ArgumentedItemQuantityInputDialogPane_OnControlCommand. | very-strong | Primary +0x48 cell; destination free. | IDA Gate 2B A0HH-03 | incorporate | proposed |
| [ ] | C0HH-044 | 0000HH | Add exact regular function comment at 0x51ff70. | very-strong | Validation/send/close behavior. | IDA Gate 2B A0HH-04 | incorporate | proposed |
| [ ] | C0HH-045 | 0000HH | Rename 0x5200d0 to ArgumentedItemConfirmInputDialogPane_Constructor. | very-strong | RTTI/vptr/callers; destination free. | IDA Gate 2B A0HH-05 | incorporate | proposed |
| [ ] | C0HH-046 | 0000HH | Add exact regular function comment at 0x5200d0. | very-strong | Constructor behavior/layout. | IDA Gate 2B A0HH-06 | incorporate | proposed |
| [ ] | C0HH-047 | 0000HH | Rename 0x5203c0 to ArgumentedItemConfirmInputDialogPane_OnControlCommand. | very-strong | Primary +0x48 cell; destination free. | IDA Gate 2B A0HH-07 | incorporate | proposed |
| [ ] | C0HH-048 | 0000HH | Add exact regular function comment at 0x5203c0. | very-strong | Price/quantity/send/close behavior. | IDA Gate 2B A0HH-08 | incorporate | proposed |
| [ ] | C0HH-049 | 0000HH | Protect six decorated vtable names/types/comments and exact table ranges unchanged. | original-proof | Current inspect/comments/slot inventory. | IDA Gate 2B A0HH-09..14 | not-applicable | proposed |
| [ ] | C0HH-050 | 0000HH | Protect six COL pointer cells as name absent/type absent/comment absent. | original-proof | Current inspect/comments and RTTI values. | IDA Gate 2B A0HH-15..20 | not-applicable | proposed |
| [ ] | C0HH-051 | 0000HH | Do not install partial derived/list UDTs; preserve absence until complete declarations can be applied atomically. | very-strong | Current type_inspect and source dependency closure. | IDA Gate 2B A0HH-21..23 | not-applicable | proposed |
| [ ] | C0HH-052 | 0000HH | Replace manual by-file coverage row with exact 93% whole-file description. | strong | Current row 82% and complete report. | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | C0HH-053 | 0001BT | Replace manual by-memory coverage row with exact 92% split/child description. | strong | Current row 84% and complete split. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C0HH-054 | 00000G | Replace manual class coverage row with exact 92% source/layout description. | strong | Current row 82% and formal class/method route. | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C0HH-055 | 00000F | Replace manual class coverage row with exact 92% source/layout description. | strong | Current row 82% and formal class/method route. | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C0HH-056 | 0000HH | Apply the ten literal manual coverage payloads in Section 28 using validator-assigned UIDs 000554 through 00055D while preserving each exact path/title/score/reconstructability/owner/emitter description and placement. | strong | Ten complete assigned-UID payloads and placement contexts in this report. | relevant -coverage-report.md files | incorporate | proposed |
| [x] | C0HH-057 | 0000HH | Run scoped validation for every changed ordinary by-* page in the callback. | strong | Commands 25417-25458; every final destination returned exit 0 and ok 1. | Validator Results | incorporate | applied |
| [x] | C0HH-058 | 0000HH | Run one coherent waited source refresh and physically reread callback-time CPP/H against the complete inventory. | strong | Command 25458 and six exact generated hashes/readbacks. | Validator Results/generated readback | incorporate | applied |
| [x] | C0HH-059 | 0000HH | Preserve no third-party import disposition. | original-proof | First-party NexusTK classes and code. | UID0000HH formal source | not-applicable | applied |
| [x] | C0HH-060 | 0000HH | Preserve Wave2/Wave3 rejection and current-evidence authority. | very-strong | Skill policy and stale trace occurrence. | UID0000HH history | reject-stale | applied |
| [x] | C0HH-061 | 0000HH | Preserve report-level positive/negative evidence and rejected alternatives without pruning. | very-strong | Rule 26 no-loss requirement. | all affected docs | incorporate | applied |
| [ ] | C0HH-062 | 0000HH | Keep manual coverage, IDA mutation, and lifecycle execution supervisor-owned. | original-proof | Goal and workflow boundary. | supervisor handoff | not-applicable | proposed |
| [x] | C0HH-063 | 0000HH | Preserve source style as C++03-era virtual/NULL/m_ and g_ conventions with no decompiler artifacts. | strong | Project headers and source-era constraints. | formal CPP/H and docs | incorporate | applied |
| [x] | C0HH-064 | 0000HH | Record remaining identifier/file-split uncertainty as a confidence cap, not a source/code blocker. | strong | Exhaustive evidence and absent original symbols. | score/open questions | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"additional_uids":["00000F","00000G","0001BT"],"agent":"B010","command_id":"000000025536","destination_path":"executed-b-agent-research/B010/0000HH-ArgumentedItemInputDialogs-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000HH-ArgumentedItemInputDialogs-file-source-quality.md","timestamp":"2026-08-17T14:44:44-04:00","uid":"0000HH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
