
# NewPredefinedFormArticleDialog Whole-File Source-Quality Report
** TARGET-REPORT-UID:0000LT **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

The accepted implementation retains [UID:0000LT] as the unique compilation-unit root for `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`, raises the file to `94/94`, and supplies the formal source needed for a matching `NewPredefinedFormArticleDialog.h`. The source-authored inventory is ten bodies: the constructor, retained previous-selection helper, command handler, timer callback, hover forwarder, paint method, file-local form parser, full-packet transfer-reply handler, retained payload handler, and submit helper. The two destructor adjustors and scalar deleting destructor are compiler ABI products and remain non-emitting. Foreground validator command `23592` coherently refreshed the generated CPP/H, and physical readback confirms the class preamble, all ten bodies, and the complete H declaration exactly match Section 22.

The pre-callback source route contained three material misclassifications, all now corrected in ordinary documentation. [UID:0002UM] is `TimerHandler::OnTimer(int,int,int)`, not a generic `HandleEvent(void *,int,int)`; [UID:0002UO] is `void OnPaint()`, not an `int` method; and [UID:0002UR] is the retained source-authored payload-layout companion to the live packet handler, not an unknowable blank-code orphan. The constructor is now populated from the dated 2026-08-14 read-only MCP evidence snapshot that resolves its direct base, argument roles, complete `0x5368` object layout, `0x40c` row type, dynamic control creation, two resource layouts, caller, and all helper roles. That mutable snapshot is non-authoritative for later IDA state; its older no-code decision is nevertheless superseded by the stable evidence.

The class formal H now declares direct inheritance from `BulletinDialog`, the seven-field naturally padded `PredefinedFormArticleEntry` structure, the five virtual overrides evidenced by the three vtable views, two private retained helpers, `SubmitArticle(unsigned short)`, the two count fields, and the twenty-entry array. The contiguous aggregate [UID:0000ZL] and duplicate by-item alias [UID:0000UE] are now non-reconstructable, non-emitting indexes after all exact children route through the class/file. New non-emitting [UID:00050Q] documents the compiler-generated vtable band `[0x0061404c,0x006140ec)`.

## Supporting Research

