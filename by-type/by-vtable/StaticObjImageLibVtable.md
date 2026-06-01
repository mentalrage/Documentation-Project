*** UID:0001YX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- `0x004dd20b` in [UID:00017I][0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor.md)
- `0x004e69c4` in the scalar deleting destructor

- 2026-06-01 IDA MCP `py_eval` confirmed `0x0061b700` as `??_R4StaticObjImageLib@@6B@`, `0x0061b704` as `??_7StaticObjImageLib@@6B@`, slots `0x0061b704/0x0061b708/0x0061b70c`, and the `0x0061b710` boundary before `ProtectedArray<EffectInfo>`.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:00017I][0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md)

## Changes

- What existed before: this page had correct vtable slot notes but was still scored `0/0`, did not link an exact by-memory vtable-data child page, and included a Wave3 status line as supporting evidence.
- What it was changed to: the page now uses IDA MCP evidence for the exact `0x0061b700-0x0061b710` vtable-data range, marks the item reconstructable, and links the exact child page [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md).
- Summary and evidence: 2026-06-01 IDA MCP `py_eval` verified the RTTI-adjacent word, three slot dwords, data xrefs, preceding `RidingImageLib` table, and following `ProtectedArray<EffectInfo>` boundary.
