** TARGET-REPORT-UID:00014C **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014C EventManAndEventFactoryHelpers Source Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00014C] as a reconstructable mixed `Event.cpp` source-module helper island owned/emitted by [UID:0000J6] `Event`, but do not populate a monolithic formal C++ block on this aggregate.
- Final disposition: update the target as an audited mixed container, then split exact child pages before source C++ is entered for individual routines or routine families.
- Required action: implement target/support documentation updates at report-level detail, update metadata to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000J6`, keep `EMITTER_UIDS:0000J6`, keep `RECONSTRUCTABLE:TRUE`, and preserve a blank aggregate `RECONSTRUCTION_CPP` block with the no-code/defer proof below.
- Confidence: high for range, mixed source-module disposition, owner/emitter, caller/callee families, event type map, and split-first C++ policy; medium-high for exact original source spellings of a few helper names and for the final `Event.cpp` versus separate `EventMan.cpp` historical source split.

## Target

- Target UID: `00014C`
- Target path: `source-3/project-documentation/by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00014C-EventManAndEventFactoryHelpers-source-quality.md`
- Current metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000J6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J6`, blank formal C++.
- Current coverage row state: stale. It still describes `0x004a8b40-0x004ab476 | class aggregate | EventMan : reconstructable : 84%`, even though the current target is the exact `0x004a8ac0-0x004ab3eb` mixed Event.cpp island.

## Supervisor Active Recheck

- The active supervisor correction requires a report-only pass for [UID:00014C] after the previous callback did not create the report file.
- I did not edit the target, support by-* docs, or `by-memory/-coverage-report.md`.
- The assigned target is split-capable and mixed, but this callback explicitly says report-only. Therefore this report gives the exact split plan, exact support update checklist, and exact supervisor-owned coverage text instead of performing splits or documentation edits now.

## Inference Research Guidance Check

- Rule 21 and Rule 23 require resolving source-quality issues instead of copying old uncertainty. This report rechecks raw helper names, event field names, caller/reachability, ownership, source placement, split policy, and final-C++ blockers.
- Rule 24 and Rule 26 require any C++ recommendation to look like plausible source and stay inside the emitting scope. Because this target is a mixed aggregate of many exact functions plus a retained no-xref helper band, one formal aggregate C++ block would either over-emit unrelated routines or erase important split boundaries. The correct first-draft C++ path is split-first.
- Rule 27 requires targeted open-question closure. The old target questions about pre-EventMan helper semantics, `ctype/narrow` naming, late event-record helpers, field names, source route, and final C++ are resolved or bounded below with the exact evidence checked.
- Rule 29 and Rule 30 require accepted report details to be carried into by-* docs later by implementation callback. The exact implementation checklist is included below.

## Evidence Standards Used

