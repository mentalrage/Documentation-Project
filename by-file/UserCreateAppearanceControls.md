*** UID:0000OX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# UserCreateAppearanceControls

## Status

- Confidence: strong for the old create-user appearance controls, complete method/type/data inventory, direct class ownership, and dedicated login source route.
- Current module: `NexusTK/login/UserCreateAppearanceControls.h` and `NexusTK/login/UserCreateAppearanceControls.cpp`.
- Current recovered sources: `class_UserShapeSelectControlPane.cpp`, `class_UserHairSelectControlPane.cpp`, `class_UserFaceSelectControlPane.cpp`, `class_UserCreatePreviewControlPane.cpp`, `class_UserHairColorSelectListPane.cpp`, and `class_UserFaceColorSelectListPane.cpp`
- Main memory doc: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Related support docs: [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md), [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md), and [UID:0000VN][-ignored](by-memory/-ignored.md)

## File Role

This file group owns the older create-user appearance widgets: body-shape preview buttons, hair and face thumbnail grids, the final character preview pane, and hair/face color swatch lists. The controls are tightly coupled to [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), `NewHumanImageLib`, sprite rendering, and palette lookup.

Dedicated `UserCreateAppearanceControls.h/.cpp` is the selected reconstruction boundary. The dialog remains a caller/coordinator; reusable control ABIs, contiguous method/vtable families, shared type/table, and cross-flow shape-control use reject dialog-owned or umbrella-owned placement.

## Current Source Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserShapeSelectControlPane` | `0x004fcd80-0x004fd520`, destructor/thunks `0x005025ea`, `0x005025f5`, `0x00502dd0` | Complete `0x140` source declaration at position `0` followed by exact core definitions at position `10`: constructor, `BuildPreviewParams`, male/female shape-bank setters, signed-short `StepShapeForward`/`StepShapeBackward` with exact `-1` terminal sentinel and invalid-state fallthrough, retained `IsSelected`, `SetSelected`, timer/mouse/paint, implicit `+0x117` alignment, sprite-id banks, and current/legacy frame resources. Historical `0x00501620`/`0x00501640` attribution belongs to the hair selector, while `0x0054b700` belongs to PrettyButtonControlPane. |
| `UserHairSelectControlPane` | `0x00501150-0x00501612`, gender-bank setters `0x00501620`, `0x00501640`, destructor/thunks `0x005025d4`, `0x005025df`, `0x00502d90` | Hair thumbnail grid with 9x2 82x58 cells, selected hair at `+0x10a`, gender/style bank at `+0x10c`, hair color at `+0x10d`, mouse capture at `+0x10e`, two 18-entry hair-frame banks at `+0x110/+0x134`, local hit rect at `+0x15c`, and `SetMaleMode`/`SetFemaleMode` helpers called by `CreateUserDialogPane::SelectMale`/`SelectFemale` on control id `6`. |
| `UserFaceSelectControlPane` | `0x00501660-0x00501af2`, destructor/thunks `0x005025be`, `0x005025c9`, `0x00502d50` | Face thumbnail grid with 6x2 cells, selected face at `+0x10a`, gender bank at `+0x10c`, face color at `+0x10d`, face-id banks at `+0x110/+0x128`, mouse selection, `USERPART.EPF`/`USERPART.PAL` selection-frame rendering, and selected-face update for old-dialog control id `7`. |
| `UserCreatePreviewControlPane` | `0x00501b40-0x00501e05`, retained helper `0x00501d80-0x00501dbc`, destructor/thunks `0x005025a8`, `0x005025b3`, `0x00502d10` | Final character preview render pane, NewHumanImageLib parameter builder, direction/update helpers, and retained base-preview refresh helper. |
| `UserHairColorSelectListPane` | `0x00501e10-0x005020c3` | Hair-color swatch list that calls `CreateUserDialogPane::SetHairColorIndex`. |
| `UserFaceColorSelectListPane` | `0x005020d0-0x00502383` | Face-color swatch list that calls `CreateUserDialogPane::SetFaceColorIndex`. |

## Evidence Notes

- IDA MCP confirms every major function start listed above.
- 2026-06-01 IDA MCP resplit confirms the source-bearing `UserShapeSelectControlPane` constructor/method island is [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md); the neighboring `0x004fccf0-0x004fce7e` island is [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md), with only a small selected-state setter at `0x004fcd80` in that generic select-box owner.
- 2026-06-25 B007 implementation established [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) as source-ready first-draft C++ under [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md). The 2026-07-22 B002 callback raises the current class/core pair to `92/93` and `91/94`, installs the complete declaration before the exact core, corrects the step return ABI to signed short, preserves no-fallback invalid-state behavior, and retains the B007 no-xref getter, field/table map, descriptor-vs-packet separation, and paint resource route through `g_useEpfAssets`, `g_pEPFLib`, `g_pNewHumanImageLib`, `USERPART.EPF`, `NEWBUTT.PAL`, `CAPSULE.EPD`, and `NPAL3.PAL`.
- `xrefs_to` confirms `UserHairSelectControlPane`, `UserFaceSelectControlPane`, both color list constructors, and `UserCreatePreviewControlPane` are constructed by `CreateUserDialogPane::CreateUserDialogPane` at `0x0052dd30`.
- 2026-06-12 Agent-C001 live IDA MCP recheck reconfirmed the selector/control cluster entry at `0x00501150`, a create-user constructor xref at `0x0052e0af` inside `0x0052dd30`, and the `0x00502383` padding/successor boundary before singleton-clear helper code at `0x00502390`.
- `xrefs_to 0x004fce80` also reports construction from the `NewUserMiscDialogPane` / `NewUserDialogPane2` area, so `UserShapeSelectControlPane` is a reusable create-user-family control rather than an inlined old-dialog-only helper.
- `xrefs_to 0x0052e930` and `0x0052e950` confirms the hair/face color lists call back into `CreateUserDialogPane::SetHairColorIndex` and `CreateUserDialogPane::SetFaceColorIndex`.

