*** UID:00000D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- [UID:0002H2][0x00464cd0-0x00464e1f.ApplicationRunMessageLoop](by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md) `RunMessageLoop` - main Win32 loop around `MsgWaitForMultipleObjects`, PlatformApi `PeekMessage`, browser/input message gating, critical-section-guarded `MSGHandler` dispatch, idle work, and heartbeat/throttle counters.
- [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) `RequestExit` - requests application shutdown, coordinates active browser/map/minimap/screen state, then either queues a private callback helper or directly signals the shutdown event and writes the exit-request flag.
- [UID:0002H4][0x00464f40-0x00464f47.ApplicationIsExitRequested](by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md) `IsExitRequested`.
- [UID:0002H5][0x00464f50-0x00465115.ApplicationDetectOS](by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md) `DetectOS` - maps Win32 version information and WOW64 state to internal OS fields.
- [UID:0002JV][0x00465120-0x00465124.ApplicationGetOsCode](by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md) `GetOsCode` candidate - returns the internal OS code at Application offset `0x10`; no direct callers currently known.
- [UID:0002JW][0x00465130-0x004651b8.ApplicationReadProcessorName](by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md) `ReadProcessorName` candidate - raw function-shaped method that reads the CPU registry `ProcessorNameString` into the Application processor-name string owner around offset `0x1c`; no direct callers currently known, and the companion copy accessor proves the concrete copied wide buffer is reached at `Application + 0x428`.
- [UID:0002GM][0x004651c0-0x004651c4.ApplicationGetInstanceHandle](by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md) `GetInstanceHandle` - returns the stored `HINSTANCE` at Application offset `0x20`.
- [UID:0002GN][0x004651d0-0x004651d7.ApplicationGetMainWindowHandle](by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md) `GetMainWindowHandle` - returns the main `HWND` at Application offset `0x828`.
- [UID:0002GO][0x004651e0-0x004651e7.ApplicationIsRunning](by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md) `IsRunning` - returns the running/active byte flag at Application offset `0x838`.
- [UID:0002JY][0x004652e0-0x004652fc.ApplicationCopyProcessorName](by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md) `CopyProcessorName` candidate - copies the stored processor-name wide buffer at `Application + 0x428` with `wcscpy_s`.
- [UID:0002GP][0x00465300-0x00465308.ApplicationGetVersionMajor](by-memory/0x00465300-0x00465308.ApplicationGetVersionMajor.md) stale `GetVersionMajor` candidate - returns Application offset `0x850`, now better understood as a license/version-validation status code written by `ValidateLicense`.
- [UID:0002GQ][0x00465310-0x00465318.ApplicationGetVersionMinor](by-memory/0x00465310-0x00465318.ApplicationGetVersionMinor.md) stale `GetVersionMinor` candidate - returns Application offset `0x842`, the low word of `VS_FIXEDFILEINFO.dwFileVersionLS` stored by `ValidateLicense`.
- [UID:0002H6][0x00465430-0x0046564c.ApplicationValidateLicense](by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md) `ValidateLicense` - checks executable version-resource fields against the embedded `7TK5E-KRU-2K` digit code.
- [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md) `ExchangeMSGHandler` - swaps active message-handler target through the application critical section.
- [UID:0002GS][0x00465690-0x0046572d.ApplicationMapFromScreen](by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md) `MapFromScreen` - scales current-screen coordinates into the base client coordinate space.
- [UID:0002GT][0x00465730-0x004657cd.ApplicationMapToScreen](by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md) `MapToScreen` - inverse coordinate scaling helper.
- [UID:0002GU][0x00465b70-0x00465b89.ApplicationCopyWorldName](by-memory/0x00465b70-0x00465b89.ApplicationCopyWorldName.md) `CopyWorldName` - copies the stored wide world/server name through `wcscpy_s`.
- [UID:0002GV][0x00465b90-0x00465bac.ApplicationCopyPlayerName](by-memory/0x00465b90-0x00465bac.ApplicationCopyPlayerName.md) `CopyPlayerName` - copies the stored wide local-player name through `wcscpy_s`.
- [UID:0002GW][0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog](by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md) `DestroyLoadingDialog` - destroys the loading-dialog handle at Application offset `0x82c` with `DestroyWindow`.
- [UID:000323][0x00467230-0x004672b7.ApplicationScalarDeletingDestructor](by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md) `ScalarDeletingDestructor`; [UID:000326][0x004671de-0x004671e6.ApplicationScalarDeletingDestructorThunk](by-memory/0x004671de-0x004671e6.ApplicationScalarDeletingDestructorThunk.md) is the non-emitting secondary-vftable adjustor thunk into this destructor.
- Related startup helper: [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) at `0x00467410`, likely file-local to `Application.cpp` rather than an `Application` method.
- [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md) `SendShutdownMessage` - constructs the `0x676f6f67` message object and forwards it through `ForwardMessage`.
- [UID:000198][0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener](by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md) `RegisterChangeListener` - parent-attached ChangeMan registration wrapper that forwards through [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md).
- [UID:00019A][0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md) `UnregisterChangeListener` - parent-attached filtered unregister wrapper that forwards through [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md).
- [UID:00019B][0x004f4b70-0x004f4b86.ApplicationForwardMessage](by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md) `ForwardMessage` - parent-attached message dispatch wrapper that forwards through [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md).
- [UID:0002H7][0x004f5fb0-0x004f6490.ApplicationStartup](by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md) `Startup`.
- [UID:0002H8][0x004f6490-0x004f66a5.ApplicationShutdown](by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md) `Shutdown`.

