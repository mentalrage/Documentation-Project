*** UID:0000M2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NumericStringControlPane

## Status

- Confidence: strong for class role and method ownership, medium-high for final original file split.
- Proposed module: `ui/controls/NumericStringControlPane.cpp`
- Projected reconstruction path: `NexusTK/ui/controls/NumericStringControlPane.cpp`
- Main address ranges: `0x00499910-0x00499be7`, plus destructor/thunk support in `0x0049af7f-0x0049b3af`
- Vtable data: [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- IDA MCP evidence pass: 2026-06-05.

## File Role

`NumericStringControlPane` is a small `ControlPane`-derived numeric text renderer. It stores a wide string, alignment mode, color variant, and a DAT-loaded `9X11FONT.BIN` font handle, then paints digits one glyph at a time with fixed 9x11 spacing.

The class special-cases `-` by drawing a symbol from `FONTSYMB.EPF`/`FONTSYMB.PAL`, skips spaces and `/`, and supports left, right, and centered alignment. Current IDA caller evidence ties construction to [UID:0000LE][MiniMap](by-file/MiniMap.md), where it creates the X/Y coordinate value controls, but the implementation is reusable numeric-glyph control code.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| constructor | [UID:00011L][0x00499910-0x004999c1.NumericStringControlPaneConstructor](by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md) | Calls `ControlPane::ControlPane` with type `8`, initializes stored text/alignment/color, and loads `9X11FONT.BIN` through [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md). |
| non-deleting destructor | [UID:00011N][0x004999d0-0x00499a4e.NumericStringControlPaneDestructor](by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md) | Releases the font handle, destroys stored text, and tears down the base control. |
| render virtual | [UID:00011O][0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString](by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md) | Clears background, computes aligned cursor position, and draws numeric glyphs or minus-symbol glyphs. |
| adjustor thunks | [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md) | Compiler thunks forwarding to scalar deleting destructor; excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper. |

## Ownership Decision

Keep this as a reusable `ui/controls` module instead of moving it into minimap. The only direct constructor callers currently found in IDA are `0x00451143` and `0x004511d8` inside [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), but the implementation is generic numeric-glyph control code.

This could later fold into a broader tiny-control source file if source-layout evidence proves the original project grouped small visual controls. For now, the separate one-class file is the least risky reconstruction target.

## Evidence Notes

- `lookup_funcs` confirms real functions at `0x00499910`, `0x004999d0`, `0x00499a50`, two adjustor thunks at `0x0049af7f`/`0x0049af8a`, and scalar deleting destructor at `0x0049b2f0`.
- `callers(0x00499910)` reports two direct constructor calls inside the minimap dialog constructor, both creating initial `L"0"` coordinate value controls.
- `xrefs_to(0x00499a50)` reports the render vtable cell at `0x006183d4`; `callers(0x00499a50)` reports no ordinary direct callers.
- `xrefs_to(0x0049b2f0)` reports two adjustor thunk code refs and the primary destructor slot at `0x00618390`.
- Constructor/destructor/scalar destructor vtable stores target `0x00618390`, `0x006183f8`, and `0x00618428`.
- Live bytes confirm `9X11FONT.BIN`, `FONTSYMB.EPF`, and `FONTSYMB.PAL` resource strings.

## Cross-References

- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:00011M][0x00499910-0x00499be6.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be6.NumericStringControlPaneCore.md)
- [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)

## Changes

- 2026-06-05: Live IDA refresh.
  - What existed before: the page was scored `84/80`, used stale source-layout caveats, and did not summarize the refreshed render/scalar details.
  - Changed to: completion `86`, confidence `88`, live constructor/destructor/render/scalar/vtable/resource evidence, and stale provenance removed.
  - Summary/evidence: live IDA confirms this as a reusable numeric-glyph control file under `ui/controls`, with only final original grouping and source-ready names remaining open.
