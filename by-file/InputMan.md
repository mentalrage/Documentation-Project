*** UID:0000K6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# InputMan

## Proposed Original Placement

- Proposed source path: `input/InputMan.cpp`
- Proposed header path: `input/InputMan.h`
- Projected reconstruction path: `NexusTK/input/InputMan.cpp`
- Confidence: strong

## Source Ownership Notes

Earlier generated views used a one-class recovered container for this module. Current ownership should be based on the IDA-backed `InputMan` class/method island and neighboring input/IME docs, not on generated container names.

## Responsibilities

`InputMan` is the process-wide Win32 input and IME manager. It owns the custom IME context, tracks UI input targets, bridges the main window procedure into text/composition/candidate events, and notifies the application when the tracked input-target set becomes empty or non-empty.

This should not be merged into `Application.cpp`: `Application` constructs and destroys it, but the implementation is large, IME-specific, and has its own state and helper routines.

Keep this separate from [UID:0000K5][IMEPanes](by-file/IMEPanes.md). `InputMan` produces and routes Win32/IMM input events, while `IMEPanes.cpp` owns the root IME pane singleton, composition/candidate/status popup panes, and focus-pane list. Also keep [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) separate: it owns Windows keyboard repeat settings, not input message routing.

## Likely File Contents

- `class InputMan`.
- Small IME helper logic currently embedded in the recovered `HandleWindowMessage` method view, such as candidate-list construction, composition string extraction, and candidate text conversion. The current `CandidateStringQueue` helper calls in this method are standard-library [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) support, not evidence for an `InputMan`-owned queue class.
- Input-manager globals:
  - `g_pInputMan`
  - `g_MessageCallback`
  - IME dispatch function pointers currently named `dword_69BE50`, `dword_69BEBC`, and `dword_69BEC0`.
- declarations for IME event emission helpers such as composition start/result/end, candidate list/close, IME open status, and character dispatch. The helper bodies should live with [UID:0000J6][Event](by-file/Event.md), because they construct `Event` records and dispatch through `g_pEventDispatcher`.

## Evidence

- IDA MCP confirms the modeled method/helper starts and sizes in the main executable island:
  - `0x004e8af0-0x004e8c11` constructor
  - `0x004e8c20-0x004e8ca1` ordinary destructor
  - `0x004e8cb0-0x004e8cdf` small message/callback helper stubs
  - `0x004e8cf0-0x004e8dcb` `TrackInputTarget`
  - `0x004e8de0-0x004e9319` `HandleWindowMessage`
  - `0x004e9430-0x004e9434` `GetInputMode`
  - `0x004e9440-0x004e9485` `SetInputMode`
  - `0x004e9490-0x004e95ab` IME composition/context helper group
  - `0x004e9650-0x004e965b` singleton clear helper
  - `0x004e9660-0x004e970d` scalar deleting destructor
- IDA MCP shows the constructor is called from `Application::Initialize` at `0x00464572`.
- IDA MCP shows `HandleWindowMessage` is called from the main application window-message path at `0x00465fad`.
- Recovered constructor evidence shows use of `ImmGetDefaultIMEWnd`, `ImmCreateContext`, `ImmAssociateContext`, `ImmGetContext`, `ImmSetOpenStatus`, `ImmReleaseContext`, and `ImmGetProperty`.
- `TrackInputTarget` sends message `0x401` through `g_MessageCallback` when active input-target state crosses empty/non-empty.
- 2026-06-07 A006 IDA MCP rechecked [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md): `dword_67AB44` is initialized to `0xffffffff` and has 18 direct xrefs. The xrefs include Application/message reads at `0x00464bff`, `0x00464d94`, `0x00465f84`, and `0x004661c7`; InputMan lifecycle writes at `0x004e8b33`, `0x004e8b3a`, `0x004e8c81`, `0x004e9650`, and `0x004e96c8`; and UI/input users at `0x004f6796`, `0x004f8ae4`, `0x005445cc`, `0x00544ebb`, `0x00544ecd`, `0x00544fa3`, `0x00590f65`, and `0x005a25e0`.
- The same singleton pass confirms `0x0067ab44-0x0067ab48` is bounded by the `g_pDATFileMgr` slot at `0x0067ab40` and a separate non-InputMan singleton slot at `0x0067ab48`.

## Migration Notes

- Keep this under the top-level `input/` folder shown in the proposed source tree unless later original-source evidence proves the project nested input under `app/`.
- Keep the IME candidate-string container name provisional. IDA now supports a `std::deque<std::wstring>`-style implementation, so reconstruct the source as ordinary wide-string/deque operations and do not add a handwritten queue implementation to `InputMan.cpp`.
- Route the now-documented event factories at `0x004a9a40-0x004a9f00` to [UID:0000J6][Event](by-file/Event.md) rather than `InputMan.cpp`.
- Keep pane-side helpers in [UID:0000K5][IMEPanes](by-file/IMEPanes.md), including `g_pIMEPane`, `IMEPane::SetFocusPane`, composition/candidate popup methods, and the candidate-string container member.
- `InputMan` depends on `Application` for the window handle, but the direction should remain app -> input rather than merging input into app.

## State And Dispatch Inventory

