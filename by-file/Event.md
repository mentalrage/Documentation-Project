*** UID:0000J6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Event

## UID0000KA Event Consumer - 2026-08-15

`InventoryPane.cpp` consumes the complete `Event`/payload declarations, `g_pEventMan`, and `EventMan::TranslateEventKey(unsigned char,unsigned char)` from `ui/core/Event.h`. Key handling reads exact key/modifier payload bytes and pointer handling reads exact type/y/x payload fields; no local event proxy or free narrow-key helper remains. Event/EventMan ownership, layouts, and scores are unchanged.

## UID0000L2 Physical Header Visibility Closure - 2026-08-12

- `NexusTK/ui/core/Event.h` is physically required by consumers that inspect `EventPayload`, including `MapNamePane::HandlePacketEvent(Event *)`. UID00004L now emits the complete guarded header declaration, all payload structures and enums, the `Event` class, and its child declarations through the H channel.
- `NexusTK/ui/core/Event.cpp` now begins with `#include "Event.h"` and then composes method children. The former class/enum/payload declaration in the CPP channel was a source-factoring defect; its content was moved without changing values, widths, order, methods, ownership, scores, or source path.
- PCH-only or forward-declaration-only visibility is insufficient because MapNamePane dereferences the packet payload. The generated header is therefore part of the compile contract, not an optional organizational preference.

## UID0003ZT Header And Source Factoring - 2026-07-23

- Canonical source pair: `NexusTK/ui/core/Event.h` and `NexusTK/ui/core/Event.cpp`. The file page remains an ownership/source index with no by-file managed formal.
- `Event.h` includes exact existing `NexusTK/util/LObject.h` before the complete [UID:00004L][Event](by-class/Event.md) declaration. It owns `PaneKeyCode`, modifier flags, `EventType` including `kEventWorkNotification = 22`, all payload records/unions, and the complete `Event` class declaration.
- `Event.cpp` includes Event.h and owns Event/EventMan construction, destruction, classifiers, factories, translation tables, notification posting, and retained helper definitions already inventoried below.
- `EventHandler.h` needs only `class Event;` for pointer signatures; `EventDispatcher.h` remains the router owner. Neither header duplicates or truncates the Event record.
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) is a new complete-record consumer through Event.h. It reads `event->m_type` and compares `kEventWorkNotification`; this does not transfer method ownership from MapPane or definitions from Event.cpp.
- Scores remain `91/92`; all prior EventMan, IME, packet, system/control, compiler-support, and retained-helper evidence remains authoritative.

## UID0001MP/UID000364 Modifier And Consumer Closure - 2026-07-20

- Win32 producer mapping is exact and complete: `VK_MENU`/Alt maps to `kEventModifierAlt = 0x01`, `VK_CONTROL` maps to `kEventModifierControl = 0x02`, and `VK_SHIFT` maps to `kEventModifierShift = 0x04`. The pre-callback Event declaration's omission of Alt/Menu was a current defect, not an accepted reduced enum.
- `EventMan::TranslateEventKey(unsigned char key, unsigned char modifiers)` is the source-facing helper at `0x004a8b10`; its `this` receiver, ten-byte identity body, and broad caller set reject CRT `std::ctype<char>::do_narrow`, free `NarrowInputKey`, and `narrowFallback` source ownership.
- [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent.md) and the normalized help-handler family compare exact Shift-only `0x04`; [UID:000364][0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent](by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md) uses the complete Event key/text overlay. These consumers do not weaken or omit the independently producer-proven Alt and Control constants.
- [UID:00004L][Event](by-class/Event.md) now preserves `sizeof(Event) == 0x110` with byte input code, byte text length, and `wchar_t[128]` text storage. Existing EventMan factories, static tables, IME/packet/system records, retained duplicate helpers, compiler wrappers, and `ui/core` route remain unchanged.

## UID00030F Delete Key And Layout Synchronization - 2026-07-20

