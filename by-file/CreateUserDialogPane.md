*** UID:0000IJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CreateUserDialogPane

## Status

- Confidence: very strong for the complete old create-user source union, login placement, semantic-global/class/constructor ordering, direct Singleton hierarchy, exact physical/vtable compiler evidence, lifecycle ownership, and generated acceptance; stripped lexical helper/interface spellings remain bounded below-95 caps.
- Proposed module: `login/CreateUserDialogPane.cpp`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Historical recovered-source lead: `source-3/simroot_v2/class_CreateUserDialogPane.cpp`; use current by-* docs over this file where generated names conflict with source-quality evidence.
- Evidence basis: `simroot_v2` method anchors as historical leads plus current IDA MCP lookup/caller/callee/xref/decompile/disassembly, exact 2026-07-26 PE loader-zero/storage and RTTI/PMD/EBO reanalysis, complete vtable/COL inventory, and current by-* source children. Current evidence supersedes old all-ones/file-local assumptions.

## File Role

`CreateUserDialogPane.cpp` should own the older `DLGNEW3` create-user dialog: username/password fields, gender/body selection, hair/face controls, preview pane, validation, two-stage create-user/create-character packet submission, and server-reply handling.

The older hair/face/color/preview controls may either live here or in [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) depending on final source size. The controls call back into `CreateUserDialogPane::SetHairColorIndex` and `CreateUserDialogPane::SetFaceColorIndex`, but the selected color fields belong to the dialog/selector state, not to the control classes.

