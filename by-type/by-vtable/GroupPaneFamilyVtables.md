*** UID:0001XP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupPane Family Vtables

## Status

- Entity kind: vtable cluster.
- Covered classes: [UID:00005X][GroupListPane](by-class/GroupListPane.md), [UID:00005Y][GroupPane](by-class/GroupPane.md), [UID:00005Z][GroupPane2](by-class/GroupPane2.md), [UID:000090][NewGroupPane](by-class/NewGroupPane.md)
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Autogen parent: [UID:0000JS][Group](by-file/Group.md), now `89/85` after the Batch 067 parent-gate refresh.
- Confidence: strong for vtable bases and destructor/thunk slots; medium for final source split.

## Vtable Bases

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Evidence |
| --- | --- | --- | --- | --- |
| `GroupListPane` | `0x00624214` | `0x0062428c` | `0x006242bc` | Installed by raw constructor `0x0056baa0` and inline child setup in `GroupPane`/`GroupPane2`. |
| `GroupPane` | `0x0062443c` | `0x0062448c` | `0x006244bc` | Installed by constructor/destructor/scalar destructor at `0x0056c4c0`, `0x0056c5c0`, and `0x00573490`. |
| `GroupPane2` | `0x006244c8` | `0x00624518` | `0x00624548` | Installed by constructor/destructor/scalar destructor at `0x0056c770`, `0x0056c870`, and `0x005733e0`. |
| `NewGroupPane` | `0x00624554` | `0x006245a4` | `0x006245d4` | Installed by constructor/destructor/scalar destructor at `0x0056ca20`, `0x0056caf0`, and `0x00573570`. |

## Exact By-Memory Children

The group-pane family is not one contiguous group-only `.rdata` range. `GroupListPane` is followed by `SpelledPane`, and `GroupPane` is preceded by `LegendPane`; keep the exact child pages split by class and leave the surrounding non-group vtables with their own owners.

| Class | Exact data child | Boundary evidence |
| --- | --- | --- |
| `GroupListPane` | [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md) | Starts at `??_R4GroupListPane@@6B@`; ends before `??_R4SpelledPane@@6B@` at `0x006242c4`. |
| `GroupPane` | [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md) | Starts at `??_R4GroupPane@@6B@`; ends before `??_R4GroupPane2@@6B@` at `0x006244c4`. |
| `GroupPane2` | [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md) | Starts at `??_R4GroupPane2@@6B@`; ends before `??_R4NewGroupPane@@6B@` at `0x00624550`. |
| `NewGroupPane` | [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md) | Starts at `??_R4NewGroupPane@@6B@`; ends before `??_R4CollectionPane@@6B@` at `0x006245dc`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| `GroupListPane +0xa0` | `+0x08` | `0x0056bb00` | Tiny zero/false-return virtual. |
| `GroupListPane primary` | inherited/near tail | `0x0056bb10` | Tiny zero/false-return virtual; xref lands at `0x00624274` inside the primary table span. |
| `GroupPane primary` | `+0x00` | `0x00573490` | Scalar deleting destructor. |
| `GroupPane +0xa0` | `+0x00` | `0x00573289` | Secondary adjustor thunk to `0x00573490`. |
| `GroupPane +0xa4` | `+0x00` | `0x00573294` | Tertiary adjustor thunk to `0x00573490`. |
| `GroupPane2 primary` | `+0x00` | `0x005733e0` | Scalar deleting destructor. |
| `GroupPane2 +0xa0` | `+0x00` | `0x00573273` | Secondary adjustor thunk to `0x005733e0`. |
| `GroupPane2 +0xa4` | `+0x00` | `0x0057327e` | Tertiary adjustor thunk to `0x005733e0`. |
| `NewGroupPane primary` | `+0x00` | `0x00573570` | Scalar deleting destructor. |
| `NewGroupPane +0xa0` | `+0x00` | `0x0057329f` | Secondary adjustor thunk to `0x00573570`. |
| `NewGroupPane +0xa4` | `+0x00` | `0x005732aa` | Tertiary adjustor thunk to `0x00573570`. |

## IDA MCP Evidence

