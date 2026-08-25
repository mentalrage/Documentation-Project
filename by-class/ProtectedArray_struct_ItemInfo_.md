*** UID:0000B8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete ProtectedArray<ItemInfo> template instantiation.
// Reusable source cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md).
// Embedded record use remains with [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) ItemObjImageLib; do not emit a standalone original source class here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_ItemInfo_

## Status

- Confidence: very strong for binary identity, destructor/vtable evidence, template routing, and concrete embedder; medium for final original template/header spelling and source record declaration names.
- Source-level name: `ProtectedArray<ItemInfo>`
- Source-level owner/emitter: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) reusable template support.
- Concrete embedder: [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), with `ProtectedArray<ItemInfo> m_itemInfos` at `ItemObjImageLib +0x04` and inline default [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) entry at object `+0x14` in [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md).
- Current generated output: 2026-06-16 `rg --files` found no active `source-3/simroot_v2/class_ProtectedArray_struct_ItemInfo_.cpp`; the only non-doc matches were Wave2 JSON metadata, which this pass did not use as authoritative source evidence.
- Memory documentation: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete item record parsing and icon draw policy owned by [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
- Final C++ remains blank because the exact `ProtectedArray<T>` declaration/header basename, final `ItemInfo` source declaration, and concrete member declaration wording are not source-quality yet.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5b10` | ordinary destructor | 16-byte interior body; resets the `ProtectedArray<ItemInfo>` vtable and frees backing storage. |
| `0x004e6180` | scalar deleting destructor | Standalone `0x2f` / 47-byte deleting body; ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

`ItemObjImageLib` owns item record parsing, fallback row semantics, and icon draw policy. This page records only the shared `ProtectedArray<T>` instantiation artifacts, so [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) remains the canonical owner/emitter. B008 2026-06-19 class-layout reanalysis clarifies that `ItemObjImageLib +0x14` is this protected array's inline `ItemInfo` default entry at suboffset `+0x10`, not a separate class-owned top-level fallback field.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<ItemInfo>` at ordinary destructor `0x004e5b10` and deleting destructor `0x004e6180`. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) identifies `0x004e5b10-0x004e5b1f` as the exact ordinary destructor body, and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) identifies `0x004e6180-0x004e61af` as the exact deleting destructor body. [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md) records the `ProtectedArray<ItemInfo>` RTTI/vtable at `0x0061b730-0x0061b734` immediately before the [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md) child range.

2026-06-16 A001 live IDA MCP refresh used active database `b001_mappane_0001AW_20260616` for read-only `NexusTK.exe`. `lookup_funcs` resolves `0x004e5b10` inside `ItemObjImageLibConstructor` (`0x1eb` bytes), confirms standalone `sub_4E6180` at `0x004e6180` (`0x2f` bytes), and confirms the ordinary destructor start `0x004dee20` is still not modeled as a function. `xrefs_to` reports the ordinary-destructor cleanup/unwind ref at `0x00600163`, the deleting-destructor vtable data ref from `0x0061b734`, and five vtable-operand refs from constructor embed `0x004dec92`, ordinary destructor cleanup `0x004dee2c`, ordinary reset `0x004e5b13`, deleting reset `0x004e6189`, and `ItemObjImageLib` scalar deleting cleanup `0x004e658f`.

The same pass decompiled `0x004e6180` and confirmed the scalar deleting shape: read/free `Block[2]`, write `ProtectedArray<ItemInfo>::vftable`, test delete flag bit `1`, optionally call the delete helper, and return `this`. Decompilation of `ItemObjImageLibConstructor` reconfirmed constructor writes to `+0x04`, `+0x08`, `+0x0c`, and `+0x10`, fallback row initialization at `+0x14`, and row allocation/copy as `20 * count` (`0x14` byte records). A read-only section-mapped PE scan found no absolute/RVA pointers to the ordinary destructor, one `.text` rel32 jump at `0x00600163`, one absolute vtable-slot pointer to the deleting destructor at `0x0061b734`, no rel32 calls/jumps to `0x004e6180`, and the five absolute vtable-operand pointer locations `0x004dec94`, `0x004dee2f`, `0x004e5b15`, `0x004e618b`, and `0x004e6592`. Byte reads also show the deleting body uses delete-size immediate `0x24`.

