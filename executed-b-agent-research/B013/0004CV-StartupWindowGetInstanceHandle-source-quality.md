** TARGET-REPORT-UID:0004CV **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# Agent-B013 B-source-quality report: [UID:0004CV] StartupWindowGetInstanceHandle

Report path: `tools/leaser/Agents/Agent-B013/research/0004CV-StartupWindowGetInstanceHandle-source-quality.md`  
Target path: `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md`  
Assignment mode: implementation callback complete after supervisor Gate 1. The target by-memory doc was edited and validated; support by-* docs were inspected and left unchanged as already-present; generated `StartupWindow.cpp` refreshed through the scoped validator only. No manual generated edits, coverage edits, validator-state edits, supervisor-ledger edits, lifecycle/archive moves, or `execute_report` commands were run.

## Finalized Report / Current Recommendation

[UID:0004CV] is a real four-byte `StartupWindow` accessor at `0x00581660-0x00581664`. Current MCP session `nexustk_supervisor_20260704` confirms the IDA function `sub_581660`, size `0x4` / 4 bytes (Verified with int_convert.py), with body bytes `8b 41 08 c3`, decompilation `return this[2]`, no callees, no ordinary callers, and no xrefs to the function start. The constructor at `0x005807d0` writes the same field at `this+0x08` from its `HINSTANCE` argument, so the current source-facing body `HINSTANCE StartupWindow::GetInstanceHandle() const { return m_instance; }` is the right source shape.

