** TARGET-REPORT-UID:0002PZ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002PZ BaramAppConstructorRaw Empty-Emitter Source-Quality Report

Assignment: `B003-report-0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality-20260628`  
Target: `by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md`  
Mode: report-only research first; no by-* edits, no leases, no generated/project/manual coverage/tool/IDA edits.

## Disposition

[UID:0002PZ] should not remain a blank code-ready empty emitter. The range is a complete, constructor-shaped out-of-line `BaramApp` constructor body:

- it forwards the same three constructor arguments to `Application__Constructor`;
- it installs the primary and secondary `BaramApp` vtable pointers at `this+0` and `this+4`;
- it performs no other member initialization; and
- it returns `this` with `retn 0Ch`, matching a three-argument `__thiscall` constructor.

Recommended metadata after implementation:

- `COMPLETION:89`
- `CONFIDENCE:92`
- keep `CANONICAL_OWNER:00000V`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:00000V`
- keep `EMITTER_POSITION_OPTIONAL:` blank
- keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank and insert the formal code in the multiline block.

The score should not go higher yet because IDA still does not promote this exact start as a function, the constructor start has no direct call/data xrefs, Hex-Rays cannot decompile `0x004f5f20` as a function, and the original header/source-file split for `BaramApp` is still inferred. Those are final-confidence limits only; they are not blockers to a formal first-draft constructor.

## Exact Formal RECONSTRUCTION_CPP CODE

Insert this exact block into the target's multiline `RECONSTRUCTION_CPP CODE` block:

```cpp
BaramApp::BaramApp(HINSTANCE hInstance,
                   const wchar_t *publisherName,
                   const wchar_t *applicationTitle)
    : Application(hInstance, publisherName, applicationTitle)
{
}
```

The constructor signature is first-draft source-facing reconstruction. `HINSTANCE` is inferred from the `_WinMain@16` caller and the `Application` constructor evidence. `publisherName` and `applicationTitle` are inferred from the existing `WinMain` formal source shape, which constructs `BaramApp app(hInstance, kPublisherName, kApplicationTitle);`, and from the push order into `Application__Constructor`.

## MCP Availability And Session Evidence

MCP was required and used. The active session remained available after the evidence pass.

- Session/database: `supervisor_20260628_resume`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input executable: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module/image base: `NexusTK.exe`, `0x400000`
- Health: `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, `strings_cache_size=2067`
- Final health probe during report preparation returned `status=ok`, `uptime_sec=11666.691`

One broad nonessential text search for `004F5F20` timed out, and a follow-up health check succeeded. I did not use that timeout as fallback evidence. The accepted evidence below comes from successful MCP byte, instruction, xref, global, entity, function, and decompile calls plus current by-* docs.

## Current Target State

The target currently has:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00000V`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000V`
- blank formal C++.

The current target text correctly recognizes that the body forwards into `Application__Constructor`, writes primary and secondary `BaramApp` vptrs, and returns `this`. The stale part is the conclusion that final C++ must stay blank until the source split/layout names clear a later gate. That caution now creates the empty-emitter problem: the code-entry gate is met, and the body has enough current evidence for a source-facing empty derived constructor with a base initializer.

The generated file is also stale relative to current by-memory metadata. `auto-generated/NexusTK/app/Application.cpp` still shows a UID0002PZ empty-emitter marker with old `Completion:80` and `Confidence:88`; the source target is already `85/90`. After the implementation callback, the target validator must refresh generated output and prove UID0002PZ no longer appears as an `Empty Emitter Marker`.

## MCP Function And Range Evidence

`lookup_funcs` showed the raw constructor range is not an IDA function, while adjacent/source-related ranges are functions:

- `0x004f5f17`: no function
- `0x004f5f20`: no function
- `0x004f5f33`: no function
- `0x004f5f4e`: no function
- `0x004f5f50`: `sub_4F5F50`, size `0x5f`
- `0x004f5fb0`: `sub_4F5FB0`, size `0x4e0`
- `0x00463310`: `Application__Constructor`, size `0x65e`
- `0x004f5c80`: `_WinMain@16`, size `0x297`

The exact bytes for `0x004f5f20-0x004f5f4e` are:

```text
55 8b ec 51 56 ff 75 10 8b f1 ff 75 0c 89 75 fc
ff 75 08 e8 d8 d3 f6 ff c7 06 18 d1 61 00 8b c6
c7 46 04 38 d1 61 00 5e 8b e5 5d c2 0c 00
```

