** TARGET-REPORT-UID:00003B **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00003B CreateUserDialogPane Class Source-Quality Report

Status: FINISHED  
Agent: B004  
Date: 2026-06-19  

## Target

- Target UID: [UID:00003B] `CreateUserDialogPane`
- Target path: `source-3/project-documentation/by-class/CreateUserDialogPane.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/00003B-CreateUserDialogPane-class-source-quality.md`
- Current target metadata checked: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000IJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IJ`, blank formal C++.
- Report-only pass: no target/support by-* documentation was edited, and `by-memory/-coverage-report.md` was not edited.

## Executive Recommendation

Update [UID:00003B] from stale below-threshold/no-C++ reasoning to current source-quality analysis:

- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000IJ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IJ`.
- Keep source ownership routed through [UID:0000IJ] `CreateUserDialogPane` / `NexusTK/login/CreateUserDialogPane.cpp`.
- Treat [UID:00003B] as a source-owned old `CreateUserDialogPane` class page, not an aggregate over all create-user dialogs.
- Add first-draft class-level C++ for the class declaration/source skeleton. The broad method-body C++ should be added on [UID:0002QT] `CreateUserDialogPaneCore` under the same emitter route; vtable data, singleton storage, adjustor thunks, and scalar deleting destructor wrappers should remain compiler/generated or data documentation rather than hand-authored class code.
- Preserve the old/new create-user split: old `CreateUserDialogPane` is active/reachable, `NewUserDialogPane2` is a sibling active variant, and `NewCreateUserDialogPane` remains a distinct retained/no-direct-constructor-route class unless later route evidence appears.

The current 85/85 gate is met for class-level C++ readiness. Remaining below-95 uncertainty is narrow and source-naming-specific: exact original names for the inherited dialog event interfaces, exact source name for the optional Nexonclub registration helper, exact semantic name of write-only field `this+0x26c`, and exact source name of fallback reply text at `word_61FF48`.

## Evidence Checked

