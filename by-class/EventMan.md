*** UID:00004O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_EVENTMAN_DECLARATION_H
#define NEXUSTK_UI_CORE_EVENTMAN_DECLARATION_H

#include <windows.h>
#include <deque>
#include <string>

struct Point;

class EventMan
{
public:
    unsigned char TranslateEventKey(unsigned char key,
                                    unsigned char modifiers);
    void GetCursorPosition(Point *position);
    void DispatchCharEvent(wchar_t character, unsigned int messageTime);
    void DispatchImeOpenStatusEvent(BOOL isOpen, unsigned int messageTime);
    void DispatchCompositionTextEvent(const wchar_t *text,
                                      unsigned int messageTime);
    void DispatchCompositionStartEvent(unsigned int messageTime);
    void DispatchCompositionResultEvent(const wchar_t *text,
                                        unsigned int messageTime);
    void DispatchCompositionEndEvent(unsigned int messageTime);
    void DispatchCandidateListEvent(
        int selectedRow,
        std::deque<std::wstring> *visibleCandidates,
        unsigned int messageTime);
    void DispatchCandidateCloseEvent(unsigned int messageTime);
};

extern EventMan *g_pEventMan;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EventMan

## UID0000KA Inventory Consumer Declaration - 2026-08-15

- `InventoryPane.cpp` and the existing keyboard consumers call the exact
  receiver-bearing `unsigned char TranslateEventKey(unsigned char key,
  unsigned char modifiers)` helper at `0x004a8b10`; the formal H channel now
  exposes that member and `extern EventMan *g_pEventMan` through the existing
  UID0000J6 `ui/core/Event.h` owner route.
- This is a declaration-visibility repair only. It does not emit an EventMan
  body, duplicate singleton storage, change the documented private-state
  evidence, or claim new original spellings.

## UID0000KB Scrollbar Cursor Declaration - 2026-08-15

- InventoryScrollPane's `UpdateDragScroll`, `HitTestScrollRegion`, `GetPartRect`, and `UpdatePositionFromCursor` consume the existing EventMan cursor reader at `0x004a9090` through the normal source-facing member `void GetCursorPosition(Point *position)`.
- Event.h owns the `Point` forward declaration, EventMan member declaration, and existing `extern EventMan *g_pEventMan`. Exact function body ownership and the documented cursor fields remain unchanged; no local InventoryScrollPane declaration or wrapper is emitted.
- The formal H replacement is intentionally complete for the two currently documented EventMan methods. It preserves the prior TranslateEventKey declaration and adds only the strongly evidenced cursor member.

## UID0000K6 InputMan Receiver Declaration - 2026-08-24

- InputMan call sites load `g_pEventMan` into ECX before every character/IME/candidate call in `0x004a97e0-0x004a9f00`. Several bodies do not read the receiver, which explains earlier Hex-Rays `__stdcall` renderings but does not make them free factories.
- The complete formal H now includes Windows/deque/string dependencies, the existing key/cursor declarations, `DispatchCharEvent`, seven IME/candidate member declarations with `unsigned int` message time, the candidate `std::deque<std::wstring> *` payload, the singleton extern, and a complete guard. Event.cpp retains all bodies and source ownership.
- Historical free-IME-factory wording is superseded for `0x004a9a40-0x004a9f00`. Packet helpers beginning at `0x004a9fa0` remain independently classified and are not changed by this receiver correction.

## Summary

`EventMan` is the process-wide input event producer. It converts cursor, mouse button, mouse wheel, keyboard, and IME composition state into temporary `Event` records and dispatches them through `g_pEventDispatcher`.

The class also owns the static key translation data copied from [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md). B001-041 live IDA recheck confirms those two `0x100`-byte tables feed only the EventMan constructor, and the resulting object fields are consumed by the EventMan key down/release methods.

B008 resolves the pre-constructor `0x004a8b10` helper as an EventMan key translation adaptor, not a CRT `ctype`/`narrow` routine. The body returns the key byte and ignores the modifier argument, while 81 local call refs connect it to pane/handler/EventDispatcher keyboard routing. Exact original spelling remains inferred; use `EventMan::TranslateEventKey` or `TranslateEventKeyByte` in documentation.

## Likely Original Placement

