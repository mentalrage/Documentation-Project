** TARGET-REPORT-UID:0002VH **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0002VH ValidateChatInputOrThrowPasswordError Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002VH] owned and emitted by [UID:0000MG] `PasswordGuard`, keep `RECONSTRUCTABLE:TRUE`, keep blank emitter position, raise the target from `85/88` to `88/90`, and insert first-draft formal C++ during a supervisor-approved implementation callback.
- Final disposition: implementation-ready source-quality repair. The previous MCP outage has been superseded by a restored current MCP pass on `2026-07-02`.
- Required action: supervisor validation, then callback edits to the target and listed support docs. B005 must not run `execute_report`, any dry-run/apply variant, any report lifecycle command, or move/archive this report.
- Confidence: high for owner/emitter/behavior; medium-high for final source spelling of the DAT wrapper and globals because those remain inferred project names.

## Target

- Target UID: `0002VH`.
- Target path: `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`.
- Source queue/report row: Not-Covered Files - Reconstructable, current target row `85/88`, reports `0`.
- Current supervisor classification: report-only source-quality research.
- Current scores and parent state: target `85/88`; direct owner [UID:0000MG] `PasswordGuard` is `86/90`; aggregate [UID:0000YS] is reviewed non-emitting mixed container `87/90`.

## Current Target State

- Existing metadata: `CANONICAL_OWNER:0000MG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MG`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Existing owner/emitter state: correct. The function belongs to `NexusTK/auth/PasswordGuard.cpp`, not to the Error hierarchy, chat panes, or the broad physical aggregate.
- Existing C++ state: blank because the page still cites final helper naming, return type, and resource-loader source shape as blockers.
- Existing support state: the old `PasswordError` constructor blocker is resolved. [UID:0002VJ] emits `PasswordError::PasswordError(const wchar_t *message) : MyError(message) {}`; [UID:0002VL] emits `PasswordError::GetErrorName() const`; [UID:0002VK] is marker-covered compiler ABI destructor support.
- Related target/support docs checked: `by-file/PasswordGuard.md`, `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`, `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md`, `by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md`, `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md`, `by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md`, `by-class/PasswordError.md`, `by-class/MyError.md`, `by-file/Error.md`, and `by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md`.

## Evidence Checked

### Current IDA MCP Evidence

MCP was mandatory, restored by the supervisor, and used for this final report.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Session/database: `supervisor_resume_20260629`.
- `server_health`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: `0x00465890` is `sub_465890`, size `0x252`; `0x00465ae2` is not a function; `0x00465abe` is inside `sub_465890`; `0x00467160` is `sub_467160`, size `0x21`; DAT helpers `0x0049c130`, `0x0049c180`, and `0x0049c370` are real functions.
- `decompile 0x00465890`: copies `unk_67A940` into a local 32-wchar buffer with `_wcsncpy_s`, loads `word_66D410`, decodes with `*p++ = seed++ ^ ch`, checks `wcsstr(Str, SubStr)`, opens `PASS_ENG.STR` through `sub_49C180`, reads lines through `sub_49C370`, converts with `MultiByteToWideChar`, appends with `_wcsncat_s`, allocates 8 bytes through `sub_4F4AA0`, calls `sub_467160(v11, Destination)` at `0x00465abe`, then throws with `_CxxThrowException` and `__TI5PAVPasswordError@@`.
- `disasm 0x00465890` with `max_instructions=180`: confirms the same instruction-level shape; the non-throwing `Str != NULL` / no-match path clears all `0x40` bytes of the decoded stack buffer; the throw path range-checks line length and conversion size before constructing the exception.
- `callees 0x00465890`: `_wcsncpy_s`, `_wcsstr`, `sub_49C130`, `sub_49C180`, `_memset`, `sub_49C370`, `_wcsncat_s`, `@__security_check_cookie@4`, `___report_rangecheckfailure`, `sub_4F4AA0`, `sub_467160`, and `__CxxThrowException@8`.
- `xrefs_to`: `0x00465890` has 13 code xrefs from outbound-input submitters at `0x00477606`, `0x00477612`, `0x0047de03`, `0x0047de0f`, `0x0059e480`, `0x005ae0a0`, `0x005b1680`, `0x005b1aa0`, `0x005b1fc0`, `0x005b23d0`, `0x005b36d1`, `0x005b3aa1`, and `0x005b42b2`.
- `xrefs_to` globals/resources: `0x0067a940` has setter/validator data xrefs including `0x004658c5`; `0x0066d410` has PasswordGuard seed xrefs including `0x004658d2`; `0x00612e8c` has one target xref at `0x0046592d`; `0x00467160` has one code xref at `0x00465abe`.
- `get_bytes`: `0x0066d410` bytes are `44 d5`, which is little-endian `0xd544`; `0x0067a940-0x0067a980` is a 64-byte zero-initialized buffer in this IDB state; `0x00612e8c` bytes decode as UTF-16 `PASS_ENG.STR`. `get_string` returned only the first wide character for those UTF-16 strings, so byte decoding is the stronger evidence for the resource name.

