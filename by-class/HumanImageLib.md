*** UID:00006A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HumanImageLib

## Status

- Confidence: strong for class role, singleton, vtable, and owned resource families; medium for exact field names.
- Likely source file: [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- Address ranges: [UID:00017A][0x004d2720-0x004e649b.HumanImageLib](by-memory/0x004d2720-0x004e649b.HumanImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_HumanImageLib.cpp`
- Singleton: [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`.
- Vtable: [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) at `0x0061b6d4`.
- Layout: [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## Class Purpose

`HumanImageLib` is the legacy human character image library. It owns old-format human body/equipment image table handles and ProtectedArray metadata for parts such as body, face, hair, weapon, shield, helmet, mantle, necklace, shoes, and coat.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `HumanImageLib::HumanImageLib` | [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md) | Large startup table loader; initializes human/equipment arrays and calls the shared frame-table loader for old human asset families. |
| `HumanImageLib::~HumanImageLib` | `0x004d4ad0` | Releases 18 body-part image-library handles, optional cached resources, and ProtectedArray buffers. |
| `HumanImageLib::ClearSingleton` | `0x004e5b80` | Tiny cleanup/static-lifetime helper that clears `g_pHumanImageLib`. |
| `ScalarDeletingDestructor` | `0x004e6460` | Calls the destructor and optionally deletes `this`. |

IDA MCP on 2026-05-26 confirms the class vtable at `0x0061b6d4`, adjacent old-human `ProtectedArray` vtables at `0x0061b674-0x0061b6cc`, and singleton storage at `0x0069b43c`. The constructor still has no direct code refs in the IDA code-ref query, which is likely because startup/static initialization invokes it through placement/new or a recovered construction wrapper.

## Relationship To NewHumanImageLib

`HumanImageLib` and [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) should be separate source modules. They both render human characters, but their data models differ: old human uses archive-family frame tables and protected arrays, while new human uses motion/layer/part composition tables.

## Cross-References

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md)
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/82`. Summary: legacy human image library role, singleton, vtable, layout, constructor/destructor/static cleanup methods, owned resource families, and separation from `NewHumanImageLib` are documented; completion is capped because this large asset system still lacks exhaustive field/resource-family internals and final field names. Evidence: `0x004d2720-0x004e649b.HumanImageLib`, destructor page, `g_pHumanImageLib`, `HumanImageLibVtable`, `HumanImageLibLayout`, `LoadImageFrameTable`, and ProtectedArray references.

- 2026-05-31 range correction and reconstructable marking:
  - What existed before: class was not marked reconstructable and still pointed at the one-byte-short aggregate label.
  - Changed to: `RECONSTRUCTABLE:TRUE`, scores `78/84`, and references will be validator-resolved to the corrected `0x004d2720-0x004e649b` aggregate.
  - Summary/evidence: IDA MCP confirmed constructor/destructor/scalar-deleting destructor ends and vtable/singleton xrefs. Scores remain below 95 because the large constructor and final source field names are not fully audited.

- 2026-06-03 constructor child link:
  - What existed before: the constructor row was only an address-level method note under the broad aggregate.
  - Changed to: the method inventory and cross-reference list now link to [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md).
  - Summary/evidence: IDA MCP on 2026-06-03 confirmed the exact constructor range, resource/table evidence, callee families, singleton/vtable refs, and post-body padding. The class score is unchanged because final field names and source declarations remain unresolved.
