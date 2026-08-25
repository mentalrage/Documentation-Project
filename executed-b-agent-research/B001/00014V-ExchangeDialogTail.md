** TARGET-REPORT-UID:00014V **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014V ExchangeDialogTail Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00014V] `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md` as a parent-blank, non-emitting split inventory. Do not assign the broad aggregate to `ExchangeDialog`, `ExchangeAlertPane`, `ExchangeMoneyEditControlPane`, `ItemDialogs`, `MixItemDialog`, or `FunctionObjects`.
- Final disposition: repaired in place. The aggregate is now `90/92`, `RECONSTRUCTABLE:FALSE`, with exact source-bearing children assigned only when direct ownership and the strict `85/85` parent gate are satisfied.
- Required action: accept the split repair if supervisor validation remains clean, archive this report, and leave the shared return-true helper parent blank until a broader pane/control virtual-helper pass proves the direct owner.
- Confidence: high for the mixed-container disposition and exact child boundaries; medium-high for the shared helper blocker because IDA proves shared vtable use but not the original base-class source owner.

## Supporting Research

## Target
- Target UID: `00014V`.
- Target path: `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md`.
- Source queue/report row: supervisor assignment `B001-027`, status `reviewed-no-85-under-review`.
- Starting state: `83/89`, `RECONSTRUCTABLE:TRUE`, parent blank. The previous A-agent review left it unassigned because the range interleaved ExchangeDialog rows with ItemDialogs/function-object rows.
- Final state: `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank. The file is now an inventory/container for exact child pages and documented blocker rows.

## Executive Recommendation
- The target is not a single reconstructable source item. It crosses `ExchangeAlertPane`, `MixItemDialog`, `FunctionObjects`, mixed compiler-generated destructor/thunk glue, `ExchangeMoneyEditControlPane`, and a shared return-true virtual helper reused by non-exchange vtables.
- The accepted `00014T` repair already split and validated the overlapping `0x004b0490-0x004b0b15` portion. B001-027 split the remaining `0x004b0b20-0x004b0ba5` tail into four exact child pages.
- `00033Z`, `000340`, and `000341` are reconstructable and assigned to gate-clearing direct parents. `000342` is reconstructable but intentionally parent blank because IDA proves the body is shared by multiple unrelated vtable families.

## Supervisor Active Recheck
- The supervisor assigned one target: `00014V ExchangeDialogTail`. B001 workers created/repaired the by-* documentation, but both subagent instances stalled before producing a final report. The supervisor finalized this report from the current by-* docs and independent validator results instead of accepting the stale checkpoint.
- The assigned item required split repair before a final master report because the broad range mixed exchange alert code, money edit-control code, item/mix destructor glue, function-object callback code, padding, and a shared virtual helper.
- Current by-* evidence shows every source-bearing child in scope is now either assigned under a gate-clearing direct parent or has a precise evidence-backed blocker.

## Inference Research Guidance Check
- `by-structure.md` requires exact source-bearing children and actual direct semantic parents. It does not permit assigning a broad mixed range to a nearby source file just because the bytes are adjacent.
- Existing documentation was treated as a lead. Accepted `00014T` evidence was reused only for the overlapping part; the remaining `00014V` tail was independently split and documented.
- IDA facts drive the ownership decisions: modeled function starts/ends, padding bytes, singleton/global references, vtable references, callers/callees, and negative shared-vtable evidence. Documentation evidence supplies context and cross-links but is not treated as proof by itself.

## Evidence Standards Used
- IDA MCP evidence recorded in the changed docs: `lookup_funcs`, disassembly/decompilation summaries, callers/callees, `xrefs_to`, vtable/data refs, dword reads, and byte checks for padding.
- Documentation evidence: accepted `00014T` report, `ExchangeDialogTail`, `ExchangeAlertPane`, `ExchangeMoneyEditControlPane`, `TextEditControlPane`, `ControlFamilyStateVirtualHelpers`, `MapRefreshDimmerVtableData`, and generated coverage state.
- Negative evidence: consumer/read/vtable references are separated from ownership. Physical adjacency to exchange code is not enough to assign item/mix thunks or a shared return-true helper to exchange classes.

## IDA MCP Facts
- Function/range facts: the aggregate spans `0x004b0490-0x004b0ba5`; the next modeled function starts at `0x004b0bb0` in the `FieldMapPane` island, so the aggregate end remains exclusive at `0x004b0ba5`.
- Existing overlap facts from accepted `00014T`: `0x004b0490-0x004b086b` is `ExchangeAlertPaneCore`; `0x004b0870-0x004b087b` clears the `MixItemDialog` singleton; `0x004b0880-0x004b08a1` is the MixItemDialog double-param function-object callback; `0x004b08a1-0x004b0b15` is a mixed compiler destructor/thunk strip.
- B001-027 tail facts: `0x004b0b20-0x004b0b31` is a modeled close-active exchange alert helper; `0x004b0b40-0x004b0b54` is a vtable-reached exchange money edit-control activation wrapper; `0x004b0b60-0x004b0b96` is a vtable-reached digit key handler; `0x004b0ba0-0x004b0ba5` is `mov al, 1; retn 4`.
- Padding facts: the aggregate records `0xcc` padding at `0x004b0819-0x004b0820`, `0x004b086b-0x004b0870`, `0x004b087b-0x004b0880`, `0x004b0a15-0x004b0a20`, `0x004b0a5b-0x004b0a60`, `0x004b0acb-0x004b0ad0`, `0x004b0b15-0x004b0b20`, `0x004b0b31-0x004b0b40`, `0x004b0b54-0x004b0b60`, `0x004b0b96-0x004b0ba0`, and `0x004b0ba5-0x004b0bb0`.
- Xref facts: `0x004b0b20` reads `dword_69B330` / `g_pExchangeAlertPane` and is called from exchange dispatcher/ready paths at `0x004ad741` and `0x004adf59`.
- Vtable/global facts: `0x004b0b40` has vtable/data ref `0x0061a2c0`; `0x004b0b60` has vtable/data ref `0x0061a2d4`; both sit in `ExchangeMoneyEditControlPane` table data. `0x004b0ba0` has refs from `0x0061a2d0`, `0x0061e8a8`, `0x0061e8ac`, `0x006234d4`, `0x006234d8`, `0x0062f01c`, and `0x0062f020`, spanning exchange money, `MapRefreshDimmer`, `ScreenDimmer`, and `InputBlockerPane` vtable data.
- Negative IDA facts: no single owner covers the whole aggregate. `0x004b0ba0` cannot be attached to `ExchangeMoneyEditControlPane` just because one exchange vtable references it; IDA proves unrelated vtables reuse the same tiny body.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b0490-0x004b0ba5` | `00014V` `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md` | Mixed split inventory | False | blank | `90/92` | repaired container |
| `0x004b0490-0x004b086b` | `00033W` `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md` | Exchange alert constructor/button/clear core | True | `00004Q` | `85/88` | existing exact child from accepted `00014T` |
| `0x004b0870-0x004b087b` | `00033X` `by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md` | Mix singleton clear | True | `00008J` | `85/90` | existing exact child from accepted `00014T` |
| `0x004b0880-0x004b08a1` | `00014W` `by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md` | Function-object callback wrapper | True | `0000JO` | `85/88` | existing exact child |
| `0x004b08a1-0x004b0b15` | `00033Y` `by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md` | Mixed compiler destructor/thunk strip | False | blank | `88/91` | non-emitting inventory |
| `0x004b0b20-0x004b0b31` | `00033Z` `by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md` | Close active exchange alert helper | True | `00004Q` | `85/90` | created and assigned |
| `0x004b0b40-0x004b0b54` | `000340` `by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md` | Money edit-control activation/state wrapper | True | `00004T` | `85/88` | created and assigned |
| `0x004b0b60-0x004b0b96` | `000341` `by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md` | Money edit-control digit key handler | True | `00004T` | `85/89` | created and assigned |
| `0x004b0ba0-0x004b0ba5` | `000342` `by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md` | Shared return-true virtual helper | True | blank | `85/87` | created, assignment blocked |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b0b20` | callers `0x004ad741`, `0x004adf59`; xrefs to `dword_69B330` | Exchange dispatcher/ready paths close the active exchange alert. |
| `0x004b0b40` | vtable/data ref `0x0061a2c0`; calls `0x00498c00`; tail-jumps to `0x00494c30` | ExchangeMoneyEditControlPane wrapper over text-edit/control state helpers. |
| `0x004b0b60` | vtable/data ref `0x0061a2d4`; calls `0x00498d90` | ExchangeMoneyEditControlPane key filter accepts numeric events and forwards accepted input. |
| `0x004b0ba0` | vtable refs `0x0061a2d0`, `0x0061e8a8`, `0x0061e8ac`, `0x006234d4`, `0x006234d8`, `0x0062f01c`, `0x0062f020` | Shared trivial true predicate reused by exchange money and unrelated pane/dimmer/input-blocker vtables. |
| `0x004b0bb0` | successor modeled function start | Confirms `00014V` ends before the FieldMapPane island. |

## Documentation Evidence And IDA Status
- Existing docs supporting the conclusion: `00014V ExchangeDialogTail`, `00014T ItemExchangeMixDialogs`, `ExchangeAlertPane`, `ExchangeMoneyEditControlPane`, `TextEditControlPane`, `ControlFamilyStateVirtualHelpers`, and `MapRefreshDimmerVtableData`.
- Docs repaired by this work: `00014V` is now a parent-blank non-emitting split inventory; `ExchangeAlertPane` is `86/89` and links `00033Z`; `ExchangeMoneyEditControlPane` is `85/88` and links `000340`, `000341`, and the blocked `000342`.
- Generated/coverage state: targeted validator file scans refreshed generated state and all seven B001-027 files exited `0`.

## Ranked Ownership Analysis

### 1. Parent-Blank Split Inventory For `00014V`
- Evidence for: the range contains exact exchange-alert code, mix/item-dialog neighbors, function-object callback glue, compiler-generated destructor/thunk strips, money edit-control methods, shared helpers, and padding.
- Evidence against: none for source emission. The exact source-bearing rows are carried by children.
- Decision: accepted. `00014V` is `RECONSTRUCTABLE:FALSE`, parent blank, and scored `90/92`.

### 2. `ExchangeDialog` / Exchange Private Classes
- Evidence for: `ExchangeAlertPane` and `ExchangeMoneyEditControlPane` are private exchange-dialog feature classes under `ExchangeDialog.cpp`; the close-active helper uses `g_pExchangeAlertPane`; money edit-control helpers are vtable-reached from exchange money table data.
- Evidence against: exchange does not own the interleaved `MixItemDialog`, `ItemDialogs`, function-object, or shared pane/control helper rows.
- Decision: accepted for `00033Z`, `000340`, `000341`, `ExchangeAlertPane`, and `ExchangeMoneyEditControlPane`; rejected for the broad aggregate.

### 3. `ItemDialogs`, `MixItemDialog`, And `FunctionObjects`
- Evidence for: accepted `00014T` already proved the overlapping mix singleton clear, callback wrapper, and destructor/thunk strip belong outside the exchange-alert/money class owners.
- Evidence against: those owners do not cover the new exchange alert close-active or money edit-control tail helpers.
- Decision: preserve accepted child ownership from `00014T`; do not assign `00014V` to these owners.

### 4. Shared Pane/Control Virtual Helper For `000342`
- Evidence for: `0x004b0ba0` is a tiny return-true implementation referenced by exchange money and unrelated pane/dimmer/input-blocker vtables, which is characteristic of a shared inherited virtual predicate.
- Evidence against: this assignment cannot be resolved from `00014V` alone. Attaching to `ExchangeMoneyEditControlPane` would ignore the proven non-exchange vtable refs.
- Decision: create and document `000342` at `85/87`, but leave `AUTOGEN_PARENT_UID` blank until a broader pane/control-family pass proves the direct owner and the direct parent clears `85/85`.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new source file is recommended for `00014V`.
- Likely full contents: existing source owners are sufficient for exchange alert and money edit-control helpers; the broad target is a non-source inventory.
- Candidate related items that belong: `00033Z` under `ExchangeAlertPane`; `000340` and `000341` under `ExchangeMoneyEditControlPane`; `000342` under a future proven shared pane/control owner.
- Candidate related items rejected: assigning `000342` to `ExchangeMoneyEditControlPane`; assigning the full aggregate to `ExchangeDialog`; merging item/mix/function-object rows into exchange.
- Standalone, narrow, or broad source-file inference: broad documentation inventory, not a standalone source file.

## Negative Evidence Summary
- Physical adjacency to exchange code is not ownership proof. `00014V` overlaps item/mix/function-object rows that accepted `00014T` already split away from exchange ownership.
- A vtable ref from `ExchangeMoneyEditControlPane` is not sufficient for `000342`; multiple unrelated vtables point at the same function body.
- Compiler-generated destructor adjustor thunks and scalar deleting destructors remain non-emitting where they represent generated glue rather than handwritten source bodies.
- Padding rows are explicitly documented as `0xcc` and should not become child source pages.

## Final Recommendation
- Exact changes applied: `00014V` converted from below-gate reconstructable aggregate to parent-blank non-emitting split inventory `90/92`; four exact child pages created for the remaining tail; direct parent pages repaired for exchange alert and money edit-control ownership.
- Exact parent assignments applied: `00033Z -> 00004Q`; `000340 -> 00004T`; `000341 -> 00004T`.
- Exact items left unassigned and why: `00014V` remains parent blank because it is a mixed non-emitting inventory; `000342` remains parent blank because IDA proves shared vtable use and the direct source owner is unresolved.
- Exact future work outside this assignment scope: a broader shared pane/control virtual-helper pass should determine whether `000342` belongs to `ControlPane`, another base pane class, a shared generated helper group, or a new source grouping. Do not assign it until that owner and parent gate are defensible.

## Follow-Up Actions
- Supervisor actions: if independent validation remains clean, update `Supervisor_notes.md` for `00014V` to `complete-or-reclassified`, move this report to `research/executed`, and assign B001 the next one-at-a-time ownership/split target.
- A-agent actions: no immediate A-agent work is required for `00014V`; avoid reassigning the aggregate as source-bearing.
- B001 future research actions: consider the shared return-true virtual helper cluster if a future target covers pane/control vtable reuse.

## Confidence
- Recommendation confidence: high for `00014V` as a non-emitting split inventory.
- Score confidence: high for `00033Z`, `000340`, and `000341`; medium-high for `000342` because exact bytes and shared refs are known, but original source owner/name are unresolved.
- Remaining uncertainty: final source-level helper names, exact event/slot names, and the direct owner for shared return-true helper `000342`.

## Validator Results
- Commands run:
  - `python tools/validator.py --queue-timeout 180 --mode file --file by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md --apply`
  - `python tools/validator.py --queue-timeout 180 --mode file --file by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md --apply`
  - `python tools/validator.py --queue-timeout 180 --mode file --file by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md --apply`
  - `python tools/validator.py --queue-timeout 180 --mode file --file by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md --apply`
  - `python tools/validator.py --queue-timeout 180 --mode file --file by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md --apply`
  - `python tools/validator.py --queue-timeout 180 --mode file --file by-class/ExchangeAlertPane.md --apply`
  - `python tools/validator.py --queue-timeout 180 --mode file --file by-class/ExchangeMoneyEditControlPane.md --apply`
- Results: all seven targeted scans exited `0`.
- Any unresolved validator warnings/errors: none for these files. The scan output includes the known `autogen_cpp_noop 0000J5 auto-generated/NexusTK/util/Error.cpp no assembled code for root` filename match; this is a validator output false positive for the word `Error.cpp`, not a `00014V` diagnostic.

## Changed Files
- Created:
  - `by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md`
  - `by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md`
  - `by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md`
  - `by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md`
- Modified:
  - `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md`
  - `by-class/ExchangeAlertPane.md`
  - `by-class/ExchangeMoneyEditControlPane.md`
  - Validator-managed generated/state outputs updated by targeted scans.
- Renamed:
  - None.
- Moved to executed:
  - None yet.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00014V-ExchangeDialogTail.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00014V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
