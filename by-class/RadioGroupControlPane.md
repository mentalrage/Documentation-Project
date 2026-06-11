*** UID:0000BI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RadioGroupControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_RadioGroupControlPane.cpp`
- Parent-gate status: reconstructable class attached to direct file parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), now `86/88`; final file split remains provisional, but the child and direct parent both clear the corrected 85/85 gate.

## Class Purpose

`RadioGroupControlPane` manages a list of radio-button options with labels, selection state, text accessors, hit testing, rendering, and parent notification when the selected option changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| State/focus helpers | `0x00494b50-0x00494c49` | Control id, skip-hit-test flag, activation and deactivation. |
| `RadioGroupControlPane` | `0x00495f70-0x00495fc2` | Constructs the radio group layout/state. |
| `AddOption` | `0x00496010-0x004960e1` | Adds label and rectangle data to the option list. |
| `SetSelectedIndex` / mouse hit | `0x00496110-0x004962fa` | Updates selection and handles mouse-up hit testing. |
| `OnPaint` | `0x00496300-0x0049648d` | Draws each radio option and label with selected/enabled state. Older Ghidra/Wave2 reporting ended this early at `0x0049638f`; current IDA keeps the body through `0x0049648d`. |
| Raw option helpers | [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) | Unpromoted count/fetch/rect-copy helpers and a single-option radio paint helper. |
| Item/text helpers | `0x004967c0`, `0x00498170-0x00498ce0` | Value, item count, selected item, current text get/set. |
| Destructor/thunks | `0x0049afab-0x0049b487` | Adjustor thunks branch into the scalar deleting destructor, which destroys option-list/base control state and is represented by exact destructor child docs. |

## Evidence Notes

- Wave3 reports 22 methods, 19 aggregate ranges, 96.1 effective grade.
- IDA MCP reports 10 direct constructor xrefs to `0x00495f70`.
- 2026-05-25 IDA MCP raw-head inspection shows `0x004964a0-0x0049662f` belongs with RadioGroup option-list rendering glue, despite stale generated `TextButtonControlPane::SetTextResource` ownership at `0x004964e0`.
- The generated summary mentions parent `BrowserPane` notification; preserve that as observed behavior, but not as file ownership evidence.
- 2026-06-07 A007 parent-gate recheck: IDA MCP reports modeled surrounding methods at `0x00495f70-0x00495fc2`, `0x00496010-0x004960e1`, `0x00496110-0x00496185`, `0x00496300-0x0049648d`, `0x00496630-0x004967b1`, `0x004967c0-0x004967f7`, and `0x00498170-0x0049817f`. Constructor/add/selection helpers have broad direct code xrefs, `OnPaint` has a vtable data xref at `0x00617eb4`, and raw helper starts [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) still have no inbound code or data xrefs. The same check reconfirmed radio asset string symbols around `0x00618750` and `0x00618784`.
- 2026-06-07 A001 Batch094 live IDA recheck reconfirmed function sizes for constructor `0x52`, `AddOption` `0xd1`, selection helper `0x75`, `OnPaint` `0x18d`, successor `SliderControlPane` constructor `0x181`, later text helper `0x0f`, adjustor thunk `0x0b`, and scalar deleting destructor `0x67`.
- 2026-06-07 A001 `xrefs_to` returned ten constructor code xrefs, broad `AddOption` fan-in from browser/object/profile/new-user style setup functions, a large selected-index helper xref set, `OnPaint` vtable data ref `0x00617eb4`, no inbound xrefs to raw helper starts `0x004964a0` or `0x004964e0`, and destructor refs from both adjustors plus primary vtable/data cell `0x00617e70`.
- 2026-06-07 A001 `callees` reconfirmed constructor dependency on the control base constructor, `AddOption` dependency on string/vector helpers, `OnPaint` dependency on `RBUTTON` EPF/palette render helpers and `DrawTextInRect`, and scalar deleting destructor dependency on option-list/base cleanup and delete dispatch.
- 2026-06-07 parent-gate check: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is `86/88` and explicitly owns the radio/choice-control family. This class now clears the corrected `85/85` attachment gate; the exact raw option-helper child can attach to this class, while final C++ remains withheld.

## Score Rationale

- Completion is `85` because the page now records the main constructor/add/selection/paint/helper method bands, broad constructor/add/selection xref evidence, vtable paint reachability, stale generated-owner rejection for the raw helper island, exact destructor/thunk child references, and the corrected parent assignment. It stays below final-source quality because the class layout, full field map, complete method inventory, and final `ButtonControlPane.cpp` versus narrower source split remain incomplete.
- Confidence is `87` because live IDA MCP evidence ties the method bands, vtable paint slot, raw helper island, destructor refs, and radio-button asset usage to `RadioGroupControlPane` behavior, and the direct file parent now clears `86/88`. It stays conservative because several helper names and source-file boundaries still depend on behavior-based reconstruction rather than source-quality names.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md)
- [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md)

## Changes

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The radio-button group control remained unclassified in autogen coverage despite documented project UI-control behavior and memory evidence.
  - After: The class is reconstructable but unassigned because the class completion score remains below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms modeled starts including `0x00495f70`, `0x00496010`, `0x00496110`, `0x00496300`, `0x004967c0`, `0x00498170`, and destructor thunk/delete-wrapper starts; `0x004964a0` remains a raw helper island as documented.

- 2026-05-30: Changed completion/confidence from `0/0` to `78/84`.
  - Before: The page was unevaluated despite documenting role, method clusters, raw helper ownership, constructor fanout, and generated-owner caveats.
  - After: Scored as moderate-high completion and strong confidence for the radio-button group control.
  - Evidence: Existing method notes, IDA MCP constructor/xref evidence, and raw-head inspection describe the class behavior and helper ownership.
- 2026-06-07 A007 Batch 004 parent-gate recheck:
  - Changed from `78/84` to `82/85`; `AUTOGEN_PARENT_UID` remains blank.
  - Evidence: fresh read-only IDA MCP rechecked constructor/add/selection/paint/successor method boundaries, broad code xrefs to constructor/add/selection helpers, the `OnPaint` vtable data xref, raw option-helper no-xref status, and radio-button asset string symbols. The page still stays below parent-attachment readiness because completion is under `85` and final class layout/source split details remain open.
- 2026-06-07 A001 Batch094 strict parent-gate update:
  - Changed from `82/85` to `85/87`; set `AUTOGEN_PARENT_UID:0000HY`.
  - Evidence: live IDA reconfirmed exact constructor/add/selection/paint/destructor sizes, broad constructor/add/selection xrefs, `OnPaint` vtable reachability, destructor refs, raw helper no-xref status, and direct parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) at `86/88`. Final C++ remains blank pending full field layout and source-quality helper names.
