** TARGET-REPORT-UID:00049S **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00049S ExchangeDialogUpdateButtonStates Source-Quality Report

Report timestamp: 2026-06-29T16:24:05-04:00  
Agent: B012  
Assignment: `B012-report-00049S-ExchangeDialogUpdateButtonStates-source-quality-20260629`  
Mode: report-only research; no leases; no by-* edits; no generated-output edits; no subagents.

## Target

- Target UID: `00049S`
- Target path: `by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md`
- Current metadata: `COMPLETION: 83`, `CONFIDENCE: 86`, `RECONSTRUCTABLE: TRUE`, `CANONICAL_OWNER: 00004R`, blank `EMITTER_UIDS`, blank C++.
- Current blocker text: packed state byte names and exact control enable/disable helper declarations remain descriptive.
- Current source route in target/support docs: `[UID:00004R] ExchangeDialog -> [UID:0000J9] ExchangeDialog`.

## Current Target State

UID00049S is currently a reconstructable, source-authored ExchangeDialog child with an exact function range and direct owner, but it is still marked non-emitting. The target's own status says `EMITTER_UIDS` and formal C++ remain blank only because packed state byte names and control helper names were not finalized in the prior split pass. Current MCP evidence and accepted support docs now resolve those blocker roles enough for first-draft source.

## Final Recommendation

Promote UID00049S from non-emitting metadata to a first-draft emitted child under direct owner `[UID:00004R] ExchangeDialog`.

- Keep `CANONICAL_OWNER: 00004R`.
- Keep `RECONSTRUCTABLE: TRUE`.
- Set `EMITTER_UIDS: 00004R`.
- Raise target score from `83/86` to `88/90`.
- Insert the formal C++ body in the target page and allow the generated route through `[UID:00004R] -> [UID:0000J9]`.
- Update support docs listed below so the state-byte/control-helper evidence is not left as a stale blocker.

The old blocker is resolved enough for implementation. Exact original member spellings are still inferred, but the workflow allows descriptive source-facing names for first-draft C++ when ownership, range, behavior, and emitter route are proven. The remaining name uncertainty is a score cap, not a reason to keep blank C++.

## MCP Session Evidence

Required current IDA MCP evidence was refreshed against session `46666bf7`; stale sessions `978e78c8` and `279422f0` were not used.

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize`: OK, protocol `2025-06-18`, server exposes 65 tools including `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, `entity_query`, and `int_convert`.
- `idb_list`: exactly one active session, `session_id:46666bf7`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, backend worker PID `20688`, `is_active:true`, `is_analyzing:false`, `owned:true`, `adopted:true`.
- `server_health(database=46666bf7)`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready with size `2067`.
- Corrected call detail: `server_health(session=46666bf7)` returned an error because the MCP schema requires `database`; the corrected `server_health(database=46666bf7)` call succeeded. This is not a MCP outage or busy state.

No `PAUSED_MCP_*` condition applies.

## Evidence Checked

