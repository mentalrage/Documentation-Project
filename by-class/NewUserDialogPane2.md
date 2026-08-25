*** UID:00009E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;
class NewUserDialogPane2;
extern NewUserDialogPane2 *g_pNewUserDialogPane2;

class NewUserDialogPane2 : public DialogPane,
                           public Singleton<NewUserDialogPane2>
{
public:
    NewUserDialogPane2();
    virtual ~NewUserDialogPane2() {}

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void ShiftShapesLeft();
    void ShiftShapesRight();
    void SelectNation(int nation);
    void SelectTotem(short totem);
    void SelectShapeSlot(int slot);
    void SelectMaleMode();
    void SelectFemaleMode();
    void OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration);
    void OnNexonclubRegistrationResult(
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &accountName);

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    int m_selectedNation;
    int m_selectedTotem;
    int m_selectedShapeSlot;
    bool m_waitingForCharacterReply;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        m_nexonclubAccountName;
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewUserDialogPane2

## Status

- Confidence: very strong for behavior, file ownership, direct launcher and callback reachability, inherited child lookup, exact own layout, singleton/vtable evidence, declaration-level C++, and exact shift children; remaining uncertainty is limited to stripped lexical/access spellings and unrelated helpers.
- Likely source file: [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella
- Main address range: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), inside aggregate [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- Current recovered file: `source-3/simroot_v2/class_NewUserDialogPane2.cpp`

## Class Purpose

`NewUserDialogPane2` is an alternate create-user dialog variant for a fixed 640x480 layout. It uses `DLGNEW02.EPD` and `NPAL3.PAL`, displays multiple shape previews, and provides gender, totem, body-shape, direction, and submit controls.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserDialogPane2` | `0x0052a540-0x0052b047` | Constructor; direct `Singleton<NewUserDialogPane2>` base lowering publishes `g_pNewUserDialogPane2`, then the source-authored body initializes selector/string state, loads `DLGNEW02.EPD`, `DIREC.EPD`, `NNATION.EPD`, `NPAL3.PAL`, and applies randomized initial selectors. |
| complete destructor body evidence | `0x0052b050-0x0052b08a` | IDA-unmodeled lifecycle body with no direct route; documented as non-emitting raw evidence rather than handwritten destructor source. |
| `ShiftShapesLeft` / `ShiftShapesRight` | `0x0052b090-0x0052b30d` | Exact callback/key/command helpers: controls `8-11` select among four visible slots; non-edge paths deselect/move/select, while edge paths gate on controls `6/7`, step the four shape indexes in direction-specific order, and update the opposite/current navigation button from a signed-short terminal sentinel. Command ids `6/7` call inherited `SetHoverControl(8)` after shifting; the key/text path adds no post-shift call. |
| `SelectNation`, `SelectTotem`, `SelectShapeSlot` | `0x0052b310`, `0x0052b3a0`, `0x0052b470` | Updates `m_selectedNation`, `m_selectedTotem`, and `m_selectedShapeSlot`. Exact `SelectTotem(short)` retrieves PrettyButton children `14-17`, clears the old indexed control, selects the caller-supplied `0..3` control, stores `m_selectedTotem`, and updates TextEdit child `19` from STR.RES id `212 + totem` without an internal clamp. Nation serializes as `m_selectedNation + 1`; totem serializes directly; shape-slot selects controls `8-11` for later shape-byte extraction. |
| `SelectMaleMode` / `SelectFemaleMode` | `0x0052b530`, `0x0052b5c0` | Exact 136-byte selector pair: inherited typed lookup obtains PrettyButton children `4/5` and UserShape children `8-11`; male selects/clears buttons `4/5` then applies `SetMaleShapeBank` four times, female reverses button state and applies `SetFemaleShapeBank`; neither method reselects `m_selectedShapeSlot`. |
| `OpenNexonclubRegistrationOrSendCharacterRequest` / `OnNexonclubRegistrationResult` | `0x0052b650`, `0x0052b730` | Boolean registration gate and const-string callback: false sends immediately; true opens `NexonclubRegistrationDialog` with STR.RES id `227`; successful nonempty account text updates `m_nexonclubAccountName`, and the callback always sends. |
| `OnControlCommand` | `0x0052b760-0x0052b88c` | Primary-slot `+0x48` void two-argument control dispatcher with unused `notifyCode`, explicit ids `4-17/20/21`, command-only `SetHoverControl(8)` after shifts, no inherited default call, and the `0x0052b844-0x0052b88c` switch jump table. |
| `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `HandlePacketEvent` | `0x0052b940`, `0x0052b890`, `0x0052b910` | EventHandler secondary slots `+0x04`, `+0x08`, and `+0x10`: exact pointer/mouse base forwarder, key/text translation-and-shift override, and opcode-`0x02` Event packet bridge. Secondary `+0x0c` remains inherited `HandleImeEvent`. |
| raw selector-clear helpers | `0x0052b950-0x0052b981`, `0x0052b990-0x0052b9ed` | Real IDA-unmodeled no-route code bodies clearing controls `12/13` and `14-17`; documented as non-emitting raw helper evidence. |
| `SubmitCreateUser` | `0x0052b9f0-0x0052bbbc` | Reads edit controls, validates digit-in-password and confirmation match, creates the dimmer, and calls the file-local account packet helper. |
| `SendCreateCharacterRequest` / `HandleCreateUserReply` | `0x0052bdd0-0x0052c325` | Builds opcode `0x04` character payload from selected shape bytes and handles two-phase `packet[1]` status plus `packet+2`/`packet+3` message data. |
| file-local `SendCreateAccountRequest` | `0x0052bbc0-0x0052bdc5` | `NewUserDialogPane2.cpp` helper, not a class method; emits through [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md). |
| Destructor family | `0x0052f767`, `0x0052f772`, `0x0052f8e0` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) records exact IDA function starts for the constructor-like body, selector/update helpers, command/event handlers, submit validation path, packet encoder, create-character payload builder, and response handler.
- Current control/EventHandler children are [UID:00043V][0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand](by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand.md), [UID:00043W][0x0052b890-0x0052b910.NewUserDialogPane2HandleKeyOrTextEvent](by-memory/0x0052b890-0x0052b910.NewUserDialogPane2HandleKeyOrTextEvent.md), [UID:00043X][0x0052b910-0x0052b936.NewUserDialogPane2HandlePacketEvent](by-memory/0x0052b910-0x0052b936.NewUserDialogPane2HandlePacketEvent.md), and [UID:00043Y][0x0052b940-0x0052b949.NewUserDialogPane2HandlePointerOrMouseEvent](by-memory/0x0052b940-0x0052b949.NewUserDialogPane2HandlePointerOrMouseEvent.md). Their exact slot/ABI contracts replace the older OnCommand/KeyEvent/direct-packet/notification abstractions.
- The constructor is reached from the main-menu create-user paths at `0x004f7ad0` and [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) at `0x004f9041`.
- Vtable, RTTI, and singleton evidence are paired: `0x0061fd04` is referenced by constructor/destructor vtable stores; RTTI at `0x0064c734-0x0064c7cc` identifies direct `Singleton<NewUserDialogPane2>` inheritance with PMD `620/-1/0`; singleton slot `0x0069b4a4` is published/cleared by direct-base and destructor lowering. The exact vtable child is [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md).
- Submit-path decompilation evidence in the child memory page shows the three edit-field reads, digit-in-password requirement, confirmation comparison, alert fallback, packet encoding through string conversion/length-prefix helpers, send through `dword_67A7EC`, and server-reply alert/reset handling.
- 2026-06-14 C001 live IDA MCP refresh on database `a001_goal2_class_batch` reconfirmed the child function map: constructor-like `sub_52A540` size `0xb07`, command dispatcher `sub_52B760` size `0xe2`, submit validator `sub_52B9F0` size `0x1cc`, packet encoder `sub_52BBC0` size `0x205`, create-character payload builder `sub_52BDD0` size `0x1f2`, and reply handler `sub_52BFD0` size `0x355`.
- The same refresh reconfirmed constructor callers at `0x004f7ad0` and `0x004f9041`, vtable refs to `0x0061fd04` at `0x0052a5b2`, `0x0052b059`, and `0x0052f8ec`, singleton refs to `0x0069b4a4` at `0x004f6a22`, `0x0052a597`, `0x0052a59e`, `0x0052b07a`, `0x0052f730`, and `0x0052f90d`, and the internal packet path `0x0052b760 -> 0x0052b9f0 -> 0x0052bbc0` plus reply-side call `0x0052bfd0 -> 0x0052bdd0`.
- Wave3's method name for `0x0052a540` should be corrected from destructor-like text to constructor.
- A001 2026-06-16 live IDA/PE refresh reconfirmed the constructor-like body at `0x0052a540`, command dispatcher `0x0052b760`, submit validator `0x0052b9f0`, packet encoder `0x0052bbc0`, create-character payload builder `0x0052bdd0`, reply handler `0x0052bfd0`, and successor boundary at `0x0052c360`. Section-mapped PE scanning found exactly two direct constructor branches to `0x0052a540` from `0x004f7ad0` and `0x004f9041`, plus no constructor pointer encodings. `analyze_function` on the submit/packet path confirms three edit-field reads, password digit/confirmation validation, length-prefixed packet encoding, and queue-send dependencies. [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) now routes through this direct class after live vtable refs and PE pointer stores were rechecked.
- B014 2026-07-04 UID0002SH support sync: MCP session `aa3930bd` reconfirmed [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) as nonfunction compiler-generated vtable data with decorated table bases at `0x0061fd04`, `0x0061fd64`, and `0x0061fd94`, constructor/complete-destructor/scalar-deleting-destructor stores only, zero RVA-pattern hits, no local UDT/type records, and the `0x0061fda0` successor owned by `NewCreateUserDialogPane`. The class declaration and exact virtual-method children are the source representation that regenerates UID0002SH; the vtable page is non-reconstructable/non-emitting and should not carry an empty emitter marker or hand-authored vtable array.
- Reconstructable attachment: this class attaches to [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md). The class H block carries the declaration and inline empty destructor without an H-channel `[[CHILDREN]]` token; [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) is a non-emitting split/index, and exact child pages under it carry method-body C++ or no-code proofs.
- Current source-channel correction: the complete class declaration, matching `extern NewUserDialogPane2 *g_pNewUserDialogPane2`, and direct Singleton base live in `RECONSTRUCTION_H CODE` at source position `10`. The class CPP block is blank because method definitions are exact children and the global definition is UID0002X3 at position `0`.

