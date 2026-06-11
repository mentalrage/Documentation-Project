*** UID:0001XW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemObjImageLib Vtable

## Status

- Confidence: strong for address, RTTI locator, slot targets, adjacent boundaries, and vptr-store xrefs.
- Owner class: [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md).
- Exact memory page: [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md).
- Backing aggregate page: [UID:00025I][0x0061b664-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c360.ImageLibraryReadOnlyData.md).
- RTTI pointer: `0x0061b738` -> `0x00648f24` (`??_R4ItemObjImageLib@@6B@`).
- Primary vtable: `0x0061b73c` (`??_7ItemObjImageLib@@6B@`).
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e6580` | `ItemObjImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table ends before the `ProtectedArray<LightInfo>` RTTI pointer at `0x0061b748` and its vtable at `0x0061b74c`.

## Adjacent Template Vtable

The `ProtectedArray<ItemInfo>` vtable is immediately before this class vtable at `0x0061b734`; its single slot points to `0x004e6180`.

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e6580` -> `sub_4E6580`, size `0x5c`, scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b730` -> `??_R4?$ProtectedArray@UItemInfo@@@@6B@`.
  - `0x0061b734` -> `??_7?$ProtectedArray@UItemInfo@@@@6B@`, the immediately preceding template vtable.
  - `0x0061b738` dword `0x00648f24` -> `??_R4ItemObjImageLib@@6B@`.
  - `0x0061b73c` dword `0x004e6580` -> `sub_4E6580`, xrefs from `0x004dec8c`, `0x004dee23`, and `0x004e6586`.
  - `0x0061b740` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b744` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b748` dword `0x006490ac` -> `??_R4?$ProtectedArray@ULightInfo@@@@6B@`, proving the next template-vtable boundary.
- IDA names in the same region include `??_7ItemObjImageLib@@6B@`, `??_R4ItemObjImageLib@@6B@`, and associated `Singleton<ItemObjImageLib>` RTTI records at `0x00648f74-0x00648fa8`.

IDA xrefs to `0x0061b73c` land at:

- `0x004dec8c` in [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- `0x004dee23` in [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- `0x004e6586` in the scalar deleting destructor

Generated `class_ItemObjImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `ItemObjImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

No `RECONSTRUCTION_CPP CODE` is emitted here. Source declarations and method bodies should be attached through the owning class/file and exact `by-memory` method pages only after the final-source confidence gate is satisfied.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)

## Changes

- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the exact [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md), RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, preceding `ProtectedArray<ItemInfo>` vtable, and next `ProtectedArray<LightInfo>` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding ItemObjImageLib draw-method dependencies are not final-audited.
