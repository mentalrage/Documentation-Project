** TARGET-REPORT-UID:0002N8 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002N8 SelfSaveInputPaneVtableData Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: retain the applied [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](../../../../../by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) disposition as one exact `0x88`-byte, source-declared/generated-binary child of [UID:0000CW][SelfSaveInputPane](../../../../../by-class/SelfSaveInputPane.md). It contains three compiler-emitted vtable views and two internal complete-object-locator cells; it contains no padding and no handwritten table source.
- Final disposition: applied as `CANONICAL_OWNER:0000CW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CW`, `EMITTER_POSITION_OPTIONAL:40`, `Nested:0`, score `91/94`, and the exact target-specific no-handwritten-vtable marker rather than fixed `.rdata` dwords.
- Completed callback: Destinations 1-8 and C01-C30 are incorporated across all eight ordinary pages. The class now uses period-plausible `virtual void OnConfirmInput();`; constructor/confirm/helper/markers/factory emit in positions `10/20/30/40/50/60` after class position `0`; all pages passed scoped validation; final waited generation passed and was read back exactly.
- Confidence: very strong for the exact bytes, all three table views, RTTI hierarchy, vptr stores, active handler, source ownership, compiler-wrapper disposition, and no-split decision. Confidence remains below absolute because several inherited slot source spellings and the original file grouping cannot be recovered from symbols, and the raw constructor/helper/factory starts still have no ordinary call route.

## Supporting Research

- Evidence collection used the supervisor-designated NexusTK IDB database `supervisor_nexustk_20260713` after a fresh `idb_list`. At evidence-collection time, `server_health` returned `ok` with auto-analysis, Hex-Rays, and strings ready; all IDB-backed facts below are time-scoped to that observation and do not assert later session availability.
- Executed sibling report [B005 UID0003O5](../../../../../executed-b-agent-research/B005/0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md) was read as historical research for the raw constructor, then independently checked against current bytes, instructions, vptr stores, prompt lookup, boundaries, and no-route state.
- Executed sibling report [B007 UID0003O7](../../../../../executed-b-agent-research/B007/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md) was read as historical research for the retained packet helper, then independently checked against current raw instructions, opcode, sender, exact `ret`, and no-route state.
- Executed sibling report [B012 UID0001KQ](../../../../../executed-b-agent-research/B012/0001KQ-SelfSaveInputPaneFactory-source-quality.md) was read as historical research for the factory, then independently checked against its modeled extent, allocation size, localized-string lookup, base constructor, EH/null path, and vptr stores.
- Those historical reports contain validator/lifecycle-era wording that is not reused as current state. Their accepted technical details are incorporated only where the current IDB and current by-* pages independently agree.
- No UID0002N8 exact-range report was found in the central executed, archive, legacy, or active roots. This is the unique report for the assigned tracker row.
- Initial report-only restrictions were observed through Gate 1 SHA `F8E7AF735D88E72955952B59EF90D794FA8D9DEBF1E0EBE1442822D6563C9BCE`. After explicit callback authorization, B002 edited only the eight accepted ordinary pages under short leases and this report, ran scoped validators plus the authorized waited refresh, and released every lease. No manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, or IDA file was manually edited; no lifecycle/probe, move, archive, or `execute_report` command was run.

## Target

- Target UID: `0002N8`.
- Target path: `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md`.
- Source queue/report row: originally assigned as the first exact-range `86/90`, report-count-zero row; that is historical selection evidence, not current target metadata.
- Current supervisor classification: Gate 1 accepted implementation callback completed by B002; current/future validation, report count, execution, move, and archive state remain external validator-owned state and are not asserted.
- Current scores and parent state: `91/94`, `CANONICAL_OWNER:0000CW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CW`, position `40`, exact formal compiler-generated marker, `Nested:0`.

## Current Target State

- Applied target: UID0002N8 is `91/94`, owner/emitter UID0000CW, position `40`, `Nested:0`, with all 34 dwords, hashes, slot sizes/roles, COL/BCD hierarchy, stores, bounds, no-padding/no-split proof, compiler-wrapper disposition, historical blocker correction, and exact marker documented.
- Applied support: UID0003HM is `90/94` position `50`; UID0000CW is `90/92` position `0` with `virtual` and no explicit destructor; UID0003O6 is `90/92` position `20` with the exact inline-send body; UID0003O5/UID0003O7/UID0001KQ preserve accepted scores/bodies at positions `10/30/60`; UID0000NM is `89/91` with complete file-root prose and no reconstruction metadata.
- Verify-only state: [UID:0001MU][SelfSaveInputPane method island](../../../../../by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md), [UID:00026W][UserPaneInputVtables](../../../../../by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md), [UID:0001XA][CommandInputPaneVtableFamily](../../../../../by-type/by-vtable/CommandInputPaneVtableFamily.md), and [UID:0001N6][SharedInputPaneAdjustorThunks](../../../../../by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md) remain `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, with existing owner semantics unchanged. No concrete drift required a bounded repair.
- Generated readback: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp` is stamped command `000000010268` / `2026-07-13T15:57:05-04:00`; it contains exactly one class, constructor, confirm method, retained helper, target marker, type marker, and factory in positions `0/10/20/30/40/50/60`, zero Empty Emitter Markers, and no handwritten scalar destructor, adjustor thunk, RTTI record, or vtable body.
- Lease state: each ordinary page was leased only for its edit/scoped-validator transaction and released immediately; final readback shows no active B002 lease.
- Current artifact/lifecycle status: B002 callback work, validators, generated verification, lease release, and report synchronization are complete. Current/future report path, report count, validation, execution, move, and archive state are external validator-owned state and are not asserted.

## Executive Recommendation

- Keep UID0002N8 intact. The exact target is one class's compiler output, and the two internal four-byte cells are RTTI complete-object locators, not padding or foreign ownership.
- Keep direct semantic owner and emitter UID0000CW. A compiler vtable is generated by the class declaration and its virtual methods; the broad memory/type aggregates are inventory indexes, not source owners.
- UID0002N8 is applied at `91/94`, position `40`, with the exact no-handwritten-vtable marker from Destination 1.
- UID0003HM is applied at `90/94`, position `50`, with the exact source-local-index/no-duplicate marker from Destination 2.
- UID0000CW is applied at `90/92`, file position `0`, with inheritance/layout/constant preserved, invalid `override` replaced by `virtual`, and `[[CHILDREN]]` retained as Destination 3 specifies.
- UID0003O6 is applied at `90/92`, position `20`, with the exact vtable-routed inline-send body from Destination 4 and no call to the retained helper.
- UID0003O5 `88/90`, UID0003O7 `87/88`, and UID0001KQ `87/88` preserve accepted bodies byte-for-byte at positions `10`, `30`, and `60`.
- Immediate by-file route UID0000NM is applied at `89/91` with complete source-placement/order prose and no by-file reconstruction metadata or formal block.
- Leave UID0001MU, UID00026W, UID0001XA, and UID0001N6 `NONE/FALSE/blank` and non-emitting. Preserve the current `SelfSaveInputPane.cpp` route; a future coordinated move to `CommandInputPanes.cpp` is possible but is neither required nor justified by this exact-range assignment.

## Supervisor Active Recheck

- The triggering instruction assigns UID0002N8 as the next unique report-only target and requires synthesis plus independent revalidation of executed SelfSave reports.
- The target required a split/no-split determination before a safe recommendation. Current bytes and RTTI prove no child split is needed inside UID0002N8.
- Every source-bearing item in the bounded SelfSave route has a precise disposition: constructor UID0003O5 preserved, confirm UID0003O6 newly source-ready, helper UID0003O7 preserved, factory UID0001KQ preserved, class UID0000CW corrected, target/type data represented by exact no-code markers, and compiler destructor/adjustor wrappers excluded from handwritten source.
- No duplicate report is proposed for UID0003O5, UID0003O7, or UID0001KQ. Their central executed artifacts are evidence inputs and their current by-* pages are callback destinations or verify-only support as specified below.

## Inference Research Guidance Check

