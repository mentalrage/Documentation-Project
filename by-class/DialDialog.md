*** UID:00003R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00003R] DialDialog class support: exact method bodies are emitted by registered by-memory children.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SocketPacket;

class DialDialog : public DialogPane {
public:
    DialDialog(const wchar_t *phoneNumber);

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual char ParseModemResponse(SocketPacket *packet);

private:
    wchar_t m_phoneNumber[64];
    int m_modemResponseState;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialDialog

## Status

- Confidence: very strong for the completed class declaration, direct inheritance, exact `0x2f0` layout, constructor caller, three authored method routes, vtables/RTTI, literal use, callback ABI, state field, and compiler-only exclusions.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- Vtable data: [UID:0003DT][0x0062dd44-0x0062dddc.DialDialogVtableData](by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md)
- Parent attachment: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) has a valid `NexusTK/login/` path and already groups the phone-book/dial terminal flow; current class evidence is strong enough to attach.

## Score Rationale

- Completion `94`: the exact formal H declaration, direct `DialogPane` inheritance, `0x2f0` size, two fields, constructor, `OnControlCommand`, parser, child emission routes, vtable/RTTI source causes, and compiler-only destructor family are documented and synchronized.
- Confidence `95`: very strong binary and source-shape evidence supports `DialDialog` ownership, behavior, callback ABI, layout, formals, and generated route. Remaining uncertainty is limited to original identifier spelling and historical header/translation-unit boundaries, not class completeness.

## Class Purpose

`DialDialog` is the terminal dialing dialog. It displays the dial-in-progress UI over `g_pTerminalPane`, converts the selected phone-book number to multibyte text, sends modem cleanup/connect commands, and starts dialing with `ATX3DT`.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `DialDialog(const wchar_t *phoneNumber)` | [UID:0004YD][0x0058d750-0x0058d9e2.DialDialogConstructor](by-memory/0x0058d750-0x0058d9e2.DialDialogConstructor.md) | Builds `DLGDIAL.EPD`, opens over `TerminalPane`, stores the target number, converts it to multibyte text, and sends reset/connect/dial strings. |
| `OnControlCommand(int controlIndex, int notifyCode)` | [UID:0004YE][0x0058d9f0-0x0058da1e.DialDialogOnControlCommand](by-memory/0x0058d9f0-0x0058da1e.DialDialogOnControlCommand.md) | Primary +0x48 virtual; control 1 sends carriage return, slide-closes, and closes. `notifyCode` is ABI-real but unused. |
| `ParseModemResponse(SocketPacket *packet)` | [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) | Secondary vtable callback parsing `SocketPacket::m_data`/`m_length` for `CONNECT` and `BUSY` response tokens, closing through inherited dialog helpers. |
| terminal singleton clear helper | [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md) | Clears [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md); constructor unwind/cleanup glue, not a normal `DialDialog` method. |
| parser support tail | [UID:0004YG][0x0058db95-0x0058dbdf.DialDialogParserTailAndRetainedCloseWrappers](by-memory/0x0058db95-0x0058dbdf.DialDialogParserTailAndRetainedCloseWrappers.md) | Compiler switch table/alignment plus two retained no-route close-wrapper copies; non-emitting. |
| `DialDialog` destructor family | [UID:0001JJ][0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks.md), [UID:0004YH][0x0058dc20-0x0058dc5a.DialDialogScalarDeletingDestructor](by-memory/0x0058dc20-0x0058dc5a.DialDialogScalarDeletingDestructor.md) | Compiler adjustor thunks plus scalar deleting destructor. No explicit authored destructor body is emitted. |

## Source-Facing Class Shape

The parser callback child [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) resolves the modem-response parser declaration and state field for class-level documentation:

```cpp
char ParseModemResponse(SocketPacket *packet);
int m_modemResponseState; // full-object +0x2ec; adjusted parser callback reads +0x24c
```

The secondary callback ABI receives the `DialDialog+0xa0` subobject, and the vtable slot at `0x0062ddb4` points to `0x0058da20`. Source C++ still records this as a normal `DialDialog` method; the `this - 0xa0` adjustment belongs to the compiled secondary-base dispatch path, not to source-facing method code.

[UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) emits the exact parser body. Constructor [UID:0004YD][0x0058d750-0x0058d9e2.DialDialogConstructor](by-memory/0x0058d750-0x0058d9e2.DialDialogConstructor.md) and command-handler [UID:0004YE][0x0058d9f0-0x0058da1e.DialDialogOnControlCommand](by-memory/0x0058d9f0-0x0058da1e.DialDialogOnControlCommand.md) children emit the other authored methods, while the formal H above completes the class declaration; remaining caution is limited to inferred original spelling and historical file split.

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA reports exact local function bounds for `0x0058d750-0x0058d9e3`, `0x0058d9f0-0x0058da1f`, `0x0058da20-0x0058db95`, `0x0058dbe0-0x0058dbeb`, `0x0058dbeb-0x0058dc01`, and `0x0058dc20-0x0058dc5b`.
- The constructor has one direct code caller: `0x0058cc17` inside `PhoneBookDialog::DialSelectedEntry` (`0x0058cb60`).
- Constructor stores the primary, secondary, and tertiary `DialDialog` vtables at `0x0062dd44`, `0x0062dda4`, and `0x0062ddd4`.
- Vtable/data slots place `OnControlCommand` at `0x0062dd8c -> 0x0058d9f0`, the modem-response parser at `0x0062ddb4 -> 0x0058da20`, and the destructor adjustors at `0x0062dda4 -> 0x0058dbeb` / `0x0062ddd4 -> 0x0058dbf6`.
- Constructor data references include `DLGDIAL.EPD`, terminal singleton `g_pTerminalPane` at `0x0069bdf8`, `WideCharToMultiByte`, and the modem command strings `ATX3DT` plus carriage-return/newline terminators.
- `OnControlCommand` sends `\r` through the packet/modem sender, then calls the slide helper `0x0049eb90` and close helper `0x0049dad0`; historical `OnDialogAction` is superseded.
- `0x0058da20` walks incoming bytes up to length `0x64`, tracks parser state at callback-subobject offset `0x24c`, recognizes `CONNECT` and `BUSY`, and closes through the same slide/close helpers on recognized or oversized input.
- The local thunk island also contains `TerminalPane` thunks at `0x0058dc01-0x0058dc17`; keep those with [UID:0000EG][TerminalPane](by-class/TerminalPane.md), not this class.
- 2026-06-12 C001 IDA MCP `c001_nexustk` session opened `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with imagebase `0x00400000`, ready Hex-Rays, and ready string cache. `entity_query` reports `??_7DialDialog@@6B@` at `0x0062dd44`, `??_7DialDialog@@6B@_0` at `0x0062dda4`, `??_7DialDialog@@6B@_1` at `0x0062ddd4`, `aAtz` at `0x0062dddc`, and `??_7TextEditPane@@6B@` at `0x0062df94`.
- The same C001 pass traced the three vtable-head back-references to constructor writes at `0x0058d7a6`, `0x0058d7ae`, and `0x0058d7b8`, and traced the `0x0062dd8c`, `0x0062ddb4`, and `0x0062dd44` slots back to the method now resolved as `OnControlCommand` (`0x0058d9f0`), the modem parser (`0x0058da20`), and the scalar deleting destructor (`0x0058dc20`).
- C001 `analyze_component` for `0x0058d750`, `0x0058d9f0`, `0x0058da20`, and `0x0058dc20` corroborates constructor use of `ATX3DT`, action-handler use of `\r`, parser closure through `sub_49EB90`/`sub_49DAD0`, and destructor/thunk linkage. `trace_data_flow` also places the `ATX3DT` string reference at `0x0058d991` inside the constructor and the `ATZ` references in the terminal setup flow, outside the DialDialog vtable range.
- 2026-06-27 B001 current IDA MCP session `b001_000241_20260627` confirms parser function `0x0058da20` size `0x175`, parser slot `0x0062ddb4`, three vtable heads `0x0062dd44`/`0x0062dda4`/`0x0062ddd4`, and constructor writes at `0x0058d7a6`/`0x0058d7ae`/`0x0058d7b8`.
- The same B001 pass confirms the parser reads `SocketPacket` fields at `+0x0c` (`m_data`) and `+0x10` (`m_length`), reads/writes the adjusted parser state at `+0x24c`, and maps that state to the full-object field at `+0x2ec` because the secondary receiver is adjusted by `0xa0`.
- B001 resolved the parser close route through [UID:00003T][DialogPane](by-class/DialogPane.md) inherited helpers: `0x0049eb90` is source-facing `SlideCloseVertical()` and `0x0049dad0` is `CloseDialog()`. The target child now emits those calls by name instead of raw `sub_` labels.

## Applied IDA Class And Method State - 2026-07-29

- Supervisor Gate2B catalog entry 0364 declared and verified analysis UDT `DialDialog` at exact size `0x2f0`: `DialogPane base +0x000` size `0x26c`, `wchar_t m_phoneNumber[64] +0x26c` size `0x80`, and `int m_modemResponseState +0x2ec` size 4. Dependency `DialogPane` remains exact size `0x26c` with its prior seven members. The analysis UDT models storage with a base field; the formal H above remains the human-source inheritance declaration.
- `SocketPacket` is now present at exact size `0x14` with opaque 12-byte prefix, `char *m_data +0x0c`, and `int m_length +0x10`. This supports the existing source-facing parser declaration without adding packet implementation to this class.
- Current function identities/types are `DialDialog_DialDialog(DialDialog *, const wchar_t *)`, `DialDialog_OnControlCommand(DialDialog *, int, int)`, and adjusted-view `DialDialog_ParseModemResponse(EventHandler *, SocketPacket *)`, each with the exact report-approved function-repeatable behavioral comment. Their measured stack arguments are `phoneNumber +0x94` with retained `arg_4 +0x98`, `controlIndex +0x0c`/`notifyCode +0x10`, and `packet +0x14`; all nonargument frame entries, bytes, ranges, xrefs, and method bodies remain unchanged.
- Compiler support identities now read `DialDialog_ScalarDeletingDestructor_AdjustA0/A4` and `DialDialog_ScalarDeletingDestructor` with exact report-approved types/comments and measured `deletingFlags +0x04/+0x04/+0x0c`. They remain compiler-only and do not add methods to the formal H. The adjacent TerminalPane adjustors and all DialDialog vtable/RTTI compiler identities were verified protected and unchanged.
- Catalog entry 0364 application evidence is bound to saved checkpoint `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, saved `2026-07-29T14:42:53.5091352-04:00`; prestate `296ED21C...CF8B` and raw `sub_` identities are historical only. A bounded read-only no-drift check through MCP database `1da2b2ae` against current authoritative saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`, reconfirmed the exact class UDT, method, compiler-support, and protected RTTI state.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md)
- [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md)
- [UID:0001JJ][0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks.md)
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md)
- [UID:0003DT][0x0062dd44-0x0062dddc.DialDialogVtableData](by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md)

## B006 Complete Class Shape And Source Cause - 2026-07-29

- `DialDialog` derives directly from `DialogPane`. RTTI contains seven entries because inherited `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler` views are represented; this does not establish extra direct source bases.
- Complete object size is `0x2f0`. `DialogPane` occupies `[+0x000,+0x26c)`, `wchar_t m_phoneNumber[64]` occupies `+0x26c` through `+0x2eb`, and `int m_modemResponseState` is at `+0x2ec`.
- The source-bearing method children are constructor [UID:0004YD][0x0058d750-0x0058d9e2.DialDialogConstructor](by-memory/0x0058d750-0x0058d9e2.DialDialogConstructor.md), primary `OnControlCommand` [UID:0004YE][0x0058d9f0-0x0058da1e.DialDialogOnControlCommand](by-memory/0x0058d9f0-0x0058da1e.DialDialogOnControlCommand.md), and EventHandler-view parser [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md). The class formal H above declares all three in stable human-source form. No raw `sub_` label, explicit receiver adjustment, vtable array, RTTI array, parser switch table, adjustor, or scalar deleting wrapper belongs in handwritten C++.
- The primary vtable head is `0x0062dd44`, EventHandler view `0x0062dda4`, and TimerHandler view `0x0062ddd4`. The primary +0x48 slot `0x0062dd8c` routes to `OnControlCommand`; EventHandler-view slot `0x0062ddb4` routes to `ParseModemResponse`; deleting-adjustor heads route through [UID:0001JJ][0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks.md) to [UID:0004YH][0x0058dc20-0x0058dc5a.DialDialogScalarDeletingDestructor](by-memory/0x0058dc20-0x0058dc5a.DialDialogScalarDeletingDestructor.md). Exact compiler data belongs to [UID:0003DT][0x0062dd44-0x0062dddc.DialDialogVtableData](by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md).
- Constructor literals are covered by [UID:0003GX][0x0062df4c-0x0062df90.DialDialogResourceAndModemStrings](by-memory/0x0062df4c-0x0062df90.DialDialogResourceAndModemStrings.md), including exact `DLGDIAL.EPD`, recovered Korean UTF-16 status text, `ATX3DT`, LF/CR, and action CR routes. They remain inline method literals rather than standalone global definitions.
- Final source route is `NexusTK/login/PhoneBookDialog.h` for this declaration and `NexusTK/login/PhoneBookDialog.cpp` for its exact method children under [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md). A larger historical `TerminalPane.cpp` placement remains a lower-ranked source-tree hypothesis, not current routing.
- Historical `OnDialogAction` is superseded by `OnControlCommand(int,int)`: the primary +0x48 slot, `retn 8`, and inherited dialog callback pattern establish two explicit arguments. Original identifier spellings remain inferred but source-facing; final code must not revert to raw IDA labels.
- No explicit destructor declaration is emitted because no independent authored destructor body survives. An empty inline destructor is a lower-ranked historical possibility; the compiler-generated deleting family is fully explained by inherited virtual destruction.
- Score `94/95` reflects complete hierarchy, layout, child inventory, virtual identities, formals, source route, vtable/RTTI/literal source causes, and compiler exclusions. Completion does not exceed 95 because the original header split and identifier spelling cannot be directly proven.

## Changes

- 2026-07-29 B006 UID0001JG callback: raised `87/89 -> 94/95`, installed the exact class H and CPP child route, registered constructor/action/tail/scalar children, corrected historical `OnDialogAction`, documented direct inheritance and `0x2f0` layout, and synchronized vtable/literal/compiler source-cause evidence.
- 2026-07-29 post-Gate2B reconciliation: catalog entry 0364 applied the exact `SocketPacket`/`DialDialog` UDTs and seven accepted function identities/types/comments, verified protected compiler state, and measured typed stack arguments without changing the formal class declaration or emitter topology.

- 2026-06-27 B001 parser implementation callback: Raised `86/88 -> 87/89`, inserted the class-level formal support marker, updated the parser row to `ParseModemResponse(SocketPacket *packet)`, added `m_modemResponseState` full/adjusted offset evidence, documented the `DialDialog+0xa0` secondary callback ABI, and superseded the old parser callback/prototype/state-name blocker for [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md).
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: dialing dialog role, constructor/action behavior, modem response parser, terminal cleanup caveat, thunk/destructor boundaries, and PhoneBook/Terminal links are documented; remaining work is final callback ownership and source-quality method naming for the nearby parser.
- 2026-06-04: Raised from `72/80` to `84/86`, marked reconstructable, and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md).
  - Before: the class page had behavior notes but blank reconstructable/parent metadata, stale recovered-file provenance, no exact live function bounds, and no explicit vtable-slot evidence for the action handler or parser.
  - After: live IDA evidence records executable identity, exact function bounds, sole constructor caller, vtable stores/slots, dial command strings, parser state behavior, shared slide/close helpers, and TerminalPane thunk exclusions.
  - Historical reasoning: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) had a valid `NexusTK/login/` path and documented phone-book/dial ownership, while [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md) and [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) already had strong reconstructable evidence. The parser-specific blank-C++ blocker from this entry is superseded by the 2026-06-27 B001 parser implementation callback above.
- 2026-06-12 C001 Batch C001-006: Raised from `84/86` to `86/88`.
  - Before: the direct class parent was below the strict `85/85` gate, so [UID:0003DT][0x0062dd44-0x0062dddc.DialDialogVtableData](by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md) remained parentless despite strong vtable evidence.
  - After: session-based IDA MCP evidence confirms the exact DialDialog vtable labels, constructor writes, action/parser/destructor slot references, literal references, and successor boundary. The class now clears the routing gate for its exact vtable child.
  - Historical reasoning: the added evidence supported direct class ownership for the vtable data. The parser callback prototype and source-facing state-field blocker from this entry is superseded for [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) by the 2026-06-27 B001 parser implementation callback above.
