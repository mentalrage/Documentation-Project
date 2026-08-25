** TARGET-REPORT-UID:00014I **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 00014I ExceptionLogicalAddressHelper Ownership / Split Research

## Finalized Report / Current Recommendation

- Implemented target path: [UID:00014I] `by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md`; the validator-aware UID-preserving rename removed the former `ExceptionLogicalAddressHelper` path while retaining UID00014I uniquely.
- Final disposition: reconstructable, source-authored, private static `ExceptionHandler::GetLogicalAddress` helper in [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp`, with [UID:00004P] retained as canonical owner/emitter.
- Implemented target state: `92/94`, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`, exact formal destination R1, and complete six-call-site/`GetModuleFileNameW` evidence. The former `86/91`, four-caller, unresolved-module-helper, and blank-formal state is historical pre-callback evidence.
- Return/source conclusion: NexusTK's binary returns an 8-bit Boolean in `AL`; use source-facing `bool`, not the published sample's 32-bit `BOOL`, while retaining the source-proven private static method name, `PVOID`, `PTSTR`, `DWORD` character-count parameter, and two `DWORD &` outputs.
- Split conclusion: no split or range change. Keep the predecessor switch island and both adjacent padding spans parent-only; the target is exactly `[0x004abfa0,0x004ac035)`.
- Confidence: very strong for behavior, range, ABI, six call sites, Win32/PE types, private static class ownership, method name, source file, and formal body; strong for the Nexus-specific `bool` adaptation because it is inferred from exact return-register code rather than a surviving Nexus declaration.
- B003 callback handoff state at this artifact epoch: `READY_FOR_SUPERVISOR_GATE2_REVIEW`. Later validation, coverage, execution, path, move, and archive state are external supervisor/validator-owned and are not asserted here.

## Supporting Research

- Mandatory live IDA MCP was healthy at evidence collection. A fresh streamable JSON-RPC session called `idb_list` and returned database `64c11373` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `21508`. `server_health` returned `status: ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and 2067 cached strings.
- Bounded live calls succeeded for `lookup_funcs`, `get_bytes`, `analyze_function`, `analyze_batch`, `xrefs_to`, `callees`, `insn_query`, `search_text`, and `decompile`. Evidence was collected between approximately `2026-07-16T11:50:21-04:00` and `2026-07-16T12:06:55-04:00`. A final fresh `idb_list`/`server_health`/16-byte target probe at `12:06:55` again returned database `64c11373`, worker PID `21508`, `status: ok`, all analysis caches ready, and bytes `55 8b ec 83 ec 1c 8d 45 e4 53 56 8b 75 08 57 6a`. These are evidence-time health facts, not an assertion that the session remains indefinitely available.
- One initial local PowerShell wrapper attempt used PowerShell's reserved `$args` name and therefore sent malformed empty arguments, producing local-client `database is required` responses. The wrapper was corrected to a nonreserved argument variable; all mandatory MCP checks then succeeded. The malformed local wrapper attempt is not target evidence and was not treated as an MCP outage.
- The configured executable is SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, size 2,679,296 bytes.
- The exact target bytes independently match the published Matt Pietrek `MSJEXHND` logical-address algorithm, but this report does not copy the source as authority. The binary independently proves every control-flow, PE-field, output, and failure behavior used in R1.
- Source/header leads checked:
  - `https://docs.polserver.com/doxygen/html/dc/dc4/msjexhnd_8cpp_source.html`
  - `https://docs.polserver.com/doxygen/html/d5/d59/msjexhnd_8h_source.html`
- The published header places `GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &)` under `private:` as a `static` class helper. The source identifies the original method name and PE algorithm. NexusTK independently changes the enclosing class name to `ExceptionHandler`, uses the Unicode dispatch slot for `GetModuleFileNameW`, passes the capacity as 260 characters, and returns through `AL`, so those Nexus-specific facts supersede blind source copying.
- The neighboring retained ImageHlp initializer at `0x004ac040` provides a same-file return-width control. Current IDA types it as `BOOL __thiscall`, and its epilogues use full-width `mov eax, 1` / `xor eax, eax`. UID00014I instead uses `mov al, 1` / `xor al, al`, making the Nexus-specific narrow Boolean return evidence materially stronger than IDA's provisional `char` label alone.
- Executed [UID:00014H] research is strong corroboration because it independently established the same `MSJEXHND` class/source lineage for adjacent private static `GetExceptionString`. Executed [UID:00014D] research remains useful for aggregate boundaries and raw-call inventory, but its file-static `GetLogicalAddress` conclusion is superseded by the exact header plus current live ABI evidence.

Historical-report searches used exact terms `00014I`, `0x004abfa0`, `ExceptionLogicalAddressHelper`, `GetLogicalAddress`, and `0069be74`:

| Search root | Outcome and target-specific classification |
| --- | --- |
| `tools/leaser/Agents/Agent-B001/research/**` | No matching active report. |
| `tools/leaser/Agents/Agent-B002/research/**` | No matching active report. |
| `tools/leaser/Agents/Agent-B003/research/**` | No pre-existing UID00014I artifact before this report. |
| `tools/leaser/Agents/Agent-B004/research/**` | No matching active report. |
| `tools/leaser/Agents/Agent-B005/research/**` | No matching active report. |
| `executed-b-agent-research/**` | Relevant support leads: B003 UID00014H, B005 UID00014D and UID000259, B015 UID00014F, B001 UID0002AS, and B007 UID0000FE. None is a dedicated UID00014I report. |
| `archived/**` | No match. |
| `tools/leaser/Agents/Older-Research/**` | No match. |
| `tools/leaser/Agents/SpecialReports/**` | No match. |

## Target

- Target UID: `00014I`.
- Historical pre-callback path: `by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md`.
- Implemented target path: `by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Callback authorization basis: supervisor exact-artifact Gate 1 acceptance of SHA-256 `12468238DDAB6137E5D29A2281CC3539D47A8B733A44BFE41CF69DC22442D8F3`.
- Implemented scores and parent state: `92/94`, owner/emitter [UID:00004P], reconstructable true, blank optional position, exact R1 formal C++, `Nested:0`.

## Current Target State

- UID00014I now has the exact renamed path, `92/94`, retained owner/emitter UID00004P, reconstructable true, blank optional position, `Nested:0`, exact accepted Item Summary, and R1 byte-for-byte equal to the accepted report block.
- The page now records the exact 149-byte hash/ABI/CFG, six calls, static no-`ECX` ABI, `AL` Boolean, 28-byte MBI, PlatformApi-owned `GetModuleFileNameW`, 260-character capacity, PE section walk, inclusive maximum extent, one-based section/offset outputs, failure mutations, source lineage, rejected alternatives, and both parent-only padding dispositions.
- UID00014D, UID00004P, UID0000J8, UID00014G, UID00014J, and UID0001QB now contain the accepted private-static/six-call/source-placement/caller-use synchronization without score, route, formal, layout, or unrelated-content loss.
- Historical pre-callback generated command/header `000000013892`, refreshed `2026-07-16T11:58:22-04:00`, SHA-256 `97BDE0D39A388DE151146B7C1EC00A9C7D072B4224BA22BE9210529BCBA69ECD`, 4,185 bytes, 114 lines, had one UID00014I Empty Emitter Marker, zero target definitions, and one stale title occurrence.
- B003 waited generated command/header `000000013981`, refreshed `2026-07-16T12:40:20-04:00`, produced `auto-generated/NexusTK/platform/ExceptionHandler.cpp` SHA-256 `E55C701ABBC7791552AF2464ED92DF43454C9F869C97BEC298800EEFF3456EA0`, 5,776 bytes, 155 lines. A later read-only external validator epoch advanced the header to command `000000013989`, refreshed `2026-07-16T12:45:15-04:00`, SHA-256 `019461C0ABB31E481907DF2C6C4AF5AB1D498D4D40499DB2F22A81471DCFF3AB`, with the same byte/line metrics and semantic assertions. Current readback has exactly one UID00014I `ExceptionHandler::GetLogicalAddress` definition, zero UID00014I Empty Emitter Markers, zero stale `ExceptionLogicalAddressHelper` text, no duplicate/wrong-range target body, and no handwritten vtable/RTTI/raw PE table source.
- The generated UID00004P class Empty Emitter Marker remains exactly one. That is independent broader class-declaration debt: the accepted callback added the exact private declaration in prose but deliberately retained a blank class formal because the unrelated `+0x0c` member and complete raw-helper declaration/access set remain unresolved.
- B003 modified only the seven accepted ordinary destinations and this report. B003 did not manually edit coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle files and did not run or probe report execution, count, move, archive, revalidation, or lifecycle commands.

Historical evidence-time ordinary/support snapshots:

| Path | SHA-256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md` | `E451797AB4497C32591C4974FD3C47999307B4AFD90967E83A511103FEF299F7` | 7,971 | 95 |
| `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md` | `45952D60EDDD39B233DA0DE6AAD88B704792D8D6A55CAB0325D94439B2945468` | 32,503 | 212 |
| `by-class/ExceptionHandler.md` | `0E68334304A9C0B5B6F30CFEDD6CD712B0CDDD05A2A5FC42165234419C6BA3FE` | 22,383 | 160 |
| `by-file/ExceptionHandler.md` | `3C01770C7E07CC15C38E968BD9FE0F08084CCA15D832AE163C3ED030A412AE7E` | 19,595 | 142 |
| `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md` | `4CE2CF3384D2177B002A084BE91A6FFCBFA9C129AB55521508A444FFDDE37569` | 14,385 | 107 |
| `by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md` | `1C5A5CA7F4AE2644E54F119C09AEE53E3FDAAECE1375BABA4CBE2F22BE7452D1` | 9,437 | 100 |
| `by-meta/client_crash_diagnostics.md` | `A52DFE06498225AE3F44CD2D33180EA726DCFB5B7AE593B9B22FDDC7CF695FA8` | 11,368 | 67 |
| `by-global/WideApiDispatchTable.md` | `CAD07BDEA56F1F8993A06B233A0A32594FC82DA2BE06B35897E019DB671149B4` | 39,280 | 267 |
| `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | `1A6EDC9EDA55DF7FF6C7B843C33B504B4B35E54D0DBE8CE2A46124F7CDCED367` | 21,099 | 134 |

Callback-time implemented ordinary snapshots:

| Path | SHA-256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md` | `9EA49167126B090D16F923B6F5DADBEBCEC11041D5B74B766C2633EA56FE567D` | 17,361 | 191 |
| `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md` | `3F425A8677102945947C0A40A45809DA23FE723675FFE93F946BA67A1EE4241B` | 35,921 | 225 |
| `by-class/ExceptionHandler.md` | `ABB673475B6B09B84581CEA86D935D6C1BA1BE02572D57CED8D2CA169BEB2A4D` | 24,658 | 172 |
| `by-file/ExceptionHandler.md` | `3506B3DC55D6E4F455C5D2E15C775DF786F3A49A4981B474E4B1198A6679CFF2` | 21,869 | 154 |
| `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md` | `A3F155F6FFFD07DB5CE7FF8E86B44236A600AE045026C80D466D541D65A0C7E2` | 16,501 | 118 |
| `by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md` | `C7982D0951072B44A9886A4700AC07ED45CB599A246EFA955BBDA780DE5B0970` | 11,443 | 112 |
| `by-meta/client_crash_diagnostics.md` | `25EF0221F59446AE9A5C0E696E871E43469CACE713824A2E119100916A76E932` | 13,725 | 75 |

Verify-only readback remained unchanged at callback time:

- UID0000TQ `by-global/WideApiDispatchTable.md`: SHA-256 `CAD07BDEA56F1F8993A06B233A0A32594FC82DA2BE06B35897E019DB671149B4`, 39,280 bytes, 267 lines.
- UID0002AS `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`: SHA-256 `1A6EDC9EDA55DF7FF6C7B843C33B504B4B35E54D0DBE8CE2A46124F7CDCED367`, 21,099 bytes, 134 lines.
- UID00014H `by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md`: SHA-256 `6AA763BEE93B5E1641B5B4D479CFEDF7928D7ADD50DF7725A5CD20B430AC3014`, 15,630 bytes, 182 lines.
- UID000259 `by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`: SHA-256 `3A2D77735793C877E809059CDC73B6075CCF580D41237A18AEC5E7EC8B32AB84`, 22,991 bytes, 145 lines.

## Executive Recommendation

- Retain [UID:00004P] as canonical owner/emitter because the published class header declares the exact helper private/static and current NexusTK ownership already adapts the enclosing name to `ExceptionHandler`.
- Retain [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp` as the final source file. Every target call site is inside the ExceptionHandler diagnostic aggregate, and the exact companion source lineage places this helper beside `GetExceptionString`, crash-report writing, and stack-walk code.
- Rename only the page/title, not the UID or range.
- Use `bool ExceptionHandler::GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &)` in source. Direct `AL` false/true returns outweigh the sample's 32-bit `BOOL` for the Nexus-specific return type.
- Preserve generic source-level `GetModuleFileName`, not raw `unk_69BE74` or `g_pfnGetModuleFileNameW`, inside R1. Current project convention and UID00014H use source-facing generic TCHAR APIs while the PlatformApi layer supplies the Unicode dispatch implementation.
- Apply exact R1 only to UID00014I. Keep UID00004P formal blank under the bounded class-level no-code proof; update its method inventory with the exact private static declaration.
- No new by-memory child, separate PE utility file, raw data emitter, or source import is justified.

## Supervisor Active Recheck

- The active assignment requires direct UID00014I research rather than treating UID00014D/UID00014H as substitutes; this report independently rechecked the complete target and only uses those reports as support.
- Split repair is not required before a final report. The target is one modeled function with exact predecessor and successor padding.
- Every source-bearing item directly required for the target model has a disposition:
  - UID00014I received R1 and the source-name rename;
  - UID00014D/UID00004P/UID0000J8/UID00014G/UID00014J/UID0001QB received bounded prose/link synchronization;
  - UID0000TQ/UID0002AS and Win32/PE declarations are already present at same-or-greater detail and remain verify-only;
  - raw parent-contained call sites remain parent evidence and do not require new child creation for this target.

## Inference Research Guidance Check

- Direct IDA facts control range, bytes, ABI, return register, caller count, call arguments, Win32 slot, PE offsets, output stores, CFG, and padding.
- Documentation evidence controls current UID ownership/emission routes, file path, class layout state, manual coverage rows, and generated output state.
- Source lineage controls the strongest human method name, private/static access, parameter family, and original developer structure only where the Nexus binary independently corroborates it.
- Inference is limited to the Nexus-specific choice of `bool`, parameter spelling refinements, and source-level generic `GetModuleFileName` expression. Each is explicitly distinguished from original-source proof.
- Existing uncertain or wrong assumptions reanalyzed:
  - four total callers;
  - unresolved `0x0069be74`;
  - file-static ownership;
  - `BOOL` automatically retained from the sample;
  - `wchar_t *`/integer-pointer descriptive signature;
  - no exact final C++.
- Wave2/Wave3 material was not used as authority. The historical `class_ExceptionHandler.cpp` route is context only; current by-file routing and live evidence control.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Resolution / classification |
| --- | --- | --- |
| Target name | Live IDA has only `sub_4ABFA0`; exact companion source/header and binary behavior match `GetLogicalAddress`. | Rename to `ExceptionHandlerGetLogicalAddress`; source method `ExceptionHandler::GetLogicalAddress`. Original method name is source-proven. |
| Class member versus file-static | No ECX is consumed, but static class methods do not use `this`. Exact header places this signature under `private:` as `static`; all six calls are inside the class diagnostic source family. | Private static class member. B005 file-static conclusion is historicalized. |
| Return type | Both failure epilogues use `xor al, al`; success uses `mov al, 1`. IDA types the result as `char`. All callers ignore it. Published source uses `BOOL`, but the same-file source-lineage `BOOL` initializer at `0x004ac040` returns through full-width `EAX`. | Nexus source changed the return to a one-byte Boolean; use `bool`, not `BOOL` or semantic `char`. This is very strong binary inference, not an original-symbol claim. |
| Calling convention | Five 4-byte stack arguments, no `this`, and `ret 0x14` prove callee cleanup. Adjacent UID00014H similarly omits explicit convention in source while compiling callee-cleaned under project settings. | Document binary `__stdcall` ABI; omit explicit calling-convention decoration from human source. |
| Address type | Caller values are exception/stack instruction addresses; `VirtualQuery` accepts `LPCVOID`; exact source uses `PVOID`. | Use `PVOID address`. |
| Module buffer type | All callers provide 260-element UTF-16 buffers; slot is `GetModuleFileNameW`; source family is TCHAR-based. | Use `PTSTR moduleName`. Under this build it is a writable wide buffer. |
| Capacity type/unit | All six calls push `0x104` / 260. The Win32 slot takes `DWORD size`; source comments define characters, not bytes. | Use `DWORD moduleNameLength`, measured in characters. Reject byte-count wording. |
| Output types | Function writes 32-bit one-based index and 32-bit RVA-relative offset; source header uses `DWORD &`. | Use `DWORD &sectionNumber`, `DWORD &sectionOffset`. |
| Section-number base | Success stores loop index plus one. | One-based section number. |
| PE headers | `AllocationBase + *(DWORD *)(base+0x3c)` is NT header; `+0x06` reads section count; `+0x14` reads optional-header size; first section is NT + 0x18 + optional size; stride 0x28. | Use `PIMAGE_DOS_HEADER`, `PIMAGE_NT_HEADERS`, `IMAGE_FIRST_SECTION`, `PIMAGE_SECTION_HEADER`. |
| Section size | Binary compares `SizeOfRawData` and `Misc.VirtualSize` and selects the larger via conditional move. | Use `std::max(sectionHeader->SizeOfRawData, sectionHeader->Misc.VirtualSize)`. |
| Containment | Binary accepts `rva >= sectionStart` and `rva <= sectionStart + maxSize`. | Preserve inclusive upper bound exactly, even though conventional ranges are often half-open. |
| Failure mutations | `VirtualQuery` failure occurs before any output mutation. `GetModuleFileName` may modify the module buffer before returning zero. Later PE/section failure leaves module text populated but does not write either DWORD output. | Document exact partial-output behavior; do not clear outputs inside R1. |
| Pointer validation | No explicit null checks exist for module buffer or output references; no DOS/NT signature validation or integer-overflow check exists. | Preserve source behavior and state caller preconditions. Do not modernize. |
| Module-path helper | Three initializer writes and four consumer calls produce seven xrefs to `0x0069be74`. Initializers load `GetModuleFileNameW`; consumers use `(HMODULE, LPWSTR, DWORD)`. | Slot is `GetModuleFileNameW`, owned by UID0000TQ/UID0002AS PlatformApi. |
| Generic API spelling | Current UID00014H formal uses generic `FormatMessage`/`GetModuleHandle` while docs resolve W dispatch slots. Exact source lineage likewise uses generic TCHAR APIs. | R1 uses `GetModuleFileName`, while prose records the W dispatch implementation. |
| Caller count | Live xrefs and bounded instruction query return six call sites. Current page's four are only the sites in two modeled caller functions. | State six total: four modeled plus two raw parent-contained calls. |
| Source file | All calls and adjacent companion methods are in ExceptionHandler diagnostics; exact source places the helper in the same class file. | `NexusTK/platform/ExceptionHandler.cpp`. Reject generic PE utility or PlatformApi ownership. |
| Class declaration debt | Exact helper declaration is solved. Full UID00004P formal remains unsafe because the Nexus class diverges materially from the sample, the `+0x0c` member has no current access proof, and unrelated raw helper declarations remain open. | Add exact declaration prose; leave UID00004P formal blank. This is bounded no-code proof, not target deferral. |
| C++ source shape | Target behavior and dependencies are complete, the emitter chain is valid, and callback validation generated the exact body. | R1 is installed on UID00014I and emitted exactly once by B003 waited command 13981 and current external header epoch 13989. |

Rejected alternatives:

- File-static `GetLogicalAddress`: rejected by the exact private static header declaration plus adjacent UID00014H class-name adaptation.
- Public member or nonstatic member: rejected by private source declaration and no incoming `this`/ECX use.
- 32-bit `BOOL` return: source-lineage lead only; contradicted by Nexus `AL`-only return code.
- `char` return: machine-compatible but semantically inferior to `bool`; no caller consumes a numeric character.
- `const void *`, `const wchar_t *`, `std::wstring`, or `SimpleUString`: source-inexact or incompatible with `VirtualQuery`/writable Win32 buffer behavior.
- `int *` outputs: ABI-compatible but weaker than exact 32-bit unsigned PE/source types and reference declaration.
- zero-based section index: contradicted by `index + 1`.
- half-open upper bound: contradicted by `jbe`/`<=`.
- `VirtualSize` only or `SizeOfRawData` only: contradicted by conditional maximum.
- raw `unk_69BE74`, local function pointer, or a module-path wrapper: contradicted by initializer identity and exact Win32 signature.
- hand-written DOS/NT offset arithmetic in final source: behaviorally possible but less source-faithful than Win32 PE declarations and `IMAGE_FIRST_SECTION`.
- a new `PeUtil.cpp`, `CrashDiagnostics.cpp`, `PlatformApi.cpp`, ImageHlp owner, runtime owner, or import owner: no independent callers/source root; all target calls remain inside ExceptionHandler diagnostics.
- clearing outputs at entry, rejecting a truncated path, validating PE signatures, or changing the inclusive boundary: modern safety changes not present in the binary.

## Evidence Standards Used

- Highest weight: current live MCP bytes, function analysis, CFG, disassembly, decompilation, caller/callee/xref inventories, slot initializer evidence, and bounded raw-helper listing.
- Strong corroboration: current by-memory/by-class/by-file/by-global docs, executed target-family reports, generated source, current manual coverage rows, and the exact adjacent source/header lineage.
- Negative evidence: no ECX use, no non-ExceptionHandler target call, no extra callee, no output writes on failure, no PE signature check, no buffer/output null check, no truncation check, no separate target data, no reason to split, and no independent source owner.
- Source comparison was accepted only where the current binary independently agrees. The return-type difference is explicitly resolved in favor of the binary.

## Evidence Checked

- IDA MCP/manual checks:
  - fresh `idb_list` and `server_health`;
  - `lookup_funcs` at target, end, predecessor/successor functions;
  - exact `get_bytes` for target, both pads, slot, initializer, and six caller windows;
  - `analyze_function` and `analyze_batch` for prototype, size, decompile, 67 instructions, 9 basic blocks, complexity 6, constants, callers, callees, and xrefs;
  - comparative `0x004ac040` analysis proving a same-file source-lineage `BOOL` helper returns full-width EAX rather than UID00014I's AL-only form;
  - `insn_query` for every call to `0x004abfa0` in the aggregate;
  - bounded caller decompilation for `0x004ab870` and `0x004ac230`;
  - bounded raw-helper disassembly for `0x004ac0f0-0x004ac221` and `0x004ac650-0x004ac859`;
  - bounded slot-xref listing for all seven `0x0069be74` refs.
- Current docs checked:
  - UID00014I, UID00014D, UID00004P, UID0000J8, UID00014G, UID00014J, UID0001QB;
  - UID0000TQ and UID0002AS dispatch-table docs;
  - UID00014H and UID000259 source/literal support;
  - proposed source tree and relevant generated/manual coverage.
- Historical reports checked only after exact-term search: UID00014H, UID00014D, UID000259, UID00014F, UID0002AS, UID0000FE.
- Source pages checked: `msjexhnd.cpp` and `msjexhnd.h` mirrors listed under Supporting Research.
- Negative checks:
  - no function at `0x004ac035`;
  - no seventh target call;
  - no target call outside `0x004ab480-0x004ac89a`;
  - no source-bearing bytes in either adjacent padding span;
  - no output-store path before successful section match;
  - no read of target return in any caller;
  - no current class-layout proof for the independent UID00004P `+0x0c` member.
- Failed or skipped checks: none material. IDA does not model the two raw callers or two alternate UniAPI initializer copies as functions, so bounded listing/raw-byte disassembly was used instead of Hex-Rays for those exact spans.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory live MCP evidence used healthy database `64c11373` at evidence time. | Very strong | Fresh idb_list, health, bounded target calls. | UID00014I Evidence/Changes | incorporate | applied | UID00014I `Evidence` and callback `Changes` preserve the exact evidence-time session/health/probe facts; validator `13966` accepted the page. |
| C02 | Exact target range is `[0x004abfa0,0x004ac035)`, size `0x95` / 149, SHA-256 `ceb8bc445299e5e1f8496c8033c79de83b9f185d7f4abffa634cc5749e666eaa`. | Very strong | lookup, bytes, hash, int_convert. | UID00014I range/evidence | incorporate | applied | UID00014I `ABI And Source Contract` and `Range And Padding`; final page SHA `9EA49167...FE567D`; command `13966`, exit 0, `ok:1`. |
| C03 | Function has 67 instructions, 9 basic blocks, 13 CFG edges inferred from the listed successors, and cyclomatic complexity 6. | Very strong | analyze_batch/analyze_function. | UID00014I CFG evidence | incorporate | applied | UID00014I exact shape/CFG evidence retained with 67/9/13/6; command `13966` passed. |
| C04 | ABI is a private static five-argument callee-cleaned method with 28-byte MBI stack local and `ret 0x14`; Nexus Boolean return is in `AL`. | Very strong | disassembly, stack frame, source header, full-EAX BOOL control at `0x004ac040`. | UID00014I/UID00004P | incorporate | applied | UID00014I `ABI And Source Contract` and UID00004P declaration synchronization; commands `13966` and `13971`, both exit 0/`ok:1`. |
| C05 | Final signature is `bool ExceptionHandler::GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &)`. | Very strong | binary ABI/types, exact source declaration, AL adaptation, same-file BOOL control. | UID00014I R1; UID00004P declaration prose | incorporate | applied | R1 is byte-for-byte equal between report and UID00014I; UID00004P contains the exact private static declaration; generated command `13981` emits one definition. |
| C06 | `VirtualQuery(address, &mbi, sizeof(mbi))` uses exact x86 size `0x1c` / 28 and supplies `AllocationBase`. | Very strong | bytes/decompile/import call. | UID00014I behavior/formal | incorporate | applied | UID00014I behavior/table/ABI and exact R1; command `13966` passed and generated readback preserves the call once. |
| C07 | Slot `0x0069be74` is `GetModuleFileNameW(HMODULE, LPWSTR, DWORD)`, zero-initialized storage owned by UID0000TQ/UID0002AS. | Very strong | seven xrefs, three initializer writes, current declarations. | UID00014I; UID0000TQ/UID0002AS verify-only | incorporate | applied | UID00014I, UID00014D, UID0000J8, and UID0001QB record the identity/ownership; UID0000TQ and UID0002AS hashes remained unchanged and were reread verify-only. |
| C08 | The module buffer capacity is in characters; every target call passes `0x104` / 260. | Very strong | six caller sequences, Win32 signature, source comment. | UID00014I/caller support | incorporate | applied | UID00014I six-row caller inventory plus UID00014G/UID00014J/UID0001QB support; commands `13966`, `13976`, `13978`, and `13980` passed. |
| C09 | PE parsing uses DOS `e_lfanew`, NT `NumberOfSections`, `SizeOfOptionalHeader`, `IMAGE_FIRST_SECTION` shape, and 40-byte section headers. | Very strong | exact offsets and stride. | UID00014I behavior/formal | incorporate | applied | UID00014I PE table/evidence and exact R1; generated command `13981` contains the source declarations and no raw PE table array. |
| C10 | RVA is `address - AllocationBase`; section extent is `max(SizeOfRawData, Misc.VirtualSize)`. | Very strong | decompile/disasm/source agreement. | UID00014I behavior/formal | incorporate | applied | UID00014I behavior/R1 and generated one-definition readback from command `13981`. |
| C11 | Containment uses an inclusive upper bound; success writes one-based section number and section-relative DWORD offset. | Very strong | branch/store instructions. | UID00014I behavior/formal | incorporate | applied | UID00014I behavior, caller contract, touched state, and exact R1 preserve `<=`, `index + 1`, and relative offset. |
| C12 | Failure before `GetModuleFileName` leaves all outputs untouched; later failure can leave module text populated while DWORD outputs remain untouched. | Very strong | CFG/store dominance and API order. | UID00014I mutation/preconditions | incorporate | applied | UID00014I caller/mutation prose and UID00014G/UID00014J support record exact caller-state consequences; all three validators passed. |
| C13 | There are six target calls: four in modeled functions and two in raw parent-contained helpers. | Very strong | xrefs_to and bounded insn_query count 6. | UID00014I Item Summary; UID00014D inventory | incorporate | applied | UID00014I Item Summary/caller table and UID00014D six-call/raw-helper synchronization; commands `13966` and `13968` passed. |
| C14 | Writer calls map fault address and frame address to 260-char buffers plus section/offset outputs; the fault call does not initialize its outputs before ignoring the Boolean result. | Very strong | writer decompile/disasm. | UID00014G/UID00014I | incorporate | applied | UID00014G exact `0x004ab939` and `0x004abc52` maps plus UID00014I caller table; command `13976` passed. |
| C15 | ImageHlp calls initialize both outputs on the first fallback, then repeat the same address with only offset reset before executable-path comparison. | Very strong | stack-walk decompile/disasm. | UID00014J/UID00014I | incorporate | applied | UID00014J exact `0x004ac3e1`/`0x004ac440` reset/use proof plus UID00014I caller table; command `13978` passed. |
| C16 | Raw calls at `0x004ac190` and `0x004ac7b4` preserve the same five-argument contract; raw2 only consumes offset after the call. | Strong | bounded raw disassembly and format-literal docs. | UID00014D/UID00014I | incorporate | applied | UID00014D raw-call paragraphs and UID00014I caller inventory; commands `13968` and `13966` passed. |
| C17 | Owner/emitter stays UID00004P and source file stays UID0000J8 `NexusTK/platform/ExceptionHandler.cpp`; generic PE/PlatformApi ownership is rejected. | Very strong | exact header, call cluster, current route. | target/class/file/meta | incorporate | applied | Metadata retained on UID00014I; UID00004P/UID0000J8/UID0001QB ownership/source sections synchronized; commands `13966`, `13971`, `13974`, and `13980` passed. |
| C18 | No split/range change; preserve predecessor switch data, four-byte pre-pad, eleven-byte post-pad, successor `0x004ac040`, and `Nested:0`. | Very strong | exact bytes/range inventory. | UID00014I/UID00014D | incorporate | applied | UID00014I `Range And Padding` and UID00014D inventory retain every span and no-split state; commands `13966`/`13968` passed. |
| C19 | Target should be renamed, raised `86/91 -> 92/94`, and receive exact formal R1; support scores/routes remain unchanged. | Strong | blocker closure and broader independent support debt. | target/support metadata | incorporate | applied | Validator `13966` reported `path_update`, completion 92, confidence 94, blank-to-block autogen update; old path absent, new path unique, support scores/routes unchanged, R1 parity exact. |
| C20 | Manual memory/class/file rows require exact no-loss replacements; generated callback proof must show one definition and zero target marker/old title. | Strong | current manual/generated snapshots. | manual handoff/checklist | incorporate | applied | Exact supervisor-owned handoff text remains unchanged below; B003 did not directly edit coverage. Waited command `13981` proves one definition, zero target marker, zero old title, no duplicate/wrong-range body, and current class marker disposition. |

## Positive Evidence Summary

- Exact target bytes, PE-field offsets, branch directions, output stores, and call sequences match the source-facing `GetLogicalAddress` algorithm.
- Exact source/header evidence supplies method name, private access, static membership, parameter family, references, and class/file placement.
- Adjacent UID00014H independently proves NexusTK adapted the same published class family into `ExceptionHandler`.
- The same-file `0x004ac040` helper demonstrates the compiler's full-EAX code shape for a genuine `BOOL`, isolating UID00014I's AL-only return as a real narrow-type distinction.
- Every target call is in the ExceptionHandler diagnostic cluster; no generic PE consumer exists.
- `0x0069be74` is proven by three independent initializer copies and a typed current declaration, not inferred from call shape alone.
- The target is fully eligible to emit through UID00004P -> UID0000J8 and has a complete human C++03 body.

## IDA MCP Facts

- Function: `sub_4ABFA0`, start `0x004abfa0`, size `0x95`, end-exclusive `0x004ac035`.
- IDA provisional prototype: `char __stdcall(char *lpAddress, int, int, _DWORD *, _DWORD *)`.
- Stack:
  - `MEMORY_BASIC_INFORMATION` at `[ebp-0x1c]`, size `0x1c`;
  - five 4-byte stack arguments;
  - `ret 0x14`.
- Instructions/CFG: 67 instructions, 9 blocks, 13 successor edges, cyclomatic complexity 6.
- Direct callees:
  - `VirtualQuery` import at `0x0060d2dc`;
  - dispatch slot `0x0069be74`.
- Target code xrefs:
  - `0x004ab939`;
  - `0x004abc52`;
  - `0x004ac190`;
  - `0x004ac3e1`;
  - `0x004ac440`;
  - `0x004ac7b4`.
- Constants:
  - `0x1c` / 28 MBI size;
  - `0x28` / 40 section-header stride;
  - `0x14` / 20 return pop;
  - `1` success value.
- Target SHA-256: `ceb8bc445299e5e1f8496c8033c79de83b9f185d7f4abffa634cc5749e666eaa`.
- Predecessor padding SHA-256 over four `0xcc` bytes: `8843b54d2df63ca265cf4a05d27dd2b29a74fb476d296dd44a0e171d74b441ca`.
- Successor padding SHA-256 over eleven `0xcc` bytes: `3682c0a62515050101266cc639bf81f5d8c5395f49e7da93fcc22603018e0943`.
- Combined `[0x004abf9c,0x004ac040)` SHA-256: `8462e26d5b3c2436f186f46a571d776c3dea72a6ec4a2b53fb8b01dfb8745fc5`.

Exact target bytes:

```text
55 8b ec 83 ec 1c 8d 45 e4 53 56 8b 75 08 57 6a
1c 50 56 ff 15 dc d2 60 00 85 c0 74 53 ff 75 10
8b 7d e8 ff 75 0c 57 ff 15 74 be 69 00 85 c0 74
3f 8b 47 3c 2b f7 03 c7 33 d2 0f b7 48 14 03 c8
0f b7 40 06 89 45 08 85 c0 74 25 8d 41 28 66 90
8b 78 fc 8b 08 8b 58 f8 3b fe 77 0b 3b cb 0f 46
cb 03 cf 3b f1 76 14 42 83 c0 28 3b 55 08 72 e0
5f 5e 32 c0 5b 8b e5 5d c2 14 00 8b 45 14 8d 4a
01 2b f7 5f 89 08 8b 45 18 89 30 b0 01 5e 5b 8b
e5 5d c2 14 00
```

CFG:

| Block | Range | Key role | Successors |
| --- | --- | --- | --- |
| B0 | `0x004abfa0-0x004abfbd` | Prologue and `VirtualQuery` | module call or failure |
| B1 | `0x004abfbd-0x004abfd1` | `GetModuleFileNameW` | PE parse or failure |
| B2 | `0x004abfd1-0x004abfeb` | RVA/NT-header setup and section-count gate | loop entry or failure |
| B3 | `0x004abfeb-0x004abff0` | First-section pointer | loop body |
| B4 | `0x004abff0-0x004abffc` | Section start/size load and lower-bound test | extent test or loop advance |
| B5 | `0x004abffc-0x004ac007` | maximum and inclusive upper-bound test | success or loop advance |
| B6 | `0x004ac007-0x004ac010` | index/section pointer advance | next section or failure |
| B7 | `0x004ac010-0x004ac01b` | false return | exit |
| B8 | `0x004ac01b-0x004ac035` | output stores and true return | exit |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004abe4a-0x004abf9c` | UID00014D parent-only | GetExceptionString compiler switch/data island | FALSE as independent source item | UID00014D | N/A | Preserve parent-only. |
| `0x004abf9c-0x004abfa0` | UID00014D parent-only | Four-byte `0xcc` alignment | FALSE | UID00014D | N/A | Preserve parent-only. |
| `0x004abfa0-0x004ac035` | UID00014I current target | Private static `ExceptionHandler::GetLogicalAddress` | TRUE | UID00004P | `86/91 -> 92/94` | Rename and implement R1. |
| `0x004ac035-0x004ac040` | UID00014D parent-only | Eleven-byte `0xcc` alignment | FALSE | UID00014D | N/A | Preserve parent-only. |
| `0x004ac040-0x004ac0ed` | UID00014D contained modeled helper | ImageHlp resolver/initializer | TRUE source-shaped, no exact child | UID00014D/UID00004P | Parent unchanged | Verify boundary only. |
| `0x004ac0f0-0x004ac221` | UID00014D raw retained helper | Raw frame/logical formatter; target call at `0x004ac190` | TRUE source-shaped, no exact child | UID00014D | Parent unchanged | Caller evidence only. |
| `0x004ac230-0x004ac4cb` | UID00014J | ImageHlp stack-walk helper | TRUE | UID00004P | `86/91` | Support prose only. |
| `0x004ac650-0x004ac859` | UID00014D raw retained helper | Raw symbol/detail helper; target call at `0x004ac7b4` | TRUE source-shaped, no exact child | UID00014D | Parent unchanged | Caller evidence only. |

