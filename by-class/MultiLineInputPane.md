*** UID:00008T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MultiLineInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_MultiLineInputPane.cpp`

## Class Purpose

`MultiLineInputPane` is a [UID:000077][LineInputPane](by-class/LineInputPane.md) variant for multi-line dialog input. Enter submits through the owner dialog and clears/rebounds the text buffer; Escape or Ctrl+C closes the dialog and clears player dialog state.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2c90-0x004f2cc4` | constructor | Builds `LineInputPane` and installs multi-line vtables. |
| `0x004f2cd0-0x004f2dca` | `OnKeyEvent` | Handles submit/close shortcuts and forwards remaining input to the text input child. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: the multi-line input variant has clear owner, purpose, constructor/key handler boundaries, vtable family, and base-class relationships documented, but it remains concise and lacks full source-level field/control detail. Evidence: linked `InputPaneBases` memory range, `LineInputPane` relationship, method address map, and text-menu dialog usage.
