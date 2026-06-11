*** UID:0000TL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SendOptionPacket11B_540E50

## Status

- Confidence: strong for packet behavior, current global identity, direct caller split, exact memory boundary, and OptionPane parent assignment; medium-high for final source-file declaration spelling.
- Address: `0x00540e50`
- Exact memory: [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md)
- Likely owner: [UID:0000M7][OptionPane](by-file/OptionPane.md) or a future narrow option/protocol helper module.
- Helper island context: [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md)
- Historical generated projection: `SendOptionPacket11B_00540E50.cpp`, retained only as prior naming context.

## Purpose

`SendOptionPacket11B_540E50` is a shared outbound option-packet helper. It sends opcode `0x011b` / decimal `283` (Verified with `int_convert.py`) with a one-byte option code through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). The transmitted packet length is `0x3` / decimal `3` bytes (Verified with `int_convert.py`), and the exact function body is `0x41` / decimal `65` bytes (Verified with `int_convert.py`).

Keep this as a global/free helper for now because it has callers outside `NewOptionPane`. Do not turn it into a `NewOptionPane` method unless later ownership work proves the `SelfLookPane` callers are artifacts.

## Evidence Notes

- IDA MCP decompilation on 2026-05-25 shows this exact three-byte packet layout: word opcode `0x011b` plus one option-code byte.
- Direct callers are `NewOptionPane::OnMouseClick` and the `SelfLookPane` neighborhood.
- The old [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) is a separate identical body. Use the same naming pattern, but keep the bodies distinct in memory/source migration notes.
- Historical generated output treated this as a standalone helper; [UID:0000M7][OptionPane](by-file/OptionPane.md) should cross-reference it because the main known UI owner family is options/settings.
- 2026-06-01 IDA MCP recheck confirms exact memory span `0x00540e50-0x00540e91`, four `NewOptionPane::OnMouseClick` callers, and two `SelfLookPane` callers. This supports `RECONSTRUCTABLE:TRUE` while keeping the final source placement caveat.
- [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md) places this helper inside the new-option helper island and records the adjacent raw `0x011b/0x63` sender plus server-option response helpers. That context supports the [UID:0000M7][OptionPane](by-file/OptionPane.md) parent while preserving the free-helper caveat.
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md) records this helper as an `OnMouseClick` callee and separately notes the two `SelfLookPane` callers, so the helper should stay documented as shared option packet support rather than a method-local body.
- No fresh live IDA call was attempted during the 2026-06-11 A001 refresh. This update promotes the global page from the already-validated [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) evidence and supporting OptionPane/network pages.

## Packet And Caller Summary

| Evidence point | Current conclusion |
| --- | --- |
| Function range | `0x00540e50-0x00540e91`, size `0x41` / decimal `65` bytes (Verified with `int_convert.py`). |
| Packet layout | Word opcode `0x011b` / decimal `283`, followed by the caller-provided option byte; only length `0x3` / decimal `3` is sent. |
| Sender dependency | Dispatches through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and the queue/send funnel at [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). |
| New-option callers | Four `NewOptionPane::OnMouseClick` sites: `0x00540a0b`, `0x00540a23`, `0x00540a46`, and `0x00540a90`. |
| Shared callers | Two `SelfLookPane` neighborhood sites: `0x005690a4` and `0x00569164`; this blocks a direct `NewOptionPane` method assignment. |
| Duplicate old-pane body | [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) has the same three-byte packet behavior but remains a separate physical function for old `OptionPane` callers. |

## Assignment Decision

Keep `AUTOGEN_PARENT_UID:0000M7` on [UID:0000M7][OptionPane](by-file/OptionPane.md). This global helper now clears `85/88`, and the direct file parent is `91/85`, so the strict child/direct-parent `85/85` gate is satisfied.

Do not assign it through [UID:000097][NewOptionPane](by-class/NewOptionPane.md). The helper has two documented `SelfLookPane` neighborhood callers, so the defensible current source shape remains a file-level option-protocol helper or a later shared inline/helper declaration.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | Exact global identity, exact memory page, function range/size, opcode/length conversions, caller split, duplicate old-pane body, sender dependency, helper-island context, and strict file-parent gate are documented. |
| Confidence | 88 | The linked memory page is already `85/88` with written IDA boundary/decompile/caller evidence, and the OptionPane parent is `91/85`. Confidence stays below final-source quality because final helper declaration placement, source-facing spelling, and sharing relationship with the old local body remain unresolved. |

## Cross-References

- [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md)
- [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md)
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-06-07 A007 generated-source wording and helper-island sync:
  - What existed before: the page listed the generated recovered source path as the current recovered source and did not directly link the exact new-option helper island or aggregate page that now document the shared-helper context.
  - Changed to: confidence `82`, generated-source wording is now historical naming context, and the page links [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md) plus [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md).
  - Summary/evidence: existing memory pages document the exact helper island, four `NewOptionPane::OnMouseClick` callers, two `SelfLookPane` callers, and adjacent option-packet helpers. The source owner remains attached to OptionPane but final C++ stays blank because the original free-helper declaration and cross-file placement are not final-audit quality.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/80`. Summary/evidence: the page documents the exact address, packet layout, caller/owner caveats, duplicate helper relationship, and network/global refs; final source placement remains medium-confidence.
- 2026-06-01: Marked reconstructable and attached parent [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Before: autogen metadata was blank despite strong packet behavior evidence.
  - After: the helper is attached to the options/settings source family while preserving the caveat that it is a shared free helper, not a `NewOptionPane` method.
- 2026-06-11 A001 gate and evidence refresh:
  - Changed scores from `84/82` to `85/88`.
  - Summary/evidence: promoted the global page to match the validated [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) evidence, added verified opcode/length/body-size conversions, documented caller split and duplicate-body relation in a summary table, linked the queue/send funnel, and recorded that the child/direct-parent `85/85` gate clears through [UID:0000M7][OptionPane](by-file/OptionPane.md). No fresh live IDA call was attempted in this pass.