`Nested:0` remains correct. This callback proposes no new address-sorted rows and no level-changing split; the predecessor UID00014H and target both retain zero relative delta, while the compiler island and padding remain parent-only rather than new semantic children.

## Direct Xref / Caller Inventory

Target calls:

| Call address | Containing item | Exact argument map and use |
| --- | --- | --- |
| `0x004ab939` | UID00014G modeled writer | `ExceptionRecord->ExceptionAddress`, uninitialized `WCHAR[260]`, `260`, uninitialized section, uninitialized offset; return ignored, then path/section/offset are formatted. |
| `0x004abc52` | UID00014G modeled fallback frame walk | frame program counter, zero-initialized `wchar_t[260]`, `260`, section `0`, offset `0`; return ignored; all outputs formatted, path compared to executable path, offset may be printed separately. |
| `0x004ac190` | UID00014D raw stack/logical formatter | current PC, zero-initialized `wchar_t[260]`, `260`, section `0`, offset `0`; return ignored; all outputs used by `%08X  %08X  %04X:%08X %ws`. |
| `0x004ac3e1` | UID00014J modeled ImageHlp fallback | `STACKFRAME.AddrPC.Offset`, zero-initialized `wchar_t[260]`, `260`, section `0`, offset `0`; return ignored; logical address formatted. |
| `0x004ac440` | UID00014J modeled executable-relative check | same PC and buffer, `260`, prior section retained, offset reset to `0`; return ignored; path compared to executable path and offset printed if equal. |
| `0x004ac7b4` | UID00014D raw symbol/detail helper | current address, zero-initialized `wchar_t[260]`, `260`, section local, offset `0`; return ignored; only offset is consumed for `L"%08X -> "`. |

