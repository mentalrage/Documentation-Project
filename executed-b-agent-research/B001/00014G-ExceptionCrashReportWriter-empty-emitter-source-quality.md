** TARGET-REPORT-UID:00014G **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00014G ExceptionHandler GenerateExceptionReport Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:00014G] as the exact source-bearing child for `[0x004ab870,0x004abd10)`, keep `CANONICAL_OWNER:00014D`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00014D`, but replace the descriptive `WriteCrashReport` identity with source-lineage-backed `void ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *pExceptionInfo)`.
- Final disposition: source-authored nonvirtual `ExceptionHandler` member in `NexusTK/platform/ExceptionHandler.cpp`; it is neither a file-static helper nor a separate `CrashReport.cpp` translation unit.
- Ordinary-document callback state: `APPLIED_VERIFIED`. Supervisor Gate 1 passed exact pre-callback report SHA256 `6191A9F031A514853C26444CC0350C945DBF92C6EFAF738A85B6A7DD1B43D4B4`. B001 then repaired the four `GetLogicalAddress` invocations across UID00014G, UID0004WU, and UID00014J to pass `sectionNumber, sectionOffset` directly; added the complete three-slot UID00014G consumer package to UID0002AS and UID0000TQ; ran serial scoped validators `17465` through `17469`; released every lease; and verified the callback at generated checkpoint `17467`. Current physical generated output is command `17510` and preserves the same accepted invariants. The accepted behavior/evidence/score package, UID00004P CPP-to-H migration, blank child-H dispositions, and unaffected UID0004WT definition remain preserved.
- Supervisor Gate 2B state: `APPLIED_VERIFIED` and persisted. The supervisor applied or explicitly verified every actionable row and every protected/no-action row in the exact IDA handoff, saved the IDB, and completed persisted readback. B001's own MCP work remained read-only.
- Confidence: very strong for exact runtime behavior, boundaries, ABI, source method/helper identities, class/file ownership, first-draft source shape, and support routing; strong rather than absolute for Nexus-specific local/global spellings that were lost at compile time.

## Supporting Research

- Lifecycle/status: the earlier revoked callback, command `17338`, validator migration `17353`, source-channel validators `17378`/`17379`/`17381`/`17382`/`17383`, first split checkpoint `17384`, defect-bearing physical command `17440`, and repaired callback checkpoint `17467` remain historical provenance. The current narrow callback was authorized from exact Gate 1 report SHA `6191A9F...3D4B4`; B001 changed exactly five ordinary docs, ran scoped validators `17465` through `17469`, and never hand-edited generated output. Current physical generated CPP/H headers identify command `17510`, refreshed `2026-07-25T04:52:56-04:00`. B001 made no IDA, coverage, direct generated, audit, goal, supervisor, validator-state, or lifecycle edit and ran no report lifecycle command; subsequent IDA and audit/catalog work was supervisor-owned.
- Gate 2B prestate session: authoritative database `f085b224`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, image base `0x00400000`, SHA256 `2C20AAD81BC18DE1FA91B04D7FBEC30A704D377E6E2A2E35344C06EAEE479BC0`, size `143186196`, with verified backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-00014G-20260725_230500.bak`. Supervisor save/readback produced stable IDB SHA256 `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`, size `143186768`, last write `2026-07-25T23:14:42.2666509-04:00`; MCP status was `ok`, Hex-Rays and strings were ready, and post-save `auto_analysis_ready:false` is recorded after exact raw-helper creation even though every required persisted readback succeeded. Historical sessions `supervisor_current_20260724_9f6e`, `b001_uid00014g_gate2b_rebase_20260724`, and `1ce787ed` supplied earlier evidence only.
- Exact target bytes: 1184 bytes from `0x004ab870`, SHA256 `B6A47AE552DF79B647601FBB60FDDD04AE54E4774A5CA660109FB9A5F85199D7`; prefix `55 8B EC 81 EC 38 0C 00 00 A1 24 2F 67 00 33 C5`; suffix `5F 5E 33 CD 5B E8 25 BA 11 00 8B E5 5D C2 04 00`.
- Source lineage: Matt Pietrek's Microsoft Systems Journal `MSJEXHND.CPP` source names the method `MSJExceptionHandler::GenerateExceptionReport`, with `InitImagehlpFunctions`, `IntelStackWalk`, `ImagehlpStackWalk`, `GetExceptionString`, and `GetLogicalAddress`. The source mirror checked was `https://docs.polserver.com/doxygen/html/dc/dc4/msjexhnd_8cpp_source.html`; the May 1997 article mirror was also checked for the source-family design.
- Lineage is naming/source-shape evidence, not permission to copy behavior blindly. NexusTK changes the report destination/content, uses wide PlatformApi dispatch slots, stores callbacks in its `0x828` object, passes `FILE *` into stack helpers, adds version/timer/phase/RGB565 fields, omits `FreeLibrary` on ImageHlp resolution failure, and retains an unconditional separator `fputs` even when opening the stream failed.
- Historical reports searched by UID/address/name/family: B005 UID00014D, B015/B001 UID00014F, B003 UID00014H and UID00014I, B005 UID000259, B014 UID0002GP, B001 UID0002AR and UID000294. They were treated as leads and revalidated against the live database/current docs.

## Target

- Target UID: `00014G`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:00014G] `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`, exact source-bearing function body and sole report-coverage target.
- Target path: `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, by-memory not-covered reconstructable queue, with generated `Empty Emitter Marker` in `auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- Current supervisor classification: uncovered reconstructable by-memory empty emitter requiring source-quality inference and formal C++.
- Assignment-time baseline scores were target `86/91`, parent UID00014D `86/90`, class UID00004P `91/92`, and file UID0000J8 `90/92`. Current ordinary metadata records target `94/96`, parent `90/94`, filter UID00014F `90/94`, helper children UID0004WT/UID0004WU/UID00014J each `94/94`, class `93/95`, and file `92/94`; the recommendations and all four method formals are now ordinary- and generated-readback verified.

## Current Target State

- Assignment-time baseline metadata was `86/91`, owner/emitter UID00014D, reconstructable true, and blank formal. Current UID00014G metadata is `94/96` with the same route. Its ordinary CPP block now passes `sectionNumber, sectionOffset` directly to `GetLogicalAddress(DWORD &, DWORD &)`, validator `17465` passed, and current generated command `17510` reproduces the corrected call with no address-of invocation tokens.
- Existing owner/emitter state is correct. UID00014D is the exact memory aggregate and routes into class UID00004P/file UID0000J8.
- Narrow-callback generated checkpoint command `000000017384` first proved the corrected source-channel split; defect-bearing command `17440` is historical, and repaired callback checkpoint `17467` is now an earlier checkpoint. Current physical generated-file metadata is command `000000017510`, refreshed `2026-07-25T04:52:56-04:00`, in both CPP/H headers. `auto-generated/NexusTK/platform/ExceptionHandler.cpp` is SHA256 `0F2CAD462252019F0A6EA5A1C18C2452D1530BB3A76DA4C9665FA82BB6D7D2D2`, 18707 bytes, 533 lines; it has one marker and one qualified definition each for UID00014G, UID0004WT, UID0004WU, and UID00014J, zero empty markers for those four UIDs, four direct-reference call sites, and zero `&sectionNumber`/`&sectionOffset` invocation arguments. Its only such address-of text is the legitimate `DWORD &` declaration on the `GetLogicalAddress` definition. `auto-generated/NexusTK/platform/ExceptionHandler.h` is SHA256 `0CF1F1ACBF0AF1470516BFC32C340577A2C1C65BC53E6B1961E6E7D228575D30`, 2370 bytes, 76 lines; it contains one UID00004P marker, each of the six callback typedef declarations once, one complete class, one `ExceptionHandlerSizeMustBe0x828` assertion, one declaration for each method including exactly one `GetLogicalAddress` declaration, and no method definition. Source-channel topology is unchanged.
- Assignment-time documentation correctly recorded the single filter caller, exception/register output, ImageHlp/fallback paths, two `GetExceptionString` calls, and class/file placement.
- Assignment-time stale assumptions described client/current-directory output, `WriteCrashReport`, `InitializeImageHlp`, `WriteImageHlpStackWalk`, blank formals, and incidental `int` return. All remain preserved in dated history but are superseded in current ordinary docs by Windows-directory output, `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, `ImagehlpStackWalk`, exact formals, and `void` target return.
- Source-channel placement corrections remain applied: C14G-28/C14G-41 place the declaration package once in UID00004P H with UID00004P CPP blank, and every method-child H block remains blank. C14G-25/C14G-26/C14G-30/C14G-32/C14G-34/C14G-35/C14G-37/C14G-38/C14G-39/C14G-41/C14G-42/C14G-43 are now `APPLIED_VERIFIED`. C14G-33 manual coverage remains supervisor-only and pending.
- Current report artifact state: the authorized five-document callback and supervisor Gate 2B are complete. This reconciled report artifact now awaits fresh supervisor exact-artifact Gate 1/final continuity, supervisor `execute_report`, and supervisor manual coverage. B001 changed only the five authorized ordinary docs during implementation, ran only their five scoped validators, released all leases, and made no IDA, coverage, direct generated, audit, goal, supervisor, validator-state, or lifecycle change; the later IDA save and audit/catalog entries are supervisor-owned.
- Current persisted IDA result: exact four functions/prototypes/regular function comments, exact-created raw Intel helper `[0x004ac0f0,0x004ac221)`, target argument and six source locals, six legacy callback typedefs, the exact `0x828`/12-member `ExceptionHandler` UDT with callback types at `+0x10..+0x24`, seven bounded globals/types/names/comments, and the RGB565 regular comment are `APPLIED_VERIFIED`. WINAPI typedefs canonicalize in IDA as semantically exact `__stdcall`; every typedef exists once and has size 4. All protected/no-action entities and CC fences remained exact.

### Current Artifact Reconciliation

Validator-owned migration batch `17353` and the defect-bearing command-17440 artifacts remain historical. The `Gate 1 pre-callback` column below preserves the earlier source-channel audit; the `Current` column records the exact authorized five-document callback results. UID00004P remains the sole source-channel migration, while UID00014G/UID0004WU/UID00014J changed only their accepted call arguments and UID0002AS/UID0000TQ changed only by additive consumer documentation.

| Artifact | Gate 1 pre-callback SHA / bytes / lines | Current SHA / bytes / lines / last write | Narrow-callback classification | Current disposition |
| --- | --- | --- | --- | --- |
| UID0004WT `by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md` | `70E44E73159603D1B7B153BF93D322D2E0DA554EA71C44B28EF4F41BB04188A8` / 9496 / 153 | `3007C9CBB29D0E667731F85F01099FC5C2D97E112C072A617FE7F16B32B1C78E` / 9819 / 153 / `2026-07-24T21:08:01.5491708-04:00` | Prose-only blank-H explanation; formal channels unchanged. | CPP definition retained; H exact blank; validator `17381` passed. |
| UID0004WU `by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md` | `914ABF316F897DA9186A0512B6D5E4E1B3A835C809112ADD89FA0D6E6C967A41` / 9141 / 145 | `C5646EE510AD7AABD385F7C43C07431EF0904AC717BF90C491A7EACC3BBCD431` / 9455 / 145 / `2026-07-24T23:45:56.5262591-04:00` | One accepted direct-reference call correction; formal channels/topology otherwise unchanged. | CPP/H `APPLIED_VERIFIED`; validator `17466` passed, H exact blank. |
| UID00014D `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md` | `1C4250534B8053725310D6FB8A25322FCE32EB379CFA914CCAFDC8FF1F2218F5` / 43349 / 250 | same / 43349 / 250 / `2026-07-24T19:56:46.3825554-04:00` | No narrow-callback difference. | CPP/H both exact blank; preserved. |
| UID00014G `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md` | `A517E7212C394F15F1C494C03B71336868D0705D242C9BBEB1D3EB2385C13187` / 28592 / 268 | `F50638A0FACB0711E9A58F69596AE2CC77DC29F718EDF349D8DA3A6E3DEE7327` / 28916 / 269 / `2026-07-24T23:45:29.1127139-04:00` | One accepted direct-reference call correction; metadata/behavior/CPP-H route otherwise unchanged. | CPP/H `APPLIED_VERIFIED`; validator `17465` passed, H exact blank. |
| UID00014F `by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md` | `C3D960B31CBC11271BA1ECD48626BEFFEFC13F4AE6B2A791B0FD48FD21C91088` / 17022 / 187 | same / 17022 / 187 / `2026-07-24T19:56:46.4261215-04:00` | No narrow-callback difference. | File-static CPP definition and blank H preserved. |
| UID00014J `by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md` | `24FEA41F853B2AD9D84E3DF4A93FF45BCA12AFF21AB31D27234D118507F17C7E` / 18203 / 226 | `B18E0620B51153FEA4307857F1B580F137EB7B60B84410D38342BAF54E56214E` / 18519 / 227 / `2026-07-24T23:46:28.9212467-04:00` | Two accepted direct-reference call corrections; metadata/behavior/CPP-H route otherwise unchanged. | CPP/H `APPLIED_VERIFIED`; validator `17467` passed, H exact blank. |
| UID00004P `by-class/ExceptionHandler.md` | `D809130E71CB06A05C9EC5FE82B19F5ADBEE531FA0046D196B9030CAD4201ACE` / 31217 / 261 | `A2B25B6A93D46C750DD1E1C55B2A45A685162D30BC30D927C556194D734D3C62` / 31478 / 261 / `2026-07-24T21:07:07.9603161-04:00` | Substantive accepted source-channel migration plus current-status prose. | CPP exact blank; H has six typedefs, complete class, size assertion, and one `[[CHILDREN]]`; validator `17378` passed. |
| UID000259 `by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md` | `AEE358891C85393043E11D87B88BF289196D647B065851BACCD5F00EB1FB9B51` / 24336 / 149 | same / 24336 / 149 / `2026-07-24T19:57:27.4281992-04:00` | No narrow-callback difference. | CPP/H both exact blank; preserved. |
| UID0000J8 `by-file/ExceptionHandler.md` | `348DD3C8560ED44A0AF16BF2CB22816D1F51F360A05C6163F6305F7F9747F12C` / 27899 / 174 | same / 27899 / 174 / `2026-07-24T12:31:41.9485848-04:00` | No narrow-callback difference. | Source root preserved. |
| UID0001QB `by-meta/client_crash_diagnostics.md` | `2B4BCB03E7997EEFDBA0C359D8FF655455A217681F6D62EE791537C9C427BFDA` / 15492 / 80 | same / 15492 / 80 / `2026-07-24T12:34:20.3035746-04:00` | No narrow-callback difference. | Preserved. |
| UID0001R1 `by-project-structure/proposed-source-tree.md` | `7D780058F841B3DDA1CF8BC72ADC520F65CD4EA730B3B30ACC55EA1E475BE73D` / 310112 / 2113 | same / 310112 / 2113 / `2026-07-24T12:34:50.5784727-04:00` | No narrow-callback difference. | Preserved. |
| UID0002AS `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | `0490CEC619FF254B66909FFA44FBB9AB616F25E12C877AAFD19F3909D9DE1CCA` / 22304 / 139 | `5CBFFB535441C962F8191C0D3B9EFA13F2A442BC7DC9BE81A253707FBEEAE41F` / 23839 / 142 / `2026-07-24T23:47:22.1466698-04:00` | Added exact three-slot UID00014G consumer evidence/cross-reference/history only. | `APPLIED_VERIFIED`; validator `17468` passed; metadata/formal/owner unchanged. |
| UID0000TQ `by-global/WideApiDispatchTable.md` | `9578D79C8FF158BBF5724E9250E6EC5C7C04D3C148412BD027A1986CB53359F6` / 40162 / 272 | `38D5AE8F13771444C3F3784C2B7319F3C988834348923A6D8B8E7B543C9648CD` / 42081 / 276 / `2026-07-24T23:48:48.9364475-04:00` | Added exact three-slot UID00014G consumer rows/evidence/cross-reference/history only. | `APPLIED_VERIFIED`; validator `17469` passed; metadata/formal/owner unchanged. |
| Generated `auto-generated/NexusTK/platform/ExceptionHandler.cpp` | command `17440`, `17113BF8C32182274A1BE6C9AD07C4E631208C837B1D2EE1960E11C04D3058ED` / 18715 / 533 defect-bearing historical checkpoint; repaired callback checkpoint `17467`, `23BAE697356D8C6CA5B9A54F1B34D8DB4C5697E02BDDE4116D5E4433448EC798` / 18705 / 533 | physical header command `17510`, refreshed `2026-07-25T04:52:56-04:00`; `0F2CAD462252019F0A6EA5A1C18C2452D1530BB3A76DA4C9665FA82BB6D7D2D2` / 18707 / 533 | Current validator-generated output preserving the three call-bearing corrections. | One marker/qualified definition each for UID00014G/UID0004WT/UID0004WU/UID00014J; zero target/helper empty markers; four direct-reference calls; zero invalid invocation address-of tokens. |
| Generated `auto-generated/NexusTK/platform/ExceptionHandler.h` | command `17440`, `A21D7F6EE89F722BD747A76857074F855A3699870A5FC3EBD692313B2A69B7CB` / 2370 / 76 historical checkpoint; repaired callback checkpoint `17467`, `E9E89AEA157D40F35BDFB7A8F4B000A2F22D82E1C52DE458D1A264746BC13881` / 2368 / 76 | physical header command `17510`, refreshed `2026-07-25T04:52:56-04:00`; `0CF1F1ACBF0AF1470516BFC32C340577A2C1C65BC53E6B1961E6E7D228575D30` / 2370 / 76 | Current validator-generated sibling; source-channel package retained. | One UID00004P marker/package, six typedefs, one class, one size assertion, one declaration per method including exactly one `GetLogicalAddress` declaration, and zero method definitions. |

- Formal-channel readback: UID00004P CPP has zero content lines and H has 69 content lines with one `[[CHILDREN]]`; UID00014G/UID0004WT/UID0004WU/UID00014J CPP blocks retain 106/53/50/98 content lines and each H has zero content lines; UID00014D and UID000259 each have zero CPP and zero H content lines. Current generated command `17510` proves both topology and corrected call semantics for the four emitted method definitions; command `17467` remains the earlier repaired callback checkpoint.
- The authorized callback changed only four call arguments in three method bodies and additive consumer prose in two PlatformApi support pages. No unrelated behavior, source channel, score, owner/emitter route, declaration package, or historical evidence changed.

## Executive Recommendation

- Use `void ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *pExceptionInfo)` as the human source declaration and definition. The `__thiscall` receiver, one `EXCEPTION_POINTERS *` stack argument, sole class-family caller, and exact source lineage agree.
- Keep the exact target range and current owner/emitter route. Do not split the target body merely because the compiler inlined `InitImagehlpFunctions` and `IntelStackWalk` into it.
- Treat retained ranges `0x004ac040-0x004ac0ed`, `0x004ac0f0-0x004ac221`, and UID00014J `0x004ac230-0x004ac4cb` as source helper definitions `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk`. Their retained out-of-line copies plus the exact MSJ source explain the target's inline duplicates.
- Emit only `GenerateExceptionReport` from UID00014G. Do not paste the resolver or fallback loop as separate handwritten nested bodies in the target source; ordinary source calls to the helpers best explain both the inline target code and retained copies.
- Preserve Nexus-specific behavior rather than reverting to the public ancestor, especially `GetWindowsDirectoryW`, the duplicate `GetExceptionString` call, ANSI conversions, timing/phase/RGB565 line, no `FreeLibrary`, and unconditional separator write.

## Supervisor Active Recheck

- Trigger: the supervisor assigned UID00014G as a not-covered reconstructable by-memory item with an empty emitter and required exhaustive report-only research.
- Split repair before the master report: no target split is required. The exact function is one coherent source method. Three neighboring helper definitions are separate source methods and must remain separate from UID00014G emission.
- Source-bearing children: UID00014G is source-ready in this report. Existing UID00014H/UID00014I are already source-ready. UID00014J and retained helper ranges receive exact source identities/prototypes and support recommendations without being declared as additional report targets.
- No unresolved target blocker is deferred. Remaining uncertainty is limited to exact lost Nexus spelling where a coherent project/source-family choice is already selected.

## Inference Research Guidance Check

- IDA facts, current documentation, public source-family evidence, and inference are separated throughout this report.
- Exact binary behavior outranks the ancestor source when they differ. The ancestor source is strongest for source names, class membership, helper decomposition, and era-appropriate shape.
- Existing documentation assumptions were treated as uncertain where they used `WriteCrashReport`, current-directory wording, generic `InitializeImageHlp`, raw callback-pointer types, or decompiler return/local names.
- Generated C++ was used only to identify the empty marker and current declaration mismatch; it was not treated as binary proof.
- Wave2/Wave3 mentions found in older project documentation were ignored as stale and were not used as evidence.

## Heuristic / Inference Reanalysis And Validation