## 2026-06-20 B004 CreateUserDialogPane Callback Boundary

- B004's old `CreateUserDialogPane` source-quality pass keeps this file as the practical owner for the appearance-control classes, but rejects assigning `CreateUserDialogPane::SetHairColorIndex` and `CreateUserDialogPane::SetFaceColorIndex` to the controls. The color-list panes are callback producers/consumers; the selected color bytes they set are reached through the old dialog's selector controls `6` and `7`.
- Hair color callbacks at `0x00501eee` and `0x005020b9` call [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) method `SetHairColorIndex` at `0x0052e930`, which writes the selected color byte to the hair selector control's `+0x10d` field.
- Face color callbacks at `0x005021ae` and `0x00502379` call [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) method `SetFaceColorIndex` at `0x0052e950`, which writes the selected color byte to the face selector control's `+0x10d` field.
- Keep [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) as the appearance-control source bucket and [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) as the old dialog class owner. Do not use the callback relationship to move old-dialog fields, submit/reply logic, or packet helpers into this file.

## 2026-06-26 B008 Old Dialog Callback Setter Sync

- The accepted [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md) split keeps `CreateUserDialogPane::SetHairColorIndex` and `CreateUserDialogPane::SetFaceColorIndex` as old-dialog methods, not appearance-control-owned methods.
- `SetHairColorIndex` writes the hair selector control `6` color byte at `+0x10d` and returns the argument; `SetFaceColorIndex` writes the face selector control `7` color byte at `+0x10d` and returns the argument. Neither setter invalidates the selector or refreshes the preview inside the setter body.
- `SetHairColorIndex`, `SetFaceColorIndex`, and `SetGender` are accepted as inline/trivial state-setter names for the B008 child formal C++ blocks. Preview refresh stays in `CreateUserDialogPane::OnDialogAction`, while these controls remain owned by this file group.

## 2026-06-20 B005 UserCreatePreviewControlPane Source-Quality Sync

