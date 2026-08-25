*** UID:0000OI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TerminalPane

## Status

- Confidence: very strong for `TerminalPane` and `TerminalSetupPane` ownership, direct class/source layout, singleton lifetime, method/compiler split, and the exact boundary from phone-book support.
- Proposed module: `login/TerminalPane.cpp`
- Source map: [UID:0000EG][TerminalPane](by-class/TerminalPane.md) emits the complete class declaration; [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) and [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) emit exact method bodies; the broad aggregate remains a nonduplicating map.
- Retained raw caveat: `0x0058b0f0-0x0058b12c` is real terminal configuration code, but current evidence proves no call/data/vtable/receiver route. Keep it as file-local raw evidence rather than declaring a TerminalPane member.
- Evidence basis: live IDA MCP boundary/caller checks and linked by-* memory/class docs.

## File Role

`TerminalPane.cpp` owns the pre-login terminal connection pane and its serial/modem setup dialog. It is launched from `MainMenuPane::ActivateMenuItem`, sends initial connection/setup packets, handles TimerHandler-driven disconnect/reconnect/leave decisions, and parses terminal-style byte streams from the connection layer.

This belongs under `login/` rather than generic UI because the pane is entered from the main menu before the normal game session and uses the same pre-login root pane/singleton lifecycle. It also has strong network coupling, but its ownership evidence is closer to login/startup UI than to the reusable packet or socket modules.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TerminalPane` | `0x0058af50-0x0058b5fb`, [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), [UID:0001JK][0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md), [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) | Complete class with direct `DialogPane` and `Singleton<TerminalPane>` bases, inline empty virtual destructor, `OnTimer`, parser, close, reconnect callback, and one parser-state dword. Exact children emit parser/callback bodies; compiler pages document but do not emit EH clear, adjustors, vtables, or scalar-delete lowering. |
| `TerminalSetupPane` | `0x0058b650-0x0058c350`, [UID:0003DP][0x0062daac-0x0062db48.TerminalSetupPaneVtableData](by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md) | `Terminal Setup` dialog for COM port and baud-rate settings, using `DLGSETUP.EPF`/`DLGSETUP.EPD`, persisted setup bytes, and the active terminal-pane parent. |
| [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) | `0x0069bdf8` | Active terminal pane singleton emitted in this source file as the single declaration `TerminalPane *g_pTerminalPane = 0;`. Exact storage child [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md) carries address/byte/xref proof and emits only a covered-by marker; phone-entry and dial dialogs are consumers, not lifetime owners. |
| [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) | `0x004f91c0-0x004f927d` | Retained main-menu terminal launcher; keep in `MainMenuPane.cpp`, not this terminal implementation file. |
| Socket/session helpers | callers only in this pass | Uses Socket-owned helpers for mode byte command `9`, serial connect, reset/close command `5`, queued modem strings, disconnect requests, and position update. Do not rename `0x00574b20` as a Terminal setup packet; Socket docs identify it as `Socket::PostResetConnectionCommand`. |

## UID0003GT Literal And Callback-Instantiation Placement

- Physical [UID:0003GT][0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData](by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md) is now a `92/94` ownerless, non-reconstructable, non-emitting index over four exact children. It must not emit a broad body into this file or into FunctionObjects.
- [UID:0004W3][0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral](by-memory/0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral.md) belongs to direct TerminalPane.cpp source use. Its bytes are `"ATZ\n\r\0"` plus two alignment zeroes; the constructor/configured-connect path references it at `0x0058b088`, and retained helper `0x0058b0f0-0x0058b12c` references it at `0x0058b11b`.
- [UID:0004W6][0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings](by-memory/0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings.md) belongs to `TerminalPane::ParseTerminalStream()`. It stores the four direct source expressions `"%I\n</RunRegistry="`, `"%c%c%c%c%c%c"`, `"dumb%c%c"`, and `"%c%c%c"`, each with one parser xref and exact terminator/alignment bytes.
- The literal children use formal covered-by markers and must not become duplicate static arrays. Pooled storage is compiler/linker layout resulting from ordinary source string expressions. The `%I` prefix is literal parser text rather than a printf conversion.
- `TerminalPane::OnTimer` owns the feature construction/binding of the 24-byte `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` object to `TerminalPane::OnReconnectOrLeave(unsigned long)`. It writes the concrete vptr at `0x0058b567`, member target beginning at object `+0x08`, zero secondary word at `+0x0c`, and adjusted TerminalPane pointer at `+0x10`.
- [UID:0004W2][PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_](by-class/PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_.md) records that exact concrete instantiation under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). Shared declarations remain on [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md); this file owns only the feature binding/use.
- [UID:0004W4][0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer](by-memory/0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer.md) and [UID:0004W5][0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData](by-memory/0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData.md) are compiler-generated from the shared declarations plus concrete instantiation and this feature binding. They are not handwritten TerminalPane globals and must not be emitted as raw pointers or dword arrays.
- Healthy MCP session `9b0396a3` revalidated exact range bytes, decorated callback identity, constructor/parser/timer consumers, literal/vtable xrefs, vtable slots, object layout, and the retained helper. No byte span or source-placement question remains unresolved inside UID0003GT.

### Generated Source Expectations

- `NexusTK/login/TerminalPane.cpp` should contain one TerminalPane declaration, one parser definition, one reconnect callback definition, and direct literal uses with no duplicate arrays and no UID0003GT Empty Emitter Marker.
- `NexusTK/util/FunctionObjects.cpp` should retain one shared FunctionObjects declaration union and concrete-instantiation/compiler-data markers for UID0004W2/UID0004W4/UID0004W5 without raw RTTI/vtable arrays.
- The retained `0x0058b0f0` configured-connect helper remains TerminalPane.cpp source-shaped evidence, but no modeled entry, inbound xref, pointer route, or receiver proof supports declaring it as a class member. Keep it out of generated member declarations unless stronger evidence appears.

## Evidence Notes

- IDA MCP confirms the TerminalPane constructor at `0x0058af50-0x0058b0ed`, [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), disconnect handler at `0x0058b470-0x0058b5df`, close handler at `0x0058b5e0-0x0058b5fb`, [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), TerminalSetupPane constructor/update/command block at `0x0058b650-0x0058c350`, and TerminalPane destructor/thunks in the later thunk island.
- 2026-06-12 A002 Batch 288 live IDA MCP recheck confirms [UID:0003DP][0x0062daac-0x0062db48.TerminalSetupPaneVtableData](by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md) is exact setup-pane vtable data owned by [UID:0000EH][TerminalSetupPane](by-class/TerminalSetupPane.md): the three constructor vptr stores are at `0x0058b690`, `0x0058b699`, and `0x0058b6a3`, and the next vtable boundary is `PhoneBookDialog` at `0x0062db48`.
- The same recheck confirms the setup constructor uses `DLGSETUP.PAL`/`DLGSETUP.EPF`, populates COM and baud controls, maps persisted modem setup fields at `dword_67A7C8 + 0x28de28/+0x28de2c`, loads `DLGSETUP.EPD`, and parents the modal through [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), reinforcing `TerminalSetupPane` as part of this terminal source module rather than the following phone-book file.
- IDA MCP callers on 2026-05-25 show the stream parser at `0x0058b130` calls [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), tying terminal byte-stream handling to the same queued position/status upload used by reconnect flow.
- B001-0003G7 confirms [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) is also one of the two direct source-use sites for [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md): the parser pushes `aBaram_0` at `0x0058b3fc`, formats it at `0x0058b40d`, sends five bytes through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) at `0x0058b424`, then calls [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md) at `0x0058b42f`. TerminalPane should emit that local packet text in final C++, but it is not the canonical owner of the pooled physical literal because [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) owns the other direct source-use site.
- 2026-07-04 B005 current-session support sync for [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) used MCP session `cbc24146`: the `0x0069bdf8` storage is zero-initialized, not a function, and has nine exact TerminalPane-family refs. Constructor `0x0058af50` publishes/clears it, setup/phone/dial paths read it as active terminal context or dialog parent, and EH/destructor helpers clear it. The source-facing name `g_pTerminalPane` is inferred/descriptive because the current IDB exposes `unk_69BDF8` / `dword_69BDF8`, but this file remains the correct source route for the singleton declaration.
- 2026-06-27 B009 current-session MCP implementation sync for [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) used active session `b001_000241_20260627` and accepted `TerminalPane::ParseTerminalStream(SocketPacket *packet)`. The receive wrapper fields are `packet->data` at `+0x0c` and `packet->length` at `+0x10`; parser state is `m_terminalParserState` at adjusted `+0x1cc` / full-object `+0x26c`; the success path calls Socket-owned `PostSocketModeByteCommand`, `Thread::WaitForQueueDrain`, inherited `DialogPane::OnDestroy()` / `DialogPane::OnHide()` through primary vtable `+0x38/+0x40`, `MainMenuPane(1)`, `SoundManager::PlaySample(0x191, 100)`, `QueueAndSendPacket("baram", 5)`, `SendPositionUpdate`, and the dialog close wrapper. The child page now carries the formal first-draft method body; no no-code marker applies.
- 2026-07-07 B005 current-session MCP implementation sync for [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) used session `43ccf853` and accepted `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`. Current facts are exact range `0x0058b620-0x0058b64f`, `0x0058b64f` alignment before `sub_58B650`, zero direct code xrefs, one data xref at `0x0058b56d`, callback type `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>`, and callees `TimerHandler::ScheduleTimer` / `Application::RequestExit`. The child page now carries formal first-draft method C++; this file remains the source root and does not duplicate the body.
- Fresh UID000247 RTTI/vtable analysis proves direct source bases `DialogPane` and `Singleton<TerminalPane>`, inherited EventHandler/TimerHandler facets, Singleton PMD `+0x26c`, EBO overlap with `m_terminalParserState`, and exact complete size `0x270`.
- The tertiary table's only non-destructor slot `0x0062daa4 -> 0x0058b470`, adjusted receiver, three stack arguments, `retn 0x0c`, and true return resolve that function as `TerminalPane::OnTimer(int,int,int)`. Historical `OnDisconnect` wording is superseded.
- UID000247 has no ordinary caller and implements only compiler deleting-destructor mechanics. UID0001JI and UID0001JK are likewise compiler EH/adjustor support. The source cause is the class declaration's direct bases and inline empty virtual destructor.
- 2026-05-26 IDA MCP recheck: `0x0058b130` has only the `0x0062da80` data/vtable reference, and `0x0058b620` is stored from the function now identified as `TerminalPane::OnTimer` at `0x0058b56d`.
- [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md) is constructor unwind glue that clears [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), not normal source logic.
- IDA MCP confirms [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) contains a `TerminalPane::TerminalPane` call at `0x004f924f`, but direct xrefs to the launcher itself are currently unresolved.
- Earlier summaries framed this as terminal-style text output; current IDA evidence shows a broader pre-login network terminal/reconnect role.

## Rule 26 Source Map

| Range | Source-facing role | Incorporation notes |
| --- | --- | --- |
| `0x0058af50-0x0058b0ee` | `TerminalPane::TerminalPane()` | Constructs the full-screen hidden/login terminal pane, writes [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), posts Socket mode command `9`, calls the session/reset helper, conditionally posts a serial connect from `g_pConfig+0x28de28/+0x28de2c`, queues `ATZ\n\r`, initializes the terminal parser state, writes startup-ready flag `g_pConfig+0x2916ca`, and arms the terminal callback/timer path when appropriate. |
| `0x0058b0f0-0x0058b12c` | retained configured-connect raw helper | Source-shaped no-route code. It checks terminal COM port values `1..4`, posts the serial connect helper at `0x00574b00`, then queues `ATZ\n\r` through [UID:0003B1][0x00574c40-0x00574ca1.QueueTransportStringCommand](by-memory/0x00574c40-0x00574ca1.QueueTransportStringCommand.md). Treat as file-local raw evidence, not padding/compiler glue and not a TerminalPane member without receiver/entry proof. |
| `0x0058b130-0x0058b44c` | `TerminalPane::ParseTerminalStream(SocketPacket *packet)` | Existing child [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) uses last-byte-style filename text; exported/IDA evidence gives exclusive end `0x0058b44c`. Packet fields are `SocketPacket` data `+0x0c` and length `+0x10`; adjusted parser-state access is `+0x1cc`, full object state is `m_terminalParserState` at `+0x26c`. B009 current-session review resolved the success path's adjusted slots as inherited `DialogPane::OnDestroy()` and `DialogPane::OnHide()` and inserted first-draft child C++. |
| `0x0058b470-0x0058b5e0` | `bool TerminalPane::OnTimer(int timerId, int arg0, int arg1)` | Tertiary TimerHandler virtual with adjusted receiver, `ret 0x0c`, and true return. Performs disconnect/session cleanup, builds the typed reconnect callback object for [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), and constructs the prompt using shared `Leave`/`Reconnect` literals. Historical `OnDisconnect` was a behavior description, not the virtual slot identity. |
| `0x0058b5e0-0x0058b5fc` | `TerminalPane::OnClose()` | Hides/disables the pane, clears `this+0x70`, and invalidates the rectangle at `this+0x44`. |
| `0x0058b620-0x0058b64f` | `void TerminalPane::OnReconnectOrLeave(unsigned long decision)` | Reconnect/leave alert callback child. Nonzero reconnect uses source-legal inherited `ScheduleTimer(0,0,0,0)`; the machine `+0xa4` receiver adjustment is TimerHandler base lowering, not a member field. Zero leave calls `g_pApplication->RequestExit()`. The exact child emits the formal body; this file-level map does not duplicate it. |
| `0x0058b650-0x0058c192` | `TerminalSetupPane::TerminalSetupPane()` with `ret 4` caveat | Retained/source-authored setup constructor with no direct route found in exported xrefs or local PE ref scans. Source-facing code may be no-arg, but docs should retain the unused/legacy stack-argument caveat until a caller is found. |
| `0x0058c1a0-0x0058c23f` | `TerminalSetupPane::UpdateControlState()` | Enables/disables COM and baud controls based on setup mode and selected COM state. |
| `0x0058c240-0x0058c350` | `TerminalSetupPane::OnCommand(int commandId, int commandParam)` | Apply writes terminal COM/baud config, refreshes active terminal pane through its virtual slot, calls Socket-owned reset command `0x00574b20`, saves placement, and closes; cancel saves placement and closes. Raw epilogue is `ret 8`, with the second argument unused in current evidence. |

First-draft C++ policy: exact by-memory method children should emit first. [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) should stay blank as a map until those children exist or are updated, because broad parent emission would duplicate child bodies and could overrun into [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md).

[UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) and [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) are the current examples of that child-first policy: they emit their own first-draft method bodies while this file-level page remains the source root and ownership map.

Class/compiler lifetime policy:

- [UID:0000EG][TerminalPane](by-class/TerminalPane.md) emits the complete class declaration and inline empty virtual destructor.
- Direct `Singleton<TerminalPane>` lifetime emits singleton publication/clear; source does not repeat those stores.
- Implicit reverse base destruction emits DialogPane teardown.
- UID000247, UID0001JI, UID0001JK, and UID0003DO are compiler/binary support and do not emit handwritten bodies.

## Split Notes

The adjacent phone-book and dial code is likely part of the same feature family. Current best migration split is:

```text
login/TerminalPane.cpp
login/PhoneBookDialog.cpp
```

If later symbol or linker-order evidence shows the original source was flatter, both files could collapse into a single `login/Terminal.cpp` or `login/TerminalPane.cpp`. Keep the split provisional until the phone-book helper ownership is cleaned up.

The terminal/setup executable boundary is exact: `TerminalSetupPane::OnCommand` ends at `0x0058c350`, and [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md) begins immediately at that successor. Do not merge the phone-book constructor into the terminal/setup aggregate unless later source-layout evidence deliberately collapses the whole login terminal/phone feature.

## Cross-References

- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0000EH][TerminalSetupPane](by-class/TerminalSetupPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md)
- [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md)
- [UID:0003GT][0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData](by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md)
- [UID:0004W2][PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_](by-class/PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_.md)
- [UID:0004W3][0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral](by-memory/0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral.md)
- [UID:0004W4][0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer](by-memory/0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer.md)
- [UID:0004W5][0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData](by-memory/0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData.md)
- [UID:0004W6][0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings](by-memory/0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings.md)
- [UID:0001JK][0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md)
- [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md)
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md)
- [UID:0003DP][0x0062daac-0x0062db48.TerminalSetupPaneVtableData](by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md)
- [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md)
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)

## Changes

- 2026-07-16 B001 accepted UID000247 callback:
  - Before: `87/85`, provisional phone split confidence, member raw-helper wording, `OnDisconnect`, embedded timer-handler wording, and incomplete source/compiler destructor route.
  - Changed to: `90/92`, preserving `NexusTK/login/` and the complete TerminalPane/TerminalSetupPane union while adding direct Singleton inheritance, EBO/size, inline destructor cause, OnTimer identity, inherited schedule call, and exact compiler-page exclusions.
  - Historicalized: member `PostConfiguredTerminalConnectIfSerial`, `m_timerHandler`, `OnDisconnect`, file-owned scalar wrapper, handwritten singleton clear/base/delete lowering, and older blank class-emitter state.
- 2026-06-06: Synced reconnect/leave callback range and removed stale generated-source wording.
  - Before: the page linked [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) with the short `0x0058b620-0x0058b64e` filename and described generated-source omissions as current state.
  - After: updated links to [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), described the stream parser/callback as exact by-memory children with provisional final names, and kept the score unchanged.
  - Evidence: live IDA MCP on 2026-06-06 confirms the callback's half-open `0x0058b620-0x0058b64f` range and callback-pointer store from `TerminalPane::OnDisconnect` at `0x0058b56d`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document captures pre-login terminal/setup role, proposed contents, singleton/global launcher notes, IDA boundary/caller evidence, stream parser/reconnect callback caveats, split notes, and cross-references; confidence remains capped by exact split from phone-book support.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TerminalPane.cpp` under `login`; IDA MCP confirms the pre-login terminal/setup block and `g_pTerminalPane` lifecycle.
