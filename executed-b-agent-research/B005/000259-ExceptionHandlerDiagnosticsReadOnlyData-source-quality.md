** TARGET-REPORT-UID:000259 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000259] ExceptionHandlerDiagnosticsReadOnlyData Source-Quality Report

Agent: B005  
Target: `by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`  
Assignment: report-only B-preferred source-quality and heuristic/inference pass  
Date: 2026-06-18

## Final Recommendation

Raise the current target from `84/89` to `86/90` if the supervisor keeps the current half-open path `0x006196c0-0x00619d28`. Keep:

```text
CANONICAL_OWNER:0000J8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000J8
```

Preferred structural repair: move the preceding four-byte `ExceptionHandler` complete-object-locator pointer at `0x006196bc-0x006196c0` out of [UID:000258] and into this page. With that range repair, rename this page to `0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md` and score it `87/91`. Without that repair, the current page is still above the gate because every byte inside `0x006196c0-0x00619d28` has a defensible source route, but the missing COL pointer is a real boundary defect and caps the page at `86/90`.

Do not populate this target's formal `RECONSTRUCTION_CPP CODE` block with a raw `.rdata` declaration. The source-authored declarations belong in [UID:00004P] `ExceptionHandler`, [UID:0000J8] `platform/ExceptionHandler.cpp`, and the executable consumer pages. This read-only-data page should document the binary layout and source route, while the compiler/linker regenerate the vtable, RTTI, pooled literals, and private string literals from the class declaration and consumer code.

## Evidence Sources Checked

