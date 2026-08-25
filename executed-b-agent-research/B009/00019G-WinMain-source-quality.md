** TARGET-REPORT-UID:00019G **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B009 Report - [UID:00019G] WinMain Source Quality

Report status: `FINISHED_IMPLEMENTATION`

Agent: B009
Assignment id: `B009-rework-report-00019G-winmain-source-quality-20260626`
Target: [UID:00019G] `by-memory/0x004f5c80-0x004f5f17.WinMain.md`
Mode: report-only rework after supervisor rejection; no by-* files, generated/project-level files, IDA DB state, validator state, or coverage reports were edited.

## Current Target State

Target metadata at rework start:

| Field | Current value |
| --- | --- |
| UID | `00019G` |
| Completion | `86` |
| Confidence | `90` |
| Canonical owner | `0000PA` / [UID:0000PA][WinMain](../../../../../by-file/WinMain.md) |
| Reconstructable | `TRUE` |
| Emitter UIDs | `0000PA` |
| Formal C++ | blank |

Supervisor rejection was valid. The earlier B009 report incorrectly modeled the `0x004f5e95-0x004f5f16` EH/message tail as `StartupWindow` virtual accessors. Current MCP and Error hierarchy docs prove that tail is a `catch (Error *error)` handler: its EH type descriptor is `??_R0PAVError@@@8`, its catch object is stored at `[ebp-0x1a94]`, its virtual slot `+0x0c` is the Error hierarchy wide-message output/copy method, and its virtual slot `+0x10` is the common `Error::GetErrorName`/descriptor slot.

This rework therefore resolves the in-range tail by expressing it as source-level `catch (Error *error)` handling, not as StartupWindow virtual failure accessors and not as an omitted compiler-only body.

## MCP Availability And Session

IDA MCP was available and responsive throughout this rework.

Live session used:

