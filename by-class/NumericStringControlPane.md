*** UID:00009M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NumericStringControlPane : public ControlPane
{
public:
    NumericStringControlPane(const wchar_t *text,
                             int alignment,
                             char colorVariant,
                             const RectBounds *bounds);
    virtual ~NumericStringControlPane();
    virtual void OnPaint();

private:
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_text;
    int m_alignment;
    char m_colorVariant;
    char *m_numericGlyphs;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NumericStringControlPane

## Status

- Disposition: reconstructable NexusTK project code.
- Likely source file: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- Vtable layout: [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md)
- Vtable data: [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- Main address ranges: `0x00499910-0x00499be7` and `0x0049b2f0-0x0049b3af`
- IDA MCP evidence pass: 2026-06-05.
- Complete object size: `0x118`; source-ready class declaration and exact child method/helper bodies now cover all custom source.
- Confidence: very strong for constructor, ordinary destructor, `OnPaint`, field layout/types, vtables, caller sites, resources, glyph helper, and compiler-wrapper/thunk distinctions; exact private spellings and original header split remain inferred below perfect confidence.

## Class Purpose

`NumericStringControlPane` is a fixed-width numeric text control. It stores `m_text`, `m_alignment`, `m_colorVariant`, and `m_numericGlyphs`, a MemoryMan-allocated numeric glyph buffer loaded from `9X11FONT.BIN`, then draws each code unit in 9x11 cells. It skips spaces and `/`, and draws `-` through the `FONTSYMB.EPF`/`FONTSYMB.PAL` symbol path.

## Observed State

```text
+0x108  m_text: mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > (one pointer)
+0x10c  m_alignment: 1 = right, 2 = centered, otherwise left
+0x110  m_colorVariant: signed/default char numeric glyph color/style selector
+0x111  implicit compiler padding through +0x113; no explicit source member
+0x114  m_numericGlyphs: char * to MemoryMan-allocated 9X11FONT.BIN numeric glyph buffer
+0x118  exclusive complete-object size
```

The base `ControlPane` occupies `0x108` bytes. Both MiniMap construction sites allocate `0x118`, and constructor/destructor/paint/scalar data flow accounts for every derived byte. The three bytes after `m_colorVariant` are natural pointer alignment, not a named field.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:00011L][0x00499910-0x004999c1.NumericStringControlPaneConstructor](by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md) | `NumericStringControlPane(const wchar_t *, int, char, const RectBounds *)`; constructs `ControlPane(8, bounds)`, assigns text, stores alignment/color, and loads `9X11FONT.BIN` with a non-null local out-size pointer. |
| non-deleting destructor | [UID:00011N][0x004999d0-0x00499a4e.NumericStringControlPaneDestructor](by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md) | Source body frees `m_numericGlyphs`; `m_text` destruction and Pane teardown are implicit member/base cleanup. |
| `OnPaint` virtual | [UID:00011O][0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString](by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md) | Clears bounds, computes signed-short fixed-width alignment, advances a 9-pixel cursor, and draws numeric or minus-symbol glyphs while skipping space/slash. |
| source-local glyph helper | [UID:0003XD][0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit](by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md) | Static `InitNumericGlyphTileContext` initializes/returns a 9x11 EPFTileContext over `m_numericGlyphs + 99 * (glyph + 10 * colorVariant - 47)`. |
| adjustor thunks | [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md) | Compiler `this`-adjusting destructor thunks; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md) | Compiler destructor/delete wrapper covered by the virtual ordinary destructor; no handwritten ABI body. |

## Evidence Notes

- `lookup_funcs` confirms exact modeled sizes for the constructor (`0xb1`), non-deleting destructor (`0x7e`), render virtual (`0x197`), adjustor thunks (`0x0b` each), and scalar deleting destructor (`0xbf`).
- `callers(0x00499910)` reports two constructor callers, `0x00451143` and `0x004511d8`, inside [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) coordinate-control setup.
- `xrefs_to(0x00499a50)` reports the render virtual through vtable data cell `0x006183d4`.
- `xrefs_to(0x0049b2f0)` reports adjustor code refs at `0x0049af85` and `0x0049af90` plus the primary destructor slot at `0x00618390`.
- Constructor/destructor/scalar destructor vtable stores target `0x00618390`, `0x006183f8`, and `0x00618428`.
- Live wide-string bytes confirm `9X11FONT.BIN` at `0x0061682c`, `FONTSYMB.EPF` at `0x00616894`, and `FONTSYMB.PAL` at `0x006168b0`.
- Render decompilation confirms the class computes text width as `9 * length`, right-aligns on mode `1`, centers on mode `2`, skips UTF-16 values `32` and `47`, draws UTF-16 value `45` through the symbol path, and advances by 9 pixels per code unit.
- B001 UID00011N callback evidence identifies `+0x114` as `m_numericGlyphs`, the `LoadDatFileBuffer(L"9X11FONT.BIN", 99, ...)` result released by `GetMemoryMan()->FreeBufferMemory` in the ordinary destructor. The older "font handle" wording is superseded by this buffer-pointer role.
- B002 MCP session `59c7e90d` on 2026-07-13 reconfirmed exact function sizes/ranges, both `0x118` MiniMap allocations and arguments, one-pointer StringBase helper family, three vtable store triads, paint/helper branches, resource bytes, scalar flags, adjustor offsets, and padding.

