** TARGET-REPORT-UID:00049T **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:00049T] ExchangeDialogOnKeyEvent Source-Quality Report

## Finalized Report / Current Disposition

- Implementation callback status: accepted by supervisor and incorporated on 2026-06-29.
- Final disposition: [UID:00049T] `ExchangeDialogOnKeyEvent` is now a first-draft emitting `ExchangeDialog::OnKeyEvent(KeyEvent *event)` method with `EMITTER_UIDS:00004R`.
- Applied action: target metadata, behavior, MCP evidence, stale blocker text, formal C++ block, support class/file/aggregate wording, and vtable slot detail were updated under leases, validated, and leases were released.
- Confidence: high for owner, exact range, vtable route, return semantics, local money-control behavior, and code shape; medium-high for exact original event field names.

## Supporting Research

This report combines current IDA MCP evidence from session `46666bf7`, existing by-* documentation, generated output as a non-authoritative consistency check, and prior executed B-agent reports as historical leads. During the accepted implementation callback, the target and listed support by-* documents were edited under B001 leases; validators refreshed generated output, and the leases were released immediately after validation.

## Target

- Target UID: `00049T`
- Target path: `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md`
- Source queue/report row from `goal.md`: score `82/87`, combined `84.5`, reconstructable `true`, report count `0`.
- Current supervisor classification: accepted implementation callback for the exact target; B001 took and released only the target/support leases listed in `goal.md`; no subagents.
- Current scores and parent state: target `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`, formal C++ present.

## Current Target State

- Current metadata: [UID:00049T], range `0x004ad7d0-0x004ad85f`, owner [UID:00004R] `ExchangeDialog`, reconstructable true, emitting through [UID:00004R].
- Current owner/emitter/reconstructable state: direct owner remains correct; emitter is now set to `00004R`.
- Current C++/emitter state: formal C++ is present and matches the accepted first-draft `ExchangeDialog::OnKeyEvent(KeyEvent *event)` body.
- Existing open questions resolved here:
  - return semantics: binary returns the inherited `DialogPane` key/control handler result in `AL`;
  - event signature: source-facing `bool ExchangeDialog::OnKeyEvent(KeyEvent *event)` matches accepted DialogPane bridge precedent;
  - money-control helper: control id `6` is the local exchange money edit control, read through `TextEditControlPane::ReadText(..., 10)`;
  - amount normalization: `_wtol` result is submitted when positive and clamped to zero otherwise;
  - source placement: direct class owner [UID:00004R], emitted through [UID:0000J9].
- Previously stale or contradictory claims now repaired:
  - The target and aggregate no longer describe all of `0x004ad85f-0x004ad900` as alignment. Current MCP bytes show only `0x004ad85f` is `CC`; `0x004ad860-0x004ad8fa` decodes as an unmodeled adjacent packet helper with no function object and no xrefs to its entry. This does not change UID00049T's exact end, and the adjacent range remains outside this callback assignment.
- Related target/support docs checked:
  - `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md`
  - `by-class/ExchangeDialog.md`
  - `by-file/ExchangeDialog.md`
  - `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
  - `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`
  - `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md`
  - `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`
  - `by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md`
  - `by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md`
  - `by-class/ExchangeMoneyEditControlPane.md`
  - `by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md`
  - `by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md`
  - `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`

## Executive Disposition

The target is now an emitting exact ExchangeDialog child:

- Kept `CANONICAL_OWNER:00004R`.
- Kept `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:00004R`.
- Raised to `COMPLETION:88`, `CONFIDENCE:90`.
- Inserted the first-draft C++ block under `RECONSTRUCTION_CPP CODE`.
- Replaced stale blocker prose with current evidence: vtable-only inbound route, inherited DialogPane delegate result, digit text event gate, control `6` read, `_wtol` positive clamp, `SubmitExchangeAmount`.
- Preserve the note that exact original `KeyEvent` field spellings remain descriptive. This caps score but no longer blocks first-draft C++ because accepted sibling docs already emit key-event overrides with descriptive `KeyEvent`/`PaneKeyEvent` fields.

No in-scope target blocker remains. The only separate cleanup is support-boundary wording for the adjacent unmodeled `0x004ad860-0x004ad8fa` range; do not absorb that range into UID00049T.

## Supervisor Active Recheck

- Supervisor recovery instruction: resume UID00049T, use fresh IDA MCP session `46666bf7`, do not use stale session `978e78c8`.
- Current MCP session used: `46666bf7`.
- `idb_list`: one active session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID and worker PID `20688`.
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`.
- Supervisor's bounded `lookup_funcs 0x004ad7d0` result was reconfirmed: `sub_4AD7D0`, size `0x8f`.
- Split repair before master report: no target split repair is needed for UID00049T itself; its half-open range remains exact. A support wording repair was applied for the following range because current MCP contradicts the older broad padding label.

