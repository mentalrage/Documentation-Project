*** UID:00006D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ImageButtonControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_ImageButtonControlPane.cpp`

## Class Purpose

`ImageButtonControlPane` is the generic EPF image-button control. It constructs over an image id and pane definition, tracks hover/press state, refreshes visual state on mouse transitions, and paints an EPF sprite frame based on state and skin mode.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ImageButtonControlPane` | `0x00495bf0-0x00495ca4` | Constructs the image button and installs image-button vtables. |
| `SetState` | `0x00495cd0-0x00495d0a` | Changes state and triggers visual refresh. |
| `OnMouseEnter` / `OnMouseLeave` | `0x00495d10-0x00495de5` | Resets state around hover/leave transitions. |
| `OnPaint` | `0x00495df0-0x00495f6b` | Selects and draws image-button EPF frames. |
| Destructor/thunks | `0x0049af69-0x0049b2e4` | This-adjustor and scalar deleting destructor. |

## Evidence Notes

- Wave3 summary reports 8 methods, 96.3 effective grade, and aggregate memory coverage.
- IDA MCP reports 306 direct xrefs to constructor `0x00495bf0`, confirming this as a broadly reused generic UI control.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: generic EPF image-button role, constructor/state/mouse/paint/destructor method inventory, broad reuse evidence, and source-module placement are documented with strong confidence; remaining work is detailed field layout and final C++ reconstruction. Evidence: `ButtonChoiceControlCore`, `ButtonControlPane`, Wave3 method-grade summary, and IDA constructor xref count.
