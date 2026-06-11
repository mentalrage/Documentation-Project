*** UID:0001UW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LightInfo

## Status

- Confidence: strong for size, offsets, constructor/destructor/draw usage, and generated-frame lifetime; medium for final names of the first two integer fields.
- Owner: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md).
- Autogen parent: attached to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md); the class scores `84/80` and this row page scores `82/86`, so both sides satisfy the 80/80 parent gate.
- Source placement: [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md).

## Layout

```text
LightInfo
  +0x00  int lightIdOrTableKey
  +0x04  int lightSource
  +0x08  int radiusX
  +0x0c  int radiusY
  +0x10  float brightness
  +0x14  float blendValue
  +0x18  AlphaMaskSurface* generatedFrame
  sizeof = 0x1c
```

## Field Evidence

- The constructor reads the first four fields with the integer DAT read helper, then reads `brightness` and `blendValue` with the float DAT read helper.
- The entry buffer allocation uses `count * 0x1c`, and all entry indexing steps by `0x1c`.
- Positive `radiusX` and `radiusY` allocate a frame sized `(2 * radiusX + 1)` by `(2 * radiusY + 1)`.
- `brightness` is converted through `int(brightness * 32.0f + 0.5f)` before radial mask generation.
- `blendValue` is passed directly into the radial mask generation helper.
- `generatedFrame` is deleted by both LightObjImageLib destructors and consumed by draw modes through its frame width and height fields.
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) uses `radiusX` and `radiusY` to emit a local bounds rectangle of `-radiusX,-radiusY,radiusX+1,radiusY+1` when `generatedFrame` is non-null.

## Notes

`LightInfo` is not an EPF frame-table record. It is a procedural light-mask descriptor loaded from `LIGHT.TBL`; the frame pointer is built at startup from the scalar fields.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)

## Changes

- 2026-06-06: Attached the light table row to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md). Scores remain `82/86`; the parent sync follows the documented constructor/draw/destructor ownership and the class page's 80/80 gate.
- 2026-05-31 LightObjImageLib split pass:
  - What existed before: metadata scores were `0/0`; field evidence did not mention the IDA-confirmed light-bounds helper.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, plus the `0x004dfb40` bounds-helper evidence and exact method cross-references.
  - Summary/evidence: IDA MCP verified the constructor's `0x1c` row allocation/read sequence, draw methods' use of generated frame pointers, destructor cleanup of `+0x18`, and the `0x004dfb40` helper's use of `radiusX/radiusY` for local bounds. Field names for the first two integers remain provisional, so scores stay below near-final thresholds.
