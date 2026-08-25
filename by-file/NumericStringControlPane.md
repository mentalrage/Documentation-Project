*** UID:0000M2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NumericStringControlPane

## Status

- Disposition: source-ready one-class-plus-helper implementation route; no duplicate aggregate body or handwritten compiler ABI source.
- Confidence: very strong for class role, complete `0x118` layout, exact source method/helper bodies, resource and lifecycle behavior, and compiler-generated support disposition; the original header split and private/helper spellings remain inferred below perfect confidence.
- Proposed module: `ui/controls/NumericStringControlPane.cpp`
- Projected reconstruction path: `NexusTK/ui/controls/NumericStringControlPane.cpp`
- Main address ranges: `0x00499910-0x00499be7`, source-local helper `0x004bb1e0-0x004bb252`, plus compiler destructor/thunk support in `0x0049af7f-0x0049b3af`
- Vtable layout: [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md)
- Vtable data: [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- IDA MCP evidence passes: 2026-06-05 and B002 session `59c7e90d` on 2026-07-13. The session identifier records evidence-collection time only and does not assert present availability.

## File Role

`NumericStringControlPane` is a small `ControlPane`-derived numeric text renderer. It stores `m_text`, `m_alignment`, `m_colorVariant`, and `m_numericGlyphs`, a MemoryMan-allocated numeric glyph buffer loaded from `9X11FONT.BIN`, then paints digits one glyph at a time with fixed 9x11 spacing.

The class special-cases `-` by drawing a symbol from `FONTSYMB.EPF`/`FONTSYMB.PAL`, skips spaces and `/`, and supports left, right, and centered alignment. Current IDA caller evidence ties construction to [UID:0000LE][MiniMap](by-file/MiniMap.md), where it creates the X/Y coordinate value controls, but the implementation is reusable numeric-glyph control code.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| constructor | [UID:00011L][0x00499910-0x004999c1.NumericStringControlPaneConstructor](by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md) | Calls `ControlPane::ControlPane` with type `8`, initializes stored text/alignment/color, and loads `9X11FONT.BIN` through [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md). |
| non-deleting destructor | [UID:00011N][0x004999d0-0x00499a4e.NumericStringControlPaneDestructor](by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md) | Source-ready ordinary destructor body frees `m_numericGlyphs`; stored text and base control teardown are member/base cleanup around the source body. |
| `OnPaint` virtual | [UID:00011O][0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString](by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md) | Clears background, computes signed-short left/right/center placement, and draws numeric glyphs or minus-symbol glyphs while skipping space/slash. `RenderNumericString` is only the retained documentation filename. |
| numeric glyph tile helper | [UID:0003XD][0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit](by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md) | Initializes the fixed 9x11 glyph tile context used by the render virtual; split from the nearby GrafPort physical range but owned by NumericStringControlPane. |
| adjustor thunks | [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md) | Compiler thunks forwarding to scalar deleting destructor; excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md) | Compiler destructor/delete wrapper covered by the source-level virtual destructor; preserve the marker and evidence, not a second destructor body. |
| vtable type/data | [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md), [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md) | Covered-by markers retain all three compiler-generated table views and raw data evidence without handwritten RTTI or arrays. |

## Source Layout And Emission Order

The base `ControlPane` occupies `0x108` bytes. The exact derived layout is a one-pointer `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_text` at `+0x108`, `int m_alignment` at `+0x10c`, `char m_colorVariant` at `+0x110`, three bytes of implicit compiler alignment at `+0x111-+0x113`, and owned `char *m_numericGlyphs` at `+0x114`; complete size is `0x118`. The padding is not an explicit source member. The older `SimpleUString`, `fontHandle`, and explicit-padding interpretations are superseded.

The file route emits one class declaration and one source definition for each human-authored operation. Deterministic positions are class declaration `0`, static `InitNumericGlyphTileContext` helper `10`, constructor `20`, accepted ordinary destructor `30`, `OnPaint` `40`, scalar-wrapper covered marker `50`, vtable-type covered marker `60`, and vtable-data covered marker `70`. [UID:00011M][0x00499910-0x00499be7.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md) remains semantically owned by the class but is a non-reconstructable, non-emitting split index; its exact constructor/destructor/paint children alone carry source. The compiler adjustors remain no-owner, non-reconstructable, and blank.

## Lifecycle And Paint Behavior

- Construction calls `ControlPane(8, bounds)`, assigns the incoming wide literal through the established one-pointer StringBase helper, stores alignment and color, and calls `LoadDatFileBuffer(L"9X11FONT.BIN", 99, &glyphBufferSize)`. The local size out parameter is non-null even though its result is not subsequently used. The constructor contains no null check, failure branch, fallback resource, or target-side cleanup.
- The class owns the returned glyph-buffer pointer. The accepted ordinary destructor preserves its exact guarded `GetMemoryMan()->FreeBufferMemory(m_numericGlyphs)` and null assignment. StringBase destruction, base teardown, vptr transitions, and stack/compiler machinery remain implicit compiler work rather than handwritten source.
- `OnPaint` copies the inherited bounds, calls `SetDrawColor(0)` and `FillRect`, computes `static_cast<short>(9 * wcslen(m_text.c_str()))`, uses mode `1` for right alignment, mode `2` for centered alignment, and defaults to the left edge. It initializes a `9x11` destination cell and advances it by 9 pixels for every UTF-16 code unit.
- Minus initializes an `EPFTileContext`, looks up frame `4` in `FONTSYMB.EPF`, offsets by the returned source bounds, calls `RenderTileFrame` in mode `1` with `FONTSYMB.PAL` and null options, then reverses the offset. Space and slash perform no draw but still advance. Every other code unit uses `InitNumericGlyphTileContext` and `g_pfnBlitSprite` in mode `1` with null palette and options.
- `InitNumericGlyphTileContext` initializes a `9x11` bounds rectangle and context, sets row stride `9`, clears encoded-mask count/pointer, stores the bounds, and selects `numericGlyphs + 99 * (glyph + 10 * colorVariant - 47)` before returning the same context pointer. It allocates and frees nothing.
- Paint deliberately has no glyph-buffer null check, no layout-lookup result check, no fallback glyph/resource branch, and no explicit stack-context release. These observed absences are preserved instead of normalized.

