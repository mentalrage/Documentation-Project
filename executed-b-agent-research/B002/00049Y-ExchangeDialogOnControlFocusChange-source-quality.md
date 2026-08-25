** TARGET-REPORT-UID:00049Y **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00049Y ExchangeDialog OnControlFocusChange Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: update [UID:00049Y] `by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md` with the fresh IDA MCP evidence from session `46666bf7`, keep `CANONICAL_OWNER:00004R`, keep `RECONSTRUCTABLE:TRUE`, and set `EMITTER_UIDS:00004R`.
- Recommended score after documentation repair: `COMPLETION:88`, `CONFIDENCE:90`.
- Final disposition: source-authored ExchangeDialog virtual/control-focus callback. It normalizes the local money edit text when focus leaves control `6`, submits the parsed amount through `ExchangeDialogSubmitExchangeAmount`, then updates the inherited DialogPane hover/active-control slot.
- The previous in-scope blocker around text-normalization helper identities is resolved for documentation: `sub_498C10` is the `TextEditControlPane` read-text forwarder to `TextEditPane::CopyWideText`, `unknown_libname_24` is CRT `_wtol`, `sub_498CA0` is the text-edit replacement/set-text wrapper, and `sub_49FC00` is the inherited `DialogPane::SetHoverControl(int)` style helper.
- Populate the formal `RECONSTRUCTION_CPP CODE` block with the exact first-draft insertion text in this report. The sibling/declaration issue is not a blocker for this target: [UID:00049V] `SubmitExchangeAmount` and [UID:00049W] `SetExchangeAmount` already have stable source-facing call names, and existing generated `ExchangeDialog.cpp` already calls `SetExchangeAmount(0)` from [UID:00014L] without requiring those sibling bodies to emit first.

## Supporting Research

## Target
- Target UID: `00049Y`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md`.
- Assigned report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00049Y-ExchangeDialogOnControlFocusChange-source-quality.md`.
- Assignment ID from `goal.md`: `B002-report-00049Y-ExchangeDialogOnControlFocusChange-source-quality-20260629`.
- Current target page state read before this report: `COMPLETION:82`, `CONFIDENCE:87`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP CODE`.
- Current generated route context: [UID:00004R] `ExchangeDialog` routes through [UID:0000J9] `ExchangeDialog` / `NexusTK/ui/dialogs/ExchangeDialog.cpp`. This target can now emit through [UID:00004R] after adding the declaration/call-surface notes below.

## Report Scope And Prior Research Search
- Searched current docs, support docs, supervisor assignments, and executed B-agent research for `TARGET-REPORT-UID:00049Y`, `00049Y`, `004adfb0`, `004ae053`, `ExchangeDialogOnControlFocusChange`, `sub_4ADFB0`, `4ADFB0`, `OnControlFocusChange`, `ExchangeDialog`, `ExchangeMoneyEditControlPane`, `OnKeyEvent`, `SubmitExchangeAmount`, and `SetExchangeAmount`.
- No prior direct executed B-agent report for `TARGET-REPORT-UID:00049Y` was found.
- Support leads used: B001 aggregate research for [UID:00014K] `ExchangeDialog`, B002 adjacent-source research for [UID:00014P], the current target page, [UID:00004R] `ExchangeDialog`, [UID:0000J9] `ExchangeDialog` file docs, current generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`, [UID:00004T] `ExchangeMoneyEditControlPane`, [UID:00011H] `TextEditControlPane`, [UID:00003T] `DialogPane`, and sibling exact children [UID:00049T], [UID:00049V], and [UID:00049W].
- This report is the first direct B002 source-quality report for `00049Y`. Existing docs were treated as leads and rechecked against current MCP evidence.

## Current IDA MCP Evidence
- MCP listener/session used: fresh session `46666bf7`, as provided by supervisor recovery. Stale session `978e78c8` was not used after recovery.
- Current `idb_list` on session `46666bf7`: one active/adopted backend worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, worker PID `20688`, `is_analyzing:false`, active `true`.
- Supervisor-provided bounded `lookup_funcs 0x004adfb0` returned `sub_4ADFB0`, size `0xa3`; this report rechecked the same session before updating the recommendation.
- `server_health` on session `46666bf7`: status `ok`; IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; `auto_analysis_ready:true`; `hexrays_ready:true`; strings cache ready with size `2067`.
- `tools/list` was checked before use. Bounded read-only tools used included `lookup_funcs`, `decompile`, `disasm`, `analyze_function`, `analyze_component`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `get_string`, `entity_query`, and `int_convert`.
- Current sibling/component pass on session `46666bf7` covered [UID:00049T] `0x004ad7d0`, [UID:00049V] `0x004ad960`, [UID:00049W] `0x004ada20`, and this target `0x004adfb0`.

