** TARGET-REPORT-UID:00021O **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 00021O ClanStatusPaneRefreshChildPanes Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00021O] owned and emitted by [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), keep the `social/Clan.cpp` source route through [UID:0000I8][Clan](by-file/Clan.md), and replace the stale blank-C++/no-code rationale with first-draft formal C++.
- Final disposition: modeled `ClanStatusPane::RefreshChildPanes()` helper with two direct callers and source-quality inherited pane cleanup names for the repeated child virtual calls.
- Required action: update target evidence, score, and formal C++; update `ClanStatusPane` support wording so [UID:00021O] is no longer blocked by unresolved `+0x38/+0x40` names.
- Confidence: high for owner, range, caller set, child order, slot targets, and C++ shape; remaining uncertainty is original method spelling only.

## Target

- Target UID: `00021O`.
- Target path: `by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md`.
- Assignment id: `B005-report-00021O-ClanStatusPaneRefreshChildPanes-20260702`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, assigned row `85/88`, reports `0`.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++ with no-code comment.

## Current Target State

The target already has the correct direct owner and emitter route. It is a real IDA function at `0x00487370`, size `0x46`, with exactly two code callers: the clan attribute parser at `0x004848d6` and `ClanStatusPane::OnKeyInput` at `0x00484d79`. It reads `m_joinListPane`, `m_infoListPane`, and `m_enlistListPane` in that order and dispatches primary child vtable slots `+0x38` and `+0x40` on each child.

The stale blocker is the statement that `+0x38/+0x40` are not source-named. Current MCP vtable bytes and current Pane docs resolve the relevant inherited slot meanings:

- Child primary slot `+0x38` points to `0x0055ef10` for all three child pane classes. Existing `ScrollablePaneCore` and `SelfSaveOKPane` docs identify this inherited pane detach/remove path as `RemoveFromLayer()`-style behavior; the `0x0055ef10` body recursively detaches enabled scrollbar children through their `+0x38` slot and then calls base `0x00544ce0`.
- Child primary slot `+0x40` points to `0x00544d70` for all three child pane classes. Existing `PaneChildRegistry`, `ChattingVarietySelectPane`, and `Pane.md` support identify this as the inherited event-handler unregister / dispatcher cleanup path.

The raw show-helper siblings [UID:00021P/Q/R] remain different: they have no function object or inbound route and additionally use selected-child setup slots `+0x30/+0x3c`. Their no-code disposition does not apply to this modeled helper, which has direct call sites and only needs the now-resolved `+0x38/+0x40` cleanup names.

## Supervisor Active Recheck

This is a report-only assignment from `Agent-B005/goal.md`. I wrote only this report in `Agent-B005/research/`. I did not edit target/support by-* docs, generated files, coverage reports, validator state, queues, archives, supervisor ledgers, or report lifecycle state. MCP was available and used through current session `supervisor_resume_20260629`.

## Inference Research Guidance Check

- Direct IDA/MCP facts: function existence, size, disassembly, decompilation, xrefs, callees, nearby function/name inventory, vtable bytes, vtable-store xrefs, helper analysis.
- Documentation evidence: target page, `ClanStatusPane`, `Clan`, child class pages, `ClanPaneListVtableData`, `Pane.md`, `ScrollablePaneCore`, `PaneChildRegistry`, B015/B002/B001 executed reports.
- Inference: `RefreshChildPanes` is the best source-facing helper name and `RemoveFromLayer()` / `UnregisterEventHandler()` are source-facing inherited pane names suitable for first-draft C++ in this target.
- Wave2/Wave3 artifacts were not used as proof.

## Heuristic / Inference Reanalysis And Validation

The previous blocker was valid when the child vtable slots were only known by offset. It is no longer valid for this exact helper. Slot `+0x38` is not a Clan-specific unknown virtual; current vtable bytes show all three child pane classes inherit the same `0x0055ef10` target. Project docs already use `Pane::RemoveFromLayer()` for this family, with the `0x0055ef10` override handling scrollable/text/list child detach before base layer removal. Slot `+0x40` is inherited `0x00544d70`, already documented as `Pane::UnregisterEventHandler()` / event-handler cleanup.

