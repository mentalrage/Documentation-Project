** TARGET-REPORT-UID:0001CU **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-MEMTOOL-00530020 NexonclubRegistrationSupportHelpers Warning Review

## Finalized Report / Current Recommendation

- Current recommendation: treat the `auto-generated/by-memory-tool-report.md` warning as a minor filename-token/body-text mismatch, not as a substantive documentation, range, split/merge, owner/emitter, or IDA repair issue.
- Final disposition for [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](../../../../../by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md): keep `CANONICAL_OWNER:0001CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001CT`, blank reconstruction C++, range `0x00530020-0x0053057b`, and score `82/90`.
- Required action: no coverage-row edit and no metadata edit. Optional target-page edit to clear the advanced-scan warning: add an explicit compact filename token under `## Status`.
- Confidence: high. Live IDA MCP and current docs confirm the island, boundaries, parent, and emitter route; the only detected scan-relevant gap is the absent exact token `NexonclubRegistrationSupportHelpers`.

## Supporting Research

## Target

- Assignment: `B003-MEMTOOL-00530020`.
- Target path: `by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md`.
- Target UID: `0001CU`.
- Current metadata: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:0001CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001CT`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- Source warning: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan reports missing document text for `NexonclubRegistrationSupportHelpers`.

## Executive Recommendation

Do not rename, split, merge, reclassify, reroute, rescore, or edit `by-memory/-coverage-report.md`.

The target page is well documented and already contains the address range, support-island inventory, IDA evidence, xrefs, switch-table bounds, boundary/padding notes, and ownership decision. Direct body-text checks found `0x00530020` four times and `0x0053057b` twice. The exact compact filename token `NexonclubRegistrationSupportHelpers` has zero body matches because the page title uses the clearer human-readable subject `NexonclubRegistrationDialog Support Helpers`.

The filename is not harmful enough to justify a rename in this assignment. The current path is stable and widely referenced by UID links and generated rows; the page body and parent docs make the registration-dialog owner explicit. If the supervisor wants the advanced-scan row cleared, add this line under `## Status`:

```text
- Canonical filename token: `NexonclubRegistrationSupportHelpers`; descriptive subject token: `NexonclubRegistrationDialogSupportHelpers`.
```

This clears the warning while preserving the existing stable filename. A future rename to `0x00530020-0x0053057b.NexonclubRegistrationDialogSupportHelpers.md` would be defensible for clarity, but it is optional churn and not required by the binary evidence or owner/emitter model.

## Evidence Summary

- Current page body already documents a registration-dialog support island, not an empty or stale page.
- Direct text scan:
  - `0x00530020`: 4 matches.
  - `0x0053057b`: 2 matches.
  - `NexonclubRegistrationSupportHelpers`: 0 matches.
  - `NexonclubRegistrationDialog Support Helpers`: 1 match in the H1 title.
  - `NexonclubRegistrationDialog`: 12 matches.
- Generated warning context: Advanced-Error-Scan states it is heuristic and checks whether filename start/end addresses and label text appear in Markdown body text after configured sections are ignored.
- Timestamps: target page last write was `2026-06-13 12:07:05`; `by-memory-tool-report.md` last write was `2026-06-13 19:13:03`. The warning is a live post-page scan result, not a stale report predating the target page.
- Coverage state: `auto-generated/-ag-memory-coverage.md` lists [UID:0001CU] as emitting through `0001CT` to `auto-generated/NexusTK/ui/dialogs/NexonclubRegistrationDialog.cpp`. `by-memory/-coverage-report.md` has the expected `82% : strong` support helper island row.
- Documentation state: [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](../../../../../by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md), [UID:00009I][NexonclubRegistrationDialog](../../../../../by-class/NexonclubRegistrationDialog.md), and [UID:0000M0][NexonclubRegistrationDialog](../../../../../by-file/NexonclubRegistrationDialog.md) all preserve this target as a registration-dialog support helper detail.

## Live IDA MCP Facts

Live IDA MCP was available through `http://127.0.0.1:13337/mcp`.

- `initialize` succeeded against `ida-pro-mcp` protocol `2025-06-18`.
- `idb_list` returned active database session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- `server_health(database=b001_0003gy)` returned `status:ok`, `imagebase:0x400000`, `auto_analysis_ready:true`, and `hexrays_ready:true`.
- `lookup_funcs` confirms the target and neighbor boundaries:
  - `0x00530020`: `sub_530020`, size `0x32`.
  - `0x00530060`: `sub_530060`, size `0x1cb`.
  - `0x00530230`: `sub_530230`, size `0x1bf`.
  - `0x00530410`: `sub_530410`, size `0xa4`.
  - `0x005304c0`: `sub_5304C0`, size `0x21`.
  - `0x005304f0`: `sub_5304F0`, size `0x75`.
  - `0x00530565`: `sub_530565`, size `0xb`.
  - `0x00530570`: `sub_530570`, size `0xb`.
  - `0x0053057b`: not a function, confirming the target's exclusive end.
  - `0x00530580`: `sub_530580`, size `0xb6`, the scalar deleting destructor successor inside the parent island.
  - `0x00530640`: `sub_530640`, size `0x4c0`, the next dialog island.
