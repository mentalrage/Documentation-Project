** TARGET-REPORT-UID:0001DV **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001DV CScrollBarBackPaneCore Source-Quality Research


## Finalized Report / Current Recommendation

- Current implemented disposition: [UID:0001DV] is now a class-owned, non-emitting `92/94` split index over three exact source-bearing children: [UID:0004Y8] retained constructor `[0x0053fea0,0x0053fed2)`, [UID:0004Y9] ordinary empty destructor `[0x0053fee0,0x0053feff)`, and [UID:0004YA] `CScrollBarBackPane::OnPaint()` `[0x0053ff00,0x0053ff8d)`. The two internal alignment spans are separately recorded in [UID:0000VN].
- Applied metadata: `CANONICAL_OWNER:00003D` is preserved, `RECONSTRUCTABLE` is false, `EMITTER_UIDS` and both formal blocks are blank, and `Nested:3`. The exact children own source and emit through [UID:00003D].
- Applied source-route correction: [UID:00003D] and its scalar-destructor/vtable support now route through [UID:0000M7] `OptionPane`; [UID:0000NF] retains the former route only as rejected history. The live instances are two `NewOptionPane` volume-slider background panes at `+0x12cc` and `+0x12d0`; no generic `ScrollPane`, `ScrollWidget`, or `ScrollablePane` route exists.
- Human identities resolved: `0x004b9600` is `GrafPort::MoveTo(int x, int y)` and `0x0069b3e4` is typed global callback `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta`. Primary vtable slot `+0x44` proves `0x0053ff00` is `CScrollBarBackPane::OnPaint()`.
- Source shape resolved: an out-of-line `CScrollBarBackPane()` calls `Pane(true)`; an out-of-line empty virtual destructor explains the ordinary helper; `OnPaint()` draws a minus sign, three-line slider groove, and plus sign. The scalar deleting destructor and the two adjusted entries remain compiler ABI output.
- Supervisor Gate 2B is applied, read back, and saved: the minimal incomplete class type, exact constructor/destructor/OnPaint/scalar-wrapper identities and prototypes, one-star adjusted receiver prototypes, function comments, stale-`Block` clears, and callback address comment all match the accepted action table. The accepted saved Gate 2B checkpoint SHA256 is `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C`; catalog entry 0354's later moving-state frame presentation is reconciled separately below without attributing any IDA mutation to B007.
- Mandatory constructor analysis discrepancy is bounded and documented: disassembly has literal `push 1` at `0x0053fea7`, proving `Pane(true)`, while current Hex-Rays warns `positive sp value has been detected, the output may be wrong!` and renders `Pane__Constructor((Pane *)this, savedregs)`. The human draft remains `Pane(true)` because bytes/disassembly, not the faulty decompile argument, are authoritative.
- Confidence: very strong for behavior, boundaries, class identity, vtable/subobject roles, helper/global identities, source bodies, and `NewOptionPane` ownership; strong for the inferred original `OptionPane.cpp` placement and source spelling.

## Supporting Research

- Research date: 2026-07-29.
- Live read-only MCP endpoint: `http://127.0.0.1:13337/mcp`; MCP session `5272cdc7-8a50-4e08-8524-fb5aa195599d`; active IDB session `5a570ede`; IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Health was `status:ok` with Hex-Rays and bounded IDB queries working. `auto_analysis_ready:false` was recorded as context only; it did not prevent exact lookup, byte, item, xref, type, comment, or decompile queries.
- Gate 1 repair recheck used the same live IDB session and read back both target adjustors plus two already-applied analogous adjustor families. The target current declarations are `Pane *__thiscall(_DWORD *this, char)`. CollectionPane2 at `0x00573247/0x00573252` and SliderControlPane at `0x0049b003/0x0049b00e` currently read back with one-star `EventHandler *` / `TimerHandler *` receivers and `unsigned int` deleting flags.
- Second exhaustive read-only Gate 1 self-audit used the same active IDB session after confirming `server_health status:ok`, `hexrays_ready:true`, and exact bounded queries. It corrected the protected successor's literal current declaration to `_DWORD *__thiscall sub_53FF90(_DWORD *this)`, distinguished `g_pfnDrawLineDelta`'s names/global-catalog identity from its blank one-byte item-head name and `MEMORY[0x69B3E4]` Hex-Rays rendering, and reverified every listed OnPaint instruction comment, all 26 callback xrefs, exact bytes/padding, type dependencies, and proposed-name collision results.
- Post-ledger-repair exhaustive self-audit rechecked this report against the current workflow vocabulary and external state. The earlier report-only checkpoint contained 84 atomic ledger rows using one allowed Action token, one affected identity, one literal destination, and the report-only Verification state `proposed`; factual already-present dispositions remained in the Action/Claim/Evidence cells and did not claim callback verification. The first Gate 2A repair expanded the ledger to 88 rows by adding the four previously omitted type-declaration, constructor-creation, ordinary-destructor, and OnPaint IDA actions. This fresh repair expands the current contiguous ledger to 97 rows by adding one blocked supervisor-owned row for each of the nine exact manual coverage operations and reclassifies C80-C82 as already-present non-actionable vtable evidence rather than blocked Gate 2B work. Mixed claims, destinations, and actions remain separated without losing their implementation payloads, live IDA session `5a570ede` reconfirmed every actionable/protected prestate, current ordinary docs and manual coverage rows matched the stated prestates, generated command `18812` remains dated unrelated/global history, and moving tracker command `18878` is recorded only as transition-safe current queue provenance.
- Final Gate 1 repair read-only evidence exhaustively enumerated all sixteen current instruction-item partitions in raw constructor `[0x0053fea0,0x0053fed2)`, the current first instruction item, Hex-Rays parameter/local state, local-user-comment state, complete stack frame, frame-member-comment state, name collision result, and deterministic expected post-action readback for the ordinary destructor, OnPaint, scalar deleting destructor, and both adjustors. It also read the callback global's exact item bounds/classification/four bytes and all applicable and non-applicable comment channels. No IDA state was changed.
- Supervisor Gate 2B then applied the accepted actions in session `5a570ede`, saved the IDB, and supplied exact readback. The accepted persisted checkpoint is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C`, `143,189,974` bytes, last-write `2026-07-29T07:58:20.9779423-04:00`. A later B007 read-only filesystem identity check found the shared IDB at intermediate SHA256 `FD8282A51836D47961EA386D7C2D25F80D0BF88B96ACFF106FFA802277F78B16`, the same `143,189,974` bytes, last-write `2026-07-29T08:08:08.7919179-04:00`. Fresh supervisor Gate 2/catalog-entry-0354 verification then used the further-advanced shared state SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB`, `143,190,049` bytes, last-write `2026-07-29T08:26:09.5759690-04:00`. These are moving shared-file checkpoints; B007 did not mutate IDA, and final supervisor lifecycle-time IDB readback remains authoritative.
- Older B003/B007 reports and current by-* prose were used as historical leads, then rechecked against the current IDB and current support docs. No stale Wave2/Wave3 conclusion was accepted.
- The Gate-1-approved ordinary-document callback created three exact child pages, updated thirteen existing ordinary support/index pages, and ran serial scoped validators only. It did not edit any manual coverage report, generated file, IDA database, audit/catalog/supervisor/lifecycle file, goal/notes file, or validator configuration/state by hand. Validator-owned projected completion statistics changed as an automatic scoped-validation side effect.

## Target

