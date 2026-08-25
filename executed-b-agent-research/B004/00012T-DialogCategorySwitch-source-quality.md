** TARGET-REPORT-UID:00012T **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# 00012T DialogCategorySwitch Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: retain stable documentation UID/path [UID:00012T] but correct the source role from a category switch to `void DialogPane::RemoveControl(int controlIndex)`.
- Final disposition: source-authored, out-of-line `DialogPane` method at exact modeled range `0x0049dd00-0x0049dd17`, emitted through [UID:00003T] and [UID:0000IT].
- Implemented callback disposition: the B005 overlap prerequisite was completed by validator command `000000008656`, after which B004 rebased and applied the accepted callback. The target is now `90/92`, all eight exact managed blocks are represented in their destination docs, support scores remain unchanged, and finalized B005 content remains intact.
- Confidence: high for range, behavior, return contract, owner, generic `List` type, and index semantics; medium-high for the exact original overload spelling because no original function symbol survives.

## Supporting Research

- Research was performed against supervisor-provided NexusTK IDB database `bf5519ae`. MCP request `72007` returned health `ok`, imagebase `0x400000`, and ready auto-analysis, Hex-Rays, and string cache. The session was healthy when this evidence was collected; this report does not assert indefinite future session availability.
- A fresh streamable MCP transport was initialized as `f8e3024e-eff7-44be-ab51-9533282b87db`. Earlier request IDs `71009-71032` and later confirmation requests `72007-72024` are evidence-time call identifiers, not lifecycle state.
- The by-* docs, generated output, tracker rows, accepted `List` API docs, and matching executed B001/B002/B003/B011 reports as they existed during this evidence pass were read as support. The old reports were treated as historical leads and were rechecked against the binary; their category/manager claims are superseded where contradicted.
- B005 UID00011F is now durable completed support state: supervisor-verified and validator-executed by command `000000008656`. B004 re-read finalized `by-class/DialogPane.md` at `89/91` and finalized [UID:0003KJ] at `90/92`. The class block preserves public `OnControlCommand(int,int)`, public `FindControlIndex(const ControlPane *) const`, every unrelated declaration/field, owner/emitter metadata, and `[[CHILDREN]]`; the UID0003KJ block preserves its public const-pointer signature, null spelling, loop, return behavior, score/metadata, and accepted pointer-lookup role.
- All eight complete destination blocks were applied and rechecked against their destination docs. The target now carries the exact body; DialogPane changes only generic List type plus overloaded removal expressions on top of finalized B005 bytes; List adds only inline `GetCount`; UID0003KK uses List type/access; UID0003KJ changes only generic `GetElementAt` slot access; FittingRoom uses corrected lookup/removal; WebBoard preserves every unrelated line and adds only removals `1` then `0`; HeadSelect changes only the documented List/index expressions.
- B004 edited only the fourteen accepted by-* documents and this report. The scoped validators and final waited autogen command produced generated/validator-owned outputs; B004 did not manually edit generated, coverage, tracker, registry, or supervisor files and performed no report execution, lifecycle, move, or archive command.

## Target

- Target UID: `00012T`.
- Target path: `by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md`.
- Historical B004 research/implementation-callback artifact path before supervisor lifecycle: `tools/leaser/Agents/Agent-B004/research/00012T-DialogCategorySwitch-source-quality.md`.
- Historical pre-callback queue snapshot: `auto-generated/-ag-research-tracker.md` listed the target under `by-memory` / `Not-Covered Files - Reconstructable` at `86/90` with zero indexed reports. Tracker/count state is validator-owned and is not frozen as current truth by this artifact.
- Current supervisor classification: reconstructable exact by-memory child under [UID:00003T] `DialogPane` and [UID:0000IT] `DialogPane` source file.

## Current Target State

