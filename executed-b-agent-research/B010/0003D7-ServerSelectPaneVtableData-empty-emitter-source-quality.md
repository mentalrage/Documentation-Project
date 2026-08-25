# UID0003D7 ServerSelectPane Vtable Data Source-Quality Research
** TARGET-REPORT-UID:0003D7 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Project context: this report supports a local old-game preservation effort for an unsupported NexusTK client. The objective is exact runtime compatibility plus source that resembles plausible human-written late-1999 through mid-2000s C++, not decompiler output.

## Finalized Report / Current Recommendation

- Implemented ordinary recommendation: [UID:0003D7] remains the exact reconstructable `ServerSelectPane` compiler-vtable child with semantic owner/emitter [UID:0000D2], emitter position `20`, score `94/98`, and the formal compiler-generated ABI marker from Section 22. Manual coverage and IDA/lifecycle work remain supervisor-owned.
- Final disposition: the 156 target bytes are three COL-prefixed vtable views generated from one human source class. Do not emit raw dword arrays, complete-object locators, adjusted destructor thunks, or a scalar-deleting wrapper as handwritten C++.
- Implemented source repair: [UID:0000D2] emits the complete `ServerSelectPane` declaration through H and `#include "ServerSelectPane.h"` plus `[[CHILDREN]]` through CPP. The declaration uses direct `DialogPane` and `Singleton<ServerSelectPane>` bases, one `ServerSelectDirectory *m_serverDirectory` field, and the corrected period-compatible virtuals `OnControlCommand(int,int)` and `UpdateActionButton()`. It intentionally has no explicit derived destructor.
- Implemented documentation repair: the complete 39-cell table, three COL records, eight-base RTTI graph, store/xref triads, code-family evidence, source/header route, corrected historical method names, negative evidence, and score rationale are incorporated into the target and listed support pages without pruning prior valid behavior evidence.
- Confidence: `98` for target bytes, boundaries, table identities, RTTI, and store xrefs; `95` for the inferred human source declaration and source order.
- Gate 2B frame repair: reproduced public `set_type` behavior proves that the exact semantic `OnControlCommand(ServerSelectPane *, int, int)` function type is accepted while the first function-type-stage physical stack row remains `Block` / `void *` / `+0x1c` / `4` and only `arg_4` becomes `notifyCode` / `int` / `+0x20` / `4`. The separate stack rename succeeds, and the explicitly bound stack-target type stage accepts source text `int` but canonically renders that physical row as `controlIndex` / `signed __int32` / `+0x1c` / `4`. Reconstructed C++ remains `int`; `signed __int32` is only the observed IDA physical-frame spelling.
- Gate 2B comment-channel repair: live comment readback proves `Block` at `0x57475b` and `0x574766` is an address regular comment, not a function comment. The corrected contract preserves that address comment and adds the evidence-backed adjustor summary only in the function regular channel; all repeatable channels remain blank.

## Supporting Research

- Lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the artifact path and validator-owned history being acted on; no ordinary report prose asserts a current lifecycle phase.
- Queue evidence at assignment time: `auto-generated/-ag-research-tracker.md` listed UID0003D7 under uncovered reconstructable by-memory work at `85/91`, zero direct/additional reports. The then-current generated `NexusTK/login/ServerSelectPane.cpp` contained an empty marker for UID0003D7.
- Live IDA evidence was collected read-only from session `supervisor-uid0000KZ-gate2b-20260814`, canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Public schema-1 `runtime_attestation` at `2026-08-15T01:33:19.735205Z` returned `ok:true`, no errors, and matching canonical listener/worker/session identity.
- Gate 1 pre-callback target snapshot: 4,083 bytes, 57 lines, SHA256 `CCBD889C1D97852427C6AC12475D13BFCF79FDA5CC23A063EF691D89DBD49AE1`.
- Gate 1 pre-callback support snapshots used:
  - `by-class/ServerSelectPane.md`: 15,577 bytes, 163 lines, SHA256 `85EFB81B0FADBFFAF71D4B76EB97322964C643F84DB7C33CF7EC88D9EB68D8DD`.
  - `by-file/ServerSelectPane.md`: 17,693 bytes, 186 lines, SHA256 `91D62D6D3775E601AEFEF7B3D009812D53DFC043227B6B4BB80EFB8EC7704ECB`.
  - `by-memory/0x00573d20-0x005747df.ServerSelectPane.md`: 32,820 bytes, 278 lines, SHA256 `0EC418AB70EE2D673774788A35D69094BAFAE32A375D0F26696C23D98D8B948D`.
  - `by-item/ServerSelectHelpers_574510_5745b0.md`: 16,197 bytes, 160 lines, SHA256 `85942752ADD000F182C77DB5D77B489E31408F93EE0355C1A958D62684C48009`.
  - `by-global/g_pServerSelectPane.md`: 12,756 bytes, 151 lines, SHA256 `F315D9AC9593EBB80D41989802885CCB4E635CC8E229A132F8FA161598D165E4`.
  - `by-memory/0x00624c60-0x00624f20.SimpleServerSelectReadOnlyData.md`: 13,183 bytes, 101 lines, SHA256 `4C206729AE743C7190219C043C7B8E5CE8D20C30A7858A2E2BA14DAC64C00FA7`.
- The Gate 1 pre-callback generated snapshot was physically reread during the repair at `2026-08-15T02:25Z`, without editing either file: `auto-generated/NexusTK/login/ServerSelectPane.cpp` SHA256 `3658B44E9B300174F8F121A5FFC4F03FE7BDDDC7B732FC63AE722CF4EC05AEA6`, 1,194 bytes/22 lines, and `auto-generated/NexusTK/login/ServerSelectPane.h` SHA256 `6DA64A124C76A8FBCC1D803AFA9453C60D50DFACAEE4BA37787E8356C6F30B79`, 467 bytes/10 lines. Both pre-callback files identify validator command `000000023750` and refresh time `2026-08-14T21:40:13-04:00`. Command `000000023779`, its refresh time, and its CPP/H hashes in Validator Results are the dated ordinary-callback receipt only; the supervisor rereads current validator-owned generated authority dynamically at Gate 2A and final verification, and a later coherent command/hash may advance without invalidating the source-content findings recorded here.
- Historical generated snapshots are retained only as superseded observations: command `000000023745` at `2026-08-14T21:20:17-04:00` produced CPP SHA256 `EA72862CD104AF67765E4FA6B6FAA0610F45918A8EA2B26707ABF48ABA22E200` and H SHA256 `FAF65059D67D9358F4A3CEF70F1374BA777D45E5F3A324BA5B1AA7F017B1840F`; the initial unbound drafting read recorded CPP `EA72C46F3536A7A4643040163DAB3442EE84F3D6AC204C3689BA04C5121DA04B` and H `FAF63D771C0E61A3B77563DD6DAD87BEA74C660458BC4268ED8B68E43D3EB902`. Neither superseded pair is a current-state hash or a Gate 2 readback authority.
- Matching executed reports `B013/0001HR-ServerSelectPane-source-quality.md` and `B005/0002XN-g_pServerSelectPane-empty-emitter-source-quality.md` were used as leads only. Neither directly covers UID0003D7.
- Accepted ordinary callback completed on 2026-08-14. Final ordinary snapshots are: target `C1186D486A4CD2BD8A6821B27724377499B06E28CF629781A9F50DFC871BD60E` (13,972 bytes/171 lines), class `E0472F9810BCC938EE1348CE393F8D00137DA638B8BECB25150544C9D56AABB2` (18,820/203), file `FB9C5090D05934E0ABE9362308E7A38AF29C810AFE00942A7FAA49915D9C83B6` (20,412/195), broad executable `7B11FF96E7771B028661C0561616684FD43D053213479A637DF1F6A08BD23AC6` (35,191/286), helper item `B1717F27E1AE553A9D0015D06B6412B2BB569538698F79B0A9336DED07C1EE76` (16,648/161), and mixed parent `1A258025619EA0D6DBC27581E0A3076316FB4F645A3F4B065E30D7F3E09F2F3E` (15,145/111). Global UID0000S8 was already exact and remains unchanged at `F315D9AC9593EBB80D41989802885CCB4E635CC8E229A132F8FA161598D165E4` (12,756/151).
- Dated Gate 2B failure and rollback on 2026-08-15: fresh canonical preflight matched, and A3D7-02 through A3D7-09.1 read back exactly. A first stack-target type attempt supplying only the variable binding returned `Stack variable name is required` and made no change. The accepted retry supplied the stack variable through the endpoint's required `name` binding and also supplied `variable` for compatibility; it accepted source text `int`, while physical `stack_frame` canonically returned `controlIndex` / `signed __int32` / `+0x1c` / `4` and retained `notifyCode` / `int` / `+0x20` / `4`. That literal contract contradiction caused an immediate hard stop before A3D7-10 or any later action. Nothing was saved; the unsaved worker was discarded, and reopened canonical state was proven restored at 143,207,841 bytes with SHA256 `B16863A05EA9E22E4911EC228FE7BD0C25D6DBE1639E791A400D0E311CFA143B`, all eight raw `sub_*` names restored, and all destination names absent.
- Dated comment-channel Gate 2B failure and rollback on 2026-08-15: a later fresh canonical prestate matched, and the early rename, type, frame, and comment actions read back until the EventHandler-adjustor comment preflight exposed that `Block` was the address regular comment at `0x57475b`, while function regular, address repeatable, and function repeatable were blank. The supervisor hard-stopped before that adjustor comment write, saved nothing, discarded the unsaved worker, and reopened canonical state. The canonical IDB was restored at 143,207,827 bytes with SHA256 `E69D27FDD92B4265CA1865FFE05FCF501244F70F424033EB02DF5123C5056C1A`; all eight raw `sub_*` names, original frames, blank function comments, and address regular comments `Block` at both `0x57475b` and `0x574766` were restored.

## Target

- Target UID: `0003D7`.
- Additional target UIDs: none. Support pages are implementation destinations, not additional report-coverage declarations.
- Target path: `by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md`.
- Exact range: `[0x00624d24,0x00624dc0)`, `0x9c`/156 bytes, exactly 39 independent four-byte IDA data items.
- Pre-callback scores and parent state were `COMPLETION:85`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000D2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D2`, blank position, and blank CPP/H. Current ordinary state is `94/98`, position `20`, the same owner/reconstructable/emitter route, exact formal CPP marker, and blank H.
- Source queue/report row: uncovered reconstructable by-memory target with zero report coverage and a generated empty marker.
- Semantic owner: [UID:0000D2] `ServerSelectPane`; source root: [UID:0000NO] `NexusTK/login/ServerSelectPane.cpp`.

## Current Target State

- The accepted ordinary callback corrected target metadata to `94/98`, position `20`, and installed the exact compiler-generated ABI marker while preserving class owner/emitter UID0000D2 and `RECONSTRUCTABLE:TRUE`.
- The target now contains the exact 39-cell inventory, six locator/table subrange hashes, all three COLs, the complete eight-base hierarchy, all slot identities, store/xref triads, current report-time IDA state, source declaration rationale, corrected virtual names, boundaries, rejected history, and score basis.
- The stale broad primary-table extent is retained only in rejected history; the current primary table is exactly `[0x00624d28,0x00624d84)`.
- The target Item Summary now states its finite compiler-generated ABI role; `Nested:0` remains correct.
- The dated ordinary-callback CPP readback from command `000000023779` resolved UID0003D7 and UID0000D2 and retained independent empty markers UID0000D1, UID0003D9, UID0000VG, and UID0001HR as separate work.
- The dated ordinary-callback H readback from command `000000023779` contained the unchanged UID0000S8 global route and the complete UID0000D2 class declaration with required base includes. The supervisor establishes current generated authority by a fresh dynamic reread at Gate 2A/final verification rather than by treating this command or hash as permanently current.
- Current IDA has decorated names on all three table heads, blank table-head types/comments, compiler-generated names on the eight related functions, incorrect decompiler types on the destructor wrappers, and a forward-like non-UDT `ServerSelectPane` type name rather than a safe complete UDT.

## Executive Recommendation

- Keep UID0003D7 as one locator-inclusive vtable child. Its three views belong to one class and one source declaration; splitting by view would create duplicate ABI artifacts without a source-level boundary.
- Keep `CANONICAL_OWNER:0000D2`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000D2`; assign position `20`.
- Emit only the target-specific ABI marker from UID0003D7. Emit the human class declaration from UID0000D2 H and route method children from UID0000D2 CPP.
- Correct stale source-facing method names: `0x00574340` is `ServerSelectPane::OnControlCommand(int controlIndex, int notifyCode)`, not `OnDialogAction(int)`; `0x00574440` is `ServerSelectPane::UpdateActionButton()`, not `UpdateScrollButtons()`.
- Keep the exact semantic `OnControlCommand(int controlIndex, int notifyCode)` prototype, but treat physical frame presentation as separately mutable metadata: function `set_type` must first read back `Block` / `void *` at `+0x1c` and `notifyCode` / `int` at `+0x20`; the dedicated stack rename then produces `controlIndex` / `void *`, and the explicitly bound stack-target type stage must finally read back `controlIndex` / `signed __int32` at `+0x1c`. The source declaration remains `int controlIndex`.
- Treat `0x00574310`, `0x00574750`, `0x0057475b`, `0x00574766`, and `0x00574780` as destructor/EH/compiler-lowering evidence. The source class needs no explicitly authored destructor or manual singleton/vptr stores.
- Preserve the address regular comments `Block` at `0x0057475b` and `0x00574766`; add the two adjustor summaries only as function regular comments. Function-comment writes must not be described as replacing those address comments.
- No new by-vtable page is recommended: the exact by-memory child already owns the complete ABI inventory and a parallel type page would duplicate the same three-view evidence.

## Supervisor Active Recheck

- The original report-first boundary is historical. Exact Gate 1 SHA `55BC727CB72ED029F051CB96D7C41667287FB36ECDBF031787D3ECC0286C3578` authorized B010's ordinary-document implementation callback; generated files remained validator-owned, and coverage, tracker/audit, lifecycle, and IDA edits remained forbidden.
- The target did not require a range split: all 39 items are exact `ServerSelectPane` COL/vtable cells, and the predecessor/successor boundaries are independently named and referenced.
- Every source-bearing dependency needed to explain the vtable was checked. Human source is the UID0000D2 declaration plus existing/future exact method children; all target bytes and destructor adjustors/wrappers are compiler-generated.
- The empty emitter is resolved in ordinary/generated state rather than deferred: UID0003D7 has a formal no-raw-ABI CPP marker and UID0000D2 has formal CPP/H. Manual coverage, IDA mutation, final verification, and lifecycle execution are supervisor-owned and were not performed by B010.

## Inference Research Guidance Check