- Target UID: `0001DV`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0001DV] `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md`, currently a mixed constructor/destructor/paint aggregate and the sole declared report target.
- Target path: `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, with zero direct/additional report coverage at assignment time.
- Current supervisor classification: Gate 1 passed for exact SHA256 `B2648F964B9E638AB3AA0592BD23781CC244295F15D93FFFD62F81378426332A`; the authorized ordinary-document callback and supervisor Gate 2B IDA closure are complete. This reconciliation revision awaits fresh independent Gate 2 review.
- Current scores and parent state: `92/94`, `CANONICAL_OWNER:00003D`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, direct class parent [UID:00003D], and source ancestor [UID:0000M7].

## Current Target State

- Assignment-time metadata was `87/89`, owner/emitter [UID:00003D], reconstructable true, blank H, and a comment-only aggregate CPP marker. That state is historical. Current ordinary metadata is the applied `92/94` non-emitting split-index state described above.
- Assignment-time owner/emitter/reconstructable analysis found direct semantic class ownership correct but aggregate reconstruction/emission structurally wrong because the range contains three separate source methods and two padding spans. The callback has now applied that correction.
- Generated C++/emitter chronology remains evidence only: command `000000018740` contained only the old ScrollBar route comments; unrelated/global commands `000000018808` (`2026-07-29T04:09:31-04:00`) and `000000018812` (`2026-07-29T04:41:43-04:00`) advanced generated files without implementing this report. The callback intentionally used `--no-generated-refresh`, so no post-callback generated CPP/H claim is made. The supervisor's later lifecycle-time generated refresh/readback is authoritative.
- Existing open questions/blockers: raw constructor treatment, cleanup helper disposition, `0x004b9600`, `dword_69B3E4`, fixed-line intent, `+0xa0/+0xa4` roles, safe adjusted-receiver declarations, exact source file, aggregate split, and formal CPP/H. Every item is resolved below rather than deferred.
- Related docs checked: [UID:00003D] `by-class/CScrollBarBackPane.md`; [UID:0001E3] scalar deleting destructor; [UID:0003LR] vtable data; [UID:0000A2] Pane; Pane vtable/layout docs; [UID:000162] GrafPort draw-state accessors; [UID:0004H4] GrafPort LineTo; semantic [UID:0000TN] and physical [UID:0001PI] SurfaceRenderCallbackTable pages; [UID:000097]/[UID:0001DW] NewOptionPane; [UID:0000M7] OptionPane; [UID:0000NF] ScrollBar; `by-project-structure/proposed-source-tree.md`; current manual coverage rows; current generated ScrollBar/OptionPane source.
- Current artifact/lifecycle status: report remains in `Agent-B007/research/`; Gate 1, the ordinary-document implementation callback, the Gate 2A defect repair, and supervisor Gate 2B IDA closure are complete. Fresh independent Gate 2 verification, manual coverage, lifecycle-time generated readback, final gates, execution, and archive remain pending.

## Executive Recommendation

- Keep the semantic class owner [UID:00003D], but split the aggregate before source emission.
- Create exact child pages:
  - `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md`, reconstructable and emitting through [UID:00003D].
  - `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md`, reconstructable and emitting through [UID:00003D].
  - `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md`, reconstructable and emitting through [UID:00003D].
- Convert [UID:0001DV] to a non-emitting split index and register `[0x0053fed2,0x0053fee0)` and `[0x0053feff,0x0053ff00)` as ignored alignment.
- Change [UID:00003D] owner/emitter from [UID:0000NF] to [UID:0000M7]. Keep the class CPP channel as `[[CHILDREN]]`; place the declaration in its H channel.
- Preserve [UID:0001E3] as class-owned reconstructable evidence with a comment-only no-handwritten-wrapper marker. Preserve [UID:0003LR] as class-owned compiler vtable/RTTI evidence with a no-handwritten-table marker.
- Supervisor Gate 2B defined and typed the raw constructor; renamed/typed/commented the ordinary destructor, OnPaint, scalar deleting destructor, and EventHandler/TimerHandler adjustors; preserved exactly one-star `EventHandler *this` and `TimerHandler *this` receivers with `unsigned int flags`; cleared both stale `Block` address comments; and attached the exact address-regular callback comment. The already-correct `GrafPort_MoveTo` and `g_pfnDrawLineDelta` identities/types remained protected.

## Supervisor Active Recheck

- Historical Gate 1 instruction was to research only UID0001DV, use live MCP, resolve all named blockers, write all 33 sections, and stop without editing docs or IDA. Gate 1 subsequently passed for the exact hash recorded above.
- The explicit implementation callback then authorized the complete split and ordinary support updates. The child pages now exist as UID0004Y8, UID0004Y9, and UID0004YA; the parent and both ignored spans are reconciled.
- Every source-bearing subrange is implemented in its exact ordinary destination. The only non-source bytes inside the target remain the exact 14-byte and 1-byte `0xcc` spans.
- The standalone `type_inspect EventHandler` pointer-form result was reconciled against the emitted EventHandler class declaration and live applied adjustor prototypes; it must not be converted into an `EventHandler **` receiver. No missing MCP evidence or unresolved source-quality blocker remains in scope.

## Inference Research Guidance Check

- `by-structure.md` and the skill require source-bearing methods to live on exact children and forbid an aggregate from emitting multiple unrelated method bodies plus padding as if it were one source item.
- Existing assumptions treated as uncertain and rechecked: ScrollBar.cpp placement, generic `DrawScrollBarBackPattern` naming, cleanup-helper wording, unresolved raw helper/global identities, and the claim that a missing IDA function object prevents source emission.
- Direct IDA facts: bytes, item boundaries, vtable entries, types, comments, xrefs, inlined vptr stores, NewOptionPane fields/layout calls, and exact helper/global identities.
- Documentation evidence: Pane slot `+0x44` is OnPaint; Pane has EventHandler at `+0xa0` and TimerHandler at `+0xa4`; `g_pfnDrawLineDelta` and `GrafPort::MoveTo` are accepted source-facing contracts.
- Inference: the retained out-of-line constructor/destructor were authored in the same translation unit as NewOptionPane, and the class declaration belonged to `OptionPane` rather than generic ScrollBar infrastructure. This is high-probability inference from source order, RTTI order, inline duplicates, sole consumers, and field/layout behavior.
- Wave2/Wave3 mentions found in old NewOptionPane/Pane prose were ignored as stale and did not determine any conclusion.

## Heuristic / Inference Reanalysis And Validation

- Raw constructor: IDA has no function object or inbound pointer, but `[0x0053fea0,0x0053fed2)` is an exclusive, complete constructor body. NewOptionPane emits the same `Pane(true)` plus three-vptr sequence twice at `0x005400f7-0x00540116` and `0x00540142-0x00540161`. Best resolution: retained out-of-line source constructor whose two live calls were inlined, not padding/dead trash/no-code evidence.
- Ordinary destructor: `sub_53FEE0` restores the three derived views and tail-chains `Pane::~Pane()` with no class-specific cleanup. Its isolated placement between constructor and OnPaint, plus a separate scalar deleting wrapper, supports an authored out-of-line empty virtual destructor. It is not a generic cleanup helper and not the scalar wrapper.
- Compiler destructor family: `0x00542680` is the scalar deleting entry; `0x0054259f` and `0x005425aa` are `this-0xa0` and `this-0xa4` adjustors. They must be documented/renamed in IDA but never emitted as handwritten deleting-flags source.
- `0x004b9600`: current IDA name/type/comment and [UID:000162] converge on `void GrafPort::MoveTo(int x, int y)`. This is resolved, not provisional.
- `0x0069b3e4`: current IDA name is `g_pfnDrawLineDelta`, applied type is `SurfaceDrawLineDeltaProc`, and 26 data xrefs include GrafPort::LineTo, renderer setup, this OnPaint, and weather paint. This is resolved, not `dword_69B3E4`.
- Paint intent: exact geometry is a 103-by-5 volume-slider background. It draws a minus at x0..4/y2, the groove center x7..94/y2, parallel rails x8..93/y1 and y3, and a plus at x98..102/y2 plus x100/y0..4. NewOptionPane gives the pane a 120-by-5 bound next to a volume slider. `OnPaint` is the accurate virtual identity.
- Subobject roles: primary offset `0` is the Pane/GrafPort view, `+0xa0` is inherited EventHandler, and `+0xa4` is inherited TimerHandler. They are facets inherited through Pane, not three direct source bases or handwritten vptr members.
- Source placement: `OptionPane.cpp` wins over `ScrollBar.cpp`. The code and RTTI immediately precede NewOptionPane, NewOptionPane constructs two instances into `+0x12cc/+0x12d0`, lays them out beside its two ScrollVolumePane instances, and marks all four child panes for deletion. Generic ScrollBar code is in the separate `0x0055c200-0x0055e65c` family and has no call/data route.
- Aggregate disposition: exact children plus ignored padding are mandatory. A single aggregate block would violate method/source boundaries; a comment-only parent while children remain absent loses source. The parent therefore becomes a non-emitting split index after children are created.
- Formal source: constructor, empty destructor, and OnPaint are complete enough for first-draft insertion. No decompiler names, vptr stores, deleting flags, raw addresses, or assembly labels are present.
- Rejected alternatives: `ScrollBar.cpp` ownership, `GrafPort::LineTo` calls, generic DrawPattern name, implicit no-declaration destructor, handwritten scalar wrapper, direct EventHandler/TimerHandler bases, and aggregate code emission. Each conflicts with current binary/source-route evidence.

## Evidence Standards Used

- Primary evidence: live function lookup, exact bytes/items, decompilation, xrefs, raw pointer searches, vtable values, current names/types/comments, local type catalog, and neighboring function boundaries.
- Corroboration: current by-class/by-file/by-memory/by-global/by-type docs, current generated source topology, and current manual coverage text.
- Negative evidence: zero inbound xrefs and zero VA/RVA pointer hits for retained constructor and ordinary destructor; no generic ScrollBar consumers; no `GrafPort::LineTo` call; no alternative proposed-name collision; no CScrollBarBackPane UDT currently present.
- The evidence ladder supports exact behavior and high-confidence source inference. Original access specifiers and whether the class declaration physically lived in OptionPane.h versus the top of OptionPane.cpp cannot be read from the binary; project declaration-channel convention selects H while preserving the exact runtime shape.

## Evidence Checked

- MCP: `server_health`, `lookup_funcs`, `inspect_items`, `get_bytes`, `decompile`, `analyze_function`, `xrefs_to`, `xref_query`, `find_bytes`, `find_regex`, `get_int`, `get_global_value`, `entity_query`, `list_globals`, `type_inspect`, `type_query`, and `get_comments`.
- Exact functions checked: `0x0053fee0`, `0x0053ff00`, `0x0053ff90`, `0x005401a0`, `0x005402a0`, `0x00540600`, `0x00542680`, `0x0054259f`, `0x005425aa`, `0x004b9600`, `0x00544460`, `0x00544580`, `0x00544e90`, and the applied receiver-type analogs `0x00573247`, `0x00573252`, `0x0049b003`, and `0x0049b00e`.
- Exact data checked: vtable/COL corridor `0x00621018-0x006210a0`; callback global `0x0069b3e4`; RTTI string `.?AVCScrollBarBackPane@@` at `0x006785cc`.
- Pointer searches: constructor VA/RVA `A0 FE 53 00` / `A0 FE 13 00` and ordinary destructor VA/RVA `E0 FE 53 00` / `E0 FE 13 00` had zero hits; OnPaint VA `00 FF 53 00` had exactly one hit at primary vtable slot `0x00621060`; OnPaint RVA had zero hits.
- Gate 1 evidence checked: target, class, scalar wrapper, vtable page, Pane class/file/layout/vtable docs, EventHandler and TimerHandler class docs, CollectionPane2 and SliderControlPane applied-adjustor docs, NewOptionPane class/memory/file docs, ScrollBar file, GrafPort accessors/LineTo, callback table, manual coverage reports, assignment-time generated command `18740`, historical intermediate command `18808`, and the then-current read-only global command `18812` ScrollBar/OptionPane source.
- Gate 1 failed/unavailable checks: none required. Validators were correctly deferred during report-only research; the later authorized callback validator evidence is recorded under `## Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0001DV | Convert the target to `92/94`, `CANONICAL_OWNER:00003D`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank CPP/H, and `Nested:3`; its Functions/Split sections route to assigned children UID0004Y8, UID0004Y9, and UID0004YA. | Very strong | Exact items/bytes cover `50+14+31+1+141 = 237` bytes, the whole `0xed` range, and prove three source methods plus two pads rather than one source item. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> metadata, Status, Functions, Range/Split, formal blocks, Item Summary | incorporate | applied |
| C02 | 0004Y8 | Create `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` at `93/94`, owner/emitter UID00003D, reconstructable true, `Nested:0`, exact constructor CPP, and blank H with declaration-owner proof. | Very strong | Complete `0x32` bytes, closed `ret` boundary, Pane(true) call, three derived-view vptr installs, and two live inline duplicates in NewOptionPane. | `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` -> metadata, Status, Behavior, Evidence, Boundaries, History, CPP/H | incorporate | applied |
| C03 | 0004Y9 | Create `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` at `92/94`, owner/emitter UID00003D, reconstructable true, `Nested:0`, exact empty-destructor CPP, and blank H with declaration-owner proof. | Strong | Exact `0x1f` source-island body restores three class views and tail-chains Pane teardown; separate scalar/adjustor family proves this is the ordinary destructor. | `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` -> metadata, Status, Behavior, Evidence, Boundaries, History, CPP/H | incorporate | applied |
| C04 | 0004YA | Create `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` at `94/94`, owner/emitter UID00003D, reconstructable true, `Nested:0`, exact OnPaint CPP, and blank H with declaration-owner proof. | Very strong | Primary Pane slot `+0x44`, exact `0x8d` body, one vtable reference, six MoveTo/callback pairs, and closed endpoint. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> metadata, Status, Geometry, Callees, Evidence, Boundaries, History, CPP/H | incorporate | applied |
| C05 | 0001DV | Preserve all six coordinates/deltas and document the minus/groove/plus volume-slider role in the aggregate split. | Very strong | Six exact MoveTo/delta pairs prove the fixed-line draw intent. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> Behavior/Split | incorporate | applied |
| C06 | 00003D | Document the fixed-line draw intent in the class purpose/method inventory. | Very strong | Exact OnPaint geometry and the primary Pane vtable slot identify the class behavior. | `by-class/CScrollBarBackPane.md` -> Class Purpose/Methods | incorporate | applied |
| C07 | 0004YA | Preserve every coordinate/delta and the minus/groove/plus interpretation in the exact source-bearing child. | Very strong | Six exact MoveTo/delta pairs and closed function boundaries. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> Geometry/CPP | incorporate | applied |
| C08 | 000097 | Document the two CScrollBarBackPane fields at `+0x12cc/+0x12d0`, paired `120x5` bounds, and common deletion lifetime. | Very strong | NewOptionPane constructs, lays out, and marks both back panes for deletion beside its two volume controls. | `by-class/NewOptionPane.md` -> fields/layout/lifetime | incorporate | applied |
| C09 | 0001DW | Document the two CScrollBarBackPane fields at `+0x12cc/+0x12d0`, paired `120x5` bounds, inline construction, and common deletion lifetime. | Very strong | Exact constructor/layout/destruction sites occur in the NewOptionPane aggregate. | `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md` -> fields/layout/lifetime | incorporate | applied |
| C10 | 0001DV | Replace raw `0x004b9600` wording with source-facing `GrafPort::MoveTo(int x, int y)`. | Very strong | Current IDA name/type/comment and UID000162 converge exactly. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> Dependencies/Behavior | incorporate | applied |
| C11 | 00003D | Replace raw `0x004b9600` wording with source-facing `GrafPort::MoveTo(int x, int y)`. | Very strong | Current IDA name/type/comment and UID000162 converge exactly. | `by-class/CScrollBarBackPane.md` -> Dependencies | incorporate | applied |
| C12 | 0004YA | Use `GrafPort::MoveTo(int x, int y)` in the exact callee inventory and CPP. | Very strong | Current IDA name/type/comment and UID000162 converge exactly. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> Callees/CPP | incorporate | applied |
| C13 | 000162 | Preserve the exact already-present `GrafPort::MoveTo(int x, int y)` contract without a content or metadata edit. | Very strong | Live `0x004b9600` readback and the current page agree on name, declaration, cursor-update behavior, and comment. | `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md` -> existing MoveTo contract | already-present | already-present |
| C14 | 0001DV | Replace target raw `dword_69B3E4` wording with typed source identity `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta`, while distinguishing the blank item-head and `MEMORY[0x69B3E4]` decompiler view. | Very strong | Catalog identity, applied callback typedef, 26 xrefs, UID0000TN, and UID0001PI converge. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> Dependencies/Behavior | incorporate | applied |
| C15 | 00003D | Use typed source identity `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta` while preserving the distinct current IDA views. | Very strong | Catalog identity, applied callback typedef, 26 xrefs, UID0000TN, and UID0001PI converge. | `by-class/CScrollBarBackPane.md` -> Dependencies | incorporate | applied |
| C16 | 0004YA | Use `g_pfnDrawLineDelta` in the exact callee inventory and human CPP. | Very strong | The applied callback typedef and 26 xrefs establish the call contract. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> Callees/CPP | incorporate | applied |
| C17 | 0000TN | Preserve the 2026-07-24 pending-tinfo wording only as dated history. | Very strong | Current IDA now has applied `SurfaceDrawLineDeltaProc`, so the prior pending statement is no longer current. | `by-global/SurfaceRenderCallbackTable.md` -> Historical Assumptions | historicalize | applied |
| C18 | 0000TN | State the current catalog-name/applied-type/blank-item-head/Hex-Rays split and applied exact Gate 2B address comment. | Very strong | Saved item, catalog, type, Hex-Rays, comments, and 26-xref readbacks are exact. | `by-global/SurfaceRenderCallbackTable.md` -> current IDA type state | incorporate | applied |
| C19 | 0001PI | Preserve the 2026-07-24 pending-tinfo wording only as dated history. | Very strong | Current IDA now has applied `SurfaceDrawLineDeltaProc`, so the prior pending statement is no longer current. | `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` -> Historical Assumptions | historicalize | applied |
| C20 | 0001PI | State the current catalog-name/applied-type/blank-item-head/Hex-Rays split and applied exact Gate 2B address comment. | Very strong | Saved item, catalog, type, Hex-Rays, comments, and 26-xref readbacks are exact. | `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` -> current IDA type state | incorporate | applied |
| C21 | 0000TN | Gate 2B preserved the global catalog name/type and applied only address-regular comment `Runtime-installed GrafPort relative-line renderer: (port, deltaX, deltaY).`; the blank item-head, address-repeatable: absent, function-regular: absent, function-repeatable: absent, `MEMORY[0x69B3E4]`, 26 xrefs, and adjacent slots remain. | Very strong | Supervisor-applied literal readback and saved IDB state for `0x0069b3e4`. | IDA global `0x0069b3e4` -> Gate 2B mutation/readback | incorporate | applied |
| C22 | 0001DV | Document Pane/GrafPort primary view, inherited EventHandler `+0xa0`, inherited TimerHandler `+0xa4`, and compiler boundaries. | Very strong | Pane `0xf8` layout and exact `-0xa0/-0xa4` adjustor bodies. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> Subobject/Compiler Boundaries | incorporate | applied |
| C23 | 00003D | Document the Pane inheritance/layout and embedded EventHandler/TimerHandler views without inventing direct bases. | Very strong | Pane/class docs, exact object size, and adjustor offsets. | `by-class/CScrollBarBackPane.md` -> Inheritance/Layout | incorporate | applied |
| C24 | 0003LR | Document the three primary/EventHandler/TimerHandler vtable views. | Very strong | Exact decorated vtable names, cells, and adjustor references. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> Vtable Views | incorporate | applied |
| C25 | 0001E3 | Document the scalar deleting destructor's compiler-family relation to the ordinary destructor. | Very strong | Exact flags/delete path and three vptr restores. | `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md` -> Destructor Family | incorporate | applied |
| C26 | 00023J | Document both exact one-star adjusted receivers and compiler-thunk boundaries. | Very strong | Exact `-0xa0/-0xa4` bodies and four live applied analogous adjustors. | `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` -> CScrollBarBackPane thunk rows | incorporate | applied |
| C27 | 0004Y8 | Document the three class-view vptr stores as ABI lowering, not handwritten statements. | Very strong | Exact constructor bytes and vtable identities. | `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` -> ABI notes | incorporate | applied |
| C28 | 0004Y9 | Document the three class-view restores as ABI lowering around the empty source destructor. | Very strong | Exact destructor body and separate scalar/adjustor family. | `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` -> ABI notes | incorporate | applied |
| C29 | 0004YA | Document the primary Pane virtual-slot role and exclude compiler-family bodies from source emission. | Very strong | Exact vtable reference and closed OnPaint range. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> ABI notes | incorporate | applied |
| C30 | 00003D | Reroute the class owner/emitter to UID0000M7 OptionPane and state the corrected source placement. | Strong | Exclusive NewOptionPane fields/lifetime plus code/RTTI adjacency reject generic ScrollBar placement. | `by-class/CScrollBarBackPane.md` -> metadata/Status/source placement | incorporate | applied |
| C31 | 0000M7 | Add CScrollBarBackPane, its three source children, scalar evidence, and vtable evidence to OptionPane contents/ranges. | Strong | Two inline constructions, paired layout/destruction, and code/RTTI adjacency. | `by-file/OptionPane.md` -> contents/ranges | incorporate | applied |
| C32 | 0001E3 | Route the compiler scalar-wrapper evidence to OptionPane.cpp without emitting handwritten wrapper source. | Strong | Class ownership and source adjacency establish the file route. | `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md` -> source placement | incorporate | applied |
| C33 | 0003LR | Route the compiler vtable evidence to OptionPane.cpp without handwritten table source. | Strong | Class ownership and RTTI adjacency establish the file route. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> source placement | incorporate | applied |
| C34 | 0004Y8 | Route the constructor definition to OptionPane.cpp through owner UID00003D/emitter UID0000M7. | Strong | Exclusive NewOptionPane ownership and code adjacency. | `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` -> source placement | incorporate | applied |
| C35 | 0004Y9 | Route the ordinary destructor definition to OptionPane.cpp through owner UID00003D/emitter UID0000M7. | Strong | Class lifetime and code adjacency. | `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` -> source placement | incorporate | applied |
| C36 | 0004YA | Route the OnPaint definition to OptionPane.cpp through owner UID00003D/emitter UID0000M7. | Strong | Exclusive NewOptionPane consumer and code adjacency. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> source placement | incorporate | applied |
| C37 | 0000NF | Preserve former ScrollBar.cpp placement only as rejected history. | Strong | Name similarity was the old basis; exclusive NewOptionPane ownership disproves it. | `by-file/ScrollBar.md` -> rejected source-placement history | historicalize | applied |
| C38 | 0001R1 | Preserve the 2026-06-01 ScrollBar route only as rejected history and add the exact OptionPane correction text supplied below. | Strong | Current ownership, layout, lifetime, and source adjacency disprove the old route. | `by-project-structure/proposed-source-tree.md` -> historical route correction | historicalize | applied |
| C39 | 0001E3 | Preserve the scalar deleting wrapper as compiler ABI evidence with no handwritten source body. | Very strong | Flags/delete path and ordinary-destructor relation. | `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md` -> compiler-wrapper disposition | incorporate | applied |
| C40 | 00023J | Preserve the EventHandler adjustor as compiler ABI evidence with no handwritten source body. | Very strong | Exact `this-0xa0` forwarding body and vtable reference. | `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` -> EventHandler thunk row | incorporate | applied |
| C41 | 00023J | Preserve the TimerHandler adjustor as compiler ABI evidence with no handwritten source body. | Very strong | Exact `this-0xa4` forwarding body and vtable reference. | `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` -> TimerHandler thunk row | incorporate | applied |
| C42 | 0003LR | Preserve the three vtable tables as compiler ABI data with no handwritten table source. | Very strong | Decorated names, exact cells, and RTTI/vtable topology. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> compiler-data disposition | incorporate | applied |
| C43 | 00003D | Exclude scalar wrappers, adjustor thunks, and vtable tables from the human class source body. | Very strong | Compiler-family evidence distinguishes source methods from ABI products. | `by-class/CScrollBarBackPane.md` -> compiler exclusions | incorporate | applied |
| C44 | 0001DV | Exclude scalar wrappers, adjustor thunks, and vtable tables from aggregate source emission. | Very strong | Exact split and compiler-family evidence. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> compiler exclusions | incorporate | applied |
| C45 | 0001E3 | Apply the complete scalar-deleting-destructor declaration/comment at Gate 2B. | Very strong | Literal item/Hex-Rays/frame prestate and supervisor-verified saved readback below. | IDA function `0x00542680` -> Gate 2B mutation/readback | incorporate | applied |
| C46 | 00023J | Apply the complete EventHandler one-star adjustor declaration/comment and clear stale address comment `Block`. | Very strong | Literal item/Hex-Rays/frame prestate and supervisor-verified one-star saved readback. | IDA function `0x0054259f` -> Gate 2B mutation/readback | incorporate | applied |
| C47 | 00023J | Apply the complete TimerHandler one-star adjustor declaration/comment and clear stale address comment `Block`. | Very strong | Literal item/Hex-Rays/frame prestate and supervisor-verified one-star saved readback. | IDA function `0x005425aa` -> Gate 2B mutation/readback | incorporate | applied |
| C48 | 00003D | Insert the exact class H declaration and `[[CHILDREN]]` CPP route. | Strong | RTTI name, Pane inheritance, size `0xf8`, and three source-island methods. | `by-class/CScrollBarBackPane.md` -> H/CPP | incorporate | applied |
| C49 | 0004Y8 | Insert the exact constructor CPP and blank H with class-declaration-owner proof. | Strong | Exact constructor source reconstruction and formal-channel rules. | `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` -> CPP/H | incorporate | applied |
| C50 | 0004Y9 | Insert the exact ordinary-destructor CPP and blank H with class-declaration-owner proof. | Strong | Exact destructor source reconstruction and formal-channel rules. | `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` -> CPP/H | incorporate | applied |
| C51 | 0004YA | Insert the exact OnPaint CPP and blank H with class-declaration-owner proof. | Very strong | Exact geometry/call sequence and formal-channel rules. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> CPP/H | incorporate | applied |
| C52 | 0000VN | Insert the literal internal padding block for `[0x53fed2,0x53fee0)` and `[0x53feff,0x53ff00)`. | Very strong | Fourteen and one exact `0xcc` bytes are alignment only. | `by-memory/-ignored.md` -> exact insertion after grouped scroll-alignment entry | incorporate | applied |
| C53 | 0000VN | Keep the existing external predecessor/successor padding entry unchanged. | Very strong | Existing `[0x53fe9b,0x53fea0)` and `[0x53ff8d,0x53ff90)` spans remain correct. | `by-memory/-ignored.md` -> existing grouped option/macro/social/profile/scroll entry | already-present | already-present |
| C54 | 0001DV | Add the two internal padding spans and three child routes to Functions/Split. | Very strong | Exact item boundaries partition the complete `0xed` aggregate. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> Functions/Split | incorporate | applied |
| C55 | 0000VL | Add the exact supervisor-owned nested coverage rows for the three children and two internal padding spans. | Very strong | Exact boundaries and assigned UID0004Y8/UID0004Y9/UID0004YA reconciliation procedure. | `by-memory/-coverage-report.md` -> CScrollBarBackPane nested rows | incorporate | blocked |
| C56 | 0004Y8 | Create, fully populate, and serially register the constructor page as UID0004Y8. | Very strong | Exact path received validator-assigned UID0004Y8 under command 18823. | `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` -> creation/UID registration | incorporate | applied |
| C57 | 0004Y9 | Create, fully populate, and serially register the ordinary-destructor page as UID0004Y9. | Very strong | Exact path received validator-assigned UID0004Y9 under command 18824. | `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` -> creation/UID registration | incorporate | applied |
| C58 | 0004YA | Create, fully populate, and serially register the OnPaint page as UID0004YA. | Very strong | Exact path received validator-assigned UID0004YA under command 18825. | `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` -> creation/UID registration | incorporate | applied |
| C59 | 0001DV | Use exact assigned UID links for all three children after serial registration/reference processing. | Very strong | Validator assignment/reference phases produced UID0004Y8, UID0004Y9, and UID0004YA. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> Functions | incorporate | applied |
| C60 | 0000VN | Use exact assigned UID links for all three owner children after registration/reference processing. | Very strong | Literal insertion now uses UID0004Y8, UID0004Y9, and UID0004YA. | `by-memory/-ignored.md` -> inserted internal-padding block | incorporate | applied |
| C61 | 0000VL | Supply exact assigned UID links for all three child coverage rows before the supervisor applies them. | Very strong | Exact manual payload below uses assigned UIDs. | `by-memory/-coverage-report.md` -> proposed nested rows | incorporate | blocked |
| C62 | 0001DV | Record assigned UIDs in this report and prove zero temporary UID tokens before final Gate 2A. | Very strong | Report inventory, ledger, checklist, and manual payload use assigned UIDs. | This report -> inventory/ledger/checklist/manual payload | incorporate | applied |
| C63 | 0001DV | Preserve raw `sub_*`, cleanup-helper, and generic DrawPattern assumptions only as superseded history with disproof. | Strong | Current identities, exact split, and formal source invalidate those assumptions. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> Historical Assumptions | historicalize | applied |
| C64 | 00003D | Preserve prior generic ScrollBar/source-shape assumptions only as superseded history. | Strong | Exclusive NewOptionPane ownership and exact class reconstruction disprove them. | `by-class/CScrollBarBackPane.md` -> Historical Assumptions | historicalize | applied |
| C65 | 0001E3 | Preserve the cleanup-helper interpretation only as superseded history. | Very strong | Flags/delete path proves scalar deleting destructor ABI glue. | `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md` -> Historical Assumptions | historicalize | applied |
| C66 | 00023J | Preserve raw adjustor labels and double-pointer receiver assumptions only as superseded history. | Very strong | Exact subtract/forward bodies and one-star analogs disprove them. | `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` -> Historical Assumptions | historicalize | applied |
| C67 | 0003LR | Preserve any handwritten-vtable interpretation only as superseded history. | Very strong | Decorated tables and ABI topology prove compiler-generated data. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> Historical Assumptions | historicalize | applied |
| C68 | 0000TN | Preserve `dword_69B3E4` and pending-tinfo wording only as superseded history. | Very strong | Current catalog/type/item/Hex-Rays split is exact. | `by-global/SurfaceRenderCallbackTable.md` -> Historical Assumptions | historicalize | applied |
| C69 | 0001PI | Preserve `dword_69B3E4` and pending-tinfo wording only as superseded history. | Very strong | Current catalog/type/item/Hex-Rays split is exact. | `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` -> Historical Assumptions | historicalize | applied |
| C70 | 0000NF | Preserve the ScrollBar.cpp ownership assumption only as rejected history. | Strong | Exclusive NewOptionPane ownership and source adjacency disprove it. | `by-file/ScrollBar.md` -> Historical Assumptions | historicalize | applied |
| C71 | 0001DV | Reject `GrafPort::LineTo` substitution. | Very strong | Exact callee is `GrafPort::MoveTo` followed by the relative-line callback. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> rejected alternatives | reject-invalid | applied |
| C72 | 0001DV | Reject aggregate source emission. | Very strong | Exact range partition proves three methods and two pads. | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` -> CPP/H constraints | reject-invalid | applied |
| C73 | 00003D | Reject direct EventHandler/TimerHandler bases. | Very strong | Pane owns the embedded handler views at `+0xa0/+0xa4`. | `by-class/CScrollBarBackPane.md` -> inheritance constraints | reject-invalid | applied |
| C74 | 0001E3 | Reject handwritten scalar deleting destructor source. | Very strong | Flags/delete path identifies compiler ABI glue. | `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md` -> source constraints | reject-invalid | applied |
| C75 | 00023J | Reject handwritten adjustor-thunk source. | Very strong | Both bodies only adjust `this` and tail-forward. | `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` -> source constraints | reject-invalid | applied |
| C76 | 00023J | Reject `EventHandler **` and `TimerHandler **` receiver declarations. | Very strong | Four live analogous declarations and target lowering support one-star receivers. | `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` -> receiver-type constraints | reject-invalid | applied |
| C77 | 0003LR | Reject handwritten vtable table source. | Very strong | Decorated vtable data is compiler generated. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> source constraints | reject-invalid | applied |
| C78 | 0001DV | Reject guessed child UIDs; preserve the completed validator-assigned reconciliation to UID0004Y8, UID0004Y9, and UID0004YA. | Very strong | Validator temporary-reference rules provided the legal deterministic workflow. | This report -> final/checklist/UID reconciliation constraints | reject-invalid | applied |
| C79 | 000162 | Keep `GrafPort_MoveTo` unchanged in Gate 2B. | Very strong | Supervisor verified the protected name, declaration, comments, range, and caller state unchanged. | IDA function `0x004b9600` -> protected no-change readback | already-present | already-present |
| C80 | 0003LR | Record decorated primary vtable name `??_7CScrollBarBackPane@@6B@` as protected non-actionable current evidence; no Gate 2B mutation or action-table readback is requested. | Very strong | Current exact decorated name, primary group `[0x00621018,0x00621064)`, base `0x0062101c`, and vtable topology are already documented and correct. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> protected compiler identity; this report -> non-actionable dependency evidence | already-present | already-present |
| C81 | 0003LR | Record decorated EventHandler-view vtable name `??_7CScrollBarBackPane@@6B@_0` as protected non-actionable current evidence; no Gate 2B mutation or action-table readback is requested. | Very strong | Current exact decorated name, EventHandler group `[0x00621064,0x00621094)`, base `0x00621068`, and `-0xa0` adjustor topology are already documented and correct. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> protected compiler identity; this report -> non-actionable dependency evidence | already-present | already-present |
| C82 | 0003LR | Record decorated TimerHandler-view vtable name `??_7CScrollBarBackPane@@6B@_1` as protected non-actionable current evidence; no Gate 2B mutation or action-table readback is requested. | Very strong | Current exact decorated name, TimerHandler group `[0x00621094,0x006210a0)`, base `0x00621098`, and `-0xa4` adjustor topology are already documented and correct. | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` -> protected compiler identity; this report -> non-actionable dependency evidence | already-present | already-present |
| C83 | 0001DU | Keep protected predecessor `ProfileDialog_RefreshProfileData` unchanged. | Very strong | Supervisor verified name, declaration, comments, exact range, and boundary state unchanged. | IDA function `0x0053fe90` -> protected no-change readback | already-present | already-present |
| C84 | 0001DW | Keep protected successor `sub_53FF90` unchanged in this target pass. | Very strong | Supervisor verified declaration, absent comments, exact range, and constructor-shaped body unchanged. | IDA function `0x0053ff90` -> protected no-change readback | already-present | already-present |
| C85 | 00003D | Gate 2B declared only the minimal incomplete IDA type `struct CScrollBarBackPane;`, with no invented size, layout, fields, bases, vtables, or handler alias. | Very strong | Saved readback contains one incomplete type at ordinal 942 with no size or members. | IDA type catalog `CScrollBarBackPane` -> Gate 2B declaration/readback | incorporate | applied |
| C86 | 0004Y8 | Gate 2B created exactly `[0x0053fea0,0x0053fed2)` as `CScrollBarBackPane__Constructor`, applied the class-pointer declaration and exact function comment, and preserved bytes/items/padding. The constructor decompile has a bounded positive-SP artifact, while disassembly proves `Pane(true)`. | Very strong | Complete sixteen-item partition, exact 50 bytes, saved function/frame readback, literal `push 1`, and recorded Hex-Rays warning. | IDA function creation at `0x0053fea0` -> Gate 2B mutation/readback | incorporate | applied |
| C87 | 0004Y9 | Gate 2B renamed/typed/commented `[0x0053fee0,0x0053feff)` exactly as `CScrollBarBackPane__Destructor(CScrollBarBackPane *this)` and preserved its return-address frame, view restores, Pane teardown, bytes, and postpad. | Very strong | Supervisor-verified saved function/frame/body readback below. | IDA function `0x0053fee0` -> Gate 2B mutation/readback | incorporate | applied |
| C88 | 0004YA | Gate 2B renamed/typed/commented `[0x0053ff00,0x0053ff8d)` exactly as `CScrollBarBackPane__OnPaint(CScrollBarBackPane *this)`, preserving every instruction comment, frame, call pair, xref, byte, and endpoint. | Very strong | Supervisor-verified saved function/frame/comment/body readback below. | IDA function `0x0053ff00` -> Gate 2B mutation/readback | incorporate | applied |
| C89 | 0001DV | Replace the existing supervisor-owned by-memory coverage row with the exact `92%` non-reconstructable class-owned split-index payload below. | Very strong | Current manual row is stale; exact target metadata, three assigned child routes, two padding spans, and non-emitting disposition are implemented and validated. | `by-memory/-coverage-report.md` -> existing UID0001DV row | incorporate | blocked |
| C90 | 0001E3 | Replace the existing supervisor-owned by-memory coverage row with the exact `90%` compiler scalar-deleting-destructor payload below. | Very strong | Current manual row is stale; exact scalar-wrapper/ordinary-destructor/adjustor relationship and OptionPane route are implemented and validated. | `by-memory/-coverage-report.md` -> existing UID0001E3 row | incorporate | blocked |
| C91 | 00023J | Replace the existing supervisor-owned generic `80%` by-memory coverage row with the exact `86%` adjustor-island payload below. | Very strong | Current manual row omits the two exact one-star CScrollBarBackPane adjustors, flags types, forwarding deltas, target, routes, and deterministic stale-comment clears. | `by-memory/-coverage-report.md` -> existing UID00023J row | incorporate | blocked |
| C92 | 00003D | Replace the existing supervisor-owned class coverage row with the exact `92%` OptionPane-local CScrollBarBackPane payload below. | Very strong | Current class row is stale relative to the complete H declaration, three exact source children, resolved geometry/contracts, inherited facets, and compiler exclusions. | `by-class/-coverage-report.md` -> existing UID00003D row | incorporate | blocked |
| C93 | 000097 | Replace the existing supervisor-owned generic `84%` class coverage row with the exact `87%` NewOptionPane support payload below. | Strong | Current class row omits the two owned CScrollBarBackPane fields, inline construction, paired bounds, rendering role, shared lifetime, and OptionPane route. | `by-class/-coverage-report.md` -> existing UID000097 row | incorporate | blocked |
| C94 | 0000M7 | Replace the existing supervisor-owned file coverage row with the exact `93%` OptionPane source-family payload below. | Very strong | Current file row is stale relative to the implemented CScrollBarBackPane source children, NewOptionPane ownership/layout/lifetime evidence, resolved contracts, and compiler boundaries. | `by-file/-coverage-report.md` -> existing UID0000M7 row | incorporate | blocked |
| C95 | 0000NF | Replace the existing supervisor-owned file coverage row with the exact `91%` ScrollBar payload below that rejects current CScrollBarBackPane placement. | Very strong | Current file row is stale; exclusive NewOptionPane ownership and OptionPane route disprove the former name-similarity placement while preserving generic ScrollBar coverage. | `by-file/-coverage-report.md` -> existing UID0000NF row | incorporate | blocked |
| C96 | 0001DW | Replace the existing supervisor-owned generic `78%` by-memory coverage row with the exact `87%` NewOptionPane aggregate payload below. | Strong | Current row omits the two backplate fields, inline construction, paired placement, rendering support, common deletion lifetime, and exact-child ownership. | `by-memory/-coverage-report.md` -> existing UID0001DW row | incorporate | blocked |
| C97 | 0003LR | Insert the exact supervisor-owned `90%` CScrollBarBackPane vtable-data row as an eight-space-indented child of UID000261 immediately before UID0003C9. | Very strong | UID0003LR is absent from current manual by-memory coverage; exact primary/EventHandler/TimerHandler groups, routes, boundaries, OptionPane placement, and compiler-only policy are implemented and validated. | `by-memory/-coverage-report.md` -> UID000261 child block immediately before UID0003C9 | incorporate | blocked |

