*** UID:0000IK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CreateUserDialogs

## Status

- Confidence: strong for the create-user dialog family; medium for exact file split between old, new, and helper control implementations.
- Proposed module folder: `login/`
- Proposed source files: `login/CreateUserDialogPane.cpp`, `login/NewCreateUserDialogPane.cpp`, `login/NewUserDialogPane2.cpp`, and possibly `login/NewUserShapeSelectControlPane.cpp` / `login/NewUserMiscDialogPane.cpp`
- Current generated sources: `class_CreateUserDialogPane.cpp`, `class_NewCreateUserDialogPane.cpp`, `class_NewUserDialogPane2.cpp`, `class_NewUserMiscDialogPane.cpp`, `class_NewUserShapeSelectControlPane.cpp`, and the old appearance-control sources covered by [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Evidence basis: generated source as a lead plus IDA MCP boundary/caller/decompile/xref checks through 2026-06-01.

## Hypothesis

The create-user flow evolved across several UI generations. The original source layout likely kept the large dialog variants close together because they share password/name validation, gender/body/totem selection, shape preview, `ScreenDimmer` behavior, and the final create-user packet send.

Recommended initial reconstruction grouping:

```text
login/CreateUserDialogPane.cpp
login/NewCreateUserDialogPane.cpp
login/NewUserDialogPane2.cpp
login/NewUserShapeSelectControlPane.cpp
```

`CreateUserDialogPane` is the `DLGNEW3` full-screen account/character creation dialog. Its older hair, face, color, body, and preview controls are now documented as [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). `NewCreateUserDialogPane` and `NewUserDialogPane2` are newer/high-resolution and alternate-resolution variants. `NewUserShapeSelectControlPane` is a reusable body-shape preview selector used by the new create-user dialogs. `NewUserMiscDialogPane` may be a companion customization/misc-settings dialog; IDA confirms its constructor and indirect message-wrapper path, but it currently uses `CashShopRequest` packet helpers and needs a focused owner review before merging.

Do not place [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) in this create-character module by name alone. That class is the older account-registration/password dialog in the login/account family; `NewUserDialogPane2` is the create-character variant.

Keep [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) separate from this login/create-user family. It also uses human/head image data, but it is an in-game packet dialog with NPC, price, and message fields plus a paged head-selection grid.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `CreateUserDialogPane` | `0x0052dd30-0x0052f86b` | `class_CreateUserDialogPane.cpp` | `DLGNEW3` create-user dialog, username/password fields, hair/face/body controls, gender selection, preview, submit. |
| `NewCreateUserDialogPane` | `0x0052c360-0x0052f8db` | `class_NewCreateUserDialogPane.cpp` | Newer full-screen create-user dialog using `DLGNEW.EPF`, `GENDER.EPF`, `DIREC.EPF`, and `NEWBUTT.PAL`. |
| `NewUserDialogPane2` | `0x0052a540-0x0052f94c` | `class_NewUserDialogPane2.cpp` | Alternate 640x480 create-user dialog using `DLGNEW02.EPD` and `NPAL3.PAL`. |
| `NewUserShapeSelectControlPane` | `0x004fd520-0x00502aaa` | `class_NewUserShapeSelectControlPane.cpp` | Body-shape selector and animated preview control used by new create-user UI. |
| `NewUserMiscDialogPane` | `0x004fb630-0x00502a60` | `class_NewUserMiscDialogPane.cpp` | Misc/customization dialog with gender/shape/style controls and packet send; final owner is still under review. |
| `UserShapeSelectControlPane` | `0x004fcd80-0x004fd520`, `0x00501620`, `0x00501640`, `0x0054b700` | `class_UserShapeSelectControlPane.cpp` | Older body-shape preview/selection control reused by create-user-family dialogs. |
| `UserHairSelectControlPane` | `0x00501150-0x00501612` | `class_UserHairSelectControlPane.cpp` | Older hair thumbnail selector used by `CreateUserDialogPane`. |
| `UserFaceSelectControlPane` | `0x00501660-0x00501af2` | `class_UserFaceSelectControlPane.cpp` | Older face thumbnail selector used by `CreateUserDialogPane`. |
| `UserCreatePreviewControlPane` | `0x00501b40-0x00501e05` | `class_UserCreatePreviewControlPane.cpp` | Final older create-user character preview pane. |
| `UserHairColorSelectListPane` / `UserFaceColorSelectListPane` | `0x00501e10-0x00502383` | color-list class files | Older hair/face color swatch lists that call back into `CreateUserDialogPane`. |
| [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) | `0x004f8fa0-0x004f9055` | not emitted standalone | Main-menu retained launcher that selects `CreateUserDialogPane` or `NewUserDialogPane2`; keep in `MainMenuPane.cpp`, not this dialog implementation file. |

## Boundary And Data Notes

- IDA confirms the main create-user variant starts at `0x0052a540`, `0x0052c360`, `0x0052dd30`, `0x0052b9f0`, `0x0052d3e0`, and `0x0052ed80`.
- IDA confirms `NewUserShapeSelectControlPane` starts at `0x004fd520`, `0x004fd660`, `0x004fd910`, `0x004fd970`, `0x004fda30`, and `0x004fdc90`.
- 2026-05-24 IDA caller checks show `CreateUserDialogPane` is called from `0x004f7a82` and [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) at `0x004f8ff8`; `NewUserDialogPane2` is called from `0x004f7ad0` and the same open helper at `0x004f9041`.
- 2026-05-24 IDA caller checks show no direct callers for `NewCreateUserDialogPane::NewCreateUserDialogPane` at `0x0052c360`, but show `NewUserShapeSelectControlPane::NewUserShapeSelectControlPane` called from `0x0052c7aa` inside that constructor.
- IDA confirms older appearance-control starts at `0x004fcd80`, `0x004fce80`, `0x004fcfc0`, `0x00501150`, `0x00501660`, `0x00501b40`, `0x00501e10`, and `0x005020d0`. Constructor xrefs tie the hair/face/preview/color controls to `CreateUserDialogPane::CreateUserDialogPane`.
- IDA confirms `NewUserMiscDialogPane::NewUserMiscDialogPane` at `0x004fb630`, with a caller at `0x004fa74e` inside `0x004fa5b0`; IDA does not currently define a function at Wave3's `NewUserMiscDialogPane::~NewUserMiscDialogPane` start `0x004fbfd0`, although the bytes are destructor-shaped and the next confirmed method starts at `0x004fc010`.
- Wave3 currently names the `0x0052a540` constructor row as `~NewUserDialogPane2` while the signature and generated source are constructor-like.
- `class_CreateUserDialogPane.cpp` omits several methods that `inspect class CreateUserDialogPane` lists, including `SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, and `OnDialogShow`.
- IDA confirms [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) constructs either `CreateUserDialogPane` or `NewUserDialogPane2`, but direct xrefs to the helper are currently unresolved. Treat it as `MainMenuPane.cpp` launcher code.
- 2026-06-01 IDA MCP `py_eval` enumerates the executable create-user family as three method/helper clusters plus lifecycle glue: `0x0052a540-0x0052c325` (`NewUserDialogPane2`), `0x0052c360-0x0052dcf5` (`NewCreateUserDialogPane`), `0x0052dd30-0x0052f6e5` (`CreateUserDialogPane`), and `0x0052f710-0x0052f94c` singleton clear/thunk/deleting-destructor glue.
- 2026-06-01 IDA MCP decompilation confirms the three submit helpers at `0x0052b9f0`, `0x0052d3e0`, and `0x0052ed80` share the same validation shape: read three edit fields, require a digit in the password, compare confirmation with `wcscmp`, alert on failure, and call the local packet encoder on success.
- 2026-06-01 IDA MCP decompilation confirms the packet encoder/helper triplets at `0x0052bbc0/0x0052bdd0/0x0052bfd0`, `0x0052d5b0/0x0052d7c0/0x0052d9a0`, and `0x0052ef50/0x0052f160/0x0052f390`, all using `dword_67A7EC` send paths and create-user reply handling.
- 2026-06-01 IDA MCP xrefs tie vtables and singleton slots to the three variants: `0x0061fd04`/`0x0069b4a4` for `NewUserDialogPane2`, `0x0061fda0`/`0x0069b4a8` for `NewCreateUserDialogPane`, and `0x0061fe3c`/`0x0069b890` for `CreateUserDialogPane`.

## Migration Notes

Do not blindly merge every `NewUser*` class into one file. A plausible split is:

```text
login/CreateUserDialogPane.cpp
login/NewCreateUserDialogPane.cpp
login/NewUserDialogPane2.cpp        # optional split; may fold into NewCreateUserDialogPane.cpp
login/NewUserShapeSelectControlPane.cpp
login/NewUserMiscDialogPane.cpp     # tentative, pending owner review
login/UserCreateAppearanceControls.cpp  # possible split from CreateUserDialogPane.cpp
```

Keep `NewUserMiscDialogPane` as a separate candidate until the `CashShopRequest` packet dependency, indirect trigger path, and the `0x004fbfd0` boundary are reviewed.

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
- [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md)
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md)
- [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)

## Changes

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
