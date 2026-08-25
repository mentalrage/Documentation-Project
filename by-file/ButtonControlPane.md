*** UID:0000HY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ButtonControlPane

## 2026-08-14 B003 ChangePassword Dependency Incorporation

- The generated CPP includes `ButtonControlPane.h`; the combined guarded H is assembled from UID00001E followed by UID00006D. The base uses EPFTileContext/ControlPane includes and writes `m_handlesEnterKey = true`; the image class exposes constructor, visual-state, enable/disable, paint, image id, and image state.
- ChangePasswordDialogPane uses this file only for generic ImageButton controls `1` and `2`. Dialog actions, resource layouts, and packet behavior remain UID0000I3-owned. File score advances from `91/93` to `92/94` with both declarations closed.

## Status

- Confidence: very strong for reusable button/choice-control roles, complete Button/TextButtonEx/Slider declarations, ordinary-destructor source, compiler exclusions, and documented exact child ranges; the final historical broad/narrow file split remains inferred.
- Current module route: `ui/controls/ButtonControlPane.h/.cpp`, with possible historical later splits into `ChoiceControlPane.cpp` or `SliderControlPane.cpp` retained as alternatives rather than current owners.
- Historical generated source candidates: `class_ButtonControlPane.cpp`, `class_ImageButtonControlPane.cpp`, `class_TextButtonExControlPane.cpp`, `class_CheckBoxControlPane.cpp`, `class_RadioGroupControlPane.cpp`, `class_SliderControlPane.cpp`, `class_SelectBoxControlPane.cpp`, and `class_SelectionControlPane.cpp`; use only as search context, not as authority.

## File Role

This family is the generic clickable-control layer above `ControlPane`. It covers base button state, image buttons, extended text buttons, radio groups, sliders, select-box hit testing, and small selection helpers. `CheckBoxControlPane` remains a related choice-control class but now has a settled standalone source route and is not directly owned by this file.

The likely original organization was not one class per file. `ButtonControlPane`, `ImageButtonControlPane`, `TextButtonExControlPane`, `RadioGroupControlPane`, and `SliderControlPane` share the corrected dense core neighborhood [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md). The nearby [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) band is a non-emitting split container whose children belong to ProgressBarControlPane or base ControlPane. CheckBox's separate core at UID00011S, dedicated `0x150` class, exact 25/11/2 vtable family, and standalone source order 10/20/30 support [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md) rather than a current fold here. Its destructor/thunk adjacency remains useful family evidence only. `SelectBoxControlPane` is farther away at `0x004fccf0-0x004fce7e` but remains a generic button/choice-control family member and retains the UID0000HY route.

[UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) also sits in this local address neighborhood, but should stay in its own source candidate. It is a passive progress indicator, not a button/choice control, and IDA currently ties its constructor directly to [UID:0000MH][PatchPane](by-file/PatchPane.md).

The base class source route is now complete through [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) R8 at source position `10`. R8 includes complete `ControlPane`, forward-declares pointer/reference-only `Event` and `RectBounds`, emits the exact inline constructor and empty virtual destructor, declares `SetControlSelected(bool)` and protected `HandleKeyOrTextEvent(Event *)`, and closes the exact `0x10c` layout with one selected byte at `+0x108` plus natural tail alignment. The class declaration precedes derived-class definitions in generated `ButtonControlPane.cpp`.

