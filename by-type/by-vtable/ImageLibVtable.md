*** UID:0001XR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ImageLib Vtable

## Status

- Confidence: strong for address, RTTI locator, slot targets, adjacent boundary, and vptr-store xrefs.
- Owner class: [UID:00006E][ImageLib](by-class/ImageLib.md).
- Backing memory page: [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md).
- RTTI pointer: `0x0061b650` -> `0x006486d4` (`??_R4ImageLib@@6B@`).
- Primary vtable: `0x0061b654` (`off_61B654`)
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e64a0` | `ImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table ends before the `MapTileImageLib` RTTI pointer at `0x0061b660` and `MapTileImageLib` vtable at `0x0061b664`. The [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) lookup family is therefore not virtual through `ImageLib`; if those methods remain in the same original source area, they are non-virtual `ImageLib` API, helper functions, or a recovered base/facet alias.

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e64a0` -> `sub_4E64A0`, size `0xd2`, ImageLib scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b650` dword `0x006486d4` -> `??_R4ImageLib@@6B@`.
  - `0x0061b654` dword `0x004e64a0` -> `sub_4E64A0`, xrefs from `0x004d0009`, `0x004d009a`, and `0x004e64d1`.
  - `0x0061b658` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b65c` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b660` dword `0x00648774` -> `??_R4MapTileImageLib@@6B@`, proving the next image-library RTTI boundary.
  - `0x0061b664` -> `??_7MapTileImageLib@@6B@`, next vtable.
- IDA names in the same region include `??_R4ImageLib@@6B@` and associated `Singleton<ImageLib>` RTTI records at `0x00648724-0x00648758`.

IDA xrefs to `0x0061b654` land at:

- `0x004d0009` in [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md)
- `0x004d009a` in [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- `0x004e64d1` in `ImageLib::ScalarDeletingDestructor`

Generated `class_ImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `ImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

No `RECONSTRUCTION_CPP CODE` is emitted here. Source declarations and method bodies should be attached through the owning class/file and exact `by-memory` pages only after the final-source confidence gate is satisfied.

## Cross-References

- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)

## Changes

- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, and the next `MapTileImageLib` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding ImageLib method dependencies are not final-audited.
