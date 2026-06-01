*** UID:00009J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumberArgsInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_NumberArgsInputPane.cpp`

## Class Purpose

`NumberArgsInputPane` is a numeric-argument prompt derived from [UID:000077][LineInputPane](by-class/LineInputPane.md). It accepts digits, comma, and space, which matches command inputs that accept one or more numeric arguments.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2b80-0x004f2bf2` | constructor | Builds `LineInputPane`, installs numeric-argument vtables, and configures the edit child. |
| `0x004f2c00-0x004f2c84` | `OnKeyInput` | Filters digit/comma/space input and forwards accepted/control events to `LineInputPane::HandleKeyInput`. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already had purpose, range, vtable, method, and cross-reference notes.
- Changed to: `COMPLETION:66` and `CONFIDENCE:82`.
- Evidence: the small class has IDA-backed constructor/key-filter boundaries and clear source-family placement; completion remains moderate because the page lacks raw code detail, caller inventory, and field/control layout beyond the main behavior.