- B005's preview-pane pass keeps [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md) source-bearing under this file and raises the class to declaration-ready status. The by-class page now emits only the class declaration shell with `[[CHILDREN]]`; constructor/paint/update bodies should be split through exact child pages rather than pasted into this file overview.
- The preview inventory is constructor `0x00501b40-0x00501bba`, `BuildPreviewParams` `0x00501bc0-0x00501c58`, vtable-only `OnPaint` `0x00501c60-0x00501d45`, `AdvanceDirection` `0x00501d50-0x00501d74`, retained three-argument `UpdatePreview` `0x00501d80-0x00501dbc`, and live five-argument `UpdatePreview` `0x00501dc0-0x00501e05`.
- Source-facing preview fields are `m_faceFrameBase` at `+0x108`, `m_hairFrame` at `+0x10a`, `m_gender` at `+0x10c`, `m_direction` at `+0x10d`, `m_hairColor` at `+0x10e`, `m_faceColor` at `+0x10f`, and constructor-cleared `m_reservedPreviewState` at `+0x110`. The preview pane does not own the old body-shape state; [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) coordinates body-shape buttons separately.
- `CreateUserDialogPane` constructs this preview pane at `0x0052e64b`, advances it at `0x0052eafe` / `0x0052e730-0x0052e744`, refreshes it at `0x0052eb68`, and queries `BuildPreviewParams` for packet payload state at `0x0052f1e8`. This keeps [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) as caller/coordinator and this file as the class source bucket.
- `OnPaint` consumes [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `0x0069b3fc` for the active-rectangle fill, uses `RectBounds(0,0,82,117)`, calls [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) / [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) `CalculateBounds` at `0x004e09e0` and `Draw` at `0x004e06a0`, and applies the visible offset `(15,75)`.
- Destructor/thunk policy is unchanged: `0x005025a8` and `0x005025b3` are `this-0xa0` / `this-0xa4` adjustor thunks, and `0x00502d10` is scalar deleting destructor glue. Source should express an ordinary/defaulted `virtual ~UserCreatePreviewControlPane()` and let the compiler regenerate wrappers.

## 2026-06-21 B007 UserFaceSelectControlPane Source-Quality Sync

- B007's face-selector pass keeps [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md) source-bearing under this file and raises the class to declaration-ready status. The class page now emits a declaration shell; executable constructor/mouse/paint/select bodies should be split through exact child pages or a reviewed method aggregate rather than pasted into this file overview.
- The face selector method inventory is constructor `0x00501660-0x00501783`, EventHandler `OnMouseEvent` `0x00501790-0x0050183a`, primary-vtable `OnPaintFrame` `0x00501840-0x00501a6a`, and `SelectFaceAtPoint` `0x00501a70-0x00501af2`.
- Source-facing face-selector fields are selected face `+0x10a`, gender bank `+0x10c`, face color `+0x10d`, mouse capture `+0x10e`, face-part id banks `+0x110/+0x128`, column count `+0x140`, and local hit rect `+0x144`; `+0x108` stays reserved/unnamed because only a constructor clear is proven.
- `CreateUserDialogPane` constructs this control at old-dialog control id `7` with allocation size `0x154`, bounds `{170,545,676,662}`, `selectedFace = rand() % 10`, `faceColor = 1`, `gender = 0`, and control flag `0`. `SelectMale`/`SelectFemale` write face selector `+0x10c` directly and invalidate; `SetFaceColorIndex` writes `+0x10d`; preview setup reads `m_facePartIds[m_gender][m_selectedFace]`.
- The `0x00501620` and `0x00501640` helpers are now documented as [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) `SetMaleMode` and `SetFemaleMode`, not shape-selector helpers. Face gender mode changes are inlined in the old dialog.
- The face paint route uses `USERPART.EPF` and `USERPART.PAL` for the selection frame. The apparent `off_61E3C0` and `off_61E420` labels are UTF-16 string fragments beginning with the dword bytes for `U\0S\0`, not source globals.

## 2026-06-21 B009 UserHairSelectControlPane Source-Quality Sync

- B009's hair-selector pass keeps [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) source-bearing under this file and raises the class to declaration-ready status. The class page now emits a declaration shell; executable constructor/mouse/paint/select/style-helper bodies should be split through exact child pages or a reviewed method aggregate rather than pasted into this file overview.
- The hair selector method inventory is constructor `0x00501150-0x005012af`, EventHandler `OnMouseEvent` `0x005012b0-0x0050135a`, primary-vtable `OnPaintFrame` `0x00501360-0x0050158a`, `SelectHairAtPoint` `0x00501590-0x00501612`, `SetMaleMode` `0x00501620-0x00501631`, and `SetFemaleMode` `0x00501640-0x00501651`.
- Source-facing hair-selector fields are reserved byte `+0x108`, selected hair slot `+0x10a`, gender/style bank `+0x10c`, hair color `+0x10d`, mouse capture `+0x10e`, 18-entry hair-frame banks `+0x110/+0x134`, column count `+0x158`, and local hit rect `+0x15c`. The constructor allocation is `0x16c`; older 712-byte OOAnalyzer class-size artifacts should not be used for final layout.
- `CreateUserDialogPane` constructs this control at old-dialog control id `6` with bounds `{170,342,926,477}`, `selectedHair = rand() % 10`, `hairColor = 12`, `genderStyle = 0`, and control flag `0`. `SelectMale`/`SelectFemale` call `SetMaleMode`/`SetFemaleMode`; `SetHairColorIndex` writes `+0x10d`; preview setup reads `m_hairPartFrames[m_genderStyle][m_selectedHairSlot]`.
- The style/gender helper correction is now source-quality strong for current evidence: `0x00501620` and `0x00501640` belong to this hair selector, not [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md). If future xrefs prove shared use, prefer a generic appearance-selector style-bank helper name, but do not revert to shape-only ownership.
- The hair paint route uses NewHumanImageLib part category `5`, palette category `14` with `m_hairColor >> 5`, shared Surface callbacks, and the `USERPART.EPF` / `USERPART.PAL` selection-frame route already shared with the face selector. Exact render helper typedefs and original method-body spellings remain below final-source quality.

## 2026-06-25 B007 UserShapeSelectControlPane Source-Quality Sync

- [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md) remains source-bearing under this file; executable bodies for the accepted exact core now emit from [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md), not from this overview.
- The source-ready method inventory is constructor `0x004fce80-0x004fcfb5`, `BuildPreviewParams` `0x004fcfc0-0x004fd02a`, `SetMaleShapeBank` `0x004fd030-0x004fd043`, `SetFemaleShapeBank` `0x004fd050-0x004fd066`, `StepShapeForward` `0x004fd070-0x004fd0c9`, `StepShapeBackward` `0x004fd0d0-0x004fd126`, retained no-xref `IsSelected` `0x004fd130-0x004fd137`, `SetSelected` `0x004fd140-0x004fd164`, `OnTimerEvent` `0x004fd170-0x004fd1de`, `OnMouseEvent` `0x004fd1e0-0x004fd228`, and `OnPaint` `0x004fd230-0x004fd520`.
- Source-facing shape fields are control flags at `+0xff`, reserved shape state at `+0x108`, shape-index limit at `+0x10a`, selected shape index at `+0x10c`, shape bank at `+0x10e`, animation frame at `+0x110`, direction at `+0x112`, animation tick at `+0x114`, selected byte at `+0x116`, and two ten-entry sprite-id banks at `+0x118..+0x12b` and `+0x12c..+0x13f`.
- `BuildPreviewParams` is a render/packet parameter builder, not a packet writer. Old/new create-user dialog code calls it and then serializes opcode `4` payload fields; this file keeps the reusable control class while packet helpers and active-pane coordination remain with their dialog pages.
- `OnPaint` uses `g_useEpfAssets` to select `USERPART.EPF` / `NEWBUTT.PAL` or `CAPSULE.EPD` / `NPAL3.PAL`, resolves the frame through `g_pEPFLib->LookupLayoutEntry`, uses the lookup-populated `EPFTileContext::bounds` as the source rectangle, and then measures/draws the body preview through `g_pNewHumanImageLib`.
- The rejected helper correction is unchanged: `0x00501620` and `0x00501640` are [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) style-bank helpers. They must not be moved back to `UserShapeSelectControlPane`.

## 2026-07-22 B002 UserShape Declaration And Step ABI Sync

- [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md) now emits the complete class declaration at position `0`, closes the class before `[[CHILDREN]]`, and preserves the exact `0x140` layout from inherited `ControlPane +0x108` through two ten-word sprite banks ending at `+0x13f`.
- Natural one-byte alignment at `+0x117` precedes the `unsigned short` sprite table; no unsupported reserve member is emitted. The source destructor is empty/defaulted, while scalar wrappers, adjustors, vptr stores, base teardown, delete flags, and storage release remain compiler-only.
- [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) emits definitions at position `10`. Its namespace constants are period-compatible `const` objects and inherited `m_controlFlags` is assigned in the constructor body rather than named in a derived initializer.
- `StepShapeForward` and `StepShapeBackward` return `short`. NewUserDialogPane2's exact UID00043M/UID00043N callers compare `-1`, and the formal bodies preserve the binary's missing invalid-state fallback rather than inventing a behavior-changing return.
- Source order is declaration, constants/local centering helpers, constructor, descriptor builder, bank setters, forward/backward steps, selected getter/setter, timer, mouse, and paint. Packet serialization remains with dialog callers.

## 2026-07-22 B002 NewUserDialogPane2 Gender-Bank Caller Sync

- [UID:00043R][0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode](by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md) calls `UserShapeSelectControlPane::SetMaleShapeBank()` on exact dialog children `8`, `9`, `10`, and `11` in literal order. Its 136-byte body has SHA256 `318E714C08908DCE721179A703BFBCBED42A2FF353F4D0A7EE03A18D3176F109` and constructor/command-id-`4` callers.
- [UID:00043S][0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode](by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md) calls `SetFemaleShapeBank()` on the same four controls; its 136-byte body has SHA256 `F9C237761B1388EEF54ED332579E1FFF9715284DF6FBA40F0E81BAF00C1B0135` and constructor/command-id-`5` callers.
- The exact bank setters remain `0x004fd030` (store bank `0` at `+0x10e`) and `0x004fd050` (store bank `1`), each followed by invalidation. No new helper or source owner is needed.
- Both dialog methods separately call [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md) on button children `4/5`. Exact UID0004E5 evidence proves `0x0054b700` writes PrettyButton `m_selected` at `+0x118`; it is not a UserShape `SetActive` helper and is excluded from this file's method inventory.
- Complete gender-method inventories show no shape-slot reselection, loop, packet, or notification behavior. Historical generic-helper and cross-class ownership claims remain superseded context only.

+## 2026-07-14 Implemented Appearance-Control Source Route

- Current file score is `92/93`; projected route remains `NexusTK/login/`.
- Selected source pair is `UserCreateAppearanceControls.h` and `UserCreateAppearanceControls.cpp`. Six contiguous reusable classes, one shared swatch type, one shared color table, contiguous RTTI/vtables, and common compiler destructor support make this route stronger than folding methods into `CreateUserDialogPane.cpp` or heterogeneous `CreateUserDialogs.cpp`.
- Header contents are shared [UID:0004P6][UserCreateAppearanceControlLayouts](by-type/by-struct/UserCreateAppearanceControlLayouts.md) type support followed by six closed class declarations in exact source order: UID0000FR at position `0`, UID0000FL at `20`, UID0000FJ at `30`, UID0000FH at `40`, UID0000FK at `50`, and UID0000FI at `60`. Each declaration has an inline empty destructor; method definitions remain in CPP.
- CPP contents are [UID:0004P7][0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable](by-memory/0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable.md) followed by 26 exact definitions in source-family order.
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) is a `92/94` non-emitting index and cannot duplicate definitions.
- [UID:0004P8][UserCreateAppearanceControlVtables](by-type/by-vtable/UserCreateAppearanceControlVtables.md) and [UID:0004P9][0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData](by-memory/0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData.md) are source-declared/generated-binary and blank by design.

