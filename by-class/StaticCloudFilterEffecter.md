*** UID:0000E0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StaticCloudFilterEffecter : public FilterEffecter
{
public:
    StaticCloudFilterEffecter();
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticCloudFilterEffecter

## Status

- Confidence: strong for role, source-module placement, and vtable-store identity; medium-high for exact source declaration because IDA does not currently model `0x0055b090` as a function object.
- Proposed source: `render/Effects.cpp`
- Current memory evidence: exact constructor child [UID:0003O9][0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor](by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md) inside [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Documentation basis: live IDA raw constructor bytes, four-view static-cloud vtable stores, sibling constructor-boundary notes, runtime-cluster evidence, and the shared [UID:0000IZ][Effects](by-file/Effects.md) source-module page.
- Recovered-output caveat: any one-class recovered output is only a migration lead; source placement stays with the shared runtime effect hierarchy.
- Rebuild handling: `source-authored` constructor-only filter subclass. Marked reconstructable and attached to [UID:0000IZ][Effects](by-file/Effects.md); formal C++ now emits a declaration-only class block because class identity and inheritance are source-quality, while the isolated raw constructor body remains withheld.

## Responsibility

`StaticCloudFilterEffecter` is a static cloud variant in the [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) subclass family. The documented raw constructor constructs the resolved `FilterEffecter : public ScreenEffecter, public Pane` base and installs static-cloud vtables in the screen/pane slots.

The class belongs with the runtime effecter hierarchy rather than as a standalone source file. The adjacent [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) constructor has the same filter-subclass shape but installs the dynamic-cloud vtable family. The raw constructor proves vtable replacement and inheritance shape, not StaticCloud-owned fields.

## Hierarchy And Sibling Evidence

| Item | Evidence |
| --- | --- |
| Source module | [UID:0000IZ][Effects](by-file/Effects.md) groups `StaticCloudFilterEffecter` with the runtime `ScreenEffecter` hierarchy in `render/Effects.cpp`, alongside the base filter, dynamic cloud, solid-color, water, overlay, and pixel-displacement branches. |
| Base class | [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) documents the base constructor at `0x0055ad00-0x0055adba`, the `ScreenEffecter, Pane` declaration, and the four-view filter object shape. Its derived-constructor evidence includes the static-cloud base call at `0x0055b09a`. |
| Vtable family | [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) places the static-cloud tables immediately after the dynamic-cloud tables in the filter branch and before the pixel-displacement/water/lake tail. |
| Read-only data | [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) lists the exact static-cloud vtable-view span at `0x00623b3c-0x00623bd8`; the vtable bytes are generated from source declarations, not hand-authored fixed data. |
| Runtime cluster | [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) covers `0x0055b000-0x0055b0c7` as the cloud/static-cloud raw constructor island inside the reviewed effecter module, with [UID:0003O9][0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor](by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md) now carrying the exact static-cloud body. |
| Sibling parity | [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) is the dynamic-cloud sibling: it calls the same `FilterEffecter` base, installs the same four-view object shape, and is separated from this static-cloud constructor by `nullsub_50` and alignment rather than by a different source family. |

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0003O9][0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor](by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md) | constructor | Raw IDA disassembly confirms the `FilterEffecter` base call at `0x0055b09a`, four static-cloud vtable stores, return, and alignment. IDA still lacks a function object or direct caller for the start. |

## Vtable Evidence

The static-cloud constructor installs the same four-view filter object shape documented by [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md). The primary view is complete `+0x00`, while the `+0x04`, `+0xa4`, and `+0xa8` entries are adjusted inherited Pane-side views from the resolved FilterEffecter base. These stores identify the class even though IDA does not currently create a function object at the constructor start.

| Object slot | Static-cloud vtable base | Store evidence |
| --- | --- | --- |
| primary `+0x00` | `0x00623b3c` | store/xref at `0x0055b09f` |
| pane/view `+0x04` | `0x00623b5c` | store/xref at `0x0055b0a7` |
| view `+0xa4` | `0x00623ba8` | store/xref at `0x0055b0ae` |
| view `+0xa8` | `0x00623bd8` | store/xref at `0x0055b0b8` |

## Boundary And Source Notes

- [UID:0003O9][0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor](by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md) records the exact 2026-06-14 live IDA evidence: no function and no direct xrefs at `0x0055b090`, constructor-shaped bytes, call to [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) at `0x0055ad00`, four static-cloud vtable stores, return at `0x0055b0c6`, and `0xcc` padding at `0x0055b0c7-0x0055b0d0`.
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) records `sub_55AD00` as a real base-constructor function whose callers include the static-cloud raw constructor call at `0x0055b09a`, plus sibling filter constructors at `0x0055ae2a`, `0x0055b00a`, and `0x0055b6ca`.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) places the raw static-cloud constructor island inside the reviewed runtime effecter cluster and classifies most other gaps as `0xcc` alignment.
- [UID:0000IZ][Effects](by-file/Effects.md) treats `StaticCloudFilterEffecter` as part of the shared `render/Effects.cpp` runtime module. The generated one-class source file is staging evidence only and is not enough to infer a separate original `.cpp`.
- 2026-06-14 A001 live IDA MCP refreshed the raw constructor and vtable evidence in database `b001_0003gy`, replacing the earlier MCP-unavailable cap.

