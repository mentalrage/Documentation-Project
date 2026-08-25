*** UID:0000EG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SocketPacket;
class TerminalPane;

extern TerminalPane *g_pTerminalPane;

class TerminalPane : public DialogPane,
                     public Singleton<TerminalPane>
{
public:
    TerminalPane();

    virtual ~TerminalPane()
    {
    }

    virtual void OnClose();
    virtual char ParseTerminalStream(SocketPacket *packet);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void OnReconnectOrLeave(unsigned long decision);

private:
    int m_terminalParserState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TerminalPane

## Status

- Confidence: very strong for class role, direct bases, inherited facets, exact layout/size, login source placement, vtable/singleton anchors, parser/callback ownership, destructor source cause, and compiler/source boundary.
- Likely source file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md) / `NexusTK/login/TerminalPane.cpp`
- Primary address range: [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- Vtable data: [UID:0003DO][0x0062da10-0x0062daac.TerminalPaneVtableData](by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md); the primary RTTI locator word immediately before it is split as [UID:0003GS][0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer](by-memory/0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer.md).
- Rebuild handling: reconstructable complete class declaration attached to the TerminalPane file parent. This page now emits the authoritative direct-base/layout/destructor declaration, while exact by-memory method children continue to emit out-of-class method bodies.
- Direct source bases: `DialogPane` and `Singleton<TerminalPane>`.
- Inherited facets: `EventHandler` and `TimerHandler` arrive through `Pane`; neither is a direct base or data member of TerminalPane.
- Exact layout: `DialogPane` occupies `0x26c` bytes. Empty `Singleton<TerminalPane>` overlaps the first derived dword at `+0x26c`, which is `m_terminalParserState`; exact complete size is `0x270`.

## Class Purpose

`TerminalPane` is the pre-login terminal connection pane. It installs a full-screen hidden dialog over the root pane, cancels stale reconnect state, sends cash-shop/session connection packets, initializes modem/serial state, handles disconnect alerts, and owns the reconnect/leave callback flow.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `TerminalPane` | `0x0058af50-0x0058b0ee` | Constructs the full-screen terminal dialog, sets [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), posts Socket mode command `9`, calls the session/reset helper, conditionally posts serial connect from `g_pConfig+0x28de28/+0x28de2c`, queues `ATZ\n\r`, initializes `m_terminalParserState`, writes the startup-ready flag, and starts/re-arms the terminal callback path. |
| retained configured-connect raw helper | `0x0058b0f0-0x0058b12c` | Real terminal configuration code with no direct call, jump, vtable, pointer, VA/RVA, or receiver route. Keep as retained file-local raw evidence in the aggregate; do not declare it as a TerminalPane member solely from address locality. |
| `ParseTerminalStream(SocketPacket *packet)` | `0x0058b130-0x0058b44c`, [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) | Accepted terminal stream parser signature with first-draft child C++ present. `SocketPacket` fields are data pointer `+0x0c` and length `+0x10`; adjusted parser-state access is `+0x1cc` and full-object field is `m_terminalParserState` at `+0x26c`. Success path calls inherited `DialogPane::OnDestroy()` and `DialogPane::OnHide()` through TerminalPane primary vtable slots `+0x38/+0x40`, then `MainMenuPane(1)`, `PlaySample(0x191, 100)`, `QueueAndSendPacket("baram", 5)`, [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), and the close wrapper. |
| `OnTimer(int timerId, int arg0, int arg1)` | `0x0058b470-0x0058b5e0` | TimerHandler tertiary virtual reached only through vtable cell `0x0062daa4`. The adjusted receiver subtracts `0xa4`, the function consumes three stack arguments with `retn 0x0c`, performs disconnect/session cleanup and reconnect/leave prompt construction, and returns true. `OnDisconnect` is a superseded descriptive label, not the source virtual identity. |
| `OnClose()` | `0x0058b5e0-0x0058b5fc` | Hides/disables the pane, clears the open/visible byte at `this+0x70`, and invalidates the rectangle at `this+0x44`. |
| `OnReconnectOrLeave(unsigned long decision)` | `0x0058b620-0x0058b64f`, [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) | Source-facing void callback used by the reconnect/leave alert. Nonzero reconnect calls inherited `ScheduleTimer` directly; the machine adjustment to the `+0xa4` TimerHandler view is compiler lowering. Zero leave exits through the application path. |
| Destructor and compiler lifetime support | [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md), [UID:0001JK][0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md), [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) | The source declaration is an inline empty virtual destructor. Direct Singleton destruction causes the unconditional global clear; implicit DialogPane destruction causes base teardown. EH clear, adjustors, vptr writes, delete flags, and storage release are compiler-only. |

## Live IDA Evidence

- IDA MCP on 2026-06-04 used IDB `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Exact IDA function records for the TerminalPane half are constructor `0x0058af50-0x0058b0ee`, stream parser `0x0058b130-0x0058b44c`, disconnect handler `0x0058b470-0x0058b5e0`, close handler `0x0058b5e0-0x0058b5fc`, reconnect/leave callback `0x0058b620-0x0058b64f`, adjustor thunks `0x0058dc01-0x0058dc0c` and `0x0058dc0c-0x0058dc17`, and scalar deleting destructor `0x0058dc60-0x0058dca5`.
- TerminalSetupPane companion functions are `0x0058b650-0x0058c192`, `0x0058c1a0-0x0058c23f`, and `0x0058c240-0x0058c350`; the next major function starts at `0x0058c350`, matching the phone-book boundary.
- Constructor code callers are `0x004f5f9b`, `0x004f647a`, `0x004f7cbb`, and `0x004f924f`; the last call is inside [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) / `0x004f91c0-0x004f927d`, which itself has no direct callers.
- Vtable/data refs keep the virtual handlers with TerminalPane: `0x0062da10 -> 0x0058dc60`, `0x0062da54 -> 0x0058b5e0`, `0x0062da80 -> 0x0058b130`, and `0x0062daa4 -> 0x0058b470`; the constructor writes the vtable at `0x0058afb9`.
- The reconnect/leave callback has a single data xref from `0x0058b56d` inside the disconnect handler, matching callback-object construction for the reconnect/leave alert.
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) at `0x0069bdf8` has nine live refs in this family: constructor writes at `0x0058afa8`/`0x0058afaf`, TerminalSetupPane and phone/dial reads, singleton-clear helper `0x0058dbe0`, and destructor clear at `0x0058dc66`.
- 2026-07-04 B005 current-session MCP support sync for [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) used session `cbc24146` and reconfirmed the singleton lifecycle with zero-initialized storage at `0x0069bdf8`. The source-facing name `g_pTerminalPane` remains inferred/descriptive: current disassembly renders `unk_69BDF8`, raw queries accept `dword_69BDF8`, and `g_pTerminalPane` is not an IDB-proven global symbol. This does not change class ownership; constructor/destructor/setup refs still prove TerminalPane lifecycle ownership while phone/dial paths remain consumers.
- `SendPositionUpdate` at `0x00574d40` has a live call from the stream parser at `0x0058b42f`, confirming the parser is connection/reconnect logic rather than plain text output.
- Destructor xrefs include both adjustor thunks (`0x0058dc07`, `0x0058dc12`) and the TerminalPane vtable slot `0x0062da10`.
- 2026-06-27 B009 current-session MCP refresh for [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) used active session `b001_000241_20260627`: `lookup_funcs` reconfirmed `sub_58B130` size `0x31c`; `get_int` read TerminalPane primary vtable cells `0x0062da48 -> 0x0049e1c0`, `0x0062da50 -> 0x0049e210`, and `0x0062da80 -> 0x0058b130`; `lookup_funcs` identified `0x0049e1c0` as the inherited `DialogPane::OnDestroy()` slot and `0x0049e210` as the inherited `DialogPane::OnHide()` slot. This resolves the previous adjusted-slot blocker for the parser child body.
- 2026-07-07 B005 current-session MCP implementation sync for [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) used session `43ccf853`: `sub_58B620` is a `0x2f`-byte function at `0x0058b620-0x0058b64f`, `0x0058b64f` is alignment, `sub_58B650` begins at `0x0058b650`, there are zero direct code xrefs and one data xref at `0x0058b56d`, and the installer writes a `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` callback object. This corrects the class sketch to a `void` method and records the `+0xa4` embedded timer-handler facet used by the reconnect branch.

Checked again on 2026-06-12 by C001:

- `entity_query` over `0x0062da10-0x0062dab0` confirms [UID:0003DO][0x0062da10-0x0062daac.TerminalPaneVtableData](by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md) contains the three `TerminalPane` vtable heads at `0x0062da10`, `0x0062da70`, and `0x0062daa0`, with `TerminalSetupPane` starting at the successor boundary `0x0062daac`.
- `entity_query` over the RTTI area confirms `??_R4TerminalPane@@6B@` at `0x00650fe0`, with secondary/tertiary locator records at `0x00651094` and `0x006510a8`; `xrefs_to` ties those locator records to `0x0062da0c`, `0x0062da6c`, and `0x0062da9c`.
- `xrefs_to` confirms constructor `sub_58AF50` stores all three TerminalPane vtable heads at `0x0058afb9`, `0x0058afc1`, and `0x0058afcb`; the next `TerminalSetupPane` constructor store is at `0x0058b690`, proving the child boundary.
- Representative virtual slot target refs are stable: `0x0058dc60` from the primary first slot, `0x0058b5e0` from `0x0062da54`, `0x0058b130` from `0x0062da80`, `0x0058b470` from `0x0062daa4`, and adjustor thunks at `0x0058dc01`/`0x0058dc0c` from the secondary and tertiary tables.
- `analyze_function 0x0058af50` confirms constructor-side singleton publish to [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), three vtable installs at object offsets `+0x00`, `+0xa0`, and `+0xa4`, terminal startup/modem traffic including `ATZ\n\r`, and callers from the terminal startup/menu paths.
- `analyze_function 0x0058b470` confirms the disconnect handler builds the reconnect/leave callback object with target `sub_58B620` at `0x0058b56d` and uses the shared `Reconnect`/`Leave` labels, tying the callback child to this class.
- `analyze_function 0x0058dc60` confirms destructor-side singleton clear at `0x0058dc66`; `xrefs_to 0x0069bdf8` still reports the constructor write/clear, TerminalSetupPane and phone/dial reads, EH clear helper, and destructor clear.
- Fresh B001 UID000247 analysis resolves the complete hierarchy to eight RTTI entries: TerminalPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<TerminalPane>`. The direct source bases are exactly DialogPane and Singleton; the Singleton PMD displacement is `+0x26c`, nonvirtual `pdisp=-1`.
- The primary, secondary, and tertiary vtable heads contain 23, 11, and 2 slots. Their destructor entries route to UID000247 directly or through the `-0xa0`/`-0xa4` adjustors. The only non-destructor tertiary slot is `0x0062daa4 -> 0x0058b470`, establishing `OnTimer`.
- No separate ordinary TerminalPane destructor function exists. The exact scalar wrapper contains no derived handwritten cleanup beyond direct-base effects, so the inline empty virtual destructor is the narrowest behavior-identical source cause.

## Modem, Parser, And Reconnect Callback Data Split

- [UID:0003GT][0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData](by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md) is now a `92/94` non-emitting mixed index rather than a TerminalPane-owned aggregate. It partitions all 88 bytes into exact source-use and compiler-data children without changing the class declaration on this page.
- TerminalPane directly owns/emits [UID:0004W3][0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral](by-memory/0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral.md) and [UID:0004W6][0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings](by-memory/0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings.md). These pages preserve exact bytes, terminators, alignment, xrefs, and source behavior while using marker-only formals because the direct string expressions already belong to the constructor/configured-connect and `ParseTerminalStream()` source bodies.
- The modem child stores `"ATZ\n\r\0"` plus two alignment zeroes. Its direct consumers are the constructor/configured serial-connect path at `0x0058b088` and retained source-shaped helper use at `0x0058b11b`. No evidence supports a separately named static character array.
- The parser child stores `"%I\n</RunRegistry="`, `"%c%c%c%c%c%c"`, `"dumb%c%c"`, and `"%c%c%c"` with exact terminator/alignment tails and one parser xref each at `0x0058b1c7`, `0x0058b2f9`, `0x0058b332`, and `0x0058b355`. `%I` is a literal 17-byte escape-sequence prefix, not a printf conversion or typo.
- The reconnect prompt path in `OnTimer` constructs a 24-byte `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` and binds it to `OnReconnectOrLeave`. [UID:0004W2][PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_](by-class/PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_.md) records that concrete instantiation and routes through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); the reusable declaration remains on [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).
- Compiler-generated [UID:0004W4][0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer](by-memory/0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer.md) and [UID:0004W5][0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData](by-memory/0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData.md) belong to UID0004W2, not to handwritten TerminalPane data. TerminalPane owns the construction/binding site; FunctionObjects source and the compiler regenerate the locator/vtable.
- The vtable's five slots resolve to the shared scalar-deleting destructor, support virtual, no-op virtual, folded `Invoke(unsigned long)`, and object-size virtual. The sole installer is `0x0058b567`; the member target begins at object `+0x08`, the secondary member-function word at `+0x0c` is zero, and the adjusted TerminalPane pointer is stored at `+0x10`.
- Healthy MCP session `9b0396a3` revalidated the exact bytes, decorated type, construction stores, literal/vtable xrefs, parser/timer behavior, and retained helper. This current pass supersedes historical broad-owner/blank-emitter assumptions but preserves them in change history.
- Retained `0x0058b0f0-0x0058b12c` remains source-shaped TerminalPane.cpp configured-connect logic and a second ATZ consumer. There is still no modeled entry, inbound code/data/pointer xref, or receiver proof, so it is not promoted to a class member and is not discarded as padding or compiler glue.

