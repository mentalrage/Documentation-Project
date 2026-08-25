** TARGET-REPORT-UID:00033F **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# 00033F WebBoardDialogOldScalarDeletingDestructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep UID00033F as the exact class-owned, source-declared/generated-binary MSVC scalar deleting destructor for `WebBoardDialogOld`; do not hand-author a deleting-wrapper function body.
- Final disposition: the source-visible cause is `class WebBoardDialogOld : public BrowserPane` with `virtual ~WebBoardDialogOld();`, plus the ordinary destructor body `g_pWebBoardDialogOld = NULL;` emitted by [UID:000212]. The compiler must regenerate the primary deleting slot, two secondary-view adjustor thunks, BrowserPane/DialogPane destruction chain, flag modes, guarded-size path, return-this ABI, and storage release.
- Implemented target state: UID00033F is `90/93`, owner/emitter UID0000G3 and all route metadata including `Nested:6` are preserved, the exact managed no-duplicate marker is present, and C01-C30 are incorporated or proven already present at same-or-greater detail.
- Implemented support correction: [UID:0000ZA] is active `WebBoardDialog::RefreshLayout`, with owner/emitter UID0000G2 and unchanged `88/90` score/range/path. Its `+0x278` close-button field and mode-dependent geometry fit active `WebBoardDialog` size `0x37c`, not old `WebBoardDialogOld` size `0x278`.
- Confidence: very high for range, vtable and thunk routing, singleton/base/delete behavior, source declaration, ordinary-body completeness, object size, and active/old layout separation; exact original spelling of the dead/no-xref active layout helper remains inferred.

## Supporting Research

- Fresh streamable MCP initialization, `tools/list` schema refresh, `idb_list`, and `server_health` succeeded against database `bf5519ae`. Evidence-time health was `ok` with imagebase `0x400000`, ready auto-analysis, Hex-Rays, and string cache. That session later expired. At callback time the supervisor verified replacement session `supervisor_20260712`; no additional binary query was needed because the accepted implementation introduced no new binary uncertainty.
- The target, ordinary destructor cluster, constructor, old class, active class, file root, singleton global/storage, mixed adjustor page, vtable/data aggregate, BrowserPane ordinary destructor, active deleting-wrapper sibling, generated `WebBoardDialog.cpp`, tracker rows, and matching executed reports were read.
- Matching reports from B001, B002, B008, B010, and B011 were treated as leads only. Their owner, no-hand-wrapper direction, and `Nested:6` metadata survive current recheck; their shallow treatment of UID00033F and old-class `+0x278` field assumption do not.
- Historical pre-callback generated output demonstrated the practical defect: it emitted a valid UID00033F marker and UID000212 ordinary destructor, but also emitted `m_closeButton // +0x278` on `WebBoardDialogOld`, used that member in the old constructor, and emitted UID0000ZA as an old-class method. The completed callback removes those contradictions.
- Callback truth: B004 edited only the nine accepted by-* documents, used immediate one-file leases, ran one successful scoped validator per changed by-* document, released every lease, and ran final waited generated refresh `000000008818`. B004 did not manually edit generated/coverage/tracker/supervisor files and performed no report execution, lifecycle, move, archive, or MCP process-management command.

## Target

- Target UID: `00033F`.
- Target path: `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md`.
- B004 research artifact path at creation: `tools/leaser/Agents/Agent-B004/research/00033F-WebBoardDialogOldScalarDeletingDestructor-source-quality.md`; supervisor/validator-owned lifecycle path state is external to this artifact.
- Historical pre-report queue snapshot: `auto-generated/-ag-research-tracker.md` listed UID00033F in `by-memory / Not-Covered Files - Reconstructable` at `86/90`, reconstructable true, with zero indexed reports. Counts and path state are validator-owned and are not frozen as current truth here.
- Current generated coverage snapshot at evidence time: `auto-generated/-ag-memory-coverage.md` routes UID00033F through owner/emitter UID0000G3 to `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` and classifies the comment marker as coded.

## Current Target State

