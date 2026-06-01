*** UID:0000EC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TakeOffInputPane

## Status

- Confidence: strong for behavior, packet helper, vtable identity, and module placement; medium for raw-constructor reachability and final helper source owner.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md), [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_TakeOffInputPane.cpp`

## Class Purpose

`TakeOffInputPane` is the equipment-removal command prompt. It supports a shortcut path, single-slot unequip, and an all-slots `*` path that iterates a fixed equipment slot list.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~TakeOffInputPane` | `0x004f2010-0x004f2092` | Destructor/reset path for base line-input state. |
| `TakeOffInputPane` | `0x005b26e0-0x005b2720` | Raw constructor-shaped bytes; prompt id `0x22`, `CharInputPane` base construction, and vtable installation. |
| `HandleTakeOffShortcut` | `0x005b2720-0x005b27b3` | Sends shortcut opcode `0x2d` or delegates to `CharInputPane`. |
| `SendTakeOffPacket` | `0x005b27c0-0x005b2827` | Shared helper that sends opcode `0x1f` with a selector byte; also called by `SelfLookPane`. |
| `ProcessUnequipCommand` | `0x005b2830-0x005b296b` | Handles `*` all-slots removal or sends slot unequip opcode `0x1f`. |
| `ScalarDeletingDestructor` | `0x005b7940-0x005b797b` | Delete wrapper around the destructor. |

## Evidence Notes

- IDA MCP confirms the destructor, shortcut handler, command handler, two thunks, and scalar deleting destructor.
- IDA reports no function at `0x005b26e0`, but raw disassembly shows constructor-shaped bytes that install vtables `0x0062f92c`, `0x0062f97c`, and `0x0062f9ac` after `CharInputPane` construction.
- IDA confirms `0x005b27c0` as a real helper function. It sends opcode `0x1f` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) when [UID:0000PQ][g_activeDialogCount](by-global/g_activeDialogCount.md) is not positive.
- IDA `py_eval` confirms the fixed equipment key table [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md) at `0x00630bd8` contains `wash#nlr####fm#c###[]12`.
- Wave3 generated source shows packet opcodes `0x2d` and `0x1f`, and an all-slots selector list of 14 equipment slots. Treat this as a lead; IDA is the authority for the helper boundary and table use.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md)
- [UID:0000PQ][g_activeDialogCount](by-global/g_activeDialogCount.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents equipment-removal behavior, destructor/raw-constructor/shortcut/packet/command/destructor methods, packet opcodes, equipment-slot key table, globals, and vtable identity; confidence remains capped by raw-constructor reachability and final helper source owner.