### Source/Compiler Boundary

- Source-authored TerminalPane code: direct literal expressions, parser logic, timer prompt construction, callback binding, and `OnReconnectOrLeave` behavior.
- Shared FunctionObjects source: reusable member-callback template declarations and virtual implementations.
- Compiler output: pooled literal layout, complete-object-locator pointer, concrete vtable bytes, vptr constant, thunks, RTTI records, and other ABI tables. Do not reproduce these as raw arrays or address-shaped C++.
- Generated-source expectation: `TerminalPane.cpp` keeps one class declaration, one parser definition, one reconnect callback definition, and direct literal expressions with no duplicate arrays or UID0003GT empty-emitter marker. FunctionObjects output records the shared declaration and concrete instantiation markers without raw dword tables.

## Source-Facing Shape

The managed reconstruction block at the top of this page is authoritative. It declares the exact direct bases, inline empty virtual destructor, `OnClose`, parser, TimerHandler `OnTimer` override, reconnect callback, and one derived parser-state dword.

Source/compiler boundary:

- `Singleton<TerminalPane>` construction/destruction accounts for publish/clear of `g_pTerminalPane`; no manual constructor publish or destructor clear belongs in TerminalPane source.
- Reverse base destruction accounts for DialogPane teardown; no explicit base-destructor call belongs in source.
- The virtual destructor declaration regenerates the primary scalar wrapper, two adjusted entries, and destructor vtable slots.
- `EventHandler` and `TimerHandler` are inherited through Pane. The `+0xa0` and `+0xa4` views are subobjects, not TerminalPane data members.
- The exact parser and reconnect child pages carry their method definitions. UID000247, UID0001JI, UID0001JK, and UID0003DO carry compiler/binary proof and must not emit handwritten bodies.
- Retained raw `0x0058b0f0` remains source-shaped evidence without a proven member receiver or entry route.

