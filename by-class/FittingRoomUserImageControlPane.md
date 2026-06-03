*** UID:000056 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomUserImageControlPane

## Status

- Confidence: strong for local preview-pane ownership and fitting-room source placement, medium-high for exact per-method internals because paint/timer bodies are still documented through the aggregate range rather than split memory pages.
- Current Wave3 file: `class_FittingRoomUserImageControlPane.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: Wave3 inspection, generated source, and IDA MCP checks on 2026-05-23 with `0x00495450` rechecked on 2026-05-25.
- Local core: [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md) records `0x00424300-0x004245f5` as the preview-pane constructor, paint, timer, direction-control, and destructor-wrapper block.
- Read-only data: [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md) records the fitting-room UI vtable block, including `FittingRoomUserImageControlPane`, as source-declared/generated-binary data owned by [UID:0000JE][FittingRoom](by-file/FittingRoom.md).

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

## Construction And Use Evidence

| Evidence | Detail |
| --- | --- |
| Source module | [UID:0000JE][FittingRoom](by-file/FittingRoom.md) lists this class as the fitting-room preview sprite panel with direction and timer-driven animation. |
| Constructor owner | [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) constructs the preview control from the current appearance block while building the dialog children. |
| Command callers | [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) gets child `1` and calls `0x00424550` for command `3` and `0x00424570` for command `4`. |
| Display path | [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md) refreshes fitting-room children before showing the preview dialog. |
| Vtable/literal island | [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md) places the class vtables with the fitting-room UI vtable block at `0x0060d9c4-0x0060e114`. |

## Boundary Cautions

- Wave3 also attaches a constructor-like function at `0x00495450`, but IDA MCP shows it is called only by `0x00517f30`, not by the fitting-room constructor. Decompilation shows a `ButtonControlPane` -> `TextButtonExControlPane` construction path with a text-provider child allocated through `0x00595390`; document it under [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md) / [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), not this preview pane.
- Simple setters at `0x00498bd0-0x00498c0e` and visibility/divider helpers at `0x005446b0`/`0x005862e0` should not be used as primary fitting-room anchors until reviewed.

## Reconstruction Notes

- This class is marked reconstructable because its source module, local code block, dialog construction path, command callers, and fitting-room vtable-data ownership are all documented through stable UID-linked evidence.
- `RECONSTRUCTION_CPP CODE` remains blank. A source-quality declaration still needs exact field names for the sprite/appearance, animation-frame, direction, and pane-state fields, plus a focused split of the constructor/paint/timer bodies into exact memory pages.
- Keep `0x00495450` and the `0x00498bd0-0x00498c0e` text-provider helpers out of this class until their generic `TextButtonExControlPane`/text-control ownership is resolved; the current fitting-room owner labels are polluted.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md)
- [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md)
- [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md)
- [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md)
- [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)

## Changes

- 2026-06-02: Raised `68/76` to `80/84`, marked reconstructable, and attached to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Added construction/use evidence, fitting-room vtable-data evidence, and reconstruction blockers while keeping `RECONSTRUCTION_CPP CODE` blank. Evidence: [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md), [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md), [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md), [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md), and [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md).
- 2026-05-27: Existing destructor range ended at `0x004245f4`. Changed it to `0x004245f5` because IDA MCP reports `sub_4245A0` size `0x55` from `0x004245a0`, and the final byte belongs to the `retn 4` instruction.
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: local fitting-room preview methods, role, and ownership cautions are documented, but attached generic helpers and full class contents are not fully settled. Evidence: confirmed local method cluster `0x00424300-0x004245f5`, IDA recheck note for `0x00495450`, and fitting-room core cross-reference.