### Exact Method Child Map



| Token | Exact new path | Bytes | SHA256 | Owner / emitter | Score / Nested |
| --- | --- | ---: | --- | --- | --- |
| [UID:0004OG][0x00501150-0x005012af.UserHairSelectControlPaneConstructor](by-memory/0x00501150-0x005012af.UserHairSelectControlPaneConstructor.md) | `by-memory/0x00501150-0x005012af.UserHairSelectControlPaneConstructor.md` | `0x15f` | `DE2365F5255C5F16DAF84E3C3968329094DE898B9B7EA631497175475A8C058E` | `0000FL` / `0000FL`, pos 10 | `91/93`, `1` |
| [UID:0004OH][0x005012b0-0x0050135a.UserHairSelectControlPaneOnMouseEvent](by-memory/0x005012b0-0x0050135a.UserHairSelectControlPaneOnMouseEvent.md) | `by-memory/0x005012b0-0x0050135a.UserHairSelectControlPaneOnMouseEvent.md` | `0xaa` | `3B5136FF6102A5CBA90EE89040105EABFAC4A15785415957DC7F70F6737A8146` | `0000FL` / `0000FL`, pos 20 | `90/93`, `0` |
| [UID:0004OI][0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame](by-memory/0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md) | `by-memory/0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md` | `0x22a` | `BEA51A3B93D7B9B419B2EF65DC72B1FDAF7180B7B66D1A0BD0A1E70C427A3B64` | `0000FL` / `0000FL`, pos 30 | `89/92`, `0` |
| [UID:0004OJ][0x00501590-0x00501612.UserHairSelectControlPaneSelectHairAtPoint](by-memory/0x00501590-0x00501612.UserHairSelectControlPaneSelectHairAtPoint.md) | `by-memory/0x00501590-0x00501612.UserHairSelectControlPaneSelectHairAtPoint.md` | `0x82` | `C2E1F0B1C0622F5306D8CDAB37773F5ED15D71F96D2481430A4C771E1D8089CB` | `0000FL` / `0000FL`, pos 40 | `91/94`, `0` |
| [UID:0004OK][0x00501620-0x00501631.UserHairSelectControlPaneSetMaleMode](by-memory/0x00501620-0x00501631.UserHairSelectControlPaneSetMaleMode.md) | `by-memory/0x00501620-0x00501631.UserHairSelectControlPaneSetMaleMode.md` | `0x11` | `4CC3FD069F2F862DCC8720A2844936B894B87551993FFA2B0191741D38B53984` | `0000FL` / `0000FL`, pos 50 | `92/95`, `0` |
| [UID:0004OL][0x00501640-0x00501651.UserHairSelectControlPaneSetFemaleMode](by-memory/0x00501640-0x00501651.UserHairSelectControlPaneSetFemaleMode.md) | `by-memory/0x00501640-0x00501651.UserHairSelectControlPaneSetFemaleMode.md` | `0x11` | `D694A704FA67C16A0230D456DDB92C9085982897EF494BD7125EBFB421C0DA7C` | `0000FL` / `0000FL`, pos 60 | `92/95`, `0` |
| [UID:0004OM][0x00501660-0x00501783.UserFaceSelectControlPaneConstructor](by-memory/0x00501660-0x00501783.UserFaceSelectControlPaneConstructor.md) | `by-memory/0x00501660-0x00501783.UserFaceSelectControlPaneConstructor.md` | `0x123` | `578E78704DB82FFFDF135A2B25266F2CCAB1C6FFF4962F4DE437275EF027AE5A` | `0000FJ` / `0000FJ`, pos 10 | `91/93`, `0` |
| [UID:0004ON][0x00501790-0x0050183a.UserFaceSelectControlPaneOnMouseEvent](by-memory/0x00501790-0x0050183a.UserFaceSelectControlPaneOnMouseEvent.md) | `by-memory/0x00501790-0x0050183a.UserFaceSelectControlPaneOnMouseEvent.md` | `0xaa` | `731D3ACE27BF7616993490DAF52EDCD08C78E51F783C95F29B9AD1DAE3E4BEC1` | `0000FJ` / `0000FJ`, pos 20 | `90/93`, `0` |
| [UID:0004OO][0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame](by-memory/0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md) | `by-memory/0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md` | `0x22a` | `D31A9B381A05A7362D49AA4EDDB01EA9DFDDB41B59D7A3A37F29D8BFB953F9CA` | `0000FJ` / `0000FJ`, pos 30 | `89/92`, `0` |
| [UID:0004OP][0x00501a70-0x00501af2.UserFaceSelectControlPaneSelectFaceAtPoint](by-memory/0x00501a70-0x00501af2.UserFaceSelectControlPaneSelectFaceAtPoint.md) | `by-memory/0x00501a70-0x00501af2.UserFaceSelectControlPaneSelectFaceAtPoint.md` | `0x82` | `89F02008694F40F8FA0936FCCE271D364C27EA8DF473925D5618D430D0369A82` | `0000FJ` / `0000FJ`, pos 40 | `91/94`, `0` |
| [UID:0004OQ][0x00501b00-0x00501b11.UserFaceSelectControlPaneSetMaleMode](by-memory/0x00501b00-0x00501b11.UserFaceSelectControlPaneSetMaleMode.md) | `by-memory/0x00501b00-0x00501b11.UserFaceSelectControlPaneSetMaleMode.md` | `0x11` | `4CC3FD069F2F862DCC8720A2844936B894B87551993FFA2B0191741D38B53984` | `0000FJ` / `0000FJ`, pos 50 | `92/95`, `0` |
| [UID:0004OR][0x00501b20-0x00501b31.UserFaceSelectControlPaneSetFemaleMode](by-memory/0x00501b20-0x00501b31.UserFaceSelectControlPaneSetFemaleMode.md) | `by-memory/0x00501b20-0x00501b31.UserFaceSelectControlPaneSetFemaleMode.md` | `0x11` | `D694A704FA67C16A0230D456DDB92C9085982897EF494BD7125EBFB421C0DA7C` | `0000FJ` / `0000FJ`, pos 60 | `92/95`, `0` |
| [UID:0004OS][0x00501b40-0x00501bba.UserCreatePreviewControlPaneConstructor](by-memory/0x00501b40-0x00501bba.UserCreatePreviewControlPaneConstructor.md) | `by-memory/0x00501b40-0x00501bba.UserCreatePreviewControlPaneConstructor.md` | `0x7a` | `42ACE6B80F84F09A9A7B6ABBE2DF1248BCDF7680D435FEE59C49E35BCBF01564` | `0000FH` / `0000FH`, pos 10 | `91/93`, `0` |
| [UID:0004OT][0x00501bc0-0x00501c58.UserCreatePreviewControlPaneBuildPreviewParams](by-memory/0x00501bc0-0x00501c58.UserCreatePreviewControlPaneBuildPreviewParams.md) | `by-memory/0x00501bc0-0x00501c58.UserCreatePreviewControlPaneBuildPreviewParams.md` | `0x98` | `FBF349956C4AE0379BA07BFE18659A793030AC0EEF88F2129C1BD579493103F0` | `0000FH` / `0000FH`, pos 20 | `91/93`, `0` |
| [UID:0004OU][0x00501c60-0x00501d45.UserCreatePreviewControlPaneOnPaint](by-memory/0x00501c60-0x00501d45.UserCreatePreviewControlPaneOnPaint.md) | `by-memory/0x00501c60-0x00501d45.UserCreatePreviewControlPaneOnPaint.md` | `0xe5` | `B1BC4C57CBB983E725030576FB66E78E647C9B6D1B362AB89DA8D7DF64E68C5A` | `0000FH` / `0000FH`, pos 30 | `90/92`, `0` |
| [UID:0004OV][0x00501d50-0x00501d74.UserCreatePreviewControlPaneAdvanceDirection](by-memory/0x00501d50-0x00501d74.UserCreatePreviewControlPaneAdvanceDirection.md) | `by-memory/0x00501d50-0x00501d74.UserCreatePreviewControlPaneAdvanceDirection.md` | `0x24` | `2E37ED77413522EB7D11E1FDD70F6A3C4D4288CBE2E8894EE5E9963059835080` | `0000FH` / `0000FH`, pos 40 | `92/94`, `0` |
| [UID:0004OW][0x00501d80-0x00501dbc.UserCreatePreviewControlPaneUpdatePreviewFaceHairGender](by-memory/0x00501d80-0x00501dbc.UserCreatePreviewControlPaneUpdatePreviewFaceHairGender.md) | `by-memory/0x00501d80-0x00501dbc.UserCreatePreviewControlPaneUpdatePreviewFaceHairGender.md` | `0x3c` | `C729AFED6C75E915C949C88F4C3E52C0AC9F38A1877530D5A74A400E53951288` | `0000FH` / `0000FH`, pos 50 | `88/90`, `0` |
| [UID:0004OX][0x00501dc0-0x00501e05.UserCreatePreviewControlPaneUpdatePreviewFull](by-memory/0x00501dc0-0x00501e05.UserCreatePreviewControlPaneUpdatePreviewFull.md) | `by-memory/0x00501dc0-0x00501e05.UserCreatePreviewControlPaneUpdatePreviewFull.md` | `0x45` | `961F5DD271748836693C9F45F9CE5BF9DE5A725BA815166327871EE0970D834A` | `0000FH` / `0000FH`, pos 60 | `91/93`, `0` |
| [UID:0004OY][0x00501e10-0x00501f12.UserHairColorSelectListPaneConstructor](by-memory/0x00501e10-0x00501f12.UserHairColorSelectListPaneConstructor.md) | `by-memory/0x00501e10-0x00501f12.UserHairColorSelectListPaneConstructor.md` | `0x102` | `70CFC752E2C87494FD0DB2F3278E92303EB1B4B6947BC9D301529B93E96DCB08` | `0000FK` / `0000FK`, pos 10 | `91/93`, `0` |
| [UID:0004OZ][0x00501f20-0x00501f2f.UserHairColorSelectListPaneGetSelectedColorValue](by-memory/0x00501f20-0x00501f2f.UserHairColorSelectListPaneGetSelectedColorValue.md) | `by-memory/0x00501f20-0x00501f2f.UserHairColorSelectListPaneGetSelectedColorValue.md` | `0xf` | `574F6A3EF9BF2E76758BA5843FEDB4B8EFC34B974C57A2650D81642C8FB3E999` | `0000FK` / `0000FK`, pos 20 | `88/91`, `0` |
| [UID:0004P0][0x00501f30-0x00502087.UserHairColorSelectListPaneDrawItem](by-memory/0x00501f30-0x00502087.UserHairColorSelectListPaneDrawItem.md) | `by-memory/0x00501f30-0x00502087.UserHairColorSelectListPaneDrawItem.md` | `0x157` | `01D529EA8C5A2ED8B6B693205E6141C18F5AF43564D28E7E9961B042DE48B6AC` | `0000FK` / `0000FK`, pos 30 | `90/93`, `0` |
| [UID:0004P1][0x00502090-0x005020c3.UserHairColorSelectListPaneOnItemSelected](by-memory/0x00502090-0x005020c3.UserHairColorSelectListPaneOnItemSelected.md) | `by-memory/0x00502090-0x005020c3.UserHairColorSelectListPaneOnItemSelected.md` | `0x33` | `0D5F46216F4DF4787C6C7E73ED8BFCCCCC862BCDDE1DCE70592B8199A3CE392B` | `0000FK` / `0000FK`, pos 40 | `91/94`, `0` |
| [UID:0004P2][0x005020d0-0x005021d2.UserFaceColorSelectListPaneConstructor](by-memory/0x005020d0-0x005021d2.UserFaceColorSelectListPaneConstructor.md) | `by-memory/0x005020d0-0x005021d2.UserFaceColorSelectListPaneConstructor.md` | `0x102` | `A5EB2D7A48E02C2211BF582E1366D060E0A4A5666A2C39C1C72E84D499ABCF4C` | `0000FI` / `0000FI`, pos 10 | `91/93`, `0` |
| [UID:0004P3][0x005021e0-0x005021ef.UserFaceColorSelectListPaneGetSelectedColorValue](by-memory/0x005021e0-0x005021ef.UserFaceColorSelectListPaneGetSelectedColorValue.md) | `by-memory/0x005021e0-0x005021ef.UserFaceColorSelectListPaneGetSelectedColorValue.md` | `0xf` | `9C0607AAA29DA6C83D5A97CA008858AC3FABC09C92E4D68F3B768B527802E262` | `0000FI` / `0000FI`, pos 20 | `88/91`, `0` |
| [UID:0004P4][0x005021f0-0x00502347.UserFaceColorSelectListPaneDrawItem](by-memory/0x005021f0-0x00502347.UserFaceColorSelectListPaneDrawItem.md) | `by-memory/0x005021f0-0x00502347.UserFaceColorSelectListPaneDrawItem.md` | `0x157` | `4F7088BC312BFA9AB83882B9E371C0F24F7E49B24E9993C597863A730229A35A` | `0000FI` / `0000FI`, pos 30 | `90/93`, `0` |

