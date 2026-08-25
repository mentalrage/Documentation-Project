*** UID:0001XO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FrameChrome Vtable Family

## Status

- Disposition: reviewed non-emitting vtable-family index. The reconstructable source-owned table groups are split into [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md).
- Covered source owner: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Covered classes: [UID:000005][AboveFrame](by-class/AboveFrame.md) and [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- Exact memory children: [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md).
- Confidence: very strong for table bases, constructor/destructor stores, adjustor thunks, exact child ranges, unique signatures, and the mixed-direct-owner/non-emitting assignment decision; medium-high for whether both classes lived in one original source file.
- Verification: IDA MCP `list_globals`, `xrefs_to`, `lookup_funcs`, `disasm`, `py_eval`, `entity_query`, `trace_data_flow`, and `make_signature_for_range` checks on 2026-05-26, 2026-05-31, A005's 2026-06-11 parent-gate refresh, and A004's 2026-06-12 split refresh. Current `simroot_v2` metadata reports `vtable_count: 0` for both checked classes.

## Table Bases

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Proposed file |
| --- | --- | --- | --- | --- |
| `AboveFrame` | `0x00610edc` | `0x00610f28` | `0x00610f58` | [UID:0000JL][FrameChrome](by-file/FrameChrome.md) |
| `FramePartPane` | `0x0061a7fc` | `0x0061a848` | `0x0061a878` | [UID:0000JL][FrameChrome](by-file/FrameChrome.md) |

## Source-Local Split Pages

This aggregate is not a source-emitting object because it spans two direct class owners. The source-owned vtable documentation is carried by these exact children:

| Child | Direct parent | Backing memory | Gate result |
| --- | --- | --- | --- |
| [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) | [UID:000005][AboveFrame](by-class/AboveFrame.md) | [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) | child `88/93`; direct parent `85/90` |
| [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) | [UID:00005I][FramePartPane](by-class/FramePartPane.md) | [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) | child `89/93`; direct parent `85/89` |

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
- 2026-06-11 A005 live IDA MCP refresh reconfirmed all six table bases and the exact child boundaries:
  - `AboveFrame` function boundaries remain `0x004610f0-0x00461299`, `0x004612a0-0x00461309`, `0x00461660-0x004616af`, `0x004616b0-0x004616c8`, adjustor thunks `0x004616c8-0x004616de`, and scalar deleting destructor `0x004616e0-0x0046178a`.
  - `FramePartPane` function boundaries remain `0x004b73b0-0x004b7401`, `0x004b7410-0x004b7480`, `0x004b7480-0x004b7515`, `0x004b7520-0x004b7590`, adjustor thunks `0x004b7590-0x004b75a6`, and scalar deleting destructor `0x004b75b0-0x004b7661`.
  - `xrefs_to` reports constructor/destructor/scalar-destructor stores to each vtable base, and `py_eval` reconfirms the `0x00610f60` UTF-16 `FRMPART.EPF` boundary plus the `0x0061a880` constant / `0x0061a884` `GeneralPurposePanel` boundary.
  - Factory/caller checks still show `BuildAboveFrameBorder` called from `0x004f7d10` at `0x004f802c` and `0x004f8670`, dynamic `AboveFrame` refresh helpers called from `0x004b8650` and `0x004b89a0`, and no direct caller for `BuildFramePartPanes`.
- 2026-06-12 A004 live IDA MCP split refresh used session `b001_nexustk` and reconfirmed the aggregate as two class-owned clusters:
  - `entity_query 0x00610ed8-0x00610f70` reports `??_7AboveFrame@@6B@` at `0x00610edc`, `??_7AboveFrame@@6B@_0` at `0x00610f28`, `??_7AboveFrame@@6B@_1` at `0x00610f58`, and successor string name `aMpartEpf` at `0x00610f64`.
  - `entity_query 0x0061a7f8-0x0061a890` reports `??_7FramePartPane@@6B@` at `0x0061a7fc`, `??_7FramePartPane@@6B@_0` at `0x0061a848`, `??_7FramePartPane@@6B@_1` at `0x0061a878`, and successor `??_7GeneralPurposePanel@@6B@` at `0x0061a888`.
  - `lookup_funcs` reconfirmed `AboveFrame` slot targets `0x004616e0`, `0x004616b0`, `0x00461660`, `0x004616c8`, `0x004616d3`, and `0x00544e90`, and `FramePartPane` slot targets `0x004b75b0`, `0x004b73b0`, `0x004b7410`, `0x004b7590`, `0x004b759b`, and `0x00544e90`.
  - `trace_data_flow backward` reconfirmed `AboveFrame` primary/secondary/tertiary vptr stores at `0x00461139`/`0x0046113f`/`0x00461149`, `0x004612cc`/`0x004612d2`/`0x004612dc`, and `0x0046170c`/`0x00461712`/`0x0046171c`; it reconfirmed `FramePartPane` stores at `0x004b74b5`/`0x004b74bb`/`0x004b74c5`, `0x004b754c`/`0x004b7552`/`0x004b755c`, and `0x004b75dc`/`0x004b75e2`/`0x004b75ec`.
  - `trace_data_flow backward 0x00610f60` reports `FRMPART.EPF` successor refs from `0x00461178` and `0x004b7446`; `trace_data_flow backward 0x0061a880` reports `dword_61A880 == 0x3e800000` refs at `0x004b7b15` and `0x004b7b43`, excluding both successors from vtable ownership.
  - `make_signature_for_range` produced unique signatures for the exact `0x00610ed8-0x00610f60` and `0x0061a7f8-0x0061a880` clusters.

## Assignment Gate

`AUTOGEN_PARENT_UID` intentionally remains blank and `RECONSTRUCTABLE` is `FALSE` for this aggregate. This page is a reviewed vtable-family index spanning two direct class owners, [UID:000005][AboveFrame](by-class/AboveFrame.md) and [UID:00005I][FramePartPane](by-class/FramePartPane.md), so assigning or emitting the aggregate would misstate ownership. The strict child/direct-parent gate is satisfied through source-local children instead: [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) attaches to [UID:000005][AboveFrame](by-class/AboveFrame.md) at child `88/93` and parent `85/90`, and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) attaches to [UID:00005I][FramePartPane](by-class/FramePartPane.md) at child `89/93` and parent `85/89`. The shared [UID:0000JL][FrameChrome](by-file/FrameChrome.md) source root remains context at `86/85`.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for `AboveFrame` and `FramePartPane`. `AboveFrame` also carries a disabled `0x00520046` row; IDA evidence shows that address-like value comes from UTF-16 string data after the short tertiary table, while the real code address is inside `ArgumentedItemQuantityInputDialogPane::OnDialogAction`. This is tracked in [wave3 data issues](../../wave3_data_issues.md).

