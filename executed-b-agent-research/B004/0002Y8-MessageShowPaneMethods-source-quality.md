** TARGET-REPORT-UID:0002Y8 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002Y8 MessageShowPaneMethods Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: reclassify UID0002Y8 `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md` as a reviewed non-emitting `MessageShowPane` method-cluster container, with exact source children for the constructor, ordinary destructor, text-row builder, and `SetWrappedText`, and exact no-source/generated children for the constructor EH cleanup, adjustor thunks, and scalar deleting destructor.
- Final disposition: UID0002Y8 is class-contained by [UID:000087] `MessageShowPane`, but it is not itself a source method, source object, or generated C++ emitter.
- Implementation callback result: supervisor Gate 1 passed for this artifact at SHA256 `D50A1AFEB354DF6A5C8AE8E9B735A2BDC4A0D4CEA1D59D032A9BFA664835858E`; B004 verified the accepted target/support by-* docs already contained the report-level implementation details, ran scoped validators for the dirty implementation doc set, released leases, and updated this report for supervisor execute review.
- Confidence: high for range/split/container, class owner, caller/vtable/singleton route, and no-code proof for the parent; medium-high for helper/member source-facing names and final `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` placement.

## Supporting Research

- Lifecycle/status notes: this is the current same-path B004 research artifact after supervisor Gate 1 acceptance and implementation callback. B004 verified that the accepted by-* implementation details were already present at same-or-greater report detail, ran scoped file validators, and updated this report's ledger/checklist. The report remains unexecuted and unarchived; supervisor execution is still pending.
- Historical repair context: the preexisting report text contained post-callback/applied-validator language before Gate 1 repair. That language was normalized for Gate 1, and this callback now records the current implementation/validation result without relying on stale lifecycle wording.
- MCP availability correction: the stale pinned session `7bfdc746` was not used. Current `idb_list` on 2026-07-06 showed live NexusTK session `b001-0001I5` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and `server_health` returned `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Callback scope: current target/support docs, generated tracker/coverage/output, executed B008 destructor report, and live IDA MCP evidence were used as inputs. B004 did not run `execute_report`, lifecycle/archive commands, registry repair commands, manual report/archive moves, generated/coverage manual edits, supervisor-ledger edits, broad validators, or IDA DB edits.

## Target

- Target UID: `0002Y8`.
- Target path: `source-3/project-documentation/by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`.
- Source queue/report row at assignment: generated tracker reported `86/89`, combined `87.5`, `reconstructable:true`, direct reports `0`.
- Current generated tracker row observed during repair: `88/91`, combined `89.5`, `reconstructable:false`, direct reports `0`, path `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`.
- Current supervisor classification: B004 implementation callback for UID0002Y8 after supervisor Gate 1 pass.
- Current scores and parent state seen in target doc: UID0002Y8 is already `88/91`, `CANONICAL_OWNER:000087`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++. This report recommends that state because the live evidence supports it.

## Current Target State

- Existing metadata observed on disk: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000087`, `RECONSTRUCTABLE:FALSE`, blank emitter fields, blank `RECONSTRUCTION_CPP CODE`.
- Existing owner/emitter/reconstructable state: class containment owner is [UID:000087] `MessageShowPane`; UID0002Y8 has no direct emitter route because it is only an audit/container page over multiple exact functions, generated glue, and padding.
- Existing C++/emitter state: UID0002Y8 formal C++ is blank. Current generated output emits source children UID0004HN, UID000492, UID0004HO, and UID0001C4 into `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`; UID0002Y8 itself appears as `not_reconstructable` in generated memory coverage.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: exact original field/helper spellings and final standalone `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` grouping remain below final-audit certainty. They limit child scores below `95`; they do not block the parent split/container recommendation.
- Related target/support docs checked: `by-class/MessageShowPane.md`, `by-file/MessageShowPane.md`, `by-file/MessageDialogs.md`, `by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md`, `by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md`, `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`, `by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md`, `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`, `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`, `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`, `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`, `by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md`, `by-global/g_pMessageShowPane.md`, `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`, and `by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md`.
- Current artifact/lifecycle status: this report remains in `tools/leaser/Agents/Agent-B004/research/`, has completed the B004 implementation callback, and is ready for supervisor Gate 2/execute review. It has not been executed or archived by B004.

## Executive Recommendation

- Best direct owner/source disposition: keep [UID:000087] `MessageShowPane` as the class containment owner and [UID:0000LB] `MessageShowPane` / `ui/dialogs/MessageShowPane.cpp` as the best current source-root route for exact source children.
- Target reclassification: UID0002Y8 should remain `RECONSTRUCTABLE:FALSE` with blank emitters and blank formal C++ because it spans multiple independent source methods, compiler-generated helper/thunk/wrapper bodies, and padding.
- Exact source-bearing children to preserve or create during callback:
  - Constructor: `0x00521da0-0x00521fc0`, current UID0004HN if already present, `MessageShowPaneConstructor`, owner/emitter UID000087, first-draft formal C++ supplied below.
  - Ordinary destructor: `0x00521fc0-0x00522025`, current UID000492, `MessageShowPaneDestructor`, owner/emitter UID000087, existing formal destructor C++ preserved.
  - Text-row builder: `0x00522030-0x00522530`, current UID0004HO if already present, `MessageShowPaneBuildTextButtons`, owner/emitter UID000087, first-draft formal C++ supplied below.
  - `SetWrappedText`: `0x00522530-0x005226ea`, current UID0001C4, owner/emitter UID000087, first-draft formal C++ supplied below if not already present.