## Function Facts
- `lookup_funcs 0x004adfb0`: `sub_4ADFB0`, size `0xa3` / decimal `163` (decimal verified through `int_convert`, size 4).
- `lookup_funcs 0x004ae052`: inside `sub_4ADFB0`.
- `lookup_funcs 0x004ae053`: not a function.
- `analyze_function 0x004adfb0`: prototype `void __thiscall(int this, int)`, size `163`, no code callers, one data xref at `0x00619d84`, basic blocks `10`, cyclomatic complexity `6`.
- `decompile 0x004adfb0`: Hex-Rays prototype `void __thiscall sub_4ADFB0(int this, int a2)`.
- `disasm 0x004adfb0`: normal stack-cookie prologue, local stack allocation `0x24` / decimal `36`, final `retn 4` at `0x004ae050`.
- `get_bytes 0x004adfb0 size 0xa3`: exact function bytes end with the security-cookie check and `c2 04 00`, matching a thiscall-like member with one stack argument.
- `get_bytes 0x004adfa0 size 0x70`: four `0xcc` bytes precede the function at `0x004adfac-0x004adfb0`.
- `get_bytes 0x004ae053 size 0x0d`: thirteen `0xcc` bytes follow the function at `0x004ae053-0x004ae060`.
- `entity_query` over `0x00619d70-0x00619da0`: nearby vtable-area name `??_7ExchangeDialog@@6B@_0` at `0x00619d8c`, corroborating the ExchangeDialog vtable area around the data reference.

## Control Flow And Behavior
- The function obtains control id `6` through the inherited control manager at `this+0x1fc` / decimal `508`, using the manager vtable slot `+0x10` / decimal `16`.
- The focus-leave normalization branch runs only when all three conditions are true:
  - the inherited active/hover control id at `this+0x214` / decimal `532` is `6`;
  - the incoming control id argument is not `6`;
  - byte `control+0x101` / decimal `257` on the money edit control is nonzero.
- When those conditions hold, the function copies text from the money edit control through `sub_498C10(control, stackBuffer, 10)`, parses it with CRT `_wtol`, and submits the amount through `sub_4AD960(this, amount)`.
- If the parsed amount is less than or equal to zero, the function first replaces the money edit text with the shared wide literal `L"0"` at `0x00610634`, submits amount `0`, and then proceeds to the final focus update.
- Whether or not the money branch runs, the function calls `sub_49FC00(this, a2)` before returning. Current support docs identify this inherited helper as `DialogPane::SetHoverControl(int)` / active-control update.
- Current decompile/disassembly shows the positive path tests `_wtol(amountText) > 0` and then obtains the submitted positive value with a second `_wtol(amountText)` call. The formal insertion text below preserves that source shape rather than collapsing it to a single parsed local.

## Helper Identity Recheck
- `sub_498C10`: `lookup_funcs` size `0xf`; decompile shows `return sub_58E380(this[67], a2, a3);`. With `this[67]` equal to offset `+0x10c`, this matches [UID:0002OA] `TextEditControlPaneReadTextForwarder`, forwarding to [UID:0002O9] `TextEditPane::CopyWideText`.
- `unknown_libname_24` at `0x005cea43`: current docs identify it as the Microsoft CRT `_wtol` wrapper [UID:0001O5]. The IDA disassembly also comments this as a Microsoft Visual C runtime library call.
- `sub_498CA0`: decompile shows a wrapper over embedded editor operations that clears/replaces text through the `TextEditPane` object at `this[67]`; source-facing role is `TextEditControlPane::SetText`, matching existing generated use of `TextEditControlPane::SetText(...)`.
- `sub_4AD960`: sibling exact child [UID:00049V] `ExchangeDialogSubmitExchangeAmount`. `xrefs_to 0x004ad960` includes constructor/setup at `0x004acff9`, [UID:00049T] `OnKeyEvent` at `0x004ad845`, and this target at `0x004ae030`.
- `sub_49FC00`: decompile reads and writes `this+0x214`, deactivates the prior control if not `-1`, activates the new control if not `-1`, and writes the new id. This matches the accepted [UID:00003T] `DialogPane::SetHoverControl(int controlId)` alias.
- `get_string 0x00610634`: value `"0"`. `xref_query` shows it is a shared literal, not owned by this target.
- `@__security_check_cookie@4`: compiler security-cookie support only.