- IDB session: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- MCP-reported input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- Worker PID: `26892`
- `server_health`: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`.

MCP tools used in this rework:

- `server_health`, `idb_list`, `tools/list`
- `lookup_funcs`
- `decompile`
- `disasm`
- `xrefs_to`
- `imports_query`
- `entity_query`
- `get_bytes`

No MCP write tools or IDA DB edits were used.

## Positive Evidence

### Function Boundary And Product Caller

`lookup_funcs` confirms `_WinMain@16` at `0x004f5c80`, size `0x297`, with exclusive end `0x004f5f17`. `lookup_funcs 0x004f5e95` still resolves inside `_WinMain@16`, proving the EH/message tail is part of this target's range. `_WinMain@16_SEH` at `0x00600fef` is also reported under the same function by IDA's function model.

Existing target evidence remains valid:

- Sole direct caller is CRT startup `?__scrt_common_main_seh@@YAHXZ` at `0x005c85bb`.
- `0x004f5f17-0x004f5f20` is post-function padding/alignment, with [UID:00019H] beginning after the target.
- The body is product startup logic, not CRT glue: it stack-constructs the app shell, starts the minimap hash cache, runs the startup/update window, launches the updater when requested, otherwise enters the normal lifecycle, and runs cleanup/error reporting.

### BaramApp/Application Stack Object

Disassembly confirms:

- `0x004f5cbf` pushes the `NexusTK` title fragment and `0x004f5cc4` pushes the `Nexon` publisher fragment before `Application__Constructor` at `0x004f5cca`.
- `0x004f5ccf` and `0x004f5cd9` write the `BaramApp` primary and secondary vtables into the stack object.
- The correct source shape remains a stack `BaramApp app(...)`, not source that manually assigns vtables.

The exact historical constructor parameter names are still inferred, but the order is now documented from the push/decompile order: hInstance, publisher/company string, then application title string. A first-draft source block should use named constants and preserve that order.

### MiniMapVersionManager Warmup

Disassembly/decompile confirms:

- `0x004f5ce3-0x004f5d04`: allocate `0x68` bytes and call `sub_4563C0`, the `MiniMapVersionManager` constructor.
- `0x004f5d09`: read `g_pMiniMapVersionManager` / `dword_67A7DC`.
- `0x004f5d13`: call `MiniMapVersionManager::LoadHashFile` / `sub_456540`.

Source shape: `new MiniMapVersionManager; g_pMiniMapVersionManager->LoadHashFile();`. WinMain owns the order, not the manager internals.

### StartupWindow Result Flow

Disassembly confirms:

- `0x004f5d18-0x004f5d3f`: allocate `0x58` bytes and construct `StartupWindow`.
- `0x004f5d45-0x004f5d57`: pass the local out byte to `StartupWindow::RunUpdateCheck` and save its integer return in `edi`.
- `0x004f5d5d-0x004f5d63`: delete the `StartupWindow` object through vtable slot zero after `RunUpdateCheck`.
- `0x004f5d65-0x004f5d6c`: if the out byte is `1`, take the updater path.
- `0x004f5e69-0x004f5e6c`: if the return is `2`, take early-exit cleanup instead of normal startup.

Resolved first-draft names:

- Local out byte: `shouldRunUpdater`.
- Return value: `startupResult`.
- Out-byte value `1`: `StartupWindow::kRunUpdater`.
- Return value `2`: `StartupWindow::kAbortStartup`.

These names are inferred but source-facing, behavior-based, and sufficient for first-draft C++. They should be documented as provisional StartupWindow result constants rather than left as raw numeric literals.

### Update Prompt And Updater Launch

MCP disassembly confirms the updater branch:

- `0x004f5d72`: pushes `0x40`, i.e. `MB_ICONINFORMATION` with implicit `MB_OK`.
- `0x004f5d74`: prompt caption from `0x0061d15c`, the `Nexus TK update needed` title area documented by [UID:0003P3].
- `0x004f5d79`: prompt text from `0x0061d190`, the "There is a newer version..." message documented by [UID:0003P3].
- `0x004f5d86-0x004f5d92`: calls the dispatch pointer at `0x0069be70` with count `0x104` and a local buffer.
- `0x004f5dab`: assigns that local buffer to `SHELLEXECUTEINFOA.lpDirectory`.
- `0x004f5df8`: assigns narrow string `NexusUpdater.exe` from `0x0061d220`.
- `0x004f5e0c`: assigns `nShow = 1` / `SW_SHOWNORMAL`.
- `0x004f5e16`: calls imported `ShellExecuteExA`.

The `0x0069be70` route is now resolved enough for source draft:

- `imports_query '*GetCurrentDirectory*'` reports both `GetCurrentDirectoryA` at `0x0060d1a4` and `GetCurrentDirectoryW` at `0x0060d26c`.
- `disasm 0x0041a360` shows `0x0041a389: mov eax, ds:GetCurrentDirectoryW` followed by `0x0041a38e: mov dword ptr unk_69BE70, eax`.
- `xrefs_to 0x0069be70` reports the initializer write at `0x0041a38e`, the WinMain read at `0x004f5d92`, and additional wide-path consumers.
- `xrefs_to 0x0060d33c` confirms WinMain calls `ShellExecuteExA` at `0x004f5e16`.

Therefore the correct target documentation must not rename the slot to `GetCurrentDirectoryA`. The formal C++ should preserve the observed PlatformApi wide dispatch slot and the observed ANSI ShellExecute call. For first-draft source, this is best represented as `g_pfnGetCurrentDirectoryW(MAX_PATH, currentDirectory);` followed by `ShellExecuteExA`, with an explicit cast/compatibility note because the binary really feeds the W-dispatch buffer through the A shell structure.

This A/W mismatch should cap final-source confidence but no longer blocks the first-draft WinMain block.

### Early-Exit Cleanup

Both the updater branch and `startupResult == StartupWindow::kAbortStartup` branch converge at `0x004f5e1c`:

- `0x004f5e1c-0x004f5e31`: if `g_pDATFileMgr` / `0x0067ab40` is non-null, call its deleting destructor through vtable slot zero with flag `1`.
- `0x004f5e33-0x004f5e39`: call `Application::RequestExit` / `sub_464E40` through `g_pApplication` / `0x0067ab1c`.
- `0x004f5e3e-0x004f5e44`: destroy the stack application object.

Source shape: delete the DAT file manager singleton if live, then request application exit, then fall through to normal stack-object destruction.

### EH/Message Tail: Correct Error Hierarchy Interpretation

The supervisor rejection centered on `0x004f5e95-0x004f5f16`. Current rework resolves it:

Observed tail instructions:

- `0x004f5e95`: loads `esi = [ebp+var_1A94]`.
- `0x004f5e9b-0x004f5eab`: calls virtual slot `+0x0c` with a `WCHAR Text` buffer and count `0x800`.
- `0x004f5eae-0x004f5ec0`: calls `Application::GetMainWindowHandle` and hides the main window with `ShowWindow(hwnd, SW_HIDE)` if it exists.
- `0x004f5ec6-0x004f5ed7`: if `g_pScreenPane` / `dword_67A7CC` is live, calls [UID:00039R] `SurfaceDirectDrawRestoreMaintenance`.
- `0x004f5edc-0x004f5eeb`: if `g_pKeySpeedMgr` / `0x0067ab48` is live, calls `KeySpeedMgr::RestoreSystemKeyboardSettings`, then [UID:00032A] `DestroyKeySpeedMgr`.
- `0x004f5ef0-0x004f5ef6`: calls virtual slot `+0x10` with pushed zero and uses the return as the `MessageBoxW` caption.
- `0x004f5f03`: calls `MessageBoxW`.
- `0x004f5f09-0x004f5f0f`: deletes the caught object through virtual slot zero with flag `1`.
- `0x004f5f11-0x004f5f16`: returns the continuation `loc_4F5E3E`, the same stack-application destructor tail.

EH metadata proof:

- `xrefs_to 0x004f5e95` reports a data xref from `0x0065efd4`.
- `get_bytes 0x0065efd0 size 40` shows the handler record: `0x00674544`, displacement `0xffffe56c`, handler `0x004f5e95`, and state data.
- `entity_query 0x00674500-0x00674590` names `0x00674544` as `??_R0PAVError@@@8`.
- `xrefs_to 0x00674544` reports the WinMain handler record at `0x0065efd4` plus other Error pointer EH uses.
- `xrefs_to 0x0065f040` reports `_WinMain@16_SEH` at `0x0060100d` loading WinMain's EH FuncInfo.

Error hierarchy slot proof:

- [UID:0001XI] maps the Error hierarchy five-slot interface: slot `+0x0c` is message-output/copy/format into a caller buffer; slot `+0x10` is the common error name/descriptor slot.
- [UID:00013Z] documents an exact stored-message `+0x0c` implementation that copies with `_wcscpy_s`.
- `lookup_funcs 0x004a6840` reports `sub_4A6840`, size `0x18`; `decompile 0x004a6840` returns `_wcscpy_s(Destination, SizeInWords, this[1])`, the heap-message implementation used by `MyError` and `PasswordError`.
- `xrefs_to 0x004a6840` reports vtable data refs at `0x006125b4` and `0x00619440`.
- `lookup_funcs 0x004a6a70` reports the common name helper, size `0x6`; `xrefs_to 0x004a6a70` reports 11 Error hierarchy vtable name-slot refs.
- `entity_query '*StartupWindow*'` in the `0x00620000-0x00630000` range reports only the `StartupWindow` vtable at `0x0062d470`; existing [UID:00026K] documents it as a destructor-only vtable. It does not have slot `+0x0c`/`+0x10` message methods.

Resolved source shape:

- The handler is `catch (Error *error)`, not `catch (...)` over StartupWindow.
- `error->CopyErrorMessage(...)` / `error->FormatErrorMessage(...)` is the slot `+0x0c` role. This report recommends `CopyErrorMessage` in the WinMain block because the handler copies text into an existing local buffer and discards the integer status.
- `error->GetErrorName()` is the slot `+0x10` role.
- The caught pointer is deleted after the message box.
- The compiler EH funclets and FuncInfo are not separate handwritten source, but the source-level catch body is in-range behavior that must be represented in [UID:00019G]'s formal C++.

## Negative Evidence And Rejected Alternatives

| Alternative | Decision | Evidence |
| --- | --- | --- |
| Treat `_WinMain@16` as CRT/runtime glue | Rejected | Sole caller is CRT startup, but body is product startup: BaramApp/Application, MiniMapVersionManager, StartupWindow, updater, message loop, shutdown, Error catch. |
| Keep formal C++ blank because the EH tail is compiler-shaped | Rejected | EH metadata and tail disassembly prove a source-level `catch (Error *error)` body. Compiler tables/funclets are not emitted, but the catch behavior must be represented. |
| Model the tail as `StartupWindow::GetFailureMessage` / `GetFailureCaption` | Rejected | EH type descriptor is `PAVError`, catch object displacement is `[ebp-0x1a94]`, StartupWindow vtable only has destructor evidence, and Error hierarchy slot map exactly matches `+0x0c`/`+0x10`. |
| Use `GetCurrentDirectoryA` for `0x0069be70` | Rejected | Initializer writes `GetCurrentDirectoryW` to `0x0069be70`; `GetCurrentDirectoryA` exists elsewhere but is not the dispatch slot read by WinMain. |
| Hide the A/W launch mismatch by using generic `ShellExecuteEx`/`GetCurrentDirectory` macros | Rejected for this exact target | The binary calls the W dispatch slot and imported `ShellExecuteExA`; the formal first draft should preserve the mismatch with explicit source-facing names/cast and document the caveat. |
| Leave startup result constants as raw `1` and `2` | Rejected | Current control flow supports inferred source constants `kRunUpdater` and `kAbortStartup`; exact spelling is final-audit-only. |
| Invent helper functions for updater launch, early-exit cleanup, or error cleanup | Rejected | The binary does not prove separate original helpers inside this range. Source may inline these blocks in WinMain. |
| Fold adjacent `Application::Startup` / `Application::Shutdown` methods into WinMain | Rejected | They are called methods with separate pages/owners. WinMain owns only orchestration. |

## Heuristic / Inference Reanalysis

Recommended source-facing names and roles:

| Binary/decompiler artifact | Recommended source-facing role |
| --- | --- |
| `_WinMain@16` / `WinMain_wrapper` | `WinMain` |
| Stack object plus BaramApp vtable stores | `BaramApp app` |
| `aNe` / `0x0061d150` | `kPublisherName` / `L"Nexon"` |
| `aNe_0` / `0x0061d140` | `kApplicationTitle` / `L"NexusTK"` |
| StartupWindow out byte | `shouldRunUpdater` |
| Out byte value `1` | `StartupWindow::kRunUpdater` |
| `RunUpdateCheck` return in `edi` | `startupResult` |
| Return value `2` | `StartupWindow::kAbortStartup` |
| `0x0061d15c` | `kUpdateRequiredTitle` |
| `0x0061d190` | `kUpdateRequiredMessage` |
| `0x0061d220` | `kNexusUpdaterExecutable` |
| `0x0069be70` | `g_pfnGetCurrentDirectoryW` / PlatformApi current-directory dispatch |
| `SHELLEXECUTEINFOA` local | `executeInfo` |
| EH handler type `??_R0PAVError@@@8` | `catch (Error *error)` |
| Error slot `+0x0c` | `Error::CopyErrorMessage` / hierarchy message-output virtual |
| Error slot `+0x10` | `Error::GetErrorName` |
| `sub_4651D0` | `Application::GetMainWindowHandle` |
| `sub_5576A0` | `ScreenPane::RestoreDirectDrawState` / SurfaceDirectDraw restore maintenance |
| `sub_4EFF30` | `KeySpeedMgr::RestoreSystemKeyboardSettings` |
| `sub_4673C0` | `DestroyKeySpeedMgr` |
| `sub_464E40` | `Application::RequestExit` |

This is enough for first-draft C++. Remaining uncertainty is now final-source polish, not a blocker:

- exact string constant spelling;
- exact StartupWindow enum/constant names;
- final shared Error hierarchy virtual name (`CopyErrorMessage` versus `FormatErrorMessage`);
- final PlatformApi typedef spelling for the dispatch slot;
- exact historical file name (`WinMain.cpp` remains best current source route).

## Source Placement And Ownership

Ranked placement:

1. [UID:0000PA][WinMain](../../../../../by-file/WinMain.md) / `NexusTK/app/WinMain.cpp` - selected.
   - For: exact product entry function, existing owner/emitter route, sole CRT caller, direct top-level orchestration responsibility, and all target behavior is inside `_WinMain@16`.
   - Against: exact historical filename may have been `Main.cpp` or folded into an Application source file. This remains a confidence cap, not an ownership blocker.
2. [UID:0000HG][Application](../../../../../by-file/Application.md) - rejected as direct owner for this function.
   - For: WinMain constructs and drives Application/BaramApp lifecycle.
   - Against: Application owns the methods; WinMain owns the process entry orchestration.
3. [UID:0000O5][StartupWindow](../../../../../by-file/StartupWindow.md) - rejected as direct owner.
   - For: update window controls the updater/abort decisions.
   - Against: StartupWindow is a helper object used by WinMain; the EH tail is Error hierarchy handling, not StartupWindow methods.
4. [UID:0000J5][Error](../../../../../by-file/Error.md) - support owner only.
   - For: the EH tail catches `Error *` and calls Error virtual slots.
   - Against: the Error class owns the caught object's implementation, not WinMain's catch policy.
5. [UID:0000ML][PlatformApi](../../../../../by-file/PlatformApi.md) - support owner only.
   - For: owns `g_pfnGetCurrentDirectoryW`.
   - Against: WinMain is only a consumer of the dispatch slot.

Recommended target metadata:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `90` |
| `CONFIDENCE` | `92` |
| `CANONICAL_OWNER` | `0000PA` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000PA` |
| Formal C++ | nonblank first draft, exact block below |

