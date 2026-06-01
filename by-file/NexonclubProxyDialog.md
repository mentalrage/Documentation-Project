*** UID:0000LZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NexonclubProxyDialog

## Status

- Confidence: strong for constructor behavior, medium for final source split from the registration dialog.
- Proposed module: `ui/dialogs/NexonclubProxyDialog.cpp`
- Current recovered source: `source-3/simroot_v2/class_NexonclubProxyDialog.cpp`
- Main memory range: [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)

## File Role

`NexonclubProxyDialog` is a small packet adapter. It parses a proxy dialog packet, creates a callback object targeting the dialog-region reply path, and opens [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md).

This source may eventually fold into `NexonclubRegistrationDialog.cpp` if original-source evidence favors one file for the whole registration flow. Current class identity, anonymous-namespace vtables, and compact constructor make a separate staging file useful.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NexonclubProxyDialog` | `0x00553610-0x005538fd` | Parses proxy packet fields and launches the registration dialog. |
| adjustor/destructor thunk | `0x005539ce-0x005539d8` | Disabled generated thunk with owner/base-label pollution; keep as compiler glue pending final inheritance cleanup. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00553610-0x005538fd` | `NexonclubProxyDialog::NexonclubProxyDialog` | Builds a `DialogPane` shell, parses text/button/object fields, allocates a callback, and constructs `NexonclubRegistrationDialog`. |
| `0x005539ce-0x005539d8` | thunk | Current generated disabled source labels this through another dialog base; treat the label as polluted until the actual base path is reconciled. |

## Ownership Notes

- The constructor calls [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) and passes a callback that targets the `TextDialog` region-selection packet helper at `0x005534a0`.
- Do not attach this constructor to [UID:0000OL][TextDialog](by-file/TextDialog.md) or [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) by address locality. Its vtable names and behavior form a separate registration proxy.
- The generated `struct_path` uses an anonymous namespace, which supports a small private adapter class shape.
- 2026-05-24 recheck: IDA models `0x005539ce-0x005539d8` as an 11-byte adjustor thunk (`this -= 0xa4`) that jumps to shared destructor glue at `0x00520b70`; the disabled generated owner/base label remains provisional.

## Cross-References

- [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md)
- [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)

## Changes

- Before: the `NexonclubProxyDialog` constructor range ended at `0x005538fc`.
- Changed to: the constructor range ends at `0x005538fd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x005538fc` is the final byte of the range-check failure call operand; the next byte is alignment before `HeadSelectDialog` destructor thunks.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `74`.
- Summary/evidence: the page documents the adapter role, constructor/thunk map, ownership notes, IDA recheck, range correction, and cross-references; confidence remains limited by possible fold-in with `NexonclubRegistrationDialog`.
