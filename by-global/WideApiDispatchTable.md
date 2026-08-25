*** UID:0000TQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ML | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ML | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WideApiDispatchTable

## Status

- Confidence: very strong for concrete storage, all 47 initializer destinations, NT-wide assignment behavior, PlatformApi ownership, and complete declaration-page coverage; strong for reconstructed `g_pfn*` spelling/typedef forms, which are not PDB-proven.
- Address ranges: `0x0069be14-0x0069bed0` for currently confirmed dispatch-pointer storage, with [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) documenting the `SendMessageW` slot that older aliases mislabeled as a browser/transport callback.
- Source initializer: [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md). Live compiler startup realization: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md).
- Likely owner file: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Current IDA synchronization: catalog0376 applies exact source-facing names/types to first slots `g_pfnWideOpenFile` and `g_pfnWideStat`; other entries may still appear as local-looking `dword_69BE*` globals inside consumer files, but the table is process-wide platform support.

## Role

This is the client-wide Windows API dispatch table. At startup, the initializer calls `GetVersionExA`, keeps an ANSI/string-conversion fallback path, and on NT-family Windows installs wide-character Win32 and CRT entry points into the `0x0069be14+` pointer cluster. Current IDA evidence shows [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) is the `SendMessageW` dispatch slot; the generated browser/transport names are consumer-biased aliases.

The file I/O layer consumes two entries:

| Address | Provisional name | Installed target | Known consumers |
| --- | --- | --- | --- |
| `0x0069be14` | current IDA `g_pfnWideOpenFile`; historical `dword_69BE14` | `_wfopen` | [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) reads/calls the slot at exact `0x004b81fe` with `L"rb"`, then closes a non-null stream and returns an existence boolean; [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md), [UID:0002BJ][0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser](by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md) opening the Thrunet auth file with mode `"ro"`, [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) calling the slot at `0x004ab8d7` with mode `L"wt"` to create `<Windows directory>\BCrash.nfo`, and many direct file-open helpers |
| `0x0069be18` | current IDA `g_pfnWideStat`; historical `dword_69BE18` | `_wstat64i32` | [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) and canonical source-bearing [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md); [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) is the non-emitting mirror |
| `0x0069be1c` | `g_pfnReadUtf16CodeUnitFromFile` / `dword_69BE1C` | `ReadUtf16CodeUnitFromFile` | [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), and raw/generated [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) projection refs |
| `0x0069be30` | `g_pfnLoadLibraryW` / `dword_69BE30` | `LoadLibraryW` | [UID:0002BK][0x00490200-0x0049050a.LgInternetSessionLauncherParser](by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md) calls the slot at `0x004902b5` to load `chigamec.dll` before resolving `WaitForSessionParameter` through `GetProcAddress`; [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) calls it at `0x004abaf8` with `L"IMAGEHLP.DLL"` before resolving the stack-walk exports. Both are PlatformApi dispatch consumers, not storage owners. |
| `0x0069be34` | `g_pfnCreateFileW` / `dword_69BE34` | `CreateFileW` | MiniMap/download helpers, screenshot/file writers, [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md), [UID:0002BZ][0x00526f10-0x00526f57.MidiSourceOpenHelper](by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md), [UID:0002C7][0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper](by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md), socket serial transport, and [UID:0000OQ][TextPad](by-file/TextPad.md) `Open`/`Save` file helpers |
| `0x0069be5c` | `g_pfnCreateDirectoryW` / `dword_69BE5C` | `CreateDirectoryW` | ProfileStorage loader/writer path setup, screenshot capture setup, and other wide directory helpers. |
| `0x0069be60` | `g_pfnDeleteFileW` / `dword_69BE60` | `DeleteFileW` | Legacy profile `.cfg` deletion, stale profile writer cleanup, minimap/download partial-file cleanup. |
| `0x0069be70` | `g_pfnGetCurrentDirectoryW` / `dword_69BE70` | `GetCurrentDirectoryW` | Legacy profile import, current-directory `.usr` fallback, registry location persistence, and [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) updater-launch directory setup. |
| `0x0069be7c` | `g_pfnGetWindowsDirectoryW` / `dword_69BE7C` | `GetWindowsDirectoryW` | [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) calls the slot at `0x004ab89d` to obtain the directory used to format `<Windows directory>\BCrash.nfo`. |

Other confirmed entries include wide `FindWindow`, `CreateFile`, `CreateWindowEx`, `DispatchMessage`, registry APIs, `SetCurrentDirectory`, version APIs, IME APIs, `SendMessageW`, `GetLocaleInfo`, and `SetFileAttributes` pointers.

The current exact memory split is:

| Range | Memory page | Role |
| --- | --- | --- |
| `0x0069be14-0x0069bec4` | [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) | Main dispatch pointer body up to the `SendMessageW` slot. |
| `0x0069bec4-0x0069bec8` | [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) | Separately retained `SendMessageW` slot because stale generated aliases made it a high-risk reference target. |
| `0x0069bec8-0x0069bed0` | [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) | Tail dispatch entries for `GetLocaleInfoW` and `SetFileAttributesW`. |