Reason not higher than `90/92`:

- final historical filename is still inferred;
- final StartupWindow enum/constant names are inferred;
- final Error hierarchy message-output virtual name is not project-wide standardized;
- WinMain exposes a real PlatformApi W-dispatch / `ShellExecuteExA` mismatch that must remain documented until final source style decides how to express it globally;
- string constant names are source-facing inferences;
- the block is first-draft source-quality, not final 95/95 audit-quality code.

Reason not lower:

- live MCP rechecked boundary, caller, disassembly, decompile, imports, dispatch initializer, EH metadata, Error type descriptor, Error virtual slots, updater launch, cleanup paths, and supporting docs.
- the previous formal C++ blocker is now resolved with a source-level `catch (Error *error)` body and a source-level dispatch-slot caveat.

## Recommended Formal C++ For Target

Destination: [UID:00019G] `by-memory/0x004f5c80-0x004f5f17.WinMain.md`

Replace the blank formal `RECONSTRUCTION_CPP CODE` block with exactly this formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    BaramApp app(hInstance, kPublisherName, kApplicationTitle);

    try {
        new MiniMapVersionManager;
        g_pMiniMapVersionManager->LoadHashFile();

        bool shouldRunUpdater = false;
        int startupResult = StartupWindow::kAbortStartup;

        StartupWindow *startupWindow = new StartupWindow(hInstance);
        startupResult = startupWindow->RunUpdateCheck(&shouldRunUpdater);
        delete startupWindow;

        if (shouldRunUpdater == StartupWindow::kRunUpdater) {
            MessageBoxW(NULL, kUpdateRequiredMessage, kUpdateRequiredTitle, MB_ICONINFORMATION);

            WCHAR currentDirectory[MAX_PATH];
            g_pfnGetCurrentDirectoryW(MAX_PATH, currentDirectory);

            SHELLEXECUTEINFOA executeInfo = {};
            executeInfo.cbSize = sizeof(executeInfo);
            executeInfo.lpFile = kNexusUpdaterExecutable;
            executeInfo.lpDirectory = reinterpret_cast<LPCSTR>(currentDirectory);
            executeInfo.nShow = SW_SHOWNORMAL;

            ShellExecuteExA(&executeInfo);
        } else if (startupResult != StartupWindow::kAbortStartup) {
            app.Startup();
            app.RunMessageLoop();
            app.Shutdown();
            return 0;
        }

        if (g_pDATFileMgr != NULL) {
            delete g_pDATFileMgr;
        }

        app.RequestExit();
    } catch (Error *error) {
        WCHAR messageText[0x800];

        error->CopyErrorMessage(messageText, _countof(messageText));

        HWND mainWindow = app.GetMainWindowHandle();
        if (mainWindow != NULL) {
            ShowWindow(mainWindow, SW_HIDE);
        }

        if (g_pScreenPane != NULL) {
            g_pScreenPane->RestoreDirectDrawState();
        }

        if (g_pKeySpeedMgr != NULL) {
            g_pKeySpeedMgr->RestoreSystemKeyboardSettings();
            DestroyKeySpeedMgr();
        }

        MessageBoxW(NULL, messageText, error->GetErrorName(), MB_OK);
        delete error;
    }

    return 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation notes for supervisor validation:

- `kPublisherName` maps to `Nexon`; `kApplicationTitle` maps to `NexusTK`. The order follows the WinMain decompile/push order for `Application__Constructor`.
- `kUpdateRequiredTitle`, `kUpdateRequiredMessage`, and `kNexusUpdaterExecutable` come from [UID:0003P3].
- `StartupWindow::kRunUpdater` and `StartupWindow::kAbortStartup` are first-draft inferred constants for the observed `1` and `2`.
- `g_pfnGetCurrentDirectoryW` is intentionally the PlatformApi W dispatch slot at `0x0069be70`; the `reinterpret_cast<LPCSTR>` is intentionally documenting the observed binary mismatch with `ShellExecuteExA`, not an idealized API pairing.
- `Error::CopyErrorMessage` is the best local source-facing name for the Error hierarchy `+0x0c` message-output virtual in this catch body. If the project standardizes the hierarchy on `FormatErrorMessage`, replace the spelling consistently in Error docs and this block during implementation.
- The MSVC EH tables/funclets themselves should not be emitted as separate source. The `catch (Error *error)` block is the by-structure-safe source representation of the in-range handler.

## Support Documentation Recommendations

### `by-memory/0x004f5c80-0x004f5f17.WinMain.md`

Required if supervisor accepts:

- Raise metadata to `COMPLETION:90`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000PA`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000PA`.
- Insert the exact formal C++ block above.
- Replace the stale tail wording that says the handler calls StartupWindow virtual slots.
- Add the current MCP session `80de0a67` evidence:
  - active/healthy MCP details;
  - boundary/caller/callee/decompile/disassembly proof;
  - `0x0069be70` import/initializer route to `GetCurrentDirectoryW`;
  - `ShellExecuteExA` import/use;
  - EH metadata `0x0065efd4` -> `??_R0PAVError@@@8` -> handler `0x004f5e95`;
  - Error slot `+0x0c`/`+0x10` role proof;
  - StartupWindow result value names.