| Area | Current evidence | File-level decision |
| --- | --- | --- |
| Executable island | [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) records the corrected range, constructor, ordinary destructor, message/callback stubs, `TrackInputTarget`, `HandleWindowMessage`, input-mode accessors, IME helper group, singleton clear helper, and scalar deleting destructor. | Treat this as the canonical `InputMan.cpp` body, but keep final C++ blank until message-helper names and API dispatch globals are typed. |
| Class layout | [UID:00006J][InputMan](by-class/InputMan.md) documents the vptr, default IME window, owned/saved HIMC fields, IME property flags, state word, input mode, and input-target list pointer. | Use these as working field roles; do not promote final source-facing names for `+0x0c`, `+0x10`, or `+0x14` yet. |
| Singleton | [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) owns the active input-manager pointer, with constructor/destructor/clear-helper and UI/IME/application xrefs. | Declare with the input subsystem, likely through `InputMan.h` or a small input-system header. |
| Vtable/read-only data | [UID:00025K][0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData](by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md) records the `InputMan` locator/vtable boundary before InterfaceEfx data. | Regenerate from the `InputMan` class declaration; do not hand-author read-only vtable bytes. |
| Windows/IMM dispatch table | [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) and adjacent dispatch-slot docs identify `ImmGetCompositionStringW`, `ImmGetCandidateListW`, `SendMessageW`, and related wide API pointers used by this file. | Keep as platform/API dispatch state initialized by `PlatformApi`/UniAPI support; type the consumers in `InputMan` instead of moving the table here. |
| Event factories | InputMan calls event helper bodies in the `0x004a97e0-0x004a9f00` family. | Route helper bodies to [UID:0000J6][Event](by-file/Event.md); `InputMan` should only call them while translating Win32/IME messages. |
| Pane-side IME state | `g_pIMEPane`, composition/candidate pane methods, focus-list state, and candidate-string member ownership are documented under [UID:0000K5][IMEPanes](by-file/IMEPanes.md). | Keep `InputMan` as the Win32/IMM producer/router and `IMEPanes.cpp` as the UI consumer/display side. |

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `86` | The file page now summarizes original placement, responsibilities, full executable inventory, class state, singleton storage/xref evidence, vtable anchors, Windows/IMM dispatch table relationship, event-factory boundary, IME-pane boundary, and remaining migration constraints. It remains below final-source quality because `HandleWindowMessage` helper names, callback/global function-pointer types, and several field names are still provisional. |
| Confidence | `89` | Confidence is strong because class, memory, global-storage, and read-only pages agree on the constructor/destructor/message-routing behavior, singleton/vtable ownership, and Application call paths. It is not higher because the unmodeled `0x004e8cc0` stub and API dispatch globals still need final typing. |

## Parent-Gate Note

No canonical `by-global/g_pInputMan.md` page exists in this documentation tree, and A006 could not lease that missing path because the leaser rejects non-existent files. Under the Batch 035 parent-gated rule, this existing file page is the direct source owner for the singleton declaration; it now clears `85/85`, so [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) can attach here unless a future leased by-global parent is created and promoted.

## Cross-References

- Class: [UID:00006J][InputMan](by-class/InputMan.md)
- Neighboring files: [UID:0000K5][IMEPanes](by-file/IMEPanes.md), [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), [UID:0000HG][Application](by-file/Application.md), [UID:0000J6][Event](by-file/Event.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Memory: [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md)
- Data: [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md), [UID:00025K][0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData](by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md), [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md)
- Type support: [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)

## Changes

- 2026-06-05: Assigned projected reconstruction path `NexusTK/input/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree place `InputMan.cpp` under `input/`.
  - After: set the validator path to `NexusTK/input/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `InputMan.cpp` under `input`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x004e8af0` as a real function of size `0x121`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: input/IME manager responsibilities, Win32/IMM bridge, method starts, application/message callers, IME pane boundary, event factory routing, and candidate-string template caveat are documented; completion is lower because globals and per-message branches still need fuller detailed documentation.
- 2026-06-06 A005 memory-range refresh:
  - Before: the file page still mentioned a generated recovered container, listed only the older six-method inventory, and linked the stale `0x004e8af0-0x004e970c` aggregate path.
  - After: replaced the generated-container note with IDA-backed ownership guidance, expanded the method/helper list, and linked the corrected [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) aggregate.
  - Evidence: IDA MCP on 2026-06-06 confirmed the ordinary destructor, helper group, singleton clear helper, and scalar deleting destructor end at `0x004e970d`; completion/confidence remain `80/84` because event helper names and global callback types are still open.
- 2026-06-07 file-level inventory pass:
  - Before: the file page had the corrected method list but did not summarize state/global/read-only/API-dispatch ownership at the parent level.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`, with state/dispatch inventory and score-rationale sections.
  - Evidence: existing class, memory, global, and read-only pages now cover the exact executable island, `InputMan` field roles, `g_pInputMan`, `InputMan` vtable/read-only boundary, Windows/IMM dispatch pointer table relationship, event-factory exclusion, and IME-pane boundary. Scores stay below final-source quality because `HandleWindowMessage` helper names, callback/API pointer types, and several field names remain unresolved.
- 2026-06-07 A006 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`, below the stricter Batch 035 direct-parent gate for the `g_pInputMan` singleton storage child.
  - After: `COMPLETION:86`, `CONFIDENCE:89`.
  - Evidence: live IDA MCP rechecked the initialized singleton storage, all 18 direct xrefs, InputMan lifecycle writes/clears, UI/Application/input users, and adjacent-slot boundaries. A missing `by-global/g_pInputMan.md` parent could not be leased/created, so this file page is documented as the direct source owner used for assignment.
