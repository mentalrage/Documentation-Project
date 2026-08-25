# UID00031K IMEPane Scalar Deleting Destructor Source-Quality Research
** TARGET-REPORT-UID:00031K **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

UID00031K is the exact retained MSVC scalar-deleting wrapper at `[0x004e8720,0x004e87f9)`. It is class-owned binary evidence for `IMEPane`, but it is not an independently authored NexusTK source function and must remain non-reconstructable, non-emitting, and blank in both formal source channels. The one human-source destructor remains UID0004CB `IMEPane::~IMEPane()` under class UID00006H and file UID0000K5.

Fresh read-only IDA MCP evidence independently reconfirms the 217-byte body, exact deleting-flag branches, three child-pane cleanup calls, `focusPaneList` teardown, singleton clear, base teardown, allocation release, complete-object-size no-free branch, two adjustor thunks, three vtable routes, frame, comments, xrefs, and boundary padding. No current source-quality blocker justifies creating a duplicate wrapper body. Current target metadata `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank CPP/H, and `Nested:0` is correct.

The assignment-time tracker score `86/91` was stale pre-research context. Current target metadata and current tracker state are `92/94`, combined `93.0`, false/non-emitting. The remaining score cap reflects unavailable original private symbols, compiler switches, and original lexical choices, not unresolved behavior or source placement.

The supervisor accepted the exact pre-callback artifact SHA256 `518B320EB44015D96A48C5C54D8812E4B1EC6227AF2AC2C5DC84568DF7752E09` at Gate 1 `33/33`. During the accepted implementation callback, B006 physically reread the target, all eleven ordinary claim-bearing support destinations, and the supporting ignored-item ledger. Every accepted ordinary fact was already present at the same or greater detail, so no ordinary destination required an activity-only edit or scoped validator run. Subsequent accepted B007/supervisor work additively advanced `by-file/IMEPanes.md` without contradicting the UID00031K conclusions; B006's repair-time reread records its current identity without claiming that external edit. The remaining IDA, manual coverage, generated/tracker, independent-verification, and lifecycle work is supervisor-owned and remains pending.

## Supporting Research

- Current target: `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`, SHA256 `30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E`, 12,506 bytes, 111 LF lines.
- Human-source destructor: `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`, SHA256 `B64D649DC5801EF12A3986610A872E4E0AEF822B3A812590829F06DCB46866D5`, 9,342 bytes, 91 LF lines.
- Class owner: `by-class/IMEPane.md`, SHA256 `544585FF4205BB8C6DE1F73F7950F3A3A868691BFB453BF17336E8A300286655`, 27,505 bytes, 185 LF lines.
- Source owner: `by-file/IMEPanes.md`, SHA256 `10412A9AE3FE9EC01034DA8CD9252FCE676C8501ED6847AB3AA41772DC9D2520`, 59,525 bytes, 214 LF lines. This additive identity was produced by later accepted B007/supervisor work; B006 only reread it.
- Mixed aggregate: `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md`, SHA256 `C6802376F4D32AA35F149F2C9004EDFA8F60058BE1ED6567633E45CCD3B9BA37`, 23,651 bytes, 133 LF lines.
- Adjustor-thunk index: `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md`, SHA256 `A40F27BAC822887F691C75C1915F704C9D9175C2AD401CEDBB19A13793CAEB22`, 13,834 bytes, 95 LF lines.
- Global owner: `by-global/g_pIMEPane.md`, SHA256 `5C536A062274538A511DE2743CBA247B2189C5FA26737075D1035B4CAA9A4080`, 6,406 bytes, 67 LF lines.
- Singleton storage: `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`, SHA256 `2C1830C724B3C1EC634C4490B16C36772F9230696B83E7540677D48F58EA4B2D`, 9,756 bytes, 105 LF lines.
- IME read-only data: `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md`, SHA256 `35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED`, 12,377 bytes, 131 LF lines.
- List teardown: `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`, SHA256 `705B1FF21EB473382ED33D64F7C181138135A1787BAA81EC6763DB7D4A575957`, 15,837 bytes, 131 LF lines.
- Focus setter: `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`, SHA256 `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB`, 9,034 bytes, 84 LF lines.
- Caret helper: `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md`, SHA256 `CB30D12CD845B9B4E0BF144DB1C055D662C1EB36C84C05812F33414DAD1F78CB`, 11,792 bytes, 120 LF lines.
- Ignored-item ledger: `by-memory/-ignored.md`, SHA256 `B1AD3EA699D5F7F480B4D603D2C2EAB34C058DA4E3FA868F17F9AADC92FC8827`, 1,127,552 bytes, 5,422 LF lines.

The active IDA snapshot used for this report was database `supervisor-uid0002OW-gate2b-20260813T0115Z` at canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. A fresh bounded `runtime_attestation` returned `ok:true` at `2026-08-13T01:51:29.403503+00:00`, route `127.0.0.1:64512`, worker PID `3544`, generation `pid:3544;created:134310578063549307`, and no errors. This identity is dated research provenance only; the supervisor must establish a fresh returned database identity before any Gate 2B readback.

Matching older reports were read only as historical corroboration: B006 direct reports SHA256 `BF55C7A853EF949ADFC477A846C431DC562A30C5EABC5553A678743CB4C284A6` and `2B66D6FCD9D8DFE67D36CDB4C01822B92AE625D45B42EBA5EE70595DC9E4DB35`, B008 family report `0CA4DCCEAEC01D430CFD46BECEDF073BA5671161130A18370AD52301E0DE4A6A`, B008 constructor report `D3A231727CD318E4B4347A01C42D80E7CA00A093EF361AB0375FD2F0CB47919C`, B011 ordinary-destructor report `2825AD92EA18829841AA3128CCE20C9CD9D126C2D956E5D717BFDECE1E453E1E`, and B004 sibling-wrapper report `0A56D403181C2348C6C0776B1367E28FD830F831187E743BAE531FAD3386E136`. Their useful facts were independently revalidated; old comment-only or proof-comment source substitutes are superseded by the current false/non-emitting blank-formal disposition.

## Target

- Primary UID: `00031K`.
- Physical document: `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`.
- Exact binary interval: `[0x004e8720,0x004e87f9)`, 217 bytes.
- Current source-facing binary identity: `IMEPane__ScalarDeletingDestructor`.
- Current IDA prototype: `IMEPane *__thiscall(IMEPane *this, unsigned int deletingFlags)`.
- Current classification: compiler-generated MSVC scalar-deleting destructor wrapper; class-owned evidence, no standalone human-source body.
- Assignment-time queue score: `86/91`, combined `88.5`, retained only as historical assignment context.
- Current target/tracker score: `92/94`, combined `93.0`.
- No additional target UID is declared. Support UIDs remain support scope rather than additional report targets.

## Current Target State

The target page is already at the recommended physical state: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `POSITION`, blank `RECONSTRUCTION_CPP`, blank `RECONSTRUCTION_H`, and `Nested:0`. It records the exact wrapper behavior and routes the sole human source to UID0004CB through class UID00006H and file UID0000K5.

The accepted implementation callback found no ordinary-document drift at callback time. A later accepted B007/supervisor update additively advanced only `by-file/IMEPanes.md` to SHA256 `10412A9AE3FE9EC01034DA8CD9252FCE676C8501ED6847AB3AA41772DC9D2520`, 59,525 bytes, 214 LF lines. B006's repair-time full-file reread confirms that the UID00031K source ownership, one-human-destructor route, and compiler-wrapper exclusion remain present at same-or-greater detail. All other ordinary target/support hashes remain those listed in Supporting Research. No ordinary by-* file was edited by B006. Consequently C31K-048 through C31K-059 remain evidence-backed validator exclusions: scoped validation is required after a B006 edit, but no such edit occurred and this reconciliation did not create activity-only validator work.

Live IDA currently models the target as a 217-byte function with 70 instructions, 15 basic blocks, cyclomatic complexity 3, the exact five-row frame, one function-regular explanatory comment, blank repeatable/address channels, and six blank historical internal regular-comment sites. Its body and boundaries are intact. No mutation is required or recommended.

Historical validator commands `000000022981`, `000000023008`, and tracker command `000000023014` remain dated superseded evidence; none is current authority. Supervisor command `000000023042` at `2026-08-13T01:06:08-04:00` is the dated repair-time generated/tracker snapshot. Physical B006 reread records `auto-generated/NexusTK/input/IMEPanes.cpp` SHA256 `DE5C5BBBA7D9CFCF6702E5ACB3E68B616E8593E85AFB5477124AD8AF57D36A97`, 17,076 bytes, 558 LF lines, and `IMEPanes.h` SHA256 `86B8CAC7B8D7816AC919136012882A1A185988F7A770C4CAF9E097075B83FB70`, 3,149 bytes, 118 LF lines. The CPP contains exactly one UID0004CB marker and exactly one `IMEPane::~IMEPane()` definition, with zero UID00031K markers/names/bodies and zero empty/placeholder markers; the H likewise contains no UID00031K or scalar-wrapper declaration.

The same dated command-23042 snapshot records `auto-generated/-ag-research-tracker.md` SHA256 `1C3C8716C6ED51E0DA0912FB5C75F61199F02921118362DBC3C1FB7718491A41`, 1,721,114 bytes, 6,765 LF lines. UID00031K is at physical line 5708 as `92/94`, combined `93.0`, `false`, with two historical B006 reports. A later repair-completion dynamic reread observed the shared tracker advance again to SHA256 `6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC`, 1,721,219 bytes, still 6,765 LF lines, while the exact UID00031K line-5708 semantics remained unchanged. No command provenance was supplied for that concurrent advance, so it is a physical current readback rather than replacement command authority or B006 credit. Command `23042` remains dated repair evidence only, not permanent future authority: every later Gate and mandatory post-move audit must physically reread and hash the then-current generated artifacts and tracker row. These supervisor-produced identities confer no B006 generated/tracker implementation credit.

## Executive Recommendation

Preserve UID00031K as exact compiler-wrapper evidence and do not emit it. Preserve UID0004CB as the only reconstructed `IMEPane::~IMEPane()` body and UID00006H as the sole class declaration owner. Preserve the primary and two adjustor vtable routes, `deletingFlags` ABI, body bytes, frame, xrefs, comments, and padding. Do not create a wrapper prototype or definition in source, do not add a separate `focusPaneCount` member, and do not substitute a proof comment for formal source.

The accepted implementation callback verified every B006-owned ordinary claim against the current physical destinations. All required detail was already present, no ordinary file was edited, and no scoped validator was applicable. Supervisor Gate 2A must independently verify the checked physical claims; Gate 2B should perform exact no-change readbacks rather than force mutations into already-correct IDA state.

## Supervisor Active Recheck

Supervisor Gate 1 accepted the exact pre-callback SHA256 `518B320EB44015D96A48C5C54D8812E4B1EC6227AF2AC2C5DC84568DF7752E09` at `33/33`; that dated acceptance authorized this ordinary implementation callback but does not pre-credit the changed report artifact. The current callback artifact requires a fresh exact-artifact audit. Gate 2A must physically reread every checked physical destination claim. Gate 2B must freshly attest the canonical IDB and confirm the structured no-change/protection rows below. Manual coverage and generated closure remain supervisor-owned operations in their fixed order. Report execution/archive state remains authoritative only from current path and validator-owned metadata/history.

## Inference Research Guidance Check

- Behavioral fidelity has priority: the wrapper's actual flag branches, teardown order, return value, and adjustment routes were recovered from bytes/disassembly and cross-checked with decompilation.
- Human source shape has priority over decompiler shape: the source is one ordinary virtual destructor, not a manually authored scalar-deleting wrapper with raw addresses or compiler intrinsics.
- Consistency is subordinate to evidence but satisfied here: the class/file family consistently uses `IMEPane`, `focusPaneList`, `g_pIMEPane`, and a virtual destructor.
- Unknown private compiler labels are not preserved as `sub_` names in source. The descriptive IDA wrapper identity is retained only as reverse-engineering metadata.
- No original symbol or source spelling was invented. The source-facing destructor spelling follows the C++ class contract and exact ordinary body.
- The practical blockers named by the assignment were resolved: final wrapper name, ABI, flags, adjustors, source owner, emitter route, layout, formal channel disposition, score, and generated exclusion all have concrete evidence-backed outcomes.

## Heuristic / Inference Reanalysis And Validation

The raw body superficially resembles an independently source-bearing destructor because it repeats child cleanup, list teardown, singleton clearing, and base teardown. That interpretation fails under the complete evidence set. The function is reached from the primary deleting-destructor vtable slot and two fixed this-adjusting thunks; it accepts compiler flags; it conditionally calls allocation release; it has a size-carrying mask-`0x4` branch to a one-byte runtime no-op; and it duplicates the already-modeled ordinary destructor. These are canonical MSVC wrapper features, not a second developer-written destructor.

The `0x120` literal independently matches the live `IMEPane` UDT size. The complete-object `+0x110` access belongs to `focusPaneList.m_count` inside the embedded `0x14`-byte list object beginning at `+0x104`; it is not a separate `IMEPane::focusPaneCount` member. UID0004CC already reflects the correct human expression `focusPaneList.GetCount()`.

The decompiler hides the mask-`0x4` no-free path because its callee is a one-byte guard/no-op function. Disassembly remains authoritative: when bit 1 is set and bit 4 is clear, the wrapper calls the project delete wrapper; when bit 4 is set, it passes `0x120` and the object to the no-op path and does not free storage. This distinction is retained in documentation but omitted from human source because the compiler regenerates it.

The score was not left at assignment-time `86/91`. Complete behavioral and routing closure, current IDA semantics, exact boundaries/hashes, formal no-code proof, correct owner/emitter exclusion, and generated absence justify `92/94`. A higher score would overstate unavailable original compiler/private-symbol evidence.

## Evidence Standards Used

1. Exact live IDA MCP bytes, item/function models, types, frame rows, comments, xrefs, disassembly, decompilation, UDTs, and data cells.
2. Exact physical by-* metadata/formal channels and SHA256 identities.
3. Cross-page ownership and emitter routing through target, ordinary destructor, class, source file, aggregate, adjustors, singleton, list, and read-only data.
4. Manual coverage rows physically read from all affected categories.
5. Generated C++/H and tracker files treated as read-only validator-owned evidence with command/hash identity.
6. Older reports used only as leads, then accepted, corrected, superseded, or excluded against current evidence.
7. Negative searches for ordinary callers, standalone source need, extra member need, target generated markers, and a second human destructor.

## Evidence Checked

- `idb_list` and `runtime_attestation` returned a healthy canonical database identity and bounded live reads succeeded.
- Target `get_bytes`, `inspect_items`, `function_inspect`, `decompile`, disassembly, xref, comment, and frame reads agreed on `[0x004e8720,0x004e87f9)`.
- Preceding and succeeding alignment bytes were read separately and hashed.
- Both adjustor thunks were independently inspected for bytes, type, frame, comments, and tail-jump target.
- Vtable cells `0x0061c4fc`, `0x0061c548`, and `0x0061c578` and all constructor/ordinary-destructor/wrapper writes were read.
- `IMEPane` and `IMEPaneFocusList` UDTs were inspected, including exact sizes and nested list-count offset.
- `g_pIMEPane` storage/type/value and all 17 xrefs were checked.
- The ordinary destructor was independently decompiled and its callee set compared to the wrapper.
- All twelve named support documents and four manual coverage files were physically read.
- Generated IMEPanes CPP/H and tracker state were physically read and hashed; UID00031K generated absence was searched directly.
- Matching historical reports were reconciled one by one; none was treated as current implementation credit.
- The initial report-only phase was read-only: no IDA mutation, by-* edit, manual coverage edit, validator, generated edit, lifecycle command, or report execution occurred.
- The accepted callback physically reread every ordinary destination and its formal channels. All accepted facts remained present at the exact Supporting Research hashes, so no by-* edit or scoped validator was applicable. No IDA, manual coverage, generated/tracker, lifecycle, or report-execution operation was performed by B006.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|
| C31K-001 | 00031K | Exact target interval is [0x004e8720,0x004e87f9), 217 bytes. | exact | Live bytes/function model and target metadata. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Item Summary and Address Range | already-present | already-present |
| C31K-002 | 00031K | Target is a compiler-generated scalar-deleting wrapper, not a standalone human-source function. | very-strong | Flags ABI, allocation branch, vtable routes, duplicate ordinary teardown. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Item Summary and Reconstruction Notes | already-present | already-present |
| C31K-003 | 00031K | Body SHA256 is 01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4; predecessor padding SHA256 is 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943; successor padding SHA256 is F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D. | exact | Fresh MCP bytes and bounded hashes. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Binary Evidence | already-present | already-present |
| C31K-004 | 00031K | Inbound refs are code 0x004e860e, code 0x004e8619, and data 0x0061c4fc; ordinary callers are zero. | exact | Fresh xref and caller reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Xrefs and Routing | already-present | already-present |
| C31K-005 | 00031K | Wrapper marks three child panes, tears down focusPaneList, clears g_pIMEPane, calls Pane teardown, and conditionally releases storage. | exact | Disassembly/decompile and callee set. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Behavior | already-present | already-present |
| C31K-006 | 00031K | deletingFlags bit 1 selects delete; bit 4 carries size 0x120 through the one-byte no-free path. | exact | Branch-level disassembly. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / ABI and Flags | already-present | already-present |
| C31K-007 | 00031K | Current name/type/frame/comment state is source-quality IDA metadata and all six interior regular/repeatable comment channels are blank. | exact | Fresh item/type/frame/comment reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA State | already-present | already-present |
| C31K-008 | 00031K | Current target metadata is 92/94; assignment-time 86/91 is historical. | exact | Target metadata plus dated tracker snapshots; every Gate requires a fresh tracker reread. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Metadata and Score Rationale | already-present | already-present |
| C31K-009 | 00031K | Preserve owner 00006H, reconstructable false, blank emitter, blank CPP/H, Nested:0. | exact | Source-form and ownership proof. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Metadata and Formal Channels | already-present | already-present |
| C31K-010 | 0004CB | UID0004CB is the sole human-source IMEPane destructor body. | very-strong | Ordinary destructor lacks wrapper flags/free logic and matches source cleanup. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / Item Summary and formal CPP | already-present | already-present |
| C31K-011 | 0004CB | Ordinary destructor marks statusPane, activeChildPane, and candidatePane, relies on List teardown, clears g_pIMEPane, and transfers to Pane teardown. | exact | Fresh decompile/callee comparison. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / Behavior | already-present | already-present |
| C31K-012 | 00006H | Class declaration owns virtual ~IMEPane() and one List focusPaneList, not a separate focusPaneCount field. | very-strong | UDT layout, UID0004CC, class H. | by-class/IMEPane.md / RECONSTRUCTION_H CODE and Layout | already-present | already-present |
| C31K-013 | 00006H | IMEPane size is 0x120 with focusPaneList at +0x104 and nested m_count at complete +0x110. | exact | Live UDTs and SetFocusPane behavior. | by-class/IMEPane.md / Layout and Evidence | already-present | already-present |
| C31K-014 | 0000K5 | IMEPanes is the sole CPP/H source owner and excludes UID00031K from emission. | very-strong | Owner/emitter chain and generated output. | by-file/IMEPanes.md / Source Inventory and Compiler Exclusions | already-present | already-present |
| C31K-015 | 00018C | Mixed aggregate records UID00031K as class-owned compiler evidence routed to UID0004CB. | very-strong | Aggregate inventory and exact children. | by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md / Item Summary | already-present | already-present |
| C31K-016 | 00018D | Adjustor roots [0x004e8608,0x004e8613) and [0x004e8613,0x004e861e) subtract 0xa0/0xa4 and tail-jump to UID00031K. | exact | Fresh thunk bytes/disassembly. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / IMEPane Pair | already-present | already-present |
| C31K-017 | 00025J | Primary and two secondary vtable routes use 0x0061c4fc, 0x0061c548, and 0x0061c578. | exact | Live data values and xrefs. | by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md / IMEPane Vtable Entries | already-present | already-present |
| C31K-018 | 0000R7 | g_pIMEPane has one human-source definition under IMEPanes and is cleared by the ordinary destructor. | very-strong | Global owner and source route. | by-global/g_pIMEPane.md / Ownership and formal CPP/H | already-present | already-present |
| C31K-019 | 0001PS | Physical singleton slot 0x0069b458 is typed IMEPane *, currently zero, with 17 exact xrefs. | exact | Live item/type/value/xref reads. | by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md / Item Summary and Xrefs | already-present | already-present |
| C31K-020 | 000192 | List teardown at 0x004f30e0 owns embedded-list destruction reached by both destructors. | very-strong | Callee identity and class layout. | by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md / Caller Context | already-present | already-present |
| C31K-021 | 0004CC | Complete-object +0x110 is focusPaneList.m_count, expressed through focusPaneList.GetCount(), not a second IMEPane field. | very-strong | UDT and current formal C++. | by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md / Layout Interpretation | already-present | already-present |
| C31K-022 | 00031G | Focus-caret helper remains source-authored class behavior and does not alter destructor ownership. | strong | Class/file routing and helper body. | by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md / Ownership | already-present | already-present |
| C31K-023 | 00031K | Dated supervisor command 23042 emits UID0004CB exactly once and UID00031K zero times; commands 22981/23008 are older history, and every later Gate must reread generated output dynamically. | exact | Repair-time physical reread of command-23042 output found one UID0004CB marker, one ordinary destructor definition, and zero UID00031K marker/name/body/empty-marker output; no B006 generated credit. | by-file/IMEPanes.md / Generated Closure Evidence | incorporate | proposed |
| C31K-024 | 00031K | Dated command-23042 generated snapshot has IMEPanes.cpp SHA256 DE5C5BBBA7D9CFCF6702E5ACB3E68B616E8593E85AFB5477124AD8AF57D36A97, 17,076 bytes/558 lines, and IMEPanes.h SHA256 86B8CAC7B8D7816AC919136012882A1A185988F7A770C4CAF9E097075B83FB70, 3,149 bytes/118 lines; future authority requires fresh physical hashes. | exact | Physical readback of the supervisor command-23042 validator-owned files at repair time. | by-file/IMEPanes.md / Generated Closure Evidence | incorporate | proposed |
| C31K-025 | 00031K | Every Gate and mandatory post-move audit must physically reread UID00031K in the then-current tracker and recompute the full tracker hash; dated command-23042 snapshot and the later dynamic readback both record line 5708 at 92/94, 93.0, false/non-emitting. | exact | Command 23042 snapshot SHA256 1C3C8716C6ED51E0DA0912FB5C75F61199F02921118362DBC3C1FB7718491A41, 1,721,114 bytes/6,765 lines; later physical readback SHA256 6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC, 1,721,219 bytes/6,765 lines, with unchanged row and no new command attribution; command 23014 is superseded history. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Score Rationale | already-present | proposed |
| C31K-026 | 00031K | Older matching reports are corroboration only and confer no current implementation credit. | exact | Six identified historical report hashes. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Research History | historicalize | already-present |
| C31K-027 | 00031K | Old proof-comment/comment-only source substitutes are superseded by false/non-emitting blank formals. | very-strong | Current formal-channel rules and wrapper disposition. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Historical Assumptions | historicalize | already-present |
| C31K-028 | 00031K | Score remains below 100 only for unavailable original symbols/compiler switches/lexical source. | strong | All behavioral/source blockers resolved. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Score Rationale | already-present | already-present |
| C31K-029 | 00031K | No standalone declaration, prototype, emitter route, or source-order slot is appropriate for the wrapper. | very-strong | Compiler-generated ownership and duplicate-body proof. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Source Placement | already-present | already-present |
| C31K-030 | 00031K | Zero ordinary callers and exact vtable/thunk routes reject an ordinary helper interpretation. | exact | Caller/xref inventory. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Negative Evidence | already-present | already-present |
| C31K-031 | 00031K | Wrapper target has no recommended IDA mutation; preserve exact current name/type/frame/comments. | exact | Fresh source-quality current state. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | already-present | proposed |
| C31K-032 | 00031K | Gate 2B must freshly attest canonical session/path before readback. | exact | Runtime identity is ephemeral. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| C31K-033 | 00031K | Gate 2B must verify exact target function model and five-row frame without mutation. | exact | Fresh function/frame snapshot. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| C31K-034 | 00031K | Gate 2B must verify the six internal regular/repeatable comment pairs remain blank. | exact | Fresh comment reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| C31K-035 | 00018D | Gate 2B must preserve A0 adjustor name, raw thunk type/frame, comment, bytes, and tail jump. | exact | Fresh thunk inspection. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / IDA Recommendations | incorporate | proposed |
| C31K-036 | 00018D | Gate 2B must preserve A4 adjustor name, raw thunk type/frame, comment, bytes, and tail jump. | exact | Fresh thunk inspection. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / IDA Recommendations | incorporate | proposed |
| C31K-037 | 00031K | Gate 2B must protect exact three inbound refs and zero ordinary callers. | exact | Fresh xref/caller reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| C31K-038 | 00025J | Gate 2B must protect three vtable cells and their three-write topologies. | exact | Fresh data/xref reads. | by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md / IDA Recommendations | incorporate | proposed |
| C31K-039 | 00031K | Gate 2B must protect target/thunk/padding body hashes and exact bounds. | exact | Fresh byte hashes. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| C31K-040 | 00006H | Gate 2B must preserve IMEPane size 0x120 and nested list layout. | exact | Fresh UDT reads. | by-class/IMEPane.md / IDA Recommendations and Layout | incorporate | proposed |
| C31K-041 | 0001PS | Gate 2B must preserve g_pIMEPane name/type/value and 17-xref topology. | exact | Fresh item/xref reads. | by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md / IDA Recommendations | incorporate | proposed |
| C31K-042 | 0004CB | Ordinary destructor remains source authority even though IDA retains sub_4E8000. | very-strong | Body/source ownership independent of current symbol. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / IDA Status | already-present | proposed |
| C31K-043 | 00031K | No IDA save is justified if all no-change readbacks pass. | exact | No mutation recommendation. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | not-applicable | proposed |
| C31K-044 | 00031K | Manual by-memory row must retain exact 92% compiler-wrapper/non-emitting text. | exact | Current row 1983. | by-memory/-coverage-report.md / UID00031K row | already-present | proposed |
| C31K-045 | 00006H | Manual by-class row must retain 91% class source and one-List/no-wrapper-emission text. | exact | Current row 259. | by-class/-coverage-report.md / UID00006H row | already-present | proposed |
| C31K-046 | 0000K5 | Manual by-file row must retain current 92% source-root, guarded-header/layout, ordinary-destructor, and compiler-wrapper exclusion text. | exact | Repair-time physical row 122 preserves and expands the accepted semantics at current SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756. | by-file/-coverage-report.md / UID0000K5 row | already-present | proposed |
| C31K-047 | 0000R7 | Manual by-global row must retain sole g_pIMEPane definition and 17-xref evidence. | exact | Current row 97. | by-global/-coverage-report.md / UID0000R7 row | already-present | proposed |
| C31K-048 | 00031K | Callback physical reread found the destination unchanged at SHA256 30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / whole document | not-applicable | excluded-with-reason |
| C31K-049 | 0004CB | Callback physical reread found the destination unchanged at SHA256 B64D649DC5801EF12A3986610A872E4E0AEF822B3A812590829F06DCB46866D5; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / whole document | not-applicable | excluded-with-reason |
| C31K-050 | 00006H | Callback physical reread found the destination unchanged at SHA256 544585FF4205BB8C6DE1F73F7950F3A3A868691BFB453BF17336E8A300286655; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-class/IMEPane.md / whole document | not-applicable | excluded-with-reason |
| C31K-051 | 0000K5 | Repair-time physical reread found the externally advanced destination at SHA256 10412A9AE3FE9EC01034DA8CD9252FCE676C8501ED6847AB3AA41772DC9D2520, 59,525 bytes/214 lines, with accepted UID00031K detail preserved; B006 made no edit and scoped validation was not applicable. | exact | Full-file reread attributes the additive drift to accepted B007/supervisor work and confirms same-or-greater source-owner/compiler-exclusion detail without B006 credit. | by-file/IMEPanes.md / whole document | not-applicable | excluded-with-reason |
| C31K-052 | 00018C | Callback physical reread found the destination unchanged at SHA256 C6802376F4D32AA35F149F2C9004EDFA8F60058BE1ED6567633E45CCD3B9BA37; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md / whole document | not-applicable | excluded-with-reason |
| C31K-053 | 00018D | Callback physical reread found the destination unchanged at SHA256 A40F27BAC822887F691C75C1915F704C9D9175C2AD401CEDBB19A13793CAEB22; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / whole document | not-applicable | excluded-with-reason |
| C31K-054 | 0000R7 | Callback physical reread found the destination unchanged at SHA256 5C536A062274538A511DE2743CBA247B2189C5FA26737075D1035B4CAA9A4080; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-global/g_pIMEPane.md / whole document | not-applicable | excluded-with-reason |
| C31K-055 | 0001PS | Callback physical reread found the destination unchanged at SHA256 2C1830C724B3C1EC634C4490B16C36772F9230696B83E7540677D48F58EA4B2D; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md / whole document | not-applicable | excluded-with-reason |
| C31K-056 | 00025J | Callback physical reread found the destination unchanged at SHA256 35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md / whole document | not-applicable | excluded-with-reason |
| C31K-057 | 000192 | Callback physical reread found the destination unchanged at SHA256 705B1FF21EB473382ED33D64F7C181138135A1787BAA81EC6763DB7D4A575957; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md / whole document | not-applicable | excluded-with-reason |
| C31K-058 | 0004CC | Callback physical reread found the destination unchanged at SHA256 128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md / whole document | not-applicable | excluded-with-reason |
| C31K-059 | 00031G | Callback physical reread found the destination unchanged at SHA256 CB30D12CD845B9B4E0BF144DB1C055D662C1EB36C84C05812F33414DAD1F78CB; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md / whole document | not-applicable | excluded-with-reason |
| C31K-060 | 00031K | Supervisor Gate 2A must independently verify all accepted physical-destination claims. | exact | Fixed workflow gate. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / implementation verification record | incorporate | proposed |
| C31K-061 | 00031K | Supervisor Gate 2B must independently complete exact no-change IDA readbacks. | exact | Fixed workflow gate and Section 21. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA verification record | incorporate | proposed |
| C31K-062 | 00031K | Supervisor must verify manual coverage rows after ordinary callback. | exact | Manual files are supervisor-owned. | by-memory/-coverage-report.md / UID00031K and named support rows | incorporate | proposed |
| C31K-063 | 00031K | Supervisor command 23042 provides the dated repair-time generated/tracker snapshot with one UID0004CB destructor and zero UID00031K output; the tracker later drifted physically without semantic row drift, so later Gates must dynamically reread or refresh before lifecycle action. | exact | Supervisor command 000000023042 at 2026-08-13T01:06:08-04:00 plus later tracker SHA256 6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC physical readback; exact inventories reread by B006 without generated implementation credit. | by-file/IMEPanes.md / generated closure evidence | incorporate | proposed |
| C31K-064 | 00031K | Report execution/archive remains supervisor-only and validator-authoritative. | exact | Lifecycle boundary. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / lifecycle authority handoff | not-applicable | proposed |

## Positive Evidence Summary

- Exact compiler ABI: `this` plus `unsigned int deletingFlags`, conditional allocation release, and complete-size no-free branch.
- Exact source overlap: child marking, list teardown, singleton clear, and Pane teardown match UID0004CB.
- Exact routing: primary vtable slot plus fixed `-0xa0` and `-0xa4` adjustors.
- Exact class layout: 0x120-byte IMEPane with one 0x14-byte embedded list at +0x104.
- Exact source placement: class declaration and ordinary destructor emit through IMEPanes; wrapper does not.
- Exact generated behavior: ordinary destructor appears once and UID00031K appears zero times.
- Exact current documentation: target, support pages, manual coverage, and tracker agree on false/non-emitting ownership.

## IDA MCP Facts

| Entity | Exact dated read-only fact |
|---|---|
| Target function | `0x004e8720`, `IMEPane__ScalarDeletingDestructor`, `[0x004e8720,0x004e87f9)`, 217 bytes, 70 instructions, 15 blocks, complexity 3. |
| Target type | `IMEPane *__thiscall(IMEPane *this, unsigned int deletingFlags)`. |
| Target frame | `var_C@+0x8/4:_DWORD`; `var_4@+0x10/4:_DWORD`; `__saved_registers@+0x14/4:_DWORD`; `__return_address@+0x18/4:_UNKNOWN *`; `deletingFlags@+0x1c/4:unsigned int`. |
| Target hash | `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`. |
| Boundary padding | `[0x004e8715,0x004e8720)` eleven `CC`, SHA `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; `[0x004e87f9,0x004e8800)` seven `CC`, SHA `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`. |
| Target comments | Exact function-regular compiler-wrapper explanation; function-repeatable/address-regular/address-repeatable blank. |
| Interior comments | Both regular and repeatable blank at `0x004e8739`, `0x004e8745`, `0x004e8775`, `0x004e8784`, `0x004e879e`, `0x004e87ba`. |
| Inbound refs | Code `0x004e860e`, code `0x004e8619`, data `0x0061c4fc`; zero ordinary callers. |
| Callees | `Pane_MarkForDeletion`, `sub_4F30E0` List teardown, `Pane__Destructor`, `NexusTK_operator_delete_wrapper`, one-byte `@_guard_check_icall_nop@4`. |
| Adjustor A0 | `0x004e8608`, 11 bytes, SHA `702705A90951161A7FFC21F6E48D17984FBE49A12CD7A37B27B262F64D722EDC`, subtract 0xa0 then tail-jump. |
| Adjustor A4 | `0x004e8613`, 11 bytes, SHA `6531CE528E8ED8EF8B291BD45BFC7100177444F946717FDAC45139DF08BC405A`, subtract 0xa4 then tail-jump. |
| Vtable cells | `0x0061c4fc -> 0x004e8720`, `0x0061c548 -> 0x004e8608`, `0x0061c578 -> 0x004e8613`. |
| IMEPane UDT | 288 bytes; `_paneBase +0`, children +f8/+fc/+100, `focusPaneList +104` size 20, caret Y/X +118/+11c. |
| List UDT | 20 bytes; `_listState +0` size 12, `focusPaneCount +c` int, `_listTail +10` size 4. |
| Singleton | `0x0069b458`, name `g_pIMEPane`, type `IMEPane *`, value zero, 17 exact xrefs. |

