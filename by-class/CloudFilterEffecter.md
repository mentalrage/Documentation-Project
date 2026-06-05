*** UID:00002T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CloudFilterEffecter

## Status

- Confidence: strong for role, Effects ownership, vtable-store identity, and exact raw constructor bytes; medium for normal constructor reachability because IDA still does not model `0x0055b000` as a function object.
- Proposed source: `render/Effects.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Rebuild handling: `source-authored` constructor-only filter subclass. Marked reconstructable and attached to [UID:0000IZ][Effects](by-file/Effects.md); C++ remains blank because the final class declaration and raw-constructor source shape are not final-audit quality.

## Responsibility

`CloudFilterEffecter` is a constructor-only cloud specialization over [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md). The raw constructor builds the filter base and installs cloud-specific screen/pane interface vtables.

The class belongs with the runtime effecter hierarchy rather than as a standalone source file. The adjacent [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) constructor has the same filter-subclass shape but installs the static-cloud vtable family.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b000-0x0055b037` | raw constructor | Live IDA disassembly confirms the `FilterEffecter` base call at `0x0055b00a`, four cloud vtable stores, return at `0x0055b036`, and `0xcc` alignment through `0x0055b040`. IDA still lacks a function object for the start. |

## Vtable Evidence

The cloud constructor installs the same four-view filter object shape documented by [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md). Live IDA xrefs to the four vtable bases come only from the raw constructor stores, which identifies the class but keeps normal reachability unresolved.

| Object slot | Cloud vtable base | Store evidence |
| --- | --- | --- |
| primary `+0x00` | `0x00623a94 -> sub_55C1C0` | store/xref at `0x0055b00f` |
| pane/view `+0x04` | `0x00623ab4 -> sub_55BA22` | store/xref at `0x0055b017` |
| view `+0xa4` | `0x00623b00 -> loc_55BA2A` | store/xref at `0x0055b01e` |
| view `+0xa8` | `0x00623b30 -> loc_55BA35` | store/xref at `0x0055b028` |

## Boundary And Source Notes

- 2026-06-05 live IDA MCP reports no function object at `0x0055b000`; `xrefs_to(0x0055b000)` is empty and a little-endian pointer-byte search for `0x0055b000` found no matches.
- Direct disassembly covers `0x0055b000-0x0055b037`: prologue, `this` save, call to [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) base constructor `sub_55AD00`, four `CloudFilterEffecter` vtable stores, `pop esi`, and `retn`.
- `sub_55AD00` is a real IDA function at `0x0055ad00-0x0055adbb`; its xrefs include the cloud raw constructor call at `0x0055b00a` plus sibling filter constructors at `0x0055ae2a`, `0x0055b09a`, and `0x0055b6ca`.
- `0x0055b037-0x0055b040` is `0xcc` padding, and the next modeled function is `nullsub_50` at `0x0055b040-0x0055b043`.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) places the raw cloud constructor island inside the reviewed runtime effecter cluster and classifies most other gaps as `0xcc` alignment.
- [UID:0000IZ][Effects](by-file/Effects.md) treats `CloudFilterEffecter` as part of the shared `render/Effects.cpp` runtime module. The one-class staging split is not enough to infer a separate original `.cpp`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now records the exact raw constructor range, base constructor function/range, return and padding boundary, four cloud vtable targets/stores, parent ownership, and the no-xref constructor caveat. |
| Confidence | 86 | Confidence is strong for class identity and Effects ownership because live IDA confirms the base call, vtable stores, vtable target slots, and sibling constructor calls into `FilterEffecter`. It remains below the reconstruction-code threshold because `0x0055b000` is not an IDA function object and has no direct xrefs or pointer hits. |
| Reconstructable | true | The class is source-authored effecter hierarchy behavior attached to [UID:0000IZ][Effects](by-file/Effects.md). C++ remains blank until the raw constructor and class declaration are final enough for the 95/95 gate. |

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
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, parent `0000IZ`, and summarized the constructor/vtable evidence without direct live raw-range details.
  - Changed to: scores `82/86`, live IDA evidence for the exact raw constructor, `FilterEffecter` base function range, vtable target slots, no-xref/no-pointer constructor reachability, and padding/next-function boundary.
  - Summary/evidence: completion increased because the page now documents the constructor body, base-call context, vtable targets, and boundary facts directly. Confidence increased because live IDA confirms the raw byte body and sibling `FilterEffecter` call pattern, while preserving the raw-constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
