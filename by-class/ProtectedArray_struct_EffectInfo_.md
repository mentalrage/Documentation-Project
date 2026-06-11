*** UID:0000B1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_EffectInfo_

## Status

- Confidence: strong that this is a generated template instantiation artifact.
- Source-level name: `ProtectedArray<EffectInfo>`
- Source-level owner: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) template support, embedded by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Current generated file: `source-3/simroot_v2/class_ProtectedArray_struct_EffectInfo_.cpp`
- Memory documentation: [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- Rebuild handling: source-declared/generated-binary template support; parented to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), with concrete effect record loading owned by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Autogen parent: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); C++ remains blank because the final template declaration and all owner integrations are below the `95/95` reconstruction-code gate.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5ab0` | ordinary destructor | Resets `ProtectedArray<EffectInfo>` vtable and frees backing storage. |
| `0x004e6060` | scalar deleting destructor | Ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

`EffectObjImageLib` owns the effect descriptor load/lookup behavior. This page records only the shared template instantiation.

## Evidence Notes

[UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records `ProtectedArray<EffectInfo>` at ordinary destructor `0x004e5ab0` and deleting destructor `0x004e6060`. [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md) identifies `0x004e5ab0-0x004e5abf` as the exact ordinary destructor body, and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md) identifies `0x004e6060-0x004e608f` as the exact deleting destructor body. [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md) and [UID:00025I][0x0061b664-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c360.ImageLibraryReadOnlyData.md) record the adjacent effect `ProtectedArray` vtables before the `EffectObjImageLib` class vtable.

## Cross-References

- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:00025I][0x0061b664-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c360.ImageLibraryReadOnlyData.md)

## Changes

- 2026-06-06: Raised completion/confidence and attached the instantiation to `ProtectedArray`.
  - Before: completion was `70`, confidence was `86`, and `AUTOGEN_PARENT_UID` was blank because parent attachment had been deferred under the 80/80 gate.
  - After: completion is `82`, confidence is `88`, and `AUTOGEN_PARENT_UID` is [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Evidence: added exact destructor memory-page evidence, the EffectObjImageLib adjacent vtable evidence, and the autogen handling note that keeps this as shared template support rather than a standalone source file. C++ remains blank under the `95/95` final-source gate.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: reconstruction autogen classification was blank for a documented custom `ProtectedArray<EffectInfo>` instantiation.
  - After: classified as reconstructable source-facing template/declaration evidence, not as a standalone original `.cpp` file.
  - Evidence: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) is already `RECONSTRUCTABLE:TRUE`, and this page ties `ProtectedArray<EffectInfo>` to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Live IDA MCP lookup confirms deleting destructor `0x004e6060` and resolves ordinary destructor address `0x004e5ab0` inside the documented effect image-library constructor/destructor region. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `70/86`.
  - Before: The page was unevaluated though it already identified the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<EffectInfo>` instantiation.
  - Evidence: Existing source-level owner, method table, and memory/template cross-references document the artifact identity and EffectObjImageLib ownership.