## Reconstruction Notes

- `RECONSTRUCTABLE:TRUE` is justified because the raw constructor is NexusTK-owned source behavior and the owning runtime module is documented.
- The autogen parent is [UID:0000IZ][Effects](by-file/Effects.md), whose confidence is high enough for attachment.
- `RECONSTRUCTION_CPP CODE` stays blank until the raw constructor's caller/reachability and exact source spelling are audited. The `FilterEffecter` declaration and inherited Pane layout are no longer blockers; the remaining blockers are raw non-function constructor status, no direct caller recovery, and lack of StaticCloud-specific field proof.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now records source-module ownership, base-class relationship, exact constructor child, base call site, four static-cloud vtable targets/stores, runtime-cluster placement, read-only data owner, dynamic-cloud sibling parity, autogen parent rationale, and explicit final-C++ blockers. |
| Confidence | 87 | Live IDA MCP agrees on the constructor-shaped body, `FilterEffecter` base call, vtable-store identity, padding boundary, and `Effects.cpp` owner. Confidence remains below final-source quality because `0x0055b090` is still a raw non-function-object constructor with no direct caller recovery. |
| Reconstructable | true | The class is source-authored runtime effecter behavior whose declarations and constructor must be recreated, while the vtable bytes themselves remain source-declared/generated-binary output. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0003O9][0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor](by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the declaration-only `StaticCloudFilterEffecter : public FilterEffecter` block. Current MCP keeps `0x0055b090` as raw constructor bytes with no function object and no direct raw-start xrefs. The raw body calls `FilterEffecter`, installs four static-cloud vtable views, returns, and aligns with `0xcc` padding. This proves class identity and Effects source placement, while the isolated raw constructor body remains withheld.

## Changes

- 2026-06-19 B013 FilterEffecter support incorporation:
  - Score unchanged at `86/87`.
  - Summary/evidence: updated hierarchy/vtable wording to reference the resolved `FilterEffecter : public ScreenEffecter, public Pane` base shape, preserved exact constructor child evidence, and narrowed the C++ blocker to raw constructor reachability/source spelling. No StaticCloud-owned fields are inferred from inherited adjusted view offsets.
- 2026-06-14 A001 exact-child/live-evidence refresh:
  - Before: scored `80/84`; the page still carried a current-session MCP-unavailable confidence cap and relied on aggregate/item evidence for the constructor body.
  - After: scored `86/87`; added exact constructor child [UID:0003O9][0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor](by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md) and refreshed the class evidence.
  - Evidence: live IDA MCP `lookup_funcs`, `disasm`, `xrefs_to`, `get_int`, and `get_bytes` confirm no function/no direct refs at `0x0055b090`, base call `0x0055b09a -> 0x0055ad00`, four static-cloud vtable stores, return at `0x0055b0c6`, and `0xcc` alignment through `0x0055b0d0`. B006 2026-06-30 now emits the declaration while keeping the raw constructor body withheld.
- 2026-06-07 A004 hierarchy/evidence refresh:
  - Before: scored `74/82` with constructor and vtable facts documented, but the page did not summarize the base-class, read-only-data, runtime-cluster, and dynamic-cloud sibling evidence in one place.
  - After: scored `80/84`, added hierarchy/sibling evidence, explicit score rationale, the `ScreenEffecterVtableData` cross-reference, and a current-session MCP-unavailable caveat.
  - Evidence: [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md), [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) agree on the `Effects.cpp` owner, `FilterEffecter` base call, `0x0055b090-0x0055b0c7` raw constructor, and `0x00623b3c-0x00623bd8` static-cloud vtable views. No final C++ emitted because the raw constructor and final declaration remain below the active `90/90+` code-entry gate.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `72`, confidence `74`.
- Evidence: the page documents the effecter role, likely source, base class, runtime cluster, and raw constructor evidence; completion/confidence stay limited because IDA does not currently model the constructor start as a function and only a narrow class slice is documented.
- 2026-06-03 reconstructable/source attachment update:
  - What existed before: the page was scored `72/74`, had blank reconstructable metadata, and did not record the exact static-cloud vtable bases/store addresses.
  - Changed to: scored `74/82`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and added the four-view vtable evidence plus C++ gating notes.
  - Summary/evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and [UID:0000IZ][Effects](by-file/Effects.md) already record IDA-backed vtable-store, raw-constructor, and module-cluster evidence. Formal output was withheld at that time; B006 2026-06-30 now emits the declaration.
- 2026-06-06 provenance cleanup:
  - Before: the status section still presented a direct recovered-source path as current evidence, and the responsibility section described the constructor as a generated body.
  - After: replaced that status evidence with the IDA-backed documentation basis and described the constructor through documented raw bytes.
  - Evidence: the page already records raw constructor bytes, four vtable stores, runtime-cluster placement, sibling constructor-boundary notes, and Effects module ownership. Scores and parent remain unchanged; B006 2026-06-30 replaces the former empty marker with declaration-only output.
