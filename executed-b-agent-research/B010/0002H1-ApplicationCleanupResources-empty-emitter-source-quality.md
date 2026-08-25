** TARGET-REPORT-UID:0002H1 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002H1] ApplicationCleanupResources Empty Emitter Source-Quality Report

**TARGET UID:** 0002H1  
**TARGET:** `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`  
**AUTHOR AGENT:** Agent-B010  
**ASSIGNMENT:** `B010-report-0002H1-ApplicationCleanupResources-empty-emitter-source-quality-20260628`  
**MODE:** Report-only research first. No by-* files, generated files, project-level files, manual coverage reports, validator/tool state, or IDA database were edited.  
**REPORT STATE:** FINISHED_REPORT

## Recommendation

Keep `ApplicationCleanupResources` as an Application-owned source method and close the empty-emitter defect with first-draft formal C++:

- `CANONICAL_OWNER:00000D` unchanged.
- `EMITTER_UIDS:00000D` unchanged.
- `RECONSTRUCTABLE:TRUE` unchanged.
- Raise the target documentation score from the current by-memory state `COMPLETION:86` / `CONFIDENCE:90` to `COMPLETION:90` / `CONFIDENCE:92`.
- Populate the formal `RECONSTRUCTION_CPP CODE` block for `Application::CleanupResources()`.

This target is not a no-owner, compiler-only, no-code, or aggregate-only range. It is a real Application lifecycle method with a precise function body, a proven `Application::Shutdown` tail-call, Application object field accesses, a vtable/data reference, and source-facing teardown behavior. The empty emitter is stale relative to the current target documentation and current MCP evidence.

The supervisor-rejected blank-C++ blocker list is now resolved enough for implementation. The `g_pConfig` vtable slot `+0x0c` is `RegistryConfig::SaveToRegistry()` through the `RegistryConfig` vtable and should be exposed on the `Config` virtual surface. The cleanup message tag should be emitted as a first-draft integer tag constant for `0x7465726d`, matching the accepted `Application::SendShutdownMessage` style. `ApplicationForwardMessage` already has accepted source-facing call shape through `Message message(...); ForwardMessage(&message);`. `0x0067ab3c` is `CheatDetector *g_pCheatDetector`, not a socket or mouse/controller singleton. The singleton delete surfaces are ordinary `delete g_p...;` statements whose object owners/destructors own global clearing.

## Supervisor Rejection Revision Findings

This revision keeps the earlier owner/range/MCP evidence, but changes the C++ disposition after actively rechecking the named blockers.

Resolved blocker findings:

- `g_pConfig` branch: current docs plus fresh MCP bytes show `RegistryConfig` vtable slots `0x00612614..0x00612624` as deleting destructor, shared support slot, null stub, `0x00491b30`, and `0x004926a0`. `lookup_funcs` resolves `0x00491b30` to the documented `RegistryConfig::SaveToRegistry` child and `0x004926a0` to `RegistryConfig::LoadFromRegistry`; `lookup_funcs 0x005ca28c` resolves the base `Config` tail slots to `__purecall`. The implementation should add `virtual void SaveToRegistry() = 0;` and `virtual bool LoadFromRegistry() = 0;` to `Config`, then write `g_pConfig->SaveToRegistry();` in H1.
- Message tag: `MessageType` is documented as `unsigned int`; `ApplicationSendShutdownMessage` already emits `static const unsigned int kPaneTagGoog = 0x676f6f67;` and `Message message(kPaneTagGoog); ForwardMessage(&message);`. Fresh MCP confirms H1 constructs the stack message with integer `0x7465726d`. `int_convert` reports little-endian bytes `6d 72 65 74` for that integer, so this report does not claim a memory-byte string; the source-facing constant is `static const MessageType kPaneTagTerm = 0x7465726d;`.
- `ApplicationForwardMessage`: the current wrapper page and generated `SendShutdownMessage` body establish the caller shape. H1 should call `ForwardMessage(&message);`; the wrapper page can be updated separately to carry its own simple body over `g_pChangeMan`.
- `0x0067ab3c`: current docs and fresh MCP xrefs identify the slot as `g_pCheatDetector`; the five xrefs are H1 cleanup plus `CheatDetector` constructor publish/null-clear and clear/destructor writes.
- BlackHole cleanup queue: `BlackHole::ReleaseQueuedOwnedObjects()` already emits first-draft source in the exact child page. H1 can call `g_pApplicationCleanupQueue->ReleaseQueuedOwnedObjects();` before deleting the queue.
- `g_pFileDownloader`: the stale `g_pCashShopRequest` filename is not a blocker for H1; current global docs accept `FileDownloader *g_pFileDownloader` as the source-facing declaration.

