*** UID:0000G5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WillBeChangedItemPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), possibly split as `ui/controls/WillBeChangedPanes.cpp`
- Address range: [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_WillBeChangedItemPane.cpp`
- Confidence: strong.

## Class Purpose

`WillBeChangedItemPane` is a temporary item preview pane used while changing or dragging item slots. It renders the item icon, key binding, and item name in standard or compact display modes, tracks anchor/cursor deltas, and dismisses itself from input events.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WillBeChangedItemPane` | `0x004c78e0-0x004c7b76` | Constructs preview pane, writes [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md), resolves item slot data, computes icon bounds, and positions the pane. |
| `OnPaint` | `0x004c7bb0-0x004c7efd` | Draws icon, slot key, and item name. |
| `OnEvent` | `0x004c7f00-0x004c7f4e` | Handles cursor movement/dismissal behavior. |
| `OnKeyEvent` | `0x004c7f50-0x004c7f8f` | Dismisses on relevant key input. |
| `ScalarDeletingDestructor` | `0x004ce670-0x004ce6cf` | Clears singleton and tears down pane. |

## Evidence Notes

- IDA confirms the constructor and virtual function starts.
- IDA xrefs show the constructor called from `0x004ed40f`.
- This class is source-adjacent to help/tooltips but is specifically a temporary item change preview.
- 2026-05-26 IDA MCP storage check confirms [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md) as a 4-byte `.data` singleton adjacent to `g_pMetaMan`.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md)
- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:86`.
  - Summary/evidence: scored from the item preview constructor/paint/event/key/destructor map, singleton storage evidence, constructor xref, and help/tooltip source grouping caveat.