- Current metadata is `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00003T`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003T`, blank position, and `Nested:0`.
- Current formal C++ is the exact accepted `void DialogPane::RemoveControl(int controlIndex)` definition. Waited generated refresh `000000008712` emitted exactly one UID00012T body in `auto-generated/NexusTK/ui/core/DialogPane.cpp` and no target Empty Emitter Marker.
- The pre-callback category-id, refresh-flag, custom-manager, and category/state-dispatch claims are retained as rejected historical evidence; current target and support prose use generic `List`, index/count, and removal semantics.
- Implementation, scoped validation, lease release, and generated verification are complete. B004 performed no report execution, lifecycle, move, or archive command; report validation, execution, count, current path, move, and archive state are external supervisor/validator-owned facts.
- No implementation item or B005 prerequisite remains. Finalized shared docs were re-read after command `000000008656`, and their unrelated/public content remained present after the B004 callback and refresh.

## Executive Recommendation

- Keep direct owner/emitter [UID:00003T] `DialogPane`, source file [UID:0000IT] `NexusTK/ui/core/DialogPane.cpp`, reconstructable true, blank position, and zero children.
- Keep the stable physical filename and UID as a historical search alias; do not perform a lifecycle-sensitive file rename. Correct the page title, summary, body, and emitted source role to `DialogPane::RemoveControl(int controlIndex)`.
- Resolve the former custom-manager blocker: `DialogPane +0x1fc` points to an exact generic `List` allocated as 20 bytes and constructed as `List(4, 20)`. Its elements are 4-byte `ControlPane *` values.
- Resolve the former category blocker: target argument values `0`, `1`, and `7` are control-list indices. The literal `1` passed to vtable slot `+0x1c` is the `count` argument to accepted `List::RemoveAt(int index, int count)`.
- Resolve the return blocker: source return is `void`; the target merely leaves the callee's incidental EAX value live, accepted `List::RemoveAt` is void, and every direct caller ignores EAX.
- Do not split, merge, reclassify, make inline, or classify as thunk/compiler glue. The one-block wrapper has a distinct modeled address, four ordinary direct call sites, normal `__thiscall` stack cleanup, and independent alignment fences.

## Supervisor Active Recheck

- The supervisor instruction that triggered this report assigned UID00012T for independent report-only source-quality research using IDB `bf5519ae`.
- The item did not require a range split: MCP models one exact `0x17`-byte function and raw bytes prove the surrounding alignment.
- The source-bearing target is fully resolved, and the directly triggered support corrections and complete managed blocks have been applied and validated.

## Inference Research Guidance Check

- Binary facts control the recommendation: modeled boundary, exact bytes, four code xrefs, caller stack values, `List::vftable`, `List(4,20)` construction, accepted vtable-slot API, and destructor behavior.
- Documentation facts are secondary: existing owner/emitter routing is retained because it agrees with receiver fields and cross-feature callers; existing category and custom-manager wording is rejected because it conflicts with stronger binary/List evidence.
- Source names are explicit inference. `RemoveControl(int controlIndex)` is preferred because the preceding sibling removes the matching `ControlPane *`, both invoke identical `RemoveAt(...,1)`, and C++ overloads naturally express the two wrappers.
- Wave3 links were encountered in DialogPane support. They were ignored as stale workflow/source authority; no Wave2/Wave3 artifact influenced the conclusion.

## Heuristic / Inference Reanalysis And Validation

- Generated-name issue: `DialogCategorySwitch`, `SwitchControlCategory`, and HeadSelect-private alternatives are rejected. Four callers span FittingRoom, WebBoardDialogOld, and HeadSelect, and none performs category-state logic.
- Argument issue: values `0`, `1`, and `7` are valid list positions. FittingRoom dereferences list element index `7`; WebBoard removes indices `1` then `0`; HeadSelect repeatedly removes index `7` until count equals `7`.
- Literal issue: the pushed `1` is `List::RemoveAt` count. The accepted List vtable maps `+0x10` to `GetElementAt`, `+0x18` to `Append`, and `+0x1c` to `RemoveAt`.
- Type issue: `sub_49DC10` allocates `0x14` bytes, invokes `sub_4F3060(this,4,20)`, and stores the result at `DialogPane +0x1fc`; IDA identifies the constructor's vtable as `List::vftable`. A source-distinct `DialogControlManager` is rejected.
- Element issue: `sub_49DC10` passes `1` and the address of its pointer argument to `List::Append`, proving 4-byte pointer elements. FittingRoom calls `GetElementAt(7)`, dereferences the returned slot, then destroys the saved `ControlPane *` after target removal.
- Return issue: IDA's `int` prototype is a tail-value artifact. Source uses `void` because `List::RemoveAt` is accepted void and no caller consumes EAX.
- Nullability issue: target has no null guard. It assumes the list exists. That assumption is valid in all observed callers and must be preserved rather than adding defensive behavior.
- Neighbor issue: `0x0049dca0` compares each stored `ControlPane *` against its pointer argument, then calls `RemoveAt(index,1)`; it is a pointer-based remove wrapper, not `SelectControlById`. Its ten direct calls in MiniMapDialog teardown pass saved control pointers, remove them from the DialogPane list, then destroy and clear the same pointers. `0x0049dd20` performs the same pointer comparison and returns the index; it is not ID-based.
- Add issue: `0x0049dc10` takes one `ControlPane *`, lazily creates `List(4,20)`, then calls `Append(1,&control)`. The category-bearing AddControl overload and custom manager are unsupported for this exact child.
- Count issue: `0x0049dd70` directly reads List count `+0x0c`, corresponding to the accepted source-inline `List::GetCount()` accessor. Its old `DialogControlManager::m_count` type claim is superseded.
- Caller-support issue: the FittingRoom formal body incorrectly treats index `7` as an ID lookup and target as returning the removed pointer; WebBoard omits the two removals; HeadSelect treats count `+0x0c` as a current category. Complete corrected blocks are supplied below.
- Liveness issue: four ordinary code xrefs and live caller behavior prove retained source use. No data xref or function-pointer route appeared in the evidence-time `xrefs_to`; none is required to establish liveness.
- Source-shape issue: the target is an out-of-line member wrapper, not inline-only, thunk, compiler artifact, scalar-deleting wrapper, or aggregate. Distinct code, ordinary prologue/epilogue, four calls, and alignment support this classification.
- Rename issue: emitted method name should change, but the physical page path should remain stable to avoid unnecessary UID/reference churn. The historical title remains only a search alias.
- Remaining uncertainty: no original PDB/source symbol proves whether the integer overload was spelled `RemoveControl`, `RemoveControlAt`, or `RemoveControlByIndex`. The overloaded neighbor and period-appropriate API symmetry make `RemoveControl(int controlIndex)` the best-supported choice; this caps confidence at `92` rather than blocking formal C++.

## Evidence Standards Used

- Highest-weight evidence: evidence-time IDA MCP function model, raw bytes, decompilation, disassembly, xrefs, caller control flow, constructor/destructor behavior, and direct `List` vtable/API documentation grounded in IDA.
- Corroborating evidence: by-* owner/file/layout docs and generated output as read during the pass, tracker rows, and matching executed B reports.
- Negative evidence: no category-state read/write, no enum comparison, no custom-manager constructor/vtable, no target data xrefs, no return use, no null guard, and no compiler-wrapper pattern.
- The evidence ladder is sufficient for source-ready behavior and ownership. Only the exact original overload spelling remains inferred.

## Evidence Checked

- MCP session/schema/health: prior refreshed `idb_list` request `71009`, health `71010`, and evidence-time health confirmation `72007` on database `bf5519ae`.
- Target: lookup/analyze/decompile/disasm/xrefs/bytes requests `71011-71017` and later evidence-time confirmations `72015-72018`.
- Callers: FittingRoom `71018-71019`, `71027`, `72012-72013`; WebBoard `71020-71021`, `71028`, `72020-72021`; HeadSelect `71022-71023`, `71029`, `72014`.
- Type/API: sibling `0x0049dca0` request `71024` and `72010`, its ten xrefs and MiniMap pointer callers `72022-72024`; destructor `71025` and `72019`; generic List constructor `71026`; add wrapper `72008-72009`; find-index sibling `72011`; vtable/global/type checks `71030-71032`; accepted [UID:000079] List docs and exact List child pages.
- Docs: target, DialogPane class/file/layout/aggregate and exact siblings, List class/file/core, all three direct caller pages, evidence-time generated DialogPane/FittingRoom/HeadSelect outputs, generated memory coverage, and research tracker.
- Historical report search terms: `UID:00012T`, `0x0049dd00`, `DialogCategorySwitch`, `SwitchControlCategory`, `m_controlManager`, `RemoveControl`, and `List::RemoveAt`. Relevant executed reports were B002 UID00012S, B001 UID0001FI, B011 UID00003T, and B003 FittingRoom core; their stale category assumptions were not copied forward.
- Failed/unavailable checks: the first PowerShell MCP initialization attempt timed out and requests `72002-72006` omitted `database` because `$args` was consumed as a PowerShell automatic variable. Corrected requests succeeded. These are client payload errors, not IDB failures. No original symbols are available.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact target range is `0x0049dd00-0x0049dd17`, size `0x17`, one block, complexity 1. | High | `72015`, `72018` | UID00012T range/status | Incorporated | Applied; target validator `000000008663` |
| C02 | Eight `CC` bytes precede target and nine `CC` bytes follow before `0x49dd20`. | High | `72017`; lookup boundaries | UID00012T boundary evidence | Incorporated | Applied; `000000008663` |
| C03 | Exactly four code xrefs exist at `0x41ce03`, `0x46e2dc`, `0x46e2e5`, `0x551394`; no data xref is returned. | High | `72016` | UID00012T caller inventory | Incorporated | Applied; `000000008663` |
| C04 | Receiver is `DialogPane`; field `+0x1fc` is the shared control list. | High | target body; constructor/destructor; callers | target/class/layout/file | Incorporated | Applied; `000000008663`, `000000008665`, `000000008667`, `000000008669` |
| C05 | Physical type at `+0x1fc` is generic `List *`, allocated `0x14` and constructed as `List(4,20)`. | High | `71026`, `72008-72009`, List vtable | target/class/layout/siblings | Incorporated | Applied; `000000008663`, `000000008665`, `000000008669`, `000000008682`, `000000008693`, `000000008697` |
| C06 | List elements are 4-byte `ControlPane *` values appended with `Append(1,&control)`. | High | `72008-72009`, Fitting `72012-72013` | class/add/caller docs | Incorporated | Applied; `000000008665`, `000000008682`, `000000008704` |
| C07 | Vtable `+0x1c` is accepted `List::RemoveAt(int index,int count)`; literal `1` is count. | High | List docs/vtable; target; siblings | target and supports | Incorporated | Applied; `000000008663`, `000000008691`, `000000008700`, `000000008702` |
| C08 | Target argument is a list index, not category id/control id/enum. | High | all four callers | target behavior/naming | Incorporated | Applied; `000000008663`, `8704`, `8708`, `8710` |
| C09 | Source return is `void`; EAX is incidental and ignored. | High | accepted List API; four callers | target signature/C++ | Incorporated | Applied; `000000008663` |
| C10 | Best source name is overloaded `DialogPane::RemoveControl(int controlIndex)`. | Medium-high | pointer overload sibling and API symmetry | target/class | Incorporated | Applied; `000000008663`, `000000008665`; emitted by `000000008712` |
| C11 | `0x49dca0` is protected `RemoveControl(ControlPane *control)`, not SelectControlById; all ten MiniMap teardown calls pass pointers and destroy the same objects after removal. | High | `72010`, `72022-72024` | UID0003KI/class/aggregate | Corrected without score inflation | Applied; `000000008691`, `000000008665`, `000000008676` |
| C12 | `0x49dd20` is finalized public `FindControlIndex(const ControlPane *control) const`, not ID-based; preserve B005's `90/92`, exact signature, `== 0` null spelling, loop/returns, and pointer-lookup role while replacing only placeholder `GetControl(index)` with exact generic List element-slot access. | High | `72011`; finalized UID0003KJ after command `000000008656` | UID0003KJ/class/aggregate | Rebased generic List expression only; finalized content preserved | Applied; `000000008693`, `000000008665`, `000000008676`; generated confirmation `000000008712` |
| C13 | `0x49dc10` is one-argument `AddControl(ControlPane *)` over List Append. | High | `72008-72009` | UID0003KH/class/aggregate | Corrected without score inflation | Applied; `000000008682`, `000000008665`, `000000008676` |
| C14 | `0x49dd70` is direct List count access expressible by inline `GetCount()`. | High | target sibling bytes; accepted List docs | UID0003KK/List class | Exact formal blocks applied | Applied; `000000008697`, `000000008700`, `000000008702`; generated confirmation `000000008712` |
| C15 | FittingRoom index 7 removal saves the pointer, removes list entry, then destroys saved control. | High | `72012-72013` | UID0002CV | Complete formal block applied | Applied; `000000008704`; generated confirmation `000000008712` |
| C16 | WebBoard removes indices 1 then 0 before destroying and rebuilding two controls. | High | `72020-72021` | UID0000ZA | Complete formal block applied | Applied; `000000008708`; generated confirmation `000000008712` |
| C17 | HeadSelect removes index 7 until List count is 7; no category state exists. | High | `72014` | UID0001FI | Complete formal block applied | Applied; `000000008710`; generated confirmation `000000008712` |
| C18 | Owner/emitter remain UID00003T, source route UID0000IT, reconstructable true, blank position, Nested 0. | High | receiver/field family and existing routing | target metadata | Preserved | Confirmed by `000000008663` and generated UID route `000000008712` |
| C19 | Stable target filename/UID remain; emitted method/title prose changes, with old label historical only. | High | stable-doc precedent and no range change | target/support refs | Incorporated | Applied; `000000008663` |
| C20 | Target score moved `86/90 -> 90/92`. | Medium-high | all former blockers resolved; symbol spelling cap | target metadata | Applied | Confirmed by `000000008663` and generated header/body `000000008712` |
| C21 | DialogPane class/file/layout/aggregate replace custom-manager/category rationales with generic List facts. | High | C04-C14 | support docs | Incorporated; support scores unchanged | Applied; `000000008665`, `000000008667`, `000000008669`, `000000008676` |
| C22 | List class exposes exact inline `GetCount() const` in its complete managed declaration; List score stays unchanged. | High | direct `+0x0c` reads and accepted List docs | by-class/List and by-file/List | Incorporated; score unchanged | Applied; `000000008700`, `000000008702`; generated confirmation `000000008712` |
| C23 | No import directive applies; this is project-authored code. | High | source placement and binary family | target C++ policy | Preserved | Confirmed by target `000000008663`; no import block introduced |
| C24 | Reject HeadSelect/FittingRoom/WebBoard/custom-manager/List ownership, no-owner, no-code, inline-only, thunk, and compiler-artifact alternatives. | High | complete positive/negative evidence | target rejection sections | Incorporated | Applied; `000000008663`, `000000008704`, `000000008708`, `000000008710` |

## Positive Evidence Summary

- The target directly loads `DialogPane +0x1fc` and invokes slot `+0x1c(index,1)`.
- Generic List construction, exact List vtable identity, accepted List API, and adjacent add/remove/find/count helpers all agree on one fixed-width pointer container.
- Every caller's surrounding behavior is removal: save/destroy an old pointer, remove two old layout entries before rebuilding, or truncate entries from index 7 onward.
- Four cross-feature callers prove shared DialogPane ownership and live out-of-line source use.
- The overloaded pointer-removal sibling provides a strong source-name comparator for the integer-index wrapper.

## IDA MCP Facts

- Function/range: `sub_49DD00`, `0x17` bytes, one basic block, normal `retn 4`, successor `sub_49DD20` at `0x49dd20`.
- Bytes: `55 8B EC 8B 89 FC 01 00 00 6A 01 FF 75 08 8B 01 FF 50 1C 5D C2 04 00`.
- Padding: `0x49dcf8-0x49dcff` eight `CC`; `0x49dd17-0x49dd1f` nine `CC`.
- Xrefs: four code refs, no returned data refs.
- Type/global: `sub_4F3060` installs `List::vftable`; `??_7List@@6B@` is at `0x61ce2c`; object size is 20 bytes with fields at `+4/+8/+0xc/+0x10`.
- Negative IDA facts: no category global/state read or write, no named direct callee due virtual dispatch, no null guard, no return-value normalization, no compiler wrapper pattern.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x49dc10-0x49dc93` | UID0003KH | `AddControl(ControlPane *)`, lazy `List(4,20)` plus `Append(1,&control)` | true | UID00003T | `87/90` | Prose/name correction, score unchanged |
| `0x49dca0-0x49dcf8` | UID0003KI | `RemoveControl(ControlPane *)` pointer-match wrapper | true | UID00003T | `86/89` | Prose/name correction, score unchanged |
| `0x49dcf8-0x49dd00` | padding | eight `CC` bytes | false | none | n/a | Remain padding |
| `0x49dd00-0x49dd17` | UID00012T | `RemoveControl(int controlIndex)` | true | UID00003T | `86/90 -> 90/92` | Source-ready target |
| `0x49dd17-0x49dd20` | padding | nine `CC` bytes | false | none | n/a | Remain padding |
| `0x49dd20-0x49dd6b` | UID0003KJ | finalized public `FindControlIndex(const ControlPane *) const` | true | UID00003T | `90/92` | Re-read/rebased after command `000000008656`; only generic List slot access changed and validated by `000000008693` |
| `0x49dd70-0x49dd7f` | UID0003KK | `GetControlCount() const` over List count | true | UID00003T | `90/91` | Type/formal support correction, score unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x41ce03` | FittingRoom `sub_41CDC0` | Gets pointer from element slot 7, removes index 7, destroys saved pointer, then appends replacement controls. |
| `0x46e2dc` | WebBoardDialogOld `sub_46E2A0` | Removes list index 1 before destroying/rebuilding old close/browser controls. |
| `0x46e2e5` | same caller | Removes list index 0 after index 1, preserving stable removal order. |
| `0x551394` | HeadSelect `sub_551350` | Repeatedly removes index 7 until count `+0x0c` equals 7, then rebuilds head buttons. |
| target slot `+0x1c` | `List::RemoveAt` | Receives index and count 1; no category dispatch. |

## Documentation Evidence And IDA Status

- Correct existing facts: exact range, four callers, shared DialogPane owner, file route, reconstructable state, blank position, zero children, and alignment.
- Stale facts: category values, refresh flag, custom `DialogControlManager` type, current-category field, ID-based sibling names, and target return shape.
- Generated state before callback: UID00012T emits through UID00003T but is uncoded and has an Empty Emitter Marker; generated FittingRoom and HeadSelect contain the same stale category/manager assumptions.
- Historical B001/B002/B003/B011 reports are useful for ranges and owner routing but their manager/category interpretation is superseded by current generic List proof.

## Ranked Ownership Analysis

### 1. [UID:00003T] DialogPane through [UID:0000IT] DialogPane

- Evidence for: receiver field at inherited `+0x1fc`, placement among DialogPane helpers, DialogPane destructor use, and callers from three derived/consumer dialog families.
- Evidence against: no original method symbol; exact overload spelling is inferred.
- Decision: accepted direct semantic owner and emitter.

### 2. [UID:000079] List

- Evidence for: target delegates its entire operation to `List::RemoveAt` and the field object is exact List.
- Evidence against: `ecx` at function entry is DialogPane, not List; List already owns the delegated method at `0x4f33e0`; target is a DialogPane convenience wrapper.
- Decision: dependency/type owner only, rejected as target owner.

### 3. HeadSelectDialog, FittingRoomDialog, or WebBoardDialogOld

- Evidence for: each family calls the target.
- Evidence against: none owns all callers; target accesses only inherited DialogPane state and sits in the DialogPane helper band.
- Decision: callers/consumers only.

### Proposed new file/grouping, if applicable

- Not applicable. Existing class/file placement is correct. No new source file, child, split, or grouping is recommended.

## Source Placement

- Recommended placement: `DialogPane` declaration in its existing class/header route and method definition in `NexusTK/ui/core/DialogPane.cpp` through UID0000IT.
- This fits the adjacent DialogPane constructor/destructor/control-helper band and cross-feature reuse.
- Rejected placements: HeadSelect/FittingRoom/WebBoard source files, generic List.cpp, a new DialogControlManager file, no-owner, and aggregate-only emission.
- Remaining uncertainty: header filename and exact original overload spelling are not symbol-proven, but file UID/path and class owner are strong.

## Range / Split / Padding / Reclassification Analysis

- Exact modeled range remains `0x0049dd00-0x0049dd17` end-exclusive.
- No split or merge: all 23 bytes form one coherent member wrapper.
- Pre/post gaps are alignment, not hidden children or data.
- The stable page filename may remain historical; no physical rename is recommended.
- Target remains reconstructable project code and does not become ignored/non-emitting.

## Negative Evidence Summary

- No category state, category enum, selected category, refresh flag, or state transition exists in target or callers.
- No custom manager constructor or custom manager vtable exists at `+0x1fc`; exact construction is generic List.
- No caller uses EAX from target.
- No null guard exists in target; adding one would alter behavior.
- No direct target data xref/function-pointer route was returned; four code calls are sufficient liveness evidence.
- FittingRoom ID `7` terminology is contextual to button command assignment, but the target operation itself receives list index 7.
- Adjacent addresses do not imply List ownership: they are DialogPane wrappers around a List field.
- Historical reports and generated C++ are rejected where they call count a current category or `RemoveAt` a category switch.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name: `DialogPane::RemoveControl(int controlIndex)`; stable IDA `sub_49DD00` was not renamed by this documentation callback.
- Source-facing sibling names: `AddControl(ControlPane *)`, `RemoveControl(ControlPane *)`, public `FindControlIndex(const ControlPane *) const`, and `GetControlCount() const`.
- Type: `DialogPane +0x1fc` is `List *`. Retain `m_controlManager` as the established field spelling in the immediate managed blocks, but explicitly redefine it as a generic List role alias rather than a distinct class. A future coordinated whole-tree naming pass may prefer `m_controls`; that spelling is not required to resolve UID00012T.
- List element type is semantically `ControlPane *`, stored in generic 4-byte slots; use casts at direct `GetElementAt` sites because generic List returns element storage.
- IDA DB edits were not requested and were not performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. This is source-authored project code with complete behavior and dependencies.
- Exact target managed insertion:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void DialogPane::RemoveControl(int controlIndex)
{
    m_controlManager->RemoveAt(controlIndex, 1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- The body preserves exact behavior: no null check, one virtual `RemoveAt` call, original index, literal count 1, and void source contract.
- The shape matches a small mid-2000s out-of-line convenience overload over a generic container and naturally pairs with the pointer-removal sibling.
- Inferred names replace IDA labels without inventing behavior: `controlIndex`, `RemoveControl`, established field spelling `m_controlManager`, and accepted `List::RemoveAt`.
- No third-party import directive applies.

### Complete DialogPane class support managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual bool OnInputEvent(InputEvent *event);
    virtual bool OnKeyInput(InputEvent *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    int FindControlIndex(const ControlPane *control) const;

protected:
    void CloseDialog();
    void StoreClampRect(const RectBounds *bounds);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, const wchar_t *paletteName);
    void AddControl(unsigned char category, ControlPane *control);
    void AddControl(ControlPane *control);
    void RemoveControl(ControlPane *control);
    void RemoveControl(int controlIndex);
    int GetControlCount() const;
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    void SetHoverControl(int controlId);
    void SetSelectionVisualState(int controlId, unsigned char state);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RedrawSelectedControl();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    List *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginX;
    int m_dragOriginY;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinY;
    int m_dragClampMinX;
    int m_dragClampMaxY;
    int m_dragClampMaxX;
    EPFTileContext m_tileContext;
    DialogBackgroundState m_backgroundState;

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Complete List class support managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef int (__cdecl *ListCompareFunction)(const void *left, const void *right);

class List : public LObject {
public:
    List(int elementSize, int pageSize);
    virtual ~List();

    virtual void *GetData();
    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void RemoveAll();
    virtual void SwapElements(int firstIndex, int secondIndex);

    void AssignFrom(List *source);
    void SetCount(int count);
    int GetCount() const { return m_count; }
    void Sort(ListCompareFunction compare);

protected:
    int m_elementSize;
    int m_pageSize;
    int m_count;
    void *m_data;

private:
    void ReserveElementCapacity(int elementCount);
    void ReservePageCapacity(int pageCount);
    int PageCountForElementCount(int elementCount);
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Complete GetControlCount support managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int DialogPane::GetControlCount() const
{
    List *controlManager = m_controlManager;
    if (controlManager == NULL)
        return 0;

    return controlManager->GetCount();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Complete FindControlIndex support managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int DialogPane::FindControlIndex(const ControlPane *control) const
{
    if (m_controlManager == 0)
        return -1;

    const int controlCount = m_controlManager->GetCount();
    for (int index = 0; index < controlCount; ++index) {
        ControlPane *entry = *static_cast<ControlPane **>(
            m_controlManager->GetElementAt(index));
        if (entry == control)
            return index;
    }

    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Complete FittingRoom caller support managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomDialog::RebuildCategoryButtons()
{
    static const FittingRoomCategoryButtonDef kButtons[] = {
        { kFittingRoomCommandUsableItems, L"UsableItems" },
        { kFittingRoomCommandWeapons, L"Weapons" },
        { kFittingRoomCommandMounts, L"Mounts" },
        { kFittingRoomCommandFace, L"Face" },
        { kFittingRoomCommandHead, L"Head" },
        { kFittingRoomCommandMantle, L"Mantle" },
        { kFittingRoomCommandNecklaces, L"Necklaces" },
        { kFittingRoomCommandCoats, L"Coats" },
        { kFittingRoomCommandShoes, L"Shoes" },
        { kFittingRoomCommandSpecialtySets, L"SpecialtySets" },
    };

    ControlPane* oldFirstButton = *static_cast<ControlPane **>(
        m_controlManager->GetElementAt(kFittingRoomCommandUsableItems));
    if (oldFirstButton != NULL) {
        RemoveControl(kFittingRoomCommandUsableItems);
        oldFirstButton->Release(true);
    }

    for (unsigned int i = 0; i < sizeof(kButtons) / sizeof(kButtons[0]); ++i) {
        RectBounds bounds;
        GetFittingRoomControlBounds(kButtons[i].commandId, &bounds);

        FittingRoomTextButtonControlPane* button =
            new FittingRoomTextButtonControlPane(kButtons[i].label, &bounds);
        AddControl(button);

        if (i == 0 && m_itemState.GetItemCount(0) <= 0) {
            button->SetSelected(true);
            m_selectedCategoryCommandId = kFittingRoomCommandUsableItems;
        }
    }

    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Complete WebBoard caller support managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void WebBoardDialogOld::RefreshOldLayout(int mode)
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

### Complete HeadSelect caller support managed block

The complete destination-specific managed block is provided in Appendix A. It preserves every existing method and changes only the directly contradicted List/index expressions: `kHeadButtonCategory` becomes `kFirstHeadButtonControlIndex`, `forceCategorySwitch` becomes `removeExistingButtons`, preview slot access uses `List::GetElementAt`, and the truncation loop uses `GetControlCount()` plus `RemoveControl(7)`.

## Final Recommendation

- B005 overlap prerequisite completed: UID00011F was supervisor-verified and validator-executed by command `000000008656`; B004 re-read and rebased finalized `by-class/DialogPane.md` and UID0003KJ in this artifact before Gate 1 recheck.
- C01-C20 were applied exactly after supervisor acceptance.
- Support C11-C17 and C21-C22 were synchronized without changing support scores or unrelated formal content.
- Keep [UID:00012S] a non-emitting aggregate; keep List as dependency rather than target owner.
- Keep stable target path/UID and record `DialogCategorySwitch` only as historical/superseded terminology.
- Outside this assignment, other generated dialog methods that use invented `FindControlById` manager APIs may receive coordinated List-access cleanup. They do not block this exact target.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md`.
- Set to `90/92`; owner/emitter UID00003T, reconstructable true, blank position, and Nested 0 are preserved.
- Summary/status/behavior/caller/ownership/rationale/change text now records the exact range, List type/API, index/count, void return, four callers, and rejected category/custom-manager alternatives from this report.
- The exact target managed block above is present.
- Keep historical filename as a search alias; no physical rename.