### Documentation And Report Leads

- Target page [UID:0002VH] already records exact range `0x00465890-0x00465ae2`, 13 outbound-input callers, protected-token copy/decode, `wcsstr`, `PASS_ENG.STR`, DAT line-reader calls, `MultiByteToWideChar`, `PasswordError` construction at `0x00465abe`, and `_CxxThrowException`.
- [UID:0000MG] `PasswordGuard` records this helper and [UID:0002VG] as the two code functions in `auth/PasswordGuard.cpp`, plus `g_protectedPasswordToken[32]` and `g_passwordProtectSeed`.
- [UID:0002VG] records the matching setter: copy password into `word_67A940`, force terminator, encode with incrementing `word_66D410`.
- [UID:000290] records the 32-wchar token buffer under PasswordGuard; [UID:00035L] records `word_66D410 == 0xd544` as the PasswordGuard XOR seed.
- [UID:0000YS] records the broad physical interval as non-emitting and mixed across PasswordGuard, Application, PasswordError/Error, and callback support.
- Executed B013 report for [UID:0002VJ] proves the constructor is now source-ready and PasswordGuard is only the throw-site consumer.
- Executed B010 report for [UID:0002VL] proves the descriptor/name virtual is source-ready as `PasswordError::GetErrorName() const`.
- Executed B001 `0001LY` report confirms target-message input panes call `0x00465890` as a shared outbound guard before packet send, supporting file-level PasswordGuard ownership rather than a single pane owner.

Search terms used for prior reports and archived leads: `0002VH`, `00465890`, `00465ae2`, `ValidateChatInputOrThrowPasswordError`, `PasswordGuard`, `PasswordError`, `PASS_ENG.STR`, `word_66D410`, `0067a940`, and outbound-input helper terms. Relevant matches opened: B013 [UID:0002VJ], B010 [UID:0002VL], and B001 [UID:0001LY]. Other PasswordError executed reports were used through current by-* docs.

## Positive Evidence Summary

- The function is exact and coherent as one guard body: decode token, check text, build warning message, throw `PasswordError`.
- The ownership route is coherent across target and support docs: setter, validator, seed, and token buffer all belong to PasswordGuard.
- Caller spread is broad outbound text/social input, not a single input-pane method.
- Error hierarchy blockers have materially improved since the target page's old no-code rationale: constructor and descriptor virtual now emit through Error/PasswordError.
- The function's meaningful source contract is a guard that returns normally or throws, so the IDA `__int16` return is a decompiler artifact of the final `eax` value rather than a source API contract.
- The resource-loading throw path is bounded enough to describe as a local PasswordGuard message-loading shape without inventing a separate source owner.

## Negative Evidence Summary

- PasswordGuard does not own `PasswordError` class declaration, vtable, destructor, or descriptor string. It only constructs and throws it.
- The broad [UID:0000YS] aggregate remains mixed and non-emitting; using it as an owner would duplicate exact children.
- Chat/social input callers consume the guard and do not own it; the 13-call spread argues against a pane-local implementation.
- `PASS_ENG.STR` use by this function does not prove a reusable global resource-loader owner. Current evidence supports a target-local/file-local PasswordGuard message-loading loop.
- No evidence supports splitting this function. The DAT open/read/convert loop is part of the throw path for this exact guard body.

## Heuristic / Inference Reanalysis And Validation

### Function Name And Contract

The current documentation name `ValidateChatInputOrThrowPasswordError` is acceptable and should remain as the by-memory/page name. It captures the observable contract better than `sub_465890`: validate an outbound wide string, return on safe input, throw `PasswordError` on disclosure.