Keep [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) separate despite the similar name; it is the account-registration/password dialog. The create-character variants are [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) and [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md).

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x0052dd30-0x0052e6eb` | constructor child | Builds `DLGNEW3`, text edits, gender/body controls, older hair/face selectors, color lists, preview pane, and final dialog activation. Direct `Singleton<CreateUserDialogPane>` base initialization generates publication; authored source does not assign the global explicitly. |
| `0x0052e6f0-0x0052e75e` | raw/no-code constructor-adjacent children | Constructor cleanup/fallback, preview-direction tail helper, and write-only `+0x26c` raw setter-shaped body; all are blank formal C++ with no-code proof. |
| `0x0052e770-0x0052e96f` | selection helpers | Updates body, gender, hair-color, and face-color state. Gender helpers do not refresh preview directly; color setters write selector `+0x10d` and return the argument without invalidate/refresh. |
| `0x0052e970-0x0052ea7c` | optional Nexonclub registration/callback helpers | [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) is an exact retained `bool openRegistration` method with false-path character request and true-path three-parameter `PlainMemberFunctionObjectT` construction, language id `227`, and callback ownership transfer; [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) stores non-empty result text at `+0x27c` and sends unconditionally. |
| `0x0052ea80-0x0052ed11` | command/key/show/packet handlers and nullsub | Handles dialog commands, `KeyEvent *event`, exact UID00046S `HandlePacketEvent(Event *event)` through secondary slot `+0x10`, dialog show delegation, no-code nullsubs, and preview refresh/advance dispatch. The packet bridge reads Event packet data at `+0x0c`, accepts opcode `0x02`, returns false otherwise, and tail-returns the reply handler. |
| `0x0052ed80-0x0052f6e5` | submit, packet, and reply path | Validates create-user fields, calls the file-local opcode `0x02` account helper, sends opcode `0x04`, and handles two-phase server replies through `m_waitingForCharacterReply` using `packet[1]`, `packet[2]`, and `packet + 3`. |
| `0x0052f6e5-0x0052f710` | reply switch table and padding | Compiler switch table beginning at `0x0052f6e8` plus padding before [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md); blank formal C++. |
| `0x0052f800-0x0052f86b` | scalar deleting destructor wrapper | Compiler-generated wrapper relationship to the ordinary `CreateUserDialogPane` destructor; do not hand-author it as source. |

Exact old-dialog coverage now flows through [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md), a non-emitting 22-child split/index. Source-authored children emit the constructor, selector handlers, submit path, file-local account helper, payload builder, and reply handler; raw cleanup/null/switch-table children carry blank formal C++ and no-code proof. [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) still owns singleton clear helpers, adjustor thunks, helper destructors, and the three create-user scalar deleting destructors.

## 2026-06-20 B004 Source-Quality Incorporation

- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) is the source-owned old `CreateUserDialogPane` class page, not an aggregate over all create-user dialogs. Its complete declaration now emits through H at source position `10`, CPP is blank, and `[[CHILDREN]]` follows the class for exact executable implementations.
- Keep [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) as the non-emitting family/index page and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) as the non-emitting split/index range. Direct class/source ownership for the old DLGNEW3 branch remains here.
- The old/new create-user split is explicit: `CreateUserDialogPane` has direct construction routes at `0x004f7a82` and `0x004f8ff8`; `NewUserDialogPane2` is a separate active sibling; `NewCreateUserDialogPane` remains a distinct retained/no-direct-constructor-route sibling unless later route evidence changes.
- Source-facing field directions for the old dialog are `m_initialAppearanceRoll` at `+0x26c` with a write-only/random-roll caveat, `m_bodyShapeIndex` at `+0x270`, `m_waitingForCharacterReply` at `+0x278`, `m_isFemale` at `+0x279`, and `SimpleUString m_createUserExtraText` at `+0x27c`.
- The core method inventory is constructor `0x0052dd30`, `SelectBodyShape`, `SelectMale`, `SelectFemale`, `SetHairColorIndex`, `SetFaceColorIndex`, [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) `OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)` with an exact C++03 three-parameter member-callback construction, [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) `OnNexonclubRegistrationResult`, `OnDialogAction`, `OnKeyEvent(KeyEvent *event)`, [UID:00046S][0x0052ecd0-0x0052ecf6.CreateUserDialogPaneHandlePacketEvent](by-memory/0x0052ecd0-0x0052ecf6.CreateUserDialogPaneHandlePacketEvent.md) `HandlePacketEvent(Event *event)`, `OnDialogShow`, `SubmitCreateUser`, file-local/free `SendCreateAccountRequest`, `SendCreateCharacterRequest`, and `HandleCreateUserReply`. Nullsubs/raw helpers/switch data are no-code child pages, not source declarations.
- UID00046S is exactly 38 bytes with SHA256 `B8CDCBD9D1881904B8BBDFD194B737C15FFEAA73A59F52B250E14D1C5803DB4B`, sole inbound vtable cell `0x0061feac`, Event packet data at `+0x0c`, no null guard, false mismatch return, raw EventHandler facet at complete-object `+0xa0`, compiler `-0xa0` complete-object recovery, and a tail jump to `HandleCreateUserReply`. UID00046S owns the CPP body; UID00003B owns the H declaration and Event forward declaration.
- Submit and reply flow: control ids `1/2/3` are account/password/confirmation edits; the missing-digit failure uses `off_61E318` with binary typo `"password must containt at least 1 number"`; mismatch uses language id `90`; `DialogOkButtonString` supplies the alert OK label; opcode `0x02` sends the account/create-user request; opcode `0x04` sends the appearance/create-character request; first-stage success caches the account/username through `g_pConfig`; and `word_61FF48` remains only a tentative fallback reply/success text name.
- Global dependencies are canonicalized as `g_pLanguageMan`, `g_pScreenPane`, `g_packetSender`, `g_pConfig`, `g_sharedEmptyWideStringLiteral` / `word_60DB20`, `DialogOkButtonString`, and `g_pCreateUserDialogPane`.
- Vtable/singleton policy: semantic [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md) owns the sole source definition at position `0`. Physical [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md), compiler [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md), and callback support [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) are false/non-emitting evidence. [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) stays compiler/lifecycle support for Singleton clears, adjustor thunks, helper destructors, and scalar deleting destructor wrappers.
- `source-3/simroot_v2/class_CreateUserDialogPane.cpp` remains a lead only: it uses generated-style names, omits real methods (`SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, `OnDialogShow`, and the secondary reply bridge), misnames `+0x278`/`+0x27c`, and does not separate source code from scalar-deleting/vtable mechanics.

## 2026-06-20 B005 Preview-Control Route Sync

- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md) is still part of [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), but this old-dialog file owns the caller/coordinator code that constructs and drives it through control id `0x12` / decimal `18`.
- Constructor setup at `0x0052e64b` builds the preview pane from old face/hair selector state: face frame from the face selector's gender-indexed face-id bank, hair frame from the hair selector's `m_hairPartFrames[m_genderStyle][m_selectedHairSlot]` table using index `selectedHair + 18 * hairStyle`, face and hair color bytes from selector `+0x10d`, the dialog gender byte at `+0x279`, the bounds pointer, and a trailing zero reserved ABI argument. The preview constructor's `ret 0x1c` proves the unused argument remains binary-visible.
- The action path advances preview direction at `0x0052eafe`, while raw helper `0x0052e730-0x0052e744` fetches control id `0x12` and tail-jumps to `UserCreatePreviewControlPane::AdvanceDirection`.
- The old dialog refreshes the preview at `0x0052eb68` through `UserCreatePreviewControlPane::UpdatePreview` after face, hair, color, and gender changes, then queries the same pane at `0x0052f1e8` through `BuildPreviewParams` for the create-character appearance payload.
- `SelectBodyShape` remains this dialog's separate body-button state and must not be confused with the preview pane's face/hair/color/gender/direction fields.

## 2026-06-21 B009 Hair-Selector Route Sync

- B009 adds the old-dialog control id `6` constructor evidence for [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md): allocation `0x16c`, bounds `{170,342,926,477}`, `selectedHair = rand() % 10`, `hairColor = 12`, `genderStyle = 0`, and control flag `0`.
- `SetHairColorIndex` writes the selector color byte at `+0x10d`, while `SelectMale`/`SelectFemale` call the out-of-line selector helpers at `0x00501620`/`0x00501640` to set hair style/gender bank `+0x10c`.
- Preview setup reads the hair frame through the selector's two-bank table and passes the resolved frame id into [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md); do not describe this as the raw selected hair slot plus gender stride.

## 2026-06-21 B010 Family Reconciliation

- B010 confirms this file is the concrete old-dialog source root after [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) were reclassified as non-emitting family/index pages.
- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) is now a non-emitting split/index; its exact child pages are the old-dialog method-body emitters or no-code proof pages. [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) remains compiler-generated lifecycle support.

## 2026-06-26 B008 CreateUserDialogPane Core Split Implementation

- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) is a blank-C++ parent split/index. Its 22 children separate source-authored constructor/method/helper ranges from constructor cleanup, no-route raw helpers, nullsubs, and the `0x0052f6e8` reply switch table/padding.
- Source-authored class children emit through [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md). The file-local opcode `0x02` helper at `0x0052ef50-0x0052f155` emits through this file root as `namespace { void SendCreateAccountRequest(...) }`.
- The accepted source shape uses `bool openRegistration`, `KeyEvent *event`, `HandlePacketEvent(Event *event)`, `event->m_payload.m_packet.m_data`, bridge opcode `packet[0]`, reply status `packet[1]`, message length `packet[2]`, and message bytes `packet + 3`. Do not reintroduce `PacketEvent`, raw event-buffer casts, a null guard, adjusted-this arithmetic, or a class-static account helper.
- The executed B015/B008 `OnCreateUserReplyEvent(const PacketEvent *)` conclusion is preserved as superseded history. Their exact UID00046S binary behavior, UID0002QT split, ownership, and boundary evidence remain valid; only the stale custom-name/type/payload inference is displaced by current EventHandler/Event evidence.
- `word_61FF48` is decoded as UTF-16 `U+C091 U+C0AC U+B9AC U+0021`; the final original source variable name remains a caveat and is represented by the source-facing `kCreateUserCompleteMessage` in the reply child C++.
- The direct old-dialog constructor routes at `0x004f7a82` and `0x004f8ff8` do not collapse the sibling `NewUserDialogPane2` and retained `NewCreateUserDialogPane` source files; those variants own their exact child pages.

## 2026-07-26 Semantic Global, Header, And Compiler Split