- Existing live IDA-backed project documentation for function starts, ends, data refs, vtable slots, callers/callees, and previous date-stamped IDA MCP checks.
- Local PE and Capstone-style range split evidence for the executable `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, `.text` containing the target range, padding bytes, rel32 call xrefs, and apparent function inventory.
- Cross-document evidence from `Event`, `EventMan`, `EventDispatcher`, `EventHandler`, `InputMan`, IME, `LogoPlayerPane`, `SocketEventDispatchHelpers`, `ApplicationShutdown`, notification research, `g_pEventMan`, and vtable data pages.
- Negative evidence: no local direct code/data xrefs found for most late helper starts `0x004aa470-0x004ab3c3`; no direct evidence that `InputMan`, `EventDispatcher`, `Socket`, or notification consumers own the helper bodies; no evidence that the whole range is a single EventMan class aggregate.
- IDA MCP caveat: the MCP server was not reachable during this resumed pass, so new live IDA calls could not be made. The report relies on current by-* pages that already preserve prior live IDA facts, plus local PE/Capstone/xref evidence.

## IDA / Binary Facts

### Range And Padding

- Exact target range: `0x004a8ac0-0x004ab3eb` half-open.
- The byte before the target at `0x004a8abf-0x004a8ac0` is `0xcc` padding after the base `Event` destructor.
- Existing live IDA documentation confirms the first function in this island is at `0x004a8ac0`.
- Existing live IDA documentation confirms the last function before the Event scalar deleting destructor is `0x004ab3e0`, size `0x0b`, ending at `0x004ab3eb`.
- The gap `0x004ab3eb-0x004ab3f0` is five `0xcc` bytes before [UID:0003LU] `EventScalarDeletingDestructor` at `0x004ab3f0`.
- The old coverage row ending at `0x004ab476` crossed two separate scalar deleting destructors and padding. That stale row should be replaced.

### Confirmed Source Families In The Range

- `0x004a8ac0-0x004a8b0b`: five `Event`-record classifier helpers used by `EventDispatcher` to choose handler slots.
- `0x004a8b10-0x004a8b3e`: small `EventMan` keyboard/key-state helpers before the constructor, including a key translation adaptor currently misdescribed as a `ctype/narrow` helper.
- `0x004a8b40-0x004a8f35`: `EventMan` constructor and ordinary destructor.
- `0x004a8f40-0x004a8f75`: EventMan-owned shutdown/timer wrappers.
- `0x004a8f80-0x004a99db`: EventMan cursor, mouse, wheel, keyboard, character, and state methods.
- `0x004a99e0-0x004a9a32`: caps/num/key state accessors.
- `0x004a9a40-0x004a9f00`: free IME event factories called by `InputMan`.
- `0x004a9fa0-0x004aa1b3`: packet/payload event factories and type `18` wrappers.
- `0x004aa1c0-0x004aa1cf`: dispatch-existing-event wrapper.
- `0x004aa1d0-0x004aa1f4`: EventMan/application notification post helper.
- `0x004aa200-0x004aa46b`: EventMan timer tick and cursor dispatch helpers.
- `0x004aa470-0x004ab3c3`: late no-direct-xref retained/duplicate event-record helper band mirroring mouse, IME, key, and packet factories.
- `0x004ab3d0-0x004ab3df`: retained dispatch-existing-event wrapper.
- `0x004ab3e0-0x004ab3eb`: singleton clear helper used by EH/unwind support, clearing `g_pEventMan`.

## Function / Child Inventory

| Range | Best source-facing role/name | Evidence and status |
| --- | --- | --- |
| `0x004a8ac0-0x004a8ac8` | `Event::IsPointerEvent()` / `Event::IsMouseEvent()` | Called by EventDispatcher classifier sites; tests event type `<= 7`. Descriptive/inferred. |
| `0x004a8ad0-0x004a8adb` | `Event::IsKeyboardEvent()` / `Event::IsKeyOrTextEvent()` | Called by EventDispatcher; accepts types `8..10`. Descriptive/inferred. |
| `0x004a8ae0-0x004a8aeb` | `Event::IsImeEvent()` | Called by EventDispatcher; accepts types `11..17`. Descriptive/inferred. |
| `0x004a8af0-0x004a8af9` | `Event::IsPacketEvent()` | Called by EventDispatcher; exact type `18`. Descriptive/inferred. |
| `0x004a8b00-0x004a8b0b` | `Event::IsSystemEvent()` / `Event::IsControlEvent()` | Called by EventDispatcher; accepts types `20..22`. Type `19` is handled by EventDispatcher as a special exact slot. Descriptive/inferred. |
| `0x004a8b10-0x004a8b1a` | `EventMan::TranslateEventKey(unsigned char key, unsigned char modifiers)` | 81 local call refs from pane/handler/EventDispatcher code; body returns first argument and pops two args. Old `ctype/narrow helper` label is rejected. |
| `0x004a8b20-0x004a8b3e` | `EventMan::ResetKeyboardState()` / `ClearInputState()` | Called from application/window focus path; clears key/modifier state. Descriptive/inferred. |
| `0x004a8b40-0x004a8f13` | `EventMan::EventMan()` | Constructor called from `Application::Initialize`; initializes `TimerHandler`, installs singleton, cursor policy, and key tables. Confirmed class method. |
| `0x004a8f20-0x004a8f35` | `EventMan::~EventMan()` | Ordinary destructor; writes EventMan vtable, clears `g_pEventMan`, tail-calls `TimerHandler` destructor. Confirmed class method. |
| `0x004a8f40-0x004a8f56` | `EventMan::ShutdownPacketEventSource()` / `CloseSocketEventStream()` | Called by `ApplicationShutdown`; calls Socket helper `0x00574b20` and virtual slot `+0x0c` on `g_packetSender`-like global `0x0067a7ec`. Descriptive/inferred. |
| `0x004a8f60-0x004a8f6e` | `EventMan::StartCursorTimer()` | Calls timer scheduler `0x005975e0` with delay `0x14`; called by UI/application paths. Descriptive/inferred. |
| `0x004a8f70-0x004a8f75` | `EventMan::StopCursorTimer()` | Tail-jumps timer cancel/remove helper `0x00597600`; called by paired application/UI paths. Descriptive/inferred. |
| `0x004a8f80-0x004a908f` | retained `EventMan::DispatchCursorIfChanged(...)` | No local direct xrefs found; same shape as later cursor helpers; do not mark active until xrefs are proven. |
| `0x004a9090-0x004a90a5` | `EventMan::GetCursorPosition(Point *out)` | Broad UI helper fan-in; copies stored cursor coordinates. Confirmed/descriptive. |
| `0x004a90b0-0x004a90c2` | `EventMan::GetModifierState(unsigned char *out)` | Copies modifier byte/word from EventMan state. Descriptive/inferred. |
| `0x004a90d0-0x004a90fd` | `EventMan::ClearKeyboardState()` | Clears `this+0x820`, `this+0x920`, and nearby flag bytes. Descriptive/inferred. |
| `0x004a9100-0x004a9115` | `EventMan::ForwardCursorEvent(...)` | Called from window message path and forwards to `0x004aa3b0`. Confirmed/descriptive. |
| `0x004a9120-0x004a925a` | `EventMan::DispatchLeftButtonDown(...)` | Emits type `1` or type `2` after threshold checks. Descriptive/inferred. |
| `0x004a9260-0x004a9356` | `EventMan::DispatchLeftButtonUp(...)` | Emits type `3` then cursor type `0`; validated by pane consumers as left release/up. Descriptive/inferred. |
| `0x004a9360-0x004a949a` | `EventMan::DispatchRightButtonDown(...)` | Emits type `4` or type `5` after threshold checks. Descriptive/inferred. |
| `0x004a94a0-0x004a9596` | `EventMan::DispatchRightButtonUp(...)` | Emits type `6` then cursor type `0`. Descriptive/inferred. |
| `0x004a95a0-0x004a969f` | `EventMan::DispatchMouseWheel(...)` | Emits type `7` and cursor update. Descriptive/inferred. |
| `0x004a96a0-0x004a97dc` | `EventMan::DispatchKeyDown(...)` | Updates key/modifier state, calls `ToAscii`, handles app-exit shortcut, dispatches type `8`. Descriptive/inferred. |
| `0x004a97e0-0x004a989a` | `EventMan::DispatchCharEvent(...)` | Dispatches type `10` for `WM_CHAR`/text input. Descriptive/inferred. |
| `0x004a98a0-0x004a99db` | `EventMan::HandleKeyUp(...)` | Prepares type `9`, clears state, runs UserPane spacebar gate, no dispatcher call in verified live path. Descriptive/inferred. |
| `0x004a99e0-0x004a99f0` | `EventMan::SetCapsLockState(bool)` | Called after `GetKeyState(0x14)`; stores `this+0x921`. Descriptive/inferred. |
| `0x004a99f0-0x004a9a00` | `EventMan::SetNumLockState(bool)` | Called after `GetKeyState(0x90)`; stores `this+0x922`. Descriptive/inferred. |
| `0x004a9a00-0x004a9a07` | `EventMan::GetCapsLockState()` | Getter for `this+0x921`; no local direct refs found. Descriptive/inferred. |
| `0x004a9a10-0x004a9a17` | `EventMan::GetNumLockState()` | Getter for `this+0x922`; no local direct refs found. Descriptive/inferred. |
| `0x004a9a20-0x004a9a32` | `EventMan::GetRawKeyState(unsigned int key)` | Reads byte array at `this+0x120+key`; no local direct refs found. Descriptive/inferred. |
| `0x004a9a40-0x004a9ad9` | `DispatchImeOpenStatusEvent(BOOL isOpen, int tickCount)` | Called by `InputMan`; emits type `11`, payload open flag at Event `+0x08`, tick at Event `+0x10c`. Confirmed free helper. |
| `0x004a9ae0-0x004a9c04` | `DispatchCompositionTextEvent(const wchar_t *text, int tickCount)` | Called from InputMan composition-string path; emits type `10` composition/text event. Descriptive/inferred. |
| `0x004a9c10-0x004a9cb0` | `DispatchCompositionStartEvent(int tickCount)` | Called by `InputMan`; emits type `12`. Confirmed free helper. |
| `0x004a9cb0-0x004a9daa` | `DispatchCompositionResultEvent(const wchar_t *text, int tickCount)` | Called by `InputMan`; emits type `13`, copies UTF-16 result text. Confirmed free helper. |
| `0x004a9db0-0x004a9e50` | `DispatchCompositionEndEvent(int tickCount)` | Called by `InputMan`; emits type `14`. Confirmed free helper. |
| `0x004a9e50-0x004a9ef2` | `DispatchCandidateListEvent(int selectedRow, CandidateStringList *visibleCandidates, int tickCount)` | Called by `InputMan`; emits type `15`, stores candidate deque pointer at Event `+0x08` and selected row at Event `+0x0c`. Confirmed free helper. |
| `0x004a9f00-0x004a9fa0` | `DispatchCandidateCloseEvent(int tickCount)` | Called by `InputMan`; emits type `16`. Confirmed free helper. |
| `0x004a9fa0-0x004aa043` | `DispatchRawPacketEvent(...)` / `DispatchPacketReferenceEvent(...)` | Called from main window packet path; emits type `18`, flag `1`, pointer and size fields. Descriptive/inferred. |
| `0x004aa050-0x004aa109` | `DispatchCopiedEventPayload(const void *data, int size)` | Called by UserPane-related helpers; allocates via `0x005c7790`, copies with `_memmove` `0x005c95b0`, emits type `18`, flag `0`. Descriptive/inferred. |
| `0x004aa110-0x004aa1b3` | `DispatchPacketEvent(const void *data, int size)` | Called from main window packet path; emits type `18`, no internal copy, flag `0`. Descriptive/inferred. |
| `0x004aa1c0-0x004aa1cf` | `DispatchEvent(Event *event)` / `DispatchExistingEvent(Event *event)` | Thin wrapper loading `g_pEventDispatcher` and jumping to dispatcher. Descriptive/inferred. |
| `0x004aa1d0-0x004aa1f4` | `EventMan::PostNotification(unsigned int channel, LObject *payload)` | 12 call refs from notification users; posts message `0x406` through `g_pfnPostMessageW` after `Application::GetWindowHandle`. Descriptive/inferred. |
| `0x004aa200-0x004aa22b` | `EventMan::OnTimerTick()` | EventMan vtable timer slot; dispatches cursor state and schedules next timer. Confirmed class method. |
| `0x004aa230-0x004aa33b` | retained `EventMan::DispatchCursorIfChanged(...)` | No local direct refs found; duplicate cursor-change helper shape. Retained helper candidate. |
| `0x004aa340-0x004aa355` | retained `EventMan::GetCursorPosition(Point *out)` | No local direct refs found; duplicate getter shape. Retained helper candidate. |
| `0x004aa360-0x004aa372` | retained `EventMan::GetModifierState(unsigned char *out)` | No local direct refs found; duplicate getter shape. Retained helper candidate. |
| `0x004aa380-0x004aa3ad` | retained `EventMan::ClearKeyboardState()` | No local direct refs found; duplicate clear-state shape. Retained helper candidate. |
| `0x004aa3b0-0x004aa46b` | `EventMan::DispatchCursorEvent(...)` | Called by `ForwardCursorEvent` and timer tick; dispatches type `0`. Confirmed/descriptive. |
| `0x004aa470-0x004aa590` | retained left-button down/double helper | No local direct refs found; mirrors live type `1/2` body. Retained helper candidate. |
| `0x004aa590-0x004aa686` | retained left-button release helper | No local direct refs found; mirrors type `3` body. Retained helper candidate. |
| `0x004aa690-0x004aa7b0` | retained right-button down/double helper | No local direct refs found; mirrors type `4/5` body. Retained helper candidate. |
| `0x004aa7b0-0x004aa8a6` | retained right-button release helper | No local direct refs found; mirrors type `6` body. Retained helper candidate. |
| `0x004aa8b0-0x004aa9af` | retained mouse-wheel helper | No local direct refs found; mirrors type `7` body. Retained helper candidate. |
| `0x004aa9b0-0x004aaa49` | retained IME open-status helper | No local direct refs found; mirrors type `11` body. Retained helper candidate. |
| `0x004aaa50-0x004aab74` | retained composition-text helper | No local direct refs found; mirrors type `10` body. Retained helper candidate. |
| `0x004aab80-0x004aac20` | retained composition-start helper | No local direct refs found; mirrors type `12` body. Retained helper candidate. |
| `0x004aac20-0x004aad1a` | retained composition-result helper | No local direct refs found; mirrors type `13` body. Retained helper candidate. |
| `0x004aad20-0x004aadc0` | retained composition-end helper | No local direct refs found; mirrors type `14` body. Retained helper candidate. |
| `0x004aadc0-0x004aae62` | retained candidate-list helper | No local direct refs found; mirrors type `15` body. Retained helper candidate. |
| `0x004aae70-0x004aaf10` | retained candidate-close helper | No local direct refs found; mirrors type `16` body. Retained helper candidate. |
| `0x004aaf10-0x004ab04c` | retained key-down helper | No local direct refs found; mirrors type `8` body. Retained helper candidate. |
| `0x004ab050-0x004ab10a` | retained char/text helper | No local direct refs found; mirrors type `10` body. Retained helper candidate. |
| `0x004ab110-0x004ab24b` | retained key-up helper | No local direct refs found; mirrors type `9` body. Retained helper candidate. |
| `0x004ab250-0x004ab260` | retained `SetCapsLockState(bool)` | No local direct refs found; duplicate setter shape. Retained helper candidate. |
| `0x004ab260-0x004ab270` | retained `SetNumLockState(bool)` | No local direct refs found; duplicate setter shape. Retained helper candidate. |
| `0x004ab270-0x004ab313` | retained packet reference helper | No local direct refs found; mirrors type `18` flag `1` body. Retained helper candidate. |
| `0x004ab320-0x004ab3c3` | retained packet helper | No local direct refs found; mirrors type `18` flag `0` body. Retained helper candidate. |
| `0x004ab3d0-0x004ab3df` | retained dispatch-existing-event wrapper | No local direct refs found; duplicate wrapper shape. Retained helper candidate. |
| `0x004ab3e0-0x004ab3eb` | `EventMan::ClearSingletonForUnwind()` / EH singleton clear helper | Existing docs record EH/unwind ref; clears `g_pEventMan`. Compiler/EH support helper, no standalone source C++. |

## Direct Xref / Caller Inventory

| Address / item | Direct caller evidence | Meaning |
| --- | --- | --- |
| `0x004a8ac0` | `0x004a72e3`, `0x004a77f8`, `0x004a780f` | EventDispatcher pointer/mouse classifier. |
| `0x004a8ad0` | `0x004a747d`, `0x004a77ed`, `0x004a7832` | EventDispatcher key/text classifier. |
| `0x004a8ae0` | `0x004a7855` | EventDispatcher IME classifier. |
| `0x004a8af0` | `0x004a6f19`, `0x004a7878` | EventDispatcher packet classifier. |
| `0x004a8b00` | `0x004a78b9` | EventDispatcher system/control classifier. |
| `0x004a8b10` | 81 local call refs from pane/handler/EventDispatcher paths | Key translation adaptor, not CRT helper. |
| `0x004a8b20` | `0x0046601b` | Focus/reset path clears keyboard state. |
| `0x004a8b40` | `0x0046463f` | Application initialization constructs `EventMan`. |
| `0x004a8f40` | `0x004f64a7` | Application shutdown packet/event-source close path. |
| `0x004a8f60` | `0x004f420e`, `0x0054b0da` | Timer scheduling/start wrapper. |
| `0x004a8f70` | `0x004f42d5`, `0x0054b1d6` | Timer stop/cancel wrapper. |
| `0x004a9090` | 68 local refs | Broad UI cursor-position accessor. |
| `0x004a90b0` | 6 local refs | Modifier-state accessor. |
| `0x004a90d0` | `0x004669d9`, `0x00466acc` | Keyboard state clear/reset. |
| `0x004a9100` | `0x004663f0` | Cursor event forwarding from input message path. |
| `0x004a9120` | `0x00466438` | Left button down/double path. |
| `0x004a9260` | `0x00466454` | Left release/up path. |
| `0x004a9360` | `0x00466487` | Right button down/double path. |
| `0x004a94a0` | `0x004664a9` | Right release/up path. |
| `0x004a95a0` | `0x0046650d` | Mouse wheel path. |
| `0x004a96a0` | `0x0046620c` | Key down path. |
| `0x004a97e0` | `0x004e8eb3` | Character event from InputMan. |
| `0x004a98a0` | `0x00466264` | Key release path. |
| `0x004a99e0` | `0x00466980` after `GetKeyState(0x14)` | Caps-lock state setter. |
| `0x004a99f0` | `0x004669b3` after `GetKeyState(0x90)` | Num-lock state setter. |
| `0x004a9a40` | `0x004e8ffe` | IME open status event from InputMan. |
| `0x004a9ae0` | `0x004e8f45` | IME composition text event from InputMan. |
| `0x004a9c10` | `0x004e8ecc` | Composition start event. |
| `0x004a9cb0` | `0x004e8f0a` | Composition result/commit event. |
| `0x004a9db0` | `0x004e8f5e` | Composition end event. |
| `0x004a9e50` | `0x004e927d` | Candidate-list event, type `15`. |
| `0x004a9f00` | `0x004e92ac` | Candidate-close event, type `16`. |
| `0x004a9fa0` | `0x00466665` | Type `18` packet/reference helper. |
| `0x004aa050` | `0x005a36c1`, `0x005a507d`, `0x005a5e18` | Type `18` copied payload helper. |
| `0x004aa110` | `0x00466679` | Type `18` packet/event helper. |
| `0x004aa1d0` | 12 notification refs in notification-related pages | Posts message `0x406` through application window. |
| `0x004aa200` | EventMan vtable slot at `0x006196b8` | Timer tick virtual. |
| `0x004aa3b0` | `0x004a910c`, `0x004aa211` | Cursor event dispatch. |
| `0x004aa470-0x004ab3c3` | no direct code/data xrefs found in local scan | Retained duplicate/helper band, not proven active. |
| `0x004ab3e0` | EH/unwind ref recorded in docs | Singleton clear helper. |

## Event Type And Payload Map

| Type | Best source-facing name | Producer evidence | Payload evidence |
| --- | --- | --- | --- |
| `0` | `kEventCursorMove` / `kEventCursor` | `EventMan::DispatchCursorEvent` | Cursor coordinates and tick/state fields. |
| `1` | `kEventLeftButtonDown` | left button down method | Position, prior/down position, modifier/tick fields. |
| `2` | `kEventLeftButtonDoubleClick` | left threshold method | Same pointer payload family as type `1`. |
| `3` | `kEventLeftButtonUp` | left release method, pane consumers | Position/state fields; validated by `LogoPlayerPane` support docs. |
| `4` | `kEventRightButtonDown` | right button down method | Pointer payload family. |
| `5` | `kEventRightButtonDoubleClick` | right threshold method | Pointer payload family. |
| `6` | `kEventRightButtonUp` | right release method | Pointer payload family. |
| `7` | `kEventMouseWheel` | wheel method | Pointer payload plus wheel delta in type-specific payload. |
| `8` | `kEventKeyDown` | key down method; pane consumers | Translated key byte at Event `+0x08`; modifier/state bytes in nearby payload; tick at Event `+0x10c`. |
| `9` | `kEventKeyUp` | key release method prepares the record | Verified path does not call `DispatchEvent`; do not overclaim live dispatch. |
| `10` | `kEventChar` / `kEventTextInput` / composition text | `DispatchCharEvent` and composition-text helper | Character or UTF-16 text buffer; composition helper appears to use text buffer beginning after the primary payload bytes. |
| `11` | `kEventImeOpenStatus` | `DispatchImeOpenStatusEvent` | Open/closed flag at Event `+0x08`, tick at Event `+0x10c`. |
| `12` | `kEventImeCompositionStart` | `DispatchCompositionStartEvent` | Empty/start composition payload, tick. |
| `13` | `kEventImeCompositionResult` | `DispatchCompositionResultEvent` | UTF-16 committed text copied into event record, tick. |
| `14` | `kEventImeCompositionEnd` | `DispatchCompositionEndEvent` | Empty/end composition payload, tick. |
| `15` | `kEventImeCandidateList` | `DispatchCandidateListEvent`; `IMECandidatePane` consumer | Candidate deque/list pointer at Event `+0x08`, selected row at Event `+0x0c`, tick at Event `+0x10c`. |
| `16` | `kEventImeCandidateClose` | `DispatchCandidateCloseEvent` | Close marker/tick. |
| `17` | reserved/IME-family accepted type | EventDispatcher classifier accepts `11..17`; no target producer found | Keep as reserved/unknown IME family until producer found. |
| `18` | `kEventPacket` / `kEventPayload` | packet helpers at `0x004a9fa0`, `0x004aa050`, `0x004aa110` | Ownership/copy flag at Event `+0x08`, data pointer at Event `+0x0c`, size at Event `+0x10`. |
| `19` | special EventHandler slot type | EventDispatcher routes exact `19` separately | No target producer found. |
| `20..22` | system/control/UI event family | EventDispatcher classifier accepts range | No target producer found; keep source name provisional. |

### Event Record Field Names

The target should stop using generic "event-record helper" wording without field context. The best source-facing field names should be added as provisional union-style fields:

- `Event::m_type` at `+0x04`: confirmed by base constructor/destructor defaulting to `0xff` and every producer storing a type.
- `Event::m_payload0` / type-specific union at `+0x08`: key byte, IME open flag, candidate list pointer, packet ownership flag, or first pointer/state field depending on type.
- `Event::m_payload1` / type-specific union at `+0x0c`: selected row for candidates, packet pointer, modifier/state field, or coordinate/state field depending on type.
- `Event::m_payload2` / type-specific union at `+0x10`: packet size, text/coordinate/wheel family field depending on type.
- `Event::m_payload3` / type-specific union at `+0x14`: wheel delta or pointer-family field in wheel/mouse methods.
- `Event::m_text` / `m_compositionText` should be treated as an embedded UTF-16 text buffer used by type `10`, `13`, and related composition helpers. Exact offset and length should be recorded in child pages after split, not invented as a final class layout in the aggregate.
- `Event::m_tickCount` / `m_timestamp` at `+0x10c`: repeated producer stores show a common tick/message-time field near the end of the `0x110` event record.

These names are descriptive and source-quality-ready for documentation. Exact original spellings are not proven, so support docs should mark them inferred/descriptive.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Candidate interpretations | Decision and score/C++ impact |
| --- | --- | --- | --- |
| Whole target ownership | Target contains Event classifiers, EventMan methods, free IME/packet factories, notification helper, retained duplicate band, and EH singleton clear. | EventMan class owner; Event class owner; Event.cpp file owner. | Keep [UID:0000J6] `Event` file owner/emitter. Whole-range EventMan class ownership is rejected because many bodies are not EventMan methods. |
| Source file placement | Existing Event file docs, Event/EventMan/EventDispatcher/InputMan split, IME factories constructing Event records, packet helpers dispatching Event records. | `ui/core/Event.cpp`; separate `EventMan.cpp`; `InputMan.cpp`; `EventDispatcher.cpp`. | Strongest route remains `NexusTK/ui/core/Event.cpp` through [UID:0000J6]. A future separate `EventMan.cpp` is possible but not currently evidenced enough to create a new by-file owner. |
| Pre-EventMan helpers | Calls from EventDispatcher classifiers and type-range tests. | Unknown small helpers; Event methods; dispatcher helpers. | They are Event type-family predicate helpers. Descriptive names should replace "small event helper". |
| `0x004a8b10` old `ctype/narrow helper` label | 81 call refs, returns first argument, signature pops two args, surrounding EventMan keyboard code. | CRT/locale helper; key translation helper. | Reject CRT/locale. Rename/document as `EventMan::TranslateEventKey` or `TranslateEventKeyByte`; exact original name not proven. |
| EventMan constructor and destructor | Application initialization caller, TimerHandler base, singleton writes, vtable and key-table evidence, ordinary destructor tail-call to TimerHandler. | EventMan class methods; source-module free helpers. | Confirmed EventMan methods; child split should attach to [UID:00004O] after exact pages exist. |
| Shutdown helper `0x004a8f40` | ApplicationShutdown caller, Socket helper `0x00574b20`, vtable call on `0x0067a7ec`. | Socket owner; EventMan close helper; Application helper. | Best descriptive name `EventMan::ShutdownPacketEventSource` or `CloseSocketEventStream`. Body belongs Event.cpp/EventMan route because Application calls it to tear down event source. |
| Timer wrappers | Paired callers and timer scheduler/cancel helpers `0x005975e0`/`0x00597600`; EventMan timer vtable slot nearby. | TimerHandler methods; EventMan wrappers. | Treat as EventMan source wrappers around TimerHandler services. |
| IME factory ownership | InputMan callers; factory bodies construct Event records and call EventDispatcher; IME pane consumes type `15`. | InputMan owns bodies; Event.cpp owns bodies. | InputMan owns Win32/IMM message handling only. Bodies should stay Event.cpp free helper functions. |
| Packet factory ownership | Main window/UserPane callers; allocation/copy helpers; type `18` event payload. | Socket/UserPane owner; Event.cpp helper owner. | Callers supply packet data; Event.cpp owns event wrapping and dispatch. |
| Notification helper `0x004aa1d0` | 12 refs from notification docs; calls `Application::GetWindowHandle`, posts message `0x406` through global PostMessageW pointer. | Notification class method; EventMan helper; Application helper. | Best name `EventMan::PostNotification` or `PostApplicationNotification`. Caller evidence says many classes use it; body belongs event/application message routing, likely Event.cpp/EventMan support. |
| Late no-xref band | No local direct code/data refs to starts `0x004aa470-0x004ab3c3`; bodies mirror earlier active helpers and store same event types. | Dead garbage; compiler-generated thunks; retained duplicate source helpers; active hidden dispatch. | Not garbage and not scalar-delete/EH glue. Best documented as retained duplicate Event.cpp helper band until a hidden route is found. This is the main reason aggregate C++ must stay blank and split-first. |
| `0x004ab3e0` helper | Existing docs record EH/unwind ref; body clears `g_pEventMan`; immediately before padding/Event scalar dtor. | Source function; EH cleanup helper; destructor fragment. | Treat as compiler/EH singleton-clear support tied to EventMan construction/destruction. No standalone source C++. |
| Event type constants | EventDispatcher classifiers, producer stores, pane consumers, InputMan/IME docs. | Leave numbers only; create inferred enum names. | Add inferred enum/source names with caveats. Type `17`, `19`, `20..22` remain accepted/routed but producer-unresolved. |
| Event field names | Base Event layout, stack Event size `0x110`, producer stores, IME candidate consumer, packet helpers. | Single fixed struct field names; type-specific union. | Use union-style descriptive fields; exact original names not proven. Enough for documentation and child C++ drafts, not enough for one aggregate block. |
| Split/merge policy | Target has 69 apparent functions and multiple ownership families. | Keep as one exact item with giant C++; split into children; merge with EventMan scalar dtor. | Keep parent as container/audit and split exact child pages. Do not merge scalar deleting destructors back into this range. |
| Formal C++ eligibility | Current target is reconstructable, has emitter, and clears combined-score gate. Scope is mixed and includes no-xref retained helpers. | Emit one long C++ block; emit `//`; keep blank with explicit defer proof. | Keep blank for aggregate with explicit no-code/defer proof. Child pages should receive first-draft C++ where exact source scope is known. |