- Metadata is `COMPLETION:90`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000G3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000G3`, blank position, and retained relative nesting delta `Nested:6`.
- Formal C++ is the exact accepted five-line no-duplicate marker. It identifies the source virtual destructor and UID000212 ordinary body while delegating deleting dispatch, adjustors, base lowering, flag modes, guarded size, return-this ABI, and storage release to the compiler.
- Current target prose contains the exact instruction/flag table, range and boundary proof, vtable/RTTI/adjustor routes, `0x278` allocation parity, ordinary-destructor comparison, singleton/base/delete dependencies, generated-binary disposition, ownership analysis, and rejected alternatives.
- Existing owner/emitter/source route is correct: direct class [UID:0000G3] and source file [UID:0000P9].
- Existing range is correct and requires no split: one modeled function `0x004707f0-0x0047084f`, size `0x5f`, 29 instructions, five basic blocks, cyclomatic complexity 2.
- Historical initial revision was report-only. The implementation and validators recorded below are complete; supervisor/validator report validation, execution, count, current path, move, and archive state remain external.

## Executive Recommendation

- Preserve UID00033F as reconstructable/routed documentation because source declarations must regenerate the wrapper, while classify the exact binary body as `source-declared/generated-binary` / compiler ABI output.
- Preserve direct owner/emitter UID0000G3 and source file UID0000P9. BrowserPane, DialogPane, MemoryMan, singleton storage, the mixed thunk aggregate, and the broad Browser/OLE island are dependencies or support, not direct owners.
- Use a detailed comment-only managed marker. A blank block would hide a routed source-declaration dependency; a handwritten `ScalarDeletingDestructor(char flags)` function would duplicate compiler ABI and risk double destruction or double free.
- The stable UID/path/title remains unchanged. UID00033F required no physical rename, range split, merge, new child, or owner move.
- `Nested:6` is retained. Validator semantics make it a relative delta from the previous address-sorted row, not a child count: predecessor UID00033E applies `-6` and renders at cumulative indentation 128, UID00033F applies `+6` and returns to 134, and successor UID00033G applies `0` and remains at 134.
- UID0000ZA is reclassified to active `WebBoardDialog`; the old constructor uses a local close-button pointer; active-only `RefreshOldLayout` / `m_closeButton +0x278` content is removed from the old-class declaration.

## Supervisor Active Recheck

- Historical trigger: the assignment named UID00033F for independent report-only research and required MCP revalidation of wrapper, ordinary destructor, vtables, adjustors, singleton, base, delete, allocation, object layout, source declaration, owner, and emitter disposition; that evidence pass and the accepted callback are complete.
- No split repair is required for UID00033F. The exact function boundary is already modeled and byte-confirmed.
- The direct support reclassification is complete: UID0000ZA moved from old UID0000G3 to active UID0000G2 because its `+0x278` field access lies one byte-range beyond the complete old object but is valid inside active size `0x37c`.
- Every target blocker is resolved and implemented; no implementation item remains deferred.

## Inference Research Guidance Check

- IDA facts control addresses, bytes, stores, calls, flags, vtable cells, xrefs, allocation sizes, and thunk adjustments.
- Current by-* docs establish accepted class/file/global naming and are corroboration, not authority where they conflict with the binary.
- Source-shape inference is limited to the most plausible Visual C++ source: one virtual destructor declaration and ordinary destructor body, with deleting wrappers, vptr transitions, adjustors, and base calls regenerated.
- The source-facing class names are unusually strong because decorated vtable names identify `WebBoardDialogOld` and `BrowserPane`; the exact internal compiler helper names and flag parameter spelling are intentionally not promoted to source.
- Wave2/Wave3/simroot mentions encountered in old docs were ignored as stale authority. Generated C++ was used only to identify current documentation consequences and contradictions.

## Heuristic / Inference Reanalysis And Validation

- Compiler-name issue: IDA types `this` as `boost::exception *` and labels `0x0049d9f0` as `boost::exception::~exception`. Current MCP decompilation of `0x0049d9f0` writes DialogPane vtables, decrements active-dialog state, destroys control-list entries, releases the control list, tears down tile state, and calls Pane cleanup. The Boost type/name is rejected pollution.
- Wrapper-versus-source issue: UID00033F duplicates the ordinary destructor lowering instead of calling `0x0046e8c0`. This does not make all duplicated instructions handwritten source. The only derived source statement common to ordinary and deleting forms is `g_pWebBoardDialogOld = NULL;`; derived/base vptr writes, base teardown, delete flags, adjustors, return-this behavior, and storage free are compiler/base effects.
- Ordinary-body completeness issue: UID000212's destructor C++ containing only the singleton clear is complete. The binary ordinary body has that store, three BrowserPane vptr reinstalls, and a tail jump to DialogPane teardown; C++ automatically supplies the latter four operations from inheritance and virtual destruction.
- Delete-mode issue: the wrapper always destroys the object first. If bit 0 is clear it returns without deallocation. If bit 0 is set and bit 2/flag value 4 is clear, it calls MemoryMan-backed operator delete at `0x004f4ac0`. If flag 4 is set, it passes `this` and `0x278` to the one-byte guard/no-op helper at `0x0041b6a0`, then returns. The report records this ABI behavior without inventing a source enum.
- Allocation issue: both direct constructor callers allocate decimal 632 / `0x278` through `sub_4F4AA0` before calling `sub_46E640`. This independently matches the wrapper's guarded-size immediate.
- Object-layout issue: old `WebBoardDialogOld` is exactly `0x278` bytes, the same size used by BrowserPane's wrapper family. Old live code uses `+0x26c` for the inherited browser-control pointer. No live old constructor store exists at `+0x278`.
- Misowned-helper issue: UID0000ZA accesses and stores a close button at `this+0x278`, so it cannot be a valid method on a `0x278`-byte old object. It uses active mode 0/4/6 geometry, while active `WebBoardDialog` has `m_closeButton +0x278`, owner-name storage at `+0x27c`, a caller allocation of decimal 892 / `0x37c`, and a scalar-wrapper guarded size of `0x37c`. UID0000ZA is therefore active `WebBoardDialog::RefreshLayout(int mode)`.
- Old-constructor issue: current old-constructor C++ stores its close button in `m_closeButton`, but disassembly allocates/constructs the button and passes the local result directly to `AddChild`; only the browser control is stored at `+0x26c`. The formal block must use a local `closeButton`.
- Vtable issue: primary `0x0061368c` points directly to UID00033F. Secondary `0x00613700` points to `0x004702e6`, which subtracts `0xa0`; tertiary `0x00613730` points to `0x004702f1`, which subtracts `0xa4`. Both thunks jump to UID00033F.
- RTTI issue: locator cells immediately before the three old vtable views are `0x00613688 -> 0x0064306c`, `0x006136fc -> 0x00643124`, and `0x0061372c -> 0x00643138`. These reinforce one complete class with secondary views.
- Singleton issue: `0x0067aba0` has exactly five current refs: constructor set/guard clear `0x46e6ba/0x46e6c1`, ordinary destructor clear `0x46e8c0`, constructor-EH singleton clear helper `0x470260`, and deleting-wrapper clear `0x4707f6`.
- EH issue: constructor EH action `0x005fae35` jumps to BrowserPane's ordinary destructor at `0x0046a8a0`; action `0x005fae43` reaches the singleton-clear helper at `0x00470260`. These are compiler unwind routes, not extra handwritten old-class destructor methods.
- Liveness issue: the ordinary destructor has zero inbound xrefs, while the deleting wrapper is reached from one primary vtable cell and two vtable-referenced adjustors. This is consistent with virtual deleting dispatch and an emitted but unreferenced ordinary destructor, not evidence that ordinary source should be deleted.
- Range issue: one `CC` byte at `0x004707ef` separates active and old wrappers. UID00033F ends exactly at `0x0047084f`, where the next modeled COM adjustor body begins; there is no successor padding to absorb.
- Remaining uncertainty: exact source spelling `RefreshLayout` for reclassified UID0000ZA is inferred because that helper has no inbound xref. Its active owner, receiver layout, method behavior, and rejection from old ownership are not uncertain.

## Evidence Standards Used

- Highest-weight evidence: evidence-time MCP `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `get_int`, `xrefs_to`, and `callees` against then-healthy `bf5519ae`; that session later expired without invalidating the recorded evidence.
- Structural evidence: decorated vtable names and cells, RTTI locator adjacency, constructor vptr stores, adjustor instructions, ordinary/deleting body comparison, constructor allocation sites, and shared base teardown behavior.
- Documentation evidence: current target/support by-* pages, generated C++, tracker/coverage snapshots, and matching executed reports after binary recheck.
- Negative evidence: zero ordinary-destructor xrefs, no direct source-shaped wrapper caller, no old-constructor `+0x278` store, no UID0000ZA entry xref, no Boost behavior, no separate wrapper source symbol, and no child range inside UID00033F.
- The evidence ladder supports source-ready declarations and exact no-duplicate policy. Lack of original PDB/source and exact compiler version caps confidence below final-symbol certainty but does not block score improvement.

## Evidence Checked

