** TARGET-REPORT-UID:00014F **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014F TopLevelExceptionFilter Source-Quality Report

Assignment: `B001-goal2-top-level-exception-filter-source-quality-00014F-20260619`  
Report-only pass: by-* target/support docs, generated files, IDA DB, project-level files, and `by-memory/-coverage-report.md` were not edited.  
Target: [UID:00014F] `by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md`

## Finalized Report / Current Recommendation

- Recommendation: update [UID:00014F] from `84/90` to `88/91`.
- Metadata route: keep `CANONICAL_OWNER:00014D`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00014D`.
- Source placement: keep the final destination in [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp`, reached through [UID:00014D] -> [UID:00004P] -> [UID:0000J8].
- C++ readiness: populate first-draft C++ on this exact child page. Do not put the callback body in the [UID:00014D] aggregate except through a valid child insertion route or optional aggregate `[[CHILDREN]]` marker.
- Stale wording to remove: the current target's "Final C++ is pending exact child-body source entry under the active combined-score/emitter gate" and parent-score wording are stale after B005 aggregate incorporation and this child-specific pass. The active C++ gate is met after the recommended score update and the emitter route is valid.
- Coverage action: supervisor should replace the [UID:00014F] row in `by-memory/-coverage-report.md` with the exact row below; this report does not edit the shared coverage report.

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00014D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00014D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Target State Checked

Current target state:

- UID: `00014F`
- Range/title: `0x004ab830-0x004ab86f TopLevelExceptionFilter`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, owner/emitter [UID:00014D]
- Current C++ block: empty
- Current status claims: reconstructable Windows unhandled-exception filter callback, installed by the ExceptionHandler constructor, no direct callers, calls KeySpeedMgr restore and crash report writer, checks `[g_pCrashTarget + 4]`, chains object offset `+8`
- Current stale facts: parent sentence still says aggregate is `84/88`; aggregate is now `86/90`. The target still names raw `dword_67AB48` in its 2026-06-06 section while project-level resolved aliases already know `g_pKeySpeedMgr`. The target says C++ is merely pending instead of giving the now-ready first-draft body.

Generated/current report state:

- `auto-generated/NexusTK/platform/ExceptionHandler.cpp` currently has an empty marker for [UID:00014F], not C++:

```text
// UID:00014F | by-memory\0x004ab830-0x004ab86f.TopLevelExceptionFilter.md | Completion:84 | Confidence:90 | Empty Emitter Marker
```

- `auto-generated/-ag-memory-coverage.md` confirms [UID:00014F] currently emits through [UID:00014D] to `auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- `project-level/-auto-completion-stats.md` lists [UID:00014F] as `84/90`, average `87.0`.
- `project-level/-resolved.md` still marks [UID:00014F] as pending for `dword_67AB48 -> g_pKeySpeedMgr` because the target text preserves the raw name.

## Evidence Sources Checked

Required guidance and workflow:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `by-structure.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- `by-memory/-guidance.md`

Primary target and direct support docs:

- [UID:00014F] `by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md`
- [UID:00014D] `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`
- [UID:00004P] `by-class/ExceptionHandler.md`
- [UID:0000J8] `by-file/ExceptionHandler.md`
- [UID:0000QN] `by-global/g_pCrashTarget.md`
- [UID:000297] `by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md`
- [UID:00014G] `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`
- [UID:0000RB] `by-global/g_pKeySpeedMgr.md`
- [UID:00018P] `by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md`
- [UID:000129] `by-memory/0x0049bae0-0x0049bbef.Crasher.md`
- [UID:00003A] `by-class/Crasher.md`
- [UID:0000II] `by-file/Crasher.md`
- [UID:0001QB] `by-meta/client_crash_diagnostics.md`

Project/generated context:

- `by-project-structure/proposed-source-tree.md`
- `project-level/-auto-completion-stats.md`
- `project-level/-resolved.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/NexusTK/platform/ExceptionHandler.cpp`
- `by-memory/-coverage-report.md` row for [UID:00014F], read only

Prior reports used as leads, then rechecked against current docs/bytes:

- B005 executed report `tools/leaser/Agents/Agent-B005/research/executed/00014D-ExceptionHandler-source-quality.md`
- B001 executed report `tools/leaser/Agents/Agent-B001/research/executed/000129-crasher-source-quality.md`
- B015 pending report `tools/leaser/Agents/Agent-B015/research/00014F-TopLevelExceptionFilter-source-quality.md`