## Inference Research Guidance Check

- IDA fact: function boundaries, instruction behavior, vtable pointer, xrefs, callees, bytes, and sibling decompiles all come from session `46666bf7`.
- Documentation evidence: existing by-* pages and executed B reports were used as leads for owner/source route, control ids, accepted names, and prior blockers.
- Inference: source-facing names `KeyEvent::type`, `KeyEvent::wideChar`, `DialogPane::OnKeyEvent`, `ExchangeMoneyEditControlPane::ReadText`, and `SubmitExchangeAmount` are descriptive/project-facing names, not recovered symbols.
- Assumptions treated as uncertain:
  - prior "alignment `0x004ad85f-0x004ad900`" text;
  - old session evidence in the target page;
  - "helper names remain descriptive" as a C++ blocker rather than a score cap.
- Wave2/Wave3 artifacts: no Wave2/Wave3 source was used as authority. Older source/export mentions in existing docs were treated only as historical context.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence | Status |
| --- | --- | --- | --- |
| Direct owner | Keep [UID:00004R] `ExchangeDialog`. | `sub_4AD7D0` is in the ExchangeDialog secondary vtable, uses ExchangeDialog control id `6`, and calls `sub_4AD960` with `this - 0xa0`. | Direct owner resolved. |
| Source route | Emit through [UID:00004R] into [UID:0000J9] `ExchangeDialog.cpp`. | Class/file pages already route ExchangeDialog children through UID0000J9; dispatcher sibling UID00014L emits this way. | Source placement resolved. |
| Key signature | Use `bool ExchangeDialog::OnKeyEvent(KeyEvent *event)`. | Binary is `thiscall`, returns `AL`, `retn 4`, first call is inherited `0x0049e6e0`; accepted UID00046R uses `bool ...::OnKeyEvent(KeyEvent *event)` for the same inherited handler bridge. | First-draft safe. |
| Return semantics | Return the inherited `DialogPane::OnKeyEvent(event)` result. | Disasm saves `sub_49E6E0` return in `BL`, performs local money side effect only on digit text events, then returns `BL`. | Exact. |
| Event gate | Check event type byte `+4 == 10` and UTF-16 character at `+0x0a` in `'0'..'9'`. | Target disasm and decompile both show these tests. ExchangeMoney digit handler UID000341 confirms the same event type/UTF-16 digit convention. | Exact offsets; source field names descriptive. |
| Money control | Use control id `6`, local money edit control. | Target calls control manager virtual slot with argument `6`; class/file docs name control `6` as the local money edit control. | Exact. |
| Text read helper | Use inherited `ReadText(amountText, 10)` on the money edit control. | Target calls `0x00498c10` with max count `0x0a`; UID0002OA documents it as `TextEditControlPane::ReadText`. | Source-facing name accepted. |
| Amount parse | Use `_wtol`; clamp non-positive values to zero. | Target calls `unknown_libname_24` at `0x005cea43` once for test and again for positive value; support reports identify it as CRT `_wtol`. | Exact behavior. |
| Submit helper | Call `SubmitExchangeAmount(amount)`. | Target calls `sub_4AD960`; UID00049V documents that function as `ExchangeDialogSubmitExchangeAmount`; current MCP confirms caller at `0x004ad845`. | Source-facing name accepted. |
| Sibling packet helper names | Do not block UID00049T C++ on packet-builder internals inside UID00049V. | The key handler only calls the source-facing helper. Dispatcher already emits calls to non-emitting sibling helpers such as `SetExchangeAmount`. | Not a target blocker. |
| Adjacent bytes after target | Narrow support wording; do not change target range. | Current bytes show `0x004ad85f` is `CC`, then `0x004ad860-0x004ad8fa` decodes as unmodeled code; `lookup_funcs 0x004ad860` is not a function and `xrefs_to 0x004ad860` is empty. | Out-of-target support repair. |

Rejected alternatives:

- `ExchangeMoneyEditControlPane` as owner: rejected. It is the child control selected by id `6`; the receiver is ExchangeDialog and the submit call uses the owning dialog pointer.
- `DialogPane` as owner: rejected. `DialogPane` is only the inherited delegate. The local side effect is exchange-specific.
- [UID:0000J9] file as direct owner: rejected. It is the source route, while the semantic owner is the class UID00004R.
- no-owner/dead/no-route: rejected. The only inbound route is a vtable data xref, which is expected for this virtual callback and is enough when paired with constructor vtable installation.
- extending UID00049T to include `0x004ad860`: rejected. UID00049T returns at `0x004ad85e`, has size `0x8f`, and the next byte is outside the function.

