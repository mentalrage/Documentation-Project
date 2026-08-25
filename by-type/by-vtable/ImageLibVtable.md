*** UID:0001XR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001XR] no standalone vtable C++ body.
// The ImageLib vtable is compiler-emitted from the class declaration; exact slot data is documented by the vtable-data child and scalar deleting destructor route.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ImageLib Vtable

## Status

- Confidence: strong for address, RTTI locator, slot targets, adjacent boundary, target function ranges, and vptr-store xrefs.
- Owner class: [UID:00006E][ImageLib](by-class/ImageLib.md).
- Exact backing memory page: [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md).
- Containing mixed aggregate: [UID:00025H][0x0061b340-0x0061b660.HourIconsIdleReadOnlyData](by-memory/0x0061b340-0x0061b660.HourIconsIdleReadOnlyData.md).
- RTTI pointer: `0x0061b650` -> `0x006486d4` (`??_R4ImageLib@@6B@`).
- Primary vtable: `0x0061b654` (current IDA `ImageLib_vftable`, historical `off_61B654`)
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e64a0` | `ImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table ends before the `MapTileImageLib` RTTI pointer at `0x0061b660` and `MapTileImageLib` vtable at `0x0061b664`. The [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) lookup family is therefore not virtual through `ImageLib`; if those methods remain in the same original source area, they are non-virtual `ImageLib` API, helper functions, or a recovered base/facet alias.

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e64a0` -> `ImageLib_ScalarDeletingDestructor`, size `0xd2`, ImageLib scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b650` dword `0x006486d4` -> `??_R4ImageLib@@6B@`.
  - `0x0061b654` dword `0x004e64a0` -> `ImageLib_ScalarDeletingDestructor`, xrefs from `0x004d0009`, `0x004d009a`, and `0x004e64d1`.
  - `0x0061b658` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b65c` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b660` dword `0x00648774` -> `??_R4MapTileImageLib@@6B@`, proving the next image-library RTTI boundary.
  - `0x0061b664` -> `??_7MapTileImageLib@@6B@`, next vtable.
- IDA names in the same region include `??_R4ImageLib@@6B@` and associated `Singleton<ImageLib>` RTTI records at `0x00648724-0x00648758`.

IDA xrefs to `0x0061b654` land at:

