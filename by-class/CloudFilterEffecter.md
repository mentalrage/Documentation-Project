*** UID:00002T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CloudFilterEffecter

## Status

- Confidence: strong for role, source-module placement, and vtable-store identity; medium-high for exact source declaration because IDA does not currently model `0x0055b000` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_CloudFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Rebuild handling: `source-authored` constructor-only filter subclass. Marked reconstructable and attached to [UID:0000IZ][Effects](by-file/Effects.md); C++ remains blank because the final class declaration and raw-constructor source shape are not final-audit quality.

## Responsibility

`CloudFilterEffecter` is a constructor-only cloud specialization over [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md). The generated body builds the filter base and installs cloud-specific screen/pane interface vtables.

The class belongs with the runtime effecter hierarchy rather than as a standalone source file. The adjacent [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) constructor has the same filter-subclass shape but installs the static-cloud vtable family.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b000-0x0055b037` | constructor | Raw IDA disassembly confirms the `FilterEffecter` base call at `0x0055b00a`, four cloud vtable stores, return, and alignment. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |

## Vtable Evidence

The cloud constructor installs the same four-view filter object shape documented by [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md). These stores identify the class even though IDA does not currently create a function object at the constructor start.

| Object slot | Cloud vtable base | Store evidence |
| --- | --- | --- |
| primary `+0x00` | `0x00623a94` | store at `0x0055b00f` |
| pane/view `+0x04` | `0x00623ab4` | store at `0x0055b017` |
| view `+0xa4` | `0x00623b00` | store at `0x0055b01e` |
| view `+0xa8` | `0x00623b30` | store at `0x0055b028` |

## Boundary And Source Notes

- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records the read-only IDA rechecks: `0x0055b000-0x0055b037` has constructor-shaped bytes, calls [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) at `0x0055ad00`, stores the four cloud vtables, returns, and then aligns before later code.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) places the raw cloud constructor island inside the reviewed runtime effecter cluster and classifies most other gaps as `0xcc` alignment.
- [UID:0000IZ][Effects](by-file/Effects.md) treats `CloudFilterEffecter` as part of the shared `render/Effects.cpp` runtime module. The generated one-class source file is staging evidence only and is not enough to infer a separate original `.cpp`.

## Reconstruction Notes

- `RECONSTRUCTABLE:TRUE` is justified because the raw constructor is NexusTK-owned source behavior and the owning runtime module is documented.
- The autogen parent is [UID:0000IZ][Effects](by-file/Effects.md), whose confidence is high enough for attachment.
- `RECONSTRUCTION_CPP CODE` stays blank until the final `FilterEffecter` declaration, embedded pane layout, and cloud/static-cloud constructor source spelling are audited together. The current evidence supports ownership and vtable identity, not final source-quality C++.

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
- 2026-06-02 reconstructable/source attachment update:
  - What existed before: the page was scored `60/76`, had blank reconstructable metadata, and did not record the exact cloud vtable bases/store addresses.
  - Changed to: scored `72/82`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and added the four-view vtable evidence plus C++ gating notes.
  - Summary/evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md), and [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) already record IDA-backed vtable-store, raw-constructor, and module-cluster evidence. C++ remains blank because final class/source declaration detail is still incomplete.