The exact order is source meaningful and should be preserved:

1. `m_joinListPane->RemoveFromLayer();`
2. `m_joinListPane->UnregisterEventHandler();`
3. `m_infoListPane->RemoveFromLayer();`
4. `m_infoListPane->UnregisterEventHandler();`
5. `m_enlistListPane->RemoveFromLayer();`
6. `m_enlistListPane->UnregisterEventHandler();`

The final dispatch is tail-jumped in machine code, but source should be an ordinary final statement in a `void` helper. The decompiler's `int` return is an ABI artifact from the tail jump, not a meaningful source return.

Rejected alternatives:

- Keep no-code marker: rejected for UID00021O because the only named blocker is now resolved and the helper has direct call sites.
- Use generic `Refresh()` / `Clear()` names for the child slots: rejected as less precise than the inherited pane cleanup names supported by current docs.
- Treat this like raw show helpers [UID:00021P/Q/R]: rejected because those starts lack function objects/routes and use additional unresolved selected-child setup slots.
- Move owner to child pane classes: rejected because this helper is a `ClanStatusPane` fan-out over three owned child fields.
- No-owner/non-emitting: rejected because owner/emitter route is already strong and valid.

## Evidence Standards Used

Evidence is strong enough for first-draft C++ because the target is a modeled function with exact direct callers, a short single-basic-block body, no direct callees, stable child field names, stable vtable cell targets, and existing project documentation for both inherited slot meanings. Confidence is capped below final audit because the exact original spelling `RefreshChildPanes` is inferred/descriptive rather than recovered from symbols.

## Evidence Checked

### IDA MCP Evidence

