** TARGET-REPORT-UID:0002XF **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002XF g_pChattingHandlePane Ownership / Split Research


## Finalized Report / Current Recommendation

- Applied target state: [UID:0002XF][0x0067ade0-0x0067ade4.g_pChattingHandlePane](../../../../by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md) is `92/94`, `CANONICAL_OWNER:0002XE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and `Nested:0`. It is exact loader-zeroed physical evidence, not a second source declaration.
- Final disposition: [UID:0002XE][g_pChattingHandlePane](../../../../by-global/g_pChattingHandlePane.md) is the semantic global and sole externally linked definition under [UID:0000I5][Chatting](../../../../by-file/Chatting.md), at source position `0`. [UID:00001V][ChattingHandlePane](../../../../by-class/ChattingHandlePane.md) is the complete class/header emitter at `92/94`, position `10`; helpers and methods emit at positions `20-70`.
- Completed callback: the direct `Pane` plus `Singleton<ChattingHandlePane>` class, retained compare/snapshot helpers, corrected constructor/ordinary destructor, address ordering, compiler-only cleanup distinctions, aggregate/file support, and bounded consumer contracts are applied without loss. Accepted OnMouseEvent/OnPaint behavior and unrelated Chatting union content are preserved. The exact thirteen-row manual coverage handoff remains supervisor-owned and unapplied by B002.
- Confidence: very strong for range, zero-fill, 15 references, physical/semantic split, direct-Singleton lowering, object layout, field meanings, source ordering, and compiler exclusions; strong for inferred private helper spellings and access labels.

## Supporting Research

- Fresh evidence pass used live NexusTK IDA MCP database `9b0396a3` through a new protocol session on 2026-07-21. The final bounded recheck at `2026-07-21T13:43:53-04:00` found one active worker PID `15732`; `server_health` was `ok`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis/Hex-Rays/string cache ready, and 2,067 cached strings. These are evidence-collection-time facts, not an assertion of indefinite session availability.
- Exact historical search terms were `UID0002XF`, `0x0067ade0`, `g_pChattingHandlePane`, `ChattingHandlePane`, `UID0002XE`, and `Singleton<ChattingHandlePane>`.
- Central executed root searched: `executed-b-agent-research/`. No direct exact UID0002XF report exists. Relevant reports opened as leads were B002 `0002XB-g_pChattingVarietySelectPane-source-quality.md`, B005 `0002X2-g_pChattingModifyHeightPane-source-quality.md`, B009 `0002FR-ChattingHandlePaneConstructor-empty-emitter-source-quality.md`, B003 `0002FT-ChattingHandlePaneOnMouseEvent-source-quality.md`, B014 `0002FU-ChattingHandlePaneOnPaint-source-quality.md`, B008 `0002FQ-ChattingHandlePaneRenderStateSnapshotHelperRaw-empty-emitter-source-quality.md`, B002 `0002FP-0002G9-chatting-ui-raw-helper-source-quality.md`, B005 `0002F5-0002FB-0002FI-0002FY-ChattingDestructorCluster-source-quality.md`, B005 `0000I5-Chatting-empty-emitter-family-source-quality.md`, B004 `0002EV-ChattingPaneOnPaint-source-quality.md`, B007 `0002F3-ChattingBackPaneUpdateVisibility-empty-emitter-source-quality.md`, B009 `0002RX-OpenInputPaneForCurrentSayMode-source-quality.md`, B005 `0001LD-0001LE-SelectObjectWithKeyboardPaneInputHandlers-source-quality.md`, B005 `0001LL-TargetObjectWithKeyboardPaneMouseEvent-source-quality.md`, B014 `000099-NewSayToUserMessageInputPane-source-quality.md`, B006 `000107-GetChatButtonAtPoint-source-quality.md`, and B011 `0002XH-g_pClanStatusPane-source-quality.md`.
- Legacy executed roots searched: `tools/leaser/Agents/Agent-B*/research/executed/`; no exact direct report or stronger current UID0002XF conclusion was found.
- Archived roots searched: `archived/` and agent-local archived report locations; no exact direct UID0002XF report was found.
- Active B001-B005 research roots searched: no loose report for this target. Final coordination read found B001 on UID0001PM, B003 on UID0001PK, B004 on UID0001PD, and B005 on UID00029O; none overlaps ChattingHandlePane. `tools/leaser/Agents/current_leases.md` showed only B002's report lease during writing and no ordinary target/support lease.
- Prior reports correctly established much of the family, but their blank/marker helper conclusions and explicit singleton writes were treated as historical leads. Current binary/source-shape evidence independently resolves those blockers.

## Target

- Target UID: `0002XF`.
- Target path: `by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`.
- Evidence-time supervisor classification before callback: exact four-byte singleton backing storage that was reconstructable only because the physical page carried a no-duplicate marker.
- Applied scores and parent state: `92/94`, semantic owner `0002XE`, reconstructable false, blank emitter/position/formal, `Nested:0`.

## Current Target State

- Evidence-time metadata incorrectly let the physical storage page participate as a reconstructable emitter even though [UID:0002XE] already emitted the semantic global. The callback corrected that state.
- The target now records all 15 xrefs, semantic parent `0002XE`, four live zero bytes, and loader-zeroed virtual-tail storage. The still-stale manual coverage `0xffffffff` row is preserved only as an external supervisor-owned replacement obligation.
- Exact target SHA-256 for the four live zero bytes is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Historical pre-callback generated snapshot command `000000015860`, SHA-256 `F4AE833BB3768B46F9723D9B3FA5AD63262CA6AE265A08FD5E620137B4A27B85`, 64,177 bytes / 1,910 lines contained the UID00001V/FP empty markers, FQ coverage marker, explicit publication/clear, and no direct Singleton declaration. Command `000000015823`/SHA `6A19435907DB81C1F83692A0F0DBB3A5BCEE20F3DF4A5F44FA898AB4BABFE660` is an earlier historical epoch.
- Final waited target refresh command `000000015889` at `2026-07-21T14:22:58-04:00` produced `auto-generated/NexusTK/social/Chatting.cpp` SHA-256 `2D4049A903F87FDA3E352AFC09F0A407DA0F9EB5133A5F247A40CD581B9BBE5A`, 66,151 bytes / 1,977 lines. It has one typed global definition at line 10; one complete class definition at line 59 plus its required forward declaration; one FP/FQ/constructor/destructor/OnMouseEvent/OnPaint definition at lines 94/109/122/146/151/309; direct Singleton inheritance; no explicit publication/clear; zero UID0002XF/UID00001V/UID0002FP/UID0002FQ Empty Emitter Markers; no FP/FQ coverage marker; and no handwritten scalar/forwarder/vtable/RTTI/EH source. The UID0003AT Empty Emitter Marker is a non-source comment for its accepted blank ABI destination, not handwritten ABI code.
- Final read-only tracker checkpoint is command `000000015910` at `2026-07-21T14:36:05-04:00`, SHA-256 `92770F71CFB52761179F96F8DD0A5807384C4E1A9A61BD1E94FD321CBE95DA08`, 1,547,661 bytes / 6,261 lines; UID0002XF appears once at line 3848 as `92/94`, score `93.0`, reconstructable false. Command `15890`/SHA `30BFF38DC472E26822F8C3C68A589158E66972973FEAAA14EE15AF53EA571B47`, command `15860`/SHA `55B45...AC7CA78`, and command `15836`/SHA `625778...0FC639` are historical. Generated/tracker checkpoints are time-bounded final-read observations and may be superseded by unrelated later validators without changing the accepted ordinary implementation.
- Current ordinary destination hashes and validators are recorded under `Changed Files` and `Validator Results`. Nineteen ordinary pages were changed under serial leases, and all leases were released.
- Current report state is implementation-callback complete with C01-C40 terminal, all 59 checklist rows checked, exact manual handoff preserved for supervisor action, and report lifecycle external.

## Executive Recommendation

- Separate physical and semantic identities exactly: UID0002XF is false/non-emitting loader storage; UID0002XE is the sole typed source definition.
- The class and method island is complete under [UID:0000I5][Chatting]: global position `0`, class/header `10`, compare helper `20`, snapshot helper `30`, constructor `40`, destructor `50`, OnMouseEvent `60`, and OnPaint `70`.
- Direct `Singleton<ChattingHandlePane>` inheritance is applied; compiler publication, clearing, adjusted-null arithmetic, vptrs, unwind cleanup, scalar delete, base teardown, and RTTI/vtables are excluded from authored source.
- Both retained private out-of-line render-state helpers emit behavior-identical source. Lack of xrefs is retained liveness evidence; each has one typed stack-pointer parameter, `ret 4`, exact paired 24-byte record semantics, and no compiler-glue signature.
- UID0002FV, UID0002GI compiler subranges, and UID0003AT ABI data remain free of handwritten ABI C++.

## Supervisor Active Recheck

- The supervisor assigned UID0002XF specifically to resolve physical storage versus semantic global, all 15 references, Singleton lowering, source/header one-definition policy, helper/body blockers, and exact coverage handoff.
- No split child creation is required: target, semantic global, class, helpers, constructor, destructor, methods, compiler glue, vtable data, mixed storage aggregate, and source file already have stable UIDs.
- Every source-bearing item directly needed for the recommendation has destination-ready source or a target-specific compiler/no-code disposition below. No blocker is deferred as independent future debt.

## Inference Research Guidance Check

- `by-structure.md` and current sibling singleton pages were used as routing rules, not binary authority. Physical linker storage does not become a second source definition merely because it has an address page.
- Existing assumptions treated as uncertain were `0xffffffff` initialization, reconstructable physical storage, explicit constructor/destructor global writes, marker-only raw helpers, generic/selector helper naming, implicit class shape, and scalar/vtable source authorship.
- Direct IDA facts, current documentation facts, and source-shape inference are labeled separately. Names `IsRenderStateCurrent`, `CaptureRenderState`, and `ChattingHandleRenderState` are high-probability descriptive source names, not recovered symbols.
- Historical Wave2/Wave3 mentions were found in older helper notes. They were ignored as stale except where current IDA independently reconfirmed the same address/range facts.

## Heuristic / Inference Reanalysis And Validation

- Storage value: live MCP returns zeros. PE section math proves the target lies `0x5e0` bytes beyond `.data` raw-backed end `0x0067a800`, within virtual `.data` ending `0x0069ce24`; no raw file payload exists for this slot. The stale `0xffffffff` claim is rejected.
- One-definition policy: the generated file already routes the semantic global through UID0002XE. The physical page must not retain reconstructable emitter semantics. Sibling UID0002X2/UID0002XB closures corroborate this, but current target evidence independently proves it.
- Direct Singleton: RTTI contains `Singleton<ChattingHandlePane>` and PMD `mdisp=+0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`. Constructor `lea this+0xf8` adjusted-null publication and ordinary/unwind/scalar clears are compiler lowering of the direct base.
- EBO/layout: the empty Singleton base and the first `ChattingHandleRenderState` member share `+0xf8`. The 24-byte record naturally contains bools at `+0/+1/+8`, ints at `+4/+0xc/+0x10/+0x14`, and implicit alignment only. No authored reserve array is justified.
- Access: runtime methods outside the class directly read `+0x111`, `+0x114`, and `+0x118`. Those three state members must be source-visible; treating all as private without friends/accessors would not compile the recovered direct accesses. Internal snapshot/mouse/latch/paint members remain private.
- Raw helper liveness: UID0002FP and UID0002FQ each have a complete prologue/body/epilogue and `ret 4`; neither has inbound xrefs, pointer tables, exports, relocations, or modeled function identity. Their exact paired record and receiver fields establish retained private member methods, not compiler glue and not an excuse for blank C++.
- Constructor: exact source is `Pane(1)` plus direct Singleton construction followed by field/config/scroll setup. Explicit source publication is rejected because the adjusted-null sequence occurs while constructing the Singleton subobject.
- Destructor: the human derived body is empty. Three vptr restores, global clear, and Pane tail teardown are compiler-generated destruction. Explicit clearing is rejected.
- Source order: global definition must precede class/method use, class and declarations must precede method definitions, and methods remain address ordered. The class closing brace precedes `[[CHILDREN]]`.
- File-local helper visibility: UID000107's accepted static definition is currently emitted after OnMouseEvent. Destination 3 therefore carries the exact matching static prototype before the class; this closes current same-translation-unit compile visibility without duplicating UID000107's body or changing its owner.
- Evidence-time enums lived inside UID0002FT's method emitter after the constructor even though the constructor named the normal state. The callback moved them to the class/header block and removed only those duplicate declarations from UID0002FT while preserving its method body byte-for-byte.
- Rejected alternatives: physical UID as a second definition; static/internal global linkage; explicit publication/clear; handwritten vptr/base/EH/scalar/vtable code; selector ownership for FP/FQ; marker-only FP/FQ; raw `sub_` names; explicit padding arrays; separate aggregate struct for the ten slots; ownership based solely on runtime consumers.

## Evidence Standards Used

- Primary evidence: fresh MCP `idb_list`, `server_health`, `get_bytes`, `xrefs_to`, decompile, disassembly, entity/RTTI queries, exact function/range inspection, and negative route searches.
- Binary corroboration: local PE headers/section math and SHA-256 against the same MCP-reported NexusTK input file. PE virtual-tail status is stronger than treating arbitrary file-offset bytes as the initializer.
- Structural evidence: constructor/destructor order, allocation size/caller, RTTI PMDs, EBO, member access offsets, vtable ownership, compiler wrapper shapes, adjacent children, generated ordering, current by-* docs, and accepted sibling patterns.
- Historical reports are corroboration only. Any conclusion used here was rechecked against the current IDB/current docs/current generated output.
- Confidence remains below 95 because original private-helper spellings and exact access labels are stripped, not because behavior, ownership, or source readiness is unresolved.

## Evidence Checked

- MCP checks: fresh session discovery/health; bytes at `0x0067ade0`, `0x00481b60`, `0x00481bc0`; 15 exact xrefs; decompiles/disassembly for all ten runtime reader functions; constructor/destructor/unwind/scalar ranges; RTTI/type descriptors/vtable data; caller/allocation at `0x004f8288`; raw helper boundaries and negative routes.
- PE checks: file SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, file length 2,679,296, `.data` RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, raw pointer `0x26ac00`, target in zero-filled virtual tail.
- Current docs checked: UID0002XF/XE/01V/2FP/2FQ/2FR/2FS/2FT/2FU/2FV/2GI/3AT/2B5/104/0I5, predecessor UID0002XB, successor UID0002XH, all ten runtime consumers, UID000107, and direct-Singleton sibling classes/globals.
- Reports/roots searched and outcomes are listed in `Supporting Research`; no direct report substitute exists.
- Generated/tracker/manual coverage and current B001-B005 goals/current leases were read immediately before report finalization.
- Negative checks: no export/import/relocation/pointer/VA/RVA/rel32 route to raw helpers, no aggregate-source identity, no raw-backed target initializer, no second semantic definition, no null guards at established-lifetime consumers, no evidence of authored ABI tables/wrappers.
- Failed/unavailable checks: none material. IDA does not model FP/FQ as functions, so raw bytes/disassembly/signature/record pairing were used; that tool limitation does not prevent source reconstruction.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0002XF is exactly `[0x0067ade0,0x0067ade4)`. | original-proof | MCP bytes, neighboring children | Destination 1 / target Boundary | incorporate | applied |
| C02 | Target live value is four zero bytes with SHA `DF3F...119`. | original-proof | MCP `get_bytes` | Destination 1 / target Evidence | incorporate | applied |
| C03 | Target is loader-zeroed `.data` virtual-tail storage, not raw `0xffffffff`. | original-proof | PE section math | Target/coverage/history | reject-stale | applied |
| C04 | Predecessor UID0002XB ends at `0x0067ade0`; successor UID0002XH begins at `0x0067ade4`. | original-proof | current pages/bytes | Target/UID0002B5 | incorporate | applied |
| C05 | Exactly 15 direct references exist. | original-proof | fresh `xrefs_to` | Target/Xref inventory | incorporate | applied |
| C06 | UID0002XF is physical evidence and must be false/non-emitting. | very-strong | one-definition/source routing | Destination 1 | incorporate | applied |
| C07 | UID0002XE is the sole typed external definition at position 0. | very-strong | generated/current sibling policy | Destination 2 | incorporate | applied |
| C08 | Global type is `ChattingHandlePane *` and zero initialization uses period-style `0`. | very-strong | all readers/constructor/generated style | Destination 2 | incorporate | applied |
| C09 | ChattingHandlePane directly inherits Pane and Singleton. | original-proof | RTTI/PMD/constructor | Destination 3 | incorporate | applied |
| C10 | Direct Singleton EBO begins at `+0xf8`. | original-proof | RTTI PMD/object stores | Destination 3/layout | incorporate | applied |
| C11 | Complete object size is `0x128`. | original-proof | sole allocation/caller | Class/constructor | incorporate | applied |
| C12 | Render-state record is 24 bytes with natural padding only. | original-proof | FP/FQ exact accesses | Destination 3 | incorporate | applied |
| C13 | Active fields are pending target `+0x111`, mode `+0x114`, secondary enabled `+0x118`. | very-strong | writers/readers/config | Class/support | incorporate | applied |
| C14 | External direct reads require source-visible active state fields. | strong inference | ten runtime consumers | Destination 3 | incorporate | applied |
| C15 | UID0002FP is a retained source member, not selector or compiler glue. | very-strong | exact thiscall body/record | Destination 4 | reject-stale | applied |
| C16 | UID0002FP returns true only for a valid six-field match. | original-proof | 89 bytes/SHA/disassembly | Destination 4 | incorporate | applied |
| C17 | UID0002FQ is a retained source member, not marker-only covered code. | very-strong | exact thiscall body/record | Destination 5 | reject-stale | applied |
| C18 | UID0002FQ sets valid then copies all six fields. | original-proof | 69 bytes/SHA/disassembly | Destination 5 | incorporate | applied |
| C19 | Constructor source uses direct Singleton base and omits explicit publication. | very-strong | adjusted-null lowering/RTTI | Destination 6 | reject-stale | applied |
| C20 | Constructor imports config, controls scroll widget, initializes latches/paint/snapshot. | original-proof | decompile/disassembly | Destination 6 | incorporate | applied |
| C21 | Ordinary derived destructor source body is empty. | very-strong | exact destructor/compiler order | Destination 7 | reject-stale | applied |
| C22 | Vptr restores, clear, Pane teardown are compiler-only. | original-proof | destructor/scalar/unwind | UID0002FS/2GI/3AT | incorporate | applied |
| C23 | UID0002FV is compiler secondary forwarder and remains false/non-emitting. | original-proof | 10-byte slot dispatch | Destination 10 | already-present | already-present |
| C24 | UID0002GI owns compiler cleanup/scalar evidence and remains false/non-emitting. | very-strong | exact glue ranges | Destination 11 | incorporate | applied |
| C25 | UID0003AT records direct Handle Singleton RTTI but emits no ABI source. | original-proof | RTTI/vtables | Destination 12 | incorporate | applied |
| C26 | OnMouseEvent body remains accepted; enum declarations move to class block. | very-strong | current formal/source order | Destination 8 | incorporate | applied |
| C27 | OnPaint remains accepted at position 70. | very-strong | current formal/binary | Destination 9 | already-present | applied |
| C28 | ChattingPane OnPaint reads `+0x118` without null check in current layout. | original-proof | `0x47f932` decompile | support prose | incorporate | already-present |
| C29 | ChattingBackPane uses `+0x114/+0x118` for alpha/mode visibility. | original-proof | `0x480740` decompile | support prose | incorporate | already-present |
| C30 | Modify-height mouse/paint methods gate on `+0x118`. | original-proof | `0x4808a0/0x480bc0` | support prose | incorporate | already-present |
| C31 | Line-input base key handler uses `+0x111` during cleanup. | original-proof | `0x4f266b` decompile | global/class prose | incorporate | applied |
| C32 | Map teardown null-checks the singleton before graph removal. | original-proof | `0x504994` decompile | UID0002QH prose | incorporate | applied |
| C33 | Current-say dispatcher gates on pending target `+0x111`. | original-proof | `0x5a514b` disassembly | global/class prose | incorporate | already-present |
| C34 | SelectObject/TargetObject/NewSayToUser consume `+0x111` for target cleanup. | original-proof | three decompiles | global/class prose | incorporate | applied |
| C35 | InitializeMainUiGraph allocates `0x128`, constructs once, places `(74,727,740,751)`. | original-proof | sole caller | constructor/class prose | incorporate | applied |
| C36 | UID0002B5/UID000104 remain aggregate indexes and emit no duplicate source. | very-strong | current split maps | aggregate prose | incorporate | applied |
| C37 | Chatting.cpp order is global 0, class/prototype 10, methods 20-70; the UID000107 prototype precedes OnMouseEvent. | strong inference | compiler visibility/address order | all managed destinations | incorporate | applied |
| C38 | Generated output must contain one global/class/helper/method set and no target empty marker/ABI source. | very-strong | current generated defect | validation plan | incorporate | applied |
| C39 | Manual coverage requires thirteen no-loss replacements across four roots. | original-proof | current rows/hashes | coverage handoff | incorporate | excluded-with-reason |
| C40 | Old marker/no-code and explicit global-write assumptions remain labeled historical. | very-strong | old reports/current binary | all affected docs | historicalize | applied |

Callback destination proof for the terminal states above:

- C01-C06 and C40: UID0002XF hash `BCEAC7AAECF45AF40B76CB90F91411612D5B73E60EA9513477AEE11AB9AB1BEE`, validator `000000015861` (`2026-07-21T14:01:42-04:00`, exit `0`, `ok:1`), contains exact range/zero-fill/15-ref evidence, false metadata, blank formal, and historicalized `0xffffffff`/marker wording.
- C07-C08: UID0002XE hash `BB4D8E496579A46C41911681A8A87B740CA7170299E96B931CFDE5DFA9254CA6`, validator `000000015862` (`2026-07-21T14:02:34-04:00`, exit `0`, `ok:1`), emits the sole typed `= 0` definition at position `0`.
- C09-C14 and C37: UID00001V hash `ACB588267DD59F3A8B386F9EB07DD06C555B2CE1AC9437F4B970B3042CBBDE7D`, validator `000000015863` (`2026-07-21T14:04:26-04:00`, exit `0`, `ok:1`), contains direct Pane/Singleton inheritance, exact natural layout/access, prototype, enums, methods, and class-before-children structure.
- C15-C16: UID0002FP hash `982ADDAD441F6C65D999868DA04EC3CD36A485A99CD7FD913151F4B89FBC439F`, validator `000000015864` (`2026-07-21T14:07:09-04:00`, exit `0`, `ok:1`), emits the exact valid-first six-field comparison at position `20`.
- C17-C18: UID0002FQ hash `E79FDC3E62D6C1BB8B3D3F52AA20343173844AC8491A4441C61792BE8B05081C`, validator `000000015865` (`2026-07-21T14:08:54-04:00`, exit `0`, `ok:1`), emits the exact valid-first six-field copy at position `30` and preserves marker-only history as superseded.
- C19-C20: UID0002FR hash `2A9953D4BE59777AB42C1CC018B5652E640EC7016F0B90C52E3BB3ACA4E4DCDA`, validator `000000015866` (`2026-07-21T14:10:20-04:00`, exit `0`, `ok:1`), emits direct-Singleton constructor source at position `40` without explicit publication.
- C21-C22: UID0002FS hash `6620559CCCD0CBE34044252ABE1A3932A327FCC6C7EFE13BC7C811B0DA94DD8A`, validator `000000015867` (`2026-07-21T14:11:21-04:00`, exit `0`, `ok:1`), emits the empty authored destructor at position `50`; UID0002GI/UID0003AT proofs below retain clear/base/scalar/vtable behavior as compiler output.
- C23: verify-only UID0002FV hash `67A5E0EB5628D9252F4B408A6A27CAB244383702BA11D9D22A9DF316C3452C24` retains `86/90`, false/no-owner/no-emitter, blank formal, and exact ten-byte secondary forwarder proof.
- C24: UID0002GI hash `283DB6B019BEA33AA49371E5026CDB6B7CDAC55ED04BE9307EF5AB460997B231`, validator `000000015870` (`2026-07-21T14:13:41-04:00`, exit `0`, `ok:1`), adds Handle unwind/scalar mapping while retaining `84/90` false/blank no-ABI state.
- C25: UID0003AT hash `AE78A185C5DF1A3F99ADA7B4A9320E7A137223D1CD81C7537AEBDBB666BBF0B1`, validator `000000015871` (`2026-07-21T14:14:39-04:00`, exit `0`, `ok:1`), records Handle primary/secondary/tertiary tables and direct-Singleton PMD while retaining blank ABI formal.
- C26: UID0002FT hash `099AEFC099D29A239865FB7045D9C029F5DE06C59069770D8768AE71E0F88444`, validator `000000015868` (`2026-07-21T14:12:03-04:00`, exit `0`, `ok:1`), preserves the complete method and moves only enums to the class block at position `60`.
- C27: UID0002FU hash `F0ED7A515565493E9D03FA25C37D5C63B7C6B73D640390CA4A8F9718AC00A99D`, validator `000000015869` (`2026-07-21T14:12:31-04:00`, exit `0`, `ok:1`), preserves the exact accepted body at position `70`.
- C28-C30 and C33: read-only same-or-greater consumer hashes are UID0002EV `6F5B8C29E14704DEC84642773DEADC8ED5B0F251A3E00CF9BFA6715D488B6D2E`, UID0002F3 `C24F0EEE7E0685848B1CB465114C64C4D6DFB0169FE134861AD9AD392A75C824`, UID0002F6 `E1B65E49938ADB210BBB5B3CDB1215C948E83487039865CAFE60346FFF03FB05`, UID0002F9 `03AE2EEBD474D8DC7969736E6D4D96F94A7BA2CB168F9170A13033A34B836F72`, and UID0002RX `15463F9BC9B380F96A181B905E749A730CCD3E3DB038AB09CA7628D97D8CF9A1`; each already contains its exact `+0x114/+0x118/+0x111` behavior and required null/no-null disposition.
- C31: UID00035Y hash `2319DF48CBBAC29C0F01BB45A226319E3125FA4AAB052C0FEB311449229FE221`, validator `000000015886` (`2026-07-21T14:21:25-04:00`, exit `0`, `ok:1`), adds the exact `0x004f266b` pending-target cleanup read without altering its existing body status.
- C32: UID0002QH hash `D449CADDFDA0A54B4575D9D39F2B94B5AB18C3E8996EF1BAA822E00DD2AD7EE5`, validator `000000015883` (`2026-07-21T14:18:43-04:00`, exit `0`, `ok:1`), records exact `0x00504994` null-checked graph removal and non-ownership.
- C34: UID0001LE hash `37B8D90EFE24F84C69FFBB45A6330CBB1622A1163BF21C065C3DC0B7799376FE`, validator `000000015887` (`2026-07-21T14:21:55-04:00`, exit `0`, `ok:1`), and UID0001LL hash `74124D7961CB5997A40D3E71656630761A2BCE9B757D3D74762C904384CC2EAA`, validator `000000015888` (`2026-07-21T14:22:19-04:00`, exit `0`, `ok:1`), replace unbacked `IsCommandPending()` calls with the exact public field read. NewSay remains same-or-greater at hash `313D6BDA1ECA2ACA25013D6DB31994D05CC5A7A630A3E84E28251C8ECC02F1E3`.
- C35: UID00019K hash `2F08BF1D488F7886F423246491D5C08907445B853B9C6F4139884F229FB6C9CD`, validator `000000015880` (`2026-07-21T14:17:55-04:00`, exit `0`, `ok:1`), records sole `0x128` allocation/construction/placement and direct-Singleton meaning.
- C36: UID0002B5 hash `9888265AFD9612AAA2CEAC7EA7F42D4E699230CB1AEC17D66C6290F9C0753464`, validator `000000015872`; UID000104 hash `82F79ED970867B6B8A7E66506CFD30A608CDC63B06D5AEC96A9BA4228DFDC5D5`, validator `000000015873`; and UID0000I5 hash `CF306B19B102987A3B6198B880F22E27E4E5559EE202BDBDFE371D09E1B48523`, validator `000000015874`, preserve non-emitting aggregate roles and the complete Chatting union while adding exact Handle closure.
- C38: lease-free waited validator `000000015889` (`2026-07-21T14:22:58-04:00`, exit `0`, `ok:1`) produced the generated hash/count/order/marker assertions recorded under Current Target State and Validator Results.
- C39: `excluded-with-reason` means B002 preserved and refreshed the exact thirteen literal replacements, but manual `-coverage-report.md` files are supervisor-owned and were not edited. Final-read hashes/anchors appear in the manual handoff section.

## Positive Evidence Summary

- Four live zeros, PE virtual-tail placement, exact predecessor/successor, and the independent semantic global prove the physical/non-emitting split.
- All 15 refs resolve into five compiler-lifetime sites and ten meaningful runtime reads; there are no unexplained references.
- RTTI names the direct Singleton specialization and its `+0xf8` PMD; constructor/destructor/scalar shapes match compiler lowering exactly.
- Raw helper instruction streams match the same 24-byte record and active fields used inline by OnMouseEvent/OnPaint. Their signatures are fully inferable despite no call route.
- Existing accepted sibling direct-Singleton pages and generated ordering corroborate, but do not substitute for, the target evidence.

## IDA MCP Facts

- Function/range facts: FP `0x00481b60-0x00481bb9`, 89 bytes, SHA `049D3A45175D9E61F5DF4E0EA079C7141693776DE45ECF238D532E380B91DAFD`; FQ `0x00481bc0-0x00481c05`, 69 bytes, SHA `2383E96AFEA172387C7F94559C6BE31DB51EF850E23285535F56EE7AEC2AA747`; constructor `0x00481c10-0x00481d2a`, 282 bytes, SHA `6218973366CB08F9B770A6F575DE3604C23799DB27619AC4292F01F6F0474005`; destructor `0x00481d30-0x00481d59`, 41 bytes, SHA `6ADE99AFAB255AD43A77BFEE256638C8998BFC77065014627F6F8FA0969FAFE9`.
- Method facts: OnMouseEvent `0x00481d60-0x0048214f`, 1,007 bytes, SHA `F4F9F2DFF743815588E42FAAFF0864F3279B591ACDE47AF66A3F0E378F04CEB1`; OnPaint `0x00482150-0x004822f6`, 422 bytes, SHA `F9B651406890644BAECF408D7063389DD28017BB0869C294170F22B3D4E1634A`.
- Compiler facts: forwarder `0x00482300-0x0048230a`, SHA `B84326BE49B27E28BFE460034B009BF9787976F75422D964A6ED9ABC0501E4E8`; clear helper `0x004839c0-0x004839cb`, SHA `9522583BF93440680B9666758D5A9FFD30A81E34547BC80F041957F39A05D52A`; scalar wrapper `0x00483ba0-0x00483bff`, SHA `CE3524645AA6D1BB040FFAC32E253B0AC93C9E967BF273FC4F4F2C5A3218881D`.
- Data facts: target and adjacent live bytes are zero. Full 40-byte UID0002B5 storage cluster SHA is `2C34CE1DF23B838C5ABF2A7F6437CCA3D3067ED509FF25F11DF6B11B582B51EB`.
- Type facts: class RTTI/vtables at `0x00614fbc/0x0061500c/0x0061503c`; type descriptors at `0x006751d4` and `0x006751f8`; class hierarchy reports seven bases and Singleton PMD `+0xf8`.
- Negative facts: FP/FQ have no modeled function, entry xref, vtable cell, pointer table, export, relocation, VA/RVA/rel32 reference, or direct caller; that proves retained no-route liveness, not compiler authorship.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067ade0-0x0067ade4` | UID0002XF target | physical storage | false applied | UID0002XE | 92/94 | non-emitting evidence |
| semantic global | UID0002XE | sole source definition | true | UID0000I5 | 92/94 | source position 0 |
| class/header | UID00001V | complete class/layout | true | UID0000I5 | 92/94 | source position 10 |
| `0x00481b60-0x00481bb9` | UID0002FP | retained compare method | true | UID00001V | 90/93 | source position 20 |
| `0x00481bc0-0x00481c05` | UID0002FQ | retained capture method | true | UID00001V | 90/93 | source position 30 |
| `0x00481c10-0x00481d2a` | UID0002FR | constructor | true | UID00001V | 92/94 | source position 40 |
| `0x00481d30-0x00481d59` | UID0002FS | ordinary destructor | true | UID00001V | 92/94 | source position 50 |
| `0x00481d60-0x0048214f` | UID0002FT | virtual mouse method | true | UID00001V | 89/91 | preserve body, position 60 |
| `0x00482150-0x004822f6` | UID0002FU | virtual paint method | true | UID00001V | 89/91 | preserve body, position 70 |
| `0x00482300-0x0048230a` | UID0002FV | compiler forwarder | false | NONE | 86/90 | blank/no source |
| `0x004839c0-0x00483ef7` | UID0002GI | compiler glue aggregate | false | NONE | 84/90 | blank/no source |
| `0x00614cdc-0x00615284` | UID0003AT | compiler RTTI/vtable data | true index | UID0000I5 | 90/94 | blank ABI source |
| `0x0067adc4-0x0067adec` | UID0002B5 | mixed storage split map | false | NONE | 88/93 | index only |
| `0x0047efb0-0x00483ef7` | UID000104 | Chatting UI aggregate | true index | UID0000I5 | 88/93 | child routed |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0047f932` | UID0002EV ChattingPane::OnPaint | current-layout `+0x118` gate; no null check; background still fills when false |
| `0x00480740` | UID0002F3 ChattingBackPane::UpdateVisibility | reads `+0x114/+0x118`; alpha `0.7/0.3` and mode/color refresh |
| `0x004808a0` | UID0002F6 ModifyHeight OnMouseEvent | `+0x118` false rejects drag |
| `0x00480bc0` | UID0002F9 ModifyHeight OnPaint | `+0x118` selects active `CHATSC.EPF` paint versus inactive clear/refresh |
| `0x00481c58` | UID0002FR constructor | adjusted-null direct-Singleton publication path |
| `0x00481c5f` | UID0002FR constructor | zero alternative in compiler-lowered publication sequence |
| `0x00481d4a` | UID0002FS ordinary destructor | direct-Singleton reverse destruction clear |
| `0x004839c0` | UID0002GI cleanup | constructor-unwind Singleton clear |
| `0x00483bc0` | UID0002GI scalar wrapper | scalar-destruction Singleton clear |
| `0x004f266b` | LineInputPane::HandleKeyInput | pending-target/chat cleanup gate at `+0x111` |
| `0x00504994` | UID0002QH MapPane exit teardown | null-check then remove pane from UI graph |
| `0x005a514b` | UID0002RX current-say dispatcher | pending target skips current-mode dispatch to default input |
| `0x005afc50` | UID0001LE SelectObject mouse | confirmed target cleanup resets state/refreshes selector |
| `0x005b04d0` | UID0001LL TargetObject mouse | corresponding target cleanup/reset |
| `0x005b1cc6` | NewSayToUserMessageInputPane key handler | empty-backspace cleanup and name-input transition |
| `0x004f8288` | UID00019K caller to constructor | one `0x128` allocation/construction; rectangle `(74,727,740,751)` |

## Documentation Evidence And IDA Status

- Current target/global/class pages identify the family and major fields with complete callback metadata/formals; their exact hashes and validators are recorded below.
- UID0002FP's blank block and UID0002FQ's covered marker are evidence-time historical dispositions superseded by exact typed bodies.
- UID0002FR/FS historically handwrote global publication/clear. Current source uses direct Singleton construction and an empty ordinary destructor while preserving the observed writes as compiler-lowering evidence.
- UID0002FT/FU bodies remain accepted source evidence. Enum/source-order placement and positions are synchronized; behavior is preserved.
- UID0002FV/2GI/3AT retain the compiler-output distinction and now include the exact Handle-specific evidence without handwritten ABI source.
- Historical generated command `15860` proved the original routing defects. Final waited command `15889` proves their removal; generated output remains routing evidence rather than binary authority and was never edited manually.

## Ranked Ownership Analysis

### 1. UID0002XE semantic global under UID0000I5 Chatting

- Evidence for: identical source type across all 15 refs, existing sole generated definition, class/file family, sibling one-definition policy, direct Singleton lifecycle.
- Evidence against: none. The earlier incomplete UID0002XE definition/score state is superseded by applied `92/94` Destination 2.
- Decision: sole semantic definition at position 0.

### 2. UID00001V ChattingHandlePane class under UID0000I5 Chatting

- Evidence for: exact RTTI/vtables, constructor/destructor, method island, fields, allocation, resources, runtime consumers, direct Singleton specialization.
- Evidence against: original private helper spellings/access labels are stripped.
- Decision: complete class/header emitter, with descriptive helper names capped below 95.

### 3. UID0002XF physical address page or UID0002B5 aggregate as source owner

- Evidence for: they preserve exact storage/range and linker adjacency.
- Evidence against: neither is a semantic source identity; emitting either duplicates UID0002XE or invents an aggregate object absent from all code.
- Decision: false/non-emitting physical child and false/non-emitting split index.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use existing `NexusTK/social/Chatting.cpp` via UID0000I5.
- Likely full contents: existing complete Chatting union plus the sole global, class declaration, retained private helpers, lifecycle, mouse, and paint methods.
- Candidate related items rejected: compiler forwarder, cleanup/scalar wrappers, RTTI/vtables, and mixed storage cluster as handwritten source.
- Source-file inference: broad existing Chatting source is stronger than a new narrow Handle file because all neighboring pane implementations/resources/globals already route there.

## Source Placement

- Recommended placement: UID0002XE definition at Chatting.cpp position 0; UID00001V declaration at 10; methods at 20-70 in address order.
- The class block provides header-level forward/type/enum/class/extern declarations and closes before `[[CHILDREN]]`. It does not duplicate method bodies.
- UID0002XF stays as address evidence only. UID0002B5 and UID000104 stay indexes only.
- Rejected placements: by-memory physical source, mixed aggregate object, selector ownership for FP/FQ, separate generated ABI source, or by-file reconstruction metadata.
- Remaining uncertainty: exact original helper spellings only; descriptive names are behavior-specific and do not affect linkage/ABI.

## Range / Split / Padding / Reclassification Analysis

- Exact storage split: UID0002XB `[0x0067addc,0x0067ade0)`, UID0002XF `[0x0067ade0,0x0067ade4)`, UID0002XH `[0x0067ade4,0x0067ade8)`; all are distinct semantic globals inside UID0002B5 `[0x0067adc4,0x0067adec)`.
- UID0002XF has no child and no padding. Its four bytes are the complete pointer slot.
- FP ends at `0x00481bb9`, followed by seven `0xcc`; FQ ends `0x00481c05`, followed by eleven `0xcc`; constructor begins `0x00481c10`, ends `0x00481d2a`, followed by six `0xcc`; destructor begins `0x00481d30`, ends `0x00481d59`, followed by seven `0xcc` before OnMouseEvent.
- Class layout uses implicit C++ alignment at record `+0x02..+0x03/+0x09..+0x0b` and object `+0x112..+0x113`; no reserve members are authored.
- Reclassify only UID0002XF to false/non-emitting. No range rename/split/new UID is needed.

## Negative Evidence Summary

- Runtime reads prove dependency, not global or class ownership; ownership is established independently by lifecycle/RTTI/source routing.
- Neighboring globals do not form a source array/struct: every slot has distinct type, owner, lifecycle, and readers.
- No raw initializer supports `0xffffffff`; the target has no raw-backed bytes at all.
- No evidence supports `static` linkage; consumers span multiple logical source families and the generated semantic global is external.
- No evidence supports explicit source publication/clear, vptr stores, base destructor calls, scalar delete flags, size guards, EH/cookie, RTTI, vtable arrays, or adjusted-null arithmetic.
- FP/FQ no-xref status does not support deletion or marker-only coverage because their bodies are source-shaped, typed, paired, and not compiler/library patterns.
- No helper/class body is moved to UID0002XF or UID0002B5.

## IDA Rename / Type / Comment Recommendations

- IDA mutation is not requested. Report source names only.
- Descriptive names: `ChattingHandleRenderState`, `IsRenderStateCurrent`, and `CaptureRenderState`; preserve historical raw page titles and explain that spelling is inferred.
- Source type: `ChattingHandlePane *g_pChattingHandlePane`; record fields are bool/int natural layout; active mode is int; paint states remain int backed by `ChatHandleButtonPaintState` values.
- Keep current source-facing field names `m_chatTargetPending`, `m_chatHandleModeIndex`, and `m_secondaryChatEnabled`; they are supported by writers, config persistence, and consumers.
- Do not rename compiler subroutines or ABI tables as authored methods.

## First-Draft C++ Recommendation

- Eligible: semantic global, complete class declaration, FP/FQ member bodies, constructor, ordinary destructor, and enum-relocated OnMouseEvent. Existing OnPaint is retained exactly.
- Not eligible: physical target, forwarder, compiler glue family, and vtable/RTTI data. Their exact blank formal blocks are included to prevent accidental ABI emission.

Destination 1 - UID0002XF exact formal replacement:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2 - UID0002XE exact formal replacement:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingHandlePane;

ChattingHandlePane *g_pChattingHandlePane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3 - UID00001V exact formal replacement:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;

static signed char GetChatButtonAtPoint(int mouseY, int mouseX);

enum ChatHandleButtonHit
{
    kChatHandleButtonNone = -1,
    kChatHandleButtonLeft = 0,
    kChatHandleBody = 1,
    kChatHandleButtonMode = 2,
    kChatHandleButtonSecondary = 3,
};

enum ChatHandleButtonPaintState
{
    kChatHandleButtonNormal = 0,
    kChatHandleButtonHover = 1,
    kChatHandleButtonPressed = 2,
};

struct ChattingHandleRenderState
{
    bool valid;
    bool chatTargetPending;
    int chatHandleModeIndex;
    bool secondaryChatEnabled;
    int leftButtonPaintState;
    int modeButtonPaintState;
    int secondaryButtonPaintState;
};

class ChattingHandlePane : public Pane,
                           public Singleton<ChattingHandlePane>
{
public:
    ChattingHandlePane();
    virtual ~ChattingHandlePane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();

private:
    bool IsRenderStateCurrent(const ChattingHandleRenderState *state) const;
    void CaptureRenderState(ChattingHandleRenderState *state) const;

    ChattingHandleRenderState m_renderStateSnapshot;
    bool m_mouseCaptured;

public:
    bool m_chatTargetPending;
    int m_chatHandleModeIndex;
    bool m_secondaryChatEnabled;

private:
    bool m_leftButtonPressed;
    bool m_modeButtonPressed;
    bool m_secondaryButtonPressed;
    int m_leftButtonPaintState;
    int m_modeButtonPaintState;
    int m_secondaryButtonPaintState;
};

extern ChattingHandlePane *g_pChattingHandlePane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4 - UID0002FP exact formal replacement:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ChattingHandlePane::IsRenderStateCurrent(
    const ChattingHandleRenderState *state) const
{
    if (!state->valid)
        return false;

    return state->chatTargetPending == m_chatTargetPending &&
           state->chatHandleModeIndex == m_chatHandleModeIndex &&
           state->secondaryChatEnabled == m_secondaryChatEnabled &&
           state->leftButtonPaintState == m_leftButtonPaintState &&
           state->modeButtonPaintState == m_modeButtonPaintState &&
           state->secondaryButtonPaintState == m_secondaryButtonPaintState;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5 - UID0002FQ exact formal replacement:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ChattingHandlePane::CaptureRenderState(
    ChattingHandleRenderState *state) const
{
    state->valid = true;
    state->chatTargetPending = m_chatTargetPending;
    state->chatHandleModeIndex = m_chatHandleModeIndex;
    state->secondaryChatEnabled = m_secondaryChatEnabled;
    state->leftButtonPaintState = m_leftButtonPaintState;
    state->modeButtonPaintState = m_modeButtonPaintState;
    state->secondaryButtonPaintState = m_secondaryButtonPaintState;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6 - UID0002FR exact formal replacement:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ChattingHandlePane::ChattingHandlePane()
    : Pane(1),
      Singleton<ChattingHandlePane>()
{
    m_mouseCaptured = false;
    m_chatHandleModeIndex = g_pConfig->m_chatHandleModeIndex;
    m_secondaryChatEnabled = (g_pConfig->m_secondaryChatEnabled != 0);
    m_chatTargetPending = (g_pConfig->m_chatHandleLeftToggle != 0);

    if (m_secondaryChatEnabled)
        g_pChattingDisplayPane->m_scrollWidget->Enable();
    else
        g_pChattingDisplayPane->m_scrollWidget->Disable();

    m_leftButtonPressed = false;
    m_modeButtonPressed = false;
    m_secondaryButtonPressed = false;
    m_leftButtonPaintState = kChatHandleButtonNormal;
    m_modeButtonPaintState = kChatHandleButtonNormal;
    m_secondaryButtonPaintState = kChatHandleButtonNormal;
    m_renderStateSnapshot.valid = false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 7 - UID0002FS exact formal replacement:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ChattingHandlePane::~ChattingHandlePane()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 8 - UID0002FT exact formal replacement preserves its complete accepted method body and removes only the two leading enum declarations now emitted by Destination 3:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ChattingHandlePane::OnMouseEvent(const PaneMouseEvent *event)
{
    bool handled = false;

    if (g_pUserPane->m_inputLocked)
        return false;

    switch (event->type) {
    case kPaneMouseMove:
    {
        if (!PointInRect(event->mouseY, event->mouseX, &m_bounds)) {
            m_leftButtonPaintState = kChatHandleButtonNormal;
            m_modeButtonPaintState = kChatHandleButtonNormal;
            m_secondaryButtonPaintState = kChatHandleButtonNormal;
            break;
        }

        RectBounds leftButtonRect;
        RectBounds modeButtonRect;
        RectBounds secondaryButtonRect;

        InitRectBounds(&leftButtonRect, 0, 4, 19, 21);
        InitRectBounds(&modeButtonRect, 630, 4, 649, 21);
        InitRectBounds(&secondaryButtonRect, 649, 4, 668, 21);

        const bool overLeft =
            PointInRect(event->mouseY, event->mouseX, &leftButtonRect);
        const bool overMode =
            PointInRect(event->mouseY, event->mouseX, &modeButtonRect);
        const bool overSecondary =
            PointInRect(event->mouseY, event->mouseX, &secondaryButtonRect);

        if (m_mouseCaptured) {
            m_leftButtonPaintState =
                (overLeft && m_leftButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
            m_modeButtonPaintState =
                (overMode && m_modeButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
            m_secondaryButtonPaintState =
                (overSecondary && m_secondaryButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
        } else {
            m_leftButtonPaintState =
                overLeft ? kChatHandleButtonHover : kChatHandleButtonNormal;
            m_modeButtonPaintState =
                overMode ? kChatHandleButtonHover : kChatHandleButtonNormal;
            m_secondaryButtonPaintState =
                overSecondary ? kChatHandleButtonHover : kChatHandleButtonNormal;
        }

        handled = true;
        break;
    }

    case kPaneMouseLeftButtonDown:
        m_mouseCaptured = true;

        switch (GetChatButtonAtPoint(event->mouseY, event->mouseX)) {
        case kChatHandleButtonLeft:
            m_leftButtonPressed = true;
            m_leftButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        case kChatHandleBody:
            if (g_pUserPane->m_pendingTargetObject == NULL) {
                OpenInputPaneForCurrentSayMode(g_pUserPane);
                handled = true;
            }
            break;

        case kChatHandleButtonMode:
            m_modeButtonPressed = true;
            m_modeButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        case kChatHandleButtonSecondary:
            m_secondaryButtonPressed = true;
            m_secondaryButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        default:
            break;
        }
        break;

    case kPaneMouseLeftButtonUp:
        m_mouseCaptured = false;

        switch (GetChatButtonAtPoint(event->mouseY, event->mouseX)) {
        case kChatHandleButtonLeft:
            if (m_leftButtonPressed)
                m_chatTargetPending = !m_chatTargetPending;
            handled = true;
            break;

        case kChatHandleButtonMode:
            if (m_modeButtonPressed) {
                m_chatHandleModeIndex = (m_chatHandleModeIndex + 1) % 3;
                g_pChattingBackPane->InvalidateRect(&g_pChattingBackPane->m_bounds);
                g_pChattingDisplayPane->InvalidateRect(&g_pChattingDisplayPane->m_bounds);
            }
            handled = true;
            break;

        case kChatHandleButtonSecondary:
            if (m_secondaryButtonPressed) {
                m_secondaryChatEnabled = !m_secondaryChatEnabled;

                if (m_secondaryChatEnabled)
                    g_pChattingDisplayPane->m_scrollWidget->Enable();
                else
                    g_pChattingDisplayPane->m_scrollWidget->Disable();

                g_pChattingBackPane->InvalidateRect(&g_pChattingBackPane->m_bounds);
                g_pChattingDisplayPane->InvalidateRect(&g_pChattingDisplayPane->m_bounds);
                g_pChattingModifyHeightPane->InvalidateRect(&g_pChattingModifyHeightPane->m_bounds);
            }
            handled = true;
            break;

        default:
            break;
        }

        m_leftButtonPressed = false;
        m_modeButtonPressed = false;
        m_secondaryButtonPressed = false;

        g_pConfig->m_chatHandleModeIndex = m_chatHandleModeIndex;
        g_pConfig->m_secondaryChatEnabled = m_secondaryChatEnabled;
        g_pConfig->m_chatHandleLeftToggle = m_chatTargetPending;
        break;

    default:
        break;
    }

    if (!m_renderStateSnapshot.valid ||
        m_renderStateSnapshot.chatTargetPending != m_chatTargetPending ||
        m_renderStateSnapshot.chatHandleModeIndex != m_chatHandleModeIndex ||
        m_renderStateSnapshot.secondaryChatEnabled != m_secondaryChatEnabled ||
        m_renderStateSnapshot.leftButtonPaintState != m_leftButtonPaintState ||
        m_renderStateSnapshot.modeButtonPaintState != m_modeButtonPaintState ||
        m_renderStateSnapshot.secondaryButtonPaintState != m_secondaryButtonPaintState) {
        InvalidateRect(&m_bounds);
    }

    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 9 - UID0002FU exact retained formal source; set position `70`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ChattingHandlePane::OnPaint()
{
    EPFTileContext tile;
    RectBounds drawRect;

    tile.Initialize();
    SetPaneDrawMode(0);

    InitRectBounds(&drawRect, 0, 4, 19, 21);
    int frameIndex = 3 * m_leftButtonPaintState;
    if (!m_chatTargetPending)
        frameIndex += 9;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    InitRectBounds(&drawRect, 630, 4, 649, 21);
    frameIndex = 3 * m_modeButtonPaintState;
    if (m_chatHandleModeIndex)
        frameIndex += 1;
    else
        frameIndex += 10;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    InitRectBounds(&drawRect, 649, 4, 668, 21);
    frameIndex = 3 * m_secondaryButtonPaintState;
    if (m_secondaryChatEnabled)
        frameIndex += 2;
    else
        frameIndex += 11;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    m_renderStateSnapshot.valid = true;
    m_renderStateSnapshot.chatTargetPending = m_chatTargetPending;
    m_renderStateSnapshot.chatHandleModeIndex = m_chatHandleModeIndex;
    m_renderStateSnapshot.secondaryChatEnabled = m_secondaryChatEnabled;
    m_renderStateSnapshot.leftButtonPaintState = m_leftButtonPaintState;
    m_renderStateSnapshot.modeButtonPaintState = m_modeButtonPaintState;
    m_renderStateSnapshot.secondaryButtonPaintState = m_secondaryButtonPaintState;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 10 - UID0002FV exact blank compiler-forwarder formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 11 - UID0002GI exact blank compiler-glue formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 12 - UID0003AT exact blank compiler-ABI formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: D4 exactly follows valid-first/six-field short-circuit compare; D5 writes valid before six fields; D6 preserves initialization and scroll order while expressing Singleton compiler lowering; D7 leaves only the authored empty body; D8/D9 preserve accepted virtual behavior.
- Source-era shape: forward declaration, external zero pointer, direct template inheritance, small POD state record, out-of-line helpers, constructor/destructor, and enums in header scope are plausible Visual C++ source without decompiler artifacts.
- No-code proof: UID0002XF has no semantic identity; UID0002FV is a ten-byte secondary dispatch forwarder; UID0002GI subranges are unwind/scalar/adjustor wrappers; UID0003AT is RTTI/vtable data. Complete class inheritance/methods regenerate all of them.

## Final Recommendation

- Destinations 1-12 and the exact source order/metadata described above are applied and validator-confirmed.
- Target/global/class/constructor/destructor are `92/94`; FP/FQ are `90/93`; FT/FU remain `89/91`, FV `86/90`, GI `84/90`, AT `90/94`, B5 `88/93`, aggregate `88/93`, and file `89/93`.
- All existing runtime behavior, ranges, hashes, field/resource/config facts, sibling pane union, and old assumptions as explicitly historical are preserved.
- No source-bearing or implementation blocker remains. Supervisor-owned manual coverage and report lifecycle remain external.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md`, final hash `BCEAC7AAECF45AF40B76CB90F91411612D5B73E60EA9513477AEE11AB9AB1BEE`.
- Applied `92/94`, retained semantic owner `0002XE`, reconstructable false, blank emitter/position/formal, and `Nested:0`.
- Applied exact Item Summary: `Exact loader-zeroed four-byte singleton backing storage; all fifteen references split into five compiler-lifetime operations and ten runtime reads, while the sole typed source definition belongs to the semantic global and this page emits no duplicate source.`
- Applied exact loader-zero evidence, target zero-byte SHA, PE section facts, predecessor/successor, all 15 classified refs, sole-definition rule, direct Singleton lifecycle distinction, and no-duplicate/generated contract.
- Historical A008 provenance and prior marker/`0xffffffff` disposition remain explicitly superseded rather than deleted.

