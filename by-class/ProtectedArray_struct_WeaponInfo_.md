*** UID:0000BD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete ProtectedArray<WeaponInfo> template instantiation.
// Reusable source cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md).
// Embedded record use remains with [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) HumanImageLib; do not emit a standalone original source class here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_WeaponInfo_

## Status

- Confidence: very strong for binary identity, destructor/vtable evidence, template routing, and concrete embedder; medium for final original template/header spelling and source record declaration names.
- Source-level name: `ProtectedArray<WeaponInfo>`
- Source-level owner/emitter: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) reusable template support.
- Concrete embedder: [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), with `ProtectedArray<WeaponInfo> weaponArray0..weaponArray5` at `HumanImageLib +0x080`, `+0x0a0`, `+0x0c0`, `+0x0e0`, `+0x100`, and `+0x120` in [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).
- Current generated output: 2026-06-16 `rg --files` found no active `source-3/simroot_v2/class_ProtectedArray_struct_WeaponInfo_.cpp`; the only non-doc matches were Wave2 JSON metadata, which this pass did not use as authoritative source evidence.
- Memory documentation: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete old-human record loading owned by [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
- Final C++ remains blank because the exact `ProtectedArray<T>` declaration/header basename, final `WeaponInfo` source declaration, six weapon-family member names/order, and concrete member declaration wording are not source-quality yet.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5b60` | ordinary destructor | 16-byte interior body (Verified with int_convert.py); resets the `ProtectedArray<WeaponInfo>` vtable and frees backing storage. |
| `0x004e6270` | scalar deleting destructor | Standalone `0x2f` / 47-byte deleting body (Verified with int_convert.py); ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

This is old-human weapon/equipment metadata support, not an independent original class source file. The reusable destructor/vtable artifacts belong to the [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) template route. [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) remains the concrete owner for table loading and the six embedded `WeaponInfo` arrays.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<WeaponInfo>` at ordinary destructor `0x004e5b60` and deleting destructor `0x004e6270`. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) identifies `0x004e5b60-0x004e5b6f` as the exact ordinary destructor body, and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) identifies `0x004e6270-0x004e629f` as the exact deleting destructor body. [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) records the `ProtectedArray<WeaponInfo>` vtable at `0x0061b68c` with slot target `0x004e6270`.

2026-06-16 A001 live IDA MCP refresh used active database `b001_mappane_0001AW_20260616` for read-only `NexusTK.exe`. `lookup_funcs` resolves `0x004e5b60` inside broad `sub_4D2720` (`0x23aa` / 9130 bytes, Verified with int_convert.py), confirms standalone `sub_4E6270` at `0x004e6270` (`0x2f` / 47 bytes, Verified with int_convert.py), and reconfirms the HumanImageLib constructor/destructor anchors `0x004d2720` and `0x004d4ad0`. `xrefs_to` reports six ordinary-destructor cleanup/unwind refs at `0x005ffb3b`, `0x005ffb4c`, `0x005ffb5d`, `0x005ffb6e`, `0x005ffb7f`, and `0x005ffb90`; the deleting-destructor vtable data ref from `0x0061b68c`; and fourteen vtable-operand refs covering constructor embeds `0x004d2801`, `0x004d2829`, `0x004d2851`, `0x004d2879`, `0x004d28a1`, `0x004d28c9`, destructor cleanup `0x004d4e8a`, `0x004d4e9f`, `0x004d4eb4`, `0x004d4ec9`, `0x004d4ede`, `0x004d4ef3`, ordinary reset `0x004e5b63`, and deleting reset `0x004e6279`.