- [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md) emits the sole externally linked `CreateUserDialogPane *g_pCreateUserDialogPane = 0;` definition at position `0`, preceded only by `class CreateUserDialogPane;`. Its H channel is blank.
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) emits at position `10`: CPP blank; H contains one forward declaration, one `extern`, direct `DialogPane` plus `Singleton<CreateUserDialogPane>` inheritance, the complete `0x280` class declaration, and `[[CHILDREN]]`.
- [UID:00046E][0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor](by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md) emits at position `20`. Its initializer uses direct `Singleton<CreateUserDialogPane>()` and zeroes only `m_waitingForCharacterReply` early; no explicit global publication or unobserved early appearance/body/female zero stores remain.
- Exact class-method and file-local helper children under [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) preserve their existing ordered positions and complete behavior. Raw cleanup, nullsub, switch/padding, adjustor, scalar-wrapper, and callback-vtable pages remain no-code compiler evidence.
- [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md) is loader-zeroed physical backing and false/non-emitting. [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md) is the exact 36-slot/three-COL compiler block and false/non-emitting.
- The complete source union remains: global definition; class header; constructor; body/gender/hair/face selection; Nexonclub callback route; dialog action/key/reply/show handlers; validation; account packet helper; character payload; two-stage reply logic; appearance-control collaborators; and exact compiler/no-code exclusions.

### Generated Acceptance Criteria

- `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` contains exactly one `CreateUserDialogPane *g_pCreateUserDialogPane = 0;` definition at the beginning of the source route and no duplicate global definition.
- `auto-generated/NexusTK/login/CreateUserDialogPane.h` contains the accepted class declaration with direct Singleton base, one extern, and no method bodies that belong in CPP.
- Constructor source follows the corrected direct-base/observed-store preamble at position `20` while preserving the accepted remainder and later random appearance assignments.
- UID0002B3 and UID0002SI emit no empty markers. Existing exact method children remain coded through UID00003B/UID0000IJ, and false compiler-support pages do not inject raw vtables, vptr stores, EH cleanup, deleting flags, or frees.

## Evidence Notes