## Function / Child Inventory

| Address | Role | Human-source disposition |
|---|---|---|
| `0x004e8000` | Ordinary IMEPane destructor, 152 bytes. | Sole source body `IMEPane::~IMEPane()`. |
| `0x004e8608` | Secondary-view deleting-destructor adjustor, subtracts 0xa0. | Compiler thunk; no source body. |
| `0x004e8613` | Tertiary-view deleting-destructor adjustor, subtracts 0xa4. | Compiler thunk; no source body. |
| `0x004e8720` | Complete-object scalar-deleting wrapper, 217 bytes. | Compiler wrapper; no source body/declaration/emitter. |
| `0x00544690` | Pane deferred-deletion marker. | Existing Pane source support. |
| `0x004f30e0` | Embedded List teardown. | Existing List source support. |
| `0x00544580` | Base Pane destructor. | Existing Pane source support. |
| `0x004f4ac0` | Project allocation-release wrapper. | Compiler/runtime support, not handwritten here. |
| `0x0041b6a0` | One-byte no-op/guard target on mask-0x4 path. | Compiler/runtime support, not handwritten here. |

The inventory is exhaustive for the target body and its direct wrapper/source relationship. There is no raw helper, data island, second ordinary body, missing child, or omitted source-bearing fragment inside the exact target range.