- Generated/no-source children to preserve: UID0001C5 `0x005226f0-0x005226fb`, UID0001C6 `0x005226fb-0x00522711`, and UID0001C7 `0x00522720-0x005227c6` should stay `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, and blank formal C++.
- Exact condition before remaining lifecycle movement: supervisor must verify this callback claim-by-claim against the changed/validated docs and validator results before any supervisor-only `execute_report` lifecycle command.

## Supervisor Active Recheck

- Current supervisor/user instruction: resume UID0002Y8 using the updated B004 goal as an implementation callback after Gate 1 pass, use any current live NexusTK MCP session, apply/verify accepted report details in the listed target/support by-* docs, update this report's ledger/checklist, run scoped validators for changed by-* docs, release leases, and return `READY_FOR_SUPERVISOR_EXECUTE`.
- Split repair requirement: the assigned item is an overbroad method-cluster target. It cannot be represented safely as one aggregate C++ body because exact IDA functions, generated glue, and padding have different source dispositions.
- Source-bearing child status: the current docs already contain exact pages for UID0004HN constructor, UID000492 ordinary destructor, UID0004HO `BuildMessageTextButtons`, and UID0001C4 `SetWrappedText`; B004 verified those as already-present implementation state and validated the files.
- Generated support status: UID0001C5, UID0001C6, and UID0001C7 are exact compiler-generated/no-source support bodies; no source-bearing child is missing inside those ranges.

## Inference Research Guidance Check

- `by-structure.md` governs the recommendation: mixed aggregate/container pages should be `RECONSTRUCTABLE:FALSE` when they are audit/index pages and their exact children carry real source ownership.
- Existing documentation assumptions treated as uncertain: Wave2/Wave3 generated ownership of `0x00522530` by `FittingRoomDownloadControlPane`, the stale `g_pExtendedUIPane` alias for `0x0069b4f4`, generated helper/global names around `0x0069b3fc`, and final `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` source grouping.
- IDA facts separated from inference:
  - IDA fact: function starts/sizes, padding bytes, xrefs, vtable cells, singleton xrefs, caller/callee sets, and decompiled behavior.
  - Documentation evidence: current by-* docs and executed B008 report support destructor split and compiler-generated destructor-glue handling.
  - Inference: source-facing field/helper names such as `m_messageText`, `m_lineCount`, `m_wrappedLineCount`, `m_maxTextWidth`, `BuildMessageTextButtons`, `MeasureTextWidth`, `PaneRect`, and `ApplyMessagePaneBorder`.
- Wave2/Wave3 mentions found: yes, in support docs and generated history. They are treated as lead/history only and rejected where contradicted by current IDA MCP evidence.

## Heuristic / Inference Reanalysis And Validation

- Range/split heuristic: live MCP `lookup_funcs` proves UID0002Y8 spans exact functions at `0x00521da0`, `0x00521fc0`, `0x00522030`, `0x00522530`, `0x005226f0`, `0x005226fb`, `0x00522706`, and `0x00522720`, plus non-function padding at `0x00522025`, `0x005226ea`, `0x00522711`, and `0x005227c6`. This requires exact children and a non-emitting parent container.
- Owner/source heuristic: constructor and destructor paths write the three MessageShowPane vtable views and the `g_pMessageShowPane` singleton; packet helper UID0003UU only constructs or updates the singleton. That supports MessageShowPane ownership and rejects LivingObjectPane ownership for the overlay methods.
- Constructor child blocker: resolved into an implementation-ready exact child. It is source-authored constructor code with single packet-helper caller at `0x005ac17e`, vtable writes, singleton publication, text copy/wrap metrics, width clamp, and layer attach.
- Text-row builder child blocker: resolved into an implementation-ready exact child. It is vtable-referenced at the row-builder slot and contains stored text copy, newline splitting, width-based row advance, palette 143 shadow passes, palette 128 face passes, and text-button creation.
- `SetWrappedText` blank-C++ blocker: resolved into formal first-draft child C++. The method is source-authored, has a single packet-helper caller at `0x005ac150`, updates the same text metric fields as the constructor, reapplies bounds, and invalidates/refreshes pane output.
- Ordinary destructor/source-vs-wrapper blocker: resolved by existing executed B008 research. UID000492 carries the source destructor body; UID0001C7 is compiler scalar deleting destructor glue; UID0001C6 adjustor thunks and UID0001C5 EH cleanup are generated support.
- Generated-output pollution: an old aggregate emitter marker for UID0002Y8 would be wrong. The correct repair is to remove UID0002Y8 from emission and emit only exact source children.
- Source placement: `MessageShowPane.cpp` under `ui/dialogs/` is the best current placement because the class, singleton, vtables, and generated output already converge there. A compact `MessageDialogs.cpp` grouping remains plausible historical grouping but is weaker because UID0003UU belongs to LivingObjectPane packet handling and MessageShowPane has a coherent class/singleton/source cluster.
- Rejected alternatives:
  - Keep UID0002Y8 reconstructable/emitting: rejected because it would synthesize one source body over unrelated functions, generated glue, and padding.
  - Assign UID0003UU packet helper to MessageShowPane: rejected because it is an external local-player packet helper and only consumes the overlay API.
  - Treat scalar deleting destructor UID0001C7 as source destructor: rejected by duplicate ordinary destructor body plus delete-flag wrapper behavior.
  - Reuse `FittingRoomDownloadControlPane` owner for `0x00522530`: rejected by the single packet-helper caller and MessageShowPane `this`-layout behavior.
  - Treat `0x0069b3fc` as MessageShowPane-owned `g_applyMessagePaneBorder`: rejected as unsupported by current xrefs; keep it as a broad UI callback/table dependency.

## Evidence Standards Used

- Evidence types used: live IDA MCP `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `callees`, `analyze_function`, and `disasm`; current by-* docs; generated tracker/memory coverage/generated C++ as state inputs; executed B008 destructor report as prior accepted research.
- Evidence strength: exact binary function boundaries, padding bytes, caller/xref counts, vtable/singleton xrefs, and callee/decompile summaries are strong enough to decide range, owner, generated support, and parent no-code disposition.
- Confidence limit: original source archive/debug symbols are not available, so exact helper/member spellings and final source-file grouping remain inferred. Scores stay below `95` for the affected items.
- Tool limitation: MCP evidence was gathered from current session `b001-0001I5`; stale session `7bfdc746` was intentionally ignored per updated supervisor instruction.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: live session `b001-0001I5`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - `server_health`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `module:NexusTK.exe`, imagebase `0x400000`.
  - `lookup_funcs`: confirmed functions and sizes at `0x00521da0` `0x220`, `0x00521fc0` `0x65`, `0x00522030` `0x500`, `0x00522530` `0x1ba`, `0x005226f0` `0x0b`, `0x005226fb` `0x0b`, `0x00522706` `0x0b`, and `0x00522720` `0xa6`; confirmed `0x00521d94`, `0x00522025`, `0x005226ea`, `0x00522711`, and `0x005227c6` are not function starts.
  - `get_bytes`: confirmed `0x00522025-0x00522030` eleven `0xcc` bytes, `0x005226ea-0x005226f0` six `0xcc` bytes, and `0x00522711-0x00522720` fifteen `0xcc` bytes.
  - `xrefs_to`: confirmed one constructor code xref at `0x005ac17e`, one `SetWrappedText` code xref at `0x005ac150`, one text-builder vtable/data xref at `0x0061fa90`, one EH helper xref at `0x00603e07`, adjustor/vtable refs for the thunks, three refs to scalar wrapper `0x00522720`, eight refs to singleton `0x0069b4f4`, and three refs each to the primary/secondary/tertiary vtable bases.
  - `callees`: checked constructor, ordinary destructor, text-builder, `SetWrappedText`, scalar wrapper, and packet helper. Packet helper calls `MultiByteToWideChar`, `0x00522530`, allocator/delete helper, and `0x00521da0`.
  - `analyze_function`: checked constructor, ordinary destructor, text-builder, `SetWrappedText`, and scalar wrapper; decompilation summaries include `wcscpy_s`, `wcsstr`, `288`-pixel width logic, `0x0069b4f4` singleton use, and `0x0069b364` render-layer use where expected.
  - `disasm`: checked UID0001C5 and UID0001C6 bodies. UID0001C5 is `mov dword ptr unk_69B4F4, 0; retn`; UID0001C6 thunks are `sub ecx, 0A0h; jmp sub_522720` and `sub ecx, 0A4h; jmp sub_522720`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target/support docs listed in Current Target State; generated `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`; generated `auto-generated/-ag-memory-coverage.md`; generated `auto-generated/-ag-research-tracker.md`; executed B008 UID0001C7 report.