The wider bytes at `0x004f5f17` show nine `0xCC` bytes before the constructor and two `0xCC` bytes after the constructor. The following real function begins at `0x004f5f50`. This supports the existing split:

- constructor body: `0x004f5f20-0x004f5f4e`;
- padding: `0x004f5f4e-0x004f5f50`;
- next child: `0x004f5f50-0x004f5faf`.

No split change is needed.

## Instruction-Level Semantics

MCP `insn_query` for `0x004f5f20-0x004f5f4e` returned 17 instructions, all outside an IDA function:

```text
0x004f5f20  push ebp
0x004f5f21  mov ebp, esp
0x004f5f23  push ecx
0x004f5f24  push esi
0x004f5f25  push dword ptr [ebp+10h]
0x004f5f28  mov esi, ecx
0x004f5f2a  push dword ptr [ebp+0Ch]
0x004f5f2d  mov [ebp-4], esi
0x004f5f30  push dword ptr [ebp+8]
0x004f5f33  call Application__Constructor
0x004f5f38  mov dword ptr [esi], offset ??_7BaramApp@@6B@
0x004f5f3e  mov eax, esi
0x004f5f40  mov dword ptr [esi+4], offset ??_7BaramApp@@6B@_0
0x004f5f47  pop esi
0x004f5f48  mov esp, ebp
0x004f5f4a  pop ebp
0x004f5f4b  retn 0Ch
```

This is the standard MSVC constructor shape for a class with a nontrivial base and multiple vptrs:

- `ecx` is saved as `this` in `esi`;
- stack arguments `[ebp+8]`, `[ebp+0Ch]`, and `[ebp+10h]` are forwarded to the base constructor in right-to-left push order;
- `Application__Constructor` performs base initialization;
- the derived constructor overwrites base vptrs with `BaramApp` vtables;
- `eax = this` is returned;
- `retn 0Ch` pops the three explicit arguments.

The two explicit vtable writes are compiler output from the source constructor and class declaration. They should not be hand-emitted as raw source statements in the formal C++ block.

## Xref And Liveness Evidence

MCP xrefs show no direct code/data xref to the raw constructor start:

- `xrefs_to(0x004f5f20)`: none.
- `find_bytes` for an absolute pointer to `0x004f5f20`: no matches.

This negative evidence explains why IDA has not promoted the range into a function and why no IDA rename/function-object edit should be made in this pass. It does not prove the range is not source-authored. The body itself contains live semantic references:

- `0x004f5f33` calls `Application__Constructor`;
- `0x004f5f38` references primary `BaramApp` vtable data at `0x0061d118`;
- `0x004f5f40` references secondary `BaramApp` vtable data at `0x0061d138`.

`xrefs_to(0x00463310)` returned two callers:

- `0x004f5cca` in `_WinMain@16`;
- `0x004f5f33` in the raw constructor body.

`xrefs_to(0x0061d118)` returned:

- `0x004f5ccf` in `_WinMain@16`;
- `0x004f5f38` in the raw constructor body.

`xrefs_to(0x0061d138)` returned:

- `0x004f5cd9` in `_WinMain@16`;
- `0x004f5f40` in the raw constructor body.

The duplicated `_WinMain@16` base-constructor call and vptr stores are consistent with the local stack construction being inlined there while the out-of-line constructor body remains emitted at `0x004f5f20`.

## Vtable And RTTI Evidence

`get_global_value` confirms the primary and secondary `BaramApp` vtable region already documented by the support docs:

```text
0x0061d118 -> 0x004f66c0
0x0061d11c -> 0x004f4b10
0x0061d120 -> 0x0041b6c0
0x0061d124 -> 0x004f5fb0
0x0061d128 -> 0x004f6490
0x0061d12c -> 0x004669c0
0x0061d130 -> 0x00466a70
0x0061d134 -> 0x0064a014
0x0061d138 -> 0x004f66b5
0x0061d13c -> 0x00465ce0
```

`entity_query` over the vtable range returns:

- `0x0061d118`: `??_7BaramApp@@6B@`
- `0x0061d138`: `??_7BaramApp@@6B@_0`

The primary vtable begins at `0x0061d118`; the secondary vtable begins at `0x0061d138`. Existing vtable support docs identify the secondary deleting-destructor thunk at `0x004f66b5`, which adjusts `this -= 4` before reaching the primary destructor path. The constructor's `this+4` vptr store is therefore a real secondary-base/secondary-view vptr install, not an unknown field write.