- MCP availability/schema at research time: fresh initialize, `tools/list`, `idb_list`, and `server_health(database=bf5519ae)`; callback introduced no new binary uncertainty requiring a replacement-session query.
- Target: lookup, analyze, decompile, full 29-instruction disassembly, bytes spanning predecessor/target/successor, xrefs, and callees for `0x004707f0`.
- Ordinary/source body: analyze, decompile, five-instruction disassembly, bytes/padding, and xrefs for `0x0046e8c0`.
- Base/delete chain: analyze `0x0049d9f0`, `0x004f4ac0`, and `0x0041b6a0`; checked DialogPane state/list/tile/Pane teardown, MemoryMan Get/Free route, and one-byte guard behavior.
- Vtables/adjustors: integer/byte reads at `0x00613688-0x00613734`; disassembly/xrefs for `0x004702e6` and `0x004702f1`; constructor stores at `0x0046e6e1/0x0046e6e7/0x0046e6f1`.
- Singleton/EH: xrefs to `0x0067aba0`, disassembly/xref for `0x00470260`, and BrowserPane EH destructor route `0x005fae35 -> 0x0046a8a0`.
- Allocation/layout: constructor xrefs `0x00508ddd` and `0x0051461e`; caller decompilation shows `sub_4F4AA0(632)`; constructor and old-family field accesses were audited.
- Active sibling: analyze/disassemble `0x00470790` and `0x0046d330`; active wrapper is the same 95-byte shape but uses singleton `0x0067ab9c` and guarded size `0x37c`. Decompilation at active constructor caller `0x00508d7a` independently shows `sub_4F4AA0(892)` before `sub_46D050`.
- Docs: UID00033F, UID000212, UID0000ZB, UID0000ZA, UID000337, UID0001OB, UID000408, WebBoardDialogOld/WebBoardDialog classes, WebBoardDialog file, singleton global/storage, generated WebBoardDialog.cpp, tracker and memory coverage.
- Historical report searches: `UID:00033F`, `0x004707f0`, `WebBoardDialogOldScalarDeletingDestructor`, `UID:000212`, `0x278`, `m_closeButton`, and `scalar deleting destructor`. Opened matching B001/B002/B008/B010/B011 reports only.
- Failed checks: initial PowerShell `Invoke-WebRequest` lacked `-UseBasicParsing`, and two local PowerShell helper drafts had parameter/automatic-variable mistakes. Corrected MCP calls succeeded; these were client-script errors, not IDB failures.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact target is `0x004707f0-0x0047084f`, size `0x5f`, 29 instructions, five blocks, complexity 2. | High | Current lookup/analyze/disasm | UID00033F range/status | Applied | Verified in target; validator `000000008797` ok 1. |
| C02 | Predecessor separation is one `CC` at `0x4707ef`; next body starts exactly at `0x47084f`; no successor padding. | High | Current bytes/lookup | UID00033F boundaries | Applied | Verified in target boundary table; `8797`. |
| C03 | Primary old vtable cell `0x61368c -> 0x4707f0`. | High | Current get_int/bytes/xrefs | target/class/vtable aggregate | Applied | Verified in target, old class, and vtable index; `8797`/`8799`/`8817`. |
| C04 | Secondary cell `0x613700 -> 0x4702e6`; thunk subtracts `0xa0` and jumps to target. | High | Current get_int/disasm/xrefs | target/adjustor/vtable docs | Applied | Verified in target/adjustor/vtable; `8797`/`8816`/`8817`. |
| C05 | Tertiary cell `0x613730 -> 0x4702f1`; thunk subtracts `0xa4` and jumps to target. | High | Current get_int/disasm/xrefs | target/adjustor/vtable docs | Applied | Verified in target/adjustor/vtable; `8797`/`8816`/`8817`. |
| C06 | Wrapper first clears `g_pWebBoardDialogOld` at `0x4707f6`. | High | Current disasm/xrefs | target/global/storage | Applied/already present | Verified in target; singleton docs already carried same-or-greater five-ref detail. |
| C07 | Wrapper reinstalls BrowserPane vptr views at offsets 0, `0xa0`, and `0xa4`. | High | Current disasm | target/class/ordinary relation | Applied | Verified in target, old class, and UID000212 relation; `8797`/`8799`/`8805`. |
| C08 | `0x49d9f0` is DialogPane ordinary teardown despite polluted Boost name. | High | Current analyze/decompile and DialogPane docs | target/UID000212 | Applied/rejected label | Verified in target ownership/base sections; `8797`. |
| C09 | Bit 0 clear means destroy-only/no storage free. | High | Current disasm | target ABI behavior | Applied | Verified in target delete-mode table; `8797`. |
| C10 | Bit 0 set and flag 4 clear calls MemoryMan-backed operator delete `0x4f4ac0`. | High | Current disasm/analyze | target/delete dependency | Applied | Verified in target delete-mode/dependency sections; `8797`. |
| C11 | Flag 4 path passes `this,0x278` to one-byte `0x41b6a0` guard/no-op and returns. | High | Current disasm/analyze | target ABI behavior | Applied | Verified in target delete-mode/allocation sections; `8797`. |
| C12 | Wrapper returns original `this` and uses `ret 4`; flags are compiler ABI, not source API. | High | Current disasm | target ABI behavior/no-code proof | Applied | Verified in target ABI section and exact marker; `8797`. |
| C13 | Both old constructor callers allocate 632 / `0x278` bytes. | High | Current xrefs and caller decompile | target/class/constructor | Applied | Verified in target, old class, constructor, and file; `8797`/`8799`/`8811`/`8815`. |
| C14 | Ordinary destructor `0x46e8c0` has the same singleton/vptr/base sequence but no delete-mode logic. | High | Current analyze/decompile/disasm | UID000212/target | Applied | Verified in target and UID000212 comparison; `8797`/`8805`. |
| C15 | UID000212 source destructor body `g_pWebBoardDialogOld = NULL;` is complete; vptr/base actions are generated. | High | C07-C14 and C++ destruction rules | UID000212/class/file | Preserved/corrected prose | Exact managed block unchanged; validator `8805`; generated ordinary-body count 1. |
| C16 | Ordinary destructor has zero inbound xrefs; target has two thunk code refs and one primary-vtable data ref. | High | Current xrefs_to | target/UID000212 liveness | Applied | Verified in target and UID000212; `8797`/`8805`. |
| C17 | Singleton has five lifecycle refs, including constructor, ordinary, EH clear helper, and deleting wrapper. | High | Current xrefs_to | target/global/storage/constructor | Applied/already present | Target/constructor synchronized; global/storage already same-or-greater, so no support edit. |
| C18 | Source declaration is `virtual ~WebBoardDialogOld();` under `class WebBoardDialogOld : public BrowserPane`. | High | Decorated vtables, current class family, constructor/destructor | class/target marker | Preserved/explained | Exact old-class block match and target marker verified; `8799`/`8797`. |
| C19 | Exact wrapper is source-declared/generated-binary and must not be hand-authored. | High | Complete ABI evidence | target rebuild handling/formal | Applied | Exact marker verified in source and generated output; no target Empty Emitter Marker. |
| C20 | Owner/emitter UID0000G3 and file route UID0000P9 remain correct. | High | vtables/singleton/constructor/source family | target metadata | Preserved | Target metadata and generated UID0000P9 route verified; `8797`/`8818`. |
| C21 | `Nested:6` is the correct relative delta: UID00033E renders at cumulative indentation 128 after `-6`, target returns to 134 with `+6`, and UID00033G keeps 134 with `0`. It is not a function-child count. | High | Validator README lines 592-598; current address-sorted source rows; generated by-memory coverage indentation | target metadata/generated hierarchy | Preserved | Source remains literal `Nested:6`; waited refresh `8818` completed. |
| C22 | Target score moved `86/90 -> 90/93`; this score change is based on wrapper/source evidence and does not depend on changing the correct nesting delta. | Medium-high | All blocker resolutions | target metadata | Applied | Source/generated both show `90/93`; `8797`/`8818`. |
| C23 | Active sibling wrapper is shape-identical but uses active singleton and `0x37c` guarded size, matching active allocation 892 / `0x37c`. | High | Current active analyze/disasm and caller decompile | target sibling comparison | Applied/no sibling edit | Preserved in target/class/file comparison; active sibling remained untouched. |
| C24 | UID0000ZA's `+0x278` close-button storage cannot belong to old size `0x278`; it belongs to active size `0x37c`. | High | Current old allocation, both wrappers, UID0000ZA disasm | UID0000ZA/class docs | Applied | Verified in layout, both classes, and file; `8812`/`8799`/`8813`/`8815`. |
| C25 | UID0000ZA should emit `WebBoardDialog::RefreshLayout(int mode)`, not `WebBoardDialogOld::RefreshOldLayout`. | Medium-high | C24 plus mode geometry/active fields; no xrefs | UID0000ZA/active class/file | Applied | Owner/emitter UID0000G2 and exact body verified; generated active count 1, old count 0. |
| C26 | Old constructor close button is local; only browser pointer is stored at inherited `+0x26c`. | High | Current constructor disasm | UID0000ZB/old class | Applied | Exact constructor/class blocks verified; `8811`/`8799`; generated local declaration present. |
| C27 | Old class block removes `RefreshOldLayout` and private `m_closeButton +0x278`; browser control storage is inherited BrowserPane state. | High | C13/C24/C26 and BrowserPane size | old class | Applied | Exact old-class block verified; generated old declaration has neither rejected member nor method. |
| C28 | Adjustor/vtable/global docs need synchronized detail but no score inflation. | High | Current direct checks | UID000337/UID0001OB/global/storage/file | Applied/already present | Adjustor/vtable/file validators `8816`/`8817`/`8815`; support scores unchanged; singleton docs already sufficient. |
| C29 | Stable target UID/path, reconstructable true, blank position, `Nested:6`, and no split/merge/new child remain correct. | High | Exact model, route, and address-sorted nesting transition | target metadata | Preserved | Source header and generated route verified; `8797`/`8818`. |
| C30 | Reject handwritten wrapper, blank/no-evidence block, Boost ownership, Browser/MemoryMan/global direct ownership, old-layout ownership, and active/old merge. | High | Positive and negative evidence | target/support rejection sections | Applied | Rejections preserved in target/class/file/layout support; no unrelated owner or body introduced. |

