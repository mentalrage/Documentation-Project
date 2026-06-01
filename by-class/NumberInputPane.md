*** UID:00009L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumberInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_NumberInputPane.cpp`

## Class Purpose

`NumberInputPane` is a numeric-only [UID:000077][LineInputPane](by-class/LineInputPane.md) variant. It disables free text input and filters key-down events so digits are converted to translated character events while control keys pass through to the base handler.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f27a0-0x004f2812` | constructor | Builds `LineInputPane`, installs numeric input vtables, and disables active edit input. |
| `0x004f2820-0x004f289a` | `HandleKeyInput` | Allows digits and control keys; forwards accepted events to `LineInputPane::HandleKeyInput`. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already captured role, source file, vtable family, and two IDA-backed methods.
- Changed to: `COMPLETION:66` and `CONFIDENCE:82`.
- Evidence: constructor and key-filter behavior are well identified and source-family placement is strong; completion stays moderate because raw body details, callers, field/control layout, and reconstructed C++ are not yet exhaustive.