## Source Model And Failure Semantics

- The class declaration is emitted once at position `0` and `[[CHILDREN]]` supplies deterministic source items: helper `10`, constructor `20`, accepted destructor `30`, `OnPaint` `40`, scalar covered marker `50`, vtable-type marker `60`, and vtable-data marker `70`.
- Constructor has no null/fallback branch after `LoadDatFileBuffer`; the class owns the returned `char *` and the ordinary destructor performs the only guarded source release.
- `OnPaint` has no glyph-buffer null check, no symbol-layout lookup result check, no fallback glyph/resource branch, and no explicit stack-context release. Those observed absences are part of the accepted behavior.
- Minus uses `FONTSYMB.EPF` frame `4` and `FONTSYMB.PAL`; space/slash skip drawing; all code units advance 9 pixels. Other glyphs use the fixed helper formula and `g_pfnBlitSprite` with null palette/options.
- Vptr stores/resets, implicit StringBase/base teardown, scalar delete flags/object free, adjustor thunks, RTTI/vtable bytes, and stack cookies are compiler output. Covered markers preserve their evidence without duplicate handwritten implementations.
- UID00011M remains semantically owned by this class but is a non-reconstructable/non-emitting split index; exact children alone carry source.

## Superseded Source Aliases

- `RenderNumericString` is retained only as a documentation filename/behavior phrase; the source-facing virtual is `OnPaint`.
- `fontHandle` at `+0x114`, larger `SimpleUString`/SSO storage at `+0x108`, raw `sub_4BB1E0`, weaker `BuildNumericGlyphTileContext`, `g_pfnLockSurface`, and raw/caller-biased render callback names are superseded.
- The accepted names are `m_numericGlyphs`, explicit wide StringBase, `InitNumericGlyphTileContext`, `FillRect`, `RenderTileFrame`, and `g_pfnBlitSprite`.

## Cross-References

- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md)
- [UID:00011M][0x00499910-0x00499be7.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md)
- [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)

## Changes

- 2026-07-13 B002 UID00011M implementation callback:
  - Raised `86/90 -> 92/93`, retained file owner/emitter [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md), and set emitter position `0`.
  - Added the exact class declaration with complete `0x118` layout, implicit padding, constructor/destructor/`OnPaint` declarations, and `[[CHILDREN]]`.
  - Incorporated complete helper/resource/alignment/lifecycle/failure behavior, compiler-only scalar/thunk/vtable distinctions, deterministic emission order, semantic ownership of the non-emitting aggregate, and superseded-alias record.
- 2026-07-09 B001 UID00011N implementation callback:
  - Score unchanged at `86/90`.
  - Updated field notes to `m_text`, `m_alignment`, `m_colorVariant`, and `m_numericGlyphs`; recorded that the ordinary destructor emits only the `m_numericGlyphs` free while string and Pane cleanup are implicit member/base output.
- 2026-06-12 A004 Batch 331:
  - No score change. Added the exact source-local vtable type child [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md), which routes directly to this class and supersedes the mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) aggregate for type-level ownership.
- 2026-06-05: Live IDA refresh.
  - What existed before: the page was scored `82/84`, cited stale recovered-output provenance, and still carried stale vtable/output caveats.
  - Changed to: completion `86`, confidence `90`, stale provenance removed, live helper/resource/vtable/caller evidence expanded, and final C++ kept blank.
  - Summary/evidence: live IDA confirms the class role, field offsets, constructor/destructor/render/scalar boundaries, vtable refs, two minimap constructor callers, resource strings, minus/space/slash behavior, and source-file parent eligibility.
