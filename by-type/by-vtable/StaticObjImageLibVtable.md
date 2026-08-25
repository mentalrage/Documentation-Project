*** UID:0001YX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib Vtable

## Status

- Confidence: near-certain for exact range, slots, RTTI hierarchy, direct bases, PMD/EBO relation, xrefs, and compiler-generated disposition.
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

## RTTI Hierarchy

| Entity | Range/address | Exact role |
| --- | --- | --- |
| Complete Object Locator | `0x00648d54-0x00648d68` | `??_R4StaticObjImageLib@@6B@`; points to the StaticObjImageLib type descriptor and class hierarchy descriptor. |
| Class Hierarchy Descriptor | `0x00648d68-0x00648d78` | `??_R3StaticObjImageLib@@8`; records three hierarchy entries. |
| Base-class array | `0x00648d78-0x00648d84` | Entries reference StaticObjImageLib, shared `LObject`, and direct `Singleton<StaticObjImageLib>`. |
| StaticObjImageLib BCD | `0x00648d88-0x00648da4` | Complete derived type descriptor, PMD `0,-1,0`. |
| Singleton direct-base BCD | `0x00648da4-0x00648dc0` | `??_R13?0A@EA@?$Singleton@VStaticObjImageLib@@@@8`; PMD `+4,-1,0`, attributes `0x40`. |
| Singleton CHD/base array/self BCD | `0x00648dc0-0x00648df4` | One-entry hierarchy for the direct empty Singleton specialization. |
| StaticObjImageLib type descriptor | `0x00676a8c-0x00676aac` | Decorated descriptor text `.?AVStaticObjImageLib@@`. |
| Singleton type descriptor | `0x00676aac-0x00676adc` | Decorated descriptor for `Singleton<StaticObjImageLib>`. |

The shared `LObject` BCD is at `0x00640348-0x00640364`. The successor `EffectObjImageLib` COL begins at `0x00648df4`; neither it nor the `ProtectedArray<EffectInfo>` pointer at `0x0061b710` belongs to this vtable/RTTI family.

The Singleton PMD and constructor EH receiver adjustment both use complete-object offset `+0x04`. Because the complete StaticObjImageLib object is `0x14` bytes and its first derived field also starts at `+0x04`, this is empty-base optimization rather than a stored base member.

## Evidence

IDA xrefs to `0x0061b704` land at:

- `0x004dcfb8` in [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md)
- `0x004dd20b` in [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md)
- `0x004e69c4` in the scalar deleting destructor

- 2026-06-01 IDA MCP `py_eval` confirmed `0x0061b700` as `??_R4StaticObjImageLib@@6B@`, `0x0061b704` as `??_7StaticObjImageLib@@6B@`, slots `0x0061b704/0x0061b708/0x0061b70c`, and the `0x0061b710` boundary before `ProtectedArray<EffectInfo>`.
- 2026-06-08 Batch124 live IDA MCP rechecked the same range against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`): `0x0061b700 -> 0x00648d54`, `0x0061b704 -> 0x004e6990`, `0x0061b708 -> 0x004f4b10`, `0x0061b70c -> 0x0041b6c0`, and `0x0061b710 -> 0x00648e94`.
- The same recheck confirms xrefs to vtable base `0x0061b704` at constructor write `0x004dcfb8`, ordinary destructor restore `0x004dd20b`, and scalar deleting destructor self-reference `0x004e69c4`. Function lookup reports stable target sizes: scalar deleting destructor `0x004e6990` size `0x116`, inherited/shared slot `0x004f4b10` size `0x6`, and `nullsub_18` size `0x3`.
- UID000184 reanalysis ties the direct Singleton BCD to [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md): constructor state 1 passes `this+4`, while the ordinary/scalar paths inline the same global clear before `LObject` destruction.

## Source Disposition

- This page is retained compiler data, not source-authored reconstructable code. It has semantic owner UID0000E2 but blank emitters and blank CPP/H.
- `class StaticObjImageLib : public LObject, public Singleton<StaticObjImageLib>` plus its `virtual ~StaticObjImageLib()` declaration regenerates the COL, CHD, base descriptors, vtable, scalar deleting slot, and associated compiler metadata.
- The exact vtable-data child UID0002OY remains binary range evidence; it must not emit an independent table or placeholder.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) as semantic owner. This page is `92/97`, non-reconstructable, and non-emitting; the direct class is `92/96` and file source root is `90/94`. The constructor, ordinary destructor, and scalar wrapper reference the exact table, while the class hierarchy is its source cause.

## Score Rationale

- `COMPLETION:92`: exact vtable/data range, all three slots, boundaries, xrefs, COL, CHD, base array, derived/`LObject`/Singleton BCDs, type descriptors, PMD/EBO interpretation, semantic owner, and blank compiler-support disposition are documented.
- `CONFIDENCE:97`: bytes, decorated RTTI names, vtable words, constructor/destructor/scalar refs, and UID000184 EH evidence agree. The remaining gap is only unavailable original build/debug bookkeeping.

## Historical Superseded Assumptions

- Earlier metadata marked the page reconstructable with emitter UID0000E2 because the class relationship was strong. That relationship remains, but compiler vtable/RTTI data has no independent source body and is now correctly non-emitting.
- Earlier class notes omitted the direct Singleton RTTI branch. The exact BCD/CHD/type descriptor and PMD `+4,-1,0` now close that hierarchy.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md)

## Changes

- 2026-08-11 B005 UID000184 lifecycle implementation: raised `85/90` to `92/97`, preserved semantic owner UID0000E2, changed reconstructable to false, blanked emitters, and incorporated the complete RTTI hierarchy, direct Singleton PMD/EBO, UID000184 relationship, exact compiler-source cause, and non-emitting formal disposition.

- What existed before: this page had correct vtable slot notes but was still scored `0/0`, did not link an exact by-memory vtable-data child page, and included a Wave3 status line as supporting evidence.
- What it was changed to: the page now uses IDA MCP evidence for the exact `0x0061b700-0x0061b710` vtable-data range, marks the item reconstructable, and links the exact child page [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md).
- Summary and evidence: 2026-06-01 IDA MCP `py_eval` verified the RTTI-adjacent word, three slot dwords, data xrefs, preceding `RidingImageLib` table, and following `ProtectedArray<EffectInfo>` boundary.
- 2026-06-08 A005 Batch124 strict-gate refresh:
  - Before: `84/90`, reconstructable, and unassigned because this page was just below the child completion gate when the exact vtable-data child was reviewed.
  - Changed to: `85/90` and `AUTOGEN_PARENT_UID:0000E2`.
  - Summary/evidence: live IDA MCP reconfirmed the exact dwords, boundary before `ProtectedArray<EffectInfo>`, constructor/destructor/scalar-destructor xrefs, and target function sizes. [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) and [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) now both clear the corrected `85/85` gate, so the class-vtable parent relationship is justified.