## Fields And Globals

Known layout notes from live IDA and supporting docs:

- total object size around 2676 bytes;
- `LObject` base plus `MSGHandler` subobject;
- `m_hMainWnd` at `0x828`;
- `m_hLoadingDlg` at `0x82c`;
- `m_hShutdownEvent` at `0x83c`;
- active message dispatcher pointer around `0x844`;
- `m_hInstance` around `0x20`;
- OS code/string fields around `0x10` and `0x854`.
- CPU processor-name string owner around `0x1c`, populated from `HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\ProcessorNameString`; the live copy accessor reads the concrete wide buffer at `Application + 0x428`, so the final `Application` string layout still needs reconciliation.
- license/version-check fields at `0x842` and `0x850`: current IDA evidence shows `0x842` receives `LOWORD(VS_FIXEDFILEINFO.dwFileVersionLS)` and `0x850` receives a license/version-validation status code.

Important globals include `g_pApplication`, `g_appState`, `g_appErrorState`, `g_defaultScreenWidth`, `g_defaultScreenHeight`, `g_hGameModule`, shutdown-object globals, and many subsystem singleton pointers created or destroyed through this class.

## Evidence

- IDA MCP confirms key function boundaries: `0x00463310-0x0046396e`, `0x004639d0-0x00464a52`, `0x00464cd0-0x00464e1f`, `0x004f5fb0-0x004f6490`, and `0x004f6490-0x004f66a5`.
- IDA MCP shows `Startup` calls the image-library and UI singleton constructors already documented in render and UI docs.
- IDA MCP shows `Initialize` calls [UID:00000W][BlackHole](by-class/BlackHole.md) construction at `0x00464549`, and cleanup drains/destroys [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md).
- IDA MCP shows `Initialize` calls [UID:00001K][ChangeMan](by-class/ChangeMan.md) construction at `0x004644c1`; message wrapper methods later read `g_pChangeMan`.
- Existing IDA MCP evidence on the exact wrapper pages confirms `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` as `Application` methods over [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md). The current `82/88` class score clears the 80/80 parent gate, so those three method pages are now attached at positions `145`, `146`, and `147`.
- IDA MCP shows `Initialize` calls [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) construction at `0x00463e3a`, [UID:00003A][Crasher](by-class/Crasher.md) construction at `0x004646ec`, and cleanup touches [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md) / [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) at `0x00464c4e` / `0x00464c5e`.
- IDA MCP shows `Initialize` calls [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) construction at `0x00464715`; cleanup later destroys [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) at `0x00464a88`.
- IDA MCP on 2026-05-25 shows [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md) is called only by `Initialize`, formats numbered `*.DAT` paths, and calls [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) for each existing file.
- IDA MCP on 2026-06-05 refreshed the small accessors and helpers at `0x00464f40`, `0x004651c0`, `0x004651d0`, `0x004651e0`, `0x004651f0`, `0x004652e0`, `0x00465320`, and `0x00465430`, adding current caller evidence and clearing below-threshold final C++ from the tiny getters.
- IDA MCP on 2026-05-31 split the previously missing local Application gap at `0x00465120-0x00465424`: OS-code accessor, processor-name registry reader, executable-path version-info helper, processor-name copy accessor, and executable version low-word helper. The same pass showed `ValidateLicense` writes the `0x842` / `0x850` fields, making the old version-major/minor labels provisional; the 2026-06-06 A009 refresh of `CopyProcessorName` corrected the concrete processor-name copy source to `Application + 0x428`.
- IDA MCP disassembly/string reads on 2026-05-25 resolve the fixed and looped [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md) names loaded by the constructor and `Initialize`.
- Application startup evidence includes `Patch\Info`, `Patch\Script`, `DirectDrawCreate`, `MsgWaitForMultipleObjects`, and license key `7TK5E-KRU-2K`; patch UI/download implementation belongs in [UID:0000MH][PatchPane](by-file/PatchPane.md).
- 2026-06-10 B001-014 IDA MCP split of [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) confirms the class-owned scalar deleting destructor at `0x00467230-0x004672b7`: the body writes Application vtables `0x006125e4`/`0x00612604`, closes the Application handle at `this+0x24`, destroys subobjects at `+0x854`, `+0x1c`, and `+4`, clears [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md) at `0x00467276`, and conditionally frees a `0xa74`-byte object. The adjacent `0x004671de-0x004671e6` thunk adjusts `ecx` by four bytes and tail-jumps into the same destructor.

