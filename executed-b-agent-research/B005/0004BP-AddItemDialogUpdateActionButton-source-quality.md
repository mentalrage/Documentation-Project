** TARGET-REPORT-UID:0004BP **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004BP AddItemDialogUpdateActionButton Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented disposition: [UID:0004BP] is the exact source-authored virtual `AddItemDialog::UpdateActionButton()` method at `[0x004aea40,0x004aea7d)`, owned/emitted by [UID:000007] through [UID:0000KE] `NexusTK/ui/dialogs/ItemDialogs.cpp`.
- The completed body uses the exact two inherited child lookups, unwraps selector `3`'s ScrollableControlPane, calls validator-issued UID0004M9 `ListPane::GetSelectionCount()`, and dispatches separate `Enable()` / `Disable()` virtual calls without null tests.
- Callback result: target `92/94`, source position `40`, unchanged true/owner/emitter/range/`Nested:0`; UID0004M9 was allocated serially; all nine literal blocks, C01-C33, and accepted support corrections were applied and scoped-validated.
- Confidence: very strong for range, behavior, dispatch, types, owner, source route, and source order; strong for stripped lexical spellings.

## Supporting Research

### Mandatory MCP recovery and evidence pass

- The supervisor's 2026-07-13 incident check established that the earlier timeout was a transient busy state rather than MCP downtime. A direct bounded `idb_list` probe succeeded at `2026-07-13T12:06:16-04:00` with database `supervisor_nexustk_20260713`, one adopted worker, PID `2236`, and `is_analyzing:false`.
- B005 then started a fresh MCP protocol client session, `ececb1ac-b18a-4202-8e84-4954ae5608bd`, and repeated the required evidence pass against `supervisor_nexustk_20260713` rather than relying on the earlier interrupted attempt.
- Evidence-time `server_health` returned `status:ok`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with 2,067 strings. The IDB path was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; the input image was `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- All bounded target, helper, byte, caller, callee, xref, vtable, and global-value calls used for this report completed. No fallback-only conclusion was used and no MCP process was started, stopped, restarted, or otherwise managed by B005.

### Prior-report search provenance

Exact search terms were re-run after supervisor execution command `000000009874`: `0004BP`, `UID:0004BP`, `TARGET-REPORT-UID:0004BP`, `0x004aea40`, `004aea40`, `AddItemDialogUpdateActionButton`, `AddItemDialog::UpdateActionButton`, and `sub_4AEA40`. Discovery expansion terms were `AddItemDialog`, `UpdateActionButton`, `ItemDialogs`, `000007`, `0000KE`, `00033Q`, `GetSelectionCount`, `0x004f3e20`, `ImageButtonControlPane`, and `ScrollableControlPane`; broad family-only hits were used as leads, not treated as direct target reports.

Search roots checked:

- central executed reports: `source-3/project-documentation/executed-b-agent-research/`;
- active reports: every `source-3/project-documentation/tools/leaser/Agents/Agent-B*/research/` directory;
- current legacy report roots: `tools/leaser/Agents/Older-Research/` and `tools/leaser/Agents/SpecialReports/`;
- archived report roots: `archived/b-agent-reports-20260623/` and `archived/duplicate-loose-b-agent-reports/`.

Every report matching the exact UID/address/source-facing-name search was opened and classified:

| Report path | Match | Classification and useful fact |
| --- | --- | --- |
| `executed-b-agent-research/B001/0004BN-AddItemDialogDestructor-source-quality.md` | UID0004BP and source order | Incidental archived executed sibling report. Supervisor execution command `000000009874` moved the accepted artifact from its former B001 working path to this central path. It establishes destructor position `20`, preserves UID0004BP body, and supplies the constructor/destructor/method ordering constraint. Its current UID0004BN by-memory result is a verify-only dependency, not a target audit or callback edit destination. |
| `executed-b-agent-research/B001/00014T-ItemExchangeMixDialogs.md` | `0x004aea40` in modeled function inventory | Incidental broad family report. It confirms the function start and neighborhood only. |
| `executed-b-agent-research/B007/0000KE-ItemDialogs-empty-emitter-family-source-quality.md` | exact path, UID, range, initial score, and method name | Direct split-creation support, but not a complete method audit. It created UID0004BP at `86/90`; its shallow body and unresolved helper names are superseded by this target-specific pass. |
| `executed-b-agent-research/B001/0004BM-AddItemDialogConstructor-source-quality.md` | UID0004BP/address and constructor relation | Incidental sibling report. Its claim that there is no direct constructor call to `0x004aea40` remains true. Its broader wording that constructor-time update does not occur is superseded: constructor `OnCreate` synchronously calls the generic virtual refresh wrapper, which reaches UID0004BP through slot `+0x4c`. |
| `executed-b-agent-research/B006/0002MH-AddEmployeeItemDialogVtableData-empty-emitter-source-quality.md` | primary slot `0x00619120 -> 0x004aea40` | Incidental derived-vtable support. It proves AddEmployee inherits UID0004BP and does not provide the method body audit. |
| `tools/leaser/Agents/Agent-B003/research/0004BQ-AddItemWithCountDialogConstructor-source-quality.md` | UID0004BP and `0x004aea40` sibling-control references | Incidental active sibling report. It treats this B005 artifact as independently owned shared control-contract evidence and does not audit or own UID0004BP. |

The active-root search also returned this assigned B005 report itself; it was excluded from prior-report classification because it is the artifact being repaired. The former `tools/leaser/Agents/Agent-B001/research/0004BN-AddItemDialogDestructor-source-quality.md` path no longer exists, while the executed path above and the current `by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md` page both exist. No exact UID/address/name match was found in Older-Research, SpecialReports, or either archived root. Evidence-based conclusion: no prior dedicated UID0004BP report exists. B007's family report created the child, while all other exact matches are incidental sibling, aggregate, or vtable support.

## Target

- Target UID: `0004BP`.
- Target path: `by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md`.
- Historical assignment row: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`, score `86/90`, report count zero at assignment time; tracker lifecycle state is supervisor/validator-owned and is not frozen by this artifact.
- Callback classification: implementation complete and independently reviewable; no report execution or lifecycle action was performed by B005.
- Current scores and parent state: `92/94`, owner/emitter `000007`, `RECONSTRUCTABLE:TRUE`, source position `40`, relative `Nested:0`, exact child of [UID:00033Q].

## Current Target State

- Metadata now preserves UID, exact range, AddItemDialog owner/emitter, reconstructable state, and relative `Nested:0` while applying `92/94` and position `40`.
- Destination 1 replaced the historical decompiler-shaped `GetDialogButtonBySelector` / direct-list / `HasSelection` / `SetEnabled` placeholder with the exact accepted API surface.
- The current body retrieves selector `3` as ScrollableControlPane, uses `GetScrollablePane()`, obtains the integer UID0004M9 selection count, and selects two distinct virtual tails without null tests.
- Target prose now contains the complete instruction/CFG/ABI, insertion-order, wrapper/owned-child, helper, field, indirect-refresh, vtable, padding, clone, negative, and rejected-history evidence from this report.
- Waited validator command `000000009960` refreshed generated ItemDialogs.cpp. Read-only inspection confirms UID000007/UID0004BM/UID0004BN/UID0004BO/UID0004BP source order and the exact current target body; the pre-callback SHA/body remains preserved as historical report-only evidence above.
- Related target/support docs checked: UID00033Q, UID0004BM, the archived executed UID0004BN report and current UID0004BN by-memory page as verify-only dependencies, UID0004BO, UID000317, UID000007, UID0000KE, UID0003ID, UID0001XV, AddEmployee/AddMixing/AddItemWithCount classes and vtables, UID00003T DialogPane, UID0000CE ScrollableControlPane and file, UID00006D ImageButtonControlPane and ButtonControlPane file, UID000038 ControlPane and file, UID0002PB, UID0002PD, UID0003N3, UID0003N4, UID0003N8, UID0003N9, UID000194/UID0003U0/UID0004LX/UID0003U1, UID00007A ListPane and file, and UID00008W MyItemListPane.
- UID0004BN dependency state after command `000000009874`: its archived executed report and current `92/94`, position-20 by-memory page remained read-only verify-only dependencies and were not edited.
- Current artifact/lifecycle status: B005 completed the authorized callback, scoped-validated every changed by-* page, released every lease, and ran only the authorized waited generated refresh. Report execution, lifecycle, move, archive, and manual generated/coverage/tracker/supervisor edits remain unperformed.

## Executive Recommendation

- Direct AddItemDialog ownership, one-method target range, source route, and no-split disposition are applied and verified.
- Exact helper UID0004M9 now owns `[0x004f3e20,0x004f3e74)` under ListPane; the former SelectionState emission is historical alias pollution.
- Current target-triggered ControlPane, ScrollableControlPane, ButtonControlPane, and ImageButton support uses enabled-state semantics, with Pane visibility separately documented at `+0xb4` and old visible/show/hover claims superseded.
- No accepted callback blocker remains. Original lexical names remain inferred rather than PDB-proven and continue to cap confidence without invalidating the implemented source.

## Supervisor Active Recheck

- Historical Gate 1 basis: the supervisor accepted exact report SHA `70A9C8DAB7E4FB8FBCC83ADE153BD8991C1C4B8362AEE61C14BFC429A1DC291D` and separately authorized this implementation callback.
- Evidence was collected during the healthy `supervisor_nexustk_20260713` session after the transient busy state; this artifact does not assert that evidence-time session remains alive.
- UID0004BP stayed unsplit. The independently addressable ListPane callee was serially registered as UID0004M9 before any cross-reference was inserted.
- All source-bearing items have their accepted literal block or prose-only disposition applied. No helper name, selector type, slot, source order, refresh route, first-draft body, or accepted callback item is deferred.

## Inference Research Guidance Check