- The project inference discipline requires direct binary facts to outrank old prose, generated output, and source-looking names. The recommendation therefore starts from exact dwords, RTTI records, stores, xrefs, function boundaries, and base-class tables.
- Existing assumptions treated as uncertain were: the two internal dwords might be padding; `OnConfirmInput` might override a base virtual; the shared scalar destructor might require source; the raw helper might be dead or compiler glue; the factory might be a class member; and `CommandInputPanes.cpp` might already be the proven source file. Each was rechecked rather than inherited.
- IDA fact: table addresses, bytes, slot targets, RTTI offsets, xrefs, function extents, constructor stores, confirm body, and helper/factory instruction behavior.
- Documentation evidence: current class/base layouts, existing accepted formal bodies, source-tree routes, resource/global pages, and executed sibling reports.
- Inference: descriptive names for inherited slots where no decorated per-function symbol survives, the file-local helper name, retained factory name, and the standalone versus grouped source-file choice.
- Wave2/Wave3 and `simroot_v2` mentions were encountered in current historical documentation and generated artifacts. They were treated as stale/historical evidence only and did not override current MCP or ordinary by-* state.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Result / evidence tier |
| --- | --- | --- |
| Range shape | Read every target dword and the predecessor/successor locator cells. | Original-proof: `0x88` bytes comprise `19` primary slots, one secondary COL cell, `11` secondary slots, one tertiary COL cell, and `2` tertiary slots. |
| Internal four-byte cells | Decoded `0x0063060c -> 0x00653880` and `0x0063063c -> 0x00653894`; parsed their COL offsets. | Original-proof: RTTI locator cells for subobjects `+0xa0` and `+0xa4`, not padding. |
| Primary locator | Read outside-target predecessor cell `0x006305bc -> 0x0065381c`. | Original-proof: primary COL belongs semantically to SelfSave but is outside the assigned half-open target. Do not widen the target. |
| Successor boundary | Read `0x00630648 -> 0x006538a8`, the BlockListen COL, and table start `0x0063064c`. | Original-proof: exclusive target end remains `0x00630648`; do not consume successor RTTI. |
| Class hierarchy | Parsed SelfSave type descriptor, CHD, eight base descriptors, and PMD offsets. | Original-proof: `SelfSaveInputPane -> CharInputPane -> LineInputPane -> Pane`, with GrafPort/LObject chain, EventHandler at `+0xa0`, TimerHandler at `+0xa4`. |
| `OnConfirmInput` declaration | Compared current LineInput/CharInput primary-table lengths and SelfSave's added final slot. | Original-proof plus source inference: this is a new virtual, not a base override. The evidence-time `override` was rejected; the applied declaration uses period-plausible `virtual`. |
| Class fields | Compared factory allocation `0x108`, constructor writes, RTTI, and inherited class layouts. | Strong inference: SelfSave adds no persistent data field. Do not add reserve bytes; inherited object extent already reaches `0x108`. |
| Destructor | Disassembled `0x005b7940`, its 23-plus table fanout, flags, base cleanup, and delete paths. | Original-proof/compiler classification: implicit scalar deleting destructor wrapper shared by command/input classes; no explicit SelfSave destructor source body. |
| Adjustor thunks | Disassembled `0x005b77c8` and `0x005b77d3`. | Original-proof/compiler classification: subtract `0xa0`/`0xa4` then tail-jump to the scalar wrapper. No handwritten source. |
| Constructor liveness | Rechecked raw instructions and all three store xrefs; searched direct routes. | Exact body and source shape, but no function object/direct route. Preserve accepted constructor and confidence cap. |
| Confirm handler | Rechecked function extent, vtable pointer, text-length/copy calls, comparisons, packet writes, and send. | Original-proof and source-ready. It remains the active virtual route. |
| Retained helper liveness | Rechecked raw instructions and exact `ret`; searched branch and pointer routes. | Source-authored, SelfSave-specific retained helper with no ordinary route. Keep it; do not force the active handler to call it. |
| Factory liveness | Rechecked modeled extent, allocation/EH/null path, prompt lookup, base construction, and stores; searched callers. | Source-authored retained factory with no ordinary route. Keep file-level `CreateSelfSaveInputPane`, not a class member. |
| Packet layout | Checked both packet-writing bodies and shared packet docs. | One transmitted byte, opcode `0x25`; `packet[1]=0` is scratch/non-transmitted. |
| Prompt resource | Checked current resource page/string row and constructor use. | Exact id `0x26` / decimal `38`, current text `Save profile? (Y/N) ` including trailing space. Source uses symbolic id. |
| Slot names | Compared base vtables and current source-facing class docs. | Exact addresses/targets and roles are proven. Inherited per-slot original spellings remain descriptive where symbols do not survive; this does not block source because inherited declarations own those slots. |
| Source placement | Compared UID0000NM and UID0000ID routes plus all SelfSave children. | Keep immediate `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`; reject a partial move. A coordinated future family consolidation is outside scope. |
| Generated output | Read evidence-time/pre-callback output and callback-time waited output; never edited generated source manually. | The pre-callback file was incomplete and contained a target Empty Emitter Marker. Waited validator `000000010268` applied the formal destinations; callback readback has all seven items exactly once, zero Empty Emitter Markers, and no handwritten ABI source. |
| Old names | Rechecked `sub_`, `FUN_`, `ctor_`, raw vftable labels, and control-character metadata. | Rejected as source-facing names. |

Rejected alternatives:

- Split UID0002N8 into three pages: rejected because all views and both internal RTTI locators belong to one class and one compiler-generated unit; splitting would add no source ownership distinction.
- Reclassify the internal COL cells as padding: rejected by exact pointers and COL `offset` values `0xa0` and `0xa4`.
- Emit literal vtable arrays/dwords: rejected because construction and class declarations regenerate the ABI data, and handwritten arrays would duplicate compiler output.
- Add an explicit `~SelfSaveInputPane` body: rejected because the observed scalar deleting body is shared compiler glue and the source can rely on an implicit derived destructor.
- Keep `override`: rejected because there is no base primary slot at that index.
- Make `OnConfirmInput` call `SendSelfSavePacket`: rejected because the active body duplicates the send instructions inline and no branch targets the retained helper.
- Delete the retained helper/factory because they have no route: rejected because both are coherent complete source-authored bodies with class-specific constants and dependencies; no-route is a confidence cap, not proof of padding or compiler generation.
- Put factory or helper in the class declaration: rejected because neither reads `this`, neither has a vtable slot, and no class-static declaration evidence exists.
- Move only UID0002N8 or one source child to CommandInputPanes: rejected because that would split one source unit across competing file emitters.

## Evidence Standards Used