## Ranked Ownership Analysis

### 1. [UID:0000J6] `Event` / `NexusTK/ui/core/Event.cpp`

- Evidence for: the target contains base Event-adjacent predicates, EventMan source methods, free Event factories, IME Event wrappers, packet Event wrappers, and EventDispatcher calls. Existing Event file documentation already models `Event.cpp` as the event object/factory layer between `InputMan` and `EventDispatcher`.
- Evidence against: not every body is a method of `Event`, and `EventMan` might historically have lived in a separate `EventMan.cpp`.
- Decision: accept as canonical owner/emitter for the aggregate. This is a source-file ownership decision, not a class ownership claim.

### 2. [UID:00004O] `EventMan`

- Evidence for: many exact functions are EventMan methods; the constructor/destructor/timer/key/mouse/cursor helpers and `g_pEventMan` lifecycle are direct EventMan class material.
- Evidence against: the aggregate also contains Event predicates, free IME/packet factories, notification helper, and retained duplicate helper bodies. Assigning the whole target to EventMan would recreate the stale class-aggregate error.
- Decision: reject as owner for the aggregate; accept as direct semantic parent for future exact child pages covering EventMan methods.

### 3. [UID:00004L] `Event`

- Evidence for: the pre-EventMan classifiers are Event predicate helpers and the whole island constructs Event records.
- Evidence against: most of the target is not base `Event` class methods. Base Event constructor/destructor and scalar deleting destructor already have exact pages.
- Decision: reject as aggregate owner; accept as direct semantic parent for future exact classifier child page if split.