- Direct IDA facts are kept separate from documentation and inference. Exact bytes, cells, values, names, COL fields, RTTI PMDs, xrefs, function ranges, frames, and comments are IDA facts.
- Source owner/path, access labels, lexical names, declaration order, and implicit-destructor choice are inference constrained by exact ABI facts, analogous accepted project headers, and existing source-tree routing.
- Existing docs were treated as hypotheses where they used `OnDialogAction`, `UpdateScrollButtons`, broad primary-table bounds, or blank formal source. Current `DialogPane` declaration and vtable slot map supersede those names.
- Historical Wave2/Wave3 mentions were encountered in support docs and ignored as stale workflow/source authority. Useful historical observations were independently rechecked through current docs and live IDA.
- The final C++ uses period-compatible virtual syntax and ordinary class inheritance. It contains no `override`, fixed-address vtable arrays, IDA labels, decompiler temporaries, manual this-adjustment, or manual RTTI.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best supported resolution | Classification |
| --- | --- | --- | --- |
| Three named vtable heads could imply three classes | COL type descriptor, shared CHD, PMD offsets, constructor/destructor stores | One `ServerSelectPane` complete object with primary, EventHandler `+0xa0`, and TimerHandler `+0xa4` views | direct ABI fact |
| Old primary extent ended at `0x00624d88` | 39 item boundaries and COL location at `0x00624d84` | Primary table is exactly `0x00624d28-0x00624d84`; `0x00624d84` is the secondary COL pointer | direct correction |
| `OnDialogAction(int)` | primary slot `+0x48`, `retn 8`, current `DialogPane` declaration/vtable | `OnControlCommand(int controlIndex, int notifyCode)` | high-probability source inference |
| Function prototype versus physical first-argument metadata | reproduced function `set_type` readback retained `Block` / `void *` at `+0x1c` while accepting the exact semantic prototype and normalizing only `notifyCode` at `+0x20`; stack rename then produced `controlIndex` / `void *`; the accepted explicitly bound stack-target type call took source text `int` but physical `stack_frame` canonicalized it to `signed __int32` | preserve both literal intermediate frames, then require the final physical row `controlIndex` / `signed __int32` while retaining semantic source type `int`; each stage keeps full-frame hard stops | reproduced endpoint fact plus source/physical-spelling distinction |
| `UpdateScrollButtons()` | primary slot `+0x4c`, current `DialogPane::UpdateActionButton`, body updates action/scroll controls | `UpdateActionButton()` | high-probability source inference |
| Explicit destructor | shared base virtual-destruction contract, ordinary cleanup, scalar wrapper, adjustors, no derived resource teardown | rely on implicit virtual destructor; do not author a derived destructor | compiler/source-shape inference |
| Singleton representation | RTTI direct base PMD `+0x26c`, EBO overlap, global lifecycle | direct empty `Singleton<ServerSelectPane>` base plus one pointer member | direct ABI plus source inference |
| Member name/type | constructor caller and store, existing complete `ServerSelectDirectory` UDT | `ServerSelectDirectory *m_serverDirectory` | strong descriptive inference |
| Header placement | external constructor caller, global H route, analogous login pane headers | complete class in `ServerSelectPane.h`; own CPP includes it | source-tree inference |
| Raw vtable source | decorated MSVC RTTI, COLs, adjustor thunks, scalar wrapper | compiler-generated from declaration; no raw arrays | direct compiler-pattern fact |
| Adjustor `Block` comments | live `get_comments` returned address `regular: Block` and blank function regular/address repeatable/function repeatable at both `0x57475b` and `0x574766` | preserve each address regular comment; add a separate function regular summary through the function-comment channel | reproduced channel fact |
| Separate by-vtable page | exact locator-inclusive by-memory child already complete | reject duplicate page; keep type evidence in target/class docs | routing inference |
| Score blockers | all cells, RTTI, xrefs, source declaration, method identities, boundaries checked | raise target to `94/98`; remaining uncertainty is stripped lexical/access style, not behavior | score conclusion |

Rejected alternatives are a `ServerSelectPaneVtables.cpp` source file, three independent vtable children, file ownership by `MainMenuPane`, a class-static singleton pointer, a manual destructor with vptr stores, a raw ABI array, C++11 `override`, and retaining decompiler names/types.

## Evidence Standards Used

- Primary evidence: live IDA item boundaries, bytes, dword values, named symbols, function lookup/decompilation, frames, xrefs, type inspection, RTTI records, and separately queried address regular/address repeatable/function regular/function repeatable comment channels.
- Corroborating evidence: current by-memory/class/file/item/global docs, parent/sibling boundaries, generated CPP/H, manual coverage rows, current research tracker, and analogous accepted login headers.
- Negative evidence: no padding inside the target, no alternate type descriptor, no separate source consumer for the raw vtable bytes, no derived-field access beyond `+0x26c`, no derived-owned teardown, no independent by-vtable page, and no reason to move the class out of `login/ServerSelectPane`.
- Evidence strength is sufficient because storage role, all 39 values, all direct table stores, full RTTI hierarchy, exact virtual slot lineage, and source-owner context agree.

## Evidence Checked

- IDA MCP/manual checks: `idb_list`, schema-1 `runtime_attestation`, `inspect_items` for all 39 cells, `get_bytes`, `get_int`, `lookup_funcs`, `analyze_function`, `stack_frame`, `get_comments`, `type_inspect`, and inbound `xref_query`.
- Public endpoint schemas rechecked for the Gate 2B repair: `rename` explicitly supports stack-variable entries bound by function/current/new name, and `set_type` supports stack targets bound by function address, entity kind, required `name`, source type, and compatibility `variable`. The first variable-only attempt proved the required-name constraint; the accepted bound call proved physical canonicalization from source text `int` to `signed __int32`. These capabilities are recorded as semantic handoff only, not as a callable transaction object.
- Exact code evidence checked at `0x00573d20`, `0x00574310`, `0x00574340`, `0x00574440`, `0x00574750`, `0x0057475b`, `0x00574766`, and `0x00574780`.
- Exact data evidence checked at target boundaries, all three table heads, all three COLs, CHD/base array/base descriptors, predecessor `0x00624d20`, and successor `0x00624dc0`.
- Documentation checked: UID0003D7, UID0000D2, UID0000NO, UID0001HR, UID0000VG, UID0000S8, UID00026F, UID0003D5, UID0003D9, current DialogPane class/vtable docs, the dated report-time and ordinary-callback generated CPP/H snapshots, manual class/file/memory coverage, tracker, and matching executed reports. Current validator-owned generated authority remains a fresh supervisor reread at each gate.
- Negative checks: no target padding; no target-local strings; no extra vtable head; no source-visible RTTI/vptr statements; no safe complete current IDA UDT; no direct reason for a separate type page; no direct caller to ordinary cleanup; no direct authored teardown beyond inherited destruction/global clear.
- Failed or unavailable checks: none. MCP remained available and bounded live queries succeeded.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3D7-001 | 0003D7 | Exact target is `[0x00624d24,0x00624dc0)`, 156 bytes, 39 four-byte data items, SHA256 `A2B59C180BD9546543BB2BB7D77288A02CBAD759AC62EF8F31C96D4F590F2C73`. | 99 | live items/bytes | target Range/Inventory | incorporate | applied |
| C3D7-002 | 0003D7 | Six exact subranges and hashes separate three COL pointers from three table views without padding. | 99 | bytes/items/hashes | target Boundaries | incorporate | applied |
| C3D7-003 | 0003D7 | Primary COL `0x624d24 -> 0x650284` precedes 23 slots at `0x624d28..0x624d80`. | 99 | dwords/COL/items | target Primary view | incorporate | applied |
| C3D7-004 | 0003D7 | Secondary COL `0x624d84 -> 0x650338` precedes 11 EventHandler slots at `0x624d88..0x624db0`. | 99 | dwords/COL/items | target Secondary view | incorporate | applied |
| C3D7-005 | 0003D7 | Tertiary COL `0x624db4 -> 0x65034c` precedes two TimerHandler slots at `0x624db8/0x624dbc`. | 99 | dwords/COL/items | target Tertiary view | incorporate | applied |
| C3D7-006 | 0003D7 | Incorporate the complete 23-slot primary table with exact targets and source roles. | 99 | bytes/lookup/current DialogPane map | target Slot inventory | incorporate | applied |
| C3D7-007 | 0003D7 | Incorporate the complete 11-slot EventHandler table and inherited handler order. | 99 | bytes/lookup/RTTI PMD | target Slot inventory | incorporate | applied |
| C3D7-008 | 0003D7 | Incorporate the complete two-slot TimerHandler table. | 99 | bytes/lookup/RTTI PMD | target Slot inventory | incorporate | applied |
| C3D7-009 | 0003D7 | Preserve all three decorated table-head names, blank types/comments, and exact four-byte item boundaries. | 99 | inspect/comments | target IDA snapshot | incorporate | applied |
| C3D7-010 | 0003D7 | Each table head has constructor, ordinary-cleanup, and scalar-wrapper stores at the exact three-address triad. | 99 | inbound xrefs | target Xrefs | incorporate | applied |
| C3D7-011 | 0003D7 | Three COLs share type descriptor `0x6791a4` and CHD `0x650298`, with offsets `0`, `0xa0`, `0xa4`. | 99 | COL dwords | target RTTI | incorporate | applied |
| C3D7-012 | 0003D7 | CHD attributes `1` and eight BCDs prove ServerSelectPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, Singleton. | 99 | CHD/BCA/BCD | target RTTI | incorporate | applied |
| C3D7-013 | 0003D7 | EventHandler PMD is `+0xa0`, TimerHandler `+0xa4`, and direct Singleton PMD is `+0x26c`; DialogPane begins at zero. | 99 | BCD PMDs | target/class Layout | incorporate | applied |
| C3D7-014 | 0003D7 | Predecessor `0x624d20` is the final SimpleList table cell; successor `0x624dc0` is the ServerSelectMenuItemList COL. | 99 | items/dwords/names | target Boundaries | incorporate | applied |
| C3D7-015 | 0001HR | Constructor `0x573d20-0x574301` stores all three vptrs, stores the directory pointer at `+0x26c`, and has one MainMenu caller. | 99 | decompile/frame/xrefs | executable Evidence | incorporate | applied |
| C3D7-016 | 0001HR | `0x574310-0x574339` is ordinary derived cleanup: restore vptrs, clear singleton, run base destruction. | 99 | decompile/bytes | executable Evidence | incorporate | applied |
| C3D7-017 | 0000D2 | `0x574340` is the two-argument primary `+0x48` override `OnControlCommand(int,int)`, superseding `OnDialogAction(int)`. | 98 | vtable slot/retn 8/base declaration/body | class Methods | incorporate | applied |
| C3D7-018 | 0000D2 | `0x574440` is primary `+0x4c` `UpdateActionButton()`, superseding `UpdateScrollButtons()`. | 98 | vtable slot/base declaration/body | class Methods | incorporate | applied |
| C3D7-019 | 0001HR | `0x574750/75b/766/780` are singleton EH clear, two adjustors, and scalar deleting wrapper, not authored class methods. | 99 | bytes/xrefs/decompile | executable Compiler lowering | incorporate | applied |
| C3D7-020 | 0000D2 | Emit no explicit derived destructor and no raw vtable/RTTI/vptr statements; implicit virtual destruction recreates the observed family. | 97 | base virtual destruction/no derived resource teardown | class Source rationale | incorporate | applied |
| C3D7-021 | 0003D7 | Keep owner/emitter UID0000D2 and reconstructable true; set target position 20. | 98 | class/source/routing evidence | target Metadata | incorporate | applied |
| C3D7-022 | 0003D7 | Add the exact Section 22 compiler-generated ABI marker in CPP and keep H blank. | 99 | formal source policy | target Formal CPP/H | incorporate | applied |
| C3D7-023 | 0003D7 | Raise target `85/91 -> 94/98`; populate Item Summary and keep Nested 0. | 97 | complete evidence closure | target Metadata/Summary | incorporate | applied |
| C3D7-024 | 0000D2 | Incorporate exact inheritance, `0x270` layout, EBO overlap, directory member, corrected virtuals, and implicit-destructor decision. | 98 | RTTI/types/code | class Layout/Methods | incorporate | applied |
| C3D7-025 | 0000D2 | Apply exact Section 22 CPP include/children route and complete H declaration. | 97 | source/header analysis | class Formal CPP/H | incorporate | applied |
| C3D7-026 | 0000D2 | Raise class `90/93 -> 93/95`, set position 10, preserve owner/emitter UID0000NO. | 96 | declaration/layout/method closure | class Metadata | incorporate | applied |
| C3D7-027 | 0000NO | Incorporate complete class/vtable/header/source-order and corrected method naming while preserving unrelated list/helper evidence. | 96 | file/generated/support evidence | file Source emission policy | incorporate | applied |
| C3D7-028 | 0000NO | Raise file `89/91 -> 91/94`; preserve `NexusTK/login/`. | 95 | target/class/header closure | file Metadata | incorporate | applied |
| C3D7-029 | 0001HR | Raise broad executable evidence `89/92 -> 91/94` and correct the method/destructor/vtable-family map while keeping formal CPP/H blank. | 95 | full related-code recheck | `by-memory/0x00573d20-0x005747df.ServerSelectPane.md` Evidence/Metadata | incorporate | applied |
| C3D7-030 | 0000VG | Keep helper `86/91` and source route; synchronize its two callers to `OnControlCommand` without claiming new helper-body closure. | 96 | caller/body relationship | `by-item/ServerSelectHelpers_574510_5745b0.md` Caller evidence | incorporate | applied |
| C3D7-031 | 00026F | Keep mixed parent `85/91`, false/non-emitting; add complete UID0003D7 child disposition without changing parent ownership. | 99 | exact mixed island/child split | `by-memory/0x00624c60-0x00624f20.SimpleServerSelectReadOnlyData.md` Child inventory | incorporate | applied |
| C3D7-032 | 0000S8 | Preserve global `92/94`, position 0, formal forward/definition/extern, and sole external linkage. | 99 | current global lifecycle | global No-change support | already-present | already-present |
| C3D7-033 | 0003D7 | Do not create a duplicate by-vtable page; document why the exact by-memory child is the complete ABI owner. | 96 | current type-page search/routing | target/support policy | incorporate | applied |
| C3D7-034 | 0000NO | Record dated ordinary-callback generated CPP/H hashes and observed post-callback result: target/class markers resolved, no raw arrays or duplicate declaration; current authority is supervisor-reread dynamically. | 99 | physical generated readback | file Generated output | incorporate | applied |
| C3D7-035 | 0003D7 | Preserve stale primary extent and old method names only as historical rejected assumptions with reasons. | 99 | current evidence comparison | target/support History | incorporate | applied |
| C3D7-036 | 0003D7 | Insert the exact Section 28 target row under UID00026F in manual by-memory coverage. | 99 | current absent row | by-memory coverage | incorporate | proposed |
| C3D7-037 | 0000D2 | Replace the exact Section 28 class row with score 93 and declaration/vtable closure text. | 99 | current class row | by-class coverage | incorporate | proposed |
| C3D7-038 | 0000NO | Replace the exact Section 28 file row with score 91 and header/vtable closure text. | 99 | current file row | by-file coverage | incorporate | proposed |
| C3D7-039 | 0003D7 | Preserve the attested canonical read-only session identity and exact report-time IDA snapshot as evidence, not an operational package. | 99 | runtime attestation/live queries | report IDA provenance | already-present | already-present |
| C3D7-040 | 0000D2 | Protect current forward-like `ServerSelectPane` type state and do not create an unsafe complete IDA UDT. | 98 | type_inspect/layout evidence | IDA Gate2B no-change | incorporate | proposed |
| C3D7-041 | 0001HR | Apply dependency-ordered rename/type/comment stages for constructor `0x573d20` with the complete frame contract. | 97 | function/frame/caller/vptr stores | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-042 | 0001HR | Apply dependency-ordered rename/type/comment stages for ordinary cleanup `0x574310`. | 98 | function/frame/body | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-043 | 0001HR | Apply dependency-ordered function rename, exact semantic `int controlIndex` function type, explicit `Block -> controlIndex` stack rename, explicitly bound source-`int` stack type with physical `signed __int32` readback, and comment stages for `OnControlCommand` at `0x574340`, preserving both reproduced intermediate frames. | 98 | slot/base/body/reproduced endpoint/frame/required-name binding/canonical IDA spelling | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-044 | 0001HR | Apply dependency-ordered rename/type/comment stages for `UpdateActionButton` at `0x574440`. | 98 | slot/base/body/frame | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-045 | 0001HR | Rename/comment the singleton construction-failure clear helper at `0x574750`; preserve its `void()` type. | 96 | body/EH xref/global clear | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-046 | 0001HR | Rename/type the `+0xa0` scalar-destructor adjustor at `0x57475b`, preserve address regular comment `Block`, and add the adjustor summary only as a function regular comment. | 97 | bytes/jump/table slot and four-channel comment readback | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-047 | 0001HR | Rename/type the `+0xa4` scalar-destructor adjustor at `0x574766`, preserve address regular comment `Block`, and add the adjustor summary only as a function regular comment. | 97 | bytes/jump/table slot and four-channel comment readback | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-048 | 0001HR | Rename/type/comment the scalar deleting wrapper at `0x574780`. | 98 | body/frame/xrefs | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-049 | 0003D7 | Add exact regular comments to the three decorated table heads while preserving names, blank types, and item boundaries. | 99 | table/COL/PMD evidence | IDA Gate2B supervisor action | incorporate | proposed |
| C3D7-050 | 0003D7 | Supervisor validates every changed ordinary destination, applies three manual coverage rows, refreshes/rereads CPP/H, and proves the UID0003D7 empty marker is gone. | 99 | workflow/generated requirements | Validator Results | incorporate | proposed |
| C3D7-051 | 0003D7 | Preserve all valid research, negative evidence, rejected alternatives, the original report-first boundary as history, and supervisor-only lifecycle authority. | 99 | workflow/report evidence | report and changed docs | incorporate | applied |

