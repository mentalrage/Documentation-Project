*** UID:000055 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomTextButtonControlPane

## Status

- Confidence: strong for the local fitting-room button cluster, medium for final base-class/source-shape details.
- Current Wave3 file: `class_FittingRoomTextButtonControlPane.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Local memory core: [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md)
- Evidence basis: linked IDA MCP evidence in fitting-room constructor/category/selection pages, FittingRoom UI aggregate, and read-only vtable data docs.

## Autogen Status

- Reconstructable: true. This is a source-owned fitting-room action/category button class.
- Autogen parent: [UID:0000JE][FittingRoom](by-file/FittingRoom.md). The file parent is high-confidence and has a valid proposed reconstruction path under `NexusTK/cashshop/`.
- Reconstruction status: no final C++ emitted yet. The exact base-class declaration, paint-frame constants, and field names are not final-source quality.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 72 | Local methods, owner module, exact memory core, category-button callers, selected-state caller, vtable block, duplicate-owner caveat, and reconstruction boundary are documented. |
| Confidence | 80 | Existing IDA-backed pages strongly tie the local cluster to fitting-room buttons; confidence remains capped by the current-session IDA MCP timeout and unresolved final class declaration details. |

## Role

Fitting-room action button control. Local methods initialize a resource-backed text button, draw the frame, and toggle enabled state.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00424020-0x0042405e` | constructor | Resource/position based control setup; called by dialog constructor and category-button rebuild paths. |
| `0x00424080-0x0042425c` | paint frame method | Draws fitting-room button frame. |
| `0x00424260-0x0042426f` | selected-state setter | Toggles selected/enabled visual state; called by the fitting-room dialog selected-button helper. |
| `0x00424270-0x0042427b` | adjustor thunk | Secondary-vtable `this - 0xa0` thunk to the deleting destructor wrapper; compiler-generated. |
| `0x00424290-0x004242e4` | scalar deleting destructor wrapper | Confirmed wrapper. |

## Evidence Notes

- [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md) is now the exact local-core memory page for this class.
- [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md) records IDA MCP callees to `0x00424020` and `0x00424260` while creating command IDs `7` through `16`.
- [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) records `0x00424260` as the only callee of the selected-button update path.
- [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md) places the class vtable in the fitting-room UI vtable block.
- A current direct IDA MCP refresh on 2026-06-02 timed out, so this update relies on already-written IDA MCP evidence and avoids final C++.

## Boundary Cautions

- Wave3 marks the class incomplete and includes generic event/motion helpers at `0x004a89f0` and `0x00544df0+`. Those are not strong fitting-room ownership evidence.
- Historical Wave2 notes identify the `0x00494f70` key handler as canonical [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) code, with `FittingRoomTextButtonControlPane` only a duplicate-shadow owner.
- Do not use the current auto grade alone for migration; use the confirmed local `0x00424020-0x004242e4` cluster first.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md)
- [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md)
- [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md)
- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `58/64`. Summary: local fitting-room button methods and ownership cautions are documented, but class contents are intentionally incomplete because generic event/motion helpers are not strong ownership evidence. Evidence: confirmed local cluster `0x00424020-0x004242e4` and documented boundary cautions against trusting current Wave3 ownership alone.

- 2026-06-02 exact local-core and autogen update:
  - What existed before: score was `58/64`, reconstructable and parent metadata were blank, and the class did not have an exact memory page.
  - Changed to: score is `72/80`, reconstructable is `TRUE`, parent is [UID:0000JE][FittingRoom](by-file/FittingRoom.md), and the class now links the exact local-core page.
  - Summary/evidence: existing IDA MCP evidence in the category-button rebuild and selected-button helper pages ties the constructor and selected-state helper to fitting-room behavior, while the read-only data page confirms the class vtable block. Fresh IDA MCP calls timed out, so final C++ remains blank.