### Dependencies And Boundaries

- CreateUserDialogPane constructs the controls and receives color callbacks; it is a caller/coordinator, not method/ABI owner.
- ControlPane/ListPane are bases. GrafPort, Surface callbacks, NewHumanImageLib, PaletteLib, EPFLib, ResourceLayoutTable, RectBounds, and HumanImageRenderParams are typed dependencies.
- UID0001AF adjustors and UID00022X scalar deleting wrappers stay compiler-only. UID00022X is non-reconstructable with a blank emitter and blank formal channels; the six inline empty virtual destructors regenerate required compiler support without an empty emitter marker.
- Selector paint preserves category 5/slot 14 for hair and category 2/slot 13 for face. List draw preserves selected 128/143 fills, inset 3, mode 1, exact palette transform, and borrowed-palette clear.
- Preview descriptor kind remains caller-owned; paint sets `0x50`. The retained three-argument `UpdatePreview` clears both colors; the live five-argument overload writes them.
- No raw addresses/offsets, explicit vptr/cookies, adjustor bodies, compiler tables, duplicate output, extra guards, palette deletion, or ownership transfers are emitted.
- No authentic source/PDB survives. Exact bytes/ranges/hashes/flow/layout/calls/constants are facts; identifier/file spellings are accepted high-probability reconstruction.