## Recommended Support Doc Changes

- Applied UID0002XE `92/94`, position 0, Destination 2, all 15 refs, and sole-definition policy.
- Applied UID00001V `92/94`, position 10, Destination 3, exact layout/access/method/source/compiler evidence.
- Applied UID0002FP/FQ `90/93`, positions 20/30, Destinations 4/5, source-authored retained liveness, exact bytes/hashes/negative routes, and superseded blank/covered-marker history.
- Applied UID0002FR/FS `92/94`, positions 40/50, Destinations 6/7, direct Singleton lowering and compiler exclusions.
- Applied UID0002FT position 60 and Destination 8 enum relocation only; full body/detail/score remain preserved.
- Applied UID0002FU position 70; exact existing body/detail/score remain preserved.
- Verified UID000107 accepted static definition remains unique and signature-equal to Destination 3's prototype; no body/page change was needed.
- Verified UID0002FV exact blank forwarder disposition; applied bounded UID0002GI/UID0003AT Handle Singleton/unwind/scalar/vtable evidence while retaining blank no-ABI formals and scores.
- Applied complete no-loss Handle closure to UID0002B5/UID000104/UID0000I5.
- Applied bounded UID00019K allocation/direct-Singleton and UID0002QH null-checked teardown prose. Same-or-greater runtime consumers remained read-only except UID00035Y exact cleanup prose and UID0001LE/UID0001LL replacement of an unbacked helper spelling with direct `m_chatTargetPending` field access.

