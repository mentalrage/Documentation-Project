*** UID:0000TL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SendOptionPacket11B_540E50

## Status

- Confidence: strong for packet behavior, current global identity, direct caller split, exact memory boundary, and alias relationship to the emitting by-memory page; medium-high for final source-file declaration spelling.
- Address: `0x00540e50`
- Exact memory: [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md)
- Likely owner: [UID:0000M7][OptionPane](by-file/OptionPane.md) or a future narrow option/protocol helper module; this by-global page is a non-emitting alias/index.
- Helper island context: [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md)
- Historical generated projection: `SendOptionPacket11B_00540E50.cpp`, retained only as prior naming context.

## Purpose

`SendOptionPacket11B_540E50` is a shared outbound option-packet helper. It sends opcode `0x011b` / decimal `283` (Verified with `int_convert.py`) with a one-byte option code through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). The transmitted packet length is `0x3` / decimal `3` bytes (Verified with `int_convert.py`), and the exact function body is `0x41` / decimal `65` bytes (Verified with `int_convert.py`).

Keep this as a global/free helper for now because it has callers outside `NewOptionPane`. Do not turn it into a `NewOptionPane` method unless later ownership work proves the `SelfLookPane` callers are artifacts.

The exact physical helper body emits from [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md). This by-global page is retained as support/index documentation for name, caller split, and protocol facts and is intentionally non-reconstructable/non-emitting to avoid duplicate generated source.

MusicControlDialog inlines the same `0x011b` packet family rather than calling this helper: its constructor sends option code `0`, and control id `1` sends option code `0x0d` before applying sound-effect enablement. This widens the documented protocol family beyond OptionPane callers without changing this physical helper's owner.

## Evidence Notes

- IDA MCP decompilation on 2026-05-25 shows this exact three-byte packet layout: word opcode `0x011b` plus one option-code byte.
- Direct callers are `NewOptionPane::OnMouseClick` and the `SelfLookPane` neighborhood.
- The old [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) is a separate identical body. Use the same naming pattern, but keep the bodies distinct in memory/source migration notes.
- Historical generated output treated this as a standalone helper; [UID:0000M7][OptionPane](by-file/OptionPane.md) should cross-reference it because the main known UI owner family is options/settings.
- 2026-06-01 IDA MCP recheck confirms exact memory span `0x00540e50-0x00540e91`, four `NewOptionPane::OnMouseClick` callers, and two `SelfLookPane` callers. This supports `RECONSTRUCTABLE:TRUE` while keeping the final source placement caveat.
- [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md) places this helper inside the new-option helper island and records the adjacent raw `0x011b/0x63` sender plus server-option response helpers. That context supports the [UID:0000M7][OptionPane](by-file/OptionPane.md) parent while preserving the free-helper caveat.
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md) records this helper as an `OnMouseClick` callee and separately notes the two `SelfLookPane` callers, so the helper should stay documented as shared option packet support rather than a method-local body.
- No fresh live IDA call was attempted during the 2026-06-11 A001 refresh. This update promotes the global page from the already-validated [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) evidence and supporting OptionPane/network pages.
- 2026-06-16 C001 live IDA refresh in session `b001_mappane_0001AW_20260616` reconfirmed `0x00540e50-0x00540e91` as a `0x41`-byte function with six direct callers, decompiled the same stack packet `{ 0x011b, optionByte }` sent with length `3`, verified `0x00540e91-0x00540ea0` as `0xcc` alignment before the raw `0x00540ea0` no-function helper, saved the IDA labels `SendOptionPacket11B` and `OptionPaneSendOptionPacket11B`, and saved the IDB. `0x00540ea0` still reports `Not a function`, so the adjacent subcommand-63 sender remains a raw helper and is not merged into this body.

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

Keep `AUTOGEN_PARENT_UID:0000M7` on [UID:0000M7][OptionPane](by-file/OptionPane.md), but do not emit from this by-global alias page. The physical by-memory helper [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) owns the formal C++ body. This page remains support documentation because it records the global name/caller/protocol relationship without duplicating source output.

Do not assign it through [UID:000097][NewOptionPane](by-class/NewOptionPane.md). The helper has two documented `SelfLookPane` neighborhood callers, so the defensible current source shape remains a file-level option-protocol helper or a later shared inline/helper declaration.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | Exact global identity, exact memory page, saved IDA function label, function range/size, opcode/length conversions, caller split, duplicate old-pane body, sender dependency, helper-island context, no-function status for the adjacent raw sender, strict file-parent gate, and non-emitting alias disposition are documented. |
| Confidence | 91 | The linked memory page has current live IDA boundary/decompile/caller evidence and owns the formal body. Confidence stays below final-source quality because final helper declaration placement and the source-level sharing relationship with the old local body remain unresolved. |

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
  - Summary/evidence: existing memory pages document the exact helper island, four `NewOptionPane::OnMouseClick` callers, two `SelfLookPane` callers, and adjacent option-packet helpers. This page is now a non-emitting alias; the physical by-memory page carries any formal C++.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/80`. Summary/evidence: the page documents the exact address, packet layout, caller/owner caveats, duplicate helper relationship, and network/global refs; final source placement remains medium-confidence.
- 2026-06-01: Marked reconstructable and attached parent [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Before: autogen metadata was blank despite strong packet behavior evidence.
  - After: the helper is attached to the options/settings source family while preserving the caveat that it is a shared free helper, not a `NewOptionPane` method.
- 2026-06-11 A001 gate and evidence refresh:
  - Changed scores from `84/82` to `85/88`.
  - Summary/evidence: promoted the global page to match the validated [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) evidence, added verified opcode/length/body-size conversions, documented caller split and duplicate-body relation in a summary table, linked the queue/send funnel, and recorded that the child/direct-parent `85/85` gate clears through [UID:0000M7][OptionPane](by-file/OptionPane.md). No fresh live IDA call was attempted in this pass.
- 2026-06-16 C001 safe IDA refresh:
  - Changed scores from `85/88` to `87/90`.
  - Summary/evidence: live IDA session `b001_mappane_0001AW_20260616` reconfirmed the function boundary, six-call-site split, decompiled packet layout, padding before the raw no-function `0x00540ea0` helper, and saved the source-quality labels `SendOptionPacket11B` and `OptionPaneSendOptionPacket11B`. The by-global page is now non-emitting because [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) owns the physical helper body.
- 2026-06-18 B003 MusicControlDialog support sync: recorded the constructor option code `0` and sound-effect control option code `0x0d` inline sends as additional evidence that opcode `0x011b` is shared option/settings protocol support.
- 2026-06-30 B007 implementation callback:
  - Changed from `87/90`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000M7` to `88/91`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
  - Evidence: this page duplicates the exact physical body documented by [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md). The by-memory page now carries the formal C++ body, while this by-global page remains an alias/index for protocol and caller-split evidence.