## Direct Singleton Base And Empty-Base Layout

- Live RTTI names the class descriptor `??_R0?AVNewUserDialogPane2@@@8`, Singleton descriptor `??_R0?AV?$Singleton@VNewUserDialogPane2@@@@@8`, and base descriptor `??_R1CGM@?0A@EA@?$Singleton@VNewUserDialogPane2@@@@8`.
- The Singleton base descriptor at `0x0064c798` records PMD `620/-1/0`, placing a non-virtual empty base at `+0x26c`. Constructor instructions at `0x0052a581-0x0052a59e` form that subobject and subtract `0x26c` before publishing complete `this`.
- Current IDA UDT size is exactly `0x280`: `DialogPane` base size `0x26c`; `m_selectedNation` at `+0x26c`; `m_selectedTotem` `+0x270`; `m_selectedShapeSlot` `+0x274`; `m_waitingForCharacterReply` `+0x278`; natural alignment through `+0x27c`; and `m_nexonclubAccountName` `+0x27c`.
- The direct Singleton base and `m_selectedNation` share `+0x26c` through old-MSVC empty-base optimization. Human H source therefore declares the base and ordinary fields without a synthetic Singleton member or authored padding array.
- The exact external storage is loader-zeroed [UID:0002X4][0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2](by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md), while semantic [UID:0002X3][g_pNewUserDialogPane2](by-global/g_pNewUserDialogPane2.md) supplies the sole definition.