## Cross-References

- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md)
- [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)

## UID0000JL Accepted Split Incorporation - 2026-08-25

- This remains a mixed, non-emitting semantic index only. Exact source-local children are [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) through [UID:000577][AboveFrame](by-file/AboveFrame.md), and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) through [UID:000578][FramePartPane](by-file/FramePartPane.md).
- The two RTTI/vtable families are disjoint (`0x00610ed8-0x00610f60` and `0x0061a7f8-0x0061a880`), have independent lifecycle stores and slot targets, and do not support a shared handwritten FrameChrome table declaration.
- `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal source remain correct. All compiler-generated tables arise from the two class declarations.

## Changes

- 2026-08-25 UID0000JL callback: preserved the mixed-index metadata and `89/93` score while replacing the historical one-file implication with exact class-centered source routes.

- 2026-05-31:
  - Before: metadata was unevaluated and the family page had table-base evidence but no exact vtable-data child pages.
  - Changed to: scored as `84/88`, marked reconstructable, and linked exact children [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md).
  - Summary/evidence: IDA MCP xrefs and dword scans verify all six table bases, constructor/destructor store sites, adjustor thunk slots, notification/paint slots, and exact boundaries before adjacent string/constant/next-class data.
- 2026-06-11 A005 parent-gate refresh:
  - Before: the family page was still unassigned without a clear mixed-owner rationale, and both exact vtable-data children were blocked by class/file parent scores below the strict gate.
  - Changed to: completion/confidence are `85/90`, the aggregate `AUTOGEN_PARENT_UID` stays blank by design, and the exact child pages now attach to their direct class owners.
  - Summary/evidence: live IDA MCP reconfirmed all six vtable bases, constructor/destructor/scalar-destructor store xrefs, slot-target refs, exact function boundaries, factory/caller state, and adjacent data boundaries; [UID:000005][AboveFrame](by-class/AboveFrame.md), [UID:00005I][FramePartPane](by-class/FramePartPane.md), and [UID:0000JL][FrameChrome](by-file/FrameChrome.md) now clear the strict parent chain.
- 2026-06-12 A004 Batch 323 split:
  - Before: [UID:0001XO] was still marked reconstructable at `85/90` even though it spanned `AboveFrame` and `FramePartPane` direct owners.
  - Changed to: [UID:0001XO] is `89/93`, `RECONSTRUCTABLE:FALSE`, and parentless as a non-emitting mixed-owner index; source-local children [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) carry the reconstructable class routes.
  - Summary/evidence: live IDA MCP `entity_query`, `lookup_funcs`, `trace_data_flow`, and `make_signature_for_range` reconfirmed both exact clusters, decorated bases, slot target sizes, lifecycle vptr stores, unique signatures, and the `FRMPART.EPF`/`0x0061a880` successor boundaries.
