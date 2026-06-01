*** UID:00001M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangeSpellSlotInputPane

## Status

- Confidence: medium overall: strong for handler behavior, vtable identity, and file placement; projected constructor reachability remains unresolved.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_ChangeSpellSlotInputPane.cpp`
- Vtable anchors: primary `0x0062fad0`, secondary `0x0062fb20`, tertiary `0x0062fb50`

## Class Purpose

`ChangeSpellSlotInputPane` is a comma-separated spell-slot reorder prompt. It reads two slot letters, validates them against the learned spell table, and sends the slot-change packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001M7][0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor](by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md) | Raw constructor-shaped body; builds [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md), installs vtables, and uses `'-'` prompt text. IDA has no function object, inbound xrefs, or raw pointer hits at the start. |
| `OnKeyInput` | [UID:0001M9][0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput](by-memory/0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md) | Handles help/panel shortcut before forwarding to the char-args input base; vtable data ref at `0x0062fb28`. |
| `SubmitSpellSlotChange` | [UID:0001MA][0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange](by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md) | Parses `from,to` slot letters, validates spell records, and sends the reorder packet; vtable data ref at `0x0062fb18`. |

## Evidence Notes

- IDA `lookup_funcs` reports `0x005b3220` as not a function, but disassembly shows a complete constructor body ending at `0x005b325f`.
- IDA confirms `0x005b3260` and `0x005b32d0` as real functions.
- No destructor thunk island is currently attached in `simroot_v2` metadata for this class during this pass.
- 2026-05-27 IDA MCP recheck found no inbound xrefs or raw dword pointer hits to projected constructor start `0x005b3220`. The constructor-shaped bytes still call `CharArgsInputPane::CharArgsInputPane` at `0x004f2a60` and store vtables `0x0062fad0`, `0x0062fb20`, and `0x0062fb50` at `0x005b323f`, `0x005b3247`, and `0x005b3251`.
- 2026-05-27 IDA vtable read confirms primary slot `+0x48 -> 0x005b32d0` for submit and primary/secondary key slots `+0x58` / `+0x08 -> 0x005b3260`.
- The submitter reads the broad player-data pointer at `0x0067a748` for spell-slot state (`+0x13a6ec + slot * 0x148`) and clears byte `+0x13ead4` when either slot is active. This is a typed player-state view, not collection-specific ownership.
- The outgoing packet is sent through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC` and `QueueAndSendPacket` at `0x00574bb0`; generated `CashShopRequest*` typing remains provisional.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md)
- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md)
- [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- What existed before: the page documented raw constructor bytes, vtable slots, key handling, submit behavior, and packet globals, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `74/80`.
- Summary and evidence: handler behavior and vtable anchors are strong, but the projected constructor has no inbound xrefs and the final player-state field names remain provisional.
