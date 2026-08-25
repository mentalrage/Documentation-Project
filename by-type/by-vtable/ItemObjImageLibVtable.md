*** UID:0001XW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemObjImageLib Vtable

## Status

- Confidence: very strong for address, RTTI locator, slot targets, direct hierarchy, adjacent boundaries, vptr-store xrefs, and generated-binary disposition.
- Owner class: [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md).
- Exact memory page: [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md).
- Backing aggregate page: [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md).
- RTTI pointer: `0x0061b738` -> `0x00648f24` (`??_R4ItemObjImageLib@@6B@`).
- Primary vtable: `0x0061b73c` (`??_7ItemObjImageLib@@6B@`).
- Rebuild handling: `source-declared/generated-binary`; semantic owner UID00006W, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and no direct source emission.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e6580` | `ItemObjImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` / runtime-class accessor |
| `+0x08` | `0x0041b6c0` | inherited `LObject::VirtualNoop(int, int)` |

The table ends before the `ProtectedArray<LightInfo>` RTTI pointer at `0x0061b748` and its vtable at `0x0061b74c`.

The `0x004f4b10` slot is inherited/shared with the `LObject` virtual interface: current support docs identify it as the runtime-class accessor returning the `LObject` string pointer. The `0x0041b6c0` slot remains the inherited no-op virtual body, best read source-facing as `LObject::VirtualNoop(int, int)` rather than the IDA artifact `nullsub_18`.

## Adjacent Template Vtable

The `ProtectedArray<ItemInfo>` vtable is immediately before this class vtable at `0x0061b734`; its single slot points to `0x004e6180`.

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e6580` -> `sub_4E6580`, size `0x5c`, scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b730` -> `??_R4?$ProtectedArray@UItemInfo@@@@6B@`.
  - `0x0061b734` -> `??_7?$ProtectedArray@UItemInfo@@@@6B@`, the immediately preceding template vtable.
  - `0x0061b738` dword `0x00648f24` -> `??_R4ItemObjImageLib@@6B@`.
  - `0x0061b73c` dword `0x004e6580` -> `sub_4E6580`, xrefs from `0x004dec8c`, `0x004dee23`, and `0x004e6586`.
  - `0x0061b740` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b744` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b748` dword `0x006490ac` -> `??_R4?$ProtectedArray@ULightInfo@@@@6B@`, proving the next template-vtable boundary.
- IDA names in the same region include `??_7ItemObjImageLib@@6B@`, `??_R4ItemObjImageLib@@6B@`, and associated `Singleton<ItemObjImageLib>` RTTI records at `0x00648f74-0x00648fa8`.

Live IDA MCP recheck on 2026-06-11 against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) reconfirmed the parent-gate evidence:

- `lookup_funcs` maps `0x004dec30` to `sub_4DEC30` size `0x1eb`, `0x004e6580` to `sub_4E6580` size `0x5c`, `0x004f4b10` to `sub_4F4B10` size `0x6`, and `0x0041b6c0` to `nullsub_18` size `0x3`; `0x004dee20` remains unmodeled as a function even though the destructor bytes are present.
- `xrefs_to 0x0061b73c` remains exactly the constructor vptr store at `0x004dec8c`, ordinary destructor store at `0x004dee23`, and scalar-deleting-destructor store at `0x004e6586`.
- Disassembly shows `0x004dec8c` storing `??_7ItemObjImageLib@@6B@`, `0x004dec92` storing the embedded `ProtectedArray<ItemInfo>` vtable, destructor bytes at `0x004dee23/0x004dee2c` restoring the same pair, and `0x004e6586/0x004e658f` doing the same during scalar deletion.
- The dword scan still reads `0x0061b730 -> 0x00648fc4`, `0x0061b734 -> 0x004e6180`, `0x0061b738 -> 0x00648f24`, `0x0061b73c/0x0061b740/0x0061b744 -> 0x004e6580/0x004f4b10/0x0041b6c0`, and `0x0061b748 -> 0x006490ac`, proving the `ProtectedArray<ItemInfo>` / `ItemObjImageLib` / `ProtectedArray<LightInfo>` boundaries.

B002 2026-06-23 MCP session `261fb29b` revalidated the destructor-specific vtable evidence while reviewing [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md). `xrefs_to 0x0061b73c` remains exactly the constructor vptr store at `0x004dec8c`, ordinary destructor store at `0x004dee23`, and scalar deleting destructor store at `0x004e6586`; `find_bytes 80 65 4e 00` finds the live vtable pointer to `sub_4E6580` at `0x0061b73c`. No VA or RVA pointer bytes to the ordinary raw destructor start `0x004dee20` were found, so slot `+0x00` stays the scalar deleting destructor and [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) remains a separate ordinary-body page with blank formal C++.

IDA xrefs to `0x0061b73c` land at:

- `0x004dec8c` in [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- `0x004dee23` in [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- `0x004e6586` in the scalar deleting destructor

Generated `class_ItemObjImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `ItemObjImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

The formal `RECONSTRUCTION_CPP CODE` block is literally blank. Source declarations and method bodies attach through the owning class/file and exact `by-memory` method pages; this type page must neither hand-port vtable dwords nor emit a compiler-artifact comment into generated source.

Semantic ownership remains [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md), not the source-file page, because this type page represents the class-owned virtual declaration shape. Emission is intentionally blank; the exact `.rdata` storage page remains the concrete generated-binary evidence anchor for the emitted dwords.

## 2026-07-20 B002 Singleton-Lifetime Callback

- Direct `Singleton<ItemObjImageLib>` inheritance is proven by the RTTI base descriptor and PMD `0,4,0`, while empty-base optimization keeps the complete object at `0x28` bytes. That non-polymorphic template base adds no vtable slot and does not alter this table's three-slot layout.
- UID0002VC is the vtable-only compiler scalar deleting destructor; UID00017O is the sole handwritten ordinary destructor. The inherited `LObject` runtime-class and no-op virtuals remain slots `+0x04` and `+0x08`.
- Constructor, ordinary destructor, and scalar wrapper stores at `0x004dec8c`, `0x004dee23`, and `0x004e6586` prove the class table route. Adjacent `ProtectedArray<ItemInfo>` and `ProtectedArray<LightInfo>` tables prove the exact exclusive boundaries.
- The accepted disposition is `92/95`, semantic owner UID00006W, non-reconstructable, and blank emitter/position/formal C++. The earlier reconstructable comment-emitter representation is retained below as history but is superseded because the class declaration regenerates all RTTI/vtable output.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)

## Changes

- 2026-07-20 B002 singleton-lifetime callback:
  - Raised the evidence score to `92/95`, retained semantic class ownership, and changed this source-declared/generated-binary type page to false/non-emitting with a literally blank managed block.
  - Preserved all slot, RTTI, direct Singleton hierarchy, adjacent-table, constructor/destructor/scalar-store, and inherited-name evidence; no handwritten vtable source is introduced.

- 2026-07-01 B007 accepted ItemObjImageLib empty-emitter implementation:
  - Added a formal comment-only no-code marker for this source-declared/generated-binary vtable type page. The emitted binary vtable is represented by the class declaration and exact vtable-data evidence, not handwritten dword source.
- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the exact [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md), RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, preceding `ProtectedArray<ItemInfo>` vtable, and next `ProtectedArray<LightInfo>` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding ItemObjImageLib draw-method dependencies are not final-audited.
- 2026-06-11 A003 parent-gate update:
  - What existed before: the page was `82/90` and parent-blank even though it documented a single `ItemObjImageLib` class vtable.
  - Changed to: `85/91` and `AUTOGEN_PARENT_UID:00006W` after [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) was refreshed to the corrected `85` confidence gate.
  - Summary/evidence: live IDA reconfirmed the IDB hash, slot target sizes, exact dword neighborhood, constructor/destructor/scalar-deleting-destructor stores, and adjacent template-vtable boundaries. The remaining unnamed inherited/shared virtual slot and non-final source declaration keep the page well below the final C++ gate.
- 2026-06-19 B008 source-quality sync:
  - No score change. Updated inherited slot names to `LObject::GetRuntimeClass` and `LObject::VirtualNoop(int, int)` based on current LObject support, while preserving the source-declared/generated-binary no-code policy.
- 2026-06-23 B002 ordinary-destructor sync:
  - No score change.
  - Summary/evidence: current MCP session `261fb29b` reconfirmed `0x0061b73c -> 0x004e6580` as the live scalar-deleting-destructor slot, the three class-vtable refs at `0x004dec8c`/`0x004dee23`/`0x004e6586`, and the absence of any direct pointer route to the ordinary raw destructor start `0x004dee20`.