### 4. [UID:0000K6] `InputMan`

- Evidence for: InputMan calls the IME factory helpers and passes Win32/IMM state.
- Evidence against: factory bodies construct Event records and route through EventDispatcher. InputMan's source responsibility is message handling, not Event object construction.
- Decision: reject as owner; keep as caller/source-route evidence.

### 5. [UID:0000J7] `EventDispatcher`

- Evidence for: EventDispatcher calls classifier helpers and consumes dispatched Events.
- Evidence against: dispatcher owns routing of ready events, not producer/factory construction.
- Decision: reject as owner; update support docs with the clarified classifier/type map.

### 6. Socket/UserPane/notification consumer owners

- Evidence for: packet and notification callers fan into helpers in this island.
- Evidence against: callers provide payloads or request notifications; event wrapping, dispatch, and application message posting live in this Event.cpp cluster.
- Decision: reject as owners. They should cross-reference the helper names but not own them.

## Source Placement Recommendation

- Keep target source module as [UID:0000J6] `Event`, projected `NexusTK/ui/core/Event.cpp`.
- Update the Event file doc to say this page is not a single method range and not an EventMan-only source page. It is a mixed Event.cpp helper island containing exact source functions that should be split into children.
- Do not create a separate `EventMan.cpp` by-file page from this report alone. The evidence for Event.cpp is stronger because base Event, EventMan, Event factories, and free helper bodies are contiguous and already modeled together. A future split may revisit this only if project-wide file evidence appears.

