*** UID:00004O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EventMan

## Summary

`EventMan` is the process-wide input event producer. It converts cursor, mouse button, mouse wheel, keyboard, and IME composition state into temporary `Event` records and dispatches them through `g_pEventDispatcher`.

The class also owns the static key translation data copied from [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md). B001-041 live IDA recheck confirms those two `0x100`-byte tables feed only the EventMan constructor, and the resulting object fields are consumed by the EventMan key down/release methods.

## Likely Original Placement

- Source: [UID:0000J6][Event](by-file/Event.md)
- Proposed path: `ui/core/Event.cpp`
- Confidence: strong that it belongs with the event object/factory code; medium that it was not split into a separate `EventMan.cpp`.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x004a8b40-0x004a8f13` | constructor | Initializes `TimerHandler`, installs `g_pEventMan`, hides/centers/clips the hardware cursor, and builds key/modifier translation tables. |
| `0x004a9090-0x004a90a5` | `GetCursorPosition` | Returns stored cursor coordinates. |
| `0x004a9100-0x004a9115` | `ForwardCursorEvent` | Thin wrapper over cursor-event dispatch. |
| `0x004a9120-0x004a925a` | `DispatchPointerThresholdEvent` | Emits left-button press or double-click events after movement/time threshold checks. |
| `0x004a9260-0x004a9356` | `DispatchLeftButtonReleaseSequence` | Emits left-button release state. |
| `0x004a9360-0x004a949a` | `DispatchRightButtonThresholdEvent` | Emits right-button press or double-click events after threshold checks. |
| `0x004a94a0-0x004a9596` | `DispatchRightButtonReleaseSequence` | Emits right-button release state. |
| `0x004a95a0-0x004a969f` | `DispatchMouseWheelSequence` | Emits mouse-wheel events with position, modifier, delta, and tick fields. |
| `0x004a96a0-0x004a97dc` | `DispatchKeyCharEvent` | Updates key/modifier state, translates virtual keys, handles `Alt+0x88` app-exit, and dispatches key-down event type `8`. |
| `0x004a97e0-0x004a989a` | `DispatchCharEvent` | Dispatches Win32 `WM_CHAR` text input as event type `10`. |
| `0x004a98a0-0x004a99db` | `HandleKeyRelease` | Clears key/modifier state and runs the full-screen spacebar release gate; IDA decompile shows no `DispatchEvent` call in this method. |
| `0x004a9ae0-0x004a9c04` | `DispatchCompositionTextEvent` | Copies up to 128 UTF-16 chars into a composition-text event and dispatches type `10` with subcode `0`. |
| `0x004aa200-0x004aa22b` | `OnTimerTick` | Dispatches current cursor position and reschedules its 20 ms timer. |
| `0x004aa3b0-0x004aa46b` | `DispatchCursorEvent` | Stores cursor coordinates and dispatches event type `0`. |
| `0x004ab440-0x004ab476` | scalar deleting destructor | Clears `g_pEventMan`, restores base vtable state, destroys `TimerHandler`, and conditionally frees storage. |

## Event Types Observed

| Type | Producer | Meaning |
| --- | --- | --- |
| `0` | `DispatchCursorEvent` | cursor/move update |
| `1`, `2`, `3` | left-button methods | left press/double/release family |
| `4`, `5`, `6` | right-button methods | right press/double/release family |
| `7` | `DispatchMouseWheelSequence` | mouse wheel |
| `8` | `DispatchKeyCharEvent` | key down / translated key event |
| `9` | `HandleKeyRelease` | key release record is prepared, but not dispatched by this binary path |
| `10` | `DispatchCharEvent`, `DispatchCompositionTextEvent` | character/composition text |

## Static Data And Owned State

| Item | Evidence | Ownership decision |
| --- | --- | --- |
| [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md) | Live IDA `xrefs_to` reports one xref to `0x0066d888` at `0x004a8cfd` and one xref to `0x0066d988` at `0x004a8d1d`, both in `EventMan::EventMan` (`0x004a8b40`). Constructor decompilation copies each source table with size `0x100` into `this + 0x420` and `this + 0x520`; keyboard down/release methods use EventMan translation/state arrays at `this + 0x620`, `this + 0x820`, and `this + 0x920`. | Direct class-owned source-declared table pair. Attach the memory child to this class, not to `InputMan`, `EventDispatcher`, or the broader `.data` section. |
| `g_pEventMan` singleton storage | Constructor stores the singleton during `Application::Initialize`, and the scalar deleting destructor clears it. | Class lifecycle state; exact storage remains documented separately under the global/memory pages. |

## Evidence

- IDA MCP confirms all listed function starts and exact ends.
- IDA MCP shows `EventMan::EventMan` is constructed from `Application::Initialize` at `0x0046463f` after `EventDispatcher` construction.
- IDA MCP shows `OnTimerTick` is reached through virtual/timer dispatch rather than a direct call, while `DispatchCursorEvent` is called by `ForwardCursorEvent` and `OnTimerTick`.
- 2026-06-11 B001 live IDA `decompile 0x004a8b40` shows the constructor configures singleton state, cursor policy, key maps, modifier maps, and event-building tables without delegating ownership to `InputMan` or `EventDispatcher`.
- 2026-06-11 B001 live IDA `decompile 0x004a96a0` and `0x004a98a0` show key down/release methods using the constructor-built keyboard state and fallback translation arrays, including reads from `this + 0x620` when `ToAscii` does not produce one byte.
- IDA decompile of `0x004a98a0` matches the generated no-dispatch key-release behavior and the special `UserPane` spacebar-release gate.

## Placement Notes

- Keep `EventMan` separate from [UID:0000K6][InputMan](by-file/InputMan.md). `InputMan` owns Win32/IMM message handling and calls into this event layer; `EventMan` owns event object construction and dispatch.
- Keep it near [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), but do not merge the responsibilities: `EventDispatcher` routes ready events, while `EventMan` produces event records.
- The adjacent free helpers at `0x004a9a40-0x004aa1b3` build IME and packet-style event records. They probably belong in the same `Event.cpp` source module even though they are not `EventMan` methods.

## Cross-References

- File: [UID:0000J6][Event](by-file/Event.md)
- Related classes: [UID:00004L][Event](by-class/Event.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00006J][InputMan](by-class/InputMan.md), [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:00014C][0x004a8b40-0x004ab476.EventMan](by-memory/0x004a8b40-0x004ab476.EventMan.md), [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md), [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md)
- Static data: [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `84/86`.
  - Summary/evidence: input-event producer responsibility, constructor, cursor/mouse/key/IME/timer dispatch methods, event-type table, Application construction evidence, InputMan/EventDispatcher placement split, and adjacent helper caveats are documented; remaining work is final source-file split and event-record field naming.
- 2026-06-05: Marked reconstructable and attached to [UID:0000J6][Event](by-file/Event.md) because the class is `84/86` and the parent is `84/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts across the constructor, cursor/mouse/key/IME/timer dispatch methods, and scalar deleting destructor from `0x004a8b40` through `0x004ab440`; current `callers` confirms construction from application initialization at `0x0046463f`.
- 2026-06-11 Agent-B001 B001-041 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`; direct children above `85/85` could not attach under the stricter corrected gate.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed the constructor copy of [UID:00027C] table starts, `0x100` copy sizes, application-initialization construction, and key down/release use of EventMan keyboard state. The class is now strong enough to act as the direct semantic parent for the key translation table child while still keeping final C++ blank until event-record field names and table member names are final-audit quality.
