*** UID:0002CG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_selfLookLastHoverEquipmentSlotId

## Summary

- Address: `0x0066fe40`
- Current IDA name: `word_66FE40`
- Type: `uint16_t` / `WORD`
- Initial value: `0xffff`
- Owner file: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- Related class: [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- Canonical memory page: [UID:000283][0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId](by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md)

This global caches the most recent `SelfLookPane` equipment slot id accepted by the mouse-move/hover branch. It prevents the branch from repeatedly cancelling and re-arming the same 1-second timer while the cursor remains over the same equipment slot.

## Evidence

- 2026-06-03 live IDA refresh confirms `word_66FE40` is a `.data` word at `0x0066fe40`; bytes `0x0066fe40-0x0066fe50` are `ff ff 00 00 20 00 09 00 00 00 00 00 00 00 00 00`, so the word initializes to `0xffff` and the following word is alignment before the `SpelledPane` wide delimiter.
- 2026-06-03 IDA `xrefs_to(0x0066fe40)` reports exactly two data xrefs: compare at `0x005692c7` and write at `0x00569310`, both inside `sub_568CB0` (`0x00568cb0-0x0056934a`, size `0x69a`).
- 2026-06-03 IDA `lookup_funcs` confirms the related function bounds: mouse handler `0x00568cb0-0x0056934a`, hit-test helper `0x0056a300-0x0056a373`, timer schedule wrapper `0x005975e0-0x005975ff`, and timer remove wrapper `0x00597600-0x0059760d`.
- IDA xrefs to `0x0066fe40` are limited to `SelfLookPane::OnMouseClick` / mouse event handling at `0x00568cb0-0x0056934a`.
- At `0x005692aa`, the handler calls `SelfLookPane::HitTestSlot` (`0x0056a300-0x0056a373`) using the event coordinates.
- At `0x005692b8-0x005692c5`, the returned slot id must be valid and in the `7..20` equipment-slot range.
- At `0x005692c7`, the handler compares the candidate slot id with `word_66FE40`.
- If the candidate differs, `0x005692d3` removes pending callbacks from the pane timer subobject and `0x005692f4` schedules a new timer with the slot id, `1000` ms delay, and the mouse coordinates.
- At `0x00569310`, the handler writes the accepted slot id back to `word_66FE40`.
- At `0x0056931a`, the handler sets the per-slot state byte at `this + 0x1655 + slotId`, then invalidates/redraws through the pane virtual slot at `+0x20`.

## Reconstruction Notes

Declare this as source-owned `SelfLookPane` static state, not compiler-generated data. The initial `0xffff` value is the no-slot sentinel and should be preserved.

The page is marked reconstructable and attached to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) because the live xrefs are confined to the `SelfLookPane` hover branch and the file page already has a validated `NexusTK/ui/panels/` placement at `72/82`. Final C++ remains blank because the exact original source spelling and surrounding class field names are below the 95/95 reconstruction gate.

The name is evidence-based but still provisional at the exact original-source spelling level. A future class-layout pass may shorten it if the timer subobject and slot-state byte array receive stronger names.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now records exact storage bytes, initial value, xref count, branch behavior, related helper bounds, owner file, canonical memory page, reconstruction handling, and open naming caveats. It remains below high completion because the final source spelling and related field names are not proven. |
| Confidence | 86 | Live IDA confirms all direct xrefs are the compare/write pair in the `SelfLookPane` slot-hover branch, and the parent file placement is already IDA-backed. Confidence is capped by unresolved original declaration spelling. |
| Reconstructable | true | This is source-owned `SelfLookPane.cpp` static state rather than compiler glue; no final C++ is emitted until the 95/95 bar is met. |

## Cross-References

- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:000283][0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId](by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)

## Changes

- 2026-06-03 live IDA refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000NL`.
  - Reason: the page now records live IDA storage bytes, the exact two data xrefs, branch disassembly semantics, helper function bounds, parent-file attachment, and final-C++ caveats.
  - Evidence: IDA MCP reports `word_66FE40` in `.data` with bytes `ff ff 00 00` at `0x0066fe40`, xrefs only from `0x005692c7` and `0x00569310` in `sub_568CB0`, the `0xffff` reject and `7..20` slot filter before the compare, timer remove/schedule calls at `0x005692d3` and `0x005692f4`, and the accepted-slot write/redraw path at `0x00569310-0x00569327`.