## Split Recommendation

The aggregate should be split before any formal C++ is entered. Recommended child pages:

| Proposed child range | Proposed name | Direct parent/source route |
| --- | --- | --- |
| `0x004a8ac0-0x004a8b0b` | `EventTypeClassifiers` | [UID:00004L] `Event`, emitted by [UID:0000J6]. |
| `0x004a8b10-0x004a8b3e` | `EventManKeyboardStateSmallHelpers` | [UID:00004O] `EventMan`, emitted by [UID:0000J6]. |
| `0x004a8b40-0x004a8f35` | `EventManConstructorDestructor` | [UID:00004O] `EventMan`, emitted by [UID:0000J6]. |
| `0x004a8f40-0x004a8f75` | `EventManShutdownAndTimerWrappers` | [UID:00004O] `EventMan`, emitted by [UID:0000J6]. |
| `0x004a8f80-0x004a90fd` | `EventManCursorAndKeyboardStateHelpers` | [UID:00004O] `EventMan`, emitted by [UID:0000J6]. |
| `0x004a9100-0x004a99db` | `EventManInputDispatchMethods` | [UID:00004O] `EventMan`, emitted by [UID:0000J6]. |
| `0x004a99e0-0x004a9a32` | `EventManLockAndKeyStateAccessors` | [UID:00004O] `EventMan`, emitted by [UID:0000J6]. |
| `0x004a9a40-0x004a9f00` | `EventImeFactories` | [UID:0000J6] `Event.cpp` free helpers. |
| `0x004a9fa0-0x004aa1c0` | `EventPacketFactories` | [UID:0000J6] `Event.cpp` free helpers. |
| `0x004aa1c0-0x004aa1cf` | `EventDispatchExistingWrapper` | [UID:0000J6] `Event.cpp` free helper. |
| `0x004aa1d0-0x004aa1f4` | `EventManPostNotification` | [UID:00004O] or [UID:0000J6]; prefer EventMan method/helper child emitted by Event.cpp. |
| `0x004aa200-0x004aa46b` | `EventManTimerAndCursorDispatch` | [UID:00004O] `EventMan`, emitted by [UID:0000J6]. |
| `0x004aa470-0x004aa9af` | `EventRetainedMouseHelpers` | [UID:0000J6] retained Event.cpp helper band; no direct active route proven. |
| `0x004aa9b0-0x004aae62` | `EventRetainedImeHelpers` | [UID:0000J6] retained Event.cpp helper band; no direct active route proven. |
| `0x004aae70-0x004ab24b` | `EventRetainedKeyboardHelpers` | [UID:0000J6] retained Event.cpp helper band; no direct active route proven. |
| `0x004ab250-0x004ab3c3` | `EventRetainedPacketAndStateHelpers` | [UID:0000J6] retained Event.cpp helper band; no direct active route proven. |
| `0x004ab3d0-0x004ab3df` | `EventRetainedDispatchExistingWrapper` | [UID:0000J6] retained Event.cpp helper band. |
| `0x004ab3e0-0x004ab3eb` | `EventManSingletonClearHelper` | EventMan/EH support; no standalone source C++. |

