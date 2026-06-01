*** UID:0000PX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_equipmentSlotKeys / word_630BD8

## Status

- Confidence: strong for address, table contents, and `TakeOffInputPane` use; medium for final source-level name.
- Address: `0x00630bd8`
- Size: `0x2e` bytes / 23 UTF-16 code units
- IDA name: `word_630BD8`
- Primary memory doc: [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md)
- Likely owner: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) or shared equipment-action command code.

## Purpose

This table maps one-character equipment take-off input keys to one-based equipment selector values. [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md) scans 23 entries and sends selector index `+1` when the typed character matches.

Observed UTF-16 contents:

```text
wash#nlr####fm#c###[]12
```

The `#` entries are placeholder or unused selector slots. The table is not a C string terminator-delimited value; it is a fixed 23-entry lookup table.

## Evidence Notes

- IDA `py_eval` on 2026-05-27 read 23 UTF-16 words at `0x00630bd8` and produced the fixed key string above.
- IDA `xrefs_to 0x00630bd8` reports a data reference from `0x005b28f0` inside `TakeOffInputPane::ProcessUnequipCommand`.
- IDA decompilation of `0x005b2830` compares a one-character input against `word_630BD8[index]` and sends selector `index + 1` via opcode `0x1f`.

## Cross-References

- [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, fixed UTF-16 table contents, take-off command behavior, IDA table/xref/decompilation evidence, memory refs, and source-owner caveat.