## Header And Generated One-Definition Contract

- H emits one forward declaration, one extern declaration, and the complete class with direct bases and an inline empty destructor. Exact method children remain CPP routes rather than an H placeholder.
- CPP emits no duplicate class declaration from this page. UID0002X3 emits the sole global definition at position `0`; constructor UID00043K emits at position `20` without a handwritten global assignment.
- Expected generated output is one `NewUserDialogPane2.h` class/extern source, one CPP global definition and child method sequence, no UID0002X3/UID0002X4 empty markers, and an allowed UID00009E CPP empty marker because this class page is H-only.

## Superseded Singleton Assumptions

- The historical declaration omitted `Singleton<NewUserDialogPane2>` and placed all class source in CPP. RTTI/PMD and current source-channel rules supersede both omissions.
- Historical prose treated `g_pNewUserDialogPane2 = this` as handwritten constructor source. Exact base-adjustment lowering proves publication belongs to the direct Singleton base constructor.
- Historical `0xffffffff` and `dword_69B4A4` remain analysis history only; PE virtual-tail proof and the live IDB establish loader zero and current `unk_69B4A4` prestate.
- Fresh UID00043N/UID00043M analysis resolves `+0x1fc` as inherited [UID:00003T][DialogPane](by-class/DialogPane.md) `List`/typed-child lookup state. The historical `ChildControlCollection *m_childControls` declaration on this derived class was duplicate storage that would shift all own fields and is removed. NewUserDialogPane2 own state begins at `+0x26c`: `m_selectedNation`, `m_selectedTotem`, `m_selectedShapeSlot`, `m_waitingForCharacterReply`, implicit alignment, and `m_nexonclubAccountName` at `+0x27c`.
- The class closes without an H-channel `[[CHILDREN]]` token. Exact qualified child definitions remain routed through their CPP owners after the complete declaration; no method body moves into H.
- [UID:00043N][0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight](by-memory/0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight.md) has two code callers plus a constructor member-callback data xref; [UID:00043M][0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft](by-memory/0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft.md) is the reciprocal callback. Both use inherited `GetChild<T>`, `m_selectedShapeSlot +0x274`, `UserShapeSelectControlPane::SetSelected`, signed-short shape steppers, and `ControlPane::IsEnabled`/Enable/Disable without handwritten vtable dispatch or security-cookie source.

