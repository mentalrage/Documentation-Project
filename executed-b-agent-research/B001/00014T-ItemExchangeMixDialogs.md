** TARGET-REPORT-UID:00014T **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014T ItemExchangeMixDialogs Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep `00014T` as a parent-blank, non-emitting split inventory. Do not assign the broad aggregate to `ItemDialogs`, `ExchangeDialog`, or any single parent.
- Final disposition: repaired in place. The target is now `90/92`, `RECONSTRUCTABLE:FALSE`, with exact source-bearing children assigned to repaired direct parents and mixed compiler glue documented as non-emitting.
- Required action: supervisor review and archive/execute this report when accepted. No remaining in-range source-bearing child is left as a vague follow-up.
- Confidence: high. IDA MCP function inventory, raw disassembly, xrefs, vtable refs, and existing by-* docs agree that the aggregate is mixed and must remain a split container.

## Supporting Research

## Target
- Target UID: `00014T`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md`.
- Source queue/report row: supervisor assigned B001-026, `reviewed-no-85-under-review`.
- Current supervisor classification: `reviewed-no-85-under-review`.
- Starting state: target was `82/89`, `RECONSTRUCTABLE:TRUE`, parent blank, with stale padding claims and below-gate children.
- Final state: target is `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank, with exact children or explicit non-emitting inventory for every in-range source-bearing/helper/destructor/thunk island.

## Executive Recommendation
- The broad aggregate should not emit source. It crosses `ItemDialogs`, `MyItemListPane`, `FunctionObjects`, `ExchangeDialog`, and mixed compiler-generated destructor/thunk glue.
- Reconstructable exact children are assigned only when child and direct parent clear `85/85`.
- Non-reconstructable thunk/destructor strips stay parent blank. Their behavior should be produced by normal C++ class inheritance/destructors, not hand-authored methods.
- Related `00014V ExchangeDialogTail` remains evidence-only for this task except for overlapping `0x004b0490-0x004b0b15` facts; full `00014V` repair is outside B001-026.

## Supervisor Active Recheck
- The supervisor asked B001 to audit `00014T`, inspect related `00014V` only where needed, repair exact children first, validate changed by-* files, and not edit `Supervisor_notes.md`.
- The assigned item required split repair before final report completion because the target contained mixed owners and stale/missing child rows.
- Every source-bearing in-range function/helper/destructor/thunk is now either exact child/repaired and assigned under a qualifying parent, or documented as non-emitting compiler-generated glue with direct evidence.

## Inference Research Guidance Check
- `by-structure.md` and `goal.md` drove the split-first decision: broad mixed ranges are inventories, not source bodies.
- Existing docs were treated as leads, not proof. The stale target claim that `0x004af4f0-0x004af570` was padding was contradicted by IDA disassembly showing a real packet helper.
- Facts are IDA function bytes/xrefs/vtables/callers. Documentation evidence is existing by-* parent/source placement. Inference is the direct owner assignment where original source names are unavailable.

## Evidence Standards Used
- IDA MCP: full function inventory for `0x004ae4c0-0x004b0b15`, raw disassembly for helper islands, xrefs/data refs, vtable refs, and caller/callee context.
- Existing docs: `ItemDialogs`, `ExchangeDialog`, `MyItemListPane`, `FunctionObjects`, class pages, exact child pages, and generated `-ag-memory-coverage`.
- Negative evidence: no single parent owns all rows; raw helper no-xref state does not make those bytes padding; physical adjacency to exchange alert code does not override MixItemDialog/FunctionObjects construction evidence.