Implemented disposition: the target page is now `88/92`, still `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and the existing formal C++ block remains unchanged. The applied target prose now carries the current UID-specific MCP evidence, generated-output freshness, constructor field-write proof, and the explanation for why the target needed UID-specific report coverage despite the B008 family report. Confidence remains capped because the function has no current callers and the exact original names `GetInstanceHandle` and `m_instance` remain source-facing inferences rather than symbol-proven spellings.

## Supporting Research

Required reads and evidence sources, plus implementation callback checks:

- `tools/leaser/Agents/Agent-B013/goal.md`: assigned UID0004CV, Medium provenance, report-only boundary, target/report paths, and required source-quality questions.
- `.codex/skills/ntk-b-agent-workflow/SKILL.md` and `references/b-agent-research-and-implementation-workflow.md`: B-agent report shape, MCP requirement, source-quality/ownership mandate, first-draft C++ block rule, and no by-* edit boundary.
- `by-structure.md` `IDA MCP Output Discipline`: used exact-address and bounded MCP calls only; no broad listing, broad search, unbounded xref, lifecycle, or validator commands.
- Target: `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md`.
- Support docs: `by-class/StartupWindow.md`, `by-file/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, and `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md`.
- Generated read-only evidence: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/app/StartupWindow.cpp`.
- Matching executed reports opened as gated leads: `executed-b-agent-research/B008/0000O5-StartupWindow-empty-emitter-family-source-quality.md` and `executed-b-agent-research/B010/0001IO-StartupWindowUpdateCheck-source-quality.md`.
- Implementation callback target validation: `python .\tools\validator.py --mode file --file by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md --apply --queue-timeout 240`, command `000000006412`, timestamp `2026-07-04T18:20:33-04:00`, exit `0`, ok `1`.
- Post-validation generated freshness check: `auto-generated/NexusTK/app/StartupWindow.cpp` currently reports `validator-command-id: 000000006415`, `validator-refreshed-at: 2026-07-04T18:21:32-04:00`, and contains UID0004CV at `Completion:88 | Confidence:92` with the same accessor body.

Search terms used before finalizing: `0004CV`, `0x00581660`, `StartupWindowGetInstanceHandle`, `GetInstanceHandle`, `HINSTANCE`, `StartupWindow`, `StartupWindowUpdateCheck`, and startup/source-family terms.

## Target

- Target UID: `0004CV`
- Target path: `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md`
- Current metadata after callback: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional position. Pre-callback metadata was `86/88`.
- Current formal C++:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HINSTANCE StartupWindow::GetInstanceHandle() const
{
    return m_instance;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Current generated output: `auto-generated/NexusTK/app/StartupWindow.cpp` header reports `validator-command-id: 000000006415`, `validator-refreshed-at: 2026-07-04T18:21:32-04:00`, and contains UID0004CV at `Completion:88 | Confidence:92` with `HINSTANCE StartupWindow::GetInstanceHandle() const` returning `m_instance`.
- Historical tracker state before supervisor execution: `auto-generated/-ag-research-tracker.md` listed UID0004CV under not-covered reconstructable by-memory rows with `86/88`, `true`, reports `0`, because B008 executed a family/split report that created the child but did not count as a UID0004CV-specific B report. This report and callback provide the missing UID-specific coverage pending supervisor execution.

## Current Target State

The target is now callback-applied. Exact range, owner/emitter route, reconstructable state, formal C++, current MCP evidence, constructor field proof, generated freshness, UID-specific report-history rationale, and confidence caps are all recorded in the target page.

- Pre-callback gap, now resolved: the target cited accepted B008 split evidence but did not carry the current `nexustk_supervisor_20260704` MCP evidence, generated header freshness, or the explicit explanation that B008 was a family report rather than a UID0004CV-specific executed report.
- Current caveat, still true after callback: IDA reports no current callers/xrefs. This remains a confidence cap, not a no-code proof, because IDA still models a function object and generated output emits the simple accessor without inventing extra range coverage.
- Current constructor proof, now recorded in target evidence: constructor `0x005807d0` writes `this[2] = a2` and `mov [ecx+8], eax`.
- The existing C++ uses `m_instance`, consistent with the constructor child's initializer list and generated `StartupWindow.cpp`; exact original member spelling is still inferred.

## Heuristic / Inference Reanalysis And Validation

The key inference question is whether a four-byte no-caller modeled function should remain source-authored C++ or be reclassified as padding/compiler artifact/no-code. Current evidence supports keeping it source-authored:

- IDA models an exact function at `0x00581660` with size `0x4`; `0x00581664` and predecessor padding start `0x0058165a` are not functions, and successor `0x00581670` is the next helper. This gives an exact body, not a range smear.
- The body is canonical MSVC thiscall accessor code: `mov eax, [ecx+8]; retn`. It does not have thunk shape, EH shape, scalar-deleting-destructor shape, import glue shape, or alignment/padding bytes.
- The constructor stores the startup `HINSTANCE` argument at the same offset. The accessor's return value is therefore not an arbitrary field read; it matches a named constructor parameter and a Win32 type needed by startup notice/window setup code.
- The no-caller fact is real, but not decisive. This exact child was created by a broad split to preserve source-bearing bodies. A private accessor can be compiled but optimized away at all current call sites or retained due to historical source shape, translation-unit references that are not direct calls in this build, or class declaration/inline evolution. Because it is a real modeled function between padding islands, deleting it from source would be a stronger claim than the current evidence supports.
- The existing owner route is still best: [UID:0000DZ] `StartupWindow` owns the class field, while [UID:0000O5] `StartupWindow.cpp` is the file emitter. File-only ownership would be too broad, and broad aggregate [UID:0001IO] is now a non-emitting split index.

The improvement path is narrow: update the target page's evidence and score, not its C++ or ownership model. Support docs already contain the relevant child inventory and constructor field notes at sufficient detail.

## Evidence Standards Used

- IDA MCP is treated as mandatory current evidence. Calls were exact-address and bounded: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, and `get_bytes`.
- Generated C++ is lead/freshness evidence only. It confirms the current validator output contains the accessor body but does not replace MCP or by-* source-quality evidence.
- Prior reports are lead/support evidence only. B008 proves why the child exists and why the tracker still shows no UID-specific report; current report conclusions are rechecked against current target docs and MCP.
- Numeric conversions are documented only where verified with `tools/int_convert.py`.
- C++ is supplied only as exact formal `RECONSTRUCTION_CPP CODE` insertion text.

## Evidence Checked

MCP session and health:

- `idb_list`: active session `nexustk_supervisor_20260704`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker PID `10024`.
- `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

MCP target checks:

- `lookup_funcs` for `0x00581660`, `0x00581664`, `0x0058165a`, and `0x00581670`: `0x00581660` is `sub_581660`, size `0x4`; `0x00581664` is not a function; `0x0058165a` is not a function; `0x00581670` is successor `sub_581670`, size `0xb4`.
- `analyze_function 0x00581660`: prototype `int __thiscall(_DWORD *this)`, size `4`, decompiled `return this[2]`, no strings, no constants, no callees, no callers, one basic block, cyclomatic complexity `1`.
- `decompile 0x00581660`: `int __thiscall sub_581660(_DWORD *this) { return this[2]; }`.
- `disasm 0x00581660`: two instructions, `mov eax, [ecx+8]` and `retn`.
- `xrefs_to 0x00581660` with `limit:20`: no cross-references, `xref_count:0`.
- `get_bytes 0x0058165a size 26`: six `0xcc` bytes before the accessor, body bytes `0x8b 0x41 0x08 0xc3`, twelve `0xcc` bytes after the accessor, then successor helper prologue `55 8b ec 83`.