## Positive Evidence Summary

- Every target byte is classified: three locator pointers and 36 function pointers, with no gap or padding.
- All three decorated heads share one type descriptor and one class hierarchy; COL offsets exactly match EventHandler and TimerHandler secondary bases.
- Constructor, ordinary cleanup, and scalar wrapper each write all three view heads at the same offsets.
- The primary table aligns exactly with the current 23-slot `DialogPane` contract. The two derived targets land at `+0x48` and `+0x4c`, proving the corrected override identities.
- Current `DialogPane` size `0x26c`, direct Singleton PMD `+0x26c`, constructor allocation `0x270`, and one pointer stored at `+0x26c` form a coherent source layout.
- Existing login headers establish the project convention for `#pragma once`, `DialogPane.h`, `Singleton.h`, forward declarations, period-compatible virtual syntax, and class declarations in H.
- The strongest chain is: exact RTTI hierarchy -> exact vptr stores -> exact inherited slot map -> derived method bodies -> class declaration. That chain is sufficient to regenerate the target without handwritten ABI data.

## IDA MCP Facts

- Report-time evidence session: `supervisor-uid0000KZ-gate2b-20260814`; canonical `NexusTK.exe.i64`; schema-1 attestation `ok:true`; no mutation was performed during that evidence pass. The later unsaved Gate 2B reproduction and verified canonical rollback are recorded separately below.
- Target SHA256: `A2B59C180BD9546543BB2BB7D77288A02CBAD759AC62EF8F31C96D4F590F2C73`.
- Subrange hashes:
  - `0x624d24-0x624d28`: `B652AFD6FB19C4725128DF53A51A8DF30C85C3EC4BAD69D40FA1CBB431F912D5`.
  - `0x624d28-0x624d84`: `147A634FA883C2F9EAB290D88E62F8CCFBD8CA896F95B1B7A5AACAA5492F9EA3`.
  - `0x624d84-0x624d88`: `82D5C71CDBD84FD23971AF579B962B19D37B1548264DF4B1CDED5735EB001812`.
  - `0x624d88-0x624db4`: `45844A5BA3AFB55904915F15E4DFCC4DD53E4EA4378BB0B8553A199F6603EEBF`.
  - `0x624db4-0x624db8`: `821AE1DB0FECCDD8A09DB67B0B79F44C69977EB494A282CB7ABB4C3FB67D22EA`.
  - `0x624db8-0x624dc0`: `BC84B8063DA6A054C35E5ACE8E8CB7C024CEF9173FBB700845441DAF4E7FFAFC`.
- COL records:
  - `0x650284`: `{signature 0, offset 0, cdOffset 0, typeDescriptor 0x6791a4, classHierarchy 0x650298}`.
  - `0x650338`: `{signature 0, offset 160, cdOffset 0, typeDescriptor 0x6791a4, classHierarchy 0x650298}`.
  - `0x65034c`: `{signature 0, offset 164, cdOffset 0, typeDescriptor 0x6791a4, classHierarchy 0x650298}`.
- CHD `0x650298`: signature `0`, attributes `1`, base count `8`, base array `0x6502a8`.
- BCD order and PMDs:

| BCD | Type descriptor | Bases | PMD mdisp/pdisp/vdisp | Attributes | Role |
| --- | --- | ---: | --- | ---: | --- |
| `0x6502cc` | `0x6791a4` ServerSelectPane | 7 | `0/-1/0` | `0x40` | self |
| `0x640790` | `0x673a70` DialogPane | 5 | `0/-1/0` | `0x40` | direct primary base |
| `0x640540` | `0x6739a0` Pane | 4 | `0/-1/0` | `0x40` | inherited |
| `0x640584` | `0x6739b4` GrafPort | 1 | `0/-1/0` | `0x40` | inherited |
| `0x640348` | `0x6738c0` LObject | 0 | `0/-1/0` | `0x40` | inherited |
| `0x6405bc` | `0x6739cc` EventHandler | 0 | `160/-1/0` | `0x40` | secondary view |
| `0x64060c` | `0x6739e8` TimerHandler | 0 | `164/-1/0` | `0x40` | tertiary view |
| `0x6502e8` | `0x6791c4` Singleton<ServerSelectPane> | 0 | `620/-1/0` | `0x40` | direct empty base |

- IDA type state: `ServerSelectPane` exists only as non-UDT declaration text with unknown-size sentinel; `Singleton<ServerSelectPane>` is absent; `DialogPane` is an exact `0x26c` UDT; `ServerSelectDirectory` is an exact `0x308` UDT with entries, count, version, and padding.
- Function hashes:
  - constructor `0x573d20-0x574301`: `129C5D7168EE71A3AED93F549AF94EF01CE521A5D132D88AE76D32C64612B4CF`.
  - ordinary cleanup `0x574310-0x574339`: `AB4FFFE6E1692CC63CFE836EFC789DF632F5C2E62D80823F223F115E97E8129F`.
  - control command `0x574340-0x574431`: `7745344EE283CB6F17F69C94E4F2A269436B8617A61C73B6CCE02A6AEFD38C64`.
  - action-button update `0x574440-0x574497`: `59ED1E2524A2E799CC53506F64C77EF9FE7D619C75EBB334F38C8C6F74AF459C`.
  - singleton clear `0x574750-0x57475b`: `638DC309EDD566266F6B3F5ACD90B32566AA56CE7B6AA0FB97F54A2781178D08`.
  - `+0xa0` adjustor `0x57475b-0x574766`: `9910A1B667C587D2BF626DA1F49B097F1E88C8097BB6D195EB1756A6A46F0E60`.
  - `+0xa4` adjustor `0x574766-0x574771`: `001BD22E06AE1148A95F25C61707EE5FECC18B3B51EC7FDD30B21BE1AD2B5E9A`.
  - scalar wrapper `0x574780-0x5747df`: `1DA30E62B9D93755286BFB47E813DF6B04D9FCAFA8808E2BA4970CF163CE1EA7`.
