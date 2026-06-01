*** UID:0000E0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticCloudFilterEffecter

## Status

- Confidence: strong for role, medium for exact constructor boundary because IDA does not currently model `0x0055b090` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_StaticCloudFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`StaticCloudFilterEffecter` is a static cloud variant in the [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) subclass family. The generated body constructs the filter base and installs static-cloud vtables in the screen/pane slots.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b090-0x0055b0c7` | constructor | Raw IDA disassembly confirms the `FilterEffecter` base call at `0x0055b09a`, four static-cloud vtable stores, return, and alignment. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `72`, confidence `74`.
- Evidence: the page documents the effecter role, likely source, base class, runtime cluster, and raw constructor evidence; completion/confidence stay limited because IDA does not currently model the constructor start as a function and only a narrow class slice is documented.