Rules and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/goal.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`

Primary and support documentation:

- `source-3/project-documentation/by-class/CreateUserDialogPane.md`
- `source-3/project-documentation/by-file/CreateUserDialogPane.md`
- `source-3/project-documentation/by-file/CreateUserDialogs.md`
- `source-3/project-documentation/by-file/UserCreateAppearanceControls.md`
- `source-3/project-documentation/by-class/UserHairColorSelectListPane.md`
- `source-3/project-documentation/by-class/UserFaceColorSelectListPane.md`
- `source-3/project-documentation/by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md`
- `source-3/project-documentation/by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md`
- `source-3/project-documentation/by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md`
- `source-3/project-documentation/by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md`
- `source-3/project-documentation/by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md`
- `source-3/project-documentation/by-global/g_pLanguageMan.md`
- `source-3/project-documentation/by-global/g_pScreenPane.md`
- `source-3/project-documentation/by-global/g_packetSender.md`
- `source-3/project-documentation/by-global/g_pConfig.md`
- `source-3/project-documentation/by-memory/0x0060db20-0x0060db24.g_sharedEmptyWideStringLiteral.md`
- `source-3/project-documentation/by-memory/0x00613a18-0x00613a1c.DialogOkButtonString.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/by-class/-coverage-report.md`

Generated/source leads:

- `source-3/project-documentation/auto-generated/NexusTK/login/CreateUserDialogPane.cpp`
- `source-3/project-documentation/auto-generated/-ag-class-coverage.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/simroot_v2/class_CreateUserDialogPane.cpp`
- `source-3/project-documentation/tools/leaser/Agents/B010/reports/0001CR-CreateUserDialogVariants-implementation.md` as a lead only, rechecked against current docs and function evidence.

Raw function/decompiler evidence checked in `resources/exported_data/functions` for:

- `0x0052dd30` constructor
- `0x0052e770` body selector
- `0x0052e840` no-op
- `0x0052e850` male selector
- `0x0052e8c0` female selector
- `0x0052e930` hair color callback/setter
- `0x0052e950` face color callback/setter
- `0x0052e970` optional Nexonclub registration helper
- `0x0052ea50` callback into `this+0x27c` then packet sender
- `0x0052ea80` vtable command dispatcher
- `0x0052ecc0` base key-event wrapper
- `0x0052ecd0` secondary-vtable packet/reply event bridge
- `0x0052ed00` base show/open wrapper
- `0x0052ed10` no-op
- `0x0052ed80` submit validation
- `0x0052ef50` account/create-user packet encoder
- `0x0052f160` appearance/create-character packet encoder
- `0x0052f390` two-phase server reply handler
- `0x0052f710` singleton clear
- `0x0052f73b`, `0x0052f746` adjustor thunks
- `0x0052f800` scalar deleting destructor wrapper

Global/string evidence checked:

- `resources/exported_data/master_globals.json` for `off_61E318`: UTF-16 literal `"password must containt at least 1 number"` at `0x0061e318`, referenced by the create-user password validator and sibling password dialogs.
- Existing docs for `dword_67A750` as `g_pLanguageMan`, `dword_67A7CC` as `g_pScreenPane`, `dword_67A7EC` as `g_packetSender`, and `dword_67A7C8` as `g_pConfig`.
- Existing docs for `word_60DB20` as `g_sharedEmptyWideStringLiteral` and `off_613A18` as `DialogOkButtonString`.

## Source Routing and Ownership

[UID:00003B] should remain directly owned by [UID:0000IJ] `CreateUserDialogPane` and emitted through `NexusTK/login/CreateUserDialogPane.cpp`.

Positive ownership evidence:

- The constructor at `0x0052dd30` is directly called by main-menu create-user routes at `0x004f7a82` and `0x004f8ff8`.
- Constructor vtable stores install the `CreateUserDialogPane` primary, secondary, and tertiary vtables at `0x0061fe3c`, `0x0061fe9c`, and `0x0061fecc`.
- The singleton slot at `0x0069b890` is written by the constructor and cleared by the lifecycle cleanup path.
- [UID:0002QT] contains source-shaped method bodies specific to the old dialog: DLGNEW3 layout, gender/body/appearance selectors, password validation, packet encoders, and reply handling.
- The appearance color list controls call back into this class via `SetHairColorIndex` and `SetFaceColorIndex`; those setters are not owned by the control classes.

Rejected ownership alternatives:

- Reject [UID:0000IK] `CreateUserDialogs` as the direct emitter for [UID:00003B]. It is a useful umbrella/source-family page, but the old class has a concrete source file page [UID:0000IJ].
- Reject [UID:0001CR] `CreateUserDialogVariants` as the direct class owner. It is an aggregate over old/new variants and compiler lifecycle glue, not a source class.
- Reject `NexonclubRegistrationDialog` ownership for `0x0052e970` or `0x0052ea50`. That dialog is constructed as an optional child/callback consumer; the helper and callback capture a `CreateUserDialogPane` instance and serialize the old dialog's create-character packet.
- Reject `MainMenuPane` ownership for the constructor or methods. Main menu owns launchers such as `OpenCreateUserDialog_4F8FA0`, but the DLGNEW3 layout and packet/reply handlers are class-local dialog behavior.
- Reject `UserCreateAppearanceControls` ownership for `SetHairColorIndex` and `SetFaceColorIndex`. The selector panes call those functions, but the fields they update are owned by the old dialog's selected hair/face controls.

## Range, Split, and Generated-Code Policy

Relevant ranges:

- [UID:0002QT] `0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore` is the executable source-shaped core for old `CreateUserDialogPane`.
- [UID:0002QU] `0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland` is mixed compiler/lifecycle glue for all three create-user variants.
- [UID:0002SI] `0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData` is the old dialog's vtable data.
- [UID:0002B3] `0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot` is the old dialog singleton pointer storage.
- [UID:0001CR] `0x0052a540-0x0052f94c.CreateUserDialogVariants` should remain aggregate/split-index documentation and should not emit duplicate C++ for all variants.

Lifecycle policy:

- `0x0052f800` is a scalar deleting destructor wrapper for `CreateUserDialogPane`. It restores vtables, destroys `SimpleUString` at `this+0x27c`, clears the singleton, calls base teardown, and conditionally frees memory. It should document an ordinary source destructor relationship but should not be copied into source as a scalar deleting destructor body.
- `0x0052f73b` and `0x0052f746` are adjustor thunks into the old dialog scalar deleting destructor. They are compiler output.
- `0x0052f710` is the old dialog singleton clear helper; it is source-relevant as lifecycle evidence but belongs to the mixed destructor/thunk island, not the class C++ block.
- Vtable rows at `0x0061fe3c`, `0x0061fe9c`, and `0x0061fecc` should be documented as RTTI/vtable data and not hand-emitted.

## Class Layout and Field Names

Recommended field directions:

| Offset | Recommended source-facing name | Evidence and caveat |
|---:|---|---|
| inherited `+0x1fc` | inherited dialog control collection/manager | Constructor and methods pass `this+508` to control lookup helpers for control ids 1-18. Keep this inherited; do not add as a unique class field. |
| `+0x26c` | `m_initialAppearanceRoll` or `m_initialGenderRoll` with low confidence | Constructor writes `rand() % 2`. Current checked evidence found no reads in the old dialog method set. Do not claim it drives final gender/body state; document as write-only random/initial appearance roll unless later evidence finds a read. |
| `+0x270` | `m_bodyShapeIndex` | Initialized and updated by `SelectBodyShape`; serialized by `SendCreateCharacterRequest` into opcode `0x04`. |
| `+0x278` | `m_waitingForCharacterReply` | Initialized to zero, set to one after account/create-user success and immediately before `SendCreateCharacterRequest`; `HandleCreateUserReply` branches on it to distinguish first account reply from second character/appearance reply. Reject old/generated `m_previewDirty`. |
| `+0x279` | `m_isFemale` | `SelectMale` writes zero, `SelectFemale` writes one; preview update and packet sender consume it as gender/sex state. |
| `+0x27c` | `m_createUserExtraText` or `m_registrationText` | `SimpleUString` constructed in the constructor, filled by the `NexonclubRegistrationDialog` callback at `0x0052ea50`, serialized by `SendCreateCharacterRequest`. It is not the body-description label and not the username field. Exact original name remains below-95. |

Rejected field names:

- Reject `m_previewDirty` for `+0x278`; the byte is a two-phase reply state flag.
- Reject `m_descriptionText` for `+0x27c`; body description text is control id 14 and is set from localized strings in `SelectBodyShape`. The `SimpleUString` at `+0x27c` is callback-filled and packet-serialized.
- Reject final naming of `+0x26c` as a proven gender/body field. The constructor writes it, but checked old dialog methods do not read it. Keep a low-confidence write-only/random roll caveat.

## Method Names and Source Shapes

Recommended method inventory for [UID:00003B] and [UID:0002QT]:

| Address | Recommended name/signature direction | Evidence |
|---:|---|---|
| `0x0052dd30` | `CreateUserDialogPane::CreateUserDialogPane()` | Direct constructor route from main menu, DLGNEW3 assets, base `DialogPane(L"NE", -1, 4)` setup, singleton/vtable install, controls 1-18, `SimpleUString` at `+0x27c`. |
| `0x0052e770` | `void SelectBodyShape(short bodyShapeIndex)` | Command ids 10-13 call it; toggles body buttons, stores `+0x270`, updates body description control 14 via `g_pLanguageMan`. |
| `0x0052e840` | no-op/placeholder virtual | One-byte no-op; document but do not treat as meaningful source body. |
| `0x0052e850` | `int SelectMale()` or `void SelectMale()` | Sets `m_isFemale = 0`, toggles gender buttons 4/5, switches hair/face selector modes. Return value is ABI/live-register noise; source can be `void` if vtable/interface allows. |
| `0x0052e8c0` | `int SelectFemale()` or `void SelectFemale()` | Sets `m_isFemale = 1`, toggles gender buttons 4/5, switches hair/face selector modes. Return value is ABI/live-register noise; source can be `void` if vtable/interface allows. |
| `0x0052e930` | `unsigned char SetHairColorIndex(unsigned char colorIndex)` | Called by `UserHairColorSelectListPane`; writes selected color byte at hair selector `+0x10d` for control id 6. |
| `0x0052e950` | `unsigned char SetFaceColorIndex(unsigned char colorIndex)` | Called by `UserFaceColorSelectListPane`; writes selected color byte at face selector `+0x10d` for control id 7. |
| `0x0052e970` | `OpenNexonclubRegistrationOrSendCharacterRequest(void *context)` | No direct function xrefs checked; allocates `PlainMemberFunctionObject` targeting `0x0052ea50`, constructs `NexonclubRegistrationDialog`, falls back to `SendCreateCharacterRequest` when allocation/context path is absent. Treat as retained/optional helper. |
| `0x0052ea50` | `OnNexonclubRegistrationResult(const SimpleUString &text)` | Callback from `0x0052e970`; if non-empty, copies text into `m_createUserExtraText`, then calls `SendCreateCharacterRequest`. |
| `0x0052ea80` | `OnDialogAction(int commandId, int action)` | Primary vtable command dispatcher. Handles gender, hair/face preview refresh, body selection, submit, cancel, and preview direction. |
| `0x0052ecc0` | `OnKeyEvent(...)` base delegate | Secondary/virtual wrapper that delegates to base `DialogPane` key event behavior. Missing from current generated source. |
| `0x0052ecd0` | `OnCreateUserReplyEvent(...)` or `OnServerResponseEvent(...)` | Secondary-vtable bridge checks packet/event marker and calls `HandleCreateUserReply(this - 0xa0, packet)`. Missing from current generated source. |
| `0x0052ed00` | `OnDialogShow(...)` base delegate | Delegates to base `DialogPane` show/open behavior. Missing from current generated source. |
| `0x0052ed10` | no-op virtual/placeholder | One-byte no-op; document but do not over-name. |
| `0x0052ed80` | `SubmitCreateUser()` | Reads controls 1/2/3, validates password digit and password confirmation, focuses invalid controls, shows alert panes, creates screen dimmer, and calls `SendCreateAccountRequest`. |
| `0x0052ef50` | `static void SendCreateAccountRequest(const wchar_t *accountName, const wchar_t *password, const wchar_t *profileText)` | File-local helper, opcode `0x02`, length-prefixed MBCS strings, sends through `g_packetSender`; caller is `SubmitCreateUser`. |
| `0x0052f160` | `void SendCreateCharacterRequest()` | Serializes preview appearance/body/extra text as opcode `0x04`; creates dimmer if absent; sends through `g_packetSender`. |
| `0x0052f390` | `bool HandleCreateUserReply(const unsigned char *packet)` | Two-phase response handler keyed by `m_waitingForCharacterReply`; account success sends character request and caches username through `g_pConfig`; error paths focus username/password and show server messages. |
| `0x0052f800` | scalar deleting destructor wrapper for `~CreateUserDialogPane()` | Compiler-generated wrapper only; source declaration should be an ordinary virtual destructor. |

## Body, Color, Preview, and Selector Helpers

`SelectBodyShape` at `0x0052e770` is strongly recoverable:

- The selected body id is stored at `this+0x270`.
- Control ids 10-13 are body-shape buttons.
- The previously selected body button is toggled off and the new button is toggled on.
- Control id 14 is the body-description label.
- The body-description label is updated from `g_pLanguageMan` with a localized id derived from `bodyShapeIndex + 212`.

`SelectMale` and `SelectFemale` are strongly recoverable:

- Control ids 4 and 5 are gender buttons.
- `SelectMale` writes `m_isFemale = 0`; `SelectFemale` writes `m_isFemale = 1`.
- Both switch hair selector control 6 and face selector control 7 into gender-specific mode and force selector refresh/update.

Hair/face callbacks:

- `SetHairColorIndex` writes the color byte into the hair selector control id 6 at selector offset `+0x10d`.
- `SetFaceColorIndex` writes the color byte into the face selector control id 7 at selector offset `+0x10d`.
- Caller evidence from `UserHairColorSelectListPane` and `UserFaceColorSelectListPane` supports keeping these as dialog-owned methods, not control-owned helpers.

Preview routing:

- The preview control id is 18.
- `OnDialogAction` refreshes preview state with selected face index/color, hair index/color, and `m_isFemale`.
- Command id 17 advances/rotates the preview direction through the preview helper.
- `SendCreateCharacterRequest` snapshots the preview via the preview control and serializes the selected appearance fields plus `m_bodyShapeIndex` and `m_createUserExtraText`.

## Submit, Packet, and Reply Flow

`SubmitCreateUser` at `0x0052ed80`:

- Reads account/username control id 1 into a 16-wide-char buffer with 15-character limit.
- Reads password control id 2 and confirm password control id 3.
- Requires at least one digit in the password.
- On missing digit, focuses password control 2 and shows an alert with literal `off_61E318`, whose decoded text is `"password must containt at least 1 number"`; preserve the binary typo in evidence.
- On mismatch, focuses password control 2 and shows localized message id 90 from `g_pLanguageMan`.
- Uses `DialogOkButtonString` (`off_613A18`) for alert OK text.
- On success, creates a screen dimmer through `g_pScreenPane` and calls the file-local opcode `0x02` sender with `g_sharedEmptyWideStringLiteral` as the third string.

`SendCreateAccountRequest` at `0x0052ef50`:

- Source-facing form should be file-local/static, not a class virtual.
- Writes opcode `0x02`.
- Converts three wide strings to multibyte strings using `WideCharToMultiByte`.
- Writes length-prefixed username/account, password, and third string payloads.
- Sends through `g_packetSender`.

`SendCreateCharacterRequest` at `0x0052f160`:

- Creates an active screen dimmer when one is not already present.
- Pulls current appearance from preview control 18.
- Writes opcode `0x04`.
- Serializes preview appearance fields, a trailing zero byte, `m_bodyShapeIndex`, and a multibyte version of `m_createUserExtraText`.
- Sends through `g_packetSender`.

`HandleCreateUserReply` at `0x0052f390`:

- Uses `m_waitingForCharacterReply` at `+0x278` as the state split between account reply and character/appearance reply.
- First-stage success sets `m_waitingForCharacterReply = 1`, sends the character request, reads control id 1, and passes the account/username to the config/profile helper at `sub_48EB50(g_pConfig, Source)`.
- First-stage error closes any active dimmer, maps server error codes to username or password focus targets, widens server message bytes, and shows an alert when a message exists.
- Error codes 3, 4, 14, 16, 17, 18, 20, and 21 focus account/username control 1.
- Error codes 5, 6, 7, 8, 9, and 15 focus password control 2.
- Second-stage success closes dimmer, shows a server/fallback message, and closes the dialog.
- Second-stage error closes dimmer and shows a non-empty server message.
- `word_61FF48` is a fallback second-stage reply/success message. I did not find a safe decoded/source name in checked docs; recommend a tentative comment name such as `kDefaultCreateUserReplyText` until string recovery resolves it.

## Singleton and Vtable Ownership

Singleton:

- `dword_69B890` should be named/described as `g_pCreateUserDialogPane`.
- Constructor writes it to `this` on normal construction.
- Constructor fallback path writes zero.
- `0x0052f710` and the scalar deleting destructor path clear it.

Vtables:

- `0x0061fe3c` primary vtable: old `CreateUserDialogPane` primary interface; includes scalar deleting destructor and primary command dispatcher `0x0052ea80`.
- `0x0061fe9c` secondary vtable: includes adjustor thunk `0x0052f73b` and wrappers/bridges including `0x0052ed00`, `0x0052ecc0`, and `0x0052ecd0`.
- `0x0061fecc` tertiary vtable: includes adjustor thunk `0x0052f746`.
- Vtable install xrefs are in the constructor at `0x0052dda2`, `0x0052dda8`, `0x0052ddb2` and fallback/reinstall paths near `0x0052e6f9`, `0x0052e6ff`, `0x0052e709`.
- Destructor wrapper xrefs reinstall these vtables at `0x0052f80c`, `0x0052f812`, and `0x0052f81c`.

Recommendation: keep vtable data under [UID:0002SI] and class method names on [UID:00003B]/[UID:0002QT]; do not hand-write vtable arrays in C++.

## Old-vs-New Create-User Split

The old `CreateUserDialogPane` source split is still defensible and should be explicit:

- Old `CreateUserDialogPane` constructor at `0x0052dd30` has direct construction routes at `0x004f7a82` and `0x004f8ff8`.
- `NewUserDialogPane2` is a separate active sibling variant with direct construction routes in the same main-menu cluster.
- `NewCreateUserDialogPane` remains a distinct sibling variant with no direct constructor xrefs in current docs/evidence; do not fold it into old `CreateUserDialogPane`.
- [UID:0001CR] is a variant aggregate/index and should not own one monolithic source body for all three variants.
- The retained launcher `OpenCreateUserDialog_4F8FA0` belongs to main-menu/startup flow, not to [UID:00003B].

## Current Generated Output Gaps

Current `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` is marker-only for UIDs `00003B`, `0002QT`, `0002SI`, and `0002B3`. It does not yet contain useful first-draft source.

`source-3/simroot_v2/class_CreateUserDialogPane.cpp` is useful only as a lead. It has broad shape but remains unsuitable as authoritative source because it:

- Uses modern/generated style rather than plausible mid-2000s project style.
- Omits active generated methods `SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, `OnDialogShow`, and the secondary reply-event bridge.
- Uses weak/generated field names such as `m_previewDirty` and `m_descriptionText` that contradict current packet/reply and callback evidence.
- Does not correctly separate scalar deleting destructor/vtable mechanics from source code.