## Recommended Support Doc Changes

- `by-class/DialogPane.md`: rebased against finalized B005 command `000000008656`; the complete class block preserves public `OnControlCommand`, public const-pointer `FindControlIndex`, finalized `89/91`, metadata, unrelated declarations/fields, and `[[CHILDREN]]`, while changing only stale select/category declarations to overloaded removal declarations and `DialogControlManager *` to `List *`.
- `by-file/DialogPane.md`: records UID00012T emission and generic List control-container facts with score/path/owner state unchanged.
- `by-type/by-struct/DialogPaneLayout.md`: records `+0x1fc` as `List *`, preserves established `m_controlManager` role alias and offsets, and keeps its score and blank formal block.
- `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`: corrects rows/source-name direction for UID0003KH/KI/12T/KJ/KK while keeping aggregate `90/91`, non-emitting, ownerless, and blank C++.
- `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md`: documents `List(4,20)` and `Append(1,&control)` with score and blank formal block unchanged.
- `by-memory/0x0049dca0-0x0049dcf8.DialogPaneSelectControlById.md`: historicalizes the title and documents pointer-match `RemoveControl(ControlPane *)` with score and blank formal block unchanged.
- `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md`: preserves finalized B005 title history, public const-pointer role, `90/92`, metadata, `== 0`, loop, and returns; only placeholder `GetControl(index)` changed to exact generic List element-slot access.
- `by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md`: carries the complete List-typed block and historical custom-manager evidence at unchanged `90/91`.
- `by-class/List.md`: carries the complete class block with inline `GetCount() const` at unchanged `92/91`.
- `by-file/List.md`: documents the accepted inline count accessor/direct-field lowering with no score/path change.
- `by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md`: carries the complete block while preserving all labels/IDs/default-selection facts at `87/91`.
- `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md`: carries the complete block with removals `1` then `0` and all unrelated layout facts preserved at `88/90`.
- `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`: carries Appendix A with category prose replaced by list-truncation facts at `87/89`.
- No generated, coverage, tracker, registry, supervisor, or lifecycle file was manually edited. Scoped validators and waited autogen owned generated refresh effects.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, UID00003T owner/emitter, reconstructable true, blank position/C++, Nested 0.
- Current implemented target: `90/92` with all non-score metadata preserved and formal C++ populated.
- Completion rises because exact type, operation, argument semantics, return contract, source name, caller behavior, and C++ blocker are resolved.
- Confidence rises because generic List construction/vtable/API and all four callers independently agree. It remains below `95` because original source symbols and exact overload spelling are unavailable.
- Score-improvement attempts: custom type resolved through constructor/vtable; flag resolved through List API; category resolved through callers; return resolved through caller use and List signature; liveness resolved through xrefs; range/padding resolved through bytes; owner/source route resolved through receiver and caller distribution. No active target blocker remains.
- Support scores remain unchanged to avoid unrelated inflation.