## Open Questions

- Confirm whether `WinMain`, `BaramApp`, and `MSGHandler` should all be one `Application.cpp` or split into `WinMain.cpp`, `BaramApp.cpp`, and `MSGHandler.cpp`.
- Review the older import/IDA mismatch around `BaramApp::BaramApp` at `0x004f5f20` before using that address as a firm function start.
- Keep [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) and [UID:00003A][Crasher](by-class/Crasher.md) as startup-owned dependencies, not as members of the final `Application.cpp` source file, unless later source-order evidence proves they were private helper classes.
- Keep [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) near this application startup module, but do not promote it to an `Application` member unless later evidence finds a hidden `this` dependency.

## Cross-References

- File: [UID:0000HG][Application](by-file/Application.md)
- Related classes: [UID:00000V][BaramApp](by-class/BaramApp.md), [UID:00008S][MSGHandler](by-class/MSGHandler.md), [UID:00001K][ChangeMan](by-class/ChangeMan.md), [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md), [UID:00000W][BlackHole](by-class/BlackHole.md), [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md), [UID:00003A][Crasher](by-class/Crasher.md), [UID:00006J][InputMan](by-class/InputMan.md), [UID:00006C][IdleWatcher](by-class/IdleWatcher.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Resource: [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md)
- Destructor children: [UID:000323][0x00467230-0x004672b7.ApplicationScalarDeletingDestructor](by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md), [UID:000326][0x004671de-0x004671e6.ApplicationScalarDeletingDestructorThunk](by-memory/0x004671de-0x004671e6.ApplicationScalarDeletingDestructorThunk.md)
- Memory: [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md), [UID:0002JV][0x00465120-0x00465124.ApplicationGetOsCode](by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md), [UID:0002JW][0x00465130-0x004651b8.ApplicationReadProcessorName](by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md), [UID:0002JX][0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo](by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md), [UID:0002JY][0x004652e0-0x004652fc.ApplicationCopyProcessorName](by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md), [UID:0002JZ][0x00465320-0x00465424.GetExecutableVersionLowWord](by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md), [UID:0002GM][0x004651c0-0x004651c4.ApplicationGetInstanceHandle](by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md), [UID:0002GN][0x004651d0-0x004651d7.ApplicationGetMainWindowHandle](by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md), [UID:0002GO][0x004651e0-0x004651e7.ApplicationIsRunning](by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md), [UID:0002GP][0x00465300-0x00465308.ApplicationGetVersionMajor](by-memory/0x00465300-0x00465308.ApplicationGetVersionMajor.md), [UID:0002GQ][0x00465310-0x00465318.ApplicationGetVersionMinor](by-memory/0x00465310-0x00465318.ApplicationGetVersionMinor.md), [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md), [UID:0002GS][0x00465690-0x0046572d.ApplicationMapFromScreen](by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md), [UID:0002GT][0x00465730-0x004657cd.ApplicationMapToScreen](by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md), [UID:0002GU][0x00465b70-0x00465b89.ApplicationCopyWorldName](by-memory/0x00465b70-0x00465b89.ApplicationCopyWorldName.md), [UID:0002GV][0x00465b90-0x00465bac.ApplicationCopyPlayerName](by-memory/0x00465b90-0x00465bac.ApplicationCopyPlayerName.md), [UID:0002GW][0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog](by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md), [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md), [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md), [UID:000198][0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener](by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md), [UID:00019A][0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md), [UID:000199][0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md), [UID:00019B][0x004f4b70-0x004f4b86.ApplicationForwardMessage](by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md), [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md), [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md), [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md), [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md), [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md), [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)

## Changes

- 2026-06-10 B001-014 destructor split:
  - Changed from `82/88` to `85/89`.
  - Added exact Application destructor children [UID:000323][0x00467230-0x004672b7.ApplicationScalarDeletingDestructor](by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md) and [UID:000326][0x004671de-0x004671e6.ApplicationScalarDeletingDestructorThunk](by-memory/0x004671de-0x004671e6.ApplicationScalarDeletingDestructorThunk.md).
  - Evidence: IDA MCP confirms the scalar deleting destructor vtable writes, `g_pApplication` clear, subobject destruction sequence, object size, and secondary-vftable adjustor thunk.

- 2026-06-05 Application helper refresh:
  - What existed before: the class page still carried older provenance wording, raw field-offset phrasing, and stale notes saying small getter pages emitted range-local C++.
  - What changed: raised scores to `82/88`, summarized the refreshed message-loop/request-exit/accessor/version-helper evidence, replaced raw singleton wording with canonical names, and clarified that below-threshold getter C++ is now blank.
  - Summary/evidence: live IDA MCP on 2026-06-05 expanded [UID:0002H2][0x00464cd0-0x00464e1f.ApplicationRunMessageLoop](by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md), [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md), [UID:0002H4][0x00464f40-0x00464f47.ApplicationIsExitRequested](by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md), [UID:0002GM][0x004651c0-0x004651c4.ApplicationGetInstanceHandle](by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md), [UID:0002GN][0x004651d0-0x004651d7.ApplicationGetMainWindowHandle](by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md), [UID:0002GO][0x004651e0-0x004651e7.ApplicationIsRunning](by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md), [UID:0002JX][0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo](by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md), [UID:0002JY][0x004652e0-0x004652fc.ApplicationCopyProcessorName](by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md), [UID:0002JZ][0x00465320-0x00465424.GetExecutableVersionLowWord](by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md), and [UID:0002H6][0x00465430-0x0046564c.ApplicationValidateLicense](by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md).
- 2026-06-06 A004 ChangeMan wrapper parent sync:
  - What existed before: the method list still had raw `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` entries and the exact wrapper pages still referenced the old below-gate parent state.
  - What changed: linked the three exact wrapper method pages, recorded parent positions `145` through `147`, and left final C++ blank under the 95/95 source-code gate.
  - Summary/evidence: the wrapper pages already contain live IDA evidence for the `g_pChangeMan` reads and ChangeMan target calls, and the current class score is `82/88`, above the 80/80 attachment gate.

- 2026-06-06 A009 processor-name layout sync:
  - What existed before: the class page described the processor-name state only as the `0x1c` field and did not mention that the copy accessor reaches the concrete wide buffer at `Application + 0x428`.
  - What changed: clarified the method list and field notes so `ReadProcessorName` remains the registry/string-owner writer candidate while `CopyProcessorName` is the copy-side accessor for the `+0x428` buffer; scores were left unchanged because final `Application` string layout is still open.
  - Summary/evidence: [UID:0002JY][0x004652e0-0x004652fc.ApplicationCopyProcessorName](by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md) now records the 2026-06-06 live IDA `lea eax,[ecx+428h]` evidence, `_wcscpy_s` callee, caller xref, and padding bytes.

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