The observed constructor order is preserved in source: `ControlPane(0, &bounds)`, inherited active false, selected false, inherited flags/reserved state set to `1`, then `SetMode(1)`. R7 supplies protected inherited state, so direct assignments are legal and source-faithful. Vtable stores, scalar deleting wrappers, secondary/tertiary adjustor thunks, object freeing, COMDAT/identical-code folding, EH/cookie code, and alignment remain compiler/linker output; no raw ABI, shared-wrapper marker comment, or vtable array belongs in this file.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ButtonControlPane` | `0x00494eb0-0x0049500c`; retained raw helper [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) | R8 supplies the exact declaration-before-definition source cause: `0x108` ControlPane base, selected byte `+0x108`, natural `0x10c` size, inline constructor/empty destructor, `SetControlSelected`, and current `HandleKeyOrTextEvent(Event *)`. The retained no-route selected-frame helper checks inherited `m_enabled` plus selected state and remains prose-only. Historical visible/show and `OnKeyPress` wording is superseded. |
| `TextButtonExControlPane` | `0x00495450-0x00495be3`; compiler support `0x0049b071-0x0049b087` and `0x0049b860-0x0049b8c7` | Complete `0x110` derived class; owns `TextBoxPane *m_labelTextBox`, emits the ordinary one-line destructor and retained `CalculateLabelRect` helpers, and uses `SetVisualState`, `Enable`/`Disable`, `AddToLayer`/`RemoveFromLayer`, `OnPaint`, and `GetText`. Adjustor/deleting entries are compiler-only. |
| `ImageButtonControlPane` | `0x00495bf0-0x00495f6b` | Very common EPF image button; IDA reports 306 direct constructor xrefs. `0x00495d10/0x00495d80` are virtual Enable/Disable overrides at inherited slots `+0x4c/+0x50`, selecting normal/disabled image state before the base transition, not mouse-enter/leave handlers. |
| `CheckBoxControlPane` | UID00011S `[0x00499d40,0x00499f0e)`, UID0004Y2 `[0x0049b8d0,0x0049b8d5)`, compiler UID00011Z/UID0004Y1 | Related but excluded standalone class. It owns checked-state accessors, EventHandler pointer/mouse handling, EPF tile/palette rendering, SetVisualState, and HitTestPart result `20` in `CheckBoxControlPane.cpp/.h`; its adjusted/scalar deleting forms are compiler-only. |
| `RadioGroupControlPane` | `0x00495f70-0x004967f7`, ordinary source destructor [UID:0004X2][0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw](by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md), [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md), and compiler support [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md)/[UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md) | Radio option list, exact 144-byte records, selection, text, paint, notification, and owned List cleanup. Human destructor source is only `delete m_options;`; adjusted/deleting ABI is compiler output. Inherited base `ControlPane` state helpers at `0x00494b80-0x00494c4a` are documented under [UID:000038][ControlPane](by-class/ControlPane.md), not RadioGroup ownership. |
| `SliderControlPane` | authored range `0x00496630-0x0049803a`; class [UID:0000DB][SliderControlPane](by-class/SliderControlPane.md); helpers UID0003NB/UID000223; compiler-only UID0002Y2/UID0002Y3 | Exact `0x2fc` ControlPane-derived SCRL001 selector with inherited range state, orientation, palette, twelve frames, active part, Point drag offset, pointer/key/timer/paint/hit-test surface, and authored process/notify helpers. The class emits in H with CPP children; deleting wrapper/adjustors emit no source. |
| `SelectionControlPane` | [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) | Tiny selected-value setter that writes `+0x10c` and invalidates/redraws immediately. |
| `SelectBoxControlPane` | `0x004fccf0-0x004fce7e` | Selectable framed box with `m_selected` at `+0x108`, `IsSelected`, `SetSelected`, adjusted EventHandler mouse-event selection, and paint behavior. NewUserMisc uses it externally for group resets rather than owning its callbacks. |

## Evidence Notes

- Wave3 class summaries for `ImageButtonControlPane`, `RadioGroupControlPane`, and `ButtonControlPane` were checked with `wave3.py show class ... --summary`.
- IDA MCP confirms `ImageButtonControlPane::ImageButtonControlPane` at `0x00495bf0` has 306 direct code xrefs, making it one of the broadest generic controls in this batch.
- IDA MCP confirms `ButtonControlPane::ButtonControlPane` at `0x00494eb0` has 9 direct xrefs, including derived controls such as image, gender, direction, and pretty buttons.
- `ButtonControlPane` generated code still contains likely polluted helper naming around `InitializeFittingRoomUserImage`; do not treat that as proof that the generic button base belongs to fitting-room code.
- `TextButtonExControlPane` generated code includes base/destructor owner-name pollution and a copied `Pane::~Pane` body at `0x00544580`; treat that as teardown evidence, not proof of file ownership.
- 2026-05-25 IDA MCP rechecked `0x00495450`: current generated `simroot_v2` places this constructor-like function under `FittingRoomUserImageControlPane`, but IDA decompilation shows generic `ButtonControlPane`/`TextButtonExControlPane` vtables and a text-provider child. Current callers reach it from `0x00517f30`, not from the fitting-room dialog constructor.
- 2026-06-21 Rule 26/B007 incorporated [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md) as retained private `TextButtonExControlPane::CalculateLabelRect` overloads in this control source family. The pass corrected the old half-open endpoint `0x00495be2` to `0x00495be3`, recorded `m_labelTextBox` as the best `TextBoxPane *` field name for `+0x10c`, rejected FittingRoom/generated owner pollution, and kept the broader possible `ChoiceControlPane.cpp` or narrower text-button split as a future file-layout caveat rather than a current owner change.
- 2026-05-26 IDA MCP rechecked [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md): constructor callers are two minimap toggles and the mail "Keep a copy" option, the second copied string is a palette/resource name, the primary vtable contains an omitted helper at `0x00499ec0`, and [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) are compiler adjustor thunks into `0x0049b110`.
- 2026-05-25 IDA MCP rechecked the raw `0x004964a0-0x0049662f` island. It is unpromoted in IDA, but the code pattern is RadioGroup option-list and radio-option painting glue; the generated `TextButtonControlPane::SetTextResource` owner for `0x004964e0` is stale.
- 2026-05-26 IDA MCP rechecked `SelectionControlPane::SetSelectionAndRefresh`: `0x00495cb0` is a real `0x19` helper that writes selected value offset `+0x10c` and tail-calls vtable slot `+0x20`. Its only current direct caller is `MusicControlDialog::TogglePauseState`, which passes pause/play frame ids `37`/`48` to control id `12`.
- 2026-06-06 IDA MCP rechecked [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md): exact functions cover constructor `0x004fccf0-0x004fcd67`, selected accessor/setter `0x004fcd70-0x004fcda4`, mouse handler `0x004fcdb0-0x004fcdf7`, paint handler `0x004fce00-0x004fce7f`, and scalar deleting destructor `0x0049b0d0-0x0049b10b`. Constructor stores the `SelectBoxControlPane` vtable views at `0x0061d4c0`, `0x0061d528`, and `0x0061d558`; the selected-state setter has seven direct new-user dialog callers, supporting reusable choice-control ownership while preserving the final `ChoiceControlPane.cpp` naming caveat.
- 2026-06-18 B002 source-quality pass resolved [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md) as a coherent generic control island with `bool m_selected` at `+0x108`, object size `0x10c`, primary/secondary/tertiary vtable views `0x0061d4c0`/`0x0061d528`/`0x0061d558`, EventHandler receiver adjustment from `this+0xa0`, no host callback/member field in the mouse handler, and seven NewUserMisc setter callers as external dialog-side group reset.
- 2026-06-21 B010 source-quality pass incorporated [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) as a retained raw ButtonControlPane selected-frame draw helper. It belongs in this `NexusTK/ui/controls/ButtonControlPane.cpp` source family, not `TextButtonControlPane`, `TextButtonExControlPane`, `SelectBoxControlPane`, GrafPort, or any feature owner implied by polluted GrafPort helper names. Generated output may keep the [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) empty marker for now; do not synthesize `sub_495010`, `FUN_00495010`, `ButtonControlPaneActiveRefreshHelper`, or a public API body until a caller/vtable/table route or retained-helper policy is proven.

## 2026-06-30 B010 Empty-Emitter Callback Evidence (Historical)

Accepted report `tools/leaser/Agents/Agent-B010/research/0000HY-ButtonControlPane-empty-emitter-family-source-quality.md` kept [UID:0000HY] as the generated source route for `NexusTK/ui/controls/ButtonControlPane.cpp`; no owner, emitter, split, rename, or new-file change was made. Its MCP and generated snapshot are retained as evidence-time history: command `2912` then showed 17 emitters, 2 filled, and 15 empty markers. That old marker count is not current callback truth; the UID0004EL callback installs complete base declaration R8 while preserving the report's valid per-child source/no-code decisions.

The MCP boundary facts at that historical cleanup checkpoint included `sub_494EB0` size `0x88`, `sub_495BF0` size `0xb5`, `sub_49B290` size `0x55`, `sub_495F70` size `0x52`, raw `0x004964a0` not a function, `sub_49B420` size `0x67`, `sub_49B0D0` size `0x3b`, `sub_495CB0` size `0x19`, `sub_496630` size `0x181`, historical `sub_49B5B0` size `0x3b`, `sub_49B930` size `0x3b`, `sub_495450` size `0x18c`, `sub_49B860` size `0x67`, and `sub_4FCCF0` size `0x78`. UID0002Y3 Gate 2B subsequently renamed only that Slider wrapper to `SliderControlPane__ScalarDeletingDestructor` while preserving its exact range, size, bytes, and xrefs.

The historical cleanup disposition covered all fifteen then-empty emitters. Its specialized-class and child decisions remain valid, but its marker-only conclusion for [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) is superseded by complete R8. The retained raw helper and compiler-only wrapper pages remain no-code; no speculative helper body or handwritten deleting/thunk implementation is introduced.

[UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) is proven by MCP as a single-block `sub_495CB0` body that writes `[ecx+0x10c]` from the stack argument, then tail-calls vtable slot `+0x20` with argument `0`; the only direct caller remains `sub_52A180` at `0x0052a1e2`. [UID:000223][0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers](by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md) is four `0x3b` source-authored Slider helpers at `0x0049b930`, `0x0049b970`, `0x0049b9b0`, and `0x0049b9f0`, mapped from `HandleKeyOrTextEvent` cases in `sub_497780` and scroll cases in `sub_497C60`; each updates inherited `ControlPane::m_rangeCurrent`/`m_rangeEnd` at `+0xfa/+0xfc` before vtable slot `+0x20` refresh.

[UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) remains no-code despite source-shaped bytes: MCP reports raw starts `0x004964a0`, `0x004964b0`, `0x004964c0`, and `0x004964e0` are not modeled functions and have no inbound xrefs; `0x00496620` only has one data xref from `0x00496525`. The live reachable `RadioGroupControlPane::OnPaint` function is `sub_496300` size `0x18d` with vtable data xref `0x00617eb4`. Scalar deleting destructor pages remain source-declared but compiler-generated binary wrappers, so they should regenerate from class destructor declarations rather than hand-authored source bodies.

## TextButtonExControlPane Source And Compiler Split

- [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md) is a complete `0x110` class: [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) occupies `0x10c`, followed by owned `TextBoxPane *m_labelTextBox` at `+0x10c`. The base and derived declarations now reside in H at source positions `10` and `20`, with one derived `[[CHILDREN]]` marker and blank class CPP channels.
- The derived source contract is constructor, virtual destructor, `SetVisualState`, `Enable`, `Disable`, `AddToLayer`, `RemoveFromLayer`, `OnPaint`, `GetText`, and two private `CalculateLabelRect` overloads. Earlier `SetState`, show/hide, and attach/detach labels are preserved as historical behavioral descriptions but superseded by inherited source-slot names.
- [UID:0003NA][0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown](by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md) is exact `[0x004955e0,0x00495615)`, 53 bytes, SHA256 `79C8CC6513105F1AC4BD4DBAD650CF17FB1ED9CA7EC22825358AFFA4F245DF9C`. Its only human source is `TextButtonExControlPane::~TextButtonExControlPane() { delete m_labelTextBox; }`; the exact vptr stores, null-safe virtual delete lowering, and implicit Pane teardown are compiler output.
- [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md) retains the two source-shaped `CalculateLabelRect` definitions. No direct branch, pointer, or vtable route reaches either raw start, but their field/text/geometry behavior and closed ranges justify retained private source under the class route.
- [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md) is the exact 103-byte complete-object deleting wrapper. It is semantic class evidence but FALSE/non-emitting: hidden bits 1/4, explicit vptr restoration, Pane teardown, operator-delete dispatch, and the `0x110` one-byte no-op path are not handwritten source.
- [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md) contains exact 11-byte `this-0xa0` and `this-0xa4` adjusted entries reached only from secondary/tertiary vtables. It remains NONE/FALSE/non-emitting.
- The exact compiler read-only-data island is `[0x00617d20,0x00617dc8)`, with 26/11/2 callable entries and deleting slots `0x00617d24 -> 0x0049b860`, `0x00617d90 -> 0x0049b071`, and `0x00617dc0 -> 0x0049b07c`. No vtable, RTTI, COL, thunk, deleting wrapper, padding, or raw ABI flag declaration belongs in source.
- Current source routing remains UID0003NA and authored method/helper children -> UID0000EK -> this file -> `NexusTK/ui/controls/ButtonControlPane.cpp/.h`. A narrower historical TextButtonEx file remains plausible but unsupported, so no speculative source-tree split is introduced.
- Generated acceptance requires exactly one TextButtonEx declaration in `ButtonControlPane.h`, one ordinary destructor plus both retained label-helper definitions in `ButtonControlPane.cpp`, and zero UID0002Y6/UID0002Y7 bodies, comments, or empty-emitter markers. Generated owner pollution such as fitting-room ownership or copied `Pane::~Pane` source is rejected.
- Applied IDA state now names/types/comments the complete family without changing that source split: `TextButtonExControlPane__Constructor` `[0x00495450,0x004955dc)`, `TextButtonExControlPane__Destructor` `[0x004955e0,0x00495615)`, `TextButtonExControlPane__ScalarDeletingDestructor` `[0x0049b860,0x0049b8c7)`, and `TextButtonExControlPane__ScalarDeletingDestructorAdjustorA0/A4` at `[0x0049b071,0x0049b07c)` / `[0x0049b07c,0x0049b087)`. Only an incomplete pointer-only `TextButtonExControlPane` type was added.
- The constructor has exact `this`, `const wchar_t *text`, and `const RectBounds *bounds` types with automatic persistent `text +0x50` and `bounds +0x54`; the wrapper and adjustors have exact `unsigned int flags` with automatic persistent entries at `+0xc` and `+0x4`. All five accepted function-repeatable comments are present, while regular/address channels remain blank.
- The newly modeled raw destructor's observed frame is solely `__return_address +0x4`, and its auto local is `void (__thiscall ***v2)(_DWORD)`. Those authoritative IDA presentations replace the predicted `+0x0` and two-argument local form; no coercion was attempted.
- Stale interior comments at `0x0049b863/0x0049b890/0x0049b8a2` were cleared. Protected bytes, exact ranges/fences, xrefs, UDTs, vtable/RTTI identities/comments, and unrelated entities are unchanged. Saved IDB SHA256 is `408F73923C6BDD17931E828365DC0D7D67F583FE6F0FDDA50103F45FB84461A7`.

## RadioGroupControlPane Ordinary Source / Compiler Support Split

- [UID:0000BI][RadioGroupControlPane](by-class/RadioGroupControlPane.md) is a complete `0x110` class with `List *m_options` at `+0x108` and `int m_selectedIndex` at `+0x10c`. `AddOption` constructs the List for `0x90`/144-byte records containing `RectBounds` plus `wchar_t[64]`; `RadioGroupOption` is the current human source-facing record name.
- [UID:0004X2][0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw](by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md) `[0x00495fd0,0x00496005)` is the exact 53-byte ordinary source destructor. The only authored body is `RadioGroupControlPane::~RadioGroupControlPane() { delete m_options; }`; compiler-supplied vptr writes and implicit Pane teardown stay outside human source.
- [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md) contains two exact 11-byte `this-0xa0`/`this-0xa4` adjusted deleting entries. [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md) is the exact 103-byte complete-object deleting wrapper with hidden storage flags, project operator-delete path, and `0x110` compiler no-op path. Both are FALSE/non-emitting with blank formals.
- The exact three-view RTTI/vtable island `[0x00617e6c,0x00617f10)`, SHA256 `340B72245692165BEB327A9FF5AFC63D990F72AE50436C04BC0931FB7B6E356E`, is compiler data generated from the class declaration; [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) documents its primary and adjusted deleting routes.
- Current source routing remains UID0004X2 -> UID0000BI -> this file -> `NexusTK/ui/controls/ButtonControlPane.cpp`. A narrower historical `ChoiceControlPane.cpp` or `RadioGroupControlPane.cpp` is plausible but unproven, so the existing broad route is retained and the split caveat remains explicit.
- Zero inbound xrefs and pointer encodings to the retained ordinary start cap confidence but do not erase coherent class-specific source. Feature/dialog callers are consumers only and do not own the reusable control definition.

## SliderControlPane Header, Layout, And Compiler Boundary

- [UID:0000DB][SliderControlPane](by-class/SliderControlPane.md) carries the complete destination-ready class declaration in H; its CPP channel is only `[[CHILDREN]]`. Authored children therefore appear in `ButtonControlPane.cpp` while one class declaration appears in `ButtonControlPane.h`.
- Exact object size is `0x2fc`: inherited `ControlPane` `[+0x000,+0x108)`, `bool m_isHorizontal` `+0x108`, natural alignment, `DLPalette *m_palette` `+0x10c`, `EPFTileContext m_frames[12]` `[+0x110,+0x2f0)`, `unsigned char m_activePart` `+0x2f0`, natural alignment, and `Point m_dragOffset` `[+0x2f4,+0x2fc)`.
- `+0xfa/+0xfc` are inherited `m_rangeCurrent`/`m_rangeEnd`; they are not duplicate Slider members. `+0x2f4/+0x2f8` are the two coordinates of `Point m_dragOffset`, not a rectangle.
- Current authored surface includes constructor, `SetCurrentValue`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `OnTimer`, `OnPaint`, `HitTestPart`, `GetPartRect`, interaction/reset/process helpers, drag/value notification, and four exact scroll helpers.
- No ordinary Slider destructor body or Slider-specific cleanup exists. The human source most likely relied on the implicit derived destructor, which remains virtual through the base. Do not invent an explicit `~SliderControlPane()` declaration or body.
- [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md) is the class-specific primary compiler wrapper: semantic owner UID0000DB, FALSE/non-emitting, blank formals. [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md) is the no-owner EventHandler/TimerHandler adjustor pair, likewise FALSE/non-emitting.
- Three exact vtable views at `0x00617f14`, `0x00617f7c`, and `0x00617fac`, constructor stores at `0x00496672/0x0049667d/0x00496687`, and three COLs at `0x00645bac/0x00645c0c/0x00645c20` prove the class/compiler relationship.
- Current source placement remains the shared `ButtonControlPane.h/.cpp` route because dense control-family adjacency, existing module ownership, and generated topology outweigh the unsupported standalone-file alternative. This is not a claim that the original split is symbol-proven.
- Generated acceptance requires exactly one Slider declaration in H, authored child bodies in CPP, and no UID0002Y2/UID0002Y3 marker or body. Historical direct-emitter and duplicate-field conclusions are preserved only as superseded evidence.

After scoped validation with generated refresh, `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` is expected to contain formal comments, `[[CHILDREN]]` expansions, and first-draft method bodies for the accepted child pages rather than the 15 stale empty markers reported at `validator-command-id: 000000002912`.

## Owner Inventory

| Owner area | Current documentation state | File-level decision |
| --- | --- | --- |
| `ButtonControlPane` base | [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) now records exact constructor/state/key-text/destructor/adjustor extents, vtable slots, broad derived-constructor fan-in, exact `0x10c` layout, and complete R8. | Emit R8 as the base declaration before derived definitions in `ButtonControlPane.cpp`; retain only exact original spelling/header split and raw-helper liveness as score caps. |
| Text button family | [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) covers the plain text-button source. UID0000EK now supplies the complete TextButtonEx H contract; UID0003NA supplies ordinary cleanup; UID0003NC supplies retained private helpers; UID0002Y6/UID0002Y7 and the vtable/RTTI island are compiler-only. | Keep grouped with the generic button file for now, emit only authored class/method/destructor/helper source, and preserve possible later split names for original-source refinement. |
| Image and selection controls | `ImageButtonControlPane` has high constructor fan-in; [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) documents the selected-value setter/redraw helper. | Treat as reusable control infrastructure despite feature-dialog callers. |
| Radio and slider controls | [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) records RadioGroup ordinary/compiler splits and the complete Slider authored range through `0x0049803a`. UID0004X2 carries human RadioGroup cleanup; UID0002YB/UID0002YC are compiler support. Slider class UID0000DB carries exact H/children; UID0002Y2/UID0002Y3 are compiler support. [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) remains a separate non-emitting split container. | Keep RadioGroup/Slider under this current source family. Emit UID0004X2 for RadioGroup cleanup and Slider authored class/method children only; never emit their adjusted/deleting ABI pages. The former `0x00498170-0x00498ce0` later-radio claim remains rejected because those starts are PopupMenu/MenuPane forwarders. |
| Checkbox and select-box controls | [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md) has a settled standalone CPP/H route with exact source positions and compiler exclusions. [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md) retains its current reusable-family route. | Keep CheckBox as related family context but excluded from this file; do not fold its source into ButtonControlPane.cpp. Retain SelectBox's separate grouping caveat independently. |
| Destructor/thunk band | [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) maps adjustor thunks, scalar deleting destructors, vtable owners, exact child splits, and non-button exclusions. | Use as ownership evidence, not as a source body; wrappers/thunks should regenerate from class declarations. A004 Batch 046 split children now cover SelectBox, ImageButton, PopupMenu, RadioGroup, Slider, TextButton, and TextButtonEx backlog rows. |
| Neighbor exclusions | ProgressBar, StaticText, EPFImage, TargetOptionEdit, NumericString, Rectangle, Scrollable, TextEdit, and PopupMenu slices are called out on the core/destructor aggregate pages. | Keep excluded from this file page even where old address-neighborhood or stale decompiler labels overlap. |

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `91` | In addition to complete R8 and the existing family union, the page now closes the TextButtonEx `0x110` layout, complete H contract, ordinary destructor, retained helpers, exact compiler-wrapper/adjustor/vtable exclusion, corrected inherited names, source order, and generated topology. |
| Confidence | `93` | Constructor/ordinary/wrapper vptr stores, exact field lifecycle, allocation size, inherited slots, RTTI/vtable cells, raw bytes, and source/compiler equivalence converge. Exact historical file split and private/helper spellings remain bounded caps. |

## Remaining Work

- Continue source-split review for `ButtonControlPane.cpp` versus possible `ChoiceControlPane.cpp`/text-control splits; the main destructor/thunk backlog now has exact child pages under [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md).
- Revisit the original source split once class declarations and field names are stronger; current evidence supports a reusable `ButtonControlPane.cpp` family but still allows a later `ChoiceControlPane.cpp` or narrower text/selection split.
- Preserve R8 as the complete base declaration at position `10`; continue separate source-split review only for specialized button families and the retained no-route helper, not as a blocker on the accepted base class.
- Preserve RadioGroup position `20` ordinary source child UID0004X2 and keep UID0002YB/UID0002YC absent from generated source; future file-split work must not collapse that source/compiler boundary.
- Preserve Slider's complete H declaration and authored children while keeping UID0002Y2/UID0002Y3 absent from generated source; future source-split work must not collapse this human-source/compiler-support boundary.
- Preserve TextButtonEx source positions and its UID0003NA/UID0003NC authored children while keeping UID0002Y6/UID0002Y7 and raw vtable/RTTI data absent from generated source; future source-split work must not collapse that boundary.

## UID0002XW Source And Compiler Boundary

- [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md) is one exact 59-byte deleting entry shared by ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane primary vtables.
- [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md) supplies the same four classes' `this-0xa0` and `this-0xa4` adjusted entries through eight secondary/tertiary vtable cells.
- The target always performs Pane teardown, conditionally calls operator delete for deleting-flags bit 1, and routes bit 4 through a one-byte no-op helper with size `0x10c`. It performs no Button/Select/Weather/Rain-specific work.
- The human Button source remains the complete class declaration and its explicit inline empty virtual destructor. Select/Weather/Rain retain their own likely implicit destructor source shape. Neither UID0002XW nor UID0002XV is a source function owned by this file.
- The single equal body is best explained by compiler COMDAT/identical-code folding. Exact linker-option spelling is unproved, but the source/compiler boundary is not: generated `ButtonControlPane.cpp` must contain zero UID0002XW annotations/comments after refresh.
- Historical generated comment output for UID0002XW was a documentation-routing artifact, not plausible developer source. It must not be preserved as a no-code marker under this file.

## Cross-References

- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md)
- [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md)
- [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md)
- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000U7][CheckBoxControlPaneSetVisualState_00499EC0](by-item/CheckBoxControlPaneSetVisualState_00499EC0.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md)
- [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md)
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:0000BI][RadioGroupControlPane](by-class/RadioGroupControlPane.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0004X2][0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw](by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md)
- [UID:0000DB][SliderControlPane](by-class/SliderControlPane.md)
- [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md)
- [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md)
- [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md)
- [UID:0002XY][0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks](by-memory/0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks.md)
- [UID:0002XZ][0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md)
- [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md)
- [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md)
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md)
- [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md)
- [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md)
- [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md)
- [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md)
- [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md)
- [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md)

## Changes

- 2026-07-29 B004 post-IDA reconciliation:
  - Recorded the applied five-function TextButtonEx IDA family, exact signatures/comment channels, automatic frame entries, raw-destructor bounded normalization, protected-state readback, and saved-IDB SHA without changing source routing or generated acceptance criteria.
- 2026-07-28 B004 UID0002Y7 accepted implementation callback:
  - Raised `90/92 -> 91/93`, retained FILE ownership and `NexusTK/ui/controls/` route, and preserved every unrelated Button/Image/Selection/Radio/Slider/CheckBox/SelectBox decision.
  - Added the complete TextButtonEx H/layout/method contract, exact UID0003NA human destructor, retained UID0003NC private helpers, UID0002Y6/UID0002Y7 compiler exclusions, 26/11/2 vtable topology, corrected inherited method names, source order, rejected owner/file alternatives, and exact generated acceptance topology.
- 2026-07-26 B002 UID0002M9 CheckBox source-route reconciliation:
  - Preserved all Button/Image/Text/Radio/Slider/SelectBox/Selection ownership, scores, source formals, compiler relationships, and historical family evidence.
  - Reclassified CheckBox from a possible direct member of this source file to a related but excluded standalone source module UID0000I7.
  - Added the exact UID00011S/UID0004Y2 authored split, UID00011Z/UID0004Y1 compiler-only split, SetVisualState/HitTestPart identities, and explicit rejection of folding CheckBox source into ButtonControlPane.cpp.

- 2026-07-25 B005 accepted UID0002YC support synchronization:
  - Kept `90/92`, FILE ownership, proposed `NexusTK/ui/controls/` path, full current class union, and broad/narrow historical source-split caveat.
  - Added the exact RadioGroup ordinary-source/compiler-support split: UID0004X2 owns `delete m_options;`, UID0002YB/UID0002YC remain compiler-only, and UID000252 records the three-view vtable island.
  - Added exact `0x110` layout, List ownership, 144-byte `RadioGroupOption` record, no-xref confidence cap, generated routing requirement, and updated address/source inventories without removing unrelated family evidence.
- 2026-07-23 B002 UID0002XW source-quality callback:
  - Score, FILE route, proposed path, class union, base/derived source declarations, and all unrelated child dispositions unchanged.
  - Added the exact four-class primary/eight-view adjusted compiler relationship, source-cause split, bit-4 no-op correction, COMDAT/folding rationale, and explicit rejection of generated UID0002XW comment output.
- 2026-07-16 B003 UID0004EL support implementation:
  - Raised `88/89 -> 90/92`; retained `NexusTK/ui/controls/`, FILE ownership, and the full current button/choice-control union.
  - Added R8 as the complete base declaration-before-definition cause with exact `0x10c` layout, inline constructor/empty destructor, selected-state declaration, current `HandleKeyOrTextEvent(Event *)` interface, and protected inherited-state contract from R7.
  - Historicalized the command-2912 marker-only snapshot and `OnKeyPress` alias without deleting its valid evidence; specialized class/child/no-code decisions remain unchanged.
  - Preserved all unrelated Text/Image/Selection/Radio/Slider/CheckBox/SelectBox facts, ranges, routes, source-split caveats, raw-helper negatives, and compiler exclusions.

- 2026-07-13 B005 UID0004BP support synchronization:
  - Kept `88/89`, route, family ownership, raw-helper no-route proof, and all unrelated class/file-split caveats unchanged.
  - Corrected ImageButton `0x00495d10/0x00495d80` to Enable/Disable, recorded its inherited `+0x4c/+0x50` target contract, and changed current `+0x101` wording from visible to `m_enabled`; visible/show remains only superseded history because Pane visibility is `+0xb4`.

- 2026-05-30: Grading changed from `0/0` to `78/82`.
  - Before: page documented the reusable button/choice-control family, proposed file grouping, class/memory/type links, and IDA/Wave3 caveats but remained unevaluated.
  - After: score reflects documented base button, image button, text-button, checkbox, radio group, slider, selection, and select-box relationships while keeping final file-split and helper-name pollution caveats.
  - Evidence: recorded IDA checks cover constructor xrefs, raw radio-option helper ownership, checkbox caller/resource evidence, selection setter behavior, and cross-links to the core/destructor memory ranges.
- 2026-06-02: Filled the validator projected path from the existing proposed module.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the status section places the family in `ui/controls/ButtonControlPane.cpp`.
  - After: projected path is `NexusTK/ui/controls/`, matching the documented button/choice-control module grouping.
  - Evidence: the page's proposed contents keep `ButtonControlPane`, image/text buttons, checkboxes, radio groups, slider controls, selection helpers, and select-box controls under the shared control source family.
- 2026-06-06 SelectBoxControlPane parent-readiness pass:
  - Before: the file page stayed at `78/82`, which kept [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md) below the documented parent-attach gate even after the class was marked reconstructable.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Evidence: live IDA MCP rechecked the select-box constructor/accessor/setter/mouse/paint/destructor boundaries, vtable stores, vtable slot refs, selected-state field, new-user setter callers, and boundary before `UserShapeSelectControlPane`. The file remains below final-source level because several other button-family classes still have source-split and helper-name caveats.
- 2026-06-07 owner-inventory pass:
  - Before: the page listed the button/choice-control family and SelectBox readiness but did not summarize current child ownership, exclusions, and score rationale in one place.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:86`, with an owner inventory, score rationale, and remaining-work list.
  - Evidence: existing class and memory pages now cover the base `ButtonControlPane` exact method set, the `ButtonChoiceControlCore` function-band audit, the `ButtonChoiceControlDestructors` ownership map, SelectBox parent attachment, checkbox/type evidence, and excluded neighboring controls. The score stays below final-source quality because unresolved wrapper child pages, helper names, and original file split questions remain.
