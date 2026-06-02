*** UID:0000EZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ThrowReallyInputPane

## Status

- Confidence: strong for accept behavior, raw constructor bytes, stored-slot layout, vtable identity, and item-action module placement; medium for raw-constructor reachability.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md), [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_ThrowReallyInputPane.cpp`

## Class Purpose

`ThrowReallyInputPane` is the confirmation prompt for destructive throw/discard behavior. It asks for an affirmative input before sending the throw packet for the stored item slot.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ThrowReallyInputPane` | `0x005b5b30-0x005b5b80` | Raw constructor-shaped bytes; prompt id `0xa5`, stored slot byte at `+0x108`, and vtable installation. |
| `OnAccept` | `0x005b5b80-0x005b5c20` | Reads confirmation input and sends opcode `0x17` for the stored slot. |

## Evidence Notes

- IDA MCP confirms `0x005b5b80` but reports no function at `0x005b5b30`.
- Raw IDA disassembly at `0x005b5b30-0x005b5b80` shows prompt string id `0xa5`, [UID:00001P][CharInputPane](by-class/CharInputPane.md) base construction, vtables `0x00630278`, `0x006302c8`, and `0x006302f8`, and a stored slot byte at `this + 0x108`.
- IDA confirms inline construction paths in `UserPane` command handling and helper `0x005aba80`; the helper stores the same three vtables and copies the item slot to `+0x108`.
- IDA decompilation of `0x005b5b80` confirms accepting `y` or `Y`, then sending opcode `0x17`, mode byte `1`, and the stored slot through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- Wave3 generated source shows prompt string id `0xa5` and the same throw opcode used by [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md), but IDA remains the authority for raw constructor and inline-construction evidence.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the raw constructor/vtable evidence, stored slot layout, accept-body decompilation, packet send behavior, and documented caveat that the constructor bytes are not currently an IDA-defined function start.
- 2026-06-02 reconstructable metadata alignment:
  - Before: class coverage described this page as reconstructable, but page metadata left `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` blank.
  - After: set `CONFIDENCE:84`, marked reconstructable, and attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md) and [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) now record refreshed constructor, accept handler, vtable, packet, and item-action ownership evidence.