## Xref Evidence
- `xrefs_to 0x004adfb0`: one data xref from `0x00619d84`; no code xrefs.
- `xref_query target 0x004adfb0 direction to`: one data edge `0x00619d84 -> 0x004adfb0`.
- `xref_query target 0x00498c10 direction to`: total `70` code xrefs, including this target at `0x004adff6` and sibling [UID:00049T] at `0x004ad819`.
- `xref_query target 0x0049fc00 direction to`: total `208` code xrefs, including this target at `0x004ae03c`; this is broad DialogPane infrastructure, not ExchangeDialog-specific ownership.
- `xref_query target 0x00610634 direction to`: total `36` data xrefs, including this target at `0x004ae021`; the literal is shared support data.
- The absence of code callers plus the vtable/data reference supports a virtual callback body rather than an ordinary directly invoked helper.

## Sibling / Declaration / Emitter Investigation
- [UID:00049T] `ExchangeDialogOnKeyEvent` (`0x004ad7d0`, size `0x8f`) is another ExchangeDialog vtable callback. Current `analyze_component` reports prototype `char __thiscall(unsigned int *this, int)`, calls the inherited key handler, reads control `6` text with `sub_498C10`, parses `_wtol`, and calls [UID:00049V] `SubmitExchangeAmount` on digit-key input. Its non-emitting status does not block `00049Y`; it shares the same `ReadText`/`_wtol`/`SubmitExchangeAmount` helper surface but is independently a key-event callback with adjusted `this - 40` ABI details.
- [UID:00049V] `ExchangeDialogSubmitExchangeAmount` (`0x004ad960`, size `0xb6`) is the stable sibling method directly called by this target. Current MCP xrefs are constructor/setup `0x004acff9`, [UID:00049T] at `0x004ad845`, and this target at `0x004ae030`. Decompile confirms it first calls [UID:00049W] `SetExchangeAmount(amount)`, then sends opcode `0x4A` subcommand `3` with exchange id `this+0x26c` and amount, or fallback subcommand `4` with only exchange id. The method name and call contract are sufficiently stable for `00049Y` formal C++ to call `SubmitExchangeAmount(amount)`.
- [UID:00049W] `ExchangeDialogSetExchangeAmount` (`0x004ada20`, size `0x64`) is the amount-state sibling. Current MCP confirms amount field `this+0x274` / decimal `628`, byte `this+0x278` / decimal `632`, timer subobject `this+0xa4` / decimal `164`, timer id `0x1000` / decimal `4096`, and delay `10000` / `0x2710`. Existing generated `ExchangeDialog.cpp` already calls `SetExchangeAmount(0)` from [UID:00014L] while [UID:00049W] remains blank in by-memory docs, proving sibling non-emission is handled by declaration/support-surface coordination rather than by suppressing this target's emitter.
- [UID:00004R] `ExchangeDialog` class docs already route to [UID:0000J9] `ExchangeDialog` file docs with `EMITTER_UIDS:0000J9`, and `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` already contains emitted ExchangeDialog method bodies plus covered-by markers. Adding `EMITTER_UIDS:00004R` to this child is the correct route because child method emission flows through the class owner and then to the file page.
- The only declaration/support notes needed for implementation are local and concrete: declare `ExchangeDialog::OnControlFocusChange(int controlId)`, use `TextEditControlPane::ReadText(wchar_t *, short)`, use `TextEditControlPane::SetText(const wchar_t *)`, call `SubmitExchangeAmount(unsigned int)`, call inherited `SetHoverControl(int)`, and accept `TextEditControlPane::m_editActive` as the source-facing field alias for byte `+0x101`.

## Heuristic / Inference Reanalysis And Validation
- Function-name inference:
  - Best source-facing name remains `ExchangeDialog::OnControlFocusChange(int controlId)` because the function is vtable-routed, takes one integer control id argument, and delegates to the inherited focus/hover-control update after special ExchangeDialog money-control handling.
  - Rejected alternatives: a standalone money-submit helper, a TextEditControlPane method, a DialogPane method, a packet handler, or a compiler/runtime artifact.
  - Validation: the target body is owner-specific before the inherited DialogPane call because it checks ExchangeDialog control id `6` and calls `ExchangeDialogSubmitExchangeAmount`.