- `idb_list`: active session `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `14860`, active true.
- `server_health(database=supervisor_resume_20260629)`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready true, Hex-Rays ready true, strings cache ready true.
- `lookup_funcs`: `0x00487370` is `sub_487370`, size `0x46`; `0x004873b5` resolves inside it; `0x004873b6` and `0x004873c0` are not functions.
- `analyze_function(0x00487370)`: one basic block, callers `sub_4842B0` and `sub_484CD0`, no direct callees, xrefs to `0x004848d6` and `0x00484d79`.
- `disasm(0x00487370)`: confirms child order `+0x2514`, `+0x2510`, `+0x2518`; calls `[eax+0x38]` then `[eax+0x40]`; final `[eax+0x40]` is tail-jumped at `0x004873b3`.
- `xrefs_to`: exactly two code xrefs to `0x00487370`; no xrefs to `0x004873b5`, `0x004873b6`, or `0x004873c0`.
- `callees(0x00487370)`: empty, matching all-indirect virtual dispatch.
- `entity_query 0x00487300-0x00487620`: only modeled functions in the band are `sub_487370` at `0x00487370` and `sub_487600` at `0x00487600`; only local names are `def_4872EF` and `jpt_4872EF`.
- `get_bytes(0x00487336, 0x8a)`: confirms the switch table before the helper, target bytes, and ten `0xcc` bytes at `0x004873b6-0x004873c0`.
- `get_bytes` for child primary vtables `0x006155f8`, `0x00615770`, and `0x00615834`: slot `+0x38` is `0x0055ef10`; slot `+0x40` is `0x00544d70` for `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane`.
- `lookup_funcs`: `0x0055ef10` is `sub_55EF10`, size `0x33`; `0x00544d70` is `sub_544D70`, size `0x3e`; `0x00544ce0` is `sub_544CE0`, size `0x4a`.
- `analyze_function(0x0055ef10)`: scrollable/text/list detach override checks child bytes at `+0x10c/+0x10d`, recursively calls child slot `+0x38`, then calls `0x00544ce0`.
- `analyze_function(0x00544d70)`: inherited dispatcher/event cleanup helper with broad vtable refs and direct code callers.
- `xrefs_to` for vtable bases: `0x006155f8` has constructor/raw stores at `0x004840fa` and `0x004885e2`; `0x00615770` has live constructor store at `0x0048416f`; `0x00615834` has live constructor store at `0x004841d5`.

### Documentation And Reports Checked

- Target: `by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md`.
- Owner/source route: `by-class/ClanStatusPane.md`, `by-file/Clan.md`.
- Constructor and child fields: `by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md`; `by-class/ClanInfoListPane.md`; `by-class/ClanJoinListPane.md`; `by-class/ClanEnlistListPane.md`; `by-class/ClanStringListPane.md`.
- Sibling/support pages: `by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md`; `by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md`; `by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md`; `by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md`; `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md`; `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`; `by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md`.
- Pane slot support: `by-file/Pane.md`; `by-file/PaneChildRegistry.md`; `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`; `by-memory/0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane.md`; `by-class/ChattingVarietySelectPane.md`.
- Existing B reports searched with terms: `00021O`, `00487370`, `004873b5`, `ClanStatusPaneRefreshChildPanes`, `RefreshChildPanes`, `ClanStatusPane`, `ClanStringListPane`, `child vtable`, `+0x38`, `+0x40`, `0055ef10`, `544D70`.
- Relevant opened reports: B015 `00002K-ClanStatusPane-class-source-quality.md`; B002 `00010C-00010G-clan-status-pane-ui-source-quality.md`; B001 `00021Q-ClanStatusPaneShowJoinList-empty-emitter-source-quality.md`.

Failed or intentionally skipped checks: no validator was run because this is report-only and no by-* files were edited. No `execute_report` or lifecycle command was run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID00021O is a modeled `ClanStatusPane` helper at `0x00487370-0x004873b5`, size `0x46`, with exactly two direct callers. | High | MCP `lookup_funcs`, `analyze_function`, `xrefs_to`, `disasm`. | Target Covered Range and IDA MCP Evidence. | incorporate | applied: target records modeled size, caller/xref set, and current MCP session evidence. |
| C2 | Child dispatch order is `m_joinListPane`, `m_infoListPane`, `m_enlistListPane`, each slot `+0x38` then `+0x40`; final `+0x40` is a tail jump. | High | MCP disassembly/decompile. | Target Behavior, Touched State, C++ block; class method row. | incorporate | applied: target behavior and formal C++ preserve the exact child order; class row mirrors it. |
| C3 | Child primary slot `+0x38` resolves to inherited `0x0055ef10` for all three child classes. | High | MCP vtable byte reads; `ClanPaneListVtableData`; child class docs. | Target Touched State / IDA MCP Evidence; class support; vtable support note. | incorporate | applied: target, class, and vtable support page all record `+0x38 -> 0x0055ef10` / `RemoveFromLayer()`. |
| C4 | Child primary slot `+0x40` resolves to inherited `0x00544d70` for all three child classes. | High | MCP vtable byte reads; `Pane.md`; `PaneChildRegistry`; destructor docs. | Target Touched State / IDA MCP Evidence; class support; vtable support note. | incorporate | applied: target, class, and vtable support page all record `+0x40 -> 0x00544d70` / `UnregisterEventHandler()`. |
| C5 | Source-facing first-draft calls should be `RemoveFromLayer()` followed by `UnregisterEventHandler()` on each child pane. | Medium-high | Slot targets plus current Pane support docs. | Target formal C++ and Reconstruction Notes; generated `social/Clan.cpp`. | incorporate | applied: formal target C++ contains the exact six calls; generated Clan.cpp includes the method after validator refresh. |
| C6 | The old blank-C++ blocker for `+0x38/+0x40` is resolved for UID00021O. | High | C3-C5 and direct caller evidence. | Target Reconstruction Notes / Score Rationale / class support. | incorporate | applied: target no-code comment replaced; class support now says UID00021O is first-draft ready. |
| C7 | Raw show-helper siblings [UID:00021P/Q/R] should not be used as no-code precedent for this modeled helper because they lack direct routes and use additional selected-child slots `+0x30/+0x3c`. | High | Sibling pages; B001 00021Q report; MCP nearby function/name inventory. | Target Negative Evidence / class support. | incorporate | applied: target Negative Evidence Summary and class reachability/C++ decision preserve the sibling distinction. |
| C8 | Recommended target score should rise from `85/88` to `89/91`. | Medium-high | Resolved C++ blocker, direct vtable-slot targets, first-draft code readiness. | Target header / Score Rationale. | incorporate | applied: target header now `COMPLETION:89`, `CONFIDENCE:91`; final target validator command `000000004547` passed. |
| C9 | Owner/emitter stay `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`. | High | Target/class/file docs and MCP caller/field evidence. | Target metadata. | already-present | already-present: metadata was preserved unchanged in the target and passed final validator command `000000004547`. |
| C10 | Negative evidence supports first-draft C++ rather than no-code/no-owner/split: no split/range defect, no no-owner route, no child-pane ownership, no generic slot naming, and only original spelling uncertainty remains. | High | MCP boundary/caller/vtable evidence, sibling raw-helper docs, child class docs, rejected alternatives in this report. | Target Negative Evidence / Score Rationale / class support. | incorporate | applied: target Negative Evidence Summary includes all rejected routes and score-cap uncertainty; class support preserves raw-helper/child-owner/generic-slot exclusions. |

## Positive Evidence Summary

- Modeled IDA function with direct call sites from two documented `ClanStatusPane` paths.
- Body is simple, bounded, and entirely over constructor-owned child fields.
- Vtable bytes prove all three children share the same inherited `+0x38/+0x40` targets.
- Existing Pane and destructor documentation already assigns source-facing meanings to these inherited cleanup paths.
- No split, owner change, or raw/no-route marker is needed for this exact target.

## Negative Evidence Summary

Checks performed and rejected for UID00021O:

- No split/range issue: MCP confirms `0x00487370` is a real modeled function of size `0x46`; `0x004873b5` resolves inside it; `0x004873b6` is not a function; and `0x004873b6-0x004873c0` is `0xcc` alignment before the raw show-helper band. The predecessor `0x00487338-0x00487370` is the row-eligibility switch table, not part of this helper. No child page, merge, boundary correction, or padding reclassification is recommended.
- No no-owner/non-emitting route: the body is called directly by two `ClanStatusPane` paths, reads only constructor-owned `ClanStatusPane` child fields, and already has valid `CANONICAL_OWNER:00002K` / `EMITTER_UIDS:00002K`. Clearing ownership or emission would be an avoidance tactic, not an evidence-backed classification.
- Raw show-helper no-code precedent does not apply: [UID:00021P/Q/R] are raw no-route siblings with no function objects or inbound start routes and with additional selected-child setup slots `+0x30/+0x3c`. UID00021O is different: it is modeled, directly called, and only uses the now-resolved child cleanup slots `+0x38/+0x40`. The sibling no-code rationale should be preserved for those siblings but not copied to this target.
- Child-pane ownership is rejected: `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` provide the virtual methods being invoked, but none owns the six-call fan-out sequence. The source shape is a parent `ClanStatusPane` helper operating over three member fields, not three separate child methods or a child-class helper.
- Generic child-slot names are rejected: names such as `Refresh`, `Clear`, `Detach`, `Update`, or raw `slot38/slot40` are weaker than the current evidence. Vtable bytes resolve slot `+0x38` to `0x0055ef10`, documented in Pane/ScrollablePane contexts as `RemoveFromLayer()`-style detach behavior, and slot `+0x40` to `0x00544d70`, documented as inherited event-handler unregister / dispatcher cleanup. The first-draft C++ should therefore use `RemoveFromLayer()` and `UnregisterEventHandler()` rather than invented Clan-specific names.
- Remaining uncertainty: exact original spelling for `ClanStatusPane::RefreshChildPanes` is inferred/descriptive, and exact final Pane API spellings are source-facing project names rather than recovered original symbols. This caps the recommendation at `89/91`, but it does not block first-draft C++ because behavior, ownership, route, field names, and child virtual targets are now documented.

This negative evidence aligns with the first-draft C++ recommendation: the rejected paths explain why the implementation should be a direct `ClanStatusPane::RefreshChildPanes()` body, not a split, no-code marker, no-owner/non-emitter downgrade, child-owned body, or generic-slot pseudocode.

## IDA MCP Facts

- Function/range facts: `sub_487370`, size `0x46`, one basic block, no direct callees, successor `0x004873b6` non-function with `0xcc` padding to `0x004873c0`.
- Data/table facts: `0x00487336-0x00487370` is switch-table data before the helper; child vtable bases are `0x006155f8`, `0x00615770`, and `0x00615834`.
- Xref facts: callers at `0x004848d6` and `0x00484d79`; no inbound xrefs to tail/end/successor.
- Vtable/type facts: primary slot `+0x38` cells `0x00615630`, `0x006157a8`, and `0x0061586c` contain `0x0055ef10`; primary slot `+0x40` cells `0x00615638`, `0x006157b0`, and `0x00615874` contain `0x00544d70`.
- Negative facts: no direct callees because all work is indirect virtual dispatch; no additional modeled function/name between `0x00487370` and `0x00487600`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00487338-0x00487370` | [UID:0000VN] `-ignored` | row-eligibility switch table | FALSE | n/a | n/a | Already ignored |
| `0x00487370-0x004873b5` | [UID:00021O] target | modeled child-pane cleanup fan-out | TRUE | `00002K` | recommend `89/91` | First-draft C++ ready |
| `0x004873b6-0x004873c0` | [UID:0000VN] `-ignored` | alignment | FALSE | n/a | n/a | Already ignored |
| `0x004873c0-0x00487475` | [UID:00021P] sibling | raw info-list view helper | TRUE | `00002K` | `85/88` | No-code blocker remains because no route and `+0x30/+0x3c` unresolved |
| `0x00487480-0x00487535` | [UID:00021Q] sibling | raw join-list view helper | TRUE | `00002K` | `87/90` | Formal no-code marker already accepted |
| `0x00487540-0x004875f5` | [UID:00021R] sibling | raw enlist-list view helper | TRUE | `00002K` | `85/88` | No-code blocker remains because no route and `+0x30/+0x3c` unresolved |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004848d6` | caller inside [UID:00010B] parser | Parser refreshes children before committing parsed status fields. |
| `0x00484d79` | caller inside [UID:00010C] `OnKeyInput` | Escape/key path refreshes/detaches child panes before invalidation/reset flow. |
| `0x0055ef10` | vtable slot `+0x38` for all three children | Inherited scrollable/text/list pane `RemoveFromLayer()`-style detach override. |
| `0x00544d70` | vtable slot `+0x40` for all three children | Inherited `Pane::UnregisterEventHandler()` / event-handler cleanup. |

## Documentation Evidence And IDA Status

Existing target/class docs already have correct owner, emitter, child field names, direct callers, and behavior order. The stale part is the final-C++ blocker. B015 correctly documented the blocker at the time, but current slot-target evidence plus existing Pane support docs now closes it for UID00021O. B001's UID00021Q no-code report remains correct for UID00021Q because that raw target still lacks a route and uses selected-child setup slots `+0x30/+0x3c`.

## Ranked Ownership Analysis

### 1. [UID:00002K] ClanStatusPane

- Evidence for: target is called by two `ClanStatusPane` paths and touches only the three `ClanStatusPane` child fields.
- Evidence against: exact original method spelling is not recovered.
- Decision: keep direct owner and emitter.

### 2. [UID:0000I8] Clan / `social/Clan.cpp`

- Evidence for: class source route, clan status/list/dialog source cluster, existing valid file route.
- Evidence against: too broad for direct semantic ownership.
- Decision: keep as source-file route through `ClanStatusPane`.

### 3. Child pane classes

- Evidence for: target dispatches child virtual methods.
- Evidence against: target body is a parent fan-out helper and no child owns the whole sequence.
- Decision: reject as direct owner; child classes provide virtual dependencies only.

### 4. No-owner / non-emitting / no-code marker

- Evidence for: previous child slot names were unresolved.
- Evidence against: current slot targets and source meanings are resolved enough for first-draft C++; target has direct callers.
- Decision: reject for UID00021O.

## Source Placement

Recommended placement remains `NexusTK/social/Clan.cpp` through [UID:0000I8] `Clan`, with direct class ownership on [UID:00002K] `ClanStatusPane`. Do not create a new file, do not move to `ClanDialogs.cpp` or `ClanBank.cpp`, and do not split this exact page.

## Range / Split / Padding / Reclassification Analysis

No split or range repair is needed. The target page already covers the exact modeled function. The predecessor switch table and successor alignment are already documented by [UID:0000VN] `by-memory/-ignored.md`.

## IDA Rename / Type / Comment Recommendations

No IDA DB edit is required during this report-only phase. If a later IDA naming pass is authorized, these source-facing labels are defensible:

- `sub_487370` -> `ClanStatusPane::RefreshChildPanes` or equivalent local method name.
- `sub_55EF10` role comment: inherited scrollable/text/list pane `RemoveFromLayer()` override.
- `sub_544D70` role comment: inherited `Pane::UnregisterEventHandler()` / event cleanup.

Do not rename raw show-helper starts as functions unless IDA modeling and route policy are separately handled.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended formal insertion text for [UID:00021O]:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ClanStatusPane::RefreshChildPanes()
{
    m_joinListPane->RemoveFromLayer();
    m_joinListPane->UnregisterEventHandler();

    m_infoListPane->RemoveFromLayer();
    m_infoListPane->UnregisterEventHandler();

    m_enlistListPane->RemoveFromLayer();
    m_enlistListPane->UnregisterEventHandler();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves original behavior: it emits the exact six virtual dispatches in the observed order over the three child fields. The final tail jump is represented as the final source statement in a `void` helper.

Reason it matches plausible original source shape: a parent `ClanStatusPane` helper that detaches/unregisters all owned child panes is a simple human-written method and avoids decompiler pointer-table syntax.

Inferred names used: `RefreshChildPanes`, `m_joinListPane`, `m_infoListPane`, `m_enlistListPane`, `RemoveFromLayer`, and `UnregisterEventHandler`. Field names are already accepted in current docs; inherited pane method names are supported by current Pane/cleanup docs.

No third-party import applies.

## Recommended Target Doc Changes

Target path: `by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md`.

- Change `COMPLETION:85` to `COMPLETION:89`.
- Change `CONFIDENCE:88` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00002K`.
- Replace the no-code comment in the formal C++ block with the first-draft code above.
- Update Status/Rebuild handling to say first-draft C++ is ready because child virtual slots `+0x38/+0x40` resolve to inherited pane cleanup methods.
- Update Touched State: `+0x38` = inherited `RemoveFromLayer()`/scrollable detach path; `+0x40` = inherited `UnregisterEventHandler()` / event cleanup.
- Add current MCP evidence for session `supervisor_resume_20260629`, vtable bytes, slot targets, and direct caller/xref reconfirmation.
- Preserve the distinction that raw show-helper siblings still have no-route and `+0x30/+0x3c` blockers.

