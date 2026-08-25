*** UID:0000IK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CreateUserDialogs

## Status

- Disposition: non-standalone create-user family/index page. It should not generate `CreateUserDialogs.cpp`.
- Confidence: `94/94`: strong for the complete family boundary, login/create-user placement, launcher reachability for the old and 640x480 variants, vtable/singleton ownership, the shared submit/packet/reply pattern, exact support disposition, and six concrete child source-file routes. Original private spellings and the retained `NewCreateUserDialogPane` direct-launch caveat remain bounded limits.
- Proposed module folder: none for this umbrella page; concrete source files remain under `login/`.
- Final source roots: `login/CreateUserDialogPane.{cpp,h}`, `login/NewCreateUserDialogPane.{cpp,h}`, `login/NewUserDialogPane2.{cpp,h}`, `login/NewUserShapeSelectControlPane.{cpp,h}`, `login/NewUserMiscDialogPane.{cpp,h}`, and `login/UserCreateAppearanceControls.{cpp,h}`.
- Source output belongs only to those six roots and their exact owner/support pages. A generated umbrella `CreateUserDialogs.cpp` or `CreateUserDialogs.h` is rejected.
- Evidence basis: generated source leads plus IDA MCP boundary/caller/decompile/xref/component/byte checks, accepted support reports, and the 2026-08-25 UID0000IK family-wide source-quality and generated-completeness review.

## Hypothesis

The create-user flow evolved across several UI generations. The original source layout likely kept the large dialog variants close together because they share password/name validation, gender/body/totem selection, shape preview, `ScreenDimmer` behavior, and the final create-user packet send.

Resolved reconstruction roots:

```text
login/CreateUserDialogPane.cpp
login/NewCreateUserDialogPane.cpp
login/NewUserDialogPane2.cpp
login/NewUserShapeSelectControlPane.cpp
login/NewUserMiscDialogPane.cpp
login/UserCreateAppearanceControls.cpp
```