## Open Questions With Attempted Resolution

- Exact original method spelling: checked target/sibling bodies, all callers, current docs, generated output, and matching reports. `RemoveControl(int)` is best supported by overload symmetry; no symbol route survives. This is a confidence cap only.
- Exact field spelling: checked existing DialogPane conventions and binary type. The physical type is conclusively List; `m_controlManager` remains an established role alias in this immediate proposal to avoid an assignment-wide rename. A future coordinated rename to `m_controls` is optional and does not affect behavior.
- Original source used inline `GetCount()` versus direct friend/protected access: accepted List docs already identify a source accessor/direct-field lowering. Adding the inline accessor is the safe class-level expression and regenerates the direct load.
- No unresolved question blocks target C++, owner/emitter, range, placement, or score movement.

## Follow-Up Actions

- Supervisor/validator-owned report validation, execution, count, current path, move, and archive state are external and are neither asserted nor directed by this artifact.
- B005 dependency is complete: command `000000008656` finalized the overlapping support, and B004 re-read, rebased, applied, and validated both shared docs while preserving those finalized bytes.
- No implementation, A-agent, or additional B-agent research item remains for UID00012T. Report validation, execution, count, current path, move, and archive state remain external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high for `90/92`.
- Remaining uncertainty: original overload and field spellings only; behavior/type/ownership are resolved.