## Score And Metadata Recommendation

- UID0002XF is applied at `92/94`, false, owner 2XE, blank emitter/position/formal; historical `86/90` true/owner-emitter state is superseded.
- UID0002XE is applied at `92/94`, owner/emitter 0I5, position 0.
- UID00001V is applied at `92/94`, owner/emitter 0I5, position 10.
- FP/FQ are applied at `90/93`, positions 20/30. Original spellings cap confidence below 94/95.
- FR/FS are applied at `92/94`, positions 40/50 because the exact source/compiler split is closed.
- Score blockers attempted and resolved: zero/static initializer, all 15 refs, global linkage/type/order, direct Singleton RTTI/EBO, full class size/fields/access, helper liveness/signatures/bodies, constructor/destructor authorship, scalar/unwind/vtable disposition, generated one-definition order, aggregate split, coverage rows, and historical report contradictions.
- Reason not higher: stripped original helper names/access labels and inability to compile the historical toolchain exactly. These do not block destination-ready source.

## Open Questions With Attempted Resolution

- Exact helper names: symbol/entity/report searches found no original names. Their receiver/parameter/return/behavior are exact, so descriptive private names are safe; confidence is capped rather than body deferred.
- Exact access labels: cross-class direct field reads prove three active members must be visible. Internal fields/helpers can be private. No evidence supports an all-private layout without friends/accessors.
- Why no helper callers: pointer/xref/relocation/byte searches were exhaustive. The most defensible result is retained unused out-of-line source, likely inlined equivalent use elsewhere; deleting or marker-covering it would fail exact source inventory.
- Explicit `0` versus `NULL`: current sibling semantic global source and source-era style support `0`; either has identical data. Use `0` consistently with direct-Singleton sibling closures.
- Remaining unresolved issues affecting owner/emitter/C++: none.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Final callback read-only manual snapshots: by-memory SHA `0DF9390A701D80ED8F95EB580DA3FAF597F7949BA072E6D77D86B45619909E87` (1,904,908 bytes/4,471 lines); by-global SHA `C01FBCA82B93ABF4E021807FBEEC5609BDD6A18A0AC14BE087553CF6DE8588C7` (94,233/214); by-class SHA `2D7FE0D78AD2E52AB5CB69D38DB18A41A4EAE898FB563F8EA38DEABA6F9D4FA4` (247,266/623); by-file SHA `AB61D69503F47C447B10FD13C622B9BEEFBA2473CB33FECC95ADB1C98236D2BA` (144,661/316).
- All thirteen current rows were reread after ordinary validation. The following remain literal full-row replacements that preserve every current valid clause and append only the accepted Handle closure. Supervisor owns application; B002 did not edit manual coverage.