## Evidence Standards Used

- IDA MCP evidence used: `idb_list`, `server_health`, `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, and `find_bytes`.
- Binary evidence strength: high. The exact target body is modeled by IDA, Hex-Rays decompiles it cleanly, and the vtable pointer is the only literal pointer to the function.
- Documentation evidence strength: high for owner/source route and accepted naming; medium-high for exact original event field spelling because no source symbols were found.
- Tool limitation affecting confidence: IDA does not model the adjacent `0x004ad860` code-looking bytes as a function. This does not affect UID00049T's boundary but prevents classifying the adjacent range in this target report.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `lookup_funcs` for `0x004ad7d0`, `0x004ad7cf`, `0x004ad85e`, `0x004ad85f`, `0x004ad860`, `0x004ad8ff`, `0x004ad900`, `0x004ad960`, `0x004ada20`, `0x004adfb0`, `0x004b0b60`, `0x00498c10`, `0x00498d90`, `0x0049e6e0`, `0x0041b9b0`, and `0x005754c0`.
  - `disasm 0x004ad7d0` and `decompile 0x004ad7d0`.
  - `xrefs_to` for `0x004ad7d0`, `0x004ad960`, `0x004ada20`, `0x004adfb0`, `0x00619d94`, and boundary addresses.
  - `callees` for `0x004ad7d0`, `0x004ad960`, `0x004adfb0`, `0x00498c10`, and `0x0049e6e0`.
  - `decompile` for siblings `0x004ad960`, `0x004ada20`, and `0x004adfb0`.
  - `get_bytes` around `0x00619d80`, `0x004ad7b0`, and `0x004ad850`.
  - `find_bytes d0 d7 4a 00`, which found only `0x00619d94`.
  - `xrefs_to` for vtable bases `0x00619d2c`, `0x00619d8c`, and `0x00619dbc`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - target, class, file, aggregate, vtable, sibling method, text-control, money-control, and generated `ExchangeDialog.cpp` docs listed above;
  - executed reports B001 UID00014K, B015 UID00014L, B006 UID00014N, and B001 UID0003LQ;
  - search over `executed-b-agent-research` and `tools/leaser/Agents` for `00049T`, `004ad7d0`, `004ad85f`, `ExchangeDialogOnKeyEvent`, `sub_4AD7D0`, and `0x00619d94`.
- Negative checks performed:
  - no direct code callers to `0x004ad7d0`;
  - only one pointer-literal hit to `0x004ad7d0`, at `0x00619d94`;
  - no xrefs to `0x004ad85f`;
  - no xrefs to `0x004ad860`;
  - `0x004ad860` is not a modeled function in current IDA.
- Failed, unavailable, or intentionally skipped checks:
  - Stale MCP session `978e78c8` was not used. Current evidence in this report uses session `46666bf7`.
  - No IDA rename/type/comment edits were attempted; the implementation callback only updated documentation.
  - Validators were run for the target and affected support docs after the edit batch.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID00049T exact modeled range is `0x004ad7d0-0x004ad85f`, size `0x8f`. | High | `lookup_funcs 0x004ad7d0`, disasm return at `0x004ad85c`, not-function at `0x004ad85f`. | Target Status / MCP Evidence | Incorporated. | Applied in target MCP Evidence/Boundary Notes using session `46666bf7`. |
| C002 | Direct owner remains `ExchangeDialog` [UID:00004R]. | High | Vtable slot `0x00619d94`, constructor vtable-base xrefs, ExchangeDialog control id `6`, call to `sub_4AD960(this - 0xa0)`. | Target Status / Ownership; class/file support | Incorporated. | Applied; owner preserved as `00004R` and support rows updated. |
| C003 | Target emits through [UID:00004R]. | High | Parent class emits through UID0000J9; dispatcher child UID00014L uses `EMITTER_UIDS:00004R`; target now clears first-draft C++ blockers. | Target metadata; class/file support | Incorporated. | Applied; `EMITTER_UIDS:00004R` and generated output includes UID00049T. |
| C004 | Return value is the inherited DialogPane key/control handler result. | High | Disasm stores `sub_49E6E0` result in `BL` and returns `BL`; decompile `v3 = sub_49E6E0(...)` and `return v3`. | Target Behavior / formal C++ | Incorporated. | Applied in behavior text and C++ as `const bool handled = DialogPane::OnKeyEvent(event); return handled;`. |
| C005 | Local logic only runs for event type `10` and UTF-16 digit at `+0x0a`. | High | Disasm `cmp byte ptr [esi+4], 0Ah`; `mov cx,[esi+0Ah]`; `sub cx,30h`; `cmp cx,9`. | Target Behavior / formal C++ | Incorporated. | Applied in behavior text and C++; field names remain explicitly descriptive. |
| C006 | The handler reads local money control id `6` and copies at most `10` wide chars. | High | Disasm pushes `6`, calls control-manager vfunc, then calls `sub_498C10(..., 0x0a)`; UID0002OA names `ReadText`. | Target Behavior / formal C++; class/file support | Incorporated. | Applied as `GetControl(6)` and `ReadText(amountText, 10)`. |
| C007 | Parsed amount is `_wtol(text)` if positive, otherwise zero. | High | Two calls to `unknown_libname_24` around `test/jle`; support docs identify `_wtol`. | Target Behavior / formal C++; class/file support | Incorporated. | Applied as `_wtol` parse plus non-positive clamp to zero. |
| C008 | Submit target is `ExchangeDialog::SubmitExchangeAmount`. | High | Callee `0x004ad960`; UID00049V documents it; current xrefs show call from `0x004ad845`. | Target Behavior / cross refs; class/file support | Incorporated. | Applied as `SubmitExchangeAmount(amount)` and support cross-reference detail. |
| C009 | Old broad `0x004ad85f-0x004ad900` alignment wording is stale. | High | Current bytes: `0x004ad85f` is `CC`; `0x004ad860-0x004ad8fa` decodes as code-like bytes; `lookup_funcs` says no function; no xrefs to `0x004ad860`. | Target Boundary Notes; aggregate support | Incorporated. | Applied; wording narrowed to single-byte `CC`, separate adjacent unmodeled code-like bytes, and later alignment. |
| C010 | Score should rise to `88/90`, not higher. | Medium-high | Exact behavior and owner are resolved; field names and sibling packet helper internals remain descriptive/project-facing. | Target metadata / score rationale | Incorporated. | Applied; validators recorded `completion_update` and `confidence_update` for UID00049T. |

## Positive Evidence Summary

- Direct facts supporting the disposition:
  - exact modeled function at `0x004ad7d0`, size `0x8f`;
  - only inbound reference is vtable data `0x00619d94 -> 0x004ad7d0`;
  - vtable bases are installed by the ExchangeDialog constructor;
  - inherited `DialogPane` handler is called first and its result is returned;
  - local body reads control id `6`, parses its text through `_wtol`, clamps non-positive values, and calls `SubmitExchangeAmount`.
- Corroborating documentation/generated-report evidence:
  - [UID:00004R] names control `6` as local money edit control;
  - [UID:00049V] names `0x004ad960` as `SubmitExchangeAmount`;
  - [UID:0002OA] names `0x00498c10` as text-control `ReadText`;
  - generated `ExchangeDialog.cpp` already uses `GetControl(6)`, `SetExchangeAmount`, and the ExchangeDialog source route.
- Strongest inference chain:
  - Secondary vtable slot plus constructor installation proves route.
  - `this - 0xa0` before the submit call proves the source receiver is the full ExchangeDialog object.
  - The accepted CreateUserDialogPane key-event bridge proves the inherited handler should be expressed as `DialogPane::OnKeyEvent(event)` with `KeyEvent *event`, not raw byte pointers.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs 0x004ad7d0`: `sub_4AD7D0`, size `0x8f`.
  - `lookup_funcs 0x004ad85e`: inside `sub_4AD7D0`.
  - `lookup_funcs 0x004ad85f`: not a function.
  - `lookup_funcs 0x004ad900`: `sub_4AD900`, size `0x5f`.
  - `lookup_funcs 0x004ad960`: `sub_4AD960`, size `0xb6`.
