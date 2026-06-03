*** UID:0000LZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NexonclubProxyDialog

## Status

- Confidence: strong for constructor behavior and source-folder placement, medium-high for final source split from the registration dialog.
- Proposed module: `NexusTK/ui/dialogs/NexonclubProxyDialog.cpp`
- Current recovered source: `source-3/simroot_v2/class_NexonclubProxyDialog.cpp`
- Main memory range: [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- Supporting read-only data: [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## File Role

`NexonclubProxyDialog` is a small packet adapter. It parses a proxy dialog packet, creates a callback object targeting the dialog-region reply path, and opens [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md).

This source may eventually fold into `NexonclubRegistrationDialog.cpp` if original-source evidence favors one file for the whole registration flow. Current class identity, anonymous-namespace vtables, and compact constructor make a separate staging file useful.

The projected reconstruction folder is `NexusTK/ui/dialogs/`, matching the packet-driven dialog cluster in [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md). That project-structure page keeps `TextDialog.cpp`, `NexonclubProxyDialog.cpp`, and `NexonclubRegistrationDialog.cpp` adjacent and records the same IDA-confirmed function starts for the split.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NexonclubProxyDialog` | `0x00553610-0x005538fd` | Parses proxy packet fields and launches the registration dialog. |
| adjustor/destructor thunk | `0x005539ce-0x005539d8` | Disabled generated thunk with owner/base-label pollution; keep as compiler glue pending final inheritance cleanup. |
| anonymous-namespace vtables | `0x00622c58-0x00622ce8` | Read-only data island proves an independent local proxy class rather than a trailing `TextDialog` body. |
| member-function callback table | `0x00622cf4` | Callback vtable used by the constructor's reply object and regenerated from source declarations/template instantiation. |

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
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the allocation wrapper that creates a `0x278`-byte object and calls the proxy constructor from the message-dialog dispatcher path.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the proxy vtables at `0x00622c58-0x00622ce8`, callback vtable at `0x00622cf4`, and xrefs back to the constructor range.

## Reconstruction Notes

- Rebuild handling is source-authored for the constructor/class declaration and source-declared/generated-binary for the vtables and callback vtable.
- The final C++ should stay blank until the constructor's packet-field names, callback object type, and shared dialog base/destructor path reach near-final confidence.
- The current separate `NexonclubProxyDialog.cpp` staging path is strong enough for validator projection and child attachment, but the registration-flow merge question should remain open until the surrounding registration helpers are final-audited.

## Cross-References

- [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md)
- [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## Changes

- Before: the `NexonclubProxyDialog` constructor range ended at `0x005538fc`.
- Changed to: the constructor range ends at `0x005538fd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x005538fc` is the final byte of the range-check failure call operand; the next byte is alignment before `HeadSelectDialog` destructor thunks.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `74`.
- Summary/evidence: the page documents the adapter role, constructor/thunk map, ownership notes, IDA recheck, range correction, and cross-references; confidence remains limited by possible fold-in with `NexonclubRegistrationDialog`.
- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and completion/confidence were `78/74`.
- Changed to: projected path `NexusTK/ui/dialogs/`, completion `82`, and confidence `82`.
- Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `NexonclubProxyDialog.cpp` in the adjacent dialog module cluster; [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) documents the allocation wrapper, and [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) documents the anonymous proxy vtables and callback vtable. The score remains below final-audit levels because the registration-flow merge question and callback type naming are not fully closed.