- UID00030F adds target-proven `kPaneKeyDelete = 0x84` to the shared PaneKeyCode declaration while preserving Escape, arrows, PageUp/PageDown, and Alt/Control/Shift constants. EventMan translation remains the source-facing key conversion route.
- The accepted class formal removes only explicit `m_padding` declarations that ordinary 32-bit C++ alignment supplies: pointer modifiers-to-detail, key/text/composition modifiers-to-time, packet kind-to-pointer, and Event type-to-payload.
- Real payload storage remains unchanged. Pointer message time stays at object `+0x18`; key/text/composition/IME time stays at `+0x10c`; candidate/open/result reserve arrays retain exact extents; EventPayload remains `0x108`; complete Event remains `0x110`.
- UID00030F consumes key-down/text-input overlays, translated Delete, modifier flags, and text length/storage directly. These uses close the source declaration without adding raw offsets, packed layout, target-specific wrappers, new ownership, or defensive behavior.
- Class/file scores and route remain `94/95` and `91/92`, owner/emitter UID0000J6, position 10, `NexusTK/ui/core/`. Constructor/destructor/factory/packet/IME/system evidence and compiler-vtable/scalar-wrapper separation remain unchanged.

## Status

- Confidence: very strong for Event lifecycle/layout, event factories, EventMan producer, type-family map, compiler-support separation, and `ui/core` placement; strong for descriptive field/enum names and whether EventMan historically used a separate `.cpp`.
- Proposed module: `ui/core/Event.cpp`
- Reconstruction status: exact children now emit the Event declaration, constructor/destructor, static key tables/global, and compiler-coverage markers. This file page stays an evidence/ownership index because UID00014C remains a mixed helper island with independent routines, retained duplicate helpers, and EH cleanup support.
- Primary class docs: [UID:00004L][Event](by-class/Event.md), [UID:00004O][EventMan](by-class/EventMan.md)
- Main address docs: [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md), [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md), [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md), [UID:0003LV][0x004ab440-0x004ab476.EventManScalarDeletingDestructor](by-memory/0x004ab440-0x004ab476.EventManScalarDeletingDestructor.md)

## File Role

`Event.cpp` is the event object/producer layer between [UID:0000K6][InputMan](by-file/InputMan.md) and [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). It provides the base `Event` object, the `EventMan` singleton that builds cursor/mouse/keyboard/text/IME/candidate events, and separate small helpers for packet-style payloads.

