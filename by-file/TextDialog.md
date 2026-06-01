*** UID:0000OL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextDialog

## Status

- Confidence: strong for class behavior and main ranges, medium for final placement of the shared navigation helpers.
- Proposed module: `ui/dialogs/TextDialog.cpp`
- Current recovered source: `source-3/simroot_v2/class_TextDialog.cpp`
- Main memory ranges: [UID:0001FJ][0x00552110-0x00553609.TextDialogCore](by-memory/0x00552110-0x00553609.TextDialogCore.md) and [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md)

## File Role

`TextDialog` is a packet-driven plain text/input dialog used by NPC/message flows. It parses dialog packet fields, builds a `DialogPane` with optional object art, static text, text-entry controls, and action buttons, then sends opcode `0x3a` replies for typed text, previous/next/current navigation, or region selection.

Keep this separate from [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md). Text-menu classes submit menu selections with opcode `0x39`; `TextDialog` handles free text and message navigation through the message-dialog opcode family.

Keep this separate from [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), but allow a shared helper boundary: the previous/next/current packet helpers at `0x0054cc30-0x0054ce0f` are currently emitted under `TextDialog` and are called by both message/menu-question dialogs and `TextDialog`.

Keep this separate from [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) and [UID:0000OQ][TextPad](by-file/TextPad.md). Those classes also use text-edit controls, but `EditablePaperPane` is item/paper packet UI and `TextPad` is a local full-screen text pad with file/formatting commands.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TextDialog` | `0x00552110-0x00553609` | Packet parser, layout builder, text-entry action handler, region-selection reply helper. |
| dialog navigation helpers | `0x0054cc30-0x0054ce0f` | Shared previous/next/current opcode `0x3a` response helpers used by message, menu-question, and text dialogs. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x0054cc30-0x0054cccf` | `SendDialogPacketPrevious` | Shared navigation helper; see [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md). |
| `0x0054ccd0-0x0054cd6f` | `SendDialogPacketNext` | Shared navigation helper. |
| `0x0054cd70-0x0054ce0f` | `SendDialogPacketCurrent` | Shared navigation helper. |
| `0x00552110-0x00553179` | `TextDialog::TextDialog` | Parses dialog packet fields and builds normal/high-resolution layouts with `DLGMSG5`, `DLGMSG51`, or `DLGMSG6` resources. |
| `0x00553180-0x00553337` | `HandleDialogAction` | Handles submit/navigation actions; action `1` reads the edit control and sends a typed-text packet. |
| `0x005534a0-0x00553609` | `SendRegionSelectionPacket` | Sends a region-name reply or falls back to the current-dialog packet helper when the region name is invalid. |

## Ownership Notes

- This file should own the main `TextDialog` class.
- The navigation helpers may ultimately live in a smaller shared dialog packet helper source, but current recovery names and locality make `TextDialog.cpp` the staging owner with explicit cross-links.
- Do not fold this range into [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md). IDA confirms `0x00552110` installs `TextDialog` vtables after the head-selection class ends.
- `0x00553610` starts [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md), not a trailing `TextDialog` method.
- 2026-05-24 `simroot_v2` recheck still emits the navigation helpers as `TextDialog` methods, while IDA callers still cross into message and menu-question dialogs. Keep them staged here only with the shared-helper caveat.

## Cross-References

- [UID:0000EL][TextDialog](by-class/TextDialog.md)
- [UID:0001FJ][0x00552110-0x00553609.TextDialogCore](by-memory/0x00552110-0x00553609.TextDialogCore.md)
- [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)

## Changes

- Before: `TextDialogCore` ended at `0x00553608`, and shared dialog navigation helpers ended at `0x0054ce0e`.
- Changed to: `TextDialogCore` ends at `0x00553609`, and shared dialog navigation helpers end at `0x0054ce0f`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows both old endpoints omitted the final byte of an adjacent instruction (`SendRegionSelectionPacket` range-check failure call and `SendDialogPacketCurrent` `retn`).
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers packet-driven text dialog role, proposed contents, function map, ownership boundaries against adjacent dialog/text modules, shared navigation-helper caveat, range correction, and cross-references; confidence is capped by final placement of shared navigation helpers.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/`.
  - Evidence: IDA MCP recheck of [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md) confirms the shared helper body/callers while preserving the staging-owner caveat, and this file already owns the main `TextDialog` implementation.
