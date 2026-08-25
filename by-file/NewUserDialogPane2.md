*** UID:0000LW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NewUserDialogPane2

## Status

- Confidence: very strong for behavior, path placement, variant ownership, direct launcher reachability, complete class declaration, inherited DialogPane child lookup, exact child method-body/source ordering, and compiler exclusions; final original lexical spellings remain descriptive.
- Proposed module: `login/NewUserDialogPane2.cpp`.
- Family/index doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), now non-emitting.
- Current recovered source: `source-3/simroot_v2/class_NewUserDialogPane2.cpp`
- Main class: [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- Exact executable island: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- Exact vtable data: [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- Singleton slot: [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## File Role

`NewUserDialogPane2.cpp` is the concrete alternate 640x480 create-character source. It declares `NewUserDialogPane2` before its exact child definitions, uses `DLGNEW02.EPD` and `NPAL3.PAL`, displays four `UserShapeSelectControlPane` previews, handles gender/totem/body-shape/direction selection, and submits the create-user request. Child lookup remains inherited from `DialogPane`; the derived class does not duplicate the base manager field.

This is not the same source role as [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). `NewUserDialogPane` is the older account-registration dialog; `NewUserDialogPane2` belongs to the character creation UI family with [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) and [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserDialogPane2` constructor | `0x0052a540-0x0052b047` | Builds the alternate 640x480 create-character dialog and initializes `m_selectedNation`, `m_selectedTotem`, `m_selectedShapeSlot`, `m_waitingForCharacterReply`, and `m_nexonclubAccountName`. |
| raw lifecycle/clear islands | `0x0052b050-0x0052b08a`, `0x0052b950-0x0052b981`, `0x0052b990-0x0052b9ed` | Non-emitting no-route evidence for an IDA-unmodeled complete-destructor body and raw selector-clear bodies. |
| shape/nation/totem/gender selectors | `0x0052b090-0x0052b648` | Exact left/right callbacks rotate the selected slot or perform signed-short edge steps. UID00043P `SelectTotem(short)` retrieves PrettyButton children `14-17`, clears old selection, selects caller-provided `0..3`, stores `m_selectedTotem`, and updates TextEdit child `19` from STR.RES id `212 + totem` without an internal clamp. Nation/totem/slot selectors own their fields; exact male/female methods toggle PrettyButton children `4/5` and switch UserShape children `8-11` to the corresponding shape bank without reselecting the shape slot. |
| Nexonclub registration gate/callback | `0x0052b650-0x0052b75c` | `OpenNexonclubRegistrationOrSendCharacterRequest(bool)` either sends directly or opens `NexonclubRegistrationDialog` with STR.RES id `227`; `OnNexonclubRegistrationResult` stores nonempty account text and always sends. |
| command/EventHandler overrides | `0x0052b760-0x0052b949` | `OnControlCommand(int,int)` dispatches ids `4-17/20/21` and only command cases `6/7` call `SetHoverControl(8)` after shifts. Secondary EventHandler slots provide pointer/mouse base forwarding, exact key/text translation and key-down shifts without notification, inherited IME handling, and an opcode-`0x02` Event packet bridge. |
| `SubmitCreateUser` | `0x0052b9f0-0x0052bbbc` | Validates edit fields, requires a digit in the password, compares confirmation text, creates the dimmer, and calls the file-local account packet helper. |
| file-local `SendCreateAccountRequest` | `0x0052bbc0-0x0052bdc5` | Encodes opcode `0x02`, three length-prefixed MBCS strings, and a trailing zero byte; it is not a `NewUserDialogPane2` class method. |
| `SendCreateCharacterRequest` / `HandleCreateUserReply` | `0x0052bdd0-0x0052c325` | Builds opcode `0x04` from selected shape bytes and handles two-phase account/character reply status and message data. |
| vtable data | `0x0061fd04-0x0061fd9c` via split pages | Source-declared/generated-binary vtable data for primary/secondary views plus the separate tertiary tail child at `0x0061fd94-0x0061fd9c`. |
| singleton slot | `0x0069b4a4` | Loader-zeroed physical evidence; sole external-linkage definition is semantic UID0002X3, and direct `Singleton<NewUserDialogPane2>` construction/destruction publishes and clears it. |
| destructor family | `0x0052f767`, `0x0052f772`, `0x0052f8e0` | Adjustor and scalar deleting destructor logic in the shared create-user destructor/thunk island. |

## Exact Totem Selector Source Contract

- [UID:00043P][0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem](by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md) emits one qualified `NewUserDialogPane2::SelectTotem(short)` definition at its exact child position in `NexusTK/login/NewUserDialogPane2.cpp`; declaration ownership remains in class H UID00009E.
- The exact `[0x0052b3a0,0x0052b462)` body is 194 bytes, SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, with 65 instructions and one basic block. Eleven `0xcc` bytes precede it, fourteen `0xcc` bytes follow it, and UID00043Q starts independently at `0x0052b470`.
- Source uses one explicit `PrettyButtonControlPane *totemButtons[4]` local filled from inherited `GetChild<T>` controls `14..17`; operation order is clear old indexed selection, select new indexed control, store `m_selectedTotem +0x270`, then update TextEdit child `19` from `g_pLanguageMan->GetLocalizedString(totem + 212)`.
- Constructor site `0x0052b001` passes a fresh normalized `_rand() % 4`; UID00043V cases `14..17` pass `0..3`. The method has no clamp, guard, null check, loop, conditional branch, packet write, or data/vtable reachability.
- UID000443 serializes the resulting totem byte directly after one-based nation. STR.RES ids `212..215` supply the four current totem descriptions while source retains runtime lookup.
- Historical `int` signature, clamp, synthesized loop, store-first order, `SetChildButtonChecked`, `SetCreateUserDescriptionText`, and `GetString` are rejected source abstractions retained only as superseded analysis.

## Exact Command And Event Source Contract

- [UID:00043V][0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand](by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand.md) is primary slot `+0x48`: a void two-argument control dispatcher with unused notify code, explicit ids `4-17/20/21`, command-only `SetHoverControl(8)` after left/right shifts, no inherited default call, and an owned compiler jump table at `0x0052b844-0x0052b88c`.
- [UID:00043W][0x0052b890-0x0052b910.NewUserDialogPane2HandleKeyOrTextEvent](by-memory/0x0052b890-0x0052b910.NewUserDialogPane2HandleKeyOrTextEvent.md) is secondary slot `+0x08`: it translates Event key/modifiers, gates inherited active control ids `8..11`, maps Left/Up key-down to left shift and Right/Down key-down to right shift, returns true only for handled shifts, delegates all other routes to DialogPane, and makes no post-shift notification/hover call.
- [UID:00043X][0x0052b910-0x0052b936.NewUserDialogPane2HandlePacketEvent](by-memory/0x0052b910-0x0052b936.NewUserDialogPane2HandlePacketEvent.md) is secondary slot `+0x10`: exact range `[0x0052b910,0x0052b936)`, 38 bytes, SHA256 `B8CDCBD9D1881904B8BBDFD194B737C15FFEAA73A59F52B250E14D1C5803DB4B`. Its four-block body reads `event->m_payload.m_packet.m_data`, accepts opcode `0x02`, returns false otherwise, rewrites the accepted stack argument to the packet pointer, restores complete `this` from the EventHandler facet with compiler adjustment `-0xa0`, and tail-dispatches from `0x0052b931` to `HandleCreateUserReply` without a synthetic null guard.
- UID00043X's only inbound xref is vtable cell `0x0061fd74`. Catalog entry `0352` preserves the binary-facing adjusted-facet declaration and automatic Event frame member; source emits the human virtual method and direct packet local, not raw facet arithmetic. UID00043W ends at the target start, and ten `0xcc` bytes separate the target endpoint from UID00043Y.
- [UID:00043Y][0x0052b940-0x0052b949.NewUserDialogPane2HandlePointerOrMouseEvent](by-memory/0x0052b940-0x0052b949.NewUserDialogPane2HandlePointerOrMouseEvent.md) is secondary slot `+0x04`: a nine-byte source forwarder to `DialogPane::HandlePointerOrMouseEvent(Event *)`. Secondary `+0x0c` remains inherited `HandleImeEvent`.
- Historical `OnCommand`, `HandleShapeKeyEvent`, `HandleCreateUserPacketEvent`, `ForwardDialogNotify`, `NotifySelectedShapeChanged`, direct-packet/null-guard, and dialog-notification interpretations are superseded. The old names remain provenance only; they are not current source or behavior.

## Exact Male/Female Selector Source Pair

- [UID:00043R][0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode](by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md) is a source-ready 136-byte method, SHA256 `318E714C08908DCE721179A703BFBCBED42A2FF353F4D0A7EE03A18D3176F109`. Its constructor and command-id-`4` call sites are `0x0052b01d` and `0x0052b790`.
- [UID:00043S][0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode](by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md) is the 136-byte symmetric method, SHA256 `F9C237761B1388EEF54ED332579E1FFF9715284DF6FBA40F0E81BAF00C1B0135`, called at constructor `0x0052b024` and command-id-`5` site `0x0052b79a`.
- The constructor chooses between the pair using a normalized `_rand()` bit. Each command case directly calls its selector and returns; the methods do not send packets or perform parent notification.
- Both methods use inherited `DialogPane::GetChild<T>`. They obtain [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md) children `4/5` and call exact [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md): male uses `true/false`, female uses `false/true`.
- They then obtain [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md) children `8`, `9`, `10`, and `11` in literal order. Male calls exact `SetMaleShapeBank()` at `0x004fd030`; female calls `SetFemaleShapeBank()` at `0x004fd050`.
- Complete executable inventories prove no `SelectShapeSlot` call, no `m_selectedShapeSlot` field access, no loop, no packet operation, and no notification. The existing selected slot is not re-applied by either gender method.
- Prior `SetChildButtonChecked`, `GetShapeSelectControl`, shape `SetMaleMode`/`SetFemaleMode`, loop, and final reselect source were historical abstractions. Exact typed child APIs replace them while preserving both positive and negative evidence.

## Exact Nexonclub Registration Source Pair

- [UID:00043T][0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md) is exactly 212 bytes, SHA256 `46089EEA71E6B8B3912883A886152516631910E997182FF94408F0DB057BD247`; [UID:00043U][0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult](by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md) is exactly 44 bytes, SHA256 `3019CB1E0DBAB342A544722DE3FD62F6A4E22042A029E15B097D9AF33895A1CE`. The intervening `0x0052b724-0x0052b730` span is 12-byte `0xCC` alignment.
- UID00043T's sole argument is a pure boolean gate. False calls `SendCreateCharacterRequest`; true allocates/binds a 24-byte `PlainMemberFunctionObjectT` through vtable `0x0061ff70`, reads `g_pLanguageMan->GetLocalizedString(227)`, and constructs the 632-byte `NexonclubRegistrationDialog`.
- Current `baram.dat` `STR.RES` id `227` is `Please input nexon.com ID and password.` Registration success state `0` passes account-control text to UID00043U; nonempty text is stored in `m_nexonclubAccountName`, and the callback always sends.
- `NexonclubRegistrationDialog` owns callback storage/invocation/release after construction. [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) owns reusable callback template source; this file owns only the concrete `NewUserDialogPane2` binding and member bodies.
- The same pair appears in `NewCreateUserDialogPane` at `0x0052d100/0x0052d1e0` and [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md)/[UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) at `0x0052e970/0x0052ea50`. Constructor `0x0052f950` has exactly those three create-user callers plus NexonclubProxyDialog.
- UID00043T has no current incoming xref or target pointer encoding. That negative evidence limits the historical callsite, not source ownership or formal C++, because the exact object/callback behavior and symmetric source pair are established.
- Historical `PromptCreateCharacterName`, `ApplyCreateCharacterName`, `m_createdUserName`, local prompt temporary, and invented generic prompt helpers are superseded and retained only as prior-analysis history.

## Boundary Notes

- Wave3 currently names the `0x0052a540` row like a destructor, but the generated body and IDA-confirmed behavior are constructor-like.
- Keep the shape-preview control implementation in [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) unless final source-size review folds it into this file.
- Keep account registration/password-only behavior in [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) and [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Keep [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) under [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). It constructs `NewUserDialogPane2` in one branch, but it is a retained main-menu launcher rather than a method owned by this dialog implementation.
- Treat [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) as compiler output generated from the [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) class declaration and virtual layout; do not hand-port the bytes into this source file. The 2026-06-16 refresh reroutes that exact vtable page through the direct class rather than the broader create-user umbrella, and the 2026-07-04 B014 callback makes it non-reconstructable/non-emitting so generated `NewUserDialogPane2.cpp` should contain class/method source but no UID0002SH empty marker or hand-authored vtable array.
- The executable child ends at `0x0052c325`; the next create-user variant starts at `0x0052c360`, so this file's modeled core should not absorb the intervening padding or the [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) method island.
- Do not fold this file into [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md). That page is now a non-emitting family/index page; this file owns the concrete alternate 640x480 variant output.
- `NewUserDialogPane2` owns only `+0x26c` nation, `+0x270` totem, `+0x274` shape slot, `+0x278` reply phase, and `+0x27c` Nexonclub account-name storage beyond `DialogPane`. The earlier duplicate `m_childControls` at `+0x1fc` is historicalized; typed `GetChild` uses the inherited base manager.
- Compiler cookie checks, complete/scalar deleting destructors, adjustor thunks, vtable bytes, singleton cleanup lowering, and command jump-table data are evidence for generated output, not handwritten source statements.

## Singleton Definition, Header, And Source Order

- Source position `0`: [UID:0002X3][g_pNewUserDialogPane2](by-global/g_pNewUserDialogPane2.md) emits the sole external-linkage CPP definition `NewUserDialogPane2 *g_pNewUserDialogPane2 = 0;` after a forward declaration.
- Source position `10`: [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) emits the matching extern declaration and complete class declaration in H, including direct public `Singleton<NewUserDialogPane2>` inheritance and `[[CHILDREN]]`. Its CPP channel is blank.
- Source position `20`: [UID:00043K][0x0052a540-0x0052b047.NewUserDialogPane2Constructor](by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md) emits the constructor with a direct Singleton base initializer and without a duplicate handwritten global assignment.
- Exact physical [UID:0002X4][0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2](by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md) is `92/94`, non-reconstructable, non-emitting evidence. Mixed aggregate UID00029W remains a parentless address index.
- Header/source one-definition acceptance requires one CPP definition, one H extern/class declaration, no UID0002X3 or UID0002X4 empty marker, no duplicate class declaration in CPP, and no explicit constructor publication.

## Loader-Zero And Direct Singleton Evidence

- Target RVA `0x0029b4a4` lies in `.data` virtual tail after raw-backed end RVA `0x0027a800`; no file offset or raw initializer exists. The executable has relocations stripped and a zero relocation directory. Loader zero-fill is the exact initial-state cause.
- The direct Singleton RTTI base descriptor at `0x0064c798` records PMD `620/-1/0`. Constructor instructions at `0x0052a581-0x0052a59e` use the same `+0x26c` adjustment to publish complete `this` or zero.
- Current class UDT is `0x280` bytes. The empty Singleton base overlaps `m_selectedNation` at `+0x26c` through MSVC empty-base optimization; source uses natural multiple inheritance without an invented field or padding array.
- Six slot refs are exact: MainMenu cleanup read `0x004f6a22`; constructor publish/fallback `0x0052a597`/`0x0052a59e`; raw complete-destructor clear `0x0052b07a`; clear helper `0x0052f730`; scalar deleting-destructor clear `0x0052f90d`.

## Corrected Singleton History

- The 2026-06-07 `0xffffffff` statement was a stale raw-byte interpretation. Current PE mapping and live IDB bytes prove loader-zeroed `0x00000000`.
- `dword_69B4A4` and current `unk_69B4A4` are historical/live IDA aliases only; human source uses `g_pNewUserDialogPane2`.
- Explicit `g_pNewUserDialogPane2 = this` constructor source, omitted Singleton inheritance, physical-slot emission, MainMenu ownership, and aggregate emission are superseded by direct-base lowering and the semantic-global one-definition route.

## Evidence Notes

- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) is now the non-emitting split/index for the constructor, selectors, Nexonclub registration/callback helpers, command/event bridges, submit path, file-local account packet helper, create-character packet builder, reply handler, and raw/lifecycle islands. Exact child pages under it carry the formal source C++ or no-code proofs.
- Constructor reachability is documented from `0x004f7ad0` and from [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) at `0x004f9041`; the launcher itself remains a [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) concern.
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) records constructor/destructor vtable references at `0x0052a5b2`, `0x0052b059`, and `0x0052f8ec`, with the adjacent `NewCreateUserDialogPane` vtable block beginning at `0x0061fda0`.
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) records `0x0069b4a4` as `g_pNewUserDialogPane2`, including constructor publish/fallback clear, constructor-adjacent cleanup clear, explicit clear helper, scalar deleting destructor clear, and main-menu cleanup read.
- Submit-path documentation records the three edit-field reads, digit-in-password requirement, password confirmation comparison, alert fallback, length-prefixed packet encoding, send through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`, and server-reply alert/reset behavior.
- Historical 2026-06-07 Batch 043 evidence described `0x0069b4a4-0x0069b4a8` as a clean `0xffffffff` singleton item with six xrefs. The six-ref inventory remains valid, but current PE mapping and live bytes supersede the value: this is loader-zeroed virtual-tail storage initialized to `0x00000000`. The exact storage has physical page [UID:0002X4][0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2](by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md) and sole source global [UID:0002X3][g_pNewUserDialogPane2](by-global/g_pNewUserDialogPane2.md).
- 2026-06-16 A001 live IDA/PE refresh reconfirmed the constructor-like body at `0x0052a540`, command/submit/packet helpers through `0x0052c325`, and the neighboring `NewCreateUserDialogPane` successor at `0x0052c360`. `xrefs_to 0x0052a540` returns the two constructor branches at `0x004f7ad0` and `0x004f9041`; section-mapped PE direct-branch scanning finds the same two hits and no pointer encodings. Submit and packet evidence was checked through `analyze_function` for `0x0052b9f0` and `0x0052bbc0`, confirming three edit-field reads, digit/password confirmation validation, length-prefixed packet encoding, and queue-send dependencies. Vtable refs at `0x0061fd04`/`0x0061fd64` and singleton refs through `0x0069b4a4` still support the direct `NewUserDialogPane2` class route, while exact field/helper names and the standalone-versus-umbrella source split remain open.
- 2026-07-04 B014 UID0002SH route check in MCP session `aa3930bd` reconfirmed an active IDB/healthy server, nonfunction vtable data at `0x0061fd04-0x0061fd94`, decorated table bases, constructor/complete-destructor/scalar-deleting-destructor stores only, zero RVA pointer-pattern hits, exact slot dwords/bytes, no local UDT/type records, and successor `0x0061fda0` owned by `NewCreateUserDialogPane`. This supports retaining `NewUserDialogPane2.cpp` as the class/method source route while treating UID0002SH as generated-binary support.
- The Nexonclub gate/callback pair keeps ownership in this source file because receiver, bound callback target, fallback packet method, stored field, and packet consumer are all `NewUserDialogPane2`. Registration-dialog and FunctionObjects modules are dependencies rather than alternate owners.

## Score Rationale

The page is now treated as a source-ready `NexusTK/login/` file because the proposed source tree lists `login/NewUserDialogPane2.cpp`, [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) is a non-emitting family index, and [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) records exact constructor, selector, submit, packet, caller, field, C++, and boundary evidence for this variant. UID00043M/UID00043N close the shift-method gap, while UID00043V/W/X/Y now provide exact primary/secondary callback ABI, Event routing, key/packet behavior, and no-notification proof. [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) and [UID:0002X3][g_pNewUserDialogPane2](by-global/g_pNewUserDialogPane2.md) add exact compiler-vtable and singleton evidence without becoming handwritten source.

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The file page records the complete class/source order, executable island, exact shift and selector families, submit validation, packet/reply helpers, inherited DialogPane manager, own field layout, vtable/singleton compiler split, launcher and neighboring-variant boundaries, exact child C++, non-emitting aggregate route, and UID00043X's exact bytes/hash/CFG/boundaries and adjusted-facet-to-human-source mapping. |
| Confidence | 95 | Current IDA-backed class/memory/global pages, catalog-0352 persisted readback, exact child callers, byte-identical Event packet-bridge precedent, vtable slot, Event UDT, and target bytes converge on ownership, ABI, packet extraction, opcode/result distinction, return contract, and tail dispatch. Remaining lexical uncertainty is explicitly isolated from the resolved bridge contract. |

## 2026-06-21 B010 Source-Quality Incorporation

- This file is the concrete source root for [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md), not an optional fold into the non-emitting [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) index.
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) now contains the first-draft method-body C++ for submit, opcode `0x02` account packet helper, opcode `0x04` create-character payload builder, and reply handler.
- Historical B010 source called `+0x27c` created-user-name storage. The current class declaration instead uses `m_nexonclubAccountName`, based on the exact registration callback producer and character-request consumer, while retaining selected-option fields, the two-phase reply flag, and `[[CHILDREN]]`.
- `g_pNewUserDialogPane2` and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) are the preferred source-facing singleton/packet globals; raw generated labels remain evidence aliases only.

## 2026-06-26 B004 Internal Split Implementation

- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) is an internal non-emitting split/index for `NewUserDialogPane2.cpp`; it is not a monolithic method-body emitter. The exact children split 18 modeled functions, one command jump table, one file-local helper, one IDA-unmodeled complete-destructor body, and two no-route raw helper islands.
- Most reconstructable children emit through [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md). The `0x0052bbc0-0x0052bdc5` account-packet helper emits through this file as file-local `SendCreateAccountRequest`; it must not be added to the class declaration.
- The three blank children are the complete-destructor raw body and the two raw selector-clear helpers. Their no-code proofs are based on `lookup_funcs`/xref/pointer-route/byte evidence, not unresolved naming.
- Corrected packet behavior for this file uses `PacketBuffer` source-facing wrappers around the observed packet-buffer append/send path, writes opcode `0x02` account requests with a trailing zero byte, writes opcode `0x04` character requests with selected shape bytes and `SizeWithoutTerminator`, and decodes replies from status `packet[1]` plus length/message at `packet+2`/`packet+3`.
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) is source-declared/generated-binary support after the 2026-07-04 B014 callback. It should be absent as a UID0002SH empty marker in generated `NexusTK/login/NewUserDialogPane2.cpp`; the class declaration and virtual method children are the source-bearing output.
- [UID:000445][0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail](by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md) records the adjacent tertiary vtable tail at `0x0061fd94-0x0061fd9c`; it is source-declared/generated-binary data regenerated from this file's class declaration and virtual method set.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md)