IDA MCP status:

- Current-session IDA MCP was unavailable. `Invoke-WebRequest` to `http://127.0.0.1:13337/mcp` returned `Unable to connect to the remote server`.
- This report therefore uses prior live-IDA evidence already incorporated into accepted docs, plus current raw PE byte/disassembly checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Raw PE / Disassembly Recheck

Raw file checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`  
Image base assumption: `0x00400000` and `.text` raw mapping used by current docs (`VA 0x00401000` maps to raw `0x400`).  
Target VA `0x004ab830` maps to raw file offset `0xaac30` / 699440 (Verified with `tools/int_convert.py`).

Raw bytes from `0x004ab830-0x004ab870`:

```text
55 8b ec 8b 0d 48 ab 67 00 56 8b 35 34 ab 67 00
85 c9 74 05 e8 e7 46 04 00 85 f6 74 1b 80 7e 04
01 74 15 ff 75 08 8b ce e8 13 00 00 00 8b 46 08
85 c0 74 04 5e 5d ff e0 33 c0 5e 5d c2 04 00 cc
```

Body length: `0x3f` / 63 bytes (Verified with `tools/int_convert.py`).  
Body SHA-1: `363a9d8b3621bf21c5bf64df650a77807eca7bc3`  
Body SHA-256: `8a6771641a81534c98f97228e3a1dbfc2786aa2bdcb86dcf8d480f74783d79b0`  
Post-body byte at `0x004ab86f`: `0xcc`, one-byte padding before [UID:00014G] starts at `0x004ab870`.

Capstone disassembly:

```text
004ab830: push   ebp
004ab831: mov    ebp, esp
004ab833: mov    ecx, dword ptr [0x67ab48]
004ab839: push   esi
004ab83a: mov    esi, dword ptr [0x67ab34]
004ab840: test   ecx, ecx
004ab842: je     0x4ab849
004ab844: call   0x4eff30
004ab849: test   esi, esi
004ab84b: je     0x4ab868
004ab84d: cmp    byte ptr [esi + 4], 1
004ab851: je     0x4ab868
004ab853: push   dword ptr [ebp + 8]
004ab856: mov    ecx, esi
004ab858: call   0x4ab870
004ab85d: mov    eax, dword ptr [esi + 8]
004ab860: test   eax, eax
004ab862: je     0x4ab868
004ab864: pop    esi
004ab865: pop    ebp
004ab866: jmp    eax
004ab868: xor    eax, eax
004ab86a: pop    esi
004ab86b: pop    ebp
004ab86c: ret    4
```

Constructor callback pointer check:

```text
004ab499: mov    dword ptr [0x67ab34], eax
004ab49e: push   0x4ab830
004ab4a3: mov    dword ptr [esi], 0x6196c0
004ab4a9: call   dword ptr [0x60d198]
004ab4af: mov    dword ptr [esi + 8], eax
```

The immediate bytes for `0x004ab830` appear once in the PE at raw offset `0xaa89f`, corresponding to VA `0x004ab49f`. The instruction starts at `0x004ab49e` because the byte at `0x004ab49e` is the `push imm32` opcode. This matches the current docs' `0x004ab49e/0x004ab49f` wording and proves the callback route through `SetUnhandledExceptionFilter`.

## Behavior Reconstruction

Direct binary behavior:

1. Load `g_pKeySpeedMgr` from `0x0067ab48` into `ecx`.
2. Load `g_pCrashTarget` from `0x0067ab34` into `esi`.
3. If `g_pKeySpeedMgr` is non-null, call `0x004eff30`, source-facing [UID:00018P] `KeySpeedMgr::RestoreSystemKeyboardSettings()`.
4. If the snapshot of `g_pCrashTarget` is null, return `0`.
5. If byte `[g_pCrashTarget + 4]` equals `1`, return `0` without writing the normal crash report and without chaining to the previous filter.
6. Otherwise push the incoming `EXCEPTION_POINTERS *`, set `ecx = g_pCrashTarget`, and call [UID:00014G] `0x004ab870`, source-facing `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)`.
7. Read dword `[g_pCrashTarget + 8]`; if non-null, tail-jump to that saved previous filter with the original caller stack intact.
8. If no previous filter is saved, return `0`.

Windows callback interpretation:

- `ret 4` and the one stack argument match `LONG WINAPI (*)(EXCEPTION_POINTERS *)`.
- Return `0` is `EXCEPTION_CONTINUE_SEARCH`.
- The `jmp eax` tail-call is source-equivalent to `return previousFilter(exceptionInfo);`; the tail jump preserves the original exception-info argument and lets the previous filter's stdcall return clean the stack.
- The filter does not inspect `ExceptionRecord` or `ContextRecord` itself. It forwards the `EXCEPTION_POINTERS *` to the writer.

## Heuristic / Inference Reanalysis And Validation

### 1. Stale blank-C++ / gate wording

Question: Should [UID:00014F] still say final C++ is pending?

Evidence checked:

- `by-memory/-guidance.md` states the active reconstruction-code gate is `RECONSTRUCTABLE:TRUE`, confirmed nonblank `EMITTER_UIDS` reaching generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- Current target is reconstructable, has `EMITTER_UIDS:00014D`, and `auto-generated/-ag-memory-coverage.md` shows the route reaches `auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- The current average is already `87.0`, and the recommended score `88/91` gives `89.5`.
- Raw bytes and support docs resolve the body and dependency names enough for a first-draft C++ body.