- Current target by-memory page UID00049S.
- ExchangeDialog support docs: `[UID:00004R] by-class/ExchangeDialog.md`, `[UID:0000J9] by-file/ExchangeDialog.md`, aggregate `[UID:00014K] by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`, dispatcher `[UID:00014L]`, ready helper `[UID:00014P]`, amount setter `[UID:00049W]`, key/action/cancel siblings as leads, and vtable data `[UID:0003NE]`.
- Control/layout support docs: DialogPane, DialogPaneLayout, ControlPane, ClanNameInputDialog, and MusicControlDialogRefreshControlStates for inherited control lookup and control-state slot polarity.
- Executed B-agent reports: B001 UID00014K split report, B002 UID00014P ready-alert report, and B015 UID00014L dispatcher report. Active B003 UID00049Q was used as a lead only.
- Current generated output: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` after validator command id `000000000913`, read as lead material only.
- MCP calls in session `46666bf7`: `initialize`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, `entity_query`, and `int_convert`.

## Search And Prior Report Audit

Search terms checked across assigned reports, executed B-agent reports, target/support docs, trackers, and generated output included `00049S`, `0x004ad200`, `004ad2fd`, `ExchangeDialogUpdateButtonStates`, `UpdateButtonStates`, `sub_4AD200`, `+0x270`, `+0x271`, `+0x272`, `+0x278`, `+0x4c`, and `+0x50`.

- No direct executed B report with `TARGET-REPORT-UID:00049S` was found.
- Executed B001 `00014K-ExchangeDialog-empty-emitter-source-quality.md` is a creation/split lead only. It created UID00049S at `0x004ad200-0x004ad2fd` as a non-emitting child with `83/86`.
- Executed B002 `00014P-exchange-dialog-ready-alert-source-quality.md` is relevant support evidence. It records constructor/ready-alert state writes and says UID00049S reads `+0x270`, `+0x271`, `+0x272`, and `+0x278` to update controls `1`, `2`, `3`, and `6`.
- Executed B015 `00014L-ExchangeDialogPacketDispatcher-source-quality.md` is relevant support evidence for the source route, packet state roles, and the `RefreshSelectedControlAfterStateUpdate` wrapper.
- Active B003 `00049Q-ExchangeDialogOnButtonAction-source-quality.md` was treated as a lead only because it is not an executed accepted report.
- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` was read after a current generated refresh (`validator-command-id: 000000000913`, refreshed `2026-06-29T16:18:30-04:00`). UID00049S is still absent because the target `EMITTER_UIDS` and C++ are blank. Existing generated ExchangeDialog code already uses source-facing `GetControl(...)` and `SetEnabled(...)`.

## Positive Evidence

- Direct MCP evidence confirms a real function at `0x004ad200`, exact size `0xfd`, and no function at the target end address.
- The only incoming xref is the ExchangeDialog vtable/data slot at `0x00619d78`, matching a virtual control-state updater.
- The body reads only ExchangeDialog state bytes and uses the inherited DialogPane control manager to fetch ExchangeDialog controls.
- Accepted sibling docs already emit or document the same state fields used here.
- MCP evidence from `0x004ada20` resolves `+0x278` as an amount-decrease/confirm-lock flag, which was the remaining packed-state blocker for the confirm button branch.
- Existing support docs resolve control virtual slot `+0x4c` as enable and `+0x50` as disable.

## Negative Evidence

- No ordinary external code callers exist; this is expected for a vtable-routed method and is not a liveness blocker.
- MCP reports no direct callees because target calls control methods indirectly through vtable slots; this does not block source reconstruction because accepted support docs resolve the slot polarity.
- No direct executed B report exists for UID00049S; this assignment is the first target-specific source-quality report.
- No symbol-proof original member names exist for the packed state bytes; this remains a confidence cap but not a first-draft C++ blocker.

## Function Boundary And Split

Current MCP proves the existing target range and split are correct.

- `lookup_funcs`: `0x004ad200 -> sub_4AD200`, size `0xfd` / 253 bytes. `0x004ad2fd` is not a function. `0x004ad320 -> sub_4AD320`, size `0x493`.
- Neighbor inventory: `0x004ad0b0 -> sub_4AD0B0`, size `0x11a`; `0x004ad1d0 -> sub_4AD1D0`, size `0x24`; `0x004ad200 -> sub_4AD200`, size `0xfd`; `0x004ad320 -> sub_4AD320`, size `0x493`.
- `get_bytes 0x004ad2fd size 0x23` returned one NOP byte at `0x004ad2fd`, then the local jump table at `0x004ad300`, then `0xcc` padding before `0x004ad320`.
- The jump table dwords target `0x004ad2a3`, `0x004ad2d0`, `0x004ad291`, `0x004ad2f6`, `0x004ad291`, and `0x004ad291`.

Conclusion: no split repair is needed. The target owns the body through `0x004ad2fc`; the `0x004ad2fd-0x004ad320` region is alignment/jump-table/padding support before UID00014L, not a separate source child.

## Xrefs And Route

Current MCP xref evidence matches a virtual method slot and supports direct class ownership.

- `xrefs_to 0x004ad200`: exactly one data xref at `0x00619d78`.
- `get_bytes 0x00619d70 size 0x20`: includes `0x004ad200` at dword `0x00619d78`; nearby dwords include other ExchangeDialog method pointers.
- `entity_query 0x00619d70-0x00619da0`: named table anchor `0x00619d8c ??_7ExchangeDialog@@6B@_0` in the same vtable cluster.
- `callees 0x004ad200`: no direct callees enumerated because all control operations are indirect virtual calls.
- `xref_query from 0x004ad200`: no ordinary external code callees; target behavior is local control lookup/state branching plus indirect control state calls.

