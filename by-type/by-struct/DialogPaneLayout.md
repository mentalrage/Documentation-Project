*** UID:0001U4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00003T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialogPane Layout

## Status

- Entity kind: class layout / inherited dialog state.
- Covered class: [UID:00003T][DialogPane](by-class/DialogPane.md) and derived modal/modeless dialog classes.
- Likely owner header/source: [UID:0000IT][DialogPane](by-file/DialogPane.md).
- Parent attachment: attached to [UID:00003T][DialogPane](by-class/DialogPane.md), which is scored `82/84`; this layout page is scored `84/88`, so both sides clear the `80/80` child attachment gate.
- Confidence: strong for the listed offsets and vtable-view offsets; medium for final source-facing field names after `+0x208`.
- Current generated source hint: `source-3/simroot_v2/class_DialogPane.cpp`; use it only as a lead, with IDA/MCP controlling the offsets.

## Observed Layout

`DialogPane` is a [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)-derived object with three vtable views. IDA confirms the primary object at `+0x00`, a secondary view at `+0xa0`, and a tertiary view at `+0xa4`. Many derived dialogs use the base fields below directly, so these offsets should be treated as inherited state rather than feature-dialog-local storage.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `DialogPane` table `0x00618a64` | Constructor and cleanup body store the primary vtable at object start. |
| `+0x04-+0xf7` | inherited `Pane` state | The constructor calls the `Pane` constructor before installing `DialogPane` vtables; see [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). |
| `+0xa0` | secondary/interface vptr, table `0x00618ac4` | Constructor stores this table; `OnShow` and `OnHide` pass `this + 0xa0` for modal registration/removal. |
| `+0xa4` | tertiary/interface vptr, table `0x00618af4` | Constructor stores this table; destructor adjustor thunk `0x0048c286` subtracts `0xa4`. |
| `+0x0f8` | dialog title, likely `wchar_t[0x80]` | Constructor and title setter pass `this + 0xf8` to `_wcscpy_s` with element count `0x80`. |
| `+0x1f8` | `uint16_t dialogConfigId` | Constructor stores the incoming config id; `OnCreate` checks it against `0xffff` and uses it for config lookup. |
| `+0x1fc` | control manager/list pointer | Constructor initializes zero; create/destroy/input/draw methods iterate or clear child controls through this pointer. |
| `+0x200` | focused/current control id | Constructor initializes `0xffffffff`; keyboard and focus drawing paths read it. |
| `+0x204` | previous/default/action control id | Constructor initializes `0xffffffff`; keyboard dispatch pushes it with `+0x200`. |
| `+0x208` | title-drag/capture active byte candidate | Constructor initializes zero; `ModelessDialogPane::HandleMouseEvent` sets and clears it while dragging title/chrome hit type `10`. |
| `+0x209` | constructor mode / saved pane mode byte candidate | Constructor stores the incoming mode byte; modeless drag saves/restores pane input mode through this field. |
| `+0x20c` | drag origin X candidate | Modeless mouse-down stores mouse X here; drag move subtracts it while updating pane position. |
| `+0x210` | drag origin Y candidate | Modeless mouse-down stores mouse Y here; drag move subtracts it while updating pane position. |
| `+0x214` | hover/control id candidate | Constructor initializes `0xffffffff`; hover and input dispatch helpers read/write it. |
| `+0x218` | pressed-control active byte candidate | Constructor initializes zero; modeless mouse-down/release toggles it. |
| `+0x21c` | pressed/control-state id candidate | Constructor initializes `0xffffffff`; modeless mouse paths store and dispatch through it. |
| `+0x220` | pressed hit type byte candidate | Modeless mouse-down stores hit type here and release checks it before activation. |
| `+0x224` | selected/prior hover control id candidate | Constructor initializes `0xffffffff`; keyboard/control dispatch and modeless release paths read/write it. |
| `+0x228` | hit-type/selection visual byte candidate | Input path checks and updates this byte; modeless release resets it to hit type `10`. |
| `+0x229` | drag clamp enabled or custom state byte candidate | Constructor initializes zero; modeless drag checks it before clamping movement. |
| `+0x22c` | minimum Y clamp candidate | Modeless drag move compares top position against this field. |
| `+0x230` | minimum X clamp candidate | Modeless drag move compares left position against this field. |
| `+0x234` | maximum Y clamp candidate | Modeless drag move compares bottom position against this field. |
| `+0x238` | maximum X clamp candidate | Modeless drag move compares right position against this field. |
| `+0x23c` | `EPFTileContext` | Constructor initializes via tile-context helper; cleanup destroys via tile-context teardown; background setup replaces it. |
| `+0x240` | tile/background context field | Background setup zeroes this field after loading frame data. |
| `+0x248` | tile/background frame data field | Background setup stores copied frame metadata here. |
| `+0x24c` | tile/background rectangle/vector field | Background setup copies a 16-byte block into this area. |
| `+0x25c` | tile/background payload size or extent | Background setup stores copied payload size here. |
| `+0x260` | custom background payload pointer/state | Draw background/border methods check this field; setup allocates/copies data into it. |
| `+0x264` | custom background width/size candidate | Constructor initializes zero; generated name is `m_bgImageWidth`. |
| `+0x268` | custom background present flag candidate | Constructor initializes zero; generated name is `m_bHasCustomBg`. |