MCP constructor/field checks:

- `lookup_funcs 0x005807d0`: `StartupWindow__Constructor`, size `0x3c`.
- `decompile 0x005807d0`: writes `unk_69BAC8`, installs `StartupWindow::vftable`, writes `byte_66DA97 = 1`, stores `this[2] = a2`, clears `this+4` and `this+84`.
- `disasm 0x005807d0`: at `0x005807fa`, `mov [ecx+8], eax`, with the constructor argument loaded at `0x005807ea`. This proves the accessor returns the constructor's `HINSTANCE` field.

Local/generated/report checks:

- Target page now has `88/92`, current MCP evidence, and unchanged formal C++ for `HINSTANCE StartupWindow::GetInstanceHandle() const`.
- Constructor child page already names the constructor parameter `HINSTANCE instance` and initializes `m_instance(instance)`.
- `by-class/StartupWindow.md` and [UID:0001IO] split index list UID0004CV as exact child and preserve no-current-caller caveat.
- `auto-generated/NexusTK/app/StartupWindow.cpp` currently contains UID0004CV under validator command `000000006415`, refreshed `2026-07-04T18:21:32-04:00`, at `Completion:88 | Confidence:92`.
- `auto-generated/-ag-research-tracker.md` row for UID0004CV showed reports `0` during the pre-callback report-only pass; this remains historical lifecycle context pending supervisor execution.
- Executed B008 StartupWindow family report created the UID0004CV child and recorded validator `000000003704` for that child. It was executed as target UID0000O5, so it does not satisfy the tracker's UID0004CV-specific executed-report count.
- Executed B010 aggregate report proposed this child as a tiny accessor, source-bearing but low priority, with no current callers and `this+0x08` `HINSTANCE` evidence.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004CV-01 | UID0004CV is an exact modeled function at `0x00581660-0x00581664`, size `0x4` / 4 bytes. | High | MCP `lookup_funcs`; int_convert.py. | Target `Status` / `Evidence` | incorporate | applied: target `Status` and `Evidence` now record exact range, `sub_581660`, size `0x4` / 4 bytes; validator `000000006412` exit `0`, ok `1`. |
| C-0004CV-02 | Body bytes are `8b 41 08 c3`, disassembling to `mov eax, [ecx+8]; retn`. | High | MCP `get_bytes`, `disasm`. | Target `Evidence` / `Boundary And Padding` | incorporate | applied: target `Evidence` records six prebytes, body bytes, twelve postbytes, and `mov eax, [ecx+8]; retn`; validator `000000006412` exit `0`, ok `1`. |
| C-0004CV-03 | The target has zero current callers/xrefs, and this should remain a confidence cap. | High | MCP `analyze_function` callers `[]`; `xrefs_to` count `0`. | Target `Evidence` / `Open caveats` | incorporate | applied: target `Evidence` records no callers, no callees, zero xrefs, and confidence-cap wording; validator `000000006412` exit `0`, ok `1`. |
| C-0004CV-04 | The returned field is the constructor-stored `HINSTANCE` at `this+0x08`. | High | Constructor `decompile` and `disasm` store argument at `this[2]` / `[ecx+8]`. | Target `Evidence`; constructor cross-reference note | incorporate | applied: target `Evidence` records constructor `this[2] = a2` and `mov [ecx+8], eax` proof; validator `000000006412` exit `0`, ok `1`. |
| C-0004CV-05 | Owner/emitter should remain `CANONICAL_OWNER:0000DZ`, `EMITTER_UIDS:0000O5`. | High | Field/class ownership, constructor child, class/file support docs, B008 split route. | Target metadata | already-present | already-present: target metadata still has `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional position after validator `000000006412`. |
| C-0004CV-06 | Existing formal C++ is correct and should be retained unchanged. | High for behavior, medium-high for exact names | MCP body and constructor field proof; generated C++; exact name/member spelling not symbol-proven. | Target formal C++ block | already-present | already-present: target formal block still contains only `HINSTANCE StartupWindow::GetInstanceHandle() const { return m_instance; }`; generated header `000000006415` confirms the same body. |
| C-0004CV-07 | UID0004CV remains in the not-covered tracker because B008 was a UID0000O5 family/split report, not a UID0004CV-specific executed B report. | High | Tracker row reports `0`; B008 report path and target UID0000O5. | Target/report history note; report final recommendation | incorporate | applied: target `Evidence` now records the B008 family/split report rationale and UID-specific coverage reason; validator `000000006412` exit `0`, ok `1`. |
| C-0004CV-08 | Score should move from `86/88` to `88/92`, with no ownership/C++ change. | Medium-high | Fresh MCP evidence closes current-evidence gap; no-caller and inferred-name caps remain. | Target metadata and score rationale | incorporate | applied: target metadata is now `COMPLETION:88`, `CONFIDENCE:92`; validator `000000006412` reported completion/confidence updates and exit `0`, ok `1`. |
| C-0004CV-09 | Broad aggregate [UID:0001IO] remains a non-emitting split index and should not regain broad C++ because this child is ready. | High | Current aggregate metadata/prose; B008 execution; child exact page emits body. | Support docs if touched; target cross-reference | already-present | already-present: support docs inspected and already preserve the aggregate split/non-emitting route; no support edit was needed. |
| C-0004CV-10 | Reject reclassification to no-code/compiler-generated/padding. | High | Exact function object, non-padding bytes, constructor field source, formal C++ already emits. | Target `Heuristic` / `Negative Evidence` | incorporate | applied: target `Evidence` now rejects no-code/padding/compiler-wrapper/Win32/file-only/broad aggregate alternatives; validator `000000006412` exit `0`, ok `1`. |

## Positive Evidence Summary

- Exact IDA function at `0x00581660`, size `0x4` / 4 bytes (Verified with int_convert.py).
- Exact body is a simple thiscall field accessor over `this+0x08`.
- Constructor `0x005807d0` stores the `HINSTANCE` argument at the same offset.
- Surrounding bytes prove clean padding islands: six `0xcc` bytes before and twelve `0xcc` bytes after the function before the next helper prologue.
- Current generated `StartupWindow.cpp` emits UID0004CV as `HINSTANCE StartupWindow::GetInstanceHandle() const`.
- Existing class/file/aggregate docs already route the child through `StartupWindow` / `StartupWindow.cpp` and preserve the non-emitting aggregate split policy.

## Negative Evidence Summary

- No current callers or xrefs to `0x00581660`; this prevents final/high-90s confidence and should remain explicit.
- No symbol proof for exact original names `GetInstanceHandle` or `m_instance`; they are source-facing inferences grounded in the constructor field and Win32 type.
- No evidence supports moving the child to file-only ownership; it returns a class field initialized by the class constructor.
- No evidence supports reclassifying it as padding: bytes are executable instructions and IDA models a function.
- No evidence supports treating it as compiler-generated wrapper/thunk: there is no branch, this-adjustment, vtable wrapper, scalar deleting destructor pattern, EH glue, or import glue.
- No evidence supports changing [UID:0001IO] back to an emitting aggregate; exact child pages now carry source-bearing bodies.

## Ranked Ownership Analysis

1. [UID:0000DZ] `StartupWindow` class, emitted through [UID:0000O5] `StartupWindow.cpp`: best fit. The accessor returns a class field at `+0x08`, and the constructor child proves that field is the constructor's `HINSTANCE` parameter.
2. [UID:0000O5] `StartupWindow` file root: valid emitter, but too broad as canonical owner because the function is source-shaped as a class accessor.
3. [UID:0001IO] `StartupWindowUpdateCheck` aggregate: rejected as direct owner because it is now a non-emitting split index over many child bodies.
4. Win32/API ownership: rejected. `HINSTANCE` is a Win32 type, but the field and accessor are NexusTK `StartupWindow` source.
5. Compiler/padding/no-code ownership: rejected. Current bytes and IDA function record prove source-bearing accessor code.

## Source Placement

Keep source placement in `NexusTK/app/StartupWindow.cpp` through [UID:0000O5]. UID0004CV should remain a class-owned by-memory child that emits through the file root. No new file, new global owner, new helper route, or support-page split is justified.

The report does not recommend any support-doc score changes. `by-class/StartupWindow.md`, `by-file/StartupWindow.md`, and [UID:0001IO] already carry the exact child inventory, source route, and non-emitting aggregate policy at sufficient detail.

## First-Draft C++ Recommendation

Keep the existing formal target block unchanged. If the supervisor accepts this report, the target implementation should preserve this exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HINSTANCE StartupWindow::GetInstanceHandle() const
{
    return m_instance;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not add helper abstractions, file-local wrappers, broad aggregate code, or an inline-only no-emitter disposition. The body maps one-to-one to the observed four-byte function.

## Final Recommendation

UID0004CV implementation callback is complete and ready for supervisor execution:

- Target metadata is now `COMPLETION:88`, `CONFIDENCE:92`.
- `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank optional position were preserved.
- The existing formal C++ block was preserved unchanged.
- Target evidence now records MCP session `nexustk_supervisor_20260704`: active IDB health, function size, no xrefs/callers, disassembly, bytes/padding, decompile, and constructor `this+0x08` write.
- Target prose explains that pre-callback tracker state lacked a UID0004CV-specific executed report because the existing executed B008 report was a UID0000O5 family/split report.
- The no-current-caller and inferred-name/member-name confidence caps remain explicit.

