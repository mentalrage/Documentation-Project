*** UID:0000B0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete ProtectedArray<CoatInfo> template instantiation.
// Reusable source cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md).
// Embedded record use remains with [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) HumanImageLib; do not emit a standalone original source class here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_CoatInfo_

## Status

- Confidence: very strong for binary identity, destructor/vtable evidence, template routing, and concrete embedder; medium for final original template/header spelling and source record declaration names.
- Source-level name: `ProtectedArray<CoatInfo>`
- Source-level owner/emitter: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) reusable template support.
- Concrete embedder: [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), with `ProtectedArray<CoatInfo> coatArray` at `HumanImageLib +0x05c` in [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md).
- Current generated output: 2026-06-16 `rg --files` found no active `source-3/simroot_v2/class_ProtectedArray_struct_CoatInfo_.cpp`; the only non-doc matches were Wave2 JSON metadata, which this pass did not use as authoritative source evidence.
- Memory documentation: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete old-human record loading owned by [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
- Final C++ remains blank because the exact `ProtectedArray<T>` declaration/header basename, final `CoatInfo` source declaration, and concrete member declaration wording are not source-quality yet.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5aa0` | ordinary destructor | 16-byte interior body; resets the `ProtectedArray<CoatInfo>` vtable and frees backing storage. |
| `0x004e6030` | scalar deleting destructor | Standalone `0x2f` / 47-byte deleting body; ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

This is old-human equipment metadata support, not an independent original class source file. The reusable destructor/vtable artifacts belong to the [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) template route. [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) remains the concrete owner for table loading and the embedded `coatArray` member.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<CoatInfo>` at ordinary destructor `0x004e5aa0` and deleting destructor `0x004e6030`. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) identifies `0x004e5aa0-0x004e5aaf` as the exact ordinary destructor body, and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) identifies `0x004e6030-0x004e605f` as the exact deleting destructor body. [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md) records the `ProtectedArray<CoatInfo>` vtable at `0x0061b684` with slot target `0x004e6030`.

2026-06-16 A001 live IDA MCP refresh used active database `b001_mappane_0001AW_20260616` for read-only `NexusTK.exe`. `lookup_funcs` resolves `0x004e5aa0` inside broad `sub_4D2720` (`0x23aa` bytes), confirms standalone `sub_4E6030` at `0x004e6030` (`0x2f` bytes), and reconfirms the HumanImageLib constructor/destructor anchors `0x004d2720` and `0x004d4ad0`. `xrefs_to` reports the ordinary-destructor cleanup/unwind ref at `0x005ffb2a`, the deleting-destructor vtable data ref from `0x0061b684`, and four vtable-operand refs from constructor embed `0x004d27e5`, destructor cleanup `0x004d4f05`, ordinary reset `0x004e5aa3`, and deleting reset `0x004e6039`.

The same pass decompiled `0x004e6030` and confirmed the scalar deleting shape: read/free `Block[2]`, write `ProtectedArray<CoatInfo>::vftable`, test delete flag bit `1`, optionally call the delete helper, and return `this`. A read-only section-mapped PE scan found no absolute/RVA pointers to the ordinary destructor, one `.text` rel32 jump at `0x005ffb2a`, one absolute vtable-slot pointer to the deleting destructor at `0x0061b684`, no rel32 calls/jumps to `0x004e6030`, and the four absolute vtable-operand pointer locations `0x004d27e8`, `0x004d4f08`, `0x004e5aa5`, and `0x004e603b`. Byte reads also show the deleting body uses delete-size immediate `0x24`.

Blockers checked: IDA `search_structs` returned no local records for `ProtectedArray`, `CoatInfo`, or `HumanImageLib`, and generated-file search found no active `simroot_v2` C++ file for this instantiation. Current IDA/docs/PE evidence proves the binary artifact and owner route, but not the original template declaration spelling, header basename, final `CoatInfo` declaration, or final HumanImageLib member declaration text.

## Score Rationale

Completion is `87` because the page now records exact ordinary/deleting destructor identity, standalone versus interior-body modeling, vtable slot and xrefs, PE reachability, concrete HumanImageLib embedding, template ownership, investigated generated-output/source-placement blockers, and a formal no-code instantiation comment. Confidence is `91` because IDA, existing support docs, bytes, decompilation, PE scanning, and the corrected no-code disposition all agree on the binary identity and owner/emitter route. It stays below final-audit quality because original source declarations and header/source placement remain unresolved.

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
  - Added the formal no-code `ProtectedArray<CoatInfo>` instantiation comment using corrected embedder [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md).
  - Summary/evidence: reusable cleanup is represented by [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) and compiler-wrapper coverage by [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md); this page remains a concrete generated template instantiation, not a standalone original source class.

- 2026-06-16 A001 Goal 2 ProtectedArray instantiation refresh:
  - Before: completion/confidence were `82/88`, with stale active-generated-file wording and only summarized destructor/vtable evidence.
  - After: completion/confidence are `86/90`, owner/emitter remain [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), and final C++ remains blank.
  - Evidence: live IDA MCP reconfirmed the ordinary destructor interior body, scalar deleting destructor, vtable slot, constructor/destructor vtable refs, and no local IDA struct records; PE scanning reconfirmed absolute/rel32 reachability and no direct calls to the deleting destructor; support docs prove the `HumanImageLib +0x05c` embedder route; generated-file search found no active `simroot_v2` C++ file for this instantiation.

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `70`, confidence was `86`, and `AUTOGEN_PARENT_UID` was blank because parent attachment had been deferred under the 80/80 gate.
  - After: completion is `82`, confidence is `88`, and `AUTOGEN_PARENT_UID` is [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact destructor memory-page evidence, the old-human vtable address, and the autogen handling note that keeps this as shared template support rather than a standalone source file. Final C++ remained blank because source-quality template/source-placement details were unresolved; the 2026-06-16 refresh supersedes the older generated-file wording.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: reconstruction autogen classification was blank for a documented custom `ProtectedArray<CoatInfo>` instantiation.
  - After: classified as reconstructable source-facing template/declaration evidence, not as a standalone original `.cpp` file.
  - Evidence: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) is already `RECONSTRUCTABLE:TRUE`, and this page ties `ProtectedArray<CoatInfo>` to [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md). Live IDA MCP lookup confirms deleting destructor `0x004e6030` and resolves ordinary destructor address `0x004e5aa0` inside the documented old-human image-library destructor island. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `70/86`.
  - Before: The page was unevaluated though it already identified the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<CoatInfo>` instantiation.
  - Evidence: Existing source-level owner, method table, and memory/template cross-references document the artifact identity and ownership.