## First-Draft C++ Recommendation

Class-level C++ is ready for [UID:00003B] as a declaration/source skeleton. Full method-body C++ should be placed on [UID:0002QT] during implementation, because [UID:00003B] is a class page and [UID:0002QT] carries the executable method range.

Recommended class C++ draft for [UID:00003B]:

```cpp
class CreateUserDialogPane : public DialogPane
{
public:
    CreateUserDialogPane();
    virtual ~CreateUserDialogPane();

    void SelectBodyShape(short bodyShapeIndex);
    void SelectMale();
    void SelectFemale();
    unsigned char SetHairColorIndex(unsigned char colorIndex);
    unsigned char SetFaceColorIndex(unsigned char colorIndex);

protected:
    void OpenNexonclubRegistrationOrSendCharacterRequest(void *context);
    void OnNexonclubRegistrationResult(const SimpleUString &text);

    virtual void OnDialogAction(int commandId, int action);
    virtual bool OnKeyEvent(unsigned char *event);
    virtual bool OnCreateUserReplyEvent(void *event);
    virtual bool OnDialogShow(int reason);
    virtual void OnUnusedDialogNotify();

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

    static void SendCreateAccountRequest(const wchar_t *accountName,
                                         const wchar_t *password,
                                         const wchar_t *profileText);

private:
    int m_initialAppearanceRoll;
    int m_bodyShapeIndex;
    unsigned char m_waitingForCharacterReply;
    unsigned char m_isFemale;
    SimpleUString m_createUserExtraText;
};
```

