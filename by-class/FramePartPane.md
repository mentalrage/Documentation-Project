*** UID:00005I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FramePartPane

## Status

- Confidence: strong for behavior.
- Likely source file: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Address range: [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- Vtable/layout anchor: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md); exact data child [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- Current recovered file: `source-3/simroot_v2/class_FramePartPane.cpp`

## Class Purpose

`FramePartPane` is a smaller frame-border pane. It stores a frame-part index, positions itself from a provided rectangle, registers for the `goog` notification, and draws one `FRMPART.EPF` or `FRMPART.EPD` image.

The five active frame-part pointers are tracked in [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md). The notification handler clears those globals after dismissing the current pane; a separate raw cleanup body at [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) releases and clears all five slots.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `OnNotification` | `0x004b73b0-0x004b7401` | Handles `goog`, dismisses pane, and clears five global frame-part slots. |
| `OnPaintFrame` | `0x004b7410-0x004b7480` | Loads `FRMPART.EPF` or `FRMPART.EPD` and draws the image. |
| `FramePartPane::FramePartPane` | `0x004b7480-0x004b7515` | Constructs base pane, stores part index, sets bounds, registers notification. |
| `~FramePartPane` | `0x004b7520-0x004b758f` | Unregisters notification, detaches from layer, destroys base. |
| `ScalarDeletingDestructor` | `0x004b75b0-0x004b7660` | Destructor/delete wrapper. |

## Evidence Notes

- IDA MCP reports the factory at `0x004b7120` calls the constructor five times.
- IDA MCP reports no direct callers for the factory at `0x004b7120` in the current database, so live construction is still unresolved.
- The `goog` notification tag and `FRMPART` resources overlap strongly with `AboveFrame`.
- IDA MCP confirms three `FramePartPane` vtable bases at `0x0061a7fc`, `0x0061a848`, and `0x0061a878`; current generated metadata reports `vtable_count: 0`.
- 2026-05-31 IDA MCP proves exact vtable-data child [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md), starting at the primary RTTI locator and ending before non-vtable constant `0x0061a880` and `GeneralPurposePanel` RTTI at `0x0061a884`.
- 2026-05-26 IDA MCP recheck corrects the exact factory span to `0x004b7120-0x004b731f` end-exclusive, confirms `0x004b7320` remains not-a-function, and confirms the five `0x0069b33c-0x0069b34c` slot xrefs still split across factory writes, raw cleanup reads/clears, and `OnNotification` clears.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md)
- [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md)
- [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)
- [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md)
- [UID:000005][AboveFrame](by-class/AboveFrame.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/84`. Summary: frame-part role, global slot ownership, constructor/factory/destructor/paint/notification methods, vtable family, resource behavior, and unresolved live-construction caveat are documented; remaining uncertainty is exact construction reachability. Evidence: FramePartPane memory pages, slot globals, `FrameChromeVtableFamily`, factory/call notes, and `AboveFrame` overlap.
- 2026-05-31:
  - Before: class metadata did not explicitly mark the class reconstructable, and vtable evidence named the bases without an exact `.rdata` child.
  - After: class metadata is reconstructable, scoring is `84/88`, and the exact vtable-data child [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) is linked.
  - Summary/evidence: IDA MCP dword and xref checks prove the exact RTTI/vtable span and exclude the non-vtable constant at `0x0061a880` and next `GeneralPurposePanel` RTTI from the class vtable.
