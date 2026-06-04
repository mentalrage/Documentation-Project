*** UID:00002Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionPane2

## Status

- Likely source file: [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Address range: [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md), plus destructor `0x00573310-0x00573365` in [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- Confidence: strong for the vtable-backed method map, render resources, false stubs, and scalar destructor; medium only for the raw constructor boundary because IDA still does not model `0x0056fd70` as a function object.
- Evidence basis: live IDA MCP `py_eval` on 2026-06-04 against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`).

## Class Purpose

`CollectionPane2` is a small alternate collection inventory frame pane. It initializes a `PanelPane` base, installs three vtable views, renders the `CLTINV.EPF` frame with the shared `ITEMINV.PAL` palette, and exposes mostly false/stub query virtuals.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionPane2` | `0x0056fd70-0x0056fda0` | [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) raw constructor bytes; calls `0x00545090`, stores vtables `0x0062466c`, `0x006246bc`, and `0x006246ec`, and returns `this`. |
| `~CollectionPane2` body | `0x0056fda0-0x0056fdbf` | [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md); restores vtables and chains to `PanelPane`. |
| adjustor/dispatcher | `0x0056fdc0-0x0056fdcc` | [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md); vtable slot `0x006246b4`, dispatches through primary vtable slot `+0x20` with `this+0x44`. |
| `RenderCollectionInventoryFrame` | `0x0056fdd0-0x0056fe41` | Vtable slot `0x006246b0`; loads `ITEMINV.PAL` from `0x0061c964`, draws `CLTINV.EPF` from `0x00624ac8`, then blits through `dword_69B3E8`. |
| `IsQuerySupported` | `0x0056fe50-0x0056fe55` | False-return vtable slot `0x006246c4`. |
| `IsAlternateQuerySupported` | `0x0056fe60-0x0056fe65` | False-return vtable slot `0x006246c0`. |
| `0x0056fe70` | `0x0056fe70-0x0056fe75` | [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md), false-return vtable slot `0x006246cc`. |
| `ScalarDeletingDestructor` | `0x00573310-0x00573365` | Primary vtable slot `0x0062466c`; restores all three vtable views, chains to `0x005450d0`, and optionally frees object storage. Secondary/tertiary adjustor thunks are documented in [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md). |

## Live IDA Evidence

- 2026-06-04 IDA confirms modeled functions at `0x0056fda0-0x0056fdbf`, `0x0056fdc0-0x0056fdcc`, `0x0056fdd0-0x0056fe41`, `0x0056fe50-0x0056fe55`, `0x0056fe60-0x0056fe65`, `0x0056fe70-0x0056fe75`, and `0x00573310-0x00573365`; the next modeled class body starts at `0x0056fe80`.
- Raw disassembly at `0x0056fd70-0x0056fda0` shows a complete constructor shape: base constructor call `0x00545090`, three `CollectionPane2` vtable stores, `eax=this`, and `retn`; there are still no xrefs to the raw start.
- The `CollectionPane2` vtable island `0x00624668-0x006246f4` contains RTTI plus primary/secondary/tertiary tables. Slots `0x006246b0`, `0x006246b4`, `0x006246c0`, `0x006246c4`, and `0x006246cc` target the render, forwarding thunk, and three false-return helpers.
- The destructor path is tied by data xrefs from primary/secondary/tertiary vtable slots to `0x00573310`, `0x00573247`, and `0x00573252`; the adjustor thunks jump into `0x00573310`.
- Render resource xrefs show `0x0056fdf9` pushing `ITEMINV.PAL` at `0x0061c964` and `0x0056fe0d` pushing `CLTINV.EPF` at `0x00624ac8`.

## Open Questions

- IDA does not model `0x0056fd70` as a function even though the bytes are executable constructor code, and no direct callers are recorded for that raw start.
- Final source-quality names for the three false-return slots and the forwarding thunk remain provisional.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md)
- [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md)
- [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)

## Changes

- Before: the scalar deleting destructor was listed as `0x00573310-0x00573364`, and the adjustor thunks were not covered by class references.
- Changed to: the destructor endpoint is corrected to `0x00573365`, with the adjacent adjustor thunks and destructor island linked.
- Evidence: 2026-05-28 IDA MCP reports `sub_573310` as `0x00573310-0x00573365`, with `0x00573247` and `0x00573252` as `-0xa0`/`-0xa4` adjustor thunks into it.
- What existed before: the page documented the alternate collection inventory frame pane and raw constructor/destructor boundaries, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/78`.
- Summary and evidence: raw constructor, destructor body, forwarding thunk, render method, false stubs, and scalar destructor are covered; IDA lacks a function object for the constructor.
- 2026-06-04: Raised from `72/78` to `82/88`.
  - What existed before: the page had the broad method list but still relied on stale external caveats, had non-exclusive endpoints for two false-return helpers, and did not tie the class methods to the live `CollectionPane2` vtable island or render resource xrefs.
  - Changed to: documented the current IDA binary identity, raw constructor disassembly facts, exact modeled function ranges, vtable slots, destructor/adjustor linkage, and `ITEMINV.PAL`/`CLTINV.EPF` resource xrefs; removed stale external-output reliance.
  - Reason for score increase: live IDA evidence now proves the alternate pane's class shape, destructor paths, render helper, and vtable ownership strongly enough for an `82/88` class page, while the raw constructor's lack of an IDA function object and direct caller keeps C++ reconstruction below the final bar.
