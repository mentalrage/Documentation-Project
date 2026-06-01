*** UID:000035 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfirmInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Constructor range: [UID:0001N4][0x005b75d0-0x005b760d.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760d.ConfirmInputPaneConstructor.md)
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_ConfirmInputPane.cpp`

## Class Purpose

`ConfirmInputPane` is a yes/no confirmation prompt built on [UID:00001P][CharInputPane](by-class/CharInputPane.md). When the text source contains one character and that character is `y` or `Y`, it invokes the stored confirmation action object. Destruction also tears down a stored parent dialog/reference.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2a10-0x004f2a57` | `OnEnterKey` | Reads the single-character response and invokes the confirmation action on `y`/`Y`. |
| `0x004f2e85-0x004f2e9a` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the scalar deleting destructor. |
| `0x004f2fb0-0x004f3016` | scalar deleting destructor | Destroys parent dialog/reference, tears down `LineInputPane`, and conditionally deletes. |
| `0x005b75d0-0x005b760d` | constructor | Builds `CharInputPane`, stores confirmation action/context, and installs vtables. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/86`.
  - Summary/evidence: class role, constructor, enter-key behavior, destructor/adjustor thunks, vtable family, and base-class relationships are documented from IDA-backed ranges; remaining work is detailed member naming and final C++ body reconstruction.