- Negative checks performed: non-function boundary checks, padding byte checks, caller/xref checks rejecting LivingObjectPane ownership, generated alias rejection for `FittingRoomDownloadControlPane` and `g_pExtendedUIPane`, scalar-wrapper no-code proof, and support-doc check preserving `MessageDialogs.cpp` as a caveat rather than primary placement.
- Failed, unavailable, or intentionally skipped checks and why: no broad validators, lifecycle/archive commands, registry repair commands, IDA DB mutations, manual generated/coverage edits, supervisor-ledger edits, or manual report/archive moves were run. Scoped file validators were run only for the target/support by-* implementation set.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0002Y8 is an overbroad MessageShowPane method-cluster container, not a single source method. | High | MCP function inventory plus padding byte checks. | `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md` Item Summary, Status, Parent No-Code Proof | incorporate | already-present |
| C2 | UID0002Y8 should be `RECONSTRUCTABLE:FALSE`, owner UID000087, blank emitters, and blank formal C++. | High | by-structure container rule; exact source/generator children cover real bodies. | `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md` metadata and blank C++ block | incorporate | already-present |
| C3 | Constructor source child is exact range `0x00521da0-0x00521fc0`. | High | `lookup_funcs`, constructor caller `0x005ac17e`, vtable/singleton writes, constructor callees. | `by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md` metadata, Status, Behavior, Evidence, formal C++ | incorporate | already-present |
| C4 | Text-row builder source child is exact range `0x00522030-0x00522530`. | High | `lookup_funcs`, vtable/data xref `0x0061fa90`, row-builder callees and behavior. | `by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md` metadata, Status, Behavior, Evidence, formal C++ | incorporate | already-present |
| C5 | Ordinary destructor source body is UID000492 `0x00521fc0-0x00522025`; scalar wrapper UID0001C7 is no-source generated glue. | High | Executed B008 report; current MCP xrefs/callees; ordinary destructor and scalar wrapper analysis. | `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`; target child inventory; class/file support | incorporate | already-present |
| C6 | UID0001C4 `SetWrappedText` remains a source-authored MessageShowPane method and should carry first-draft formal C++. | High | One packet-helper caller at `0x005ac150`, text metric behavior, current class/file support. | `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md` metadata, Behavior, Evidence, Source Reconstruction, formal C++ | incorporate | already-present |
| C7 | UID0001C5, UID0001C6, and UID0001C7 are compiler-generated/no-source support. | High | EH helper disasm, adjustor thunk disasm, scalar wrapper delete-flag behavior. | target child inventory; `MessageShowPaneClearSingletonEH`, `MessageShowPaneAdjustorThunks`, and `MessageShowPaneScalarDeletingDestructor` support pages | incorporate | already-present |
| C8 | MessageShowPane class UID000087 is the correct direct semantic owner for source children. | High | Vtable refs, singleton xrefs, constructor/destructor/SetWrappedText behavior, class docs. | target/support metadata; `by-class/MessageShowPane.md` Status and Method Map | incorporate | already-present |
| C9 | `MessageShowPane.cpp` UID0000LB is the best current source placement, with `MessageDialogs.cpp` retained as a caveat. | Medium-high | current file/class docs, generated path, coherent singleton/class cluster. | `by-file/MessageShowPane.md` Status, Hypothesis, Boundary Notes; `by-class/MessageShowPane.md` Status | incorporate | already-present |
| C10 | `LivingObjectPaneHandleMessageShowPacket` UID0003UU is an external packet-helper caller/dependency, not MessageShowPane source ownership. | High | packet helper caller/callee role and executed B011 support docs. | `by-file/MessageShowPane.md` Proposed Contents and Boundary Notes; `by-class/MessageShowPane.md` Method Map and Evidence Notes | incorporate | already-present |
| C11 | Historical `FittingRoomDownloadControlPane` ownership for `0x00522530` and `g_pExtendedUIPane` alias for `0x0069b4f4` are stale/rejected for this target. | High | current xrefs and docs show MessageShowPane singleton/update route. | target Stale Evidence; `SetWrappedText` Status/Evidence; `by-file/MessageShowPane.md` Boundary Notes | reject-stale | already-present |
| C12 | No manual supervisor-owned coverage/tracker text is required. | High | generated tracker/coverage are validator-owned; source by-* edits/validators refresh them. | Exact Manual Supervisor-Owned Coverage Or Tracker Text; Validator Results | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: exact function inventory, exact padding bytes, single constructor/update packet-helper callers, singleton xrefs, vtable refs, generated support disassembly, and child source method behavior all agree that UID0002Y8 is a cluster/container.
- Corroborating documentation/generated-report evidence: current target/class/file docs and generated memory coverage already represent UID0002Y8 as non-reconstructable and exact source children as coded/emitting through `MessageShowPane.cpp`.
- Strongest inference chain and why it is sufficient: the constructor, destructor, text builder, and `SetWrappedText` are independently bounded MessageShowPane source behaviors; the EH helper/thunks/scalar wrapper are compiler-generated; therefore a single parent source body would be synthetic and wrong.

## IDA MCP Facts

- Function/range facts:
  - `0x00521da0` `sub_521DA0`, size `0x220`, constructor range `0x00521da0-0x00521fc0`.
  - `0x00521fc0` `sub_521FC0`, size `0x65`, ordinary destructor range `0x00521fc0-0x00522025`.
  - `0x00522030` `sub_522030`, size `0x500`, text-row builder range `0x00522030-0x00522530`.
  - `0x00522530` `sub_522530`, size `0x1ba`, `SetWrappedText` range `0x00522530-0x005226ea`.
  - `0x005226f0`, `0x005226fb`, and `0x00522706` are each `0x0b` helper/thunk functions.
  - `0x00522720` `sub_522720`, size `0xa6`, scalar deleting destructor wrapper range `0x00522720-0x005227c6`.
- Data/table/padding facts:
  - `0x00522025-0x00522030`, `0x005226ea-0x005226f0`, and `0x00522711-0x00522720` are all `0xcc` padding.
  - Vtable/data refs point at `0x00522030`, `0x005226fb`, `0x00522706`, and `0x00522720`.
- Xref facts:
  - Constructor has one code xref from packet helper at `0x005ac17e`.
  - `SetWrappedText` has one code xref from packet helper at `0x005ac150`.
  - Singleton `0x0069b4f4` has eight lifecycle/packet/UI cleanup refs including constructor, destructor, EH helper, scalar wrapper, and packet helper.
  - Primary, secondary, and tertiary MessageShowPane vtable bases are written from constructor/destructor/scalar-wrapper contexts.
- Vtable/global/type facts:
  - `0x0061fa4c`, `0x0061fa98`, and `0x0061fac8` are the MessageShowPane vtable bases that tie the executable cluster to the class.
  - `0x0069b4f4` is the active `g_pMessageShowPane` singleton for constructor/destructor/update/packet lifecycle.