- Update score rationale to explain first-draft C++ readiness and final-audit caveats.

### `by-file/WinMain.md`

Required support sync:

- Raise from `86/86` to `89/88`.
- Add that [UID:00019G] now has an accepted first-draft formal block if supervisor validates this report.
- Add that the in-range EH/message tail is a source-level `catch (Error *error)` handler, not StartupWindow virtual accessors and not padding.
- Add that WinMain consumes the PlatformApi `g_pfnGetCurrentDirectoryW` slot before an ANSI `ShellExecuteExA` updater launch; keep the mismatch as a target caveat.
- Keep proposed path `NexusTK/app/`.

### `by-file/StartupWindow.md` and/or `by-class/StartupWindow.md`

Required support sync, no score change required:

- Add result-flow constants inferred from WinMain:
  - out-byte `1` -> run updater / `kRunUpdater`;
  - `RunUpdateCheck` return `2` -> abort startup / `kAbortStartup`.
- Add a corrective note that WinMain's `0x004f5e95` EH handler does not prove StartupWindow failure-message virtuals; current EH metadata proves `Error *` handling instead.
- Do not move the EH tail into StartupWindow ownership.

### `by-type/by-vtable/ErrorHierarchyVtables.md`, `by-class/Error.md`, and/or `by-file/Error.md`

