*** UID:0000HY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ButtonControlPane

## Status

- Confidence: strong for reusable button/choice-control roles and documented exact child ranges, medium-high for final original file split.
- Proposed module: `ui/controls/ButtonControlPane.cpp`, with possible later split into `ChoiceControlPane.cpp` or `SliderControlPane.cpp`.
- Historical generated source candidates: `class_ButtonControlPane.cpp`, `class_ImageButtonControlPane.cpp`, `class_TextButtonExControlPane.cpp`, `class_CheckBoxControlPane.cpp`, `class_RadioGroupControlPane.cpp`, `class_SliderControlPane.cpp`, `class_SelectBoxControlPane.cpp`, and `class_SelectionControlPane.cpp`; use only as search context, not as authority.

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
- 2026-06-06 IDA MCP rechecked [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md): exact functions cover constructor `0x004fccf0-0x004fcd67`, selected accessor/setter `0x004fcd70-0x004fcda4`, mouse handler `0x004fcdb0-0x004fcdf7`, paint handler `0x004fce00-0x004fce7f`, and scalar deleting destructor `0x0049b0d0-0x0049b10b`. Constructor stores the `SelectBoxControlPane` vtable views at `0x0061d4c0`, `0x0061d528`, and `0x0061d558`; the selected-state setter has seven direct new-user dialog callers, supporting reusable choice-control ownership while preserving the final `ChoiceControlPane.cpp` naming caveat.

## Owner Inventory

| Owner area | Current documentation state | File-level decision |
| --- | --- | --- |
| `ButtonControlPane` base | [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) now records exact constructor/state/key/destructor/adjustor extents, vtable slots, broad derived-constructor fan-in, and remaining field-name gaps. | Keep as the base class in `ButtonControlPane.cpp`; do not emit final source until the class layout and field names are source-quality. |
| Text button family | [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) and the core aggregate cover the text-button constructor/paint/accessor anchors plus `TextButtonExControlPane` constructor, raw teardown, label-state methods, and scalar deleting destructor. | Keep grouped with the generic button file for now, while preserving possible later split names for original-source refinement. |
| Image and selection controls | `ImageButtonControlPane` has high constructor fan-in; [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) documents the selected-value setter/redraw helper. | Treat as reusable control infrastructure despite feature-dialog callers. |
| Radio and slider controls | [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md) records the radio constructor/option/hit-test/paint blocks, raw option-helper child, later radio text helpers, and SCRL001-backed slider methods. | Keep under the button/choice-control family; raw helper names remain provisional. |
| Checkbox and select-box controls | [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md) and [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md) now carry reconstructable, parent-ready evidence with exact vtable/core/destructor support. | Attach to this reusable control source family while retaining a possible `ChoiceControlPane.cpp` original-name caveat. |
| Destructor/thunk band | [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) maps adjustor thunks, scalar deleting destructors, vtable owners, exact child splits, and non-button exclusions. | Use as ownership evidence, not as a source body; wrappers/thunks should regenerate from class declarations. A004 Batch 046 split children now cover SelectBox, ImageButton, PopupMenu, RadioGroup, Slider, TextButton, and TextButtonEx backlog rows. |
| Neighbor exclusions | ProgressBar, StaticText, EPFImage, TargetOptionEdit, NumericString, Rectangle, Scrollable, TextEdit, and PopupMenu slices are called out on the core/destructor aggregate pages. | Keep excluded from this file page even where old address-neighborhood or stale decompiler labels overlap. |

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `86` | The page now has the projected path, family role, per-owner contents, exact memory/class links, current SelectBox attachment evidence, core/destructor aggregate routing, and explicit exclusions. A004 Batch 046 resolved the main destructor/thunk table-only backlog by adding exact child pages for SelectBox, ImageButton, PopupMenu, RadioGroup, Slider, TextButton, and TextButtonEx rows. |
| Confidence | `88` | Confidence is strong because the claims are backed by live IDA method/vtable checks and linked exact child pages. It improves because the major destructor/thunk endpoints and owner rows are now exact child docs, but final source-quality class declarations, field names, and original file boundaries remain partly provisional. |

## Remaining Work

- Continue source-split review for `ButtonControlPane.cpp` versus possible `ChoiceControlPane.cpp`/text-control splits; the main destructor/thunk backlog now has exact child pages under [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md).
- Revisit the original source split once class declarations and field names are stronger; current evidence supports a reusable `ButtonControlPane.cpp` family but still allows a later `ChoiceControlPane.cpp` or narrower text/selection split.
- Keep final C++ reconstruction blank until base/derived class layouts, state-field names, and helper names clear the 95/95 gate.

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
- [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md)
- [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md)
- [UID:0002XY][0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks](by-memory/0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks.md)
- [UID:0002XZ][0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md)
- [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md)
- [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md)
- [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md)
- [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md)
- [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md)
- [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md)
- [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md)
- [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md)

## Changes

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