- 2026-06-07 A004 Batch 046 split-recheck:
  - Before: scores were `84/86`, and the remaining-work list still called out table-only destructor/thunk rows for several button/choice-control owners.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Evidence: A004 read-only IDA MCP confirmed exact half-open endpoints, vtable/data xrefs, adjustor-to-scalar-destructor branch refs, and padding slices for SelectBox, ImageButton, PopupMenu, RadioGroup, Slider, TextButton, and TextButtonEx destructor/thunk rows; those rows now have exact child pages linked from this file and [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md).
- 2026-06-12 C001 Goal 2 boundary correction:
  - Scores and projected path unchanged.
  - Updated the core range from stale `0x00494b50-0x00499e30` to [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md), kept the preceding state-helper band separate, and rejected the old `0x00498170-0x00498ce0` RadioGroup claim after live IDA showed those functions are PopupMenu/MenuPane forwarders.
- 2026-06-13 B002 state-helper split repair:
  - Scores unchanged.
  - Repaired stale RadioGroup/Button wording after [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) was split into exact children. The modeled `0x00494b80-0x00494c4a` helpers now route to [UID:000038][ControlPane](by-class/ControlPane.md), and the `0x00494b50` helper routes to [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md).
- 2026-06-18 B002 SelectBox source-quality support update:
  - Scores unchanged.
  - Added the resolved SelectBox source route: [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md) remains in this generic button/choice-control family, NewUserMisc is a consumer only, and a future `ChoiceControlPane.cpp` split remains a caveat rather than current owner evidence.
