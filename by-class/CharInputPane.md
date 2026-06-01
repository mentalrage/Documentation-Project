*** UID:00001P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CharInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_CharInputPane.cpp`

## Class Purpose

`CharInputPane` is a single-character prompt built on [UID:000077][LineInputPane](by-class/LineInputPane.md). It disables free text editing, accepts printable characters, converts them into translated character events, dismisses the prompt, clears pending player input state, forwards the accepted key to the base handler, and notifies the owner pane.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f28a0-0x004f2912` | constructor | Builds `LineInputPane`, installs `CharInputPane` vtables, and disables active edit input. |
| `0x004f2920-0x004f29c9` | `OnCharInput` | Accepts printable characters, handles Escape through base key input, rejects some extended keys, and notifies owner on accepted input. |
| `0x004f2e6f-0x004f2e84` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the scalar deleting destructor. |
| `0x004f2f70-0x004f2faa` | scalar deleting destructor | Tears down `LineInputPane` and conditionally deletes storage. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)

## Changes

- What existed before: the page documented constructor, char input, destructor adjustors, scalar destructor, and references, but metadata remained `0/0`.
- What it was changed to: scores were set to `72/86`.
- Summary and evidence: IDA boundaries and class role are strong; completion is limited by missing detailed field/layout notes and exact owner notification naming.
