*** UID:0000JL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FrameChrome

## Status

- Confidence: strong for `AboveFrame` and `FramePartPane` as visible UI frame chrome, medium for exact original filename.
- Proposed module: `ui/core/FrameChrome.cpp`, `ui/core/Frame.cpp`, or separate `AboveFrame.cpp` plus `FramePartPane.cpp`.
- Current recovered sources: `source-3/simroot_v2/class_AboveFrame.cpp` and `class_FramePartPane.cpp`
- Main address ranges: `0x004610f0-0x0046178a`, `0x004b7120-0x004b7661`
- Global slots: [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- Vtable/layout anchor: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md), with exact children [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)

## File Role

This module owns visible frame-border panes built from `FRMPART`, `TABS`, and palette resources. It is UI chrome code: it creates pane objects, positions them around the screen/dialog edge, registers for the shared notification tag `0x676f6f67` (`goog`), and draws frame-part EPF/EPD resources through the EPF resource registry.

This is distinct from [UID:0000JM][FrameMgr](by-file/FrameMgr.md), which schedules frame callbacks. It is also distinct from [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md), which owns the underlying resource registry and frame metadata loaders.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `AboveFrame` | `0x004610f0-0x0046178a` | Pane for a frame or tab border piece using `FRMPART.EPF`, `TABS.EPF`, or legacy `FRMPART.EPD`. |
| `BuildAboveFrameBorder` provisional | `0x00461310-0x004615aa` | Factory/helper that creates multiple `AboveFrame` instances and stores them in global frame slots. |
| `AboveFrame` refresh helpers | `0x004615b0-0x00461657` | Releases/rebuilds the dynamic `AboveFrame` slot used after side-panel tab switches. |
| `FramePartPane` | `0x004b73b0-0x004b7661` | Smaller frame-part pane used by a five-part border factory. |
| `BuildFramePartPanes` provisional | [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) | Factory/helper that creates five `FramePartPane` objects at fixed rectangles. |
| `FramePartPane` slot cleanup | `0x004b7320-0x004b73a3` | Raw cleanup body that releases and clears all five `FramePartPane` global slots. |

## Evidence Notes

- Wave3 notes say `AboveFrame` is a `Pane`-derived 572-byte object with an `EPFTileContext` at offset `0xf8` and frame data at `0x108`.
- IDA MCP confirms `BuildAboveFrameBorder` at `0x00461310` calls `AboveFrame::AboveFrame` nine times and has two direct callers from the map/game-server startup neighborhood at `0x004f7d10`.
- IDA MCP confirms `BuildFramePartPanes` at `0x004b7120` calls `FramePartPane::FramePartPane` five times and stores five global frame-part pointers.
- IDA MCP confirms [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) at `0x0067a834-0x0067a874` and [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md) at `0x0069b33c-0x0069b350`.
- The `AboveFrame` refresh helper pair at [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md) is called by [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) tab switches but still owns frame-chrome state.
- IDA currently reports no direct callers for `0x004b7120`; keep the five-part `FramePartPane` factory as retained or indirect frame-chrome construction until a live caller is found.
- Both classes use the same `goog` notification tag and the same `FRMPART` resource family, supporting a shared chrome/source-file hypothesis.
- IDA MCP confirms `AboveFrame` vtables at `0x00610edc`, `0x00610f28`, and `0x00610f58`, and `FramePartPane` vtables at `0x0061a7fc`, `0x0061a848`, and `0x0061a878`. Current generated metadata reports `vtable_count: 0` for both classes, so use [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) as the layout anchor.
- 2026-05-31 IDA MCP verifies exact vtable-data children [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md), including boundaries before `FRMPART.EPF` string data and `GeneralPurposePanel` RTTI.
- 2026-05-26 recheck using `simroot_v2` and IDA MCP only: `class_FramePartPane.cpp` still omits the raw cleanup body, `lookup_funcs` still reports `0x004b7320` as not-a-function, `callers 0x004b7120` is still empty, and `0x004615b0`/`0x004615d0` are still called from `GeneralPurposePanel` switch helpers at `0x004b8650` and `0x004b89a0`. 2026-05-28 byte review extends the current raw cleanup endpoint to `0x004b7320-0x004b73a3`.
- 2026-05-26 exact xref recheck: `AboveFrame::AboveFrame` has ten direct code refs in this chrome island: nine from `BuildAboveFrameBorder` and one from `0x004615d0`. The `BuildAboveFrameBorder` slot writes cover `0x0067a834`, `0x0067a838`, `0x0067a83c`, `0x0067a840`, `0x0067a848`, `0x0067a84c[]`, and `0x0067a860[]`.
- 2026-05-26 exact boundary recheck corrects `BuildFramePartPanes` to `0x004b7120-0x004b731f` end-exclusive. It writes the five `FramePartPane` slots at `0x0069b33c-0x0069b34c`; direct callers remain unresolved.
- 2026-05-28 IDA boundary check corrects `FramePartPane` to `0x004b73b0-0x004b7661`; byte `0x004b7660` is the final immediate byte of the scalar-deleting destructor's `retn 4`.

## Open Issues

- `class_AboveFrame.meta_wave3` has a bad summary and a disabled unrelated method at `0x00520046`; IDA shows this address-like value comes from `FRMPART.EPF` UTF-16 string bytes after the short tertiary vtable, while the real code address is inside `ArgumentedItemQuantityInputDialogPane::OnDialogAction`. See [wave3 data issues](../wave3_data_issues.md).
- `AboveFrame` and `FramePartPane` may represent old/new frame chrome implementations rather than two active implementations. Keep both documented together until callers and globals are reconciled.
- IDA labels the `0x004615d0-0x00461657` dynamic `AboveFrame` creator as `__std_parallel_algorithms_hw_threads`; decompilation shows frame-chrome behavior, so do not treat that label as standard-library ownership.
- Active `class_FramePartPane.cpp` omits the raw [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) body even though it reads and clears the same five global slots.

## Cross-References

- [UID:000005][AboveFrame](by-class/AboveFrame.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md)
- [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md)
- [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md)
- [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md)
- [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md)
- [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)
- [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md)
- [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the status kept the final filename/folder open.
  - Changed to: `NexusTK/ui/core/`.
  - Summary/evidence: the existing proposed source tree groups frame chrome under UI core, and IDA MCP recheck of the `FramePartPane` helper cluster confirms UI chrome behavior: fixed frame-part pane construction, global frame-part slot lifecycle, `FRMPART` resource use, and no evidence of ownership by MapPane, ResourceLayoutTable, or generic scheduler code.

- Before: `AboveFrame` was listed as `0x004610f0-0x00461789`.
- After: `AboveFrame` is listed as `0x004610f0-0x0046178a`.
- Summary/evidence: IDA MCP reports the scalar deleting destructor through `0x0046178a`; the following bytes `0x0046178a-0x00461790` are alignment padding before the AES helper island.
- Before: `FramePartPane` was listed as `0x004b73b0-0x004b7660`.
- After: `FramePartPane` is listed as `0x004b73b0-0x004b7661`.
- Summary/evidence: 2026-05-28 IDA MCP and raw-byte review show the scalar-deleting destructor's final instruction is `c2 04 00`, with byte `0x004b7660` as the final immediate byte; padding starts at `0x004b7661`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: visible frame chrome role, AboveFrame/FramePartPane grouping, factory/slot helpers, vtable/global anchors, old/new implementation caveats, generated metadata problems, and range corrections are documented; confidence remains at 80 because exact original filename and active use of the FramePartPane factory remain unresolved.
