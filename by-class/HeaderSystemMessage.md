*** UID:000061 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HeaderSystemMessage

## Status

- Confidence: strong for marker-entry role and vtable membership; medium for final semantic name of boolean slots.
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
| `0x0055c1b0-0x0055c1b2` | true boolean virtual | Returns true; appears in the header/footer marker vtable area. |
| `0x0055c1c0-0x0055c1c2` | false boolean virtual | Returns false; appears in the header/footer marker vtable area and other message classes. |
| `0x00587890-0x005878fe` | `CreateInstance` | Allocates four bytes, constructs `LObject`, installs `HeaderSystemMessage` vtable, and returns the marker object. |

## Evidence Notes

- IDA names the vtable at `0x0062d6ac` as `HeaderSystemMessage`.
- The vtable points at `0x00514e60`, boolean helpers `0x0055c1b0` and `0x0055c1c0`, factory `0x00587890`, and another shared helper at `0x0058af40`.
- Generated output currently exposes only the destructor wrapper and factory; the boolean virtual slots are not in `class_HeaderSystemMessage.cpp`.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)

## Changes

- 2026-05-28: Corrected the shared scalar deleting destructor endpoint from `0x00514e97` to `0x00514e98`. Evidence: IDA MCP reports `sub_514e60` as `0x00514e60-0x00514e98`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/78`. Summary: marker-entry purpose, four-byte object shape, vtable membership, shared destructor, boolean virtual helpers, and factory are documented; final semantic names for the boolean slots remain medium-confidence. Evidence: vtable `0x0062d6ac`, factory `0x00587890-0x005878fe`, shared destructor `0x00514e60-0x00514e98`, and `SystemMessagePanes` cross-references.
