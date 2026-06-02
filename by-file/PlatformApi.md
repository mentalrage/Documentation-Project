*** UID:0000ML | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PlatformApi

## Proposed Original Placement

- Proposed source path: `platform/PlatformApi.cpp`
- Proposed header path: `platform/PlatformApi.h`
- Confidence: medium

## Current Wave3 Containers

- `class_UniAPIInit.cpp`
- `class_AutoInit.cpp`

## Responsibilities

This module is a platform compatibility layer for late-1990s/early-2000s Windows support. `UniAPIInit` chooses ANSI fallback behavior on 9x or wide-character Win32 entry points on NT-family Windows. `AutoInit` / [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) is a tiny COM/OLE lifetime helper that calls `OleInitialize(0)` during startup and `OleUninitialize` during static or virtual teardown.

The exact IDA-backed initializer for the wide API dispatch table is [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md). It owns the process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), including the `_wfopen` pointer at `0x0069be14` and `_wstat64i32` pointer at `0x0069be18` consumed by [UID:0000O9][StdioFile](by-file/StdioFile.md) and [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md).

`AutoInit` may ultimately belong in the browser/OLE module because the browser code uses COM heavily, but current evidence proves a process-wide startup initializer rather than browser-instance ownership. Keep it in a platform/OLE bucket unless historical source evidence proves browser placement.

## Likely File Contents

- `class UniAPIInit` and the process-wide Win32 API dispatch table.
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), including `dword_69BE14` / `_wfopen`, `dword_69BE18` / `_wstat64i32`, and the neighboring Win32 `*W` dispatch pointers.
- ANSI/wide string conversion helpers used by the dispatch table and by the MAPI helper, documented at [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md).
- `class AutoInit` or a smaller `OleAutoInit` helper.
- `InitializeOleSupport` startup initializer, `AutoInit` destructor body, and the `0x0060c0f0` `atexit` shutdown thunk.
- global function pointers such as `g_pfnCreateWindowEx`, `g_pfnDispatchMessage`, `g_pfnPeekMessage`, `g_pfnRegQueryValueEx`, `g_pfnImmGetCompositionString`, and related `g_pfn*` entries.

## Evidence

- Generated `UniAPIInit` source calls `GetVersionExA`, sets ANSI conversion by default, and installs many `*W` Win32 APIs when `dwPlatformId == VER_PLATFORM_WIN32_NT`.
- IDA MCP confirms a real initializer at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md): it calls `GetVersionExA`, installs the `0x0069be14-0x0069bed0` dispatch-pointer table on NT-family Windows, writes `_wfopen` to `dword_69BE14`, writes `_wstat64i32` to `dword_69BE18`, writes `SendMessageW` to [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md), and registers [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) through `atexit`.
- IDA MCP confirms `UniAPIInit::ScalarDeletingDestructor` at `0x00599a10-0x00599a34`.
- IDA MCP does not define a function at Wave3's `UniAPIInit::~UniAPIInit` start `0x005995b0`; the previous helper island is [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), and the next function is `0x005997e0-0x005997e7`. Treat the generated `0x005995b0` initializer body as a boundary/provenance issue until Wave3 data is refreshed.
- 2026-05-28 IDA MCP confirms `0x00599440`/`0x005994b0` convert/free MAPI strings, `0x005994d0`/`0x00599550` are the inverse wide-string helper pair, and `0x00599570` is stored into `dword_69BE1C` by `WideApiDispatchInit`.
- 2026-05-26 IDA MCP recheck reconfirmed `0x0041a280` size `0x228`, no modeled callers but a startup-table data xref at `0x0060d71c`, no callers/xrefs for `0x005995b0`, and the `0x00599a10` scalar deleting destructor vtable data ref at `0x0062e57c`.
- 2026-05-26 IDA MCP confirms `0x0060c440-0x0060c44b` as the `UniAPIInit` static cleanup wrapper that writes the vtable pointer at `0x006702c4`. Keep it with platform static lifetime documentation and ignore it as a standalone source function.
- 2026-05-26 current `simroot_v2/class_UniAPIInit.cpp` still emits the dispatch initializer as `~UniAPIInit` at `0x005995b0`, so the generated boundary/name caveat remains active.
- `AutoInit::ScalarDeletingDestructor` is confirmed by IDA MCP at `0x00470300-0x0047032a` and calls the OLE teardown path.
- IDA MCP confirms `InitializeOleSupport` at `0x00419ee0-0x00419ef4`: it calls `OleInitialize(0)`, registers `0x0060c0f0` through `_atexit`, and is referenced by startup initializer table entry `0x0060d6a4`.
- IDA MCP confirms `0x0060c0f0` writes the anonymous `AutoInit` vtable slot and tail-jumps to `OleUninitialize`.
- IDA MCP confirms the ordinary `AutoInit` destructor at `0x0046efe0-0x0046efeb` and the scalar deleting destructor at `0x00470300-0x00470329`; local IDA data inspection confirms the one-slot `AutoInit` vtable at `0x0061373c`.