- Method identity: source-family match plus exact behavior selects `GenerateExceptionReport`, not `WriteCrashReport`, `WriteExceptionReport`, or a file-static writer. The name is source-lineage-backed; the enclosing class adaptation from `MSJExceptionHandler` to project `ExceptionHandler` is binary/documentation-backed.
- Return type: public ancestor source is `void`; the only caller ignores EAX; the binary's final EAX is incidental residue from `fputs`/`fclose`. `int` is rejected as a decompiler artifact.
- Parameter: `EXCEPTION_POINTERS *pExceptionInfo` is proved by reads of `[arg]+0` as `ExceptionRecord` and `[arg]+4` as `ContextRecord`; `unsigned int *` is rejected.
- Report directory: `0x0069be7c` has initializer and five xrefs and maps to `GetWindowsDirectoryW`, while `GetCurrentDirectoryW` is the distinct `0x0069be70` slot. The previous client/current-directory statement is rejected.
- Local arrays: `Buffer` is `wchar_t reportPath[MAX_PATH]`; `ArgList` is `wchar_t windowsDirectory[MAX_PATH]`, despite IDA's byte-array presentation; `MultiByteStr` is a lifetime-reused `char ansiText[1024]`; `String2` is `wchar_t executablePath[MAX_PATH]`; `WideCharStr` is `wchar_t faultingModule[MAX_PATH]`; `String1` is fallback `wchar_t moduleName[MAX_PATH]`.
- Helper decomposition: exact MSJ source names, retained out-of-line copies, and target inline semantic copies establish source calls to `InitImagehlpFunctions` and `IntelStackWalk`. Hand-authoring both inline bodies inside `GenerateExceptionReport` is rejected as compiler-shaped source.
- ImageHlp callback types: exact GetProcAddress names and use sites resolve six legacy 32-bit signatures. `void *` fields are documentation/IDA type gaps, not source declarations.
- ImageHlp ownership: callback pointers at `this+0x10..+0x24` and member helper receivers prove class fields. Static process globals and a standalone ImageHlp utility are rejected.
- C++ reference binding: UID00014I declares `GetLogicalAddress(..., DWORD &sectionNumber, DWORD &sectionOffset)`, so each source call passes `sectionNumber, sectionOffset` directly. Passing `&sectionNumber, &sectionOffset` is a decompiler-to-source conversion error, not a binary behavior choice; the corrected report formals remove it while preserving the same callee ABI.
- Failure behavior: unlike the ancestor source, Nexus does not free the loaded module on partial resolution failure. Adding `FreeLibrary` would change runtime side effects and is rejected.
- Null stream: the final separator `fputs` is outside the stream test. Moving it under `if (pReportFile)` would improve safety but fail behavioral fidelity; the latent null-stream fault is intentionally retained.
- Exception text: the first `GetExceptionString` result is discarded and the second is converted. Removing the first call would change fallback-buffer/API behavior and is rejected.
- Logical-address output: the first call receives uninitialized section/module outputs and ignores failure; the fallback helper initializes its own outputs. Defensive initialization in the target source would alter failure behavior and is rejected.
- Source placement: all callers, fields, helpers, literals, vtable, and public ancestor structure converge on `platform/ExceptionHandler.cpp`; `Application.cpp`, `Error.cpp`, `Crasher.cpp`, and a new `CrashReport.cpp` are weaker.
- Naming style: exact ancestor method spellings are retained where available; project-established `m_*` and `g_*` names remain for Nexus-specific fields/globals. This prioritizes behavior and human source shape over forced cosmetic uniformity.
- Score blockers: every named/type/source/return/slot/helper blocker was actively researched. The remaining cap is absence of Nexus PDB/source and rebuild byte-comparison, not an unattempted question.

## Evidence Standards Used

- Direct IDA MCP: health, function lookup, decompile, component analysis, CFG, caller/callee/xrefs, raw bytes, item boundaries, stack frame, type inspection, current comments, names/collision search, literals, imports, and global reads.
- Binary evidence: exact bytes/hashes, call ABI, stack cleanup, object offsets, output formats, control flow, side-effect order, and adjacent padding/function boundaries.
- Documentation evidence: current by-memory/class/file/global/meta/source-tree pages, generated output, manual coverage rows, and selected executed reports.
- Source-family evidence: exact public MSJ source names and decomposition, accepted only where Nexus binary semantics corroborate the relationship.
- Negative evidence: zero helper-start xrefs, no source-name collisions, no separate owner/caller cluster, no import-table ImageHlp linkage, no `FreeLibrary`, and no target split boundary.
- Evidence strength: strong enough for corrected and `APPLIED_VERIFIED` ordinary/generated source plus an implementation-ready supervisor IDA handoff. Confidence remains below certainty because exact Nexus-local spellings and a compiler/rebuild match are unavailable.

## Evidence Checked

- MCP calls: `server_health`, `analyze_batch(0x004ab870)`, `decompile` for `0x004ab830`, `0x004ac040`, and `0x004ac230`, `analyze_component`, `disasm`, `lookup_funcs`, `xrefs_to`, `inspect_items`, `stack_frame`, `type_inspect(ExceptionHandler)`, `get_comments`, `entity_query`, and `get_bytes`.
- Raw checks: target 1184-byte hash; predecessor byte; successor prefix; retained helper/padding boundaries; helper byte hashes; literal item boundaries; import entries; global slots.
- Current docs: UID00014D/14F/14G/14H/14I/14J/259/2GP/2JX/2JZ/2AR/28Z/29U/294/2AS, class UID00004P, file UID0000J8, global UID0000TQ, meta UID0001QB, and proposed source tree UID0001R1.
- Generated/manual checks: `auto-generated/NexusTK/platform/ExceptionHandler.cpp` and manual by-memory/by-class/by-file/by-global coverage rows.
- Archived report searches: `00014G`, `0x004ab870`, `ExceptionCrashReportWriter`, `WriteCrashReport`, `GenerateExceptionReport`, and `ExceptionHandler` family terms.
- External source checks: MSJ source mirror and article mirror. No original Nexus source, PDB, or map was found or claimed.
- Negative checks: no collision for `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, `ImagehlpStackWalk`, or proposed Nexus-specific global names; zero xrefs to retained starts `0x004ac040` and `0x004ac0f0`; exactly one target xref to `0x004ac230`.
- Failed/skipped: decompilation of raw `0x004ac0f0` is unavailable because IDA has no function record; bytes/manual listing and exact source/inline duplicate were used instead. No mutating MCP tool was called.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C14G-01 | 00014G | Exact half-open range is `[0x004ab870,0x004abd10)`, 1184 bytes, target SHA256 `B6A47AE...99D7`. | exact | MCP bytes/function/CFG | UID00014G Evidence/Boundaries | applied | APPLIED_VERIFIED |
| C14G-02 | 00014G | Sole direct caller is `TopLevelExceptionFilter` call site `0x004ab858`. | exact | callers/xrefs | UID00014G Caller Map | applied | APPLIED_VERIFIED |
| C14G-03 | 00014G | Source identity is `ExceptionHandler::GenerateExceptionReport`. | very strong | exact MSJ lineage plus member ABI/behavior | UID00014G Status/Source Identity | applied | APPLIED_VERIFIED |
| C14G-04 | 00014G | Source return is `void`; parameter is `EXCEPTION_POINTERS *pExceptionInfo`. | very strong | lineage, caller, field reads, `ret 4` | UID00014G ABI | applied | APPLIED_VERIFIED |
| C14G-05 | 00014G | Report path is `<Windows directory>\BCrash.nfo`, not current/client directory. | exact | slot `0x69be7c`, table map, xrefs, call order | UID00014G Behavior/Historical Corrections | applied | APPLIED_VERIFIED |
| C14G-06 | 00014G | Report opens via `g_pfnWideOpenFile(reportPath,L"wt")`. | exact | call slot `0x69be14`, literals | UID00014G Behavior | applied | APPLIED_VERIFIED |
| C14G-07 | 00014G | Version line is `%d.%d.Eng.R\n` from `g_pApplication->GetVersionMajor()` and `GetExecutableVersionLowWord()`. | exact/source-ready | decompile and support docs | UID00014G Output Inventory | applied | APPLIED_VERIFIED |
| C14G-08 | 00014G | Fault resolution calls private static `GetLogicalAddress` and ignores its Boolean result with uninitialized first-call outputs. | exact | decompile/UID00014I | UID00014G Failure Contract | applied | APPLIED_VERIFIED |
| C14G-09 | 00014G | `GetExceptionString` is called twice; first result discarded, second converted. | exact | calls `0x4ab951/0x4ab968` | UID00014G Exception Flow | applied | APPLIED_VERIFIED |
| C14G-10 | 00014G | Exception/module wide text converts through `WideCharToMultiByte(CP_ACP)` into a 1024-byte buffer; return values are ignored. | exact | decompile/import | UID00014G Conversion Contract | applied | APPLIED_VERIFIED |
| C14G-11 | 00014G | Exact register and segment output maps x86 `CONTEXT` offsets through EFlags. | exact | disassembly/decompile | UID00014G Register Map | applied | APPLIED_VERIFIED |
| C14G-12 | 00014G | Diagnostic state is current tick minus baseline tick, application phase, and RGB565 flag. | exact/source-ready | dword/byte reads and support docs | UID00014G Global Inputs | applied | APPLIED_VERIFIED |
| C14G-13 | 00014G | Resolver loads `IMAGEHLP.DLL` through `g_pfnLoadLibraryW` and resolves six required exports plus optional `SymSetOptions`. | exact | calls/literals/member stores | UID00014G ImageHlp Flow | applied | APPLIED_VERIFIED |
| C14G-14 | 00014G | Resolver stores callbacks at `this+0x10..+0x24` using six exact legacy typedefs. | exact | decompile/type layout | UID00014G/Class UID00004P | applied | APPLIED_VERIFIED |
| C14G-15 | 00014G | Nexus does not call `FreeLibrary` on partial resolution failure. | exact negative | complete callee/disassembly check | UID00014G Historical Difference | applied | APPLIED_VERIFIED |
| C14G-16 | 00014G | Successful setup calls `ImagehlpStackWalk`, then `m_symCleanup(GetCurrentProcess())`. | exact | call/member flow | UID00014G Behavior | applied | APPLIED_VERIFIED |
| C14G-17 | 00014G | Failed setup/initialization uses `IntelStackWalk`; the target contains an inline semantic copy of retained helper `0x004ac0f0`. | very strong | target/raw bytes/source lineage/zero xrefs | UID00014G Source Shape | applied | APPLIED_VERIFIED |
| C14G-18 | 00014G | Final separator `fputs` is unconditional even when stream is null; flush/close remain conditional. | exact | terminal CFG | UID00014G Failure Contract/Formal | applied | APPLIED_VERIFIED |
| C14G-19 | 00014G | Stack locals map to reportPath, windowsDirectory, ansiText, executablePath, faultingModule, and moduleName arrays. | very strong | stack frame plus data flow | UID00014G Local Layout | applied | APPLIED_VERIFIED |
| C14G-20 | 00014G | `var_C30/var_C2C/var_C28` are lifetime-coalesced and unsafe to force into one source name. | strong | frame/decompile reuse | UID00014G IDA/Historical | applied | APPLIED_VERIFIED |
| C14G-21 | 00014G | `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk` are exact source-family helper identities. | very strong | source lineage and binary matches | UID00014D/04P/0J8/14J | applied | APPLIED_VERIFIED |
| C14G-22 | 00014G | Target source calls helpers; compiler inlining explains target duplicate bodies and retained zero-xref copies. | very strong | source decomposition/xrefs/semantic duplicates | UID00014G Source Shape | applied | APPLIED_VERIFIED |
| C14G-23 | 00014G | Source placement remains `NexusTK/platform/ExceptionHandler.cpp`. | very strong | class fields/callers/source tree | UID00014G/0000J8/0001R1 | applied | APPLIED_VERIFIED |
| C14G-24 | 00014G | Owner/emitter route remains UID00014D; no duplicate class/file target emission. | exact project structure | metadata/aggregate/class/file | UID00014G Metadata | applied | APPLIED_VERIFIED |
| C14G-25 | 00014G | Formal source must emit exactly one `GenerateExceptionReport` definition through UID00014G CPP with exact Nexus behavior; UID00014G H remains exactly blank because the declaration belongs once in UID00004P H. | very strong | complete evidence synthesis plus separate CPP/H channel policy | UID00014G CPP/H formals | applied | `APPLIED_VERIFIED`; direct-reference call installed, validator `17465`, SHA `F50638A0...E7327`, current generated command `17510`; exact blank H retained |
| C14G-26 | 00014G | Recommended target score is `94/96` after the corrected formal is applied and verified. | strong | all source/formal blockers closed; residual no-PDB/rebuild cap | UID00014G metadata/formal | applied | `APPLIED_VERIFIED`; metadata/formal pair and generated body read back together |
| C14G-27 | 00014G | Parent aggregate should historicalize raw helper-name uncertainty and record exact helper identities. | strong | support audit | UID00014D | applied | APPLIED_VERIFIED |
| C14G-28 | 00014G | UID00004P H must contain the six exact callback typedefs, complete `ExceptionHandler` declaration using `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk`, size assertion, and `[[CHILDREN]]`; UID00004P CPP must be exact blank because no separate class-level implementation belongs there. | very strong | source lineage/member layout plus separate CPP/H channel policy | UID00004P CPP/H formals | applied | `APPLIED_VERIFIED`; validator `17378`, current ordinary SHA `A2B25B6A...D3C62`, current generated H command `17510` SHA `0CF1F1AC...575D30` (`17384` first split checkpoint; `17440` defect-bearing historical; `17467` repaired callback checkpoint) |
| C14G-29 | 00014G | Top-level filter must call `GenerateExceptionReport`, not `WriteCrashReport`. | very strong | source identity and sole call | UID00014F | applied | APPLIED_VERIFIED |
| C14G-30 | 00014G | File/meta/source-tree docs must synchronize method/helper names and Windows-directory behavior, and UID0002AS/UID0000TQ must add report-level UID00014G consumer detail for `_wfopen` slot `0x0069be14`, `LoadLibraryW` slot `0x0069be30`, and `GetWindowsDirectoryW` slot `0x0069be7c`. | strong | documentation audit and exact support-page readback | UID0000J8/0001QB/0001R1 plus UID0002AS/UID0000TQ | applied | `APPLIED_VERIFIED`: prior file/meta/tree package retained; UID0002AS validator `17468` SHA `5CBFFB53...EAE41F`; UID0000TQ validator `17469` SHA `38D5AE8F...648CD` |
| C14G-31 | 00014G | Existing UID00014J should be named `ExceptionHandler::ImagehlpStackWalk(CONTEXT *, FILE *)`. | very strong | source lineage and exact binary ABI | UID00014J | applied | APPLIED_VERIFIED |
| C14G-32 | 00014G | Generated CPP must contain one UID00014G qualified body and no UID00014G empty marker; generated H must contain the single UID00004P declaration package without duplicating method definitions; all four calls must match the C++ reference declaration. | exact expected effect | emitter route and separate CPP/H assembly | generated readback | applied | `APPLIED_VERIFIED`; current command `17510`, CPP SHA `0F2CAD46...D7D2D2` has one definition each, four direct-reference calls, zero target/helper empty markers, and zero invalid invocation tokens; H SHA `0CF1F1AC...575D30` retains one declaration package, exactly one `GetLogicalAddress` declaration, and no definitions |
| C14G-33 | 00014G | Existing manual coverage rows must be replaced with the exact payloads in this report, while new UID0004WT and UID0004WU rows must be inserted in address order after current UID00014I and before current UID00014J. | exact documentation state | current manual rows/order | by-memory and support coverage | supervisor-only | pending |
| C14G-34 | 00014G | Supervisor Gate 2B applied/verified the exact function/local/UDT/global action set without touching protected neighbors, then saved and read back the IDB. | exact workflow/result | current prestate tables plus persisted supervisor readback | supervisor Gate 2B | supervisor-applied | APPLIED_VERIFIED; post-save SHA `3EB64AC3...A1AD79D` |
| C14G-35 | 00014G | Every Gate 2B prestate was re-read through authoritative database `f085b224` against bounded saved-IDB observation SHA256 `2C20AAD81BC18DE1FA91B04D7FBEC30A704D377E6E2A2E35344C06EAEE479BC0`, size `143186196`; verified backup `NexusTK.exe.i64.pre-00014G-20260725_230500.bak` preceded mutation. Supervisor save/readback stabilized at SHA256 `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`, size `143186768`, last write `2026-07-25T23:14:42.2666509-04:00`; 7509/9DF/CB62/9F6E/B6A2/48EB/D99/EF0/F28/6A and older observations remain historical checkpoints only. | exact | stable prestate, verified backup, complete item-by-item apply/protect/readback, `idb_save ok`, stable post-save hash | IDA Recommendations / Gate 2B result | supervisor-applied | APPLIED_VERIFIED |
| C14G-36 | 00014G | Raw Intel helper is exact code `[0x004ac0f0,0x004ac221)`: 89 instructions, first `55`/`push ebp`, terminal `C2 08 00`/`retn 8` at `0x004ac21e`, zero start xrefs, no function record, followed by one 15-byte all-`CC` item. | exact | `insn_query`, `inspect_items`, `get_bytes`, `xrefs_to`, `lookup_funcs`, `get_comments` | UID00014D and UID0004WU Evidence/Boundaries | applied | APPLIED_VERIFIED |
| C14G-37 | 0004WT | Exact child `by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md`, `94/94`, owner/emitter UID00004P, reconstructable true, with destination-ready `InitImagehlpFunctions` definition in CPP and exact blank H because UID00004P H owns the declaration. | very strong | exact decompile/bytes/source lineage/zero-xref retained-definition evidence plus separate CPP/H policy | UID0004WT plus UID00014D/class/file links | CPP applied; H mechanically present/blank | CPP `APPLIED_VERIFIED`; exact blank H `CURRENT_VERIFIED` |
| C14G-38 | 0004WU | Exact child `by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md`, `94/94`, owner/emitter UID00004P, reconstructable true, with corrected `IntelStackWalk` definition in CPP and exact blank H because UID00004P H owns the declaration. | very strong | exact 89-instruction listing/source lineage/inline duplicate plus separate CPP/H policy | UID0004WU plus UID00014D/class/file links | applied | `APPLIED_VERIFIED`; validator `17466`, SHA `C5646EE5...D431`, one direct-reference call, blank H retained |
| C14G-39 | 00014J | UID00014J is recommended `94/94` with the corrected `ImagehlpStackWalk` definition in CPP and exact blank H because UID00004P H owns the declaration; exact one caller, callback fields, formats, reset asymmetry, and five-byte pad are preserved. | very strong | exact decompile/caller/bytes/source lineage plus separate CPP/H policy | UID00014J formal/behavior/evidence | applied | `APPLIED_VERIFIED`; validator `17467`, SHA `B18E0620...214E`, two direct-reference calls, blank H retained |
| C14G-40 | 00014D | Aggregate routing links UID0004WT, UID0004WU, and UID00014J, preserves all three padding items as parent-only, and keeps aggregate formal blank/child-only to prevent duplicate emission. | exact structure | by-structure rules plus exact range map | UID00014D Covered Range/Children/Source Shape | applied | APPLIED_VERIFIED |
| C14G-41 | 00004P | The six typedefs, complete class declaration, size assertion, and `[[CHILDREN]]` must exist once in UID00004P H while UID00004P CPP is exact blank; method definitions remain once in the four child CPP channels, and all four child H channels remain blank to prevent duplicate declarations. | exact project structure | owner/emitter graph, separate CPP/H assembly, and generator policy | UID00004P/UID0000J8/UID00014G/UID0004WT/UID0004WU/UID00014J | applied | `APPLIED_VERIFIED`; current generated command `17510` proves one package, four definitions, exact blank child H channels, and no duplicated declarations/bodies |
| C14G-42 | 00014G | All three source-ready helper identities/bodies/splits are closed in research and implementation. The only target `94/96` caps are no original Nexus PDB/source/map and no rebuilt-binary comparison. | strong | complete corrected helper formals, exact split plan, scoped validators, generated readback | Score/Open Questions/Final Recommendation | applied | `APPLIED_VERIFIED`; no ordinary source-quality blocker remains |
| C14G-43 | 00014G | MultiByteStr Gate 2B action was deterministic rename-only to `ansiText`; current `CHAR` type/504-byte represented extent and all neighbor offsets remained unchanged on persisted readback. | exact safe action/result | revision-bound stack frame, source lifetime analysis, and persisted readback | Gate 2B local action/readback | supervisor-applied | APPLIED_VERIFIED |

## Positive Evidence Summary

- The target is a complete modeled function with exact boundaries, strong internal structure, one class-family caller, and no mixed-owner tail.
- Public source lineage matches the unusual method/helper sequence, exception text mapping, logical-address walk, x86 fallback, dynamic ImageHlp resolution, and function-pointer family.
- Nexus-specific differences are visible directly in the binary and can be retained without decompiler labels.
- Retained helper copies plus inline target semantics explain optimization while preserving ordinary source helper calls.
- Class layout, callback fields, globals, literals, and generated source route all agree on `ExceptionHandler.cpp`.
- No competing name collision or source owner was found.

## IDA MCP Facts

- Function: current `sub_4AB870`, prototype `int __thiscall(_DWORD *this, unsigned int *)`, exact size `0x4a0`, 327 instructions, 31 basic blocks, cyclomatic complexity 21.
- Caller: one code xref from `0x004ab858` in `TopLevelExceptionFilter`.
- Direct callees: `unk_69BE7C`, `GetProcAddress`, `ExceptionHandler_GetExceptionString`, `sub_4651F0`, `sub_41B9B0`, `_fputs`, security-cookie check, `_wcsicmp`, `IsBadWritePtr`, `GetCurrentProcess`, `sub_443990`, `ExceptionHandler_GetLogicalAddress`, `sub_465300`, `unk_69BE30`, `_fclose`, `WideCharToMultiByte`, `sub_4AC230`, slot `0x69be14`, and `_fflush`.
- Predecessor boundary: one byte `0xCC` at `0x004ab86f`; successor starts at `0x004abd10` as `ExceptionHandler_GetExceptionString`, size `0x13a`.
- Retained resolver: `sub_4AC040`, `[0x004ac040,0x004ac0ed)`, size `0xad`, 12 blocks, complexity 9, zero xrefs, followed by three `0xCC` bytes.
- Retained Intel fallback: code `[0x004ac0f0,0x004ac221)`, no function record/name/type, zero start xrefs, `ret 8`, followed by 15 `0xCC` bytes.
- ImageHlp helper: `sub_4AC230`, `[0x004ac230,0x004ac4cb)`, size `0x29b`, 18 blocks, complexity 11, one caller at target `0x004abbb8`, followed by five `0xCC` bytes.
- `ExceptionHandler` UDT size is `0x828`; callback members at `+0x10..+0x24` are currently six `void *` fields.
- Global xref counts: `0x0067ab1c` 140, `0x0069be14` 41, `0x0069be30` 8, `0x0069be7c` 5, `0x0069be0c` 2, `0x0069be10` 4, `0x0067a938` 5, `0x0069b3d5` 16.
- Historical Gate 2B prestate delta in `f085b224`: the five previously reconciled one-byte heads at `0x0069be30`, `0x0069be7c`, `0x0069be0c`, `0x0069be10`, and `0x0067a938` had default display names with no explicit name-index entries; `0x0067ab1c` was a one-byte `unk_67AB1C` head typed `LObject *` plus three tails; protected `0x0067ab20` and `0x0067a93c` were fragmented one-byte groups; and `0x0069b3d5` had no comment. Supervisor Gate 2B used those exact prestates, preserved both protected fragmented spans, created/retyped/renamed only the bounded actionable slots, and restored the accepted RGB565 regular comment. Persisted post-save readback passed.
- Current IDA result: `ExceptionHandler__GenerateExceptionReport`, `ExceptionHandler__InitImagehlpFunctions`, exact-created `ExceptionHandler__IntelStackWalk` at `[0x004ac0f0,0x004ac221)`, and `ExceptionHandler__ImagehlpStackWalk` have exact accepted prototypes and regular function comments. The target argument and six source locals have accepted names/types, the six callback typedefs each exist once at size 4 with semantically exact IDA `__stdcall` rendering, the `ExceptionHandler` UDT remains exactly `0x828` with 12 members and typed callbacks at `+0x10..+0x24`, seven bounded globals are normalized, and the RGB565 comment is present.
- Current persisted comment state: the four actionable functions have their exact accepted regular function comments; their repeatable function comments and entry regular/repeatable channels remain absent as required. Existing exact protected function comments at UID00014H and UID00014I remain unchanged, and all other protected function comment channels remain exact.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Assignment baseline -> recommendation | Current report-aware status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ab830-0x004ab86f` | UID00014F | file-static top-level filter | true | UID00014D | 88/91 -> 90/94 | `APPLIED_VERIFIED`; exact `GenerateExceptionReport` call identity and complete formal preserved. |
| `0x004ab86f-0x004ab870` | parent-only | alignment | no source emission | UID00014D | n/a | one `0xCC` |
| `0x004ab870-0x004abd10` | UID00014G | `GenerateExceptionReport` | true | UID00014D | 86/91 -> current 94/96 | Routing/evidence retained; corrected formal is installed and `APPLIED_VERIFIED` by validator `17465` plus current generated command `17510`. |
| `0x004abd10-0x004abe4a` | UID00014H | `GetExceptionString` | true | UID00004P | 92/94 | source-ready, protected |
| `0x004abe4a-0x004abf9c` | parent-only | switch/table island | compiler data | UID00014D | n/a | no handwritten array |
| `0x004abfa0-0x004ac035` | UID00014I | `GetLogicalAddress` | true | UID00004P | 92/94 | source-ready, protected |
| `0x004ac040-0x004ac0ed` | UID0004WT `by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md` | `InitImagehlpFunctions` retained definition | true | UID00004P | new 94/94 child | `APPLIED_VERIFIED`; exact body, split, route, padding exclusion, formal, and zero-xref/inlined-copy disposition validated. |
| `0x004ac0ed-0x004ac0f0` | parent-only | alignment | no source emission | UID00014D | n/a | three `0xCC` |
| `0x004ac0f0-0x004ac221` | UID0004WU `by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md` | `IntelStackWalk` retained definition | true | UID00004P | current 94/94 child | Exact 89-instruction evidence/split/route/padding remain valid; corrected ordinary CPP is `APPLIED_VERIFIED` by validator `17466`. |
| `0x004ac221-0x004ac230` | parent-only | alignment | no source emission | UID00014D | n/a | fifteen `0xCC` |
| `0x004ac230-0x004ac4cb` | UID00014J | `ImagehlpStackWalk` | true | UID00004P | 86/91 -> current 94/94 | Exact behavior/caller/fields/asymmetry/padding remain valid; corrected ordinary CPP is `APPLIED_VERIFIED` by validator `17467`. |
| `0x004ac4cb-0x004ac4d0` | parent-only | alignment | no source emission | UID00014D | n/a | five `0xCC` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ab858` | `TopLevelExceptionFilter -> sub_4AB870` | sole target caller and member receiver proof |
| `0x004ab89d` | call slot `0x0069be7c` | `GetWindowsDirectoryW`, not current directory |
| `0x004ab8d7` | call slot `0x0069be14` | `_wfopen`-compatible wide report open |
| `0x004ab8e6` | `sub_465300` | `Application::GetVersionMajor` |
| `0x004ab8f4` | `sub_465320` | executable version low word |
| `0x004ab939` | `GetLogicalAddress` | fault address/module/section/offset; result ignored |
| `0x004ab951` | `GetExceptionString` | first result deliberately discarded |
| `0x004ab968` | `GetExceptionString` | second result converted and printed |
| `0x004ab9aa`, `0x004aba04` | `WideCharToMultiByte` | ANSI exception/module report text |
| `0x004abaf8` | slot `0x0069be30` | `LoadLibraryW(L"IMAGEHLP.DLL")` |
| `0x004abb0e..0x004abb8c` | `GetProcAddress` | six required and one optional ImageHlp exports |
| `0x004abbb8` | `sub_4AC230` | `ImagehlpStackWalk` success path |
| `0x004abbd0..0x004abcd6` | inline fallback | semantic copy of `IntelStackWalk` |
| `0x004abce2` | `_fputs` | unconditional separator write |
| `0x004ac040` | zero incoming xrefs | retained `InitImagehlpFunctions`, target has inline copy |
| `0x004ac0f0` | zero incoming xrefs | retained `IntelStackWalk`, target has inline copy |
| `0x004ac230` | one incoming xref | out-of-line `ImagehlpStackWalk` call |

## Documentation Evidence And IDA Status

- UID00014D correctly owns the aggregate and enumerates the retained helper ranges. Its assignment-time stale helper names/raw uncertainty are historical; current `90/94` content and exact UID0004WT/UID0004WU/UID00014J routing remain applied, while the call-level fixes live only in the affected child CPP pages.
- UID00014F formal called `WriteCrashReport` at assignment time. Current `90/94` content and exact `GenerateExceptionReport` call identity are `APPLIED_VERIFIED`.
- UID00014H/UID00014I already use exact source names and have complete formals; they require no target-driven body changes.
- UID00014J had exact binary behavior but a descriptive title/source identity at assignment time. Its current metadata, one caller, behavior, five-byte pad, corrected `ImagehlpStackWalk` CPP, and blank H disposition are now destination-readback verified.
- UID00004P content now uses `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk` with six exact callback typedefs, and the `0x828` layout remains preserved. Narrow-callback readback is `APPLIED_VERIFIED`: CPP is exact blank and H contains the existing six typedefs, complete class declaration, exact size assertion, and `[[CHILDREN]]` exactly once. No method-child H block duplicates those declarations.
- UID0000J8 placement remains correct and now records exact private spellings, retained-helper liveness/inlining, and exact child routes; callback readback is `APPLIED_VERIFIED`.
- UID0000TQ/UID0002AS now identify UID00014G as the exact consumer of `_wfopen` at `0x0069be14`, `LoadLibraryW` at `0x0069be30`, and `GetWindowsDirectoryW` at `0x0069be7c`, including call addresses, operands, report-path/open behavior, and the explicit consumer-only ownership boundary.
- Generated `ExceptionHandler.cpp` had one UID00014G empty marker and no body at assignment time. Historical command `17338` first cleared that state, command `17367` still carried declarations in CPP, command `17384` first proved the corrected channel split, command `17440` exposed the now-repaired reference-call defect, and command `17467` captured the repaired callback checkpoint. Current command `17510` CPP SHA `0F2CAD462252019F0A6EA5A1C18C2452D1530BB3A76DA4C9665FA82BB6D7D2D2` contains exactly one definition each for UID00014G/UID0004WT/UID0004WU/UID00014J, four direct-reference calls, and zero target/helper empty markers or invalid invocation tokens. Current H SHA `0CF1F1ACBF0AF1470516BFC32C340577A2C1C65BC53E6B1961E6E7D228575D30` contains the UID00004P declaration package once, exactly one `GetLogicalAddress` declaration, and no method definitions. C14G-28/C14G-32/C14G-41 are `APPLIED_VERIFIED`.
- Current IDA authority is the supervisor-persisted post-save checkpoint recorded in C14G-35: SHA256 `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`, size `143186768`, last write `2026-07-25T23:14:42.2666509-04:00`. The 2C20 tables below remain the exact prestate/action/expected-readback audit trail. Supervisor readback verified every actionable entity plus fragmented `0x0067ab20`/`0x0067a93c`, PlatformApi neighbors, six protected functions, nine imports, all protected locals/UDT members, zero bytes/xref totals, and the 3/15/5-byte `CC` fences. B001 made no IDA mutation; Gate 2B changes were supervisor-owned.

## Ranked Ownership Analysis

### 1. ExceptionHandler in platform/ExceptionHandler.cpp

- Evidence for: `__thiscall` receiver; callback fields at object offsets; sole file-static filter caller using `g_pCrashTarget`; exact source-family class; shared literals and adjacent helpers; class/file/aggregate routes; generated destination.
- Evidence against: exact Nexus local spellings are not symbol-proven.
- Decision: accepted with very strong confidence.

### 2. Separate CrashReport.cpp or CrashDiagnostics.cpp

- Evidence for: report writing is a coherent concern.
- Evidence against: no independent global, initializer, caller cluster, source path, or cross-class API; all helper fields and calls are class-local and exact source lineage keeps them in the class implementation.
- Decision: rejected.

### 3. Application.cpp, Error.cpp, or Crasher.cpp

- Evidence for: Application owns lifecycle construction; Crasher suppresses expected reports; Error is adjacent conceptually.
- Evidence against: all are consumers/lifecycle neighbors. None owns fields, callback installation, or report helper cluster.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/platform/ExceptionHandler.cpp` is the correct source root.
- Related items that belong: class UID00004P, global `g_pCrashTarget`, filter UID00014F, target UID00014G, exact helper children/ranges, and compiler-generated vtable/RTTI regenerated by the class.
- Rejected from direct ownership: Application cleanup wrapper, Crasher, Error hierarchy, timer globals, Surface globals, PlatformApi pointer storage, imported CRT/Win32 functions.

