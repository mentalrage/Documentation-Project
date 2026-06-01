*** UID:00002T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CloudFilterEffecter

## Status

- Confidence: strong for role, medium for exact constructor boundary because IDA does not currently model `0x0055b000` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_CloudFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`CloudFilterEffecter` is a constructor-only cloud specialization over [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md). The generated body builds the filter base and installs cloud-specific screen/pane interface vtables.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b000-0x0055b037` | constructor | Raw IDA disassembly confirms the `FilterEffecter` base call at `0x0055b00a`, four cloud vtable stores, return, and alignment. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- What existed before: the page documented role, raw constructor bytes, base call, vtable stores, and effect-family references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `60/76`.
- Summary and evidence: the constructor-only specialization is understood, but IDA does not model the constructor start as a function object and the page lacks final source-level declaration/layout detail.