The source-facing return type should be `void`. MCP decompilation reports `__int16` because the epilogue returns whatever `eax` contains after the clear loop or earlier decode/load operations. The callers documented so far use this helper as a guard before packet/message send paths, and no target evidence shows return-value consumption. The formal source should be:

```cpp
void ValidateChatInputOrThrowPasswordError(const wchar_t *text)
```

### Token Decode Naming

The seed and buffer pages justify descriptive names even without original symbols:

- `g_protectedPasswordToken[32]` or `g_passwordGuardToken[32]` for `word_67A940-0x67A97E`.
- `g_passwordProtectSeed` or `kPasswordProtectSeed` for `word_66D410 == 0xd544`.

For this target's first C++, prefer direct local decode logic instead of a new shared helper. A shared encode/decode helper may be plausible when [UID:0002VG] receives a coordinated C++ pass, but this exact function can emit without waiting for that abstraction.

### Resource Loader Shape

The throw path opens `PASS_ENG.STR`, reads 200-byte raw lines through DAT helpers, converts each line to wide text, appends nonterminating lines into a 1024-wchar message buffer, and throws after the first blank/one-byte terminating record. This is implementation-ready as part of the PasswordGuard helper body. The exact DAT class/function spellings remain project-name choices for callback, not a blocker for source shape.

### Throw Helper And Exception Type

The thrown type is `PasswordError *` through `_CxxThrowException` and the constructor [UID:0002VJ]. The source should use ordinary C++ throw syntax:

```cpp
throw new PasswordError(message);
```

Do not emit `_CxxThrowException` or explicit vtable stores in source C++.

### Source Placement

Keep `NexusTK/auth/PasswordGuard.cpp`. The helper sits between login token capture and outbound chat/social protection. Moving it to `Error.cpp` would confuse throw-site behavior with exception class ownership. Moving it into `SayInputPanes.cpp` would miss the broader caller spread.

### C++ Readiness

This target is now eligible for first-draft C++. The old final-code gate language on the target page is stale: constructor and descriptor blockers are resolved, the child already clears `85/85` with a valid PasswordGuard emitter route, and current MCP confirms the body. The remaining inferred names should cap the score below final audit, not keep the formal block blank.

## Ranked Ownership Analysis

### 1. [UID:0000MG] PasswordGuard

- Evidence for: owns setter [UID:0002VG], token buffer [UID:000290], seed [UID:00035L], and this validator; caller split is login capture plus outbound input validation; `by-file/PasswordGuard.md` already stages `NexusTK/auth/PasswordGuard.cpp`.
- Evidence against: exact original file/folder name is inferred; resource helper spelling remains partly inferred.
- Decision: keep as direct owner and emitter.

### 2. [UID:0000A8] PasswordError / [UID:0000J5] Error

- Evidence for: target constructs and throws `PasswordError`; constructor and descriptor virtual are Error hierarchy code.
- Evidence against: target owns token decode, `PASS_ENG.STR` message assembly, and throw-site guard logic, not class declaration/vtable/destructor/source.
- Decision: support dependency only, not owner.

### 3. Chat/social input pane owners

- Evidence for: many direct callers are outbound text input submitters.
- Evidence against: caller spread spans multiple panes and social paths; shared guard behavior is not a pane method.
- Decision: rejected as direct owner.

### 4. [UID:0000YS] PasswordGuardAndFatalError aggregate

- Evidence for: physical interval contains this function.
- Evidence against: aggregate is a reviewed non-emitting mixed container.
- Decision: rejected as owner/emitter.

## Range / Split / Reclassification Analysis

