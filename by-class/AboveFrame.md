*** UID:000005 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AboveFrame

## Status

- Confidence: strong for frame-chrome behavior, medium for final class name.
- Likely source file: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Address range: [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- Vtable/layout anchor: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md); exact data child [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- Autogen parent: [UID:0000JL][FrameChrome](by-file/FrameChrome.md).

## Class Purpose

`AboveFrame` is a `Pane`-derived frame chrome object. It loads one frame or tab piece from `FRMPART.EPF`, `TABS.EPF`, or legacy `FRMPART.EPD`, positions it at a supplied origin, registers for the shared `goog` notification, and draws the loaded tile with the appropriate palette.

## Observed State

Live IDA decompilation and linked layout pages support these object fields:

| Offset | Meaning |
| --- | --- |
| `+0x000` | primary Pane-derived object/vtable |
| `+0x0a0` | secondary vtable view |
| `+0x0a4` | tertiary vtable view |
| `+0x0f8` | `EPFTileContext`/tile context storage |
| `+0x108` | loaded frame rectangle/tile bounds |
| `+0x120` | positioned pane bounds |
| `+0x130` | frame/tab resource mode flag |

For frame indices below `4`, EPF mode loads `FRMPART.EPF`. For frame indices `4` and above, EPF mode loads `TABS.EPF`. Legacy mode loads `FRMPART.EPD`.

The visible frame objects are tracked through [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md). The `AboveFrame` slot family lives at [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md); a dynamic slot at `0x0067a840` is released/rebuilt by [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md) after general-purpose panel tab switches.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AboveFrame::AboveFrame` | `0x004610f0-0x00461299` | Initializes pane, loads frame/tab EPF/EPD resource, positions bounds, registers notification. |
| `~AboveFrame` | `0x004612a0-0x00461309` | Unregisters notification and destroys base pane. |
| `DrawFrame` | `0x00461660-0x004616af` | Selects `FRMPART.PAL`, `TABS.PAL`, or `NPAL5.PAL` and draws the tile. |
| `OnNotify` | `0x004616b0-0x004616c8` | Handles `goog` notification by destroying/dismissing itself. |
| `ScalarDeletingDestructor` | `0x004616e0-0x0046178a` | Destructor and optional delete wrapper. |

## Evidence Notes

- IDA MCP reports the factory at `0x00461310` calls the constructor nine times.
- IDA MCP reports `0x004615b0` releases the dynamic `AboveFrame` slot and the adjacent helper rebuilds it, despite the current misleading IDA name on the creator.
- 2026-06-04 exact xref recheck splits the ten direct constructor refs into nine from the border factory at `0x00461310` and one from the dynamic recreate helper at `0x004615d0`.
- IDA MCP confirms three `AboveFrame` vtable bases at `0x00610edc`, `0x00610f28`, and `0x00610f58`.
- 2026-05-31 IDA MCP proves exact vtable-data child [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md), starting at the primary RTTI locator and ending before UTF-16 `FRMPART.EPF` string data at `0x00610f60`.
- The address-like value `0x00520046` is adjacent UTF-16 `FRMPART.EPF` string data after the short tertiary vtable, not an `AboveFrame` method.
- Live IDA string decoding ties the class to `FRMPART.EPF`, `FRMPART.EPD`, `TABS.EPF`, `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL`.
- `EPFLibrary::LoadFrame`-style calls should be treated as `ResourceLayoutTable`/`g_pEPFLib` registry calls until an actual `EPFLibrary` class is proven.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md)
- [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md)
- [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md)
- [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

### 2026-06-04 - Live IDA refresh and parent assignment

- Before: score was `72/88`, autogen parent was blank, and the page still used stale recovered-source wording for layout evidence.
- Changed to: score is now `84/90`, attached to [UID:0000JL][FrameChrome](by-file/FrameChrome.md), and replaced stale source wording with live IDA offset/resource/vtable evidence.
- Summary/evidence: live IDA confirms constructor/destructor/draw/notify/scalar-deleting-destructor ranges, ten constructor call sites, vtable bases `0x00610edc/0x00610f28/0x00610f58`, offsets `+0xf8/+0x108/+0x120/+0x130`, resources `FRMPART.EPF`, `TABS.EPF`, `FRMPART.EPD`, palettes `FRMPART.PAL`, `TABS.PAL`, `NPAL5.PAL`, notification tag `goog`, and boundary padding.

- Before: the `AboveFrame` memory range and scalar deleting destructor ended at `0x00461789`.
- After: the range and scalar deleting destructor end at `0x0046178a`.
- Summary/evidence: IDA MCP reports the scalar deleting destructor as `0x004616e0-0x0046178a`; byte checks show `0x00461789` is part of the final return encoding and `0x0046178a-0x00461790` is padding.
- 2026-05-31:
  - Before: class metadata did not explicitly mark the class reconstructable, and vtable evidence named the bases without an exact `.rdata` child.
  - After: class metadata is reconstructable, scoring is `72/88`, and the exact vtable-data child [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) is linked.
  - Summary/evidence: IDA MCP dword and xref checks prove the exact RTTI/vtable span and exclude the adjacent UTF-16 `FRMPART.EPF` bytes from the vtable.
