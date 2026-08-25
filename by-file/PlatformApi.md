*** UID:0000ML | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PlatformApi

## UID0000MS ProfileStorage Dependency Closure - 2026-08-25

[UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) now exposes nine consumer-required `PlatformApi.h` externs: the existing wide-open, wide-stat, CreateFileW, GetCurrentDirectoryW, and CharUpperBuffW pointers plus `g_pfnReadUtf16CodeUnitFromFile`, `g_pfnCreateDirectoryW`, `g_pfnDeleteFileW`, and `g_pfnSetFileAttributesW`. ProfileStorage consumes the latter four for legacy quoted-field reads and `.usr`/`.cfg` directory/file lifecycle.

Storage, initializer assignment, and CPP definitions remain with PlatformApi/WideApiDispatchTable, including the `0x0069becc` tail definition. The header declaration does not move that slot into UID0002AS's physical range or expose unrelated table entries. Older text below that says the guarded header exposes exactly five externs is retained as historical pre-ProfileStorage state and is superseded by this section.

## Proposed Original Placement

- Proposed source path: `platform/PlatformApi.cpp`
- Proposed header path: `platform/PlatformApi.h`
- Confidence: strong

## Current Wave3 Containers

- `class_UniAPIInit.cpp`
- `class_AutoInit.cpp`

These names are historical generated-container provenance only. Final source routing uses this PlatformApi file page and exact by-class/by-memory emitters; stale generated `~UniAPIInit` naming does not control source identity.

## Responsibilities

This module is a platform compatibility layer for late-1990s/early-2000s Windows support. `UniAPIInit` chooses ANSI fallback behavior on 9x or wide-character Win32 entry points on NT-family Windows. The current best source model is a file-local static initializer object, documented as `static UniAPIInit s_uniAPIInit`, plus PlatformApi file-scope dispatch function-pointer globals. The exact static variable prefix is inferred, but the static-object shape is now accepted; it is no longer an open source-placement blocker. `AutoInit` / [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) is a tiny COM/OLE lifetime helper that calls `OleInitialize(0)` during startup and `OleUninitialize` during static or virtual teardown.

The exact human source constructor is [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md); the exact empty out-of-line virtual destructor is [UID:0004N7][0x005997e0-0x005997e7.UniAPIInitDestructor](by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md). [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) is the sole live compiler startup wrapper and inlined constructor realization, not a handwritten source emitter. Together they initialize process-wide [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), including `_wfopen` at `0x0069be14`, `_wstat64i32` at `0x0069be18`, unconditional `ReadUtf16CodeUnitFromFile` at `0x0069be1c`, and `GlobalGetAtomNameW` at `0x0069be80`.

PlatformApi owns the `0x0069be14` and `0x0069be18` storage, declarations, and initialization policy as `FILE *(__cdecl *g_pfnWideOpenFile)(const wchar_t *, const wchar_t *)` and `int (__cdecl *g_pfnWideStat)(const wchar_t *, struct _stat64i32 *)`. It does not own the two canonical [UID:0000MI][PathUtil](by-file/PathUtil.md) bodies: [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) reads/calls `g_pfnWideOpenFile` at `0x004b81fe`, while [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) reads/calls `g_pfnWideStat` at `0x00582478`. [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) is another executable consumer of both slots.

`AutoInit` may ultimately belong in the browser/OLE module because the browser code uses COM heavily, but current evidence proves a process-wide startup initializer rather than browser-instance ownership. Keep it in a platform/OLE bucket unless historical source evidence proves browser placement.

## Likely File Contents