- Reproduced A3D7-09 endpoint behavior: after the already-verified rename, public function `set_type` accepted `void __thiscall ServerSelectPane__OnControlCommand(ServerSelectPane *this, int controlIndex, int notifyCode)`. `inspect_items` returned that exact function type. `stack_frame` returned `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `Block`/void pointer/+0x1c/4, and `notifyCode`/int/+0x20/4. No save occurred; the unsaved worker was discarded and canonical disk state was reopened and verified rolled back.
- Reproduced A3D7-09.2 endpoint behavior: after A3D7-09.1 renamed the physical row to `controlIndex` / `void *` / `+0x1c` / `4`, a variable-only stack-target type call returned `Stack variable name is required` without changing the frame. The accepted call supplied the stack target through required `name` plus compatibility `variable` and source text `int`; physical `stack_frame` returned `controlIndex` / `signed __int32` / `+0x1c` / `4`, while `notifyCode` remained `int` / `+0x20` / `4`. `signed __int32` is IDA's observed canonical physical spelling for this 32-bit signed row; the semantic function signature and reconstructed C++ parameter remain `int controlIndex`.
- Public metadata boundary: function-level `set_type` does not promise to overwrite a pre-named physical stack row, and stack-targeted source text does not promise identical physical spelling. The public `rename` stack scope and required-name-bound `set_type` stack scope are the supported explicit follow-on operations; each must be read back separately and abandoned on any range, type, frame, comment, or xref drift.
- Fresh bounded wrapper readback:
  - `0x57475b`: literal current prototype `boost::exception *__thiscall(char *this, char)`, one-row return-only frame, address regular comment `Block`, blank address repeatable/function regular/function repeatable channels, sole data xref `0x624d88`.
  - `0x574766`: literal current prototype `boost::exception *__thiscall(char *this, char)`, one-row return-only frame, address regular comment `Block`, blank address repeatable/function regular/function repeatable channels, sole data xref `0x624db8`.
  - `0x574780`: literal current prototype `boost::exception *__thiscall(boost::exception *Block, char)`, exact saved/return/`arg_0` frame, blank entry address regular/address repeatable/function regular/function repeatable channels, interior address regular comments `int` at `0x574783` and `block` at `0x5747ba`, and blank interior address repeatable channels, with inbound thunk/table xrefs unchanged.
- Full comment-channel audit result: constructor `0x573d20`, cleanup `0x574310`, `OnControlCommand` `0x574340`, `UpdateActionButton` `0x574440`, helper `0x574750`, and wrapper entry `0x574780` have blank address regular/address repeatable/function regular/function repeatable prestates and correctly use `set_function_comments` only for new function regular summaries. Wrapper interior `0x574783`/`0x5747ba`, all three vtable heads, locators, and COL fields are address-channel entities; their rows correctly preserve or set address comments through `set_address_comments`. The only prior channel mismatches were the two adjustor `Block` comments corrected in A3D7-16 through A3D7-21 and C3D7-046/C3D7-047.

## Function / Child Inventory

### Exact 39-cell target inventory

| Cell | Address | Value | Exact role |
| ---: | --- | --- | --- |
| 0 | `0x624d24` | `0x650284` | primary COL pointer |
| 1 | `0x624d28` | `0x574780` | primary slot `+0x00`, scalar deleting destructor |
| 2 | `0x624d2c` | `0x4f4b10` | `LObject::GetRuntimeClass` |
| 3 | `0x624d30` | `0x41b6c0` | `LObject::OnChangeMessage` |
| 4 | `0x624d34` | `0x4b8e20` | inherited `Pane::UpdateRenderRegion` |
| 5 | `0x624d38` | `0x41d680` | inherited `Pane::DrawOnTarget` |
| 6 | `0x624d3c` | `0x544730` | inherited `Pane::Show` |
| 7 | `0x624d40` | `0x544750` | inherited `Pane::Hide` |
| 8 | `0x624d44` | `0x5447a0` | `Pane::GetParentPane` |
| 9 | `0x624d48` | `0x544800` | `Pane::InvalidateRect` |
| 10 | `0x624d4c` | `0x544a20` | `Pane::GetDescription` |
| 11 | `0x624d50` | `0x544b80` | inherited `Pane::GetScreenBounds` |
| 12 | `0x624d54` | `0x544bd0` | inherited `Pane::SetBounds` |
| 13 | `0x624d58` | `0x49dfd0` | `DialogPane::OnCreate` |
| 14 | `0x624d5c` | `0x544cb0` | inherited `Pane::InsertInLayer` |
| 15 | `0x624d60` | `0x49e1c0` | `DialogPane::OnDestroy` |
| 16 | `0x624d64` | `0x49e190` | `DialogPane::OnShow` |
| 17 | `0x624d68` | `0x49e210` | `DialogPane::OnHide` |
| 18 | `0x624d6c` | `0x49f090` | `DialogPane::OnPaint` |
| 19 | `0x624d70` | `0x574340` | `ServerSelectPane::OnControlCommand(int,int)` |
| 20 | `0x624d74` | `0x574440` | `ServerSelectPane::UpdateActionButton()` |
| 21 | `0x624d78` | `0x49f1d0` | `DialogPane::DrawBackground` |
| 22 | `0x624d7c` | `0x49f2e0` | `DialogPane::DrawBorder` |
| 23 | `0x624d80` | `0x49fc00` | `DialogPane::SetHoverControl` |
| 24 | `0x624d84` | `0x650338` | EventHandler-view COL pointer |
| 25 | `0x624d88` | `0x57475b` | adjusted scalar deleting destructor, `this-0xa0` |
| 26 | `0x624d8c` | `0x49e240` | `DialogPane::HandlePointerOrMouseEvent` |
| 27 | `0x624d90` | `0x49e6e0` | `DialogPane::HandleKeyOrTextEvent` |
| 28 | `0x624d94` | `0x49ea60` | `DialogPane::HandleImeEvent` |
| 29 | `0x624d98` | `0x41d6b0` | inherited false packet-event default |
| 30 | `0x624d9c` | `0x544df0` | inherited system/control event handler |
| 31 | `0x624da0` | `0x544e00` | inherited type-19 event handler |
| 32 | `0x624da4` | `0x4a89f0` | inherited forward-handler order |
| 33 | `0x624da8` | `0x544e10` | inherited local event pair |
| 34 | `0x624dac` | `0x544e30` | inherited screen event pair |
| 35 | `0x624db0` | `0x544e70` | inherited event acceptance predicate |
| 36 | `0x624db4` | `0x65034c` | TimerHandler-view COL pointer |
| 37 | `0x624db8` | `0x574766` | adjusted scalar deleting destructor, `this-0xa4` |
| 38 | `0x624dbc` | `0x544e90` | inherited `Pane::OnTimer` |

### Related source/support inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x624d24-0x624dc0` | UID0003D7 target | exact three-view ABI child | true | UID0000D2 | `85/91 -> 94/98` | formal marker required |
| class declaration | UID0000D2 `by-class/ServerSelectPane.md` | human source that causes target ABI | true | UID0000NO | `90/93 -> 93/95` | formal CPP/H required |
| source module | UID0000NO `by-file/ServerSelectPane.md` | login compilation unit | file root | FILE | `89/91 -> 91/94` | source/header policy update |
| `0x573d20-0x5747df` mixed code | UID0001HR | constructor, dialog methods, list/helper/compiler family | true | UID0000NO | `89/92 -> 91/94` | evidence/name map update; formal stays blank |
| `0x574510-0x57465d` helper cluster | UID0000VG | selected-server helpers | true | UID0000NO | `86/91` | caller-name sync only |
| singleton global | UID0000S8 | sole external pointer definition/H extern | true | UID0000NO | `92/94` | unchanged |
| `0x624c60-0x624f20` mixed rdata | UID00026F | non-emitting parent/index | false | none | `85/91` | add complete child disposition |
| `0x624c60-0x624d24` predecessor | UID0003D5 | SimpleListPane ABI child | true | UID0000D8 | `94/98` | excluded, exact boundary |
| `0x624dc0-0x624e84` successor | UID0003D9 | ServerSelectMenuItemList ABI child | true | UID0000D1 | `86/91` | excluded, separate report need |
| by-vtable support | none | no independent exact ServerSelect page | n/a | n/a | n/a | duplicate page rejected |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x624d28` primary head | stores at `0x573d8f`, `0x574310`, `0x574786` | constructor, ordinary cleanup, scalar wrapper |
| `0x624d88` secondary head | stores at `0x573d98`, `0x574316`, `0x57478c` | same three lifecycle paths at `+0xa0` |
| `0x624db8` tertiary head | stores at `0x573da2`, `0x574320`, `0x574796` | same three lifecycle paths at `+0xa4` |
| `0x650284/0x650338/0x65034c` | one data xref each from preceding COL pointer | exact locator/table pairing |
| `0x573d20` constructor | caller `0x4f70db` in `MainMenuPane_HandlePacketEvent` | pre-login creation route |
| `0x574310` ordinary cleanup | no direct inbound code xref | compiler/EH cleanup route, not dead-data proof |
| `0x574340` control command | sole inbound data xref `0x624d70` | exact primary virtual |
| `0x574440` action update | sole inbound data xref `0x624d74` | exact primary virtual |
| `0x574750` singleton clear | code xref `0x607f81` within constructor EH metadata/cleanup region | construction-failure clear |
| `0x57475b` adjustor | sole table xref `0x624d88`; jumps `0x574780` after `this-0xa0` | compiler secondary destructor thunk |
| `0x574766` adjustor | sole table xref `0x624db8`; jumps `0x574780` after `this-0xa4` | compiler tertiary destructor thunk |
| `0x574780` scalar wrapper | table xref `0x624d28`; code xrefs from both adjustors | compiler deleting wrapper |
| `0x624d24/0x624d84/0x624db4` | no inbound xrefs to the pointer-cell addresses | expected for COL prefix cells; values point to RTTI records |

## Documentation Evidence And IDA Status

- Current ordinary docs establish login ownership, the direct Singleton base, `m_serverDirectory`, global linkage, resource behavior, selected-server packet helpers, broad aggregate boundaries, the exact 39-cell/three-COL RTTI inventory, corrected virtual identities, formal target/class routes, and current scores/positions.
- Historical pre-callback defects now repaired in ordinary docs were:
  - the stale target primary extent and missing complete table/RTTI inventories;
  - class/file/broad-memory `OnDialogAction` and `UpdateScrollButtons` names;
  - blank target/class formal blocks and positions;
  - generated UID0003D7 and UID0000D2 empty markers.
- The exact supervisor-owned manual coverage handoff is the three rows reproduced in Section 28.
- Current IDA function names remain `sub_*`; constructor and cleanup receiver types are base-shaped; control/update prototypes are decompiler-shaped; wrapper prototypes incorrectly mention `boost::exception`.
- At the dated ordinary-callback readback, validator command `000000023779` resolved the UID0003D7 and UID0000D2 target/class empty markers and showed only the separately identified independent empty emitters UID0000D1, UID0003D9, UID0000VG, and UID0001HR. This receipt is not permanent generated authority: generated files remain validator-owned, and the supervisor rereads their current command/hash/content dynamically at Gate 2A and final verification.

## Ranked Ownership Analysis

### 1. UID0000D2 ServerSelectPane

- Evidence for: decorated names, one type descriptor/CHD, constructor/destructor vptr stores, exact derived virtual slots, class RTTI, existing file route, and matching lifecycle code.
- Evidence against: none material. The bytes are compiler-generated, so ownership is semantic rather than handwritten-data authorship.
- Decision: canonical owner and sole emitter remain UID0000D2.

### 2. UID0000NO ServerSelectPane file

- Evidence for: compilation-unit route owns class, global, methods, list, helpers, resources, and generated destination.
- Evidence against: it is broader than the direct class owner.
- Decision: retain as source root through class ownership; do not route UID0003D7 directly to the file.

### 3. UID00026F mixed read-only aggregate

- Evidence for: physically contains the target.
- Evidence against: also contains reusable SimpleList data, list-class data, and strings from distinct semantic owners; intentionally false/non-emitting.
- Decision: parent/index only, never canonical owner or emitter.

### Proposed new file/grouping, if applicable

- No new source or by-vtable file is needed. `NexusTK/login/ServerSelectPane.cpp` and `.h` are the complete source route.
- Candidate duplicate `ServerSelectPaneVtables` page is rejected because UID0003D7 already provides the exact locator-inclusive inventory and compiler-source disposition.

## Source Placement

- Recommended source placement: declaration in generated `NexusTK/login/ServerSelectPane.h`; method definitions/children and the ABI marker in generated `NexusTK/login/ServerSelectPane.cpp`.
- UID0000S8 remains first at position 0 with forward declaration, definition, and H extern. UID0000D2 follows at position 10, includes its own header in CPP, and carries `[[CHILDREN]]`. UID0003D7 follows at position 20 with only the compiler-generated ABI marker.
- This order keeps the current global definition valid with an incomplete type, gives later method bodies the complete class declaration, and prevents vtable arrays from entering human source.
- Rejected placements: MainMenuPane (consumer), generic DialogPane (base), UID00026F (mixed physical index), standalone ABI source file, and ServerSelectMenuItemList (successor class).
- Remaining uncertainty: exact original header filename/access-label whitespace is stripped. The project-standard `ServerSelectPane.h` route and `public/protected/private` shape are the strongest consistent reconstruction.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is stable and requires no split.
- Internal layout:
  - primary COL `0x624d24-28`;
  - primary table `0x624d28-84`;
  - secondary COL `0x624d84-88`;
  - secondary table `0x624d88-db4`;
  - tertiary COL `0x624db4-db8`;
  - tertiary table `0x624db8-dc0`.
- No internal padding exists; every four-byte cell is an IDA data item and has a resolved semantic value.
- Predecessor `0x624d20` belongs to UID0003D5; successor `0x624dc0` begins UID0003D9.
- Keep target reconstructable because the project routes exact compiler ABI evidence through its source class and uses a formal no-raw-data marker. Reclassification to false/non-emitting is a weaker alternative under the current accepted UID0002N6/UID0003D5 routing precedent.
- Parent UID00026F remains false/non-emitting and `Nested:0`; child coverage is expressed by manual report indentation rather than changing the parent into an emitter.

## Negative Evidence Summary

- No target cell is padding, an untyped blob, a string, or a separately owned literal.
- No COL names a class other than `ServerSelectPane`; three-view splitting into distinct classes is contradicted.
- No persistent derived field beyond `m_serverDirectory` is accessed or required by allocation/layout.
- No class-specific authored destructor body performs derived resource cleanup. The observable bodies restore vptrs, clear singleton storage, invoke base destruction, adjust `this`, or conditionally free memory.
- No evidence supports manual singleton registration, raw RTTI structures, raw vtable arrays, explicit this-adjustment, `boost::exception` involvement, or decompiler-generated types in final source.
- Physical adjacency to SimpleList and ServerSelectMenuItemList does not transfer class ownership.
- The absence of direct xrefs to the ordinary cleanup body does not make it non-code; constructor EH/lifecycle and scalar-wrapper structure explain it.
- Existing `OnDialogAction`/`UpdateScrollButtons` wording is contradicted by current base-slot identities. It remains useful only as historical naming provenance.
- The reproduced A3D7-09 result is negative evidence against assuming that a function signature application alone rewrites every pre-named physical argument row. `Block` / `void *` is therefore a required intermediate state, not evidence against the exact source-facing `controlIndex` parameter.
- The reproduced A3D7-09.2 result is negative evidence against requiring source type text and IDA's physical frame rendering to use the same spelling. Source `int controlIndex` and physical `controlIndex` / `signed __int32` are semantically consistent; a literal physical `int` expectation is disproven.
- The reproduced adjustor preflight is negative evidence against treating a generic `regular` result as a function comment. At `0x57475b` and `0x574766`, `Block` belongs to the address regular channel; `set_function_comments` cannot replace it and must instead create a separate function regular summary while preserving the address channel.

## IDA Rename / Type / Comment Recommendations

These are semantic, supervisor-owned Gate 2B recommendations. They are not an executable transaction package. Each stage is dependency ordered and must be attempted only after a fresh canonical read proves the complete literal prestate shown here. Any name, type, range, frame, byte, xref, or comment drift requires a stop and report rebase. Preserve the three existing COL regular comments `signature`; do not create a complete `ServerSelectPane` UDT, alter data items, redefine functions, change bytes, or rename decorated vtable heads.
The classification column uses only the allowed values `apply` and `no change recommended`, exactly one per row. Endpoint names are semantic public-MCP bindings, not callable request objects.
Fresh destination-collision evidence was collected read-only from attested canonical session `supervisor-uid0000KZ-gate2b-20260814` at `2026-08-15T02:47:59Z`. Public `lookup_funcs` returned a literal absent/free result for each of the eight exact destination names; every rename row below binds its own result, recheck rule, collision hard stop, and expected post-rename lookup.
Comment-channel audit rule: each function-row contract below either names all four entry channels independently as address regular, address repeatable, function regular, and function repeatable, or binds unchanged comment state to the immediately preceding stage that lists those four channels; any `entry` wording denotes address-channel state. Interior instruction comments and vtable/COL comments are address-channel state. Function summaries use only `set_function_comments`; vtable-head summaries use only `set_address_comments`. The two adjustor rows preserve address regular `Block` while adding a distinct function regular summary.

| Action ID | Entity / range | Literal current or intermediate prestate | Public endpoint / semantic action | Evidence and safety constraints | Complete expected poststate | Classification |
| --- | --- | --- | --- | --- | --- | --- |
| A3D7-01 | named type `ServerSelectPane` | type exists as non-UDT, unknown-size declaration with zero members; `Singleton<ServerSelectPane>` is absent | No public mutation endpoint; preserve the current named-type state | RTTI proves inheritance and layout, but IDA lacks safe complete base/member definitions for this derived type | named-type state remains exactly the same; no UDT or template type is created | no change recommended |
| A3D7-02 | `0x00573d20-0x00574301` constructor | name `sub_573D20`; type `DialogPane *__thiscall(DialogPane *this, const unsigned __int16 **)`; frame `var_38`/DialogPane pointer/+0x10/4, `var_34`/DWORD/+0x14/4, `var_30`/DWORD/+0x18/4, `item`/DWORD/+0x1c/4, `scrollablePane`/ScrollablePane pointer/+0x20/4, `Block`/void pointer/+0x24/4, `bounds`/RectBounds/+0x28/0x10, `var_10`/DWORD/+0x38/4, `var_C`/DWORD/+0x3c/4, `var_4`/DWORD/+0x44/4, `__saved_registers`/DWORD/+0x48/4, `__return_address`/unknown pointer/+0x4c/4, `arg_0`/DWORD/+0x50/4, `arg_4`/DWORD/+0x54/4; function and entry regular/repeatable comments blank | `rename` with `pure:true`; rename to `ServerSelectPane__Constructor` | exact range, SHA256 `129C5D7168EE71A3AED93F549AF94EF01CE521A5D132D88AE76D32C64612B4CF`, three vptr stores, member store at `+0x26c`, one caller `0x4f70db`; rename must not alter range/type/frame/comments Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__Constructor` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | name `ServerSelectPane__Constructor`; all other listed prestate fields remain literal Post-rename public `lookup_funcs` readback for `ServerSelectPane__Constructor` must resolve exactly to address `0x00573d20`, name `ServerSelectPane__Constructor`, size `0x5e1`, with no error. | apply |
| A3D7-03 | `0x00573d20` after A3D7-02 | name `ServerSelectPane__Constructor`; old DialogPane-shaped type; complete frame and blank comments exactly as A3D7-02 | `set_type`; set semantic type `ServerSelectPane *__thiscall ServerSelectPane__Constructor(ServerSelectPane *this, ServerSelectDirectory *serverDirectory)` | source declaration, allocation/layout, member store, caller and RTTI agree; stop if parser changes any local, removes `arg_4`, or does not produce the named `serverDirectory` argument | exact new type; frame rows through `__return_address` remain byte-for-byte as listed in A3D7-02, `arg_0` becomes `serverDirectory`/ServerSelectDirectory pointer/+0x50/4, `arg_4` remains DWORD/+0x54/4; comments remain blank | apply |
| A3D7-04 | `0x00573d20` after A3D7-03 | renamed constructor, exact semantic type and exact expected frame from A3D7-03; address regular, address repeatable, function regular, and function repeatable channels blank | `set_function_comments`; function regular channel; set function regular comment `Construct ServerSelectPane, initialize DialogPane and list controls, install primary/EventHandler/TimerHandler vptrs, and retain the ServerSelectDirectory pointer.` | comment states observed behavior without claiming raw ABI source; no address-comment endpoint is used | name/type/frame stay exact; function regular comment equals the literal text; function repeatable, address regular, and address repeatable channels remain blank | apply |
| A3D7-05 | `0x00574310-0x00574339` ordinary cleanup | name `sub_574310`; type `void __thiscall(DialogPane *this)`; frame only `__return_address`/unknown pointer/+0x0/4; all function/entry comment channels blank; no direct inbound xref | `rename` with `pure:true`; rename to `ServerSelectPane__Destructor` | exact range, SHA256 `AB4FFFE6E1692CC63CFE836EFC789DF632F5C2E62D80823F223F115E97E8129F`, three vptr restores, singleton clear and base teardown; no function-boundary change Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__Destructor` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | new name; old type, one-row frame, blank comments and xref state remain exact Post-rename public `lookup_funcs` readback for `ServerSelectPane__Destructor` must resolve exactly to address `0x00574310`, name `ServerSelectPane__Destructor`, size `0x29`, with no error. | apply |
| A3D7-06 | `0x00574310` after A3D7-05 | new name; old DialogPane receiver type; one-row frame; blank comments | `set_type`; set semantic type `void __thiscall ServerSelectPane__Destructor(ServerSelectPane *this)` | receiver correction only; stop if range or one-row frame changes | exact new type; frame remains only `__return_address`/unknown pointer/+0x0/4; comments remain blank | apply |
| A3D7-07 | `0x00574310` after A3D7-06 | exact renamed/typed function; one-row frame; address regular, address repeatable, function regular, and function repeatable channels blank | `set_function_comments`; function regular channel; set function regular comment `Restore ServerSelectPane vptrs, clear the singleton instance, and run base-class destruction.` | describes compiler-visible ordinary derived cleanup without forcing an explicit source destructor; no address-comment endpoint is used | name/type/frame remain exact; function regular comment equals literal text; function repeatable, address regular, and address repeatable channels remain blank | apply |
| A3D7-08 | `0x00574340-0x00574431` primary slot `+0x48` | name `sub_574340`; type `void __userpurge(int *@<ecx>, int@<ebx>, int@<edi>, char *Block, int)`; frame `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `Block`/void pointer/+0x1c/4, `arg_4`/int/+0x20/4; comments blank; sole inbound xref `0x624d70` | `rename` with `pure:true`; rename to `ServerSelectPane__OnControlCommand` | exact SHA256 `7745344EE283CB6F17F69C94E4F2A269436B8617A61C73B6CCE02A6AEFD38C64`, `retn 8`, DialogPane slot identity and body dispatch; no range/frame/type change during rename Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__OnControlCommand` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | new name; all other listed prestate remains exact Post-rename public `lookup_funcs` readback for `ServerSelectPane__OnControlCommand` must resolve exactly to address `0x00574340`, name `ServerSelectPane__OnControlCommand`, size `0xf1`, with no error. | apply |
| A3D7-09 | `0x00574340` after A3D7-08 | exact function range `[0x00574340,0x00574431)`, SHA256 `7745344EE283CB6F17F69C94E4F2A269436B8617A61C73B6CCE02A6AEFD38C64`, name `ServerSelectPane__OnControlCommand`; type `void __userpurge(int *@<ecx>, int@<ebx>, int@<edi>, char *Block, int)`; frame exactly `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `Block`/void pointer/+0x1c/4, `arg_4`/int/+0x20/4; function and entry regular/repeatable comments blank; sole inbound xref `0x624d70` | `set_type`; set semantic function type `void __thiscall ServerSelectPane__OnControlCommand(ServerSelectPane *this, int controlIndex, int notifyCode)` | Base-slot contract, body dispatch and `retn 8` prove two semantic arguments. Reproduced public endpoint behavior accepted the exact function type while retaining the pre-named first physical argument row. Hard-stop unless the resulting type is exact, `arg_4` alone becomes `notifyCode`/int, and every other row/name/type/offset/size plus range/hash/comments/xref remains literal; do not require or accept implicit `Block` normalization in this stage. | exact range/hash and name remain protected; exact semantic function type; frame exactly `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `Block`/void pointer/+0x1c/4, `notifyCode`/int/+0x20/4; function and entry regular/repeatable comments blank; sole inbound xref `0x624d70` | apply |
| A3D7-09.1 | stack row `Block` in function `0x00574340`, after A3D7-09 | exact function range `[0x00574340,0x00574431)`, SHA256 `7745344EE283CB6F17F69C94E4F2A269436B8617A61C73B6CCE02A6AEFD38C64`, name `ServerSelectPane__OnControlCommand`; exact semantic function type; frame exactly `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `Block`/void pointer/+0x1c/4, `notifyCode`/int/+0x20/4; no `controlIndex` frame row exists; all function and entry regular/repeatable comments blank; sole inbound xref `0x624d70` | Public `rename` endpoint, stack-variable scope bound to function `0x00574340`; rename the exact current stack row `Block` to `controlIndex`, with overwrite forbidden | Current public schema supports an explicit stack rename keyed by function/current/new name. Hard-stop before mutation unless `Block` is the unique `+0x1c`/4 row, `controlIndex` is absent from the frame, and the complete prestate matches. Hard-stop after mutation unless only that row name changes; no type, offset, size, range, hash, function type, comment, xref, or other frame row may change. | exact range/hash, name and semantic function type remain protected; frame exactly `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `controlIndex`/void pointer/+0x1c/4, `notifyCode`/int/+0x20/4; all function and entry regular/repeatable comments blank; sole inbound xref `0x624d70` | apply |
| A3D7-09.2 | stack row `controlIndex` in function `0x00574340`, after A3D7-09.1 | exact function range `[0x00574340,0x00574431)`, SHA256 `7745344EE283CB6F17F69C94E4F2A269436B8617A61C73B6CCE02A6AEFD38C64`, name `ServerSelectPane__OnControlCommand`; exact semantic function type `void __thiscall ServerSelectPane__OnControlCommand(ServerSelectPane *this, int controlIndex, int notifyCode)`; frame exactly `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `controlIndex`/void pointer/+0x1c/4, `notifyCode`/int/+0x20/4; all function and entry regular/repeatable comments blank; sole inbound xref `0x624d70` | Public `set_type` endpoint, stack target bound to function `0x00574340` through required `name` `controlIndex`, with compatibility `variable` also `controlIndex`; apply source type text `int` only to that row | The first variable-only call returned `Stack variable name is required` and left the frame unchanged; therefore the required `name` binding is part of this contract. The accepted bound call proved that source text `int` canonicalizes in physical `stack_frame` as `signed __int32`. The semantic source parameter, 32-bit slot, base virtual contract, body dispatch and `retn 8` justify the signed 32-bit type. Hard-stop before mutation unless the exact intermediate prestate matches. Hard-stop after mutation unless only the `+0x1c` row type changes from `void *` to physical `signed __int32`; preserve its name/offset/size and every other range/hash/type/frame/comment/xref field literally. | exact range/hash, name and semantic function type remain protected; frame exactly `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `controlIndex`/`signed __int32`/+0x1c/4, `notifyCode`/int/+0x20/4; all function and entry regular/repeatable comments blank; sole inbound xref `0x624d70`; semantic C++ remains `int controlIndex` | apply |
| A3D7-10 | `0x00574340` after A3D7-09.2 | exact function range `[0x00574340,0x00574431)`, SHA256 `7745344EE283CB6F17F69C94E4F2A269436B8617A61C73B6CCE02A6AEFD38C64`, name `ServerSelectPane__OnControlCommand`; exact semantic function type `void __thiscall ServerSelectPane__OnControlCommand(ServerSelectPane *this, int controlIndex, int notifyCode)`; frame exactly `var_C`/DWORD/+0x8/4, `var_4`/DWORD/+0x10/4, `__saved_registers`/DWORD/+0x14/4, `__return_address`/unknown pointer/+0x18/4, `controlIndex`/`signed __int32`/+0x1c/4, `notifyCode`/int/+0x20/4; all function and entry regular/repeatable comments blank; sole inbound xref `0x624d70` | `set_function_comments`; regular function-comment channel; set regular function comment `Handle ServerSelectPane control notifications, update selection state, and refresh the action button.` | source-facing summary follows observed calls and slot identity; hard-stop unless the complete A3D7-09.2 state is present, including physical `signed __int32` while the semantic signature retains `int controlIndex` | exact range/hash, name, semantic type, complete six-row frame and xref remain protected; physical `controlIndex` stays `signed __int32` at +0x1c/4 and `notifyCode` stays int at +0x20/4; regular function comment equals the literal text; function repeatable and entry regular/repeatable comments remain blank | apply |
| A3D7-11 | `0x00574440-0x00574497` primary slot `+0x4c` | name `sub_574440`; type `int __thiscall(_DWORD **this)`; frame only `__return_address`/unknown pointer/+0xc/4; address regular, address repeatable, function regular, and function repeatable channels blank; sole inbound xref `0x624d74` | `rename` with `pure:true`; rename to `ServerSelectPane__UpdateActionButton` | exact SHA256 `59ED1E2524A2E799CC53506F64C77EF9FE7D619C75EBB334F38C8C6F74AF459C`, body and DialogPane virtual order; no range/type/frame/comment change during rename Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__UpdateActionButton` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | new name; old type, frame, four blank comment channels and xref remain exact Post-rename public `lookup_funcs` readback for `ServerSelectPane__UpdateActionButton` must resolve exactly to address `0x00574440`, name `ServerSelectPane__UpdateActionButton`, size `0x57`, with no error. | apply |
| A3D7-12 | `0x00574440` after A3D7-11 | renamed function; old `_DWORD **` receiver and int return; one-row frame at +0xc; all four entry comment channels blank | `set_type`; set semantic type `void __thiscall ServerSelectPane__UpdateActionButton(ServerSelectPane *this)` | no meaningful return value is consumed and source role is state refresh; stop unless parser preserves the literal one-row frame and all comment channels | exact new type; frame remains only `__return_address`/unknown pointer/+0xc/4; address regular, address repeatable, function regular, and function repeatable channels remain blank | apply |
| A3D7-13 | `0x00574440` after A3D7-12 | exact renamed/typed function and one-row frame; address regular, address repeatable, function regular, and function repeatable channels blank | `set_function_comments`; function regular channel; set function regular comment `Enable or disable the server-selection action control from the current directory and selection state.` | body-derived purpose; no unsupported widget member names; no address-comment endpoint is used | name/type/frame stay exact; function regular comment equals literal text; function repeatable, address regular, and address repeatable channels remain blank | apply |
| A3D7-14 | `0x00574750-0x0057475b` singleton clear helper | name `sub_574750`; type `void()`; frame only `__return_address`/unknown pointer/+0x0/4; bytes `c7 05 ac b4 69 00 00 00 00 00 c3`; address regular, address repeatable, function regular, and function repeatable channels blank; code xref `0x607f81` | `rename` with `pure:true`; rename to `ServerSelectPane__ClearSingletonOnConstructionFailure` | exact SHA256 `638DC309EDD566266F6B3F5ACD90B32566AA56CE7B6AA0FB97F54A2781178D08`; preserve `void()` type, exact function boundary, and all comment channels Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__ClearSingletonOnConstructionFailure` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | new name; type/frame/bytes/xref and all four blank comment channels remain exact Post-rename public `lookup_funcs` readback for `ServerSelectPane__ClearSingletonOnConstructionFailure` must resolve exactly to address `0x00574750`, name `ServerSelectPane__ClearSingletonOnConstructionFailure`, size `0xb`, with no error. | apply |
| A3D7-15 | `0x00574750` after A3D7-14 | renamed helper, `void()` type, one-row frame; address regular, address repeatable, function regular, and function repeatable channels blank | `set_function_comments`; function regular channel; set function regular comment `Clear g_pServerSelectPane during constructor exception cleanup.` | literal global store and EH-region xref; do not model as authored class method; no address-comment endpoint is used | name/type/frame remain exact; function regular comment equals literal text; function repeatable, address regular, and address repeatable channels remain blank | apply |
| A3D7-16 | `0x0057475b-0x00574766` EventHandler adjustor | name `sub_57475B`; type `boost::exception *__thiscall(char *this, char)`; frame only `__return_address`/unknown pointer/+0x0/4; address regular comment `Block`; address repeatable, function regular, and function repeatable channels blank; bytes `81 e9 a0 00 00 00 e9 1a 00 00 00`; sole inbound xref `0x624d88` | `rename` with `pure:true`; rename to `ServerSelectPane__ScalarDeletingDestructor_EventHandlerAdjustor` | exact SHA256 `9910A1B667C587D2BF626DA1F49B097F1E88C8097BB6D195EB1756A6A46F0E60`, subtracts `0xa0` and jumps to `0x574780`; do not change bytes/range/comments Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__ScalarDeletingDestructor_EventHandlerAdjustor` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | new name; literal old type/frame, address regular `Block`, three blank comment channels, and xref remain exact Post-rename public `lookup_funcs` readback for `ServerSelectPane__ScalarDeletingDestructor_EventHandlerAdjustor` must resolve exactly to address `0x0057475b`, name `ServerSelectPane__ScalarDeletingDestructor_EventHandlerAdjustor`, size `0xb`, with no error. | apply |
| A3D7-17 | `0x0057475b` after A3D7-16 | new name; type `boost::exception *__thiscall(char *this, char)`; one-row frame; address regular comment `Block`; address repeatable, function regular, and function repeatable channels blank | `set_type`; set semantic type `void *__thiscall ServerSelectPane__ScalarDeletingDestructor_EventHandlerAdjustor(void *eventHandlerView, unsigned int flags)` | PMD and bytes prove adjusted receiver; stop unless frame becomes exactly return plus flags and every comment channel remains literal | exact type; frame exactly `__return_address`/unknown pointer/+0x0/4 and `flags`/unsigned int/+0x4/4; address regular comment remains `Block`; address repeatable, function regular, and function repeatable channels remain blank | apply |
| A3D7-18 | `0x0057475b` after A3D7-17 | exact name/type/two-row frame; address regular comment `Block`; address repeatable, function regular, and function repeatable channels blank | `set_function_comments`; function regular channel; add function regular comment `Adjust the EventHandler view by -0xa0 and tail-call the ServerSelectPane scalar deleting destructor.` | exact instruction bytes and table slot; the function-comment endpoint adds a separate semantic summary and must not replace or mutate address regular `Block` | name/type/frame remain exact; address regular comment remains `Block`; function regular comment equals the literal summary; address repeatable and function repeatable channels remain blank | apply |
| A3D7-19 | `0x00574766-0x00574771` TimerHandler adjustor | name `sub_574766`; type `boost::exception *__thiscall(char *this, char)`; frame only `__return_address`/unknown pointer/+0x0/4; address regular comment `Block`; address repeatable, function regular, and function repeatable channels blank; subtracts `0xa4`; sole inbound xref `0x624db8` | `rename` with `pure:true`; rename to `ServerSelectPane__ScalarDeletingDestructor_TimerHandlerAdjustor` | exact SHA256 `001BD22E06AE1148A95F25C61707EE5FECC18B3B51EC7FDD30B21BE1AD2B5E9A`; do not change bytes/range/comments Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__ScalarDeletingDestructor_TimerHandlerAdjustor` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | new name; literal old type/frame, address regular `Block`, three blank comment channels, and xref remain exact Post-rename public `lookup_funcs` readback for `ServerSelectPane__ScalarDeletingDestructor_TimerHandlerAdjustor` must resolve exactly to address `0x00574766`, name `ServerSelectPane__ScalarDeletingDestructor_TimerHandlerAdjustor`, size `0xb`, with no error. | apply |
| A3D7-20 | `0x00574766` after A3D7-19 | new name; type `boost::exception *__thiscall(char *this, char)`; one-row frame; address regular comment `Block`; address repeatable, function regular, and function repeatable channels blank | `set_type`; set semantic type `void *__thiscall ServerSelectPane__ScalarDeletingDestructor_TimerHandlerAdjustor(void *timerHandlerView, unsigned int flags)` | PMD and bytes prove adjusted receiver; stop unless frame becomes exactly two rows and every comment channel remains literal | exact type; frame exactly `__return_address`/unknown pointer/+0x0/4 and `flags`/unsigned int/+0x4/4; address regular comment remains `Block`; address repeatable, function regular, and function repeatable channels remain blank | apply |
| A3D7-21 | `0x00574766` after A3D7-20 | exact name/type/two-row frame; address regular comment `Block`; address repeatable, function regular, and function repeatable channels blank | `set_function_comments`; function regular channel; add function regular comment `Adjust the TimerHandler view by -0xa4 and tail-call the ServerSelectPane scalar deleting destructor.` | exact bytes and table slot; the function-comment endpoint adds a separate semantic summary and must not replace or mutate address regular `Block` | name/type/frame remain exact; address regular comment remains `Block`; function regular comment equals the literal summary; address repeatable and function repeatable channels remain blank | apply |
| A3D7-22 | `0x00574780-0x005747df` scalar deleting wrapper | name `sub_574780`; type `boost::exception *__thiscall(boost::exception *Block, char)`; frame `__saved_registers`/DWORD/+0x4/4, `__return_address`/unknown pointer/+0x8/4, `arg_0`/int/+0xc/4; entry address regular, address repeatable, function regular, and function repeatable channels blank; interior address regular comments `int` at `0x574783` and `block` at `0x5747ba`; interior address repeatable channels blank; inbound xrefs from `0x574761`, `0x57476c`, and table cell `0x624d28` | `rename` with `pure:true`; rename to `ServerSelectPane__ScalarDeletingDestructor` | exact SHA256 `1DA30E62B9D93755286BFB47E813DF6B04D9FCAFA8808E2BA4970CF163CE1EA7`; wrapper invokes cleanup and conditionally frees; preserve every entry and interior comment channel Fresh read-only public `lookup_funcs` destination query `ServerSelectPane__ScalarDeletingDestructor` returned literal `fn:null`, `error:Not found`; the destination is absent/free. Immediately before rename, repeat that exact destination lookup. If it resolves to the same source address, stop and rebase this row as `already present`; if it resolves to any different entity or address, hard stop and do not rename. | new name; literal old type/frame, four blank entry channels, both interior address regular comments, both blank interior address repeatable channels, and xrefs remain exact Post-rename public `lookup_funcs` readback for `ServerSelectPane__ScalarDeletingDestructor` must resolve exactly to address `0x00574780`, name `ServerSelectPane__ScalarDeletingDestructor`, size `0x5f`, with no error. | apply |
| A3D7-23 | `0x00574780` after A3D7-22 | new name; type `boost::exception *__thiscall(boost::exception *Block, char)`; exact three-row frame; four blank entry comment channels; interior address regular comments `int` and `block`; interior address repeatable channels blank | `set_type`; set semantic type `ServerSelectPane *__thiscall ServerSelectPane__ScalarDeletingDestructor(ServerSelectPane *this, unsigned int flags)` | deleting-wrapper body and all three table/thunk routes agree; stop if saved/return offsets or any comment channel changes | exact type; saved and return rows remain exact; `arg_0` becomes `flags`/unsigned int/+0xc/4; all four entry channels remain blank; both interior address regular comments and blank address repeatable channels are preserved | apply |
| A3D7-24 | `0x00574780` after A3D7-23 | exact name/type/frame; address regular, address repeatable, function regular, and function repeatable entry channels blank; interior address regular comments `int` and `block`; interior address repeatable channels blank | `set_function_comments`; function regular channel; set function regular comment `Run ServerSelectPane destruction and free the complete object when the deleting-destructor flags request it.` | exact body; identifies compiler wrapper rather than source destructor; preserve all address-comment state and do not use an address-comment endpoint | name/type/frame remain exact; function regular comment equals literal text; entry address regular/address repeatable/function repeatable channels remain blank; both interior address regular comments and blank address repeatable channels are preserved | apply |
| A3D7-25 | primary vtable head `[0x00624d28,0x00624d2c)` plus locator `[0x00624d24,0x00624d28)` and COL `[0x00650284,0x00650298)` | Locator item: data, name absent, type absent, regular comment absent, repeatable comment absent, bytes `84 02 65 00`, SHA256 `B652AFD6FB19C4725128DF53A51A8DF30C85C3EC4BAD69D40FA1CBB431F912D5`, dword pointer `0x00650284`, zero inbound xrefs. Head item: data, name `??_7ServerSelectPane@@6B@`, type absent, regular comment absent, repeatable comment absent, bytes `80 47 57 00`, SHA256 `4874D5AF37AC268420392CE50D6FC67CBF30EB1759BB6ED299080D0A01371891`, dword target `0x00574780`, inbound data xrefs exactly `0x00573d8f`, `0x00574310`, `0x00574786`. COL has five four-byte data items and full bytes `00 00 00 00 00 00 00 00 00 00 00 00 a4 91 67 00 98 02 65 00`, SHA256 `74DC01B6ECF0E42726586825E86D71D991695AFB41C43383BA90EBAA20FE7EAB`: `[0x650284,0x650288)` name `??_R4ServerSelectPane@@6B@`, type absent, value `0`, regular `signature`, repeatable absent, sole xref `0x624d24`; `[0x650288,0x65028c)` name/type absent, value `0`, regular `offset of this vtable in complete class (from top)`, repeatable absent, zero xrefs; `[0x65028c,0x650290)` name/type absent, value `0`, regular `offset of constructor displacement`, repeatable absent, zero xrefs; `[0x650290,0x650294)` name/type absent, value `0x006791a4`, regular `reference to type description`, repeatable absent, zero xrefs; `[0x650294,0x650298)` name/type absent, value `0x00650298`, regular `reference to hierarchy description`, repeatable absent, zero xrefs | `set_address_comments`; regular channel text `ServerSelectPane primary DialogPane vtable; COL at 0x00624d24, 23 slots, complete-object offset 0.` | Before mutation, hard-stop if any listed boundary, classification, name, type, comment channel, bytes, hash, value, or xref differs. Apply only the head regular comment. After readback, hard-stop and do not persist if the head repeatable channel changes or any locator/COL/head protected state changes | Locator remains data `[0x624d24,0x624d28)`, unnamed/untyped, both comments absent, bytes/hash/value/xrefs exactly as prestate. Head remains data `[0x624d28,0x624d2c)`, same decorated name, absent type, same bytes/hash/value/three xrefs, repeatable absent, with regular comment exactly `ServerSelectPane primary DialogPane vtable; COL at 0x00624d24, 23 slots, complete-object offset 0.`. All five COL items remain at their literal boundaries with the same names/types/values/regular texts/repeatable absence/xrefs, full bytes and hash listed in prestate | apply |
| A3D7-26 | secondary vtable head `[0x00624d88,0x00624d8c)` plus locator `[0x00624d84,0x00624d88)` and COL `[0x00650338,0x0065034c)` | Locator item: data, name absent, type absent, regular comment absent, repeatable comment absent, bytes `38 03 65 00`, SHA256 `82D5C71CDBD84FD23971AF579B962B19D37B1548264DF4B1CDED5735EB001812`, dword pointer `0x00650338`, zero inbound xrefs. Head item: data, name `??_7ServerSelectPane@@6B@_0`, type absent, regular comment absent, repeatable comment absent, bytes `5b 47 57 00`, SHA256 `5039E66C63CA02759700D9C61AE8CBA5E2FED29AB9EB7ADC58151AB67BB82D7F`, dword target `0x0057475b`, inbound data xrefs exactly `0x00573d98`, `0x00574316`, `0x0057478c`. COL has five four-byte data items and full bytes `00 00 00 00 a0 00 00 00 00 00 00 00 a4 91 67 00 98 02 65 00`, SHA256 `A44104FD942E6E7404F28C6ECDA2CF1E8DB8A1E749CE4908948767F7B8501DFD`: `[0x650338,0x65033c)` name `??_R4ServerSelectPane@@6B@_0`, type absent, value `0`, regular `signature`, repeatable absent, sole xref `0x624d84`; `[0x65033c,0x650340)` name/type absent, value `0xa0`, regular `offset of this vtable in complete class (from top)`, repeatable absent, zero xrefs; `[0x650340,0x650344)` name/type absent, value `0`, regular `offset of constructor displacement`, repeatable absent, zero xrefs; `[0x650344,0x650348)` name/type absent, value `0x006791a4`, regular `reference to type description`, repeatable absent, zero xrefs; `[0x650348,0x65034c)` name/type absent, value `0x00650298`, regular `reference to hierarchy description`, repeatable absent, zero xrefs | `set_address_comments`; regular channel text `ServerSelectPane EventHandler secondary vtable; COL at 0x00624d84, 11 slots, complete-object offset 0xa0.` | Before mutation, hard-stop if any listed boundary, classification, name, type, comment channel, bytes, hash, value, or xref differs. Apply only the head regular comment. After readback, hard-stop and do not persist if the head repeatable channel changes or any locator/COL/head protected state changes | Locator remains data `[0x624d84,0x624d88)`, unnamed/untyped, both comments absent, bytes/hash/value/xrefs exactly as prestate. Head remains data `[0x624d88,0x624d8c)`, same decorated name, absent type, same bytes/hash/value/three xrefs, repeatable absent, with regular comment exactly `ServerSelectPane EventHandler secondary vtable; COL at 0x00624d84, 11 slots, complete-object offset 0xa0.`. All five COL items remain at their literal boundaries with the same names/types/values/regular texts/repeatable absence/xrefs, full bytes and hash listed in prestate | apply |
| A3D7-27 | tertiary vtable head `[0x00624db8,0x00624dbc)` plus locator `[0x00624db4,0x00624db8)` and COL `[0x0065034c,0x00650360)` | Locator item: data, name absent, type absent, regular comment absent, repeatable comment absent, bytes `4c 03 65 00`, SHA256 `821AE1DB0FECCDD8A09DB67B0B79F44C69977EB494A282CB7ABB4C3FB67D22EA`, dword pointer `0x0065034c`, zero inbound xrefs. Head item: data, name `??_7ServerSelectPane@@6B@_1`, type absent, regular comment absent, repeatable comment absent, bytes `66 47 57 00`, SHA256 `8B93199BFD1CC52F0762813701D3F36C48DA4AC08B83D17444CFA45879FDBD73`, dword target `0x00574766`, inbound data xrefs exactly `0x00573da2`, `0x00574320`, `0x00574796`. COL has five four-byte data items and full bytes `00 00 00 00 a4 00 00 00 00 00 00 00 a4 91 67 00 98 02 65 00`, SHA256 `55D86B3DC5B7068123F5D71E36543CFCEEE4596A00CFE8451594B50A4D212EDF`: `[0x65034c,0x650350)` name `??_R4ServerSelectPane@@6B@_1`, type absent, value `0`, regular `signature`, repeatable absent, sole xref `0x624db4`; `[0x650350,0x650354)` name/type absent, value `0xa4`, regular `offset of this vtable in complete class (from top)`, repeatable absent, zero xrefs; `[0x650354,0x650358)` name/type absent, value `0`, regular `offset of constructor displacement`, repeatable absent, zero xrefs; `[0x650358,0x65035c)` name/type absent, value `0x006791a4`, regular `reference to type description`, repeatable absent, zero xrefs; `[0x65035c,0x650360)` name/type absent, value `0x00650298`, regular `reference to hierarchy description`, repeatable absent, zero xrefs | `set_address_comments`; regular channel text `ServerSelectPane TimerHandler tertiary vtable; COL at 0x00624db4, 2 slots, complete-object offset 0xa4.` | Before mutation, hard-stop if any listed boundary, classification, name, type, comment channel, bytes, hash, value, or xref differs. Apply only the head regular comment. After readback, hard-stop and do not persist if the head repeatable channel changes or any locator/COL/head protected state changes | Locator remains data `[0x624db4,0x624db8)`, unnamed/untyped, both comments absent, bytes/hash/value/xrefs exactly as prestate. Head remains data `[0x624db8,0x624dbc)`, same decorated name, absent type, same bytes/hash/value/three xrefs, repeatable absent, with regular comment exactly `ServerSelectPane TimerHandler tertiary vtable; COL at 0x00624db4, 2 slots, complete-object offset 0xa4.`. All five COL items remain at their literal boundaries with the same names/types/values/regular texts/repeatable absence/xrefs, full bytes and hash listed in prestate | apply |

## First-Draft C++ Recommendation

The source reconstruction must cause the compiler to recreate the three vtable views, RTTI records, vptr stores, adjustor thunks, and deleting wrapper. It must not encode those artifacts as arrays or explicit vptr writes. The sole persistent derived member is the directory pointer at `+0x26c`; the empty Singleton base overlaps that offset through EBO. The observed cleanup performs no derived resource teardown, so an explicit destructor would invent human source and is omitted.

Formal target `RECONSTRUCTION_CPP` payload for UID0003D7:

```cpp
// ServerSelectPane vtables and RTTI are compiler-generated from the class
// declaration and virtual methods. Do not hand-author the
// 0x00624d24-0x00624dc0 locator or table dwords as C++.
```

Formal class `RECONSTRUCTION_CPP` payload for UID0000D2:

```cpp
#include "ServerSelectPane.h"