## Ownership Decision

Keep this as a reusable `ui/controls` module instead of moving it into minimap. The only direct constructor callers currently found in IDA are `0x00451143` and `0x004511d8` inside [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), but the implementation is generic numeric-glyph control code.

The current one-class-plus-helper route is the strongest source placement. MiniMap is rejected because its two sites are consumers and no method reads MiniMap state. GrafPort, Surface, DATFile, EPFTileContext, and ResourceLayoutTable are rejected because they own drawing, loading, context, or lookup dependencies rather than the receiver semantics. A broader tiny-controls file remains possible only if independent source-layout evidence appears; it is not a current blocker and does not justify moving or duplicating this implementation.

Compiler-only scalar delete flags/object free, secondary/tertiary `this` adjustment, vptr resets, RTTI, vtable arrays, implicit member/base teardown, and stack cookies are represented by exact covered/non-emitting dispositions. They must not be handwritten into this file as extra destructors, thunks, or table data.

## Evidence Notes

- `lookup_funcs` confirms real functions at `0x00499910`, `0x004999d0`, `0x00499a50`, two adjustor thunks at `0x0049af7f`/`0x0049af8a`, and scalar deleting destructor at `0x0049b2f0`.
- `callers(0x00499910)` reports two direct constructor calls inside the minimap dialog constructor, both creating initial `L"0"` coordinate value controls.
- `xrefs_to(0x00499a50)` reports the render vtable cell at `0x006183d4`; `callers(0x00499a50)` reports no ordinary direct callers.
- `xrefs_to(0x0049b2f0)` reports two adjustor thunk code refs and the primary destructor slot at `0x00618390`.
- Constructor/destructor/scalar destructor vtable stores target `0x00618390`, `0x006183f8`, and `0x00618428`.
- Live bytes confirm `9X11FONT.BIN`, `FONTSYMB.EPF`, and `FONTSYMB.PAL` resource strings.
- B001 UID00011N callback evidence makes the ordinary destructor source-ready in this file route: the generated `NumericStringControlPane.cpp` should emit `NumericStringControlPane::~NumericStringControlPane()` with the guarded `m_numericGlyphs` free instead of leaving UID00011N as an empty marker.
- B002 MCP session `59c7e90d` on 2026-07-13 reconfirmed the exact constructor/destructor/paint/helper ranges and bodies, both MiniMap `0x118` allocations and arguments, StringBase helper family, resource bytes, vtable store triads, scalar flags, adjustor offsets, and every recorded negative branch/cleanup absence.
- Source-facing names are `NumericStringControlPane::OnPaint`, static `InitNumericGlyphTileContext`, `FillRect`, `RenderTileFrame`, and `g_pfnBlitSprite`. `RenderNumericString`, raw `sub_4BB1E0`, `BuildNumericGlyphTileContext`, `g_pfnLockSurface`, and caller-biased callback aliases are retained only as rejected or superseded history.

## Cross-References

- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md)
- [UID:00011M][0x00499910-0x00499be7.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md)
- [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0003XD][0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit](by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)

## Changes

- 2026-07-13 B002 UID00011M implementation callback:
  - Raised `86/88 -> 92/92` after closing the class layout, exact source bodies, helper naming/type, failure semantics, ownership, source placement, and compiler-wrapper disposition.
  - Added the complete one-class-plus-helper source model, exact `0x118` fields and implicit padding, resource/lifecycle/paint behavior, deterministic positions `0-70`, and no-duplicate aggregate/scalar/thunk/vtable policy.
  - Preserved the accepted UID00011N body/provenance and all same-or-greater dependency evidence; recorded the evidence session as a time-scoped observation.
- 2026-07-09 B001 UID00011N implementation callback:
  - Score unchanged at `86/88`.
  - Updated `+0x114` wording from opaque font handle to `m_numericGlyphs`, the loaded `9X11FONT.BIN` numeric glyph buffer; recorded that UID00011N now emits the ordinary destructor body in this source file route.
- 2026-06-17 B003 GrafPort split/source-quality support update:
  - Score unchanged at `86/88`.
  - Evidence: added [UID:0003XD][0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit](by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md), a one-caller fixed `9x11` glyph tile-context helper split from the broad GrafPort physical range. Ownership routes here because NumericString rendering is the live caller and the helper initializes context for `9X11FONT.BIN` glyph drawing rather than generic GrafPort or FontImageLib code.
- 2026-06-12 A004 Batch 331:
  - No score change. Added exact source-local vtable type child [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md) as the type-level owner under [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md); the mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) aggregate is now non-emitting.
- 2026-06-05: Live IDA refresh.
  - What existed before: the page was scored `84/80`, used stale source-layout notes, and did not summarize the refreshed render/scalar details.
  - Changed to: completion `86`, confidence `88`, live constructor/destructor/render/scalar/vtable/resource evidence, and stale provenance removed.
  - Summary/evidence: live IDA confirms this as a reusable numeric-glyph control file under `ui/controls`, with only final original grouping and source-ready names remaining open.
