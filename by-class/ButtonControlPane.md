*** UID:00001E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ButtonControlPane

## Status

- Confidence: strong for base button role, medium for generated helper names.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_ButtonControlPane.cpp`

## Class Purpose

`ButtonControlPane` is the base clickable button control above `ControlPane`. It installs button-specific vtables, initializes pressed/selected flags, handles selected-state redraw, and contains key-activation evidence reused by derived button classes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ButtonControlPane` | `0x00494eb0-0x00494f37` | Constructs the base `ControlPane`, installs button vtables, clears button state. |
| `SetControlSelected` | `0x00494f40-0x00494f63` | Updates selected state and invalidates/redraws if it changed. |
| `OnKeyPress` | `0x00494f70-0x0049500c` | Space/Enter activation evidence; Wave3 keeps polluted derived-owner naming here. |

## Evidence Notes

- Wave3 reports 3 methods, class summary "Control widget for a clickable button", and aggregate ranges at `0x00494eb0-0x00494f37` and `0x00494f40-0x00494f63`.
- IDA MCP reports 9 direct xrefs to `0x00494eb0` from derived control constructors, including image, gender, direction, and pretty buttons.
- The generated `InitializeFittingRoomUserImage(true)` name is probably helper/owner pollution and should not be treated as fitting-room ownership.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- What existed before: the page documented the base button role, methods, and owner-pollution caveat, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `66/76`.
- Summary and evidence: constructor, selected-state update, key activation, and derived-constructor xrefs are covered; final helper names, event semantics, and class layout remain only partially documented.