## Source Declaration Style

The current best C++ direction is a group of PlatformApi file-scope function-pointer globals, with typedefs or Windows SDK pointer types, documented here as one dispatch table because the binary storage is contiguous. Do not force this into a runtime `struct WideApiDispatchTable g_table` unless later evidence finds base-pointer indexing, a table pointer, or source declarations that require it. Current code uses direct absolute slot references, and a declaration/link-order cluster explains the contiguous storage.

2026-07-04 B001 UID0002AS implementation callback populated formal grouped PlatformApi function-pointer declarations on the main-body child [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md). Historical MCP session `ba171fe4` confirmed that child range is `0x0069be14-0x0069bec4`, 176 bytes / 44 dwords, zero-initialized before runtime assignment, and initialized by `sub_41A280` at `0x0041a280`; its then-valid absence of IDA names is superseded only for the first two slots by catalog0376 and remains useful negative original-typedef evidence.

Rejected declaration/ownership alternatives:

- Raw `dword_69BE*` variables are not source-quality now that slot targets and roles are known.
- Consumer-local declarations in file I/O, browser/socket, input, thread/event, or UI modules are rejected because those modules read or call individual entries; they do not own initialization or storage.
- A forced struct/table object is acceptable only as a documentation abstraction. It is weaker as final C++ than grouped named globals because no observed code computes `base + index * 4`.

The source initializer that installs these entries is exact constructor UID0004N6, modeled through [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md). UID0000WD is the non-emitting live startup-table wrapper/inlined realization and registers compiler cleanup; it is not a second source body. The file-local object is `static UniAPIInit s_uniAPIInit`; its exact prefix remains inferred.

B014's 2026-06-19 UniAPIInit reanalysis keeps the same declaration style and clarifies projection writes: the live `ReadUtf16CodeUnitFromFile` slot assignment is the startup initializer write at `0x0041a2b1`, while raw/generated projection writes at `0x005995ea` and `0x00599821` are provenance evidence from [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), not ownership evidence for a separate table or source function. Keep `0x0069be1c` as `g_pfnReadUtf16CodeUnitFromFile` and keep raw `dword_69BE*` names out of final source where named slots are known.

The exact declaration surface is now complete across the 44-slot UID0002AS body, [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md), and [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md). Constructor UID0004N6 uses all 47 accepted names in exact assignment order: one unconditional reader and the complete NT-only sequence. No raw alias, forced runtime struct, duplicate source initializer, or consumer-local declaration is required.

## Full Startup Assignment Sequence

Current raw PE validation and the existing IDA-backed docs agree on this PlatformApi dispatch assignment sequence:

| Slot | Installed target/source |
| --- | --- |
| `0x0069be1c` | `ReadUtf16CodeUnitFromFile` at `0x00599570`, unconditional after `GetVersionExA` |
| `0x0069be20` | `FindWindowW` |
| `0x0069be24` | `OpenFileMappingW` |
| `0x0069be28` | `CreateMutexW` |
| `0x0069be2c` | `CreateDialogParamW` |
| `0x0069be30` | `LoadLibraryW` |
| `0x0069be34` | `CreateFileW` |
| `0x0069be38` | `CreateProcessW` |
| `0x0069be3c` | `CreateEventW` |
| `0x0069be40` | `RegisterClassW` |
| `0x0069be44` | `CreateWindowExW` |
| `0x0069be48` | `CreateFileMappingW` |
| `0x0069be4c` | `CreateSemaphoreW` |
| `0x0069be50` | `DefWindowProcW` |
| `0x0069be54` | `RegisterClipboardFormatW` |
| `0x0069be58` | `CharUpperBuffW` |
| `0x0069be5c` | `CreateDirectoryW` |
| `0x0069be60` | `DeleteFileW` |
| `0x0069be64` | `DispatchMessageW` |
| `0x0069be68` | `FindFirstFileW` |
| `0x0069be6c` | `FormatMessageW` |
| `0x0069be70` | `GetCurrentDirectoryW` |
| `0x0069be74` | `GetModuleFileNameW` |
| `0x0069be78` | `GetModuleHandleW` |
| `0x0069be7c` | `GetWindowsDirectoryW` |
| `0x0069be80` | `GlobalGetAtomNameW` |
| `0x0069be84` | `LoadCursorW` |
| `0x0069be88` | `LoadIconW` |
| `0x0069be8c` | `PeekMessageW` |
| `0x0069be90` | `PostMessageW` |
| `0x0069be94` | `RegCreateKeyExW` |
| `0x0069be98` | `RegDeleteKeyW` |
| `0x0069be9c` | `RegEnumValueW` |
| `0x0069bea0` | `RegQueryInfoKeyW` |
| `0x0069bea4` | `RegQueryValueExW` |
| `0x0069bea8` | `RegSetValueExW` |
| `0x0069beac` | `SetCurrentDirectoryW` |
| `0x0069be14` | `_wfopen` wrapper/address `0x005d253a` |
| `0x0069be18` | `_wstat64i32` wrapper/address `0x005e25aa` |
| `0x0069beb0` | `GetFileVersionInfoSizeW` wrapper/address `0x005c5c8d` |
| `0x0069beb4` | `GetFileVersionInfoW` wrapper/address `0x005c5c93` |
| `0x0069beb8` | `VerQueryValueW` wrapper/address `0x005c5c99` |
| `0x0069bebc` | `ImmGetCompositionStringW` wrapper/address `0x005c5cc9` |
| `0x0069bec0` | `ImmGetCandidateListW` wrapper/address `0x005c5ce7` |
| `0x0069bec4` | `SendMessageW` |
| `0x0069bec8` | `GetLocaleInfoW` |
| `0x0069becc` | `SetFileAttributesW` |

