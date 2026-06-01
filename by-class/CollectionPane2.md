*** UID:00002Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Current recovered file: `source-3/simroot_v2/class_CollectionPane2.cpp`
- Confidence: medium because the constructor is raw-code confirmed but not an IDA function object.

## Class Purpose

`CollectionPane2` is a small alternate collection inventory frame pane. It initializes a `PanelPane` base, installs three vtable views, renders the `CLTINV.EPF` frame with `ITEMINV.PAL`, and exposes mostly false/stub query virtuals.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionPane2` | `0x0056fd70-0x0056fda0` | [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) confirmed by IDA disassembly; IDA did not create a function at this start. |
| `~CollectionPane2` body | `0x0056fda0-0x0056fdbf` | [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md); restores vtables and chains to `PanelPane`. |
| adjustor/dispatcher | `0x0056fdc0-0x0056fdcc` | [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md). |
| `RenderCollectionInventoryFrame` | `0x0056fdd0-0x0056fe40` | Loads `ITEMINV.PAL` and `CLTINV.EPF` frame zero, then blits through `g_pfnBlitText`. |
| `IsQuerySupported` | `0x0056fe50-0x0056fe54` | Returns false. |
| `IsAlternateQuerySupported` | `0x0056fe60-0x0056fe64` | Returns false. |
| `0x0056fe70` | `0x0056fe70-0x0056fe75` | [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md), likely another vtable slot. |
| `ScalarDeletingDestructor` | `0x00573310-0x00573365` | Destructor wrapper; secondary/tertiary adjustor thunks are documented in [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md). |

## Open Questions

- Wave3 currently emits the constructor at `0x0056fd70`; IDA does not model that start as a function even though the bytes are executable constructor code. Treat this as an IDA/Wave3 boundary caveat before migration.
- Wave3 omits `0x0056fda0`, `0x0056fdc0`, and `0x0056fe70`.

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
- Summary and evidence: raw constructor, destructor body, forwarding thunk, render method, false stubs, and scalar destructor are covered; IDA lacks a function object for the constructor and Wave3 omits several helper bodies.