## Positive Evidence Summary

- Constructor bytes are complete and match two inline NewOptionPane constructions byte-for-semantics.
- OnPaint has an exact primary vtable route and exact inherited slot identity.
- Class RTTI name is present and three vtable groups encode the Pane/EventHandler/TimerHandler layout.
- NewOptionPane owns two 0xf8 instances, lays them out as 120x5 backgrounds beside its two volume-slider panes, and deletes them with those panes.
- Helper/global identities are already source-quality in current IDA and current support docs.
- Exact neighboring padding prevents hidden/fallthrough ambiguity.
- Live CollectionPane2 and SliderControlPane `-0xa0/-0xa4` adjustors establish the safe current IDA convention: `EventHandler *this` and `TimerHandler *this`, not an added `EventHandler **` layer.
- The strongest chain is: exact class RTTI/vtable -> exact source method island -> two NewOptionPane inline constructions and member fields -> exact layout beside volume panes -> exact minus/groove/plus paint. This is sufficient for OptionPane placement and formal source.

## IDA MCP Facts

- Gate 1 prestate had no function object/frame/decompilation at `[0x0053fea0,0x0053fed2)`; Gate 2B now models exact `CScrollBarBackPane__Constructor` over all 50 bytes while preserving the sixteen code items and `ret` at `0x0053fed1`. Predecessor `[0x0053fe9b,0x0053fea0)` remains five-byte padding.
- Gate 1 prestate `sub_53FEE0` / `void __thiscall(Pane *this)` is now exact `CScrollBarBackPane__Destructor` / `void __thiscall(CScrollBarBackPane *this)`, size `0x1f`, with the same three vptr stores, Pane destructor tail chain, and no inbound xref/pointer route.
- Gate 1 prestate `sub_53FF00` / `void __thiscall(GrafPort *this)` is now exact `CScrollBarBackPane__OnPaint` / `void __thiscall(CScrollBarBackPane *this)`, size `0x8d`, with the same one data xref from `0x00621060`, no direct callers, and six call pairs.
- Exact internal/post padding: `[0x53fed2,0x53fee0)` 14 bytes; `[0x53feff,0x53ff00)` 1 byte; `[0x53ff8d,0x53ff90)` 3 bytes.
- Primary table `[0x62101c,0x621064)` ends at `+0x44` cell `0x621060 -> 0x53ff00`. Secondary EventHandler base is `0x621068`; tertiary TimerHandler base is `0x621098`, with inherited `Pane_OnTimer` at `0x62109c`.
- `0x53fea0` and `0x53fee0` have no VA/RVA pointer hits. `0x53ff00` has exactly the vtable VA hit.
- `CScrollBarBackPane` now exists once as minimal incomplete ordinal 942 with no size or members; `Pane` remains size 248, `GrafPort` size 160, and `SurfaceDrawLineDeltaProc` size 4.
- `0x0054259f` and `0x005425aa` now read back with the accepted `CScrollBarBackPane *` returns, exactly one-star `EventHandler *this` / `TimerHandler *this` receivers, and `unsigned int flags`. Their bodies still subtract `0xa0` and `0xa4` before forwarding to exact scalar target `0x00542680`.
- Standalone `type_inspect` reports `EventHandler` as a four-byte pointer-form result and `TimerHandler` as a four-byte UDT, while the current EventHandler source declaration is a class. The operational function-type evidence resolves the ambiguity: four already-applied analogous adjustors decompile and read back with exactly one visible `EventHandler *` / `TimerHandler *` receiver and no extra pointer layer.
- `0x0069b3e4` is named `g_pfnDrawLineDelta` in the names/global catalogs and has applied type `SurfaceDrawLineDeltaProc`; its containing one-byte item reports a blank item-head name, and current Hex-Rays renders the six calls as `MEMORY[0x69B3E4]`. Static image value is zero because runtime initialization installs its implementation. These distinct current views are preserved literally rather than collapsed into a false claim that Hex-Rays already renders the source-facing name.
- Proposed source-quality function names have zero current name collisions.
- Protected boundary declarations remain `void __cdecl ProfileDialog_RefreshProfileData()` at `[0x0053fe90,0x0053fe9b)` and `_DWORD *__thiscall sub_53FF90(_DWORD *this)` at `[0x0053ff90,0x00540194)`; Gate 2B verified both unchanged.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x53fea0,0x53ff8d)` | UID0001DV target | Mixed split index | No after split | UID00003D | 92/94 applied | Converted and validated by command 18830 |
| `[0x53fea0,0x53fed2)` | UID0004Y8 | Source constructor | Yes | UID00003D | 93/94 applied | Created, registered, and revalidated |
| `[0x53fed2,0x53fee0)` | UID0000VN by-memory/-ignored | 14-byte alignment | No | UID0001DV context | 100/strong | Exact ignored entry applied |
| `[0x53fee0,0x53feff)` | UID0004Y9 | Source empty destructor | Yes | UID00003D | 92/94 applied | Created, registered, and revalidated |
| `[0x53feff,0x53ff00)` | UID0000VN by-memory/-ignored | 1-byte alignment | No | UID0001DV context | 100/strong | Exact ignored entry applied |
| `[0x53ff00,0x53ff8d)` | UID0004YA | Source virtual paint | Yes | UID00003D | 94/94 applied | Created, registered, and revalidated |
| `[0x54259f,0x5425aa)` | UID00023J subrange | EventHandler adjustor | No handwritten source | Compiler through UID00003D | Existing | Preserve compiler disposition |
| `[0x5425aa,0x5425b5)` | UID00023J subrange | TimerHandler adjustor | No handwritten source | Compiler through UID00003D | Existing | Preserve compiler disposition |
| `[0x542680,0x5426d5)` | UID0001E3 | Scalar deleting destructor | Comment-only compiler evidence | UID00003D | 90/94 applied | Marker preserved; route updated |
| `[0x621018,0x6210a0)` | UID0003LR | RTTI/vtable data | Comment-only compiler evidence | UID00003D | 90/94 applied | Marker preserved; route updated |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x53fea0` | No inbound xrefs; no VA/RVA pointer hits | Retained out-of-line constructor with inlined live uses, not directly called |
| `0x53feb1/0x53feb9/0x53fec3` | Stores `0x62101c/0x621068/0x621098` | Primary/EventHandler/TimerHandler class views |
| `0x53fee0` | No inbound xrefs; no VA/RVA pointer hits | Retained ordinary destructor body; virtual deletion uses scalar wrapper |
| `0x53fefa -> 0x544580` | Pane ordinary destructor | Base teardown only |
| `0x621060 -> 0x53ff00` | Primary vtable `+0x44` | Exact OnPaint identity |
| `0x53ff07`, `0x53ff1e`, `0x53ff35`, `0x53ff4c`, `0x53ff63`, `0x53ff7a` -> `0x4b9600` | Six MoveTo calls | Exact local cursor starts |
| `0x53ff12`, `0x53ff29`, `0x53ff40`, `0x53ff57`, `0x53ff6e`, `0x53ff85` -> `0x69b3e4` | Six typed callback calls | Exact line deltas |
| `0x5400fc/102/10c` and `0x540147/14d/157` | Two inline class-vptr triplets | Two live NewOptionPane-owned instances |
| `0x54031c` and `0x540384` | SetBounds through fields `+0x12cc/+0x12d0` | Two 120x5 volume-slider backgrounds |
| `0x540207` and `0x540216` | Pane_MarkForDeletion for `+0x12cc/+0x12d0` | NewOptionPane owns their lifetime |
| `0x62101c -> 0x542680` | Primary scalar deleting entry | Compiler virtual deletion route |
| `0x621068 -> 0x54259f` | Secondary adjusted scalar entry | EventHandler `this-0xa0` ABI glue |
| `0x621098 -> 0x5425aa` | Tertiary adjusted scalar entry | TimerHandler `this-0xa4` ABI glue |

