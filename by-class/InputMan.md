*** UID:00006J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Parent attachment: attached to [UID:0000K6][InputMan](by-file/InputMan.md) at position `10` because the file root is `80/84` and this refreshed class page is `82/86`.

## Observed State

```text
InputMan
  +0x00  vptr
  +0x04  default IME window handle
  +0x08  owned HIMC
  +0x0c  saved/restored app HIMC
  +0x10  IME property flags from ImmGetProperty(..., 4)
  +0x14  small composition/input state word
  +0x18  input mode
  +0x1c  input-target list pointer
```

The constructor, ordinary destructor, scalar deleting destructor, mode getter/setter, and target-tracking method all support this layout. The final source-facing names for `+0x0c`, `+0x10`, and `+0x14` remain provisional.

## Methods

| Range | Role |
| --- | --- |
| [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) | Aggregate page for the exact executable island. |
| `0x004e8af0-0x004e8c11` | Constructor; creates IME context, associates it with the app window, disables IME open status, reads IME properties, allocates the input-target list, and sets `g_pInputMan`. |
| `0x004e8c20-0x004e8ca1` | Ordinary destructor; restores the saved app IME context, destroys the owned context, releases list state, clears `g_pInputMan`, and calls base cleanup. |
| `0x004e8cf0-0x004e8dcb` | `TrackInputTarget`; adds/removes target ids and sends message `0x401` when the tracked set changes empty/non-empty state. |
| `0x004e8de0-0x004e9319` | `HandleWindowMessage`; handles IME composition, candidates, open status, character dispatch, owned-context replacement, custom `0x401` context toggling, and fallback dispatch. |
| `0x004e9430-0x004e9434` | `GetInputMode`; returns `+0x18`. |
| `0x004e9440-0x004e9485` | `SetInputMode`; changes mode and finalizes active composition when switching into mode `2`. |
| `0x004e9490-0x004e95ab` | IME helper group used by this class and IME pane code: composition finalization, composition-length query, composition-string copy, and current-context release. |
| `0x004e9650-0x004e965b` | Singleton clear helper. |
| `0x004e9660-0x004e970d` | Scalar deleting destructor; mirrors ordinary cleanup and conditionally deletes `this`. |

## Evidence

- IDA MCP confirms the modeled method/helper boundaries in the aggregate, including the previously omitted ordinary destructor at `0x004e8c20`, helper group at `0x004e9490-0x004e95ab`, singleton clear helper at `0x004e9650`, and corrected scalar deleting destructor end at `0x004e970d`.
- IDA MCP shows the constructor caller at `Application::Initialize` address `0x00464572`.
- IDA MCP shows `HandleWindowMessage` called from application message handling at `0x00465fad`.
- IDA MCP xrefs tie `g_pInputMan` at `0x0067ab44` to constructor/destructor paths, application message-loop users, IME pane code, and UI focus paths.
- IDA MCP xrefs tie the `InputMan` vtable at `0x0061c5a4` to constructor, ordinary destructor, and scalar deleting destructor stores.
- Decompilation shows direct calls to `ImmGetDefaultIMEWnd`, `ImmCreateContext`, `ImmAssociateContext`, `ImmGetContext`, `ImmSetOpenStatus`, `ImmNotifyIME`, `ImmReleaseContext`, `ImmDestroyContext`, `ImmGetOpenStatus`, and `ImmGetCompositionStringW`.

## Open Questions

- The helper calls around `0x004a97e0-0x004a9db0` used by `HandleWindowMessage` need event-class naming before the method can be rewritten cleanly.
- Several function-pointer globals in the generated source still have `dword_69BE*` names and should be typed through the platform API docs.
- The `0x004e8cc0-0x004e8cdf` keyboard-layout dispatch stub is real code in this island but is not modeled as a function by IDA; keep it documented as an unmodeled helper until the callback ownership is clearer.

## Cross-References

- File: [UID:0000K6][InputMan](by-file/InputMan.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md)
- Memory: [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: global input/IME manager purpose, original placement, six major methods, Win32 IMM API use, Application call sites, and open event-helper/global typing questions are documented; completion is capped because helper event-class naming and function-pointer globals remain unresolved. Evidence: `0x004e8af0-0x004e970c.InputMan`, Application initialization/message-handling xrefs, and IMM API calls.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the global input/IME manager unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/82`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e8af0`, `0x004e8cf0`, `0x004e8de0`, `0x004e9430`, `0x004e9440`, and `0x004e9660`; constructor and window-message callers remain the application paths at `0x00464572` and `0x00465fad`.
- 2026-06-06 A005 InputMan refresh:
  - Before: the class remained `74/82`, unparented, omitted the ordinary destructor/helper group/singleton clear helper, and linked the aggregate with stale `0x004e970c` end.
  - After: raised to `82/86`, attached to [UID:0000K6][InputMan](by-file/InputMan.md), linked the corrected [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) aggregate, and added state layout plus the full IDA-backed method/helper inventory.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, and targeted decompilation on 2026-06-06 confirmed the missing functions, corrected end boundary, constructor/window-message callers, singleton/vtable xrefs, IME API use, and remaining callback/function-pointer naming caveats.