- `entity_query(kind=functions, 0x0052f950-0x00530650)` returned the same constructor/destructor/helper/deleting-destructor/next-dialog function inventory.
- `get_bytes` confirms padding and table shape:
  - `0x00530015-0x00530020` is `0xcc` padding before the first support helper.
  - `0x005303ef` is `0x90`, followed by six dword switch targets at `0x005303f0-0x00530408` and `0xcc` padding through `0x00530410`.
  - `0x005304b4-0x005304c0`, `0x005304e1-0x005304f0`, `0x0053057b-0x00530580`, and `0x00530636-0x00530640` are padding.
- `xrefs_to` confirms registration-dialog relationship:
  - `0x00530020` has the real callback assignment at `0x0053018f` inside `sub_530060`; additional refs are data-area artifacts already treated as non-owner evidence by the target page.
  - `0x00530060` is referenced by vtable data at `0x006200f4`.
  - `0x00530230` is referenced by vtable data at `0x00620124`.
  - `0x00530410` is referenced by vtable data at `0x00620140`.
  - `0x005304c0` is called by `sub_530230` at `0x005302eb`.
  - `0x005304f0` is called by `sub_530230` at `0x00530336`, `0x00530358`, `0x0053037a`, `0x0053039c`, and `0x005303be`.
  - `0x00530565` and `0x00530570` are referenced by secondary/tertiary vtable data at `0x0062010c` and `0x0062013c`.
  - `0x00530580` is reached by jumps from the two adjustor thunks and by primary vtable data at `0x006200ac`.
- `callees` confirms target behavior:
  - `sub_530020` calls timer cancel/cleanup and pane destruction helpers.
  - `sub_530060` calls the submit/cancel/web-registration helpers, including `ShellExecuteA`, text getters, NCA submission `sub_528310`, callback allocation, alert construction, and timer start.
  - `sub_530230` calls pending cleanup, account text getter `sub_5304C0`, localized alert creator `sub_5304F0`, and close/destroy helpers.
  - `sub_530410` and `sub_5304F0` construct status alerts; `sub_5304c0` reads control text; the two thunks have no callees.
- `analyze_function 0x00530060` decompiled command cases `4`, `5`, and `6`: submit reads account/password controls, calls `sub_528310`, assigns `sub_530020` into a `PlainMemberFunctionObject`, starts a `30000` ms timer, cancel calls the result handler and closes the dialog, and case `6` opens the Nexon registration URL.
- `analyze_function 0x00530230` decompiled the `NCAu` response handler: it gates on immediate `1315127669` (`0x4e634175`) and pending state, clears timer/alert state, switches on response states `0..5`, calls `sub_5304C0` for success, and maps states `1..5` to message ids `228..232` through `sub_5304F0`.
- `disasm 0x00530565` confirms the thunk body `sub ecx, 0xa0; jmp sub_530580`.
- `disasm 0x00530230` confirms the six switch cases at `0x005302e5`, `0x0053032f`, `0x00530351`, `0x00530373`, `0x00530395`, and `0x005303b7`.

## Direct Xref / Caller Inventory

| Address / Item | Evidence | Meaning |
| --- | --- | --- |
| `0x00530020` | callback assignment at `0x0053018f` inside `sub_530060` | Timeout/cancel callback helper used by submit path. |
| `0x00530060` | vtable data ref `0x006200f4` | Registration-dialog command handler. |
| `0x00530230` | vtable data ref `0x00620124` | NCA/auth response handler. |
| `0x00530410` | vtable data ref `0x00620140` | Pending/status alert handler. |
| `0x005304c0` | call from `0x005302eb` | Account text getter in success response path. |
| `0x005304f0` | five calls from `sub_530230` | Localized failure/result alert helper. |
| `0x00530565` / `0x00530570` | vtable data refs `0x0062010c` / `0x0062013c` | Secondary/tertiary adjustor thunks. |
| `0x0053057b` | not a function; zero direct xrefs | Correct exclusive target end. |
| `0x00530580` | jumps from thunks and primary vtable data ref `0x006200ac` | Successor scalar deleting destructor, not part of this target. |

## Documentation Evidence And Current State

- Target page records the function island, behavior evidence, xref notes, switch-table and padding notes, explicit ownership decision, and final-C++ blockers.
- [UID:0001CT] parent page documents the full `0x0052f950-0x00530636` registration-dialog island and lists this helper page as the support-helper detail.
- [UID:00009I] class page documents this target as the support-helper page for command, response, account text, alert, and thunk support.
- [UID:0000M0] file page has valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and routes the registration-dialog source to `NexusTK/ui/dialogs/NexonclubRegistrationDialog.cpp`.
- [UID:0003C7][NexonclubRegistrationDialogReadOnlyData](../../../../../by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md) confirms vtable/resource/callback-object ownership for the same class/file route.
- [UID:00001T][ChattingColorPane](../../../../../by-class/ChattingColorPane.md) explicitly warns that older generated metadata mislabels `0x005304c0` and `0x005304f0` as chat-color methods, while current docs assign them to this registration support page.