- Money-control semantics:
  - Best inference: control id `6` is the local money edit control documented by `ExchangeMoneyEditControlPane`; the branch fires when focus leaves that control and its wrapper/editor state-sync guard is set.
  - Rejected alternatives: remote amount control id `9`, item-list controls `5` or `8`, or a generic text field. Only id `6` is fetched and compared in this function, and support docs consistently assign id `6` to the local money edit.

- Text-normalization helpers:
  - Best inference: read text with the inherited TextEditControlPane forwarder, parse with CRT `_wtol`, set displayed text to `L"0"` only for non-positive parsed values, then submit the amount.
  - Rejected alternatives: packet-string conversion, custom parser, UTF-8 conversion helper, or ExchangeDialog-specific text-normalization helper. Current MCP shows direct TextEditControlPane wrappers and CRT parsing.

- Source field names:
  - Best inference: `this+0x214` should continue to use the inherited DialogPane active/hover-control slot name already documented in `DialogPane`; `control+0x101` should continue to use the inherited TextEditControlPane state-sync/guard wording already documented in TextEditControlPane and ExchangeMoneyEditControlPane.
  - Remaining caution: exact original member names are not recoverable from this target alone. This is no longer a target documentation blocker because the field roles are validated by the support pages and current MCP.

## Ranked Ownership Analysis
1. [UID:00004R] `ExchangeDialog`: strongest and recommended canonical owner. The function uses ExchangeDialog control ids, reads inherited DialogPane state through an ExchangeDialog instance, calls ExchangeDialog amount submission, and is referenced from the ExchangeDialog vtable area.
2. [UID:0000J9] `ExchangeDialog` file: correct source route/emission root for the class, but not the narrow semantic owner.
3. [UID:00003T] `DialogPane`: support owner for the final `SetHoverControl` helper and inherited fields, but the function's owner-specific branch and vtable placement are ExchangeDialog-specific.
4. [UID:00004T] `ExchangeMoneyEditControlPane` and [UID:00011H] `TextEditControlPane`: support owners for the control object and text helpers, not owners of the callback.
5. CRT/runtime: owns `_wtol` and security-cookie mechanics only.