Best direction: replace the stale blocker with first-draft C++ readiness. The target should rise, not stay `84/90`.

Rejected alternatives:

- Leave C++ blank until 95/95: rejected because the old threshold is explicitly obsolete.
- Leave C++ blank because the aggregate is not a monolithic body: rejected for this exact child. The aggregate should stay blank or `[[CHILDREN]]`, but the child is a normal source-authored callback body.

Score impact: completion rises materially because the main blocker is resolved. Confidence rises slightly because raw bytes match prior IDA docs and generated route checks.

### 2. Callback name and signature

Question: What source-facing name/signature should replace raw or decompiler forms?

Evidence checked:

- The current target and prior IDA docs use `TopLevelExceptionFilter`.
- Constructor pushes the function pointer directly to imported `SetUnhandledExceptionFilter`.
- Body ends in `ret 4`, has one pointer argument, and returns `LONG`-style values.
- `by-class/ExceptionHandler.md` and `by-file/ExceptionHandler.md` already list a file-static `TopLevelExceptionFilter` helper.
- There are no direct ordinary callers or exports requiring external linkage.

Best direction: `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)`.

Rejected alternatives:

- `ExceptionHandler::TopLevelExceptionFilter`: possible as a static member, but weaker because the body uses the global active target and current support docs explicitly route it as a file-static helper. If future source metadata proves static-member form, the body is mechanically equivalent.
- Class virtual method: rejected. There is no vtable slot or `this` receiver; Windows calls it by a plain function pointer.
- CRT/SEH runtime helper: rejected. It is installed by NexusTK `ExceptionHandler` construction and touches NexusTK globals/fields.
- `UnhandledExceptionFilter`: rejected as a function name because that is the Windows API concept/name; using it would collide semantically with the imported/default API family. `TopLevelExceptionFilter` is the best current source-facing callback name.

Remaining uncertainty: exact original linkage spelling (`static` versus external/global) is inferred. No source/debug metadata proves original text. This caps final-audit confidence but does not block draft C++.

### 3. `g_pCrashTarget` type and fields

Question: What are object offsets `+4` and `+8`?

Evidence checked:

- [UID:0000QN] and [UID:000297] identify `dword_67AB34` as `ExceptionHandler *g_pCrashTarget`.
- Constructor writes `g_pCrashTarget = this`.
- Constructor clears byte `+4`.
- [UID:000129] `Crasher::TriggerCrash` writes byte `[g_pCrashTarget + 4] = 1` before an intentional null write.
- This filter compares `[target + 4]` to `1` and skips normal report generation when set.
- Constructor stores the return from `SetUnhandledExceptionFilter` at `this+8`.
- Destructor/rest body restores the saved filter from `this+8`.
- This filter reads `[target + 8]` and tail-calls it.

Best direction:

- `0x0067ab34`: `ExceptionHandler *g_pCrashTarget`
- `+0x04`: `bool m_skipCrashReport`
- `+0x05..+0x07`: padding
- `+0x08`: `LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter`

Rejected alternatives:

- Name `m_suppressCrashReport`: semantically valid, but B005/current docs standardized `m_skipCrashReport`; use the settled name unless stronger source evidence appears.
- Treat `+4` as a generic state byte: rejected because the only documented semantics are specifically skip normal crash report for intentional Crasher path.
- Treat `+8` as arbitrary callback/global: rejected because constructor/destructor/filter all tie it directly to `SetUnhandledExceptionFilter`.

Remaining uncertainty: exact original field spelling is not source-proven. The descriptive names are strong enough for source-facing docs and C++ draft.

### 4. KeySpeedMgr restore dependency

Question: Is raw `dword_67AB48` / `sub_4EFF30` resolved?

Evidence checked:

- [UID:0000RB] resolves `dword_67AB48` as `g_pKeySpeedMgr`.
- [UID:00018P] resolves `0x004eff30` as `KeySpeedMgr::RestoreSystemKeyboardSettings`.
- [UID:00018P] caller evidence includes this filter at `0x004ab844`.
- `project-level/-resolved.md` marks [UID:00014F] as pending for `dword_67AB48 -> g_pKeySpeedMgr` only because this target still preserves raw wording.
- Disassembly loads `g_pKeySpeedMgr` into `ecx`, tests it, then calls `0x004eff30`.

Best direction: target should use `g_pKeySpeedMgr->RestoreSystemKeyboardSettings()`, with address evidence preserved in raw-evidence sections only.

Rejected alternatives:

- Move or own the filter under KeySpeedMgr: rejected. KeySpeedMgr is a cleanup dependency; it does not install the exception filter or own `g_pCrashTarget`.
- Name the method `RestoreKeyboardSettings`: rejected for target implementation because the exact current support-doc name is `RestoreSystemKeyboardSettings`.

Score impact: resolves a generated/raw name issue and removes the project-level alias pending row for this target after validation.

### 5. Suppress-report behavior

Question: What exactly happens when `m_skipCrashReport` is set?

Evidence checked:

- Disassembly branch at `0x004ab84d-0x004ab851` jumps directly to `xor eax,eax; ret 4`.
- No call to [UID:00014G] occurs on that branch.
- No previous-filter chain occurs on that branch.
- [UID:000129] sets the flag before intentional diagnostic crash.

Best direction: wording should say the filter skips normal `BCrash.nfo` generation and returns `EXCEPTION_CONTINUE_SEARCH` / `0` when `m_skipCrashReport` is set. It should not say the previous filter is always chained.

Rejected alternatives:

- "Suppress report but still chain previous filter": rejected by the branch target.
- "Suppress all crash handling": too broad; Windows will continue searching because the callback returns `0`.

### 6. Previous-filter chain

Question: How should `[target + 8]` be modeled?

Evidence checked:

- Constructor call to `SetUnhandledExceptionFilter` stores EAX at `this+8`.
- Destructor/reset restores that value.
- Filter reads `[esi+8]`, tests it, and `jmp eax` after popping `esi`/`ebp`.
- Windows type for this callback is `LPTOP_LEVEL_EXCEPTION_FILTER`.

Best direction: source-facing field `LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter`; C++ body should use `return previousFilter(exceptionInfo);`.

Rejected alternatives:

- Direct `jmp`/function-pointer trampoline in handwritten C++: rejected as compiler/tailcall output.
- Generic saved callback pointer name: weaker than `m_previousFilter` because the SetUnhandledExceptionFilter lifecycle proves the role.

### 7. No-direct-caller callback route

Question: Does no direct caller mean dead code?

Evidence checked:

- Current target and class docs say `callers 0x004ab830` is empty.
- Raw scan found exactly one embedded VA pointer to `0x004ab830`, at constructor VA `0x004ab49f`.
- Constructor instruction at `0x004ab49e` is `push 0x4ab830` immediately before imported `SetUnhandledExceptionFilter`.

Best direction: no ordinary direct callers is expected and is positive callback evidence, not liveness doubt.

Rejected alternatives:

- Unreachable/dead retained function: rejected by the constructor callback registration.
- Ordinary helper called elsewhere: rejected by direct caller evidence and raw pointer scan.

### 8. ExceptionHandler versus Crasher ownership boundary

Question: Does Crasher's write to `g_pCrashTarget + 4` make this filter or field Crasher-owned?

Evidence checked:

- Crasher has its own [UID:0000II] `platform/Crasher.cpp` route and [UID:00003A] class.
- Crasher writes the flag but does not install the filter, own `g_pCrashTarget`, call the crash writer, or store/restore the previous filter.
- [UID:0000QN] and [UID:000297] place `g_pCrashTarget` under [UID:0000J8] `ExceptionHandler.cpp`.
- `by-project-structure/proposed-source-tree.md` keeps `ExceptionHandler.cpp` and `Crasher.cpp` as separate platform companions.

Best direction: keep `Crasher` as a consumer of `ExceptionHandler::m_skipCrashReport`; do not move [UID:00014F] out of ExceptionHandler.

Rejected alternatives:

- Fold this filter into `Crasher.cpp`: rejected because Crasher only sets the flag for deliberate crash behavior.
- Move the field to Crasher docs as owner: rejected because the field lives in `ExceptionHandler` object layout and is cleared/read by ExceptionHandler code.

### 9. ExceptionHandler aggregate versus exact child source placement

Question: Should C++ go in [UID:00014D] aggregate or this exact child?

Evidence checked:

- [UID:00014D] covers many exact children, raw helper bodies, padding, compiler-generated scalar deleting destructor output, and data/switch islands.
- B005 incorporated a no-monolithic-aggregate policy.
- Current generated output has separate markers for [UID:00014D], [UID:00014F], [UID:00014G], and other children.
- This target is a complete single source-authored callback body with exact boundaries and valid emitter route.

Best direction: keep owner/emitter [UID:00014D] for current route stability, but put the code in [UID:00014F]'s C++ block. The aggregate can stay blank or use `[[CHILDREN]]` if the generator needs a parent insertion point.

Rejected alternatives:

- Move [UID:00014F] directly to [UID:00004P] or [UID:0000J8] now: plausible but not needed. Other child pages are split between [UID:00014D] and [UID:00004P]; changing this one route would be a broader emitter cleanup outside the target need.
- Put a full source file skeleton in [UID:00014D]: rejected as monolithic aggregate C++.

### 10. Source access style: fields, accessors, friend, or static member

Question: How can a file-static callback access `m_skipCrashReport` and `m_previousFilter`?

Evidence checked:

- Binary uses direct field reads.
- Current [UID:00004P] declaration guidance already mentions draft inline accessors `ShouldSkipCrashReport()` and `PreviousFilter()`.
- No out-of-line accessor functions exist, so if accessors are used they must be inline and compile away.
- A file-static callback could also be declared as a friend or the fields could have non-private access; no source metadata proves either.

Best direction: first-draft C++ should use inline accessors in the callback body, because this avoids raw offset leakage and is compatible with a private class layout. The implementation checklist should also allow a direct-field variant if the class declaration later chooses friend/static-member/public-field access.

Rejected alternatives:

- Use `*((BYTE *)target + 4)` and `*(DWORD *)(target + 8)` in final C++: rejected as decompiler pollution.
- Add out-of-line getter bodies: rejected because no functions exist; inline only.

Score impact: source access style is the main remaining source-shape uncertainty. It caps score below final audit, but it does not block target C++ because both accessor and direct-field variants compile to the documented behavior.

### 11. Prior B015 report comparison

Question: Should B001 follow the B015 recommendation exactly?

Evidence checked:

- B015 correctly identified first-draft C++ readiness, [UID:00014D] owner/emitter retention, file-static callback shape, field names, and coverage row need.
- B015 held completion to `85`, citing current-session IDA unavailability and exact original helper spellings.
- This B001 pass additionally rechecked raw PE bytes, disassembled the exact body, verified the one callback pointer hit, preserved the snapshot/load order of `g_pCrashTarget`, and corrected the KeySpeed method spelling to `RestoreSystemKeyboardSettings`.

Best direction: converge with B015 on ownership/C++ readiness but recommend a stronger completion score: `88/91` instead of `85/91`. The target is short, exact, and fully source-shaped once the C++ block and raw-name cleanup are applied.

Rejected alternatives:

- Keep B015 `85/91`: too conservative after the raw byte/disassembly recheck and because `85` would understate the effect of adding detailed C++ and removing stale blocker text.
- Exceed low 90s confidence: rejected because exact original source linkage/access style remains inferred and current-session IDA MCP was unavailable.

## First-Draft C++ Recommendation

Populate [UID:00014F]'s `RECONSTRUCTION_CPP CODE` block with this body:

```cpp
static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)
{
    KeySpeedMgr *keySpeedMgr = g_pKeySpeedMgr;
    ExceptionHandler *target = g_pCrashTarget;

    if (keySpeedMgr != 0) {
        keySpeedMgr->RestoreSystemKeyboardSettings();
    }

    if (target == 0 || target->ShouldSkipCrashReport()) {
        return EXCEPTION_CONTINUE_SEARCH;
    }

    target->WriteCrashReport(exceptionInfo);

    LPTOP_LEVEL_EXCEPTION_FILTER previousFilter = target->PreviousFilter();
    if (previousFilter != 0) {
        return previousFilter(exceptionInfo);
    }

    return EXCEPTION_CONTINUE_SEARCH;
}
```

Why this is plausible mid-2000s source rather than decompiler output:

- It uses the Windows callback type (`LONG WINAPI`) and SDK constants instead of raw `int`/`0` intent-free returns, while preserving the binary value `EXCEPTION_CONTINUE_SEARCH == 0`.
- It uses explicit null comparisons (`!= 0`, `== 0`) consistent with pre-C++11 style and avoids `nullptr`, `auto`, lambdas, or C++11 constructs.
- It names the active globals and methods (`g_pKeySpeedMgr`, `RestoreSystemKeyboardSettings`, `g_pCrashTarget`, `WriteCrashReport`) instead of preserving `dword_` or `sub_` names.
- It does not hand-author the tail `jmp eax`; a normal function-pointer return lets the compiler choose tailcall or call/return.
- It avoids raw `this+offset`/cast pointer arithmetic. The inline accessors are a declaration-level solution for a file-static callback accessing class state.
- It snapshots `g_pKeySpeedMgr` and `g_pCrashTarget` before restore to match the observed load order.

Equivalent acceptable variant if the class declaration makes `TopLevelExceptionFilter` a friend/static member or fields non-private:

```cpp
static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)
{
    KeySpeedMgr *keySpeedMgr = g_pKeySpeedMgr;
    ExceptionHandler *target = g_pCrashTarget;

    if (keySpeedMgr != 0) {
        keySpeedMgr->RestoreSystemKeyboardSettings();
    }

    if (target == 0 || target->m_skipCrashReport) {
        return EXCEPTION_CONTINUE_SEARCH;
    }

    target->WriteCrashReport(exceptionInfo);

    if (target->m_previousFilter != 0) {
        return target->m_previousFilter(exceptionInfo);
    }

    return EXCEPTION_CONTINUE_SEARCH;
}
```

The accessor version is the recommended report implementation because it fits current [UID:00004P] class guidance and avoids forcing a friend/static-member decision in this child-only pass.

## Exact Target Implementation Instructions

Apply these to `by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md` after supervisor acceptance:

1. Change metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter [UID:00014D].
2. Populate the `RECONSTRUCTION_CPP CODE` block with the recommended first-draft C++ above.
3. Update `## Status`:
   - Keep disposition and source module.
   - Replace parent sentence with: attached to [UID:00014D], now `86/90`; child route emits through [UID:00014D] -> [UID:00004P] -> [UID:0000J8].
   - Replace stale C++ blocker with: first-draft C++ is ready on this exact child page; do not place the callback body in the monolithic aggregate.
4. Add or update `## Source Shape / Signature`:

```text
Best current source signature is `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)`. The constructor installs it through `SetUnhandledExceptionFilter`; no ordinary direct callers are expected. It is a file-scope Windows callback in `platform/ExceptionHandler.cpp`, not a class virtual method, Crasher method, KeySpeedMgr method, CRT helper, or generic SEH runtime helper.
```

5. Replace behavior bullets with source-facing names:
   - snapshot/read `g_pKeySpeedMgr` and call `KeySpeedMgr::RestoreSystemKeyboardSettings()` when live;
   - snapshot/read `g_pCrashTarget` as `ExceptionHandler *`;
   - return `EXCEPTION_CONTINUE_SEARCH` / `0` when no active target exists;
   - return `EXCEPTION_CONTINUE_SEARCH` / `0` without writing or chaining when `m_skipCrashReport` at `+0x04` is set;
   - call [UID:00014G] `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)` otherwise;
   - chain `m_previousFilter` at `+0x08` if present.