## Recommended Target Doc Changes

For `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md`:

These changes were applied during the callback:

1. Metadata changed from `COMPLETION:86`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:92`.
2. Metadata unchanged: `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank optional position.
3. Formal C++ block kept exactly as previously written.
4. `Evidence` expanded into current-session target facts:
   - MCP session `nexustk_supervisor_20260704`;
   - `lookup_funcs 0x00581660`: `sub_581660`, size `0x4` / 4 bytes (Verified with int_convert.py);
   - no function at `0x00581664`, no function at `0x0058165a`, successor `0x00581670`;
   - `analyze_function` no callers/callees, one basic block;
   - `xrefs_to 0x00581660`: zero refs;
   - `disasm`: `mov eax, [ecx+8]; retn`;
   - `get_bytes`: six `0xcc` bytes before, body bytes `8b 41 08 c3`, twelve `0xcc` bytes after;
   - constructor `0x005807d0` writes the `HINSTANCE` argument at `[ecx+8]`.
5. Source-quality note added: no callers cap confidence, but no-code/padding/compiler-wrapper reclassification is rejected because IDA models a real four-byte accessor and the constructor field write proves semantic content.
6. Report-history note added: B008 family report created and validated the child, but pre-callback tracker state had no UID0004CV-specific executed B report.

