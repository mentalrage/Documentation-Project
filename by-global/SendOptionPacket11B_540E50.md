*** UID:0000TL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SendOptionPacket11B_540E50

## Status

- Confidence: strong for packet behavior and current global identity; medium for final source-file placement.
- Address: `0x00540e50`
- Exact memory: [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md)
- Likely owner: [UID:0000M7][OptionPane](by-file/OptionPane.md) or a future narrow option/protocol helper module.
- Current recovered source: `source-3/simroot_v2/recovered/SendOptionPacket11B_00540E50.cpp`

## Purpose

`SendOptionPacket11B_540E50` is a shared outbound option-packet helper. It sends opcode `0x011b` with a one-byte option code through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

Keep this as a global/free helper for now because it has callers outside `NewOptionPane`. Do not turn it into a `NewOptionPane` method unless later ownership work proves the `SelfLookPane` callers are artifacts.

## Evidence Notes

- IDA MCP decompilation on 2026-05-25 shows this exact three-byte packet layout: word opcode `0x011b` plus one option-code byte.
- Direct callers are `NewOptionPane::OnMouseClick` and the `SelfLookPane` neighborhood.
- The old [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) is a separate identical body. Use the same naming pattern, but keep the bodies distinct in memory/source migration notes.
- The helper currently lives as a recovered standalone file in `simroot_v2`; [UID:0000M7][OptionPane](by-file/OptionPane.md) should cross-reference it because the main known UI owner family is options/settings.
- 2026-06-01 IDA MCP recheck confirms exact memory span `0x00540e50-0x00540e91`, four `NewOptionPane::OnMouseClick` callers, and two `SelfLookPane` callers. This supports `RECONSTRUCTABLE:TRUE` while keeping the final source placement caveat.

## Cross-References

- [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/80`. Summary/evidence: the page documents the exact address, packet layout, caller/owner caveats, duplicate helper relationship, and network/global refs; final source placement remains medium-confidence.
- 2026-06-01: Marked reconstructable and attached parent [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Before: autogen metadata was blank despite strong packet behavior evidence.
  - After: the helper is attached to the options/settings source family while preserving the caveat that it is a shared free helper, not a `NewOptionPane` method.