`CreateUserDialogPane` is the `DLGNEW3` full-screen account/character creation dialog. Its older hair, face, color, body, and preview controls are standalone reusable source under [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). `NewCreateUserDialogPane` and `NewUserDialogPane2` are retained high-resolution and active alternate-resolution variants. `NewUserShapeSelectControlPane` is a standalone reusable body-shape preview selector. `NewUserMiscDialogPane` is final standalone [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md) source: the account-registration reply-success path constructs it at `0x004fa74e`, its packets use [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and it has no `CashShopRequest` ownership or dependency.

Do not place [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) in this create-character module by name alone. That class is the older account-registration/password dialog in the login/account family; `NewUserDialogPane2` is the create-character variant.

Keep [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) separate from this login/create-user family. It also uses human/head image data, but it is an in-game packet dialog with NPC, price, and message fields plus a paged head-selection grid.

Do not emit a standalone `CreateUserDialogs.cpp` from this page. [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) is now a non-emitting source-family split/index, and this by-file page is the matching family/index record. Exact class/file pages own the emitted code.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `CreateUserDialogPane` | `0x0052dd30-0x0052f710` plus lifecycle support in [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) | `class_CreateUserDialogPane.cpp` / `login/CreateUserDialogPane.cpp` | `DLGNEW3` create-user dialog, username/password fields, hair/face/body controls, gender selection, preview, submit, packet helpers, and reply handling through exact child pages under [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md). |
| `NewCreateUserDialogPane` | `0x0052c360-0x0052dcf5` plus shared lifecycle support in UID0002QU | `login/NewCreateUserDialogPane.cpp` / `.h` | Retained full-screen create-user dialog using `DLGNEW.EPF`, `GENDER.EPF`, `DIREC.EPF`, and `NEWBUTT.PAL`; the complete 16-slot source includes the exact constructor, selector/event methods, child-id-8 create-character sender, and no source for `nullsub_42`. No current constructor route was found, but coherent method/vtable/singleton evidence preserves the class. |
| `NewUserDialogPane2` | `0x0052a540-0x0052c325` plus shared lifecycle support in UID0002QU | `login/NewUserDialogPane2.cpp` / `.h` | Active alternate 640x480 create-user dialog using `DLGNEW02.EPD` and `NPAL3.PAL`, including the exact Nexonclub registration-or-send gate and account-result callback at `0x0052b650-0x0052b75c`; launcher edges are `0x004f7ad0` and `0x004f9041`. |
| `NewUserShapeSelectControlPane` | authored core `[0x004fd520,0x004fdd33)`; compiler support `[0x0050253a,0x00502550)` and `[0x00502a70,0x00502aab)`; vtable/RTTI `[0x0061d604,0x0061d6a8)` | `login/NewUserShapeSelectControlPane.cpp` / `.h` | Final standalone body-shape selector. [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) owns 13 CPP definitions, [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) owns exact size `0x11c` H, [UID:00050L][0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks](by-memory/0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks.md)/[UID:00050K][0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor](by-memory/0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor.md) are non-emitting compiler support, and [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) supplies the packed render descriptor. |
| `NewUserMiscDialogPane` | source methods/raw islands in `0x004fb630-0x004fccee`, with compiler lifecycle support at `0x005029f0` | `login/NewUserMiscDialogPane.cpp` / `.h` | Final standalone customization dialog. The exact indirect trigger is `0x004fa74e`; packets use `g_packetSender`; the constructor uses `g_mainUiLayerSlots.overlayPaneLayerContext`; authored destruction is `delete g_pScreenDimmer; g_pNewUserMiscDialogPane = 0;`, while compiler vptr/base/delete-flag lowering is excluded. |
| `UserShapeSelectControlPane` | `0x004fce80-0x004fd520`, including male/female bank methods `0x004fd030` / `0x004fd050` | `login/UserCreateAppearanceControls.cpp` / `.h` | Older body-shape preview/selection control reused by create-user-family dialogs; `0x004fcd80` is the neighboring SelectBox setter, `0x00501620`/`0x00501640` belong to UserHairSelectControlPane, and `0x0054b700` belongs to PrettyButtonControlPane. |
| `UserHairSelectControlPane` | `0x00501150-0x00501612` | `class_UserHairSelectControlPane.cpp` | Older hair thumbnail selector used by `CreateUserDialogPane`. |
| `UserFaceSelectControlPane` | `0x00501660-0x00501af2` | `class_UserFaceSelectControlPane.cpp` | Older face thumbnail selector used by `CreateUserDialogPane`. |
| `UserCreatePreviewControlPane` | `0x00501b40-0x00501e05`, retained helper `0x00501d80-0x00501dbc` | `class_UserCreatePreviewControlPane.cpp` | Final older create-user character preview pane, render-param builder, direction/update methods, and retained no-direct-xref base-preview update helper. |
| `UserHairColorSelectListPane` / `UserFaceColorSelectListPane` | `0x00501e10-0x00502383` | color-list class files | Older hair/face color swatch lists that call back into `CreateUserDialogPane`. |
| `UserCreateAppearanceControls` source root | authored controls in `0x004fce80-0x00502383`; compiler support separately documented | `login/UserCreateAppearanceControls.cpp` / `.h` | Standalone reusable appearance source: six class declarations in H positions `0/20/30/40/50/60`, 26 definitions plus shared table/type support in CPP order, and no handwritten scalar deleting wrappers or empty emitter marker. |
| [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) | `0x004f8fa0-0x004f9055` | not emitted standalone | Main-menu retained launcher that selects `CreateUserDialogPane` or `NewUserDialogPane2`; keep in `MainMenuPane.cpp`, not this dialog implementation file. |

## Corrected Appearance-Helper Ownership And Gender Callers

- [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md) owns exact `SetMaleShapeBank()` at `0x004fd030` and `SetFemaleShapeBank()` at `0x004fd050`. They write shape-bank values `0` and `1` at `+0x10e` and invalidate the control.
- [UID:00043R][0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode](by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md) calls the male bank method on UserShape children `8-11`; [UID:00043S][0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode](by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md) calls the female bank method on the same children.
- Both gender-selector ranges are 136 bytes. Their hashes are `318E714C08908DCE721179A703BFBCBED42A2FF353F4D0A7EE03A18D3176F109` and `F9C237761B1388EEF54ED332579E1FFF9715284DF6FBA40F0E81BAF00C1B0135`; constructor and command ids `4/5` are their only direct callers.
- `0x00501620` and `0x00501640` are [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) `SetMaleMode`/`SetFemaleMode`, called for old-dialog hair control id `6`. They must not be attributed to UserShape.
- `0x0054b700` is exact [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md). NewUserDialogPane2 gender selectors call it on button ids `4/5` before changing the four UserShape banks. It is not a UserShape `SetActive` method.
- Neither gender selector calls `SelectShapeSlot`, accesses `m_selectedShapeSlot`, loops, sends a packet, or notifies a parent. Historical broad-family inventory and generic helper/reselect source are explicitly superseded by exact child evidence.
- This family page remains non-emitting. Concrete class/file pages own all source bodies; these corrected associations are family-map evidence only.

## Replicated Nexonclub Registration Gate Pattern

- All three create-user variants retain a structurally identical boolean gate plus const-string callback:
  - [UID:00043T][0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md) / [UID:00043U][0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult](by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md) at `0x0052b650/0x0052b730`.
  - `NewCreateUserDialogPane` retained siblings at `0x0052d100/0x0052d1e0`.
  - [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) / [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md) at `0x0052e970/0x0052ea50`.
- Each gate tests one argument as a boolean. False sends the variant's character request; true allocates a 24-byte `PlainMemberFunctionObjectT`, binds its class callback, reads `g_pLanguageMan->GetLocalizedString(227)`, and constructs the 632-byte `NexonclubRegistrationDialog`.
- Current `baram.dat` `STR.RES` id `227` is `Please input nexon.com ID and password.` The callback payload is successful Nexonclub account-control text; nonempty text is stored in each variant's `+0x27c` `SimpleUString`, then the character request is sent.
- `NexonclubRegistrationDialog` owns registration behavior and callback storage/invocation/release. [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) owns reusable callback source. Each concrete create-user class owns only its binding method, callback, field, and packet consumer.
- Registration constructor `0x0052f950` has exactly four direct callers: the three create-user gates plus NexonclubProxyDialog. UID00043T has no current direct xref or pointer encoding, but exact source-level behavior and the two siblings preserve its source disposition.
- Historical NewUserDialogPane2 names `PromptCreateCharacterName`, `ApplyCreateCharacterName`, and `m_createdUserName` are superseded by `OpenNexonclubRegistrationOrSendCharacterRequest`, `OnNexonclubRegistrationResult`, and `m_nexonclubAccountName`. This family page records the relationship but remains non-emitting.

## Boundary And Data Notes

The complete modeled family inventory is 120 functions: 6 Misc functions, 11 old `UserShapeSelectControlPane` functions, 13 `NewUserShapeSelectControlPane` functions, 24 old appearance-control functions, and 66 functions across the three dialog variants and shared lifecycle island. The support inventory additionally includes Misc raw code islands, switch tables and padding; old/NewUser2 raw destructor and helper spans; selector adjustors and scalar deleting wrappers; vtable/RTTI blocks; four dialog singleton slots; packet, layer, screen, language and configuration dependencies; the 16-entry appearance color table; and exact resource names/IDs. These remain with their literal owner/support pages and do not create umbrella source output.

Excluded neighboring roots are `SelectBoxControlPane` at `[0x004fccf0,0x004fce80)`, `ChangePasswordDialogPane` from `0x004fdd40`, `BackStoryDialogPane` at `0x00502390`, generic `PrettyButtonControlPane` at `0x0054b700` except for its required header dependency, `NexonclubRegistrationDialog` at `0x0052f950`, and account-registration `NewUserDialogPane`. Shared globals, resources, vtables, singleton slots, compiler support and launcher bodies remain dependencies rather than content to move into this index.

The selector no longer has a fold/open-placement question. [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) is a concrete standalone source root, not content for this non-emitting family index. Its separate RTTI identity, method range, compiler-support islands, complete H contract, and explicit include from [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) outweigh its single known constructor consumer. This index preserves the family relationship but emits no selector body, declaration, wrapper, or raw vtable data.

The complete selector inventory is: class [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md), exact core [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), compiler adjustors [UID:00050L][0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks](by-memory/0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks.md), scalar deleting wrapper [UID:00050K][0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor](by-memory/0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor.md), packed [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md), and compiler-data subrange in [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md).

- IDA confirms the main create-user variant starts at `0x0052a540`, `0x0052c360`, `0x0052dd30`, `0x0052b9f0`, `0x0052d3e0`, and `0x0052ed80`.
- IDA confirms `NewUserShapeSelectControlPane` starts at `0x004fd520`, `0x004fd660`, `0x004fd910`, `0x004fd970`, `0x004fda30`, and `0x004fdc90`.
- 2026-05-24 IDA caller checks show `CreateUserDialogPane` is called from `0x004f7a82` and [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) at `0x004f8ff8`; `NewUserDialogPane2` is called from `0x004f7ad0` and the same open helper at `0x004f9041`.
- 2026-05-24 IDA caller checks show no direct callers for `NewCreateUserDialogPane::NewCreateUserDialogPane` at `0x0052c360`, but show `NewUserShapeSelectControlPane::NewUserShapeSelectControlPane` called from `0x0052c7aa` inside that constructor.
- IDA confirms older appearance-control starts at `0x004fcd80`, `0x004fce80`, `0x004fcfc0`, `0x00501150`, `0x00501660`, `0x00501b40`, `0x00501e10`, and `0x005020d0`. Constructor xrefs tie the hair/face/preview/color controls to `CreateUserDialogPane::CreateUserDialogPane`.
- 2026-06-19 B005 destructor-cluster recheck keeps old appearance-control destructor evidence under [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). `CreateUserDialogPane` constructs and coordinates the controls, but the scalar deleting destructor cluster [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md) is class/vtable support for the controls, not direct dialog-owned source logic.
- 2026-06-20 B005 preview-pane source-quality sync keeps [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md) under [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) and records [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) as the caller/coordinator. The old dialog constructs control id `0x12` at `0x0052e64b`, advances direction at `0x0052eafe` / `0x0052e730-0x0052e744`, refreshes face/hair/color/gender preview state at `0x0052eb68`, and queries `BuildPreviewParams` at `0x0052f1e8` for the create-character payload. The retained no-direct-xref preview helper `0x00501d80-0x00501dbc` belongs to the preview class, not to this umbrella page.
- The 2026-08-25 research observation confirms `NewUserMiscDialogPane::NewUserMiscDialogPane` at `0x004fb630` with caller `0x004fa74e` inside `0x004fa5b0`. The raw `0x004fbfd0-0x004fc00f` destructor lowering proves the exact two-statement authored cleanup; absence of a modeled function at that raw entry does not make the source root tentative.
- A dated Wave3 snapshot named the `0x0052a540` constructor row as `~NewUserDialogPane2`; its signature, behavior and exact child source establish it as the constructor. That stale label is evidence history, not source authority.
- A pre-callback recovered `class_CreateUserDialogPane.cpp` lead omitted methods including `SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, and `OnDialogShow`; exact owner/child pages and current generated receipts, rather than that historical lead, govern source completeness.
- IDA confirms [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) constructs either `CreateUserDialogPane` or `NewUserDialogPane2`, but direct xrefs to the helper are currently unresolved. Treat it as `MainMenuPane.cpp` launcher code.
- 2026-06-01 IDA MCP `py_eval` enumerates the executable create-user family as three method/helper clusters plus lifecycle glue: `0x0052a540-0x0052c325` (`NewUserDialogPane2`), `0x0052c360-0x0052dcf5` (`NewCreateUserDialogPane`), `0x0052dd30-0x0052f6e5` (`CreateUserDialogPane`), and `0x0052f710-0x0052f94c` singleton clear/thunk/deleting-destructor glue.
- 2026-06-01 IDA MCP decompilation confirms the three submit helpers at `0x0052b9f0`, `0x0052d3e0`, and `0x0052ed80` share the same validation shape: read three edit fields, require a digit in the password, compare confirmation with `wcscmp`, alert on failure, and call the local packet encoder on success.
- 2026-06-01 IDA MCP decompilation confirms the packet encoder/helper triplets at `0x0052bbc0/0x0052bdd0/0x0052bfd0`, `0x0052d5b0/0x0052d7c0/0x0052d9a0`, and `0x0052ef50/0x0052f160/0x0052f390`, all using [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC` send paths and create-user reply handling.
- 2026-06-01 IDA MCP xrefs tie vtables and singleton slots to the three variants: `0x0061fd04`/`0x0069b4a4` for `NewUserDialogPane2`, `0x0061fda0`/`0x0069b4a8` for `NewCreateUserDialogPane`, and `0x0061fe3c`/`0x0069b890` for `CreateUserDialogPane`.
- 2026-06-14 C001 live IDA MCP recheck on active `NexusTK.exe.i64` confirmed auto-analysis and Hex-Rays ready, then reconfirmed the main create-user starts/sizes: `0x0052a540` size `0xb07`, `0x0052c360` size `0x9e9`, `0x0052dd30` size `0x9bb`, the three submit validators at `0x0052b9f0`/`0x0052d3e0`/`0x0052ed80` size `0x1cc`, singleton clear helpers at `0x0052f710`/`0x0052f720`/`0x0052f730`, six `0xb`-byte adjustor thunks through `0x0052f772`, and the three scalar deleting destructors at `0x0052f800`/`0x0052f870`/`0x0052f8e0` size `0x6c`.
- 2026-06-14 C001 live xrefs reconfirmed constructor reachability for `NewUserDialogPane2` from `0x004f7ad0` and `0x004f9041`, constructor reachability for `CreateUserDialogPane` from `0x004f7a82` and `0x004f8ff8`, and no direct xrefs to `NewCreateUserDialogPane` at `0x0052c360`; this preserves the retained/newer-variant caveat while strengthening the old/new-launcher split.
- 2026-06-14 C001 live `analyze_function 0x004f8fa0` decompiled the retained main-menu open helper as a branch that calls `0x0052dd30` when `byte_66DA97 == 1` and calls `0x0052a540` otherwise after the shared 640-wide screen check. The helper still has no inbound xrefs, so it remains documented under [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) rather than this dialog implementation family.
- 2026-06-14 C001 live component analysis reconfirmed the three submit validators share the same callee shape and shared state (`word_60DB20`, `off_613A18`, `off_61E318`, `dword_67A750`, and `dword_67A7CC` where applicable), while the packet/reply helper triplets share `dword_67A7EC` / [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and internal reply-to-payload edges `0x0052bfd0 -> 0x0052bdd0`, `0x0052d9a0 -> 0x0052d7c0`, and `0x0052f390 -> 0x0052f160`.
- 2026-06-14 C001 live xrefs reconfirmed vtable refs at `0x0061fd04`, `0x0061fda0`, and `0x0061fe3c` from each variant's constructor/destructor family, singleton refs for `0x0069b4a4`, `0x0069b4a8`, and `0x0069b890`, one `NewUserShapeSelectControlPane` constructor xref from `0x0052c7aa`, and one `NewUserMiscDialogPane` constructor xref from `0x004fa74e`.
- 2026-06-14 C001 byte checks reconfirmed alignment before `0x0052a540`, `0x0052c360`, and `0x0052dd30`, the singleton-clear/thunk island bytes beginning after the old dialog core, and the `0x0052f94c-0x0052f950` `0xcc` padding before the `0x0052f950` `NexonclubRegistrationDialog` successor.

## 2026-06-20 B004 Old CreateUserDialogPane Sync

- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) is a source-owned old `CreateUserDialogPane` class page emitted through [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), not this umbrella. This page remains the create-user family/index page.
- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) is now a non-emitting 22-child split/index for the old DLGNEW3 branch: constructor, body/gender/color selectors, optional Nexonclub callback helper, command/key/show/reply handlers, submit validator, file-local opcode `0x02` account sender, opcode `0x04` appearance sender, two-phase reply handler, raw/no-code spans, nullsubs, and reply switch-table/padding.
- Old/new split remains: old `CreateUserDialogPane` has direct construction routes at `0x004f7a82` and `0x004f8ff8`; `NewUserDialogPane2` is a separate active sibling variant; `NewCreateUserDialogPane` remains retained/no-direct-constructor-route in current evidence. [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) should remain an aggregate/split index rather than owning one monolithic source body.
- Old-dialog field directions now used by the exact class/core pages are `m_initialAppearanceRoll` at `+0x26c` with a write-only/random-roll caveat, `m_bodyShapeIndex` at `+0x270`, `m_waitingForCharacterReply` at `+0x278`, `m_isFemale` at `+0x279`, and `m_createUserExtraText` at `+0x27c`. Reject generated `m_previewDirty` and `m_descriptionText` for these fields.
- Shared state names for old create-user evidence are canonicalized as `g_pLanguageMan`, `g_pScreenPane`, `g_packetSender`, `g_pConfig`, `DialogOkButtonString`, `g_pCreateUserDialogPane`, and shared empty wide string / `word_60DB20`. `off_61E318` is the password-digit alert text with binary typo `"password must containt at least 1 number"`; `word_61FF48` remains an unresolved fallback reply/success text.
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) is now documented as non-emitting compiler/lifecycle support: singleton clears, adjustor thunks, helper destructors, and scalar deleting destructor wrappers should be regenerated by the compiler from ordinary class declarations and destructors.