`by-memory/-coverage-report.md` replace current line 4323:

```text
        - [UID:0002XF][0x0067ade0-0x0067ade4.g_pChattingHandlePane](by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md) 0x0067ade0-0x0067ade4 | global pointer backing | g_pChattingHandlePane : not_reconstructable : 92% : very-strong : Exact loader-zeroed four-byte backing storage for semantic g_pChattingHandlePane; target SHA-256 DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119; fifteen refs comprise five compiler-lowered direct-Singleton lifetime writes/clears and ten runtime reads; sole source definition emits from UID0002XE, so this physical page is false/non-emitting evidence and historical 0xffffffff wording is superseded.
```

Replace lines 818, 820, 822, 824, and 828 respectively:

```text
        - [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md) 0x00481b60-0x00481bb9 | retained class helper | ChattingHandlePaneIsRenderStateCurrent : reconstructable : 90% : very-strong : Exact 89-byte/SHA-256 049D3A45175D9E61F5DF4E0EA079C7141693776DE45ECF238D532E380B91DAFD private source helper; thiscall receiver plus one 24-byte state pointer, valid-first six-field comparison, ret 4, exact padding, zero inbound route, descriptive IsRenderStateCurrent spelling, and no selector/compiler-glue ownership.
        - [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) 0x00481bc0-0x00481c05 | retained class helper | ChattingHandlePaneCaptureRenderState : reconstructable : 90% : very-strong : Exact 69-byte/SHA-256 2383E96AFEA172387C7F94559C6BE31DB51EF850E23285535F56EE7AEC2AA747 private source helper; thiscall receiver plus one 24-byte state pointer, valid-first six-field copy, ret 4, exact padding, zero inbound route, descriptive CaptureRenderState spelling, and superseded marker-only coverage.
        - [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md) 0x00481c10-0x00481d2a | constructor | ChattingHandlePaneConstructor : reconstructable : 92% : very-strong : Exact 282-byte/SHA-256 6218973366CB08F9B770A6F575DE3604C23799DB27619AC4292F01F6F0474005 constructor with sole InitializeMainUiGraph allocation after 0x128 allocation; source uses Pane(1), direct Singleton<ChattingHandlePane>, config imports, scroll enable/disable, latch/paint/snapshot initialization; adjusted-null publication, vptrs, SEH/cookie, and cleanup are compiler output.
        - [UID:0002FS][0x00481d30-0x00481d59.ChattingHandlePaneDestructor](by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md) 0x00481d30-0x00481d59 | destructor body | ChattingHandlePaneDestructor : reconstructable : 92% : very-strong : Exact 41-byte/SHA-256 6ADE99AFAB255AD43A77BFEE256638C8998BFC77065014627F6F8FA0969FAFE9 ordinary virtual destructor with an empty human body; compiler restores three class vtables, destroys Singleton<ChattingHandlePane> to clear 0x0067ade0, then tail-calls Pane::~Pane; scalar/vtable liveness, exact padding, and rejected explicit-clear/base-call/ABI source remain documented.
        - [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md) 0x00482150-0x004822f6 | class method | ChattingHandlePaneOnPaint : reconstructable : 89% : strong : Source-ready ChattingHandlePane painter preserving CHATBUTT.EPF/CHATBUTT.PAL rectangles, three paint-state frame formulas, pending/mode/secondary offsets, exact RenderTileFrame calls, and full seven-field m_renderStateSnapshot refresh.
```

