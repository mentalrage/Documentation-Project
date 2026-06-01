*** UID:0000R9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pItemHelpPane

## Status

- Address: [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), or a split `ui/controls/ItemHelpPane.cpp`
- Current generated names: `g_pItemHelpPane`, `dword_69AE04`
- Confidence: strong.

## Purpose

`g_pItemHelpPane` points to the active [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), the rich item-tooltip popup. It is written by the constructor, cleared by destruction, and used by `DismissItemHelp` to close the active item tooltip.

## Evidence Notes

- IDA MCP storage check reports a 4-byte `.data` item at `0x0069ae04` with 20 data references.
- IDA MCP decompilation on 2026-05-27 confirms [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) closes this singleton through virtual slot `0` with flag `1` when it is non-null.
- 2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearItemHelpPaneSingleton` at `0x004ce310`, which writes zero to this storage from constructor/destructor unwind cleanup.
- `simroot_v2/class_ItemHelpPane.cpp` uses this storage as `g_pItemHelpPane`.
- Current `simroot_v2/class_ItemHelpPane.cpp` sets `g_pItemHelpPane = this` in `ItemHelpPane::ItemHelpPane` at generated line 32, clears it in `ItemHelpPane::~ItemHelpPane` at line 262, reads it in `ItemHelpPane::DismissItemHelp` at lines 610-612, and clears it again in `ItemHelpPane::ScalarDeletingDestructor` at line 1040.
- `simroot_v2/class_ItemHelpPane.meta_wave3` lists the active owner file as `class_ItemHelpPane.cpp`, active methods `0x004c82d0`, `0x004c8b20`, `0x004c8bd0`, `0x004ccc20`, `0x004ccc40`, `0x004ccc80`, `0x004ccca0`, `0x004ce100`, and `0x004ce430`, and includes `g_pItemHelpPane` in the active `global_data` partition.
- Source-map caveat: `class_ItemHelpPane.cpp.source_map.json` identifies `global-data:g_pItemHelpPane`, but its global-data lines have `missing_memory_range_line_count: 2`; the exact `0x0069ae04-0x0069ae08` storage claim therefore still comes from the IDA-backed by-memory/global documentation, not from the current source map alone.

## Cross-References

- [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)
- [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence header values despite documenting the storage address, singleton purpose, IDA-backed close/clear behavior, and generated-name usage.
- What changed: completion/confidence were raised to `82/85`, and the evidence notes now include current generated-code lifecycle writes/reads, active Wave3 partition data, and the source-map limitation for the global-data storage line.
- Summary and evidence: current generated `class_ItemHelpPane.cpp` confirms constructor, destructor, dismiss-helper, and scalar-deleting-destructor use of `g_pItemHelpPane`; existing by-memory docs provide the stronger IDA-backed `0x0069ae04-0x0069ae08` storage evidence. The score remains below near-complete because the page does not enumerate every one of the 20 IDA data references and the current source map does not bind the global-data comment directly to storage bytes.