`0x0069be74` xrefs:

| Xref | Kind | Meaning |
| --- | --- | --- |
| `0x0041a398` | initializer write | Modeled WideApi initializer stores imported `GetModuleFileNameW`. |
| `0x0046373b` | consumer call | Application constructor requests current module filename into a 260-character buffer and tests the return. |
| `0x004638aa` | consumer call | Second Application constructor path repeats the same typed module-filename call and tests the return. |
| `0x004abfc7` | consumer call | UID00014I target call with `AllocationBase`, caller buffer, caller character capacity. |
| `0x004ac548` | raw consumer call | Raw frame/module formatter calls the same API after `VirtualQuery`, then performs direct PE parsing. |
| `0x005996d1` | initializer write | Raw retained alternate UniAPI initializer copy stores imported `GetModuleFileNameW`. |
| `0x00599908` | initializer write | Second raw retained alternate initializer copy stores imported `GetModuleFileNameW`. |

## Documentation Evidence And IDA Status

- Historical pre-callback UID00014I had the correct exact range and broad PE behavior but was stale on caller count, helper identity, source name, signature, output contract, and formal C++. The implemented page now closes each defect at `92/94` with exact R1.
- Historical pre-callback UID00014D already recorded all six calls in its rel32 inventory, contradicting UID00014I's four-caller Item Summary. The current page now explicitly resolves the target to the private static Boolean method, preserves both raw calls, and retains the complete predecessor/successor range map.
- UID00004P and UID0000J8 established the class/file route and adjacent private static `GetExceptionString` lineage. Their current pages now add the exact `GetLogicalAddress` declaration/source state while preserving scores, route, blank class formal, and unrelated inventory.
- Historical pre-callback UID00014G and UID00014J documented the four modeled calls without the exact signature and initialization asymmetries. Their current pages now contain both accepted call maps at report-level detail.
- Historical pre-callback UID0001QB established the crash-diagnostics family without the exact logical-address contract. Its current page now records the private static identity, six-call role, one-based outputs, W-dispatch dependency, and failure mutation consequences.
- UID0000TQ and UID0002AS already type `0x0069be74` as `GetModuleFileNameW`; no changes to their formals/scores/routes are required.
- Historical B005 UID00014D research correctly found the method body and six calls but inferred file-static ownership and a pointer-output signature. Those are superseded by exact header and current ABI evidence.
- Evidence-time generated command 13892 remains explicitly historical pre-callback source evidence: UID00014I had one Empty Emitter Marker and no definition. B003 waited command 13981 emitted exactly one target definition and zero target markers/old-title occurrences; current external header epoch 13989 preserves those semantics and the independent UID00004P class marker.