## Direct Xref / Caller Inventory

- `0x004e860e -> 0x004e8720`: tail jump from the `-0xa0` adjustor.
- `0x004e8619 -> 0x004e8720`: tail jump from the `-0xa4` adjustor.
- `0x0061c4fc -> 0x004e8720`: primary deleting-destructor vtable entry.
- Ordinary code callers: zero.
- Vtable cell `0x0061c4fc` is written by constructor `0x004e7f87`, ordinary destructor `0x004e802b`, and wrapper `0x004e8752`.
- Vtable cell `0x0061c548` is written by `0x004e7f8d`, `0x004e8031`, and `0x004e8758`.
- Vtable cell `0x0061c578` is written by `0x004e7f97`, `0x004e803b`, and `0x004e8762`.
- The complete `g_pIMEPane` xref set is `0x4e74b0`, `0x4e7689`, `0x4e77c2`, `0x4e77d3`, `0x4e7a83`, `0x4e7c46`, `0x4e7f68`, `0x4e7f6f`, `0x4e8079`, `0x4e8391`, `0x4e85b0`, `0x4e87a0`, `0x4f64ac`, `0x58e0d0`, `0x58e1ff`, `0x58ead2`, `0x59545a`.

## Documentation Evidence And IDA Status

The ordinary documentation is mutually consistent at report time. The target page is detailed and non-emitting; UID0004CB supplies the source body; UID00006H supplies the class declaration and one-List layout; UID0000K5 supplies file ownership; UID00018C/UID00018D classify wrappers and adjustors; UID00025J records vtable data; UID0000R7/UID0001PS cover the singleton; UID0004CC rejects the extra-member interpretation; UID00031G remains independent source-authored class behavior. Later accepted B007/supervisor additions expanded `by-file/IMEPanes.md` but preserved these UID00031K facts.

