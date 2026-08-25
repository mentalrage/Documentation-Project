** TARGET-REPORT-UID:000130 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID000130 VersatileAlertPane Destructor Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation and applied state: UID000130 is the reviewed compiler-destructor ABI index at `by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md`, not a source method. It is split into exact non-emitting children UID0004NE, UID0004NF, and UID0004NG; the parent and children retain semantic owner UID0000FU `VersatileAlertPane`, are `RECONSTRUCTABLE:FALSE`, have blank emitters/positions/formal blocks, and are scored `94/97` and `95/98` respectively.
- Final disposition: the two adjustor thunks and scalar deleting destructor are compiler/linker-generated. Human source is one ordinary `VersatileAlertPane::~VersatileAlertPane()` definition, carried by UID00012Y after UID-preserving rename to `by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md`.
- Applied callback boundary: the completed B002 method-family handoff remains byte-for-byte read-only. B004 applied only UID000130/UID0004NE/UID0004NF/UID0004NG, UID0002P1/UID0001Z0/UID0001TO, UID000228 nesting, and method/ABI padding plus renamed links in `by-memory/-ignored.md`. No B002-owned source-method/class/file page was edited.
- Confidence: very strong. Direct bytes, hashes, disassembly, decompilation, xrefs, RTTI, vtables, allocation sites, decorated callback types, source-template declarations, and sibling destructor policy agree. Remaining uncertainty is limited to the exact original header/file basename and why the linker retained the unreferenced ordinary destructor copy; neither affects the source contract.

## Supporting Research

