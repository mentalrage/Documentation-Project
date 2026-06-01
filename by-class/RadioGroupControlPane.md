*** UID:0000BI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RadioGroupControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_RadioGroupControlPane.cpp`

## Class Purpose

`RadioGroupControlPane` manages a list of radio-button options with labels, selection state, text accessors, hit testing, rendering, and parent notification when the selected option changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| State/focus helpers | `0x00494b50-0x00494c49` | Control id, skip-hit-test flag, activation and deactivation. |
| `RadioGroupControlPane` | `0x00495f70-0x00495fc1` | Constructs the radio group layout/state. |
| `AddOption` | `0x00496010-0x004960e0` | Adds label and rectangle data to the option list. |
| `SetSelectedIndex` / mouse hit | `0x00496110-0x004962fa` | Updates selection and handles mouse-up hit testing. |
| `OnPaint` | `0x00496300-0x0049648c` | Draws each radio option and label with selected/enabled state. Older Ghidra/Wave2 reporting ended this early at `0x0049638f`; current IDA keeps the body through `0x0049648c`. |
| Raw option helpers | [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) | Unpromoted count/fetch/rect-copy helpers and a single-option radio paint helper. |
| Item/text helpers | `0x004967c0`, `0x00498170-0x00498ce0` | Value, item count, selected item, current text get/set. |
| Destructor/thunks | `0x0049afab-0x0049b486` | Destroys option list and base text-button/control state. |

## Evidence Notes

- Wave3 reports 22 methods, 19 aggregate ranges, 96.1 effective grade.
- IDA MCP reports 10 direct constructor xrefs to `0x00495f70`.
- 2026-05-25 IDA MCP raw-head inspection shows `0x004964a0-0x0049662f` belongs with RadioGroup option-list rendering glue, despite stale generated `TextButtonControlPane::SetTextResource` ownership at `0x004964e0`.
- The generated summary mentions parent `BrowserPane` notification; preserve that as observed behavior, but not as file ownership evidence.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `78/84`.
  - Before: The page was unevaluated despite documenting role, method clusters, raw helper ownership, constructor fanout, and generated-owner caveats.
  - After: Scored as moderate-high completion and strong confidence for the radio-button group control.
  - Evidence: Existing method notes, IDA MCP constructor/xref evidence, and raw-head inspection describe the class behavior and helper ownership.