- IDA MCP confirms `0x0052dd30` as a `0x9bb`-byte constructor and `0x0052ed80` as a `0x1cc`-byte submit helper.
- IDA MCP caller checks show constructor calls from `0x004f7a82` and [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) at `0x004f8ff8`.
- Historical generated-output caveat: older active output omitted methods listed by class metadata (`SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, and `OnDialogShow`). Current generated `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` now declares and emits those methods; UID00046T emits `CreateUserDialogPane::OnDialogShow(int reason)` with `DialogPane::OnDialogShow(reason)`, while the class/memory docs remain the evidence source for exact method semantics.
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) is attached to this file page and links the old-dialog core, destructor/thunk island, [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md), and [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md).
- 2026-06-03 IDA MCP recheck confirms the old-dialog method island used by this source page: constructor `0x0052dd30`, body/gender helpers `0x0052e770`, `0x0052e850`, and `0x0052e8c0`, color setters `0x0052e930` and `0x0052e950`, command dispatcher `0x0052ea80`, submit validator `0x0052ed80`, packet/payload helpers `0x0052ef50`, `0x0052f160`, response handler `0x0052f390`, singleton clear `0x0052f710`, adjustor thunks `0x0052f73b`/`0x0052f746`, and scalar deleting destructor `0x0052f800`.
- 2026-06-03 IDA MCP xrefs confirm `0x0061fe3c` vtable references from constructor/destructor code and `0x0069b890` singleton references from the constructor, cleanup helper, and scalar deleting destructor. This ties the class, vtable data, and singleton slot to the same source module.
- Historical 2026-06-07 text reported a four-byte `dword_69B890` initialized as `ff ff ff ff`. Fresh 2026-07-26 live IDA reads `00 00 00 00`, and exact PE raw/virtual section math proves loader-zero storage with no raw file bytes. The five direct refs remain exact at `0x0052dd87`, `0x0052dd8e`, `0x0052e71a`, `0x0052f710`, and `0x0052f82d`; direct Singleton RTTI/PMD/EBO now supplies the corrected human-source cause.
- 2026-06-03 IDA MCP decompilation confirms the omitted color setters are real source-level methods called by the older hair/face color-list controls, and confirms the submit validator reads the name/password/confirmation controls, enforces the password digit rule, compares confirmation with `wcscmp`, reports failures through alert panes, and calls `0x0052ef50` on success.
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) remains the practical split candidate for older shape/hair/face/preview/color-list controls, but its xref evidence keeps those controls tightly coupled to this constructor and its color setter callbacks.

## 2026-06-14 C001 IDA MCP Refresh

- Current IDA MCP health reports active database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed the old-dialog inventory: constructor `0x0052dd30` size `0x9bb` / 2491 bytes, submit validator `0x0052ed80` size `0x1cc` / 460 bytes, packet encoder `0x0052ef50` size `0x205` / 517 bytes, appearance payload builder `0x0052f160` size `0x22d` / 557 bytes, reply handler `0x0052f390` size `0x355` / 853 bytes, singleton clear `0x0052f710` size `0x0b`, and scalar deleting destructor `0x0052f800` size `0x6c`. Size conversions were verified with `tools/int_convert.py`.
- The current component analysis keeps `0x0052dd30` as the constructor/interface entry and records internal edges from the command dispatcher to selector helpers and `0x0052ed80`, from the submit validator to `0x0052ef50`, and from the reply handler to `0x0052f160`.
- Constructor callees still include the old appearance-control and preview-control construction family, including `0x00501150`, `0x00501660`, `0x00501b40`, `0x00501e10`, `0x005020d0`, and `0x004991f0`, which supports keeping this page tied to the old create-user dialog while retaining the [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) split caveat.
- `xrefs_to` reconfirmed constructor callers at `0x004f7a82` and `0x004f8ff8`, the submit call from `0x0052ea80`, the packet call from `0x0052ed80`, vtable refs through `0x0061fe3c`, and singleton refs at `0x0052dd87`, `0x0052dd8e`, `0x0052f710`, and `0x0052f82d`.
- `find_regex` found `CreateUserDialogPane`, `Singleton<CreateUserDialogPane>`, and the related `PlainMemberFunctionObjectT<...CreateUserDialogPane...>` RTTI strings at `0x00677fd0`, `0x00677ff4`, and `0x006781e8`, confirming the current IDA class identity for this old-dialog branch.

## 2026-07-22 B003 Registration Callback Source Closure

- [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) now carries the exact 212-byte method evidence and `92/94` source-quality state. The target has zero recovered inbound xrefs/pointer hits, but two same-shaped create-user helpers corroborate the retained source-method pattern.
- The false branch calls `SendCreateCharacterRequest`. The true branch allocates a 24-byte callback, uses `g_pLanguageMan->GetLocalizedString(227)`, allocates a 632-byte `NexonclubRegistrationDialog`, and transfers the callback.
- Compiler metadata and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) require `PlainMemberFunctionObjectT<TMember, TObject, TArg>`. The target formal therefore uses a local pointer-to-member typedef, `CreateUserDialogPane`, and `const SimpleUString &`; the prior two-argument shorthand and older `void *context` form are historical/rejected.
- [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) is the exact non-reconstructable/non-emitting callback locator/vtable child. Its source-generation route is the shared FunctionObjects declaration plus the concrete UID00046O binding; no raw dword table belongs in this file.
- `NexonclubRegistrationDialog` stores the callback at `+0x26c`, invokes it on cancel/success, and releases it in its destructor. [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md), now `90/93`, stores non-empty text in `m_createUserExtraText` at `+0x27c` and sends unconditionally.
- Preserve observed allocation behavior: do not add explicit callback/dialog null guards, cleanup, smart pointers, exception wrappers, or modern callback types. The compiler EH funclets are lowering artifacts outside the human source method.
- Original private/local/parameter spellings, the literal for language id `227`, and the absent direct caller remain bounded below-95 caveats; they do not change this file's owner route or justify decompiler-style code.

## Score Rationale

The page is `93/94` because the complete old-dialog source union, exact child split, semantic global at position 0, class H at 10, corrected constructor at 20, direct Singleton/PMD/EBO cause, loader-zero physical slot, complete three-view vtable/COL block, lifecycle/thunk exclusions, UID00046S Event packet bridge hash/CFG/slot/receiver/return contract, packet/reply/callback/appearance behavior, and generated acceptance are documented. Confidence remains below 95 only for stripped original lexical spellings such as a few unrelated helpers and the exact historical name of `word_61FF48`, not for ownership, source placement, bridge ABI, or emission topology.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md)
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md)
- [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md)
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)

## Changes

- 2026-07-29 B004 UID00043X support implementation callback:
  - Raised `92/93 -> 93/94`; synchronized UID00046S's renamed Event-based path, exact body/hash/CFG, vtable slot, payload offset, no-null behavior, opcode/result separation, facet adjustment, false/tail return, UID00046S CPP and UID00003B H placement, and superseded PacketEvent history.
  - Preserved `NexusTK/login/`, file ownership, the complete old-dialog source union, all unrelated child routes, and generated/compiler exclusions. This file page has no formal CPP/H channel and received no invented one.

- 2026-07-26 B003 accepted UID0002B3/UID0002SI callback:
  - Raised `88/89 -> 92/93`; added semantic global position 0, class H position 10, corrected constructor position 20, complete source union and generated acceptance; corrected all-ones/file-local/publication assumptions; and reclassified UID0002B3/UID0002SI as false/non-emitting physical/compiler evidence with no remaining empty markers expected.

- 2026-07-22 Agent-B003 UID00046O Rule 26 support sync:
  - Kept file metadata `88/89`, `CANONICAL_OWNER:FILE`, and `NexusTK/login/CreateUserDialogPane.cpp`.
  - Incorporated the exact UID00046O/UID00046P callback type, construction, ownership/lifetime, generated-support, allocation-failure, no-entry/sibling, historical correction, and source-shape evidence without duplicating method bodies at file level.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: old create-user dialog role, method-family ranges, construction callers, active generated-output omissions, umbrella relationships, and helper-control split caveats are documented; confidence is capped by the unresolved split from appearance controls and newer dialog variants.
- 2026-06-03 MCP verification and projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `80/76`, leaving it in projected-path cleanup and below the 80-confidence parent-attachment threshold.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, `COMPLETION:82`, and `CONFIDENCE:80`.
  - Summary/evidence: fresh IDA MCP lookup, caller/callee, xref, decompile, and disassembly checks confirmed the method island, constructor callers, vtable/singleton ownership, omitted color setters, submit validation, packet handoff, and destructor thunk shape. Confidence remains capped at 80 because exact source split from appearance controls and final field/helper naming still need reconstruction-grade review.
- 2026-06-07 A010 class/core synchronization:
  - What existed before: the page was scored `82/80` and captured the old-dialog method island, but did not yet link the exact old-dialog child page, lifecycle/thunk island, vtable data page, singleton-slot page, or class-parent synchronization.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`, exact child coverage links, class/vtable/singleton evidence notes, and a score rationale describing why helper-control split risk still caps the page.
  - Summary/evidence: synchronized file-level documentation with existing [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md), [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md), and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) evidence; no new live IDA facts were introduced.
