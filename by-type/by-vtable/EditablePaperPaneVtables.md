*** UID:0001XF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EditablePaperPane Vtables

## Status

- Disposition: vtable inventory for reconstructable paper-dialog pane code.
- Covered source owner: [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- Covered class: [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md)
- Exact memory data: [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md)
- Confidence: strong for table bases, constructor stores, callback slots, adjustor thunks, and short tertiary-table extent.
- Verification: IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, `strings`, and `py_eval` checks on 2026-05-31.

## Table Bases

| Object offset | Vtable symbol | Address | First slot | Notes |
| --- | --- | --- | --- | --- |
| `+0x00` | `??_7EditablePaperPane@@6B@` | `0x00621afc` | `0x00545e00` | Primary `DialogPane` view with paper-specific drawing/action callbacks. |
| `+0xa0` | `??_7EditablePaperPane@@6B@_0` | `0x00621b60` | `0x00545ddd` | Secondary handler view; destructor adjustor subtracts `0xa0`. |
| `+0xa4` | `??_7EditablePaperPane@@6B@_1` | `0x00621b90` | `0x00545de8` | Tertiary handler view; destructor adjustor subtracts `0xa4`. |

## Slot Evidence

| Table | Slot | Target | Interpretation |
| --- | --- | --- | --- |
| primary | `+0x00` | `0x00545e00` | `EditablePaperPane` scalar deleting destructor. |
| primary | `+0x30` | `0x0049dfd0` | Inherited `DialogPane::OnCreate`. |
| primary | `+0x38` | `0x0049e1c0` | Inherited `DialogPane::OnDestroy`. |
| primary | `+0x3c` | `0x0049e190` | Inherited `DialogPane::OnShow`. |
| primary | `+0x40` | `0x0049e210` | Inherited `DialogPane::OnHide`. |
| primary | `+0x44` | `0x0049f090` | Inherited dialog focus/border drawing helper. |
| primary | `+0x48` | `0x00545220` | `EditablePaperPane::OnDialogAction`; saves editable paper and dismisses on action `0`. |
| primary | `+0x50` | `0x00545d50` | `EditablePaperPane::DrawBackground`; draws `LINE001.EPD` frame `8`. |
| primary | `+0x54` | `0x005459b0` | `EditablePaperPane::DrawBorder`; tiles `LINE001.EPD` border frames. |
| primary | `+0x58` | `0x0049fc00` | Inherited `DialogPane::SetHoverControl`. |
| primary | `+0x5c` | `0x00545250` | `EditablePaperPane::InitializePaperContent`; creates text edit control and opens the pane. |
| secondary | `+0x00` | `0x00545ddd` | Adjustor thunk subtracting `0xa0`, then jumping to `0x00545e00`. |
| secondary | `+0x04` through `+0x28` | `0x0049e240`, `0x0049e6e0`, `0x0049ea60`, `0x0041d6b0`, `0x00544df0`, `0x00544e00`, `0x004a89f0`, `0x00544e10`, `0x00544e30`, `0x00544e70` | Inherited dialog/event-handler slots. |
| tertiary | `+0x00` | `0x00545de8` | Adjustor thunk subtracting `0xa4`, then jumping to `0x00545e00`. |
| tertiary | `+0x04` | `0x00544e90` | Inherited handler-interface slot. |

Do not read the tertiary table past slot `+0x04`. The dword at `0x00621b98` begins adjacent `LINE001.EPD` string/data, not another `EditablePaperPane` virtual. The following dword at `0x00621b9c` decodes as `0x0045004e`, an interior address in the LodePNG lower-bound helper; this is string/data adjacency, not a paper-pane vtable slot.

## Constructor Store Evidence

IDA `xrefs_to` reports all three vtable bases written from the constructor:

- Constructor `0x00545170`: writes primary at `0x005451b7`, secondary at `0x005451bd`, and tertiary at `0x005451c7`.
- `xrefs_to 0x00545e00` reports code references from the two adjustor thunks and a data reference from the primary vtable slot at `0x00621afc`.
- `xrefs_to` for `0x00545ddd` and `0x00545de8` reports data references at `0x00621b60` and `0x00621b90`.

Unlike [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md), IDA did not report constructor/destructor-style rewrite xrefs from the scalar deleting destructor back to the three vtable bases in the checked database. Current evidence still supports the three-view ABI layout through constructor writes and vtable slots.

## Wave3 Data Issue

Disabled `class_EditablePaperPane.cpp` marks `0x00545ddd` as missing code and emits `0x00545de8` with a nonsensical adjusted-this expression. IDA recognizes both as ordinary 11-byte adjustor thunks. The same disabled file also emits an `EditablePaperPane` row at `0x0045004e`, but IDA places that address inside [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md); the vtable dump shows how `0x0045004e` appears immediately after the short tertiary table as adjacent string/data, not as a real paper-pane slot.

## Cross References

- [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md)
- [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md)
- [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md)

## Changes

- 2026-05-31:
  - What existed before: metadata was unevaluated at `0/0`, and the vtable inventory did not have an exact by-memory child page.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, and exact memory child [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md).
  - Summary/evidence: IDA MCP confirmed all three vtable bases, constructor stores, destructor adjustor xrefs, key slot targets, and the `0x00621b98` boundary where `LINE001.EPD` string data begins.
