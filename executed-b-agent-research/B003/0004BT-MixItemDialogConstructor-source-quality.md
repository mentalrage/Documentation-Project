** TARGET-REPORT-UID:0004BT **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0004BT MixItemDialogConstructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented state: `[0x004af570,0x004af8af)` remains one complete, source-authored, parameterless `MixItemDialog` constructor owned and emitted by [UID:00008J] through [UID:0000KE] `NexusTK/ui/dialogs/ItemDialogs.cpp`.
- Implemented target disposition: UID0004BT is `92/94`, retains `CANONICAL_OWNER:00008J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008J`, and `Nested:0`, uses source position `10`, and contains formal block R1 exactly.
- Implemented source shape: `MixItemDialog : public DialogPane, public Singleton<MixItemDialog>` is installed as R2. RTTI, constructor state, object size, and EH prove the empty Singleton base at `+0x26c`; no `m_itemList` or other MixItemDialog data member was introduced.
- Implemented no-duplicate state: aggregate UID00033U is a non-emitting `92/94` split index with blank formal C++; UID0004BT alone emits the constructor. Aggregate `Nested:8` remains the address-sorted relative delta, not a child count.
- Implemented compiler/source state: validator command `000000010488` preserved UID00033X while renaming it to `0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md`, made it non-emitting source-declared/generated-binary support at `93/96`, and removed the false handwritten `ClearActiveMixItemDialog` body.
- Callback completion: all accepted C01-C20 facts and R1-R7 destinations are applied or preserved at report-level detail; B003 waited command `000000010495` completed, and the latest observed externally refreshed generated header `000000010511` preserves every accepted uniqueness/no-marker check.
- Confidence: very strong for range, ABI, owner, base layout, control sequence, row clearing, EH/lifetime, and formal C++; high rather than absolute for original physical filename and exact lexical helper spellings.

## Supporting Research

### Mandatory MCP provenance