- Negative IDA facts:
  - Boundary addresses `0x00521d94`, `0x00522025`, `0x005226ea`, `0x00522711`, and `0x005227c6` are not functions.
  - UID0001C5 and UID0001C6 contain two-instruction generated bodies, not handwritten source methods.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00521da0-0x00521fc0` | UID0004HN / `by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md` | Source constructor | True | UID000087 | `89/91` recommended/present | Exact source child, first-draft C++ supplied. |
| `0x00521fc0-0x00522025` | UID000492 / `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md` | Ordinary destructor source body | True | UID000087 | `89/91` present | Existing exact source child from executed B008. |
| `0x00522025-0x00522030` | Padding | Inter-function `0xcc` padding | False | None | n/a | Non-code. |
| `0x00522030-0x00522530` | UID0004HO / `by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md` | Text-row/button builder | True | UID000087 | `88/90` recommended/present | Exact source child, first-draft C++ supplied. |
| `0x00522530-0x005226ea` | UID0001C4 / `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md` | Source update method | True | UID000087 | `88/91` recommended/present | Exact source child, first-draft C++ supplied. |
| `0x005226ea-0x005226f0` | Padding | Inter-function `0xcc` padding | False | None | n/a | Non-code. |
| `0x005226f0-0x005226fb` | UID0001C5 / `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md` | Constructor EH cleanup | False | None | `88/92` present | Generated/no-source support. |
| `0x005226fb-0x00522711` | UID0001C6 / `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md` | Two destructor adjustor thunks | False | None | `88/92` present | Generated/no-source support. |
| `0x00522711-0x00522720` | Padding | Inter-function `0xcc` padding | False | None | n/a | Non-code. |
| `0x00522720-0x005227c6` | UID0001C7 / `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md` | Scalar deleting destructor wrapper | False | None | `88/92` present | Generated/no-source support. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00521da0` constructor | one code xref at `0x005ac17e` in `sub_5AC070` | Packet helper constructs overlay when singleton is absent. |
| `0x00522030` text-row builder | data xref at `0x0061fa90` | Vtable/virtual route, not ordinary free helper. |
| `0x00522530` SetWrappedText | one code xref at `0x005ac150` in `sub_5AC070` | Packet helper updates existing overlay. |
| `0x005226f0` EH helper | code xref at `0x00603e07` from constructor EH/unwind context | Generated cleanup support. |
| `0x005226fb` / `0x00522706` thunks | vtable/data refs at `0x0061fa98` and `0x0061fac8`; jumps to `0x00522720` | Compiler adjustor thunks. |
| `0x00522720` scalar wrapper | xrefs from thunks at `0x00522701`/`0x0052270c` and vtable data at `0x0061fa4c` | Generated scalar deleting destructor support. |
| `0x0069b4f4` singleton | eight refs across constructor, destructor, EH helper, scalar wrapper, packet helper, and UI cleanup | Confirms `g_pMessageShowPane` lifecycle and stale alias rejection. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page currently records UID0002Y8 as non-emitting container; class/file pages list exact source children and generated support; child pages document formal source C++ or no-code proof; executed B008 report documents destructor split and scalar-wrapper no-code disposition.
- Existing docs that are stale, incomplete, or contradicted: current target/support docs now carry the accepted implementation details at same-or-greater report detail. Older Wave2/Wave3/generated `FittingRoomDownloadControlPane` and `g_pExtendedUIPane` claims remain stale for this target and are preserved as rejected history.
- Generated/coverage report state: generated tracker currently lists UID0002Y8 as `88/91`, reconstructable false. Generated memory coverage lists constructor/destructor/text-builder/SetWrappedText children as coded and UID0002Y8/UID0001C5/UID0001C6/UID0001C7 as not reconstructable. Generated C++ contains child source bodies under `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`. Generated files are validator-owned and were not edited.

## Ranked Ownership Analysis

### 1. MessageShowPane class UID000087

- Evidence for: constructor/destructor/scalar-wrapper vtable writes use MessageShowPane vtables; singleton `g_pMessageShowPane` is written/read across constructor/destructor/packet/update lifecycle; class/file docs already own this overlay; exact child behavior is class-specific.
- Evidence against: exact original field/helper names are inferred, and the final standalone source-file grouping remains not final-proof.
- Decision: best direct semantic owner for source children and containment owner for UID0002Y8.

### 2. MessageShowPane.cpp by-file UID0000LB

- Evidence for: current projected file path, generated output path, class/source grouping, singleton/global support, and support docs all route through `ui/dialogs/MessageShowPane.cpp`.
- Evidence against: compact `MessageDialogs.cpp` remains a plausible legacy grouping; generated output is lead/state, not original-source proof.
- Decision: best current emitter/file route for source children, with caveat preserved.

### 3. LivingObjectPane packet helper / UID0003UU

- Evidence for: packet helper is the only direct code caller for constructor and `SetWrappedText`.
- Evidence against: it is a consumer of the overlay API, not the object owner; it is reached from `UserPane::OnServerMessage` opcode `0x58`, converts packet text, and then constructs/updates/deletes the overlay through singleton logic.
- Decision: dependency/caller only; reject as owner/emitter for UID0002Y8 source children.

### 4. FittingRoomDownloadControlPane / stale generated owner

- Evidence for: older generated/cache material attached `0x00522530` there.
- Evidence against: current IDA xrefs, field layout, singleton route, class/file docs, and packet helper all support MessageShowPane.
- Decision: reject stale generated ownership.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new by-file page is recommended. Use existing [UID:0000LB] `by-file/MessageShowPane.md` and path `NexusTK/ui/dialogs/`.
- Likely full contents: `MessageShowPane` class source children, `g_pMessageShowPane` declaration/use, vtable/source declaration effects via class definition, and helper dependencies needed by the overlay.
- Candidate related items that belong: constructor, ordinary destructor, `BuildMessageTextButtons`, `SetWrappedText`, singleton declaration/use, vtable support documentation.
- Candidate related items rejected: UID0003UU packet helper, compiler EH cleanup, adjustor thunks, scalar deleting destructor wrapper, broad UI callback/table `0x0069b3fc` as MessageShowPane-owned global.
- Standalone, narrow, or broad source-file inference: standalone narrow `MessageShowPane.cpp` is best current placement, while compact dialog grouping remains a documented caveat.

## Source Placement

- Recommended source file/class/global/module placement: [UID:000087] `MessageShowPane` source children emitted through [UID:0000LB] `MessageShowPane` at `NexusTK/ui/dialogs/MessageShowPane.cpp`.
- Why this placement fits source-tree and subsystem context: the overlay is a dialog/UI pane with its own singleton, vtables, class docs, and generated output path. Its source methods form a coherent overlay class cluster.
- Rejected placements and why:
  - `LivingObjectPane.cpp`: rejected because UID0003UU is only packet-handler caller/dependency.
  - `FittingRoomDownloadControlPane.cpp`: rejected as stale generated ownership.
  - `MessageDialogs.cpp`: not rejected entirely, but weaker than standalone `MessageShowPane.cpp`; preserve as caveat.
- Remaining placement uncertainty, if any: exact original source-file grouping below final-audit certainty.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: live MCP `lookup_funcs` and `get_bytes` prove each child and padding range listed in the Function / Child Inventory.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: exact source children should be constructor, ordinary destructor, text builder, and `SetWrappedText`; generated/no-source children should be EH helper, adjustor thunks, and scalar wrapper; padding remains non-code. No merge is recommended.
- Padding/table/data/code distinctions: three `0xcc` padding gaps divide exact code bodies. Vtable/data refs support class ownership but do not convert generated wrappers into source methods.
- Parent/container impact: UID0002Y8 should remain a non-emitting reviewed container with class containment only.