Rejected historical shapes:

- Pane-only direct inheritance;
- direct EventHandler or TimerHandler bases;
- `TimerHandler m_timerHandler`;
- `OnDisconnect` for `0x0058b470`;
- member `PostConfiguredTerminalConnectIfSerial` without a receiver route;
- handwritten singleton clear, guarded clear, explicit DialogPane destructor call, delete flags, vptr writes, adjustors, or operator delete.

Socket-owned helpers remain Socket-owned: `Socket::PostResetConnectionCommand`, serial connect, queued modem strings, `SetSocketConnectionFlag`, `PostSocketModeByteCommand`, `SendSingleByteCommand`, `QueueAndSendPacket`, and `SendPositionUpdate`.

## Cross-References

- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EH][TerminalSetupPane](by-class/TerminalSetupPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md)
- [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md)
- [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md)
- [UID:0003GT][0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData](by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md)
- [UID:0004W2][PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_](by-class/PlainMemberFunctionObject_void____thiscall_TerminalPane_____unsigned_long____class_TerminalPane_.md)
- [UID:0004W3][0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral](by-memory/0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral.md)
- [UID:0004W4][0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer](by-memory/0x0062dde4-0x0062dde8.TerminalPaneReconnectCallbackRttiLocatorPointer.md)
- [UID:0004W5][0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData](by-memory/0x0062dde8-0x0062ddfc.TerminalPaneReconnectCallbackVtableData.md)
- [UID:0004W6][0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings](by-memory/0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings.md)
- [UID:0001JK][0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md)
- [UID:0003DO][0x0062da10-0x0062daac.TerminalPaneVtableData](by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md)
- [UID:0003GS][0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer](by-memory/0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer.md)
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)