## 2026-06-21 B010 Non-Standalone Family Index

- This page now uses `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` because it is not an original standalone source root. It remains as a family/index and quarantine page to prevent a synthetic `CreateUserDialogs.cpp` from duplicating exact child output.
- Source ownership is child-only: [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) owns [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md); [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) owns [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) through [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md); and [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) / [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) own exact source children under [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md).
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) and generated vtable/singleton pages stay source-declared/generated-binary support. They should not emit handwritten scalar deleting destructor wrappers, adjustor thunks, or umbrella lifecycle C++.
- `NewCreateUserDialogPane` remains retained/no-direct-caller in this binary after xref and PE pointer/branch scans; this page keeps that source-evolution caveat while preserving the class because constructor/method/vtable/singleton evidence is coherent.

## 2026-06-26 B004 NewUserDialogPane2 Split Callback

- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) is now an internal non-emitting split/index under [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), not a direct monolithic method-body emitter.
- Exact child pages under [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) own the `NewUserDialogPane2.cpp` constructor, selectors, Nexonclub registration gate/callback, command/event, submit, file-local account-packet, create-character, reply, raw helper, and lifecycle-adjacent evidence. This page remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`.
- The file-local `0x0052bbc0-0x0052bdc5` helper is `SendCreateAccountRequest` in `NewUserDialogPane2.cpp`, not a `CreateUserDialogs` umbrella function and not a `NewUserDialogPane2` class method.

## 2026-06-26 B008 CreateUserDialogPane Split Callback

- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) is now aligned with the same split/index policy already used for [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md): the parent stays non-emitting and exact child pages carry formal C++ or no-code proof.
- The old-dialog callback fixes are `bool openRegistration`, `KeyEvent *event`, `const PacketEvent *event`, `event->payload`, file-local account helper ownership through [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), and reply payload decoding from `packet[1]`, `packet[2]`, and `packet + 3`.
- The `0x0052f6e5-0x0052f710` child accounts for the reply-handler switch table at `0x0052f6e8` plus padding before the destructor/thunk island; [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) still starts at `0x0052f710`.

## Migration Notes

Do not merge every `NewUser*` class into one file. The final six independent source roots are:

```text
login/CreateUserDialogPane.cpp
login/NewCreateUserDialogPane.cpp
login/NewUserDialogPane2.cpp
login/NewUserShapeSelectControlPane.cpp
login/NewUserMiscDialogPane.cpp
login/UserCreateAppearanceControls.cpp
```

Each root has a matching header route. `NewUserMiscDialogPane` is final standalone UID0000LX source: `0x004fa74e` is its indirect trigger, `g_packetSender` owns packet transmission, and `0x004fbfd0` proves its authored destructor. `NewUserDialogPane2` is an independent active variant, and `UserCreateAppearanceControls` is independent reusable source; neither may be folded into another dialog root.

This page is not itself one of those source files. It is the coordination record for the family and should remain non-emitting unless future source-tree evidence proves an actual umbrella translation unit.

## Cross-References

- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md)
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md)
- [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md)
- [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md)
- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md)
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md)
- [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)

## Changes

- 2026-08-11 B005 UID0000LY whole-file synchronization:
  - Finalized the selector `.cpp/.h` split and replaced the stale broad compiler range with exact authored, adjustor, scalar-wrapper, and vtable/RTTI boundaries.
  - Added the complete class/core/type/compiler inventory and explicit NewCreate consumer include route while preserving this page as a non-emitting family index.

- 2026-07-22 B002 accepted UID00043T family sync:
  - Retained this page at `90/89`, `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, and `CANONICAL_OWNER:NONE`; it remains a non-emitting family map.
  - Added the exact three-variant Nexonclub registration gate/callback pattern, id-227 resource role, account-text field/packet route, registration/template ownership boundaries, caller cluster, and UID00043T negative reachability.
  - Superseded the old NewUserDialogPane2 character-name prompt/apply interpretation without moving source into this umbrella.

