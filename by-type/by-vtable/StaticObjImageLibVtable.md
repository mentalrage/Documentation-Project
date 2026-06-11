*** UID:0001YX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib Vtable

## Status

- Confidence: strong for address and slots.
- Owner class: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md).
- RTTI pointer: `0x0061b700`
- Primary vtable: `0x0061b704`
- Exact vtable-data child: [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md)

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e6990` | `StaticObjImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The exact vtable-data range is `0x0061b700-0x0061b710`. It starts at the `StaticObjImageLib` RTTI-adjacent complete-object-locator pointer and ends before the `ProtectedArray<EffectInfo>` RTTI pointer at `0x0061b710`.

## Evidence

IDA xrefs to `0x0061b704` land at:

- `0x004dcfb8` in [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md)
- `0x004dd20b` in [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md)
- `0x004e69c4` in the scalar deleting destructor

- 2026-06-01 IDA MCP `py_eval` confirmed `0x0061b700` as `??_R4StaticObjImageLib@@6B@`, `0x0061b704` as `??_7StaticObjImageLib@@6B@`, slots `0x0061b704/0x0061b708/0x0061b70c`, and the `0x0061b710` boundary before `ProtectedArray<EffectInfo>`.
- 2026-06-08 Batch124 live IDA MCP rechecked the same range against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`): `0x0061b700 -> 0x00648d54`, `0x0061b704 -> 0x004e6990`, `0x0061b708 -> 0x004f4b10`, `0x0061b70c -> 0x0041b6c0`, and `0x0061b710 -> 0x00648e94`.
- The same recheck confirms xrefs to vtable base `0x0061b704` at constructor write `0x004dcfb8`, ordinary destructor restore `0x004dd20b`, and scalar deleting destructor self-reference `0x004e69c4`. Function lookup reports stable target sizes: scalar deleting destructor `0x004e6990` size `0x116`, inherited/shared slot `0x004f4b10` size `0x6`, and `nullsub_18` size `0x3`.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). The vtable page now clears `85/90`, the direct class parent clears `86/85`, and the class's file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) also clears `86/85`. This is a direct class-vtable relationship: the slots are written by the `StaticObjImageLib` constructor, ordinary destructor, and scalar deleting destructor, and the exact vtable-data child can attach to this type page.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md)

## Changes

- What existed before: this page had correct vtable slot notes but was still scored `0/0`, did not link an exact by-memory vtable-data child page, and included a Wave3 status line as supporting evidence.
- What it was changed to: the page now uses IDA MCP evidence for the exact `0x0061b700-0x0061b710` vtable-data range, marks the item reconstructable, and links the exact child page [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md).
- Summary and evidence: 2026-06-01 IDA MCP `py_eval` verified the RTTI-adjacent word, three slot dwords, data xrefs, preceding `RidingImageLib` table, and following `ProtectedArray<EffectInfo>` boundary.
- 2026-06-08 A005 Batch124 strict-gate refresh:
  - Before: `84/90`, reconstructable, and unassigned because this page was just below the child completion gate when the exact vtable-data child was reviewed.
  - Changed to: `85/90` and `AUTOGEN_PARENT_UID:0000E2`.
  - Summary/evidence: live IDA MCP reconfirmed the exact dwords, boundary before `ProtectedArray<EffectInfo>`, constructor/destructor/scalar-destructor xrefs, and target function sizes. [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) and [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) now both clear the corrected `85/85` gate, so the class-vtable parent relationship is justified.