## Source Placement

- Recommended placement: `NexusTK/platform/ExceptionHandler.cpp`, member definition on `ExceptionHandler`.
- Header placement: declarations and legacy ImageHlp callback typedefs in `ExceptionHandler.h` or the existing class declaration destination represented by UID00004P.
- The source should resemble the late-1990s MSJ-derived class adaptation used by the Nexus developers, not a decompiler-shaped 1184-byte monolith.
- `PlatformApi.cpp` owns the wide dispatch globals; `TimerMgr.cpp`, `Application.cpp`, and `Surface.cpp` own their globals. UID00014G only consumes them.
- No remaining source-placement uncertainty blocks target C++.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and coherent. No internal split is recommended.
- Predecessor `0x004ab86f` is one-byte `0xCC`; successor at `0x004abd10` is a separate modeled function. Neither belongs to UID00014G source.
- Retained source methods: resolver `[0x004ac040,0x004ac0ed)`, Intel fallback `[0x004ac0f0,0x004ac221)`, and ImageHlp walk `[0x004ac230,0x004ac4cb)`.
- Exact padding: `[0x004ac0ed,0x004ac0f0)` three bytes, `[0x004ac221,0x004ac230)` fifteen bytes, `[0x004ac4cb,0x004ac4d0)` five bytes. These are compiler alignment, not source arrays/functions.
- Compiler inlining explains target duplicate semantics. Do not emit helper bodies twice from UID00014G.
- Parent impact: UID00014D should preserve all ranges and historical raw-state evidence while replacing unresolved helper identities with the accepted source names.

## Negative Evidence Summary

- No second caller, callback pointer, vtable slot, or external xref supports a different owner.
- No collision exists for the proposed method/helper/global names in the current name index.
- No imported ImageHlp entries exist; dynamic loading is exact and must remain.
- No `FreeLibrary` call exists in target or retained resolver; ancestor cleanup behavior is not Nexus behavior.
- No function record exists at `0x004ac0f0`, but exact code/ret/padding, semantic duplicate, and source lineage disprove a data/padding classification.
- Zero xrefs to retained helper starts do not prove dead source because complete inline copies are present.
- Consumer xrefs to timer/Application/Surface/PlatformApi globals do not transfer ownership to ExceptionHandler.
- The target's final EAX does not prove an `int` return; source lineage and caller use reject it.
- Existing current-directory wording is disproved by the exact `0x0069be7c` table slot.

## IDA Rename / Type / Comment Recommendations

B001 used IDA MCP read-only to establish the exact prestates below. The supervisor subsequently completed every Gate 2B action/protection row, persisted the IDB, and verified the expected readbacks. In the tables, `absent` is the literal 2C20 prestate from `get_comments`; stack/member comments were absent in that prestate. Proposed-operation and expected-readback columns are preserved as the accepted audit trail, not as pending work.

Saved-revision binding and persisted Gate 2B result:

