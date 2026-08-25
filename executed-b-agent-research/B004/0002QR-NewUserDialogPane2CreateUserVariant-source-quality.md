** TARGET-REPORT-UID:0002QR **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002QR] NewUserDialogPane2CreateUserVariant Source-Quality Report

Agent: B004  
Assignment: `B004-report-0002QR-new-user-dialog-pane2-create-user-variant-source-quality-20260626`  
Target: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](../../../../../by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)  
Mode: report-only research; no by-* documentation edits made in this pass.

## Executive Decision

[UID:0002QR] should not remain a single reconstructable/emitting memory page with one aggregate C++ block. It is a mixed executable island: one constructor, one constructor-adjacent complete-destructor body that IDA does not model as a function, selector helpers, a command dispatcher plus its switch jump table, event/reply bridge functions, two unmodeled no-xref helper bodies, a file-local account-packet helper, a create-character payload builder, and a two-phase reply handler. The current formal C++ block only sketches the submit/account/payload/reply path and is materially wrong for the create-character payload and reply handler.

Recommended treatment: convert [UID:0002QR] into a non-emitting split/index page under [UID:0000LW][NewUserDialogPane2](../../../../../by-file/NewUserDialogPane2.md), then create exact child pages for the source-authored methods, file-local helper, compiler/lifecycle raw body, jump-table-bearing dispatcher, and unmodeled raw helper islands. Child pages should carry either formal C++ blocks or target-specific no-code proofs; the parent C++ block should be blank.

## Live IDA MCP Evidence