## Positive Evidence Summary

- Exact disassembly gives all target operations and all three delete-mode outcomes.
- Three old-class vtable views converge on one complete-object wrapper through direct and adjusted routes.
- Constructor allocation `0x278` independently corroborates wrapper guarded size `0x278`.
- Ordinary and deleting bodies share precisely the derived singleton clear and inherited destruction lowering.
- Decorated vtable identities, singleton identity, old constructor, and old source family agree on UID0000G3 ownership.
- Active sibling parity proves the compiler pattern while its `0x37c` size distinguishes active-only tail fields from old layout.

## IDA MCP Facts

- UID00033F: `sub_4707F0`, size 95 decimal / `0x5f`.
- Instructions: singleton clear; BrowserPane vtables `0x6132ec/0x613360/0x613390`; call `0x49d9f0`; tests `flags & 1` and `flags & 4`; optional `0x4f4ac0`; guarded `this,0x278` call to `0x41b6a0`; return original pointer.
- Xrefs to target: `0x4702ec`, `0x4702f7`, and `0x61368c`.
- Ordinary destructor `sub_46E8C0`: size `0x29`, five instructions, zero inbound xrefs.
- Base cleanup `0x49d9f0`: size `0xdb`, actual DialogPane teardown with 75-class-family fan-in despite polluted name.
- Delete helper `0x4f4ac0`: size `0x40`, calls `0x516030` GetMemoryMan route and `0x516170` FreeBufferMemory route.
- Guard helper `0x41b6a0`: size 1, no callees, no side effects.
- Active sibling `0x470790`: same `0x5f` wrapper shape, active singleton `0x67ab9c`, and size immediate `0x37c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046a8a0-0x0046a8bf` | UID000408 BrowserPaneNonDeletingDestructor | empty source `BrowserPane::~BrowserPane()`; vptr/base lowering | TRUE | UID000019 | `88/90` | inherited base source support |
| `0x0046e640-0x0046e8be` | UID0000ZB WebBoardDialogOldConstructor | old constructor, `0x278` object | TRUE | UID0000G3 | `90/91` | corrected local close-button expression; inherited browser pointer retained |
| `0x0046e8c0-0x0046e8e9` | inside UID000212 | ordinary old destructor | TRUE | UID0000G3 | cluster `86/91` | singleton-only source body is complete |
| `0x00470260-0x0047026b` | mixed cleanup support | constructor-EH singleton clear helper | generated | NONE | support | no standalone method |
| `0x004702e6-0x004702f1` | inside UID000337 | `-0xa0` deleting adjustor | generated | NONE | `86/90` | vtable-reached thunk |
| `0x004702f1-0x004702fc` | inside UID000337 | `-0xa4` deleting adjustor | generated | NONE | `86/90` | vtable-reached thunk |
| `0x00470790-0x004707ef` | UID00033E | active scalar deleting wrapper | TRUE/routed | UID0000G2 | `86/90` | sibling, active size `0x37c` |
| `0x004707f0-0x0047084f` | UID00033F target | old scalar deleting wrapper | TRUE/routed | UID0000G3 | `90/93` | exact no-duplicate target implemented |
| `0x0046e2a0-0x0046e4b6` | UID0000ZA | active layout refresh historically misowned as old | TRUE | UID0000G2 | `88/90` | reclassified; score/range/path unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061368c` | primary vtable -> UID00033F | complete-object deleting dispatch |
| `0x00613700` | secondary vtable -> `0x4702e6` | adjust `this -= 0xa0`, jump target |
| `0x00613730` | tertiary vtable -> `0x4702f1` | adjust `this -= 0xa4`, jump target |
| `0x00508dbb/0x00508ddd` | allocate 632, call old constructor | first old allocation route |
| `0x00514601/0x0051461e` | allocate 632, call old constructor | second old allocation route |
| `0x004707f6` | clear `0x0067aba0` | deleting-wrapper singleton parity |
| `0x0047081a` | call `0x0049d9f0` | DialogPane inherited teardown |
| `0x0047082b` | call `0x004f4ac0` | ordinary storage-free path |
| `0x00470840` | call `0x0041b6a0(this,0x278)` | guarded flag-4 path |
| `0x005fae35` | constructor EH -> BrowserPane destructor | base construction unwind, not source caller |
| `0x005fae43` | constructor EH -> singleton clear helper | partial-construction cleanup |

## Documentation Evidence And IDA Status

- UID00033F correctly preserves owner/emitter, no-hand-wrapper direction, and relative `Nested:6` delta, but its wrapper evidence remains shallow.
- UID000212 carries correct ordinary destructor C++ but its Item Summary falsely says final C++ remains blank and underexplains generated vptr/base effects.
- UID0000G3 declares the virtual destructor but incorrectly includes `RefreshOldLayout` and `m_closeButton +0x278`.
- UID0000ZB formal C++ incorrectly treats the constructor's close button as a member; current disassembly proves it is local.
- UID0000ZA correctly records `+0x278/+0x26c` and mode behavior but assigns them to the wrong class.
- UID000337 accurately records both adjustors but lacks the complete current target/size/source-declaration relation.
- UID0001OB records old vtable data generally; it should include exact primary/secondary/tertiary destructor cells and RTTI locator adjacency.
- Singleton global/storage docs already carry all five lifecycle refs at same-or-greater detail; only optional synchronization is needed.
- Generated output currently exposes all four source-shape consequences: good ordinary body and marker, wrong old close-button member, wrong old constructor expression, and wrong old ownership for UID0000ZA.

## Ranked Ownership Analysis

### 1. [UID:0000G3] WebBoardDialogOld

- Evidence for: decorated old vtable names, old singleton clear, old constructor vptr stores, three old vtable destructor routes, ordinary old destructor, and old source family.
- Evidence against: exact wrapper instructions are compiler ABI output rather than handwritten method source.
- Decision: retain as direct canonical owner and emitter because the class declaration/destructor causes this generated body.

### 2. [UID:0000P9] WebBoardDialog source file

- Evidence for: active and old classes, singleton definitions, constructor/destructor/callback/helper family, and current generated route.
- Evidence against: direct method ownership belongs to the class when the class clears the gate.
- Decision: retain as source module route, not direct target owner.

### 3. [UID:000019] BrowserPane and [UID:00003T] DialogPane

- Evidence for: wrapper restores BrowserPane vtables and executes DialogPane teardown.
- Evidence against: inherited/base cleanup does not own the derived singleton clear or old vtable slots.
- Decision: dependencies/base declarations only.

### 4. [UID:0000SR] g_pWebBoardDialogOld and MemoryMan

- Evidence for: target clears singleton storage and may free through MemoryMan.
- Evidence against: written storage and allocator are dependencies; neither owns the class method or vtable dispatch.
- Decision: support pages only.

### 5. UID0000ZF broad Browser/OLE aggregate, UID000337 mixed thunk page, or owner NONE

- Evidence for: physical locality and thunk containment.
- Evidence against: aggregates are mixed/non-emitting; exact old class identity and direct class route are established.
- Decision: reject as owner.

### Proposed new file/grouping, if applicable

- No new file/grouping is required.
- Existing `NexusTK/ui/dialogs/WebBoardDialog.cpp` remains the correct broad source module.
- UID0000ZA moves between existing active/old class owners inside the same file; no new page or physical filename is required.

## Source Placement

- Place source declarations and ordinary old destructor in `NexusTK/ui/dialogs/WebBoardDialog.cpp` through UID0000P9.
- Emit UID00033F only as a documentation marker through UID0000G3; let the compiler generate executable deleting-wrapper bytes.
- Keep allocator implementation under MemoryMan and base destructors under BrowserPane/DialogPane source roots.
- Rejected placements: Browser.cpp, MemoryMan.cpp, singleton-only source, standalone DestructorWrappers.cpp, RankingDialog, or ownerless mixed Browser/OLE aggregate.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact `0x004707f0-0x0047084f`; no split or merge.
- One byte `0xCC` at `0x004707ef` is predecessor alignment and belongs to neither wrapper.
- UID00033F ends at the next body start `0x0047084f`; no successor padding should be added.
- `Nested:6` is unrelated to whether the exact function has children. In address order, UID00033D is rendered at cumulative indentation 134; UID00033E's `Nested:-6` lifts to 128; target UID00033F's `Nested:+6` restores 134; successor UID00033G's `Nested:0` keeps 134. Retaining 6 preserves the generated hierarchy; changing it to 0 would incorrectly leave UID00033F and its zero-delta successors six columns too high at level 128.
- UID0000ZA requires semantic reclassification, not a range change: same `0x0046e2a0-0x0046e4b6` bytes, stable UID/path, active owner/emitter UID0000G2, source-facing `WebBoardDialog::RefreshLayout(int mode)`.
- No target child, ignored subrange, duplicate range, or mixed target ownership remains.

## Negative Evidence Summary

- No direct ordinary-destructor xref exists; this does not invalidate source destructor emission because generated deleting dispatch duplicates/inlines its lowering.
- No source-shaped direct caller targets UID00033F. All routes are primary vtable or compiler adjustors.
- No old constructor instruction stores the close button at `+0x278`; generated old-constructor C++ is wrong on that point.
- UID0000ZA has no entry xrefs and uses an offset exactly one-past the old allocation; it cannot prove an old-class live member.
- Active/old wrapper adjacency does not imply one class: distinct singleton globals, vtable sets, constructor families, RTTI locators, and object sizes separate them.
- The polluted Boost label does not prove Boost ownership; current base body behavior is DialogPane-specific.
- `0x004f4ac0` and `0x0041b6a0` are runtime/compiler dependencies, not source methods on WebBoardDialogOld.
- A real `WebBoardDialogOld::ScalarDeletingDestructor(char)` source function is rejected because it exposes non-source ABI flags and duplicates destruction/free logic.
- A blank formal block is rejected because it would erase the resolved source-declaration dependency and generated-binary disposition.

## IDA Rename / Type / Comment Recommendations

- Source-facing target description: `WebBoardDialogOld scalar deleting destructor`; no IDA rename is required for this documentation callback.
- Treat target prototype as compiler-internal `WebBoardDialogOld *(WebBoardDialogOld *this, unsigned int deletingFlags)`; do not expose it in project headers.
- Comment `0x0049d9f0` in documentation as `DialogPane::~DialogPane` ordinary/base teardown; reject IDA's Boost name.
- Source-facing UID0000ZA name: `WebBoardDialog::RefreshLayout(int mode)`, explicitly inferred/descriptive because entry xrefs are absent.
- Source-facing old constructor local: `ImageButtonControlPane *closeButton`; inherited field: `m_browserControlPane` at `+0x26c`.
- No IDA database mutation is requested or permitted by this report-only assignment.

## First-Draft C++ Recommendation

UID00033F should use this exact managed no-duplicate marker:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated MSVC scalar deleting destructor for WebBoardDialogOld.
// Reconstruct virtual ~WebBoardDialogOld() and the ordinary destructor body emitted by UID000212.
// Let the compiler regenerate vtable deleting dispatch, +0xa0/+0xa4 adjustor thunks,
// BrowserPane/DialogPane base destruction, deleting-flag handling, the 0x278 guarded-size path,
// return-this ABI behavior, and storage release. Do not hand-author this wrapper.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Complete corrected `WebBoardDialogOld` class managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WebBoardDialogOld : public BrowserPane
{
public:
    WebBoardDialogOld(const unsigned char *initialResponsePayload,
                      OLECHAR *initialUrl);
    virtual ~WebBoardDialogOld();

    virtual void OnCloseStateChanged(int state, int reason);
    virtual bool OnInputEventWithBrowserReposition(InputEvent *event);
    virtual bool OnWebBoardPacket(void *event);

    bool HandleBoardResponse(const unsigned char *payload);
    void SendInitialBoardRequest();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Complete corrected UID0000ZB old-constructor managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WebBoardDialogOld::WebBoardDialogOld(const unsigned char *initialResponsePayload,
                                     OLECHAR *initialUrl)
    : BrowserPane(L"", -1, true)
{
    g_pWebBoardDialogOld = this;

    Rect frameRect(0, 0, 540, 379);
    ImagePane *frame =
        new ImagePane(L"WEBBOARD.EPD", frameRect, true, L"WEBBOARD.PAD");
    AddChild(frame);

    Rect closeRect(234, 342, 306, 358);
    ImageButtonControlPane *closeButton =
        new ImageButtonControlPane(30, closeRect);
    AddChild(closeButton);

    Rect browserRect(30, 30, 510, 334);
    m_browserControlPane = new BrowserControlPane(browserRect,
                                                  initialUrl,
                                                  this);
    AddChild(m_browserControlPane);

    Rect dialogRect(50, 50, 590, 429);
    SetBackgroundImage(L"WEBBOARD.EPD", 0);
    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(true);
    SetEnabled(true);

    if (initialResponsePayload != NULL)
        HandleBoardResponse(initialResponsePayload);
    else if (initialUrl == NULL)
        SendInitialBoardRequest();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Complete UID000212 managed block; destructor source remains singleton-only while unrelated accepted callbacks are preserved:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WebBoardDialogOld::~WebBoardDialogOld()
{
    g_pWebBoardDialogOld = NULL;
}

void WebBoardDialogOld::OnCloseStateChanged(int state, int reason)
{
    (void)reason;

    if (state != 1)
        return;

    OnBrowserDialogClosed();

    if (m_browserControlPane != NULL)
        m_browserControlPane->Shutdown();

    HideDialog();
    ReleaseDialogControls();

    if (g_pApplicationCleanupQueue != NULL)
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}

bool WebBoardDialogOld::OnInputEventWithBrowserReposition(InputEvent *event)
{
    const bool handled = DialogPane::OnInputEvent(event);

    if (event != NULL && event->type == 0 && m_isTitleDragActive &&
        g_activeBrowserControlPane != NULL && m_browserControlPane != NULL)
    {
        RECT browserClient;
        ::GetClientRect(g_activeBrowserControlPane->GetBrowserWindow(), &browserClient);

        Rect dialogRect;
        GetPaneRect(&dialogRect);

        ::MoveWindow(m_browserControlPane->GetBrowserWindow(),
                     dialogRect.left + 30,
                     dialogRect.top + 30,
                     browserClient.right - browserClient.left,
                     browserClient.bottom - browserClient.top,
                     FALSE);

        if (g_pScreenPane != NULL)
            g_pScreenPane->Refresh();
    }

    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Complete active `WebBoardDialog` class block with the reclassified method declaration:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WebBoardDialog : public BrowserPane {
public:
    WebBoardDialog(int boardMode,
                   const wchar_t *boardOwnerName,
                   const void *initialResponsePacket,
                   OLECHAR *initialUrl);
    virtual ~WebBoardDialog();
    virtual void OnCloseStateChanged(int state, int reason);
    virtual int OnInputEventWithBrowserReposition(void *event);
    virtual bool OnPacket(void *event);
    virtual bool OnKeyEvent(InputEvent *event);

    void RefreshLayout(int mode);
    bool HandleBoardResponse(const void *packet);
    void SendInitialBoardRequest(unsigned char boardMode);

protected:
    BrowserControlPane *m_browserControlPane; // +0x26c
    ImageButtonControlPane *m_closeButton;    // +0x278
    wchar_t m_boardOwnerName[0x80];           // +0x27c
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Complete reclassified UID0000ZA managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void WebBoardDialog::RefreshLayout(int mode)
{
    ReleaseDialogControls();
    DetachDialogChildren();
    RemoveControl(1);
    RemoveControl(0);
    SetVisible(true);
    SetEnabled(false);

    if (m_closeButton != NULL)
        m_closeButton->Destroy(true);

    if (m_browserControlPane != NULL)
        m_browserControlPane->Destroy(true);

    Rect closeRect;
    if (mode == 0 || mode == 4)
        closeRect.Set(318, 468, 381, 492);
    else if (mode == 6)
        closeRect.Set(368, 568, 431, 592);

    m_closeButton = new ImageButtonControlPane(14, closeRect);
    AddChild(m_closeButton);

    Rect browserRect;
    if (mode == 0)
        browserRect.Set(11, 42, 689, 460);
    else if (mode == 4)
        browserRect.Set(11, 42, 407, 526);
    else if (mode == 6)
        browserRect.Set(11, 42, 789, 560);

    m_browserControlPane = new BrowserControlPane(browserRect, NULL, this);
    AddChild(m_browserControlPane);

    Rect dialogRect;
    if (mode == 0)
        dialogRect.Set(162, 134, 862, 634);
    else if (mode == 4)
        dialogRect.Set(303, 101, 721, 667);
    else if (mode == 6)
        dialogRect.Set(112, 84, 912, 684);

    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(false);
    SetEnabled(false);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- These blocks preserve exact behavior without exposing deleting flags as a source API.
- Third-party import directive: not applicable; this is project-authored class code plus compiler-generated ABI.

## Final Recommendation

- C01-C30 are applied at report-level detail or explicitly proven already present.
- UID00033F is `90/93`; `Nested:6`, UID0000G3 owner/emitter, reconstructable true, blank position, stable range/path, and marker-only no-duplicate policy are preserved.
- UID000212's complete ordinary destructor/callback block is unchanged; stale summary/prose is corrected and the wrapper relationship is explicit.
- UID0000ZA is active UID0000G2 `WebBoardDialog::RefreshLayout(int mode)` with unchanged score/range/path and the exact complete block above.
- Old class and constructor complete blocks no longer contain active-only `+0x278` close-button state; the local close button and inherited `+0x26c` browser pointer match evidence.
- Vtable, adjustor, file, and already-proven singleton support are synchronized without unrelated score inflation.
- No implementation item remains; no new file, split, imported source, manual tracker edit, or sibling edit was required.

## Recommended Target Doc Changes

- Target: `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md`.
- Applied metadata: `86/90 -> 90/93`; retained `Nested:6` as the proven address-sorted relative delta and preserved owner/emitter/reconstructable/position/path.
- Applied the exact target marker above.
- Added exact 29-instruction behavior, flag table, `0x278` size/allocation proof, primary/adjustor/RTTI inventory, ordinary-body relationship, singleton lifecycle, base/delete helpers, exact boundaries, generated-binary disposition, and rejected alternatives.
- Historical B001/B008/B010 marker decisions were preserved as earlier shallow states superseded by current evidence, not as current completeness proof.

## Recommended Support Doc Changes

Current implementation result: all accepted support changes are complete. UID000212's exact block stayed unchanged while its stale summary/prose was corrected; both class blocks and the old constructor are exact matches to the managed payloads; UID0000ZA is active UID0000G2 with unchanged score/range/path; file, adjustor, and vtable evidence is synchronized; singleton docs and active UID00033E were already sufficient and remained unedited. All support scores are unchanged except the accepted old-class confidence increase `88 -> 90`.

Historical accepted callback plan, retained to show full intended scope (all required items below are complete):

- `by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md`: preserve complete formal block and `86/91`; correct the Item Summary's false “final C++ remains blank,” state that singleton-only destructor source is complete, and add ordinary/deleting comparison, no-xref fact, generated vptr/base chain, and target link.
- `by-class/WebBoardDialogOld.md`: apply the complete corrected class block; remove `RefreshOldLayout` and old-private `m_closeButton +0x278`; identify `m_browserControlPane +0x26c` as inherited BrowserPane storage; add size `0x278`, vtable/adjustor/ordinary/deleting relations. Recommend `90/88 -> 90/90` because false layout ownership is resolved while other class callback-name caveats remain.
- `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md`: apply complete corrected constructor block using local `closeButton`; preserve score/metadata and all unrelated constructor evidence.
- `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md`: preserve UID/path/range and score `88/90`; change owner/emitter `0000G3 -> 0000G2`, title/source role to active `WebBoardDialog::RefreshLayout(int mode)`, and apply complete block above. Preserve no-xref status and all rectangle/control behavior.
- `by-class/WebBoardDialog.md`: apply complete block above adding only `RefreshLayout(int mode)`; preserve existing declarations, fields, metadata, and score.
- `by-file/WebBoardDialog.md`: record the exact old wrapper source-declared/generated-binary disposition, old size `0x278`, active size `0x37c`, and UID0000ZA active-class correction; preserve file score/path and broader family content.
- `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md`: add current old target cells and exact `-0xa0/-0xa4` routes; preserve non-reconstructable, ownerless, non-emitting metadata and score.
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`: add old primary/secondary/tertiary deleting cells and RTTI locator adjacency; preserve mixed data aggregate disposition and score.
- `by-global/g_pWebBoardDialogOld.md` and `by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md`: current five-ref lifecycle and source definition/duplicate-storage policy are already same-or-greater; no required edit unless synchronization wording is desired.
- `by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md`: no required edit; use only as active sibling parity. Do not copy old size `0x278` over its current active `0x37c` behavior.
- No manual generated, coverage, tracker, registry, supervisor, or lifecycle file edit is recommended.