The callback full-file reread reconfirmed that same ordinary state without drift at callback time. The repair-time reread reconfirmed all ordinary identities in Supporting Research except the explicitly attributed additive B007/supervisor advance of `by-file/IMEPanes.md`; that current file still contains the accepted source-owner and compiler-wrapper exclusion detail. The supporting ignored-item ledger remains byte-identical. These rereads provide only B006 ordinary claim verification and no credit for the external by-file edit, independent Gate 2A, IDA, manual coverage, generated/tracker, or lifecycle work.

The live IDA state is also internally consistent. The target and adjustors already have useful source-quality names/comments, while the adjustor physical prototype remains deliberately raw because the thunks are compiler-owned secondary views. The ordinary destructor remains `sub_4E8000` in current IDA; that symbol state does not change source ownership and is not part of this target's recommended mutation scope. No report claim depends on mutating or saving IDA.

Generated and tracker observations are dated validator-owned snapshots. They confirm current source routing but do not establish callback completion, Gate 2A credit, Gate 2B credit, manual coverage closure, or lifecycle completion.

## Ranked Ownership Analysis

1. **UID00006H IMEPane class owner: accepted.** The wrapper operates on the exact 0x120 class layout and restores its three view vtables.
2. **UID0004CB ordinary destructor as human-source owner: accepted.** It contains the developer-authored teardown once, without scalar-deleting ABI machinery.
3. **UID0000K5 IMEPanes file owner/emitter: accepted for source family, rejected as direct wrapper emitter.** It emits the class and ordinary body only.
4. **UID00018C aggregate and UID00018D adjustor index: accepted as binary indexes/support, rejected as source owners.**
5. **Standalone wrapper ownership/emission: rejected.** The compiler ABI, duplicate teardown, vtable-only routing, and generated absence provide direct negative proof.

## Source Placement

- Header: `IMEPanes.h` contains `virtual ~IMEPane();` inside `class IMEPane`, the one `List focusPaneList` member, and `extern IMEPane *g_pIMEPane;`.
- Source: `IMEPanes.cpp` contains one `IMEPane::~IMEPane()` definition through UID0004CB and one `g_pIMEPane` definition through UID0000R7.
- UID00031K: no CPP insertion, no H insertion, no emitter route, no source-order slot, and no comment-only pseudo-source.
- Adjustor thunks: no CPP/H insertion.
- Compiler-generated deleting flags, allocation release, mask-0x4 size path, and vtable restoration are regenerated by the compiler from the virtual destructor/class model.