The whole-file decision combines a dated 2026-08-14 read-only IDA MCP evidence snapshot, every related by-* page, the current validator-generated source, and matching archived reports. Session `supervisor-uid0000IW-recovery-20260814` and path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` remain historical research-evidence locators. At capture time, health was `status:ok`; bounded decompilation, type, byte, xref, function, and data queries succeeded, and `auto_analysis_ready:false` did not prevent the bounded checks. The supervisor later established independent mutable authority for Gate 2B under canonical session `supervisor-uid0000KZ-gate2b-20260814`; Section 21 records the dated closure receipt without granting the older research session continuing authority.

The main code cluster is `[0x004777a0,0x00478f8e)`. Nine bodies are IDA-modeled and one source-shaped retained navigation body at `[0x004781f0,0x00478238)` is raw/unmodeled. The cluster contains ten exact `0xcc` alignment gaps and no unidentified executable bytes. Three distant compiler bodies complete the class ABI: adjustors at `0x0047e931` and `0x0047e93c`, and the scalar deleting destructor at `0x0047ec30`.

The `0x0061404c-0x006140ec` data band contains three complete-object views: a primary table with 24 slots, an `EventHandler` secondary table with 11 slots, and a `TimerHandler` tertiary table with two slots. Constructor stores at `0x004777ee`, `0x004777f4`, and `0x004777fe` install those views at complete-object offsets `0`, `+0xa0`, and `+0xa4`. RTTI names a nine-base hierarchy and identifies `BulletinDialog` as the direct source base. The compiler's direct `DialogInSession` constructor call is consistent with an optimized/trivial intermediate `BulletinDialog` constructor and does not justify skipping the direct source base.

## Target

- Primary UID: `0000LT`.
- Primary path: `by-file/NewPredefinedFormArticleDialog.md`.
- Implemented source: `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`.
- Required sibling declaration file: `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.h`.
- Direct class owner: [UID:000098] `by-class/NewPredefinedFormArticleDialog.md`.
- Exact main aggregate: [UID:0000ZL] `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`.
- Exact source-bearing children: [UID:0002UJ], [UID:0002EK], [UID:0002UK], [UID:0002UM], [UID:0002UN], [UID:0002UO], [UID:0002UP], [UID:0002UQ], [UID:0002UR], and [UID:0002UL].
- Compiler-only companions: [UID:0000ZQ] and [UID:0000ZS].
- Duplicate parser alias: [UID:0000UE].
- Vtable-family support: [UID:0001X4].
- Additional UID declaration: none. Related UIDs are support scope and retain independent evidence/dispositions below.

## Current Target State

| Page / output | Current state | Whole-file defect |
| --- | --- | --- |
| UID0000LT by-file | `94/94`, owner `FILE`, path `NexusTK/ui/dialogs/` | Whole-file inventory, source contract, historical corrections, resource/dependency set, and CPP/H routing are incorporated. |
| UID000098 class | `94/94`, owner/emitter UID0000LT, reconstructable | Exact accepted CPP preamble and H declaration are populated; all ten child definitions route through `[[CHILDREN]]`. |
| UID0000ZL aggregate | `94/94`, contextual owner UID0000LT, non-reconstructable, no emitter | Exhaustive physical index over ten exact source children and ten alignment gaps; blank formal source is intentional. |
| UID0000UE parser alias | `92/94`, contextual owner UID0000LT, non-reconstructable, no emitter | Duplicate search alias is covered by UID0002UP and the class-H row declaration. |
| UID0002UJ constructor | `93/94`, class-owned/emitted | Exact accepted constructor CPP is populated and prior blank-source blockers are resolved. |
| UID0002UM timer callback | `94/94`, class-owned/emitted as `OnTimer` | UID-preserving path/title rename and exact TimerHandler formal source are complete. |
| UID0002UO paint | `93/94`, class-owned/emitted as `void OnPaint` | Exact current/legacy paint branches are populated without an artificial return value. |
| UID0002UR retained payload helper | `92/93`, class-owned/emitted | UID-preserving payload-helper rename and exact retained formal source are complete; zero-xref evidence remains historical context. |
| Validator-generated CPP/H | command `23592`, timestamp `2026-08-14T16:39:03-04:00`, foreground refresh completed | CPP has the class preamble plus ten exact source bodies; H exactly matches the complete formal declaration. Physical readback found no empty marker, unresolved child placeholder, TODO, or source-order loss. |
| New vtable child UID00050Q | `94/95`, non-reconstructable, no emitter | Exact `[0x0061404c,0x006140ec)` three-view COL/vtable band is documented and linked from UID0001X4. |

## Executive Recommendation

1. Keep UID0000LT as the file root and UID000098 as the sole source class emitter.
2. Put the complete class/row declarations in UID000098's formal H block and a small include/parser-forward-declaration plus `[[CHILDREN]]` in its CPP block.
3. Populate exact formal CPP on all ten source-authored children; do not emit the aggregate, alias, vtable bytes, thunks, or scalar deleting destructor.
4. Rename UID0002UM's path/title to `NewPredefinedFormArticleDialogOnTimer` and UID0002UR's path/title to `NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload` while preserving their UIDs and historical aliases in prose.
5. Create an exact non-emitting vtable-data child for `[0x0061404c,0x006140ec)`; update UID0001X4 to link it.
6. Retain the structured semantic IDA handoff as accepted action/protection history. The supervisor completed Gate 2B under the dated Section 21 receipt; B004 remained read-only.
7. Retain the exact manual coverage rows as implemented evidence. The supervisor applied and validated them under commands `23703`-`23707`; B004 did not edit coverage files.

## Supervisor Active Recheck

For final reconciliation, the supervisor independently rereads the exact report hash and verifies:

- all 33 literal headings are present and substantive;
- the ten source-authored and three compiler-only bodies are individually represented;
- every alignment gap, vtable view, RTTI element, resource/import group, and related support page has a disposition;
- the formal H contains no explicit synthetic padding fields and naturally produces `sizeof(PredefinedFormArticleEntry) == 0x40c`;
- the CPP uses `OnTimer`, `void OnPaint`, a retained payload helper, and `TimerHandler::ScheduleTimer(0,15000,0,0)`;
- IDA rows retain literal dated 2026-08-14 snapshot names, prototypes or absence, comment states, proposed semantic action, negative constraints, and expected readback; the separate dated Gate 2B receipt supplies the applied/no-change result and saved-IDB identity;
- the ledger and checklist have exact eight-field parity;
- no executable operational scripting is present.

## Inference Research Guidance Check

This audit treats binary facts as behavioral authority while inferring human source names and organization where original symbols were lost. It does not preserve `sub_` labels, decompiler temporaries, complete-object pointer corrections, explicit vtable writes, explicit padding fields, deleting-destructor flags, or range-check helper calls in final source. The inferred names follow the existing dialog subsystem: `OnCommand`, `OnTimer`, `OnPaint`, `SetHoverControl`, `SubmitArticle`, `HandleTransferReplyPredefinedAlert`, and `PredefinedFormArticleEntry`.

The source shape is intentionally Visual C++ 6/7-era C++: ordinary header/source split, direct inheritance, fixed arrays, private helpers, file-local parser, explicit `new`, `NULL`/zero-compatible behavior, and no modern lambdas, range-for, `auto`, smart pointers, or decompiler artifacts. Exact runtime behavior has priority over stylistic consistency; consistent subsystem naming is applied only after behavior and plausible human source shape.

Stale Wave2/Wave3 mentions encountered in current pages were rejected as evidence. Their historical presence should remain documented only as superseded provenance where useful.

## Heuristic / Inference Reanalysis And Validation

- `0x004782b0`: tertiary vtable slot `0x006140e8`, complete-object offset `+0xa4`, and the existing `TimerHandler::OnTimer(int,int,int)` contract jointly outweigh the old generic event label. The null comparison is `timerId == 0`; the decompiler's `void *Block` is type pollution.
- `0x00478380`: the dated 2026-08-14 IDA snapshot prototype is `void __thiscall(int this)`, and the inherited `DialogPane` contract is `virtual void OnPaint()`. Returning the final draw helper is a decompiler-shaped mistake.
- `0x00478aa0`: exact size, callee sequence, alert construction, payload offsets, and same-size structural twin `NewArticleDialog::HandleTransferReplyPayload` prove a retained source method. Zero inbound xrefs prove dead/unrouted retention, not compiler generation.
- `0x004777a0`: allocation size `0x5368`, direct caller arguments, parser calls, row stride, exact control constructors, geometry, resource branch, and class RTTI resolve the constructor enough for formal source. The old no-code conclusion relied on unresolved labels that are now independently identified.
- Direct base: RTTI says `BulletinDialog`; the direct compiled `DialogInSession` call is optimization/lowering evidence, not a source inheritance contradiction.
- Parser row type: natural MSVC alignment supplies one byte before each `wchar_t` array and two bytes before the final `int`. Explicit `reserved...` fields are unnecessary reverse-engineering scaffolding and should be removed from human source.
- Aggregate and by-item alias: both only duplicate exact source children and should not emit. Their evidence remains useful, but the final source graph must have one definition per source item.

## Evidence Standards Used

- Direct evidence: dated 2026-08-14 non-authoritative MCP snapshot function bounds/prototypes/decompilation, raw bytes, xrefs, vtable entries, RTTI names/hierarchy, caller/callee sets, type-query negatives, and comment states.
- Corroborating evidence: current by-* pages, inherited class contracts, matching sibling `NewArticleDialog` bodies, current validator-generated CPP/H from command `23592`, and matching archived reports.
- Inference: original lexical names, private/public visibility, exact original file spelling, and source-level helper spelling where no symbols survive.
- Negative evidence: no local `NewPredefined*` IDA type, no inbound route for retained raw/payload helpers, no extra code in alignment gaps, and no legitimate need to hand-author ABI glue. The missing generated sibling H was a pre-callback defect and is not current after command `23592`.
- Confidence remains below `95/95` because exact original lexical spelling and some control-field visibility are inferred even though behavior/layout/source ownership are strongly resolved.

## Evidence Checked

- Dated MCP evidence locator: session `supervisor-uid0000IW-recovery-20260814`, captured 2026-08-14; this identifier is historical and non-authoritative, not a claim of present activity or canonical status.
- Modeled functions: `0x4777a0`, `0x478240`, `0x4782b0`, `0x478370`, `0x478380`, `0x478650`, `0x478940`, `0x478aa0`, `0x478be0`, `0x47e931`, `0x47e93c`, and `0x47ec30`.
- Raw code: exact disassembly/bytes for `0x4781f0-0x478238`.
- Data: exact bytes and xrefs for `0x61404c-0x6140ec`; RTTI at `0x674e00`, `0x6439a4`, `0x6439b8`, `0x6439c8`, `0x6439f0`, `0x643a0c`, and `0x643a20`.
- Negative type queries: `NewPredefined*` and `PredefinedForm*` returned zero local named types.
- Dated comment snapshot: regular, repeatable, function regular, and function repeatable comments were empty at every proposed function/data action start on 2026-08-14; the dated Gate 2B receipt records the later fresh supervisor prestate and post-save readback.
- Related docs: UID0000LT, UID000098, UID0000ZL, UID0000UE, UID0002UJ/EK/UK/UM/UN/UO/UP/UQ/UR/UL, UID0000ZQ, UID0000ZS, UID0001X4, the broad board/mail read-only-data page, inherited `BulletinDialog`, `DialogPane`, and `TimerHandler` contracts.
- Generated readback: command `23592` refreshed `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp` and `.h`; the CPP contains the exact class preamble and all ten formal bodies, and the H contains the exact complete Section 22 declaration.
- Matching archived reports searched by UID, address, class name, parser name, and retained helper. Opened relevant B001, B002, B005, B006, B011, B012, and B014 reports.
- No research check failed. The initial report-only phase ran no validator; the accepted implementation callback subsequently ran the exact scoped validators recorded in Section 31.

## Claim And Incorporation Ledger

Every row is independently actionable. Section 33 repeats these eight fields byte-for-byte and adds only `Done`.

All IDA/MCP names, prototypes, comments, types, frames, xrefs, and item states referenced by this ledger and its mirrored checklist began as dated 2026-08-14 non-authoritative evidence snapshots. They do not independently establish later mutable state. The dated supervisor Gate 2B receipt in Section 21 now closes C31-C74 as `APPLIED_VERIFIED` or `NO_CHANGE_VERIFIED`; ordinary claims C01-C30 and C76-C81 remain applied and scoped-validated; supervisor-owned C75 coverage is applied and validated under commands `23703`-`23707`.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0000LT | UID0000LT is the unique NewPredefinedFormArticleDialog CPP/H compilation-unit root under NexusTK/ui/dialogs. | High | File route, contiguous cluster, class emitter, generated path, and subsystem placement | UID0000LT status, inventory, placement, and source contract | incorporate | applied |
| C02 | 0000LT | The whole file contains exactly ten source-authored code bodies in the main cluster. | High | Nine modeled functions plus exact raw navigation body and complete gap scan | UID0000LT exhaustive function inventory | incorporate | applied |
| C03 | 0000LT | The two adjustor thunks and scalar deleting destructor are compiler ABI products with no handwritten CPP bodies. | High | Vtable-only refs, this adjustments, deleting flags, and base cleanup | UID0000LT compiler inventory and UID0000ZQ/0000ZS | incorporate | applied |
| C04 | 0000LT | Ten exact internal CC alignment gaps account for every byte between the source bodies. | High | Dated 2026-08-14 byte snapshots for all ten half-open gaps | UID0000LT range and padding ledger | incorporate | applied |
| C05 | 0002UJ | The constructor is source-ready with BulletinDialog base, four arguments, two layout branches, controls, parser, and exact 0x5368 layout. | High | Full decompile, caller, allocation, helper prototypes, RTTI, and field offsets | UID0002UJ formal CPP and evidence | incorporate | applied |
| C06 | 0002EK | The raw navigation body is a private retained source helper and should emit NavigateToPreviousArticleSelection. | High | Exact code, previous-dialog/list control flow, shared navigation helper, and padding | UID0002EK formal CPP and metadata | incorporate | applied |
| C07 | 0002UK | The command override submits command 0 with unsigned board id and cancels command 1. | High | Primary vtable slot, submit call, session field, dimmer, and pop route | UID0002UK formal CPP and evidence | incorporate | applied |
| C08 | 0002UM | Address 0x4782b0 is TimerHandler OnTimer, not HandleEvent. | High | Tertiary vtable slot, +0xa4 facet, TimerHandler contract, and ScheduleTimer pair | UID0002UM rename, formal CPP, and historical correction | incorporate | applied |
| C09 | 0002UN | The nine-byte hover body is the normal SetHoverControl override forwarding to DialogPane. | High | Primary vtable slot and sole inherited tail-call | UID0002UN formal CPP and evidence | incorporate | applied |
| C10 | 0002UO | OnPaint returns void and draws exact EPF or legacy header, row, and footer sequences. | High | Dated 2026-08-14 void-prototype snapshot, inherited contract, resources, loops, and geometry | UID0002UO formal CPP and historical correction | incorporate | applied |
| C11 | 0002UP | The file-local parser is __stdcall, uses a naturally padded 0x40c row type, and precedes constructor use through a forward declaration. | High | retn convention, two ctor callers, field writes, and natural MSVC layout | UID0002UP formal CPP and UID000098 H/CPP preamble | incorporate | applied |
| C12 | 0002UQ | The live virtual packet handler accepts subcommand 0x06 and constructs TransferReplyPredefinedAlert from packet+2. | High | Primary vtable slot, packet bytes, conversion, dimmer, and alert stores | UID0002UQ formal CPP and evidence | incorporate | applied |
| C13 | 0002UR | The no-xref 0x478aa0 body is a retained source payload helper, not compiler glue or blank code. | High | Exact structural twin, same size/callees, payload offsets, and clean boundaries | UID0002UR rename, formal CPP, and liveness history | incorporate | applied |
| C14 | 0002UL | SubmitArticle takes unsigned short boardId and schedules TimerHandler timer 0 for 15000 ms after send. | High | Packet writer width, session field, exact TimerHandler callee, and call arguments | UID0002UL formal CPP and correction | incorporate | applied |
| C15 | 000098 | PredefinedFormArticleEntry has seven human-source fields and natural padding to size 0x40c. | High | Exact offsets 0/2/202/203/204/206/408 and MSVC alignment | UID000098 formal H and layout section | incorporate | applied |
| C16 | 000098 | NewPredefinedFormArticleDialog directly inherits BulletinDialog and owns the two counts plus twenty-entry row array. | High | Nine-base RTTI, base order, object allocation, and parser/consumer offsets | UID000098 formal H and class layout | incorporate | applied |
| C17 | 0001X4 | The exact vtable/COL band is 0x61404c-0x6140ec and needs one non-emitting by-memory child. | High | Exact bytes, three COLs, 24/11/2 slots, constructor stores, and next boundary | UID0001X4 and new vtable-data child | incorporate | applied |
| C18 | 000098 | RTTI proves BulletinDialog direct source inheritance and EventHandler/TimerHandler secondary views at +0xa0/+0xa4. | High | Type descriptor, hierarchy, base array, PMDs, and COL offsets | UID000098 inheritance and vtable analysis | incorporate | applied |
| C19 | 0000LT | DLGBBS08.EPF/PAL and DLGBBS08.EPD/NPAL8.PAL are the exact current/legacy resource pairs. | High | Constructor/paint string and call evidence | UID0000LT resource inventory and UID0002UO | incorporate | applied |
| C20 | 0000LT | MultiByteToWideChar, WideCharToMultiByte, packet helpers, screen dimmer, EPF library, user pane, and packet sender are required dependencies. | High | Direct imports, callees, and global xrefs | UID0000LT dependency inventory and CPP include contract | incorporate | applied |
| C21 | 0002UJ | Caller 0x471c00 supplies prior subject, EPF/legacy bounds, form packet, and allocates exactly 0x5368 bytes. | High | Sole constructor caller and argument/data flow | UID0002UJ caller and construction contract | incorporate | applied |
| C22 | 0000LT | The pre-callback generated CPP/H was incomplete; command 23592 now emits the exact class preamble, ten source bodies, and complete H with no empty marker, placeholder, or ordering defect. | High | Pre-callback defect audit plus command 23592 physical CPP/H readback and exact formal-block comparison | UID0000LT generated-output audit | incorporate | applied |
| C23 | 000098 | The class should be 94/94, reconstructable, owned/emitted by UID0000LT, with formal CPP/H populated. | High | Complete inventory, header, source bodies, and emitter route | UID000098 metadata and formal blocks | incorporate | applied |
| C24 | 0000LT | The file should be 94/94 while retaining owner FILE and NexusTK/ui/dialogs path. | High | Whole-file completion with lexical uncertainty below 95 | UID0000LT metadata and score rationale | incorporate | applied |
| C25 | 0000ZL | The physical aggregate should become non-reconstructable and non-emitting because exact children own all source. | High | Complete child coverage and duplicate empty-marker proof | UID0000ZL metadata and no-code disposition | incorporate | applied |
| C26 | 0000UE | The parser by-item alias should become non-reconstructable and non-emitting, covered by UID0002UP. | High | Same address/body and duplicate generated marker | UID0000UE metadata and covered-by disposition | incorporate | applied |
| C27 | 0002UJ | Constructor score should rise to 93/94 with class owner/emitter retained and formal CPP populated. | High | Resolved prior blockers and exact source reconstruction | UID0002UJ metadata and score rationale | incorporate | applied |
| C28 | 0000LT | All source-bearing children should receive the exact per-page scores and formal CPP dispositions listed in Section 26. | High | Per-function evidence and under-95 source-quality cap | Affected by-memory metadata and formal blocks | incorporate | applied |
| C29 | 0000ZQ | UID0000ZQ and UID0000ZS should preserve their current ignored/non-emitting compiler dispositions. | High | ABI-only behavior and regeneration from class declaration | UID0000ZQ/0000ZS no-code history | incorporate | applied |
| C30 | 0001X4 | BoardArticleDialogVtableFamily should link the exact new child and correct 0x4782b0 to OnTimer. | High | Dated 2026-08-14 exact slot-map snapshot and stale family prose | UID0001X4 NewPredefined row and notes | incorporate | applied |
| C31 | 0002EK | I01 preserves the exact raw navigation range as unmodeled code with no function object, function name absent, prototype absent, frame absent, AR absent, AP absent, FR not applicable, and FP not applicable. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact 72-byte body, boundary, fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP readback, zero-xref set, and unchanged padding | Gate 2B I01 | incorporate | NO_CHANGE_VERIFIED |
| C32 | 0002UJ | I02 recommends only the exact constructor function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I02 | incorporate | APPLIED_VERIFIED |
| C33 | 0002EK | I03 preserves the navigation range with no function object, function name absent, prototype absent, frame absent, AR absent, AP absent unless independently accepted I23 changes only AP, FR not applicable, and FP not applicable. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact raw range plus fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP readback with the accepted zero-xref set | Gate 2B I03 | incorporate | NO_CHANGE_VERIFIED |
| C34 | 0002UK | I04 recommends only the exact OnCommand function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I04 | incorporate | APPLIED_VERIFIED |
| C35 | 0002UM | I05 recommends only the exact OnTimer function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I05 | incorporate | APPLIED_VERIFIED |
| C36 | 0002UN | I06 recommends only the exact SetHoverControl function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I06 | incorporate | APPLIED_VERIFIED |
| C37 | 0002UO | I07 recommends only the exact OnPaint function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I07 | incorporate | APPLIED_VERIFIED |
| C38 | 0002UP | I08 recommends only the exact parser function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I08 | incorporate | APPLIED_VERIFIED |
| C39 | 0002UQ | I09 recommends only the exact full-packet-handler function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I09 | incorporate | APPLIED_VERIFIED |
| C40 | 0002UR | I10 recommends only the exact retained-payload function-name change while preserving zero-xref evidence. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot, absent destination, and liveness evidence | Gate 2B I10 | incorporate | APPLIED_VERIFIED |
| C41 | 0002UL | I11 recommends only the exact SubmitArticle function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I11 | incorporate | APPLIED_VERIFIED |
| C42 | 0002UJ | I12 protects the constructor prototype/frame and records a self-contained source candidate without authorizing an IDA type change. Classification: `no change recommended`; mutation endpoint `none`. | High | Dated 2026-08-14 signature snapshot, F01, absent local UDTs, and no deterministic frame proof | Gate 2B I12 | incorporate | NO_CHANGE_VERIFIED |
| C43 | 0002EK | I13 protects no function object, function name absent, prototype absent, frame absent, AR absent, AP absent, FR not applicable, and FP not applicable while recording a source candidate without authorizing function creation, type/frame mutation, or comments; I23 remains the separate independent AP-only action. Classification: `no change recommended`; mutation endpoint `none`. | High | Fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP readback plus absent class UDT | Gate 2B I13 | incorporate | NO_CHANGE_VERIFIED |
| C44 | 0002UK | I14 protects the snapshot OnCommand prototype/F03; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F03 | Gate 2B I14 | incorporate | NO_CHANGE_VERIFIED |
| C45 | 0002UM | I15 protects OnTimer prototype/F04; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F04 | Gate 2B I15 | incorporate | NO_CHANGE_VERIFIED |
| C46 | 0002UN | I16 protects SetHoverControl prototype/F05; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F05 | Gate 2B I16 | incorporate | NO_CHANGE_VERIFIED |
| C47 | 0002UO | I17 protects OnPaint prototype/F06; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F06 | Gate 2B I17 | incorporate | NO_CHANGE_VERIFIED |
| C48 | 0002UP | I18 protects parser prototype/F07 and the four-argument stdcall frame. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot, complete F07, and absent row UDT | Gate 2B I18 | incorporate | NO_CHANGE_VERIFIED |
| C49 | 0002UQ | I19 protects full-packet handler prototype/F08, including snapshot `arg_4`. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F08 | Gate 2B I19 | incorporate | NO_CHANGE_VERIFIED |
| C50 | 0002UR | I20 protects retained-payload prototype/F09, including snapshot `arg_4`. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F09 | Gate 2B I20 | incorporate | NO_CHANGE_VERIFIED |
| C51 | 0002UL | I21 protects SubmitArticle prototype/F10 and the 2-byte argument row. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F10 | Gate 2B I21 | incorporate | NO_CHANGE_VERIFIED |
| C52 | 0002UJ | I22 recommends only the exact constructor address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact role text | Gate 2B I22 | incorporate | APPLIED_VERIFIED |
| C53 | 0002EK | I23 recommends the exact navigation-helper AP independently of function creation while preserving no function object, function name absent, prototype absent, frame absent, AR absent, FR not applicable, and FP not applicable. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; AP is the only changed channel. | High | Fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP prestate, accepted zero-xref set, and exact retained-helper role | Gate 2B I23 | incorporate | APPLIED_VERIFIED |
| C54 | 0002UK | I24 recommends only the exact OnCommand address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact command role | Gate 2B I24 | incorporate | APPLIED_VERIFIED |
| C55 | 0002UM | I25 recommends only the exact OnTimer address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact timer role | Gate 2B I25 | incorporate | APPLIED_VERIFIED |
| C56 | 0002UN | I26 recommends only the exact SetHoverControl address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact forwarding role | Gate 2B I26 | incorporate | APPLIED_VERIFIED |
| C57 | 0002UO | I27 recommends only the exact OnPaint address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact paint role | Gate 2B I27 | incorporate | APPLIED_VERIFIED |
| C58 | 0002UP | I28 recommends only the exact parser address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact parser role | Gate 2B I28 | incorporate | APPLIED_VERIFIED |
| C59 | 0002UQ | I29 recommends only the exact full-packet address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact packet role | Gate 2B I29 | incorporate | APPLIED_VERIFIED |
| C60 | 0002UR | I30 recommends only the exact retained-payload address-repeatable comment and preserves the zero-xref caveat. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact retained role | Gate 2B I30 | incorporate | APPLIED_VERIFIED |
| C61 | 0002UL | I31 recommends only the exact SubmitArticle address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact packet/timer role | Gate 2B I31 | incorporate | APPLIED_VERIFIED |
| C62 | 0000ZQ | I32 independently protects the EventHandler-view adjustor identity/type/frame with AR absent, AP absent, FR absent, and FP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 name/range/prototype/F11, literal AR/AP/FR/FP, and accepted xref-set snapshot | Gate 2B I32 | incorporate | NO_CHANGE_VERIFIED |
| C63 | 0000ZQ | I33 independently protects the TimerHandler-view adjustor identity/type/frame with AR absent, AP absent, FR absent, and FP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 name/range/prototype/F12, literal AR/AP/FR/FP, and accepted xref-set snapshot | Gate 2B I33 | incorporate | NO_CHANGE_VERIFIED |
| C64 | 0000ZS | I34 independently protects the scalar deleting destructor identity/type/frame with AR absent, AP absent, FR absent, and FP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 name/range/prototype/F13, literal AR/AP/FR/FP, and accepted three-xref-set snapshot | Gate 2B I34 | incorporate | NO_CHANGE_VERIFIED |
| C65 | 0000ZQ | I35 resolves the first adjustor comment as exact no-change. Classification: `no change recommended`; mutation endpoint `none`. | High | All comment channels absent and compiler-only role documented elsewhere | Gate 2B I35 | incorporate | NO_CHANGE_VERIFIED |
| C66 | 0000ZQ | I36 resolves the second adjustor comment as exact no-change. Classification: `no change recommended`; mutation endpoint `none`. | High | All comment channels absent and compiler-only role documented elsewhere | Gate 2B I36 | incorporate | NO_CHANGE_VERIFIED |
| C67 | 0000ZS | I37 resolves the deleting-destructor comment as exact no-change. Classification: `no change recommended`; mutation endpoint `none`. | High | All comment channels absent and compiler-only role documented elsewhere | Gate 2B I37 | incorporate | NO_CHANGE_VERIFIED |
| C68 | 0001X4 | I38 independently protects the primary vtable item/name/type. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact item head/end/width/name/type | Gate 2B I38 | incorporate | NO_CHANGE_VERIFIED |
| C69 | 0001X4 | I39 independently protects the EventHandler-view vtable item/name/type. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact item head/end/width/name/type | Gate 2B I39 | incorporate | NO_CHANGE_VERIFIED |
| C70 | 0001X4 | I40 independently protects the TimerHandler-view vtable item/name/type. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact item head/end/width/name/type | Gate 2B I40 | incorporate | NO_CHANGE_VERIFIED |
| C71 | 0001X4 | I41 resolves the primary-vtable comment as exact no-change with AR absent and AP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Literal AR absent; literal AP absent | Gate 2B I41 | incorporate | NO_CHANGE_VERIFIED |
| C72 | 0001X4 | I42 resolves the EventHandler-vtable comment as exact no-change with AR absent and AP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Literal AR absent; literal AP absent | Gate 2B I42 | incorporate | NO_CHANGE_VERIFIED |
| C73 | 0001X4 | I43 resolves the TimerHandler-vtable comment as exact no-change with AR absent and AP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Literal AR absent; literal AP absent | Gate 2B I43 | incorporate | NO_CHANGE_VERIFIED |
| C74 | 000098 | I44 preserves `PredefinedFormArticleEntry` absent and `NewPredefinedFormArticleDialog` absent as independent local-type states and prohibits dependent IDA type changes. Classification: `no change recommended`; mutation endpoint `none`. | High | Dated 2026-08-14 exact-name and wildcard searches returned zero matches for each named type, with exact Section 22 source layout | Gate 2B I44 | incorporate | NO_CHANGE_VERIFIED |
| C75 | 0000LT | The supervisor applied the exact Section 28 file, class, memory, item, and vtable coverage replacements and validated all five coverage files under commands 23703-23707. | High | Exact replacement text plus supervisor coverage validation receipts | Supervisor-owned manual coverage files | incorporate | applied |
| C76 | 0000LT | Matching archived method reports remain useful evidence but their constructor no-code, HandleEvent, int OnPaint, and blank retained-helper conclusions are superseded. | High | Independent dated 2026-08-14 MCP snapshot recheck and report comparison | UID0000LT historical assumptions and support docs | incorporate | applied |
| C77 | 0000LT | Wave2/Wave3 material is stale and supplies no current claim evidence. | High | Current skill rule and independent current evidence | UID0000LT evidence provenance | incorporate | applied |
| C78 | 0000LT | Every discovered source blocker has a current resolution; IDA type mutation is separately narrowed to proven safe no-change. | High | Exhaustive inventory, types, xrefs, callers, source comparison, and frame audit | UID0000LT open-questions resolution | incorporate | applied |
| C79 | 000098 | A real sibling H is required because the class layout and parser row type are shared by multiple CPP bodies. | High | Constructor/parser/submit field use, pre-callback H absence, and command 23592 exact generated-H readback | UID000098 formal H and UID0000LT generated contract | incorporate | applied |
| C80 | 0000LT | Parser declaration must precede constructor use while definitions retain address/source child order through the emitter graph. | High | Parser caller order and current child assembly order | UID000098 CPP preamble and emitter-order notes | incorporate | applied |
| C81 | 0000LT | No third-party import directive applies to this first-party dialog compilation unit. | High | All bodies, resources, imports, and ownership are NexusTK-local | UID0000LT source contract | incorporate | applied |

## Positive Evidence Summary

- The code neighborhood is closed: every byte in the main range is a named source body or exact `0xcc` alignment.
- Vtable slots identify every virtual body and separate source methods from destructor adjustors.
- RTTI, allocation size, parser stride, and field offsets jointly recover the class and row layouts.
- The sole constructor caller explains every argument and the EPF/legacy outer bounds.
- The retained payload helper has a same-size, same-shape, same-callee sibling in `NewArticleDialog`.
- Current generated output demonstrates the emitter route and makes every remaining absence or wrong signature directly observable.
- Existing support pages already establish most packet/resource/control behavior; the dated 2026-08-14 MCP snapshot resolves the stale identities that prevented a complete source module.

## IDA MCP Facts

Every fact in this section is a dated 2026-08-14 non-authoritative evidence snapshot. It supports the source analysis but does not assert present IDA/session state; the supervisor rereads mutable state independently at Gate 2B.

- Exact main modeled sizes: constructor `0xa45`; command `0x62`; timer `0xb3`; hover `0x09`; paint `0x2cc`; parser `0x2e3`; full-packet reply `0x153`; retained payload `0x139`; submit `0x3ae`.
- Raw navigation body: `0x48` bytes, bounded by `0x0b` and `0x08` bytes of `0xcc`.
- Compiler bodies: two `0x0b` adjustors and one `0x3b` scalar deleting destructor.
- Dated snapshot prototypes are preserved literally in Section 21. Notable pollution includes `void *Block` on the timer callback, `Pane *` on both alert handlers, and `boost::exception *` on ABI wrappers.
- Primary slots include `0x614094 -> 0x478380`, `0x614098 -> 0x478240`, `0x6140a8 -> 0x478370`, and `0x6140ac -> 0x478940`.
- Tertiary slot `0x6140e8 -> 0x4782b0` proves the timer override.
- Parser xrefs are exactly constructor callsites `0x477848` and `0x477d0c`; submit's sole caller is `0x47827e`; constructor's sole caller is `0x471d4a`.
- Retained payload helper and raw navigation helper have no inbound xrefs or raw VA/RVA pointer hits; their complete source-shaped bodies and sibling analogs still support retained source emission.
- Vtable band is exactly 160 bytes; next class COL begins at `0x6140ec`.
- All proposed action comments read as absent/empty in the dated snapshot.

Complete vtable slot inventory:

| View / slot | Slot address | Target | Dated 2026-08-14 snapshot IDA name | Source disposition |
| --- | --- | --- | --- | --- |
| primary COL | `0x61404c` | `0x6439a4` | RTTI complete-object locator | Compiler-generated from the class hierarchy. |
| primary 0 | `0x614050` | `0x47ec30` | `sub_47EC30` | Scalar deleting destructor; compiler-only. |
| primary 1 | `0x614054` | `0x4f4b10` | `LObject__GetRuntimeClass` | Inherited. |
| primary 2 | `0x614058` | `0x41b6c0` | `LObject__OnChangeMessage` | Inherited. |
| primary 3 | `0x61405c` | `0x4b8e20` | `sub_4B8E20` | Inherited GrafPort/Pane behavior; not file-owned. |
| primary 4 | `0x614060` | `0x41d680` | `Pane_DrawOnTarget` | Inherited. |
| primary 5 | `0x614064` | `0x544730` | `sub_544730` | Inherited Pane behavior. |
| primary 6 | `0x614068` | `0x544750` | `sub_544750` | Inherited Pane behavior. |
| primary 7 | `0x61406c` | `0x5447a0` | `Pane_GetParentPane` | Inherited. |
| primary 8 | `0x614070` | `0x544800` | `Pane_InvalidateRect` | Inherited. |
| primary 9 | `0x614074` | `0x544a20` | `Pane_GetDescription` | Inherited. |
| primary 10 | `0x614078` | `0x544b80` | `sub_544B80` | Inherited Pane behavior. |
| primary 11 | `0x61407c` | `0x544bd0` | `sub_544BD0` | Inherited bounds/origin behavior. |
| primary 12 | `0x614080` | `0x49dfd0` | `DialogPane__OnCreate` | Inherited. |
| primary 13 | `0x614084` | `0x544cb0` | `sub_544CB0` | Inherited Pane behavior. |
| primary 14 | `0x614088` | `0x49e1c0` | `DialogPane_OnDestroy` | Inherited. |
| primary 15 | `0x61408c` | `0x49e190` | `DialogPane__OnShow` | Inherited. |
| primary 16 | `0x614090` | `0x49e210` | `DialogPane_OnHide` | Inherited. |
| primary 17 | `0x614094` | `0x478380` | `sub_478380` | File-owned `OnPaint`. |
| primary 18 | `0x614098` | `0x478240` | `sub_478240` | File-owned `OnCommand`. |
| primary 19 | `0x61409c` | `0x41b6a0` | `@_guard_check_icall_nop@4` | Inherited/default compiler guard slot; no authored body here. |
| primary 20 | `0x6140a0` | `0x49f1d0` | `DialogPane_DrawBackground` | Inherited. |
| primary 21 | `0x6140a4` | `0x49f2e0` | `DialogPane_DrawBorder` | Inherited. |
| primary 22 | `0x6140a8` | `0x478370` | `sub_478370` | File-owned `SetHoverControl`. |
| primary 23 | `0x6140ac` | `0x478940` | `sub_478940` | File-owned full-packet reply override. |
| EventHandler COL | `0x6140b0` | `0x643a0c` | RTTI locator for PMD `+0xa0` | Compiler-generated. |
| EventHandler 0 | `0x6140b4` | `0x47e931` | `sub_47E931` | Compiler destructor adjustor. |
| EventHandler 1 | `0x6140b8` | `0x49e240` | `sub_49E240` | Inherited DialogPane event behavior. |
| EventHandler 2 | `0x6140bc` | `0x49e6e0` | `DialogPane_HandleKeyOrTextEvent` | Inherited. |
| EventHandler 3 | `0x6140c0` | `0x49ea60` | `DialogPane_HandleImeEvent` | Inherited. |
| EventHandler 4 | `0x6140c4` | `0x472040` | `sub_472040` | Shared board-dialog command-one bridge; not file-owned. |
| EventHandler 5 | `0x6140c8` | `0x544df0` | `sub_544DF0` | Inherited EventHandler behavior. |
| EventHandler 6 | `0x6140cc` | `0x544e00` | `sub_544E00` | Inherited EventHandler behavior. |
| EventHandler 7 | `0x6140d0` | `0x4a89f0` | `sub_4A89F0` | Inherited/shared event behavior. |
| EventHandler 8 | `0x6140d4` | `0x544e10` | `sub_544E10` | Inherited EventHandler behavior. |
| EventHandler 9 | `0x6140d8` | `0x544e30` | `sub_544E30` | Inherited EventHandler behavior. |
| EventHandler 10 | `0x6140dc` | `0x544e70` | `sub_544E70` | Inherited EventHandler behavior. |
| TimerHandler COL | `0x6140e0` | `0x643a20` | RTTI locator for PMD `+0xa4` | Compiler-generated. |
| TimerHandler 0 | `0x6140e4` | `0x47e93c` | `sub_47E93C` | Compiler destructor adjustor. |
| TimerHandler 1 | `0x6140e8` | `0x4782b0` | `sub_4782B0` | File-owned `OnTimer`. |

The nine RTTI base entries are, in order, `NewPredefinedFormArticleDialog`, `BulletinDialog`, `DialogInSession`, `DialogPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler` at PMD `+0xa0`, and `TimerHandler` at PMD `+0xa4`. No slot in the three views points to the raw navigation or retained payload helper, consistent with their private retained disposition.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x4777a0-0x4781e5` | UID0002UJ constructor | Complete dynamic form-dialog constructor | TRUE | UID000098 | `88/91 -> 93/94` | Formal CPP required; prior no-code decision superseded. |
| `0x4781e5-0x4781f0` | exact gap | 11-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding; no code/data. |
| `0x4781f0-0x478238` | UID0002EK | Retained previous-selection navigation helper | TRUE | UID000098 | `88/91 -> 92/93` | Formal CPP preserved/refined. |
| `0x478238-0x478240` | exact gap | 8-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x478240-0x4782a2` | UID0002UK | `OnCommand` | TRUE | UID000098 | `90/91 -> 93/93` | Formal CPP corrected to unsigned board id. |
| `0x4782a2-0x4782b0` | exact gap | 14-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x4782b0-0x478363` | UID0002UM | `OnTimer` failure callback | TRUE | UID000098 | `90/92 -> 94/94` | Rename page/title and replace wrong HandleEvent CPP. |
| `0x478363-0x478370` | exact gap | 13-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x478370-0x478379` | UID0002UN | `SetHoverControl` forwarder | TRUE | UID000098 | `90/92 -> 93/94` | Formal CPP already behaviorally correct. |
| `0x478379-0x478380` | exact gap | 7-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x478380-0x47864c` | UID0002UO | `void OnPaint` | TRUE | UID000098 | `90/92 -> 93/94` | Replace wrong return type/returns. |
| `0x47864c-0x478650` | exact gap | 4-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x478650-0x478933` | UID0002UP | File-local `__stdcall` row parser | TRUE | UID0000LT | `90/92 -> 93/94` | Formal CPP plus H-owned row declaration. |
| `0x478933-0x478940` | exact gap | 13-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x478940-0x478a93` | UID0002UQ | Virtual full-packet transfer-reply handler | TRUE | UID000098 | `90/91 -> 92/93` | Formal CPP retained/refined. |
| `0x478a93-0x478aa0` | exact gap | 13-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x478aa0-0x478bd9` | UID0002UR | Retained payload-layout transfer-reply helper | TRUE | UID000098 | `87/92 -> 92/93` | Rename and add formal CPP. |
| `0x478bd9-0x478be0` | exact gap | 7-byte alignment | FALSE | UID0000ZL | n/a | Compiler padding. |
| `0x478be0-0x478f8e` | UID0002UL | Article packet serializer/submission helper | TRUE | UID000098 | `90/91 -> 93/94` | Correct board type and timer call. |
| `0x478f8e-0x478f90` | exact gap | 2-byte alignment | FALSE | UID0000ZL | n/a | Exact end padding before next class family. |
| `0x47e931-0x47e93c` | UID0000ZQ child 1 | EventHandler destructor adjustor `this -= 0xa0` | FALSE | NONE | `85/93` | Compiler-generated; no source body. |
| `0x47e93c-0x47e947` | UID0000ZQ child 2 | TimerHandler destructor adjustor `this -= 0xa4` | FALSE | NONE | `85/93` | Compiler-generated; no source body. |
| `0x47ec30-0x47ec6b` | UID0000ZS | Scalar deleting destructor | FALSE | NONE | `85/92` | Compiler-generated from implicit destructor/hierarchy. |
| `0x61404c-0x6140ec` | UID00050Q exact child | Three COL/vtable views, 24/11/2 slots | FALSE | UID000098 | `94/95` | Non-emitting data child; class H regenerates it. |
| `0x674e00` | RTTI type descriptor | `NewPredefinedFormArticleDialog` type identity | FALSE | UID000098 | support | Compiler-generated; no raw source. |
| `0x6439a4-0x643a34` | RTTI locator/hierarchy/base descriptors | Nine-base hierarchy and 0/+a0/+a4 views | FALSE | UID000098 | support | Compiler-generated from class declaration. |
| `PredefinedFormArticleEntry` | no separate by-type page | Seven-field row layout, size `0x40c` | TRUE | UID000098 | `94/95` source evidence | Declared in the class H; no separate by-struct split was required. |
| `NewPredefinedFormArticleDialog` layout | UID000098 | `BulletinDialog` base + counts + 20 rows, size `0x5368` | TRUE | UID0000LT | `86/87 -> 94/94` | Complete H required. |
| resources | UID0000LT/UID0002UO | `DLGBBS08.EPF`, `DLGBBS08.PAL`, `DLGBBS08.EPD`, `NPAL8.PAL` | support | UID0000LT | support | Exact resource names/branch usage retained. |
| imports | UID0000LT | `MultiByteToWideChar`, `WideCharToMultiByte` | support | UID0000LT | support | Required Win32 conversion imports. |
| globals | UID0000LT | `g_useEpfAssets`, `g_pUserPane`, `g_pEPFLib`, `g_pScreenDimmer`, `g_packetSender`, `g_emptyWideString` | support | existing owners | support | Referenced, not re-owned by this file. |
| runtime/helper dependencies | UID0000LT | control constructors, packet readers/writers, memmove/wide copy, timer, session, drawing | support | existing owners | support | Include/call only; no duplicate ownership. |
| UID0000ZL | aggregate page | Physical address-ordered index | FALSE | UID0000LT context | `85/90 -> 94/94` | Blank emitter; exact children own source. |
| UID0000UE | parser by-item alias | Search/index alias for UID0002UP | FALSE | UID0000LT context | `90/92 -> 92/94` | Blank emitter; covered by UID0002UP. |

Inventory totals: 10 source-authored bodies, 3 compiler code bodies, 10 internal alignment gaps, 1 exact vtable/COL band, 1 RTTI family, 2 source types/layouts, 4 named resources, 2 direct Win32 imports, 6 named globals, and the enumerated helper dependency families. No reasonably discoverable file-owned function, code range, table, type, resource, import, or generated fragment remains without a source/no-code disposition.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x4777a0` | sole caller `0x471d4a` in `0x471c00` | Validates form data, chooses resource bounds, allocates `0x5368`, constructs, and pushes dialog. |
| `0x4781f0` | zero inbound xrefs/pointer hits; calls prior-dialog/list/navigation helpers | Retained private method, not virtual. |
| `0x478240` | data xref `0x614098`; calls `0x478be0` at `0x47827e` | Primary `OnCommand` override. |
| `0x4782b0` | data xref `0x6140e8`; dimmer/alert callees | Tertiary `TimerHandler::OnTimer` override. |
| `0x478370` | data xref `0x6140a8`; tail-calls `DialogPane::SetHoverControl` | Primary hover override. |
| `0x478380` | data xref `0x614094`; EPF load/draw/global callbacks | Primary `void OnPaint`. |
| `0x478650` | calls at `0x477848` and `0x477d0c`; Win32 conversion/wide copy | File-local parser used by both resource-layout constructor branches. |
| `0x478940` | data xref `0x6140ac`; dimmer/conversion/alert callees | Live full-packet virtual reply handler. |
| `0x478aa0` | zero inbound xrefs/pointer hits; same alert/conversion callees | Retained payload-layout source method. |
| `0x478be0` | sole caller `0x47827e`; packet, conversion, sender, timer callees | Private submit helper. |
| `0x47e931` | vtable data xref `0x6140b4`; jump `0x47ec30` | Compiler EventHandler-view destructor adjustor. |
| `0x47e93c` | vtable data xref `0x6140e4`; jump `0x47ec30` | Compiler TimerHandler-view destructor adjustor. |
| `0x47ec30` | primary vtable `0x614050` and both adjustors | Compiler scalar deleting destructor. |
| `0x614050/0x6140b4/0x6140e4` | ctor stores `0x4777ee/0x4777f4/0x4777fe` | Three object views installed by constructor lowering. |
| `0x674e00` and RTTI hierarchy | COL/hierarchy/base references | Proves class identity, direct base, and secondary interfaces. |
| resource strings | constructor/paint references | Exact current/legacy layout and palette selection. |
| conversion imports | parser/reply/submit callsites | ANSI/wide packet and form text conversion. |
| named globals | direct reads/writes in constructor/paint/reply/submit | Shared state dependencies only; no new file-local global ownership. |

