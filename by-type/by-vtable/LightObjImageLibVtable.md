*** UID:0001XY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LightObjImageLib Vtable

## Status

- Confidence: strong for address and slots.
- Owner class: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md).
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

- `0x004df83c` in [UID:00017P][0x004df7e0-0x004e669c.LightObjImageLib](by-memory/0x004df7e0-0x004e669c.LightObjImageLib.md)
- `0x004dfab9` in [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- `0x004e65ec` in the scalar deleting destructor

IDA xrefs to `0x0061b74c` land at:

- `0x004df842` in the constructor
- `0x004dfb14` in the ordinary destructor
- `0x004e5b23` in constructor unwind/cleanup code associated with the constructor
- `0x004e61b9` in the `ProtectedArray<LightInfo>` destructor
- `0x004e664e` in the scalar deleting destructor

Active `class_LightObjImageLib.meta_wave3` currently reports `vtable_count: 0`, so this page is the IDA-confirmed vtable anchor until generated metadata catches up.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)

## Changes

- 2026-05-31 LightObjImageLib split pass:
  - What existed before: metadata scores were `0/0`, and vtable slots pointed to unlinked address labels.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, with exact method child references for the deleting destructor and draw slots.
  - Summary/evidence: IDA MCP verified RTTI/vtable dwords at `0x0061b750-0x0061b768`, xrefs from constructor/destructors, and the adjacent `ProtectedArray<LightInfo>` vtable. Completion remains below near-final because inherited/shared slot `0x004f4b10` and final source declaration shape are not fully documented here.