- Required guidance: `Supervisor.md`, `Agent-B005/goal.md`, `Agent-B005/notes.md`, `by-structure.md`, and `inference_research.md`.
- Current target and support docs: [UID:000259], [UID:000258], [UID:00025A], [UID:00004P], [UID:0000J8], [UID:00014D], [UID:00014E], [UID:00014F], [UID:00014G], [UID:00014H], [UID:00014I], [UID:00014J], [UID:0000QN], and [UID:0001QB].
- Prior accepted report: `research/executed/00014D-ExceptionHandler-source-quality.md`.
- Local IDA-derived exports: `memory.bin`, segment metadata, globals, functions, strings, xrefs, and decompile JSON under `C:\Users\admin\Desktop\CTools\Output\ida`.
- Generated context: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, and zero-byte `auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- IDA MCP status: unavailable during this pass. The direct endpoint request could not connect, so every renewed fact below is from local binary/export/doc evidence rather than live IDA MCP.

> The removed literal PowerShell command is preserved only in [000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality-removed.md](000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality-removed.md). The archive is non-authoritative and must not be executed.

## Byte And Boundary Reanalysis

The assigned half-open range is `0x006196c0-0x00619d28`, size `0x668` / 1640 bytes (Verified with `int_convert.py`). The preferred repaired vtable/COL range is `0x006196bc-0x00619d28`, size `0x66c` / 1644 bytes (Verified with `int_convert.py`).

| Address span | Bytes / object | Reanalysis result |
| --- | --- | --- |
| `0x006196bc-0x006196c0` | dword `0x00647168` | `ExceptionHandler` RTTI complete-object-locator pointer. It currently belongs to predecessor [UID:000258] only because [UID:000259] starts at the vtable label. This should move into [UID:000259] if range repair is allowed. |
| `0x006196c0-0x006196c4` | dword `0x004ac860` | Sole `ExceptionHandler` vtable slot, the scalar deleting destructor. Constructor/destructor/scalar stores use this vtable base. |
| `0x006196c4-0x0061973c` | ASCII OS/version prefix literals | `Win95:%02d%02d :`, `Win98:%02d%02d :`, `WinME:%02d%02d :`, `Unknown:%02d%02d :`, `Win2K:%02d%02d :`, `WinXP:%02d%02d :`. |
| `0x0061973c-0x00619770` | UTF-16 file/path/mode literals | `L"BCrash.nfo"`, `L"%s\\%s"`, `L"rt"`, `L"wt"`. The path/mode literals include pooled generic forms used outside ExceptionHandler. |
| `0x00619770-0x006198b4` | ASCII crash-report format strings | Version, exception-code, fault-address, register, segment, flags/time/phase/pixel-format, and separator formats. |
| `0x006198b4-0x00619bd4` | UTF-16 exception-code names and fallback module literal | Direct SEH/NTSTATUS name literals plus `L"NTDLL.DLL"`. No `.rdata` pointer table was found here; the executable switch/helper selects literal addresses. |
| `0x00619bd4-0x00619c68` | ASCII stack/logical-address formats | `Call stack`, frame/header, logical address, symbol, and fallback frame formats. |
| `0x00619c68-0x00619cb0` | UTF-16 raw helper formats and module literal | `L"%08X -> "`, `L"%hs+%X -> "`, and `L"IMAGEHLP.DLL"`. |
| `0x00619cb0-0x00619d28` | ASCII ImageHlp API-name literals and terminal padding | `SymInitialize`, `SymCleanup`, `StackWalk`, `SymFunctionTableAccess`, `SymGetModuleBase`, `SymGetSymFromAddr`, and `SymSetOptions`; the string terminator/padding ends exactly before the next object. |
| `0x00619d28` | dword `0x00647204` | Start of [UID:00025A]/[UID:0003NE] successor data, the `ExchangeDialog` COL pointer. Not part of this target. |

There is no unexplained padding before the current start other than the misplaced COL pointer. There is no unexplained data after `SymSetOptions`; the null terminator and alignment bytes end at `0x00619d28`, followed immediately by the `ExchangeDialog` COL pointer.

## Literal And Object Inventory

| VA | Kind | Source-facing value / identity | Main consumer evidence |
| --- | --- | --- | --- |
| `0x006196bc` | dword, outside current target | `ExceptionHandler` COL pointer `0x00647168` | Boundary repair candidate; should be grouped with vtable. |
| `0x006196c0` | dword | `ExceptionHandler` scalar deleting destructor slot `0x004ac860` | Constructor/destructor/scalar stores at `0x004ab4a3/0x004ab4a5`, `0x004ab4f3/0x004ab4f5`, and `0x004ac869/0x004ac86b`. |
| `0x006196c4` | char literal | `"Win95:%02d%02d : "` | `sub_4AB510` OS prefix selection. |
| `0x006196d8` | char literal | `"Win98:%02d%02d : "` | `sub_4AB510` OS prefix selection. |
| `0x006196ec` | char literal | `"WinME:%02d%02d : "` | `sub_4AB510` OS prefix selection. |
| `0x00619700` | char literal | `"Unknown:%02d%02d : "` | `sub_4AB510` default/unknown OS prefix selection. |
| `0x00619714` | char literal | `"Win2K:%02d%02d : "` | `sub_4AB510` OS prefix selection. |
| `0x00619728` | char literal | `"WinXP:%02d%02d : "` | `sub_4AB510` OS prefix selection. |
| `0x0061973c` | wide literal | `L"BCrash.nfo"` | Open/read/write crash report paths in `0x004ab510` and [UID:00014G]. |
| `0x00619754` | wide literal | `L"%s\\%s"` | ExceptionHandler path construction plus pooled screenshot path use in [UID:0001G9]. |
| `0x00619760` | wide literal | `L"rt"` | ExceptionHandler read mode plus pooled PhoneBookDialog load use. |
| `0x00619768` | wide literal | `L"wt"` | ExceptionHandler write mode plus pooled PhoneBookDialog save use. |
| `0x00619770` | char literal | `"%d.%d.Eng.R\n"` | [UID:00014G] crash-report version line. |
| `0x00619780` | char literal | `"Exception code: %08X %s\n"` | [UID:00014G] exception-code output. |
| `0x0061979c` | char literal | `"Fault address:  %08X %02X:%08X %s\n"` | [UID:00014G] fault-address output. |
| `0x006197c0` | char literal | `"\nRegisters:\n"` | [UID:00014G] register heading. |
| `0x006197d0` | char literal | `"EAX:%08X\nEBX:%08X\nECX:%08X\nEDX:%08X\nESI:%08X\nEDI:%08X\n"` | [UID:00014G] general-register output. |
| `0x00619808` | char literal | `"CS:EIP:%04X:%08X\n"` | [UID:00014G] code segment/instruction pointer output. |
| `0x0061981c` | char literal | `"SS:ESP:%04X:%08X  EBP:%08X\n"` | [UID:00014G] stack pointer/base pointer output. |
| `0x00619838` | char literal | `"DS:%04X  ES:%04X  FS:%04X  GS:%04X\n"` | [UID:00014G] data segment output. |
| `0x0061985c` | char literal | `"Flags:%08X Time:%d Phase:%d 565:%d\n\n"` | [UID:00014G] flags/time/phase/pixel-format output. |
| `0x00619884` | char literal | `"-----------------------------------------------"` | [UID:00014G] report separator. |
| `0x006198b4` | wide literal | `L"ACCESS_VIOLATION"` | [UID:00014H] SEH code-name helper. |
| `0x006198d8` | wide literal | `L"DATATYPE_MISALIGNMENT"` | [UID:00014H] SEH code-name helper. |
| `0x00619904` | wide literal | `L"BREAKPOINT"` | [UID:00014H] SEH code-name helper. |
| `0x0061991c` | wide literal | `L"SINGLE_STEP"` | [UID:00014H] SEH code-name helper. |
| `0x00619934` | wide literal | `L"ARRAY_BOUNDS_EXCEEDED"` | [UID:00014H] SEH code-name helper. |
| `0x00619960` | wide literal | `L"FLT_DENORMAL_OPERAND"` | [UID:00014H] SEH code-name helper. |
| `0x0061998c` | wide literal | `L"FLT_DIVIDE_BY_ZERO"` | [UID:00014H] SEH code-name helper. |
| `0x006199b4` | wide literal | `L"FLT_INEXACT_RESULT"` | [UID:00014H] SEH code-name helper. |
| `0x006199dc` | wide literal | `L"FLT_INVALID_OPERATION"` | [UID:00014H] SEH code-name helper. |
| `0x00619a08` | wide literal | `L"FLT_OVERFLOW"` | [UID:00014H] SEH code-name helper. |
| `0x00619a24` | wide literal | `L"FLT_STACK_CHECK"` | [UID:00014H] SEH code-name helper. |
| `0x00619a44` | wide literal | `L"FLT_UNDERFLOW"` | [UID:00014H] SEH code-name helper. |
| `0x00619a60` | wide literal | `L"INT_DIVIDE_BY_ZERO"` | [UID:00014H] SEH code-name helper. |
| `0x00619a88` | wide literal | `L"INT_OVERFLOW"` | [UID:00014H] SEH code-name helper. |
| `0x00619aa4` | wide literal | `L"PRIV_INSTRUCTION"` | [UID:00014H] SEH code-name helper. |
| `0x00619ac8` | wide literal | `L"IN_PAGE_ERROR"` | [UID:00014H] SEH code-name helper. |
| `0x00619ae4` | wide literal | `L"ILLEGAL_INSTRUCTION"` | [UID:00014H] SEH code-name helper. |
| `0x00619b0c` | wide literal | `L"NONCONTINUABLE_EXCEPTION"` | [UID:00014H] SEH code-name helper. |
| `0x00619b40` | wide literal | `L"STACK_OVERFLOW"` | [UID:00014H] SEH code-name helper. |
| `0x00619b60` | wide literal | `L"INVALID_DISPOSITION"` | [UID:00014H] SEH code-name helper. |
| `0x00619b88` | wide literal | `L"GUARD_PAGE"` | [UID:00014H] SEH code-name helper. |
| `0x00619ba0` | wide literal | `L"INVALID_HANDLE"` | [UID:00014H] SEH code-name helper. |
| `0x00619bc0` | wide literal | `L"NTDLL.DLL"` | [UID:00014H] fallback module lookup. |
| `0x00619bd4` | char literal | `"Call stack:\n"` | [UID:00014G] and raw stack formatter. |
| `0x00619be4` | char literal | `"Address   Frame     Logical addr  Module\n"` | [UID:00014G], raw stack formatter, and [UID:00014J]. |
| `0x00619c10` | char literal | `"%08X  %08X  %04X:%08X %ws\n"` | [UID:00014G] and raw stack formatter. |
| `0x00619c2c` | char literal | `"%08X\n"` | [UID:00014G], raw stack formatter, and [UID:00014J]. |
| `0x00619c34` | char literal | `"Call stack\n"` | [UID:00014J] ImageHlp stack header. |
| `0x00619c40` | char literal | `"%08X  %08X  "` | [UID:00014J] frame/address prefix. |
| `0x00619c50` | char literal | `"%hs+%X\n"` | [UID:00014J] symbol+offset output. |
| `0x00619c58` | char literal | `"%04X:%08X %ws\n"` | [UID:00014J] logical address fallback. |
| `0x00619c68` | wide literal | `L"%08X -> "` | Raw logical-address/string formatting helpers at `0x004ac4d0` and `0x004ac650`. |
| `0x00619c7c` | wide literal | `L"%hs+%X -> "` | Raw symbol/detail formatter at `0x004ac650`. |
| `0x00619c94` | wide literal | `L"IMAGEHLP.DLL"` | [UID:00014G] and resolver body `0x004ac040-0x004ac0ed`. |
| `0x00619cb0` | char literal | `"SymInitialize"` | `GetProcAddress` API-name literal. |
| `0x00619cc0` | char literal | `"SymCleanup"` | `GetProcAddress` API-name literal. |
| `0x00619ccc` | char literal | `"StackWalk"` | `GetProcAddress` API-name literal. |
| `0x00619cd8` | char literal | `"SymFunctionTableAccess"` | `GetProcAddress` API-name literal. |
| `0x00619cf0` | char literal | `"SymGetModuleBase"` | `GetProcAddress` API-name literal. |
| `0x00619d04` | char literal | `"SymGetSymFromAddr"` | `GetProcAddress` API-name literal. |
| `0x00619d18` | char literal | `"SymSetOptions"` | `GetProcAddress` API-name literal. |

## Consumer And Reachability Revalidation

The vtable slot is reached through source-owned `ExceptionHandler` construction and destruction, not through a generic runtime island. Local xref export/pointer evidence ties the vtable base at `0x006196c0` to the constructor store in [UID:00014D], the raw ordinary destructor/reset store, and the scalar deleting destructor at `0x004ac860`.

The OS-version strings are selected by `sub_4AB510`, the raw wide-string setter/startup diagnostic helper documented by the ExceptionHandler aggregate. They are not an independent OS utility table because every in-range OS prefix consumer belongs to the ExceptionHandler diagnostics cluster.

The crash-report path and report-format strings are consumed by [UID:00014G] `ExceptionCrashReportWriter`. The local decompile export confirms the writer uses `L"BCrash.nfo"`, `L"%s\\%s"`, `L"wt"`, the version line, exception/fault/register/flags formats, stack headers, `L"IMAGEHLP.DLL"`, and the ImageHlp API-name literals.

The exception-code string block is consumed by [UID:00014H]. The renewed pass rejects a separate `.rdata` pointer-table model for this page: the strings are stored contiguously, but the selection logic returns direct literal addresses from executable switch/helper code. The switch/control data belongs to the executable helper page, not this read-only-data page.

The stack/logical-address formats are shared inside the ExceptionHandler source file between [UID:00014G], raw helper bodies around `0x004ac0f0`, [UID:00014I], raw helper bodies around `0x004ac4d0` and `0x004ac650`, and [UID:00014J]. This supports one file owner, not separate support-file emission.

The ImageHlp API-name literals are consumed by both [UID:00014G] and the resolver body documented under [UID:00014D]. They are best modeled as `GetProcAddress` string literals in `platform/ExceptionHandler.cpp`, not as hand-authored exported tables.

The only cross-module literal pooling found inside the target is limited to `L"%s\\%s"`, `L"rt"`, and `L"wt"`:

- `L"%s\\%s"` is also used by screenshot path construction in [UID:0001G9].
- `L"rt"` and `L"wt"` are also used by PhoneBookDialog load/save paths.

This does not defeat the [UID:0000J8] owner for the aggregate target. It means those three literals should be expressed inline at each source use and allowed to pool, not named as `ExceptionHandler`-unique globals. A future literal-pooling cleanup could split `0x00619754-0x00619770` into a shared literal child, but that is not required to complete this target and would be broader than the current assignment.

## Ranked Ownership And Source Placement

1. [UID:0000J8] `ExceptionHandler` / `platform/ExceptionHandler.cpp`: best owner and emitter. It owns the dominant vtable, crash-report strings, exception-code literals, stack/logical-address formats, and ImageHlp resolver API-name strings.
2. [UID:00004P] `ExceptionHandler` class: correct class owner for the vtable/COL/RTTI and field/method declarations, but not the emitter for all format literals by itself.
3. `CANONICAL_OWNER:NONE` / shared pooled literals: rejected for the whole target. Only three generic wide literals have cross-module pooling evidence; the rest of the page is ExceptionHandler-specific.
4. [UID:000258] `ErrorEventReadOnlyData`: rejected as an owner. It currently includes the `0x006196bc` COL pointer due to a range boundary defect, but the pointer belongs with `ExceptionHandler`, not Error/Event.
5. [UID:00025A] `ExchangeItemReadOnlyData`: rejected. It begins at `0x00619d28` with `ExchangeDialog` COL pointer `0x00647204`; no byte inside the assigned half-open target belongs to Exchange/Item.
6. ScreenshotCapture and PhoneBookDialog: rejected as target owners. Their evidence is limited to pooled `L"%s\\%s"`, `L"rt"`, and `L"wt"` literals.
7. Generic crash diagnostics support file: rejected. The already-accepted [UID:00014D] pass established `platform/ExceptionHandler.cpp`, and this target's consumers cluster around the same source file and class.

## Source-Facing Declaration Recommendations

Do not hand-author the `ExceptionHandler` vtable, RTTI COL, or MSVC decorated symbols. The source-facing declaration belongs on [UID:00004P] as the `ExceptionHandler` class with a virtual destructor/scalar-delete-compatible destructor shape. The compiler should regenerate `??_7ExceptionHandler@@6B@` and the COL/RTTI metadata.

The crash-report writer should use local/private literals in [UID:00014G] rather than a raw static byte blob. The source shape should be ordinary C/C++ formatting code using the observed values:

```cpp
// Declaration shape only; do not paste into the [UID:000259] formal block.
static const wchar_t kCrashReportFileName[] = L"BCrash.nfo";

