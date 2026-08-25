*** UID:00004P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
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

    void SetSkipCrashReport(bool skipCrashReport)
    {
        m_skipCrashReport = skipCrashReport;
    }

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

# ExceptionHandler

## Status

- Confidence: very strong for class responsibility, complete source declaration, exact `0x828` layout, callback/report behavior, live ranges, singleton lifecycle, exact report/helper identities, legacy callback types, and crash-diagnostics ownership; unavailable original Nexus symbols/source and rebuilt-binary comparison remain the final cap.
- Prior generated file: `class_ExceptionHandler.cpp`, treated only as non-authoritative context.
- Likely source module: [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- Current range: [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- Evidence basis: live IDA MCP checks on 2026-06-06 plus existing documentation.
- Exact method bodies remain on source-bearing child CPP pages, while this page's H channel carries the six callback typedefs, complete class declaration, exact `0x828` size assertion, and `[[CHILDREN]]` required by those definitions. Its CPP channel is intentionally blank because no separate class-level implementation belongs here; method-child H channels remain blank to avoid duplicate declarations. Unsplit raw helpers remain independently scoped and do not block the accepted class source shape.

## Responsibility

`ExceptionHandler` is the process-level crash/exception filter object. It installs a top-level exception filter, owns the active crash target pointer, writes crash reports, and restores the previous filter on destruction.

The object byte at offset `+4` is `m_skipCrashReport`. [UID:00003A][Crasher](by-class/Crasher.md) calls the public inline `SetSkipCrashReport(true)` immediately before an intentional diagnostic null write, and [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) reads it to skip normal report generation. The inline setter is the legal source surface for the exact observed byte store and changes neither class size nor generated behavior.

Use descriptive source-facing names `m_skipCrashReport`, `m_previousFilter`, `m_symInitialize`, `m_symCleanup`, `m_stackWalk`, `m_symFunctionTableAccess`, `m_symGetModuleBase`, `m_symGetSymFromAddr`, and `m_reportText[0x400]`. These names are inferred from binary behavior and should be used in draft C++ until stronger source metadata appears.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004ab480` | `ExceptionHandler` | Sets `g_pCrashTarget`, installs vtable, calls `SetUnhandledExceptionFilter`, and clears crash state. |
| `0x004ab4f0-0x004ab50a` | raw ordinary destructor/reset body | Not modeled as an IDA function; restores the previous filter from `this+8`, writes the vtable, clears `g_pCrashTarget`, and returns. |
| `0x004ab510-0x004ab73b` | crash diagnostic report sender | IDA models `sub_4AB510`; reads `BCrash.nfo`, prefixes OS-version text, packetizes the contents, sends through the packet sender, closes/deletes the file, and has a single caller at `0x005101e8`. |
| [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) | `ExceptionHandler::SendCrashDiagnosticText` | Encodes and sends an already-formatted ANSI diagnostic text packet for timer-skew detection; the callee body does not dereference fields, but caller `0x00466e80` loads [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) into `ECX` immediately before pushing the text and calling the helper, so the best source shape is a nonvirtual class member emitted through [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). |
| `0x004ab810-0x004ab82b` | raw wide-string setter | Not modeled as an IDA function; copies a caller wide string into the object buffer at `this+0x28` with `_wcscpy_s`. |
| [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) | `TopLevelExceptionFilter` | File-static Windows callback now has first-draft child C++; restores [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md), reads [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), skips normal report output through `m_skipCrashReport`, calls the crash-report helper, and may chain to `m_previousFilter`. |
| [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) | `ExceptionHandler::GenerateExceptionReport` | Source-ready `94/96` method writes Windows-directory `BCrash.nfo`, version/exception/register/timer/phase/RGB565 data, and an ImageHlp-or-Intel call stack while preserving exact failure quirks. |
| [UID:00014H][0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString](by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md) | `private: static LPTSTR GetExceptionString(DWORD dwCode);` | Maps 22 SEH codes to direct `TCHAR` names and falls back to mutable shared `TCHAR[512]` storage populated from `NTDLL.DLL`; the static member ABI explains the absence of `this`/`ECX`. |
| `0x004abe4a-0x004abf9c` | exception-code switch data | Parent-only, non-emitting jump and indirect tables used by `GetExceptionString`; followed by parent-only `0xcc` padding to `0x004abfa0`. |
| [UID:00014I][0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress](by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md) | `private: static bool GetLogicalAddress(PVOID address, PTSTR moduleName, DWORD moduleNameLength, DWORD &sectionNumber, DWORD &sectionOffset);` | Exact source lineage and ABI prove a private static method: no `ECX` receiver, five stack arguments, `ret 0x14`, `AL` Boolean return, six internal calls, and out-of-class source body on the exact child page. |
| [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md) | `ExceptionHandler::InitImagehlpFunctions` | Source-ready `94/94` retained method loads `IMAGEHLP.DLL`, resolves/stores six callback pointers at `+0x10..+0x24`, optionally calls `SymSetOptions(7)`, and initializes symbols without failure-path `FreeLibrary`. |
| [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md) | `ExceptionHandler::IntelStackWalk` | Source-ready `94/94` retained raw/non-function-modelled method with 89 instructions and `ret 8`; walks the x86 EBP chain and is also inlined into `GenerateExceptionReport`. |
| [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) | `ExceptionHandler::ImagehlpStackWalk` | Source-ready `94/94` method uses the legacy `STACKFRAME` and callback family when symbols are available. |
| `0x004ac4d0-0x004ac642` | raw frame-chain stack formatter | Not modeled as an IDA function; stack-cookie-protected helper that walks frame-chain/module data for report output. |
| `0x004ac650-0x004ac859` | raw symbol/detail stack formatter | Not modeled as an IDA function; stack-cookie-protected helper adjacent to the stack-walk output code. |
| `0x004ac860` | `ScalarDeletingDestructor` | Restores the previous exception filter, clears `g_pCrashTarget`, and optionally deletes. |

## 2026-06-06 Live IDA Recheck

- `lookup_funcs` maps the constructor to `sub_4AB480`, size `0x6d`, and the scalar deleting destructor to `sub_4AC860`, size `0x3a`; the next function after the aggregate is `sub_4AC8A0` at `0x004ac8a0`.
- `TopLevelExceptionFilter` is a real function at `0x004ab830`, size `0x3f`, with no ordinary code callers and a constructor data reference at `0x004ab49e`, matching `SetUnhandledExceptionFilter`.
- The report writer at `0x004ab870`, size `0x4a0`, is called only from the filter at `0x004ab858` and owns the `BCrash.nfo` version, exception, register, ImageHlp, and fallback frame-chain output.
- Raw body and data islands are now explicit: `0x004ab4f0-0x004ab50a`, `0x004ab510-0x004ab73b`, `0x004ab810-0x004ab82b`, exception-code switch data `0x004abe4a-0x004abf9c`, `0x004ac040-0x004ac0ed`, `0x004ac0f0-0x004ac221`, `0x004ac4d0-0x004ac642`, and `0x004ac650-0x004ac859`.
- Parentage remains [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md); the class is now above the 80/80 parent threshold, so memory children may safely attach to this class or the aggregate page.
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms constructor `sub_4AB480` size `0x6d`, raw ordinary destructor/reset body `0x004ab4f0` as `Not a function`, crash upload helper `sub_4AB510` size `0x22b`, diagnostic text sender `sub_4AB740` size `0xc4`, `TopLevelExceptionFilter` size `0x3f`, crash writer `sub_4AB870` size `0x4a0`, exception-code helper `sub_4ABD10` size `0x13a`, logical-address helper `sub_4ABFA0` size `0x95`, ImageHlp resolver `sub_4AC040` size `0xad`, stack-walk helper `sub_4AC230` size `0x29b`, and scalar deleting destructor `sub_4AC860` size `0x3a`.
- Current xrefs confirm the constructor caller at `0x00463e3a`, filter callback pointer reference at `0x004ab49e`, report-writer call from the filter at `0x004ab858`, scalar destructor vtable cell `0x006196c0`, and `g_pCrashTarget` lifecycle/consumer xrefs including constructor write `0x004ab499`, raw destructor clear `0x004ab4ff`, filter read `0x004ab83a`, scalar destructor clear `0x004ac879`, and the Application-owned destroy helper at `0x004673a0`.
- Historical 2026-06-17 B001 Crasher reanalysis identified the cross-module offset-`+4` byte write under the provisional name `Crasher::TriggerCrash`. Current source reconstruction resolves the method as `Crasher::OnTimer` and the legal source expression as `g_pCrashTarget->SetSkipCrashReport(true)`; this class remains the source owner for the object layout, private flag, and inline setter.
- Historical `analyze_component` output used the provisional label `ExceptionCodeStringHelper` while reporting internal edges `TopLevelExceptionFilter -> ExceptionCrashReportWriter`, `ExceptionCrashReportWriter -> ImageHlpStackWalkHelper`, `ExceptionCrashReportWriter -> ExceptionCodeStringHelper`, `ExceptionCrashReportWriter -> ExceptionLogicalAddressHelper`, and `ImageHlpStackWalkHelper -> ExceptionLogicalAddressHelper`, plus shared `BCrash.nfo` and ImageHlp string/data use across the cluster. The current source identity for that provisional node is `ExceptionHandler::GetExceptionString`; `make_signature_for_range(0x004ab480,0x004ac89a)` returned a unique wildcarded signature for the documented class span.

## 2026-06-18 B005 Layout And Source-Quality Reanalysis

B005 rechecked the aggregate with local IDA exports and byte scans after live MCP was unavailable. The constructor is explicitly called from Application startup after an `operator new(0x828)` allocation; this is not static/global construction. The aggregate remains source-owned by [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md), while [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md) remains Application fatal-load cleanup and [UID:00003A][Crasher](by-class/Crasher.md) remains a consumer of the skip-report flag.

B005 also rechecked [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md). The repaired `.rdata` island starts with this class's complete-object-locator pointer at `0x006196bc` and vtable slot at `0x006196c0`. Draft source should not hand-author those decorated MSVC objects; the class declaration and virtual destructor regenerate them, while crash-report, exception-code, stack/logical-address, and ImageHlp literals stay in the executable helpers.

Recommended source-facing layout:

| Offset | Size | Recommended field | Evidence and status |
| --- | ---: | --- | --- |
| `+0x00` | 4 | vptr | Constructor/destructor/scalar vtable stores to `0x006196c0`. |
| `+0x04` | 1 | `bool m_skipCrashReport` | Constructor clears byte, [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) reads it, Crasher writes it before intentional crash. |
| `+0x05..+0x07` | 3 | compiler-natural alignment, not a source member | Normal 32-bit MSVC alignment places the pointer at `+0x08`; no explicit field is evidenced or emitted. |
| `+0x08` | 4 | `LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter` | Saved from `SetUnhandledExceptionFilter`; destructor restores it; filter chains through it. |
| `+0x0c` | 4 | `m_reserved0C` / padding | No local export or byte scan evidence of meaningful accesses. |
| `+0x10` | 4 | `SYMINITIALIZEPROC m_symInitialize` | Exact legacy `BOOL WINAPI(HANDLE, PCSTR, BOOL)` callback. |
| `+0x14` | 4 | `SYMCLEANUPPROC m_symCleanup` | Exact legacy `BOOL WINAPI(HANDLE)` callback. |
| `+0x18` | 4 | `STACKWALKPROC m_stackWalk` | Exact nine-argument legacy StackWalk callback. |
| `+0x1c` | 4 | `SYMFUNCTIONTABLEACCESSPROC m_symFunctionTableAccess` | Exact `PVOID WINAPI(HANDLE, DWORD)` callback passed to `StackWalk`. |
| `+0x20` | 4 | `SYMGETMODULEBASEPROC m_symGetModuleBase` | Exact `DWORD WINAPI(HANDLE, DWORD)` callback passed to `StackWalk`. |
| `+0x24` | 4 | `SYMGETSYMFROMADDRPROC m_symGetSymFromAddr` | Exact `BOOL WINAPI(HANDLE, DWORD, PDWORD, PIMAGEHLP_SYMBOL)` callback called by UID00014J. |
| `+0x28` | `0x800` / 2048 bytes | `wchar_t m_reportText[0x400]` | Constructor zeroes first char; raw setter copies with count `0x400` / 1024 wide chars. No confirmed read/caller path yet. |

Current declarations expose the constructor, virtual destructor, `SetReportText`, `SendCrashDiagnosticText`, `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, `ImagehlpStackWalk`, inline `SetSkipCrashReport`, `ShouldSkipCrashReport`, and `PreviousFilter`, plus exact private static `GetExceptionString` and `GetLogicalAddress` declarations. The six callback fields use the exact legacy procedure typedefs shown in the formal block. `SendCrashDiagnosticText` remains a nonvirtual member because its sole caller passes [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) in `ECX`; earlier file-static and `WriteCrashReport`/`InitializeImageHlp`/`WriteImageHlpStackWalk` spellings are preserved only in dated historical sections. File-static `TopLevelExceptionFilter` remains on its exact child, and the scalar deleting destructor/vtable/RTTI/security-cookie artifacts remain compiler-generated rather than hand-authored.

## 2026-07-14 B003 GetExceptionString Declaration Synchronization

- The declaration required by the exact target body is `private: static LPTSTR GetExceptionString(DWORD dwCode);`. Microsoft `MSJEXHND` source and header independently supply the class, access, storage-class, return-type, method-name, and parameter spelling.
- Static membership explains the binary ABI: no `this` pointer or meaningful incoming `ECX` is consumed at `0x004abd10`, and the sole argument is the caller-pushed `DWORD` exception code. That ABI is positive evidence for the class-static declaration, not file-static ownership.
- `LPTSTR` is intentionally mutable because direct cases return macro-generated `TCHAR` literals under the era's non-const signature and the fallback returns one shared writable `static TCHAR szBuffer[512]`. The pointer remains valid after return but fallback calls overwrite the same storage; callers neither provide nor own an output buffer.
- The method stays `private`, as in the recovered header. Its two calls originate inside the crash-report implementation, so no public API exposure or friend/access workaround is needed.
- The class formal block remains blank in this callback because the accepted scope supplies the complete method body on UID00014H and exact declaration guidance here, not a complete safe reconstruction of the broader `0x828` class. This preserves the existing owner/emitter route and does not turn an incomplete class shell into generated source.
- Scores remain `87/90`: UID00014H's name/type/access blocker is closed, but independent raw-helper liveness, exact spellings elsewhere in the family, and the full source-safe class declaration remain broader class-level caps.

## 2026-07-16 B003 GetLogicalAddress Declaration Synchronization

- The exact declaration is `private: static bool GetLogicalAddress(PVOID address, PTSTR moduleName, DWORD moduleNameLength, DWORD &sectionNumber, DWORD &sectionOffset);`.
- Static membership is positively supported by exact header lineage and the binary ABI: the method consumes no object receiver or incoming `ECX`, receives five stack arguments, performs callee cleanup with `ret 0x14`, and returns the Nexus Boolean through `AL`.
- Six internal call sites are proven at `0x004ab939`, `0x004abc52`, `0x004ac190`, `0x004ac3e1`, `0x004ac440`, and `0x004ac7b4`. All pass a 260-character module buffer capacity and ignore the Boolean result while relying on caller initialization appropriate to each path.
- The source body remains on UID00014I and uses generic `GetModuleFileName`; the linked PlatformApi slot is concretely `GetModuleFileNameW`. Wide dispatch storage does not transfer method ownership out of this class.
- The former file-static, pointer-output, four-caller, unresolved-module-helper, and `BOOL` descriptions are historical proposals superseded by exact source/ABI/xref evidence.
- The class formal remains blank. This target closes its declaration and body, but an independently complete class shell remains unsafe because the unrelated `+0x0c` member and full raw-helper declaration/access set are unresolved. Scores remain `87/90` for those broader reasons.

Recommended inline accessors for the file-static callback:

```cpp
bool ShouldSkipCrashReport() const { return m_skipCrashReport; }
LPTOP_LEVEL_EXCEPTION_FILTER PreviousFilter() const { return m_previousFilter; }
```

[UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) should remain modeled as a file-static `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)` callback in `platform/ExceptionHandler.cpp`, not as a class virtual method. If later declaration evidence proves the original source used a friend callback, public fields, or a static member, that is an access-style refinement only; the behavior and field roles do not change.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The page records the complete class declaration, exact `0x828` layout, source owner, constructor/destructor/filter/report inventory, source-ready Generate/Init/Intel/ImageHlp helper family, six exact callback typedefs, callback/global xrefs, `g_pCrashTarget` lifecycle, compiler exclusions, and exact child-emission route. |
| Confidence | 95 | Live IDA, source-family lineage, exact child bodies, the file/global/memory pages, and callback-member use agree on ownership, method identities, ABI, and field roles. Only unavailable original Nexus symbols/source and rebuilt-binary comparison prevent final historical certainty. |

## Ownership Notes

Place in `platform/ExceptionHandler.cpp` for now. Do not group it with generic imported C++ exception/runtime code. Keep [UID:00003A][Crasher](by-class/Crasher.md) as a companion class until source grouping is confirmed.

## Cross-References

- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md)
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md)
- [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md)