- Source: [UID:0000J6][Event](by-file/Event.md)
- Proposed path: `ui/core/Event.cpp`
- Confidence: strong that it belongs with the event object/factory code; medium that it was not split into a separate `EventMan.cpp`.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x004a8b40-0x004a8f13` | constructor | Initializes `TimerHandler`, installs `g_pEventMan`, hides/centers/clips the hardware cursor, and builds key/modifier translation tables. |
| `0x004a8b10-0x004a8b1a` | `TranslateEventKey` / `TranslateEventKeyByte` | Two-argument key translation adaptor; old CRT/locale label is rejected. |
| `0x004a8b20-0x004a8b3e` | `ResetKeyboardState` / `ClearInputState` | Focus/reset helper that clears keyboard/modifier state before constructor-aligned methods. |
| `0x004a8f20-0x004a8f35` | ordinary destructor | Restores EventMan vtable state, clears `g_pEventMan`, and tears down the `TimerHandler` base. |
| `0x004a8f40-0x004a8f56` | `ShutdownPacketEventSource` / `CloseSocketEventStream` | Application shutdown helper that calls Socket reset/event-source services but remains EventMan/Event.cpp-owned. |
| `0x004a8f60-0x004a8f6e` | `StartCursorTimer` | Schedules a 20 ms cursor timer through the timer manager helper. |
| `0x004a8f70-0x004a8f75` | `StopCursorTimer` | Cancels/removes the cursor timer through the timer manager helper. |
| `0x004a9090-0x004a90a5` | `GetCursorPosition` | Returns stored cursor coordinates. |
| `0x004a90b0-0x004a90c2` | `GetModifierState` | Copies `m_modifierState` into the caller buffer. Producer `DispatchKeyCharEvent` proves bit `0x04` is [UID:00004L][Event](by-class/Event.md) `kEventModifierShift`; [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md) masks that bit to suppress forced chat autoscroll while Shift is held. |
| `0x004a90d0-0x004a90fd` | `ClearKeyboardState` | Clears keyboard-state arrays and flags around `this+0x820`/`this+0x920`. |
| `0x004a9100-0x004a9115` | `ForwardCursorEvent` | Thin wrapper over cursor-event dispatch. |
| `0x004a9120-0x004a925a` | `DispatchPointerThresholdEvent` | Emits left-button press or double-click events after movement/time threshold checks. |
| `0x004a9260-0x004a9356` | `DispatchLeftButtonReleaseSequence` | Emits left-button release state. |
| `0x004a9360-0x004a949a` | `DispatchRightButtonThresholdEvent` | Emits right-button press or double-click events after threshold checks. |
| `0x004a94a0-0x004a9596` | `DispatchRightButtonReleaseSequence` | Emits right-button release state. |
| `0x004a95a0-0x004a969f` | `DispatchMouseWheelSequence` | Emits mouse-wheel events with position, modifier, delta, and tick fields. |
| `0x004a96a0-0x004a97dc` | `DispatchKeyCharEvent` | Updates key/modifier state, translates virtual keys, handles `Alt+0x88` app-exit, and dispatches key-down event type `8`. |
| `0x004a97e0-0x004a989a` | `DispatchCharEvent` | Dispatches Win32 `WM_CHAR` text input as event type `10`. |
| `0x004a98a0-0x004a99db` | `HandleKeyRelease` | Clears key/modifier state and runs the full-screen spacebar release gate; IDA decompile shows no `DispatchEvent` call in this method. |
| `0x004a99e0-0x004a99f0` | `SetCapsLockState` | Stores the `GetKeyState(0x14)` result at `this+0x921`. |
| `0x004a99f0-0x004a9a00` | `SetNumLockState` | Stores the `GetKeyState(0x90)` result at `this+0x922`. |
| `0x004a9a00-0x004a9a07` | `GetCapsLockState` | Getter for `this+0x921`; no local direct refs found in B008 scan. |
| `0x004a9a10-0x004a9a17` | `GetNumLockState` | Getter for `this+0x922`; no local direct refs found in B008 scan. |
| `0x004a9a20-0x004a9a32` | `GetRawKeyState` | Reads byte array at `this+0x120+key`; no local direct refs found in B008 scan. |
| `0x004a9a40-0x004a9ad9` | `DispatchImeOpenStatusEvent` | Receiver-bearing type-11 producer called through `g_pEventMan`; stores open state and message time. |
| `0x004a9ae0-0x004a9c04` | `DispatchCompositionTextEvent` | Copies up to 128 UTF-16 chars into a composition-text event and dispatches type `10` with subcode `0`. |
| `0x004a9c10-0x004a9cb0` | `DispatchCompositionStartEvent` | Receiver-bearing type-12 producer called through `g_pEventMan`. |
| `0x004a9cb0-0x004a9daa` | `DispatchCompositionResultEvent` | Receiver-bearing type-13 producer; copies UTF-16 result text. |
| `0x004a9db0-0x004a9e50` | `DispatchCompositionEndEvent` | Receiver-bearing type-14 producer. |
| `0x004a9e50-0x004a9ef2` | `DispatchCandidateListEvent` | Receiver-bearing type-15 producer; stores visible deque pointer, selected row, and message time. |
| `0x004a9f00-0x004a9fa0` | `DispatchCandidateCloseEvent` | Receiver-bearing type-16 producer. |
| `0x004aa1d0-0x004aa1f4` | `PostNotification` / `PostApplicationNotification` | EventMan/Event.cpp notification router; obtains the application window and posts message `0x406` with channel plus `LObject *` payload. |
| `0x004aa200-0x004aa22b` | `OnTimerTick` | Dispatches current cursor position and reschedules its 20 ms timer. |
| `0x004aa3b0-0x004aa46b` | `DispatchCursorEvent` | Stores cursor coordinates and dispatches event type `0`. |
| `0x004ab3e0-0x004ab3eb` | `ClearSingletonForUnwind` | EH/unwind singleton clear helper; not a standalone hand-written source method. |
| `0x004ab440-0x004ab476` | scalar deleting destructor | Clears `g_pEventMan`, restores base vtable state, destroys `TimerHandler`, and conditionally frees storage; exact memory page is [UID:0003LV][0x004ab440-0x004ab476.EventManScalarDeletingDestructor](by-memory/0x004ab440-0x004ab476.EventManScalarDeletingDestructor.md). |

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
| `11` | `DispatchImeOpenStatusEvent` | IME open/closed status event produced by EventMan member |
| `12` | `DispatchCompositionStartEvent` | IME composition start event |
| `13` | `DispatchCompositionResultEvent` | IME result text event |
| `14` | `DispatchCompositionEndEvent` | IME composition end event |
| `15` | `DispatchCandidateListEvent` | visible candidate deque/list pointer at Event `+0x08`, selected row at `+0x0c` |
| `16` | `DispatchCandidateCloseEvent` | IME candidate popup close |
| `17` | `kEventImeReserved` | EventDispatcher accepts it; no producer is proven in this island, all Event-vtable construction sites, or the five out-of-line Event constructor callers |
| `18` | packet helper family | packet/reference/copied payload event factories |
| `19` | `kEventApplicationNotification` | `EventMan::PostNotification` posts message `0x406`; Main_WndProc constructs type `19` with channel and `LObject *` payload |
| `20` | `kEventDispatchSuppressed` | EventDispatcher suppresses this value before normal routing; no producer found |
| `21` | `kEventSystemControl` | accepted by the system/control classifier; no producer found |
| `22` | `kEventWorkNotification` | Main_WndProc custom message `0x400`, low-word subtype `32`; independent work-notification consumers test the same type |

## Event Record And UID00014B Synchronization

- [UID:00004L][Event](by-class/Event.md) now emits the accepted `0x110` declaration: unsigned type byte `+0x04`, alignment, and a `0x108` payload union beginning at `+0x08`.
- EventMan pointer/mouse factories populate x/y `+0x08/+0x0c`, modifiers `+0x10`, detail/wheel `+0x14`, and message time `+0x18`; key/text factories use key/input/text storage beginning `+0x08/+0x0a`, modifier `+0x10a`, and message time `+0x10c`. The historical blanket tick-at-`+0x10c` claim is superseded for pointer/mouse records.
- EventMan IME members use open/candidate/text/result overlays at `+0x08` through `+0x10c`; packet factories use kind/data/size at `+0x08/+0x0c/+0x10`. Dispatcher cleanup frees the type-18 data pointer, so the kind byte is not overclaimed as the only ownership bit.
- [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md) emits source lifecycle and resolves `kEventNone = 0xff`. EventMan/free factories often inline the same LObject construction and Event vptr store; that is compiler inlining, not another Event class.
- UID00014B has five non-inlined constructor calls and 49 destructor refs. Event vtable has 79 refs across lifecycle, inlined factory construction/cleanup, and scalar support.
- [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md) and [UID:0003I7][0x006196a0-0x006196b0.EventVtableData](by-memory/0x006196a0-0x006196b0.EventVtableData.md) emit only compiler-coverage markers; EventMan must not duplicate their ABI/data bodies.
- Current RTTI/name inventory has one Event record class and no Event-derived class or alternate Event-record vtable. EventMan is the main input producer, not the Event lifecycle owner.

## Static Data And Owned State

| Item | Evidence | Ownership decision |
| --- | --- | --- |
| [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md) | Live IDA `xrefs_to` reports one xref to `0x0066d888` at `0x004a8cfd` and one xref to `0x0066d988` at `0x004a8d1d`, both in `EventMan::EventMan` (`0x004a8b40`). Constructor decompilation copies each source table with size `0x100` into `this + 0x420` and `this + 0x520`; keyboard down/release methods use EventMan translation/state arrays at `this + 0x620`, `this + 0x820`, and `this + 0x920`. | Direct class-owned source-declared table pair. Attach the memory child to this class, not to `InputMan`, `EventDispatcher`, or the broader `.data` section. |
| `g_pEventMan` singleton storage | Constructor stores the singleton during `Application::Initialize`, and the scalar deleting destructor clears it. | Class lifecycle state; exact storage remains documented separately under the global/memory pages. |
| keyboard/state fields | Key-state array near `this+0x120`, copied translation tables at `this+0x420`/`this+0x520`, translation/state arrays around `this+0x620`/`this+0x820`, `m_modifierState` at `this+0x920`, and caps/num flags at `this+0x921`/`this+0x922`. `DispatchKeyCharEvent` ORs per-key modifier masks into `m_modifierState`, tests bit `0x04` during alphabetic Shift normalization, and copies the byte into `Event::m_payload.m_key.m_modifiers`; `GetModifierState` returns the same byte. | `m_modifierState` and its Shift bit are source-quality consumer-facing semantics. Other exact original field spellings remain provisional. Do not duplicate the modifier enum; [UID:00004L][Event](by-class/Event.md) owns `kEventModifierShift = 0x04`. |

## Evidence

- IDA MCP confirms all listed function starts and exact ends.
- IDA MCP shows `EventMan::EventMan` is constructed from `Application::Initialize` at `0x0046463f` after `EventDispatcher` construction.
- IDA MCP shows `OnTimerTick` is reached through virtual/timer dispatch rather than a direct call, while `DispatchCursorEvent` is called by `ForwardCursorEvent` and `OnTimerTick`.
- 2026-06-11 B001 live IDA `decompile 0x004a8b40` shows the constructor configures singleton state, cursor policy, key maps, modifier maps, and event-building tables without delegating ownership to `InputMan` or `EventDispatcher`.
- 2026-06-11 B001 live IDA `decompile 0x004a96a0` and `0x004a98a0` show key down/release methods using the constructor-built keyboard state and fallback translation arrays, including reads from `this + 0x620` when `ToAscii` does not produce one byte.
- B007's UID0002ER live-MCP reconciliation closes the semantic path for modifier bit `0x04`: `DispatchKeyCharEvent` ORs the selected key-mask into `this+0x920`, tests bit `4` to normalize alphabetic Shift behavior, and copies that modifier byte into the key Event payload. `GetModifierState` copies the same byte to callers, and `ChattingPane::AddIncomingMessage` masks `kEventModifierShift` to suppress forced bottom scrolling. This is producer/consumer proof, not a generic interaction-state guess.
- IDA decompile of `0x004a98a0` confirms the no-dispatch key-release behavior and the special `UserPane` spacebar-release gate.
- 2026-06-19 B008 local source-quality pass resolves `0x004a8b10` as key translation rather than CRT/locale code, adds caps/num setters/getters, `ShutdownPacketEventSource`, cursor timer wrappers, `PostNotification`, the retained duplicate helper caveat, and confirms the `0x006196b8 -> 0x004aa200` vtable slot as `EventMan::OnTimerTick`.
- 2026-08-24 InputMan call-shape reread rejects the former free-IME-factory model: each call in `0x004a9a40-0x004a9f00` loads `g_pEventMan` into ECX. Unused receivers explain decompiler calling-convention loss; source declarations remain receiver-bearing EventMan members.

## Placement Notes

- Keep `EventMan` separate from [UID:0000K6][InputMan](by-file/InputMan.md). `InputMan` owns Win32/IMM message handling and calls into this event layer; `EventMan` owns event object construction and dispatch.
- Keep it near [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), but do not merge the responsibilities: `EventDispatcher` routes ready events, while `EventMan` produces event records.
- The receiver-bearing IME methods at `0x004a9a40-0x004a9f00` and the separate packet-style helpers at `0x004a9fa0-0x004aa1b3` belong in the same `Event.cpp` source module. The former are EventMan members even where the receiver is unused; the latter retain their existing free-helper classifications.
- The retained duplicate helper band at `0x004aa470-0x004ab3c3` mirrors active EventMan/free Event.cpp helpers but has no local direct code/data xrefs in B008's scan. Treat it as retained support, not as proof that the whole [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) range should become an EventMan class page.
- The mixed [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) page stays attached to [UID:0000J6][Event](by-file/Event.md), not this class, because it also contains pre-EventMan `Event` classifiers, packet factories, notification routing, retained duplicate helpers, and EH cleanup support. Receiver correction for the IME band does not make the mixed physical aggregate a class emitter.

## Cross-References

- File: [UID:0000J6][Event](by-file/Event.md)
- Related classes: [UID:00004L][Event](by-class/Event.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00006J][InputMan](by-class/InputMan.md), [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md), [UID:0003LV][0x004ab440-0x004ab476.EventManScalarDeletingDestructor](by-memory/0x004ab440-0x004ab476.EventManScalarDeletingDestructor.md), [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md), [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md)
- Static data: [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md)
- Chat consumer: [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md)

## Changes

- 2026-08-24 B008 UID0000K6 accepted implementation callback: retained `90/92` and Event.cpp ownership; expanded the complete formal H guard/dependencies from two methods to the exact key/cursor/character/IME/candidate receiver interface needed by InputMan; added the candidate deque signature and singleton extern; historicalized free-factory wording for `0x004a9a40-0x004a9f00` using ECX/g_pEventMan call-site evidence.

- 2026-08-15 B005 UID0000KB source-contract callback: added the Point forward declaration and `EventMan::GetCursorPosition(Point *)` to the Event.h-owned formal H while preserving `90/92`, existing TranslateEventKey, singleton declaration, behavior research, and body ownership.

- 2026-07-29 B007 UID0002ER support implementation:
  - Preserved `90/92`, owner/emitter [UID:0000J6][Event](by-file/Event.md), reconstructable true, blank formal blocks, Event/source placement, and all existing method/type/state evidence.
  - Added the exact `m_modifierState` producer/GetModifierState/consumer chain proving bit `0x04` is [UID:00004L][Event](by-class/Event.md) `kEventModifierShift`, while retaining enum ownership on Event and rejecting the older generic interaction-state interpretation.

- 2026-07-12 B002 accepted UID00014B EventMan synchronization:
  - Changed `88/90 -> 90/92`; preserved owner/emitter [UID:0000J6][Event](by-file/Event.md), reconstructable state, and blank class formal block.
  - Incorporated exact Event layout/payload variants, source lifecycle, inlined-factory relation, five constructor calls/49 destructor refs/79 vtable refs, type19/type22 producers, types17/20/21 no-producer caveats, packet cleanup semantics, scalar/vtable marker policy, and no-subclass/owner distinction.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `84/86`.
  - Summary/evidence: input-event producer responsibility, constructor, cursor/mouse/key/IME/timer dispatch methods, event-type table, Application construction evidence, InputMan/EventDispatcher placement split, and adjacent helper caveats are documented; remaining work is final source-file split and event-record field naming.
- 2026-06-05: Marked reconstructable and attached to [UID:0000J6][Event](by-file/Event.md) because the class is `84/86` and the parent is `84/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts across the constructor, cursor/mouse/key/IME/timer dispatch methods, and scalar deleting destructor from `0x004a8b40` through `0x004ab440`; current `callers` confirms construction from application initialization at `0x0046463f`.
- 2026-06-11 Agent-B001 B001-041 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`; direct children above `85/85` could not attach under the stricter corrected gate.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed the constructor copy of [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md) table starts, `0x100` copy sizes, application-initialization construction, and key down/release use of EventMan keyboard state. The class is now strong enough to act as the direct semantic parent for the key translation table child while still keeping final C++ blank until event-record field names and table member names are final-audit quality.
- 2026-06-12 Agent-C001 Goal 2 barrier repair:
  - Before: memory cross-references still pointed to the old first-to-last EventMan aggregate and the broad EventObjects range.
  - Changed to: class references now distinguish the mixed Event.cpp helper island from the exact EventMan scalar deleting destructor page.
  - Summary/evidence: live IDA MCP confirms the mixed island contains non-EventMan helpers, while `0x004ab440-0x004ab476` is the exact EventMan destructor through its vtable slot and singleton clear. Only exact EventMan-owned children attach to this class.
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`; several helpers were missing or still named broadly, including `0x004a8b10`, caps/num state helpers, timer wrappers, notification posting, and retained duplicate caveats.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Summary/evidence: B008 rechecked [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md), rejected the stale `ctype/narrow` label for `0x004a8b10`, mapped EventMan keyboard/state/cursor/timer/notification helpers, added Event type-family entries through packet/system/control routing, documented provisional object-state offsets, confirmed the EventMan vtable timer slot, and preserved the mixed Event.cpp ownership route instead of incorrectly claiming the whole island as EventMan-owned.