static const char* FormatWindowsVersionPrefix(/* OSVERSIONINFO or equivalent */);
static const wchar_t* FormatExceptionCodeName(DWORD code);

// In ExceptionHandler::WriteCrashReport or its helper:
// fprintf(file, "%d.%d.Eng.R\n", ...);
// fprintf(file, "Exception code: %08X %s\n", ...);
// fprintf(file, "Fault address:  %08X %02X:%08X %s\n", ...);
// fprintf(file, "\nRegisters:\n");
// fprintf(file, "EAX:%08X\nEBX:%08X\nECX:%08X\nEDX:%08X\nESI:%08X\nEDI:%08X\n", ...);
// fprintf(file, "Flags:%08X Time:%d Phase:%d 565:%d\n\n", ...);
```

The exception-code helper should be represented as a switch over SEH/NTSTATUS constants that returns the observed wide literals. A named array is less likely than a switch because the renewed `.rdata` pass found direct literal storage and the executable helper selects addresses, while no contiguous pointer table for the names appears inside this range.

The ImageHlp resolver should keep the API-name strings as `GetProcAddress` literals in the resolver/writer code:

```cpp
// Declaration shape only; do not paste into the [UID:000259] formal block.
HMODULE imageHelp = LoadLibraryW(L"IMAGEHLP.DLL");
resolve("SymInitialize");
resolve("SymCleanup");
resolve("StackWalk");
resolve("SymFunctionTableAccess");
resolve("SymGetModuleBase");
resolve("SymGetSymFromAddr");
resolve("SymSetOptions");
```

The pooled `L"%s\\%s"`, `L"rt"`, and `L"wt"` values should remain ordinary literals at each use site. Do not introduce `ExceptionHandler`-specific globals for them.

## First-Draft C++ / No-Code Proof

Formal C++ on [UID:000259] should remain blank. This is target-specific, not a generic refusal:

- The `0x006196bc` COL pointer and `0x006196c0` vtable slot are compiler-generated from the [UID:00004P] class declaration. Hand-authoring them would create source that does not match normal mid-2000s MSVC project style.
- The diagnostic strings are source-authored, but their correct source locations are executable consumers: [UID:00014G] for crash-report formats, [UID:00014H] for exception-code names, [UID:00014I]/raw helpers/[UID:00014J] for logical-address and stack formatting, and the ImageHlp resolver body for API names.
- The target is an aggregate `.rdata` island containing pooled literals and compiler-generated data. A single formal code block on this page would either duplicate child/consumer code or invent artificial global arrays that the evidence does not require.
- The existing generated `platform/ExceptionHandler.cpp` is zero bytes, so there is no source-output precedent to preserve here. Emission should be driven by the class/file and child executable pages, not this raw data page.

Therefore the target is reconstructable as source-declared/generated-binary evidence, but declaration-only from this page. This justifies `86/90` in the current range and `87/91` after the COL boundary repair, while withholding a formal `RECONSTRUCTION_CPP CODE` block on [UID:000259].

## Heuristic / Inference Reanalysis And Validation

### Boundary Against [UID:000258]

Evidence checked: raw bytes before target, current [UID:000258] doc, current [UID:000259] doc, adjacent vtable conventions, and [UID:0003NE] style for including COL pointers before vtable slots.

Rejected alternative: keep `0x006196bc` as Error/Event data. That byte pattern is a pointer to `0x00647168`, and the next dword is the `ExceptionHandler` vtable slot. It has no defensible Error/Event ownership.

Best inference: current [UID:000259] is exact for the vtable-base/literal span, but not exact for the full vtable/COL object. Preferred repair is [UID:000258] ending at `0x006196bc` and [UID:000259] starting at `0x006196bc`.

Effect: current path can score `86/90`; repaired path can score `87/91`. It does not change owner/emitter.

### Boundary Against [UID:00025A]

Evidence checked: raw dword at `0x00619d28`, [UID:00025A], and [UID:0003NE] ExchangeDialog child docs.

Rejected alternative: extend [UID:000259] through `0x00619d2c` or later. The dword at `0x00619d28` is `0x00647204`, the `ExchangeDialog` COL pointer, followed by the `ExchangeDialog` vtable slot at `0x00619d2c`.

Best inference: `0x00619d28` is the correct exclusive end for [UID:000259] under both current and repaired start options.

Effect: no split or extension at the successor boundary.

### Exception-Code Lookup Shape

Evidence checked: literal inventory, xrefs/pointer hits to each wide string, [UID:00014H], and local decompile for `0x004abd10`.

Rejected alternative: declare a `.rdata` array of exception-code/name pairs on [UID:000259]. The in-range bytes are only string literals; the selection logic resides in code and switch/control data outside this `.rdata` span.

Best inference: [UID:00014H] should emit a switch or equivalent helper returning observed wide literals, preferably using Windows exception constants where available.

Effect: source readiness improves; no formal [UID:000259] code block.

### ImageHlp API-Name Data

Evidence checked: API literal ordering, [UID:00014G], resolver body in [UID:00014D], and accepted [UID:00014D] ImageHlp field names.

Rejected alternative: a separate `ImageHlpImports` static table emitted by [UID:000259]. The decompile evidence shows repeated `GetProcAddress`-style literal consumption and field stores, not a standalone table structure in this range.

Best inference: keep API names inline or in a tiny private resolver-local declaration in `platform/ExceptionHandler.cpp`.

Effect: supports [UID:0000J8] owner/emitter and raises source quality without creating artificial global data.

### Pooled Path And File-Mode Literals

Evidence checked: cross-module refs for `L"%s\\%s"`, `L"rt"`, and `L"wt"`; screenshot and PhoneBookDialog docs.

Rejected alternative: demote the whole page to `CANONICAL_OWNER:NONE` due to pooling. Only three short generic literals are pooled, while all dominant data is ExceptionHandler-specific.

Best inference: leave the aggregate owner as [UID:0000J8], but document that these three literals are source-inline pooled values and not unique ExceptionHandler globals.

Effect: no metadata owner change; prevents false source declarations.

### Source Placement

Evidence checked: [UID:0000J8], [UID:00004P], [UID:00014D] accepted report, `client_crash_diagnostics`, and current generated source path.

Rejected alternatives: generic platform diagnostics support file, Error/Event support file, Exchange/Item support file, ScreenshotCapture, PhoneBookDialog.

Best inference: source placement remains `platform/ExceptionHandler.cpp`, with class declarations in [UID:00004P] and executable/literal use in [UID:00014G]/[UID:00014H]/[UID:00014I]/[UID:00014J] plus raw helpers.

Effect: keep `CANONICAL_OWNER:0000J8` and `EMITTER_UIDS:0000J8`.

### Final C++ Readiness

Evidence checked: target blank block, zero-byte generated `ExceptionHandler.cpp`, consumer docs, byte inventory, and compiler-generated vtable/RTTI model.

Rejected alternative: fill [UID:000259] with artificial static arrays or decorated vtable symbols. That would be less source-faithful than ordinary class declarations and consumer literals.

Best inference: declaration-only/no formal code block on this read-only-data page. First-draft C++ belongs on class/file/consumer pages.

Effect: current page can still pass above 85 as reconstructable source-declared/generated-binary data, but should not claim standalone C++ emission.

## Metadata Recommendations

If supervisor keeps the current target path:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

If supervisor applies the preferred range repair:

```text
Rename:
by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md
to:
by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md