## Changes

- 2026-08-06 B005 UID000298 Crasher dependency synchronization:
  - Added exact public inline `SetSkipCrashReport(bool)` in the formal H block without changing the `0x828` layout or current scores.
  - Documented it as the legal source expression for Crasher's observed `[g_pCrashTarget + 4] = 1` write; `m_skipCrashReport` remains private and TopLevelExceptionFilter retains the read side.

- 2026-07-16 B003 GetLogicalAddress implementation support sync:
  - Preserved `87/90`, owner/emitter UID0000J8, exact `0x828` layout, blank formal, and all unrelated class evidence.
  - Added the exact private static Boolean declaration, no-`ECX`/five-stack-argument/`AL` ABI proof, six-call inventory, source-lineage and W-dispatch evidence, and historical correction.
- 2026-07-14 B003 GetExceptionString implementation support sync:
  - Preserved `87/90`, owner/emitter [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md), exact `0x828` layout evidence, and the accepted blank formal block.
  - Added the exact private static `LPTSTR GetExceptionString(DWORD dwCode)` row/declaration, static-member ABI explanation, mutable shared fallback-buffer lifetime, and source/header lineage.
  - Historicalized file-static `GetExceptionCodeText` without disturbing unrelated helper declarations, layouts, compiler exclusions, or score caps.