Replace UID0002GI line 875:

```text
        - [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md) 0x004839c0-0x00483ef7 | compiler-generated glue | ChattingUiDestructorGlueFamily : ignored : 84% : strong : Exact cleanup/adjustor/scalar-wrapper family with complete sibling vtable/data refs, call sets, padding, and delete flags; 0x004839d0 constructor-unwind clear and 0x00483c20 scalar-wrapper clear are compiler-lowered Singleton<ChattingModifyHeightPane> destruction, while UID0002F5 has an empty human destructor body and no standalone glue C++ is emitted; ChattingPane clear helper 0x004839e0 and scalar wrapper 0x00483c60 are compiler manifestations of source-ready UID0002EO/UID0002EP and remain non-emitting; ChattingHandlePane clear helper 0x004839c0 and scalar wrapper 0x00483ba0 are compiler-lowered direct Singleton<ChattingHandlePane> destruction around an empty UID0002FS human body and remain non-emitting.
```

Replace UID0003AT current line 3905:

```text
        - [UID:0003AT][0x00614cdc-0x00615284.ChattingVtableData](by-memory/0x00614cdc-0x00615284.ChattingVtableData.md) 0x00614cdc-0x00615284 | vtable-data | ChattingVtableData : reconstructable : 90% : very-strong : Exact Chatting RTTI/vtable group with complete class table inventory and compiler-only disposition; ChattingModifyHeightPane retains primary/secondary tables and UID0002F7 packet slot, while RTTI directly proves Pane plus Singleton<ChattingModifyHeightPane> with Singleton PMD +0xf8, explaining constructor/unwind/ordinary/scalar lifetime writes without handwritten vtables, adjustors, RTTI, or duplicate source; selector RTTI likewise directly proves Pane plus Singleton<ChattingVarietySelectPane> with Singleton PMD +0xf8/EBO, explaining its constructor, ordinary-destructor, and scalar-wrapper publication/clear writes under the same compiler-only ABI disposition; ChattingHandlePane RTTI likewise directly proves Pane plus Singleton<ChattingHandlePane> with Singleton PMD +0xf8/EBO and compiler-only primary/secondary vtables, publication/clear lowering, forwarder, scalar wrapper, and RTTI.
```

