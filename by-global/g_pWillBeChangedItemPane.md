*** UID:0000SS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pWillBeChangedItemPane

## Status

- Address: [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), or a split `ui/controls/WillBeChangedPanes.cpp`
- Current generated names: `g_pWillBeChangedItemPane`, `dword_69B414`
- Confidence: strong for exact storage, lifecycle, class role, and owner family.
- Exact storage evidence: [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md) records a four-byte `.data` slot initialized to `0xffffffff`, with five direct data xrefs and separation from adjacent [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md).

## Purpose

`g_pWillBeChangedItemPane` points to the active [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md), the temporary item slot/change preview pane. It is distinct from adjacent metadata global storage and should stay with the tooltip/preview overlay family.

2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearWillBeChangedItemPaneSingleton` at `0x004ce340`, which writes zero to this storage from constructor/destructor unwind cleanup.

Treat the `0x0069b410-0x0069b418` adjacency as physical storage locality, not as source-level grouping with `MetaMan`. The declaration belongs with the help/tooltip temporary preview pane source family; the exact original split between `HelpPanes.cpp` and a possible `WillBeChangedPanes.cpp` remains open.

## Evidence Notes

- IDA MCP storage check reports a 4-byte `.data` item at `0x0069b414` with 5 data references.
- `simroot_v2/class_WillBeChangedItemPane.cpp` writes and clears this storage as `g_pWillBeChangedItemPane`.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0069b414` is a 4-byte `.data` item named `dword_69B414`, initialized to `0xffffffff`, with 5 data xrefs: constructor set/cleanup at `0x004c7939` and `0x004c7940`, event/destructor clear at `0x004c7b9a`, helper clear at `0x004ce340`, and scalar-deleting destructor clear at `0x004ce690`.
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md) records the item preview constructor, non-deleting reset body, paint path, event and key dismissal handlers, sibling spell-preview pane, exact padding, and constructor caller `0x004ed40f`.
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) records the `WillBeChangedItemPane` adjustor thunks and scalar deleting destructor at `0x004ce670-0x004ce6cf`, including the singleton clear at `0x004ce690`.
- [UID:00025G][0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData](by-memory/0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData.md) records the `WillBeChangedItemPane` vtables in the help/item-help read-only data span.

## Cross-References

- [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:00025G][0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData](by-memory/0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData.md)
- [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)

## Changes

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and ordered file-local position `70`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/helper clears, and separation from adjacent `g_pMetaMan`; final C++ remains blank because the exact split between `HelpPanes.cpp` and a possible `WillBeChangedPanes.cpp` is still open.
- 2026-06-06: Raised `COMPLETION` from `74` to `86` and `CONFIDENCE` from `86` to `89`.
  - Added current exact storage evidence, preview-pane executable range support, destructor/thunk support, read-only vtable evidence, and a source-adjacency caveat separating this slot from `g_pMetaMan`.
  - Evidence: existing IDA-backed docs now account for the singleton slot in [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md), the item/spell preview code range in [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), destructor behavior in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md), vtables in [UID:00025G][0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData](by-memory/0x0061aad4-0x0061b344.HelpItemHelpReadOnlyData.md), and source-family ownership in [UID:0000JU][HelpPanes](by-file/HelpPanes.md). Final C++ remains blank because the final source split and class-layout/member names are below the 95/95 threshold.