*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Do not set this item to non-reconstructable or ignored. The page is source-route reconstructable; the formal code block is blank only because the source should be expressed through class declarations and consumer code, not a raw `.rdata` island declaration.

## Exact Support-Doc Incorporation Plan

Add this subsection to [UID:000259] after `## Evidence` or `## Reconstruction Notes`:

```text
## 2026-06-18 B005 Byte/Table Reanalysis

- The assigned half-open range `0x006196c0-0x00619d28` is `0x668` / 1640 bytes (Verified with `int_convert.py`). Every byte inside this current range is now accounted for as the `ExceptionHandler` vtable slot, crash diagnostics literals, exception-code wide-string literals, stack/logical-address format strings, ImageHlp module/API-name literals, or terminal alignment before the next object.
- The preceding four bytes `0x006196bc-0x006196c0` are dword `0x00647168`, the `ExceptionHandler` complete-object-locator pointer. Preferred structural repair is to trim [UID:000258] to `0x00619340-0x006196bc` and expand/rename this page to `0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md`; the repaired size is `0x66c` / 1644 bytes (Verified with `int_convert.py`).
- The first dword inside the current target is `0x006196c0 -> 0x004ac860`, the scalar deleting destructor slot for `ExceptionHandler`. Constructor/destructor/scalar stores at `0x004ab4a3/0x004ab4a5`, `0x004ab4f3/0x004ab4f5`, and `0x004ac869/0x004ac86b` revalidate the vtable owner.
- The successor boundary at `0x00619d28` is exact: dword `0x00647204` is the `ExchangeDialog` COL pointer, followed by the `ExchangeDialog` vtable at `0x00619d2c`.
- No standalone exception-code pointer table was found inside this `.rdata` target. The exception-code helper selects direct wide-string literal addresses from executable code/switch data, so first-draft C++ belongs on [UID:00014H] as a switch/helper, not as a raw static table on this page.
- `L"%s\\%s"`, `L"rt"`, and `L"wt"` are pooled generic literals also used by ScreenshotCapture and PhoneBookDialog paths. They should remain inline literals at each source use rather than ExceptionHandler-specific globals.
- Formal C++ on this read-only-data page remains intentionally blank. The vtable/COL are compiler-generated from [UID:00004P], and the source-authored strings belong in [UID:00014G], [UID:00014H], [UID:00014I], [UID:00014J], and raw helper bodies within [UID:0000J8] `platform/ExceptionHandler.cpp`.
```