## Documentation Evidence And IDA Status

- Current ordinary target/class/support docs now establish class identity, exact split bounds, vtable ownership, Pane constructor/destructor dependencies, scalar-wrapper policy, human helper/global identities, fixed-line geometry, inherited `+0xa0/+0xa4` roles, OptionPane source placement, and formal class/method source.
- Historical assignment-time defects were unresolved helper/global names, generic cleanup/DrawPattern wording, generic handler roles, ScrollBar placement, aggregate source emission, and blank class H. Each is now either corrected in ordinary docs or retained only in an explicitly superseded/rejected-history section.
- Generated commands `18740`, `18808`, and `18812` remain dated pre-callback checkpoints only. Every callback validator used `--no-generated-refresh`, so final generated OptionPane CPP/H emission and ScrollBar route removal await the supervisor lifecycle-time refresh/readback.
- Manual coverage rows remain supervisor-owned and stale: UID0001DV says 76%, UID0001E3 says 74%, UID00003D says 78%, UID0000M7 says 91%, and UID0000NF says 90%; the exact replacement/insertion payloads below remain unapplied.
- Gate 1 raw `sub_*` identities and stale comment channels below are assignment-time prestates. Current saved IDA contains every accepted target/compiler identity, prototype, and function comment; both stale `Block` address comments are absent; the callback address comment is exact; protected `GrafPort_MoveTo`, predecessor/successor, vtables, ranges, bytes, padding, and adjacent callback slots remain unchanged.

## Ranked Ownership Analysis

### 1. OptionPane / NewOptionPane volume controls

- Evidence for: code and RTTI adjacency; two exact inline constructions in NewOptionPane; 0xf8 allocations; fields `+0x12cc/+0x12d0`; bounds set beside `ScrollVolumePane` fields; common destruction; fixed minus/groove/plus geometry; no other live object route.
- Evidence against: no embedded source filename string and no direct call to the retained out-of-line constructor.
- Decision: accepted with strong confidence. Inlining explains the missing constructor call, and independent field/layout/lifetime evidence resolves the source family.

### 2. Generic ScrollBar.cpp

- Evidence for: class name contains ScrollBar and visual behavior is scrollbar-like.
- Evidence against: generic ScrollBar classes live in distant function/vtable families, no generic caller/data route reaches this class, and the only live instances are NewOptionPane volume controls.
- Decision: rejected. Name/theme similarity is weaker than exact ownership and source-order evidence.

### 3. Standalone CScrollBarBackPane.cpp or ScrollVolumePane.cpp

- Evidence for: exact RTTI class name could permit a standalone source; behavior is paired with ScrollVolumePane.
- Evidence against: methods/vtable are adjacent to NewOptionPane, not ScrollVolumePane; only NewOptionPane constructs/positions/destroys instances; no other TU consumer exists.
- Decision: rejected as unnecessarily broad. A local supporting class in OptionPane is the most plausible original grouping.

### Proposed new file/grouping, if applicable

- No new by-file root is warranted. Route the class into existing [UID:0000M7] `NexusTK/ui/dialogs/OptionPane.cpp` and its header channel.
- Likely full relevant grouping: existing OptionPane/NewOptionPane classes and helpers plus CScrollBarBackPane declaration, constructor, empty destructor, OnPaint, compiler-derived scalar/adjustor/vtable evidence, and the two NewOptionPane member pointers.
- Rejected from this grouping: generic ScrollPane/ScrollWidget/ScrollablePane methods and constants; ScrollVolumePane implementation remains its own source module even though NewOptionPane owns instances.

## Source Placement

- Recommended placement: [UID:00003D] declaration in `NexusTK/ui/dialogs/OptionPane.h`; exact method children in `NexusTK/ui/dialogs/OptionPane.cpp`; compiler wrapper/vtables regenerate from that declaration.
- Why: all live construction/layout/lifetime behavior belongs to NewOptionPane, and code/RTTI order places CScrollBarBackPane immediately before NewOptionPane.
- Adjustor receiver declarations are physical IDA ABI annotations only. The one-star EventHandler/TimerHandler receiver resolution does not add direct bases, fields, typedefs, or handwritten thunk source to OptionPane.h/OptionPane.cpp.
- NewOptionPane field names inferred for support documentation: `m_musicVolumeScrollPane` `+0x12c4`, `m_soundVolumeScrollPane` `+0x12c8`, `m_musicVolumeBackPane` `+0x12cc`, and `m_soundVolumeBackPane` `+0x12d0`. Constructor kind `1` versus `0` and OnVolumeChanged behavior support music then sound order.
- Rejected: `NexusTK/ui/core/ScrollBar.cpp`, a standalone source file, and `ScrollVolumePane.cpp` for the reasons in the ranked analysis.
- Remaining placement uncertainty: none requiring deferral. Exact original header-vs-file-local declaration location is not binary-provable, but the project H channel is the consistent reconstruction choice and preserves runtime behavior.

## Range / Split / Padding / Reclassification Analysis

- Exact parent range length: `0xed` / 237 bytes.
- Constructor child: `[0x0053fea0,0x0053fed2)`, `0x32` / 50 bytes, exclusive `ret` at `0x0053fed1`.
- Internal padding 1: `[0x0053fed2,0x0053fee0)`, `0x0e` / 14 `0xcc` bytes.
- Ordinary destructor child: `[0x0053fee0,0x0053feff)`, `0x1f` / 31 bytes.
- Internal padding 2: `[0x0053feff,0x0053ff00)`, one `0xcc` byte.
- OnPaint child: `[0x0053ff00,0x0053ff8d)`, `0x8d` / 141 bytes, exclusive `ret` at `0x0053ff8c`.
- Predecessor: ProfileDialog refresh ends `0x0053fe9b`, then `[0x0053fe9b,0x0053fea0)` is five-byte alignment.
- Successor: `[0x0053ff8d,0x0053ff90)` is three-byte alignment; NewOptionPane constructor begins exactly `0x0053ff90`.
- Parent impact: [UID:0001DV] remains as a semantic index with `Nested:3`, owner [UID:00003D], false reconstructable, blank emitter/formals. Exact children alone emit.
- No merge with predecessor, successor, scalar-wrapper island, or vtable data is valid.

## Negative Evidence Summary

- No direct xrefs or encoded pointers reach constructor/destructor starts; this does not negate source because live uses are inlined and virtual deletion routes through the scalar wrapper.
- No source caller reaches OnPaint; its primary vtable cell is the expected virtual route.
- No generic ScrollBar class constructs, stores, lays out, or destroys CScrollBarBackPane.
- No `GrafPort::LineTo` call exists in the body. Formal source must preserve direct line-delta callback calls rather than replacing them with absolute LineTo calls.
- No evidence supports direct inheritance from EventHandler or TimerHandler; Pane already owns those facets.
- No evidence supports handwritten vptr stores, deleting flags, adjustor thunks, vtable arrays, or runtime guard calls.
- No current IDA name collision exists for any proposed CScrollBarBackPane function identity.
- No evidence supports `EventHandler **`, `TimerHandler **`, `void **`, or a new handler pointer typedef for either adjustor. Those would depart from current applied Pane-derived adjustor conventions without changing the machine body.
- No hidden code exists in the two internal padding spans or three-byte successor alignment.

## IDA Rename / Type / Comment Recommendations

Gate 2B action/readback table (supervisor-applied; B007 remained read-only):

| Entity | Action classification | Literal accepted IDA pre-state | Applied supervisor action | Verified current readback | Safety / negative constraints |
| --- | --- | --- | --- | --- | --- |
| Type declaration `CScrollBarBackPane` | apply | Type name absent; declaration absent; ordinal absent; layout/size absent; address-regular: absent; address-repeatable: absent; function-regular: absent; function-repeatable: absent; those four channels are not applicable to a type-catalog declaration. Exact-name collision query returned no `CScrollBarBackPane` type. | Declared only minimal incomplete type `struct CScrollBarBackPane;`. | Type catalog contains exactly one incomplete `CScrollBarBackPane`, ordinal 942, with no size or members; no address/function comment channel applies. | No Pane/GrafPort/EventHandler/TimerHandler inheritance, fields, vtables, size, or handler pointer alias was invented in IDA. |
| Raw constructor item `[0x0053fea0,0x0053fed2)`, size `0x32` | apply | Function object/name/declaration/frame/decompile absent; all bytes already code; address-regular/address-repeatable/function-regular/function-repeatable absent; zero inbound xrefs/pointers; no name collision. | Defined exact function, renamed `CScrollBarBackPane__Constructor`, applied `CScrollBarBackPane *__thiscall CScrollBarBackPane__Constructor(CScrollBarBackPane *this)`, and set function-regular comment `CScrollBarBackPane constructor; Pane(true) base construction followed by compiler-emitted primary/EventHandler/TimerHandler vptr installation.` | Exact `[0x0053fea0,0x0053fed2)`, 50 bytes, name/prototype/comment, address-regular/address-repeatable/function-repeatable absent, and exact `var_4`/saved-register/return-address frame. Hex-Rays warns `positive sp value has been detected, the output may be wrong!` and renders `Pane__Constructor((Pane *)this, savedregs)`; it does not literally show true. Disassembly `push 1` at `0x0053fea7` remains the exact evidence for `Pane(true)`. | Padding, bytes, and sixteen item partitions remain unchanged. The faulty decompiler argument is not promoted into source or used to reject the literal byte/disassembly fact. |
| Function `[0x0053fee0,0x0053feff)`, size `0x1f` | apply | Name `sub_53FEE0`; declaration `void __thiscall sub_53FEE0(Pane *this)`; all four entry/function comment channels absent; zero inbound xrefs/pointers; no name collision. | Renamed `CScrollBarBackPane__Destructor`; applied `void __thiscall CScrollBarBackPane__Destructor(CScrollBarBackPane *this)` and exact ordinary-destructor function comment. | Exact name/declaration; address-regular/address-repeatable/function-repeatable absent; exact function-regular comment; class-pointer receiver, one-member return-address frame, three vptr stores, Pane teardown, range, bytes, and postpad preserved. | It is not a cleanup helper or deleting wrapper; no boundary or byte changed. |
| Function `[0x0053ff00,0x0053ff8d)`, size `0x8d` | apply | Name `sub_53FF00`; declaration `void __thiscall sub_53FF00(GrafPort *this)`; entry/function comment channels absent; exact `x`/`y`/`this`/`deltaX`/`deltaY`/`port` instruction comments and absent repeatable channels inventoried; no name collision. | Renamed `CScrollBarBackPane__OnPaint`; applied `void __thiscall CScrollBarBackPane__OnPaint(CScrollBarBackPane *this)` and exact paint function comment; preserved every instruction comment. | Exact name/declaration/comment; entry address-regular/address-repeatable/function-repeatable absent; class-pointer receiver, one-member return-address frame, all instruction comments, six MoveTo/callback pairs, vtable xref, bytes, and endpoint preserved. | No generic DrawPattern rename, LineTo substitution, comment loss, or boundary change occurred. |
| Function `[0x00542680,0x005426d5)`, size `0x55` | apply | Name `sub_542680`; type `Pane *__thiscall(Pane *Block, char)`; Hex-Rays parameters `Block`/`a2`; entry/function comments absent; instruction comments `int` and `block`; no name collision. Historical pre-typing frame member at `+0xc` was `arg_0 : int`. | Renamed `CScrollBarBackPane__ScalarDeletingDestructor`; applied `CScrollBarBackPane *__thiscall CScrollBarBackPane__ScalarDeletingDestructor(CScrollBarBackPane *this, unsigned int flags)` and exact compiler-wrapper function comment. | Exact class-pointer/unsigned-flags declaration and comment; entry address-regular/address-repeatable/function-repeatable absent; current frame is `__saved_registers +0x4`, `__return_address +0x8`, and `flags +0xc : unsigned int`, all four bytes with absent member comments; instruction comments, vptr stores, Pane teardown, conditional delete/guard behavior, bytes, range, and refs preserved. | Compiler-only no-source disposition remains; no merge or byte/comment loss occurred. |
| Function `[0x0054259f,0x005425aa)`, size `0x0b` | apply | Name `sub_54259F`; declaration `Pane *__thiscall sub_54259F(_DWORD *this, char a2)`; address-regular: `Block`; address-repeatable: absent; function-regular: stale TargetOptionDialog sentence; function-repeatable: absent. Historical pre-typing frame exposed only `__return_address +0x0`. | Renamed `CScrollBarBackPane__ScalarDeletingDestructor__EventHandlerAdjustor`; applied `CScrollBarBackPane *__thiscall CScrollBarBackPane__ScalarDeletingDestructor__EventHandlerAdjustor(EventHandler *this, unsigned int flags)`; cleared address-regular `Block`; set function-regular comment `MSVC EventHandler-view deleting-destructor adjustor; subtracts 0xa0 and forwards to the CScrollBarBackPane scalar deleting destructor.` | Name and full declaration are exact with one receiver star; address-regular: absent; address-repeatable: absent; function-regular: exact accepted sentence; function-repeatable: absent; current frame is `__return_address +0x0` plus `flags +0x4 : unsigned int`, both four bytes with absent member comments; unchanged `this-0xa0` tail forward, range, bytes, and reference. | No double pointer, alias, handwritten source, TargetOptionDialog content, or unrelated thunk mutation. |
| Function `[0x005425aa,0x005425b5)`, size `0x0b` | apply | Name `sub_5425AA`; declaration `Pane *__thiscall sub_5425AA(_DWORD *this, char a2)`; address-regular: `Block`; address-repeatable: absent; function-regular: absent; function-repeatable: absent. Historical pre-typing frame exposed only `__return_address +0x0`. | Renamed `CScrollBarBackPane__ScalarDeletingDestructor__TimerHandlerAdjustor`; applied `CScrollBarBackPane *__thiscall CScrollBarBackPane__ScalarDeletingDestructor__TimerHandlerAdjustor(TimerHandler *this, unsigned int flags)`; cleared address-regular `Block`; set function-regular comment `MSVC TimerHandler-view deleting-destructor adjustor; subtracts 0xa4 and forwards to the CScrollBarBackPane scalar deleting destructor.` | Name and full declaration are exact with one receiver star; address-regular: absent; address-repeatable: absent; function-regular: exact accepted sentence; function-repeatable: absent; current frame is `__return_address +0x0` plus `flags +0x4 : unsigned int`, both four bytes with absent member comments; unchanged `this-0xa4` tail forward, range, bytes, and reference. | No double pointer, alias, handwritten source, or unrelated thunk mutation. |
| Function `[0x004b9600,0x004b9613)`, size `0x13` | already present | Name `GrafPort_MoveTo`; declaration `void __thiscall GrafPort_MoveTo(GrafPort *this, int x, int y)`; address-regular: absent; address-repeatable: absent; function-regular exactly `Source-facing GrafPort::MoveTo(int x, int y); updates the current drawing cursor.`; function-repeatable: absent. | Preserve the exact current state; perform no mutation. | Exact same name and declaration; address-regular: absent; address-repeatable: absent; function-regular exactly the current sentence; function-repeatable: absent; size, bytes, and broad caller set unchanged. | Do not rename, retype, rewrite either function-comment channel, or fold into target. |
| Global `0x0069b3e4` | apply | Item `[0x0069b3e4,0x0069b3e5)`, size 1, non-code/non-data unknown byte `00`; blank item-head; type `SurfaceDrawLineDeltaProc`; catalog name `g_pfnDrawLineDelta`; Hex-Rays `MEMORY[0x69B3E4]`; all comment channels absent; four-byte storage zero; 26 xrefs. | Preserved catalog name/type and applied only address-regular comment `Runtime-installed GrafPort relative-line renderer: (port, deltaX, deltaY).` | Same one-byte item, blank head, type/catalog, four zero bytes, `MEMORY[...]` possibility, 26 xrefs, and adjacent slots; address-regular is exact; address-repeatable/function-regular/function-repeatable absent; no reclassification. | No dword creation, resize, static target, adjacent-slot edit, forced Hex-Rays rename, or raw-name regression. |
| Protected predecessor function `[0x0053fe90,0x0053fe9b)`, size `0x0b` | already present | Name `ProfileDialog_RefreshProfileData`; applied item type and current Hex-Rays signature `void __cdecl ProfileDialog_RefreshProfileData()`; address-regular: absent; address-repeatable: absent; function-regular: absent; function-repeatable exactly `ProfileDialog.cpp retained refresh helper: loads g_activeMapPane and tail-forwards to MapPane::RefreshSelectedProfileData; no direct xref, pointer, immediate, or vtable route survives.` | Preserve the exact current state; perform no mutation. | Exact same name and declaration; address-regular: absent; address-repeatable: absent; function-regular: absent; function-repeatable exactly the current sentence; range, bytes, no-route result, and five-byte successor padding `[0x0053fe9b,0x0053fea0)` unchanged. | Do not rename/retype/recomment it, merge it with padding, or move the new constructor start below `0x0053fea0`. |
| Protected successor function `[0x0053ff90,0x00540194)`, size `0x204` | no change recommended | Name `sub_53FF90`; applied item type and current Hex-Rays signature `_DWORD *__thiscall sub_53FF90(_DWORD *this)`; address-regular: absent; address-repeatable: absent; function-regular: absent; function-repeatable: absent. | Preserve the exact current state; perform no mutation in this target pass. | Exact same name and declaration; address-regular: absent; address-repeatable: absent; function-regular: absent; function-repeatable: absent; range, bytes, and constructor-shaped body unchanged. | Do not rename/retype/recomment NewOptionPane here; preserve `[0x0053ff8d,0x0053ff90)` padding and keep OnPaint's exclusive end at `0x0053ff8d`. |

