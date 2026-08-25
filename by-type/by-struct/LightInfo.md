*** UID:0001UW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct LightInfo
{
    int tableId;
    int innerRadius;
    int radiusX;
    int radiusY;
    float brightness;
    float blendScale;
    IntAlphaSurface *generatedFrame;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LightInfo

## 2026-08-18 Header Ownership

The exact 0x1c `LIGHT.TBL` row now emits once in `LightObjImageLib.h`, not as a CPP-local declaration. Field order remains table id, inner radius, X/Y radii, brightness at `+0x10`, blend scale, and generated `IntAlphaSurface *`. Constructor, bounds, draw, and metric dataflow and score remain unchanged; the formal H block is positioned before the class layout declaration.

## UID0001PR Accepted Source-Ready Record Declaration - 2026-07-21

- This exact `0x1c` declaration now emits at [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) position `1`, immediately before the complete class declaration. It is source-bearing type content, not a method-body substitute.
- `tableId` is a bounded lexical inference for the first integer loaded from `LIGHT.TBL`; no runtime read resolves its original spelling. The name is retained because it identifies the table-origin role without claiming a light object pointer or a live source selector.
- `innerRadius`, `radiusX`, and `radiusY` are fixed by the constructor call to `FillEllipticGradient`, generated-frame dimensions, and bounds helper. `brightness` is fixed by the `* 32.0f + 0.5f` alpha conversion and the external metric consumer. `blendScale` is the second table float passed directly to radial generation. `generatedFrame` is the allocated/deleted/drawn `IntAlphaSurface *` at `+0x18`.
- Constructor allocation/indexing, fallback-row access, bounds, both draw modes, and both destructor lowerings all use a `0x1c` stride. There is no tail padding or hidden source field in the record.
- Historical blank-formal wording below describes the pre-callback state and is superseded by the managed source declaration above. Method bodies remain on exact by-memory children, while this page now correctly emits the shared record type required by those bodies.

## Status

- Confidence: strong for size, offsets, constructor/destructor/draw usage, generated-frame lifetime, and source-facing names for all runtime-used fields; bounded for the exact original spelling of the first table identifier field.
- Owner: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md).
- Owner/emitter route: attached to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md), which emits through [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md). The class/file route clears the strict gate; this page emits the source-ready record declaration at position `1`, while method bodies emit through the exact by-memory children.
- Source placement: [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md).

## Layout

```text
LightInfo
  +0x00  int tableId
  +0x04  int innerRadius
  +0x08  int radiusX
  +0x0c  int radiusY
  +0x10  float brightness
  +0x14  float blendScale
  +0x18  IntAlphaSurface* generatedFrame
  sizeof = 0x1c
```

## Field Evidence