Timer/threading consumers also use the dispatch table:

| Address | Provisional name | Installed target | Known consumers |
| --- | --- | --- | --- |
| `0x0069be3c` | `g_pfnCreateEventW` / historical `dword_69BE3C` | `CreateEventW` | [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md): constructor call `0x005c1026` creates persistent `m_completionEvent`, exact raw [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) call `0x005c1134` creates transient `m_callbackGateEvent`; also [UID:0000OR][Thread](by-file/Thread.md), socket/browser worker helpers, and MIDI buffer event setup. |

Input/window-message consumers also use the dispatch table:

UID0003OD's 2026-08-12 exact vtable/source-role pass adds a second concrete `0x0069be64` consumer. [UID:00050N][0x00465ce0-0x00465ce6.ApplicationDispatchMessage](by-memory/0x00465ce0-0x00465ce6.ApplicationDispatchMessage.md) is the six-byte secondary-vtable body `jmp dword ptr [0x0069be64]`, reached only from the Application and BaramApp MSGHandler table slots at `0x00612608` and `0x0061d13c`. Its authored source is exactly `return g_pfnDispatchMessageW(message);`; it adds no null check, fallback, `this` use, or conversion. This consumer evidence strengthens the source-facing global name while leaving PlatformApi ownership and the `DispatchMessageW` initializer assignment unchanged.

| Address | Provisional name | Installed target | Known consumers |
| --- | --- | --- | --- |
| `0x0069be50` | `g_pfnDefWindowProcW` | `DefWindowProcW` | Consumed by main window/default fallback and [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) on `WM_IME_SETCONTEXT` when IME property bit `0x20000` is not set. |
| `0x0069be58` | `g_pfnCharUpperBuffW` / `dword_69BE58` | `CharUpperBuffW` | [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md) constructor uppercases `m_fieldMapEpfPath` after appending `.EPF`; PE import parsing resolves initializer source IAT cell `0x0060d39c` to `USER32.dll!CharUpperBuffW`. |
| `0x0069be64` | `g_pfnDispatchMessageW` / historical `dword_69BE64` | `DispatchMessageW` | [UID:00050N][0x00465ce0-0x00465ce6.ApplicationDispatchMessage](by-memory/0x00465ce0-0x00465ce6.ApplicationDispatchMessage.md) reads/tail-calls this slot at `0x00465ce0` as the Application/BaramApp MSGHandler secondary-vtable implementation; [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md) calls it at `0x0046f10b` after `TranslateMessage` for ordinary browser-thread messages. Both are consumers; PlatformApi owns declaration, storage, and initialization. |
| `0x0069be8c` | `g_pfnPeekMessage` / `dword_69BE8C` | `PeekMessageW` | [UID:0002H2][0x00464cd0-0x00464e1f.ApplicationRunMessageLoop](by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md) drains queued Win32 messages through this slot with `PM_REMOVE` at `0x00464d63` and `0x00464de1`; Application is a consumer, while PlatformApi owns the dispatch storage and initializer. |
| `0x0069be90` | `g_pfnPostMessageW` | `PostMessageW` | Consumed by [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) to post custom `WM_USER + 1` / `0x401` context-toggle notifications when active input-target state changes; [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md) also calls it at `0x0046f0c3` to post `WM_QUIT` to `g_pApplication->GetMainWindowHandle()` for Alt+F4 handling. |
| `0x0069bec4` | `g_pfnSendMessageW` / `dword_69BEC4` | `SendMessageW` | [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) is the dedicated storage page for this stale-alias high-risk slot; [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md) calls it at `0x0046f0e6` to forward Tab to the hosted Browser HWND, and BrowserThread remains only a consumer. |

Registry/startup parser consumers also use the dispatch table:

| Address | Provisional name | Installed target | Known consumers |
| --- | --- | --- | --- |
| `0x0069be14` | `g_pfnWideOpenFile` / `dword_69BE14` | `_wfopen` | [UID:0002BJ][0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser](by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md) reads the slot at `0x0048fd7f` to open the command-line-provided Thrunet auth file path with mode `"ro"` before parsing endpoint, port, and auth request data. |
| `0x0069be30` | `g_pfnLoadLibraryW` / `dword_69BE30` | `LoadLibraryW` | [UID:0002BK][0x00490200-0x0049050a.LgInternetSessionLauncherParser](by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md) calls the slot at `0x004902b5` with the full UTF-16 `chigamec.dll` operand at `0x00616f1c`, then resolves the ANSI `WaitForSessionParameter` export at `0x00616f38`. |
| `0x0069be80` | `g_pfnGlobalGetAtomNameW` / `dword_69BE80` | `GlobalGetAtomNameW` | [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md) validates a launcher global-atom token by calling the slot with `(ATOM)token`, a `128`-wide-character output buffer, and then comparing the returned atom name to the expected validation token. |

## IDA MCP Evidence

Checked on 2026-05-25 and 2026-05-26:

- 2026-07-04 B001 current MCP session `ba171fe4` reports health `ok` for `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. `lookup_funcs` reports `sub_41A280` at `0x0041a280`, size `0x228`; `0x0041a4a8`, `0x005995b0`, `0x0069be14`, `0x0069bec4`, and `0x0069bec8` are not functions. `get_bytes` returns zero bytes for `0x0069be14` size `176` and `0x0069bec4` size `12`, superseding older initial-byte notes on sibling storage pages.
- The same current pass reconfirms representative slot xrefs: `0x0069be14` has shown refs at `0x0041a42e`, `0x0042220e`, `0x004225dd`, `0x00422a26`, and `0x0045431d` with more; `0x0069be18` has `0x0041a438`, `0x00582104`, and `0x00582478`; `0x0069be34`, `0x0069be5c`, `0x0069be60`, `0x0069be70`, `0x0069be8c`, `0x0069be90`, version, IME, `0x0069bec4`, and tail slots all retain initializer refs plus live consumers. Wrapper lookups resolve `_wfopen` `0x005d253a`, `_wstat64i32` `0x005e25aa`, version thunks `0x005c5c8d`/`0x005c5c93`/`0x005c5c99`, IME thunks `0x005c5cc9`/`0x005c5ce7`, and cleanup wrapper `0x0060c440`.
- Historical pre-catalog0376 source-symbol checks found zero globals or names in `0x0069be14-0x0069bed0` and zero `type_query` hits for `*WideApi*`, `*g_pfn*`, and `*UniAPI*`. Current IDA now contains only the accepted first-two item names/types from catalog0376; no PDB or original typedef spellings were recovered, and the other 42 UID0002AS slots remain unchanged.
- 2026-07-24 B001 UID00014G support synchronization records the exact `ExceptionHandler::GenerateExceptionReport` dispatch reads: `0x004ab89d` calls `g_pfnGetWindowsDirectoryW` / slot `0x0069be7c` to obtain the report directory, `0x004ab8d7` calls `g_pfnWideOpenFile` / `_wfopen` slot `0x0069be14` with `L"wt"` to create `BCrash.nfo`, and `0x004abaf8` calls `g_pfnLoadLibraryW` / slot `0x0069be30` with `L"IMAGEHLP.DLL"`. This adds consumer evidence only and does not transfer table ownership or alter declarations, range, score, or initializer routing.
- 2026-07-30 supervisor catalog0376 applied/read back `FILE *(__cdecl *g_pfnWideOpenFile)(const wchar_t *path, const wchar_t *mode)` with 41 refs and `int (__cdecl *g_pfnWideStat)(const wchar_t *path, struct _stat64i32 *buffer)` with five refs. Both exact four-byte items remain zero with blank address comments; `_stat64i32` stays 48 bytes/11 members, the other 42 main-body slots remain unchanged, and saved IDB SHA256 is `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94`.
- 2026-08-16 B006 UID0000MI support synchronization records [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) as the exact `g_pfnWideOpenFile` consumer at `0x004b81fe`. Its `L"rb"`/null/close/boolean body remains PathUtil-owned; this adds one concrete consumer to the existing 41-xref slot evidence and does not transfer storage, initializer, declaration, or table ownership.

- `lookup_funcs 0x0041a280` reports `sub_41A280`, size `0x228`.
- `decompile 0x0041a280` calls `GetVersionExA`, assigns `dword_69BE1C = ReadUtf16CodeUnitFromFile`, and when `dwPlatformId == 2` writes the wide API pointer table.
- The same decompilation assigns `dword_69BE14 = _wfopen` at `0x0041a42e` and `dword_69BE18 = _wstat64i32` at `0x0041a438`.
- `disasm 0x0041a280` assigns `CreateFileW` to `dword_69BE34` at `0x0041a2f3-0x0041a2f8`; this is the file-open dispatch slot used by [UID:0002BZ][0x00526f10-0x00526f57.MidiSourceOpenHelper](by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md) and [UID:0002C7][0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper](by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md), among other file-open consumers.
- `disasm 0x0041a280` assigns `CreateEventW` to `dword_69BE3C` at `0x0041a30c`; this is the event-creation dispatch used by [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md). The accepted 2026-08-04 B005 UID0001NY pass counted 12 exact slot xrefs and resolved the two WaitableTimer consumers: constructor call `0x005c1026` stores the persistent completion event at `+0x04`, while raw start call `0x005c1134` stores the callback startup gate at `+0x28`. This supports source-facing `g_pfnCreateEventW`; `dword_69BE3C` remains only a historical raw alias, and WaitableTimer remains a consumer rather than table owner.
- `decompile 0x0041a280` assigns `SendMessageW` to `dword_69BEC4` at `0x0041a474`; the slot is documented by [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) because older aliases attached browser/transport names to its consumers.
- `xrefs_to 0x0069be18` reports exactly five refs: initializer write `0x0041a438`, [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) read `0x00582104`, [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) read `0x00582478`, retained [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md) store `0x0059976d`, and retained raw projection store `0x005999a8`.
- `xrefs_to 0x0069be14` reports the initializer write at `0x0041a42e`, the [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) read at `0x00582118`, and many additional direct file-open consumers.
- B007's accepted UID0002H2 implementation pass on 2026-06-29 rechecked MCP session `b6b3c97e` and confirmed `xrefs_to 0x0069be8c` includes the initializer write plus [UID:0002H2][0x00464cd0-0x00464e1f.ApplicationRunMessageLoop](by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md) reads/calls at `0x00464d63` and `0x00464de1`. This supports the source-facing `g_pfnPeekMessage` consumer name in Application code without moving the dispatch slot out of PlatformApi.
- 2026-05-26 IDA MCP recheck reconfirmed the same initializer writes and consumer pattern. The broad `0x0069be14` xrefs include screenshot file-open paths, profile/config I/O, startup/resource loads, and `StdioFile::Open`, reinforcing platform-table ownership rather than any one consumer module.
- 2026-06-17 B002 source-quality reanalysis of [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) confirmed another direct `_wfopen` dispatch consumer: instruction `0x004f50cd` reads `0x0069be14` while opening the startup `.LGO` path in binary mode.
- 2026-06-17 B002 source-quality reanalysis of [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md) names the `0x0069be1c` slot target as `ReadUtf16CodeUnitFromFile`. That helper checks `feof`, returns `0xffff` at EOF, otherwise reads one two-byte UTF-16 code unit with `fread`, and remains part of the PlatformApi helper island.
- 2026-05-26 IDA MCP confirms [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) is the static cleanup wrapper registered by the initializer. It writes the `UniAPIInit` vtable pointer at `0x006702c4` and is not part of the adjacent pool cleanup wrappers.
- 2026-06-05 IDA MCP recheck confirmed `sub_41A280`, size `0x228`, no direct callers, `GetVersionExA`/`atexit`/security-cookie callees, and xrefs to dispatch entries including `_wfopen`, `_wstat64i32`, `CreateEventW`, and `SendMessageW` slots.
- 2026-06-18 B002 [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) source-quality reanalysis resolves the FieldMapPane constructor's `call dword ptr [0x0069be58]` as `CharUpperBuffW(fieldMapEpfPath, wcslen(fieldMapEpfPath))`, not a FieldMap-owned path helper. The slot is installed from IAT cell `0x0060d39c`, which imports `USER32.dll!CharUpperBuffW`.
- 2026-06-20 B005 [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) source-quality incorporation names `0x0069be5c` / `dword_69BE5C` as the wide directory-create dispatch consumed by JPG screenshot setup after formatting `Documents\NexusTK` and `Documents\NexusTK\ScreenShots`; BMP/PNG capture uses the same directory setup family.
- 2026-06-21 B008 [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md) source-quality incorporation names `0x0069be80` / `dword_69BE80` as `g_pfnGlobalGetAtomNameW`, installed from `KERNEL32.dll!GlobalGetAtomNameW` IAT cell `0x0060d260` by [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) at `0x0041a3b1-0x0041a3b6`. This rejects RegistryConfig/Netsgo-local callback ownership for the slot.
- 2026-06-26 B006 [UID:0002BJ][0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser](by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md) source-quality incorporation confirms another `_wfopen` dispatch consumer: `sub_48FCA0` reads/calls `0x0069be14` at `0x0048fd7f` with the command-line-provided Thrunet auth-file path and mode string `"ro"`. The dispatch-table initializer write remains [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) at `0x0041a42e`; the RegistryConfig parser is only a consumer.
- 2026-06-27 B009 [UID:0002BK][0x00490200-0x0049050a.LgInternetSessionLauncherParser](by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md) source-quality implementation confirms `0x0069be30` / `dword_69BE30` as `g_pfnLoadLibraryW`, installed by [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) and consumed at `0x004902b5` to load `chigamec.dll` before `GetProcAddress("WaitForSessionParameter")`.
- 2026-06-22 B013 ProfileLoadAndLegacyImport source-quality incorporation rechecked exported `0x0041a280` facts and resolves the ProfileStorage path slots: `0x0069be5c` is `CreateDirectoryW`, `0x0069be60` is `DeleteFileW`, and `0x0069be70` is `GetCurrentDirectoryW`. ProfileStorage is a consumer of these PlatformApi dispatch entries, not their owner.
- 2026-06-26 B009 WinMain implementation sync confirms another `0x0069be70` consumer. MCP session `80de0a67` shows [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) calls the slot at `0x004f5d92` with count `0x104` and a local buffer before assigning that buffer to `SHELLEXECUTEINFOA.lpDirectory` and calling imported `ShellExecuteExA` at `0x004f5e16`. Keep the installed target as `GetCurrentDirectoryW`; do not rename the slot to `GetCurrentDirectoryA` just because this caller feeds the buffer to an ANSI shell-execute structure.

## Ownership Decision

Keep the dispatch table with [UID:0000ML][PlatformApi](by-file/PlatformApi.md), not with `StdioFile`, `PathUtil`, screenshot/image writers, map loading, startup-logo loading, or audio. Those modules consume specific entries through the platform abstraction; they do not own the process-wide compatibility table.

This table is closely related to [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md). Although IDA does not model `0x005995b0` as a function and it has no linked route, exact member shape plus the live UID0000WD inlined counterpart establish UID0004N6 as the human source constructor. UID0000WD remains exact runtime code evidence only.

2026-06-21 B007 source-shape reanalysis keeps this ownership but refines the C++ style: [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md) now emits the `UniAPIInit` class declaration, PlatformApi owns the file-local static object and grouped dispatch globals, [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) is the real initializer/inlined constructor logic, and [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) `0x005995b0` remains no-code raw/generated duplicate evidence. Consumer modules remain call/read evidence only.

As of the 2026-06-07 A010 Batch057 parent-gate review, this page is the direct by-global parent for the split table-body memory pages. Child pages [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) and [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) can attach here because the child pages clear `85/85` and this table page now clears `90/86`; this page can retain [UID:0000ML][PlatformApi](by-file/PlatformApi.md) because the file page now clears `88/85`.

## Cross-References

- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md)
- [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md)
- [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md)
- [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md)
- [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000MI][PathUtil](by-file/PathUtil.md)
- [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0002BJ][0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser](by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md)
- [UID:0002BK][0x00490200-0x0049050a.LgInternetSessionLauncherParser](by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md)
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md)

## Changes

- 2026-08-17 B007 UID0000PA narrow-header consumer closure:
  - Preserved the 44-entry PlatformApi dispatch-table definitions, startup assignment sequence, owner/emitter route, and W-suffixed API identities.
  - The exact child [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) now exposes three H declarations: wide open, wide stat, and `g_pfnGetCurrentDirectoryW`, with the required Windows SDK dependency.
  - WinMain is a consumer, not an owner: it uses the current-directory dispatch and intentionally retains the observed ANSI `SHELLEXECUTEINFOA`/`ShellExecuteExA` launch route. No second dispatch table or WinMain-owned extern is introduced.

- 2026-08-16 B006 UID0000MI support synchronization: added the exact FileExists read/call at `0x004b81fe`, its `L"rb"` open/close boolean role, and the PathUtil-consumer/PlatformApi-provider boundary while preserving table ownership, 41-xref state, declaration model, and score.

- 2026-08-04 B005 UID0001NY support synchronization:
  - Expanded `0x0069be3c` with all 12 report-time xrefs in scope and the exact WaitableTimer constructor/start call sites and distinct completion-event/callback-gate destinations.
  - Preserved PlatformApi ownership and existing score/declaration state; this is consumer evidence only and does not move the dispatch slot into WaitableTimer.
- 2026-07-30 B010 UID0002AP post-Gate2B reconciliation:
  - Updated only the first two table dispositions to catalog0376-applied `g_pfnWideOpenFile` and `g_pfnWideStat` types/names, preserving `dword_69BE14`/`dword_69BE18` as historical aliases and all 41/five refs.
  - Explicitly left the remaining 42 UID0002AS IDA slots, source declarations, initializer sequence, consumers, table ownership, score, and aggregate blank formal block unchanged.

- 2026-07-24 B001 UID00014G support synchronization: added report-level `ExceptionHandler::GenerateExceptionReport` consumer detail to `g_pfnWideOpenFile` / `_wfopen` at `0x0069be14`, `g_pfnLoadLibraryW` / `LoadLibraryW` at `0x0069be30`, and `g_pfnGetWindowsDirectoryW` / `GetWindowsDirectoryW` at `0x0069be7c`, including exact call sites, report path/open mode, and ImageHlp operand. Score, declarations, source placement, memory split, initializer, and PlatformApi ownership remain unchanged.
- 2026-07-24 B001 UID0001IZ support verification: changed the `_wstat64i32` consumer row to canonical source-bearing UID0001IZ with UID0000V6 explicitly retained as its non-emitting mirror, and replaced the vague retained-projection wording with all five exact `0x0069be18` xrefs. Score, ownership, and dispatch-table disposition are unchanged.

- 2026-07-14 B004 UID0003E5 callback: raised `90/86` to `92/91`; preserved owner/emitter UID0000ML, reconstructable state, blank aggregate formal block, grouped-global model, full assignment sequence, consumers, and rejected raw/struct/local alternatives; linked exact constructor UID0004N6 and recorded complete declaration coverage across UID0002AS, UID0001Q1, and UID0002A6.

- 2026-07-04 B001 UID0002AS implementation callback:
  - Score unchanged at `90/86`.
  - Added current MCP session `ba171fe4` confirmation for UID0002AS formal declaration readiness: zero-initialized 176-byte / 44-dword main body, live `sub_41A280` initializer range, representative xrefs, wrapper/thunk facts, negative name/type evidence, raw `0x005995b0` projection rejection, and preserved sibling boundaries for UID0001Q1/UID0002A6.
- 2026-07-03 B008 UID00032Q support sync:
  - Added explicit [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md) consumer rows for the `DispatchMessageW`, `PostMessageW`, and `SendMessageW` dispatch slots. Current MCP session `b010_00032w_20260703` confirms calls at `0x0046f10b`, `0x0046f0c3`, and `0x0046f0e6`; BrowserThread does not own the PlatformApi storage.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/82`. Summary/evidence: the page documents table ranges, concrete slots, initializer/decompilation evidence, consumer families, ownership decision, and prior range-split correction; final dispatch symbol names remain provisional.

