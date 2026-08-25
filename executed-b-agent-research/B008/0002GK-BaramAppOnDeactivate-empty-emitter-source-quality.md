** TARGET-REPORT-UID:0002GK **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002GK BaramAppOnDeactivate Empty-Emitter Source-Quality Report

Agent: Agent-B008  
Date: 2026-06-29  
Target: `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md`  
UID: `0002GK`  
Mode: report-only research first  
Status: `IMPLEMENTATION_APPLIED` - accepted details incorporated; pending supervisor verification/execution  

## Original Report-Only Guardrails

No target/support by-* docs, generated files, coverage reports, project-level generated files, validator/tool state, lock files, IDA DB, or executed-report archives were edited for this report-only pass. No leases were taken. No subagents were spawned.

IDA MCP was available at `http://127.0.0.1:13337/mcp`. The active read-only IDB session used for current evidence was `b6b3c97e`; `server_health` reported `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, module `NexusTK.exe`, imagebase `0x400000`.

## Report-Time Target And Generated State

Current target metadata in `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md`:

| Field | Current value |
|---|---|
| UID | `0002GK` |
| Name | `BaramAppOnDeactivate` |
| Owner UID | `00000V` |
| Emitter UID | `00000V` |
| Reconstructable | `TRUE` |
| Completion / confidence | `86 / 91` |
| Formal C++ | blank |

At report time, generated `auto-generated/NexusTK/app/Application.cpp` was checked as context only. It still showed UID0002GK as `Completion:80 | Confidence:90 | Empty Emitter Marker`, with generated header `validator-command-id:000000000466` and `validator-refreshed-at:2026-06-29T09:01:40-04:00`. That report-time generated state was stale relative to the target document and was not edited manually; the implementation callback results below record the validator-refreshed replacement with real UID0002GK code.

## Summary Recommendation

UID0002GK is ready for a first-draft formal C++ reconstruction. Current MCP evidence resolves the older target/class blocker that Hex-Rays could not recover the function because of the non-contiguous audio tail: the current decompile of `0x00466a70` succeeds and includes the tail chunk at `0x0057a450` as part of the same function. The function has no code callers and is reached through Application/BaramApp vtable data refs, so the existing Application file ownership remains correct.

Recommended metadata update:

| Field | Recommended value | Reason |
|---|---|---|
| `COMPLETION` | `90` | Empty emitter can be replaced by source-shaped C++; current decompile/disassembly, vtable refs, globals, and support pages resolve the target behavior. |
| `CONFIDENCE` | `92` | Control flow and dependencies are direct MCP evidence; remaining risk is source spelling for one input-active field and several app-focus SoundManager/EventMan helper names. |
| `EMITTER_UIDS` | `00000V` | Application/BaramApp owner is still correct. |
| `EMITTER_POSITION_OPTIONAL` | `40` | Target prose already places deactivation after activation in `app/Application.cpp`; fill the metadata field so generation order is explicit. |
| Formal C++ | insert the block in this report | Current MCP decompile is nonblank and source-ready enough for a first-draft reconstruction. |

No exact no-code marker is recommended. The range is not fully covered by another UID, and current MCP proves UID0002GK owns both the main body and the `0x0057a450` audio tail as one decompiled function.

## Current MCP Evidence

### Function Identity

`lookup_funcs` at `0x00466a70` resolves the current IDB function as `sub_466A70`, size `0xb3`. The saved by-* name `BaramAppOnDeactivate` is not present in the current IDB, but the target document and vtable placement identify the source role.

`xrefs_to 0x00466a70` returns exactly two data refs and no code refs:

| Ref address | Meaning |
|---|---|
| `0x006125fc` | Application/BaramApp vtable data slot for the deactivation callback. |
| `0x0061d130` | Second vtable data slot for the same callback route. |

`xrefs_to 0x0057a450` returns exactly one code ref, `0x00466b1c` inside `sub_466A70`. This proves the app-deactivation music tail is target-owned for UID0002GK and is not a separately reached function in the current IDB.

### Current Decompile

Current Hex-Rays decompilation succeeds:

```c
void __thiscall sub_466A70(_BYTE *this)
{
  int v1; // eax
  int v2; // esi
  unsigned int v3; // [esp-8h] [ebp-8h]

  if ( !this[2106] )
  {
    this[2105] = 0;
    if ( !unk_67A93C && dword_67A7CC )
    {
      *(_BYTE *)(unk_67AB1C + 2104) = 0;
      ShowWindow(*(HWND *)(unk_67AB1C + 2088), 6);
      sub_5576A0((_BYTE *)dword_67A7CC);
    }
    if ( dword_67A754 )
      sub_4A90D0(dword_67A754, 0);
    if ( unk_67AB48 )
      sub_4EFF30((_DWORD *)unk_67AB48);
    if ( dword_67A764 )
      sub_505CC0((_BYTE *)dword_67A764);
    v1 = dword_67A7C8;
    v2 = dword_67A7D0;
    if ( *(_BYTE *)(dword_67A7C8 + 2678344) )
    {
      sub_57A780((_BYTE *)dword_67A7D0);
      v1 = dword_67A7C8;
    }
    if ( !*(_DWORD *)(v1 + 2693384) )
    {
      if ( *(_BYTE *)(v2 + 12) )
        *(_BYTE *)(v2 + 4) = 1;
      sub_5260D0(unk_67AB4C);
      v3 = *(_DWORD *)(v2 + 16);
      *(_BYTE *)(v2 + 12) = 0;
      sub_57A340(v2, v3);
    }
  }
}
```

### Current Disassembly Shape

Important disassembly facts:

| Address | Evidence |
|---|---|
| `0x00466a70` | `cmp byte ptr [ecx+83Ah], 0`; if set, return. This is the Application `m_exitRequested` gate. |
| `0x00466a7d` | `mov byte ptr [ecx+839h], 0`; deactivation clears the BaramApp/Application input-active byte. |
| `0x00466a84` | Tests `ApplicationActiveGate` (`unk_67A93C`) and `g_pScreenPane` (`dword_67A7CC`). |
| `0x00466a96` | Loads `g_pApplication`; clears `g_pApplication+0x838`; this is `Application::m_isRunning`. |
| `0x00466aa9` | Pushes `g_pApplication+0x828` and `6`; calls `ShowWindow`, matching `SW_MINIMIZE`. |
| `0x00466abb` | Calls `sub_5576A0(g_pScreenPane)`, accepted as `ScreenPane::RestoreDirectDrawState()`. |
| `0x00466ac0` | If `g_pEventMan` is non-null, calls `sub_4A90D0(g_pEventMan, 0)`. |
| `0x00466ad1` | If `g_pKeySpeedMgr` is non-null, calls `KeySpeedMgr::RestoreSystemKeyboardSettings()`. |
| `0x00466ae0` | If `g_activeMapPane` is non-null, calls `MapPane::ClearQueuedMapStateRefresh()`. |
| `0x00466aef` | Loads `g_pConfig` and `g_pSoundManager`. |
| `0x00466afb` | If `g_pConfig+0x28de48` is set, calls the app-focus SFX suspend helper at `0x0057a780`. |
| `0x00466b10` | If `g_pConfig+0x291908` is zero, tail-jumps to the app-deactivation music suspend block at `0x0057a450`. |
| `0x0057a450` | If `g_pSoundManager+0x0c` is set, sets `g_pSoundManager+0x04`; disables MIDI playback; clears `g_pSoundManager+0x0c`; calls `SoundManager::SetStreamVolume(g_pSoundManager+0x10)`. |

### Neighbor And Field Searches

The sibling activation function at `0x004669c0` also decompiles successfully in the current MCP session. It mirrors UID0002GK by checking `this+0x83a`, setting `g_pEventMan` active with argument `1`, setting `g_pApplication+0x838`, restoring the window with `ShowWindow(..., 9)`, restoring keyboard/input state, and using the SoundManager/MidiPlayer activation tail at `0x0057a480`.

Bounded MCP searches in the Application/BaramApp range support the field interpretations:

| Search | Evidence |
|---|---|
| `83Ah` in `0x00463000-0x00468000` | Constructor clears the byte, exit helpers set it, `RequestExit` sets it, the getter reads it, Main WndProc gates on it, and both activation/deactivation callbacks test it. This supports `m_exitRequested`. |
| `839h` in `0x00463000-0x00468000` | Main WndProc tests/sets this byte around key and mouse dispatch; UID0002GK clears it. This supports a window/input-active field. |
| `838h` in broader code | Constructor and OnActivate set it, UID0002GK clears it, and `Application::IsRunning()` reads it. This supports `m_isRunning`. |

## Support Evidence Checked

Relevant by-* documents and prior executed reports were checked as support evidence only:

| Support item | Current useful evidence |
|---|---|
| `by-class/Application.md` | Defines `m_isRunning` at `+0x838`, `m_exitRequested` at `+0x83a`, and main window handle at `+0x828`. Notes that `+0x839` is distinct from `m_isRunning`. |
| `by-class/BaramApp.md` | Owns activation/deactivation behavior under Application/BaramApp. Still contains stale language that Hex-Rays fails on the tail chunks; this report should supersede that blocker for UID0002GK. |
| `by-file/Application.md` | Correct source file placement is `app/Application.cpp` / `app/Application.h`; Application owns the BaramApp shell behavior. |
| `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` | Confirms `g_pApplication`, including `m_isRunning` and main window handle consumers. |
| `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md` | Confirms `ApplicationActiveGate` at `0x0067a93c` as an Application lifecycle gate used by deactivation and ScreenPane restore. |
| `by-global/g_pScreenPane.md` and `by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md` | Confirm `g_pScreenPane` and accepted source-facing `ScreenPane::RestoreDirectDrawState()`. |
| `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` | Confirms `g_pEventMan`. The helper at `0x004a90d0` still needs a source-facing helper name incorporated. |
| `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`, `by-global/g_pKeySpeedMgr.md`, and `by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md` | Confirm `g_pKeySpeedMgr` and exact helper `KeySpeedMgr::RestoreSystemKeyboardSettings()`. |
| `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md` and `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md` | Confirm `g_activeMapPane` and exact helper `MapPane::ClearQueuedMapStateRefresh()`. |
| `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | Confirms `g_pConfig`, `m_soundEffectsEnabled` at `+0x28de48`, `m_musicEnabled` at `+0x28de50`, and the music source/playback-mode cluster at `+0x291908`. |
| `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md` and `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | Confirm `g_pSoundManager`, `SoundManager::SetStreamVolume`, the app-focus SFX helper at `0x0057a780`, and the app-deactivation music tail at `0x0057a450`. |
| `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md`, `by-global/g_pMidiPlayer.md`, and `by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md` | Confirm `g_pMidiPlayer` and exact helper `MidiPlayer::DisableMidiPlayback()`. |

Prior reports referenced by support docs, including B005 Application state work, B002/B005 ScreenPane/Surface restore work, and SoundManager/MusicControl work, were used as historical support. Current MCP evidence is the authority for UID0002GK's function body, tail ownership, and source-readiness.

## Blocker Reanalysis

| Previous/open blocker | Current finding | Disposition |
|---|---|---|
| BaramApp/Application ownership split | Vtable refs, Application class docs, and source file docs keep this in Application/BaramApp. No evidence moves it to ScreenPane, SoundManager, or MapPane. | Resolved for implementation; keep owner/emitter `00000V`. |
| Class layout and secondary-base spelling | UID0002GK receives primary `this`; it tests Application/BaramApp bytes at `+0x83a` and `+0x839`. Secondary vtable/destructor issues do not block this primary callback. | Resolved for this target; no secondary-base C++ spelling needed in the formal block. |
| Exact method signature | Vtable-only reachability and sibling OnActivate support `void BaramApp::OnDeactivate()`. | Use that signature in formal C++. |
| Global names | All major globals have accepted support docs: `g_pApplication`, `ApplicationActiveGate`, `g_pScreenPane`, `g_pEventMan`, `g_pKeySpeedMgr`, `g_activeMapPane`, `g_pConfig`, `g_pSoundManager`, `g_pMidiPlayer`. | Resolved, except EventMan helper naming remains source-facing/inferred. |
| Audio-tail/source split | Current Hex-Rays includes tail `0x0057a450` in `sub_466A70`; `xrefs_to 0x0057a450` has only the code ref from UID0002GK. | Treat the tail as UID0002GK-owned source behavior, not as a no-code covered range. |
| ScreenPane/KeySpeedMgr/Surface/MusicControl dependencies | ScreenPane, KeySpeedMgr, MapPane, MidiPlayer, Config, and SoundManager support pages now provide enough names for first-draft source. | Resolved for first draft. |
| Caller/reachability and vtable route | No code callers; two vtable data refs. | Source shape is callback/virtual method. |
| Final C++ readiness | The old empty-emitter rationale is stale. Remaining names are narrow and can be ledgered. | Insert first-draft C++. |

## Naming Analysis

### Formal Function Name

Use `BaramApp::OnDeactivate()`.

Reasons:

- The target by-memory name and class docs already identify the role as BaramApp deactivation.
- The function has no ordinary code caller and is reached through vtable data refs, matching a virtual/window lifecycle callback.
- The sibling `0x004669c0` is the activation counterpart and current MCP shows mirrored behavior.
- A free helper name such as `ApplicationDeactivate` would lose the vtable/member-call evidence. A ScreenPane, SoundManager, MapPane, EventMan, or MidiPlayer member name would misplace the source owner because those objects are only dependencies.

### Application Field Names

Use current Application class names where already established:

| Offset | Recommended name | Evidence |
|---|---|---|
| `+0x838` | `m_isRunning` | Constructor/OnActivate set, UID0002GK clears, `Application::IsRunning()` reads. |
| `+0x83a` | `m_exitRequested` | Constructor clears, exit helpers set, `Application::IsExitRequested()` reads, UID0002GK gates on it. |
| `+0x839` | `m_windowInputActive` | Main WndProc tests/sets around key and mouse input delegation; UID0002GK clears it. Exact original spelling is unrecovered, so this should be presented as a source-facing field name rather than a recovered symbol. |

### Dependency Helper Names

Use accepted exact helper names where already present:

| Raw target | Formal name |
|---|---|
| `sub_5576A0` | `ScreenPane::RestoreDirectDrawState()` |
| `sub_4EFF30` | `KeySpeedMgr::RestoreSystemKeyboardSettings()` |
| `sub_505CC0` | `MapPane::ClearQueuedMapStateRefresh()` |
| `sub_5260D0` | `MidiPlayer::DisableMidiPlayback()` |
| `sub_57A340` | `SoundManager::SetStreamVolume()` |

Use these source-facing names for helpers that are still underdocumented:

| Raw target | Recommended source-facing name | Justification |
|---|---|---|
| `sub_4A90D0(g_pEventMan, 0)` | `EventMan::ResetInputState(false)` | The helper clears an EventMan input/event-state block and sibling activation passes `true`; current helper body does not consume the bool, but the call-site argument should be preserved as the app-active/deactive semantic. |
| `sub_57A780(g_pSoundManager)` | `SoundManager::SuspendSoundEffectsForApplicationDeactivate()` | It is only called in UID0002GK when `g_pConfig->m_soundEffectsEnabled` is true; it clears the SoundManager SFX active byte and records a restore/defer flag if needed. |

The music tail should be represented inline in `BaramApp::OnDeactivate()` rather than hidden behind an unsupported standalone helper. It is target-owned and directly performs the SoundManager/MidiPlayer state transition.

## Formal RECONSTRUCTION_CPP Recommendation

Insert only this C++ text into the target's formal `RECONSTRUCTION_CPP` block during implementation:

```cpp
void BaramApp::OnDeactivate()
{
    if (m_exitRequested)
        return;

    m_windowInputActive = false;

    if (ApplicationActiveGate == 0 && g_pScreenPane != NULL) {
        g_pApplication->m_isRunning = false;
        ::ShowWindow(g_pApplication->GetMainWindowHandle(), SW_MINIMIZE);
        g_pScreenPane->RestoreDirectDrawState();
    }

    if (g_pEventMan != NULL)
        g_pEventMan->ResetInputState(false);

    if (g_pKeySpeedMgr != NULL)
        g_pKeySpeedMgr->RestoreSystemKeyboardSettings();

    if (g_activeMapPane != NULL)
        g_activeMapPane->ClearQueuedMapStateRefresh();

    if (g_pConfig->m_soundEffectsEnabled)
        g_pSoundManager->SuspendSoundEffectsForApplicationDeactivate();

    if (g_pConfig->m_musicPlaybackMode == 0) {
        if (g_pSoundManager->m_musicPlaybackEnabled)
            g_pSoundManager->m_restoreMusicOnActivate = true;

        g_pMidiPlayer->DisableMidiPlayback();
        g_pSoundManager->m_musicPlaybackEnabled = false;
        g_pSoundManager->SetStreamVolume(g_pSoundManager->m_streamVolume);
    }
}
```

Notes for implementation:

- Do not insert this report heading or any markdown fence into the by-memory formal block. Insert the C++ only, preserving the validator's formal block delimiters.
- The `SW_MINIMIZE` source constant maps to the observed `ShowWindow` argument `6`.
- `GetMainWindowHandle()` is the source-facing accessor for `g_pApplication+0x828`; direct field access would also match the binary, but the accessor is already used by accepted ScreenPane C++.
- The target C++ intentionally includes the music tail behavior inline because current MCP proves `0x0057a450` is owned by UID0002GK.

## Target And Support Documentation Updates Needed

Implement these after supervisor acceptance, under short leases:

| File | Required update |
|---|---|
| `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md` | Insert the formal C++ block above; update metadata to `COMPLETION:90`, `CONFIDENCE:92`, and `EMITTER_POSITION_OPTIONAL:40`; replace stale "do not emit final C++" and Hex-Rays/tail-blocker language with current MCP decompile/tail ownership proof; add the field/global/helper mapping and score rationale. |
| `by-class/BaramApp.md` | Update UID0002GK child/behavior notes to say current MCP decompiles the function and the audio tail is UID0002GK-owned; add/align `m_windowInputActive` as the source-facing name for `+0x839`; historicalize stale "Hex-Rays fails" wording for this target. |
| `by-class/Application.md` | Add or align the UID0002GK evidence for `m_exitRequested`, `m_isRunning`, and distinct `m_windowInputActive`; keep `+0x839` distinct from `m_isRunning`. |
| `by-file/Application.md` | Add UID0002GK as source-ready in `app/Application.cpp`, with `BaramApp::OnDeactivate()` after activation and before later lifecycle helpers. |
| `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` or the EventMan aggregate helper page | Add the `sub_4A90D0` source-facing helper note/name used by the formal C++: `EventMan::ResetInputState(bool applicationActive)`, with deactivation argument `false` and activation argument `true`. |
| `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | Add the UID0002GK-specific app-deactivation SFX helper name and note that the `0x0057a450` raw app-deactivation music tail is represented inline in `BaramApp::OnDeactivate()` rather than treated as a standalone owned emitter. |
| `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | If not already explicit enough for the implementation callback, add UID0002GK consumers for `m_soundEffectsEnabled` and `m_musicPlaybackMode`/`+0x291908` guard. |
| `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md` and `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md` | Add only narrow UID0002GK consumer notes if the formal C++ references need local support beyond the existing SoundManager/MidiPlayer playback pages. |

Do not edit generated `Application.cpp`; use validators to refresh it.

## Validator Plan For Implementation Callback

Run scoped validators after accepted edits. Exact command set may be adjusted by the supervisor callback, but the implementation should include at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [0002GK-BaramAppOnDeactivate-empty-emitter-source-quality-removed.md](0002GK-BaramAppOnDeactivate-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If additional support docs are edited, run matching scoped file validators for those docs. After the target validator finishes with generated refresh, inspect `auto-generated/NexusTK/app/Application.cpp` to prove UID0002GK no longer emits the Empty Emitter Marker and that the generated metadata reflects the new score.

## Implementation Callback Results

Accepted details were applied on 2026-06-29 under short B008 leases. Required files were initially blocked by active Application/BaramApp/Application-file leases from other agents; B008 waited/rechecked until the required paths became free, then leased only the immediate edit/validator files. A later B002 lease on `by-file/Application.md` was also waited out before validating that page. `tools/leaser/Agents/current_leases.md` was re-read after release and showed no active leases.

Changed by-* docs:

| File | Proof |
|---|---|
| `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md` | Metadata now `90/92`, `EMITTER_POSITION_OPTIONAL:40`; formal block contains only `void BaramApp::OnDeactivate()` C++; stale Hex-Rays/tail blocker historicalized; current MCP/tail ownership, helper mapping, rejected alternatives, and score rationale incorporated. |
| `by-class/BaramApp.md` | UID0002GK child row now `90/92` and source-ready; `m_windowInputActive`, decompile success, inline tail ownership, stale tail-blocker historicalization, and behavior notes incorporated. |
| `by-class/Application.md` | Added UID0002GK support note, `m_windowInputActive` distinct from `m_isRunning`, `m_exitRequested` guard, `m_isRunning` writer proof, dependency-owner boundaries, and B008 source-quality sync. |
| `by-file/Application.md` | Added UID0002GK as source-ready `BaramApp::OnDeactivate()` in `NexusTK/app/Application.cpp`, route-table row, and change-log proof. |
| `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` | Added `EventMan::ResetInputState(bool applicationActive)` support note with UID0002GK deactivation argument `false` and sibling activation argument `true`. |
| `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | Added `SoundManager::SuspendSoundEffectsForApplicationDeactivate()` for `0x0057a780` and recorded `0x0057a450` as UID0002GK inline music tail rather than a standalone SoundManager child. |