- The constructor reads the first four fields with the integer DAT read helper, then reads `brightness` and `blendScale` with the float DAT read helper.
- The entry buffer allocation uses `count * 0x1c`, and all entry indexing steps by `0x1c`.
- Positive `radiusX` and `radiusY` allocate a frame sized `(2 * radiusX + 1)` by `(2 * radiusY + 1)`.
- `brightness` is converted through `int(brightness * 32.0f + 0.5f)` before radial mask generation.
- [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) provides a direct consumer of this field outside the LightObjImageLib method bodies: the raw resolver helper copies a selected or fallback row to stack locals, then `fld [ebp-0x0c]` reads local row offset `+0x10`, proving that the helper returns `LightInfo::brightness`.
- `blendScale` is passed directly into the radial mask generation helper.
- The former `lightSource` label for `+0x04` is rejected. Constructor dataflow passes `+0x04` to `IntAlphaSurface::FillEllipticGradient` as the `innerRadius` argument after `GetCenterPoint` has computed the generated frame center from frame dimensions.
- The second float at `+0x14` flows into `FillEllipticGradient` as the falloff/blend scale parameter, so `blendScale` is a better source-facing name than `blendValue`.
- The first integer at `+0x00` is preserved from `LIGHT.TBL` but has no recovered runtime consumer in constructor, bounds, draw, or destructor paths. `tableId` is the best bounded source-facing name; exact original spelling remains unknown.
- `generatedFrame` is deleted by both LightObjImageLib destructors and consumed by draw modes through its frame width and height fields.
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) uses `radiusX` and `radiusY` to emit a local bounds rectangle of `-radiusX,-radiusY,radiusX+1,radiusY+1` when `generatedFrame` is non-null.
- 2026-06-14 live IDA MCP rechecked the current family: constructor `0x004df7e0` is size `0x2c6`, bounds helper `0x004dfb40` is size `0x70`, draw modes `0x004dfbb0` and `0x004dfc60` are size `0xaa` each, scalar deleting destructor `0x004e65e0` is size `0xbd`, and the ordinary destructor start `0x004dfab0` still reports `Not a function`.
- Current constructor decompilation opens `LIGHT.TBL`, allocates `28 * count`, reads four integer fields followed by two floats, creates a generated frame only when both radii are positive, sizes that frame as `(2 * radiusX + 1)` by `(2 * radiusY + 1)`, converts brightness through `int(brightness * 32.0f + 0.5f)`, passes the second float into radial frame generation, and stores the row as `0x10` bytes plus the two float/pointer words at `+0x10/+0x14/+0x18`.
- Raw destructor disassembly at `0x004dfab0` and scalar deleting destructor decompilation both iterate by `0x1c`, select the fallback record at object `+0x14` for out-of-range cases, delete the generated-frame pointer at row `+0x18`, restore the `ProtectedArray<LightInfo>` vtable, free the row buffer at object `+0x0c`, and clear `g_pLightObjImageLib`.
- Current bounds and draw decompilation index entries as `base + 28 * index`, use fallback `this + 0x14` when the index is out of range, test generated-frame pointer `+0x18`, derive bounds from `radiusX/radiusY`, and draw centered generated frames using blend modes `1` and `2`.

## Notes

`LightInfo` is not an EPF frame-table record. It is a procedural light-mask descriptor loaded from `LIGHT.TBL`; the frame pointer is built at startup from the scalar fields.

## Score Rationale

Completion is raised to `90` because the row size, constructor read order, generated-frame allocation, `IntAlphaSurface` argument mapping, bounds behavior, both draw modes, ordinary/scalar destructor cleanup, fallback row, class/file route, and exact emitting declaration are now documented. Confidence remains `92` because constructor dataflow into `FillEllipticGradient` resolves the historical `+0x04` ambiguity as `innerRadius`; confidence remains below final because the exact original spelling of `tableId` is inferred rather than symbol-proven.

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
- [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md)

## Changes

- 2026-06-14 A002 score pass: raised from `82/86` to `85/90` after live IDA MCP reconfirmed `LIGHT.TBL` loading, `28 * count` row allocation, generated-frame creation at row `+0x18`, bounds/draw consumption, ordinary and scalar destructor cleanup, and the class/file emitter route. Reconstruction C++ remains blank because the first two field names and declaration placement remain below final source quality.
- 2026-06-06: Attached the light table row to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md). Scores remain `82/86`; the parent sync follows the documented constructor/draw/destructor ownership and the class page's 80/80 gate.
- 2026-05-31 LightObjImageLib split pass:
  - What existed before: metadata scores were `0/0`; field evidence did not mention the IDA-confirmed light-bounds helper.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, plus the `0x004dfb40` bounds-helper evidence and exact method cross-references.
  - Summary/evidence: IDA MCP verified the constructor's `0x1c` row allocation/read sequence, draw methods' use of generated frame pointers, destructor cleanup of `+0x18`, and the `0x004dfb40` helper's use of `radiusX/radiusY` for local bounds. Field names for the first two integers remain provisional, so scores stay below near-final thresholds.
- 2026-06-17 B003 source-quality audit:
  - Rejected the historical `lightSource` field name for `+0x04` and renamed the source-facing schema to `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`.
  - Evidence: constructor dataflow into `IntAlphaSurface::FillEllipticGradient`, downstream bounds/draw/destructor usage, fallback row behavior, and LightObjImageLib source readiness.
- 2026-06-21 B011 AttachmentAnchorResolver consumer sync:
  - Score unchanged at `88/92`.
  - Summary/evidence: [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) now documents a raw resolver helper that selects a `LightInfo` row and returns row offset `+0x10`; this reinforces the `brightness` field name while preserving exact original spelling caveats for `tableId`.