MCP was available and used. `idb_list` returned one active session, `80de0a67`, worker PID `26892`, `is_analyzing:false`. On 2026-06-26 at `05:06:33-04:00`, `server_health` on database `80de0a67` returned `status:"ok"`, `module:"NexusTK.exe"`, `idb_path:"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"`, `imagebase:"0x400000"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.

`lookup_funcs` confirms the currently documented modeled functions inside `0x0052a540-0x0052c325`: constructor-like `sub_52A540` size `0xb07` / 2823 bytes (Verified with int_convert.py), selector helpers through `sub_52B5C0`, command dispatcher `sub_52B760`, event/reply bridge helpers, submit validator `sub_52B9F0` size `0x1cc` / 460 bytes (Verified with int_convert.py), file-local packet helper `sub_52BBC0` size `0x205` / 517 bytes (Verified with int_convert.py), payload builder `sub_52BDD0` size `0x1f2` / 498 bytes (Verified with int_convert.py), and reply handler `sub_52BFD0` size `0x355` / 853 bytes (Verified with int_convert.py). The whole `0002QR` range is `0x1de5` / 7653 bytes (Verified with int_convert.py).

Additional live evidence found important content that the current page does not model:

- `insn_query 0x0052b047-0x0052b090` shows alignment at `0x0052b047`, then an IDA-unmodeled destructor-shaped body at `0x0052b050-0x0052b08a`: it writes `NewUserDialogPane2` vtables at `this+0`, `+0xa0`, and `+0xa4`, destroys the `SimpleUString`-like member at `+0x27c`, clears `g_pNewUserDialogPane2` / `0x0069b4a4`, and tail-jumps to the base destructor. `lookup_funcs` reports `0x0052b050` as "Not a function", and `xrefs_to` / direct VA byte-pattern search found no incoming route.
- `insn_query 0x0052b843-0x0052b890` identifies `0x0052b844-0x0052b88c` as the jump table for `sub_52B760`. It belongs with the command-dispatch child, not with padding.
- `insn_query 0x0052b94a-0x0052b9f0` shows two IDA-unmodeled code bodies: `0x0052b950-0x0052b981` clears controls `0x0c` and `0x0d`; `0x0052b990-0x0052b9ed` clears controls `0x0e` through `0x11`. `lookup_funcs`, `xrefs_to`, and VA byte-pattern search found no incoming route for `0x0052b950` or `0x0052b990`.
- `xrefs_to 0x0052a540` returns the two constructor callers at `0x004f7ad0` and `0x004f9041`. `xrefs_to` confirms internal edges `0x0052b77c -> 0x0052b9f0`, `0x0052bbb2 -> 0x0052bbc0`, `0x0052b70c` / `0x0052b752` / `0x0052c126 -> 0x0052bdd0`, and `0x0052b931 -> 0x0052bfd0`.

## Current Documentation Problems

The current parent page metadata says `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00009E`, `EMITTER_UIDS:00009E`, `Nested:4`, and carries a single formal C++ block. That is not source-quality safe for this range.

Specific problems:

- The formal block omits the constructor, selector helpers, prompt/callback helper, command dispatcher, event bridge, packet-event bridge, trivial virtual forwarder, constructor-adjacent destructor body, dispatcher jump table, and the two raw helper bodies.
- `SendCreateCharacterRequest` is not the simple field write shown in the current block. Live decompilation of `0x0052bdd0` shows a guard/dimmer path through `unk_69AE08`, reads the shape control selected by `this+628`, calls the shape extraction helper, writes opcode `0x04`, serializes fixed value `0xc8`, selector fields at `this+620` / `this+624`, and converts the string at `this+636` before sending through `g_packetSender`.
- `HandleCreateUserReply` does not use `packet[0]` as the result byte. Decompilation of `0x0052bfd0` uses the status at `packet+1`, message length/data fields at later offsets, the two-phase flag at `this+632`, calls `0x0052bdd0` on first-stage success, and updates state through `sub_48EB50(dword_67A7C8, Source)`.
- `0x0052bbc0` is a `__stdcall` file-local helper, not a class member. Its direct semantic owner is [UID:0000LW][NewUserDialogPane2](../../../../../by-file/NewUserDialogPane2.md), while most surrounding children are class methods under [UID:00009E][NewUserDialogPane2](../../../../../by-class/NewUserDialogPane2.md). This mixed ownership is another reason the parent should be a non-emitting file-level split index.
- The current `Nested:4` does not reflect the real internal source split. The implementation should create 21 exact child pages and set the parent `Nested` count accordingly.

## Score Reanalysis

The current `88/88` target score should not remain unchanged after this pass. That score was reasonable for the B010 state because B010 had no live MCP in its session and only inserted a broad first-draft formal block. The 2026-06-26 live pass proves the parent block is unsafe and supplies an implementation-ready repair: exact child split, corrected source/file ownership for the file-local account-packet helper, target-specific no-code proofs for raw islands, corrected payload/reply evidence, and a required vtable-tail support child.

Recommended parent score after implementation is `89/90`: completion rises because the parent becomes a correct non-emitting split/index with the real 21-child inventory and no-code proof instead of an incorrect aggregate emitter; confidence rises because the split is backed by live `lookup_funcs`, `xrefs_to`, `decompile`, `insn_query`, `find_bytes`, and boundary-byte evidence. It should not be raised higher in this callback because the parent is an index, not the final method-body owner, and several child pages intentionally carry no-code proofs instead of source bodies. That is a source-split disposition, not a "names are inferred" excuse.

## Naming And Source-Shape Decisions

- `+0x1fc` is `m_childControls`: every edit/control access in the submit, selector, packet, and raw-clear helpers goes through this inherited child lookup container. Rejected alternative: leaving it as `this[127]` or "control lookup" only; implementation needs a source-facing field.
- `+0x26c` is `m_selectedNation`: controls `12/13` select two alternatives, constructor resources include `NNATION.EPD`, language ids are `210/211`, and the create-character packet serializes the value plus one. Rejected alternatives: `m_selectedGenderOrNation` is too vague, and `m_selectedGender` conflicts with the separate male/female mode helpers at `0x0052b530`/`0x0052b5c0`.
- `+0x270` is `m_selectedTotem`: controls `14-17` form the four-way selector and language ids `212-215` match the totem-style role already used in the class/file pages. Rejected alternative: `m_selectedSecondOption`, which preserves no domain meaning.
- `+0x274` is `m_selectedShapeSlot`: it is an index `0-3` used to choose child controls `8-11`; it is not directly serialized into the create-character packet. Rejected alternative: `m_selectedShapeBase`, because live `0x0052bdd0` reads the selected child and serializes shape bytes from that child instead.
- `+0x278` remains `m_waitingForCharacterReply`: first-stage success sets it before sending the character packet and second-stage handling branches on it. Rejected alternative: `m_createCharacterPhase`, which is less consistent with the existing class declaration and hides that the flag means "waiting for second reply."
- `+0x27c` remains `m_createdUserName`: constructor initializes it as the local wide string field, `0x0052b730` stores prompt text into it, and `0x0052bdd0` serializes it. Rejected alternative: `m_accountName`, because reply handling also copies edit-control `1` into separate global account/user-name state.
- Use file-local `SendCreateAccountRequest` for `0x0052bbc0`. Rejected alternatives: making it a `NewUserDialogPane2` member, which contradicts the `__stdcall` helper shape, or naming it `SendCreateUserAccountRequest`, which adds no observed source distinction.
- Use `NewUserDialogPane2::SendCreateCharacterRequest` for `0x0052bdd0` and `NewUserDialogPane2::HandleCreateUserReply` for `0x0052bfd0`. Rejected alternative: renaming the reply method to `OnCreateUserReply`; existing class/support docs already use `HandleCreateUserReply`, and the bridge at `0x0052b910` can be documented as the event/packet hook that calls it.
- Use `DecodeCreateUserReplyMessage` and `ShowCreateUserReplyText` as the local reply-message helper names in the formal reply child. Rejected alternative: keeping packet text extraction inline in the handler; the observed `packet+2` length and `packet+3` MBCS text payload are clear enough to name the operation. Use `IsCreateUserNameReplyError` and `IsCreateUserPasswordReplyError` for the focus-routing result-code groups. Use `g_newUserDialogCreatedAccountName` for `dword_67A7C8`; first-phase success copies edit-control `1` there through `sub_48EB50`, so `g_accountNameScratch` is too vague and `g_loginUserName` would overclaim a post-dialog login role. Use `g_createUserScreenDimmer` for `unk_69AE08` and `kCreateUserDefaultProfileText` for `word_60DB20` in the formal blocks; those names express the observed dimmer lifetime and fixed third account-request string without leaving global placeholders in the recommended C++.

## Recommended Parent Update

For `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md`:

- Keep UID `0002QR` and the current filename.
- Change to `COMPLETION:89`, `CONFIDENCE:90`.
- Change `CANONICAL_OWNER` to `0000LW` because the range is a source-file split/index containing class methods plus a file-local packet helper and raw compiler/lifecycle/source helper islands.
- Change `RECONSTRUCTABLE:FALSE`.
- Clear `EMITTER_UIDS`.
- Clear the formal `RECONSTRUCTION_CPP` block.
- Change `Nested` to `21`.
- Replace the summary with: "Non-emitting NewUserDialogPane2.cpp split index for constructor, selector, command/event, submit, account-packet, create-character, reply, raw helper, and lifecycle-adjacent children; exact child pages carry source C++ or no-code proofs."
- Add a "2026-06-26 B004 Source-Quality Reanalysis" section recording the live MCP session, exact child split, hidden raw islands, jump-table treatment, and why the current aggregate code is superseded.

Parent no-code proof to place on the page:

> Formal C++ is intentionally blank for this aggregate. The range contains 18 modeled functions, one IDA-unmodeled complete-destructor body, one command jump table, two IDA-unmodeled no-xref helper bodies, and mixed class/file-local ownership. Emitting one C++ block here would duplicate or conflate child methods and would preserve the current incorrect payload/reply skeleton. Exact child pages carry the reconstructable source where safe; compiler/lifecycle and no-route raw islands are documented as non-emitting evidence.

## Exact Child Pages To Create

The child page filenames below are the recommended implementation paths. Validator-assigned UIDs should be accepted during implementation.

| Child path | Recommended metadata | Formal C++ disposition |
| --- | --- | --- |
| `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b050-0x0052b08a.NewUserDialogPane2CompleteDestructorBody.md` | `86/88`, owner `00009E`, reconstructable false, emitter blank | Blank with no-code proof: IDA-unmodeled destructor-shaped lifecycle body, no xrefs/pointer route, source should use ordinary destructor declaration/body policy rather than hand-emitting this raw island. |
| `by-memory/0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b310-0x0052b395.NewUserDialogPane2SelectNation.md` | `88/90`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md` | `88/90`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b470-0x0052b52c.NewUserDialogPane2SelectShapeSlot.md` | `88/90`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b650-0x0052b724.NewUserDialogPane2PromptCreateCharacterName.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2ApplyCreateCharacterName.md` | `88/90`, owner/emitter `00009E`, reconstructable true | Exact formal `RECONSTRUCTION_CPP CODE` marker block below. |
| `by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnCommand.md` | `88/90`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below; include the `0x0052b844-0x0052b88c` jump table in this child. |
| `by-memory/0x0052b890-0x0052b910.NewUserDialogPane2HandleShapeKeyEvent.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b910-0x0052b936.NewUserDialogPane2HandleCreateUserPacketEvent.md` | `87/89`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b940-0x0052b949.NewUserDialogPane2ForwardDialogNotify.md` | `86/88`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052b950-0x0052b981.NewUserDialogPane2ClearGenderSelectionButtonsRaw.md` | `84/86`, owner `00009E`, reconstructable false, emitter blank | Blank no-code proof: real raw code body with no function record, no xrefs, and no pointer encodings; document under current no-route helper evidence. |
| `by-memory/0x0052b990-0x0052b9ed.NewUserDialogPane2ClearTotemSelectionButtonsRaw.md` | `84/86`, owner `00009E`, reconstructable false, emitter blank | Blank no-code proof matching the gender-clear raw child. |
| `by-memory/0x0052b9f0-0x0052bbbc.NewUserDialogPane2SubmitCreateUser.md` | `89/90`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052bbc0-0x0052bdc5.NewUserDialogPane2SendCreateAccountRequest.md` | `88/90`, owner/emitter `0000LW`, reconstructable true | Exact formal `RECONSTRUCTION_CPP CODE` marker block below. Document that `PacketBuffer` and method names are source-facing wrappers for the observed `sub_575380` / `sub_516220` / `sub_574BB0` path. It must not be a class member. |
| `by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md` | `89/90`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |
| `by-memory/0x0052bfd0-0x0052c325.NewUserDialogPane2HandleCreateUserReply.md` | `89/90`, owner/emitter `00009E`, reconstructable true | Exact formal first-draft C++ marker block below. |

Only three proposed code-range children stay blank: the IDA-unmodeled complete-destructor body and the two no-xref raw selector-clear bodies. They are non-emitting, reconstructable-false evidence pages with negative route proof. Every ordinary source-authored child with `RECONSTRUCTABLE:TRUE` and nonblank `EMITTER_UIDS` has formal first-draft `RECONSTRUCTION_CPP CODE` content below.

## Formal C++ Blocks For Reconstructable Children

The following blocks are the exact formal `RECONSTRUCTION_CPP CODE` content recommended for the source-authored child pages. The names are the implementation names recommended by this report, not placeholders. They use source-facing wrappers for observed UI, packet-buffer, alert, and child-control operations so the child pages are not left blank for ordinary helper/type-name uncertainty.

### Formal C++ For `0x0052a540-0x0052b047`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewUserDialogPane2::NewUserDialogPane2()
    : DialogPane(L"NE", -1, true),
      m_selectedNation(0),
      m_selectedTotem(0),
      m_selectedShapeSlot(0),
      m_waitingForCharacterReply(false)
{
    g_pNewUserDialogPane2 = this;
    m_createdUserName.clear();

    srand((unsigned)_time64(0));

    LoadDialogBackground(L"DLGNEW02.EPD");
    CreateAccountEditControls();
    CreateShapeSelectControls(L"DIREC.EPD");
    CreateNationButtons(L"NNATION.EPD");
    CreateTotemButtons(L"NNATION.EPD", L"NPAL3.PAL");
    CreateCreateUserCommandButtons();

    m_selectedShapeSlot = rand() % 4;
    m_selectedNation = rand() % 2;
    m_selectedTotem = rand() % 4;

    if ((rand() & 1) != 0) {
        SelectFemaleMode();
    } else {
        SelectMaleMode();
    }

    SelectShapeSlot(m_selectedShapeSlot);
    SelectNation(m_selectedNation);
    SelectTotem(m_selectedTotem);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b090-0x0052b1cb`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::ShiftShapesLeft()
{
    UserShapeSelectControlPane *controls[4];

    for (int i = 0; i < 4; ++i) {
        controls[i] = GetShapeSelectControl(8 + i);
    }

    if (m_selectedShapeSlot > 0) {
        SelectShapeSlot(m_selectedShapeSlot - 1);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        controls[i]->ShiftShapeLeft();
    }

    SelectShapeSlot(0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b1d0-0x0052b30d`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::ShiftShapesRight()
{
    UserShapeSelectControlPane *controls[4];

    for (int i = 0; i < 4; ++i) {
        controls[i] = GetShapeSelectControl(8 + i);
    }

    if (m_selectedShapeSlot < 3) {
        SelectShapeSlot(m_selectedShapeSlot + 1);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        controls[i]->ShiftShapeRight();
    }

    SelectShapeSlot(3);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b310-0x0052b395`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::SelectNation(int nation)
{
    if (nation < 0) {
        nation = 0;
    } else if (nation > 1) {
        nation = 1;
    }

    m_selectedNation = nation;
    SetChildButtonChecked(12, nation == 0);
    SetChildButtonChecked(13, nation == 1);
    SetCreateUserDescriptionText(g_pLanguageMan->GetString(210 + nation));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b3a0-0x0052b462`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::SelectTotem(int totem)
{
    if (totem < 0) {
        totem = 0;
    } else if (totem > 3) {
        totem = 3;
    }

    m_selectedTotem = totem;

    for (int i = 0; i < 4; ++i) {
        SetChildButtonChecked(14 + i, i == totem);
    }

    SetCreateUserDescriptionText(g_pLanguageMan->GetString(212 + totem));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b470-0x0052b52c`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::SelectShapeSlot(int slot)
{
    if (slot < 0) {
        slot = 0;
    } else if (slot > 3) {
        slot = 3;
    }

    m_selectedShapeSlot = slot;

    for (int i = 0; i < 4; ++i) {
        GetShapeSelectControl(8 + i)->SetSelected(i == slot);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b530-0x0052b5b8`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::SelectMaleMode()
{
    SetChildButtonChecked(4, true);
    SetChildButtonChecked(5, false);

    for (int i = 0; i < 4; ++i) {
        GetShapeSelectControl(8 + i)->SetMaleMode();
    }

    SelectShapeSlot(m_selectedShapeSlot);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b5c0-0x0052b648`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::SelectFemaleMode()
{
    SetChildButtonChecked(4, false);
    SetChildButtonChecked(5, true);

    for (int i = 0; i < 4; ++i) {
        GetShapeSelectControl(8 + i)->SetFemaleMode();
    }

    SelectShapeSlot(m_selectedShapeSlot);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b650-0x0052b724`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::PromptCreateCharacterName()
{
    SimpleUString initialName;

    GetCreateCharacterNamePromptText(initialName);
    ShowCreateCharacterNamePrompt(initialName,
                                  this,
                                  &NewUserDialogPane2::ApplyCreateCharacterName);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b730-0x0052b75c`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::ApplyCreateCharacterName(const SimpleUString &name)
{
    if (!name.empty()) {
        m_createdUserName = name;
    }

    SendCreateCharacterRequest();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b760-0x0052b88c`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewUserDialogPane2::OnCommand(int commandId)
{
    switch (commandId) {
    case 4:
        SelectMaleMode();
        return true;

    case 5:
        SelectFemaleMode();
        return true;

    case 6:
        ShiftShapesLeft();
        NotifySelectedShapeChanged();
        return true;

    case 7:
        ShiftShapesRight();
        NotifySelectedShapeChanged();
        return true;

    case 8:
    case 9:
    case 10:
    case 11:
        SelectShapeSlot(commandId - 8);
        return true;

    case 12:
    case 13:
        SelectNation(commandId - 12);
        return true;

    case 14:
    case 15:
    case 16:
    case 17:
        SelectTotem(commandId - 14);
        return true;

    case 20:
        SubmitCreateUser();
        return true;

    case 21:
        Close();
        return true;

    default:
        return DialogPane::OnCommand(commandId);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b890-0x0052b910`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewUserDialogPane2::HandleShapeKeyEvent(const KeyEvent &event)
{
    if (event.IsLeft()) {
        ShiftShapesLeft();
        NotifySelectedShapeChanged();
        return true;
    }

    if (event.IsRight()) {
        ShiftShapesRight();
        NotifySelectedShapeChanged();
        return true;
    }

    return DialogPane::HandleKeyEvent(event);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b910-0x0052b936`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewUserDialogPane2::HandleCreateUserPacketEvent(const unsigned char *packet)
{
    if (packet == 0 || packet[0] != 0x02) {
        return false;
    }

    return HandleCreateUserReply(packet);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b940-0x0052b949`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewUserDialogPane2::ForwardDialogNotify(DialogEvent &event)
{
    return DialogPane::OnDialogNotify(event);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052b9f0-0x0052bbbc`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t confirmPassword[16];

    GetChildEditText(1, accountName, 15);
    GetChildEditText(2, password, 15);
    GetChildEditText(3, confirmPassword, 15);

    bool hasDigit = false;
    for (const wchar_t *scan = password; *scan != L'\0'; ++scan) {
        if (*scan >= L'0' && *scan <= L'9') {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        FocusChildControl(2);
        ShowCreateUserAlert(g_pLanguageMan->GetString(89));
        return;
    }

    if (wcscmp(password, confirmPassword) != 0) {
        FocusChildControl(2);
        ShowCreateUserAlert(g_pLanguageMan->GetString(90));
        return;
    }

    CreateCreateUserScreenDimmer();
    SendCreateAccountRequest(accountName, password, kCreateUserDefaultProfileText);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052bbc0-0x0052bdc5`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
void SendCreateAccountRequest(const wchar_t *accountName,
                              const wchar_t *password,
                              const wchar_t *profileText)
{
    PacketBuffer packet;
    packet.WriteByte(0x02);
    packet.WriteLengthPrefixedMbcString(accountName);
    packet.WriteLengthPrefixedMbcString(password);
    packet.WriteLengthPrefixedMbcString(profileText);
    packet.WriteByte(0);
    g_packetSender->QueueAndSendPacket(packet.Data(), packet.Size());
}
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052bdd0-0x0052bfc2`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewUserDialogPane2::SendCreateCharacterRequest()
{
    if (g_createUserScreenDimmer == 0) {
        CreateCreateUserScreenDimmer();
    }

    UserShapeSelectControlPane *shapeControl =
        GetShapeSelectControl(8 + m_selectedShapeSlot);
    CreateUserShapePacketData shapeData;
    shapeControl->GetCreateUserShapePacketData(shapeData);

    PacketBuffer packet;
    packet.WriteByte(0x04);
    packet.WriteWord(0x00c8);
    packet.WriteByte(shapeData.shape);
    packet.WriteByte(shapeData.direction);
    packet.WriteByte((unsigned char)(m_selectedNation + 1));
    packet.WriteByte((unsigned char)m_selectedTotem);
    packet.WriteLengthPrefixedMbcString(m_createdUserName.c_str());

    g_packetSender->QueueAndSendPacket(packet.Data(), packet.SizeWithoutTerminator());
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Formal C++ For `0x0052bfd0-0x0052c325`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
SimpleUString DecodeCreateUserReplyMessage(const unsigned char *packet)
{
    return SimpleUString::FromMbcString(packet + 3, packet[2]);
}

bool IsCreateUserNameReplyError(unsigned char result)
{
    switch (result) {
    case 3:
    case 4:
    case 14:
    case 16:
    case 17:
    case 18:
    case 20:
    case 21:
        return true;

    default:
        return false;
    }
}

bool IsCreateUserPasswordReplyError(unsigned char result)
{
    switch (result) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 15:
        return true;

    default:
        return false;
    }
}

void ShowCreateUserReplyText(const SimpleUString &message)
{
    if (!message.empty()) {
        ShowCreateUserAlert(message.c_str());
    }
}
}

bool NewUserDialogPane2::HandleCreateUserReply(const unsigned char *packet)
{
    const unsigned char result = packet[1];
    const SimpleUString message = DecodeCreateUserReplyMessage(packet);

    if (!m_waitingForCharacterReply) {
        if (result == 0) {
            wchar_t accountName[16];

            m_waitingForCharacterReply = true;
            SendCreateCharacterRequest();

            GetChildEditText(1, accountName, 15);
            g_newUserDialogCreatedAccountName.Assign(accountName);
            return true;
        }

        DestroyCreateUserScreenDimmer();

        if (IsCreateUserNameReplyError(result)) {
            FocusChildControl(1);
        } else if (IsCreateUserPasswordReplyError(result)) {
            FocusChildControl(2);
        }

        ShowCreateUserReplyText(message);
        return true;
    }

    DestroyCreateUserScreenDimmer();

    if (result != 0) {
        ShowCreateUserReplyText(message);
        return true;
    }

    if (!message.empty()) {
        ShowCreateUserAlert(message.c_str());
    } else {
        ShowCreateUserAlert(kCreateUserCompleteMessage);
    }

    Close();
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Required Vtable Tail Child

Create `by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md`. This is not optional: live evidence proves `0x0061fd94` is the third `NewUserDialogPane2` vtable-view tail, while the current [UID:0002SH][NewUserDialogPane2VtableData](../../../../../by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) page ends immediately before it and incorrectly treats `0x0061fd84` as the relevant negative check.

Recommended metadata and disposition:

- `COMPLETION:86`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00009E`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `Nested:0`
- Formal C++ stays blank because this is source-declared/generated-binary vtable data regenerated from the `NewUserDialogPane2` class declaration, not a standalone source-emitting code/data range:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended item summary:

> Exact third `NewUserDialogPane2` vtable-view tail at `0x0061fd94-0x0061fd9c`; live MCP confirms constructor, constructor-adjacent cleanup, and scalar-deleting-destructor stores to `0x0061fd94`, first entries `0x0052f772` and `0x00544e90`, and source-declared/generated-binary non-emitting disposition under [UID:00009E][NewUserDialogPane2].

Evidence to record on the child:

- `xrefs_to 0x0061fd94` returns data refs at `0x0052a5c2` in the constructor, `0x0052b069` in the IDA-unmodeled complete-destructor body, and `0x0052f8fc` in the scalar deleting destructor.
- `get_int` reads `0x0061fd94 -> 0x0052f772`, `0x0061fd98 -> 0x00544e90`, `0x0061fd9c -> 0x0064c810`, and `0x0061fda0 -> 0x0052f870`, proving the tail sits between the current [UID:0002SH] range and the `NewCreateUserDialogPane` vtable block.
- Update [UID:0002SH] so its boundary notes point to this new child at `0x0061fd94` and remove the stale "no tertiary-view consumer" inference from `xrefs_to 0x0061fd84`.

Vtable-tail no-code proof: this child documents an uncovered slice of compiler-emitted vtable data whose source output is the `NewUserDialogPane2` class declaration and virtual-method set, not a standalone C++ statement or local static initializer inside this address slice. Because the page is recommended as `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`, the formal block remains blank instead of using an emitter comment. That avoids creating a false source emitter while preserving the exact data-boundary evidence required to repair [UID:0002SH].

## Support Document Updates Required

`by-class/NewUserDialogPane2.md` should be updated, without broad rewriting, to say:

- [UID:0002QR] is now a split/index, not the method-body emitter.
- Exact child pages carry method bodies and no-code proofs.
- The method list should include the constructor-adjacent complete destructor body as raw lifecycle evidence, `PromptCreateCharacterName`, `ApplyCreateCharacterName`, the create-user packet-event bridge, and the two raw no-route clear helpers.
- The declaration block or method inventory should include the formal child methods named in this report, including `PromptCreateCharacterName`, `ApplyCreateCharacterName(const SimpleUString &name)`, `SubmitCreateUser`, `SendCreateCharacterRequest`, `HandleCreateUserReply`, and the event/command bridge names where the class page maintains declarations. Do not add `SendCreateAccountRequest` to the class declaration; it is file-local in [UID:0000LW].
- The field declarations should use the source-facing names from this report: `m_childControls` for `+0x1fc`, `m_selectedNation` for `+0x26c`, `m_selectedTotem` for `+0x270`, `m_selectedShapeSlot` for `+0x274`, `m_waitingForCharacterReply` for `+0x278`, and `m_createdUserName` for `+0x27c`.
- The payload/reply notes should supersede the old "field write" interpretation: `SendCreateCharacterRequest` extracts shape descriptor data before serializing opcode `0x04`, and `HandleCreateUserReply` is a two-phase handler using status at packet offset `+1`.

`by-file/NewUserDialogPane2.md` should be updated to say:

- [UID:0002QR] is a non-emitting split/index over exact children.
- `0x0052bbc0-0x0052bdc5` is a file-local `SendCreateAccountRequest` helper, not a class method.
- `0x0052b050-0x0052b08a`, `0x0052b950-0x0052b981`, and `0x0052b990-0x0052b9ed` are real code islands discovered in the target range; two have no xrefs/pointer route and should stay non-emitting under the current negative route proof.

`by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md` should get a narrow note that [UID:0002QR] is now an internal split/index and that exact NewUserDialogPane2 method/helper children sit under it. Do not change the broad parent ownership policy.

`by-file/CreateUserDialogs.md` should get a narrow support-line update that [UID:0002QR] is an internal split/index under `NewUserDialogPane2.cpp`, not a direct monolithic method-body emitter. Keep [UID:0000IK] non-emitting.

`by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md` should be updated to say its range covers the primary and secondary `NewUserDialogPane2` vtable views and ends before the required `0x0061fd94-0x0061fd9c` tertiary-tail child. Replace the stale `xrefs_to 0x0061fd84` negative inference with the live `xrefs_to 0x0061fd94` evidence and cross-link the new child.

No generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md` should be edited manually.

## Generated Refresh Expectations

After accepted implementation, scoped file validators with `--wait-generated` should refresh autogen metadata for each touched/created by-* file. It is expected that generated `auto-generated/-ag-*` rows are stale before implementation; for example, generated coverage/tracker rows currently lag the source by-* pages for this family. Do not hand-patch those rows.

## Validator Command Set For Accepted Implementation

Run from `source-3/project-documentation` after creating/editing the accepted files. Record command id, timestamp, exit status, and ok count for each command.

> Executable block R001 was removed from this report and preserved verbatim in [0002QR-NewUserDialogPane2CreateUserVariant-source-quality-removed.md](0002QR-NewUserDialogPane2CreateUserVariant-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Tracking Checklist

Implementation completed by Agent-B004 on 2026-06-26.

- [x] Lease only the immediate edit batch and update `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md`: metadata is `89/90`, owner `0000LW`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++, `Nested:21`, new split/index summary, parent no-code proof, live MCP evidence, resolved child table, raw/jump-table/padding notes, naming decisions, and superseded aggregate C++ section. Proof: sections `Status`, `Parent No-Code Proof`, `2026-06-26 B004 Source-Quality Reanalysis`, `Child Split Index`, `Naming And Source-Shape Decisions`, `Superseded Aggregate C++ Assumptions`; validator `000000002443`, `2026-06-26T05:44:59-04:00`, exit `0`, `ok:1`, generated refresh `completed`.
- [x] Create `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` as [UID:00043K] with metadata, constructor callers/resources/field-offset evidence, and exact formal constructor block. Proof: validator `000000002444`, `2026-06-26T05:45:44-04:00`, exit `0`, `ok:1`, generated refresh `completed`.
- [x] Create `by-memory/0x0052b050-0x0052b08a.NewUserDialogPane2CompleteDestructorBody.md` as [UID:00043L] non-emitting lifecycle/raw evidence with blank formal C++ and no xref/pointer route proof. Proof: validator `000000002445`, `2026-06-26T05:45:57-04:00`, exit `0`, `ok:1`, generated refresh `completed`.
- [x] Create selector helper children [UID:00043M] through [UID:00043S] for `ShiftShapesLeft`, `ShiftShapesRight`, `SelectNation`, `SelectTotem`, `SelectShapeSlot`, `SelectMaleMode`, and `SelectFemaleMode`, with behavior/control evidence and exact formal C++ blocks. Proof: validators `000000002446`-`000000002452`, timestamps `2026-06-26T05:46:09-04:00` through `2026-06-26T05:47:21-04:00`, all exit `0`, each `ok:1`, generated refresh `completed`.
- [x] Create prompt/callback children [UID:00043T] and [UID:00043U] for `PromptCreateCharacterName` and `ApplyCreateCharacterName`, with exact formal C++ blocks. Proof: validators `000000002453` (`2026-06-26T05:47:33-04:00`) and `000000002454` (`2026-06-26T05:48:30-04:00`), both exit `0`, `ok:1`, generated refresh `completed`.
- [x] Create `by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnCommand.md` as [UID:00043V], including the `0x0052b844-0x0052b88c` jump table, command table, callees, `NotifySelectedShapeChanged`, and exact formal C++ block. Proof: validator `000000002455`, `2026-06-26T05:48:42-04:00`, exit `0`, `ok:1`, generated refresh `completed`.
- [x] Create event/bridge children [UID:00043W], [UID:00043X], and [UID:00043Y] for `HandleShapeKeyEvent`, `HandleCreateUserPacketEvent`, and `ForwardDialogNotify`, with adjusted-receiver evidence and exact formal C++ blocks. Proof: validators `000000002456`-`000000002458`, timestamps `2026-06-26T05:48:54-04:00` through `2026-06-26T05:49:18-04:00`, all exit `0`, each `ok:1`, generated refresh `completed`.
- [x] Create non-emitting raw helper children [UID:00043Z] and [UID:000440] for `0x0052b950-0x0052b981` and `0x0052b990-0x0052b9ed`, with blank formal C++ blocks and lookup/xref/byte-pattern negative evidence. Proof: validators `000000002459` (`2026-06-26T05:49:31-04:00`) and `000000002460` (`2026-06-26T05:49:43-04:00`), both exit `0`, `ok:1`, generated refresh `completed`.
- [x] Create submit/account/payload/reply children [UID:000441], [UID:000442], [UID:000443], and [UID:000444]; `0x0052bbc0` is owner/emitter `0000LW`, and all four reconstructable children contain the exact formal blocks for `SubmitCreateUser`, file-local `SendCreateAccountRequest`, `SendCreateCharacterRequest`, and `HandleCreateUserReply`. Proof: validators `000000002461`-`000000002464`, timestamps `2026-06-26T05:49:54-04:00` through `2026-06-26T05:50:31-04:00`, all exit `0`, each `ok:1`, generated refresh `completed`.
- [x] Create `by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md` as [UID:000445] with `86/91`, owner `00009E`, reconstructable false, blank emitter/formal C++, item summary, `xrefs_to 0x0061fd94`, `get_int` values, and non-emitting vtable-tail disposition. Proof: validator `000000002466`, `2026-06-26T05:51:32-04:00`, exit `0`, `ok:1`, generated refresh `completed`. Earlier validator `000000002465` also completed generated refresh for the same path but did not print a parsed `ok` count, so `000000002466` is the recorded proof command.
- [x] Update `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md`: stale `xrefs_to 0x0061fd84` tertiary-negative inference removed, live `0x0061fd94` tail evidence added, and [UID:000445] cross-linked. Proof: sections `Summary`, `Evidence`, `Boundary Notes`, `Score Rationale`, `Cross-References`, `Changes`; validator `000000002467`, `2026-06-26T05:51:44-04:00`, exit `0`, `ok:6`, generated refresh `completed`.
- [x] Update `by-class/NewUserDialogPane2.md` method list, evidence notes, field declarations (`m_childControls`, `m_selectedNation`, `m_selectedTotem`, `m_selectedShapeSlot`, `m_waitingForCharacterReply`, `m_createdUserName`), child-method declaration notes including `ApplyCreateCharacterName`, and superseded payload/reply interpretation. Proof: class C++ block and section `2026-06-26 B004 Exact Child Split Implementation`; validator `000000002468`, `2026-06-26T05:51:57-04:00`, exit `0`, `ok:2`, generated refresh `completed`.
- [x] Update `by-file/NewUserDialogPane2.md` for split-index treatment, exact child ownership, file-local packet helper, raw island evidence, corrected packet/reply source shape, and vtable-tail support. Proof: `Proposed Contents`, `Evidence Notes`, and section `2026-06-26 B004 Internal Split Implementation`; validator `000000002469`, `2026-06-26T05:52:09-04:00`, exit `0`, `ok:2`, generated refresh `completed`.
- [x] Update `by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md` with a narrow support note that [UID:0002QR] is now a non-emitting internal split/index with exact children, without changing the broad parent ownership policy. Proof: section `2026-06-26 B004 NewUserDialogPane2 Internal Split`; validator `000000002470`, `2026-06-26T05:52:21-04:00`, exit `0`, `ok:1`, generated refresh `completed`.
- [x] Update `by-file/CreateUserDialogs.md` with a narrow note that [UID:0002QR] is an internal split/index under `NewUserDialogPane2.cpp`, not a direct monolithic method-body emitter, while [UID:0000IK] remains non-emitting. Proof: section `2026-06-26 B004 NewUserDialogPane2 Split Callback`; validator `000000002471`, `2026-06-26T05:52:33-04:00`, exit `0`, `ok:1`, generated refresh `completed`.
- [x] Run the exact scoped validator command set above from `source-3/project-documentation` for every touched/created by-* file. Proof: command IDs `000000002443`-`000000002464` and `000000002466`-`000000002471`; all recorded commands exited `0`. The extra tail validation `000000002465` also exited `0` and generated refresh completed, but `000000002466` is retained as the row with parsed `ok:1`.
- [x] Record validator `command_id`, `command_timestamp`, exit status, and ok count for every validator command in this checklist. Proof: per-item entries above.
- [x] Record generated-refresh observations for affected autogen rows/source output; do not edit generated files manually. Proof: every recorded validator reported `generated_refresh: completed`. Command `000000002443` also reported validator-owned UID insertion for [UID:00043K]-[UID:000445], TMP-link replacement, `autogen_backup_create`, `autogen_cpp_update`, `memory_auto_coverage_update`, `projected_stats_update`, and `research_tracker_update`; these were validator-owned refreshes, not manual generated-file edits.
- [x] Confirm no generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md` were manually edited. Proof: manual edits were limited to accepted by-* docs plus this Agent-B004 report checklist; generated changes came only from scoped validator commands with `--wait-generated`.
- [x] Release all leases immediately after the edit/validator batch and record lease release proof/no active B004 leases. Proof: after `python .\tools\leaser\leaser.py B004 unlease ...` for the remaining validator batch, `tools/leaser/Agents/current_leases.md` read `No active leases.`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002QR-NewUserDialogPane2CreateUserVariant-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002QR-NewUserDialogPane2CreateUserVariant-source-quality.md","timestamp":"2026-06-26T06:06:58","uid":"0002QR"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002QR-NewUserDialogPane2CreateUserVariant-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002QR-NewUserDialogPane2CreateUserVariant-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002QR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