## Ownership Notes

- Keep this cluster with login/create-user UI, not generic controls. It depends on create-user state and human-image resources.
- The brush helpers [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) are currently emitted under `UserHairColorSelectListPane` by generated output, but IDA caller evidence is broader than this class. Treat those as [UID:00005V][GrafPort](by-class/GrafPort.md) draw-state helpers, not create-user appearance methods.
- The dense destructor/adjustor thunk area around [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md) and [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md) is compiler destructor support for these controls and adjacent create-user panes; do not use the thunk pile as evidence for a separate source module. The adjustor range is excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). UID00022X remains associated binary evidence for four class destructor/vtable identities but is non-reconstructable, has no emitter, and keeps both formal channels blank because the wrappers contain no derived cleanup beyond inline empty destructors, base `Pane::~Pane()`, delete flags, and compiler guard/delete support.
- 2026-05-26 IDA MCP recheck confirms the appearance adjustor thunks as `this - 0xa0` / `this - 0xa4` destructor wrappers. The same pass reconfirmed `0x004b96a0` and `0x004b96b0` as broad draw-context brush helpers, not hair-color-list-owned methods.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md)
- [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md)
- [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)
- [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md)

## Changes

- 2026-07-22 B002 UID00043R implementation callback source-owner sync:
  - Kept UID0000OX metadata and complete appearance-control source route unchanged.
  - Added exact UID00043R/UID00043S caller evidence for UserShape male/female bank setters, including ranges, hashes, caller roles, child ids, literal order, and negative evidence.
  - Removed `0x0054b700` from the current UserShape method inventory and preserved its prior attribution as rejected history now resolved to UID0004E5 PrettyButtonControlPane.