## Recommended Support Doc Changes

Support path: `by-class/ClanStatusPane.md`.

- Update the `RefreshChildPanes` method row to state that [UID:00021O] now has first-draft C++ and that `+0x38/+0x40` resolve to inherited pane cleanup calls.
- In the class C++ decision / heuristic table, replace the blanket "`00021O/P/Q/R` keep C++ blank for child vslot names" wording. New meaning: [UID:00021O] is first-draft ready; raw [UID:00021P/Q/R] remain no-code/blank because they lack direct routes and still require selected-child `+0x30/+0x3c` naming.

Support path: `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`.

- Add a slot note that `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` primary slots `+0x38/+0x40` are `0x0055ef10` / `0x00544d70`, supporting UID00021O's first-draft cleanup fan-out.

Generated files:

- Do not manually edit generated files. After accepted implementation and scoped validation, generated `auto-generated/NexusTK/social/Clan.cpp` should include UID00021O's method body under the `ClanStatusPane` route.

## Score And Metadata Recommendation

Current score/metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00002K`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00002K`
- blank formal C++ with no-code comment

Recommended score/metadata:

- `COMPLETION:89`
- `CONFIDENCE:91`
- owner/reconstructable/emitter unchanged
- formal first-draft C++ populated

Score rationale: completion rises because the named C++ blocker is resolved with current vtable-target evidence and existing Pane source-name support. Confidence rises because the target is modeled, small, directly called, and all six virtual dispatches now have source-facing names. Scores stay below final audit because exact original method spelling and final Pane API spellings are inferred from project evidence rather than recovered symbols, and sibling raw show helpers still have separate unresolved slots.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / impact |
| --- | --- | --- |
| Are `+0x38/+0x40` still unknown for UID00021O? | MCP vtable bytes, `Pane.md`, `ScrollablePaneCore`, `PaneChildRegistry`, destructor docs. | No. They resolve to inherited pane cleanup calls sufficient for first-draft C++. |
| Is `RefreshChildPanes` directly reachable? | MCP `xrefs_to`, `analyze_function`, caller docs. | Yes. Parser and key-input paths call it directly. |
| Should a no-code marker be used like UID00021Q? | B001 UID00021Q report, sibling pages, nearby function inventory. | No. UID00021Q is raw/no-route and uses additional selected-child slots; UID00021O is modeled and directly called. |
| Is a split needed? | Function boundary, surrounding bytes, ignored ledger. | No. Exact target range is already isolated. |
| Are any owner/emitter changes needed? | Target/class/file docs and current MCP evidence. | No. Existing owner/emitter are correct. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker edit is required from B005. If the supervisor chooses to refresh a manual `by-memory/-coverage-report.md` row after accepting implementation, use this replacement summary concept:

