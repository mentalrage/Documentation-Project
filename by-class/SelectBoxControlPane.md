*** UID:0000CQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelectBoxControlPane

## Status

- Confidence: strong for behavior, vtable identity, state field, and method boundaries; medium-high for final file grouping.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), with `ChoiceControlPane.cpp` still possible only as a later original-name/source-split refinement.
- Historical generated source candidate: `class_SelectBoxControlPane.cpp`; use only as search context, not as authority.
- Parent-gate status: reconstructable class attached to direct file parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), now `86/88`; this class now clears the corrected `85/85` gate for direct SelectBox destructor children.

## Class Purpose

`SelectBoxControlPane` displays a selectable framed box. It constructs a `ControlPane`-derived object, tracks selection activation, hit-tests mouse-down events against a host select region, calls the host selection callback, and paints double-width rectangle indication for selected or non-default state.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Destructor thunks | `0x0049af11-0x0049b10a` | Adjustor thunks and scalar deleting destructor. |
| `SelectBoxControlPane` | `0x004fccf0-0x004fcd67` | Constructs and clears selection state. |
| `IsSelected` | `0x004fcd70-0x004fcd77` | Returns the selected byte at object offset `+264`. |
| `SetSelected` | `0x004fcd80-0x004fcda4` | Updates selected byte `+264` and invalidates/redraws through vtable slot `+0x20` only when the state changes. |
| `OnMouseDown` | `0x004fcdb0-0x004fcdf7` | Hit-tests host selection region and invokes callback once. |
| `OnPaint` | `0x004fce00-0x004fce7e` | Draws selection frame/double border. |

## Evidence Notes

- 2026-06-06 live IDA MCP confirms exact functions at `0x004fccf0` (`0x78`), `0x004fcd70` (`0x7`), `0x004fcd80` (`0x24`), `0x004fcdb0` (`0x48`), `0x004fce00` (`0x7f`), thunk `0x0049af11` (`0xb`), scalar deleting destructor `0x0049b0d0` (`0x3b`), and next owner `0x004fce80` (`UserShapeSelectControlPane`, `0x135`).
- Constructor decompilation calls the base control constructor `0x004949e0`, installs `SelectBoxControlPane` vtable views at `0x0061d4c0`, `0x0061d528`, and `0x0061d558`, clears selected byte `+264`, and enables the pane through `0x005446b0`.
- The selected-state setter has seven direct callers in the new-user miscellaneous dialog path `0x004fc010`, covering shape/option state resets; the constructor and paint/mouse virtuals have no direct code callers because current evidence reaches them through construction/vtable data.
- Vtable xrefs tie `OnPaint` to slot data at `0x0061d504` and `OnMouseDown` to slot data at `0x0061d52c`; constructor vtable stores are at `0x004fcd2e`, `0x004fcd34`, and `0x004fcd3e`.
- Source grouping is still capped below final-source quality because this exact class island is physically closer to new-user shape dialogs, while the generic behavior and existing [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) file page keep it in the reusable button/choice-control family.
- 2026-06-08 A004 Batch 114 IDA recheck confirmed the same constructor/destructor/method cluster: constructor `0x004fccf0` installs vtables at object offsets `0`, `+160`, and `+164`, clears selected byte `+264`, and enables the control; setter `0x004fcd80` updates that byte and invalidates only on change; mouse/draw methods read the same inline state; scalar deleting destructor `0x0049b0d0` performs only base/control teardown and conditional allocator free. This establishes the actual direct parent for [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md).

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md)

## Score Rationale

- Completion is `85` because the page now records exact constructor/accessor/setter/mouse/paint/destructor boundaries, vtable stores, selected-state storage, setter fan-in, and direct file parent; it remains below final-source quality because original field names, complete layout, and the final `ButtonControlPane.cpp` versus narrower source split are still provisional.
- Confidence is `86` because live IDA callers, callees, vtable refs, and decompiled method bodies consistently support `SelectBoxControlPane` as the direct class owner under [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), with no evidence for a competing direct source owner.

## Changes

- 2026-06-08 A004 Batch 114 strict parent-gate update:
  - Changed from `82/84` to `85/86`; kept `AUTOGEN_PARENT_UID:0000HY`.
  - Evidence: live IDA rechecked constructor/accessor/setter/mouse/paint/destructor sizes and behavior, selected byte `+264`, setter fan-in, vtable data ownership, and direct parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) at `86/88`. Final C++ remains blank pending full field layout and source-quality names.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The selectable framed-box control remained unclassified in autogen coverage despite documented constructor, mouse, paint, and destructor-thunk evidence.
  - After: The class is reconstructable but unassigned because the class confidence and likely parent completion scores are below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms modeled starts at `0x004fccf0`, `0x004fcdb0`, `0x004fce00`, and destructor-thunk/deleting-destructor neighborhood starts at `0x0049af11` and `0x0049b100`; existing notes keep final source-file grouping open.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `78`.
- Evidence: the page has the class purpose, likely file ownership, recovered method table, core by-memory link, and direct IDA/Wave3 caveat for the constructor-xref gap; remaining uncertainty is final source-file grouping.

- 2026-06-06 live IDA parent-readiness pass:
  - Before: the page was reconstructable but unassigned, and it omitted the accessor/setter method split and vtable-store evidence.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, and parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).
  - Evidence: live IDA MCP rechecked the exact constructor/accessor/setter/mouse/paint/destructor boundaries, constructor vtable stores, vtable data refs, seven new-user caller sites into the selected-state setter, selected byte offset `+264`, and the `0x004fce80` next-owner boundary. C++ remains blank because field names and final original source split are still below 95/95.