- 2026-07-22 B002 UID00043R implementation callback family-map correction:
  - Kept UID0000IK at `88` completion and preserved its non-emitting family/index role.
  - Corrected UserShape ownership to exact `0x004fd030/0x004fd050`, routed `0x00501620/0x00501640` to UserHairSelectControlPane, and routed `0x0054b700` to UID0004E5 PrettyButtonControlPane.
  - Added exact UID00043R/UID00043S hashes, callers, child ids, call order, and no-reselect/no-loop/no-packet/no-notification evidence without moving source into this umbrella.

- 2026-06-07: Replaced the raw `dword_67A7EC` create-user packet-send reference with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the create-user packet encoder triplets were tied to the historical generated global only.
  - After: the page links the resolved packet sender while keeping the historical label for IDA traceability.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and this page's existing IDA evidence ties the three create-user submit helpers to shared packet-send paths.

### 2026-05-28 - Create-User Range Endpoint Corrected

- What existed before: the create-user dialog family was recorded as ending at `0x0052f94b`.
- What changed: the documented endpoint is now `0x0052f94c`.
- Why: IDA MCP reports `sub_52F8E0` ending at `0x0052f94c`; the byte at `0x0052f94b` is part of the final scalar deleting destructor return instruction.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: old/new create-user dialog generations, appearance controls, shape/misc variants, boundary/caller evidence, split recommendations, migration cautions, and endpoint correction are documented; confidence remains medium-high because exact original file split between variants and helper controls is still open.
- 2026-06-01 source path and score update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `86/78`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, `COMPLETION:88`, and `CONFIDENCE:82`.
  - Summary/evidence: IDA MCP function enumeration, decompilation, caller checks, vtable/singleton xrefs, and child memory-range splits now support this as the parent login/create-user source family page.