The same pass decompiled `0x004e6270` and confirmed the scalar deleting shape: read/free `Block[2]`, write `ProtectedArray<WeaponInfo>::vftable`, test delete flag bit `1`, optionally call the delete helper, and return `this`. A read-only section-mapped PE scan found no absolute/RVA pointers to the ordinary destructor, six `.text` rel32 jumps at the same cleanup/unwind addresses, one absolute vtable-slot pointer to the deleting destructor at `0x0061b68c`, no rel32 calls/jumps to `0x004e6270`, and fourteen absolute vtable-operand pointer locations `0x004d2807`, `0x004d282f`, `0x004d2857`, `0x004d287f`, `0x004d28a7`, `0x004d28cf`, `0x004d4e90`, `0x004d4ea5`, `0x004d4eba`, `0x004d4ecf`, `0x004d4ee4`, `0x004d4ef9`, `0x004e5b65`, and `0x004e627b`. Byte reads also show the deleting body uses delete-size immediate `0x20` / 32 bytes (Verified with int_convert.py).

Blockers checked: IDA `search_structs` returned no local records for `ProtectedArray`, `WeaponInfo`, or `HumanImageLib`, and generated-file search found no active `simroot_v2` C++ file for this instantiation. Current IDA/docs/PE evidence proves the binary artifact and owner route, but not the original template declaration spelling, header basename, final `WeaponInfo` declaration, final six weapon-family member names/order, or final HumanImageLib member declaration text.

## Score Rationale

Completion is `87` because the page now records exact ordinary/deleting destructor identity, standalone versus interior-body modeling, vtable slot and xrefs, PE reachability, concrete six-array HumanImageLib embedding, template ownership, investigated generated-output/source-placement blockers, and a formal no-code instantiation comment. Confidence is `91` because IDA, existing support docs, bytes, decompilation, PE scanning, and the corrected no-code disposition all agree on the binary identity and owner/emitter route. It stays below final-audit quality because original source declarations, six weapon-family field names/order, and header/source placement remain unresolved.

## Cross-References

- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)

## Changes

- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `86/90` to `87/91`.
  - Added the formal no-code `ProtectedArray<WeaponInfo>` instantiation comment using corrected embedder [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
  - Summary/evidence: reusable cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage by [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); this page remains a concrete generated template instantiation, not a standalone original source class.

- 2026-06-16 A001 Goal 2 ProtectedArray instantiation refresh:
  - Before: completion/confidence were `82/88`, with stale active-generated-file wording and only summarized destructor/vtable evidence.
  - After: completion/confidence are `86/90`, owner/emitter remain [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), and final C++ remains blank.
  - Evidence: live IDA MCP reconfirmed the ordinary destructor interior body, scalar deleting destructor, vtable slot, six constructor/destructor embedder groups, and no local IDA struct records; PE scanning reconfirmed absolute/rel32 reachability and no direct calls to the deleting destructor; support docs prove the six `HumanImageLib +0x080..+0x120` embedder routes; generated-file search found no active `simroot_v2` C++ file for this instantiation.

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `70`, confidence was `86`, and `AUTOGEN_PARENT_UID` was blank because parent attachment had been deferred under the 80/80 gate.
  - After: completion is `82`, confidence is `88`, and `AUTOGEN_PARENT_UID` is [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact destructor memory-page evidence, the old-human vtable address, and the autogen handling note that keeps this as shared template support rather than a standalone source file. Final C++ remained blank because source-quality template/source-placement details were unresolved; the 2026-06-16 refresh supersedes the older generated-file wording.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The class was still unclassified in autogen coverage even though the page identified `ProtectedArray<WeaponInfo>` as NexusTK-owned template support embedded by `HumanImageLib`.
  - After: The concrete template instantiation was reconstructable but left unassigned at that time; this was superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
  - Evidence: Live IDA MCP lookup confirms the ordinary cleanup entry at `0x004e5b60` and deleting destructor at `0x004e6270`; linked template and memory docs identify the shared `ProtectedArray<T>` rebuild requirement.

- 2026-05-30: Changed completion/confidence from `0/0` to `70/86`.
  - Before: The page was unevaluated though it already identified the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<WeaponInfo>` instantiation.
  - Evidence: Existing source-level owner, method table, and memory/template cross-references document the artifact identity and ownership.