## Changes

- 2026-07-16 B001 accepted UID000247 callback:
  - Before: `87/88`, blank formal class C++, Pane-only body sketch, fictitious `m_timerHandler`, `OnDisconnect` labeling, member treatment of raw `0x0058b0f0`, and no complete destructor/source-layout closure.
  - Changed to: `92/94` with the complete managed declaration, direct `DialogPane` plus `Singleton<TerminalPane>` inheritance, inline empty virtual destructor, inherited TimerHandler `OnTimer`, source-legal reconnect declaration, one parser-state dword, and `[[CHILDREN]]`.
  - Exact layout/source cause: DialogPane size `0x26c`; direct empty Singleton PMD `+0x26c`; parser state overlaps through EBO; complete size `0x270`; Singleton and implicit base destruction regenerate global clear and DialogPane teardown.
  - Historicalized: Pane-only inheritance, direct/embedded TimerHandler, OnDisconnect, member raw helper, handwritten clear/base/delete lowering, and the old blank class-emitter conclusion.
- 2026-06-06:
  - Before: the reconnect/leave callback row had the correct half-open address text but linked to the short `0x0058b620-0x0058b64e` filename.
  - After: updated the [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) link to [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md).
  - Why: live IDA MCP confirms the callback is a `0x2f`-byte function ending at exclusive `0x0058b64f`.

