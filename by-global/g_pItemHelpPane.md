*** UID:0000R9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pItemHelpPane

## Status

- Address: [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), or a split `ui/controls/ItemHelpPane.cpp`
- Observed aliases: `g_pItemHelpPane`, `dword_69AE04`
- Confidence: strong.

## Purpose

`g_pItemHelpPane` points to the active [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), the rich item-tooltip popup. It is written by the constructor, cleared by destruction, and used by `DismissItemHelp` to close the active item tooltip.

## Evidence Notes

- IDA MCP storage check reports a 4-byte `.data` item at `0x0069ae04` with 20 data references.
- IDA MCP decompilation on 2026-05-27 confirms [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) closes this singleton through virtual slot `0` with flag `1` when it is non-null.
- 2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearItemHelpPaneSingleton` at `0x004ce310`, which writes zero to this storage from constructor/destructor unwind cleanup.
- Live IDA MCP confirms constructor/destructor/clear-helper references, with the exact `0x0069ae04-0x0069ae08` storage claim coming from the IDA-backed by-memory/global documentation.

## Cross-References

- [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)
- [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence header values despite documenting the storage address, singleton purpose, and IDA-backed close/clear behavior.
- What changed: completion/confidence were raised to `82/85`, and the evidence notes now include lifecycle writes/reads plus the IDA storage binding.
- Summary and evidence: by-memory docs provide IDA-backed `0x0069ae04-0x0069ae08` storage evidence and the singleton lifecycle. The score remains below near-complete because the page does not enumerate every one of the 20 IDA data references.
- 2026-06-05: Marked reconstructable under [UID:0000JU][HelpPanes](by-file/HelpPanes.md). Evidence: live IDA MCP reports 20 xrefs to `0x0069ae04`; decompilation confirms clear helper `0x004ce310` and scalar deleting destructor `0x004ce430` clear `dword_69AE04`, with constructor/close-helper xrefs in the item help pane cluster.