Replace the final sentence of [UID:000259] `## Reconstruction Notes` with:

```text
Final C++ for this read-only-data page remains blank by policy: the vtable/COL/RTTI are compiler-generated from the `ExceptionHandler` class declaration, and the source-authored literals should be emitted through the crash-report writer, exception-code helper, stack/logical-address helpers, and ImageHlp resolver in `platform/ExceptionHandler.cpp`, not through an artificial raw `.rdata` blob.
```

Add this note to [UID:000258] if the range repair is accepted:

```text
2026-06-18 B005 boundary repair: the previous terminal dword at `0x006196bc` is `0x00647168`, the `ExceptionHandler` complete-object-locator pointer. It is not Error/Event data; this page should end at `0x006196bc`, and [UID:000259] should begin at `0x006196bc` so the ExceptionHandler COL pointer stays with its vtable.
```

Add this note to [UID:0000J8] and [UID:00004P] if a support-doc summary is desired:

```text
2026-06-18 B005 `.rdata` reanalysis confirms that the `ExceptionHandler` diagnostics read-only island is source-owned by `platform/ExceptionHandler.cpp`. The class declaration regenerates the vtable/COL, while crash-report, exception-code, stack/logical-address, and ImageHlp resolver literals should remain in the executable consumer helpers rather than a hand-authored data blob.
```