## Exact Control And EventHandler Contract

- Primary vtable cell `0x0061fd4c`, slot `+0x48`, routes UID00043V as `void OnControlCommand(int controlIndex, int notifyCode)`. `retn 8` proves two explicit arguments; `notifyCode` is unused. Cases `6/7` call `SetHoverControl(8)` after shifting. The callback has no bool return, no `NotifySelectedShapeChanged`, and no inherited default call.
- The secondary EventHandler table starts at `0x0061fd64`. Cell `0x0061fd68` / `+0x04` routes UID00043Y to `HandlePointerOrMouseEvent(Event *)`; `0x0061fd6c` / `+0x08` routes UID00043W to `HandleKeyOrTextEvent(Event *)`; `+0x0c` remains inherited `HandleImeEvent`; and `0x0061fd74` / `+0x10` routes UID00043X to `HandlePacketEvent(Event *)`.
- UID00043W is exactly 128 bytes with SHA256 `7A11666C6D57A42A95053DDAA7AF102BD6406CCAE04575B69047BEC712554B72`. It translates Event key/modifiers before gating inherited `m_activeControlId` to `8..11`; Left/Up key-down shifts left, Right/Down key-down shifts right, handled paths return true, and every other route returns `DialogPane::HandleKeyOrTextEvent(event)`. It performs no notification or hover-control update.
- UID00043X reads `event->m_payload.m_packet.m_data`, accepts opcode `0x02`, restores complete `this` from the `+0xa0` EventHandler facet, and delegates to `HandleCreateUserReply`; it has no invented null guard. UID00043Y is a nine-byte tail forwarder to `DialogPane::HandlePointerOrMouseEvent(Event *)`.
- UID00043X is exactly `[0x0052b910,0x0052b936)`, 38 bytes, with byte SHA256 `B8CDCBD9D1881904B8BBDFD194B737C15FFEAA73A59F52B250E14D1C5803DB4B`. Its four blocks are entry/opcode comparison, false return, accepted receiver/argument rewrite, and tail dispatch from `0x0052b931`; UID00043W ends at its start and ten `0xcc` bytes follow its exclusive endpoint before UID00043Y.
- The sole inbound xref is secondary-vtable cell `0x0061fd74`. Catalog entry `0352` persists the adjusted-facet IDA model `bool __thiscall(void *eventHandlerFacet, Event *event)`, automatic `event +0x08/4 Event *` frame member, and the exact repeatable comment documenting opcode `0x02`, `-0xa0` complete-object recovery, reply tail dispatch, and false mismatch. Human source remains `bool NewUserDialogPane2::HandlePacketEvent(Event *event)` and hides compiler receiver adjustment.
- Historical `bool OnCommand(int)`, `HandleShapeKeyEvent(const KeyEvent &)`, `HandleCreateUserPacketEvent(const unsigned char *)`, `ForwardDialogNotify(DialogEvent &)`, `NotifySelectedShapeChanged`, `IsLeft`/`IsRight`, direct packet/null-guard, and notification-forwarder source are superseded by the current slot, Event UDT, ABI, and callee evidence. They remain historical analysis only and are not current declarations.