## Changes

- 2026-07-29 B004 UID00043X implementation callback: raised `92/94 -> 93/95`; added exact target size/hash/CFG, predecessor/padding boundaries, sole vtable xref, Event payload offset, opcode/result distinction, adjusted-facet compiler ABI, human-source method route, catalog-0352 applied state, and tail-return contract without duplicating the child formal body.

- 2026-07-29 B002 UID00043W implementation callback: retained file metadata at `92/94`; synchronized the exact OnControlCommand and EventHandler method family, source order, slots, Event/packet routes, key gates, command-only hover update, inherited fallbacks, and no-notification proof; updated all child paths; and historicalized the prior OnCommand/KeyEvent/direct-packet/notification source without pruning provenance.

- 2026-07-28 B003 UID0002X4 implementation callback: retained file metadata at `92/94`; established exact source positions `0/10/20` for semantic global, H-only class, and corrected constructor; incorporated loader-zero PE proof, direct Singleton RTTI/PMD and EBO layout, six-ref lifetime, one-definition/generated acceptance, and corrected historical `0xffffffff`/raw-name/explicit-publication assumptions without pruning prior evidence.

- 2026-07-22 B002 accepted UID00043T implementation callback:
  - Retained UID0000LW at `92/94`, owner `FILE`, reconstruction path `NexusTK/login/`, and blank file-level formal C++.
  - Replaced stale name-prompt/apply and created-user-name descriptions with the exact Nexonclub registration gate, account-result callback, and `m_nexonclubAccountName`.
  - Added exact ranges/hashes/padding, branch and callback construction/lifetime, id-227 resource provenance, account-field/packet route, sibling pair, negative reachability, module boundaries, rejected alternatives, and superseded history.

