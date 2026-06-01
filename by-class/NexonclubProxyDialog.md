*** UID:00009H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NexonclubProxyDialog

## Status

- Confidence: strong for constructor behavior, medium for final file split.
- Likely source file: [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- Main address range: [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- Current recovered file: `source-3/simroot_v2/class_NexonclubProxyDialog.cpp`

## Class Purpose

`NexonclubProxyDialog` parses a server-provided proxy dialog packet and immediately opens `NexonclubRegistrationDialog` with the parsed text and callback data. It is a bridge between the NPC/message dialog packet format and the account-registration UI.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x00553610-0x005538fd` | constructor | Parses proxy-packet text, button, object, and dimension fields, creates a callback, and constructs `NexonclubRegistrationDialog`. |
| `0x005539ce-0x005539d8` | thunk | Disabled generated thunk; exact base owner remains polluted. |

## Key Relationships

- Constructs [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md).
- Uses [UID:0000EL][TextDialog](by-class/TextDialog.md) region-selection reply behavior as a callback target.
- Sits immediately after `TextDialog`, but has independent vtable installation and class identity.

## Cross-References

- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md)

## Changes

- Before: the constructor range ended at `0x005538fc`.
- Changed to: the constructor range ends at `0x005538fd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old endpoint omitted the final byte of the range-check failure call operand.
- Before: completion/confidence metadata were `0/0` despite constructor, packet-bridge role, thunk caveat, and class relationship notes.
- Changed to: `COMPLETION:68` and `CONFIDENCE:76`.
- Evidence: the page documents the constructor range, parsed proxy-packet role, callback relationship, and registration-dialog construction; confidence stays medium because only the constructor is meaningfully described and final source split/base-owner pollution remain open.