- 2026-06-07 A001 Batch 045 parent-gate refresh:
  - What existed before: the page was scored `84/84`, just below the corrected child-and-parent assignment gate for the exact singleton-slot memory page.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`, and added the live `0x0069b890` singleton bytes/xrefs/function-family evidence.
  - Summary/evidence: current IDA confirms the singleton is file-local `CreateUserDialogPane` lifecycle state, so this page now clears the direct-parent gate for [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md).
- 2026-06-14 C001 Goal 2 score pass: Raised `85/85 -> 87/87`.
  - Summary/evidence: current IDA 9.1 MCP reconfirmed method sizes, constructor callers, submit/packet/reply internal edges, vtable/singleton xrefs, create-user RTTI strings, and the continued old-dialog-to-appearance-control coupling. No owner/emitter route changed.
- 2026-06-20 B004 Rule 26 source-quality incorporation: Raised `87/87 -> 88/89`.
  - Summary/evidence: synced the file root to the B004 class report: old DLGNEW3 class ownership, method inventory, field/control naming, submit/packet/reply/literal flow, canonical global names, old/new variant split, simroot caveats, vtable/singleton generated-data policy, and compiler destructor/thunk no-code policy. [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) now emits declaration-level first-draft C++ through this file root.
- 2026-06-21 B010 family split reconciliation:
  - Score unchanged.
  - Summary/evidence: recorded the non-emitting status of the create-user family/index pages and reaffirmed this file as the old-dialog source root with method bodies carried by exact children under [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md).