- 2026-06-04:
  - Before: scored `84/76`, reconstructability and parent attachment were blank, and the page still had stale source-reference wording.
  - After: scored `86/84`, marked reconstructable, attached to [UID:0000OI][TerminalPane](by-file/TerminalPane.md), and replaced the evidence with live IDA boundary, vtable, caller, callback, singleton, and parser-call checks.
  - Why: current IDA evidence proves TerminalPane class ownership, login source placement, virtual handler anchors, singleton lifecycle, reconnect callback ownership, and parser behavior. Confidence remains below 90 because final helper names and the phone/dial split still need source-quality cleanup.

- 2026-06-12 C001 Batch C001-005:
  - Before: `86/84`, which blocked strict-gate assignment of the direct TerminalPane vtable-data child.
  - After: `87/88`, with [UID:0003DO][0x0062da10-0x0062daac.TerminalPaneVtableData](by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md) documented as the exact vtable-head child.
  - Why: live IDA recheck confirmed the vtable heads, RTTI locator records, constructor vtable stores, successor `TerminalSetupPane` boundary, representative virtual slot targets, constructor singleton/startup behavior, reconnect/leave callback construction, and destructor singleton clear. The class-level C++ block remains blank because exact by-memory method children are the emission surface.
- 2026-06-21 B006 Rule 26 support sync:
  - Added the retained `0x0058b0f0` configured-connect helper, corrected parser-state offset interpretation, documented Socket-owned helper names, recorded the `OnDisconnect` three-argument ABI caveat and callback object type, and added a source-facing class-shape sketch for child emission.
  - Score unchanged because ownership and class identity were already strong; the new facts refine method-level reconstruction readiness.
- 2026-06-27 B009 [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) implementation callback:
  - Promoted `ParseTerminalStream(SocketPacket *packet)` and `m_terminalParserState` wording from provisional direction to accepted class-shape guidance, added current-session slot proof for inherited `DialogPane::OnDestroy()` / `DialogPane::OnHide()` at primary vtable `+0x38/+0x40`, and recorded that the parser child now emits first-draft method C++.
  - Score unchanged; this class page remains a source-shape/support page while method C++ belongs on the exact by-memory child.
- 2026-07-04 B005 UID000300 support sync:
  - Added the current-session raw-name caveat for `g_pTerminalPane`: it is the project/source-facing singleton name, while the current IDB exposes `unk_69BDF8` / `dword_69BDF8`.
  - Score unchanged; this class page already contained same-or-greater TerminalPane lifecycle evidence, and no class-static C++ or class-level formal block change is required.
- 2026-07-07 B005 UID0001JD implementation callback:
  - Before: the class method inventory and sketch used the older `int OnReconnectOrLeave(unsigned long decision)` wording and did not state that the child now emits formal first-draft C++.
  - After: corrected the source-facing callback signature to `void`, recorded the `+0xa4` embedded timer-handler facet, added current-session callback-object evidence, and noted that [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) now carries its method body.
  - Why: MCP session `43ccf853` confirms the typed `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` installer and the exact reconnect/leave branch behavior.

- 2026-07-22 B001 UID0003GT source-quality callback:
  - Preserved class score `92/94`, ownership/emitter route, and complete formal declaration.
  - Added real literal children UID0004W3/UID0004W6, concrete callback instantiation UID0004W2, compiler locator/vtable children UID0004W4/UID0004W5, exact source-use/no-array handling, callback layout/slot/install facts, and healthy current MCP evidence.
  - Kept retained helper `0x0058b0f0` as source-shaped non-member evidence and separated TerminalPane binding/use from shared FunctionObjects declaration and compiler-generated ABI data.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `76`.
- Evidence: the page documents terminal connection responsibility, constructor/disconnect/close/parser/callback/destructor ranges, singleton, helper coverage gaps, parser call evidence, and reconnect/leave flow; confidence remains capped by unmodeled helper ownership and broad terminal/dial thunk island interactions.
