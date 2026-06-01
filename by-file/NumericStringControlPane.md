*** UID:0000M2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NumericStringControlPane

## Status

- Confidence: strong for class role and method ownership, medium for final original file split.
- Proposed module: `ui/controls/NumericStringControlPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_NumericStringControlPane.cpp`
- Main address ranges: `0x00499910-0x00499be7`, plus destructor/thunk support in `0x0049af7f-0x0049b3af`
- Vtable layout: [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)

## File Role

`NumericStringControlPane` is a small `ControlPane`-derived numeric text renderer. It stores a wide string, alignment mode, color variant, and a DAT-loaded `9X11FONT.BIN` font handle, then paints digits one glyph at a time with fixed 9x11 spacing.

The class special-cases `-` by drawing a symbol from `FONTSYMB.EPF`, skips spaces and `/`, and supports left, right, and centered alignment. Current IDA caller evidence ties construction to [UID:0000LE][MiniMap](by-file/MiniMap.md), where it creates the X/Y coordinate value controls.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `NumericStringControlPane` | [UID:00011L][0x00499910-0x004999c1.NumericStringControlPaneConstructor](by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md) | Constructor; calls `ControlPane::ControlPane` with type `8`, initializes stored text/alignment/color, and loads `9X11FONT.BIN` through [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md). |
| `~NumericStringControlPane` | [UID:00011N][0x004999d0-0x00499a4e.NumericStringControlPaneDestructor](by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md) | Non-deleting destructor; releases the font handle, destroys stored text, and tears down the base control. |
| `RenderNumericString` | [UID:00011O][0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString](by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md) | Paint virtual; clears background, computes aligned cursor position, and draws numeric glyphs or minus symbol glyphs. |
| adjustor thunks | [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md) | Compiler thunks forwarding to scalar deleting destructor; excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper. |

## Ownership Decision

Keep this as a reusable `ui/controls` module instead of moving it into minimap. The only direct constructor callers found in IDA are currently `0x00451143` and `0x004511d8` inside `MiniMapDialog::MiniMapDialog`, but the implementation is generic numeric-glyph control code and its recovered source file is `NumericStringControlPane.cpp`.

This could later fold into a broader `BasicControlPanes.cpp` or `TextControlPanes.cpp` if source-layout evidence shows the original project grouped tiny visual controls. For now, the separate one-class file is the least risky reconstruction target.

## Evidence Notes

- IDA MCP confirms real functions at `0x00499910`, `0x004999d0`, `0x00499a50`, and `0x0049b2f0`.
- IDA MCP confirms adjustor thunks at `0x0049af7f` and `0x0049af8a`.
- 2026-05-26 IDA recheck decompiles both adjustor thunks as `this`-adjusting forwards into `0x0049b2f0`; they are compiler glue, while the scalar deleting destructor remains a reconstructable owner method.
- 2026-05-26 IDA vtable recheck confirms table bases at `0x00618390`, `0x006183f8`, and `0x00618428`; active Wave3 metadata reports `vtable_count: 0`, so vtable reconstruction currently depends on IDA evidence.
- IDA MCP caller lookup reports two direct constructor call sites in `MiniMapDialog::MiniMapDialog`, both creating initial `L"0"` coordinate value controls.
- `RenderNumericString` calls [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) indirectly via the loaded font handle and uses render helpers for `FONTSYMB.EPF`/`FONTSYMB.PAL` minus sign drawing.

## Cross-References

- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:00011M][0x00499910-0x00499be6.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be6.NumericStringControlPaneCore.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `80`.
- Summary/evidence: the page documents control behavior, proposed contents, ownership decision, IDA/vtable evidence, caller evidence, and cross-references; confidence remains capped by possible fold into a broader control-pane source.