`InputMan` should keep Win32/IMM message ownership. Event production should live here: most routines in this module construct a stack `Event`, fill a type-specific payload, dispatch through `g_pEventDispatcher`, and tear the temporary object down.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `Event` | `0x004a8a90-0x004a8abf`, destructor wrapper at `0x004ab3f0-0x004ab435` | Base event object construction/destruction. |
| Event type classifiers | `0x004a8ac0`, `0x004a8ad0`, `0x004a8ae0`, `0x004a8af0`, `0x004a8b00` | EventDispatcher-facing predicates for pointer/mouse `0..7`, key/text `8..10`, IME `11..17`, packet `18`, and system/control `20..22` families. |
| `EventMan` | class methods inside `0x004a8ac0-0x004ab3eb`, scalar destructor at `0x004ab440-0x004ab476` | Singleton input event producer for cursor, mouse, keyboard, character, composition text, notification posting, packet-event-source shutdown, and timer cursor polling. |
| EventMan key translation tables | [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md) | Static normal/shifted keyboard lookup tables copied into the EventMan object by its constructor and consumed by key down/release methods. |
| EventMan IME/candidate methods | `0x004a9a40`, `0x004a9c10`, `0x004a9cb0`, `0x004a9db0`, `0x004a9e50`, `0x004a9f00` | Receiver-bearing methods called through `g_pEventMan` by `InputMan::HandleWindowMessage`; they build IME status/composition/candidate events. `0x004a9e50` dispatches Event type `15` with the candidate deque pointer and selected row used by `IMECandidatePane::ShowCandidateList`. |
| packet/payload event factories | `0x004a9fa0`, `0x004aa050`, `0x004aa110` | Free helpers that dispatch type `18` packet or copied-payload events. |
| retained duplicate event helpers | `0x004aa470-0x004ab3c3` | Source-shaped duplicate Event.cpp helper bodies for mouse, IME, key, state, and packet families. B008 found no local direct code/data xrefs, so they are retained-support candidates, not padding or scalar-delete glue. |
| EventMan notification router | `0x004aa1d0-0x004aa1f4` | Best documented as `EventMan::PostNotification` / `PostApplicationNotification`: notification producers call it to post message `0x406` through the application window using `g_pfnPostMessageW`. Exact original name is inferred. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Base event construction | `0x004a8a90` | Initializes `LObject`, installs event vtable, and sets default event type. |
| Base event destruction | `0x004a8ab0`, `0x004ab3f0` | UID00014B emits the source destructor; UID0003LU is separate compiler-generated scalar-delete support with a covered-by marker. |
| Event manager construction | `0x004a8b40` | Installs `g_pEventMan`, hides/clips/centers the cursor, and initializes key translation tables. |
| Mouse/cursor dispatch | `0x004a9120`, `0x004a9260`, `0x004a9360`, `0x004a94a0`, `0x004a95a0`, `0x004aa3b0` | Builds event types `0` through `7` for cursor movement, button state, double-clicks, release, and wheel input. |
| Keyboard/text dispatch | `0x004a96a0`, `0x004a97e0`, `0x004a98a0`, `0x004a9ae0` | Builds key-down, char, key-release, and composition-text records; `0x004a98a0` prepares a type `9` record but does not dispatch it in the verified binary path. |
| IME helper dispatch | `0x004a9a40-0x004a9f00` | EventMan member producers for IME open status, composition text/start/result/end, candidate list, and candidate close; call sites load `g_pEventMan` into ECX even where bodies do not consume `this`. |
| Packet/payload helper dispatch | `0x004a9fa0-0x004aa110` | Free helpers for packet/payload event type `18`. |
| Notification dispatch | `0x004aa1d0` | EventMan/Event.cpp router for notification channel plus `LObject *` payload; posts application window message `0x406`. |
| Timer dispatch | `0x004aa200` | Sends cursor state every 20 ms through `EventMan::DispatchCursorEvent`. |

## Event Type And Payload Map

[UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) now carries the consolidated type map used by this file: cursor/mouse `0..7`, key/text `8..10`, IME `11..17`, packet `18`, special handler slot type `19`, and system/control `20..22`. The most stable source names are `kEventCursorMove`, left/right button down/double/up, `kEventMouseWheel`, `kEventKeyDown`, `kEventKeyUp`, `kEventTextInput`, `kEventImeOpenStatus`, composition start/result/end, candidate list/close, and `kEventPacket`.

The accepted [UID:00004L][Event](by-class/Event.md) declaration uses an unsigned `m_type` at `+0x04`, compiler alignment through `+0x07`, and an aligned `0x108` payload union at `+0x08`, preserving exact `sizeof(Event) == 0x110`. Pointer/mouse records use y at +0x08, x at +0x0c, modifiers at +0x10, detail at +0x14, and message time at +0x18. Key/text/IME records use embedded UTF-16 storage with modifier `+0x10a` where applicable and message time at `+0x10c`. Candidate records use pointer/row/time at `+0x08/+0x0c/+0x10c`; packets use kind/data/size at `+0x08/+0x0c/+0x10`; application notifications use channel/payload at `+0x08/+0x0c`. The historical blanket `tick +0x10c` statement is superseded.

The pointer order is high-confidence source-facing reconstruction supported by converging direct evidence: EventMan pointer producers place y in Event `+0x08` and x in `+0x0c`; [UID:00048N][0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent](by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md) passes the `+0x08` value before the `+0x0c` value to accepted `PointInRect(int y, int x, const RectBounds *)`; and UID00004L emits `m_y` before `m_x`. The former x-at-`+0x08` / y-at-`+0x0c` file prose is preserved as an explicitly superseded historical assumption rather than silently removed. Exact original field spellings remain a lexical confidence cap only. This file page remains a prose/source-route index and carries no `RECONSTRUCTION_CPP` metadata or duplicate Event declaration.