## Source Placement
- Keep target canonical owner as [UID:00004R] `ExchangeDialog`.
- Set generated source route as [UID:00049Y] -> [UID:00004R] `ExchangeDialog` -> [UID:0000J9] `ExchangeDialog` -> `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Set `EMITTER_UIDS:00004R` for this target. The body references stable support/class surfaces and does not require [UID:00049T], [UID:00049V], or [UID:00049W] to emit first.
- Do not route this target directly to the file UID as canonical owner, to DialogPane, or to TextEditControlPane.

## Range / Split / Reclassification Analysis
- Keep the existing exact range: `0x004adfb0-0x004ae053` half-open, IDA start `0x004adfb0`, size `0xa3`, final instruction ending at `0x004ae052`.
- The previous four bytes `0x004adfac-0x004adfb0` are padding after [UID:00014P] `ExchangeDialogReadyAlertHelper`.
- The following thirteen bytes `0x004ae053-0x004ae060` are padding before the next modeled region.
- Do not split this target. The body is one coherent callback with one owner and one final inherited focus update.
- Do not merge it back into [UID:00014K] `ExchangeDialog` aggregate. The exact child page is valid and already separated.
- Do not reclassify as compiler-generated, runtime, ignored, or raw helper. It has real source behavior and owner-specific UI semantics.

## Positive Evidence Summary
- Current MCP validates the exact function start, size, and boundary.
- Current MCP validates one vtable/data xref and no code callers, matching a virtual callback.
- The vtable-area name near the data reference is `ExchangeDialog`, supporting the class owner.
- The body's constants match known ExchangeDialog controls: id `6` local money edit and `L"0"` fallback text.
- Helper identities are now grounded in current decompilation and support docs: TextEditControlPane read forwarder, CRT `_wtol`, TextEditControlPane set-text wrapper, ExchangeDialog submit amount, and DialogPane focus update.
- Source route through ExchangeDialog/ExchangeDialog.cpp is already established by class/file docs.

## Negative Evidence Summary
- No direct code caller proves the original C++ call syntax or exact virtual method spelling.
- The exact original source spelling for the TextEditControlPane active byte at `+0x101` is not symbol-recovered. The report resolves this for emission with the field alias `m_editActive`, based on the documented active/show-state role and the accepted `SetEditActiveState` naming family.
- [UID:00049T], [UID:00049V], and [UID:00049W] remain useful support pages for later class-wide cleanup, but their current non-emitting status is not evidence against emitting this callback. Existing generated ExchangeDialog code already relies on sibling declarations and accepted class method names.
- These negatives keep the recommendation conservative at `88/90`; they do not justify blank `EMITTER_UIDS` or blank formal C++ for this target.

## First-Draft C++ Recommendation
- Recommended formal C++ status for the target page: populate `RECONSTRUCTION_CPP CODE` with the exact insertion text below.
- This is not illustrative or sample code. It is the formal first-draft reconstruction recommended for supervisor-approved insertion.

```cpp
void ExchangeDialog::OnControlFocusChange(int controlId)
{
    TextEditControlPane *moneyEdit =
        static_cast<TextEditControlPane *>(GetControl(6));

    if (m_activeControlId == 6 && controlId != 6 && moneyEdit->m_editActive) {
        wchar_t amountText[16];
        moneyEdit->ReadText(amountText, 10);

        unsigned int amount = 0;
        if (_wtol(amountText) > 0) {
            amount = static_cast<unsigned int>(_wtol(amountText));
        }

        if (amount == 0) {
            moneyEdit->SetText(L"0");
        }

        SubmitExchangeAmount(amount);
    }

    SetHoverControl(controlId);
}
```

- Required declaration/support alignment for this insertion: `ExchangeDialog::OnControlFocusChange(int controlId)` must be declared on the ExchangeDialog surface; `SubmitExchangeAmount(unsigned int)` is the sibling method name for [UID:00049V]; `TextEditControlPane::ReadText` maps to [UID:0002OA]/[UID:0002O9]; `TextEditControlPane::SetText` maps to `sub_498CA0`; `m_activeControlId` maps to DialogPane offset `+0x214`; `m_editActive` maps to TextEditControlPane byte `+0x101`; and `SetHoverControl(int)` maps to [UID:00003T] `sub_49FC00`.

## Score And Metadata Recommendation
- `CANONICAL_OWNER`: keep `00004R`.
- `RECONSTRUCTABLE`: keep `TRUE`.
- `EMITTER_UIDS`: set `00004R`.
- `RECONSTRUCTION_CPP CODE`: populate with the formal insertion text above.
- `COMPLETION`: raise from `82` to `88`.
- `CONFIDENCE`: raise from `87` to `90`.
- Rationale: current MCP resolves range, vtable route, behavior, helper identities, support helper roles, owner/source placement, sibling call surface, and a first-draft formal body. Completion stays below 90 because exact original virtual declaration spelling and exact `+0x101` field spelling remain inferred rather than symbol-recovered.
- Current combined score was `(82 + 87) / 2 = 84.5`, below the project code-entry threshold.
- Recommended combined score would be `(88 + 90) / 2 = 89`, with nonblank emitter and formal first-draft C++.

## Recommended Target Doc Changes
- Update the Item Summary to remove the stale "text-normalization helper names are not final-source ready" blocker. Suggested wording: "Vtable-routed ExchangeDialog focus-change callback that normalizes control 6 money text with TextEditControlPane read/set helpers and CRT `_wtol`, submits through `ExchangeDialogSubmitExchangeAmount`, then calls inherited `DialogPane::SetHoverControl`."
- Add a current MCP evidence block naming session `46666bf7`, worker PID `20688` as supervisor-provided, `server_health` facts, `lookup_funcs` size `0xa3`, `analyze_function` no code callers/data xref `0x00619d84`, and the vtable-area `ExchangeDialog` name.
- Replace the stale helper-blocker language with the helper identity mapping in this report.
- Add exact range/padding evidence: preceding `0x004adfac-0x004adfb0` `cc` padding and following `0x004ae053-0x004ae060` `cc` padding.
- Add the sibling/emitter investigation and formal first-draft C++ block from this report.
- Update score metadata to `COMPLETION:88`, `CONFIDENCE:90`; set `EMITTER_UIDS:00004R` and leave owner/reconstructable as described above.

## Recommended Support Doc Changes
- [UID:00014K] `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`: update the exact-child row for `00049Y` to the new score and replace the helper-name blocker with "helper roles resolved; first-draft C++ emits through ExchangeDialog owner."
- [UID:00004R] `by-class/ExchangeDialog.md`: update the `OnControlFocusChange` method inventory row with the current helper mapping, precise focus-leave behavior, `EMITTER_UIDS:00004R` child route, and declaration/call-surface names used by the formal block.
- [UID:0000J9] `by-file/ExchangeDialog.md`: add/align the focus-change note under the control/money model so source generation routes this callback through `ExchangeDialog.cpp`; generated source should be produced only by the approved validator/generation path, not by manual source editing.
- [UID:00004T] `by-class/ExchangeMoneyEditControlPane.md`: align the existing note with current MCP: focus leave reads control id `6` text through `TextEditControlPaneReadTextForwarder`, parses with `_wtol`, normalizes non-positive text to `L"0"`, then submits the amount.
- [UID:00049V] `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`: add current xref evidence from this target at `0x004ae030` if not already present, and preserve `SubmitExchangeAmount(unsigned int)` as the callable sibling name used by `00049Y`.
- [UID:00049T] `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md`: use the same `ReadText`/`_wtol`/`SubmitExchangeAmount` naming so key-submit and focus-leave submit paths stay consistent.
- [UID:00049W] `by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md`: add current MCP timer/field evidence if refreshed, but do not treat its non-emitting state as a blocker for `00049Y`.
- No support doc score increase is required solely from this target report unless the implementation callback owner chooses to refresh those pages after edits.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C1 | Current MCP evidence was refreshed on session `46666bf7`; stale `978e78c8` was not used. | 1.00 | `idb_list`, `server_health`, supervisor recovery details, bounded MCP calls in this report. | Target evidence section. | incorporate | applied |
| C2 | Function range is exactly `0x004adfb0-0x004ae053`, size `0xa3` / decimal `163`. | 1.00 | `lookup_funcs`, `analyze_function`, `get_bytes`, `int_convert`. | Target Status/Boundary. | incorporate | applied |
| C3 | Preceding `0x004adfac-0x004adfb0` and following `0x004ae053-0x004ae060` bytes are padding, not target body. | 0.99 | `get_bytes 0x004adfa0 size 0x70`, `get_bytes 0x004ae053 size 0x0d`. | Target Boundary; [UID:00014K] child table if touched. | incorporate | applied |
| C4 | Target has no code callers and one data/vtable xref at `0x00619d84`. | 1.00 | `analyze_function`, `xrefs_to`, `xref_query`. | Target Evidence/Xrefs. | incorporate | applied |
| C5 | Vtable area is ExchangeDialog-associated. | 0.98 | `entity_query` near `0x00619d84` found `??_7ExchangeDialog@@6B@_0`; class docs. | Ownership rationale. | incorporate | applied |
| C6 | Branch triggers only when focus leaves control id `6` and TextEditControlPane byte `+0x101` is nonzero. | 0.98 | `decompile`/`disasm 0x004adfb0`; `int_convert` for `0x214` and `0x101`; control docs. | Target Behavior; ExchangeDialog method row. | incorporate | applied |
| C7 | `sub_498C10` is the TextEditControlPane read-text forwarder. | 0.97 | `decompile 0x00498c10`; [UID:0002OA], [UID:0002O9]; generated uses of `ReadText`. | Target helper mapping; [UID:00004T] note. | incorporate | applied |
| C8 | `unknown_libname_24` is CRT `_wtol`. | 1.00 | Current IDA decompile/disassembly naming and [UID:0001O5]. | Target helper mapping. | incorporate | applied |
| C9 | `sub_498CA0` is the TextEditControlPane set/replacement-text wrapper and should be surfaced as `SetText`. | 0.94 | `decompile 0x00498ca0`; embedded editor at `this[67]`; existing generated `TextEditControlPane::SetText(...)` calls. | Target helper mapping; [UID:00004T] note. | incorporate | applied |
| C10 | Non-positive amount sets displayed text to `L"0"` then submits amount `0`. | 0.99 | `decompile`/`disasm 0x004adfb0`; `get_string 0x00610634`. | Target Behavior. | incorporate | applied |
| C11 | Positive amount submits the `_wtol` amount through [UID:00049V]. | 0.99 | `decompile`/`disasm 0x004adfb0`; `xrefs_to 0x004ad960`. | Target Behavior. | incorporate | applied |
| C12 | Final call is inherited DialogPane active/hover-control update, source-facing `SetHoverControl(int)`. | 0.96 | `decompile 0x0049fc00`; [UID:00003T] accepted alias; broad xrefs. | Target Behavior; ExchangeDialog method row. | incorporate | applied |
| C13 | Canonical owner remains ExchangeDialog [UID:00004R]. | 0.99 | Owner-specific control ids, submit helper call, vtable-area evidence, support docs. | Target metadata. | incorporate | applied |
| C14 | `EMITTER_UIDS` should be set to `00004R`. | 0.92 | [UID:00004R] routes to [UID:0000J9]; generated `ExchangeDialog.cpp`; sibling/declaration investigation. | Target metadata; [UID:00004R] method row. | incorporate | applied |
| C15 | Formal `RECONSTRUCTION_CPP CODE` should be populated with this report's exact insertion text. | 0.90 | Current MCP behavior, helper mapping, source-route evidence, sibling non-blocker proof. | Target C++ block. | incorporate | applied |
| C16 | [UID:00049V] has stable callable surface `SubmitExchangeAmount(unsigned int)` for this target. | 0.94 | Current decompile/xrefs for `0x004ad960`; target call at `0x004ae030`; sibling docs. | Target C++ block; [UID:00049V] xref/naming note. | incorporate | applied |
| C17 | [UID:00049W] non-emission does not block `00049Y` because generated [UID:00014L] already calls `SetExchangeAmount(0)`. | 0.90 | Current generated `ExchangeDialog.cpp`; [UID:00049W] docs; current `analyze_component`/decompile. | Target Source Placement; [UID:00049W] support note if edited. | incorporate | applied |
| C18 | [UID:00049T] shares text-submit helper names but does not need to emit before `00049Y`. | 0.91 | Current `analyze_component`/decompile for `0x004ad7d0`; sibling docs. | Target Sibling Investigation; [UID:00049T] helper-name note if edited. | incorporate | applied |
| C19 | Recommended score is `COMPLETION:88`, `CONFIDENCE:90`, conservative because exact virtual declaration spelling and exact `+0x101` field spelling are inferred. | 0.89 | Score-blocker standard; current MCP; formal C++ and remaining negatives. | Target metadata and score rationale. | incorporate | applied |
| C20 | No in-scope blocker remains for target source-quality repair; remaining work is implementation callback execution with leases/validators. | 0.90 | Sibling investigation, formal insertion text, support-route evidence. | Target Open Questions; Implementation Tracking Checklist. | incorporate | applied |

## Open Questions And Resolution
- Exact original virtual method spelling: not symbol-recovered from current binary. Resolution: use established descriptive name `OnControlFocusChange(int controlId)` and document that the IDA prototype is `void __thiscall(int this, int)`.
- Exact original `sub_498CA0` wrapper name: not symbol-recovered. Resolution: use `TextEditControlPane::SetText` because that source-facing name is already present in generated output and matches the helper role.
- Exact original byte `+0x101` member spelling: not symbol-recovered. Resolution: use `TextEditControlPane::m_editActive` in the formal insertion because current docs identify the byte as the active/show-state bit and the local source-facing helper family already uses `SetEditActiveState`.
- Formal source emission: implemented in callback. The target now has `EMITTER_UIDS:00004R` and the exact first-draft C++ block, with scoped validators and generated output freshness recorded below.
- No in-scope source-quality blocker remains unresolved for target documentation repair. Sibling callback cleanup remains useful but is not a blocker for this target.

## Validator Results
- `python .\tools\validator.py --mode file --file by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md --apply --queue-timeout 240` from `source-3/project-documentation`: command_id `000000000923`, command_timestamp `2026-06-29T16:27:28-04:00`, exit code `0`, `ok: 1`, generated_refresh `deferred`.
- `python .\tools\validator.py --mode file --file by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md --apply --queue-timeout 240`: command_id `000000000925`, command_timestamp `2026-06-29T16:27:35-04:00`, exit code `0`, `ok: 1`, generated_refresh `deferred`.
- `python .\tools\validator.py --mode file --file by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md --apply --queue-timeout 240`: command_id `000000000926`, command_timestamp `2026-06-29T16:27:53-04:00`, exit code `0`, `ok: 1`, generated_refresh `deferred`.
- `python .\tools\validator.py --mode file --file by-class/ExchangeMoneyEditControlPane.md --apply --queue-timeout 240`: command_id `000000000928`, command_timestamp `2026-06-29T16:28:01-04:00`, exit code `0`, `ok: 1`, generated_refresh `deferred`; validator reported pre-existing missing UID warnings for `0003BK` and `0003LQ` references on that page.
- `python .\tools\validator.py --mode file --file by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240`: command_id `000000000929`, command_timestamp `2026-06-29T16:30:30-04:00`, exit code `0`, `ok: 1`, generated_refresh `deferred`.
- `python .\tools\validator.py --mode file --file by-class/ExchangeDialog.md --apply --queue-timeout 240`: command_id `000000000930`, command_timestamp `2026-06-29T16:30:42-04:00`, exit code `0`, `ok: 1`, generated_refresh `deferred`.
- `python .\tools\validator.py --mode file --file by-file/ExchangeDialog.md --apply --queue-timeout 240`: command_id `000000000931`, command_timestamp `2026-06-29T16:30:49-04:00`, exit code `0`, `ok: 1`, generated_refresh `deferred`.
- `python .\tools\validator.py --queue-status`: command_id `000000000932`, command_timestamp `2026-06-29T16:31:11-04:00`; worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Generated freshness: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header is `validator-command-id: 000000000931`, `validator-refreshed-at: 2026-06-29T16:30:49-04:00`, matching the final by-file validator command. The file contains UID00049Y formal `ExchangeDialog::OnControlFocusChange(int controlId)` emission and no UID00049Y empty marker.

## Changed Files
- Updated target/support docs:
  - `source-3/project-documentation/by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md`
  - `source-3/project-documentation/by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`
  - `source-3/project-documentation/by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md`
  - `source-3/project-documentation/by-class/ExchangeMoneyEditControlPane.md`
  - `source-3/project-documentation/by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
  - `source-3/project-documentation/by-class/ExchangeDialog.md`
  - `source-3/project-documentation/by-file/ExchangeDialog.md`