Required support sync, no score change required:

- Add WinMain as a current `catch (Error *error)` consumer of the Error virtual interface:
  - EH handler record at `0x0065efd4`;
  - type descriptor `0x00674544` / `??_R0PAVError@@@8`;
  - handler at `0x004f5e95`;
  - slot `+0x0c` copies/formats wide text into a caller buffer;
  - slot `+0x10` supplies the message-box caption/name;
  - vtable slot zero deletes the caught pointer after display.
- If the project standardizes `CopyErrorMessage` versus `FormatErrorMessage`, reflect that spelling here and in the WinMain block.

### `by-global/WideApiDispatchTable.md`

Required support sync, no score change required:

- Add WinMain as a concrete `0x0069be70` consumer at `0x004f5d92`.
- Preserve the installed target as `GetCurrentDirectoryW`; do not rename to `GetCurrentDirectoryA`.
- Record the target-specific caveat that WinMain immediately feeds the resulting buffer into `SHELLEXECUTEINFOA.lpDirectory` and calls `ShellExecuteExA`.

### `by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md`

Optional support sync, no score change required:

- Add/update the item summary if desired; it is currently blank.
- If implementation names string constants on [UID:00019G], record the mappings:
  - `kPublisherName` = `Nexon`;
  - `kApplicationTitle` = `NexusTK`;
  - `kUpdateRequiredTitle` = `Nexus TK update needed`;
  - `kUpdateRequiredMessage` = the newer-version prompt;
  - `kNexusUpdaterExecutable` = `NexusUpdater.exe`.

### Support docs checked with no direct edit required

- [UID:00000D][Application](../../../../../by-class/Application.md): already owns `GetMainWindowHandle`, lifecycle methods, and `RequestExit`.
- [UID:00000V][BaramApp](../../../../../by-class/BaramApp.md): already documents vtable/write evidence and startup string area.
- [UID:0000XP][MiniMapVersionManager aggregate](../../../../../by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md): already documents the WinMain construction/load call path.
- [UID:00039R][SurfaceDirectDrawRestoreMaintenance](../../../../../by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md): already documents WinMain caller/restore role.
- [UID:00032A][DestroyKeySpeedMgr](../../../../../by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md): already documents the WinMain early-exit caller.

## Open Questions With Attempted Resolution