- Data/table/padding facts:
  - `get_bytes 0x00619d80 size 0x30` decodes secondary slot `0x00619d94 -> 0x004ad7d0`.
  - `find_bytes d0 d7 4a 00` finds only `0x00619d94`.
  - `get_bytes 0x004ad7b0 size 0x50` confirms pre-target switch table/padding then prologue at `0x004ad7d0`.
  - `get_bytes 0x004ad850 size 0xb0` confirms target epilogue through `0x004ad85e`, `CC` at `0x004ad85f`, and code-like bytes at `0x004ad860`.
- Xref facts:
  - `xrefs_to 0x004ad7d0`: one data xref at `0x00619d94`.
  - `xrefs_to 0x004ad960`: callers at `0x004acff9`, `0x004ad845`, and `0x004ae030`.
  - `xrefs_to 0x00619d2c`, `0x00619d8c`, `0x00619dbc`: each has one constructor-store xref in `sub_4AC8A0`.
- Callee facts:
  - `callees 0x004ad7d0`: `0x0049e6e0`, `0x00498c10`, `_wtol` at `0x005cea43`, `0x004ad960`, and security-cookie support.
- Negative IDA facts:
  - no ordinary code callers to target start;
  - no xrefs to `0x004ad85f`;
  - no xrefs to `0x004ad860`;
  - `lookup_funcs 0x004ad860` and `0x004ad8ff` are not functions in current IDA.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ad7d0-0x004ad85f` | [UID:00049T] target | ExchangeDialog key event override; submits money after digit text input. | TRUE | `00004R` | `88/90` | First-draft emitting C++ applied. |
| `0x004ad900-0x004ad95f` | [UID:00049U] | Send cancel packet. | TRUE | `00004R` | `83/87` | Sibling; stays non-emitting here. |
| `0x004ad960-0x004ada16` | [UID:00049V] | Submit exchange amount. | TRUE | `00004R` | `83/87` | Callee; source-facing helper name enough for this target. |
| `0x004ada20-0x004ada84` | [UID:00049W] | Set local exchange amount/state. | TRUE | `00004R` | `83/87` | Sibling; not modified. |
| `0x004adfb0-0x004ae053` | [UID:00049Y] | Focus-change submit/normalize path. | TRUE | `00004R` | `82/87` | Corroborating sibling; not modified. |
| `0x004ad860-0x004ad8fa` | no page found | Unmodeled adjacent code-like packet helper after one `CC`. | unresolved | outside UID00049T | n/a | Support wording narrowed; separate classification remains out of scope. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00619d94 -> 0x004ad7d0` | sole target pointer and sole target xref | Vtable-only inbound route, expected virtual callback. |
| `0x004ad7e9 -> 0x0049e6e0` | callee | Inherited DialogPane key/control handler; returned result preserved. |
| `0x004ad80e` | control-manager vfunc with argument `6` | Local money edit control lookup. |
| `0x004ad819 -> 0x00498c10` | callee | Text edit `ReadText` forwarder. |
| `0x004ad822`, `0x004ad832 -> 0x005cea43` | callee | CRT `_wtol`; positive test and value parse. |
| `0x004ad845 -> 0x004ad960` | callee | `ExchangeDialog::SubmitExchangeAmount`. |
| `0x004ae030 -> 0x004ad960` | sibling caller | Focus-loss path submits the same normalized amount. |
| `0x004acff9 -> 0x004ad960` | sibling caller | Constructor/init path reaches the submit helper. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:00004R] `ExchangeDialog` already owns UID00049T and names control `6` as local money edit.
  - [UID:0000J9] routes ExchangeDialog source through `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
  - [UID:0003NE] records the ExchangeDialog vtable region and table bases.
  - [UID:00049V] records `0x004ad960` as `SubmitExchangeAmount`.
  - [UID:00049Y] shows the same read/parse/clamp/submit money behavior on focus loss.
  - [UID:0002OA] documents the text read forwarder at `0x00498c10`.
- Existing docs that are stale, incomplete, or contradicted:
  - Target and aggregate boundary notes formerly calling all of `0x004ad85f-0x004ad900` alignment were too broad. The accepted callback narrowed the wording; current MCP shows code-like bytes at `0x004ad860-0x004ad8fa`.
  - Target's former non-emitting reason was stale. The accepted callback replaced it with first-draft C++ and current evidence because key-event signature, return semantics, and money helper roles are now resolved to first-draft quality.
- Generated/coverage report state:
  - Validator-generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` now includes `UID:00049T` with `bool ExchangeDialog::OnKeyEvent(KeyEvent *event)` at generated lines 153-172. Header metadata shows `validator-command-id: 000000000913`, matching the final target validator rerun.