Remaining caveats are support-document edits, not target no-code blockers: the `Config` and `RegistryConfig` class declarations need the persistence virtuals synchronized, `ApplicationForwardMessage` should have its own first-draft wrapper body, and several global pages still keep declaration/destructor confidence below final audit. Those caveats do not require H1 to remain an empty emitter because the H1 source can use the accepted source-facing calls and ordinary `delete` syntax without inlining subsystem destructors.

## Current Target State

Target file checked:

- `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`

Current target metadata:

- `UID:0002H1`
- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00000D`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`
- Formal C++ block currently blank; this revised report recommends populating it with the first-draft body below.

Generated state checked:

- `auto-generated/NexusTK/app/Application.cpp`
- `auto-generated/-ag-research-tracker.md`

Generated marker state:

- `Application.cpp` still has an empty emitter marker for `UID:0002H1`.
- The generated tracker still reports `82/88` and direct report count `0` for `UID:0002H1`.
- This is stale compared with the current target doc `86/90` and this report's recommended `90/92`; generated outputs should be refreshed only by the validator/supervisor pipeline, not by manual edits.

Prior leads checked and re-evaluated:

- `executed-b-agent-research/B002/0002H0-0002JV-application-lifecycle-source-quality.md`
- `by-file/Application.md`
- `by-class/Application.md`
- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
- `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md`
- `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md`
- `by-class/Message.md`
- `by-memory/0x00520e30-0x00521d94.MessageCore.md`
- `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`
- `by-global/g_pCashShopRequest.md`
- `by-file/FileDownloader.md`
- `by-class/FileDownloader.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-file/Config.md`
- `by-class/Config.md`
- `by-class/RegistryConfig.md`
- `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`
- `by-memory/0x006168d0-0x006168e8.ConfigVtableData.md`
- `by-global/g_pApplicationCleanupQueue.md`
- `by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md`
- `by-global/g_pCheatDetector.md`
- `by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md`
- Representative singleton/global support docs for the teardown targets listed below.

## IDA MCP Status

IDA MCP was mandatory for this report and was available.

Read-only listener and process state observed before MCP calls:

- `127.0.0.1:13337` was listening.
- Listener owner process observed as PID `18824`.
- `idalib-mcp` process observed as PID `9040`, path `C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\idalib-mcp.exe`.
- `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded: True`.

MCP session state:

- `initialize` succeeded for `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `tools/list` succeeded.
- `idb_list` showed active database session `agent_b009_0002my_20260628`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active `true`, worker PID `2412`.
- `server_health` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, imagebase `0x400000`, module `NexusTK.exe`.

Revision MCP recheck:

- This rejection revision repeated a read-only status check. `Get-Process` still showed `idalib-mcp` PID `9040` at `C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\idalib-mcp.exe`.
- `Get-NetTCPConnection -LocalPort 13337` showed a `127.0.0.1:13337` listener owned by PID `18824` plus one transient local connection entry from the probe.
- `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded: True`.
- `initialize` again succeeded for `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `idb_list` again showed active worker session `agent_b009_0002my_20260628`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active `true`, worker PID `2412`.
- `server_health` again returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, imagebase `0x400000`, module `NexusTK.exe`, and strings cache size `2067`.

Read-only MCP calls used after initialization:

- `lookup_funcs`
- `analyze_function`
- `decompile`
- `disasm`
- `callees`
- `xrefs_to`
- `get_bytes`
- `get_global_value`

## MCP Function Evidence

`lookup_funcs`:

- `0x00464a60` resolves to `sub_464A60`.
- `0x00464cc1` is not a function start.
- `0x00464cd0` resolves to the next function, `sub_464CD0`.
- `0x004f6490` resolves to `sub_4F6490` (`ApplicationShutdown`).
- `0x004f66a0` belongs to `sub_4F6490`.

`analyze_function` for `0x00464a60`:

- Raw IDA name: `sub_464A60`.
- Prototype recovered by IDA: `int __thiscall(int this)`.
- Size: `609` bytes, matching `0x261`.
- Basic blocks: `55`.
- Cyclomatic complexity: `25`.

`disasm` for `0x00464a60`:

- Instruction count: `215`.
- Total instructions reported: `215`.
- Tail includes local `Message` destructor call through `sub_520ED0` at `0x00464cac` and a normal epilogue ending at `0x00464cc0`.
- EH cleanup fragment exists outside the source range at `0x005fa827`, where the local `Message` destructor is invoked for unwind cleanup.

`xrefs_to`:

- `0x00464a60` has a code xref from `0x004f66a0` inside `sub_4F6490` (`ApplicationShutdown`), plus a data/vtable reference at `0x006125f4`.
- `0x006125f4` has no separate incoming xrefs in the sampled call.

`get_bytes`:

- `0x00464a52` through `0x00464a5f` is `0xcc` padding before the target.
- `0x00464cc1` through `0x00464ccf` is `0xcc` padding before the successor at `0x00464cd0`.