## IDA MCP Facts
- Function/range facts: IDA confirms modeled starts at `0x004ae4c0`, `0x004ae900`, `0x004ae930`, `0x004aea40`, `0x004aea80`, `0x004aeab0`, `0x004aeb30`, `0x004aec80`, `0x004aec90`, `0x004af040`, `0x004af380`, `0x004af480`, `0x004af4c0`, `0x004af570`, `0x004af8b0`, `0x004afcc0`, `0x004afe40`, `0x004b0000`, `0x004b0120`, `0x004b0490`, `0x004b0820`, `0x004b0860`, `0x004b0870`, `0x004b0880`, and the strip starts through `0x004b0ad0`.
- Raw helper facts: `0x004aeac0-0x004aeb2f` builds opcode `0x4a/1`; `0x004af4f0-0x004af570` builds opcode `0x4a/2`; `0x004afb80-0x004afcb7` builds opcode `0x6b`.
- Data/table/padding facts: `0x004afb68` is a switch jump table for `MixItemDialog` action dispatch; all listed inter-function gaps were checked as `0xcc` padding except raw helper bodies/table data.
- Xref facts: `0x004b0490` is called from ExchangeDialog packet alert paths at `0x004ad656`, `0x004ad775`, `0x004ade18`, and `0x004adf8d`; `0x004b0880` is vtable/data referenced at `0x0061a3bc` and constructed at `0x004afd62`/`0x004b0370`.
- Vtable/global facts: `dword_69B328` is AddItem/AddMixing singleton state, `dword_69B32C` is MixItemDialog singleton state, and `dword_69B330` is ExchangeAlertPane singleton state.
- Negative IDA facts: the raw helpers have no ordinary static xrefs and are not modeled as IDA functions, but their prologues, packet writes, sends, returns, and ownership-adjacent fields are concrete executable code.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ae4c0-0x004b0b15` | `00014T` target | Mixed inventory | False | blank | `90/92` | repaired container |
| `0x004ae4c0-0x004aea7d` | `00033Q` AddItemDialogCore | constructor/destructor/action/state | True | `000007` | `85/89` | assigned |
| `0x004aea80-0x004aeab0` | `000317` AddItemDialog packet close | vtable packet-close handler | True | `000007` | existing 85+ | assigned |
| `0x004aeab0-0x004aeb30` | `00033R` AddItemDialogSubmitPacketHelper | singleton getter plus raw packet helper | True | `000007` | `85/86` | assigned |
| `0x004aeb30-0x004af031` | `00014U` MyItemListPane | split inventory | False | blank | `86/88` | repaired container |
| `0x004aeb30-0x004aec77` | `0002JO` MyItemListPaneConstructor | list constructor | True | `0000LO` | `85/88` | assigned |
| `0x004aec80-0x004aec8e` | `0002JP` MyItemListPaneGetSelectedSlotIndex | selected slot helper | True | `0000LO` | `85/90` | assigned |
| `0x004aec90-0x004af031` | `0002JQ` MyItemListPaneDrawListEntry | virtual row renderer | True | `0000LO` | `85/88` | assigned |
| `0x004af040-0x004af4b7` | `00033S` AddItemWithCountDialogCore | constructor/action/state | True | `000008` | `85/89` | assigned |
| `0x004af4c0-0x004af4f0` | `000318` AddItemWithCount packet close | vtable packet-close handler | True | `000008` | existing 85+ | assigned |
| `0x004af4f0-0x004af570` | `00033T` AddItemWithCountSubmitPacketHelper | raw packet helper | True | `000008` | `85/86` | assigned |
| `0x004af570-0x004afb80` | `00033U` MixItemDialogCore | constructor/action/switch table | True | `00008J` | `85/88` | assigned |
| `0x004afb80-0x004afcc0` | `00033V` MixItemDialogSubmitPacketHelper | raw mix packet helper | True | `00008J` | `85/86` | assigned |
| `0x004afcc0-0x004afe38` | `000319` MixItemDialogQuantityPromptHelper | quantity prompt helper | True | `00008J` | existing 85+ | assigned |
| `0x004afe40-0x004afff7` | `00031A` MixItemDialogQuantityCallback | quantity callback | True | `00008J` | existing 85+ | assigned |
| `0x004b0000-0x004b0118` | `0002U1` AddMixing constructor | filtered picker constructor | True | `000009` | `85/88` | assigned |
| `0x004b0120-0x004b048a` | `0002U2` AddMixing confirm | confirm/action handler | True | `000009` | `85/88` | assigned |
| `0x004b0490-0x004b086b` | `00033W` ExchangeAlertPaneCore | alert constructor/button/clear | True | `00004Q` | `85/88` | assigned |
| `0x004b0870-0x004b087b` | `00033X` MixItemDialogSingletonClearHelper | singleton clear | True | `00008J` | `85/90` | assigned |
| `0x004b0880-0x004b08a1` | `00014W` MixItemDialogDoubleParamCallback | callback wrapper | True | `0000JO` | `85/88` | assigned |
| `0x004b08a1-0x004b0b15` | `00033Y` ItemExchangeDestructorAndThunkStrip | mixed compiler glue | False | blank | `88/91` | non-emitting |
| `0x004b08b7-0x004b08cd` | `0002U3` AddMixing adjustors | compiler thunks | False | blank | `85/90` | non-emitting |
| `0x004b08cd-0x004b08e3` | `00014X` ExchangeAlertPane adjustors | compiler thunks | False | blank | `85/88` | non-emitting |
| `0x004b0ab5-0x004b0acb` | `00014Y` ExchangeMoney adjustors | compiler thunks | False | blank | `85/88` | non-emitting |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ae4c0` | callers `0x004a339f`, `0x004ad124`, `0x004af924`, `0x004b0031` | Reusable AddItemDialog used by employee/exchange/mix/add-mixing flows. |
| `0x004aeb30` | callers `0x0048a50d`, `0x004ae63e`, `0x004ae7f0`, `0x004af7a7` | MyItemListPane is reusable picker support, not clan-only or exchange-only. |
| `0x004af040` | callers `0x004ad3bf`, `0x004adaeb` | Exchange code constructs AddItemWithCountDialog but does not own implementation. |
| `0x004b0490` | callers `0x004ad656`, `0x004ad775`, `0x004ade18`, `0x004adf8d` | ExchangeDialog packet alert paths own ExchangeAlertPane core. |
| `0x004b0820` | data ref `0x0061a208` | ExchangeAlertPane action slot. |
| `0x004b0870` | clears `dword_69B32C` | MixItemDialog singleton, not ExchangeAlertPane. |
| `0x004b0880` | data ref `0x0061a3bc`; vtable stores `0x004afd62`, `0x004b0370` | FunctionObject callback wrapper for MixItemDialog quantity paths. |
| `0x004b08a1-0x004b0b15` | vtable-only refs and jumps to scalar deleting destructors | Mixed compiler-generated glue, not handwritten source. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: `ItemDialogs.md` (`90/87`), `ExchangeDialog.md` (`88/86`), `MyItemListPane.md` now `86/85`, `FunctionObjects.md` (`87/85`), `AddItemDialog.md`, `AddItemWithCountDialog.md`, `MixItemDialog.md`, `AddMixingItemDialog.md`, and `ExchangeAlertPane.md`.
- Existing docs repaired: `00014T`, `00014U`, `MyItemListPane` direct parent/children, `AddMixingItemDialog` direct parent/children, function-object class/wrapper, `ExchangeAlertPane`, and existing adjustor pages.
- Existing docs intentionally not fully repaired: `00014V ExchangeDialogTail` remains a separate aggregate. B001 used it only for overlapping evidence and did not convert the whole adjacent row.
- Generated/coverage state after validation: `00014T`, `00014U`, `00033Y`, `0002U3`, `00014X`, and `00014Y` are `not_reconstructable`; exact source-bearing children are assigned to their repaired parents.

