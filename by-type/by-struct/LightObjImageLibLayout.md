*** UID:0001UX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LightObjImageLib Layout

## Status

- Confidence: strong for observed offsets, medium for final field names.
- Owner class: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md).
- Autogen parent: attached to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md); the class scores `84/80` and this layout scores `84/86`, so both sides satisfy the 80/80 parent gate.
- Evidence: IDA constructor/destructor/draw decompilation and xrefs on 2026-05-26.

## Layout

```text
LightObjImageLib
  +0x00  LObject/vtable
  +0x04  ProtectedArray<LightInfo> lightInfoArray
  +0x14  LightInfo fallbackLightInfo
```

Expanded view:

```text
  +0x04  void* protectedArrayVtable
  +0x08  int lightInfoCount
  +0x0c  LightInfo* lightInfoEntries
  +0x10  int initialOrGrowCapacity
  +0x14  LightInfo fallbackLightInfo
```

The fallback record at `+0x14` is `0x1c` bytes, so the observed object state reaches at least `+0x30`.

## Notes

- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) writes [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md), stores the [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md), installs the `ProtectedArray<LightInfo>` vtable at `+0x04`, initializes capacity `10`, and seeds the fallback record from constants at `0x00619660`.
- The constructor opens `LIGHT.TBL`, reads a count, reallocates the entry buffer as `count * 0x1c`, then reads each [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) row.
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md), [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md), and [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) index the entry buffer by light index, falling back to `+0x14` when out of range.
- The ordinary and [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) delete each generated frame, free the entry buffer at `+0x0c`, restore the protected-array vtable, and clear [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md).

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)
- [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)

## Changes

- 2026-06-06: Attached the object layout to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md). Scores remain `84/86`; this parent metadata update follows the documented class-owned `ProtectedArray<LightInfo>` and fallback row.
- 2026-05-31 LightObjImageLib split pass:
  - What existed before: metadata scores were `0/0`, and the layout page referenced broad method roles without exact child pages for the constructor, bounds helper, draw modes, or scalar deleting destructor.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, with exact by-memory references for the verified method children.
  - Summary/evidence: IDA MCP verified the constructor, draw methods, bounds helper, ordinary destructor, scalar deleting destructor, vtable writes, singleton writes, `ProtectedArray<LightInfo>` vtable writes, and 0x1c-byte row stride. Final field names still need source-level refinement, so scores remain below near-final thresholds.