Config and MidiPlayer support docs were not edited because same-or-greater-detail support was already present for `g_pConfig` sound/music gates and `MidiPlayer::DisableMidiPlayback()`. The target and SoundManager support now contain the UID0002GK consumer proof needed for the formal C++.

Validator results:

| File | Command | command_id | command_timestamp | Result |
|---|---|---|---|---|
| UID0002GK target | `python .\tools\validator.py --mode file --file by-memory\0x00466a70-0x00466b23.BaramAppOnDeactivate.md --apply --wait-generated --queue-timeout 240` | `000000000582` | `2026-06-29T10:36:51-04:00` | exit 0, `ok: 1`, generated refresh completed. |
| `by-class/BaramApp.md` | `python .\tools\validator.py --mode file --file by-class\BaramApp.md --apply --queue-timeout 240` | `000000000586` | `2026-06-29T10:38:17-04:00` | exit 0, `ok: 1`. |
| `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` | `python .\tools\validator.py --mode file --file by-memory\0x0067a754-0x0067a758.g_pEventMan.md --apply --queue-timeout 240` | `000000000589` | `2026-06-29T10:38:25-04:00` | exit 0, `ok: 1`. |
| `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | `python .\tools\validator.py --mode file --file by-memory\0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md --apply --queue-timeout 240` | `000000000591` | `2026-06-29T10:38:45-04:00` | exit 0, `ok: 1`. |
| `by-class/Application.md` | `python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240` | `000000000602` | `2026-06-29T10:40:17-04:00` | exit 0, `ok: 1`. |
| `by-file/Application.md` | `python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240` | `000000000614` | `2026-06-29T10:42:03-04:00` | exit 0, `ok: 1`. |

Generated proof: `auto-generated/NexusTK/app/Application.cpp` header now shows `validator-command-id: 000000000614` and `validator-refreshed-at: 2026-06-29T10:42:03-04:00`. UID0002GK appears as `// UID:0002GK | by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md | Completion:90 | Confidence:92` followed by real `void BaramApp::OnDeactivate()` code. UID0002GK no longer appears as an Empty Emitter Marker.