Constructor item-partition and prestate inventory for the exact exclusive creation range `[0x0053fea0,0x0053fed2)`:

| Item head | Item end | Size | Classification | Current name | Current type | Address regular | Address repeatable |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0053fea0` | `0x0053fea1` | `1` | code instruction | blank | blank | absent | absent |
| `0x0053fea1` | `0x0053fea3` | `2` | code instruction | blank | blank | absent | absent |
| `0x0053fea3` | `0x0053fea4` | `1` | code instruction | blank | blank | absent | absent |
| `0x0053fea4` | `0x0053fea5` | `1` | code instruction | blank | blank | absent | absent |
| `0x0053fea5` | `0x0053fea7` | `2` | code instruction | blank | blank | absent | absent |
| `0x0053fea7` | `0x0053fea9` | `2` | code instruction | blank | blank | absent | absent |
| `0x0053fea9` | `0x0053feac` | `3` | code instruction | blank | blank | absent | absent |
| `0x0053feac` | `0x0053feb1` | `5` | code instruction | blank | blank | absent | absent |
| `0x0053feb1` | `0x0053feb7` | `6` | code instruction | blank | blank | absent | absent |
| `0x0053feb7` | `0x0053feb9` | `2` | code instruction | blank | blank | absent | absent |
| `0x0053feb9` | `0x0053fec3` | `10` | code instruction | blank | blank | absent | absent |
| `0x0053fec3` | `0x0053fecd` | `10` | code instruction | blank | blank | absent | absent |
| `0x0053fecd` | `0x0053fece` | `1` | code instruction | blank | blank | absent | absent |
| `0x0053fece` | `0x0053fed0` | `2` | code instruction | blank | blank | absent | absent |
| `0x0053fed0` | `0x0053fed1` | `1` | code instruction | blank | blank | absent | absent |
| `0x0053fed1` | `0x0053fed2` | `1` | code instruction | blank | blank | absent | absent |

- Constructor accepted prestate: exact bytes are `55 8b ec 51 56 8b f1 6a 01 89 75 fc e8 af 45 00 00 c7 06 1c 10 62 00 8b c6 c7 86 a0 00 00 00 68 10 62 00 c7 86 a4 00 00 00 98 10 62 00 5e 8b e5 5d c3`. No function contained `0x0053fea0`; function name/declaration, frame, decompilation, Hex-Rays parameters/locals, and local-user comments were absent; address-regular/address-repeatable were absent on every item; function comments were absent; exact-name lookup returned `Not found`.
- Constructor applied readback: exact function `[0x0053fea0,0x0053fed2)`, size `0x32`, name `CScrollBarBackPane__Constructor`, declaration `CScrollBarBackPane *__thiscall CScrollBarBackPane__Constructor(CScrollBarBackPane *this)`, exact function-regular comment, and absent address-regular/address-repeatable/function-repeatable channels. Frame is exactly `var_4` `+0x4`/4/`_DWORD`, `__saved_registers` `+0x8`/4/`_DWORD`, and `__return_address` `+0xc`/4/`_UNKNOWN *`, with all member comments absent. All sixteen item partitions and 50 bytes remain unchanged.
- Constructor Hex-Rays discrepancy: the current decompiler warns `positive sp value has been detected, the output may be wrong!` and renders `Pane__Constructor((Pane *)this, savedregs)`. It does not provide a trustworthy literal argument or clean result/local model for this function. Disassembly at `0x0053fea7` is unambiguous `push 1` immediately before the Pane constructor call, so exact source semantics remain `Pane(true)`. The report does not hide the failed decompile normalization and does not substitute `savedregs` into human source.

Modeled-function first-item, Hex-Rays, frame, collision, and post-action inventory:

| Entity | Literal accepted prestate first item and Hex-Rays state | Accepted prestate frame | Name collision | Verified applied parameter/local/frame readback |
| --- | --- | --- | --- | --- |
| Ordinary destructor `[0x0053fee0,0x0053feff)` | First item `[0x0053fee0,0x0053fee6)`, size 6, name `sub_53FEE0`, type `void __thiscall(Pane *this)`; only parameter `this`; no locals/user comments. | `__return_address` `+0x0`, size 4, `_UNKNOWN *`, comment absent. | `CScrollBarBackPane__Destructor`: not found. | Current exact name/prototype/comment applied; parameter `this` is `CScrollBarBackPane *`, width four; no locals/user comments; same one-member frame and body. |
| OnPaint `[0x0053ff00,0x0053ff8d)` | First item `[0x0053ff00,0x0053ff01)`, size 1, name `sub_53FF00`, type `void __thiscall(GrafPort *this)`; only parameter `this`; no locals/user comments. | `__return_address` `+0x4`, size 4, `_UNKNOWN *`, comment absent. | `CScrollBarBackPane__OnPaint`: not found. | Current exact name/prototype/comment applied; parameter `this` is `CScrollBarBackPane *`, width four; no locals/user comments; same frame, instruction comments, and call sequence. |
| Scalar deleting destructor `[0x00542680,0x005426d5)` | First item `[0x00542680,0x00542681)`, size 1, name `sub_542680`, type `Pane *__thiscall(Pane *Block, char)`; parameters `Block`/`a2`; no locals/user comments. | Historical prestate: `__saved_registers +0x4`, `__return_address +0x8`, and `arg_0 +0xc : int`; all size 4 and comments absent. | Exact long name: not found. | Current exact name/prototype/comment applied; parameters `this : CScrollBarBackPane *` and `flags : unsigned int`, both width four; current frame is `__saved_registers +0x4`, `__return_address +0x8`, and `flags +0xc : unsigned int`, all size four with absent member comments; no locals/user comments; body state preserved. |
| EventHandler adjustor `[0x0054259f,0x005425aa)` | First item `[0x0054259f,0x005425a5)`, size 6, name `sub_54259F`, type `Pane *__thiscall(_DWORD *this, char)`; parameters `this`/`a2`; no locals/user comments. | Historical prestate: only `__return_address +0x0`, size 4, `_UNKNOWN *`, comment absent. | Exact long name: not found. | Current exact long name/prototype/comment applied; `this` is exactly one-star `EventHandler *`, `flags` is `unsigned int`, both width four; current frame is `__return_address +0x0` plus `flags +0x4 : unsigned int`, both size four with absent member comments; no locals/user comments; same tail body; `Block` absent. |
| TimerHandler adjustor `[0x005425aa,0x005425b5)` | First item `[0x005425aa,0x005425b0)`, size 6, name `sub_5425AA`, type `Pane *__thiscall(_DWORD *this, char)`; parameters `this`/`a2`; no locals/user comments. | Historical prestate: only `__return_address +0x0`, size 4, `_UNKNOWN *`, comment absent. | Exact long name: not found. | Current exact long name/prototype/comment applied; `this` is exactly one-star `TimerHandler *`, `flags` is `unsigned int`, both width four; current frame is `__return_address +0x0` plus `flags +0x4 : unsigned int`, both size four with absent member comments; no locals/user comments; same tail body; `Block` absent. |

- The applied `stack_frame` readback exposes no member-comment text for any listed frame member; each member-comment state remains absent. Current decompile readbacks expose the applied formal names/types above and no independent local declarations or local-user comments, except that the newly modeled constructor has the explicitly bounded positive-SP warning and unreliable `savedregs` call rendering recorded above. Instruction comments remain separate preserved evidence rather than parameter/local-user-comment substitutes.

- Non-actionable dependency evidence, deliberately outside the Gate 2B action table: `Pane` exists at size `0xf8`; `GrafPort` exists at size `0xa0`; `SurfaceDrawLineDeltaProc` exists at size four; `TimerHandler` is a four-byte UDT; standalone `type_inspect EventHandler` returns a four-byte pointer-form classification, while the project emits an EventHandler class contract. Current applied CollectionPane2 adjustors at `0x00573247/0x00573252` and SliderControlPane adjustors at `0x0049b003/0x0049b00e` prove the operational one-star `EventHandler *` / `TimerHandler *` spelling. These dependencies receive no declaration, rename, type, or comment mutation from this report.
- Non-actionable protected vtable evidence, deliberately outside the Gate 2B action table: primary group `[0x00621018,0x00621064)` has decorated base `??_7CScrollBarBackPane@@6B@` at `0x0062101c`; EventHandler group `[0x00621064,0x00621094)` has decorated base `??_7CScrollBarBackPane@@6B@_0` at `0x00621068`; TimerHandler group `[0x00621094,0x006210a0)` has decorated base `??_7CScrollBarBackPane@@6B@_1` at `0x00621098`. All three exact compiler identities and table topologies are already present in UID0003LR and receive no rename, type, comment, or Gate 2B readback action from this report.
- Deterministic comment closure is applied and saved: address-regular `Block` is absent at `0x54259f` and `0x5425aa`; both exact function-regular adjustor comments are present; the exact address-regular callback comment is present at `0x69b3e4`; address-repeatable remains absent on every listed entity/instruction; function-repeatable remains absent wherever listed; all unlisted channels remain untouched.

## First-Draft C++ Recommendation

- Eligible: yes. The split, ordinary formal insertion, and supervisor Gate 2B closure are applied; lifecycle-time generated verification remains pending but does not erase the installed first-draft source.
- UID0001DV parent CPP insertion: blank. Exact no-code proof: it becomes a non-emitting index over three child methods and padding; parent code would duplicate child source.
- UID0001DV parent H insertion: blank. It is a memory index, not a declaration owner.
- New constructor child CPP insertion:

```cpp
CScrollBarBackPane::CScrollBarBackPane()
    : Pane(true)
{
}
```

- New constructor child H insertion: blank; declaration belongs to [UID:00003D].
- New ordinary-destructor child CPP insertion:

```cpp
CScrollBarBackPane::~CScrollBarBackPane()
{
}
```

- New ordinary-destructor child H insertion: blank; declaration belongs to [UID:00003D].
- New OnPaint child CPP insertion:

```cpp
void CScrollBarBackPane::OnPaint()
{
    MoveTo(0, 2);
    g_pfnDrawLineDelta(this, 4, 0);

    MoveTo(7, 2);
    g_pfnDrawLineDelta(this, 87, 0);
    MoveTo(8, 1);
    g_pfnDrawLineDelta(this, 85, 0);
    MoveTo(8, 3);
    g_pfnDrawLineDelta(this, 85, 0);

    MoveTo(98, 2);
    g_pfnDrawLineDelta(this, 4, 0);
    MoveTo(100, 0);
    g_pfnDrawLineDelta(this, 0, 4);
}
```

- New OnPaint child H insertion: blank; declaration belongs to [UID:00003D].
- [UID:00003D] CPP insertion:

```cpp
[[CHILDREN]]
```

- [UID:00003D] H insertion:

```cpp
class CScrollBarBackPane : public Pane
{
public:
    CScrollBarBackPane();
    virtual ~CScrollBarBackPane();