- 2026-06-18 B005 source-quality incorporation:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`.
  - Evidence: added the source-facing layout, field names, explicit Application allocation route, ExceptionHandler.cpp source-placement conclusion, Crasher/Application ownership boundaries, [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) vtable/COL source route, and aggregate/child C++ policy. Exact original helper spellings and raw no-static-caller helper liveness remain score-capping only.
- 2026-06-20 B001/B015 TopLevelExceptionFilter child sync:
  - Score unchanged at `87/90`.
  - Added first-draft declaration guidance for [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md): keep it file-static/free-helper shaped, use inline `ShouldSkipCrashReport()` and `PreviousFilter()` accessors unless later declaration evidence proves a friend/static-member/public-field style, and preserve `m_skipCrashReport`/`m_previousFilter` as the current source-facing field names.
- 2026-06-20 B005 CrashDiagnosticTextSender child sync:
  - Score unchanged at `87/90`.
  - Historical note: the earlier pass treated [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) as a file-static helper because the callee body has no object-field access.
- 2026-06-22 B013 CrashDiagnosticTextSender member-call correction:
  - Score unchanged at `87/90`.
  - Reclassified [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) as a nonvirtual `ExceptionHandler::SendCrashDiagnosticText(const char *)` member helper after B013 rechecked caller `0x00466e80` and found `ECX = g_pCrashTarget` immediately before the call. The method body remains emitted on the exact child page through this class into [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md).
- 2026-06-17 B001 Crasher source-quality sync:
  - Score unchanged at `86/89`.
  - Added the inferred suppress/skip-report field direction at object offset `+4`; later B005 source-quality work promoted the descriptive draft name to `m_skipCrashReport`.
- 2026-06-06 A001 live IDA recheck:
  - Before: `COMPLETION:76`, `CONFIDENCE:80`, and only coarse constructor/filter/report helper coverage.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`; final C++ remained blank because helper names, field names, and declarations were not source-quality.
  - Evidence: live IDA reconfirms constructor/destructor/filter/report bounds, callback pointer reference, report-writer caller/callee behavior, next-function boundary, and previously undocumented raw helper/data islands in the aggregate range.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/80`.
  - Summary/evidence: process exception-filter role, constructor, top-level filter, crash report/text/address/stack helpers, singleton/global ownership, and companion `Crasher` links are documented; remaining uncertainty is final folder placement and exact source-facing helper names.
- 2026-06-15 A002 Goal 2 by-class refresh: raised from `82/86` to `86/89` with no owner/emitter changes and synchronized the stale coverage-report row. Live IDA reconfirmed method/helper sizes, raw reset-body status, constructor/filter/report/destructor xrefs, `g_pCrashTarget` lifecycle refs, internal crash-report helper graph, shared crash/ImageHlp strings, unique class-span signature, and Application ownership of the external destroy helper. C++ remains blank because helper names, field names, and source declarations are not source-quality.

## B001 UID0003TY Complete Declaration Synchronization - 2026-07-20

- The managed block now provides one complete `ExceptionHandler` declaration at `91/92`, owner/emitter UID0000J8, reconstructable true, blank position. It declares constructor, virtual ordinary destructor, text/report helpers, new [UID:0004TS][0x004ab510-0x004ab73b.ExceptionHandlerSendStoredCrashReportFile](by-memory/0x004ab510-0x004ab73b.ExceptionHandlerSendStoredCrashReportFile.md), existing diagnostic/report/ImageHlp methods, accessors used by the file-static filter, and the two proven private static helpers.
- Exact layout is `bool m_skipCrashReport` at `+0x04`, then normal 32-bit compiler alignment before `m_previousFilter` at `+0x08`. There is no explicit `m_alignment05[3]`, reserved-tail array, or other fake source member for `+0x05..+0x07`.
- Real unresolved storage `DWORD m_reserved0C` remains at `+0x0c`. No access supports a stronger semantic name, so it is retained as layout-only rather than silently removed or conflated with natural alignment.
- IMAGEHLP function pointers occupy `+0x10..+0x27`; `wchar_t m_reportText[0x400]` begins at `+0x28`. Constructor allocation, all field accesses, and scalar-delete operand establish exact `sizeof(ExceptionHandler) == 0x828`, enforced by the source guard.
- UID0004TS receives `ECX = g_pCrashTarget` from UID0003TY and is therefore a nonvirtual member, superseding the historical file-static classification. It builds the OS prefix, reads/deletes `BCrash.nfo`, and sends opcode `0x42` subtype 1 without moving PlatformApi, Socket, or report-file ownership into the class layout.
- Class declaration closes before `[[CHILDREN]]`; vptr/RTTI/EH/cookie/scalar-delete/base-teardown and SetUnhandledExceptionFilter callback lowering remain compiler output. Exact child bodies remain on their own pages and are not duplicated here.
- Historical blank-C++, unresolved declaration, explicit-source-padding, and file-static stored-report conclusions are superseded. Existing Crasher flag evidence, top-level callback, report writer, diagnostic sender, logical-address helpers, stack walkers, ordinary destructor, global lifecycle, retained raw bodies, and all unrelated history remain preserved.

## 2026-07-24 B001 GenerateExceptionReport Family Declaration Closure

- The class is now `93/95` with source-lineage-backed declarations `void GenerateExceptionReport(EXCEPTION_POINTERS *)`, `BOOL InitImagehlpFunctions()`, `void IntelStackWalk(CONTEXT *, FILE *)`, and `void ImagehlpStackWalk(CONTEXT *, FILE *)`.
- Exact callback typedefs are `SYMINITIALIZEPROC`, `SYMCLEANUPPROC`, `STACKWALKPROC`, `SYMFUNCTIONTABLEACCESSPROC`, `SYMGETMODULEBASEPROC`, and `SYMGETSYMFROMADDRPROC`. Each is a four-byte `WINAPI` procedure pointer under the 32-bit build, and each field remains at its proven `+0x10..+0x24` offset.
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md), [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md), [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md), and [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) own their exact formal bodies. The class block supplies declarations plus `[[CHILDREN]]`; it does not duplicate those bodies.
- Exact layout remains vptr `+0x00`, `m_skipCrashReport +0x04`, natural alignment `+0x05..+0x07`, `m_previousFilter +0x08`, unresolved-but-real `m_reserved0C +0x0c`, six callback pointers, and `m_reportText[0x400] +0x28`, for total size `0x828`.
- Dated statements that the class formal was blank, target-family names/liveness were unresolved, or helper bodies were future work are historical snapshots superseded by this closure. Unrelated retained raw ranges and the unread `m_reportText` path remain documented without blocking the accepted declaration.
