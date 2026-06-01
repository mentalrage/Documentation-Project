*** UID:0000CQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelectBoxControlPane

## Status

- Confidence: strong for behavior, medium for final file grouping.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) or `ChoiceControlPane.cpp`
- Current recovered file: `source-3/simroot_v2/class_SelectBoxControlPane.cpp`

## Class Purpose

`SelectBoxControlPane` displays a selectable framed box. It constructs a `ControlPane`-derived object, tracks selection activation, hit-tests mouse-down events against a host select region, calls the host selection callback, and paints double-width rectangle indication for selected or non-default state.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Destructor thunks | `0x0049af11-0x0049b10a` | Adjustor thunks and scalar deleting destructor. |
| `SelectBoxControlPane` | `0x004fccf0-0x004fcd67` | Constructs and clears selection state. |
| `OnMouseDown` | `0x004fcdb0-0x004fcdf7` | Hit-tests host selection region and invokes callback once. |
| `OnPaint` | `0x004fce00-0x004fce7e` | Draws selection frame/double border. |

## Evidence Notes

- Wave3 reports 6 methods, 97.1 effective grade, and summary "Checkbox-style control pane".
- IDA MCP reports no direct xrefs to `0x004fccf0`; this may be vtable/factory-created or recovered from lower metadata rather than direct constructor calls.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00019V][0x004fccf0-0x004fce7e.SelectBoxControlPane](by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `78`.
- Evidence: the page has the class purpose, likely file ownership, recovered method table, core by-memory link, and direct IDA/Wave3 caveat for the constructor-xref gap; remaining uncertainty is final source-file grouping.
