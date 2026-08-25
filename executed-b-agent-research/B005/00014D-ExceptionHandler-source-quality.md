** TARGET-REPORT-UID:00014D **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014D ExceptionHandler Source-Quality Research

Revision: B005-goal2-exceptionhandler-aggregate-source-quality-00014D-20260618, report-only, 2026-06-18.

## Finalized Report / Current Recommendation

- Target UID/path: [UID:00014D] `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`.
- Current state checked: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:00004P`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004P`, formal C++ blank.
- Recommendation: raise [UID:00014D] to `COMPLETION:86`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00004P`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004P`.
- Source placement: keep the implementation family in [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp`. Do not split it to a new generic crash-diagnostics file now, and do not move it to `Application.cpp`, `Crasher.cpp`, `KeySpeedMgr`, ImageHlp/runtime, network packet code, or generic `Error`.
- Aggregate C++ decision: do not populate [UID:00014D] with a monolithic implementation body. The target is a source-bearing aggregate/container over already-split exact child pages plus unsplit raw helper bodies and compiler-generated ABI/data spans. Populate C++ on exact children or split the remaining raw helpers first. If the generator requires a parent insertion point for children emitted through [UID:00014D], the only target-level block that should be considered is exactly `[[CHILDREN]]`, not source statements.
- Field/name recommendation: use descriptive source names `m_skipCrashReport`, `m_previousFilter`, ImageHlp function-pointer fields `m_symInitialize`, `m_symCleanup`, `m_stackWalk`, `m_symFunctionTableAccess`, `m_symGetModuleBase`, `m_symGetSymFromAddr`, and `m_reportText[0x400]`. These are inferred/descriptive, not original-symbol proof, but they are strong enough for source-facing documentation and C++ drafts.
- Coverage action: replace the current [UID:00014D] row in `by-memory/-coverage-report.md` with the exact row in this report. Do not edit coverage directly from this report-only pass.
- Confidence: high for boundaries, function inventory, source root, callback/reachability, field layout, and owner/emitter route; medium-high for exact original helper spellings and the raw no-xref helper source-shape.

## Target

- Target UID: `00014D`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004ab480-0x004ac89a.ExceptionHandler.md`
- Source queue/report row: refreshed `project-level/-auto-completion-stats.md`, `84/88`, average `86.0`.
- Current owner/emitter chain: [UID:00014D] -> [UID:00004P] `ExceptionHandler` -> [UID:0000J8] `ExceptionHandler.cpp`; `auto-generated/-ag-memory-coverage.md` confirms the route reaches `auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- Generated output state checked: `auto-generated/NexusTK/platform/ExceptionHandler.cpp` exists but is zero bytes. The route is live; output is empty because the file/class/global/memory pages still have blank reconstruction blocks.

## Evidence Sources Checked

- Required guidance: `Agent-B005/goal.md`, `Agent-B005/notes.md`, `Supervisor.md`, `by-structure.md`, and `inference_research.md`.
- Target and support docs: [UID:00014D], [UID:00004P], [UID:0000J8], [UID:00014E], [UID:00014F], [UID:00014G], [UID:00014H], [UID:00014I], [UID:00014J], [UID:0000QN], [UID:000297], [UID:000129], [UID:00003A], [UID:0000II], [UID:0000YW], [UID:0000UG], [UID:000259], and [UID:0001QB].
- Prior B reports read/revalidated as leads: B001 `000129-crasher-source-quality.md`, B001 `older/0000YW-DestroyExceptionHandler.md`, and B001 `older/00025A-ExchangeItemReadOnlyData-B001-00025A.md` for the adjacent diagnostics `.rdata` boundary.
- Generated reports: `project-level/-auto-completion-stats.md`, `project-level/-unresolved.md`, `project-level/-resolved.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `auto-generated/-ag-global-coverage.md`, and the current zero-byte generated `ExceptionHandler.cpp`.
- Local IDA export evidence: `C:\Users\admin\Desktop\CTools\Output\ida\decompile\*.json`, `functions/functions.json`, `cache/member_layout/ExceptionHandler.json`, `cache/method_lifecycle.json`, `segments/segments.json`, and `memory/memory.bin`.
- Live IDA MCP status: unavailable in this session. `Invoke-WebRequest` to `http://127.0.0.1:13337/mcp` returned `Unable to connect to the remote server`. Findings below therefore use refreshed local IDA export JSON, prior accepted live-MCP docs, and byte-level memory checks.
- Number conversions: size and offset conversions cited below were verified with `tools/int_convert.py`.

## Boundary / Bytes / Reachability

The aggregate half-open range is exact: `0x004ab480-0x004ac89a`, size `0x141a` / 5146 bytes (Verified with `int_convert.py`). The preceding `0x004ab476-0x004ab480` span is ten `0xcc` bytes. The successor `0x004ac89a-0x004ac8a0` span is six `0xcc` bytes, followed by the ExchangeDialog successor at `0x004ac8a0`.

Byte-level range map from `memory.bin`:

| Range | Size | Role | Boundary result |
| --- | ---: | --- | --- |
| `0x004ab480-0x004ab4ed` | `0x6d` / 109 | constructor | Modeled `sub_4AB480`, one caller at `0x00463e3a`. |
| `0x004ab4ed-0x004ab4f0` | `0x3` / 3 | padding | `cc cc cc`. |
| `0x004ab4f0-0x004ab50a` | `0x1a` / 26 | raw ordinary destructor/reset | Not an IDA function; source-shaped body restores filter and clears `g_pCrashTarget`. |
| `0x004ab50a-0x004ab510` | `0x6` / 6 | padding | `cc` fill. |
| `0x004ab510-0x004ab73b` | `0x22b` / 555 | stored crash-report sender | Modeled `sub_4AB510`, one caller at `0x005101e8`. |
| `0x004ab73b-0x004ab740` | `0x5` / 5 | padding | `cc` fill. |
| `0x004ab740-0x004ab804` | `0xc4` / 196 | diagnostic text sender | Exact child [UID:00014E], one caller at `0x00466e80`. |
| `0x004ab804-0x004ab810` | `0xc` / 12 | padding | `cc` fill before raw setter. |
| `0x004ab810-0x004ab82b` | `0x1b` / 27 | raw wide-string setter | Copies to `this+0x28` with `_wcscpy_s`, no static caller found. |
| `0x004ab82b-0x004ab830` | `0x5` / 5 | padding | `cc` fill. |
| `0x004ab830-0x004ab86f` | `0x3f` / 63 | top-level filter | Exact child [UID:00014F], callback pointer from constructor. |
| `0x004ab86f-0x004ab870` | `0x1` / 1 | padding | One `0xcc`. |
| `0x004ab870-0x004abd10` | `0x4a0` / 1184 | crash-report writer | Exact child [UID:00014G], only caller `TopLevelExceptionFilter`. |
| `0x004abd10-0x004abe4a` | `0x13a` / 314 | exception-code helper | Exact child [UID:00014H]. |
| `0x004abe4a-0x004abf9c` | `0x152` / 338 | switch/data island | Used by [UID:00014H]. Current docs should distinguish this from the following `0x4` padding. |
| `0x004abf9c-0x004abfa0` | `0x4` / 4 | padding | `cc cc cc cc`. |
| `0x004abfa0-0x004ac035` | `0x95` / 149 | logical-address helper | Exact child [UID:00014I]. |
| `0x004ac035-0x004ac040` | `0xb` / 11 | padding | `cc` fill. |
| `0x004ac040-0x004ac0ed` | `0xad` / 173 | ImageHlp resolver | Modeled `sub_4AC040`, no static callers. |
| `0x004ac0ed-0x004ac0f0` | `0x3` / 3 | padding | `cc cc cc`. |
| `0x004ac0f0-0x004ac221` | `0x131` / 305 | raw stack/logical-address formatter | Not an IDA function; calls [UID:00014I] at `0x004ac190`. |
| `0x004ac221-0x004ac230` | `0xf` / 15 | padding | `cc` fill. |
| `0x004ac230-0x004ac4cb` | `0x29b` / 667 | ImageHlp stack-walk helper | Exact child [UID:00014J]. |
| `0x004ac4cb-0x004ac4d0` | `0x5` / 5 | padding | `cc` fill. |
| `0x004ac4d0-0x004ac642` | `0x172` / 370 | raw frame-chain/module formatter | Not an IDA function; uses `VirtualQuery` and module-path helper. |
| `0x004ac642-0x004ac650` | `0xe` / 14 | padding | `cc` fill. |
| `0x004ac650-0x004ac859` | `0x209` / 521 | raw symbol/detail formatter | Not an IDA function; calls [UID:00014I] at `0x004ac7b4`. |
| `0x004ac859-0x004ac860` | `0x7` / 7 | padding | `cc` fill. |
| `0x004ac860-0x004ac89a` | `0x3a` / 58 | scalar deleting destructor | Modeled `sub_4AC860`, vtable cell `0x006196c0`. |

Static route checks:

- VA pointer hits to `0x004ab830`: one immediate at `0x004ab49f`, the callback pointer passed by the constructor to `SetUnhandledExceptionFilter`.
- VA pointer hits to `0x004ac860`: one pointer at `0x006196c0`, the `ExceptionHandler` vtable slot.
- VA pointer hits to `0x006196c0`: constructor/destructor/scalar-destructor vtable stores at `0x004ab4a5`, `0x004ab4f5`, and `0x004ac86b`.
- VA pointer hits to `0x0067ab34`: nine sites: `0x00464c60`, `0x00466e72`, `0x004673a2`, `0x0049bb61`, `0x004ab49a`, `0x004ab501`, `0x004ab83c`, `0x004ac87b`, and `0x005101e4`.
- Rel32 calls to the aggregate starts: constructor `0x00463e3a`, stored-report sender `0x005101e8`, diagnostic text sender `0x00466e80`, crash writer `0x004ab858`, exception-code helper `0x004ab951` and `0x004ab968`, logical-address helper `0x004ab939`, `0x004abc52`, `0x004ac190`, `0x004ac3e1`, `0x004ac440`, `0x004ac7b4`, and stack-walk helper `0x004abbb8`.
- No VA pointer or rel32 route was found to raw starts `0x004ab4f0`, `0x004ab810`, `0x004ac040`, `0x004ac0f0`, `0x004ac4d0`, or `0x004ac650`. They are source-shaped retained bodies, but no active static caller should be claimed without new evidence.

## Function / Child Inventory

| Range / item | UID / path | Best source-facing role | Reconstructable | Owner/source placement recommendation | C++ status |
| --- | --- | --- | --- | --- | --- |
| `0x004ab480-0x004ab4ed` | contained in [UID:00014D] | `ExceptionHandler::ExceptionHandler()` | TRUE | [UID:00004P] method in [UID:0000J8] | Safe as exact child if split; do not place in aggregate monolith. |
| `0x004ab4f0-0x004ab50a` | contained in [UID:00014D] | `ExceptionHandler::~ExceptionHandler()` ordinary destructor/reset | TRUE | [UID:00004P] method in [UID:0000J8] | Safe source body if split; scalar deleting destructor stays compiler-generated. |
| `0x004ab510-0x004ab73b` | contained in [UID:00014D] | `SendStoredCrashReportFile()` / stored `BCrash.nfo` upload helper | TRUE | file-static helper in [UID:0000J8] | Safe as new exact child; one caller in account/startup packet path. |
| `0x004ab740-0x004ab804` | [UID:00014E] | `SendCrashDiagnosticText(const char *)` | TRUE | file-static diagnostics helper in [UID:0000J8], currently routed through [UID:00004P] | C++ safe after stale threshold text is removed. |
| `0x004ab810-0x004ab82b` | contained in [UID:00014D] | `ExceptionHandler::SetReportText(const wchar_t *)` | TRUE | [UID:00004P] method in [UID:0000J8] | No caller found; split before final code if exact emission is desired. |
| `0x004ab830-0x004ab86f` | [UID:00014F] | `LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)` | TRUE | file callback installed by `ExceptionHandler` | C++ safe as callback child; not a class virtual method. |
| `0x004ab870-0x004abd10` | [UID:00014G] | `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)` | TRUE | [UID:00004P] method | C++ safe as child; large but well bounded. |
| `0x004abd10-0x004abe4a` | [UID:00014H] | `GetExceptionCodeText(DWORD)` | TRUE | file-static helper in [UID:0000J8] | C++ safe as lookup helper with fallback path caveat. |
| `0x004abe4a-0x004abf9c` | contained data | exception-code switch data | TRUE/source-declared-generated | belongs with [UID:00014H] | Do not hand-code as separate function. |
| `0x004abfa0-0x004ac035` | [UID:00014I] | `GetLogicalAddress(...)` | TRUE | file-static helper in [UID:0000J8] | C++ safe as helper. |
| `0x004ac040-0x004ac0ed` | contained in [UID:00014D] | `ExceptionHandler::InitializeImageHlp()` | TRUE | [UID:00004P] method | No static caller; source-shaped retained helper, split before final code if emitted. |
| `0x004ac0f0-0x004ac221` | contained in [UID:00014D] | `WriteFrameChainStackTrace(...)` style raw helper | TRUE | local helper in [UID:0000J8] | No caller to start; do not emit until split/rechecked. |
| `0x004ac230-0x004ac4cb` | [UID:00014J] | `ExceptionHandler::WriteImageHlpStackWalk(...)` | TRUE | [UID:00004P] method | C++ safe as child with ImageHlp field names. |
| `0x004ac4d0-0x004ac642` | contained in [UID:00014D] | raw module/frame formatter | TRUE | local helper in [UID:0000J8] | No caller to start; split/recheck before final code. |
| `0x004ac650-0x004ac859` | contained in [UID:00014D] | raw symbol/detail stack formatter | TRUE | local helper in [UID:0000J8] | No caller to start; split/recheck before final code. |
| `0x004ac860-0x004ac89a` | contained in [UID:00014D] | scalar deleting destructor | compiler-generated ABI for source virtual destructor | [UID:00004P] vtable output | Document, but do not hand-author final C++ body. |

## Caller / Callee / Lifecycle Revalidation

- Constructor startup: `sub_4639D0` at `0x00463e1f` allocates `0x828` / 2088 bytes (Verified with `int_convert.py`) and calls `sub_4AB480` at `0x00463e3a`. This is explicit Application startup construction, not static/global C++ initialization.
- Constructor behavior: stores `g_pCrashTarget`, writes vtable `0x006196c0`, installs `TopLevelExceptionFilter`, stores the previous filter at `this+8`, clears ImageHlp function pointers `+0x10..+0x24`, clears `m_skipCrashReport` at `+4`, and zeroes the first wide char at `+0x28`.
- Ordinary destructor/reset body: `0x004ab4f0` pushes `this+8`, writes vtable `0x006196c0`, calls `SetUnhandledExceptionFilter`, clears `g_pCrashTarget`, and returns. It has no direct static caller; the scalar deleting destructor duplicates the reset logic.
- Stored crash-report sender: `0x004ab510` reads `<client>\BCrash.nfo`, prefixes `Win95/Win98/WinME/Win2K/WinXP/Unknown` OS text, packetizes opcode `0x42`, subtype `1`, and file bytes, sends through `g_packetSender`, closes the file, and deletes it through the wide file helper. Its only direct caller is `0x005101e8` in the account/startup packet path.
- Diagnostic text sender [UID:00014E]: one caller `0x00466e80` from timer-skew diagnostics, packet `{0x42,1,length16,payload,0}`, accepted text length `1..0xfff` / `1..4095` bytes (Verified with `int_convert.py`).
- Top-level filter [UID:00014F]: no ordinary code caller; constructor callback xref only. It restores KeySpeedMgr state when live, reads `g_pCrashTarget`, skips writing `BCrash.nfo` when `m_skipCrashReport` is set, otherwise calls [UID:00014G], then chains to `m_previousFilter` if non-null.
- Crash writer [UID:00014G]: one caller from filter at `0x004ab858`; writes `BCrash.nfo`, version line, exception/fault/register fields, elapsed/phase/pixel format state, ImageHlp stack walk when initialized, and fallback frame-chain output.
- Exception-code helper [UID:00014H]: two calls from writer, static table for known SEH/NTSTATUS values, fallback buffer `0x0069af28` and helper slots `0x0069be78/0x0069be6c`.
- Logical-address helper [UID:00014I]: direct calls from writer, ImageHlp stack walk, and raw formatter bodies; uses `VirtualQuery`, module-path helper `0x0069be74`, PE headers, and one-based section output.
- ImageHlp resolver `0x004ac040`: no static caller, but source-shaped class method duplicates the resolver sequence in [UID:00014G]. It loads `IMAGEHLP.DLL`, resolves `SymInitialize`, `SymCleanup`, `StackWalk`, `SymFunctionTableAccess`, `SymGetModuleBase`, `SymGetSymFromAddr`, optionally calls `SymSetOptions(7)`, and calls `SymInitialize(GetCurrentProcess(), 0, TRUE)`.
- ImageHlp stack-walk helper [UID:00014J]: one caller from writer; uses class fields `+0x18/+0x1c/+0x20/+0x24` and falls back to [UID:00014I].
- External destroy helper [UID:0000YW]: prior B001 claim revalidated. It deletes the active object from Application fatal-load cleanup, but direct source ownership remains Application. Normal `g_pCrashTarget` lifecycle remains in this ExceptionHandler cluster.
- Crasher relationship: prior B001 claim revalidated. `Crasher::TriggerCrash` is a consumer that sets `m_skipCrashReport` through `g_pCrashTarget`; it does not own `g_pCrashTarget`, the filter, or the report writer.

## Object Layout Recommendation

Recommended source-facing layout for [UID:00004P] `ExceptionHandler`:

| Offset | Size | Recommended field | Evidence and status |
| --- | ---: | --- | --- |
| `+0x00` | 4 | vptr | Constructor/destructor/scalar vtable stores to `0x006196c0`. |
| `+0x04` | 1 | `bool m_skipCrashReport` | Constructor clears byte, [UID:00014F] reads it, Crasher writes it before intentional crash. This is the final best descriptive name. |
| `+0x05..+0x07` | 3 | padding | Required for `+0x08` pointer alignment. |
| `+0x08` | 4 | `LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter` | Saved from `SetUnhandledExceptionFilter`; destructor restores it; filter chains through it. |
| `+0x0c` | 4 | `m_reserved0C` / padding | No local export or byte scan evidence of meaningful accesses; do not invent a domain name. |
| `+0x10` | 4 | `PFNSYMINITIALIZE m_symInitialize` | Resolver/writer store and call. |
| `+0x14` | 4 | `PFNSYMCLEANUP m_symCleanup` | Resolver/writer store and call. |
| `+0x18` | 4 | `PFNSTACKWALK m_stackWalk` | Stack-walk helper calls this field. |
| `+0x1c` | 4 | `PFNSYMFUNCTIONTABLEACCESS m_symFunctionTableAccess` | Passed to `StackWalk`. |
| `+0x20` | 4 | `PFNSYMGETMODULEBASE m_symGetModuleBase` | Passed to `StackWalk`. |
| `+0x24` | 4 | `PFNSYMGETSYMFROMADDR m_symGetSymFromAddr` | Called in [UID:00014J]. |
| `+0x28` | `0x800` / 2048 bytes | `wchar_t m_reportText[0x400]` | Constructor zeroes first char; raw setter copies with count `0x400` / 1024 wide chars (Verified with `int_convert.py`). No report-writer read and no setter caller found, so the name is descriptive and should cap final-audit confidence. |

The allocation size observed at Application startup is `0x828` / 2088 bytes (Verified with `int_convert.py`), matching `0x28` bytes of fields plus `0x800` bytes for the wide buffer.

## Ranked Ownership / Source Placement Analysis

### 1. [UID:00004P] `ExceptionHandler` class with [UID:0000J8] `platform/ExceptionHandler.cpp`

Decision: accepted for [UID:00014D].

Evidence for:

- Constructor, ordinary destructor/reset, scalar deleting destructor, report writer, ImageHlp resolver, and stack-walk helper all operate on the `ExceptionHandler` object or its vtable/function-pointer fields.
- [UID:0000QN] `g_pCrashTarget` is written/cleared by this cluster and consumed by the filter and Crasher.
- The top-level callback pointer is installed by the constructor and is meaningful only with the active `ExceptionHandler` object.
- The `.rdata` diagnostics island [UID:000259] contains the class vtable, crash strings, exception-code strings, stack formats, and ImageHlp API names for this implementation family.
- The current generated route already reaches `platform/ExceptionHandler.cpp` without a dead-end.

Evidence against:

- Several helpers are file-static/free helper shaped rather than member functions: [UID:00014E], [UID:00014F], [UID:00014H], [UID:00014I], and the stored-report sender at `0x004ab510`.
- Some raw helper starts have no static caller, so source-level liveness is retained/emitted-code evidence, not active-call evidence.

Conclusion: keep [UID:00014D] as the class implementation aggregate under [UID:00004P], and document the file-static helper source signatures under [UID:0000J8]. This is stronger and lower-risk than rerouting the whole aggregate to a new owner.

### 2. New `CrashDiagnostics.cpp` / `CrashReport.cpp` support file

Decision: rejected for now.

Evidence for:

- Some helpers are generic-looking crash diagnostics helpers and not all are class methods.
- The diagnostic packet sender [UID:00014E] has a timer-skew caller outside normal exception handling.

Evidence against:

- There is no independent initializer, global owner, source-path evidence, or caller cluster proving a standalone diagnostics translation unit.
- The strongest state and string ownership anchors are `ExceptionHandler` object fields, `g_pCrashTarget`, `BCrash.nfo`, and the `ExceptionHandler` `.rdata` island.
- Splitting now would create a speculative file with only local helpers already naturally private to `ExceptionHandler.cpp`.

Conclusion: keep all helpers in `platform/ExceptionHandler.cpp`; record file-static helper status instead of creating a new source file.

### 3. [UID:0000HG] `Application`

Decision: lifecycle orchestrator only; rejected as direct target owner.

Evidence for:

- Application explicitly allocates the `ExceptionHandler` object at `0x00463e1f` and calls the constructor at `0x00463e3a`.
- Application cleanup and fatal-load cleanup can delete the active object through `g_pCrashTarget`.

Evidence against:

- Application does not own the vtable, filter callback, report writer, ImageHlp fields, exception-code table, or crash-report strings.
- Prior B001 correctly assigns only the external tiny deletion wrapper [UID:0000YW] to Application, while leaving normal crash-handler lifecycle here.

Conclusion: do not move [UID:00014D] to Application.

### 4. [UID:0000II] `Crasher`

Decision: consumer/companion only; rejected as owner.

Evidence for:

- `Crasher::TriggerCrash` writes the object byte at `g_pCrashTarget+4`.

Evidence against:

- Crasher has its own Pane-derived class, vtables, singleton, and file route.
- It only sets `m_skipCrashReport` before intentional crash; it does not install the filter or write reports.

Conclusion: preserve separate `platform/Crasher.cpp` and document `m_skipCrashReport` as an ExceptionHandler field consumed by Crasher.

### 5. KeySpeedMgr, packet sender/network, ImageHlp/runtime, generic `Error`

Decision: dependencies only; rejected as owners.

Evidence for:

- `TopLevelExceptionFilter` calls KeySpeedMgr restore logic.
- [UID:00014E] and `0x004ab510` send packets through `g_packetSender`.
- ImageHlp APIs are dynamically loaded and called by the report writer.

Evidence against:

- None of those dependencies own the `ExceptionHandler` object, `g_pCrashTarget`, vtable, BCrash file creation, or report formatting state.

Conclusion: keep them as callees/dependencies in support docs.

## Heuristic / Inference Reanalysis And Validation

### 1. Aggregate split/source-code policy

Evidence checked: target page, all exact child pages [UID:00014E] through [UID:00014J], `auto-generated/-ag-memory-coverage.md`, zero-byte generated `ExceptionHandler.cpp`, byte-level child/padding map, and by-structure C++ rules.

Rejected alternatives:

- Populate [UID:00014D] with a full C++ implementation of every function in the range. Rejected because it would duplicate exact child pages and include compiler-generated scalar deleting destructor/switch-data/padding.
- Reclassify [UID:00014D] as non-reconstructable. Rejected because the aggregate is a real source-bearing implementation island and is still an emitter route for child pages.
- Split the aggregate directly in this report-only pass. Rejected procedurally because the assignment is report-only; recommended as follow-up for the raw/modelled helpers that still lack exact child pages.

Final inference: [UID:00014D] should remain a reconstructable source-bearing aggregate/container, but its formal C++ block should not contain source statements. Exact child pages should emit the real source bodies.

Impact: raises documentation score to `86/90`, keeps owner/emitter stable, and blocks aggregate-level monolithic C++ while allowing child-level C++.

### 2. `m_skipCrashReport` field at `+0x04`

Evidence checked: constructor byte clear at `0x004ab4de`, filter byte read at `0x004ab862`, Crasher write at `0x0049bb60`, [UID:0000QN]/[UID:000297] xref inventories, and B001 Crasher report.

Rejected alternatives:

- `m_hasCrashed`: rejected because the filter does not mark it after reporting; it only checks to skip normal report generation.
- `m_isCrasherCrash`: rejected because the field's binary behavior is report-suppression, not a type tag.
- Leave as `this+4`: rejected because the source semantics are now clear enough.

Final inference: use `bool m_skipCrashReport`. This is descriptive, not proven original spelling.

Impact: closes the Crasher/ExceptionHandler field-name blocker for source drafts; still caps final-audit confidence because original symbol spelling is unavailable.

### 3. Previous-filter and ImageHlp fields

Evidence checked: constructor stores `SetUnhandledExceptionFilter` return to `this+8`, destructor and scalar destructor restore it, filter chains through `this+8`, resolver/writer stores ImageHlp pointers at `+0x10..+0x24`, and stack-walk helper calls fields `+0x18..+0x24`.

Rejected alternatives:

- Treat `+0x10..+0x24` as generic scratch fields. Rejected because the GetProcAddress strings and call sites identify each function pointer.
- Store ImageHlp module handle at `+0x0c`. Rejected because no local export/memory scan evidence found access to `+0x0c`.

Final inference: field names listed in the layout table are safe descriptive names. `+0x0c` should remain reserved/padding until evidence appears.

Impact: supports class layout and C++ declarations; no owner/emitter blocker remains.

### 4. `this+0x28` wide buffer and raw setter

Evidence checked: allocation size `0x828`, constructor zero at `this+0x28`, raw setter `0x004ab810-0x004ab82b` uses `_wcscpy_s(this+0x28, 0x400, source)`, no VA/rel32 route to `0x004ab810`, and no report-writer read of the buffer in decompiled `0x004ab870`.

Rejected alternatives:

- Name it as a known user-visible comment field. Rejected because no writer use or caller was found.
- Ignore it as padding. Rejected because constructor and setter explicitly treat it as a wide string buffer.

Final inference: use `wchar_t m_reportText[0x400]` and `ExceptionHandler::SetReportText(const wchar_t *)` as descriptive names. Do not claim a user-facing feature or report output until a caller/read path is found.

Impact: field/type issue no longer a bare blocker; it caps score below `90+` and should block only final-audit naming, not source placement.

### 5. Stored `BCrash.nfo` sender at `0x004ab510`

Evidence checked: modeled function JSON, direct caller `0x005101e8`, decompilation of caller `0x0050feb0`, packet send/delete behavior, and packet helper dependencies.

Rejected alternatives:

- Class method: rejected because there is no `this` use and no object field access.
- Network packet owner: rejected because the packet sender is a dependency and the helper's payload is crash-report file data.
- Application owner: rejected because the code and strings belong to the crash diagnostics cluster despite being triggered by account/startup packet logic.

Final inference: file-static helper in `ExceptionHandler.cpp`, recommended descriptive name `SendStoredCrashReportFile()` or `UploadStoredCrashReportFile()`.

Impact: source placement resolved; exact child page recommended if the supervisor wants C++ emission for this body.

### 6. Diagnostic text sender [UID:00014E]

Evidence checked: exact child doc, single caller `0x00466e80` from timer-skew path, packet layout, and dependencies.

Rejected alternatives:

- `Socket`/packet source owner: rejected because packet helpers are dependencies.
- `Application`/timer owner: rejected because the helper lives in the ExceptionHandler range and sends crash-diagnostic text.
- New diagnostics file: rejected with the broader source-file analysis.

Final inference: file-static `SendCrashDiagnosticText(const char *)` in `ExceptionHandler.cpp`.

Impact: safe for child-level C++; current owner/emitter route remains usable, but support docs should stop calling the source split open.

### 7. Top-level filter [UID:00014F]

Evidence checked: no ordinary callers, constructor pointer reference `0x004ab49e/0x004ab49f`, KeySpeedMgr restore, `g_pCrashTarget` read, report-writer call, and previous-filter chain.

Rejected alternatives:

- Class virtual method: rejected because Windows calls it as a callback pointer and the function uses the global active object.
- Application-owned crash callback: rejected because constructor installs it and object fields drive behavior.

Final inference: `LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)` as a file-level callback in `ExceptionHandler.cpp`.

Impact: safe child-level C++; do not attach it to Crasher or KeySpeedMgr.

### 8. Crash-report writer [UID:00014G]

Evidence checked: one caller from the filter, BCrash path, version helpers, exception/register output, elapsed/phase/pixel state, ImageHlp resolver duplication, fallback frame-chain loop, and exact child docs.

Rejected alternatives:

- Free helper only: rejected because it receives and uses the active `ExceptionHandler *` object for ImageHlp fields.
- Separate `CrashReportWriter` class: rejected because no object allocation/vtable/global evidence exists.

Final inference: `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)`.

Impact: safe child-level C++, but large body should be emitted on [UID:00014G], not the aggregate.

### 9. Exception-code and logical-address helpers [UID:00014H]/[UID:00014I]

Evidence checked: caller sets, static strings, fallback buffers, switch/data island, `VirtualQuery`, module-path helper, PE section table walk, raw helper calls into [UID:00014I].

Rejected alternatives:

- Runtime exception library: rejected because the static strings and BCrash writer call sites are local project diagnostics.
- Generic PE utility file: rejected because only crash-report paths call it.

Final inference: file-static `GetExceptionCodeText(DWORD)` and `GetLogicalAddress(...)` helpers in `ExceptionHandler.cpp`.

Impact: safe child-level C++; switch table should be source-expressed through `switch`/lookup strings, not raw bytes.

### 10. ImageHlp resolver and raw stack helpers

Evidence checked: modeled `0x004ac040` helper has no static callers but stores the same function pointers as the inline resolver sequence in [UID:00014G]; raw helpers at `0x004ac0f0`, `0x004ac4d0`, and `0x004ac650` are source-shaped, cookie-protected, and call formatting/logical-address helpers, but have no VA/rel32 route to their starts.

Rejected alternatives:

- Treat as padding/dead junk. Rejected because they are well-formed function bodies with prologue, calls, and returns.
- Claim active direct reachability. Rejected because pointer/rel32 scans found none.
- Emit from aggregate now. Rejected because names and direct call paths are less complete than exact children.

Final inference: these are retained private helper bodies in the ExceptionHandler object file, likely uncalled or inlined-elsewhere out-of-line copies under this build/link setting. Recommend exact child pages before final code.

Impact: source placement is resolved; liveness uncertainty caps [UID:00014D] at `86/90` and is the main reason not to enter aggregate-level C++.

### 11. Static/global startup versus explicit construction

Evidence checked: constructor caller in `0x004639d0`, allocation size `0x828`, no VA pointer table route to constructor, and Application file docs.

Rejected alternatives:

- Static global object construction. Rejected because the constructor is called after `operator new(0x828)` in Application startup.
- Lazy filter construction inside the exception callback. Rejected because filter pointer is installed by the explicit constructor.

Final inference: explicit startup allocation from Application, but source ownership remains `ExceptionHandler.cpp`.

Impact: support docs should replace the open question with this conclusion.

## First-Draft C++ Placement Recommendation

Do not paste the following as the [UID:00014D] aggregate formal block. It is the source-shape recommendation for the class/file and exact child pages.

For [UID:00014D], recommended formal block action:

```cpp
[[CHILDREN]]
```

Use that only if the generator needs a parent insertion point for [UID:00014F]/[UID:00014G]. Otherwise keep [UID:00014D] formal C++ blank and put code on exact children.

Recommended source declarations for [UID:00004P]/[UID:0000J8]:

```cpp
typedef BOOL (WINAPI *PFNSYMINITIALIZE)(HANDLE, PCSTR, BOOL);
typedef BOOL (WINAPI *PFNSYMCLEANUP)(HANDLE);
typedef BOOL (WINAPI *PFNSTACKWALK)(DWORD, HANDLE, HANDLE, LPSTACKFRAME, PVOID,
                                    PREAD_PROCESS_MEMORY_ROUTINE,
                                    PFUNCTION_TABLE_ACCESS_ROUTINE,
                                    PGET_MODULE_BASE_ROUTINE,
                                    PTRANSLATE_ADDRESS_ROUTINE);
typedef PVOID (WINAPI *PFNSYMFUNCTIONTABLEACCESS)(HANDLE, DWORD);
typedef DWORD (WINAPI *PFNSYMGETMODULEBASE)(HANDLE, DWORD);
typedef BOOL (WINAPI *PFNSYMGETSYMFROMADDR)(HANDLE, DWORD, PDWORD, PIMAGEHLP_SYMBOL);

class ExceptionHandler {
public:
    ExceptionHandler();
    virtual ~ExceptionHandler();

    void SetReportText(const wchar_t *text);
    void WriteCrashReport(EXCEPTION_POINTERS *exceptionInfo);
    bool InitializeImageHlp();
    void WriteImageHlpStackWalk(const CONTEXT *context, FILE *reportFile);

    bool ShouldSkipCrashReport() const { return m_skipCrashReport; }
    LPTOP_LEVEL_EXCEPTION_FILTER PreviousFilter() const { return m_previousFilter; }

private:
    bool m_skipCrashReport;
    unsigned char m_reserved04[3];
    LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter;
    DWORD m_reserved0C;
    PFNSYMINITIALIZE m_symInitialize;
    PFNSYMCLEANUP m_symCleanup;
    PFNSTACKWALK m_stackWalk;
    PFNSYMFUNCTIONTABLEACCESS m_symFunctionTableAccess;
    PFNSYMGETMODULEBASE m_symGetModuleBase;
    PFNSYMGETSYMFROMADDR m_symGetSymFromAddr;
    wchar_t m_reportText[0x400];
};

ExceptionHandler *g_pCrashTarget;

static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo);
static void SendStoredCrashReportFile();
static int SendCrashDiagnosticText(const char *text);
static const wchar_t *GetExceptionCodeText(DWORD exceptionCode);
static bool GetLogicalAddress(const void *address, wchar_t *modulePath, int modulePathChars,
                              int *sectionNumber, DWORD *sectionOffset);
```

Representative exact-child code shape:

```cpp
ExceptionHandler::ExceptionHandler()
    : m_skipCrashReport(false),
      m_previousFilter(0),
      m_reserved0C(0),
      m_symInitialize(0),
      m_symCleanup(0),
      m_stackWalk(0),
      m_symFunctionTableAccess(0),
      m_symGetModuleBase(0),
      m_symGetSymFromAddr(0)
{
    g_pCrashTarget = this;
    m_previousFilter = SetUnhandledExceptionFilter(TopLevelExceptionFilter);
    m_reportText[0] = 0;
}

ExceptionHandler::~ExceptionHandler()
{
    SetUnhandledExceptionFilter(m_previousFilter);
    g_pCrashTarget = 0;
}

void ExceptionHandler::SetReportText(const wchar_t *text)
{
    wcscpy_s(m_reportText, 0x400, text);
}

static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)
{
    if (g_pKeySpeedMgr != 0) {
        g_pKeySpeedMgr->RestoreKeyboardSettings();
    }

    ExceptionHandler *target = g_pCrashTarget;
    if (target == 0 || target->ShouldSkipCrashReport()) {
        return EXCEPTION_CONTINUE_SEARCH;
    }

    target->WriteCrashReport(exceptionInfo);

    LPTOP_LEVEL_EXCEPTION_FILTER previous = target->PreviousFilter();
    if (previous != 0) {
        return previous(exceptionInfo);
    }

    return EXCEPTION_CONTINUE_SEARCH;
}
```

Notes for the supervisor:

- The `g_pKeySpeedMgr->RestoreKeyboardSettings()` spelling is descriptive; use the current KeySpeedMgr source-facing name when that page finalizes it.
- Do not write a scalar deleting destructor in final source. It is compiler-generated from the virtual destructor.
- Do not write raw vtable stores, RTTI, switch-table bytes, security-cookie scaffolding, or `this+offset` pointer arithmetic in final C++.
- [UID:00014G], [UID:00014H], [UID:00014I], and [UID:00014J] can receive larger first-draft bodies from their exact pages; the aggregate should only route them.

## Metadata Recommendations

For [UID:00014D] `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004P | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004P | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion improves because the aggregate boundary, byte padding, exact child/raw body inventory, explicit startup allocation, `g_pCrashTarget` lifecycle, field layout, helper names, and source placement are now resolved or narrowed with direct evidence.
- Confidence improves because current docs, prior B001 reports, local IDA export JSON, raw byte scans, pointer/rel32 scans, generated coverage, and support docs agree on the source route.
- Do not raise above `90` confidence or near final-audit levels. Remaining limits are original helper spelling, uncalled retained raw helper source-shape, and lack of formal exact child C++ for all contained bodies.

Support-page score notes:

- [UID:00004P] `ExceptionHandler` class can stay `86/89` unless the supervisor incorporates the full layout table and first-draft declaration; after that, `87/90` is defensible.
- [UID:0000J8] `ExceptionHandler` file can stay `86/86`; after adding the resolved source-placement/open-question text and the class layout summary, `87/88` is defensible.
- No child metadata change is required to complete this target. Child pages [UID:00014E]/[UID:00014F] should have stale "95/95 threshold" text removed; if first-draft child C++ is entered, both can defensibly move from `84/90` to `85/91`.

## Exact Support-Doc Incorporation Plan

### Target [UID:00014D]

Replace the stale status sentence:

```text
- Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold.
```

with:

```text
- Final C++ is intentionally not populated as a monolithic aggregate body. The active code-entry gate is the combined-score/emitter route gate, which this page can satisfy after B005 source-quality incorporation, but this range is a source-bearing aggregate over exact child pages, raw no-xref helper bodies, switch/data islands, compiler-generated scalar deleting destructor output, and padding. Populate C++ on exact child pages or add only a `[[CHILDREN]]` insertion point if the generator needs one.
```

Add this section after the current `2026-06-06 Live IDA Recheck` section:

```text
## 2026-06-18 B005 Source-Quality Reanalysis

- B005 local IDA-export and byte-level recheck confirms the aggregate half-open range `0x004ab480-0x004ac89a`, size `0x141a` / 5146 bytes (Verified with `tools/int_convert.py`), with ten `0xcc` bytes before the start and six `0xcc` bytes before successor `0x004ac8a0`.
- Application explicitly constructs the handler: `sub_4639D0` allocates `0x828` / 2088 bytes (Verified with `tools/int_convert.py`) and calls the constructor at `0x00463e3a`. This is not static/global C++ construction.
- Recommended source-facing fields are `m_skipCrashReport` at `+0x04`, `m_previousFilter` at `+0x08`, reserved/padding `+0x0c`, ImageHlp function pointers `+0x10..+0x24`, and `wchar_t m_reportText[0x400]` at `+0x28`.
- Recommended helper names are `SendStoredCrashReportFile`, `SendCrashDiagnosticText`, `TopLevelExceptionFilter`, `ExceptionHandler::WriteCrashReport`, `GetExceptionCodeText`, `GetLogicalAddress`, `ExceptionHandler::InitializeImageHlp`, `ExceptionHandler::WriteImageHlpStackWalk`, and descriptive raw formatter names pending exact child splits.
- Raw helper starts `0x004ab810`, `0x004ac040`, `0x004ac0f0`, `0x004ac4d0`, and `0x004ac650` have no static VA/rel32 route to their starts in the byte scan, but are source-shaped retained helper bodies. Do not claim active direct callers until a future IDA/runtime pass proves them.
- The exception-code switch/data span is `0x004abe4a-0x004abf9c`; `0x004abf9c-0x004abfa0` is four `0xcc` bytes before [UID:00014I].
```

Replace the `Open Questions` section with:

```text
## Open Questions / Closed Source-Quality Findings

- Closed: the constructor is explicit Application startup allocation, not static/global construction.
- Closed: formatting/storage helpers should stay in `platform/ExceptionHandler.cpp`; no separate diagnostics support file is justified by current evidence.
- Closed for draft source: use descriptive helper names and `m_skipCrashReport`, `m_previousFilter`, ImageHlp pointer field names, and `m_reportText[0x400]`.
- Remaining, score-capping only: exact original helper spellings are not proven; raw helper starts with no static callers need exact child pages before final source emission; `m_reportText` has a setter and constructor initialization but no confirmed read/caller path.
```

### [UID:00004P] `ExceptionHandler`

Add the layout table from this report under the responsibility/method inventory. Replace the final-C++ sentence with:

```text
Final C++ should be entered on exact child pages and class/global declaration pages, not as a monolithic aggregate body. The class layout is now source-shaped enough for first-draft declarations, but unsplit raw helper bodies and exact original helper spellings keep this page below final-audit quality.
```

Replace the open helper-name wording with:

```text
Use descriptive source-facing names `m_skipCrashReport`, `m_previousFilter`, `m_symInitialize`, `m_symCleanup`, `m_stackWalk`, `m_symFunctionTableAccess`, `m_symGetModuleBase`, `m_symGetSymFromAddr`, and `m_reportText[0x400]`. These names are inferred from binary behavior and should be used in draft C++ until stronger source metadata appears.
```

### [UID:0000J8] `ExceptionHandler`

Replace the `Open Questions` section with:

```text
## Open Questions / Current Source-Placement Conclusions

- Closed: keep this family in `platform/ExceptionHandler.cpp`. A separate `CrashDiagnostics.cpp` is not justified by current evidence because the helpers are tied to `ExceptionHandler` fields, `g_pCrashTarget`, `BCrash.nfo`, and the ExceptionHandler diagnostics `.rdata` island.
- Closed: [UID:0000II] `Crasher` remains a separate companion source file and only consumes `g_pCrashTarget` / `m_skipCrashReport`.
- Closed: [UID:0000YW] `DestroyExceptionHandler` is Application fatal-load cleanup, not direct ExceptionHandler implementation ownership.
- Remaining source-quality limits: original helper spellings, raw no-static-caller helper liveness, and exact child C++ bodies for every contained source-authored range.
```

### [UID:0001QB] `client_crash_diagnostics`

Replace the open question about the offset `+4` flag with:

```text
- The `ExceptionHandler` offset `+4` byte is now best named descriptively as `m_skipCrashReport`: Crasher sets it before the intentional null write, and `TopLevelExceptionFilter` reads it to bypass normal `BCrash.nfo` generation.
```

Replace the open question about helper split with:

```text
- Current best source placement keeps crash-report helpers in `platform/ExceptionHandler.cpp`; no separate diagnostics utility file is justified without new source-path, initializer, or non-ExceptionHandler caller evidence.
```

### Child Pages [UID:00014E] through [UID:00014J]

Replace any sentence that says final C++ is blank only because of the old `95/95` threshold with:

```text
Final C++ is pending exact child-body source entry under the active combined-score/emitter gate. The old `95/95` threshold is obsolete. This child should receive C++ only on its own exact page or through a valid child insertion route, not through a monolithic [UID:00014D] aggregate body.
```

For [UID:00014H], replace the current tail-data sentence with:

```text
The exception-code helper's switch/data span is `0x004abe4a-0x004abf9c`; the following `0x004abf9c-0x004abfa0` span is four `0xcc` padding bytes before [UID:00014I].
```

## Exact Coverage Row Recommendation

Placement context: replace the existing [UID:00014D] row in `by-memory/-coverage-report.md` between:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ab476-0x004ab480 | padding | EventMan to ExceptionHandler alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
```

and:

```text
    - [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) : reconstructable : 84% : strong : Exact half-open bounds, sole caller `0x00466e80`, packet `{0x42,1,length16,payload,0}`, accepted length `1..0xFFF`, send length `length+5`, `g_packetSender` read, allocator/memmove/packet-writer callees, and twelve-byte padding before raw setter verified.
```

Replacement row:

```text
    - [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) : reconstructable : 86% : very strong : B005 source-quality recheck confirms exact `0x141a` / 5146-byte aggregate range (Verified with int_convert.py), ten-byte pre-padding and six-byte successor padding, explicit Application startup allocation/call rather than static construction, constructor/destructor/filter/report/helper inventory, callback route through `SetUnhandledExceptionFilter`, `g_pCrashTarget` lifecycle, `m_skipCrashReport` field consumed by Crasher, ImageHlp function-pointer fields `+0x10..+0x24`, `m_reportText[0x400]` buffer at `+0x28`, stored `BCrash.nfo` upload helper, raw no-static-caller helper bodies, exception-code switch/data island split from padding, `platform/ExceptionHandler.cpp` source placement, and target-specific no-monolithic-C++ proof; populate exact child pages or `[[CHILDREN]]` only.
```

No other `by-memory/-coverage-report.md` row must change for this target report. If the supervisor separately enters child C++ or score changes for [UID:00014E]/[UID:00014F], those rows should be updated in that child-specific execution pass.

## Validation / Expected Generated Impact

- No by-* docs, coverage reports, generated files, or IDA data were edited.
- No validator was run because this report only creates a research file under Agent-B005.
- Expected generated impact after supervisor incorporation: [UID:00014D] remains an emitting aggregate route to `auto-generated/NexusTK/platform/ExceptionHandler.cpp`; the file may remain zero bytes until exact child pages receive C++ or [UID:00014D] receives a `[[CHILDREN]]` insertion point and child code.
- Active unresolved-report items for `sub_4AB480`, `sub_4AB510`, `sub_4AC040`, `sub_4AC860`, and `this+0x28` should be reduced by applying the descriptive names and layout text above. `sub_5C7526` remains an allocator/free helper dependency, not an ExceptionHandler source helper.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00014D-ExceptionHandler-source-quality.md`
- Modified: none outside Agent-B005 research.
- Coverage edited directly: no.
- Generated/source files edited directly: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00014D-ExceptionHandler-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00014D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