## Documentation Evidence And IDA Status

Before the accepted callback, the documentation correctly preserved packet layout, resource names, most child boundaries, command/hover behavior, parser stride, full-packet reply behavior, submit body, and compiler-thunk disposition, but it still carried the constructor no-code decision, generic `HandleEvent`, `int OnPaint`, blank payload-helper code, and duplicate aggregate/alias emitters. Those are historical pre-callback defects. Current ordinary by-* documentation contains the accepted classifications, exact emitters, formal CPP/H, UID-preserving renames, and non-emitting aggregate/alias dispositions.

The dated 2026-08-14 IDA snapshot had no source-quality names for any main body except inherited/helper callees, no function object at `0x4781f0`, no local named `PredefinedFormArticleEntry` or `NewPredefinedFormArticleDialog` type, and no comments at the action addresses. It retained exact MSVC vtable symbols at `0x614050`, `0x6140b4`, and `0x6140e4`, plus the class RTTI type descriptor. A supplemental read-only preflight through session `supervisor-uid0000KZ-gate2b-20260814` again returned zero functions and zero names in `[0x004781f0,0x00478238)`, one-byte code items through `0x00478237`, unchanged eight-byte data padding at `[0x00478238,0x00478240)`, absent address comments, and `No function found` for the stack frame. Because read-only evidence could not prove a deterministic post-creation prototype/frame, I01/I03/I13 preserved the no-function state and I23 remained an independent address-comment action. The later dated Gate 2B receipt established that session as canonical mutation authority for the accepted rows, applied I23 only to AP, and verified every protected no-change state after save.

## Ranked Ownership Analysis

### 1. Dedicated NewPredefinedFormArticleDialog compilation unit

- Evidence for: unique file page, isolated contiguous main cluster, one class, one file-local parser, class-specific resources/packet behavior, existing generated path, direct class emitter, and a required coherent H.
- Evidence against: historical possibility of a broader `ArticleDialogs.cpp`.
- Decision: selected. The amount of class-specific constructor/parser/layout code and the existing routed file identity make a dedicated CPP/H the strongest source reconstruction.

### 2. Broad BoardDialogs or ArticleDialogs unit

- Evidence for: adjacent `NewArticleDialog`, shared alert/session helpers, and broad board vtable family.
- Evidence against: UID0000LT already has a stable distinct route; moving it would conflate a large template-form parser/type with normal article dialogs and disturb current ownership.
- Decision: rejected as current canonical source placement; retain as historical alternative only.

### 3. Parser-owned recovered helper file

- Evidence for: current old generated history once emitted the parser as a separate recovered file.
- Evidence against: parser has exactly two constructor-only callers, consumes the class row layout, and has no independent subsystem use.
- Decision: rejected. It is a file-local static helper in UID0000LT.

### Current file/grouping disposition

- No new compilation unit.
- The formerly missing sibling H and one non-emitting exact vtable-data documentation child now exist.
- Do not create standalone files for compiler thunks, scalar destructor, parser alias, RTTI, or raw vtable bytes.

## Source Placement

- CPP: `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`.
- H: `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.h`.
- Class emitter: UID000098.
- Method definitions: exact by-memory children in address order.
- File-local parser: UID0002UP, with a forward declaration before `[[CHILDREN]]` so the later address-ordered definition is visible to the constructor.
- The vtable, RTTI, adjustor thunks, and scalar deleting destructor are generated from the H declaration.
- Shared globals, packet helpers, controls, screen dimmer, and resources remain with their existing owners.

## Range / Split / Padding / Reclassification Analysis

- Main range remains `[0x004777a0,0x00478f8e)`; no split changes to the ten existing code children are required.
- Rename UID0002UM's document only; preserve UID/range.
- Rename UID0002UR's document only; preserve UID/range and its negative reachability history.
- Mark UID0000ZL `RECONSTRUCTABLE:FALSE`, clear emitter UIDs, and keep blank formal CPP/H because it is an index.
- Mark UID0000UE `RECONSTRUCTABLE:FALSE`, clear emitter UIDs, and keep blank formal CPP/H because UID0002UP owns the exact parser.
- Create `by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md` as a non-emitting class-owned data child after callback. Its range ends exactly where the next class COL begins.
- Preserve all ten `0xcc` gaps as alignment, not UNKNOWN code.
- Keep UID0000ZQ and UID0000ZS separate distant compiler companions.

## Negative Evidence Summary

- No extra function starts or executable bytes exist inside the main aggregate.
- No local named class/row UDT existed in the dated 2026-08-14 snapshot; decompiler types are not source proof.
- No inbound xref or pointer hit existed for `0x4781f0` or `0x478aa0` in the dated 2026-08-14 snapshot; this rejects a claim of observed live dispatch in that snapshot but does not reject retained authored source.
- No vtable slot points to the navigation or retained payload helpers; they are private retained methods.
- No evidence supports a handwritten destructor, raw vtable array, RTTI array, or adjustor function in source.
- No evidence supports the old generic `HandleEvent` interface or `int OnPaint`.
- No evidence supports a separate recovered parser compilation unit.
- Before callback, no generated H existed; that historical defect disproved a headerless module because multiple method bodies require the class and row declarations. Command `23592` now generates the exact required H.
- No third-party source import applies.

## IDA Rename / Type / Comment Recommendations

All IDA/MCP identities, prototypes, comments, item models, type results, and frames in the action rows began as a dated 2026-08-14 read-only evidence snapshot. The observed session identifier `supervisor-uid0000IW-recovery-20260814` remains only a historical evidence locator. The supervisor later established fresh runtime/database authority under canonical session `supervisor-uid0000KZ-gate2b-20260814`, applied or protected the accepted rows, saved, and completed post-save attestation/readback as recorded below.

Operational material removed during this repair is preserved verbatim in the [inert removed-material companion](0000LT-NewPredefinedFormArticleDialog-file-source-quality-removed.md). That companion is non-authoritative, must never be executed, and receives no report or lifecycle credit. The authoritative rows below contain semantic recommendations only.

### Semantic IDA recommendations and protections

The 44 rows below have explicit classifications: 19 `apply` and 25 `no change recommended`. The only mutation endpoints authorized are nine name-only public `rename` actions with `pure:true` and ten public `set_address_repeatable_comments` actions. Every no-change row has endpoint `none`; no row authorizes function creation, type/frame mutation, regular-address comments, function comments, data reshaping, or UDT creation.

### Dated supervisor Gate 2B closure receipt

- Closure date: `2026-08-14` local / `2026-08-15` UTC. Action-authorizing report SHA256: `8DB82EB79E27175B7D6750A10EDF21494D997732DCFAB2E577D3A6C954DA3D4D`.
- Runtime authority: canonical session `supervisor-uid0000KZ-gate2b-20260814`, canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; schema-1 runtime attestation passed at every preflight, mutation, save, and post-save boundary.
- Durable backup: `E:\NTK\Resources\NexusTK\idb-backups\NexusTK.exe.uid0000LT-pre-gate2b-20260815T0005269086295Z.i64`, SHA256 `35A59ACB79CB9F605187E0696B0D975F0ABF610CC6BFED1EC1B64640C8763ECA`, `143207794` bytes.
- Outcomes: I02/I04-I11 pure renames and I22-I31 address-repeatable comments are `APPLIED_VERIFIED`; I01/I03/I12-I21/I32-I44 are `NO_CHANGE_VERIFIED`.
- Save/readback: `idb_save` returned `ok:true`; canonical saved SHA256 `D62CA4D5D004A5F49D5ADBE72CEC550FD63281B8BA6CC6C741B0860896490FA7`, `143207794` bytes; post-save attestation and loaded-session readback passed.

