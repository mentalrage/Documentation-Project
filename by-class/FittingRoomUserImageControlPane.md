*** UID:000056 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomUserImageControlPane

## Status

- Confidence: strong for local preview-pane methods, medium for all currently attached methods.
- Current Wave3 file: `class_FittingRoomUserImageControlPane.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: Wave3 inspection, generated source, and IDA MCP checks on 2026-05-23 with `0x00495450` rechecked on 2026-05-25.

## Role

Preview image control for the fitting-room dialog. It displays and animates a user character sprite, supports direction changes, and participates in timer-driven preview animation.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00424300-0x004243af` | constructor | Initializes preview pane with sprite ID and bounds. |
| `0x004243d0-0x004244fa` | `OnPaint` | Draws preview image/background. |
| `0x00424500-0x0042454d` | `OnTimer` | Advances preview animation. |
| `0x00424550-0x00424569` | `AdvanceFacingDirection` | Rotates preview forward. |
| `0x00424570-0x00424583` | `RetreatFacingDirection` | Rotates preview backward. |
| `0x004245a0-0x004245f5` | scalar deleting destructor wrapper | Confirmed wrapper. |

## Boundary Cautions

- Wave3 also attaches a constructor-like function at `0x00495450`, but IDA MCP shows it is called only by `0x00517f30`, not by the fitting-room constructor. Decompilation shows a `ButtonControlPane` -> `TextButtonExControlPane` construction path with a text-provider child allocated through `0x00595390`; document it under [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md) / [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), not this preview pane.
- Simple setters at `0x00498bd0-0x00498c0e` and visibility/divider helpers at `0x005446b0`/`0x005862e0` should not be used as primary fitting-room anchors until reviewed.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-05-27: Existing destructor range ended at `0x004245f4`. Changed it to `0x004245f5` because IDA MCP reports `sub_4245A0` size `0x55` from `0x004245a0`, and the final byte belongs to the `retn 4` instruction.
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: local fitting-room preview methods, role, and ownership cautions are documented, but attached generic helpers and full class contents are not fully settled. Evidence: confirmed local method cluster `0x00424300-0x004245f5`, IDA recheck note for `0x00495450`, and fitting-room core cross-reference.
