*** UID:00003B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
class KeyEvent;
class CreateUserDialogPane;
extern CreateUserDialogPane *g_pCreateUserDialogPane;

class CreateUserDialogPane : public DialogPane,
                             public Singleton<CreateUserDialogPane>
{
public:
    CreateUserDialogPane();
    virtual ~CreateUserDialogPane() {}

    void SelectBodyShape(short bodyShapeIndex);
    void SelectMale();
    void SelectFemale();
    unsigned char SetHairColorIndex(unsigned char colorIndex);
    unsigned char SetFaceColorIndex(unsigned char colorIndex);

protected:
    void OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration);
    void OnNexonclubRegistrationResult(
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &text);

    virtual void OnDialogAction(int commandId, int action);
    virtual bool OnKeyEvent(KeyEvent *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnDialogShow(int reason);

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    int m_initialAppearanceRoll;
    int m_bodyShapeIndex;
    bool m_waitingForCharacterReply;
    bool m_isFemale;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        m_createUserExtraText;
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CreateUserDialogPane

## Status

- Confidence: very strong for behavior, direct base hierarchy, exact `0x280` layout, lifecycle ownership, old-dialog method inventory, H-channel class declaration, semantic-global contract, and compiler/source separation; stripped lexical spellings remain bounded below-95 caps.
- Likely source file: [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), under [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Address range: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- Exact method-range evidence: [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md), now a non-emitting split/index whose exact children carry source C++ or no-code proof, with lifecycle glue in [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- Associated generated/static data: false/non-emitting [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md), false/non-emitting physical slot [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md), semantic source definition [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md), and non-emitting callback support [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md).
- Historical generated-output lead: `source-3/simroot_v2/class_CreateUserDialogPane.cpp`; use IDA and the linked project docs as authority for current scoring.
- Autogen parent: [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), source position `10`. The complete declaration belongs in H and CPP is exactly blank; executable method bodies remain routed by their exact children without an H-channel `[[CHILDREN]]` token. The inline empty virtual destructor is the source cause for compiler teardown wrappers. Vtable/COL data, physical singleton storage, vptr stores, adjustor thunks, scalar deleting destructor wrappers, nullsubs, and raw cleanup/padding spans stay false/non-emitting compiler evidence rather than handwritten class code.

## Class Purpose

`CreateUserDialogPane` is a full-screen create-user dialog. It builds the `DLGNEW3` account/character setup UI, randomizes initial body/hair/face state, drives gender/body selection, updates the preview, validates password fields, and sends the create-user request.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CreateUserDialogPane` | `0x0052dd30` | Builds `DLGNEW3` dialog, text edits, gender/body buttons, hair/face selectors, color lists, and preview. |
| `SelectBodyShape` | `0x0052e770` | Updates selected body shape and description text. |
| `SelectMale` / `SelectFemale` | `0x0052e850`, `0x0052e8c0` | Toggles dialog gender state, updates gender buttons, calls hair selector `SetMaleMode`/`SetFemaleMode` on control id `6`, writes face selector gender bank byte `+0x10c` through the accepted `SetGender` source-facing setter on control id `7`, and invalidates the face selector. Preview refresh is performed by `OnDialogAction`, not these helpers. |
| `SetHairColorIndex` / `SetFaceColorIndex` | `0x0052e930`, `0x0052e950` | IDA MCP confirms these as 0x1f-byte color setter helpers called from the hair/face color-list controls. They look up controls `6`/`7`, write selector color byte `+0x10d` through the accepted inline setter names, return the argument, and do not invalidate or refresh preview state. |
| `OnDialogAction` | `0x0052ea80` | Handles gender, body, scroll, submit, cancel, and preview-direction commands. |
| `OpenNexonclubRegistrationOrSendCharacterRequest` | `0x0052e970` | Exact 212-byte retained helper that tests `bool openRegistration`; false sends the character request, while true allocates the compiler-proven three-parameter `PlainMemberFunctionObjectT` bound to `OnNexonclubRegistrationResult`, uses language id `227`, constructs `NexonclubRegistrationDialog`, and transfers callback ownership without invented null guards or cleanup. |
| `OnNexonclubRegistrationResult` | `0x0052ea50` | Exact 44-byte const-wide-string callback with one binding from the opener; copies non-empty registration text into `m_createUserExtraText` at `+0x27c`, then calls `SendCreateCharacterRequest` unconditionally. |
| `OnKeyEvent` / `HandlePacketEvent` / `OnDialogShow` | `0x0052ecc0`, `0x0052ecd0`, `0x0052ed00` | Secondary-vtable wrappers: key and show/open behavior delegate to `DialogPane`; UID00046S is exact EventHandler slot `+0x10`, reading `event->m_payload.m_packet.m_data` at Event `+0x0c`, accepting opcode `packet[0] == 0x02`, returning false otherwise, recovering complete this from the `+0xa0` facet, and tail-returning `HandleCreateUserReply(packet)` without raw casts or null guards. |
| raw/null/no-code children | `0x0052e6f0`, `0x0052e730`, `0x0052e750`, `0x0052e840`, `0x0052ed10`, `0x0052f6e5` | Constructor cleanup, no-route raw helpers, nullsubs, and reply switch-table/padding are represented by blank-C++ child pages under [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md), not class declarations. |
| `SubmitCreateUser` | `0x0052ed80` | Validates password digit/match rules, shows alerts, and sends create-account request. |
| `SendCreateAccountRequest` | `0x0052ef50` | File-local/free opcode `0x02` helper emitted by [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), not by this class; it converts three wide strings to MBCS length-prefixed fields and sends through `g_packetSender`. |
| `SendCreateCharacterRequest` | `0x0052f160` | Sends opcode `0x04` using current preview appearance, `m_bodyShapeIndex`, and `m_createUserExtraText`; creates a screen dimmer when needed. |
| `HandleCreateUserReply` | `0x0052f390` | Two-phase server reply handler split by `m_waitingForCharacterReply`; status is `packet[1]`, message length is `packet[2]`, message bytes are `packet + 3`, first account success caches the username, and second-stage success/failure closes dimmers and reports server/fallback text. |
| `ScalarDeletingDestructor` | `0x0052f800` | Restores the `CreateUserDialogPane` vtables, destroys dialog state, clears the [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md), runs the base destructor, and optionally frees `this`. |

## 2026-06-20 B004 Source-Quality Resolution

- Source route: keep direct ownership under [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) / `NexusTK/login/CreateUserDialogPane.cpp`. [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) remains an umbrella/source-family page, and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) remains an aggregate/split index rather than the direct class owner.
- Positive owner evidence: constructor calls at `0x004f7a82` and `0x004f8ff8`, vtable installs at `0x0061fe3c`, `0x0061fe9c`, and `0x0061fecc`, singleton publication through `0x0069b890`, and the old-dialog-specific [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) split children for DLGNEW3 layout, appearance selectors, password validation, packet encoders, reply handling, raw cleanup/null proof, and switch-table padding.
- Rejected owners: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is only the family umbrella; [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) spans old/new variants and lifecycle glue; `NexonclubRegistrationDialog` only consumes/calls back into the old dialog; `MainMenuPane` owns launchers such as `OpenCreateUserDialog_4F8FA0`; and [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) owns selector controls that call this dialog, not the dialog fields those callbacks mutate.
- Old/new split: old `CreateUserDialogPane` is active and reachable; `NewUserDialogPane2` is a separate active sibling with direct launch routes; `NewCreateUserDialogPane` remains a distinct retained/no-direct-constructor-route class until stronger route evidence appears. Do not fold the retained launcher or all three variants into this class page.

## 2026-07-22 B003 Registration Callback Source Closure

- [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) is now `92/94`. Its exact 212-byte body has byte SHA-256 `21D7FD7646F890A61CD299278685A2CFF297ABA0EDB49D443741CBE184999CBA`, predecessor `0xcc`, twelve-byte `0xcc` successor padding, and no recovered inbound xref or absolute/RVA pointer route.
- The historical `void *context` signature is rejected because the stack argument is only tested for zero. The class declaration's `bool openRegistration` is the strongest source form.
- The current two-argument callback shorthand is also rejected. Live compiler metadata at vtable `0x00620094` and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) prove a three-parameter `PlainMemberFunctionObjectT<TMember, TObject, TArg>` specialization. UID00046O uses a local pointer-to-member typedef, `CreateUserDialogPane`, and `const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &` in human C++03 source.
- Exact callback object layout is 24 bytes: member target [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) at `+0x08`, zero this-adjustment at `+0x0c`, and bound `CreateUserDialogPane` at `+0x10`. [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) records the compiler-generated locator/five-slot vtable and remains non-reconstructable/non-emitting.
- The true branch uses `g_pLanguageMan->GetLocalizedString(227)`, allocates a 632-byte `NexonclubRegistrationDialog`, and transfers the callback. The registration constructor stores it at `+0x26c`; cancel/success paths invoke it, and the registration destructor releases it with deleting-destructor flag `1`.
- [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) is now `90/93`. It stores non-empty text in `m_createUserExtraText` at class offset `+0x27c` and sends the character request unconditionally.
- Callback allocation failure may pass null if the dialog allocation succeeds; dialog allocation failure returns without an explicit callback release on that path. Do not introduce explicit guards, smart pointers, callback cleanup, modern callback syntax, or handwritten RTTI/vtable data.
- Same-shaped retained helpers at `0x0052b650` and `0x0052d100` corroborate the no-entry source-retention pattern. The absent direct caller caps source-name confidence but does not reclassify this coherent class method as compiler glue.
- Original private method/local typedef/parameter spelling and literal text for language id `227` remain below-95 caveats. They do not justify raw IDA names or blank class/member C++.

## Field And Control Layout

| Offset/control | Source-facing name or role | Evidence and caveat |
| --- | --- | --- |
| inherited `+0x1fc` | inherited dialog control collection/manager | Constructor and methods pass `this+508` to control lookup helpers for ids `1` through `18`; keep inherited, not a unique field. |
| `+0x26c` | `m_initialAppearanceRoll` / write-only initial gender or appearance roll | Constructor writes `rand() % 2`; checked old-dialog methods do not read it. Do not claim it drives final gender/body state. |
| `+0x270` | `m_bodyShapeIndex` | `SelectBodyShape` stores it; opcode `0x04` create-character sender serializes it. |
| `+0x278` | `m_waitingForCharacterReply` | Set after account/create-user success and before `SendCreateCharacterRequest`; `HandleCreateUserReply` branches on it. Reject stale/generated `m_previewDirty`. |
| `+0x279` | `m_isFemale` | `SelectMale` writes zero and `SelectFemale` writes one; preview and packet paths consume it as sex/gender state. |
| `+0x27c` | `m_createUserExtraText` / optional registration text | Constructed as a `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`, filled by `OnNexonclubRegistrationResult`, and serialized by `SendCreateCharacterRequest`; it is not body-description text or the username field. |
| control `1` | account/username edit | Read during submit and first-stage success cache. |
| controls `2` / `3` | password / confirmation edit | Password digit rule and confirmation comparison source. |
| controls `4` / `5` | male / female buttons | Toggled by `SelectMale` and `SelectFemale`. |
| controls `6` / `7` | hair / face selectors | Control `6` is `UserHairSelectControlPane`; `SelectMale`/`SelectFemale` call its `SetMaleMode`/`SetFemaleMode` helpers at `0x00501620`/`0x00501640`, and hair-color callbacks write its selected color byte to `+0x10d`. Control `7` is `UserFaceSelectControlPane`; gender selection writes its `+0x10c` bank byte directly and invalidates, while face-color callbacks write `+0x10d`. |
| controls `8` / `9` | selector scroll/action controls | Used by the command dispatcher around selector updates. |
| controls `10` through `13` | body-shape buttons | `SelectBodyShape` toggles the old and new body buttons. |
| control `14` | body description label | Updated with `g_pLanguageMan` id `bodyShapeIndex + 212`. |
| controls `15` / `16` / `17` | submit / cancel / preview direction | Handled by `OnDialogAction`; id `17` advances or rotates preview direction. |
| control `18` / `0x12` | `UserCreatePreviewControlPane` | Constructed at `0x0052e64b`, advanced at `0x0052eafe` and `0x0052e730-0x0052e744`, refreshed at `0x0052eb68` from current face, hair, color, and `m_isFemale` state, and queried by `SendCreateCharacterRequest` at `0x0052f1e8` through `BuildPreviewParams`. |

Rejected field names: do not use `m_previewDirty` for `+0x278`, do not use `m_descriptionText` for `+0x27c`, and do not promote `+0x26c` to a proven final gender/body field without a read-side route.

## 2026-06-20 B005 Preview-Control Route Sync

- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md) remains owned/emitted by [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); this old dialog class is the coordinator that creates and calls it through inherited control lookup id `0x12` / decimal `18`.
- The constructor route at `0x0052e64b` derives preview inputs from the old face and hair selectors: face frame is read from the face selector's gender-indexed face-id bank, hair frame is read from the hair selector's `m_hairPartFrames[m_genderStyle][m_selectedHairSlot]` table using index `selectedHair + 18 * hairStyle`, face and hair colors are read from selector `+0x10d`, and the dialog gender byte is read from `+0x279`. The call also pushes a trailing zero reserved argument; the preview constructor returns with `ret 0x1c`, so the unused ABI slot must stay documented.
- The command path reaches `UserCreatePreviewControlPane::AdvanceDirection` directly at `0x0052eafe`; the raw/tail helper at `0x0052e730-0x0052e744` fetches control id `0x12` and jumps to the same method.
- `OnDialogAction` refreshes the preview at `0x0052eb68` by pushing selected face frame, face color, hair frame, hair color, and `m_isFemale` into `UserCreatePreviewControlPane::UpdatePreview`.
- `SendCreateCharacterRequest` / appearance payload building queries control id `0x12` at `0x0052f1e8` and calls `BuildPreviewParams`. This supports a source-facing payload route through the preview pane rather than copying preview-field layout into the dialog class.
- `SelectMale` and `SelectFemale` update `m_isFemale` and reconfigure the selector controls; `SelectBodyShape` remains separate body-button state. Do not treat `UserCreatePreviewControlPane` as owning `m_bodyShapeIndex`.

## 2026-06-21 B007 Face-Selector Route Sync

- The old dialog constructs [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md) for control id `7` with allocation size `0x154`, bounds `{170,545,676,662}`, constructor arguments `selectedFace = rand() % 10`, `faceColor = 1`, `gender = 0`, `bounds`, and `controlFlag = 0`.
- `SelectMale` writes `m_isFemale = 0`, toggles controls `4`/`5`, calls [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) `SetMaleMode` at `0x00501620` on control id `6`, writes byte `0` to face selector `+0x10c` on control id `7`, and invalidates the face selector. Preview refresh occurs in `OnDialogAction`.
- `SelectFemale` mirrors this with `m_isFemale = 1`, hair `SetFemaleMode` at `0x00501640`, face selector `+0x10c = 1`, and face selector invalidation. Preview refresh occurs in `OnDialogAction`.
- `SetFaceColorIndex` at `0x0052e950` looks up control id `7`, writes the selected face color to `+0x10d`, and returns the argument; it does not invalidate or refresh preview state. The face selector is a caller/coordinator dependency here; ownership of the selector class remains [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Preview setup reads the face selector as `m_facePartIds[m_gender][m_selectedFace]` plus `m_faceColor`; the dialog's own `m_isFemale` byte remains the gender argument passed to the preview pane and the create-character payload.

## 2026-06-21 B009 Hair-Selector Route Sync

- The old dialog constructs [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) for control id `6` with allocation size `0x16c`, bounds `{170,342,926,477}`, constructor arguments `selectedHair = rand() % 10`, `hairColor = 12`, `genderStyle = 0`, and `controlFlag = 0`.
- `SetHairColorIndex` at `0x0052e930` looks up control id `6`, writes selected hair color to selector `+0x10d`, and returns the argument; it does not invalidate or refresh preview state. Ownership of the selector class remains [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Preview setup and refresh read the hair selector as `m_hairPartFrames[m_genderStyle][m_selectedHairSlot]` plus `m_hairColor`; the style/gender bank is changed by `SetMaleMode`/`SetFemaleMode` at `0x00501620`/`0x00501640`.

## Submit, Packet, Reply, And Literal Flow

- [UID:00046S][0x0052ecd0-0x0052ecf6.CreateUserDialogPaneHandlePacketEvent](by-memory/0x0052ecd0-0x0052ecf6.CreateUserDialogPaneHandlePacketEvent.md) is exactly 38 bytes with SHA256 `B8CDCBD9D1881904B8BBDFD194B737C15FFEAA73A59F52B250E14D1C5803DB4B`. Its sole inbound xref is secondary-vtable cell `0x0061feac`; four blocks implement Event packet extraction, opcode `0x02` comparison, false mismatch return, raw-facet receiver/argument rewrite, and a tail jump from `0x0052ecf1` to `HandleCreateUserReply` preserving the Boolean result.
- Source declares `virtual bool HandlePacketEvent(Event *event);`. The raw entry uses an EventHandler facet at complete-object `+0xa0` and compiler adjustment `-0xa0`; the adjusted receiver is not expressed in human source. The bridge does not read reply result byte `packet[1]`, add null guards, or define a separate `PacketEvent` type.
- `SubmitCreateUser` reads account/username control `1`, password control `2`, and confirmation control `3`; requires at least one password digit; compares confirmation with `wcscmp`; focuses invalid controls; and uses alert panes for failures.
- The missing-digit alert uses `off_61E318`, decoded in the B004 pass as the UTF-16 literal `"password must containt at least 1 number"`; preserve the binary typo. Password mismatch uses localized language id `90` from `g_pLanguageMan`, and alert buttons use [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md).
- Successful first-stage validation creates a screen dimmer through `g_pScreenPane` and calls file-local `SendCreateAccountRequest` with [shared empty wide string / `word_60DB20`] as the third profile string.
- `SendCreateAccountRequest` writes opcode `0x02`, converts three wide strings with `WideCharToMultiByte`, writes length-prefixed account, password, and third-string payloads, and sends through `g_packetSender`.
- `SendCreateCharacterRequest` creates a dimmer if needed, snapshots preview control `18`, writes opcode `0x04`, serializes preview appearance fields, a trailing zero byte, `m_bodyShapeIndex`, and a multibyte copy of `m_createUserExtraText`, then sends through `g_packetSender`.
- `HandleCreateUserReply` uses `m_waitingForCharacterReply` as the two-phase split. First-stage success sets the flag, sends the character request, reads control `1`, and caches the account/username through `g_pConfig`; first-stage errors close dimmers, map error codes `3`, `4`, `14`, `16`, `17`, `18`, `20`, and `21` to username focus, and error codes `5`, `6`, `7`, `8`, `9`, and `15` to password focus. Second-stage success closes the dimmer, shows server/fallback text, and closes the dialog; second-stage error closes the dimmer and shows non-empty server text.
- `word_61FF48` is a fallback second-stage reply/success text. No safe decoded/source name was found in checked docs; use a tentative comment name such as `kDefaultCreateUserReplyText` until string recovery resolves it.

## Vtable, Singleton, And Generated-Code Policy

- The sole semantic singleton definition is [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md). This H channel carries exactly one matching `extern CreateUserDialogPane *g_pCreateUserDialogPane;`; the class CPP channel does not duplicate the definition.
- RTTI proves direct bases in source order: `DialogPane`, then `Singleton<CreateUserDialogPane>`. The Singleton base descriptor PMD is `{0x26c,-1,0}` with attributes `0x40`.
- `DialogPane` occupies `0x26c` bytes. Old-MSVC empty-base optimization permits the empty Singleton base and first derived field `m_initialAppearanceRoll` to share `+0x26c`; no synthetic padding or fake nonempty Singleton member is authored. Complete-object size remains exactly `0x280`.
- [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md) is loader-zeroed physical backing only. Constructor publication/fallback and unwind/scalar clears are direct Singleton-base compiler/template lowering, so ordinary constructor/destructor source must not handwrite them.
- Vtable bases: primary `0x0061fe3c`, secondary `0x0061fe9c`, and tertiary `0x0061fecc`. Constructor install refs are `0x0052dda2`, `0x0052dda8`, and `0x0052ddb2`; constructor-adjacent fallback/reinstall refs are near `0x0052e6f9`, `0x0052e6ff`, and `0x0052e709`; destructor reinstall refs are `0x0052f80c`, `0x0052f812`, and `0x0052f81c`.
- [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md) now records all 36 function slots and three in-range COL dwords. It is false/non-emitting and regenerated by this declaration plus exact virtual children; no raw vtable/COL arrays are authored.
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) stays generated/lifecycle support. `0x0052f73b` and `0x0052f746` are adjustor thunks into the old-dialog scalar deleting destructor. `0x0052f800` is an MSVC scalar deleting destructor wrapper generated from the ordinary source destructor relationship and should not be copied as handwritten source.
- `source-3/simroot_v2/class_CreateUserDialogPane.cpp` is a useful lead only. It omits active methods (`SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, `OnDialogShow`, and the secondary reply-event bridge), uses weak generated names such as `m_previewDirty` and `m_descriptionText`, and does not separate scalar deleting destructor/vtable mechanics from source.

## 2026-06-21 B010 Family Reconciliation

- B010 confirms this class is the direct old-dialog class owner while [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) are non-emitting family/index pages.
- The old-dialog route now flows through [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) as a non-emitting split/index whose exact children hold method-body C++ or no-code proof, while [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) remains non-emitting compiler lifecycle support.
- The direct old-dialog constructor routes at `0x004f7a82` and `0x004f8ff8` should not be used to rename or collapse retained/newer [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md) or active sibling [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md).
- The current class declaration and child method-body C++ are valid first-draft source under the active 85/85 eligibility rule. Remaining issues cap final-audit confidence but are not reasons to remove the draft.

## 2026-06-26 B008 Core Split Implementation

- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) is now a non-emitting `Nested:22` split/index. Source-authored children carry exact formal C++; constructor cleanup, no-route raw helpers, nullsubs, and reply switch-table/padding children carry blank formal C++ with target-specific no-code proof.
- The class declaration now uses the accepted source-facing signatures: `OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)`, `OnKeyEvent(KeyEvent *event)`, and `HandlePacketEvent(Event *event)`. The no-route nullsub at `0x0052ed10` is not declared as a virtual method.
- The account helper at `0x0052ef50` is file-local/free and emitted by [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), so it is not declared as a static class member.
- Reply handling uses `packet[1]` for status, `packet[2]` for message length, and `packet + 3` for message bytes. The packet bridge uses `event->m_payload.m_packet.m_data`, checks opcode `packet[0]`, and does not expose raw event-buffer casts or adjusted-this pointer arithmetic.

## Evidence Notes

- IDA confirms the constructor and submit method starts.
- Wave3 class inspection lists 13 methods, but the generated file currently omits several listed methods. This is recorded as a Wave3 data/materialization issue.
- 2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed the old-dialog function inventory: constructor `0x0052dd30` size `0x9bb`, selector helpers `0x0052e770` size `0xc2`, `0x0052e850`/`0x0052e8c0` size `0x67`, color setters `0x0052e930`/`0x0052e950` size `0x1f`, command dispatcher `0x0052ea80` size `0x200`, submit validator `0x0052ed80` size `0x1cc`, packet/reply helpers `0x0052ef50` size `0x205`, `0x0052f160` size `0x22d`, `0x0052f390` size `0x355`, singleton clear helper `0x0052f710` size `0xb`, adjustor thunks `0x0052f73b`/`0x0052f746` size `0xb`, and scalar deleting destructor `0x0052f800` size `0x6c`.
- 2026-06-14 A001 xref/callee refresh confirmed constructor callers at `0x004f7a82` and `0x004f8ff8`, command-dispatch to submit edge `0x0052ea80 -> 0x0052ed80`, submit helper edge `0x0052ed80 -> 0x0052ef50`, destructor/vtable refs through `0x0061fe3c`, and singleton-slot refs at `0x0052dd87`, `0x0052dd8e`, `0x0052f710`, and `0x0052f82d`.
- 2026-06-14 boundary byte check reconfirmed that the `0x0052f6e5-0x0052f710` span is jump/table and `0xcc` alignment before the destructor/thunk island, and `0x0052f94c` begins `0xcc` padding after the island.
- 2026-06-03 IDA MCP recheck confirms method boundaries for the core old-dialog methods: constructor `0x0052dd30` size `0x9bb`, `SelectBodyShape` `0x0052e770` size `0xc2`, color setters `0x0052e930`/`0x0052e950` size `0x1f` each, command dispatcher `0x0052ea80` size `0x200`, submit validator `0x0052ed80` size `0x1cc`, packet helpers `0x0052ef50` size `0x205`, `0x0052f160` size `0x22d`, response handler `0x0052f390` size `0x355`, singleton clear helper `0x0052f710` size `0xb`, adjustor thunks `0x0052f73b`/`0x0052f746` size `0xb`, and scalar deleting destructor `0x0052f800` size `0x6c`.
- 2026-06-03 IDA MCP caller checks show the constructor called from `0x004f7a82` and `0x004f8ff8`, the command dispatcher calling `0x0052ed80`, the submit validator calling `0x0052ef50`, and the appearance payload helper `0x0052f160` called from local helpers and the response handler.
- 2026-06-03 IDA MCP xrefs tie [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md) to constructor/destructor references at `0x0052dda2`, `0x0052e6f9`, and `0x0052f80c`, and [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md) to constructor writes/reads plus cleanup at `0x0052f710` and `0x0052f82d`.
- 2026-06-03 IDA MCP decompilation confirms `0x0052e930` looks up control id 6 and writes the selected byte to offset `269`; `0x0052e950` does the same for control id 7. Xrefs to the setters come from the hair/face color-list controls at `0x00501eee`, `0x005020b9`, `0x005021ae`, and `0x00502379`.
- 2026-06-03 IDA MCP decompilation of `0x0052ed80` confirms the submit path reads three text-edit controls, requires at least one digit in the password, compares password confirmation with `wcscmp`, shows alert panes on validation failure, and calls `0x0052ef50` after a successful validation.
- 2026-06-03 IDA MCP disassembly confirms the two 0xb-byte adjustor thunks subtract `0xa0` or `0xa4` from `ecx` before jumping to `0x0052f800`, and the scalar deleting destructor restores three `CreateUserDialogPane` vtables, destroys the description text, clears the `CreateUserDialogPane` singleton slot, runs the base destructor, and conditionally frees `this`.
- The current by-memory child pages split the old-dialog implementation into [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md); the child at `0x0052f6e5-0x0052f710` is reply switch-table/padding evidence, not additional source logic.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `93` | The class page now covers the complete old-dialog behavior/method/field/control/packet/reply source union, exact owner/routing, direct `DialogPane` plus `Singleton<CreateUserDialogPane>` hierarchy, PMD/EBO layout, one extern/global contract, complete H declaration with CPP blank, exact child routing, UID00046S Event bridge hash/CFG/slot/receiver/return contract, false physical/vtable children, and no-handwritten compiler artifacts. |
| Confidence `94` | RTTI hierarchy/PMD, exact ordinal-592 `0x280` eight-member layout, singleton lifecycle, three-view vtable/COL evidence, Event/EventHandler declarations, byte-identical accepted bridge precedents, exact UID00046S child, and source-root behavior agree. Confidence remains below `95` only because stripped original lexical names for a few unrelated helpers and `word_61FF48` cannot be proven byte-for-byte. |

## Historical And Superseded Assumptions

- Executed B015 and B008 research correctly established UID00046S range/behavior, UID0002QT's 22-child split, owner route, receiver adjustment, and no-code boundaries, but inferred `OnCreateUserReplyEvent(const PacketEvent *)` from then-current support precedent. The EventHandler slot, Event UDT, and byte-identical accepted handlers supersede only that name/type/payload conclusion. It remains historical provenance and is not a current declaration.
- Earlier formal declaration source lived in the class CPP channel and omitted the direct Singleton base. The declaration now lives in H, includes RTTI-proven `Singleton<CreateUserDialogPane>`, and leaves CPP blank for exact source separation.
- Earlier class code placed `[[CHILDREN]]` inside the class body. The marker now follows the completed class declaration so method definitions route as implementation children rather than invalid members.
- Earlier singleton prose used `dword_69B890` and treated publication/clear as explicit lifecycle assignments. Semantic UID0004Y3 plus the direct Singleton PMD/EBO route supersede that decompiler-shaped source model.
- Earlier physical/vtable pages remained reconstructable blank emitters. UID0002B3 and UID0002SI are now false/non-emitting evidence regenerated by the semantic global, class H, and exact method children.

## Cross-References

- [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md)
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md)
- [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md)
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md)
- [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md)
- [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)