`callees` for `0x00464a60`:

- `sub_520E30` (`Message` constructor path)
- `sub_4F4B70` (`ApplicationForwardMessage`)
- `ShowCursor`
- `___acrt_iob_func`
- `_fclose`
- `sub_4EFF30` (`KeySpeedMgr` restore path)
- `ShowWindow`
- `MessageBoxW`
- `sub_469200` (`BlackHole` cleanup queue release path)
- `CloseHandle`
- `sub_520ED0` (`Message` destructor path)

Representative global checks:

- `0x0067a738` has exactly 9 xrefs in the MCP sample, including the cleanup delete at `0x00464a98`. Current docs resolve this global as `FileDownloader *g_pFileDownloader`; the stale `g_pCashShopRequest` spelling is not source-facing.
- `0x0067a7c8` has cleanup references at `0x00464bb0` and `0x00464bbf`; current docs identify it as `Config *g_pConfig`.
- `0x0067a99c` and `0x0067a9a0` are the Application error text buffer/count statics used by the cleanup error-message branch.
- `get_global_value` returned `0x0` for sampled runtime global storage locations, as expected for the inactive IDB state and not as source identity evidence.

Revision-specific MCP proof for the rejected blockers:

- `lookup_funcs` resolves `0x00491b30` to `sub_491B30` size `0xb65`, the documented `RegistryConfig::SaveToRegistry` child; `0x004926a0` resolves to `sub_4926A0` size `0x1789`, the documented `RegistryConfig::LoadFromRegistry` child; and `0x005ca28c` resolves to `__purecall`.
- `get_bytes 0x00612614 size 20` returned dwords `0x00467340`, `0x004f4b10`, `0x0041b6c0`, `0x00491b30`, and `0x004926a0`, matching the `RegistryConfig` destructor/support/null/SaveToRegistry/LoadFromRegistry vtable layout.
- `get_bytes 0x006168d0 size 24` returned dwords `0x00494020`, `0x004f4b10`, `0x0041b6c0`, `0x005ca28c`, `0x005ca28c`, and `0x00000000`, proving the base `Config` persistence tail slots are currently pure virtual/support entries rather than unrelated runtime data.
- `xrefs_to 0x0067ab3c` returned exactly five refs: H1 cleanup at `0x00464ba0`, constructor publish/null-clear at `0x00483f33` and `0x00483f3a`, clear helper at `0x00483ff0`, and deleting-destructor clear at `0x0048400f`; this is `g_pCheatDetector`.
- `int_convert 0x7465726d size 4` returned decimal `1952805485`, little-endian bytes `6d 72 65 74`, and ASCII `mret`. `int_convert 0x676f6f67 size 4` returned bytes `67 6f 6f 67` and ASCII `goog`. This supports documenting `0x7465726d` as an integer tag constant analogous to `kPaneTagGoog`, while avoiding a false memory-byte string claim.
- Current `decompile 0x00464a60` still shows `sub_520E30((void *)0x7465726D)`, `sub_4F4B70(v6)`, `sub_4EFF30(unk_67AB48)` before the `delete g_pKeySpeedMgr` null-check, the `g_pConfig` slot `+12` call before delete, `sub_469200()` before queue delete, and `CloseHandle(*(HANDLE *)(this + 2108))` followed by writing zero.

## Behavior Reconstructed

The function performs the final Application resource cleanup pass in this order:

1. Deletes the global miscellaneous worker/thread object if present.
2. Deletes `g_pFileDownloader` if present.
3. Constructs a local `Message` with tag `0x7465726d`.
4. Calls `ApplicationForwardMessage` with that local message.
5. Calls `ShowCursor(TRUE)`.
6. Closes CRT standard streams 0, 1, and 2 through `__acrt_iob_func` plus `fclose`.
7. Restores keyboard repeat/speed state through the `KeySpeedMgr` helper, then deletes `g_pKeySpeedMgr`.
8. Deletes the documented singleton/global managers in the exact MCP order, including SoundManager, EventMan, ScreenPane, DirectX, EventDispatcher, MidiPlayer, `g_pCheatDetector`, Config, FontImageLib, EPFLib, PaletteLib, InputMan, BlackHole cleanup queue, LanguageMan, ChangeMan, Crasher, crash target, MiniMapVersionManager, and DATFileMgr.
9. Calls `ShowWindow(this + 0x828, SW_HIDE)` on the Application main-window handle.
10. If the static Application error text count is nonzero, calls `MessageBoxW(NULL, s_applicationErrorText, L"Error", 0)`.
11. For `g_pConfig`, invokes virtual slot `+0x0c`, resolved in this revision as `Config::SaveToRegistry()` / `RegistryConfig::SaveToRegistry()`, before deleting the singleton.
12. If `this + 0x83c` contains a shutdown handle, calls `CloseHandle` and clears that field to zero.
13. Destroys the local `Message` on normal return and through the EH cleanup path.