## Decompiler Evidence

`decompile(0x004f5f20)` failed with `Decompilation failed at 0x4f5f20`, which is expected because no IDA function object exists at that address. This is negative IDA-model evidence only.

`decompile(0x004f5c80)` for `_WinMain@16` produced a bad-stack warning but still exposed the relevant inlined construction sequence:

- call `Application__Constructor((int)hInstance, (wchar_t *)aNe, (wchar_t *)aNe_0)` at `0x004f5cca`;
- write `BaramApp::vftable` at `0x004f5ccf`;
- write the secondary `BaramApp::vftable` at `0x004f5cd9`.

The current `WinMain` by-memory formal C++ is better source-facing evidence than the decompiler: it already reconstructs the source as `BaramApp app(hInstance, kPublisherName, kApplicationTitle);`.

## Source-Facing Signature And Names

The accepted first-draft formal signature should be:

```cpp
BaramApp::BaramApp(HINSTANCE hInstance,
                   const wchar_t *publisherName,
                   const wchar_t *applicationTitle)
```

Rationale:

- `_WinMain@16` pushes `hInstance` into the same first explicit constructor argument position, and the `Application` constructor stores/uses it as the application instance handle.
- The two string arguments are passed through unchanged into `Application__Constructor`.
- The current `WinMain` reconstruction names the source literals as `kPublisherName` and `kApplicationTitle`, so `publisherName` and `applicationTitle` are the most realistic local parameter names for the constructor.
- The strings are read/copied by the base constructor and not mutated by this body, so `const wchar_t *` is the best first-draft source-facing type even though the current decompiler-style `Application__Constructor` prototype still prints non-const `wchar_t *`.

The exact original parameter names remain unproven. That uncertainty should be documented as inferred naming, not used to keep the formal block blank.

## Ownership, Emitter Route, And Source Placement

Keep:

- owner: `BaramApp` / [UID:00000V];
- emitter: `BaramApp` / [UID:00000V];
- source route: `by-file/Application.md` / generated `auto-generated/NexusTK/app/Application.cpp`.

Do not move this target to `Application` or `_WinMain@16`. The call to `Application__Constructor` is a base-initializer side effect, not ownership evidence for `Application`. The `_WinMain@16` sequence proves one inlined stack construction site, not ownership of the out-of-line constructor body.

Do not create or require a new `app/BaramApp.cpp` route in this pass. The docs already route `BaramApp` through the application shell source file. A separate source file is plausible but not proven by current evidence.

## Rejected Alternatives

1. Keep UID0002PZ as a blank formal C++ emitter.
   - Rejected. The current code-entry gate is met, and the body has an exact first-draft source shape: an empty derived constructor with a base initializer.

2. Use a comment-only covered-by marker.
   - Rejected. The target is not raw vtable bytes, RTTI, padding, or unavoidable compiler-only glue. It is a complete constructor body with a source-facing declaration and body.

3. Clear `EMITTER_UIDS` or set `RECONSTRUCTABLE:FALSE`.
   - Rejected. The body is project code and is reconstructable as source, even if not directly called in the current IDA xref graph.

4. Emit raw vtable-write statements in the formal C++ block.
   - Rejected. `*(void **)this = ...` and `*(void **)((char *)this + 4) = ...` would preserve binary mechanics but not plausible human-written source. The class declaration and constructor definition cause the compiler to write those vptrs.

5. Keep decompiler-style parameters such as `int a2`, `wchar_t *Source`, and `wchar_t *a4`.
   - Rejected for this constructor's source-facing formal block. Those names/types describe an IDA/base-constructor boundary. The target has enough caller/source-context evidence for `HINSTANCE hInstance`, `publisherName`, and `applicationTitle`.

6. Promote or rename an IDA function at `0x004f5f20`.
   - Rejected for this B-agent pass. IDA DB edits are out of scope, and the no-start-xref/no-function evidence explains why the IDB is cautious.

## Required Implementation Edits After Supervisor Acceptance

### Target: `by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md`

Update metadata and target prose at report-level detail:

