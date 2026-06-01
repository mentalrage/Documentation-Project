*** UID:00000D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Application

## Summary

`Application` is the main NexusTK client application singleton. It owns the Win32 process/window lifecycle, startup/shutdown ordering, DirectDraw setup entry points, patch continuation checks, license validation, message-loop dispatch, and global singleton creation/destruction.

## Likely Original Placement

- Source: [UID:0000HG][Application](by-file/Application.md)
- Proposed path: `app/Application.cpp`
- Header: `app/Application.h`
- Confidence: strong

## Methods

- [UID:0002GY][0x00463310-0x0046396e.ApplicationConstructor](by-memory/0x00463310-0x0046396e.ApplicationConstructor.md) `Application` - constructs the singleton, sets `g_pApplication`, records startup timestamps, executable paths, screen defaults, OS string, and module handle.
- [UID:0002GZ][0x00463970-0x004639c4.ApplicationDestructor](by-memory/0x00463970-0x004639c4.ApplicationDestructor.md) `~Application` - closes the single-instance mutex, destroys string members and `MSGHandler`, clears `g_pApplication`.
- [UID:0002H0][0x004639d0-0x00464a52.ApplicationInitialize](by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md) `Initialize` - creates the main window, validates [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md), resumes patch state, initializes DirectDraw and core singleton managers, and constructs platform diagnostics singletons including [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) and [UID:00003A][Crasher](by-class/Crasher.md).
- [UID:0002H1][0x00464a60-0x00464cc1.ApplicationCleanupResources](by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md) `CleanupResources` - final teardown pass for managers, [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion queue, crash-diagnostics singletons, keyboard state, window visibility, error display, and shutdown handles.
- [UID:0002H2][0x00464cd0-0x00464e1f.ApplicationRunMessageLoop](by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md) `RunMessageLoop` - main Win32 loop around `MsgWaitForMultipleObjects`, message dispatch, `InputMan` input-mode checks, and idle work.
- [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) `RequestExit` - requests application shutdown and defers final exit through other subsystems.
- [UID:0002H4][0x00464f40-0x00464f47.ApplicationIsExitRequested](by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md) `IsExitRequested`.
- [UID:0002H5][0x00464f50-0x00465115.ApplicationDetectOS](by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md) `DetectOS` - maps Win32 version information and WOW64 state to internal OS fields.
- [UID:0002JV][0x00465120-0x00465124.ApplicationGetOsCode](by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md) `GetOsCode` candidate - returns the internal OS code at `this + 0x10`; no direct callers currently known.
- [UID:0002JW][0x00465130-0x004651b8.ApplicationReadProcessorName](by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md) `ReadProcessorName` candidate - raw function-shaped method that reads the CPU registry `ProcessorNameString` into the Application field at `this + 0x1c`; no direct callers currently known.
- [UID:0002GM][0x004651c0-0x004651c4.ApplicationGetInstanceHandle](by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md) `GetInstanceHandle` - returns `this + 0x20` as the stored `HINSTANCE`.
- [UID:0002GN][0x004651d0-0x004651d7.ApplicationGetMainWindowHandle](by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md) `GetMainWindowHandle` - returns `this + 0x828` as the main `HWND`.
- [UID:0002GO][0x004651e0-0x004651e7.ApplicationIsRunning](by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md) `IsRunning` - returns the byte flag at `this + 0x838`.
- [UID:0002JY][0x004652e0-0x004652fc.ApplicationCopyProcessorName](by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md) `CopyProcessorName` candidate - copies the stored processor-name string with `wcscpy_s`.
- [UID:0002GP][0x00465300-0x00465308.ApplicationGetVersionMajor](by-memory/0x00465300-0x00465308.ApplicationGetVersionMajor.md) stale `GetVersionMajor` candidate - returns `this + 0x850`, now better understood as a license/version-validation status code written by `ValidateLicense`.
- [UID:0002GQ][0x00465310-0x00465318.ApplicationGetVersionMinor](by-memory/0x00465310-0x00465318.ApplicationGetVersionMinor.md) stale `GetVersionMinor` candidate - returns `this + 0x842`, the low word of `VS_FIXEDFILEINFO.dwFileVersionLS` stored by `ValidateLicense`.
- [UID:0002H6][0x00465430-0x0046564c.ApplicationValidateLicense](by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md) `ValidateLicense` - checks executable version-resource fields against the embedded `7TK5E-KRU-2K` digit code.
- [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md) `ExchangeMSGHandler` - swaps active message-handler target through the application critical section.
- [UID:0002GS][0x00465690-0x0046572d.ApplicationMapFromScreen](by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md) `MapFromScreen` - scales current-screen coordinates into the base client coordinate space.
- [UID:0002GT][0x00465730-0x004657cd.ApplicationMapToScreen](by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md) `MapToScreen` - inverse coordinate scaling helper.
- [UID:0002GU][0x00465b70-0x00465b89.ApplicationCopyWorldName](by-memory/0x00465b70-0x00465b89.ApplicationCopyWorldName.md) `CopyWorldName` - copies the stored wide world/server name through `wcscpy_s`.
- [UID:0002GV][0x00465b90-0x00465bac.ApplicationCopyPlayerName](by-memory/0x00465b90-0x00465bac.ApplicationCopyPlayerName.md) `CopyPlayerName` - copies the stored wide local-player name through `wcscpy_s`.
- [UID:0002GW][0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog](by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md) `DestroyLoadingDialog` - destroys `this + 0x82c` with `DestroyWindow`.
- `0x00467230` `ScalarDeletingDestructor`.
- Related startup helper: [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) at `0x00467410`, likely file-local to `Application.cpp` rather than an `Application` method.
- [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md) `SendShutdownMessage` - constructs the `0x676f6f67` message object and forwards it through `ForwardMessage`.
- `0x004f4b30` `RegisterChangeMessage` candidate - forwards to [UID:00001K][ChangeMan](by-class/ChangeMan.md).
- `0x004f4b50` `UnregisterChangeMessage` candidate - forwards to [UID:00001K][ChangeMan](by-class/ChangeMan.md).
- `0x004f4b70` `ForwardMessage` - forwards to [UID:00001K][ChangeMan](by-class/ChangeMan.md).
- [UID:0002H7][0x004f5fb0-0x004f6490.ApplicationStartup](by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md) `Startup`.
- [UID:0002H8][0x004f6490-0x004f66a5.ApplicationShutdown](by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md) `Shutdown`.

## Fields And Globals

Known layout notes from Wave3:

- total object size around 2676 bytes;
- `LObject` base plus `MSGHandler` subobject;
- `m_hMainWnd` at `0x828`;
- `m_hLoadingDlg` at `0x82c`;
- `m_hShutdownEvent` at `0x83c`;
- active message dispatcher pointer around `0x844`;
- `m_hInstance` around `0x20`;
- OS code/string fields around `0x10` and `0x854`.
- CPU processor-name string field around `0x1c`, populated from `HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\ProcessorNameString`.
- license/version-check fields at `0x842` and `0x850`: current IDA evidence shows `0x842` receives `LOWORD(VS_FIXEDFILEINFO.dwFileVersionLS)` and `0x850` receives a license/version-validation status code.

Important globals include `g_pApplication`, `g_appState`, `g_appErrorState`, `g_defaultScreenWidth`, `g_defaultScreenHeight`, `g_hGameModule`, shutdown-object globals, and many subsystem singleton pointers created or destroyed through this class.

## Evidence

- IDA MCP confirms key function boundaries: `0x00463310-0x0046396e`, `0x004639d0-0x00464a52`, `0x00464cd0-0x00464e1f`, `0x004f5fb0-0x004f6490`, and `0x004f6490-0x004f66a5`.
- IDA MCP shows `Startup` calls the image-library and UI singleton constructors already documented in render and UI docs.
- IDA MCP shows `Initialize` calls [UID:00000W][BlackHole](by-class/BlackHole.md) construction at `0x00464549`, and cleanup drains/destroys `dword_67A74C`.
- IDA MCP shows `Initialize` calls [UID:00001K][ChangeMan](by-class/ChangeMan.md) construction at `0x004644c1`; message wrapper methods later read `g_pChangeMan`.
- IDA MCP shows `Initialize` calls [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) construction at `0x00463e3a`, [UID:00003A][Crasher](by-class/Crasher.md) construction at `0x004646ec`, and cleanup touches [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) / [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) at `0x00464c4e` / `0x00464c5e`.
- IDA MCP shows `Initialize` calls [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) construction at `0x00464715`; cleanup later destroys [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) at `0x00464a88`.
- IDA MCP on 2026-05-25 shows [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md) is called only by `Initialize`, formats numbered `*.DAT` paths, and calls [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) for each existing file.
- IDA MCP on 2026-05-31 split the small accessors and helpers at `0x004651c0`, `0x004651d0`, `0x004651e0`, `0x00465300`, `0x00465310`, `0x00465650`, `0x00465690`, `0x00465730`, `0x00465b70`, `0x00465b90`, `0x00465bb0`, and `0x00467960` into exact child method pages with range-local C++ snippets.
- IDA MCP on 2026-05-31 split the previously missing local Application gap at `0x00465120-0x00465424`: OS-code accessor, processor-name registry reader, executable-path version-info helper, processor-name copy accessor, and executable version low-word helper. The same pass showed `ValidateLicense` writes the `0x842` / `0x850` fields, making the old version-major/minor labels provisional.
- IDA MCP disassembly/string reads on 2026-05-25 resolve the fixed and looped [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md) names loaded by the constructor and `Initialize`.
- Generated source includes `Patch\Info`, `Patch\Script`, `DirectDrawCreate`, `MsgWaitForMultipleObjects`, and license key `7TK5E-KRU-2K`; patch UI/download implementation belongs in [UID:0000MH][PatchPane](by-file/PatchPane.md).

## Open Questions

- Confirm whether `WinMain`, `BaramApp`, and `MSGHandler` should all be one `Application.cpp` or split into `WinMain.cpp`, `BaramApp.cpp`, and `MSGHandler.cpp`.
- Review the Wave3/IDA mismatch around `BaramApp::BaramApp` at `0x004f5f20` before using that address as a firm function start.
- Keep [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) and [UID:00003A][Crasher](by-class/Crasher.md) as startup-owned dependencies, not as members of the final `Application.cpp` source file, unless later source-order evidence proves they were private helper classes.
- Keep [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) near this application startup module, but do not promote it to an `Application` member unless later evidence finds a hidden `this` dependency.

## Cross-References

- File: [UID:0000HG][Application](by-file/Application.md)
- Related classes: [UID:00000V][BaramApp](by-class/BaramApp.md), [UID:00008S][MSGHandler](by-class/MSGHandler.md), [UID:00001K][ChangeMan](by-class/ChangeMan.md), [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md), [UID:00000W][BlackHole](by-class/BlackHole.md), [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md), [UID:00003A][Crasher](by-class/Crasher.md), [UID:00006J][InputMan](by-class/InputMan.md), [UID:00006C][IdleWatcher](by-class/IdleWatcher.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Resource: [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md)
- Memory: [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md), [UID:0002JV][0x00465120-0x00465124.ApplicationGetOsCode](by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md), [UID:0002JW][0x00465130-0x004651b8.ApplicationReadProcessorName](by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md), [UID:0002JX][0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo](by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md), [UID:0002JY][0x004652e0-0x004652fc.ApplicationCopyProcessorName](by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md), [UID:0002JZ][0x00465320-0x00465424.GetExecutableVersionLowWord](by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md), [UID:0002GM][0x004651c0-0x004651c4.ApplicationGetInstanceHandle](by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md), [UID:0002GN][0x004651d0-0x004651d7.ApplicationGetMainWindowHandle](by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md), [UID:0002GO][0x004651e0-0x004651e7.ApplicationIsRunning](by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md), [UID:0002GP][0x00465300-0x00465308.ApplicationGetVersionMajor](by-memory/0x00465300-0x00465308.ApplicationGetVersionMajor.md), [UID:0002GQ][0x00465310-0x00465318.ApplicationGetVersionMinor](by-memory/0x00465310-0x00465318.ApplicationGetVersionMinor.md), [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md), [UID:0002GS][0x00465690-0x0046572d.ApplicationMapFromScreen](by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md), [UID:0002GT][0x00465730-0x004657cd.ApplicationMapToScreen](by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md), [UID:0002GU][0x00465b70-0x00465b89.ApplicationCopyWorldName](by-memory/0x00465b70-0x00465b89.ApplicationCopyWorldName.md), [UID:0002GV][0x00465b90-0x00465bac.ApplicationCopyPlayerName](by-memory/0x00465b90-0x00465bac.ApplicationCopyPlayerName.md), [UID:0002GW][0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog](by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md), [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md), [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md), [UID:00019B][0x004f4b70-0x004f4b86.ApplicationForwardMessage](by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md), [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md), [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md), [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md), [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md), [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md), [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)

## Changes

- 2026-05-31 reconstruction-code removal:
  - What existed before: the class page emitted a draft `class Application` C++ block with final-looking method declarations, including stale `GetVersionMajor` / `GetVersionMinor` names and a likely wrong `ValidateLicense(const char*)` signature.
  - What it was changed to: removed the C++ block contents and kept the class reconstructable/attached only through documentation for now.
  - Summary/evidence: current by-structure policy requires final-source-quality C++ only at near-final confidence; the fresh IDA pass showed the version accessor names/signature evidence is not ready for emitted source.

- 2026-05-31 autogen attachment:
  - What existed before: the reconstruction skeleton listed the main lifecycle methods but had no child insertion marker and did not declare the ChangeMan wrapper methods.
  - What it was changed to: added a `MSGHandler` forward declaration, the ChangeMan wrapper method declarations, and a `[[CHILDREN]]` insertion point for exact child bodies.
  - Summary/evidence: IDA MCP confirms `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` as tiny `Application` wrappers over `g_pChangeMan`; attaching those child bodies under this class lets `auto-generated/NexusTK/app/Application.cpp` show the currently supported draft layout.
- 2026-05-31 small method split:
  - What existed before: the class page listed many `Application` methods as address-only bullets, including two name helpers as pointer-style getters.
  - What it was changed to: linked the verified lifecycle/accessor/helper methods to exact by-memory child pages, corrected the wide-name helpers to `CopyWorldName`/`CopyPlayerName`, and updated the class reconstruction declarations to match IDA-observed signatures.
  - Summary/evidence: IDA MCP `lookup_funcs`/`decompile` verifies each new exact child range and shows the wide-name helpers return `wcscpy_s`, not raw pointers.
