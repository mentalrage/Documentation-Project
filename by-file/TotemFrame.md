*** UID:0000OV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TotemFrame

## Status

- Confidence: strong for class behavior, medium for final feature-folder placement.
- Proposed module: `ui/panels/TotemFrame.cpp` or a private helper beside the old user-status/totem UI.
- Current recovered source: `source-3/simroot_v2/class_TotemFrame.cpp`
- Main address range: [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)

## File Role

`TotemFrame` is a feature-specific frame pane for the totem/status UI. It constructs a `Pane`, installs [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md), positions a 192-by-288 frame on the right side of the screen, loads `TOTFRAME.EPD`, and renders it using `NPAL7.PAL`. Its frame index comes from [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md).

It shares frame-resource concepts with [UID:0000JL][FrameChrome](by-file/FrameChrome.md), but the resource family and callers are totem/status-specific enough that it should remain a separate file unless later evidence shows a shared original `Frame.cpp`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TotemFrame` | `0x00598cc0-0x00598ecf` | Totem/status frame singleton pane, painting, cleanup helpers, destructor/delete wrapper. |
| [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md) | `0x0069b35c` | Singleton installed by constructor and cleared by cleanup/destructor helpers. |
| [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) | `0x0069b4ec` | Status-pane singleton read by `TotemFrame::OnPaint` to select the totem frame. |
| [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) | string evidence at `0x0062e460` and `0x006152ec` | Totem frame image and palette resources. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction and placement | `0x00598cc0` | Builds pane, stores singleton, installs vtables, and sets bounds `435,11,627,299`. |
| Cleanup | `0x00598da0`, `0x00598e40`, `0x00598e70` | Clears singleton and runs pane base cleanup. Active generated output omits the first two helpers. |
| Rendering | `0x00598dd0` | Gets a frame index from `OldUserStatusPane::GetSpiritId` and renders `TOTFRAME.EPD` with `NPAL7.PAL`. |
| Adjustor thunks | `0x00598e4b`, `0x00598e56` | Destructor thunks for secondary subobjects at offsets `0xa0` and `0xa4`. |

## Evidence Notes

- IDA MCP reports two direct constructor callers in the `0x005ba4a0` and `0x005bf7c0` old/new status-update feature neighborhoods.
- IDA MCP confirms `TotemFrame::OnPaint` reads `0x0069b4ec` and calls `0x005bdc60`, now documented as `OldUserStatusPane::GetSpiritId`.
- Generated `SpellOneArgInputPane.cpp` checks `g_pTotemFrame` and marks it for deletion, showing cross-feature lifecycle coupling.
- `OnPaint` loads `TOTFRAME.EPD` through `g_pEPFLib` and uses `NPAL7.PAL`.
- IDA confirms omitted cleanup body `0x00598da0`, singleton clear helper `0x00598e40`, and adjustor thunks `0x00598e4b` and `0x00598e56`.
- 2026-05-28 IDA MCP boundary recheck confirms `TotemFrame` code ends at `0x00598ecf`; `0x00598ecf-0x00598ed0` is one `0xcc` alignment byte, then `0x00598ed0` starts [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md).

## Cross-References

- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md)
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- 2026-05-28 boundary correction:
  - What existed before: file documentation used the memory range `0x00598cc0-0x00598ece`.
  - Changed to: file documentation uses `0x00598cc0-0x00598ecf`, with `0x00598ecf-0x00598ed0` treated as padding.
  - Summary/evidence: IDA MCP reports `sub_598E70` as ending at `0x00598ecf` and shows `0x00598ed0` as the next TransferServerDialogPane function start.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers totem/status frame role, proposed contents, singleton/status-pane dependencies, method families, IDA evidence, resource refs, boundary correction, and cross-references; confidence remains capped by final feature-folder placement.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TotemFrame.cpp` under `ui/panels`; IDA MCP confirms the compact `0x00598cc0-0x00598ecf` TotemFrame range and status-pane/totem ownership.