[[CHILDREN]]
```

Formal class `RECONSTRUCTION_H` payload for UID0000D2:

```cpp
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"

struct ServerSelectDirectory;

class ServerSelectPane : public DialogPane,
                         public Singleton<ServerSelectPane>
{
public:
    ServerSelectPane(ServerSelectDirectory *serverDirectory);

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

private:
    ServerSelectDirectory *m_serverDirectory;
};
```

The syntax is period-compatible and project-consistent: no C++11 `override`, no decompiler names, no raw ABI declarations, and no explicit destructor absent authored behavior. UID0003D7 H remains blank. Existing UID0000S8 forward declaration, CPP global definition, and H extern remain unchanged and precede this class route.

## Final Recommendation

- Ordinary claims C3D7-001 through C3D7-035 and C3D7-051 have been implemented at report depth across the target and support documents. C3D7-032 and C3D7-039 were independently already present and preserved.
- Keep UID0003D7 class-owned, reconstructable, and emitted by UID0000D2. Keep UID00026F false/non-emitting as a mixed physical parent.
- Generate the observed ABI through the class declaration and virtual methods; never author raw vtables, RTTI, vptr stores, adjustor thunks, or deleting wrappers.
- Supervisor applies C3D7-036 through C3D7-038 to manual coverage only after ordinary-document verification.
- Supervisor applies IDA claims C3D7-040 through C3D7-049 only after fresh Gate 2A and literal canonical prestate checks; C3D7-039 remains checked `already-present` provenance and is not a pending Gate 2B mutation.
- Within C3D7-043, the reproduced function-level type stage has a bounded intermediate frame: `Block` / `void *` remains at `+0x1c` while `notifyCode` / `int` appears at `+0x20`. The stack rename then yields `controlIndex` / `void *`; the required-name-bound stack type stage accepts source text `int` and must physically read back `controlIndex` / `signed __int32` at `+0x1c`. The semantic function signature remains `int controlIndex`. Any other result or non-target drift fails closed and leaves canonical state unsaved.
- Within C3D7-046 and C3D7-047, preserve address regular `Block` at each adjustor entry and add the literal semantic summary only in the function regular channel. Address repeatable and function repeatable remain blank; any channel drift fails closed before persistence.
- B010 completed scoped ordinary validation and the validator-owned generated refresh/readback recorded below. C3D7-050 remains unchecked because its exact compound claim also requires supervisor verification and the three manual coverage rows. Lifecycle execution and archival remain supervisor-owned.
- Independent generated empty emitters UID0000D1, UID0003D9, UID0000VG, and UID0001HR are not falsely claimed resolved by this target.

## Recommended Target Doc Changes

For `by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md`:

The following accepted target changes are now applied:

- Set `COMPLETION:94`, `CONFIDENCE:98`, `POSITION:20`; preserve UID, owner `0000D2`, `RECONSTRUCTABLE:TRUE`, emitter `0000D2`, and `Nested:0`.
- Set Item Summary to: `Exact 156-byte ServerSelectPane compiler ABI child: three locator-prefixed primary/EventHandler/TimerHandler vtable views, complete 39-cell slot map, shared eight-base RTTI graph, constructor/cleanup/deleting-wrapper store triads, corrected OnControlCommand/UpdateActionButton overrides, clean SimpleListPane/ServerSelectMenuItemList boundaries, and declaration-generated no-raw-array source disposition.`
- Incorporate the complete 39-cell inventory, six COL/table subrange hashes, three COL graphs, CHD/BCA/eight-BCD graph, PMDs, all inbound store/xref triads, exact neighboring cells, relevant function hashes/frames, source-route reasoning, no-split decision, current IDA snapshot, and positive/negative evidence.
- Put the exact target marker from Section 22 in formal CPP and keep formal H blank.
- Preserve the old broad primary extent and old method names in a `Historical Assumptions Rejected By Current Evidence` section with their contradicting slot/boundary proof.

## Recommended Support Doc Changes

The following accepted ordinary support changes are now applied, except UID0000S8 which was already exact and remained byte-for-byte unchanged:

- `by-class/ServerSelectPane.md` UID0000D2: set `93/95`, position 10, preserve owner/emitter UID0000NO; incorporate exact inheritance, RTTI views/PMDs, `0x270` layout, EBO-overlapped directory member, corrected two virtuals, implicit-destructor/compiler-artifact disposition, header/source order, and exact Section 22 CPP/H payloads.
- `by-file/ServerSelectPane.md` UID0000NO: set `91/94`; preserve source path `NexusTK/login/`; add complete class/header/vtable source order and corrected method naming while retaining every unrelated list/helper/resource fact.
- `by-memory/0x00573d20-0x005747df.ServerSelectPane.md` UID0001HR is the exact existing current path: set `91/94`; preserve owner/emitter UID0000NO and blank formal channels; add the exact constructor, cleanup, two human virtuals, singleton clear, adjustors, deleting wrapper, hashes, frames, xrefs, and compiler/source dispositions. Superseded alias `by-memory/0x00573d20-0x005747af.ServerSelectPane.md` is historical only and is not a live destination.
- `by-item/ServerSelectHelpers_574510_5745b0.md` UID0000VG is the exact existing current path: keep `86/91`; preserve owner/emitter and formal payload; synchronize both caller descriptions from `OnDialogAction` to `OnControlCommand` without claiming helper-body closure. Superseded alias `by-item/ServerSelectServerDirectoryLookup.md` is historical only and is not a live destination.
- `by-memory/0x00624c60-0x00624f20.SimpleServerSelectReadOnlyData.md` UID00026F is the exact existing current path: keep `85/91`, `RECONSTRUCTABLE:FALSE`, no owner/emitter; add exact UID0003D7 range, three-view child disposition, and clean predecessor/successor boundaries without raw arrays. Superseded alias `by-memory/0x00624b24-0x00625e78.ServerSelectData.md` is historical only and is not a live destination.
- `by-global/g_pServerSelectPane.md` UID0000S8: keep `92/94`, position 0, formal forward/definition/extern and sole external-linkage evidence unchanged; add only a cross-reference to the completed class lifecycle if needed.
- Do not create a new by-vtable page. UID0003D7 itself is the exact locator-inclusive ABI inventory.

## Score And Metadata Recommendation

| UID | Current | Recommended | Owner / emitter | Reason |
| --- | --- | --- | --- | --- |
| 0003D7 | pre-callback 85/91 | applied 94/98, position 20 | 0000D2 / 0000D2 | complete bytes, slots, RTTI, xrefs, layout, boundaries, source route and formal no-raw-data disposition |
| 0000D2 | pre-callback 90/93 | applied 93/95, position 10 | 0000NO / 0000NO | exact declaration, member/layout, corrected virtuals and implicit-destructor decision |
| 0000NO | pre-callback 89/91 | applied 91/94 | existing file root | target-specific class/header/source-order closure; unrelated child work remains |
| 0001HR | pre-callback 89/92 | applied 91/94 | 0000NO / 0000NO | complete executable-family identities, frames, hashes, xrefs and source/compiler split |
| 0000VG | 86/91 | keep 86/91 | existing | caller-name synchronization only; helper body not newly researched |
| 00026F | 85/91 | keep 85/91 | none / none | mixed parent remains a non-emitting physical index |
| 0000S8 | 92/94 | keep 92/94, position 0 | existing | current global source is already exact |

The target does not exceed the 95 completion barrier because manual coverage, final supervisor verification, and canonical IDA recommendations remain supervisor-gated. Confidence 98 is justified for the finite ABI data itself; source spelling/access labels remain inferred. The reproduced A3D7-09/A3D7-09.2 frame behavior does not lower the source score: it is a bounded IDA metadata-rendering distinction, the semantic `int controlIndex` function type is accepted exactly, and the explicitly bound stack-target type stage deterministically canonicalizes the physical row to equivalent `signed __int32` with a complete hard-stop contract. The adjustor comment-channel correction likewise does not lower the source score: live four-channel readback resolves the ambiguity exactly, and A3D7-16 through A3D7-21 now preserve address regular `Block` while adding separate function regular summaries.

## Open Questions With Attempted Resolution

- Exact original class header spelling is not recoverable from the binary. `ServerSelectPane.h` is the high-probability project-consistent result because the file route and generated naming already use it.
- Exact original member spelling is stripped. `m_serverDirectory` is selected over raw/abbreviated alternatives from the `ServerSelectDirectory` type, constructor source role, project member conventions, and sole `+0x26c` derived field.
- Old `OnDialogAction` and `UpdateScrollButtons` names were actively rechecked and rejected. The direct base-slot identities, two-argument cleanup, and behavior support `OnControlCommand` and `UpdateActionButton`.
- An explicit destructor was investigated and rejected: no derived owned resource is torn down; ordinary cleanup consists of compiler-visible vptr/singleton/base lifecycle work.
- A standalone by-vtable page was investigated and rejected because it would duplicate UID0003D7's exact range, inventory, owner and formal source disposition.
- Constructor `arg_4` and decompiler-shaped locals are retained literally in the IDA safety contract rather than silently normalized. Only the evidence-backed source argument/member are promoted.
- The `OnControlCommand` first physical argument is resolved as a staged metadata issue rather than deferred: function `set_type` demonstrably leaves `Block` / `void *` at `+0x1c`; stack rename produces `controlIndex` / `void *`; the stack-target type endpoint requires the `name` binding and accepts source text `int`, but physical `stack_frame` canonically reports `controlIndex` / `signed __int32`. This physical spelling is the correct expected IDA state and does not alter reconstructed C++ `int controlIndex`. If any dedicated endpoint fails its exact prestate/poststate contract, the supervisor must stop rather than claim an implicit or differently spelled conversion.
- Adjustor comment ownership is resolved rather than deferred: live `get_comments` identifies `Block` at `0x57475b` and `0x574766` as address regular state and proves both function channels plus both repeatable channels are otherwise blank. The evidence-preserving contract keeps `Block` in the address regular channel and writes the source-quality summary only to function regular; a function-comment action is never described as replacing address state.
- The target's empty emitter is resolved by the formal compiler-generated marker plus the owning class declaration. Other generated empty markers belong to separate UIDs and remain explicit non-claims.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Insert under UID00026F in `by-memory/-coverage-report.md`, immediately after UID0003D5:

`      - [UID:0003D7][0x00624d24-0x00624dc0.ServerSelectPaneVtableData](by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md) 0x00624d24-0x00624dc0 | compiler vtable/RTTI data | ServerSelectPaneVtableData : reconstructable : 94% : very-strong : Exact 156-byte/39-cell primary, EventHandler, and TimerHandler locator-prefixed vtable child with shared eight-base RTTI, PMD offsets 0/+0xa0/+0xa4, complete slots and lifecycle store triads, corrected OnControlCommand/UpdateActionButton overrides, clean neighboring boundaries, class UID0000D2 owner/emitter, and formal declaration-generated no-raw-array disposition.`

Replace the UID0000D2 row in `by-class/-coverage-report.md` with:

`- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md) : reconstructable : 93% : very-strong : Pre-login server-selection dialog with exact DialogPane plus Singleton<ServerSelectPane> inheritance, 0x270 layout and EBO-overlapped ServerSelectDirectory pointer, corrected OnControlCommand/UpdateActionButton virtuals, implicit-destructor/compiler-wrapper disposition, complete three-view RTTI/vtable cause, formal ServerSelectPane.h declaration, and child-based CPP routing.`

Replace the UID0000NO row in `by-file/-coverage-report.md` with:

`- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) : reconstructable : 91% : very-strong : Login server-selection source module with class/list/helper/resource inventories, exact singleton external-linkage source, complete ServerSelectPane declaration/header route, three-view compiler-vtable child and corrected virtual identities; independent list/helper/broad-method emitters remain separate work.`

No tracker row is edited manually. Generated tracker state remains validator-owned.

## Follow-Up Actions

1. Any lifecycle action requires a fresh exact-artifact Gate 1 audit for the artifact revision being acted on.
2. Supervisor verifies every ordinary claim and final destination hash, then applies the three exact manual coverage rows.
3. Supervisor performs fresh Gate 2A/Gate 2B checks and canonical IDA work for C3D7-040 through C3D7-049 while preserving the already-present read-only provenance C3D7-039; the C3D7-043 retry must use A3D7-09.2's required `name` binding and accept only the exact physical `controlIndex` / `signed __int32` readback while retaining semantic `int controlIndex`. For C3D7-046/C3D7-047, fresh preflight must confirm address regular `Block` plus three blank channels at each adjustor, preserve that address comment through rename/type, then add only the distinct function regular summary.
4. Supervisor completes the compound C3D7-050 verification, then alone executes or archives the report after all gates pass. Independent empty emitters remain queued under their own UIDs.

## Confidence

- Exact range, cells, slots, RTTI records, PMDs, boundary ownership, vptr-store triads and current IDA state: 99%.
- Constructor/cleanup/compiler-wrapper classification and absence of authored derived teardown: 98%.
- Corrected `OnControlCommand` and `UpdateActionButton` identities/signatures: 98%.
- Owner/emitter/source route and no duplicate by-vtable page: 98%.
- Human source declaration, access labels, filename and member spelling: 94%.
- Recommended target score: completion 94, confidence 98.

## Validator Results

All commands used exact working directory `E:\NTK\GhidraBridge\source-3\project-documentation`; validator output resolved the canonical root as `C:\FastStorage\NTK_Sources\source-3\project-documentation`. Commands are recorded as inert single-line receipts, not executable blocks.

| Destination | Exact command and receipt | Result / diagnostics / side effects | Final reread |
| --- | --- | --- | --- |
| `by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md` | `python .\tools\validator.py --mode file --file "by-memory\0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md" --apply --queue-timeout 240`; command `000000023773`, `2026-08-14T23:05:21-04:00` | exit `0`, `ok:1`, no warnings/errors; completion/confidence `94/98`, position/formal registry updates, four UID-link repairs, two reference-index adds, projected-stats update; generated refresh deferred | SHA256 `C1186D486A4CD2BD8A6821B27724377499B06E28CF629781A9F50DFC871BD60E`, 13,972 bytes/171 lines |
| `by-class/ServerSelectPane.md` | `python .\tools\validator.py --mode file --file "by-class\ServerSelectPane.md" --apply --queue-timeout 240`; command `000000023775`, `2026-08-14T23:06:30-04:00` | exit `0`, `ok:1`, no warnings/errors; completion/confidence `93/95`, position/CPP/H registry updates, one reference-index add, projected-stats update; generated refresh deferred | SHA256 `E0472F9810BCC938EE1348CE393F8D00137DA638B8BECB25150544C9D56AABB2`, 18,820 bytes/203 lines |
| `by-memory/0x00573d20-0x005747df.ServerSelectPane.md` | `python .\tools\validator.py --mode file --file "by-memory\0x00573d20-0x005747df.ServerSelectPane.md" --apply --queue-timeout 240`; command `000000023776`, `2026-08-14T23:09:11-04:00` | exit `0`, `ok:1`, no warnings/errors; completion/confidence `91/94`, two reference-index adds, projected-stats update; generated refresh deferred | SHA256 `7B11FF96E7771B028661C0561616684FD43D053213479A637DF1F6A08BD23AC6`, 35,191 bytes/286 lines |
| `by-item/ServerSelectHelpers_574510_5745b0.md` | `python .\tools\validator.py --mode file --file "by-item\ServerSelectHelpers_574510_5745b0.md" --apply --queue-timeout 240`; command `000000023777`, `2026-08-14T23:09:51-04:00` | exit `0`, `ok:1`, no warnings/errors; score remained `86/91`, one stats-row and projected-stats update; generated refresh deferred | SHA256 `B1717F27E1AE553A9D0015D06B6412B2BB569538698F79B0A9336DED07C1EE76`, 16,648 bytes/161 lines |
| `by-memory/0x00624c60-0x00624f20.SimpleServerSelectReadOnlyData.md` | `python .\tools\validator.py --mode file --file "by-memory\0x00624c60-0x00624f20.SimpleServerSelectReadOnlyData.md" --apply --queue-timeout 240`; command `000000023778`, `2026-08-14T23:10:32-04:00` | exit `0`, `ok:1`, no warnings/errors; score remained `85/91`, one UID-link repair, two reference-index adds, projected-stats update; generated refresh deferred | SHA256 `1A258025619EA0D6DBC27581E0A3076316FB4F645A3F4B065E30D7F3E09F2F3E`, 15,145 bytes/111 lines |
| `by-file/ServerSelectPane.md` and coherent refresh | `python .\tools\validator.py --mode file --file "by-file\ServerSelectPane.md" --apply --queue-timeout 240 --wait-generated`; command `000000023779`, `2026-08-14T23:11:51-04:00` | exit `0`, `ok:1`; completion/confidence `91/94`, two reference-index adds and projected-stats update. Generated refresh completed, rebuilt validator registry, refreshed generated metadata/tracker, and reported unrelated repository-wide diagnostics: 72 missing explicit CPP child markers, 74 independent empty emitters, one missing H child marker, nine fallback child insertions, and unrelated header no-op/metadata rows. No UID0003D7-specific warning or error occurred. | by-file SHA256 `FB9C5090D05934E0ABE9362308E7A38AF29C810AFE00942A7FAA49915D9C83B6`, 20,412 bytes/195 lines; physical CPP/H readback below |

Physical generated readback from dated ordinary-callback command `000000023779`:

- `auto-generated/NexusTK/login/ServerSelectPane.cpp`: SHA256 `7161A3E46761EDEFFCBBBC0160C0BAFE3A015A2A26AE7F8BC31612F3576A597E`, 1,369 bytes/26 lines. It identifies command `000000023779`, emits UID0000S8 once, UID0000D2's `#include "ServerSelectPane.h"` route, then UID0003D7's exact three-line compiler-generated ABI marker. UID0000D2 and UID0003D7 have no empty marker. No raw table array, duplicate ServerSelectPane definition, stub, TODO, or placeholder was introduced. Independent empty markers UID0000D1, UID0003D9, UID0000VG, and UID0001HR remain explicit separate work.
- `auto-generated/NexusTK/login/ServerSelectPane.h`: SHA256 `4A1390BEE9733544F6A65B0E163DB9DBF1CCE40E7DB654438F3878FDE6DC8239`, 1,012 bytes/32 lines. It identifies command `000000023779`, contains UID0000S8's forward/extern exactly once and UID0000D2's exact base includes, directory forward declaration, two-base class, constructor, period-compatible `OnControlCommand`/`UpdateActionButton` virtuals, and directory member. There is one complete ServerSelectPane declaration and no duplicate or placeholder.
- Superseded command `000000023750`, command `000000023745`, and initial drafting hashes remain historical observations only. Command `000000023779` and its hashes are the dated ordinary-callback receipt, not permanently current generated authority; the supervisor's fresh gate-time reread controls current validator-owned generated state and may advance coherently.

