*** UID:0001XQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HumanImageLib Vtable

## Status

- Confidence: strong for address, RTTI locator, slot targets, adjacent boundaries, and vptr-store xrefs.
- Owner class: [UID:00006A][HumanImageLib](by-class/HumanImageLib.md).
- Backing memory page: [UID:00025I][0x0061b664-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c360.ImageLibraryReadOnlyData.md).
- RTTI pointer: `0x0061b6d0` -> `0x00648814` (`??_R4HumanImageLib@@6B@`).
- Primary vtable: `0x0061b6d4` (`??_7HumanImageLib@@6B@`).
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e6460` | `HumanImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

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

## Rebuild Notes

This vtable is not handwritten table source. It is a compiler-emitted artifact produced by the `HumanImageLib` class declaration and virtual methods. The reconstructable source requirement is to preserve the class declaration, inheritance, virtual destructor/deleting-destructor semantics, and inherited/shared virtual slots well enough that the rebuilt compiler emits an equivalent table.

Do not add `RECONSTRUCTION_CPP CODE` for the vtable bytes here. Attach source declarations and method bodies through the owning class, file, and exact `by-memory` method pages only after they satisfy the final-source confidence gate.

## Cross-References

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:00006A][HumanImageLib](by-class/HumanImageLib.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:00017B][0x004d4ad0-0x004d4f67.HumanImageLibDestructor](by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)

## Changes

- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had detailed vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the RTTI locator, `??_7HumanImageLib@@6B@` vtable symbol, three slot targets, constructor/destructor vptr-store xrefs, adjacent old-human `ProtectedArray` vtables, and the next `MonsterImageLib` table boundary. Scores remain below `95` because final source declarations, inherited/shared slot names, and full surrounding source reconstruction are not near-final audited.