- 2026-07-22 B002 UID00043R implementation callback source-file sync:
  - Retained file metadata at `92/94` and preserved the complete existing source inventory.
  - Added exact male/female ranges, hashes, callers, constructor/command roles, PrettyButton/UserShape identities, button arguments, shape-bank calls, literal ordering, and negative evidence.
  - Historical generic helper, loop, and reselect source is now explicitly superseded instead of remaining as current behavior.

- 2026-07-22 B002 UID00043N implementation callback source-file completion:
  - Raised the file to `92/94` and synchronized the complete class-before-children order, inherited DialogPane manager route, own `+0x26c..+0x27c` layout, exact left/right shift behavior, and signed-short shape-step contract.
  - Preserved every constructor, selector, command, packet, reply, resource, singleton, raw-island, lifecycle, and compiler-exclusion fact from the B004/B010/B014 union.
  - Historicalized the duplicate-derived-manager and simplistic shift assumptions without removing their provenance.

- 2026-06-16 A001 Goal 2 file completion refresh:
  - Before: `85/86`, with a stale score-rationale table from an earlier `82/84` pass and an obsolete current-session MCP-unavailable caveat.
  - After: `86/88`; the score rationale and evidence notes now reflect the live IDA/PE refresh, and [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) is documented as a direct-class generated vtable child.
  - Summary/evidence: live IDA/PE checks reconfirmed constructor branches at `0x004f7ad0` and `0x004f9041`, submit/packet helper behavior at `0x0052b9f0`/`0x0052bbc0`, vtable/singleton references, and the neighboring `0x0052c360` boundary. Final C++ remains blank because field/helper names and standalone-versus-umbrella source placement still require source-quality inference.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Changed to: `88/89`.
  - Summary/evidence: incorporated non-emitting parent policy, concrete `NewUserDialogPane2.cpp` source ownership, child method-body C++ readiness, class declaration C++, field/helper candidates, singleton naming, and packet-helper alias rejection.