## Ranked Ownership Analysis

### 1. [UID:00004R] ExchangeDialog

- Evidence for: vtable slot belongs to ExchangeDialog; constructor stores the table bases; body uses ExchangeDialog controls and calls ExchangeDialog money-submit helper; source route already established.
- Evidence against: none for direct ownership. Event handler is reached through a secondary base pointer, but the binary adjusts back to the full dialog for the exchange-specific call.
- Decision: accepted direct owner and emitter.

### 2. [UID:0000J9] ExchangeDialog file

- Evidence for: final source file route for the class and related private controls.
- Evidence against: by-memory method pages use the semantic class owner as direct owner; file is not the direct receiver.
- Decision: keep as source route only.

### 3. ExchangeMoneyEditControlPane / TextEditControlPane

- Evidence for: control id `6` is an ExchangeMoneyEditControlPane and text read comes from TextEditControlPane.
- Evidence against: those are child/control helper consumers; the receiver and state mutation are on ExchangeDialog.
- Decision: rejected as target owner.

### 4. DialogPane

- Evidence for: first callee is inherited `DialogPane` key/control handler.
- Evidence against: DialogPane does not own the money-submit side effect.
- Decision: rejected as direct owner; use only as base-call expression in C++.

## Source Placement

- Applied placement: `ExchangeDialog::OnKeyEvent(KeyEvent *event)` in [UID:0000J9] `NexusTK/ui/dialogs/ExchangeDialog.cpp`, emitted through [UID:00004R].
- Why this fits: sibling dispatcher UID00014L already emits into this file; class docs group the local money control, money submit helper, and packet dispatcher under ExchangeDialog.
- Rejected placements: `ExchangeMoneyEditControlPane`, `TextEditControlPane`, `DialogPane`, file-level free helper, no-owner.
- Remaining placement uncertainty: none for direct owner/source route. Exact event field names remain descriptive and cap score.

