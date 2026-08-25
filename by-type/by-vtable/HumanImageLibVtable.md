*** UID:0001XQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HumanImageLib Vtable

## Status

- Confidence: very strong for address, RTTI locator, all slot identities, adjacent boundaries, vptr-store xrefs, direct class source cause, and non-emitting policy.
- Semantic source cause: [UID:00006A][HumanImageLib](by-class/HumanImageLib.md); the compiler artifact itself has no independent owner/emitter.
- Current disposition: `92/94`, false/non-emitting, blank formal C++, regenerated from the complete class declaration.
- Exact backing memory page: [UID:00036H][0x0061b6d0-0x0061b6e0.HumanImageLibVtableData](by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md).
- Containing aggregate page: [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md).
- RTTI pointer: `0x0061b6d0` -> `0x00648814` (`??_R4HumanImageLib@@6B@`).
- Primary vtable: `0x0061b6d4` (`??_7HumanImageLib@@6B@`).
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e6460` | `HumanImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` |
| `+0x08` | `0x0041b6c0` | inherited `LObject::VirtualNoop(int,int)` |

The table ends before the `MonsterImageLib` RTTI pointer at `0x0061b6e0` and its vtable at `0x0061b6e4`.

## Adjacent Template Vtables

The old-human `ProtectedArray<...Info>` vtables sit immediately before the class vtable:

| Address | Type | Slot target |
| --- | --- | --- |
| `0x0061b674` | `ProtectedArray<HeadInfo>` | `0x004e6120` |
| `0x0061b67c` | `ProtectedArray<BodyInfo>` | `0x004e6000` |
| `0x0061b684` | `ProtectedArray<CoatInfo>` | `0x004e6030` |
| `0x0061b68c` | `ProtectedArray<WeaponInfo>` | `0x004e6270` |
| `0x0061b694` | `ProtectedArray<FaceInfo>` | `0x004e60c0` |
| `0x0061b69c` | `ProtectedArray<Acc1Info>` | `0x004e5fa0` |
| `0x0061b6a4` | `ProtectedArray<HairInfo>` | `0x004e60f0` |
| `0x0061b6ac` | `ProtectedArray<Acc2Info>` | `0x004e5fd0` |
| `0x0061b6b4` | `ProtectedArray<HelmetInfo>` | `0x004e6150` |
| `0x0061b6bc` | `ProtectedArray<MantleInfo>` | `0x004e61e0` |
| `0x0061b6c4` | `ProtectedArray<NecklaceInfo>` | `0x004e6210` |
| `0x0061b6cc` | `ProtectedArray<ShoeInfo>` | `0x004e6240` |

These are template destructor vtables, not separate source modules. They belong to the `ProtectedArray` template support while their concrete instances are embedded in [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e6460` -> `sub_4E6460`, size `0x3b`, HumanImageLib scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b6d0` dword `0x00648814` -> `??_R4HumanImageLib@@6B@`.
  - `0x0061b6d4` dword `0x004e6460` -> `sub_4E6460`, xrefs from `0x004d278c` and `0x004d4afd`.
  - `0x0061b6d8` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b6dc` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b6e0` dword `0x00648c14` -> `??_R4MonsterImageLib@@6B@`, proving the next image-library table boundary.
- IDA names in the same region include `??_7HumanImageLib@@6B@`, `??_R4HumanImageLib@@6B@`, and the associated `Singleton<HumanImageLib>` RTTI records at `0x00648864-0x00648898`.

IDA xrefs to `0x0061b6d4` land at:

- `0x004d278c` in `HumanImageLib::HumanImageLib`
- `0x004d4afd` in [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)

Generated `class_HumanImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## 2026-06-11 Exact Child And Gate Recheck

[UID:00036H][0x0061b6d0-0x0061b6e0.HumanImageLibVtableData](by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md) now owns the concrete compiler-emitted locator/vtable dwords. That exact child records the half-open range, `0x0061b6d0` RTTI pointer, three slot dwords, slot target sizes, constructor/destructor vptr-store xrefs, the old-human `ProtectedArray` template-vtable boundary before this range, and the following `MonsterImageLib` locator boundary at `0x0061b6e0`.