| ID | Classification / exact public endpoint binding | Address/entity | Dated 2026-08-14 literal snapshot prestate | Proposed semantic action or no-change | Evidence | Safety constraints | Expected semantic readback |
| --- | --- | --- | --- | --- | --- | --- | --- |
| I01 | no change recommended; endpoint `none` | `[0x004781f0,0x00478238)` | No function object; function name absent; prototype absent; frame absent; AR absent; AP absent; FR not applicable; FP not applicable because no function exists; exact 72-byte body `51 8B 89 70 02 00 00 E8 54 90 02 00 6A 07 8B 88 FC 01 00 00 8B 01 FF 50 10 8B 00 8B 88 08 01 00 00 33 C0 80 3D 97 DA 66 00 01 0F 95 C0 0F B7 91 4C 01 00 00 8D 04 85 EC FF FF FF 50 68 FF 7F 00 00 52 E8 89 CF FF FF C3`; one-byte code items span through `0x00478237`; adjacent `[0x00478238,0x00478240)` is one eight-byte data/padding item; dated 2026-08-14 inbound xref count `0`, complete set `{}`, across the retained range, with zero VA/RVA/raw-offset pointer hits | Preserve this exact raw-code/no-function state; this report authorizes no function creation. | Complete bounded source-shaped body, fresh zero-function/zero-name/frame-error readback, exact adjacent padding, and the literal dated zero-xref set. | Preserve every byte/item boundary, no function object, function name absent, prototype absent, frame absent, FR not applicable, FP not applicable, and inbound xref count `0` with complete set `{}`; preserve AR absent; AP remains absent unless independently accepted I23 changes only AP. | No function object exists in `[0x4781f0,0x478238)`; function name remains absent; prototype remains absent; frame remains absent; bytes and item boundaries remain exact; dated inbound xref count remains `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits; AR remains absent; AP remains absent until independently adjudicated I23; FR remains not applicable; FP remains not applicable. |
| I02 | apply; endpoint `rename`; `pure:true`; old `sub_4777A0`; new `NewPredefinedFormArticleDialog__NewPredefinedFormArticleDialog`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x004777a0` | Name `sub_4777A0`; size `0xa45`; type `int __thiscall(int this, DialogSession *session, const unsigned __int16 *, int *, int)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x00471d4a, kind code call}` | Change only the function name to `NewPredefinedFormArticleDialog__NewPredefinedFormArticleDialog`. | Exact class, caller, RTTI, allocation size, and argument roles. | Preserve function range, type, F01 frame, bytes, all four comment channels, and inbound xref count `1` with complete set `{source 0x00471d4a, kind code call}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x4777a0`, size `0xa45`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `1` with complete set `{source 0x00471d4a, kind code call}`. |
| I03 | no change recommended; endpoint `none` | `0x004781f0` | No function object; function name absent; prototype absent; frame absent; AR absent; AP absent; FR not applicable; FP not applicable; dated 2026-08-14 inbound xref count `0`, complete set `{}`, for `0x004781f0` and the retained range, with zero VA/RVA/raw-offset pointer hits | Preserve the absent function-name state; do not rename or create an entity from this report. | Retained source semantics are already captured in formal CPP, while fresh read-only evidence cannot prove a deterministic function-creation poststate. | Preserve `[0x4781f0,0x478238)`, bytes/items, no function object, function name absent, prototype absent, frame absent, AR absent, FR not applicable, FP not applicable, and inbound xref count `0` with complete set `{}`; AP remains absent unless independently accepted I23 changes only AP; no destination collision check is needed because no rename is authorized. | No function object exists; function name remains absent; prototype remains absent; frame remains absent; bytes and item boundaries remain as I01 specifies; inbound xref count remains `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits; AR remains absent; AP remains absent unless independently accepted I23 changes only AP; FR remains not applicable; FP remains not applicable. |
| I04 | apply; endpoint `rename`; `pure:true`; old `sub_478240`; new `NewPredefinedFormArticleDialog_OnCommand`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x00478240` | Name `sub_478240`; size `0x62`; type `void __userpurge(unsigned int@<ecx>, __int16@<bx>, int, int)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x00614098, kind data}` | Change only the function name to `NewPredefinedFormArticleDialog_OnCommand`. | Primary vtable slot and complete two-command control flow. | Preserve range, snapshot type, F03 frame, bytes, all four comment channels, and inbound xref count `1` with complete set `{source 0x00614098, kind data}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x478240`, size `0x62`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `1` with complete set `{source 0x00614098, kind data}`. |
| I05 | apply; endpoint `rename`; `pure:true`; old `sub_4782B0`; new `NewPredefinedFormArticleDialog_OnTimer`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x004782b0` | Name `sub_4782B0`; size `0xb3`; type `char __thiscall(_DWORD *this, void *Block, int, int)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x006140e8, kind data}` | Change only the function name to `NewPredefinedFormArticleDialog_OnTimer`. | Tertiary TimerHandler vtable slot and timer-id-zero behavior. | Preserve range, snapshot type, F04 frame, bytes, all four comment channels, and inbound xref count `1` with complete set `{source 0x006140e8, kind data}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x4782b0`, size `0xb3`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `1` with complete set `{source 0x006140e8, kind data}`. |
| I06 | apply; endpoint `rename`; `pure:true`; old `sub_478370`; new `NewPredefinedFormArticleDialog_SetHoverControl`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x00478370` | Name `sub_478370`; size `0x9`; type `void __thiscall(DialogPane *this, int controlId)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x006140a8, kind data}` | Change only the function name to `NewPredefinedFormArticleDialog_SetHoverControl`. | Primary vtable slot and exact inherited forwarding body. | Preserve range, snapshot type, F05 frame, bytes, all four comment channels, and inbound xref count `1` with complete set `{source 0x006140a8, kind data}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x478370`, size `0x9`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `1` with complete set `{source 0x006140a8, kind data}`. |
| I07 | apply; endpoint `rename`; `pure:true`; old `sub_478380`; new `NewPredefinedFormArticleDialog_OnPaint`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x00478380` | Name `sub_478380`; size `0x2cc`; type `void __thiscall(int this)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x00614094, kind data}` | Change only the function name to `NewPredefinedFormArticleDialog_OnPaint`. | Primary vtable slot, inherited void contract, and complete paint behavior. | Preserve range, snapshot type, F06 frame, bytes, all four comment channels, and inbound xref count `1` with complete set `{source 0x00614094, kind data}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x478380`, size `0x2cc`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `1` with complete set `{source 0x00614094, kind data}`. |
| I08 | apply; endpoint `rename`; `pure:true`; old `sub_478650`; new `DeserializePredefinedFormArticleEntries`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x00478650` | Name `sub_478650`; size `0x2e3`; type `int __stdcall(int, int, _WORD *, _WORD *)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `2`, complete set `{source 0x00477848, kind code call; source 0x00477d0c, kind code call}` | Change only the function name to `DeserializePredefinedFormArticleEntries`. | Two constructor callers, callee cleanup, and exact row writes. | Preserve range, snapshot type, F07 frame, bytes, calling convention, all four comment channels, and inbound xref count `2` with complete set `{source 0x00477848, kind code call; source 0x00477d0c, kind code call}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x478650`, size `0x2e3`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `2` with complete set `{source 0x00477848, kind code call; source 0x00477d0c, kind code call}`. |
| I09 | apply; endpoint `rename`; `pure:true`; old `sub_478940`; new `NewPredefinedFormArticleDialog_HandleTransferReplyPredefinedAlert`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x00478940` | Name `sub_478940`; size `0x153`; type `char __thiscall(Pane *this, int)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x006140ac, kind data}` | Change only the function name to `NewPredefinedFormArticleDialog_HandleTransferReplyPredefinedAlert`. | Primary vtable slot, packet subcommand gate, and alert construction. | Preserve range, snapshot type, F08 frame, bytes, all four comment channels, and inbound xref count `1` with complete set `{source 0x006140ac, kind data}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x478940`, size `0x153`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `1` with complete set `{source 0x006140ac, kind data}`. |
| I10 | apply; endpoint `rename`; `pure:true`; old `sub_478AA0`; new `NewPredefinedFormArticleDialog_HandleTransferReplyPredefinedAlertPayload`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x00478aa0` | Name `sub_478AA0`; size `0x139`; type `char __thiscall(Pane *this, int)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `0`, complete set `{}`, with zero VA/RVA/raw-offset pointer hits | Change only the function name to `NewPredefinedFormArticleDialog_HandleTransferReplyPredefinedAlertPayload`. | Exact structural twin, same alert callees, and retained source-shaped payload behavior. | Preserve range, snapshot type, F09 frame, bytes, all four comment channels, and inbound xref count `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x478aa0`, size `0x139`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits. |
| I11 | apply; endpoint `rename`; `pure:true`; old `sub_478BE0`; new `NewPredefinedFormArticleDialog_SubmitArticle`; fail closed if source prestate differs, destination resolves to another entity, or readback is ambiguous | `0x00478be0` | Name `sub_478BE0`; size `0x3ae`; type `void __thiscall(unsigned int this, unsigned __int16)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x0047827e, kind code call}` | Change only the function name to `NewPredefinedFormArticleDialog_SubmitArticle`. | Sole command caller, packet writer width, and exact packet/timer body. | Preserve range, snapshot type, F10 frame, bytes, all four comment channels, and inbound xref count `1` with complete set `{source 0x0047827e, kind code call}`; destination name must not identify another entity. Endpoint scope is name-only; do not set a type, frame, or any comment channel. | Sole function at `0x478be0`, size `0x3ae`, requested name, exact snapshot type/frame/comments otherwise unchanged; inbound xref count remains `1` with complete set `{source 0x0047827e, kind code call}`. |
| I12 | no change recommended; endpoint `none` | `0x004777a0` | Type `int __thiscall(int this, DialogSession *session, const unsigned __int16 *, int *, int)`; complete frame F01 | Preserve the snapshot type/frame. Human-source candidate: `struct NewPredefinedFormArticleDialog *__thiscall NewPredefinedFormArticleDialog__NewPredefinedFormArticleDialog(struct NewPredefinedFormArticleDialog *this, DialogSession *session, const wchar_t *previousSubject, RectBounds *bounds, const unsigned char *formPacket)`. | Exact constructor behavior and source declaration in Section 22, but no deterministic target-specific IDA frame proof. | Authorize no IDA type/frame change from this report. | Snapshot type and every F01 row remain unchanged. |
| I13 | no change recommended; endpoint `none` | `0x004781f0` | No function object; function name absent; prototype absent; frame absent; AR absent; AP absent; FR not applicable; FP not applicable | Preserve absent prototype/frame as no-change evidence. Human-source candidate: `void __thiscall NewPredefinedFormArticleDialog_NavigateToPreviousArticleSelection(struct NewPredefinedFormArticleDialog *this)`. I23 is a separate independent AP-only action and is not authorized by I13. | Exact source-shaped body supports source C++, but fresh read-only evidence still contains no function or modeled frame. | Authorize no function creation and no IDA type/frame or comment change from this report row; preserve AR absent, FR not applicable, and FP not applicable; preserve AP absent unless independently accepted I23 changes only AP. | No function object exists; function name remains absent; prototype remains absent; frame remains absent; bytes/items remain unchanged; AR remains absent; AP remains absent unless independently accepted I23 sets its exact text; FR remains not applicable; FP remains not applicable. |
| I14 | no change recommended; endpoint `none` | `0x00478240` | Type `void __userpurge(unsigned int@<ecx>, __int16@<bx>, int, int)`; complete frame F03 | Preserve the snapshot type/frame. Human-source candidate: `void __thiscall NewPredefinedFormArticleDialog_OnCommand(struct NewPredefinedFormArticleDialog *this, int commandId, int commandParam)`. | Source role is strong, but exact IDA argument-row transformation lacks deterministic proof. | Authorize no IDA type/frame change and no added/removed stack row. | Snapshot type and every F03 row remain unchanged. |
| I15 | no change recommended; endpoint `none` | `0x004782b0` | Type `char __thiscall(_DWORD *this, void *Block, int, int)`; complete frame F04 | Preserve the snapshot type/frame. Human-source candidate: `bool __thiscall NewPredefinedFormArticleDialog_OnTimer(struct NewPredefinedFormArticleDialog *this, int timerId, int arg0, int arg1)`. | Tertiary vtable proves source role; exact IDA third-argument frame result is not proven. | Authorize no IDA type/frame change and no inferred stack row. | Snapshot type and every F04 row remain unchanged. |
| I16 | no change recommended; endpoint `none` | `0x00478370` | Type `void __thiscall(DialogPane *this, int controlId)`; complete frame F05 | Preserve the snapshot type/frame. Human-source candidate: `void __thiscall NewPredefinedFormArticleDialog_SetHoverControl(struct NewPredefinedFormArticleDialog *this, int controlId)`. | Derived receiver is source-correct; exact IDA frame transformation is not independently proven. | Authorize no IDA type/frame change. | Snapshot type and every F05 row remain unchanged. |
| I17 | no change recommended; endpoint `none` | `0x00478380` | Type `void __thiscall(int this)`; complete frame F06 | Preserve the snapshot type/frame. Human-source candidate: `void __thiscall NewPredefinedFormArticleDialog_OnPaint(struct NewPredefinedFormArticleDialog *this)`. | Void source contract is proven; exact receiver-type catalog behavior is not. | Authorize no IDA type/frame change. | Snapshot type and every F06 row remain unchanged. |
| I18 | no change recommended; endpoint `none` | `0x00478650` | Type `int __stdcall(int, int, _WORD *, _WORD *)`; complete frame F07 | Preserve the snapshot type/frame. Human-source candidate: `int __stdcall DeserializePredefinedFormArticleEntries(const unsigned char *serializedForm, struct PredefinedFormArticleEntry *entries, unsigned short *outVisibleRowCount, unsigned short *outEntryCount)`. | Four-argument stdcall source role is proven; local row UDT is absent. | Authorize no IDA type/frame change; preserve calling convention and all argument rows. | Snapshot type and every F07 row remain unchanged. |
| I19 | no change recommended; endpoint `none` | `0x00478940` | Type `char __thiscall(Pane *this, int)`; complete frame F08 | Preserve the snapshot type/frame. Human-source candidate: `bool __thiscall NewPredefinedFormArticleDialog_HandleTransferReplyPredefinedAlert(struct NewPredefinedFormArticleDialog *this, const unsigned char *packet)`. | Packet behavior is proven; snapshot `arg_4` cannot be removed without exact frame proof. | Authorize no IDA type/frame change. | Snapshot type and every F08 row remain unchanged. |
| I20 | no change recommended; endpoint `none` | `0x00478aa0` | Type `char __thiscall(Pane *this, int)`; complete frame F09 | Preserve the snapshot type/frame. Human-source candidate: `bool __thiscall NewPredefinedFormArticleDialog_HandleTransferReplyPredefinedAlertPayload(struct NewPredefinedFormArticleDialog *this, const unsigned char *payload)`. | Payload behavior is proven; snapshot `arg_4` cannot be removed without exact frame proof. | Authorize no IDA type/frame change. | Snapshot type and every F09 row remain unchanged. |
| I21 | no change recommended; endpoint `none` | `0x00478be0` | Type `void __thiscall(unsigned int this, unsigned __int16)`; complete frame F10 | Preserve the snapshot type/frame. Human-source candidate: `void __thiscall NewPredefinedFormArticleDialog_SubmitArticle(struct NewPredefinedFormArticleDialog *this, unsigned short boardId)`. | Packet width proves the source argument, but local class type is absent. | Authorize no IDA type/frame change; preserve the 2-byte argument row. | Snapshot type and every F10 row remain unchanged. |
| I22 | apply; endpoint `set_address_repeatable_comments`; address `0x004777a0`; exact repeatable text `Constructs the predefined-form article dialog, parses up to twenty form rows, creates current or legacy controls, and applies final bounds.` | `0x004777a0` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `Constructs the predefined-form article dialog, parses up to twenty form rows, creates current or legacy controls, and applies final bounds.` | Exact constructor behavior and role. | Preserve the regular address and both function comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I23 | apply; endpoint `set_address_repeatable_comments`; address `0x004781f0`; exact repeatable text `Retained private helper that reads the previous article selection and sends the shared navigation request.` | `0x004781f0` | No function object; function name absent; prototype absent; frame absent; AR absent; AP absent; FR not applicable; FP not applicable; dated 2026-08-14 inbound xref count `0`, complete set `{}`, for `0x004781f0` and the retained range, with zero VA/RVA/raw-offset pointer hits | Independently set AP to `Retained private helper that reads the previous article selection and sends the shared navigation request.` | Exact retained navigation behavior and fresh no-function/comment/xref readback. | Preserve no function object, function name absent, prototype absent, frame absent, all bytes/items, AR absent, FR not applicable, FP not applicable, and inbound xref count `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits. Endpoint scope is AP-only; do not alter any other comment channel. | No function object exists; function name remains absent; prototype remains absent; frame remains absent; AP equals the exact text; AR remains absent; FR remains not applicable; FP remains not applicable; inbound xref count remains `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits. |
| I24 | apply; endpoint `set_address_repeatable_comments`; address `0x00478240`; exact repeatable text `Handles submit command 0 and cancel command 1 for the predefined-form article dialog.` | `0x00478240` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `Handles submit command 0 and cancel command 1 for the predefined-form article dialog.` | Complete two-command control flow. | Preserve the other three comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I25 | apply; endpoint `set_address_repeatable_comments`; address `0x004782b0`; exact repeatable text `TimerHandler override for submit timeout id 0; releases the dimmer and opens the fixed transfer-error alert.` | `0x004782b0` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `TimerHandler override for submit timeout id 0; releases the dimmer and opens the fixed transfer-error alert.` | Tertiary vtable slot and exact timer behavior. | Preserve the other three comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I26 | apply; endpoint `set_address_repeatable_comments`; address `0x00478370`; exact repeatable text `Forwards hover-control selection to DialogPane.` | `0x00478370` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `Forwards hover-control selection to DialogPane.` | Exact inherited tail-forwarding body. | Preserve the other three comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I27 | apply; endpoint `set_address_repeatable_comments`; address `0x00478380`; exact repeatable text `Paints the variable-height DLGBBS08 current or legacy dialog frame.` | `0x00478380` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `Paints the variable-height DLGBBS08 current or legacy dialog frame.` | Exact resource branch and paint loops. | Preserve the other three comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I28 | apply; endpoint `set_address_repeatable_comments`; address `0x00478650`; exact repeatable text `Parses serialized predefined-form rows into 0x40c-byte PredefinedFormArticleEntry records.` | `0x00478650` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `Parses serialized predefined-form rows into 0x40c-byte PredefinedFormArticleEntry records.` | Exact parser writes, stride, and callers. | Preserve the other three comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I29 | apply; endpoint `set_address_repeatable_comments`; address `0x00478940`; exact repeatable text `Handles full transfer-reply packets whose subcommand byte is 0x06.` | `0x00478940` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `Handles full transfer-reply packets whose subcommand byte is 0x06.` | Primary vtable slot and packet gate. | Preserve the other three comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I30 | apply; endpoint `set_address_repeatable_comments`; address `0x00478aa0`; exact repeatable text `Retained payload-layout transfer-reply helper; no inbound xref was present in the 2026-08-14 research snapshot.` | `0x00478aa0` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent; dated 2026-08-14 inbound xref count `0`, complete set `{}`, with zero VA/RVA/raw-offset pointer hits | Set address-repeatable comment to `Retained payload-layout transfer-reply helper; no inbound xref was present in the 2026-08-14 research snapshot.` | Structural twin and dated zero-xref snapshot. | Preserve the other three comment channels, the documented liveness caveat, and inbound xref count `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent; inbound xref count remains `0` with complete set `{}` and zero VA/RVA/raw-offset pointer hits. |
| I31 | apply; endpoint `set_address_repeatable_comments`; address `0x00478be0`; exact repeatable text `Serializes and sends opcode 0x3b subcommand 4, then schedules timer id 0 for 15000 ms.` | `0x00478be0` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Set address-repeatable comment to `Serializes and sends opcode 0x3b subcommand 4, then schedules timer id 0 for 15000 ms.` | Exact packet and timer behavior. | Preserve the other three comment channels. Endpoint scope is address-repeatable only; do not alter any other comment channel. | Address repeatable equals exact text; the other three channels remain absent. |
| I32 | no change recommended; endpoint `none` | `0x0047e931` | Name `sub_47E931`; size `0xb`; type `boost::exception *__thiscall(char *this, char)`; frame F11; AR absent; AP absent; FR absent; FP absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x006140b4, kind data}` | Preserve function identity, type, frame, AR, AP, FR, FP, and literal xref set. | Compiler adjustor with `this -= 0xa0`. | Do not invent a human-source method identity; preserve inbound xref count `1` with complete set `{source 0x006140b4, kind data}`. | Name, range, type, F11, and bytes remain unchanged; AR remains absent; AP remains absent; FR remains absent; FP remains absent; inbound xref count remains `1` with complete set `{source 0x006140b4, kind data}`. |
| I33 | no change recommended; endpoint `none` | `0x0047e93c` | Name `sub_47E93C`; size `0xb`; type `boost::exception *__thiscall(char *this, char)`; frame F12; AR absent; AP absent; FR absent; FP absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x006140e4, kind data}` | Preserve function identity, type, frame, AR, AP, FR, FP, and literal xref set. | Compiler adjustor with `this -= 0xa4`. | Do not invent a human-source method identity; preserve inbound xref count `1` with complete set `{source 0x006140e4, kind data}`. | Name, range, type, F12, and bytes remain unchanged; AR remains absent; AP remains absent; FR remains absent; FP remains absent; inbound xref count remains `1` with complete set `{source 0x006140e4, kind data}`. |
| I34 | no change recommended; endpoint `none` | `0x0047ec30` | Name `sub_47EC30`; size `0x3b`; type `boost::exception *__thiscall(boost::exception *Block, char)`; frame F13; AR absent; AP absent; FR absent; FP absent; dated 2026-08-14 inbound xref count `3`, complete set `{source 0x00614050, kind data; source 0x0047e937, kind code jump; source 0x0047e942, kind code jump}` | Preserve function identity, type, frame, AR, AP, FR, FP, and literal xref set. | Compiler-generated scalar deleting destructor. | Do not invent a handwritten destructor body; preserve inbound xref count `3` with complete set `{source 0x00614050, kind data; source 0x0047e937, kind code jump; source 0x0047e942, kind code jump}`. | Name, range, type, F13, and bytes remain unchanged; AR remains absent; AP remains absent; FR remains absent; FP remains absent; inbound xref count remains `3` with complete set `{source 0x00614050, kind data; source 0x0047e937, kind code jump; source 0x0047e942, kind code jump}`. |
| I35 | no change recommended; endpoint `none` | `0x0047e931` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Preserve all comment channels as absent. | Compiler-only role is already documented in source evidence. | Add no IDA comment. | All four channels remain absent. |
| I36 | no change recommended; endpoint `none` | `0x0047e93c` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Preserve all comment channels as absent. | Compiler-only role is already documented in source evidence. | Add no IDA comment. | All four channels remain absent. |
| I37 | no change recommended; endpoint `none` | `0x0047ec30` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent | Preserve all comment channels as absent. | Compiler-only role is already documented in source evidence. | Add no IDA comment. | All four channels remain absent. |
| I38 | no change recommended; endpoint `none` | `0x00614050` | Data item `[0x614050,0x614054)`; size 4; empty type; name `??_7NewPredefinedFormArticleDialog@@6B@`; address regular absent; address repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x004777ee, kind data}` | Preserve the data item, name, type, comments, and literal xref set. | Existing MSVC primary-view vtable symbol is stronger than an inferred alias. | Do not reshape or rename compiler data; preserve inbound xref count `1` with complete set `{source 0x004777ee, kind data}`. | Exact head/end/size/name/type and comments remain unchanged; inbound xref count remains `1` with complete set `{source 0x004777ee, kind data}`. |
| I39 | no change recommended; endpoint `none` | `0x006140b4` | Data item `[0x6140b4,0x6140b8)`; size 4; empty type; name `??_7NewPredefinedFormArticleDialog@@6B@_0`; address regular absent; address repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x004777f4, kind data}` | Preserve the data item, name, type, comments, and literal xref set. | Existing MSVC EventHandler-view symbol is stronger than an inferred alias. | Do not reshape or rename compiler data; preserve inbound xref count `1` with complete set `{source 0x004777f4, kind data}`. | Exact head/end/size/name/type and comments remain unchanged; inbound xref count remains `1` with complete set `{source 0x004777f4, kind data}`. |
| I40 | no change recommended; endpoint `none` | `0x006140e4` | Data item `[0x6140e4,0x6140e8)`; size 4; empty type; name `??_7NewPredefinedFormArticleDialog@@6B@_1`; address regular absent; address repeatable absent; dated 2026-08-14 inbound xref count `1`, complete set `{source 0x004777fe, kind data}` | Preserve the data item, name, type, comments, and literal xref set. | Existing MSVC TimerHandler-view symbol is stronger than an inferred alias. | Do not reshape or rename compiler data; preserve inbound xref count `1` with complete set `{source 0x004777fe, kind data}`. | Exact head/end/size/name/type and comments remain unchanged; inbound xref count remains `1` with complete set `{source 0x004777fe, kind data}`. |
| I41 | no change recommended; endpoint `none` | `0x00614050` | AR absent; AP absent | Preserve AR absent; preserve AP absent. | View role is documented in the report and source routing. | Add no IDA comment. | AR remains absent; AP remains absent. |
| I42 | no change recommended; endpoint `none` | `0x006140b4` | AR absent; AP absent | Preserve AR absent; preserve AP absent. | View role is documented in the report and source routing. | Add no IDA comment. | AR remains absent; AP remains absent. |
| I43 | no change recommended; endpoint `none` | `0x006140e4` | AR absent; AP absent | Preserve AR absent; preserve AP absent. | View role is documented in the report and source routing. | Add no IDA comment. | AR remains absent; AP remains absent. |
| I44 | no change recommended; endpoint `none` | `PredefinedFormArticleEntry` and `NewPredefinedFormArticleDialog` | `PredefinedFormArticleEntry` absent; `NewPredefinedFormArticleDialog` absent; exact-name and wildcard searches returned zero matching local types for each name | Preserve each local-type absence independently; authorize no local UDT creation or dependent IDA type change. | Public named-type absence and exact human-source layout in Section 22. | Keep the source declaration solely in the formal H recommendation. | `PredefinedFormArticleEntry` remains absent; `NewPredefinedFormArticleDialog` remains absent. Source layout remains seven fields at offsets `0x000`, `0x002`, `0x202`, `0x203`, `0x204`, `0x206`, and `0x408`, total size `0x40c`, with no explicit reserved fields. |

RTTI at `0x00674e00` and `[0x006439a4,0x00643a34)` is a protected dependency, not a Gate 2B action. In the dated 2026-08-14 snapshot, item `0x00674e00` was `[0x674e00,0x674e04)`, size 4, empty type, name `??_R0?AVNewPredefinedFormArticleDialog@@@8`; item `0x006439a4` was `[0x6439a4,0x6439a8)`, size 4, empty type, name `??_R4NewPredefinedFormArticleDialog@@6B@`. These facts are non-authoritative for later mutable state, and no semantic recommendation changes those ranges.

### Dated frame evidence and protected semantic disposition

The 2026-08-14 snapshot supports no IDA type/frame change from this report. Each frame below is historical non-authoritative evidence, and the semantic disposition preserves every listed row. The source candidates in I12-I21 document human-source shape only.

| Frame | Function | Complete dated snapshot frame; exact protected semantic disposition |
| --- | --- | --- |
| F01 | `0x004777a0` | `textWidthScale@0x0:float:0x4`; `var_40@0x18:_DWORD:0x4`; `var_3C@0x1c:void *:0x4`; `block@0x20:void *:0x4`; `var_34@0x24:_DWORD:0x4`; `var_30@0x28:void *:0x4`; `var_2C@0x2c:TextEditControlPane *:0x4`; `Block@0x30:void *:0x4`; `var_21@0x37:_BYTE:0x1`; `bounds@0x38:struct RectBounds:0x10`; `var_10@0x48:_DWORD:0x4`; `var_C@0x4c:_DWORD:0x4`; `var_4@0x54:_DWORD:0x4`; `__saved_registers@0x58:_DWORD:0x4`; `__return_address@0x5c:_UNKNOWN *:0x4`; `session@0x60:DialogSession *:0x4`; `arg_4@0x64:_DWORD:0x4`; `arg_8@0x68:_DWORD:0x4`; `arg_C@0x6c:_DWORD:0x4`. |
| F02 | `0x004781f0` | No function or frame existed in the dated snapshot; this report authorizes no type/frame change for that entity. |
| F03 | `0x00478240` | `__saved_registers@0x4:_DWORD:0x4`; `__return_address@0x8:_UNKNOWN *:0x4`; `arg_0@0xc:_DWORD:0x4`. |
| F04 | `0x004782b0` | `var_C@0xc:_DWORD:0x4`; `var_4@0x14:_DWORD:0x4`; `__saved_registers@0x18:_DWORD:0x4`; `__return_address@0x1c:_UNKNOWN *:0x4`; `Block@0x20:void *:0x4`; `arg_4@0x24:_DWORD:0x4`. |
| F05 | `0x00478370` | `__saved_registers@0x0:_DWORD:0x4`; `__return_address@0x4:_UNKNOWN *:0x4`. |
| F06 | `0x00478380` | `outContext@0xc:EPFTileContext:0x28`; `var_64@0x34:EPFTileContext:0x28`; `tileContext@0x5c:EPFTileContext:0x28`; `bounds@0x84:struct RectBounds:0x10`; `var_4@0x94:_DWORD:0x4`; `__saved_registers@0x98:_DWORD:0x4`; `__return_address@0x9c:_UNKNOWN *:0x4`. |
| F07 | `0x00478650` | `var_324@0xc:_DWORD:0x4`; `var_320@0x10:_DWORD:0x4`; `var_31C@0x14:_DWORD:0x4`; `var_318@0x18:_DWORD:0x4`; `var_314@0x1c:MemoryMan *:0x4`; `var_310@0x20:_DWORD:0x4`; `var_30C@0x24:_DWORD:0x4`; `var_307@0x29:_BYTE:0x1`; `var_306@0x2a:_BYTE:0x1`; `var_305@0x2b:_BYTE:0x1`; `var_304@0x2c:WCHAR[256]:0x200`; `destination@0x22c:CHAR[256]:0x100`; `var_4@0x32c:_DWORD:0x4`; `__saved_registers@0x330:_DWORD:0x4`; `__return_address@0x334:_UNKNOWN *:0x4`; `arg_0@0x338:_DWORD:0x4`; `arg_4@0x33c:_DWORD:0x4`; `arg_8@0x340:_DWORD:0x4`; `arg_C@0x344:_DWORD:0x4`. |
| F08 | `0x00478940` | `Block@0x10:void *:0x4`; `var_311@0x17:_BYTE:0x1`; `WideCharStr@0x18:WCHAR[256]:0x200`; `MultiByteStr@0x218:CHAR[256]:0x100`; `var_10@0x318:_DWORD:0x4`; `var_C@0x31c:_DWORD:0x4`; `var_4@0x324:_DWORD:0x4`; `__saved_registers@0x328:_DWORD:0x4`; `__return_address@0x32c:_UNKNOWN *:0x4`; `arg_0@0x330:_DWORD:0x4`; `arg_4@0x334:_DWORD:0x4`. |
| F09 | `0x00478aa0` | `Block@0x10:void *:0x4`; `var_311@0x17:_BYTE:0x1`; `WideCharStr@0x18:WCHAR[256]:0x200`; `MultiByteStr@0x218:CHAR[256]:0x100`; `var_10@0x318:_DWORD:0x4`; `var_C@0x31c:_DWORD:0x4`; `var_4@0x324:_DWORD:0x4`; `__saved_registers@0x328:_DWORD:0x4`; `__return_address@0x32c:_UNKNOWN *:0x4`; `arg_0@0x330:_DWORD:0x4`; `arg_4@0x334:_DWORD:0x4`. |
| F10 | `0x00478be0` | `var_D214@0xc:_DWORD:0x4`; `var_D210@0x10:_DWORD:0x4`; `var_D20C@0x14:_DWORD:0x4`; `var_D208@0x18:MemoryMan *:0x4`; `destination@0x1c:unsigned __int8:0x1`; `var_D203@0x1d:unsigned __int8:0x1`; `var_D202@0x1e:char[2]:0x2`; `var_D200@0x20:unsigned __int8:0x1`; `var_D1FF@0x21:_BYTE:0x1`; `var_D1FD@0x23:_BYTE:0x1`; `Src@0x801c:WCHAR[4096]:0x2000`; `Destination@0xa01c:wchar_t[4096]:0x2000`; `MultiByteStr@0xc01c:CHAR[4096]:0x1000`; `WideCharStr@0xd01c:WCHAR:0x2`; `var_4@0xd21c:_DWORD:0x4`; `__saved_registers@0xd220:_DWORD:0x4`; `__return_address@0xd224:_UNKNOWN *:0x4`; `arg_0@0xd228:_WORD:0x2`. |
| F11 | `0x0047e931` | `__return_address@0x0:_UNKNOWN *:0x4`. |
| F12 | `0x0047e93c` | `__return_address@0x0:_UNKNOWN *:0x4`. |
| F13 | `0x0047ec30` | `__saved_registers@0x4:_DWORD:0x4`; `__return_address@0x8:_UNKNOWN *:0x4`; `arg_0@0xc:_DWORD:0x4`. |

## First-Draft C++ Recommendation

Eligible: every source-authored body. Compiler-only thunks/destructor, physical aggregate, parser alias, vtable/RTTI bytes, and alignment remain blank.

### UID000098 formal RECONSTRUCTION_H insertion

```cpp
#pragma once

