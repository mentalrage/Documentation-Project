*** UID:0000B5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_HairInfo_

## Status

- Confidence: strong that this is a generated template instantiation artifact.
- Source-level name: `ProtectedArray<HairInfo>`
- Source-level owner: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) template support, embedded by [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- Current generated file: `source-3/simroot_v2/class_ProtectedArray_struct_HairInfo_.cpp`

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e5ae0` | ordinary destructor | Resets `ProtectedArray<HairInfo>` vtable and frees backing storage. |
| `0x004e5f20` | `GetAtOrDefault(int index)` | Bounds-checked accessor using a `0x10` byte element stride. |
| `0x004e60f0` | scalar deleting destructor | Ordinary cleanup plus conditional `operator delete`. |

## Ownership Notes

`HumanImageLib::HumanImageLib` uses this accessor while populating old hair color/variant metadata. Keep the template code in shared support and the data loading in `HumanImageLib`.

## Cross-References

- [UID:000186][0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors.md)
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `72/86`.
  - Before: The page was unevaluated despite identifying the concrete template instance, destructor slots, accessor, and source-level owner.
  - After: Scored as adequate completion and strong confidence for a generated `ProtectedArray<HairInfo>` instantiation.
  - Evidence: Existing method table and ownership notes tie the accessor/destructors to HumanImageLib metadata and shared template support.
