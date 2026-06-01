*** UID:00006J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InputMan

## Summary

`InputMan` is the global keyboard/mouse/IME manager. It creates and owns an IME context, tracks active input targets, and converts Win32 input and IME window messages into higher-level client events.

## Likely Original Placement

- Source: [UID:0000K6][InputMan](by-file/InputMan.md)
- Proposed path: `input/InputMan.cpp`
- Confidence: strong

## Methods

- `0x004e8af0` constructor - creates IME context, associates it with the app window, disables IME open status, reads IME properties, allocates the input-target list, and sets `g_pInputMan`.
- `0x004e8cf0` `TrackInputTarget` - adds/removes target ids and sends message `0x401` when the tracked set changes empty/non-empty state.
- `0x004e8de0` `HandleWindowMessage` - handles IME composition, candidates, open status, character dispatch, and fallback dispatch.
- `0x004e9430` `GetInputMode`.
- `0x004e9440` `SetInputMode` - changes mode and finalizes active composition when switching into mode 2.
- `0x004e9660` deleting destructor - restores IME association, destroys the owned IME context, releases list state, and clears `g_pInputMan`.

## Evidence

- IDA MCP confirms all six method boundaries and shows the constructor caller at `Application::Initialize` address `0x00464572`.
- IDA MCP shows `HandleWindowMessage` called from application message handling at `0x00465fad`.
- Generated source calls `ImmGetDefaultIMEWnd`, `ImmCreateContext`, `ImmAssociateContext`, `ImmGetContext`, `ImmNotifyIME`, and `ImmDestroyContext`.

## Open Questions

- The helper calls around `0x004a97e0-0x004a9db0` used by `HandleWindowMessage` need event-class naming before the method can be rewritten cleanly.
- Several function-pointer globals in the generated source still have `dword_69BE*` names and should be typed through the platform API docs.

## Cross-References

- File: [UID:0000K6][InputMan](by-file/InputMan.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md)
- Memory: [UID:00018E][0x004e8af0-0x004e970c.InputMan](by-memory/0x004e8af0-0x004e970c.InputMan.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: global input/IME manager purpose, original placement, six major methods, Win32 IMM API use, Application call sites, and open event-helper/global typing questions are documented; completion is capped because helper event-class naming and function-pointer globals remain unresolved. Evidence: `0x004e8af0-0x004e970c.InputMan`, Application initialization/message-handling xrefs, and IMM API calls.
