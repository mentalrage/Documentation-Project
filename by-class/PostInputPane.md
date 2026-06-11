*** UID:0000AO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PostInputPane

## Status

- Confidence: strong for behavior, vtable identity, and command-input module placement.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- Address range: [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md), documented true range `0x005b5630-0x005b5890`
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)

## Class Purpose

`PostInputPane` is a single-letter post selection prompt. It formats a localized prompt with the player name, accepts a letter mapped to a post index, validates it against the active user/status pane limit, and sends post command opcode `0x34`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PostInputPane` | `0x005b5630-0x005b56f7` | Constructs prompt with player name and installs vtables. |
| `OnKeyInput` | `0x005b5700-0x005b576c` | Handles help-panel shortcut. |
| `OnConfirmInput` | `0x005b5770-0x005b5830` | Converts letter to post index and sends opcode `0x34`. |
| `SendPostPacketRawHelper` | `0x005b5830-0x005b5890` | Raw IDA-unmodeled helper that writes opcode `0x34`, one signed byte argument, and sends two bytes through `g_packetSender`; no direct xref to the raw start. |

## Evidence Notes

- 2026-06-05 IDA MCP `analyze_funcs` confirms modeled extents `0x005b5630-0x005b56f7`, `0x005b5700-0x005b576c`, and `0x005b5770-0x005b5830`.
- Raw byte/disassembly review confirms `0x005b56f7-0x005b5700` and `0x005b576c-0x005b5770` are `0xcc` alignment spans, while `0x005b5830-0x005b5890` is executable helper-shaped packet-send code.
- IDA MCP confirms three `PostInputPane` vtable views at `0x00630160`, `0x006301b0`, and `0x006301e0`, with stores from the command dispatcher `0x005a5bd0`, open helper `0x005a9a90`, and constructor `0x005b5630`.
- Vtable data xrefs put `OnConfirmInput` at slot `0x006301a8` and `OnKeyInput` at slot `0x006301b8`.
- The constructor reads local-player/name data through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), localized prompt id `11` through [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), then sets the prompt text through the shared input-pane helper.
- The key handler accepts only the `?` shortcut event shape, switches [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) to tab `2`, invokes sound/effect id `0x198`, and delegates all other input to the base handler.
- The confirm handler maps `a-z` to `1-26` and `A-Z` to `27-52`, checks [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`, and queues packet bytes `{ 0x34, postIndex }` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

## Source Placement

Attach this class to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). Both pages now meet the 80/80 parent gate, and the behavior is command/post routing rather than item-action ownership. Final class C++ remains blank because the exact source-facing names for the shared input base, packet writer, packet queue wrapper, and side-panel helpers are not final-audit quality.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)
- [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)

## Changes

- 2026-06-05 live IDA refresh:
  - Before: the page was scored `72/84`, class autogen parent was blank, and the method inventory stopped at `0x005b5830`.
  - After: raised to `82/90`, attached to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), added the raw `0x005b5830-0x005b5890` post packet helper, and kept the evidence chain on IDA/project-documentation sources.
  - Evidence: IDA MCP confirms the modeled method extents, vtable slots/stores, raw helper bytes, global dependencies, post opcode `0x34`, active status-pane slot-limit check, and exclusive boundary before the item-action `ThrowInputPane` constructor at `0x005b5890`. No final C++ was emitted because the page is below the 95/95 reconstruction-code bar.

- Earlier 2026-06-05 scoring/classification pass:
  - Before: completion/confidence metadata were `0/0` and reconstructable metadata was blank despite documented class purpose, three method starts, vtable views, packet opcode, and command-input placement.
  - After: set `COMPLETION:72`, `CONFIDENCE:84`, and `RECONSTRUCTABLE:TRUE`; parent attachment was deferred at that time because the class did not yet meet the 80/80 attach gate.