#include "BulletinDialog.h"

class DialogSession;
struct RectBounds;

struct PredefinedFormArticleEntry
{
    unsigned char titleLength;
    wchar_t title[256];
    bool usesUserImagePane;
    unsigned char textLineCount;
    unsigned char bodyLength;
    wchar_t body[256];
    int rowAdvanceMode;
};

class NewPredefinedFormArticleDialog : public BulletinDialog
{
public:
    NewPredefinedFormArticleDialog(DialogSession *session,
        const wchar_t *previousSubject,
        RectBounds *bounds,
        const unsigned char *formPacket);

    virtual void OnPaint();
    virtual void OnCommand(int commandId, int commandParam);
    virtual void SetHoverControl(int controlId);
    virtual bool HandleTransferReplyPredefinedAlert(
        const unsigned char *packet);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void NavigateToPreviousArticleSelection();
    bool HandleTransferReplyPredefinedAlertPayload(
        const unsigned char *payload);
    void SubmitArticle(unsigned short boardId);

    unsigned short m_predefinedFormEntryCount;
    unsigned short m_visibleFormRowCount;
    PredefinedFormArticleEntry m_predefinedFormEntries[20];
};
```

### UID000098 formal RECONSTRUCTION_CPP insertion

```cpp
#include "NewPredefinedFormArticleDialog.h"

#include <windows.h>
#include <cstring>
#include <cwchar>

#include "BulletinSession.h"
#include "DialogControls.h"
#include "PacketBuffer.h"
#include "ScreenDimmer.h"
#include "TransferReplyPredefinedAlert.h"

static int __stdcall DeserializePredefinedFormArticleEntries(
    const unsigned char *serializedForm,
    PredefinedFormArticleEntry *entries,
    unsigned short *outVisibleRowCount,
    unsigned short *outEntryCount);