- `0x004d0009` in [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md)
- `0x004d009a` in [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- `0x004e64d1` in `ImageLib::ScalarDeletingDestructor`

Generated `class_ImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## 2026-06-08 Assignment Gate Recheck

Batch 139 split the exact concrete vtable data out of the mixed UI/Idle aggregate as [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md). Live IDA evidence in that child records the IDB hashes, `0x0061b650` RTTI pointer, three slot dwords, target function sizes, constructor/destructor/scalar-deleting-destructor xrefs, and the `MapTileImageLib` boundary at `0x0061b660`.

The direct parent for this type page is [UID:00006E][ImageLib](by-class/ImageLib.md), now `87/88`, and the source-file parent below that class is [UID:0000K2][ImageLib](by-file/ImageLib.md), `90/88`. This type page is now `88/93`, and the exact memory child is [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md) at `89/93`, so the corrected child-and-direct-parent gate is satisfied. `CANONICAL_OWNER` and `EMITTER_UIDS` therefore stay on the class page, while the exact memory child attaches here to keep concrete vtable bytes under the source-level vtable declaration.

## 2026-06-11 A005 Batch 174 Recheck

Live IDA MCP reconfirmed the source-declared/generated-binary boundary:

| Address | Dword | Meaning |
| --- | --- | --- |
| `0x0061b650` | `0x006486d4` | `??_R4ImageLib@@6B@` complete-object locator. |
| `0x0061b654` | `0x004e64a0` | `ImageLib` scalar deleting destructor, function range `0x004e64a0-0x004e6572`. |
| `0x0061b658` | `0x004f4b10` | inherited/shared virtual slot, function range `0x004f4b10-0x004f4b16`. |
| `0x0061b65c` | `0x0041b6c0` | `nullsub_18`, function range `0x0041b6c0-0x0041b6c3`. |
| `0x0061b660` | `0x00648774` | `MapTileImageLib` RTTI locator and exact successor boundary. |
| `0x0061b664` | `0x004e66a0` | first `MapTileImageLib` slot, not part of this `ImageLib` vtable. |
| `0x0061b670` | `0x006488b4` | following `ProtectedArray<HeadInfo>` RTTI locator. |

The recheck also reconfirmed `0x0061b654` vptr-store/reset xrefs from `0x004cffb0`, `0x004d0070`, and `0x004e64a0`. The `0x0061b660` successor remains the exact boundary for this page; the adjacent `MapTileImageLib` type/memory pages own the next table rather than this `ImageLib` vtable page.

## 2026-06-16 C001 IDA Label Sync

C001 live IDA refresh for [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md) saved the descriptive labels `ImageLib_vftable` at `0x0061b654` and `ImageLib_ScalarDeletingDestructor` at `0x004e64a0`. Post-save `lookup_funcs` and `entity_query` confirmed the labels and the unchanged `0xd2` scalar deleting destructor body. No slot type, prototype, or class-layout mutation was made because the inherited/shared `0x004f4b10` slot and `ImageLib`/`ResourceLayoutTable` API split remain unresolved.

## 2026-06-27 Destructor Source Route

B006 MCP session `80de0a67` preserves the vtable slot as `0x0061b654 -> 0x004e64a0`. The ordinary destructor [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) now carries source `ImageLib::~ImageLib()` C++, but it is not a vtable pointer target: `find_bytes` found no VA or RVA pointer route to `0x004d0070`, while the positive control found the scalar-wrapper pointer at `0x0061b654`. This is the expected MSVC destructor split, so do not rewrite slot `+0x00` to point at the ordinary destructor.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page records current slot dwords, target function ranges, constructor/destructor/scalar-delete vptr-store xrefs, exact backing child, direct parent gate, the three-level successor boundary through `MapTileImageLib` and `ProtectedArray<HeadInfo>`, and the formal no-standalone-vtable marker with child route. |
| Confidence | 93 | Live IDA strongly supports the vtable range, ownership, bytes, and source-declared/generated-binary disposition. Confidence remains below final-audit quality because the inherited/shared slot name and full `ResourceLayoutTable`/`ImageLib` API split are still unresolved. |

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `ImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

This page emits only the accepted no-standalone-vtable marker plus `[[CHILDREN]]`. Source declarations and method bodies belong on the owning class/file and exact `by-memory` pages; the concrete vtable dwords remain compiler-emitted from those declarations.

## Cross-References

- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation:
  - Changed score from `87/92` to `88/93` and inserted the formal no-standalone-vtable marker with `[[CHILDREN]]`.
  - Summary/evidence: current IDA bytes and xrefs prove the vtable route, but this is source-declared/generated-binary data. The marker routes exact slot data to [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md) and keeps source bodies on class/memory children.
- 2026-06-27 B006 destructor source-quality implementation: no score change. Added the source-route note that [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) owns source C++ while slot `+0x00` remains `0x0061b654 -> 0x004e64a0` for [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md). MCP session `80de0a67` supplies no-pointer-route proof for `0x004d0070` and positive scalar pointer proof.
- 2026-06-08 A007 Batch 139 gate update:
  - What existed before: the vtable page was `82/90`, had no autogen parent, and pointed only to the mixed Hour/Icons/Idle read-only aggregate.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, `AUTOGEN_PARENT_UID:00006E`, and an exact backing child link to [UID:00031R][0x0061b650-0x0061b660.ImageLibVtableData](by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md).
  - Summary/evidence: Batch 139 exact child evidence records the RTTI/vtable dwords, target sizes, xrefs, and neighboring `MapTileImageLib` boundary; [UID:00006E][ImageLib](by-class/ImageLib.md) was refreshed to `86/86`, satisfying the strict child-and-direct-parent gate.
- 2026-06-11 A005 Batch 174: Raised from `86/91` to `87/92` after live IDA MCP reconfirmed the RTTI locator, three slot dwords, slot target function ranges, vptr-store/reset xrefs, `MapTileImageLib` successor locator at `0x0061b660`, first successor slot at `0x0061b664`, and `ProtectedArray<HeadInfo>` boundary at `0x0061b670`. Final confidence remains below `95` because the inherited/shared slot name and `ResourceLayoutTable` relationship are still provisional.
- 2026-06-16 C001 IDA label sync: Score unchanged at `87/92`. C001 saved `off_61B654 -> ImageLib_vftable` and `sub_4E64A0 -> ImageLib_ScalarDeletingDestructor` during the ImageLib lifecycle refresh; no prototype, slot type, or layout edit was made.
- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, and the next `MapTileImageLib` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding ImageLib method dependencies are not final-audited.