6. Add raw byte/disassembly evidence from this report or a condensed version sufficient to prove the branch/order/return behavior.
7. Normalize raw names:
   - `dword_67AB34` -> `g_pCrashTarget` in explanatory/source-facing text, with raw alias preserved only in evidence.
   - `dword_67AB48` -> `g_pKeySpeedMgr`.
   - `sub_4EFF30` -> `KeySpeedMgr::RestoreSystemKeyboardSettings`.
   - `sub_4AB870` -> `ExceptionHandler::WriteCrashReport`.
   - object offset `+4` -> `m_skipCrashReport`.
   - object offset `+8` -> `m_previousFilter`.
8. Add a `## Score Rationale` section:

```text
`88/91` reflects exact 63-byte body/boundary evidence, one-byte `0xcc` padding before [UID:00014G], one constructor callback-pointer route and no ordinary direct callers, resolved Windows `LONG WINAPI` callback shape, resolved `g_pCrashTarget` field roles, resolved `g_pKeySpeedMgr` restore dependency, exact report-writer callee, first-draft C++ readiness, and stable source placement in `platform/ExceptionHandler.cpp`. It remains below final-audit quality because exact original source linkage/access style and field/helper spellings are descriptive inferences rather than source/debug-symbol proof, and current-session IDA MCP was unavailable.
```

9. Add a `## Changes` entry dated 2026-06-20 or the supervisor implementation date:

```text
- 2026-06-20 B001 source-quality implementation:
  - Recommended `84/90 -> 88/91`; owner/emitter remain [UID:00014D].
  - Resolved the stale blank-C++/gate wording and added first-draft `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)` C++ on the exact child page.
  - Normalized raw names to `g_pCrashTarget`, `g_pKeySpeedMgr`, `KeySpeedMgr::RestoreSystemKeyboardSettings`, `ExceptionHandler::WriteCrashReport`, `m_skipCrashReport`, `m_previousFilter`, and `EXCEPTION_CONTINUE_SEARCH`.
  - Evidence: raw PE byte/disassembly recheck confirms the exact 63-byte body at raw offset `0xaac30`, `ret 4`, one-byte post padding, sole callback pointer at constructor VA `0x004ab49f`, KeySpeed restore call at `0x004ab844`, report-writer call at `0x004ab858`, suppress-report branch, and previous-filter tailcall.
```

## Support-Doc Implementation Checklist

Do not apply these during the report-only pass. Apply after supervisor acceptance if touched by the target implementation.

1. [UID:00014D] `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`
   - Update the child row for [UID:00014F] to state it now has first-draft child C++ and `88/91`.
   - Preserve aggregate formal C++ blank or `[[CHILDREN]]` only; do not paste the callback body into the aggregate.
   - Add that [UID:00014F] now closes the stale child C++ blocker while raw no-static-caller helpers remain aggregate score caps.

2. [UID:00004P] `by-class/ExceptionHandler.md`
   - Ensure declaration guidance includes either inline accessors:

```cpp
bool ShouldSkipCrashReport() const { return m_skipCrashReport; }
LPTOP_LEVEL_EXCEPTION_FILTER PreviousFilter() const { return m_previousFilter; }
```

   - Keep field names `m_skipCrashReport` and `m_previousFilter`.
   - Note [UID:00014F] is a file-static callback, not a class virtual method. If a future declaration pass chooses a static member or friend callback, record it as an access-style refinement, not a behavior change.

3. [UID:0000J8] `by-file/ExceptionHandler.md`
   - Update likely contents to say [UID:00014F] has first-draft source-ready callback code.
   - Keep `platform/ExceptionHandler.cpp` as the source root.
   - Preserve `Crasher.cpp` and `KeySpeedMgr.cpp` as companion/dependency files, not owners.

4. [UID:0000QN] `by-global/g_pCrashTarget.md` and [UID:000297] `by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md`
   - No owner/emitter change recommended.
   - If edited, update the filter link to say [UID:00014F] now has first-draft C++ and reads `m_skipCrashReport`/`m_previousFilter` through source-facing names.

5. [UID:0000RB] `by-global/g_pKeySpeedMgr.md` and [UID:00018P] `by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md`
   - No metadata change recommended from this target.
   - If edited, preserve exact caller `0x004ab844` and source-facing callee name `RestoreSystemKeyboardSettings`.

6. [UID:000129] `by-memory/0x0049bae0-0x0049bbef.Crasher.md`, [UID:00003A] `by-class/Crasher.md`, [UID:0000II] `by-file/Crasher.md`
   - No score or owner change recommended.
   - If touched, make only a cross-reference wording update: Crasher consumes `ExceptionHandler::m_skipCrashReport`; it does not own the filter, global, or report writer.

