*** UID:0001XG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00004A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectObjImageLib Vtable

## Status

- Confidence: strong for address, RTTI locator, slot targets, adjacent boundaries, and vptr-store xrefs.
- Owner class: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md).
- Exact memory page: [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md).
- Backing aggregate page: [UID:00025I][0x0061b664-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c360.ImageLibraryReadOnlyData.md).
- Autogen status: attached under [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md); final C++ remains blank under the `95/95` gate.
- RTTI pointer: `0x0061b720` -> `0x00648df4` (`??_R4EffectObjImageLib@@6B@`).
- Primary vtable: `0x0061b724` (`??_7EffectObjImageLib@@6B@`).
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e62f0` | `EffectObjImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table ends before the `ProtectedArray<ItemInfo>` RTTI pointer at `0x0061b730` and its vtable at `0x0061b734`.

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e62f0` -> `sub_4E62F0`, size `0x166`, scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b714` is the preceding `ProtectedArray<EffectInfo>` vtable.
  - `0x0061b71c` is the preceding `ProtectedArray<EffectPixMapInfo>` vtable.
  - `0x0061b720` dword `0x00648df4` -> `??_R4EffectObjImageLib@@6B@`.
  - `0x0061b724` dword `0x004e62f0` -> `sub_4E62F0`, xrefs from `0x004ddfb0`, `0x004de07d`, and `0x004e6324`.
  - `0x0061b728` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b72c` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b730` dword `0x00648fc4` -> `??_R4?$ProtectedArray@UItemInfo@@@@6B@`, proving the next template-vtable boundary.
- IDA names in the same region include `??_7EffectObjImageLib@@6B@`, `??_R4EffectObjImageLib@@6B@`, and the associated `Singleton<EffectObjImageLib>` RTTI records at `0x00648e44-0x00648e78`.

IDA xrefs to `0x0061b724` land at:

- `0x004ddfb0` in [UID:00017K][0x004ddf60-0x004e6455.EffectObjImageLib](by-memory/0x004ddf60-0x004e6455.EffectObjImageLib.md)
- `0x004de07d` in [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md)
- `0x004e6324` in the scalar deleting destructor

Generated `class_EffectObjImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `EffectObjImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

No `RECONSTRUCTION_CPP CODE` is emitted here. Source declarations and method bodies should be attached through the owning class/file and exact `by-memory` method pages only after the final-source confidence gate is satisfied.

## Parent Rationale

Attach this generated-binary vtable page to [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md). The page describes only the `EffectObjImageLib` primary vtable and RTTI locator, the owner class already clears the `80/80` attachment gate and is attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and the neighboring template vtables are documented as boundaries rather than part of this class.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the page had strong RTTI/vtable evidence and an exact memory child, but no autogen parent.
  - Changed to: `COMPLETION:84` and `AUTOGEN_PARENT_UID:00004A`, with an explicit class-parent rationale.
  - Summary/evidence: the vtable page covers only the `EffectObjImageLib` primary vtable at `0x0061b724`; [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) clears the attachment gate, and the adjacent `ProtectedArray` vtables remain documented as non-owner boundaries.
- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the exact [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md), RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, preceding `ProtectedArray<EffectInfo>` / `ProtectedArray<EffectPixMapInfo>` vtables, and next `ProtectedArray<ItemInfo>` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding EffectObjImageLib method dependencies are not final-audited.