## Range / Split / Padding / Reclassification Analysis

The target interval is already split correctly. Eleven `CC` bytes immediately precede it and seven `CC` bytes immediately follow it before the next modeled function. The two adjustors are separately modeled at `[0x004e8608,0x004e8613)` and `[0x004e8613,0x004e861e)`. The target contains one complete wrapper body and no embedded data or independently source-bearing child.

No merge with UID0004CB is appropriate because the ordinary destructor and deleting wrapper are distinct binary functions with different ABI responsibilities. No additional split is appropriate because all 217 bytes participate in one compiler wrapper. Reclassification from assignment-time reconstructable queue context to current `RECONSTRUCTABLE:FALSE` is evidence-backed and already physically represented.

## Negative Evidence Summary

- No ordinary code caller reaches UID00031K.
- No second handwritten destructor is needed to explain any branch or teardown action.
- No independent source symbol, declaration, emitter route, or generated marker exists for UID00031K.
- No separate `IMEPane::focusPaneCount` field exists; +0x110 is nested list state.
- No target-range raw helper, data island, unmodeled child, or unresolved boundary remains.
- No IDA name/type/comment defect remains that justifies mutation.
- No source-quality score blocker remains beyond unavailable original symbols/compiler switches/lexical evidence.
- Old proof-comment and wrapper-body suggestions are not current authority and are retained only as superseded history.

## IDA Rename / Type / Comment Recommendations

The recommendation is **NO_CHANGE with exact protected readback**. No rename, type, frame, comment, item-normalization, or save action is proposed.

