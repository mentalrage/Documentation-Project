*** UID:00008T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); C++ remains blank because base-layout names and exact source declarations are below the `95/95` final-source gate.

## Class Purpose

`MultiLineInputPane` is a [UID:000077][LineInputPane](by-class/LineInputPane.md) variant for multi-line dialog input. Enter submits through the owner dialog and clears/rebounds the text buffer; Escape or Ctrl+C closes the dialog and clears player dialog state.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f2c90-0x004f2cc4` | Builds the `LineInputPane` base and installs the `MultiLineInputPane` three-vtable family. |
| Key handler range `0x004f2cd0-0x004f2dca` | Multi-line submit/close handler; handles Enter, Escape, and Ctrl+C before forwarding remaining input to the text input child. |
| Vtable bases `0x0061cda0`, `0x0061cdf0`, `0x0061ce20` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2cd0` | Confirms the multi-line key handler is the derived key-input override. |
| Vtable boundary `0x0061ce28 -> List RTTI locator` | Confirms the end of the input-pane vtable family after the `MultiLineInputPane` tertiary table. |
| Aggregate range [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) | Places constructor/key handler with the reusable input-pane base family. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) | Multi-line text dialog workflows consume this reusable input pane while text-dialog-specific owner behavior remains in the dialog module. |

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

- 2026-06-06: Raised completion/confidence and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: completion/confidence were `74/84`, and `AUTOGEN_PARENT_UID` was blank because the page had not cleared the child-side parent gate.
  - After: completion/confidence are `82/86`, and `AUTOGEN_PARENT_UID` is `0000K7`.
  - Evidence: added constructor/key-handler range evidence, exact vtable bases and secondary override slot from [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md), the `0x0061ce28` vtable-family boundary, aggregate ownership, and `TextMenuDialogs` consumer placement. C++ remains blank under the `95/95` final-source gate.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the multi-line constructor and key handler starts at `0x004f2c90` and `0x004f2cd0`. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: the multi-line input variant has clear owner, purpose, constructor/key handler boundaries, vtable family, and base-class relationships documented, but it remains concise and lacks full source-level field/control detail. Evidence: linked `InputPaneBases` memory range, `LineInputPane` relationship, method address map, and text-menu dialog usage.
