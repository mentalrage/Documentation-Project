*** UID:0001XP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupPane Family Vtables

## Status

- Entity kind: vtable cluster.
- Covered classes: [UID:00005X][GroupListPane](by-class/GroupListPane.md), [UID:00005Y][GroupPane](by-class/GroupPane.md), [UID:00005Z][GroupPane2](by-class/GroupPane2.md), [UID:000090][NewGroupPane](by-class/NewGroupPane.md)
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
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

- 2026-05-31: Split exact vtable-data children and raised stale metadata from `0/0` to `84/88`.
  - Before: this page had strong slot notes but no completion/confidence score, and the group vtable rows were only described inside a broad mixed `.rdata` aggregate.
  - After: exact by-memory children document `GroupListPane`, `GroupPane`, `GroupPane2`, and `NewGroupPane` vtable data with RTTI boundary evidence; this page is marked reconstructable but still below final-audit scoring because final source-level virtual names and full class declarations remain incomplete.
  - Evidence: IDA MCP `py_eval` dword scan and `xrefs_to` checks on 2026-05-31 confirmed base stores, destructor/thunk targets, and next-class RTTI boundaries.
