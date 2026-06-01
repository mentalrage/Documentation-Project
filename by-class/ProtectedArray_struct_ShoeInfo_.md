*** UID:0000BC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5b50` | ordinary destructor | Resets `ProtectedArray<ShoeInfo>` vtable and frees backing storage. |
| `0x004e6240` | scalar deleting destructor | Ordinary cleanup plus conditional `operator delete`; generated marker is currently split across lines. |

## Ownership Notes

This is old human shoe metadata support, not an independent original class source file. The active generated file has broken `NTK_ScopedInstall` marker comments for both methods, so use the memory docs and IDA evidence for method identity.

## Cross-References

- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `68/82`.
  - Before: The page was unevaluated despite identifying the concrete template instance and destructor slots.
  - After: Scored as adequate completion and strong confidence, slightly below sibling artifacts because the active generated file has broken marker comments.
  - Evidence: Existing method table, ownership notes, and memory/template cross-references document the artifact identity and explain the generated-marker caveat.