## Score And Metadata Recommendation

- UID00033F historical pre-callback: `86/90`, UID0000G3 owner/emitter, reconstructable true, blank position, `Nested:6`.
- UID00033F current implemented state: `90/93`, same owner/emitter/reconstructable/position and retained `Nested:6`.
- Completion rises for exact instruction/flag/delete/base/vtable/adjustor/RTTI/allocation/size/boundary/source-declaration/no-code proof and support-layout correction.
- Confidence rose because the evidence-time MCP pass independently confirmed every binary claim and active/old comparison resolved the field contradiction. It remains below 95 because original source/PDB and exact compiler-internal naming are unavailable.
- Old class applied `90/88 -> 90/90`; its broad remaining callback/helper-name caveats prevent a larger increase.
- UID0000ZA stays `88/90`; ownership/type improves, but zero entry xrefs and inferred exact helper spelling remain confidence caps.
- All other support scores remain unchanged.

## Open Questions With Attempted Resolution

- Is UID00033F handwritten? Checked body shape, flags, vtable-only routing, adjustors, ordinary duplicate, base/delete helpers, and sibling wrappers. Resolution: no; source-declared/generated-binary.
- Is UID000212 missing explicit BrowserPane/DialogPane calls? Compared ordinary and deleting disassembly plus C++ destruction lowering. Resolution: no; singleton-only derived body is complete.
- Does flag 4 mean vector delete, placement suppression, or another internal mode? Checked exact branch, one-byte helper, size immediate, and sibling patterns. Resolution: record exact bit-4 guarded-size behavior without inventing a source enum; it has no source-header impact.
- Is `0x278` object size? Checked two old allocation sites and target immediate. Resolution: yes for old object.
- Can `m_closeButton +0x278` belong to old class? Checked old constructor stores, old allocation size, UID0000ZA accesses, active class fields, and active wrapper size `0x37c`. Resolution: no; UID0000ZA is active-class code and old constructor button is local.
- Is `RefreshLayout` exact original spelling? Checked current names, function behavior, class methods, xrefs, and old/active layout. Best supported descriptive spelling is `WebBoardDialog::RefreshLayout(int mode)`; absence of an original symbol caps only that support method's name confidence, not target score or ownership.
- Does target need split/rename/new child? Checked exact boundary bytes and next body. Resolution: no.
- Is `Nested:6` a stale child count? Checked validator README lines 592-598, source metadata for UID00033D/33E/33F/33G, and generated address-sorted indentation. Resolution: no; it is the exact `+6` transition restoring cumulative level 134 after UID00033E's `-6` transition to 128. It must remain 6 even though UID00033F itself has no child ranges.
- No open question blocks target metadata, owner/emitter, marker, source declaration, ordinary body, or callback implementation plan.