    virtual void OnPaint();
};
```

- [UID:0001E3] remains comment-only compiler-wrapper proof and does not receive a handwritten body. [UID:0003LR] remains comment-only compiler-table proof.
- Exact behavior: source calls preserve every cursor coordinate and relative delta; constructor preserves `Pane(true)`; empty destructor delegates all runtime mechanics to the compiler/base.
- Human source shape: normal 2000s class declaration and method definitions, no `sub_*`, raw addresses, explicit vptr writes, deleting flags, adjustor code, or Hex-Rays locals.
- Naming style follows current project contracts: PascalCase class/method, `g_pfn` callback prefix, and inherited method calls without decompiler casts.
- Third-party import directive: not applicable; this is NexusTK product code.

## Final Recommendation

- Applied: UID0001DV is a false/non-emitting class-owned split index at `92/94`; UID0004Y8, UID0004Y9, and UID0004YA contain the exact constructor, ordinary destructor, and OnPaint formals; UID0000VN records the two ignored internal alignments.
- Applied: UID00003D now routes through UID0000M7 and contains its complete class H declaration plus child CPP route.
- Applied: UID0001E3 and UID0003LR source placement/history now preserve compiler-only emission; UID00023J remains `86/90` with exact CScrollBarBackPane adjustor subranges, one-star declarations, both stale `Block` comments cleared, and no-handwritten-source disposition.
- Applied: NewOptionPane docs contain the two back-pane member pointers, inline construction, layout, and lifetime evidence.
- Applied: generic ScrollBar no longer claims current CScrollBarBackPane ownership and preserves the old route only as rejected history.
- Applied under the explicit callback override: `by-project-structure/proposed-source-tree.md` preserves the former 2026-06-01 ScrollBar route as history and records the exact 2026-07-29 OptionPane correction.
- Fresh supervisor Gate 2A currentness readback supersedes only the earlier physical identities for three shared support files: `by-file/ScrollBar.md` is now SHA256 `F467456C8778B6FF17A47E411316C3A3D853824D7CF75A94A90D692C1457968A`, 46,082 bytes, 231 lines and includes unrelated later B005 ScrollPane split work; `by-memory/-ignored.md` is now SHA256 `CE93201D24BF65D43B2451593A95F622D346CD8EA91FA1C0E1FAC3056D625701`, 1,125,060 bytes, 5,414 lines; `by-project-structure/proposed-source-tree.md` is now SHA256 `527DC0CBE955189013A86297B63BBB6258BC9616361A81BD4DE53FDD7BA23049`, 315,420 bytes, 2,128 lines. The current ignored/source-tree files retain every UID0001DV insertion and correction exactly; the larger identities reflect unrelated concurrent additions and do not supersede this report's accepted content or dated validator evidence.
- Applied through the supervisor: complete function declarations with one-star `EventHandler *this` / `TimerHandler *this` adjusted receivers and `unsigned int flags`, exact function comments, both required `Block` clears, and the exact `g_pfnDrawLineDelta` address comment. No pointer indirection or handwritten scalar-deleting, adjustor, or vtable code was introduced.
- Gate 2B readback preserves the literal sixteen-item constructor inventory, each modeled function's first instruction item/parameters/locals/frame/collision constraints, and the callback global's one-byte item plus four-byte storage. Catalog entry 0354's later current frame presentation is reconciled exactly: scalar `__saved_registers +0x4`, `__return_address +0x8`, `flags +0xc : unsigned int`; each adjustor `__return_address +0x0`, `flags +0x4 : unsigned int`; earlier `arg_0`/one-member displays are historical prestates only. The constructor's positive-SP Hex-Rays warning and `Pane__Constructor((Pane *)this, savedregs)` rendering are a bounded analysis artifact; literal disassembly `push 1` at `0x0053fea7` remains the exact source fact supporting human draft `Pane(true)`.
- No in-scope research, B007-owned ordinary implementation, or accepted Gate 2B action remains. Fresh independent Gate 2 verification, manual coverage, lifecycle-time generated and shared-IDB readback, final gates, execution, and archive remain supervisor-owned.

## Recommended Target Doc Changes

- Callback disposition: every target-doc change below is applied and validated; the before/after wording is retained to preserve the accepted Gate 1 plan and its implementation trace.
- Path: `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md`.
- Metadata: `87/89 -> 92/94`; owner remains `00003D`; `RECONSTRUCTABLE:FALSE`; blank emitters; `Nested:3`; blank CPP/H.
- Replace Functions with exact assigned child links: [UID:0004Y8][constructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md), [UID:0004Y9][ordinary destructor](by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md), and [UID:0004YA][OnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md). Commands 18823-18825 assigned these UIDs serially; no guessed UID remains.
- Add exact byte/item boundaries, source-island behavior, NewOptionPane inline duplicates, OnPaint geometry, helper/global identities, subobject roles, split no-code proof, OptionPane placement, and scalar/adjustor/compiler exclusions.
- Historicalize the ScrollBar route, unresolved helper/global wording, generic cleanup helper wording, DrawPattern identity, and aggregate comment-emitter policy. Preserve them as superseded assumptions with reasons, not deletion.
- Item Summary: `Class-owned non-emitting split index over exact CScrollBarBackPane constructor, ordinary destructor, OnPaint, and internal alignment; exact children emit the OptionPane volume-slider minus/groove/plus source while compiler scalar/adjustor/vtable support remains separate.`

## Recommended Support Doc Changes

- Callback disposition: all ordinary support changes below are applied and validated, including the explicitly authorized proposed-source-tree correction. Supervisor Gate 2B IDA mutations are applied/read back at the accepted saved checkpoint; manual coverage and remaining lifecycle actions remain supervisor-owned.
- Applied `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` as validator-assigned UID0004Y8 with `93/94`, owner/emitter UID00003D, reconstructable true, `Nested:0`, exact constructor CPP, blank H with declaration-owner proof, and complete `0x32` boundary/bytes/callee/inline-duplicate evidence.
- Applied `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` as validator-assigned UID0004Y9 with `92/94`, owner/emitter UID00003D, reconstructable true, `Nested:0`, exact empty-destructor CPP, blank H with declaration-owner proof, and complete `0x1f` boundary/vptr/base-tail/compiler-regeneration evidence.
- Applied `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` as validator-assigned UID0004YA with `94/94`, owner/emitter UID00003D, reconstructable true, `Nested:0`, exact OnPaint CPP, blank H with declaration-owner proof, and complete `0x8d` boundary/vtable/callee/xref/coordinate/delta/geometry evidence.
- `by-class/CScrollBarBackPane.md`: `87/88 -> 92/94`; owner/emitter `0000NF -> 0000M7`; CPP `[[CHILDREN]]`; insert exact H declaration; add complete purpose, source route, method/child map, geometry, inherited facets, NewOptionPane ownership, helper/global identities, and historical placement correction.
- `by-file/OptionPane.md`: `92/88 -> 93/91`; add CScrollBarBackPane as NewOptionPane volume-slider support, its full code/RTTI/scalar ranges, two fields, construction/layout/destruction evidence, and generated CPP/H route.
- `by-file/ScrollBar.md`: `90/87 -> 91/90`; remove CScrollBarBackPane from current contents/ranges/cross-routes; preserve its prior medium-confidence placement as rejected history. Fresh supervisor currentness identity is SHA256 `F467456C8778B6FF17A47E411316C3A3D853824D7CF75A94A90D692C1457968A`, 46,082 bytes, 231 lines. Its later B005 ScrollPane split additions are unrelated concurrent work and are preserved; the UID0001DV historicalization and OptionPane routing remain present exactly.
- `by-class/NewOptionPane.md` and `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`: keep metadata; add fields `+0x12cc/+0x12d0`, paired volume-slider roles, inline CScrollBarBackPane construction, 120x5 bounds, and common Pane_MarkForDeletion lifetime.
- `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md`: `88/92 -> 90/94`; owner/emitter unchanged; source file changes to OptionPane; retain comment-only scalar-wrapper code and add exact human ordinary-destructor regeneration route. Preserve `arg_0 +0xc : int` only as the accepted pre-typing frame display and record catalog-entry-0354 current frame `__saved_registers +0x4`, `__return_address +0x8`, `flags +0xc : unsigned int`, with all member comments absent.
- `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md` [UID:00023J]: keep `86/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/formals; add exact CScrollBarBackPane EventHandler/TimerHandler adjustor subranges, one-star receiver declarations, `unsigned int flags`, `-0xa0/-0xa4` forwarding behavior, deterministic stale-`Block` clear disposition, vtable routes, and compiler-only/no-handwritten-source explanation without disturbing unrelated dialog adjustors. Preserve each earlier one-member frame only as accepted pre-typing history and record each catalog-entry-0354 current frame as `__return_address +0x0` plus `flags +0x4 : unsigned int`, with both member comments absent.
- `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md`: `87/91 -> 90/94`; owner/emitter unchanged; source file changes to OptionPane; name `+0x44` OnPaint and exact inherited facet roles; preserve no handwritten table.
- `by-memory/-ignored.md`: preserve the existing grouped option/macro/social/profile/scroll alignment entry, including its external `[0x0053fe9b,0x0053fea0)` and `[0x0053ff8d,0x0053ff90)` spans, unchanged. Immediately after that existing entry and before the current `0x00541b2b-...` entry, insert the following literal block using assigned child links. Fresh supervisor currentness identity is SHA256 `CE93201D24BF65D43B2451593A95F622D346CD8EA91FA1C0E1FAC3056D625701`, 1,125,060 bytes, 5,414 lines; all UID0001DV spans, links, and rationale below remain present exactly despite unrelated concurrent additions:

```text
- `0x0053fed2-0x0053fee0` and `0x0053feff-0x0053ff00` - CScrollBarBackPane internal method alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes between the retained CScrollBarBackPane constructor, ordinary destructor, and OnPaint bodies; these spans contain no source-authored logic or data.
  - Evidence: the 2026-07-29 B007 UID0001DV bounded byte/item audit confirmed constructor `[0x0053fea0,0x0053fed2)` ending at `ret` `0x0053fed1`, fourteen `0xcc` bytes at `[0x0053fed2,0x0053fee0)`, ordinary destructor `[0x0053fee0,0x0053feff)`, one `0xcc` byte at `[0x0053feff,0x0053ff00)`, and OnPaint `[0x0053ff00,0x0053ff8d)` ending at `ret` `0x0053ff8c`. Exact item boundaries, bytes, and adjacent modeled/raw method roles leave no hidden-code or fallthrough ambiguity.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes between three separately emitted CScrollBarBackPane methods.
  - Owner docs: [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md), [UID:0004Y8][0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md), [UID:0004Y9][0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor](by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md), [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md), [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md), and [UID:0000M7][OptionPane](by-file/OptionPane.md).
```
- `by-global/SurfaceRenderCallbackTable.md` [UID:0000TN]: keep `93/94`, owner/emitter/formals unchanged; historicalize the 2026-07-24 missing-tinfo state and record the saved split readback exactly: names/global catalogs contain `g_pfnDrawLineDelta`, applied type is `SurfaceDrawLineDeltaProc`, the one-byte item-head name remains blank, Hex-Rays may still render `MEMORY[0x69B3E4]`, and the exact address-regular comment is applied. Do not duplicate or alter the accepted Surface.h/Surface.cpp declaration-definition set.
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` [UID:0001PI]: keep current `91/93`, owner/emitter/formals and physical 12-dword storage disposition unchanged; historicalize its 2026-07-24 pending-tinfo statement with the same current names-catalog/applied-type/item-head/Hex-Rays distinction. Do not emit duplicate storage or callback source from this physical page.
- `by-project-structure/proposed-source-tree.md`: the explicit callback overrode the normal B-agent structural boundary; the former 2026-06-01 ScrollBar route is historical and the exact 2026-07-29 OptionPane correction text was applied and validated. Fresh supervisor currentness identity is SHA256 `527DC0CBE955189013A86297B63BBB6258BC9616361A81BD4DE53FDD7BA23049`, 315,420 bytes, 2,128 lines; its current shared version retains the complete UID0001DV correction exactly while preserving unrelated concurrent additions.
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`, `by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md`, and Pane docs: no content/metadata change required; they already supply exact accepted dependencies.

## Score And Metadata Recommendation

- Target assignment-time state: `87/89`, owner/emitter 00003D, true, comment-only aggregate emitter.
- Target current applied state: `92/94`, owner 00003D, false, blank emitter/formals, `Nested:3`.
- Reason higher: every byte, method role, dependency identity, virtual slot, subobject role, adjusted-receiver declaration, consumer, geometry, source route, split, formal source, and compiler exclusion is resolved.
- Reason not higher: child pages, ordinary incorporation, scoped validator evidence, and supervisor Gate 2B now exist, but fresh independent Gate 2 verification, manual coverage, lifecycle-time generated readback, and execution remain pending. Exact original access placement remains inferred, and source placement is strong rather than direct-symbol proof. The `95+` final-audit gate therefore does not apply.
- Applied child scores: constructor UID0004Y8 `93/94`; ordinary destructor UID0004Y9 `92/94`; OnPaint UID0004YA `94/94`. No child uses `95+` before final supervisor audit and lifecycle closure.
- Class: `87/88 -> 92/94`; OptionPane file `92/88 -> 93/91`; ScrollBar file `90/87 -> 91/90`; scalar wrapper `88/92 -> 90/94`; vtable `87/91 -> 90/94`; UID00023J remains `86/90` because its page is a mixed compiler-only thunk island and this report resolves only its two CScrollBarBackPane subranges.
- Score-improvement audit:
  - Raw constructor blocker removed by exact bytes, inline duplicates, boundaries, and source-shape comparison.
  - Cleanup blocker removed by destructor-family/source-island analysis.
  - Raw helper/global blockers removed by current IDA names/types and support docs.
  - Draw-intent blocker removed by exact geometry plus NewOptionPane layout.
  - Source-placement blocker removed by construction/member/layout/lifetime and adjacency evidence.
  - Aggregate blocker removed by complete exact split and formal channel plan.
  - Adjusted-receiver blocker removed by corrected live target prestates, the EventHandler/TimerHandler source contracts, and four current applied one-star adjustor analogs; no double-pointer declaration is proposed.
- No score cap is justified by a statement that more research is needed.

## Open Questions With Attempted Resolution

- Raw constructor source treatment: resolved as out-of-line `CScrollBarBackPane()` with `Pane(true)`; missing direct calls are explained by two exact inlined live uses.
- Cleanup helper versus destructor: resolved as the ordinary out-of-line empty destructor; scalar and adjustor forms are separately identified compiler ABI.
- `0x004b9600`: resolved as `GrafPort::MoveTo(int,int)`.
- `dword_69B3E4`: resolved as typed `g_pfnDrawLineDelta`.
- Fixed draw purpose: resolved as NewOptionPane volume-slider minus/groove/plus background.
- Subobject roles: resolved as Pane/GrafPort primary, inherited EventHandler secondary, inherited TimerHandler tertiary.
- Adjusted-receiver types: resolved as exactly `EventHandler *this` for the `-0xa0` thunk and `TimerHandler *this` for the `-0xa4` thunk, each with `unsigned int flags`. The standalone EventHandler pointer-form inspection is outweighed by the emitted EventHandler class contract and exact live CollectionPane2/SliderControlPane function-type readbacks; adding a second star would be unsupported.
- Aggregate versus split: resolved as exact three-child split plus two ignored pads.
- Owner/source placement: resolved to OptionPane/NewOptionPane support, not generic ScrollBar.
- Formal CPP/H: resolved with exact insertion text above.
- Original access specifiers and exact header-locality are not directly encoded. The best period/project-consistent choice is a public override declaration in the class H channel. This is a selected inference, not an unresolved blocker, and does not change execution.
- Questions remaining unresolved: none in scope.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected manual files: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-global/-coverage-report.md`. Target-family rows listed below are stale and require supervisor edits after callback implementation.
- Evidence-specific no-change coverage dispositions: UID0000TN's current by-global row already describes the typed Surface.h/Surface.cpp declaration-definition set at `93%` and does not claim IDA tinfo is pending; UID0001PI's current by-memory row already describes exact physical storage and the semantic UID0000TN route at `91%` and likewise does not claim pending tinfo. Their ordinary docs need current-state history corrections, but neither manual coverage row needs replacement for this report.
- Replace the current UID0001DV row with:

```text
    - [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md) 0x0053fea0-0x0053ff8d | class-owned split index | CScrollBarBackPaneCore : not_reconstructable : 92% : very-strong : Class-owned non-emitting split index over exact constructor, ordinary destructor, OnPaint, and internal alignment; exact children emit the OptionPane volume-slider minus/groove/plus source while scalar/adjustor/vtable compiler support remains separate.
```

- Insert the following exact rows immediately under UID0001DV. Commands 18823-18825 assigned the three child UIDs serially; these are supervisor-ready canonical links.

```text
        - [UID:0004Y8][0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor](by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md) 0x0053fea0-0x0053fed2 | constructor | CScrollBarBackPaneConstructor : reconstructable : 93% : very-strong : Exact retained out-of-line CScrollBarBackPane constructor; Pane(true), three inherited-view vptr installs, two live NewOptionPane inline equivalents, closed boundaries, and human formal source are resolved.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053fed2-0x0053fee0 | padding | CScrollBarBackPane constructor-to-destructor alignment : ignored : 100% : strong : Fourteen confirmed 0xcc bytes; no hidden code or data.
        - [UID:0004Y9][0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor](by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md) 0x0053fee0-0x0053feff | ordinary destructor | CScrollBarBackPaneOrdinaryDestructor : reconstructable : 92% : very-strong : Exact out-of-line empty virtual destructor; three class-view restores and Pane tail teardown are compiler output from the human empty destructor, distinct from scalar/adjustor ABI glue.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053feff-0x0053ff00 | padding | CScrollBarBackPane destructor-to-OnPaint alignment : ignored : 100% : strong : One confirmed 0xcc byte; no hidden code or data.
        - [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md) 0x0053ff00-0x0053ff8d | virtual method | CScrollBarBackPaneOnPaint : reconstructable : 94% : very-strong : Exact Pane +0x44 OnPaint draws the NewOptionPane volume-slider minus sign, three-line groove, and plus sign through GrafPort::MoveTo and typed g_pfnDrawLineDelta with complete human formal source.
