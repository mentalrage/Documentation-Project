*** UID:00003X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DirectionButtonControlPane : public ButtonControlPane
{
public:
    DirectionButtonControlPane(int directionIndex, const RectBounds &bounds)
        : ButtonControlPane(bounds),
          m_directionIndex(directionIndex),
          m_stateFrameOffset(0)
    {
    }

protected:
    virtual void OnPaint();
    virtual void SetVisualState(unsigned char visualState);

private:
    int m_directionIndex;
    int m_stateFrameOffset;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DirectionButtonControlPane

## Status

- Confidence: very strong for the class role, one-base inheritance, exact `0x114` layout, two fields, retained-inline constructor, virtual state/paint methods, three compiler table views, destructor ABI, live consumers, and shared source-family placement. Remaining uncertainty is limited to stripped lexical spellings and the literal historical filename.
- Likely source file: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Memory range: mixed container [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md), exact physical index [UID:00036V][0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods](by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md), source children [UID:00050G][0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor](by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md), [UID:00050H][0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState](by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md), [UID:00050I][0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint](by-memory/0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md), and compiler wrapper [UID:00036W][0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor](by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md).
- Current recovered file: `source-3/simroot_v2/class_DirectionButtonControlPane.cpp`
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Class Purpose

`DirectionButtonControlPane` is a button-like control that renders directional arrow sprites from `DIREC.EPD`, updates a visual-state frame offset for the selected direction, and chains through the generic button/control destruction pattern.

## Rebuild Handling

- Reconstructability: true for the class declaration, direction/visual-state fields, recognized virtual methods, and destructor behavior.
- Parent handling: attach to [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at source position `30`. The file root owns shared `NexusTK/ui/controls/SpecializedButtonPanes.cpp/.h`; this class remains the single semantic emitter for Direction source.
- C++ handling: formal H contains the complete human class declaration and inline constructor. Formal CPP contains only `[[CHILDREN]]`; UID00050H and UID00050I provide exact out-of-line definitions, while UID00050G carries covered-by comments because its source is already inline in H. Compiler vtable/RTTI/deleting-wrapper pages emit nothing.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DirectionButtonControlPane` | [UID:00050G][0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor](by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md) | Exact retained copy of the inline `(int directionIndex, const RectBounds &bounds)` constructor. It calls the ButtonControlPane base, stores `m_directionIndex`, installs three inherited vptr views, clears `m_stateFrameOffset`, and is followed by eight bytes of alignment. Two live NewUser inlines prove source liveness despite no direct route. |
| `SetVisualState` | [UID:00050H][0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState](by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md) | Exact byte-state override. When inherited state changes, it maps `11` to frame offset `1` and every other changed state to `0`, then always delegates to [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md). Historical `SetEnabled` and broad `SetState` aliases are superseded. |
| `OnPaint` | [UID:00050I][0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint](by-memory/0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md) | Exact paint override. It initializes `EPFTileContext`, selects `DIREC.EPD` frame `2 * m_directionIndex + m_stateFrameOffset`, renders with `NPAL3.PAL`, and then applies inherited disabled shading using color `143` and draw mode `2`. |
| Destructor/thunks | `0x0050248a`, `0x00502495`, `0x005026a0-0x005026f5` | This-adjustor thunks plus exact scalar deleting destructor child [UID:00036W][0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor](by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md); vtable data xrefs at `0x0061dc9c`, `0x0061dccc`, and `0x0061dc34`. |

## Field Evidence

| Offset | Field hypothesis | Evidence |
| ---: | --- | --- |
| `0x10c` | `m_directionIndex` | Raw constructor-shaped bytes store the first stack argument here; `NewUserMiscDialogPane` inline setup writes `0` for one direction button and `1` for the other. `OnPaint` uses it as `2 * m_directionIndex` for the `DIREC.EPD` frame group. Rejected alternatives: `m_frameIndex` is too broad because `+0x110` contributes the state frame, and `m_isLeft` is too narrow because the value is numeric and multiplied rather than treated as a boolean. |
| `0x110` | `m_stateFrameOffset` | Constructor bytes and both live inlines clear this `int`. `SetVisualState` writes `1` for changed state `11` and `0` for every other changed state; `OnPaint` adds it to `2 * m_directionIndex`. `m_visualStateFrameOffset` is retained only as a historical longer alternative; `m_enabled` and `m_pressed` are rejected because the field is an integer frame offset rather than a boolean. |

Inherited fields used by this class remain owned by `ControlPane`/`ButtonControlPane`: `+0x44` is the bounds/draw-rect subobject, `+0x101` gates disabled overlay drawing, `+0x103` is the inherited visual/control state byte, and `+0x00/+0xa0/+0xa4` are primary/secondary/tertiary vptr views rather than source data members.

## Vtable Evidence

- [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md) records exact primary, secondary, and tertiary vtable data for this class.
- Primary vtable `0x0061dc34` has store xrefs from inline setup at `0x004fba6d` and `0x004fbaf3`, the raw constructor body at `0x005007bd`, and destructor reset at `0x005026a6`.
- Secondary vtable `0x0061dc9c` has store xrefs at `0x004fba73`, `0x004fbaf9`, `0x005007c3`, and `0x005026ac`.
- Tertiary vtable `0x0061dccc` has store xrefs at `0x004fba7d`, `0x004fbb03`, `0x005007cd`, and `0x005026b6`.
- Key slots tie `0x00500820` to paint at primary `+0x44`, `0x005007f0` to state/update at primary `+0x48`, and `0x005026a0` to the scalar deleting destructor at primary `+0x00`.

## Accepted Source Closure

- Exact complete-object size is `0x114`. The source declaration has one direct base, `ButtonControlPane`; RTTI's EventHandler and TimerHandler rows are inherited Pane facets at `+0xa0/+0xa4`, not repeated source bases.
- The primary/EventHandler/TimerHandler views have `25/11/2` slots and complete-object offsets `0/0xa0/0xa4`. The complete slot and RTTI maps are preserved in [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md).
- Inline consumer blocks `[0x004fba68,0x004fba92)` and `[0x004fbaee,0x004fbb18)` construct direction values `0` and `1`. They establish liveness but do not transfer reusable-control ownership to NewUser.
- [UID:00036W][0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor](by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md) resets the three vptrs, runs Pane teardown, and conditionally frees storage. Its wrapper and `-0xa0/-0xa4` adjustors are compiler ABI products; the human declaration needs no explicit nontrivial derived destructor body.
- Historical blockers about missing `RectBounds`, unresolved one-base inheritance, raw-constructor liveness, broad mixed-range emission, helper naming, and source routing are superseded by the exact children and accepted support documents. Literal original member/file spellings remain inferred but do not justify compiler labels in final source.

## 2026-06-20 B004 Source-Quality Reanalysis

Local PE recheck used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (size `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, image base `0x00400000`; `.text 0x00401000-0x0060c4ac`, `.rdata 0x0060d000-0x0066c0be`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2c38`).

| Target | Absolute VA hits | RVA hits | Direct `E8`/`E9` branches | Interpretation |
| --- | ---: | ---: | --- | --- |
| `0x005007a0` | `0` | `0` | none | Raw constructor-shaped body has no direct executable/data route. |
| `0x005007f0` | `1` at `0x0061dc7c` | `0` | none | Vtable slot only; exact modeled visual-state override. |
| `0x00500820` | `1` at `0x0061dc78` | `0` | none | Vtable slot only; exact modeled paint override. |
| `0x005026a0` | `1` at `0x0061dc34` | `0` | `0x00502490`, `0x0050249b` | Vtable destructor slot plus secondary/tertiary adjustor-thunk jumps. |
| `0x0061dc34` | `4` at `0x004fba6f`, `0x004fbaf5`, `0x005007bf`, `0x005026a8` | `0` | none | Primary vtable immediate stores from inline setup, raw constructor bytes, and destructor reset. |
| `0x0061dc9c` | `4` at `0x004fba79`, `0x004fbaff`, `0x005007c9`, `0x005026b2` | `0` | none | Secondary vtable immediate stores from the same source/setup/destructor families. |
| `0x0061dccc` | `4` at `0x004fba83`, `0x004fbb09`, `0x005007d3`, `0x005026bc` | `0` | none | Tertiary vtable immediate stores from the same source/setup/destructor families. |

Disassembly-derived decisions:

- The retained constructor body is exactly `[0x005007a0,0x005007e8)`, 72 bytes, followed by eight `0xcc` alignment bytes at `[0x005007e8,0x005007f0)`. Its accepted human declaration is `DirectionButtonControlPane(int directionIndex, const RectBounds &bounds)`: it delegates to `ButtonControlPane(bounds)`, initializes `m_directionIndex`, installs the three inherited object-view vptrs in the retained binary copy, clears `m_stateFrameOffset`, and returns with `retn 8`. The implementation appears once as an inline constructor in this page's formal H block; [UID:00050G][0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor](by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md) records the retained copy and its two live NewUser inline-equivalent consumers.
- `[0x005007f0,0x0050081e)` is the exact out-of-line `SetVisualState(unsigned char)` override. It maps changed state `0x0b` to `m_stateFrameOffset = 1`, maps every other changed state to zero, and always delegates to `ControlPane::SetVisualState`. The broader `SetState` and stale boolean `SetEnabled` spellings are superseded by the accepted base virtual contract and [UID:00050H][0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState](by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md).
- `[0x00500820,0x005008b9)` is the exact out-of-line `OnPaint()` override. Source-facing reconstruction uses `EPFTileContext::Initialize`, [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), `RenderTileFrame`, `SetDrawColor`, `m_drawMode`, and `FillRect`, with UTF-16 `DIREC.EPD` and `NPAL3.PAL`. Raw `sub_457A60`, `sub_4B9980`, `sub_4B9660`, and `dword_69B3FC`/`unk_69B3FC` labels are binary-analysis history only and must not enter human-written source.
- Superseded 2026-06-20 provisional wording ended the constructor at `0x005007e5`, used the placeholder type `ControlPaneBoundsLike`, left `SetState` versus `SetVisualState` open, and described paint dependencies with raw compiler labels. Exact endpoint decoding, accepted `RectBounds` support, the base-vtable contract, source-facing helper roles, UID00050G/H/I splits, and live NewUser consumers resolved those earlier uncertainties; retain them only as this historical correction, not as current blockers.
- `0x005026a0-0x005026f5` is the MSVC scalar deleting destructor wrapper. Source should model a normal destructor/class inheritance and let the compiler regenerate wrapper/thunk glue; do not hand-write scalar-delete C++.
- ASCII `DIREC.EPD` has no hits; UTF-16LE `DIREC.EPD` has one hit at `0x0061e540`, raw file offset `0x21cf40`, with representative xrefs `0x00500861`, `0x0052a8ad`, and `0x0052a956`.
- `NewUserMiscDialogPane` inline setup at `0x004fba68-0x004fba91` and `0x004fbaee-0x004fbb17` allocates two `0x114` Direction controls, calls base constructor `0x00494eb0`, writes the three Direction vtables, sets `m_directionIndex` to `0` and `1`, and clears `m_stateFrameOffset`. This is consumer/setup evidence, not ownership evidence for [UID:00003X].

Ownership and emission decisions:

- Keep [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) as the current provisional owner/emitter because it is the strongest safe `NexusTK/ui/controls/` source-family route. Do not route this class to `NewUserMiscDialogPane`, `ButtonControlPane`, `ControlPane`, or the mixed [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) aggregate.
- Future final-source work may split `SpecializedButtonPanes.cpp` into `DirectionButtonControlPane.cpp`, `GenderButtonControlPane.cpp`, and `CheckBoxTextControlPane.cpp`, but no original filename evidence requires that split now.
- The exact Direction split and formal source placement are complete. [UID:00050G][0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor](by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md) records the retained constructor copy while this class H block owns its inline source; [UID:00050H][0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState](by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md) and [UID:00050I][0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint](by-memory/0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md) own the two out-of-line CPP definitions. Keep this class CPP block as `[[CHILDREN]]`, retain the inline constructor and virtual declarations in H, and do not duplicate method bodies or compiler vptr/deleting-wrapper mechanics here.

## Evidence Notes

- Wave3 effective grade is 96.7.
- 2026-05-24 IDA MCP reports no function, callers, or xrefs at `0x005007a0`; the previous function is `0x00500700-0x00500797`, and the next recognized function is `0x005007f0-0x0050081e`.
- 2026-05-24 IDA MCP recognizes `0x005007f0`, `0x00500820`, and `0x005026a0`, all reached by vtable data rather than direct code callers.
- The `NewUserMiscDialogPane` constructor inlines direction-button child setup at `0x004fba68-0x004fba91` and `0x004fbaee-0x004fbb17`, matching the control behavior without proving a standalone constructor body.
- 2026-05-26 IDA MCP confirmed primary vtable `0x0061dc34`, secondary vtable `0x0061dc9c`, and tertiary vtable `0x0061dccc`. Inline setup allocates `0x114` bytes and writes subclass fields at `+0x10c` and `+0x110`.
- 2026-05-27 IDA MCP recheck still reports `0x005007a0` as `NOFUNC` with no xrefs, and a raw dword scan across loaded segments found no pointers to `0x005007a0`. The virtual methods remain confirmed through vtable refs at `0x0061dc78` and `0x0061dc7c`.
- 2026-06-01 aggregate and vtable-data pages add exact raw-constructor stores, vtable child boundaries, slot targets, and field-layout evidence for `+0x10c` and `+0x110`.
- 2026-06-03 IDA MCP recheck again reports `0x005007a0` as `NOFUNC` with no xrefs or raw pointer hits. It reconfirmed `0x005007f0`, `0x00500820`, and `0x005026a0` as real functions, primary vtable slots `0x0061dc34+0x44 -> 0x00500820`, `+0x48 -> 0x005007f0`, and `+0x00 -> 0x005026a0`, plus constructor/inline/destructor vtable store refs at `0x004fba6d`, `0x004fbaf3`, `0x005007bd`, and `0x005026a6`.
- 2026-06-06 live IDA MCP recheck reconfirmed the current class boundary: `0x005007a0` is still not an IDA function and has no xrefs/callers, while `0x005007f0`, `0x00500820`, and `0x005026a0` remain modeled functions. `xrefs_to` still ties state/paint/destruction through vtable data at `0x0061dc7c`, `0x0061dc78`, and `0x0061dc34`; primary-vtable store refs remain split between inline setup in `NewUserMiscDialogPane` at `0x004fba6d`/`0x004fbaf3`, raw constructor-shaped bytes at `0x005007bd`, and destructor reset at `0x005026a6`. `callees` confirms the state method delegates through `0x00494b80`, the paint method uses the resource/render helper family, and the scalar deleting destructor chains to pane cleanup plus operator delete.
- 2026-06-11 A007 Batch 161 live IDA MCP refresh reconfirmed `0x005007a0` as a raw `NOFUNC` constructor-shaped start with no xrefs or raw pointer hits, and reconfirmed `0x005007f0-0x0050081e`, `0x00500820-0x005008b9`, and `0x005026a0-0x005026f5` as exact modeled functions. The destructor body has thunk callers at `0x00502490`/`0x0050249b`, primary vtable ref `0x0061dc34`, vtable reset stores at `this+0x00/+0xa0/+0xa4`, base teardown through `0x00544580`, and guarded delete through `0x004f4ac0`.

## Reconstruction Notes

- Model this as the concrete `ButtonControlPane` subclass emitted by the formal H block, with exact `int` fields `m_directionIndex` and `m_stateFrameOffset`.
- The inline constructor, state override, and paint body are now formal source. Preserve the exact frame arithmetic, base-call timing, resource arguments, and disabled-overlay order.
- Treat `0x0050248a` and `0x00502495` as compiler-generated adjustor thunks, not source methods.
- Treat `SetEnabled` and `SetState` as historical/generated aliases; the exact base virtual contract supports `SetVisualState(unsigned char)`.
- Use established source-facing dependencies `EPFTileContext::Initialize`, `g_pEPFLib`, `ResourceLayoutTableLookupLayoutEntry`, `RenderTileFrame`, `SetDrawColor`, `FillRect`, `DIREC.EPD`, and `NPAL3.PAL`; do not carry raw `sub_`/`dword_` labels into source.

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md)
- [UID:00036V][0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods](by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md)
- [UID:00036W][0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor](by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md)
- [UID:00050G][0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor](by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md)
- [UID:00050H][0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState](by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md)
- [UID:00050I][0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint](by-memory/0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-08-05 B004 UID0002OW accepted callback:
  - Raised `88/89 -> 94/95`, preserved owner/emitter UID0000NY, and moved source position to `30` after Gender.
  - Installed the complete `ButtonControlPane`-derived H declaration with inline constructor, exact fields, virtual declarations, and H/CPP child markers.
  - Linked exact children UID00050G/UID00050H/UID00050I; resolved constructor liveness through two live inlines; recorded exact `0x114` layout, `25/11/2` inherited table views, compiler-only destruction machinery, resources, source ordering, and superseded blocker history.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `62/66`.
  - Summary/evidence: render/control role, confirmed virtual methods, destructor/thunks, vtable refs, inline setup evidence, and projected-constructor caveat are documented; score remains lower because the standalone constructor boundary is still unproven and has no direct xrefs.
- 2026-06-02:
  - Before: the page remained in the low-both queue even though adjacent IDA-backed aggregate, layout, vtable, and exact vtable-data pages had been raised.
  - After: raised to `74/82` and marked `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank.
  - Summary/evidence: exact vtable child [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md), aggregate method map [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md), and layout fields [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) support the class role and rebuild shape while preserving the `0x005007a0` raw-constructor caveat.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank because the likely file parent was below the 80+ confidence threshold and had no projected path.
  - Changed to: `AUTOGEN_PARENT_UID:0000NY` and position `10`; reconstruction C++ remains blank.
  - Summary/evidence: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now a `76/82` provisional `NexusTK/ui/controls/` parent after a fresh IDA MCP recheck reconfirmed direction-button vtable/function evidence while preserving the raw constructor caveat.
- 2026-06-06 live IDA refresh:
  - Before: the class page had strong older evidence but had not recorded the current IDA state after several adjacent button/control updates.
  - Changed to: score `80/84`, retaining `RECONSTRUCTABLE:TRUE`, parent attachment, and blank final C++.
  - Summary/evidence: live IDA MCP reconfirmed `0x005007a0` as `NOFUNC` with no entry xrefs/callers, confirmed the state/paint/destructor function objects and sizes, confirmed vtable data refs and inline setup stores, and confirmed the state/paint/destructor callee families. Confidence stays below high-final because the constructor remains raw/non-IDA-function and final inherited slot names are not source quality.
- 2026-06-11 A007 Batch 161:
  - Changed to: raised scores from `80/84` to `85/86`, retained parent [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at position `10`, and linked exact method/destructor child pages.
  - Summary/evidence: live IDA MCP reconfirmed the raw constructor caveat, modeled state/paint/destructor extents, vtable refs, destructor thunk callers, and delete-flag behavior. The class and file parent now satisfy the strict `85/85` gate.
- 2026-06-20 B004 Rule 26 incorporation:
  - Changed to: raised scores from `85/86` to `88/89`; owner/emitter remain [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md); formal C++ remains blank.
  - Summary/evidence: incorporated the local PE pointer/branch/resource scan, binary hashes, constructor/state/paint/destructor disassembly facts, `SetState` naming correction with `SetEnabled` retained as an alias, `m_directionIndex` and `m_stateFrameOffset` field names, resolved `g_pEPFLib`/`ResourceLayoutTableLookupLayoutEntry`/UTF-16 `DIREC.EPD` references, `NewUserMiscDialogPane` consumer-only inline setup evidence, rejected owner alternatives, and exact-child split policy before method C++ is emitted.