- `class UniAPIInit`, the file-local static `UniAPIInit` object, and the process-wide Win32 API dispatch table. The class page emits the declaration; PlatformApi owns the static object and the dispatch initialization policy.
- [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md), which preserves the exact `OSVERSIONINFOA` behavior, unconditional reader install, and complete NT-only 47-destination assignment sequence.
- [UID:0004N7][0x005997e0-0x005997e7.UniAPIInitDestructor](by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md), one empty out-of-line source definition. Compiler vptr reset, deleting wrapper, startup wrapper, and static cleanup remain non-emitting.
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), including `dword_69BE14` / `_wfopen`, `dword_69BE18` / `_wstat64i32`, `0x0069be34` / `g_pfnCreateFileW`, and the neighboring Win32 `*W` dispatch pointers.
- [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) provides the formal grouped `g_pfn*` definitions for the main 44-slot body and the guarded consumer-driven `PlatformApi.h`. That header exposes exactly five currently required externs: `g_pfnWideOpenFile`, `g_pfnWideStat`, `g_pfnCreateFileW`, `g_pfnGetCurrentDirectoryW`, and `g_pfnCharUpperBuffW`; unrelated slots remain provider-internal.
- ANSI/wide string conversion helpers and the UTF-16 file-code-unit reader documented at [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md): `AllocAnsiFromWideDefaultCodepage`, `FreeAllocatedAnsiString`, retained no-direct-edge inverse helpers `AllocWideFromAnsiDefaultCodepage` and `FreeAllocatedWideString`, and dispatch-table reader `ReadUtf16CodeUnitFromFile`.
- [UID:00022V][0x004f5b20-0x004f5c73.MapiSendMailHelper](by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md), a retained no-direct-static-caller Simple MAPI helper that dynamically loads `MAPI32.DLL`, resolves `MAPISendMail`, converts wide input strings through the PlatformApi default-codepage helpers, builds SDK `MapiMessage`/`MapiRecipDesc`/optional `MapiFileDesc` records, and emits the MAPI lookup literals inline rather than as standalone globals.
- `class AutoInit` or a smaller `OleAutoInit` helper.
- `InitializeOleSupport` startup initializer, `AutoInit` destructor body, and the `0x0060c0f0` `atexit` shutdown thunk.
- grouped file-scope function pointers such as `g_pfnCreateWindowEx`, `g_pfnDispatchMessage`, `g_pfnPeekMessage`, `g_pfnRegQueryValueEx`, `g_pfnGlobalGetAtomNameW`, `g_pfnImmGetCompositionString`, and related `g_pfn*` entries. These should be treated as PlatformApi-owned dispatch globals documented by [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), not as raw `dword_69BE*` storage or consumer-local globals.

## Evidence