## Range / Split / Padding / Reclassification Analysis

- Exact target range/boundary facts:
  - target starts at `0x004ad7d0`, ends half-open at `0x004ad85f`;
  - body returns with `retn 4` ending at `0x004ad85e`;
  - preceding dispatcher support `0x004ad7b3-0x004ad7d0` remains outside target;
  - `0x004ad85f` is one `CC` byte after the target.
- Children/subranges:
  - no split of UID00049T needed;
  - no merge with `0x004ad860` or `0x004ad900` is justified;
  - adjacent `0x004ad860-0x004ad8fa` needs separate support/coverage investigation outside this assignment.
- Padding/table/data/code distinctions:
  - pre-target switch-table/padding distinction remains valid;
  - post-target broad "alignment to `0x004ad900`" is invalid. Only the first byte is confirmed `CC`; `0x004ad8fb` aligns before `0x004ad900`.
- Parent/container impact:
  - update target and aggregate support notes to stop labeling `0x004ad85f-0x004ad900` as all padding.

## Negative Evidence Summary

- No ordinary callers exist for `0x004ad7d0`; this is expected and not a dead-code sign because the vtable slot is the inbound route.
- No additional pointer copies to `0x004ad7d0` were found beyond `0x00619d94`.
- No xrefs to `0x004ad860` were found, so the adjacent code-like bytes cannot be classified here as a live ExchangeDialog child.
- ExchangeMoneyEditControlPane owns its digit filter at `0x004b0b60`, not this outer-dialog submit-on-digit callback.
- The non-emitting state of `SubmitExchangeAmount` does not block this target; this target's own behavior is a call to the helper, not reconstruction of packet serialization internals.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing function name/type:
  - `bool ExchangeDialog::OnKeyEvent(KeyEvent *event)` for `0x004ad7d0`.
- Proposed source-facing comments:
  - vtable-only ExchangeDialog key-event override;
  - delegates first to inherited `DialogPane::OnKeyEvent`;
  - on text/digit event, reads local money control `6`, parses `_wtol`, clamps non-positive to zero, and calls `SubmitExchangeAmount`.
- Items intentionally left unchanged:
  - no IDA database rename/type/comment was applied in this implementation callback;
  - no source-level name is proposed for adjacent `0x004ad860` because it is outside UID00049T and has no xrefs.