- 2026-06-21 Rule 26/B007 TextButtonEx label-helper support update:
  - Scores unchanged.
  - Added the corrected [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md) range and source-quality conclusion to the TextButtonEx family inventory. The child now carries first-draft `CalculateLabelRect` C++, while this file remains a source-family route rather than a file-scope declaration emitter.
- 2026-06-21 B010 ButtonControlPane selected-frame helper support update (historical terminology superseded above):
  - Scores unchanged.
  - Added [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) to the ButtonControlPane proposed contents as retained raw source-shaped code. That pass called `+0x101` a visible flag; current evidence supersedes the spelling with inherited `m_enabled`. The selected flag `+0x108`, GrafPort draw/blit mode `+0x70`, bounds `+0x44`, `SetDrawColor(1)`, and `DrawRectFrame(&m_bounds)` facts remain valid, while the generated C++ marker stays blank until route/liveness evidence improves.
- 2026-06-30 B010 empty-emitter family implementation:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`; owner, emitter, projected path, split, and filename unchanged.
  - Evidence: accepted B010 report incorporated current MCP `supervisor_resume_20260629` function sizes/xrefs, generated file freshness `000000002912`, raw radio-helper no-route proof, scalar deleting destructor wrapper proof, exact SelectionControlPane setter body, and exact SliderControlPane scroll-helper bodies. The generated output should now refresh from child pages instead of preserving the fifteen empty markers.