- Generated `UniAPIInit` source calls `GetVersionExA`, sets ANSI conversion by default, and installs many `*W` Win32 APIs when `dwPlatformId == VER_PLATFORM_WIN32_NT`.
- IDA MCP confirms a real initializer at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md): it calls `GetVersionExA`, installs the `0x0069be14-0x0069bed0` dispatch-pointer table on NT-family Windows, writes `_wfopen` to `dword_69BE14`, writes `_wstat64i32` to `dword_69BE18`, writes `SendMessageW` to [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md), and registers [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) through `atexit`.
- 2026-07-04 B001 current MCP session `ba171fe4` reconfirms the PlatformApi dispatch declaration route for UID0002AS: `sub_41A280` is the real initializer at `0x0041a280`, size `0x228`; the main table body is `0x0069be14-0x0069bec4`, 176 bytes / 44 dwords, zero-initialized; the adjacent `0x0069bec4-0x0069bed0` sibling/tail bytes are also zero-initialized; wrapper/thunk addresses resolve for `_wfopen`, `_wstat64i32`, version, and IME slots; and no IDA source globals/names/types exist for original `g_pfn*` typedef spellings.
- UID0001IZ support verification records all five exact `0x0069be18` xrefs: live initializer store `0x0041a438`, StdioFile read `0x00582104`, PathExistsViaStat read `0x00582478`, retained constructor store `0x0059976d`, and retained raw projection store `0x005999a8`. These prove one PlatformApi-owned dispatch slot with two executable consumers, not consumer-local storage.
- UID0000MI whole-file verification records [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) as the exact `0x0069be14` consumer at `0x004b81fe`. Its 46-byte `L"rb"`/null/close/boolean body remains PathUtil-owned; the slot retains 41 total refs and PlatformApi storage/initializer ownership.
- IDA MCP confirms scalar deleting destructor UID0004N9 at `0x00599a10-0x00599a34`; it is compiler ABI support, not human source.
- IDA does not model the retained constructor start `0x005995b0`, but exact bytes show `this`, vptr setup, return-this shape, and the full source behavior, independently corroborated by the live inlined startup copy. The stale Wave3 `UniAPIInit::~UniAPIInit` identity is superseded; exact ordinary destructor source is UID0004N7.
- 2026-05-28 IDA MCP confirms `0x00599440`/`0x005994b0` convert/free MAPI strings, `0x005994d0`/`0x00599550` are the inverse wide-string helper pair, and `0x00599570` is stored into `dword_69BE1C` by `WideApiDispatchInit`.
- 2026-06-17 B002 source-quality reanalysis names the helper island as PlatformApi-owned default-codepage/UTF-16 support: `AllocAnsiFromWideDefaultCodepage` and `FreeAllocatedAnsiString` are live MAPI dependencies, `AllocWideFromAnsiDefaultCodepage` and `FreeAllocatedWideString` are retained source-shaped inverse helpers with no hidden PE rel32/VA refs, and `ReadUtf16CodeUnitFromFile` is the `0x0069be1c` dispatch-table reader.
- 2026-06-20 B003 MAPI helper source-quality incorporation keeps [UID:00022V][0x004f5b20-0x004f5c73.MapiSendMailHelper](by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md) in this module. The helper is Win32 platform integration code, not NexusTK in-game mail packet handling: it uses `LoadLibraryA("MAPI32.DLL")`, `GetProcAddress(..., "MAPISendMail")`, SDK Simple MAPI structures, `MAPI_RECEIPT_REQUESTED`, and the default-codepage conversion/free helpers. No feature caller is currently proven, but no stronger owner than PlatformApi is supported.
- 2026-05-26 IDA MCP recheck reconfirmed `0x0041a280` size `0x228`, no modeled callers but a startup-table data xref at `0x0060d71c`, no callers/xrefs for `0x005995b0`, and the `0x00599a10` scalar deleting destructor vtable data ref at `0x0062e57c`.
- 2026-05-26 IDA MCP confirms `0x0060c440-0x0060c44b` as the `UniAPIInit` static cleanup wrapper that writes the vtable pointer at `0x006702c4`. Keep it with platform static lifetime documentation and ignore it as a standalone source function.
- 2026-05-26 `simroot_v2/class_UniAPIInit.cpp` emitted the dispatch initializer as `~UniAPIInit` at `0x005995b0`; this remains historical provenance only and is superseded by the exact constructor/destructor split.
- 2026-06-21 B007 source-shape reanalysis resolves the stale caveat direction: `0x0041a280` remains the real startup dynamic initializer/inlined `UniAPIInit` constructor logic, `0x005995b0` is constructor-shaped raw/generated duplicate code with no current rel32 call/jump or absolute pointer route, `0x005997e0` is only a vptr reset helper, `0x00599a10-0x00599a34` is scalar deleting destructor glue, `0x0060c440-0x0060c44b` is compiler/static-lifetime cleanup, and `0x006702c4` should be represented as storage for a file-local static `UniAPIInit` object rather than a handwritten vptr global.
- B014's exact split evidence remains valid, but the prior defer is closed: constructor UID0004N6 and ordinary destructor UID0004N7 emit source; duplicate UID0004N8, scalar UID0004N9, live wrapper UID0000WD, cleanup UID0001O9, target UID0003E5, and mixed parent UID0001KE remain compiler/non-emitting.
- Full RTTI reanalysis proves `UniAPIInit` is a four-byte vptr-only class with one self base, no inheritance, and one virtual destructor slot. The file-local object at `0x006702c4` is source-declared as `static UniAPIInit s_uniAPIInit;`; exact `s_` spelling and public access remain explicit high-probability inference.
- Read-only `third_party_embeds` inspection found only unrelated jsoncpp, libjpeg, lodepng, and zlib families. No UniAPI/PlatformApi import route applies; this is project-owned source.
- 2026-06-21 B008 source-quality incorporation for [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md) resolves `dword_69BE80` as the PlatformApi `g_pfnGlobalGetAtomNameW` slot. Local PE/import evidence maps IAT cell `0x0060d260` to `KERNEL32.dll!GlobalGetAtomNameW`, [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) installs it at `0x0041a3b1-0x0041a3b6`, and the RegistryConfig Netsgo parser consumes it at `0x0048f9f8` for global-atom-name validation.
- 2026-06-07 A010 Batch057 parent-gate review: the platform ownership evidence is now consistent across the exact initializer [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), global table [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), split table-body docs [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md), [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md), and [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md). Remaining uncertainty is final source declaration style and generated `UniAPIInit` boundary naming, not the direct source-file owner.
- `AutoInit::ScalarDeletingDestructor` is confirmed by IDA MCP at `0x00470300-0x0047032a` and calls the OLE teardown path.
- IDA MCP confirms `InitializeOleSupport` at `0x00419ee0-0x00419ef4`: it calls `OleInitialize(0)`, registers `0x0060c0f0` through `_atexit`, and is referenced by startup initializer table entry `0x0060d6a4`.
- IDA MCP confirms `0x0060c0f0` writes the anonymous `AutoInit` vtable slot and tail-jumps to `OleUninitialize`.
- IDA MCP confirms the ordinary `AutoInit` destructor at `0x0046efe0-0x0046efeb` and the scalar deleting destructor at `0x00470300-0x00470329`; local IDA data inspection confirms the one-slot `AutoInit` vtable at `0x0061373c`.