Replace UID0002B5 current line 4315:

```text
    - [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) 0x0067adc4-0x0067adec | global-data split map | UiChatClanSingletonSlots : not_reconstructable : 88% : very-strong : Exact non-emitting ten-dword split map for linker-adjacent system-message, TextFilter, chat, clan, and clan-bank singleton storage; current MCP proves all forty virtual .data bytes are zero and exact four-byte children retain distinct semantic owners; UID0002X6 remains false/non-emitting backing storage for the sole UID0002X5 g_pChattingVarietyPane definition with all 18 refs classified; UID0002X2 is loader-zeroed false/non-emitting g_pChattingModifyHeightPane backing storage at 92/94 with five compiler-lifetime and two runtime refs while UID0002X1 emits the sole definition; every other zero/xref/boundary/consumer fact remains preserved and no aggregate array/struct/global source is emitted; UID0002WY is source-declared/generated-binary g_pChattingDisplayPane backing storage at 92/94 with exhaustive 20-reference classification; UID0002XB is loader-zeroed false/non-emitting g_pChattingVarietySelectPane backing storage at 92/94 with all seven refs classified as five compiler-lowered direct-Singleton lifetime writes/clears and two runtime reads while UID0002XA emits the sole source definition, so neither the target child nor this aggregate emits duplicate source; UID0002XF is loader-zeroed false/non-emitting g_pChattingHandlePane backing storage at 92/94 with five compiler-lifetime and ten runtime refs while UID0002XE emits the sole typed source definition.
```