- 2026-05-28 dispatch range split:
  - What existed before: the table range was described as one continuous `0x0069be14-0x0069bed0` dispatch-pointer cluster.
  - Changed to: the table is documented as `0x0069be14-0x0069bec4` plus `0x0069bec8-0x0069bed0`, with [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) called out as the intervening non-dispatch slot.
  - Summary/evidence: IDA MCP xref audit of the former `0x0069ba3c-0x0069bec4` UNKNOWN row and prior `g_browserControlKeyCallback` review show `0x0069bec4` is browser/transport callback storage, while [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) and [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) hold the dispatch pointers.
- 2026-06-02 SendMessageW slot correction:
  - What existed before: the page described [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) as an intervening non-dispatch browser/transport callback slot.
  - Changed to: the page now includes it as the `SendMessageW` dispatch slot in the wide API table, while preserving the separate memory page because stale aliases make it a high-risk reference target.
  - Summary/evidence: IDA MCP decompilation of [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) writes `SendMessageW` to `dword_69BEC4` at `0x0041a474`, between `ImmGetCandidateListW` and `GetLocaleInfoW`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
  - Reason: live IDA MCP recheck confirms this source-declared platform dispatch table is installed by the wide API initializer and consumed broadly by platform/file/event/message callers.
- 2026-06-07 A010 Batch057 parent-gate review:
  - What existed before: `CONFIDENCE:82`, with exact split memory pages already documented but direct-child routing blocked by the corrected 85/85 gate.
  - Changed to: `CONFIDENCE:86`, retained [UID:0000ML][PlatformApi](by-file/PlatformApi.md), and added the explicit split memory table.
  - Summary/evidence: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) documents the exact initializer, [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) resolves the stale `SendMessageW` slot, and [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) plus [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) cover the table body and tail. Remaining uncertainty is final typedef/name style, not range or owner.
