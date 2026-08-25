** TARGET-REPORT-UID:0002H8 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002H8] ApplicationShutdown empty-emitter source-quality report

**Agent:** B008  
**Assignment:** B008-report-0002H8-ApplicationShutdown-empty-emitter-source-quality-20260628  
**Target:** `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md`  
**Current callback mode:** report-only research first  
**Report status:** implementation recommended; no project documentation was edited in this report pass

## Current target state

- UID `0002H8` is the by-memory target for the `ApplicationShutdown` body at `0x004f6490-0x004f66a5`.
- Current target metadata is `COMPLETION:86`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00000D`, and `EMITTER_UIDS:00000D`.
- The source route is valid: `0002H8` emits through `by-class/Application.md` (`UID:00000D`), which emits through `by-file/Application.md` (`UID:0000HG`) to `NexusTK/app/Application.cpp`.
- The target currently has blank `RECONSTRUCTION_CPP CODE` fields even though its score average is `(86 + 91) / 2 = 88.5`, which is above the current source-entry gate.
- Generated `auto-generated/NexusTK/app/Application.cpp` is stale for this target: its generated header still records `0002H8` as an empty emitter marker with older `80/89` metadata, while the source by-memory target is now `86/91`.

## MCP and local evidence checked

IDA MCP was mandatory for this assignment and was available.

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Active IDB session: `agent_b009_0002my_20260628`
- Active IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path reported by server health: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Server health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`
- Active worker process from `idb_list`: PID `2412`

MCP calls used:

- `initialize`
- `tools/list`
- `idb_list`
- `server_health`
- `lookup_funcs`
- `xrefs_to`
- `callees`
- `analyze_function`
- `disasm`
- `get_bytes`

Local documentation and generated files checked:

- `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md`
- `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`
- `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`
- `by-file/Application.md`
- `by-class/Application.md`
- `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
- `by-global/g_packetSender.md`
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- `by-file/Socket.md`
- `by-class/Socket.md`
- `by-class/Thread.md`
- `by-file/Thread.md`
- `by-global/MainUiLayerSlots.md`
- `by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md`
- `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`
- `by-global/g_pIMEPane.md`
- `auto-generated/NexusTK/app/Application.cpp`
- `auto-generated/-ag-research-tracker.md`

No by-* documentation, generated files, validator state, project-level generated files, manual coverage reports, or IDA database state were edited.

## Positive binary evidence

MCP confirms the target body is a single function beginning at `0x004f6490`:

- `lookup_funcs 0x004f6490` resolves to current IDB name `sub_4F6490`, size `0x215`.
- `lookup_funcs 0x004f66a5` finds no function, matching `0x004f66a5` as the byte after the tail jump body.
- `get_bytes 0x004f66a0` shows the tail jump bytes at `0x004f66a0` followed by `0xcc` padding through the next function start at `0x004f66b0`.
- `xrefs_to 0x004f6490` reports exactly two xrefs: a code xref from `_WinMain@16` at `0x004f5e8e` and a data xref from vtable storage at `0x0061d128`.
- `xrefs_to 0x004f66a5` reports no xrefs.

MCP `analyze_function` and disassembly agree on the shutdown order:

1. Write `4` to `0x0067a938`, documented as `ApplicationPhaseState`.
2. If the event manager global exists, call the EventMan shutdown helper at `0x004a8f40`.
3. Delete `g_pIMEPane`.
4. If `g_pScreenPane` exists, call the layer detach helper at `0x00556d20` for six main UI layer slots in this order: status, layout, overlay, effect, root, FPS overlay.
5. Delete the main UI graph/global at `0x0067aba4`.
6. Delete and clear the six main UI layer globals in this order: FPS overlay, status, overlay, effect, root, layout.
7. Delete image-library globals in this order: EffectObj, StaticObj, NewHuman, Monster, Riding, MapTile, ItemObj, LightObj.
8. Delete `g_pIdleWatcher`.
9. Call `g_packetSender` vtable slot `+0x10`, then delete `g_packetSender` if non-null.
10. Delete `g_pTextFilter`.
11. Delete `g_pMetaMan`.
12. Tail jump to `ApplicationCleanupResources` at `0x00464a60`.

The direct callees reported by MCP are only `sub_4A8F40` and `sub_556D20`; the destructor calls, socket/thread shutdown call, and final cleanup are indirect virtual calls or a tail jump. This matches the current target prose and explains why older generated output treated the target as an empty emitter despite the now-sufficient surrounding source evidence.

## Dependency evidence

The earlier blockers have enough accepted local support to write first-draft C++ without inventing ownership.

- `ApplicationStartup` already emits formal source for the matching startup half and uses the same `g_mainUiLayerSlots` member names.
- `ApplicationCleanupResources` is a separate Application-owned tail callee. It should stay a separate call and should not be inlined into this target.
- `EventManAndEventFactoryHelpers` documents `0x004a8f40` as the EventMan packet-event shutdown/close helper. MCP decompilation shows it uses `g_packetSender`, calls a Socket-side helper, then tail-calls vtable slot `+0x0c`.
- `g_packetSender` is now source-facing as `Socket *`, with owner/emitter under Socket.
- Socket/Thread documentation resolves the relevant vtable slots: slot `+0x0c` is the graceful stop path and slot `+0x10` is inherited `Thread::ForceTerminate()`.
- `MainUiLayerSlots` documents the six Application-owned layer context globals used by Startup and Shutdown.
- `ApplicationLifecycleFlags` documents the `0x0067a938` write as `ApplicationPhaseState`.
- `g_pIMEPane`, ScreenPane, image-library globals, `IdleWatcher`, `TextFilter`, and `MetaMan` support docs identify the shutdown-owned globals sufficiently for source reconstruction.

The remaining uncertainty is mostly exact original spelling for some support-level helper names, especially the ScreenPane layer-detach method and final enum/constant name for phase value `4`. Those are support-quality caps, not blockers for this target's source entry, because the target's behavior, ordering, ownership route, and binary bounds are now verified.

## Negative evidence and rejected alternatives

- **Do not leave the emitter blank.** The target already passes the code-entry score gate and has a valid emitter route. The old blank-C++ rationale is stale after the Socket/Thread/EventMan and layer-slot support pages were improved.
- **Do not move this body to Socket, EventMan, ScreenPane, IME, or image-library owners.** Those pages own helper classes and globals, but the orchestrating method is Application-owned through the vtable xref at `0x0061d128` and `_WinMain@16` call at `0x004f5e8e`.
- **Do not make this a no-owner or split target.** The range is exact, has one coherent `this` register, and ends with a tail jump into the known Application cleanup callee.
- **Do not inline `ApplicationCleanupResources`.** The tail jump is a separate Application helper beginning at `0x00464a60`; its own page remains the correct owner for that teardown pass.
- **Do not treat `g_packetSender` as an unresolved raw helper.** Current Socket/Thread support resolves the source type and the slot call in this target to `g_packetSender->ForceTerminate()`.
- **Do not edit generated Application.cpp manually.** It is stale and should be refreshed by validator/generator flow during implementation.

## Heuristic and source-quality reanalysis

This target now satisfies the B-agent source-entry gate:

- `RECONSTRUCTABLE:TRUE` is already set.
- `EMITTER_UIDS:00000D` is nonblank and reaches the Application class/file route.
- `(COMPLETION + CONFIDENCE) / 2` is `88.5`, greater than `85`.
- The old source-quality blockers have been resolved or reduced to support-level spelling caps:
  - Socket/Thread support resolves `g_packetSender` and the vtable `+0x10` shutdown call.
  - EventMan support resolves the packet-event shutdown helper.
  - Main UI layer slot names are accepted and already used by `ApplicationStartup`.
  - Tail-call ownership is resolved as `ApplicationCleanupResources`.
  - The binary range, xrefs, and call order were verified with MCP.

The implementation callback should therefore convert `0002H8` from a high-priority empty emitter to a source-emitting Application method.

## Ranked ownership/source-placement alternatives

1. **Keep owner/emitter as Application class/file.** This is the correct placement. The function is vtable-referenced as an Application method, is called from `_WinMain@16`, uses Application startup/shutdown globals, and tail-calls the Application cleanup helper.
2. **ScreenPane or layer-slot ownership.** Rejected. ScreenPane only owns the detach helper and active layer frame behavior; it does not own the orchestration body.
3. **Socket/EventMan ownership.** Rejected. Those modules own the helper calls used inside shutdown; the outer shutdown method remains Application-owned.
4. **Global/helper ownership.** Rejected. The function has an Application `this` pointer and class lifecycle semantics, not a standalone helper shape.

No metadata ownership move is recommended.

## Split/range analysis

The current range `0x004f6490-0x004f66a5` should be kept.

- Prologue begins at `0x004f6490` with `push esi; mov esi, ecx`.
- The target writes the phase state, performs teardown, and ends at `0x004f66a0` with a tail jump to `0x00464a60`.
- Bytes from `0x004f66a5` to the next function at `0x004f66b0` are padding.
- There is no evidence of an internal function start, switch island, or merged helper inside the range.
- Direct helper bodies `0x004a8f40`, `0x00556d20`, and `0x00464a60` have their own ownership and should remain out of the target C++ body except as calls.

## Score and metadata disposition

Recommended target metadata after implementation:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:00000D`
- `EMITTER_UIDS:00000D`
- `EMITTER_POSITION_OPTIONAL:` unchanged/blank