## Ranked Ownership Analysis

### 1. UID00004P ExceptionHandler private static method

- Evidence for:
  - exact source header declares private static `GetLogicalAddress` with matching five source parameters;
  - adjacent UID00014H independently proves the same class/source adaptation;
  - no ECX use is expected for static membership;
  - all six callers are in the ExceptionHandler diagnostic aggregate;
  - current target already routes through UID00004P.
- Evidence against:
  - Nexus return type differs from the published sample;
  - current full class formal is unresolved.
- Decision: retain UID00004P canonical owner/emitter. Return-type adaptation does not undermine class ownership.

### 2. UID0000J8 ExceptionHandler file-static helper

- Evidence for:
  - target has no `this`;
  - all calls remain in one `.cpp`;
  - B005 previously inferred file-static ownership.
- Evidence against:
  - exact header places the method under private static class access;
  - adjacent `GetExceptionString` already demonstrates Nexus retained private static ownership.
- Decision: reject as target owner. UID0000J8 remains final file route, not direct semantic owner.

### 3. Generic PE/platform utility or WideApi owner

- Evidence for:
  - routine parses PE headers and consumes a platform dispatch slot.
- Evidence against:
  - no non-crash caller;
  - no independent source initializer/global/type;
  - exact class source identity;
  - WideApi owns only the function-pointer storage.
