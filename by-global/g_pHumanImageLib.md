*** UID:0000R5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pHumanImageLib

## Status

- Confidence: strong for address and owner, medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PM][0x0069b43c-0x0069b440.g_pHumanImageLib](by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md), IDA `dword_69B43C`.
- Canonical owner: [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) in [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).

## Meaning

`g_pHumanImageLib` is the global pointer to the legacy human/equipment image library. This is the old archive-family renderer that loads body-part and equipment frame tables such as `HEAD`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, and `COAT`.

Keep this global with `render/HumanImageLib.cpp`. Do not confuse it with the newer table-driven [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) singleton at `0x0067a760`.

## Write Evidence

IDA MCP on 2026-05-26 reports these writes to `0x0069b43c`:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004d277b` | `HumanImageLib::HumanImageLib` | Stores the constructed `HumanImageLib*` singleton. |
| `0x004d2782` | `HumanImageLib::HumanImageLib` | Clears the singleton on the null/guard path. |
| `0x004d4f44` | [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5b80` | [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |

The constructor also installs the [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) and initializes many embedded `ProtectedArray<...Info>` members recorded in [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## Ownership Decision

This is source-owned by `HumanImageLib`, not by [UID:0000K2][ImageLib](by-file/ImageLib.md), [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), or consumers that only draw a resolved human image. The shared frame-table loader remains in `ImageFrameTable.cpp`; the old-human array fields, frame handles, and singleton lifetime belong here.

## Cross-References

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:00017A][0x004d2720-0x004e649b.HumanImageLib](by-memory/0x004d2720-0x004e649b.HumanImageLib.md)
- [UID:0001PM][0x0069b43c-0x0069b440.g_pHumanImageLib](by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents backing storage, owner, legacy human/equipment image-library role, write/clear evidence, vtable/layout refs, ownership decision, and distinction from `NewHumanImageLib`; final original symbol spelling remains medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Evidence: live IDA MCP reports four xrefs to `0x0069b43c`, with constructor writes at `0x004d277b`/`0x004d2782`, non-deleting destructor clear at `0x004d4f44`, and singleton clear helper at `0x004e5b80`.