Rationale:

- Completion should rise because the target should no longer be blank and now has a concrete first-draft source body.
- Confidence can rise modestly because the key vtable and helper-name questions were resolved with current MCP and accepted support docs.
- Do not raise to a near-final score yet because final original spelling for the phase enum/constant, ScreenPane detach method, and several destructors remains support-capped.

## Formal C++ recommendation

The implementation callback should install a formal `RECONSTRUCTION_CPP CODE` body equivalent to the following. The method name should follow the existing Application class/source naming convention for this target; the body must preserve the binary deletion and clear order.

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | source=agent-b008-report-20260629, confidence=92 ***
void Application::Shutdown()
{
    ApplicationPhaseState = 4;

    if (g_pEventMan)
        g_pEventMan->ShutdownPacketEventSource();

    delete g_pIMEPane;

    if (g_pScreenPane) {
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.statusPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.layoutPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.fpsOverlayLayerContext);
    }

    delete g_pMainUiGraph;

    delete g_mainUiLayerSlots.fpsOverlayLayerContext;
    g_mainUiLayerSlots.fpsOverlayLayerContext = NULL;

    delete g_mainUiLayerSlots.statusPaneLayerContext;
    g_mainUiLayerSlots.statusPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.overlayPaneLayerContext;
    g_mainUiLayerSlots.overlayPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.effectPaneLayerContext;
    g_mainUiLayerSlots.effectPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.rootPaneLayerContext;
    g_mainUiLayerSlots.rootPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.layoutPaneLayerContext;
    g_mainUiLayerSlots.layoutPaneLayerContext = NULL;

    delete g_pEffectObjImageLib;
    delete g_pStaticObjImageLib;
    delete g_pNewHumanImageLib;
    delete g_pMonsterImageLib;
    delete g_pRidingImageLib;
    delete g_pMapTileImageLib;
    delete g_pItemObjImageLib;
    delete g_pLightObjImageLib;

    delete g_pIdleWatcher;

    g_packetSender->ForceTerminate();
    delete g_packetSender;

    delete g_pTextFilter;
    delete g_pMetaMan;

    CleanupResources();
}
*** RECONSTRUCTION_CPP CODE:BEGIN | source=agent-b008-report-20260629, confidence=92 ***
void Application::Shutdown()
{
    ApplicationPhaseState = 4;

    if (g_pEventMan)
        g_pEventMan->ShutdownPacketEventSource();

    delete g_pIMEPane;

    if (g_pScreenPane) {
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.statusPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.layoutPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.fpsOverlayLayerContext);
    }

    delete g_pMainUiGraph;

    delete g_mainUiLayerSlots.fpsOverlayLayerContext;
    g_mainUiLayerSlots.fpsOverlayLayerContext = NULL;

    delete g_mainUiLayerSlots.statusPaneLayerContext;
    g_mainUiLayerSlots.statusPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.overlayPaneLayerContext;
    g_mainUiLayerSlots.overlayPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.effectPaneLayerContext;
    g_mainUiLayerSlots.effectPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.rootPaneLayerContext;
    g_mainUiLayerSlots.rootPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.layoutPaneLayerContext;
    g_mainUiLayerSlots.layoutPaneLayerContext = NULL;

    delete g_pEffectObjImageLib;
    delete g_pStaticObjImageLib;
    delete g_pNewHumanImageLib;
    delete g_pMonsterImageLib;
    delete g_pRidingImageLib;
    delete g_pMapTileImageLib;
    delete g_pItemObjImageLib;
    delete g_pLightObjImageLib;

    delete g_pIdleWatcher;

    g_packetSender->ForceTerminate();
    delete g_packetSender;

    delete g_pTextFilter;
    delete g_pMetaMan;

    CleanupResources();
}
*** RECONSTRUCTION_CPP CODE:END | source=agent-b008-report-20260629, confidence=92 ***
```

Implementation notes for the callback:

- Keep `g_packetSender->ForceTerminate()` unconditional, then delete the pointer. The binary calls slot `+0x10` before the delete check.
- Keep explicit `NULL` clears for the six layer slot globals. The binary clears those globals after deletion.
- Do not add clears for globals where the body does not explicitly write zero.
- Keep `CleanupResources()` as the final statement; do not inline that helper.
- `DetachLayerFrame` is a recommended source-facing name for the helper at `0x00556d20`. If the Application/ScreenPane support docs settle on `RemoveLayerFrame`, use that name consistently, but do not leave the body blank for this spelling issue alone.

## Implementation tracking checklist

- [x] Lease only the docs being edited immediately for the implementation batch. Proof: B008 held only the target/support leases for `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md`, `by-file/Application.md`, `by-class/Application.md`, `by-memory/0x00556910-0x00557132.ScreenPane.md`, and `by-class/ScreenPane.md` during the edit/validator batch.
- [x] Update `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md` metadata to recommended `COMPLETION:90` and `CONFIDENCE:92`, keeping owner/emitter fields unchanged. Proof: target validator command `000000000083` accepted the target with `ok: 1`; generated `Application.cpp` now reports `UID:0002H8 ... Completion:90 | Confidence:92`.
- [x] Replace the blank `RECONSTRUCTION_CPP CODE` entries in the target with a formal C++ body preserving the verified teardown order. Proof: the target multiline block now contains only the accepted `void Application::Shutdown()` body, with `ApplicationPhaseState = 4`, packet event shutdown, IME deletion, six `DetachLayerFrame` calls, graph/layer/image-library/watchers/sender/filter/meta cleanup, and final `CleanupResources()`; the illustrative report `source=agent-b008-report-20260629` header/footer lines were not copied into the target block.
- [x] Update the target Item Summary, Reconstruction Notes, IDA Evidence, Score Rationale, and Changes sections to cite the 2026-06-29 B008 report and the MCP evidence above. Proof: target validator command `000000000083` accepted the revised target after the B008 evidence and rationale sections were updated.
- [x] Remove or supersede the stale target-level no-code rationale that says singleton deletion order, indirect destructor targets, and the `g_packetSender` route still block formal source. Proof: the target now states those items are resolved by B008 MCP evidence and emits the accepted formal body.
- [x] Update `by-file/Application.md` only if needed to record that `ApplicationShutdown` now emits source into `NexusTK/app/Application.cpp`. Proof: `by-file/Application.md` records the UID `0002H8` source-ready exact child and the generated-source stale marker resolution; scoped validator command `000000000085` returned `ok: 1`.
- [x] Update `by-class/Application.md` only if needed to record that the `Application::Shutdown` method entry is no longer an empty emitter. Proof: `by-class/Application.md` records `Application::Shutdown` as the source-ready first-draft child at `90/92`; scoped validator command `000000000087` returned `ok: 1`.
- [x] Verify supporting pages for `g_packetSender`, Socket, Thread, EventMan, MainUiLayerSlots, ScreenPane, ApplicationLifecycleFlags, IMEPane, and CleanupResources already contain the names used by the target C++ or add narrowly scoped support notes if a validator requires them. Proof: existing support was sufficient for the packet sender, Socket/Thread/EventMan route, layer slot globals, lifecycle flag, IME pane, and cleanup helper; the ScreenPane target/class support docs were narrowly patched for the `DetachLayerFrame` caller-side name and validated by commands `000000000088` and `000000000089`.
- [x] Run the scoped validator/generator for every edited by-* file with `--wait-generated`; do not manually edit generated output. Proof: target/support commands `000000000083`, `000000000085`, `000000000087`, `000000000088`, and `000000000089` all ran with `--wait-generated`, returned `ok: 1`, and completed generated refresh.
- [x] Confirm generated `auto-generated/NexusTK/app/Application.cpp` no longer marks `0002H8` as an empty emitter and now contains the shutdown body. Proof: generated output refreshed by command `000000000089` at `2026-06-28T22:32:55-04:00` and contains `// UID:0002H8 ... Completion:90 | Confidence:92` followed by `void Application::Shutdown()` and the emitted body, not an Empty Emitter Marker for this UID.
- [x] Confirm generated metadata no longer reports the stale `80/89` target score for `0002H8`. Proof: generated `Application.cpp` reports `Completion:90 | Confidence:92` for UID `0002H8`.
- [x] Release all leases immediately after the edit/validator batch. Proof: final `python leaser.py B008 unlease` returned `B008: No active leases`, and `Agents/current_leases.md` has no `B008`/`Agent-B008` entries afterward.
- [x] Return `FINISHED_IMPLEMENTATION` only after all accepted details are applied or verified already present. Proof: all accepted target/support details above are applied or verified, validators passed, generated UID `0002H8` is no longer empty, and B008 leases are released.

## Report-only closure

This report did not edit target docs, generated files, validator/tool state, manual coverage reports, or IDA DB state. No leases were acquired because this pass was report-only. IDA MCP was available and used for read-only verification, so this assignment is not paused for MCP availability.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002H8-ApplicationShutdown-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002H8-ApplicationShutdown-empty-emitter-source-quality.md","timestamp":"2026-06-28T22:35:25","uid":"0002H8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