| Question | Resolution for this pass |
| --- | --- |
| Should the EH/message tail be omitted as compiler-generated? | No. Compiler EH tables/funclets are generated, but the handler body at `0x004f5e95` is source-level catch behavior and is represented as `catch (Error *error)`. |
| Is the EH tail StartupWindow-owned? | No. `??_R0PAVError@@@8` EH metadata and Error vtable slot map reject the StartupWindow interpretation. |
| Can first-draft C++ use `GetCurrentDirectoryA`? | No. The slot at `0x0069be70` is initialized from `GetCurrentDirectoryW`. The formal block preserves W dispatch and documents the A shell-call mismatch. |
| Are `kRunUpdater`, `kAbortStartup`, and string constant names exact originals? | Not proven, but they are high-probability source-facing names inferred from control flow and literal roles. They are acceptable for first draft and should cap final audit, not block code. |
| Is `CopyErrorMessage` the final Error virtual name? | Not proven. It is the best local WinMain spelling for a buffer-copy handler. `FormatErrorMessage` remains a valid project-wide alternative if standardized consistently. |
| Does target score exceed 95 after this work? | No. First-draft C++ and source-quality route are now strong, but final original naming/style is still inferred. Keep below the 95+ final-audit barrier. |

## Implementation Tracking Checklist

Implementation callback completed by B009 on 2026-06-26. B009 edited the accepted target/support by-* docs only; no generated/project-level file, validator/tool state file, IDA DB, or `-coverage-report.md` file was manually edited. Validator commands refreshed tool-owned state as normal.

Lease proof:

- Lease command from `source-3/project-documentation`: `python .\tools\leaser\leaser.py B009 lease by-memory\0x004f5c80-0x004f5f17.WinMain.md by-file\WinMain.md by-file\StartupWindow.md by-class\StartupWindow.md by-type\by-vtable\ErrorHierarchyVtables.md by-class\Error.md by-file\Error.md by-global\WideApiDispatchTable.md by-memory\0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md`
- Lease command result: `Success` for all nine files.
- Cleanup command from `source-3/project-documentation`: `python .\tools\leaser\leaser.py B009 unlease ...` for the same nine paths.
- Cleanup result: each path reported `Rejected[No active lease]`, and `tools/leaser/Agents/current_leases.md` immediately afterward contained `No active leases.` No B009 lease rows remained.

Checked implementation items:

- [x] Supervisor validated this revised report, including the Error-pointer EH correction, PlatformApi W-dispatch route, and formal C++ block.
  - Proof: supervisor acceptance callback was written to `Agent-B009/goal.md` before this implementation pass.