The behavior belongs in `Application::CleanupResources`, not in the subsystem pages. The subsystem pages own their respective declarations, constructors, destructors, and singleton storage. This function is the Application orchestrator that sequences them.

## Positive Evidence

Source-bearing method evidence:

- The exact function has a normal body, not only jump padding or compiler glue.
- `ApplicationShutdown` tail-calls this function at `0x004f66a0`.
- The function reads and writes Application object fields at `this + 0x828` and `this + 0x83c`, matching `m_hMainWnd` and `m_hShutdownEvent` from `by-class/Application.md`.
- The data reference at `0x006125f4` supports Application dispatch/vtable ownership rather than free-function ownership.
- The function coordinates high-level shutdown state: termination broadcast, cursor visibility, CRT stream closure, singleton teardown, error reporting, and final shutdown-handle close.
- Adjacent bytes prove a clean range boundary: padding before `0x00464a60`, padding after `0x00464cc0`, successor function at `0x00464cd0`.

Resolved or partially resolved older blockers:

- `dword_67A738` is no longer a CashShop blocker for this target. Current FileDownloader docs identify the source-facing global as `FileDownloader *g_pFileDownloader`, with cleanup xref at `0x00464a98`.
- The local `Message` object shape is stronger than in the older report. `by-class/Message.md` documents `typedef unsigned int MessageType;`, `explicit Message(MessageType);`, and `virtual ~Message();`; `ApplicationSendShutdownMessage` already demonstrates a source-facing stack `Message` plus `ForwardMessage(&message)` pattern.
- `g_pConfig` is no longer an unknown global pointer. Current docs identify `Config *g_pConfig` and class/file support exists.
- `g_pConfig` slot `+0x0c` is no longer a no-code blocker. The `RegistryConfig` vtable maps the slot to `SaveToRegistry`, and the base `Config` vtable maps the persistence slots to `__purecall`, supporting virtual declarations on `Config`.
- The cleanup message tag has a safe source-facing first-draft constant: `static const MessageType kPaneTagTerm = 0x7465726d;`. The name is descriptive, not claimed as original-source proof.
- `0x0067ab3c` is no longer an unknown singleton. It is `CheatDetector *g_pCheatDetector` with five current MCP-confirmed xrefs.
- Most singleton global names in this function now have support pages with plausible source-facing names and ownership.
- The exact shutdown caller, range, padding, and target ownership have been rechecked under current MCP, not inherited from the older B002 report.

## Negative Evidence and Remaining Caveats

Formal C++ should not remain blank for `UID:0002H1`. The current negative evidence only limits final-source confidence; it does not justify another no-code disposition.

Residual implementation caveats:

- `Config` currently lacks declaration-level virtual persistence methods even though the base vtable tail resolves to `__purecall` and `RegistryConfig` supplies `SaveToRegistry`/`LoadFromRegistry`. The implementation should update `Config` and `RegistryConfig` support docs in the same accepted batch.
- `kPaneTagTerm` is a descriptive first-draft constant name. The binary proves the integer tag `0x7465726d`; it does not prove the original symbol spelling or a closed enum member.
- `ApplicationForwardMessage` still has its own empty emitter marker. That support page can emit the direct wrapper body independently, but H1 can safely call `ForwardMessage(&message)` because the accepted `SendShutdownMessage` body already uses that call shape.
- Several subsystem singleton pages still keep their own class/global formal C++ below final audit. H1 should not inline destructors or scalar deleting wrappers; it should use ordinary `delete g_p...;` statements and let each subsystem owner provide declarations/destructors.
- EPFLib/ImageLib and BlackHole singleton/header details remain support-page confidence caps, but they do not block H1 from deleting `g_pEPFLib` or calling `BlackHole::ReleaseQueuedOwnedObjects()` on `g_pApplicationCleanupQueue`.
- The `_AUTOBUF<wchar_t>` static API casing is still not final. H1 can use the documented fields `s_applicationErrorText.m_count` and `s_applicationErrorText.m_data` in first-draft source because those field names are accepted support names for the wide AUTOBUF storage.

Rejected blank-C++ alternatives:

- Omitting the config save branch is invalid because H1 explicitly calls the vtable slot before deletion.
- Leaving the tag anonymous in prose only is weaker than the accepted `kPaneTagGoog` precedent and would preserve an avoidable empty emitter.
- Requiring every deleted singleton's final header to be complete before writing `delete g_p...;` is too strict for first-draft source: the observed ABI lowering is exactly what ordinary C++ delete generates, and the owner pages already carry the declarations/destructor route.

## Heuristic and Inference Reanalysis