Recommended support edit: add the `0x00619d78 -> 0x004ad200 -> UID00049S UpdateButtonStates` slot fact to `[UID:0003NE] by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`.

## Decompiled Behavior

`analyze_function 0x004ad200 include_asm=false` reports `sub_4AD200`, prototype `int __thiscall(int this)` from decompiler recovery, size 253, 11 basic blocks, cyclomatic complexity 7, no direct callees, and one data xref at `0x00619d78`. The source-facing return should be `void`; the decompiler's `int` is an artifact of returning the last indirect virtual call result.

The decompilation fetches controls through the inherited DialogPane control manager at `this + 0x1fc`:

- Control id `1`: confirm/ready/OK button.
- Control id `3`: cancel button.
- Control id `2`: add item button.
- Control id `6`: local money edit control.

The function builds a state value from three ExchangeDialog state bytes:

- `this + 0x270`: local offer/ready-request state, recommended source-facing `m_localOfferPending`; contributes bit `4`.
- `this + 0x271`: local ready-confirmed state, recommended source-facing `m_localReadyConfirmed`; contributes bit `2`.
- `this + 0x272`: remote/peer ready-confirmed state, recommended source-facing `m_peerReadyConfirmed`; contributes bit `1`.
- `this + 0x278`: amount-decrease/confirm lock flag, recommended source-facing `m_amountDecreasePending`; gates only changes to control id `1`.

State behavior:

| State | Meaning | Control updates |
|---|---|---|
| `0` | neither side ready and no local offer pending | if `+0x278 == 0`, enable id `1`; enable ids `3`, `2`, and `6` |
| `1` | peer ready only | if `+0x278 == 0`, enable id `1`; enable id `3`; disable ids `2` and `6` |
| `2`, `4`, `5` | local ready/pending states that block local edit/add | if `+0x278 == 0`, disable id `1`; enable id `3`; disable ids `2` and `6` |
| `3`, `6`, `7`, and any other value | already-complete or unsupported combination | no state changes |

The branch table and disassembly confirm this exact case set. `cmp edx,5; ja default` sends states above `5` to no-op, and table index `3` also points to the no-op return block.

## State Field And Control Helper Resolution

The stale blocker names are now implementation-ready:

- `[UID:00014L] ExchangeDialogPacketDispatcher` already emits `m_peerReadyConfirmed`, `m_localReadyConfirmed`, and `m_localOfferPending` in case 5.
- `[UID:00014P] ExchangeDialogReadyAlertHelper` records the same ready-state cluster: `+0x270` local offer/ready-request, `+0x271` local ready-confirmed, and `+0x272` peer/remote ready-confirmed.
- `decompile 0x004ada20` proves `+0x274` is the local exchange amount and `+0x278` is set when the new local amount is less than the previous amount. The helper disables control id `1`, schedules timer/event `4096` for `10000` ms, and then writes the new amount. This resolves `+0x278` as an amount-decrease pending/confirm-lock flag for UID00049S.
- Existing accepted support for control virtual slots resolves `+0x4c` as enable / `SetEnabled(true)` and `+0x50` as disable / `SetEnabled(false)`. Corroborating docs include `ClanNameInputDialog`, `MusicControlDialogRefreshControlStates`, and executed control-state reports.
- Existing generated code uses `ControlPane *control = GetControl(...)` and `control->SetEnabled(...)`; the recommended formal insertion follows that local C++ surface.

No in-scope blocker remains. Original symbolic names may differ, but the chosen names are descriptive, consistent with already emitted ExchangeDialog code, and sufficient for first-draft generated source.

## Ownership Ranking