Implementation caveats for this draft:

- The exact inherited base/interface list is still below-95 because the secondary and tertiary vtables imply additional inherited interfaces, but the current class page can still emit a useful first-draft source declaration.
- `OnDialogAction`, `OnKeyEvent`, `OnDialogShow`, and `OnCreateUserReplyEvent` names should be adapted to the project's established `DialogPane` virtual spelling if support docs already define exact names.
- If implementers prefer source-return fidelity for `SelectMale`, `SelectFemale`, or color setters, preserve the existing decompiled return type. The strongest source-style inference is that gender selectors are `void` and color setters may return the stored color byte because the ABI leaves it live.
- The `m_initialAppearanceRoll` field must carry a low-confidence/write-only comment; do not present it as a proven runtime setting.

## Recommended Exact Implementation Checklist

When the supervisor accepts this report for implementation, update [UID:00003B]:

1. Change target metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:0000IJ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IJ`.
2. Replace the stale no-C++/below-entry-gate rationale with current 85/85 gate analysis:
   - source ownership through [UID:0000IJ],
   - direct constructor route at `0x004f7a82`/`0x004f8ff8`,
   - executable method range through [UID:0002QT],
   - current first-draft class C++ readiness,
   - remaining below-95 naming caveats.
3. Add the class-level C++ skeleton above or an equivalent project-style declaration using existing project virtual names if known.
4. Add/update class method inventory with the method names in this report, especially missing active generated methods:
   - `SetHairColorIndex`
   - `SetFaceColorIndex`
   - `OnKeyEvent`
   - `OnDialogShow`
   - `OnCreateUserReplyEvent` / server reply bridge
5. Replace field names:
   - `+0x270` -> `m_bodyShapeIndex`
   - `+0x278` -> `m_waitingForCharacterReply`
   - `+0x279` -> `m_isFemale`
   - `+0x27c` -> `m_createUserExtraText` or `m_registrationText`
   - `+0x26c` -> low-confidence `m_initialAppearanceRoll` / write-only random roll caveat.
6. Document selector/control ids:
   - 1 account/username edit,
   - 2 password edit,
   - 3 confirmation edit,
   - 4 male,
   - 5 female,
   - 6 hair selector,
   - 7 face selector,
   - 8/9 selector scroll/action,
   - 10-13 body shape buttons,
   - 14 body description label,
   - 15 submit,
   - 16 cancel,
   - 17 preview direction,
   - 18 preview pane.
7. Document submit/packet/reply flow:
   - password digit check uses literal at `off_61E318`,
   - mismatch uses localized language id 90,
   - opcode `0x02` account/create-user request,
   - opcode `0x04` appearance/create-character request,
   - `m_waitingForCharacterReply` splits the two server replies,
   - `g_pConfig` caches the account/username after first-stage success.
8. Document singleton/vtable ownership:
   - `dword_69B890` = `g_pCreateUserDialogPane`,
   - vtables at `0x0061fe3c`, `0x0061fe9c`, `0x0061fecc`,
   - scalar deleting destructor and adjustor thunks are compiler output.
9. Reject old/generated field/helper names that contradict evidence:
   - do not keep `m_previewDirty` for `+0x278`,
   - do not keep `m_descriptionText` for `+0x27c`,
   - do not label `0x0052ef50` as a class virtual.

Recommended support updates if accepted:

1. `by-file/CreateUserDialogPane.md`
   - Update score if desired to track target, e.g. `COMPLETION:88`, `CONFIDENCE:89`.
   - Incorporate the resolved method inventory and global names.
   - Explicitly state generated source is currently marker-only and should receive class/child C++ after implementation.
2. `by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md`
   - Update score to about `COMPLETION:88`, `CONFIDENCE:89`.
   - Add first-draft method-body C++ or at least exact method signatures and source-shape prose from this report.
   - Replace stale raw names for packet helpers and reply handler.
3. `by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md`
   - Keep/report as compiler lifecycle island and source-reference only; do not emit handwritten C++ for the scalar deleting destructors/thunks.
4. `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md`
   - Add/confirm slot names for `OnDialogAction`, `OnKeyEvent`, `OnCreateUserReplyEvent`, and `OnDialogShow`.
5. `by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md`
   - Confirm preferred name `g_pCreateUserDialogPane` and constructor/destructor xrefs.
6. `by-file/CreateUserDialogs.md`
   - Clarify old/new split and retained/no-direct-route `NewCreateUserDialogPane` status.
7. `by-file/UserCreateAppearanceControls.md`, `by-class/UserHairColorSelectListPane.md`, and `by-class/UserFaceColorSelectListPane.md`
   - Only update if they still omit the callback role of `SetHairColorIndex` and `SetFaceColorIndex`.
8. Global/support docs:
   - Ensure `off_61E318` is not treated as unknown if a string/global page exists or is later created.
   - Ensure `word_61FF48` remains a fallback reply text with unresolved exact name.

## Score and Metadata Rationale

Recommended target score: `88/89`.

Why not lower:

- Direct constructor route, vtable installs, singleton ownership, and source file route are strong.
- Most class fields and method roles are resolved.
- Packet opcodes, global send path, and two-phase reply behavior are source-shaped and stable.
- Class-level C++ is useful and no longer blocked by the old 90/90+ policy.

Why not 95+:

- Exact source names for inherited virtual interfaces remain inferred.
- `0x0052e970` has no direct function xrefs and remains a retained/optional registration-helper inference.
- `this+0x26c` is write-only in checked evidence.
- `word_61FF48` fallback text/source name remains unresolved.
- The class declaration's exact inherited interface list may need adjustment once the secondary/tertiary vtable family is named.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report pass. The following rows are for supervisor-owned application if the implementation callback changes the corresponding docs.

Recommended replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) : reconstructable : 88% : strong : B004 source-quality reanalysis resolves old DLGNEW3 create-user class source shape under [UID:0000IJ] CreateUserDialogPane, current 85/85 emitter gate, direct constructor route at `0x004f7a82`/`0x004f8ff8`, method inventory through [UID:0002QT], field directions `m_bodyShapeIndex` at `+0x270`, `m_waitingForCharacterReply` at `+0x278`, `m_isFemale` at `+0x279`, `m_createUserExtraText` at `+0x27c`, write-only `+0x26c` caveat, body/gender/color selector names, submit/packet/reply flow through `g_pLanguageMan`, `g_pScreenPane`, `g_packetSender`, `g_pConfig`, `DialogOkButtonString`, vtable/singleton ownership at `0x0061fe3c`/`0x0069b890`, old/new create-user split, compiler-generated destructor/thunk policy, generated-output omissions, and class-declaration first-draft C++ readiness.
```