- Keep exact range `0x00465890-0x00465ae2`.
- No split is recommended. The function has one coherent guard responsibility.
- No merge with [UID:0002VG] is recommended; setter and validator have separate callers and exact pages.
- No merge with `PasswordError` constructor is recommended; constructor is class-owned Error hierarchy code.
- No aggregate reclassification is recommended; [UID:0000YS] remains non-emitting.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00465890-0x00465ae2` | [UID:0002VH] `ValidateChatInputOrThrowPasswordError` | PasswordGuard outbound-text disclosure guard | TRUE | [UID:0000MG] | `85/88` -> recommend `88/90` | Keep exact; add C++ |
| `0x004657d0-0x00465827` | [UID:0002VG] `SetProtectedPasswordToken` | Matching token setter/encoder | TRUE | [UID:0000MG] | `85/90` | Support sibling |
| `0x0067a940-0x0067a980` | [UID:000290] protected token buffer | 32-wchar PasswordGuard token storage | TRUE | [UID:0000MG] | `86/87` | Support global |
| `0x0066d410-0x0066d412` | [UID:00035L] XOR seed | Initial password-token XOR seed | TRUE | [UID:0000MG] | `87/90` | Support global |
| `0x00467160-0x00467181` | [UID:0002VJ] `PasswordErrorConstructor` | Error hierarchy constructor | TRUE | [UID:0000A8] | `90/92` | Throw-path callee |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00477606`, `0x00477612` | `sub_477590` callers | outbound input guard consumers |
| `0x0047de03`, `0x0047de0f` | `sub_47DCB0` callers | outbound input guard consumers |
| `0x0059e480` | `sub_59E3D0` caller | outbound input guard consumer |
| `0x005ae0a0` | [UID:0001KW] spell string input caller | shared guard before packet send |
| `0x005b1680`, `0x005b1aa0`, `0x005b1fc0`, `0x005b23d0` | target/group/clan message input callers | shared say/social guard |
| `0x005b36d1`, `0x005b3aa1`, `0x005b42b2` | Say/Chat/Shout input callers | shared chat guard |
| `0x00465abe` | call to [UID:0002VJ] `PasswordErrorConstructor` | throw path constructs Error-owned exception |
| `0x0046592d` | xref to `0x00612e8c` | `PASS_ENG.STR` resource filename |
| `0x004658d2` | xref to `word_66D410` | decode seed load |
| `0x004658c5` | xref to `0x0067a940` | protected token source copy |

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended formal C++ insertion text for supervisor callback. The callback should align `DATFile`, `Open`, `ReadLineRaw`, `g_protectedPasswordToken`, and `g_passwordProtectSeed` with the accepted project names if different:

```cpp
void ValidateChatInputOrThrowPasswordError(const wchar_t *text)
{
    wchar_t decodedPassword[32];
    wcsncpy_s(decodedPassword, 32, g_protectedPasswordToken, 32);
    decodedPassword[31] = L'\0';

    unsigned int seed = g_passwordProtectSeed;
    for (wchar_t *scan = decodedPassword; *scan != L'\0'; ++scan)
    {
        *scan = static_cast<wchar_t>(*scan ^ seed);
        ++seed;
    }

    if (text != NULL && wcsstr(text, decodedPassword) != NULL)
    {
        DATFile passwordMessageFile;
        passwordMessageFile.Open(L"PASS_ENG.STR");

        wchar_t message[1024];
        memset(message, 0, sizeof(message));

        char line[200];
        int lineLength = passwordMessageFile.ReadLineRaw(line, sizeof(line));
        if (lineLength >= sizeof(line))
            _invalid_parameter_noinfo_noreturn();

        while (lineLength > 1)
        {
            line[lineLength] = '\0';

            wchar_t wideLine[200];
            int wideChars = MultiByteToWideChar(CP_ACP, 0, line, -1, wideLine, 199);
            if (wideChars >= 200)
                _invalid_parameter_noinfo_noreturn();

            wideLine[wideChars] = L'\0';
            wcsncat_s(message, 1024, wideLine, 200);

            lineLength = passwordMessageFile.ReadLineRaw(line, sizeof(line));
            if (lineLength >= sizeof(line))
                _invalid_parameter_noinfo_noreturn();
        }

        message[1023] = L'\0';
        throw new PasswordError(message);
    }

    memset(decodedPassword, 0, sizeof(decodedPassword));
}
```

Reason this preserves original behavior: it copies and decodes the protected token with the same incrementing XOR seed, uses `wcsstr` only when the input pointer is non-null, loads and converts `PASS_ENG.STR`, constructs `PasswordError` with the assembled message, throws a pointer exception, and clears the decoded stack copy on the normal checked path.