| Rank | Candidate | Decision |
|---|---|---|
| 1 | `[UID:00004R] ExchangeDialog` | Direct owner. The method reads ExchangeDialog state bytes, uses ExchangeDialog controls, and is in the ExchangeDialog vtable cluster. |
| 2 | `[UID:0000J9] by-file/ExchangeDialog.md` | Correct source file route, not direct child owner. |
| 3 | DialogPane / DialogControlManager | Rejected as owner. Target only uses inherited control lookup machinery at `+0x1fc`; it does not define generic dialog-control behavior. |
| 4 | ControlPane / button classes | Rejected as owner. Target invokes control-state virtuals but does not own those helpers. |

The current `CANONICAL_OWNER: 00004R` is correct.

## Heuristic / Inference Reanalysis And Validation

The only material inference left is source-facing naming, not behavior. I rejected raw names such as `byte_270`, `byte_278`, `sub_4AD200`, and decompiler temporaries because the workflow requires plausible source-facing names once behavior is known. The recommended names were validated against current evidence:

- `m_localOfferPending`, `m_localReadyConfirmed`, and `m_peerReadyConfirmed` are already used by emitted/support ExchangeDialog packet handling for the same offsets and state transitions.
- `m_amountDecreasePending` is inferred from direct MCP evidence in `SetExchangeAmount`: the helper sets `+0x278` only when the local amount is reduced, disables the confirm button, and starts a timer before UID00049S suppresses confirm-button state changes while the byte is nonzero.
- `UpdateButtonStates` is the target's existing source-facing role and matches the selected-control refresh path that invokes this vtable slot.
- `GetControl(...)` and `SetEnabled(...)` match current generated project style and accepted control-slot polarity evidence.

Rejected alternatives:

- DialogPane or ControlPane ownership was rejected because the target consumes inherited control lookup and control methods but operates entirely on ExchangeDialog-specific state.
- Keeping blank C++ was rejected because the prior blocker has been resolved to implementation-ready descriptive names and exact branch behavior.
- Splitting the switch table/padding into a child was rejected because the bytes are local table/alignment support for this function and the next real function starts at `0x004ad320`.

## Source Placement

Recommended placement is the existing source route:

- Target UID00049S emits to owner `[UID:00004R] ExchangeDialog`.
- Owner `[UID:00004R]` emits through `[UID:0000J9] by-file/ExchangeDialog.md`.
- Generated output should therefore refresh into `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.

No alternate source file is indicated by current MCP or support docs.

## Score And Metadata Recommendation

Recommended target metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00004R
EMITTER_UIDS: 00004R
```

Score rationale:

- Completion improves because exact bounds, branch behavior, control ids, state bits, slot polarity, and source route are now resolved.
- Confidence improves because session `46666bf7` directly confirms the body, xrefs, vtable pointer, neighboring functions, switch table, and sibling state writers.
- Score remains below 95 because exact original member names and exact original button/control class declarations remain inferred rather than symbol-proven.

## First-Draft C++ Recommendation

UID00049S is eligible for code insertion under the project C++ gate:

- `RECONSTRUCTABLE: TRUE`.
- Nonblank emitter route is now justified: `EMITTER_UIDS: 00004R`.
- Recommended score `88/90` gives combined `89`, above the `>85` code-entry threshold.
- The code below is limited to the exact target body behavior and does not claim sibling code.