## Validator Results

- Each accepted by-* document was leased only immediately before its edit, validated in a scoped file command, and released immediately after validation. Every scoped command exited `0` with validator `ok: 1` and `generated_refresh: skipped`.

| Command ID | Timestamp | Scoped document | Exit | Result |
| --- | --- | --- | --- | --- |
| `000000008663` | `2026-07-12T20:01:33-04:00` | `by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md` | 0 | `ok:1`; generated skipped |
| `000000008665` | `2026-07-12T20:02:30-04:00` | `by-class/DialogPane.md` | 0 | `ok:1`; generated skipped |
| `000000008667` | `2026-07-12T20:03:21-04:00` | `by-file/DialogPane.md` | 0 | `ok:1`; generated skipped |
| `000000008669` | `2026-07-12T20:04:04-04:00` | `by-type/by-struct/DialogPaneLayout.md` | 0 | `ok:1`; generated skipped |
| `000000008676` | `2026-07-12T20:05:14-04:00` | `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md` | 0 | `ok:1`; generated skipped |
| `000000008682` | `2026-07-12T20:05:46-04:00` | `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md` | 0 | `ok:1`; generated skipped |
| `000000008691` | `2026-07-12T20:06:21-04:00` | `by-memory/0x0049dca0-0x0049dcf8.DialogPaneSelectControlById.md` | 0 | `ok:1`; generated skipped |
| `000000008693` | `2026-07-12T20:07:02-04:00` | `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md` | 0 | `ok:1`; generated skipped |
| `000000008697` | `2026-07-12T20:07:56-04:00` | `by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md` | 0 | `ok:1`; generated skipped |
| `000000008700` | `2026-07-12T20:08:28-04:00` | `by-class/List.md` | 0 | `ok:1`; generated skipped |
| `000000008702` | `2026-07-12T20:08:58-04:00` | `by-file/List.md` | 0 | `ok:1`; generated skipped |
| `000000008704` | `2026-07-12T20:09:55-04:00` | `by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md` | 0 | `ok:1`; generated skipped |
| `000000008708` | `2026-07-12T20:10:27-04:00` | `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md` | 0 | `ok:1`; generated skipped |
| `000000008710` | `2026-07-12T20:11:20-04:00` | `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md` | 0 | `ok:1`; generated skipped |
| `000000008712` | `2026-07-12T20:11:44-04:00` | waited project autogen refresh | 0 | `generated_refresh: completed` |

