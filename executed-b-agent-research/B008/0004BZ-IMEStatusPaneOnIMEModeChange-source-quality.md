** TARGET-REPORT-UID:0004BZ **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0004BZ] IMEStatusPaneOnIMEModeChange Source-Quality Report

## Finalized Report / Current Recommendation

- Assignment: `B008-report-0004BZ-IMEStatusPaneOnIMEModeChange-20260630`
- Target: [UID:0004BZ][0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange](../../../../../by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md)
- Current disposition: exact `IMEStatusPane` virtual handler split child is reconstructable and owner-known but still non-emitting because `EMITTER_UIDS` and formal C++ are blank.
- Recommendation: make the target an emitting [UID:00006I][IMEStatusPane](../../../../../by-class/IMEStatusPane.md) child, raise it to `88/91`, and insert the formal C++ block below. The body is small enough and directly verified enough that the current future-work wording is no longer valid under the score-blocker standard.
- Required action after supervisor acceptance: edit the target page only unless current support docs drift before callback. The class/file/aggregate/Event/literal support docs already contain the owner route and supporting facts at sufficient detail.

## Target

- Target UID: `0004BZ`
- Target path: `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md`
- Queue row: `auto-generated/-ag-research-tracker.md` row `0004BZ` is `82/88`, combined `85.0`, reconstructable `true`, reports `0`.
- Generated coverage row: `auto-generated/-ag-coverage-report-by-memory.md` lists `emits_code:false` for this target and summarizes it as the exact mode-change child that switches between `IME` and `ENG` through `SetText`.
- Current metadata:
  - `COMPLETION:82`
  - `CONFIDENCE:88`
  - `CANONICAL_OWNER:00006I`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - `EMITTER_POSITION_OPTIONAL:` blank
  - formal `RECONSTRUCTION_CPP CODE` blank

## Current Target State

The current page correctly identifies the class owner, source route, aggregate route, Event type `11`, and `IME`/`ENG` literal selection. Its remaining blocker is not factual ownership; it is the stale report-split wording that says child-specific formal C++ was not accepted yet. Current MCP evidence now resolves the child body and supports emitting it through [UID:00006I][IMEStatusPane](../../../../../by-class/IMEStatusPane.md) into [UID:0000K5][IMEPanes](../../../../../by-file/IMEPanes.md).

Related support docs checked:

- [UID:00006I][IMEStatusPane](../../../../../by-class/IMEStatusPane.md): already emits a class shell with `virtual bool OnIMEModeChange(const Event *event);`, `SetText`, `statusText[256]`, and `[[CHILDREN]]`.
- [UID:0000K5][IMEPanes](../../../../../by-file/IMEPanes.md): already projects `NexusTK/input/` and records `IMEStatusPane` as part of the pane-side IME UI source root.
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](../../../../../by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md): already records this exact child range and owner route.
- [UID:00025J][0x0061c360-0x0061c5a0.IMEPaneReadOnlyData](../../../../../by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md): already decodes the `Closed`, `IME`, and `ENG` UTF-16 literals and vtable island.
- [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](../../../../../by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md), [UID:0000J6][Event](../../../../../by-file/Event.md), and [UID:00004L][Event](../../../../../by-class/Event.md): already document the IME event family, type `11` open-status producer, and payload slot direction.

## Supervisor Active Recheck

- The active `goal.md` says this is report-only research for [UID:0004BZ], with no by-* edits or leases before supervisor validation.
- The assignment specifically required resolving source-quality blockers, source placement, Event type `11`, literal selection, `SetText` behavior, owner/emitter route, and first-draft C++ readiness.
- No split is needed. MCP lookup, disassembly, bytes, and padding confirm one exact `0x48`-byte modeled function from `0x004e72b0` through exclusive end `0x004e72f8`.
- No subagents were spawned. No leases were taken.

## Evidence Checked

Project documentation and generated state:

- Target page [UID:0004BZ], class [UID:00006I], file [UID:0000K5], aggregate [UID:000189], read-only data [UID:00025J], Event support [UID:00014C], [UID:0000J6], [UID:00004L], and adjacent status-pane children [UID:0004BW], [UID:0004BX], [UID:0004BY], [UID:0004C0].
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` rows for UID0004BZ.
- `auto-generated/NexusTK/input/IMEPanes.cpp` header from validator command `000000003193`, refreshed `2026-06-30T16:22:35-04:00`, confirming the current generated source route exists but UID0004BZ still has no emitted body yet.

Old report and active report search:

- Searched active Agent folders and central executed reports with `0004BZ`, `0x004e72b0`, `IMEStatusPaneOnIMEModeChange`, `OnIMEModeChange`, `IMEStatusPane`, and `IMEPane` terms.
- Matching leads opened/used: executed B008 `0000K5-IMEPanes-empty-emitter-family-source-quality.md` for the class shell and split plan; executed B007 `0004C0-IMEStatusPaneOnPaintFrame-source-quality.md` for the accepted sibling target pattern; active B007 `0004BY-IMEStatusPaneOrdinaryDestructor-source-quality.md` as a current adjacent status-pane report lead.
- No active B009 `0004BW` or B011 `0004BX` report file was present in those agents' `research` folders when checked.
- Stale Wave2 traces appeared in broad text search output and were ignored as stale lead material under the skill.

MCP and raw evidence:

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- `idb_list` MCP id `10`: one active worker session `supervisor_resume_20260629`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `24256`, not analyzing.
- `server_health` MCP id `12`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `lookup_funcs` MCP id `13`: `0x004e72b0 -> sub_4E72B0` size `0x48`; `0x004e72f8` is not a function; `0x004e7300 -> sub_4E7300`; sibling `SetText` and constructor starts are `0x004e70f0` and `0x004e71c0`.
- `decompile 0x004e72b0` MCP id `21`: rejects non-type-`11` Events, reads payload slot `+0x08`, chooses `ENG` by default, chooses `IME` when the payload is `1`, calls `sub_4E70F0((int)this - 160, selectedLiteral, 2 * (payload != 1) + 4)`, and returns `1`.
- `disasm 0x004e72b0` MCP id `29`: confirms `cmp byte ptr [ecx+4], 0Bh`, false return at `0x004e72be`, `mov ecx,[ecx+8]`, `cmp ecx,1`, `lea ecx,[edx-0A0h]`, `mov esi, offset aIme`, computed count `4 + 2*setnz`, `mov eax, offset aEng`, `cmovz eax, esi`, and `call sub_4E70F0`.
- `xrefs_to` MCP id `30`: one data xref to target entry from `0x0061c3bc`; one xref each to `aIme` at `0x0061c590` and `aEng` at `0x0061c598` from this handler; `SetText` has exactly two code xrefs, constructor `0x004e7249` and this handler `0x004e72ec`; `DispatchImeOpenStatusEvent` at `0x004a9a40` is called from InputMan at `0x004e8ffe`.
- `get_bytes` MCP id `28`: byte span proves one `0xcc` byte at `0x004e72af` before the function, the exact body bytes through `0x004e72f7`, and eight `0xcc` bytes at `0x004e72f8-0x004e72ff` before `OnPaintFrame`; also proves `Closed`, `IME`, and `ENG` UTF-16 bytes at `0x0061c580-0x0061c59f`.
- `callees` MCP id `31`: UID0004BZ has exactly one callee, `sub_4E70F0`; `InputMan::HandleWindowMessage` at `0x004e8de0` calls `ImmGetOpenStatus`, `DispatchImeOpenStatusEvent` at `0x004a9a40`, and the other IME event factories.
- `decompile 0x004a9a40` MCP id `32`: constructs an Event, stores Event type `11`, stores its first argument as the open-status payload slot, stores tick count, dispatches through EventDispatcher, and tears down the stack Event.
- `analyze_function 0x004e72b0` MCP id `33`: reports prototype `char __thiscall(void *this, int)`, size `72`, three basic blocks, one data xref, no code callers, and one callee `sub_4E70F0`.
- `get_int` MCP id `34`: vtable cell `0x0061c3bc` reads decimal `5141168`, which is `0x4e72b0` (Verified with `tools/int_convert.py`).
- `decompile 0x004e70f0` MCP id `27`: `SetText` clamps its third argument to `255`, uses it for text measurement, calls `wcsncpy_s(statusText, 0x100, Source, MaxCount)`, writes an explicit terminator at `statusText[MaxCount]`, and invalidates the pane.
- `decompile 0x004e71c0` MCP id `35`: constructor clears `statusText[256]` at `+0xf8`, calls `SetText(L"Closed", 6)`, and installs the three `IMEStatusPane` vtable views.
- `tools/int_convert.py`: verified `0x0b` is decimal `11`, `0xa0` is decimal `160`, `0x48` is decimal `72`, and decimal `5141168` is hex `0x4e72b0`.

Skipped or negative checks:

- No broad MCP searches or unbounded callgraphs were run.
- `get_string` was intentionally not used as authority for the short labels because the decompile refs rendered the UTF-16 strings as garbled CJK-looking text; direct bytes and [UID:00025J] decode the strings correctly.
- No validator was run because this is report-only and no by-* docs were edited.

## Positive Evidence Summary

- The target is an exact function: MCP lookup reports `0x48` bytes / decimal `72` (Verified with `tools/int_convert.py`) at `0x004e72b0`, and the exclusive end `0x004e72f8` is not a function.
- The function is reached by a single IMEStatusPane vtable data xref at `0x0061c3bc`; `get_int` proves that cell stores `0x004e72b0`.
- The handler body uses Event `+0x04` type byte, accepts only `0x0b` / decimal `11` (Verified with `tools/int_convert.py`), reads Event `+0x08` payload, and calls only `IMEStatusPane::SetText`.
- `Event` support already documents type `11` as `kEventImeOpenStatus` with open flag at Event `+0x08`, and MCP decompile of `0x004a9a40` confirms the producer writes type `11` plus the open-status payload.
- Literal bytes prove `IME` at `0x0061c590` and `ENG` at `0x0061c598`; xrefs to both literals come only from this handler.
- `SetText` direct xrefs are closed to the constructor and this handler, so the call is class-local status-label behavior rather than a shared text utility.

## Negative Evidence Summary

- There are no direct code callers to `0x004e72b0`; this is not dead code because the data xref from `0x0061c3bc` places it in the `IMEStatusPane` vtable.
- The Event producer and InputMan caller do not own this consumer body. `InputMan` owns Win32/IMM message handling and calls the Event factory; this target is pane-side UI reaction code reached through the status-pane vtable.
- The read-only data page owns neither the method nor raw source output for this handler. It only contains compiler/source-declared vtables and string literals.
- The `this - 0xa0` adjustment in disassembly is a compiler calling-convention artifact for a secondary/base-adjusted virtual view; it is not evidence for a separate source class or new helper function.
- The binary's `SetText` count constants are not normalized to `3`/`3`. Disassembly proves `4` for the `IME` branch and `6` for the `ENG` branch, so the formal C++ must preserve those constants.

## Heuristic / Inference Reanalysis And Validation

The current blocker was "method-body C++ remains for a child-specific pass." That blocker is resolved. The handler has one branch gate, one payload test, two static literals, one class-local callee, and vtable-only reachability. The source-facing shape is a normal `bool IMEStatusPane::OnIMEModeChange(const Event *event)` override, matching the already-emitted class declaration.

Inferred source-facing names:

- `kEventImeOpenStatus`: inferred from accepted Event support for type `11`.
- `event->m_type`: accepted Event support name for byte `+0x04`.
- `event->imeOpenStatus`: target-specific source-facing name for the type-11 payload at Event `+0x08`, more readable than `m_payload0` in this method. Exact original spelling remains inferred, but the field role is directly proven by Event factory and consumer evidence.
- `SetText`: already accepted class-local helper name on [UID:00006I].

Rejected source-quality alternatives:

- Raw decompiler code with `(int)this - 160`, `sub_4E70F0`, and `a2 + 8` is rejected because the class declaration and vtable route supply a source-level method call and Event payload field.
- A no-code proof is rejected because the body is source-authored, reconstructable, owner-routed, and above the code-entry gate after this report's recommended score.
- Leaving `EMITTER_UIDS` blank is rejected because [UID:00006I] already emits through [UID:0000K5] with `[[CHILDREN]]`, and this exact child now has a safe formal body.
- Reassigning ownership to Event, EventMan, or InputMan is rejected because those pages produce/route the Event; this target consumes the Event as `IMEStatusPane` UI code.
- Reassigning ownership to [UID:0000K5] directly is rejected because `IMEStatusPane` is the narrow class owner. [UID:0000K5] is only the source-file route.

Remaining caveats are non-blocking:

- Exact original Event member spellings are not recovered. The project already accepts descriptive/inferred Event payload names for child C++ direction, and the target score remains below final-audit levels because of that.
- The `SetText` counts `4` and `6` look source-unusual for the short labels, but they are direct binary facts. The report recommends preserving them exactly rather than replacing them with apparent string lengths.

## Ranked Ownership Analysis

### 1. [UID:00006I] IMEStatusPane

- Evidence for: vtable data xref at `0x0061c3bc`; class page already declares `OnIMEModeChange`; body calls status-pane `SetText`; body reads only Event data and IME status literals; aggregate and file support place this exact range in the `IMEStatusPane` method group.
- Evidence against: none material. The adjusted `this - 0xa0` is a compiler/base-view detail, not a competing owner.
- Decision: best and recommended direct owner. Keep `CANONICAL_OWNER:00006I` and set `EMITTER_UIDS:00006I`.

### 2. [UID:0000K5] IMEPanes

- Evidence for: source-file root for the class; generated route is [UID:00006I] -> [UID:0000K5].
- Evidence against: by-structure requires the narrow semantic owner when a class method is proven. Direct file ownership would bypass the class page and its `[[CHILDREN]]` route.
- Decision: transitive emitter root only, not direct canonical owner.

### 3. Event/EventMan/InputMan

- Evidence for: `DispatchImeOpenStatusEvent` builds type-11 records and `InputMan::HandleWindowMessage` calls that factory after IMM state checks.
- Evidence against: producer dependency does not own pane-consumer UI response. The target is vtable-reached and class-local to `IMEStatusPane`.
- Decision: dependency/support only.

### 4. IMEPaneReadOnlyData or literal ownership

- Evidence for: literals and vtable slot live in [UID:00025J].
- Evidence against: read-only data is compiler/source-declared support, not this executable method's source owner.
- Decision: support doc only.

## Source Placement

Recommended source placement is `NexusTK/input/IMEPanes.cpp` via [UID:00006I][IMEStatusPane](../../../../../by-class/IMEStatusPane.md) and its `[[CHILDREN]]` marker. This matches the current file page, class shell, aggregate split plan, and generated source route.

Implementation coordination note: B007, B009, and B011 may be touching sibling `IMEStatusPane` pages and shared support docs around [UID:0004BY], [UID:0004C0], [UID:0004BW], and [UID:0004BX]. During callback, re-read the target and support docs immediately before editing, check active leases, and do not overwrite newer accepted sibling support edits. If shared support docs have already gained same-or-greater detail, leave them unchanged and record `already-present`.

## Range / Split / Padding Analysis

- Exact half-open function range: `0x004e72b0-0x004e72f8`.
- Function size: `0x48` / decimal `72` (Verified with `tools/int_convert.py`).
- Boundary proof: `lookup_funcs` id `13` identifies the function start and says exclusive end `0x004e72f8` is not a function; `get_bytes` id `28` shows one `0xcc` byte at `0x004e72af` before the target and eight `0xcc` bytes at `0x004e72f8-0x004e72ff` before `0x004e7300`.
- No split is recommended. The range is one modeled function with one class-local call and no embedded data/switch table.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e72b0-0x004e72f8` | [UID:0004BZ][0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange](../../../../../by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md) | `IMEStatusPane::OnIMEModeChange` type-11 handler | `TRUE` | [UID:00006I][IMEStatusPane](../../../../../by-class/IMEStatusPane.md) | current `82/88`, recommended `88/91` | Needs callback metadata/formal C++ edit. |
| `0x004e70f0-0x004e71bc` | [UID:0004BW][IMEStatusPaneSetText](../../../../../by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md) | Class-local status-label setter callee | `TRUE` | [UID:00006I] | current `82/88` when read | Support lead only; no edit required by this report. |
| `0x004a9a40-0x004a9ad9` | covered by [UID:00014C][EventManAndEventFactoryHelpers](../../../../../by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) | Event type-11 producer | `TRUE` aggregate support | [UID:0000J6][Event](../../../../../by-file/Event.md) | `88/90` aggregate support | Already-present support evidence. |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x0061c3bc -> 0x004e72b0` | one data xref to target; `get_int` value `0x004e72b0` | `IMEStatusPane` vtable slot routes the virtual handler. |
| `0x004e72b0` | no direct code callers in `analyze_function` | Expected for vtable-only UI event override. |
| `0x004e72ec -> 0x004e70f0` | only target callee | Calls `IMEStatusPane::SetText`. |
| `0x004e7249 -> 0x004e70f0` | sibling constructor caller | Confirms `SetText` is local to status initialization and mode changes. |
| `0x004e72d6 -> 0x0061c590` | data xref | `IME` UTF-16 literal. |
| `0x004e72e3 -> 0x0061c598` | data xref | `ENG` UTF-16 literal. |
| `0x004e8ffe -> 0x004a9a40` | InputMan caller of Event factory | Producer path for Event type `11`, not target owner. |

## First-Draft C++ Recommendation

Eligible for draft C++: yes. After applying the recommended target metadata, the target will be `RECONSTRUCTABLE:TRUE`, have a nonblank emitter route through [UID:00006I] to [UID:0000K5], and have combined score `(88 + 91) / 2 = 89.5`.

Exact formal insertion text for the target `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IMEStatusPane::OnIMEModeChange(const Event *event)
{
    if (event->m_type != kEventImeOpenStatus) {
        return false;
    }

    if (event->imeOpenStatus == 1) {
        SetText(L"IME", 4);
    } else {
        SetText(L"ENG", 6);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior preservation:

- `event->m_type != kEventImeOpenStatus` preserves the byte compare against Event `+0x04` value `0x0b` / decimal `11` (Verified with `tools/int_convert.py`) and returns false for other events.
- `event->imeOpenStatus == 1` preserves the Event payload test at `+0x08`.
- `SetText(L"IME", 4)` and `SetText(L"ENG", 6)` preserve the disassembly's exact pushed count constants. Do not normalize these to apparent label lengths during implementation.
- The source omits `this - 0xa0` because that is the compiler's secondary/base-view adjustment before calling the complete `IMEStatusPane::SetText`.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md`

Required callback edits:

- Set metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:00006I` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:00006I`
  - `EMITTER_POSITION_OPTIONAL:` blank
- Insert the exact formal C++ block from this report.
- Replace stale "method-body C++ remains for a child-specific pass" wording with resolved child-specific evidence.
- Add MCP-backed behavior/range evidence: session `supervisor_resume_20260629`; function size `0x48`; type-byte compare to `0x0b` / decimal `11`; payload `+0x08` open flag; exact `SetText` constants `4` and `6`; string literal addresses/bytes; single `SetText` callee; vtable cell `0x0061c3bc`; padding before and after the body.
- Preserve rejected alternatives: no direct InputMan/Event ownership, no read-only literal ownership, no direct by-file owner shortcut, no split, no no-code proof, and no normalized string-length rewrite.

Suggested target item summary:

```text
Exact emitting IMEStatusPane mode-change handler; MCP proves vtable-only Event type 0x0b/11 consumer, Event +0x08 open-status payload, SetText(L"IME",4) versus SetText(L"ENG",6), IME/ENG literal xrefs, and padding through 0x004e72f8.
```

## Recommended Support Doc Changes

No support doc edit is required if current support remains as observed:

- [UID:00006I][IMEStatusPane](../../../../../by-class/IMEStatusPane.md) already has the `OnIMEModeChange` declaration, owner route, `SetText`, `statusText[256]`, and `[[CHILDREN]]`.
- [UID:0000K5][IMEPanes](../../../../../by-file/IMEPanes.md) already describes `IMEStatusPane` and this file as the pane-side IME source root.
- [UID:000189][IMEPaneFamily](../../../../../by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md) already contains the exact child row and owner/emitter route.
- [UID:00025J][IMEPaneReadOnlyData](../../../../../by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md) already decodes `IME` and `ENG`.
- Event support docs already establish type `11` as the IME open-status event with open flag at Event `+0x08`.

If a callback agent finds those support docs have changed and now contradict the accepted target facts, add concise synchronization notes under leases and validate those files. Otherwise record support facts as `already-present` and avoid churn in shared docs that B007/B009/B011 may be touching.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `82` | `88` | Exact range, padding, vtable route, Event type/payload, literal bytes, `SetText` callee, producer support, rejected alternatives, and first-draft formal C++ are now documented. |
| `CONFIDENCE` | `88` | `91` | MCP directly proves the handler body and dependencies. Confidence stays below final audit because exact original Event field spellings are inferred and the `SetText` count constants are source-unusual even though binary-proven. |
| `CANONICAL_OWNER` | `00006I` | `00006I` | `IMEStatusPane` is the narrow class owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored project UI handler. |
| `EMITTER_UIDS` | blank | `00006I` | [UID:00006I] emits to [UID:0000K5] and has `[[CHILDREN]]`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No child ordering override required. |

Reason not higher: field spellings and final Event declaration shape remain inferred support-wide questions; this target does not need a 95+ final-audit score. Reason not lower: all behavior and routing blockers named in the assignment are now directly checked and resolved.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | Target is one exact function `0x004e72b0-0x004e72f8`, size `0x48` / decimal `72`. | High | MCP `lookup_funcs` id `13`, `get_bytes` id `28`, `int_convert.py 0x48`. | Target `Status` / `Evidence` / `Score Rationale`; proof: target now records range, size, and padding before/after. | incorporate | applied |
| C2 | Target is vtable-reached `IMEStatusPane` code with one data xref from `0x0061c3bc` and no direct code callers. | High | MCP `xrefs_to` id `30`, `analyze_function` id `33`, `get_int` id `34`. | Target `Evidence` / `Reconstruction Notes`; proof: target records vtable cell `0x0061c3bc`, no direct callers, and pane-side vtable ownership. | incorporate | applied |
| C3 | Handler rejects non-type-`11` Events and returns false. | High | MCP `decompile` id `21`, `disasm` id `29`, `int_convert.py 0x0b`. | Target `Behavior` and formal C++; proof: formal body guards `event->m_type != kEventImeOpenStatus` and returns `false`. | incorporate | applied |
| C4 | Handler reads Event payload slot `+0x08`; payload value `1` selects `IME`, otherwise `ENG`. | High | MCP `decompile` id `21`, `disasm` id `29`, Event support [UID:00014C]. | Target `Behavior` / formal C++; proof: target text records Event `+0x08` and formal body tests `event->imeOpenStatus == 1`. | incorporate | applied |
| C5 | The binary calls `SetText(L"IME", 4)` for open status and `SetText(L"ENG", 6)` otherwise; those constants must not be normalized. | High | MCP `disasm` id `29`, `decompile` id `21`, `decompile SetText` id `27`. | Target `Behavior`, `Reconstruction Notes`, formal C++; proof: target text and formal body preserve `4` and `6` and reject string-length normalization. | incorporate | applied |
| C6 | `IME` and `ENG` literals are UTF-16 at `0x0061c590` and `0x0061c598`, each xrefed only from this handler. | High | MCP `get_bytes` id `28`, `xrefs_to` id `30`, support [UID:00025J]. | Target `Evidence`; support already-present in [UID:00025J]. Proof: target records literal addresses/xref sites and [UID:00025J] already decodes the literals. | incorporate | applied |
| C7 | `SetText` is class-local to the status constructor and this handler. | High | MCP `xrefs_to 0x004e70f0` id `30`; `decompile SetText` id `27`. | Target `Evidence` / `Reconstruction Notes`; proof: target records direct code xrefs from constructor `0x004e7249` and this handler `0x004e72ec`. | incorporate | applied |
| C8 | Event type `11` is produced by Event helper `0x004a9a40`, called from `InputMan`, with open flag stored into Event payload slot `+0x08`. | High | MCP `xrefs_to 0x004a9a40` id `30`, `callees 0x004e8de0` id `31`, `decompile 0x004a9a40` id `32`, [UID:00014C]. | Target `Evidence`; Event support already-present. Proof: target records producer `0x004a9a40`, Event `+0x08`, tick `+0x10c`, and InputMan producer role. | incorporate | applied |
| C9 | Direct owner remains [UID:00006I] and emitter route should be [UID:00006I] -> [UID:0000K5]. | High | Class/file/aggregate docs, vtable xref, formal class shell with `[[CHILDREN]]`. | Target metadata and `Status`; support docs already-present. Proof: metadata is `CANONICAL_OWNER:00006I`, `EMITTER_UIDS:00006I`, and Status records the class-to-file route. | incorporate | applied |
| C10 | Recommended target metadata is `88/91`, owner unchanged, reconstructable true, `EMITTER_UIDS:00006I`, blank position. | High | Current MCP body and by-structure code-entry gate. | Target metadata; proof: target header is now `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006I`, blank position. | incorporate | applied |
| C11 | Exact formal C++ block in this report is implementation-ready. | High | MCP body, class declaration, Event support, literal bytes. | Target formal `RECONSTRUCTION_CPP CODE` block; proof: exact accepted method body inserted without report marker lines. | incorporate | applied |
| C12 | Support docs do not require mandatory edits if current route/literal/Event facts remain present. | Medium-high | Current [UID:00006I], [UID:0000K5], [UID:000189], [UID:00025J], [UID:00014C], [UID:0000J6], [UID:00004L]. | Callback proof: re-read support pages during implementation; they still contain the class shell/route, file route, aggregate child row, UTF-16 literal data, Event type `11`/payload direction, and Event payload field direction. No support doc edits needed. | already-present | already-present |
| C13 | Rejected alternatives must be preserved: no InputMan/Event owner, no read-only-data owner, no direct file-owner shortcut, no split, no no-code proof, no string-length normalization. | High | Negative MCP/source-placement analysis in this report. | Target `Reconstruction Notes`; proof: target now records each rejected alternative and the reason it remains rejected. | incorporate | applied |

## Open Questions With Attempted Resolution

- Exact original Event field spellings: unresolved at original-symbol level, but not a blocker. Current Event support explicitly allows type-specific union-style payload names until exact child pages prove original declarations. This report recommends `m_type` and `imeOpenStatus` as source-facing names for this target and keeps the score below final audit.
- Exact reason for `SetText` count constants `4` and `6`: not proven from symbols, but the constants are exact binary facts. Do not replace them with apparent string lengths. This is a confidence cap, not a C++ blocker.
- Whether support docs should mirror the full target evidence: no mandatory support edit. The target is the canonical full method body home; support docs already carry class/file/event/literal facts. Re-read during callback in case B007/B009/B011 have changed shared docs.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. No manual `-coverage-report.md` or supervisor tracker edit is requested. The generated research tracker and generated by-memory coverage should update only after validator execution/refresh by the supervisor workflow.

## Validator Expectations After Callback

Required scoped validator after target edit:

> Executable block R001 was removed from this report and preserved verbatim in [0004BZ-IMEStatusPaneOnIMEModeChange-source-quality-removed.md](0004BZ-IMEStatusPaneOnIMEModeChange-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If any support doc is edited because it drifted or contradicted the accepted report, validate each changed support file with the same scoped `--mode file` pattern. Use `--wait-generated` for target/class/file validators where `auto-generated/NexusTK/input/IMEPanes.cpp` freshness matters.

Generated freshness expectation: after the target validator with `--wait-generated`, `auto-generated/NexusTK/input/IMEPanes.cpp` should have a `validator-command-id` equal to or newer than the validator command id, include a `// UID:0004BZ | by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md` marker, contain `bool IMEStatusPane::OnIMEModeChange(const Event *event)`, and have no `Empty Emitter Marker` for UID0004BZ.

## Changed Files

Report-only pass:

- Created: `tools/leaser/Agents/Agent-B008/research/0004BZ-IMEStatusPaneOnIMEModeChange-source-quality.md`
- Modified by-* docs: none
- Generated files/reports: none
- Leases: none
- Validators run: none, by design for report-only mode

Implementation callback pass:

- Modified by hand: `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md`.
- Modified by hand: `tools/leaser/Agents/Agent-B008/research/0004BZ-IMEStatusPaneOnIMEModeChange-source-quality.md` ledger/checklist proof.
- Support docs changed by hand: none. Re-read [UID:00006I], [UID:0000K5], [UID:000189], [UID:00025J], [UID:00014C], [UID:0000J6], and [UID:00004L]; current support remained consistent and already-present.
- Validator-owned/generated side effects from scoped target validation: `auto-generated/NexusTK/input/IMEPanes.cpp` refreshed, `auto-generated/-ag-research-tracker.md` refreshed, `auto-generated/-ag-coverage-report-by-memory.md` refreshed, `project-level/-auto-completion-stats.md` refreshed, and validator metadata/registry state updated by the validator. No generated report, generated C++, manual `-coverage-report.md`, validator/tool state, queue/lock file, executed archive, supervisor ledger, or IDA DB was edited by hand.
- Leases: B008 leased `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md` only for the immediate edit/validator batch and released it immediately after validation.

## Validator Results

Report-only pass: no validators were run because no target/support by-* docs were edited.

Implementation callback validator:

> Executable block R002 was removed from this report and preserved verbatim in [0004BZ-IMEStatusPaneOnIMEModeChange-source-quality-removed.md](0004BZ-IMEStatusPaneOnIMEModeChange-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Working directory: `source-3/project-documentation`
- Exit code: `0`
- `command_id`: `000000003208`
- `command_timestamp`: `2026-07-01T03:48:12-04:00`
- `ok`: `1`
- Target-specific updates: `completion_update 0004BZ ... 88`, `confidence_update 0004BZ ... 91`, `autogen_registry_update 0004BZ ... -> 00006I`, and formal C++ block registered as nonblank.
- Validator-driven side effects: `autogen_cpp_update: 1`, `autogen_registry_rebuild: 1`, `research_tracker_update: 1`, `memory_auto_coverage_update: 1`, `projected_stats_update: 1`, `generated_metadata_refresh: 279`, and generated backup creation. The broad `autogen_emitter_has_no_code` and `autogen_children_marker_missing` messages were unrelated existing project-wide autogen diagnostics.
- Generated refresh: `generated_refresh: completed`, `generated_refresh_command_id: 000000003208`, `generated_refresh_timestamp: 2026-07-01T03:48:12-04:00`.
- Generated `auto-generated/NexusTK/input/IMEPanes.cpp` freshness proof: subsequent header checks observed generated command ids newer than the validator command, including `validator-command-id: 000000003212` at `2026-07-01T03:49:21-04:00` and `validator-command-id: 000000003215` at `2026-07-01T03:51:07-04:00`, both newer than validator command `000000003208`. The generated file contains `// UID:0004BZ | by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md | Completion:88 | Confidence:91`, contains `bool IMEStatusPane::OnIMEModeChange(const Event *event)`, and `rg -n "0004BZ|OnIMEModeChange|Empty Emitter Marker" auto-generated/NexusTK/input/IMEPanes.cpp` showed no UID0004BZ empty-emitter marker.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Callback received in `goal.md` for assignment `B008-implement-0004BZ-IMEStatusPaneOnIMEModeChange-20260630`.
- [x] During callback, re-read current target and shared support docs immediately before editing, especially [UID:00006I], [UID:0000K5], [UID:000189], [UID:00025J], and Event support docs; check leases because B007/B009/B011 may be touching sibling IMEStatusPane work. Proof: re-read target and support docs, checked current lease report before edit, and found no active conflicting lease on the target.
- [x] Target metadata: update [UID:0004BZ] from `82/88`, blank emitter to `88/91`, `EMITTER_UIDS:00006I`, owner unchanged `00006I`, reconstructable unchanged `TRUE`, blank emitter position. Proof: target header now has the accepted values.
- [x] Target formal C++: insert the exact `RECONSTRUCTION_CPP CODE` block from this report, preserving `SetText(L"IME", 4)` and `SetText(L"ENG", 6)`. Proof: target formal block contains only the accepted method body, and generated `IMEPanes.cpp` now contains the UID0004BZ marker/body.
- [x] Target behavior/evidence: incorporate MCP-backed function size/range/padding, Event type `0x0b`/`11`, Event `+0x08` open-status payload, literal xrefs/bytes, `SetText` caller closure, vtable cell `0x0061c3bc`, and Event producer `0x004a9a40` proof. Proof: target `Behavior` and `Evidence` sections now record each fact.
- [x] Target source-placement/rejected alternatives: document why owner/emitter is [UID:00006I] -> [UID:0000K5], not InputMan/Event/EventMan/read-only data/direct file ownership, and why no split/no-code/no string-length normalization is accepted. Proof: target `Reconstruction Notes` records each rejected alternative and rationale.
- [x] Support docs: if current support remains as observed, record [UID:00006I], [UID:0000K5], [UID:000189], [UID:00025J], and Event support as already-present at same-or-greater route/literal/type detail; if support drifted, apply only concise non-conflicting support synchronization under short leases. Proof: support docs remained consistent and were not edited.
- [x] Claim And Incorporation Ledger: update every row from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked` with proof after callback. Proof: C1-C11 and C13 are `applied`; C12 is `already-present`.
- [x] Validators: run the scoped target validator from `source-3/project-documentation` with `--wait-generated`, record command id, timestamp, exit code, `ok` count, warnings, and generated-refresh state; validate any support doc edited. Proof: validator command `000000003208`, timestamp `2026-07-01T03:48:12-04:00`, exit `0`, `ok: 1`; no support docs edited.
- [x] Generated freshness: verify `auto-generated/NexusTK/input/IMEPanes.cpp` header is equal/newer than the validator command and contains the UID0004BZ marker/body with no UID0004BZ empty-emitter marker. Proof: generated header was observed newer at commands `000000003212` and `000000003215`; `rg` found UID/body lines and no UID0004BZ empty marker.
- [x] Confirm no generated files, generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, or lock files were manually edited. Proof: generated/tool-state changes listed above are validator-owned side effects only; no prohibited files were manually edited.
- [x] Leave supervisor-owned report execution and generated tracker refresh to the supervisor after verification. Proof: report remains in Agent-B008 research folder; no execute-report command was run.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` mode is implementation callback for accepted report.
- [x] All accepted target/support details incorporated, already present, excluded with reason, or blocked with exact proof. Proof: no blocked rows; C1-C11/C13 applied to target, C12 support facts already-present.
- [x] Leases used only for immediate edit/validator batches and released immediately. Proof: B008 leased the target before edit/validation and released it after validator completion.
- [x] Validators and generated freshness recorded in this report and in the final callback checkpoint. Proof: validator and generated freshness details recorded above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0004BZ-IMEStatusPaneOnIMEModeChange-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004BZ-IMEStatusPaneOnIMEModeChange-source-quality.md","timestamp":"2026-07-01T03:52:50","uid":"0004BZ"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004BZ-IMEStatusPaneOnIMEModeChange-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0004BZ-IMEStatusPaneOnIMEModeChange-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004BZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