```

- Replace UID0001E3 row with:

```text
    - [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md) 0x00542680-0x005426d5 | compiler scalar deleting destructor | CScrollBarBackPaneDestructor : reconstructable : 90% : very-strong : Exact MSVC scalar deleting wrapper for the OptionPane-local CScrollBarBackPane; ordinary empty destructor/class source regenerates vptr resets, Pane teardown, deleting flags, guarded-size path, and EventHandler/TimerHandler adjustors, so only a formal no-handwritten-wrapper marker emits.
```

- Replace UID00023J's current generic `80%` ignored row with:

```text
    - [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) 0x0054259f-0x0054267b | adjustor-thunks | DialogPaneAdjustorThunkIsland : ignored : 86% : strong : Compiler/linker-generated dialog deleting-destructor adjustor island; exact CScrollBarBackPane EventHandler and TimerHandler entries at 0x0054259f/0x005425aa use one-star receivers, unsigned-int flags, -0xa0/-0xa4 forwarding, typed scalar target 0x00542680, exact vtable routes, and deterministic stale-Block comment clears, while all adjustors remain non-emitting compiler ABI evidence.
```

- Replace UID00003D class row with:

```text
- [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) : reconstructable : 92% : very-strong : OptionPane-local Pane-derived volume-slider backplate with complete class declaration, exact constructor/ordinary-destructor/OnPaint split, minus/groove/plus geometry, NewOptionPane member/layout/lifetime evidence, resolved GrafPort::MoveTo/g_pfnDrawLineDelta contracts, inherited EventHandler/TimerHandler facets, and compiler scalar/adjustor/vtable exclusions.
```

- Replace UID000097's current generic `84%` class row with:

```text
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md) : reconstructable : 87% : strong : New options pane with exact method/helper inventory plus two owned CScrollBarBackPane volume-slider backplates at +0x12cc/+0x12d0; their inline Pane(true) construction, paired 120x5 bounds, minus/groove/plus drawing role, shared deletion lifetime, and OptionPane source route are documented without changing NewOptionPane metadata or emitting duplicate child source.
```

- Replace UID0000M7 file row with:

```text
- [UID:0000M7][OptionPane](by-file/OptionPane.md) : reconstructable : 93% : very-strong : Old/new options UI source family plus the exact CScrollBarBackPane volume-slider support class; NewOptionPane owns two ScrollVolumePane and two CScrollBarBackPane children with resolved construction, layout, lifetime, drawing, helper/global contracts, source routing, and compiler boundaries, while unrelated raw option-helper questions remain separately documented.
```

- Replace UID0000NF file row with:

```text
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md) : reconstructable : 91% : very-strong : Generic ScrollPane/ScrollWidget/ScrollablePane source family with exact class/method/layout/constant/compiler routes; historical CScrollBarBackPane placement is rejected by its exclusive NewOptionPane volume-control ownership and rerouted to OptionPane.
```

- Replace UID0001DW's current generic `78%` memory row with:

```text
    - [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md) 0x0053ff90-0x00541b2b | class-cluster | NewOptionPane : reconstructable : 87% : strong : NewOptionPane aggregate with exact method/helper map plus two owned CScrollBarBackPane backplates at +0x12cc/+0x12d0; inline Pane(true) construction, paired 120x5 volume-slider placement, minus/groove/plus rendering support, common Pane_MarkForDeletion lifetime, and OptionPane source placement are documented while exact child pages retain source ownership.
```

- UID0003LR has no current manual by-memory row. Insert this exact row as an eight-space-indented child of UID000261 `OptionMacroProfileReadOnlyData`, immediately before existing UID0003C9 `TargetOptionDialogVtableData`:

```text
        - [UID:0003LR][0x00621018-0x006210a0.CScrollBarBackPaneVtableData](by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md) 0x00621018-0x006210a0 | compiler RTTI/vtable data | CScrollBarBackPaneVtableData : reconstructable : 90% : very-strong : Exact OptionPane-local CScrollBarBackPane primary, EventHandler, and TimerHandler RTTI/vtable views with primary OnPaint slot, scalar deleting destructor, one-star -0xa0/-0xa4 adjusted entries, inherited Pane routes, exact NewOptionPane successor boundary, and class-covered no-handwritten-table emission policy.
```

- Reason B007 must not apply: all manual coverage files are supervisor-owned collision points. The three new child references now use exact validator-assigned UID links for supervisor use; the supervisor must validate the edited manual coverage file. No UID was guessed or reserved.
- No generated `auto-generated/-ag-*` text is supplied. Commands `18740`, `18808`, and `18812` remain dated assignment/intermediate/unrelated-global checkpoints and none is implementation evidence. The moving `auto-generated/-ag-research-tracker.md` advanced independently to command `000000018878`, refreshed `2026-07-29T07:38:28-04:00`, SHA256 `0709E455BC00C5E2F2080500ACADC7076C7FB07C90DA89B9A93B6B0AC3498F77`, 1,668,879 bytes, 6,603 lines; its UID0001DV row is line 5473 at `92/94`, combined `93.0`, reconstructable false. This is transition-safe moving provenance only: later supervisor/global refreshes may advance it, and the supervisor's lifecycle-time generated/tracker readback is authoritative.

## Follow-Up Actions

- Supervisor Gate 2A: independently verify all 97 contiguous ledger rows against the exact current destinations and the hashes/validator evidence below. The B007-owned ordinary implementation, exact Gate 1/Gate 2A repair rows, and accepted Gate 2B actions are complete; blocked rows are limited to supervisor-owned manual coverage operations.
- Supervisor Gate 2B: applied and saved at accepted checkpoint SHA256 `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C`. Catalog entry 0354 subsequently required frame-presentation reconciliation against moving shared IDB SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB`; that bounded report/ordinary-document reconciliation is complete. Current presentation is scalar `__saved_registers +0x4`, `__return_address +0x8`, `flags +0xc : unsigned int`, and each adjustor `__return_address +0x0`, `flags +0x4 : unsigned int`; the former scalar `arg_0` and adjustor one-member displays remain only as historical prestates. Fresh verification must also preserve the created constructor frame and bounded positive-SP Hex-Rays artifact, the one-star `EventHandler *this` / `TimerHandler *this` adjustor declarations, absent address comments after both stale `Block` clears, exact function comments, and the exact `g_pfnDrawLineDelta` address-regular comment. B007 did not mutate IDA; because the shared IDB may advance again, lifecycle-time semantic and physical readback is authoritative.
- Supervisor manual coverage: apply the exact UID0004Y8/UID0004Y9/UID0004YA nested payload plus the atomically mapped UID0001DV/UID0001E3/UID00023J/UID00003D/UID000097/UID0000M7/UID0000NF/UID0001DW/UID0003LR operations below and validate each affected manual coverage file. B007 did not edit any coverage report.
- Supervisor lifecycle closure: run the authorized generated refresh/readback, verify OptionPane CPP/H and removal of current CScrollBarBackPane routing from ScrollBar, rerun fresh final gates, then execute/archive through validator lifecycle. The proposed-source-tree correction is already applied under the explicit callback override and needs only Gate 2A verification.
- A-agent actions: none.
- B007 future research actions: none unless Gate 1 identifies a concrete evidence defect.

## Confidence

- Recommendation confidence: very strong for split, source bodies, virtual identity, behavior, helper/global identities, subobject roles, and class owner; strong for exact original source file.
- Score confidence: strong. Applied scores distinguish complete research, ordinary implementation, and Gate 2B closure from still-pending supervisor manual-coverage/generated/final-lifecycle proof.
- Gate 2B closure confidence: very strong. Every actionable name, declaration, first instruction item, parameter/local name/type/width/local-user-comment state, frame/member-comment state, address/function comment channel, clear operation, collision result, no-change constraint, and saved poststate is recorded. Catalog entry 0354's bounded frame-presentation discrepancy is reconciled: scalar `flags` is current at `+0xc`, while each adjustor has current `flags` at `+0x4`; the earlier `arg_0`/one-member displays are retained only as prestates. The raw constructor has the complete sixteen-item partition, exact created function/frame, and honestly bounded positive-SP Hex-Rays artifact; bytes still prove `Pane(true)`. All eleven action-table entities are represented atomically; C80-C82 remain non-actionable protected vtable evidence. No optional or unapplied IDA action remains.
- Adjusted-receiver confidence: very strong. Corrected target prestates are direct live readbacks, and both receiver spellings are supported by source-class documentation plus two independent current applied Pane-derived adjustor families. Exactly one visible pointer star is required; double-pointer alternatives are rejected.
- Remaining uncertainty: original private/public layout and whether the declaration physically appeared in OptionPane.h or OptionPane.cpp cannot be recovered exactly. The selected project-conventional H placement is human, consistent, and execution-neutral; it does not justify deferral or raw naming.

## Validator Results

- Common invocation working directory for all commands below: `E:\NTK\GhidraBridge\source-3\project-documentation`; validator-reported canonical root: `C:\FastStorage\NTK_Sources\source-3\project-documentation`. Every command used `--apply --no-generated-refresh --queue-timeout 240`, returned exit `0` and `ok: 1`, updated projected completion statistics as a validator-owned side effect, and reported `generated_refresh: skipped` with its own command ID/timestamp.
- Initial child registration, run serially before any cross-reference reconciliation:
  - `000000018823`, `2026-07-29T06:38:44-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md" --apply --no-generated-refresh --queue-timeout 240`; assigned UID0004Y8; no warning reported.
  - `000000018824`, `2026-07-29T06:39:00-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md" --apply --no-generated-refresh --queue-timeout 240`; assigned UID0004Y9; no warning reported.
  - `000000018825`, `2026-07-29T06:39:15-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md" --apply --no-generated-refresh --queue-timeout 240`; assigned UID0004YA; no warning reported.
- Final serial ordinary-document validation after exact UID reconciliation:
  - `000000018827`, `2026-07-29T06:52:56-04:00`: constructor UID0004Y8 command above; no warning.
  - `000000018828`, `2026-07-29T06:52:59-04:00`: ordinary-destructor UID0004Y9 command above; no warning.
  - `000000018829`, `2026-07-29T06:53:02-04:00`: OnPaint UID0004YA command above; no warning.
  - `000000018830`, `2026-07-29T06:53:05-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md" --apply --no-generated-refresh --queue-timeout 240`; applied `92/94`, reconstructable false, blank emitter/formals, and exact child links; no warning.
  - `000000018833`, `2026-07-29T06:54:46-04:00`: `python .\tools\validator.py --mode file --file "by-class\CScrollBarBackPane.md" --apply --no-generated-refresh --queue-timeout 240`; applied `92/94`, owner/emitter UID0000M7, CPP/H and child links; no warning.
  - `000000018834`, `2026-07-29T06:54:50-04:00`: `python .\tools\validator.py --mode file --file "by-file\OptionPane.md" --apply --no-generated-refresh --queue-timeout 240`; applied `93/91` and normalized child/support links; no warning.
  - `000000018835`, `2026-07-29T06:54:53-04:00`: `python .\tools\validator.py --mode file --file "by-file\ScrollBar.md" --apply --no-generated-refresh --queue-timeout 240`; applied `91/90` and historicalized route links; no warning.
  - `000000018836`, `2026-07-29T06:54:56-04:00`: `python .\tools\validator.py --mode file --file "by-class\NewOptionPane.md" --apply --no-generated-refresh --queue-timeout 240`; `missing_ref_uid: 5`, all for pre-existing absent UID00038E; callback links applied and `ok: 1`.
  - `000000018837`, `2026-07-29T06:55:11-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053ff90-0x00541b2b.NewOptionPane.md" --apply --no-generated-refresh --queue-timeout 240`; no warning.
  - `000000018838`, `2026-07-29T06:55:15-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md" --apply --no-generated-refresh --queue-timeout 240`; applied `90/94`; no warning.
  - `000000018839`, `2026-07-29T06:55:18-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md" --apply --no-generated-refresh --queue-timeout 240`; no warning.
  - `000000018840`, `2026-07-29T06:55:21-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md" --apply --no-generated-refresh --queue-timeout 240`; applied `90/94`; no warning.
  - `000000018842`, `2026-07-29T06:55:35-04:00`: `python .\tools\validator.py --mode file --file "by-global\SurfaceRenderCallbackTable.md" --apply --no-generated-refresh --queue-timeout 240`; `missing_ref_uid: 3`, all for pre-existing absent UID0003XE; callback history/current-state links applied and `ok: 1`.
  - `000000018843`, `2026-07-29T06:55:38-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md" --apply --no-generated-refresh --queue-timeout 240`; `missing_ref_uid: 3`, all for pre-existing absent UID0003XE; callback history/current-state links applied and `ok: 1`.
  - `000000018844`, `2026-07-29T06:55:42-04:00`: `python .\tools\validator.py --mode file --file "by-memory\-ignored.md" --apply --no-generated-refresh --queue-timeout 240`; `missing_ref_uid: 200` across the pre-existing broad ignored ledger; exact UID0001DV/UID0004Y8/UID0004Y9/UID0004YA references indexed and `ok: 1`.
  - `000000018845`, `2026-07-29T06:55:46-04:00`: `python .\tools\validator.py --mode file --file "by-project-structure\proposed-source-tree.md" --apply --no-generated-refresh --queue-timeout 240`; five pre-existing missing refs UID0003LP/UID0003WL/UID0003WM/UID0003WN/UID0003WO; exact OptionPane correction links applied and `ok: 1`.
- Gate 2A ordinary-document contradiction repair, run serially with the same working directory and flags; each command returned exit `0`, `ok: 1`, no warning, and `generated_refresh: skipped`:
  - `000000018863`, `2026-07-29T07:19:26-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md" --apply --no-generated-refresh --queue-timeout 240`; replaced current cleanup-helper wording with ordinary-destructor classification and corrected the current `92/94` target/class plus `93/91` OptionPane assignment gate.
  - `000000018864`, `2026-07-29T07:19:55-04:00`: `python .\tools\validator.py --mode file --file "by-class\CScrollBarBackPane.md" --apply --no-generated-refresh --queue-timeout 240`; replaced current ScrollBar-ancestor/deferred-declaration contradictions with the applied OptionPane route and complete class declaration while preserving the dated 2026-07-01 state as history.
  - `000000018865`, `2026-07-29T07:20:36-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md" --apply --no-generated-refresh --queue-timeout 240`; replaced current cleanup-helper wording with ordinary-destructor classification and reconciled the score rationale to metadata `90/94`.
- Fresh Gate 1/Gate 2A ordinary-currentness repair, run serially with the same working directory and flags; each command returned exit `0`, `ok: 1`, no warning, and `generated_refresh: skipped`:
  - `000000018879`, `2026-07-29T07:42:51-04:00`: `python .\tools\validator.py --mode file --file "by-class\CScrollBarBackPane.md" --apply --no-generated-refresh --queue-timeout 240`; historicalized the standalone recovered filename, generic DrawPattern name, raw cleanup/draw labels, and former ScrollBar ancestor while stating current OptionPane placement, ordinary-destructor/OnPaint identities, and resolved MoveTo/callback contracts.
  - `000000018880`, `2026-07-29T07:42:58-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md" --apply --no-generated-refresh --queue-timeout 240`; converted the dated provisional `0x004b9600`/`dword_69B3E4` statement into explicit history and stated the current resolved `GrafPort::MoveTo`/`g_pfnDrawLineDelta` contracts.
- Supervisor Gate 2B ordinary-document reconciliation, run serially with the same working directory and flags; every command returned exit `0`, `ok: 1`, and `generated_refresh: skipped`:
  - `000000018899`, `2026-07-29T08:02:18-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md" --apply --no-generated-refresh --queue-timeout 240`; recorded all accepted applied IDA identities/comments and the constructor disassembly-versus-Hex-Rays discrepancy; no warning.
  - `000000018900`, `2026-07-29T08:02:47-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md" --apply --no-generated-refresh --queue-timeout 240`; recorded the exact created function/prototype/comment/frame, minimal type ordinal 942, positive-SP warning, misleading `savedregs` rendering, and byte-proven `Pane(true)`; no warning.
  - `000000018901`, `2026-07-29T08:03:13-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md" --apply --no-generated-refresh --queue-timeout 240`; recorded exact destructor name/prototype/comment/frame/current decompile; no warning.
  - `000000018902`, `2026-07-29T08:03:42-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md" --apply --no-generated-refresh --queue-timeout 240`; recorded exact OnPaint name/prototype/comment/frame/current decompile while preserving instruction comments; no warning.
  - `000000018903`, `2026-07-29T08:04:20-04:00`: `python .\tools\validator.py --mode file --file "by-class\CScrollBarBackPane.md" --apply --no-generated-refresh --queue-timeout 240`; recorded minimal incomplete type ordinal 942, the complete applied function family, cleared stale comments, and constructor Hex-Rays artifact; no warning.
  - `000000018904`, `2026-07-29T08:05:02-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md" --apply --no-generated-refresh --queue-timeout 240`; recorded the exact scalar-wrapper identity/prototype/comment and accepted Gate 2B checkpoint frame presentation; that dated frame-member presentation is historical after catalog entry 0354 and command 18984; no warning.
  - `000000018905`, `2026-07-29T08:05:40-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md" --apply --no-generated-refresh --queue-timeout 240`; recorded both exact one-star adjustor declarations/comments, accepted Gate 2B checkpoint frame presentations, and absent stale `Block` address comments; those dated one-member frame presentations are historical after catalog entry 0354 and command 18985; no warning.
  - `000000018906`, `2026-07-29T08:06:11-04:00`: `python .\tools\validator.py --mode file --file "by-global\SurfaceRenderCallbackTable.md" --apply --no-generated-refresh --queue-timeout 240`; recorded exact applied callback address comment and unchanged storage/catalog/type state; three `missing_ref_uid` warnings for pre-existing absent UID0003XE.
  - `000000018907`, `2026-07-29T08:06:39-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md" --apply --no-generated-refresh --queue-timeout 240`; recorded the same physical callback-slot readback; three `missing_ref_uid` warnings for pre-existing absent UID0003XE.