## Exact Totem Selection Contract

- [UID:00043P][0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem](by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md) is the exact `[0x0052b3a0,0x0052b462)` / 194-byte source method with SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, 65 instructions, and one basic block.
- Its source ABI is `void SelectTotem(short totem)`. The stack argument is two bytes and sign-extended; constructor and control-command callers supply only `0..3`, so the body performs no clamp, comparison, branch, null check, loop, or validation.
- Inherited `GetChild<PrettyButtonControlPane>` retrieves controls `14`, `15`, `16`, and `17` into one four-pointer local array. Exact order is clear the control indexed by old `m_selectedTotem`, select the control indexed by `totem`, store `totem` at `+0x270`, then call `GetChild<TextEditControlPane>(19)->SetText(g_pLanguageMan->GetLocalizedString(totem + 212))`.
- Constructor call `0x0052b001` passes a fresh normalized `_rand() % 4`; UID00043V command cases `14..17` pass literal `0..3`. Five direct code xrefs are contained by those two caller functions, with no data/vtable route.
- STR.RES ids `212..215` are the Ju Jak, Baekho, Hyun Moo, and Chung Ryong descriptions. [UID:000443][0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest](by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md) serializes `m_selectedTotem` directly after one-based nation and before Nexonclub account text.
- Historical `SelectTotem(int)`, clamp/loop/store-first source, `SetChildButtonChecked`, `SetCreateUserDescriptionText`, and `GetString` are superseded by exact ABI and callee evidence. They remain historical analysis only and are not emitted APIs or behavior.

## Exact Gender-Mode Selector Contract

- [UID:00043R][0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode](by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md) is an exact `0x88`-byte source method with SHA256 `318E714C08908DCE721179A703BFBCBED42A2FF353F4D0A7EE03A18D3176F109`. Its callers are the constructor at `0x0052b01d` and command-id-`4` dispatch at `0x0052b790`.
- [UID:00043S][0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode](by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md) is the exact symmetric `0x88`-byte method with SHA256 `F9C237761B1388EEF54ED332579E1FFF9715284DF6FBA40F0E81BAF00C1B0135`. Its callers are the constructor at `0x0052b024` and command-id-`5` dispatch at `0x0052b79a`.
- The constructor chooses between the methods from a normalized `_rand()` bit. Command dispatch calls the corresponding selector and returns; parent notification and packet work are absent from both method bodies.
- Both selectors retrieve [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md) children `4` and `5` before calling exact [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md). Male uses `true/false`; female uses `false/true`.
- Both retrieve [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md) children `8`, `9`, `10`, and `11` in literal order. Male calls `SetMaleShapeBank()` at `0x004fd030`; female calls `SetFemaleShapeBank()` at `0x004fd050`.
- Complete call/field inventories prove no call to `SelectShapeSlot`, no access to `m_selectedShapeSlot +0x274`, no loop, no packet serialization, and no notification. Shape-slot selection remains the independent UID00043Q method.
- Historical `SetChildButtonChecked`, `GetShapeSelectControl`, `SetMaleMode`/`SetFemaleMode`, synthesized loop, and final `SelectShapeSlot(m_selectedShapeSlot)` drafts are superseded. The source-ready contract uses inherited `GetChild<T>`, `PrettyButtonControlPane::SetSelected`, and the exact UserShape bank methods.

## Exact Nexonclub Registration Contract

