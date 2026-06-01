*** UID:0000E3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane

## Status

- Confidence: strong for broad static text control role; medium for generated field names.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- Main address ranges: `0x00498dd0-0x004991ec` and `0x0049b920-0x0049b925`
- Current recovered file: `source-3/simroot_v2/class_StaticTextControlPane.cpp`

## Class Purpose

`StaticTextControlPane` is an older static text control wrapper used broadly by dialogs. It exposes a fixed pane/control type code `19` and has helper virtuals that switch an embedded text pane between inactive and active/selectable display states.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00498dd0-0x00498e5e` | active/show state helpers | Generated fitting-room/user-image names are provisional; IDA shows vtable-only generic static-text state helpers. |
| `0x00498e60-0x00498f4b` | active/inactive text-pane state helpers | Set embedded text pane editable state, selection range, bounds callback, and parent callback state. |
| `0x00498f50-0x00499021` | frame/highlight paint helper | Vtable-only draw helper gated by byte `+0x109`; draws a small framed rectangle through GrafPort helpers. |
| `0x00499030-0x004991ec` | `StaticTextControlPane::StaticTextControlPane` | Constructor range; current emitted source is incomplete. |
| [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md) | `GetPaneTypeCode` | Returns fixed type code `19`. |

## Evidence Notes

- IDA MCP reports 104 direct constructor callers, which strongly supports a generic control role.
- Dialog constructors instantiate this class for prompts and labels beside buttons and editable text controls.
- `GetPaneTypeCode` returns `0x13` / `19`.

## Current Caveats

- Current active generated source for the constructor at `0x00499030` is incomplete: it contains only the marker and a local `TextEditPane` struct.
- The class summary and some helper field names are overfit to fitting-room user-image behavior. Treat that naming as provisional until field ownership is verified.

## Cross-References

- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:00011I][0x00498dd0-0x004991ec.StaticTextControlPane](by-memory/0x00498dd0-0x004991ec.StaticTextControlPane.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents generic static-text role, constructor/helper/type-id ranges, high caller count, and current generated caveats; completion remains limited because the constructor output is incomplete and helper field names are still overfit to fitting-room behavior.
- Before: the type-id helper was listed as `0x0049b920-0x0049b924`.
- Changed to: `0x0049b920-0x0049b925` and linked to its new by-memory page.
- Summary/evidence: IDA MCP reports `sub_49B920` size `0x5`, so the `mov al, 13h; retn 8` helper ends exclusive at `0x0049b925`.
