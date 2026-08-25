** TARGET-REPORT-UID:00014H **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 00014H ExceptionCodeStringHelper Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented recommendation: [UID:00014H] was renamed through the validator-aware UID-preserving workflow to `by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md`; [UID:00004P] `ExceptionHandler` remains canonical owner/emitter, and [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp` remains the source file.
- Implemented disposition: source-authored, reconstructable private static class helper `LPTSTR ExceptionHandler::GetExceptionString(DWORD)` with complete R1 formal C++ on the exact child page. The method is a Unicode NexusTK adaptation of the published Matt Pietrek `MSJExceptionHandler::GetExceptionString` source, not a file-static `GetExceptionCodeText` helper.
- Callback result: C01-C20 and the exact bounded target/support synchronization are complete. The adjacent compiler-lowered switch island, dispatch slots, fallback storage, vtable, and RTTI remain unsplit/non-emitting as accepted.
- Confidence: very strong for range, behavior, caller set, API identities, storage lifetime, 22 mappings, original method name/type/access, and source placement; strong for the conclusion that NexusTK retained the source method name after renaming the enclosing class.

## Supporting Research

- Mandatory live IDA MCP evidence was redone after supervisor recovery. At `2026-07-14T21:57:34.3468808-04:00`, a fresh `idb_list` returned active database `0cf42e97` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `8808`; `server_health` returned `status: ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, strings ready, and 2067 cached strings. Valid bounded `lookup_funcs`, `get_bytes`, decompile, disassembly, basic-block, xref, callee, and raw UTF-16 evidence calls succeeded from `21:57:34` through `22:00:41` EDT. A final fresh `idb_list`/health/lookup/16-byte probe at `2026-07-14T22:02:13.9330266-04:00` again returned the active worker, `status: ok`, `sub_4ABD10` size `0x13a`, and real target bytes. This records health at evidence-collection time and does not assert indefinite session availability.
- The exact target SHA-256 is `9d3abc26d4c8d8cc53e3475c7f470458dbb688311d46d7a43c2f7c2286bf0469` over `0x004abd10-0x004abe4a`.
- The exact adjacent switch/data SHA-256 is `02dbb079f215d8342f4903e5da06e14647786fa7bcaaf5d4c67c45534e0bf1be` over `0x004abe4a-0x004abf9c`. The combined switch/data-plus-successor-padding span `0x004abe4a-0x004abfa0` hashes to `1f86c1997bdff7e39666c597aaeee4438261a16c36ca2e56a2fe04dbee1905da`; the difference is exactly the terminal four `0xcc` bytes.
- The published source lead was independently compared rather than copied as an assumption. The `MSJEXHND.CPP` source identifies Matt Pietrek and Microsoft Systems Journal, May 1997, and its `GetExceptionString` method matches the target's complete case order, strings, static buffer, fallback module, flags, API nesting, argument values, and return behavior. Source pages checked on 2026-07-14:
  - `https://docs.polserver.com/doxygen/html/dc/dc4/msjexhnd_8cpp_source.html`
  - `https://docs.polserver.com/doxygen/html/d5/d59/msjexhnd_8h_source.html`
- The header lead is decisive for ownership/access/type: `GetExceptionString(DWORD)` is a `private` `static` method returning `LPTSTR`. NexusTK changed the enclosing class from `MSJExceptionHandler` to `ExceptionHandler`, adapted surrounding report behavior, and resolves Unicode Win32 APIs through [UID:0000TQ], but preserved this helper's source body.
- Historical prior-report assumptions are retained only as superseded evidence. B005's executed [UID:00014D] report correctly established the family, source file, range, and switch/data relationship but inferred file-static `GetExceptionCodeText(DWORD)`. The exact source match and current binary now reject that naming/ownership inference.

Historical-report searches used exact terms `00014H`, `0x004abd10`, `ExceptionCodeStringHelper`, `GetExceptionCodeText`, and `ExceptionHandler` against these roots:

| Search root | Outcome and target-specific classification |
| --- | --- |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/**` | No current target report. ExceptionHandler-family mentions are support leads only. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/**` | No current target report or contrary source disposition. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/**` | No pre-existing UID00014H report before this artifact. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/**` | No current target report. InternetError/FormatMessage material is API-pattern support only and not target ownership. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/**` | No active target artifact; the relevant B005 reports are now under the executed root. |
| `source-3/project-documentation/executed-b-agent-research/**` | Relevant leads: B005 `00014D-ExceptionHandler-source-quality.md` establishes the aggregate/source route but carries the superseded file-static name; B005 `000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality.md` proves the exact literal island and absence of a pointer table; B015 `00014F-TopLevelExceptionFilter-source-quality.md` and B013/B005 `00014E-CrashDiagnosticTextSender` work support the family route but do not resolve this target. Crasher/Application reports are boundary evidence only. |
| `source-3/project-documentation/archived/**` | No matching report or contrary target conclusion. |
| `source-3/project-documentation/tools/leaser/Agents/Older-Research/**` | No matching report. |
| `source-3/project-documentation/tools/leaser/Agents/SpecialReports/**` | No matching report. |

## Target

- Target UID: `00014H`.
- Implemented target path: `by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md`; historical pre-callback path: `by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Callback classification: accepted direct source-quality research implemented on the exact reconstructable child and bounded support set.
- Implemented scores and parent state: `92/94`, `CANONICAL_OWNER:00004P`, `EMITTER_UIDS:00004P`, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`, complete R1 formal C++.
- B003 research artifact path before any external supervisor lifecycle action: `tools/leaser/Agents/Agent-B003/research/00014H-ExceptionCodeStringHelper-source-quality.md`.

## Current Target State

- Implemented metadata preserves the exact `0x004abd10-0x004abe4a` range, class owner/emitter route, reconstructable state, blank optional position, and `Nested:0`, while applying `92/94` and R1.
- Implemented behavior documentation records two report-writer calls, all 22 `TCHAR` exception names, `NTDLL.DLL`, fallback storage `0x0069af28`, API slots `0x0069be78`/`0x0069be6c`, the adjacent switch island, source/header lineage, lifetime, failure behavior, and rejected alternatives.
- The former helper-name, class/static ownership, return/constness, API identity, static-buffer extent/lifetime, source-body, and split blockers are closed. `GetExceptionCodeText`, file-static ownership, and generic `ExceptionCodeStringHelper` remain only as explicitly labeled historical/superseded provenance.
- Historical pre-callback generated state at command `000000012372`, timestamp `2026-07-14T22:00:56-04:00`, SHA-256 `D442FD7055258CF89D61846529D6AB4980E7D069F5BD16DEEE7289CA74DE1182`, had one UID00014H Empty Emitter Marker and no definition.
- B003 waited generated command `000000012420`, timestamp/header `2026-07-14T22:32:19-04:00`, produced SHA-256 `52F1D8C90B07EC90F9B034B309AA2F6DE04E43CFAC7F00C4959353503BE843A1`. A later external foreground validator refresh was observed at command/header `000000012445`, timestamp `2026-07-14T22:36:28-04:00`, SHA-256 `73349EF749919E18A075CBEAF2A3A2BD06C3328385B04EA6412180DE3665D8C6`; it preserves one UID00014H row, one exact `GetExceptionString` definition, 22 direct cases, one `NTDLL.DLL` literal, one `FormatMessage` call, zero UID00014H Empty Emitter Markers, zero old helper names, and zero handwritten vtable/RTTI/data objects. The unrelated pre-existing UID00004P and other family empty emitters remain outside this exact target callback.
- Related docs were reread/synchronized as bounded below. B003 performed the authorized ordinary implementation and validators, but no manual coverage edit, report execution/probe/count/registry/move/archive/revalidation, generated-file edit, lifecycle command, IDA mutation, or MCP management action.

## Executive Recommendation

- Keep owner/emitter [UID:00004P] because exact upstream declaration evidence makes the helper a private static `ExceptionHandler` method; lack of ECX consumption is expected for a static member and does not make it file-static.
- Keep final placement in [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp`; both callers are in the same ExceptionHandler report writer, companion `GetLogicalAddress` matches the same published source family, and the literals/data route through the same file.
- UID00014H is renamed to `ExceptionHandlerGetExceptionString`, R1 is installed, and the score is `92/94` from `86/91`.
- Keep `0x004abe4a-0x004abf9c` parent-only compiler-lowered switch data and `0x004abf9c-0x004abfa0` parent-only alignment padding. No child creation, raw table emission, or range extension is justified.
- Keep [UID:0000TQ]/[UID:0002AS] API-dispatch declarations unchanged; they already identify `FormatMessageW` and `GetModuleHandleW` with exact types.

## Supervisor Active Recheck

- The supervisor accepted the exact report artifact and authorized the bounded UID00014H implementation callback; healthy live IDA MCP evidence, exhaustive blocker closure, score improvement, exact formal C++, support synchronization, and exact manual coverage text are retained.
- Split repair before the final report is not required. The executable function is exact, the compiler table island is separately bounded inside the existing aggregate, and successor padding/function boundaries are explicit.
- Every source-bearing item in direct scope has its implemented disposition: UID00014H contains R1; caller/aggregate/class/file/read-only-data pages contain bounded prose/link synchronization; API dispatch pages and companion helpers were reread verify-only, with only the validator-managed renamed link in UID0001QB changing automatically.

## Inference Research Guidance Check

- The project inference discipline and `by-structure.md` require source identity to follow behavior, ownership, caller context, and source-era structure rather than IDA's `sub_4ABD10` or a generated descriptive title.
- Existing documentation assumptions treated as uncertain were `GetExceptionCodeText`, file-static ownership, unknown `0x0069be78`/`0x0069be6c` identities, vague wide-pointer constness, and possible switch-table splitting.
- Direct IDA facts are ranges, bytes, xrefs, API-slot calls, data references, return convention, and storage. Documentation evidence is the current UID graph and prior executed reports. Source lineage is a published-source comparison corroborated independently by the binary. The final NexusTK class-name adaptation is inference supported by current class/file ownership and the exact method body.
- No Wave2/Wave3 artifact was used as authority. The prior `class_ExceptionHandler.cpp` reference and generated output were treated only as current routing/emission diagnostics.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution/classification |
| --- | --- | --- |
| Generated target name | IDA has `sub_4ABD10`; docs use descriptive `ExceptionCodeStringHelper`; published source and binary match `GetExceptionString`. | `ExceptionHandler::GetExceptionString`; original-source name adapted only for enclosing Nexus class. |
| File-static versus class-static | Body consumes one stack argument and no ECX; header source declares the exact helper `private static`; both callers are in the class report writer. | Private static member. File-static `GetExceptionCodeText` is rejected stale inference. |
| Return type/constness | Every known branch returns a writable-typed literal pointer under legacy TCHAR rules; fallback returns mutable static `TCHAR[512]`; source declaration is `LPTSTR`. | Preserve `LPTSTR`, not `const wchar_t *`, `std::wstring`, or `SimpleUString`. |
| Calling convention | Binary has one 32-bit stack argument and `retn 4`; no ECX use. The source declaration has no explicit convention and project compiler defaults/lowering can account for callee cleanup. | Write source declaration without assembly calling-convention decoration; preserve one `DWORD` argument. |
| Fallback API identities | Nested evaluation and API-dispatch initialization prove `GetModuleHandleW(L"NTDLL.DLL")` is the module argument to `FormatMessageW`. | Use generic `GetModuleHandle`/`FormatMessage` with `TCHAR` in source-faithful Unicode-era C++; document resolved W slots. |
| Fallback flags | Immediate `0x0a00` is `FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE`. | Preserve exact flags; reject `FORMAT_MESSAGE_FROM_SYSTEM` and `FORMAT_MESSAGE_ALLOCATE_BUFFER`. |
| Buffer shape/lifetime | Two xrefs to `0x0069af28`; next known object at `0x0069b328`; source has `static TCHAR szBuffer[512]`. Unicode size is 1024 bytes. | Process-lifetime shared mutable `TCHAR[512]`; non-reentrant and overwritten on unknown-code calls. |
| Size argument quirk | Binary pushes `0x400`; source passes `sizeof(szBuffer)` to a character-count parameter. | Preserve `sizeof(szBuffer)` exactly, even though `_countof(szBuffer)`/512 would be safer. |
| Failure behavior | No branch tests `FormatMessage`; source static initialization happens once, not per call. | Preserve unchecked call and return buffer; failure can expose empty or prior content. |
| Switch/data island | Target branches into three tables immediately after function end; island has no independent source identity and is reproduced by the switch. | Parent-only compiler lowering; no split, import, raw table, or formal C++. |
| Literal storage | All 22 direct literal addresses are in UID000259; no pointer table exists. | Keep strings as source literals generated by the `EXCEPTION` macro; UID000259 remains blank. |
| First caller return discard | `0x004ab951` pushes the exception code, calls target, and does not consume EAX. | Record exact binary behavior; do not add side effects to rationalize it. |
| Second caller conversion | `0x004ab968` calls target; returned UTF-16 is passed to `WideCharToMultiByte` before ANSI report formatting. | Writer support prose must record this actual use and call order. |
| Source file | Exact helper, report writer caller, companion logical-address algorithm, strings, and source family cluster together. | `NexusTK/platform/ExceptionHandler.cpp`; reject new `CrashDiagnostics.cpp`, CRT, NTDLL, Error, or generic utility ownership. |
| Class declaration dependency | Exact private declaration is now known, but UID00004P still has broader unresolved raw helper declarations and a complete class formal is outside what this target body can safely manufacture. | Add exact declaration guidance to UID00004P prose; leave its formal block and score unchanged rather than emit an incomplete shell. |

Rejected alternatives:

- `GetExceptionCodeText`, `DescribeExceptionCode`, and free `ExceptionCodeStringHelper`: rejected by exact source-name/declaration/body match.
- `const wchar_t *`: source-inexact and wrong for the mutable fallback buffer's declared type.
- returning `std::wstring`, `SimpleUString`, allocated memory, or caller-owned storage: contradicted by direct pointer returns and static storage.
- `FormatMessageW(..., 512, ...)` or `_countof(szBuffer)`: cleaner modern code but byte-inexact; binary/source use `sizeof` and pass `0x400`.
- `FORMAT_MESSAGE_FROM_SYSTEM`, `LocalFree`, a second formatting/finalization helper, or explicit fallback text: absent from bytes, xrefs, source, and dispatch identities.
- hand-authored jump tables or a new data child: compiler artifact with no separate source body.
- a separate source file or API-table owner: callers and companion algorithm remain in ExceptionHandler.

## Evidence Standards Used

- Highest-weight evidence: live MCP function/byte/disassembly/xref/data checks against the configured NexusTK IDB and exact binary/source-body agreement.
- Corroborating evidence: current UID metadata/routes, executed family reports, API dispatch declarations, current generated output, and manual coverage rows.
- Negative evidence: no third caller, no ECX read, no dynamic allocation/free, no fallback-result test, no pointer table, no independent island xrefs/source identity, and no competing source owner.
- The published source mirror is not accepted alone. Its exact 22-case sequence, fallback code, companion `GetLogicalAddress` algorithm, and writer format are independently present in the NexusTK binary, making lineage evidence much stronger than name resemblance.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks: fresh `idb_list`; `server_health`; bounded `lookup_funcs` at target/end/adjacent helpers; target `get_bytes`; target decompile/disassembly; caller disassembly; xrefs to target, buffer, module literal, API slots, and tables; table/data extraction; Unicode literal decoding; hashes; UniAPI initializer disassembly around `0x005995b0`.
- by-* and support docs: UID00014H, UID00014D, UID00014G, UID00014I, UID000259, UID00004P, UID0000J8, UID0000TQ, UID0002AS, UID00014E, UID00014F, UID0001QB, and relevant manual coverage rows.
- Historical reports: exact roots/search outcomes listed under Supporting Research; relevant B005/B013/B015 claims were revalidated rather than copied.
- External source comparison: published `msjexhnd.cpp` and `msjexhnd.h` source pages, including method declaration/access and companion logical-address algorithm.
- Generated output: read-only `auto-generated/NexusTK/platform/ExceptionHandler.cpp`, command `000000012372`, 69 lines, 2886 bytes, current hash recorded above.
- Negative checks: no function at `0x004abe4a`, no extra target callers, no pointer table in UID000259, no `LocalFree`, no system-message flag, no result test, and no standalone table owner.
- Intentionally skipped check: current-session `lookup_funcs 0x005995b0` returned `Not a function`, so Hex-Rays decompilation was not used for that raw UniAPI constructor start. A bounded current-session disassembly succeeded and directly showed the `FormatMessageW`/`GetModuleHandleW` loads and stores; this is an IDA function-model limitation, not missing evidence or an MCP outage.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Healthy mandatory MCP evidence used active database `0cf42e97` at evidence time. | Very strong | Fresh idb_list, health, bounded lookup/bytes/decompile/disassembly/xrefs. | UID00014H Evidence/Changes | incorporate | applied | Target documents the bounded `0cf42e97` health/evidence facts without asserting later availability; final target hash `D2081329E46C1660D0A8D29342A1B2CCCBCC17BE760BD90C4FB30D4CA446FC81`; validator `000000012392`, exit 0, ok 1. |
| C02 | Exact function is `0x004abd10-0x004abe4a`, size `0x13a`/314, SHA-256 `9d3abc26d4c8d8cc53e3475c7f470458dbb688311d46d7a43c2f7c2286bf0469`. | Very strong | lookup, bytes, hash, adjacent starts. | UID00014H metadata/Evidence | incorporate | applied | Exact range, explicit hexadecimal/decimal size, target byte hash, instruction/block counts, and adjacent boundaries are in UID00014H; validator `000000012392`. |
| C03 | Source identity is private static `LPTSTR ExceptionHandler::GetExceptionString(DWORD)`. | Very strong | Exact source/header match plus binary. | UID00014H, UID00004P, UID00014D, UID0000J8 | incorporate | applied | Identity/source/header/ABI/access detail is in target plus UID00014D/04P/0J8; validators `000000012392`, `000000012394`, `000000012405`, and `000000012409`, all exit 0/ok 1. |
| C04 | Rename target path/title while preserving UID/range/route. | Strong | Original name and class ownership closed. | UID00014H validator-aware rename | incorporate | applied | Validator-aware rename completed to `by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md`; `000000012392` reports `path_update:1`, registry/reference/UID-link updates, and preserved UID00014H/range/owner/emitter/TRUE/blank position/Nested 0. |
| C05 | Exactly 22 known codes return exact TCHAR names. | Very strong | UTF-16 decode, switch, published source. | UID00014H Behavior/R1; UID000259 | incorporate | applied | R1 and target prose list/preserve all 22 cases; UID000259 states 22 direct macro-generated literals and no pointer table; validators `000000012392`/`000000012397`; generated command `000000012420` counts 22 direct cases. |
| C06 | Exactly two direct calls, both from UID00014G at `0x004ab951` and `0x004ab968`. | Very strong | xrefs and caller disassembly. | UID00014H/UID00014G | incorporate | applied | Both exact calls are recorded in target and writer; UID00014G validator `000000012393`, exit 0/ok 1. |
| C07 | First call discards EAX; second converts returned UTF-16 before ANSI report formatting. | Very strong | Caller instruction/data flow. | UID00014H/UID00014G | incorporate | applied | UID00014G now distinguishes the discarded first result and `WideCharToMultiByte`-converted second result at report-level detail; validator `000000012393`. |
| C08 | Unknown codes use `GetModuleHandleW` and `FormatMessageW` slots. | Very strong | Push order, initializer stores, UID0000TQ/2AS. | UID00014H; API pages verify-only | incorporate | applied | Target identifies both exact slots/APIs and generic source macros; UID0000TQ hash `CAD07BDEA56F1F8993A06B233A0A32594FC82DA2BE06B35897E019DB671149B4` and UID0002AS hash `1A6EDC9EDA55DF7FF6C7B843C33B504B4B35E54D0DBE8CE2A46124F7CDCED367` were reread unchanged. |
| C09 | Flags are exactly `IGNORE_INSERTS` plus `FROM_HMODULE`; language and Arguments are zero. | Very strong | Immediate values/source match. | UID00014H/R1 | incorporate | applied | Exact flags and zero language/Arguments are preserved in prose and R1; target validator `000000012392`; generated command `000000012420` contains one fallback call. |
| C10 | Fallback storage is static `TCHAR[512]` at `0x0069af28-0x0069b328`. | Very strong | xrefs, next-storage boundary, source. | UID00014H | incorporate | applied | Exact BSS span, 512-element/1024-byte Unicode shape, shared lifetime, overwrite behavior, and no raw global page are in target; validator `000000012392`. |
| C11 | Preserve `sizeof(szBuffer)` -> `0x400` Unicode character-count quirk and unchecked result. | Very strong | Binary pushes/source. | UID00014H/R1 | incorporate | applied | R1 retains `sizeof(szBuffer)` and no result branch; target prose records the `0x400` quirk/failure behavior; validator `000000012392`. |
| C12 | Return type remains legacy mutable `LPTSTR`; no allocation/free or const modernization. | Very strong | Header declaration and fallback storage. | UID00014H/UID00004P | incorporate | applied | Target R1 and class declaration guidance retain mutable `LPTSTR`, static lifetime, no allocation/free, and rejected const/container rewrites; validators `000000012392`/`000000012405`. |
| C13 | Switch/data island is `0x004abe4a-0x004abf9c`, SHA-256 `02dbb079f215d8342f4903e5da06e14647786fa7bcaaf5d4c67c45534e0bf1be`, parent-only; the island plus four-byte pad through `0x004abfa0` hashes to `1f86c1997bdff7e39666c597aaeee4438261a16c36ca2e56a2fe04dbee1905da`. | Very strong | repeated bounded bytes/table refs/hashes. | UID00014H/UID00014D | incorporate | applied | Both exact spans/hashes and parent-only/non-emitting disposition are in target and aggregate; validators `000000012392`/`000000012394`. |
| C14 | Island subspans are 2-byte NOP, 4-entry low table, 18-entry high table, and 248-byte selector table. | Very strong | Raw bytes/table decode. | UID00014H/UID00014D | incorporate | applied | Exact subspan inventory is retained in target evidence and aggregate synchronization; validators `000000012392`/`000000012394`. |
| C15 | `0x004abf9c-0x004abfa0` is four-byte `0xcc` padding before UID00014I. | Very strong | bytes/lookup. | UID00014H/UID00014D | incorporate | applied | Exact four-byte parent-only padding and successor disposition are in both docs; UID00014I verify-only hash `E451797AB4497C32591C4974FD3C47999307B4AFD90967E83A511103FEF299F7`; validators `000000012392`/`000000012394`. |
| C16 | Apply exact formal R1 only to UID00014H; do not emit tables/RTTI/dispatch storage. | Very strong | Source body and compiler/data distinction. | UID00014H formal | incorporate | applied | R1 is installed only on UID00014H. Generated command `000000012420` has one target row/definition, zero target marker, zero old names, and zero handwritten compiler data; generated SHA-256 `52F1D8C90B07EC90F9B034B309AA2F6DE04E43CFAC7F00C4959353503BE843A1`. |
| C17 | Target score improves `86/91 -> 92/94`; metadata otherwise unchanged. | Strong | All prior target blockers resolved. | UID00014H metadata/Score | incorporate | applied | Target is `92/94`; UID00014H, exact range, owner/emitter UID00004P, TRUE, blank position, and Nested 0 are preserved; `000000012392` reports completion/confidence updates. |
| C18 | Historicalize `GetExceptionCodeText`/file-static uncertainty without deleting provenance. | Very strong | Exact source contradicts old inference. | UID00014D/04P/0J8 and target history | historicalize | applied | Target, aggregate, class, file, and writer explicitly label old identities as historical/superseded while retaining their rationale; final scoped validators `000000012392`, `000000012393`, `000000012394`, `000000012405`, `000000012409`. |
| C19 | Synchronize writer, aggregate, class, file, and rdata support; API/companion pages verify-only. | Strong | Current-link audit and bounded effect. | UID00014G/14D/04P/0J8/259 | incorporate | applied | Five support pages were synchronized and validated by `000000012393`, `000000012394`, `000000012405`, `000000012409`, and `000000012397`. Verify-only UID0000TQ/2AS/14I/14E/14F/1QB were reread; UID0001QB received only validator-managed renamed-link propagation, no B003 prose edit. |
| C20 | Manual coverage rows are stale and exact supervisor-owned replacements are supplied; B003 does not edit them. | Very strong | Read-only coverage audit. | Manual coverage text section | incorporate | applied | Exact replacement text remains below; readback confirms manual rows remain stale (`84`, `86`, `86`, `84`, `76`, `86` respectively). UID00014H's path/title link was updated automatically by validator `000000012392`; B003 made no manual coverage edit. |

## Positive Evidence Summary

- Exact source and binary agreement covers method name, return type, static class membership, all 22 cases, string spellings, fallback buffer, flags, module, nested API shape, argument values, and return.
- Exact companion agreement extends beyond the target: UID00014I implements the same PE-section `GetLogicalAddress` algorithm and UID00014G contains the same exception report format lineage.
- Binary ownership is narrow: two calls from one ExceptionHandler writer, direct read-only literals in UID000259, and already-typed WideApi dispatch slots.
- No score blocker from the old page remains at target level. Remaining ExceptionHandler raw-helper/class-formal debt is broader family work and does not make this exact body ambiguous.

## IDA MCP Facts

- Function/range facts: `sub_4ABD10`, `0x13a` bytes, 94 instructions, 29 basic blocks, IDA cyclomatic value 3 for the switch-lowered graph; predecessor UID00014G ends exactly at start; target ends exactly at non-function `0x004abe4a`.
- Data/table/padding facts: `0x004abe4a-0x004abe4c` is `66 90`; `0x004abe4c-0x004abe5c` is a 4-entry low table; `0x004abe5c-0x004abea4` is an 18-entry high table; `0x004abea4-0x004abf9c` is a 248-byte sparse selector; `0x004abf9c-0x004abfa0` is `cc cc cc cc`.
- Xref facts: two target code xrefs; two fallback-buffer xrefs; one `NTDLL.DLL` xref; target plus initializer references to both API slots; one target reference to each table start.
- Global/type facts: `0x0069be78` is `GetModuleHandleW`; `0x0069be6c` is `FormatMessageW`; `0x0069af28` is the 0x400-byte fallback buffer; 22 returned literals occupy `0x006198b4..0x00619ba0`; `NTDLL.DLL` begins at `0x00619bc0`.
- Negative IDA facts: no ECX read, no third caller, no allocation/free, no fallback status branch, no pointer table, no separate function at the island start, and no source-bearing successor bytes before UID00014I.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ab480-0x004ac89a` | UID00014D `ExceptionHandler` | Aggregate/container | TRUE | UID00004P | `86/90` | Implemented bounded support update; aggregate/formal unchanged. |
| `0x004ab870-0x004abd10` | UID00014G `ExceptionCrashReportWriter` | Sole containing caller function | TRUE | UID00014D | `86/91` | Call facts synchronized; path/score/formal unchanged. |
| `0x004abd10-0x004abe4a` | UID00014H `ExceptionHandlerGetExceptionString` | Private static source method | TRUE | UID00004P | `92/94` | UID-preserving rename and R1 implemented. |
| `0x004abe4a-0x004abf9c` | Parent-only under UID00014D | Compiler-lowered switch tables | FALSE as separate source | UID00014D | N/A | Keep unsplit/non-emitting. |
| `0x004abf9c-0x004abfa0` | Parent-only padding | Alignment | FALSE | UID00014D | N/A | Preserve. |
| `0x004abfa0-0x004ac035` | UID00014I `ExceptionLogicalAddressHelper` | Companion source helper | TRUE | UID00014D | `86/91` | Verify-only; corroborates lineage. |
| `0x006198b4..0x00619bc0` | Within UID000259 | Direct wide literals | Source-emitted through consumers | UID0000J8 | `87/91` | Bounded literal/macro/no-pointer-table update implemented; formal stays blank. |
| `0x0069af28-0x0069b328` | Static BSS storage | `TCHAR szBuffer[512]` | Source local static | UID00014H source | N/A | Document, do not create raw global page. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ab951` | UID00014G -> UID00014H | Pushes exception code; target return is discarded. |
| `0x004ab968` | UID00014G -> UID00014H | Pushes same exception code; returned wide pointer feeds `WideCharToMultiByte` and exception-line output. |
| `0x004abe22` | UID00014H -> `0x0069af28` | Passes static fallback buffer to `FormatMessageW`. |
| `0x004abe2a` | UID00014H -> `0x00619bc0` | Passes `L"NTDLL.DLL"` to `GetModuleHandleW`. |
| `0x004abe2f` | UID00014H -> slot `0x0069be78` | Calls `GetModuleHandleW`. |
| `0x004abe3b` | UID00014H -> slot `0x0069be6c` | Calls `FormatMessageW`. |
| `0x004abe41` | UID00014H -> `0x0069af28` | Returns the shared static buffer. |
| `0x005996bd` | UniAPI initializer -> `0x0069be6c` | Stores resolved `FormatMessageW`. |
| `0x005996db` | UniAPI initializer -> `0x0069be78` | Stores resolved `GetModuleHandleW`. |

## Documentation Evidence And IDA Status

- Existing docs correctly establish the parent/class/file route, exact function boundary, literal island, writer callers, static fallback address, and switch-data extent.
- Historical pre-callback docs called the helper `ExceptionCodeStringHelper` or file-static `GetExceptionCodeText`, left API slots unidentified, and capped the score because source name/type/ownership were open. Current target/support docs now mark those conclusions superseded and contain the exact source identity.
- UID0000TQ and UID0002AS already contain exact API identities/prototypes and require no edit.
- UID000259 rejects a pointer-table/raw-rdata body and now states the exact method identity, 22 direct macro literals, `NTDLL.DLL` role, and source-emission relationship.
- Historical generated command `000000012372` had one UID00014H Empty Emitter Marker and zero target definitions. Current waited command `000000012420` has one exact R1 definition and zero target markers, with the exact current hash/count proof recorded below.
- Manual coverage rows remain stale for the renamed target and several support scores/descriptions. Exact replacement text appears below; B003 did not edit manual coverage. Validator `000000012392` automatically propagated the UID00014H link/path only.

## Ranked Ownership Analysis

### 1. UID00004P ExceptionHandler class through UID0000J8 ExceptionHandler.cpp

- Evidence for: exact header declaration is private static; both calls occur in the same class report writer; companion logical-address method shares source lineage; current owner/emitter already routes here.
- Evidence against: target body has no ECX read. This is expected for a static member and is not contrary evidence.
- Decision: retain as canonical owner/emitter and source route.

### 2. File-static helper in ExceptionHandler.cpp

- Evidence for: no ECX consumption and current B005 descriptive inference.
- Evidence against: exact published declaration/body proves class-static membership; no binary fact contradicts a static method.
- Decision: reject as stale ownership shape while retaining the old inference in history.

### 3. NTDLL/CRT/Error/generic crash utility

- Evidence for: fallback queries NTDLL and uses Win32 formatting.
- Evidence against: those are consumed APIs; all callers, literals, and companion routines belong to ExceptionHandler. No independent source route or generic caller exists.
- Decision: reject.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. Keep `NexusTK/platform/ExceptionHandler.cpp`.
- Likely full contents: existing ExceptionHandler class, filter, report writer, exact target method, logical-address and stack/ImageHlp helpers, and source-generated literals.
- Candidate related items rejected: new `CrashDiagnostics.cpp`, NTDLL wrapper file, Error module, WideApi owner, and raw switch-table source file.
- Standalone, narrow, or broad source-file inference: existing narrow platform crash-diagnostics source file.

## Source Placement

- Recommended placement: private static declaration in `ExceptionHandler`; definition in `NexusTK/platform/ExceptionHandler.cpp` emitted from UID00014H through UID00004P/UID0000J8.
- This placement fits the existing project route, direct caller locality, exact source lineage, companion method behavior, and diagnostic literal ownership.
- Rejected placements: `Crasher.cpp` is only a consumer of crash state; `Application.cpp` constructs/cleans up the object; `Error.cpp`, WideApi, NTDLL, runtime, and a new support file do not own the helper.
- Remaining placement uncertainty: none material to target emission. Exact header filename is not PDB-proven, but class/source ownership is strong enough for the existing route.

## Range / Split / Padding / Reclassification Analysis

- Exact target range remains `0x004abd10-0x004abe4a`, size `0x13a`/314. Do not extend the page to include compiler tables.
- Predecessor UID00014G ends exactly at `0x004abd10`; there is no predecessor padding.
- The adjacent `0x004abe4a-0x004abf9c` data island is generated by the target switch and remains parent-only inside UID00014D. Its exact internal spans are recorded above.
- The existing four-byte `0x004abf9c-0x004abfa0` `0xcc` alignment remains parent-only before UID00014I.
- No new child, ignored page, global page, pointer-table page, import directive, or source split is warranted.
- Reclassification is semantic/title-only: generic helper -> exact private static class method, still reconstructable source code.

## Negative Evidence Summary

- No target xrefs exist outside UID00014G; consumers do not establish another owner.
- No ECX use exists, but that distinguishes static from non-static member, not class-static from file-static. Exact source resolves the latter.
- No const return contract exists; the mutable static fallback directly contradicts a uniformly const source type.
- No dynamic buffer allocation, `FORMAT_MESSAGE_ALLOCATE_BUFFER`, `LocalFree`, post-format finalizer, or success test exists.
- No standalone exception-name pointer table exists in UID000259.
- No function, independent xref family, or source name begins at the switch island.
- No `FORMAT_MESSAGE_FROM_SYSTEM` flag exists; `0x0a00` has an exact two-flag decomposition.
- No evidence supports modernizing the source quirk from `sizeof(szBuffer)` to character count 512.

## IDA Rename / Type / Comment Recommendations

- Validator-aware documentation rename: UID00014H path/title to `ExceptionHandlerGetExceptionString`, preserving UID and range.
- Source-facing IDA name if a separately authorized IDA pass occurs: `ExceptionHandler__GetExceptionString` or the project's standard class-method encoding; prototype `LPTSTR __stdcall(DWORD)` at binary ABI level, with source declaration `static LPTSTR GetExceptionString(DWORD)` and no explicit assembly-shaped convention in formal C++.
- Comment the fallback as legacy shared `TCHAR[512]` storage with `sizeof` passed to `FormatMessage` under a Unicode build; do not call the second API a finalizer.
- Comment the island as compiler-lowered switch control data for `GetExceptionString`, not an independent source table.
- IDA DB edits were not requested and were not performed during either the research pass or callback.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The source body is complete, independently corroborated, and above the owner/emitter quality gate.
- Implemented formal destination R1: renamed UID00014H. This is the only C++ text in this report.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LPTSTR ExceptionHandler::GetExceptionString(DWORD dwCode)
{
#define EXCEPTION(name) \
    case EXCEPTION_##name: \
        return _T(#name);

    switch (dwCode) {
        EXCEPTION(ACCESS_VIOLATION)
        EXCEPTION(DATATYPE_MISALIGNMENT)
        EXCEPTION(BREAKPOINT)
        EXCEPTION(SINGLE_STEP)
        EXCEPTION(ARRAY_BOUNDS_EXCEEDED)
        EXCEPTION(FLT_DENORMAL_OPERAND)
        EXCEPTION(FLT_DIVIDE_BY_ZERO)
        EXCEPTION(FLT_INEXACT_RESULT)
        EXCEPTION(FLT_INVALID_OPERATION)
        EXCEPTION(FLT_OVERFLOW)
        EXCEPTION(FLT_STACK_CHECK)
        EXCEPTION(FLT_UNDERFLOW)
        EXCEPTION(INT_DIVIDE_BY_ZERO)
        EXCEPTION(INT_OVERFLOW)
        EXCEPTION(PRIV_INSTRUCTION)
        EXCEPTION(IN_PAGE_ERROR)
        EXCEPTION(ILLEGAL_INSTRUCTION)
        EXCEPTION(NONCONTINUABLE_EXCEPTION)
        EXCEPTION(STACK_OVERFLOW)
        EXCEPTION(INVALID_DISPOSITION)
        EXCEPTION(GUARD_PAGE)
        EXCEPTION(INVALID_HANDLE)
    }

#undef EXCEPTION

    static TCHAR szBuffer[512] = { 0 };

    FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE,
                  GetModuleHandle(_T("NTDLL.DLL")),
                  dwCode,
                  0,
                  szBuffer,
                  sizeof(szBuffer),
                  0);

    return szBuffer;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation: all 22 known codes return direct compile-time TCHAR literals; every other code calls the module-message API and returns the process-lifetime shared buffer without a result check.
- Source-era shape: preserves the exact `EXCEPTION` macro, `LPTSTR`, `DWORD`, `TCHAR`, `_T`, generic Win32 API macros, static 512-element buffer, and `sizeof` quirk from the source lineage. Under NexusTK's Unicode build, APIs resolve to the observed W slots and the size argument is `0x400`.
- Inferred versus proved names: `GetExceptionString`, `dwCode`, `szBuffer`, and the macro are source-proven; only replacing enclosing `MSJExceptionHandler` with current `ExceptionHandler` is a Nexus-specific adaptation supported by current ownership docs.
- No raw addresses, IDA names, decompiler labels, switch tables, explicit dispatch-slot calls, vtable/RTTI objects, or modern container/string substitutions are present.
- Third-party import directive: not applicable. This is adapted NexusTK project source, not a static third-party embed destination.

## Final Recommendation

- Implemented UID00014H at the exact method path/title with R1, exact Item Summary/evidence/history, and `92/94`.
- Retained owner/emitter UID00004P, reconstructable true, blank optional position, Nested 0, and exact range.
- Synchronized UID00014G, UID00014D, UID00004P, UID0000J8, and UID000259 at report-level detail without changing their scores/routes/formals.
- Reread UID0000TQ, UID0002AS, UID00014I, UID00014E, UID00014F, and UID0001QB verify-only; no factual contradiction required a prose/body edit. UID0001QB's target link changed only through validator-managed rename propagation.
- Switch tables, static storage, API slots, vtable/RTTI, and manual coverage remain non-emitting or supervisor-owned as specified.
- No accepted target/callback item remains. Broader UID00004P complete-class formal and unrelated raw ExceptionHandler helper bodies remain outside this exact child implementation and are not misrepresented as solved.

## Recommended Target Doc Changes

- Implemented target path: validator-aware rename from `by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md` to `by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md`.
- Implemented metadata: `COMPLETION:92`, `CONFIDENCE:94`; retained `CANONICAL_OWNER:00004P`, `EMITTER_UIDS:00004P`, `RECONSTRUCTABLE:TRUE`, blank position, `Nested:0`.
- Exact Item Summary: `Private static ExceptionHandler::GetExceptionString(DWORD) maps 22 SEH codes to TCHAR names and falls back to NTDLL FormatMessage using shared TCHAR[512] storage; exact source lineage, writer calls, switch island, API slots, and padding are verified.`
- R1 is installed exactly in the formal block.
- Exact target hash, 94-instruction/29-block facts, two-call semantics, all 22 mappings, source/header lineage, static access/type/lifetime, API slot identities, flags, fallback size quirk/failure behavior, island hashes/subspans, and predecessor/successor dispositions are applied.
- `ExceptionCodeStringHelper`, `GetExceptionCodeText`, unknown finalizer/helper, file-static interpretation, and vague wide-pointer constness are preserved as explicitly superseded assumptions.
- Negative evidence and rejected modernizations/owners are preserved.

## Recommended Support Doc Changes

- Implemented UID00014G `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`: renamed target link, private static identity, calls at `0x004ab951`/`0x004ab968`, discarded first return, converted second return; preserved `86/91`, route, blank formal, and unrelated report/ImageHlp detail.
- Implemented UID00014D `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`: child link/title/inventory, private static identity, exact source lineage, island subspans/hash, and unchanged parent-only padding; preserved `86/90`, range, route, blank formal, and unrelated children/raw helpers.
- Implemented UID00004P `by-class/ExceptionHandler.md`: exact `private: static LPTSTR GetExceptionString(DWORD dwCode);` guidance, source/header lineage, static/no-ECX explanation, mutable return/fallback lifetime, and rejected old file-static declaration; preserved `87/90`, owner/emitter/route, layout, blank formal, and broader raw-helper blockers.
- Implemented UID0000J8 `by-file/ExceptionHandler.md`: exact class-static method/`MSJEXHND` source state, closed open question, and historicalized `GetExceptionCodeText`; retained `87/88`, `NexusTK/platform/`, and unrelated family boundaries.
- Implemented UID000259 `by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`: renamed target link/title, 22 direct macro-generated TCHAR literals plus `NTDLL.DLL`, no pointer table, and R1 source emission; preserved `87/91`, owner/emitter, Nested -12, blank formal, vtable/COL, and unrelated literals.
- Verified UID0000TQ and UID0002AS read-only; existing slot names/prototypes remain exact.
- Verified UID00014I read-only; its body remains lineage corroboration, not a direct destination.
- Verified UID00014E, UID00014F, and UID0001QB read-only with no contradiction. Validator-managed rename propagation updated only UID0001QB's UID00014H link/path.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/91`, owner/emitter UID00004P, true, blank position/formal, Nested 0.
- Implemented target: `92/94`, same owner/emitter/reconstructable/position/nesting and exact range, complete R1.
- Completion rose six points because the exact method name, class/static access, return type, full body, API identities, storage extent/lifetime, fallback source shape, table disposition, and implementation route are closed.
- Confidence rose three points because exact upstream source/header lineage is independently corroborated by complete binary behavior and companion-family algorithms, not merely naming resemblance.
- Not higher than `92/94`: the NexusTK header filename and whether its local style retained parameter name `dwCode` are not PDB-proven; broader class formal/raw-helper work remains incomplete. Neither uncertainty changes target behavior or route.
- Score-improvement attempt results:
  - Name/access blocker: removed through exact source/header match.
  - Return/constness blocker: removed through `LPTSTR` declaration plus mutable static fallback.
  - API identity blocker: removed through live initializer stores and current dispatch docs.
  - Fallback storage blocker: removed through exact BSS span and source `TCHAR[512]`.
  - Switch split blocker: removed through table boundaries/source switch correspondence.
  - Complete C++ blocker: removed by R1.
- Support scores/routes remain unchanged; the target-specific evidence improves their descriptions but does not close their independent raw-body/class-formal blockers.

## Open Questions With Attempted Resolution

- Exact source-facing helper name: resolved to `GetExceptionString` by exact source and header declaration.
- Member/static/access shape: resolved to private static; no ECX consumption is consistent.
- Return type and constness: resolved to `LPTSTR`; preserve legacy mutable typing.
- Fallback API identities and nesting: resolved to `FormatMessageW(GetModuleHandleW(L"NTDLL.DLL"), ...)` through evaluation order, initializer stores, prototypes, and source.
- Fallback storage and lifetime: resolved to shared process-lifetime `TCHAR[512]` at exact BSS span.
- `0x400` size: resolved as source's `sizeof(szBuffer)` Unicode quirk, not element count.
- Switch/data disposition: resolved as parent-only compiler lowering with explicit alignment/padding.
- Original source file in NexusTK: existing `platform/ExceptionHandler.cpp` route is strongest; no separate file evidence exists.
- Remaining uncertainty: exact NexusTK header filename and parameter spelling are unavailable without original project source/PDB. This caps confidence at 94 but does not block R1, metadata, ownership, or source placement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only files inspected: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`.
- The target row needs a path/title/score/description replacement. Support rows whose exact current metadata or source identity is stale also need replacement text. B003 must not edit manual coverage.

File/placement: `by-memory/-coverage-report.md`, replace current UID00014D row with:

    - [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) : reconstructable : 86% : strong : ExceptionHandler aggregate with exact bounds, complete child/raw/data inventory, private static GetExceptionString source lineage, compiler-lowered switch-island and padding dispositions, constructor/destructor/filter/report/ImageHlp evidence, parent class route, and retained blank aggregate formal because exact source bodies belong to child pages.

File/placement: `by-memory/-coverage-report.md`, replace current UID00014G row with:

    - [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) : reconstructable : 86% : strong : Crash report writer with exact bounds/caller/report fields/ImageHlp and fallback stack paths; two calls to private static ExceptionHandler::GetExceptionString are verified at 0x004ab951 and 0x004ab968, with the first result discarded and the second converted from UTF-16 for the exception report line; final C++ remains blank.

File/placement: `by-memory/-coverage-report.md`, replace current UID00014H row with:

    - [UID:00014H][0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString](by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md) : reconstructable : 92% : very strong : Private static LPTSTR ExceptionHandler::GetExceptionString(DWORD) is source-ready from exact MSJEXHND lineage and live IDA evidence: 22 direct TCHAR names, two writer calls, shared static TCHAR[512] NTDLL FormatMessage fallback, exact Unicode sizeof-buffer quirk, API dispatch identities, switch-island/padding disposition, and complete formal C++.

File/placement: `by-memory/-coverage-report.md`, replace current UID000259 row with:

    - [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) 0x006196bc-0x00619d28 | vtable/string-data | ExceptionHandlerDiagnosticsReadOnlyData : reconstructable : 87% : strong : ExceptionHandler COL/vtable and diagnostics literal island with exact boundary, 22 direct GetExceptionString TCHAR names plus NTDLL.DLL, no pointer-table disposition, report/logical-address/stack/ImageHlp consumers, pooled-literal caveats, and source emission through class/helper consumers rather than raw vtable or data arrays.

File/placement: `by-class/-coverage-report.md`, replace current UID00004P row with:

- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) : reconstructable : 87% : strong : Process crash-filter/report class with exact 0x828 layout, lifecycle, fields, filter/writer/ImageHlp family, private static LPTSTR GetExceptionString(DWORD) declaration/source lineage, and platform source ownership; class formal remains blank because independent raw-helper and complete-class declaration blockers remain.

File/placement: `by-file/-coverage-report.md`, replace current UID0000J8 row with:

- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) : reconstructable : 87% : strong : NexusTK/platform/ExceptionHandler.cpp owns the process exception-filter class/global/report family; exact private static GetExceptionString source lineage, 22-code/fallback implementation route, companion logical-address evidence, ImageHlp/raw-helper inventory, Crasher/Application boundaries, and retained broader source-quality blockers are documented.

- Reason B agent must not apply directly: manual `-coverage-report.md` files are supervisor-owned restricted artifacts; validator-generated coverage does not replace this manual text.
- No auto-generated tracker row text is proposed because tracker state is validator/supervisor-owned.

## Follow-Up Actions

- The accepted C01-C20/R1 callback implementation, bounded support synchronization, scoped validators, verify-only rereads, and waited generated verification are complete; no B003 implementation item remains.
- Manual coverage application, independent report validation, report execution, count, artifact path/status, move, archive, and later generated state are external supervisor/validator-owned facts; this artifact neither asserts nor directs those lifecycle outcomes.
- B003 performed no report execution/probe/count/registry/revalidation/lifecycle/move/archive command and no manual coverage/generated/validator-state edit. Broader UID00004P complete-class/raw-helper reconstruction is separate family debt and is not a blocker disguised as target follow-up.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; `92/94` reflects complete target source quality while preserving modest caps for Nexus-specific spelling/header uncertainty.
- Remaining uncertainty: only original NexusTK header filename and exact parameter spelling. There is no unresolved target behavior, ownership, type, API, storage, split, or formal-C++ question.

## Validator Results

- All commands were run from `source-3/project-documentation` with `--apply --queue-timeout 240`; each exited 0 with `ok:1`. Scoped refreshes were deferred unless explicitly waited.

| Command ID | Timestamp | Scope/result | Side effects and proof |
| --- | --- | --- | --- |
| `000000012392` | `2026-07-14T22:23:38-04:00` | UID00014H renamed target; exit 0, ok 1. | `path_update:1`, `completion_update:1`, `confidence_update:1`, `autogen_registry_update:2`, `reference_source_path_update:7`, `uid_link_update:22`, `projected_stats_update:1`; generated refresh deferred. Three unrelated `missing_ref_uid` diagnostics (`0003MT`, `00039L`, `0003T6`) were reported in manual by-memory coverage and were not hand-repaired. Validator propagation updated the renamed UID00014H link in current ordinary references and the manual coverage link/path. |
| `000000012393` | `2026-07-14T22:25:50-04:00` | UID00014G writer; exit 0, ok 1. | `projected_stats_update:1`, incremental stats no-op, generated refresh deferred. |
| `000000012394` | `2026-07-14T22:26:48-04:00` | UID00014D aggregate; exit 0, ok 1. | `projected_stats_update:1`, incremental stats no-op, generated refresh deferred. |
| `000000012395` | `2026-07-14T22:27:32-04:00` | UID00004P class initial scoped validation; exit 0, ok 1. | `projected_stats_update:1`, incremental stats no-op, generated refresh deferred. |
| `000000012396` | `2026-07-14T22:28:18-04:00` | UID0000J8 file initial scoped validation; exit 0, ok 1. | `projected_stats_update:1`, incremental stats no-op, generated refresh deferred. |
| `000000012397` | `2026-07-14T22:28:59-04:00` | UID000259 read-only-data support; exit 0, ok 1. | `projected_stats_update:1`, incremental stats no-op, generated refresh deferred. |
| `000000012405` | `2026-07-14T22:30:30-04:00` | UID00004P final scoped validation after historical-label cleanup; exit 0, ok 1. | `projected_stats_update:1`, incremental stats no-op, generated refresh deferred; this is the final class-page validator. |
| `000000012409` | `2026-07-14T22:30:52-04:00` | UID0000J8 final scoped validation after historical-Wave3 wording cleanup; exit 0, ok 1. | `projected_stats_update:1`, incremental stats no-op, generated refresh deferred; this is the final file-page scoped validator. |
| `000000012413` | `2026-07-14T22:31:11-04:00` | First waited UID0000J8 refresh; exit 0, ok 1, generated completed. | Full authorized refresh reported `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:86`, `autogen_emitter_has_no_code:175`, `autogen_registry_rebuild:1`, and `generated_metadata_refresh:281`. A later-dequeued deferred refresh from `000000012409` replaced only the generated header, so a second waited refresh was issued for unambiguous freshness. |
| `000000012420` | `2026-07-14T22:32:19-04:00` | Final waited UID0000J8 refresh; exit 0, ok 1, generated completed. | Same project-wide generator warning counts/registry and metadata refresh classes as above. `auto-generated/NexusTK/platform/ExceptionHandler.cpp` header is `000000012420`, `foreground-generated-refresh`, timestamp `2026-07-14T22:32:19-04:00`, SHA-256 `52F1D8C90B07EC90F9B034B309AA2F6DE04E43CFAC7F00C4959353503BE843A1`. |

- Latest external generated observation after B003's waited refresh: foreground header `000000012445`, timestamp `2026-07-14T22:36:28-04:00`, SHA-256 `73349EF749919E18A075CBEAF2A3A2BD06C3328385B04EA6412180DE3665D8C6`. B003 did not issue or manage that external command; content counts and absence assertions remained identical.
- Final generated assertions: UID00014H row count 1; exact `LPTSTR ExceptionHandler::GetExceptionString(DWORD dwCode)` definition count 1; UID00014H Empty Emitter Marker count 0; old `ExceptionCodeStringHelper`/`GetExceptionCodeText` count 0; direct `EXCEPTION(<uppercase-name>)` case count 22; `NTDLL.DLL` count 1; `FormatMessage` call count 1; existing `TopLevelExceptionFilter` count 1; existing `SendCrashDiagnosticText` count 1; handwritten `ExceptionHandler_vtable`/COL/RTTI/raw-address data count 0. No duplicate or wrong-range UID00014H emitter exists.
- The generated file still contains unrelated pre-existing empty emitters for UID00004P, UID00014D, UID00014G, UID00014I, UID00014J, UID0000QN, UID000297, and UID000259. The accepted callback requires only UID00014H marker removal and does not misstate those broader debts as solved.
- MCP/tool limitation record remains research evidence: current-session lookup classified raw UniAPI start `0x005995b0` as not an IDA function, so Hex-Rays was intentionally not used there; bounded live disassembly supplied the initializer evidence.

## Changed Files

- UID-preserving rename/implementation: historical `by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md` -> current `by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md`, final SHA-256 `D2081329E46C1660D0A8D29342A1B2CCCBCC17BE760BD90C4FB30D4CA446FC81`.
- Modified ordinary support pages:
  - `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`, SHA-256 `4CE2CF3384D2177B002A084BE91A6FFCBFA9C129AB55521508A444FFDDE37569`.
  - `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`, SHA-256 `45952D60EDDD39B233DA0DE6AAD88B704792D8D6A55CAB0325D94439B2945468`.
  - `by-class/ExceptionHandler.md`, SHA-256 `0E68334304A9C0B5B6F30CFEDD6CD712B0CDDD05A2A5FC42165234419C6BA3FE`.
  - `by-file/ExceptionHandler.md`, SHA-256 `3C01770C7E07CC15C38E968BD9FE0F08084CCA15D832AE163C3ED030A412AE7E`.
  - `by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`, SHA-256 `A5D2752A1AF1193EAF65385D4EDBBF2835FA4E0086C0E35943C055098D54758B`.
- Validator-managed renamed-link propagation only: `by-meta/client_crash_diagnostics.md`, SHA-256 `A52DFE06498225AE3F44CD2D33180EA726DCFB5B7AE593B9B22FDDC7CF695FA8`; B003 made no prose/formal/metadata edit.
- Verify-only rereads with no direct edit: UID0000TQ `CAD07BDEA56F1F8993A06B233A0A32594FC82DA2BE06B35897E019DB671149B4`; UID0002AS `1A6EDC9EDA55DF7FF6C7B843C33B504B4B35E54D0DBE8CE2A46124F7CDCED367`; UID00014I `E451797AB4497C32591C4974FD3C47999307B4AFD90967E83A511103FEF299F7`; UID00014E `D8ACF0CBE3F78D8C3CDD4943169AD45556960DAD1D5348669A5C8EE9D3D44E85`; UID00014F `1AE07EFAFB1903784589DC0E6368B90462592F77F2EACBAC9491C5287ACBC3DE`; UID0001QB was reread after its validator-managed link propagation as recorded above.
- Report updated in place: `tools/leaser/Agents/Agent-B003/research/00014H-ExceptionCodeStringHelper-source-quality.md`; current hash is reported after final self-review.
- Validator-owned side effects, not manual B003 edits: UID00014H link/path propagation in `by-memory/-coverage-report.md` (current SHA-256 `B2F9A66E683C4C1862D281A935B197DD6B2F796127F9B255B54066720C70BD26`), generated coverage/tracker/C++ refreshes, projected stats, and `tools/validator.ini` registry rebuild. The exact manual row contents remain stale and the replacement text above remains supervisor-owned.
- B003 manually edited no `-coverage-report.md`, generated/tracker/audit/supervisor/validator-state/queue/lock/lifecycle/archive file and ran no report execution/probe/count/registry/revalidation/move/archive command.
- Lease proof: every ordinary lease was acquired only for its active edit/validation and released before the next; final `tools/leaser/Agents/current_leases.md` readback contains no B003 row.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation; exact accepted artifact SHA `12A7975CBEF4440A890127F0A6E5F148591D488E26BD1742546B958E638DB0CF` passed Gate 1.
- [x] Target/support docs updated: UID00014H, UID00014G, UID00014D, UID00004P, UID0000J8, and UID000259; verify-only UID0000TQ, UID0002AS, UID00014I, UID00014E, UID00014F, and UID0001QB reread.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination, legal final action/state, and implementation proof for every accepted claim.
- [x] Metadata/score change applied: UID00014H `86/91 -> 92/94`; support scores unchanged.
- [x] Score-limiting blockers researched to resolution; no target blocker remains.
- [x] Owner/emitter/reconstructable state retained as UID00004P/UID00004P/TRUE.
- [x] UID-preserving target rename completed; no child/split created.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment conclusions applied or retained as not applicable.
- [x] Exact R1 first-draft C++ applied.
- [x] Third-party import directive confirmed not applicable because this is adapted NexusTK project source, not an embedded import.
- [x] Exact target/support doc facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 references encountered were labeled historical/non-authoritative rather than used as current evidence.
- [x] Open target questions closed; only documented nonblocking Nexus header/parameter spelling uncertainty remains.
- [x] One scoped validator was run after each final ordinary-page edit, with initial and correction validators both retained where applicable; final waited UID0000J8 refresh completed.
- [x] Generated refresh proof and exact manual supervisor-owned coverage replacement text recorded.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] Validator-aware UID00014H rename completed without UID/range/route loss.
- [x] R1 installed byte-for-byte in the renamed target formal block.
- [x] Target metadata, Item Summary, evidence, history, score rationale, negatives, and source lineage applied.
- [x] UID00014G two-call/discard/conversion facts and renamed link applied with score/formal unchanged.
- [x] UID00014D exact child identity, source lineage, table subspans/hash, and padding applied with score/formal unchanged.
- [x] UID00004P private static declaration/type/access/source evidence applied with class formal/score/layout otherwise unchanged.
- [x] UID0000J8 source inventory/open-question/history synchronization applied with route/score unchanged.
- [x] UID000259 exact literal/macro/no-pointer-table synchronization applied with score/formal/route unchanged.
- [x] Verify-only dependencies reread; no contradiction required a direct content edit, and UID0001QB received only validator-managed link propagation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with legal final action/state and destination-specific proof for C01-C20.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly retained with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed nonblocking rationale.
- [x] Scoped validators recorded for every final changed ordinary page; command IDs/timestamps/exits/ok/warnings are present; leases released immediately.
- [x] Final waited generated refresh `000000012420` recorded with header freshness/hash and exact one-definition/zero-target-marker/no-table assertions.
- [x] Current generated `ExceptionHandler.cpp` checked for one R1 definition, zero UID00014H Empty Emitter Marker, no duplicate/wrong-range body, and no handwritten switch/vtable/RTTI/data arrays.
- [x] Manual supervisor-owned coverage text retained without B003 manually editing coverage.
- [x] Changed/read-only/forbidden path sets and no-lease proof recorded.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000012469","destination_path":"executed-b-agent-research/B003/00014H-ExceptionCodeStringHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00014H-ExceptionCodeStringHelper-source-quality.md","timestamp":"2026-07-14T23:02:02-04:00","uid":"00014H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
