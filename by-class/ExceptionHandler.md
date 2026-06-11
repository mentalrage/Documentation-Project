*** UID:00004P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExceptionHandler

## Status

- Confidence: strong for class responsibility, callback/report behavior, live ranges, and crash-diagnostics ownership; medium for final source-facing helper names.
- Prior generated file: `class_ExceptionHandler.cpp`, treated only as non-authoritative context.
- Likely source module: [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- Current range: [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- Evidence basis: live IDA MCP checks on 2026-06-06 plus existing documentation.
- Final C++ is intentionally blank because exact field names, helper names, and source declarations remain below the 95/95 reconstruction-code threshold.

## Responsibility

`ExceptionHandler` is the process-level crash/exception filter object. It installs a top-level exception filter, owns the active crash target pointer, writes crash reports, and restores the previous filter on destruction.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004ab480` | `ExceptionHandler` | Sets `g_pCrashTarget`, installs vtable, calls `SetUnhandledExceptionFilter`, and clears crash state. |
| `0x004ab4f0-0x004ab50a` | raw ordinary destructor/reset body | Not modeled as an IDA function; restores the previous filter from `this+8`, writes the vtable, clears `g_pCrashTarget`, and returns. |
| `0x004ab510-0x004ab73b` | crash diagnostic report sender | IDA models `sub_4AB510`; reads `BCrash.nfo`, prefixes OS-version text, packetizes the contents, sends through the packet sender, closes/deletes the file, and has a single caller at `0x005101e8`. |
| [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) | diagnostic text sender candidate | Encodes and sends a diagnostic text packet; used by timer-skew detection. |
| `0x004ab810-0x004ab82b` | raw wide-string setter | Not modeled as an IDA function; copies a caller wide string into the object buffer at `this+0x28` with `_wcscpy_s`. |
| [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) | `TopLevelExceptionFilter` | Restores keyboard settings, reads [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), calls crash-report helper, and may chain to previous filter. |
| [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) | crash-report writer candidate | Writes `BCrash.nfo`, exception/register data, and call stack. |
| [UID:00014H][0x004abd10-0x004abe4a.ExceptionCodeStringHelper](by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md) | exception-code string helper | Converts exception codes to wide diagnostic strings. |
| `0x004abe4a-0x004abf9c` | exception-code switch data | Jump table and indirect table used by the exception-code string helper; followed by `0xcc` padding to `0x004abfa0`. |
| [UID:00014I][0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper](by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md) | address/module helper | Resolves logical address/module text for crash reports. |
| `0x004ac040-0x004ac0ed` | ImageHlp resolver helper | IDA models `sub_4AC040`; loads `IMAGEHLP.DLL`, resolves/stores ImageHlp function pointers at object offsets `+0x10..+0x24`, optionally calls `SymSetOptions(7)`, and initializes symbols. |
| `0x004ac0f0-0x004ac221` | raw stack/logical-address formatter | Not modeled as an IDA function; stack-cookie-protected helper in the crash-report stack formatting cluster. |
| [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) | symbol stack-walk helper | Uses IMAGEHLP symbol APIs when available. |
| `0x004ac4d0-0x004ac642` | raw frame-chain stack formatter | Not modeled as an IDA function; stack-cookie-protected helper that walks frame-chain/module data for report output. |
| `0x004ac650-0x004ac859` | raw symbol/detail stack formatter | Not modeled as an IDA function; stack-cookie-protected helper adjacent to the stack-walk output code. |
| `0x004ac860` | `ScalarDeletingDestructor` | Restores the previous exception filter, clears `g_pCrashTarget`, and optionally deletes. |

## 2026-06-06 Live IDA Recheck

- `lookup_funcs` maps the constructor to `sub_4AB480`, size `0x6d`, and the scalar deleting destructor to `sub_4AC860`, size `0x3a`; the next function after the aggregate is `sub_4AC8A0` at `0x004ac8a0`.
- `TopLevelExceptionFilter` is a real function at `0x004ab830`, size `0x3f`, with no ordinary code callers and a constructor data reference at `0x004ab49e`, matching `SetUnhandledExceptionFilter`.
- The report writer at `0x004ab870`, size `0x4a0`, is called only from the filter at `0x004ab858` and owns the `BCrash.nfo` version, exception, register, ImageHlp, and fallback frame-chain output.
- Raw body and data islands are now explicit: `0x004ab4f0-0x004ab50a`, `0x004ab510-0x004ab73b`, `0x004ab810-0x004ab82b`, exception-code switch data `0x004abe4a-0x004abf9c`, `0x004ac040-0x004ac0ed`, `0x004ac0f0-0x004ac221`, `0x004ac4d0-0x004ac642`, and `0x004ac650-0x004ac859`.
- Parentage remains [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md); the class is now above the 80/80 parent threshold, so memory children may safely attach to this class or the aggregate page.

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

## Changes

- 2026-06-06 A001 live IDA recheck:
  - Before: `COMPLETION:76`, `CONFIDENCE:80`, and only coarse constructor/filter/report helper coverage.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`; final C++ remains blank under the 95/95 gate.
  - Evidence: live IDA reconfirms constructor/destructor/filter/report bounds, callback pointer reference, report-writer caller/callee behavior, next-function boundary, and previously undocumented raw helper/data islands in the aggregate range.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/80`.
  - Summary/evidence: process exception-filter role, constructor, top-level filter, crash report/text/address/stack helpers, singleton/global ownership, and companion `Crasher` links are documented; remaining uncertainty is final folder placement and exact source-facing helper names.
