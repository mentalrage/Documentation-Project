*** UID:0001XO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FrameChrome Vtable Family

## Status

- Disposition: vtable family inventory for reconstructable frame-chrome pane code.
- Covered source owner: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Covered classes: [UID:000005][AboveFrame](by-class/AboveFrame.md) and [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- Exact memory children: [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md).
- Confidence: strong for table bases, constructor/destructor stores, and adjustor thunks; medium for whether both classes lived in one original source file.
- Verification: IDA MCP `list_globals`, `xrefs_to`, `lookup_funcs`, `disasm`, and `py_eval` checks on 2026-05-26. Current `simroot_v2` metadata reports `vtable_count: 0` for both checked classes.

## Table Bases

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Proposed file |
| --- | --- | --- | --- | --- |
| `AboveFrame` | `0x00610edc` | `0x00610f28` | `0x00610f58` | [UID:0000JL][FrameChrome](by-file/FrameChrome.md) |
| `FramePartPane` | `0x0061a7fc` | `0x0061a848` | `0x0061a878` | [UID:0000JL][FrameChrome](by-file/FrameChrome.md) |

## Slot Evidence

- `AboveFrame` primary slot `+0x00` points to scalar deleting destructor `0x004616e0`; slot `+0x08` points to notification handler `0x004616b0`.
- `AboveFrame` secondary slot `+0x00` points to adjustor thunk `0x004616c8`, which subtracts `0xa0` and jumps to `0x004616e0`.
- `AboveFrame` tertiary slot `+0x00` points to adjustor thunk `0x004616d3`, which subtracts `0xa4` and jumps to `0x004616e0`.
- `FramePartPane` primary slot `+0x00` points to scalar deleting destructor `0x004b75b0`; slot `+0x08` points to notification handler `0x004b73b0`.
- `FramePartPane` secondary slot `+0x00` points to adjustor thunk `0x004b7590`, which subtracts `0xa0` and jumps to `0x004b75b0`.
- `FramePartPane` tertiary slot `+0x00` points to adjustor thunk `0x004b759b`, which subtracts `0xa4` and jumps to `0x004b75b0`.

The tertiary table extents are short. For `AboveFrame`, the dword at `0x00610f60` decodes as UTF-16 `FR` and begins the adjacent `FRMPART.EPF` string, not a vtable slot. For `FramePartPane`, the dword after the known tertiary slots is adjacent non-FramePartPane data. Do not treat those neighbors as frame-chrome virtual methods.

## Layout Evidence

- IDA `xrefs_to` shows `AboveFrame` constructor, destructor helper, and scalar deleting destructor store all three `AboveFrame` vtable bases.
- IDA `xrefs_to` shows `FramePartPane` constructor, destructor helper, and scalar deleting destructor store all three `FramePartPane` vtable bases.
- 2026-05-31 IDA MCP `py_eval` proves exact vtable-data children:
  - [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) starts at `AboveFrame` primary RTTI and stops before UTF-16 `FRMPART.EPF` string bytes at `0x00610f60`.
  - [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) starts at `FramePartPane` primary RTTI and stops before the non-vtable constant at `0x0061a880` and `GeneralPurposePanel` RTTI at `0x0061a884`.
- Both classes share the same pane-base three-view pattern, the `goog` notification tag, and `FRMPART` resource family, supporting [UID:0000JL][FrameChrome](by-file/FrameChrome.md) as the current source-module owner.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for `AboveFrame` and `FramePartPane`. `AboveFrame` also carries a disabled `0x00520046` row; IDA evidence shows that address-like value comes from UTF-16 string data after the short tertiary table, while the real code address is inside `ArgumentedItemQuantityInputDialogPane::OnDialogAction`. This is tracked in [wave3 data issues](../../wave3_data_issues.md).

## Cross-References

- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md)
- [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)

## Changes

- 2026-05-31:
  - Before: metadata was unevaluated and the family page had table-base evidence but no exact vtable-data child pages.
  - Changed to: scored as `84/88`, marked reconstructable, and linked exact children [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md).
  - Summary/evidence: IDA MCP xrefs and dword scans verify all six table bases, constructor/destructor store sites, adjustor thunk slots, notification/paint slots, and exact boundaries before adjacent string/constant/next-class data.