| Question | Current finding |
| --- | --- |
| Is the empty emitter caused by no owner? | No. Owner remains Application class/file, `UID:00000D`. |
| Is this compiler-generated only? | No. It has Application object field access, user-visible Win32 side effects, singleton teardown ordering, and a shutdown caller. |
| Should this be folded into `ApplicationShutdown`? | No. `ApplicationShutdown` tail-calls this exact function at `0x004f66a0`; padding and function boundaries keep it separate. |
| Should this be owned by Message or ChangeMan? | No. Message/ChangeMan provide support APIs; Application constructs and forwards the termination message as part of its cleanup pass. |
| Should this be owned by FileDownloader? | No. `g_pFileDownloader` identity is resolved, but the function only deletes it in Application teardown order. |
| Should this be owned by Config? | No. `Config`/`RegistryConfig` own `g_pConfig` and the `SaveToRegistry` method; Application owns the final call/delete sequence. |
| Is `dword_67A738` still a blocker? | Not for identity. It is `FileDownloader *g_pFileDownloader`; stale `g_pCashShopRequest` should not be used. |
| Is `Message` spelling still a blocker? | No for first-draft H1 emission. `Message message(kPaneTagTerm)` is supported; only the exact original constant spelling remains unproven. |
| Are indirect virtual deletes still blockers? | No for H1. Ordinary `delete g_p...;` is the source-facing form; subsystem owner pages own destructor declarations and global clearing. |
| Is C++ emission ready? | Yes. The target should emit first-draft `Application::CleanupResources()` with support edits for `Config` persistence virtuals and the `ApplicationForwardMessage` wrapper. |

## Ranked Owner and Source-Placement Alternatives

1. **Application class/file, accepted.**  
   The method should remain `Application::CleanupResources` under `NexusTK/app/Application.cpp`, owned and emitted by `UID:00000D`. This matches the target doc, `by-file/Application.md`, `by-class/Application.md`, the shutdown tail-call, field accesses, and lifecycle behavior.

2. **ApplicationLifecycle aggregate, rejected as emitter.**  
   The aggregate is useful for context and score/caveat rollup, but it should not emit this source method. The concrete method remains the by-memory target under Application.

3. **ApplicationShutdown merge, rejected.**  
   `ApplicationShutdown` is a separate method that tail-calls `ApplicationCleanupResources`. The function boundary, padding, and successor location do not support merging the source into `Shutdown`.

4. **Subsystem ownership, rejected.**  
   FileDownloader, Config, Message, ChangeMan, BlackHole, SoundManager, EventMan, and other subsystem pages own their declarations and teardown primitives. They do not own the Application-level teardown sequence.

5. **No-owner/no-code/compiler helper, rejected.**  
   The function is source-bearing and project-owned. The prior blank formal C++ gate is superseded by this revision's implementation-ready body.

## Split and Range Analysis

Recommended range remains:

- Start: `0x00464a60`
- End: `0x00464cc1`
- Size: `0x261` bytes, `609` decimal bytes.

Evidence:

- MCP `lookup_funcs` resolves `0x00464a60` to a function start and `0x00464cd0` to the successor function.
- MCP `disasm` reports `215` instructions for the target function.
- Bytes before the target from `0x00464a52` through `0x00464a5f` are all `0xcc`.
- Bytes after the target from `0x00464cc1` through `0x00464ccf` are all `0xcc`.
- The EH cleanup at `0x005fa827` is compiler-owned unwind support for the local `Message` destructor and should not be merged into the source range.

No split, merge, or ignored-range edit is recommended. The adjacent padding is already represented by the existing ignored-range convention.

## Score and Metadata Disposition

Recommended target metadata after implementation:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00000D`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`

Rationale for `90/92`:

- Completion improves because current MCP reconfirms the live function boundary, caller, exact callee set, adjacent padding, teardown order, stale `dword_67A738` identity as `g_pFileDownloader`, `0x0067ab3c` identity as `g_pCheatDetector`, and `g_pConfig` slot `+0x0c` as the `SaveToRegistry` vtable entry.
- Confidence improves because ownership and range are independently rechecked under current MCP and each rejected blocker now has current support evidence rather than older lifecycle-only reasoning.
- Completion should stay below final-source quality because exact original constant spelling, broad subsystem header completeness, and a few support-page summaries still need synchronization, but those are no longer empty-emitter blockers.

Generated refresh expectations:

- The generated `Application.cpp` marker for `UID:0002H1` should be replaced by the first-draft method body after the supervisor-approved validator batch.
- The generated marker/tracker score should refresh from stale `82/88` toward the implemented target doc state after the validator pipeline regenerates output.
- Generated files must not be edited manually.

## First-Draft C++ Disposition

Formal `RECONSTRUCTION_CPP CODE` is recommended for `UID:0002H1`.

Implementation-ready target body:

```cpp
static const MessageType kPaneTagTerm = 0x7465726d;

void Application::CleanupResources()
{
    delete g_pMiscWorkThread;
    delete g_pFileDownloader;

    Message message(kPaneTagTerm);
    ForwardMessage(&message);

    ShowCursor(TRUE);

    fclose(__acrt_iob_func(0));
    fclose(__acrt_iob_func(1));
    fclose(__acrt_iob_func(2));

    g_pKeySpeedMgr->RestoreSystemKeyboardSettings();
    delete g_pKeySpeedMgr;

    delete g_pSoundManager;
    delete g_pEventMan;
    delete g_pScreenPane;
    delete g_pDirectX;

    ShowWindow(m_hMainWnd, SW_HIDE);

    if (s_applicationErrorText.m_count != 0)
        MessageBoxW(NULL, s_applicationErrorText.m_data, L"Error", 0);

    delete g_pEventDispatcher;
    delete g_pMidiPlayer;
    delete g_pCheatDetector;

    if (g_pConfig != NULL)
    {
        g_pConfig->SaveToRegistry();
        delete g_pConfig;
    }

    delete g_pFontImageLib;
    delete g_pEPFLib;
    delete g_pPaletteLib;
    delete g_pInputMan;

    if (g_pApplicationCleanupQueue != NULL)
    {
        g_pApplicationCleanupQueue->ReleaseQueuedOwnedObjects();
        delete g_pApplicationCleanupQueue;
    }

    delete g_pLanguageMan;
    delete g_pChangeMan;
    delete g_pCrasher;
    delete g_pCrashTarget;

    if (m_hShutdownEvent != NULL)
    {
        CloseHandle(m_hShutdownEvent);
        m_hShutdownEvent = NULL;
    }

    delete g_pMiniMapVersionManager;
    delete g_pDATFileMgr;
}
```

Source-shape notes:

- The `g_pKeySpeedMgr->RestoreSystemKeyboardSettings();` call is intentionally unguarded because the current decompile calls `sub_4EFF30(unk_67AB48)` before the delete null-check. This matches source that assumes the singleton exists during normal cleanup.
- Ordinary `delete g_p...;` statements intentionally replace raw vtable deleting-destructor calls. The subsystem owner pages own ordinary destructors/global clears; H1 owns only the teardown sequence.
- `s_applicationErrorText.m_count` and `s_applicationErrorText.m_data` use the accepted `_AUTOBUF<wchar_t>` field names from current AUTOBUF/Application support docs.
- `kPaneTagTerm` is first-draft descriptive naming for the proven integer tag. Do not emit a C++ multi-character literal or a final enum name in this pass.
- If the implementation prefers stricter CRT source style, the three stream closes may remain as `fclose(__acrt_iob_func(0/1/2))` exactly as shown; converting to `stdin`/`stdout`/`stderr` is a later polish decision, not required for this callback.

## Recommended Implementation Edits

If the supervisor accepts this report for implementation, edit only the files below and only under an immediate lease batch. Release leases immediately after the edit/validator batch.

Required target edit:

- `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`
  - Update score to `COMPLETION:90` / `CONFIDENCE:92`.
  - Keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000D`.
  - Populate the formal C++ block with the `Application::CleanupResources()` body in this report.
  - Add current B010 MCP evidence: server status, function size, decompile/callee set, xrefs, adjacent padding, `RegistryConfig`/`Config` vtable bytes, `__purecall` lookup, `g_pCheatDetector` xrefs, and tag conversion proof.
  - Update stale blocker language: resolve `dword_67A738` to `g_pFileDownloader`; resolve `0x0067ab3c` to `g_pCheatDetector`; resolve `g_pConfig` slot `+0x0c` to `SaveToRegistry`; add `kPaneTagTerm`.
  - Add or update teardown-order notes for `g_pFileDownloader`, `g_pCheatDetector`, `g_pConfig`, local `Message`, `ForwardMessage`, Application error statics, BlackHole drain, and shutdown-handle close.
  - Replace the old no-code proof with a first-draft C++ proof and residual support-caveat list.

Required support edits:

- `by-file/Application.md`
  - Update the `ApplicationCleanupResources` row/note to reflect current `90/92`, resolved `g_pFileDownloader`, `g_pCheatDetector`, `g_pConfig->SaveToRegistry()`, `kPaneTagTerm`, current MCP proof, and C++ readiness.

- `by-class/Application.md`
  - Update the `CleanupResources` method/context note to mark the exact child as source-ready first-draft C++ and to record the `kPaneTagTerm` / `ForwardMessage` shape.
  - Preserve Application ownership and method placement.

- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
  - Update the H1/cleanup child-row status to match the target recommendation.
  - Make clear the lifecycle aggregate is context only and not the emitter for H1.

- `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md`
  - Add first-draft wrapper C++ if current validator context permits:
    `void Application::ForwardMessage(Message *message) { g_pChangeMan->DispatchMessage(this, message); }`
  - At minimum, update the note that H1 and `SendShutdownMessage` use the accepted `ForwardMessage(&message)` call shape.

- `by-class/Config.md`
  - Add declaration-level persistence virtuals:
    `virtual void SaveToRegistry() = 0;`
    `virtual bool LoadFromRegistry() = 0;`
  - Record that base vtable tail slots resolve to `__purecall` and support H1's `g_pConfig->SaveToRegistry()` call.

- `by-class/RegistryConfig.md`
  - Add or synchronize declaration-level overrides:
    `void SaveToRegistry();`
    `bool LoadFromRegistry();`
  - Record that H1 uses the base `Config *g_pConfig` pointer to call `SaveToRegistry()` before delete.

- `by-memory/0x006168d0-0x006168e8.ConfigVtableData.md`
  - Update slot wording for `0x006168dc` and `0x006168e0` from generic runtime/type-data tail wording to `__purecall` persistence slots corresponding to `SaveToRegistry` and `LoadFromRegistry`.

- `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`
  - Add the H1 consumer cross-reference for slot `0x00612620` / `SaveToRegistry`.

- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
  - Add a concise cross-reference that `ApplicationCleanupResources` calls `g_pConfig->SaveToRegistry()` before deletion, resolving the former H1 vtable-slot blocker.

Recommended cleanup support edit if touched in the same implementation batch:

- `by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md`
  - Fix the stale item summary phrase that says final C++ remains blank; the page already has first-draft C++ and supports the H1 call.

No edit required:

- `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`
- `by-global/g_pCashShopRequest.md`
- `by-file/FileDownloader.md`
- `by-class/FileDownloader.md`
- `by-class/Message.md`
- `by-memory/0x00520e30-0x00521d94.MessageCore.md`

Those pages are useful evidence, but the checked docs already contain enough support for the implementation update.

Do not edit:

- `auto-generated/NexusTK/app/Application.cpp`
- `auto-generated/-ag-research-tracker.md`
- Any generated report or project-level generated file.
- Any manual `-coverage-report.md` file.
- Validator/tool state by hand.
- IDA database state.

## Validator Commands for Accepted Implementation

Run validators only after the future implementation edit batch, from:

`E:\NTK\GhidraBridge\source-3\project-documentation`

Required if all required support edits are made:

> Executable block R001 was removed from this report and preserved verbatim in [0002H1-ApplicationCleanupResources-empty-emitter-source-quality-removed.md](0002H1-ApplicationCleanupResources-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add this validator only if the stale BlackHole item-summary cleanup is edited:

> Executable block R002 was removed from this report and preserved verbatim in [0002H1-ApplicationCleanupResources-empty-emitter-source-quality-removed.md](0002H1-ApplicationCleanupResources-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validators, inspect generated output only as validator-owned refresh output:

- Confirm `auto-generated/NexusTK/app/Application.cpp` now includes the `UID:0002H1` first-draft `Application::CleanupResources()` body rather than an empty marker.
- Confirm the generated marker/tracker score no longer reports stale `82/88` after refresh if the validator pipeline regenerates it.
- Do not manually edit generated files.

## Implementation Tracking Checklist

- [x] Rechecked MCP availability and active IDB status for this rejection revision.
- [x] Reinvestigated `g_pConfig` slot `+0x0c`; proof is `RegistryConfig` vtable bytes plus `lookup_funcs` for `SaveToRegistry`, `LoadFromRegistry`, and `__purecall`.
- [x] Reinvestigated termination tag `0x7465726d`; proof is current H1 decompile, `MessageType` docs, `SendShutdownMessage` precedent, and `int_convert` byte-order warning.
- [x] Reinvestigated `ApplicationForwardMessage` shape; proof is current wrapper docs and generated `SendShutdownMessage` source shape.
- [x] Reinvestigated singleton/global declaration surfaces; proof includes `g_pFileDownloader`, `g_pCheatDetector`, `BlackHole::ReleaseQueuedOwnedObjects`, and current global/class support docs.
- [x] Replaced the rejected blank-C++ disposition with implementation-ready first-draft `Application::CleanupResources()` source in this report.
- [x] On accepted implementation callback, leased only the immediate edit/validator set before implementation: target H1 doc, Application file/class docs, ApplicationLifecycle aggregate, ForwardMessage, Config/RegistryConfig/vtable support, `g_pConfig`, and optional BlackHole summary cleanup. Proof: `python .\tools\leaser\leaser.py B010 lease ...` returned `Success` for all 11 by-* paths before validation.
- [x] Updated `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md` with score `90/92`, current MCP evidence, resolved blockers, teardown-order notes, and the formal C++ body. Validator proof: command `000000000148`, timestamp `2026-06-28T23:00:12-04:00`, exit `0`, `ok: 1`, generated refresh `deferred`.
- [x] Updated `by-file/Application.md` and `by-class/Application.md` with H1 source-ready status, `kPaneTagTerm`, `ForwardMessage`, and cleanup-order support. Validator proof: by-file command `000000000149`, timestamp `2026-06-28T23:00:13-04:00`, exit `0`, `ok: 1`, generated refresh `deferred`; by-class command `000000000150`, timestamp `2026-06-28T23:00:15-04:00`, exit `0`, `ok: 1`, exposed one bad `0002MY` UID link rewrite, which was corrected to canonical `00019B` and revalidated by command `000000000159`, timestamp `2026-06-28T23:01:21-04:00`, exit `0`, `ok: 1`, generated refresh `deferred`, `reference_index_remove 0002MY`.
- [x] Updated `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` with H1 child-row/context refresh. Validator proof: command `000000000151`, timestamp `2026-06-28T23:00:17-04:00`, exit `0`, `ok: 1`, generated refresh `deferred`.
- [x] Updated `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md` with wrapper call-shape/body support. Validator proof: command `000000000152`, timestamp `2026-06-28T23:00:19-04:00`, exit `0`, `ok: 1`, generated refresh `deferred`.
- [x] Updated `by-class/Config.md`, `by-class/RegistryConfig.md`, `by-memory/0x006168d0-0x006168e8.ConfigVtableData.md`, `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` with the virtual persistence support and H1 cross-reference. Validator proof: commands `000000000153` through `000000000157`, timestamps `2026-06-28T23:00:28-04:00` through `2026-06-28T23:00:41-04:00`, all exit `0`, all `ok: 1`, generated refresh `deferred`.
- [x] Optionally updated `by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md` to remove the stale item-summary blank-C++ phrase. Validator proof: command `000000000158`, timestamp `2026-06-28T23:00:42-04:00`, exit `0`, `ok: 1`, generated refresh `deferred`.
- [x] Ran the validator commands listed above for every touched by-* file. Proof: commands `000000000148` through `000000000159` covered all 11 touched by-* files, with a final corrective rerun for `by-class/Application.md`; every validator exited `0` and reported `ok: 1`.
- [x] Checked validator-owned generated output for the `UID:0002H1` body/tracker refresh without manually editing generated files. Proof: queue-status command `000000000160` at `2026-06-28T23:01:46-04:00` showed generated refresh pending/processing; status command `000000000161` at `2026-06-28T23:02:00-04:00` showed queued/processing generated refresh jobs `0/0`; `auto-generated/NexusTK/app/Application.cpp` then reported `validator-command-id: 000000000172`, `validator-refreshed-at: 2026-06-28T23:02:54-04:00`, `validator-refresh-source: foreground-generated-refresh`, and contains `// UID:0002H1 ... Completion:90 | Confidence:92` plus the accepted `Application::CleanupResources()` body.
- [x] Released all leases immediately after the edit/validator batch. Proof: `python .\tools\leaser\leaser.py B010 unlease ...` returned `Success` for all 11 paths; `tools/leaser/Agents/current_leases.md` read afterward listed no `B010` leases.
- [x] Return an implementation result and update this checklist with checked implementation items plus validator proof if the implementation callback is accepted. Proof: this checklist was updated after validation and lease release; final response will return `FINISHED_IMPLEMENTATION`.