Replace UID000104 line 732:

```text
    - [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md) 0x0047efb0-0x00483ef7 | aggregate | ChattingUI : reconstructable : 88% : very-strong : Address-ordered Chat UI aggregate/index preserving every pane/message/input/color child, resource and padding fact, exact method bodies, vtable/compiler-glue tail, and unrelated follow-up; ChattingModifyHeightPane now has direct Pane plus Singleton inheritance, source-clean constructor, empty ordinary destructor, false/non-emitting physical storage, sole semantic global definition, and no aggregate duplicate emission; ChattingPane display singleton storage/definition/declaration/constructor/destructor lifecycle is source-ready on exact children, with no aggregate duplicate emission; ChattingHandlePane now has direct Pane plus Singleton inheritance, complete class/layout, source-ready retained compare/snapshot helpers, corrected constructor, empty ordinary destructor, false/non-emitting physical storage, sole semantic global definition, and no aggregate duplicate emission.
```

`by-global/-coverage-report.md` replace line 66:

```text
- [UID:0002XE][g_pChattingHandlePane](by-global/g_pChattingHandlePane.md) : reconstructable : 92% : very-strong : Sole externally linked ChattingHandlePane pointer definition for loader-zeroed physical child UID0002XF; exact fifteen-reference inventory, direct Singleton<ChattingHandlePane> publication/clear lowering, complete runtime consumer/field semantics, source position zero, and no duplicate physical/aggregate/ABI source.
```

`by-class/-coverage-report.md` replace line 92:

```text
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md) : reconstructable : 92% : very-strong : Complete 0x128 Pane plus Singleton<ChattingHandlePane> class with direct-Singleton PMD +0xf8/EBO, exact 24-byte render snapshot and active/latch/paint fields, source-ready retained compare/capture helpers, corrected constructor, empty ordinary destructor, accepted mouse/paint methods, external active-state access, compiler-only forwarder/scalar/vtable handling, and sole UID0002XE global contract.
```

`by-file/-coverage-report.md` replace line 49:

```text
- [UID:0000I5][Chatting](by-file/Chatting.md) : reconstructable : 89% : very-strong : NexusTK/social/Chatting.cpp owns the complete current chat UI union, including one position-zero externally linked g_pChattingVarietyPane definition, false/non-emitting UID0002X6 backing storage, source-clean closed ChattingVarietyPane declaration plus extern contract, exact variety constructor/ordinary-destructor lifecycle, all 18 selector/input/map/target/say consumers, current class declarations and exact pane/message/input/packet/color/handle children through ColorStringChattingMessage, established singleton/source routing, and preserved compiler-artifact distinctions; ChattingModifyHeightPane additionally uses direct Pane plus Singleton inheritance, one external zero definition at UID0002X1, false/non-emitting physical UID0002X2 storage, a source-clean constructor, empty ordinary destructor, compiler-only unwind/scalar clears, and exact HandlePane invalidation and MapPane teardown consumers; all unrelated content and remaining follow-up inventory stay preserved; ChattingPane adds one g_pChattingDisplayPane external declaration, sole definition, physical marker route, source-ready constructor/destructor, exhaustive 20-reference singleton lifetime, and no duplicate compiler-ABI body; the selector-popup closure adds one position-zero externally linked g_pChattingVarietySelectPane definition, false/non-emitting UID0002XB backing storage, a complete Pane plus Singleton<ChattingVarietySelectPane> declaration and extern, exact retained constructor and authored-cleanup destructor, compact ChattingVarietyPane GetItemRect/HitTest plus HandlePointerOrMouseEvent source, selector implicit tail padding +0xfa..+0xfb, compact-pane implicit pointer alignment +0xf9..+0xfb, exact Event/UserPane/MainUiLayerSlots dependencies, and compiler-only Singleton/EH/scalar/vtable handling without physical, aggregate, global, or ABI duplicate emission; the handle-pane closure adds one position-zero externally linked g_pChattingHandlePane definition, false/non-emitting UID0002XF backing storage, a complete Pane plus Singleton<ChattingHandlePane> declaration/extern and exact 0x128 layout, retained IsRenderStateCurrent/CaptureRenderState source helpers, corrected direct-Singleton constructor, empty ordinary destructor, accepted mouse/paint methods in address order, exhaustive fifteen-reference lifetime/runtime inventory, and compiler-only unwind/scalar/forwarder/vtable handling without physical, aggregate, or ABI duplicate emission.
```

- UID0002FT's current row at line 826 remains exact and needs no manual replacement. Its formal-only enum relocation does not change row behavior.
- No by-struct manual coverage root applies; no by-struct destination exists.

## Follow-Up Actions

- B002 implementation, scoped validators, final waited generation, readback, report reconciliation, and lease release are complete.
- Supervisor-owned work is the independent exact-artifact/Gate 2 review, application of the thirteen literal no-loss manual rows when accepted, manual-row validation, and all report lifecycle handling. B002 does not assert a current or future execution/archive path; the exact current path and validator-owned history are authoritative.
- A-agent work is not required. No source-quality or implementation blocker remains.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: very strong for target/global/class/lifecycle; strong for 90/93 private helper names.
- Remaining uncertainty: original private helper spellings/access labels only; explicitly capped and non-blocking.

## Validator Results

- Every scoped command exited `0` with `ok:1`; generated refresh was deferred for scoped commands as required. No scoped warning affected its target. Validator-managed side effects were limited to ordinary metadata/registry/reference/projected-stat synchronization and deferred generated scheduling.

| Command | Timestamp | Scoped page | Result / validator-owned side effects |
| --- | --- | --- | --- |
| `000000015861` | `2026-07-21T14:01:42-04:00` | UID0002XF | exit 0, ok:1; completion/confidence, reconstructable true-to-false, blank emitter/position/formal registry, links/reference index, projected stats. |
| `000000015862` | `2026-07-21T14:02:34-04:00` | UID0002XE | exit 0, ok:1; completion/confidence/position/formal registry and projected stats. |
| `000000015863` | `2026-07-21T14:04:26-04:00` | UID00001V | exit 0, ok:1; completion/confidence/position/class formal registry and projected stats. |
| `000000015864` | `2026-07-21T14:07:09-04:00` | UID0002FP | exit 0, ok:1; `90/93`, position `20`, blank-to-block registry, projected stats. |
| `000000015865` | `2026-07-21T14:08:54-04:00` | UID0002FQ | exit 0, ok:1; `90/93`, position `30`, formal hash update, projected stats. |
| `000000015866` | `2026-07-21T14:10:20-04:00` | UID0002FR | exit 0, ok:1; `92/94`, position `40`, formal hash update, projected stats. |
| `000000015867` | `2026-07-21T14:11:21-04:00` | UID0002FS | exit 0, ok:1; `92/94`, position `50`, formal hash update, projected stats. |
| `000000015868` | `2026-07-21T14:12:03-04:00` | UID0002FT | exit 0, ok:1; position `60`, formal hash update, projected stats. |
| `000000015869` | `2026-07-21T14:12:31-04:00` | UID0002FU | exit 0, ok:1; position `70`, projected stats. |
| `000000015870` | `2026-07-21T14:13:41-04:00` | UID0002GI | exit 0, ok:1; UID0002FS reference and ignored/stat rows synchronized. |
| `000000015871` | `2026-07-21T14:14:39-04:00` | UID0003AT | exit 0, ok:1; projected stats; blank ABI formal unchanged. |
| `000000015872` | `2026-07-21T14:15:14-04:00` | UID0002B5 | exit 0, ok:1; projected stats; aggregate non-emission unchanged. |
| `000000015873` | `2026-07-21T14:16:06-04:00` | UID000104 | exit 0, ok:1; projected stats; aggregate non-emission unchanged. |
| `000000015874` | `2026-07-21T14:17:11-04:00` | UID0000I5 | exit 0, ok:1; projected stats; no by-file reconstruction metadata added. |
| `000000015880` | `2026-07-21T14:17:55-04:00` | UID00019K | exit 0, ok:1; UID0002FR reference index and projected stats. |
| `000000015883` | `2026-07-21T14:18:43-04:00` | UID0002QH | exit 0, ok:1; UID0002FS/XE/XF reference indexes and projected stats. |
| `000000015886` | `2026-07-21T14:21:25-04:00` | UID00035Y | exit 0, ok:1; normalized metadata-header blank, initialized existing UID registry/path, added support references, projected stats. |
| `000000015887` | `2026-07-21T14:21:55-04:00` | UID0001LE | exit 0, ok:1; formal hash registry and projected stats. |
| `000000015888` | `2026-07-21T14:22:19-04:00` | UID0001LL | exit 0, ok:1; formal hash registry and projected stats. |
| `000000015889` | `2026-07-21T14:22:58-04:00` | final UID0002XF `--wait-generated` | exit 0, ok:1; registry rebuild, generated metadata refresh, Chatting.cpp refresh, tracker update. Global pre-existing children-marker/emitter-no-code diagnostics were unrelated; no Handle target/formal error occurred. |

