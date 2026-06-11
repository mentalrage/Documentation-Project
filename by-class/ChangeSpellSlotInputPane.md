*** UID:00001M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangeSpellSlotInputPane

## Status

- Confidence: strong overall for handler behavior, vtable identity, and file placement; projected constructor reachability remains unresolved.
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
| `OnKeyInput` | [UID:0001M9][0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput](by-memory/0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md) | Handles the special help/panel shortcut (`do_narrow(...) == '?'`, event byte `4`, key/state byte `8`), switches the general-purpose panel to child `3`, plays sound `0x198`, and otherwise forwards to the char-args input base; vtable data ref at `0x0062fb28`. |
| `SubmitSpellSlotChange` | [UID:0001MA][0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange](by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md) | Parses `from,to` slot letters, validates spell records, clears the spell-panel dirty/cache byte when either slot is active, and sends the four-byte reorder packet; vtable data ref at `0x0062fb18`. |
| raw packet sender | [UID:0002S6][0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender](by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md) | Raw helper-shaped body immediately after submit tail padding; writes opcode `0x30`, subcommand `1`, source slot, destination slot, and sends four bytes. No inbound xrefs found. |

## Evidence Notes

- IDA `lookup_funcs` reports `0x005b3220` as not a function, but disassembly shows a complete constructor body ending at `0x005b325f`.
- IDA confirms `0x005b3260` and `0x005b32d0` as real functions.
- No destructor thunk island is currently attached in `simroot_v2` metadata for this class during this pass.
- 2026-06-02 IDA MCP `lookup_funcs` confirms `0x005b3260-0x005b32cc` and `0x005b32d0-0x005b340e` as the two real handler functions, while `0x005b3220`, `0x005b32cc`, `0x005b340e`, and `0x005b3410` are not IDA function starts.
- 2026-06-02 raw byte/disassembly review identifies [UID:0002S6][0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender](by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md) as a complete helper-shaped body after the submit handler. It has no direct xrefs to its raw start, but emits the same slot-reorder packet shape as the submit handler.
- 2026-06-02 IDA byte reads confirm `0x005b32cc-0x005b32d0` is four `0xcc` bytes between key and submit handlers and `0x005b340e-0x005b3410` is two `0xcc` bytes before the raw packet helper.
- 2026-06-06 A007 boundary refresh corrects the raw packet sender end-exclusive address to `0x005b3485`; the `retn 8` starts at `0x005b3482`, the post-helper alignment is `0x005b3485-0x005b3490`, and raw `SayInputPane` constructor-shaped bytes start at `0x005b3490`.
- 2026-06-02 IDA `xrefs_to` / `search data_ref` reports no xrefs or raw data-reference hits to `0x005b3220`; `0x005b3260` has the single data hit `0x0062fb28`, and `0x005b32d0` has the single data hit `0x0062fb18`.
- 2026-06-02 IDA `xrefs_to` reports `ChangeSpellSlotInputPane` vtable stores from `0x005a61d7/0x005a61df/0x005a61e9`, `0x005a9486/0x005a948c/0x005a9496`, and raw constructor stores `0x005b323f/0x005b3247/0x005b3251`.
- 2026-05-27 IDA MCP recheck found no inbound xrefs or raw dword pointer hits to projected constructor start `0x005b3220`. The constructor-shaped bytes still call `CharArgsInputPane::CharArgsInputPane` at `0x004f2a60` and store vtables `0x0062fad0`, `0x0062fb20`, and `0x0062fb50` at `0x005b323f`, `0x005b3247`, and `0x005b3251`.
- 2026-05-27 IDA vtable read confirms primary slot `+0x48 -> 0x005b32d0` for submit and primary/secondary key slots `+0x58` / `+0x08 -> 0x005b3260`.
- 2026-06-02 IDA vtable dword read confirms primary `0x0062fad0` has scalar deleting destructor `0x005b7940` and submit slot `+0x48 -> 0x005b32d0`, secondary `0x0062fb20` has adjustor thunk `0x005b77c8` and key slot `+0x08 -> 0x005b3260`, and tertiary `0x0062fb50` has adjustor thunk `0x005b77d3` plus inherited slot `0x00544e90`.
- The submitter reads the broad player-data pointer at `0x0067a748` for spell-slot state (`+0x13a6ec + slot * 0x148`) and clears byte `+0x13ead4` when either slot is active. This is a typed player-state view, not collection-specific ownership.
- The outgoing packet is sent through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC` and `QueueAndSendPacket` at `0x00574bb0`; generated `CashShopRequest*` typing remains provisional.

## Batch 023 Vtable Parent Evidence

Live IDA MCP on 2026-06-07 rechecked `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) for the exact vtable-data child [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md):

- The three vtable bases remain `0x0062fad0`, `0x0062fb20`, and `0x0062fb50`, named as the primary, secondary, and tertiary `ChangeSpellSlotInputPane` views.
- Key class-owned slots remain `0x0062fb18 -> 0x005b32d0` for submit and `0x0062fb28 -> 0x005b3260` for key input, matching the documented method pages.
- Store xrefs remain the command dispatcher/open-helper writes at `0x005a61d7/0x005a61df/0x005a61e9` and `0x005a9486/0x005a948c/0x005a9496`, plus raw constructor-shaped stores at `0x005b323f/0x005b3247/0x005b3251`.
- Boundary dwords at `0x0062fb1c` and `0x0062fb4c` are the secondary and tertiary RTTI locators; the exclusive end remains `0x0062fb58` before the `SayInputPane` RTTI locator.

This class page is the direct source-level owner for the vtable-data child because the child is a compiler-emitted artifact of this class declaration and virtual method set. The page now meets the corrected `85/85` parent gate for assigning [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md) here. The unresolved constructor reachability still blocks final-source C++.

## Reconstruction Notes

This class is confirmed NexusTK-owned source and is now attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) for autogen grouping. Leave the class C++ block empty until the inherited base layout, field names, player-state spell-slot view, and helper names are final-source quality.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md)
- [UID:0002S6][0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender](by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md)
- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md)
- [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- What existed before: the page documented raw constructor bytes, vtable slots, key handling, submit behavior, and packet globals, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `74/80`.
- Summary and evidence: handler behavior and vtable anchors are strong, but the projected constructor has no inbound xrefs and the final player-state field names remain provisional.
- 2026-06-07 A003 Batch 023 parent gate:
  - Before: `82/84`, below the corrected direct-parent gate for the exact vtable-data child.
  - After: `86/86`, with current hash-backed vtable slot, xref, and boundary evidence.
  - Summary/evidence: the class page already documented handler behavior, packet sender state, raw constructor caveats, and source placement; the Batch 023 IDA recheck closes the specific vtable ownership gate while keeping final C++ blocked by unresolved raw-constructor reachability and provisional player-state names.