- Authoritative IDA MCP database/session: `f085b224`.
- Exact IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Historical bounded checkpoints, not current prestates: supervisor-supplied SHA256 `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`, size `143187026`, timestamp `2026-07-24 10:57:57 local`; B001-observed SHA256 `F28C8B463F64693561E118790FD5E9D68739F85C697B9B58F391F56E1911ED99`, size `143187027`, timestamp `2026-07-24 11:48:53 local`; supervisor-observed SHA256 `EF0E6C656CE837EE350D347D93BD7967B73E556CB4582EEB80ADE241A9CACC2E`, size `143185517`, timestamp `2026-07-24T12:32:56.5741976-04:00`; UID00014G-bounded SHA256 `D99CF538F565D8D19F2BA24510FE71A2D58969E79BA4379BBDAD9C9D2A4573A8`, size `143185611`, timestamp `2026-07-24T12:53:32.4505331-04:00`; SHA256 `48EBC47071A99F8E90D2B639724A67CCB2ABA32FD34A776CA894471AE3CD8BED`, size `143185660`, timestamp `2026-07-24T13:21:32.8746112-04:00`; supervisor-supplied B6A2 SHA256 `B6A2BD3E2D92B9E77CFB82660F87E71D3709BC2D80C777140D9762234684A138`, size `143186131`, timestamp `2026-07-24T14:11:31.3531890-04:00`; supervisor-observed 9F6E SHA256 `9F6E2C7AA9CFB718AB146AC8F8363CC1401F8474AA63803D7FAED35FA8ADE7CF`, size `143186002`, timestamp `2026-07-24T18:12:13.9828605-04:00`; supervisor-observed CB62 SHA256 `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E`, size `143186380`, timestamp `2026-07-24T20:36:29.1906020-04:00`; bounded 9DF SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, size `143186002`, timestamp `2026-07-24T22:09:37.3164487-04:00`; and bounded 7509 SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, size `143186450`, timestamp `2026-07-24T22:54:09.6318603-04:00`. They remain useful provenance only.
- Supervisor-verified Gate 2B prestate observation: SHA256 `2C20AAD81BC18DE1FA91B04D7FBEC30A704D377E6E2A2E35344C06EAEE479BC0`, size `143186196` bytes. Verified pre-mutation backup: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-00014G-20260725_230500.bak`.
- B001 re-read every recommendation prestate in the function, frame/local, typedef, UDT, global/data, import, padding, protected-function, protected-adjacent-data, collision, and protected-literal tables through healthy authoritative session `f085b224`. The filesystem hash before the final item-by-item pass and after all read-only requests both returned 2C20, size `143186196`, last write `2026-07-25T22:20:13.8438553-04:00`; final server health was `ok`, Hex-Rays and the 2068-entry string cache were ready, and `auto_analysis_ready` was literally `true`.
- 2C20 continuity result: target/protected function names, prototypes, bounds, callers/xrefs, all function/entry comment channels, frame/local layout, six typedef absences, the 0x828 `ExceptionHandler` UDT and its 12 members, raw-helper instruction/byte/padding state, global bytes/types/xref counts except the explicitly rebased item shapes/comments below, import declarations/comments, protected padding, and all 29 protected literal ranges/names/types/comments remain exact. The 89-instruction raw range still has `fn:null` for every instruction, first `55`/`push ebp`, terminal `C2 08 00`/`retn 8`, zero start xrefs, and the protected 15-byte successor pad. The six proposed typedefs remain absent; all six callback fields remain `void *`.
- 2C20 current-name reconciliation: `inspect_items` renders the five unnamed one-byte heads at `0x0069be30`, `0x0069be7c`, `0x0069be0c`, `0x0069be10`, and `0x0067a938` as default display names `unk_69BE30`, `unk_69BE7C`, `unk_69BE0C`, `unk_69BE10`, and `unk_67A938`; bounded name-index queries contain no explicit entries at those addresses. Their three separate one-byte undefined tails, current types, zero bytes, xref counts, and all head/tail comment-channel absences remain exact. Proposed function and global names have no current collisions. The older 9DF wording that called those current displays blank remains historical only.
- Current item-shape reconciliation at 2C20: `0x0069be14` remains a one-byte head followed by three separate one-byte undefined tails, with name-index `g_pfnWideOpenFile`. Logical slot `[0x0067ab1c,0x0067ab20)` is now four independent one-byte items: head `[0x0067ab1c,0x0067ab1d)` displays `unk_67AB1C`, carries type `LObject *`, has no explicit name-index entry, and tails `+1/+2/+3` are blank/untyped. Protected logical slot `[0x0067ab20,0x0067ab24)` is also four independent blank/untyped one-byte items with no name-index entry. Protected logical slot `[0x0067a93c,0x0067a940)` is four independent one-byte items: head `[0x0067a93c,0x0067a93d)` has blank display, name-index `g_isWindowedDisplayMode`, and type `int`; tails `+1/+2/+3` are blank/untyped. All three logical slots contain four zero bytes and have absent regular/repeatable comments at every head/tail; head xref counts remain respectively 140, 19, and 18. The 7509 four-byte-item descriptions are historical only. No IDA mutation was performed by B001.
- 2C20 RGB drift disposition: one-byte item `[0x0069b3d5,0x0069b3d6)` had name-index `g_surfaceUsesRgb565Pixels`, type `bool`, byte `00`, 16 xrefs, and both comments absent. Supervisor Gate 2B set the accepted regular comment exactly `True when the active 16-bit surface uses RGB565 rather than RGB555 channel layout.` and preserved the repeatable channel as absent.
- Evidence/confidence rule for every row below: `exact` means direct revision-bound `lookup_funcs`, `inspect_items`, `get_comments`, `get_bytes`, `xrefs_to`, `stack_frame`, `type_query`, `type_inspect`, `insn_query`, `decompile`, or exact filesystem checkpoint evidence. `Very strong` source-facing operations combine that exact prestate with the documented source-family match. The supervisor applied each actionable row against the verified 2C20 prestate and verified every no-action row before save.
- Gate 2B persisted result: `idb_save` returned `ok`; stable post-save IDB SHA256 is `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`, size `143186768`, last write `2026-07-25T23:14:42.2666509-04:00`. MCP status remained `ok`, Hex-Rays and strings remained ready. `auto_analysis_ready:false` after exact raw-helper definition/save is recorded without invalidating the completed result because every required persisted readback succeeded.
- Applied/readback summary: exact four functions/prototypes/regular function comments; exact-created raw Intel helper `[0x004ac0f0,0x004ac221)`; exact target argument and six source locals; six legacy callback typedefs; exact `0x828`/12-member `ExceptionHandler` UDT with callback types at `+0x10..+0x24`; seven bounded globals/types/names/comments; and the RGB565 regular comment are `APPLIED_VERIFIED`. IDA canonicalizes `WINAPI` as semantically exact `__stdcall`; all six typedefs exist once and have size 4. Protected fragmented `0x0067ab20` and `0x0067a93c`, PlatformApi neighbors, six protected functions, nine imports, all protected locals/UDT members, zero bytes/xref totals, and 3/15/5-byte `CC` fences remained exact.

### Actionable function and local entities

Evidence/confidence for every row in this table: literal prestate is direct saved-revision MCP readback (`lookup_funcs`, `stack_frame`, `get_comments`, `insn_query`, `get_bytes`, and collision queries) with exact confidence; source-facing names, signatures, and local identities combine that exact prestate with the MSJ source-family match and have very-strong confidence. Each row inherits the saved-revision stop-and-rebase rule above.

| Entity | Literal live current prestate | Proposed operation and exact payload | Collision/boundary constraints | Expected Gate 2B readback |
| --- | --- | --- | --- | --- |
| Function `[0x004ab870,0x004abd10)` | Name `sub_4AB870`; declaration `int __thiscall(_DWORD *this, unsigned int *)`; function regular comment absent; function repeatable comment absent; entry regular comment absent; entry repeatable comment absent. | Rename `ExceptionHandler__GenerateExceptionReport`; apply `void __thiscall ExceptionHandler__GenerateExceptionReport(ExceptionHandler *this, EXCEPTION_POINTERS *pExceptionInfo)`; regular comment: `ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *). Writes BCrash.nfo under the Windows directory; records version, exception, registers, timer/phase/RGB565 state; initializes ImageHlp stack walking or falls back to the x86 EBP chain. Preserves the original unconditional separator write even when report-file open fails.` Repeatable comment remains absent. | Preserve exact start/end, 327 instructions, 31 blocks, sole caller, predecessor `0xCC`, successor UID00014H, and all instruction comments. Collision query found no `GenerateExceptionReport`. | New name/prototype/comment exact; size/caller/bounds unchanged; decompile exposes `ExceptionHandler *` and `EXCEPTION_POINTERS *`, void return. |
| Argument frame `arg_0`, function `0x004ab870`, frame offset `0xc4c` / `[ebp+8]` | Name `arg_0`; type `_DWORD`; stack-member comment absent. | Rename `pExceptionInfo`; type `EXCEPTION_POINTERS *`; no comment addition. | Do not shift frame or alter calling convention/`ret 4`. | Local readback `pExceptionInfo: EXCEPTION_POINTERS *`; ExceptionRecord/ContextRecord field decompile. |
| Local `Buffer`, frame offset `0x20` / `[ebp-0xc24]` | Name `Buffer`; base type `wchar_t`; inferred array extent 260; stack-member comment absent. | Rename `reportPath`; type `wchar_t[260]`; no comment addition. | Preserve overlap/bounds through next local at `[ebp-0xa1c]`. | `wchar_t reportPath[260]`. |
| Local `ArgList`, frame offset `0x228` / `[ebp-0xa1c]` | Name `ArgList`; type `char` with IDA extent 520 bytes; stack-member comment absent. | Rename `windowsDirectory`; type `wchar_t[260]`; no comment addition. | This is a type correction over the same 520 bytes; do not resize frame. | `wchar_t windowsDirectory[260]` and `GetWindowsDirectoryW` call. |
| Local `MultiByteStr`, frame offset `0x430` / `[ebp-0x814]` | Name `MultiByteStr`; base type `CHAR`; IDA extent stops at 504 bytes because the logical 1024-byte ANSI lifetime overlaps `String2`; stack-member comment absent. | Rename only to `ansiText`. Preserve the current IDA `CHAR` base type and current 504-byte represented extent; do not apply an array resize or local retype. | The source-level local remains `char ansiText[1024]`, but Gate 2B must not overwrite `String2` at frame offset `0x628` / `[ebp-0x61c]`, move `WideCharStr` at `0x830`, resize the frame, or change any neighboring local. | Name exactly `ansiText`; current `CHAR` type and 504-byte represented extent unchanged; `String2` remains at `0x628`, `WideCharStr` remains at `0x830`, frame size unchanged, and decompile still exposes conversion capacity 1024. |
| Local `String2`, frame offset `0x628` / `[ebp-0x61c]` | Name `String2`; type `wchar_t[260]`; stack-member comment absent. | Rename `executablePath`; retain type. | Preserve lifetime overlap with earlier ANSI buffer. | `wchar_t executablePath[260]`. |
| Local `WideCharStr`, frame offset `0x830` / `[ebp-0x414]` | Name `WideCharStr`; type `WCHAR[260]`; stack-member comment absent. | Rename `faultingModule`; retain `wchar_t[260]`. | Preserve exact offset/extent. | `wchar_t faultingModule[260]`. |
| Local `String1`, frame offset `0xa38` / `[ebp-0x20c]` | Name `String1`; type `wchar_t[260]`; stack-member comment absent. | Rename `moduleName`; retain type. | Preserve exact offset/extent. | `wchar_t moduleName[260]`. |
| Function `[0x004ac040,0x004ac0ed)` | Name `sub_4AC040`; declaration `BOOL __thiscall(_DWORD *this)`; all function/entry comments absent. | Rename `ExceptionHandler__InitImagehlpFunctions`; apply `BOOL __thiscall ExceptionHandler__InitImagehlpFunctions(ExceptionHandler *this)`; regular comment: `ExceptionHandler::InitImagehlpFunctions(). Loads IMAGEHLP.DLL through the wide API dispatch, resolves six legacy ImageHlp callbacks, optionally applies SymSetOptions(7), and calls SymInitialize. NexusTK does not FreeLibrary on failure.` Repeatable absent. | Preserve exact end `0x004ac0ed`, zero xrefs, and following three `0xCC`; no name collision. | Exact name/type/comment; size `0xad`, zero xrefs, and padding unchanged. |
| Raw code `[0x004ac0f0,0x004ac221)` | No function record (`lookup_funcs`: `Not a function`); no entry name or type. The first IDA code item is exactly `[0x004ac0f0,0x004ac0f1)`, instruction `push ebp`, byte `55`. `insn_query` enumerates 89 code instructions over the exact range with every `fn:null`. Entry regular comment absent; entry repeatable comment absent. The terminal item is `[0x004ac21e,0x004ac221)`, instruction `retn 8`, bytes `C2 08 00`. Start xrefs are exactly zero. The successor is one data/alignment item `[0x004ac221,0x004ac230)`, 15 bytes, all `CC`, both comments absent. | Create one function with exact half-open bounds `[0x004ac0f0,0x004ac221)`; name `ExceptionHandler__IntelStackWalk`; apply `void __thiscall ExceptionHandler__IntelStackWalk(ExceptionHandler *this, CONTEXT *pContext, FILE *pReportFile)`; set function regular comment exactly `ExceptionHandler::IntelStackWalk(CONTEXT *, FILE *). Retained x86 EBP-chain fallback helper; formats logical module addresses and executable-relative offsets when a report stream exists. GenerateExceptionReport contains an inline copy.` Leave function repeatable and both entry comment channels absent. | Preserve every code byte, all 89 instruction heads, exact first/terminal items, zero start xrefs, terminal `ret 8`, and the entire 15-byte successor item. Do not absorb `[0x004ac221,0x004ac230)`, create a tail, change the calling convention, or alter the no-collision result. | Exactly one function `[0x004ac0f0,0x004ac221)` named/typed/commented as specified; first item remains `55`/`push ebp`; terminal remains `C2 08 00`/`retn 8`; start xrefs remain zero; entry and function-repeatable comments remain absent; successor remains one 15-byte all-`CC` item with both comments absent. |
| Function `[0x004ac230,0x004ac4cb)` | Name `sub_4AC230`; declaration `LPCVOID __thiscall(int this, LPCVOID *, int)`; all function/entry comments absent. | Rename `ExceptionHandler__ImagehlpStackWalk`; apply `void __thiscall ExceptionHandler__ImagehlpStackWalk(ExceptionHandler *this, CONTEXT *pContext, FILE *pReportFile)`; regular comment: `ExceptionHandler::ImagehlpStackWalk(CONTEXT *, FILE *). Walks x86 STACKFRAME records through resolved ImageHlp callbacks, prints symbols or logical module addresses, and emits executable-relative offsets.` Repeatable absent. | Preserve exact caller `0x004abbb8`, end `0x004ac4cb`, and five-byte pad; no collision. | Exact name/type/comment; size `0x29b`, one caller, bounds unchanged. |

### Actionable function comment channels

Each comment channel below was read independently. `Function` means IDA function comment state; `entry` means the regular/repeatable address comment at the function start.

Evidence/confidence for every row in this table: direct saved-revision `get_comments` plus bound function/range readback; confidence exact for current/expected channel state and very strong for the four source-facing regular-comment payloads.

| Function/range | Comment channel | Literal live prestate | Exact Gate 2B operation | Exact expected readback |
| --- | --- | --- | --- | --- |
| `[0x004ab870,0x004abd10)` | function regular | absent | Set exact `ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *). Writes BCrash.nfo under the Windows directory; records version, exception, registers, timer/phase/RGB565 state; initializes ImageHlp stack walking or falls back to the x86 EBP chain. Preserves the original unconditional separator write even when report-file open fails.` | Function regular equals exact payload. |
| `[0x004ab870,0x004abd10)` | function repeatable | absent | No change. | absent |
| `[0x004ab870,0x004abd10)` | entry regular at `0x004ab870` | absent | No change. | absent |
| `[0x004ab870,0x004abd10)` | entry repeatable at `0x004ab870` | absent | No change. | absent |
| `[0x004ac040,0x004ac0ed)` | function regular | absent | Set exact `ExceptionHandler::InitImagehlpFunctions(). Loads IMAGEHLP.DLL through the wide API dispatch, resolves six legacy ImageHlp callbacks, optionally applies SymSetOptions(7), and calls SymInitialize. NexusTK does not FreeLibrary on failure.` | Function regular equals exact payload. |
| `[0x004ac040,0x004ac0ed)` | function repeatable | absent | No change. | absent |
| `[0x004ac040,0x004ac0ed)` | entry regular at `0x004ac040` | absent | No change. | absent |
| `[0x004ac040,0x004ac0ed)` | entry repeatable at `0x004ac040` | absent | No change. | absent |
| Raw `[0x004ac0f0,0x004ac221)` | function regular | not applicable because no function record exists | After exact-bounds function creation, set exact `ExceptionHandler::IntelStackWalk(CONTEXT *, FILE *). Retained x86 EBP-chain fallback helper; formats logical module addresses and executable-relative offsets when a report stream exists. GenerateExceptionReport contains an inline copy.` | New function regular equals exact payload. |
| Raw `[0x004ac0f0,0x004ac221)` | function repeatable | not applicable because no function record exists | Create no repeatable function comment. | absent on created function |
| Raw `[0x004ac0f0,0x004ac221)` | entry regular at `0x004ac0f0` | absent | Preserve entry channel; function regular is separate. | absent |
| Raw `[0x004ac0f0,0x004ac221)` | entry repeatable at `0x004ac0f0` | absent | No change. | absent |
| `[0x004ac230,0x004ac4cb)` | function regular | absent | Set exact `ExceptionHandler::ImagehlpStackWalk(CONTEXT *, FILE *). Walks x86 STACKFRAME records through resolved ImageHlp callbacks, prints symbols or logical module addresses, and emits executable-relative offsets.` | Function regular equals exact payload. |
| `[0x004ac230,0x004ac4cb)` | function repeatable | absent | No change. | absent |
| `[0x004ac230,0x004ac4cb)` | entry regular at `0x004ac230` | absent | No change. | absent |
| `[0x004ac230,0x004ac4cb)` | entry repeatable at `0x004ac230` | absent | No change. | absent |

### Actionable UDT member types

Required IDA type declarations, 32-bit widths preserved:

- `typedef BOOL (WINAPI *SYMINITIALIZEPROC)(HANDLE, PCSTR, BOOL);`
- `typedef BOOL (WINAPI *SYMCLEANUPPROC)(HANDLE);`
- `typedef BOOL (WINAPI *STACKWALKPROC)(DWORD, HANDLE, HANDLE, LPSTACKFRAME, PVOID, PREAD_PROCESS_MEMORY_ROUTINE, PFUNCTION_TABLE_ACCESS_ROUTINE, PGET_MODULE_BASE_ROUTINE, PTRANSLATE_ADDRESS_ROUTINE);`
- `typedef PVOID (WINAPI *SYMFUNCTIONTABLEACCESSPROC)(HANDLE, DWORD);`
- `typedef DWORD (WINAPI *SYMGETMODULEBASEPROC)(HANDLE, DWORD);`
- `typedef BOOL (WINAPI *SYMGETSYMFROMADDRPROC)(HANDLE, DWORD, PDWORD, PIMAGEHLP_SYMBOL);`

Prestate exact-name `type_inspect` returned `exists:false` for each proposed name in database `f085b224` against 2C20. The supervisor created each typedef during Gate 2B; persisted readback now shows every exact name once, size 4, with IDA's semantically exact `__stdcall` canonicalization of `WINAPI`.

Evidence/confidence for every typedef row: direct saved-revision exact-name `type_query` absence with exact confidence; declarations and ABI constraints are the exact legacy ImageHlp callback contracts matched to the observed `GetProcAddress` uses, with very-strong confidence.

| Typedef entity | Literal live prestate / absent result | Create-or-reuse action | Collision and 32-bit ABI constraints | Exact expected readback |
| --- | --- | --- | --- | --- |
| `SYMINITIALIZEPROC` | `f085b224`/2C20 exact-name `type_inspect`: `exists:false`; declaration absent. | Create `typedef BOOL (WINAPI *SYMINITIALIZEPROC)(HANDLE, PCSTR, BOOL);`; if another accepted Gate 2B action creates it first, reuse only an exact declaration. | No exact-name collision. Preserve `WINAPI`/`__stdcall`, three parameters, `BOOL` return, and four-byte pointer size. | Exact-name query total `1`; declaration text exact; typedef size 4. |
| `SYMCLEANUPPROC` | `f085b224`/2C20 exact-name `type_inspect`: `exists:false`; declaration absent. | Create `typedef BOOL (WINAPI *SYMCLEANUPPROC)(HANDLE);`; reuse only an exact declaration introduced earlier in the same Gate 2B. | No exact-name collision. Preserve `WINAPI`, one `HANDLE`, `BOOL` return, and four-byte pointer size. | Exact-name query total `1`; declaration text exact; typedef size 4. |
| `STACKWALKPROC` | `f085b224`/2C20 exact-name `type_inspect`: `exists:false`; declaration absent. | Create `typedef BOOL (WINAPI *STACKWALKPROC)(DWORD, HANDLE, HANDLE, LPSTACKFRAME, PVOID, PREAD_PROCESS_MEMORY_ROUTINE, PFUNCTION_TABLE_ACCESS_ROUTINE, PGET_MODULE_BASE_ROUTINE, PTRANSLATE_ADDRESS_ROUTINE);`; reuse only exact. | No exact-name collision. Preserve nine parameters in this order, 32-bit `DWORD` machine type, `WINAPI`, `BOOL` return, and four-byte pointer size. | Exact-name query total `1`; full declaration exact; typedef size 4. |
| `SYMFUNCTIONTABLEACCESSPROC` | `f085b224`/2C20 exact-name `type_inspect`: `exists:false`; declaration absent. | Create `typedef PVOID (WINAPI *SYMFUNCTIONTABLEACCESSPROC)(HANDLE, DWORD);`; reuse only exact. | No exact-name collision. Preserve `PVOID` return, two parameters, `WINAPI`, 32-bit address, and four-byte pointer size. | Exact-name query total `1`; declaration exact; typedef size 4. |
| `SYMGETMODULEBASEPROC` | `f085b224`/2C20 exact-name `type_inspect`: `exists:false`; declaration absent. | Create `typedef DWORD (WINAPI *SYMGETMODULEBASEPROC)(HANDLE, DWORD);`; reuse only exact. | No exact-name collision. Preserve `DWORD` return/address, two parameters, `WINAPI`, and four-byte pointer size. | Exact-name query total `1`; declaration exact; typedef size 4. |
| `SYMGETSYMFROMADDRPROC` | `f085b224`/2C20 exact-name `type_inspect`: `exists:false`; declaration absent. | Create `typedef BOOL (WINAPI *SYMGETSYMFROMADDRPROC)(HANDLE, DWORD, PDWORD, PIMAGEHLP_SYMBOL);`; reuse only exact. | No exact-name collision. Preserve four parameters, 32-bit address/displacement, `WINAPI`, `BOOL` return, and four-byte pointer size. | Exact-name query total `1`; declaration exact; typedef size 4. |

| Entity | Literal live current prestate | Proposed operation | Constraints | Expected readback |
| --- | --- | --- | --- | --- |
| `ExceptionHandler+0x10 m_symInitialize` | Offset `0x10`; current name `m_symInitialize`; current type `void *`; size 4; member comment absent. | Keep name/offset; apply `SYMINITIALIZEPROC`; add no member comment. | Typedef must already exist exactly; keep member width 4, following member at `0x14`, all other members, and total UDT size `0x828`. | Offset `0x10`, name exact, type `SYMINITIALIZEPROC`, size 4, comment absent; UDT remains `0x828`. |
| `ExceptionHandler+0x14 m_symCleanup` | Offset `0x14`; current name `m_symCleanup`; current type `void *`; size 4; member comment absent. | Keep name/offset; apply `SYMCLEANUPPROC`; add no comment. | Keep width 4, neighbors `0x10/0x18`, structure order, and total UDT size `0x828`. | Offset `0x14`, name exact, type `SYMCLEANUPPROC`, size 4, comment absent; UDT `0x828`. |
| `ExceptionHandler+0x18 m_stackWalk` | Offset `0x18`; current name `m_stackWalk`; current type `void *`; size 4; member comment absent. | Keep name/offset; apply `STACKWALKPROC`; add no comment. | Keep width 4, neighbors `0x14/0x1c`, structure order, and total UDT size `0x828`. | Offset `0x18`, name exact, type `STACKWALKPROC`, size 4, comment absent; UDT `0x828`. |
| `ExceptionHandler+0x1c m_symFunctionTableAccess` | Offset `0x1c`; current name `m_symFunctionTableAccess`; current type `void *`; size 4; member comment absent. | Keep name/offset; apply `SYMFUNCTIONTABLEACCESSPROC`; add no comment. | Keep width 4, neighbors `0x18/0x20`, structure order, and total UDT size `0x828`. | Offset `0x1c`, name exact, type `SYMFUNCTIONTABLEACCESSPROC`, size 4, comment absent; UDT `0x828`. |
| `ExceptionHandler+0x20 m_symGetModuleBase` | Offset `0x20`; current name `m_symGetModuleBase`; current type `void *`; size 4; member comment absent. | Keep name/offset; apply `SYMGETMODULEBASEPROC`; add no comment. | Keep width 4, neighbors `0x1c/0x24`, structure order, and total UDT size `0x828`. | Offset `0x20`, name exact, type `SYMGETMODULEBASEPROC`, size 4, comment absent; UDT `0x828`. |
| `ExceptionHandler+0x24 m_symGetSymFromAddr` | Offset `0x24`; current name `m_symGetSymFromAddr`; current type `void *`; size 4; member comment absent. | Keep name/offset; apply `SYMGETSYMFROMADDRPROC`; add no comment. | Keep width 4, preceding member `0x20`, `m_reportText` at `0x28`, structure order, and total UDT size `0x828`. | Offset `0x24`, name exact, type `SYMGETSYMFROMADDRPROC`, size 4, comment absent; `m_reportText` still starts `0x28`; UDT `0x828`. |

Evidence/confidence for every UDT row: direct saved-revision `type_inspect` member name/offset/type/size/comment readback is exact; replacement callback typedef identity is supported by exact slot use plus source lineage and is very strong. Every row independently preserves the `0x828` structure constraint.

### Actionable global/data entities

Evidence/confidence for every row in this table: direct saved-revision `inspect_items`, `get_bytes`, `get_comments`, `xrefs_to`, and name/type readback is exact; source-facing names/types/comments combine those use sets with neighboring-table and source-family context and are very strong. Each bounded operation must stop if any byte, head, extent, xref count, neighbor, or comment channel differs.

| Entity | Literal live item/byte/type/name prestate | Regular comment prestate | Repeatable comment prestate | Bounded Gate 2B operation and exact payload | Bytes/xrefs/adjacent constraints | Exact expected readback |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x0067ab1c,0x0067ab20)` | Four independent one-byte items: head `[0x0067ab1c,0x0067ab1d)` displays `unk_67AB1C`, has no explicit name-index entry, current type `LObject *`, and `is_data:false`; `+1/+2/+3` are separate blank/untyped one-byte items. All four bytes are `00`; all eight head/tail comment channels are absent; head xref count 140. | absent | absent | Bounded undefine only `[0x0067ab1c,0x0067ab20)`, recreate one four-byte pointer item, rename `g_pApplication`, apply `Application *`, and set regular comment `Active Application singleton pointer. ExceptionHandler::GenerateExceptionReport reads the version-major field through this object.` Repeatable remains absent. | Preserve all four zero bytes, current head xref count 140, and protected adjacent logical slot `[0x0067ab20,0x0067ab24)`, which is four separate blank/untyped one-byte items with no name-index entry, four zero bytes, head xref count 19, and all comments absent. Do not undefine, widen, split, merge, rename, retype, or comment any byte at or above `0x0067ab20`. | One four-byte item `[0x0067ab1c,0x0067ab20)` has name `g_pApplication`, type `Application *`, exact regular comment, repeatable absent, bytes unchanged, and head xref count 140; all four protected one-byte items in `[0x0067ab20,0x0067ab24)` remain exact. |
| `[0x0069be14,0x0069be18)` | Head `0x0069be14` is a one-byte item; display name blank while name index exposes `g_pfnWideOpenFile`; current type `int (__cdecl *)(_DWORD, _DWORD)`; `+1/+2/+3` are three separate unnamed/untyped one-byte undefined items; bytes `00 00 00 00`; xref count 41. | absent | absent | Bounded undefine only `[0x0069be14,0x0069be18)`, recreate one four-byte function-pointer item, retain/normalize name `g_pfnWideOpenFile`, apply `FILE *(__cdecl *)(const wchar_t *path, const wchar_t *mode)`, and set regular comment `PlatformApi wide fopen dispatch used to create BCrash.nfo and by other wide-file consumers.` Repeatable remains absent. | Preserve all four zero bytes, xref count 41, and following one-byte head `0x0069be18`, whose name index is `g_pfnWideStat` and whose wide-stat callback type/comments remain unchanged; do not widen past the half-open range. | One four-byte item `[0x0069be14,0x0069be18)` with exact name/type/regular comment; repeatable absent; bytes unchanged; xref count 41; next one-byte head unchanged. |
| `[0x0069be30,0x0069be34)` | Head `0x0069be30` is a one-byte item with default display name `unk_69BE30` and no explicit name-index entry, type `int (__stdcall *)(_DWORD)`, `is_data:false`; `+1/+2/+3` are separate unnamed/untyped one-byte undefined items; bytes `00 00 00 00`; xref count 8. | absent | absent | Bounded undefine `[0x0069be30,0x0069be34)`, recreate one four-byte function-pointer item, rename `g_pfnLoadLibraryW`, type `HMODULE (WINAPI *)(LPCWSTR fileName)`, regular comment `PlatformApi LoadLibraryW dispatch; GenerateExceptionReport uses it to load IMAGEHLP.DLL.` Repeatable absent. | Preserve bytes, xref count 8, and adjacent one-byte head `0x0069be34`, whose seven-argument cdecl pointer type, three undefined tails, zero bytes, and absent comments remain unchanged; no spill outside four-byte slot. | One four-byte item with exact name/type/comment, repeatable absent, bytes unchanged, xref count 8, neighbor unchanged. |
| `[0x0069be7c,0x0069be80)` | Head `0x0069be7c` is a one-byte item with default display name `unk_69BE7C` and no explicit name-index entry, type `int (__stdcall *)(_DWORD, _DWORD)`, `is_data:false`; `+1/+2/+3` are separate unnamed/untyped one-byte undefined items; bytes `00 00 00 00`; xref count 5. | absent | absent | Bounded undefine `[0x0069be7c,0x0069be80)`, recreate one four-byte function-pointer item, rename `g_pfnGetWindowsDirectoryW`, type `UINT (WINAPI *)(LPWSTR buffer, UINT size)`, regular comment `PlatformApi GetWindowsDirectoryW dispatch. ExceptionHandler report writer and stored-report sender place BCrash.nfo under this directory.` Repeatable absent. | Preserve bytes, xref count 5, preceding distinct one-byte `GetCurrentDirectoryW`-typed head at `0x0069be70` plus its three undefined tails, and next blank/untyped one-byte head at `0x0069be80` plus its three undefined tails; all protected comments/bytes remain absent/zero. | One four-byte item with exact name/type/comment, repeatable absent, bytes unchanged, xref count 5; both protected neighboring head/tail groups unchanged. |
| `[0x0069be0c,0x0069be10)` | Head `0x0069be0c` is a one-byte item with default display name `unk_69BE0C` and no explicit name-index entry, type absent, `is_data:false`; `+1/+2/+3` are separate unnamed/untyped one-byte undefined items; bytes `00 00 00 00`; xref count 2. | absent | absent | Bounded undefine `[0x0069be0c,0x0069be10)`, recreate one four-byte `DWORD`, rename `g_timerTickBaselineMirror`, regular comment `TimerMgr baseline tick mirror subtracted from the current tick in crash diagnostics.` Repeatable absent. | Preserve bytes, both current xrefs, preceding TimerMgr-owned state, and next default-named one-byte head `unk_69BE10` at `0x0069be10`. | One four-byte DWORD item, exact name/regular comment, repeatable absent, bytes unchanged, xref count 2, next item begins `0x0069be10`. |
| `[0x0069be10,0x0069be14)` | Head `0x0069be10` is a one-byte item with default display name `unk_69BE10` and no explicit name-index entry, type absent, `is_data:false`; `+1/+2/+3` are separate unnamed/untyped one-byte undefined items; bytes `00 00 00 00`; xref count 4. | absent | absent | Bounded undefine `[0x0069be10,0x0069be14)`, recreate one four-byte `DWORD`, rename `g_timerCurrentTickMirror`, regular comment `TimerMgr current tick mirror used by crash diagnostics and timer dispatch.` Repeatable absent. | Preserve bytes, all four current xrefs, preceding default-named head `unk_69BE0C` at `0x0069be0c`, and wide-open table head `0x0069be14`. | One four-byte DWORD item, exact name/regular comment, repeatable absent, bytes unchanged, xref count 4, both adjacent heads unchanged. |
| `[0x0067a938,0x0067a93c)` | Head `0x0067a938` is a one-byte item with default display name `unk_67A938` and no explicit name-index entry, type absent, `is_data:false`; `+1/+2/+3` are separate unnamed/untyped one-byte undefined items; bytes `00 00 00 00`; xref count 5. | absent | absent | Bounded undefine `[0x0067a938,0x0067a93c)`, recreate one four-byte `int`, rename `g_applicationPhaseState`, regular comment `Application lifecycle phase/state value emitted in BCrash.nfo and consumed by startup/input paths.` Repeatable absent. | Preserve bytes, xref count 5, and following protected logical slot `[0x0067a93c,0x0067a940)`: four independent one-byte items, with head `[0x0067a93c,0x0067a93d)` displaying blank, name-index `g_isWindowedDisplayMode`, type `int`, and `+1/+2/+3` blank/untyped; all four bytes zero, head xref count 18, and all comments absent. Do not touch any byte at or above `0x0067a93c`. | One four-byte int item with exact name/comment, repeatable absent, bytes unchanged, xref count 5; all four protected one-byte items in `[0x0067a93c,0x0067a940)` remain exact. |
| Byte `0x0069b3d5` | One-byte item at exact head/end `[0x0069b3d5,0x0069b3d6)`, display name blank while name index exposes `g_surfaceUsesRgb565Pixels`, type `bool`, byte `00`, xref count 16. Adjacent `0x0069b3d4` is a separate bool byte; `0x0069b3d6` and `0x0069b3d7` are separate unnamed/untyped bytes. | absent | absent | Set regular comment exactly `True when the active 16-bit surface uses RGB565 rather than RGB555 channel layout.` Leave repeatable absent; perform no rename, retype, undefine, or boundary action. | Preserve byte `00`, xref count 16, absent repeatable comment, name-index/type, adjacent bool `0x0069b3d4`, and bytes/items `[0x0069b3d6,0x0069b3d8)`. | Same one-byte bool item/name-index/type with exact regular comment `True when the active 16-bit surface uses RGB565 rather than RGB555 channel layout.`, repeatable absent, byte unchanged, xref count 16, neighbors unchanged. |