- 2026-07-22 B002 UID00043N bounded support synchronization:
  - Preserved `92/93`, all five-class method maps, 26-child current union, render dependencies, callback ownership, and compiler ABI exclusions.
  - Added the complete UserShape declaration/core ordering, exact `0x140` layout and implicit padding, signed-short step contract, period-compatible constants, legal inherited field assignment, and UID00043M/UID00043N caller evidence.

- 2026-07-14 B004 UID0001A6 implementation callback:
  - Raised this page to `92/93`, resolved the dedicated `NexusTK/login/` source/header route, and recorded all real child/type/data UIDs.
  - Preserved CreateUserDialogPane as caller/coordinator, compiler ABI pages as non-emitting, and existing shape-control/dependency history.
  - Replaced historical `UpdateBasePreview` and unresolved source-split wording with the accepted overload and dedicated-module contract.

- 2026-06-25 B007 UserShapeSelectControlPane source-ready sync:
  - Score unchanged at `87/86`.
  - Summary/evidence: updated this appearance-control owner page for accepted [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) implementation. The page now records the source-ready exact child, retained `IsSelected` getter, method/field/resource inventory, descriptor-vs-packet distinction, and corrected `g_pEPFLib` paint route while preserving this file as the reusable control owner and keeping dialog packet/coordinator logic outside the file overview.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page already documents the appearance-control source role, likely class contents, IDA-backed constructor/vtable/resource evidence, ownership boundaries, and open source-split caveats, but exact original file split remains less than fully proven.