- `xrefs_to 0x00624214/0x0062428c/0x006242bc` shows vtable stores in the raw `GroupListPane` constructor and in the `GroupPane`/`GroupPane2` inline child constructors.
- `xrefs_to 0x0062443c/0x0062448c/0x006244bc` shows stores from `GroupPane` constructor, destructor, and scalar deleting destructor.
- `xrefs_to 0x006244c8/0x00624518/0x00624548` shows stores from `GroupPane2` constructor, destructor, and scalar deleting destructor.
- `xrefs_to 0x00624554/0x006245a4/0x006245d4` shows stores from `NewGroupPane` constructor, destructor, and scalar deleting destructor.
- 2026-05-31 IDA MCP `py_eval` dword scan confirms the exact child boundaries above and proves that neighboring `SpelledPane`, `LegendPane`, and `CollectionPane` RTTI records are not part of the group-pane vtable pages.

## 2026-06-07 Live IDA Refresh

- IDA MCP `py_eval` reconfirmed every dword in the four exact family child ranges: [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md), [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md), [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md), and [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md).
- The live table-base xref audit reconfirmed complete three-view stores for each class: `GroupListPane` bases from `0x0056badc/0x0056bae4/0x0056baee`, inline `GroupPane` child setup `0x0056c55e/0x0056c564/0x0056c56e`, and inline `GroupPane2` child setup `0x0056c80e/0x0056c814/0x0056c81e`; `GroupPane` bases from `0x0056c4fd/0x0056c503/0x0056c50d`, `0x0056c5eb/0x0056c5f1/0x0056c5fb`, and `0x005734bb/0x005734c1/0x005734cb`; `GroupPane2` bases from `0x0056c7ad/0x0056c7b3/0x0056c7bd`, `0x0056c89b/0x0056c8a1/0x0056c8ab`, and `0x0057340b/0x00573411/0x0057341b`; and `NewGroupPane` bases from `0x0056ca64/0x0056ca6a/0x0056ca74`, `0x0056cb1b/0x0056cb21/0x0056cb2b`, and `0x005735a2/0x005735a8/0x005735b2`.
- Function-boundary checks reconfirmed the key family functions and glue: `GroupPane` constructor/destructor/layout/paint/stubs at `0x0056c4c0-0x0056c5b1`, `0x0056c5c0-0x0056c62c`, `0x0056c630-0x0056c6bf`, `0x0056c6c0-0x0056c731`, `0x0056c740-0x0056c745`, and `0x0056c750-0x0056c755`; `GroupPane2` constructor/destructor/layout/paint/stubs at `0x0056c770-0x0056c861`, `0x0056c870-0x0056c8dc`, `0x0056c8e0-0x0056c96f`, `0x0056c970-0x0056c9e1`, `0x0056c9f0-0x0056c9f5`, and `0x0056ca00-0x0056ca05`; and NewGroupPane slots at `0x0056ca20-0x0056caeb`, `0x0056cb80-0x0056cbe6`, `0x0056cbf0-0x0056cc78`, `0x0056cc80-0x0056cd25`, `0x0056ce50-0x0056da03`, `0x0056da10-0x0056daf7`, `0x0056db00-0x0056dd46`, `0x0056dd50-0x0056def6`, `0x0056df40-0x0056dfa6`, and `0x0056dfb0-0x0056dfc6`.
- The same pass reconfirmed adjustor thunk and scalar deleting destructor extents: `GroupPane2` thunks `0x00573273-0x0057327e` and `0x0057327e-0x00573289` target destructor `0x005733e0-0x0057348d`; `GroupPane` thunks `0x00573289-0x00573294` and `0x00573294-0x0057329f` target destructor `0x00573490-0x0057353d`; and `NewGroupPane` thunks `0x0057329f-0x005732aa` and `0x005732aa-0x005732b5` target destructor `0x00573570-0x00573634`.
- Boundary dword reads reconfirmed that this family is split around neighboring owners: `GroupListPane` starts at `0x00624210` and ends before `SpelledPane` RTTI at `0x006242c4`; `GroupPane` starts at `0x00624438` after `LegendPane`; `GroupPane2` starts at `0x006244c4`; `NewGroupPane` starts at `0x00624550`; and `CollectionPane` RTTI starts at `0x006245dc`.