### Protected/no-action functions, ranges, imports, locals, and UDT members

Evidence/confidence for every row in this table: direct saved-revision function/item/frame/type/comment readback is exact. Every disposition is an exact `NO_CHANGE`; the stated range, declaration/type, width/offset, comment channels, bytes where listed, frame/UDT size, and adjacent boundaries are preservation constraints and the same literal state is the expected readback.

| Entity | Literal live current prestate | Disposition and expected readback |
| --- | --- | --- |
| Function `[0x004ab830,0x004ab86f)` | Name `TopLevelExceptionFilter`; declaration `LONG __stdcall(struct _EXCEPTION_POINTERS *ExceptionInfo)`; size `0x3f`; function regular/repeatable and entry regular/repeatable comments all absent. | No target-driven IDA change. Preserve exact name/type/size/comment channels. Ordinary source call spelling changes only. |
| Byte `[0x004ab86f,0x004ab870)` | Name/type absent; data item width 1; regular/repeatable comments absent; byte `CC`. | Protected alignment; unchanged. |
| Function `[0x004abd10,0x004abe4a)` | Name `ExceptionHandler_GetExceptionString`; declaration `wchar_t *__stdcall(unsigned int exceptionCode)`; function regular comment exactly `Private static ExceptionHandler::GetExceptionString(DWORD), source-proven from the MSJExceptionHandler lineage and adapted to the NexusTK enclosing class. Returns mutable legacy LPTSTR storage.`; repeatable/entry comments absent. | Already present; preserve all state. |
| Function `[0x004abfa0,0x004ac035)` | Name `ExceptionHandler_GetLogicalAddress`; declaration `bool __stdcall(void *address, wchar_t *moduleName, unsigned int moduleNameLength, unsigned int *sectionNumber, unsigned int *sectionOffset)`; function regular comment exactly `Private static source helper ExceptionHandler::GetLogicalAddress. moduleNameLength is a count of wide characters. Walks PE sections using max(SizeOfRawData, VirtualSize) with an inclusive end; writes one-based sectionNumber and sectionOffset only after a successful match. AL-only returns establish source bool rather than Win32 BOOL.`; repeatable/entry comments absent. | Already present; preserve all state. |
| Padding `[0x004ac0ed,0x004ac0f0)` | One unnamed/untyped data item, width 3, bytes `CC CC CC`; item regular comment absent; item repeatable comment absent. | Exact revision-bound `inspect_items`/`get_bytes`/`get_comments`; confidence exact. NO_CHANGE: preserve one three-byte item, bytes, bounds, name/type absence, regular-comment absence, and repeatable-comment absence. Expected readback is independently unchanged for both channels. |
| Padding `[0x004ac221,0x004ac230)` | One unnamed/untyped data item, width 15, all bytes `CC`; item regular comment absent; item repeatable comment absent. | Exact revision-bound `inspect_items`/`get_bytes`/`get_comments`; confidence exact. NO_CHANGE: preserve one fifteen-byte item, bytes, bounds, name/type absence, regular-comment absence, and repeatable-comment absence. Expected readback is independently unchanged for both channels. |
| Padding `[0x004ac4cb,0x004ac4d0)` | One unnamed/untyped data item, width 5, bytes `CC CC CC CC CC`; item regular comment absent; item repeatable comment absent. | Exact revision-bound `inspect_items`/`get_bytes`/`get_comments`; confidence exact. NO_CHANGE: preserve one five-byte item, bytes, bounds, name/type absence, regular-comment absence, and repeatable-comment absence. Expected readback is independently unchanged for both channels. |
| Function `[0x004651f0,0x004652dc)` | Name `sub_4651F0`; declaration `errno_t __stdcall(wchar_t *Destination, rsize_t SizeInWords)`; size `0xec`; all four function/entry comment channels absent. | Protected dependency owned by UID0002JX; no name/type/comment/boundary change. Expected exact unchanged readback. |
| Function `[0x00465300,0x00465308)` | Name `sub_465300`; declaration `__int16 __thiscall(_WORD *this)`; size `0x8`; all four comment channels absent. | Protected dependency owned by UID0002GP; no name/type/comment/boundary change. Expected exact unchanged readback. |
| Function `[0x00465320,0x00465424)` | Name `sub_465320`; declaration `__int16()`; size `0x104`; all four comment channels absent. | Protected dependency owned by UID0002JZ; no name/type/comment/boundary change. Expected exact unchanged readback. |
| Import item `[0x0060d128,0x0060d12c)` | Name `GetProcAddress`; current declaration `FARPROC (__stdcall *)(HMODULE hModule, LPCSTR lpProcName)`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action. Expected readback is the same range/name/literal declaration/width and both comments absent. |
| Import item `[0x0060d170,0x0060d174)` | Name `WideCharToMultiByte`; current declaration `int (__stdcall *)(UINT CodePage, DWORD dwFlags, LPCWCH lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar)`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action. Expected readback is the same range/name/eight-parameter declaration/width and both comments absent. |
| Import item `[0x0060d134,0x0060d138)` | Name `GetCurrentProcess`; current declaration `HANDLE (__stdcall *)()`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action. Expected exact unchanged range/name/declaration/width/comments. |
| Import item `[0x0060d19c,0x0060d1a0)` | Name `GetCurrentThread`; current declaration `HANDLE (__stdcall *)()`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action. Expected exact unchanged range/name/declaration/width/comments. |
| Import item `[0x0060d1a0,0x0060d1a4)` | Name `IsBadWritePtr`; current declaration `BOOL (__stdcall *)(LPVOID lp, UINT_PTR ucb)`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action; preserve the legacy API use. Expected exact unchanged range/name/declaration/width/comments. |
| Import item `[0x0060d2dc,0x0060d2e0)` | Name `VirtualQuery`; current declaration `SIZE_T (__stdcall *)(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action. Expected exact unchanged range/name/declaration/width/comments. |
| Import item `[0x0060d258,0x0060d25c)` | Name `GetModuleFileNameW`; current declaration `DWORD (__stdcall *)(HMODULE hModule, LPWSTR lpFilename, DWORD nSize)`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action. Expected exact unchanged range/name/declaration/width/comments. |
| Import item `[0x0060d26c,0x0060d270)` | Name `GetCurrentDirectoryW`; current declaration `DWORD (__stdcall *)(DWORD nBufferLength, LPWSTR lpBuffer)`; width 4; regular comment absent; repeatable comment absent. | Protected distinct import; no rename/type/comment/boundary action and do not associate it with target slot `0x0069be7c`. Expected exact unchanged range/name/declaration/width/comments. |
| Import item `[0x0060d254,0x0060d258)` | Name `LoadLibraryW`; current declaration `HMODULE (__stdcall *)(LPCWSTR lpLibFileName)`; width 4; regular comment absent; repeatable comment absent. | No rename/type/comment/boundary action. Expected exact unchanged range/name/declaration/width/comments. |
| Protected data span `[0x0067ab20,0x0067ab24)` | Four independent one-byte items: head `[0x0067ab20,0x0067ab21)` and tails `+1/+2/+3` are all blank/untyped, no explicit name-index entry exists anywhere in the span, all four bytes are `00`, head xref count is 19, and all eight regular/repeatable comment channels are absent. | Protected neighbor of actionable `0x0067ab1c`; exact NO_CHANGE. Preserve all four one-byte heads, blank names/types, absent name-index/comments, zero bytes, and head xref count 19. The bounded recreation at `[0x0067ab1c,0x0067ab20)` must stop before this span. Expected readback is the same four-item state. |
| Protected data span `[0x0067a93c,0x0067a940)` | Four independent one-byte items: head `[0x0067a93c,0x0067a93d)` has blank display, name-index `g_isWindowedDisplayMode`, current type `int`, and `is_data:false`; tails `+1/+2/+3` are blank/untyped. All four bytes are `00`; head xref count is 18; all eight regular/repeatable comment channels are absent. | Protected neighbor of actionable `0x0067a938`; exact NO_CHANGE. Preserve the four-item one-byte shape, head name-index/type, blank tails, all absent comment channels, all zero bytes, head xref count 18, and following one-byte `wchar_t` item at `0x0067a940`. Do not undefine, merge, widen, rename, retype, or comment this span. Expected readback is that same literal state. |
| Local `sectionNumber` in function `0x004ab870` | Frame offset `0x0c`, `[ebp-0xc38]`; current name `sectionNumber`; type `unsigned int`; width 4; stack-member comment absent. | No change. Preserve exact name/type/location/width/comment and the intentionally uninitialized first `GetLogicalAddress` call. |
| Local `sectionOffset` in function `0x004ab870` | Frame offset `0x10`, `[ebp-0xc34]`; current name `sectionOffset`; type `unsigned int`; width 4; stack-member comment absent. | No change. Preserve exact name/type/location/width/comment and intentionally uninitialized first call. |
| Local `var_C30` in function `0x004ab870` | Frame offset `0x14`, `[ebp-0xc30]`; current name `var_C30`; type `unsigned int`; width 4; stack-member comment absent. | No forced rename/type/comment because lifetime-coalesced uses do not support one safe source identity. Expected exact unchanged readback. |
| Local `var_C2C` in function `0x004ab870` | Frame offset `0x18`, `[ebp-0xc2c]`; current name `var_C2C`; type `_DWORD`; width 4; stack-member comment absent. | No forced rename/type/comment; preserve coalesced receiver/context/fallback-output uses and exact location. |
| Local `var_C28` in function `0x004ab870` | Frame offset `0x1c`, `[ebp-0xc28]`; current name `var_C28`; type `unsigned int`; width 4; stack-member comment absent. | No forced rename/type/comment; preserve coalesced lifetime and exact location. |
| Local `var_4` in function `0x004ab870` | Frame offset `0xc40`, `[ebp-0x4]`; current name `var_4`; type `_DWORD`; width 4; stack-member comment absent. | Compiler security-cookie state; no rename/type/comment. Expected exact offset/name/type/width unchanged. |
| Frame member `__saved_registers` in function `0x004ab870` | Frame offset `0xc44`, `[ebp+0]`; current name `__saved_registers`; type `_DWORD`; width 4; comment absent. | Compiler frame state; exact NO_CHANGE. Expected readback is the same offset/location/name/type/width/comment with frame size unchanged. |
| Frame member `__return_address` in function `0x004ab870` | Frame offset `0xc48`, `[ebp+4]`; current name `__return_address`; type `_UNKNOWN *`; width 4; comment absent. | Compiler frame state; exact NO_CHANGE. Expected readback is the same offset/location/name/type/width/comment with frame size unchanged. |
| UDT member `ExceptionHandler+0x00 vftable` | Offset `0x00`; name `vftable`; type `void *`; size 4; member comment absent. | Protected no-action. Preserve name/type/offset/width and total UDT size `0x828`; expected unchanged readback. |
| UDT member `ExceptionHandler+0x04 m_skipCrashReport` | Offset `0x04`; name `m_skipCrashReport`; type `bool`; size 1; member comment absent. | Protected no-action. Preserve exact byte field and following alignment; UDT remains `0x828`. |
| UDT member `ExceptionHandler+0x05 _naturalAlignment005` | Offset `0x05`; name `_naturalAlignment005`; type `unsigned __int8[3]`; size 3; member comment absent. | Protected natural alignment; no rename/type/comment; preserve `m_previousFilter` at `0x08` and total UDT size `0x828`. |
| UDT member `ExceptionHandler+0x08 m_previousFilter` | Offset `0x08`; name `m_previousFilter`; type `LPTOP_LEVEL_EXCEPTION_FILTER`; size 4; member comment absent. | Protected no-action. Preserve callback pointer type/offset/width and UDT size `0x828`. |
| UDT member `ExceptionHandler+0x0c m_reserved0C` | Offset `0x0c`; name `m_reserved0C`; type `DWORD`; size 4; member comment absent. | Protected no-action; do not invent semantics. Preserve offset/width, callback field start `0x10`, and UDT size `0x828`. |
| UDT member `ExceptionHandler+0x28 m_reportText` | Offset `0x28`; name `m_reportText`; type `wchar_t[1024]`; size 2048; member comment absent. | Protected no-action. Preserve exact buffer extent through class end and total UDT size `0x828`. |

### Protected padding comment-channel readback

Each comment channel was re-read independently against bounded saved-IDB observation `2C20AAD81BC18DE1FA91B04D7FBEC30A704D377E6E2A2E35344C06EAEE479BC0` through session `f085b224`. Evidence for every row is revision-bound `inspect_items`, `get_bytes`, and `get_comments`; confidence is exact.

| Exact padding item | Channel | Literal saved-revision prestate | Gate 2B disposition | Exact expected readback | Evidence / confidence |
| --- | --- | --- | --- | --- | --- |
| `[0x004ac0ed,0x004ac0f0)` | item regular | absent | NO_CHANGE; do not set a comment. | regular absent | direct MCP / exact |
| `[0x004ac0ed,0x004ac0f0)` | item repeatable | absent | NO_CHANGE; do not set a comment. | repeatable absent | direct MCP / exact |
| `[0x004ac221,0x004ac230)` | item regular | absent | NO_CHANGE; do not set a comment. | regular absent | direct MCP / exact |
| `[0x004ac221,0x004ac230)` | item repeatable | absent | NO_CHANGE; do not set a comment. | repeatable absent | direct MCP / exact |
| `[0x004ac4cb,0x004ac4d0)` | item regular | absent | NO_CHANGE; do not set a comment. | regular absent | direct MCP / exact |
| `[0x004ac4cb,0x004ac4d0)` | item repeatable | absent | NO_CHANGE; do not set a comment. | repeatable absent | direct MCP / exact |

### Protected function comment-channel readback

Evidence/confidence for every row in this table: direct saved-revision function and entry `get_comments` readback; confidence exact. Every row is an independent `NO_CHANGE` operation and its literal prestate is also the exact expected readback.

| Function | Comment channel | Literal live prestate | No-action constraint and expected unchanged readback |
| --- | --- | --- | --- |
| `[0x004ab830,0x004ab86f)` | function regular | absent | Leave absent. |
| `[0x004ab830,0x004ab86f)` | function repeatable | absent | Leave absent. |
| `[0x004ab830,0x004ab86f)` | entry regular at `0x004ab830` | absent | Leave absent. |
| `[0x004ab830,0x004ab86f)` | entry repeatable at `0x004ab830` | absent | Leave absent. |
| `[0x004abd10,0x004abe4a)` | function regular | exact `Private static ExceptionHandler::GetExceptionString(DWORD), source-proven from the MSJExceptionHandler lineage and adapted to the NexusTK enclosing class. Returns mutable legacy LPTSTR storage.` | Preserve exact text. |
| `[0x004abd10,0x004abe4a)` | function repeatable | absent | Leave absent. |
| `[0x004abd10,0x004abe4a)` | entry regular at `0x004abd10` | absent | Leave absent. |
| `[0x004abd10,0x004abe4a)` | entry repeatable at `0x004abd10` | absent | Leave absent. |
| `[0x004abfa0,0x004ac035)` | function regular | exact `Private static source helper ExceptionHandler::GetLogicalAddress. moduleNameLength is a count of wide characters. Walks PE sections using max(SizeOfRawData, VirtualSize) with an inclusive end; writes one-based sectionNumber and sectionOffset only after a successful match. AL-only returns establish source bool rather than Win32 BOOL.` | Preserve exact text. |
| `[0x004abfa0,0x004ac035)` | function repeatable | absent | Leave absent. |
| `[0x004abfa0,0x004ac035)` | entry regular at `0x004abfa0` | absent | Leave absent. |
| `[0x004abfa0,0x004ac035)` | entry repeatable at `0x004abfa0` | absent | Leave absent. |
| `[0x004651f0,0x004652dc)` | function regular | absent | Leave absent; UID0002JX owns any future change. |
| `[0x004651f0,0x004652dc)` | function repeatable | absent | Leave absent. |
| `[0x004651f0,0x004652dc)` | entry regular at `0x004651f0` | absent | Leave absent. |
| `[0x004651f0,0x004652dc)` | entry repeatable at `0x004651f0` | absent | Leave absent. |
| `[0x00465300,0x00465308)` | function regular | absent | Leave absent; UID0002GP owns any future change. |
| `[0x00465300,0x00465308)` | function repeatable | absent | Leave absent. |
| `[0x00465300,0x00465308)` | entry regular at `0x00465300` | absent | Leave absent. |
| `[0x00465300,0x00465308)` | entry repeatable at `0x00465300` | absent | Leave absent. |
| `[0x00465320,0x00465424)` | function regular | absent | Leave absent; UID0002JZ owns any future change. |
| `[0x00465320,0x00465424)` | function repeatable | absent | Leave absent. |
| `[0x00465320,0x00465424)` | entry regular at `0x00465320` | absent | Leave absent. |
| `[0x00465320,0x00465424)` | entry repeatable at `0x00465320` | absent | Leave absent. |

### Protected literal/data entities

Each item was read independently. Regular and repeatable comments are literally absent on every listed head. These are protected no-action entities: do not undefine, merge, widen, rename, retype, or comment them. Per-literal xref sets were not inventoried, so this table deliberately makes no unchanged-xref claim.

Evidence/confidence for every row in this table: direct saved-revision `inspect_items`, string/item readback, and independent regular/repeatable `get_comments`; confidence exact. Each row is an exact `NO_CHANGE`, and its listed range/name/type/comment state plus boundary-safety constraint is the expected readback.

| Exact current item range | Literal live name / type / role | Regular comment prestate | Repeatable comment prestate | No-action and boundary-safety constraint | Exact expected readback |
| --- | --- | --- | --- | --- | --- |
| `[0x0061973c,0x00619752)` | Name `aBcrashNfo`; type absent; wide `BCrash.nfo`. | absent | absent | No action; preserve this exact half-open item and do not merge with the next item at `0x00619754`. | Same range/name/type and both comments absent. |
| `[0x00619754,0x00619760)` | Name `aSS_1`; type `const wchar_t`; wide `%s\\%s`. | absent | absent | No action; preserve the exact item and the gap/items on both sides. | Same range/name/type and both comments absent. |
| `[0x00619768,0x0061976e)` | Name `aWt`; type absent; wide `wt`. | absent | absent | No action; preserve exact bounds and do not absorb the version literal at `0x00619770`. | Same range/name/type and both comments absent. |
| `[0x00619770,0x0061977d)` | Name `aDDEngR`; type absent; version line. | absent | absent | No action; preserve exact bounds and adjacent report literals. | Same range/name/type and both comments absent. |
| `[0x00619780,0x00619799)` | Name `aExceptionCode0`; type absent; exception line. | absent | absent | No action; preserve exact bounds and the fault literal beginning `0x0061979c`. | Same range/name/type and both comments absent. |
| `[0x0061979c,0x006197bf)` | Name `aFaultAddress08`; type absent; fault line. | absent | absent | No action; preserve exact bounds and register heading at `0x006197c0`. | Same range/name/type and both comments absent. |
| `[0x006197c0,0x006197cd)` | Name `aRegisters`; type absent; register heading. | absent | absent | No action; preserve exact bounds and the GPR block beginning `0x006197d0`. | Same range/name/type and both comments absent. |
| `[0x006197d0,0x00619807)` | Name `aEax08xEbx08xEc`; type absent; GPR block. | absent | absent | No action; preserve exact bounds and CS:EIP item at `0x00619808`. | Same range/name/type and both comments absent. |
| `[0x00619808,0x0061981a)` | Name `aCsEip04x08x`; type absent; CS:EIP line. | absent | absent | No action; preserve exact bounds and SS:ESP/EBP item at `0x0061981c`. | Same range/name/type and both comments absent. |
| `[0x0061981c,0x00619838)` | Name `aSsEsp04x08xEbp`; type absent; SS:ESP/EBP line. | absent | absent | No action; preserve exact bounds; do not merge with the segment item also beginning at boundary `0x00619838`. | Same range/name/type and both comments absent. |
| `[0x00619838,0x0061985c)` | Name `aDs04xEs04xFs04`; type absent; segment line. | absent | absent | No action; preserve exact bounds and flags/time item at `0x0061985c`. | Same range/name/type and both comments absent. |
| `[0x0061985c,0x00619881)` | Name `aFlags08xTimeDP`; type absent; flags/time/phase/RGB565 line. | absent | absent | No action; preserve exact bounds and separator item at `0x00619884`. | Same range/name/type and both comments absent. |
| `[0x00619884,0x006198b4)` | Name `asc_619884`; type `const char[]`; final separator. | absent | absent | No action; preserve exact item extent and all adjacent data. | Same range/name/type and both comments absent. |
| `[0x00619bd4,0x00619be1)` | Name `aCallStack`; type absent; fallback heading. | absent | absent | No action; preserve exact bounds and columns item at `0x00619be4`. | Same range/name/type and both comments absent. |
| `[0x00619be4,0x00619c0e)` | Name `aAddressFrameLo`; type absent; fallback columns. | absent | absent | No action; preserve exact bounds and frame-format item at `0x00619c10`. | Same range/name/type and both comments absent. |
| `[0x00619c10,0x00619c2b)` | Name `a08x08x04x08xWs`; type absent; fallback frame line. | absent | absent | No action; preserve exact bounds and executable-offset item at `0x00619c2c`. | Same range/name/type and both comments absent. |
| `[0x00619c2c,0x00619c32)` | Name `a08x`; type absent; executable-relative offset. | absent | absent | No action; preserve exact bounds and ImageHlp heading at `0x00619c34`. | Same range/name/type and both comments absent. |
| `[0x00619c34,0x00619c40)` | Name `aCallStack_0`; type absent; ImageHlp heading. | absent | absent | No action; preserve exact bounds; the address/frame item starts exactly at `0x00619c40`. | Same range/name/type and both comments absent. |
| `[0x00619c40,0x00619c4d)` | Name `a08x08x`; type absent; ImageHlp address/frame line. | absent | absent | No action; preserve exact bounds and symbol format at `0x00619c50`. | Same range/name/type and both comments absent. |
| `[0x00619c50,0x00619c58)` | Name `aHsX`; type absent; symbol plus displacement. | absent | absent | No action; preserve exact bounds; logical-fallback item starts exactly at `0x00619c58`. | Same range/name/type and both comments absent. |
| `[0x00619c58,0x00619c67)` | Name `a04x08xWs`; type absent; logical fallback line. | absent | absent | No action; preserve exact bounds and all following data through the next listed item. | Same range/name/type and both comments absent. |
| `[0x00619c94,0x00619c98)` | Name `off_619C94`; type absent; wide `IMAGEHLP.DLL` pointer/item. | absent | absent | No action; preserve this exact four-byte item and do not reinterpret or merge neighboring data. | Same range/name/type and both comments absent. |
| `[0x00619cb0,0x00619cbe)` | Name `aSyminitialize`; type `const CHAR[]`; `SymInitialize`. | absent | absent | No action; preserve exact bounds and `SymCleanup` item at `0x00619cc0`. | Same range/name/type and both comments absent. |
| `[0x00619cc0,0x00619ccb)` | Name `aSymcleanup`; type `const CHAR[]`; `SymCleanup`. | absent | absent | No action; preserve exact bounds and `StackWalk` item at `0x00619ccc`. | Same range/name/type and both comments absent. |
| `[0x00619ccc,0x00619cd6)` | Name `aStackwalk`; type `const CHAR[]`; `StackWalk`. | absent | absent | No action; preserve exact bounds and function-table item at `0x00619cd8`. | Same range/name/type and both comments absent. |
| `[0x00619cd8,0x00619cef)` | Name `aSymfunctiontab`; type `const CHAR[]`; `SymFunctionTableAccess`. | absent | absent | No action; preserve exact bounds and module-base item at `0x00619cf0`. | Same range/name/type and both comments absent. |
| `[0x00619cf0,0x00619d01)` | Name `aSymgetmoduleba`; type `const CHAR[]`; `SymGetModuleBase`. | absent | absent | No action; preserve exact bounds and symbol-address item at `0x00619d04`. | Same range/name/type and both comments absent. |
| `[0x00619d04,0x00619d16)` | Name `aSymgetsymfroma`; type `const CHAR[]`; `SymGetSymFromAddr`. | absent | absent | No action; preserve exact bounds and options item at `0x00619d18`. | Same range/name/type and both comments absent. |
| `[0x00619d18,0x00619d26)` | Name `aSymsetoptions`; type `const CHAR[]`; `SymSetOptions`. | absent | absent | No action; preserve exact bounds and all following data. | Same range/name/type and both comments absent. |

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is an exact source-bearing method with resolved owner, source method name, return/parameter type, helper decomposition, local roles, and behavior.
- Recommended code: replace the target's metadata/formal with the following exact block. This code deliberately retains observed failure behavior rather than correcting it.

```cpp
*** UID:00014G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00014D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00014D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *pExceptionInfo)
{
    wchar_t windowsDirectory[MAX_PATH];
    wchar_t reportPath[MAX_PATH];
    g_pfnGetWindowsDirectoryW(windowsDirectory, MAX_PATH);
    swprintf_s(reportPath, MAX_PATH, L"%s\\%s",
               windowsDirectory, L"BCrash.nfo");

    FILE *pReportFile = g_pfnWideOpenFile(reportPath, L"wt");
    if (pReportFile != NULL) {
        fprintf(pReportFile, "%d.%d.Eng.R\n",
                g_pApplication->GetVersionMajor(),
                GetExecutableVersionLowWord());
    }

    EXCEPTION_RECORD *pExceptionRecord = pExceptionInfo->ExceptionRecord;
    wchar_t faultingModule[MAX_PATH];
    DWORD sectionNumber;
    DWORD sectionOffset;
    GetLogicalAddress(pExceptionRecord->ExceptionAddress,
                      faultingModule,
                      MAX_PATH,
                      sectionNumber,
                      sectionOffset);

    CONTEXT *pContext = pExceptionInfo->ContextRecord;
    (void)GetExceptionString(pExceptionRecord->ExceptionCode);

    if (pReportFile != NULL) {
        char ansiText[1024];
        LPTSTR exceptionText =
            GetExceptionString(pExceptionRecord->ExceptionCode);
        WideCharToMultiByte(CP_ACP,
                            0,
                            exceptionText,
                            static_cast<int>(wcslen(exceptionText) + 1),
                            ansiText,
                            sizeof(ansiText),
                            NULL,
                            NULL);
        fprintf(pReportFile,
                "Exception code: %08X %s\n",
                pExceptionRecord->ExceptionCode,
                ansiText);

        WideCharToMultiByte(CP_ACP,
                            0,
                            faultingModule,
                            static_cast<int>(wcslen(faultingModule) + 1),
                            ansiText,
                            sizeof(ansiText),
                            NULL,
                            NULL);
        fprintf(pReportFile,
                "Fault address:  %08X %02X:%08X %s\n",
                pExceptionRecord->ExceptionAddress,
                sectionNumber,
                sectionOffset,
                ansiText);

        fprintf(pReportFile, "\nRegisters:\n");
        fprintf(pReportFile,
                "EAX:%08X\nEBX:%08X\nECX:%08X\nEDX:%08X\n"
                "ESI:%08X\nEDI:%08X\n",
                pContext->Eax,
                pContext->Ebx,
                pContext->Ecx,
                pContext->Edx,
                pContext->Esi,
                pContext->Edi);
        fprintf(pReportFile,
                "CS:EIP:%04X:%08X\n",
                pContext->SegCs,
                pContext->Eip);
        fprintf(pReportFile,
                "SS:ESP:%04X:%08X  EBP:%08X\n",
                pContext->SegSs,
                pContext->Esp,
                pContext->Ebp);
        fprintf(pReportFile,
                "DS:%04X  ES:%04X  FS:%04X  GS:%04X\n",
                pContext->SegDs,
                pContext->SegEs,
                pContext->SegFs,
                pContext->SegGs);
        fprintf(pReportFile,
                "Flags:%08X Time:%d Phase:%d 565:%d\n\n",
                pContext->EFlags,
                g_timerCurrentTickMirror - g_timerTickBaselineMirror,
                g_applicationPhaseState,
                g_surfaceUsesRgb565Pixels);
    }

    if (InitImagehlpFunctions()) {
        ImagehlpStackWalk(pContext, pReportFile);
        m_symCleanup(GetCurrentProcess());
    } else {
        IntelStackWalk(pContext, pReportFile);
    }

    fputs("-----------------------------------------------", pReportFile);
    if (pReportFile != NULL) {
        fflush(pReportFile);
        fclose(pReportFile);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID00014G H block disposition: keep the method-child H channel exactly empty. The single declaration `void GenerateExceptionReport(EXCEPTION_POINTERS *pExceptionInfo);` belongs inside the complete `ExceptionHandler` class declaration in UID00004P H; repeating it in this child would create a duplicate or out-of-class declaration.

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- Existing child destination: [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md). Preserve `COMPLETION:94`, `CONFIDENCE:94`, `CANONICAL_OWNER:00004P`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004P`. Its following exact formal block is already present and remains current; no page creation or UID allocation is required:

```cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BOOL ExceptionHandler::InitImagehlpFunctions()
{
    HMODULE imageHlp = g_pfnLoadLibraryW(L"IMAGEHLP.DLL");
    if (imageHlp == NULL) {
        return FALSE;
    }

    m_symInitialize =
        (SYMINITIALIZEPROC)GetProcAddress(imageHlp, "SymInitialize");
    if (m_symInitialize == NULL) {
        return FALSE;
    }

    m_symCleanup =
        (SYMCLEANUPPROC)GetProcAddress(imageHlp, "SymCleanup");
    if (m_symCleanup == NULL) {
        return FALSE;
    }

    m_stackWalk =
        (STACKWALKPROC)GetProcAddress(imageHlp, "StackWalk");
    if (m_stackWalk == NULL) {
        return FALSE;
    }

    m_symFunctionTableAccess =
        (SYMFUNCTIONTABLEACCESSPROC)GetProcAddress(
            imageHlp,
            "SymFunctionTableAccess");
    if (m_symFunctionTableAccess == NULL) {
        return FALSE;
    }

    m_symGetModuleBase =
        (SYMGETMODULEBASEPROC)GetProcAddress(imageHlp, "SymGetModuleBase");
    if (m_symGetModuleBase == NULL) {
        return FALSE;
    }

    m_symGetSymFromAddr =
        (SYMGETSYMFROMADDRPROC)GetProcAddress(imageHlp, "SymGetSymFromAddr");
    if (m_symGetSymFromAddr == NULL) {
        return FALSE;
    }

    DWORD (WINAPI *symSetOptions)(DWORD) =
        (DWORD (WINAPI *)(DWORD))GetProcAddress(imageHlp, "SymSetOptions");
    if (symSetOptions != NULL) {
        symSetOptions(7);
    }

    return m_symInitialize(GetCurrentProcess(), NULL, TRUE) != FALSE;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0004WT H block disposition: keep the method-child H channel exactly empty. The single declaration `BOOL InitImagehlpFunctions();` belongs inside UID00004P H; this child owns only the retained out-of-line definition in CPP.

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- This exact resolver formal preserves all six required short-circuit failures, optional `SymSetOptions(7)`, `SymInitialize(GetCurrentProcess(), NULL, TRUE)`, and the Nexus-specific absence of `FreeLibrary` on failure. The zero-xref retained copy is emitted once through its exact child because the source call was inlined into UID00014G; zero xrefs do not make the retained source definition non-emitting.

- Existing child destination: [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md). Preserve `COMPLETION:94`, `CONFIDENCE:94`, `CANONICAL_OWNER:00004P`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004P`. The corrected formal shown below is installed and read back in the current ordinary CPP block; no page creation or UID allocation was required:

```cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ExceptionHandler::IntelStackWalk(CONTEXT *pContext,
                                      FILE *pReportFile)
{
    wchar_t executablePath[MAX_PATH];
    if (pReportFile != NULL) {
        BuildExecutablePathForVersionInfo(executablePath, MAX_PATH);
        fprintf(pReportFile, "Call stack:\n");
        fprintf(pReportFile,
                "Address   Frame     Logical addr  Module\n");
    }

    DWORD instructionPointer = pContext->Eip;
    DWORD *pFrame = (DWORD *)pContext->Ebp;

    for (;;) {
        wchar_t moduleName[MAX_PATH];
        moduleName[0] = L'\0';
        DWORD sectionNumber = 0;
        DWORD sectionOffset = 0;
        GetLogicalAddress((PVOID)instructionPointer,
                          moduleName,
                          MAX_PATH,
                          sectionNumber,
                          sectionOffset);

        if (pReportFile != NULL) {
            fprintf(pReportFile,
                    "%08X  %08X  %04X:%08X %ws\n",
                    instructionPointer,
                    pFrame,
                    sectionNumber,
                    sectionOffset,
                    moduleName);

            if (_wcsicmp(moduleName, executablePath) == 0) {
                fprintf(pReportFile, "%08X\n", sectionOffset);
            }
        }

        instructionPointer = pFrame[1];
        DWORD *pPreviousFrame = pFrame;
        pFrame = (DWORD *)pFrame[0];

        if (((DWORD_PTR)pFrame & 3) != 0 ||
            pFrame <= pPreviousFrame ||
            IsBadWritePtr(pFrame, sizeof(DWORD) * 2)) {
            break;
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0004WU H block disposition: keep the method-child H channel exactly empty. The single declaration `void IntelStackWalk(CONTEXT *pContext, FILE *pReportFile);` belongs inside UID00004P H; this child owns only the retained out-of-line definition in CPP.

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- This corrected formal is installed and `APPLIED_VERIFIED` in UID0004WU by validator `17466` and current generated command `17510`. It preserves initial EIP/EBP use, optional executable-path/header setup, per-frame `GetLogicalAddress`, exact `%08X  %08X  %04X:%08X %ws\n` and executable-offset formats, frame update order, 4-byte alignment test, strictly increasing frame test, and `IsBadWritePtr(frame, 8)` termination. Security-cookie mechanics are compiler output and the 15-byte successor pad remains parent-only.

- Existing child destination: [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md). Callback readback confirms the `94/94` metadata, retained behavior/evidence, and corrected installed ordinary CPP. The formal below is the current `APPLIED_VERIFIED` block:

```cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ExceptionHandler::ImagehlpStackWalk(CONTEXT *pContext,
                                         FILE *pReportFile)
{
    wchar_t executablePath[MAX_PATH];
    if (pReportFile != NULL) {
        BuildExecutablePathForVersionInfo(executablePath, MAX_PATH);
        fprintf(pReportFile, "Call stack\n");
        fprintf(pReportFile,
                "Address   Frame     Logical addr  Module\n");
    }

    STACKFRAME stackFrame;
    memset(&stackFrame, 0, sizeof(stackFrame));
    stackFrame.AddrPC.Offset = pContext->Eip;
    stackFrame.AddrPC.Mode = AddrModeFlat;
    stackFrame.AddrStack.Offset = pContext->Esp;
    stackFrame.AddrStack.Mode = AddrModeFlat;
    stackFrame.AddrFrame.Offset = pContext->Ebp;
    stackFrame.AddrFrame.Mode = AddrModeFlat;

    DWORD sectionNumber;

    while (m_stackWalk(IMAGE_FILE_MACHINE_I386,
                       GetCurrentProcess(),
                       GetCurrentThread(),
                       &stackFrame,
                       pContext,
                       NULL,
                       m_symFunctionTableAccess,
                       m_symGetModuleBase,
                       NULL)) {
        if (stackFrame.AddrFrame.Offset == 0) {
            break;
        }

        if (pReportFile != NULL) {
            fprintf(pReportFile,
                    "%08X  %08X  ",
                    stackFrame.AddrPC.Offset,
                    stackFrame.AddrFrame.Offset);
        }

        char symbolStorage[sizeof(IMAGEHLP_SYMBOL) + 512];
        PIMAGEHLP_SYMBOL pSymbol =
            (PIMAGEHLP_SYMBOL)symbolStorage;
        pSymbol->SizeOfStruct = sizeof(symbolStorage);
        pSymbol->MaxNameLength = 512;

        DWORD displacement = 0;
        if (m_symGetSymFromAddr(GetCurrentProcess(),
                                stackFrame.AddrPC.Offset,
                                &displacement,
                                pSymbol)) {
            if (pReportFile != NULL) {
                fprintf(pReportFile,
                        "%hs+%X\n",
                        pSymbol->Name,
                        displacement);
            }
        } else {
            wchar_t moduleName[MAX_PATH];
            moduleName[0] = L'\0';
            sectionNumber = 0;
            DWORD sectionOffset = 0;
            GetLogicalAddress((PVOID)stackFrame.AddrPC.Offset,
                              moduleName,
                              MAX_PATH,
                              sectionNumber,
                              sectionOffset);

            if (pReportFile != NULL) {
                fprintf(pReportFile,
                        "%04X:%08X %ws\n",
                        sectionNumber,
                        sectionOffset,
                        moduleName);
            }
        }

        if (pReportFile != NULL) {
            wchar_t moduleName[MAX_PATH];
            moduleName[0] = L'\0';
            DWORD sectionOffset = 0;
            GetLogicalAddress((PVOID)stackFrame.AddrPC.Offset,
                              moduleName,
                              MAX_PATH,
                              sectionNumber,
                              sectionOffset);
            if (_wcsicmp(moduleName, executablePath) == 0) {
                fprintf(pReportFile, "%08X\n", sectionOffset);
            }
        }
    }

    if (pReportFile != NULL) {
        fprintf(pReportFile, "\n");
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID00014J H block disposition: keep the method-child H channel exactly empty. The single declaration `void ImagehlpStackWalk(CONTEXT *pContext, FILE *pReportFile);` belongs inside UID00004P H; this child owns only the out-of-line definition in CPP.

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- UID00004P class-channel migration was applied during the supervisor-authorized narrow ordinary callback. UID00004P has no separate class-level implementation source: all method definitions belong to exact child CPP pages. Its CPP block is exact blank:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID00004P H now contains the existing six callback typedefs, complete class declaration, exact `0x828` size assertion, and `[[CHILDREN]]` once, with no duplicate declarations in CPP or method-child H blocks:

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef BOOL (WINAPI *SYMINITIALIZEPROC)(HANDLE, PCSTR, BOOL);
typedef BOOL (WINAPI *SYMCLEANUPPROC)(HANDLE);
typedef BOOL (WINAPI *STACKWALKPROC)(
    DWORD,
    HANDLE,
    HANDLE,
    LPSTACKFRAME,
    PVOID,
    PREAD_PROCESS_MEMORY_ROUTINE,
    PFUNCTION_TABLE_ACCESS_ROUTINE,
    PGET_MODULE_BASE_ROUTINE,
    PTRANSLATE_ADDRESS_ROUTINE);
typedef PVOID (WINAPI *SYMFUNCTIONTABLEACCESSPROC)(HANDLE, DWORD);
typedef DWORD (WINAPI *SYMGETMODULEBASEPROC)(HANDLE, DWORD);
typedef BOOL (WINAPI *SYMGETSYMFROMADDRPROC)(
    HANDLE,
    DWORD,
    PDWORD,
    PIMAGEHLP_SYMBOL);

class ExceptionHandler
{
public:
    ExceptionHandler();
    virtual ~ExceptionHandler();

    void SetReportText(const wchar_t *text);
    void SendStoredCrashReportFile();
    void SendCrashDiagnosticText(const char *text);
    void GenerateExceptionReport(EXCEPTION_POINTERS *pExceptionInfo);
    BOOL InitImagehlpFunctions();
    void IntelStackWalk(CONTEXT *pContext, FILE *pReportFile);
    void ImagehlpStackWalk(CONTEXT *pContext, FILE *pReportFile);

    bool ShouldSkipCrashReport() const
    {
        return m_skipCrashReport;
    }

    LPTOP_LEVEL_EXCEPTION_FILTER PreviousFilter() const
    {
        return m_previousFilter;
    }

private:
    static LPTSTR GetExceptionString(DWORD dwCode);
    static bool GetLogicalAddress(
        PVOID address,
        PTSTR moduleName,
        DWORD moduleNameLength,
        DWORD &sectionNumber,
        DWORD &sectionOffset);

    bool m_skipCrashReport;
    LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter;
    DWORD m_reserved0C;
    SYMINITIALIZEPROC m_symInitialize;
    SYMCLEANUPPROC m_symCleanup;
    STACKWALKPROC m_stackWalk;
    SYMFUNCTIONTABLEACCESSPROC m_symFunctionTableAccess;
    SYMGETMODULEBASEPROC m_symGetModuleBase;
    SYMGETSYMFROMADDRPROC m_symGetSymFromAddr;
    wchar_t m_reportText[0x400];
};

typedef char ExceptionHandlerSizeMustBe0x828[
    sizeof(ExceptionHandler) == 0x828 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- The second executable-relative `GetLogicalAddress` call intentionally resets its module buffer and offset but reuses `sectionNumber`. On symbol failure, that value is the preceding zero-initialized/logical-address result; on symbol success before any failure path, it retains the binary's uninitialized stack state. The Boolean result is ignored and only the offset/path comparison is consumed. The body preserves the 536-byte symbol storage (`sizeof(IMAGEHLP_SYMBOL) + 512`), `SizeOfStruct = 536`, `MaxNameLength = 512`, exact legacy `STACKFRAME`, one caller, symbol/logical fallback, and trailing blank line.
- Reference-call rule for all four call sites: the declaration takes `DWORD &sectionNumber, DWORD &sectionOffset`; calls therefore pass `sectionNumber, sectionOffset` directly. Defect-bearing command `17440` and the old ordinary hashes are retained only as historical invalid implementation state; command `17467` is the earlier repaired callback checkpoint. Current validators `17465`/`17466`/`17467` and current generated command `17510` prove the corrected calls.
- Split/emitter rule: exact children UID0004WT, UID0004WU, and UID00014J each emit one helper definition through CPP, while UID00014G emits one `GenerateExceptionReport` definition through CPP. Their H channels remain exact blank. UID00014D remains blank in both channels as a child-only aggregate. UID00004P alone owns the header typedefs, complete class declaration, size assertion, and H-channel `[[CHILDREN]]`; UID0000J8 remains the source root. Current ordinary readback and generated command `17510` prove the complete source-channel topology and corrected call-level implementation without duplicate declarations or bodies.

- Exact behavior preservation: order, ignored return values, uninitialized first logical-address outputs, duplicate exception-string call, ANSI conversion, ImageHlp/fallback choice, cleanup, unconditional separator, and conditional flush/close all match the binary.
- Human source shape: source-level helper calls match the MSJ class design and explain compiler inlining without reproducing raw offsets/decompiler temporaries.
- Source-facing names: no `sub_`, `unk_`, `a1`, `vNN`, raw field offset, or decompiler cast remains.
- Style: late-1990s/mid-2000s Win32/CRT conventions, `NULL`, `MAX_PATH`, `FILE *`, Win32 typedefs, and straightforward class helpers.
- Third-party import directive: not applicable; this is Nexus-adapted project source, not a static third-party source embed.
- Reason code should remain blank: not applicable.

## Final Recommendation

- Retain target score `94/96`, exact blank-H disposition, corrected Windows-directory behavior, source identity, source/helper decomposition, ABI, local/global/callback types, failure behavior, boundaries, historical corrections, and the `APPLIED_VERIFIED` direct-reference formal.
- Keep target owner/emitter/reconstructable metadata unchanged; routing and implementation evidence are complete.
- Retain `94/94` for UID0004WT and UID0004WU, both routed through owner/emitter UID00004P with exact blank H channels. UID0004WT's CPP is unaffected; UID0004WU's corrected CPP is `APPLIED_VERIFIED`.
- Retain `94/94` for UID00014J and its exact blank H channel; its corrected CPP is `APPLIED_VERIFIED`. UID00014D/file/filter/meta/source-tree support remains synchronized at report-level detail, UID0002AS/UID0000TQ now contain the complete UID00014G consumer package, and UID00014H/UID00014I remain protected already-correct dependencies.
- Retain the narrow-callback source-channel result: UID00004P's exact typedefs, complete class declaration, size assertion, and `[[CHILDREN]]` are in H exactly once; UID00004P CPP is exact blank; all four method definitions remain only in `ExceptionHandler.cpp`; all four method-child H blocks remain exact blank with destination-level reasoning.
- Supervisor Gate 2B is complete: the `f085b224`/2C20-bound action table was applied, every protected entity was verified, the IDB was saved/read back, and the stable 3EB6 post-save checkpoint is recorded in this report. Fresh exact-artifact Gate 1/final continuity, supervisor `execute_report`, and supervisor coverage remain pending.
- No target or source-ready helper item remains no-owner, non-emitting, deferred as future research, or blocked on ordinary implementation. The four method-child H channels are intentionally blank because UID00004P owns their declarations once; UID00014D remains blank in both channels because it is a child-only aggregate.

## Recommended Target Doc Changes

- Path: `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`; current SHA256 `F50638A0FACB0711E9A58F69596AE2CC77DC29F718EDF349D8DA3A6E3DEE7327`. Gate-1 pre-callback SHA `8225B374...AC4`, earlier SHA `A517E721...13187`, and historical callback SHA `C968278A...80EB0` remain provenance.
- Current artifact retains metadata `94/96`, owner UID00014D, reconstructable true, emitter UID00014D, exact range, non-nested status, exact blank H by design, and the `APPLIED_VERIFIED` corrected CPP definition.
- Current prose uses `ExceptionHandler::GenerateExceptionReport` while retaining the stable path and includes exact bytes/hash/CFG/caller/callee/local/global/literal/boundary/helper-inlining/source-lineage facts.
- Current behavior records Windows-directory output plus duplicate `GetExceptionString`, ignored returns, null-stream behavior, no `FreeLibrary`, and uninitialized outputs.
- `WriteCrashReport`, `InitializeImageHlp`, `WriteImageHlpStackWalk`, current-directory wording, `int` return, and inline-monolith source remain preserved only as superseded historical assumptions.

## Recommended Support Doc Changes

- UID0004WT Init child current SHA `3007C9CB...1C78E` retains `94/94`, owner/emitter UID00004P, reconstructable true, exact range, source file UID0000J8, zero-xref retained/inlined disposition, three-byte successor padding exclusion, exact CPP definition, exact blank H channel, and explicit centralized-declaration reasoning.
- UID0004WU Intel child current SHA `C5646EE5...D431` retains metadata `94/94`, owner/emitter UID00004P, reconstructable true, exact 89-instruction range, source file UID0000J8, zero-xref retained/inlined disposition, 15-byte successor padding exclusion, exact blank H channel, and `APPLIED_VERIFIED` corrected CPP.
- UID00014D aggregate current SHA `1C425053...18F5` is callback content plus only the validator H header. Retain `90/94`, exact `GenerateExceptionReport`, UID0004WT, UID0004WU, and UID00014J routes, exact padding, unrelated raw-helper caps, both formal channels blank under the child-only policy, and historical assumptions.
- UID00014F filter current SHA `C3D960B3...1088` is callback content plus only the validator H header. Retain `90/94`, exact `GenerateExceptionReport` call identity, live caller/prototype evidence, callback behavior, ownership, CPP definition, and blank H for the file-static function.
- UID00014J helper current SHA `B18E0620...214E` retains metadata `94/94`, `void ExceptionHandler::ImagehlpStackWalk(CONTEXT *pContext, FILE *pReportFile)`, exact blank H channel, explicit centralized-declaration reasoning, exact 667-byte behavior, one caller, field offsets, formats, section-reset asymmetry, five-byte padding, and `APPLIED_VERIFIED` corrected CPP. This report does not claim additional UID00014J report coverage.
- UID00004P class current SHA `A2B25B6A...3C62` retains `93/95`; its six typedefs, complete class declaration, fields/offsets/size assertion, natural alignment, `m_reserved0C`, vtable/compiler exclusions, and `[[CHILDREN]]` occur exactly once in H, while CPP is exact blank. Child H channels do not duplicate declarations.
- UID0000J8 file is callback-verified at `92/94` with exact source lineage, corrected Windows-directory path, helper decomposition/inlining, Nexus differences, UID0004WT/UID0004WU/UID00014J routes, closed target-relevant blockers, `NexusTK/platform/` placement, and child-only emission.
- UID000259, UID0001QB, and UID0001R1 now contain their accepted target-specific diagnostic-literal, crash-meta, and source-tree synchronization without unrelated score/path changes.
- UID0002AS SHA `5CBFFB53...EAE41F` and UID0000TQ SHA `38D5AE8F...648CD` now contain report-level UID00014G consumer detail for `_wfopen` at `0x0069be14`, `LoadLibraryW` at `0x0069be30`, and `GetWindowsDirectoryW` at `0x0069be7c`, including exact call sites and behavior while preserving PlatformApi ownership. UID0002GP/2JX/2JZ, UID0002AR tick pages, UID00028Z, UID00029U, and UID000294 were verified and require no target-driven edit.
- No `-coverage-report.md` file may be edited by B001. Exact supervisor payloads follow.

## Score And Metadata Recommendation

- Target assignment-time baseline: `86/91`, owner/emitter UID00014D, reconstructable true, blank formal.
- Current target metadata/formal pair is `94/96`, same owner/emitter/reconstructable state, exact blank H whose declaration is centralized in UID00004P H, and `APPLIED_VERIFIED` ordinary/generated CPP.
- Reason `94/96` is not lower: exact function/range/hash/CFG/caller, complete runtime behavior, exact public source-family names/decomposition, resolved ABI/locals/callback types/globals, exact source placement, corrected destination C++, serial scoped validation, and generated readback.
- Reason not higher: no original Nexus PDB/source/map and no rebuilt binary comparison; Nexus-specific local/global spellings remain high-probability source-facing inference.
- Blocker `WriteCrashReport` name: exact source lineage resolves to `GenerateExceptionReport`.
- Blocker `int` return: source lineage and caller behavior resolve to `void`.
- Blocker report directory: exact table address resolves `GetWindowsDirectoryW`.
- Blocker helper identities/liveness: exact source names plus retained copies/inline semantic duplicates resolve source methods and inlining.
- Blocker helper splits/formals: resolved and `APPLIED_VERIFIED` through existing UID0004WT/UID0004WU/UID00014J children, class-owned emitter routes, parent-only padding, four corrected CPP definitions, four exact blank child H dispositions, and one complete UID00004P H declaration package.
- Blocker callback fields: GetProcAddress strings and call sites resolve all six prototypes.
- Blocker locals: frame/data-flow audit resolves arrays and protects lifetime-coalesced slots.
- Blocker no-code/empty emitter: resolved by complete ordinary formals and current generated command `17510`; no target/helper empty marker remains.
- Support scores recommended only where this report closes material target-family caps; unrelated support scores remain unchanged.

## Open Questions With Attempted Resolution

- Original method name: resolved to `GenerateExceptionReport` through exact source-family match; no unresolved impact.
- Original helper names: resolved to `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk`; no unresolved impact.
- Report directory: resolved to Windows directory through exact slot `0x0069be7c`; former current-directory wording rejected.
- Return/parameter types: resolved to `void` and `EXCEPTION_POINTERS *`.
- Callback typedefs: resolved to exact 32-bit legacy signatures from export names/call use.
- Source helper calls versus inline bodies: resolved to ordinary helper calls with compiler inlining from retained zero-xref definitions and ancestor source.
- `MultiByteStr` extent conflict: resolved as source-lifetime reuse of `char[1024]`; the one safe Gate 2B operation was rename-only to `ansiText`. Supervisor persisted readback verifies the retained IDA `CHAR` type, 504-byte represented extent, `String2` at `0x628`, and all neighboring offsets.
- `InitImagehlpFunctions` body/split/emitter: resolved on existing UID0004WT `[0x004ac040,0x004ac0ed)`, `94/94`, UID00004P owner/emitter, and the current formal above.
- `IntelStackWalk` body/split/emitter: resolved and applied on existing UID0004WU `[0x004ac0f0,0x004ac221)`, `94/94`, UID00004P owner/emitter, and the corrected formal above; 89 instructions, `ret 8`, zero xrefs, and inline duplicate are fully accounted for.
- `ImagehlpStackWalk` body: resolved and applied on existing UID00014J at `94/94` with the corrected formal above; no independent blank-formal or call-site work remains.
- CPP/H source placement: resolved and applied. Definitions remain on the four method-child CPP pages; their H channels are exact blank. UID00004P alone owns the six typedefs, complete class declaration, size assertion, and `[[CHILDREN]]` in H, while UID00004P CPP is exact blank. Current ordinary and generated command-17510 readback prove both the source-channel split and call-level correctness.
- Exact Nexus-specific identifier spelling: original proof is unavailable, but coherent project names are selected and documented. This is a confidence cap, not a code blocker and not permission to retain IDA labels.
- No research, ordinary implementation, or Gate 2B question remains unresolved. Remaining work is supervisor-owned fresh exact-artifact Gate 1/final continuity, `execute_report`, and post-execution manual coverage.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected current manual rows in `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-global/-coverage-report.md` for every score/path/source-quality support destination.
- B001 must not edit these files. After report execution/archive, the supervisor should apply these exact replacements.
- `by-memory/-coverage-report.md` line containing UID00014D, replace with:

`    - [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) : reconstructable : 90% : very-strong : ExceptionHandler aggregate with exact bounds and complete child/raw/data/padding inventory; source-lineage-backed GenerateExceptionReport, InitImagehlpFunctions, IntelStackWalk, ImagehlpStackWalk, GetExceptionString, and GetLogicalAddress identities; exact callback types, Windows-directory BCrash.nfo route, inlining/retained-helper disposition, parent class route, and blank child-only aggregate formal.`

- UID00014F replacement:

`    - [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) : reconstructable : 90% : very-strong : Exact file-static LONG WINAPI filter with constructor callback xref, no ordinary callers, keyboard restore, suppress-report gate, source-lineage-backed ExceptionHandler::GenerateExceptionReport call, previous-filter chain, one-byte padding, parent route, and complete formal C++.`

- UID00014G replacement:

`    - [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) : reconstructable : 94% : very-strong : Source-ready void ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *) with exact 1184-byte bounds/hash/sole caller, Windows-directory BCrash.nfo path, version/exception/register/timer/phase/RGB565 output, duplicate exception-string call, legacy ImageHlp setup, source helper/inlining disposition, x86 EBP fallback, exact cleanup/null-stream quirks, and complete formal C++.`

- UID0004WT insertion: this is a new row, not a replacement. Insert it in address order immediately after the current UID00014I row and before UID0004WU/UID00014J:

`    - [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md) : reconstructable : 94% : very-strong : Exact 173-byte retained ExceptionHandler::InitImagehlpFunctions source method with six required ImageHlp export resolutions, optional SymSetOptions(7), SymInitialize, Nexus no-FreeLibrary failure behavior, zero-xref/inlined-copy disposition, complete formal C++, and three-byte successor-padding exclusion.`

- UID0004WU insertion: this is a new row, not a replacement. Insert it in address order immediately after the new UID0004WT row and before the current UID00014J row:

`    - [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md) : reconstructable : 94% : very-strong : Exact 305-byte/89-instruction retained ExceptionHandler::IntelStackWalk source method with first 55/push-ebp and terminal C2-08-00/retn-8 bytes, zero-xref/inlined-copy disposition, x86 EBP-chain validation and formatting, corrected formal C++, and fifteen-byte successor-padding exclusion.`

- UID00014J replacement (after the two insertions above):

`    - [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) : reconstructable : 94% : very-strong : Source-ready void ExceptionHandler::ImagehlpStackWalk(CONTEXT *, FILE *) with exact 667-byte bounds, sole GenerateExceptionReport caller, complete legacy STACKFRAME/callback formal, 536-byte symbol storage, symbol-or-logical-address output, preserved section-reset asymmetry, executable-relative offset handling, and five-byte tail padding.`

- `by-class/-coverage-report.md` UID00004P replacement:

`- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) : reconstructable : 93% : very-strong : Complete 0x828 crash-handler declaration with GenerateExceptionReport, InitImagehlpFunctions, IntelStackWalk, ImagehlpStackWalk, exact GetExceptionString/GetLogicalAddress methods, six typed legacy ImageHlp callbacks, stored-report/diagnostic methods, skip/filter accessors, report buffer, source-owned g_pCrashTarget, complete child routing, and compiler-wrapper exclusions.`

- `by-file/-coverage-report.md` UID0000J8 replacement:

`- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) : reconstructable : 92% : very-strong : NexusTK/platform/ExceptionHandler.cpp source union with complete 0x828 class, g_pCrashTarget, stored-report sender, top-level filter, source-lineage-backed GenerateExceptionReport and three stack/ImageHlp helpers, exact Windows-directory BCrash.nfo behavior, typed callbacks, child order/inlining disposition, and compiler-only vtable/EH/scalar-wrapper exclusions.`

- `by-global/-coverage-report.md` UID0000TQ row requires no replacement because its score/path/description already covers all 47 slots. The ordinary support callback is complete: UID0002AS and UID0000TQ now contain report-level UID00014G consumer detail for `_wfopen` slot `0x0069be14`, `LoadLibraryW` slot `0x0069be30`, and `GetWindowsDirectoryW` slot `0x0069be7c`. This support-doc work does not alter the manual UID0000TQ coverage row.
- No validator-owned auto-generated tracker text is supplied or edited.

## Follow-Up Actions

- Supervisor Gate 1 passed exact pre-callback artifact SHA256 `6191A9F031A514853C26444CC0350C945DBF92C6EFAF738A85B6A7DD1B43D4B4` before this narrow implementation callback.
- Historical ordinary callback: all four revoked-callback partials were independently rebased, accepted behavior/evidence/score/CPP-body claims were applied/read back, UID0004WT/UID0004WU were created, all changed files were serially scoped-validated, and all leases were released. Validator migration `17353` subsequently added empty H headers; command `17367` is historical.
- Historical narrow callback: B001 moved UID00004P's exact declaration package from CPP to H, left UID00004P CPP blank, preserved the four source-body CPP blocks and exact blank child H channels, added destination-level blank-H reasoning, ran serial scoped validators `17378`/`17379`/`17381`/`17382`/`17383`, released every lease, and verified generated checkpoint `17384`. Those syntax validators did not detect that three call-bearing CPP blocks pass addresses to C++ reference parameters.
- Supervisor exact-artifact continuity: freshly verify this reconciled report, the five exact destination hashes and validators `17465`-`17469`, current generated command `17510`, four direct-reference calls, complete three-slot support package, persisted Gate 2B checkpoint `3EB64AC3...A1AD79D`, and ordered UID0004WT/UID0004WU coverage insertions.
- Authorized ordinary callback: complete. UID00014G, UID0004WU, and UID00014J pass `sectionNumber, sectionOffset`; UID0002AS and UID0000TQ contain the exact three-slot UID00014G consumer detail; validators passed; leases were released; current generated command `17510` has no invalid address-of invocation tokens, and command `17467` remains the earlier repaired callback checkpoint. UID0004WT and UID00004P required no call-level edit.
- Supervisor Gate 2B: `APPLIED_VERIFIED`. The supervisor used the verified 2C20 prestate/backup, applied the exact action set, preserved every no-action entity, saved/read back the IDB, and recorded stable post-save SHA `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`.
- Supervisor lifecycle: execute/archive only after fresh exact-artifact Gate 1/final continuity passes; Gate 2A implementation and Gate 2B IDA closure are complete. After execution, apply the exact manual coverage replacements plus UID0004WT/UID0004WU insertions.
- No A-agent action is required.
- B001 future research/ordinary implementation: none for UID00014G or the three source-ready helpers. Research, source-channel placement, reference-call repair, support synchronization, validators, generated readback, and supervisor Gate 2B are complete; only fresh supervisor exact-artifact continuity, lifecycle, and manual coverage remain.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong.
- Runtime-behavior confidence: very strong from complete target decompile/CFG/bytes and dependency checks.
- Source-shape confidence: very strong for method/helper decomposition and names; strong for Nexus-specific identifier spelling.
- Remaining uncertainty: exact original Nexus spelling and eventual compiler/rebuild equivalence only. No unresolved research or ordinary/generated implementation defect remains.

## Validator Results

- Historical accepted-callback command `000000017307`: `python .\tools\validator.py --mode file --file by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md --apply --queue-timeout 240`; exit `0`; `ok:1`; artifact last-write readback `2026-07-24T12:23:36.7623056-04:00`.
- Historical accepted-callback command `000000017309`: `python .\tools\validator.py --mode file --file by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md --apply --queue-timeout 240`; exit `0`; `ok:1`; artifact last-write readback `2026-07-24T12:23:51.8642339-04:00`.
- Historical accepted-callback command `000000017311`: `python .\tools\validator.py --mode file --file by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md --apply --queue-timeout 240`; `2026-07-24T12:24:59-04:00`; exit `0`; `ok:1`.
- Historical accepted-callback command `000000017318`: `python .\tools\validator.py --mode file --file by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md --apply --queue-timeout 240`; `2026-07-24T12:26:24-04:00`; exit `0`; `ok:1`.
- Historical accepted-callback command `000000017325`: `python .\tools\validator.py --mode file --file by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md --apply --queue-timeout 240`; `2026-07-24T12:27:17-04:00`; exit `0`; `ok:1`.
- Historical accepted-callback command `000000017328`: `python .\tools\validator.py --mode file --file by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md --apply --queue-timeout 240`; `2026-07-24T12:28:34-04:00`; exit `0`; `ok:1`.
- Historical accepted-callback command `000000017330`: `python .\tools\validator.py --mode file --file by-class/ExceptionHandler.md --apply --queue-timeout 240`; exit `0`; `ok:1`; artifact last-write readback `2026-07-24T12:30:19.7592070-04:00`.
- Historical accepted-callback command `000000017333`: `python .\tools\validator.py --mode file --file by-file/ExceptionHandler.md --apply --queue-timeout 240`; exit `0`; `ok:1`; artifact last-write readback `2026-07-24T12:31:41.9485848-04:00`.
- Historical accepted-callback command `000000017335`: `python .\tools\validator.py --mode file --file by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md --apply --queue-timeout 240`; exit `0`; `ok:1`; artifact last-write readback `2026-07-24T12:33:37.4304051-04:00`.
- Historical accepted-callback command `000000017336`: `python .\tools\validator.py --mode file --file by-meta/client_crash_diagnostics.md --apply --queue-timeout 240`; exit `0`; `ok:1`; artifact last-write readback `2026-07-24T12:34:20.3035746-04:00`.
- Historical accepted-callback command `000000017338`: `python .\tools\validator.py --mode file --file by-project-structure/proposed-source-tree.md --apply --queue-timeout 240`; exit `0`; `ok:1`; artifact last-write readback `2026-07-24T12:34:50.5784727-04:00`. Its warnings are pre-existing missing references UID0003LP/UID0003WL/UID0003WM/UID0003WN/UID0003WO and are unrelated to UID00014G.
- Validator-owned H-channel migration command/batch `000000017353`, `tools/validator_migrations/reconstruction_h/20260724T195403-0400-000000017353`: its `backup/`, `files/`, manifest, and apply journal prove that UID0004WT, UID0004WU, UID00014D, UID00014G, UID00014F, UID00014J, UID00004P, and UID000259 changed only by insertion of the two empty H-channel marker lines (+140 bytes/+2 lines each). This was not run by B001.
- Historical generated command `000000017367`, refreshed `2026-07-24T20:02:22-04:00`, produced CPP SHA `9EC2B969...F3AB8`, 20645 bytes, 601 lines, with UID00004P declarations still in CPP and no generated H. It is the accepted Gate-1 pre-callback checkpoint, not current output. Command `000000017338` generated SHA `37707F15...26BC` and revoked-callback commands `000000017274`, `000000017278`, `000000017280`, and `000000017281` are earlier historical provenance only.
- Narrow-callback command `000000017378`, timestamp `2026-07-24T21:07:14-04:00`: `python .\tools\validator.py --mode file --file by-class/ExceptionHandler.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; current ordinary SHA `A2B25B6A93D46C750DD1E1C55B2A45A685162D30BC30D927C556194D734D3C62`.
- Narrow-callback command `000000017379`, timestamp `2026-07-24T21:07:38-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; current ordinary SHA `8225B374D5931289CF91764CE27B601D9EB026AC8C190678053C11C9BCAE7AC4`.
- Narrow-callback command `000000017381`, timestamp `2026-07-24T21:08:05-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; current ordinary SHA `3007C9CBB29D0E667731F85F01099FC5C2D97E112C072A617FE7F16B32B1C78E`.
- Narrow-callback command `000000017382`, timestamp `2026-07-24T21:08:48-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; current ordinary SHA `2F1DF6FC3153B7751BF05CD7CFE2749BBDDD35CCA87A3285FE5056AAE0EF7742`.
- Narrow-callback command `000000017383`, timestamp `2026-07-24T21:09:13-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; current ordinary SHA `572FF68FFE5B9A1994AD91123B5D53C4A4B1050B9C2503E511DFC0E906C000EB`.
- Generated callback checkpoint command `000000017384`, refreshed `2026-07-24T21:09:24-04:00`, first proved the accepted split: CPP SHA `AB23FC61DD687E459135D63CE8AD6F8EA90E356924DF0C1F2E42949CA5A2DAED`, 18715 bytes, 533 lines; H SHA `F92525D56B075B19B000991B2FD3A4B3ECD6331C7A9EE30D067CCB5896902B80`, 2370 bytes, 76 lines.
- Current callback command `000000017465`, timestamp `2026-07-24T23:45:33-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; autogen registry updated UID00014G; current SHA `F50638A0FACB0711E9A58F69596AE2CC77DC29F718EDF349D8DA3A6E3DEE7327`.
- Current callback command `000000017466`, timestamp `2026-07-24T23:46:00-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; autogen registry updated UID0004WU; current SHA `C5646EE510AD7AABD385F7C43C07431EF0904AC717BF90C491A7EACC3BBCD431`.
- Current callback command `000000017467`, timestamp `2026-07-24T23:46:32-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; autogen registry updated UID00014J; current SHA `B18E0620B51153FEA4307857F1B580F137EB7B60B84410D38342BAF54E56214E`.
- Current callback command `000000017468`, timestamp `2026-07-24T23:47:27-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; UID00014G reference-index entry added; current SHA `5CBFFB535441C962F8191C0D3B9EFA13F2A442BC7DC9BE81A253707FBEEAE41F`.
- Current callback command `000000017469`, timestamp `2026-07-24T23:48:55-04:00`: `python .\tools\validator.py --mode file --file by-global/WideApiDispatchTable.md --apply --queue-timeout 240`; exit `0`; `ok:1`; warnings none; UID00014G reference-index entry added; current SHA `38D5AE8F13771444C3F3784C2B7319F3C988834348923A6D8B8E7B543C9648CD`.
- Current generated physical-file metadata is command `000000017510`, refreshed `2026-07-25T04:52:56-04:00`, as embedded in both headers: CPP SHA `0F2CAD462252019F0A6EA5A1C18C2452D1530BB3A76DA4C9665FA82BB6D7D2D2`, 18707 bytes, 533 lines; H SHA `0CF1F1ACBF0AF1470516BFC32C340577A2C1C65BC53E6B1961E6E7D228575D30`, 2370 bytes, 76 lines. CPP has no UID00004P declaration package, one marker and one qualified definition each for UID00014G/UID0004WT/UID0004WU/UID00014J, zero empty markers for those four, four direct-reference calls, and zero invalid `&sectionNumber`/`&sectionOffset` invocation arguments. H has one UID00004P marker, each callback typedef once, one class, one size assertion, one declaration per method including exactly one `GetLogicalAddress` declaration, and no method definition. Command `17440` is the historical defect-bearing checkpoint; command `17467` is the earlier repaired callback checkpoint; `17414`/`17434`/`17447`/`17449` remain earlier provenance.
- No validator was run during the historical D99/48EB/B6A2/9F6E/CB62/9DF/7509 or current `f085b224`/2C20 report-only IDA rebase. B001 ran only scoped file validators `17465` through `17469` during the earlier authorized callback and ran no report lifecycle command.
- No validator was run for this supervisor-result report reconciliation; none is required because only this report changed.

## Changed Files

- Modified and serially scoped-validated by B001 during the narrow callback: UID00004P `by-class/ExceptionHandler.md`, SHA256 `A2B25B6A93D46C750DD1E1C55B2A45A685162D30BC30D927C556194D734D3C62`, 31478 bytes, 261 lines, validator `17378`; declaration package moved to H, CPP exact blank.
- Modified and serially scoped-validated by B001 during the current callback: UID00014G `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`, SHA256 `F50638A0FACB0711E9A58F69596AE2CC77DC29F718EDF349D8DA3A6E3DEE7327`, 28916 bytes, 269 lines, validator `17465`; one call now passes `sectionNumber, sectionOffset` directly, while metadata, behavior, source-channel routing, and blank H remain unchanged. Historical defect-bearing SHA `8225B374...AC4` / validator `17379` is retained only as provenance.
- Modified and serially scoped-validated by B001 during the narrow callback: UID0004WT `by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md`, SHA256 `3007C9CBB29D0E667731F85F01099FC5C2D97E112C072A617FE7F16B32B1C78E`, 9819 bytes, 153 lines, validator `17381`; method body unchanged, blank-H reason added.
- Modified and serially scoped-validated by B001 during the current callback: UID0004WU `by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md`, SHA256 `C5646EE510AD7AABD385F7C43C07431EF0904AC717BF90C491A7EACC3BBCD431`, 9455 bytes, 145 lines, validator `17466`; its one call now passes reference arguments directly, with metadata/evidence/blank H/padding dispositions preserved. Historical defect-bearing SHA `2F1DF6FC...F7742` / validator `17382` is provenance only.
- Modified and serially scoped-validated by B001 during the current callback: UID00014J `by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md`, SHA256 `B18E0620B51153FEA4307857F1B580F137EB7B60B84410D38342BAF54E56214E`, 18519 bytes, 227 lines, validator `17467`; both calls now pass reference arguments directly, with metadata/evidence/blank H/asymmetry/caller/padding dispositions preserved. Historical defect-bearing SHA `572FF68F...00EB` / validator `17383` is provenance only.
- Modified and serially scoped-validated by B001 during the current callback: UID0002AS `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`, SHA256 `5CBFFB535441C962F8191C0D3B9EFA13F2A442BC7DC9BE81A253707FBEEAE41F`, 23839 bytes, 142 lines, validator `17468`; added exact UID00014G consumer evidence/cross-reference/history for slots `0x0069be14`, `0x0069be30`, and `0x0069be7c`, preserving metadata, formal, score, and PlatformApi ownership.
- Modified and serially scoped-validated by B001 during the current callback: UID0000TQ `by-global/WideApiDispatchTable.md`, SHA256 `38D5AE8F13771444C3F3784C2B7319F3C988834348923A6D8B8E7B543C9648CD`, 42081 bytes, 276 lines, validator `17469`; added exact UID00014G consumer rows/evidence/cross-reference/history for the same three slots, preserving metadata, formal, score, initializer, and ownership.
- Preserved unchanged: UID00014D `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`, SHA256 `1C4250534B8053725310D6FB8A25322FCE32EB379CFA914CCAFDC8FF1F2218F5`, 43349 bytes, 250 lines; CPP/H both exact blank.
- Preserved unchanged: UID00014F `by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md`, SHA256 `C3D960B31CBC11271BA1ECD48626BEFFEFC13F4AE6B2A791B0FD48FD21C91088`, 17022 bytes, 187 lines; file-static CPP definition and blank H retained.
- Preserved unchanged: UID000259 `by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`, SHA256 `AEE358891C85393043E11D87B88BF289196D647B065851BACCD5F00EB1FB9B51`, 24336 bytes, 149 lines; CPP/H both exact blank.
- Preserved unchanged: UID0000J8 `by-file/ExceptionHandler.md`, SHA256 `348DD3C8560ED44A0AF16BF2CB22816D1F51F360A05C6163F6305F7F9747F12C`, 27899 bytes, 174 lines; UID0001QB `by-meta/client_crash_diagnostics.md`, SHA256 `2B4BCB03E7997EEFDBA0C359D8FF655455A217681F6D62EE791537C9C427BFDA`, 15492 bytes, 80 lines; UID0001R1 `by-project-structure/proposed-source-tree.md`, SHA256 `7D780058F841B3DDA1CF8BC72ADC520F65CD4EA730B3B30ACC55EA1E475BE73D`, 310112 bytes, 2113 lines.
- Current generated validator side effects, never hand-edited: physical-header command `000000017510`, refreshed `2026-07-25T04:52:56-04:00`; `auto-generated/NexusTK/platform/ExceptionHandler.cpp` SHA256 `0F2CAD462252019F0A6EA5A1C18C2452D1530BB3A76DA4C9665FA82BB6D7D2D2`, 18707 bytes, 533 lines; `auto-generated/NexusTK/platform/ExceptionHandler.h` SHA256 `0CF1F1ACBF0AF1470516BFC32C340577A2C1C65BC53E6B1961E6E7D228575D30`, 2370 bytes, 76 lines. CPP has one marker/definition each for UID00014G/UID0004WT/UID0004WU/UID00014J, zero target/helper empty markers, four direct-reference calls, and zero invalid address-of invocation arguments; H has the single declaration package, exactly one `GetLogicalAddress` declaration, and no definitions. Defect-bearing command `17440`, repaired callback checkpoint `17467`, callback checkpoint `17384`, pre-migration `17367`, and older checkpoints remain historical provenance.
- Support callback complete: UID0002AS and UID0000TQ now contain the exact UID00014G `_wfopen`/`LoadLibraryW`/`GetWindowsDirectoryW` consumer package. Verify-only supports UID00014H/UID00014I, UID0002GP/UID0002JX/UID0002JZ, UID0002AR tick pages, UID00028Z, UID00029U, and UID000294 required no target-driven edit.
- Historical 7509 rebase mutation scope: during that report-only pass B001 changed only this same report, used live MCP read-only, and changed no ordinary/support/coverage/generated/tracker/audit/goal/supervisor/validator/lifecycle file or IDB. B001's later `f085b224`/2C20 prestate-rebase scope was identical: this report only, MCP read-only, no IDA mutation, no validator, and no lifecycle command. The supervisor-owned Gate 2B mutation/save is recorded separately below, and the earlier authorized five-document callback remains recorded above; the exact reconciled report artifact hash is returned outside this self-referential document.
- Supervisor Gate 2B IDB result: verified backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-00014G-20260725_230500.bak`; prestate IDB SHA `2C20AAD81BC18DE1FA91B04D7FBEC30A704D377E6E2A2E35344C06EAEE479BC0`, size `143186196`; `idb_save ok`; stable post-save SHA `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`, size `143186768`, last write `2026-07-25T23:14:42.2666509-04:00`.
- Supervisor Gate 2B applied/read back: four accepted function identities/prototypes/comments including exact raw-helper creation; target argument and six local identities; six size-4 callback typedefs with semantically exact IDA `__stdcall` canonicalization; exact 12-member/`0x828` UDT callback typing; seven bounded global names/types/comments; and the RGB565 comment. Protected fragmented spans, PlatformApi neighbors, six functions, nine imports, locals/UDT members, zero bytes/xref totals, and 3/15/5-byte fences remained exact.
- Supervisor audit/catalog entries for this Gate 2B result now exist and remain supervisor-owned; B001 did not edit them during reconciliation.
- B001 report-reconciliation renames: none. The accepted IDA renames/types/comments were applied by the supervisor during Gate 2B.
- IDA mutation: supervisor Gate 2B `APPLIED_VERIFIED` and persisted; B001's own IDA use remained read-only.
- Lease state: current callback leases for all five ordinary docs were acquired only immediately before each edit and released immediately after validators `17465` through `17469`; no lease remains. This same-report reconciliation acquired no lease and edited no external file.
- Report execution: not run; B001 did not run, probe, dry-run, or invoke any report lifecycle command.

## Implementation Tracking Checklist

Gate 1, revoked-callback rebase, and current callback:

- [x] Historical supervisor exact-artifact Gate 1 validation passed report SHA256 `C4CE14D2079CAFF3D6BB92E48AA11C73C31536C992724A9B4E63EDB4F59A4899` before the earlier resumed ordinary edits; supervisor separately passed exact repaired pre-narrow-callback artifact SHA256 `E887A1B3B9A11A30C2C31804525A25518013029E186E3C024B8AA46800F3AB51`.
- [x] Rebased and independently verified all four preserved revoked-callback partials; repaired/completed them where C14G-01 through C14G-43 required it.
- [x] Reapplied and verified the affected ordinary portions of C14G-25/C14G-26/C14G-30/C14G-32/C14G-38/C14G-39/C14G-42 after exact Gate 1 report SHA `6191A9F0...3D4B4`; all other accepted ordinary claims and C14G-28/C14G-41 remain preserved. Supervisor Gate 2B subsequently completed C14G-34/C14G-35/C14G-43; only C14G-33 manual coverage remains pending.
- [x] Repaired UID00014G's ordinary CPP to pass `sectionNumber, sectionOffset`, ran scoped validator `17465`, and verified current generated command `17510`; metadata/routing and the exact blank H block remain preserved. Generated command `17467` remains the earlier repaired callback checkpoint.
- [x] Incorporated exact range/hash/CFG/caller/callee/literal/local/global/failure/source-lineage evidence into UID00014G without summarizing it away.
- [x] Corrected Windows-directory behavior and historicalized current/client-directory wording.
- [x] Historicalized `WriteCrashReport`, `InitializeImageHlp`, `WriteImageHlpStackWalk`, `int` return, and decompiler-inline source shape.
- [x] Synchronized UID00014D to `90/94` with exact helper identities and retained-range/inlining disposition.
- [x] Synchronized UID00014F to `90/94` and replaced ordinary/formal `WriteCrashReport` use with `GenerateExceptionReport`.
- [x] Historical callback record: created/scoped-validated the now-existing UID0004WT at `by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md`, `94/94`, owner/emitter UID00004P, reconstructable true, exact CPP definition, exact blank H channel, and three-byte successor-pad exclusion.
- [x] Repaired UID0004WU's existing ordinary CPP to pass `sectionNumber, sectionOffset`, ran scoped validator `17466`, and verified current generated command `17510`; its UID/range/metadata/evidence/blank H/padding dispositions remain preserved.
- [x] Repaired UID00014J's two ordinary CPP calls to pass `sectionNumber, sectionOffset`, ran scoped validator `17467`, and verified current generated command `17510`; its metadata/evidence/blank H/asymmetry/caller/padding dispositions remain preserved.
- [x] Replaced UID00014D aggregate-only/raw helper rows with UID0004WT/UID0004WU links while keeping UID00014D blank in both formal channels and child-only.
- [x] Synchronized UID00004P to `93/95`, preserved the exact declarations, six callback typedefs, and `0x828` layout, then moved the declaration package into H exactly once and left CPP exact blank.
- [x] Synchronized UID0000J8 to `92/94` with exact source-family/Nexus-difference/helper-inlining findings.
- [x] Updated UID000259/UID0001QB/UID0001R1 only for accepted missing target-specific identity/path facts.
- [x] Added report-level UID00014G consumer detail to UID0002AS and UID0000TQ for `_wfopen` slot `0x0069be14`, `LoadLibraryW` slot `0x0069be30`, and `GetWindowsDirectoryW` slot `0x0069be7c`; validators `17468`/`17469` and exact readback passed. UID00014H/14I, UID0002GP/2JX/2JZ, UID0002AR tick pages, UID00028Z, UID00029U, and UID000294 remain verify-only.
- [x] Preserved every historical/rejected assumption and negative finding in a clearly historical section.
- [x] Left every `-coverage-report.md` untouched by B001 and preserved exact supervisor payloads.
- [x] Ran one serial scoped file validator for every changed ordinary by-* destination and released each immediate lease afterward.
- [x] Verified current generated command `17510` has exactly one UID00014G body, no UID00014G empty marker, and no invalid address-of invocation arguments.
- [x] Verified current generated command `17510` has exactly one body each for UID0004WT/UID0004WU/UID00014J, no empty markers for those helpers, all four `GetLogicalAddress` calls use reference arguments directly, and H contains exactly one `GetLogicalAddress` declaration.
- [x] Verified no duplicate target/helper body is emitted by UID00014D, UID00004P, UID0000J8, UID00014G, UID0004WT, UID0004WU, or UID00014J.
- [x] Re-read every affected callback destination and reconciled the supplied current physical generated `ExceptionHandler.cpp`/`.h` checkpoint to exact command `17510` hashes/metrics/invariants; preserved source-channel dispositions and historicalized defect-bearing command `17440`, repaired callback checkpoint `17467`, and older checkpoints.
- [x] Added separate exact CPP and H dispositions for UID00014G, UID0004WT, UID0004WU, and UID00014J, including destination-specific reasons their H channels remain blank.
- [x] Added exact UID00004P migration formals: CPP blank; H contains the six typedefs, complete class declaration, `0x828` size assertion, and `[[CHILDREN]]` once.
- [x] Implemented the UID00004P CPP-to-H migration and destination-level blank-H explanations in five ordinary docs, then ran serial scoped validators `17378`/`17379`/`17381`/`17382`/`17383` and released every lease.
- [x] Verified current generated `ExceptionHandler.h` contains the UID00004P declaration package once, generated CPP contains no UID00004P declaration package, and the four method definitions/body counts remain unchanged.
- [x] Supervisor Gate 1 accepted exact pre-callback report SHA `6191A9F031A514853C26444CC0350C945DBF92C6EFAF738A85B6A7DD1B43D4B4` and authorized the narrow callback.
- [x] Completed the authorized five-document callback covering three reference-call repairs plus UID0002AS/UID0000TQ consumer-link additions; exact destination hashes, validators, support content, and generated CPP/H counts are recorded above.
- [ ] Supervisor must complete final exact-artifact continuity: accept this reconciled report and independently verify the five current destination identities, validators `17465` through `17469`, support content, and current generated command `17510` CPP/H hashes, topology, and call/declaration counts.
- [x] Re-read every actionable and protected/no-action Gate 2B entity item by item through authoritative session `f085b224` against bounded saved-IDB observation 2C20; preserved all stable rows, rebased fragmented `0x0067ab1c`, protected fragmented `0x0067ab20`, protected fragmented `0x0067a93c`, and absent RGB565 comment state, and proved the filesystem hash stable before/after the final read-only pass.
- [x] Supervisor Gate 2B applied/verified every exact `f085b224`/2C20-bound actionable and protected/no-action entity, including bounded recreation only of `[0x0067ab1c,0x0067ab20)`, exact preservation of `[0x0067ab20,0x0067ab24)` and `[0x0067a93c,0x0067a940)`, restoration/readback of the RGB565 regular comment, all function/local/typedef/UDT/global actions, and every protected dependency/fence. Verified backup preceded mutation; `idb_save` returned `ok`; stable post-save SHA is `3EB64AC3C74D9FB2E2C208D41A7D033EF4193C17925C2D8D835B13FE2A1AD79D`.
- [ ] Supervisor must execute/archive the report only after this exact reconciled artifact passes fresh Gate 1/final continuity; Gate 2A and Gate 2B are complete. B001 must not run lifecycle commands.
- [ ] Supervisor must verify and apply exact target/support manual coverage replacements after report execution.

Historical Resumed Implementation Callback Pass

All checked acceptance and implementation rows in this subsection are historical records of the prior callback. Current callback and Gate 2B completion are recorded in the active checklist above; only fresh exact-artifact Gate 1/final continuity, lifecycle, and post-execution coverage remain unchecked.

- [x] Historical acceptance record: supervisor report acceptance was recorded before the resumed ordinary edits; the revoked acceptance was not reused.
- [x] Historical implementation record: immediate leases were acquired only for files being edited and released after each scoped validator; no lease remains.
- [x] Historical implementation record: all accepted behavior/evidence/score/CPP-body details were preserved at report-level detail, and the narrow callback applied only the accepted source-channel migration and blank-H explanations.
- [x] Historical verification record: claim-ledger destination/action/verification states were updated only after the then-current exact readback.
- [x] Historical artifact record: migration backups and five earlier narrow-callback ordinary results remain recorded; generated command `17467` remains the earlier repaired callback checkpoint and current generated CPP/H identity is physical-header command `17510` above.
- [x] Historical validator record: callback commands/results, validator-owned migration command `17353`, narrow-callback validators `17378`/`17379`/`17381`/`17382`/`17383`, generated checkpoint `17384`, defect-bearing command `17440`, and older shared-tree checkpoints are preserved with actor/lifecycle boundaries.
- [x] Current reconciliation readback record: physical command-17510 generated hashes/body/empty-marker/declaration/call counts and the absence of invalid invocation tokens are recorded; command `17467` is retained only as the earlier repaired callback checkpoint or scoped UID00014J validator where explicitly identified.
- [x] Current ordinary callback work is complete for UID00014G, UID0004WU, UID00014J, UID0002AS, and UID0000TQ; UID00004P migration, destination-level blank-H reasoning, and lease release remain complete.
- [x] Historical read-only IDA-prestate record: the earlier 9DF- and 7509-bound passes remain preserved as provenance; B001 did not apply IDA changes. The current `f085b224`/2C20 prestate and supervisor-persisted 3EB6 Gate 2B result are recorded in the active checklist above.
- [x] Current report reconciliation leaves only fresh exact-artifact Gate 1/final continuity, execution/archive, and post-execution coverage unclaimed in the explicit supervisor-owned rows above; Gate 2A and Gate 2B are complete.
- [x] B001 did not run/probe/dry-run `execute_report` or any report lifecycle command.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000017524","destination_path":"executed-b-agent-research/B001/00014G-ExceptionCrashReportWriter-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00014G-ExceptionCrashReportWriter-empty-emitter-source-quality.md","timestamp":"2026-07-25T23:26:01-04:00","uid":"00014G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