7. [UID:0001QB] `by-meta/client_crash_diagnostics.md`
   - If touched, replace any wording implying the filter simply "checks `[target + 4]`" with source-facing `m_skipCrashReport` and note the suppressed path returns `EXCEPTION_CONTINUE_SEARCH` without writing or chaining.

8. Generated output after implementation
   - Run validator/autogen. Inspect `auto-generated/NexusTK/platform/ExceptionHandler.cpp` and verify:
     - [UID:00014F] no longer appears only as an "Empty Emitter Marker".
     - The generated body includes `TopLevelExceptionFilter`, `RestoreSystemKeyboardSettings`, `WriteCrashReport`, and previous-filter call.
     - [UID:00014D] remains aggregate blank or child-routing only.

## Exact Coverage Row Recommendation

Current row read from `by-memory/-coverage-report.md`:

```text
    - [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) : reconstructable : 84% : strong : Live IDA reconfirms TopLevelExceptionFilter bounds 0x004ab830-0x004ab86f, constructor callback xref, no ordinary code callers, keyboard restore, `m_skipCrashReport` gate at g_pCrashTarget+4, report-writer call, previous-filter chain through object offset +8, one-byte padding before report writer, parent aggregate attachment, and final C++ remains pending exact child-body source entry.
```

Replace it with:

```text
    - [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) 0x004ab830-0x004ab86f | callback | TopLevelExceptionFilter : reconstructable : 88% : very strong : B001 2026-06-20 source-quality reanalysis resolves stale blank-C++/gate wording and recommends first-draft `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)` on the exact child page; raw PE recheck confirms the 63-byte body at raw offset `0xaac30`, one-byte `0xcc` padding before [UID:00014G], `ret 4` Windows callback shape, only constructor callback pointer route at `0x004ab49e/0x004ab49f`, no ordinary direct callers, `g_pKeySpeedMgr->RestoreSystemKeyboardSettings()` call at `0x004ab844`, active [UID:0000QN] `g_pCrashTarget` snapshot/read, `m_skipCrashReport` gate at handler offset `+0x04` returning `EXCEPTION_CONTINUE_SEARCH` without writing or chaining, [UID:00014G] `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)` call at `0x004ab858`, optional previous-filter tailcall through `m_previousFilter` at `+0x08`, owner/emitter route through [UID:00014D] -> [UID:00004P] -> [UID:0000J8] `platform/ExceptionHandler.cpp`, and Crasher/KeySpeedMgr/Application rejected as direct owners.
```

No `by-class/-coverage-report.md` or `by-file/-coverage-report.md` replacement row is required for this target-specific implementation. Existing class/file rows already cover the B005 aggregate/source-placement work.

## Validator Commands

Baseline already run during this report-only pass:

> Executable block R001 was removed from this report and preserved verbatim in [00014F-TopLevelExceptionFilter-source-quality-removed.md](00014F-TopLevelExceptionFilter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
ok: 1
ok           00014F by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md UID header exists
dry run only; pass --apply to write changes
```

The dry run also printed unrelated global validator/autogen warnings such as a missing registered file [UID:0000YI] and existing emitter/no-code notices. They are not [UID:00014F] blockers.

After implementation, run focused validators for every edited by-* doc. Minimum if only the target is edited:

> Executable block R002 was removed from this report and preserved verbatim in [00014F-TopLevelExceptionFilter-source-quality-removed.md](00014F-TopLevelExceptionFilter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, also run:

> Executable block R003 was removed from this report and preserved verbatim in [00014F-TopLevelExceptionFilter-source-quality-removed.md](00014F-TopLevelExceptionFilter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated-output inspection after autogen:

> Executable block R004 was removed from this report and preserved verbatim in [00014F-TopLevelExceptionFilter-source-quality-removed.md](00014F-TopLevelExceptionFilter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: [UID:00014F] appears with actual source instead of only an empty marker.

## Changed Files In This Report Pass

Created:

- `tools/leaser/Agents/Agent-B001/research/00014F-TopLevelExceptionFilter-source-quality.md`

Modified:

- None outside Agent-B001 research.

Renamed:

- None.

Coverage edited directly:

- No.

Generated/source/project-level/by-* docs edited directly:

- No.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00014F-TopLevelExceptionFilter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00014F"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014F-TopLevelExceptionFilter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00014F-TopLevelExceptionFilter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