## Accepted Implementation Proof

Accepted callback implementation completed on 2026-06-28/2026-06-29 without running `execute_report` and without manual edits to generated C++. The validator-owned generated `Application.cpp` refresh is command `000000000172` and includes the `UID:0002H1` first-draft body, `kPaneTagTerm`, `g_pFileDownloader`, `g_pCheatDetector`, `g_pConfig->SaveToRegistry()`, and `g_pApplicationCleanupQueue->ReleaseQueuedOwnedObjects()`.

## Report-Only Proof

This rejection-revision report-only pass edited only the existing report:

- `tools/leaser/Agents/Agent-B010/research/0002H1-ApplicationCleanupResources-empty-emitter-source-quality.md`

No leases were taken. No validators were run. No by-* docs, generated files, project-level files, manual coverage reports, validator/tool state, or IDA database were edited.

Revision proof summary:

- MCP was available and read-only calls succeeded.
- The supervisor-named blockers were rechecked and resolved to implementation-ready support edits.
- The report now recommends first-draft formal C++ for `UID:0002H1` rather than a blank-code/no-improvement disposition.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002H1-ApplicationCleanupResources-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002H1-ApplicationCleanupResources-empty-emitter-source-quality.md","timestamp":"2026-06-28T23:08:26","uid":"0002H1"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002H1-ApplicationCleanupResources-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0002H1-ApplicationCleanupResources-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002H1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