## Claim And Incorporation Ledger

| ID | Claim / fact to apply or preserve | Evidence | Target/support doc action | Incorporation action | Verification state |
|---|---|---|---|---|---|
| C01 | UID0002GK is a BaramApp/Application virtual deactivation callback with no ordinary code callers. | `xrefs_to 0x00466a70`: data refs `0x006125fc`, `0x0061d130`, no code refs. | Target, BaramApp class, Application file. | incorporate | applied: target evidence, BaramApp child row, and Application file route-table row record vtable-only refs and no ordinary code callers. |
| C02 | Current Hex-Rays decompile succeeds and includes the `0x0057a450` audio tail in `sub_466A70`. | MCP `decompile 0x00466a70`; `xrefs_to 0x0057a450` only from `0x00466b1c`. | Target, BaramApp class, SoundManager support. | incorporate | applied: target evidence/reconstruction notes, BaramApp child row, and SoundManager support all record successful decompile and inline tail ownership. |
| C03 | Guard byte `this+0x83a` is Application `m_exitRequested`. | Application docs and bounded MCP `83Ah` search: constructor clears, exit helpers set, getter reads, WndProc and activation/deactivation test. | Target, Application class, BaramApp class. | already-present plus incorporate UID0002GK proof | applied: target formal code/prose uses `m_exitRequested`; Application class UID0002GK sync and BaramApp notes preserve the guard evidence. |
| C04 | UID0002GK clears input-active byte `this+0x839`; source-facing name should be `m_windowInputActive`. | MCP disassembly at `0x00466a7d`; WndProc `839h` search tests/sets this byte around key/mouse dispatch. | Target, Application class, BaramApp class. | incorporate | applied: target formal code/prose uses `m_windowInputActive`; Application field list and BaramApp layout notes record it as distinct from `m_isRunning`. |
| C05 | UID0002GK clears `g_pApplication->m_isRunning` and minimizes the main window when the lifecycle gate allows it. | MCP decompile/disassembly: write `g_pApplication+0x838`, `ShowWindow(g_pApplication+0x828, 6)`. | Target, Application class, g_pApplication support, Application file. | incorporate | applied: target formal code/prose, Application class sync, and Application file route notes record `m_isRunning = false` and `SW_MINIMIZE`; existing g_pApplication support already covered singleton storage. |
| C06 | `ApplicationActiveGate` and `g_pScreenPane` guard the DirectDraw restore path. | MCP disassembly and `ApplicationLifecycleFlags` / ScreenPane support docs. | Target and ScreenPane support as needed. | already-present plus incorporate UID0002GK proof | applied: target formal code/prose records the gate and ScreenPane guard; no ScreenPane edit needed because restore helper support was already same-or-greater detail. |
| C07 | `sub_5576A0` should be emitted as `ScreenPane::RestoreDirectDrawState()`. | ScreenPane restore support page formal C++; MCP call at `0x00466abb`. | Target only unless ScreenPane support needs a UID consumer note. | already-present | applied: target formal code uses `g_pScreenPane->RestoreDirectDrawState()`; ScreenPane support was already sufficient, so no support edit was needed. |
| C08 | `g_pEventMan` helper at `0x004a90d0` should be named source-facing `EventMan::ResetInputState(bool applicationActive)`. | MCP decompile/disassembly: deactivation passes `0`, activation passes `1`; helper clears EventMan input-state storage. | Target and EventMan support. | incorporate | applied: target formal code uses `ResetInputState(false)`; EventMan singleton page now documents helper name, deactivation `false`, and activation `true`. |
| C09 | `sub_4EFF30` should be emitted as `KeySpeedMgr::RestoreSystemKeyboardSettings()`. | KeySpeedMgr support formal C++; MCP call from UID0002GK. | Target only unless consumer note is desired. | already-present | applied: target formal code uses `RestoreSystemKeyboardSettings()`; KeySpeedMgr support was already sufficient, so no support edit was needed. |
| C10 | `sub_505CC0` should be emitted as `MapPane::ClearQueuedMapStateRefresh()`. | MapPane support formal C++; MCP call from UID0002GK. | Target only unless consumer note is desired. | already-present | applied: target formal code uses `ClearQueuedMapStateRefresh()`; MapPane support was already sufficient, so no support edit was needed. |
| C11 | `g_pConfig->m_soundEffectsEnabled` at `+0x28de48` gates the app-focus SFX suspend call. | Config support and MCP decompile/disassembly. | Target, Config support, SoundManager playback support. | incorporate | applied: target formal code and SoundManager support record the SFX gate/use; Config support was already sufficient and not edited. |
| C12 | `sub_57A780` should be represented as `SoundManager::SuspendSoundEffectsForApplicationDeactivate()`. | MCP decompile of `0x0057a780`; SoundManager support inventory describes it as app-focus SFX mute/defer helper. | Target and SoundManager playback support. | incorporate | applied: target formal code uses the accepted helper name; SoundManager playback support now names `0x0057a780` accordingly. |
| C13 | `g_pConfig+0x291908` is the music source/playback-mode guard used before the music suspend tail. | Config support and MCP decompile/disassembly. | Target and Config support. | incorporate | applied: target formal code uses `g_pConfig->m_musicPlaybackMode == 0`; Config support was already sufficient and not edited. |
| C14 | The music tail sets `m_restoreMusicOnActivate` if music was active, disables MIDI playback, clears music playback active, and reapplies stream volume. | MCP tail decompile at `0x0057a450`; MidiPlayer and SoundManager support docs. | Target and SoundManager/MidiPlayer support. | incorporate | applied: target formal code includes the inline tail behavior; SoundManager support records UID0002GK inline tail; MidiPlayer support already had `DisableMidiPlayback()`. |
| C15 | `sub_5260D0` should be emitted as `MidiPlayer::DisableMidiPlayback()`. | MidiPlayer playback toggle support formal C++. | Target only unless consumer note is desired. | already-present | applied: target formal code uses `DisableMidiPlayback()`; MidiPlayer support was already sufficient, so no support edit was needed. |
| C16 | `sub_57A340` should be emitted as `SoundManager::SetStreamVolume()`. | SoundManager playback support inventory/decompile. | Target and SoundManager support. | already-present plus incorporate UID0002GK use | applied: target formal code uses `SetStreamVolume(...)`; SoundManager support now records UID0002GK use in the inline tail. |
| C17 | Existing generated `Application.cpp` UID0002GK empty marker is stale and must be cleared by validator refresh, not manual edit. | Generated header/check showed command id `000000000466`, refreshed `2026-06-29T09:01:40-04:00`, UID0002GK `80/90 Empty Emitter Marker`. | Implementation proof only. | incorporate | applied: validators refreshed generated `Application.cpp`; final header is `validator-command-id: 000000000614`, UID0002GK appears at `90/92` with real `BaramApp::OnDeactivate()` code and no empty marker. |
| C18 | Stale target/class claims that Hex-Rays cannot recover the tail should be historicalized for UID0002GK. | Current MCP decompile succeeds and includes the tail. | Target and BaramApp class. | reject-stale / historicalize | applied: target reconstruction notes and BaramApp child row/change log explicitly historicalize old Hex-Rays/tail-blocker wording. |
| C19 | `EMITTER_POSITION_OPTIONAL` should be filled with `40`. | Target prose already states optional position 40; generated Application order expects activation/deactivation lifecycle placement. | Target metadata. | incorporate | applied: target metadata is `EMITTER_POSITION_OPTIONAL:40`; validator command `000000000582` recorded registry update for position `40`. |
| C20 | The formal C++ block should be inserted as code only, without report markdown headings or fences. | Rule 26/by-structure formal block requirement. | Target formal block during implementation. | incorporate | applied: target formal block contains only the `void BaramApp::OnDeactivate()` C++ body between validator delimiters; no report heading/fence was inserted. |

