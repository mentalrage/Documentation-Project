*** UID:0000PN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FrameChromeSlots

## Status

- Confidence: strong for the two observed slot clusters and their factory/cleanup writers; medium for final source-level names and full neighboring-global separation.
- Likely owner file: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Vtable/layout anchor: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- Related memory docs: [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md), [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md), and [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)

## Role

The frame chrome code keeps global pointers to visible frame-border pane objects. There are two related but distinct slot families:

| Slot family | Data range | Object type | Builder / users |
| --- | --- | --- | --- |
| `AboveFrame` slots | `0x0067a834-0x0067a874` | [UID:000005][AboveFrame](by-class/AboveFrame.md) pointers and two five-entry pointer arrays | Built by [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md); refreshed by [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md); called from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) tab switches. |
| `FramePartPane` slots | `0x0069b33c-0x0069b350` | Five [UID:00005I][FramePartPane](by-class/FramePartPane.md) pointers | Built by [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md); cleared by `FramePartPane::OnNotification` and by [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md). |

## Ownership Decision

Keep these globals with frame/chrome source, not with [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), or generic pane-manager source. General-purpose panel switches call the refresh helpers, but they do not own the frame objects or the slot storage.

## IDA MCP Evidence

Checked on 2026-05-25 and rechecked on 2026-05-26:

- `xrefs_to 0x0069b33c-0x0069b34c` shows writes from `0x004b7120`, clears from raw cleanup bytes at `0x004b7320-0x004b73a3`, and clears from `FramePartPane::OnNotification` at `0x004b73b0`.
- `xrefs_to 0x0067a834-0x0067a860` shows writes from `BuildAboveFrameBorder` at `0x00461310`. `0x0067a840` also has cleanup/refresh xrefs from `0x004615b0` and the adjacent dynamic-create helper currently mislabeled by IDA as `__std_parallel_algorithms_hw_threads`.
- `callers 0x00461310` reports two calls inside `0x004f7d10`, matching main UI graph setup. `callers 0x004b7120` currently reports no direct callers, so the five-part `FramePartPane` factory remains a retained or indirect construction path until a caller is recovered.
- `callers 0x004615b0` and `callers 0x004615d0` both report the general-panel switch functions `0x004b8650` and `0x004b89a0`; those calls are dependencies on frame-chrome state, not ownership evidence for the globals.
- 2026-05-30 IDA MCP `xrefs_to 0x0067a840` confirms dynamic `AboveFrame` slot writes from `BuildAboveFrameBorder`, delete/read at `0x004615b0`, recreate write at `0x0046162b`, and allocation-failure clear at `0x0046163f`.
- 2026-05-30 IDA MCP `xrefs_to 0x0069b33c` confirms the `FramePartPane` slot start is written by `0x004b7120`, referenced by raw cleanup bytes at `0x004b7320`/`0x004b7330`, and cleared by `FramePartPane::OnNotification` at `0x004b73cb`.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:000005][AboveFrame](by-class/AboveFrame.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `76/84`. Previously this overview had strong content but no score; it now records current IDA MCP xrefs for the dynamic `AboveFrame` slot and `FramePartPane` slot start while retaining the final-name and neighboring-global caveats.