If implementation does not perform the split immediately, target [UID:00014C] should remain a detailed parent/container page with the inventory table above and the explicit formal-C++ defer proof.

## First-Draft C++ Recommendation

### Aggregate Formal C++ Policy

Do not populate [UID:00014C]'s formal `RECONSTRUCTION_CPP` block with a large aggregate body. The target meets the minimum reconstructable/emitter/score gate, but the source scope is mixed:

- It contains multiple exact functions, not one function or one class method.
- It spans Event class predicate helpers, EventMan class methods, free IME/packet factories, a notification post helper, retained duplicate helpers with no direct xrefs, and an EH singleton-clear helper.
- Some child functions are source-authored and source-C++ ready, while `0x004ab3e0` is compiler/EH cleanup support and the no-xref retained band requires reachability caveats.
- A single C++ block would either emit unrelated source into one artificial function or hide the precise split/range evidence.

The target should keep the formal block blank during the implementation callback and add this target-specific no-code/defer proof. After split, child pages should emit C++ where their exact source scope is safe.

### Review-Only Child C++ Snippets

These snippets are source-style directions for future child pages, not a formal aggregate block for [UID:00014C].

```cpp
enum EventType {
    kEventCursorMove = 0,
    kEventLeftButtonDown = 1,
    kEventLeftButtonDoubleClick = 2,
    kEventLeftButtonUp = 3,
    kEventRightButtonDown = 4,
    kEventRightButtonDoubleClick = 5,
    kEventRightButtonUp = 6,
    kEventMouseWheel = 7,
    kEventKeyDown = 8,
    kEventKeyUp = 9,
    kEventTextInput = 10,
    kEventImeOpenStatus = 11,
    kEventImeCompositionStart = 12,
    kEventImeCompositionResult = 13,
    kEventImeCompositionEnd = 14,
    kEventImeCandidateList = 15,
    kEventImeCandidateClose = 16,
    kEventPacket = 18
};

bool Event::IsPointerEvent() const
{
    return m_type <= kEventMouseWheel;
}

bool Event::IsKeyOrTextEvent() const
{
    return m_type >= kEventKeyDown && m_type <= kEventTextInput;
}

bool Event::IsImeEvent() const
{
    return m_type >= kEventImeOpenStatus && m_type <= 17;
}

bool Event::IsPacketEvent() const
{
    return m_type == kEventPacket;
}
```

```cpp
unsigned char EventMan::TranslateEventKey(unsigned char key, unsigned char modifiers)
{
    UNREFERENCED_PARAMETER(modifiers);
    return key;
}

void EventMan::SetCapsLockState(bool enabled)
{
    m_capsLock = enabled;
}

void EventMan::SetNumLockState(bool enabled)
{
    m_numLock = enabled;
}
```

```cpp
void DispatchCandidateListEvent(int selectedRow,
                                CandidateStringList *visibleCandidates,
                                int tickCount)
{
    Event event;

    event.m_type = kEventImeCandidateList;
    event.m_imeCandidates = visibleCandidates;
    event.m_imeSelectedRow = selectedRow;
    event.m_tickCount = tickCount;

    g_pEventDispatcher->DispatchEvent(&event);
}
```

```cpp
void EventMan::PostNotification(unsigned int channel, LObject *payload)
{
    HWND hwnd = g_pApplication->GetWindowHandle();
    g_pfnPostMessageW(hwnd, 0x406, channel, reinterpret_cast<LPARAM>(payload));
}
```

