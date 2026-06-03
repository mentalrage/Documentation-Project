*** UID:0000BC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_ShoeInfo_

## Status

- Confidence: strong that this is a generated template instantiation artifact.
- Source-level name: `ProtectedArray<ShoeInfo>`
- Source-level owner: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) template support, embedded by [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- Current generated file: `source-3/simroot_v2/class_ProtectedArray_struct_ShoeInfo_.cpp`
- Rebuild handling: source-declared/generated-binary; the reusable template belongs under [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), while [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) owns the old-human `shoeArray` field and table loading.
- Autogen parent: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); C++ remains blank because final template declaration spelling and all owner integrations are below the `95/95` reconstruction-code gate.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5b50` | ordinary destructor | Resets `ProtectedArray<ShoeInfo>` vtable and frees backing storage; current generated output still omits the body. |
| `0x004e6240` | scalar deleting destructor | Ordinary cleanup plus conditional `operator delete`; IDA models this as a compact `0x2f`-byte function. |

## Ownership Notes

This is old human shoe metadata support, not an independent original class source file. The active generated file still omits the ordinary destructor body at `0x004e5b50`, so use the memory docs and IDA evidence for exact method identity.

The generated `ShoeInfo` instantiation is concrete evidence for the old-human image-library field at `HumanImageLib +0x220`, but the original reusable implementation should remain with [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md). [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) records both `0x004e5b50` and `0x004e6240`, and [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md) derives a `0x10` byte `ShoeInfo` fallback record from the scalar deleting destructor size.

## Cross-References

- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)

## Changes

- 2026-06-03 parent attachment and generated-caveat update:
  - Before: scored `68/82` with blank reconstructable and parent metadata.
  - After: scored `74/86`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md).
  - Summary/evidence: `ProtectedArray` now has a utility path and parent-link confidence, the template page lists `ProtectedArray<ShoeInfo>` at `0x004e5b50`/`0x004e6240`, the layout page records the `ShoeInfo` fallback size, and `HumanImageLib` owns the embedded concrete field. No C++ was added because this remains compiler-emitted template support below the final-source gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `68/82`.
  - Before: The page was unevaluated despite identifying the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence, slightly below sibling artifacts because the active generated file has broken marker comments.
  - Evidence: Existing method table, ownership notes, and memory/template cross-references document the artifact identity and explain the generated-marker caveat.