## Migration Notes

- Add a `platform/` folder to the proposed tree if more Win32 compatibility wrappers are confirmed.
- Keep the `UniAPIInit` constructor/destructor naming provisional; Wave3 currently labels the initializer body as `~UniAPIInit` at non-function `0x005995b0`, while IDA anchors the matching dispatch setup at `0x0041a280`.
- Keep `dword_69BE14` and `dword_69BE18` with this module's dispatch table. Consumer docs should reference them as platform API entries instead of declaring them as local globals.
- `AutoInit` no longer needs a heap-allocation search before source placement; the confirmed lifetime path is a static initializer plus `atexit` shutdown thunk, with an ordinary destructor and scalar deleting destructor as ABI-side teardown evidence.
- Browser COM ownership remains plausible only as a source-file grouping choice, not as a runtime lifetime fact.

## Cross-References

- Classes: [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md), [UID:00000Q][AutoInit](by-class/AutoInit.md)
- Globals: [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- Neighboring files: [UID:0000HG][Application](by-file/Application.md), [UID:0000HV][Browser](by-file/Browser.md), [UID:0000K6][InputMan](by-file/InputMan.md)
- Memory: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md), [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
- Vtables: [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md)

## Changes

- 2026-05-28 helper-island split:
  - What existed before: the previous `0x00599570-0x005995a7` boundary was mentioned only as an unnamed previous function before the generated `UniAPIInit` body.
  - Changed to: `0x00599440-0x005995a7` is documented as `PlatformStringConversionHelpers` and linked as part of this platform/string compatibility module.
  - Summary/evidence: IDA MCP shows the helper island contains ANSI/wide allocation/free helpers plus the `dword_69BE1C` UTF-16 stream-reader target; xrefs connect it to both `MapiSendMailHelper` and `WideApiDispatchInit`.

- 2026-05-28 dispatch table range split:
  - What existed before: the evidence section described `0x0069be14-0x0069bed0` as one continuous dispatch-pointer cluster.
  - Changed to: the documented dispatch storage is `0x0069be14-0x0069bec4` plus `0x0069bec8-0x0069bed0`, with [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) identified as the intervening non-dispatch callback slot.
  - Summary/evidence: [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) and [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) now cover the exact dispatch ranges, while the existing callback page covers `0x0069bec4-0x0069bec8`.
- 2026-06-02 SendMessageW slot correction:
  - What existed before: the page described [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) as an intervening non-dispatch callback slot.
  - Changed to: the page now treats it as the `SendMessageW` wide API dispatch slot.
  - Summary/evidence: IDA MCP decompilation of [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) writes `SendMessageW` to `dword_69BEC4` at `0x0041a474`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `80`.
- Summary/evidence: the page documents platform/OLE responsibilities, wide API dispatch ownership, likely contents, IDA evidence, migration notes, range splits, and cross-references; confidence remains capped by generated `UniAPIInit` boundary/name issues and possible browser/OLE source grouping.

- 2026-06-02 reconstruction path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the proposed tree already placed `PlatformApi.cpp` under `platform/`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/"`.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already includes `platform/PlatformApi.cpp`, and this page's evidence anchors the module as platform/OLE compatibility code rather than an app/UI source file.