- Read-only freshness check: affected generated roots `NexusTK/ui/core/DialogPane.cpp`, `NexusTK/util/List.cpp`, `NexusTK/cashshop/FittingRoom.cpp`, `NexusTK/ui/dialogs/WebBoardDialog.cpp`, and `NexusTK/ui/dialogs/HeadSelectDialog.cpp` all carry `validator-command-id: 000000008712` and `validator-refreshed-at: 2026-07-12T20:11:44-04:00`.
- Read-only target check: generated DialogPane contains exactly one `UID:00012T`, exactly one `void DialogPane::RemoveControl(int controlIndex)` body, score `90/92`, and zero `UID:00012T ... Empty Emitter Marker` lines.
- Read-only support check: generated DialogPane preserves B005's public `OnControlCommand(int,int)` and public `FindControlIndex(const ControlPane *) const`; the find body uses exact `GetElementAt` slot access. Generated List contains inline `GetCount()`, FittingRoom saves index 7 before removal/destruction, WebBoard removes `1` then `0`, and HeadSelect truncates at index/count 7.
- Read-only managed-block check: the report contains exactly eight managed blocks, each corresponding destination contains exactly one managed block, and normalized byte-for-byte comparison matched all eight report blocks to their current destination blocks.
- Known validator link warnings for UID0003KH/UID0003KI reflect registry lag and were not validation failures; scoped commands exited successfully and inserted validator-owned links. No accepted callback item remains unresolved.

## Changed Files