## Coverage Row Text

Placement context: replace the existing [UID:000259] row between [UID:000258] `ErrorEventReadOnlyData` and [UID:00025A] `ExchangeItemReadOnlyData`.

Fallback row if the current path is retained:

```text
    - [UID:000259][0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196c0-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) 0x006196c0-0x00619d28 | vtable/string-data | ExceptionHandlerDiagnosticsReadOnlyData : reconstructable : 86% : very-strong : B005 byte-level reanalysis accounts for the current `0x668` / 1640-byte half-open range (Verified with `int_convert.py`): `ExceptionHandler` scalar-deleting-destructor vtable slot, crash-report and OS-version literals, exception-code wide-string literals, stack/logical-address format strings, ImageHlp module/API-name literals, and exact successor boundary at `0x00619d28`; current range excludes the preceding `ExceptionHandler` COL pointer at `0x006196bc`, so formal C++ remains declaration-only through `platform/ExceptionHandler.cpp` consumers rather than a raw `.rdata` block.
```

Preferred row if the supervisor applies the range repair and renames the page:

```text
    - [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) 0x006196bc-0x00619d28 | vtable/string-data | ExceptionHandlerDiagnosticsReadOnlyData : reconstructable : 87% : very-strong : B005 byte-level reanalysis accounts for the repaired `0x66c` / 1644-byte half-open range (Verified with `int_convert.py`): `ExceptionHandler` COL pointer `0x006196bc -> 0x00647168`, scalar-deleting-destructor vtable slot `0x006196c0 -> 0x004ac860`, crash-report and OS-version literals, exception-code wide-string literals, stack/logical-address format strings, ImageHlp module/API-name literals, pooled generic path/mode literals, and exact successor boundary at `0x00619d28`; source emission belongs to `platform/ExceptionHandler.cpp` class/consumer declarations, not a raw `.rdata` formal block.
```

