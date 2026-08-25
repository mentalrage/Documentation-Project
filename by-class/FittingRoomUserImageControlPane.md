*** UID:000056 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FittingRoomUserImageControlPane

## Status

- Confidence: strong for local preview-pane ownership, vtable identity, exact child ranges, direction-helper C++ readiness, and fitting-room source placement; medium-high for exact field names in constructor/paint/timer bodies.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: live IDA MCP checks and existing by-* support docs, including B003 current-session `80de0a67` split evidence on 2026-06-23. Historical recovered-output labels are treated only as naming leads, not as authority.
- Local core: [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md) now links exact preview-pane children [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md) through [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md) for the constructor, destructor body, paint, timer, direction controls, adjustor thunks, and scalar deleting destructor wrapper.
- Read-only data: [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md) records the fitting-room UI vtable block, including `FittingRoomUserImageControlPane`, as source-declared/generated-binary data owned by [UID:0000JE][FittingRoom](by-file/FittingRoom.md).

## Role

Preview image control for the fitting-room dialog. It displays and animates a user character sprite, supports direction changes, and participates in timer-driven preview animation.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md) | constructor | `0xb0` byte function. Called from `0x0041bfda`, initializes the preview pane, stores the sprite/appearance argument at `this + 0x108`, seeds fields at `+0x10c`, `+0x110`, and `+0x114 = 2`, starts the 300 ms timer on the adjusted pane view, installs vtables `0x0060e07c`/`0x0060e0e4`/`0x0060e114`, SHA16 `211386c0d3895ed1`, and keeps formal C++ blank until class/facet declarations are source-quality. |
| [UID:000576][0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody](by-memory/0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md) | non-deleting destructor body | Vtable restores and teardown call with no direct xrefs, SHA16 `854fe91dc4a6888f`; blank C++ because the source destructor obligation must not be emitted here and again through the scalar deleting wrapper. |
| [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md) | `OnPaint` | `0x12b` byte function with vtable cell `0x0060e0c0`, 10x10 tiled background draw, current appearance/direction render path, SHA16 `271d1481dfa9e04e`; blank C++ until render/global helper declarations are source-quality. |
| [UID:00041X][0x00505130-0x0050516a.MapPaneMapToScreenCoords](by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md) | `OnTimer` | `0x4e` byte timer method with vtable cell `0x0060e118`, timer id `0`, frame advance/wrap through `this+0x10c`, pause gate `this+0x110`, invalidate/reschedule path, SHA16 `254b7adb3e84b3c7`; blank C++ until adjusted TimerHandler source shape is safe. |
| [UID:00041Y][0x00505170-0x005051bb.MapPaneScreenToMapCoords](by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md) | `AdvanceFacingDirection` | 26-byte function called from [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) at `0x0041c486`; increments `m_facingDirection` and wraps values above `3` to `0`, SHA16 `a9205a0255299b43`, first-draft C++ populated. |
| [UID:00041Z][0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords](by-memory/0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords.md) | `RetreatFacingDirection` | 20-byte function called from [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) at `0x0041c49f`; decrements `m_facingDirection` and wraps negative values to `3`, SHA16 `c07d5af5eb4abdeb`, first-draft C++ populated. |
| [UID:0004WG][0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks](by-memory/0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md) | secondary/tertiary adjustor thunks | Two 11-byte compiler thunks from vtable cells `0x0060e0e4` and `0x0060e114` targeting the destructor path, SHA16 `0ba2e54363ffe97f`; nonreconstructable and blank C++. |
| [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md) | scalar deleting destructor wrapper | 85-byte wrapper with vtable data xref `0x0060e07c`, adjustor-thunk callers, vtable restores, teardown, conditional delete, SHA16 `1909c91c8a5203f1`; blank C++ as compiler scalar deleting wrapper. |

## Construction And Use Evidence

| Evidence | Detail |
| --- | --- |
| Source module | [UID:0000JE][FittingRoom](by-file/FittingRoom.md) lists this class as the fitting-room preview sprite panel with direction and timer-driven animation. |
| Constructor owner | [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) constructs the preview control from the current appearance block while building the dialog children. |
| Command callers | [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md) gets child `1` and calls `0x00424550` for command `3` and `0x00424570` for command `4`. |
| Display path | [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md) refreshes fitting-room children before showing the preview dialog. |
| Vtable/literal island | [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md) places the class vtables with the fitting-room UI vtable block at `0x0060d9c4-0x0060e114`. |

2026-06-14 live IDA MCP evidence:

- `lookup_funcs` confirms real function starts and sizes for constructor `0x00424300` size `0xb0`, paint `0x004243d0` size `0x12b`, timer `0x00424500` size `0x4e`, direction helpers `0x00424550` size `0x1a` and `0x00424570` size `0x14`, adjustor thunks at `0x00424584`/`0x0042458f`, and deleting-destructor wrapper `0x004245a0` size `0x55`.
- `analyze_function 0x00424300` shows the constructor is called from [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md) constructor `0x0041bdd0`, writes the three vtable views at `0x00424342`, `0x00424348`, and `0x00424352`, stores the sprite/appearance argument, initializes direction `2`, and starts a 300 ms timer.
- `trace_data_flow backward` from vtable heads `0x0060e07c`, `0x0060e0e4`, and `0x0060e114` confirms stores from the constructor, the local non-deleting reset body at `0x004243b0`, and the deleting destructor at `0x004245a0`; the secondary and tertiary vtable heads point to the `0x00424584` and `0x0042458f` adjustor thunks.
- `analyze_function` confirms `0x00424550` and `0x00424570` are directly called from [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md), matching rotate-forward command `3` and rotate-backward command `4`.

