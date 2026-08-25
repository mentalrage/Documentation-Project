** TARGET-REPORT-UID:0002JW **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 Research Report: 0002JW ApplicationReadProcessorName Source Quality

Report status: FINISHED_REPORT
Assignment: B003-report-0002JW-ApplicationReadProcessorName-source-quality-20260627
Target: [UID:0002JW] `by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md`
Required output: report-only research artifact

## Scope And Constraints

- Used the project-level `ntk-b-agent-workflow` skill instructions.
- Did not spawn subagents.
- Did not start, stop, or restart IDA MCP.
- Did not edit by-* documentation during report-only work.
- Did not edit generated reports, generated C++ files, project-level generated files, manual coverage reports, validator/tool state, or the IDA database.
- No leases were acquired because this is report-only work.
- No validators were run because no by-* documentation was changed in this pass.

## Current Target Snapshot

The source target currently records:

- `COMPLETION: 85`
- `CONFIDENCE: 89`
- `CANONICAL_OWNER: [UID:00000D] by-class/Application.md`
- `EMITTER_UIDS: [UID:00000D] by-class/Application.md`
- `RECONSTRUCTABLE: TRUE`
- blank formal `RECONSTRUCTION_CPP CODE`

The generated tracker and generated Application.cpp still show stale `80/87` empty-marker state for this UID. Treat those as generated refresh lag, not the current source-page truth.

## MCP Availability And Session Evidence

Mandatory MCP-backed evidence was available and used.

