*** UID:00001O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CharArgsInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_CharArgsInputPane.cpp`

## Class Purpose

`CharArgsInputPane` is a character-argument prompt derived from [UID:000077][LineInputPane](by-class/LineInputPane.md). It accepts alphabetic characters, comma, and space as translated input while passing standard control keys through to the base handler.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2a60-0x004f2ad2` | constructor | Builds `LineInputPane`, installs character-argument vtables, and disables active edit input. |
| `0x004f2ae0-0x004f2b73` | `OnKeyInput` | Filters alphabetic/comma/space input and forwards accepted/control events to `LineInputPane::HandleKeyInput`. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- What existed before: the page documented class role, constructor, key filter, and references, but metadata remained `0/0`.
- What it was changed to: scores were set to `70/86`.
- Summary and evidence: the class is simple and IDA boundaries are strong; completion is capped because detailed field layout, accepted-key edge cases, and final header form are not fully expanded here.
