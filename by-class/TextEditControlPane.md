*** UID:0000EM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextEditControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- Main address ranges: `0x004988d0-0x00499020` and `0x0049b6c0-0x0049b731`
- Current recovered file: `source-3/simroot_v2/class_TextEditControlPane.cpp`

## Class Purpose

`TextEditControlPane` is a [UID:000038][ControlPane](by-class/ControlPane.md) adapter that owns an embedded [UID:0000EO][TextEditPane](by-class/TextEditPane.md). It provides the dialog-control surface for text editing: construction from control bounds and style options, layer attach/detach, show/hide/focus forwarding, border painting, and destruction of the child editor.

## Observed State

Important recovered state:

```text
+0x0ff  initialized flag
+0x108  input mode byte
+0x109  inset-text-bounds flag
+0x10c  embedded TextEditPane*
+0x110  cached byte from embedded pane
```

The full layout still needs a named struct pass, but the embedded editor pointer at `+0x10c` is stable in the constructor and virtual forwarding methods.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction | `0x004988d0-0x00498b8c` | Build `ControlPane` type `5`, allocate/configure a `TextEditPane`, set bounds, max text, max lines, editability, visibility, and initial text. |
| Lifecycle and text forwarding | `0x00498b90-0x00498dc7`, [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) | Destroy child editor, forward attach/detach/show/hide/focus, and forward bounded text-copy requests through the embedded editor pointer at `+0x10c`. |
| Paint/type/destructor | `0x00498f50-0x00499020`, `0x0049b6c0-0x0049b731` | Paint border and provide scalar deleting destructor. |

## Evidence Notes

- IDA MCP reports 85 direct callers to the full constructor at `0x00498920`.
- The constructor signature accepts initial text, style flags, background/scroll colors, bounds, scrollbar flags, inset flag, width scale, and input mode.
- The constructor allocates 372 bytes for the embedded editor and calls `TextEditPane::TextEditPane`.
- The wrapper has much broader dialog fan-in than the editor constructor itself, matching a reusable control adapter.
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) confirms that callers can read text through the wrapper by forwarding to the embedded [UID:0000EO][TextEditPane](by-class/TextEditPane.md).

## Cross-References

- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:00011H][0x004988d0-0x00499020.TextEditControlPaneCore](by-memory/0x004988d0-0x00499020.TextEditControlPaneCore.md)
- [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md)
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `86`.
- Evidence: the page documents the dialog-control adapter role, stable embedded editor pointer, constructor/lifecycle/paint/destructor families, broad constructor fan-in, and exact memory docs; remaining completion gap is a full named layout/source-ready rewrite.
