*** UID:000084 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Message

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), or a nearby message model file if the final layout splits overlay/model code.
- Main address range: [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- Current recovered file: `source-3/simroot_v2/class_Message.cpp`

## Class Purpose

`Message` is a base message object. It derives from `LObject`, stores a message type, and owns a sorted list of fixed-size message entries.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00520e30-0x00520ecb` | `Message::Message(uint32_t messageType)` | Constructs the `LObject` base, installs the `Message` vtable, stores the type, and allocates a `SortedList` for entries. |
| `0x00520ed0-0x00520ef5` | `Message::~Message()` | Deletes the entry list and destroys the `LObject` base. |
| `0x00521d40-0x00521d94` | `Message::ScalarDeletingDestructor(uint32_t flags)` | Destructor wrapper with MSVC scalar-delete flag handling. |

## Evidence Notes

- Wave3 grades the class at effective `97.0` with no attention-needed methods.
- IDA MCP confirms all three functions as exact starts.
- The constructor allocates the sorted entry list with item size `0x98` and compare callback `CompareMessageEntries`. That target is [UID:0000DF][SortedList](by-class/SortedList.md), not a message-local private list class.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the compact base message object has clear class role, constructor/destructor/scalar destructor boundaries, sorted-list ownership, and entry size/compare evidence, but the page remains concise and does not yet include full entry-structure reconstruction. Evidence: linked `MessageAndMessageShowPane` range, IDA-confirmed starts, Wave3 grade, and `SortedList` allocation with item size `0x98`.