The final child-page code should use the project's actual type names once the relevant class/type pages are updated. The snippets intentionally avoid decompiler temporaries and keep the mid-2000s source shape.

## Recommended Target Doc Changes

Update `source-3/project-documentation/by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`:

- Metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - keep `CANONICAL_OWNER:0000J6`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:0000J6`
  - keep formal `RECONSTRUCTION_CPP` blank and add the explicit split-first/no-code-defer proof in the narrative.
- Replace the stale "ctype/narrow helper" wording for `0x004a8b10` with `EventMan::TranslateEventKey(unsigned char key, unsigned char modifiers)` or `TranslateEventKeyByte`; note exact original name is not proven but CRT/locale naming is rejected.
- Replace "small event helper; exact semantic name open" rows for `0x004a8ac0-0x004a8b0b` with Event type-family classifier names and EventDispatcher evidence.
- Replace vague "late event-record helper band" wording with the retained duplicate helper inventory, including no-local-xref status and mirrored event types.
- Add the complete event type map `0..22` with caveats for unproduced/accepted types `17`, `19`, and `20..22`.
- Add the provisional Event record field names and type-specific union semantics, including candidate and packet payload fields.
- Add the direct xref/caller inventory for the active helper starts.
- Add `0x004aa1d0` `EventMan::PostNotification` / `PostApplicationNotification` evidence.
- Add `0x004a8f40` shutdown/packet-event-source helper evidence and reject Socket/Application ownership for the helper body.
- Add the 2026-06-19 change-log entry:
  - "B008 source-quality report: rechecked the exact `0x004a8ac0-0x004ab3eb` mixed Event.cpp island; resolved pre-EventMan helpers as Event type-family classifiers; rejected the stale `ctype/narrow` name for `0x004a8b10` in favor of EventMan key translation; mapped active EventMan, IME, packet, notification, timer, and retained duplicate helper families; recorded event type/payload semantics; kept owner/emitter [UID:0000J6]; recommended split-first child pages and formal aggregate C++ defer."

## Recommended Support Doc Changes

- [UID:0000J6] `source-3/project-documentation/by-file/Event.md`
  - Raise to `COMPLETION:88`, `CONFIDENCE:89`.
  - Add the full mixed island family table from this report.
  - Clarify `Event.cpp` owns Event object/factory bodies, EventMan source methods, free IME factories, packet payload factories, and retained duplicate helper bodies.
  - Preserve caveat that a separate historical `EventMan.cpp` is not proven; current route remains Event.cpp.
- [UID:00004O] `source-3/project-documentation/by-class/EventMan.md`
  - Raise to `COMPLETION:88`, `CONFIDENCE:90`.
  - Update method names for EventMan active methods and accessors.
  - Add `TranslateEventKey`, `ResetKeyboardState`, caps/num setters/getters, `ShutdownPacketEventSource`, timer wrappers, `PostNotification`, and retained duplicate caveats.
  - State that future exact children may attach to EventMan, but [UID:00014C] as a whole remains file-owned.
- [UID:00004L] `source-3/project-documentation/by-class/Event.md`
  - Raise to `COMPLETION:87`, `CONFIDENCE:90`.
  - Add Event classifier helper names and Event record field/union naming direction.
  - Keep base Event ctor/dtor/scalar dtor pages exact and separate.
- [UID:000141] `source-3/project-documentation/by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`
  - Add the classifier-helper name map and routed type families: pointer `0..7`, key/text `8..10`, IME `11..17`, packet `18`, special type `19`, system/control `20..22`.
  - No score change required unless the implementation expands field/slot names enough to justify one.
- [UID:0000J7] `source-3/project-documentation/by-file/EventDispatcher.md`
  - Cross-reference classifier helper names and confirm dispatcher consumes ready events rather than owning factory bodies.
- [UID:00004N] or current EventHandler class doc if present
  - Update virtual slot family names to match the type-family map: pointer/mouse, key/text, IME, packet, system/control, and special type `19`.
- [UID:0000K6] `source-3/project-documentation/by-file/InputMan.md`
  - Clarify InputMan calls the IME factory helpers but does not own their bodies.
  - Keep current score unless implementation uncovers additional source-quality changes.
- [UID:00018E] `source-3/project-documentation/by-memory/0x004e8af0-0x004e970d.InputMan.md`
  - Cross-note exact helper names/signatures from this report, especially `DispatchCompositionTextEvent` at `0x004a9ae0`.
- [UID:00018B] `source-3/project-documentation/by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`
  - Already supports type `15`; add backward link to this report's candidate payload field names if missing.
- [UID:0002PV] `source-3/project-documentation/by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md`
  - Keep its event type validation and link to the consolidated type map.
- [UID:00028L] `source-3/project-documentation/by-memory/0x0067a754-0x0067a758.g_pEventMan.md`
  - Add the `0x004ab3e0` singleton clear helper and `0x004aa1d0` notification post helper cross-reference.
- [UID:0003I8] `source-3/project-documentation/by-memory/0x006196b0-0x006196bc.EventManVtableData.md`
  - Confirm slot `0x006196b8 -> 0x004aa200` as `EventMan::OnTimerTick`.
- [UID:00027C] `source-3/project-documentation/by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md`
  - Add cross-note that `0x004a8b10` is not a CRT/ctype helper; it is an EventMan key translation adaptor.
- [UID:0003LU] and [UID:0003LV] scalar deleting destructor pages
  - No merge. Preserve them as exact split pages and cross-reference that [UID:00014C] ends before the Event scalar deleting destructor.
- `source-3/project-documentation/by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`
  - Cross-note `0x004a8f40` as EventMan/Event.cpp shutdown helper caller of Socket event-source services, not Socket-owned body.
- `source-3/project-documentation/by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md`
  - Add a cross-note that the event cleanup call is `EventMan::ShutdownPacketEventSource` / `CloseSocketEventStream`.
- Notification support docs that cite `0x004aa1d0`
  - Standardize the helper name to `EventMan::PostNotification` or `PostApplicationNotification`.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` during the report pass. Supervisor-owned replacement for the existing row at line containing `[UID:00014C]`:

```markdown
    - [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) 0x004a8ac0-0x004ab3eb | mixed source-module helper island | Event.cpp event producers and EventMan helper cluster : reconstructable : 88% : very strong : B008 2026-06-19 source-quality recheck resolves the stale EventMan class-aggregate row as a mixed Event.cpp island: pre-Event type classifiers, EventMan constructor/destructor/input/timer/state helpers, free IME and packet factories, notification-post helper, retained no-direct-xref duplicate helper band, and EH singleton-clear support. Keep owner/emitter [UID:0000J6], raise metadata to 88/90, replace raw/generated helper labels with inferred source-facing names, and split exact child pages before formal C++; aggregate C++ remains blank with a target-specific split/defer proof.
```

If the split plan is accepted later, coverage rows for new child pages should be inserted after UID assignment by validator. Do not guess new UIDs in this report.

## IDA Rename / Type / Comment Recommendations

High-confidence/descriptive rename recommendations:

- `0x004a8ac0`: `Event::IsPointerEvent`
- `0x004a8ad0`: `Event::IsKeyOrTextEvent`
- `0x004a8ae0`: `Event::IsImeEvent`
- `0x004a8af0`: `Event::IsPacketEvent`
- `0x004a8b00`: `Event::IsSystemOrControlEvent`
- `0x004a8b10`: `EventMan::TranslateEventKey` or `EventMan::TranslateEventKeyByte`
- `0x004a8b20`: `EventMan::ResetKeyboardState`
- `0x004a8b40`: `EventMan::EventMan`
- `0x004a8f20`: `EventMan::~EventMan`
- `0x004a8f40`: `EventMan::ShutdownPacketEventSource`
- `0x004a8f60`: `EventMan::StartCursorTimer`
- `0x004a8f70`: `EventMan::StopCursorTimer`
- `0x004a9090`: `EventMan::GetCursorPosition`
- `0x004a90b0`: `EventMan::GetModifierState`
- `0x004a90d0`: `EventMan::ClearKeyboardState`
- `0x004a9100`: `EventMan::ForwardCursorEvent`
- `0x004a9120`: `EventMan::DispatchLeftButtonDown`
- `0x004a9260`: `EventMan::DispatchLeftButtonUp`
- `0x004a9360`: `EventMan::DispatchRightButtonDown`
- `0x004a94a0`: `EventMan::DispatchRightButtonUp`
- `0x004a95a0`: `EventMan::DispatchMouseWheel`
- `0x004a96a0`: `EventMan::DispatchKeyDown`
- `0x004a97e0`: `EventMan::DispatchCharEvent`
- `0x004a98a0`: `EventMan::HandleKeyUp`
- `0x004a99e0`: `EventMan::SetCapsLockState`
- `0x004a99f0`: `EventMan::SetNumLockState`
- `0x004a9a00`: `EventMan::GetCapsLockState`
- `0x004a9a10`: `EventMan::GetNumLockState`
- `0x004a9a20`: `EventMan::GetRawKeyState`
- `0x004a9a40`: `DispatchImeOpenStatusEvent`
- `0x004a9ae0`: `DispatchCompositionTextEvent`
- `0x004a9c10`: `DispatchCompositionStartEvent`
- `0x004a9cb0`: `DispatchCompositionResultEvent`
- `0x004a9db0`: `DispatchCompositionEndEvent`
- `0x004a9e50`: `DispatchCandidateListEvent`
- `0x004a9f00`: `DispatchCandidateCloseEvent`
- `0x004a9fa0`: `DispatchRawPacketEvent`
- `0x004aa050`: `DispatchCopiedEventPayload`
- `0x004aa110`: `DispatchPacketEvent`
- `0x004aa1c0`: `DispatchExistingEvent`
- `0x004aa1d0`: `EventMan::PostNotification`
- `0x004aa200`: `EventMan::OnTimerTick`
- `0x004aa3b0`: `EventMan::DispatchCursorEvent`
- `0x004ab3e0`: `EventMan::ClearSingletonForUnwind`

For late helpers `0x004aa470-0x004ab3c3`, use `retained_` or `unused_` prefixes only in comments unless the project naming convention accepts such names. Add comments such as "retained duplicate Event.cpp helper; no direct code/data xref found in B008 local scan; mirrors active type N helper".

Recommended type/comment work:

- Add an inferred `EventType` enum with the type map above.
- Model `Event` payload as a type-specific union rather than one misleading flat struct.
- Model `EventMan` fields provisionally for key arrays and state:
  - key-state array around `this+0x120`
  - copied translation tables at `this+0x420` and `this+0x520`
  - key/translation/state arrays used around `this+0x620`, `this+0x820`, and `this+0x920`
  - caps/num flags at `this+0x921` and `this+0x922`
- Add comments to `0x004a8f40` explaining the Socket helper call and ApplicationShutdown route.
- Add comments to `0x004aa1d0` explaining message `0x406`, application window handle lookup, and broad notification caller fan-in.

## Open Questions And Resolutions

- Exact original helper names: not provable from binary alone. Descriptive source-facing names above are strong enough for documentation and IDA rename suggestions. Mark exact spelling as inferred.
- `Event.cpp` versus `EventMan.cpp`: current best route remains Event.cpp. A separate EventMan source file is possible but not evidenced enough to create a new owner or move emitter routing.
- Late helper reachability: no local direct code/data xrefs were found for most starts. Bodies are valid source-shaped event helpers, not padding or garbage. Treat as retained duplicate helper band and cap aggregate C++ until split/route is resolved.
- Type `17`, type `19`, and type `20..22` producer names: EventDispatcher routes them, but no producer in this target/local scan proves final names. Document accepted/routed family semantics and keep producer-specific names open.
- Event text buffer exact field offset/length: child pages should record exact stores/copies when split. The aggregate can document a type-specific `m_text`/`m_compositionText` buffer but should not claim final original layout spelling.

## Validation Commands Expected After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00014C-EventManAndEventFactoryHelpers-source-quality-removed.md](00014C-EventManAndEventFactoryHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation creates split child pages, each new child path must be validated with the same file-mode command after creation. `by-memory/-coverage-report.md` remains supervisor-owned and should not be edited by B008 unless the ban is explicitly lifted.

## Implementation Callback Checklist

When accepted by supervisor, lease the target and all support docs being edited. Then:

1. Update target [UID:00014C] metadata to `88/90`, owner/emitter unchanged.
2. Replace stale helper tables with the function inventory and direct xref inventory in this report.
3. Add the event type map and provisional Event union field names.
4. Add source placement and ranked ownership analysis: Event.cpp owner accepted, EventMan/InputMan/EventDispatcher/Socket consumers rejected as aggregate owners.
5. Add split recommendation exactly enough that future child-page work can create ranges without rediscovering boundaries.
6. Keep aggregate formal C++ blank and insert the exact split-first no-code/defer proof.
7. Update the support docs listed above with report-level detail, not compact summaries.
8. Preserve historical stale assumptions by marking them superseded rather than deleting:
   - old `0x004a8b40-0x004ab476` EventMan class aggregate wording
   - old `ctype/narrow helper` label
   - old vague "late event-record helper band" unresolved wording
9. Do not edit `by-memory/-coverage-report.md`; keep the exact replacement row in notes/report for supervisor.
10. Run scoped validators and record exact results.

## Final Recommendation

[UID:00014C] should remain a reconstructable Event.cpp-owned mixed container at `88/90`, not a direct EventMan class page. The report resolves the main source-quality blockers by naming the Event type classifiers, replacing raw/generated helper labels, mapping EventMan/free factory/helper families, assigning source placement, documenting retained duplicate helper reachability, and explaining why one aggregate C++ block is unsafe. The next implementation should update target/support docs in detail and then split exact children before adding formal C++ to source-authored child pages.

FINISHED report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00014C-EventManAndEventFactoryHelpers-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00014C-EventManAndEventFactoryHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00014C"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014C-EventManAndEventFactoryHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00014C-EventManAndEventFactoryHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
