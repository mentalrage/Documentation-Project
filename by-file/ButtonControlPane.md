*** UID:0000HY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ButtonControlPane

## Status

- Confidence: strong for reusable button/choice-control roles, medium for final original file split.
- Proposed module: `ui/controls/ButtonControlPane.cpp`, with possible later split into `ChoiceControlPane.cpp` or `SliderControlPane.cpp`.
- Current recovered sources: `source-3/simroot_v2/class_ButtonControlPane.cpp`, `class_ImageButtonControlPane.cpp`, `class_TextButtonExControlPane.cpp`, `class_CheckBoxControlPane.cpp`, `class_RadioGroupControlPane.cpp`, `class_SliderControlPane.cpp`, `class_SelectBoxControlPane.cpp`, and `class_SelectionControlPane.cpp`.

## File Role

This family is the generic clickable-control layer above `ControlPane`. It covers base button state, image buttons, extended text buttons, checkboxes, radio groups, sliders, select-box hit testing, and small selection helpers.

The likely original organization was not one class per file. `ButtonControlPane`, `ImageButtonControlPane`, `TextButtonExControlPane`, `CheckBoxControlPane`, `RadioGroupControlPane`, and `SliderControlPane` share a dense address neighborhood around `0x00494b50-0x00499e30`, with destructor/thunk support around `0x0049af11-0x0049b8d5`. `SelectBoxControlPane` is farther away at `0x004fccf0-0x004fce7e` but uses the same `ControlPane`/selection callback idiom.

[UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) also sits in this local address neighborhood, but should stay in its own source candidate. It is a passive progress indicator, not a button/choice control, and IDA currently ties its constructor directly to [UID:0000MH][PatchPane](by-file/PatchPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ButtonControlPane` | `0x00494eb0-0x0049500c` | Base clickable button state, selected-state refresh, key activation evidence. |
| `TextButtonExControlPane` | `0x00495450-0x00495940`, `0x0049b860` | Text-button construction, text-label sub-pane management, BUTTONEX-style rendering, show/hide and base teardown. |
| `ImageButtonControlPane` | `0x00495bf0-0x00495f6b` | Very common EPF image button; IDA reports 306 direct constructor xrefs. |
| `CheckBoxControlPane` | `0x00499d40-0x00499f0e`, `0x0049b8d0` | Toggleable checkbox with checked-state accessors, tile/palette rendering, omitted vtable-only state helper, and type id `20`. |
| `RadioGroupControlPane` | `0x00494b50-0x00498ce0`, including [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) | Radio option list, selection, text, paint, raw option helper glue, and notification behavior. |
| `SliderControlPane` | `0x00496630-0x00497885` | SCRL001-backed value/scroll selector with drag, key, and repeat timer handling. |
| `SelectionControlPane` | [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) | Tiny selected-value setter that writes `+0x10c` and invalidates/redraws immediately. |
| `SelectBoxControlPane` | `0x004fccf0-0x004fce7e` | Selectable framed box with hit-test callback behavior. |

## Evidence Notes

- Wave3 class summaries for `ImageButtonControlPane`, `RadioGroupControlPane`, and `ButtonControlPane` were checked with `wave3.py show class ... --summary`.
- IDA MCP confirms `ImageButtonControlPane::ImageButtonControlPane` at `0x00495bf0` has 306 direct code xrefs, making it one of the broadest generic controls in this batch.
- IDA MCP confirms `ButtonControlPane::ButtonControlPane` at `0x00494eb0` has 9 direct xrefs, including derived controls such as image, gender, direction, and pretty buttons.
- `ButtonControlPane` generated code still contains likely polluted helper naming around `InitializeFittingRoomUserImage`; do not treat that as proof that the generic button base belongs to fitting-room code.
- `TextButtonExControlPane` generated code includes base/destructor owner-name pollution and a copied `Pane::~Pane` body at `0x00544580`; treat that as teardown evidence, not proof of file ownership.
- 2026-05-25 IDA MCP rechecked `0x00495450`: current generated `simroot_v2` places this constructor-like function under `FittingRoomUserImageControlPane`, but IDA decompilation shows generic `ButtonControlPane`/`TextButtonExControlPane` vtables and a text-provider child. Current callers reach it from `0x00517f30`, not from the fitting-room dialog constructor.
- 2026-05-26 IDA MCP rechecked [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md): constructor callers are two minimap toggles and the mail "Keep a copy" option, the second copied string is a palette/resource name, the primary vtable contains an omitted helper at `0x00499ec0`, and [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) are compiler adjustor thunks into `0x0049b110`.
- 2026-05-25 IDA MCP rechecked the raw `0x004964a0-0x0049662f` island. It is unpromoted in IDA, but the code pattern is RadioGroup option-list and radio-option painting glue; the generated `TextButtonControlPane::SetTextResource` owner for `0x004964e0` is stale.
- 2026-05-26 IDA MCP rechecked `SelectionControlPane::SetSelectionAndRefresh`: `0x00495cb0` is a real `0x19` helper that writes selected value offset `+0x10c` and tail-calls vtable slot `+0x20`. Its only current direct caller is `MusicControlDialog::TogglePauseState`, which passes pause/play frame ids `37`/`48` to control id `12`.

## Cross-References

- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md)
- [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md)
- [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md)
- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:0000BI][RadioGroupControlPane](by-class/RadioGroupControlPane.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0000DB][SliderControlPane](by-class/SliderControlPane.md)
- [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md)
- [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/82`.
  - Before: page documented the reusable button/choice-control family, proposed file grouping, class/memory/type links, and IDA/Wave3 caveats but remained unevaluated.
  - After: score reflects documented base button, image button, text-button, checkbox, radio group, slider, selection, and select-box relationships while keeping final file-split and helper-name pollution caveats.
  - Evidence: recorded IDA checks cover constructor xrefs, raw radio-option helper ownership, checkbox caller/resource evidence, selection setter behavior, and cross-links to the core/destructor memory ranges.
- 2026-06-02: Filled the validator projected path from the existing proposed module.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the status section places the family in `ui/controls/ButtonControlPane.cpp`.
  - After: projected path is `NexusTK/ui/controls/`, matching the documented button/choice-control module grouping.
  - Evidence: the page's proposed contents keep `ButtonControlPane`, image/text buttons, checkboxes, radio groups, slider controls, selection helpers, and select-box controls under the shared control source family.
