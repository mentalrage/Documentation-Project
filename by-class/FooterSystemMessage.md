*** UID:00005D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FooterSystemMessage

## Status

- Confidence: strong for marker-entry role, factory body, and vtable membership; medium for final semantic names of the shared boolean/default virtual slots.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Non-contiguous destructor helper: [UID:0001B5][0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md)
- Tiny virtual helpers: [UID:0001GG][0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals](by-memory/0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals.md)
- Current recovered file: `source-3/simroot_v2/class_FooterSystemMessage.cpp`

## Class Purpose

`FooterSystemMessage` is the sibling marker entry to [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md). It constructs a tiny `LObject`-based marker object and installs the `FooterSystemMessage` vtable for the system-message entry stream.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00514e60-0x00514e98` | scalar deleting destructor | Shared small marker-entry destructor; calls `LObject` cleanup and conditionally deletes storage. |
| `0x0055c1b0-0x0055c1b3` | true boolean virtual | Returns true; appears in the header/footer marker vtable area. |
| `0x0055c1c0-0x0055c1c3` | false boolean virtual | Returns false; appears in the header/footer marker vtable area and other message classes. |
| `0x00587900-0x0058796f` | `CreateInstance` | Allocates four bytes, constructs `LObject`, installs `FooterSystemMessage` vtable, and returns the marker object. |
| `0x0058af40-0x0058af48` | default true virtual | Returns true and consumes two stack arguments; used by both header/footer marker vtables. |

## Evidence Notes

- IDA names the vtable at `0x0062d6d0` as `FooterSystemMessage`.
- The vtable points at the same small destructor helper as `HeaderSystemMessage`, plus factory `0x00587900` and the same tiny boolean helper pair.
- 2026-06-03 IDA MCP recheck resolves the factory as `0x00587900-0x0058796f`: it allocates four bytes through `sub_4F4AA0`, calls the `LObject` shell constructor at `sub_4F4A80`, writes vtable `0x0062d6d0`, and returns null only on allocation failure.
- Vtable slot order from IDA data words is destructor `+0x00`, inherited/empty slots at `+0x04`/`+0x08`, false/true boolean stubs at `+0x0c`/`+0x10`, factory `+0x14`, default true helper `+0x18`, and another null slot at `+0x1c`.
- The shared destructor `0x00514e60` is also referenced by `MerchantDialogCreator` and `PursuitMessageDialogCreator` vtables, so it is LObject scalar-delete glue reused by several tiny marker/creator classes rather than an exclusive header/footer body.
- Generated output currently exposes only the factory in `class_FooterSystemMessage.cpp`; its inherited/shared destructor and boolean virtual slots are not emitted there.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)

## Changes

- 2026-05-28: Corrected the shared scalar deleting destructor endpoint from `0x00514e97` to `0x00514e98`. Evidence: IDA MCP reports `sub_514e60` as `0x00514e60-0x00514e98`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/78`. Summary: marker-entry purpose, vtable membership, factory/destructor/boolean virtuals, and generated-output limitation are documented, but the semantic names of the boolean slots are still not final. Evidence: vtable address `0x0062d6d0`, factory `0x00587900-0x0058796e`, shared destructor `0x00514e60-0x00514e98`, and system-message pane cross-references.
- 2026-06-03: Rechecked the factory and vtable with IDA MCP, corrected the factory half-open endpoint from `0x0058796e` to `0x0058796f`, added the `0x0058af40-0x0058af48` default true helper, and recorded the shared destructor's extra dialog-creator vtable references.
  - Before: completion/confidence `70/78`, reconstructable/parent metadata blank.
  - After: completion/confidence `76/82`, reconstructable true, attached to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) at position 40.
  - C++ remains blank because final source names for the boolean/default virtual slots are not at the 95% reconstruction threshold.