## Negative Evidence Summary

- Consumer/caller evidence does not prove LivingObjectPane ownership: UID0003UU consumes overlay constructor/update methods but its packet context is external to the overlay class.
- Vtable refs to scalar wrapper/thunks do not prove source bodies: adjustor thunks and scalar deleting destructor are compiler-generated ABI artifacts.
- Generated ownership history does not override IDA: stale `FittingRoomDownloadControlPane` and `g_pExtendedUIPane` labels are contradicted by current xrefs and object behavior.
- The presence of child C++ in generated output does not validate the report. Gate 1 must stand on this report artifact; generated output is only current-state/read-only evidence.
- Lack of final original symbol spelling proof does not justify leaving source children blank; the behavior and owner route are strong enough for first-draft source-facing names while keeping scores below final-audit quality.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - Use `MessageShowPane::MessageShowPane(wchar_t *messageText)` for the constructor child.
  - Use `MessageShowPane::BuildMessageTextButtons()` for `0x00522030-0x00522530`.
  - Use `MessageShowPane::SetWrappedText(wchar_t *messageText)` for UID0001C4.
  - Use `m_messageText`, `m_lineCount`, `m_wrappedLineCount`, `m_maxTextWidth`, `PaneRect`, `MeasureTextWidth`, `g_wszNewline`, and `g_pRenderLayer1` as inferred source-facing names in formal first-draft child C++.
  - Use `ClearMessageShowPaneSingleton` only as descriptive documentation for the EH helper, not as a source method.
- Evidence for each proposed name/type/comment: method behavior, field offsets, singleton/vtable ownership, current docs, packet-helper route, and conventional mid-2000s UI pane naming.
- Items intentionally left unchanged and why: IDA DB labels/types were not changed; exact original helper/member spellings remain below final proof; `0x0069b3fc` is left as broad UI dependency rather than MessageShowPane-owned global.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested in this B-agent report-first assignment.

## First-Draft C++ Recommendation

- Eligible for draft C++:
  - UID0002Y8 parent: not eligible. It needs a target-specific no-code proof because it is a mixed container.
  - Constructor child UID0004HN: eligible, `89/91`, owner/emitter UID000087.
  - Ordinary destructor child UID000492: eligible and already has formal C++ from B008.
  - Text-row builder child UID0004HO: eligible, `88/90`, owner/emitter UID000087.
  - SetWrappedText child UID0001C4: eligible, `88/91`, owner/emitter UID000087.
  - UID0001C5/UID0001C6/UID0001C7: not eligible; generated/no-source.
- Recommended code for UID0002Y8 parent: leave formal `RECONSTRUCTION_CPP CODE` blank. Exact no-code proof: UID0002Y8 spans multiple source methods, generated EH/thunk/scalar-wrapper glue, and padding; aggregate emission would duplicate child source or create a synthetic function that was not original source.
- Recommended code for constructor child UID0004HN:

```cpp
MessageShowPane::MessageShowPane(wchar_t *messageText)
    : Pane(1)
{
    g_pMessageShowPane = this;

    m_lineCount = 0;
    m_wrappedLineCount = 0;
    m_maxTextWidth = 0;

    wcscpy_s(m_messageText, 0x8000, messageText);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, messageText);

    wchar_t *lineStart = textCopy;
    for (wchar_t *lineEnd = wcsstr(textCopy, g_wszNewline);
         lineEnd != NULL;
         lineEnd = wcsstr(lineEnd + 1, g_wszNewline))
    {
        *lineEnd = 0;
        ++m_lineCount;
        ++m_wrappedLineCount;

        const int lineWidth = MeasureTextWidth(lineStart);
        if (m_maxTextWidth < lineWidth)
            m_maxTextWidth = lineWidth;

        m_wrappedLineCount += (lineWidth - 1) / 288;
        lineStart = lineEnd + 1;
    }

    ++m_lineCount;
    ++m_wrappedLineCount;

    const int finalLineWidth = MeasureTextWidth(lineStart);
    if (m_maxTextWidth < finalLineWidth)
        m_maxTextWidth = finalLineWidth;

    m_wrappedLineCount += (finalLineWidth - 1) / 288;

    int paneWidth = m_maxTextWidth;
    if (paneWidth > 288)
        paneWidth = 288;
    m_maxTextWidth = paneWidth;

    PaneRect bounds(806 - paneWidth,
                    10,
                    809,
                    3 * (m_lineCount + 4 * m_wrappedLineCount + 3));
    AddToLayer(&bounds, 0, 0, g_pRenderLayer1);
}
```

- Recommended code for ordinary destructor child UID000492:

```cpp
MessageShowPane::~MessageShowPane()
{
    RemoveFromLayer();
    g_pMessageShowPane = NULL;
}
```

- Recommended code for text-row builder child UID0004HO:

```cpp
void MessageShowPane::BuildMessageTextButtons()
{
    PaneRect lineBounds;
    GetTextButtonBounds(&lineBounds);
    ClearTextButtons(false);
    ApplyMessagePaneBorder(this, &lineBounds);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, m_messageText);

    wchar_t *lineStart = textCopy;
    for (wchar_t *lineEnd = wcsstr(textCopy, g_wszNewline);
         lineEnd != NULL;
         lineEnd = wcsstr(lineEnd + 1, g_wszNewline))
    {
        *lineEnd = 0;

        const int lineWidth = MeasureTextWidth(lineStart);
        const int lineAdvance = 12 * ((lineWidth - 1) / 288) + 12;

        PaneRect textBounds = lineBounds;
        textBounds.right -= 3;
        textBounds.bottom = textBounds.top + lineAdvance + 2;

        const int textLength = static_cast<int>(wcslen(lineStart));

        SetTextPalette(143);
        OffsetPaneRect(&textBounds, 1, 0);
        AddTextButton(lineStart, textLength, &textBounds);
        OffsetPaneRect(&textBounds, 1, 0);
        AddTextButton(lineStart, textLength, &textBounds);
        OffsetPaneRect(&textBounds, -2, 1);
        AddTextButton(lineStart, textLength, &textBounds);
        OffsetPaneRect(&textBounds, 3, 0);
        AddTextButton(lineStart, textLength, &textBounds);
        OffsetPaneRect(&textBounds, -2, 1);
        AddTextButton(lineStart, textLength, &textBounds);
        OffsetPaneRect(&textBounds, 1, 0);
        AddTextButton(lineStart, textLength, &textBounds);

        SetTextPalette(128);
        OffsetPaneRect(&textBounds, -1, -1);
        AddTextButton(lineStart, textLength, &textBounds);
        OffsetPaneRect(&textBounds, 1, 0);
        AddTextButton(lineStart, textLength, &textBounds);

        OffsetPaneRect(&lineBounds, 0, lineAdvance + 3);
        lineStart = lineEnd + 1;
    }

    const int lineWidth = MeasureTextWidth(lineStart);
    const int lineAdvance = 12 * ((lineWidth - 1) / 288) + 12;

    PaneRect textBounds = lineBounds;
    textBounds.right -= 3;
    textBounds.bottom = textBounds.top + lineAdvance + 2;

    const int textLength = static_cast<int>(wcslen(lineStart));

    SetTextPalette(143);
    OffsetPaneRect(&textBounds, 1, 0);
    AddTextButton(lineStart, textLength, &textBounds);
    OffsetPaneRect(&textBounds, 1, 0);
    AddTextButton(lineStart, textLength, &textBounds);
    OffsetPaneRect(&textBounds, -2, 1);
    AddTextButton(lineStart, textLength, &textBounds);
    OffsetPaneRect(&textBounds, 3, 0);
    AddTextButton(lineStart, textLength, &textBounds);
    OffsetPaneRect(&textBounds, -2, 1);
    AddTextButton(lineStart, textLength, &textBounds);
    OffsetPaneRect(&textBounds, 1, 0);
    AddTextButton(lineStart, textLength, &textBounds);

    SetTextPalette(128);
    OffsetPaneRect(&textBounds, -1, -1);
    AddTextButton(lineStart, textLength, &textBounds);
    OffsetPaneRect(&textBounds, 1, 0);
    AddTextButton(lineStart, textLength, &textBounds);
}
```

