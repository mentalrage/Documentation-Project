*** UID:000076 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LightObjImageLib

## Status

- Confidence: strong for method roles, singleton/vtable evidence, and observed layout offsets; medium for final field names.
- Likely source file: [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- Address ranges: [UID:00017P][0x004df7e0-0x004e669c.LightObjImageLib](by-memory/0x004df7e0-0x004e669c.LightObjImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_LightObjImageLib.cpp`
- Singleton: [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) at `0x0069b450`
- Vtable: [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md) at `0x0061b754`

## Class Purpose

`LightObjImageLib` is the singleton-backed light-source rendering library behind `g_pLightObjImageLib`. It loads light metadata from `LIGHT.TBL`, creates radial light frames at startup, renders those frames with two blend modes, and releases the generated frames during destruction.

## Observed State

```text
0x00  LObject/vtable base
0x04  ProtectedArray<LightInfo> vtable
0x08  int lightInfoCount
0x0c  LightInfo* lightInfoEntries
0x10  int initialOrGrowCapacity
0x14  LightInfo fallback/default record
```

The recovered [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) rows are `0x1c` bytes and include light id/source, X/Y radii, brightness, blend value, and a generated image-frame pointer. See [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md) for the current offset model.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LightObjImageLib::LightObjImageLib` | [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) | Loads `LIGHT.TBL`, allocates light records, and prebuilds radial light frames. |
| `LightObjImageLib::~LightObjImageLib` | `0x004dfab0` | Raw ordinary destructor body; releases generated frames, frees the record array, clears the singleton, and tail-calls `LObject` cleanup. |
| `GetLightBounds` | [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) | Returns a local light bounds rectangle from the selected record radii. |
| `DrawLightMode1` | [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) | Draws a centered light frame through `DrawFrameWithBlendMode` using blend mode `1`. |
| `DrawLightMode2` | [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) | Draws a centered light frame through `DrawFrameWithBlendMode` using blend mode `2`. |
| `ClearLightObjImageLibSingleton` | `0x004e5bb0` | Tiny helper that clears `g_pLightObjImageLib`; no direct callers currently modeled. |
| `ScalarDeletingDestructor` | [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) | Releases generated frames, frees the light record array, clears `g_pLightObjImageLib`, and optionally deletes `this`. |

IDA MCP on 2026-05-22 confirms the constructor has one startup caller at `0x004f6139`. The two draw methods have no direct code refs because they are virtual dispatch targets, but IDA confirms slots `+0x0c` and `+0x10` in the class vtable and both methods call the same frame blitter at `0x00462e10`; see [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md).

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:00017P][0x004df7e0-0x004e669c.LightObjImageLib](by-memory/0x004df7e0-0x004e669c.LightObjImageLib.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/80`. Summary: the singleton library is documented at a high level of detail across purpose, observed layout, vtable, global, `LIGHT.TBL` loading, generated light-frame lifetime, and draw methods, but exact final field names are still medium-confidence. Evidence: linked memory range, `LightInfo` and layout type pages, `g_pLightObjImageLib`, vtable slot evidence, constructor startup caller, and shared frame blitter reference.
- 2026-05-31 exact method split:
  - What existed before: the method table used bare addresses for the constructor, draw modes, and scalar deleting destructor and did not include the `0x004dfb40` bounds helper.
  - Changed to: exact by-memory links for the constructor, bounds helper, draw mode methods, and scalar deleting destructor.
  - Summary/evidence: IDA MCP verified exact function bounds, vtable slots for the two draw methods and deleting destructor, and an external caller for the bounds helper at `0x0053c82b`.