- Modified by B004: `by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md`, `by-class/DialogPane.md`, `by-file/DialogPane.md`, `by-type/by-struct/DialogPaneLayout.md`, `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`, `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md`, and `by-memory/0x0049dca0-0x0049dcf8.DialogPaneSelectControlById.md`.
- Modified by B004: `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md`, `by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md`, `by-class/List.md`, `by-file/List.md`, `by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md`, `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md`, and `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`.
- Modified by B004: `tools/leaser/Agents/Agent-B004/research/00012T-DialogCategorySwitch-source-quality.md`.
- Validator-owned side effects: generated roots and validator metadata refreshed through commands recorded above; B004 made no manual generated/coverage/tracker/registry/supervisor edit.
- Renamed: none.
- Leases: each by-* lease was acquired immediately before that file's edit and released immediately after its scoped validator; no lease remains held. No lease was required for the report in B004's own research folder.
- Report lifecycle: B004 performed no execute, lifecycle, move, or archive command. Supervisor/validator-owned state is external and must be read from validator headers/history/current path.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor accepted exact pre-callback report SHA `56B5B2E15E216FA3A4E376AF57350DB04F11B9E99E5C14AAB1D5C4ECF19AD5D5` before implementation.
- [x] Target/support docs to update are enumerated path by path.
- [x] Current target state and actual MCP/docs/generated evidence are recorded.
- [x] Claim And Incorporation Ledger has destination/action/state for C01-C24.
- [x] Target metadata recommendation is `86/90 -> 90/92`; support scores stay unchanged.
- [x] Every target score blocker was researched to a concrete resolution.
- [x] Owner/emitter/reconstructable/position/Nested state is explicitly preserved.
- [x] Split/rename/new-child disposition is no split, no merge, no physical rename, no new child.
- [x] Source placement, range, padding, liveness, type, return, and name issues are resolved.
- [x] Exact target and triggered support managed C++ is supplied; Appendix A carries the full HeadSelect aggregate block.
- [x] Third-party import directive is confirmed not applicable.
- [x] Target/support facts are specified at report-level detail without relying on generated output as authority.
- [x] Historical category/custom-manager/ID assumptions and rejected alternatives are preserved as superseded evidence.
- [x] Wave3 references encountered in support were ignored as stale authority.
- [x] Open questions are reduced to nonblocking original-spelling caps.
- [x] B005 overlap prerequisite completed: UID00011F supervisor-verified/validator-executed at `000000008656`; finalized `by-class/DialogPane.md` and UID0003KJ re-read/rebased in all related report sections and managed blocks.
- [x] One scoped file validator passed for each accepted changed by-* document; command IDs/timestamps are recorded above.
- [x] Generated DialogPane/FittingRoom/WebBoard/HeadSelect/List refresh completed at `000000008712`; read-only UID00012T one-body/no-empty-marker checks passed.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact SHA `56B5B2E15E216FA3A4E376AF57350DB04F11B9E99E5C14AAB1D5C4ECF19AD5D5`.
- [x] B005 UID00011F supervisor-finalized and validator-executed at `000000008656`; shared `by-class/DialogPane.md` and UID0003KJ re-read/rebased report-only before any B004 lease or by-* edit.
- [x] All accepted target/support details incorporated at report-level detail across fourteen by-* documents.
- [x] Ledger updated claim by claim with validator proof for C01-C24.
- [x] Metadata/score/owner/emitter/name/C++ changes applied exactly as accepted; target is `90/92`, owner/emitter UID00003T, reconstructable true, blank position, Nested 0.
- [x] Historical/rejected/negative evidence preserved.
- [x] Open questions retained only as evidence-backed spelling caps.
- [x] Scoped validators run and command IDs/timestamps/exit/ok recorded.
- [x] Generated refresh `000000008712` awaited; target emitted body/no Empty Emitter Marker verified read-only.
- [x] No accepted implementation item remains unapplied or blocked.

## Appendix A - Complete HeadSelect Support Managed Block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {

const int kHeadsPerPage = 10;
const int kHeadButtonCount = 10;
const int kFirstHeadButtonControlIndex = 7;
const int kPreviewControlIndex = 5;

int LowSignedByte(int value)
{
    return static_cast<signed char>(value & 0xff);
}

void PatchNormalHeadOffsets()
{
    s_normalHeadVerticalOffsets[900] = -5;
    s_normalHeadVerticalOffsets[901] = -8;
    s_normalHeadVerticalOffsets[902] = -2;
}

void PatchHighResHeadOffsets()
{
    static const int kTail[] = {
        -5, -8, -2, -7, -8, -9, -3, -2, -9, -2, -10, -3, -3
    };

    for (int i = 0; i < static_cast<int>(sizeof(kTail) / sizeof(kTail[0])); ++i) {
        s_highResHeadVerticalOffsets[900 + i] = kTail[i];
    }
}

const int *CurrentHeadOffsetTable()
{
    return (g_useEpfAssets == 1)
        ? s_highResHeadVerticalOffsets
        : s_normalHeadVerticalOffsets;
}

RectBounds PreviewRect()
{
    return (g_useEpfAssets == 1)
        ? RectBounds(36, 40, 73, 95)
        : RectBounds(36, 40, 71, 88);
}

RectBounds BottomButtonRect(int slot)
{
    static const RectBounds kHighRes[] = {
        RectBounds(40, 266, 103, 290),
        RectBounds(114, 266, 177, 290),
        RectBounds(188, 266, 251, 290),
        RectBounds(262, 266, 325, 290),
    };

    static const RectBounds kNormal[] = {
        RectBounds(40, 266, 112, 282),
        RectBounds(114, 266, 186, 282),
        RectBounds(188, 266, 260, 282),
        RectBounds(262, 266, 334, 282),
    };

    return (g_useEpfAssets == 1) ? kHighRes[slot] : kNormal[slot];
}

RectBounds HeadButtonRect(int slot)
{
    const int x = 54 * (slot % 5) + 58;
    const int y = ((slot / 5) << 6) + 113;
    return RectBounds(x, y, x + 41, y + 54);
}

} // namespace