- Direct evidence: IDA MCP `idb_list`, `server_health`, byte reads, dword reads, instruction queries, function lookup, decompilation, xrefs, decorated-name lookup, RTTI structures, table comparisons, and section/boundary context.
- Corroborating evidence: current by-memory/by-class/by-file/by-type/by-layout/by-resource/by-global pages, current read-only generated source, source-tree route metadata, and executed sibling reports.
- Negative evidence: no direct route to raw constructor/helper/factory starts; no explicit SelfSave destructor; no SelfSave-specific fields; no padding inside the target; no exact UID0002N8 report in searched roots; no active collision report; no base virtual for the SelfSave-only final primary slot.
- Binary facts were treated as strongest. Existing docs and executed reports were accepted only after current binary revalidation. Generated source was used only to detect emission gaps, never as authority over the binary.
- Confidence is high because all 34 slot/locator dwords, all three vptr-store pairs, all RTTI base descriptors, exact boundaries, and the active method body agree. Confidence is capped by missing original symbols, missing ordinary routes for retained bodies, and unresolved original source-file grouping.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: fresh `idb_list`; evidence-time `server_health`; bytes and hashes for `0x006305bc-0x0063064c`; exact target bytes/hash; dword inventories for all three views; function lookup for every slot target; raw constructor/helper instruction queries; confirm/factory decompilation; xrefs to table bases, handler, scalar wrapper, and adjustors; RTTI COL/CHD/type/base-descriptor reads; predecessor/successor boundary reads.
- Exact target hash: `SHA256 8D10C1E386E81C36935A768719766D9F351FFA2CA8DC7834200E475975D318D4` for `0x006305c0-0x00630648`.
- Exact subrange hashes: primary slots `1AF9850C413B4022D897E383F5D69B355302E538C45A3D9DC78125DBCFA66966`; secondary slots `11FBB0BD05C14D44550F8D240F63467002021276C1D54C234ADA19B4C31A56B7`; tertiary slots `6D30D4563468ADCDECAE8FD6BF679F50B6E6310338419E16D9BCA75911930960`.
- Current by-* docs checked: UID0002N8, UID0003HM, UID0000CW, UID0000NM, UID0001MU, UID0003O5, UID0003O6, UID0003O7, UID0001KQ, UID00026W, UID0001XA, UID0001N6, CharInputPane, LineInputPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, PaneLayout, PaneVtables, InputPaneBaseVtableFamily, BlockListen successor docs, `g_pLanguageMan`, `g_packetSender`, localized strings, packet-write helpers, and QueueAndSendPacket.
- Exact old-report search terms: `UID0002N8`, `UID:0002N8`, `TARGET-REPORT-UID:0002N8`, `0002N8`, `0x006305c0`, `0x00630648`, `SelfSaveInputPaneVtableData`, `SelfSaveInputPaneVtables`, `SelfSaveInputPane`, `0x005b67c0`, `0x005b6800`, `0x005b6870`, `0x005aa140`, `0x00630608`, `0x0065381c`, `0x00653880`, and `0x00653894`.
- Central executed root searched: `source-3/project-documentation/executed-b-agent-research/**`. No exact UID0002N8 report. Opened direct reports `B005/0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md`, `B007/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md`, and `B012/0001KQ-SelfSaveInputPaneFactory-source-quality.md`; findings are independently revalidated above. Context-only matches B001 UID0001KM/UID0002SB/UID00042U, B004 UID0001AY, B005 UID0002FH/UID0002QB, B007 UID0001M0, B008 UID0003NZ, and B012 UID0001MS were classified as neighboring source-shape precedent, not target research.
- Central archive root searched: `source-3/project-documentation/tools/leaser/archived/**`; no exact or direct SelfSave target report.
- Legacy executed roots searched: `source-3/project-documentation/tools/leaser/Agents/Agent-B*/research/executed/**`; no exact or direct target report, with executed work centralized under the current executed root.
- Active roots searched: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/**` through `Agent-B015/research/**`; no exact UID0002N8 report or active collision.
- Older research root searched: `source-3/project-documentation/Older-Research/**`; no exact or direct target report.
- Special reports root searched: `source-3/project-documentation/SpecialReports/**`; no exact or direct target report.
- Evidence-time / pre-callback generated source checked read-only: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp` then had one class and one factory, a UID0002N8 Empty Emitter Marker, and no emitted UID0003O5/UID0003O6/UID0003O7 body. The callback-time waited generated readback is recorded in `Validator Results`: all seven accepted source/marker destinations now occur exactly once in deterministic order and the Empty Emitter Marker count is zero.
- Manual coverage files checked read-only: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-type/by-vtable/-coverage-report.md`, `by-resource/-coverage-report.md`, and `by-global/-coverage-report.md`. Exact supervisor text is supplied below for every stale/absent affected row.
- Negative checks performed: target-exact report search, route searches, target interior padding check, successor/predecessor overlap check, base virtual-slot comparison, explicit-destructor search, class-field/write search, duplicate source-body search, and manual coverage row search.
- Failed, unavailable, or intentionally skipped checks: no required bounded MCP call failed. IDA writes/renames/types were intentionally not performed. During the initial report-only phase, validators, generated refresh, leases, lifecycle probes, and implementation were intentionally skipped. After Gate 1 callback authorization, the eight scoped validators and one waited refresh recorded below completed; lifecycle probes and IDA writes remained intentionally unperformed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0002N8 is exactly `0x006305c0-0x00630648`, size `0x88`, target SHA256 `8D10C1E386E81C36935A768719766D9F351FFA2CA8DC7834200E475975D318D4`. | very strong | Current MCP bytes/hash and boundaries | UID0002N8 exact range/hash section; validator `000000010217`, waited `000000010268` | incorporate | applied |
| C02 | The target has 19 primary slots, a secondary COL cell, 11 secondary slots, a tertiary COL cell, and 2 tertiary slots. | very strong | All 34 target dwords | UID0002N8 complete slot tables; UID0003HM complete inventory | incorporate | applied |
| C03 | The internal cells point to COLs `0x00653880` and `0x00653894`; they are not padding. | very strong | Pointer/COL reads | UID0002N8/UID0003HM locator and no-padding proof | incorporate | applied |
| C04 | Wear's tertiary table at `0x006305b4` and SelfSave primary COL at `0x006305bc` precede the target; BlockListen COL at `0x00630648` is the successor. | very strong | Boundary dwords/RTTI names | UID0002N8/UID0003HM exact predecessor/successor prose | incorporate | applied |
| C05 | SelfSave RTTI has eight bases and proves EventHandler `+0xa0`, TimerHandler `+0xa4`. | very strong | TD/CHD/BCD/PMD records | UID0002N8 BCD table; UID0003HM/UID0000CW hierarchy prose | incorporate | applied |
| C06 | Primary table slot `+0x48` is SelfSave's active confirmation handler at `0x005b6800`. | very strong | Slot dword and unique xref | UID0002N8, UID0000CW, UID0003O6; validators `000000010217/000000010221/000000010224` | incorporate | applied |
| C07 | All other primary slots are inherited or compiler wrapper slots; source declarations own them. | strong | Base table comparison/function lookup | UID0002N8 per-slot table and UID0003HM/UID0000CW disposition | incorporate | applied |
| C08 | Secondary table is EventHandler subobject at `+0xa0`; tertiary table is TimerHandler at `+0xa4`. | very strong | COL offsets, RTTI PMDs, slot comparison | UID0002N8, UID0003HM, UID0000CW | incorporate | applied |
| C09 | Stores at `0x005aa196/19c/1a6` and `0x005b67df/e7/f1` install all three table bases. | very strong | Current xrefs/instructions | All seven source/formal destinations and UID0000NM source-unit section | incorporate | applied |
| C10 | Raw constructor UID0003O5 is source-ready despite no modeled start/direct route. | very strong | Raw instructions, unique bytes, factory corroboration | Accepted body retained; position/sync added; validator `000000010227` | already-present | already-present |
| C11 | Factory UID0001KQ allocates `0x108`, handles null/EH, constructs the same object, and is a retained file helper. | strong | Current decompile/stores/no-route search | Accepted body retained; position/sync added; validator `000000010248` | already-present | already-present |
| C12 | SelfSave adds no persistent data fields beyond inherited `0x108` extent. | strong | Allocation size, writes, class/layout docs | UID0002N8, UID0000CW, UID0003O5, UID0001KQ, UID0000NM | incorporate | applied |
| C13 | `OnConfirmInput` accepts only one `y`/`Y`, writes opcode `0x25`, clears scratch byte, and sends one byte. | very strong | Current decompile/callees/CFG | UID0003O6 exact formal body/prose; validator `000000010224` | incorporate | applied |
| C14 | The active handler duplicates the send tail inline and must not be rewritten to call UID0003O7. | very strong | No branch to helper; body comparison | UID0003O6/UID0003O7/UID0000NM and generated readback | incorporate | applied |
| C15 | UID0003O7 is a retained file-local source helper with no ordinary route, not dead padding or compiler glue. | strong | Complete raw body, constants/dependencies, route scan | Accepted body retained; position/sync added; validator `000000010232` | already-present | already-present |
| C16 | Prompt resource is id `0x26` / 38 and current text includes trailing space. | very strong | Constructor immediate and resource row | UID0000CW, UID0003O5, UID0001KQ, UID0000NM | incorporate | applied |
| C17 | Packet sender is shared `g_packetSender`; packet opcode is `0x25`; only one byte is transmitted. | very strong | Two bodies/global/protocol docs | UID0003O6/UID0003O7/UID0000NM exact behavior | incorporate | applied |
| C18 | `0x005b7940` is a shared scalar deleting destructor wrapper and does not justify explicit destructor source. | very strong | Disassembly/flags/delete/base-call/high fanout | UID0002N8/UID0003HM/UID0000CW/UID0000NM; generated absence proved | incorporate | applied |
| C19 | `0x005b77c8` and `0x005b77d3` are compiler adjustor thunks for `+0xa0/+0xa4`. | very strong | Exact subtract-and-jump bodies | Existing UID0001N6 preserved; ordinary destinations and generated absence verified | already-present | already-present |
| C20 | UID0002N8 remains one child; no split, merge, widening, padding child, or new UID is needed. | very strong | Unified RTTI/class ownership and boundaries | UID0002N8/UID0003HM applied; UID00026W verify-only unchanged | incorporate | applied |
| C21 | UID00026W and UID0001XA remain non-emitting mixed-owner indexes; UID0003HM is the direct source-local type child. | very strong | Current metadata/child inventories | UID0003HM applied; UID00026W/UID0001XA readback `FALSE/blank` | already-present | applied |
| C22 | Semantic/source owner UID0000CW and immediate file UID0000NM remain correct. | strong | Class RTTI, methods, current source route | All owner/emitter metadata read back exact | already-present | already-present |
| C23 | A partial move to CommandInputPanes is unsafe; any future move must be coordinated for the whole SelfSave unit. | strong | Current owner/emitter graph | UID0000CW/UID0000NM current prose; partial move not performed | reject-invalid | excluded-with-reason |
| C24 | UID0002N8 is `91/94`, owner/emitter UID0000CW, position 40, formal marker, Nested 0. | very strong | Closed range/ABI/source blockers | UID0002N8 metadata/formal readback exact; validator `000000010217` | incorporate | applied |
| C25 | UID0003HM is `90/94`, owner/emitter UID0000CW, position 50, formal marker. | very strong | Exact target/type relationship | UID0003HM metadata/formal readback exact; validator `000000010218` | incorporate | applied |
| C26 | The evidence-time `void OnConfirmInput() override;` declaration was invalid; the applied declaration is `virtual void OnConfirmInput();`. | very strong | Base table lengths and added SelfSave slot | UID0000CW exact formal block and generated line readback | reject-invalid | applied |
| C27 | UID0003O6 is `90/92`, position 20, with the exact inline-send body. | very strong | Complete vtable/CFG/callee/body proof | UID0003O6 metadata/formal readback exact; validator `000000010224` | incorporate | applied |
| C28 | UID0003O5, UID0003O7, and UID0001KQ retain their formal bodies and scores at positions 10/30/60. | very strong | Accepted current pages and live revalidation | Bodies/scores exact; validators `000000010227/000000010232/000000010248`; generated order exact | already-present | applied |
| C29 | UID0000CW position 0 and UID0000NM score `89/91` yield deterministic one-file source order without by-file formal metadata. | strong | Current ownership model/generator rules | UID0000CW/UID0000NM validators `000000010221/000000010266`; by-file metadata absence and output order proved | incorporate | applied |
| C30 | Waited generation shows exactly one class/ctor/confirm/helper/factory, two disposition markers, no UID0002N8 Empty Emitter Marker, and no handwritten ABI wrappers/tables. | very strong | Formal destination graph | Waited command `000000010268`; exact generated count/order/absence readback | incorporate | applied |

## Positive Evidence Summary

- Direct facts: exact target bytes and SHA; three decorated table bases; two internal locator cells; primary/secondary/tertiary COL offsets; eight-base RTTI hierarchy; six paired construction stores; one active handler slot; exact predecessor/successor boundaries.
- Corroboration: current class and base docs agree with the RTTI hierarchy; executed constructor/helper/factory findings match current bytes; resource/global/protocol pages match the literals and calls; pre-callback generated source exposed the formal-emission gap and callback-time waited readback proves its closure.
- Strongest inference chain: class RTTI plus constructor/factory stores prove the tables belong to SelfSave; base-table comparison proves the final primary slot is newly declared by SelfSave; the vtable xref and complete handler body prove source-bearing `OnConfirmInput`; shared wrapper fanout proves destructor/adjustors are compiler ABI; therefore class/method source plus no-code vtable markers is behavior-identical and avoids literal table duplication.

## IDA MCP Facts

- Evidence-time database: `supervisor_nexustk_20260713`; fresh `idb_list` and `server_health ok` observed before bounded target calls.
- Exact target: `[0x006305c0,0x00630648)`, `0x88` / 136 bytes, SHA256 `8D10C1E386E81C36935A768719766D9F351FFA2CA8DC7834200E475975D318D4`.
- Decorated bases: `??_7SelfSaveInputPane@@6B@` at `0x006305c0`, `_0` at `0x00630610`, `_1` at `0x00630640`.
- Primary slots `[0x006305c0,0x0063060c)`, 19 dwords:

| Offset | Target | Evidence-backed role |
| --- | --- | --- |
| `+0x00` | `0x005b7940` | shared scalar deleting destructor wrapper |
| `+0x04` | `0x004f4b10` | inherited LObject runtime-class/query slot |
| `+0x08` | `0x0041b6c0` | inherited default no-op slot |
| `+0x0c` | `0x004f2320` | inherited LineInputPane layout/update slot |
| `+0x10` | `0x0041d680` | inherited default no-op slot |
| `+0x14` | `0x00544730` | inherited Pane show slot |
| `+0x18` | `0x00544750` | inherited Pane hide slot |
| `+0x1c` | `0x005447a0` | inherited repaint slot |
| `+0x20` | `0x00544800` | inherited invalidate-rect slot |
| `+0x24` | `0x00544a20` | inherited description slot |
| `+0x28` | `0x00544b80` | inherited screen-bounds slot |
| `+0x2c` | `0x00544bd0` | inherited set-bounds slot |
| `+0x30` | `0x004f2430` | inherited LineInputPane child-attach slot |
| `+0x34` | `0x00544cb0` | inherited layer insertion slot |
| `+0x38` | `0x004f24c0` | inherited child show/invalidate slot |
| `+0x3c` | `0x00544d30` | inherited pane-order slot |
| `+0x40` | `0x00544d70` | inherited unregister-event-handler slot |
| `+0x44` | `0x004f2790` | inherited LineInputPane no-op slot |
| `+0x48` | `0x005b6800` | SelfSave confirmation virtual, source-facing `OnConfirmInput` |

- Secondary COL cell: `0x0063060c -> 0x00653880`; its COL offset is `0xa0`.
- Secondary slots `[0x00630610,0x0063063c)`, 11 dwords:

| Offset | Target | Evidence-backed role |
| --- | --- | --- |
| `+0x00` | `0x005b77c8` | `this -= 0xa0` scalar-destructor adjustor |
| `+0x04` | `0x004f24f0` | inherited pointer/mouse/hit-test event path |
| `+0x08` | `0x004f2920` | inherited CharInput key/text path |
| `+0x0c` | `0x004f2580` | inherited IME/active-child forwarder |
| `+0x10` | `0x004f2760` | inherited packet/text-edit forwarder |
| `+0x14` | `0x00544df0` | inherited system/control default |
| `+0x18` | `0x00544e00` | inherited type-19 default |
| `+0x1c` | `0x004a89f0` | EventHandler forward-order method |
| `+0x20` | `0x00544e10` | inherited local event-pair output |
| `+0x24` | `0x00544e30` | inherited screen event-pair output |
| `+0x28` | `0x00544e70` | inherited event-accept predicate |

- Tertiary COL cell: `0x0063063c -> 0x00653894`; its COL offset is `0xa4`.
- Tertiary slots `[0x00630640,0x00630648)`: `0x005b77d3` scalar-destructor adjustor and inherited/default timer callback `0x00544e90`.
- Primary COL outside target: `0x006305bc -> 0x0065381c`, offset `0`. Successor COL outside target: `0x00630648 -> 0x006538a8`, followed by `BlockListenInputPane` table at `0x0063064c`.
- Immediate predecessor context: the preceding WearInputPane tertiary table starts at `0x006305b4` and ends before SelfSave's primary COL cell at `0x006305bc`. This proves the assigned target does not absorb Wear slots or the SelfSave primary locator.
- RTTI: type descriptor `0x0067a240` names `.?AVSelfSaveInputPane@@`; CHD `0x00653830` has attributes `1`, base count `8`, base array `0x00653840`.
- All three COLs have signature `0`, constructor displacement `0`, type descriptor `0x0067a240`, and CHD `0x00653830`; their object offsets are respectively `0`, `0xa0`, and `0xa4`.
- Exact base-descriptor matrix:

| BCD | Type | Contained bases | PMD / attributes |
| --- | --- | --- | --- |
| `0x00653864` | SelfSaveInputPane | `7` | `mdisp 0`, `pdisp -1`, `vdisp 0`, attributes `0x40` |
| `0x00649afc` | CharInputPane | `6` | primary base at `0` |
| `0x006499ec` | LineInputPane | `5` | primary base at `0` |
| `0x00640540` | Pane | `4` | primary base at `0` |
| `0x00640584` | GrafPort | `1` | primary chain at `0` |
| `0x00640348` | LObject | `0` | primary chain at `0` |
| `0x006405bc` | EventHandler | `0` | non-primary subobject at `+0xa0` |
| `0x0064060c` | TimerHandler | `0` | non-primary subobject at `+0xa4` |

- Current function lookup confirms every slot target and modeled size: `0x005b7940/0x3b`, `0x004f4b10/0x06`, `0x0041b6c0/0x03`, `0x004f2320/0x10f`, `0x0041d680/0x03`, `0x00544730/0x1a`, `0x00544750/0x4c`, `0x005447a0/0x14`, `0x00544800/0xac`, `0x00544a20/0x15`, `0x00544b80/0x41`, `0x00544bd0/0x73`, `0x004f2430/0x85`, `0x00544cb0/0x27`, `0x004f24c0/0x25`, `0x00544d30/0x3f`, `0x00544d70/0x3e`, `0x004f2790/0x01`, `0x005b6800/0x6c`, `0x005b77c8/0x0b`, `0x004f24f0/0x8a`, `0x004f2920/0xaa`, `0x004f2580/0x18`, `0x004f2760/0x23`, `0x00544df0/0x09`, `0x00544e00/0x09`, `0x004a89f0/0x1a`, `0x00544e10/0x15`, `0x00544e30/0x36`, `0x00544e70/0x1a`, `0x005b77d3/0x0b`, and `0x00544e90/0x05`.
- Store xrefs: factory `0x005aa196/0x005aa19c/0x005aa1a6`; raw constructor `0x005b67df/0x005b67e7/0x005b67f1`.
- Handler `0x005b6800` is modeled size `0x6c`; its only direct data route is primary slot `0x00630608`.
- Raw constructor `0x005b67c0-0x005b6800` decodes as 20 instructions and is not modeled as a function. Raw helper `0x005b6870-0x005b68b1` decodes through `ret` at `0x005b68b0` and is not modeled as a function.
- Factory `0x005aa140` is modeled size `0x80`, allocates `0x108`, has an allocation-null path/EH construction shape, resolves prompt `0x26`, constructs CharInputPane, and stores all three vptrs.
- Shared scalar wrapper `0x005b7940` has 25 current xrefs including two code adjustors and 23 primary-table data refs. It calls LineInputPane cleanup and conditionally deletes according to compiler flags.
- Negative facts: no direct route to raw constructor/helper/factory starts; no target padding; no explicit source destructor; no extra SelfSave field writes; no base primary virtual corresponding to the SelfSave `+0x48` slot.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x006305c0-0x00630648` | UID0002N8 target | exact three-view compiler vtable/RTTI cluster | TRUE | UID0000CW | `86/90 -> 91/94` | one child; formal no-code marker applied at position 40 |
| SelfSave vtable type | UID0003HM | source-local type/index over UID0002N8 | TRUE | UID0000CW | `86/91 -> 90/94` | marker applied at position 50 |
| class declaration | UID0000CW | direct semantic owner/source class | TRUE | UID0000NM | `87/89 -> 90/92` | `override` correction applied at position 0 |
| `0x005b67c0-0x005b6800` | UID0003O5 | raw constructor body | TRUE | UID0000CW | `88/90` | accepted body retained at position 10 |
| `0x005b6800-0x005b686c` | UID0003O6 | active confirmation virtual | TRUE | UID0000CW | `86/88 -> 90/92` | exact body applied at position 20 |
| `0x005b686c-0x005b6870` | no child | alignment | FALSE | none | not applicable | remains documented padding only |
| `0x005b6870-0x005b68b1` | UID0003O7 | retained file-local packet helper | TRUE | UID0000CW | `87/88` | accepted body retained at position 30 |
| `0x005aa140-0x005aa1bf` | UID0001KQ | retained file-level factory | TRUE | UID0000NM | `87/88` | accepted body retained at position 60 |
| `0x005b7940` | shared compiler function | scalar deleting destructor wrapper | no handwritten source | compiler ABI | not applicable | excluded from new child/source body |
| `0x005b77c8`, `0x005b77d3` | UID0001N6 support | destructor adjustor thunks | FALSE | NONE | `88/92` | unchanged compiler support |
| `0x005b67c0-0x005b68b1` | UID0001MU | method-island inventory | FALSE | UID0000CW semantic | `88/89` | unchanged non-emitter; exact children carry source |
| `0x0062ef0c-0x006307ec` | UID00026W | mixed-owner memory aggregate | FALSE | NONE | `88/92` | unchanged non-emitting index |
| command-family type | UID0001XA | mixed-owner type aggregate | FALSE | NONE | `88/92` | unchanged non-emitting index |
| source file | UID0000NM | immediate file emitter | file root | FILE | `87/87 -> 89/91` | prose/ordering sync applied; no formal by-file block |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006305c0` primary base | stores at `0x005aa196`, `0x005b67df` | factory and raw constructor install primary view |
| `0x00630610` secondary base | stores at `0x005aa19c`, `0x005b67e7` | factory and raw constructor install EventHandler `+0xa0` view |
| `0x00630640` tertiary base | stores at `0x005aa1a6`, `0x005b67f1` | factory and raw constructor install TimerHandler `+0xa4` view |
| `0x005b6800` | data xref `0x00630608` | exact active virtual route |
| `0x005b6800` callees | `0x004f2310`, `0x004f2300`, `0x00575380`, `0x00574bb0` | text length/copy, opcode write, queued send |
| `0x005b67c0` | no direct caller/start xref | retained raw constructor; confidence cap only |
| `0x005b6870` | no direct caller/start/range pointer | retained raw helper; not called by active handler |
| `0x005aa140` | no direct modeled caller/start xref | retained factory; liveness cap |
| `0x005b7940` | 25 xrefs | shared compiler scalar deleting wrapper, not SelfSave-authored destructor body |
| `0x005b77c8` | table data refs across input-pane family | compiler `+0xa0` adjustor |
| `0x005b77d3` | table data refs across input-pane family | compiler `+0xa4` adjustor |
| `g_pLanguageMan` `0x0067a750` | constructor/factory reads | localization provider, not owner |
| `g_packetSender` `0x0067a7ec` | handler/helper reads amid broad fanout | shared network state, not owner |

## Documentation Evidence And IDA Status

- Evidence-time / pre-callback UID0002N8 supported the class owner, exact three bases, paired stores, active slot, and successor boundary but lacked all-slot/RTTI/no-padding/hash/formal detail. Validator `000000010217` applied `91/94`, owner/emitter UID0000CW, position 40, Nested 0, the exact marker, and the complete evidence set.
- Evidence-time / pre-callback UID0000CW had the correct inheritance, prompt constant, source route, children, and packet behavior, but its `override` token contradicted table comparison. Validator `000000010221` applied `90/92`, position 0, no-added-fields/implicit-destructor detail, and the exact `virtual void OnConfirmInput();` declaration while preserving the invalid token as history.
- UID0003O5, UID0003O7, and UID0001KQ formal bodies agreed with independent live revalidation. Validators `000000010227`, `000000010232`, and `000000010248` preserved those bodies/scores and applied positions 10, 30, and 60 plus synchronized evidence.
- Evidence-time / pre-callback UID0003O6 had exact behavior but blank C++. Validator `000000010224` applied `90/92`, position 20, and the exact active method body with its inline send tail.
- Evidence-time / pre-callback UID0003HM had the exact child relation but lacked all-slot/RTTI/no-handwritten-data detail and a formal marker. Validator `000000010218` applied `90/94`, owner/emitter UID0000CW, position 50, the exact marker, and the complete relationship/ABI evidence.
- UID0001MU remains a non-emitting inventory. UID00026W and UID0001XA remain mixed-owner non-emitting aggregates. UID0001N6 remains compiler-only. Callback readback found no concrete drift, so all four verify-only pages remained unedited.
- UID0000NM remains the immediate source route at applied `89/91` after validator `000000010266`. Its text now records the full deterministic unit and keeps CommandInputPanes only as a coordinated future possibility; it has no by-file reconstruction metadata or formal block.
- Evidence-time / pre-callback generated output had one class and one factory, omitted constructor/confirm/helper, and contained a UID0002N8 Empty Emitter Marker. Waited validator `000000010268` regenerated the accepted unit without manual generated edits; current callback readback has exactly one class/constructor/confirm/helper/factory and two markers in positions 0/10/20/30/40/50/60, with zero Empty Emitter Markers and no handwritten ABI data/wrappers.
- Manual coverage status is not current for several affected pages. Exact supervisor-owned replacement/addition text is supplied in the dedicated section; validator-generated coverage is not treated as satisfying this requirement.

## Ranked Ownership Analysis

### 1. UID0000CW SelfSaveInputPane class

- Evidence for: exact RTTI type, inheritance, all three vptr stores, class-specific final virtual, constructor, confirm handler, prompt id, packet opcode, and current direct owner metadata.
- Evidence against: the precise historical source file may have been a broader command-input unit, but file grouping does not weaken semantic class ownership.
- Decision: accepted direct semantic owner and class emitter for UID0002N8, UID0003HM, UID0003O5, UID0003O6, and UID0003O7.

### 2. UID0000NM SelfSaveInputPane file

- Evidence for: current dedicated route already owns/emits UID0000CW and UID0001KQ; all source-bearing SelfSave details form a coherent one-class unit.
- Evidence against: neighboring classes suggest a possible historical CommandInputPanes grouping, and no original source archive identifies the file.
- Decision: accepted immediate source file and callback destination. Confidence capped; no partial move.

### 3. UID0001XA / UID00026W aggregates

- Evidence for: both index the exact target and neighboring input-pane vtables.
- Evidence against: both are mixed-owner, `NONE/FALSE`, and cannot own one class's source emission without duplicating class/file ownership.
- Decision: rejected as direct owners; preserve as verify-only non-emitting inventories.

### 4. UID0000ID CommandInputPanes

- Evidence for: neighboring command/spell/self-save/block-list classes plausibly shared a historical source module.
- Evidence against: current owner graph uses UID0000NM, and moving one target or child would split the source unit and create duplicate/ordering risk.
- Decision: reject for this callback. Preserve only a coordinated future grouping note.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Keep `NexusTK/ui/dialogs/SelfSaveInputPane.cpp` under UID0000NM.
- Likely full contents: class declaration, constructor, active confirm method, retained file-local send helper, retained factory, and compiler-generated vtables/RTTI/destructor wrappers.
- Candidate related items that belong: UID0000CW, UID0003O5, UID0003O6, UID0003O7, UID0002N8, UID0003HM, UID0001KQ.
- Candidate related items rejected: broad UID0001MU/UID00026W/UID0001XA indexes, shared UID0001N6 adjustors, BlockListen successor, SelfSaveOK feature sibling, and provider globals/resources.
- Standalone, narrow, or broad source-file inference: narrow standalone route retained now; broader command-input consolidation remains unproven future work.

## Source Placement

- Recommended source file/class/global/module placement: UID0000CW and class-owned children emit under UID0000NM at `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`; UID0001KQ remains a file-owned helper in the same output.
- Deterministic positions: class `0`; constructor `10`; confirm `20`; retained helper `30`; UID0002N8 marker `40`; UID0003HM marker `50`; factory `60`.
- Why this fits: it preserves current source ownership, groups every class-specific body and generated-data disposition, and avoids cross-file declarations or duplicated ABI data.
- Rejected placements: raw `.rdata` arrays, separate vtable source, class-member factory/helper declarations, a partial CommandInputPanes move, InputPanes base infrastructure, BlockListen successor source, SelfSaveOK source, resource/global provider pages.
- Remaining uncertainty: original historical file grouping is not recoverable from current symbols/routes. This caps scores but does not block a coherent generated unit.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is `[0x006305c0,0x00630648)`. Do not widen left across the SelfSave primary COL at `0x006305bc` into the WearInputPane tertiary table at `0x006305b4`, or right to the BlockListen COL at `0x00630648`.
- Primary table: `[0x006305c0,0x0063060c)`, 76 bytes.
- Secondary locator cell: `[0x0063060c,0x00630610)`, four bytes, points to COL with object offset `0xa0`.
- Secondary table: `[0x00630610,0x0063063c)`, 44 bytes.
- Tertiary locator cell: `[0x0063063c,0x00630640)`, four bytes, points to COL with object offset `0xa4`.
- Tertiary table: `[0x00630640,0x00630648)`, 8 bytes.
- No bytes in the target are padding. No bytes are source-authored constants. All target bytes are compiler-emitted vtable slots or RTTI locator references.
- No split/merge/new child is recommended. One target page best expresses one class-owned generated binary cluster.
- UID0001MU remains the method-island semantic inventory and is not a parent emitter. UID00026W remains the broad mixed-owner memory index. UID0001XA remains the broad mixed-owner type index. UID0003HM remains the narrow source-local type page linked one-to-one to the exact target.
- The class's implicit destructor causes the scalar wrapper and adjustors; no compiler-wrapper child or formal source body should be added.

## Negative Evidence Summary

- No exact UID0002N8 report exists in central executed, archive, legacy, older, special, or active report roots.
- No ordinary direct route reaches raw constructor `0x005b67c0`, retained helper `0x005b6870`, or factory `0x005aa140`; these are retained source with explicit liveness caps, not proof of non-source bytes.
- No branch from active `0x005b6800` calls the retained helper. Source must preserve duplicate inline send behavior.
- No base primary table exposes a virtual at SelfSave's final slot. `override` is rejected.
- No SelfSave-specific persistent field writes occur after inherited `0x108` construction. No reserve field is justified.
- No explicit source destructor behavior appears. The scalar deleting destructor and two adjustors are high-fanout compiler ABI wrappers.
- No padding occurs in UID0002N8. The apparent gaps are exact RTTI locator cells.
- No evidence supports literal table arrays, a separate vtable source file, a class-member factory, a class-member send helper, a partial CommandInputPanes move, or ownership by resource/network providers.
- Consumer/provider xrefs to `g_pLanguageMan`, `g_packetSender`, packet helpers, base panes, or BlockListen adjacency do not transfer semantic ownership from SelfSave.

## IDA Rename / Type / Comment Recommendations

- Source-facing class declaration: `SelfSaveInputPane : public CharInputPane` with `virtual void OnConfirmInput();` and `static const int kSelfSavePromptStringId = 0x26;`.
- Source-facing active method: `SelfSaveInputPane::OnConfirmInput` for `0x005b6800`.
- Source-facing retained helper: file-local `SendSelfSavePacket` for raw `0x005b6870`.
- Source-facing retained factory: file-level `CreateSelfSaveInputPane` for `0x005aa140`.
- Vtable comments: primary complete-object view at `0x006305c0`; EventHandler view at `0x00630610` / object `+0xa0`; TimerHandler view at `0x00630640` / object `+0xa4`; internal cells at `0x0063060c/3c` are COL pointers.
- Preserve descriptive inherited-slot names unless a current symbol/declaration proves exact historical spelling. Do not promote descriptive labels to IDA facts.
- Reject `sub_5B6800`, `FUN_005b6800`, `virt_meth_0x5b6800`, `ctor_0x5b67c0`, control-character `SelfSaveInputPane\r`, raw vftable-address labels, and documentation slugs as source names.
- Reject an IDA function creation/rename/type edit in this report-only task. Current raw-start evidence is recorded, but IDA writes were not requested and are outside B002 report scope.

## First-Draft C++ Recommendation

- Eligible for draft C++: class declaration UID0000CW, constructor UID0003O5, active confirm method UID0003O6, retained helper UID0003O7, and retained factory UID0001KQ.
- No handwritten ABI C++: UID0002N8 and UID0003HM receive target-specific marker comments only. UID0001N6, scalar deleting destructor, RTTI cells, and broad aggregates remain blank/non-emitting.
- The following seven destination blocks are exact formal insertion text. No body-only or side-channel C++ is recommended.

### Destination 1: UID0002N8 target

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SelfSaveInputPane vtables and RTTI are compiler-generated from the class
// declaration and virtual methods. Do not hand-author the
// 0x006305c0-0x00630648 table or locator dwords as C++.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2: UID0003HM vtable type

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SelfSaveInputPaneVtables is the source-local index for UID0002N8.
// Regenerate the tables through SelfSaveInputPane; do not duplicate fixed
// vtable, RTTI, scalar-destructor, or adjustor-thunk bytes here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: UID0000CW class

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfSaveInputPane : public CharInputPane
{
public:
    SelfSaveInputPane();

protected:
    virtual void OnConfirmInput();

    static const int kSelfSavePromptStringId = 0x26;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: UID0003O6 active confirm handler

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfSaveInputPane::OnConfirmInput()
{
    if (TextLength() != 1)
        return;

    wchar_t response = 0;
    CopyText(&response, 1);
    if (response != L'y' && response != L'Y')
        return;

    char packet[2];
    PacketBufferWriteUInt8(static_cast<char>(0x25), packet);
    packet[1] = 0;

    QueueAndSendPacket(g_packetSender, packet, 1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5: UID0003O5 constructor, preserve exactly

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SelfSaveInputPane::SelfSaveInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(kSelfSavePromptStringId))
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6: UID0003O7 retained helper, preserve exactly

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const unsigned char kSelfSavePacketOpcode = 0x25;

static void SendSelfSavePacket()
{
    char packet[2];

    PacketBufferWriteUInt8(static_cast<char>(kSelfSavePacketOpcode), packet);
    packet[1] = 0;

    QueueAndSendPacket(g_packetSender, packet, 1);
}
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7: UID0001KQ retained factory, preserve exactly

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SelfSaveInputPane *CreateSelfSaveInputPane()
{
    return new SelfSaveInputPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8: UID0000NM by-file source route, prose only

- Apply the complete contents/order/source-placement facts in `Recommended Support Doc Changes` and score `89/91`.
- Do not add `RECONSTRUCTION_CPP` metadata or a formal block to the by-file root. Its owned ordinary pages provide the emitted class and definitions.

### Destination 9: UID0001MU, UID00026W, and UID0001XA indexes, verify only

- Preserve current `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, exact child inventory, and semantic cross-references.
- Do not emit duplicate aggregate source. Edit only if callback-time concrete drift contradicts the accepted target relationship and the supervisor permits the bounded repair.

### Destination 10: UID0001N6 and shared scalar-destructor support, verify only

- Preserve UID0001N6 `NONE/FALSE/blank` and the compiler-generated `+0xa0/+0xa4` adjustor disposition.
- Do not create a child, declaration, destructor body, thunk body, or vtable slot definition for shared scalar wrapper `0x005b7940` or adjustors `0x005b77c8/0x005b77d3`.

- Reason behavior is preserved: the constructor uses the resource id, the active method retains both early returns and inline packet-send tail, the helper remains separately retained despite no route, the factory retains `new` null/EH semantics, and all ABI tables/wrappers are left to the compiler.
- Period plausibility: explicit `virtual` instead of C++11 `override`, C-style project-era pointer/layout types already used by surrounding docs, file-local unnamed namespace helper, simple early returns, and no modern library abstraction.
- Inferred names/types: `OnConfirmInput`, `SendSelfSavePacket`, `CreateSelfSaveInputPane`, `wchar_t`, `char[2]`, symbolic prompt id. These replace raw labels while matching current sibling conventions.
- Reason no literal vtable code should be emitted: target bytes are compiler output tied to inheritance, virtual declarations, RTTI, implicit destructor, and subobject adjustments. Literal tables would be ABI-specific duplicates and would not be source-identical.

## Final Recommendation

- Destinations 1-8 and C01-C30 are applied at report-level detail; Destinations 9-10 were read back unchanged.
- UID0002N8 remains one exact child with owner/emitter UID0000CW, score `91/94`, position `40`, `Nested:0`, and the formal compiler-generated marker.
- UID0003HM remains the one-to-one type page at `90/94`, position `50`, with the formal source-local-index marker.
- UID0000CW is `90/92`, position `0`, with no-added-fields layout, prompt constant, `virtual void OnConfirmInput();`, and no explicit destructor.
- UID0003O6 is `90/92`, position `20`, with the exact inline-send body.
- UID0003O5 `88/90`, UID0003O7 `87/88`, and UID0001KQ `87/88` preserve accepted bodies at positions `10`, `30`, and `60`.
- UID0000NM is `89/91` with complete source-unit prose and no by-file reconstruction metadata or formal block.
- UID0001MU, UID00026W, UID0001XA, and UID0001N6 remain non-emitting. No duplicate report/child or handwritten scalar destructor, adjustor thunk, RTTI, or vtable source was created.
- Future work outside this assignment: only a coordinated whole-unit source-file consolidation if independent source-tree evidence establishes CommandInputPanes as original. It is not a blocker for this reconstruction.

## Recommended Target Doc Changes

- Target path: `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md`.
- Applied metadata: `COMPLETION:91`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000CW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CW`, `EMITTER_POSITION_OPTIONAL:40`, `Nested:0`.
- Applied formal C++: Destination 1 exactly.
- Applied Item Summary: exact three-view compiler-generated SelfSave cluster; 19 primary slots, EventHandler `+0xa0` and TimerHandler `+0xa4` views, two internal RTTI locator cells, constructor/factory stores, active confirm slot, no padding/split, and no handwritten table bytes.
- Applied complete target hash/subhashes, dword/slot inventory, RTTI hierarchy, boundaries, store/xref inventory, active method relationship, implicit destructor/adjustor dispositions, no-added-field result, source ownership, source placement, rejected alternatives, negative evidence, score rationale, and historicalization of the former blank-C++/raw-constructor blocker.
- Valid historical evidence and changes remain preserved, with superseded statements labeled evidence-time/pre-source-quality assumptions.

## Recommended Support Doc Changes

- Applied `by-type/by-vtable/SelfSaveInputPaneVtables.md` UID0003HM at `90/94`, owner/emitter UID0000CW, position `50`, Destination 2 marker, and complete views/slots/RTTI/store/compiler-wrapper/no-duplicate detail.
- Applied `by-class/SelfSaveInputPane.md` UID0000CW at `90/92`, owner/emitter UID0000NM, position `0`, Destination 3 exact class block, implicit `0x108` layout/no added fields, new-virtual proof, no explicit destructor, complete child order/source route, and historicalized invalid `override`/handler blockers.
- Applied `by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md` UID0003O6 at `90/92`, owner/emitter UID0000CW, position `20`, Destination 4 body, and exact CFG/calls/types/packet/vtable/no-helper-call proof.
- Applied positions/synchronization while preserving Destination 5 UID0003O5 `88/90`, Destination 6 UID0003O7 `87/88`, and Destination 7 UID0001KQ `87/88` bodies and evidence.
- Applied `by-file/SelfSaveInputPane.md` UID0000NM `87/87 -> 89/91`, complete contents/order/source grouping/compiler-wrapper disposition, and generated expectation; no reconstruction metadata/formal block was added.
- Verified unchanged: UID0001MU, UID00026W, UID0001XA, UID0001N6, base/layout/resource/global/protocol dependencies. No concrete callback drift required edits.
- No new UIDs, reports, children, source files, compiler wrappers, or IDA changes.

## Score And Metadata Recommendation

| UID | Pre-callback | Applied | Owner | Reconstructable / emitter | Position |
| --- | --- | --- | --- | --- | --- |
| UID0002N8 | `86/90` | `91/94` | `0000CW` | `TRUE / 0000CW` | `40` |
| UID0003HM | `86/91` | `90/94` | `0000CW` | `TRUE / 0000CW` | `50` |
| UID0000CW | `87/89` | `90/92` | `0000NM` | `TRUE / 0000NM` | `0` |
| UID0003O5 | `88/90` | `88/90` | `0000CW` | `TRUE / 0000CW` | `10` |
| UID0003O6 | `86/88` | `90/92` | `0000CW` | `TRUE / 0000CW` | `20` |
| UID0003O7 | `87/88` | `87/88` | `0000CW` | `TRUE / 0000CW` | `30` |
| UID0001KQ | `87/88` | `87/88` | `0000NM` | `TRUE / 0000NM` | `60` |
| UID0000NM | `87/87` | `89/91` | `FILE` | file root | not applicable |
| UID0001MU | `88/89` | `88/89` | `0000CW` semantic | `FALSE / blank` | blank |
| UID00026W | `88/92` | `88/92` | `NONE` | `FALSE / blank` | blank |
| UID0001XA | `88/92` | `88/92` | `NONE` | `FALSE / blank` | blank |
| UID0001N6 | `88/92` | `88/92` | `NONE` | `FALSE / blank` | blank |

- Target completion rises because every target byte, slot, locator, RTTI relation, store, boundary, source owner, split decision, and formal disposition is resolved. It remains below final because exact historical names for inherited slots are not all recoverable and original file grouping is uncertain.
- Target confidence rises because current bytes/RTTI/xrefs and independent sibling revalidation agree. It remains below 95 because the no-route constructor/helper/factory state and missing original symbols are real evidence limits.
- Class/confirm scores rise because the base-virtual blocker, class-field question, destructor question, handler body, source signature, and formal emission are resolved. They remain capped by original naming/file uncertainty.
- File score rises because the complete source-bearing inventory and deterministic generation route are resolved. It remains below the target/class confidence because standalone versus coordinated historical grouping is still inferential.
- Score-improvement attempts: full slot enumeration removed the unknown-slot blocker; RTTI parsing removed subobject/layout blockers; base comparison removed `override` ambiguity; wrapper disassembly removed destructor/EH ABI blockers; route scans bounded liveness; source-tree comparison bounded file placement; manual coverage comparison identified supervisor-owned synchronization work.

## Open Questions With Attempted Resolution

- Is `OnConfirmInput` an override? Checked LineInputPane/CharInputPane primary tables and declarations. Resolution: no; it is a SelfSave-added virtual. Use `virtual`, not `override`.
- Do the two four-byte target gaps represent padding? Checked pointers, COL structures, and object offsets. Resolution: no; they are secondary/tertiary COL cells.
- Should target split into three children? Checked unified RTTI/type/store/source owner. Resolution: no; one class-generated cluster is the strongest model.
- Does SelfSave add unknown data fields? Checked `0x108` allocation, constructor/factory writes, inherited layout, and RTTI. Resolution: no defensible added field; do not reserve bytes.
- Is an explicit destructor needed? Checked scalar-wrapper body, flags, base cleanup, high fanout, and adjustors. Resolution: no; implicit derived destructor/compiler ABI is sufficient.
- Should confirm call the retained helper? Checked current instructions and routes. Resolution: no; preserve inline duplicated send tail.
- Are raw constructor/helper/factory live? Exhaustive direct branch/pointer/start searches found no route, while coherent unique bodies and class-specific stores/constants remain. Resolution: retain source with liveness caps; do not call them padding or compiler glue.
- What is the exact historical source file? Checked current file pages, neighboring command-input grouping, emitter graph, reports, and generated route. Resolution: keep UID0000NM now; only a coordinated future move is defensible.
- What are exact original names for every inherited slot? Checked function names, base docs, table comparisons, and method behavior. Resolution: roles are exact, some spellings remain descriptive. This does not block source because base declarations own them; it caps score only.
- Is manual coverage not applicable? No. Read-only inspection found stale and absent rows. Exact supervisor text follows.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected `by-memory/-coverage-report.md`: UID0002N8 row exists but is stale at `80%` and lacks the resolved RTTI/no-padding/source disposition; UID0001MU exists but is stale at `reconstructable : 78%` despite current `FALSE`/`88`; UID0001KQ exists but is stale at `78%` despite current `87`; UID0003O5/UID0003O6/UID0003O7 rows are absent; UID00026W exists but is stale at `reconstructable : 82%` despite current `FALSE`/`88`; UID0001N6 exists but is stale at `80%` despite current `88`.
- Inspected `by-class/-coverage-report.md`: UID0000CW exists at `85%` and is stale relative to applied `90/92` and corrected virtual/source disposition.
- Inspected `by-file/-coverage-report.md`: UID0000NM exists at `86%` and is stale relative to applied `89/91` and complete source-bearing inventory.
- Inspected `by-type/by-vtable/-coverage-report.md`: UID0003HM exists at `86%` and is stale relative to applied `90/94`; UID0001XA exists as `ignored : 88% : very-strong` with the correct child inventory and needs no replacement.
- Inspected `by-resource/-coverage-report.md`: UID0001RP current row already records id `38` / `0x26`, exact current prompt text with trailing space, and SelfSave constructor consumption; no change proposed.
- Inspected `by-global/-coverage-report.md`: UID0000Q5 and UID0000RC rows remain provider-global descriptions and do not acquire SelfSave ownership; no change proposed.
- Dependency rows for CharInputPane UID00001P, LanguageMan helper UID00018U, and QueueAndSendPacket UID0001HU were inspected where present and remain current for this report's dependency-only use. Missing packet-scalar/base-helper rows are not new or changed pages in this recommendation, so no new manual row is requested for them.
- Manual coverage files are supervisor-owned. B002 must not apply the following text directly.

File/placement: `by-memory/-coverage-report.md`, replace the existing UID0001KQ row in place:

```text
    - [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) 0x005aa140-0x005aa1bf | function | SelfSaveInputPaneFactory : reconstructable : 87% : very-strong : Retained file-level `CreateSelfSaveInputPane` factory; exact `0x80` modeled extent, `0x108` allocation with null/EH path, prompt id `0x26`, `CharInputPane` construction, three SelfSave vptr stores, no-direct-route confidence cap, and source-ready `return new SelfSaveInputPane;` are documented.
```

File/placement: `by-memory/-coverage-report.md`, replace the existing UID0001MU row and insert the three child rows immediately below it:

```text
    - [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md) 0x005b67c0-0x005b68b1 | class method island | SelfSaveInputPane : ignored : 88% : very-strong : Non-emitting SelfSave method inventory; exact constructor, active confirmation handler, four-byte alignment, and retained send-helper children carry the source reconstruction without duplicate aggregate C++.
        - [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) 0x005b67c0-0x005b6800 | raw constructor | SelfSaveInputPaneConstructor : reconstructable : 88% : very-strong : Source-ready raw constructor using prompt id `0x26`, `CharInputPane` base construction, compiler vptr stores, exact boundaries, and a preserved no-direct-route confidence cap.
        - [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) 0x005b6800-0x005b686c | virtual method | SelfSaveInputPane::OnConfirmInput : reconstructable : 90% : very-strong : Exact vtable-routed one-character `y`/`Y` confirmation path with inline opcode `0x25` write, scratch terminator clear, one-byte queued send, and no forced call to the retained no-route helper.
        - [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) 0x005b6870-0x005b68b1 | retained raw helper | SendSelfSavePacket : reconstructable : 87% : strong : File-local source helper that writes opcode `0x25`, clears a non-transmitted scratch byte, queues one byte through `g_packetSender`, includes `ret` at `0x005b68b0`, and retains its exhaustive no-route caveat.
```

File/placement: `by-memory/-coverage-report.md`, replace the existing UID0001N6 row in place:

```text
    - [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md) : ignored : 88% : very-strong : Compiler-generated shared input-pane scalar-destructor adjustors; SelfSave uses the exact `this -= 0xa0` and `this -= 0xa4` tails, with no handwritten source body or emitter.
```

File/placement: `by-memory/-coverage-report.md`, replace the existing UID00026W row in place:

```text
    - [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md) 0x0062ef0c-0x006307ec | vtable-data aggregate | UserPaneInputVtables : ignored : 88% : very-strong : Parentless mixed-owner vtable inventory; exact source-local children, including UID0002N8 SelfSave, carry ownership and generated-binary dispositions while the aggregate remains NONE/FALSE with blank C++.
```

File/placement: `by-memory/-coverage-report.md`, replace the existing UID0002N8 row in place under UID00026W:

```text
        - [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) 0x006305c0-0x00630648 | vtable-data | SelfSaveInputPaneVtableData : reconstructable : 91% : very-strong : Exact `0x88`-byte compiler-generated SelfSave cluster with 19 primary slots, EventHandler `+0xa0` and TimerHandler `+0xa4` views, two internal RTTI locator cells, paired constructor/factory stores, active confirmation slot, no padding/split, and no handwritten table bytes.
```

File/placement: `by-class/-coverage-report.md`, replace UID0000CW in place:

```text
- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) : reconstructable : 90% : very-strong : `CharInputPane`-derived self-save confirmation class with exact `0x108` inherited extent, prompt id `0x26`, source-ready constructor/confirm/helper/factory route, new `virtual OnConfirmInput` declaration, implicit-destructor/compiler-vtable disposition, deterministic child order, and opcode `0x25` behavior.
```

File/placement: `by-file/-coverage-report.md`, replace UID0000NM in place:

```text
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) : reconstructable : 89% : very-strong : Immediate `NexusTK/ui/dialogs/SelfSaveInputPane.cpp` route for the class, constructor, active confirmation method, retained packet helper, generated vtable/RTTI dispositions, and retained factory; preserves prompt id `0x26`, opcode `0x25`, no-route caps, and coordinated-only future CommandInputPanes consolidation.
```

File/placement: `by-type/by-vtable/-coverage-report.md`, replace UID0003HM in place:

```text
- [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md) : reconstructable : 90% : very-strong : Source-local index over exact UID0002N8 primary/EventHandler/TimerHandler table views; complete slot, RTTI, constructor/factory store, active handler, implicit scalar-destructor, adjustor-thunk, and no-handwritten-vtable dispositions are documented.
```

- Exact tracker text: no manual tracker edit is proposed. The lifecycle/report-count tracker is validator-owned and outside B002 write scope. The manual coverage replacements/additions above are the only supervisor-owned text required by the inspected affected rows.

## Follow-Up Actions

- B002 work is complete: Destinations 1-8 and C01-C30 are applied, Destinations 9-10 are verified unchanged, all leases are released, all scoped validators returned `ok: 1`, waited generation is current, and this report records exact proof.
- Manual coverage replacement/addition text remains preserved above for external supervisor-owned synchronization; B002 did not edit any manual `-coverage-report.md` file and does not assert whether that external update has occurred.
- Optional future IDA names/types/comments and a coordinated whole-unit CommandInputPanes consolidation remain outside this callback. Neither is a blocker to the applied source.
- Current/future report validation, path, count, execution, move, archive, tracker, and manual coverage state are external validator/supervisor-owned state and are not asserted or directed here.

## Confidence

- Recommendation confidence: `94/100` for owner, no-split/generated-binary disposition, three-view layout, RTTI offsets, active method route, and compiler-wrapper exclusion.
- Score confidence: `92/100`; applied scores are consistent with exact evidence and remaining original-symbol/source-file uncertainty.
- Remaining uncertainty: exact historical names for several inherited slots, original standalone-versus-command-family source file, and runtime route for retained raw constructor/helper/factory. These are bounded confidence caps, not blockers to the formal first draft.

## Validator Results

- All commands ran from `source-3/project-documentation` using `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; the final command added `--wait-generated`. The validator resolves the workspace junction to `C:\FastStorage\NTK_Sources\source-3\project-documentation` in its output.

| File / purpose | Command ID | Timestamp | Exit / ok | Warnings and side effects |
| --- | --- | --- | --- | --- |
| UID0002N8 target | `000000010217` | `2026-07-13T15:47:11-04:00` | `0 / 1` | Applied `91/94`, position `40`, blank-to-block registry; five transitional missing refs to UID0003HM/UID0003O6/UID0003O7 before their registration; projected stats update; generated refresh deferred. |
| UID0003HM vtable type | `000000010218` | `2026-07-13T15:48:18-04:00` | `0 / 1` | Added UID mapping/owner/`90/94`/position `50`/block; six transitional child refs before UID0003O5/6/7 registration; projected stats update; deferred refresh. |
| UID0000CW class | `000000010221` | `2026-07-13T15:49:46-04:00` | `0 / 1` | Applied `90/92`, position `0`, formal hash; transitional missing child refs; projected stats update; deferred refresh. |
| UID0003O6 confirm | `000000010224` | `2026-07-13T15:50:49-04:00` | `0 / 1` | Added header blank, UID mapping/owner/`90/92`/position `20`/block; six transitional UID0003O7 refs; projected stats update; deferred refresh. |
| UID0003O5 constructor | `000000010227` | `2026-07-13T15:52:06-04:00` | `0 / 1` | Added header blank, UID mapping/owner/position `10`; transitional UID0003O7 refs plus pre-existing unregistered dependency UID000363; projected stats update; deferred refresh. |
| UID0003O7 retained helper | `000000010232` | `2026-07-13T15:53:18-04:00` | `0 / 1` | Added header blank, UID mapping/owner/position `30`; no missing-ref warning; projected stats update; deferred refresh. |
| UID0001KQ factory | `000000010248` | `2026-07-13T15:54:05-04:00` | `0 / 1` | Applied position `60`; three pre-existing UID000363 dependency warnings; projected stats update; deferred refresh. |
| UID0000NM by-file | `000000010266` | `2026-07-13T15:56:37-04:00` | `0 / 1` | Applied `89/91`; three pre-existing UID000363 dependency warnings; projected stats update; deferred refresh. |
| Final target waited refresh | `000000010268` | `2026-07-13T15:57:05-04:00` | `0 / 1` | Registry rebuild, generated metadata/memory coverage/projected-stats refresh, unrelated global children/emitter warnings, unrelated missing TimerTotem source, and concurrent TransferServer generated update; no UID0002N8/SelfSave target failure; `generated_refresh: completed`. |

- Transitional UID0003O5/6/7/3HM warnings cleared as those accepted pages were registered; helper validator and final waited command contain no such missing refs. UID000363 is an existing CharInputPane-constructor dependency outside this callback and was not changed or used to excuse a target failure.
- Validator-generated side effects were not manually edited. Expected projected stats, registry, generated metadata, auto coverage, and C++ refreshes are validator-owned.
- Generated readback: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp`, header command `000000010268`, refresh time `2026-07-13T15:57:05-04:00`, SHA256 `D7F69DD271EA5C1AAE30214ACF6008818D2C0A6EF24C9CA992A8855F8423C783`.
- Exact order/readback lines: UID0000CW line `7`, UID0003O5 `19`, UID0003O6 `25`, UID0003O7 `43`, UID0002N8 `58`, UID0003HM `63`, UID0001KQ `68`.
- Exact counts: class `1`, constructor `1`, active confirm method `1`, retained helper `1`, factory `1`, target marker `1`, type marker `1`, Empty Emitter Marker `0`.
- Forbidden ABI readback: no emitted `0x005b7940`, `0x005b77c8`, or `0x005b77d3`; no explicit destructor, adjustor-thunk body, RTTI record, literal vtable array, duplicate method, or unresolved source route. Address `0x006305c0` occurs only inside target marker comments, not handwritten ABI source.
- Lease proof: every leaser acquire and release returned `Success`; each lease covered only one ordinary page through its scoped validator. Final read-only lease report at `2026-07-13T16:02:20.9716099-04:00` shows no B002 lease active.

## Changed Files

- Modified ordinary pages and callback-readback SHA256:

| Path | SHA256 |
| --- | --- |
| `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md` | `E2E7444EB873F712BA1F72712E73CDAF7A1AF44C7E9D11C997F53CA04CB47A6A` |
| `by-type/by-vtable/SelfSaveInputPaneVtables.md` | `19B36DC60E8CDDC8D7811FF15AFEB20C58BBBA48347A410EF2D2E243C85C91B2` |
| `by-class/SelfSaveInputPane.md` | `122C6AA16CD9BE940B34EBBA78196116E52DFD8EA18DEF2B20298D29C9B8E3F0` |
| `by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md` | `191FF706AA05688CD72A19D1B33D250DCEDEF8A92892954779B1DE747D82E548` |
| `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md` | `B66D7DF310E65D1E9EEC4A2848F495F86193D3248D92D201A659275FFFB283F9` |
| `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md` | `A5E96A7D98CB3E94321C5170FFFFD6C22E046AD7C8A5E7055407F14FBD5933BB` |
| `by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md` | `32774A1981A939CFC579B16F6BE949E3F835AD0DF333A9B5B3933B9789A122BB` |
| `by-file/SelfSaveInputPane.md` | `F0E18F6C341B0FBF52830D2AC9BC79EBA6E5F67CE3B994277CB99778CD6B87E6` |

- Modified report: this same `tools/leaser/Agents/Agent-B002/research/0002N8-SelfSaveInputPaneVtableData-source-quality.md` with research preserved and callback proof added.
- Validator-owned generated readback: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp` SHA256 `D7F69DD271EA5C1AAE30214ACF6008818D2C0A6EF24C9CA992A8855F8423C783`; not manually edited.
- Verify-only ordinary pages: UID0001MU, UID00026W, UID0001XA, UID0001N6 and same-or-greater dependencies remained unedited.
- Manual coverage, generated/tracker/audit/supervisor/validator-state/lifecycle/IDA files: no manual edits. Exact manual coverage text remains in this report for external ownership.
- Renamed/created ordinary pages: none.
- Report execution/lifecycle: not run. B002 did not run `execute_report`, lifecycle/probe, move, archive, or equivalent commands.

## Fixed-Matrix Self-Review

| Gate | Result | Evidence in this report |
| --- | --- | --- |
| Provenance/target/path | PASS | Header, Target, Changed Files |
| Current state versus historical state | PASS | Current Target State, Supporting Research |
| Fresh live MCP and bounded target request | PASS | Supporting Research, Evidence Checked, IDA MCP Facts |
| Exact bytes/hash/range/boundaries | PASS | Evidence Checked, IDA MCP Facts, Range Analysis |
| All three views/all slots | PASS | IDA MCP Facts tables |
| RTTI hierarchy/object offsets | PASS | Heuristic table, IDA MCP Facts |
| Constructor/destructor/timer/event/confirm behavior | PASS | Heuristic table, inventories, formal blocks |
| Callers/xrefs/stores/negative routes | PASS | Direct Xref / Caller Inventory, Negative Evidence |
| Ownership/source placement | PASS | Ranked Ownership Analysis, Source Placement |
| Split/padding/compiler disposition | PASS | Range / Split / Padding / Reclassification Analysis |
| Score/C++ blockers resolved | PASS | Score And Metadata, Open Questions |
| Exact formal managed blocks | PASS | Destinations 1-7 |
| C01-C30 legal action vocabulary | PASS | Ledger uses only permitted actions |
| C01-C30 callback states | PASS | Every row is `applied`, `already-present`, or `excluded-with-reason` with separate destination proof |
| Executed/active/archive report search provenance | PASS | Evidence Checked lists terms, roots, matches, outcomes |
| Manual coverage row comparison | PASS | Exact Manual Supervisor-Owned Coverage Or Tracker Text |
| Checked implementation checklist | PASS | Gate 1 and callback phases below are checked with exact proof |
| No forbidden writes/lifecycle | PASS | Only accepted ordinary pages/report were manually edited; allowed validators ran; no lifecycle/probe/execute/move/archive command ran |
| Stale contradiction scan | PASS | Pre-callback states are historicalized; current applied state, generated proof, and archive-neutral lifecycle wording agree |

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation passed exact report SHA `F8E7AF735D88E72955952B59EF90D794FA8D9DEBF1E0EBE1442822D6563C9BCE` before implementation.
- [x] Target/support scope remained exactly UID0002N8, UID0003HM, UID0000CW, UID0003O6, UID0003O5, UID0003O7, UID0001KQ, and UID0000NM; verify-only pages remained unchanged.
- [x] Current target state and actual evidence are recorded, including evidence-time MCP, exact hashes, all slots, RTTI, stores, callers, wrappers, reports, generated source, and manual coverage rows.
- [x] Claim And Incorporation Ledger retained C01-C30 legal Action enums and now records legal callback states plus exact destination proof.
- [x] Applied metadata/scores: UID0002N8 `91/94` position 40; UID0003HM `90/94` position 50; UID0000CW `90/92` position 0; UID0003O6 `90/92` position 20; UID0000NM `89/91`; retained other scores with positions 10/30/60.
- [x] Score-limiting blockers resolved: complete slot/RTTI/range, class fields, new virtual, handler body, destructor/adjustors, retained-body liveness, source placement, generated route, and manual coverage state.
- [x] Owner/emitter/reconstructable state applied or preserved exactly as the score table states.
- [x] No split/rename/new child/report was created; one target remains and only the source-facing class declaration was corrected.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment decisions were applied/preserved; no IDA write occurred.
- [x] Exact Destinations 1-7 formal blocks were applied; Destination 8 prose was applied; Destinations 9-10 were verified unchanged.
- [x] Third-party import remains not applicable; this is NexusTK source/compiler output, not embedded third-party source.
- [x] Target/support facts were incorporated at report-level detail without compressing valid prior evidence.
- [x] Historical/stale assumptions, rejected alternatives, route negatives, and compiler-wrapper evidence were preserved and current wording synchronized.
- [x] Wave2/Wave3/simroot artifacts remain labeled historical evidence only.
- [x] Open questions are closed or bounded with exact confidence impact.
- [x] One scoped validator ran per changed ordinary page and the final authorized waited refresh completed.
- [x] Generated expectation and exact supervisor-owned manual coverage text remain recorded; B002 made no manual coverage edit.

Implementation callback pass:

- [x] Supervisor accepted exact Gate 1 artifact and authorized this callback.
- [x] Re-read every destination and the lease report before editing; no destination collision/drift required verify-only repair.
- [x] Leased one ordinary page at a time immediately before edit and released it immediately after scoped validation; final lease report has no B002 entry.
- [x] Applied UID0002N8 `91/94`, owner/emitter/position/Nested, full evidence, Item Summary, score rationale, and Destination 1 marker; validator `000000010217`.
- [x] Applied UID0003HM `90/94`, owner/emitter/position, complete relationship/ABI evidence, and Destination 2 marker; validator `000000010218`.
- [x] Applied UID0000CW `90/92`, position/layout/source details, `virtual` declaration, no `override`, and no explicit destructor; validator `000000010221`.
- [x] Applied UID0003O6 `90/92`, position/body and exact inline send without UID0003O7 call; validator `000000010224`.
- [x] Preserved UID0003O5/UID0003O7/UID0001KQ accepted bodies/scores, set positions `10/30/60`, and added accepted synchronization; validators `000000010227/000000010232/000000010248`.
- [x] Applied UID0000NM `89/91` and complete source placement/order prose without by-file reconstruction metadata; validator `000000010266`.
- [x] Read back UID0001MU, UID00026W, UID0001XA, and UID0001N6 unchanged at their accepted non-emitting dispositions; dependencies required no bounded repair.
- [x] Updated C01-C30 with legal callback states and separate destination/validator/generated proof.
- [x] Preserved all historical research, rejected alternatives, negative evidence, no-route caps, and manual coverage text.
- [x] Recorded every scoped validator command id, timestamp, exit, ok, warnings, side effects, and lease result.
- [x] Final `--wait-generated` command `000000010268` completed and exact order `0/10/20/30/40/50/60` was read back.
- [x] Generated readback has one class/constructor/confirm/helper/factory/two markers, zero Empty Emitter Markers, no duplicates, and no handwritten scalar destructor/adjustor/RTTI/vtable body.
- [x] Updated Current Target State, ledger, Validator Results, Changed Files, generated/lease proof, and this checklist archive-neutrally.
- [x] Manually edited no manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/IDA file; validator-owned side effects are recorded only.
- [x] Ran no `execute_report`, lifecycle/probe, move, archive, or equivalent command.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000010317","destination_path":"executed-b-agent-research/B002/0002N8-SelfSaveInputPaneVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002N8-SelfSaveInputPaneVtableData-source-quality.md","timestamp":"2026-07-13T16:19:44-04:00","uid":"0002N8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