Reason this matches source shape: a `void` guard that throws on failure is ordinary mid-2000s C++ source; direct `_CxxThrowException`, raw `sub_` names, explicit vtable writes, and decompiler return artifacts are not.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000MG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MG`, blank C++.
- Recommended: `COMPLETION:88`, `CONFIDENCE:90`, same owner/reconstructable/emitter fields, formal C++ inserted.
- Reason not higher: exact original DAT wrapper names, exact global spellings, and exact original source-file name remain inferred; setter/validator name coordination should be finalized together in callback.
- Reason not lower: current MCP confirms range/body/xrefs/globals/resource/throw path; constructor and descriptor blockers are resolved; ownership/emitter route is stable.
- Metadata fields to leave unchanged: `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | Keep [UID:0002VH] owned/emitted by PasswordGuard. | High | Current MCP xrefs; PasswordGuard/token/seed docs | Already present: `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md` metadata has `CANONICAL_OWNER:0000MG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MG`, blank `EMITTER_POSITION_OPTIONAL`; `Scope`/`Reconstruction Notes` preserve PasswordGuard ownership and rejected Error/chat/aggregate owners. | already-present | already-present |
| C2 | `0x00465890-0x00465ae2` is an exact single guard function. | High | MCP `lookup_funcs`, `disasm`, `decompile` | Already present: target `Scope`, `IDA Evidence`, `Callers`, `Behavior`, and `Reconstruction Notes`; aggregate child row in `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`. | already-present | already-present |
| C3 | Source contract should be a `void` guard that throws. | Medium-high | Current decompile, caller use, no return-use evidence in docs | Applied/already present: target `Signature` explains IDA `__int16` as artifact and formal C++ uses `void ValidateChatInputOrThrowPasswordError(const wchar_t *text)`; B005 callback corrected the formal C++ normal path to always clear `decodedPassword`. | incorporate | applied |
| C4 | `PASS_ENG.STR` resource loop is target-local PasswordGuard throw-path behavior. | High | MCP decompile/disasm/xref/bytes | Already present with callback C++ correction: target `Behavior`, `IDA Evidence`, formal C++; `by-file/PasswordGuard.md` `Responsibility`, `Likely Contents`, `Source Split`, `Evidence`, and `Open Questions` state local PasswordGuard message loading and reject Error/global-resource ownership. | incorporate | applied |
| C5 | PasswordError constructor blocker is resolved. | High | [UID:0002VJ], B013 executed report | Already present: target `IDA Evidence` and `Reconstruction Notes`; `by-file/PasswordGuard.md` `Likely Contents`/`Source Split`; aggregate `Covered Range` and `Source Split` record source-ready [UID:0002VJ] while preserving Error ownership. | already-present | already-present |
| C6 | Descriptor/name virtual blocker is resolved for Error hierarchy. | High | [UID:0002VL], B010 executed report | Already present: target `Reconstruction Notes`; aggregate `Covered Range`/`Source Split`; `PasswordGuard.md` keeps PasswordError class implementation in Error and does not list descriptor work as a UID0002VH blocker. Error/PasswordError docs also already record source-ready descriptor/name virtual. | already-present | already-present |
| C7 | Raise target to `88/90` and insert formal C++. | Medium-high | Current MCP plus resolved support docs | Applied/already present: target headers already had `COMPLETION:88` and `CONFIDENCE:90`; formal C++ was present and B005 callback corrected the normal-path clearing plus blank-emitter-position prose. Validator `000000004338` accepted target and generated `PasswordGuard.cpp`; later generated header is `000000004340`. | incorporate | applied |

## Recommended Target Doc Changes

Target path: `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`.

- Raise to `88/90`.
- Keep owner/emitter/reconstructable metadata unchanged.
- Replace stale 95/95 final-code-gate wording with current source-ready rationale.
- Update Signature to `void ValidateChatInputOrThrowPasswordError(const wchar_t *text)` and explain why IDA's `__int16` is a decompiler artifact.
- Add current 2026-07-02 MCP evidence: health/session, exact range, decompile/disasm body, callee set, caller set, token/seed/resource xrefs, byte evidence for `PASS_ENG.STR`, and seed bytes `44 d5` for little-endian `0xd544`.
- Insert formal first-draft C++ using accepted DAT/global names.
- Preserve negative evidence: PasswordGuard is throw-site owner; PasswordError class remains Error-owned; aggregate remains non-emitting; chat panes are callers only.

## Recommended Support Doc Changes