Recommended replacement row for `by-memory/-coverage-report.md` if [UID:0002QT] support is updated:

```markdown
        - [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md) 0x0052dd30-0x0052f6e5 | executable child | CreateUserDialogPaneCore : reconstructable : 88% : strong : B004 source-quality reanalysis resolves the old DLGNEW3 CreateUserDialogPane core method names and source shape: constructor, SelectBodyShape, SelectMale/Female, SetHairColorIndex/SetFaceColorIndex callbacks, OnDialogAction, base OnKeyEvent/OnDialogShow delegates, secondary reply-event bridge, SubmitCreateUser validation, file-local SendCreateAccountRequest opcode `0x02`, SendCreateCharacterRequest opcode `0x04`, HandleCreateUserReply two-phase state, global aliases `g_pLanguageMan`, `g_pScreenPane`, `g_packetSender`, `g_pConfig`, `DialogOkButtonString`, and field directions `+0x270/+0x278/+0x279/+0x27c`; first-draft method C++ is ready pending implementation callback.
```

Recommended replacement row for `by-memory/-coverage-report.md` if [UID:0002QU] support is updated:

```markdown
        - [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) 0x0052f710-0x0052f94c | compiler/lifecycle child | CreateUserDialogDestructorAndThunkIsland : ignored/non-emitting : 88% : strong : B004 confirms this is a mixed create-user variant destructor/thunk island: `0x0052f710` clears `g_pCreateUserDialogPane`, `0x0052f720` and `0x0052f730` clear sibling singleton slots, `0x0052f73b/0x0052f746` are CreateUserDialogPane adjustor thunks, `0x0052f800` is the old dialog scalar deleting destructor wrapper, and the remaining rows belong to NewCreateUserDialogPane/NewUserDialogPane2 compiler lifecycle output; source docs should reference ordinary destructors but not emit handwritten scalar-wrapper C++.
```

