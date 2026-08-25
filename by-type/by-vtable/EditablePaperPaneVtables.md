*** UID:0001XF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000048 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated EditablePaperPane three-view vtable/RTTI layout.
// No handwritten vtable arrays, locator pointers, or adjustor entries.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EditablePaperPane Vtables

## Status

- Disposition: non-reconstructable compiler-generated vtable/RTTI layout evidence; class and method source remain reconstructable through their own formal channels.
- Covered source owner: [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- Covered class: [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md)
- Exact memory data: [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md)
- Autogen status: owned by [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md), with `RECONSTRUCTABLE:FALSE`, a blank emitter list, comment-only formal CPP, and intentionally blank formal H. The compiler produces these bytes from the complete class declaration and virtual definitions.
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
| primary | `+0x48` | `0x00545220` | `EditablePaperPane::OnControlCommand(int,int)`; the second argument is ignored, editable action `0` saves, and the dialog closes. |
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

Disabled `class_EditablePaperPane.cpp` marks `0x00545ddd` as missing code and emits `0x00545de8` with a nonsensical adjusted-this expression. IDA recognizes both as ordinary 11-byte adjustor thunks. The same disabled file also emits an `EditablePaperPane` row at `0x0045004e`, but IDA places that address inside [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md); the vtable dump shows how `0x0045004e` appears immediately after the short tertiary table as adjacent string/data, not as a real paper-pane slot.

## Parent Rationale

Attach this vtable cluster to [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md). The three table bases all belong to the single `EditablePaperPane` class, the class page already clears the `80/80` attachment gate and is attached to [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md), and the adjacent `LINE001.EPD` bytes are documented as boundary data rather than additional virtual slots.

## 2026-08-16 Complete RTTI And Layout Closure

- Corrected physical source: [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md), 160 bytes, 40 contiguous dwords, SHA256 `333CABA0EA935B111622DCA266CB46993EABE7CC33EF674E29F5CA909C9DE468`.
- Complete-object locators are `0x0064db30`, `0x0064db90`, and `0x0064dba4`; all reference type descriptor `0x006786a8` and class hierarchy descriptor `0x0064db44`.
- COL offsets are exactly `0`, `+0xa0`, and `+0xa4`. CHD attributes are `1`; its seven bases are EditablePaperPane, DialogPane, Pane, GrafPort, LObject, EventHandler (`mdisp +0xa0`), and TimerHandler (`mdisp +0xa4`). Only DialogPane is a direct source base; EventHandler and TimerHandler are inherited through Pane.
- The primary view has 24 slots `[0x00621afc,0x00621b5c)`, SHA256 `AB38EDEC91491E7792EA370EE3E56AEC8A26CC26DA2CC25CC58FBD455734150B`. Its class-specific slots are `OnControlCommand` at `+0x48`, `DrawBackground` at `+0x50`, `DrawBorder` at `+0x54`, and `InitializePaperContent` at `+0x5c`; all remaining entries are the documented LObject/Pane/DialogPane inheritance surface or compiler destructor wrapper.
- The secondary EventHandler facet has 11 slots `[0x00621b60,0x00621b8c)`, SHA256 `2F88477641D49F006E4290F2A23D88860287716E28E989299DF2B1889BC3651E`; slot zero is the `this-0xa0` adjustor and the remaining ten targets are inherited event/offset/acceptance methods.
- The tertiary TimerHandler facet has exactly two slots `[0x00621b90,0x00621b98)`, SHA256 `CC945B208F8E596075076F41FE2AD6EB2D9A68F5A91434048B0AEE9649AE2F2D`; slot zero is the `this-0xa4` adjustor and slot one is inherited `Pane::OnTimer`.
- Constructor stores at `0x005451b7`, `0x005451bd`, and `0x005451c7` independently establish all three view heads. The implicit derived destructor is sufficient source cause for the scalar deleting wrapper and both adjustors; no handwritten vtable, COL, RTTI, adjustor, or destructor-wrapper array/body is emitted here.
- Exact successor `LINE001.EPD` starts at `0x00621b98`, spans 24 bytes through `0x00621bb0`, and has SHA256 `360677F05A5B7E5FA705801995CF7DB126D43A42CA18269252F1F5695605B3F2`. The apparent `0x0045004e` dword is UTF-16 interior bytes, not a slot.

## Cross References

- [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md)
- [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md)
- [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md)

## Changes

- 2026-08-16 B001 implementation callback: raised `86/90 -> 94/96`, changed the type page to compiler-generated/non-reconstructable evidence owned by UID000048, cleared its emitter, installed the accepted no-code formal CPP comment, corrected `OnControlCommand`, and added complete COL/CHD/base/PMD, table-shape, source-cause, constructor-xref, and successor-boundary evidence. Formal H remains intentionally blank.

- 2026-06-18 B003 source-quality execution: replaced stale `95/95` code-gate wording with the active by-structure gate while preserving the no-handwritten-C++ policy for vtable/RTTI bytes.

- 2026-06-07 parent attachment update:
  - What existed before: the vtable page had strong single-class evidence and an exact memory child, but no autogen parent.
  - Changed to: `COMPLETION:86` and `AUTOGEN_PARENT_UID:000048`, with an explicit class-parent rationale.
  - Summary/evidence: all three vtable views are `EditablePaperPane` views, [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md) clears the attachment gate, and the documented `0x00621b98` boundary prevents adjacent `LINE001.EPD` data from being mistaken for extra class ownership.
- 2026-05-31:
  - What existed before: metadata was unevaluated at `0/0`, and the vtable inventory did not have an exact by-memory child page.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, and exact memory child [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md).
  - Summary/evidence: IDA MCP confirmed all three vtable bases, constructor stores, destructor adjustor xrefs, key slot targets, and the `0x00621b98` boundary where `LINE001.EPD` string data begins.
