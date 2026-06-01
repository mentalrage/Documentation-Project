*** UID:0000EL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextDialog

## Status

- Confidence: strong for main behavior and function boundaries.
- Likely source file: [UID:0000OL][TextDialog](by-file/TextDialog.md)
- Main address range: [UID:0001FJ][0x00552110-0x00553609.TextDialogCore](by-memory/0x00552110-0x00553609.TextDialogCore.md)
- Current recovered file: `source-3/simroot_v2/class_TextDialog.cpp`

## Class Purpose

`TextDialog` is a `DialogPane`-derived NPC/message dialog that shows packet-provided text, optional object art, optional input text controls, and navigation buttons. It submits replies through opcode `0x3a`.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x00552110-0x00553179` | constructor | Parses dialog packet fields, chooses normal/high-resolution resources, and constructs child controls. |
| `0x00553180-0x00553337` | `HandleDialogAction` | Handles submit, previous, next, and current commands. |
| `0x005534a0-0x00553609` | `SendRegionSelectionPacket` | Sends a selected region string or current-dialog fallback packet. |

## Shared Helpers

The opcode `0x3a` previous/next/current helpers at `0x0054cc30`, `0x0054ccd0`, and `0x0054cd70` are currently recovered under `TextDialog`, but direct callers include `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, and this class. Treat them as shared dialog packet helpers rather than private class methods.

2026-05-24 recheck: current `simroot_v2/class_TextDialog.cpp` still emits these helpers before the `TextDialog` constructor, and IDA MCP still reports direct callers from message/menu-question action handlers plus `TextDialog` action/region-selection handlers.

## Key Relationships

- Uses [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) for optional object/NPC art.
- Uses [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) for the editable input field.
- Uses [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md), [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), and button controls for the dialog layout.
- Neighboring [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md) reuses the region-selection callback target.

## Cross-References

- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0001FJ][0x00552110-0x00553609.TextDialogCore](by-memory/0x00552110-0x00553609.TextDialogCore.md)
- [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `86`.
- Evidence: the page documents dialog purpose, constructor/action/region packet ranges, shared navigation helper ownership, key child-control relationships, neighboring dialog callback relationship, and corrected endpoints; remaining completion gap is source-ready C++ detail and exhaustive field naming.
- Before: `TextDialogCore` ended at `0x00553608`, and shared navigation helper links ended at `0x0054ce0e`.
- Changed to: `TextDialogCore` ends at `0x00553609`, and shared navigation helper links end at `0x0054ce0f`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows both old endpoints omitted the final byte of an adjacent instruction.