- `by-structure.md` and the project skill require exact address children for understood methods, owner assignment from behavior/callers/vtables rather than adjacency, compiler/source separation, and formal managed blocks for every proposed C++ edit. Those rules drive the retained target range, the separate ListPane helper child, and the refusal to emit raw vtables or padding.
- Existing names and types were treated as hypotheses. `ButtonPane`, direct selector-to-ListPane lookup, `HasSelection`, `SetEnabled`, ImageButton hover methods, `m_controlVisible`, and the claim of no constructor-time refresh were all rechecked rather than copied forward.
- Direct IDA facts are stated as addresses, bytes, instructions, xrefs, vtable cells, and function boundaries. Documentation facts are cited as current accepted class/file/formal surfaces. Inferred source spellings are labeled as inferred but selected when they are the strongest coherent source form.
- Wave2/Wave3 and `simroot_v2` aliases were encountered in current support docs. They were used only as stale search context. `SelectionState`, `ButtonPane`, hover labels, and decompiler helper names were rejected where current binary and accepted class contracts disagree.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Resolution |
| --- | --- | --- |
| Target method name | Current target/class, AddItemWithCount override family, and AddItem vtable slot all use the same conceptual updater. No stronger stripped-symbol spelling exists. | Retain inferred `AddItemDialog::UpdateActionButton()` and declare it virtual. |
| Selector helper direction | Both selector operations load `this+0x1fc`, call manager virtual slot `+0x10`, then dereference the returned entry. DialogPane's accepted `GetChild<T>(int)` wraps `GetChildControl`. | Reject free helpers; use inherited `GetChild<T>`. |
| Selector values | UID0004BM adds background, action button, cancel button, and scroll wrapper in that exact order. | Values `1` and `3` are zero-based insertion indices, not resource ids or category values. |
| Selector 1 type | Constructor index 1 is `ImageButtonControlPane(36, ...)`; target stores that exact control and dispatches its overridden slots. | Local `actionButton` is best typed `ImageButtonControlPane *`. |
| Selector 3 type | Constructor index 3 is a `ScrollableControlPane` whose `+0x108` member owns the MyItemListPane. Target performs the same extra load before the ListPane call. | Local `itemListControl` is `ScrollableControlPane *`; unwrap with an inline `GetScrollablePane()` accessor. |
| Underlying list type | Constructor allocates `MyItemListPane`, configures inherited selection mode, and transfers it to the wrapper. The called helper is a generic ListPane method. | Use `ListPane *itemList` after a descriptive downcast; document dynamic MyItemListPane identity without inventing an AddItemDialog field. |
| Selection predicate | `0x004f3e20` returns a count, including values greater than one in multi-select mode. | Canonical descriptive name is `int ListPane::GetSelectionCount() const`; reject boolean `HasSelection`. |
| Button state call | Positive count tail-jumps to primary vtable `+0x4c`; zero/nonpositive tail-jumps to `+0x50`. Base and Scrollable slot inventories, ImageButton override bodies, and UI availability consumers agree. | Use distinct `Enable()` and `Disable()` calls; reject synthetic `SetEnabled(bool)`. |
| `+0x101` field | Base slots set/clear the byte and invalidate. ImageButton overrides use it as a gate, set image state 0 when enabling and 2 when disabling, then apply the base transition. Pane visibility is separately `+0xb4`. | Rename the source-facing field from `m_controlVisible` to `m_enabled` in affected current claims and formal constructor C++. Historical visible/show claims remain explicitly superseded. |
| Null behavior | Target has no compare/branch on either manager result, wrapper, or list pointer. Constructor invariants establish all controls before refresh. | Preserve no-null-check behavior exactly. |
| Refresh timing | No direct constructor call targets UID0004BP. UID0004BM calls `DialogPane::OnCreate` at `0x004ae8b5`; `OnCreate` calls generic refresh wrapper `0x0049fe20`; that wrapper virtual-dispatches slot `+0x4c`. | Historical direct-call negative remains valid, but broad no-constructor-refresh wording is superseded. |
| Derived reachability | AddItem, AddEmployee, and AddMixing primary vtables point slot `+0x4c` to target. AddItemWithCount points the same slot to its own `0x004af480` override. | Document three dynamic owners of this implementation and the one override exclusion. |
| Source order | Constructor is position 10; the archived executed B001 destructor report and current verify-only UID0004BN page fix 20; OnAction is the next logical method; target is fourth. | Set UID0004BO to position 30 and target to position 40. The assignment's "position 4" is a logical ordinal, not the literal validator position value. |
| Helper split nesting | Validator `Nested` is a relative address-sorted delta, never child count. Current generated levels are ListPane 211, UID0003U0 212, UID0004LX 212. | Keep UID0003U0 `Nested:1`; existing/new exact children and following UID0003U1 use `Nested:0`, preserving level 212. |
| Generated pollution | Pre-callback generated ItemDialogs emitted the stale helpers, and ListPane documentation recorded `0x004f3e20` under a synthetic `SelectionState` alias. | Corrected through source docs/validators only; current generated output uses UID0004M9/ListPane ownership and was never edited manually. |
| Source module | All exact class siblings and current file route are ItemDialogs; ListPane/control dependencies already have separate control modules. | Target remains `NexusTK/ui/dialogs/ItemDialogs.cpp`; helper/control declarations remain under their existing modules. |

Rejected alternatives:

- `ButtonPane`, `GetDialogButtonBySelector`, `GetDialogListBySelector`, `HasSelection`, `SetEnabled`, and `m_controlVisible` are rejected as current source-facing names because they conflict with exact instructions or stronger class/vtable consumers.
- `OnMouseEnter` / `OnMouseLeave` for ImageButton `0x00495d10/0x00495d80` are rejected. The functions occupy inherited enable/disable slots and select normal/disabled image states; they do not inspect mouse events.
- Direct ListPane storage in AddItemDialog is rejected. UID0004BM stores no list pointer field, and the target must traverse the wrapper's `+0x108` child.
- Constructor-local explicit call and "refresh only later" are both incomplete. The direct call is absent, while synchronous virtual refresh through `OnCreate` is present.
- A target split, inline-only disposition, compiler-generated classification, standalone free function, or owner transfer to DialogPane/ListPane is rejected by exact function/vtable/class evidence.

## Evidence Standards Used

- Primary evidence: fresh IDA MCP function lookup, decompilation, exact instruction queries, CFG blocks, raw bytes, xrefs, callers/callees, vtable/global dword reads, constructor stores, and unique-signature checks.
- Corroboration: local read-only PE SHA-256 and exact byte scan, current by-memory/class/file/type documentation, current generated C++, and all exact-match historical reports.
- Negative evidence: no ordinary code xref to target, no target-internal function, no null test, no boolean setter call, no AddItemDialog list field, no target byte outside the modeled function, no exact duplicate body, and no source reason to emit vtable/padding/compiler mechanics.
- The evidence ladder is sufficient for high source readiness because behavior, types, control composition, vtable slots, generic refresh route, and helper implementation converge independently. Confidence remains below absolute only because stripped lexical names and exact original header organization are not symbol-proven.

## Evidence Checked