```text
    - [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md) 0x00487370-0x004873b5 | method | ClanStatusPane::RefreshChildPanes : reconstructable : 89% : very strong : Current B005 MCP reanalysis confirms modeled `0x46`-byte helper with exactly two direct callers, no direct callees because all work is indirect virtual dispatch, child order `m_joinListPane`/`m_infoListPane`/`m_enlistListPane`, primary child slots `+0x38/+0x40` resolved via vtable bytes to inherited `RemoveFromLayer()` and `UnregisterEventHandler()` cleanup paths, exact padding before the raw show-helper siblings, owner/emitter [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), and first-draft C++ readiness through `social/Clan.cpp`.
```

Do not edit validator-owned `auto-generated/-ag-*` reports manually.

## Validator Results

Implementation callback scoped validators run from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md --apply --wait-generated --queue-timeout 240`
  - Final target revalidation exit code: `0`; `command_id: 000000004547`; `command_timestamp: 2026-07-02T14:16:35-04:00`; `ok: 1`.
  - Relevant effects: generated refresh `completed`, `generated_refresh_command_id: 000000004547`, `generated_refresh_timestamp: 2026-07-02T14:16:35-04:00`; generated `auto-generated/NexusTK/social/Clan.cpp` header shows `validator-command-id: 000000004547` and `validator-refreshed-at: 2026-07-02T14:16:35-04:00`.
  - Earlier target validator command `000000004540` at `2026-07-02T14:13:46-04:00` also passed with `ok: 1` and applied `completion_update 00021O 89`, `confidence_update 00021O 91`, and `autogen_cpp_update 0000I8`; it was superseded only because B005 historicalized one target change-note sentence afterward and reran the final target validator.
- `python .\tools\validator.py --mode file --file by-class/ClanStatusPane.md --apply --queue-timeout 240`
  - Exit code: `0`; `command_id: 000000004541`; `command_timestamp: 2026-07-02T14:14:02-04:00`; `ok: 1`.
  - Warnings/effects: existing `missing_ref_uid` warnings for `0003B8`, `000411`, `000412`, and `000413`; `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md --apply --queue-timeout 240`
  - Exit code: `0`; `command_id: 000000004542`; `command_timestamp: 2026-07-02T14:14:07-04:00`; `ok: 1`.
  - Relevant effects: `reference_index_add 00021O` for the vtable support page; `generated_refresh: deferred`.

Generated-refresh state: final target validation used `--wait-generated` and completed. Generated `auto-generated/NexusTK/social/Clan.cpp` was inspected read-only afterward; it contains `void ClanStatusPane::RefreshChildPanes()` with the six accepted `RemoveFromLayer()` / `UnregisterEventHandler()` calls, and its generated header equals final target command `000000004547`.

## Changed Files

- Modified: `by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md`.
- Modified: `by-class/ClanStatusPane.md`.
- Modified: `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`.
- Modified: `tools/leaser/Agents/Agent-B005/research/00021O-ClanStatusPaneRefreshChildPanes-source-quality.md` for callback ledger/checklist proof.
- Validator-owned generated side effects reported above were produced by scoped validators; B005 did not manually edit generated files.
- Report execution: not run. B005 did not run `tools/validator.py execute_report`, any dry-run/status/probing variant, registry lifecycle command, manual report move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation; supervisor accepted this report for implementation callback on 2026-07-02.
- [x] Target/support docs to update:
  - [x] `by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md`: score updated to `89/91`, no-code comment replaced with formal first-draft C++, current MCP/vtable-slot evidence, touched-state, negative evidence, and score rationale added; owner/emitter preserved.
  - [x] `by-class/ClanStatusPane.md`: method row, child-slot table, reachability heuristic row, and class C++ decision updated so UID00021O is first-draft ready while raw [UID:00021P/Q/R] remain separate no-code/blank cases for route and `+0x30/+0x3c` reasons.
  - [x] `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`: support note added for child primary slots `+0x38/+0x40` resolving to `0x0055ef10` / `0x00544d70`.
- [x] Current target state and actual evidence checked recorded; applied into target evidence and preserved in this report.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: `00021O` `85/88 -> 89/91`; owner/emitter unchanged.
- [x] Score-limiting blockers researched to resolution: `+0x38/+0x40` names resolved for UID00021O; sibling raw-helper blockers explicitly separated in target and class support.
- [x] Owner/emitter/reconstructable changes: none; target still has `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`.
- [x] Split/rename/new-child changes: none; target Negative Evidence Summary records no split/range defect.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes confirmed not applicable; no IDA DB edits were made.
- [x] First-draft C++ applied: exact `ClanStatusPane::RefreshChildPanes()` body inserted into the target formal block.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: callers, child order, vtable cells, inherited pane cleanup names, no direct callees, sibling distinction.
- [x] Negative Evidence Summary incorporated/preserved: no split/range defect, no no-owner/non-emitting route, raw show-helper no-code precedent rejected for UID00021O, child-pane ownership rejected, generic child-slot names rejected, and remaining original-spelling uncertainty recorded as score cap rather than C++ blocker.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old unresolved-slot blocker superseded for UID00021O; no-code marker rejected for this target; raw show-helper no-code rationale remains valid for [UID:00021P/Q/R].
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: none used as proof.
- [x] Open questions closed or documented: original method spelling remains inferred; exact final Pane API spelling remains project-evidence source-facing but not original-symbol proof.
- [x] Validators run after accepted implementation:
  - [x] `python .\tools\validator.py --mode file --file by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md --apply --wait-generated --queue-timeout 240` -> final exit `0`, command `000000004547`, `ok: 1` after historicalizing the stale B015 change-note sentence.
  - [x] `python .\tools\validator.py --mode file --file by-class/ClanStatusPane.md --apply --queue-timeout 240` -> exit `0`, command `000000004541`, `ok: 1`.
  - [x] `python .\tools\validator.py --mode file --file by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md --apply --queue-timeout 240` -> exit `0`, command `000000004542`, `ok: 1`.
- [x] Generated report refresh expected: target validator used `--wait-generated` and completed; generated `auto-generated/NexusTK/social/Clan.cpp` includes UID00021O's method body and was not manually edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; manual supervisor-owned coverage/tracker text confirmed unchanged/not edited by B005.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004553","destination_path":"executed-b-agent-research/B005/00021O-ClanStatusPaneRefreshChildPanes-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00021O-ClanStatusPaneRefreshChildPanes-source-quality.md","timestamp":"2026-07-02T14:20:48-04:00","uid":"00021O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