Use this exact formal `RECONSTRUCTION_CPP CODE` insertion text for the target:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ExchangeDialog::UpdateButtonStates()
{
    ControlPane *confirmButton = GetControl(1);
    ControlPane *cancelButton = GetControl(3);
    ControlPane *addItemButton = GetControl(2);
    ControlPane *moneyEdit = GetControl(6);

    unsigned int state = 0;
    if (m_localOfferPending != 0) {
        state |= 4;
    }
    if (m_localReadyConfirmed != 0) {
        state |= 2;
    }
    if (m_peerReadyConfirmed != 0) {
        state |= 1;
    }

    switch (state) {
    case 0:
        if (m_amountDecreasePending == 0) {
            confirmButton->SetEnabled(true);
        }
        cancelButton->SetEnabled(true);
        addItemButton->SetEnabled(true);
        moneyEdit->SetEnabled(true);
        break;

    case 1:
        if (m_amountDecreasePending == 0) {
            confirmButton->SetEnabled(true);
        }
        cancelButton->SetEnabled(true);
        addItemButton->SetEnabled(false);
        moneyEdit->SetEnabled(false);
        break;

    case 2:
    case 4:
    case 5:
        if (m_amountDecreasePending == 0) {
            confirmButton->SetEnabled(false);
        }
        cancelButton->SetEnabled(true);
        addItemButton->SetEnabled(false);
        moneyEdit->SetEnabled(false);
        break;

    default:
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: If the owner class later standardizes a different field spelling for `+0x278`, keep the same behavior and update only the source-facing name consistently across UID00049S and UID00049W.

## Recommended Target Doc Edits

For `by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md`:

- Update metadata to the recommended score and `EMITTER_UIDS: 00004R`.
- Replace the stale no-code blocker with the session `46666bf7` evidence from this report.
- Add the exact formal C++ body above.
- Document the controls and state cases:
  - id `1` confirm/ready/OK.
  - id `2` add item.
  - id `3` cancel.
  - id `6` local money edit.
  - `+0x270`, `+0x271`, `+0x272`, and `+0x278` as above.
- Record `0x00619d78` as the vtable data xref and `0x004ad2fd-0x004ad320` as alignment/jump-table/padding before UID00014L.

## Recommended Support Doc Edits

These are report-only recommendations; do not apply them until the implementation callback leases the files.

1. `by-class/ExchangeDialog.md`
   - Update the UID00049S method row from "non-emitting until names are final" to first-draft emitted method.
   - Add `+0x278` as the amount-decrease/confirm-lock flag, cross-referenced to UID00049W and UID00049S.
   - Preserve the note that exact original field spellings remain inferred.

2. `by-file/ExchangeDialog.md`
   - Add UID00049S to the emitted ExchangeDialog method inventory and generated source route.
   - Mention that the control-state updater uses `GetControl(1/2/3/6)` and `SetEnabled(...)`.

3. `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
   - Update the UID00049S child row and aggregate caveat so it no longer claims the updater is held blank by unresolved helper names.

4. `by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md`
   - Add support evidence that `0x004ada20` writes `+0x274` as the local amount, sets `+0x278` when the amount decreases, disables control id `1` through slot `+0x50`, and schedules the timer/event used to hold the confirm button lock.
   - This support edit resolves the UID00049S `+0x278` name role without requiring UID00049W to emit in the same callback.

5. `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`
   - Add the slot fact `0x00619d78 -> 0x004ad200 -> UID00049S ExchangeDialog::UpdateButtonStates`.

No required edit is recommended for `[UID:00014L] ExchangeDialogPacketDispatcher` or `[UID:00014P] ExchangeDialogReadyAlertHelper`; they already contain compatible state-field evidence. A cross-link may be added during implementation only if the editor is already touching those files for another accepted item.

## Out-Of-Scope Items Explicitly Excluded

- Proving original proprietary member spelling for the state bytes is out of scope for this source-quality repair. Descriptive source-facing names are implementation-ready and consistent with already emitted ExchangeDialog code.
- Reclassifying or emitting UID00049W, UID00049V, UID00049U, or other ExchangeDialog siblings is out of scope except for the support fact needed to name `+0x278`.
- Refactoring generated C++ style outside the UID00049S body is out of scope.
- Editing generated reports, manual coverage reports, tool/validator state, IDA DB state, supervisor ledgers, or executed archives is prohibited and was not done.

## Numeric Conversion Notes

MCP `int_convert` was used successfully for the documented offsets and sizes:

- `0xfd` = 253, `0x23` = 35, `0x1fc` = 508, `0x4c` = 76, `0x50` = 80.
- `0x270` = 624, `0x271` = 625, `0x272` = 626, `0x278` = 632, `0x27c` = 636.
- `0x3ec0` = 16064, `0x00619d78` = 6397304, `0x004ad200` = 4903424.

Local filesystem command `python .\tools\int_convert.py ...` failed with exit `1` because `E:\NTK\GhidraBridge\tools\int_convert.py` does not exist in this checkout, and `rg --files` found no `int_convert.py` or `int_convert_readme` file. This does not affect MCP-backed target evidence; implementation can either use MCP `int_convert` as above or restore the missing local helper before documenting more conversions.

## Validators

No validators were run in this report-only assignment. Recommended implementation-time validator batch after leased edits:

- Run the target/support markdown validators for all edited by-* files.
- Run the generated refresh/validator path that updates `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Confirm generated `ExchangeDialog.cpp` includes UID00049S as emitted code and that no unrelated generated churn is present.

## Leases

No leases were taken. This was required by the report-only assignment.

## Changed Files

- Created `tools/leaser/Agents/Agent-B012/research/00049S-ExchangeDialogUpdateButtonStates-source-quality.md`.

No target/support by-* docs, generated reports, project-level generated reports, manual coverage reports, tool/validator state, IDA DB files, supervisor ledgers, or executed archives were edited.

## Claim And Incorporation Ledger

Implementation callback note: supervisor MCP recovery override replaced stale session `46666bf7` with current session `dad3692b`. Callback checks used `dad3692b` for `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, and `decompile`.

| Claim ID | Claim | Evidence | Incorporation / verification state |
|---|---|---|---|
| C-00049S-01 | Target range `0x004ad200-0x004ad2fd` is exact. | MCP `lookup_funcs`, `get_bytes`, neighboring `entity_query`, and switch-table bytes. | Applied: target status and MCP evidence now record session `dad3692b`, `sub_4AD200` size `0xfd`, and `0x004ad2fd` as not a function. |
| C-00049S-02 | `0x004ad2fd-0x004ad320` is alignment/jump-table/padding before UID00014L. | MCP `get_bytes 0x004ad2fd size 0x23`. | Applied: target boundary notes and aggregate row record the local switch-table/alignment/padding before UID00014L. |
| C-00049S-03 | The only incoming target reference is vtable/data pointer `0x00619d78`. | MCP `xrefs_to 0x004ad200`; vtable bytes around `0x00619d70`. | Applied: target evidence and UID0003NE vtable page record `0x00619d78 -> 0x004ad200 -> UID00049S`. |
| C-00049S-04 | Direct owner remains ExchangeDialog UID00004R. | Vtable cluster, state-field reads, ExchangeDialog controls, source route docs. | Applied: target metadata kept `CANONICAL_OWNER:00004R`; support docs preserve direct class ownership. |
| C-00049S-05 | Source route remains UID00004R -> UID0000J9. | Current target/class/file docs and generated output route. | Applied: target `EMITTER_UIDS:00004R`; class/file/aggregate pages record the emitted route. |
| C-00049S-06 | Control ids are 1 confirm/ready/OK, 2 add item, 3 cancel, 6 local money edit. | MCP decompile/disasm plus ExchangeDialog class/file docs and sibling methods. | Applied: target behavior, class data/control notes, and file packet/control model record controls `1/2/3/6`. |
| C-00049S-07 | `+0x270`, `+0x271`, `+0x272` are local offer pending, local ready confirmed, peer ready confirmed. | MCP target reads plus UID00014L and UID00014P support docs. | Applied: target behavior/C++ and class state-field notes use `m_localOfferPending`, `m_localReadyConfirmed`, and `m_peerReadyConfirmed`. |
| C-00049S-08 | `+0x278` gates confirm-button updates and is set by local amount decrease handling. | MCP target reads; MCP `decompile 0x004ada20` sets `+0x278`, disables id `1`, schedules timer. | Applied: target, class, file, aggregate, and UID00049W support doc record `m_amountDecreasePending` / amount-decrease confirm-lock behavior. |
| C-00049S-09 | Slot `+0x4c` is enable and slot `+0x50` is disable. | Current support docs and accepted control-state reports; target disasm matches expected UI behavior. | Applied: target evidence and formal C++ use `SetEnabled(true/false)`; class/file docs record helper polarity. |
| C-00049S-10 | States `0`, `1`, `2`, `4`, and `5` are the only mutating cases; `3`, `6`, `7`, and default are no-op. | MCP decompile/disasm and jump table. | Applied: target behavior table and formal C++ switch preserve exact state cases. |
| C-00049S-11 | The old blank-C++ blocker is resolved enough for first-draft source. | Current MCP evidence plus support docs resolve helper polarity and packed-state roles. | Applied: target raised to `88/90`, emitter set to `00004R`, formal C++ inserted, support docs updated from non-emitting wording. |
| C-00049S-12 | Remaining original symbolic-name uncertainty is a score cap, not a code blocker. | Project C++ gate and existing descriptive ExchangeDialog generated code. | Applied: target/class/file/aggregate caveats preserve inferred-name score cap without treating it as a first-draft blocker. |
| C-00049S-13 | Vtable support page lacks the explicit UID00049S slot fact. | Read of UID0003NE plus MCP bytes. | Applied: UID0003NE layout, IDA evidence, and changes sections include the `0x00619d78` slot fact. |
| C-00049S-14 | Generated ExchangeDialog source currently lacks UID00049S. | `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`, command id `000000000913`. | Applied: validator command `000000000948` refreshed generated `ExchangeDialog.cpp`; header is current and generated file includes UID00049S at line 39. |

## Implementation Tracking Checklist

- [x] Lease only files about to be edited immediately; expected files are the target page and the support docs listed above. Proof: B012 leased the six required by-* files, edited them, validated them, and released all six successfully.
- [x] Update `by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md` metadata to `88/90`, `RECONSTRUCTABLE: TRUE`, `CANONICAL_OWNER: 00004R`, `EMITTER_UIDS: 00004R`. Proof: target metadata now has `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00004R`, and `EMITTER_UIDS:00004R`; validator `000000000942` ok `1`.
- [x] Insert the formal `RECONSTRUCTION_CPP CODE` block from this report into the target page. Proof: target formal block contains `void ExchangeDialog::UpdateButtonStates()`; generated `ExchangeDialog.cpp` command `000000000948` includes UID00049S.
- [x] Replace stale no-code blocker text with session `dad3692b` MCP evidence, vtable xref, exact state cases, and control-helper polarity. Proof: target Status/MCP Evidence/C++ disposition/Behavior sections now record `dad3692b`, `0x00619d78`, states `0/1/2/4/5`, no-op default states, and `+0x4c/+0x50` polarity.
- [x] Update `by-class/ExchangeDialog.md` method row and state field table for UID00049S and `+0x278`. Proof: class method row marks UID00049S first-draft `88/90`; Data And Controls names `+0x278` as amount-decrease/confirm-lock and cross-links UID00049W/UID00049S; validator `000000000943` ok `1`.
- [x] Update `by-file/ExchangeDialog.md` to include UID00049S in the emitted route/method inventory. Proof: file Packet And Control Model and Changes sections list first-draft `ExchangeDialog::UpdateButtonStates()` through `ExchangeDialog.cpp`; validator `000000000944` ok `1`.
- [x] Update `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` child row/caveat for UID00049S. Proof: aggregate child row now says UID00049S is first-draft emitting `88/90`; aggregate caveat no longer treats unresolved names as blocking UID00049S; validator `000000000945` ok `1`.
- [x] Update `by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md` with the `+0x278` amount-decrease/confirm-lock support fact. Proof: UID00049W Behavior and Changes sections document `+0x274`, `+0x278`, control id `1` slot `+0x50`, timer/event `0x1000`, and UID00049S support use; validator `000000000946` ok `1`.
- [x] Update `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md` with `0x00619d78 -> UID00049S`. Proof: UID0003NE Layout/IDA Evidence/Changes sections include `0x00619d78 -> 0x004ad200 -> UID00049S`; validator `000000000947` ok `1`.
- [x] Run the required markdown/source validators for all edited by-* files and generated ExchangeDialog output. Proof: required validators `000000000942` through `000000000947` each exited `0` with ok `1`; final target rerun `000000000948 --wait-generated` exited `0` with ok `1`.
- [x] Confirm generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` includes UID00049S and preserves unrelated generated content. Proof: generated header has `validator-command-id: 000000000948` and `validator-refreshed-at: 2026-06-29T17:06:04-04:00`; UID00049S appears at generated line 39 with `ExchangeDialog::UpdateButtonStates()`.
- [x] Release all leases immediately after the edit/validator batch. Proof: `python .\tools\leaser\leaser.py B012 unlease ...` returned `Success` for all six leased by-* files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00049S-ExchangeDialogUpdateButtonStates-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/00049S-ExchangeDialogUpdateButtonStates-source-quality.md","timestamp":"2026-06-29T17:10:55","uid":"00049S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