## Follow-Up Actions

- No additional B-agent binary research or implementation item remains for UID00033F.
- Implementation, scoped validation, and waited generated verification are complete. Report validation, execution, count, current path, move, and archive state are external supervisor/validator-owned lifecycle facts; this artifact neither asserts nor directs them.
- A later BrowserPane declaration audit may centralize inherited `m_browserControlPane +0x26c`; that broader class-shell work is not required to remove the proven false old `m_closeButton +0x278` declaration now.

## Confidence

- Recommendation confidence: very high.
- Target score confidence: high for `90/93`.
- Remaining uncertainty: exact original source spelling of active `RefreshLayout` and internal MSVC flag nomenclature only; neither affects target behavior, source declaration, owner, emitter, range, or no-duplicate C++ disposition.

## Validator Results

- Historical rejected invocation: `000000008796`, `2026-07-12T21:06:20-04:00`, exit 1, before validation; obsolete `--skip-generated` was rejected by argparse. It changed no file and was immediately corrected to the documented `--no-generated-refresh` form.

| File / scope | Command ID | Timestamp | Exit | ok | Generated state |
| --- | --- | --- | ---: | ---: | --- |
| UID00033F target | `000000008797` | `2026-07-12T21:06:26-04:00` | 0 | 1 | skipped by scoped command |
| `by-class/WebBoardDialogOld.md` | `000000008799` | `2026-07-12T21:09:12-04:00` | 0 | 1 | skipped by scoped command |
| UID000212 | `000000008805` | `2026-07-12T21:10:11-04:00` | 0 | 1 | skipped by scoped command |
| UID0000ZB constructor | `000000008811` | `2026-07-12T21:10:56-04:00` | 0 | 1 | skipped by scoped command |
| UID0000ZA layout | `000000008812` | `2026-07-12T21:11:59-04:00` | 0 | 1 | skipped by scoped command |
| `by-class/WebBoardDialog.md` | `000000008813` | `2026-07-12T21:12:38-04:00` | 0 | 1 | skipped by scoped command |
| `by-file/WebBoardDialog.md` | `000000008815` | `2026-07-12T21:14:09-04:00` | 0 | 1 | skipped by scoped command |
| UID000337 adjustor index | `000000008816` | `2026-07-12T21:14:44-04:00` | 0 | 1 | skipped by scoped command |
| UID0001OB vtable index | `000000008817` | `2026-07-12T21:15:17-04:00` | 0 | 1 | skipped by scoped command |
| final autogen, waited | `000000008818` | `2026-07-12T21:15:31-04:00` | 0 | n/a | completed |