- [x] Update `by-memory/0x004f5c80-0x004f5f17.WinMain.md` metadata to `COMPLETION:90`, `CONFIDENCE:92`; keep owner/emitter/reconstructable metadata unchanged.
  - Proof: target header now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000PA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PA`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into `by-memory/0x004f5c80-0x004f5f17.WinMain.md`.
  - Proof: target formal block now contains the accepted `int WINAPI WinMain(...)` body with `BaramApp app`, `StartupWindow::kRunUpdater`, `g_pfnGetCurrentDirectoryW`, `ShellExecuteExA`, and `catch (Error *error)`.
- [x] Update target behavior/evidence sections with MCP session `80de0a67`, boundary/caller/callee proof, updater branch, `0x0069be70` `GetCurrentDirectoryW` initializer route, `ShellExecuteExA` use, and the Error-pointer EH handler evidence.
  - Proof: target sections `IDA MCP Evidence`, `BaramApp, MiniMap, And StartupWindow Flow`, `Updater Prompt And PlatformApi Dispatch`, and `Error Catch Tail` carry the report-level details.
- [x] Remove or supersede any target wording that says `0x004f5e95` calls StartupWindow failure-message/failure-caption virtuals.
  - Proof: target now states the previous StartupWindow-tail interpretation is superseded, and identifies the tail as `catch (Error *error)`.
- [x] Update target score rationale to explain `90/92`, not higher/lower.
  - Proof: target `Score Rationale` section explains `90/92`, final-audit caps, and why the score is not lower.
- [x] Update `by-file/WinMain.md` to `89/88` and add first-draft-C++ readiness, Error catch, and PlatformApi/ShellExecute caveat notes.
  - Proof: `by-file/WinMain.md` header now has `COMPLETION:89`, `CONFIDENCE:88`; `File Role`, `Proposed Contents`, `Boundary Notes`, `Cross-References`, and `Changes` include the accepted B009 details.
- [x] Update `by-file/StartupWindow.md` and `by-class/StartupWindow.md` with `kRunUpdater` / `kAbortStartup` source-facing result constants and a corrective note rejecting StartupWindow ownership of the EH tail.
  - Proof: both docs now describe `StartupWindow::kRunUpdater`, `StartupWindow::kAbortStartup`, and the correction that WinMain's `0x004f5e95` tail is Error-pointer EH handling, not StartupWindow virtual accessors.
- [x] Update `by-type/by-vtable/ErrorHierarchyVtables.md`, `by-class/Error.md`, and `by-file/Error.md` with WinMain's `catch (Error *error)` consumer evidence and the slot `+0x0c`/`+0x10` use.
  - Proof: all three docs now include WinMain EH record `0x0065efd4`, type descriptor `0x00674544` / `??_R0PAVError@@@8`, handler `0x004f5e95`, slot `+0x0c` message-output use, slot `+0x10` name/caption use, and caught-object deletion through slot zero.
- [x] Update `by-global/WideApiDispatchTable.md` with WinMain's `0x0069be70` consumer route and the W-dispatch/A-ShellExecute caveat; do not rename the slot to `GetCurrentDirectoryA`.
  - Proof: the `0x0069be70` row now lists WinMain as a consumer; evidence and changes sections state the slot remains `GetCurrentDirectoryW` and document the `SHELLEXECUTEINFOA` / `ShellExecuteExA` caveat.
- [x] Optionally update `by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md` item summary/string constant mapping.
  - Proof: item summary is now populated, and `Reconstruction Notes` include `kPublisherName`, `kApplicationTitle`, `kUpdateRequiredTitle`, `kUpdateRequiredMessage`, and `kNexusUpdaterExecutable` mappings.
- [x] Do not edit any `-coverage-report.md` as B009. Supervisor owns any coverage report refresh/update.
  - Proof: no `-coverage-report.md` files were edited. Expected by-memory manual row score remains supervisor-owned if a manual row still exists; validator-owned generated reports were not manually edited.
- [x] Validate changed by-* docs from `source-3/project-documentation` with scoped file validation.
  - Proof:
    - `python .\tools\validator.py --mode file --file by-memory/0x004f5c80-0x004f5f17.WinMain.md --apply --queue-timeout 240`
      - `command_id: 000000002543`, `command_timestamp: 2026-06-26T06:47:51-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
      - Revalidated after `0003P3` registry registration: `command_id: 000000002553`, `command_timestamp: 2026-06-26T06:48:37-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-file/WinMain.md --apply --queue-timeout 240`
      - `command_id: 000000002544`, `command_timestamp: 2026-06-26T06:47:53-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
      - Revalidated after `0003P3` registry registration: `command_id: 000000002554`, `command_timestamp: 2026-06-26T06:48:39-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240`
      - `command_id: 000000002545`, `command_timestamp: 2026-06-26T06:47:54-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240`
      - `command_id: 000000002546`, `command_timestamp: 2026-06-26T06:47:56-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-type/by-vtable/ErrorHierarchyVtables.md --apply --queue-timeout 240`
      - `command_id: 000000002547`, `command_timestamp: 2026-06-26T06:47:57-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-class/Error.md --apply --queue-timeout 240`
      - `command_id: 000000002548`, `command_timestamp: 2026-06-26T06:47:59-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-file/Error.md --apply --queue-timeout 240`
      - `command_id: 000000002550`, `command_timestamp: 2026-06-26T06:48:09-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-global/WideApiDispatchTable.md --apply --queue-timeout 240`
      - `command_id: 000000002551`, `command_timestamp: 2026-06-26T06:48:11-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md --apply --queue-timeout 240`
      - `command_id: 000000002552`, `command_timestamp: 2026-06-26T06:48:13-04:00`, exit `0`, `ok: 1`, generated refresh deferred.

Validator diagnostics to report to supervisor:

- Target revalidation `000000002553` still reports pre-existing/stale registry issues: `missing_ref_uid 00039R` for `SurfaceDirectDrawRestoreMaintenance` even though `by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md` exists with UID `00039R`, and `missing_ref_target 0000YR` because validator registry points to stale `by-memory/0x00463310-0x004679be.ApplicationLifecycle.md` while the live file is `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`.
- StartupWindow validation still reports stale `00026K` target path `0x0062d418-0x0062d5ac` while live docs use `0x0062d418-0x0062d5a8`.
- Error hierarchy/Error validation still reports stale `0002ND` target path `0x00619344-0x00619448` while current docs use `0x00619340-0x00619448`.
- These diagnostics did not fail scoped validation (`ok: 1`, exit `0`) and were not repaired by hand because validator/tool registry state is supervisor/tool-owned.

Unchecked blockers: none for accepted implementation. Supervisor still owns post-implementation claim-by-claim verification, any manual coverage report update, and validator `execute_report`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00019G-WinMain-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00019G-WinMain-source-quality.md","timestamp":"2026-06-26T06:52:20","uid":"00019G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