## 2026-08-11 UID0001CU Registration-Provider Incorporation

- Metadata remains `93/94`; owner/emitter remain [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), reconstructable remains true, position remains `10`, and `Nested:0` remains exact.
- Formal CPP remains blank. Formal H is compile-closed for the current source route and preserves the complete class, singleton pointer, existing appearance and event methods, registration opener/result callback, and trailing state.
- The registration result uses `const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >&`; the prior SimpleUString approximation is historical. The pane owns provider construction and callback result policy, while UID0001CU owns dialog storage/invocation/deletion.
- RegistrationString remains translation-unit-local in the provider CPP and is deliberately absent from this public declaration.

## Changes

- 2026-07-29 B004 UID00043X support implementation callback:
  - Raised `92/93 -> 93/94`; replaced the complete H payload with one `class Event;` declaration, `HandlePacketEvent(Event *)`, and exact ordinal-592 `bool` state members while preserving every unrelated declaration and `[[CHILDREN]]`.
  - Added UID00046S's exact bytes/hash/CFG, vtable slot, Event payload, no-null, opcode/result, secondary-facet receiver, tail-return, CPP/H placement, score rationale, and superseded PacketEvent history. IDA remained pending supervisor Gate 2B.

- 2026-07-26 B003 accepted UID0002B3/UID0002SI callback:
  - Raised `88/89 -> 92/93`, set source position `10`, moved the complete class declaration from CPP to H, added direct `Singleton<CreateUserDialogPane>` inheritance and one semantic-global extern, moved `[[CHILDREN]]` after the class declaration, and incorporated exact PMD/EBO, physical-slot, vtable/COL, one-definition, compiler-lowering, and historical-correction evidence.

