*** UID:0000CY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:12 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SeparatorMenuItem : public MenuItem
{
public:
    SeparatorMenuItem();

    virtual void DrawItem(GrafPort *port);
    virtual MenuItemMetrics GetDefaultDimensions() const;
    virtual MenuItemStyleFlags GetStyleFlags() const;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SeparatorMenuItem

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Vtables: [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- Layout docs: [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_SeparatorMenuItem.cpp`

## Class Purpose

`SeparatorMenuItem` is a retained abstract, non-interactive menu separator. It leaves the base `GetItemSize` and `GetText` contract pure, adds separate fixed-dimension/style virtuals, and draws a horizontal separator line centered in its item bounds.

IDA currently confirms no fields beyond the shared [UID:00007V][MenuItem](by-class/MenuItem.md) base. The separator-specific behavior is vtable-driven: draw at slot `+0x14`, fixed dimensions at `+0x18`, and style/flags at `+0x1c`.

## Hierarchy And Virtual Contract

- RTTI proves the single-inheritance chain `SeparatorMenuItem -> MenuItem -> LObject`; the class-hierarchy descriptor has attributes `0` and all three PMDs are `0,-1,0`.
- The exact eight-slot table contains the folded MenuItem deleting wrapper, inherited `GetRuntimeClass`, inherited `OnChangeMessage`, pure `GetItemSize`, pure `GetText`, concrete `DrawItem`, concrete `GetDefaultDimensions`, and concrete `GetStyleFlags`.
- `GetDefaultDimensions` at `+0x18` does not occupy or satisfy base `GetItemSize` at `+0x0c`. The two retained purecalls make the class abstract despite its constructor and concrete separator-specific methods.
- Multiple inheritance, a second interface facet, a concrete inherited metric/text contract, and a separate `DrawSeparator` virtual are rejected.

## Method Map

| Memory page | Method | Role |
| --- | --- | --- |
| [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) | `SeparatorMenuItem::SeparatorMenuItem()` | Initializes base menu item state and installs separator vtable. |
| [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md) | `GetDefaultDimensions()` candidate | Returns fixed `MenuItemMetrics { height = 6, width = 20 }`. |
| [UID:0002JD][0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags](by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md) | `GetStyleFlags()` candidate | Returns zeroed `MenuItemStyleFlags` using a 16-bit wrapper/out-result shape. |
| [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) | `DrawItem(GrafPort *port)` | Draws a centered separator rectangle through the shared menu-item draw slot. |

## B003 Source-Quality Incorporation

B003 rechecked the separator family as a source-quality/interface issue and accepted these high-probability roles:

| Item | Best current source role | Evidence | Caveat |
| --- | --- | --- | --- |
| Constructor | `SeparatorMenuItem::SeparatorMenuItem()` | Source-authored constructor: expands `MenuItem` base setup, leaves shared bounds zeroed, sets `m_enabled` false for non-interactive separator behavior, and relies on compiler codegen for vtable stores. | No direct constructor callers/pointer refs are currently proven; EH/security-cookie scaffolding is compiler support, not source. |
| `0002JC` vtable slot `+0x18` | `MenuItemMetrics SeparatorMenuItem::GetDefaultDimensions() const` | Writes output dword `[0]=6` and `[1]=20`; StringMenuItem metrics use the same height-first/width-second result convention. | Exact original lexical spelling remains inferred; the distinct new-slot contract is resolved. |
| `0002JD` vtable slot `+0x1c` | `MenuItemStyleFlags SeparatorMenuItem::GetStyleFlags() const` | Writes a zero 16-bit result through the hidden result pointer and returns with `retn 4`; a primitive return would use AX. | The two-byte UDT source shape is resolved; exact type/member spelling remains inferred. |
| `0002JE` vtable slot `+0x14` | `void SeparatorMenuItem::DrawItem(GrafPort *port)` | Uses shared bounds, clears `GrafPort+0x70` active draw/blit mode, calls `GrafPort::SetDrawColor(0x80)`, builds an inset centered `RectBounds`, and calls Surface slot `0x0069b3fc` as a fill/invalidate callback. | Exact callback typedef/member name and `GrafPort+0x70` field spelling remain descriptive. |

B015 source-quality recheck for [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) resolves the constructor source shape as `SeparatorMenuItem::SeparatorMenuItem() : MenuItem() { m_enabled = false; }`. The emitted word clear at `+0x14` is best understood through the shared `MenuItem` state layout: low byte `m_enabled` becomes false so separators are skipped by enabled-item scans, while high byte `m_selected` remains false. The constructor has no confirmed direct callers or pointer-table refs, so final call-site reachability remains a below-final-audit caveat.

B004 source-quality recheck for [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) resolves the draw virtual as `SeparatorMenuItem::DrawItem(GrafPort *port)`, not a separate `DrawSeparator(FittingRoomListPane *)` source contract. The page path keeps `DrawSeparator` as a behavior label, but source and vtable docs should use `DrawItem` for slot `+0x14`, matching [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md). The method is first-draft C++ ready; it draws a 3-pixel-tall separator band from `centerY - 1` through `centerY + 2`, inset horizontally by 3 pixels from inherited `m_bounds`, after setting active draw color `0x80`.

## Layout And Destruction

`SeparatorMenuItem` is exactly `0x18`, the same size as `MenuItem`, and introduces no fields, secondary vptr, or authored padding. Its vtable slot 0 reuses the exact `0x005172e0-0x0051731e` MenuItem scalar deleting wrapper, whose `0x18` delete-size path and two table references prove identical destruction/layout. Since `LObject` already provides virtual destruction and Separator has no nontrivial member cleanup, the accepted H declaration omits an explicit derived destructor and relies on implicit virtual derived destruction. The earlier `virtual ~SeparatorMenuItem()` draft and a hypothetical separate wrapper remain historical rejected alternatives.

## Reachability And Liveness

The constructor at `0x005171b0-0x0051721d` is a complete retained source body, but live xrefs report zero incoming references and bounded byte searches find no literal VA pointer hit. Its own final vptr store at `0x00517205` is the sole `0x0061ebd0` immediate route. This supports a retained abstract class whose surviving binary includes out-of-line construction/method code without proving a live concrete instantiation. It does not justify deleting the class, marking it compiler-only, inventing a pointer table, or raising a concrete-use claim.

## Evidence Notes

- IDA MCP `lookup_funcs` confirms all listed starts and extents as exact functions.
- 2026-05-26 IDA MCP resolves the decorated `SeparatorMenuItem` vtable symbol to `0x0061ebd0`; generated metadata still reports `vtable_count: 0`.
- The separator constructor writes the base `MenuItem` vtable first, clears the shared state word to `0`, then installs `SeparatorMenuItem`'s vtable.
- 2026-06-07 A010 Batch096 parent-gate review confirms this class already clears the corrected child gate at `86/90`. Associated parent work raised [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) to `86/85` by synchronizing the newer `MenuPaneAndItems`, `MenuItemVtables`, `MenuItemLayouts`, and proposed-source-tree evidence.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). The class is now `92/94`, and the direct source-file parent is recommended at `88/88`. By-structure ownership remains direct: `SeparatorMenuItem` is a retained abstract type in the reusable popup-menu/menu-item source family rather than a feature-dialog local class.

## Ownership And History

- The complete class declaration now emits from H; CPP contains only `[[CHILDREN]]`, keeping exact constructor/dimension/style/draw definitions at namespace scope.
- UID0000MN remains the current `PopupMenuControls.h/.cpp` source root. UID0001Y4 owns the shared table semantics and routes UID00036I.
- Historical descriptions of Separator as concrete, `GetDefaultDimensions` as the base metric implementation, an explicit/separate destructor, and `DrawSeparator` as an independent virtual are superseded by exact purecall/slot/wrapper evidence and retained here as rejected assumptions.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)

## Changes

- 2026-08-01 B003 UID00036I ordinary implementation callback:
  - Raised `88/91 -> 92/94` while preserving owner/emitter UID0000MN, reconstructable true, position `12`, exact constructor/method routes, disabled state, no-field layout, and all prior evidence/history.
  - Moved the complete declaration to H, left CPP as `[[CHILDREN]]` only, removed the unsupported explicit destructor declaration, and documented implicit virtual derived destruction through the folded `0x18` wrapper.
  - Added the exact three-class RTTI chain, explicit abstract `GetItemSize`/`GetText` state, eight-slot contract, resolved two-byte style UDT ABI, zero-route retained-source evidence, and UID0001Y4 -> UID00036I semantic-data route.
  - Historicalized the concrete/separate-destructor/base-metric/DrawSeparator alternatives instead of deleting them.

- 2026-07-15 B003 UID0002JH callback structural repair:
  - Applied exact R7 by closing the complete `SeparatorMenuItem` declaration before `[[CHILDREN]]`; qualified child definitions now emit at namespace scope rather than inside the class body.
  - Preserved `88/91`, owner/emitter UID0000MN, reconstructable true, position `12`, every declaration/route, no-derived-field model, disabled-state constructor, metric/style/draw and compiler-wrapper evidence, abstract-slot caveats, and all unrelated historical content.

- 2026-06-30 B008 empty-emitter implementation:
  - Raised from `86/90` to `88/91`, set `EMITTER_POSITION_OPTIONAL:12`, and populated the formal declaration shell with constructor/destructor declarations, `DrawItem`, `GetDefaultDimensions`, `GetStyleFlags`, and `[[CHILDREN]]`.
  - Evidence: current constructor/dimension/style/draw child pages, `MenuItemVtables` slot evidence, and B008 MCP vtable checks keep `SeparatorMenuItem` under [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) with [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) as the source root.
  - Source-quality decision: preserve inherited purecall/abstract-slot caveats for inherited base text/metric slots and do not invent separator-specific fields.
- 2026-06-07 A010 Batch096 class coverage toss-up:
  - Before: score `86/90`, `AUTOGEN_PARENT_UID` blank because the likely direct parent was below the corrected gate.
  - After: score remains `86/90`, `AUTOGEN_PARENT_UID:0000MN`.
  - Evidence: the class already had exact constructor/metric/style/draw child pages and vtable/layout evidence; associated parent work raised [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) to `86/85`, satisfying the strict child-and-parent gate.
- 2026-06-17 B003 source-quality incorporation:
  - Recorded `MenuItemMetrics`, `MenuItemStyleFlags`, constructor state, and separator draw roles as high-probability source roles.
  - Rerouted exact SeparatorMenuItem child pages from direct file owner/emitter to [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) where applicable, while keeping [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) as the source-file root.
- 2026-06-19 B015 constructor source-quality implementation:
  - Score unchanged at `86/90`.
  - Evidence: [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) now carries first-draft constructor C++; B015 confirmed the expanded base setup, shared bounds zeroing, `m_enabled=false` source role, `m_selected=false` side effect of the raw word clear, no direct constructor caller/pointer route, and compiler-generated EH/vtable scaffolding policy.
- 2026-06-20 B004 draw virtual source-quality implementation:
  - Score unchanged at `86/90`; class-level C++ remains blank while exact child [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) carries first-draft method C++.
  - Evidence: recorded the source-facing `DrawItem(GrafPort *port)` name, slot `+0x14` relationship, centered separator rectangle math, `GrafPort::SetDrawColor(0x80)`, slot-7 fill/invalidate callback, and rejection of generated `DrawSeparator(FittingRoomListPane *)` naming.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `90`.
- Evidence: the page documents the class role, file ownership, main by-memory range, vtable/layout links, exact constructor and virtual method ranges, and IDA-confirmed vtable symbol; remaining completion gap is final source-ready C++ detail.
- Reconstructable metadata update: existed before as blank; changed to `TRUE`. Summary: IDA evidence confirms this is NexusTK-owned menu infrastructure. This older note predates B003's method-level first-draft C++ pass; current source bodies are attached to exact child pages where evidence supports them.
- Method-map split update: existed before as raw address rows; changed to UID links for exact by-memory child pages. Evidence: IDA MCP exact function-boundary lookup and vtable slot xrefs support the child pages.