## Ranked Issue Analysis

### 1. Missing exact compact filename token

- Evidence for: direct text scan found zero body matches for `NexonclubRegistrationSupportHelpers`.
- Evidence against: none for the token subwarning.
- Decision: accepted as a minor advanced-scan hygiene issue. Optional one-line token edit recommended.

### 2. Stale filename/name issue

- Evidence for: target title and evidence use the more precise `NexonclubRegistrationDialog Support Helpers`, while the filename token omits `Dialog`.
- Evidence against: the filename is stable, already used by generated rows and many UID-generated links, and still accurately describes Nexonclub registration support helpers. The owner/emitter route and title remove ambiguity.
- Decision: not worth a rename for this assignment. Optional future rename to `NexonclubRegistrationDialogSupportHelpers` is clarity-only and should be handled as a deliberate validator-backed rename if desired.

### 3. Missing document content

- Evidence for: advanced-scan row says missing document text for the compact token.
- Evidence against: the target page has detailed body content for range, helper inventory, behavior, xrefs, switch table, ownership, and blockers.
- Decision: rejected as a substantive problem.

### 4. Range, split, merge, or IDA repair issue

- Evidence for: none.
- Evidence against: live IDA confirms all modeled function starts/ends, switch-table bytes, padding gaps, adjustor thunks, target end, successor scalar deleting destructor, and next `NumberInputDialog` island.
- Decision: rejected. No range/split/merge/IDA repair.

### 5. Owner/emitter repair

- Evidence for: none.
- Evidence against: live xrefs and behavior tie the island to `NexonclubRegistrationDialog`; current `CANONICAL_OWNER:0001CT` and `EMITTER_UIDS:0001CT` route through the parent memory page to [UID:0000M0] `NexusTK/ui/dialogs/NexonclubRegistrationDialog.cpp`.
- Decision: rejected. Keep current owner/emitter.

### 6. Code-entry-quality content

- Evidence for: target confidence is `90`, and behavior/range confidence is strong.
- Evidence against: completion is `82`, below the 90/90+ code-entry gate. The target page itself says exact original helper names, callback type declarations, field names, and source-private split are not source-grade.
- Decision: do not add reconstruction C++.

## Exact Recommended Edits

No mandatory edits are required for correctness.

Optional target-page edit to clear the Advanced-Error-Scan warning:

Placement: `by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md`, under `## Status`, after the existing `- Confidence: ...` line.

```text
- Canonical filename token: `NexonclubRegistrationSupportHelpers`; descriptive subject token: `NexonclubRegistrationDialogSupportHelpers`.
```

No metadata/header change:

```text
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001CT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0001CT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No coverage-row change. Retain current `by-memory/-coverage-report.md` row:

```text
    - [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) : reconstructable : 82% : strong : Live IDA reconfirms support helper island 0x00530020-0x0053057b, command submit/cancel/web cases, pending-registration timer/alert state, NCAu response handler, embedded switch table 0x005303f0-0x00530408 mapping states 0..5, account text getter, localized alert helper ids 228-234, adjustor thunks, parent 0001CT attachment, unresolved helper/field names, and final C++ remains blank.
```

## Validation / Memory-Ranges Recommendation

- Validator not run by B003 because no by-* file was edited in this report-only pass.
- If the optional token line is applied, run the normal single-file validator with `--apply` for the target page.
- After that, rerun the memory-ranges advanced scan/report so `auto-generated/by-memory-tool-report.md` can be regenerated and the warning can clear.
- Do not edit `auto-generated/by-memory-tool-report.md`, `auto-generated/-ag-memory-coverage.md`, or `by-memory/-coverage-report.md` manually.

Suggested supervisor/A-agent verification commands after applying the optional by-memory edit:

> Executable block R001 was removed from this report and preserved verbatim in [B003-MEMTOOL-00530020-NexonclubRegistrationSupportHelpers-removed.md](B003-MEMTOOL-00530020-NexonclubRegistrationSupportHelpers-removed.md). The archived block is non-authoritative and must not be executed.

## Confidence

- Recommendation confidence: `92/100`.
- Score before/after: `82/90` before, `82/90` after.
- Remaining uncertainty: the preferred long-term filename style. `NexonclubRegistrationDialogSupportHelpers` is clearer, but the existing `NexonclubRegistrationSupportHelpers` filename is stable and not misleading enough to require a rename in this warning-only pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/B003-MEMTOOL-00530020-NexonclubRegistrationSupportHelpers.md`.
- Modified: none outside Agent-B003 research.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/B003-MEMTOOL-00530020-NexonclubRegistrationSupportHelpers.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0001CU"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at B003-MEMTOOL-00530020-NexonclubRegistrationSupportHelpers-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/B003-MEMTOOL-00530020-NexonclubRegistrationSupportHelpers.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