- 2026-06-12 A002 Batch 288:
  - Before: `COMPLETION:86`, `CONFIDENCE:80`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:85`.
  - Evidence: live IDA MCP reconfirmed exact [UID:0000EH][TerminalSetupPane](by-class/TerminalSetupPane.md) vtable ownership, constructor vptr stores, setup resource/control creation, config writes, terminal-pane parent linkage, and the `PhoneBookDialog` successor boundary. The file split from phone-book support remains documented as provisional, so the score stays below final-audit levels.
- 2026-06-21 B006 Rule 26 support sync:
  - Added the retained `0x0058b0f0-0x0058b12c` configured-connect helper, exact method split map, parser-state full/adjusted offsets, terminal config field names, Socket-owned helper names, setup constructor `ret 4`/no-route caveat, `OnDisconnect` `ret 0x0c`, `OnCommand` `ret 8`, and child-first emission policy.
  - Score unchanged; this pass refined source placement and first-draft direction without changing the file-level ownership decision.
- 2026-06-27 B009 [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) implementation callback:
  - Added current-session parser evidence, accepted `SocketPacket` data/length fields, accepted `m_terminalParserState` offsets, source-facing Socket/SoundManager/DialogPane helper names, inherited `OnDestroy()` / `OnHide()` slot resolution, state-6 handoff details, and noted that the parser child now carries formal first-draft C++.
  - Score unchanged; this file page already owned the source root, and the parser-specific score/code change belongs to [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md).
- 2026-07-04 B005 UID000300 support sync:
  - Added that [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) emits the singleton declaration in `NexusTK/login/TerminalPane.cpp`, while [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md) carries exact storage proof and a covered-by marker.
  - Summary/evidence: MCP session `cbc24146` confirmed zero-initialized storage, nine constructor/read/clear refs, no owner transfer to phone/dial consumers, and raw IDB names `unk_69BDF8` / `dword_69BDF8` rather than source-proven `g_pTerminalPane`.
- 2026-07-07 B005 UID0001JD implementation callback:
  - Added current-session reconnect/leave callback evidence, corrected the source-facing callback signature to `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`, and noted that the child now emits formal first-draft C++.
  - Summary/evidence: MCP session `43ccf853` confirmed the exact function range, no direct code callers, data xref at `0x0058b56d`, typed void callback object, reconnect branch through `TimerHandler::ScheduleTimer`, and leave branch through `Application::RequestExit`.
- 2026-07-22 B001 UID0003GT source-quality callback:
  - Preserved `90/92`, the file ownership route, source map, and all existing formal/source content.
  - Added exact UID0003GT split placement, TerminalPane literal children UID0004W3/UID0004W6, concrete callback instantiation UID0004W2, compiler locator/vtable children UID0004W4/UID0004W5, no-duplicate source policy, generated expectations, and current healthy MCP support.
  - Preserved retained `0x0058b0f0` as file-local source-shaped evidence without promoting it to a class member or discarding it as compiler/padding data.
