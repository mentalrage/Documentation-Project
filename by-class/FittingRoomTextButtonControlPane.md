*** UID:000055 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:58 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomTextButtonControlPane

## Status

- Confidence: medium for fitting-room button behavior, low for current complete class contents.
- Current Wave3 file: `class_FittingRoomTextButtonControlPane.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: Wave3 inspection and IDA MCP checks on 2026-05-23.

## Role

Fitting-room action button control. Local methods initialize a resource-backed text button, draw the frame, and toggle enabled state.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00424020-0x0042405e` | constructor | Resource/position based control setup. |
| `0x00424080-0x0042425c` | `OnPaintFrame` | Draws fitting-room button frame. |
| `0x00424260-0x0042426f` | `SetEnabled` | Toggles enabled state. |
| `0x00424290-0x004242e4` | scalar deleting destructor wrapper | Confirmed wrapper. |

## Boundary Cautions

- Wave3 marks the class incomplete and includes generic event/motion helpers at `0x004a89f0` and `0x00544df0+`. Those are not strong fitting-room ownership evidence.
- Do not use the current auto grade alone for migration; use the confirmed local `0x00424020-0x004242e4` cluster first.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `58/64`. Summary: local fitting-room button methods and ownership cautions are documented, but class contents are intentionally incomplete because generic event/motion helpers are not strong ownership evidence. Evidence: confirmed local cluster `0x00424020-0x004242e4` and documented boundary cautions against trusting current Wave3 ownership alone.
