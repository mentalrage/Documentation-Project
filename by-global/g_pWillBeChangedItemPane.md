*** UID:0000SS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: strong.

## Purpose

`g_pWillBeChangedItemPane` points to the active [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md), the temporary item slot/change preview pane. It is distinct from adjacent metadata global storage and should stay with the tooltip/preview overlay family.

2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearWillBeChangedItemPaneSingleton` at `0x004ce340`, which writes zero to this storage from constructor/destructor unwind cleanup.

## Evidence Notes

- IDA MCP storage check reports a 4-byte `.data` item at `0x0069b414` with 5 data references.
- `simroot_v2/class_WillBeChangedItemPane.cpp` writes and clears this storage as `g_pWillBeChangedItemPane`.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0069b414` is a 4-byte `.data` item named `dword_69B414`, initialized to `0xffffffff`, with 5 data xrefs: constructor set/cleanup at `0x004c7939` and `0x004c7940`, event/destructor clear at `0x004c7b9a`, helper clear at `0x004ce340`, and scalar-deleting destructor clear at `0x004ce690`.

## Cross-References

- [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)

## Changes

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and ordered file-local position `70`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/helper clears, and separation from adjacent `g_pMetaMan`; final C++ remains blank because the exact split between `HelpPanes.cpp` and a possible `WillBeChangedPanes.cpp` is still open.