- Listener check: `127.0.0.1:13337` accepted TCP connections.
- Listener process: Python listener PID `21700`, creation time `2026-06-27 12:27:25` local.
- Related process state observed: `idalib-mcp` PID `10020`; worker/session Python PID `23132`.
- JSON-RPC initialize succeeded against `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- Active IDB session: `b001_000241_20260627`.
- Active IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Server health: status `ok`; module `NexusTK.exe`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; auto-analysis, Hex-Rays, and strings cache ready; `is_analyzing:false`.

## MCP Findings

### Target Bytes And Boundaries

`get_bytes(0x00465130, 0x88)` returned a complete 136-byte body:

```text
55 8b ec 81 ec 0c 08 00 00 a1 24 2f 67 00 33 c5 89 45 fc 56 8d 85 f8 f7 ff ff 8b f1 50 6a 01 6a 00 68 f8 28 61 00 68 02 00 00 80 ff 15 18 d0 60 00 8d 85 f4 f7 ff ff c7 85 f4 f7 ff ff 00 08 00 00 50 8d 85 fc f7 ff ff 50 6a 00 6a 00 68 58 29 61 00 ff b5 f8 f7 ff ff ff 15 14 d0 60 00 ff b5 f8 f7 ff ff ff 15 10 d0 60 00 8d 85 fc f7 ff ff 50 8d 4e 1c e8 77 db 11 00 8b 4d fc 33 cd 5e e8 7b 25 16 00 8b e5 5d c3
```

The adjacent padding spans are still all `0xcc`:

- `0x00465124-0x00465130`: `cc` padding.
- `0x004651b8-0x004651c0`: `cc` padding.

MCP `lookup_funcs` reports no IDA function object at `0x00465130`, `0x004651b7`, or `0x004651b8`; neighboring defined functions begin at `0x004651c0`, `0x004651d0`, `0x004651e0`, and `0x004651f0`. The target is therefore raw but cleanly bounded and method-shaped.

### Instruction-Level Behavior

`insn_query(0x00465130, 0x004651b8)` returned 38 instructions with `fn:null`. The body:

- builds a stack frame with `/GS` security cookie and an 0x80c-byte local area;
- preserves `this` in `esi`;
- opens `HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0` with `RegOpenKeyExW(..., KEY_QUERY_VALUE, &processorKey)`;
- sets a `DWORD` size local to `0x800`;
- queries `ProcessorNameString` with `RegQueryValueExW`;
- closes the key with `RegCloseKey`;
- assigns the local wide buffer into the Application member at `this + 0x1c` by calling `sub_582D20`;
- performs the security cookie check and returns.

Return values from all registry APIs are ignored, and the key handle is used unconditionally. The formal C++ should preserve that behavior and should not add error handling.

### String And Field Evidence

The registry path and value name are exact:

- Raw UTF-16 at `0x006128f8`: `HARDWARE\DESCRIPTION\System\CentralProcessor\0`
- Raw UTF-16 at `0x00612958`: `ProcessorNameString`

MCP `search_text("ProcessorNameString")` in the Application area found exactly two hits:

- `0x0046355e` inside `Application__Constructor`
- `0x0046517d` inside this raw target

`xrefs_to` confirms both data references for each string: one from the constructor duplicate sequence and one from this target. No other processor-name reader was found in the searched Application region.

The destination object for this target is `this + 0x1c`. B008's accepted Application accessor report and the current Application class notes distinguish that pointer-backed StringBase-style member from the fixed DAT filename buffer at `this + 0x428`. Fresh MCP also confirms the DAT accessor at `0x004652e0` uses `lea eax, [ecx+428h]` and `_wcscpy_s`, so `+0x428` must not be reused as processor-name evidence.

### String Helper Evidence

`analyze_function(0x00582d20)` reports a 65-byte `__thiscall` helper that:

- releases the current wide buffer via `sub_5833A0`;
- computes `wcslen(source)`;
- allocates a new wide buffer via `sub_582E30`;
- copies `2 * length` bytes using `memmove`.

The executed B006 StringBase report and generated StringBase.cpp name this helper role `StringBase<wchar_t, mychar_traits<wchar_t> >::AssignWideLiteral`. The target's call site passes `ecx = this + 0x1c`, so the source-facing Application member should be represented as a StringBase-style `m_processorName` and the call should be emitted as `m_processorName.AssignWideLiteral(processorName)`.

### Duplicate Constructor Sequence

`insn_query(0x00463527, 0x0046358a)` inside `Application__Constructor` shows the same registry sequence:

- `RegOpenKeyExW` on `HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0`;
- `RegQueryValueExW` on `ProcessorNameString`;
- `RegCloseKey`;
- assignment into `edi + 0x1c` through `sub_582D20`.

This duplicate supports the member identification and behavior. It does not cover the raw range at `0x00465130-0x004651b8`: the constructor emits a separate byte range and cannot justify a covered-by no-code marker for this target.

### Reachability And Pointer-Route Evidence

- `xrefs_to(0x00465130)` returned no cross-references.
- `find_bytes("30 51 46 00")` returned zero matches, so no simple absolute pointer to the target start was found.
- `make_signature_for_range(0x00465130, 0x004651b8)` produced a unique signature for the byte body.

The absence of an IDA function object and absence of direct xrefs remain real confidence caps. They are not current-scope C++ blockers: the body is complete, uniquely bounded, Application-owned, reconstructable, and semantically exact. It should be treated as a retained raw private helper or source-authored duplicate helper unless a later whole-program route proves it dead. Do not mark it as constructor-covered no-code.

## Source Quality Decision

All assignment-scope blockers were investigated:

- MCP was available and used.
- Raw/no-function status was confirmed.
- Direct xrefs and simple pointer references were checked and remain absent.
- Constructor duplicate coverage was checked and rejected as a no-code rationale for this range.
- The `+0x428` DAT filename confusion was checked against B008 and live MCP and does not apply.
- The `+0x1c` StringBase-style assignment helper was checked against live MCP and the StringBase generated source.

Recommendation: make [UID:0002JW] source-ready with formal C++ instead of leaving the C++ block blank.

Recommended target metadata:

- `COMPLETION: 88`
- `CONFIDENCE: 91`
- `CANONICAL_OWNER: [UID:00000D] by-class/Application.md`
- `EMITTER_UIDS: [UID:00000D] by-class/Application.md`
- `RECONSTRUCTABLE: TRUE`

Rationale for `88/91`: the behavior, constants, range boundaries, field offset, Application ownership, and helper semantics are now MCP-confirmed and sufficient for first-draft C++. The score should remain below a 95+ final-audit tier because the target is still raw, has no direct caller route, and uses inferred source names for the method and member.

Recommended source-facing names:

- Method: `Application::ReadProcessorName`
- Member: `m_processorName` at `this + 0x1c`
- Local key: `processorKey`
- Local size: `processorNameBytes`
- Local buffer: `processorName[0x400]`

`ReadProcessorName` is a descriptive inferred name, not an original symbol proof. It matches the existing Application class/file naming already attached to this UID and the exact registry-read behavior.

## Exact Formal C++ For Supervisor-Approved Insertion

Insert this exact managed block into `by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md`:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Application::ReadProcessorName()
{
    HKEY processorKey;
    DWORD processorNameBytes;
    wchar_t processorName[0x400];

    RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                  L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                  0,
                  KEY_QUERY_VALUE,
                  &processorKey);

    processorNameBytes = sizeof(processorName);
    RegQueryValueExW(processorKey,
                     L"ProcessorNameString",
                     NULL,
                     NULL,
                     reinterpret_cast<LPBYTE>(processorName),
                     &processorNameBytes);
    RegCloseKey(processorKey);

    m_processorName.AssignWideLiteral(processorName);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not add registry error checks, key-handle guards, alternate default strings, or buffer zeroing in the formal body; those behaviors are not present in the target bytes.

## Target Documentation Updates To Apply

Update `by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md` as follows:

- Change header scores to `COMPLETION: 88` and `CONFIDENCE: 91`.
- Keep `CANONICAL_OWNER`, `EMITTER_UIDS`, and `RECONSTRUCTABLE` unchanged.
- Replace the blank formal C++ block with the exact block above.
- Update the Item Summary to say the raw target is a source-ready Application processor-name registry reader with raw/no-route confidence caps.
- Add a Current MCP Evidence section recording session `b001_000241_20260627`, listener availability, raw/no-function status, 38-instruction body, exact strings, zero direct xrefs, zero simple pointer hits, and unique signature.
- Update Behavior/Reconstruction Notes to state that the constructor sequence is a duplicate, not a covered-by range.
- Update score rationale to explain why C++ is now emitted and why remaining raw/no-route evidence caps the score.
- Add a change-log note for Agent-B003 report `0002JW-ApplicationReadProcessorName-source-quality.md`.

Suggested Item Summary replacement:

```text
Raw retained Application processor-name registry reader; fresh MCP confirms a complete unique method-shaped body that opens HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0, reads ProcessorNameString into a 0x400-wchar stack buffer, and assigns it through the StringBase-style member at Application +0x1c. Formal first-draft Application::ReadProcessorName C++ is recommended; confidence remains capped by raw/no-function status and lack of direct xrefs.
```

## Support Documentation Updates To Apply

Apply only after the supervisor accepts this report and acquires the required leases.

- `by-class/Application.md`
  - Change the [UID:0002JW] method row from candidate/blank-C++ wording to source-ready `ReadProcessorName`.
  - Keep the no-direct-caller caveat.
  - Ensure `+0x1c` remains the inferred `m_processorName` StringBase-style member and `+0x428` remains DAT filename only.

- `by-file/Application.md`
  - Update the Application responsibilities/source-readiness note to say [UID:0002JW] now has formal first-draft C++ under Application emission.
  - Retain the raw/no-route caveat.

- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
  - Update the child table/coverage wording for [UID:0002JW] to `88/91`, source-ready formal C++ with raw/no-route cap.
  - Keep the aggregate lifecycle page no-code unless separately justified.

- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
  - Optional support edit only if the supervisor wants a backlink: state that the constructor contains a duplicate inline processor-name read, while [UID:0002JW] emits the separate retained helper body.
  - Do not use the constructor to mark [UID:0002JW] as covered-by/no-code.

No generated report or generated C++ file should be edited by hand. Validator/autogen should refresh those files after by-* changes are made.

## Validation Plan For Implementation Pass

After supervisor applies documentation edits, run targeted validators. Include `--wait-generated` on the target because adding formal C++ should refresh generated Application.cpp and coverage artifacts.

> Executable block R001 was removed from this report and preserved verbatim in [0002JW-ApplicationReadProcessorName-source-quality-removed.md](0002JW-ApplicationReadProcessorName-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional constructor backlink is edited:

> Executable block R002 was removed from this report and preserved verbatim in [0002JW-ApplicationReadProcessorName-source-quality-removed.md](0002JW-ApplicationReadProcessorName-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validator/autogen effects:

- `auto-generated/NexusTK/app/Application.cpp` should replace the [UID:0002JW] empty emitter marker with `Application::ReadProcessorName`.
- Generated coverage should stop reporting [UID:0002JW] as `emits_code:false`.
- No manual edits should be made to generated coverage or generated C++.

## Implementation Tracking Checklist

- [x] Acquire leases for `by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md`, `by-class/Application.md`, `by-file/Application.md`, and `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` before editing. Proof: B003 acquired the four edit leases before the by-* edits; after validation, B003 also acquired a validator-only lease for `by-memory/0x004652e0-0x004652fc.ApplicationCopyDatFileName.md` to repair the stale [UID:0002JY] path mapping surfaced by the target validator. `python .\tools\leaser\leaser.py B003 unlease` released the remaining B003 lease successfully, and `current_leases.md` has no B003 entries.
- [x] Update [UID:0002JW] header scores to `COMPLETION: 88` and `CONFIDENCE: 91`. Proof: `by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md` header now carries `COMPLETION:88` and `CONFIDENCE:91`; target validator command `000000004711` returned exit code 0 with `ok: 1`.
- [x] Keep [UID:0002JW] owner/emitter/reconstructable fields unchanged. Proof: the target header still uses `CANONICAL_OWNER:00000D`, `EMITTER_UIDS:00000D`, and `RECONSTRUCTABLE:TRUE`; target validator command `000000004711` accepted the file.
- [x] Insert the exact managed formal C++ block from this report into [UID:0002JW]. Proof: the target formal `RECONSTRUCTION_CPP CODE` block contains `void Application::ReadProcessorName()` with the accepted Win32 registry open/query/close sequence and `m_processorName.AssignWideLiteral(processorName)` call; generated `auto-generated/NexusTK/app/Application.cpp` now emits the same UID as code.
- [x] Update [UID:0002JW] summary, evidence, behavior notes, score rationale, and change log to reflect fresh MCP-backed source readiness. Proof: target sections now record session `b001_000241_20260627`, raw/no-function status, 136-byte body, `/GS` frame and `0x80c` local area, exact registry strings, no xrefs/pointer hits, constructor duplicate evidence, `0x00582d20` assignment role, `+0x1c` versus `+0x428`, and the 88/91 score rationale.
- [x] Update Application class support docs so [UID:0002JW] is source-ready, while preserving the no-direct-caller caveat. Proof: `by-class/Application.md` now lists [UID:0002JW] as source-ready `Application::ReadProcessorName`, preserves the raw/no-direct/pointer-route caveat, updates the `m_processorName` field row, and records the 2026-06-27 B003 evidence/change-log entry; validator command `000000004714` returned exit code 0 with `ok: 1`.
- [x] Update Application file support docs so [UID:0002JW] is listed as formal first-draft C++. Proof: `by-file/Application.md` now states that [UID:0002JW] emits formal first-draft C++ in `NexusTK/app/Application.cpp` and preserves the no-route confidence cap and `+0x428` DAT-buffer distinction; validator command `000000004715` returned exit code 0 with `ok: 1`.
- [x] Update ApplicationLifecycle child coverage wording for [UID:0002JW] to `88/91`. Proof: `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` now includes an 88/91 source-ready [UID:0002JW] child row and covered-method wording with the raw/no-route caveat; validator command `000000004717` returned exit code 0 with `ok: 1`.
- [x] Optionally add the constructor backlink only if the supervisor wants the duplicate inline read called out there. Proof/exclusion: no constructor edit was needed because `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` already records the duplicate `ProcessorNameString` read from `HKEY_LOCAL_MACHINE\HARDWARE\DESCRIPTION\System\CentralProcessor\0`, the `AssignWideLiteral` call, and the `this + 0x1c` StringBase-style member at sufficient detail.
- [x] Run the target validator with `--wait-generated`. Proof: `python .\tools\validator.py --mode file --file by-memory\0x00465130-0x004651b8.ApplicationReadProcessorName.md --apply --queue-timeout 240 --wait-generated` returned exit code 0, `ok: 1`, `command_id: 000000004711`, `command_timestamp: 2026-06-27T23:04:19-04:00`, and `generated_refresh: completed`.
- [x] Run support-document validators. Proof: `by-class\Application.md` validator command `000000004714` at `2026-06-27T23:05:33-04:00`, `by-file\Application.md` command `000000004715` at `2026-06-27T23:05:39-04:00`, and `by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md` command `000000004717` at `2026-06-27T23:05:47-04:00` all returned exit code 0 with `ok: 1`. Extra validator-only cleanup for `by-memory\0x004652e0-0x004652fc.ApplicationCopyDatFileName.md` command `000000004712` repaired the stale [UID:0002JY] path mapping without manual content edits.
- [x] Inspect generated Application.cpp and generated coverage artifacts for validator-owned refresh only. Proof: generated queue status command `000000004719` showed zero queued/processing jobs; `auto-generated/NexusTK/app/Application.cpp` header is `validator-command-id: 000000004717`, `validator-refreshed-at: 2026-06-27T23:05:47-04:00`, newer than target validator `000000004711`; generated coverage/tracker rows show [UID:0002JW] as `coded`, `yes`, output `auto-generated/NexusTK/app/Application.cpp`, and tracker score `88/91`.
- [x] Confirm generated Application.cpp emits [UID:0002JW] as code and no longer as an empty marker. Proof: `auto-generated/NexusTK/app/Application.cpp` contains `// UID:0002JW ... Completion:88 | Confidence:91`, `void Application::ReadProcessorName()`, and `m_processorName.AssignWideLiteral(processorName)`; no [UID:0002JW] empty-emitter marker remains.
- [x] Confirm no generated files, manual coverage reports, validator/tool state, or IDA DB were manually edited. Proof: manual edits were limited to the accepted by-* support docs and this report checklist via patch; generated files/reports, validator state, and coverage link/index changes were validator-owned side effects of the scoped validator commands; no IDA DB writes were performed.

## Residual Risks

- No direct caller or pointer route to `0x00465130` was found. This should cap confidence but should not block C++ emission for this reconstructable Application-owned helper.
- IDA still has no function object for this range. The byte boundary, padding, unique signature, and complete prologue/body/epilogue shape make the range source-quality enough, but it is not final-audit proof.
- `ReadProcessorName`, `m_processorName`, and local variable names are source-facing inferred names, not recovered original symbols.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002JW-ApplicationReadProcessorName-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002JW-ApplicationReadProcessorName-source-quality.md","timestamp":"2026-06-27T23:09:33","uid":"0002JW"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002JW-ApplicationReadProcessorName-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002JW-ApplicationReadProcessorName-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002JW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