- 2026-06-16 A002 MIDI source-core support refresh:
  - What existed before: the page described `CreateFile` as a confirmed table entry but did not list the exact `0x0069be34` slot row, leaving MIDI/source helper pages to repeat a `dword_69BE34` local-alias caveat.
  - Changed to: added the `0x0069be34` `CreateFileW` row and explicit initializer evidence.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` showed `0x0041a2f3: mov eax, ds:CreateFileW` followed by `0x0041a2f8: mov dword ptr unk_69BE34, eax`; `xrefs_to 0x0069be34` reports the initializer write, MIDI source-open read at `0x00526f49`, SMF document-loader read at `0x00527400`, and broader file-open consumers. Score unchanged because this resolves a row-level support detail, not the table owner/range confidence.
- 2026-06-17 B002 LogoPane `_wfopen` consumer sync:
  - What changed: added [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) as a concrete consumer of the `0x0069be14` `_wfopen` dispatch slot.
  - Summary/evidence: B002 verified the retained static-logo loader reads the slot at `0x004f50cd` while opening the startup logo path. Score unchanged because ownership and range confidence were already established.
- 2026-06-17 B002 PlatformStringConversionHelpers reader-slot sync:
  - What changed: added the `0x0069be1c` row as `g_pfnReadUtf16CodeUnitFromFile` / `dword_69BE1C`, installed target `ReadUtf16CodeUnitFromFile`.
  - Summary/evidence: B002 rechecked the [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md) helper body and xrefs from the real initializer plus raw/generated `UniAPIInit` projection refs. The table remains owned by [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
- 2026-06-18 B001 InputMan support check:
  - What changed: added explicit `0x0069be50` and `0x0069be90` entries as `g_pfnDefWindowProcW` and `g_pfnPostMessageW`.
  - Summary/evidence: `0x0041a280` initializer JSON/decompilation installs `DefWindowProcW` and `PostMessageW`; [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) consumes them for `WM_IME_SETCONTEXT` default handling and `WM_USER + 1` input-context toggle posts.
- 2026-06-18 B002 FieldMapPane path-uppercase slot sync:
  - What changed: added explicit `0x0069be58` as `g_pfnCharUpperBuffW` / `dword_69BE58`.
  - Summary/evidence: [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) reanalysis traced the FieldMapPane constructor sequence after `.EPF` append to `call dword ptr [0x0069be58]`, and PE import parsing resolves initializer source IAT cell `0x0060d39c` to `USER32.dll!CharUpperBuffW`. The table remains owned by [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
- 2026-06-20 B005 screenshot directory-create slot sync:
  - What changed: added explicit `0x0069be5c` as provisional `g_pfnCreateDirectoryW` / `dword_69BE5C`.
  - Summary/evidence: [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) calls this slot after formatting `Documents\NexusTK` and `Documents\NexusTK\ScreenShots`; sibling BMP/PNG screenshot capture follows the same directory setup pattern. The exact final typedef/name remains medium confidence until an initializer/import-slot pass refreshes the table, but the consumer role is wide directory creation.
- 2026-06-21 B007 UniAPIInit source-shape sync:
  - What changed: added the grouped file-scope dispatch-global C++ direction, the full startup assignment sequence, and rejected alternatives for raw `dword_` names, consumer ownership, and forced struct/table emission.
  - Summary/evidence: B007 reanalysis validates the file-local static `UniAPIInit` object model, the real [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) initializer route, no-route proof for `0x005995b0`, and PlatformApi ownership of both the dispatch storage and static initializer policy.
- 2026-06-21 B008 Netsgo parser support sync:
  - What changed: added explicit `0x0069be80` as `g_pfnGlobalGetAtomNameW` / `dword_69BE80`, with [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md) as a concrete consumer.
  - Summary/evidence: B008 local PE/import analysis resolves the slot as `KERNEL32.dll!GlobalGetAtomNameW` installed from IAT cell `0x0060d260`; the Netsgo parser call at `0x0048f9f8` is a platform dispatch read, not an unresolved callback.
- 2026-06-21 B008 TextPad source-quality sync:
  - Score unchanged at `90/86`.
  - Synced `0x0069be34` as the provider slot for TextPad `Open`/`Save` helpers. TextPad remains the owner of the UI/file command methods; this table only owns the process-wide `CreateFileW` dispatch pointer.
- 2026-06-22 B013 ProfileStorage path-slot sync:
  - Score unchanged at `90/86`.
  - Updated `0x0069be5c` to the direct `CreateDirectoryW` target and added `0x0069be60` / `DeleteFileW` plus `0x0069be70` / `GetCurrentDirectoryW` as concrete ProfileStorage loader/import path dependencies. These remain PlatformApi dispatch globals rather than ProfileStorage-owned local globals.
- 2026-06-19 B014 UniAPIInit projection sync:
  - Score unchanged at `90/86`.
  - Added the projection-vs-live-write caveat for `0x0069be1c`: startup initializer [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) owns the live write, while [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) raw writes are retained projection/provenance evidence.
- 2026-06-26 B009 WinMain current-directory consumer sync:
  - Score unchanged at `90/86`.
  - Added WinMain's updater-launch read of `0x0069be70` at `0x004f5d92` and recorded the target-specific W-dispatch/A-`ShellExecuteExA` mismatch as a consumer caveat.
- 2026-06-26 B006 Thrunet auth-file parser support sync:
  - Score unchanged at `90/86`.
  - Added [UID:0002BJ][0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser](by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md) as a concrete `0x0069be14` `_wfopen` dispatch consumer opening the command-line auth file with mode `"ro"`.
- 2026-06-27 B009 LG Internet session parser support sync:
  - Score unchanged at `90/86`.
  - Added `0x0069be30` as `g_pfnLoadLibraryW` / `dword_69BE30`, installed from `LoadLibraryW` and consumed by [UID:0002BK][0x00490200-0x0049050a.LgInternetSessionLauncherParser](by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md) at `0x004902b5` to load `chigamec.dll` before resolving `WaitForSessionParameter`.
