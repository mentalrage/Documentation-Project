*** UID:0000AB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:15 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PatchPane::PatchFileData

## Status

- Confidence: strong for nested `PatchPane` ownership, destructor behavior, and one-slot vtable identity; medium-high for complete field/layout semantics because the producer/allocation path and full backing-storage layout remain open.
- Likely source file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Generated-output reference: legacy generated output had a standalone `class_PatchPane__PatchFileData.cpp`; reconstruction should keep this as a nested `PatchPane` support type.
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)

## Class Purpose

`PatchPane::PatchFileData` is a nested support object for patch-file backing storage in the startup patch/update subsystem. Current by-* evidence exposes its one emitted virtual path, a scalar deleting destructor at `0x00548500`, and vtable identity under the `PatchPane` vtable island. The producer and full data layout are still not documented deeply enough for final source emission.

## Rebuild Handling

- Reconstructability: true for the nested type declaration and scalar deleting destructor behavior.
- Parent handling: attach under [UID:0000MH][PatchPane](by-file/PatchPane.md), which already owns `PatchPane`, `PatchPane2`, and the nested patch-file support types at `88/80`.
- C++ handling: leave final C++ blank. The backing-storage destructor is clear, but field names, allocation/producer semantics, and the full nested object lifetime are not final-source quality.
- Binary handling: do not emit the vtable data directly. [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) is compiler-emitted evidence that should be regenerated from the final nested type declaration.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00548500-0x00548554` | scalar deleting destructor | Reinstalls the `PatchPane::PatchFileData` vtable, releases backing storage at the observed `+0x208` field, clears that field, and optionally deletes the object storage. |

## Data And Vtable Evidence

- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) records `PatchPane::PatchFileData` as a one-slot nested vtable at `0x00621dc4`.
- The preceding RTTI dword at `0x00621dc0` points to `??_R4PatchFileData@PatchPane@@6B@`, which ties the vtable identity to the nested `PatchPane` type.
- The only vtable slot at `0x00621dc4` targets `0x00548500`, matching the scalar deleting destructor documented here.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) includes `PatchPane::PatchFileData` between `PatchFileSlice` and the main `PatchPane` vtable family, matching the source nesting described by [UID:0000MH][PatchPane](by-file/PatchPane.md).
- [UID:000264][0x00621db8-0x00622034.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622034.PatchPaneReadOnlyData.md) keeps the surrounding `.rdata` aggregate source-declared/generated-binary rather than a hand-ported data blob.

## Evidence Notes

- `PatchPane` constructor/destructor paths in [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md) are the executable owner for this nested helper, and the aggregate keeps `0x00548500-0x00548554` between the `PatchFileSlice` vector deleting destructor and `PatchPane` scalar deleting destructor.
- Existing IDA-backed docs confirm `0x00548500` as a real function immediately before `PatchPane` scalar deleting destructor.
- The helper is too tightly coupled to patch entry backing storage to be a standalone original source file.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the `PatchFileData` vtable at `0x00621dc4` with only the scalar deleting destructor slot.
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) confirms exact neighboring boundaries: `PatchFileSlice` at `0x00621dbc`, `PatchFileData` at `0x00621dc4`, `PatchPane` primary at `0x00621dcc`, and the string boundary at `0x00621e64`.
- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) provides the stronger sibling pattern: nested file-support objects are rebuilt through `PatchPane` declarations, with exact field names held until producer/allocation semantics are known.

## Reconstruction Notes

- Model this as a nested `PatchPane::PatchFileData` support object, not as an independent patch module class.
- Preserve only the destructor-supported field evidence: a backing-store pointer at the observed `+0x208` offset that is released and cleared.
- Delay source-level field names and constructor/body reconstruction until producer/allocation code for this backing store is audited.
- Keep the final C++ block blank until the full object layout, allocator/release routine identity, and producer path are documented to the 95/95 source gate.

## Score Rationale

- Completion is raised to `80` because the page now records parent attachment, nested ownership, destructor behavior, one-slot vtable/RTTI placement, neighboring range boundaries, sibling `PatchFileSlice` comparison, and final-code gates.
- Confidence is raised to `86` because the parent file, aggregate executable page, vtable-data page, read-only-data aggregate, and vtable-family page agree on ownership and identity. Confidence remains below the sibling `PatchFileSlice` page because this class still has only destructor-visible layout evidence and no documented producer/allocation pass.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md)
- [UID:000264][0x00621db8-0x00622034.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622034.PatchPaneReadOnlyData.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite the page identifying this as a nested patch backing-storage object with a known scalar deleting destructor.
- Changed to: `COMPLETION:62` and `CONFIDENCE:68`.
- Evidence: destructor behavior, backing-store pointer release, vtable slot, and tight ownership by `PatchPane` are documented; completion and confidence remain moderate because only one emitted method is understood and the full nested layout/lifetime semantics are not yet reconstructed.
- 2026-06-02:
  - Before: the page remained in the low-both queue and was not attached to the confirmed patch source file.
  - After: raised to `74/82`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MH][PatchPane](by-file/PatchPane.md).
  - Summary/evidence: `PatchPane` file ownership at `88/80`, exact vtable child [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md), vtable-family slot evidence, and the real destructor at `0x00548500` support nested-source reconstruction while keeping final C++ blank.
- 2026-06-07 A004:
  - Before: the page was attached and had the key destructor/vtable evidence, but still carried stale score history and did not explain the sibling `PatchFileSlice` comparison, `.rdata` rebuild handling, or why confidence stays below final/source-emission quality.
  - After: raised to `80/86`, clarified nested-source handling, expanded evidence and reconstruction notes, added score rationale, and cross-linked the read-only-data aggregate.
  - Summary/evidence: [UID:0000MH][PatchPane](by-file/PatchPane.md) owns the patch subsystem, [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md) places `0x00548500-0x00548554` in the patch-pane executable island, [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) records the one-slot nested vtable/RTTI identity, and [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) provides the current nested-helper documentation pattern.