- Recommended code for SetWrappedText child UID0001C4:

```cpp
void MessageShowPane::SetWrappedText(wchar_t *messageText)
{
    RemoveFromLayer();

    m_lineCount = 0;
    m_wrappedLineCount = 0;
    m_maxTextWidth = 0;

    wcscpy_s(m_messageText, 0x8000, messageText);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, messageText);

    wchar_t *lineStart = textCopy;
    for (wchar_t *lineEnd = wcsstr(textCopy, g_wszNewline);
         lineEnd != NULL;
         lineEnd = wcsstr(lineEnd + 1, g_wszNewline))
    {
        *lineEnd = 0;
        ++m_lineCount;
        ++m_wrappedLineCount;

        const int lineWidth = MeasureTextWidth(lineStart);
        if (m_maxTextWidth < lineWidth)
            m_maxTextWidth = lineWidth;

        m_wrappedLineCount += (lineWidth - 1) / 288;
        lineStart = lineEnd + 1;
    }

    ++m_lineCount;
    ++m_wrappedLineCount;

    const int finalLineWidth = MeasureTextWidth(lineStart);
    if (m_maxTextWidth < finalLineWidth)
        m_maxTextWidth = finalLineWidth;

    m_wrappedLineCount += (finalLineWidth - 1) / 288;

    int paneWidth = m_maxTextWidth;
    if (paneWidth > 288)
        paneWidth = 288;
    m_maxTextWidth = paneWidth;

    PaneRect bounds(806 - paneWidth,
                    10,
                    809,
                    3 * (m_lineCount + 4 * m_wrappedLineCount + 3));
    AddToLayer(&bounds, 0, 0, g_pRenderLayer1);
    InvalidateRect(&m_bounds);
}
```

- Third-party import directive, when applicable: not applicable; this is NexusTK-owned UI code, not a staged third-party embed.
- Reason it preserves exact original behavior: code preserves observed text copy, newline split, width measurement, width clamp, layer bounds, text button palette/offset sequence, singleton publication/clear, and update/create route while excluding compiler-generated vtable/EH/thunk/scalar-delete mechanics.
- Reason it matches plausible original mid-2000s source shape: simple class methods, stack wide-character scratch buffers, direct pane operations, and source-facing helper names fit the surrounding UI code style better than decompiler labels.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `m_messageText`, `m_lineCount`, `m_wrappedLineCount`, `m_maxTextWidth`, `PaneRect`, `MeasureTextWidth`, `GetTextButtonBounds`, `ClearTextButtons`, `ApplyMessagePaneBorder`, `SetTextPalette`, `OffsetPaneRect`, `AddTextButton`, `RemoveFromLayer`, `AddToLayer`, `InvalidateRect`, `g_wszNewline`, `g_pRenderLayer1`, `g_pMessageShowPane`.
- Naming/coding style convention used and evidence for consistency: `MessageShowPane::MethodName`, `m_` members, and `g_` globals match current class/global documentation and generated source-facing names already used across support docs.
- Reason code should remain blank, if applicable: UID0002Y8 parent and generated-support children must remain blank because they are container/compiler artifacts.
- Exact no-code proof, if not eligible: parent UID0002Y8 and support UIDs 0001C5/0001C6/0001C7 are not source-authored bodies; emitting them would duplicate child source or hand-port compiler artifacts.

## Final Recommendation

- Exact changes recommended:
  - Preserve or set UID0002Y8 as `88/91`, `CANONICAL_OWNER:000087`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank formal C++.
  - Preserve or create constructor child UID0004HN at `0x00521da0-0x00521fc0` with owner/emitter UID000087, `89/91`, and constructor C++ above.
  - Preserve ordinary destructor child UID000492 as source child with owner/emitter UID000087 and destructor C++ above.
  - Preserve or create text-row builder child UID0004HO at `0x00522030-0x00522530` with owner/emitter UID000087, `88/90`, and text-builder C++ above.
  - Preserve or update UID0001C4 with owner/emitter UID000087, `88/91`, and SetWrappedText C++ above.
  - Preserve UID0001C5/UID0001C6/UID0001C7 as generated/no-source support.
- Exact parent assignments recommended: UID0002Y8 containment owner UID000087; source child owner/emitter UID000087; generated support owner/emitter none.
- Exact items left no-owner/non-emitting and why: UID0002Y8 is non-emitting container; UID0001C5/UID0001C6/UID0001C7 are compiler-generated support; padding ranges are non-code.
- Exact future work outside this assignment scope: final-source audit of exact original helper/member spellings and final `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` grouping.

## Recommended Target Doc Changes

