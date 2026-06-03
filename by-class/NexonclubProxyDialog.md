*** UID:00009H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NexonclubProxyDialog

## Status

- Confidence: strong for constructor behavior, vtable identity, and dialog-file placement; medium-high for final source split.
- Likely source file: [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- Main address range: [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- Read-only data evidence: [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)
- Current recovered file: `source-3/simroot_v2/class_NexonclubProxyDialog.cpp`

## Class Purpose

`NexonclubProxyDialog` parses a server-provided proxy dialog packet and immediately opens `NexonclubRegistrationDialog` with the parsed text and callback data. It is a bridge between the NPC/message dialog packet format and the account-registration UI.

The class appears to be an anonymous-namespace/local implementation class in the original dialog source cluster. The separate class page is retained because the constructor and vtable island are concrete reconstruction inputs, while file-level docs keep open whether the original source eventually folded the proxy into the registration module.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x00553610-0x005538fd` | constructor | Parses proxy-packet text, button, object, and dimension fields, creates a callback, and constructs `NexonclubRegistrationDialog`. |
| `0x005539ce-0x005539d8` | thunk | Disabled generated thunk; exact base owner remains polluted. |

## Vtable And Data Evidence

| Range | Evidence | Interpretation |
| --- | --- | --- |
| `0x00622c58-0x00622ce8` | [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records anonymous-namespace `NexonclubProxyDialog` vtables. | Confirms class identity separate from adjacent `TextDialog` and `HeadSelectDialog` ranges. |
| `0x00622cf4` | Same read-only-data page records the `PlainMemberFunctionObjectT` callback vtable. | Supports the constructor's callback allocation and reply-target binding. |
| `0x0054c9f0-0x0054ca49` | [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the dispatcher wrapper that allocates `0x278` bytes and calls `0x00553610`. | Confirms construction path from the NPC/message dialog dispatcher. |

## Key Relationships

- Constructs [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md).
- Uses [UID:0000EL][TextDialog](by-class/TextDialog.md) region-selection reply behavior as a callback target.
- Sits immediately after `TextDialog`, but has independent vtable installation and class identity.
- Belongs under [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md), whose projected source folder is now `NexusTK/ui/dialogs/`.

## Reconstruction Notes

- Rebuild handling: source-authored class/constructor declarations plus compiler-generated vtables from source declarations.
- Marked reconstructable because the constructor and vtables are NexusTK-owned dialog code/data that must be represented in rebuilt source.
- `RECONSTRUCTION_CPP CODE` intentionally stays blank: packet-field naming, callback type shape, and shared destructor/base thunk cleanup are not documented to the 95+ gate.

## Cross-References

- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## Changes

- Before: the constructor range ended at `0x005538fc`.
- Changed to: the constructor range ends at `0x005538fd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old endpoint omitted the final byte of the range-check failure call operand.
- Before: completion/confidence metadata were `0/0` despite constructor, packet-bridge role, thunk caveat, and class relationship notes.
- Changed to: `COMPLETION:68` and `CONFIDENCE:76`.
- Evidence: the page documents the constructor range, parsed proxy-packet role, callback relationship, and registration-dialog construction; confidence stays medium because only the constructor is meaningfully described and final source split/base-owner pollution remain open.
- Before: class metadata was `68/76`, reconstructable was blank, and no parent was assigned.
- Changed to: `COMPLETION:80`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md).
- Evidence: the class now records the dispatcher wrapper, anonymous proxy vtables, callback vtable, projected dialog source folder, and reconstruction blockers. C++ remains blank because final callback/base/destructor names are not near-final.