- [UID:00043T][0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md) is exactly `0xd4` / 212 bytes with SHA256 `46089EEA71E6B8B3912883A886152516631910E997182FF94408F0DB057BD247`; [UID:00043U][0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult](by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md) is exactly `0x2c` / 44 bytes with SHA256 `3019CB1E0DBAB342A544722DE3FD62F6A4E22042A029E15B097D9AF33895A1CE`.
- UID00043T treats its sole argument as a boolean gate. False calls `SendCreateCharacterRequest`; true allocates a 24-byte `PlainMemberFunctionObjectT`, binds UID00043U with zero this-adjust through concrete vtable `0x0061ff70`, reads `g_pLanguageMan->GetLocalizedString(227)`, and constructs the 632-byte `NexonclubRegistrationDialog`.
- Current `baram.dat` `STR.RES` id `227` / `0xe3` is `Please input nexon.com ID and password.` The source preserves the runtime LanguageMan lookup instead of hard-coding that current English payload.
- Registration success state `0` supplies account-control text to UID00043U. The callback writes nonempty text to `m_nexonclubAccountName` at `+0x27c` and always sends; [UID:000443][0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest](by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md) serializes the same field.
- `NexonclubRegistrationDialog` owns callback storage/invocation/release after construction; [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) owns reusable callback-template source. This class owns only the concrete binding and callback methods.
- `NewCreateUserDialogPane` at `0x0052d100/0x0052d1e0` and [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md)/[UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) at `0x0052e970/0x0052ea50` preserve the same method pair. The registration constructor has exactly four callers across the three create-user variants and NexonclubProxyDialog.
- UID00043T has no incoming code/data xrefs and no target VA/RVA/raw-offset pointer hits. That limits retained-callsite confidence, but exact source-level object construction, class-local data flow, and symmetric siblings reject compiler-glue or no-code treatment.
- Historical `PromptCreateCharacterName`, `ApplyCreateCharacterName`, `m_createdUserName`, local `SimpleUString initialName`, and invented generic prompt helpers are superseded by this direct binary/resource route.

## Assignment Gate

This class clears the strict parent side of the `85/85` gate at its current `93/95`. [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) is the direct source root, so exact executable and vtable children for this class should attach here first and emit through this class to `NexusTK/login/NewUserDialogPane2.cpp`. [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is now a non-emitting family/index page, not an umbrella source root.

## 2026-06-21 B010 Source-Quality Incorporation

- B010 resolves the old broad-parent split: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) is non-emitting, while [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) carries this class's method-body draft.
- Historical B010 source-facing methods included `OnCommand` and event/notify stubs. Current evidence supersedes those spellings with `OnControlCommand`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and `HandlePacketEvent`; the remaining constructor, selector, submit, request, and reply families stay valid.
- Historical B010 field direction called `+0x27c` `m_createdUserName` at a generic stored account/user-name string. Current UID00043T/UID00043U evidence resolves the producer as Nexonclub registration account text and uses `m_nexonclubAccountName`; exact original spelling remains inferred.
- Source-facing singleton/global names are `g_pNewUserDialogPane2` for `0x0069b4a4` and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) for historical `dword_67A7EC`. Raw `dword_69B4A4` and packet helper labels should remain only as evidence aliases.
- The final source should not use the Wave3 destructor-like name for `0x0052a540`; the function is constructor-shaped and directly reached from create-user launcher paths.

## 2026-06-26 B004 Exact Child Split Implementation

- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) is now a non-emitting split/index under [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), not the class method-body emitter. Its exact children hold the source-authored method C++ and the no-code proofs for raw/lifecycle islands.
- Historical B004 field interpretation: that pass called inherited `+0x1fc` storage `m_childControls` and `+0x27c` `m_createdUserName`. Fresh analysis supersedes both names where contradicted: DialogPane owns the manager and typed lookup, while `+0x27c` is the Nexonclub account string `m_nexonclubAccountName`. The valid own fields remain `m_selectedNation` at `+0x26c`, `m_selectedTotem` at `+0x270`, `m_selectedShapeSlot` at `+0x274`, and `m_waitingForCharacterReply` at `+0x278`.
- The 2026-06-26 split originally used `HandleShapeKeyEvent`, `HandleCreateUserPacketEvent`, and `ForwardDialogNotify`; those names are retained as superseded history. Current reconstructed children use `OnControlCommand`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and `HandlePacketEvent`, alongside `OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)`, `OnNexonclubRegistrationResult(const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &accountName)`, `SubmitCreateUser`, `SendCreateCharacterRequest`, and `HandleCreateUserReply`. `SendCreateAccountRequest` remains intentionally absent because `0x0052bbc0-0x0052bdc5` is a file-local `NewUserDialogPane2.cpp` helper.
- The accepted packet/reply interpretation supersedes the old aggregate body: opcode `0x02` account request writes a trailing zero byte, opcode `0x04` character request extracts two shape bytes from the selected child control and sends `SizeWithoutTerminator`, reply status is `packet[1]`, reply text is length/data at `packet+2`/`packet+3`, first-phase success sets `m_waitingForCharacterReply`, sends the character request, and copies edit control `1` into `g_newUserDialogCreatedAccountName`.
- `g_createUserScreenDimmer`, `g_newUserDialogCreatedAccountName`, `kCreateUserDefaultProfileText`, `PacketBuffer`, `GetChildEditText`, `FocusChildControl`, `ShowCreateUserAlert`, `DecodeCreateUserReplyMessage`, `ShowCreateUserReplyText`, `IsCreateUserNameReplyError`, and `IsCreateUserPasswordReplyError` are inferred source-facing names for observed helpers/globals, not proven original symbols.
- The compiler/generated support side now includes [UID:000445][0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail](by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md) as the `0x0061fd94-0x0061fd9c` tertiary vtable-view tail. It is non-reconstructable/non-emitting vtable data under this class; the normal class declaration and virtual-method set regenerate it.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## 2026-08-11 UID0001CU Registration-Provider Incorporation

- Metadata remains `93/95`; owner/emitter remain [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), reconstructable remains true, position remains `10`, and `Nested:0` remains exact.
- Formal CPP remains blank. Formal H is compile-closed and preserves the complete class declaration, singleton pointer, existing virtual handlers and selection helpers, registration pair, request/reply methods, and private state.
- The callback and retained account field now use wide StringBase. UID00043T/UID00043U own the definitions; UID0001CU owns the registration dialog's callback lifetime after construction.
- RegistrationString remains function-local in the provider CPP and does not leak into this public declaration.

## Changes

- 2026-07-29 B004 UID00043X implementation callback: raised `92/94 -> 93/95`; added the required `class Event;` forward declaration to the complete H payload; incorporated the exact target range, size, byte hash, four-block CFG, boundaries, sole vtable xref, adjusted-facet ABI, catalog-0352 saved readback, and source-versus-compiler receiver distinction while preserving all unrelated declarations and history.

- 2026-07-29 B002 Gate 2A repair callback: corrected the current Assignment Gate score from stale `88/89` wording to metadata-consistent `92/94`; the older `88/89` transition remains only in its explicitly dated history below.
- 2026-07-29 B002 UID00043W implementation callback: retained class metadata at `92/94`; replaced stale OnCommand/KeyEvent/direct-packet/notification declarations with exact `OnControlCommand` and EventHandler overrides; removed the nonexistent notification helper; synchronized primary/secondary slot, Event layout, complete-this, key/packet/fallback/no-notification evidence; and preserved all displaced names as superseded history.

- 2026-07-28 B003 UID0002X4 implementation callback: retained `92/94`, moved the complete class declaration from CPP to H at position `10`, added the extern singleton declaration and direct `Singleton<NewUserDialogPane2>` base, incorporated exact RTTI/PMD `+0x26c` and `0x280` EBO layout evidence, documented one-definition/generated topology, and historicalized omitted-base, explicit-publication, raw-name, and stale-initializer assumptions.

- 2026-07-22 B002 accepted UID00043T implementation callback:
  - Retained class metadata at `92/94`, owner/emitter UID0000LW, reconstructable true, complete declaration, and unrelated class evidence.
  - Replaced stale character-name method declarations and `m_createdUserName` with the exact Nexonclub registration gate, result callback, and `m_nexonclubAccountName`.
  - Added exact ranges, hashes, branches, callback layout/lifetime, id-227 resource provenance, account-field/packet route, siblings, no-route proof, source ownership, rejected alternatives, and explicit superseded history.