- Target path: `source-3/project-documentation/by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`.
- Exact report facts to incorporate:
  - UID0002Y8 is a reviewed non-emitting MessageShowPane method-cluster container.
  - Child inventory must list constructor UID0004HN, ordinary destructor UID000492, BuildMessageTextButtons UID0004HO, SetWrappedText UID0001C4, generated EH helper UID0001C5, generated adjustor thunks UID0001C6, generated scalar wrapper UID0001C7, and exact `0xcc` padding gaps.
  - Parent no-code proof must state that aggregate C++ would duplicate source children or synthesize a non-source function.
  - Stale FittingRoomDownloadControlPane/g_pExtendedUIPane/generated aggregate assumptions must be preserved as rejected history.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Recommended state: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000087`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
  - If the current target already matches, callback should verify it and leave it unchanged.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: generated old aggregate emitter, FittingRoomDownloadControlPane owner, `g_pExtendedUIPane` alias, LivingObjectPane owner alternative, scalar wrapper as source destructor alternative, and broad UI callback/table ownership by MessageShowPane.

## Recommended Support Doc Changes

- Support path: `source-3/project-documentation/by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md`.
  - Exact report facts to incorporate: exact constructor range, single packet-helper caller, vtable/singleton writes, text copy/wrap metrics, 288-pixel clamp, layer attach, and formal constructor C++.
  - Metadata/link/score/coverage/source-placement changes: use or preserve UID0004HN, `89/91`, owner/emitter UID000087, reconstructable true.
- Support path: `source-3/project-documentation/by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md`.
  - Exact report facts to incorporate: exact text-builder range, vtable/data xref, stored text copy, newline split, palette 143/128 pass sequence, text-button helper calls, and formal text-builder C++.
  - Metadata/link/score/coverage/source-placement changes: use or preserve UID0004HO, `88/90`, owner/emitter UID000087, reconstructable true.
- Support path: `source-3/project-documentation/by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`.
  - Exact report facts to incorporate: owner/emitter UID000087, single packet-helper caller, constructor-parallel text metric logic, layer/bounds refresh, and formal SetWrappedText C++.
  - Metadata/link/score/coverage/source-placement changes: `88/91`, reconstructable true, owner/emitter UID000087.
- Support path: `source-3/project-documentation/by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`.
  - Exact report facts to incorporate: ordinary source destructor body; preserve B008 destructor C++ and wrapper split.
  - Metadata/link/score/coverage/source-placement changes: no change if already `89/91`, owner/emitter UID000087.
- Support paths: `source-3/project-documentation/by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`, `source-3/project-documentation/by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`, and `source-3/project-documentation/by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`.
  - Exact report facts to incorporate: generated/no-source dispositions and cross-links to the source children.
  - Metadata/link/score/coverage/source-placement changes: no change if already no-owner/non-reconstructable/blank emitters/blank C++.
- Support paths: `source-3/project-documentation/by-class/MessageShowPane.md` and `source-3/project-documentation/by-file/MessageShowPane.md`.
  - Exact report facts to incorporate: exact source children, UID0002Y8 as non-emitting container, UID0003UU as external packet-helper dependency, `MessageShowPane.cpp` best placement, `MessageDialogs.cpp` caveat, stale generated ownership rejection, and broad `0x0069b3fc` dependency not MessageShowPane-owned.
  - Metadata/link/score/coverage/source-placement changes: keep class/file scores unless callback supervisor requests a score change; this report does not recommend raising them above current `86/88` and `86/87`.
- Generated/validator-owned support: do not manually edit generated reports, generated C++ output, coverage reports, validator state, or supervisor ledgers.

## Score And Metadata Recommendation

- Current score/metadata: UID0002Y8 currently reads `88/91`, `CANONICAL_OWNER:000087`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank formal C++.
- Recommended score/metadata: keep exactly that state.
- Score rationale and reason not higher/lower:
  - Higher than assignment `86/89` because current MCP evidence resolves exact child ranges, padding, source-vs-generated split, caller/vtable/singleton route, and parent no-code proof.
  - Not higher than `88/91` because UID0002Y8 is a container, not a final source body, and exact original helper/member spellings plus final source-file grouping remain inferred on children/support docs.
  - Not lower because every material range/split/ownership/source-vs-generated blocker for the parent has an implementation-ready recommendation.
- Score-improvement attempt:
  - Range/split blocker: resolved by `lookup_funcs` and padding `get_bytes`.
  - Ownership blocker: resolved by vtable/singleton/caller evidence; class UID000087 is supported.
  - Emitter/blocker: resolved by parent no-code proof and exact child emitter recommendations.
  - Generated alias blocker: stale generated owner/alias claims checked and rejected.
  - First-draft C++ blocker: parent has exact no-code proof; source children have formal first-draft C++ recommendations.
  - Source placement blocker: researched through file/class docs/generated path; `MessageShowPane.cpp` remains best current placement with caveat.
- Metadata fields to change or leave unchanged: leave UID0002Y8 as non-emitting container; create/preserve child metadata as listed; do not assign generated support as source-owned emitters.

## Open Questions With Attempted Resolution

- Open question found: Is UID0002Y8 itself a source-emitting method body?
  - Evidence checked: exact function inventory, padding bytes, decompile summaries, generated state, current child docs.
  - Best supported resolution: no. It is a container over source children, generated glue, and padding.
- Open question found: Does constructor range need an exact child?
  - Evidence checked: function size, caller, vtable/singleton writes, constructor text-wrap behavior.
  - Best supported resolution: yes, exact child UID0004HN/current path if present, with first-draft formal C++.
- Open question found: Does text-row builder range need an exact child?
  - Evidence checked: function size, vtable/data xref, callees, palette/text row behavior.
  - Best supported resolution: yes, exact child UID0004HO/current path if present, with first-draft formal C++.
- Open question found: Can SetWrappedText remain blank?
  - Evidence checked: current score/owner/emitter, single caller, constructor-parallel logic, source method behavior.
  - Best supported resolution: no; it is eligible and should carry first-draft formal C++.
- Open question found: Is the final original file definitely `MessageShowPane.cpp` rather than compact `MessageDialogs.cpp`?
  - Evidence checked: current by-file/class docs, generated path, singleton/vtable/message overlay grouping, `MessageDialogs` caveat.
  - Best supported resolution: `MessageShowPane.cpp` is best current placement; compact grouping remains a score limiter, not a blocker.
- Questions remaining unresolved: exact original helper/member spellings and final source-file grouping. Current evidence gives behavior, fields, constants, xrefs, and source-facing names enough for first-draft C++ but not final-audit `95+` confidence. Future evidence required would be original source/debug symbols or stronger independent class-layout/helper reports.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Applicable disposition: not applicable for this pass.
- File/placement: none.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated coverage/tracker files are validator-owned; this assignment forbids generated, coverage, supervisor-ledger, and validator-state edits.

## Follow-Up Actions

- Supervisor actions: perform Gate 2 claim-by-claim verification against this report, the listed by-* docs, and scoped validator results. If accepted, supervisor alone may run `execute_report`.
- A-agent actions: none requested by B004.
- B004 future research actions: none required before supervisor execute review. Optional future work outside this report can refine exact helper/member spellings or final source-file grouping.

## Confidence

- Recommendation confidence: high for UID0002Y8 parent non-emitting container, exact child split, owner UID000087, and generated support no-code disposition.
- Score confidence: medium-high for parent `88/91`, constructor `89/91`, row-builder `88/90`, SetWrappedText `88/91`, and generated support no-source scores.
- Remaining uncertainty: exact source-facing helper/member spelling and final `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` grouping.

## Validator Results

- Scoped file validator commands run during this implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md --apply --queue-timeout 240`
    - `command_id: 000000007688`
    - `command_timestamp: 2026-07-06T19:06:37-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md --apply --queue-timeout 240`
    - `command_id: 000000007689`
    - `command_timestamp: 2026-07-06T19:06:43-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md --apply --queue-timeout 240`
    - `command_id: 000000007690`
    - `command_timestamp: 2026-07-06T19:06:53-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md --apply --queue-timeout 240`
    - `command_id: 000000007693`
    - `command_timestamp: 2026-07-06T19:07:06-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md --apply --queue-timeout 240`
    - `command_id: 000000007695`
    - `command_timestamp: 2026-07-06T19:07:22-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md --apply --queue-timeout 240`
    - `command_id: 000000007696`
    - `command_timestamp: 2026-07-06T19:07:32-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md --apply --queue-timeout 240`
    - `command_id: 000000007697`
    - `command_timestamp: 2026-07-06T19:07:42-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md --apply --queue-timeout 240`
    - `command_id: 000000007698`
    - `command_timestamp: 2026-07-06T19:07:53-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class/MessageShowPane.md --apply --queue-timeout 240`
    - `command_id: 000000007699`
    - `command_timestamp: 2026-07-06T19:08:04-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file/MessageShowPane.md --apply --queue-timeout 240`
    - `command_id: 000000007700`
    - `command_timestamp: 2026-07-06T19:08:16-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Side effects reported: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
- Queue/generated refresh check:
  - `python .\tools\validator.py --queue-status`
  - `command_id: 000000007710`
  - `command_timestamp: 2026-07-06T19:11:32-04:00`
  - Exit code: `0`
  - `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.
