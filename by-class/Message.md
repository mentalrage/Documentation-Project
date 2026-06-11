*** UID:000084 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Message

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), with a nearby tiny message-model file still possible for final hand-authored organization.
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), because both the class and direct file parent now clear the corrected `85/85` gate.
- Main address range: [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md), split from [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- Current recovered file: `source-3/simroot_v2/class_Message.cpp`

## Class Purpose

`Message` is a base message object. It derives from `LObject`, stores a message type, and owns a sorted list of fixed-size message entries.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00520e30-0x00520ecb` | `Message::Message(uint32_t messageType)` | Constructs the `LObject` base, installs the `Message` vtable, stores the type, and allocates a `SortedList` for entries. |
| `0x00520ed0-0x00520ef5` | `Message::~Message()` | Deletes the entry list and destroys the `LObject` base. |
| `0x00520f00-0x00521c80` | raw message entry helpers | Insert/update and lookup helper band for `0x98`-byte message entries; IDA leaves the starts unmodeled but disassembly shows repeated `SortedList` insert/lookup patterns. |
| `0x00521c80-0x00521cf6` | entry sequence normalizer | Called by the raw insert helpers to update entry sequence/count field `+0x84`. |
| `0x00521d00-0x00521d35` | `CompareMessageEntries` | `SortedList` compare callback referenced by the constructor at `0x00520e88`. |
| `0x00521d40-0x00521d94` | `Message::ScalarDeletingDestructor(uint32_t flags)` | Destructor wrapper with MSVC scalar-delete flag handling. |

## Evidence Notes

- IDA MCP confirms all three functions as exact starts.
- The constructor allocates the sorted entry list with item size `0x98` and compare callback `CompareMessageEntries`. That target is [UID:0000DF][SortedList](by-class/SortedList.md), not a message-local private list class.
- 2026-06-07 A005 split recheck confirms the raw helper band begins at `0x00520f00`, the modeled sequence normalizer and compare callback are `0x00521c80` and `0x00521d00`, and the direct child [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md) cleanly separates this class from `MessageShowPane`.
- 2026-06-07 A008 parent-chain recheck refreshes [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) to `89/85` with the exact `MessageCore` child evidence. That makes `MessageDialogs` the best current direct source parent for this base message model while keeping the possible final tiny model-file split documented.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md)
- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)

## Changes

- 2026-06-07 A005 Batch 047 parent-gate refresh:
  - Before: `76/84`, with only constructor/destructor/scalar-destructor rows and no raw helper/compare inventory.
  - After: `85/86`; added [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md), the raw `0x00520f00-0x00521c80` helper band, `0x00521c80` normalizer, and `0x00521d00` compare callback evidence.
  - Assignment effect: direct parent now satisfies `85/85` for [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md). This class remains unassigned to a file parent because [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is still below the confidence gate at `88/80`.
- 2026-06-07 A008 Batch 053 parent-chain repair:
  - Before: `AUTOGEN_PARENT_UID` was blank, so [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md) still produced a generated memory-coverage parent-chain error despite the direct class parent being `85/86`.
  - Changed to: `AUTOGEN_PARENT_UID:0000LA`.
  - Why: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) was refreshed to `89/85` with exact `MessageCore` evidence, and it remains the best direct source-family parent for the base message model while the overlay half is split to [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md).

- 2026-06-05: Marked reconstructable because live IDA MCP confirms this compact base message object has real constructor/destructor/scalar-destructor functions and owns message-entry storage setup. Kept `AUTOGEN_PARENT_UID` blank because the class is `76/84`, below the 80/80 parent-attachment gate, even though [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00520e30`, `0x00520ed0`, and `0x00521d40`; `callers` confirms constructor uses from `0x00464ab0` and `0x00467990`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the compact base message object has clear class role, constructor/destructor/scalar destructor boundaries, sorted-list ownership, and entry size/compare evidence, but the page remains concise and does not yet include full entry-structure reconstruction. Evidence: linked `MessageAndMessageShowPane` range, IDA-confirmed starts, Wave3 grade, and `SortedList` allocation with item size `0x98`.