- Evidence was collected on `2026-07-13` through the streamable MCP endpoint with HTTP session `c5f0dea8-d462-4f57-b974-22a8fd1ca2dd` and database argument `supervisor_nexustk_20260713` on every IDB-backed call.
- Fresh request `61`, `idb_list`, at `2026-07-13T17:27:56-04:00` returned exactly one active adopted worker session: `supervisor_nexustk_20260713`, `NexusTK.exe.i64`, PID/worker PID `2236`, created `2026-07-13T09:48:56.928703`, not analyzing.
- Fresh request `62`, `server_health`, returned `status:ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with `2067` entries.
- Bounded target `lookup_funcs`, `get_bytes`, decompile, disassembly, xref, callee, signature, RTTI, and EH reads all returned real IDB data. This is not a fallback-only report.

### Historical-report search provenance

Exact case-insensitive terms were searched individually and as a bounded alternation: `0004BT`, `0x004af570`, `0x004af8af`, `MixItemDialogConstructor`, `MixItemDialog`, `sub_4AF570`, `Singleton<MixItemDialog>`, `ClearActiveMixItemDialog`, `UID00033U`, and `ItemDialogs`.

| Exact root searched | Outcome and target-specific classification |
| --- | --- |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/**` | No match for the exact target/range/name terms; no active B001 overlap. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/**` | No match; no active B002 overlap. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/**` | No pre-existing report match before this artifact was created. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/**` | No match; no active B004 overlap. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/**` | No match; no active B005 overlap. |
| `source-3/project-documentation/executed-b-agent-research/**` | Material matches are classified below. Broad `MixItemDialog`/`ItemDialogs` matches outside that list are consumer, sibling, callback-template, or family mentions and do not independently research UID0004BT. |
| `source-3/project-documentation/archived/**` | No exact-term match. |
| `source-3/project-documentation/tools/leaser/Agents/Older-Research/**` | No exact-term match. |
| `source-3/project-documentation/tools/leaser/Agents/SpecialReports/**` | No exact-term match. |

Material executed-report matches:

- B007 `0000KE-ItemDialogs-empty-emitter-family-source-quality.md`: direct historical origin of UID0004BT, aggregate UID00033U, and the stale constructor/clear-helper drafts. Its exact range and broad owner were useful; its manual singleton assignment, `Dialog()` base, invented `m_itemList`, and handwritten clear helper are superseded by current RTTI/EH evidence.
- B001 `00014T-ItemExchangeMixDialogs.md`: valid split-first evidence that broad UID00014T is a non-emitting mixed inventory and exact Mix children own their source. It did not solve the constructor body or Singleton base.
- B001 `00025A-ExchangeItemReadOnlyData-B001-00025A.md` and B002 `00025A-ExchangeItemReadOnlyData-post-migration.md`: valid vtable/resource-neighborhood and `sub_4AF570` reference evidence; source ownership remains MixItemDialog, not the broad read-only-data page.
- B003 `0002JO-MyItemListPaneConstructor-source-quality.md`: valid proof that `sub_4AEB30` is a parameterless `MyItemListPane` constructor and that callers transfer list ownership through `ScrollableControlPane`; it rejects `new MyItemListPane(this)`.
- B003 `0004BQ-AddItemWithCountDialogConstructor-source-quality.md`: valid immediate-predecessor, DialogPane API, control-constructor, and `ItemDialogs.cpp` style comparator. It does not own the Mix constructor.
- B009 `00033V-MixItemDialogSubmitPacketHelper-source-quality.md`: valid later Mix action/helper and selector-5 list evidence. Its retained no-route helper is outside UID0004BT and remains unchanged.
- B011 `00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md`: valid exact predecessor proof. The complete raw body ends with `ret 4` at `0x004af56d-0x004af570`; none of it is target padding.
- B012 `00014W-MixItemDialogDoubleParamCallback-empty-emitter-source-quality.md`: valid FunctionObjects ownership for the later quantity callback wrapper; it is not constructor ownership.
- B001 UID000126, B002 UID0004BS, B003 UID00014M, and B003 UID00033R matched `0x004af570` only as an endpoint, sibling boundary, or source-family reference. They are corroborating context, not target research.

## Target

- Target UID: `0004BT`.
- Target path: `by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md`.
- Assignment-time source queue/report row: research tracker reconstructable by-memory row `86/90`, combined `88.0`, report count `0`.
- Callback classification: supervisor-authorized implementation is complete; report validation/execution/count/path/move/archive state remains external supervisor/validator-owned.
- Implemented scores and parent state: `92/94`, owner/emitter UID00008J, reconstructable true, position `10`, `Nested:0`; source route resolves through class UID00008J to file UID0000KE.
- Exact binary identity: half-open `[0x004af570,0x004af8af)`, `0x33f` / 831 bytes, SHA256 `EA3D557FBA4CB0C30CD73DEE02CE6061D4499C38C0AEFCA3509F7B95C45CDAB4`.

## Current Target State

- Implemented metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00008J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008J`, position `10`, `Nested:0`.
- Managed C++ now uses exact `DialogPane(L"",9,1)` and `Singleton<MixItemDialog>` initialization, six direct controls, a parameterless local `MyItemListPane`, `ScrollableControlPane` ownership transfer, selectors `1/3/4`, last-to-first row removal, exact lifecycle arguments, and no derived fields.
- The historical `Dialog()`/manual global/`CreateMixItemDialogControls`/`m_itemList`/`AddChild`/`ClearMixRows` draft remains documented as rejected history and is absent from current formal source.
- Aggregate UID00033U is now reconstructable false with blank emitter/position/formal; its exact children attach directly to UID00008J, and latest observed generated command `000000010511` contains no UID00033U marker or route.
- UID00033X is now the validator-registered `MixItemDialogSingletonBaseDestructor` page, reconstructable false with blank emitter/position/formal; exact EH/RTTI/EBO/scalar/comparator evidence replaces the handwritten helper model.
- Related docs checked: UID00008J, UID0000KE, UID00033U, UID0004BU, UID0004BV, UID00033V, UID000319, UID00031A, UID00033X, UID0002AY, UID0003IG, UID0003NJ, UID00014T, UID00008W, UID0000CE, UID00003T, and UID00007A.
- Historical B003 research/implementation-callback artifact path before any external lifecycle action: `tools/leaser/Agents/Agent-B003/research/0004BT-MixItemDialogConstructor-source-quality.md`. B003 performed no report execution, lifecycle, move, or archive command; current external path/count/status is supervisor/validator-owned and is not asserted by this artifact.

## Executive Recommendation

UID0004BT is implemented as a complete source constructor, not a mixed code island. It emits once through UID00008J with formal block R1 and score `92/94`. UID00008J contains exact class declaration R2, including `DialogPane` followed by `Singleton<MixItemDialog>`, no data members, and `[[CHILDREN]]` after the closing class brace.

UID00033U is a non-emitting `92/94` split index with R3 blank, owner UID00008J retained as semantic context, blank emitter/position, and `Nested:8`. UID00033X is renamed/reclassified as the non-emitting Singleton base destructor with R4 blank. UID0003IG vtable data and UID0003NJ literal storage are compiler/source-derived non-emitting support with R5/R6 blank. Typed singleton globals continue to emit through UID0000KE using exact declarations R7.

No child split inside UID0004BT is warranted. The one `0xcc` byte at `0x004af8af` remains parent-only alignment between the constructor and UID0004BU.

## Supervisor Active Recheck

- Historical report-only gate: the initial pass forbade by-* edits, validators, and leases; exact SHA `C21DAA9E3CF7D9F736CDD4AAC737FE2688CD252EB8A64D54FC62313FD1BEF749` passed supervisor Gate 1 before this callback.
- Implemented split repair is limited to aggregate/emission policy: UID0004BT remains one exact page and no new target child was created; UID00033U no longer emits an unattached aggregate marker.
- Every source-bearing item inside the target is represented by R1. Compiler-generated EH/vptr/security-cookie operations remain represented by source inheritance/new expressions and explicit no-code dispositions, not copied bodies.
- Current callback state: implementation, scoped validators, UID-preserving rename, waited generated refresh, and readback are complete. B003 performed no report execution or lifecycle/move/archive command.

## Inference Research Guidance Check

- `by-structure.md` and the workflow's split-first rule were applied: physical adjacency and a broad aggregate do not override a complete modeled constructor or its direct class owner.
- Current names, owner, first-draft C++, aggregate emitter, and helper identity were treated as hypotheses. Exact bytes, callers, RTTI, EH, vtable stores, helper signatures, and sibling accepted source shapes were rechecked.
- IDA facts are labeled as executable facts. Existing by-* and executed reports are documentation evidence. Source names, access, and physical filename are inference where symbols do not prove them.
- Stale Wave2/Wave3-era generated/source assumptions were not used as authority. No current explicit instruction revives them.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and resolution | Classification |
| --- | --- | --- |
| Constructor signature | Both callers allocate `0x26c`, set `ECX`, call `0x004af570`, and push no source argument. Source declaration is `MixItemDialog()`; IDA's `__int16 *` return is implicit constructor ABI. | Original behavior; source spelling inferred from RTTI/class convention. |
| Direct base | First call is `DialogPane(L"",9,1)`, not `Dialog()`. RTTI lists DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler. | Binary-proven. |
| Singleton publication | RTTI names `Singleton<MixItemDialog>` and BCD `mdisp=0x26c`. Constructor forms `this+0x26c`, publishes complete `this`, and advances EH state. | Binary-proven source base, not manual body assignment. |
| Object layout | Both callers allocate `0x26c`; scalar wrapper's size-aware path also uses `0x26c`. No target write creates a field after DialogPane. Singleton is empty-base optimized at `+0x26c`. | Binary-proven. |
| `m_itemList` | The parameterless `MyItemListPane` pointer is held in `EBX`, passed to a newly allocated `ScrollableControlPane`, and used locally for row clearing. It is never stored into MixItemDialog. | Rejected stale field. |
| Control helper | There is no single `CreateMixItemDialogControls` call. The constructor performs five explicit control allocations plus one scroll wrapper allocation. | Rejected stale helper. |
| Child attachment | `MyItemListPane` is the scrollable pane argument to `ScrollableControlPane(&bounds,itemList,0,0,0)`, then the wrapper is added with inherited `AddControl`. | Binary-proven ownership transfer. |
| Row initialization | `MyItemListPane` initially enumerates inventory. After `OnCreate`, this constructor removes every row from last index to zero using `GetItemCount()-1` and `RemoveItems(index,1)`. | Binary-proven exact loop. |
| Control selectors | Insertion indexes are background 0, buttons 1-4, wrapper 5. Hover/focused/pending calls use `1/3/4`. | Binary-proven; semantic button labels remain descriptive. |
| Lifecycle arguments | `OnCreate` receives full bounds, z-order 0, null parent, and overlay layer. `OnShow` receives two null pointers; unlike AddItemDialog, no `g_pBackPane` argument is pushed. | Binary-proven correction. |
| Allocation failure | Seven old-MSVC `new` lowerings test raw allocation before constructor calls. Formal source uses ordinary `new`; no handwritten null branches, catch, scope guard, smart pointer, or cleanup funclet belongs in source. | Compiler lowering. |
| EH cleanup | States 2-8 free the raw allocation currently under construction; state 1 destroys Singleton; state 0 tears down DialogPane. | Compiler-generated from source construction order. |
| Vptr stores | `0x0061a088`, `0x0061a0e8`, and `0x0061a118` are written after Singleton construction. | Compiler-generated from class declaration. |
| Clear helper | `0x004b0870` has only EH xref `0x005fe593`; comparator UID0000Y0 has the same source identity and layout. | Reclassify/rename; reject handwritten helper. |
| Aggregate emission | UID00033U's `[[CHILDREN]]` has no attached children because exact pages emit directly through UID00008J. | Reclassify aggregate non-emitting. |
| Vtable and literal pages | Vtable arrays/RTTI and separately indexed string storage are regenerated by class/method source; manual arrays or duplicate literal definitions would be wrong. | Non-emitting support. |
| Source file | Contiguous item-dialog family, current class/file ownership, sibling accepted constructors, globals, and generated route support `NexusTK/ui/dialogs/ItemDialogs.cpp`. | Strong project source placement; original physical filename not symbol-proven. |

Rejected alternatives:

- `Dialog` base, direct global assignment, and a derived `m_itemList` are rejected by the exact base call, RTTI/EH base state, and absence of a member store.
- `new MyItemListPane(this)` is rejected by the parameterless call and current MyItemListPane constructor evidence.
- A free `CreateMixItemDialogControls` or `ClearMixRows` helper is rejected because the target directly contains every call and loop.
- `OnShow(NULL,g_pBackPane)` is rejected by two literal zero pushes.
- `ExchangeDialog`, `MyItemListPane`, `ScrollableControlPane`, and broad UID00014T ownership are rejected: they are caller/callee/container context, not implementation owner.
- A separate `MixItemDialog.cpp` remains a plausible original-file spelling but is weaker than the accepted current source route; no symbol, path string, or independent file boundary proves it.
- Handwritten vtable arrays, explicit EH actions, security-cookie code, scalar-delete flags, and manual Singleton clear helpers are rejected compiler artifacts.

## Evidence Standards Used

- Primary evidence: live IDA MCP bytes, function boundaries, decompilation, disassembly, xrefs, callees, RTTI records/type names, global refs, vtable values, EH FuncInfo/unwind actions, and exact caller instruction sequences.
- Secondary evidence: current by-* pages, accepted sibling source forms, current generated output, manual coverage rows, and executed reports.
- Negative evidence: no target parameter pushes, no derived member store, no internal split, no ordinary caller to UID00033X, no vtable/pointer route to that helper, no target reference to `g_pBackPane`, and no source string/path proving a different file.
- Binary and documentation agree on the direct class and source family. Lexical uncertainty affects confidence but does not block exact formal source.

## Evidence Checked

- MCP requests included fresh `idb_list`/`server_health`; `lookup_funcs` for target/end/successor/helper; target and boundary `get_bytes`; target/helper/scalar-wrapper decompile/disassembly; target/global/string/helper xrefs; target callees; unique signatures; RTTI entity/type/raw records; and constructor EH metadata/action bytes.
- Current docs checked include the target, UID00033U/4BU/4BV/33V/319/31A/33X/2AY/3NJ, class UID00008J, vtable UID0003IG, file UID0000KE, broad UID00014T, and reusable DialogPane/ListPane/MyItemListPane/ScrollableControlPane/control constructors.
- Generated `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` was inspected read-only. Evidence-time header command is `000000010428`, refreshed `2026-07-13T17:19:32-04:00`.
- Manual by-memory/by-class/by-vtable/by-file coverage rows were read. Relevant stale or absent rows are supplied exactly below; no coverage file was edited.
- Active B001-B005 research roots and executed/archive/Older-Research/SpecialReports roots were searched with the exact terms listed above.
- One MCP request to a nonexistent method name `callers` returned `Method 'callers' not found`; this was not an outage. Complete caller evidence came from `xrefs_to 0x004af570` plus bounded caller instructions/decompilation. No evidence route remained blocked.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory evidence-time MCP session was healthy and all target reads used database `supervisor_nexustk_20260713`. | Very strong | Requests 61/62 plus bounded target reads. | UID0004BT MCP evidence; report provenance. | incorporate | applied | Evidence-time session/request facts remain durable in `Supporting Research`; no indefinite current-session claim was introduced. |
| C02 | UID0004BT is exactly `[0x004af570,0x004af8af)`, `0x33f`/831 bytes, with the stated SHA256 and no internal padding. | Very strong | `lookup_funcs`, request 57 full bytes/hash, terminal `ret` at `0x004af8ae`. | UID0004BT boundary/evidence. | incorporate | applied | Target contains range/size/hash/first+last bytes/signature/instruction/return and predecessor/successor padding proof; scoped validator `000000010463`, exit 0, `ok:1`. |
| C03 | Source signature is parameterless `MixItemDialog()`; apparent return is constructor ABI only. | Very strong | Two no-argument callers, ECX receiver, return-this lowering. | UID0004BT/class UID00008J. | incorporate | applied | Target and class declaration contain parameterless signature and two caller ABI proof; validators `10463` and post-rename class `10489`, both exit 0/`ok:1`. |
| C04 | Direct bases are `DialogPane` then `Singleton<MixItemDialog>`; DialogPane args are `L"",9,1`. | Very strong | First call, RTTI eight-entry hierarchy, Singleton decorated type/BCD. | UID0004BT, UID00008J, UID0003IG. | incorporate | applied | R1/R2 are byte-for-byte equal to report; vtable page carries complete RTTI hierarchy. Validators `10463`, `10489`, `10470`; generated lines 396-419 prove class/base order. |
| C05 | Complete object size is `0x26c`; Singleton EBO is at `+0x26c`; MixItemDialog adds no data members. | Very strong | Caller allocations, scalar size path, BCD `mdisp`, no derived stores. | UID0004BT and UID00008J layout. | incorporate | applied | Target/class/helper/vtable pages carry allocations, scalar path, BCD values, no-store proof, and EBO model; validators `10463`, `10489`, `10488`, `10470`. |
| C06 | Exact resources are `MIXITEM.EPF` and `MIXITEM.PAL`; background bounds are `(0,0,292,309)`. | Very strong | UTF-16 bytes/xrefs and constructor operands. | UID0004BT; UID0003NJ. | incorporate | applied | Target R1/control table and resource page exact UTF-16 byte ranges/xrefs applied; validators `10463` and `10473`. |
| C07 | Four button IDs/bounds are exactly `36 (23,273,86,297)`, `21 (85,273,148,297)`, `14 (147,273,210,297)`, and `22 (209,273,272,297)`. | Very strong | Repeated InitRect/constructor call operands. | UID0004BT control table. | incorporate | applied | Exact ordered control table and R1 are present; validator `10463`, generated constructor lines 427-438. |
| C08 | `MyItemListPane` construction is parameterless/local; wrapper bounds are `(37,68,264,236)` and arguments `(itemList,0,0,0)`. | Very strong | Calls `0x004aeb30` and `0x004985a0`, local EBX flow. | UID0004BT; verify-only UID00008W/0000CE support. | incorporate | applied | Target/class/file carry local ownership transfer and no-field rejection; verify-only support was not changed. Validator `10463`; generated lines 440-442. |
| C09 | Control insertion indexes are 0-5; hover/focused/pending are `1/3/4`. | Very strong | Six AddControl calls followed by exact selector calls. | UID0004BT. | incorporate | applied | Target control table/order and selector facts applied; validator `10463`; generated lines 444-447. |
| C10 | `OnCreate` receives full bounds, 0, null, overlay layer; `OnShow` receives null/null; then `SlideOpenVertical`. | Very strong | Calls at `0x004af85a`, `0x004af885`, `0x004af88c`. | UID0004BT. | incorporate | applied | Exact lifecycle args/order and `g_pBackPane` negative applied; validator `10463`; generated lines 449-462. |
| C11 | Mix rows are cleared last-to-first after `OnCreate` via local list `GetItemCount` and `RemoveItems(index,1)`. | Very strong | Loop at `0x004af86b-0x004af875`; ListPane contracts. | UID0004BT. | incorporate | applied | Exact loop and behavior prose applied; validator `10463`; generated lines 453-458. |
| C12 | Seven allocation EH states and security-cookie/vptr mechanics are compiler output, not handwritten source. | Very strong | FuncInfo/unwind map and external actions. | UID0004BT compiler/source section. | incorporate | applied | Target documents FuncInfo/states/actions and exclusions; R1 contains normal source only. Validator `10463`; exact R1 equality check passed. |
| C13 | UID00033X is the EH-only `Singleton<MixItemDialog>` base destructor, not `ClearActiveMixItemDialog`. | Very strong | Exact 11 bytes, sole EH xref, adjusted ECX, RTTI, UID0000Y0 comparator. | Validator-preserving UID00033X rename/reclassification R4. | reject-stale | applied | Validator `10488` preserved UID, moved path, set `93/96`, false/blank, and propagated nine links; helper contains exhaustive EH/RTTI/EBO/scalar/comparator no-code proof. `ClearActiveMixItemDialog` is absent from generated output. |
| C14 | UID00033U must be non-emitting; target UID0004BT is the sole constructor emitter. | Very strong | Exact direct-class child route and historical generated unattached marker. | UID00033U R3; UID0004BT R1. | reject-stale | applied | Aggregate validator `10467` set false/blank R3 and preserved `Nested:8`; latest observed generated command `10511` contains UID0004BT once and UID00033U zero times. |
| C15 | UID0003IG is compiler-generated vtable/RTTI support and must not emit manual arrays or an Empty Emitter Marker. | Very strong | Vtable cluster, constructor stores, RTTI, scalar/adjustor routes. | UID0003IG R5. | incorporate | applied | Vtable page is `92/95`, false/blank R5 with complete compiler proof; validator `10470`; latest observed generated command `10511` has zero UID0003IG routes and no raw Mix vtable/RTTI array. |
| C16 | UID0003NJ is source-derived literal storage covered by R1 and should be non-emitting. | Very strong | Exact UTF-16 bytes and target-only xrefs. | UID0003NJ R6. | incorporate | applied | Resource page is `92/95`, false/blank R6 with exact bytes/xrefs; validator `10473`, exit 0/`ok:1` with pre-existing missing-UID0003IH warning; latest observed generated command `10511` has zero UID0003NJ routes. |
| C17 | UID0002AY retains the two exact zero-initialized typed global declarations and records Singleton-backed Mix lifetime. | Very strong | Zero bytes and exact per-slot xrefs. | UID0002AY R7. | incorporate | applied | R7 is byte-for-byte equal, page is `92/95`, and post-rename validator `10493` is exit 0/`ok:1`; generated lines 574-576 contain the declarations once as a block. |
| C18 | UID00008J receives complete no-field class declaration R2 and score `91/93`; implicit virtual destruction is compiler-generated from its bases/vtable. | Strong | RTTI/layout/method children/scalar wrapper. | by-class/MixItemDialog.md. | incorporate | applied | R2 equality, layout/lifetime/history evidence, and score applied; post-rename validator `10489`, exit 0/`ok:1`; generated class closes at line 414 before first definition line 417. |
| C19 | UID0000KE remains source root, improves to `92/92`, and records exact constructor/class/compiler split without changing route. | Strong | Contiguous family, current routes, sibling accepted source, no contrary filename proof. | by-file/ItemDialogs.md. | incorporate | applied | File inventory and route applied without compressing concurrent evidence; current scoped validator `10491` and final waited `10495`, exit 0/`ok:1`; path remains `NexusTK/ui/dialogs/`. |
| C20 | Manual coverage rows, generated pre-callback state, historical assumptions, rejected alternatives, validators, and lifecycle boundaries must be preserved claim-by-claim. | Very strong | Current docs/generated/manual coverage/workflow. | Report coverage/checklist and all changed destinations. | incorporate | applied | Exact supervisor-owned coverage text remains unchanged; pre-callback command `10428` is historicalized; changed docs retain rejected history; validator/lease/generated proof is recorded below; no B003 execute/lifecycle/move/archive command occurred. |

## Positive Evidence Summary

- The modeled start, size, unique prefix, full-byte hash, final return, and successor start close the exact target range.
- Both callers allocate exactly `0x26c`, pass no arguments, and guard construction with the same typed singleton slot.
- RTTI independently proves class identity, direct DialogPane plus Singleton inheritance, and the `+0x26c` empty-base displacement.
- Decompilation and disassembly agree on every resource, rectangle, button ID, list/wrapper construction, selector, lifecycle call, and row-removal loop.
- EH state ordering explains early singleton publication and cleanup without manual source scaffolding.
- Existing accepted control/list APIs provide source-facing declarations for every R1 call.
- The strongest inference chain is: exact constructor body + direct caller object size + RTTI base descriptor + EH adjusted cleanup + typed global lifecycle. It excludes the stale draft and supports ordinary human-written constructor source.

## IDA MCP Facts

### Function and byte facts

- `lookup_funcs 0x004af570` returns `sub_4AF570`, size `0x33f`; `0x004af8af` is not a function; successor `sub_4AF8B0` starts at `0x004af8b0`, size `0x2b5`.
- Request 57 returned 831 target bytes and SHA256 `EA3D557FBA4CB0C30CD73DEE02CE6061D4499C38C0AEFCA3509F7B95C45CDAB4`.
- First 16 bytes: `55 8B EC 6A FF 68 E5 E5 5F 00 64 A1 00 00 00 00`.
- Last 16 bytes: `5E 5B 8B 4D F0 33 CD E8 84 7E 11 00 8B E5 5D C3`.
- Unique target-start signature: `55 8B EC 6A FF 68 E5 E5 5F 00`; exact 16-byte prefix occurs only at `0x004af570`.
- IDA disassembly reports 263 contiguous body instructions; including attached external cleanup actions gives 313. Exactly one return is at `0x004af8ae`.

### Constructor operation order

| Order | Address/call | Exact meaning |
| --- | --- | --- |
| 1 | `0x004af5ac -> 0x0049d8a0` | `DialogPane(L"",9,1)`. |
| 2 | `0x004af5c7/0x004af5ce` | Singleton base publishes complete `this`; adjusted-null fallback stores zero. |
| 3 | `0x004af5ee/0x004af5f4/0x004af5fe` | Compiler stores primary/secondary/tertiary Mix vptrs. |
| 4 | `0x004af608-0x004af649` | Background bounds, 332-byte EPF control, `MIXITEM.EPF`, flags 0/1, `MIXITEM.PAL`, AddControl. |
| 5 | `0x004af660-0x004af788` | Four 276-byte ImageButton controls with exact IDs/bounds, each added in order. |
| 6 | `0x004af792-0x004af7ac` | Allocate 332 bytes and call parameterless `MyItemListPane`. |
| 7 | `0x004af7c8-0x004af802` | Allocate 268-byte `ScrollableControlPane(&bounds,itemList,0,0,0)` and add wrapper. |
| 8 | `0x004af810-0x004af82b` | Background resource; hover 1; focused 3; pending 4. |
| 9 | `0x004af842-0x004af85a` | Full bounds and `OnCreate(...,overlayPaneLayerContext)`. |
| 10 | `0x004af86b-0x004af875` | Remove local list rows from last to first. |
| 11 | `0x004af885/0x004af88c` | `OnShow(NULL,NULL)` then `SlideOpenVertical()`. |

### Callee inventory

| Address | Source-facing role |
| --- | --- |
| `0x0049d8a0` | DialogPane constructor |
| `0x004b7c50` | InitRectBounds |
| `0x004f4aa0` | allocation helper / operator new lowering |
| `0x004991f0` | EPFImageControlPane constructor |
| `0x0049dc10` | DialogPane::AddControl |
| `0x00495bf0` | ImageButtonControlPane constructor |
| `0x004aeb30` | MyItemListPane constructor |
| `0x004985a0` | ScrollableControlPane constructor |
| `0x0049db60` | SetBackgroundResource |
| `0x0049fc00` | SetHoverControl |
| `0x0049dd80` | SetFocusedControl |
| `0x0049ddd0` | SetPendingControl |
| `0x0049dfd0` | OnCreate |
| `0x004f3bd0` | ListPane::GetItemCount |
| `0x004f3d60` | ListPane::RemoveItems |
| `0x0049e190` | OnShow |
| `0x0049eac0` | SlideOpenVertical |
| `0x005c772f` | security-cookie check, compiler-only |

### EH, RTTI, and layout facts

- FuncInfo `0x0065c7b8` has magic `0x19930522`, maximum state `9`, unwind map `0x0065c978`, no try blocks, and EH flags `1`.
- State 0 action `0x005fe582` tears down DialogPane through `0x0049d9f0`. State 1 action `0x005fe58a` adjusts to `this+0x26c` and reaches `0x004b0870`. States 2-8 use delete actions `0x005fe598`, `0x005fe5a3`, `0x005fe5ae`, `0x005fe5b9`, `0x005fe5c4`, `0x005fe5cf`, and `0x005fe5da` for the seven raw allocations under construction.
- The seven allocations are background, four buttons, MyItemListPane, and ScrollableControlPane. Successful AddControl/wrapper construction transfers ownership; the source does not use smart pointers or explicit catches.
- Mix RTTI type descriptor is `0x00676038` (`.?AVMixItemDialog@@`). Singleton type descriptor is `0x00676054` (`.?AV?$Singleton@VMixItemDialog@@@@`).
- Primary COL `0x00647468`, hierarchy `0x0064747c`, base array `0x0064748c`, Mix BCD `0x006474b0`, and Singleton BCD `0x006474cc` describe eight entries: MixItemDialog, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, Singleton.
- Singleton BCD records `mdisp=0x26c`, `pdisp=-1`, `vdisp=0`, attributes `0x40`; it is direct, nonvirtual, and empty-base optimized.
- Vtables are `0x0061a088`, `0x0061a0e8`, and `0x0061a118`, corresponding to complete-object offsets `+0`, `+0xa0`, and `+0xa4`.
- No target write establishes a MixItemDialog data member. `+0x26c` is the Singleton base address, not storage for `m_itemList`.

### Global and helper facts

- `0x0069b32c` has exactly six refs: constructor publish/fallback `0x004af5c7/0x004af5ce`, EH-only base destructor `0x004b0870`, scalar wrapper clear `0x004b0ad6`, and open-if-null checks `0x005a4e03/0x005a5fbb`.
- Helper `[0x004b0870,0x004b087b)` is exactly `C7 05 2C B3 69 00 00 00 00 00 C3`, two instructions, unique signature, and one inbound code xref `0x005fe593` from target EH.
- Scalar deleting wrapper `[0x004b0ad0,0x004b0b15)` clears the singleton, tears down DialogPane, interprets delete flags, and optionally frees `0x26c`; primary vtable and two adjustors reach it. Its polluted `boost::exception` base label is rejected.
- `MIXITEM.PAL` begins at `0x0061a37c` with one target xref; `MIXITEM.EPF` begins at `0x0061a394` with two target xrefs. Raw UTF-16 bytes close the strings exactly before `0x0061a3ac` callback metadata.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004af4f0-0x004af570` | UID00033T AddItemWithCountDialogSubmitPacketHelper | Complete predecessor raw helper ending in `ret 4` | True, blank formal by no-route policy | UID000008 | `86/90` | verify-only unchanged |
| `0x004af570-0x004af8af` | UID0004BT target | Complete parameterless MixItemDialog constructor | True | UID00008J | `92/94` implemented | R1 emits once in latest observed command `10511` |
| `0x004af570-0x004afb80` | UID00033U MixItemDialogCore | Constructor/action/table split index | False | UID00008J semantic | `92/94` implemented | non-emitting R3; zero generated route |
| `0x004af8af-0x004af8b0` | parent-only byte | one `0xcc` alignment byte | No | UID00033U | n/a | preserve outside target |
| `0x004af8b0-0x004afb65` | UID0004BU | OnAction and live inline submit | True | UID00008J | `88/90` | verify-only unchanged |
| `0x004afb65-0x004afb80` | UID0004BV | switch table plus eight-byte tail alignment | False | UID00008J | `86/90` | verify-only unchanged |
| `0x004afb80-0x004afcc0` | UID00033V | retained no-direct-route submit helper | True | UID00008J | `88/89` | verify-only unchanged |
| `0x004afcc0-0x004afe38` | UID000319 | AddMixItem quantity prompt/helper | True | UID00008J | `88/90` | verify-only unchanged |
| `0x004afe40-0x004afff7` | UID00031A | quantity callback | True | UID00008J | `88/90` | verify-only unchanged |
| `0x004b0870-0x004b087b` | UID00033X `MixItemDialogSingletonBaseDestructor` | Singleton base-destructor instantiation | False | UID00008J semantic | `93/96` implemented | validator-preserved rename; non-emitting R4 |
| `0x0061a084-0x0061a120` | UID0003IG | Mix vtable/RTTI cluster | False | UID00008J semantic | `92/95` implemented | non-emitting R5 |
| `0x0061a37c-0x0061a3ac` | UID0003NJ | exact resource literals | False | UID00008J semantic | `92/95` implemented | covered by R1; R6 blank |
| `0x0069b328-0x0069b330` | UID0002AY | typed AddItem/Mix singleton globals | True | UID0000KE | `92/95` implemented | source declarations R7 once |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a4e29` | call from `sub_5A4DE0`, `[0x005a4de0,0x005a4e3d)` | Checks `g_pMixItemDialog`, allocates `0x26c`, sets ECX, calls with no arguments. Adjacent UI open helper; source owner of caller remains unresolved and does not affect constructor ownership. |
| `0x005a5fec` | call from `sub_5A5BD0`, `[0x005a5bd0,0x005a7422)` | UserPane key/event dispatcher case checks the same global, allocates `0x26c`, and calls with no arguments. Consumer only. |
| `0x004af5c7/0x004af5ce` | writes `0x0069b32c` | Singleton base publish/fallback clear during construction. |
| `0x005fe593 -> 0x004b0870` | sole helper xref | Constructor-unwind destruction of the live Singleton base. |
| `0x0061a088 -> 0x004b0ad0` | primary vtable scalar-deleting slot | Compiler destruction route; not an ordinary source method body. |
| `0x004b08ff/0x004b090a -> 0x004b0ad0` | secondary/tertiary adjustors | Compiler view adjustment. |
| `0x004af625 -> 0x0061a37c` | `MIXITEM.PAL` | EPF background constructor palette literal. |
| `0x004af632/0x004af809 -> 0x0061a394` | `MIXITEM.EPF` | EPF control resource and dialog background resource. |

## Documentation Evidence And IDA Status

- Historical pre-callback UID0004BT state had a correct range/owner and broad narrative but stale base, singleton, controls, list ownership, fields, and helper names. Current UID0004BT contains exact R1 and report-level evidence at `92/94`.
- Historical pre-callback UID00033U correctly inventoried constructor/action/table ranges but incorrectly remained an emitter. Current UID00033U is a non-emitting `92/94` split index; exact child and parent-only padding facts remain valid.
- Historical pre-callback UID00008J correctly owned the method family but lacked a declaration and described UID00033X as a helper. Current UID00008J contains exact R2/no-field layout at `91/93` and all UID00033X links use the base-destructor identity.
- Historical pre-callback UID00033X correctly recorded bytes/global effect but misclassified source identity and emitted duplicate handwritten source. Current UID00033X is validator-renamed, `93/96`, false/blank R4 with exhaustive generated-binary proof.
- Historical pre-callback UID0003IG had valid exact cluster/slots/successor evidence but source-shape-incorrect reconstructable/emitter metadata. Current UID0003IG is non-emitting `92/95` compiler vtable/RTTI support.
- UID0003NJ's strings/range/xrefs remain valid; current metadata is non-emitting `92/95`, and R1 alone expresses both literals.
- UID0002AY currently records zero-initialized two-slot storage, exact refs, and Singleton lifetime at `92/95`; the manual coverage row remains stale at the old mixed `0x0069b328-0x0069b33c` all-`0xff` interpretation and remains external supervisor-owned.
- Historical pre-callback generated command `000000010428` emitted the stale UID0004BT draft at lines 396-405, an unattached UID00033U `[[No Children Attached]]` marker, handwritten `ClearActiveMixItemDialog`, and an empty UID00008J marker.
- B003 waited generated command `000000010495`, refreshed `2026-07-13T18:03:59-04:00`, emitted the closed UID00008J class followed by R1 and every existing Mix definition once, R7 once, and zero UID00033U/33X/3IG/3NJ routes.
- Latest read-only generated header at final self-review is external command `000000010511`, refreshed `2026-07-13T18:10:06-04:00`. It is newer than B003's waited proof and preserves the same structure/counts; the historical marker/helper state remains absent.

## Ranked Ownership Analysis

### 1. UID00008J MixItemDialog through UID0000KE ItemDialogs

- Evidence for: constructor RTTI/vtables/global, direct Mix methods, exact class-sized callers, contiguous ItemDialogs family, current owner chain, and sibling source routes.
- Evidence against: original physical filename is not embedded or symbol-proven.
- Decision: accepted. This is the narrow semantic owner and strongest current project source route.

### 2. UID00033U MixItemDialogCore aggregate

- Evidence for: exact aggregate begins at the constructor and inventories action/table children.
- Evidence against: it is not a source entity, its children attach directly to the class, and aggregate emission produces no attached children. Emitting here duplicates the target route.
- Decision: retain as non-emitting split index with semantic owner UID00008J and blank emitter/formal C++.

### 3. ExchangeDialog, MyItemListPane, ScrollableControlPane, or broad UID00014T

- Evidence for: callers/callees and physical adjacency connect these entities to the workflow.
- Evidence against: none owns the constructor's vtables, RTTI, singleton, or method family. UID00014T is deliberately mixed/no-owner.
- Decision: reject as canonical owner or emitter; preserve as dependencies/context only.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file page. Retain UID0000KE route `NexusTK/ui/dialogs/ItemDialogs.cpp`.
- Likely full contents: current AddItem, AddItemWithCount, MixItemDialog, AddMixing, singleton globals, and accepted exact children already inventoried by UID0000KE.
- Candidate related items that belong: UID0004BT, UID00008J, UID0002AY, and current Mix method children.
- Candidate related items rejected: MyItemListPane remains separately owned by UID0000LO; FunctionObjects callback wrapper remains UID000041/UID0000JO; ExchangeDialog remains UID0000J9; broad UID00014T remains no-owner.
- Inference: compact legacy `ItemDialogs.cpp` is stronger than a new `MixItemDialog.cpp`; no new source root should be created from this target alone.

## Source Placement

- Recommended placement: class declaration and exact constructor in `NexusTK/ui/dialogs/ItemDialogs.cpp` through UID00008J -> UID0000KE.
- The direct dependencies are general dialog/control/list APIs, but the resources, singleton, caller gates, and later action/quantity methods are MixItemDialog feature code.
- Rejected placements: ExchangeDialog (consumer), MyItemListPane/ScrollableControlPane (owned dependencies), generic DialogPane (base), FunctionObjects (later callback wrapper), and broad no-owner UID00014T.
- Remaining uncertainty: no original source path string or PDB survives. This caps file confidence but does not justify creating a competing route.

## Range / Split / Padding / Reclassification Analysis

- Exact target is half-open `[0x004af570,0x004af8af)`. Its size is `0x33f` / 831, ending with `retn` at `0x004af8ae`.
- Predecessor UID00033T ends exactly at `0x004af570` with bytes `... 5D C2 04 00`; there is no predecessor padding to absorb.
- Successor alignment is exactly one `0xcc` byte `[0x004af8af,0x004af8b0)`. It remains parent-only UID00033U documentation and does not extend UID0004BT.
- UID0004BU begins exactly at `0x004af8b0`; no target instruction, EH action, table, or literal crosses that boundary.
- Far EH actions at `0x005fe582-0x005fe605` are IDA-attached compiler chunks, not contiguous target bytes and not child pages.
- No target split is needed: all contiguous operations are one constructor and one source control flow.
- UID00033U covers constructor + one-byte pad + action + switch table/tail. It remains `Nested:8`, which is the existing relative address-sorted delta. UID0004BT/4BU/4BV remain `Nested:0`; changing aggregate Nested to a child count would corrupt following relative levels.
- Reclassifications: UID00033U split index false/blank; UID00033X generated base destructor false/blank with UID-preserving rename; UID0003IG compiler vtable data false/blank; UID0003NJ source-derived literals false/blank.

## Negative Evidence Summary

- No stack arguments are pushed at either constructor call.
- No target store creates `m_itemList`, a control pointer field, a row collection field, or any other derived data member.
- No separate helper call corresponds to stale `CreateMixItemDialogControls` or `ClearMixRows` names.
- No target call uses `AddChild`; the inherited API is `AddControl`, and wrapper ownership is explicit.
- No target reference reaches `g_pBackPane`; both OnShow arguments are zero.
- No ordinary caller, vtable cell, function pointer, or direct source call reaches `0x004b0870`; its sole route is constructor EH.
- No evidence supports an explicit handwritten Singleton assignment plus manual cleanup. That would duplicate the template base and alter construction-failure lifetime.
- No vtable/RTTI array or standalone resource-storage definition belongs in handwritten source.
- Physical adjacency to AddItemWithCount, Exchange, callback, or destructor bands does not transfer owner.
- IDA's polluted `boost::exception` type at DialogPane teardown is contradicted by RTTI, vptrs, object size, and current DialogPane docs.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name/signature: `MixItemDialog::MixItemDialog()`; current IDA `sub_4AF570` may be documented with this identity after approval, but B003 requests no IDB mutation.
- Source-facing helper identity: `Singleton<MixItemDialog>::~Singleton()` compiler instantiation for `sub_4B0870`; use the page title `MixItemDialogSingletonBaseDestructor`, not a free-helper name.
- Source-facing types: `RectBounds`, `EPFImageControlPane`, `ImageButtonControlPane`, `MyItemListPane`, `ScrollableControlPane`, and `ListPane` APIs already established in current docs.
- Accepted global name/type: `static MixItemDialog *g_pMixItemDialog = 0` via UID0002AY. Historical `unk_69B32C` is an IDA alias only.
- Descriptive local: `MyItemListPane *itemList`; it is not a member.
- Intentionally unchanged: later action/helper names and row structs are outside the exact constructor and remain on their accepted pages absent a direct contradiction.
- No IDA rename/type/comment edit was performed during research or callback; IDA remained read-only.

## First-Draft C++ Recommendation

Eligible destination R1, UID0004BT:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MixItemDialog::MixItemDialog()
    : DialogPane(L"", 9, 1),
      Singleton<MixItemDialog>()
{
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 292, 309);
    AddControl(new EPFImageControlPane(L"MIXITEM.EPF", 0, 1,
                                        &bounds, L"MIXITEM.PAL"));

    InitRectBounds(&bounds, 23, 273, 86, 297);
    AddControl(new ImageButtonControlPane(36, &bounds));

    InitRectBounds(&bounds, 85, 273, 148, 297);
    AddControl(new ImageButtonControlPane(21, &bounds));

    InitRectBounds(&bounds, 147, 273, 210, 297);
    AddControl(new ImageButtonControlPane(14, &bounds));

    InitRectBounds(&bounds, 209, 273, 272, 297);
    AddControl(new ImageButtonControlPane(22, &bounds));

    MyItemListPane *itemList = new MyItemListPane();

    InitRectBounds(&bounds, 37, 68, 264, 236);
    AddControl(new ScrollableControlPane(&bounds, itemList, 0, 0, 0));

    SetBackgroundResource(L"MIXITEM.EPF", NULL);
    SetHoverControl(1);
    SetFocusedControl(3);
    SetPendingControl(4);

    InitRectBounds(&bounds, 0, 0, 292, 309);
    OnCreate(&bounds, 0, NULL,
             g_mainUiLayerSlots.overlayPaneLayerContext);

    for (int itemIndex = itemList->GetItemCount() - 1;
         itemIndex >= 0;
         --itemIndex)
    {
        itemList->RemoveItems(itemIndex, 1);
    }

    OnShow(NULL, NULL);
    SlideOpenVertical();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Eligible destination R2, UID00008J:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MixItemDialog : public DialogPane,
                      public Singleton<MixItemDialog>
{
public:
    MixItemDialog();

    virtual int OnAction(unsigned int actionId);

    void AddMixItem(unsigned char itemId,
                    unsigned short itemSerial,
                    const wchar_t *itemName,
                    unsigned char style);

private:
    void SubmitMixPacket();
    void OnMixItemQuantity(unsigned int count,
                           unsigned char itemId,
                           unsigned char style);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Non-emitting destination R3, UID00033U:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Non-emitting destination R4, UID00033X after validator-preserving rename:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Non-emitting destination R5, UID0003IG:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Non-emitting destination R6, UID0003NJ:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Source-emitting destination R7, UID0002AY, retained exactly:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static AddItemDialog *g_pAddItemDialog = 0;
static MixItemDialog *g_pMixItemDialog = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R1 preserves exact order, operands, selectors, row-clearing behavior, and null/null OnShow arguments while expressing old-MSVC allocation/EH through normal C++. R2 expresses the original RTTI-proven base layout without raw offsets or invented fields. The implicit destructor is intentionally not declared as an authored out-of-line method: the compiler-generated scalar wrapper and Singleton base lifetime regenerate the observed clear/teardown route.

R3-R6 remain exactly blank because aggregate routing, EH-only template destruction, vtable/RTTI arrays, and literal storage are regenerated or covered by source. A comment marker would still create duplicate/pseudo-source and is therefore rejected.

## Final Recommendation

- Implemented target R1 and metadata `92/94`, owner/emitter UID00008J, reconstructable true, position 10, Nested 0.
- Implemented class R2 and `91/93`; exact 0x26c no-field layout, direct bases, controls, methods, lifetime, and compiler exclusions are recorded.
- Implemented UID00033U `92/94`, reconstructable false, blank emitter/position/formal, semantic owner UID00008J and Nested 8 retained.
- Completed the documented validator-preserving UID00033X rename; it is `93/96`, reconstructable false, blank emitter/position/formal, with owner UID00008J and Nested 0 retained.
- Implemented UID0003IG `92/95`, reconstructable false, blank emitter/position/formal, with semantic owner UID00008J retained.
- Implemented UID0003NJ `92/95`, reconstructable false, blank emitter/position/formal, with semantic owner UID00008J and Nested 0 retained.
- Implemented UID0002AY `92/95`, owner/emitter UID0000KE, reconstructable true, blank position, Nested 0, and exact R7 declarations preserved.
- Implemented UID0000KE `92/92`, preserving file route and adding exact source/compiler inventory. Broad UID00014T remains unchanged in score/owner/route with synchronized links/names.
- Verify-only UID0004BU, UID0004BV, UID00033V, UID000319, UID00031A, UID00008W, UID0000CE, UID00003T, UID00007A, and callback-template support were not broadened. Validator rename propagation touched only the UID00033X links in current reverse-reference pages; ExchangeDialogTail received the bounded exact-end/current-identity correction documented below.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md`.
- Implemented the exact metadata and Item Summary: `Parameterless DialogPane/Singleton-derived MixItemDialog constructor; builds the exact MIXITEM six-control tree, transfers a local MyItemListPane into ScrollableControlPane, clears its rows, initializes dialog selectors/lifecycle, and opens vertically.`
- Formal block R1 is installed exactly; report-to-destination equality check passed.
- Exact range/size/hash/signature/instruction/end/padding evidence; two callers and no-argument ABI; complete callee/control table; direct-base/RTTI/EBO/no-field layout; global lifetime; seven allocations/EH states; local-list ownership; row-clear loop; lifecycle args; compiler exclusions; rejected stale body and ownership alternatives; and score rationale are present.
- Exact owner, emitter, range, Nested, and source route are preserved. Position `10` is the only ordering change.

## Recommended Support Doc Changes

1. `by-class/MixItemDialog.md`: implemented `91/93`, R2, direct bases, 0x26c layout/no fields, full method inventory, typed global, resource/control/local-list/lifecycle facts, EH/scalar/compiler distinctions, UID00033X renamed identity, rejected `m_itemList`/manual helper assumptions.
2. `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md` UID00033U: implemented `92/94`, reconstructable false, blank emitter/position/formal R3, owner UID00008J and Nested 8 retained; exact three-child inventory, one-byte constructor/action pad, table/tail bytes, live-vs-retained submit evidence, and no-duplicate rationale are preserved.
3. UID00033X: completed validator-preserving rename to `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md`; implemented `93/96`, false, blank emitter/position, R4, exact 11-byte body/signature/one EH xref/RTTI/EBO/constructor state/scalar-copy/comparator/no-code proof. Old helper title/name remains only as historical rejected alias.
4. `by-type/by-vtable/MixItemDialogVtables.md`: implemented `92/95`, false, blank emitter/position, R5; exact cluster/slots/adjustors/successor, full RTTI hierarchy, and compiler-generated/no-manual-array disposition are present.
5. `by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md`: implemented `92/95`, false, blank emitter/position, R6; exact range/bytes/xrefs/literals and R1 source coverage are present.
6. `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`: implemented `92/95`, route and R7 retained; exact Singleton-backed Mix lifetime is present and old all-`0xff`/mixed-range state is historicalized.
7. `by-file/ItemDialogs.md`: implemented `92/92`, same path/route; exact Mix constructor/class/aggregate/helper/vtable/literal/global source disposition and generated uniqueness expectations are present without compressing other agents' ItemDialogs evidence.
8. `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md`: score/owner/emitter remain unchanged; UID0004BT score/body, UID00033U non-emission, UID00033X new path/source identity, and compiler/source split are synchronized without assigning the broad parent an owner.
9. UID0004BU/4BV/33V/319/31A and reusable UI/List support: verified without broadening. Current accepted bodies, scores, routes, raw-helper negatives, callback ownership, and unrelated details remain intact.

## Score And Metadata Recommendation

| Destination | Pre-callback | Implemented | Rationale/cap |
| --- | --- | --- | --- |
| UID0004BT | `86/90`, true, owner/emitter 00008J, blank pos, Nested 0 | `92/94`, same except position 10 | Exact source body, ABI, bounds, calls, layout, EH, callers, and no blockers; cap for lexical helper/file spelling. |
| UID00008J | `87/88` | `91/93` | Complete no-field class declaration and direct-base/lifetime evidence; later helper field spellings remain provisional. |
| UID00033U | `86/90`, true/emitter | `92/94`, false/blank | Exact split index and padding/table inventory; no authored aggregate source. |
| UID00033X | `88/92`, true/emitter | `93/96`, false/blank plus rename | Exact compiler-instantiation identity closes prior helper ambiguity. |
| UID0003IG | `89/92`, true/emitter | `92/95`, false/blank | Exact vtable/RTTI cluster and source-generated disposition. |
| UID0003NJ | `86/91`, true/emitter | `92/95`, false/blank | Exact strings/bytes/xrefs and constructor coverage. |
| UID0002AY | `89/92` | `92/95` | Exact zero bytes, storage split, xrefs, typed declarations, and Singleton lifecycle. |
| UID0000KE | `91/90` | `92/92` | Exact Mix source/compiler inventory improves module confidence; physical original split remains inferred. |

Score-improvement attempt:

- Signature blocker removed by both callers and no argument pushes.
- Base/layout blocker removed by RTTI hierarchy/BCD, object allocations, and scalar size path.
- Control/helper blocker removed by exact callee signatures and sibling current APIs.
- Field blocker removed: no derived fields exist; local list flow is exact.
- Lifetime/EH blocker removed by FuncInfo/unwind actions and Singleton comparator.
- Range/padding blocker removed by full bytes, predecessor return, final return, one-byte successor pad, and successor function.
- Source-placement blocker narrowed to original filename spelling only; current route is implementation-ready.
- No unresolved issue blocks formal C++ or score improvement.

## Open Questions With Attempted Resolution

- Was the original file named `ItemDialogs.cpp` or `MixItemDialog.cpp`? All current owner routes, contiguous family code, globals, and sibling accepted reports support ItemDialogs; no path string/PDB proves a separate file. Use the established route and cap file confidence at 92.
- Was singleton publication manually written? No. RTTI direct-base identity, `+0x26c` adjustment, EH state, and identical accepted Singleton comparator prove template-base construction/destruction.
- Is there a derived list member? No. Object size and local register flow disprove it.
- Does `MyItemListPane` receive the owner? No. Its constructor is parameterless; ScrollableControlPane receives it.
- Does OnShow use `g_pBackPane` as the AddItem sibling does? No. Exact caller pushes are null/null.
- Are allocation null branches authored? No defensible evidence supports that. They are old-MSVC new-expression lowering; R1 is behaviorally/source-shape correct.
- Is an explicit Mix destructor declaration required? No authored ordinary destructor body is identified in this scope. Virtual base behavior makes the implicit destructor virtual, and compiler-generated scalar/Singleton teardown reproduces observed lifetime.
- Exact original local variable names and button semantic labels are unavailable, but R1 uses descriptive `bounds`, `itemList`, and `itemIndex` without changing binary behavior. This is a confidence cap only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 inspected the current manual rows. UID00014T and UID0002AY are stale; UID0004BT/33U/4BU/4BV/33V/319/31A/33X/3NJ are absent; UID00008J, UID0003IG, and UID0000KE are stale. The following is exact supervisor-owned replacement/addition text. B003 must not edit manual coverage.

### `by-memory/-coverage-report.md`

Replace the stale UID00014T row and add its Mix subset in address order:

```text
    - [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md) 0x004ae4c0-0x004b0ba5 | mixed split inventory | ItemExchangeMixDialogs : not_reconstructable : 90% : very-strong : Non-emitting mixed ItemDialogs/ExchangeDialog inventory with exact class/source children, retained no-route packet helpers, callback/template support, compiler destructor/thunk strips, tables, and padding; no single owner or aggregate C++ is valid.
        - [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) 0x004af570-0x004afb80 | method-cluster split index | MixItemDialogCore : not_reconstructable : 92% : very-strong : Non-emitting exact split index for the constructor, one-byte pad, OnAction, switch table, and tail alignment; UID0004BT/UID0004BU carry source and UID0004BV carries compiler table data, so aggregate emission is blank.
            - [UID:0004BT][0x004af570-0x004af8af.MixItemDialogConstructor](by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md) 0x004af570-0x004af8af | constructor | MixItemDialogConstructor : reconstructable : 92% : very-strong : Exact parameterless DialogPane/Singleton-derived constructor with 0x26c no-field layout, MIXITEM six-control tree, local MyItemListPane ownership transfer, selectors, row clearing, lifecycle, callers, EH/compiler exclusions, and complete formal C++.
            - [UID:0004BU][0x004af8b0-0x004afb65.MixItemDialogOnAction](by-memory/0x004af8b0-0x004afb65.MixItemDialogOnAction.md) 0x004af8b0-0x004afb65 | method | MixItemDialogOnAction : reconstructable : 88% : very-strong : Mix action dispatcher with add/remove/submit/cancel cases and active inline mix-submit path; retained helper UID00033V remains a separate no-direct-route source-shaped copy.
            - [UID:0004BV][0x004afb65-0x004afb80.MixItemDialogActionSwitchTable](by-memory/0x004afb65-0x004afb80.MixItemDialogActionSwitchTable.md) 0x004afb65-0x004afb80 | switch table/alignment | MixItemDialogActionSwitchTable : not_reconstructable : 86% : strong : Compiler-generated action switch targets followed by alignment; no standalone source body.
        - [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) 0x004afb80-0x004afcc0 | retained raw helper | MixItemDialogSubmitPacketHelper : reconstructable : 88% : strong : Retained no-direct-route mix packet helper with exact opcode/row serialization and first-draft source, while the live action case contains the active inline equivalent.
        - [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) 0x004afcc0-0x004afe38 | method | MixItemDialogQuantityPromptHelper : reconstructable : 88% : very-strong : Mix row add/quantity-prompt helper with exact callback binding and direct/non-stackable paths.
        - [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) 0x004afe40-0x004afff7 | callback method | MixItemDialogQuantityCallback : reconstructable : 88% : very-strong : Quantity callback target that resolves inventory state, formats row fields, and appends the selected mix row.
        - [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md) 0x004b0870-0x004b087b | source-declared/generated-binary base destructor | Singleton<MixItemDialog> base destructor : not_reconstructable : 93% : very-strong : Exact eleven-byte EH-only Singleton base-destructor instantiation with direct +0x26c RTTI/EBO identity, one constructor-unwind xref, typed singleton clear, and exhaustive no-handwritten-helper proof.
```

Add the resource row at its address-sorted location:

```text
    - [UID:0003NJ][0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings](by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md) 0x0061a37c-0x0061a3ac | source-derived UTF-16 literals | MixItemDialogResourceStrings : not_reconstructable : 92% : very-strong : Exact MIXITEM.PAL/MIXITEM.EPF bytes and target-only xrefs; constructor source carries both literals and no separate data emitter is valid.
```

Replace stale UID0002AY row:

```text
    - [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) 0x0069b328-0x0069b330 | global pointer pair | ItemDialogSingletonGlobals : reconstructable : 92% : very-strong : Exact zero-initialized AddItemDialog and MixItemDialog pointer slots with per-slot xrefs, typed declarations, neighboring globals split away, and RTTI/EH-proven Singleton<MixItemDialog> publication/destruction lifecycle.
```

### `by-class/-coverage-report.md`

Replace UID00008J row:

```text
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md) : reconstructable : 91% : very-strong : ItemDialogs-owned 0x26c DialogPane plus Singleton<MixItemDialog> class with no derived fields, complete declaration/child route, exact constructor/action/quantity inventory, typed singleton lifetime, vtables/RTTI, local list ownership, and compiler-generated destructor/EH exclusions.
```

### `by-type/by-vtable/-coverage-report.md`

Replace UID0003IG row:

```text
- [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md) : ignored : 92% : very-strong : Non-emitting source-declared/generated-binary MixItemDialog primary/secondary/tertiary vtable and RTTI cluster; exact slots, adjustors, constructor stores, eight-entry hierarchy, Singleton +0x26c EBO, and AddMixing successor are documented while the class declaration regenerates all tables.
```

### `by-file/-coverage-report.md`

Replace UID0000KE row:

```text
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) : reconstructable : 92% : very-strong : Exact ItemDialogs source route for AddItem, AddItemWithCount, MixItemDialog, AddMixing, typed globals, and accepted method children; preserves separate MyItemListPane/ExchangeDialog/FunctionObjects ownership, retained no-route helpers, compiler non-emission, and the remaining original physical-file-name caveat.
```

Reason B003 must not apply these directly: manual `-coverage-report.md` files are supervisor-owned; validator-generated coverage is a separate mechanism and does not authorize manual edits by the B agent.

## Follow-Up Actions

- External supervisor/validator ownership: report validation, manual coverage application, report execution, count, path, move, and archive state are outside this artifact and are neither asserted nor directed by B003.
- B003 callback state: implementation, scoped validation, UID-preserving rename, generated refresh/readback, ledger reconciliation, and checklist reconciliation are complete; no B003 implementation item remains.
- A-agent or additional B-agent action: none identified by this callback.

## Confidence

- Recommendation confidence: `94/100` for target; direct bytes, callers, RTTI, EH, and current API contracts converge.
- Score confidence: high. `92/94` matches sibling final-source constructors while reserving points for original lexical/file-name uncertainty.
- Remaining uncertainty: original physical filename, original local identifiers, and exact template header/static-member spelling. None affects owner, ABI, behavior, layout, formal C++, or no-code dispositions.

## Validator Results

- Working directory for every command: `source-3/project-documentation` (validator output resolved the active root as `C:\FastStorage\NTK_Sources\source-3\project-documentation`).
- Command form for scoped pages: `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; final command added `--wait-generated`.

| Current destination / purpose | Command ID | Timestamp | Exit / ok | Relevant result and side effects |
| --- | --- | --- | --- | --- |
| UID0004BT target | `000000010463` | `2026-07-13T17:52:15-04:00` | `0` / `ok:1` | Applied `92/94`, position 10, R1 hash; metadata/registry/reference/projected-stats updates; generated deferred. |
| UID00033U aggregate | `000000010467` | `2026-07-13T17:53:08-04:00` | `0` / `ok:1` | Applied `92/94`, true->false, emitter->blank, block->blank; generated deferred. |
| UID0003IG vtables | `000000010470` | `2026-07-13T17:53:48-04:00` | `0` / `ok:1` | Applied `92/95`, false/blank R5; validator registered current path and refreshed references; generated deferred. |
| UID0003NJ resources | `000000010473` | `2026-07-13T17:54:36-04:00` | `0` / `ok:1` | Applied `92/95`, false/blank R6 and path mapping. Reported pre-existing `missing_ref_uid 0003IH`; no target-specific failure; generated deferred. |
| UID00033X rename/new path | `000000010488` | `2026-07-13T18:01:44-04:00` | `0` / `ok:1` | Validator-preserved UID path rename, applied `93/96`, true->false, emitter/block->blank, updated four reverse-reference source paths and nine links. Repeated pre-existing UID0003IH warnings arose while propagating class links; generated deferred. |
| UID00008J class after rename propagation | `000000010489` | `2026-07-13T18:02:12-04:00` | `0` / `ok:1` | Current `91/93` R2 validated; four pre-existing missing UID0003IH references reported; generated deferred. |
| UID0000KE file after final callback wording | `000000010491` | `2026-07-13T18:02:39-04:00` | `0` / `ok:1` | Current `92/92` route/inventory validated; generated deferred. Earlier successful `10483/10490` are superseded by this current page result. |
| UID00014T broad support after rename | `000000010492` | `2026-07-13T18:02:48-04:00` | `0` / `ok:1` | Score/owner/route unchanged `90/92`/none/blank; synchronized Mix evidence and renamed link; generated deferred. |
| UID0002AY globals after rename | `000000010493` | `2026-07-13T18:02:56-04:00` | `0` / `ok:1` | Current `92/95` R7 and renamed lifecycle link validated; generated deferred. |
| UID00014V bounded rename-reference correction | `000000010494` | `2026-07-13T18:03:42-04:00` | `0` / `ok:1` | Validated propagated link plus exact `[0x004b0870,0x004b087b)` end/current Singleton-base identity; score/route unchanged; generated deferred. |
| Final waited ItemDialogs refresh | `000000010495` | `2026-07-13T18:03:59-04:00` | `0` / `ok:1` | `generated_refresh:completed` with matching command ID/timestamp; validator rebuilt 4735-node/3839-edge autogen registry and refreshed generated metadata. Global warnings were unrelated existing marker/fallback inventory. |

- Additional successful superseded scoped commands retained for audit: globals `10476`, class `10480`, file `10483`/`10490`, and broad support `10484`; later rows above validate their current post-rename content.
- Generated header freshness: B003's waited command `10495` completed at `2026-07-13T18:03:59-04:00`. Final read-only self-review observed the newer external header `validator-command-id: 000000010511` and `validator-refreshed-at: 2026-07-13T18:10:06-04:00`; newer-than-waited freshness is current, and all Mix structure/count assertions were rerun against command `10511` content.
- Generated structural proof: UID00008J class begins at line 396 and closes at line 414; first qualified definition begins at line 417. Definition counts are constructor 1, OnAction 1, SubmitMixPacket 1, AddMixItem 1, and OnMixItemQuantity 1. UID routes are UID0004BT 1 and UID0002AY 1; UID00033U/33X/3IG/3NJ are each 0.
- Generated source proof: R1 appears once at lines 417-462; R7 declarations appear together once at lines 575-576; `ClearActiveMixItemDialog`, old UID00033X path, raw Mix vtable/RTTI arrays, and Mix-specific empty/unattached markers are absent. Existing unrelated Empty Emitter Markers and two unrelated `[[No Children Attached]]` lines remain outside this accepted scope.
- Exact formal-block comparison: report R1-R7 each compare byte-for-byte equal to their current destination managed blocks.
- Validator-owned side effects were produced only by the validator. B003 did not manually edit `tools/validator.ini`, generated C++, generated reports, projected stats, tracker, audit, queue, lock, or lifecycle state.
- MCP read request 53 used an unavailable method name and was replaced by supported `xrefs_to`; this remains evidence-tool provenance, not a validator result or MCP outage.

## Changed Files

- Modified ordinary pages:
  - `by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md`
  - `by-class/MixItemDialog.md`
  - `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md`
  - `by-type/by-vtable/MixItemDialogVtables.md`
  - `by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md`
  - `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`
  - `by-file/ItemDialogs.md`
  - `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md`
  - `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md` only for validator-propagated UID00033X link plus bounded exact-end/current-identity correction.
- Validator-preserving rename: removed old mapped path `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md` and registered current UID00033X path `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md` through command `10488`.
- Updated report artifact: `tools/leaser/Agents/Agent-B003/research/0004BT-MixItemDialogConstructor-source-quality.md`.
- Read-only verify-only dependencies: UID0004BU, UID0004BV, UID00033V, UID000319, UID00031A, UID00008W, UID0000CE, UID00003T, UID00007A, callback-template support, and their accepted code/scores/routes were not edited.
- Forbidden/manual sets: no manual `-coverage-report.md`, auto-generated C++, generated/tracker/audit/supervisor/validator/lifecycle/archive file, or IDA state was manually edited. The exact supervisor-owned coverage text above remains pending external ownership.
- Lease-boundary correction: at `2026-07-13T21:59:30Z`, B003 acquired the UID00033X page plus five reverse-reference support leases together to protect rename propagation. The physical old-path-to-new-path move had begun, but the helper content patch and rename validator had not run when the user issued the one-file correction. B003 immediately released all five support leases and verified `current_leases.md` retained only the old-mapped helper lease; the helper content patch and command `10488` then completed the rename under that single lease, after which it was released. Every subsequent support validation used one file lease at a time and released it before the next acquisition.
- Final lease proof: `tools/leaser/Agents/Agent-B003/current_leases.md` contains no B003 lease.
- Lifecycle boundary: B003 performed no `execute_report`, report probe, lifecycle, move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Exact Gate-1 report SHA `C21DAA9E3CF7D9F736CDD4AAC737FE2688CD252EB8A64D54FC62313FD1BEF749` was supervisor-accepted before implementation.
- [x] Target/support set implemented: UID0004BT, UID00008J, UID00033U, UID00033X rename, UID0003IG, UID0003NJ, UID0002AY, UID0000KE, and bounded UID00014T sync; validator-propagated UID00014V link/current-identity correction is recorded.
- [x] Current target state and actual evidence checked are recorded.
- [x] Claim And Incorporation Ledger C01-C20 contains one legal action and callback verification state per claim plus exact destination/validator proof.
- [x] Metadata/score changes are applied exactly as accepted.
- [x] Score-limiting blockers are resolved or retained only as bounded lexical confidence caps.
- [x] Owner/emitter/reconstructable changes are applied.
- [x] UID00033X validator-preserving rename and UID00033U/3IG/3NJ reclassifications are complete; no new target child was created.
- [x] Source placement, range, split, padding, reclassification, and IDA name/type/comment decisions are applied or preserved.
- [x] Formal destination blocks R1-R7 are byte-for-byte equal to the accepted report; no side-section C++ substitute exists.
- [x] Third-party import directive is not applicable; this is NexusTK project source, not a third-party embed.
- [x] Exact target/support facts are incorporated at report-level detail.
- [x] Historical stale drafts, rejected alternatives, compiler/source distinctions, and negative evidence are preserved.
- [x] Wave2/Wave3 artifacts remain historical leads rather than current authority.
- [x] Open questions are closed or capped with exact evidence-backed rationale.
- [x] One current scoped validator result exists for every actually changed/renamed ordinary page; lease correction and subsequent one-file boundaries are recorded.
- [x] Final waited generated refresh/read-only ItemDialogs.cpp checks are complete; exact manual coverage text remains external supervisor-owned.
- [x] Every C01-C20 ledger row is in a legal callback action/state with destination/validator proof.

Implementation callback pass:

- [x] Report was accepted by supervisor for implementation at the exact Gate-1 hash above.
- [x] All accepted target/support doc details are incorporated at report-level detail.
- [x] Claim And Incorporation Ledger has final permitted action/state and proof for C01-C20.
- [x] Metadata/score/owner/emitter/reclassification/rename/C++ changes are applied; no accepted item is excluded or blocked.
- [x] Historical/stale assumptions, rejected alternatives, compiler/source distinctions, and negative evidence are preserved.
- [x] Open questions are resolved or retained only with evidence-backed lexical/file-name caps.
- [x] Scoped validators ran for every actually changed/new/renamed ordinary page; command IDs/timestamps/exits/ok/side effects are recorded.
- [x] Final B003 `--wait-generated` command `10495` completed; latest observed external header `10511` is newer and retains the exact generated structure/count proof.
- [x] Generated ItemDialogs.cpp has the class closed before qualified definitions, R1 exactly once, all existing Mix definitions once, R7 once, no UID0004BT/33U/33X/3IG/3NJ empty or unattached markers, no handwritten Mix vtable/RTTI arrays, no duplicate/wrong-range emitters, and no stale helper body.
- [x] Lease-boundary correction is recorded accurately; every lease is released and no implementation item remains.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000010532","destination_path":"executed-b-agent-research/B003/0004BT-MixItemDialogConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004BT-MixItemDialogConstructor-source-quality.md","timestamp":"2026-07-13T18:31:33-04:00","uid":"0004BT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