## 2026-08-18 B007 FieldMapPane Consumer And Header Route

- [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md) consumes the wide dispatch slot at `0x0069be58` from constructor call site `0x004b0c41`. The constructor first builds the path stem, appends pooled `L".EPF"`, computes the completed string length, and invokes the dispatch in place.
- Import/initializer evidence resolves the slot as `USER32.dll!CharUpperBuffW`. Source-facing provider name and type are `DWORD (WINAPI *g_pfnCharUpperBuffW)(LPWSTR text, DWORD length)`.
- Storage and the single CPP definition remain on [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) through PlatformApi owner UID `0000TQ`. FieldMapPane is a consumer and must not define or locally own the global.
- The intentionally narrow generated `NexusTK/platform/PlatformApi.h` exposes five consumer-required declarations: wide open, wide stat, `g_pfnCreateFileW`, current directory, and `g_pfnCharUpperBuffW`. This is a consumer-driven public surface, not a requirement to expose all 44 dispatch slots.
- `BuildFieldMapPath` does not consume the slot. Uppercasing is constructor behavior after suffix append, preserving the exact source and call order.

## Migration Notes

- Add a `platform/` folder to the proposed tree if more Win32 compatibility wrappers are confirmed.
- Keep the stale Wave3 `~UniAPIInit` label only as historical generated provenance. Final source declares `class UniAPIInit`, emits exact UID0004N6 constructor and UID0004N7 empty destructor, declares `static UniAPIInit s_uniAPIInit`, and uses grouped file-scope dispatch globals.
- Do not emit mixed UID0001KE, startup wrapper UID0000WD, duplicate projection UID0004N8, scalar UID0004N9, cleanup UID0001O9, or vtable UID0003E5. Their exact behavior remains documentation evidence while compiler lowering regenerates their binary roles.
- Keep `dword_69BE14`, `dword_69BE18`, and `dword_69BE1C` with this module's dispatch table. Consumer docs should reference them as platform API entries instead of declaring them as local globals.
- Keep `dword_69BE80` with this module's dispatch table as `g_pfnGlobalGetAtomNameW`. [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md) is a concrete consumer, but the parser remains RegistryConfig-owned source logic; only the Win32 dispatch slot belongs here.
- Keep the inverse ANSI-to-wide conversion pair with the PlatformApi helper island even though no current direct edge reaches it. Current B002 evidence treats it as retained source-shaped platform helper code rather than padding, MAPI-local code, dispatch-table storage, or compiler-generated CRT glue.
- Keep [UID:00022V][0x004f5b20-0x004f5c73.MapiSendMailHelper](by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md) with this module unless future caller evidence proves a feature-specific source file. Current no-direct-caller status is a reachability caveat, not a no-code/no-owner proof. The `MAPI32.DLL` and `MAPISendMail` literals from [UID:0003OT][0x0061d0f0-0x0061d118.MapiLookupStrings](by-memory/0x0061d0f0-0x0061d118.MapiLookupStrings.md) should be represented inline by the helper C++.
- [UID:0000OQ][TextPad](by-file/TextPad.md) file helpers consume `g_pfnCreateFileW` at `0x0069be34` for local `Open`/`Save` commands. This is provider-only evidence for PlatformApi; TextPad still owns the UI command routing, file format, and helper bodies.
- TextPad's exact consumer contract is `HANDLE (WINAPI *)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE)`. `Open` passes `GENERIC_READ`, no sharing/security, `OPEN_EXISTING`, and `FILE_FLAG_SEQUENTIAL_SCAN`; `Save` passes `GENERIC_WRITE`, no sharing/security, `CREATE_ALWAYS`, and `FILE_FLAG_SEQUENTIAL_SCAN`. The declaration is emitted once by UID0002AS, while TextPad includes `../../platform/PlatformApi.h`.
- `AutoInit` no longer needs a heap-allocation search before source placement; the confirmed lifetime path is a static initializer plus `atexit` shutdown thunk, with an ordinary destructor and scalar deleting destructor as ABI-side teardown evidence.
- Browser COM ownership remains plausible only as a source-file grouping choice, not as a runtime lifetime fact. The wide API dispatch table itself should stay with this platform module; browser, socket, file, IME, and user-interface code are consumers.