- IDA DB edits: not requested and not applied under this documentation-only callback.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Applied code: exact formal `RECONSTRUCTION_CPP CODE` block insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ExchangeDialog::OnKeyEvent(KeyEvent *event)
{
    const bool handled = DialogPane::OnKeyEvent(event);

    if (event->type == 10 &&
        event->wideChar >= L'0' &&
        event->wideChar <= L'9') {
        wchar_t amountText[10];
        ExchangeMoneyEditControlPane *moneyEdit =
            static_cast<ExchangeMoneyEditControlPane *>(GetControl(6));
        moneyEdit->ReadText(amountText, 10);

        const long parsedAmount = _wtol(amountText);
        const unsigned int amount =
            parsedAmount > 0 ? static_cast<unsigned int>(parsedAmount) : 0;
        SubmitExchangeAmount(amount);
    }

    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior:
  - inherited DialogPane result is computed before local checks and returned unchanged;
  - local side effect is gated by event type `10` and UTF-16 digit;
  - control id `6` is read with max count `10`;
  - `_wtol` result is clamped to zero when non-positive;
  - `SubmitExchangeAmount` is called with the normalized amount.
- Reason it matches plausible original source shape:
  - source uses class method and inherited base call rather than raw `this - 0xa0` pointer arithmetic;
  - control lookup, text read, and money helper names match existing generated/source-facing ExchangeDialog conventions;
  - accepted key-event pages use descriptive `KeyEvent` fields when symbols are unavailable.
- Inferred source-facing names/types/fields used instead of IDA labels:
  - `KeyEvent *event`, `event->type`, `event->wideChar`;
  - `DialogPane::OnKeyEvent`;
  - `ExchangeMoneyEditControlPane`;
  - `ReadText`;
  - `_wtol`;
  - `SubmitExchangeAmount`.
- Naming/coding style convention used:
  - follows generated `ExchangeDialog.cpp` style with `GetControl(6)`, local `const` values, and direct helper calls.
- Reason not higher than `88/90`:
  - exact original event field names and event type constant name are not symbol-proven;
  - `SubmitExchangeAmount` internals still have packet-helper naming caveats in its own page;
  - adjacent `0x004ad860` classification remains separate support cleanup.
- Third-party import directive: not applicable.

## Implementation Disposition

- Exact changes applied:
  - Target metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`.
  - Target formal C++: inserted the block above.
  - Target behavior/evidence: replaced old session references and no-code blocker with current session `46666bf7` evidence.
  - Target boundary note: replaced broad `0x004ad85f-0x004ad900` alignment statement with the precise current fact: target ends before `0x004ad85f`; `0x004ad85f` is `CC`; `0x004ad860-0x004ad8fa` is adjacent unmodeled code-like bytes outside UID00049T; `0x004ad8fb-0x004ad900` aligns before UID00049U.
- Exact parent assignments confirmed:
  - direct owner remains [UID:00004R];
  - source route remains [UID:0000J9].
- Exact items left no-owner/non-emitting and why:
  - adjacent `0x004ad860-0x004ad8fa` remains out of scope and should not be assigned by this report without a dedicated investigation.
- Exact future work outside this assignment scope:
  - separate support/coverage pass for `0x004ad860-0x004ad8fa` if supervisor wants to classify that adjacent unmodeled helper.

## Applied Target Doc Changes

- Target path: `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md`
- Exact report facts incorporated:
  - current MCP session `46666bf7`, active IDB path, worker PID `20688`, health ok;
  - exact function `sub_4AD7D0`, size `0x8f`;
  - vtable slot `0x00619d94 -> 0x004ad7d0`, only pointer/xref;
  - inherited base call `0x0049e6e0` result is returned;
  - event type `10`, UTF-16 digit at `+0x0a`;
  - control `6`, `ReadText(..., 10)`, `_wtol`, clamp, `SubmitExchangeAmount`;
  - post-target boundary correction.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:00004R`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00004R`
  - formal C++ block above.
- Historical/stale assumptions to preserve as rejected:
  - old no-code reason was valid before this pass but is superseded;
  - broad post-target alignment claim is superseded by current bytes;
  - stale MCP session `978e78c8` must not be used as current evidence.

## Applied Support Doc Changes

- Support path: `by-class/ExchangeDialog.md`
  - Updated the OnKeyEvent method row from non-emitting blocker text to source-ready first-draft: returns inherited DialogPane key handler result and submits parsed local money on digit text input.
  - Kept class score unchanged because the callback scope was UID00049T-specific.
- Support path: `by-file/ExchangeDialog.md`
  - Added UID00049T to the emitted/first-draft method inventory after target implementation.
  - Preserved sibling packet-helper caveats for UID00049U/UID00049V/UID00049W because those are separately scoped.
- Support path: `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
  - Updated UID00049T child row to `88/90`, `EMITTER_UIDS:00004R`, first-draft C++ present.
  - Replaced `0x004ad85f-0x004ad900` padding/support span with precise split wording: `0x004ad85f` `CC`; `0x004ad860-0x004ad8fa` adjacent unmodeled code-like bytes with no current function/xrefs; `0x004ad8fb-0x004ad900` alignment before UID00049U.
- Support path: `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`
  - Added slot detail: secondary table base `0x00619d8c`, slot `+0x08` at `0x00619d94` routes to UID00049T `ExchangeDialog::OnKeyEvent`.

## Score And Metadata Disposition

- Previous score/metadata:
  - `COMPLETION:82`
  - `CONFIDENCE:87`
  - `CANONICAL_OWNER:00004R`
  - `RECONSTRUCTABLE:TRUE`
  - blank `EMITTER_UIDS`
  - blank C++.
- Applied score/metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:00004R`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00004R`
  - formal C++ present.
- Score rationale:
  - raise because owner, route, signature, return semantics, helper roles, and behavior are now MCP-backed and implementation-ready;
  - do not raise above `88/90` because exact original event field spellings and event type constant are descriptive, sibling packet internals remain separately non-emitting, and post-target support cleanup remains outside this target.
- Score-improvement attempt:
  - key-event signature: checked accepted DialogPane bridge pages; resolved to `KeyEvent *event`;
  - return semantics: checked disasm/decompile; resolved;
  - helper names: checked `TextEditControlPaneReadTextForwarder`, `_wtol` support reports, and UID00049V; resolved to source-facing names;
  - split/padding: checked current bytes and xrefs; target exact, support wording needs repair;
  - source placement: checked class/file/vtable docs and generated output; resolved.
- Metadata fields to change or leave unchanged:
  - change `COMPLETION`, `CONFIDENCE`, `EMITTER_UIDS`, and C++ block;
  - leave UID, owner, reconstructable, and source route unchanged.

## Open Questions With Attempted Resolution

- Exact original event field names:
  - Evidence checked: target disasm, ExchangeMoney digit handler, accepted key-event docs, CreateUserDialogPane bridge.
  - Resolution: use project-facing `KeyEvent *event`, `event->type`, and `event->wideChar`. Exact symbol names remain descriptive but no longer block first-draft C++.
- Exact event type constant name for value `10`:
  - Evidence checked: target and ExchangeMoney digit handler both use `+4 == 10`.
  - Resolution: keep numeric `10` in first-draft C++ rather than inventing an unproven constant. This caps score.
- SubmitExchangeAmount internals:
  - Evidence checked: current MCP decompile of `0x004ad960`, UID00049V docs.
  - Resolution: out of scope for this target; this target only calls the helper. No blocker for UID00049T.
- Adjacent `0x004ad860-0x004ad8fa`:
  - Evidence checked: `lookup_funcs`, `disasm`, `xrefs_to`, bytes, doc search.
  - Resolution: not part of UID00049T and not safe to classify here. Support wording should stop calling it all padding.

No in-scope blocker remains unresolved.

## Follow-Up Actions

- Implementation callback status:
  - Accepted target/support doc updates are incorporated and validated.
  - B001 target/support leases were released after validation.
  - No accepted UID00049T implementation item remains unapplied.
- Out-of-scope future research only if separately assigned:
  - Investigate the adjacent unmodeled `0x004ad860-0x004ad8fa` range as a separate support/coverage target.

## Confidence

- Disposition confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact source-level event field names and the unclassified adjacent range, neither of which blocks UID00049T first-draft C++.

## Validator Results

- Target validator pass: `python .\tools\validator.py --mode file --file by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md --apply --queue-timeout 240`, command `000000000908`, exit 0, `ok: 1`; recorded UID00049T completion/confidence/emitter updates and exposed missing UID0003NE reference before the vtable support page registered it.
- Support validators: `by-class/ExchangeDialog.md` command `000000000909`, `by-file/ExchangeDialog.md` command `000000000910`, aggregate `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` command `000000000911`, and vtable `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md` command `000000000912`; all exited 0 with `ok: 1`.
- Final target rerun: command `000000000913`, exit 0, `ok: 1`; UID0003NE reference was resolved after vtable page validation.
- Generated refresh: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` refreshed by validator command `000000000913` and includes UID00049T. Final queue status command `000000000916` showed no queued or processing jobs.
- Any unresolved validator warnings/errors: none for the edited target/support files.

## Changed Files

- Manually modified under B001 leases:
  - `by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md`
  - `by-class/ExchangeDialog.md`
  - `by-file/ExchangeDialog.md`
  - `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
  - `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`
- Report updated:
  - `tools/leaser/Agents/Agent-B001/research/00049T-ExchangeDialogOnKeyEvent-source-quality.md`
- Validator-managed side effects observed:
  - target completion/confidence/emitter registry updates, reference-index updates, and generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` refresh.
- Renamed: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Accepted for implementation callback on 2026-06-29.
- [x] Target/support docs to update: target UID00049T; `by-class/ExchangeDialog.md`; `by-file/ExchangeDialog.md`; aggregate `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`; vtable slot detail in UID0003NE.
- [x] Current target state and actual evidence checked recorded using MCP session `46666bf7`.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: UID00049T to `88/90`, `EMITTER_UIDS:00004R`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or exact evidence-backed no-improvement proof.
- [x] Owner/emitter/reconstructable changes applied: owner `00004R` kept, reconstructable true kept, emitter `00004R` set.
- [x] Split/rename/new-child changes applied or ruled out: no target split; support wording repaired for adjacent post-target range.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable.
- [x] First-draft C++ applied: inserted `ExchangeDialog::OnKeyEvent(KeyEvent *event)` block.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable.
- [x] Open questions closed or documented as evidence-backed unresolved.
- [x] Validators run after implementation: target, class, file, aggregate, and vtable support docs validated with `ok: 1`.
- [x] Generated report refresh completed by validator; `ExchangeDialog.cpp` includes UID00049T after command `000000000913`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; final queue status command `000000000916` showed no queued or processing jobs.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00049T-ExchangeDialogOnKeyEvent-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00049T-ExchangeDialogOnKeyEvent-source-quality.md","timestamp":"2026-06-29T16:26:08","uid":"00049T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