- 2026-06-12 Agent-C001 Batch C001-011 parent-gate repair:
  - Changed to: `87/85`, projected path unchanged.
  - Summary/evidence: C001 live IDA MCP reconfirmed the `0x00501150` entry, the `0x0052e0af` create-user constructor xref, and the `0x00502383`/`0x00502390` boundary, while [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) now records `85/89`. The file is strong enough as the direct provisional login/create-user source-family parent, with final `CreateUserDialogs.cpp` versus split helper-file naming still below final-source certainty.
- 2026-06-13 A003 support wording update:
  - Score unchanged at `87/85`.
  - Evidence: [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) was rerouted to [UID:00005V][GrafPort](by-class/GrafPort.md), so this page now describes those calls as external GrafPort draw-state support rather than unresolved create-user-local ownership.
- 2026-06-20 B004 old-dialog callback boundary sync:
  - Changed to: `87/86`.
  - Evidence: B004 confirmed the hair/face color list callback paths into `CreateUserDialogPane::SetHairColorIndex` and `CreateUserDialogPane::SetFaceColorIndex` while preserving this file as the owner for the appearance-control classes only, not the old dialog's packet/reply fields or methods.
- 2026-06-26 B008 old-dialog setter correction:
  - Score unchanged.
  - Evidence: B008's accepted split confirms the old-dialog color setters are direct selector color-byte writes with no invalidate/preview refresh inside the setter methods; preview refresh belongs to `CreateUserDialogPane::OnDialogAction`.
- 2026-06-20 B005 preview-pane source-quality sync:
  - Score unchanged at `87/86`.
  - Evidence: B005 resolved the preview-pane constructor/update/paint source shape, the retained `0x00501d80` helper, face/hair/color/gender/direction fields, dialog control-id routes, NewHumanImageLib draw/bounds usage, and generated destructor/thunk exclusion while preserving this file as the appearance-control owner.
- 2026-06-21 B007 face-selector source-quality sync:
  - Score unchanged at `87/86`.
  - Evidence: B007 corrected the stale helper ownership for `0x00501620`/`0x00501640`, resolved the face selector field/resource/caller model, and confirmed this file as the source owner while `CreateUserDialogPane` remains the coordinator.
- 2026-06-21 B009 hair-selector source-quality sync:
  - Score unchanged at `87/86`.
  - Evidence: B009 raises [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) to declaration-ready status under this file, resolves the 9x2 grid, decoded hair-frame banks, field names, style/gender helper ownership, old-dialog control id `6` routes, preview table-index formula, vtable/thunk/destructor no-code policy, and remaining event/render/source-split caveats.