- set `COMPLETION:89`;
- set `CONFIDENCE:92`;
- keep owner/emitter/reconstructable fields as described above;
- replace the stale "final C++ stays blank" empty-emitter explanation with the resolved disposition that the range emits a first-draft `BaramApp::BaramApp(...)` constructor;
- insert the exact formal C++ block from this report into the multiline `RECONSTRUCTION_CPP CODE` block;
- document the exact bytes, instruction sequence, `Application__Constructor` forwarding, vtable writes, return convention, and `0xCC` padding boundaries;
- document no direct start xref/no function/decompile failure as IDA-model negative evidence only;
- document that `_WinMain@16` contains an inlined equivalent stack construction sequence;
- document that source-facing names are inferred from the current `WinMain` formal source and `Application` constructor evidence.

### Support: `by-class/BaramApp.md`

Update the BaramApp class doc to record the resolved constructor disposition:

- child [UID:0002PZ] moves to `89/92`;
- the constructor now has a formal first-draft C++ block;
- `BaramApp` remains the owner/emitter;
- no function object/no direct constructor-start xref remains a liveness/IDA-model caveat, not a C++ blocker;
- source route remains through `by-file/Application.md` unless later source-file evidence proves a separate `BaramApp.cpp`.

### Support: `by-file/Application.md`

Update the application shell source-route doc to record:

- [UID:0002PZ] now contributes source to generated `Application.cpp` as `BaramApp::BaramApp(...)`;
- generated `Application.cpp` currently has a stale empty-emitter marker for UID0002PZ and must refresh after the target validator/report execution;
- the constructor's source shape is an empty body with base initializer, not raw vptr stores;
- the existing `Application::Startup` and `WinMain` source evidence continue to support the `BaramApp` route and names.

### Support: `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`

Update the aggregate doc to keep the aggregate itself non-emitting/mixed but record that child [UID:0002PZ] is no longer a blank empty emitter:

- child range `0x004f5f20-0x004f5f4e` now has formal first-draft constructor C++;
- padding `0x004f5f4e-0x004f5f50` remains padding;
- child `0x004f5f50-0x004f5faf` and later startup/destructor/thunk ranges remain separate;
- do not emit aggregate-level C++ that duplicates or conflates child ranges.

### Support: `by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md`

Update the vtable support doc only to the extent needed to synchronize evidence:

- the constructor at [UID:0002PZ] now has source-facing C++ that explains the primary/secondary vptr stores as compiler output from the class constructor;
- raw vtable arrays remain compiler-generated `.rdata` evidence and should not be hand-emitted as source;
- keep the existing primary/secondary slot facts and secondary thunk facts.

### Support Docs Checked, No Required Edit

These docs already contain same-or-greater useful facts and do not require edits unless the supervisor wants cross-reference wording:

- `by-memory/0x004f5c80-0x004f5f17.WinMain.md`: already has `BaramApp app(hInstance, kPublisherName, kApplicationTitle);` and the inlined base-constructor/vtable-store sequence.
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`: already documents the raw BaramApp forwarding call and the source-facing role of `hInstance` plus the two string parameters.
- `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`: callback naming does not block the constructor disposition.
- `by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md`: destructor/vtable reachability remains independent of the constructor formal block.

## Validator And Generated-Refresh Plan After Callback

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality-removed.md](0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the target validator with `--wait-generated`, check:

- `auto-generated/NexusTK/app/Application.cpp` has a validator header equal to or newer than the target validator `command_timestamp`;
- UID0002PZ no longer appears as an `Empty Emitter Marker`;
- generated `Application.cpp` contains the accepted formal `BaramApp::BaramApp(...)` constructor block, or, if the generator routes class methods differently, contains an explicit non-empty UID0002PZ formal emission consistent with the inserted block.

Do not edit generated files manually.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md`: metadata changed to `COMPLETION:89`, `CONFIDENCE:92`, owner/emitter/reconstructable fields preserved. Proof: target validator command `python .\tools\validator.py --mode file --file by-memory\0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md --apply --queue-timeout 240 --wait-generated`, `command_id: 000000005239`, `command_timestamp: 2026-06-28T18:39:37-04:00`, exit `0`, `ok: 1`.
- [x] Target: exact formal `RECONSTRUCTION_CPP CODE` block inserted as specified in this report. Proof: generated refresh from target validator emitted `BaramApp::BaramApp(HINSTANCE hInstance, const wchar_t *publisherName, const wchar_t *applicationTitle) : Application(hInstance, publisherName, applicationTitle) {}` for UID0002PZ in `auto-generated/NexusTK/app/Application.cpp`.
- [x] Target: stale blank-empty-emitter explanation replaced with resolved constructor disposition, including bytes, instruction sequence, base-constructor forwarding, primary/secondary vptr stores, return convention, padding/range split, negative xref/function/decompile evidence, and inferred source-facing names. Proof: target doc now records the raw byte sequence, 17-instruction constructor sequence, `Application__Constructor` call, two `BaramApp` vptr stores, `retn 0Ch`, no-function/no-start-xref/decompile failure caveat, and source-facing constructor signature.
- [x] `by-class/BaramApp.md`: child UID0002PZ score/status/source-route notes updated and no-start-xref caveat preserved as nonblocking. Proof: support validator command `python .\tools\validator.py --mode file --file by-class\BaramApp.md --apply --queue-timeout 240`, `command_id: 000000005223`, `command_timestamp: 2026-06-28T18:37:59-04:00`, exit `0`, `ok: 1`.
- [x] `by-file/Application.md`: application source-route/generator notes updated for UID0002PZ constructor emission and stale generated empty marker. Proof: support validator command `python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240 --wait-generated`, `command_id: 000000005227`, `command_timestamp: 2026-06-28T18:38:23-04:00`, exit `0`, `ok: 1`.
- [x] `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`: aggregate child matrix/status updated while aggregate remains mixed/non-emitting. Proof: support validator command `python .\tools\validator.py --mode file --file by-memory\0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md --apply --queue-timeout 240`, `command_id: 000000005231`, `command_timestamp: 2026-06-28T18:38:54-04:00`, exit `0`, `ok: 1`.
- [x] `by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md`: vtable evidence synchronized with the constructor source interpretation; raw vtable arrays remain non-source evidence. Proof: support validator command `python .\tools\validator.py --mode file --file by-memory\0x0061d118-0x0061d140.BaramAppVtableData.md --apply --queue-timeout 240`, `command_id: 000000005234`, `command_timestamp: 2026-06-28T18:39:14-04:00`, exit `0`, `ok: 1`.
- [x] No manual edits made to generated reports, project-level files, manual coverage-report files, tool state, validator state, or IDA DB. Proof: implementation edits were limited to the five accepted by-* docs and this research checklist; required validators produced their own generated/project/registry side effects, including generated refresh and registry/stat updates, and IDA MCP was used read-only.
- [x] Short-lived leases acquired only during the implementation edit/validator batch and cleared after validation. Proof: B003 leased exactly the five accepted by-* paths before editing; post-validation release attempt reported `Rejected[No active lease]` for all five paths, and `tools/leaser/Agents/current_leases.md` reported `No active leases.`
- [x] Target validator run with `--wait-generated`; report command, `command_id`, `command_timestamp`, exit code, and `ok` count. Proof: `python .\tools\validator.py --mode file --file by-memory\0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md --apply --queue-timeout 240 --wait-generated`, `command_id: 000000005239`, `command_timestamp: 2026-06-28T18:39:37-04:00`, exit `0`, `ok: 1`.
- [x] Support validators run; report command, `command_id`, `command_timestamp`, exit code, and `ok` count for each. Proof: `by-class\BaramApp.md` command `000000005223` at `2026-06-28T18:37:59-04:00`, exit `0`, `ok: 1`; `by-file\Application.md` command `000000005227` at `2026-06-28T18:38:23-04:00`, exit `0`, `ok: 1`; `by-memory\0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` command `000000005231` at `2026-06-28T18:38:54-04:00`, exit `0`, `ok: 1`; `by-memory\0x0061d118-0x0061d140.BaramAppVtableData.md` command `000000005234` at `2026-06-28T18:39:14-04:00`, exit `0`, `ok: 1`.
- [x] Generated `auto-generated/NexusTK/app/Application.cpp` checked after target validator: UID0002PZ no longer appears as an `Empty Emitter Marker` and emits the accepted formal constructor content. Proof: generated header shows `validator-command-id: 000000005252` and `validator-refreshed-at: 2026-06-28T18:41:46-04:00`; UID0002PZ lines 276-282 emit the accepted constructor block, and UID0002PZ does not appear in any `Empty Emitter Marker` line.
- [x] This checklist updated with implementation proof after supervisor acceptance and callback. Proof: checklist completed during the accepted implementation callback after validators, generated marker check, and lease-state verification.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality.md","timestamp":"2026-06-28T18:51:21","uid":"0002PZ"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