- Updated this implementation report: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/00049Y-ExchangeDialogOnControlFocusChange-source-quality.md`.
- Validator-owned generated/project files refreshed as side effects; no generated reports, generated C++ source, manual coverage reports, validator/tool state, IDA database files, supervisor ledgers, or executed archives were edited by hand.

## Implementation Tracking Checklist
- [x] Lease the exact target/support docs before any implementation callback edits; B002 leased/released target, [UID:00049V], [UID:00049W], [UID:00004T], [UID:00014K], [UID:00004R], and [UID:0000J9]. Initial B003 conflict on [UID:00014K]/[UID:00004R]/[UID:0000J9] was waited out and rechecked before editing.
- [x] Update `by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md` with current MCP session `46666bf7` evidence, exact range/padding, helper identity mapping, behavior rewrite, sibling/emitter investigation, and `88/90` score. Proof: target validator command `000000000923`.
- [x] Keep target `CANONICAL_OWNER:00004R` and `RECONSTRUCTABLE:TRUE`; set `EMITTER_UIDS:00004R`. Proof: target metadata validated in command `000000000923`.
- [x] Populate the target `RECONSTRUCTION_CPP CODE` block with the exact formal insertion text from this report. Proof: target validator command `000000000923`; generated `ExchangeDialog.cpp` header command `000000000931` includes UID00049Y formal method body.
- [x] Update [UID:00014K] `ExchangeDialog` aggregate child row for `00049Y` to match the new score and resolved-helper/emitting rationale. Proof: aggregate validator command `000000000929`.
- [x] Update [UID:00004R] `ExchangeDialog`, [UID:0000J9] `ExchangeDialog` file docs, and [UID:00004T] `ExchangeMoneyEditControlPane` with the aligned focus-leave helper mapping and declaration/call-surface names. Proof: validator commands `000000000930`, `000000000931`, and `000000000928`.
- [x] Align sibling [UID:00049V] `SubmitExchangeAmount`, [UID:00049W] `SetExchangeAmount`, and [UID:00049T] `OnKeyEvent` helper names/xref notes with this report where those pages are edited. Proof: [UID:00049V] command `000000000925`; [UID:00049W] command `000000000926`; [UID:00049T] already had `ReadText`/`_wtol`/`SubmitExchangeAmount` naming and focus-handler cross-reference at same-or-greater detail, so it was not edited.
- [x] Run the by-memory validator on the edited target page, then run file-scoped validators for every edited support page with the project-approved queue timeout. Proof: commands `000000000923`, `000000000925`, `000000000926`, `000000000928`, `000000000929`, `000000000930`, and `000000000931`, all exit code `0` with `ok: 1`.
- [x] Review validator-owned generated report/tracker updates; do not manually edit generated coverage text. Proof: generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` is current to command `000000000931` and contains UID00049Y formal emission; no generated/manual coverage files were edited by hand.
- [x] Keep the Claim And Incorporation Ledger synchronized with every incorporated claim during the implementation callback. Proof: all accepted claim rows now have verification state `applied`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00049Y-ExchangeDialogOnControlFocusChange-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00049Y-ExchangeDialogOnControlFocusChange-source-quality.md","timestamp":"2026-06-29T16:52:20","uid":"00049Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