HeadSelectDialog::HeadSelectDialog(const unsigned char *packet)
    : DialogPane(L"", true, true),
      m_dialogSubtype(0),
      m_headPrice(0),
      m_npcId(0),
      m_objectId(0),
      m_headCount(0),
      m_selectedHead(0),
      m_currentPage(0),
      m_baseHeadDrawOffset(0),
      m_previewPane(0),
      m_confirmButton(0),
      m_nextPageButton(0),
      m_prevPageButton(0)
{
    m_previewObject.defaultByte = 0x50;

    if (g_useEpfAssets == 1) {
        PatchHighResHeadOffsets();
    } else {
        PatchNormalHeadOffsets();
    }

    m_dialogSubtype = packet[0];
    m_headPrice = PacketBufferReadUInt32BE(packet + 1);

    if (packet[5] == 2) {
        const_cast<unsigned char *>(packet)[6] = 2;
    }

    const int objectBytes = ObjectStatusBlob::ParseTaggedStatus(&m_previewObject, packet + 6);
    if (objectBytes < 0) {
        return;
    }

    const int *offsetTable = CurrentHeadOffsetTable();
    m_baseHeadDrawOffset =
        static_cast<unsigned char>(m_previewObject.headDrawOffset) -
        offsetTable[m_previewObject.headIndex];

    int pos = objectBytes + 10;
    m_npcId = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    m_objectId = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    packet[pos++];
    packet[pos++];

    const unsigned int messageLength = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    char messageText[32768];
    wchar_t wideMessageText[32768];

    CopyBytes(messageText, packet + pos, messageLength);
    if (messageLength >= sizeof(messageText)) {
        ReportRangeCheckFailure();
    }
    messageText[messageLength] = 0;

    const unsigned int wideLength = MultiByteToWideChar(
        0,
        0,
        messageText,
        messageLength,
        wideMessageText,
        32768);
    if (wideLength >= 32768) {
        ReportRangeCheckFailure();
    }
    wideMessageText[wideLength] = 0;

    m_headCount = g_pNewHumanImageLib->GetHeadCount();
    m_selectedHead = m_previewObject.headIndex;
    if (m_selectedHead >= m_headCount) {
        m_selectedHead = m_headCount - 1;
    }
    if (m_selectedHead < 0) {
        m_selectedHead = 0;
    }

    m_currentPage = m_selectedHead / kHeadsPerPage;

    AddControl(new EPFImageControlPane(
        L"DLGMSGH.EPF",
        0,
        true,
        RectBounds(0, 0, 374, 316),
        L"NPAL8.PAL"));

    m_confirmButton = new ImageButtonControlPane(14, BottomButtonRect(0));
    AddControl(m_confirmButton);

    m_prevPageButton = new ImageButtonControlPane(18, BottomButtonRect(1));
    AddControl(m_prevPageButton);

    m_nextPageButton = new ImageButtonControlPane(19, BottomButtonRect(2));
    AddControl(m_nextPageButton);

    AddControl(new ImageButtonControlPane(15, BottomButtonRect(3)));

    UpdatePageButtonStates();

    m_previewPane = new ObjectImageControlPane(&m_previewObject, PreviewRect());
    AddControl(m_previewPane);

    AddControl(new StaticTextControlPane(
        wideMessageText,
        true,
        128,
        143,
        RectBounds(86, 29, 336, 92),
        false,
        0));

    for (int i = 0; i < kHeadButtonCount; ++i) {
        m_headButtons[i] = 0;
    }

    SetFocusedControl(1);
    SetPendingControl(4);
    SetBackgroundResource(L"DLGMSGH.EPF", 0);
    OnShow(0, 0);

    PopulateHeadButtons(m_currentPage, false);
}

HeadSelectDialog::~HeadSelectDialog()
{
    OnDialogDestroying();
    RemoveDialogControls();
}

void HeadSelectDialog::RefreshHeadPreview()
{
    ObjectImageControlPane *oldPreview = m_previewPane;
    const int *offsetTable = CurrentHeadOffsetTable();

    m_previewObject.headIndex = static_cast<unsigned short>(m_selectedHead);
    m_previewObject.headDrawOffset = static_cast<unsigned char>(
        m_baseHeadDrawOffset + LowSignedByte(offsetTable[m_selectedHead]));

    m_previewPane = new ObjectImageControlPane(&m_previewObject, PreviewRect());
    ControlPane **previewSlot = static_cast<ControlPane **>(
        m_controlManager->GetElementAt(kPreviewControlIndex));
    *previewSlot = m_previewPane;

    DestroyPane(oldPreview);
    Invalidate();
    Repaint(RectBounds(0, 0, 374, 316), 0, 0, g_transparentColor);
}

void HeadSelectDialog::UpdatePageButtonStates()
{
    if (m_currentPage < 1) {
        m_prevPageButton->Disable();
    } else {
        m_prevPageButton->Enable();
    }

    if (m_currentPage >= m_headCount / kHeadsPerPage) {
        m_nextPageButton->Disable();
    } else {
        m_nextPageButton->Enable();
    }
}

void HeadSelectDialog::NextHeadPage()
{
    ++m_currentPage;
    if (m_currentPage * kHeadsPerPage >= m_headCount) {
        --m_currentPage;
    }

    PopulateHeadButtons(m_currentPage, true);
    UpdatePageButtonStates();
}

void HeadSelectDialog::PreviousHeadPage()
{
    --m_currentPage;
    if (m_currentPage < 0) {
        m_currentPage = 0;
    }

    PopulateHeadButtons(m_currentPage, true);
    UpdatePageButtonStates();
}

void HeadSelectDialog::PopulateHeadButtons(int page, bool removeExistingButtons)
{
    if (removeExistingButtons && GetControlCount() != kFirstHeadButtonControlIndex) {
        do {
            RemoveControl(kFirstHeadButtonControlIndex);
        } while (GetControlCount() != kFirstHeadButtonControlIndex);
    }

    const int firstHead = page * kHeadsPerPage;
    const int *offsetTable = CurrentHeadOffsetTable();

    for (int slot = 0; slot < kHeadButtonCount; ++slot) {
        if (m_headButtons[slot] != 0) {
            DestroyPane(m_headButtons[slot]);
            m_headButtons[slot] = 0;
        }

        const int head = firstHead + slot;
        m_previewObject.headIndex = static_cast<unsigned short>(head);
        m_previewObject.headDrawOffset = static_cast<unsigned char>(
            m_baseHeadDrawOffset + LowSignedByte(offsetTable[head]));

        if (head >= m_headCount) {
            break;
        }

        ObjectImageButtonPane *button =
            new ObjectImageButtonPane(&m_previewObject, HeadButtonRect(slot));
        m_headButtons[slot] = button;

        if (head == m_selectedHead) {
            button->SetButtonHighlight(true);
        }

        AddControl(button);
    }

    Invalidate();
    Repaint(RectBounds(0, 0, 374, 316), 0, 0, g_transparentColor);
}

void HeadSelectDialog::OnAction(int actionId, int /*unused*/)
{
    switch (actionId) {
    case 1:
    case 4:
        CloseDialog();
        break;

    case 2:
        PreviousHeadPage();
        break;

    case 3:
        NextHeadPage();
        break;

    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        ObjectImageButtonPane *oldButton =
            m_headButtons[m_selectedHead % kHeadsPerPage];
        if (oldButton != 0) {
            oldButton->SetButtonHighlight(false);
        }

        m_selectedHead = actionId + (m_currentPage * kHeadsPerPage) - 7;

        ObjectImageButtonPane *newButton =
            m_headButtons[m_selectedHead % kHeadsPerPage];
        if (newButton != 0) {
            newButton->SetButtonHighlight(true);
        }

        RefreshHeadPreview();
        PopulateHeadButtons(m_currentPage, true);
        break;
    }

    default:
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000008758","destination_path":"executed-b-agent-research/B004/00012T-DialogCategorySwitch-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00012T-DialogCategorySwitch-source-quality.md","timestamp":"2026-07-12T20:32:38-04:00","uid":"00012T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
