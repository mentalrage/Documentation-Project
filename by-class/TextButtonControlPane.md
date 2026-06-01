*** UID:0000EJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextButtonControlPane

## Status

- Confidence: strong for class role.
- Likely source file: [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_TextButtonControlPane.cpp`

## Class Purpose

`TextButtonControlPane` is a text-labeled button control. It stores a dynamically allocated wide-string text buffer, paints a beveled button, draws the centered label, and supports text/resource updates.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TextButtonControlPane::TextButtonControlPane` | `0x00495040-0x0049512e` | Constructs base control/button state and copies label text. |
| `~TextButtonControlPane` | `0x00495130-0x004951a2` | Frees text resource and chains to parent destructor. |
| `GetText` | `0x004951b0-0x00495217` | Copies clamped text into caller buffer. |
| `OnPaint` | `0x00495220-0x0049544f` | Draws beveled button frame, centered text, focus/hover frame. |
| `SetTextResource` | `0x004964e0`, generated/provisional only | Current `simroot_v2` emits this row, but raw IDA evidence maps `0x004964e0-0x0049662f` to [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md). Do not treat this as a confirmed text-button method. |
| `DrawTextInRect` | `0x004bad70-0x004baf92` | Shared wrapped text draw helper; see item doc. |

## Current simroot_v2 Caveat

2026-05-25 recheck without running `wave3.py`: active `simroot_v2/class_TextButtonControlPane.cpp` still emits `SetTextResource` at `0x004964e0`, but IDA MCP still reports that address as `Not a function`. Active `simroot_v2/class_RadioGroupControlPane.cpp` has the promoted radio-button paint loop at `0x00496300`; the unpromoted `0x004964e0` island remains a RadioGroup option-helper/table caveat, not confirmed `TextButtonControlPane` behavior.

## Cross-References

- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0000UJ][DrawTextInRect_004BAD70](by-item/DrawTextInRect_004BAD70.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `82`.
- Evidence: the page documents button role, constructor/destructor/get-text/paint ranges, shared draw helper, destructor/core memory links, and the `SetTextResource` generated-data caveat; confidence remains capped by provisional helper ownership around the radio-group island.