## Recommended Support Doc Changes

No support-doc edits were required for acceptance. Current support state was inspected and already sufficient:

- `by-class/StartupWindow.md` lists the accessor in the `state access/helper` child range and links UID0004CV through the accepted B008 split.
- `by-file/StartupWindow.md` lists UID0004CV among exact source-bearing child pages and preserves `NexusTK/app/StartupWindow.cpp`.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` lists UID0004CV as an exact child returning the `HINSTANCE` at `this+0x08`, preserves the no-current-caller caveat, and remains non-emitting.
- `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md` already documents the constructor's `HINSTANCE` storage at `this+8`.

No one-line support sync note was added because the accepted callback said support docs were expected already-present and inspection found no lower-detail or stale contradiction.

## Score And Metadata Recommendation

| Path | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md` | Pre-callback `86/88`, owner `0000DZ`, emitter `0000O5`, formal C++ present | Applied `88/92`, owner/emitter/C++ unchanged | Fresh UID-specific MCP evidence confirms exact function, zero xrefs, bytes, padding, constructor `HINSTANCE` field, generated output, and tracker/report-history reason. |
| `by-class/StartupWindow.md` | `88/89` | unchanged | Child inventory and field notes are already sufficient; no broader class audit needed. |
| `by-file/StartupWindow.md` | `89/88` | unchanged | File route and exact child list are already sufficient. |
| `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` | `88/90`, non-emitting | unchanged | Split index already lists UID0004CV and should not emit broad code. |

The recommended `88/92` target score is deliberately conservative: completion remains below 90 because the target page only needs a small evidence refresh, while confidence can rise because the exact four-byte behavior and field source are now strongly proven. Confidence remains capped below final because there are no current callers and the exact original source names are inferred.

## Open Questions With Attempted Resolution