- Decision: reject.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; retain `NexusTK/platform/ExceptionHandler.cpp`.
- Likely full contents remain the existing ExceptionHandler class/global/report/stack helper family.
- No new standalone PE utility or crash-diagnostics translation unit is justified.

## Source Placement

- Recommended source: [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp`.
- Class placement: private static declaration inside [UID:00004P] `ExceptionHandler`; out-of-class definition emitted by UID00014I.
- Why it fits:
  - exact source lineage;
  - adjacent target order;
  - six caller cluster;
  - shared `BCrash.nfo`, stack formats, ImageHlp, and PE diagnostics.
- Rejected:
  - `NexusTK/util/PeUtil.cpp`;
  - `NexusTK/platform/PlatformApi.cpp`;
  - `NexusTK/platform/CrashDiagnostics.cpp`;
  - Application, Crasher, ImageHlp, Error, runtime, import, or Windows ownership.
- Remaining placement uncertainty: none material.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x004abfa0,0x004ac035)`, size `0x95` / 149 (Verified with `tools/int_convert.py`).
- Exact predecessor:
  - `0x004abe4a-0x004abf9c`: parent-only GetExceptionString switch/data;
  - `0x004abf9c-0x004abfa0`: four `0xcc` bytes.
- Exact successor:
  - `0x004ac035-0x004ac040`: eleven `0xcc` bytes;
  - modeled `sub_4AC040` starts exactly at `0x004ac040`, size `0xad`.
- No target-internal padding/data island exists.
- No split, merge, extension, shrink, ignored reclassification, or new child is recommended.
- Parent UID00014D must retain both padding spans and its complete raw/helper inventory.
- `Nested:0` remains exact because the recommendation changes no relative address-sorted hierarchy.

## Negative Evidence Summary

- No call from a generic PE parser, loader, updater, or non-crash module.
- No object receiver use; this rejects nonstatic membership but supports static membership.
- No output initialization at function entry.
- No output writes on any failure path.
- No DOS `e_magic`, NT signature, machine, optional-header magic, or section-name validation.
- No `GetModuleFileName` truncation/full-buffer check.
- No upper-bound overflow check.
- No half-open section-end comparison.
- No zero-based section output.
- No independent module-path helper around `0x0069be74`.
- No source/import ownership transfer from the dispatch slot to this target.
- No target range reason to split or absorb either padding span.
- No safe complete UID00004P formal class block from this target alone because the class's unrelated `+0x0c` member and raw helper declaration set remain unresolved.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing function name: `ExceptionHandler::GetLogicalAddress`.
- Proposed by-memory title/path: `ExceptionHandlerGetLogicalAddress`.
- Proposed type:
  - `bool` return;
  - `PVOID address`;
  - `PTSTR moduleName`;
  - `DWORD moduleNameLength`;
  - `DWORD &sectionNumber`;
  - `DWORD &sectionOffset`.
- Proposed binary comment facts:
  - private static source helper;
  - `moduleNameLength` is characters;
  - section number is one-based;
  - section extent uses inclusive end and maximum raw/virtual size;
  - outputs are written only on successful section match.
- IDA database edits are not requested or authorized. These are documentation/source recommendations only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Formal destination R1: [UID:00014I] `by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ExceptionHandler::GetLogicalAddress(PVOID address,
                                         PTSTR moduleName,
                                         DWORD moduleNameLength,
                                         DWORD &sectionNumber,
                                         DWORD &sectionOffset)
{
    MEMORY_BASIC_INFORMATION memoryInformation;
    if (VirtualQuery(address, &memoryInformation, sizeof(memoryInformation)) == 0) {
        return false;
    }

    const DWORD moduleBase = (DWORD)memoryInformation.AllocationBase;
    if (GetModuleFileName((HMODULE)moduleBase,
                          moduleName,
                          moduleNameLength) == 0) {
        return false;
    }

    PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)moduleBase;
    PIMAGE_NT_HEADERS ntHeaders =
        (PIMAGE_NT_HEADERS)(moduleBase + dosHeader->e_lfanew);
    PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);
    const DWORD relativeAddress = (DWORD)address - moduleBase;

    for (unsigned int index = 0;
         index < ntHeaders->FileHeader.NumberOfSections;
         ++index, ++sectionHeader) {
        const DWORD sectionStart = sectionHeader->VirtualAddress;
        const DWORD sectionEnd =
            sectionStart + std::max(sectionHeader->SizeOfRawData,
                                    sectionHeader->Misc.VirtualSize);

        if (relativeAddress >= sectionStart && relativeAddress <= sectionEnd) {
            sectionNumber = index + 1;
            sectionOffset = relativeAddress - sectionStart;
            return true;
        }
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation:
  - exact `VirtualQuery` order and size;
  - exact module-base/path call order;
  - exact PE header traversal;
  - exact maximum and inclusive end;
  - exact one-based/relative outputs;
  - exact no-output-write failure behavior.
- Source-shape rationale:
  - uses Windows/TCHAR/PE declarations present in the original source era;
  - uses the proven class method name and private static declaration shape;
  - retains ordinary C++03 control flow and `std::max`;
  - avoids IDA labels, offsets, raw slot names, decompiler temporaries, and defensive modernization.
- Naming convention: current ExceptionHandler methods use PascalCase and Windows typedefs; parameter/local names are descriptive lower camel case.
- UID00004P class formal remains blank. Exact declaration prose added:
  - `private: static bool GetLogicalAddress(PVOID address, PTSTR moduleName, DWORD moduleNameLength, DWORD &sectionNumber, DWORD &sectionOffset);`
  This is documentation guidance, not a separate formal C++ destination in this report.

## Final Recommendation

- UID00014I was renamed to `ExceptionHandlerGetLogicalAddress` through validator-managed UID preservation.
- Only the target was raised to `92/94`; owner/emitter UID00004P, reconstructable true, blank optional position, `Nested:0`, and exact range were retained.
- R1 was installed exactly.
- UID00014D, UID00004P, UID0000J8, UID00014G, UID00014J, and UID0001QB were synchronized with the private static name/signature, six-call inventory, exact caller initialization differences, `GetModuleFileNameW` identity, source placement, and historical file-static correction.
- UID0000TQ/UID0002AS, VirtualQuery import, Windows PE types, UID00014H, UID000259, and raw helper ranges remained verify-only except validator-propagated renamed links.
- All predecessor/successor padding and parent raw/helper inventory were preserved.
- No new source file, child page, raw table, vtable/RTTI code, or class formal shell was created.

## Recommended Target Doc Changes

The accepted target specification below is implemented and retained as the exact callback audit record.

- Target path before rename: `by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md`.
- Target path after accepted rename: `by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md`.
- Metadata:
  - `COMPLETION:92`;
  - `CONFIDENCE:94`;
  - retain `CANONICAL_OWNER:00004P`;
  - retain `RECONSTRUCTABLE:TRUE`;
  - retain `EMITTER_UIDS:00004P`;
  - retain blank optional position;
  - retain `Nested:0`.
- Item Summary replacement:
  - `Private static GetLogicalAddress source lineage, exact 149-byte hash/ABI, six call sites, GetModuleFileNameW dispatch identity, VirtualQuery/PE section walk, inclusive one-based section/offset outputs, failure-side mutations, and predecessor/successor padding verified.`
- Incorporate:
  - exact bytes/hash/CFG/instruction/stack facts;
  - exact five-argument signature and Boolean return analysis;
  - all six callers with modeled/raw classification;
  - exact slot xrefs/owner/type;
  - PE field table and inclusive containment;
  - output preconditions/mutations;
  - exact source lineage and Nexus adaptations;
  - R1;
  - rejected alternatives and historical correction.

## Recommended Support Doc Changes

The accepted support specification below is implemented and retained as the exact callback audit record.

### UID00014D `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`

- Preserve `86/90`, owner/emitter, range, blank formal, all children/raw bodies/data/padding, and unrelated source history.
- Replace file-static `GetLogicalAddress` wording with private static `bool ExceptionHandler::GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &)`.
- Record six calls, not only the four modeled calls.
- Record `0x0069be74` as PlatformApi-owned `GetModuleFileNameW`.
- Preserve raw calls at `0x004ac190`/`0x004ac7b4` and direct duplicate PE parsing in the raw `0x004ac4d0` helper.
- Historicalize B005's file-static/pointer-output proposal.

### UID00004P `by-class/ExceptionHandler.md`

- Preserve `87/90`, owner/emitter UID0000J8, exact `0x828` layout, blank formal, and unrelated class evidence.
- Replace the generic target row with:
  - `private: static bool GetLogicalAddress(PVOID address, PTSTR moduleName, DWORD moduleNameLength, DWORD &sectionNumber, DWORD &sectionOffset);`
- Explain no ECX/static ABI, AL Boolean return, six internal calls, and exact source lineage.
- Preserve the class formal no-code proof: target declaration is solved, but full class emission remains unsafe due unrelated `+0x0c`/raw-helper declaration debt.

### UID0000J8 `by-file/ExceptionHandler.md`

- Preserve `87/88`, `NexusTK/platform/`, all unrelated inventory and ownership boundaries.
- Close the `GetLogicalAddress` spelling/ownership question as private static class source.
- Record the source-ready target and `GetModuleFileNameW` dispatch adaptation.
- Reject separate PE/diagnostics utility placement.

### UID00014G `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`

- Preserve `86/91`, owner/emitter, range, blank formal, and all unrelated writer evidence.
- Record exact calls:
  - `0x004ab939` fault address with caller-uninitialized module/section/offset and ignored return;
  - `0x004abc52` fallback PC with zero-initialized outputs/buffer and ignored return.
- Use the renamed target link and private static signature.

### UID00014J `by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md`

- Preserve `86/91`, owner/emitter, range, blank formal, and all unrelated ImageHlp evidence.
- Record exact calls:
  - `0x004ac3e1` initializes module, section, and offset to zero;
  - `0x004ac440` resets module/offset but retains prior section before the repeated call and executable-path comparison.
- Use the renamed target link and private static signature.

### UID0001QB `by-meta/client_crash_diagnostics.md`

- Add the exact private static helper identity, six-call family role, one-based section/offset contract, and `GetModuleFileNameW` dispatch dependency.
- Historicalize file-static/unknown-module-helper wording if encountered.
- Preserve all unrelated Crasher, timer-skew, filter, packet, and Application cleanup evidence.

### Verify-only support

- UID0000TQ and UID0002AS already contain exact `GetModuleFileNameW` declarations and ownership; do not edit absent contradiction.
- UID00014H/UID000259 source lineage and diagnostic literal facts remain unchanged.
- VirtualQuery and Windows PE declarations are SDK/import dependencies, not new NexusTK owners.
- No raw helper split is required for this target.

## Score And Metadata Recommendation

- UID00014I historical pre-callback state: `86/91`, UID00004P owner/emitter, true, blank position/formal, `Nested:0`.
- UID00014I implemented state: `92/94`, same owner/emitter/reconstructable/position/Nested, exact R1, renamed title/path.
- Completion increase rationale:
  - exact bytes/hash/CFG/instructions;
  - complete ABI and return type;
  - six callers and argument maps;
  - exact slot identity/xrefs;
  - exact PE declarations/semantics;
  - exact source name/access/file;
  - complete formal body;
  - manual coverage handoff.
- Confidence increase rationale:
  - binary and source/header agreement is unusually strong;
  - target-specific Nexus differences are explicitly separated.
- Reason not `95+`:
  - no Nexus PDB/header survives;
  - the `bool` return is binary inference against a source-lineage `BOOL`;
  - exact Nexus parameter spelling cannot be proven;
  - a `95+` final-audit score would require compiler/output parity beyond this documentation pass.
- Support scores stay unchanged:
  - UID00014D `86/90`;
  - UID00004P `87/90`;
  - UID0000J8 `87/88`;
  - UID00014G/UID00014J `86/91`.
- Score-improvement blocker audit:
  - unresolved slot: solved;
  - caller count: solved;
  - return/signature/types: solved;
  - source name/access/file: solved;
  - formal body: solved;
  - split/padding/Nested: solved;
  - full class formal: investigated and excluded under exact independent class-level no-code proof, not used to cap the target below source-ready status.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution |
| --- | --- | --- |
| Is the return `BOOL` or `bool`? | Exact AL-only false/true epilogues, IDA `char`, all ignored returns, source `BOOL`, and same-file source-lineage `BOOL` helper `0x004ac040` with full-EAX epilogues. | Nexus source uses `bool`; use `bool`, document source divergence. |
| Is the method file-static? | Exact header private/static, no ECX, caller family, UID14H adaptation. | Private static class method. |
| Is `0x0069be74` a wrapper? | Seven xrefs, three direct imported-function assignments, typed formal docs. | Direct `GetModuleFileNameW` dispatch pointer. |
| Is length bytes or characters? | Six `260` calls, Win32 signature, source comment. | Characters. |
| Are section/offset pointers or references? | ABI pointers, exact source references, 32-bit stores. | Source references to `DWORD`. |
| Is section end inclusive? | Exact branch and source agreement. | Yes; preserve `<=`. |
| Should outputs be initialized internally? | Store dominance and source behavior. | No; callers own initialization. |
| Does target need a split? | Full bytes/CFG/padding/successor checks. | No. |
| Can UID00004P receive a complete formal now? | Current class page, constructor, source header, raw-helper/class layout checks. | No safe complete Nexus class shell from this target; retain blank formal and add exact declaration prose. |

No target-level question remains unresolved. The only retained uncertainty is the exact Nexus spelling of descriptive parameter/local names and the independent broader class formal, both reflected in scores and without blocking R1.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Historical report-only evidence snapshots, reread twice with stable hashes:

- `by-memory/-coverage-report.md`: SHA-256 `DDC1BF3968AAACEA64488A35BD9B6984BFF17526587AE965151F616FDED8A9BA`, 1,761,720 bytes, 4,231 lines.
- `by-class/-coverage-report.md`: SHA-256 `8FDB67F11C0C6385DF3E64120245E80BEAFE6DF8651758524C393F6C33950CA1`, 228,225 bytes, 622 lines.
- `by-file/-coverage-report.md`: SHA-256 `B542557D94F82B0EAFA13115D771BA100C2FDA2E4BB8E6ACC583654CE922E665`, 131,150 bytes, 316 lines.

Callback-time read-only manual snapshots:

- `by-memory/-coverage-report.md`: SHA-256 `6C2F436736E4BA86639EB767A538B96E9018AEE22CF2E64283B512AA494DE117`, 1,762,192 bytes, 4,232 lines.
- `by-class/-coverage-report.md`: SHA-256 `A4AE36910FCFD2616E30F92B792DC390DC8AEB9D1980E1214FB525C68ED369AC`, 228,369 bytes, 622 lines.
- `by-file/-coverage-report.md`: SHA-256 `DAB064BFC53369EA708D0EEDFF45D1C82EBFCC0C124D063B879A6314ADDCFBA8`, 131,070 bytes, 316 lines.
- UID00014D and UID00014I remain at by-memory lines 1350 and 1355; UID00004P remains at by-class line 194; UID0000J8 remains at by-file line 89.
- Validator command `13966` propagated only the accepted UID00014I path/title link into the manual by-memory page as a validator-owned rename side effect. The row still carries the historical `86%`/four-caller description, so the exact replacement text below remains the no-loss supervisor-owned handoff. B003 made no direct manual coverage edit.

Exact by-memory replacements:

1. Replace current UID00014D line 1350, between UID0000VN pre-padding and UID00014E:

```text
    - [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) : reconstructable : 86% : strong : ExceptionHandler aggregate with exact bounds and complete child/raw/data/padding inventory; private static GetExceptionString and GetLogicalAddress source lineage; six logical-address calls across modeled and raw helpers; GetModuleFileNameW dispatch identity; constructor/destructor/filter/report/ImageHlp evidence; parent class route; and retained blank aggregate formal because exact source bodies belong to child pages.