Types `19` and `22` now have global producer evidence outside the mixed helper island. Main_WndProc message `0x406` builds `kEventApplicationNotification` type `19`, stores channel and `LObject *`, dispatches, then releases the payload; `EventMan::PostNotification` posts that message. Main_WndProc custom message `0x400` with low-word subtype `32` builds `kEventWorkNotification` type `22`. Types `17`, `20`, and `21` retain no-producer caveats after checking every Event-vtable construction site and all five out-of-line constructor callers; type `20` is explicitly suppressed by EventDispatcher before routing.

## Accepted UID00014B Lifecycle And Source Policy

- UID00014B is exact `0x004a8a90-0x004a8abf`: 32-byte constructor plus 15-byte ordinary destructor, followed by one outside `0xcc` byte before the first classifier.
- Constructor source initializes `m_type` to `kEventNone`; destructor source resets it. LObject calls, vptr stores, return-this/tail-call shape, EH cleanup, scalar delete flags, and RTTI/vtable bytes remain compiler output.
- Constructor has five calls: Main_WndProc type22/type19 routes, MapPane default temporary, retained mouse helper, and retained key helper. The ordinary destructor has six normal calls plus 43 EH cleanup refs; Event vtable has 79 refs including inlined factories.
- [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md) emits only a marker covered by UID00014B; [UID:0003I7][0x006196a0-0x006196b0.EventVtableData](by-memory/0x006196a0-0x006196b0.EventVtableData.md) emits only a marker covered by the Event declaration/destructor. Handwritten ABI wrapper or raw vtable arrays are rejected.
- RTTI/name inventory contains one Event record class and no Event-derived class or alternate Event-record vtable. EventHandler/EventDispatcher/EventMan and RankingEvent UI classes are separate types.
- A separate EventLayout page or source file is rejected because UID00004L is the canonical declaration/layout owner. EventDispatcher ownership is rejected because it consumes ready records. EventMan owns the receiver-bearing IME producer methods but not base Event lifecycle, Main_WndProc construction, or the separate packet helpers, so the Event record declaration remains independently owned.
- Exact original spellings/header split remain confidence caps only. Accepted names are period-appropriate descriptive source names and do not block exact child source.

## Boundary Notes

- IDA confirms exact starts at `0x004a8a90`, `0x004a8ab0`, and `0x004ab3f0` for base `Event`.
- IDA confirms exact `EventMan` starts from `0x004a8b40` through `0x004ab440`; class methods are non-contiguous because packet/event-record helpers and compiler support occupy gaps. The `0x004a9a40-0x004a9f00` IME band is receiver-bearing despite decompiler loss of `this` in bodies that do not read it.
- IDA callers show `EventMan::EventMan` is called from `Application::Initialize`, while the IME event factories are called from `InputMan::HandleWindowMessage`.
- 2026-06-17 B001 source-quality reanalysis for [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) confirms the IME candidate-list factory at `0x004a9e50` stores the visible candidate deque pointer in the Event payload field consumed at `+0x08` and stores selected row in the field consumed at `+0x0c`.
- 2026-06-11 B001 live IDA recheck confirms the EventMan key tables at `0x0066d888` and `0x0066d988` have their only direct xrefs from the EventMan constructor, each copy uses size `0x100`, and the successor `0x0066da88` belongs to FolderSelectDialog rather than the event module.
- The old broad EventObjects memory doc has been split. [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md) and [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md) are exact Event-owned pages; [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) is a mixed Event.cpp helper island.
- 2026-06-04 live IDA recheck confirms the base `Event` constructor `0x004a8a90-0x004a8ab0`, destructor `0x004a8ab0-0x004a8abf`, and scalar deleting destructor `0x004ab3f0-0x004ab435`, with `Event` vtable data at `0x006196a0-0x006196b0` and the following `EventMan` RTTI/vtable beginning at `0x006196b0`.
- 2026-06-12 Agent-C001 live IDA MCP recheck confirms the mixed Event.cpp helper island starts at `0x004a8ac0` and ends at `0x004ab3eb`, followed by five `0xcc` bytes, the exact Event scalar deleting destructor, eleven `0xcc` bytes, the exact EventMan scalar deleting destructor, and ten `0xcc` bytes before `ExceptionHandler`.
- 2026-06-19 B008 source-quality work correctly established a mixed Event.cpp island, the `EventMan::TranslateEventKey` identity, packet/notification/timer helpers, and retained duplicate bodies. Its free-IME-factory interpretation for `0x004a9a40-0x004a9f00` is now historicalized: current InputMan call sites pass `g_pEventMan` in ECX, proving source-facing EventMan member declarations.