## Expected Validation Commands

Run from `source-3/project-documentation` after implementation, for every touched file:

> Executable block R001 was removed from this report and preserved verbatim in [00003B-CreateUserDialogPane-class-source-quality-removed.md](00003B-CreateUserDialogPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If a formal C++ block is added to [UID:00003B] or [UID:0002QT], run the repository's normal generated-output/rescore workflow and report whether `auto-generated/NexusTK/login/CreateUserDialogPane.cpp`, class coverage, memory coverage, or stats files changed. No validation was run during this report-only pass.

## IDA Rename, Type, and Comment Recommendations

Function names:

- `sub_52DD30` -> `CreateUserDialogPane::CreateUserDialogPane`
- `sub_52E770` -> `CreateUserDialogPane::SelectBodyShape`
- `sub_52E840` -> `CreateUserDialogPane::NoOpDialogNotify` or leave as no-op with comment
- `sub_52E850` -> `CreateUserDialogPane::SelectMale`
- `sub_52E8C0` -> `CreateUserDialogPane::SelectFemale`
- `sub_52E930` -> `CreateUserDialogPane::SetHairColorIndex`
- `sub_52E950` -> `CreateUserDialogPane::SetFaceColorIndex`
- `sub_52E970` -> `CreateUserDialogPane::OpenNexonclubRegistrationOrSendCharacterRequest` with lower confidence/no-direct-xref comment
- `sub_52EA50` -> `CreateUserDialogPane::OnNexonclubRegistrationResult`
- `sub_52EA80` -> `CreateUserDialogPane::OnDialogAction`
- `sub_52ECC0` -> `CreateUserDialogPane::OnKeyEvent`
- `sub_52ECD0` -> `CreateUserDialogPane::OnCreateUserReplyEvent`
- `sub_52ED00` -> `CreateUserDialogPane::OnDialogShow`
- `nullsub_44` at `0x0052ed10` -> no-op virtual placeholder
- `sub_52ED80` -> `CreateUserDialogPane::SubmitCreateUser`
- `sub_52EF50` -> `SendCreateAccountRequest`
- `sub_52F160` -> `CreateUserDialogPane::SendCreateCharacterRequest`
- `sub_52F390` -> `CreateUserDialogPane::HandleCreateUserReply`
- `sub_52F710` -> `ClearCreateUserDialogPaneSingleton`
- `sub_52F73B`, `sub_52F746` -> adjustor thunks to `CreateUserDialogPane` scalar deleting destructor
- `sub_52F800` -> `CreateUserDialogPane::scalar_deleting_destructor`

Global names/comments:

- `dword_69B890` -> `g_pCreateUserDialogPane`
- `dword_67A750` -> `g_pLanguageMan`
- `dword_67A7CC` -> `g_pScreenPane`
- `dword_67A7EC` -> `g_packetSender`
- `dword_67A7C8` -> `g_pConfig`
- `word_60DB20` -> `g_sharedEmptyWideStringLiteral`
- `off_613A18` -> `DialogOkButtonString`
- `off_61E318` -> `kPasswordMustContainDigitText`; comment exact binary text `"password must containt at least 1 number"`.
- `word_61FF48` -> tentative `kDefaultCreateUserReplyText`; keep unresolved-string caveat.

Field comments:

- `this+0x26c`: write-only random/initial appearance roll in checked evidence.
- `this+0x270`: `m_bodyShapeIndex`.
- `this+0x278`: `m_waitingForCharacterReply`.
- `this+0x279`: `m_isFemale`.
- `this+0x27c`: `SimpleUString m_createUserExtraText` / optional registration text serialized in opcode `0x04`.

## Remaining Issues and Impact

- Exact original source name for `0x0052e970` is not safely recoverable because no direct function xrefs were found. Best supported direction is optional Nexonclub registration/dialog callback helper; impact is naming only, not source ownership.
- Exact source name for `this+0x26c` is not safely recoverable because current checked old dialog methods only show a constructor write. Impact is a field-name caveat; it does not block class C++ or packet/reply recovery.
- Exact decoded/source name for `word_61FF48` was not found in checked docs. Impact is fallback-message naming only.
- Exact inherited interface names for the secondary and tertiary vtables remain below-95. Impact is class declaration base/interface spelling; vtable ownership and method routing are still strong.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00003B-CreateUserDialogPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00003B"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00003B-CreateUserDialogPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00003B-CreateUserDialogPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00003B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