- Fresh IDA MCP checks: `idb_list`, `server_health`, bounded `lookup_funcs` at target/predecessor-end/target-end/successor/helper and control methods, target/helper decompilation, complete target disassembly, helper/control bounded instruction checks, CFG, exact bytes, `xrefs_to`, `callers`, `callees`, vtable/global-value reads, and exact signature/clone comparisons.
- Manual/read-only checks: local PE SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`; unique target byte hit at raw offset `0xADE40`, mapped through `.text` raw `0x400` / VA `0x00401000` to `0x004aea40`; current generated ItemDialogs and control/ListPane outputs; generated by-memory indentation.
- Documentation checks: every current target/support page listed in Current Target State, validator `Nested` semantics, by-memory guidance, source tree/file routes, and the five exact matching reports classified under Supporting Research.
- Negative checks: target endpoint/function-start queries, preceding/following padding, target xrefs, duplicate exact bytes, target-internal starts, null/control/list field tests, direct constructor call, AddItemWithCount slot override, and stale generated/heuristic aliases.
- Historical report-only phase: IDA mutation, rename/type/comment application, implementation validators, generated refresh, tracker/coverage edits, leases, `execute_report`, lifecycle probes/actions, move, and archive commands were intentionally excluded before Gate 1. The accepted callback later used only the recorded short leases, scoped validators, and authorized waited refresh; IDA mutation, manual tracker/coverage/generated edits, `execute_report`, lifecycle actions, move, and archive remained unperformed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target is exactly `[0x004aea40,0x004aea7d)`, 61 bytes, one modeled function. | very strong | MCP lookup/bytes; unique PE hit | UID0004BP | incorporate | applied |
| C02 | Six-byte prepad and three-byte postpad are alignment outside the body; successor starts at `0x004aea80`. | very strong | bytes/function lookups | UID0004BP/UID00033Q | incorporate | applied |
| C03 | Target has 23 instructions and three CFG blocks with two virtual tail exits. | very strong | complete disassembly/CFG | UID0004BP | incorporate | applied |
| C04 | ABI is `void __thiscall`, ECX receiver, no explicit source arguments. | very strong | prologue/stack/tail calls | UID0004BP/class | incorporate | applied |
| C05 | Selectors 1 and 3 are zero-based manager insertion indices. | very strong | constructor order/manager dispatch | UID0004BP/UID0004BM/UID0004BO | incorporate | applied |
| C06 | Selector 1 is the action `ImageButtonControlPane`. | very strong | constructor allocation/index/vtable | UID0004BP/ImageButton/class/file | incorporate | applied |
| C07 | Selector 3 is a `ScrollableControlPane`, not a direct ListPane. | very strong | constructor ownership/target `+0x108` load | UID0004BP/UID0004BO/Scrollable/MyItem | incorporate | applied |
| C08 | `ScrollableControlPane::GetScrollablePane()` is the exact inline accessor needed for `+0x108`. | strong | accepted field layout/direct load/sibling source use | UID0000CE managed block/file | incorporate | applied |
| C09 | `0x004f3e20` is `ListPane::GetSelectionCount() const`, not `HasSelection`. | very strong behavior; strong spelling | complete helper body/14 callers | UID0004M9/ListPane class/file | incorporate | applied |
| C10 | New helper child is `[0x004f3e20,0x004f3e74)`, `91/93`, owner/emitter `00007A`, reconstructable true, blank position, `Nested:0`; UID must be validator-issued. | very strong | function/bytes/padding/nesting | UID0004M9/UID0003U0 | incorporate | applied |
| C11 | Positive count dispatches `Enable`; zero/nonpositive dispatches `Disable`. | very strong | target tails/base/derived slots | UID0004BP/control support | incorporate | applied |
| C12 | A single `SetEnabled(bool)` call is binary-inaccurate and must be rejected. | very strong | separate tail calls | target history/negative evidence | reject-invalid | applied |
| C13 | Target performs no null checks and source must not add them. | very strong | every instruction/CFG | target body/negative evidence | reject-invalid | applied |
| C14 | `+0x101` is enabled state, not ControlPane visibility. | very strong | target, ImageButton override states, Scrollable slots, Pane `+0xb4` visibility | ControlPane/Scrollable/Button/Image support | reject-stale | applied |
| C15 | UID0003N3 is `ControlPane::Enable()` and should be renamed/formalized at `90/93`. | very strong behavior; strong spelling | base vtable/callers/body | UID0003N3 Destination 6 | incorporate | applied |
| C16 | UID0003N4 is `ControlPane::Disable()` and should be renamed/formalized at `90/93`. | very strong behavior; strong spelling | base vtable/callers/body | UID0003N4 Destination 7 | incorporate | applied |
| C17 | ControlPane constructor field is `m_enabled(true)`, superseding `m_controlVisible(true)`. | very strong | constructor offset/consumer semantics | UID0002PB Destination 8 | incorporate | applied |
| C18 | ImageButton `0x00495d10/0x00495d80` are Enable/Disable overrides, not mouse enter/leave. | very strong | exact bodies/vtable slots/states | UID00006D Destination 5/support | reject-stale | applied |
| C19 | AddItem target is a virtual method at primary slot `+0x4c`. | very strong | AddItem/derived vtables | UID000007 Destination 2/vtable docs | incorporate | applied |
| C20 | AddItem, AddEmployee, and AddMixing route slot `+0x4c` to target; AddItemWithCount overrides with `0x004af480`. | very strong | exact dword reads | class/vtable/file support | incorporate | applied |
| C21 | Constructor has no direct target call but reaches target synchronously through `OnCreate -> 0x0049fe20 -> virtual +0x4c`. | very strong | constructor/callee/disassembly chain | UID0004BM/class/file/target | historicalize | applied |
| C22 | Generic refresh wrapper has ten direct callers; only dynamic AddItem-family receivers route to target. | very strong | wrapper decompile/callers | target/DialogPane support | incorporate | applied |
| C23 | Method name remains `UpdateActionButton`; stripped lexical uncertainty does not justify renaming. | strong | existing family and override continuity | target/class | already-present | already-present |
| C24 | Target source position is 40; UID0004BO becomes 30; B001 UID0004BN position 20 remains verify-only. | strong | address/class order/executed report and current-page dependency | target/UID0004BO/class/file | incorporate | applied |
| C25 | Target score becomes `92/94`; owner/emitter/range/reconstructable/Nested stay fixed. | strong | blocker closure | target metadata | incorporate | applied |
| C26 | AddItemDialog class becomes `91/93` and declares virtual updater. | strong | complete method/vtable route | UID000007 Destination 2 | incorporate | applied |
| C27 | UID0004BO's selector-3 line must use wrapper/accessor while preserving its packet logic and `88/90`. | very strong for access; existing for packet body | constructor/target/current handler | UID0004BO Destination 9 | incorporate | applied |
| C28 | UID00033Q remains non-body `[[CHILDREN]]` aggregate at `88/92`, with complete target details added. | very strong | exact child inventory | UID00033Q | incorporate | applied |
| C29 | ItemDialogs remains source route `91/90`; generated output must change only through validators. | very strong | current routing/generated read | UID0000KE | already-present | already-present |
| C30 | AddItem vtable docs must add missing primary `+0x4c` row and derived inheritance/override table. | very strong | exact dwords | UID0003ID/UID0001XV | incorporate | applied |
| C31 | ListPane parent keeps `Nested:1`; existing/new children and following UID0003U1 remain `Nested:0` at cumulative level 212. | very strong | validator semantics/current generated indentation | UID0003U0/UID0004M9/UID0003U1 | already-present | already-present |
| C32 | No exact duplicate target body exists; eight structural siblings corroborate source shape without changing ownership. | very strong | signature/clone scan | target evidence | incorporate | applied |
| C33 | No IDA mutation or third-party import applies. | very strong | project policy/target provenance | report/checklist | not-applicable | excluded-with-reason |

### Callback Verification Notes

| Claim | Implemented/verified destination proof |
| --- | --- |
| C01 | UID0004BP retains exact `[0x004aea40,0x004aea7d)` metadata and records the 61-byte single-function boundary; scoped validator `000000009893` returned `ok:1`. |
| C02 | UID0004BP and UID00033Q now preserve the six-byte predecessor and three-byte successor alignment, with `0x004aea80` excluded as the next function. |
| C03 | UID0004BP records all 23 instructions, three CFG blocks, and both virtual tail exits without collapsing the raw evidence. |
| C04 | UID0004BP and AddItemDialog document `void __thiscall`, ECX receiver, and no explicit argument; Destination 1 emits that exact source shape. |
| C05 | UID0004BP, UID0004BM, and UID0004BO consistently document zero-based selectors `1` and `3` from constructor insertion order. |
| C06 | UID0004BP and ImageButton class/file support identify selector `1` as `ImageButtonControlPane`; Destination 1 uses the exact type. |
| C07 | UID0004BP, UID0004BO, Scrollable support, and MyItem support identify selector `3` as the wrapper and exclude a direct ListPane result. |
| C08 | Destination 4 is byte-for-byte present on UID0000CE, and the file page records the target consumer; generated ScrollableControlPane.cpp contains the inline accessor. |
| C09 | Validator-issued UID0004M9 emits Destination 3 as `int ListPane::GetSelectionCount() const`; ListPane parent/class/file replace synthetic SelectionState ownership. |
| C10 | UID0004M9 is registered at `91/93`, owner/emitter `00007A`, true, blank position, `Nested:0`; command `000000009891` issued the UID before any other page referenced it. |
| C11 | Destination 1 retains separate positive `Enable()` and zero/nonpositive `Disable()` calls; ControlPane and ImageButton support map the paired slots. |
| C12 | No `SetEnabled(bool)` was introduced in any destination; target negative evidence explicitly retains the rejected synthetic setter. |
| C13 | Destination 1 contains no null checks, and target prose preserves constructor-invariant/no-null CFG evidence. |
| C14 | ControlPane constructor/class/file/aggregate, Scrollable class/file, ImageButton class, Button class/file, UID0003N8, and UID0003N9 use current enabled-state wording and historicalize visible/show claims. |
| C15 | UID0003N3 was UID-preservingly renamed to `ControlPaneEnable.md`, raised to `90/93`, and given Destination 6; validator `000000009922` recorded the new path. |
| C16 | UID0003N4 was UID-preservingly renamed to `ControlPaneDisable.md`, raised to `90/93`, and given Destination 7; validator `000000009925` recorded the new path. |
| C17 | UID0002PB preserves all accepted constructor content and changes only the managed member spelling to `m_enabled`; Destination 8 compares byte-for-byte. |
| C18 | UID00006D now declares ButtonControlPane inheritance plus virtual Enable/Disable and records normal/disabled state behavior; stale hover labels are historical rejections. |
| C19 | AddItemDialog Destination 2 declares the updater virtual, and UID0003ID adds primary slot `0x00619ed8` / relative `+0x4c`. |
| C20 | UID0003ID/UID0001XV and AddEmployee/AddMixing/AddItemWithCount class/vtable support record the two inherited routes and the distinct `0x004af480` override. |
| C21 | UID0004BM, AddItemDialog, ItemDialogs, UID0004BP, and DialogPane support distinguish the valid no-direct-call result from synchronous `OnCreate -> 0x0049fe20 -> +0x4c`. |
| C22 | DialogPane class/file and target support retain all ten wrapper callers and identify dynamic AddItem-family versus non-target receivers. |
| C23 | The existing `UpdateActionButton` family spelling was retained on target/class/vtable docs and generated ItemDialogs.cpp. |
| C24 | UID0004BM/UID0004BN/UID0004BO/UID0004BP generated order is `10/20/30/40`; UID0004BN report/page were inspected read-only and never edited. |
| C25 | UID0004BP is `92/94`, position `40`, owner/emitter `000007`, true, `Nested:0`, and exact range unchanged; validator `000000009893` accepted it. |
| C26 | UID000007 is `91/93` with Destination 2 and full target/refresh/vtable evidence; validator `000000009894` returned `ok:1`. |
| C27 | UID0004BO retains `88/90` and packet/loop logic, uses the selector-3 wrapper/accessor sequence, and is position `30`; Destination 9 compares byte-for-byte. |
| C28 | UID00033Q remains `88/92`, `Nested:8`, owner/emitter unchanged, and `[[CHILDREN]]` aggregate-only; target/padding/order evidence was added without a duplicate body. |
| C29 | UID0000KE remains `91/90` at the same route; no generated file was manually edited, and waited validator `000000009960` produced the refresh. |
| C30 | UID0003ID is `90/93` with the missing primary row; UID0001XV and all derived class/vtable pages carry the synchronized inheritance/override table. |
| C31 | UID0003U0 remains relative `Nested:1`; UID0004LX, UID0004M9, and read-only UID0003U1 are `Nested:0`, preserving cumulative level 212. |
| C32 | UID0004BP retains the unique-signature result and eight structural sibling dispositions; no owner or source range was transferred. |
| C33 | Excluded with reason: this callback used documentation, leaser, scoped validator, and authorized autogen operations only; no IDA mutation or third-party source import occurred. |

## Positive Evidence Summary

- IDA models one exact 61-byte function and three blocks. Its instruction stream directly expresses two control lookups, one wrapper child load, one integer selection query, and separate enable/disable tails.
- UID0004BM independently proves exact control insertion order and dynamic types. DialogPane independently supplies `GetChild<T>`. ScrollableControlPane independently supplies the `+0x108` owned child. ListPane independently supplies selection fields and the exact helper body.
- AddItem, AddEmployee, and AddMixing vtables independently route their primary `+0x4c` slot to target. AddItemWithCount independently demonstrates ordinary virtual override semantics at the same slot.
- ImageButton and base ControlPane bodies independently prove the enable/disable names and `m_enabled` field interpretation. Pane's separate `+0xb4` visibility state rejects the stale visible-field alias.
- Eight same-size structural sibling updaters use the same child lookup, count, and two-tail pattern. Their different selector values and call displacements explain why none is an exact byte duplicate.
- The strongest inference chain is constructor type/order -> inherited child API -> target exact load/call sequence -> helper exact body -> vtable slot semantics -> derived routing. No single heuristic carries the recommendation.

## IDA MCP Facts

### Target instruction inventory

| Address | Instruction | Source meaning |
| --- | --- | --- |
| `0x004aea40` | `push esi` | save register |
| `0x004aea41` | `mov esi, ecx` | preserve `this` |
| `0x004aea43` | `push edi` | save action-button register |
| `0x004aea44` | `push 1` | selector 1 |
| `0x004aea46` | `mov ecx, [esi+0x1fc]` | inherited control manager |
| `0x004aea4c` | `mov eax, [ecx]` | manager vtable |
| `0x004aea4e` | `call dword ptr [eax+0x10]` | manager `GetElementAt(1)` |
| `0x004aea51` | `mov ecx, [esi+0x1fc]` | reload manager |
| `0x004aea57` | `push 3` | selector 3 |
| `0x004aea59` | `mov edi, [eax]` | dereference selector-1 action control |
| `0x004aea5b` | `mov eax, [ecx]` | manager vtable |
| `0x004aea5d` | `call dword ptr [eax+0x10]` | manager `GetElementAt(3)` |
| `0x004aea60` | `mov ecx, [eax]` | dereference selector-3 wrapper control |
| `0x004aea62` | `mov ecx, [ecx+0x108]` | load wrapper-owned scrollable pane |
| `0x004aea68` | `call 0x004f3e20` | `ListPane::GetSelectionCount()` |
| `0x004aea6d` | `mov edx, [edi]` | action-button vtable |
| `0x004aea6f` | `mov ecx, edi` | action-button receiver |
| `0x004aea71` | `pop edi` | restore register before tail |
| `0x004aea72` | `pop esi` | restore register before tail |
| `0x004aea73` | `test eax, eax` | count zero/positive test |
| `0x004aea75` | `jg 0x004aea7a` | positive selection branch |
| `0x004aea77` | `jmp dword ptr [edx+0x50]` | nonpositive `Disable()` tail |
| `0x004aea7a` | `jmp dword ptr [edx+0x4c]` | positive `Enable()` tail |

CFG blocks are `[0x004aea40,0x004aea77)`, `[0x004aea77,0x004aea7a)`, and `[0x004aea7a,0x004aea7d)`. The tail dispatches supply the source `void` return; there is no authored return value or explicit argument.

### Selection helper facts

- `sub_4F3E20` is exactly `[0x004f3e20,0x004f3e74)`, size `0x54`, 34 instructions, six CFG blocks, and has no function at its exclusive end.
- If byte `this+0x13c` is zero, it returns whether signed selected index `this+0x134` is nonnegative.
- If multi-select mode is active, it calls selection-list `GetData`, reads count at selection-list `+0x0c`, counts every nonzero byte, and returns the integer count.
- It has 14 code callers and a unique exact-range signature. Four `0xcc` bytes precede it at `[0x004f3e1c,0x004f3e20)` and twelve follow at `[0x004f3e74,0x004f3e80)`.

### Target bytes and boundaries

- Exact bytes: `56 8b f1 57 6a 01 8b 8e fc 01 00 00 8b 01 ff 50 10 8b 8e fc 01 00 00 6a 03 8b 38 8b 01 ff 50 10 8b 08 8b 89 08 01 00 00 e8 b3 53 04 00 8b 17 8b cf 5f 5e 85 c0 7f 03 ff 62 50 ff 62 4c`.
- Predecessor UID0004BO ends at `0x004aea3a`; `[0x004aea3a,0x004aea40)` is six `0xcc` bytes.
- `[0x004aea7d,0x004aea80)` is three `0xcc` bytes; `sub_4AEA80` starts at `0x004aea80`, size `0x30`.
- Local PE scan found the 61-byte target exactly once at raw `0xADE40`, correctly mapping to VA `0x004aea40`.

### ImageButton and base slot facts

- `0x00495d10-0x00495d76` and `0x00495d80-0x00495de6` are each `0x66` bytes. The first runs only while `+0x101` is false, writes image state `+0x110=0`, invalidates copied bounds, then sets `+0x101=true` and invalidates inherited bounds. The second runs only while `+0x101` is true, writes image state `+0x110=2`, invalidates copied bounds, then clears `+0x101` and invalidates inherited bounds.
- ImageButton primary cells `0x00617e18` and `0x00617e1c` point to those functions. Base ControlPane primary cells `0x00617adc` and `0x00617ae0` point to `0x00494bb0` and `0x00494bd0` at the same relative slots.
- Base bodies only transition `+0x101` on change and dispatch invalidation through slot `+0x20`; these are exact `Enable` / `Disable` semantics.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004aea3a,0x004aea40)` | parent-only bytes | six-byte alignment after UID0004BO | no | UID00033Q | n/a | padding, no page |
| `[0x004aea40,0x004aea7d)` | UID0004BP target | virtual action-button updater | true | UID000007 | `92/94` applied | exact source method |
| `[0x004aea7d,0x004aea80)` | parent-only bytes | three-byte alignment | no | UID00033Q | n/a | padding, no page |
| `[0x004aea80,0x004aeab0)` | UID000317 | packet close handler | true | UID000007 | unchanged | separate successor |
| `[0x004f3dd0,0x004f3e1c)` | UID0004LX | set multiple-selection mode | true | UID00007A | `91/93` unchanged | existing exact child |
| `[0x004f3e1c,0x004f3e20)` | UID0003U0 parent-only bytes | four-byte alignment | no | UID0003U0 | n/a | no child |
| `[0x004f3e20,0x004f3e74)` | validator-issued UID0004M9 | `ListPane::GetSelectionCount() const` | true | UID00007A | `91/93` applied | serially created and registered |
| `[0x004f3e74,0x004f3e80)` | UID0003U0 parent-only bytes | twelve-byte alignment | no | UID0003U0 | n/a | no child |
| `[0x004f3e80,0x004f3ef7)` | contained existing function | selected-index export helper | current aggregate disposition | UID0003U0 | unchanged | not modified by target callback |
| `[0x00495d10,0x00495d76)` | current ImageButton core inventory | `ImageButtonControlPane::Enable` override | true source behavior | UID00006D | class support `89/92` applied | declaration/prose correction applied; no new child in this report |
| `[0x00495d80,0x00495de6)` | current ImageButton core inventory | `ImageButtonControlPane::Disable` override | true source behavior | UID00006D | class support `89/92` applied | declaration/prose correction applied; no new child in this report |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00619ed8 -> 0x004aea40` | AddItemDialog primary slot `+0x4c` | direct vtable route |
| `0x00619120 -> 0x004aea40` | AddEmployeeItemDialog primary slot `+0x4c` | inherited implementation |
| `0x0061a170 -> 0x004aea40` | AddMixingItemDialog primary slot `+0x4c` | inherited implementation |
| `0x0061a038 -> 0x004af480` | AddItemWithCount primary slot `+0x4c` | class-specific override, target exclusion |
| `0x004aea68 -> 0x004f3e20` | target's sole ordinary callee | generic selection count |
| `0x004ae8b5 -> 0x0049dfd0` | UID0004BM constructor to DialogPane `OnCreate` | constructor-time setup route |
| `0x0049e119 -> 0x0049fe20` | `OnCreate` to generic selected-control refresh | synchronous indirect target route |
| `0x0049e240` | generic wrapper caller | base dialog input/control dispatch |
| `0x0049e6e0` | generic wrapper caller | base key/focus/selection handling |
| `0x0049ea60` | generic wrapper caller | inherited dialog update/refresh path |
| `0x004a0840` | generic wrapper caller | modeless mouse/input path |
| `0x004ad320` | generic wrapper caller | ExchangeDialog packet dispatcher; reaches Exchange override, not target |
| `0x004ade60` | generic wrapper caller | Exchange ready helper; reaches Exchange override, not target |
| `0x004fae90` | generic wrapper caller | Login dialog mouse path; dynamic non-target slot |
| `0x0059b0f0`, `0x0059b110` | generic wrapper callers | UserInfo input/key paths; dynamic non-target slots |

`0x004f3e20` caller-function inventory: `0x004729a0`, `0x00474170`, `0x0047a320`, `0x004aea40`, `0x005194c0`, `0x0051ae50`, `0x0051c430`, `0x0051d6c0`, `0x0051e600`, `0x0051f250`, `0x0054fa20`, `0x00550c40`, `0x00574440`, and `0x0058cc40`. This broad fanout proves generic ListPane ownership.

Structural same-size updater siblings at `0x004729a0`, `0x0051ae50`, `0x0051c430`, `0x0051d6c0`, `0x0051e600`, `0x0051f250`, `0x0054fa20`, and `0x00550c40` use the same button/list/count/two-tail skeleton with list selectors 3, 5, or 6. They corroborate source shape but do not transfer target ownership.

## Documentation Evidence And IDA Status

- Current UID0004BM is authoritative for control construction, insertion order, MyItemListPane local ownership transfer, resources, and AddItemDialog field layout.
- Current DialogPane formal C++ is authoritative for `m_controlManager`, `GetChildControl`, and protected `GetChild<T>(int)`.
- Current ScrollableControlPane formal C++ is authoritative for inheritance and `m_scrollablePane` at `+0x108` and now includes the exact inline getter needed by accepted callers.
- Current UID0004LX and ListPane docs are authoritative for `m_multipleSelectionEnabled`, `m_selectionFlags`, selected index `+0x134`, and generic ListPane ownership. The pre-callback note that `0x004f3e20` emitted under `SelectionState` was stale generated ownership pollution; UID0004M9 now owns and emits the helper through ListPane.
- Current ScrollableControlPane, ControlPane, and ImageButtonControlPane docs use `Enable` / `Disable` consistently with multiple UI availability consumers. The pre-callback visible/hover wording was contradicted and is now explicitly superseded.
- The current AddItem vtable page includes the formerly missing primary slot `+0x4c`; the AddEmployee vtable-data page records its inherited target cell and remains useful positive support.
- Pre-callback generated ItemDialogs mirrored the target's placeholder managed block and was stale by construction. Validator-owned refresh `000000009960` now emits the exact accepted body; B005 did not edit generated artifacts manually.
- IDA status at evidence time: healthy, analyzed, Hex-Rays ready, strings ready, one adopted database. Target and helper were modeled functions; no IDA database mutation was performed.

## Ranked Ownership Analysis

### 1. AddItemDialog / ItemDialogs

- Evidence for: exact AddItem vtable cell, current method/class name continuity, constructor-created controls, inherited DialogPane receiver layout, current owner/emitter route, derived AddEmployee/AddMixing inheritance, AddItemWithCount override, and contiguous AddItem source ordering.
- Evidence against: original symbol spelling is stripped; implementation is reached through a generic virtual wrapper rather than ordinary direct callers.
- Decision: retain canonical owner/emitter UID000007 and source file UID0000KE. Virtual-only reachability is positive class ownership evidence, not a blocker.

### 2. DialogPane

- Evidence for: owns `m_controlManager`, `GetChild`, `OnCreate`, and generic refresh wrapper `0x0049fe20`.
- Evidence against: wrapper is generic and dispatches many derived slot implementations; target appears only in AddItem-family vtables and uses AddItem-specific selectors/control composition.
- Decision: dependency and indirect caller only; reject as owner.

### 3. ListPane / ScrollableControlPane / ImageButtonControlPane

- Evidence for: own the target's exact callee, wrapper field, and enable/disable implementations.
- Evidence against: none owns the coordinating AddItemDialog receiver, selectors, or virtual slot.
- Decision: retain as independent support owners. Create the exact ListPane helper child and correct control declarations; do not move target ownership.

### Proposed new file/grouping, if applicable

- No new source file. The only new documentation child belongs to existing [UID0000KT] `NexusTK/ui/controls/ListPane.cpp` through class [UID00007A].
- It must be narrow: exact `ListPane::GetSelectionCount() const` only. Target, button, wrapper, and dialog code remain in their established files.
- Rejected grouping: a target-local `SelectionState` class, AddItem-local selection helper, or generic DialogPane button-state file.

## Source Placement

- Recommended target placement: [UID0000KE] `NexusTK/ui/dialogs/ItemDialogs.cpp`, method position `40` under class [UID000007].
- Ordered AddItem source surface: constructor UID0004BM position `10`; destructor UID0004BN position `20` as established by the archived executed B001 report and current verify-only by-memory page; OnAction UID0004BO position `30`; target UID0004BP position `40`; later packet/helper methods keep their established order.
- Recommended helper placement: [UID0000KT] `NexusTK/ui/controls/ListPane.cpp`, exact child under [UID00007A], optional source position blank because the current ListPane route does not assign numeric positions to UID0004LX or neighboring exact helpers.
- Control declaration placements remain [UID0000NE] ScrollableControlPane, [UID0000HY] ButtonControlPane, and [UID0000IG] ControlPane.
- Rejected placements: DialogPane is a generic dispatcher; MyItemListPane only supplies the dynamic list object; Employee/Mixing modules are derived consumers; AddItemWithCount has a distinct override.
- Remaining uncertainty: exact original header/file splitting inside the control modules and stripped lexical spellings are not PDB-proven. No uncertainty remains about target module, class, method order, or emitted body.

## Range / Split / Padding / Reclassification Analysis

- Target exact range remains `[0x004aea40,0x004aea7d)`. No byte inside is padding, data, EH, compiler-only, or a second source method.
- The six bytes before and three bytes after are `0xcc` parent-only alignment. They must not become children or be included in adjacent source methods.
- UID00033Q remains the broad AddItem core `[[CHILDREN]]` aggregate. Target relative `Nested:0` and current generated cumulative indentation `213` remain unchanged; `Nested` is not a method count.
- The reusable helper is independently modeled at `[0x004f3e20,0x004f3e74)` and must be split from UID0003U0. Its four-byte prepad and twelve-byte postpad stay parent-only.
- Validator address order/cumulative nesting for the ListPane insertion is exact: UID000194 currently renders at cumulative 211; UID0003U0 applies `Nested:+1` and renders at 212; UID0004LX applies `0` and remains 212; the new helper applies `0` and remains 212; following UID0003U1 retains `0` and remains 212. No following-row repair is required.
- Serial child workflow: create the exact file without a guessed UID, run its scoped validator to allocate/register the real UID, then add that issued UID to UID0003U0, ListPane class/file, and target/support cross-references. Do not reference a placeholder UID in by-* docs.
- No target rename, merge, inline-only disposition, owner reclassification, raw-helper retention, compiler wrapper, vtable emission, or third-party import applies.

## Negative Evidence Summary

- No ordinary code xref points to target. The three inbound references are vtable data cells; this is expected for a virtual-only method.
- No target instruction checks action button, wrapper, or list for null. Adding defensive checks would change observed behavior and code shape.
- No AddItemDialog field stores MyItemListPane or ScrollableControlPane. The controls are owned through the manager/wrapper lifecycle.
- No target instruction calls a boolean setter. Two distinct virtual tails are observable.
- No target instruction reads an event, hover state, resource id, packet, singleton, employee owner, or mixing state.
- No exact duplicate 61-byte body exists. Structural siblings differ by selector and displacement and remain separate class methods.
- No direct constructor call to `0x004aea40` exists. This does not negate the separately proved synchronous virtual route through `OnCreate`.
- No source evidence supports `SelectionState` as a class. ListPane RTTI, fields, helper adjacency, and broad callers establish reusable ListPane ownership.
- Physical adjacency to packet handlers and ItemExchangeMix ranges does not transfer ownership away from AddItemDialog.
- Current visible/show and hover names are rejected because the same state slots are consumed to disable unavailable action/navigation controls and drive normal/disabled ImageButton state.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name/type: `void AddItemDialog::UpdateActionButton()`; receiver `AddItemDialog *`; no explicit parameters.
- Source-facing locals: `ImageButtonControlPane *actionButton`, `ScrollableControlPane *itemListControl`, and `ListPane *itemList`.
- Source-facing dependencies: `DialogPane::GetChild<T>(int)`, `ScrollableControlPane::GetScrollablePane() const`, `ListPane::GetSelectionCount() const`, `ControlPane::Enable()`, and `ControlPane::Disable()`.
- Source-facing state: `m_enabled` at ControlPane `+0x101`; ImageButton state at `+0x110` may remain descriptively `m_imageState` in prose because this report does not propose its field declaration.
- Preserve raw labels `sub_4AEA40`, `sub_4F3E20`, `sub_495D10`, `sub_495D80`, and offsets only as evidence/search aliases.
- IDA DB edits were not requested or performed. The documentation/managed C++ corrections were completed in this callback; any independent IDA rename/type/comment mutation remains outside this report and requires separate supervisor authority.

## First-Draft C++ Recommendation

- Eligible: target, AddItemDialog declaration, new ListPane helper child, ScrollableControlPane declaration/accessor, ImageButtonControlPane target-required declaration, base Enable/Disable children, ControlPane constructor field correction, and UID0004BO wrapper-access correction.
- Exactly nine literal managed destination blocks follow and were applied. No other C++ edit was authorized or applied by this report.
- The bodies preserve the observed absence of null checks, integer count test, wrapper load, two virtual exits, state transition guards, and source-visible class relationships. Raw manager internals, offsets, vtables, cookies, and decompiler labels are omitted.
- Style follows current accepted NexusTK docs: PascalCase methods, `m_` fields, `NULL` in existing period-style bodies, explicit pointer types, braces, and `[[CHILDREN]]` after class declarations.
- Third-party import: not applicable.

### Destination 1 - UID0004BP exact target body

Exact destination: `by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void AddItemDialog::UpdateActionButton()
{
    ImageButtonControlPane *actionButton =
        GetChild<ImageButtonControlPane>(1);
    ScrollableControlPane *itemListControl =
        GetChild<ScrollableControlPane>(3);
    ListPane *itemList =
        static_cast<ListPane *>(itemListControl->GetScrollablePane());

    if (itemList->GetSelectionCount() > 0)
        actionButton->Enable();
    else
        actionButton->Disable();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID000007 AddItemDialog declaration

Exact destination: `by-class/AddItemDialog.md`. Preserve all accepted class content; the method change is nonvirtual to virtual.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class AddItemDialog : public DialogPane
{
public:
    AddItemDialog(unsigned int exchangeSessionId,
                  unsigned char allowMultipleSelection);
    virtual ~AddItemDialog();

    virtual int OnAction(unsigned int actionId);
    virtual int OnClosePacket(const unsigned char *packet);
    virtual void UpdateActionButton();
    void SendSelectedItemPacket(char selectedInventorySlot);

protected:
    unsigned int m_exchangeSessionId;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - new exact ListPane selection-count child

Exact destination path before validator UID allocation: `by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ListPane::GetSelectionCount() const
{
    if (!m_multipleSelectionEnabled)
        return m_selectedIndex >= 0;

    int selectedCount = 0;
    const unsigned char *selectionFlags =
        static_cast<const unsigned char *>(m_selectionFlags->GetData());

    for (int i = 0; i < m_selectionFlags->GetCount(); ++i)
    {
        if (selectionFlags[i] != 0)
            ++selectedCount;
    }

    return selectedCount;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID0000CE ScrollableControlPane declaration

Exact destination: `by-class/ScrollableControlPane.md`. Preserve the complete current declaration and add only the inline accessor shown.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Layer;
class Pane;
class ScrollablePane;
struct RectBounds;

class ScrollableControlPane : public ControlPane
{
public:
    ScrollableControlPane(const RectBounds *bounds,
                          ScrollablePane *scrollablePane,
                          int horizontalScrollBarOffset,
                          int verticalScrollBarOffset,
                          int scrollBarInset);
    virtual ~ScrollableControlPane();

    ScrollablePane *GetScrollablePane() const
    {
        return m_scrollablePane;
    }

    void SetScrollTargetValue(short targetValue, char axis);
    void SetScrollCurrentValue(short currentValue, char axis);
    short GetScrollMax(char axis) const;
    short GetScrollPosition(char axis) const;

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void Enable();
    virtual void Disable();
    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    ScrollablePane *m_scrollablePane;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID00006D ImageButtonControlPane declaration

Exact destination: `by-class/ImageButtonControlPane.md`. This is the complete target-required surface; other class methods remain in their existing inventory and are not given new bodies here.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ImageButtonControlPane : public ButtonControlPane
{
public:
    ImageButtonControlPane(int imageId, const RectBounds *bounds);
    virtual void Enable();
    virtual void Disable();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0003N3 ControlPane Enable

Exact destination after UID-preserving path rename: `by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ControlPane::Enable()
{
    if (m_enabled)
        return;

    m_enabled = true;
    Invalidate(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - UID0003N4 ControlPane Disable

Exact destination after UID-preserving path rename: `by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ControlPane::Disable()
{
    if (!m_enabled)
        return;

    m_enabled = false;
    Invalidate(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - UID0002PB ControlPane constructor field correction

Exact destination: `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`. Preserve the complete accepted body; change only the superseded `m_controlVisible` member spelling to `m_enabled`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)
    : Pane(1),
      m_rangeStart(0),
      m_rangeCurrent(0),
      m_rangeEnd(0),
      m_controlType(controlType),
      m_controlFlags(0),
      m_reservedControlState(0),
      m_enabled(true),
      m_controlActive(false),
      m_visualState(10),
      m_ignoreHitTesting(false)
{
    if (bounds != NULL)
        SetBounds(bounds, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - UID0004BO selector-3 wrapper correction

Exact destination: `by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md`. Preserve the accepted packet/loop body and replace only the stale direct-list selector helper with the exact wrapper/accessor sequence; set position `30`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int AddItemDialog::OnAction(unsigned int actionId)
{
    if (actionId == 2)
    {
        CloseDialog();
        return 0;
    }

    if (actionId != 1)
        return 0;

    ScrollableControlPane *itemListControl =
        GetChild<ScrollableControlPane>(3);
    ListPane *itemList =
        static_cast<ListPane *>(itemListControl->GetScrollablePane());
    DialogRow *selectedRows[256] = {};
    const int selectedCount = GetSelectedRows(itemList, selectedRows, 256);

    for (int i = 0; i < selectedCount; ++i)
    {
        const ItemListRow *row = static_cast<const ItemListRow *>(selectedRows[i]);
        if (row == 0)
            continue;

        unsigned char packet[8] = {};
        PacketBufferWriteUInt8(0x4a, packet);
        PacketBufferWriteUInt8(1, packet + 1);
        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        PacketBufferWriteUInt8(row->itemId, packet + 6);
        packet[7] = 0;
        g_packetSender->QueueAndSendPacket(packet, 7);
    }

    CloseDialog();
    return 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- C01-C33 are implemented without compression; raw facts, historical assumptions, rejected aliases, derived routes, clone evidence, padding, and negative evidence remain preserved.
- Exactly nine managed blocks are present and byte-for-byte verified. The sole new ListPane child was registered as UID0004M9 before references were inserted.
- Target owner/emitter/range/reconstructable/Nested remain fixed; `92/94`, position `40`, the exact Item Summary, and Destination 1 are current.
- Supporting class/control contracts now use the accepted wrapper, count, enable/disable, and field semantics instead of placeholder APIs.
- The archived executed B001 UID0004BN report and current UID0004BN by-memory page remained read-only verify-only dependencies at source position `20`.
- No target-related item remains no-owner or blocked. Parent padding and compiler vtable mechanics remain non-emitting; no third-party import or IDA mutation occurred.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md`.
- Current metadata is `92/94`; owner/emitter `000007`, true, range, and `Nested:0` are unchanged, with position `40`.
- Current Item Summary is exactly: `AddItemDialog virtual action-button updater; resolves action control 1 and scroll-wrapper control 3, unwraps the owned ListPane, queries integer selection count, and tail-dispatches Enable or Disable without null checks.`
- Destination 1 is the current formal block and compares byte-for-byte with this report.
- Every target instruction, CFG, ABI, byte, padding, unique-hit, selector, type, helper, vtable, caller, refresh, derived route, clone, source-order, and negative-evidence fact is incorporated.
- B007's initial placeholder body/score, the narrower direct-call negative, `ButtonPane`, direct ListPane selector, boolean `HasSelection`, `SetEnabled`, and null-check assumptions remain explicitly historical/superseded.

## Recommended Support Doc Changes

- UID000007 now carries Destination 2 at `91/93` with complete target/selector/helper/refresh/vtable/order evidence and the exact direct-call-negative/synchronous-OnCreate distinction.
- UID00033Q remains `88/92`, owner/emitter, `[[CHILDREN]]`, range, and `Nested:8`, with expanded target/padding/order/wrapper evidence.
- UID0000KE remains `91/90` on the same route with source order, refresh, ListPane/control dependencies, derived routing, and generated expectations recorded.
- UID0004BM remains `92/94`, position `10`, and body-identical; only the broad no-constructor-update wording was historicalized around the exact synchronous route.
- The archived executed B001 UID0004BN report and current page were verified read-only at position `20`; neither was edited.
- UID0004BO remains `88/90` and retains packet logic/range/ownership/`Nested:0`; Destination 9 and position `30` are current.
- UID0003ID is `90/93` with primary `0x00619ed8` / `+0x4c`, stores, and inheritance/override evidence; UID0001XV carries the synchronized table without unrelated score/route changes.
- AddEmployee and AddMixing class/vtable support now names inherited target behavior/refresh while keeping scores/routes/formal bodies; AddItemWithCount preserves separate `0x004af480` override exclusion.
- DialogPane class/file preserve formal blocks/scores and now carry exact `0x0049fe20` behavior, ten callers, dynamic ownership, and historical direct-call distinction.
- ScrollableControlPane class/file preserve `92/94` and `91/93`; Destination 4, inline getter, target consumer, and current enabled-state prose are applied.
- ImageButtonControlPane is `89/92` with Destination 5 and Enable/Disable labels/behavior; constructor, SetState, OnPaint, compiler route, fanout, and unresolved non-target fields remain preserved.
- ButtonControlPane file/class preserve scores/routes/no-code/raw evidence while using current enabled-gate and corrected control links.
- UID0002PB remains `89/92`, same metadata/body except Destination 8 member spelling; Item Summary/layout/history now use current `m_enabled` and superseded visible wording.
- UID0003N3/UID0003N4 retain UIDs and metadata, are renamed to ControlPaneEnable/Disable, are `90/93`, and carry Destinations 6/7.
- ControlPane class/file are `88/91`, with constructor/slots/consumers/Pane visibility/raw-helper history synchronized; class formal remains blank and unrelated blockers remain explicit.
- UID0002PD remains `88/91`, owner-none/non-emitting/blank, with updated child paths and enabled-state evidence.
- UID0003N9/UID0003N8 preserve scores, owners, true state, ranges, complete raw no-route proof, and blank blocks; only current `+0x101` terminology changed, with old visible/show claims historicalized.
- UID0004M9 was created/registered serially at `91/93`, owner/emitter `00007A`, true, blank position, Destination 3, exact Item Summary, and `Nested:0`.
- UID0003U0 remains `87/90`, same range/owner/emitter/true/blank/`Nested:1`, with UID0004M9, exact body/padding/callers, and updated summary.
- ListPane class/file remain `90/88` and `89/87`, link UID0004M9, establish exact ListPane ownership/body/fields/callers, and preserve UID0004LX/raw blockers.
- UID0003U1 was verified read-only at `Nested:0` and was not edited.
- MyItemListPane class/file preserve scores/formal routes and now document wrapper traversal, dynamic receiver, inherited UID0004M9, and the absence of an AddItemDialog member.
- Final command `000000009960` refreshed generated state through the validator. ItemDialogs.cpp, ListPane.cpp, ScrollableControlPane.cpp, ButtonControlPane.cpp, and ControlPane.cpp were inspected read-only; no generated file was manually edited.

## Score And Metadata Recommendation

| Item | Pre-callback | Current callback | Metadata disposition |
| --- | --- | --- | --- |
| UID0004BP target | `86/90` | `92/94` | owner/emitter/range/true/Nested unchanged; position `40`, applied |
| UID000007 AddItemDialog | `90/92` | `91/93` | owner/emitter/path unchanged; Destination 2 applied |
| UID00033Q AddItem core | `88/92` | `88/92` | aggregate/range/Nested/children preserved |
| UID0004BM constructor | `92/94` | `92/94` | position 10; prose correction applied |
| UID0004BO OnAction | `88/90` | `88/90` | position `30`; Destination 9 applied |
| UID0003ID AddItem vtables | `88/92` | `90/93` | owner/class route unchanged |
| UID0000KE ItemDialogs | `91/90` | `91/90` | source path unchanged |
| UID0004M9 ListPane child | absent | `91/93` | validator-issued; owner/emitter 00007A; true; blank position; Nested0 |
| UID0003U0 ListPane parent | `87/90` | `87/90` | Nested1; child/evidence added |
| UID00007A ListPane | `90/88` | `90/88` | broad source blockers remain |
| UID0000KT ListPane file | `89/87` | `89/87` | broad source blockers remain |
| UID0000CE ScrollableControlPane | `92/94` | `92/94` | Destination 4; owner/position/route unchanged |
| UID00006D ImageButtonControlPane | `87/89` | `89/92` | Destination 5; owner/route unchanged |
| UID0003N3 Enable | `86/90` | `90/93` | UID-preserving path rename; owner/emitter/range/true/Nested unchanged |
| UID0003N4 Disable | `86/90` | `90/93` | UID-preserving path rename; owner/emitter/range/true/Nested unchanged |
| UID0002PB ControlPane constructor | `89/92` | `89/92` | Destination 8 applied |
| UID000038 ControlPane class | `86/88` | `88/91` | blank formal remains; owner/route unchanged |
| UID0000IG ControlPane file | `86/88` | `88/91` | path unchanged |
| UID0002PD state aggregate | `88/91` | `88/91` | non-emitting/owner-none/blank body preserved |

Implemented score rationale:

- Range blocker removed by fresh function/endpoint/byte/padding/unique-hit checks.
- Calling-convention and return blocker removed by complete 23-instruction/tail-dispatch audit.
- Selector/helper/type blocker removed by constructor order, accepted DialogPane API, wrapper field, and ListPane helper body.
- Null/dispatch blocker removed by complete CFG and control-slot audit.
- Caller/timing blocker removed by vtable reads, wrapper decompile, ten wrapper callers, and constructor `OnCreate` route.
- Source-name blocker reduced through class-family spellings and structural siblings; names remain inferred, so target confidence stops at 94 rather than symbol-level final.
- Source-placement/order blocker removed by exact class family, the archived executed destructor report/current verify-only page, and numeric position convention.
- New helper score stops at `91/93` because `GetSelectionCount` and member names are descriptive/inferred despite exact behavior.
- ControlPane class/file remain below 90 completion because unrelated fixed virtual, destructor representation, and raw active-frame source representation remain open; this report does not erase those blockers.

## Open Questions With Attempted Resolution

- Is selector 1 a generic ControlPane or ImageButton? Checked constructor allocations/order, ImageButton constructor id 36, target vtable tails, and derived slot bodies. Resolution: dynamic and best source type is ImageButtonControlPane; generic ControlPane remains a legal weaker type but loses exact evidence.
- Is selector 3 a ListPane? Checked constructor, wrapper ownership, target `+0x108` load, Scrollable layout, and MyItemListPane construction. Resolution: selector 3 is the wrapper; its owned child is dynamically MyItemListPane and generically ListPane.
- Is `0x004f3e20` boolean? Checked all helper instructions and multi-select loop. Resolution: no; integer count, with boolean 0/1 only in single-select mode.
- Are slots `+0x4c/+0x50` visibility, hover, selection, or enablement? Checked base bodies, Scrollable formal names, target consumer, ImageButton normal/disabled states, navigation-control availability consumers, and separate Pane visibility field. Resolution: Enable/Disable.
- Should source use one boolean setter? Checked target tails and sibling updaters. Resolution: no; explicit branch and two virtual calls reproduce the binary.
- Does constructor initialize button state? Checked direct callees, `OnCreate`, and `0x0049fe20`. Resolution: no direct call, but yes synchronous indirect virtual refresh after controls and AddItem vtables exist.
- Is target source position 4 or 40? Checked current numeric convention and the executed B001/current UID0004BN position 20. Resolution: logical ordinal four, literal validator position 40.
- Does target need a split? Checked every byte/block/end/pad/duplicate. Resolution: no.
- Does the helper need a new child? Checked current broad parent, modeled function, generated alias pollution, and exact child policy. Resolution: yes, serially registered without guessed UID.
- What remains unresolved? Only exact original lexical spellings/header split are not symbol-proven. The selected names are the highest-probability coherent source form and do not block C++ or owner/score recommendations.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual coverage or tracker text should be changed.
- Validator-owned auto-generated reports must derive from target Item Summary, score, position, owner/emitter, and relative `Nested` metadata plus the serially registered helper child.
- The tracker/report lifecycle count is external supervisor/validator state and is not frozen or predicted by this artifact.

## Follow-Up Actions

- Supervisor-owned lifecycle state remains external to this archive-neutral report; no report execution, move, archive, or tracker action is directed or asserted here.
- A-agent actions: none required by the evidence.
- B005 responsibilities are complete: C01-C33 and Destinations 1-9 are applied, UID0004M9 was allocated serially, every changed by-* page received one scoped validator under a short lease, all leases were released, and the authorized waited refresh/read-only verification completed.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: target `92/94` is justified by complete binary/source-route closure; support score changes are conservative relative to remaining class-wide blockers.
- Remaining uncertainty: stripped exact spellings and historical header split only. They do not affect range, ABI, behavior, types, virtual slots, owner, source file, source order, or first-draft completeness.

## Validator Results

- Historical report-only phase: no validator was run before accepted Gate 1 SHA `70A9C8DAB7E4FB8FBCC83ADE153BD8991C1C4B8362AEE61C14BFC429A1DC291D`.
- Callback validators: all 35 scoped file commands exited `0` with `ok:1`; each deferred generation until the final authorized refresh.

| Command | Timestamp ET | Scoped page | Result | Warning/result notes |
| --- | --- | --- | --- | --- |
| `000000009891` | `2026-07-13T12:48:44-04:00` | new `ListPaneGetSelectionCount.md` | exit 0, ok 1 | issued UID0004M9; registered score/owner/emitter/true/Nested0 |
| `000000009893` | `2026-07-13T12:50:04-04:00` | UID0004BP target | exit 0, ok 1 | target metadata/body accepted |
| `000000009894` | `2026-07-13T12:50:53-04:00` | AddItemDialog class | exit 0, ok 1 | four pre-existing missing UID0003ID reference warnings |
| `000000009895` | `2026-07-13T12:51:35-04:00` | UID00033Q | exit 0, ok 1 | no target-specific warning |
| `000000009896` | `2026-07-13T12:52:29-04:00` | ItemDialogs file | exit 0, ok 1 | pre-registration missing-reference warnings for UID0003ID/3IE/3IG/3IF |
| `000000009897` | `2026-07-13T12:52:57-04:00` | UID0004BM | exit 0, ok 1 | no target-specific warning |
| `000000009898` | `2026-07-13T12:53:29-04:00` | UID0004BO | exit 0, ok 1 | no target-specific warning |
| `000000009899` | `2026-07-13T12:54:06-04:00` | UID0003ID | exit 0, ok 1 | path mapping added |
| `000000009900` | `2026-07-13T12:54:38-04:00` | UID0001XV | exit 0, ok 1 | pre-registration sibling-vtable reference warnings |
| `000000009901` | `2026-07-13T12:55:12-04:00` | AddEmployeeItemDialog class | exit 0, ok 1 | no target-specific warning |
| `000000009902` | `2026-07-13T12:55:56-04:00` | UID0002MH | exit 0, ok 1 | two pre-existing UID0003KY reference warnings |
| `000000009903` | `2026-07-13T12:56:26-04:00` | AddMixingItemDialog class | exit 0, ok 1 | pre-registration UID0003IF warnings |
| `000000009904` | `2026-07-13T12:56:55-04:00` | AddMixing vtables | exit 0, ok 1 | UID0003IF path mapping added |
| `000000009905` | `2026-07-13T12:57:21-04:00` | AddItemWithCountDialog class | exit 0, ok 1 | pre-registration UID0003IE warning |
| `000000009906` | `2026-07-13T12:57:50-04:00` | AddItemWithCount vtables | exit 0, ok 1 | UID0003IE path mapping added |
| `000000009909` | `2026-07-13T12:59:26-04:00` | DialogPane class | exit 0, ok 1 | ten pre-existing missing-reference warnings (UID0003JB/3AW/3KD/3KP) |
| `000000009911` | `2026-07-13T13:00:17-04:00` | DialogPane file | exit 0, ok 1 | eight pre-existing missing-reference warnings (UID0003JB/3KD/3KP/3AW) |
| `000000009912` | `2026-07-13T13:00:49-04:00` | ScrollableControlPane class | exit 0, ok 1 | managed-block registry hash updated |
| `000000009915` | `2026-07-13T13:01:16-04:00` | ScrollableControlPane file | exit 0, ok 1 | no target-specific warning |
| `000000009917` | `2026-07-13T13:02:04-04:00` | ImageButtonControlPane class | exit 0, ok 1 | score and managed-block registry updated |
| `000000009918` | `2026-07-13T13:02:43-04:00` | ButtonControlPane file | exit 0, ok 1 | two pre-existing UID0003NC reference warnings |
| `000000009920` | `2026-07-13T13:03:23-04:00` | UID0002PB | exit 0, ok 1 | managed-block registry updated |
| `000000009922` | `2026-07-13T13:04:29-04:00` | UID0003N3 Enable | exit 0, ok 1 | UID-preserving path/score/body update; one UID0003J8 warning |
| `000000009925` | `2026-07-13T13:05:20-04:00` | UID0003N4 Disable | exit 0, ok 1 | UID-preserving path/score/body update; one UID0003J8 warning |
| `000000009930` | `2026-07-13T13:07:46-04:00` | ControlPane class | exit 0, ok 1 | 16 pre-existing missing-reference warnings; renamed UID links updated |
| `000000009934` | `2026-07-13T13:09:24-04:00` | ControlPane file | exit 0, ok 1 | 14 pre-existing missing-reference warnings; renamed UID links updated |
| `000000009937` | `2026-07-13T13:10:41-04:00` | UID0002PD | exit 0, ok 1 | six pre-existing UID0003N1/3N6/3N7 warnings |
| `000000009941` | `2026-07-13T13:11:56-04:00` | UID0003N9 | exit 0, ok 1 | two pre-existing UID0003N6/3N7 warnings |
| `000000009944` | `2026-07-13T13:13:02-04:00` | UID0003N8 | exit 0, ok 1 | reference index synchronized; no target-specific warning |
| `000000009946` | `2026-07-13T13:13:47-04:00` | ButtonControlPane class | exit 0, ok 1 | corrected UID links/reference index |
| `000000009947` | `2026-07-13T13:15:12-04:00` | UID0003U0 | exit 0, ok 1 | UID0004M9/UID0004BP references registered |
| `000000009950` | `2026-07-13T13:15:57-04:00` | ListPane class | exit 0, ok 1 | eight pre-existing split-child reference warnings |
| `000000009953` | `2026-07-13T13:16:37-04:00` | ListPane file | exit 0, ok 1 | nine pre-existing vtable/split-child reference warnings |
| `000000009957` | `2026-07-13T13:17:25-04:00` | MyItemListPane class | exit 0, ok 1 | stats/reference index synchronized |
| `000000009959` | `2026-07-13T13:18:03-04:00` | MyItemListPane file | exit 0, ok 1 | no target-specific warning |

- Validator-owned scoped side effects included projected `project-level/-auto-completion-stats.md`, reference-index, path, score, UID, and autogen-registry updates where reported. B005 did not edit those files manually.
- Final authorized refresh: `000000009960`, `2026-07-13T13:18:31-04:00`, exit `0`, `generated_refresh:completed`; it rebuilt 4,669 metadata nodes/3,803 edges and refreshed 281 generated metadata entries. Global pre-existing warnings were `autogen_children_fallback_insert:15`, `autogen_children_marker_missing:83`, and `autogen_emitter_has_no_code:204`; none blocked this callback.
- Read-only generated proof after `000000009960`:
  - `ItemDialogs.cpp` SHA-256 `B6733DAC9E93E459815C2CEE802A97DA8497B849DBC6C609DD0E74E8C6AC3FC8`: UID000007 class shell and UID0004BM/4BN/4BO/4BP order are correct; target body uses wrapper/accessor/count/two tails.
  - `ListPane.cpp` SHA-256 `84F62D39EC14E92D1DAFA617E9405416E3A42F77F59A1580D316CCABD793F03B`: UID0004LX then UID0004M9 emit through ListPane; UID0003U0 remains the expected empty aggregate marker and no SelectionState owner appears.
  - `ScrollableControlPane.cpp` SHA-256 `51E0A7252432BB77BB8E0FDF16A1F7A5E14A89F5531A8D6192208B7D2ACC81C7`: complete class shell contains inline `GetScrollablePane()`; existing exact method children remain independently emitted.
  - `ButtonControlPane.cpp` SHA-256 `00F460222D26A952E36C4DF15E64E0B889F4D26468B3345814D31D7DBF5EC82A`: ImageButton class shell declares ButtonControlPane inheritance and virtual Enable/Disable; UID0003N8 remains non-emitting as accepted.
  - `ControlPane.cpp` SHA-256 `EEFC1163550D40B25A41716BD3E6E18611CDAF66DE4A16AE592AD17F585C1DC7`: constructor emits `m_enabled(true)`, UID0003N3/3N4 emit Enable/Disable, and UID0003N9 remains the expected empty raw-helper marker.
- Literal-block audit: exactly nine report blocks were found, and Destinations 1-9 each compared byte-for-byte equal to the current destination managed block.
- Lease audit: `tools/leaser/Agents/current_leases.md` contained no B005 row after completion; every B005 lease was released.

## Changed Files

- Callback artifact modified: `tools/leaser/Agents/Agent-B005/research/0004BP-AddItemDialogUpdateActionButton-source-quality.md`.
- Created and registered: `by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md` as UID0004M9.
- UID-preserving renames:
  - `by-memory/0x00494bb0-0x00494bca.ControlPaneSetVisibleFlag.md` -> `by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md`.
  - `by-memory/0x00494bd0-0x00494bea.ControlPaneClearVisibleFlag.md` -> `by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md`.
- Modified ordinary by-* pages:
  - `by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md`
  - `by-class/AddItemDialog.md`
  - `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md`
  - `by-file/ItemDialogs.md`
  - `by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md`
  - `by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md`
  - `by-type/by-vtable/AddItemDialogVtables.md`
  - `by-type/by-vtable/ItemDialogVtableFamily.md`
  - `by-class/AddEmployeeItemDialog.md`
  - `by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md`
  - `by-class/AddMixingItemDialog.md`
  - `by-type/by-vtable/AddMixingItemDialogVtables.md`
  - `by-class/AddItemWithCountDialog.md`
  - `by-type/by-vtable/AddItemWithCountDialogVtables.md`
  - `by-class/DialogPane.md`
  - `by-file/DialogPane.md`
  - `by-class/ScrollableControlPane.md`
  - `by-file/ScrollableControlPane.md`
  - `by-class/ImageButtonControlPane.md`
  - `by-file/ButtonControlPane.md`
  - `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`
  - `by-class/ControlPane.md`
  - `by-file/ControlPane.md`
  - `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
  - `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`
  - `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`
  - `by-class/ButtonControlPane.md`
  - `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
  - `by-class/ListPane.md`
  - `by-file/ListPane.md`
  - `by-class/MyItemListPane.md`
  - `by-file/MyItemListPane.md`
- Verify-only and unchanged: archived executed UID0004BN report, current UID0004BN by-memory page, and UID0003U1.
- Validator-owned side effects: validator registry/reference/statistics state plus authorized generated metadata/C++ refresh; no such file was manually edited.
- Report execution/lifecycle/move/archive: not run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact report SHA `70A9C8DAB7E4FB8FBCC83ADE153BD8991C1C4B8362AEE61C14BFC429A1DC291D` before implementation.
- [x] C01-C33 were applied claim by claim without compressing evidence, negatives, history, or rejected alternatives.
- [x] UID0004BP is `92/94`, position `40`, exact Item Summary, unchanged owner/emitter/range/true/Nested, and Destination 1.
- [x] All nine literal managed blocks are exact; no draft/example C++ was added outside them.
- [x] UID0004M9 was allocated/registered serially before cross-reference insertion.
- [x] UID0003U0 `Nested:1`, UID0004LX/UID0004M9/UID0003U1 `Nested:0`, and cumulative level 212 are preserved.
- [x] UID000007/33Q/0KE/4BM/4BO/3ID/1XV target-family details are complete.
- [x] Archived/current UID0004BN dependencies were verified read-only at position `20` and not edited.
- [x] Scrollable getter/enabled-state support and ImageButton Enable/Disable declaration/evidence/score/history are applied.
- [x] UID0003N3/UID0003N4 were UID-preservingly renamed/formalized and direct links synchronized.
- [x] Target-triggered current `+0x101` claims use enabled-state wording; old visible/show/hover claims are historical/superseded.
- [x] UID0003N8/UID0003N9 liveness negatives, scores, owners, ranges, and blank blocks are preserved.
- [x] AddEmployee/AddMixing inheritance and AddItemWithCount override exclusion are preserved with unrelated bodies unchanged.
- [x] Padding, no-null behavior, no-direct-call fact, indirect OnCreate route, clone inventory, and no-split decision are preserved.
- [x] Wave2/Wave3/simroot and SelectionState/ButtonPane/HasSelection/SetEnabled/hover/visible aliases remain stale or rejected context only.
- [x] No third-party import or IDA mutation occurred.
- [x] One file was leased at a time; each lease was released immediately after its single scoped validator.
- [x] Exactly one scoped validator ran per changed by-* page; command/timestamp/result/warning/side-effect proof is recorded above.
- [x] Final waited refresh `000000009960` completed and all five generated outputs were inspected read-only.
- [x] No generated/coverage/tracker/validator/supervisor/lifecycle/audit file was manually edited.
- [x] No execute_report, dry-run/probe, registry/lifecycle, move, archive, or deletion command was run.

Implementation callback pass:

- [x] Separate supervisor authorization was recorded before the first by-* edit.
- [x] Every ledger Verification state is one of `applied`, `already-present`, or `excluded-with-reason`; none is blocked.
- [x] Current Target State, recommendations, scores, validator results, changed files, follow-up, and checklist are archive-neutral completed-callback state.
- [x] Real helper UID0004M9 and every scoped/final validator proof are recorded.
- [x] Every accepted item is applied, already present, or excluded with a concrete reason; B005 callback work is complete.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000010044","destination_path":"executed-b-agent-research/B005/0004BP-AddItemDialogUpdateActionButton-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0004BP-AddItemDialogUpdateActionButton-source-quality.md","timestamp":"2026-07-13T13:59:04-04:00","uid":"0004BP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
