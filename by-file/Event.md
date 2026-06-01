*** UID:0000J6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Event

## Status

- Confidence: strong for event-object and event-factory ownership; medium for whether `EventMan` was split into its own `.cpp`.
- Proposed module: `ui/core/Event.cpp`
- Current generated sources: `class_Event.cpp`, `class_EventMan.cpp`, recovered event helper files under `simroot_v2/recovered`
- Primary class docs: [UID:00004L][Event](by-class/Event.md), [UID:00004O][EventMan](by-class/EventMan.md)
- Main address docs: [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md), [UID:00014C][0x004a8b40-0x004ab476.EventMan](by-memory/0x004a8b40-0x004ab476.EventMan.md)

## File Role

`Event.cpp` is the event object/factory layer between [UID:0000K6][InputMan](by-file/InputMan.md) and [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). It provides the base `Event` object, the `EventMan` singleton that builds cursor/mouse/keyboard/text events, and a set of small free helpers that package IME and packet-style payloads into temporary `Event` records.

`InputMan` should keep Win32/IMM message ownership. Event production should live here: most routines in this module construct a stack `Event`, fill a type-specific payload, dispatch through `g_pEventDispatcher`, and tear the temporary object down.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `Event` | `0x004a8a90-0x004a8abf`, destructor wrapper at `0x004ab3f0` | Base event object construction/destruction. |
| `EventMan` | `0x004a8b40-0x004ab476` non-contiguous class aggregate | Singleton input event producer for cursor, mouse, keyboard, character, composition text, and timer cursor polling. |
| IME event factories | `0x004a9a40`, `0x004a9c10`, `0x004a9cb0`, `0x004a9db0`, `0x004a9e50`, `0x004a9f00` | Free helpers called by `InputMan::HandleWindowMessage`; they build IME status/composition/candidate events. |
| packet/payload event factories | `0x004a9fa0`, `0x004aa050`, `0x004aa110` | Free helpers that dispatch type `18` packet or copied-payload events. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Base event construction | `0x004a8a90` | Initializes `LObject`, installs event vtable, and sets default event type. |
| Base event destruction | `0x004a8ab0`, `0x004ab3f0` | Resets event state, destroys base, and optionally frees storage. |
| Event manager construction | `0x004a8b40` | Installs `g_pEventMan`, hides/clips/centers the cursor, and initializes key translation tables. |
| Mouse/cursor dispatch | `0x004a9120`, `0x004a9260`, `0x004a9360`, `0x004a94a0`, `0x004a95a0`, `0x004aa3b0` | Builds event types `0` through `7` for cursor movement, button state, double-clicks, release, and wheel input. |
| Keyboard/text dispatch | `0x004a96a0`, `0x004a97e0`, `0x004a98a0`, `0x004a9ae0` | Builds key-down, char, key-release, and composition-text records; `0x004a98a0` prepares a type `9` record but does not dispatch it in the verified binary path. |
| IME helper dispatch | `0x004a9a40-0x004a9f00` | Free event factories for IME open status, composition start/result/end, candidate list, and candidate close. |
| Packet/payload helper dispatch | `0x004a9fa0-0x004aa110` | Free helpers for packet/payload event type `18`. |
| Timer dispatch | `0x004aa200` | Sends cursor state every 20 ms through `EventMan::DispatchCursorEvent`. |

## Boundary Notes

- IDA confirms exact starts at `0x004a8a90`, `0x004a8ab0`, and `0x004ab3f0` for base `Event`.
- IDA confirms exact `EventMan` starts from `0x004a8b40` through `0x004ab440`; the class methods are non-contiguous because free event factories occupy gaps.
- IDA callers show `EventMan::EventMan` is called from `Application::Initialize`, while the IME event factories are called from `InputMan::HandleWindowMessage`.
- The old [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md) memory doc is a broad base-event span and should not be treated as ownership of every byte between its endpoints.

## Cross-References

- [UID:00004L][Event](by-class/Event.md)
- [UID:00004O][EventMan](by-class/EventMan.md)
- [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md)
- [UID:00014C][0x004a8b40-0x004ab476.EventMan](by-memory/0x004a8b40-0x004ab476.EventMan.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000K6][InputMan](by-file/InputMan.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: event object/factory role, proposed contents, method families, EventMan/IME/payload factory boundaries, InputMan/EventDispatcher separation, and broad memory-range caveat are documented; confidence remains medium-high because final `EventMan` source split remains open.