- Scoped validators reported known pre-existing missing-reference warnings for UID000408, UID0003V2-UID0003V4, and UID0003OH references; every changed file itself returned `ok:1`. No warning was target-specific.
- Final generated header is `validator-command-id: 000000008818` and `validator-refreshed-at: 2026-07-12T21:15:31-04:00`, equal to the waited command proof.
- Read-only generated checks: UID00033F count 1; target Empty Emitter Marker count 0; exact target marker count 1; `WebBoardDialogOld::~WebBoardDialogOld()` count 1; `WebBoardDialog::RefreshLayout(int mode)` count 1; `WebBoardDialogOld::RefreshOldLayout` count 0. The old constructor emits local `ImageButtonControlPane *closeButton`; all six managed blocks match their report payloads exactly after newline normalization.

## Changed Files

- Modified target: `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md` (`79E219F5EB18F887F33F7E01A7CAA920F832762419EA60C90C53A6009D1C6BBD`).
- Modified support: `by-class/WebBoardDialogOld.md` (`773F2643FEBFB8DFA1ED4A50761C5B4E62D16484F4F683CEEA7F8D4F26099B04`).
- Modified support: `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md` (`6C7724950E485458D5A566EC84914034304C57B91DFDC0F714ADB5974071EE7B`).
- Modified support: `by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md` (`2EF0AC8DD70523A3A681BC96FA3B55CE064B920352997121E97286EC96625921`).
- Modified support: `by-class/WebBoardDialog.md` (`291AAD99F26D25E691FF3A6ABA8F584045BF49B3A8101E907DBC6A76B2BA18B0`).
- Modified support: `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md` (`C5CB9ACD7FFB8C337A3CD19D1DA457426ACF74958E303E4C95D8E5BBD9BD8068`).
- Modified support: `by-file/WebBoardDialog.md` (`465EC656A1346B391866911BB4C2F526BB7C371A8462F1F25929DE3E8DCB6E67`).
- Modified support: `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md` (`0679DEF695328202AFDE167271016FF65DEF85B99722296EA7CF58744D521289`).
- Modified support: `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` (`D0FF2E2727D8BE13C3E98117712FE9748F71A6D92AB4BC095A97725C4FA25D1E`).
- Modified this same research artifact to record callback proof. No by-* file was renamed or created.
- Validator-owned side effects: final autogen refreshed `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`, generated reports, tracker, coverage, registry, and projected stats. B004 did not edit those files manually.
- Leases: each by-* file was leased only immediately before its edit/validation and released immediately afterward; final lease search returned no B004 row.
- Report lifecycle: B004 performed no execute, lifecycle, move, or archive command. Supervisor/validator-owned state is external.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor accepted exact report SHA `37292F45B2CD340583A643DB5774A6AB133FB37AF6A8E03EE40ABFE56F261AF5` before implementation.
- [x] Target and every triggered support doc are enumerated path by path.
- [x] Current target metadata, marker, generated route, tracker snapshot, and lifecycle-neutral report state recorded.
- [x] Evidence-time MCP schema/session/health pass completed against then-healthy `bf5519ae`; later session expiry is recorded without an indefinite availability claim.
- [x] Exact wrapper range, bytes, instructions, blocks, padding, and successor boundary resolved.
- [x] Primary vtable, two adjustor thunks, RTTI locator adjacency, singleton, ordinary destructor, base chain, delete helper, and guard path resolved.
- [x] Both old allocation routes and exact `0x278` object size resolved.
- [x] UID000212 ordinary destructor source body confirmed complete.
- [x] Active sibling parity and active `0x37c` size checked.
- [x] UID0000ZA active/old ownership contradiction resolved to active UID0000G2.
- [x] Claim And Incorporation Ledger C01-C30 has destination/action/verification state.
- [x] Target metadata plan is `86/90 -> 90/93`, with correct relative `Nested:6` and owner/emitter/reconstructable/position preserved.
- [x] No split, merge, physical rename, new child, or import directive applies.
- [x] Exact target marker and five complete destination-specific support managed blocks supplied.
- [x] Historical/shallow marker evidence, rejected Boost/handwrapper/owner/layout alternatives, and negative evidence preserved.
- [x] Score-limiting blockers are resolved; only nonblocking source-spelling caps remain.
- [x] One immediate lease, edit, successful scoped validator, and immediate release completed for each of nine accepted changed by-* files.
- [x] Final waited generated refresh `000000008818` and read-only target marker/ordinary-body/class-layout checks completed.

Implementation callback pass:

- [x] Exact report artifact accepted by supervisor.
- [x] C01-C30 incorporated at report-level detail or marked already-present with claim-specific proof.
- [x] UID00033F target score change applied while `Nested:6` is retained; marker, evidence, and rejection sections applied.
- [x] UID000212 summary/prose corrected while complete formal block remains unchanged.
- [x] Old class and constructor complete blocks corrected without losing unrelated content.
- [x] UID0000ZA reclassified to UID0000G2 with complete active method block and score/range/path preserved.
- [x] Active class complete block updated with only the new declaration.
- [x] File/vtable/adjustor support synchronized without unrelated score inflation.
- [x] Historical/rejected/negative evidence preserved.
- [x] Scoped validator command IDs, timestamps, exits, and ok counts recorded per changed by-* file.
- [x] Generated refresh awaited; one UID00033F marker, one UID000212 ordinary body, corrected active/old declarations, and no duplicate wrapper body verified read-only.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000008836","destination_path":"executed-b-agent-research/B004/00033F-WebBoardDialogOldScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00033F-WebBoardDialogOldScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-12T21:25:31-04:00","uid":"00033F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