## Ranked Ownership Analysis

### 1. Parent-Blank Split Inventory For `00014T`
- Evidence for: the range contains multiple source owners, raw helper islands, exchange-alert overlap, function-object glue, and mixed destructor/thunk rows.
- Evidence against: none for target-wide source ownership; the only reconstructable work belongs to exact children.
- Decision: accepted. Target converted to `RECONSTRUCTABLE:FALSE`, `90/92`, parent blank.

### 2. `ItemDialogs` / Item Dialog Classes
- Evidence for: most rows are AddItemDialog, AddItemWithCountDialog, MixItemDialog, and AddMixingItemDialog code; raw helper opcodes and singleton globals match those classes.
- Evidence against: `0x004b0490-0x004b086b` is ExchangeAlertPane, `0x004b0880` is FunctionObjects template glue, and the destructor strip is mixed.
- Decision: accepted only for exact item/mix children; rejected for broad target.

### 3. `ExchangeDialog`
- Evidence for: `0x004b0490-0x004b086b` constructor callers and singleton/vtable refs are exchange-alert evidence; part of the destructor strip belongs to exchange classes.
- Evidence against: ExchangeDialog does not own AddItemDialog/AddItemWithCount/MyItemListPane/Mix/AddMixing implementations.
- Decision: accepted only for exact ExchangeAlertPane child; rejected for broad target.

### 4. `FunctionObjects`
- Evidence for: `0x004b0880` construction stores and vtable data tie the callback wrapper to the shared function-object template family.
- Evidence against: it owns only the callback wrapper, not surrounding item/exchange code.
- Decision: accepted for `00014W` only.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new source file is recommended.
- Likely full contents: existing owners are sufficient; `00014T` is a documentation inventory.
- Candidate related items that belong: exact children listed above.
- Candidate related items rejected: whole `00014V`; full adjacent exchange-tail repair should be a separate target.
- Standalone, narrow, or broad source-file inference: broad non-source inventory, not a new source module.

## Negative Evidence Summary
- Exchange constructor/caller xrefs prove use of item dialogs, not implementation ownership.
- Physical adjacency to `ExchangeAlertPane` does not make `0x004b0880` exchange-owned; construction-site evidence ties it to MixItemDialog/NumberInput callback use.
- Raw helpers with no IDA function object are not padding; executable prologue/cookie/packet/send/return bytes prove source-bearing helper bodies.
- Compiler-generated adjustor thunks and scalar deleting destructors are not handwritten source-bearing methods.