## UID0000K6 Receiver-Call Historicalization - 2026-08-24

- Active source-facing classification is `EventMan::DispatchImeOpenStatusEvent`, `DispatchCompositionTextEvent`, `DispatchCompositionStartEvent`, `DispatchCompositionResultEvent`, `DispatchCompositionEndEvent`, `DispatchCandidateListEvent`, and `DispatchCandidateCloseEvent` for `0x004a9a40-0x004a9f00`.
- Every InputMan call loads `g_pEventMan` into ECX. Bodies that ignore the receiver can decompile as `__stdcall`, but that artifact does not erase the call-site object model. UID00004O's complete formal H now exposes these member declarations with Windows/deque/string dependencies.
- Event.cpp ownership, mixed aggregate boundaries, packet-helper classifications from `0x004a9fa0`, Event payload layout, and dispatcher ownership remain unchanged. This is a corrected source-facing declaration/call-shape decision, not a split or body move.

## Cross-References

- [UID:00004L][Event](by-class/Event.md)
- [UID:00004O][EventMan](by-class/EventMan.md)
- [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md)
- [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md)
- [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md)
- [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md)
- [UID:0003LV][0x004ab440-0x004ab476.EventManScalarDeletingDestructor](by-memory/0x004ab440-0x004ab476.EventManScalarDeletingDestructor.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000K6][InputMan](by-file/InputMan.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- 2026-08-24 B008 UID0000K6 accepted implementation callback: historicalized every active free-IME-factory claim for `0x004a9a40-0x004a9f00`, documented the `g_pEventMan` ECX receiver proof and exact EventMan method set, retained Event.cpp ownership and packet-helper distinctions, and synchronized the complete UID00004O header contract consumed by InputMan.

- 2026-07-14 B002 UID00048I implementation callback:
  - Preserved `91/92`, `NexusTK/ui/core/`, `CANONICAL_OWNER:FILE`, all unrelated Event/EventMan source-family detail, and the by-file prose-only/non-emitting policy.
  - Corrected pointer/mouse payload prose to y `+0x08` then x `+0x0c`; recorded EventMan producer, UID00048N consumer, `PointInRect(y,x,...)`, and UID00004L declaration convergence; retained exact confidence limits and explicitly historicalized the prior reversed assumption without adding reconstruction metadata/body.

- 2026-07-12 B002 accepted UID00014B file synchronization:
  - Changed `88/89 -> 91/92`; preserved `NexusTK/ui/core/` and file ownership.
  - Incorporated exact Event declaration/layout, source constructor/destructor, five constructor calls, 49 destructor refs, 79 vtable refs, corrected variant payload offsets, type19/type22 producer routes, types17/20/21 no-producer caveats, scalar/vtable marker policy, no-subclass evidence, source/compiler boundary, and rejected alternate owners/layout page/raw ABI source.

- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Before: `COMPLETION:86`, `CONFIDENCE:86`; the file page described Event/EventMan/factory ownership but did not carry the resolved Event type-family classifier map, the `0x004a8b10` key-translation decision, the retained duplicate helper status, or the notification router naming caveat.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: B008 rechecked [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) as a mixed Event.cpp island, resolved Event classifiers, EventMan methods, IME/packet factories, `EventMan::PostNotification`, Event type and union-style payload directions, retained no-direct-xref helper bodies, and split-first C++ policy. Exact source-file split between one `Event.cpp` and a possible adjacent `EventMan.cpp` remains a caveat, so confidence stays below final.
- 2026-06-04 projected path and base-event evidence refresh:
  - What existed before: projected reconstruction path was blank, score was `82/78`, and the page still cited emitted-source provenance instead of only current evidence.
  - Changed to: projected path `NexusTK/ui/core/`, score `84/82`, and documentation-only reconstruction status.
  - Summary/evidence: live IDA confirms the base `Event` method bounds, `Event` vtable data before the adjacent `EventMan` RTTI/vtable, and the same UI-core ownership already argued by the `EventDispatcher`, `InputMan`, and `EventMan` separation notes.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: event object/factory role, proposed contents, method families, EventMan/IME/payload factory boundaries, InputMan/EventDispatcher separation, and broad memory-range caveat are documented; confidence remains medium-high because final `EventMan` source split remains open.
- 2026-06-11 Agent-B001 B001-041 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:82`; the source-file page was below the corrected `85/85` gate for EventMan-owned children.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP confirmed [UID:00027C][0x0066d888-0x0066da88.EventManKeyTranslationTables](by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md) table ownership by the EventMan constructor and the Event.cpp companion placement. The then-recorded free-event-factory wording is historical: the IME band is now receiver-bearing EventMan source, while packet helpers retain separate free-helper disposition. The final one-file `Event.cpp` versus adjacent `EventMan.cpp` split remains an explicit caveat, so scores stay below final-audit levels.
- 2026-06-12 Agent-C001 Goal 2 barrier repair:
  - Before: main memory references used the broad EventObjects and first-to-last EventMan ranges.
  - Changed to: references now use the exact Event ctor/dtor page, mixed Event.cpp helper island, exact Event scalar deleting destructor, and exact EventMan scalar deleting destructor pages.
  - Summary/evidence: live IDA MCP confirmed the broad overlap was a real range/structure issue. The source file remains the correct parent for the mixed helper island, while exact Event and EventMan child pages attach to their direct classes.
- 2026-06-17 B001 support update:
  - Changed support wording without changing score.
  - Summary/evidence: [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) validates `0x004a9e50` as the candidate-list Event type `15` factory carrying candidate deque pointer and selected row from `InputMan` to `IMECandidatePane`.

## UID0004QZ Copied Packet-Event Source Integration - 2026-07-15

- File metadata remains `91/92` with `NexusTK/ui/core/` ownership. The mixed UID00014C range remains an evidence/index page with blank aggregate C++; exact children emit source independently.
- [UID:0004QZ][0x004aa050-0x004aa109.DispatchCopiedEventPayload](by-memory/0x004aa050-0x004aa109.DispatchCopiedEventPayload.md) is the exact free Event.cpp child at `92/94`, reconstructable true, owner/emitter UID0000J6, blank position, and `Nested:0`.
- The helper allocates/copies the caller payload, constructs Event type 18 with packet kind zero/data/size, and dispatches through `g_pEventDispatcher`. EventDispatcher owns/frees the copied pointer after synchronous dispatch; caller stack payloads remain borrowed.
- Direct callers are the [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md) status-event path at `0x005a36c1` plus UserPane callers `0x005a507d` and `0x005a5e18`. Cross-caller/no-receiver evidence rejects UserPane, MapPane, or EventDispatcher member ownership.
- The stack Event destructor/unwind is compiler-only support. No explicit source EH, cleanup body, vptr write, ownership guard, smart pointer, or duplicate aggregate body is introduced; all unrelated Event/EventMan factories, type maps, tables, retained helpers, and scores remain unchanged.