The base object must be large enough to include byte `+0x268`. Do not treat `AlertPane` offset `+0x26c` as base `DialogPane` state; current IDA evidence puts `+0x26c` in the alert-family derived tail.

## IDA Evidence

Checked on 2026-05-26 and spot-rechecked on 2026-05-31:

- `DialogPane::DialogPane` at `0x0049d8a0` calls the `Pane` constructor, initializes `EPFTileContext` at `+0x23c`, installs vtables at `+0x00`, `+0xa0`, and `+0xa4`, copies the title into `+0xf8`, then initializes the control/config/mode/background fields listed above.
- The cleanup body at `0x0049da10` reinstalls the same three vtables, tears down the control manager at `+0x1fc`, destroys the tile context at `+0x23c`, and then calls base `Pane` teardown.
- The title setter at `0x0049db30` copies to `+0xf8` and invalidates/repaints through a virtual slot.
- The background/tile setup helper at `0x0049db60` replaces the tile context at `+0x23c` and writes the `+0x240` through `+0x260` background fields.
- `OnCreate` at `0x0049dfd0` reads `+0x1f8` for dialog config lookup and uses `+0x1fc` for child-control setup.
- `OnShow` and `OnHide` at `0x0049e190` and `0x0049e210` pass `this + 0xa0` to modal/list registration helpers.
- Keyboard/control handling at `0x0049e6e0` uses `+0x1fc`, `+0x200`, `+0x204`, `+0x214`, `+0x224`, and `+0x228`.
- Draw/focus/background helpers at `0x0049f090`, `0x0049f1d0`, and `0x0049f2e0` use the focus id, tile context, and custom background fields.
- `ModelessDialogPane::HandleMouseEvent` at `0x004a0840` receives the secondary view as `this == object + 0xa0`; its secondary-relative accesses map back to base offsets `+0x208` through `+0x238`.
- 2026-05-31 IDA MCP `lookup_funcs` reconfirms key method starts and sizes including constructor `0x0049d8a0` size `0x148`, `OnCreate` `0x0049dfd0` size `0x1b9`, `OnShow` `0x0049e190` size `0x2e`, `OnHide` `0x0049e210` size `0x22`, control handling `0x0049e6e0` size `0x379`, slide helper `0x0049eac0` size `0xcd`, and final cluster function `sub_49FE20` ending at `0x0049feae`.
- 2026-05-31 IDA MCP decompilation of the constructor directly shows vtable stores at `+0x00/+0xa0/+0xa4`, title copy to `+0xf8`, config id at `+0x1f8`, control manager at `+0x1fc`, focus/control ids at `+0x200/+0x204/+0x214/+0x21c/+0x224`, state bytes at `+0x208/+0x209/+0x218/+0x229`, tile context at `+0x23c`, and custom background state through `+0x268`.
- `xrefs_to 0x00618a64` confirms the primary vtable is installed by constructor/destructor paths.

## Boundary Notes

- Browser/embedded-window input handlers in the `0x0046ad80-0x0046e9f4` area reference additional offsets such as `+0x11c`, `+0x120`, `+0x26c`, `+0x278`, and `+0x27c`. Those are derived/browser-pane fields or adjusted-this views, not confirmed base `DialogPane` fields.
- `AlertPane`, `BlueAlertPane`, `VersatileAlertPane`, and `UrlAlertPane` add derived tail fields beginning at `+0x26c` or later; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- `DialogInSession` also uses derived tail fields at `+0x26c` and `+0x270`; see [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md).
- `ModelessDialogPane` does not currently need a separate derived tail for its mouse-event state; see [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md) for the secondary-view offset mapping.
- Generated names in `class_DialogPane.cpp` are useful hints, but IDA evidence should control final field ownership and names.

## Cross-References

- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the constructor, lifecycle/control methods, vtable stores, and major field offsets; the page remains below `95+` because several state bytes after `+0x208` still have provisional source-facing names and some derived-dialog ownership boundaries remain under review.
- 2026-06-06 parent attachment:
  - What existed before: the layout had strong IDA-backed offsets and was scored above `80/80`, but `AUTOGEN_PARENT_UID` was blank.
  - Changed to: attached to [UID:00003T][DialogPane](by-class/DialogPane.md) without changing scores.
  - Summary/evidence: the `DialogPane` class page is scored `82/84`, links this layout as its consolidated state map, and the layout page documents constructor, lifecycle, control handling, modeless secondary-view mapping, and vtable-store evidence.
