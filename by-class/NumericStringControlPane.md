*** UID:00009M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumericStringControlPane

## Status

- Disposition: reconstructable NexusTK project code.
- Likely source file: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- Vtable data: [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- Main address ranges: `0x00499910-0x00499be7` and `0x0049b2f0-0x0049b3af`
- IDA MCP evidence pass: 2026-06-05.
- Confidence: strong for constructor, destructor, render virtual, vtables, caller sites, resource strings, and thunk ownership; medium-high for final field names and original source grouping.

## Class Purpose

`NumericStringControlPane` is a fixed-width numeric text control. It stores a wide string, alignment mode, color variant, and a DAT-loaded font handle, then draws each code unit in 9x11 cells. It skips spaces and `/`, and draws `-` through the `FONTSYMB.EPF`/`FONTSYMB.PAL` symbol path.

## Observed State

```text
+0x108  owned wide-string storage
+0x10c  alignment mode: 1 = right, 2 = centered, otherwise left
+0x110  numeric glyph color/style selector byte
+0x114  loaded 9X11FONT.BIN font handle
```

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:00011L][0x00499910-0x004999c1.NumericStringControlPaneConstructor](by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md) | Constructs the base `ControlPane`, copies the text, records alignment/color, and loads `9X11FONT.BIN`. |
| non-deleting destructor | [UID:00011N][0x004999d0-0x00499a4e.NumericStringControlPaneDestructor](by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md) | Releases the font handle and destroys local text/base control state. |
| render virtual | [UID:00011O][0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString](by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md) | Computes alignment, advances a 9-pixel cursor, and draws numeric glyphs or minus-symbol glyphs. |
| adjustor thunks | [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md) | Compiler `this`-adjusting destructor thunks; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper reached through the primary destructor slot and adjustor thunks. |

## Evidence Notes

- `lookup_funcs` confirms exact modeled sizes for the constructor (`0xb1`), non-deleting destructor (`0x7e`), render virtual (`0x197`), adjustor thunks (`0x0b` each), and scalar deleting destructor (`0xbf`).
- `callers(0x00499910)` reports two constructor callers, `0x00451143` and `0x004511d8`, inside [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) coordinate-control setup.
- `xrefs_to(0x00499a50)` reports the render virtual through vtable data cell `0x006183d4`.
- `xrefs_to(0x0049b2f0)` reports adjustor code refs at `0x0049af85` and `0x0049af90` plus the primary destructor slot at `0x00618390`.
- Constructor/destructor/scalar destructor vtable stores target `0x00618390`, `0x006183f8`, and `0x00618428`.
- Live wide-string bytes confirm `9X11FONT.BIN` at `0x0061682c`, `FONTSYMB.EPF` at `0x00616894`, and `FONTSYMB.PAL` at `0x006168b0`.
- Render decompilation confirms the class computes text width as `9 * length`, right-aligns on mode `1`, centers on mode `2`, skips UTF-16 values `32` and `47`, draws UTF-16 value `45` through the symbol path, and advances by 9 pixels per code unit.

## Cross-References

- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:00011M][0x00499910-0x00499be6.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be6.NumericStringControlPaneCore.md)
- [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)

## Changes

- 2026-06-05: Live IDA refresh.
  - What existed before: the page was scored `82/84`, cited stale recovered-output provenance, and still carried stale vtable/output caveats.
  - Changed to: completion `86`, confidence `90`, stale provenance removed, live helper/resource/vtable/caller evidence expanded, and final C++ kept blank.
  - Summary/evidence: live IDA confirms the class role, field offsets, constructor/destructor/render/scalar boundaries, vtable refs, two minimap constructor callers, resource strings, minus/space/slash behavior, and source-file parent eligibility.