## Final Recommendation
- Exact changes applied: converted `00014T` and `00014U` to non-emitting inventories, created nine exact child pages, raised below-gate parents/children, and validated changed by-* docs.
- Exact parent assignments applied: new/repaired reconstructable children attach to `000007`, `000008`, `00008J`, `000009`, `0000LO`, `0000JO`, or `00004Q` only when those parents now clear `85/85`.
- Exact items left unassigned and why: `00014T`, `00014U`, `00033Y`, `0002U3`, `00014X`, and `00014Y` are intentionally non-reconstructable/parent blank.
- Exact future work outside scope: full `00014V ExchangeDialogTail` remains eligible for a separate split repair if assigned.

## Follow-Up Actions
- Supervisor actions: review the split repair and, if accepted, execute/archive this report. Do not treat `00014T` as an unassigned source-bearing row anymore.
- A-agent actions: none required for in-range `00014T` source-bearing work.
- B001 future research actions: only if supervisor assigns `00014V` or another adjacent tail row.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for split/container disposition and parent gate repairs; medium-high for raw helper final source names due no static xrefs.
- Remaining uncertainty: original source helper names and exact packet helper names are inferred, so final C++ remains blank on new pages.

## Validator Results
- Commands run:
  - Initial UID assignment scans for the nine new pages: `python tools/validator.py --queue-timeout 180 --mode file --file <new by-memory path> --apply`.
  - Final targeted scans for every created/modified by-* file: `python tools/validator.py --queue-timeout 180 --mode file --file <path> --apply`.
- Results: every changed by-* file scan exited `0`.
- Diagnostics: no `missing_ref`, `tmp_ref`, `invalid`, `duplicate`, `conflict`, `failed`, `traceback`, `unresolved`, or autogen-parent diagnostics were reported. A filtered string match on `auto-generated/NexusTK/util/Error.cpp` was a filename false positive, not a validator issue.

| File | Result |
| --- | --- |
| `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md` | exit `0`; UID `00033Q`; no targeted diagnostics |
| `by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md` | exit `0`; UID `00033R`; no targeted diagnostics |
| `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md` | exit `0`; UID `00033S`; no targeted diagnostics |
| `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md` | exit `0`; UID `00033T`; no targeted diagnostics |
| `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md` | exit `0`; UID `00033U`; no targeted diagnostics |
| `by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md` | exit `0`; UID `00033V`; no targeted diagnostics |
| `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md` | exit `0`; UID `00033W`; no targeted diagnostics |
| `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md` | exit `0`; UID `00033X`; no targeted diagnostics |
| `by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md` | exit `0`; UID `00033Y`; no targeted diagnostics |
| `by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md` | exit `0`; final re-scan clean |
| `by-file/MyItemListPane.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004aeb30-0x004af031.MyItemListPane.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` | exit `0`; no targeted diagnostics |
| `by-class/AddMixingItemDialog.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md` | exit `0`; no targeted diagnostics |
| `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md` | exit `0`; no targeted diagnostics |
| `by-class/ExchangeAlertPane.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md` | exit `0`; no targeted diagnostics |
| `by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md` | exit `0`; no targeted diagnostics |
| `by-class/AddItemDialog.md` | exit `0`; no targeted diagnostics |
| `by-class/AddItemWithCountDialog.md` | exit `0`; no targeted diagnostics |
| `by-class/MixItemDialog.md` | exit `0`; no targeted diagnostics |

## Changed Files
- Created:
  - `tools/leaser/Agents/Agent-B001/research/00014T-ItemExchangeMixDialogs.md`
  - `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md`
  - `by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md`
  - `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md`
  - `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`
  - `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md`
  - `by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md`
  - `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`
  - `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md`
  - `by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md`
- Modified:
  - `by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md`
  - `by-file/MyItemListPane.md`
  - `by-memory/0x004aeb30-0x004af031.MyItemListPane.md`
  - `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md`
  - `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`
  - `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`
  - `by-class/AddMixingItemDialog.md`
  - `by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md`
  - `by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md`
  - `by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md`
  - `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md`
  - `by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md`
  - `by-class/ExchangeAlertPane.md`
  - `by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md`
  - `by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md`
  - `by-class/AddItemDialog.md`
  - `by-class/AddItemWithCountDialog.md`
  - `by-class/MixItemDialog.md`
  - Validator-managed generated/state outputs updated by file scans, including `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and validator backup directories under `tools/validator_autogen_backup/20260610-*`.
- Renamed:
  - None.
- Moved to executed:
  - None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00014T-ItemExchangeMixDialogs.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00014T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