```

2. Replace current UID00014I line 1355, between UID00014H and UID00014J:

```text
    - [UID:00014I][0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress](by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md) : reconstructable : 92% : very strong : Private static bool ExceptionHandler::GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &) is source-ready from exact live IDA and MSJEXHND lineage: 149-byte hash/ABI, six calls, 260-character buffers, VirtualQuery, GetModuleFileNameW dispatch, DOS/NT/section parsing, inclusive max(raw,virtual) containment, one-based section/offset outputs, failure-side mutation rules, exact padding, and complete formal C++.
```

Exact by-class replacement:

3. Replace current UID00004P line 194:

```text
- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) : reconstructable : 87% : strong : Process crash-filter/report class with exact 0x828 layout, lifecycle, fields, filter/writer/ImageHlp family, private static LPTSTR GetExceptionString(DWORD) and bool GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &) declarations/source lineage, and platform source ownership; class formal remains blank because independent raw-helper and complete-class declaration blockers remain.
```

Exact by-file replacement:

4. Replace current UID0000J8 line 89:

```text
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) : reconstructable : 87% : strong : NexusTK/platform/ExceptionHandler.cpp owns the process exception-filter class/global/report family; exact private static GetExceptionString and GetLogicalAddress source lineage and implementation routes; six logical-address calls; GetModuleFileNameW/VirtualQuery/PE behavior; ImageHlp/raw-helper inventory; Crasher/Application boundaries; and retained broader source-quality blockers are documented.
```

Read-only no-change conclusions:

- UID00014G and UID00014J by-memory rows remain accurate at their current scores/paths; their bounded caller prose changes do not require row replacements.
- UID0000TQ/UID0002AS rows already type the slot and need no change.
- UID0001QB has no score/path/coverage-row change in this report.
- B003 did not apply manual coverage text directly. Exact current file/header/row state is external file/validator-owned; the text above remains immutable handoff content for this implemented callback epoch.

## Follow-Up Actions

- The accepted implementation checklist below is complete; no B003 implementation item remains.
- Independent complete-class reconstruction remains outside this target's ordinary edit set. UID00004P now contains the exact private UID00014I declaration in prose and accurately retains its blank formal/class Empty Emitter Marker for unrelated class-level debt.
- Report validation, manual coverage application, generated refresh after this captured callback epoch, execution, count, path movement, and archive state are external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.
- B003 itself performs no report execution, probe, count, move, archive, revalidation, or lifecycle command.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong.
- Formal C++ confidence: very strong for behavior and source structure; strong for the Nexus `bool` return inference.
- Remaining uncertainty:
  - exact Nexus parameter/local spellings;
  - full UID00004P class formal and unrelated `+0x0c` member identity.
- Neither uncertainty blocks target rename, ownership, R1, score improvement, or support synchronization.

## Validator Results

All commands ran from `source-3/project-documentation` with `--apply --queue-timeout 240`; each scoped command ran while the edited ordinary page's single B003 lease was active, and each lease was released immediately afterward.

| Command ID | Timestamp | Scope | Exit / ok | Relevant result and side effects |
| --- | --- | --- | --- | --- |
| `000000013966` | `2026-07-16T12:35:28-04:00` | renamed UID00014I target | `0 / 1` | UID-preserving `path_update`; `86/91 -> 92/94`; blank-to-block autogen registry update; 37 UID-link updates and six reference-source path updates; generated refresh deferred. Four `missing_ref_uid` warnings (`0003MT`, `0003VS`, `00039L`, `0003T6`) came from unrelated current manual coverage rows. |
| `000000013968` | `2026-07-16T12:36:26-04:00` | UID00014D parent | `0 / 1` | Scoped content/registry validation passed; projected stats refreshed; generated refresh deferred; no warnings. |
| `000000013971` | `2026-07-16T12:37:42-04:00` | UID00004P class | `0 / 1` | Scoped content/registry validation passed; projected stats refreshed; generated refresh deferred; no warnings. |
| `000000013974` | `2026-07-16T12:38:19-04:00` | UID0000J8 file | `0 / 1` | Scoped content/registry validation passed; projected stats refreshed; generated refresh deferred; no warnings. |
| `000000013976` | `2026-07-16T12:38:59-04:00` | UID00014G writer | `0 / 1` | Scoped content/registry validation passed; projected stats refreshed; generated refresh deferred; no warnings. |
| `000000013978` | `2026-07-16T12:39:29-04:00` | UID00014J stack walk | `0 / 1` | Scoped content/registry validation passed; projected stats refreshed; generated refresh deferred; no warnings. |
| `000000013980` | `2026-07-16T12:40:07-04:00` | UID0001QB meta | `0 / 1` | Scoped content/registry validation passed; projected stats refreshed; generated refresh deferred; no warnings. |
| `000000013981` | `2026-07-16T12:40:20-04:00` | final UID0000J8 `--wait-generated` | `0 / 1` | Generated refresh completed in the foreground; validator registry rebuilt over 5,067 nodes/4,090 edges and generated metadata refreshed. Project-wide child-marker/emitter-no-code diagnostics were unrelated to UID00014I; no target error occurred. |

Generated readback:

- B003 waited snapshot command/header `13981`: SHA-256 `E55C701ABBC7791552AF2464ED92DF43454C9F869C97BEC298800EEFF3456EA0`, 5,776 bytes, 155 lines.
- Current read-only external command/header `13989`, refreshed `2026-07-16T12:45:15-04:00`: SHA-256 `019461C0ABB31E481907DF2C6C4AF5AB1D498D4D40499DB2F22A81471DCFF3AB`, 5,776 bytes, 155 lines; semantic assertions below are unchanged.
- Exactly one `bool ExceptionHandler::GetLogicalAddress(...)` definition and one UID00014I generated source comment.
- Zero UID00014I Empty Emitter Markers and zero stale `ExceptionLogicalAddressHelper` text.
- Zero duplicate/wrong-range target bodies and zero handwritten vtable/RTTI/raw PE table arrays.
- R1 report/target formal parity: 1,609 characters each, byte-for-byte exact.
- UID00004P class Empty Emitter Marker: exactly one, accurately retained for independent complete-class debt; the callback does not claim it was solved.

## Changed Files

- Renamed and modified:
  - `by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md` -> `by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md`, UID00014I retained, final SHA-256 `9EA49167126B090D16F923B6F5DADBEBCEC11041D5B74B766C2633EA56FE567D`.
- Modified ordinary support:
  - `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`, final SHA-256 `3F425A8677102945947C0A40A45809DA23FE723675FFE93F946BA67A1EE4241B`.
  - `by-class/ExceptionHandler.md`, final SHA-256 `ABB673475B6B09B84581CEA86D935D6C1BA1BE02572D57CED8D2CA169BEB2A4D`.
  - `by-file/ExceptionHandler.md`, final SHA-256 `3506B3DC55D6E4F455C5D2E15C775DF786F3A49A4981B474E4B1198A6679CFF2`.
  - `by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md`, final SHA-256 `A3F155F6FFFD07DB5CE7FF8E86B44236A600AE045026C80D466D541D65A0C7E2`.
  - `by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md`, final SHA-256 `C7982D0951072B44A9886A4700AC07ED45CB599A246EFA955BBDA780DE5B0970`.
  - `by-meta/client_crash_diagnostics.md`, final SHA-256 `25EF0221F59446AE9A5C0E696E871E43469CACE713824A2E119100916A76E932`.
- Modified report:
  - `tools/leaser/Agents/Agent-B003/research/00014I-ExceptionLogicalAddressHelper-source-quality.md`.
- Validator-owned side effects, not manual B003 edits:
  - registry/reference/projected-stats state refreshed;
  - generated C++/generated metadata refreshed by B003 waited command `13981`; later external command/header `13989` advanced the current generated epoch without changing target semantics;
  - validator command `13966` propagated the renamed UID00014I path into known references, including the by-memory manual coverage link while leaving its score/description content for the exact supervisor-owned handoff.
- Verify-only pages UID0000TQ, UID0002AS, UID00014H, and UID000259 were reread and not edited.
- B003 manually edited no `-coverage-report.md`, generated, tracker, audit, supervisor, validator-state, queue, lock, archive, lifecycle, or IDA file.
- Leases: each of the seven ordinary destinations was leased alone, validated, and immediately released. Current lease report shows no B003 lease.
- Report lifecycle: B003 ran no execution, probe, count, move, archive, revalidation, or lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Reread the exact accepted report hash and current destination files immediately before each callback edit.
- [x] Rename UID00014I through the validator-aware UID-preserving workflow to `by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md`.
- [x] Preserve UID00014I exact range, owner/emitter UID00004P, reconstructable true, blank optional position, and `Nested:0`.
- [x] Apply UID00014I `86/91 -> 92/94`.
- [x] Replace UID00014I Item Summary exactly as recommended.
- [x] Install formal R1 exactly on UID00014I.
- [x] Incorporate exact target bytes/hash/size/instruction/CFG/stack/ABI facts.
- [x] Incorporate exact VirtualQuery/MBI and PE-header/section-walk facts.
- [x] Incorporate exact GetModuleFileNameW slot identity, signature, owner, seven xrefs, and generic source API spelling.
- [x] Incorporate all six target call sites and distinguish four modeled from two raw callers.
- [x] Incorporate exact caller initialization, ignored-return, and output-consumption differences.
- [x] Incorporate exact success/failure and partial-mutation behavior.
- [x] Preserve inclusive upper bound, one-based section number, and max raw/virtual extent.
- [x] Preserve predecessor switch data, four-byte pre-pad, eleven-byte post-pad, successor boundary, and no-split conclusion.
- [x] Update UID00014D at report-level detail without changing its score/route/formal or losing unrelated content.
- [x] Update UID00004P with the exact private static declaration/proof while retaining its score/route/layout and blank-formal no-code proof.
- [x] Update UID0000J8 with exact source-ready target identity and placement while retaining score/route/unrelated inventory.
- [x] Update UID00014G with exact two call maps while retaining score/route/formal/unrelated writer facts.
- [x] Update UID00014J with exact two call maps while retaining score/route/formal/unrelated ImageHlp facts.
- [x] Update UID0001QB with bounded target family semantics while preserving unrelated crash-diagnostics content.
- [x] Reread UID0000TQ, UID0002AS, UID00014H, UID000259, Win32 PE/import support, and raw helper ranges verify-only; edit only on exact contradiction.
- [x] Historicalize file-static, four-caller, unresolved-slot, pointer-output, and `BOOL` assumptions with exact reasons.
- [x] Preserve rejected generic PE/PlatformApi/Application/Crasher/ImageHlp/runtime/source-file alternatives.
- [x] Retain the exact manual by-memory/class/file handoff text for the supervisor-owned coverage workflow; B003 did not directly edit coverage.
- [x] Run one scoped file validator per changed ordinary by-* destination during the accepted callback.
- [x] Release each short ordinary-file lease immediately after its edit/scoped validator.
- [x] Run one final authorized waited by-file ExceptionHandler refresh.
- [x] Verify generated `ExceptionHandler.cpp` has one R1 definition, zero UID00014I Empty Emitter Markers, zero stale target title, no duplicate/wrong-range body, and no handwritten vtable/RTTI/raw PE tables.
- [x] Verify the independent UID00004P class Empty Emitter Marker disposition is reported accurately and not falsely claimed solved by this target.
- [x] Update C01-C20 to legal callback states with exact destination/validator/generated proof.
- [x] Update Validator Results, Changed Files, Current Target State, manual handoff status, and lifecycle wording to durable callback-time truth.
- [x] Confirm zero B003 leases and no prohibited manual coverage/generated/IDA/lifecycle edit remains.
- [x] Confirm B003 did not run or probe `execute_report`, report count, move, archive, revalidation, or any lifecycle command.

Implementation callback pass:

- [x] Exact report artifact accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated at report-level factual depth.
- [x] Claim And Incorporation Ledger updated claim by claim with legal final states and proof.
- [x] Metadata/rename/R1 changes applied exactly.
- [x] Historical assumptions, negative evidence, and rejected alternatives preserved.
- [x] Scoped validators and generated proof recorded with command IDs/timestamps/exits/ok/side effects.
- [x] Exact manual coverage handoff retained and reconciled against the callback epoch without direct B003 coverage edits.
- [x] Every accepted item is checked only after independent readback; no B003 implementation blocker remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000014039","destination_path":"executed-b-agent-research/B003/00014I-ExceptionLogicalAddressHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00014I-ExceptionLogicalAddressHelper-source-quality.md","timestamp":"2026-07-16T13:04:33-04:00","uid":"00014I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
