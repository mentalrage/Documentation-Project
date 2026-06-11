*** UID:0001XY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LightObjImageLib Vtable

## Status

- Confidence: strong for address and slots.
- Owner class: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md).
- Exact backing memory page: [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md).
- RTTI pointer: `0x0061b750` -> `0x0064900c`.
- Primary vtable: `0x0061b754`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e65e0` | [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |
| `+0x0c` | `0x004dfbb0` | [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) |
| `+0x10` | `0x004dfc60` | [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) |

The table ends before the `NewHumanImageLib` RTTI pointer at `0x0061b768`.

## Adjacent Template Vtable

The `ProtectedArray<LightInfo>` vtable is immediately before this class vtable:

| Address | Slot | Function |
| --- | --- | --- |
| `0x0061b74c` | `+0x00` | `0x004e61b0`, `ProtectedArray<LightInfo>` scalar deleting destructor |

Its RTTI pointer at `0x0061b748` points to `0x006490ac`.

## Evidence

IDA xrefs to `0x0061b754` land at:

- `0x004df83c` in [UID:00017P][0x004df7e0-0x004e669d.LightObjImageLib](by-memory/0x004df7e0-0x004e669d.LightObjImageLib.md)
- `0x004dfab9` in [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- `0x004e65ec` in the scalar deleting destructor

IDA xrefs to `0x0061b74c` land at:

- `0x004df842` in the constructor
- `0x004dfb14` in the ordinary destructor
- `0x004e5b23` in constructor unwind/cleanup code associated with the constructor
- `0x004e61b9` in the `ProtectedArray<LightInfo>` destructor
- `0x004e664e` in the scalar deleting destructor

Active `class_LightObjImageLib.meta_wave3` currently reports `vtable_count: 0`, so this page is the IDA-confirmed vtable anchor until generated metadata catches up.

## 2026-06-08 Assignment Gate Recheck

Batch 139 split the exact concrete vtable data out of the broader image-library read-only aggregate as [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md). That child records the RTTI pointer, five slot dwords, target function sizes, constructor/raw-destructor/scalar-deleting-destructor xrefs, and the adjacent `ProtectedArray<LightInfo>` and `NewHumanImageLib` boundaries.

The adjacent `ProtectedArray<LightInfo>` vtable at `0x0061b748-0x0061b750` is lifecycle/template support, not part of the `LightObjImageLib` primary vtable. Keeping the exact child at `0x0061b750-0x0061b768` prevents that template pair from being folded into the class vtable declaration.

The direct parent for this type page is [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md), now `86/86`, and the source-file parent below that class is [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md), now `87/85`. The child page is `86/91`, so the corrected child-and-direct-parent `85/85` gate is satisfied. `AUTOGEN_PARENT_UID` is therefore set to the class page, while the concrete vtable-data child attaches here.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)

## Changes

- 2026-06-08 A007 Batch 139 gate update:
  - What existed before: the vtable page was `82/90`, had no autogen parent, and relied on the broad image-library aggregate plus vtable-slot prose.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, `AUTOGEN_PARENT_UID:000076`, and an exact backing child link to [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md).
  - Summary/evidence: Batch 139 exact child evidence records the RTTI/vtable dwords, five target slots, xrefs, and neighboring `ProtectedArray<LightInfo>` / `NewHumanImageLib` boundaries; [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) and [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) were refreshed enough to satisfy the strict parent gate.
- 2026-05-31 LightObjImageLib split pass:
  - What existed before: metadata scores were `0/0`, and vtable slots pointed to unlinked address labels.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, with exact method child references for the deleting destructor and draw slots.
  - Summary/evidence: IDA MCP verified RTTI/vtable dwords at `0x0061b750-0x0061b768`, xrefs from constructor/destructors, and the adjacent `ProtectedArray<LightInfo>` vtable. Completion remains below near-final because inherited/shared slot `0x004f4b10` and final source declaration shape are not fully documented here.
