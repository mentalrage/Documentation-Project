*** UID:0000E3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane

## Status

- Confidence: strong for broad static text control role, live method boundaries, vtable placement, constructor fan-in, embedded text-pane behavior, and fixed type code; medium for final field names.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- Main address ranges: `0x00498dd0-0x004991ec` and `0x0049b920-0x0049b925`
- Parent attachment: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md) has a documented `NexusTK/ui/controls/` reconstruction path and covers the same static-text control family.

## Class Purpose

`StaticTextControlPane` is an older static text control wrapper used broadly by dialogs. It exposes a fixed pane/control type code `19` and has helper virtuals that switch an embedded text pane between inactive and active/selectable display states.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00498dd0-0x00498e0e` | show/activate helper | Restores the embedded child pane state from owner byte `+0x110`, sets active byte `+0x101`, and invalidates the owner bounds through the vtable callback. |
| `0x00498e10-0x00498e5e` | hide/deactivate helper | Saves child byte `+0xb5` into owner byte `+0x110`, maps child state to `2` or `3`, clears owner byte `+0x101`, and invalidates the owner bounds. |
| `0x00498e60-0x00498eca` | inactive text-pane state helper | Calls the child text pane state helper with `(0, 0)`, syncs bounds, and clears owner byte `+0x102` after invalidation. |
| `0x00498ed0-0x00498f4c` | active/selectable text-pane state helper | Calls the child text pane state helper with `(1, 1)`, selects range `0-0x7fff`, syncs bounds, and sets owner byte `+0x102` after invalidation. |
| `0x00498f50-0x00499021` | frame/highlight paint helper | Vtable-only draw helper gated by byte `+0x109`; draws a small framed rectangle through GrafPort helpers. |
| `0x00499030-0x004991ec` | `StaticTextControlPane::StaticTextControlPane` | Constructor calls the base pane constructor with type argument `5`, installs three `StaticTextControlPane` vtables, allocates a 372-byte embedded text pane, applies owner-relative bounds, initializes child state, seeds optional text, and finalizes owner state `4`. |
| [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md) | `GetPaneTypeCode` | Returns fixed type code `19`. |

## Evidence Notes

- IDA MCP reports `sub_498DD0`, `sub_498E10`, `sub_498E60`, `sub_498ED0`, `sub_498F50`, `sub_499030`, and `sub_49B920` with exact end-exclusive ranges `0x00498e0e`, `0x00498e5e`, `0x00498eca`, `0x00498f4c`, `0x00499021`, `0x004991ec`, and `0x0049b925`.
- IDA MCP reports 104 direct constructor call sites across 43 caller functions, including dialog/control constructors such as `sub_472CA0`, `sub_4753E0`, `sub_51A520`, `sub_51B880`, `sub_58D750`, and `sub_59BC90`, which strongly supports a generic control role.
- Live IDA names three `StaticTextControlPane` vtables at `0x006181a4`, `0x0061820c`, and `0x0061823c`, with constructor stores at `0x004990be`, `0x004990c4`, and `0x004990ce`.
- Vtable data references place helper methods at `0x00618144`, `0x0061814c`, `0x00618150`, `0x00618158`, `0x0061815c`, `0x00618160`, `0x006181e8`, `0x006181f0`, `0x006181f4`, `0x006181fc`, `0x00618200`, and `0x00618204`.
- Constructor decompilation shows embedded text-pane allocation through `sub_4F4AA0(372)` and `sub_58DCE0`, child pointer storage at owner offset `+0x10c`, child state calls `sub_5446B0(..., 1)` and `sub_58EA80(..., 0, 0)`, optional text seeding through `sub_58E270`, and final owner state `sub_5446B0(this, 4)`.
- Dialog constructors instantiate this class for prompts and labels beside buttons and editable text controls.
- `GetPaneTypeCode` returns `0x13` / `19`.

## Current Caveats

- Final source reconstruction still needs original field names, vtable slot names, and a clean owner/child text-pane naming pass.
- The class is reconstructable as documentation, but it remains below the `95/95` source threshold because field names and exact public constructor signature names are not proven.

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
- 2026-06-04: Raised completion/confidence from `78/76` to `82/84`, set `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).
  - Evidence: live IDA rechecked all method boundaries, vtable references, and the constructor body; confirmed 104 direct constructor call sites across 43 functions; confirmed three `StaticTextControlPane` vtable installs at `0x004990be`, `0x004990c4`, and `0x004990ce`; confirmed embedded text-pane allocation/setup at owner offset `+0x10c`; and confirmed fixed type code `19`.
  - Remaining limits: scores stay below final-source level because exact member names, public API names, and full source-level constructor parameter names are still inferred rather than proven.