Blockers checked: IDA `search_structs` returned no local records for `ProtectedArray`, `ItemInfo`, or `ItemObjImageLib`, and generated-file search found no active `simroot_v2` C++ file for this instantiation. Current IDA/docs/PE evidence proves the binary artifact and owner route, but not the original template declaration spelling, header basename, final `ItemInfo` field names, or final ItemObjImageLib member declaration text.

## Score Rationale

Completion is `87` because the page now records exact ordinary/deleting destructor identity, standalone versus interior-body modeling, vtable slot and xrefs, PE reachability, concrete ItemObjImageLib embedding, template ownership, investigated generated-output/source-placement blockers, and a formal no-code instantiation comment. Confidence is `91` because IDA, existing support docs, bytes, decompilation, PE scanning, and the corrected no-code disposition all agree on the binary identity and owner/emitter route. It stays below final-audit quality because original source declarations and header/source placement remain unresolved.

## Cross-References

- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md)
- [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md)

## Changes

- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `86/90` to `87/91`.
  - Added the formal no-code `ProtectedArray<ItemInfo>` instantiation comment using corrected embedder [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
  - Summary/evidence: reusable cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage by [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); this page remains a concrete generated template instantiation, not a standalone original source class. The stale UID 0000KA / InventoryPane embedder value is rejected for this row.

- 2026-06-16 A001 Goal 2 ProtectedArray instantiation refresh:
  - Before: completion/confidence were `82/88`, with stale active-generated-file wording and only summarized destructor/vtable evidence.
  - After: completion/confidence are `86/90`, owner/emitter remain [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), and final C++ remains blank.
  - Evidence: live IDA MCP reconfirmed the ordinary destructor interior body, scalar deleting destructor, vtable slot, constructor/destructor/scalar-deleting vtable refs, and no local IDA struct records; PE scanning reconfirmed absolute/rel32 reachability and no direct calls to the deleting destructor; support docs prove the `ItemObjImageLib +0x04` embedder route and `0x14` byte `ItemInfo` record; generated-file search found no active `simroot_v2` C++ file for this instantiation.
- 2026-06-19 B008 ItemObjImageLib layout sync:
  - No score change. Added the explicit cross-note that `ItemObjImageLib +0x14` is `ProtectedArray<ItemInfo>::m_defaultEntry`, not a separate class field.

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `70`, confidence was `86`, and `AUTOGEN_PARENT_UID` was blank because parent attachment had been deferred under the 80/80 gate.
  - After: completion is `82`, confidence is `88`, and `AUTOGEN_PARENT_UID` is [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact destructor memory-page evidence, the ItemObjImageLib adjacent vtable evidence, and the autogen handling note that keeps this as shared template support rather than a standalone source file. Final C++ remained blank because source-quality template/source-placement details were unresolved; the 2026-06-16 refresh supersedes the older generated-file wording.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The class was still unclassified in autogen coverage even though the page identified `ProtectedArray<ItemInfo>` as NexusTK-owned template support embedded by `ItemObjImageLib`.
  - After: The concrete template instantiation was reconstructable but left unassigned at that time; this was superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
  - Evidence: Live IDA MCP lookup confirms the ordinary cleanup entry at `0x004e5b10` and deleting destructor at `0x004e6180`; linked template and memory docs identify the shared `ProtectedArray<T>` rebuild requirement.

- 2026-05-30: Changed completion/confidence from `0/0` to `70/86`.
  - Before: The page was unevaluated though it already identified the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<ItemInfo>` instantiation.
  - Evidence: Existing source-level owner, method table, and memory/template cross-references document the artifact identity and ItemObjImageLib ownership.
