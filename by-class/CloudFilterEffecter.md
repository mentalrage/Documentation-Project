*** UID:00002T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CloudFilterEffecter : public FilterEffecter
{
public:
    CloudFilterEffecter();
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CloudFilterEffecter

## Status

- Confidence: strong for role, Effects ownership, vtable-store identity, and exact raw constructor bytes; medium for normal constructor reachability because IDA still does not model `0x0055b000` as a function object.
- Proposed source: `render/Effects.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Rebuild handling: `source-authored` constructor-only filter subclass. Marked reconstructable and attached to [UID:0000IZ][Effects](by-file/Effects.md); formal C++ now emits a declaration-only class block because class identity and inheritance are source-quality, while the isolated raw constructor body remains withheld.

## Responsibility

`CloudFilterEffecter` is a constructor-only cloud specialization over [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md). The raw constructor builds the resolved `FilterEffecter : public ScreenEffecter, public Pane` base and installs cloud-specific screen/pane interface vtables.

The class belongs with the runtime effecter hierarchy rather than as a standalone source file. The adjacent [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) constructor has the same filter-subclass shape but installs the static-cloud vtable family. No Cloud-specific fields are proven by this raw constructor; do not invent fields from the inherited Pane/GrafPort adjusted views.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b000-0x0055b037` | raw constructor | Live IDA disassembly confirms the `FilterEffecter` base call at `0x0055b00a`, four cloud vtable stores, return at `0x0055b036`, and `0xcc` alignment through `0x0055b040`. IDA still lacks a function object for the start. |

## Vtable Evidence

The cloud constructor installs the same four-view filter object shape documented by [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md). The primary view is at complete `+0x00`, while the `+0x04`, `+0xa4`, and `+0xa8` entries are adjusted inherited Pane-side views from the FilterEffecter base shape. Live IDA xrefs to the four vtable bases come only from the raw constructor stores, which identifies the class but keeps normal reachability unresolved.

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
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` still reports `0x0055b000` as `Not a function`, `sub_55AD00` as size `0xbb`, and `nullsub_50` at `0x0055b040` size `0x3`.
- The same recheck confirms `xrefs_to(0x0055b000)` is still empty; `xrefs_to(0x0055ad00)` includes sibling constructor calls at `0x0055ae2a`, raw cloud call `0x0055b00a`, raw static-cloud call `0x0055b09a`, and water/filter call `0x0055b6ca`.
- Vtable base xrefs remain one store each from the raw cloud constructor: `0x00623a94` at `0x0055b00f`, `0x00623ab4` at `0x0055b017`, `0x00623b00` at `0x0055b01e`, and `0x00623b30` at `0x0055b028`. `make_signature_for_range(0x0055b000,0x0055b037)` returns a unique wildcarded signature for the raw constructor island.
- `analyze_component` over `FilterEffecter` context functions `0x0055ad00`, `0x0055ae00`, and `0x0055b6a0` shows the sibling modeled constructors call the same `sub_55AD00` base and share `dword_67A764`, supporting the cloud island's placement in the filter-effecter family even though the cloud start itself is raw.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now records the exact raw constructor range, base constructor function/range, return and padding boundary, four cloud vtable targets/stores, Effects owner/emitter route, no-xref constructor caveat, sibling filter-context evidence, and a unique raw-range signature. |
| Confidence | 88 | Confidence is strong for class identity and Effects ownership because live IDA confirms the base call, vtable stores, vtable target slots, and sibling constructor calls into `FilterEffecter`. It remains capped because `0x0055b000` is not an IDA function object and has no direct xrefs or pointer hits. |
| Reconstructable | true | The class is source-authored effecter hierarchy behavior attached to [UID:0000IZ][Effects](by-file/Effects.md). The class declaration is now source-quality; the raw constructor body remains withheld because IDA still has no function object or direct raw-start xref. |

## Reconstruction Notes

- `RECONSTRUCTABLE:TRUE` is justified because the raw constructor is NexusTK-owned source behavior and the owning runtime module is documented.
- The owner/emitter route is [UID:0000IZ][Effects](by-file/Effects.md), whose confidence is high enough for attachment.
- `RECONSTRUCTION_CPP CODE` now carries a declaration-only class block. The `FilterEffecter` declaration and inherited Pane layout are no longer blockers; the remaining blockers for an executable constructor body are the raw no-xref constructor start, no IDA function object, and absent Cloud-specific field/caller proof.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the class declaration `CloudFilterEffecter : public FilterEffecter`. Current MCP database `supervisor_resume_20260629` still reports `0x0055b000` as not an IDA function and reports no direct xrefs to the raw start, so the isolated constructor body remains withheld. The declaration is supported by the raw byte shape: the constructor calls `0x0055ad00` (`FilterEffecter`), stores four cloud vtables at `0x00623a94`, `0x00623ab4`, `0x00623b00`, and `0x00623b30`, returns, and is followed by `0xcc` padding. This page is source-authored and emitted through [UID:0000IZ][Effects](by-file/Effects.md), but raw constructor reachability remains the confidence cap.

## Changes

- 2026-06-19 B013 FilterEffecter support incorporation:
  - Score unchanged at `85/88`.
  - Summary/evidence: updated the page to reference the resolved `FilterEffecter : public ScreenEffecter, public Pane` base shape, preserved the four-view replacement evidence, and narrowed the C++ blocker to the raw no-xref constructor/caller problem. No Cloud-owned fields are inferred from inherited Pane/GrafPort vptr offsets.
- What existed before: the page documented role, raw constructor bytes, base call, vtable stores, and effect-family references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `60/76`.
- Summary and evidence: the constructor-only specialization is understood, but IDA does not model the constructor start as a function object and the page lacks final source-level declaration/layout detail.
- 2026-06-02 reconstructable/source attachment update:
  - What existed before: the page was scored `60/76`, had blank reconstructable metadata, and did not record the exact cloud vtable bases/store addresses.
  - Changed to: scored `72/82`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and added the four-view vtable evidence plus C++ gating notes.
  - Summary/evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md), and [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) already record IDA-backed vtable-store, raw-constructor, and module-cluster evidence. Formal output was withheld at that time; B006 2026-06-30 now emits the declaration.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, parent `0000IZ`, and summarized the constructor/vtable evidence without direct live raw-range details.
  - Changed to: scores `82/86`, live IDA evidence for the exact raw constructor, `FilterEffecter` base function range, vtable target slots, no-xref/no-pointer constructor reachability, and padding/next-function boundary.
  - Summary/evidence: completion increased because the page now documents the constructor body, base-call context, vtable targets, and boundary facts directly. Confidence increased because live IDA confirms the raw byte body and sibling `FilterEffecter` call pattern, while preserving the raw-constructor cap. Formal output was withheld under the then-active threshold; B006 2026-06-30 supersedes that with declaration-only output.
- 2026-06-15 A002 Goal 2 by-class refresh:
  - Changed to: scores `85/88`, with no owner/emitter changes.
  - Summary/evidence: live IDA reconfirmed `0x0055b000` is still not a function and has no direct xrefs, `sub_55AD00` and `nullsub_50` boundaries, the four one-xref cloud vtable stores, sibling calls into `FilterEffecter`, and a unique raw constructor signature. B006 2026-06-30 keeps the raw constructor body withheld but emits the source-quality class declaration.