## Assignment Gate

- This page is now the direct type/layout parent for [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md), [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md), and [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md).
- The parent-side score is `86/92`, and each target child is now `88/92`, so the corrected 85/85 child-and-direct-parent gate is met for those vtable-data assignments.
- Batch066 sets this page's own `AUTOGEN_PARENT_UID` to [UID:0000JS][Group](by-file/Group.md) because this type page is `86/92`, the direct source-file parent is now `89/85`, and the group-pane family vtable declarations belong to the `Group.cpp` source root rather than to the mixed read-only-data aggregate.
- [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md) remains unassigned in this pass because it is not a Batch 020 target and still needs its own child-side refresh before crossing the 85 completion gate.
- This page is not a valid parent for the broad [UID:00026E][0x00624188-0x00624c64.LookGroupCollectionReadOnlyData](by-memory/0x00624188-0x00624c64.LookGroupCollectionReadOnlyData.md) aggregate because that aggregate also contains self-look, spelled, legend, collection, line-iterator, and resource-string data outside the group-pane vtable type layout.

## Reconstruction Notes

The recurring vtable offsets `+0x00`, `+0xa0`, and `+0xa4` match the broader pane/control multiple-inheritance pattern seen across the client. The secondary and tertiary destructor entries are compiler thunks, not handwritten methods.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md)
- [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)
- [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md)
- [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md)
- [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md)

## Changes

- 2026-06-07 A004 Batch 068 coverage-error verification:
  - Before: generated memory coverage for [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md) reported `autogen_parent_unknown` for this parent UID even though the child assignment was structurally correct.
  - After: scores remain `86/92` and `AUTOGEN_PARENT_UID:0000JS`; validator revalidation registers this page as the direct vtable-family parent, so [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md) clears generated memory coverage as assigned to `0001XP`.
  - Evidence: [UID:0000JS][Group](by-file/Group.md) remains the direct source-file parent at `89/85`, while this page directly owns the exact GroupPane/GroupPane2/NewGroupPane vtable-data children at `86/92`.

- 2026-06-07 A010 Batch066 coverage-error repair:
  - Before: `AUTOGEN_PARENT_UID` was blank, so memory child [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md) reported `autogen_parent_unknown` for `0001XP` in generated memory coverage even though this type page existed.
  - After: set `AUTOGEN_PARENT_UID:0000JS`; scores remain `86/92`.
  - Evidence: [UID:0000JS][Group](by-file/Group.md) is now `89/85` with a valid `NexusTK/social/` source root and exact group-pane vtable/data children, while this page is the direct `86/92` type/layout parent for the GroupPane/GroupPane2/NewGroupPane vtable-data children.
- 2026-05-31: Split exact vtable-data children and raised stale metadata from `0/0` to `84/88`.
  - Before: this page had strong slot notes but no completion/confidence score, and the group vtable rows were only described inside a broad mixed `.rdata` aggregate.
  - After: exact by-memory children document `GroupListPane`, `GroupPane`, `GroupPane2`, and `NewGroupPane` vtable data with RTTI boundary evidence; this page is marked reconstructable but still below final-audit scoring because final source-level virtual names and full class declarations remain incomplete.
  - Evidence: IDA MCP `py_eval` dword scan and `xrefs_to` checks on 2026-05-31 confirmed base stores, destructor/thunk targets, and next-class RTTI boundaries.
- 2026-06-07 A007 Batch020 associated-parent refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:88`, and the page was below the corrected 85/85 parent gate for the exact GroupPane/GroupPane2/NewGroupPane vtable-data children.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:92`, live IDA refresh evidence, and an explicit assignment-gate note for the three Batch020 child ranges.
  - Summary/evidence: live IDA MCP reconfirmed every dword in the family child ranges, all table-base xref sets, key constructor/destructor/paint/layout/input/thunk/destructor function extents, and the neighboring `SpelledPane`, `LegendPane`, and `CollectionPane` RTTI boundaries. `GroupListPane` remains unassigned because its child page was not refreshed above 85 completion in this batch.