## Boundary Cautions

- Older recovered-output labels also attach a constructor-like function at `0x00495450`, but live IDA shows it is called only by `0x00517f30`, not by the fitting-room constructor. Decompilation shows a `ButtonControlPane` -> `TextButtonExControlPane` construction path with a text-provider child allocated through `0x00595390`; document it under [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md) / [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), not this preview pane.
- Simple setters at `0x00498bd0-0x00498c0e` and visibility/divider helpers at `0x005446b0`/`0x005862e0` should not be used as primary fitting-room anchors until reviewed.

## Reconstruction Notes

- This class is marked reconstructable because its source module, exact local child pages, dialog construction path, command callers, and fitting-room vtable-data ownership are all documented through stable UID-linked evidence.
- `RECONSTRUCTION_CPP CODE` remains blank at class level. Exact child pages now carry the implementation decisions: [UID:00041Y][0x00505170-0x005051bb.MapPaneScreenToMapCoords](by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md) and [UID:00041Z][0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords](by-memory/0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords.md) have first-draft direction-helper C++, while constructor, non-deleting destructor body, OnPaint, OnTimer, adjustor thunks, and scalar deleting destructor stay blank with target-specific no-code proofs.
- Keep `0x00495450` and the `0x00498bd0-0x00498c0e` text-provider helpers out of this class until their generic `TextButtonExControlPane`/text-control ownership is resolved; the current fitting-room owner labels are polluted.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page records exact child memory pages for constructor, destructor body, paint, timer, direction helpers, adjustor thunks, and scalar deleting destructor; constructor caller; rotate-command callers; vtable cells; child SHA16 values; false-anchor exclusion for `0x00495450`; fitting-room file ownership; and read-only-data support. Completion remains below 90 because exact field names for appearance, frame, direction, and pane/timer state in constructor/paint/timer bodies are still inferred. |
| Confidence `90` | Confidence is strong for [UID:0000JE][FittingRoom](by-file/FittingRoom.md) ownership because the constructor is called from `FittingRoomDialog`, rotate helpers are called from `FittingRoomDialog::OnCommand`, the vtables sit inside the fitting-room read-only data block, and B003 current-session child xrefs/bytes confirm every local subrange. It is not higher because generic recovered labels around `0x00495450`/text-provider helpers still need separate cleanup and non-direction field names remain inferred. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md)
- [UID:000576][0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody](by-memory/0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md)
- [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md)
- [UID:00041X][0x00505130-0x0050516a.MapPaneMapToScreenCoords](by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md)
- [UID:00041Y][0x00505170-0x005051bb.MapPaneScreenToMapCoords](by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md)
- [UID:00041Z][0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords](by-memory/0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords.md)
- [UID:0004WG][0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks](by-memory/0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md)
- [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md)
- [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md)
- [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md)
- [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md)
- [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md)
- [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)

## Changes

- 2026-06-23 B003 accepted split implementation: Raised from `85/87` to `87/90`; replaced the local-core aggregate rows with exact children [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md)/[UID:000576][0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody](by-memory/0x004243b0-0x004243cf.FittingRoomUserImageControlPaneNonDeletingDestructorBody.md)/[UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md)/[UID:00041X][0x00505130-0x0050516a.MapPaneMapToScreenCoords](by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md)/[UID:00041Y][0x00505170-0x005051bb.MapPaneScreenToMapCoords](by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md)/[UID:00041Z][0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords](by-memory/0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords.md)/[UID:0004WG][0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks](by-memory/0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md)/[UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md). Incorporated MCP `80de0a67` vtable cells `0x0060e07c`, `0x0060e0e4`, `0x0060e114`, paint slot `0x0060e0c0`, timer slot `0x0060e118`, direction callers `0x0041c486`/`0x0041c49f`, SHA16 values, and C++ policy: first-draft C++ only for [UID:00041Y][0x00505170-0x005051bb.MapPaneScreenToMapCoords](by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md) and [UID:00041Z][0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords](by-memory/0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords.md), blank C++ for constructor/paint/timer/destructor/thunks.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: scored `80/84`.
  - After: scored `85/87`; owner/emitter remains [UID:0000JE][FittingRoom](by-file/FittingRoom.md); final C++ remains blank below the active `90/90+` code-entry gate.
  - Evidence: live IDA MCP `lookup_funcs`, `analyze_component`, `analyze_function`, and vtable `trace_data_flow` confirmed all local method sizes, constructor caller `0x0041bdd0`, rotate-command callers in `0x0041c310`, three vtable heads/stores, adjustor thunks, deleting-destructor wrapper, and the `0x00495450` generic text-button false anchor.
- 2026-06-02: Raised `68/76` to `80/84`, marked reconstructable, and attached to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Added construction/use evidence, fitting-room vtable-data evidence, and reconstruction blockers while keeping `RECONSTRUCTION_CPP CODE` blank. Evidence: [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md), [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md), [UID:0002CQ][0x0041c310-0x0041c596.FittingRoomDialogOnCommand](by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md), [UID:0002CU][0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview](by-memory/0x0041cd40-0x0041cdbf.FittingRoomDialogShowPreview.md), and [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md).
- 2026-05-27: Existing destructor range ended at `0x004245f4`. Changed it to `0x004245f5` because IDA MCP reports `sub_4245A0` size `0x55` from `0x004245a0`, and the final byte belongs to the `retn 4` instruction.
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: local fitting-room preview methods, role, and ownership cautions are documented, but attached generic helpers and full class contents are not fully settled. Evidence: confirmed local method cluster `0x00424300-0x004245f5`, IDA recheck note for `0x00495450`, and fitting-room core cross-reference.