- Independent generated readback: `Chatting.cpp` SHA `2D4049A903F87FDA3E352AFC09F0A407DA0F9EB5133A5F247A40CD581B9BBE5A`, 66,151 bytes / 1,977 lines, command `15889`. It contains one semantic global definition, one complete class definition, one each FP/FQ/constructor/destructor/mouse/paint definition in exact order, one direct Singleton base, zero explicit global publication/clear, zero UID0002XF/01V/2FP/2FQ Empty Emitter Markers, zero FP/FQ covered marker, and zero handwritten scalar/forwarder/vtable/RTTI/EH source. UID000107 remains one static definition with its accepted coverage comment and class-scope forward prototype.
- Cross-source compile visibility readback: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` SHA `9C3814FBCCDA36C7EB9DC48E2C2AD7C5DB548CEDDB158BF01A482BF5228737`, 46,158 bytes / 1,273 lines, contains two direct `m_chatTargetPending` uses and zero `IsCommandPending` references.

## Changed Files

- Modified ordinary pages, exact final SHA/bytes/lines:
  - `by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md` `BCEAC7AAECF45AF40B76CB90F91411612D5B73E60EA9513477AEE11AB9AB1BEE` / 13,376 / 91.
  - `by-global/g_pChattingHandlePane.md` `BB4D8E496579A46C41911681A8A87B740CA7170299E96B931CFDE5DFA9254CA6` / 10,233 / 71.
  - `by-class/ChattingHandlePane.md` `ACB588267DD59F3A8B386F9EB07DD06C555B2CE1AC9437F4B970B3042CBBDE7D` / 22,602 / 179.
  - `by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md` `982ADDAD441F6C65D999868DA04EC3CD36A485A99CD7FD913151F4B89FBC439F` / 11,520 / 102.
  - `by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md` `E79FDC3E62D6C1BB8B3D3F52AA20343173844AC8491A4441C61792BE8B05081C` / 16,317 / 119.
  - `by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md` `2A9953D4BE59777AB42C1CC018B5652E640EC7016F0B90C52E3BB3ACA4E4DCDA` / 12,702 / 111.
  - `by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md` `6620559CCCD0CBE34044252ABE1A3932A327FCC6C7EFE13BC7C811B0DA94DD8A` / 5,969 / 70.
  - `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md` `099AEFC099D29A239865FB7045D9C029F5DE06C59069770D8768AE71E0F88444` / 22,492 / 286.
  - `by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md` `F0ED7A515565493E9D03FA25C37D5C63B7C6B73D640390CA4A8F9718AC00A99D` / 11,998 / 146.
  - `by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md` `283DB6B019BEA33AA49371E5026CDB6B7CDAC55ED04BE9307EF5AB460997B231` / 18,227 / 106.
  - `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md` `AE78A185C5DF1A3F99ADA7B4A9320E7A137223D1CD81C7537AEBDBB666BBF0B1` / 26,346 / 168.
  - `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md` `9888265AFD9612AAA2CEAC7EA7F42D4E699230CB1AEC17D66C6290F9C0753464` / 28,395 / 157.
  - `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md` `82F79ED970867B6B8A7E66506CFD30A608CDC63B06D5AEC96A9BA4228DFDC5D5` / 102,788 / 437.
  - `by-file/Chatting.md` `CF306B19B102987A3B6198B880F22E27E4E5559EE202BDBDFE371D09E1B48523` / 152,700 / 497.
  - `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` `2F08BF1D488F7886F423246491D5C08907445B853B9C6F4139884F229FB6C9CD` / 40,395 / 433.
  - `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` `D449CADDFDA0A54B4575D9D39F2B94B5AB18C3E8996EF1BAA822E00DD2AD7EE5` / 29,560 / 248.
  - `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` `2319DF48CBBAC29C0F01BB45A226319E3125FA4AAB052C0FEB311449229FE221` / 3,972 / 53.
  - `by-memory/0x005afa10-0x005afc8d.SelectObjectWithKeyboardPaneOnMouseEvent.md` `37B8D90EFE24F84C69FFBB45A6330CBB1622A1163BF21C065C3DC0B7799376FE` / 20,170 / 215.
  - `by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md` `74124D7961CB5997A40D3E71656630761A2BCE9B757D3D74762C904384CC2EAA` / 20,200 / 208.
- Verify-only ordinary pages were reread and unchanged where their current facts matched: UID0002FV, UID000107, UID0002EV, UID0002F3, UID0002F6, UID0002F9, UID0002RX, and NewSay. No duplicate helper/report/UID or explicit padding member was created.
- Validator-generated output/tracker changed only through authorized validators; B002 did not edit them manually. Manual coverage, audit, supervisor, validator state, IDA, and lifecycle files were not edited.
- Every ordinary lease was acquired only for its immediate edit/validator and released immediately. Final lease read contains zero B002 entries.
- Report execution/lifecycle is not performed or asserted by B002; exact current path and validator-owned history remain authoritative.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted the exact pre-callback artifact.
- [x] Re-read and no-loss update UID0002XF target.
- [x] Apply Destination 1 and target 92/94 false/non-emitting metadata.
- [x] Re-read and no-loss update UID0002XE.
- [x] Apply Destination 2 and position 0.
- [x] Re-read and no-loss update UID00001V.
- [x] Apply Destination 3 complete class/header and position 10.
- [x] Re-read and no-loss update UID0002FP.
- [x] Apply Destination 4, 90/93, and position 20.
- [x] Re-read and no-loss update UID0002FQ.
- [x] Apply Destination 5, 90/93, and position 30.
- [x] Re-read and no-loss update UID0002FR.
- [x] Apply Destination 6, 92/94, and position 40.
- [x] Re-read and no-loss update UID0002FS.
- [x] Apply Destination 7, 92/94, and position 50.
- [x] Re-read UID0002FT and preserve complete accepted body/detail.
- [x] Apply Destination 8 enum relocation and position 60 without body loss.
- [x] Re-read UID0002FU and verify Destination 9/current body at position 70.
- [x] Verify Destination 3 prototype exactly matches the unique UID000107 static definition and precedes OnMouseEvent.
- [x] Verify UID0002FV blank compiler-forwarder Destination 10.
- [x] Update UID0002GI Handle compiler-lowering evidence and verify Destination 11 blank.
- [x] Update UID0003AT Handle RTTI/vtable evidence and verify Destination 12 blank.
- [x] Update UID0002B5 split closure without aggregate emission.
- [x] Update UID000104 child closure without aggregate emission.
- [x] Update UID0000I5 complete source order/one-definition/compiler exclusion prose.
- [x] Bounded UID00019K allocation/direct-Singleton prose incorporated.
- [x] Bounded UID0002QH null-checked teardown prose incorporated.
- [x] Verify all ten runtime consumers; preserve same-or-greater pages and repair only three concrete support drifts.
- [x] Preserve historical `0xffffffff`, marker-only helpers, and explicit global writes as superseded history.
- [x] Confirm no explicit reserve/padding members were introduced.
- [x] Confirm no duplicate helper page/report/UID was created.
- [x] Confirm ledger Actions use only permitted report-only enums.
- [x] Confirm all C01-C40 Verification states use legal terminal callback values.
- [x] Confirm all twelve managed destination blocks are exact and destination-specific.
- [x] Confirm third-party import directive is not applicable; no third-party source is involved.
- [x] Confirm no Wave2/Wave3 artifact is used as current evidence.
- [x] Confirm exact thirteen-row supervisor-owned manual handoff against the final-read current union.
- [x] Run one successful scoped validator per changed ordinary page after callback authorization.
- [x] Run final waited Chatting generation lease-free after ordinary validation.
- [x] Independently verify generated one-definition/order/count/marker/ABI assertions.
- [x] Update report ledger/results/hashes/checklist after callback without dropping research.

Implementation callback pass:
- [x] Exact report accepted by supervisor for implementation.
- [x] All C01-C40 accepted claims implemented or verified at destinations.
- [x] Every changed ordinary page reread after lease and before edit.
- [x] Every changed ordinary page scoped-validated successfully.
- [x] Every ordinary lease released immediately after its validator.
- [x] All target/global/class/helper/lifecycle metadata and positions applied.
- [x] All source-bearing formal blocks installed exactly.
- [x] Compiler/no-code blocks remain blank and justified.
- [x] Complete existing Chatting union preserved.
- [x] Final generated refresh completed and command metadata recorded.
- [x] Exact generated counts/order and zero prohibited ABI source confirmed.
- [x] Manual coverage remains supervisor-owned and exact handoff remains current.
- [x] Changed files/final hashes/validator warnings/side effects recorded.
- [x] Claim ledger uses legal final callback states only.
- [x] All accepted checklist rows truthfully terminalized.
- [x] Zero B002 leases confirmed.
- [x] No generated/manual/tracker/audit/supervisor/validator/IDA/lifecycle file edited manually.
- [x] No `execute_report`, probe, count, move, archive, or lifecycle command run.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000015934","destination_path":"executed-b-agent-research/B002/0002XF-g_pChattingHandlePane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002XF-g_pChattingHandlePane-source-quality.md","timestamp":"2026-07-21T14:52:42-04:00","uid":"0002XF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
