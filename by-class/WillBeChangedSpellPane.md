*** UID:0000G6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WillBeChangedSpellPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), possibly split as `ui/controls/WillBeChangedPanes.cpp`
- Address range: [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_WillBeChangedSpellPane.cpp`
- Confidence: strong.

## Class Purpose

`WillBeChangedSpellPane` is a temporary spell preview pane used while changing spell slots. It points into the player spell table, draws the slot key and spell name, tracks cursor-relative movement, and dismisses on relevant mouse or key input.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WillBeChangedSpellPane` | `0x004c7f90-0x004c80c0` | Constructs preview pane, resolves spell-slot record, sizes a 160-pixel text row, and positions the pane. |
| `OnPaint` | `0x004c80e0-0x004c824d` | Draws key binding and spell name. |
| `HandleMouseInput` | `0x004c8250-0x004c828a` | Dismisses or moves the pane based on mouse event type. |
| `HandleKeyInput` | `0x004c8290-0x004c82cf` | Dismisses on key input. |
| `ScalarDeletingDestructor` | `0x004ce6d0-0x004ce725` | Tears down pane and optionally deletes storage. |

## Evidence Notes

- IDA confirms the constructor and virtual function starts.
- IDA xrefs show the constructor called from `0x0057df03`.
- This class is paired with [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md) by purpose and memory locality.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:0000DN][SpellInventoryPane](by-class/SpellInventoryPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the spell preview constructor/paint/mouse/key/destructor map, constructor xref, paired item-preview locality, and help/tooltip source grouping caveat.