If the preferred range repair is accepted, [UID:000258] coverage should also be adjusted to end at `0x006196bc`; I did not draft a full replacement for [UID:000258] because it is outside this assignment and already has its own non-emitting split-index evidence, but the boundary sentence above is the required placement fact.

## Open Questions Closed Or Carried Forward

- Literal ordering: closed. The report lists the observed order from `0x006196c4` through `0x00619d18`.
- Non-string data: closed. Inside the current target, only `0x006196c0 -> 0x004ac860` is non-string pointer data; the preferred repaired range additionally includes `0x006196bc -> 0x00647168` COL pointer.
- Table shape: closed for this target. No exception-code pointer table or ImageHlp API table is required inside this `.rdata` span; source should use switch/helper and resolver literals.
- Owner/emitter: closed. [UID:0000J8] remains owner/emitter; [UID:00004P] owns class declarations.
- Boundary: partially open only as a supervisor action. Evidence supports the `0x006196bc` repair, but this report is not authorized to rename or edit by-* docs directly.
- Formal C++: closed. Leave [UID:000259] blank; declarations belong to [UID:00004P]/[UID:0000J8] and executable consumer pages.

## Validation Notes

- `int_convert.py` was used for `0x668 -> 1640`, `0x66c -> 1644`, and other byte-size checks cited above.
- Live IDA MCP was unavailable, so this pass did not perform live IDA re-labeling or py-eval validation.
- No by-memory docs, generated files, or coverage files were edited by this pass.

## Changed Files

- Added report: `tools/leaser/Agents/Agent-B005/research/000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"000259"} -->
<!-- {"agent":"B005","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"000259"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
