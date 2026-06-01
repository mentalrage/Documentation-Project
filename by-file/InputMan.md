*** UID:0000K6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# InputMan

## Proposed Original Placement

- Proposed source path: `input/InputMan.cpp`
- Proposed header path: `input/InputMan.h`
- Confidence: strong

## Current Wave3 Containers

- `class_InputMan.cpp`

## Responsibilities

`InputMan` is the process-wide Win32 input and IME manager. It owns the custom IME context, tracks UI input targets, bridges the main window procedure into text/composition/candidate events, and notifies the application when the tracked input-target set becomes empty or non-empty.

This should not be merged into `Application.cpp`: `Application` constructs and destroys it, but the implementation is large, IME-specific, and has its own state and helper routines.

Keep this separate from [UID:0000K5][IMEPanes](by-file/IMEPanes.md). `InputMan` produces and routes Win32/IMM input events, while `IMEPanes.cpp` owns the root IME pane singleton, composition/candidate/status popup panes, and focus-pane list. Also keep [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) separate: it owns Windows keyboard repeat settings, not input message routing.

## Likely File Contents

- `class InputMan`.
- Small IME helper logic currently embedded in the generated `HandleWindowMessage` method view, such as candidate-list construction, composition string extraction, and candidate text conversion. The current `CandidateStringQueue` helper calls in this method are standard-library [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) support, not evidence for an `InputMan`-owned queue class.
- Input-manager globals:
  - `g_pInputMan`
  - `g_MessageCallback`
  - IME dispatch function pointers currently named `dword_69BE50`, `dword_69BEBC`, and `dword_69BEC0`.
- declarations for IME event emission helpers such as composition start/result/end, candidate list/close, IME open status, and character dispatch. The helper bodies should live with [UID:0000J6][Event](by-file/Event.md), because they construct `Event` records and dispatch through `g_pEventDispatcher`.

## Evidence

- Wave3 reports six active methods and no disabled methods.
- IDA MCP confirms all six Wave3 method starts as functions:
  - `0x004e8af0-0x004e8c11` constructor
  - `0x004e8cf0-0x004e8dcb` `TrackInputTarget`
  - `0x004e8de0-0x004e9319` `HandleWindowMessage`
  - `0x004e9430-0x004e9433` `GetInputMode`
  - `0x004e9440-0x004e9485` `SetInputMode`
  - `0x004e9660-0x004e970d` deleting destructor
- IDA MCP shows the constructor is called from `Application::Initialize` at `0x00464572`.
- IDA MCP shows `HandleWindowMessage` is called from the main application window-message path at `0x00465fad`.
- Generated source shows the constructor uses `ImmGetDefaultIMEWnd`, `ImmCreateContext`, `ImmAssociateContext`, `ImmGetContext`, `ImmSetOpenStatus`, `ImmReleaseContext`, and `ImmGetProperty`.
- `TrackInputTarget` sends message `0x401` through `g_MessageCallback` when active input-target state crosses empty/non-empty.

## Migration Notes

- Create a real `input/` folder in the proposed tree, or place this under `app/input/` if the final tree avoids a top-level input folder.
- Keep the IME candidate-string container name provisional. IDA now supports a `std::deque<std::wstring>`-style implementation, so reconstruct the source as ordinary wide-string/deque operations and do not add a handwritten queue implementation to `InputMan.cpp`.
- Route the now-documented event factories at `0x004a9a40-0x004a9f00` to [UID:0000J6][Event](by-file/Event.md) rather than `InputMan.cpp`.
- Keep pane-side helpers in [UID:0000K5][IMEPanes](by-file/IMEPanes.md), including `g_pIMEPane`, `IMEPane::SetFocusPane`, composition/candidate popup methods, and the candidate-string container member.
- `InputMan` depends on `Application` for the window handle, but the direction should remain app -> input rather than merging input into app.

## Cross-References

- Class: [UID:00006J][InputMan](by-class/InputMan.md)
- Neighboring files: [UID:0000K5][IMEPanes](by-file/IMEPanes.md), [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), [UID:0000HG][Application](by-file/Application.md), [UID:0000J6][Event](by-file/Event.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Memory: [UID:00018E][0x004e8af0-0x004e970c.InputMan](by-memory/0x004e8af0-0x004e970c.InputMan.md)
- Type support: [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: input/IME manager responsibilities, Win32/IMM bridge, method starts, application/message callers, IME pane boundary, event factory routing, and candidate-string template caveat are documented; completion is lower because globals and per-message branches still need fuller detailed documentation.