- 2026-06-26 B004 implementation sync:
  - Summary/evidence: incorporated the accepted internal split/index treatment for [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), exact child ownership, file-local `SendCreateAccountRequest`, raw island no-code proofs, corrected packet/reply source shape, and the `0x0061fd94-0x0061fd9c` tertiary vtable-tail support child.
- 2026-07-04 B014 UID0002SH vtable support sync:
  - Summary/evidence: synchronized the file page with UID0002SH's accepted non-reconstructable/non-emitting disposition, current `aa3930bd` MCP evidence, and generated-output expectation that class/method source remains in this file while compiler-generated vtable bytes are not hand-authored.
- 2026-06-07: Replaced raw create-character packet-send references with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the file role and submit-path evidence described the send path through historical `dword_67A7EC` only.
  - After: the page links the resolved packet sender while retaining the historical global for IDA traceability.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and the linked `NewUserDialogPane2CreateUserVariant` memory page records the payload send through that global.

- 2026-06-07 A010 evidence consolidation:
  - What existed before: scores were `80/82`; the page had correct login placement and broad method-family notes, but did not summarize the exact vtable data, singleton slot, launcher ownership boundary, or packet/reply evidence already present in linked pages.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: integrated [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md), [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md), and [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) into the file-source summary. IDA MCP was unavailable in this session, so no fresh live evidence was added and C++ remains blank.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: `82/84`.
  - After: `85/86`.
  - Evidence: live IDA MCP reconfirmed the exact singleton slot, item bounds, initial value, and all six xrefs. The page already links exact executable and vtable children, so the direct global parent for the split storage page can route through this file without violating the corrected `85/85` gate. C++ remains blank because field names and the final standalone-vs-umbrella split are still below the final reconstruction bar.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `74`, confidence `72`.
- Summary/evidence: the page documents the alternate create-character role, major method families, boundary distinctions, and cross-references; confidence is limited by final standalone-source split and the generated constructor/destructor naming issue.
- 2026-06-02 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `74/72`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, completion `80`, and confidence `82`.
  - Summary/evidence: the create-user umbrella, proposed source tree, aggregate memory page, and exact child memory page all place this alternate create-character dialog in the login/create-user source family.