- 2026-06-14 C001 live evidence refresh:
  - What existed before: the page was scored `88/82` and still described the exact old/new/helper split at medium confidence despite several direct file pages and singleton children now clearing the strict gate.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:86`, stronger status wording, and current IDA MCP evidence for the launcher branches, function starts/sizes, submit/packet/reply component shape, vtable/singleton refs, shape/misc constructor edges, and boundary bytes.
  - Summary/evidence: active IDA 9.1 MCP session `b001_0002bd` reconfirmed the aggregate's boundaries and ownership map without changing final source placement or adding C++; confidence remains below final-audit level because `NewCreateUserDialogPane` still lacks a direct constructor xref and the final standalone-vs-folded source split is unresolved.
- 2026-06-20 B004 old-dialog support sync:
  - Changed to: `89/87`.
  - Summary/evidence: incorporated B004's old `CreateUserDialogPane` source-quality routing, field/control/packet/reply terminology, old/new split, canonical global names, generated destructor/thunk policy, and umbrella-vs-direct-owner separation.
- 2026-06-21 B010 non-standalone family-index reclassification:
  - Changed to: `90/89`, `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, and `CANONICAL_OWNER:NONE`.
  - Summary/evidence: B010 source-quality pass resolves the old umbrella-source ambiguity by making this page a non-emitting family/index. Concrete child source files own `CreateUserDialogPane`, `NewCreateUserDialogPane`, and `NewUserDialogPane2`; lifecycle/destructor/thunk support remains non-emitting generated-binary evidence.
- 2026-06-26 B004 support sync:
  - Summary/evidence: recorded that [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) is an internal 21-child split/index under `NewUserDialogPane2.cpp`, with exact child emitters/no-code pages and no standalone `CreateUserDialogs.cpp` output.