- 2026-07-22 Agent-B003 UID00046O Rule 26 support sync:
  - Kept class metadata `88/89`, owner/emitter UID0000IJ, and declaration-level formal C++.
  - Replaced the stale registration-helper callback description with the exact three-parameter `PlainMemberFunctionObjectT` type, 24-byte layout, language-id/dialog construction, callback ownership/invocation/release, UID00046P result route, UID0004WH compiler-support child, allocation-failure behavior, no-entry/sibling evidence, rejected alternatives, and bounded source-name uncertainty.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/78`.
  - Summary/evidence: major UI responsibility, constructor/action/submit/destructor roles, companion appearance controls, and missing emitted-method caveat are documented; remaining work is detailed body reconstruction and resolving Wave3 materialization gaps.
- 2026-06-03 MCP verification and parent attachment:
  - What existed before: the class remained unassigned at `68/78`, with some behavior documented but no fresh verification for the omitted setter methods or destructor-thunk details.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md).
  - Summary/evidence: live IDA MCP lookup/caller/callee/xref/decompile/disassembly checks confirmed the old dialog method boundaries, constructor callers, color setter behavior, submit validation flow, vtable/singleton xrefs, and destructor adjustor thunks. C++ was blank in that pass because field layout, helper names, and exact original source shape still needed source-quality review.
- 2026-06-07 A009 documentation synchronization:
  - What existed before: the page described the singleton and vtable evidence but did not link the exact by-memory child pages or canonical singleton-slot page.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, explicit links to the core-method child, destructor/thunk island, vtable data, and singleton-slot pages.
  - Summary/evidence: existing project-documentation pages now tie the old dialog method range, lifecycle glue, generated vtable block, and static singleton storage together without adding unverified C++.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with stale generated-output wording and outdated C++ gate text.
  - After: `85/86`, with current IDA MCP evidence for method starts/sizes, caller/callee edges, vtable and singleton xrefs, boundary bytes, and the remaining field/helper-name work documented as source-quality risk.
  - Summary/evidence: the page cleared the documentation target without changing owner/emitter routing; later B004/B010 work added the first-draft C++.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Before: `85/86`, blank formal C++, and stale below-code-entry wording.
  - After: `88/89`, owner/emitter unchanged [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), first-draft declaration-level class C++ added, and stale generated names rejected.
  - Summary/evidence: incorporated B004's full source-quality reanalysis: direct constructor routes, old/new split, method inventory including color callbacks and secondary event bridge, field directions, control ids, submit/packet/reply flow, literal/global usage, singleton/vtable ownership, generated destructor/thunk policy, simroot caveats, and remaining below-95 naming issues.
- 2026-06-21 B007 face-selector route sync:
  - Score unchanged.
  - Summary/evidence: expanded selector caller documentation for control ids `6`/`7`, the corrected hair gender-bank helpers, direct face selector `+0x10c` gender writes, `+0x10d` face-color writes, constructor allocation/bounds/argument evidence, and preview reads from the face selector's gender-indexed face-id banks.
- 2026-06-21 B009 hair-selector route sync:
  - Score unchanged.
  - Summary/evidence: added the exact hair selector constructor allocation/bounds/arguments, `SetHairColorIndex` write to control id `6 +0x10d`, and preview frame-table read from `m_hairPartFrames[m_genderStyle][m_selectedHairSlot]`, replacing shorthand wording that could be read as passing a raw selected-hair index.
- 2026-06-21 B010 family split reconciliation:
  - Score unchanged.
  - Summary/evidence: recorded that the class and [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) child split remain the old-dialog source route after [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) were reclassified as non-emitting family/index pages.