- Assignment source: `tools/leaser/Agents/Agent-B004/goal.md`, followed by the supervisor-authorized implementation callback for exact Gate-1 SHA `4C69CBE5FAF738BE69B736D1701363D5F8EC9FA13D53E5017AB73000CFB4603A` under `ntk-b-agent-workflow` and Rule 26.
- Historical B004 implementation artifact SHA `E4827C20A585553566DC3DBA5EC2A2CDACFE2E94EC09BD4A62C494BF9DC136E3` records the completed implementation state before this narrow B002 coordination-pin repair. It is historical implementation evidence only, is superseded by this report-text edit, and is not asserted as a durable archived hash.
- Evidence-time tracker snapshot: `auto-generated/-ag-research-tracker.md` listed UID000130 at `86/90`, reconstructable, with zero direct reports. That is a historical queue snapshot, not a permanent classification or count assertion.
- Callback destinations reread and applied: UID000130, new UID0004NE/UID0004NF/UID0004NG, UID0002P1, UID0001Z0, UID0001TO, UID000228 nesting, and `by-memory/-ignored.md`. Completed B002 destinations UID00012X, UID0004NB, UID00012Y, UID0004NC, UID0004ND, UID0000FU, UID00012Z, and UID0000HE plus verify-only UID00000B, UID00012R, UID00012W, UID00010W, UID000197, UID0001WQ, and UID00005K were read-only. Manual coverage was compared but not edited; generated `AlertPanes.cpp` was refreshed by the validator and inspected read-only.
- At evidence collection time, MCP database `5288313d` was returned by `idb_list`; `server_health` reported `status:ok`, NexusTK IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, and ready auto-analysis, Hex-Rays, and string cache. A final health call at the end of the evidence pass remained healthy. This records evidence-time availability only.
- Executable identity: SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`; MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Exact-report searches used: `UID000130`, `UID:000130`, `000130`, `0x004a0cb0`, `0x004a0d37`, `VersatileAlertPaneDestructor`, `VersatileAlertPane destructor`, `UID00012Y`, `0x004a06e0`, `UID00012X`, `0x004a0690`, `UID0002P1`, `0x00618ba0`, `m_resultCallback`, `FunctionObjectT<unsigned long>`, `AlertPanes`, `0x005301de`, `0x0058b5c5`, `NexonclubRegistrationDialog`, and `TerminalPane`.
- `tools/leaser/Agents/Older-Research/**`: zero direct exact-target matches.
- `tools/leaser/Agents/SpecialReports/**`: zero direct exact-target matches.
- `archived/**`: zero direct exact-target matches.
- B001-B005 report roots at coordination verification time: `tools/leaser/Agents/Agent-B002/research/00012X-versatile-alert-pane-callbacks-source-quality.md`, SHA256 `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` (123,027 bytes, 1,151 lines), was the finalized active B002 coordination artifact verified before supervisor execution. Its Gate 1 and claim-by-claim Gate 2 were complete, and supervisor validator `000000010947` was complete. Earlier sequential commands `000000010827-000000010835` remain historical phase-1 validation evidence. Direct reread of the report, all eight B002 destinations, and generated `AlertPanes.cpp` confirmed the real method UIDs, scores, split, class closure, blank positions, source bodies, nesting, and disjoint B004 scope. This SHA is time-scoped to that pre-execution active artifact and is not asserted as a durable archived hash; report execution and manual coverage remain supervisor-owned.
- Central executed matches opened and classified:
  - `executed-b-agent-research/B008/00012Y-VersatileAlertPaneRawCleanup-source-quality.md`: exact no-entry/raw-byte/PE evidence; its blank-C++ conclusion is superseded by the present complete source-route analysis.
  - `executed-b-agent-research/B005/0002P1-VersatileAlertPaneVtableData-source-quality.md`: exact vtable boundaries and slot mapping; its `TRUE`/comment-emitter policy came from a pass with MCP unavailable and is superseded by current source-declared/generated-binary classification.
  - `executed-b-agent-research/B011/0000HE-AlertPanes-empty-emitter-family-source-quality.md`: current file-family grouping and historical marker policy; preserve the file score cap and unrelated Blue/Url content, but remove target-family empty/comment emitters through exact children.
  - `executed-b-agent-research/B001/000228-help-pane-singleton-close-source-quality.md`: successor-boundary evidence only; no UID000130 source-disposition claim.
  - `executed-b-agent-research/B002/00000B-alertpane-source-quality.md`: base declaration and callback-slot naming support.
  - `executed-b-agent-research/B002/0001CT-nexonclub-registration-dialog-source-quality.md`: confirms the `0x005301de` constructor route and 24-byte unsigned-long member callback object.
  - `executed-b-agent-research/B005/0001JD-TerminalPaneReconnectLeaveCallback-source-quality.md`: confirms the `0x0058b5c5` route, exact decorated unsigned-long callback type, and nonzero/zero result semantics.
- Numeric-only search hits in B015 FolderTree, B004 IconsPane, and B005 Surface reports were validator-command-id collisions (`000000000130`, `000000001300`, and related IDs), not UID000130 evidence.
- No Wave2/Wave3 evidence was used. Current docs still contain a stale Wave3 link in the family-layout history; it is historical and must not be used as evidence.

## Target

- Target UID: `000130`.
- Historical pre-callback path: `by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md`; it is absent after the one-time UID-preserving move.
- Current UID-preserved path: `by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md`.
- Source queue/report row: evidence-time tracker `86/90`, reconstructable, zero direct reports.
- Historical pre-callback metadata was `86/90`, owner/emitter UID0000FU, reconstructable true, blank position, comment-only formal block, `Nested:-4`.
- Current applied metadata is `94/97`, `CANONICAL_OWNER:0000FU`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank position, exactly blank formal block, and retained `Nested:-4`.
- Callback ownership was enforced: B002 phase 1 remained validated/generated-read-back/lease-free and byte-for-byte read-only; B004 changed only the disjoint phase-two destinations.
- Exact range: `0x004a0cb0-0x004a0d37`, 135 bytes (Verified with `tools/int_convert.py` for `0x87 -> 135`).
- Whole-range SHA256: `5171c77801d64839600ef411d68e669e165eb63561d793216ba7d4e518d13afe`.

## Current Target State

- The historical page recognized two `this`-adjustor thunks and one scalar deleting destructor but conflated compiler ABI support with source reconstruction. The current UID000130 page is a false/non-emitting ABI index with exact child links, blank formal C++, and complete behavior/no-code evidence.
- The historical destructor title is replaced by `VersatileAlertPaneDeletingDestructorAbiIsland`, matching the two vtable-entry thunks, ten `0xcc` bytes, and scalar deleting wrapper.
- Callback spelling/ownership, DialogPane base identity, UID00012Y source placement, object size, flags, split, nesting, and compiler disposition are resolved and applied.
- UID00012X remains `by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md` at `94/97`, false/non-emitting, with real exact children UID0004NB constructor, UID00012Y ordinary destructor, UID0004NC primary callback, and UID0004ND secondary callback. B004 documented its three internal alignment spans only in `by-memory/-ignored.md` without editing the B002 pages.
- UID00012Y is now the UID-preserved `by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md` at `94/96`, with exact `delete m_resultCallback;` formal source and all no-entry/unique-body history preserved.
- UID0002P1 and UID0001Z0 are now `94/97` false/non-emitting source-declared/generated-binary vtable support with blank emitter/position/formal blocks and exact ABI-child/RTTI hierarchy links. UID0001TO is now a `91/95` false/non-emitting cross-family layout audit with exact AlertPane/Versatile sizes and callback ownership.
- B004's final waited generated `AlertPanes.cpp` readback had SHA256 `3577D3E0F313E0F29FE1A5F5F41ED5054973CC88A3E270863F5D6FE31AEE2408`, header command `000000010895`, and refresh time `2026-07-14T06:38:25-04:00`. A later external refresh, command `000000010907` at `2026-07-14T06:45:33-04:00`, produced read-only SHA256 `5DF82FAE80075720C9E6CEF92A5CF7BA3EC5D0B45D5A61ECCF70F873FF1AEF1B`; target-specific assertions remained identical: exactly one `VersatileAlertPane` class and one each UID0004NB constructor, UID00012Y destructor, UID0004NC primary, and UID0004ND secondary definition; zero UID00012X, UID000130, UID0004NE, UID0004NF, UID0004NG, UID0002P1, UID0001Z0, UID0001TO, and `Empty Emitter Marker`; no ABI wrapper/vptr/size/flag body.
- At pre-execution coordination verification time, finalized active B002 SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` independently confirmed the completed four-source-method state and exclusive B004 phase-2 scope. B002 Gate 1/Gate 2 and supervisor validator `000000010947` were complete; commands `000000010827-000000010835` remain earlier phase-1 evidence, and all B002 leases were released. The time-scoped SHA is not an archived-state assertion.
- The implementation and scoped validation are complete. B004 did not edit IDA, manual coverage, generated files, tracker/audit/supervisor/validator/lifecycle state, or any B002-owned page manually. B004 did not execute, probe, move, or archive the report; external supervisor/validator lifecycle state remains authoritative.

## Executive Recommendation

- Keep UID0000FU as semantic owner and UID0000HE as source file route.
- Reclassify UID000130 and its three exact compiler children as non-reconstructable/non-emitting ABI support.
- Preserve applied UID00012X as the non-emitting method-island index and preserve exact source children UID0004NB, UID00012Y, UID0004NC, and UID0004ND without B004 edits.
- Preserve applied UID00012Y as the exact source-facing destructor page containing `delete m_resultCallback;`.
- Keep the concrete callback declaration `FunctionObjectT<unsigned long> *`; both constructor sites and decorated callback vtables prove this family and argument type.
- Emit exactly one class declaration, one constructor, one destructor, one `OnPrimaryButton`, and one `OnSecondaryButton`. Do not emit vptr stores, base-destructor calls, adjustor functions, scalar flags, operator delete calls, guard calls, RTTI, or vtable arrays.
- Keep source-emitter positions blank for constructor/destructor/primary/secondary; exact address order plus relative `Nested` deltas gives deterministic source order. Every false index/compiler/vtable/layout page also has blank emitter, position, and formal content.
- Serial boundary is complete: B002's source-method phase remained read-only and B004 applied only the target ABI/data/layout phase. No B002-owned destination changed.

## Supervisor Active Recheck

- The supervisor assigned one report-only UID000130 source-quality target and required mandatory healthy MCP. That condition was met throughout the completed evidence pass.
- The target and UID00012X both trigger split-first rules: each is an aggregate over individually understood functions and padding. Exact child work is specified now; none is deferred.
- Three B002 source-child paths remain UID0004NB, UID0004NC, and UID0004ND; existing UID00012Y is the fourth source child. B004 serially registered ABI children UID0004NE, UID0004NF, and UID0004NG and replaced every placeholder.
- Finalized active B002 coordination artifact SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0`, verified before supervisor execution, and the destination/generated readback are incorporated. Earlier coordination revisions and method placeholders are superseded history, not callback instructions; the time-scoped SHA is not claimed as a durable archived hash.
- Callback ownership remained collision-free: B002 owns the already-applied read-only source-method state; B004 completed the disjoint ABI/data/layout state. Their editable destination sets did not overlap.
- No second target was started.

## Inference Research Guidance Check

- `by-structure.md` requires every understood method/function to receive an exact by-memory page and says reviewed audit/index containers should be `RECONSTRUCTABLE:FALSE` when exact children carry source ownership.
- Direct IDA facts are kept separate from documentation evidence and inference. Bytes, hashes, instructions, xrefs, RTTI addresses, PMDs, decorated callback names, allocation sizes, and call sites are direct facts. Human names and source placement are inferences corroborated by class/file conventions.
- Existing assumptions challenged: `boost::exception`/`TransferReplyAlert` base labels, comment emitters for compiler data, `RawCleanup` as unresolved helper, broad UID00012X emission, and the claim that `FunctionObjectT<unsigned long>` call/delete spelling remained blocked.
- Concurrent-plan assumptions challenged: stable misleading slugs, marker comments on false generated-data pages, all-zero child nesting, `[[CHILDREN]]` inside the class, an unsplit compiler-function island, and overlapping B002/B004 callbacks.
- Stale Wave2/Wave3 material was ignored.

## Heuristic / Inference Reanalysis And Validation

### Target boundary and role

The target is homogeneous compiler ABI output, but its three functions must still be exact children under split-first documentation rules. The parent remains an index only. Two thunks are vtable entry points for inherited subobjects; the scalar wrapper contains the inlined source destructor semantics plus compiler delete handling. None is a separately authored human method.

### Callback type, ownership, and call spelling

Both constructor sites allocate 24 bytes for a `PlainMemberFunctionObject<void (__thiscall ...::*)(unsigned long), ...>`, initialize its callback member, zero adjustment, and object pointer, then pass it as argument 3 to `0x004a0690`. The constructor stores it at `this+0x270`. The callback vtables place the generic one-argument invoke thunk at slot `+0x0c`; the shared formal template declares `FunctionObjectT<TArg>::Invoke(TArg value)` and a virtual destructor. The pane's handlers call `Invoke(1)` and `Invoke(0)`. Both destructor copies call slot 0 with deleting flag 1, which source-level `delete m_resultCallback;` reproduces. The callers do not retain or free the callback after transfer, so the pane owns it.

Rejected callback alternatives:

- `FunctionObject *`: ABI-compatible as a conservative base, but weaker than the decorated unsigned-long type and current formal template.
- `AlertResultCallback` typedef: plausible convenience alias, but no direct symbol/header evidence proves it; use the concrete template spelling.
- `bool` parameter: the domain is boolean-like, but decorated member-function types prove `unsigned long`.
- borrowed callback pointer: rejected by the pane destructor's virtual deleting call and absence of caller cleanup.
- pane-local interface: rejected by shared FunctionObjects vtables and generic invoke/object-size slots.

### Source destructor placement

UID00012Y is the unique exact ordinary/non-deleting destructor copy. It restores three vptrs, deletes the callback, and tail-chains to `DialogPane::~DialogPane()`. Vptr stores and implicit base teardown are compiler output; the one human side effect is `delete m_resultCallback;`. No direct entry route exists, but the live scalar wrapper performs the same sequence and is installed in all three vtable views. Source semantics therefore belong on UID00012Y as the exact ordinary destructor definition, while UID000130 remains compiler ABI support. This is the same accepted distinction used by exact non-deleting destructor versus scalar-wrapper siblings elsewhere in the project.

### Base identity and teardown order

Current decompilation of `0x0049d9f0` proves IDA's `boost::exception::~exception` type is polluted. The body writes `DialogPane` vtables at `0x00618a64`, `0x00618ac4`, and `0x00618af4`; decrements `g_activeDialogCount` storage `0x0069b380`; releases the shared `0x0069ae04` object when present; removes and deletes control entries from the list at `+0x1fc`; deletes the list and clears it; tears down state at `+0x23c`; and calls ordinary Pane cleanup at `0x00544580`. The source order is: explicit `VersatileAlertPane` callback deletion, implicit trivial `AlertPane` destruction, `DialogPane` destruction, then lower Pane/GrafPort/LObject and inherited interface teardown generated by the compiler.

### RTTI and inheritance

The three COLs are `0x00646644` (offset 0), `0x006466a8` (offset `0xa0`), and `0x006466bc` (offset `0xa4`). All point to type descriptor `0x00675b80`, `.?AVVersatileAlertPane@@`, and class hierarchy descriptor `0x00646658`. The hierarchy has attributes `1`, eight entries, and base array `0x00646668`:

1. `VersatileAlertPane`, PMD mdisp `0`.
2. `AlertPane`, PMD mdisp `0`.
3. `DialogPane`, PMD mdisp `0`.
4. `Pane`, PMD mdisp `0`.
5. `GrafPort`, PMD mdisp `0`.
6. `LObject`, PMD mdisp `0`.
7. `EventHandler`, PMD mdisp `0xa0` / 160 (Verified with `tools/int_convert.py`).
8. `TimerHandler`, PMD mdisp `0xa4` / 164 (Verified with `tools/int_convert.py`).

This validates direct human inheritance `VersatileAlertPane : public AlertPane`; the secondary and tertiary views are inherited interface subobjects, not two new direct bases invented for this class.

### Object size

The scalar wrapper's flag-4 path passes size `0x274` / 628 (Verified with `tools/int_convert.py`). The only derived field is the four-byte callback at `+0x270` / 624, so `sizeof(VersatileAlertPane) == 0x274`. The shared AlertPane-family wrapper's `0x270` size and the derived-field start independently support `sizeof(AlertPane) == 0x270` for this layout. This resolves the prior family-layout size blocker for these two classes without making claims about BlueAlertPane or UrlAlertPane beyond their existing evidence.

### Split and generated-source shape

UID00012X and UID000130 are indexes after split. `[[CHILDREN]]` must follow the closing brace of the `VersatileAlertPane` class so out-of-class method definitions are structurally valid. Generated source should contain four definitions and no compiler ABI bodies/markers from the reviewed false pages.

### Rejected source alternatives

- Handwritten scalar deleting destructor: rejected as compiler ABI and duplicate source behavior.
- Handwritten adjustor methods: rejected as compiler-generated vtable entries.
- Standalone `VersatileAlertPaneRawCleanup` helper: rejected because the bytes are an ordinary destructor copy and no call contract exists.
- Emitting source from broad UID00012X or UID000130: rejected because exact children must carry each method/function disposition.
- Explicit vptr assignment, `DialogPane::~DialogPane()` call, `OperatorDeleteWrapper`, guard helper, flags, or object-size branch in source: rejected as compiler output.
- `TransferReplyAlert`, Boost, `ModelessDialogPane`, FunctionObjects, Nexonclub, or TerminalPane ownership: rejected by RTTI, vtable stores, field access, and dependency direction.

### Concurrent B002 conflict reconciliation and callback ownership

Finalized active B002 coordination artifact SHA256 `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` is the exact pre-supervisor-execution revision compared claim by claim with this report. Its method-family destinations passed Gate 1 and claim-by-claim Gate 2, supervisor validator `000000010947` completed, and generated readback passed; `000000010827-000000010835` remain historical phase-1 validator evidence. Compatible byte/behavior/source-body evidence is retained as current implementation fact. The pin is time-scoped to the finalized active coordination artifact, not asserted as a durable archived hash. The matrix distinguishes immutable B002 handoff state from the applied B004 phase-2 changes; no row averages alternatives or defers an investigable decision.

| Destination / conflict | Completed B002 phase-1 state | B004 accepted recommendation | Current unified fact / applied B004 action | Ownership / status |
| --- | --- | --- | --- | --- |
| UID00012X path, split, score | Applied `...VersatileAlertPaneMethodIsland.md`; `94/97`; FALSE/blank split index; `Nested:0`. | Same rename/index/score. | Preserve the current page byte-for-byte during B004 callback. The range contains constructor, destructor, two callbacks, and padding, so the resolved `MethodIsland` name remains correct. | B002 complete; B004 read-only |
| Constructor child | UID0004NB exists at `94/96`, blank position, `Nested:+4`, with exact formal body. | Same exact child plan with a temporary token. | Replace every former method token with UID0004NB and preserve the current page/formal body. | B002 complete; B004 read-only |
| UID00012Y path, score, body | Applied `...VersatileAlertPaneDestructor.md`; `94/96`; blank position; `Nested:0`; exact destructor body. | Same rename/body. | Preserve current UID00012Y and its no-entry provenance; no B004 edit. | B002 complete; B004 read-only |
| Primary child | UID0004NC exists at `95/97`, blank position, `Nested:0`, with exact formal body. | Same exact child plan with a temporary token. | Replace every former method token with UID0004NC and preserve the current page/formal body. | B002 complete; B004 read-only |
| Secondary child | UID0004ND exists at `95/97`, blank position, `Nested:0`, with exact formal body. | Same exact child plan with a temporary token. | Replace every former method token with UID0004ND and preserve the current page/formal body. | B002 complete; B004 read-only |
| UID00012Z nesting | Current page has `Nested:-4`; every other Modeless fact is preserved. | Same delta. | Handoff is complete; no B004 edit. | B002 complete; B004 read-only |
| UID000130 path, split, score | B002 intentionally left the old path at `86/90`, TRUE/comment-emitting because it was outside B002 scope. | Rename to `94/97` FALSE/blank ABI island with three exact children. | Renamed once with UID preserved; current page is `94/97`, FALSE, blank emitter/position/formal, and indexes UID0004NE/UID0004NF/UID0004NG. | B004 applied; validators `000000010883`, `000000010895` |
| New A0/A4/scalar children | Not registered by B002. | Three exact FALSE/blank `95/98` children. | Registered serially as UID0004NE, UID0004NF, and UID0004NG, then cross-referenced only after assignment; each is `95/98` FALSE/blank. | B004 applied; validators `000000010873-000000010875`, `000000010884-000000010886` |
| Target/successor nesting | Before B004, UID000130 was `Nested:-4`; UID000228 was `Nested:0`. | Parent `-4`, children `+4,0,0`, UID000228 `-4`. | Current deltas are parent `-4`, UID0004NE `+4`, UID0004NF `0`, UID0004NG `0`, and UID000228 `-4`; unrelated UID000228 facts are unchanged. | B004 applied |
| UID0002P1 vtable data | B002 intentionally left it at `87/92`, TRUE/comment-emitting. | `94/97` FALSE/blank. | Current page is `94/97`, FALSE, blank emitter/position/formal, with source-declared/generated-binary disposition and exact child links. | B004 applied; validator `000000010888` |
| UID0001Z0 vtable type | B002 intentionally left it at `87/92`, TRUE/comment-emitting. | `94/97` FALSE/blank. | Current page is `94/97`, FALSE, blank emitter/position/formal, with exact RTTI hierarchy and child links. | B004 applied; validator `000000010891` |
| UID0001TO layout audit | B002 intentionally left it at `85/89`, TRUE/comment-emitting. | `91/95` FALSE/blank. | Current page is `91/95`, FALSE, blank emitter/position/formal, with exact `0x270/0x274` facts. | B004 applied; validator `000000010893` |
| UID0000FU class | Current `93/96`; exact class closes before `[[CHILDREN]]`; links UID0004NB/UID00012Y/UID0004NC/UID0004ND. | Same class block. | Preserve current class/formal block; no B004 edit. | B002 complete; B004 read-only |
| UID0000HE file score | Current `85/88`, prose synchronized to the real method UIDs. | Same score and route. | Preserve current file page and unrelated family content; no B004 edit. | B002 complete; B004 read-only |
| Formal-block count/disposition | Six B002 blocks are applied: five source plus blank UID00012X. | Apply seven additional blank blocks. | Six B002 blocks remain byte-for-byte read-only; all seven B004 blocks are now blank at their destinations. Total is 13, five nonblank/eight blank. | B002 preserved; B004 applied |
| Positions | All B002 method and index positions were blank. | Keep all B004 false-page positions blank. | All target, ABI-child, vtable, and layout positions are blank; no phase-2 position was created. | Applied |
| Manual coverage | Method substitutions were exact UID0004NB/UID00012Y/UID0004NC/UID0004ND; three ABI tokens remained. | Replace tokens after serial registration. | Exact supervisor-owned row text below now uses UID0004NE/UID0004NF/UID0004NG. B004 did not edit manual coverage. | B004 report text applied; supervisor-owned coverage external |
| Generated expectation | B002 readback had one class/four methods, zero UID00012X marker, zero Empty marker, with phase-2 comments remaining. | Final no family marker after phase 2. | Waited command `000000010895` proves one class/four methods and zero UID000130, ABI-child, vtable/layout, Empty, adjustor, scalar-wrapper, flags, size, or vtable-address marker. | B004 applied and verified |
| Callback collision | Method/class/file pages are validated, generated-read-back, and lease-free. | ABI/vtable/layout/padding pages only. | B004 starts from the current read-only handoff and never edits a B002 page. | Serial boundary satisfied |
| Cross-report revision pin | Finalized active B002 coordination SHA was `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` when verified before supervisor execution. | This B004 report receives a new coordination-repair hash. | Bind technical handoff to that time-scoped pre-execution SHA and real UIDs; neither it nor historical B004 SHA `E482...136E3` is asserted as a durable archived hash. | External artifact preflight only |

The callback contract remains fixed against completed B002 phase 1. B002 excluded UID000130, UID0002P1, UID0001Z0, UID0001TO, UID000228, and `-ignored`; B004 applied only that disjoint phase-2 scope. B004 re-read the final shared pages, verified their hashes unchanged, and did not reapply or alter them. This is a completed ownership handoff and implementation, not an unresolved technical question.

## Evidence Standards Used

- Direct binary evidence: bounded MCP `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `xrefs_to`, vtable bytes, RTTI/COL/CHD/base descriptors, constructor call sites, and decorated callback vtables.
- Independent raw-image evidence: executable hashes, exact SHA256 per function/range, unique ordinary-destructor signature, no absolute VA/RVA pointer to `0x004a06e0`, and no `.text` rel32 call/jump/near-conditional route to it.
- Documentation evidence: current by-* pages, exact manual coverage rows, current generated `AlertPanes.cpp`, current FunctionObjects formal declarations, matching executed reports, and finalized active B002 coordination SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0`, time-scoped to verification before supervisor execution, reconciled section by section as the implemented phase-1 handoff.
- Inference standard: choose the narrowest late-1999 to mid-2000s human C++ that reproduces observed semantics and leaves MSVC ABI artifacts to the compiler.
- Evidence strength: sufficient for exact split, ownership, type, names, source placement, source bodies, no-code proof, and scores. It does not prove the original physical header basename or compiler version, so scores remain below 100.

## Evidence Checked

- MCP transport: initialized streamable JSON-RPC endpoint `http://127.0.0.1:13337/mcp`; refreshed `tools/list`; used database `5288313d` on every IDB call.
- Health and real probes: `idb_list`, `server_health`, `lookup_funcs`, and bounded `get_bytes` succeeded; final health remained `status:ok` at evidence time.
- Target functions: lookups/disassembly/decompilation for `0x004a0cb0`, `0x004a0cbb`, `0x004a0cd0`; predecessor/successor probes at `0x004a0ca0`, `0x004a0d37`, and `0x004a0d40`.
- Source siblings: constructor `0x004a0690`, ordinary destructor bytes `0x004a06e0`, callbacks `0x004a0720` and `0x004a0740`, base teardown `0x0049d9f0`, operator-delete wrapper `0x004f4ac0`, and guard no-op `0x0041b6a0`.
- Call sites: containing functions `0x00530060` and `0x0058b470`; callback targets `0x00530020` and `0x0058b620`; callback vtables `0x00620184` and `0x0062dde8`.
- Xrefs: target three entries, all three class vtable bases, constructor, callbacks, and raw destructor entry.
- RTTI: vtable-adjacent words `0x00618ba0`, `0x00618c08`, `0x00618c38`; COLs `0x00646644`, `0x006466a8`, `0x006466bc`; type descriptor `0x00675b80`; CHD/base array and all eight base descriptors.
- Raw PE negative checks: no absolute VA `0x004a06e0`, no RVA `0x000a06e0`, and no E8/E9/0F8x rel32 route in `.text`; exact 53-byte ordinary destructor signature appears once at raw offset `0x9fae0`.
- Docs and reports: concrete paths and findings are listed under Supporting Research.
- Completed-artifact reconciliation: opened the complete 1,151-line finalized active B002 coordination report at SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` before supervisor execution; compared its Finalized state, ledger, inventory, split, all 13 formal blocks, Final/Target/Support, score, Callback Ownership And Order, coverage, generated proof, Changed Files, validators, and checklist against this report; then reread UID00012X, UID0004NB, UID00012Y, UID0004NC, UID0004ND, UID0000FU, UID00012Z, UID0000HE, every B004 destination before and after its bounded edit, and final generated `AlertPanes.cpp`. The SHA is evidence-time coordination provenance, not an archived-state claim.
- Handoff validation evidence: supervisor-provided exact-artifact Gate 1, claim-by-claim Gate 2, and supervisor validator `000000010947` establish completed B002 coordination validation; commands `000000010827-000000010835` remain historical phase-1 evidence. Historical phase-1 generated header `000000010833` independently confirmed the one-class/four-method handoff and the then-expected remaining B004 markers; final B004 and later external readbacks are recorded below. Report execution and manual coverage remain external supervisor-owned state.
- Manual coverage inspected read-only: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-type/by-vtable/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md`.
- Callback boundary: no IDA mutation or type application occurred. The authorized by-* renames/edits, short leases, scoped validators, and one waited generated refresh are recorded below. B004 ran no report execute, probe, move, archive, or other lifecycle command.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time MCP database `5288313d` was healthy and IDB-backed calls succeeded. | very high | `idb_list`, `server_health`, lookup/get-bytes probes | all changed evidence sections | incorporate | applied |
| C02 | NexusTK image SHA256/MD5 are exact as recorded. | very high | `Get-FileHash` read-only | UID000130, UID0004NE, UID0004NF, UID0004NG | incorporate | applied |
| C03 | UID000130 range is 135 bytes with SHA256 `5171...3afe`. | very high | MCP bytes, local SHA256 | renamed UID000130; validators `000000010883`, `000000010895` | incorporate | applied |
| C04 | Predecessor ends `0x004a0c8e`; `66 90` and 32-byte switch table end exactly at target start. | very high | lookup/bytes/current ignored doc | UID000130 and `by-memory/-ignored.md`; validators `000000010895`, `000000010894` | incorporate | applied |
| C05 | `0x004a0cb0-0x004a0cbb` subtracts `0xa0` and jumps to scalar wrapper; hash `2b7d...3e89`. | very high | disasm/bytes/xref | UID0004NE; validators `000000010873`, `000000010884` | incorporate | applied |
| C06 | `0x004a0cbb-0x004a0cc6` subtracts `0xa4` and jumps to scalar wrapper; hash `016c...b0a`. | very high | disasm/bytes/xref | UID0004NF; validators `000000010874`, `000000010885` | incorporate | applied |
| C07 | `0x004a0cc6-0x004a0cd0` is ten `0xcc` bytes; hash `22e5...f045`. | very high | MCP bytes | UID000130 and `by-memory/-ignored.md`; validators `000000010895`, `000000010894` | incorporate | applied |
| C08 | `0x004a0cd0-0x004a0d37` is a 103-byte thiscall scalar deleting wrapper; hash `a1c6...d5ad`. | very high | lookup/disasm/bytes | UID0004NG; validators `000000010875`, `000000010886` | incorporate | applied |
| C09 | Scalar wrapper restores class vtables at offsets 0, `0xa0`, `0xa4`. | very high | disasm/xrefs | UID0004NG, UID0002P1, UID0001Z0 | incorporate | applied |
| C10 | Scalar wrapper deletes callback at `+0x270` through virtual slot 0 with flag 1 before base teardown. | very high | disasm/decompile | UID0004NG; source cause UID00012Y retained read-only | incorporate | applied |
| C11 | `0x0049d9f0` is `DialogPane::~DialogPane()` behavior, not Boost/TransferReply. | very high | current decompile, DialogPane docs | UID000130/UID0004NG evidence; no dependency edit required | reject-stale | excluded-with-reason |
| C12 | When flag bit 0 is clear, wrapper returns `this` without freeing. | very high | disasm | UID0004NG | incorporate | applied |
| C13 | When bit 0 is set and mask 4 clear, wrapper calls UID000197 OperatorDeleteWrapper with `this`. | very high | disasm/callee doc | UID0004NG | incorporate | applied |
| C14 | Mask-4 branch passes `this` and size `0x274` to compiler guard path; source must not hand-code it. | very high | disasm | UID0004NG and UID0001TO | incorporate | applied |
| C15 | All scalar paths return complete-object `this` and consume one stack flags argument with `ret 4`. | very high | disasm | UID0004NE/UID0004NF/UID0004NG | incorporate | applied |
| C16 | Target liveness is exactly three vtable routes: primary scalar and two adjusted slots; no ordinary callers. | very high | `xrefs_to` | UID000130, ABI children, UID0002P1, UID0001Z0 | incorporate | applied |
| C17 | Three COLs share `VersatileAlertPane` type/CHD and encode offsets 0, `0xa0`, `0xa4`. | very high | RTTI bytes | UID000130, ABI children, UID0002P1, UID0001Z0 | incorporate | applied |
| C18 | RTTI hierarchy is VersatileAlertPane, AlertPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler with interface PMDs `0xa0/0xa4`. | very high | CHD/base descriptors | UID000130, UID0002P1, UID0001Z0, UID0001TO | incorporate | applied |
| C19 | Constructor exact range/hash and argument forwarding are resolved and applied on UID0004NB. | very high | current UID0004NB, disasm/decompile/bytes | B002 read-only constructor child UID0004NB | already-present | already-present |
| C20 | Two constructor sites allocate 628-byte pane and 24-byte unsigned-long callback objects; current class/method docs preserve both. | very high | current UID0004NB/UID0000FU/UID0000HE and caller evidence | B002 read-only constructor/class/file | already-present | already-present |
| C21 | UID0004NC `OnPrimaryButton` exact range/hash invokes callback slot `+0x0c` with 1. | very high | current UID0004NC/decompile/bytes/vtable ref | B002 read-only primary child | already-present | already-present |
| C22 | UID0004ND `OnSecondaryButton` exact range/hash invokes callback slot `+0x0c` with 0. | very high | current UID0004ND/decompile/bytes/vtable ref | B002 read-only secondary child | already-present | already-present |
| C23 | UID00012Y exact 53-byte body/hash is unique, has no IDA/PE entry route, and is applied at the corrected destructor path. | very high | current UID00012Y, bytes/hash/xrefs/raw scan | B002 read-only UID00012Y | already-present | already-present |
| C24 | UID00012Y is the applied source ordinary destructor carrier; no standalone raw helper. | high | current formal body, scalar mirror, source policy, unique body | B002 read-only UID00012Y/class | already-present | already-present |
| C25 | `m_resultCallback` is owned `FunctionObjectT<unsigned long> *`; current source operations are `Invoke(1/0)` and `delete`. | very high | current class/four source children, decorated types/template/call sites | B002 read-only class/method pages | already-present | already-present |
| C26 | Applied human names are constructor, destructor, `OnPrimaryButton`, and `OnSecondaryButton`. | very high | current pages, RTTI/base declaration/vtable slots | B002 read-only class/source children | already-present | already-present |
| C27 | Source placement remains applied through UID0000HE to `NexusTK/ui/dialogs/AlertPanes.cpp/.h`. | high | current class/file/generated route | B002 read-only class/file/source children | already-present | already-present |
| C28 | UID000130 becomes non-emitting index and receives three exact children. | very high | by-structure split rules | renamed UID000130 plus UID0004NE/UID0004NF/UID0004NG | incorporate | applied |
| C29 | Target child Nested deltas are `+4,0,0`; successor UID000228 becomes `-4`. | very high | validator README relative-delta rule/current cumulative nesting | UID0004NE/UID0004NF/UID0004NG and UID000228; validators `000000010884-000000010887` | incorporate | applied |
| C30 | UID00012X is the applied renamed non-emitting method-island index with real children UID0004NB/UID00012Y/UID0004NC/UID0004ND. | very high | current pages and exact ranges | B002 read-only method family | already-present | already-present |
| C31 | Applied method-island Nested deltas are constructor `+4`, UID00012Y `0`, primary `0`, secondary `0`; UID00012Z is `-4`; all source positions are blank. | very high | current headers, validator relative-delta rule, address ordering | B002 read-only method children/UID00012Z | already-present | already-present |
| C32 | Current UID0000FU closes before `[[CHILDREN]]`, and generated definitions are outside the declaration. | very high | current class block and generated readback | B002 read-only UID0000FU | already-present | already-present |
| C33 | Exact constructor/destructor/callback formal definitions are applied on UID0004NB/UID00012Y/UID0004NC/UID0004ND. | high | current four source pages/generated output | B002 read-only source children | already-present | already-present |
| C34 | UID00012X has its required blank formal block; target parent, three ABI children, vtable pages, and layout page have the seven B004 blank blocks. | very high | compiler/index/no-standalone disposition and literal destination readback | B002 read-only UID00012X; seven B004 destinations | incorporate | applied |
| C35 | UID0002P1 and UID0001Z0 are source-declared/generated-binary and false/non-emitting. | very high | RTTI/vtable source cause | UID0002P1 validator `000000010888`; UID0001Z0 validator `000000010891` | incorporate | applied |
| C36 | UID0001TO is a false/non-emitting audit and records exact AlertPane/Versatile sizes. | high | size constants/layout fields/container rule | UID0001TO validator `000000010893` | incorporate | applied |
| C37 | UID0000HE remains `85/88` and already contains the resolved Versatile source route without unrelated file inflation. | high | current broad file page | B002 read-only UID0000HE | already-present | already-present |
| C38 | UID0001WQ/UID00005K and DialogPane/OperatorDelete support already provide required declarations/roles. | very high | current formal/docs | read-only support pages | already-present | already-present |
| C39 | Boost, TransferReply, Modeless, FunctionObjects owner, feature consumer owner, pane-local interface, borrowed callback, bool signature, and handwritten ABI alternatives are rejected. | very high | direct negative evidence | target/support evidence; no rejected-owner destination edit | reject-invalid | excluded-with-reason |
| C40 | Finalized active B002 coordination SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0`, time-scoped to verification before supervisor execution, real method UIDs, completed Gate 1/Gate 2 and supervisor validator `000000010947`, and generated handoff are reconciled claim by claim; older B002/B005/B008/B011 material remains labeled history. | very high | finalized active B002 coordination artifact/destinations/generated output and conflict matrix | report and callback boundary | already-present | already-present |
| C41 | Target score moves `86/90 -> 94/97`; each ABI child is `95/98`. | high | exhaustive exact evidence | UID000130, UID0004NE, UID0004NF, UID0004NG | incorporate | applied |
| C42 | Current method parent is `94/97`; UID0004NB/UID00012Y are `94/96`; UID0004NC/UID0004ND are `95/97`; class is `93/96`; all true method emitter positions are blank. | high | current B002 method/class pages and generated output | B002 read-only method/class pages | already-present | already-present |
| C43 | Vtable pages are `94/97` and layout is `91/95`; no support score was inflated without direct new evidence. | high | RTTI/layout resolution | UID0002P1, UID0001Z0, UID0001TO | incorporate | applied |
| C44 | Exact manual coverage replacement text now contains real B002 method and B004 ABI UIDs; B004 did not edit the supervisor-owned coverage files. | very high | assigned UIDs, destination readback, manual-row comparison | report coverage text only | incorporate | applied |
| C45 | Final waited generated readback proves one class/four source definitions and no UID000130, ABI-child, vtable/layout, Empty, adjustor, scalar-wrapper, flags, size, or vtable-address marker. | high | command `000000010895`, SHA256 `3577D3E0F313E0F29FE1A5F5F41ED5054973CC88A3E270863F5D6FE31AEE2408` | generated verification, read-only | incorporate | applied |
| C46 | No investigable target, handoff, concurrent-callback, implementation, validator, generated, or lease blocker remains; original-file/header and retained-copy provenance limit only final certainty. | high | evidence/conflict matrices/current destinations/validators/generated readback | report/open questions/callback completion | incorporate | applied |

## Positive Evidence Summary

- Exact target bytes split cleanly into two 11-byte thunks, ten padding bytes, and one 103-byte scalar wrapper.
- All three modeled functions are live through the three `VersatileAlertPane` vtable views.
- Constructor, ordinary destructor copy, and scalar wrapper write the same vtables and use the same callback field.
- Two independent construction sites prove 628-byte pane allocation, 24-byte concrete unsigned-long callback objects, ownership transfer, and feature-independent reuse.
- RTTI proves class name, direct base chain, and adjusted interface offsets.
- Current FunctionObjects formal source proves exact `Invoke` and destructor vocabulary.
- The unique ordinary destructor body and scalar mirror jointly support one human destructor definition.
- Completed B002 phase 1 and the applied B004 phase 2 independently converge on the four source bodies and source owner; the conflict matrix preserves compatible binary evidence while separating read-only method state from compiler-only ABI work.
- `by-structure.md` directly resolves the unsplit-ABI and generated-marker disputes: understood functions require exact pages, reviewed audit/compiler containers are false, and false pages cannot retain emitters, positions, or comment code.
- Validator ordering rules and current generated readback resolve the position dispute: all four emitting methods use blank positions because exact by-memory address order plus relative `Nested` deltas deterministically describes source hierarchy.

## IDA MCP Facts

### Function and byte facts

| Range | Size | Exact bytes / SHA256 | Role |
| --- | ---: | --- | --- |
| `0x004a0cb0-0x004a0cbb` | 11 | `81 e9 a0 00 00 00 e9 15 00 00 00`; `2b7d74d928201d21275293d84a56304c6f048b11f07c04fc4914686438863e89` | `this-0xa0` adjustor thunk |
| `0x004a0cbb-0x004a0cc6` | 11 | `81 e9 a4 00 00 00 e9 0a 00 00 00`; `016c96a3c590b116d9151540acd9761aac37b32ff432215103036c2739105b0a` | `this-0xa4` adjustor thunk |
| `0x004a0cc6-0x004a0cd0` | 10 | ten `cc`; `22e52bba61da8ad6732be550205a10b89a1bb3b0ea491be07de9294f0eb6f045` | compiler alignment |
| `0x004a0cd0-0x004a0d37` | 103 | SHA256 `a1c61b3b708277f95eec87a3ca4d4fb00991d71a31070733c7dfcb6fa3c5d5ad` | scalar deleting destructor |
| `0x004a0690-0x004a06d7` | 71 | SHA256 `032181f46138d60c37f3cc0b4ebfe109c2ff73f6058438da387411b29e66b33e` | source constructor |
| `0x004a06e0-0x004a0715` | 53 | SHA256 `63b15ae95d640c3cb7a16d3ddd866cd8e68aad835102c6f4c0f66c20b6d3968d` | ordinary destructor copy |
| `0x004a0720-0x004a0732` | 18 | SHA256 `e33512ed2a23e0c009bc814b721bbc339462cd02dba96a824c77ed47b3834e61` | primary callback |
| `0x004a0740-0x004a0752` | 18 | SHA256 `4644625d04c8bd5a7d3a3ebce6f672027a44bc6742e80c33c461bfc297a24cf3` | secondary callback |

Exact 135-byte target payload (`0x004a0cb0-0x004a0d37`), read from healthy MCP database `5288313d`:

```text
81 e9 a0 00 00 00 e9 15 00 00 00 81 e9 a4 00 00
00 e9 0a 00 00 00 cc cc cc cc cc cc cc cc cc cc
55 8b ec 56 8b f1 8b 8e 70 02 00 00 c7 06 a4 8b
61 00 c7 86 a0 00 00 00 0c 8c 61 00 c7 86 a4 00
00 00 3c 8c 61 00 85 c9 74 06 8b 01 6a 01 ff 10
8b ce e8 e9 cc ff ff 8b 45 08 a8 01 74 22 a8 04
75 10 56 e8 a8 3d 05 00 83 c4 04 8b c6 5e 5d c2
04 00 68 74 02 00 00 56 e8 73 a9 f7 ff 83 c4 08
8b c6 5e 5d c2 04 00
```

The payload has 135 byte tokens and hashes to `5171c77801d64839600ef411d68e669e165eb63561d793216ba7d4e518d13afe`.

### Scalar wrapper instruction facts

- ECX is complete-object `this`; stack argument at `[ebp+8]` is deleting flags; `ret 4` consumes it.
- Callback pointer is loaded from `this+0x270` before vptr stores.
- Vptr stores are primary `0x00618ba4`, secondary `0x00618c0c`, tertiary `0x00618c3c`.
- Non-null callback receives virtual deleting call slot 0 with argument 1.
- Base call is `0x0049d9f0`.
- Flags mask 1 controls storage deletion. Mask 4 selects guarded size path rather than ordinary `0x004f4ac0` free.
- Guard path size is `0x274`; every return yields original complete-object `this` in EAX.

### Data, padding, and boundary facts

- Predecessor function `0x004a0840-0x004a0c8e` ends before `66 90` and switch table `0x004a0c90-0x004a0cb0`.
- Target begins exactly at `0x004a0cb0`; no overlap with jump-table data.
- Internal padding is exactly `0x004a0cc6-0x004a0cd0`.
- Target ends exactly at scalar `ret 4` byte range `0x004a0d30-0x004a0d37`.
- Successor padding is nine `0xcc` bytes `0x004a0d37-0x004a0d40`; HelpPane helper starts `0x004a0d40`.
- Method-island internal padding is `0x004a06d7-0x004a06e0` (9 `cc`), `0x004a0715-0x004a0720` (11 `cc`), and `0x004a0732-0x004a0740` (14 `cc`).

### Vtable, RTTI, and negative facts

- Primary `0x00618ba4` slot 0 -> scalar wrapper.
- Secondary `0x00618c0c` slot 0 -> A0 thunk.
- Tertiary `0x00618c3c` slot 0 -> A4 thunk; slot 1 remains inherited `0x00544e90`.
- Constructor, ordinary destructor, and scalar wrapper each produce one store xref to each vtable address point.
- Raw destructor entry `0x004a06e0` has zero MCP xrefs, zero absolute VA/RVA hits, and zero filtered `.text` rel32 routes; exact body occurs once.
- Callbacks have data-only vtable refs at `0x00618c00` and `0x00618c04`; virtual liveness is proven despite zero ordinary code callers.

## Function / Child Inventory

All source-method and ABI-child rows now use their real validator-assigned UIDs. The former ABI registration placeholders were replaced everywhere after serial assignment.

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a0690-0x004a0752` | UID00012X / `...VersatileAlertPaneMethodIsland.md` | non-emitting split index | FALSE | UID0000FU | `94/97` | Applied B002 state; B004 read-only |
| `0x004a0690-0x004a06d7` | UID0004NB / `...VersatileAlertPaneConstructor.md` | source constructor | TRUE | UID0000FU | `94/96` | Applied B002 state; blank position; `Nested:+4`; B004 read-only |
| `0x004a06e0-0x004a0715` | UID00012Y / `...VersatileAlertPaneDestructor.md` | source ordinary destructor | TRUE | UID0000FU | `94/96` | Applied B002 state; blank position; `Nested:0`; B004 read-only |
| `0x004a0720-0x004a0732` | UID0004NC / `...VersatileAlertPaneOnPrimaryButton.md` | source override | TRUE | UID0000FU | `95/97` | Applied B002 state; blank position; `Nested:0`; B004 read-only |
| `0x004a0740-0x004a0752` | UID0004ND / `...VersatileAlertPaneOnSecondaryButton.md` | source override | TRUE | UID0000FU | `95/97` | Applied B002 state; blank position; `Nested:0`; B004 read-only |
| `0x004a0cb0-0x004a0d37` | UID000130 / `...VersatileAlertPaneDeletingDestructorAbiIsland.md` | non-emitting ABI index | FALSE | UID0000FU | `94/97` | Applied B004 rename/reclassification; blank position; `Nested:-4` |
| `0x004a0cb0-0x004a0cbb` | UID0004NE / `...VersatileAlertPaneDestructorAdjustorThunkA0.md` | compiler adjustor | FALSE | UID0000FU | `95/98` | Applied B004 child; blank position; `Nested:+4` |
| `0x004a0cbb-0x004a0cc6` | UID0004NF / `...VersatileAlertPaneDestructorAdjustorThunkA4.md` | compiler adjustor | FALSE | UID0000FU | `95/98` | Applied B004 child; blank position; `Nested:0` |
| `0x004a0cd0-0x004a0d37` | UID0004NG / `...VersatileAlertPaneScalarDeletingDestructor.md` | compiler scalar wrapper | FALSE | UID0000FU | `95/98` | Applied B004 child; blank position; `Nested:0` |
| class | UID0000FU `VersatileAlertPane` | declaration/source owner | TRUE | UID0000HE | `93/96` | Applied B002 state; exact block/details; B004 read-only |
| `.rdata` | UID0002P1 / UID0001Z0 | generated vtable support | FALSE | UID0000FU | `94/97` each | Applied B004 false/blank disposition |
| layout audit | UID0001TO | cross-family evidence only | FALSE | UID0000HE | `91/95` | Applied B004 false/blank disposition and size facts |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004a0cb0` | data xref `0x00618c0c` only | live secondary destructor slot |
| `0x004a0cbb` | data xref `0x00618c3c` only | live tertiary destructor slot |
| `0x004a0cd0` | code refs `0x004a0cb6`, `0x004a0cc1`; data ref `0x00618ba4` | live primary scalar wrapper plus adjusted entries |
| `0x004a0cd0` callees | indirect callback slot 0; `0x0049d9f0`; `0x004f4ac0`; `0x0041b6a0` | callback delete, base teardown, ordinary free, guarded compiler path |
| `0x004a0690` | calls at `0x005301de`, `0x0058b5c5` | independent Nexonclub and Terminal construction routes |
| `0x004a0720` | data xref `0x00618c00` only | virtual primary result path |
| `0x004a0740` | data xref `0x00618c04` only | virtual secondary result path |
| `0x004a06e0` | no direct xref/absolute pointer/rel32 route | retained ordinary destructor copy, not dead semantics |
| `0x005301de` | allocates 628-byte pane; passes 24-byte `PlainMemberFunctionObject<NexonclubRegistrationDialog,unsigned long>` | provider transfers callback ownership |
| `0x0058b5c5` | allocates 628-byte pane; passes 24-byte `PlainMemberFunctionObject<TerminalPane,unsigned long>` | second provider and result-liveness proof |
| `0x00530020` | concrete callback ignores result, clears pending alert state | unsigned-long callback target |
| `0x0058b620` | nonzero schedules reconnect; zero requests exit | validates 1/0 semantics |

## Documentation Evidence And IDA Status

- Correct current docs: vtable bases/slots, callback offset, class/file route, FunctionObjects declarations, DialogPane teardown identity, operator-delete wrapper, and source-facing callback override names.
- Previously stale B004-scope docs are corrected: target, ABI children, vtable pages, family layout audit, UID000228 nesting, and method/ABI padding rows now carry the accepted state. Manual supervisor-owned coverage remains read-only and its exact replacement text appears below. The B002 method/class/file docs remain current and read-only.
- Completed B002 status: current binary/source facts and synchronized method plan are applied under real UIDs. Explicitly labeled pre-coordination stable slugs, all-zero child nesting, lower scores, in-class `[[CHILDREN]]`, and overlapping ownership remain superseded history; they are not current instructions.
- Current IDA label pollution: `0x0049d9f0` still decompiles as `boost::exception::~exception`, but its body and all current DialogPane docs disprove that source identity.
- Generated output is read-only verification material. Waited command `000000010895` contains exactly the four method definitions and none of the former B004 UID000130/UID0002P1/UID0001Z0/UID0001TO or ABI-child markers.

## Ranked Ownership Analysis

### 1. UID0000FU VersatileAlertPane

- Evidence for: exact RTTI class name; all three vtable stores; callback member offset; constructor and method behavior; scalar/ordinary destructor mirror; class declaration; shared source route.
- Evidence against: none for semantic ownership. Compiler pages still must have blank emitters.
- Decision: retain as canonical owner for target parent, ABI children, method children, vtable pages, and human source definitions.

### 2. UID0000HE AlertPanes

- Evidence for: established shared modal-alert source family, class parent route, generated path, and generic use from unrelated Nexonclub/Terminal features.
- Evidence against: file page is broader than this class and exact original basename remains inferred.
- Decision: retain as file emitter/source placement, not direct method owner.

### 3. UID0001WQ / UID0000JO FunctionObjects

- Evidence for: owns callback base/templates and concrete invoke/destructor ABI.
- Evidence against: does not own pane object, field lifetime decision, vtables, or result semantics.
- Decision: dependency only; reject direct ownership.

### 4. Feature consumers and inherited bases

- Evidence for: Nexonclub/Terminal allocate callbacks; AlertPane/DialogPane provide base behavior.
- Evidence against: consumers provide callbacks but do not implement the generic pane; bases do not own derived field/vtables.
- Decision: reject direct ownership.

### Applied new file/grouping, if applicable

- No new source file. Use existing `NexusTK/ui/dialogs/AlertPanes.cpp` and header route.
- New pages are exact by-memory children only, not new source modules.

## Source Placement

- Recommended source class: `VersatileAlertPane`.
- Recommended source module: `NexusTK/ui/dialogs/AlertPanes.cpp`, declaration in the corresponding AlertPanes header.
- Dependency: FunctionObjects declaration providing `FunctionObjectT<unsigned long>` and `Invoke`.
- Feature construction remains in NexonclubRegistrationDialog and TerminalPane modules.
- Rejected placements: FunctionObjects, NexonclubRegistrationDialog, TerminalPane, ModelessDialogPane, DialogPane, Boost, raw ABI helper source, and one-class-per-file split.
- Remaining placement uncertainty: exact original basename/header split is inferred, not symbol-proven; the established project path is still the highest-probability source family.
- Callback placement ownership: B002 phase 1 applied the source-bearing class/method/file route. B004 phase 2 documented compiler ABI/vtable regeneration without altering source placement or B002 pages.

## Range / Split / Padding / Reclassification Analysis

### UID00012X method island

- Current path is `0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md`.
- Parent is `Nested:0`, false/non-emitting, and indexes exact children UID0004NB, UID00012Y, UID0004NC, and UID0004ND.
- Current child order/deltas: UID0004NB constructor `Nested:4`; UID00012Y destructor `Nested:0`; UID0004NC primary `Nested:0`; UID0004ND secondary `Nested:0`.
- All four method emission positions remain blank. Exact by-memory address order plus the relative `Nested` sequence deterministically orders constructor, destructor, primary, and secondary definitions.
- UID00012Z ModelessDialogPane is already `Nested:-4`, closing the method children before its own children begin.
- Internal alignment is recorded in `-ignored`, not made into source pages.
- B002 completed the method parent/children/UID00012Y/UID00012Z phase and allocated real UIDs 0004NB/0004NC/0004ND. B002 did not edit `by-memory/-ignored.md`; B004 adds all family padding using these now-stable method paths and UIDs.

### UID000130 ABI island

- Renamed once to `0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md`; old path is absent and UID000130 remains unique.
- Retain parent `Nested:-4`; it already closes UID00012Z's children and returns to top level.
- Child order/deltas: A0 thunk `Nested:4`; A4 thunk `Nested:0`; scalar wrapper `Nested:0`.
- All target parent/children positions remain blank because all four pages are false/non-emitting.
- UID000228 HelpPaneSingletonCloseHelpers changed `Nested:0 -> -4` to close target children; all other content stayed unchanged.
- Internal `0x004a0cc6-0x004a0cd0` padding is ignored/compiler alignment.
- B004 applied this complete phase-2 edit set after serially allocating UID0004NE, UID0004NF, and UID0004NG; the required phase-1 rebase remained unchanged.

### Reclassification

- UID00012X and UID000130 are false audit/index pages.
- Source children are constructor, ordinary destructor, and two callbacks.
- ABI children, UID0002P1, UID0001Z0, and UID0001TO are false/non-emitting.
- The B002 method placeholders are validator-assigned UID0004NB/UID0004NC/UID0004ND; the B004 ABI placeholders are validator-assigned UID0004NE/UID0004NF/UID0004NG. No placeholder remains.
- UID0002P1/UID0001Z0/UID0001TO belonged to B004's compiler-support phase and now carry the accepted false generated/layout disposition.

## Negative Evidence Summary

- No direct call, pointer, or rel32 route reaches the ordinary destructor copy.
- No direct code caller reaches either virtual callback or target ABI entry; vtable data proves liveness.
- No caller retains callback cleanup ownership after construction.
- No binary evidence supports a pane-specific callback interface, bool callback ABI, or borrowed pointer.
- No RTTI or vtable evidence supports Boost, TransferReplyAlert, or Modeless ownership.
- No source-level reason exists to hand-author vptr resets, adjustor thunks, scalar flags, size/guard branches, RTTI, or vtable dwords.
- Consumer xrefs prove use, not ownership; Nexonclub and Terminal remain construction contexts.
- Address proximity to ModelessDialogPane does not override exact switch-table/RTTI boundaries.
- No evidence or workflow rule supports concurrent B002/B004 edits. Completed B002 pages are lease-free read-only handoff state; superseded pre-coordination overlap is retained only as rejected history.

## IDA Rename / Type / Comment Recommendations

- Source-facing names: `VersatileAlertPane::VersatileAlertPane`, `VersatileAlertPane::~VersatileAlertPane`, `VersatileAlertPane::OnPrimaryButton`, `VersatileAlertPane::OnSecondaryButton`, and `m_resultCallback`.
- Type: `FunctionObjectT<unsigned long> *m_resultCallback` at `+0x270`.
- Descriptive compiler child names: `VersatileAlertPaneDestructorAdjustorThunkA0`, `VersatileAlertPaneDestructorAdjustorThunkA4`, and `VersatileAlertPaneScalarDeletingDestructor`.
- Base target `0x0049d9f0`: source identity `DialogPane::~DialogPane()` / ordinary DialogPane teardown; reject current Boost prototype.
- No IDA DB edits are requested or permitted. These are documentation/source recommendations only.

## First-Draft C++ Recommendation

- Eligible source emitters are already applied and read-only: UID0000FU plus UID0004NB, UID00012Y, UID0004NC, and UID0004ND, all with blank positions and deterministic address order.
- Ineligible: both aggregate parents, all three ABI children, UID0002P1, UID0001Z0, and UID0001TO.
- The following 13 complete managed blocks are exact destination text. Five nonblank source blocks plus blank UID00012X were applied by B002 and remain immutable handoff proof. The seven B004 phase-2 blocks (UID000130, UID0004NE, UID0004NF, UID0004NG, UID0002P1, UID0001Z0, UID0001TO) are applied and deliberately blank after exhaustive no-code proof.

### Applied B002 phase 1 - UID0000FU `by-class/VersatileAlertPane.md` (B004 read-only)

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class VersatileAlertPane : public AlertPane
{
public:
    VersatileAlertPane(const wchar_t *messageText,
                       Pane *layoutReference,
                       FunctionObjectT<unsigned long> *resultCallback,
                       const wchar_t *primaryButtonText,
                       const wchar_t *secondaryButtonText);
    virtual ~VersatileAlertPane();

protected:
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

private:
    FunctionObjectT<unsigned long> *m_resultCallback;
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B002 phase 1 - UID0004NB `by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md`, blank position (B004 read-only)

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
VersatileAlertPane::VersatileAlertPane(
    const wchar_t *messageText,
    Pane *layoutReference,
    FunctionObjectT<unsigned long> *resultCallback,
    const wchar_t *primaryButtonText,
    const wchar_t *secondaryButtonText)
    : AlertPane(messageText,
                layoutReference,
                primaryButtonText,
                secondaryButtonText),
      m_resultCallback(resultCallback)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B002 phase 1 - UID00012Y `by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md`, blank position (B004 read-only)

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
VersatileAlertPane::~VersatileAlertPane()
{
    delete m_resultCallback;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B002 phase 1 - UID0004NC `by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md`, blank position (B004 read-only)

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void VersatileAlertPane::OnPrimaryButton()
{
    if (m_resultCallback != NULL)
        m_resultCallback->Invoke(1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B002 phase 1 - UID0004ND `by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md`, blank position (B004 read-only)

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void VersatileAlertPane::OnSecondaryButton()
{
    if (m_resultCallback != NULL)
        m_resultCallback->Invoke(0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B002 phase 1 - UID00012X `by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md` (B004 read-only)

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B004 phase 2 - UID000130 `by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B004 phase 2 - UID0004NE `by-memory/0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B004 phase 2 - UID0004NF `by-memory/0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B004 phase 2 - UID0004NG `by-memory/0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B004 phase 2 - UID0002P1 `by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B004 phase 2 - UID0001Z0 `by-type/by-vtable/VersatileAlertPaneVtables.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Applied B004 phase 2 - UID0001TO `by-type/by-struct/AlertPaneLayout.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact no-code proof: these eight pages are indexes, compiler ABI functions, generated RTTI/vtables, or a cross-family layout audit. None is an original standalone function/object/source unit. Their complete source causes are the class declaration and four method definitions. Nonblank comments would retain false emitters and obscure generated verification; decompiler-shaped bodies would duplicate or expose compiler internals.
- Current B002 formal, validator, generated, and checklist sections prove that the six method/class blocks are applied, all source positions are blank, and `[[CHILDREN]]` follows the class closing brace. B004 applied the seven exclusive blank blocks without altering those six; older incompatible text remains historical only.
- Behavior preservation: C++ `delete` reproduces null check, virtual deleting call, and ownership transfer; virtual callback calls reproduce slot `+0x0c`; inheritance causes vptr/RTTI/thunk/base teardown regeneration; object allocation remains at callers.
- Source-shape fit: ordinary VC6/VC7-era class, initializer list, virtual methods, raw owning callback pointer, `NULL`, and no C++11 syntax.

## Final Recommendation

- Preserve C01-C46 without compression under the completed handoff and collision-free ownership plan.
- Completed phase 1, read-only for B004: B002 renamed UID00012X/UID00012Y; registered UID0004NB/UID0004NC/UID0004ND; retained blank positions; applied method `Nested` deltas, UID00012Z close, UID0000FU class closure, and UID0000HE prose at unchanged `85/88`; then validated, generated-read-back, and released every lease.
- Applied phase 2, B004 only: renamed UID000130; registered UID0004NE/UID0004NF/UID0004NG; applied ABI `Nested` deltas, UID000228 close, UID0002P1/UID0001Z0/UID0001TO false/blank disposition, and all method/ABI padding plus renamed links. B004 replaced all three ABI placeholders and did not edit the completed method pages.
- Emit exactly four method definitions through UID0000FU and retain one class declaration with class closure before `[[CHILDREN]]`.
- Reclassify all compiler/index/vtable/layout support as false/non-emitting and blank their emitter, position, and formal blocks.
- Preserve existing direct owner/file route and all unrelated AlertPanes content/scores. B004 verifies phase-1 output but does not edit it; B002 does not edit phase-2 destinations.
- No future target research item remains. Residual original basename/linker-retention uncertainty is documented and does not block implementation.

## Recommended Target Doc Changes

### Applied UID000130 renamed parent

- Renamed once to `by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md` with UID preserved; the old path is absent.
- Current state is `94/97`, owner `0000FU`, false, blank emitter/position/formal, `Nested:-4`.
- Item Summary: `Non-emitting compiler destructor ABI index covering two adjusted vtable entries, internal alignment, and the scalar deleting wrapper; human destruction is carried by the exact ordinary destructor child and class declaration.`
- Incorporate full bytes/hashes, boundaries, calling convention, flag/return/delete/guard behavior, xrefs/liveness, RTTI/subobjects, source route, no-code proof, rejected alternatives, and child inventory.
- Callback owner: B004 phase 2 only. B002 phase 1 remained read-only, and B004 verified the final shared-page hashes and generated output.

### Applied three target children

- A0 UID0004NE: `by-memory/0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0.md`; `95/98`, owner `0000FU`, false, blank emitter/position/formal, `Nested:4`.
- A4 UID0004NF: `by-memory/0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4.md`; `95/98`, owner `0000FU`, false, blank emitter/position/formal, `Nested:0`.
- Scalar UID0004NG: `by-memory/0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor.md`; `95/98`, owner `0000FU`, false, blank emitter/position/formal, `Nested:0`.
- Each page carries its exact bytes/hash, xrefs, vtable/COL relation, compiler-only no-code proof, source cause UID00012Y/UID0000FU, and rejected handwritten ABI alternatives.
- B004 registered these three paths serially before adding cross-references. B002 created none of them and its completed callback did not edit UID000130/UID0002P1/UID0001Z0.

## Recommended Support Doc Changes

- Already present/read-only UID00012X: `by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md`; `94/97`, owner `0000FU`, false, blank emitter/position/formal, `Nested:0`; exact four-child index and internal padding.
- Already present/read-only constructor UID0004NB: exact path/range/formal block above; `94/96`, owner/emitter `0000FU`, true, blank position, `Nested:4`.
- Already present/read-only UID00012Y: `by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md`; `94/96`, owner/emitter `0000FU`, true, blank position, `Nested:0`; exact destructor block and retained no-route/unique-body evidence.
- Already present/read-only UID0004NC/UID0004ND: exact primary/secondary paths/ranges/formal blocks above; each owner/emitter `0000FU`, true, blank position, `Nested:0`; scores `95/97`.
- Already present/read-only UID00012Z `ModelessDialogPane`: `Nested:-4`; every other byte/content/score/formal item remains preserved.
- Applied B004 UID000228 `HelpPaneSingletonCloseHelpers`: metadata-only `Nested:0 -> -4`; every other byte/content/score/formal item is preserved.
- Already present/read-only UID0000FU `VersatileAlertPane`: `93/96`, complete class block, size `0x274`, exact callback type/ownership, RTTI hierarchy, real source children, compiler ABI exclusions, and two construction contexts.
- Already present/read-only UID0000HE `AlertPanes`: `85/88` and current path; real Versatile inventory, four emitted methods, callback dependency, and ABI exclusions; unrelated AlertPane/Blue/Url/global content remains preserved.
- Applied B004 UID0002P1: `87/92 -> 94/97`; owner `0000FU`; false; blank emitter/position/formal; exact range/slot/COL/xref data and source-declared/generated-binary explanation retained.
- Applied B004 UID0001Z0: `87/92 -> 94/97`; owner `0000FU`; false; blank emitter/position/formal; exact RTTI hierarchy and child links added.
- Applied B004 UID0001TO: `85/89 -> 91/95`; owner `0000HE`; false; blank emitter/position/formal; exact `sizeof(AlertPane)==0x270` and `sizeof(VersatileAlertPane)==0x274`, callback field, and no standalone layout-source unit added.
- Applied B004 `by-memory/-ignored.md`: added all method-island and ABI-island padding plus renamed links after UIDs stabilized; all existing neighboring rows were preserved.
- `by-type/by-vtable/AlertPaneVtables.md`, `by-type/by-template/FunctionObjectTemplates.md`, `by-file/FunctionObjects.md`, and `by-class/FunctionObject.md`: content changes only if validator-managed reverse-reference propagation updates renamed links. Preserve scores/formal blocks and unrelated facts.
- DialogPane, AlertPane, UID000197, UID00010W, and generated files are read-only/verify-only unless validator-managed reverse links change. No score or C++ inflation.
- B004 phase 2 re-read and did not edit UID00012X, UID0004NB, UID00012Y, UID0004NC, UID0004ND, UID00012Z, UID0000FU, or UID0000HE. Their post-callback hashes match the pre-edit pins. Completed B002 phase 1 had not edited UID000130, the three ABI children, UID000228, UID0002P1, UID0001Z0, UID0001TO, or `by-memory/-ignored.md`.

## Score And Metadata Recommendation

| Destination | Current | Recommended | Metadata disposition | Callback owner/order |
| --- | --- | --- | --- | --- |
| UID000130 | historical `86/90` | current `94/97` | renamed; owner retained; FALSE/blank | B004 applied |
| UID0004NE/UID0004NF/UID0004NG | historically absent | current `95/98` each | owner class; FALSE; blank emitter/position/formal | B004 applied |
| UID00012X | `94/97` applied | preserve | FALSE index; blank emitter/position/formal | B002 complete; B004 read-only |
| UID0004NB constructor | `94/96` applied | preserve | TRUE; owner/emitter class; blank position | B002 complete; B004 read-only |
| UID00012Y | `94/96` applied | preserve | TRUE; owner/emitter class; blank position; destructor block | B002 complete; B004 read-only |
| UID0004NC/UID0004ND callbacks | `95/97` each applied | preserve | TRUE; owner/emitter class; blank positions | B002 complete; B004 read-only |
| UID0000FU | `93/96` applied | preserve | owner/emitter unchanged; complete class block closed before children | B002 complete; B004 read-only |
| UID0002P1 | historical `87/92` | current `94/97` | FALSE/blank emitter/position/formal; owner retained | B004 applied |
| UID0001Z0 | historical `87/92` | current `94/97` | FALSE/blank emitter/position/formal; owner retained | B004 applied |
| UID0001TO | historical `85/89` | current `91/95` | FALSE/blank emitter/position/formal; owner retained | B004 applied |
| UID0000HE | `85/88` applied | preserve | broader file score preserved; prose only | B002 complete; B004 read-only |

Score-improvement attempts and outcomes:

- Base identity: resolved by current decompile and DialogPane support.
- Callback type/call/delete spelling: resolved by decorated concrete vtables, call sites, and FunctionObjects formal source.
- One-source destructor placement: resolved to renamed UID00012Y.
- Wrapper liveness: resolved through all three vtable views.
- Raw body no-route role: exhausted through IDA xrefs, VA/RVA, rel32, uniqueness, scalar mirror, and source policy.
- Split/Nested policy: method side remains applied with real UID0004NB/UID00012Y/UID0004NC/UID0004ND and UID00012Z `-4`; ABI side is applied with UID0004NE/UID0004NF/UID0004NG and UID000228 `-4`.
- Object size: resolved to `0x274`; AlertPane base size to `0x270`.
- Formal C++: resolved to five nonblank and eight blank exact managed blocks.
- Concurrent plan: B002 phase 1 is complete and read-only; B004 phase 2 is complete on its disjoint destinations, with no shared destination or technical choice left to either callback.
- Reason scores are not 100: no original PDB/header/file basename or exact linker reason for retained ordinary copy; these are provenance uncertainties, not behavior blockers.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / impact |
| --- | --- | --- |
| Is `0x0049d9f0` Boost/TransferReply? | full current decompile, vtables, DialogPane docs/call fanout | No; it is DialogPane ordinary teardown. No remaining impact. |
| Is callback type only conservative `FunctionObject *`? | two decorated concrete vtables, 24-byte layouts, generic invoke slot, formal template | No; use `FunctionObjectT<unsigned long> *`. |
| Who owns callback deletion? | caller construction, no caller free, both destructor copies | VersatileAlertPane owns and deletes it. |
| Should raw body remain blank? | exact unique body, scalar mirror, project destructor siblings, class declaration | No; it is the exact source ordinary destructor carrier. |
| Why no entry route to raw body? | IDA, raw PE pointer/rel32 scans, uniqueness, xrefs | Exact linker/COMDAT reason remains unknowable without original build artifacts. Preserve as retained ordinary copy; no source/score blocker beyond final provenance. |
| Should target stay aggregate only? | by-structure exact-child rule and exact boundaries | Parent remains an index, but all three functions receive exact children. |
| Is `0x274` a field offset or object size? | scalar guard size, callback at `+0x270`, caller allocation 628 | Object size exactly `0x274`; callback is final 4-byte field. |
| Original file/header basename? | existing source tree, shared class family, two feature consumers | `AlertPanes.cpp/.h` is highest probability; exact basename not symbol-proven and does not block reconstruction. |
| Which concurrent report plan controls? | Finalized active B002 coordination SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` verified before supervisor execution, destinations/generated output, current binary, by-structure, validator position/Nested rules | B002's applied source-method state remains authoritative and read-only; this report applied only the disjoint B004 ABI/data/layout stage. The SHA is a time-scoped coordination pin, not a durable archived-hash assertion. No overlap or deferred choice remains. |

No investigable behavior, ownership, emitter, split, name, type, range, score, formal-C++, concurrent-plan, or callback-ownership blocker remains.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The manual rows inspected read-only during research/callback were stale: by-memory reported UID000130 `84%`, UID00012X `82%`, UID00012Y old end `0x004a0714` and `76%`; vtable memory `84%`; class `86%`; file `82%`; vtable type `87%` reconstructable; layout `85%` reconstructable. B004 did not edit manual coverage.

The rows below are exact with real method UIDs UID0004NB, UID00012Y, UID0004NC, UID0004ND and real ABI UIDs UID0004NE, UID0004NF, UID0004NG. All pre-registration tokens were replaced after serial registration. The row text is claim-for-claim synchronized with current B002 method state and applied B004 ABI state.

### `by-memory/-coverage-report.md`

Replace the UID00012X/UID00012Y portion at current lines 1231-1232 and insert the child/padding rows in address order with:

```text
    - [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md) 0x004a0690-0x004a0752 | method-island index | VersatileAlertPaneMethodIsland : ignored : 94% : very-strong : Non-emitting exact index over constructor, ordinary destructor, and primary/secondary callback children; internal alignment is ignored and source emits only from exact method pages.
        - [UID:0004NB][0x004a0690-0x004a06d7.VersatileAlertPaneConstructor](by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md) 0x004a0690-0x004a06d7 | constructor | VersatileAlertPaneConstructor : reconstructable : 94% : very-strong : Calls AlertPane construction, stores owned FunctionObjectT<unsigned long> result callback at +0x270, installs three class vtables, and is reached from Nexonclub and Terminal construction sites.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004a06d7-0x004a06e0 | padding | VersatileAlertPane constructor-to-destructor alignment : ignored : 100% : very-strong : Nine confirmed 0xcc compiler alignment bytes.
        - [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md) 0x004a06e0-0x004a0715 | non-deleting destructor | VersatileAlertPaneDestructor : reconstructable : 94% : very-strong : Unique ordinary destructor copy; source deletes owned m_resultCallback while vptr resets and DialogPane base teardown remain compiler-generated; no direct binary entry route was found.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004a0715-0x004a0720 | padding | VersatileAlertPane destructor-to-primary alignment : ignored : 100% : very-strong : Eleven confirmed 0xcc compiler alignment bytes.
        - [UID:0004NC][0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton](by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md) 0x004a0720-0x004a0732 | virtual method | VersatileAlertPaneOnPrimaryButton : reconstructable : 95% : very-strong : Vtable-only override invokes owned unsigned-long result callback with 1 when non-null.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004a0732-0x004a0740 | padding | VersatileAlertPane primary-to-secondary alignment : ignored : 100% : very-strong : Fourteen confirmed 0xcc compiler alignment bytes.
        - [UID:0004ND][0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton](by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md) 0x004a0740-0x004a0752 | virtual method | VersatileAlertPaneOnSecondaryButton : reconstructable : 95% : very-strong : Vtable-only override invokes owned unsigned-long result callback with 0 when non-null.
```

Replace UID000130 current line 1240 and insert its exact children/padding with:

```text
    - [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md) 0x004a0cb0-0x004a0d37 | compiler-destructor index | VersatileAlertPaneDeletingDestructorAbiIsland : ignored : 94% : very-strong : Non-emitting compiler ABI index over two adjusted vtable entries, internal alignment, and scalar deleting wrapper; human destruction is emitted by the exact ordinary destructor child.
        - [UID:0004NE][0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0](by-memory/0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0.md) 0x004a0cb0-0x004a0cbb | adjustor thunk | VersatileAlertPaneDestructorAdjustorThunkA0 : ignored : 95% : very-strong : Compiler vtable entry subtracts 0xa0 and tail-jumps to the scalar deleting destructor.
        - [UID:0004NF][0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4](by-memory/0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4.md) 0x004a0cbb-0x004a0cc6 | adjustor thunk | VersatileAlertPaneDestructorAdjustorThunkA4 : ignored : 95% : very-strong : Compiler vtable entry subtracts 0xa4 and tail-jumps to the scalar deleting destructor.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004a0cc6-0x004a0cd0 | padding | VersatileAlertPane destructor-thunk alignment : ignored : 100% : very-strong : Ten confirmed 0xcc compiler alignment bytes.
        - [UID:0004NG][0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor](by-memory/0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor.md) 0x004a0cd0-0x004a0d37 | scalar deleting destructor | VersatileAlertPaneScalarDeletingDestructor : ignored : 95% : very-strong : Compiler wrapper inlines callback deletion and base teardown, implements delete flags/operator-delete/0x274 guard path, and is regenerated from the class destructor.
```

Replace UID0002P1 current line 3225 with:

```text
        - [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md) 0x00618ba0-0x00618c44 | vtable-data | VersatileAlertPaneVtableData : ignored : 94% : very-strong : Non-emitting source-declared/generated-binary three-view vtable/RTTI cluster with exact COL offsets, eight-entry hierarchy, source-method slots, destructor adjustors, store xrefs, and boundary before ModelessDialogPane.
```

Replace stale read-only dependency UID00012W with:

```text
    - [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md) 0x0049feb0-0x004a0686 | class method cluster | AlertPaneCore : reconstructable : 88% : strong : AlertPane constructor/dismiss cluster attached to AlertPane; exact constructor/dismiss ranges, broad constructor fan-in, three vtable stores, layout offsets, and no-argument OnPrimaryButton/OnSecondaryButton dispatch used by VersatileAlertPane.
```

### `by-class/-coverage-report.md`

Replace UID0000FU and the independently stale UID00000B row with:

```text
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md) : reconstructable : 93% : very-strong : Generic AlertPane subclass with exact 0x274 layout, owned FunctionObjectT<unsigned long> callback, two live construction contexts, exact constructor/destructor/primary/secondary method children, three-view RTTI, and compiler-only deleting-wrapper/vtable exclusions.
- [UID:00000B][AlertPane](by-class/AlertPane.md) : reconstructable : 88% : very-strong : Shared modal alert base attached to AlertPanes.cpp, with accepted constructor and DismissDialog declarations, 96-call constructor fan-in, vtable/layout evidence, and no-argument primary/secondary virtual extension slots used by VersatileAlertPane.
```

### `by-file/-coverage-report.md`

Replace UID0000HE current line 22 with:

```text
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md) : reconstructable : 85% : strong : `NexusTK/ui/dialogs/AlertPanes.cpp` shared modal-alert source root; VersatileAlertPane now has exact typed constructor/destructor/callback source children and non-emitting ABI/vtable support, while all unrelated AlertPane/Blue/Url family evidence and the conservative whole-file score remain preserved.
```

### `by-type/by-vtable/-coverage-report.md`

Replace UID0001Z0 current line 129 with:

```text
- [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md) : ignored : 94% : very-strong : Non-emitting source-declared/generated-binary three-view VersatileAlertPane vtable/RTTI model with COL offsets 0/0xa0/0xa4, eight-entry hierarchy, exact constructor/destructor stores, callback slots, adjusted deleting entries, and class-source regeneration route.
```

### `by-type/by-struct/-coverage-report.md`

Replace UID0001TO current line 18 with:

```text
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md) : ignored : 91% : very-strong : Non-emitting alert-family layout audit; exact three-view offsets, DialogPane inherited state, AlertPane size 0x270, VersatileAlertPane size 0x274 with owned callback at +0x270, and existing Url/other derived-tail distinctions are documented on source-owning class pages.
```

### `by-type/by-template/-coverage-report.md`

Replace stale read-only dependency UID0001WQ with:

```text
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) : reconstructable : 88% : strong : Shared FunctionObject, FunctionObject0, FunctionObjectT, and member-function wrapper declarations routed through UID0000JO; accepted virtual destructor and void Invoke(TArg) interface directly support VersatileAlertPane's unsigned-long result callback.
```

- Reason neither B002 nor B004 may apply: every named `-coverage-report.md` is manual supervisor-owned coverage and explicitly forbidden for B-agent edits. Validator-generated coverage does not replace this manual update. All method and ABI rows now have real UIDs and exact current paths; any manual-row application remains external supervisor-owned state.

## Follow-Up Actions

- Supervisor coordination boundary: B002 Gate 1/Gate 2 and supervisor validator `000000010947` are complete; commands `000000010827-000000010835` remain historical phase-1 evidence, and the B002 ordinary-doc handoff is generated-read-back and lease-free. The accepted B004 phase-2 plan is fully implemented and locally verified. Manual coverage application and report execution, validation, count, path, move, and archive state remain external supervisor/validator-owned and are neither asserted nor directed by this artifact.
- A-agent actions: none required for this target.
- Completed B002 phase-1 handoff: UID00012X/UID0004NB/UID00012Y/UID0004NC/UID0004ND/UID00012Z/UID0000FU/UID0000HE are current read-only contracts with blank positions, real UIDs, released leases, validators, and generated proof.
- Completed B004 phase-2 scope: UID000130/UID0004NE/UID0004NF/UID0004NG/UID000228/UID0002P1/UID0001Z0/UID0001TO and all family padding/renamed links are applied; phase-1 destinations remained read-only; final waited generated readback passed.
- Future research or implementation actions: none. Every accepted C01-C46 item is applied, already present, or excluded with an evidence-backed reason.

## Confidence

- Recommendation confidence: 97/100.
- Score confidence: high; exact target/ABI children support `94-95` completion and `97-98` confidence.
- Coordination confidence: very high; the finalized active B002 artifact was reconciled at exact SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` before supervisor execution, every conflict has one technical outcome, and destination ownership is disjoint in time and scope. That evidence-time pin is not asserted as an archived hash.
- Remaining uncertainty: exact original source basename/header split and the precise linker/COMDAT reason the ordinary destructor copy has no route. Neither changes code, ownership, split, emitter, or generated-source decisions.

## Validator Results

- Completed external B002 proof: exact-artifact Gate 1, claim-by-claim Gate 2, and supervisor validator `000000010947` completed; sequential commands `000000010827-000000010835` remain historical phase-1 validation evidence. The eight B002 destinations retain the accepted metadata/formal/source state, and their pinned hashes remained unchanged after B004. Manual coverage and report execution remain external supervisor-owned state.

| Command | Timestamp (EDT) | Scoped destination / purpose | Exit / result | Validator side effects |
| --- | --- | --- | --- | --- |
| `000000010873` | `2026-07-14T06:28:14-04:00` | create/register A0 child | exit 0; UID0004NE assigned | `insert_uid:1`, `path_update:1`, metadata/autogen updates; generated deferred; new-registration mode emitted no `ok:` counter |
| `000000010874` | `2026-07-14T06:28:59-04:00` | create/register A4 child | exit 0; UID0004NF assigned | `insert_uid:1`, `path_update:1`, metadata/autogen updates; generated deferred; new-registration mode emitted no `ok:` counter |
| `000000010875` | `2026-07-14T06:30:16-04:00` | create/register scalar child | exit 0; UID0004NG assigned | `insert_uid:1`, `path_update:1`, metadata/autogen updates; generated deferred; new-registration mode emitted no `ok:` counter |
| `000000010883` | `2026-07-14T06:32:10-04:00` | UID000130 preserved rename scan, `--uid-only` | exit 0; `ok:1` | old-to-new `path_update`, seven registry reverse-path updates, score/autogen normalization; generated skipped |
| `000000010884` | `2026-07-14T06:32:34-04:00` | final UID0004NE scoped scan | exit 0; `ok:1` | final references normalized; generated deferred |
| `000000010885` | `2026-07-14T06:32:52-04:00` | final UID0004NF scoped scan | exit 0; `ok:1` | final references normalized; generated deferred |
| `000000010886` | `2026-07-14T06:33:12-04:00` | final UID0004NG scoped scan | exit 0; `ok:1` | final references normalized; generated deferred |
| `000000010887` | `2026-07-14T06:33:34-04:00` | UID000228 nesting-only edit | exit 0; `ok:1` | metadata normalized; generated deferred |
| `000000010888` | `2026-07-14T06:35:00-04:00` | UID0002P1 vtable-data support | exit 0; `ok:1` | one UID000130 link updated; generated deferred |
| `000000010891` | `2026-07-14T06:35:53-04:00` | UID0001Z0 vtable-type support | exit 0; `ok:1` | three child UID links added and one stale reference-index entry removed; generated deferred |
| `000000010893` | `2026-07-14T06:36:50-04:00` | UID0001TO layout audit | exit 0; `ok:1` | stale stats row removed/rescore recommendation recorded; generated deferred |
| `000000010894` | `2026-07-14T06:37:33-04:00` | `by-memory/-ignored.md` padding/renamed links | exit 0; `ok:1` | eight reference-index additions; 314 pre-existing `missing_ref_uid` warnings, 10 shown and 304 suppressed; generated deferred |
| `000000010895` | `2026-07-14T06:38:25-04:00` | final UID000130 scan with `--wait-generated` | exit 0; `ok:1`; generated complete | target child links normalized; metadata refresh 280; registry rebuild 4,754 nodes/3,845 edges; existing global warnings `children_fallback_insert:15`, `children_marker_missing:84`, `emitter_has_no_code:196` |

- Final generated readback owned by B004: `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`, command `000000010895`, refreshed `2026-07-14T06:38:25-04:00`, SHA256 `3577D3E0F313E0F29FE1A5F5F41ED5054973CC88A3E270863F5D6FE31AEE2408`. It had exactly one `class VersatileAlertPane`, constructor, destructor, `OnPrimaryButton`, and `OnSecondaryButton`; the class closed before out-of-class definitions. Counts were zero for UID000130, UID0004NE, UID0004NF, UID0004NG, UID0002P1, UID0001Z0, UID0001TO, `Empty Emitter Marker`, `AdjustorThunk`, `ScalarDeletingDestructor`, `0x00618ba4`, `0x274`, and `deletingFlags`. Read-only recheck after external command `000000010907` found SHA256 `5DF82FAE80075720C9E6CEF92A5CF7BA3EC5D0B45D5A61ECCF70F873FF1AEF1B` and the same target-specific counts.
- Validator warnings are recorded rather than hidden. The `-ignored` missing-reference set and final global autogen warning counters are pre-existing whole-project diagnostics; every scoped destination returned exit 0, every ordinary final scan returned `ok:1`, and generated refresh completed.

## Changed Files

- Renamed once with UID preserved: `by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md` -> `by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md`; old path absent, UID000130 unique.
- Created/registered serially: `by-memory/0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0.md` (UID0004NE), `by-memory/0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4.md` (UID0004NF), and `by-memory/0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor.md` (UID0004NG).
- Modified ordinary support: `by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md` (UID000228), `by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md` (UID0002P1), `by-type/by-vtable/VersatileAlertPaneVtables.md` (UID0001Z0), `by-type/by-struct/AlertPaneLayout.md` (UID0001TO), and `by-memory/-ignored.md`.
- Modified report: `tools/leaser/Agents/Agent-B004/research/000130-VersatileAlertPaneDestructor-source-quality.md` to record applied C01-C46, real UIDs, destination and validator proof, exact manual coverage text, generated readback, and checklist completion.
- Narrow coordination-pin repair: this report text alone replaced the superseded B002 report pin/current-lifecycle wording with the finalized active pre-execution artifact SHA and completed validator `000000010947`; no by-*, generated, coverage, tracker, audit, goal/notes, IDA, validator-state, lifecycle, or archive file was edited, and no validator or report command was run.
- Strictly read-only hashes remained unchanged: UID00012X `4DCFD71E7D4A3955FF838EA9ABC2AE190B8EB1F104617645481D17A3529760DF`, UID0004NB `79218AF0F39FE57F1EBB9D9289F01D9844AE485107CEAAB45C6DAB96A8C0E1F5`, UID00012Y `912CEAD3D05A45513B6A7A475AFD6EB2310848809AE08CA20CABEAB3E4F8AC97`, UID0004NC `EB9A0A41A813AC4B7607AF6413178157B21FBCF41737A69026064ACFE522B952`, UID0004ND `58FEFAD93AE329E82ECB1D4C3A3740621BCFE306F7655985726B69E3158B9D70`, UID00012Z `933431636C9FA5974FB913D1A2DD1B024B9D6D7419DFFBAE1645AA34E4776B82`, UID0000FU `0AB1B843C15C7656C7FC234046ACD16614802FB0DBC05F9B46BFB9CCDC727183`, UID0000HE `033750F5B87B5AFCE75F4FDC1E50C182DF2A511104DAE723E1314021EEBEDBA1`.
- Leases: each of the nine ordinary destination paths above was leased only for its own edit/validation window and released immediately. The target used its old path for the bounded move and final new path for validation; the three children were handled serially. No B004 lease remains.
- Report execution: not run by B004. No execute, lifecycle, probe, move, or archive command was run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor accepted exact pre-callback SHA `4C69CBE5FAF738BE69B736D1701363D5F8EC9FA13D53E5017AB73000CFB4603A` before implementation.
- [x] Confirmed finalized active B002 coordination artifact SHA `54B392ADAA0610C94C7DEF3AE58A0B1C227BCB5AAC77536BFB5A5AC9B96B3FB0` at pre-supervisor-execution verification time, completed Gate 1/Gate 2 and supervisor validator `000000010947`, historical phase-1 validators `000000010827-000000010835`, and generated readback; no durable archived-hash claim is made.
- [x] Confirmed strict callback order: B002 phase 1 fully validated/released before this B004 report-only reread/rebase; B004 has not edited a shared destination.
- [x] Verified current UID-preserving paths UID00012X MethodIsland and UID00012Y Destructor; old source-facing paths are absent from the current handoff.
- [x] Verified real method UIDs UID0004NB, UID0004NC, and UID0004ND and replaced every B002 method token throughout this report.
- [x] Verified current UID00012X `94/97` false/non-emitting method-index metadata, child inventory, padding history, blank no-code block, and `Nested:0`.
- [x] Verified current UID0004NB/UID00012Y `94/96` and UID0004NC/UID0004ND `95/97`, UID0000FU owner/emitter, blank positions, exact formal blocks, bytes/hashes, xrefs, ownership, and source evidence.
- [x] Verified current method-child `Nested:+4,0,0,0` and UID00012Z `-4`; confirmed B002 did not content-edit `by-memory/-ignored.md`.
- [x] Verified current UID0000FU `93/96` complete class block with `};` before `[[CHILDREN]]`, size/type/ownership/hierarchy/real child links.
- [x] Verified current UID0000HE detail at unchanged `85/88`, including real method UIDs and preserved unrelated family content.
- [x] Verified completed B002 validators/releases and current generated proof: one class/four methods, zero UID00012X marker, zero Empty marker, and lease-free handoff.
- [x] B004 report-only rebase reread every completed phase-1 destination and generated output; no source-family edit was made.
- [x] B004 phase 2: UID-preserving rename UID000130 to DeletingDestructorAbiIsland completed; old path absent and UID unique.
- [x] B004 phase 2: serially registered UID0004NE/UID0004NF/UID0004NG and replaced every former ABI token throughout this report.
- [x] B004 phase 2: applied UID000130 `94/97` false/non-emitting ABI-index metadata and all exact target evidence.
- [x] B004 phase 2: applied three ABI children `95/98`, owner UID0000FU, false/blank emitter/position/formal, exact hashes, vtable/RTTI/flag/return/delete evidence, and no-code proof.
- [x] B004 phase 2: retained target parent `Nested:-4`; applied ABI child `Nested:+4,0,0`, UID000228 `-4`, and all method/ABI padding plus renamed links in `by-memory/-ignored.md`.
- [x] B004 phase 2: applied UID0002P1 and UID0001Z0 `94/97` false/blank generated-binary dispositions and UID0001TO `91/95` false/blank layout disposition with complete RTTI/vtable/size evidence.
- [x] Preserved DialogPane/AlertPane/FunctionObjects/OperatorDelete facts already present without unrelated score/C++ inflation.
- [x] Preserved all exact binary behavior, raw no-route evidence, historical leads, rejected alternatives, negative evidence, source placement, and score rationale at report-level detail.
- [x] Verified the six B002 managed blocks are already applied exactly: five nonblank source blocks plus blank UID00012X.
- [x] Applied only the seven B004 phase-2 blank managed blocks; preserved the six B002 blocks unchanged so the overall count remains five nonblank/eight blank.
- [x] Ran scoped validators for every changed B004 ordinary page, recorded command id/timestamp/exit/ok/side effects, and released every lease immediately.
- [x] Ran B004's final authorized waited generated refresh; verified class closure, blank positions with address order, one constructor/destructor/primary/secondary definition each, no ABI bodies, no explicit vptr/base/flags/free/guard code, and no target-family empty/comment marker.
- [x] Supplied one exact unified manual coverage set with all real UIDs; neither B agent edited supervisor-owned coverage.
- [x] Updated C01-C46 destinations/states and this checklist claim by claim during callback.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact SHA `4C69CBE5FAF738BE69B736D1701363D5F8EC9FA13D53E5017AB73000CFB4603A`.
- [x] B002 phase-1 completion and exact handoff independently confirmed in this report-only rebase before any B004 phase-2 authorization.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with legal callback verification states for C01-C46.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly excluded with reason.
- [x] All three new B002 method UIDs captured and every method placeholder replaced.
- [x] Captured UID0004NE/UID0004NF/UID0004NG and replaced every ABI placeholder before the post-callback report hash.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions and concurrent-report conflicts remain closed; only the exact evidence-backed provenance limits above remain.
- [x] Both phases' scoped validators and B004 final waited generated proof recorded.
- [x] No manual coverage/generated/tracker/audit/supervisor/validator/lifecycle file manually edited.
- [x] No lease remains.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000010958","destination_path":"executed-b-agent-research/B004/000130-VersatileAlertPaneDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000130-VersatileAlertPaneDestructor-source-quality.md","timestamp":"2026-07-14T07:29:16-04:00","uid":"000130"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
