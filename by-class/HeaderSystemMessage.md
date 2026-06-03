*** UID:000061 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HeaderSystemMessage

## Status

- Confidence: strong for marker-entry role, factory body, and vtable membership; medium for final semantic names of the shared boolean/default virtual slots.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Non-contiguous destructor helper: [UID:0001B5][0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md)
- Tiny virtual helpers: [UID:0001GG][0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals](by-memory/0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals.md)
- Current recovered file: `source-3/simroot_v2/class_HeaderSystemMessage.cpp`

## Class Purpose

`HeaderSystemMessage` is a tiny marker entry used by the system-message pane list. The object is only four bytes in the recovered constructor path: it constructs the `LObject` shell and installs the `HeaderSystemMessage` vtable.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00514e60-0x00514e98` | scalar deleting destructor | Shared small marker-entry destructor; calls `LObject` cleanup and conditionally deletes storage. |
| `0x0055c1b0-0x0055c1b3` | true boolean virtual | Returns true; appears in the header/footer marker vtable area. |
| `0x0055c1c0-0x0055c1c3` | false boolean virtual | Returns false; appears in the header/footer marker vtable area and other message classes. |
| `0x00587890-0x005878ff` | `CreateInstance` | Allocates four bytes, constructs `LObject`, installs `HeaderSystemMessage` vtable, and returns the marker object. |
| `0x0058af40-0x0058af48` | default true virtual | Returns true and consumes two stack arguments; used by both header/footer marker vtables. |

## Evidence Notes

- IDA names the vtable at `0x0062d6ac` as `HeaderSystemMessage`.
- The vtable points at `0x00514e60`, boolean helpers `0x0055c1b0` and `0x0055c1c0`, factory `0x00587890`, and another shared helper at `0x0058af40`.
- 2026-06-03 IDA MCP recheck resolves the factory as `0x00587890-0x005878ff`: it allocates four bytes through `sub_4F4AA0`, calls the `LObject` shell constructor at `sub_4F4A80`, writes vtable `0x0062d6ac`, and returns null only on allocation failure.
- Vtable slot order from IDA data words is destructor `+0x00`, inherited/empty slots at `+0x04`/`+0x08`, true/false boolean stubs at `+0x0c`/`+0x10`, factory `+0x14`, default true helper `+0x18`, and another null slot at `+0x1c`.
- The shared destructor `0x00514e60` is also referenced by `MerchantDialogCreator` and `PursuitMessageDialogCreator` vtables, so it is LObject scalar-delete glue reused by several tiny marker/creator classes rather than an exclusive header/footer body.
- Generated output currently exposes only the destructor wrapper and factory; the boolean virtual slots are not in `class_HeaderSystemMessage.cpp`.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)

## Changes

- 2026-05-28: Corrected the shared scalar deleting destructor endpoint from `0x00514e97` to `0x00514e98`. Evidence: IDA MCP reports `sub_514e60` as `0x00514e60-0x00514e98`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/78`. Summary: marker-entry purpose, four-byte object shape, vtable membership, shared destructor, boolean virtual helpers, and factory are documented; final semantic names for the boolean slots remain medium-confidence. Evidence: vtable `0x0062d6ac`, factory `0x00587890-0x005878fe`, shared destructor `0x00514e60-0x00514e98`, and `SystemMessagePanes` cross-references.
- 2026-06-03: Rechecked the factory and vtable with IDA MCP, corrected the factory half-open endpoint from `0x005878fe` to `0x005878ff`, added the `0x0058af40-0x0058af48` default true helper, and recorded the shared destructor's extra dialog-creator vtable references.
  - Before: completion/confidence `70/78`, reconstructable/parent metadata blank.
  - After: completion/confidence `76/82`, reconstructable true, attached to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) at position 30.
  - C++ remains blank because final source names for the boolean/default virtual slots are not at the 95% reconstruction threshold.