[[CHILDREN]]
```

### UID0002UJ formal RECONSTRUCTION_CPP insertion

```cpp
NewPredefinedFormArticleDialog::NewPredefinedFormArticleDialog(
    DialogSession *session,
    const wchar_t *previousSubject,
    RectBounds *bounds,
    const unsigned char *formPacket)
    : BulletinDialog(session, 5)
{
    const bool freeTextMode =
        g_pUserPane->m_predefinedFormArticleFreeTextMode;

    if (freeTextMode)
    {
        m_predefinedFormEntryCount = 1;
        m_visibleFormRowCount = 5;
    }
    else
    {
        DeserializePredefinedFormArticleEntries(
            formPacket,
            m_predefinedFormEntries,
            &m_visibleFormRowCount,
            &m_predefinedFormEntryCount);
    }

    RectBounds controlBounds;
    const int visibleRows = m_visibleFormRowCount;

    if (g_useEpfAssets)
    {
        InitRectBounds(&controlBounds, 149, 25 * visibleRows + 139,
            212, 25 * visibleRows + 163);
        AddControl(new ImageButtonControlPane(23, &controlBounds));

        InitRectBounds(&controlBounds, 226, 25 * visibleRows + 139,
            289, 25 * visibleRows + 163);
        AddControl(new ImageButtonControlPane(22, &controlBounds));

        InitRectBounds(&controlBounds, 94, 59, 404, 71);
        AddControl(new StaticTextControlPane(previousSubject, true,
            37, 0, &controlBounds, false, false));

        InitRectBounds(&controlBounds, 94, 86, 404, 98);
    }
    else
    {
        InitRectBounds(&controlBounds, 149, 21 * visibleRows + 108,
            221, 21 * visibleRows + 124);
        AddControl(new ImageButtonControlPane(23, &controlBounds));

        InitRectBounds(&controlBounds, 226, 21 * visibleRows + 108,
            298, 21 * visibleRows + 124);
        AddControl(new ImageButtonControlPane(22, &controlBounds));

        InitRectBounds(&controlBounds, 131, 51, 410, 63);
        AddControl(new StaticTextControlPane(previousSubject, true,
            37, 0, &controlBounds, false, false));

        InitRectBounds(&controlBounds, 131, 71, 410, 83);
    }

    AddControl(new TextEditControlPane(g_emptyWideString, true,
        143, 0, &controlBounds, false, false, false, false, 1.0f, 0));

    if (freeTextMode)
    {
        InitRectBounds(&controlBounds, 36, 110, 410,
            (g_useEpfAssets ? 25 : 21) * visibleRows + 110);

        TextEditControlPane *bodyEdit =
            new TextEditControlPane(g_emptyWideString, true,
                143, 0, &controlBounds, false, true,
                false, false, 0.99f, 0);
        bodyEdit->m_reservedControlState = 1;
        bodyEdit->SetMaxLines(1024);
        bodyEdit->SetMaxLength(4096);
        AddControl(bodyEdit);
    }
    else
    {
        int left = 36;
        int rowTop = 110;

        for (unsigned char rowIndex = 0;
             rowIndex < m_predefinedFormEntryCount;
             ++rowIndex)
        {
            PredefinedFormArticleEntry& entry =
                m_predefinedFormEntries[rowIndex];
            const int titleWidth =
                GetTextWidth(entry.title, entry.titleLength);
            const int titleRight = left + titleWidth;

            InitRectBounds(&controlBounds,
                left, rowTop, titleRight, rowTop + 16);
            AddControl(new StaticTextControlPane(entry.title, true,
                37, 0, &controlBounds, false, false));

            TextEditControlPane *valueEdit;

            if (entry.usesUserImagePane)
            {
                InitRectBounds(&controlBounds,
                    titleRight, rowTop,
                    titleRight + titleWidth, rowTop + 16);
                valueEdit = new TextEditControlPane(entry.body, true,
                    143, 0, &controlBounds, false, false,
                    true, false, 1.0f, 0);

                if (entry.rowAdvanceMode != 0)
                {
                    rowTop += 21;
                    left = 36;
                }
                else
                {
                    left = titleRight + 5 + 6 * entry.textLineCount;
                }
            }
            else
            {
                rowTop += 21;
                InitRectBounds(&controlBounds,
                    36, rowTop, 400,
                    rowTop + 16 * entry.textLineCount);
                valueEdit = new TextEditControlPane(entry.body, true,
                    143, 0, &controlBounds, false, true,
                    true, false, 0.99f, 0);
                valueEdit->m_reservedControlState = 1;
                valueEdit->SetMaxLines(1024);
                valueEdit->SetMaxLength(4000);
                rowTop += 21 *
                    ((16 * entry.textLineCount) / 21 + 1);
                left = 36;
            }

            AddControl(valueEdit);
        }
    }

    InitRectBounds(bounds, 50, 50,
        g_useEpfAssets ? 500 : 496,
        (g_useEpfAssets ? 25 : 21) * visibleRows +
            (g_useEpfAssets ? 254 : 208));
    SetPendingControl(1);
    SetHoverControl(3);
    SetBounds(bounds, false);
}
```

The two inferred source-facing inline/protected spellings `m_reservedControlState` and `SetBounds` are backed by the exact direct stores/call and surrounding ControlPane/Pane conventions. The accepted callback retained those spellings in the formal source, and command `23592` reproduces them exactly in generated CPP. Any later project-wide rename requires separate evidence and is not an unresolved callback substitution.

### UID0002EK formal RECONSTRUCTION_CPP insertion

```cpp
void NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()
{
    DialogInSession *previous = m_session->FindPreviousDialog(this);
    ListPane *list =
        static_cast<ListPane *>(previous->GetControl(7));
    const unsigned short articleId =
        static_cast<unsigned short>(list->SelectedArticleId());

    SendArticleNavigationRequest(articleId, 0x7fff,
        g_useEpfAssets ? -0x14 : -0x10);
}
```

### UID0002UK formal RECONSTRUCTION_CPP insertion

```cpp
void NewPredefinedFormArticleDialog::OnCommand(
    int commandId, int)
{
    BulletinSession *session = GetSession();

    if (commandId == 0)
    {
        const unsigned short boardId =
            session != NULL ? session->m_currentBoardId : 0;
        SubmitArticle(boardId);

        if (g_pUserPane != NULL)
        {
            g_pUserPane->m_activeDialogHostPane = this;
        }

        CreateScreenDimmer();
        return;
    }

    if (commandId == 1 && session != NULL)
    {
        session->PopCurrentDialog(false);
    }
}
```

### UID0002UM formal RECONSTRUCTION_CPP insertion

```cpp
bool NewPredefinedFormArticleDialog::OnTimer(
    int timerId, int, int)
{
    if (timerId == 0 && IsScreenDimmerActive())
    {
        ReleaseScreenDimmer();
        new TransferReplyPredefinedAlert(false,
            L"Your post didn't go through due to an error.",
            this);
    }

    return true;
}
```

### UID0002UN formal RECONSTRUCTION_CPP insertion

```cpp
void NewPredefinedFormArticleDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}
```

### UID0002UO formal RECONSTRUCTION_CPP insertion

```cpp
void NewPredefinedFormArticleDialog::OnPaint()
{
    EPFFrame headerFrame;
    EPFFrame rowFrame;
    EPFFrame footerFrame;
    RectBounds drawRect;

    headerFrame.Clear();
    rowFrame.Clear();
    footerFrame.Clear();

    m_redrawPending = false;
    SetPaneDrawMode(0);
    g_surfaceCallbacks.FillOrPresent(this, &m_paintRegion);
    SetPaneDrawMode(0x80);

    if (g_useEpfAssets)
    {
        g_pEPFLib->LoadFrame(L"DLGBBS08.EPF", 0, &headerFrame);
        g_pEPFLib->LoadFrame(L"DLGBBS08.EPF", 1, &rowFrame);
        g_pEPFLib->LoadFrame(L"DLGBBS08.EPF", 2, &footerFrame);

        drawRect.Set(0, 0, 450, 120);
        DrawEPFFrame(&headerFrame, &drawRect, L"DLGBBS08.PAL");

        drawRect.Offset(0, 120);
        drawRect.bottom = drawRect.top + 25;
        for (unsigned char row = 0;
             row < m_visibleFormRowCount;
             ++row)
        {
            DrawEPFFrame(&rowFrame, &drawRect, L"DLGBBS08.PAL");
            drawRect.Offset(0, 25);
            drawRect.bottom = drawRect.top + 25;
        }

        drawRect.bottom = drawRect.top + 84;
        DrawEPFFrame(&footerFrame, &drawRect, L"DLGBBS08.PAL");
        return;
    }

    g_pEPFLib->LoadFrame(L"DLGBBS08.EPD", 0, &headerFrame);
    g_pEPFLib->LoadFrame(L"DLGBBS08.EPD", 1, &rowFrame);
    g_pEPFLib->LoadFrame(L"DLGBBS08.EPD", 2, &footerFrame);

    drawRect.Set(0, 0, 446, 88);
    DrawEPFFrame(&headerFrame, &drawRect, L"NPAL8.PAL");

    drawRect.Offset(0, 88);
    drawRect.bottom = drawRect.top + 21;
    for (unsigned char row = 0;
         row < m_visibleFormRowCount;
         ++row)
    {
        DrawEPFFrame(&rowFrame, &drawRect, L"NPAL8.PAL");
        drawRect.Offset(0, 21);
        drawRect.bottom = drawRect.top + 21;
    }

    drawRect.bottom = drawRect.top + 70;
    DrawEPFFrame(&footerFrame, &drawRect, L"NPAL8.PAL");
}
```

### UID0002UP formal RECONSTRUCTION_CPP insertion

```cpp
static int __stdcall DeserializePredefinedFormArticleEntries(
    const unsigned char *serializedForm,
    PredefinedFormArticleEntry *entries,
    unsigned short *outVisibleRowCount,
    unsigned short *outEntryCount)
{
    char narrowText[256] = {};
    wchar_t convertedBody[256] = {};

    unsigned char entryCount = 0;
    unsigned char visibleRowCount = 0;
    unsigned char titleByteLength = serializedForm[1];
    int cursor = 2;

    while (titleByteLength != 0)
    {
        PredefinedFormArticleEntry& entry = entries[entryCount];

        memmove(narrowText, serializedForm + cursor, titleByteLength);
        narrowText[titleByteLength] = '\0';

        const unsigned char titleLength =
            static_cast<unsigned char>(MultiByteToWideChar(
                CP_ACP, 0, narrowText, titleByteLength,
                entry.title, 256));
        entry.titleLength = titleLength;
        entry.title[titleLength] = L'\0';

        cursor += titleByteLength + 1;
        entry.usesUserImagePane = serializedForm[cursor++] == 1;
        entry.textLineCount = serializedForm[cursor++];

        const unsigned char bodyByteLength =
            serializedForm[cursor++];
        memmove(narrowText, serializedForm + cursor, bodyByteLength);
        narrowText[bodyByteLength] = '\0';
        cursor += bodyByteLength;

        const unsigned char convertedBodyLength =
            static_cast<unsigned char>(MultiByteToWideChar(
                CP_ACP, 0, narrowText, bodyByteLength,
                convertedBody, 256));
        convertedBody[convertedBodyLength] = L'\0';

        const bool bodyIsEmpty =
            wcscmp(convertedBody, L"empty") == 0;
        entry.bodyLength =
            bodyIsEmpty ? 0 : convertedBodyLength;
        wcscpy_s(entry.body, 256,
            bodyIsEmpty ? g_emptyWideString : convertedBody);

        entry.rowAdvanceMode =
            serializedForm[cursor++] == 1 ? 1 : 0;

        unsigned char rowBase = visibleRowCount;
        if (entry.rowAdvanceMode == 1)
        {
            rowBase = ++visibleRowCount;
        }

        if (!entry.usesUserImagePane)
        {
            visibleRowCount = static_cast<unsigned char>(
                rowBase + (16 * entry.textLineCount) / 21 + 1);
        }

        ++entryCount;
        titleByteLength = serializedForm[cursor++];
    }

    *outEntryCount = entryCount;
    *outVisibleRowCount = visibleRowCount;
    return visibleRowCount;
}
```

### UID0002UQ formal RECONSTRUCTION_CPP insertion

```cpp
bool NewPredefinedFormArticleDialog::
HandleTransferReplyPredefinedAlert(const unsigned char *packet)
{
    if (packet[1] != 0x06)
    {
        return false;
    }

    if (IsScreenDimmerActive())
    {
        ReleaseScreenDimmer();
    }

    const unsigned char replyMode = packet[2];
    const unsigned int messageLength = packet[3];

    char multiByteMessage[256] = {};
    memmove(multiByteMessage, packet + 4, messageLength);
    multiByteMessage[messageLength] = '\0';

    wchar_t wideMessage[256] = {};
    const unsigned char wideLength =
        static_cast<unsigned char>(MultiByteToWideChar(
            CP_ACP, 0, multiByteMessage,
            static_cast<int>(messageLength),
            wideMessage, 256));
    wideMessage[wideLength] = L'\0';

    new TransferReplyPredefinedAlert(
        replyMode, wideMessage, this);
    return true;
}
```

### UID0002UR formal RECONSTRUCTION_CPP insertion

```cpp
bool NewPredefinedFormArticleDialog::
HandleTransferReplyPredefinedAlertPayload(
    const unsigned char *payload)
{
    if (IsScreenDimmerActive())
    {
        ReleaseScreenDimmer();
    }

    const unsigned char replyMode = payload[0];
    const unsigned int messageLength = payload[1];

    char multiByteMessage[256] = {};
    memmove(multiByteMessage, payload + 2, messageLength);
    multiByteMessage[messageLength] = '\0';

    wchar_t wideMessage[256] = {};
    const unsigned char wideLength =
        static_cast<unsigned char>(MultiByteToWideChar(
            CP_ACP, 0, multiByteMessage,
            static_cast<int>(messageLength),
            wideMessage, 256));
    wideMessage[wideLength] = L'\0';

    new TransferReplyPredefinedAlert(
        replyMode, wideMessage, this);
    return true;
}
```

### UID0002UL formal RECONSTRUCTION_CPP insertion

```cpp
void NewPredefinedFormArticleDialog::SubmitArticle(
    unsigned short boardId)
{
    char packet[0x8000] = {};
    char convertedText[0x1000] = {};
    wchar_t subject[0x100] = {};
    wchar_t body[0x1000] = {};
    wchar_t fieldText[0x1000] = {};

    const int subjectLength = static_cast<TextEditControlPane *>(
        GetControl(3))->ReadText(subject, 0xff);

    int bodyLength = 0;

    if (m_predefinedFormEntryCount != 0)
    {
        if (g_pUserPane->m_predefinedFormArticleFreeTextMode)
        {
            bodyLength = static_cast<TextEditControlPane *>(
                GetControl(4))->ReadText(body, 0xfff);
        }
        else
        {
            for (unsigned char row = 0;
                 row < m_predefinedFormEntryCount;
                 ++row)
            {
                const PredefinedFormArticleEntry& entry =
                    m_predefinedFormEntries[row];

                const int labelLength =
                    static_cast<TextEditControlPane *>(
                        GetControl(4 + row * 2))->
                            ReadText(fieldText, 0xfff);
                memmove(body + bodyLength, fieldText,
                    labelLength * sizeof(wchar_t));
                bodyLength += labelLength;

                if (!entry.usesUserImagePane)
                {
                    body[bodyLength++] = L' ';
                }

                const int valueLength =
                    static_cast<TextEditControlPane *>(
                        GetControl(5 + row * 2))->
                            ReadText(fieldText, 0xfff);
                memmove(body + bodyLength, fieldText,
                    valueLength * sizeof(wchar_t));
                bodyLength += valueLength;

                if (entry.rowAdvanceMode == 0)
                {
                    body[bodyLength++] = L' ';
                }
                else if (entry.rowAdvanceMode == 1)
                {
                    body[bodyLength++] = L'\r';
                }
            }
        }
    }

    body[bodyLength] = L'\0';

    PacketBufferWriteUInt8(0x3b, packet);
    PacketBufferWriteUInt8(0x04, packet + 1);
    PacketBufferWriteUInt16BE(boardId, packet + 2);

    const int subjectByteLength = WideCharToMultiByte(
        CP_ACP, 0, subject, subjectLength,
        convertedText, 0x100, NULL, NULL);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(subjectByteLength),
        packet + 4);
    memmove(packet + 5, convertedText, subjectByteLength);

    const int bodyByteLength = WideCharToMultiByte(
        CP_ACP, 0, body, bodyLength,
        convertedText, sizeof(convertedText), NULL, NULL);

    char *bodyLengthField = packet + 5 + subjectByteLength;
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(bodyByteLength),
        bodyLengthField);
    memmove(bodyLengthField + 2, convertedText, bodyByteLength);

    const int packetLength =
        subjectByteLength + bodyByteLength + 7;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    TimerHandler::ScheduleTimer(0, 15000, 0, 0);
}
```

The fixed arrays and bounded conversion/read calls should retain the original compiler's security/range behavior; final source must not spell `__report_rangecheckfailure`, vtable stores, deleting-destructor flags, or decompiler receiver adjustments. The code uses human names where symbols are lost while preserving packet bytes, control IDs, geometry, resources, timer arguments, and side-effect order.

## Final Recommendation

- Source, metadata, rename, split, history, and support changes enumerated in Sections 24-26 are applied and scoped-validated under the accepted Gate 1 callback.
- Keep UID0000LT and UID000098 as the file/class route.
- Ten exact source bodies and one complete H are populated and physically present in command `23592` output.
- UID0000ZL and UID0000UE are non-emitting/non-reconstructable indexes.
- Preserve UID0000ZQ/UID0000ZS as compiler-only no-code pages.
- The exact non-emitting vtable data child exists and is linked from UID0001X4.
- Preserve the IDA handoff in Section 21 as accepted historical prestate/action/protection evidence; the dated receipt records exact applied/no-change closure and post-save readback.
- No unresolved ordinary source, IDA, or manual-coverage blocker remains. Generated CPP/H refresh, Gate 2B, physical readback, and coverage validation are complete; later compilation/testing remains outside this B-agent callback.

## Recommended Target Doc Changes

- Target: `by-file/NewPredefinedFormArticleDialog.md`.
- The stale constructor no-code, `HandleEvent`, `int OnPaint`, and blank retained-helper conclusions were replaced with the current whole-file decisions.
- The exhaustive inventory, exact ten gaps, vtable/RTTI band, class/row layouts, dependencies/resources/imports, historical generated CPP/H defects, source order, and exact formal-source routing are present.
- `COMPLETION:94` and `CONFIDENCE:94` are current; owner `FILE` and path `NexusTK/ui/dialogs/` are retained.
- Preserve historical assumptions in a clearly marked superseded section rather than deleting them.

## Recommended Support Doc Changes

| Support path | Accepted and applied change |
| --- | --- |
| `by-class/NewPredefinedFormArticleDialog.md` | Set `94/94`; add complete H/CPP preamble, inheritance/layout/vtable facts, ten-body inventory, and stale-assumption corrections. |
| `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md` | Set `94/94`, `RECONSTRUCTABLE:FALSE`, blank emitter; retain as exhaustive physical index. |
| UID0002UJ constructor page | Set `93/94`; add exact constructor CPP, caller, controls, layouts, and resolved blockers. |
| UID0002EK page | Set `92/93`; preserve no-xref fact while keeping retained helper source. |
| UID0002UK page | Set `93/93`; use unsigned board id. |
| UID0002UM page | Rename to `...OnTimer.md`; set `94/94`; replace title, interface, evidence, and CPP. |
| UID0002UN page | Set `93/94`; keep formal forwarder. |
| UID0002UO page | Set `93/94`; correct to `void OnPaint`. |
| UID0002UP page | Set `93/94`; add `__stdcall`, H-owned natural row layout, and source-order forward declaration. |
| UID0002UQ page | Set `92/93`; retain full-packet handler. |
| UID0002UR page | Rename to `...HandleTransferReplyPredefinedAlertPayload.md`; set `92/93`; add exact retained source and negative liveness history. |
| UID0002UL page | Set `93/94`; use unsigned board id and inherited timer call. |
| UID0000ZQ / UID0000ZS | Preserve score/metadata/no-code; add cross-link to completed H where useful. |
| `by-item/DeserializePredefinedFormArticleEntries_478650.md` | Set `92/94`, `RECONSTRUCTABLE:FALSE`, blank emitter/CPP/H; covered by UID0002UP. |
| `by-type/by-vtable/BoardArticleDialogVtableFamily.md` | Correct timer slot identity and link exact new vtable-data child. |
| new `by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md` | Non-emitting class-owned exact COL/vtable data child with 24/11/2 slots and compiler-generated disposition. |

## Score And Metadata Recommendation

The `Current` column below records the pre-callback state audited at Gate 1. Every ordinary `Recommended` value is now implemented; C31-C74 are supervisor-verified under the dated Gate 2B receipt, and C75 coverage is supervisor-applied and validated.

| UID | Current | Recommended | Owner / emitter / reconstructable |
| --- | --- | --- | --- |
| 0000LT | `88/85` | `94/94` | Keep `FILE`; path unchanged. |
| 000098 | `86/87` | `94/94` | Keep owner/emitter 0000LT; TRUE; populate CPP/H. |
| 0000ZL | `85/90` | `94/94` | Keep contextual owner 0000LT; change FALSE; clear emitter; blank code. |
| 0000UE | `90/92` | `92/94` | Keep contextual owner 0000LT; change FALSE; clear emitter; blank code. |
| 0002UJ | `88/91` | `93/94` | Keep owner/emitter 000098; TRUE; populate CPP. |
| 0002EK | `88/91` | `92/93` | Keep owner/emitter 000098; TRUE. |
| 0002UK | `90/91` | `93/93` | Keep owner/emitter 000098; TRUE. |
| 0002UM | `90/92` | `94/94` | Keep owner/emitter 000098; TRUE; rename page; replace CPP. |
| 0002UN | `90/92` | `93/94` | Keep owner/emitter 000098; TRUE. |
| 0002UO | `90/92` | `93/94` | Keep owner/emitter 000098; TRUE; replace CPP. |
| 0002UP | `90/92` | `93/94` | Keep owner/emitter 0000LT; TRUE; replace CPP. |
| 0002UQ | `90/91` | `92/93` | Keep owner/emitter 000098; TRUE. |
| 0002UR | `87/92` | `92/93` | Keep owner/emitter 000098; TRUE; rename page; populate CPP. |
| 0002UL | `90/91` | `93/94` | Keep owner/emitter 000098; TRUE; replace CPP. |
| 0000ZQ | `85/93` | unchanged | NONE / none / FALSE. |
| 0000ZS | `85/92` | unchanged | NONE / none / FALSE. |
| 0001X4 | `85/91` | `88/93` | Keep owner/emitter 0000HT; TRUE; marker/no raw table source. |
| new vtable child | absent | `94/95` | Owner 000098; FALSE; no emitter; blank code. |

Reason not higher: original private helper/member spelling, exact original source filename history, visibility of the inherited control-state field, and some include spelling remain inferred. Those are lexical/source-shape confidence caps, not behavior, ownership, layout, or source-eligibility blockers. Reason not lower: the current binary closes the complete code/data/type inventory and supports exact formal behavior for every source-authored item.

## Open Questions With Attempted Resolution

- Was the original unit named exactly `NewPredefinedFormArticleDialog.cpp`? Current route and class specialization make this the strongest source-facing name; broader `ArticleDialogs.cpp` is weaker and rejected. This lexical uncertainty caps confidence only.
- Is `m_reservedControlState` the original field spelling? The direct byte store and project ControlPane convention support it. The accepted callback retained this strongest current spelling, command `23592` reproduces it exactly, and no unresolved callback substitution remains. Leaving a raw offset is rejected.
- Is the final geometry method spelled `SetBounds`? Its complete role and arguments are proven; `SetBounds(bounds,false)` is the strongest human-source inference. Raw `sub_544BD0` is rejected.
- Were the retained private helper names exactly as proposed? No original symbols survive, but subsystem analogs and payload shapes support the selected names with high probability. Raw labels or omission are worse.
- Should the parser use `__stdcall` in source? The current callee-cleanup convention and IDA prototype make it necessary for faithful binary behavior; generic cdecl is rejected.
- Should the retained payload helper be omitted because it has no caller? No. The exact source-shaped structural twin and non-ABI behavior support retained dead source. The no-xref fact remains documented.
- Should the constructor remain blank until every control constructor parameter name is original? No. Exact positional semantics and helper identities are known, and plausible human names are required where original lexical proof is lost.
- No unresolved question prevents CPP/H insertion or score movement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual rows were physically reread before application. The supervisor applied the exact C75 text below and validated the five coverage files under commands `23703`-`23707`; B004 did not edit any coverage report. The replacement text remains here as historical implemented evidence.

File coverage replacement:

`- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) : reconstructable : 94% : very-strong : Complete predefined-form article dialog compilation unit with ten source-authored bodies, exact CPP/H class and row declarations, packet/resource/control behavior, exact vtable/RTTI and padding inventory, retained-helper liveness evidence, compiler-only destructor companions, and corrected OnTimer/void-OnPaint source contracts.`

Class coverage replacement:

`- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md) : reconstructable : 94% : very-strong : Source-complete BulletinDialog-derived predefined-form article composer with exact 0x5368 layout, 0x40c row type, constructor, command/timer/hover/paint/reply/submit overrides and helpers, separate CPP/H emission, exact three-view vtable/RTTI evidence, and compiler-generated destructor glue excluded from handwritten source.`

Memory coverage replacements:

`    - [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md) 0x004777a0-0x00478f8e | non-emitting physical cluster index | NewPredefinedFormArticleDialog : not_reconstructable : 94% : very-strong : Exhaustive index of ten exact source children and ten CC alignment gaps; source emits only from exact children through class UID000098, so the aggregate is intentionally blank and non-emitting.`

`      - [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md) 0x004777a0-0x004781e5 | constructor | NewPredefinedFormArticleDialogConstructor : reconstructable : 93% : very-strong : Source-ready BulletinDialog-derived constructor with exact caller arguments, 0x5368 layout, form parser, current/legacy controls and geometry, count/row-array fields, final bounds, pending control, hover control, and formal CPP.`

`      - [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md) 0x004781f0-0x00478238 | retained private navigation helper | NewPredefinedFormArticleDialogRawNavigateSelectionHelper : reconstructable : 92% : very-strong : Exact retained previous-dialog/list-selection navigation body with shared request helper, current/legacy offset, clean padding, formal CPP, and preserved zero-xref evidence.`

`      - [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) 0x00478240-0x004782a2 | virtual command handler | NewPredefinedFormArticleDialogHandleButtonClick : reconstructable : 93% : very-strong : Source-ready OnCommand override for unsigned-board-id submit command 0 and cancel command 1, with active dialog host and screen dimmer side effects.`

`      - [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md) 0x004782b0-0x00478363 | TimerHandler override | NewPredefinedFormArticleDialogOnTimer : reconstructable : 94% : very-strong : Tertiary-vtable-proven OnTimer callback for timer id 0, screen-dimmer release, fixed transfer-error alert construction, and unconditional true return; historical generic HandleEvent identity is superseded.`

`      - [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md) 0x00478370-0x00478379 | hover forwarder | NewPredefinedFormArticleDialogSetHoverControl : reconstructable : 93% : very-strong : Exact nine-byte primary-vtable SetHoverControl override forwarding to DialogPane with formal CPP.`

`      - [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md) 0x00478380-0x0047864c | virtual paint handler | NewPredefinedFormArticleDialogOnPaint : reconstructable : 93% : very-strong : Source-ready void OnPaint override drawing exact DLGBBS08 EPF/PAL or EPD/NPAL8 header, variable rows, and footer; historical int return is superseded.`

`      - [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) 0x00478650-0x00478933 | file-local parser helper | DeserializePredefinedFormArticleEntries : reconstructable : 93% : very-strong : Exact __stdcall parser for naturally padded 0x40c PredefinedFormArticleEntry rows, ANSI/wide conversion, empty marker, row advance, count outputs, two constructor callers, and formal CPP/H route.`

`      - [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md) 0x00478940-0x00478a93 | virtual transfer-reply handler | NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert : reconstructable : 92% : very-strong : Primary-vtable full-packet handler for subcommand 0x06, reply mode, bounded ANSI/wide message conversion, dimmer release, and predefined alert construction.`

`      - [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md) 0x00478aa0-0x00478bd9 | retained payload-layout helper | NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload : reconstructable : 92% : very-strong : Source-ready retained payload helper structurally matching NewArticleDialog, with mode/length/text layout, dimmer release, conversion, alert construction, clean padding, and preserved zero-inbound-xref evidence.`

`      - [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md) 0x00478be0-0x00478f8e | submit helper | NewPredefinedFormArticleDialogSubmitArticle : reconstructable : 93% : very-strong : Source-ready opcode 0x3b subcommand 4 serializer using unsigned board id, subject and free-text/row body controls, ANSI conversion, packet send, and inherited TimerHandler schedule id 0 for 15000 ms.`

The existing UID0000ZQ and UID0000ZS rows remain textually adequate after support cross-links and need no score replacement.

By-item replacement:

`- [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md) : not_reconstructable : 92% : very-strong : Non-emitting search alias covered exactly by source child UID0002UP; the parser definition emits once through NewPredefinedFormArticleDialog.cpp and the naturally padded row declaration lives in the class H.`

Vtable-family replacement:

`- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) : reconstructable : 88% : very-strong : Broad board/article vtable inventory now linked to exact NewPredefinedFormArticleDialog three-view data band 0x0061404c-0x006140ec, including primary command/paint/hover/reply slots, EventHandler view, TimerHandler OnTimer slot, compiler destructor adjustors, RTTI hierarchy, and existing exact BulletinDialog/BoardListDialog children; remaining unrelated family tables still need exact children.`

New vtable-child insertion after the UID0000ZL cluster row:

`    - [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md) 0x0061404c-0x006140ec | compiler vtable/RTTI locator data | NewPredefinedFormArticleDialogVtableData : not_reconstructable : 94% : very-strong : Exact 0xa0-byte three-view vtable band with primary/EventHandler/TimerHandler COLs, 24/11/2 slots, constructor stores, source-method routes, destructor adjustors, next-class boundary, and no handwritten raw-table source.`

## Follow-Up Actions

- Historical pre-implementation Gate 1 passed for SHA256 `0EB23585196E6EB57FEB076FD90286EFB406207B43CFFBA570B71CA3CFC8EB6A`; the accepted ordinary implementation callback is complete, and that receipt does not represent the current reconciled artifact's Gate 1 decision.
- B004 implemented and scoped-validated C01-C30 and C76-C81 across the accepted target/support paths without editing coverage/generated/audit/tracker files or IDA.
- Supervisor Gate 2B completed under canonical session `supervisor-uid0000KZ-gate2b-20260814`: I02/I04-I11 and I22-I31 are `APPLIED_VERIFIED`; I01/I03/I12-I21/I32-I44 are `NO_CHANGE_VERIFIED`; save and post-save readback passed.
- Supervisor C75 coverage application completed, including UID00050Q, and commands `23703`-`23707` each returned `ok:1` for the five manual coverage files.
- Generated CPP/H refresh and physical readback completed under command `23592`; the recorded exact-block results remain the ordinary implementation receipt.
- No A-agent action is required.
- No new B-agent research target is required for this file unless Gate 1 identifies a concrete omitted claim.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: `94/100`.
- Behavior/layout/ownership confidence: very strong.
- Remaining uncertainty: original lexical spellings and visibility/include details only. None justify raw IDA names, blank source, or score stagnation.

## Validator Results

- Historical receipt provenance: exact foreground commands, working directories, timestamps, result counters, and rename diagnostics below were recovered from `C:\Users\admin\.codex\sessions\2026\08\14\rollout-2026-08-14T11-23-21-01a000de-e102-7931-b1a1-03aab1630b35.jsonl`. Asynchronous generated-refresh completion and side-effect counters for commands `23554` through `23584` were cross-checked against `tools/validator_queue/generated_refresh_results/zz-generated-refresh-0000000<command>-*.result.json`. The commands ran from junction path `E:\NTK\GhidraBridge\source-3\project-documentation`; every validator result independently resolved root `C:\FastStorage\NTK_Sources\source-3\project-documentation`.
- Generated-refresh shorthand used in every applicable receipt: `GR75` means `completed`, scope `file-incremental`, generated-result exit `0`, empty `stderr`, `autogen_children_fallback_insert:9`, `autogen_children_marker_missing:72`, `autogen_emitter_has_no_code:75`, `autogen_incremental_scope:1`, and `autogen_registry_rebuild:1`; `GR74` is identical except `autogen_emitter_has_no_code:74`. These are project-wide generated warnings/maintenance counters, not target-specific validator errors. Each row records the remaining exact generated side effects after the semicolon.

| command_id / command_timestamp | Exact working directory | Exact single-line command | Exit code, ok count, warnings/errors, and direct effects | Generated-refresh state and relevant side effects |
| --- | --- | --- | --- | --- |
| `23554` / `2026-08-14T15:49:09-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md' --apply --queue-timeout 240` | Exit code `0`; bootstrap pass emitted no `ok` field. Exact searches of `C:\Users\admin\.codex\sessions\2026\08\14\rollout-2026-08-14T11-23-21-01a000de-e102-7931-b1a1-03aab1630b35.jsonl` and `tools/validator_queue/generated_refresh_results/zz-generated-refresh-000000023554-678cfa29c9dc.result.json` found no foreground `ok` count. It inserted UID00050Q, default/required metadata, CPP/H channels, memory metadata, link/index state, and the new UID path mapping. No foreground error was emitted. This bounded missing receipt field is superseded by command `23555`, which validated the same finalized path with `ok:1`. | `GR75`; `autogen_report_update:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`. |
| `23555` / `2026-08-14T15:50:17-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; finalized UID00050Q completion/confidence after registration. | `GR75`; `autogen_report_update:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`. |
| `23556` / `2026-08-14T15:50:19-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file by-type/by-vtable/BoardArticleDialogVtableFamily.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; completion/confidence updated and four UID links normalized. | `GR75`; `autogen_cpp_update:1`, `autogen_header_noop:1`, `generated_metadata_refresh:2`. |
| `23564` / `2026-08-14T15:57:42-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; constructor completion/confidence accepted. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23566` / `2026-08-14T15:58:44-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; command-handler completion/confidence accepted. | `GR74`; `autogen_cpp_update:1`, `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`. |
| `23567` / `2026-08-14T15:58:47-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; hover-forwarder completion/confidence accepted. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23568` / `2026-08-14T15:58:49-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; paint-method completion/confidence accepted. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23569` / `2026-08-14T16:00:37-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; parser completion/confidence accepted. | `GR74`; `autogen_cpp_update:1`, `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`. |
| `23570` / `2026-08-14T16:00:40-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; full-packet reply completion/confidence accepted. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23571` / `2026-08-14T16:00:42-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; submit-helper completion/confidence accepted. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23572` / `2026-08-14T16:01:42-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; registered UID0002UM path change from `...HandleEvent.md` to `...OnTimer.md`, updated nine reference-source paths and 32 UID links, and accepted completion/confidence. Rename-window diagnostics were exactly `missing_ref_target:25` plus project-global `missing_ref_uid:176`; the missing target was the simultaneously moved UID0002UR old path `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md` (10 rows printed, 15 suppressed). These were transient ordering diagnostics, not an `ok` failure. | `GR74`; `autogen_cpp_update:1`, `autogen_header_metadata_refresh:1`, `autogen_report_update:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`. |
| `23573` / `2026-08-14T16:01:46-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; registered UID0002UR path change from `...UnreferencedTransferReplyHelper.md` to `...HandleTransferReplyPredefinedAlertPayload.md`, updated five reference-source paths and 28 UID links, and accepted completion/confidence. The remaining foreground diagnostic was project-global `missing_ref_uid:176`; `missing_ref_target` was no longer emitted after this second path registration. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23574` / `2026-08-14T16:02:35-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-item/DeserializePredefinedFormArticleEntries_478650.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; parser-alias completion/confidence accepted. | `GR74`; `autogen_cpp_update:1`, `autogen_header_metadata_refresh:1`, `autogen_report_update:1`, `research_tracker_update:1`. |
| `23575` / `2026-08-14T16:02:38-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; adjustor-thunk disposition accepted without a score counter. | `GR74`; `generated_metadata_refresh:2`, `memory_auto_coverage_update:1`. |
| `23576` / `2026-08-14T16:02:40-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; scalar-deleting-destructor disposition accepted without a score counter. | `GR74`; `generated_metadata_refresh:3`. |
| `23578` / `2026-08-14T16:03:56-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-file/NewPredefinedFormArticleDialog.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; final post-rename file-root pass. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:3`. |
| `23579` / `2026-08-14T16:03:59-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-class/NewPredefinedFormArticleDialog.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; final post-rename class pass. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:3`. |
| `23580` / `2026-08-14T16:04:09-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; final post-rename aggregate pass. | `GR74`; `generated_metadata_refresh:3`. |
| `23581` / `2026-08-14T16:04:19-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground missing-target or target-specific error; final UID0002UM post-rename pass. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23582` / `2026-08-14T16:04:32-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground missing-target or target-specific error; final UID0002UR post-rename pass. | `GR74`; `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:4`. |
| `23584` / `2026-08-14T16:10:42-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md' --apply --queue-timeout 240` | Exit `0`; `ok:1`; no foreground warning/error; final navigation exact-form repair accepted. | `GR74`; `autogen_cpp_update:1`, `autogen_header_metadata_refresh:1`, `generated_metadata_refresh:2`, `memory_auto_coverage_update:1`. |
| `23592` / `2026-08-14T16:39:03-04:00` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file by-file\NewPredefinedFormArticleDialog.md --apply --wait-generated --queue-timeout 240` | Exit `0`; `ok:1`; no target-specific error; `generated_refresh:completed`. Project-wide generated diagnostics were `autogen_children_fallback_insert:9`, `autogen_children_marker_missing:72`, and `autogen_emitter_has_no_code:74`. | Foreground coherent refresh completed: `autogen_header_metadata_refresh:121`, `autogen_header_noop:148`, `autogen_registry_rebuild:1`, `generated_metadata_refresh:278`, `projected_stats_update:1`, and `stats_incremental_noop:1`; CPP and H were regenerated and then physically reread below. |

- Commands `23581` and `23582` supersede the bounded two-path rename-window diagnostics from `23572` and `23573`: both final target passes returned `exit 0`, `ok:1`, and no missing-target diagnostic. Command `23592` then coherently refreshed validator-owned registry/reference state, projected stats, generated metadata, CPP, and H from the final paths.
- Physical CPP readback: `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`, SHA256 `EAC93FC4004254399CD44F6A8C6D6452F690536A0B537268D97A83B67341F3AE`, `17574` bytes, `532` physical lines, header command `23592` and timestamp `2026-08-14T16:39:03-04:00`. Exact substring comparison passed for UID000098's CPP preamble and each of UID0002UJ/EK/UK/UM/UN/UO/UP/UQ/UR/UL's ten formal bodies; the file has one root marker plus ten child markers and no empty-emitter marker, `[[CHILDREN]]`, TODO, or placeholder.
- Physical H readback: `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.h`, SHA256 `882BCFB3EB4016BF1ABA37508C9525EEA822847F504DA3F758864E08AE90BDEC`, `1615` bytes, `50` physical lines, header command `23592` and timestamp `2026-08-14T16:39:03-04:00`. The complete `1194`-character UID000098 formal H block matches exactly, including `PredefinedFormArticleEntry`, direct `BulletinDialog` inheritance, constructor, five virtual declarations, two retained helpers, `SubmitArticle(unsigned short)`, two count fields, and the twenty-entry array.

Supervisor-owned C75 coverage validation receipts (foreground generated refresh was deferred for each):

| Coverage file | command_id / command_timestamp | Result | Documented diagnostics |
| --- | --- | --- | --- |
| `by-file/-coverage-report.md` | `23703` / `2026-08-14T20:12:02-04:00` | `ok:1`; exact Section 28 file row applied | Pre-existing `missing_ref_uid` warnings were reported; none was introduced by or specific to UID0000LT. |
| `by-class/-coverage-report.md` | `23704` / `2026-08-14T20:12:05-04:00` | `ok:1`; exact Section 28 class row applied | Pre-existing `missing_ref_uid` warnings were reported; none was introduced by or specific to UID0000LT. |
| `by-memory/-coverage-report.md` | `23705` / `2026-08-14T20:12:07-04:00` | `ok:1`; exact Section 28 memory rows applied | Pre-existing `missing_ref_uid` warnings were reported; none was introduced by or specific to UID0000LT. |
| `by-item/-coverage-report.md` | `23706` / `2026-08-14T20:12:18-04:00` | `ok:1`; exact Section 28 item row applied | Pre-existing `missing_ref_uid` warnings were reported; none was introduced by or specific to UID0000LT. |
| `by-type/by-vtable/-coverage-report.md` | `23707` / `2026-08-14T20:12:20-04:00` | `ok:1`; exact Section 28 vtable row applied | Pre-existing `missing_ref_uid` warnings were reported; none was introduced by or specific to UID0000LT. |

## Changed Files

- Created: `by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md` as validator-assigned [UID:00050Q].
- Modified: UID0000LT, UID000098, UID0000ZL, UID0002UJ/EK/UK/UN/UO/UP/UQ/UL, UID0000UE, UID0000ZQ, UID0000ZS, and UID0001X4 target/support pages, plus this same report.
- Renamed with UID preservation: UID0002UM to `by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md`; UID0002UR to `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md`.
- Formal source: UID000098 CPP/H and all ten exact source-child CPP channels match Section 22; aggregate, alias, vtable bytes, adjustors, scalar deleting destructor, and padding remain blank/no-code.
- IDA/MCP: B004 made no IDA change. Supervisor Gate 2B closed C31-C74 under the dated Section 21 receipt and saved/read back the canonical IDB.
- Generated/coverage/tracker/audit/catalog/lifecycle/goal/notes: B004 made no manual edit. Validator-owned generated CPP/H and metadata refresh side effects from command `23592` are recorded in Section 31; supervisor-owned C75 coverage edits and commands `23703`-`23707` are recorded there separately.

### Ordinary implementation artifact receipts

| Path / UID | Before SHA256 | After SHA256 |
| --- | --- | --- |
| `by-file/NewPredefinedFormArticleDialog.md` / 0000LT | `E9D201DE50109F0F81A29F376B8B074CB7371C628A11ED79EA430C28D51123F9` | `B5D2BD426D3FA2A05A262903F20557201762A70739A9DB8A1BA636E04BB69CAE` |
| `by-class/NewPredefinedFormArticleDialog.md` / 000098 | `D5C1948C602D560D58957853669CD3413C76F6F2174756ECB88736DCA276C14C` | `7B5999657D3320F213EF84AF6FA7CE6A8AC599286FABDB20A440FEB5C1308AE2` |
| `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md` / 0000ZL | `CF9D529850CA3F30104957EFBE4073FF7BCCD410518E438965312D802755C371` | `C9DADE6F883B4D037DF6E143746DAF272F5CE792CACE2ED9C3BF9B59FE65BAC4` |
| `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md` / 0002UJ | `06AAF06FD83A2BC806D952C911C69D599C73B9B58AFCD4DF64FEEE116F11C9EE` | `DCAE4E1CC37BF2688C0D0781521041E3EDFA9FFA7874F0E79CBD6436D17C987D` |
| `by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md` / 0002EK | `AA3556ED3FBDCCAB132E9F732406C1F917A50E608AA88CA07E2C3BF499A8D4F4` | `AA90EFBAB8B1641509AEC081274C03B85EC6AE0A265B8CDA40040CAE7DEF881E` |
| `by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md` / 0002UK | `E1D3E29807646F92954AA276827EEFDACB2728ECC4AA18FFB18CADC331EAEEA4` | `BE75CF10E2166399CA2DEC752539B6720E9CE1E61A280BA46A92962C25C0EBDB` |
| UID0002UM, old `...HandleEvent.md`, new `...OnTimer.md` | `A0F4A82D87549B075F9111C2DF4E9FBA8D002C18F86CA8B69AD76931E22B9B72` | `483AE8B75732CF0FB208AD4C763D8BD87B4AFCF7BC3848FCBA4B972AA7EAA72A` |
| `by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md` / 0002UN | `0EEE7A3476D360B25412F59CD4913ABD0DF99CBB0D25372713356B2298531046` | `AA48788914D63D161D051396769888751AF373F3284C52C8D429AB366BB3C41C` |
| `by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md` / 0002UO | `FA7D648F8FD8562711DD2EB117E0A1C8F9D902F865054565ECC5CA99733C19DC` | `FB1112F5111BBCB1DE9B794F14630053023A013B8DFA6DE8E0474B64034EF2C3` |
| `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md` / 0002UP | `9A9CA8662A5AB7A8190D47D946509C96D031A01470D02475F462C8EFCE0B0936` | `032A7D6FA7229C11A3A46D9EA5F3CE1DF95D046CD4A575B40349537C2B95C561` |
| `by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md` / 0002UQ | `3FF7904EBCFA841A287B007690F608ABC6D92F473B275EC7410016F3AA93546B` | `199C6E3EC711E299D506413589438CD0889D1E00E381C99571B5BB6713C39A4F` |
| UID0002UR, old `...UnreferencedTransferReplyHelper.md`, new `...HandleTransferReplyPredefinedAlertPayload.md` | `C6A7B7A39044046DB4E9AE50CBC61E3DF5EFF0932C59CAD5FEB3899F58554CBC` | `F6648F7E9DF94FCB6E0684D9C548355C41FFE7B7507BBCADE164048DED058F35` |
| `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md` / 0002UL | `FE167785FB6C1DA669B4ED11C1ABF231B3005C42E222A4918F8583BE879920BC` | `E0FC0F59290073E7DCEC0EE4C19D4FEBA7F02F5B9248739BBCBB9F1F10048428` |
| `by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md` / 0000ZQ | `97B08C827BBAB25D3161B2D82AA33AE79BD5365D1A77D82C72EF8C35F526B102` | `0C3B67F09260D108F0CB9C9D8C6F0682A2F7F2F057681DA9F64B8C729F5E3643` |
| `by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md` / 0000ZS | `6C6158E2E8BCAB06FDDFB3AB16D990623E7947167BFDF011BFF67C1E4B3F4310` | `2A2125BA630C4984495F69A2F80BB53DFE5404C3C3A9647988BC7562EB531318` |
| `by-item/DeserializePredefinedFormArticleEntries_478650.md` / 0000UE | `675C28B5B56510059664121B30A594EF206EE8A199C81AC50E7034278F27E36F` | `9E40E0B8B688C9E7D731B2BF231B9BD84B4D672AC88B090A0B52CA3B2ADD1022` |
| `by-type/by-vtable/BoardArticleDialogVtableFamily.md` / 0001X4 | `A8FB2D153D038B3E46AA7B19D3F1074C5E3ABFAC68AE79B03C48B77DB6093362` | `D10E31BD00DD54E75E69A750791C2E38545878AFE554921F195C4910557DE792` |
| `by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md` / 00050Q | absent | `6C60C00AFB3A6D23ED3B059348164FCB7DAF9A3BFE9D1250A5873911158B77F5` |

- Report execution/archive state is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

The following rows mirror Section 11 exactly. All C01-C81 rows are checked after ordinary implementation, supervisor Gate 2B closure, and C75 coverage validation; their verification states preserve the distinction between applied changes and verified no-change protections.

All IDA/MCP prestate evidence in these rows is the same dated 2026-08-14 non-authoritative snapshot described in Section 21. The supervisor establishes fresh mutable-state authority independently at Gate 2B.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0000LT | UID0000LT is the unique NewPredefinedFormArticleDialog CPP/H compilation-unit root under NexusTK/ui/dialogs. | High | File route, contiguous cluster, class emitter, generated path, and subsystem placement | UID0000LT status, inventory, placement, and source contract | incorporate | applied |
| [x] | C02 | 0000LT | The whole file contains exactly ten source-authored code bodies in the main cluster. | High | Nine modeled functions plus exact raw navigation body and complete gap scan | UID0000LT exhaustive function inventory | incorporate | applied |
| [x] | C03 | 0000LT | The two adjustor thunks and scalar deleting destructor are compiler ABI products with no handwritten CPP bodies. | High | Vtable-only refs, this adjustments, deleting flags, and base cleanup | UID0000LT compiler inventory and UID0000ZQ/0000ZS | incorporate | applied |
| [x] | C04 | 0000LT | Ten exact internal CC alignment gaps account for every byte between the source bodies. | High | Dated 2026-08-14 byte snapshots for all ten half-open gaps | UID0000LT range and padding ledger | incorporate | applied |
| [x] | C05 | 0002UJ | The constructor is source-ready with BulletinDialog base, four arguments, two layout branches, controls, parser, and exact 0x5368 layout. | High | Full decompile, caller, allocation, helper prototypes, RTTI, and field offsets | UID0002UJ formal CPP and evidence | incorporate | applied |
| [x] | C06 | 0002EK | The raw navigation body is a private retained source helper and should emit NavigateToPreviousArticleSelection. | High | Exact code, previous-dialog/list control flow, shared navigation helper, and padding | UID0002EK formal CPP and metadata | incorporate | applied |
| [x] | C07 | 0002UK | The command override submits command 0 with unsigned board id and cancels command 1. | High | Primary vtable slot, submit call, session field, dimmer, and pop route | UID0002UK formal CPP and evidence | incorporate | applied |
| [x] | C08 | 0002UM | Address 0x4782b0 is TimerHandler OnTimer, not HandleEvent. | High | Tertiary vtable slot, +0xa4 facet, TimerHandler contract, and ScheduleTimer pair | UID0002UM rename, formal CPP, and historical correction | incorporate | applied |
| [x] | C09 | 0002UN | The nine-byte hover body is the normal SetHoverControl override forwarding to DialogPane. | High | Primary vtable slot and sole inherited tail-call | UID0002UN formal CPP and evidence | incorporate | applied |
| [x] | C10 | 0002UO | OnPaint returns void and draws exact EPF or legacy header, row, and footer sequences. | High | Dated 2026-08-14 void-prototype snapshot, inherited contract, resources, loops, and geometry | UID0002UO formal CPP and historical correction | incorporate | applied |
| [x] | C11 | 0002UP | The file-local parser is __stdcall, uses a naturally padded 0x40c row type, and precedes constructor use through a forward declaration. | High | retn convention, two ctor callers, field writes, and natural MSVC layout | UID0002UP formal CPP and UID000098 H/CPP preamble | incorporate | applied |
| [x] | C12 | 0002UQ | The live virtual packet handler accepts subcommand 0x06 and constructs TransferReplyPredefinedAlert from packet+2. | High | Primary vtable slot, packet bytes, conversion, dimmer, and alert stores | UID0002UQ formal CPP and evidence | incorporate | applied |
| [x] | C13 | 0002UR | The no-xref 0x478aa0 body is a retained source payload helper, not compiler glue or blank code. | High | Exact structural twin, same size/callees, payload offsets, and clean boundaries | UID0002UR rename, formal CPP, and liveness history | incorporate | applied |
| [x] | C14 | 0002UL | SubmitArticle takes unsigned short boardId and schedules TimerHandler timer 0 for 15000 ms after send. | High | Packet writer width, session field, exact TimerHandler callee, and call arguments | UID0002UL formal CPP and correction | incorporate | applied |
| [x] | C15 | 000098 | PredefinedFormArticleEntry has seven human-source fields and natural padding to size 0x40c. | High | Exact offsets 0/2/202/203/204/206/408 and MSVC alignment | UID000098 formal H and layout section | incorporate | applied |
| [x] | C16 | 000098 | NewPredefinedFormArticleDialog directly inherits BulletinDialog and owns the two counts plus twenty-entry row array. | High | Nine-base RTTI, base order, object allocation, and parser/consumer offsets | UID000098 formal H and class layout | incorporate | applied |
| [x] | C17 | 0001X4 | The exact vtable/COL band is 0x61404c-0x6140ec and needs one non-emitting by-memory child. | High | Exact bytes, three COLs, 24/11/2 slots, constructor stores, and next boundary | UID0001X4 and new vtable-data child | incorporate | applied |
| [x] | C18 | 000098 | RTTI proves BulletinDialog direct source inheritance and EventHandler/TimerHandler secondary views at +0xa0/+0xa4. | High | Type descriptor, hierarchy, base array, PMDs, and COL offsets | UID000098 inheritance and vtable analysis | incorporate | applied |
| [x] | C19 | 0000LT | DLGBBS08.EPF/PAL and DLGBBS08.EPD/NPAL8.PAL are the exact current/legacy resource pairs. | High | Constructor/paint string and call evidence | UID0000LT resource inventory and UID0002UO | incorporate | applied |
| [x] | C20 | 0000LT | MultiByteToWideChar, WideCharToMultiByte, packet helpers, screen dimmer, EPF library, user pane, and packet sender are required dependencies. | High | Direct imports, callees, and global xrefs | UID0000LT dependency inventory and CPP include contract | incorporate | applied |
| [x] | C21 | 0002UJ | Caller 0x471c00 supplies prior subject, EPF/legacy bounds, form packet, and allocates exactly 0x5368 bytes. | High | Sole constructor caller and argument/data flow | UID0002UJ caller and construction contract | incorporate | applied |
| [x] | C22 | 0000LT | The pre-callback generated CPP/H was incomplete; command 23592 now emits the exact class preamble, ten source bodies, and complete H with no empty marker, placeholder, or ordering defect. | High | Pre-callback defect audit plus command 23592 physical CPP/H readback and exact formal-block comparison | UID0000LT generated-output audit | incorporate | applied |
| [x] | C23 | 000098 | The class should be 94/94, reconstructable, owned/emitted by UID0000LT, with formal CPP/H populated. | High | Complete inventory, header, source bodies, and emitter route | UID000098 metadata and formal blocks | incorporate | applied |
| [x] | C24 | 0000LT | The file should be 94/94 while retaining owner FILE and NexusTK/ui/dialogs path. | High | Whole-file completion with lexical uncertainty below 95 | UID0000LT metadata and score rationale | incorporate | applied |
| [x] | C25 | 0000ZL | The physical aggregate should become non-reconstructable and non-emitting because exact children own all source. | High | Complete child coverage and duplicate empty-marker proof | UID0000ZL metadata and no-code disposition | incorporate | applied |
| [x] | C26 | 0000UE | The parser by-item alias should become non-reconstructable and non-emitting, covered by UID0002UP. | High | Same address/body and duplicate generated marker | UID0000UE metadata and covered-by disposition | incorporate | applied |
| [x] | C27 | 0002UJ | Constructor score should rise to 93/94 with class owner/emitter retained and formal CPP populated. | High | Resolved prior blockers and exact source reconstruction | UID0002UJ metadata and score rationale | incorporate | applied |
| [x] | C28 | 0000LT | All source-bearing children should receive the exact per-page scores and formal CPP dispositions listed in Section 26. | High | Per-function evidence and under-95 source-quality cap | Affected by-memory metadata and formal blocks | incorporate | applied |
| [x] | C29 | 0000ZQ | UID0000ZQ and UID0000ZS should preserve their current ignored/non-emitting compiler dispositions. | High | ABI-only behavior and regeneration from class declaration | UID0000ZQ/0000ZS no-code history | incorporate | applied |
| [x] | C30 | 0001X4 | BoardArticleDialogVtableFamily should link the exact new child and correct 0x4782b0 to OnTimer. | High | Dated 2026-08-14 exact slot-map snapshot and stale family prose | UID0001X4 NewPredefined row and notes | incorporate | applied |
| [x] | C31 | 0002EK | I01 preserves the exact raw navigation range as unmodeled code with no function object, function name absent, prototype absent, frame absent, AR absent, AP absent, FR not applicable, and FP not applicable. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact 72-byte body, boundary, fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP readback, zero-xref set, and unchanged padding | Gate 2B I01 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C32 | 0002UJ | I02 recommends only the exact constructor function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I02 | incorporate | APPLIED_VERIFIED |
| [x] | C33 | 0002EK | I03 preserves the navigation range with no function object, function name absent, prototype absent, frame absent, AR absent, AP absent unless independently accepted I23 changes only AP, FR not applicable, and FP not applicable. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact raw range plus fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP readback with the accepted zero-xref set | Gate 2B I03 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C34 | 0002UK | I04 recommends only the exact OnCommand function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I04 | incorporate | APPLIED_VERIFIED |
| [x] | C35 | 0002UM | I05 recommends only the exact OnTimer function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I05 | incorporate | APPLIED_VERIFIED |
| [x] | C36 | 0002UN | I06 recommends only the exact SetHoverControl function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I06 | incorporate | APPLIED_VERIFIED |
| [x] | C37 | 0002UO | I07 recommends only the exact OnPaint function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I07 | incorporate | APPLIED_VERIFIED |
| [x] | C38 | 0002UP | I08 recommends only the exact parser function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I08 | incorporate | APPLIED_VERIFIED |
| [x] | C39 | 0002UQ | I09 recommends only the exact full-packet-handler function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I09 | incorporate | APPLIED_VERIFIED |
| [x] | C40 | 0002UR | I10 recommends only the exact retained-payload function-name change while preserving zero-xref evidence. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot, absent destination, and liveness evidence | Gate 2B I10 | incorporate | APPLIED_VERIFIED |
| [x] | C41 | 0002UL | I11 recommends only the exact SubmitArticle function-name change. Classification: `apply` through public `rename` with `pure:true`; fail closed on source-prestate mismatch, destination collision, or ambiguous readback. | High | Dated 2026-08-14 function/name/size snapshot and absent destination | Gate 2B I11 | incorporate | APPLIED_VERIFIED |
| [x] | C42 | 0002UJ | I12 protects the constructor prototype/frame and records a self-contained source candidate without authorizing an IDA type change. Classification: `no change recommended`; mutation endpoint `none`. | High | Dated 2026-08-14 signature snapshot, F01, absent local UDTs, and no deterministic frame proof | Gate 2B I12 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C43 | 0002EK | I13 protects no function object, function name absent, prototype absent, frame absent, AR absent, AP absent, FR not applicable, and FP not applicable while recording a source candidate without authorizing function creation, type/frame mutation, or comments; I23 remains the separate independent AP-only action. Classification: `no change recommended`; mutation endpoint `none`. | High | Fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP readback plus absent class UDT | Gate 2B I13 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C44 | 0002UK | I14 protects the snapshot OnCommand prototype/F03; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F03 | Gate 2B I14 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C45 | 0002UM | I15 protects OnTimer prototype/F04; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F04 | Gate 2B I15 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C46 | 0002UN | I16 protects SetHoverControl prototype/F05; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F05 | Gate 2B I16 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C47 | 0002UO | I17 protects OnPaint prototype/F06; deterministic frame-change proof was absent, so Gate 2B verified no change. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F06 | Gate 2B I17 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C48 | 0002UP | I18 protects parser prototype/F07 and the four-argument stdcall frame. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot, complete F07, and absent row UDT | Gate 2B I18 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C49 | 0002UQ | I19 protects full-packet handler prototype/F08, including snapshot `arg_4`. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F08 | Gate 2B I19 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C50 | 0002UR | I20 protects retained-payload prototype/F09, including snapshot `arg_4`. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F09 | Gate 2B I20 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C51 | 0002UL | I21 protects SubmitArticle prototype/F10 and the 2-byte argument row. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 signature snapshot and complete F10 | Gate 2B I21 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C52 | 0002UJ | I22 recommends only the exact constructor address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact role text | Gate 2B I22 | incorporate | APPLIED_VERIFIED |
| [x] | C53 | 0002EK | I23 recommends the exact navigation-helper AP independently of function creation while preserving no function object, function name absent, prototype absent, frame absent, AR absent, FR not applicable, and FP not applicable. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; AP is the only changed channel. | High | Fresh dated 2026-08-14 literal object/name/prototype/frame and AR/AP/FR/FP prestate, accepted zero-xref set, and exact retained-helper role | Gate 2B I23 | incorporate | APPLIED_VERIFIED |
| [x] | C54 | 0002UK | I24 recommends only the exact OnCommand address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact command role | Gate 2B I24 | incorporate | APPLIED_VERIFIED |
| [x] | C55 | 0002UM | I25 recommends only the exact OnTimer address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact timer role | Gate 2B I25 | incorporate | APPLIED_VERIFIED |
| [x] | C56 | 0002UN | I26 recommends only the exact SetHoverControl address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact forwarding role | Gate 2B I26 | incorporate | APPLIED_VERIFIED |
| [x] | C57 | 0002UO | I27 recommends only the exact OnPaint address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact paint role | Gate 2B I27 | incorporate | APPLIED_VERIFIED |
| [x] | C58 | 0002UP | I28 recommends only the exact parser address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact parser role | Gate 2B I28 | incorporate | APPLIED_VERIFIED |
| [x] | C59 | 0002UQ | I29 recommends only the exact full-packet address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact packet role | Gate 2B I29 | incorporate | APPLIED_VERIFIED |
| [x] | C60 | 0002UR | I30 recommends only the exact retained-payload address-repeatable comment and preserves the zero-xref caveat. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact retained role | Gate 2B I30 | incorporate | APPLIED_VERIFIED |
| [x] | C61 | 0002UL | I31 recommends only the exact SubmitArticle address-repeatable comment. Classification: `apply` through public `set_address_repeatable_comments` at the exact address; preserve address-regular and both function-comment channels. | High | Dated 2026-08-14 four-channel comment snapshot and exact packet/timer role | Gate 2B I31 | incorporate | APPLIED_VERIFIED |
| [x] | C62 | 0000ZQ | I32 independently protects the EventHandler-view adjustor identity/type/frame with AR absent, AP absent, FR absent, and FP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 name/range/prototype/F11, literal AR/AP/FR/FP, and accepted xref-set snapshot | Gate 2B I32 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C63 | 0000ZQ | I33 independently protects the TimerHandler-view adjustor identity/type/frame with AR absent, AP absent, FR absent, and FP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 name/range/prototype/F12, literal AR/AP/FR/FP, and accepted xref-set snapshot | Gate 2B I33 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C64 | 0000ZS | I34 independently protects the scalar deleting destructor identity/type/frame with AR absent, AP absent, FR absent, and FP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact dated 2026-08-14 name/range/prototype/F13, literal AR/AP/FR/FP, and accepted three-xref-set snapshot | Gate 2B I34 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C65 | 0000ZQ | I35 resolves the first adjustor comment as exact no-change. Classification: `no change recommended`; mutation endpoint `none`. | High | All comment channels absent and compiler-only role documented elsewhere | Gate 2B I35 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C66 | 0000ZQ | I36 resolves the second adjustor comment as exact no-change. Classification: `no change recommended`; mutation endpoint `none`. | High | All comment channels absent and compiler-only role documented elsewhere | Gate 2B I36 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C67 | 0000ZS | I37 resolves the deleting-destructor comment as exact no-change. Classification: `no change recommended`; mutation endpoint `none`. | High | All comment channels absent and compiler-only role documented elsewhere | Gate 2B I37 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C68 | 0001X4 | I38 independently protects the primary vtable item/name/type. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact item head/end/width/name/type | Gate 2B I38 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C69 | 0001X4 | I39 independently protects the EventHandler-view vtable item/name/type. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact item head/end/width/name/type | Gate 2B I39 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C70 | 0001X4 | I40 independently protects the TimerHandler-view vtable item/name/type. Classification: `no change recommended`; mutation endpoint `none`. | High | Exact item head/end/width/name/type | Gate 2B I40 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C71 | 0001X4 | I41 resolves the primary-vtable comment as exact no-change with AR absent and AP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Literal AR absent; literal AP absent | Gate 2B I41 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C72 | 0001X4 | I42 resolves the EventHandler-vtable comment as exact no-change with AR absent and AP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Literal AR absent; literal AP absent | Gate 2B I42 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C73 | 0001X4 | I43 resolves the TimerHandler-vtable comment as exact no-change with AR absent and AP absent. Classification: `no change recommended`; mutation endpoint `none`. | High | Literal AR absent; literal AP absent | Gate 2B I43 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C74 | 000098 | I44 preserves `PredefinedFormArticleEntry` absent and `NewPredefinedFormArticleDialog` absent as independent local-type states and prohibits dependent IDA type changes. Classification: `no change recommended`; mutation endpoint `none`. | High | Dated 2026-08-14 exact-name and wildcard searches returned zero matches for each named type, with exact Section 22 source layout | Gate 2B I44 | incorporate | NO_CHANGE_VERIFIED |
| [x] | C75 | 0000LT | The supervisor applied the exact Section 28 file, class, memory, item, and vtable coverage replacements and validated all five coverage files under commands 23703-23707. | High | Exact replacement text plus supervisor coverage validation receipts | Supervisor-owned manual coverage files | incorporate | applied |
| [x] | C76 | 0000LT | Matching archived method reports remain useful evidence but their constructor no-code, HandleEvent, int OnPaint, and blank retained-helper conclusions are superseded. | High | Independent dated 2026-08-14 MCP snapshot recheck and report comparison | UID0000LT historical assumptions and support docs | incorporate | applied |
| [x] | C77 | 0000LT | Wave2/Wave3 material is stale and supplies no current claim evidence. | High | Current skill rule and independent current evidence | UID0000LT evidence provenance | incorporate | applied |
| [x] | C78 | 0000LT | Every discovered source blocker has a current resolution; IDA type mutation is separately narrowed to proven safe no-change. | High | Exhaustive inventory, types, xrefs, callers, source comparison, and frame audit | UID0000LT open-questions resolution | incorporate | applied |
| [x] | C79 | 000098 | A real sibling H is required because the class layout and parser row type are shared by multiple CPP bodies. | High | Constructor/parser/submit field use, pre-callback H absence, and command 23592 exact generated-H readback | UID000098 formal H and UID0000LT generated contract | incorporate | applied |
| [x] | C80 | 0000LT | Parser declaration must precede constructor use while definitions retain address/source child order through the emitter graph. | High | Parser caller order and current child assembly order | UID000098 CPP preamble and emitter-order notes | incorporate | applied |
| [x] | C81 | 0000LT | No third-party import directive applies to this first-party dialog compilation unit. | High | All bodies, resources, imports, and ownership are NexusTK-local | UID0000LT source contract | incorporate | applied |

Implementation callback state:

- [x] Historical pre-implementation Gate 1 accepted the exact SHA256 recorded in Section 29 under Follow-Up Actions; that receipt does not represent the current report artifact's Gate 1 decision.
- [x] Ordinary claims C01-C30 and C76-C81 were implemented and scoped-validated.
- [x] Command `23592` coherently refreshed generated CPP/H; physical readback matched the class CPP preamble, all ten child bodies, and the complete H declaration exactly.
- [x] Supervisor-owned IDA claims C31-C74 are closed under the dated Gate 2B receipt: 19 `APPLIED_VERIFIED` and 25 `NO_CHANGE_VERIFIED`.
- [x] Supervisor-owned manual coverage claim C75 is applied and validated under commands `23703`-`23707`.
- [x] B004 manually edited no generated, coverage, tracker, audit, catalog, lifecycle, goal, or notes file.
- [x] Every B004 lease was released after the corresponding edit/validation.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000023722","destination_path":"executed-b-agent-research/B004/0000LT-NewPredefinedFormArticleDialog-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000LT-NewPredefinedFormArticleDialog-file-source-quality.md","timestamp":"2026-08-14T20:27:04-04:00","uid":"0000LT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
