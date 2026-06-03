*** UID:0000E0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticCloudFilterEffecter

## Status

- Confidence: strong for role, source-module placement, and vtable-store identity; medium-high for exact source declaration because IDA does not currently model `0x0055b090` as a function object.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_StaticCloudFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Rebuild handling: `source-authored` constructor-only filter subclass. Marked reconstructable and attached to [UID:0000IZ][Effects](by-file/Effects.md); C++ remains blank because the final class declaration and raw-constructor source shape are not final-audit quality.

## Responsibility

`StaticCloudFilterEffecter` is a static cloud variant in the [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) subclass family. The generated body constructs the filter base and installs static-cloud vtables in the screen/pane slots.

The class belongs with the runtime effecter hierarchy rather than as a standalone source file. The adjacent [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) constructor has the same filter-subclass shape but installs the dynamic-cloud vtable family.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b090-0x0055b0c7` | constructor | Raw IDA disassembly confirms the `FilterEffecter` base call at `0x0055b09a`, four static-cloud vtable stores, return, and alignment. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |

## Vtable Evidence

The static-cloud constructor installs the same four-view filter object shape documented by [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md). These stores identify the class even though IDA does not currently create a function object at the constructor start.

| Object slot | Static-cloud vtable base | Store evidence |
| --- | --- | --- |
| primary `+0x00` | `0x00623b3c` | store at `0x0055b09f` |
| pane/view `+0x04` | `0x00623b5c` | store at `0x0055b0a7` |
| view `+0xa4` | `0x00623ba8` | store at `0x0055b0ae` |
| view `+0xa8` | `0x00623bd8` | store at `0x0055b0b8` |

## Boundary And Source Notes

- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records the read-only IDA rechecks: `0x0055b090-0x0055b0c7` has constructor-shaped bytes, calls [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) at `0x0055ad00`, stores the four static-cloud vtables, returns, and then aligns before later code.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) places the raw static-cloud constructor island inside the reviewed runtime effecter cluster and classifies most other gaps as `0xcc` alignment.
- [UID:0000IZ][Effects](by-file/Effects.md) treats `StaticCloudFilterEffecter` as part of the shared `render/Effects.cpp` runtime module. The generated one-class source file is staging evidence only and is not enough to infer a separate original `.cpp`.

## Reconstruction Notes

- `RECONSTRUCTABLE:TRUE` is justified because the raw constructor is NexusTK-owned source behavior and the owning runtime module is documented.
- The autogen parent is [UID:0000IZ][Effects](by-file/Effects.md), whose confidence is high enough for attachment.
- `RECONSTRUCTION_CPP CODE` stays blank until the final `FilterEffecter` declaration, embedded pane layout, and cloud/static-cloud constructor source spelling are audited together. The current evidence supports ownership and vtable identity, not final source-quality C++.

## Score Rationale

- Completion is raised to `74` because the page now records source-module ownership, reconstructable status, exact vtable bases/store addresses, and sibling/boundary evidence.
- Confidence is raised to `82` because [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and [UID:0000IZ][Effects](by-file/Effects.md) agree on the class, constructor-shaped range, four-view vtable identity, and runtime module owner.
- Confidence stays at `82` rather than moving higher because fresh IDA MCP was unavailable on 2026-06-03 and the constructor start remains a raw non-function-object boundary in IDA.

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
- 2026-06-03 reconstructable/source attachment update:
  - What existed before: the page was scored `72/74`, had blank reconstructable metadata, and did not record the exact static-cloud vtable bases/store addresses.
  - Changed to: scored `74/82`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and added the four-view vtable evidence plus C++ gating notes.
  - Summary/evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and [UID:0000IZ][Effects](by-file/Effects.md) already record IDA-backed vtable-store, raw-constructor, and module-cluster evidence. C++ remains blank because final class/source declaration detail is still incomplete.