- Shared-IDB-checkpoint wording correction after read-only currentness detection:
  - `000000018909`, `2026-07-29T08:16:12-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md" --apply --no-generated-refresh --queue-timeout 240`; labeled SHA256 `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C` as the accepted Gate 2B saved checkpoint rather than an indefinitely current shared-file hash; exit `0`, `ok: 1`, no warning, `generated_refresh: skipped`.
- Catalog-entry-0354 frame-presentation reconciliation, run serially with the same working directory and flags; each command returned exit `0`, `ok: 1`, no warning, and `generated_refresh: skipped`:
  - `000000018984`, `2026-07-29T08:41:50-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md" --apply --no-generated-refresh --queue-timeout 240`; preserved the accepted `arg_0 +0xc : int` display as historical prestate and recorded current `__saved_registers +0x4`, `__return_address +0x8`, and `flags +0xc : unsigned int`, all four bytes with absent frame-member comments.
  - `000000018985`, `2026-07-29T08:41:53-04:00`: `python .\tools\validator.py --mode file --file "by-memory\0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md" --apply --no-generated-refresh --queue-timeout 240`; preserved each accepted one-member adjustor frame as historical prestate and recorded each current frame as `__return_address +0x0` plus `flags +0x4 : unsigned int`, both four bytes with absent frame-member comments.
- Fresh support-file currentness reconciliation was report-only and ran no validator: supervisor Gate 2A supplied `by-file/ScrollBar.md` SHA256 `F467456C8778B6FF17A47E411316C3A3D853824D7CF75A94A90D692C1457968A` (46,082 bytes, 231 lines), `by-memory/-ignored.md` SHA256 `CE93201D24BF65D43B2451593A95F622D346CD8EA91FA1C0E1FAC3056D625701` (1,125,060 bytes, 5,414 lines), and `by-project-structure/proposed-source-tree.md` SHA256 `527DC0CBE955189013A86297B63BBB6258BC9616361A81BD4DE53FDD7BA23049` (315,420 bytes, 2,128 lines). Commands 18835, 18844, and 18845 remain dated UID0001DV implementation/validation checkpoints, not claims that their earlier physical hashes remain current. The current ScrollBar file preserves later B005 ScrollPane split work, and the current ignored/source-tree files retain every UID0001DV change exactly.
- Temporary-reference reconciliation: exact headers are UID0004Y8, UID0004Y9, and UID0004YA; all sixteen ordinary callback destinations and this report contain zero unresolved temporary UID-reference placeholders.
- No final generated refresh was run because the callback explicitly prohibited it. Supervisor lifecycle-time generated refresh/readback remains required and authoritative.
- Bounded warnings are pre-existing missing-reference debt in broad support pages; no validator error or callback-specific missing reference remains.

## Changed Files

- Created ordinary pages:
  - `by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md` (UID0004Y8), SHA256 `19CD4090DDBC0F8C9864A95707B46C68E6075B5387EBB0C2A181C3A37D6EF800`, 8,338 bytes, 91 lines; Gate 2B reconciliation command 18900.
  - `by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md` (UID0004Y9), SHA256 `D20FD68F9613F905F0C22032B95EB188EB5D1E497F0403B8A9B7CF75B3DAE98B`, 7,145 bytes, 86 lines; Gate 2B reconciliation command 18901.
  - `by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md` (UID0004YA), SHA256 `F9AD12636EA867798914AB578DEA0BD347407A42875681D0B155695847E6F14A`, 8,893 bytes, 114 lines; Gate 2B reconciliation command 18902.
- Modified ordinary pages; entries below are post-validator checkpoints except where a fresh supervisor currentness identity is stated explicitly:
  - `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md`, SHA256 `A64BA296C827F9141A31C0FA28324B3C87C2B0D1BD3E466700C8F805C0956B40`, 18,895 bytes, 139 lines; Gate 2B reconciliation command 18899.
  - `by-class/CScrollBarBackPane.md`, SHA256 `EAB9D758FA71BB545D10AF71B6A2CF235FE74A2A4BAFC645103DA55515704D6F`, 17,938 bytes, 130 lines; Gate 2B reconciliation command 18903.
  - `by-file/OptionPane.md`, SHA256 `455717C714B78A4D3BC397090A84E877470AFBA65C27D68258A4F33637576F83`, 36,851 bytes, 175 lines.
  - `by-file/ScrollBar.md`, current supervisor-read identity SHA256 `F467456C8778B6FF17A47E411316C3A3D853824D7CF75A94A90D692C1457968A`, 46,082 bytes, 231 lines. This current shared file includes unrelated later B005 ScrollPane split work and retains the UID0001DV historicalization/OptionPane route exactly; command 18835 remains the dated UID0001DV validation checkpoint.
  - `by-class/NewOptionPane.md`, SHA256 `8C54C573A2B0A7F1EE7740A3C4486ACC3DAC0FB005D7DF610A784A4ED8FCA44D`, 25,061 bytes, 142 lines.
  - `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`, SHA256 `3412D3C93DFD7950E8F3A92F39F7950EF300CF52855731DF7E744D0480B87BD4`, 42,414 bytes, 235 lines.
  - `by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md`, SHA256 `9BD3509E387EC6678C0771FA136819703113FCFECD54AAE25AE0CFB44A462C3D`, 21,876 bytes, 171 lines; Gate 2B reconciliation command 18904, shared-IDB-checkpoint wording command 18909, and catalog-entry-0354 frame-presentation command 18984.
  - `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md`, SHA256 `F20DF7B1DCF5175A8BD17C1391B831E63A4D7CA6D5243AF77440AC9FD8001854`, 12,579 bytes, 107 lines; Gate 2B reconciliation command 18905 plus catalog-entry-0354 frame-presentation command 18985.
  - `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md`, SHA256 `666A6F291D7D9B81054641CCC974B5D8084030526E6F3BF72A3903BB78976A83`, 14,701 bytes, 116 lines; current Gate 2A repair checkpoint command 18865.
  - `by-global/SurfaceRenderCallbackTable.md`, SHA256 `E1CCD7C9425BCC12DA609FFAA1533873CC4EE32ACC3BD12163A99C2D0E3255E4`, 80,308 bytes, 444 lines; Gate 2B reconciliation command 18906.
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, SHA256 `ACBE8AA2B4C39428A037021857F32E08B78C4031F4E67D21B1042B3B1DCB6C5F`, 67,608 bytes, 370 lines; Gate 2B reconciliation command 18907.
  - `by-memory/-ignored.md`, current supervisor-read identity SHA256 `CE93201D24BF65D43B2451593A95F622D346CD8EA91FA1C0E1FAC3056D625701`, 1,125,060 bytes, 5,414 lines. All UID0001DV ignored-span content remains exact; command 18844 remains the dated UID0001DV validation checkpoint and unrelated concurrent additions explain the larger identity.
  - `by-project-structure/proposed-source-tree.md`, current supervisor-read identity SHA256 `527DC0CBE955189013A86297B63BBB6258BC9616361A81BD4DE53FDD7BA23049`, 315,420 bytes, 2,128 lines. The exact UID0001DV historical route correction remains present; command 18845 remains the dated UID0001DV validation checkpoint and unrelated concurrent additions explain the larger identity.
- Updated in place: this same report, retaining all Gate 1 research and adding callback truth, assigned UIDs, per-claim states, validator evidence, hashes, and remaining supervisor-only work.
- Automatic validator side effect: `project-level/-auto-completion-stats.md` projected statistics were refreshed by each scoped command; B007 did not edit that file manually and does not claim a stable checkpoint hash while other validator work may continue.
- Renamed/moved/generated/manual-coverage files: none. B007 did not mutate IDA. The supervisor-supplied accepted Gate 2B checkpoint is SHA256 `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C`, `143,189,974` bytes, last-write `2026-07-29T07:58:20.9779423-04:00`. Read-only filesystem currentness at `2026-07-29T08:14:10-04:00` found the shared IDB at intermediate SHA256 `FD8282A51836D47961EA386D7C2D25F80D0BF88B96ACFF106FFA802277F78B16`, the same size, last-write `2026-07-29T08:08:08.7919179-04:00`. Fresh supervisor Gate 2/catalog-entry-0354 verification used the later moving shared IDB SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB`, `143,190,049` bytes, last-write `2026-07-29T08:26:09.5759690-04:00`, and established only the bounded current frame presentations reconciled above. These are distinct shared-file checkpoints; lifecycle-time readback is authoritative.
- Report execution: not run. B007 did not run/probe `execute_report`, edit lifecycle state, move/archive the report, or run a generated refresh.

## Implementation Tracking Checklist

Initial report-only and Gate 1 pass:

- [x] Supervisor validation passed for exact pre-callback SHA256 `B2648F964B9E638AB3AA0592BD23781CC244295F15D93FFFD62F81378426332A`; implementation callback was explicitly authorized.
- [x] Target/support docs to update: UID0001DV, three new exact children, UID00003D, UID0001E3, UID00023J, UID0003LR, UID0000M7, UID0000NF, UID000097/UID0001DW NewOptionPane support, UID0000TN/UID0001PI callback type-state history, and `by-memory/-ignored.md`; supervisor-owned follow-through also covers `by-project-structure/proposed-source-tree.md` and exact manual coverage rows. UID00023J receives exact adjustor declarations/comment-disposition/compiler-only documentation while retaining `86/90` and non-emitting metadata.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: no additional target UIDs declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated to 97 contiguous rows with one affected identity, one claim, one destination, one allowed Action token, and one Verification state per row; C85-C88 atomically mirror the previously omitted type/constructor/ordinary-destructor/OnPaint IDA actions, and C89-C97 map the nine exact supervisor-owned coverage operations one-for-one.
- [x] Metadata/score changes to apply recorded.
- [x] Score-limiting blockers researched to resolution or implementation-ready repair; no rare no-improvement exception used.
- [x] Owner/emitter/reconstructable changes to apply recorded.
- [x] Split/rename/new-child changes to apply recorded with exact boundaries and paths.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment changes recorded.
- [x] Adjusted-receiver ambiguity resolved from live target and analogous function readbacks; exact one-star EventHandler/TimerHandler signatures and double-pointer exclusions recorded.
- [x] Raw-constructor Gate 2B prestate inventories every one of the sixteen current item partitions through exclusive end `0x0053fed2`, all applicable address comments, absent function/frame/decompile/local state, exact bytes/collision result, and deterministic expected function/receiver/result/frame/local readback.
- [x] Ordinary destructor, OnPaint, scalar deleting destructor, and both adjustors each record literal first instruction item, current Hex-Rays parameter/local names/types/widths/local-user-comment state, complete frame/member-comment state, collision result, and exact post-action parameter/local/frame readback; instruction comments are separately preserved and are not substitutes.
- [x] Callback global `0x0069b3e4` records exact item head/end/size/classification/bytes/name/type, four-byte storage bytes, address-regular/address-repeatable channels, function-regular: absent, function-repeatable: absent, deterministic action/constraints, and exact expected readback.
- [x] Supervisor Gate 2B IDA handoff was deterministic and listed every exact address/entity, complete declaration, literal pre-state, required comment clear/replacement, safety constraint, and expected readback; the supervisor applied, saved, and supplied exact readback, including the bounded constructor Hex-Rays artifact.
- [x] First-draft CPP block text/no-code proof and H block text/no-header-code proof recorded for parent, class, and every child.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate recorded at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve recorded.
- [x] Wave2/Wave3 mentions encountered and ignored/rejected as stale.
- [x] Open questions closed with best-supported resolutions; none deferred as `needs investigation`.
- [x] Validators to run after callback recorded during Gate 1; all required serial ordinary validators are now complete under commands 18823-18845 listed above.
- [x] Generated refresh expectation and exact supervisor-owned manual coverage payload recorded; the three new children use validator-assigned UID0004Y8/UID0004Y9/UID0004YA links with no guessed UID or angle-bracket placeholder, UID0003LR is an exact insertion, every listed stale target/support row has exact replacement text, and `by-memory/-ignored.md` has a literal insertion block with exact placement.
- [x] Manual coverage checklist mapping is atomic: C89 UID0001DV replace; C90 UID0001E3 replace; C91 UID00023J replace; C92 UID00003D replace; C93 UID000097 replace; C94 UID0000M7 replace; C95 UID0000NF replace; C96 UID0001DW replace; C97 UID0003LR insert at the exact UID000261/UID0003C9 location. C55/C61 separately retain the three assigned child plus two padding nested-row operation.
- [x] C80-C82 are already-present, non-actionable decorated-vtable evidence and are excluded from blocked Gate 2B work; no vtable rename/type/comment/readback mutation is requested.
- [x] Current `by-project-structure/proposed-source-tree.md` ScrollBar-route contradiction identified with exact supervisor-owned correction text and callback boundary.
- [x] Deterministic post-creation UID reconciliation completed through commands 18823-18825: UID0004Y8, UID0004Y9, and UID0004YA are the exact assigned child identities.

Implementation callback pass:

- [x] Supervisor-owned IDA changes were applied and read back at accepted saved checkpoint SHA256 `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C`; B007 did not mutate IDA. C21, C45-C47, and C85-C88 are `applied`; C79-C84 are protected/non-actionable `already-present` evidence. Catalog entry 0354's later moving-state presentation is reconciled in this report and the two affected ordinary pages: scalar current `flags +0xc`, both adjustors current `flags +0x4`, with the former `arg_0`/one-member displays retained only as prestates.
- [x] Report accepted by supervisor for implementation at exact Gate 1 hash recorded above.
- [x] All accepted B007-owned target/support doc details incorporated at report-level specificity across sixteen ordinary destinations.
- [x] Primary UID0001DV and all affected support/child UIDs independently checked against their atomic ledger destinations.
- [x] Claim And Incorporation Ledger updated: ordinary callback and accepted IDA mutation rows are `applied`, exact protected facts are `already-present`, and only supervisor-owned manual-coverage rows remain `blocked` with exact reasons.
- [x] Metadata/score/owner/emitter/split/source-route/CPP/H changes applied; no ordinary rename was required beyond the three exact child creations and UID registration.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, compiler-only dispositions, padding, and no-change constraints preserved.
- [x] Open questions remain resolved; no new ordinary-document blocker was introduced.
- [x] All thirty-six serial scoped ordinary-document validator commands returned exit `0`, `ok: 1`, and skipped generated refresh; commands 18863-18865 cover the first Gate 2A contradiction repairs, commands 18879-18880 cover the fresh class/core currentness repairs, commands 18899-18907 cover Gate 2B ordinary reconciliation, command 18909 covers the narrow shared-IDB-checkpoint wording correction, and commands 18984-18985 cover catalog-entry-0354 frame-presentation reconciliation. Bounded pre-existing missing-reference warnings remain itemized above.
- [x] Fresh report-only support-file currentness reconciliation records exact supervisor-supplied identities for `by-file/ScrollBar.md`, `by-memory/-ignored.md`, and `by-project-structure/proposed-source-tree.md`; no validator or ordinary edit was run. Later B005 ScrollPane split work is preserved in ScrollBar, and every UID0001DV ignored/source-tree change remains exact alongside unrelated concurrent additions.
- [x] Exact assigned UIDs reconciled and zero unresolved temporary UID-reference placeholders confirmed in all changed ordinary docs and this report.
- [x] B007-owned implementation is complete and all remaining accepted actions are listed below with exact supervisor-only ownership.
- [ ] Fresh supervisor Gate 2A independent claim-by-claim reverification remains pending for the reconciled 97-row ledger and current ordinary destinations.
- [x] Supervisor Gate 2B IDA application/readback is complete for C21, C45-C47, and C85-C88; protected C79-C84 required no mutation. The accepted checkpoint, intermediate shared state, and catalog-entry-0354 moving current state are recorded without conflation, and the bounded frame-presentation mismatch is reconciled without attributing any IDA mutation to B007.
- [ ] Supervisor manual coverage application/validation remains pending for C55, C61, and C89-C97 using the exact payload section across by-memory, by-class, and by-file coverage reports.
- [ ] Supervisor lifecycle-time generated refresh/readback, fresh final gates, execute, and archive remain pending.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000019064","destination_path":"executed-b-agent-research/B007/0001DV-CScrollBarBackPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001DV-CScrollBarBackPaneCore-source-quality.md","timestamp":"2026-07-29T09:55:05-04:00","uid":"0001DV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