## Changed Files

- Ordinary documents changed and scoped-validated: `by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md`, `by-class/ServerSelectPane.md`, `by-file/ServerSelectPane.md`, `by-memory/0x00573d20-0x005747df.ServerSelectPane.md`, `by-item/ServerSelectHelpers_574510_5745b0.md`, and `by-memory/0x00624c60-0x00624f20.SimpleServerSelectReadOnlyData.md`.
- Report updated in place: `tools/leaser/Agents/Agent-B010/research/0003D7-ServerSelectPaneVtableData-empty-emitter-source-quality.md`.
- `by-global/g_pServerSelectPane.md` was verified already exact and remained byte-for-byte unchanged at SHA256 `F315D9AC9593EBB80D41989802885CCB4E635CC8E229A132F8FA161598D165E4`.
- No manual coverage report, audit/catalog file, goal/notes file, lifecycle state, or IDA database was changed. Generated outputs, generated tracker/metadata, projected stats, and validator registry changed only as validator-owned side effects of the authorized scoped commands; no generated or validator-owned file was edited directly.
- Lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the artifact path and validator-owned history being acted on; no ordinary report prose asserts a current lifecycle phase.

## Implementation Tracking Checklist

| Implemented | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C3D7-001 | 0003D7 | Exact target is `[0x00624d24,0x00624dc0)`, 156 bytes, 39 four-byte data items, SHA256 `A2B59C180BD9546543BB2BB7D77288A02CBAD759AC62EF8F31C96D4F590F2C73`. | 99 | live items/bytes | target Range/Inventory | incorporate | applied |
| [x] | C3D7-002 | 0003D7 | Six exact subranges and hashes separate three COL pointers from three table views without padding. | 99 | bytes/items/hashes | target Boundaries | incorporate | applied |
| [x] | C3D7-003 | 0003D7 | Primary COL `0x624d24 -> 0x650284` precedes 23 slots at `0x624d28..0x624d80`. | 99 | dwords/COL/items | target Primary view | incorporate | applied |
| [x] | C3D7-004 | 0003D7 | Secondary COL `0x624d84 -> 0x650338` precedes 11 EventHandler slots at `0x624d88..0x624db0`. | 99 | dwords/COL/items | target Secondary view | incorporate | applied |
| [x] | C3D7-005 | 0003D7 | Tertiary COL `0x624db4 -> 0x65034c` precedes two TimerHandler slots at `0x624db8/0x624dbc`. | 99 | dwords/COL/items | target Tertiary view | incorporate | applied |
| [x] | C3D7-006 | 0003D7 | Incorporate the complete 23-slot primary table with exact targets and source roles. | 99 | bytes/lookup/current DialogPane map | target Slot inventory | incorporate | applied |
| [x] | C3D7-007 | 0003D7 | Incorporate the complete 11-slot EventHandler table and inherited handler order. | 99 | bytes/lookup/RTTI PMD | target Slot inventory | incorporate | applied |
| [x] | C3D7-008 | 0003D7 | Incorporate the complete two-slot TimerHandler table. | 99 | bytes/lookup/RTTI PMD | target Slot inventory | incorporate | applied |
| [x] | C3D7-009 | 0003D7 | Preserve all three decorated table-head names, blank types/comments, and exact four-byte item boundaries. | 99 | inspect/comments | target IDA snapshot | incorporate | applied |
| [x] | C3D7-010 | 0003D7 | Each table head has constructor, ordinary-cleanup, and scalar-wrapper stores at the exact three-address triad. | 99 | inbound xrefs | target Xrefs | incorporate | applied |
| [x] | C3D7-011 | 0003D7 | Three COLs share type descriptor `0x6791a4` and CHD `0x650298`, with offsets `0`, `0xa0`, `0xa4`. | 99 | COL dwords | target RTTI | incorporate | applied |
| [x] | C3D7-012 | 0003D7 | CHD attributes `1` and eight BCDs prove ServerSelectPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, Singleton. | 99 | CHD/BCA/BCD | target RTTI | incorporate | applied |
| [x] | C3D7-013 | 0003D7 | EventHandler PMD is `+0xa0`, TimerHandler `+0xa4`, and direct Singleton PMD is `+0x26c`; DialogPane begins at zero. | 99 | BCD PMDs | target/class Layout | incorporate | applied |
| [x] | C3D7-014 | 0003D7 | Predecessor `0x624d20` is the final SimpleList table cell; successor `0x624dc0` is the ServerSelectMenuItemList COL. | 99 | items/dwords/names | target Boundaries | incorporate | applied |
| [x] | C3D7-015 | 0001HR | Constructor `0x573d20-0x574301` stores all three vptrs, stores the directory pointer at `+0x26c`, and has one MainMenu caller. | 99 | decompile/frame/xrefs | executable Evidence | incorporate | applied |
| [x] | C3D7-016 | 0001HR | `0x574310-0x574339` is ordinary derived cleanup: restore vptrs, clear singleton, run base destruction. | 99 | decompile/bytes | executable Evidence | incorporate | applied |
| [x] | C3D7-017 | 0000D2 | `0x574340` is the two-argument primary `+0x48` override `OnControlCommand(int,int)`, superseding `OnDialogAction(int)`. | 98 | vtable slot/retn 8/base declaration/body | class Methods | incorporate | applied |
| [x] | C3D7-018 | 0000D2 | `0x574440` is primary `+0x4c` `UpdateActionButton()`, superseding `UpdateScrollButtons()`. | 98 | vtable slot/base declaration/body | class Methods | incorporate | applied |
| [x] | C3D7-019 | 0001HR | `0x574750/75b/766/780` are singleton EH clear, two adjustors, and scalar deleting wrapper, not authored class methods. | 99 | bytes/xrefs/decompile | executable Compiler lowering | incorporate | applied |
| [x] | C3D7-020 | 0000D2 | Emit no explicit derived destructor and no raw vtable/RTTI/vptr statements; implicit virtual destruction recreates the observed family. | 97 | base virtual destruction/no derived resource teardown | class Source rationale | incorporate | applied |
| [x] | C3D7-021 | 0003D7 | Keep owner/emitter UID0000D2 and reconstructable true; set target position 20. | 98 | class/source/routing evidence | target Metadata | incorporate | applied |
| [x] | C3D7-022 | 0003D7 | Add the exact Section 22 compiler-generated ABI marker in CPP and keep H blank. | 99 | formal source policy | target Formal CPP/H | incorporate | applied |
| [x] | C3D7-023 | 0003D7 | Raise target `85/91 -> 94/98`; populate Item Summary and keep Nested 0. | 97 | complete evidence closure | target Metadata/Summary | incorporate | applied |
| [x] | C3D7-024 | 0000D2 | Incorporate exact inheritance, `0x270` layout, EBO overlap, directory member, corrected virtuals, and implicit-destructor decision. | 98 | RTTI/types/code | class Layout/Methods | incorporate | applied |
| [x] | C3D7-025 | 0000D2 | Apply exact Section 22 CPP include/children route and complete H declaration. | 97 | source/header analysis | class Formal CPP/H | incorporate | applied |
| [x] | C3D7-026 | 0000D2 | Raise class `90/93 -> 93/95`, set position 10, preserve owner/emitter UID0000NO. | 96 | declaration/layout/method closure | class Metadata | incorporate | applied |
| [x] | C3D7-027 | 0000NO | Incorporate complete class/vtable/header/source-order and corrected method naming while preserving unrelated list/helper evidence. | 96 | file/generated/support evidence | file Source emission policy | incorporate | applied |
| [x] | C3D7-028 | 0000NO | Raise file `89/91 -> 91/94`; preserve `NexusTK/login/`. | 95 | target/class/header closure | file Metadata | incorporate | applied |
| [x] | C3D7-029 | 0001HR | Raise broad executable evidence `89/92 -> 91/94` and correct the method/destructor/vtable-family map while keeping formal CPP/H blank. | 95 | full related-code recheck | `by-memory/0x00573d20-0x005747df.ServerSelectPane.md` Evidence/Metadata | incorporate | applied |
| [x] | C3D7-030 | 0000VG | Keep helper `86/91` and source route; synchronize its two callers to `OnControlCommand` without claiming new helper-body closure. | 96 | caller/body relationship | `by-item/ServerSelectHelpers_574510_5745b0.md` Caller evidence | incorporate | applied |
| [x] | C3D7-031 | 00026F | Keep mixed parent `85/91`, false/non-emitting; add complete UID0003D7 child disposition without changing parent ownership. | 99 | exact mixed island/child split | `by-memory/0x00624c60-0x00624f20.SimpleServerSelectReadOnlyData.md` Child inventory | incorporate | applied |
| [x] | C3D7-032 | 0000S8 | Preserve global `92/94`, position 0, formal forward/definition/extern, and sole external linkage. | 99 | current global lifecycle | global No-change support | already-present | already-present |
| [x] | C3D7-033 | 0003D7 | Do not create a duplicate by-vtable page; document why the exact by-memory child is the complete ABI owner. | 96 | current type-page search/routing | target/support policy | incorporate | applied |
| [x] | C3D7-034 | 0000NO | Record dated ordinary-callback generated CPP/H hashes and observed post-callback result: target/class markers resolved, no raw arrays or duplicate declaration; current authority is supervisor-reread dynamically. | 99 | physical generated readback | file Generated output | incorporate | applied |
| [x] | C3D7-035 | 0003D7 | Preserve stale primary extent and old method names only as historical rejected assumptions with reasons. | 99 | current evidence comparison | target/support History | incorporate | applied |
| [ ] | C3D7-036 | 0003D7 | Insert the exact Section 28 target row under UID00026F in manual by-memory coverage. | 99 | current absent row | by-memory coverage | incorporate | proposed |
| [ ] | C3D7-037 | 0000D2 | Replace the exact Section 28 class row with score 93 and declaration/vtable closure text. | 99 | current class row | by-class coverage | incorporate | proposed |
| [ ] | C3D7-038 | 0000NO | Replace the exact Section 28 file row with score 91 and header/vtable closure text. | 99 | current file row | by-file coverage | incorporate | proposed |
| [x] | C3D7-039 | 0003D7 | Preserve the attested canonical read-only session identity and exact report-time IDA snapshot as evidence, not an operational package. | 99 | runtime attestation/live queries | report IDA provenance | already-present | already-present |
| [ ] | C3D7-040 | 0000D2 | Protect current forward-like `ServerSelectPane` type state and do not create an unsafe complete IDA UDT. | 98 | type_inspect/layout evidence | IDA Gate2B no-change | incorporate | proposed |
| [ ] | C3D7-041 | 0001HR | Apply dependency-ordered rename/type/comment stages for constructor `0x573d20` with the complete frame contract. | 97 | function/frame/caller/vptr stores | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-042 | 0001HR | Apply dependency-ordered rename/type/comment stages for ordinary cleanup `0x574310`. | 98 | function/frame/body | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-043 | 0001HR | Apply dependency-ordered function rename, exact semantic `int controlIndex` function type, explicit `Block -> controlIndex` stack rename, explicitly bound source-`int` stack type with physical `signed __int32` readback, and comment stages for `OnControlCommand` at `0x574340`, preserving both reproduced intermediate frames. | 98 | slot/base/body/reproduced endpoint/frame/required-name binding/canonical IDA spelling | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-044 | 0001HR | Apply dependency-ordered rename/type/comment stages for `UpdateActionButton` at `0x574440`. | 98 | slot/base/body/frame | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-045 | 0001HR | Rename/comment the singleton construction-failure clear helper at `0x574750`; preserve its `void()` type. | 96 | body/EH xref/global clear | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-046 | 0001HR | Rename/type the `+0xa0` scalar-destructor adjustor at `0x57475b`, preserve address regular comment `Block`, and add the adjustor summary only as a function regular comment. | 97 | bytes/jump/table slot and four-channel comment readback | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-047 | 0001HR | Rename/type the `+0xa4` scalar-destructor adjustor at `0x574766`, preserve address regular comment `Block`, and add the adjustor summary only as a function regular comment. | 97 | bytes/jump/table slot and four-channel comment readback | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-048 | 0001HR | Rename/type/comment the scalar deleting wrapper at `0x574780`. | 98 | body/frame/xrefs | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-049 | 0003D7 | Add exact regular comments to the three decorated table heads while preserving names, blank types, and item boundaries. | 99 | table/COL/PMD evidence | IDA Gate2B supervisor action | incorporate | proposed |
| [ ] | C3D7-050 | 0003D7 | Supervisor validates every changed ordinary destination, applies three manual coverage rows, refreshes/rereads CPP/H, and proves the UID0003D7 empty marker is gone. | 99 | workflow/generated requirements | Validator Results | incorporate | proposed |
| [x] | C3D7-051 | 0003D7 | Preserve all valid research, negative evidence, rejected alternatives, the original report-first boundary as history, and supervisor-only lifecycle authority. | 99 | workflow/report evidence | report and changed docs | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000024025","destination_path":"executed-b-agent-research/B010/0003D7-ServerSelectPaneVtableData-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0003D7-ServerSelectPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-15T05:43:54-04:00","uid":"0003D7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
