*** UID:00005D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FooterSystemMessage

## Status

- Confidence: strong for marker-entry role and vtable membership; medium for final semantic name of boolean slots.
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
| `0x0055c1b0-0x0055c1b2` | true boolean virtual | Returns true; appears in the header/footer marker vtable area. |
| `0x0055c1c0-0x0055c1c2` | false boolean virtual | Returns false; appears in the header/footer marker vtable area and other message classes. |
| `0x00587900-0x0058796e` | `CreateInstance` | Allocates four bytes, constructs `LObject`, installs `FooterSystemMessage` vtable, and returns the marker object. |

## Evidence Notes

- IDA names the vtable at `0x0062d6d0` as `FooterSystemMessage`.
- The vtable points at the same small destructor helper as `HeaderSystemMessage`, plus factory `0x00587900` and the same tiny boolean helper pair.
- Generated output currently exposes only the factory in `class_FooterSystemMessage.cpp`; its inherited/shared destructor and boolean virtual slots are not emitted there.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)

## Changes

- 2026-05-28: Corrected the shared scalar deleting destructor endpoint from `0x00514e97` to `0x00514e98`. Evidence: IDA MCP reports `sub_514e60` as `0x00514e60-0x00514e98`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/78`. Summary: marker-entry purpose, vtable membership, factory/destructor/boolean virtuals, and generated-output limitation are documented, but the semantic names of the boolean slots are still not final. Evidence: vtable address `0x0062d6d0`, factory `0x00587900-0x0058796e`, shared destructor `0x00514e60-0x00514e98`, and system-message pane cross-references.