## Implementation Tracking Checklist

- [x] Lease only the immediate target/support files selected for editing, after checking `tools/leaser/Agents/current_leases.md`. Proof: B008 checked leases, waited through active B010/B012/B007/B002 conflicts as needed, leased only the immediate by-* edit/validator paths, and released leases after validator batches.
- [x] Update `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md` metadata to `COMPLETION:90`, `CONFIDENCE:92`, and `EMITTER_POSITION_OPTIONAL:40`. Proof: target metadata changed and validator `000000000582` recorded `completion_update`, `confidence_update`, and position registry update.
- [x] Insert only the recommended C++ function text into the target formal `RECONSTRUCTION_CPP` block, preserving validator delimiters and omitting markdown fences/headings. Proof: generated `Application.cpp` emits real `void BaramApp::OnDeactivate()` code from the formal block.
- [x] Replace target stale "do not emit final C++" / old Hex-Rays-tail-blocker language with current MCP decompile and tail-ownership evidence. Proof: target now records current successful decompile, `xrefs_to 0x0057a450` only from `0x00466b1c`, and stale blocker historicalization.
- [x] Update the target behavior/global/helper tables to include all ledger claims C01 through C20. Proof: target behavior, IDA evidence, reconstruction notes, score rationale, and change log incorporate the accepted field/global/helper/tail/score details.
- [x] Update `by-class/BaramApp.md` for current UID0002GK decompile success, source-ready status, `m_windowInputActive`, and historicalized stale tail-blocker wording. Proof: BaramApp child matrix row is `90/92`, behavior notes and evidence include UID0002GK decompile/tail proof, validator `000000000586` returned `ok: 1`.
- [x] Update `by-class/Application.md` to preserve `m_isRunning`, `m_exitRequested`, and distinct `m_windowInputActive` evidence for UID0002GK. Proof: Application field list and B008 source-quality sync include all three, validator `000000000602` returned `ok: 1`.
- [x] Update `by-file/Application.md` so `BaramApp::OnDeactivate()` is listed as source-ready in `app/Application.cpp` at the accepted lifecycle position. Proof: Application file route page has UID0002GK behavior note, route-table row, and change log; validator `000000000614` returned `ok: 1`.
- [x] Update EventMan support with `EventMan::ResetInputState(bool applicationActive)` or an equivalent supervisor-accepted source-facing helper name, preserving deactivation argument `false`. Proof: EventMan singleton page records `0x004a90d0`, UID0002GK `false`, sibling activation `true`; validator `000000000589` returned `ok: 1`.
- [x] Update SoundManager playback support with `SoundManager::SuspendSoundEffectsForApplicationDeactivate()` and the UID0002GK-owned inline music-tail disposition. Proof: SoundManager playback page names `0x0057a780` and records `0x0057a450` as UID0002GK inline tail; validator `000000000591` returned `ok: 1`.
- [x] Add narrow Config/SoundManager/MidiPlayer consumer notes only where needed to support formal C++ names not already present. Proof: SoundManager support was edited; Config and MidiPlayer support were already sufficient for gates/helper names and were not edited, with no missing support after target/generated verification.
- [x] Run all scoped validators for edited target/support files, using `--wait-generated` on the target validator and `--queue-timeout 240`. Proof: validator commands `000000000582`, `000000000586`, `000000000589`, `000000000591`, `000000000602`, and `000000000614` all exited 0 with `ok: 1`.
- [x] Inspect generated `auto-generated/NexusTK/app/Application.cpp` after validator refresh and record proof that UID0002GK is no longer an Empty Emitter Marker and shows current score metadata. Proof: final generated header `validator-command-id: 000000000614`, `validator-refreshed-at: 2026-06-29T10:42:03-04:00`; UID0002GK line shows `Completion:90 | Confidence:92` followed by real `BaramApp::OnDeactivate()` body.
- [x] Release all leases immediately after the edit/validator batch. Proof: `python .\leaser.py B008 unlease` released B008 paths; final `current_leases.md` read showed no active leases.
- [x] Update this ledger and checklist with `applied`, `already-present`, or `excluded-with-reason` proof for every claim before returning implementation completion. Proof: ledger rows C01-C20 now contain applied/already-present/excluded proof states.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002GK-BaramAppOnDeactivate-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002GK-BaramAppOnDeactivate-empty-emitter-source-quality.md","timestamp":"2026-06-29T10:49:29","uid":"0002GK"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GK-BaramAppOnDeactivate-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0002GK-BaramAppOnDeactivate-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