The complete [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) declaration at `92/93` and UID00017B ordinary destructor are the source cause. This semantic page is now `92/94`, false/non-emitting, and ownerless as a standalone binary artifact; exact memory child UID00036H remains parallel physical evidence rather than a source child emitter.

## Score Rationale

- Completion is `92` because the page records all three slots, RTTI/boundaries, lifecycle vptr xrefs, direct class/destructor cause, adjacent template-vtable context, exact backing memory, inherited LObject identities, and final generated non-emitting disposition.
- Confidence is `94` because the dwords, symbols, target sizes, inherited method identities, and constructor/destructor xrefs agree across current class/file/memory evidence.

## Rebuild Notes

This vtable is not handwritten table source. It is a compiler-emitted artifact produced by the `HumanImageLib` class declaration and virtual methods. The reconstructable source requirement is to preserve the class declaration, inheritance, virtual destructor/deleting-destructor semantics, and inherited/shared virtual slots well enough that the rebuilt compiler emits an equivalent table.

Do not add `RECONSTRUCTION_CPP CODE` for the vtable bytes here. Attach source declarations and method bodies through the owning class, file, and exact `by-memory` method pages only after they satisfy the final-source confidence gate.

`0x004f4b10` and `0x0041b6c0` are inherited LObject slots; the complete class declaration adds no duplicate overrides. Vtable and RTTI dwords remain compiler artifacts regenerated from the current direct bases and virtual destructor.

## Historical / Superseded Assumptions

- The former direct owner/emitter attachment to UID00006A and reconstructable status conflated semantic source cause with standalone source emission. The class still causes the table, but this page emits nothing.
- The unresolved inherited-slot caveat is superseded by the LObject method identities above. Historical raw aliases remain evidence-only.

## Cross-References

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:00036H][0x0061b6d0-0x0061b6e0.HumanImageLibVtableData](by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)

## Changes

- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had detailed vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the RTTI locator, `??_7HumanImageLib@@6B@` vtable symbol, three slot targets, constructor/destructor vptr-store xrefs, adjacent old-human `ProtectedArray` vtables, and the next `MonsterImageLib` table boundary. Scores remain below `95` because final source declarations, inherited/shared slot names, and full surrounding source reconstruction are not near-final audited.
- 2026-06-11 A001 exact child and parent assignment:
  - What existed before: `AUTOGEN_PARENT_UID:` was blank, completion remained `82`, and the concrete `0x0061b6d0-0x0061b6e0` backing data had no standalone by-memory child.
  - Changed to: `COMPLETION:86`, `AUTOGEN_PARENT_UID:00006A`, and an exact backing-memory link to [UID:00036H][0x0061b6d0-0x0061b6e0.HumanImageLibVtableData](by-memory/0x0061b6d0-0x0061b6e0.HumanImageLibVtableData.md).
  - Summary/evidence: the exact child split records the RTTI/vtable dwords, slot target sizes, constructor/destructor vptr-store xrefs, and neighboring ProtectedArray/Monster boundaries; [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) is `85/86` and [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) is `85/85`, so the strict child/direct-parent gate clears.
- 2026-06-20 B004 Rule 26 parent-score and unresolved-slot refresh:
  - What existed before: the parent gate text still cited [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) `85/86` and [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) `85/85`.
  - Changed to: parent gate text now cites [UID:00006A][HumanImageLib](by-class/HumanImageLib.md) `88/88` and [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) `87/88`, and the unresolved inherited/shared slot/no-op slot caveat is restated.
  - Summary/evidence: B004 reanalysis keeps the vtable source-declared/generated-binary policy and rejects raw dword C++ emission until the final class declaration and inherited virtual interface are resolved.
- 2026-07-21 B001 accepted UID0001PM callback: raised to `92/94`, changed to false/non-emitting with no owner/emitter, resolved both inherited LObject slots, retained exact RTTI/dword/xref/boundary evidence, and kept formal C++ blank.