| Step | Entity/address | Literal dated prestate | Proposed disposition | Protected state and expected readback | Evidence/confidence |
|---|---|---|---|---|---|
| A00 | Canonical runtime | Dated research session `supervisor-uid0002OW-gate2b-20260813T0115Z`, canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. | Freshly call `idb_list`, server health, and `runtime_attestation` with the expected canonical path; bind every readback to the exact database identifier returned by that fresh attestation. | Attestation `ok:true`, exact path/session returned, bounded read succeeds, empty errors. The dated B006 session is provenance only. | Mandatory fail-closed session authority; exact. |
| A01 | `0x004e8720` | Function `IMEPane__ScalarDeletingDestructor`, range `[0x004e8720,0x004e87f9)`, type `IMEPane *__thiscall(IMEPane *this, unsigned int deletingFlags)`; frame is exactly `var_C@+0x8/4:_DWORD`, `var_4@+0x10/4:_DWORD`, `__saved_registers@+0x14/4:_DWORD`, `__return_address@+0x18/4:_UNKNOWN *`, and `deletingFlags@+0x1c/4:unsigned int`. | NO_CHANGE. | Same name, range, type, and all five literal frame rows with no additional, missing, renamed, retyped, resized, or moved row. | Current state is source-quality binary metadata; exact. |
| A02 | `0x004e8720` comments | Function-regular is exactly `Compiler-generated IMEPane scalar deleting destructor: repeats UID0004CB child-pane, focus-list, singleton, and Pane teardown; frees storage only when deletingFlags mask 0x1 is set and mask 0x4 is clear; carries complete-object size 0x120 on the mask-0x4 one-byte runtime no-op path. Human source is virtual IMEPane::~IMEPane(); do not hand-author this wrapper.` Function-repeatable is absent; address-regular is absent; address-repeatable is absent. | NO_CHANGE. | Function-regular reproduces the complete literal text byte-for-byte; function-repeatable, address-regular, and address-repeatable each read absent independently. | Comment accurately states behavior/source disposition; exact. |
| A03 | Six interior addresses | Regular/repeatable both blank at `0x004e8739`, `0x004e8745`, `0x004e8775`, `0x004e8784`, `0x004e879e`, `0x004e87ba`. | NO_CHANGE. | All twelve channel reads remain blank. | Stale decompiler-variable comments are absent; exact. |
| A04 | `0x004e8608` | Function `IMEPane__ScalarDeletingDestructorAdjustorA0`, range `[0x004e8608,0x004e8613)`, 11 bytes, type `_DWORD *__thiscall(_DWORD *this, char)`, frame only `__return_address@+0x0/4:_UNKNOWN *`. Function-regular is exactly `Compiler-generated IMEPane deleting-destructor adjustor; subtracts 0xa0 from the secondary-view this pointer and tail-jumps to the complete-object scalar deleting entry at 0x004e8720. No handwritten source body.` Function-repeatable, address-regular, and address-repeatable are each absent. | NO_CHANGE. | Same name/type/sole frame row; function-regular reproduces the complete literal text byte-for-byte; the other three comment channels each remain absent; SHA256 `702705A90951161A7FFC21F6E48D17984FBE49A12CD7A37B27B262F64D722EDC`; exact `sub ecx,0xa0` then jump to `0x004e8720`. | Raw thunk signature is compiler-view metadata; inventing a class signature would weaken evidence. |
| A05 | `0x004e8613` | Function `IMEPane__ScalarDeletingDestructorAdjustorA4`, range `[0x004e8613,0x004e861e)`, 11 bytes, type `_DWORD *__thiscall(_DWORD *this, char)`, frame only `__return_address@+0x0/4:_UNKNOWN *`. Function-regular is exactly `Compiler-generated IMEPane deleting-destructor adjustor; subtracts 0xa4 from the tertiary-view this pointer and tail-jumps to the complete-object scalar deleting entry at 0x004e8720. No handwritten source body.` Function-repeatable, address-regular, and address-repeatable are each absent. | NO_CHANGE. | Same name/type/sole frame row; function-regular reproduces the complete literal text byte-for-byte; the other three comment channels each remain absent; SHA256 `6531CE528E8ED8EF8B291BD45BFC7100177444F946717FDAC45139DF08BC405A`; exact `sub ecx,0xa4` then jump to `0x004e8720`. | Same rationale as A04. |
| P01 | Target topology | Inbound refs code `0x004e860e`, code `0x004e8619`, data `0x0061c4fc`; zero callers. | PROTECT. | Exact three-ref set and zero caller set unchanged. | Defines compiler routing; exact. |
| P02 | Vtable cells | Primary cell `0x0061c4fc`, name `??_7IMEPane@@6B@`, value `0x004e8720`, write refs `0x004e7f87`, `0x004e802b`, `0x004e8752`; secondary cell `0x0061c548`, name `??_7IMEPane@@6B@_0`, value `0x004e8608`, write refs `0x004e7f8d`, `0x004e8031`, `0x004e8758`; tertiary cell `0x0061c578`, name `??_7IMEPane@@6B@_1`, value `0x004e8613`, write refs `0x004e7f97`, `0x004e803b`, `0x004e8762`. | PROTECT. | Each cell independently retains its literal address, name, value, and exact three-reference set; all nine write-reference addresses remain exactly as listed and no table/data/type/comment mutation occurs. | Three-view destructor topology; exact. |
| P03 | Bytes/bounds | Target `[0x004e8720,0x004e87f9)` SHA256 `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`; A0 `[0x004e8608,0x004e8613)` SHA256 `702705A90951161A7FFC21F6E48D17984FBE49A12CD7A37B27B262F64D722EDC`; A4 `[0x004e8613,0x004e861e)` SHA256 `6531CE528E8ED8EF8B291BD45BFC7100177444F946717FDAC45139DF08BC405A`; predecessor padding `[0x004e8715,0x004e8720)` SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; successor padding `[0x004e87f9,0x004e8800)` SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`. | PROTECT. | All five ranges, item heads, byte counts, full 64-hex hashes, and alignment-byte identities reproduce exactly. | Prevents accidental reanalysis drift; exact. |
| P04A | `IMEPane` UDT | Type `IMEPane`, UDT ordinal 674, size `0x120`; members are `_paneBase@+0x0/0xf8`, `statusPane@+0xf8/4`, `activeChildPane@+0xfc/4`, `candidatePane@+0x100/4`, `focusPaneList@+0x104/0x14`, `focusCaretAnchorY@+0x118/4`, and `focusCaretAnchorX@+0x11c/4`. | PROTECT. | Type name/kind/ordinal/size and all seven literal member names, offsets, and widths read back independently with no additional, missing, moved, or resized member. | Complete-object layout and 0x120 deleting-wrapper size agree; exact. |
| P04B | `IMEPaneFocusList` UDT | Type `IMEPaneFocusList`, UDT ordinal 673, size `0x14`; projected members are opaque `_listState@+0x0/0xc`, `focusPaneCount@+0xc/4:int`, and opaque `_listTail@+0x10/4`. The projected count is source-facing `focusPaneList.m_count`, not a separate IMEPane member. | PROTECT. | Type name/kind/ordinal/size and all three literal member names, offsets, widths, plus `focusPaneCount` type `int`, read back independently; source interpretation remains one complete `List`. | Embedded-list projection and source layout agree; exact. |
| P04C | `0x0069b458` singleton item | Entity name `g_pIMEPane`; item type `IMEPane *`; value `0x00000000`; `entity_query` supplies the name while `inspect_items` exposes a one-byte projection with blank item name. Exact data xrefs are `0x004e74b0`, `0x004e7689`, `0x004e77c2`, `0x004e77d3`, `0x004e7a83`, `0x004e7c46`, `0x004e7f68`, `0x004e7f6f`, `0x004e8079`, `0x004e8391`, `0x004e85b0`, `0x004e87a0`, `0x004f64ac`, `0x0058e0d0`, `0x0058e1ff`, `0x0058ead2`, and `0x0059545a`. | PROTECT. | Entity and item views independently retain the literal address/name-projection distinction, type, zero value, and exact 17-address xref set; no global/item/type/comment mutation occurs. | Singleton identity, value, and topology; exact. |

Deterministic order is A00, A01, A02, A03, A04, A05, P01, P02, P03, P04A, P04B, P04C. Every step is read-only. Any mismatch stops Gate 2B and returns the exact drift to this report; no mutation or save is authorized by this handoff.

## First-Draft C++ Recommendation

**Target UID00031K formal CPP disposition:** blank. The compiler must generate the scalar-deleting wrapper; inserting any body would duplicate ABI machinery.

**Target UID00031K formal H disposition:** blank. The class declaration already owns the only required source declaration.

The following owner-source body is the exact source-facing reconstruction that explains UID0004CB and causes compiler generation of UID00031K. It belongs only in UID0004CB's formal CPP channel, where it is already present:

```cpp
IMEPane::~IMEPane()
{
    if (statusPane != NULL) {
        statusPane->MarkForDeletion();
    }

    if (activeChildPane != NULL) {
        activeChildPane->MarkForDeletion();
    }

    if (candidatePane != NULL) {
        candidatePane->MarkForDeletion();
    }

    g_pIMEPane = NULL;
}
```

The required owner declaration belongs only in UID00006H's formal H channel, where it is already present:

```cpp
virtual ~IMEPane();
```

The omitted explicit `focusPaneList` and base cleanup are normal C++ member/base destruction semantics. The compiler inserts them after the body. The compiler also generates vtable restoration, deleting flags, allocation release, adjustor thunks, and the complete-object-size branch. None belongs in handwritten NexusTK source.

## Final Recommendation

Keep UID00031K at `92/94`, class-owned by UID00006H, false/non-emitting, blank CPP/H, and `Nested:0`. Keep UID0004CB as the sole destructor body and UID0000K5 as file owner. Preserve one embedded List, the nested +0x110 count interpretation, the three vtable routes, the two adjustors, exact target ABI, comments, bytes, frame, xrefs, and boundary padding. Treat all historical attempts to emit or pseudo-emit this wrapper as superseded.

The accepted callback made no activity-only edits: each ordinary destination was physically reread and the accepted detail was already present at the recorded hash. No ordinary validator was applicable because no ordinary file changed. Supervisor now independently verifies the checked physical claims, manual coverage, current generated exclusion, and exact no-change IDA state before any lifecycle action.

## Recommended Target Doc Changes

The accepted callback physically verified that the target still contains all of the following at report-level detail:

- Exact interval, body/padding hashes, item boundaries, name, type, frame, and comments.
- Complete teardown call flow and exact flag semantics.
- Exact inbound routes, vtable cells, adjustors, and no ordinary callers.
- UID0004CB sole-source relationship and compiler-generated/no-emitter rationale.
- `92/94`, owner `00006H`, `RECONSTRUCTABLE:FALSE`, blank emitter/CPP/H, `Nested:0`.
- Historical assignment score and obsolete proof-comment/body ideas labeled superseded if retained.

All remained present at the accepted SHA256, so the target was recorded `already-present` without rewriting or an activity-only validator.

## Recommended Support Doc Changes

The accepted callback independently verified:

- UID0004CB: sole ordinary body and exact cleanup behavior/formal CPP.
- UID00006H: virtual destructor declaration, one List member, coherent 0x120 layout/formal H.
- UID0000K5: source ownership and explicit compiler-wrapper exclusion.
- UID00018C/UID00018D: full wrapper/adjustor index and exact A0/A4 roots.
- UID00025J: three vtable cells and constructor/destructor/wrapper restoration topology.
- UID0000R7/UID0001PS: sole global source route and exact physical slot/xrefs.
- UID000192: embedded List teardown route.
- UID0004CC: nested list count, not a separate IMEPane field.
- UID00031G: independent source-authored class helper placement.

All support detail remained present at the accepted hashes; no support edit or activity-only validator was required. No separate wrapper declaration/body, duplicate emitter, or new support page is recommended.

## Score And Metadata Recommendation

| Field | Historical assignment context | Current recommendation | Rationale |
|---|---:|---:|---|
| COMPLETION | 86 | 92 | Behavior, ABI, routes, ranges, ownership, source form, formals, and generated exclusion are complete. |
| CONFIDENCE | 91 | 94 | Multiple independent exact evidence routes agree; only unavailable original private/compiler lexical evidence remains. |
| CANONICAL_OWNER | unresolved in queue context | 00006H | Exact class layout/vtable/destructor ownership. |
| RECONSTRUCTABLE | queue labeled reconstructable | FALSE | Compiler wrapper is not standalone human source. |
| EMITTER_UIDS | not resolved | blank | Emitting it would duplicate compiler output. |
| Nested | not emphasized | 0 | Complete independent binary wrapper page, not a nested source child. |
| Formal CPP/H | unresolved | both blank | Sole body/declaration live under UID0004CB/UID00006H. |

Reason not higher: no original PDB/private compiler symbols, exact historical compiler switches, or original developer lexical choices survive. Those rare unknowns do not justify raw names or source duplication.

Reason not lower: exact bytes, boundaries, frame, type, flag branches, callees, xrefs, vtable routes, UDT layout, ordinary-body overlap, owner/emitter route, manual coverage, and generated exclusion are all independently established.

## Open Questions With Attempted Resolution

- **Was the wrapper handwritten?** Resolved no. Compiler flags, conditional delete, complete-size branch, adjustors, vtable-only routing, and duplicate ordinary teardown are conclusive.
- **Should `IMEPane__ScalarDeletingDestructor` become source?** Resolved no. It is a useful IDA binary name only; source remains `virtual ~IMEPane()` plus one ordinary body.
- **Is +0x110 a separate field?** Resolved no. UDT and UID0004CC prove nested `focusPaneList.m_count`.
- **Should adjustor raw types be prettified?** Resolved no-change. Their physical secondary-view signature is compiler metadata and no deterministic source-facing thunk prototype improves source reconstruction.
- **Does the mask-0x4 path free storage?** Resolved no. Disassembly shows a one-byte runtime/no-op route with size 0x120 and no delete call.
- **Can score reach 100?** Not from current evidence. Missing original symbols/compiler switches/lexical provenance impose the remaining modest cap; all practical project blockers are resolved.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual rows are already exact and require supervisor verification rather than agent editing:

- `by-memory/-coverage-report.md` line 1983 records UID00031K as a 92% exact 217-byte class-owned MSVC wrapper, body SHA `01FD...FCFF4`, primary plus `-0xa0/-0xa4` routes, duplicate teardown, bit-1 delete, bit-4 0x120 no-free path, and blank formal C++.
- Line 1968 records UID0004CB as the 91% sole human destructor definition.
- Lines 1977/1980 record UID00018C/UID00018D as non-emitting aggregate/adjustor evidence.
- Line 4830 records UID0001PS singleton storage and 17 xrefs.
- `by-class/-coverage-report.md` line 259 records UID00006H at 91% with one exact List member and compiler-only UID00031K exclusion.
- `by-file/-coverage-report.md` line 122 records UID0000K5 at 92% with the guarded IMEPanes header/source root, exact sizes/layout, ordinary destructor routes, and all four scalar-wrapper exclusions. The earlier 91% wording is superseded history.
- `by-global/-coverage-report.md` line 97 records UID0000R7 at 90% as the sole source definition and 17-xref global owner.

Repair-time physical manual-coverage identities are dated snapshots, not permanent authority: by-memory SHA256 `BD69D1C1B92DD2840D1D91DA909725366B9538051472A91D25DF1EB884E98F1C`, by-class SHA256 `FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0`, by-file SHA256 `02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756`, and by-global SHA256 `B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A`. The UID00006H row remains line 259 at 91% with the exact one-List/UID00031K false-non-emitting semantics. The UID0000K5 row remains line 122 but is now 92%, with additive guarded-header/layout detail and the accepted ordinary-destructor/compiler-wrapper exclusions intact. B006 made no shared-file edit and claims no implementation or validation credit.

Dated historical receipts only: supervisor commands `000000022993` and `000000022994`, the then-recorded by-class SHA256 `68BBB4638AE94068BCFE822C8CF0538B418A6DFD6F52A211FAC9B504B4C6DEEC`, and the then-recorded by-file SHA256 `C3644FB199C7DE965A92AEA8FF02A581833670593B977E18AF5917FC87B6DC8F`. They are superseded identities, not current-state evidence. Every manual shared-file identity in this section is dated; every later Gate and mandatory post-move audit must physically reread the then-current files and named rows rather than promoting any recorded hash to permanent authority.

The tracker row requires no manual edit. Supervisor command `000000023042` supplies the dated repair-time snapshot recorded above; it remains validator-owned and must be dynamically reread, and coherently refreshed if stale, at every later Gate and mandatory post-move audit.

## Follow-Up Actions

1. Supervisor performs a fresh exact-artifact audit of this callback-updated report.
2. Supervisor performs independent Gate 2A against every checked physical claim.
3. Supervisor performs the Section 21 fresh-attestation no-change Gate 2B readback.
4. Supervisor verifies manual coverage and dynamically rereads the dated command-23042 generated/tracker snapshot, refreshing it coherently if later drift is present.
5. Supervisor alone controls report lifecycle/execution according to current path and validator metadata.

These are invariant role/order requirements, not a claim about current lifecycle status.

## Confidence

Overall confidence is `94/100` for the compiler-wrapper/no-emitter conclusion and `92/100` completion for the target documentation state. Exact behavior, ABI, topology, layout, source ownership, and generated exclusion are closed. The residual uncertainty is limited to unavailable original private symbols, historical compiler switches, and lexical source choices. It does not affect runtime reconstruction or the blank target CPP/H disposition.

## Validator Results

No validator was run in the initial report-only phase because no by-* file was edited. The accepted callback likewise changed zero ordinary by-* files, so C31K-048 through C31K-059 are evidence-backed `not-applicable` / `excluded-with-reason` dispositions rather than activity-only validator runs. Repair-time reread reconfirmed these exact hashes: target `30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E`; UID0004CB `B64D649DC5801EF12A3986610A872E4E0AEF822B3A812590829F06DCB46866D5`; UID00006H `544585FF4205BB8C6DE1F73F7950F3A3A868691BFB453BF17336E8A300286655`; externally advanced UID0000K5 `10412A9AE3FE9EC01034DA8CD9252FCE676C8501ED6847AB3AA41772DC9D2520`; UID00018C `C6802376F4D32AA35F149F2C9004EDFA8F60058BE1ED6567633E45CCD3B9BA37`; UID00018D `A40F27BAC822887F691C75C1915F704C9D9175C2AD401CEDBB19A13793CAEB22`; UID0000R7 `5C536A062274538A511DE2743CBA247B2189C5FA26737075D1035B4CAA9A4080`; UID0001PS `2C1830C724B3C1EC634C4490B16C36772F9230696B83E7540677D48F58EA4B2D`; UID00025J `35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED`; UID000192 `705B1FF21EB473382ED33D64F7C181138135A1787BAA81EC6763DB7D4A575957`; UID0004CC `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB`; UID00031G `CB30D12CD845B9B4E0BF144DB1C055D662C1EB36C84C05812F33414DAD1F78CB`. B007/supervisor produced the UID0000K5 drift; B006 made no ordinary edit and claims no validator credit. The supporting ignored ledger remained `B1AD3EA699D5F7F480B4D603D2C2EAB34C058DA4E3FA868F17F9AADC92FC8827`.

Commands `000000022981`, `000000023008`, and `000000023014` remain dated superseded generated/tracker history. Supervisor command `000000023042` at `2026-08-13T01:06:08-04:00` is the dated repair snapshot: IMEPanes.cpp SHA256 `DE5C5BBBA7D9CFCF6702E5ACB3E68B616E8593E85AFB5477124AD8AF57D36A97`, 17,076 bytes/558 lines; IMEPanes.h SHA256 `86B8CAC7B8D7816AC919136012882A1A185988F7A770C4CAF9E097075B83FB70`, 3,149 bytes/118 lines; tracker SHA256 `1C3C8716C6ED51E0DA0912FB5C75F61199F02921118362DBC3C1FB7718491A41`, 1,721,114 bytes/6,765 lines. Physical reread found exactly one UID0004CB marker and one ordinary destructor definition, zero UID00031K generated markers/names/bodies/empty markers, and tracker line 5708 at `92/94`, `93.0`, `false`. A later repair-completion reread found the shared tracker at SHA256 `6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC`, 1,721,219 bytes/6,765 lines, with that exact UID00031K row unchanged; no replacement command provenance is attributed. This supervisor/shared output confers no B006 generated/tracker credit and must be dynamically reread at every later Gate and mandatory post-move audit.

## Changed Files

- Updated only `tools/leaser/Agents/Agent-B006/research/00031K-IMEPaneScalarDeletingDestructor-source-quality.md` to record the accepted no-drift implementation callback.
- No target/support by-* file was changed by B006. Later accepted B007/supervisor work advanced `by-file/IMEPanes.md` to the current hash recorded above; every accepted UID00031K fact remains present.
- No manual coverage, generated, tracker, audit, goal, notes, validator registry, IDA, or lifecycle file changed.
- No sibling `-removed.md` companion was needed because the report contains no executable automation.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Read the current goal, project skill, workflow reference, and literal 33-section template.
- [x] Performed mandatory fresh read-only IDA MCP attestation and bounded target/support research.
- [x] Exhausted final-name, source-form, ABI, flags, adjustor, vtable, layout, owner, emitter, split, score, and C++ blockers.
- [x] Read target and every affected ordinary support destination.
- [x] Read exact manual coverage rows and dated generated/tracker snapshots without editing them; recorded the mandatory dynamic reread rule for every Gate and post-move audit.
- [x] Reconciled all matching prior reports as historical corroboration or superseded guidance.
- [x] Supplied target-specific blank CPP/H proof and exact owner-source CPP/H context.
- [x] Supplied structured non-executable IDA no-change/protection rows.
- [x] Confirmed third-party import is not applicable to this compiler-generated IME wrapper.
- [x] Resolved all practical open questions; only evidence-backed historical/compiler provenance limits remain.
- [x] Supervisor Gate 1 accepted exact SHA256 `518B320EB44015D96A48C5C54D8812E4B1EC6227AF2AC2C5DC84568DF7752E09` at `33/33` and authorized the callback.

Implementation callback pass:

- [x] Callback accepted for exact SHA256 `518B320EB44015D96A48C5C54D8812E4B1EC6227AF2AC2C5DC84568DF7752E09`.
- [x] Every ordinary physical destination claim was reread at full report detail and exact current hash.
- [x] No actual ordinary drift existed; no repair or activity-only edit was required.
- [x] Scoped validation was correctly not applicable because zero ordinary by-* files changed; all destinations were physically reread.
- [ ] Independent Gate 2A completed for every checked claim.
- [ ] Supervisor exact no-change Gate 2B completed.
- [ ] Supervisor manual coverage verification completed.
- [ ] Supervisor generated CPP/H and tracker closure completed.
- [ ] Supervisor lifecycle action completed only after all required gates.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|---|
| [x] | C31K-001 | 00031K | Exact target interval is [0x004e8720,0x004e87f9), 217 bytes. | exact | Live bytes/function model and target metadata. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Item Summary and Address Range | already-present | already-present |
| [x] | C31K-002 | 00031K | Target is a compiler-generated scalar-deleting wrapper, not a standalone human-source function. | very-strong | Flags ABI, allocation branch, vtable routes, duplicate ordinary teardown. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Item Summary and Reconstruction Notes | already-present | already-present |
| [x] | C31K-003 | 00031K | Body SHA256 is 01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4; predecessor padding SHA256 is 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943; successor padding SHA256 is F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D. | exact | Fresh MCP bytes and bounded hashes. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Binary Evidence | already-present | already-present |
| [x] | C31K-004 | 00031K | Inbound refs are code 0x004e860e, code 0x004e8619, and data 0x0061c4fc; ordinary callers are zero. | exact | Fresh xref and caller reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Xrefs and Routing | already-present | already-present |
| [x] | C31K-005 | 00031K | Wrapper marks three child panes, tears down focusPaneList, clears g_pIMEPane, calls Pane teardown, and conditionally releases storage. | exact | Disassembly/decompile and callee set. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Behavior | already-present | already-present |
| [x] | C31K-006 | 00031K | deletingFlags bit 1 selects delete; bit 4 carries size 0x120 through the one-byte no-free path. | exact | Branch-level disassembly. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / ABI and Flags | already-present | already-present |
| [x] | C31K-007 | 00031K | Current name/type/frame/comment state is source-quality IDA metadata and all six interior regular/repeatable comment channels are blank. | exact | Fresh item/type/frame/comment reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA State | already-present | already-present |
| [x] | C31K-008 | 00031K | Current target metadata is 92/94; assignment-time 86/91 is historical. | exact | Target metadata plus dated tracker snapshots; every Gate requires a fresh tracker reread. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Metadata and Score Rationale | already-present | already-present |
| [x] | C31K-009 | 00031K | Preserve owner 00006H, reconstructable false, blank emitter, blank CPP/H, Nested:0. | exact | Source-form and ownership proof. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Metadata and Formal Channels | already-present | already-present |
| [x] | C31K-010 | 0004CB | UID0004CB is the sole human-source IMEPane destructor body. | very-strong | Ordinary destructor lacks wrapper flags/free logic and matches source cleanup. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / Item Summary and formal CPP | already-present | already-present |
| [x] | C31K-011 | 0004CB | Ordinary destructor marks statusPane, activeChildPane, and candidatePane, relies on List teardown, clears g_pIMEPane, and transfers to Pane teardown. | exact | Fresh decompile/callee comparison. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / Behavior | already-present | already-present |
| [x] | C31K-012 | 00006H | Class declaration owns virtual ~IMEPane() and one List focusPaneList, not a separate focusPaneCount field. | very-strong | UDT layout, UID0004CC, class H. | by-class/IMEPane.md / RECONSTRUCTION_H CODE and Layout | already-present | already-present |
| [x] | C31K-013 | 00006H | IMEPane size is 0x120 with focusPaneList at +0x104 and nested m_count at complete +0x110. | exact | Live UDTs and SetFocusPane behavior. | by-class/IMEPane.md / Layout and Evidence | already-present | already-present |
| [x] | C31K-014 | 0000K5 | IMEPanes is the sole CPP/H source owner and excludes UID00031K from emission. | very-strong | Owner/emitter chain and generated output. | by-file/IMEPanes.md / Source Inventory and Compiler Exclusions | already-present | already-present |
| [x] | C31K-015 | 00018C | Mixed aggregate records UID00031K as class-owned compiler evidence routed to UID0004CB. | very-strong | Aggregate inventory and exact children. | by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md / Item Summary | already-present | already-present |
| [x] | C31K-016 | 00018D | Adjustor roots [0x004e8608,0x004e8613) and [0x004e8613,0x004e861e) subtract 0xa0/0xa4 and tail-jump to UID00031K. | exact | Fresh thunk bytes/disassembly. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / IMEPane Pair | already-present | already-present |
| [x] | C31K-017 | 00025J | Primary and two secondary vtable routes use 0x0061c4fc, 0x0061c548, and 0x0061c578. | exact | Live data values and xrefs. | by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md / IMEPane Vtable Entries | already-present | already-present |
| [x] | C31K-018 | 0000R7 | g_pIMEPane has one human-source definition under IMEPanes and is cleared by the ordinary destructor. | very-strong | Global owner and source route. | by-global/g_pIMEPane.md / Ownership and formal CPP/H | already-present | already-present |
| [x] | C31K-019 | 0001PS | Physical singleton slot 0x0069b458 is typed IMEPane *, currently zero, with 17 exact xrefs. | exact | Live item/type/value/xref reads. | by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md / Item Summary and Xrefs | already-present | already-present |
| [x] | C31K-020 | 000192 | List teardown at 0x004f30e0 owns embedded-list destruction reached by both destructors. | very-strong | Callee identity and class layout. | by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md / Caller Context | already-present | already-present |
| [x] | C31K-021 | 0004CC | Complete-object +0x110 is focusPaneList.m_count, expressed through focusPaneList.GetCount(), not a second IMEPane field. | very-strong | UDT and current formal C++. | by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md / Layout Interpretation | already-present | already-present |
| [x] | C31K-022 | 00031G | Focus-caret helper remains source-authored class behavior and does not alter destructor ownership. | strong | Class/file routing and helper body. | by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md / Ownership | already-present | already-present |
| [ ] | C31K-023 | 00031K | Dated supervisor command 23042 emits UID0004CB exactly once and UID00031K zero times; commands 22981/23008 are older history, and every later Gate must reread generated output dynamically. | exact | Repair-time physical reread of command-23042 output found one UID0004CB marker, one ordinary destructor definition, and zero UID00031K marker/name/body/empty-marker output; no B006 generated credit. | by-file/IMEPanes.md / Generated Closure Evidence | incorporate | proposed |
| [ ] | C31K-024 | 00031K | Dated command-23042 generated snapshot has IMEPanes.cpp SHA256 DE5C5BBBA7D9CFCF6702E5ACB3E68B616E8593E85AFB5477124AD8AF57D36A97, 17,076 bytes/558 lines, and IMEPanes.h SHA256 86B8CAC7B8D7816AC919136012882A1A185988F7A770C4CAF9E097075B83FB70, 3,149 bytes/118 lines; future authority requires fresh physical hashes. | exact | Physical readback of the supervisor command-23042 validator-owned files at repair time. | by-file/IMEPanes.md / Generated Closure Evidence | incorporate | proposed |
| [ ] | C31K-025 | 00031K | Every Gate and mandatory post-move audit must physically reread UID00031K in the then-current tracker and recompute the full tracker hash; dated command-23042 snapshot and the later dynamic readback both record line 5708 at 92/94, 93.0, false/non-emitting. | exact | Command 23042 snapshot SHA256 1C3C8716C6ED51E0DA0912FB5C75F61199F02921118362DBC3C1FB7718491A41, 1,721,114 bytes/6,765 lines; later physical readback SHA256 6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC, 1,721,219 bytes/6,765 lines, with unchanged row and no new command attribution; command 23014 is superseded history. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Score Rationale | already-present | proposed |
| [x] | C31K-026 | 00031K | Older matching reports are corroboration only and confer no current implementation credit. | exact | Six identified historical report hashes. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Research History | historicalize | already-present |
| [x] | C31K-027 | 00031K | Old proof-comment/comment-only source substitutes are superseded by false/non-emitting blank formals. | very-strong | Current formal-channel rules and wrapper disposition. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Historical Assumptions | historicalize | already-present |
| [x] | C31K-028 | 00031K | Score remains below 100 only for unavailable original symbols/compiler switches/lexical source. | strong | All behavioral/source blockers resolved. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Score Rationale | already-present | already-present |
| [x] | C31K-029 | 00031K | No standalone declaration, prototype, emitter route, or source-order slot is appropriate for the wrapper. | very-strong | Compiler-generated ownership and duplicate-body proof. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Source Placement | already-present | already-present |
| [x] | C31K-030 | 00031K | Zero ordinary callers and exact vtable/thunk routes reject an ordinary helper interpretation. | exact | Caller/xref inventory. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / Negative Evidence | already-present | already-present |
| [ ] | C31K-031 | 00031K | Wrapper target has no recommended IDA mutation; preserve exact current name/type/frame/comments. | exact | Fresh source-quality current state. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | already-present | proposed |
| [ ] | C31K-032 | 00031K | Gate 2B must freshly attest canonical session/path before readback. | exact | Runtime identity is ephemeral. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-033 | 00031K | Gate 2B must verify exact target function model and five-row frame without mutation. | exact | Fresh function/frame snapshot. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-034 | 00031K | Gate 2B must verify the six internal regular/repeatable comment pairs remain blank. | exact | Fresh comment reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-035 | 00018D | Gate 2B must preserve A0 adjustor name, raw thunk type/frame, comment, bytes, and tail jump. | exact | Fresh thunk inspection. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-036 | 00018D | Gate 2B must preserve A4 adjustor name, raw thunk type/frame, comment, bytes, and tail jump. | exact | Fresh thunk inspection. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-037 | 00031K | Gate 2B must protect exact three inbound refs and zero ordinary callers. | exact | Fresh xref/caller reads. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-038 | 00025J | Gate 2B must protect three vtable cells and their three-write topologies. | exact | Fresh data/xref reads. | by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-039 | 00031K | Gate 2B must protect target/thunk/padding body hashes and exact bounds. | exact | Fresh byte hashes. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-040 | 00006H | Gate 2B must preserve IMEPane size 0x120 and nested list layout. | exact | Fresh UDT reads. | by-class/IMEPane.md / IDA Recommendations and Layout | incorporate | proposed |
| [ ] | C31K-041 | 0001PS | Gate 2B must preserve g_pIMEPane name/type/value and 17-xref topology. | exact | Fresh item/xref reads. | by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md / IDA Recommendations | incorporate | proposed |
| [ ] | C31K-042 | 0004CB | Ordinary destructor remains source authority even though IDA retains sub_4E8000. | very-strong | Body/source ownership independent of current symbol. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / IDA Status | already-present | proposed |
| [ ] | C31K-043 | 00031K | No IDA save is justified if all no-change readbacks pass. | exact | No mutation recommendation. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA Recommendations | not-applicable | proposed |
| [ ] | C31K-044 | 00031K | Manual by-memory row must retain exact 92% compiler-wrapper/non-emitting text. | exact | Current row 1983. | by-memory/-coverage-report.md / UID00031K row | already-present | proposed |
| [ ] | C31K-045 | 00006H | Manual by-class row must retain 91% class source and one-List/no-wrapper-emission text. | exact | Current row 259. | by-class/-coverage-report.md / UID00006H row | already-present | proposed |
| [ ] | C31K-046 | 0000K5 | Manual by-file row must retain current 92% source-root, guarded-header/layout, ordinary-destructor, and compiler-wrapper exclusion text. | exact | Repair-time physical row 122 preserves and expands the accepted semantics at current SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756. | by-file/-coverage-report.md / UID0000K5 row | already-present | proposed |
| [ ] | C31K-047 | 0000R7 | Manual by-global row must retain sole g_pIMEPane definition and 17-xref evidence. | exact | Current row 97. | by-global/-coverage-report.md / UID0000R7 row | already-present | proposed |
| [x] | C31K-048 | 00031K | Callback physical reread found the destination unchanged at SHA256 30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-049 | 0004CB | Callback physical reread found the destination unchanged at SHA256 B64D649DC5801EF12A3986610A872E4E0AEF822B3A812590829F06DCB46866D5; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-050 | 00006H | Callback physical reread found the destination unchanged at SHA256 544585FF4205BB8C6DE1F73F7950F3A3A868691BFB453BF17336E8A300286655; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-class/IMEPane.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-051 | 0000K5 | Repair-time physical reread found the externally advanced destination at SHA256 10412A9AE3FE9EC01034DA8CD9252FCE676C8501ED6847AB3AA41772DC9D2520, 59,525 bytes/214 lines, with accepted UID00031K detail preserved; B006 made no edit and scoped validation was not applicable. | exact | Full-file reread attributes the additive drift to accepted B007/supervisor work and confirms same-or-greater source-owner/compiler-exclusion detail without B006 credit. | by-file/IMEPanes.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-052 | 00018C | Callback physical reread found the destination unchanged at SHA256 C6802376F4D32AA35F149F2C9004EDFA8F60058BE1ED6567633E45CCD3B9BA37; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-053 | 00018D | Callback physical reread found the destination unchanged at SHA256 A40F27BAC822887F691C75C1915F704C9D9175C2AD401CEDBB19A13793CAEB22; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-054 | 0000R7 | Callback physical reread found the destination unchanged at SHA256 5C536A062274538A511DE2743CBA247B2189C5FA26737075D1035B4CAA9A4080; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-global/g_pIMEPane.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-055 | 0001PS | Callback physical reread found the destination unchanged at SHA256 2C1830C724B3C1EC634C4490B16C36772F9230696B83E7540677D48F58EA4B2D; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-056 | 00025J | Callback physical reread found the destination unchanged at SHA256 35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-057 | 000192 | Callback physical reread found the destination unchanged at SHA256 705B1FF21EB473382ED33D64F7C181138135A1787BAA81EC6763DB7D4A575957; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-058 | 0004CC | Callback physical reread found the destination unchanged at SHA256 128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md / whole document | not-applicable | excluded-with-reason |
| [x] | C31K-059 | 00031G | Callback physical reread found the destination unchanged at SHA256 CB30D12CD845B9B4E0BF144DB1C055D662C1EB36C84C05812F33414DAD1F78CB; scoped validation was not applicable because no edit occurred. | exact | Full-file physical reread at accepted callback detail; no activity-only validator was run. | by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md / whole document | not-applicable | excluded-with-reason |
| [ ] | C31K-060 | 00031K | Supervisor Gate 2A must independently verify all accepted physical-destination claims. | exact | Fixed workflow gate. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / implementation verification record | incorporate | proposed |
| [ ] | C31K-061 | 00031K | Supervisor Gate 2B must independently complete exact no-change IDA readbacks. | exact | Fixed workflow gate and Section 21. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / IDA verification record | incorporate | proposed |
| [ ] | C31K-062 | 00031K | Supervisor must verify manual coverage rows after ordinary callback. | exact | Manual files are supervisor-owned. | by-memory/-coverage-report.md / UID00031K and named support rows | incorporate | proposed |
| [ ] | C31K-063 | 00031K | Supervisor command 23042 provides the dated repair-time generated/tracker snapshot with one UID0004CB destructor and zero UID00031K output; the tracker later drifted physically without semantic row drift, so later Gates must dynamically reread or refresh before lifecycle action. | exact | Supervisor command 000000023042 at 2026-08-13T01:06:08-04:00 plus later tracker SHA256 6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC physical readback; exact inventories reread by B006 without generated implementation credit. | by-file/IMEPanes.md / generated closure evidence | incorporate | proposed |
| [ ] | C31K-064 | 00031K | Report execution/archive remains supervisor-only and validator-authoritative. | exact | Lifecycle boundary. | by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md / lifecycle authority handoff | not-applicable | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000023050","destination_path":"executed-b-agent-research/B006/00031K-IMEPaneScalarDeletingDestructor-source-quality-3.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00031K-IMEPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T02:43:43-04:00","uid":"00031K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