- Generated freshness observations:
  - `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp` header shows `validator-command-id: 000000007700`, `validator-refreshed-at: 2026-07-06T19:08:16-04:00`, equal to the final by-file validator command timestamp.
  - `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-research-tracker.md` headers show `validator-command-id: 000000007709`, `validator-refreshed-at: 2026-07-06T19:10:21-04:00`, current after deferred generated refresh processing.
- Any unresolved validator warnings/errors: none for the scoped file commands. Each scoped validator exited `0` with `ok: 1`.

## Changed Files

- Created by implementation state: exact child pages already present and validated:
  - `source-3/project-documentation/by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md`
  - `source-3/project-documentation/by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`
  - `source-3/project-documentation/by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md`
- Modified/validated by-* implementation set:
  - `source-3/project-documentation/by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`
  - `source-3/project-documentation/by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md`
  - `source-3/project-documentation/by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md`
  - `source-3/project-documentation/by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`
  - `source-3/project-documentation/by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`
  - `source-3/project-documentation/by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`
  - `source-3/project-documentation/by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`
  - `source-3/project-documentation/by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`
  - `source-3/project-documentation/by-class/MessageShowPane.md`
  - `source-3/project-documentation/by-file/MessageShowPane.md`
- Modified by this report update:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0002Y8-MessageShowPaneMethods-source-quality.md`
- Renamed: none.
- Validator/tool-owned side effects: scoped validators reported projected stats updates and deferred generated refresh; B004 did not manually edit generated files, coverage reports, validator state, supervisor ledgers, queue files, lifecycle headers/footers, or manual coverage reports.
- Leases: B004 leased the ten target/support by-* docs for the validator batch and released all ten immediately afterward; current lease report shows no active B004 leases.
- Report execution: not run. B004 did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry repair commands, manual report/archive moves, supervisor-ledger edits, broad validators, or IDA DB edits.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 validation before implementation callback: supervisor Gate 1 passed for SHA256 `D50A1AFEB354DF6A5C8AE8E9B735A2BDC4A0D4CEA1D59D032A9BFA664835858E`.
- [x] Target/support docs to update or verify after callback:
  - `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`
  - `by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md`
  - `by-memory/0x00522030-0x00522530.MessageShowPaneBuildTextButtons.md`
  - `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`
  - `by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md`
  - `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`
  - `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`
  - `by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md`
  - `by-class/MessageShowPane.md`
  - `by-file/MessageShowPane.md`
- [x] Current target state and actual evidence checked recorded: MCP session `b001-0001I5`, `server_health`, exact function inventory, padding bytes, xrefs, callees, analyze summaries, generated/support docs, and callback validator results are recorded above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C1-C11 are `already-present`; C12 is `excluded-with-reason`.
- [x] Metadata/score changes to apply or verify: UID0002Y8 `88/91`, owner UID000087, `RECONSTRUCTABLE:FALSE`, blank emitters/C++; source child scores/owners/emitters as listed; generated support no-owner/non-reconstructable/blank emitters/C++ were already present and validated.
- [x] Score-limiting blockers researched to resolution or implementation-ready repair: range/split, owner/emitter, source placement, caller/vtable route, generated alias rejection, child C++ readiness, and parent no-code proof are documented.
- [x] Owner/emitter/reconstructable changes to apply or verify: parent non-emitting container; source children owner/emitter UID000087; generated support no-owner/no-emitter all already present and validated.
- [x] Split/rename/new-child changes to apply or verify: constructor child UID0004HN, destructor child UID000492, text-builder child UID0004HO, SetWrappedText UID0001C4, generated support UID0001C5/UID0001C6/UID0001C7, and padding inventory are already present and validated.
- [x] Source-placement/range/split/padding/reclassification changes to apply or confirm not applicable: `MessageShowPane.cpp` best placement and `MessageDialogs.cpp` caveat are preserved; exact padding and child inventory are present.
- [x] First-draft C++ or no-code proof to apply: parent exact no-code proof is present; constructor/destructor/text-builder/SetWrappedText formal child C++ blocks are present; UID0001C5/UID0001C6/UID0001C7 no-source proofs are present.
- [x] Third-party import directive to apply or confirm not applicable: not applicable; no third-party embed.
- [x] Exact target/support doc facts to incorporate at report-level detail: all facts in Recommended Target Doc Changes and Recommended Support Doc Changes were verified already present at same-or-greater detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: stale Wave2/Wave3/generated owner aliases, LivingObjectPane owner rejection, scalar-wrapper source rejection, broad UI callback/table rejection, and source-file grouping caveat are preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: yes, documented above and in target/support docs.
- [x] Open questions to close or document as evidence-backed unresolved: helper/member spelling and final file grouping remain documented as score limiters only.
- [x] Validators to run after callback implementation/reconciliation: ten scoped validators were run for the target/support implementation set; all exited `0` with `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual tracker/coverage text. Validator queue status confirmed no queued or processing generated refresh jobs; generated `MessageShowPane.cpp` header is current to command `000000007700`.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: Gate 1 pass supplied with SHA256 `D50A1AFEB354DF6A5C8AE8E9B735A2BDC4A0D4CEA1D59D032A9BFA664835858E`.
- [x] All accepted target/support doc details incorporated at report-level detail, already present at same-or-greater detail, or excluded with reason: already present in the ten listed by-* docs; C12 excluded as not applicable because manual tracker/coverage text is not required.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C1-C11 `already-present`; C12 `excluded-with-reason`.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: accepted metadata/source/no-code states are already present and validated; no new rename was needed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: stale `FittingRoomDownloadControlPane`, stale `g_pExtendedUIPane`, LivingObjectPane owner rejection, scalar-wrapper source rejection, broad `0x0069b3fc` ownership rejection, and source-file grouping caveat are present.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact helper/member spellings and final `MessageShowPane.cpp` versus `MessageDialogs.cpp` grouping remain documented confidence limits.
- [x] Validators run and results recorded with command id, timestamp, exit code, ok count, warnings, and generated-refresh state: see Validator Results.
- [x] Generated report refresh completed by validator or confirmed deferred/current; no manual generated/coverage edits: queue status command `000000007710` shows no queued/processing generated refresh jobs; generated `MessageShowPane.cpp` header is current to `000000007700`.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007718","destination_path":"executed-b-agent-research/B004/0002Y8-MessageShowPaneMethods-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002Y8-MessageShowPaneMethods-source-quality.md","timestamp":"2026-07-06T19:16:41-04:00","uid":"0002Y8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