- `by-file/PasswordGuard.md`: update open questions to say `PASS_ENG.STR` resource-helper shape is implementation-ready as local PasswordGuard message loading; remove wording that PasswordError constructor support blocks validator C++.
- `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md`: no required metadata change; add a coordination note if callback settles shared names for token buffer and seed.
- `by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md`: update emitted declaration/name only if callback settles `g_protectedPasswordToken` or another accepted spelling.
- `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md`: update emitted declaration/name only if callback settles `g_passwordProtectSeed` or `kPasswordProtectSeed`.
- `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`: update the [UID:0002VH] child row if target C++ is inserted; preserve non-emitting aggregate.
- `by-class/PasswordError.md`, `by-class/MyError.md`, and `by-file/Error.md`: no required changes unless they still say [UID:0002VH] is blocked by constructor/descriptor work; if touched, preserve PasswordGuard as consumer only.

## Open Questions With Attempted Resolution

- DAT helper exact source type/name: resolved to target-local PasswordGuard resource-message loading shape; final spelling must align with accepted DAT docs during callback.
- Return type: resolved as source-facing `void`; reject only if a future caller-specific MCP pass proves return-value consumption.
- Global names: descriptive names are safe for first-draft C++, but exact original spelling remains unknown and caps score below final audit.
- Resource helper placement: local to PasswordGuard for this target; no evidence supports moving it to Error or a global resource module.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker text is required. Do not edit `auto-generated/-ag-*`, `project-level/*`, or any manual `-coverage-report.md` file. Source by-* metadata and formal C++ should drive validator-owned generated coverage and generated `NexusTK/auth/PasswordGuard.cpp` refresh.

## Validator Results

- Callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md --apply --queue-timeout 240 --wait-generated`: exit code `0`, `command_id:000000004338`, `command_timestamp:2026-07-02T06:28:47-04:00`, `ok:1`, `generated_refresh:completed`, `autogen_cpp_update:1`, generated refresh command `000000004338`.
  - `python .\tools\validator.py --mode file --file by-file\PasswordGuard.md --apply --queue-timeout 240`: exit code `0`, `command_id:000000004340`, `command_timestamp:2026-07-02T06:29:04-04:00`, `ok:1`, `generated_refresh:deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004657d0-0x00467406.PasswordGuardAndFatalError.md --apply --queue-timeout 240`: exit code `0`, `command_id:000000004342`, `command_timestamp:2026-07-02T06:29:18-04:00`, `ok:1`, `generated_refresh:deferred`.
- Generated `auto-generated/NexusTK/auth/PasswordGuard.cpp` inspected after validation. Header is `validator-command-id:000000004340`, `validator-refreshed-at:2026-07-02T06:29:04-04:00`, which is newer than the target validator `000000004338`; generated UID0002VH body is present and clears `decodedPassword` unconditionally on the normal path.
- Validator-owned side effects reported: `validator.ini` registry rebuild/update, generated metadata refresh, `auto-generated/NexusTK/auth/PasswordGuard.cpp` update, generated coverage metadata refresh, `auto-generated/-ag-research-tracker.md` refresh, projected stats update, and validator autogen backups. These were validator-owned outputs; B005 did not edit generated/tool-state files by hand.
- Leases used for the edit/validator batch: B005 leases were active on `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`, `by-file/PasswordGuard.md`, `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`, plus conditional token/seed support docs. Cleanup `unlease` reported `Rejected[No active lease]` for each B005 path because the short leases had already expired; final `current_leases.md` check showed no active B005 leases for these files.
- `execute_report`, report lifecycle dry-runs, registry lifecycle commands, manual report moves, and equivalent archive/execution commands were not run.

## Changed Files

- Modified: `tools/leaser/Agents/Agent-B005/research/0002VH-ValidateChatInputOrThrowPasswordError-source-quality.md`.
- Modified: `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`.
- Required support docs checked and validated; accepted content was already present at same-or-greater detail: `by-file/PasswordGuard.md`, `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`.
- Conditional support docs checked; no extra edits required because accepted token/seed names and Error/PasswordError resolved status were already synchronized: `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md`, `by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md`, `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md`, `by-class/PasswordError.md`, `by-class/MyError.md`, and `by-file/Error.md`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback on 2026-07-02 explicitly accepted this report for implementation.
- [x] Update `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md` metadata to `88/90`, preserve `CANONICAL_OWNER:0000MG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MG`, and blank emitter position. Proof: target metadata already had `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000MG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MG`, and blank `EMITTER_POSITION_OPTIONAL`; B005 callback also corrected target `Item Summary`/`Scope` prose to say blank emitter position instead of legacy position `20`.
- [x] Insert formal first-draft C++ using accepted project DAT/global names, with source-facing `void ValidateChatInputOrThrowPasswordError(const wchar_t *text)`. Proof: target formal `RECONSTRUCTION_CPP CODE` already contained the accepted signature and `DATFile` / `ReadLineRaw` / `g_protectedPasswordToken` / `g_passwordProtectSeed` names; B005 callback corrected the normal path to `memset(decodedPassword, 0, sizeof(decodedPassword));` unconditionally.
- [x] Update target prose with current 2026-07-02 MCP evidence, `void` guard contract, `PASS_ENG.STR` message-loading shape, resolved `PasswordError` constructor/descriptor blockers, and rejected owner alternatives. Proof: target `IDA Evidence`, `Signature`, `Behavior`, `Reconstruction Notes`, `Score Rationale`, and `Changes` already preserve the current MCP session `supervisor_resume_20260629`, exact range/body/callees/callers, resource/seed/token bytes/xrefs, resolved constructor/descriptor blockers, and rejected PasswordError/Error, chat-pane, and aggregate ownership.
- [x] Update `by-file/PasswordGuard.md` with the target's C++ readiness and local resource-message-loader shape. Proof: already present at same-or-greater detail in `Responsibility`, `Likely Contents`, `Source Split`, `Evidence`, `Open Questions`, and `Changes`; validator `000000004340` returned `ok:1`.
- [x] Update support token/seed docs only if callback settles emitted global names. Proof: no new edits required; conditional docs already record accepted descriptive names and caveats in `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md`, `by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md`, and `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md`.
- [x] Preserve Error/PasswordError support ownership: constructor/descriptor/destructor stay routed through [UID:0000A8]/[UID:0000J5]; PasswordGuard remains consumer/throw-site. Proof: already present in target `Reconstruction Notes`, `PasswordGuard.md` source split, aggregate source split, and conditional Error/PasswordError docs; no contradiction found by `rg` checks.
- [x] Preserve [UID:0000YS] as non-emitting mixed aggregate; update only its child row/evidence if target C++ is accepted. Proof: already present in aggregate metadata `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; `Covered Range`, `Source Split`, `Evidence`, `Resolved Caveats`, and `Changes` record UID0002VH as source-ready while preserving aggregate non-emission. Validator `000000004342` returned `ok:1`.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C1-C7 rows above now state `applied` or `already-present` with path/section proof.
- [x] Preserve historical/stale assumptions, rejected alternatives, and negative evidence. Proof: target `Reconstruction Notes`, `Score Rationale`, and `Changes`; `PasswordGuard.md` `Source Split`/`Placement Notes`; aggregate `Ownership Decision`/`Resolved Caveats` preserve stale/rejected Error, chat-pane, aggregate, global-resource-loader, and final-name caveats.
- [x] Confirm third-party import directive is not applicable. Proof: target is first-party PasswordGuard helper and formal C++ is inline; no third-party staged source/import directive applies.
- [x] Run scoped validators for every changed by-* file with `--wait-generated`, recording command id, timestamp, exit code, `ok` count, and generated refresh state. Proof: target validator `000000004338`, timestamp `2026-07-02T06:28:47-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`; required support validators `000000004340` and `000000004342`, both exit `0`, `ok:1`, deferred generated refresh.
- [x] Confirm generated `auto-generated/NexusTK/auth/PasswordGuard.cpp` is equal/newer than the validator command and includes UID0002VH body if C++ is inserted. Proof: generated file inspected after validators; header `validator-command-id:000000004340`, `validator-refreshed-at:2026-07-02T06:29:04-04:00`, newer than target command `000000004338`, and UID0002VH body includes unconditional decoded-buffer clearing.
- [x] Do not manually edit generated reports, manual coverage reports, validator/tool state, queue/lock files, archives, supervisor ledgers, or IDA DB. Proof: B005 only edited target by-memory doc and this report; generated/tool-state changes were validator-owned outputs.
- [x] B005 must not run `execute_report`, dry-run/apply variants, registry lifecycle commands, manual report moves, or equivalent archive/execution commands; supervisor executes only after independent verification. Proof: only scoped `--mode file` validators were run; no report execution/archive command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004351","destination_path":"executed-b-agent-research/B005/0002VH-ValidateChatInputOrThrowPasswordError-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002VH-ValidateChatInputOrThrowPasswordError-source-quality.md","timestamp":"2026-07-02T06:32:03-04:00","uid":"0002VH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