- Why is UID0004CV still in the not-covered tracker? Resolved: B008 executed a UID0000O5 StartupWindow family/split report and created UID0004CV, but the tracker row for UID0004CV still reports `0` UID-specific executed reports. This report provides the missing UID-specific coverage.
- Should a no-caller four-byte function be removed or marked no-code? Resolved against removal: IDA models it as a real function, bytes are executable, and constructor field evidence gives semantic content. No callers are a confidence cap only.
- Is `GetInstanceHandle` the original name? Unresolved but acceptable: generated/source-facing naming and Win32 field semantics support it; no PDB/source symbol proves exact spelling.
- Is `m_instance` the original field name? Unresolved but acceptable: constructor child and generated output use this source-facing name; exact spelling remains inferred.
- Should the target score exceed 92 confidence? No. Zero xrefs and inferred naming prevent high-final confidence even though behavior is exact.

## Validator Results

Callback validation was run for the changed target by-memory doc from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0004CV-StartupWindowGetInstanceHandle-source-quality-removed.md](0004CV-StartupWindowGetInstanceHandle-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Command id: `000000006412`
- Command timestamp: `2026-07-04T18:20:33-04:00`
- Exit code: `0`
- Ok count: `1`
- Reported effects: `completion_update` UID0004CV to `88`, `confidence_update` UID0004CV to `92`, `stats_incremental_noop` for absent generated stats-list membership, `projected_stats_update` for the projected completion section, and `generated_refresh: deferred`.
- Warnings/errors: none reported.

Generated freshness was then checked read-only. `auto-generated/NexusTK/app/StartupWindow.cpp` currently reports `validator-command-id: 000000006415`, `validator-refreshed-at: 2026-07-04T18:21:32-04:00`, contains UID0004CV at `Completion:88 | Confidence:92`, and still emits `HINSTANCE StartupWindow::GetInstanceHandle() const` returning `m_instance`. The generated file was refreshed by validator infrastructure only, not manually edited.

## Changed Files

Implementation callback changed:

- `tools/leaser/Agents/Agent-B013/research/0004CV-StartupWindowGetInstanceHandle-source-quality.md`
- `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md`
- `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed by validator infrastructure after the scoped target validation; not manually edited.

Support by-* docs were inspected and not edited: `by-class/StartupWindow.md`, `by-file/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, and `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md`.

Lease used and released: `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md` leased by B013 immediately before edit and unleased after validation. No coverage reports, validator state, supervisor ledgers, lifecycle/archive files, executed-report registries, or manual generated files were edited.

## Implementation Tracking Checklist

- [x] Target metadata updated in `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md`: `COMPLETION:88`, `CONFIDENCE:92`, owner `0000DZ`, reconstructable true, emitter `0000O5`.
- [x] Target formal C++ block preserved exactly as `HINSTANCE StartupWindow::GetInstanceHandle() const { return m_instance; }`.
- [x] Target evidence updated with MCP session `nexustk_supervisor_20260704`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, and `get_bytes` facts.
- [x] Target boundary notes record six `0xcc` prebytes, body bytes `8b 41 08 c3`, twelve `0xcc` postbytes, no function at `0x00581664`, and successor `0x00581670`.
- [x] Target constructor relationship records `StartupWindow__Constructor` storing the `HINSTANCE` argument at `this+0x08` / `this[2]`.
- [x] Target prose preserves zero-current-caller and inferred-name/member-name confidence caps.
- [x] Target prose rejects no-code, padding, compiler-wrapper, Win32/API ownership, file-only ownership, and broad aggregate ownership alternatives.
- [x] Target prose explains why UID0004CV lacked a UID-specific executed B report before this callback despite the B008 family/split implementation.
- [x] Support docs inspected and found already-present; no support edits required.
- [x] Scoped validator run for the target by-memory doc from `source-3/project-documentation`: command `000000006412`, timestamp `2026-07-04T18:20:33-04:00`, exit `0`, ok `1`.
- [x] Generated `auto-generated/NexusTK/app/StartupWindow.cpp` freshness checked after validation: header `000000006415`, refreshed `2026-07-04T18:21:32-04:00`, UID0004CV still returns `m_instance`.
- [x] Claim And Incorporation Ledger verification states updated from `proposed` to `applied` or `already-present`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000006438","destination_path":"executed-b-agent-research/B013/0004CV-StartupWindowGetInstanceHandle-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0004CV-StartupWindowGetInstanceHandle-source-quality.md","timestamp":"2026-07-04T18:27:54-04:00","uid":"0004CV"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004CV-StartupWindowGetInstanceHandle-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0004CV-StartupWindowGetInstanceHandle-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004CV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
