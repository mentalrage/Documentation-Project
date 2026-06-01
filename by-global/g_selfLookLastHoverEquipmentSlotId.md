*** UID:0002CG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Owner: [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- Canonical memory page: [UID:000283][0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId](by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md)

This global caches the most recent `SelfLookPane` equipment slot id accepted by the mouse-move/hover branch. It prevents the branch from repeatedly cancelling and re-arming the same 1-second timer while the cursor remains over the same equipment slot.

## Evidence

- IDA xrefs to `0x0066fe40` are limited to `SelfLookPane::OnMouseClick` / mouse event handling at `0x00568cb0-0x0056934a`.
- At `0x005692aa`, the handler calls `SelfLookPane::HitTestSlot` (`0x0056a300-0x0056a373`) using the event coordinates.
- At `0x005692b8-0x005692c5`, the returned slot id must be valid and in the `7..20` equipment-slot range.
- At `0x005692c7`, the handler compares the candidate slot id with `word_66FE40`.
- If the candidate differs, `0x005692d3` removes pending callbacks from the pane timer subobject and `0x005692f4` schedules a new timer with the slot id, `1000` ms delay, and the mouse coordinates.
- At `0x00569310`, the handler writes the accepted slot id back to `word_66FE40`.
- At `0x0056931a`, the handler sets the per-slot state byte at `this + 0x1655 + slotId`, then invalidates/redraws through the pane virtual slot at `+0x20`.

## Reconstruction Notes

Declare this as source-owned `SelfLookPane` static state, not compiler-generated data. The initial `0xffff` value is the no-slot sentinel and should be preserved.

The name is evidence-based but still provisional at the exact original-source spelling level. A future class-layout pass may shorten it if the timer subobject and slot-state byte array receive stronger names.

## Cross-References

- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:000283][0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId](by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