- 2026-07-22 B002 UID00043R implementation callback:
  - Kept class metadata and complete declaration unchanged at `92/94` while synchronizing exact UID00043R/UID00043S behavior.
  - Added ranges, hashes, callers, constructor/command roles, child ids/types, selected-state arguments, shape-bank calls, literal ordering, and complete no-reselect/no-loop/no-packet/no-notification proof.
  - Preserved prior generic helper/loop/reselect source as explicitly superseded history rather than silently dropping it.

- 2026-07-22 B002 accepted UID00043N implementation callback:
  - Raised `88/89` to `92/94`; retained owner/emitter UID0000LW, reconstructable true, and blank optional position.
  - Removed only the contradicted derived `ChildControlCollection *m_childControls`; preserved the inherited DialogPane lookup route and exact own fields at `+0x26c..+0x27c`.
  - Moved `[[CHILDREN]]` after the class closing brace and preserved every unrelated declaration and historical fact.
  - Linked exact UID00043M/UID00043N reciprocal source bodies, constructor member-callback liveness, controls `6-11`, non-edge selection, edge gates, signed-short step semantics, button updates, caller-owned notification, and compiler-cookie exclusion.
- Before: completion/confidence metadata were `0/0` even though the page already documented class purpose, method boundaries, assets, destructor family, and Wave3 naming caveat.
- Changed to: `COMPLETION:72` and `CONFIDENCE:76`.
- Evidence: IDA-confirmed constructor/destructor starts, selector/submit method inventory, fixed-layout resources, and cross-links support a moderate-high score; confidence remains medium because the current Wave3 constructor name is wrong and detailed state/layout fields remain incomplete.
- 2026-06-02 owner/emitter attachment:
  - What existed before: the class had no reconstructable flag or parent attachment and was scored `72/76`.
  - Changed to: `RECONSTRUCTABLE:TRUE`, file-root owner/emitter routing through [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), completion `74`, and confidence `80`.
  - Summary/evidence: the exact child memory page records constructor, singleton, vtable, selector, submit, packet, and response-handler evidence; the class now has a validated login/create-user file parent, but reconstructed C++ remains blank until final names and layout are audited.

- 2026-06-06 evidence sync:
  - What existed before: the class page remained at `74/80` even though the linked exact child and vtable pages now record the constructor callers, selector helpers, submit/packet/reply paths, vtable refs, singleton slot, and boundary split.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md), and [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) now cover the core method inventory, constructor reachability, vtable/singleton evidence, and login/create-user ownership. C++ remains blank because source-grade field/helper names and source split are unresolved.
- 2026-06-14 C001 Goal 2 refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Evidence: live IDA MCP on `a001_goal2_class_batch` reconfirmed the exact executable child starts/sizes, constructor callers, vtable/singleton xrefs, and representative internal call graph for the constructor/command/submit/packet/reply cluster. The class now clears the strict parent gate for [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md); final C++ remains blank because field names and helper names are not final-source quality.
- 2026-06-16 A001 Goal 2 evidence refresh:
  - Before: `85/86`.
  - Changed to: `86/88`.
  - Evidence: live IDA/PE checks reconfirmed constructor branches, no constructor pointer encodings, submit/packet decompilation behavior, vtable refs/pointer stores, singleton refs, and the `0x0052c360` successor boundary. The exact vtable child now routes through this direct class; final C++ remains blank because source-grade field/helper names and standalone-versus-umbrella source placement are unresolved.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Changed to: `88/89`, first-draft class declaration C++ populated, owner/emitter unchanged [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md).
  - Summary/evidence: incorporated child-only emission, direct constructor reachability, singleton/vtable names, method/helper names, field candidates, packet-helper alias rejection, and the correction that [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is non-emitting family context only.
- 2026-06-26 B004 implementation sync:
  - Updated the declaration and method inventory to the exact split-child names, field names, file-local packet-helper boundary, raw helper no-code disposition, corrected packet/reply interpretation, and tertiary vtable-tail support from the accepted B004 report.
- 2026-07-04 B014 UID0002SH vtable support sync:
  - Recorded that the primary/secondary vtable page is now source-declared/generated-binary support at `88/92`, non-reconstructable and non-emitting under this class. The direct source route remains this class declaration plus exact virtual-method children; inherited-interface and exact original spelling caveats remain class-level confidence limits, not a reason to emit a vtable array.