## Cross-References

- Classes: [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md), [UID:00000Q][AutoInit](by-class/AutoInit.md)
- Globals: [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- Neighboring files: [UID:0000HG][Application](by-file/Application.md), [UID:0000HV][Browser](by-file/Browser.md), [UID:0000K6][InputMan](by-file/InputMan.md)
- Memory: [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md), [UID:0004N7][0x005997e0-0x005997e7.UniAPIInitDestructor](by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md), [UID:0004N8][0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection](by-memory/0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection.md), [UID:0004N9][0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor](by-memory/0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor.md), [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:00022V][0x004f5b20-0x004f5c73.MapiSendMailHelper](by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md), [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), [UID:0003OT][0x0061d0f0-0x0061d118.MapiLookupStrings](by-memory/0x0061d0f0-0x0061d118.MapiLookupStrings.md), [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md), [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
- Vtables: [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md)
- Field-map consumer: [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md), [UID:00004U][FieldMapPane](by-class/FieldMapPane.md), and [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)

## Changes

- 2026-08-18 B007 UID0000JA support synchronization:
  - Added FieldMapPane constructor call `0x004b0c41` as the exact `g_pfnCharUpperBuffW` consumer and documented the provider-owned `PlatformApi.h` extern route.
  - Preserved PlatformApi storage/initializer ownership, the existing 44 CPP definitions, the three pre-existing H declarations, and current `90/88` score; no duplicate FieldMap definition was introduced.

- 2026-08-22 B003 UID0000OQ support synchronization:
  - Raised confidence from `88` to `90` after closing the exact `g_pfnCreateFileW` consumer declaration and argument contract; completion remains `90`.
  - Added TextPad `Open`/`Save` as provider-only consumers and updated the narrow generated-header inventory from four to five declarations. All 44 CPP definitions, storage/initializer ownership, unrelated consumers, and file-helper ownership remain unchanged.

- 2026-08-17 B007 UID0000PA generated-header consumer closure:
  - Preserved PlatformApi as the single source owner for the 44 initialized function-pointer definitions and initialization behavior.
  - Its intentionally narrow public header now includes exactly three declarations required by current consumers: `g_pfnWideOpenFile`, `g_pfnWideStat`, and `g_pfnGetCurrentDirectoryW`, with stdio/stat/Windows dependencies.
  - [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) includes this header and consumes the current-directory dispatch. The observed wide-directory/ANSI-shell-execute mismatch is preserved exactly rather than silently converted to a different API family.

- 2026-08-16 B006 UID0000MI support synchronization:
  - Added FileExists as the exact `g_pfnWideOpenFile` consumer at `0x004b81fe` and retained PathExistsViaStat as the exact `g_pfnWideStat` consumer at `0x00582478`.
  - Recorded UID0002AS's narrow guarded `PlatformApi.h` route for the two typed PathUtil dependencies while preserving all 44 CPP definitions, process-wide storage/initializer ownership, unrelated APIs, and the existing score.
  - Kept both helper bodies with PathUtil; PlatformApi remains provider/storage owner rather than consumer-body owner.

- 2026-07-24 B001 UID0001IZ support verification: added canonical PathUtil-owned PathExistsViaStat as the exact `g_pfnWideStat` consumer at `0x00582478`, retained StdioFile as the other executable consumer, and recorded all five slot xrefs while preserving PlatformApi declaration/initializer ownership and current score.

- 2026-07-14 B004 UID0003E5 callback: raised `88/85` to `90/88`; preserved reconstruction path, FILE ownership, and all AutoInit/MAPI/helper/consumer content; replaced deferred UniAPIInit wording with exact constructor UID0004N6, destructor UID0004N7, class/static/global source model, compiler-only UID0004N8/UID0004N9/UID0000WD/UID0001O9/UID0003E5 dispositions, no-third-party result, and historicalized stale Wave destructor naming.

- 2026-07-04 B001 UID0002AS implementation callback:
  - Score unchanged at `88/85`.
  - Recorded that UID0002AS now emits formal grouped PlatformApi `g_pfn*` declarations into `NexusTK/platform/PlatformApi.cpp` after validator refresh. Current MCP session `ba171fe4` supports the same source route with zero-initialized storage, exact `sub_41A280` initializer evidence, wrapper/thunk facts, negative original-name/type evidence, and raw `0x005995b0` projection rejection.
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
- 2026-06-07 A010 Batch057 parent-gate review:
  - What existed before: `CONFIDENCE:80`, which blocked corrected 85/85 routing through this file.
  - Changed to: `CONFIDENCE:85`; completion remains `88`.
  - Summary/evidence: existing UID-backed IDA evidence now agrees that [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) owns the wide dispatch initialization, [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) is the process-wide table, and the split memory pages cover the exact `0x0069be14-0x0069bed0` storage. Generated `UniAPIInit` naming remains a caveat, but it no longer undermines the direct PlatformApi source-file owner.
- 2026-06-17 B002 PlatformStringConversionHelpers source-quality sync:
  - What changed: recorded source-facing helper names and retained inverse-helper liveness for [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), including the `ReadUtf16CodeUnitFromFile` slot at `0x0069be1c`.
  - Summary/evidence: B002 rechecked current IDA and PE-aware call/pointer evidence, confirmed MAPI consumes only the ANSI conversion/free pair, rejected MAPI/UniAPIInit/FileIO/StringUtil ownership alternatives, and kept the full helper island in `platform/PlatformApi.cpp`.
- 2026-06-20 B003 MapiSendMailHelper source-quality sync:
  - What changed: added [UID:00022V][0x004f5b20-0x004f5c73.MapiSendMailHelper](by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md) to likely file contents and PlatformApi evidence, with [UID:0003OT][0x0061d0f0-0x0061d118.MapiLookupStrings](by-memory/0x0061d0f0-0x0061d118.MapiLookupStrings.md) handled as inline literals.
  - Summary/evidence: B003's Rule 26 report reclassified the helper's remaining unknowns as source-quality caveats rather than owner/code blockers: no direct feature caller is proven, but SDK Simple MAPI behavior, dynamic Win32 loading, PlatformApi conversion-helper use, and rejected startup-logo/WinMain/in-game-mail alternatives make PlatformApi the best current owner.
- 2026-06-21 B007 UniAPIInit source-shape sync:
  - What changed: accepted the file-local static `UniAPIInit` object source model and grouped file-scope dispatch-global declaration style for PlatformApi.
  - Summary/evidence: B007 raw PE/current-doc reanalysis preserves the startup-table xref `0x0060d71c` for [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), no-route proof for raw/generated `0x005995b0`, exact vptr-reset/scalar-deleting/static-cleanup bodies, vtable/static-slot relation, WideApiDispatchTable ownership, and rejected consumer-owner/raw-vptr/forced-struct-table alternatives.
- 2026-06-21 B008 Netsgo parser support sync:
  - What changed: added `g_pfnGlobalGetAtomNameW` / `dword_69BE80` to the PlatformApi dispatch globals and recorded [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md) as a consumer.
  - Summary/evidence: B008 resolves the slot through `KERNEL32.dll!GlobalGetAtomNameW` IAT cell `0x0060d260`, initializer write `0x0041a3b1-0x0041a3b6`, and Netsgo parser call `0x0048f9f8`. This is a dispatch dependency, not a source-placement reason to move parser logic out of RegistryConfig.
- 2026-06-21 B008 TextPad source-quality sync:
  - Score unchanged at `88/85`.
  - Recorded TextPad as a `g_pfnCreateFileW` dispatch consumer while preserving provider-only PlatformApi ownership and rejecting PlatformApi/FileIO ownership of TextPad's file command helpers.
- 2026-06-19 B014 UniAPIInit support sync:
  - Score unchanged at `88/85`; the pass resolves a child caveat rather than changing the source-file owner.
  - Summary/evidence: B014 confirms the file-scope static `UniAPIInit` object/source route, the real startup initializer at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), the retained raw projection/no-route status of [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), and the compiler-generated disposition for vtable reset, static cleanup wrapper, vtable dword, static object slot, and scalar deleting destructor support.
