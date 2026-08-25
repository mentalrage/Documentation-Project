*** UID:0000B2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete ProtectedArray<EffectPixMapInfo> template instantiation.
// Reusable source cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md).
// Embedded record use remains with [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) EffectObjImageLib; do not emit a standalone original source class here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_EffectPixMapInfo_

## Status

- Confidence: very strong for binary identity, destructor/vtable evidence, template routing, and concrete embedder; medium for final original template/header spelling and source record declaration names.
- Source-level name: `ProtectedArray<EffectPixMapInfo>`
- Source-level owner/emitter: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) reusable template support.
- Concrete embedder: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), with `ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray` at `EffectObjImageLib +0x48` and fallback [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md) at `+0x58` in [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md).
- Current generated output: 2026-06-16 `rg --files` found no active `source-3/simroot_v2/class_ProtectedArray_struct_EffectPixMapInfo_.cpp`; the only non-doc matches were Wave2 JSON metadata, which this pass did not use as authoritative source evidence.
- Memory documentation: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete effect pixmap record loading owned by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Final C++ remains blank because the exact `ProtectedArray<T>` declaration/header basename, final `EffectPixMapInfo` typedef/record spelling, and concrete member declaration wording are not source-quality yet.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5ac0` | ordinary destructor | 16-byte interior body; resets the `ProtectedArray<EffectPixMapInfo>` vtable and frees backing storage. |
| `0x004e6090` | scalar deleting destructor | Standalone `0x2f` / 47-byte deleting body; ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

`EffectObjImageLib` owns the `EFFECT.FRM` frame-remap table logic and the four-byte remap entry declaration. This page records only the shared `ProtectedArray<T>` instantiation artifacts, so [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) remains the canonical owner/emitter.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<EffectPixMapInfo>` at ordinary destructor `0x004e5ac0` and deleting destructor `0x004e6090`. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) identifies `0x004e5ac0-0x004e5acf` as the exact ordinary destructor body, and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) identifies `0x004e6090-0x004e60bf` as the exact deleting destructor body. [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md) and [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md) record the adjacent effect `ProtectedArray` vtables before the `EffectObjImageLib` class vtable.

2026-06-16 A001 live IDA MCP refresh used active database `b001_mappane_0001AW_20260616` for read-only `NexusTK.exe`. `lookup_funcs` resolves `0x004e5ac0` inside broad `sub_4DDF60` (`0xee` bytes), confirms standalone `sub_4E6090` at `0x004e6090` (`0x2f` bytes), and reconfirms the `EffectObjImageLib` constructor/destructor anchors `0x004ddf60` and `0x004de050`. `xrefs_to` reports the ordinary-destructor cleanup/unwind ref at `0x006000a0`, the deleting-destructor vtable data ref from `0x0061b71c`, and five vtable-operand refs from constructor embed `0x004ddfd9`, ordinary destructor cleanup `0x004de149`, ordinary reset `0x004e5ac3`, deleting reset `0x004e6099`, and `EffectObjImageLib` scalar deleting cleanup `0x004e63f0`.

The same pass decompiled `0x004e6090` and confirmed the scalar deleting shape: read/free `Block[2]`, write `ProtectedArray<EffectPixMapInfo>::vftable`, test delete flag bit `1`, optionally call the delete helper, and return `this`. Decompilation of `0x004ddf60` and `0x004de050` reconfirmed constructor/destructor writes to `this[18]` (`+0x48`) and remap cleanup through `this[20]` (`+0x50`). A read-only section-mapped PE scan found no absolute/RVA pointers to the ordinary destructor, one `.text` rel32 jump at `0x006000a0`, one absolute vtable-slot pointer to the deleting destructor at `0x0061b71c`, no rel32 calls/jumps to `0x004e6090`, and the five absolute vtable-operand pointer locations `0x004ddfdc`, `0x004de14c`, `0x004e5ac5`, `0x004e609b`, and `0x004e63f3`. Byte reads also show the deleting body uses delete-size immediate `0x14`, matching a `0x10` ProtectedArray header plus a four-byte fallback element.

Blockers checked: IDA `search_structs` returned no local records for `ProtectedArray`, `EffectPixMapInfo`, or `EffectObjImageLib`, and generated-file search found no active `simroot_v2` C++ file for this instantiation. Current IDA/docs/PE evidence proves the binary artifact and owner route, but not the original template declaration spelling, header basename, final typedef-versus-record spelling for `EffectPixMapInfo`, or final EffectObjImageLib member declaration text.

## Score Rationale

Completion is `87` because the page now records exact ordinary/deleting destructor identity, standalone versus interior-body modeling, vtable slot and xrefs, PE reachability, concrete EffectObjImageLib embedding, template ownership, investigated generated-output/source-placement blockers, and a formal no-code instantiation comment. Confidence is `91` because IDA, existing support docs, bytes, decompilation, PE scanning, and the corrected no-code disposition all agree on the binary identity and owner/emitter route. It stays below final-audit quality because original source declarations and header/source placement remain unresolved.

## Cross-References

- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md)

## Changes

- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `86/90` to `87/91`.
  - Added the formal no-code `ProtectedArray<EffectPixMapInfo>` instantiation comment using corrected embedder [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: reusable cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage by [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); this page remains a concrete generated template instantiation, not a standalone original source class. The stale UID 0000JD / FileIO embedder value is rejected for this row.

- 2026-06-16 A001 Goal 2 ProtectedArray instantiation refresh:
  - Before: completion/confidence were `82/88`, with stale active-generated-file wording and only summarized destructor/vtable evidence.
  - After: completion/confidence are `86/90`, owner/emitter remain [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), and final C++ remains blank.
  - Evidence: live IDA MCP reconfirmed the ordinary destructor interior body, scalar deleting destructor, vtable slot, constructor/destructor/scalar-deleting vtable refs, and no local IDA struct records; PE scanning reconfirmed absolute/rel32 reachability and no direct calls to the deleting destructor; support docs prove the `EffectObjImageLib +0x48` embedder route and four-byte `EffectPixMapInfo` record; generated-file search found no active `simroot_v2` C++ file for this instantiation.

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `70`, confidence was `86`, and `AUTOGEN_PARENT_UID` was blank because parent attachment had been deferred under the 80/80 gate.
  - After: completion is `82`, confidence is `88`, and `AUTOGEN_PARENT_UID` is [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact destructor memory-page evidence, the EffectObjImageLib adjacent vtable evidence, and the autogen handling note that keeps this as shared template support rather than a standalone source file. Final C++ remained blank because source-quality template/source-placement details were unresolved; the 2026-06-16 refresh supersedes the older generated-file wording.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: reconstruction autogen classification was blank for a documented custom `ProtectedArray<EffectPixMapInfo>` instantiation.
  - After: classified as reconstructable source-facing template/declaration evidence, not as a standalone original `.cpp` file.
  - Evidence: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) is already `RECONSTRUCTABLE:TRUE`, and this page ties `ProtectedArray<EffectPixMapInfo>` to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Live IDA MCP lookup confirms deleting destructor `0x004e6090` and resolves ordinary destructor address `0x004e5ac0` inside the documented effect image-library constructor/destructor region. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `70/86`.
  - Before: The page was unevaluated though it already identified the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<EffectPixMapInfo>` instantiation.
  - Evidence: Existing source-level owner, method table, and memory/template cross-references document the artifact identity and EffectObjImageLib ownership.
